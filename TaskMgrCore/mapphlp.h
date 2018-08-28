#pragma once
#include "stdafx.h"
#include "ntdef.h"
#include "cscall.h"
#include "msup.h"

#define M_MTMSG_ 1
#define M_MTMSG_COSCLOSE 1

#define M_DRAW_HEADER_HOT 1
#define M_DRAW_HEADER_PRESSED 2
#define M_DRAW_HEADER_SORTDOWN 3
#define M_DRAW_HEADER_SORTUP 4

#define M_DRAW_LISTVIEW_HOT 1
#define M_DRAW_LISTVIEW_SELECT_NOFOCUS 2
#define M_DRAW_LISTVIEW_HOT_SELECT 3
#define M_DRAW_LISTVIEW_SELECT 4

#define M_DRAW_TREEVIEW_GY_OPEN 5
#define M_DRAW_TREEVIEW_GY_CLOSED 6
#define M_DRAW_TREEVIEW_GY_OPEN_HOT 7
#define M_DRAW_TREEVIEW_GY_CLOSED_HOT 8

#define M_DRAW_EXPAND_NORMAL 1
#define M_DRAW_EXPAND_HOVER 2
#define M_DRAW_EXPAND_PRESSED 3

typedef void(__cdecl *exitcallback)();
typedef int(__cdecl *taskdialogcallback)(HWND hwnd, LPWSTR text, LPWSTR title, LPWSTR apptl, int ico, int button);
typedef void(__cdecl *EnumWinsCallBack)(HWND hWnd, HWND hWndParent);
typedef void(__cdecl *GetWinsCallBack)(HWND hWnd, HWND hWndParent, int i);
typedef void(__cdecl *WorkerCallBack)(int msg, void* data1, void* data2);
typedef BOOL(__cdecl *TerminateImporantWarnCallBack)(LPWSTR commandName, int id);

//������ WinProc
LRESULT MAppWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT MProcListWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//��ʾ����Ի���
void MPrintErrorMessage(LPWSTR str, int icon = MB_OK);
//��ʾһ���Ի���
int MShowMessageDialog(HWND hwnd, LPWSTR text, LPWSTR title, LPWSTR instruction, int i=0, int button=0);
//��ʾ����Ի���
int MShowErrorMessage(LPWSTR text, LPWSTR intr, int ico=0, int btn=0);
//��ʾ����LastErr�Ĵ���Ի���
int MShowErrorMessageWithLastErr(LPWSTR text, LPWSTR intr, int ico, int btn);
//��ʾ NTSTATUS ����Ի���
void MShowErrorMessageWithNTSTATUS(LPWSTR msg, LPWSTR title, NTSTATUS status);

EXTERN_C M_API BOOL MIsSystemSupport();
EXTERN_C M_API void MAppRun2();
EXTERN_C M_API void MAppMainExit(UINT exitcode);
EXTERN_C M_API DWORD MAppMainGetExitCode();
EXTERN_C M_API BOOL MAppMainRun();

EXTERN_C M_API int MAppMainGetArgs(LPWSTR cmdline);
EXTERN_C M_API LPWSTR MAppMainGetArgsStr(int index);
EXTERN_C M_API void MAppMainGetArgsFreeAll();

EXTERN_C M_API void MAppHideCos();
EXTERN_C M_API void* MAppSetCallBack(void* cp, int id);
EXTERN_C M_API void MAppMainCall(int msg, void * data1, void * data2);
EXTERN_C M_API void MAppSetLanuageItems(int in, int ind, LPWSTR msg, int size);
EXTERN_C M_API int MAppRegShowHotKey(HWND hWnd, UINT vkkey, UINT key);
EXTERN_C M_API void MAppSetStartingProgessText(LPWSTR text);
EXTERN_C M_API void MAppSet(int id, void*v);
EXTERN_C M_API void MAppTest(int id, void*v);
EXTERN_C M_API void MAppExit();
EXTERN_C M_API void MAppRebot();
EXTERN_C M_API void MAppRebotAdmin();
EXTERN_C M_API void MAppRebotAdmin2(LPWSTR agrs);

EXTERN_C M_API HANDLE MOpenThemeData(HWND hWnd, LPWSTR className);
EXTERN_C M_API void MCloseThemeData(HANDLE hTheme);
EXTERN_C M_API void MSetAsExplorerTheme(HWND hWnd);
EXTERN_C M_API void MDrawIcon(HICON hIcon, HDC hdc, int x, int y);
EXTERN_C M_API void MExpandDrawButton(HANDLE hTheme, HDC hdc, int x, int y, int state, BOOL on);
EXTERN_C M_API void MHeaderDrawItem(HANDLE hTheme, HDC hdc, int x, int y, int w, int h, int state);
EXTERN_C M_API void MListDrawItem(HANDLE hTheme, HDC hdc, int x, int y, int w, int h, int state);
BOOL MAppStartEnd();
BOOL MAppStartTryActiveLastApp(LPWSTR windowTitle);
EXTERN_C M_API BOOL MAppKillOld(LPWSTR procName);
BOOL MAppStartTest();
EXTERN_C M_API LRESULT MAppWorkCall1(WPARAM wParam, LPARAM lParam);
EXTERN_C M_API void MAppWorkCall2(UINT msg, WPARAM wParam, LPARAM lParam);
EXTERN_C M_API int MAppWorkCall3(int id, HWND hWnd, void*data);
EXTERN_C M_API LRESULT MAppMainThreadCall(WPARAM wParam, LPARAM lParam);

//��ȡ���ڵ�ͼ��
//    hWnd �����ھ��
EXTERN_C M_API HICON MGetWindowIcon(HWND hWnd);

M_CAPI(void) MListViewSetColumnSortArrow(HWND hListHeader, int index, BOOL isUp, BOOL no);
M_CAPI(HWND) MListViewGetHeaderControl(HWND hList, BOOL isMain = FALSE);

//�ַ����Ƿ����
#define MStrEqual MStrEqualW
//խ�ַ�תΪ���ַ�
#define A2W MConvertLPCSTRToLPWSTR
//���ַ�תΪխ�ַ�
#define W2A MConvertLPWSTRToLPCSTR

EXTERN_C M_API void MConvertStrDel(void * str);

//խ�ַ�תΪ���ַ�
EXTERN_C M_API LPWSTR MConvertLPCSTRToLPWSTR(const char * szString);
//���ַ�תΪխ�ַ�
EXTERN_C M_API LPCSTR MConvertLPWSTRToLPCSTR(const WCHAR * szString);
EXTERN_C M_API LPWSTR cMStrLoW(const LPWSTR str);
EXTERN_C M_API LPWSTR MStrUpW(const LPWSTR str);
EXTERN_C M_API LPCSTR MStrUpA(const LPCSTR str);
EXTERN_C M_API LPWSTR MStrLoW(const LPWSTR str);
EXTERN_C M_API LPCSTR MStrLoA(const LPCSTR str);
EXTERN_C M_API LPWSTR MStrAddW(const LPWSTR str1, const LPWSTR str2);
EXTERN_C M_API LPCSTR MStrAddA(const LPCSTR str1, const LPCSTR str2);
//�ַ����Ƿ����
EXTERN_C M_API BOOL MStrEqualA(const LPCSTR str1, const LPCSTR str2);
//�ַ����Ƿ����
EXTERN_C M_API BOOL MStrEqualW(const wchar_t* str1, const wchar_t* str2);
EXTERN_C M_API LPCSTR MIntToStrA(int i);
EXTERN_C M_API LPWSTR MIntToStrW(int i);
EXTERN_C M_API LPCSTR MLongToStrA(long i);
EXTERN_C M_API LPWSTR MLongToStrW(long i);
EXTERN_C M_API int MStrToIntA(char * str);
EXTERN_C M_API int MStrToIntW(LPWSTR str);
EXTERN_C M_API DWORD MStrSplitA(char * str, const LPCSTR splitStr, LPCSTR * result, char ** lead);
EXTERN_C M_API DWORD MStrSplitW(LPWSTR str, const LPWSTR splitStr, LPWSTR * result, wchar_t ** lead);
EXTERN_C M_API BOOL MStrContainsA(const LPCSTR str, const LPCSTR testStr, LPCSTR * resultStr);
EXTERN_C M_API BOOL MStrContainsW(const LPWSTR str, const LPWSTR testStr, LPWSTR * resultStr);
EXTERN_C M_API BOOL MStrContainsCharA(const LPCSTR str, const CHAR testStr);
EXTERN_C M_API BOOL MStrContainsCharW(const LPWSTR str, const WCHAR testStr);
EXTERN_C M_API int MHexStrToIntW(wchar_t *s);
EXTERN_C M_API long long MHexStrToLongW(wchar_t *s);

//��ʾ NTSTATUS ����Ի���
void ThrowErrorAndErrorCodeX(NTSTATUS code, LPWSTR msg, LPWSTR title, BOOL ntstatus = TRUE);