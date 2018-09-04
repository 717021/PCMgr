#pragma once
#include "stdafx.h"

//ö��ע���ĳ��������ֵ�ص�
typedef BOOL(*ENUMKEYVALECALLBACK)(HKEY hRootKey, LPWSTR path, LPWSTR valueName, DWORD dataType, DWORD dataSize, LPWSTR dataSample, DWORD index, DWORD allCount);
//ö��ע���ĳ�������Ӽ��ص�
typedef BOOL(*ENUMKEYSCALLBACK)(HKEY hRootKey, LPWSTR path, LPWSTR childKeyName, BOOL hasChild, DWORD index, DWORD allCount);

//������ע�����
M_CAPI(BOOL) MREG_RenameKey(HKEY hRootKey, LPWSTR path, LPWSTR newName);
//ǿ��ɾ�����������ע���
M_CAPI(BOOL) MREG_ForceDeleteServiceRegkey(LPWSTR lpszDriverName);
//��ȡ�����ע����ֵ·��
//    servicName����������
//    [OUT] buf�����ע����ֵ·��
//    size��buf��������С���ַ���
M_CAPI(BOOL) MREG_GetServiceReg(LPWSTR servicName, LPWSTR buf, size_t size);
//����ת��CLSID
M_CAPI(HKEY) MREG_CLSIDToHKEY(HKEY hRootKey, LPWSTR clsid);
//����ת��CLSID����InprocServer32ֵ
M_CAPI(HKEY) MREG_CLSIDToHKEYInprocServer32(HKEY hRootKey, LPWSTR clsid);
//��ע����ֵת�ַ���
M_CAPI(LPWSTR) MREG_ROOTKEYToStr(HKEY hRootKey);
//ע���ֵ����ת�ַ���
M_CAPI(LPWSTR) MREG_RegTypeToStr(DWORD regType);
//ɾ��ע�����Լ��Ӽ�
M_CAPI(BOOL) MREG_DeleteKey(HKEY hRootKey, LPWSTR path);
//ɾ��ע������µ���ֵ
M_CAPI(BOOL) MREG_DeleteKeyValue(HKEY hRootKey, LPWSTR path, LPWSTR value);
//ö��ע���ĳ���µ�������ֵ
M_CAPI(BOOL) MREG_EnumKeyVaules(HKEY hRootKey, LPWSTR path, ENUMKEYVALECALLBACK callBack);
//ö��ע���ĳ���µ������Ӽ�
M_CAPI(BOOL) MREG_EnumKeys(HKEY hRootKey, LPWSTR path, ENUMKEYSCALLBACK callBack);

