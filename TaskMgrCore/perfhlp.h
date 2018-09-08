#pragma once
#include "stdafx.h"
#include "uwphlp.h"
#include "DltHlp.h"
#include "ntdef.h"
#include <Pdh.h>
#include <PdhMsg.h>


//��ʼ��PDH��
M_CAPI(BOOL) MPERF_GlobalInit();
//�ͷ�PDH��
M_CAPI(VOID) MPERF_GlobalDestroy();


//����������Ϣ�ݴ�ṹ
struct MPerfAndProcessData
{
	DWORD ProcessId;

	FLOAT CpuUserUsage;
	FLOAT CpuKernelUsage;

	MUINT64_DELTA CpuKernelDelta;
	MUINT64_DELTA CpuUserDelta;
	MUINT64_DELTA PageFaultsDelta;
	MUINT64_DELTA CycleTimeDelta; // since WIN7

	MUINT64_DELTA IoReadDelta;
	MUINT64_DELTA IoWriteDelta;
	MUINT64_DELTA IoOtherDelta;
	MUINT64_DELTA IoReadCountDelta;
	MUINT64_DELTA IoWriteCountDelta;
	MUINT64_DELTA IoOtherCountDelta;

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




