#pragma once
#include "stdafx.h"

//��ȡBOOL����
M_CAPI(BOOL) M_CFG_GetConfigBOOL(LPWSTR configkey, LPWSTR configSection, BOOL defaultValue);
//д��BOOL����
M_CAPI(BOOL) M_CFG_SetConfigBOOL(LPWSTR configkey, LPWSTR configSection, BOOL value);
