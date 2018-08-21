#pragma once
#include "stdafx.h"
#include "perfhlp.h"
#include "ntdef.h"

typedef void(__cdecl*EnumProcessCallBack)(DWORD pid, DWORD parentid, LPWSTR exename, LPWSTR exefullpath, int tp, HANDLE hProcess, PSYSTEM_PROCESSES proc);
typedef void(__cdecl*EnumProcessCallBack2)(DWORD pid, PSYSTEM_PROCESSES proc);

typedef struct tag_PEOCESSKINFO {
	WCHAR Eprocess[32];
	WCHAR PebAddress[32];
	WCHAR JobAddress[32];
	WCHAR ImageFileName[MAX_PATH];
	WCHAR ImageFullName[MAX_PATH];
}PEOCESSKINFO,*PPEOCESSKINFO;

BOOL LoadDll();
void FreeDll();
void MFroceKillProcessUser();
void MKillProcessUser(BOOL ask);
void MKillProcessTreeUser();

EXTERN_C M_API BOOL MKillProcessUser2(DWORD pid, BOOL showErr);

//������Ȩ
EXTERN_C M_API BOOL MGetPrivileges2();
//ˢ�½����б�
EXTERN_C M_API void MEnumProcessCore();
//ˢ�½����б���ͷ���Դ����
EXTERN_C M_API void MEnumProcessFree();
//ö�ٽ���
//    callBack���ص�
EXTERN_C M_API void MEnumProcess(EnumProcessCallBack callBack);
//��ö�ٽ���
//    callBack���򵥻ص�
EXTERN_C M_API void MEnumProcess2Refesh(EnumProcessCallBack2 callBack);
EXTERN_C M_API BOOL MReUpdateProcess(DWORD pid, EnumProcessCallBack calBack);

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
//    handle�����̾����Ϊ NULL ʱʹ�� dwPId
EXTERN_C M_API NTSTATUS MOpenProcessNt(DWORD dwId, PHANDLE pLandle);
//��ͨ��������
//    dwPId������id��Ϊ 0 ʱʹ�� handle
//    handle�����̾����Ϊ NULL ʱʹ�� dwPId
EXTERN_C M_API NTSTATUS MTerminateProcessNt(DWORD dwId, HANDLE handle);

//����UWPӦ��
//    packageName����������
//    name�����е� App ����
//  ������Google ��How to start a uwp app��
EXTERN_C M_API BOOL MRunUWPApp(LPWSTR packageName, LPWSTR name);

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
//��ȡ�����ں�EPROCESS��Ϣ
//    pid������id
//  �� M_SU_GetEPROCESS �ķ�װ
EXTERN_C M_API BOOL MGetProcessEprocess(DWORD pid, PPEOCESSKINFO info);
//��ȡ�����ڴ�ר�ù�����
//    hProcess�����̾��
//    pageSize����ҳһҳ��С
M_API ULONG_PTR MGetProcessWorkingSetPrivate(HANDLE hProcess, SIZE_T pageSize);
//��ȡUWPӦ����������
//    handle�����̾��
//    [OUT] len������ַ����������ַ�����
//    [OUT] buffer������ַ���������
EXTERN_C M_API BOOL MGetUWPPackageFullName(HANDLE handle, int * len, LPWSTR buffer);
//��ȡ����״̬
//  2����ͣ/1����������/0��δ֪
//    p��ö�������Ĳ���
//    hWnd��0
EXTERN_C M_API int MGetProcessState(PSYSTEM_PROCESSES p, HWND hWnd);
//��ȡSYSTEM_PROCESSES�µ�SYSTEM_THREADS
EXTERN_C M_API VOID* MGetProcessThreads(DWORD pid);
//��ȡ����pid�ڽ����б����ȡ SYSTEM_PROCESSES �ṹ������� MEnumProcessCore(); ˢ���б�
EXTERN_C M_API PSYSTEM_PROCESSES MGetProcessInfo(DWORD pid);
//��ȡϵͳ�ڴ�ʹ���ʣ�0-1��
EXTERN_C M_API double MGetRamUseAge();
//��ȡϵͳ�����ڴ��С��MB��
EXTERN_C M_API ULONG MGetAllRam();












