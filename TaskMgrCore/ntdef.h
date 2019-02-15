#pragma once
#include "stdafx.h"
//#include <winternl.h>

typedef LONG NTSTATUS;
typedef LONG KPRIORITY;

#define STATUS_SUCCESS                         ((NTSTATUS)0x00000000L)
#define STATUS_UNSUCCESSFUL                ((NTSTATUS)0xC0000001L)
#define STATUS_NOT_IMPLEMENTED            ((NTSTATUS)0xC0000002L)
#define STATUS_INVALID_INFO_CLASS      ((NTSTATUS)0xC0000003L)
#define STATUS_INFO_LENGTH_MISMATCH ((NTSTATUS)0xC0000004L)
#define STATUS_BUFFER_OVERFLOW           ((NTSTATUS)0x80000005L)
#define STATUS_INVALID_CID                      ((NTSTATUS)0xC000000BL)
#define STATUS_ACCESS_DENIED                 ((NTSTATUS)0xC0000022L)
#define STATUS_BUFFER_TOO_SMALL          ((NTSTATUS)0xC0000023L)
#define STATUS_PROCESS_IS_TERMINATING  ((NTSTATUS)0xC000010AL)
#define STATUS_THREAD_IS_TERMINATING   ((NTSTATUS)0xC000004BL)
#define STATUS_PORT_NOT_SET                ((NTSTATUS)0xC0000353L)
#define STATUS_NOT_SUPPORTED                ((NTSTATUS)0xC00000BBL)



#define NT_SUCCESS(status) ((NTSTATUS)(status)>=0)

typedef struct _ANSI_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PCHAR Buffer;
} ANSI_STRING, *PANSI_STRING;
typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
#ifdef MIDL_PASS
	[size_is(MaximumLength / 2), length_is((Length) / 2)] USHORT * Buffer;
#else // MIDL_PASS
	_Field_size_bytes_part_(MaximumLength, Length) PWCH   Buffer;
#endif // MIDL_PASS
} UNICODE_STRING, *PUNICODE_STRING;



typedef struct _RTL_USER_PROCESS_PARAMETERS {
	BYTE Reserved1[16];
	PVOID Reserved2[10];
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef VOID(NTAPI *PPS_POST_PROCESS_INIT_ROUTINE) (VOID);

typedef struct _PEB_LDR_DATA {
	BYTE Reserved1[8];
	PVOID Reserved2[3];
	LIST_ENTRY InMemoryOrderModuleList;
} PEB_LDR_DATA, *PPEB_LDR_DATA;
typedef struct _PEB {
	BYTE                          Reserved1[2];
	BYTE                          BeingDebugged;
	BYTE                          Reserved2[1];
	PVOID                         Reserved3[2];
	PPEB_LDR_DATA                 Ldr;
	PRTL_USER_PROCESS_PARAMETERS  ProcessParameters;
	PVOID                         Reserved4[3];
	PVOID                         AtlThunkSListPtr;
	PVOID                         Reserved5;
	ULONG                         Reserved6;
	PVOID                         Reserved7;
	ULONG                         Reserved8;
	ULONG                         AtlThunkSListPtr32;
	PVOID                         Reserved9[45];
	BYTE                          Reserved10[96];
	PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
	BYTE                          Reserved11[128];
	PVOID                         Reserved12[1];
	ULONG                         SessionId;
} PEB, *PPEB;
typedef struct _TEB {
	PVOID Reserved1[12];
	PPEB  ProcessEnvironmentBlock;
	PVOID Reserved2[399];
	BYTE  Reserved3[1952];
	PVOID TlsSlots[64];
	BYTE  Reserved4[8];
	PVOID Reserved5[26];
	PVOID ReservedForOle;
	PVOID Reserved6[4];
	PVOID TlsExpansionSlots;
} TEB, *PTEB;

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

typedef struct _CLIENT_ID
{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _OBJECT_ATTRIBUTES {
	ULONG Length;
	HANDLE RootDirectory;
	PUNICODE_STRING ObjectName;
	ULONG Attributes;
	PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
	PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;


typedef enum _SYSTEM_HANDLE_TYPE
{
	OB_TYPE_UNKNOWN,         // 0,δ֪����
	OB_TYPE_TYPE,            // 1,����
	OB_TYPE_DIRECTORY,       // 2,Ŀ¼
	OB_TYPE_SYMBOLIC_LINK,   // 3,��������
	OB_TYPE_TOKEN,           // 4,��ȫ
	OB_TYPE_PROCESS,         // 5,����
	OB_TYPE_THREAD,          // 6,�߳�
	OB_TYPE_JOB,             // 7,Job
	OB_TYPE_DEBUG_OBJECT,    // 8,���Զ���
	OB_TYPE_EVENT,           // 9,�¼�
	OB_TYPE_EVENT_PAIR,      // 10,�¼�
	OB_TYPE_MUTANT,          // 11,������
	OB_TYPE_CALLBACK,        // 12,�ص�
	OB_TYPE_SEMAPHORE,       // 13,�ź���
	OB_TYPE_TIMER,           // 14,ʱ��
	OB_TYPE_PROFILE,         // 15,Profile
	OB_TYPE_KEYED_EVENT,     // 16,�����¼�
	OB_TYPE_WINDOWS_STATION, // 17,fixed
	OB_TYPE_DESKTOP,         // 18,����
	OB_TYPE_SECTION,         // 19,�����ڴ���
	OB_TYPE_KEY,             // 20,��ֵ
	OB_TYPE_PORT,            // 21,�˿�
	OB_TYPE_WAITABLE_PORT,   // 22,�ɵȴ��˿�
	OB_TYPE_ADAPTER,         // 23,������
	OB_TYPE_CONTROLLER,      // 24,������
	OB_TYPE_DEVICE,          // 25,�豸
	OB_TYPE_DRIVER,          // 26,����
	OB_TYPE_IOCOMPLETION,    // 27,fixed
	OB_TYPE_FILE,            // 28,�ڴ�ӳ���ļ�
	OB_TYPE_WMIGUID          // 29,fixed
} SYSTEM_HANDLE_TYPE;
typedef enum _THREAD_STATE : ULONG {
	StateInitialized,
	StateReady,
	StateRunning,
	StateStandby,
	StateTerminated,
	StateWait,
	StateTransition,
	StateUnknown
} THREAD_STATE;
typedef enum _KWAIT_REASON : ULONG {
	Executive,
	FreePage,
	PageIn,
	PoolAllocation,
	DelayExecution,
	Suspended,
	UserRequest,
	WrExecutive,
	WrFreePage,
	WrPageIn,
	WrPoolAllocation,
	WrDelayExecution,
	WrSuspended,
	WrUserRequest,
	WrEventPair,
	WrQueue,
	WrLpcReceive,
	WrLpcReply,
	WrVirtualMemory,
	WrPageOut,
	WrRendezvous,
	Spare2,
	Spare3,
	Spare4,
	Spare5,
	Spare6,
	WrKernel
} KWAIT_REASON;

//system info
// source:http://www.microsoft.com/whdc/system/Sysinternals/MoreThan64proc.mspx
typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation, // q: SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation, // q: SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation, // q: SYSTEM_PERFORMANCE_INFORMATION
	SystemTimeOfDayInformation, // q: SYSTEM_TIMEOFDAY_INFORMATION
	SystemPathInformation, // not implemented
	SystemProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemCallCountInformation, // q: SYSTEM_CALL_COUNT_INFORMATION
	SystemDeviceInformation, // q: SYSTEM_DEVICE_INFORMATION
	SystemProcessorPerformanceInformation, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
	SystemFlagsInformation, // q: SYSTEM_FLAGS_INFORMATION
	SystemCallTimeInformation, // not implemented // 10
	SystemModuleInformation, // q: RTL_PROCESS_MODULES
	SystemLocksInformation,
	SystemStackTraceInformation,
	SystemPagedPoolInformation, // not implemented
	SystemNonPagedPoolInformation, // not implemented
	SystemHandleInformation, // q: SYSTEM_HANDLE_INFORMATION
	SystemObjectInformation, // q: SYSTEM_OBJECTTYPE_INFORMATION mixed with SYSTEM_OBJECT_INFORMATION
	SystemPageFileInformation, // q: SYSTEM_PAGEFILE_INFORMATION
	SystemVdmInstemulInformation, // q
	SystemVdmBopInformation, // not implemented // 20
	SystemFileCacheInformation, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemCache)
	SystemPoolTagInformation, // q: SYSTEM_POOLTAG_INFORMATION
	SystemInterruptInformation, // q: SYSTEM_INTERRUPT_INFORMATION
	SystemDpcBehaviorInformation, // q: SYSTEM_DPC_BEHAVIOR_INFORMATION; s: SYSTEM_DPC_BEHAVIOR_INFORMATION (requires SeLoadDriverPrivilege)
	SystemFullMemoryInformation, // not implemented
	SystemLoadGdiDriverInformation, // s (kernel-mode only)
	SystemUnloadGdiDriverInformation, // s (kernel-mode only)
	SystemTimeAdjustmentInformation, // q: SYSTEM_QUERY_TIME_ADJUST_INFORMATION; s: SYSTEM_SET_TIME_ADJUST_INFORMATION (requires SeSystemtimePrivilege)
	SystemSummaryMemoryInformation, // not implemented
	SystemMirrorMemoryInformation, // s (requires license value "Kernel-MemoryMirroringSupported") (requires SeShutdownPrivilege) // 30
	SystemPerformanceTraceInformation, // s
	SystemObsolete0, // not implemented
	SystemExceptionInformation, // q: SYSTEM_EXCEPTION_INFORMATION
	SystemCrashDumpStateInformation, // s (requires SeDebugPrivilege)
	SystemKernelDebuggerInformation, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION
	SystemContextSwitchInformation, // q: SYSTEM_CONTEXT_SWITCH_INFORMATION
	SystemRegistryQuotaInformation, // q: SYSTEM_REGISTRY_QUOTA_INFORMATION; s (requires SeIncreaseQuotaPrivilege)
	SystemExtendServiceTableInformation, // s (requires SeLoadDriverPrivilege) // loads win32k only
	SystemPrioritySeperation, // s (requires SeTcbPrivilege)
	SystemVerifierAddDriverInformation, // s (requires SeDebugPrivilege) // 40
	SystemVerifierRemoveDriverInformation, // s (requires SeDebugPrivilege)
	SystemProcessorIdleInformation, // q: SYSTEM_PROCESSOR_IDLE_INFORMATION
	SystemLegacyDriverInformation, // q: SYSTEM_LEGACY_DRIVER_INFORMATION
	SystemCurrentTimeZoneInformation, // q
	SystemLookasideInformation, // q: SYSTEM_LOOKASIDE_INFORMATION
	SystemTimeSlipNotification, // s (requires SeSystemtimePrivilege)
	SystemSessionCreate, // not implemented
	SystemSessionDetach, // not implemented
	SystemSessionInformation, // not implemented
	SystemRangeStartInformation, // q // 50
	SystemVerifierInformation, // q: SYSTEM_VERIFIER_INFORMATION; s (requires SeDebugPrivilege)
	SystemVerifierThunkExtend, // s (kernel-mode only)
	SystemSessionProcessInformation, // q: SYSTEM_SESSION_PROCESS_INFORMATION
	SystemLoadGdiDriverInSystemSpace, // s (kernel-mode only) (same as SystemLoadGdiDriverInformation)
	SystemNumaProcessorMap, // q
	SystemPrefetcherInformation, // q: PREFETCHER_INFORMATION; s: PREFETCHER_INFORMATION // PfSnQueryPrefetcherInformation
	SystemExtendedProcessInformation, // q: SYSTEM_PROCESS_INFORMATION
	SystemRecommendedSharedDataAlignment, // q
	SystemComPlusPackage, // q; s
	SystemNumaAvailableMemory, // 60
	SystemProcessorPowerInformation, // q: SYSTEM_PROCESSOR_POWER_INFORMATION
	SystemEmulationBasicInformation, // q
	SystemEmulationProcessorInformation,
	SystemExtendedHandleInformation, // q: SYSTEM_HANDLE_INFORMATION_EX
	SystemLostDelayedWriteInformation, // q: ULONG
	SystemBigPoolInformation, // q: SYSTEM_BIGPOOL_INFORMATION
	SystemSessionPoolTagInformation, // q: SYSTEM_SESSION_POOLTAG_INFORMATION
	SystemSessionMappedViewInformation, // q: SYSTEM_SESSION_MAPPED_VIEW_INFORMATION
	SystemHotpatchInformation, // q; s
	SystemObjectSecurityMode, // q // 70
	SystemWatchdogTimerHandler, // s (kernel-mode only)
	SystemWatchdogTimerInformation, // q (kernel-mode only); s (kernel-mode only)
	SystemLogicalProcessorInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION
	SystemWow64SharedInformationObsolete, // not implemented
	SystemRegisterFirmwareTableInformationHandler, // s (kernel-mode only)
	SystemFirmwareTableInformation, // not implemented
	SystemModuleInformationEx, // q: RTL_PROCESS_MODULE_INFORMATION_EX
	SystemVerifierTriageInformation, // not implemented
	SystemSuperfetchInformation, // q: SUPERFETCH_INFORMATION; s: SUPERFETCH_INFORMATION // PfQuerySuperfetchInformation
	SystemMemoryListInformation, // q: SYSTEM_MEMORY_LIST_INFORMATION; s: SYSTEM_MEMORY_LIST_COMMAND (requires SeProfileSingleProcessPrivilege) // 80
	SystemFileCacheInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (same as SystemFileCacheInformation)
	SystemThreadPriorityClientIdInformation, // s: SYSTEM_THREAD_CID_PRIORITY_INFORMATION (requires SeIncreaseBasePriorityPrivilege)
	SystemProcessorIdleCycleTimeInformation, // q: SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION[]
	SystemVerifierCancellationInformation, // not implemented // name:wow64:whNT32QuerySystemVerifierCancellationInformation
	SystemProcessorPowerInformationEx, // not implemented
	SystemRefTraceInformation, // q; s // ObQueryRefTraceInformation
	SystemSpecialPoolInformation, // q; s (requires SeDebugPrivilege) // MmSpecialPoolTag, then MmSpecialPoolCatchOverruns != 0
	SystemProcessIdInformation, // q: SYSTEM_PROCESS_ID_INFORMATION
	SystemErrorPortInformation, // s (requires SeTcbPrivilege)
	SystemBootEnvironmentInformation, // q: SYSTEM_BOOT_ENVIRONMENT_INFORMATION // 90
	SystemHypervisorInformation, // q; s (kernel-mode only)
	SystemVerifierInformationEx, // q; s
	SystemTimeZoneInformation, // s (requires SeTimeZonePrivilege)
	SystemImageFileExecutionOptionsInformation, // s: SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION (requires SeTcbPrivilege)
	SystemCoverageInformation, // q; s // name:wow64:whNT32QuerySystemCoverageInformation; ExpCovQueryInformation
	SystemPrefetchPatchInformation, // not implemented
	SystemVerifierFaultsInformation, // s (requires SeDebugPrivilege)
	SystemSystemPartitionInformation, // q: SYSTEM_SYSTEM_PARTITION_INFORMATION
	SystemSystemDiskInformation, // q: SYSTEM_SYSTEM_DISK_INFORMATION
	SystemProcessorPerformanceDistribution, // q: SYSTEM_PROCESSOR_PERFORMANCE_DISTRIBUTION // 100
	SystemNumaProximityNodeInformation, // q
	SystemDynamicTimeZoneInformation, // q; s (requires SeTimeZonePrivilege)
	SystemCodeIntegrityInformation, // q // SeCodeIntegrityQueryInformation
	SystemProcessorMicrocodeUpdateInformation, // s
	SystemProcessorBrandString, // q // HaliQuerySystemInformation -> HalpGetProcessorBrandString, info class 23
	SystemVirtualAddressInformation, // q: SYSTEM_VA_LIST_INFORMATION[]; s: SYSTEM_VA_LIST_INFORMATION[] (requires SeIncreaseQuotaPrivilege) // MmQuerySystemVaInformation
	SystemLogicalProcessorAndGroupInformation, // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX // since WIN7 // KeQueryLogicalProcessorRelationship
	SystemProcessorCycleTimeInformation, // q: SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION[]
	SystemStoreInformation, // q; s // SmQueryStoreInformation SYSTEM_COMPRESSION_INFO
	SystemRegistryAppendString, // s: SYSTEM_REGISTRY_APPEND_STRING_PARAMETERS // 110
	SystemAitSamplingValue, // s: ULONG (requires SeProfileSingleProcessPrivilege)
	SystemVhdBootInformation, // q: SYSTEM_VHD_BOOT_INFORMATION
	SystemCpuQuotaInformation, // q; s // PsQueryCpuQuotaInformation
	SystemNativeBasicInformation, // not implemented
	SystemSpare1, // not implemented
	SystemLowPriorityIoInformation, // q: SYSTEM_LOW_PRIORITY_IO_INFORMATION
	SystemTpmBootEntropyInformation, // q: TPM_BOOT_ENTROPY_NT_RESULT // ExQueryTpmBootEntropyInformation
	SystemVerifierCountersInformation, // q: SYSTEM_VERIFIER_COUNTERS_INFORMATION
	SystemPagedPoolInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypePagedPool)
	SystemSystemPtesInformationEx, // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemPtes) // 120
	SystemNodeDistanceInformation, // q
	SystemAcpiAuditInformation, // q: SYSTEM_ACPI_AUDIT_INFORMATION // HaliQuerySystemInformation -> HalpAuditQueryResults, info class 26
	SystemBasicPerformanceInformation, // q: SYSTEM_BASIC_PERFORMANCE_INFORMATION // name:wow64:whNtQuerySystemInformation_SystemBasicPerformanceInformation
	SystemQueryPerformanceCounterInformation, // q: SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION // since WIN7 SP1
	SystemSessionBigPoolInformation, // since WIN8
	SystemBootGraphicsInformation,
	SystemScrubPhysicalMemoryInformation,
	SystemBadPageInformation,
	SystemProcessorProfileControlArea,
	SystemCombinePhysicalMemoryInformation, // 130
	SystemEntropyInterruptTimingCallback,
	SystemConsoleInformation,
	SystemPlatformBinaryInformation,
	SystemThrottleNotificationInformation,
	SystemHypervisorProcessorCountInformation,
	SystemDeviceDataInformation,
	SystemDeviceDataEnumerationInformation,
	SystemMemoryTopologyInformation,
	SystemMemoryChannelInformation,
	SystemBootLogoInformation, // 140
	SystemProcessorPerformanceInformationEx, // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX // since WINBLUE
	SystemSpare0,
	SystemSecureBootPolicyInformation,
	SystemPageFileInformationEx, // q: SYSTEM_PAGEFILE_INFORMATION_EX
	SystemSecureBootInformation,
	SystemEntropyInterruptTimingRawInformation,
	SystemPortableWorkspaceEfiLauncherInformation,
	SystemFullProcessInformation, // q: SYSTEM_PROCESS_INFORMATION with SYSTEM_PROCESS_INFORMATION_EXTENSION (requires admin)
	SystemKernelDebuggerInformationEx, // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION_EX
	SystemBootMetadataInformation, // 150
	SystemSoftRebootInformation,
	SystemElamCertificateInformation,
	SystemOfflineDumpConfigInformation,
	SystemProcessorFeaturesInformation, // q: SYSTEM_PROCESSOR_FEATURES_INFORMATION
	SystemRegistryReconciliationInformation,
	SystemEdidInformation,
	SystemManufacturingInformation, // q: SYSTEM_MANUFACTURING_INFORMATION // since THRESHOLD 10.0 and higher
	SystemEnergyEstimationConfigInformation, // q: SYSTEM_ENERGY_ESTIMATION_CONFIG_INFORMATION
	SystemHypervisorDetailInformation, // q: SYSTEM_HYPERVISOR_DETAIL_INFORMATION
	SystemProcessorCycleStatsInformation, // q: SYSTEM_PROCESSOR_CYCLE_STATS_INFORMATION // 160
	SystemVmGenerationCountInformation,
	SystemTrustedPlatformModuleInformation, // q: SYSTEM_TPM_INFORMATION
	SystemKernelDebuggerFlags,
	SystemCodeIntegrityPolicyInformation,
	SystemIsolatedUserModeInformation,
	SystemHardwareSecurityTestInterfaceResultsInformation,
	SystemSingleModuleInformation, // q: SYSTEM_SINGLE_MODULE_INFORMATION
	SystemAllowedCpuSetsInformation,
	SystemDmaProtectionInformation, // q: SYSTEM_DMA_PROTECTION_INFORMATION
	SystemInterruptCpuSetsInformation,
	SystemSecureBootPolicyFullInformation,
	SystemCodeIntegrityPolicyFullInformation,
	SystemAffinitizedInterruptProcessorInformation,
	SystemRootSiloInformation, // q: SYSTEM_ROOT_SILO_INFORMATION
	SystemCpuSetInformation, // q: SYSTEM_CPU_SET_INFORMATION // since THRESHOLD2
	SystemCpuSetTagInformation, // q: SYSTEM_CPU_SET_TAG_INFORMATION
	SystemWin32WerStartCallout,
	SystemSecureKernelProfileInformation,
	SystemCodeIntegrityPlatformManifestInformation,//1511 and higher
	SystemInterruptSteeringInformation,
	SystemSuppportedProcessorArchitectures,
	SystemMemoryUsageInformation,//1607 and higher
	SystemCodeIntegrityCertificateInformation,
	SystemPhysicalMemoryInformation,
	SystemControlFlowTransition,
	SystemKernelDebuggingAllowed,
	SystemActivityModerationExeState,
	SystemActivityModerationUserSettings,
	SystemCodeIntegrityPoliciesFullInformation,
	SystemCodeIntegrityUnlockInformation,
	SystemIntegrityQuotaInformation,
	SystemFlushInformation,
	SystemProcessorIdleMaskInformation,
	SystemSecureDumpEncryptionInformation,
	SystemWriteConstraintInformation,
	MaxSystemInfoClass,
} SYSTEM_INFORMATION_CLASS;
typedef enum _OBJECT_INFORMATION_CLASS {
	ObjectBasicInformation = 0,
	ObjectNameInformation = 1,
	ObjectTypeInformation = 2
} OBJECT_INFORMATION_CLASS;
typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation, // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters, // q: IO_COUNTERS
	ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
	ProcessTimes, // q: KERNEL_USER_TIMES
	ProcessBasePriority, // s: KPRIORITY
	ProcessRaisePriority, // s: ULONG
	ProcessDebugPort, // q: HANDLE
	ProcessExceptionPort, // s: HANDLE
	ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation, // qs: PROCESS_LDT_INFORMATION // 10
	ProcessLdtSize, // s: PROCESS_LDT_SIZE
	ProcessDefaultHardErrorMode, // qs: ULONG
	ProcessIoPortHandlers, // (kernel-mode only)
	ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
	ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information,
	ProcessHandleCount, // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
	ProcessAffinityMask, // s: KAFFINITY
	ProcessPriorityBoost, // qs: ULONG
	ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information, // q: ULONG_PTR
	ProcessImageFileName, // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled, // q: ULONG
	ProcessBreakOnTermination, // qs: ULONG
	ProcessDebugObjectHandle, // q: HANDLE // 30
	ProcessDebugFlags, // qs: ULONG
	ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
	ProcessIoPriority, // qs: IO_PRIORITY_HINT
	ProcessExecuteFlags, // qs: ULONG
	ProcessResourceManagement,
	ProcessCookie, // q: ULONG
	ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
	ProcessPagePriority, // q: ULONG
	ProcessInstrumentationCallback, // 40
	ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
	ProcessImageFileNameWin32, // q: UNICODE_STRING
	ProcessImageFileMapping, // q: HANDLE (input)
	ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation, // q: USHORT[]
	ProcessTokenVirtualizationEnabled, // s: ULONG
	ProcessConsoleHostProcess, // q: ULONG_PTR
	ProcessWindowInformation, // q: PROCESS_WINDOW_INFORMATION // 50
	ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,
	ProcessHandleCheckingMode,
	ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
	ProcessHandleTable, // since WINBLUE
	ProcessCheckStackExtentsMode,
	ProcessCommandLineInformation, // q: UNICODE_STRING // 60
	ProcessProtectionInformation, // q: PS_PROTECTION
	ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
	ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
	ProcessTelemetryIdInformation, // PROCESS_TELEMETRY_ID_INFORMATION
	ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
	ProcessDefaultCpuSetsInformation,
	ProcessAllowedCpuSetsInformation,
	ProcessReserved1Information,
	ProcessReserved2Information,
	ProcessSubsystemProcess, // 70
	ProcessJobMemoryInformation, // PROCESS_JOB_MEMORY_INFO
	ProcessInPrivate, // since THRESHOLD2
	ProcessRaiseUMExceptionOnInvalidHandleClose,
	MaxProcessInfoClass
} PROCESSINFOCLASS;
typedef enum _THREADINFOCLASS {
	ThreadBasicInformation,
	ThreadTimes,
	ThreadPriority,
	ThreadBasePriority,
	ThreadAffinityMask,
	ThreadImpersonationToken,
	ThreadDescriptorTableEntry,
	ThreadEnableAlignmentFaultFixup,
	ThreadEventPair_Reusable,
	ThreadQuerySetWin32StartAddress,
	ThreadZeroTlsCell,
	ThreadPerformanceCount,
	ThreadAmILastThread,
	ThreadIdealProcessor,
	ThreadPriorityBoost,
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending,
	ThreadHideFromDebugger,
	ThreadBreakOnTermination,
	MaxThreadInfoClass
}   THREADINFOCLASS;
typedef enum _STORE_INFORMATION_CLASS
{
	ProcessCompressionInfoRequest = 0x16,
	StoreInformationMax
}STORE_INFORMATION_CLASS;
typedef enum _DEBUGOBJECTINFOCLASS
{
	DebugObjectFlags = 1,
	MaxDebugObjectInfoClass
} DEBUGOBJECTINFOCLASS, *PDEBUGOBJECTINFOCLASS;

typedef enum _IO_PRIORITY_HINT
{
	IoPriorityVeryLow = 0, // Defragging, content indexing and other background I/Os.
	IoPriorityLow, // Prefetching for applications.
	IoPriorityNormal, // Normal I/Os.
	IoPriorityHigh, // Used by filesystems for checkpoint I/O.
	IoPriorityCritical, // Used by memory manager. Not available for applications.
	MaxIoPriorityTypes
} IO_PRIORITY_HINT;

#define PROCESS_PRIORITY_CLASS_UNKNOWN 0
#define PROCESS_PRIORITY_CLASS_IDLE 1
#define PROCESS_PRIORITY_CLASS_NORMAL 2
#define PROCESS_PRIORITY_CLASS_HIGH 3
#define PROCESS_PRIORITY_CLASS_REALTIME 4
#define PROCESS_PRIORITY_CLASS_BELOW_NORMAL 5
#define PROCESS_PRIORITY_CLASS_ABOVE_NORMAL 6

typedef struct _PROCESS_PRIORITY_CLASS
{
	BOOLEAN Foreground;
	UCHAR PriorityClass;
} PROCESS_PRIORITY_CLASS, *PPROCESS_PRIORITY_CLASS;
typedef struct _PROCESS_WINDOW_INFORMATION
{
	ULONG WindowFlags;
	USHORT WindowTitleLength;
	WCHAR WindowTitle[1];
} PROCESS_WINDOW_INFORMATION, *PPROCESS_WINDOW_INFORMATION;
typedef struct _PROCESS_BASIC_INFORMATION {
	NTSTATUS ExitStatus;
	PPEB PebBaseAddress;
	ULONG_PTR AffinityMask;
	KPRIORITY BasePriority;
	ULONG_PTR UniqueProcessId;
	ULONG_PTR InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION,*PPROCESS_BASIC_INFORMATION;
typedef struct _PROCESS_HANDLE_TABLE_ENTRY_INFO
{
	HANDLE HandleValue;
	ULONG_PTR HandleCount;
	ULONG_PTR PointerCount;
	ULONG GrantedAccess;
	ULONG ObjectTypeIndex;
	ULONG HandleAttributes;
	ULONG Reserved;
} PROCESS_HANDLE_TABLE_ENTRY_INFO, *PPROCESS_HANDLE_TABLE_ENTRY_INFO;
typedef struct _PROCESS_HANDLE_SNAPSHOT_INFORMATION
{
	ULONG_PTR NumberOfHandles;
	ULONG_PTR Reserved;
	PROCESS_HANDLE_TABLE_ENTRY_INFO Handles[1];
} PROCESS_HANDLE_SNAPSHOT_INFORMATION, *PPROCESS_HANDLE_SNAPSHOT_INFORMATION;
typedef struct _PROCESS_HANDLE_INFORMATION
{
	ULONG HandleCount;
	ULONG HandleCountHighWatermark;
} PROCESS_HANDLE_INFORMATION, *PPROCESS_HANDLE_INFORMATION;
typedef struct _PROCESS_COMPRESSION_INFO {
	ULONG Version;
	ULONG CompressionPid;
	ULONGLONG CompressionWorkingSetSize;
	ULONGLONG CompressSize;
	ULONGLONG CompressedSize;
	ULONGLONG NonCompressedSize;
}PROCESS_COMPRESSION_INFO,*PPROCESS_COMPRESSION_INFO;

typedef struct _THREAD_BASIC_INFORMATION { // Information Class 0
	NTSTATUS ExitStatus;
	PTEB TebBaseAddress;
	CLIENT_ID ClientId;
	LONG AffinityMask;
	LONG Priority;
	LONG BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

typedef struct _SYSTEM_MODULE_INFORMATION {
	ULONG Reserved[2];
	PVOID Base;
	ULONG Size;
	ULONG Flags;
	USHORT Index;
	USHORT Unknown;
	USHORT LoadCount;
	USHORT ModuleNameOffset;
	CHAR ImageName[256];
} SYSTEM_MODULE_INFORMATION, *PSYSTEM_MODULE_INFORMATION;
typedef struct _SYSTEM_BASIC_INFORMATION
{
	ULONG Reserved;
	ULONG TimerResolution;
	ULONG PageSize;
	ULONG NumberOfPhysicalPages;
	ULONG LowestPhysicalPageNumber;
	ULONG HighestPhysicalPageNumber;
	ULONG AllocationGranularity;
	ULONG_PTR MinimumUserModeAddress;
	ULONG_PTR MaximumUserModeAddress;
	ULONG_PTR ActiveProcessorsAffinityMask;
	CCHAR NumberOfProcessors;
} SYSTEM_BASIC_INFORMATION, *PSYSTEM_BASIC_INFORMATION;
typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
{
	LARGE_INTEGER IdleTime;
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER DpcTime;
	LARGE_INTEGER InterruptTime;
	ULONG InterruptCount;
} SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION, *PSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;
typedef struct _SYSTEM_PROCESS_ID_INFORMATION {
	PVOID ProcessId;
	UNICODE_STRING ImageName;
}SYSTEM_PROCESS_ID_INFORMATION,*PSYSTEM_PROCESS_ID_INFORMATION;

typedef struct _OBJECT_NAME_INFORMATION
{
	UNICODE_STRING Name; // defined in winternl.h
	WCHAR NameBuffer;
}OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;
typedef struct _OBJECT_TYPE_INFORMATION
{
	UNICODE_STRING TypeName;
	ULONG TotalNumberOfObjects;
	ULONG TotalNumberOfHandles;
	ULONG TotalPagedPoolUsage;
	ULONG TotalNonPagedPoolUsage;
	ULONG TotalNamePoolUsage;
	ULONG TotalHandleTableUsage;
	ULONG HighWaterNumberOfObjects;
	ULONG HighWaterNumberOfHandles;
	ULONG HighWaterPagedPoolUsage;
	ULONG HighWaterNonPagedPoolUsage;
	ULONG HighWaterNamePoolUsage;
	ULONG HighWaterHandleTableUsage;
	ULONG InvalidAttributes;
	GENERIC_MAPPING GenericMapping;
	ULONG ValidAccessMask;
	BOOLEAN SecurityRequired;
	BOOLEAN MaintainHandleCount;
	ULONG PoolType;
	ULONG DefaultPagedPoolCharge;
	ULONG DefaultNonPagedPoolCharge;
} OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;
typedef struct _OBJECT_BASIC_INFORMATION {
	ULONG                   Attributes;
	ACCESS_MASK             DesiredAccess;
	ULONG                   HandleCount;
	ULONG                   ReferenceCount;
	ULONG                   PagedPoolUsage;
	ULONG                   NonPagedPoolUsage;
	ULONG                   Reserved[3];
	ULONG                   NameInformationLength;
	ULONG                   TypeInformationLength;
	ULONG                   SecurityDescriptorLength;
	LARGE_INTEGER           CreationTime;
} OBJECT_BASIC_INFORMATION, *POBJECT_BASIC_INFORMATION;

typedef struct _MEMORY_WORKING_SET_BLOCK
{
	ULONG_PTR Protection : 5;
	ULONG_PTR ShareCount : 3;
	ULONG_PTR Shared : 1;
	ULONG_PTR Node : 3;
#ifdef _WIN64
	ULONG_PTR VirtualPage : 52;
#else
	ULONG VirtualPage : 20;
#endif
} MEMORY_WORKING_SET_BLOCK, *PMEMORY_WORKING_SET_BLOCK;
typedef struct _MEMORY_WORKING_SET_INFORMATION
{
	ULONG_PTR NumberOfEntries;
	MEMORY_WORKING_SET_BLOCK WorkingSetInfo[1];
} MEMORY_WORKING_SET_INFORMATION, *PMEMORY_WORKING_SET_INFORMATION;
typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation, // MEMORY_BASIC_INFORMATION
	MemoryWorkingSetInformation, // MEMORY_WORKING_SET_INFORMATION
	MemoryMappedFilenameInformation, // UNICODE_STRING
	MemoryRegionInformation, // MEMORY_REGION_INFORMATION
	MemoryWorkingSetExInformation, // MEMORY_WORKING_SET_EX_INFORMATION
	MemorySharedCommitInformation, // MEMORY_SHARED_COMMIT_INFORMATION
	MemoryImageInformation // MEMORY_IMAGE_INFORMATION
} MEMORY_INFORMATION_CLASS;

typedef struct _SYSTEMMODULELIST {
	ULONG ulCount;
	SYSTEM_MODULE_INFORMATION smi[1];
} SYSTEMMODULELIST, *PSYSTEMMODULELIST;

typedef struct _VM_COUNTERS {
	ULONG_PTR PeakVirtualSize;
	ULONG_PTR VirtualSize;
	ULONG PageFaultCount;
	ULONG_PTR PeakWorkingSetSize;
	ULONG_PTR WorkingSetSize;
	ULONG_PTR QuotaPeakPagedPoolUsage;
	ULONG_PTR QuotaPagedPoolUsage;
	ULONG_PTR QuotaPeakNonPagedPoolUsage;
	ULONG_PTR QuotaNonPagedPoolUsage;
	ULONG_PTR PagefileUsage;
	ULONG_PTR PeakPagefileUsage;
	ULONG_PTR PrivatePageCount;
}VM_COUNTERS, *PVM_COUNTERS;

typedef struct _SYSTEM_THREADS {
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
	ULONG ContextSwitchCount;
	THREAD_STATE ThreadState;
	KWAIT_REASON WaitReason;
} SYSTEM_THREADS, *PSYSTEM_THREADS;
typedef struct _SYSTEM_PROCESSES { // Information Class 5 (Latest win10)(After win7)
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	LARGE_INTEGER WorkingSetPrivateSize;
	ULONG HardFaultCount;
	ULONG NumberOfThreadsHighWatermark;
	ULONGLONG CycleTime;
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ImageName;
	KPRIORITY BasePriority;
	PVOID ProcessId;
	PVOID InheritedFromProcessId;
	ULONG HandleCount;
	ULONG SessionId;
	ULONG_PTR UniqueProcessKey;
	VM_COUNTERS VmCounters;
	IO_COUNTERS IoCounters;
	SYSTEM_THREADS Threads[1];
} SYSTEM_PROCESSES, *PSYSTEM_PROCESSES;

typedef struct _SYSTEM_STORE_INFORMATION {
	ULONG Version;
	_STORE_INFORMATION_CLASS InfoClass;
	PVOID Data;
	ULONG Length;
}SYSTEM_STORE_INFORMATION,*PSYSTEM_STORE_INFORMATION;
typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO {
	USHORT UniqueProcessId;
	USHORT CreatorBackTraceIndex;
	UCHAR ObjectTypeIndex;
	UCHAR HandleAttributes;
	USHORT HandleValue;
	PVOID Object;
	ULONG GrantedAccess;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO, *PSYSTEM_HANDLE_TABLE_ENTRY_INFO;
typedef struct _SYSTEM_HANDLE_INFORMATION {
	ULONG NumberOfHandles;
	_SYSTEM_HANDLE_TABLE_ENTRY_INFO Handles[1];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;
typedef struct _SYSTEM_PERFORMANCE_INFORMATION
{
	LARGE_INTEGER IdleProcessTime;
	LARGE_INTEGER IoReadTransferCount;
	LARGE_INTEGER IoWriteTransferCount;
	LARGE_INTEGER IoOtherTransferCount;
	ULONG IoReadOperationCount;
	ULONG IoWriteOperationCount;
	ULONG IoOtherOperationCount;
	ULONG AvailablePages;//����
	ULONG CommittedPages;//���ύ
	ULONG CommitLimit;//�ύ����
	ULONG PeakCommitment;//�ύ��ֵ
	ULONG PageFaultCount;
	ULONG CopyOnWriteCount;
	ULONG TransitionCount;
	ULONG CacheTransitionCount;
	ULONG DemandZeroCount;
	ULONG PageReadCount;
	ULONG PageReadIoCount;
	ULONG CacheReadCount;
	ULONG CacheIoCount;
	ULONG DirtyPagesWriteCount;
	ULONG DirtyWriteIoCount;
	ULONG MappedPagesWriteCount;
	ULONG MappedWriteIoCount;
	ULONG PagedPoolPages;//��ҳ�����
	ULONG NonPagedPoolPages;//�Ƿ�ҳ�����
	ULONG PagedPoolAllocs;
	ULONG PagedPoolFrees;
	ULONG NonPagedPoolAllocs;
	ULONG NonPagedPoolFrees;
	ULONG FreeSystemPtes;
	ULONG ResidentSystemCodePage;
	ULONG TotalSystemDriverPages;
	ULONG TotalSystemCodePages;
	ULONG NonPagedPoolLookasideHits;
	ULONG PagedPoolLookasideHits;
	ULONG AvailablePagedPoolPages;
	ULONG ResidentSystemCachePage;
	ULONG ResidentPagedPoolPage;
	ULONG ResidentSystemDriverPage;
	ULONG CcFastReadNoWait;
	ULONG CcFastReadWait;
	ULONG CcFastReadResourceMiss;
	ULONG CcFastReadNotPossible;
	ULONG CcFastMdlReadNoWait;
	ULONG CcFastMdlReadWait;
	ULONG CcFastMdlReadResourceMiss;
	ULONG CcFastMdlReadNotPossible;
	ULONG CcMapDataNoWait;
	ULONG CcMapDataWait;
	ULONG CcMapDataNoWaitMiss;
	ULONG CcMapDataWaitMiss;
	ULONG CcPinMappedDataCount;
	ULONG CcPinReadNoWait;
	ULONG CcPinReadWait;
	ULONG CcPinReadNoWaitMiss;
	ULONG CcPinReadWaitMiss;
	ULONG CcCopyReadNoWait;
	ULONG CcCopyReadWait;
	ULONG CcCopyReadNoWaitMiss;
	ULONG CcCopyReadWaitMiss;
	ULONG CcMdlReadNoWait;
	ULONG CcMdlReadWait;
	ULONG CcMdlReadNoWaitMiss;
	ULONG CcMdlReadWaitMiss;
	ULONG CcReadAheadIos;
	ULONG CcLazyWriteIos;
	ULONG CcLazyWritePages;
	ULONG CcDataFlushes;
	ULONG CcDataPages;
	ULONG ContextSwitches;
	ULONG FirstLevelTbFills;
	ULONG SecondLevelTbFills;
	ULONG SystemCalls;
	ULONGLONG CcTotalDirtyPages;
	ULONGLONG CcDirtyPageThreshold;
	LONGLONG ResidentAvailablePages;
	ULONGLONG SharedCommittedPages;
}SYSTEM_PERFORMANCE_INFORMATION, *PSYSTEM_PERFORMANCE_INFORMATION;
typedef struct _SYSTEM_MEMORY_LIST_INFORMATION
{
	ULONG_PTR ZeroPageCount;
	ULONG_PTR FreePageCount;
	ULONG_PTR ModifiedPageCount;
	ULONG_PTR ModifiedNoWritePageCount;
	ULONG_PTR BadPageCount;
	ULONG_PTR PageCountByPriority[8];
	ULONG_PTR RepurposedPagesByPriority[8];
	ULONG_PTR ModifiedPageCountPageFile;
} SYSTEM_MEMORY_LIST_INFORMATION, *PSYSTEM_MEMORY_LIST_INFORMATION;

typedef LONG(NTAPI * RtlNtStatusToDosErrorFun)(ULONG status);
typedef NTSTATUS(NTAPI *RtlGetLastWin32ErrorFun)();
typedef NTSTATUS(NTAPI *NtOpenThreadFun)(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);
typedef NTSTATUS(NTAPI *NtTerminateThreadFun)(HANDLE ThreadHandle, DWORD ExitCode);
typedef NTSTATUS(NTAPI *NtSuspendThreadFun)(HANDLE ThreadHandle, PULONG PreviousSuspendCount OPTIONAL);
typedef NTSTATUS(NTAPI *NtResumeThreadFun)(HANDLE ThreadHandle, PULONG SuspendCount OPTIONAL);


typedef NTSTATUS(NTAPI*NtSetInformationProcessFun)(_In_ HANDLE ProcessHandle, _In_ PROCESSINFOCLASS ProcessInformationClass, _In_reads_bytes_(ProcessInformationLength) PVOID ProcessInformation, _In_ ULONG ProcessInformationLength);
typedef NTSTATUS(NTAPI*NtSetInformationDebugObjectFun)(_In_ HANDLE DebugObjectHandle,	_In_ DEBUGOBJECTINFOCLASS DebugObjectInformationClass,	_In_ PVOID DebugInformation,	_In_ ULONG DebugInformationLength,	_Out_opt_ PULONG ReturnLength);

typedef NTSTATUS(NTAPI*NtRemoveProcessDebugFun)(_In_ HANDLE ProcessHandle, _In_ HANDLE DebugObjectHandle);

typedef NTSTATUS(NTAPI *NtQueryVirtualMemoryFun)(_In_ HANDLE ProcessHandle, _In_ PVOID BaseAddress, _In_ MEMORY_INFORMATION_CLASS MemoryInformationClass, _Out_writes_bytes_(MemoryInformationLength) PVOID MemoryInformation, _In_ SIZE_T MemoryInformationLength, _Out_opt_ PSIZE_T ReturnLength);
typedef NTSTATUS(NTAPI *NtQueryInformationProcessFun)(HANDLE ProcessHandle, DWORD ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
typedef NTSTATUS(NTAPI *NtQuerySystemInformationFun)(IN ULONG SysInfoClass, IN OUT PVOID SystemInformation, IN ULONG SystemInformationLength, OUT PULONG nRet);
typedef NTSTATUS(NTAPI *NtQueryInformationThreadFun)(HANDLE ThreadHandle, ULONG ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength, PULONG ReturnLength OPTIONAL);
typedef NTSTATUS(NTAPI *NtSuspendProcessFun)(HANDLE);
typedef NTSTATUS(NTAPI *NtResumeProcessFun)(HANDLE);
typedef NTSTATUS(NTAPI *NtTerminateProcessFun)(HANDLE, DWORD);
typedef NTSTATUS(NTAPI *NtOpenProcessFun)(PHANDLE ProcessHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);
typedef NTSTATUS(NTAPI *NtUnmapViewOfSectionFun)(IN HANDLE ProcessHandle, IN PVOID BaseAddress);
typedef NTSTATUS(NTAPI *NtQueryObjectFun)(HANDLE Handle, OBJECT_INFORMATION_CLASS Info, PVOID Buffer, ULONG BufferSize, PULONG ReturnLength);
typedef NTSTATUS(NTAPI *NtReadVirtualMemoryFun)(_In_ HANDLE ProcessHandle, _In_opt_ PVOID BaseAddress, _Out_writes_bytes_(BufferSize) PVOID Buffer, _In_ SIZE_T BufferSize, _Out_opt_ PSIZE_T NumberOfBytesRead);
typedef NTSTATUS(NTAPI *NtDuplicateObjectFun)(_In_ HANDLE SourceProcessHandle, _In_ HANDLE SourceHandle, _In_opt_ HANDLE TargetProcessHandle, _Out_opt_ PHANDLE TargetHandle, _In_ ACCESS_MASK DesiredAccess, _In_ ULONG HandleAttributes, _In_ ULONG Options);
typedef NTSTATUS(NTAPI *NtCloseFun)(_In_ HANDLE Handle);

typedef NTSTATUS(NTAPI *LdrGetProcedureAddressFun)(_In_ PVOID DllHandle, _In_opt_ PANSI_STRING ProcedureName, _In_opt_ ULONG ProcedureNumber, _Out_ PVOID* ProcedureAddress);
typedef VOID(NTAPI *RtlInitAnsiStringFun)(_Out_ PANSI_STRING DestinationString, _In_opt_ PSTR SourceString);

#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)
#define ZwCurrentProcess() NtCurrentProcess()
#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)
#define ZwCurrentThread() NtCurrentThread()
#define NtCurrentSession() ((HANDLE)(LONG_PTR)-3)
#define ZwCurrentSession() NtCurrentSession()
#define NtCurrentPeb() (NtCurrentTeb()->ProcessEnvironmentBlock)

/*typedef BOOL(*KsGetStateFun)();
typedef BOOL(*KsOpenProcessHandleFun)(DWORD dwPID, PHANDLE pHandle);
typedef BOOL(*KsOpenThreadHandleFun)(DWORD dwTID, PHANDLE pHandle);
typedef BOOL(*KsTerminateProcessFun)(DWORD dwPID);
typedef BOOL(*KsTerminateThreadFun)(DWORD dwTID);
typedef BOOL(*KsSuspendProcessFun)(DWORD dwPID);
typedef BOOL(*KsResusemeProcessFun)(DWORD dwPID);*/

#define IsConsoleHandle(h) (((((ULONG_PTR)h) & 0x10000003) == 0x3) ? TRUE : FALSE)

#define OBJ_INHERIT             0x00000002L
#define OBJ_PERMANENT           0x00000010L
#define OBJ_EXCLUSIVE           0x00000020L
#define OBJ_CASE_INSENSITIVE    0x00000040L
#define OBJ_OPENIF              0x00000080L
#define OBJ_OPENLINK            0x00000100L
#define OBJ_KERNEL_HANDLE       0x00000200L
#define OBJ_FORCE_ACCESS_CHECK  0x00000400L
#define OBJ_VALID_ATTRIBUTES    0x000007F2L