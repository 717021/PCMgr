#include "stdafx.h"
#include "MProcessMonitor.h"
#include "MSystemPerformanctMonitor.h"
#include "loghlp.h"

using namespace std;

#define LPVOID_PID(ptr) ((DWORD)(ULONG_PTR)ptr)
#define PSYP_PID(ptr) ((DWORD)(ULONG_PTR)ptr->ProcessId)

extern PSYSTEM_PROCESSES current_system_process;

extern NtQuerySystemInformationFun NtQuerySystemInformation;
extern RtlNtStatusToDosErrorFun RtlNtStatusToDosError;

SYSTEM_PROCESSES InterruptsProcessInformation;

//Pubilc Interface

MProcessMonitor::MProcessMonitor()
{

}
MProcessMonitor::~MProcessMonitor()
{

}

MProcessMonitor * MProcessMonitor::CreateProcessMonitor(ProcessMonitorRemoveItemCallBack removeItemCallBack, ProcessMonitorNewItemCallBack newItemCallBack, ProcessMonitorUpdateNotIncludeItemCallBack updateNotIncludeItemCallBack)
{
	return new MProcessMonitorCore(removeItemCallBack, newItemCallBack, updateNotIncludeItemCallBack);
}
void MProcessMonitor::DestroyProcessMonitor(MProcessMonitor *m)
{
	delete m;
}

BOOL MProcessMonitor::EnumAllProcess(MProcessMonitor * monitor)
{
	return monitor->EnumAllProcess();
}
BOOL MProcessMonitor::RefeshAllProcess(MProcessMonitor * monitor)
{
	return monitor->RefeshAllProcess();
}
BOOL MProcessMonitor::RefeshAllProcessNotInclude(MProcessMonitor * monitor)
{
	return monitor->RefeshAllProcessNotInclude();
}

//Core
MProcessMonitorCore::MProcessMonitorCore(ProcessMonitorRemoveItemCallBack removeItemCallBack, ProcessMonitorNewItemCallBack newItemCallBack, ProcessMonitorUpdateNotIncludeItemCallBack updateNotIncludeItemCallBack)
{
	RemoveItemCallBack = removeItemCallBack;
	NewItemCallBack = newItemCallBack;
	UpdateNotIncludeItemCallBack = updateNotIncludeItemCallBack;

	processesStorage = nullptr;
	validPidsEnd = &validPids;
	memset(&allProcessItems, 0, sizeof(allProcessItems));
	allProcessItemsEnd = &allProcessItems;

	memset(&InterruptsProcessInformation, 0, sizeof(InterruptsProcessInformation));
	InterruptsProcessInformation.ProcessId = (LPVOID)(ULONG_PTR)2UL;

	InitializeCriticalSection(&cs);
}
MProcessMonitorCore::~MProcessMonitorCore()
{
	FreeAllProcessItems();
	FreeProcessBuffer();
	ClearVaildPids();

	DeleteCriticalSection(&cs);
}

//Global Enum and Refesh
bool MProcessMonitorCore::EnumAllProcess()
{
	EnterCriticalSection(&cs);

	if (RefreshProcessBuffer())
	{
		FreeAllProcessItems();
		ClearVaildPids();

		MSystemPerformanctMonitor::UpdateCpuGlobal();
		MSystemPerformanctMonitor::UpdateCpuInformation();

		RefreshVaildPids();
		RefreshAllProcessItem();

		LeaveCriticalSection(&cs);

		return true;
	}

	LeaveCriticalSection(&cs);

	return false;
}
bool MProcessMonitorCore::RefeshAllProcess()
{
	EnterCriticalSection(&cs);

	if (RefreshProcessBuffer()) 
	{
		ClearVaildPids();

		MSystemPerformanctMonitor::UpdateCpuGlobal();
		MSystemPerformanctMonitor::UpdateCpuInformation();

		//ˢ�½��̹�ϵ
		RefreshVaildPids();
		RefreshAllProcessItem();

		LeaveCriticalSection(&cs);
		return true;
	}

	LeaveCriticalSection(&cs);
	return false;
}
bool MProcessMonitorCore::RefeshAllProcessNotInclude()
{
	EnterCriticalSection(&cs);

	if (UpdateNotIncludeItemCallBack)
	{
		if (allProcessItems.Next)//��ѭ������ˢ����Ŀ�Լ�cpu��Ϣ
		{
			PMPROCESS_ITEM item = &allProcessItems;
			PMPROCESS_ITEM pn = allProcessItems.Next;
			do {
				item = pn;
				pn = item->Next;

				if (!UpdateNotIncludeItemCallBack(item->ProcessId))
				{
					PSYSTEM_PROCESSES p = item->Data;

					WCHAR exeFullPath[260];
					memset(exeFullPath, 0, sizeof(exeFullPath));

					HANDLE hProcess = NULL; 
					MGetProcessFullPathEx(static_cast<DWORD>((ULONG_PTR)p->ProcessId), exeFullPath, &hProcess, p->ImageName.Buffer);

					NewItemCallBack(static_cast<DWORD>((ULONG_PTR)p->ProcessId), static_cast<DWORD>((ULONG_PTR)p->InheritedFromProcessId), p->ImageName.Buffer, exeFullPath, hProcess, item);
				}

			} while (pn);
		}
		LeaveCriticalSection(&cs);
		return true;
	}
	LeaveCriticalSection(&cs);
	return false;
}

//Clears
void MProcessMonitorCore::FreeAllProcessItems()
{
	PMPROCESS_ITEM pi = &allProcessItems;
	allProcessItemsEnd = &allProcessItems;
	if (pi->Next)
	{
		PMPROCESS_ITEM pn = pi->Next;
		do {
			pi = pn;
			pn = pi->Next;
			if (pi->PerfData)
				delete pi->PerfData;
			free(pi);
		} while (pn);
	}
	allProcessItemsEnd->Next = nullptr;
}
void MProcessMonitorCore::FreeProcessBuffer()
{
	if (currentProcessBuffer)
	{
		free(currentProcessBuffer);
		currentProcessBuffer = nullptr;
		current_system_process = nullptr;
	}
 	if (processesStorage)
	{
		free(processesStorage);
		processesStorage = nullptr;
	}
}
void MProcessMonitorCore::ClearVaildPids()
{
	PSTG_PID_ITEM pp = &validPids;
	if (pp) 
	{
		if (pp->Next)
		{
			PSTG_PID_ITEM pn = pp->Next;
			do {
				pp = pn;
				pn = pp->Next;
				delete pp;
			} while (pn);
		}
		validPidsEnd = &validPids;
	}
}

//ProcessesStorage
int Partition(PSYSTEM_PROCESSES a[], DWORD low, DWORD high)
{
	PSYSTEM_PROCESSES xo = a[high];
	DWORD x = PSYP_PID(xo);//��������������һ������Ϊ��Ԫ����������������л���
	DWORD i = low - 1;//i�����һ��С����Ԫ�������±�
	for (DWORD j = low; j < high; j++)//�����±���low��high-1����
	{
		if (PSYP_PID(a[j]) < x)//�����С����Ԫ�Ļ��ͽ�i��ǰŲ��һ��λ�ã����ҽ���j��i���ֱ�ָ�����
		{
			PSYSTEM_PROCESSES temp;
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	//���������ѭ��֮���±�Ϊ��low��i������i�������;�ΪС��x�����ˣ����ڽ���Ԫ��i+1λ������������н���
	a[high] = a[i + 1];
	a[i + 1] = xo;
	return i + 1;
}
void QuickSortForProcessesStorage(PSYSTEM_PROCESSES a[], DWORD low, DWORD high)
{
	if (low < high)
	{
		int q = Partition(a, low, high);
		QuickSortForProcessesStorage(a, low, q - 1);
		QuickSortForProcessesStorage(a, q + 1, high);
	}
}
PSYSTEM_PROCESSES BinarySearchProcessesStorage(PSYSTEM_PROCESSES array[], DWORD n, DWORD key)
{
	DWORD left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key < PSYP_PID(array[mid]))
			right = mid - 1;
		else if (key > PSYP_PID(array[mid]))
			left = mid + 1;
		else return array[mid];
	}
	return nullptr;
}
PSYSTEM_PROCESSES MProcessMonitorCore::FindProcess(DWORD pid)
{
	if (pid == 2) return &InterruptsProcessInformation;
	return BinarySearchProcessesStorage(processesStorage, processCount, pid);
}

//Valid Pid
void MProcessMonitorCore::AddValidPid(DWORD pid)
{
	validPidsEnd->Next = (PSTG_PID_ITEM)malloc(sizeof(STG_PID_ITEM));
	validPidsEnd = validPidsEnd->Next;
	validPidsEnd->Next = nullptr;
	validPidsEnd->Pid = pid;
}
void MProcessMonitorCore::RemoveValidPid(DWORD pid)
{
	PSTG_PID_ITEM pf;
	PSTG_PID_ITEM pp = &validPids;
	if (pp->Next)
	{
		do {
			pf = pp;
			pp = pp->Next;
			if (pp->Pid == pid)
			{
				pf->Next = pp->Next;
				delete pp;
				return;
			}
		} while (pp->Next);
	}
}

//Global refesh
bool MProcessMonitorCore::RefreshProcessBuffer()
{
	FreeProcessBuffer();

	DWORD dwSize = 0;
	NTSTATUS status = NtQuerySystemInformation(SystemProcessInformation, NULL, 0, &dwSize);
	if (status == STATUS_INFO_LENGTH_MISMATCH && dwSize > 0)
	{
		currentProcessBuffer = (PSYSTEM_PROCESSES)malloc(dwSize);
		status = NtQuerySystemInformation(SystemProcessInformation, currentProcessBuffer, dwSize, 0);
		if (!NT_SUCCESS(status))
			SetLastError(RtlNtStatusToDosError(status));
		else {
			current_system_process = currentProcessBuffer;
			return true;
		}
	}
	return false;
}
void MProcessMonitorCore::RefreshVaildPids()
{
	bool done = false;
	DWORD ret = 0;
	DWORD pid = 0;

	MSystemPerformanctMonitor::UpdatePerformance();

	processCount = MSystemPerformanctMonitor::GetProcessCount();

	processesStorage = (PSYSTEM_PROCESSES*)malloc((processCount) * sizeof(PSYSTEM_PROCESSES));
	memset(processesStorage, 0, (processCount) * sizeof(PSYSTEM_PROCESSES));
	
	validPids.Next = nullptr;
	validPids.Pid = 0;
	validPidsEnd = &validPids;

	processCount = 0;
	processesStorage[0] = &InterruptsProcessInformation;//Add Interrupts process
	
	AddValidPid(2);//Add Interrupts process fake pid 2

	for (PSYSTEM_PROCESSES p = currentProcessBuffer; !done; p = PSYSTEM_PROCESSES(PCHAR(p) + p->NextEntryOffset))
	{
		pid = static_cast<DWORD>((ULONG_PTR)p->ProcessId);

		processesStorage[processCount] = p;

		AddValidPid(pid);

		processCount++;
		done = p->NextEntryOffset == 0;
	}

	QuickSortForProcessesStorage(processesStorage, 0, processCount - 1);
}
void MProcessMonitorCore::RefreshAllProcessItem()
{
	ULONG64 sysTotalCycleTime = 0; // total cycle time for this update period
	ULONG64 sysIdleCycleTime = 0; // total idle cycle time for this update period

	MSystemPerformanctMonitor::UpdateCpuCycleInformation(&sysIdleCycleTime);

	if (allProcessItems.Next)//��ѭ������ˢ����Ŀ�Լ�cpu��Ϣ
	{
		PMPROCESS_ITEM item = &allProcessItems;
		PMPROCESS_ITEM pn = allProcessItems.Next;
		do {
			item = pn;
			pn = item->Next;

			bool erase_item;
			PSYSTEM_PROCESSES psp = FindProcess(item->ProcessId);

			if (psp == NULL) 	//�����Ч����
			{
				if (RemoveItemCallBack) RemoveItemCallBack(item->ProcessId);

				//Log(L"RemoveItem : %d", item->ProcessId);

				MProcessHANDLEStorageDestroyItem(item->ProcessId);

				if (item->PerfData)
					delete item->PerfData;

				erase_item = true; //ɾ����Ŀ
			}
			else //��Ч��Ŀˢ��
			{
				if (item->ProcessId == 2)
					continue;
				//ˢ��PSYSTEM_PROCESSESֵ
				if (item->Data != psp)
					item->Data = psp;
				
				if (psp->ProcessId == 0)
				{
					psp->CycleTime = MSystemPerformanctMonitor::CpuIdleCycleDelta.Value;
					psp->KernelTime = MSystemPerformanctMonitor::CpuTotals.IdleTime;
				}

				sysTotalCycleTime += item->Data->CycleTime - item->PerfData->CycleTimeDelta.Value; // existing process

				erase_item = false;
			}

			if (erase_item)
			{
				if (item == allProcessItemsEnd) {
					allProcessItemsEnd = item->Prvious;
					if (item->Prvious)
						item->Prvious->Next = NULL;
				}
				else {
					if (item->Prvious) item->Prvious->Next = item->Next;
					//˫������ɾ��
					if (item->Next) item->Next->Prvious = item->Prvious;
				}
				free(item);
			}
		} 
		while (pn);
	} 

	InterruptsProcessInformation.KernelTime.QuadPart = MSystemPerformanctMonitor::CpuTotals.DpcTime.QuadPart + MSystemPerformanctMonitor::CpuTotals.InterruptTime.QuadPart;
	InterruptsProcessInformation.CycleTime = MSystemPerformanctMonitor::CpuSystemCycleDelta.Value;

	sysTotalCycleTime += MSystemPerformanctMonitor::CpuSystemCycleDelta.Delta;

	MSystemPerformanctMonitor::UpdateCpuCycleUsageInformation(sysTotalCycleTime, sysIdleCycleTime);

	if (allProcessItems.Next)//��ѭ������ˢ��������Ϣ
	{
		PMPROCESS_ITEM item = &allProcessItems;
		PMPROCESS_ITEM pn = allProcessItems.Next;
		do {
			item = pn;
			pn = item->Next;

			PSYSTEM_PROCESSES psp = item->Data;
			MPerfAndProcessData *perfdata = item->PerfData;

			//ˢ��������Ŀ
			if (item->ProcessId != 2)//Not for 2
			{
				MUpdateDelta(&perfdata->CpuKernelDelta, psp->KernelTime.QuadPart);
				MUpdateDelta(&perfdata->CycleTimeDelta, psp->CycleTime);
				MUpdateDelta(&perfdata->CpuUserDelta, psp->UserTime.QuadPart);
				MUpdateDelta(&perfdata->IoReadDelta, psp->IoCounters.ReadTransferCount);
				MUpdateDelta(&perfdata->IoWriteDelta, psp->IoCounters.WriteTransferCount);
				MUpdateDelta(&perfdata->IoOtherDelta, psp->IoCounters.OtherTransferCount);
				MUpdateDelta(&perfdata->IoReadCountDelta, psp->IoCounters.ReadOperationCount);
				MUpdateDelta(&perfdata->IoWriteCountDelta, psp->IoCounters.WriteOperationCount);
				MUpdateDelta(&perfdata->IoOtherCountDelta, psp->IoCounters.OtherOperationCount);
				MUpdateDelta(&perfdata->PrivateWorkingSetDelta, psp->WorkingSetPrivateSize.QuadPart);
			
			}
			else 
			{
				MUpdateDelta(&perfdata->CpuKernelDelta, psp->KernelTime.QuadPart);
				MUpdateDelta(&perfdata->CycleTimeDelta, psp->CycleTime);
			}

			if (item->ProcessId == 2)
			{
				perfdata->CpuKernelUsage = ((FLOAT)perfdata->CpuKernelDelta.Delta / MSystemPerformanctMonitor::CpuTotalTime);
			}
			else
			{
				FLOAT totalDelta;
				FLOAT newCpuUsage = (FLOAT)perfdata->CycleTimeDelta.Delta / sysTotalCycleTime;// sysTotalCycleTime;

				totalDelta = (FLOAT)(perfdata->CpuKernelDelta.Delta + perfdata->CpuUserDelta.Delta);

				if (totalDelta != 0)
				{
					perfdata->CpuKernelUsage = newCpuUsage * ((FLOAT)perfdata->CpuKernelDelta.Delta / totalDelta);
					perfdata->CpuUserUsage = newCpuUsage * ((FLOAT)perfdata->CpuUserDelta.Delta / totalDelta);
				}
				else
				{
					if (psp->UserTime.QuadPart != 0)
					{
						perfdata->CpuKernelUsage = newCpuUsage / 2;
						perfdata->CpuUserUsage = newCpuUsage / 2;
					}
					else
					{
						perfdata->CpuKernelUsage = newCpuUsage;
						perfdata->CpuUserUsage = 0;
					}

				}
			}

			RemoveValidPid(item->ProcessId);

		} while (pn);
	}

	//���validPids��û��ɾ���꣬��ôʣ�µľ����³��ֵĽ���

	PSTG_PID_ITEM pp = &validPids;
	if (pp->Next)
	{
		do{
			pp = pp->Next;
			
			if (pp->Pid == 2) { //�����ٵ�ϵͳ�жϽ���

				PMPROCESS_ITEM newItem = (PMPROCESS_ITEM)malloc(sizeof(MPROCESS_ITEM));
				newItem->Data = &InterruptsProcessInformation;
				newItem->ProcessId = 2;
				newItem->PerfData = new MPerfAndProcessData();
				newItem->Prvious = allProcessItemsEnd;
				newItem->Next = nullptr;

				memset(newItem->PerfData, 0, sizeof(MPerfAndProcessData));

				newItem->PerfData->ProcessId = 2;

				allProcessItemsEnd->Next = newItem;
				allProcessItemsEnd = newItem;

				NewItemCallBack(2, 0, NULL, NULL, NULL, newItem);
			}
			else {				//����³��ֵĽ���

				PMPROCESS_ITEM newItem = (PMPROCESS_ITEM)malloc(sizeof(MPROCESS_ITEM));
				PSYSTEM_PROCESSES p = FindProcess(pp->Pid);

				newItem->Data = p;
				newItem->ProcessId = (DWORD)(ULONG_PTR)(p->ProcessId);
				newItem->PerfData = new MPerfAndProcessData();
				newItem->Prvious = allProcessItemsEnd;
				newItem->Next = nullptr;

				memset(newItem->PerfData, 0, sizeof(MPerfAndProcessData));

				newItem->PerfData->ProcessId = newItem->ProcessId;

				allProcessItemsEnd->Next = newItem;
				allProcessItemsEnd = newItem;

				WCHAR exeFullPath[260];
				memset(exeFullPath, 0, sizeof(exeFullPath));

				HANDLE hProcess = NULL;
				MGetProcessFullPathEx(static_cast<DWORD>((ULONG_PTR)p->ProcessId), exeFullPath, &hProcess, p->ImageName.Buffer);

				NewItemCallBack(static_cast<DWORD>((ULONG_PTR)p->ProcessId), static_cast<DWORD>((ULONG_PTR)p->InheritedFromProcessId), p->ImageName.Buffer, exeFullPath, hProcess, newItem);

				//Log(L"NewItem : %d", newItem->ProcessId);

				sysTotalCycleTime += p->CycleTime;
			}

		} while (pp->Next);
	}

}


