#pragma once
#include "stdafx.h"
#include "appmodel.h"
#include "appxpackaging.h"

//��ȡCPU������
M_CAPI(int) MPERF_GetProcessNumber();
//��ȡCPUʹ���ʣ�0-1��
M_CAPI(double) MPERF_GetCupUseAge();
//ˢ���ڴ�״̬
M_CAPI(BOOL) MPERF_GetRamUseAge();
//��ȡ�ڴ�ʹ���ʣ��ڵ��� MPERF_GetRamUseAge ����Ч
M_CAPI(double) MPERF_GetRamUseAge2();

void MPERF_FreeCpuInfos();

//��ȡ�����ڴ��С
M_CAPI(ULONGLONG) MPERF_GetAllRam();
//��ȡ���з�ҳ�ڴ��С
M_CAPI(ULONGLONG) MPERF_GetPageSize();
//��ȡ�����ں˷�ҳ�ڴ��С
M_CAPI(ULONGLONG) MPERF_GetKernelPaged();
//��ȡ�����ں˷Ƿ�ҳ�ڴ��С
M_CAPI(ULONGLONG) MPERF_GetKernelNonpaged();
//��ȡ�����ں˻����С
M_CAPI(ULONGLONG) MPERF_GetSystemCacheSize();
//��ȡ�������ύ��С
M_CAPI(ULONGLONG) MPERF_GetCommitTotal();
//��ȡ�������ύ��С��
M_CAPI(ULONGLONG) MPERF_GetCommitPeak();
//��ȡ�����ڴ�
M_CAPI(ULONGLONG) MPERF_GetRamAvail();
//��ȡ���÷�ҳ�ڴ�
M_CAPI(ULONGLONG) MPERF_GetRamAvailPageFile();

//����������Ϣ�ṹ
struct MPerfAndProcessData
{
	__int64 NowCpuTime;
	__int64 LastCpuTime;
	ULONGLONG LastRead;
	ULONGLONG LastWrite;
	ULONG64 NetWorkInBandWidth;
	ULONG64 NetWorkOutBandWidth;

	PACKAGE_ID* packageId=NULL;
};

//�ͷ����н��̵�������Ϣ
M_CAPI(void) MPERF_NET_FreeAllProcessNetInfo();

//��ȡCPU������
M_CAPI(int) MPERF_GetProcessNumber();
//��ȡCPUһ������
M_CAPI(DWORD) MPERF_GetCpuL1Cache();
//��ȡCPU��������
M_CAPI(DWORD) MPERF_GetCpuL2Cache();
//��ȡCPU��������
M_CAPI(DWORD) MPERF_GetCpuL3Cache();
//��ȡ����CPU��
M_CAPI(DWORD) MPERF_GetCpuPackage();
//��ȡCPU�����
M_CAPI(DWORD) MPERF_GetCpuNodeCount();
//��ȡCPU����
//    [OUT] buf��CPU�����ַ���������
//    size��CPU�����ַ����������ַ�����
M_CAPI(BOOL) MPERF_GetCpuName(LPWSTR buf, int size);
//��ȡCPU��Ƶ
M_CAPI(int) MPERF_GetCpuFrequency();

//��ȡ����CPU��Ϣ��ֻ��ʹ�ô˷����Ժ� MPERF_GetCpuxxx ��ȡ����Ϣ����Ч
M_CAPI(BOOL) MPERF_GetCpuInfos();




