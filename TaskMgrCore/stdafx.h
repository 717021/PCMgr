// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>



#define M_API __declspec(dllexport)
#define M_CAPI(x) extern "C" M_API x

#define DEFDIALOGGTITLE L"PC Manager"


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
