#pragma once
#include "stdafx.h"
#include "ntdef.h"

//��ͨ���߳�
//    dwId��thread id
//    [OUT] pLandle������߳̾��
//    dwPId������id������Ϊ 0
EXTERN_C M_API NTSTATUS MOpenThreadNt(DWORD dwId, PHANDLE pLandle, DWORD dwPId);
//��ͨ�����߳�
//    hThread���߳̾��
EXTERN_C M_API NTSTATUS MTerminateThreadNt(HANDLE hThread);
//��ͨ�����߳�����
//    hThread���߳̾��
EXTERN_C M_API NTSTATUS MResumeThreadNt(HANDLE hThread);
//��ͨ��ͣ�߳�����
//    hThread���߳̾��
EXTERN_C M_API NTSTATUS MSuspendThreadNt(HANDLE hThread);
//��ȡ�߳� TEB ��ַ
//    hThread���߳̾��
EXTERN_C M_API PTEB MGetThreadPeb(HANDLE hThread);
//��ȡ�߳���ʼ��ַ
//    hThread���߳̾��
EXTERN_C M_API PVOID MGetThreadWin32StartAddress(HANDLE hThread);