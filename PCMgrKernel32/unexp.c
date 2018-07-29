#include "unexp.h"

PspTerminateThreadByPointer_ PspTerminateThreadByPointer;
PspExitThread_ PspExitThread;

ULONG KxGetWin10Ver() {
	return 0;
}
NTSTATUS KxGetFunctions(ULONG parm)
{
	NTSTATUS status = STATUS_SUCCESS;

	if (parm == 7 || parm == 8) {
		PspTerminateThreadByPointer = (PspTerminateThreadByPointer_)KxGetPspTerminateThreadByPointerAddress78();
		PspExitThread = (PspExitThread_)KxGetPspExitThreadAddress78();

		KdPrint(("PspTerminateThreadByPointer : 0x%08x", PspTerminateThreadByPointer));
		KdPrint(("PspExitThread : 0x%08x", PspExitThread));
	}
	else {
		ULONG w10ver = KxGetWin10Ver();
		KdPrint(("Win10 Ver : %d", w10ver));


	}

	return status;
}

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
ULONG_PTR KxGetPspTerminateThreadByPointerAddress78()
{
	UNICODE_STRING  FunName;
	UCHAR FeatureCode[2] = { 0x50,0xe8 };//������push    eax call XXXX
	ULONG_PTR   FeatureAddress = 0; //�ҵ�����������׵�ַ
	ULONG_PTR   FunAddress = 0;
	ULONG_PTR   RetAddress = 0;//���շ���
	ULONG_PTR   FunAdd = 0;

	RtlInitUnicodeString(&FunName, L"PsTerminateSystemThread");
	FunAdd = (ULONG_PTR)MmGetSystemRoutineAddress(&FunName);

	KdPrint(("PsTerminateSystemThread : %08X", FunAdd));
	//���Ȼ�ȡPsTerminateSystemThread���������ַ.��ʵ�������ֱ�ӵ��õ�PspTerminateThreadByPointer
	//�����������ǳ���С,����ͨ����������.��λcall Ȼ��call�ĵ�ַ�ó������������㼴��

	FeatureAddress = KxSearchFeatureCodeForAddress(FunAdd, FeatureCode, 2, 0x27);
	//PsTerminateSystemThread������Ҫ�����ĳ���0x27

	KdPrint(("FeatureAddress : %08X", FeatureAddress));

	RtlCopyMemory(&FunAddress, (ULONG_PTR*)(FeatureAddress + 2), 4);

	//Ŀ���ַ=����ָ��ĵ�ַ+������E8����������32λ��
	//ע�⣬������E8����������32λ�� �� little-endian ��ʽ�ģ���8λ��ǰ����8λ�ں�
	RetAddress = FunAddress + (FeatureAddress + 2 + 4);

	return RetAddress;
}
ULONG_PTR KxGetPspExitThreadAddress78()
{
	ULONG_PTR Address = 0; //�ҵ�����������׵�ַ
	ULONG_PTR PTTBPAddress = (ULONG_PTR)PspTerminateThreadByPointer;
	ULONG_PTR RetAddress = 0;//���շ���
	if (PTTBPAddress != 0) {
		for (int i = 1; i < 0xff; i++)
		{
			if (MmIsAddressValid((PVOID)(PTTBPAddress + i)) != FALSE)
			{
				//Ŀ���ַ-ԭʼ��ַ-5=������
				//Ŀ���ַ=������+5+ԭʼ��ַ
				if (*(BYTE *)(PTTBPAddress + i + 1) == 0xCC)//int 3
				{
					RtlMoveMemory(&Address, (PVOID)(PTTBPAddress + i), 4);
					RetAddress = (ULONG_PTR)Address + 5 + PTTBPAddress + i;
				}
			}
		}
	}
	return RetAddress;
}

ULONG_PTR KxGetPspTerminateThreadByPointerAddress10(ULONG ver)
{
	return 0;
}
ULONG_PTR KxGetPspExitThreadAddress10(ULONG ver)
{
	return 0;
}