#pragma once
#include "stdafx.h"
#include "ntdef.h"

//��ȡ������Ϣ
NTSTATUS MQueryProcessVariableSize(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID * Buffer);
//NTSTATUS תΪ�ַ���
M_CAPI(LPWSTR) MNtStatusToStr(NTSTATUS status);
