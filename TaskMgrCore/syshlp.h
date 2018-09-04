#pragma once
#include "stdafx.h"
#include "ntdef.h"
#include "sysfuns.h"

#define PTR_ADD_OFFSET(Pointer, Offset) ((PVOID)((ULONG_PTR)(Pointer) + (ULONG_PTR)(Offset)))
#define PTR_SUB_OFFSET(Pointer, Offset) ((PVOID)((ULONG_PTR)(Pointer) - (ULONG_PTR)(Offset)))

BOOL MGetDebuggerInformation();

//��ʾ�����С��Ի���hwndOwner���Լ��Ĵ��ھ��������ȫ����NULL��
M_CAPI(BOOL) MRunFileDlg(HWND hwndOwner, HICON hIcon, LPCWSTR lpszDirectory, LPCWSTR lpszTitle, LPCWSTR lpszDescription, ULONG uFlags);
//ϵͳ�Ƿ���64λ
M_CAPI(BOOL) MIs64BitOS();
//������Ȩ
M_CAPI(BOOL) MGetPrivileges();
//��ȡ�����Ƿ��Թ���Ա�������
M_CAPI(BOOL) MIsRunasAdmin();

//���ݵ����������ƻ�����ҳ�ģ��ĵ�������
//    DllHandle��ģ����
//    ProcedureName�������������Ϊ NULL ��ʹ�� ProcedureNumber �����ң�
//    ProcedureNumber�������������
M_CAPI(PVOID) MGetProcedureAddress(PVOID DllHandle, PSTR ProcedureName, ULONG ProcedureNumber);
//���� GetProcAddress���Լ�ʵ�ֵģ�
M_CAPI(PVOID) MGetProcAddress(PVOID DllHandle, PSTR ProcedureName);

//��ȡϵͳ��������ʶ
M_CAPI(BOOL) MGetSystemAffinityMask(PULONG_PTR SystemAffinityMask);

//������תΪ�ļ�·��
//    cmdline��������
//    [OUT] buffer������ļ�·��������
//    size������ļ�·���������ַ�����
M_CAPI(BOOL) MCommandLineToFilePath(LPWSTR cmdline, LPWSTR buffer, int size);
//������תΪ�ļ�·���Ͳ���
//    cmdline��������
//    [OUT] buffer������ļ�·��������
//    size������ļ�·���������ַ�����
//    [OUT] argbuffer���������������
//    argbuffersize����������������ַ�����
M_CAPI(BOOL) MCommandLineSplitPath(LPWSTR cmdline, LPWSTR buffer, int size, LPWSTR argbuffer, int argbuffersize);

//��ȡϵͳ Bulid �汾������ MGetWindowsBulidVersion �Ժ���Ч��
M_CAPI(DWORD) MGetWindowsBulidVersionValue();

//��ȡϵͳ�ǲ���Win8���ϣ����� MGetWindowsBulidVersion �Ժ���Ч��
M_CAPI(BOOL) MGetWindowsWin8Upper();

//��ȡ Windows Bulid Version
M_CAPI(BOOL) MGetWindowsBulidVersion();
//����һ��EXE
//    path��·��
//    args������
//    runAsadmin���Ƿ��Թ���Ա�������
//    hWnd�������ߴ���
M_CAPI(BOOL) MRunExe(LPWSTR path, LPWSTR args, BOOL runAsadmin, HWND hWnd);
//����һ��EXE
//    pathargs��·�����ɴ�������
//    runAsadmin���Ƿ��Թ���Ա�������
//    hWnd�������ߴ���
M_CAPI(BOOL) MRunExeWithAgrs(LPWSTR pathargs, BOOL runAsadmin, HWND hWnd);

//��ȡ Ntos And Win32 �Ļ���ַ
M_CAPI(BOOL) MGetNtosAndWin32kfullNameAndStartAddress(LPWSTR name, size_t buffersize, ULONG_PTR *address, ULONG_PTR *win32kfulladdress);

//VK��ֵתΪ�ַ���
M_CAPI(LPWSTR) MKeyToStr(UINT vk);
//�ȼ�תΪ�ַ���
M_CAPI(BOOL) MHotKeyToStr(UINT fsModifiers, UINT vk, LPWSTR buffer, int size);

//�����ַ�������������
//    const WCHAR * pszData����Ҫ���Ƶ��ַ���
//    const size_t nDataLen ����Ҫ���Ƶ��ַ����ַ�����������\0��
EXTERN_C M_API BOOL MCopyToClipboard(const WCHAR * pszData, const size_t nDataLen);
//�����ַ�������������
//    const WCHAR * pszData����Ҫ���Ƶ��ַ���
EXTERN_C M_API BOOL MCopyToClipboard2(const WCHAR * pszData);

