#pragma once
#include "stdafx.h"
#include "ntdef.h"

//��ͨ���߳�
//    dwId��thread id
//    [OUT] pLandle������߳̾��
//    dwPId������id������Ϊ 0
EXTERN_C M_API NTSTATUS MOpenThreadNt(DWORD dwId, PHANDLE pLandle, DWORD dwPId);
//��ȡ�̻߳�����Ϣ
//    ThreadHandle���߳̾��
//    BasicInformation������THREAD_BASIC_INFORMATION�ṹ�����
EXTERN_C M_API NTSTATUS MGetThreadBasicInformation(HANDLE ThreadHandle, PTHREAD_BASIC_INFORMATION BasicInformation);
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
//    [OUT] pPTeb������PTEB��Ϣ����
EXTERN_C M_API NTSTATUS MGetThreadPeb(HANDLE hThread, PTEB*pPTeb);
//��ȡ�߳���ʼ��ַ
//    hThread���߳̾��
//    [OUT] outStartAddress�����ձ���
EXTERN_C M_API NTSTATUS MGetThreadWin32StartAddress(HANDLE hThread, PVOID * outStartAddress);