#pragma once
#include "stdafx.h"

//�����ļ��Ի���
//    hWnd��������
//    startDir����ʼĿ¼
//    title���Ի������
//    fileFilter���ļ�ɸѡ�������磺�ı��ļ�\0*.txt\0�����ļ�\0*.*\0
//    fileName��Ĭ���ļ�����
//    defExt��Ĭ���ļ���չ��
//    [OUT] strrs�����ѡ����ļ��ַ���������
//    bufsize��ѡ����ļ��ַ����������ַ�������
M_CAPI(BOOL) M_DLG_SaveFileSingal(HWND hWnd, LPWSTR startDir, LPWSTR title, LPWSTR fileFilter, LPWSTR fileName, LPWSTR defExt, LPWSTR  strrs, size_t bufsize);

//ѡ���ļ��Ի���
//    hWnd��������
//    startDir����ʼĿ¼
//    title���Ի������
//    fileFilter���ļ�ɸѡ�������磺�ı��ļ�\0*.txt\0�����ļ�\0*.*\0
//    fileName��Ĭ���ļ�����
//    defExt��Ĭ���ļ���չ��
//    [OUT] strrs�����ѡ����ļ��ַ���������
//    bufsize��ѡ����ļ��ַ����������ַ�������
M_CAPI(BOOL) M_DLG_ChooseFileSingal(HWND hWnd, LPWSTR startDir, LPWSTR title, LPWSTR fileFilter, LPWSTR fileName, LPWSTR defExt, LPWSTR strrs, size_t bufsize);
//ѡ���ļ��жԻ���
//    hWnd��������
//    startDir����ʼĿ¼
//    title���Ի������
//    [OUT] strrs�����ѡ���Ŀ¼�ַ���������
//    bufsize��ѡ���Ŀ¼�ַ����������ַ�������
M_CAPI(BOOL) M_DLG_ChooseDir(HWND hWnd, LPWSTR startDir, LPWSTR title, LPWSTR strrs, size_t bufsize);