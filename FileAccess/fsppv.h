#pragma once
#ifdef FILEACCESS_USER
#include <Windows.h>

typedef struct _CLIENT_ID
{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

#else
#include "..\FileAccessKrnl\driver.h"
#endif

//�ļ��б�������
typedef enum MFS_PROTECT_TYPE{
	PROTECT_TYPE_DIR_ONLY,//����Ŀ¼
    PROTECT_TYPE_DIR_AND_CHILD_DIR,//������Ŀ¼�Լ�����Ŀ¼
	PROTECT_TYPE_DIR_ALL,//������Ŀ¼�Լ�����Ŀ¼�Լ��������ļ�
};
//�����ȼ�
typedef enum MFS_PROTECT_LEVEL {
	PROTECT_LEVEL_NOACCESS,//�ܾ�����
	PROTECT_LEVEL_ONLY_READ,//ֻ��
	PROTECT_LEVEL_ASK_FOR_PERMIT,//������ɣ��ɹ���ᱣ�����
	PROTECT_LEVEL_ONLY_LOG,//��¼
};
//�����������
typedef enum MFS_PERMIT_TYPE {
	PERMIT_REQUEST_AS_USER,//���û��������
	PERMIT_REQUEST_FOR_APPLICATION,//��Ӧ�ý������
	PERMIT_REQUEST_EVERY_TIME,//ÿ�ζ�Ҫ����
};

typedef struct tag_MFS_THREAD
{
	struct tag_MFS_THREAD*GlNext;
	struct tag_MFS_THREAD*GlPrv;
	struct tag_MFS_THREAD*Next;
	struct tag_MFS_THREAD*Prv;

	CLIENT_ID ThreadId;
}MFS_THREAD,*PMFS_THREAD;
//��������
typedef struct tag_MFS_APP_TOKEN 
{
	struct tag_MFS_APP_TOKEN*Next;
	struct tag_MFS_APP_TOKEN*Prv;

	WCHAR Path[260];//·��
	PMFS_THREAD Threads;//�߳��ݴ�

}MFS_APP_TOKEN,*PMFS_APP_TOKEN;

//����
typedef struct tag_MFS_PROTECT
{
	struct tag_MFS_PROTECT*Next;
	struct tag_MFS_PROTECT*Prv;

	BOOLEAN IsDirectory;
	WCHAR Path[260];//·��
	MFS_PROTECT_TYPE ProtectType;//�ļ��б�������
	MFS_PROTECT_LEVEL ProtectLevel = PROTECT_LEVEL_ASK_FOR_PERMIT;//�����ȼ�	
	MFS_PERMIT_TYPE PermitRequsetType;//�����������

	BOOLEAN AllowedUser;//�û��Ƿ����
	PMFS_APP_TOKEN AllowedApplication;//��ɵĳ���

}MFS_PROTECT,*PMFS_PROTECT;