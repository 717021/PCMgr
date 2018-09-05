#pragma once
#include "stdafx.h"

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
#ifdef MIDL_PASS
	[size_is(MaximumLength / 2), length_is((Length) / 2)] USHORT * Buffer;
#else // MIDL_PASS
	_Field_size_bytes_part_(MaximumLength, Length) PWCH   Buffer;
#endif // MIDL_PASS
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _PEB_LDR_DATA {
	BYTE       Reserved1[8];
	PVOID      Reserved2[3];
	LIST_ENTRY InMemoryOrderModuleList;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _LDR_MODULE {
	LIST_ENTRY              InLoadOrderModuleList;//��������˳�򹹳ɵ�ģ������
	LIST_ENTRY              InMemoryOrderModuleList;//�����ڴ�˳�򹹳ɵ�ģ������
	LIST_ENTRY            InInitializationOrderModuleList;//������ʼ��˳�򹹳ɵ�ģ������
	PVOID                   BaseAddress;//��ģ��Ļ���ַ
	PVOID                   EntryPoint;//��ģ������
	ULONG                   SizeOfImage;//��ģ���Ӱ���С
	UNICODE_STRING          FullDllName;//����·����ģ����
	UNICODE_STRING          BaseDllName;//������·����ģ����
	ULONG                   Flags;
	SHORT                   LoadCount;//��ģ������ü���
	SHORT                   TlsIndex;
	HANDLE                  SectionHandle;
	ULONG                   CheckSum;
	ULONG                   TimeDateStamp;
} LDR_MODULE, *PLDR_MODULE;

typedef struct _PEB {
	BYTE                          Reserved1[2];
	BYTE                          BeingDebugged;
	BYTE                          Reserved2[1];
	PVOID                         Reserved3[2];
	PPEB_LDR_DATA                 Ldr;
} PEB, *PPEB;

PVOID MGetK32ModuleHandle();
PVOID MGetProcAddress(HMODULE hModule, LPCSTR lpProcName);
PVOID MGetK32ModuleGetProcAddress(HMODULE hK32);
VOID MGetModuleHandles();