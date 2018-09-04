#pragma once
#include "stdafx.h"
#undef _USE_ATTRIBUTES_FOR_SAL
#define _USE_ATTRIBUTES_FOR_SAL 1
#include <sal.h>

//��־��¼�ȼ�
enum LogLevel {
	LogLevFull,//ȫ����¼
	LogLevDebug,//���������������
	LogLevWarn,//�����漰����
	LogLevError,//������
	LogLevDisabled//�������
};


//���/��¼����
#define LogErr M_LOG_LogErrW
//���/��¼����
#define LogWarn M_LOG_LogWarnW
//���/��¼��Ϣ
#define LogInfo M_LOG_LogInfoW
//���/��¼����
#define LogText M_LOG_LogTextW
//���/��¼
#define Log M_LOG_LogW

//���/��¼�����ļ�
#define FLogErr M_LOG_Error_ForceFileW
//���/��¼���浽�ļ�
#define FLogWarn M_LOG_Warning_ForceFileW
//���/��¼��Ϣ���ļ�
#define FLogInfo M_LOG_Info_ForceFileW
//���/��¼���ֵ��ļ�
#define FLog M_LOG_Str_ForceFileW

M_CAPI(void) M_LOG_Error_ForceFileA(_Printf_format_string_ const char* szFormat, ...);
M_CAPI(void) M_LOG_Warning_ForceFileA(_Printf_format_string_ const char* szFormat, ...);
M_CAPI(void) M_LOG_Info_ForceFileA(_Printf_format_string_ const char* szFormat, ...);
M_CAPI(void) M_LOG_Str_ForceFileA(_Printf_format_string_ const char* szFormat, ...);
M_CAPI(void) M_LOG_Error_ForceFileW(_Printf_format_string_ const wchar_t* szFormat, ...);
M_CAPI(void) M_LOG_Warning_ForceFileW(_Printf_format_string_ const wchar_t* szFormat, ...);
M_CAPI(void) M_LOG_Info_ForceFileW(_Printf_format_string_ const wchar_t* szFormat, ...);
M_CAPI(void) M_LOG_Str_ForceFileW(_Printf_format_string_ const wchar_t* szFormat, ...);

void M_LOG_Init();
void M_LOG_Destroy();
void M_LOG_FocusConsoleWindow();
void M_LOG_CloseConsole(BOOL callFormCloseEvent, BOOL callFormConsoleApp = FALSE);

//���� Log ��ǰ��¼�ȼ�
//   	LogLevFull,        ȫ����¼
//   	LogLevDebug,   ���������������
//   	LogLevWarn,     �����漰����
//   	LogLevError,     ������
//   	LogLevDisabled �������
M_CAPI(void) M_LOG_SetLogLevelStr(LPCWSTR level);
//���� Log ��ǰ��¼�ȼ�
M_CAPI(void) M_LOG_SetLogLevel(LogLevel level);
//��ȡ Log ��ǰ��¼�ȼ�
M_CAPI(LogLevel) M_LOG_GetLogLevel(int l);
//���� Log ģ��
M_CAPI(void) M_LOG_DisableLog();

//�ر� Log ģ�飨�����ڿ���̨����
M_CAPI(void) M_LOG_Close_InConsole();
//�ر� Log ģ��
M_CAPI(void) M_LOG_Close();
//��ʼ�� Log ģ�飨�����ڿ���̨����
M_CAPI(void) M_LOG_Init_InConsole();
//��ʼ�� Log ģ�飨�����ڷǿ���̨����
//    showConsole���Ƿ���ʾ����̨�������
//    enableFileLog���Ƿ������ļ���¼
M_CAPI(void) M_LOG_Init(BOOL showConsole, BOOL enableFileLog = TRUE);

//���/��¼�����Զ���¼����λ��
#define LogErr2(format,...) M_LOG_LogErr_WithFunAndLineW(__FILE__,__FUNCTION__,__LINE__,format, __VA_ARGS__)
//���/��¼���沢�Զ���¼����λ��
#define LogWarn2(format,...) M_LOG_LogWarn_WithFunAndLineW(__FILE__,__FUNCTION__,__LINE__,format, __VA_ARGS__)
//���/��¼��Ϣ���Զ���¼����λ��
#define LogInfo2(format,...) M_LOG_LogInfo_WithFunAndLineW(__FILE__,__FUNCTION__,__LINE__,format, __VA_ARGS__)
//���/��¼��Ϣ���Զ���¼����λ��
#define Log2(format,...) M_LOG_Log_WithFunAndLineW(__FILE__,__FUNCTION__,__LINE__,format, __VA_ARGS__)

M_CAPI(void) M_LOG_LogErr_WithFunAndLineW(LPSTR fileName, LPSTR funName, INT lineNumber,  _In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_LogWarn_WithFunAndLineW(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_LogInfo_WithFunAndLineW(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_Log_WithFunAndLineW(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);

M_CAPI(void) M_LOG_LogErrW(_In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_LogWarnW(_In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_LogInfoW(_In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);
M_CAPI(void) M_LOG_LogW(_In_z_ _Printf_format_string_ wchar_t const* const _Format, ...);

M_CAPI(void) M_LOG_LogErr_WithFunAndLineA(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_LogWarn_WithFunAndLineA(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_LogInfo_WithFunAndLineA(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_Log_WithFunAndLineA(LPSTR fileName, LPSTR funName, INT lineNumber, _In_z_ _Printf_format_string_ char const* const _Format, ...);

M_CAPI(void) M_LOG_LogErrA(_In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_LogWarnA(_In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_LogInfoA(_In_z_ _Printf_format_string_ char const* const _Format, ...);
M_CAPI(void) M_LOG_LogA(_In_z_ _Printf_format_string_ char const* const _Format, ...);

M_CAPI(void) M_LOG_PrintColorTextA(WORD color, char const* const _Format, ...);
M_CAPI(void) M_LOG_PrintColorTextW(WORD color, wchar_t const* const _Format, ...);
