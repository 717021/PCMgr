#pragma once
#include "stdafx.h"

//ǿ��ɾ�����������ע���
M_CAPI(BOOL) MREG_ForceDeleteServiceRegkey(LPWSTR lpszDriverName);
//��ȡ�����ע����ֵ·��
M_CAPI(BOOL) MREG_GetServiceReg(LPWSTR servicName, LPWSTR buf, size_t size);
//����ת��CLSID
M_CAPI(HKEY) MREG_CLSIDToHKEY(HKEY hRootKey, LPWSTR clsid);
//����ת��CLSID����InprocServer32ֵ
M_CAPI(HKEY) MREG_CLSIDToHKEYInprocServer32(HKEY hRootKey, LPWSTR clsid);
//��ע����ֵת�ַ���
M_CAPI(LPWSTR) MREG_ROOTKEYToStr(HKEY hRootKey);
//ɾ��ע�����Լ��Ӽ�
M_CAPI(BOOL) MREG_DeleteKey(HKEY hRootKey, LPWSTR path);
//ɾ��ע������µ���ֵ
M_CAPI(BOOL) MREG_DeleteKeyValue(HKEY hRootKey, LPWSTR path, LPWSTR value);
