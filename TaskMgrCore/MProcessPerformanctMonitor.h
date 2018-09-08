#pragma once
#include "stdafx.h"
#include "perfhlp.h"
#include "prochlp.h"
#include <vector>


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


//�������ܼ�����
class M_API MProcessPerformanctMonitor
{
	static SIZE_T GetProcessPrivateWoringSet(PMPROCESS_ITEM processItem);
	static SIZE_T GetProcessIOSpeed(PMPROCESS_ITEM processItem);
	static ULONG64 GetProcessNetworkSpeed(PMPROCESS_ITEM processItem);

	static double GetProcessCpuUseAgeKernel(PMPROCESS_ITEM processItem);
	static double GetProcessCpuUseAgeUser(PMPROCESS_ITEM processItem);
	static double GetProcessCpuUseAge(PMPROCESS_ITEM processItem);

	static ULONGLONG GetProcessCpuTime(PMPROCESS_ITEM processItem);
	static ULONGLONG GetProcessCycle(PMPROCESS_ITEM processItem);
	//��ȡ�����ڴ���Ϣ
	//    p��������Ϣ���
	//    col����Ϣ���M_GET_PROCMEM_*���������ж���
	static SIZE_T GetProcessMemoryInfo(PMPROCESS_ITEM processItem, int col);
	//��ȡ����IO��Ϣ
	//    p��������Ϣ���
	//    col����Ϣ���M_GET_PROCIO_*���������ж���
	static ULONGLONG GetProcessIOInfo(PMPROCESS_ITEM processItem, int col);
};

