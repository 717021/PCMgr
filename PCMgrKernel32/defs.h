#pragma once

typedef char BYTE;
typedef unsigned long DWORD;

typedef void* (__cdecl *memset_)(void*  _Dst, int _Val, size_t _Size);
typedef int(_stdcall *memcpy_s_)(void* const _Destination, rsize_t const _DestinationSize, void const* const _Source, rsize_t const _SourceSize);
typedef int(_stdcall *strcpy_s_)(char* _Destination, rsize_t _SizeInBytes, char const* _Source);
typedef int(_stdcall *strcat_s_)(char* _Destination, rsize_t _SizeInBytes, char const* _Source);
typedef int(_stdcall *swprintf_s_)(wchar_t* _Buffer, wchar_t const* _Format, ...);
typedef int(_stdcall *wcscpy_s_)(wchar_t* _Destination, rsize_t _SizeInWords,	_In_z_ wchar_t const* _Source);
typedef int(_stdcall *wcscat_s_)(wchar_t* _Destination, rsize_t _SizeInWords, _In_z_ wchar_t const* _Source);

typedef NTSTATUS(_stdcall *PspTerminateThreadByPointer_)(IN PETHREAD Thread, IN NTSTATUS ExitStatus, IN BOOLEAN DirectTerminate);
typedef NTSTATUS(_stdcall *PspExitThread_)(IN NTSTATUS ExitStatus);
typedef NTSTATUS(_stdcall *PsResumeProcess_)(PEPROCESS Process);
typedef NTSTATUS(_stdcall *PsSuspendProcess_)(PEPROCESS Process);
typedef NTSTATUS(_stdcall *PsLookupProcessByProcessId_)(HANDLE ProcessId, PEPROCESS *Process);
typedef NTSTATUS(_stdcall *PsLookupThreadByThreadId_)(HANDLE ThreadId, PETHREAD *Thread);
typedef PETHREAD(_stdcall *PsGetNextProcessThread_)(IN PEPROCESS Process, IN PETHREAD Thread);
typedef NTSTATUS(_stdcall *PsTerminateProcess_)(PEPROCESS Process, NTSTATUS ExitStatus);
typedef PEPROCESS(_stdcall *PsGetNextProcess_)(PEPROCESS Process);
typedef ULONG(_stdcall *KeForceResumeThread_)(__inout PKTHREAD Thread);

typedef enum _KAPC_ENVIRONMENT
{
	OriginalApcEnvironment,
	AttachedApcEnvironment,
	CurrentApcEnvironment,
	InsertApcEnvironment
} KAPC_ENVIRONMENT;

typedef VOID(*PKNORMAL_ROUTINE) (IN PVOID NormalContext, IN PVOID SystemArgument1, IN PVOID SystemArgument2);
typedef VOID(*PKKERNEL_ROUTINE) (IN struct _KAPC *Apc, IN OUT PKNORMAL_ROUTINE *NormalRoutine, IN OUT PVOID *NormalContext, IN OUT PVOID *SystemArgument1, IN OUT PVOID *SystemArgument2);
typedef VOID (*PKRUNDOWN_ROUTINE) (IN struct _KAPC *Apc);


typedef struct _THREAD_BASIC_INFORMATION { // Information Class 0
	LONG     ExitStatus;
	PVOID    TebBaseAddress;
	CLIENT_ID ClientId;
	LONG AffinityMask;
	LONG Priority;
	LONG BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

typedef struct _LDR_DATA_TABLE_ENTRY64
{
	LIST_ENTRY64    InLoadOrderLinks;
	LIST_ENTRY64    InMemoryOrderLinks;
	LIST_ENTRY64    InInitializationOrderLinks;
	PVOID            DllBase;
	PVOID            EntryPoint;
	ULONG            SizeOfImage;
	UNICODE_STRING    FullDllName;
	UNICODE_STRING     BaseDllName;
	ULONG            Flags;
	USHORT            LoadCount;
	USHORT            TlsIndex;
	PVOID            SectionPointer;
	ULONG            CheckSum;
	PVOID            LoadedImports;
	PVOID            EntryPointActivationContext;
	PVOID            PatchInformation;
	LIST_ENTRY64    ForwarderLinks;
	LIST_ENTRY64    ServiceTagLinks;
	LIST_ENTRY64    StaticLinks;
	PVOID            ContextInformation;
	ULONG64            OriginalBase;
	LARGE_INTEGER    LoadTime;
} LDR_DATA_TABLE_ENTRY64, *PLDR_DATA_TABLE_ENTRY64;

typedef struct _LDR_DATA_TABLE_ENTRY32 {
	LIST_ENTRY32 InLoadOrderLinks;
	LIST_ENTRY32 InMemoryOrderLinks;
	LIST_ENTRY32 InInitializationOrderLinks;
	ULONG DllBase;
	ULONG EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING32 FullDllName;
	UNICODE_STRING32 BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY32 HashLinks;
	ULONG SectionPointer;
	ULONG CheckSum;
	ULONG TimeDateStamp;
	ULONG LoadedImports;
	ULONG EntryPointActivationContext;
	ULONG PatchInformation;
	LIST_ENTRY32 ForwarderLinks;
	LIST_ENTRY32 ServiceTagLinks;
	LIST_ENTRY32 StaticLinks;
	ULONG ContextInformation;
	ULONG OriginalBase;
	LARGE_INTEGER LoadTime;
} LDR_DATA_TABLE_ENTRY32, *PLDR_DATA_TABLE_ENTRY32;

typedef struct _OBJECT_HANDLE_FLAG_INFORMATION {
	BOOLEAN Inherit;
	BOOLEAN ProtectFromClose;
}OBJECT_HANDLE_FLAG_INFORMATION, *POBJECT_HANDLE_FLAG_INFORMATION;

typedef PVOID HWND;
typedef unsigned int UINT;

//Hot key
typedef struct _HOT_KEY_ITEM
{
	LIST_ENTRY ListEntry;
	struct _ETHREAD *Thread;
	HWND hWnd;
	int id;
	UINT fsModifiers;
	UINT vk;
} HOT_KEY_ITEM, *PHOT_KEY_ITEM;

typedef struct _HEAD {
	HANDLE h;
	DWORD cLockObj;
} HEAD, *PHEAD;
//Timer
typedef struct tagTIMER {
	HEAD head;
	// 下个结构
	struct tagTIMER *ptmrNext;
	struct tagTIMER *ptmrPrev;
	PULONG pti;
	// 窗口句柄
	PULONG spwnd;
	// 定时器ID
	UINT_PTR nID;
	// 倒计时
	INT cmsCountdown;
	// 间隔时间
	INT cmsRate;
	UINT flags;
	// 函数入口
	ULONG pfn;
	PULONG ptiOptCreator;
} TIMER, *PTIMER;

#ifdef _AMD64_
typedef struct _PEB_LDR_DATA {
	ULONG Length;
	UCHAR Initialized;
	PVOID SsHandle;
	LIST_ENTRY64 InLoadOrderLinks;
	LIST_ENTRY64 InMemoryOrderLinks;
	LIST_ENTRY64 InInitializationOrderLinks;
	PVOID EntryInProgress;
	UCHAR ShutdownInProgress;
	PVOID ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;
#else
typedef struct _PEB_LDR_DATA {
	ULONG Length;
	UCHAR Initialized;
	PVOID SsHandle;
	LIST_ENTRY32 InLoadOrderLinks;
	LIST_ENTRY32 InMemoryOrderLinks;
	LIST_ENTRY32 InInitializationOrderLinks;
	PVOID EntryInProgress;
	UCHAR ShutdownInProgress;
	PVOID ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;
#endif

typedef struct tag_GET_HOT_KEYS_CACHE
{
	struct tag_GET_HOT_KEYS_CACHE*Next;
	struct HOT_KEY_ITEM*Object;
}GET_HOT_KEYS_CACHE, *PGET_HOT_KEYS_CACHE;

typedef struct tag_GET_TIMERS_CACHE
{
	struct tag_GET_TIMERS_CACHE*Next;
	struct TIMER*Object;
}GET_TIMERS_CACHE,*PGET_TIMERS_CACHE;

extern NTKERNELAPI int PsGetProcessPriorityClass(PEPROCESS Process);
extern NTKERNELAPI VOID* PsGetProcessJob(PEPROCESS Process);
extern NTKERNELAPI VOID* PsGetProcessPeb(PEPROCESS Process);
extern NTKERNELAPI UCHAR* PsGetProcessImageFileName(PEPROCESS Process);
extern NTKERNELAPI VOID* PsGetThreadTeb(PETHREAD Thread);
extern NTKERNELAPI NTSTATUS PsResumeProcess(PEPROCESS Process);
extern NTKERNELAPI NTSTATUS PsSuspendProcess(PEPROCESS Process);
extern NTKERNELAPI PEPROCESS IoThreadToProcess(PETHREAD Thread);
extern NTKERNELAPI NTSTATUS ZwQueryInformationThread(HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength, PULONG ReturnLength OPTIONAL);
extern NTKERNELAPI NTSTATUS ZwQueryInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
extern NTKERNELAPI NTSTATUS ObReferenceObjectByName(PUNICODE_STRING ObjectName, ULONG Attributes, PACCESS_STATE AccessState, ACCESS_MASK DesiredAccess, POBJECT_TYPE ObjectType, KPROCESSOR_MODE AccessMode, PVOID ParseContext, PVOID *Object);
extern NTKERNELAPI NTSTATUS ObSetHandleAttributes(HANDLE Handle, POBJECT_HANDLE_FLAG_INFORMATION HandleFlags, KPROCESSOR_MODE PreviousMode);

extern POBJECT_TYPE *IoDriverObjectType;

extern VOID NTAPI KeInitializeApc(__in PKAPC Apc, __in PKTHREAD Thread, __in KAPC_ENVIRONMENT   TargetEnvironment, __in PKKERNEL_ROUTINE KernelRoutine, __in_opt PKRUNDOWN_ROUTINE RundownRoutine, __in PKNORMAL_ROUTINE NormalRoutine, __in KPROCESSOR_MODE Mode, __in PVOID Context);
extern BOOLEAN NTAPI KeInsertQueueApc(IN PKAPC Apc, IN PVOID SystemArgument1, IN PVOID SystemArgument2, IN KPRIORITY PriorityBoost);

