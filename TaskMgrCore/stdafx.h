// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>

#define M_API __declspec(dllexport)
#define M_CAPI(x) extern "C" M_API x

#define DEFDIALOGGTITLE L"PC Manager"
#define ENDTASKASKTEXT L"���ĳ���򿪵ĳ�����˽��̹��������رմ˳����ҽ���ʧ����δ��������ݡ��������ĳ��ϵͳ���̣�����ܵ���ϵͳ���ȶ�����ȷ��Ҫ������ ?"

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
