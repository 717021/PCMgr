#include "unexp.h"

extern PsResumeProcess_ _PsResumeProcess;

PspTerminateThreadByPointer_ PspTerminateThreadByPointer = 0;
PspExitThread_ PspExitThread = 0;
PsGetNextProcessThread_ PsGetNextProcessThread = 0;
PsTerminateProcess_ PsTerminateProcess = 0;
PsGetNextProcess_ PsGetNextProcess = 0;
KeForceResumeThread_ KeForceResumeThread = 0;

//������ַ
ULONG_PTR KxSearchFeatureCodeForAddress(ULONG_PTR StartAddress, PUCHAR FeatureCode, int FeatureCodeSize, int Search_MaxLength)
{
	PUCHAR Start_scan = (PUCHAR)StartAddress;
	BOOLEAN IsTrue = FALSE;
	ULONG_PTR Real_address = 0;
	int i, fi;

	for (i = 0; i < Search_MaxLength; i++)
	{
		if (Start_scan[i] == FeatureCode[0])
		{
			for (fi = 0; fi < FeatureCodeSize; fi++)
			{
				if (Start_scan[i + fi] != FeatureCode[fi])
				{
					//�κ�һ���ֽڲ�ͬ,�����ʧ��,����
					IsTrue = FALSE;
					break;
				}
				else
				{
					if (fi == FeatureCodeSize - 1)
					{
						IsTrue = TRUE;
						//ָ�����ȵ��ֽڶ���ͬ.��Ϊ�ҵ���
					}
				}
			}

			if (IsTrue == TRUE)
			{
				Real_address = (ULONG_PTR)&Start_scan[i];
				break;
			}
		}
	}
	return Real_address;
}
//��ȡ PspTerminateThreadByPointer 32/64 ����Win
//0 : 32 0x50 64 0xA0
//0x50,0xe8 (push eax call XXXX) / 0xA0,0xe8 (mov r8b call XXXX)
ULONG_PTR KxGetPspTerminateThreadByPointerAddressX_7Or8Or10(UCHAR FeatureCode0)
{
	//ժ���Ĵ���
	UNICODE_STRING  FunName;
	UCHAR FeatureCode[2] = { 0x00,0xe8 };//������
	FeatureCode[0] = FeatureCode0;
	ULONG_PTR   FeatureAddress = 0; //�ҵ�����������׵�ַ
	ULONG_PTR   FunAddress = 0;
	ULONG_PTR   RetAddress = 0;//���շ���
	ULONG_PTR   FunAdd = 0;

	RtlInitUnicodeString(&FunName, L"PsTerminateSystemThread");
	FunAdd = (ULONG_PTR)MmGetSystemRoutineAddress(&FunName);

	//���Ȼ�ȡPsTerminateSystemThread���������ַ.��ʵ�������ֱ�ӵ��õ�PspTerminateThreadByPointer
	//�����������ǳ���С,����ͨ����������.��λcall Ȼ��call�ĵ�ַ�ó������������㼴��
	FeatureAddress = KxSearchFeatureCodeForAddress(FunAdd, FeatureCode, 2, 0x27);
	//PsTerminateSystemThread������Ҫ�����ĳ���0x27
	if (FeatureAddress != 0) {
		RtlCopyMemory(&FunAddress, (ULONG_PTR*)(FeatureAddress + 2), 4);

		//Ŀ���ַ=����ָ��ĵ�ַ+������E8����������32λ��
		//ע�⣬������E8����������32λ�� �� little-endian ��ʽ�ģ���8λ��ǰ����8λ�ں�
		RetAddress = FunAddress + (FeatureAddress + 2 + 4);
	}
	return RetAddress;
}

//��ȡ PspExitThread 32/64 ����Win
ULONG_PTR KxGetPspExitThread_32_64() {
	ULONG_PTR i = 0;
	ULONG_PTR callcode = 0;
	ULONG_PTR  curcodeptr = 0;
	ULONG_PTR RetAddress = 0;
	ULONG_PTR AddressPTTBP = (ULONG_PTR)PspTerminateThreadByPointer;//PspTerminateThreadByPointer��ַ
	PUCHAR Scan = (PUCHAR)AddressPTTBP;

	if (AddressPTTBP != 0) 
	{
		//�������0x60��
		for (i = 1; i < 0x60; i++)
		{
			curcodeptr = (ULONG_PTR)&Scan[i];
			if (MmIsAddressValid((PVOID)curcodeptr))
			{
				if (Scan[i] == 0xe8/*call immed16 ��λλ�� (һ�� 5 �ֽ�) */
					&& Scan[i + 5] == 0xcc/*int 3*/)//��������࣬ÿ��ϵͳcall PspExitThread���涼��int 3��
					//��ǰ���ָ�һ����������ʹ�ô˷������
				{
					//Ŀ���ַ=������+5+ԭʼ��ַ
					RtlMoveMemory(&callcode, (PVOID)(curcodeptr + 1), 4);//��ת��ַ
					RetAddress = (ULONG_PTR)((curcodeptr/*������*/ + 5 + callcode) & 0x0000ffffffff);
					break;
				}
			}
		}
	}
	else KdPrint(("AddressPTTBP == 0!"));
	return RetAddress;
}

//���� PsGetNextProcessThread X
ULONG_PTR KxGetPsGetNextProcessThread_32Or64_X(ULONG TWO_CALL_OFF)
{
	ULONG_PTR RetAddress = 0;
	ULONG_PTR PsResumeProcessAddress = (ULONG_PTR)_PsResumeProcess;//��PsResumeProcess����

	ULONG_PTR i = 0;
	ULONG_PTR callcode = 0;
	ULONG_PTR  curcodeptr = 0;

	PUCHAR Scan = (PUCHAR)PsResumeProcessAddress;

	//����0x50
	for (i = 1; i < 0x50; i++)
	{
		if (MmIsAddressValid((PVOID)(PsResumeProcessAddress + i)) && MmIsAddressValid((PVOID)(ULONG_PTR)(PsResumeProcessAddress + i + TWO_CALL_OFF)))
		{
			curcodeptr = (ULONG_PTR)&Scan[i];
			if (Scan[i] == 0xe8/*call immed16*/
				&& Scan[i + TWO_CALL_OFF] == 0xe8/*call immed16*/)
			{
				curcodeptr = (ULONG_PTR)&Scan[i + TWO_CALL_OFF];
				//Ŀ���ַ=������+5+ԭʼ��ַ
				RtlMoveMemory(&callcode, (PVOID)(curcodeptr + 1), 4);//��ת��ַ
				RetAddress = (ULONG_PTR)((curcodeptr/*������*/ + 5 + callcode) & 0x0000ffffffff);
				break;
			}
		}
	}

	return RetAddress;
}

//��ȡһЩδ��������
NTSTATUS KxGetFunctions(PWINVERS parm)
{
	NTSTATUS status = STATUS_SUCCESS;

#ifdef _AMD64_
	PspTerminateThreadByPointer = (PspTerminateThreadByPointer_)KxGetPspTerminateThreadByPointerAddressX_7Or8Or10(0xA0);
#else
	PspTerminateThreadByPointer = (PspTerminateThreadByPointer_)KxGetPspTerminateThreadByPointerAddressX_7Or8Or10(0x50);
#endif

	PspExitThread = (PspExitThread_)KxGetPspExitThread_32_64();

	if (parm->VerSimple == 7)//Win7
	{
#ifdef _AMD64_//����CALL �ļ��
		PsGetNextProcessThread = (PsGetNextProcessThread_)KxGetPsGetNextProcessThread_32Or64_X(0xB);
#else
		PsGetNextProcessThread = (PsGetNextProcessThread_)KxGetPsGetNextProcessThread_32Or64_X(0x9);
#endif
		
	}
	else if (parm->VerSimple == 10)//Win10
	{
#ifdef _AMD64_//����CALL �ļ��
		PsGetNextProcessThread = (PsGetNextProcessThread_)KxGetPsGetNextProcessThread_32Or64_X(0xE);
#else
		PsGetNextProcessThread = (PsGetNextProcessThread_)KxGetPsGetNextProcessThread_32Or64_X(0x9);
#endif
	}
	else if (parm->VerSimple == 8)//Win8
	{

	}
	else if (parm->VerSimple == 81)//Win8.1
	{

	}

	KxPrintInternalFuns();

	return status;
}
//��pdb��ȡһЩδ��������
VOID KxGetFunctionsFormPDBData(PNTOS_PDB_DATA data) {
	PspExitThread = (PspExitThread_)data->PspExitThread_;
	PspTerminateThreadByPointer = (PspTerminateThreadByPointer_)data->PspTerminateThreadByPointer_;
	PsGetNextProcessThread = (PsGetNextProcessThread_)data->PsGetNextProcessThread_;
	PsGetNextProcess = (PsGetNextProcess_)data->PsGetNextProcess_;
	PsTerminateProcess = (PsTerminateProcess_)data->PsTerminateProcess_;
	KeForceResumeThread = (KeForceResumeThread_)data->KeForceResumeThread_;

	KxPrintInternalFuns();
}

ULONG_PTR EPROCESS_ThreadListHead_Offest;
ULONG_PTR EPROCESS_RundownProtect_Offest;
ULONG_PTR EPROCESS_Flags_Offest;
ULONG_PTR ETHREAD_Tcb_Offest;
ULONG_PTR ETHREAD_CrossThreadFlags_Offest;

VOID KxGetStructOffestsFormPDBData(PNTOS_EPROCESS_OFF_DATA data) {

	EPROCESS_ThreadListHead_Offest = data->EPROCESS_ThreadListHeadOffest;
	EPROCESS_RundownProtect_Offest = data->EPROCESS_RundownProtectOffest;
	EPROCESS_Flags_Offest = data->EPROCESS_FlagsOffest;
	ETHREAD_Tcb_Offest = data->ETHREAD_TcbOffest;
	ETHREAD_CrossThreadFlags_Offest = data->ETHREAD_CrossThreadFlagsOffest;
	KxPrintInternalOffests();
}

VOID KxPrintInternalFuns() 
{
#ifdef _AMD64_
	KdPrint(("PspTerminateThreadByPointer : 0x%I64x", PspTerminateThreadByPointer));
	KdPrint(("PspExitThread : 0x%I64x", PspExitThread));
	KdPrint(("PsGetNextProcessThread : 0x%I64x", PsGetNextProcessThread));
	KdPrint(("PsTerminateProcess : 0x%I64x", PsTerminateProcess));
	KdPrint(("PsGetNextProcess : 0x%I64x", PsGetNextProcess));
	KdPrint(("KeForceResumeThread : 0x%I64x", KeForceResumeThread));
#else
	KdPrint(("PspTerminateThreadByPointer : 0x%08x", PspTerminateThreadByPointer));
	KdPrint(("PspExitThread : 0x%08x", PspExitThread));
	KdPrint(("PsGetNextProcessThread : 0x%08x", PsGetNextProcessThread));
	KdPrint(("PsTerminateProcess : 0x%08x", PsTerminateProcess));
	KdPrint(("PsGetNextProcess : 0x%08x", PsGetNextProcess));
	KdPrint(("KeForceResumeThread : 0x%08x", KeForceResumeThread));
#endif
}
VOID KxPrintInternalOffests()
{
#ifdef _AMD64_
	KdPrint(("_EPROCESS->ThreadListHead : +0x%I64x", EPROCESS_ThreadListHead_Offest));
	KdPrint(("_EPROCESS->RundownProtect : +0x%I64x", EPROCESS_RundownProtect_Offest));
	KdPrint(("_EPROCESS->Flags : +0x%I64x", EPROCESS_Flags_Offest));
	KdPrint(("_ETHREAD->Tcb : +0x%I64x", ETHREAD_Tcb_Offest));
	KdPrint(("_ETHREAD->CrossThreadFlags : +0x%I64x", ETHREAD_CrossThreadFlags_Offest));
#else
	KdPrint(("_EPROCESS->ThreadListHead : +0x%08x", EPROCESS_ThreadListHead_Offest));
	KdPrint(("_EPROCESS->RundownProtect : +0x%08x", EPROCESS_RundownProtect_Offest));
	KdPrint(("_EPROCESS->Flags : +0x%08x", EPROCESS_Flags_Offest));
	KdPrint(("_ETHREAD->Tcb : +0x%08x", ETHREAD_Tcb_Offest));
	KdPrint(("_ETHREAD->CrossThreadFlags : +0x%08x", ETHREAD_CrossThreadFlags_Offest));
#endif
}



//���ݴ���汾ѡ��һЩ�ṹ��ƫ��
NTSTATUS KxLoadStructOffests(PWINVERS parm)
{
	NTSTATUS status = STATUS_SUCCESS;
	if (parm->VerSimple == 10) {//win10
#ifdef _AMD64_
		EPROCESS_ThreadListHead_Offest = 0x030;//kprocess 10-17134
		EPROCESS_RundownProtect_Offest = 0x2f8;
#else
		//EPROCESS_RundownProtect_Offest = 0x000;
#endif
	}
	else if (parm->VerSimple == 81)//Win8.1
	{

	}
	else if (parm->VerSimple == 8)//Win8
	{

	}
	else if (parm->VerSimple == 7)//Win7
	{

#ifdef _AMD64_
		//EPROCESS_RundownProtect_Offest = 0x000;
#else
		EPROCESS_RundownProtect_Offest = 0x0b0;
#endif
		
	}
	KxPrintInternalOffests();
	return status;
}