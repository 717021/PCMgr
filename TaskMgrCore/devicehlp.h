#pragma once
#include "stdafx.h"


//���������Ϣ
struct MDevicePhysicalDisk
{
	WCHAR Name[64];
	WCHAR Model[64];
	UINT64 Size;
	UINT32 Index;
	WCHAR SizeStr[64];
};
//�ڴ���Ϣ
struct MDeviceMemory
{
	WCHAR Name[64];
	UINT16 FormatFactor;
	WCHAR DeviceLocator[32];
	UINT64 Size;
	UINT32 Speed;
	UINT32 SMBIOSMemoryType;
	UINT64 Capacity;
};
//������Ϣ
struct MDeviceNetworkAdapter
{
	WCHAR Description[64];
	WCHAR IPAddressV4[32];
	WCHAR IPAddressV6[64];
	UINT16 StatusInfo;
	BOOL PhysicalAdapter;
	BOOL Enabled;
};

//��ʼ��
M_CAPI(BOOL) MDEVICE_Init();
//�ͷ�
M_CAPI(void) MDEVICE_UnInit();

//��ȡ������Ϣ��ʹ���������� MDEVICE_DestroyLogicalDiskInfo �ͷ�
M_CAPI(BOOL) MDEVICE_GetLogicalDiskInfo();
//�ͷŴ�����Ϣ
M_CAPI(BOOL) MDEVICE_DestroyLogicalDiskInfo();
//��ȡ��ǰ���м�������
M_CAPI(UINT) MDEVICE_GetLogicalDiskInfoSize();
//��ȡ������Ϣ
//    index���������
//    [OUT] nameBuffer���������ƣ�64��
//    [OUT] modelBuffer�������ͺţ�64��
//    [OUT] outIndex���������
//    [OUT] outSize�����̴�С
//    [OUT] sizeBuffer����С�ַ�����outSize���ܲ�׼����64��
M_CAPI(BOOL) MDEVICE_GetLogicalDiskInfoItem(int index, LPWSTR nameBuffer, LPWSTR modelBuffer, UINT*outIndex, UINT64*outSize, LPWSTR sizeBuffer);
//�̷�תΪ����������
M_CAPI(DWORD) MDEVICE_GetPhysicalDriveFromPartitionLetter(CHAR letter);
//��ȡ�Ƿ���ϵͳ����
//    perfStr��c:
M_CAPI(BOOL) MDEVICE_GetIsSystemDisk(LPCSTR perfStr);

