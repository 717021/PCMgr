#pragma once
#include "stdafx.h"
#include "ntdef.h"
#include "sysfuns.h"

//��ʾ�����С��Ի���
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
//���� GetProcAddress
M_CAPI(PVOID) MGetProcAddress(PVOID DllHandle, PSTR ProcedureName);

//������תΪ�ļ�·��
//    cmdline��������
//    [OUT] buffer������ļ�·��������
//    size������ļ�·���������ַ�����
M_CAPI(BOOL) MCommandLineToFilePath(LPWSTR cmdline, LPWSTR buffer, int size);

//��ȡϵͳ Bulid �汾������ MGetWindowsBulidVersion �Ժ���Ч��
M_CAPI(DWORD) MGetWindowsBulidVersionValue();

//��ȡϵͳ�ǲ���Win8���ϣ����� MGetWindowsBulidVersion �Ժ���Ч��
M_CAPI(BOOL) MGetWindowsWin8Upper();

//��ȡ Windows Bulid Version
M_CAPI(BOOL) MGetWindowsBulidVersion();
//����һ��EXE
//    path��·��
//    args������
//    runAsadmin���Ƿ���
M_CAPI(BOOL) MRunExe(LPWSTR path, LPWSTR args, BOOL runAsadmin, HWND hWnd);

//��ȡ Ntos And Win32 �Ļ���ַ
M_CAPI(BOOL) MGetNtosAndWin32kfullNameAndStartAddress(LPWSTR name, size_t buffersize, ULONG_PTR *address, ULONG_PTR *win32kfulladdress);

//VK��ֵתΪ�ַ���
M_CAPI(LPWSTR) MKeyToStr(UINT vk);
//�ȼ�תΪ�ַ���
M_CAPI(BOOL) MHotKeyToStr(UINT fsModifiers, UINT vk, LPWSTR buffer, int size);

