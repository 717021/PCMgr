#pragma once
#include "stdafx.h"
#include <Psapi.h>
#include <process.h>
#include <tlhelp32.h>
#include <CommCtrl.h>
#include <Uxtheme.h>
#include <shellapi.h>
#include <string>
#include <string.h>

void WindowEnumStart();
void WindowEnumDestroy();

BOOL MAppVProcessAllWindows();
void MAppVProcessAllWindowsUWP();
BOOL MAppVProcessAllWindowsGetProcessWindow(DWORD pid);
BOOL MAppVProcessAllWindowsGetProcessWindow2(DWORD pid);


//��ʾ�鿴ģ��Ի���
//    dwPID����Ҫ�鿴�Ľ���id
//    hDlg��������
//    procName���������֣���ʾ�ڱ�������
EXTERN_C M_API BOOL MAppVProcessModuls(DWORD dwPID, HWND hDlg, LPWSTR procName);
//��ʾ�鿴�̶߳Ի���
//    dwPID����Ҫ�鿴�Ľ���id
//    hDlg��������
//    procName���������֣���ʾ�ڱ�������
EXTERN_C M_API BOOL MAppVProcessThreads(DWORD dwPID, HWND hDlg, LPWSTR procName);
//��ʾ�鿴���ڶԻ���
//    dwPID����Ҫ�鿴�Ľ���id
//    hDlg��������
//    procName���������֣���ʾ�ڱ�������
EXTERN_C M_API BOOL MAppVProcessWindows(DWORD dwPID, HWND hDlg, LPWSTR procName);


BOOL MAppVModuls(DWORD dwPID, HWND hDlg, LPWSTR procName);

BOOL MAppVThreads(DWORD dwPID, HWND hDlg, LPWSTR procName);

BOOL MAppVWins(DWORD dwPID, HWND hDlg, LPWSTR procName);


INT_PTR CALLBACK VWinsDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK VModulsDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK VThreadsDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
