#pragma once
#include "stdafx.h"
#include <ShlObj.h>
#include <ShlGuid.h>
#include <shellapi.h>
#include <shlwapi.h>

typedef void* (__cdecl*MFCALLBACK)(int msg, void* lParam, void* wParam);

//��ʾ�ļ����ԶԻ���
//    LPWSTR file���ļ�·��
EXTERN_C M_API VOID MShowFileProp(LPWSTR file);
//�����ַ�������������
//    const WCHAR * pszData����Ҫ���Ƶ��ַ���
//    const size_t nDataLen ����Ҫ���Ƶ��ַ����ַ�����������\0��
EXTERN_C M_API BOOL MCopyToClipboard(const WCHAR * pszData, const size_t nDataLen);
//�����ַ�������������
//    const WCHAR * pszData����Ҫ���Ƶ��ַ���
EXTERN_C M_API BOOL MCopyToClipboard2(const WCHAR * pszData);

//��ȡ�ļ���չ����Ӧ��ͼ���Լ��ļ���չ��˵������
//    LPWSTR extention����չ����.txt��
//    LPWSTR s������ļ���չ��˵�������ַ���������
//    int count������ַ������������ָ���
EXTERN_C M_API HICON MFM_GetFileIcon(LPWSTR extention, LPWSTR s, int count);
//��ȡ�ļ��еĶ�Ӧͼ��
EXTERN_C M_API HICON MFM_GetFolderIcon();
//��ȡ���˵��ԡ��Ķ�Ӧͼ��
EXTERN_C M_API HICON MFM_GetMyComputerIcon();
EXTERN_C M_API void MFM_GetRoots();
EXTERN_C M_API void MFM_SetCallBack(MFCALLBACK cp);
EXTERN_C M_API BOOL MFM_GetFolders(LPWSTR path);
//����һ��exe
//    LPWSTR path���ļ�·��
//    LPWSTR cmd�����Ӳ���
//    HWND hWnd�������ߴ��ھ��
EXTERN_C M_API BOOL MFM_RunExe(LPWSTR path, LPWSTR cmd, HWND hWnd);
//��һ���ļ�
//    LPWSTR path���ļ�·��
//    HWND hWnd�������ߴ��ھ��
EXTERN_C M_API BOOL MFM_OpenFile(LPWSTR path, HWND hWnd);
EXTERN_C M_API BOOL MFM_ReUpdateFile(LPWSTR fullPath, LPWSTR dirPath);
EXTERN_C M_API BOOL MFM_UpdateFile(LPWSTR fullPath, LPWSTR dirPath);
EXTERN_C M_API BOOL MFM_GetFiles(LPWSTR path);
//��ȡ�ļ�ʹ��ʱ���Լ��Ѿ���ʽ���Ժ���ַ���
EXTERN_C M_API BOOL MFM_GetFileTime(FILETIME * ft, LPWSTR s, int count);
//��ȡ�ļ����Ը�ʽ���Ժ���ַ���
//    DWORD att����������
//    LPWSTR s������ļ���չ��˵�������ַ���������
//    int count������ַ������������ָ���
//    BOOL*hiddenout������Ƿ������ر�ʶ
EXTERN_C M_API BOOL MFM_GetFileAttr(DWORD att, LPWSTR s, int count, BOOL*hiddenout);
//���ٴ�һ���ļ�
EXTERN_C M_API BOOL MFM_OpenAFile(LPWSTR path);

//������C#����ˢ�µĻص�
EXTERN_C M_API void MFM_Refesh();
//������C#����Ļص�
EXTERN_C M_API void MFM_Recall(int id, LPWSTR path);
EXTERN_C M_API void MFM_SetStatus(LPWSTR st);
EXTERN_C M_API void MFM_SetStatus2(int st);

//���ƻ����һ���ļ���������
//    LPWSTR szFileName���ļ�·��
//    BOOL isCopy��TRUEΪ����FALSEΪ����
EXTERN_C M_API int MFM_CopyOrCutFileToClipboard(LPWSTR szFileName, BOOL isCopy);
//��֤������ַ����Ƿ��������Ч���ļ���
EXTERN_C M_API BOOL MFM_IsValidateFolderFileName(wchar_t * pName);
//����Ŀ¼
EXTERN_C M_API BOOL MFM_CreateDir(wchar_t * path);
//ɾ��һ���ļ��л������ļ�
EXTERN_C M_API BOOL MFM_DeleteDirOrFile(wchar_t * path);
//������ļ����������ļ��ĸ���
EXTERN_C M_API UINT MFM_CalcFileCount(const wchar_t * szFileDir);
//ɾ��Ŀ¼�µ������ļ����Լ��ļ�
EXTERN_C M_API BOOL MFM_DeleteDir(const wchar_t * szFileDir);
//��֤��·����һ���ļ������ļ��У����ļ����򷵻�TRUE
EXTERN_C M_API BOOL MFM_IsPathDir(const wchar_t * path);

BOOL MFM_RenameFile();
BOOL MFM_MoveFileToUser();
BOOL MFM_CopyFileToUser();
BOOL MFM_DelFileToRecBinUser();
BOOL MFM_DelFileForeverUser();
void MFF_ShowFolderProp();
void MFF_CopyPath();
void MFF_ShowInExplorer();
BOOL MFF_DelToRecBin();
BOOL MFF_DelForever();
BOOL MFF_ForceDel();
void MFF_Copy();
void MFF_Patse();
void MFF_Cut();
void MFF_Remane();
void MFF_ShowFolder();

EXTERN_C M_API LPWSTR MFM_GetSeledItemPath(int index);
EXTERN_C M_API void MFM_GetSeledItemFree(void* v);
EXTERN_C M_API BOOL MFM_GetShowHiddenFiles();

//����ļ����ļ����Ƿ����
EXTERN_C M_API BOOL MFM_FileExist(const wchar_t * path);
//����ļ����ļ����Ƿ����
EXTERN_C M_API BOOL MFM_FileExistA(const char * path);

EXTERN_C M_API void MFM_SetShowHiddenFiles(BOOL b);

//ǿ��ɾ���ļ����ļ���
EXTERN_C M_API BOOL MFM_DeleteDirOrFileForce(const wchar_t * szFileDir);
//ǿ��ɾ���ļ���
EXTERN_C M_API BOOL MFM_DeleteDirForce(const wchar_t * szFileDir);
//ǿ��ɾ���ļ�
EXTERN_C M_API BOOL MFM_DeleteFileForce(const wchar_t * szFileDir);
//�����ļ�����
//    szFileDir���ļ�·��
//    attr����Ҫ��ӽ�ȥ������
EXTERN_C M_API BOOL MFM_SetFileArrtibute(const wchar_t * szFileDir, DWORD attr);
//�Ƴ��ļ�����
//    szFileDir���ļ�·��
//    attr����Ҫ�����Ƴ�������
EXTERN_C M_API BOOL MFM_RemoveFileArrtibute(const wchar_t * szFileDir, DWORD attr);
//���ļ���� 00
//    szFile���ļ�·��
//    force���Ƿ�ǿ��
//    fileSize����Ҫ���Ĵ�С
EXTERN_C M_API BOOL MFM_FillData(const wchar_t* szFile, BOOL force, UINT fileSize);
//����ļ�
//    force���Ƿ�ǿ��
EXTERN_C M_API BOOL MFM_EmeptyFile(const wchar_t* szFile, BOOL force);
EXTERN_C M_API BOOL MFM_GetFileInformationString(const wchar_t * szFile, LPWSTR strbuf, UINT bufsize);
//���ļ���Դ����������λ�� szFile ָ����·��
EXTERN_C M_API BOOL MFM_ShowInExplorer(const wchar_t * szFile);
//��ȡ���˵��ԡ������֣���win7��ʾ�����������win10��ʾ���˵��ԡ���
EXTERN_C M_API LPWSTR MFM_GetMyComputerName();

DWORD WINAPI MFM_DeleteDirThread(LPVOID lpThreadParameter);
BOOL MFM_DeleteDirInnern(const wchar_t * szFileDir);
void MFM_ReSetShowHiddenFiles();

//�˵�����

EXTERN_C M_API int MAppWorkShowMenuFM(LPWSTR strFilePath, BOOL mutilSelect, int selectCount);
EXTERN_C M_API int MAppWorkShowMenuFMF(LPWSTR strfolderPath);



