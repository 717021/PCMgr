#pragma once
#include "stdafx.h"

//������Ϣ�ݴ�
typedef struct _SERVICE_STORAGE {
	LPWSTR                    lpServiceName;//��������
	LPENUM_SERVICE_STATUS_PROCESS lpSvc;//״̬
	WCHAR    ServiceImagePath[MAX_PATH];//��Ӧ��ӳ��·��
	BOOL  DriverServiceFounded;
	SC_HANDLE ServiceHandle;//������
	DWORD ServiceStartType;//����������Ϣ
} SERVICE_STORAGE, *LPSERVICE_STORAGE;

//ö�ٷ���ص�
typedef void(__cdecl*EnumServicesCallBack)(LPWSTR dspName, LPWSTR scName,
	DWORD scType, DWORD currentState, DWORD dwProcessId,	BOOL sysSc, DWORD dwStartType,
	LPWSTR lpBinaryPathName, LPWSTR lpLoadOrderGroup);

//���ķ������������
//    scname����������
//    type����������
//    errText����������
M_CAPI(BOOL) MSCM_ChangeScStartType(LPWSTR scname, DWORD type, LPWSTR errText);
//���ķ����״̬
//    scname����������
//    targetStatus��Ŀ��״̬��SERVICE_STOPPED/SERVICE_RUNNING/SERVICE_PAUSED��
//    targetCtl��SERVICE_CONTROL_STOP/SERVICE_CONTROL_PAUSE /SERVICE_CONTROL_CONTINUE/SERVICE_CONTROL_INTERROGATE/SERVICE_CONTROL_SHUTDOWN
//    errText����������
M_CAPI(BOOL) MSCM_ControlSc(LPWSTR scname, DWORD targetStatus, DWORD targetCtl, LPWSTR errText);

M_CAPI(void) MSCM_SetCurrSelSc(LPWSTR scname);

LRESULT MSCM_HandleWmCommand(WPARAM wParam);

//��ʼ���������Ƿ�ɹ�
//  ���ȵ��ô˺���
M_CAPI(BOOL) MSCM_Init();
//�˳��ͷ���Դ
M_CAPI(void) MSCM_Exit();

//��ȡһ����������Ӧ�ķ����飬����svchost���ص�ϵͳ������Ч
//    path�����������������
M_CAPI(LPWSTR) MSCM_GetScGroup(LPWSTR path);

//��� fileName ��Ӧ�������ǲ����ڷ�����ע��
//    fileName����Ҫ��������
//    [OUT] outName������������ƣ���������С260��
//    [OUT] pScInfo�����������Ϣ
M_CAPI(BOOL) MSCM_CheckDriverServices(LPWSTR fileName, LPWSTR outName, LPSERVICE_STORAGE*pScInfo);
//ö�������ķ���
M_CAPI(BOOL) MSCM_EnumDriverServices();
//ö������Win32����
//    callback���ص�
M_CAPI(BOOL) MEnumServices(EnumServicesCallBack callback);
//ɾ������
//    scname����������
//    errText����������
M_CAPI(BOOL) MSCM_DeleteService(LPWSTR scname, LPWSTR errText);
