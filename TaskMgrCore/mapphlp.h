#pragma once
#include "stdafx.h"

typedef void(__stdcall *exitcallback)();
typedef int(__stdcall *taskdialogcallback)(HWND hwnd, LPWSTR text, LPWSTR title, LPWSTR apptl, int ico, int button);
typedef void(__stdcall *EnumWinsCallBack)(HWND hWnd, HWND hWndParent);

LRESULT MAppWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void MPrintErrorMessage(LPWSTR str, int icon = MB_OK);
int MShowMessageDialog(HWND hwnd, LPWSTR text, LPWSTR title, LPWSTR apptl, int i=0, int button=0);
int MShowErrorMessage(LPWSTR text, LPWSTR intr, int ico=0, int btn=0);

EXTERN_C M_API BOOL MIsSystemSupport();
EXTERN_C M_API BOOL MLoadMainApp();
EXTERN_C M_API bool MIs64BitOS();
EXTERN_C M_API void* MAppSetCallBack(void* cp, int id);
EXTERN_C M_API void MAppExit();
EXTERN_C M_API void MAppRebot();
EXTERN_C M_API void MListDrawItem(HWND hWnd, HDC hdc, int x, int y, int w, int h, int state);
EXTERN_C M_API bool MGetPrivileges();
EXTERN_C M_API VOID MShowFileProp(LPWSTR file);
EXTERN_C M_API int MAppWorkCall3(int id, HWND hWnd, void*data);
EXTERN_C M_API HICON MGetWindowIcon(HWND hWnd);

#define MStrAdd MStrAddW
#define A2W MConvertLPCSTRToLPWSTR
#define W2A MConvertLPWSTRToLPCSTR

EXTERN_C M_API LPWSTR MConvertLPCSTRToLPWSTR(const char * szString);
EXTERN_C M_API LPCSTR MConvertLPWSTRToLPCSTR(const WCHAR * szString);
EXTERN_C M_API LPWSTR cMStrLoW(const LPWSTR str);
EXTERN_C M_API LPWSTR MStrUpW(const LPWSTR str);
EXTERN_C M_API LPCSTR MStrUpA(const LPCSTR str);
EXTERN_C M_API LPWSTR MStrLoW(const LPWSTR str);
EXTERN_C M_API LPCSTR MStrLoA(const LPCSTR str);
EXTERN_C M_API LPWSTR MStrAddW(const LPWSTR str1, const LPWSTR str2);
EXTERN_C M_API LPCSTR MStrAddA(const LPCSTR str1, const LPCSTR str2);
EXTERN_C M_API BOOL MStrEqualA(const LPCSTR str1, const LPCSTR str2);
EXTERN_C M_API BOOL MStrEqualW(const LPWSTR str1, const LPWSTR str2);
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
EXTERN_C M_API int MHexStrToIntW(wchar_t *s);
EXTERN_C M_API long long MHexStrToLongW(wchar_t *s);

void ThrowErrorAndErrorCodeX(DWORD code, LPWSTR msg, LPWSTR title);