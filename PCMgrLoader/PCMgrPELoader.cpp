#include "stdafx.h"
#include "PCMgrPELoader.h"
#include "DyFuns.h"
#include "mcrt.h"

extern PVOID MGetK32ModuleHandleCore();
extern PVOID MGetPEBLdr();

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

PVOID MGetProcAddress(HMODULE hModule, 	LPCSTR lpProcName)
{
	int i = 0;
	char *pRet = NULL;
	PIMAGE_DOS_HEADER pImageDosHeader = NULL;
	PIMAGE_NT_HEADERS pImageNtHeader = NULL;
	PIMAGE_EXPORT_DIRECTORY pImageExportDirectory = NULL;

	pImageDosHeader = (PIMAGE_DOS_HEADER)hModule;
	pImageNtHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + pImageDosHeader->e_lfanew);
	pImageExportDirectory = (PIMAGE_EXPORT_DIRECTORY)((DWORD)hModule + pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	DWORD dwExportRVA = pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	DWORD dwExportSize = pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	DWORD *pAddressOfFunction = (DWORD*)(pImageExportDirectory->AddressOfFunctions + (DWORD)hModule);
	DWORD *pAddressOfNames = (DWORD*)(pImageExportDirectory->AddressOfNames + (DWORD)hModule);
	DWORD dwNumberOfNames = (DWORD)(pImageExportDirectory->NumberOfNames);
	DWORD dwBase = (DWORD)(pImageExportDirectory->Base);

	WORD *pAddressOfNameOrdinals = (WORD*)(pImageExportDirectory->AddressOfNameOrdinals + (DWORD)hModule);

	//����ǲ�һ���ǰ���ʲô��ʽ����������or������ţ����麯����ַ��
	DWORD dwName = (DWORD)lpProcName;
	if ((dwName & 0xFFFF0000) == 0)
		goto xuhao;

	for (i = 0; i<(int)dwNumberOfNames; i++)
	{
		char *strFunction = (char *)(pAddressOfNames[i] + (DWORD)hModule);
		if (m_strcmp(strFunction, (char *)lpProcName) == 0)
		{
			pRet = (char *)(pAddressOfFunction[pAddressOfNameOrdinals[i]] + (DWORD)hModule);
			goto _exit11;
		}
	}
	//�����ͨ������ŵķ�ʽ���麯����ַ��
xuhao:
	if (dwName < dwBase || dwName > dwBase + pImageExportDirectory->NumberOfFunctions - 1)
		return 0;
	pRet = (char *)(pAddressOfFunction[dwName - dwBase] + (DWORD)hModule);
_exit11:
	//�жϵõ��ĵ�ַ��û��Խ��
	if ((DWORD)pRet<dwExportRVA + (DWORD)hModule || (DWORD)pRet > dwExportRVA + (DWORD)hModule + dwExportSize)
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
	m_strcat(pTempDll, ".dll");

	HMODULE h = _LoadLibraryA(pTempDll);
	if (h == NULL)
		return (PVOID)pRet;
	return MGetProcAddress(h, pTempFuction);
}
PVOID MGetK32ModuleHandle()
{
	PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)MGetPEBLdr();

	PLIST_ENTRY list_head = &pLdr->InMemoryOrderModuleList;
	PLIST_ENTRY p = &pLdr->InMemoryOrderModuleList;

	WCHAR thisName[MAX_PATH];

	for (p = list_head->Flink; p != list_head; p = p->Flink) {
		PLDR_MODULE thisModule = CONTAINING_RECORD(p, LDR_MODULE, InMemoryOrderModuleList);
		if (thisModule->BaseDllName.Buffer != NULL) {
			m_wcscpy(thisName, thisModule->BaseDllName.Buffer);
			m_wcslwr(thisName);
			if (m_wcscmp(thisName, L"kernel32.dll") == 0)
				return thisModule->BaseAddress;
		}
	}
	//return GetModuleHandle(L"KERNEL32.DLL");
	return MGetK32ModuleHandleCore();
}
PVOID MGetK32ModuleGetProcAddress(HMODULE hK32)
{
	return MGetProcAddress(hK32, "GetProcAddress");
}