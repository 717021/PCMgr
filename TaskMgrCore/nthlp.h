#pragma once
#include "stdafx.h"
#include "ntdef.h"

//��ȡ������Ϣ
M_CAPI(NTSTATUS) MQueryProcessVariableSize(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID * Buffer);
//NTSTATUS תΪ�ַ���
M_CAPI(LPWSTR) MNtstatusToStr(NTSTATUS status);
