#pragma once
#include "stdafx.h"
#include "reghlp.h"

//ö�ٿ���������ص�
typedef void(__cdecl*EnumStartupsCallBack)(
	LPWSTR dspName, //��������������
	LPWSTR type, //�������
	LPWSTR path, //��ִ���ļ�·��
	HKEY regrootpath, //��ע���
	LPWSTR regpath,//ע���·��
	LPWSTR regvalue//ע���·����Ӧ��ֵ����
	);

//ö�ٿ���������
//    callBack���ص�
M_CAPI(VOID) MEnumStartups(EnumStartupsCallBack callBack);

LRESULT MSM_HandleWmCommand(WPARAM wParam);
