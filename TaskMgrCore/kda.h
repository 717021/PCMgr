#pragma once
#include "stdafx.h"

//��������棨���ڿ�Դ capstone ��������棩
//    buf��ԭʼ����
//    startaddress����ʼ��ַ������ʵ�Ļ����ϵĵ�ַ��
//    callback���ص���DACALLBACK��
//    size��ԭʼ�����С
//    x86Orx64��TRUEΪx86 FALSEΪx64 
M_CAPI(BOOL) M_KDA_Dec(PUCHAR buf, ULONG_PTR startaddress, LPVOID callback, ULONG_PTR size, BOOL x86Orx64);

//����൱ǰ���루���ڿ�Դ capstone ��������棩
//    buf��ԭʼ����
//    startaddress����ʼ��ַ������ʵ�Ļ����ϵĵ�ַ��
//    size��ԭʼ�����С
//    outstr��std::wstring** , �����������ַ�����������Ҫdelete
M_CAPI(BOOL) M_KDA_DeAssemblier(PUCHAR buf, ULONG_PTR startaddress, ULONG_PTR size, LPVOID outstr);