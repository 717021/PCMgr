#include <Windows.h>

typedef BOOL(*MIsSystemSupportFun)();
typedef BOOL(*MLoadMainAppFun)();

typedef void *(*mallocFun)(unsigned int num_bytes);
typedef void (*freeFun)(void *ptr);

typedef struct
{
	int tk;
	DWORD pid;
	PVOID token;
}PCMGRTOKEN,*PPCMGRTOKEN;

MIsSystemSupportFun MIsSystemSupport;
MLoadMainAppFun MLoadMainApp;
freeFun _free;
mallocFun _malloc;

WCHAR*token = 0;

bool LoadDll();

void print(LPWSTR str)
{
	MessageBox(0, str, L"", MB_OK);
}

int main()
{
	if (!LoadDll()) {
		MessageBox(0, L"�޷�����������", L"PC Manager - ϵͳ����", MB_ICONERROR | MB_OK);
		goto EXIT;
	}
	if (MIsSystemSupport()) {
		MLoadMainApp();
	}
	else MessageBox(0, L"�޷����г�����Ϊ����ϵͳ�汾���͡�\nҪ���б�����������ҪWindows7��", L"PC Manager - ϵͳ����", MB_ICONERROR | MB_OK);

EXIT:
	_free(token);
	ExitProcess(0);
	return 0;
}

void* GetEntry()
{
	if (token == 0)
	{
		token = (WCHAR*)_malloc(7 * sizeof(WCHAR));
		token[0] = L'2';
		token[1] = L'3';
		token[2] = L'R';
		token[3] = L'G';
		token[4] = L'M';
		token[5] = L'C';
		token[6] = L'P';
		token[7] = L'\0';
	}
	return token;
}

bool LoadDll()
{
	HMODULE hDllMt = LoadLibrary(L"msvcrt.dll");
	if (hDllMt) {
		_free = (freeFun)GetProcAddress(hDllMt, "free");
		_malloc = (mallocFun)GetProcAddress(hDllMt, "malloc");
		HMODULE hDll = LoadLibrary(L"PCMgr32.dll");
		if (hDll) {
			MIsSystemSupport = (MIsSystemSupportFun)GetProcAddress(hDll, "MIsSystemSupport");
			MLoadMainApp = (MLoadMainAppFun)GetProcAddress(hDll, "MLoadMainApp");
			return true;
		}
	}
	return false;
}

int GetToken()
{
    return 342342 + 53672 * 56;
	/*_asm
	{
		push    ebp
		mov     ebp, esp
		sub     esp, 40h
		push    ebx
		push    esi
		push    edi
		mov     eax, 331606h
		pop     edi
		pop     esi
		pop     ebx
		mov     esp, ebp
		pop     ebp
		retn
	}*/
}

EXTERN_C __declspec(dllexport) DWORD MGetPID()
{
	return GetCurrentProcessId();
}

EXTERN_C __declspec(dllexport) PPCMGRTOKEN MGetToken()
{
	PCMGRTOKEN *t = (PCMGRTOKEN*)_malloc(sizeof(PCMGRTOKEN));
	t->tk = GetToken();
	t->pid = MGetPID();
	t->token = GetEntry();
	return t;
}