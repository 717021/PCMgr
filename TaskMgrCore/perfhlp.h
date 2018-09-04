#pragma once
#include "stdafx.h"
#include "uwphlp.h"
#include "ntdef.h"
#include <Pdh.h>
#include <PdhMsg.h>

//�ڴ湤��������
#define M_GET_PROCMEM_WORKINGSET 0
//ר���ڴ湤����
#define M_GET_PROCMEM_WORKINGSETPRIVATE 1
//�����ڴ湤����
#define M_GET_PROCMEM_WORKINGSETSHARE 2
//��ֵ�ڴ湤��������
#define M_GET_PROCMEM_PEAKWORKINGSET 3
//�ύ��С
#define M_GET_PROCMEM_COMMITEDSIZE 4
//�Ƿ�ҳ�ڴ�
#define M_GET_PROCMEM_NONPAGEDPOOL 5
//��ҳ�ڴ�
#define M_GET_PROCMEM_PAGEDPOOL 6
//ҳ�����
#define M_GET_PROCMEM_PAGEDFAULT 7

//IO��ȡ������
#define M_GET_PROCIO_READ 0
//IOд�������
#define M_GET_PROCIO_WRITE 1
//IO����������
#define M_GET_PROCIO_OTHER 2
//IO��ȡ�ֽ�
#define M_GET_PROCIO_READ_BYTES 3
//IOд���ֽ�
#define M_GET_PROCIO_WRITE_BYTES 4
//IO�����ֽ�
#define M_GET_PROCIO_OTHER_BYTES 5

//��ȡCPU������
M_CAPI(int) MPERF_GetProcessNumber();
//��ȡCPUʹ���ʣ�0-1��
M_CAPI(double) MPERF_GetCupUseAge();
//ˢ���ڴ�״̬
M_CAPI(BOOL) MPERF_GetRamUseAge();
//��ȡ�ڴ�ʹ���ʣ��ڵ��� MPERF_GetRamUseAge ����Ч
M_CAPI(double) MPERF_GetRamUseAge2();

//��ʼ��PDH��
M_CAPI(BOOL) MPERF_GlobalInit();
//�ͷ�PDH��
M_CAPI(VOID) MPERF_GlobalDestroy();
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
//��ȡ�������ύ������
M_CAPI(ULONGLONG) MPERF_GetCommitLimit();
//��ȡ�����ڴ�
M_CAPI(ULONGLONG) MPERF_GetRamAvail();
//��ȡ�����ڴ�
M_CAPI(ULONGLONG) MPERF_GetRamUsed();
//��ȡ���÷�ҳ�ڴ�
M_CAPI(ULONGLONG) MPERF_GetRamAvailPageFile();
//ˢ��������Ϣ��ˢ���Ժ�����ĺ���������
M_CAPI(BOOL) MPERF_UpdatePerformance();

//����������Ϣ�ݴ�ṹ
struct MPerfAndProcessData
{
	__int64 NowCpuTime;
	__int64 LastCpuTime;

	ULONGLONG LastRead;
	ULONGLONG LastWrite;

	ULONG64 InBandwidth;
	ULONG64 OutBandwidth;
	ULONG64 InBandwidth6;
	ULONG64 OutBandwidth6;
	ULONG64 ConnectCount;

	ULONG64 LastBandwidth;

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

//ö�����ܼ����������е�ʵ������
//    counterName����Ҫö�ٵ����ܼ�����
//    ���أ���������ʵ�����ƣ���"\0\0"��β����Ҫ�ֶ�����free�ͷţ�
M_CAPI(LPWSTR) MPERF_EnumPerformanceCounterInstanceNames(LPWSTR counterName);

//�������ܼ������ṹ
struct MPerfDiskData
{
	//Disk Reads/sec
	PDH_HCOUNTER*performanceCounter_read;
	//Disk Writes/sec
	PDH_HCOUNTER*performanceCounter_write;
	//Disk Read Bytes/sec
	PDH_HCOUNTER*performanceCounter_readSpeed;
	//Disk Write Bytes/sec
	PDH_HCOUNTER*performanceCounter_writeSpeed;
	//Avg. Disk Queue Length
	PDH_HCOUNTER*performanceCounter_avgQue;

	//Name
	WCHAR performanceCounter_Name[32];

};
//�������ܼ������ṹ
struct MPerfNetData
{
	//Bytes Sent/sec
	PDH_HCOUNTER*performanceCounter_sent;
	//Bytes Received/sec
	PDH_HCOUNTER*performanceCounter_receive;
	//Bytes Total/sec
	PDH_HCOUNTER*performanceCounter_total;

	//Name
	WCHAR performanceCounter_Name[64];
};

//�����������������ݴ�ṹ������ÿ���ʹ����/�ٶȵ�ʱ��Ҫ�ã����õ�ʱ��Ҫ�ͷţ�
M_CAPI(MPerfAndProcessData*) MPERF_PerfDataCreate();
//�ͷŽ������������ݴ�ṹ
M_CAPI(void) MPERF_PerfDataDestroy(MPerfAndProcessData*data);
//ˢ��CPUʱ����������cpuʹ��������ʱ��ÿ��һ��ʱ����ã�
M_CAPI(void) MPERF_CpuTimeUpdate();
//��ȡ����CPUʹ����
//    p��������Ϣ���
//    data�����������ݴ�ṹ
M_CAPI(double) MPERF_GetProcessCpuUseAge(PSYSTEM_PROCESSES p, MPerfAndProcessData*data);
//��ȡ�����ܵ�CPUʱ��
//    p��������Ϣ���
M_CAPI(ULONGLONG) MPERF_GetProcessCpuTime(PSYSTEM_PROCESSES p);
//��ȡ��������
//    p��������Ϣ���
M_CAPI(ULONGLONG) MPERF_GetProcessCycle(PSYSTEM_PROCESSES p);
//��ȡ�����ڴ�ר�ù�����
//    p��������Ϣ���
//    hProcess��Reserved
M_CAPI(SIZE_T) MPERF_GetProcessRam(PSYSTEM_PROCESSES p, HANDLE hProcess);
//��ȡ�����ڴ���Ϣ
//    p��������Ϣ���
//    col����Ϣ���M_GET_PROCMEM_*���������ж���
M_CAPI(SIZE_T) MPERF_GetProcessMemoryInfo(PSYSTEM_PROCESSES p, int col);
//��ȡ����IO��Ϣ
//    p��������Ϣ���
//    col����Ϣ���M_GET_PROCIO_*���������ж���
M_CAPI(ULONGLONG) MPERF_GetProcessIOInfo(PSYSTEM_PROCESSES p, int col);
//��ȡ���̴���ʹ����
//    p��������Ϣ���
//    data�����������ݴ�ṹ
M_CAPI(DWORD) MPERF_GetProcessDiskRate(PSYSTEM_PROCESSES p, MPerfAndProcessData*data);



