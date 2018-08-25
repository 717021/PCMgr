#pragma once
#include "stdafx.h"
#include "ntdef.h"
#include "schlp.h"
#include "sysstructs.h"

//�ݴ��ں�ģ����Ϣ
typedef struct _KernelModulSmallInfo
{
	ULONG_PTR DriverObject;//��������
	WCHAR szFullDllPathOrginal[MAX_PATH];
	WCHAR szFullDllPath[MAX_PATH];//����·��
	WCHAR szServiceName[MAX_PATH];//��������
	LPSERVICE_STORAGE serviceInfo;//������Ϣ
}KernelModulSmallInfo,*PKernelModulSmallInfo;

//ö���ں�ģ����Ϣ�Ļص�
typedef void(__cdecl*EnumKernelModulsCallBack)(
	PKernelModulSmallInfo kmi,//�ݴ��ں�ģ����Ϣ
	LPWSTR szBaseDllName, //ģ������
	LPWSTR szFullDllPath,//����·��
	LPWSTR szFullDllPathOrginal,//����·����δת����Win32·����
	LPWSTR szEntryPoint,//��ڵ�
	LPWSTR szSizeOfImage,//ӳ���С
	LPWSTR szDriverObject,//��������
	LPWSTR szBase,//����ַ
	LPWSTR szServiceName,//��������
	ULONG Order//����˳��
	);

//ö�ٽ����ȼ��ص�
typedef void(__cdecl*EnumProcessHotKeyCallBack)(
	PHOT_KEY_DATA pHotKeyData, //�ȼ���Ϣ���ص������Ժ�ᱻ�ͷ�
	LPWSTR objectStr,//�ȼ�������ַ���
	DWORD keyID, //�ȼ�ID
	LPWSTR keyStr,//�ȼ���ֵ
	DWORD pid,//����ID
	DWORD tid,//�߳�ID
	LPWSTR procName//��������
	);

//ö�ٽ��̶�ʱ���ص�
typedef void(__cdecl*EnumProcessTimerCallBack)(
	PTIMER_DATA pHotKeyData,//��ʱ����Ϣ���ص������Ժ�ᱻ�ͷ�
	LPWSTR objectStr,//��ʱ��������ַ���
	LPWSTR funStr,//��ʱ����Ӧ�������ַ���
	LPWSTR moduleStr,//��ʱ����Ӧģ����ַ���
	LPWSTR hwndStr,//��ʱ����Ӧ���ڵ��ַ���
	HWND hWnd,
	DWORD tid,//�߳�ID
	UINT_PTR nID,//��ʱ��ID
	UINT interval,//��ʱ��ʱ����
	DWORD pid//����ID
	);

//�ں˷����ص�
typedef void(__cdecl*DACALLBACK)(
	ULONG_PTR curaddress, /*��ǰ��ַ*/
	LPWSTR addressstr, /*��ǰ��ַ���ַ���*/
	LPWSTR shellstr, /*�����֮��Ĵ����ַ���1*/
	LPWSTR bariny, /*�������ַ���*/
	LPWSTR asmstr/*�����֮��Ĵ����ַ���2*/
	);

M_CAPI(BOOL) M_SU_CreateFile(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, PHANDLE pHandle);
//�ں˴򿪽���
M_CAPI(BOOL) M_SU_OpenProcess(DWORD pid, PHANDLE pHandle, NTSTATUS* pStatus);
//�ں˴��߳�
M_CAPI(BOOL) M_SU_OpenThread(DWORD pid, DWORD tid, PHANDLE pHandle, NTSTATUS* pStatus);

//ǿ�ƽ�������
//    pid��process id
//    exitCode���˳����루һ����0��
//    [OUT] pStatus���������ص� NTSTATUS
//    useApc���Ƿ�ʹ�ò���apc�������̵�ÿһ���߳�
M_CAPI(BOOL) M_SU_TerminateProcessPID(DWORD pid, UINT exitCode, NTSTATUS* pStatus, BOOL useApc = FALSE);
//ǿ�ƽ����߳�
//    tid��thread id
//    exitCode���˳����루һ����0��
//    [OUT] pStatus���������ص� NTSTATUS
//    useApc���Ƿ�ʹ�ò���apc�����߳�
M_CAPI(BOOL) M_SU_TerminateThreadTID(DWORD tid, UINT exitCode, NTSTATUS* pStatus, BOOL useApc = FALSE);
//ǿ�ƹرս����ڵ�һ�����
M_CAPI(BOOL) M_SU_CloseHandleWithProcess(DWORD pid, LPVOID handleValue);
//�ں˹������
//    pid��process id
//    [OUT] pStatus���������ص� NTSTATUS
M_CAPI(BOOL) M_SU_SuspendProcess(DWORD pid, NTSTATUS * pStatus);
//�ں�ȡ���������
//    pid��process id
//    [OUT] pStatus���������ص� NTSTATUS
M_CAPI(BOOL) M_SU_ResumeProcess(DWORD pid, NTSTATUS * pStatus);

//��ȡEPROCESS�ṹ��Ϣ
//    pid��process id
//    [OUT] lpEprocess�����EPROCESS��ַ
//    [OUT] lpPeb�����Peb��ַ
//    [OUT] lpJob�����Job��ַ
//    [OUT] imagename����������ļ���[260]
//    [OUT] path�������������·��[260]��Ϊδת����NTPath
M_CAPI(BOOL) M_SU_GetEPROCESS(DWORD pid, ULONG_PTR* lpEprocess, ULONG_PTR* lpPeb, ULONG_PTR* lpJob, LPWSTR imagename, LPWSTR path); 
//��ȡETHREAD�ṹ��Ϣ
//    tid��thread id
//    [OUT] lpEthread�����ETHREAD��ַ
//    [OUT] lpTeb�����Teb��ַ
M_CAPI(BOOL) M_SU_GetETHREAD(DWORD tid, ULONG_PTR* lpEthread, ULONG_PTR * lpTeb);
//��ȡ���������в��� CommandLine
//    pid��process id
//    [OUT] outCmdLine������������ַ���������������[1024]��
M_CAPI(BOOL) M_SU_GetProcessCommandLine(DWORD pid, LPWSTR outCmdLine);
//������ں˴���
//    callback�������һ�еĻص�
//    startaddress����Ҫ��������ʼ��ַ
//   size����Ҫ�����Ĵ�С�����ֽ�Ϊ��λ
M_CAPI(BOOL) M_SU_KDA(DACALLBACK callback, ULONG_PTR startaddress, ULONG_PTR size);

//�ݴ��ں�ģ����Ϣ�ṹ��ɾ��
//  ��ö���ں�ģ����Ϣ�ص��е�һ�������Ľṹ��ʹ������ڴ�ɾ����������ڴ�й©
M_CAPI(void) M_SU_EnumKernelModulsItemDestroy(KernelModulSmallInfo * km);
//ö���ں�ģ��
//    callback��ö���ں�ģ����Ϣ�Ļص�
//    showall���Ƿ���ʾδ���ص�����
M_CAPI(BOOL) M_SU_EnumKernelModuls(EnumKernelModulsCallBack callback, BOOL showall = FALSE);

//Not For public������

BOOL M_SU_ForceShutdown();
BOOL M_SU_ForceReboot();

BOOL M_SU_ProtectMySelf();
BOOL M_SU_UnProtectMySelf();

//�ں˳�ʼ������
M_CAPI(BOOL) M_SU_Init(BOOL requestNtosValue, PKNTOSVALUE outValue);


M_CAPI(BOOL) M_SU_SetDbgViewEvent(HANDLE hEvent);
M_CAPI(BOOL) M_SU_ReSetDbgViewEvent();
M_CAPI(BOOL) M_SU_GetDbgViewLastBuffer(LPWSTR outbuffer, size_t bufsize, BOOL*hasMoreData);

M_CAPI(BOOL) M_SU_PrintInternalFuns();

//ö�ٽ����ȼ�
//    pid��process id
//    callBack���ص�
M_CAPI(BOOL) M_SU_GetProcessHotKeys(DWORD pid, EnumProcessHotKeyCallBack callBack);
//ö�ٽ��̶�ʱ��
//    pid��process id
//    callBack���ص�
M_CAPI(BOOL) M_SU_GetProcessTimers(DWORD pid, EnumProcessTimerCallBack callBack);

LRESULT M_SU_EnumKernelModuls_HandleWmCommand(WPARAM wParam);
