#include "kmodul.h"

extern wcscpy_s_ _wcscpy_s;
extern wcscat_s_ _wcscat_s;

NTSTATUS KxUnLoadDrvObjectByDrvObject(ULONG_PTR pDrvObject)
{
	NTSTATUS status = STATUS_UNSUCCESSFUL;


	return status;
}
NTSTATUS KxGetDrvObjectByName(wchar_t *pszDrvName, ULONG_PTR* pDrvObject)
{
	NTSTATUS status = STATUS_SUCCESS;
	UNICODE_STRING uniObjName, uniFileDev;

	wchar_t dev[256] = { 0 };
	wchar_t sym[256] = { 0 };
	wchar_t fileDev[256] = { 0 };
	wchar_t fileSym[256] = { 0 };
	//��������
	PDRIVER_OBJECT pDrvObj = NULL;

	//����ָ������
	*pDrvObject = 0;

	//�ǿ���תUnicode������
	if (pszDrvName[0] != '\0')
	{
		_wcscpy_s(dev, 256, L"\\Driver\\");
		// "\Driver\xxx.sys"
		_wcscat_s(dev, 256, pszDrvName);

		_wcscpy_s(fileDev, 256, L"\\FileSystem\\");
		//"\FileSystem\xxx.sys"
		_wcscat_s(fileDev, 256, pszDrvName);

		//ȥ����׺��(��ȥ��4���ַ���"\Driver\xxx")
		RtlMoveMemory(sym, dev, (wcslen(dev) - 4) * sizeof(wchar_t));
		//ȥ����׺��(��ȥ��4���ַ���"\FileSystem\xxx")
		RtlMoveMemory(fileSym, fileDev, (wcslen(dev) - 4) * sizeof(wchar_t));

		RtlInitUnicodeString(&uniObjName, sym);
		RtlInitUnicodeString(&uniFileDev, fileSym);
	}

	//��ʼ��objectAttributes
	OBJECT_ATTRIBUTES objectAttributes;
	InitializeObjectAttributes(&objectAttributes, &uniObjName, OBJ_CASE_INSENSITIVE, NULL, NULL);

	HANDLE hDevice;
	IO_STATUS_BLOCK status_block;
	//�趨��FILE_SYNCHRONOUS_IO_NONALERT����FILE_SYNCHRONOUS_IO_ALERTΪͬ�����豸
	status = ZwCreateFile(&hDevice,
		FILE_READ_ATTRIBUTES | SYNCHRONIZE,
		&objectAttributes,
		&status_block,
		NULL, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ,
		FILE_OPEN_IF, FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0);

	if (NT_SUCCESS(status)) {
		status = ObReferenceObjectByHandle(hDevice, FILE_ALL_ACCESS, *IoDriverObjectType, KernelMode, (PVOID *)&pDrvObj, NULL);
		ZwClose(hDevice);
	}
	else
	{
		KdPrint(("ZwCreateFile (\"\\Driver\\%ws\") Failed! Status: 0x%x\n", uniObjName.Buffer, status));
		//���ö���ͨ������("\Driver\xxx")
		status = ObReferenceObjectByName(&uniObjName, OBJ_CASE_INSENSITIVE, NULL, FILE_ALL_ACCESS, *IoDriverObjectType, KernelMode, NULL, (PVOID *)&pDrvObj);
		if (!NT_SUCCESS(status))
		{
			//���ö���ͨ������("\FileSystem\xxx")
			status = ObReferenceObjectByName(&uniFileDev, OBJ_CASE_INSENSITIVE, NULL, FILE_ALL_ACCESS, *IoDriverObjectType, KernelMode, NULL, (PVOID *)&pDrvObj);
			if (!NT_SUCCESS(status))
			{
				KdPrint(("ObReferenceObjectByName(\"\\FileSystem\\xxx\") Failed! Status: ������:%ws \t 0x%x\n", uniObjName.Buffer, status));
				return status;
			}
		}
	}
	
	//KdPrint(("������:%ws \t ��������:0x%08X\n", uniObjName.Buffer, pDrvObj));
	*pDrvObject = (ULONG_PTR)pDrvObj;
	//�����������
	ObDereferenceObject(pDrvObj);
	return status;
}


