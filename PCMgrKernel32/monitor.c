#include "monitor.h"
#include "protect.h"

extern ULONG_PTR CurrentPCMgrProcess;

extern PsLookupProcessByProcessId_ _PsLookupProcessByProcessId;
extern PsLookupThreadByThreadId_ _PsLookupThreadByThreadId;

BOOLEAN kxCanCreateProcess = TRUE;
BOOLEAN kxCanCreateThread = TRUE;
BOOLEAN kxCanLoadDriver = TRUE;

VOID KxPsMonitorSetReset() {
	kxCanCreateProcess = TRUE;
	kxCanCreateThread = TRUE;
	kxCanLoadDriver = TRUE;
}
NTSTATUS KxPsMonitorInit() {
	NTSTATUS status = PsSetCreateProcessNotifyRoutineEx((PCREATE_PROCESS_NOTIFY_ROUTINE_EX)KxCreateProcessNotifyEx, FALSE);
	status = PsSetCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)KxCreateProcessNotifyEx);
	status = PsSetLoadImageNotifyRoutine((PLOAD_IMAGE_NOTIFY_ROUTINE)KxLmageNotifyRoutine);
	return status;
}
VOID KxPsMonitorUnInit() {
	PsSetCreateProcessNotifyRoutineEx((PCREATE_PROCESS_NOTIFY_ROUTINE_EX)KxCreateProcessNotifyEx, TRUE);
	PsRemoveCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)KxCreateProcessNotifyEx);
	PsRemoveLoadImageNotifyRoutine((PLOAD_IMAGE_NOTIFY_ROUTINE)KxLmageNotifyRoutine);
}

VOID KxLmageNotifyRoutine(PUNICODE_STRING FullImageName, HANDLE  ProcessId, PIMAGE_INFO  ImageInfo)
{
	//KdPrint(("�������� %ws pid : %ld", FullImageName->Buffer, ProcessId));
	return;
}

VOID KxCreateProcessNotifyEx(__inout PEPROCESS Process,__in HANDLE ProcessId,__in_opt PPS_CREATE_NOTIFY_INFO CreateInfo)
{
	if (CreateInfo != NULL)	//���̴����¼�
	{
		//KdPrint(("���̴��� %ld", ProcessId));
		if(!kxCanCreateProcess) CreateInfo->CreationStatus = STATUS_UNSUCCESSFUL;
	}
	else
	{
		//KdPrint(("�����˳� %ld", ProcessId));
		if (KxIsProcessProtect(ProcessId))
			KxUnProtectProcessWithPid(ProcessId);
		if ((ULONG_PTR)ProcessId == CurrentPCMgrProcess)
			KxPsMonitorSetReset();
	}
}

VOID KxCreateThreadNotify(IN HANDLE ProcessId, IN HANDLE ThreadId, IN BOOLEAN Create)
{
	if (Create)
	{
		if (!kxCanCreateThread)
			KxRefuseCreateThread(ProcessId, ThreadId);
	}
}

NTSTATUS KxRefuseCreateThread(IN HANDLE ProcessId, IN HANDLE ThreadId)
{
	NTSTATUS status = STATUS_SUCCESS;
	PEPROCESS eprocess;
	status = _PsLookupProcessByProcessId(ProcessId, &eprocess);
	if (NT_SUCCESS(status))
	{

	}
	return status;
}
