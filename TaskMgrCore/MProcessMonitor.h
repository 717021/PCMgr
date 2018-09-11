#pragma once
#include "stdafx.h"
#include "prochlp.h"
#include <list>
#include <vector>
#include "MProcessPerformanctMonitor.h"

//��Ч����ɾ���ص�
typedef void(*ProcessMonitorRemoveItemCallBack)(DWORD pid);
//�½�����ӻص�
typedef void(*ProcessMonitorNewItemCallBack)(DWORD pid, DWORD parentid, LPWSTR exename, LPWSTR exefullpath, HANDLE hProcess, PMPROCESS_ITEM processItem);
//ˢ��û�еĽ��̻ص�
//    ���أ����� FALSE ���� NewItemCallBack
typedef BOOL(*ProcessMonitorUpdateNotIncludeItemCallBack)(DWORD pid);

//���̼�����
class M_API MProcessMonitor
{	
protected:
	MProcessMonitor();
public:
	virtual ~MProcessMonitor();

	//ö�����н���
	virtual bool EnumAllProcess() { return false; };
	//ˢ�½���
	virtual bool RefeshAllProcess() { return false; };
	//ˢ��δ���ڵĽ���
	virtual bool RefeshAllProcessNotInclude() { return false; };

	//Static fun

	//���� ProcessMonitor ���벻Ҫֱ��ʹ�� new MProcessMonitor����ʹ�ô˷������� MProcessMonitor
	//    removeItemCallBack��ɾ����Ч���̻ص�
	//    newItemCallBack���½��̳��ֻص�
	//    updateNotIncludeItemCallBack����ѡ��RefeshAllProcessNotIncludeʹ�ô˻ص�
	static MProcessMonitor *CreateProcessMonitor(ProcessMonitorRemoveItemCallBack removeItemCallBack, ProcessMonitorNewItemCallBack newItemCallBack, ProcessMonitorUpdateNotIncludeItemCallBack updateNotIncludeItemCallBack);
	//ɾ�� ProcessMonitor������ʹ�� CreateProcessMonitor ���ص� MProcessMonitor ��ʹ�ô˷����ͷ�
	static void DestroyProcessMonitor(MProcessMonitor *monitor);
	
	static BOOL EnumAllProcess(MProcessMonitor *monitor);
	static BOOL RefeshAllProcess(MProcessMonitor *monitor);
	static BOOL RefeshAllProcessNotInclude(MProcessMonitor *monitor);
};

typedef struct tag_PID_ITEM {

}PID_ITEM,*PPID_ITEM;
typedef struct tag_STG_PID_ITEM {
	DWORD Pid;
	struct tag_STG_PID_ITEM*Next;
}STG_PID_ITEM, *PSTG_PID_ITEM;

//���̼����� Internal
class MProcessMonitorCore : public MProcessMonitor
{
public:
	MProcessMonitorCore(ProcessMonitorRemoveItemCallBack removeItemCallBack, ProcessMonitorNewItemCallBack newItemCallBack, ProcessMonitorUpdateNotIncludeItemCallBack updateNotIncludeItemCallBack);
	~MProcessMonitorCore();

	//ö�����н���
	bool EnumAllProcess() override;
	//ˢ�½���
	bool RefeshAllProcess() override;
	//ˢ��δ���ڵĽ���
	bool RefeshAllProcessNotInclude() override;
private:
	//�ͷŽ�������
	void FreeProcessBuffer();
	//�����ЧPID
	void ClearVaildPids();

	//ˢ����ЧPID
	void RefreshVaildPids();
	//ˢ�½�������
	bool RefreshProcessBuffer();
	//ˢ�����н�����Ŀ
	void RefreshAllProcessItem();

	void AddValidPid(DWORD pid);
	void RemoveValidPid(DWORD pid);

	//��Ч��PID
	STG_PID_ITEM validPids = { 0 };
	PSTG_PID_ITEM validPidsEnd;
	//���н�����Ŀ
	PSYSTEM_PROCESSES* processesStorage = NULL;
	DWORD processCount = 0;

	PSYSTEM_PROCESSES FindProcess(DWORD pid);
	//������н�����Ŀ
	VOID FreeAllProcessItems();

	MPROCESS_ITEM allProcessItems = { 0 };
	PMPROCESS_ITEM allProcessItemsEnd = NULL;

	CRITICAL_SECTION cs;

	//�ص�
	ProcessMonitorRemoveItemCallBack RemoveItemCallBack;
	ProcessMonitorNewItemCallBack NewItemCallBack;
	ProcessMonitorUpdateNotIncludeItemCallBack UpdateNotIncludeItemCallBack;

	PSYSTEM_PROCESSES currentProcessBuffer = NULL;
};