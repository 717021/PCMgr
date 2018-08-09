#include "stdafx.h"
#include "kernelhlp.h"
#include "mapphlp.h"
#include "syshlp.h"
#include "fmhlp.h"
#include "suact.h"
#include "reghlp.h"
#include "loghlp.h"
#include "resource.h"
#include "settinghlp.h"
#include "thdhlp.h"
#include "ntsymbol.h"
#include "sysstructs.h"
#include "StringHlp.h"
#include <io.h>

BOOL isKernelNeed64 = FALSE;
BOOL isKernelDriverLoaded = FALSE;
BOOL isKernelPDBLoaded = FALSE;
HANDLE hKernelDevice = NULL;
extern HWND hWndMain;
extern HMENU hMenuMainFile;

ULONG_PTR uNTBaseAddress = 0;
HANDLE hThreadDbgView = NULL;
HANDLE hEventDbgView = NULL;
BOOL isMyDbgViewLoaded = FALSE;
BOOL isMyDbgViewRunning = FALSE;

BOOL MForceDeleteServiceRegkey(LPWSTR lpszDriverName)
{
	BOOL rs = FALSE;
	wchar_t regPath[MAX_PATH];
	wsprintf(regPath, L"SYSTEM\\CurrentControlSet\\services\\%s", lpszDriverName);
	rs = MREG_DeleteKey(HKEY_LOCAL_MACHINE, regPath);

	if (!rs)LogErr(L"RegDeleteTree failed : %d in delete key HKEY_LOCAL_MACHINE\\%s", GetLastError(), regPath);
	else Log(L"Service Key deleted : HKEY_LOCAL_MACHINE\\%s", regPath);
	
	wchar_t regName[MAX_PATH];
	wcscpy_s(regName, lpszDriverName);
	_wcsupr_s(regName);
	wsprintf(regPath, L"SYSTEM\\CurrentControlSet\\Enum\\Root\\LEGACY_%s", regName);
	rs = MREG_DeleteKey(HKEY_LOCAL_MACHINE, regPath);

	if (!rs) {
		LogWarn(L"RegDeleteTree failed : %d in delete key HKEY_LOCAL_MACHINE\\%s", GetLastError(), regPath);
		rs = TRUE;
	}
	else Log(L"Service Key deleted : HKEY_LOCAL_MACHINE\\%s", regPath);

	return rs;
}
M_CAPI(BOOL) MLoadKernelDriver(LPWSTR lpszDriverName, LPWSTR driverPath, LPWSTR lpszDisplayName)
{
#ifndef _AMD64_
	if (MIs64BitOS())
	{
		LogErr(L"You need to use 64 bit version PCMgr application to load driver.");
		return FALSE;
	}
#endif
	if (MIsRunasAdmin())
	{
		wchar_t sDriverName[32];
		wcscpy_s(sDriverName, lpszDriverName);

		bool recreatee = false;

	RECREATE:
		BOOL bRet = FALSE;
		SC_HANDLE hServiceMgr = NULL;
		SC_HANDLE hServiceDDK = NULL;
		hServiceMgr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if (hServiceMgr == NULL)
		{
			LogErr(L"Load driver error in OpenSCManager : %d", GetLastError());
			bRet = FALSE;
			goto BeforeLeave;
		}

		hServiceDDK = CreateService(hServiceMgr, lpszDriverName, lpszDisplayName, SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER,
			SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, driverPath, NULL, NULL,NULL,	NULL,NULL);

		DWORD dwRtn = 0;
		if (hServiceDDK == NULL)
		{
			dwRtn = GetLastError();
			if (dwRtn == ERROR_SERVICE_MARKED_FOR_DELETE)
			{
				LogErr(L"Load driver error in CreateService : ERROR_SERVICE_MARKED_FOR_DELETE");
				if (!recreatee) {
					recreatee = true;
					if (hServiceDDK) CloseServiceHandle(hServiceDDK);
					if (hServiceMgr) CloseServiceHandle(hServiceMgr);
					if (MForceDeleteServiceRegkey(sDriverName)) goto RECREATE;
				}
			}
			if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_EXISTS)
			{
				LogErr(L"Load driver error in CreateService : %d", dwRtn);
				bRet = FALSE;
				goto BeforeLeave;
			}
			hServiceDDK = OpenService(hServiceMgr, lpszDriverName, SERVICE_ALL_ACCESS);
			if (hServiceDDK == NULL)
			{
				dwRtn = GetLastError();
				LogErr(L"Load driver error in OpenService : %d", dwRtn);
				bRet = FALSE;
				goto BeforeLeave;
			}
		}
		bRet = StartService(hServiceDDK, NULL, NULL);	
		if (!bRet)
		{
			DWORD dwRtn = GetLastError();
			if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_ALREADY_RUNNING)
			{
				LogErr(L"Load driver error in StartService : %d", dwRtn);
				bRet = FALSE;
				goto BeforeLeave;
			}
			else
			{
				if (dwRtn == ERROR_IO_PENDING)
				{
					bRet = FALSE;
					goto BeforeLeave;
				}
				else
				{
					bRet = TRUE;
					goto BeforeLeave;
				}
			}
		}
		bRet = TRUE;
		//�뿪ǰ�رվ��
	BeforeLeave:
		if (hServiceDDK) CloseServiceHandle(hServiceDDK);
		if (hServiceMgr) CloseServiceHandle(hServiceMgr);
		return bRet;
	}else LogErr(L"Load driver error because need adminstrator.");
	return FALSE;
}
M_CAPI(BOOL) MUnLoadKernelDriver(LPWSTR szSvrName)
{
	BOOL bDeleted = FALSE;
	BOOL bRet = FALSE;
	SC_HANDLE hServiceMgr = NULL;
	SC_HANDLE hServiceDDK = NULL;
	SERVICE_STATUS SvrSta;
	hServiceMgr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hServiceMgr == NULL)
	{
		LogErr(L"UnLoad driver error in OpenSCManager : %d", GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	//����������Ӧ�ķ���
	hServiceDDK = OpenService(hServiceMgr, szSvrName, SERVICE_ALL_ACCESS);
	if (hServiceDDK == NULL)
	{
		if (GetLastError() == ERROR_SERVICE_DOES_NOT_EXIST)
			LogErr(L"UnLoad driver error because driver not load.");
		else LogErr(L"UnLoad driver error in OpenService : %d", GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	//ֹͣ�����������ֹͣʧ�ܣ�ֻ�������������ܣ��ٶ�̬���ء� 
	if (!ControlService(hServiceDDK, SERVICE_CONTROL_STOP, &SvrSta)) {
		LogErr(L"UnLoad driver error in ControlService : %d", GetLastError());
	}
	//��̬ж���������� 
	if (!DeleteService(hServiceDDK)) {
		LogErr(L"UnLoad driver error in DeleteService : %d", GetLastError());
		bRet = FALSE;
	}
	else bDeleted = TRUE;

BeforeLeave:
	//�뿪ǰ�رմ򿪵ľ��
	if (hServiceDDK) CloseServiceHandle(hServiceDDK);
	if (hServiceMgr) CloseServiceHandle(hServiceMgr);

	if(bDeleted) bRet = MForceDeleteServiceRegkey(szSvrName);

	return bRet;
}

M_CAPI(ULONG_PTR) MGetNTBaseAddress() {
	return uNTBaseAddress;
}
void MInitKernelSwitchMenuState(BOOL loaded)
{
	if (loaded) {
		EnableMenuItem(hMenuMainFile, IDM_UNLOAD_DRIVER, MF_ENABLED);
		EnableMenuItem(hMenuMainFile, IDM_LOAD_DRIVER, MF_DISABLED);
	}
	else {
		EnableMenuItem(hMenuMainFile, IDM_UNLOAD_DRIVER, MF_DISABLED);
		EnableMenuItem(hMenuMainFile, IDM_LOAD_DRIVER, MF_ENABLED);
	}
}
BOOL MInitKernelDriverHandle() {
	hKernelDevice = CreateFile(L"\\\\.\\PCMGRK",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hKernelDevice == INVALID_HANDLE_VALUE)
	{
		LogErr(L"Get Kernel driver handle (CreateFile) failed : %d . ", GetLastError());
		return FALSE;
	}

	Log(L"Kernel Driver HANDLE Created.");

	MInitMyDbgView();

	CreateThread(NULL, 0, MLoadingThread, NULL, 0, NULL);

	MInitKernelSwitchMenuState(isKernelDriverLoaded);
	return TRUE;
}

BOOL MInitKernelNTPDB(BOOL usingNtosPDB, PKNTOSVALUE kNtosValue)
{
	if (!usingNtosPDB)
		return TRUE;
	if (!InitSymHandler())
		return FALSE;

	if (kNtosValue->NtostAddress != 0 && !MStrEqualW(kNtosValue->NtosModuleName, L""))
	{
		uNTBaseAddress = kNtosValue->NtostAddress;
		char* ntosNameC = (char*)MConvertLPWSTRToLPCSTR(kNtosValue->NtosModuleName);
#ifdef _AMD64_
		Log(L"Get NTOS base info : %s 0x%I64X", kNtosValue->NtosModuleName, kNtosValue->NtostAddress);
#else
		Log(L"Get NTOS base info : %s 0x%08X", kNtosValue->NtosModuleName, kNtosValue->NtostAddress);
#endif
		MAppSetStartingProgessText(L"Downloading and loading ntos PDB file...");
		if (MKSymInit(ntosNameC, kNtosValue->NtostAddress))
		{
			isKernelPDBLoaded = TRUE;
			MAppSetStartingProgessText(L"Analysis of the kernel PDB files...");
			if (MEnumSyms(kNtosValue->NtostAddress, (PSYM_ENUMERATESYMBOLS_CALLBACK)MEnumSymRoutine, NULL))
			{
				delete ntosNameC;

				MSendAllSymAddressToDriver();;
				return TRUE;
			}
		}
		delete ntosNameC;
	}
	else LogErr2(L"Failed get ntos baseAddress and name!");

	return FALSE;
}
BOOL MUnInitKernelNTPDB() {
	if (isKernelPDBLoaded)
		return MEnumSymsClear();
	return TRUE;
}

M_CAPI(BOOL) MIsKernelNeed64()
{
	return isKernelNeed64;
}
M_CAPI(BOOL) MCanUseKernel()
{
	return isKernelDriverLoaded && hKernelDevice != NULL;
}
M_CAPI(BOOL) MInitKernel(LPWSTR currentPath)
{
	Log(L"MInitKernel (%s)...", currentPath);
	MAppSetStartingProgessText(L"Loading kernel driver...");
	if (!isKernelDriverLoaded)
	{
		wchar_t path[MAX_PATH];
		if (MIs64BitOS()) {
#ifdef _AMD64_
			wsprintf(path, L"%s\\PCMgrKernel64.sys", currentPath);
#else
			isKernelNeed64 = TRUE;
			LogErr(L"You need to use 64 bit version PCMgr application to load driver.");
			return FALSE;
#endif
		}
		else wsprintf(path, L"%s\\PCMgrKernel32.sys", currentPath);

		if (MFM_FileExist(path))
		{
			Log(L"LoadKernelDrive (%s)...", path);
			
			if (MLoadKernelDriver(L"PCMgrKernel", path, L"PCMgr kernel driver")) {
				Log(L"Kernel Driver Loaded.");
				isKernelDriverLoaded = TRUE;
				return MInitKernelDriverHandle();
			}
			else
			{
				if (MInitKernelDriverHandle()) {
					isKernelDriverLoaded = TRUE;
					MInitKernelSwitchMenuState(isKernelDriverLoaded);
				}
				else {
					isKernelDriverLoaded = FALSE;
					LogErr(L"Load Kernel driver error");
				}
			}
		}
		else if (MInitKernelDriverHandle()) {
			Log(L"Kernel driver file missing.");
			isKernelDriverLoaded = TRUE;
			MInitKernelSwitchMenuState(isKernelDriverLoaded);
		}
		else {

			LogErr(L"Load Kernel driver error because kernel driver file missing.");
			LogInfo(L"Try find kernel driver file : %s.", path);

			isKernelDriverLoaded = FALSE;
			MInitKernelSwitchMenuState(isKernelDriverLoaded);
		}
	}
	else Log(L"Kernel alreday loaded");
	return isKernelDriverLoaded;
}
M_CAPI(BOOL) MUninitKernel()
{
	Log(L"MUninitKernel...");
	if (isKernelDriverLoaded)
	{
		if (isMyDbgViewLoaded)
			MUnInitMyDbgView();
		if (hKernelDevice != NULL)
			CloseHandle(hKernelDevice);

		if (MUnLoadKernelDriver(L"PCMgrKernel")) {
			isKernelDriverLoaded = FALSE;
			EnableMenuItem(hMenuMainFile, IDM_UNLOAD_DRIVER, MF_DISABLED);
			EnableMenuItem(hMenuMainFile, IDM_LOAD_DRIVER, MF_ENABLED);
			
			Log(L"Kernel unloaded");
			return TRUE;
		}
		else Log(L"Kernel unload failed");
		return !isKernelDriverLoaded;
	}
	else {
		LogWarn(L"Kernel not load , try force delete service");

		if (MUnLoadKernelDriver(L"PCMgrKernel")) {
			isKernelDriverLoaded = FALSE;
			EnableMenuItem(hMenuMainFile, IDM_UNLOAD_DRIVER, MF_DISABLED);
			EnableMenuItem(hMenuMainFile, IDM_LOAD_DRIVER, MF_ENABLED);

			Log(L"Kernel unloaded");
			return TRUE;
		}
		else LogErr(L"Kernel unload failed");
	}
	return FALSE;
}

BOOL froceNotUseMyDbgView = FALSE;

BOOL MUnInitMyDbgView() {
	if (isMyDbgViewLoaded)
	{
		M_SU_ReSetDbgViewEvent();
		if (hEventDbgView) { CloseHandle(hEventDbgView); hEventDbgView = 0; }
		isMyDbgViewRunning = FALSE;
		DWORD dw = WaitForSingleObject(hThreadDbgView, 1000);
		if (dw == WAIT_TIMEOUT) { 
			if(NT_SUCCESS(MTerminateThreadNt(hThreadDbgView)))
				LogInfo(L"MDbgViewReceiveThread Terminated.");
			else LogWarn(L"MDbgViewReceiveThread Terminate failed!");
		}
		if (hThreadDbgView) { CloseHandle(hThreadDbgView); hThreadDbgView = 0; }
		isMyDbgViewLoaded = FALSE;
		LogInfo(L"MyDbgView stoped.");
	}
	return !isMyDbgViewLoaded;
}
BOOL MInitMyDbgView() 
{
	if (!isMyDbgViewLoaded)
	{
		if (!M_CFG_GetConfigBOOL(L"LogDbgPrint", L"Configure", true) && !froceNotUseMyDbgView)
			return TRUE;

		hEventDbgView = CreateEvent(NULL, TRUE, FALSE, L"PCMGR_DBGVIEW");
		if (!M_SU_SetDbgViewEvent(hEventDbgView)) {
			CloseHandle(hEventDbgView);
			return FALSE;
		}

		isMyDbgViewRunning = TRUE;
		hThreadDbgView = CreateThread(NULL, 0, MDbgViewReceiveThread, NULL, 0, NULL);
		if (hThreadDbgView) {
			isMyDbgViewLoaded = TRUE;
			LogInfo(L"MyDbgView started.");
			return isMyDbgViewLoaded;
		}
		else LogWarn(L"Create MyDbgView Thread failed : %d", GetLastError());
	}
	return FALSE;
}
M_CAPI(VOID) MDoNotStartMyDbgView()
{
	froceNotUseMyDbgView = TRUE;
}

DWORD WINAPI MDbgViewReceiveThread(LPVOID lpParameter)
{
	LogInfo(L"MDbgViewReceiveThread sterted.");

	while (isMyDbgViewRunning) 
	{
		WaitForSingleObject(hEventDbgView, INFINITE);

		WCHAR lastBuffer[256];

		CONTINUE:
		BOOL hasMoreData = FALSE;
		memset(lastBuffer, 0, sizeof(lastBuffer));
		if (M_SU_GetDbgViewLastBuffer(lastBuffer, 256, &hasMoreData))
		{
			if (MStrEqualW(lastBuffer, L""))
				LogText(FOREGROUND_INTENSITY | FOREGROUND_BLUE |	FOREGROUND_RED, L"[DBGL] \n", lastBuffer);
			else LogText(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE, L"[DBGL] %s\n", lastBuffer);

			if (hasMoreData) goto CONTINUE;
		}

		ResetEvent(hEventDbgView);
	}

	LogInfo(L"MDbgViewReceiveThread exiting.");
	return 0;
}
DWORD WINAPI MLoadingThread(LPVOID lpParameter)
{
	BOOL usingNtosPDB = M_CFG_GetConfigBOOL(L"UseKrnlPDB", L"Configure", true);
	MAppSetStartingProgessText(L"Init Kernel...");
	KNTOSVALUE kNtosValue = { 0 };
	M_SU_Init(usingNtosPDB, &kNtosValue);
	if (!kNtosValue.KernelDataInited)
	{
		MGetNtosNameAndStartAddress(kNtosValue.NtosModuleName, 32, (kNtosValue.NtostAddress == 0 ? &kNtosValue.NtostAddress : 0));
		if (!MInitKernelNTPDB(usingNtosPDB, &kNtosValue) && !isKernelPDBLoaded) {
			M_SU_Init(false, &kNtosValue);
		}
	}
	MAppSetStartingProgessText(L"Initializing...");
	MAppMainCall(36, 0, 0);
	return 0;
}