#pragma once
#include "stdafx.h"
#include "sysstructs.h"

DWORD WINAPI MDbgViewReceiveThread(LPVOID lpParameter);
DWORD WINAPI MLoadingThread(LPVOID lpParameter);

//MyDbgView�ر�
M_CAPI(BOOL) MUnInitMyDbgView();
//���� MyDbgView
M_CAPI(BOOL) MInitMyDbgView();
M_CAPI(BOOL) MMyDbgViewStarted();

//ǿ�Ʋ����� MyDbgView
M_CAPI(VOID) MDoNotStartMyDbgView();
//�����ں˵�pdb
M_CAPI(BOOL) MInitKernelNTPDB(BOOL usingNtosPDB, PKNTOSVALUE kNtosValue);
//�����ں˵�pdb�ͷ���Դ
M_CAPI(BOOL) MUnInitKernelNTPDB();

VOID MLoadKernelNTPDB(PKNTOSVALUE kNtosValue, BOOL usingNtosPDB);

M_CAPI(BOOL) MIsKernelNeed64();

//��ȡPCMgr�ں������Ƿ����
M_CAPI(BOOL) MCanUseKernel();
//����PCMgr�ں�����
M_CAPI(BOOL) MInitKernel();
//ж��PCMgr�ں�����
M_CAPI(BOOL) MUninitKernel();
BOOL MShowMyDbgView();

//��������
//    lpszDriverName�������ķ�����
//    driverPath������������·��
//    lpszDisplayName��nullptr
M_CAPI(BOOL) MLoadKernelDriver(LPWSTR lpszDriverName, LPWSTR driverPath, LPWSTR lpszDisplayName);
//ж������
//    szSvrName��������
M_CAPI(BOOL) MUnLoadKernelDriver(LPWSTR szSvrName);

//��ȡntoskrn.exe����ַ���ں˼����Ժ���Ч��
M_CAPI(ULONG_PTR) MGetNTBaseAddress();

M_CAPI(void) MInitKernelSwitchMenuState(BOOL loaded);
M_CAPI(BOOL) MInitKernelDriverHandleEndStep(HANDLE hHandle);
