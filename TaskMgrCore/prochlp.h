#pragma once
#include "stdafx.h"
#include "perfhlp.h"
#include "ntdef.h"
#include "nthlp.h"
#include "handlehlp.h"

//ö�ٽ���ģ��ص�
//����FALSE��ֹͣö��
typedef BOOL(__cdecl*EnumProcessModulesCallBack)(
	LPWSTR moduleName, //ģ������
	LPWSTR fullDllName, //ģ������·��
	PVOID baseAddress, //ģ�����ַ��ȫ�֣�
	ULONG sizeOfImage, //ģ���С
	LPVOID customData//�Զ�������
	);
//ö�ٽ��̴��ڻص�
//����FALSE��ֹͣö��
typedef BOOL(__cdecl*EnumProcessWindowsCallBack)(
	HWND hWnd, //���ھ��
	LPWSTR windowText, //��������
	LPVOID customData//�Զ�������
	);
//ö�ٽ����̻߳ص�
//����FALSE��ֹͣö��
typedef BOOL(__cdecl*EnumProcessThreadsCallBack)(
	DWORD tid, //�߳�id
	DWORD pid, //����id
	PVOID startAddress, //��ʼ��ַ����Win32StartAddress����Ҫ��ȡWin32StartAddress��ʹ��MGetThreadWin32StartAddress��
	PSYSTEM_THREADS t, //�߳���Ϣ���ݽṹ���ص������Ժ�ᱻ�ͷţ�
	LPVOID customData//�Զ�������
	);
//ö�ٽ��̻ص�
//����FALSE��ֹͣö��
typedef BOOL(__cdecl*EnumProcessCallBack)(
	DWORD pid,//����id
	DWORD parentid, //������id
	LPWSTR exename, //��������
	LPWSTR exefullpath,//��������·��
	int tp, //�Ƿ������һ��ģ�飬��ö������Ժ���ٵ���һ�λص���tp=0��pid��ŵ��ǽ�������
	HANDLE hProcess, //��ǰ���̾��
	PSYSTEM_PROCESSES proc, //������Ϣ���ݽṹ����һ�ε���MEnumProcess/MEnumProcessCore֮��ᱻ�ͷţ�
	LPVOID customData//�Զ�������
	);
//��ö�ٽ��̻ص�
//����FALSE��ֹͣö��
typedef void(__cdecl*EnumProcessCallBack2)(
	DWORD pid, //����id
	PSYSTEM_PROCESSES proc//������Ϣ���ݽṹ����һ�ε���MEnumProcess/MEnumProcessCore֮��ᱻ�ͷţ�
	);

//ö�ٽ���Ȩ�޻ص�
//    name��Ȩ������
typedef void(__cdecl *EnumPrivilegesCallBack)(LPWSTR name);

//private

typedef struct tag_USERNAME {
	PSID Sid;
	WCHAR UserName[64];
	WCHAR DomainName[128];

}USERNAME,*PUSERNAME;
typedef struct tag_EPW_ARG {
	DWORD pid;
	EnumProcessWindowsCallBack c;
	LPVOID data;
}EPW_ARG,*PEPW_ARG;
typedef struct tag_PEOCESSKINFO {
	WCHAR Eprocess[32];
	WCHAR PebAddress[32];
	WCHAR JobAddress[32];
	WCHAR ImageFileName[MAX_PATH];
	WCHAR ImageFullName[MAX_PATH];
}PEOCESSKINFO,*PPEOCESSKINFO;
typedef struct tag_PROCHANDLE_STORAGE {
	DWORD pid;
	HANDLE hProcess;
}PROCHANDLE_STORAGE,*PPROCHANDLE_STORAGE;

//Not use
//private

VOID MAnitInjectLow();

//private

void MProcessHANDLEStorageDestroyItem(DWORD pid);
void MProcessHANDLEStorageDestroy();
BOOL LoadDll();
void FreeDll();
void MFroceKillProcessUser();
void MKillProcessUser(BOOL ask);
void MKillProcessTreeUser();
BOOL MKillProcessUser2(HWND hWnd, DWORD pid, BOOL showErr, BOOL ignoreTerminateing);
void MAppProcPropertyClassHandleWmCommand(WPARAM wParam);
BOOL MDetachFromDebuggerProcess(DWORD pid);

//������Ȩ
EXTERN_C M_API BOOL MGetPrivileges2();
//ˢ�½����б�
EXTERN_C M_API BOOL MEnumProcessCore();
//ˢ�½����б���ͷ���Դ����
EXTERN_C M_API void MEnumProcessFree();
//ö�ٽ��̣����� ������Ϣ��Ϣ��
//    callBack���ص�
EXTERN_C M_API BOOL MEnumProcess(EnumProcessCallBack callBack, LPVOID customData);
//��ö�ٽ��̣��������� PID��ͨ������ˢ�£�
//    callBack���򵥻ص�
EXTERN_C M_API BOOL MEnumProcess2(EnumProcessCallBack2 callBack);
//�ӽ����б�����ָ��PID������ calBack
//��MEnumProcess/MEnumProcessCore֮��ʹ�ã�
EXTERN_C M_API BOOL MUpdateProcess(DWORD pid, EnumProcessCallBack calBack, LPVOID customData);
//����ö�ٵĽ����б�����ָ��PID�Ľ�����Ϣ
//��MEnumProcess/MEnumProcessCore֮��ʹ�ã�
EXTERN_C M_API PSYSTEM_PROCESSES MFindProcessInLoadedProcesses(DWORD pid);
//����ö�ٵĽ����б�����ָ��PID�Ľ��̣�ö�����߳�
//��MEnumProcess/MEnumProcessCore֮��ʹ�ã�
EXTERN_C M_API BOOL MEnumProcessThreads(PSYSTEM_PROCESSES p, EnumProcessThreadsCallBack c, LPVOID customData);
//ö�ٽ������д���
//    dwPID������pid
//    callBack���ص�
EXTERN_C M_API BOOL MEnumProcessWindow(DWORD dwPID, EnumProcessWindowsCallBack callback, LPVOID customData);
//ö�ٽ�������ģ��
//    dwPID������pid
//    callBack���ص�
EXTERN_C M_API BOOL MEnumProcessModules(DWORD dwPID, EnumProcessModulesCallBack callback, LPVOID customData);
//ö�ٽ������о��
//    dwPID������pid
//    callBack���ص�
EXTERN_C M_API BOOL MEnumProcessHandles(DWORD pid, EHCALLBACK callback);
//ö�ٽ�������Ȩ��
//    dwPID������pid
//    callBack���ص�
M_CAPI(BOOL) MEnumProcessPrivileges(DWORD dwId, EnumPrivilegesCallBack callBack);

//�Ѵ��������ӵ�·��תΪ�ɷ��ʵ��ļ�·��
//    pszNtPath������·��
//    [OUT] pszFilePath������ļ�·��������
//    bufferSize������ļ�·���������ַ�����
EXTERN_C M_API BOOL MNtPathToFilePath(LPWSTR pszNtPath, LPWSTR pszFilePath, size_t bufferSize);
//��Dos·��תΪ�ں�·��
//    pszNtPath������Dos·��
//    [OUT] pszNtPath�����Nt·��������
EXTERN_C M_API BOOL MDosPathToNtPath(LPWSTR pszDosPath, LPWSTR pszNtPath);
//���ں�·��תΪ�ɷ��ʵ��ļ�·��
//    pszNtPath������·��
//    [OUT] pszDosPath������ļ�·��������
//    szDosPathSize������ļ�·���������ַ�����
EXTERN_C M_API DWORD MNtPathToDosPath(LPWSTR pszNtPath, LPWSTR pszDosPath, UINT szDosPathSize);
//���ļ������ȡ�ں�·��
//    hFile���ļ����
//    [OUT] pszNtPath������ں�·��������
//    pszNtPathSize������ں�·���������ַ�����
EXTERN_C M_API DWORD MGetNtPathFromHandle(HANDLE hFile, LPWSTR pszNtPath, UINT pszNtPathSize);

//����pid��ȡ��������·����R3��
//    dwPID������pid
//    [OUT] outNter���������·������������С��MAX_PATH��
//    [OUT] phandle��������̾�����˺������Զ��򿪽��̾������������򿪣���رգ�
//    pszExeName������������� (*.exe)
EXTERN_C M_API BOOL MGetProcessFullPathEx(DWORD dwPID, LPWSTR outNter, PHANDLE phandle, LPWSTR pszExeName);
//��ȡPE�ļ��İ�Ȩ��Ϣ
//    pszFullPath������·��
//    InfoItem����Ŀ�����¶�Ӧ��ͬ��Ϣ
//        	CompanyName
//        	FileDescription
//        	FileVersion
//        	InternalName
//        	LegalCopyright
//        	OriginalFilename
//        	ProductName
//        	ProductVersion
//        	Comments
//        	LegalTrademarks
//        	PrivateBuild
//        	SpecialBuild
//    [OUT] str������ַ���������
//    maxCount���ַ�����������С
EXTERN_C M_API BOOL MGetExeInfo(LPWSTR strFilePath, LPWSTR InfoItem, LPWSTR str, int maxCount);
//��ȡPE�ļ���˵����Ϣ
//    pszFullPath������·��
//    [OUT] str������ַ���������
//    maxCount���ַ�����������С
EXTERN_C M_API BOOL MGetExeDescribe(LPWSTR pszFullPath, LPWSTR str, int maxCount);
//��ȡPE�ļ��ķ�������Ϣ
//    pszFullPath������·��
//    [OUT] str������ַ���������
//    maxCount���ַ�����������С
EXTERN_C M_API BOOL MGetExeCompany(LPWSTR pszFullPath, LPWSTR str, int maxCount);
//��ȡEXE�ļ���ͼ��
//    pszFullPath������·��
EXTERN_C M_API HICON MGetExeIcon(LPWSTR pszFullPath);
//���һ�������ļ��Ƿ�ǩ�����������Ƿ����Σ�
//    pszFullPath������·��
EXTERN_C M_API BOOL MGetExeFileTrust(LPCWSTR pszFullPath);
//���һ�������ļ�ǩ��״̬
//[����]
//  ERROR_SUCCESS����ǩ��
//  TRUST_E_NOSIGNATURE��û��ǩ��
//  TRUST_E_SUBJECT_NOT_TRUSTED����ǩ�����ǲ�������
//  TRUST_E_EXPLICIT_DISTRUST����ǩ�����ǲ�������
//  CRYPT_E_SECURITY_SETTINGS������Ա�ѽ��ð�ȫѡ��
//  ������δ֪����
EXTERN_C M_API LONG MVerifyEmbeddedSignature(LPCWSTR pwszSourceFile);
//��ʾһ�������ļ���֤����Ϣ�Ի���
EXTERN_C M_API BOOL MShowExeFileSignatureInfo(LPCWSTR pwszSourceFile);

//�رվ��������ǿ�ƣ�
EXTERN_C M_API BOOL MCloseHandle(HANDLE handle);
//��ͨ��ͣ��������
//    dwPId������id��Ϊ 0 ʱʹ�� handle
//    handle�����̾����Ϊ NULL ʱʹ�� dwPId
EXTERN_C M_API NTSTATUS MSuspendProcessNt(DWORD dwPId, HANDLE handle);
//��ͨ������������
//    dwPId������id��Ϊ 0 ʱʹ�� handle
//    handle�����̾����Ϊ NULL ʱʹ�� dwPId
EXTERN_C M_API NTSTATUS MResumeProcessNt(DWORD dwPId, HANDLE handle);
//��ͨ�򿪽���
//    dwPId������id��Ϊ 0 ʱʹ�� handle
//    [OUT] pLhandle�����ؽ��̾��
EXTERN_C M_API NTSTATUS MOpenProcessNt(DWORD dwId, PHANDLE pLhandle);
//��ͨ��������
//    dwPId������id��Ϊ 0 ʱʹ�� handle
//    handle�����̾����Ϊ NULL ʱʹ�� dwPId
EXTERN_C M_API NTSTATUS MTerminateProcessNt(DWORD dwId, HANDLE handle);

//����UWPӦ��
//    packageName����������
//    appName��Ҫ�����İ��е� App ����
//  ������Google ��How to start a uwp app��
EXTERN_C M_API BOOL MRunUWPApp(LPWSTR packageName, LPWSTR appName);

//��ȡ���������в���
//    handle�����̾����Ϊ NULL ʱ��ʹ�� pid
//    [OUT] buffer������ַ���������
//    maxcount������ַ����������ַ�����
//    pid������id
EXTERN_C M_API BOOL MGetProcessCommandLine(HANDLE handle, LPWSTR buffer, int maxcount, DWORD pid = 0);
//��ȡ�����Ƿ���UWPӦ��
EXTERN_C M_API BOOL MGetProcessIsUWP(HANDLE handle);
//��ȡ�����Ƿ���32λ
EXTERN_C M_API BOOL MGetProcessIs32Bit(HANDLE handle);
//��ȡ���̵�GDI�������
M_API DWORD MGetProcessGdiHandleCount(HANDLE handle);
//��ȡ���̵��û��������
M_API DWORD MGetProcessUserHandleCount(HANDLE handle);
//��ȡ�����ں�EPROCESS��Ϣ
//    pid������id
//  �� M_SU_GetEPROCESS �ķ�װ
EXTERN_C M_API BOOL MGetProcessEprocess(DWORD pid, PPEOCESSKINFO info);
//��ȡ�����ڴ�ר�ù�����
//    hProcess�����̾��
//    pageSize����ҳһҳ��С
EXTERN_C M_API ULONG_PTR MGetProcessWorkingSetPrivate(HANDLE hProcess, SIZE_T pageSize);
//��ȡ���̻ỰID
//    pid������id
EXTERN_C M_API DWORD MGetProcessSessionID(DWORD pid);
//��ȡ�����û���
//    hProcess�����̾��
//    [OUT] buffer������ַ���������
//    len������ַ����������ַ�����
EXTERN_C M_API BOOL MGetProcessUserName(HANDLE hProcess, LPWSTR buffer, int maxcount);
//PSID->PUSERNAME
EXTERN_C M_API PUSERNAME MGetUserNameBySID(PSID sid);
//��ȡ�����߳���
EXTERN_C M_API ULONG MGetProcessThreadsCount(PSYSTEM_PROCESSES p);
//��ȡ���̾����
EXTERN_C M_API ULONG MGetProcessHandlesCount(PSYSTEM_PROCESSES p);
//=K32GetMappedFileName
EXTERN_C M_API NTSTATUS MGetProcessMappedFileName(HANDLE ProcessHandle, PVOID BaseAddress, LPWSTR OutFileName, int BufferSize);
//��ȡ����PEB��ַ
//    hProcess�����̾��
//    [OUT] pPpeb������PPEB����
EXTERN_C M_API NTSTATUS MGetProcessPeb(HANDLE handle, PPEB* pPpeb);
//��ȡ���� Win32 ·��
//    ProcessHandle�����̾��
//    [OUT] FileNameBuffer������ַ���������
//    FileNameBufferSize������ַ����������ַ�����
EXTERN_C M_API NTSTATUS MGetProcessImageFileNameWin32(HANDLE ProcessHandle, LPWSTR FileNameBuffer, ULONG FileNameBufferSize);
//��ȡ����·��
//    ProcessHandle�����̾��
//    [OUT] FileNameBuffer������ַ���������
//    FileNameBufferSize������ַ����������ַ�����
EXTERN_C M_API NTSTATUS MGetProcessImageFileName(HANDLE ProcessHandle, LPWSTR FileNameBuffer, ULONG FileNameBufferSize);
//��ȡ����PROCESS_BASIC_INFORMATION
//    ProcessHandle�����̾��
//    [OUT] BasicInformation������PROCESS_BASIC_INFORMATION�ṹ�����
EXTERN_C M_API NTSTATUS MGetProcessBasicInformation(HANDLE ProcessHandle, PPROCESS_BASIC_INFORMATION BasicInformation);
//��ȡ����������־
//    ProcessHandle�����̾��
//    [OUT] ExecuteFlags������ExecuteFlags��Ϣ����
EXTERN_C M_API NTSTATUS MGetProcessExecuteFlags(HANDLE ProcessHandle, PULONG ExecuteFlags);
//��ȡ����IO���ȼ�
//    ProcessHandle�����̾��
//    [OUT] IoPriority������IO_PRIORITY_HINT��Ϣ�ṹ�����
EXTERN_C M_API NTSTATUS MGetProcessIoPriority(HANDLE ProcessHandle, IO_PRIORITY_HINT *IoPriority);
//��ȡ���� ExitStatus
//    ProcessHandle�����̾��
//    [OUT] ExitStatus��������Ϣ����
EXTERN_C M_API NTSTATUS MGetProcessExitStatus(HANDLE ProcessHandle, NTSTATUS *ExitStatus);
//��ȡ���� BasePriority
//    ProcessHandle�����̾��
//    [OUT] BasePriority��������Ϣ����
EXTERN_C M_API NTSTATUS MGetProcessBasePriority(HANDLE ProcessHandle, PULONG BasePriority);
//��ȡ���� AffinityMask
//    ProcessHandle�����̾��
//    [OUT] AffinityMask��������Ϣ����
EXTERN_C M_API NTSTATUS MGetProcessAffinityMask(HANDLE ProcessHandle, PULONG_PTR AffinityMask);

EXTERN_C M_API NTSTATUS MGetProcessDebugObject(HANDLE ProcessHandle, PHANDLE DebugObjectHandle);

NTSTATUS MSetProcessPriorityClass(HANDLE ProcessHandle, UCHAR PriorityClass);
NTSTATUS MSetProcessAffinityMask(HANDLE ProcessHandle, ULONG_PTR AffinityMask);

//��ȡUWPӦ����������
//    handle�����̾��
//    [OUT] len������ַ����������ַ�����
//    [OUT] buffer������ַ���������
EXTERN_C M_API BOOL MGetUWPPackageFullName(HANDLE handle, int * len, LPWSTR buffer);
//��ȡ����״̬
//[����]
//  3������Ӧ/2����ͣ/1����������/0��δ֪
//    p��ö�������Ľ�����Ϣ�ṹ
//    hWnd��������̵�������
EXTERN_C M_API int MGetProcessState(PSYSTEM_PROCESSES p, HWND hWnd);
//��ȡSYSTEM_PROCESSES�µ�SYSTEM_THREADS
EXTERN_C M_API PSYSTEM_THREADS MGetProcessThreads(DWORD pid);
//��ȡ����pid�ڽ����б����ȡ SYSTEM_PROCESSES �ṹ������� MEnumProcessCore(); ˢ���б�
EXTERN_C M_API PSYSTEM_PROCESSES MGetProcessInfo(DWORD pid);

EXTERN_C M_API PPEB MGetCurrentPeb();
EXTERN_C M_API PTEB MGetCurrentTeb();












