/*

		Written by AlexLong

		Bug Report: 
		Email:	33445621@163.com
		MSN:	33445621@163.com

		All rights reserved
*/

#include "stdafx.h"
#include "Disassemble.h"

/************************************************************************/
/* 1��opcodeָ���                                                      */
/************************************************************************/
DWORD OneOpCodeMapTable[256]=
{
	/*		0			1			2			3			4							5			6			7			8				9			A			B			C			D			E			F		*/
	/*0*/	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,						Imm66,		OneByte,	OneByte,	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,		Imm66,		OneByte,	TwoOpCode0F,		
	/*1*/	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,						Imm66,		OneByte,	OneByte,	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,		Imm66,		OneByte,	OneByte,		
	/*2*/	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,						Imm66,		PreSegment,	OneByte,	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,		Imm66,		PreSegment,	OneByte,		
	/*3*/	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,						Imm66,		PreSegment,	OneByte,	ModRM,		ModRM,		ModRM,		ModRM,		Imm8,		Imm66,		PreSegment,	OneByte,		
	/*4*/	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,					OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,		
	/*5*/	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,					OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,		
	/*6*/	OneByte,	OneByte,	ModRM+Mxx,	ModRM,		PreSegment,					PreSegment,		PreOperandSize66,PreAddressSize67,Imm66,Imm66+ModRM,Imm8,	Imm8+ModRM,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,
	/*7*/	Imm8,		Imm8,		Imm8,		Imm8,		Imm8,						Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,		Imm8,
	/*8*/	Group,		Group,		Group,		Group,		ModRM,						ModRM,ModRM,ModRM,	ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM+Mxx,		ModRM,		Group,
	/*9*/	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,					OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	Imm16+Imm66,OneByte,	OneByte,	OneByte,	OneByte,	OneByte,
	/*A*/	Addr67,		Addr67,		Addr67,		Addr67,		OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	Imm8,		Imm66,		OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,	OneByte+StringInstruction,
	/*B*/	Imm8,		Imm8,		Imm8,		Imm8,		Imm8,						Imm8,		Imm8,		Imm8,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,
	/*C*/	Group,		Group,		Imm16,		OneByte,	ModRM+Mxx,					ModRM+Mxx,		Group,Group,Imm16+Imm8,OneByte,Imm16,OneByte,	OneByte,	Imm8,		OneByte,	OneByte,
	/*D*/	Group,		Group,		Group,		Group,		Imm8,						Imm8,		OneByte,	OneByte,	FPUOpCode,		FPUOpCode,		FPUOpCode,		FPUOpCode,		FPUOpCode,		FPUOpCode,		FPUOpCode,		FPUOpCode,
	/*E*/	Imm8,		Imm8,		Imm8,		Imm8,		Imm8,						Imm8,		Imm8,		Imm8,		Imm66,		Imm66,		Imm66+Imm16,Imm8,		OneByte,	OneByte,	OneByte,	OneByte,
	/*F*/	PreLockF0,	OneByte,	PreRep,		PreRep,		OneByte,					OneByte,	Group,Group,OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	Group,Group
};

/************************************************************************/
/* 2��opcodeָ���                                                      */
/************************************************************************/
DWORD TwoOpCodeMapTable[256]=
{
	/*		0			1			2			3			4			5			6			7			8				9			A			B			C			D			E			F		*/
	/*0*/	Group,Group,ModRM,		ModRM,		Reserved,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	Reserved,	OneByte,	Reserved,	ModRM,		Reserved,	Reserved,		
	/*1*/	ModRM,		ModRM,		ModRM+Mxx+Uxx,		ModRM+Mxx+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+Uxx+Mxx+MustNoF2,		ModRM+Mxx+MustNoF2+MustNoF3,		Group,Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	ModRM,		
	/*2*/	ModRM+Rxx,		ModRM+Rxx,		ModRM+Rxx,		ModRM+Rxx,		Reserved,	Reserved,	Reserved,	Reserved,	ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM,		ModRM+Mxx,		ModRM,		ModRM,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,
	/*3*/	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	OneByte,	Reserved,	Reserved,	ThreeOpCode0F38,Reserved,ThreeOpCode0F3A,ModRM,	ModRM,		ModRM,		ModRM,		ModRM,
	/*4*/	ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,
	/*5*/	ModRM+Uxx+MustNoF2+MustNoF3,	ModRM,		ModRM+MustNo66+MustNoF2,		ModRM+MustNo66+MustNoF2,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM,		ModRM,		ModRM,		ModRM+MustNoF2,		ModRM,		ModRM,		ModRM,		ModRM,
	/*6*/	ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3+MustHave66,		ModRM+MustNoF2+MustNoF3+MustHave66,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2,
	/*7*/	ModRM+Imm8,	Group,		Group,		Group,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNo66+MustNoF2+MustNoF3,ModRM+MustNo66+MustNoF2+MustNoF3,		ModRM+MustNo66+MustNoF2+MustNoF3,		Reserved,	Reserved,	ModRM+MustNoF3+MustHavePrefix,		ModRM+MustNoF3+MustHavePrefix,		ModRM+MustNoF2,		ModRM+MustNoF2,
	/*8*/	Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,		Imm66,
	/*9*/	ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,		ModRM,
	/*A*/	OneByte,	OneByte,	OneByte,	ModRM,		ModRM+Imm8,	ModRM,		Reserved,	Reserved,	OneByte,	OneByte,	OneByte,	ModRM,		ModRM+Imm8,	ModRM,		Group,ModRM,
	/*B*/	ModRM,		ModRM,		ModRM+Mxx,		ModRM,		ModRM+Mxx,		ModRM+Mxx,		ModRM,		ModRM,		Reserved+MustNo66,	Group,Group,ModRM,ModRM,		ModRM,		ModRM,		ModRM,
	/*C*/	ModRM+MustNo66+MustNoF2+MustNoF3,		ModRM+MustNo66+MustNoF2+MustNoF3,		ModRM+Imm8,	ModRM+Mxx+MustNo66+MustNoF2+MustNoF3,		ModRM+Rxx+Mxx+Imm8+MustNoF2+MustNoF3,	ModRM+Imm8+Uxx+Nxx+MustNoF2+MustNoF3,	ModRM+Imm8+MustNoF2+MustNoF3,	ModRM+Group,OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,	OneByte+MustNo66,
	/*D*/	ModRM+MustNoF3+MustHavePrefix,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustHavePrefix,		ModRM+Uxx+Nxx+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,
	/*E*/	ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustHavePrefix,		ModRM+Mxx+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,
	/*F*/	ModRM+Mxx+MustHaveF2+MustNo66+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+Uxx+Nxx+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		Reserved,
};

/************************************************************************/
/* 3��opcodeָ���A(0F 38)                                              */
/************************************************************************/
DWORD ThreeOpCodeMapTable0F38[256]=
{
	/*		0			1			2			3			4			5			6			7			8				9			A			B			C			D			E			F		*/
	/*0*/	ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	Reserved,		
	/*1*/	ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	Reserved,	ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		ModRM+MustNoF2+MustNoF3,		Reserved,		
	/*2*/	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+Mxx+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	Reserved,	
	/*3*/	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,
	/*4*/	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*5*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*6*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*7*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*8*/	ModRM+Mxx+MustHave66+MustNoF2+MustNoF3,		ModRM+Mxx+MustHave66+MustNoF2+MustNoF3,		Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*9*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*A*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*B*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*C*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*D*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,		ModRM+MustHave66+MustNoF2+MustNoF3,
	/*E*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*F*/	ModRM+Mxx+MustNoF3,	ModRM+Mxx+MustNoF3,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
};

/************************************************************************/
/* 3��opcodeָ���B(0F 3A)                                              */
/************************************************************************/
DWORD ThreeOpCodeMapTable0F3A[256]=
{
	/*		0			1			2			3			4			5			6			7			8				9			A			B			C			D			E			F		*/
	/*0*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustNoF2+MustNoF3+Imm8,
	/*1*/	Reserved,	Reserved,	Reserved,	Reserved,	ModRM+Rxx+Mxx+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+Rxx+Mxx+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*2*/	ModRM+Rxx+Mxx+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+Uxx+Mxx+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*3*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*4*/	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,		Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*5*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*6*/	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*7*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*8*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*9*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*A*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*B*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*C*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*D*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	ModRM+MustHave66+MustNoF2+MustNoF3+Imm8,
	/*E*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
	/*F*/	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,	Reserved,
};

/************************************************************************/
/* Groupָ���,��17�飬ÿ��8��                                          */
/************************************************************************/
DWORD GroupOpCodeMapTable[17][8]=
{
	/*					0				1				2				3				4				5			6				7		*/
	/*1  80-83		*/	{ModRM,			ModRM,			ModRM,			ModRM,			ModRM,			ModRM,		ModRM,			ModRM},
	/*1A 8F			*/	{ModRM,			Reserved,		Reserved,		Reserved,		Reserved,		Reserved,	Reserved,		Reserved},
	/*2  C0 C1 D0-D3*/	{ModRM,			ModRM,			ModRM,			ModRM,			ModRM,			ModRM,		ModRM,			ModRM},
	/*3  F6 F7		*/	{ModRM,			Reserved,		ModRM,			ModRM,			ModRM,			ModRM,		ModRM,			ModRM},
	/*4  FE			*/	{ModRM,			ModRM,			Reserved,		Reserved,		Reserved,		Reserved,	Reserved,		Reserved},
	/*5  FF			*/	{ModRM,			ModRM,			ModRM,			ModRM,			ModRM,			ModRM,		ModRM,			Reserved},
	/*6  0F 00		*/	{ModRM+Mxx+Rxx,	ModRM+Mxx+Rxx,	ModRM,			ModRM,			ModRM,			ModRM,		Reserved,		Reserved},
	/*7  0F 01		*/	{ModRM,			ModRM,			ModRM+Mxx,		ModRM+Mxx,		ModRM+Mxx+Rxx,	Reserved,	ModRM,			ModRM+Mxx},
	/*8  0F BA		*/	{Reserved,		Reserved,		Reserved,		Reserved,		ModRM,			ModRM,		ModRM,			ModRM},
	/*9	 0F C7		*/	{Reserved,		ModRM+Mxx,		Reserved,		Reserved,		Reserved,		Reserved,	ModRM+Mxx,		ModRM+Mxx},
	/*10 0F B9		*/	{OneByte,		OneByte,		OneByte,		OneByte,		OneByte,		OneByte,	OneByte,		OneByte},
	/*11 C6 C7		*/	{ModRM,			Reserved,		Reserved,		Reserved,		Reserved,		Reserved,	Reserved,		Reserved},
	/*12 0F 71		*/	{Reserved,		Reserved,		ModRM+Imm8+Uxx,	Reserved,		ModRM+Imm8+Uxx,	Reserved,	ModRM+Imm8+Uxx,	Reserved},
	/*13 0F 72		*/	{Reserved,		Reserved,		ModRM+Imm8+Uxx,	Reserved,		ModRM+Imm8+Uxx,	Reserved,	ModRM+Imm8+Uxx,	Reserved},
	/*14 0F 73		*/	{Reserved,		Reserved,		ModRM+Imm8+Uxx,	ModRM+Imm8+Uxx,	Reserved,		Reserved,	ModRM+Imm8+Uxx,	ModRM+Imm8+Uxx},
	/*15 0F AE		*/	{ModRM+Mxx,		ModRM+Mxx,		ModRM+Mxx,		ModRM+Mxx,		Reserved,		ModRM+Uxx,	ModRM+Uxx,		ModRM},
	/*16 0F 18		*/	{ModRM+Mxx,		ModRM+Mxx,		ModRM+Mxx,		ModRM+Mxx,		Reserved,		Reserved,	Reserved,		Reserved}
};

/************************************************************************/
/* FPUָ���,��40�飬ÿ��16��                                          */
/************************************************************************/
DWORD FpuOpCodeMapTable[5*8][16]=
{
	/*D8 ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*D8 ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
	/*D9 ModRM 00-BF*/	{ModRM,		Reserved,	ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*D9 ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{ModRM,		ModRM,		Reserved,	Reserved,	ModRM,ModRM,Reserved,Reserved,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,Reserved},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
	/*DA ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DA ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DB ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		Reserved,ModRM,Reserved,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DB ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{Reserved,	Reserved,	ModRM,		ModRM,		Reserved,Reserved,Reserved,Reserved,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DC ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DC ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
	/*DD ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,Reserved,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DD ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DE ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DE ModRM C0-FF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
	/*DF ModRM 00-BF*/	{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
	/*DF ModRM C0-FF*/	{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{Reserved,	Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved},
						{ModRM,		Reserved,	Reserved,	Reserved,	Reserved,Reserved,Reserved,Reserved,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM,ModRM},
						{ModRM,		ModRM,		ModRM,		ModRM,		ModRM,ModRM,ModRM,ModRM,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved,Reserved}
};		
		
void GetGroupSignature(IN BYTE* &pCurOpcode,IN PINSTRUCTION &pInstruction,OUT DWORD &dwSignature)
{
	BYTE modrm = *pCurOpcode;
	BYTE mod = (modrm >> 6) & 3;
	BYTE regopcode = (modrm >> 3) & 7;
	BYTE rm = modrm & 7;

	switch(pInstruction->Opcode1 == 0x0F ? *(pCurOpcode-2) : *(pCurOpcode-1))	//����pCurOpcode�Ѿ�ָ��modrm����������opcode1���Group��-1��Ϊopcode���������opcode2���е�Group��������Ҫ-2,OF XX,*(pCurOpcode-2) == 0x0F
	{
	case 0x80: case 0x82: case 0x83: case 0xC0: case 0xC1: 	//GROUP1 GROUP2,��Ϊ0xC0 0xC1��ȫ����־��GROUP1ȫ����ͬ������д�����ˡ�ʡ�ط�^_^
		dwSignature = GroupOpCodeMapTable[0][regopcode] + Imm8;
		break;
	case 0x81: 	//GROUP1
		dwSignature = GroupOpCodeMapTable[0][regopcode] + Imm66;
		break;
	case 0x8F:	//GROUP1A
		dwSignature = GroupOpCodeMapTable[1][regopcode];
		break;
	case 0xD0: case 0xD1: case 0xD2: case 0xD3:	//GROUP2
		dwSignature = GroupOpCodeMapTable[2][regopcode];
		break;
	case 0xF6:	//GROUP3
		{
			if (regopcode == 0)
			{
				dwSignature = GroupOpCodeMapTable[3][regopcode] + Imm8;
			}
			else
				dwSignature = GroupOpCodeMapTable[3][regopcode];
		}
		break;
	case 0xF7:	//GROUP3
		{
			if (regopcode == 0)
			{
				dwSignature = GroupOpCodeMapTable[3][regopcode] + Imm66;
			}
			else
				dwSignature = GroupOpCodeMapTable[3][regopcode];
		}
		break;
	case 0xFE:	//GROUP4
		dwSignature = GroupOpCodeMapTable[4][regopcode];
		break;
	case 0xFF:	//GROUP5
		dwSignature = GroupOpCodeMapTable[5][regopcode];
		break;
	case 0xC6:	////GROUP11
		dwSignature = GroupOpCodeMapTable[11][regopcode] + Imm8;
		break;
	case 0xC7:	//GROUP11
		dwSignature = GroupOpCodeMapTable[11][regopcode] + Imm66;
		break;
	case 0x0F:
		{
			switch(*(pCurOpcode-1))
			{
			case 0x00:	//GROUP6
				dwSignature = GroupOpCodeMapTable[6][regopcode];
				break;
			case 0x01:	//GROUP7
				{
					dwSignature = GroupOpCodeMapTable[7][regopcode];
					if (regopcode == 0)		//�����������Դ�
					{
						if (mod == 3)
						{
							if (rm != 1 || rm != 2 || rm != 3 || rm != 4)
							{
								dwSignature = Reserved;
							}
						}
					}
					if (regopcode == 1)
					{
						if (mod == 3)
						{
							if (rm != 0 || rm != 1)
							{
								dwSignature = Reserved;
							}
						}
					}
				}
				break;
			case 0xBA:	//GROUP8
				dwSignature = GroupOpCodeMapTable[8][regopcode];
				break;
			case 0xC7:	//GROUP9
				dwSignature = GroupOpCodeMapTable[9][regopcode];
				break;
			case 0xB9:	//GROUP10
				dwSignature = GroupOpCodeMapTable[10][regopcode];
				break;
			case 0x71:	//GROUP12
				dwSignature = GroupOpCodeMapTable[12][regopcode];
				break;
			case 0x72:	//GROUP13
				dwSignature = GroupOpCodeMapTable[13][regopcode];
				break;
			case 0x73:	//GROUP14
				dwSignature = GroupOpCodeMapTable[14][regopcode];
				break;
			case 0xAE:	//GROUP15
				dwSignature = GroupOpCodeMapTable[15][regopcode];
				break;
			case 0x18:	//GROUP16
				dwSignature = GroupOpCodeMapTable[16][regopcode];
				break;
			}
		}
		break;
	}
}

void GetFPUSignature(IN BYTE* &pCurOpcode,IN PINSTRUCTION &pInstruction,OUT DWORD &dwSignature)
{
	BYTE modrm = *pCurOpcode;
	BYTE regopcode = (modrm >> 3) & 7;
	
	int index = pInstruction->Opcode1 & 0x07;
	int col = (modrm >> 4) & 0x03;
	int row = modrm & 0x0F;
	
	if (modrm < 0xC0)
	{
	//	sprintf(strMnemonic,"%s",FpuMnemonic[5*index][regopcode]);
		dwSignature = FpuOpCodeMapTable[5*index][regopcode];
	}
	else
	{
		//sprintf(strMnemonic,"%s",FpuMnemonic[5*index + col +1][row]);
		dwSignature = FpuOpCodeMapTable[5*index + col +1][row];
	}
}

void DecodeImm66(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature)
{
	//����0x66ǰ׺ʱ
	if (pInstruction->OperandPrefix == 0x66)
	{
		pInstruction->Immediate.ImmWord = *(WORD*)pCurOpcode;
		pCurOpcode+=2;
	}
	else//������0x66ǰ׺ʱ
	{
		pInstruction->Immediate.ImmDword = *(DWORD*)pCurOpcode;
		pCurOpcode+=4;
	}
}

void DecodeImm8(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature)
{
	pInstruction->Immediate.ImmByte = *pCurOpcode++;
}

/************************************************************************/
/* ����Imm16������������ﴦ����Imm16��Imm8��Imm66�ص����              */
/************************************************************************/
void DecodeImm16(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature)
{
	//����Imm16��Imm8�ص���ʱ��
	if (dwSignature & Imm8)
	{
		pInstruction->Displacement.DispWord = *(WORD*)pCurOpcode;
		pCurOpcode+=2;
		pInstruction->Immediate.ImmByte = *pCurOpcode++;
	}
	
	//����Imm16��Imm66�ص���ʱ��
	if (dwSignature & Imm66)
	{
		if (pInstruction->OperandPrefix == 0x66)
		{
			pInstruction->Displacement.DispWord = *(WORD*)pCurOpcode;
			pCurOpcode+=2;
			pInstruction->Immediate.ImmWord = *(WORD*)pCurOpcode;
			pCurOpcode+=2;
		}
		else
		{
			pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
			pCurOpcode+=4;
			pInstruction->Immediate.ImmWord = *(WORD*)pCurOpcode;
			pCurOpcode+=2;
		}
	}
	else //�������κα�־�ص���ʱ��
	{
		pInstruction->Immediate.ImmWord = *(WORD*)pCurOpcode;
		pCurOpcode+=2;
	}
}

/************************************************************************/
/* ����ModRM������������ﴦ����ModRM��Imm8��Imm66�ص����              */
/************************************************************************/
void DecodeModRM(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature)
{
	BYTE modrm = *pCurOpcode++;
	BYTE mod = modrm & 0xC0;
	BYTE regopcode = modrm & 0x38;
	BYTE rm = modrm & 0x07;
	pInstruction->Modrm = modrm;

	//���2λ����11
	if (mod !=0xC0)
	{
		//��0x67ǰ׺
		if (pInstruction->AddressPrefix == 0x67)	//����0x67����32λת��16λ����ѯ16λModRM��
		{
			//mod == 00
			if (mod == 0x00)
			{
				if (rm == 0x06)
				{
					pInstruction->Displacement.DispWord = *(WORD*)pCurOpcode;
					pCurOpcode+=2;
				}
			}
			
			//mod == 01
			if (mod == 0x40)
			{
				pInstruction->Displacement.DispByte = *pCurOpcode++;
			}
			
			//mod ==10
			if (mod == 0x80)
			{
				pInstruction->Displacement.DispWord = *(WORD*)pCurOpcode;
				pCurOpcode+=2;
			}
		}
		else	//û��0x67ǰ׺,��ѯ32λModRM��
		{
			//mod == 00
			if (mod == 0x00)
			{
				if (rm == 0x04)
				{
					pInstruction->SIB = *pCurOpcode++;
					//����SIB.Base=101ʱ�����
					if ((pInstruction->SIB & 0x07) == 0x05)
					{
						pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
						pCurOpcode+=4;
					}
				}
				if (rm == 0x05)
				{
					pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
					pCurOpcode+=4;
				}
			}

			//mod == 01
			if (mod == 0x40)
			{
				if (rm == 0x04)
				{
					pInstruction->SIB = *pCurOpcode++;
					pInstruction->Displacement.DispByte = *pCurOpcode++;
				}
				else
				{
					pInstruction->Displacement.DispByte = *pCurOpcode++;
				}
			}

			//mod ==10
			if (mod == 0x80)
			{
				if (rm == 0x04)
				{
					pInstruction->SIB = *pCurOpcode++;
					pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
					pCurOpcode+=4;
				}
				else
				{
					pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
					pCurOpcode+=4;
				}
			}
		}
	}
	//����ModRM��Imm8�ص���ʱ��
	if (dwSignature & Imm8)
	{
		pInstruction->Immediate.ImmByte = *pCurOpcode++;
	}
	//����ModRM��Imm66�ص���ʱ��
	if (dwSignature & Imm66)
	{
		//����0x66ǰ׺ʱ
		if (pInstruction->OperandPrefix == 0x66)
		{
			pInstruction->Immediate.ImmWord = *(WORD*)pCurOpcode;
			pCurOpcode+=2;
		}
		else//������0x66ǰ׺ʱ
		{
			pInstruction->Immediate.ImmDword = *(DWORD*)pCurOpcode;
			pCurOpcode+=4;
		}
	}
}

int Dissassemble(IN BYTE* pOpcode,OUT PINSTRUCTION pInstruction)//,OUT char *pstrInstruction)
{
	BYTE* pCurOpcode = pOpcode;
	DWORD dwflag = 0;

	memset(pInstruction,0,sizeof(INSTRUCTION));//���ṹ�������Ϊ0������Ӱ������ָ��Ľ���
/************************************************************************/
/*����ǰ׺ָ��                                                          */
/************************************************************************/
_CheckPrefix:
	BYTE opcode = *pCurOpcode++;
	DWORD dwSignature = OneOpCodeMapTable[opcode];	//ȡopcode1���еı�־

	if (dwSignature & Prefix)
	{
		//�����ظ�ͬ��ǰ׺
		if (dwflag & dwSignature)
		{
			pInstruction->dwInstructionLen = 1;	
			return 1;	//����ָ���Ϊ1��ֻ����һ��ǰ׺ָ��
		}
		//�����־
		dwflag |= dwSignature;
		if (dwSignature & PreSegment)
		{
			pInstruction->SegmentPrefix = opcode;
		}
		if (dwSignature & PreOperandSize66)
		{
			pInstruction->OperandPrefix = opcode;
		}
		if (dwSignature & PreAddressSize67)
		{
			pInstruction->AddressPrefix = opcode;
		}
		if (dwSignature & PreLockF0)
		{
			pInstruction->RepeatPrefix = opcode;
		}
		if (dwSignature & PreRep)
		{
			pInstruction->RepeatPrefix = opcode;
		}

		goto _CheckPrefix;
	}

	//����opcode,ͬʱҲ������OneByte��1�ֽ�opcode�����
	pInstruction->Opcode1 = opcode;

/************************************************************************/
/* ������ȡopcode2 opcode38/3A Group FPU��ı�־��opcode1���־������ȡ���� */
/************************************************************************/

	if (dwSignature & TwoOpCode0F)	//ȡopcode2 opcode38/3A ����
	{
		//����opcode1��opcode2��Ҳ�Ǵ�����OneByte���
		pInstruction->Opcode1 = opcode;
		pInstruction->Opcode2 = *pCurOpcode++;
		dwSignature = TwoOpCodeMapTable[pInstruction->Opcode2];
		
		if (dwSignature & ThreeOpCode0F38)	//ȡopcode38���еı��
		{
			pInstruction->Opcode3 = *pCurOpcode++;
			dwSignature = ThreeOpCodeMapTable0F38[pInstruction->Opcode3];
		}

		if (dwSignature & ThreeOpCode0F3A)	//ȡopcode3A���еı��
		{
			pInstruction->Opcode3 = *pCurOpcode++;
			dwSignature = ThreeOpCodeMapTable0F3A[pInstruction->Opcode3];
		}
	}

	if (dwSignature & Group)	//ȡopcode1 opcode2���е�Group�ı��
	{
		GetGroupSignature(pCurOpcode,pInstruction,dwSignature);
	}

	if (dwSignature & FPUOpCode)	//ȡFPU���еı�־
	{
		GetFPUSignature(pCurOpcode,pInstruction,dwSignature);
	}
	//����Ƚ������ָ��0xD6(��0xF3ǰ׺ʱmod����Ϊ11) 0xF0(��ǰ׺��ǰ׺Ϊ0x66ʱ��Mxx��־��ǰ׺ΪF2��66 F2 ʱ����Mxx��־
	if (pInstruction->RepeatPrefix == 0xF3 && pInstruction->Opcode2 == 0xD6)
	{
		dwSignature += Uxx;
	}
	if (pInstruction->RepeatPrefix == 0xF2 && (pInstruction->Opcode3 == 0xF0 || pInstruction->Opcode3 == 0xF1))
	{
		dwSignature -= Mxx;
	}

//���¿�ʼ����ȡ���ı��
/************************************************************************/
/* ����Imm16������������ﴦ����Imm16��Imm8��Imm66�ص����              */
/************************************************************************/

	if (dwSignature & Imm16)	//0x66��0x67ǰ׺��Ӱ��ָ��ȣ������Ƿ���ڶ�ȡһ��WORD������
	{
		DecodeImm16(pCurOpcode,pInstruction,dwSignature);
	}


/************************************************************************/
/* ����Addr67�����                                                     */
/************************************************************************/

	if (dwSignature & Addr67)//ֻ��0x67Ӱ��ָ���
	{
		if (pInstruction->AddressPrefix == 0x67)
		{
			pInstruction->Displacement.DispWord = *(WORD*)pCurOpcode;
			pCurOpcode+=2;
		}
		else
		{
			pInstruction->Displacement.DispDword = *(DWORD*)pCurOpcode;
			pCurOpcode+=4;
		}
	}

/************************************************************************/
/* ����ModRM������������ﴦ����ModRM��Imm8��Imm66�ص����              */
/************************************************************************/
	
	if (dwSignature & ModRM)
	{
		DecodeModRM(pCurOpcode,pInstruction,dwSignature);
	}

/************************************************************************/
/* ����Imm8�����                                                       */
/************************************************************************/

	if (dwSignature & Imm8)//0x66��0x67ǰ׺��Ӱ��ָ��ȣ�����0x66��0x67ǰ׺�Ƿ���ڣ�ָ���ȡһ��byte������
	{
		if (dwSignature & ModRM || dwSignature & Imm16)
		{//Imm8��Imm16�ص�������Ѿ���DecodeImm16���洦���ˣ���ModRM�ص��Ѿ�DecodeModRM�д���
		}
		else
		{
			DecodeImm8(pCurOpcode,pInstruction,dwSignature);
		}
	}

/************************************************************************/
/*����Imm66�����                                                       */
/************************************************************************/

	if (dwSignature & Imm66)//ֻ��0x66Ӱ��ָ���
	{
		if (dwSignature & ModRM || dwSignature & Imm16)
		{//Imm66��Imm16�ص�������Ѿ���DecodeImm16���洦���ˣ���ModRM�ص��Ѿ�DecodeModRM�д���
		}
		else
		{
			DecodeImm66(pCurOpcode,pInstruction,dwSignature);
		}
	}

/************************************************************************/
/* ����MustHave66��־                                                   */
/************************************************************************/

	if (dwSignature & MustHave66)	//opcode38/3A�����кܶ������0x66ǰ׺��ָ��
	{
		if (pInstruction->OperandPrefix != 0x66)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����MustHaveF2��־		                                            */
/************************************************************************/

	if (dwSignature & MustHaveF2)	//��opcode2������һ��������F2��ָ���opcode2���е�F0
	{
		if (pInstruction->RepeatPrefix != 0xF2)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����MustHavePrefix��־		                                        */
/************************************************************************/
	
	if (dwSignature & MustHavePrefix)	//��opcode2������һ��������F2��ָ���opcode2���е�F0
	{
		if (pInstruction->RepeatPrefix == 0 && pInstruction->OperandPrefix == 0)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����MustNo66��־                                                     */
/************************************************************************/

	if (dwSignature & MustNo66)	//������0x66ǰ׺��ָ��
	{
		if (pInstruction->OperandPrefix == 0x66)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����MustNoF2��־                                                     */
/************************************************************************/

	if (dwSignature & MustNoF2)	//������0xF2ǰ׺��ָ��
	{
		if (pInstruction->RepeatPrefix == 0xF2)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����MustNoF3��־                                                     */
/************************************************************************/
	
	if (dwSignature & MustNoF3)	//������0xF3ǰ׺��ָ��
	{
		if (pInstruction->RepeatPrefix == 0xF3)
		{
			pInstruction->dwInstructionLen = 1;
			return 1;
		}
	}

/************************************************************************/
/* ����StringMnemonic��־                                               */
/************************************************************************/
	
	if (!(dwSignature & StringInstruction) && pInstruction->Opcode1 != 0x0F)	//���û��StringInstruction���
	{
		if (pInstruction->RepeatPrefix > 0)	//�����ǰ׺ָ��0xF2��0xF3
		{
			pInstruction->dwInstructionLen = 1;
			return 1;	
		}
	}

/************************************************************************/
/* ����Reservedָ�һ�ɷ���1                                          */
/************************************************************************/

	if (dwSignature & Reserved)
	{
		pInstruction->dwInstructionLen = 1;
		return 1;
	}
	
/************************************************************************/
/* ����Uxx��־                                                          */
/************************************************************************/

	if (dwSignature & Uxx)
	{
		BYTE modrm = pInstruction->Modrm;
		BYTE mod = (modrm >> 6) & 3;
		if (!(dwSignature & Mxx))	//���Uxx��Mxxû���ص�����ֻ��Uxx��־�Ļ�������mod == 11
		{
			if (mod != 3)	//mod != 11
			{
				pInstruction->dwInstructionLen = 1;
				return 1;
			}
		}
	}

/************************************************************************/
/* ����Rxx��־                                                          */
/************************************************************************/
	
	if (dwSignature & Rxx)		//Rxxʵ�����ú�Uxx��һ���ģ���������д��һ����־��URNxx
	{
		BYTE modrm = pInstruction->Modrm;
		BYTE mod = (modrm >> 6) & 3;
		if (!(dwSignature & Mxx))	//���Rxx��Mxxû���ص�����ֻ��Rxx��־�Ļ�������mod == 11
		{
			if (mod != 3)	//mod != 11
			{
				pInstruction->dwInstructionLen = 1;
				return 1;
			}
		}
	}

/************************************************************************/
/* ����Mxx��־                                                          */
/************************************************************************/
	
	if (dwSignature & Mxx)
	{
		BYTE modrm = pInstruction->Modrm;
		BYTE mod = (modrm >> 6) & 3;
		if (!(dwSignature & Uxx || dwSignature & Rxx))	//���Mxx��Uxx��Rxxû���ص�����ֻ��Mxx��־�Ļ�������mod != 11
		{
			if (mod == 3)	//mod == 11
			{
				pInstruction->dwInstructionLen = 1;
				return 1;
			}
		}
	}

	//����ָ���
	pInstruction->dwInstructionLen = (DWORD)(pCurOpcode-pOpcode);
	//��ָ���һ�ݴ���pInstruction->InstructionBuf
	memcpy(pInstruction->InstructionBuf,pOpcode,pInstruction->dwInstructionLen);

	return (int)(pCurOpcode-pOpcode);	//����ָ���
}


