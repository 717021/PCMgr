#include "stdafx.h"
#include "PCMgrPELoader.h"
#include "PCMgrDyFuns.h"
#include "mcrt.h"



UINT dotdll[] = { '.','d','l','l','\0', };
UINT gpa[] = { 'G','e','t','P','r','o','c','A','d','d','r','e','s','s','\0','\0', };
USHORT k32name[] = { L'k',L'e',L'r',L'n',L'e',L'l',L'3',L'2',L'.',L'd',L'l',L'l',L'\0', };
USHORT ntdllname[] = { L'n',L't',L'd',L'l',L'l',L'.',L'd',L'l',L'l',L'\0', };



extern PPEB MGetCurrentPeb();

extern HMODULE hKernel32;
extern HMODULE hNtdll;

PVOID MGetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
	char strdotdll[5];
	m_copyto_strarray(strdotdll, dotdll, 5);

	UINT i = 0;
	char *pRet = NULL;

	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((ULONG_PTR)hModule + pDosHeader->e_lfanew);
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = (PIMAGE_OPTIONAL_HEADER)((PBYTE)hModule + pDosHeader->e_lfanew + offsetof(IMAGE_NT_HEADERS, OptionalHeader));
	PIMAGE_EXPORT_DIRECTORY pExportDirectory = (PIMAGE_EXPORT_DIRECTORY)((PBYTE)hModule + pOptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
	LPCSTR lpstrLibraryName = (LPCSTR)hModule + pExportDirectory->Name;
	PDWORD aryAddressOfFunctions = (PDWORD)((PBYTE)hModule + pExportDirectory->AddressOfFunctions);
	PDWORD aryAddressOfNames = (PDWORD)((PBYTE)hModule + pExportDirectory->AddressOfNames);
	LPWORD aryAddressOfNameOrdinals = (LPWORD)((PBYTE)hModule + pExportDirectory->AddressOfNameOrdinals);
	DWORD dwNumberOfNames = pExportDirectory->NumberOfNames;
	DWORD dwBase = pExportDirectory->Base;

	DWORD dwExportRVA = pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	DWORD dwExportSize = pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	//����ǲ�һ���ǰ���ʲô��ʽ����������or������ţ����麯����ַ��
	ULONG_PTR dwName = (ULONG_PTR)lpProcName;
	if ((dwName & 0xFFFF0000) == 0)
		goto xuhao;

	for (i = 0; i < dwNumberOfNames; i++)
	{
		char *strFunction = (char *)(aryAddressOfNames[i] + (ULONG_PTR)hModule);
		if (m_strcmp(strFunction, (char *)lpProcName) == 0)
		{
			pRet = (char *)(aryAddressOfFunctions[aryAddressOfNameOrdinals[i]] + (ULONG_PTR)hModule);
			goto _exit11;
		}
	}
	//�����ͨ������ŵķ�ʽ���麯����ַ��
xuhao:
	if (dwName < dwBase || dwName > dwBase + pExportDirectory->NumberOfFunctions - 1)
		return 0;
	pRet = (char *)(aryAddressOfFunctions[dwName - dwBase] + (ULONG_PTR)hModule);
_exit11:
	//�жϵõ��ĵ�ַ��û��Խ��
	if ((ULONG_PTR)pRet<dwExportRVA + (ULONG_PTR)hModule || (ULONG_PTR)pRet > dwExportRVA + (ULONG_PTR)hModule + dwExportSize)
		return (PVOID)pRet;

	char pTempDll[MAX_PATH];
	m_memset(pTempDll, 0, sizeof(pTempDll));
	char pTempFuction[64];
	m_memset(pTempFuction, 0, sizeof(pTempFuction));

	m_strcpy(pTempDll, pRet);
	char *p = m_strchr(pTempDll, '.');
	if (!p)
		return (PVOID)pRet;
	*p = 0;
	m_strcpy(pTempFuction, p + 1);
	m_strcat(pTempDll, strdotdll);

	HMODULE h = _LoadLibraryA(pTempDll);
	if (h == NULL)
		return (PVOID)pRet;
	return MGetProcAddress(h, pTempFuction);
}
PVOID MGetK32ModuleHandle()
{
	PPEB pPeb = MGetCurrentPeb();
	PPEB_LDR_DATA pLdr = pPeb->Ldr;

	PLIST_ENTRY list_head = &pLdr->InMemoryOrderModuleList;
	PLIST_ENTRY p = &pLdr->InMemoryOrderModuleList;

	WCHAR thisName[MAX_PATH];
	WCHAR k32NameName[13];
	m_copyto_wcsarray(k32NameName, k32name, 13);

	for (p = list_head->Flink; p != list_head; p = p->Flink) {
		PLDR_MODULE thisModule = CONTAINING_RECORD(p, LDR_MODULE, InMemoryOrderModuleList);
		if (thisModule->BaseDllName.Buffer != NULL) {
			m_wcscpy(thisName, thisModule->BaseDllName.Buffer);
			m_wcslwr(thisName);
			if (m_wcscmp(thisName, k32NameName) == 0)
				return thisModule->BaseAddress;
		}
	}
	//return GetModuleHandle(L"KERNEL32.DLL");
	return 0;
}
PVOID MGetK32ModuleGetProcAddress(HMODULE hK32)
{
	char strgpa[15];
	m_copyto_strarray(strgpa, gpa, 15);
	return MGetProcAddress(hK32, strgpa);
}
VOID MGetModuleHandles()
{
	PPEB pPeb = MGetCurrentPeb();
	PPEB_LDR_DATA pLdr = pPeb->Ldr;

	PLIST_ENTRY list_head = &pLdr->InMemoryOrderModuleList;
	PLIST_ENTRY p = &pLdr->InMemoryOrderModuleList;

	WCHAR thisName[MAX_PATH];

	WCHAR k32NameName[13];
	m_copyto_wcsarray(k32NameName, k32name, 13);
	WCHAR ntdllNameName[10];
	m_copyto_wcsarray(ntdllNameName, ntdllname, 10);

	for (p = list_head->Flink; p != list_head; p = p->Flink) {
		PLDR_MODULE thisModule = CONTAINING_RECORD(p, LDR_MODULE, InMemoryOrderModuleList);
		if (thisModule->BaseDllName.Buffer != NULL) {
			m_wcscpy(thisName, thisModule->BaseDllName.Buffer);
			m_wcslwr(thisName);
			if (m_wcscmp(thisName, k32NameName) == 0)
				hKernel32 = thisModule->BaseAddress;
			else if (m_wcscmp(thisName, ntdllNameName) == 0)
				hNtdll = thisModule->BaseAddress;
		}
	}
}
