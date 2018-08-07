/*

		Written by AlexLong

		Bug Report: 
		Email:	33445621@163.com
		MSN:	33445621@163.com

		All rights reserved
*/


#include "stdafx.h"

typedef struct  _INSTRUCTION
{
	BYTE	RepeatPrefix;	//�ظ�ָ��ǰ׺
	BYTE	SegmentPrefix;	//��ǰ׺
	BYTE	OperandPrefix;	//��������Сǰ׺0x66
	BYTE	AddressPrefix;	//��ַ��Сǰ׺0x67

	BYTE	Opcode1;		//opcode1
	BYTE	Opcode2;		//opcode2
	BYTE	Opcode3;		//opcode3
	
	BYTE	Modrm;			//modrm
	
	BYTE	SIB;			//sib
	
	union					//displacement������
	{
		BYTE	DispByte;
		WORD	DispWord;
		DWORD	DispDword;
	}Displacement;

	union					//immediate������
	{
		BYTE	ImmByte;
		WORD	ImmWord;
		DWORD	ImmDword;
	}Immediate;
	
	BYTE	InstructionBuf[32];	//����ָ�����
	DWORD	dwInstructionLen;	//����ָ���
		
}INSTRUCTION,*PINSTRUCTION;
 
#define Reserve             0x00000000
#define ModRM				0x00000001		//����ModRM
#define Imm8				0x00000002		//�������1�ֽ�������
#define Imm16				0x00000004		//�������2�ֽ�������
#define Imm66				0x00000008		//���������������Immediate�������������ȵÿ��Ƿ���0x66ǰ׺
#define Addr67				0x00000010		//�������ƫ������Displacement����ƫ�������ȵÿ��Ƿ���0x67ǰ׺
#define OneByte				0x00000020		//ֻ��1���ֽڣ���1���ֽڶ�����һ��ָ��
#define TwoOpCode0F			0x00000040		//0x0F��2��opcode
#define ThreeOpCode0F38		0x00000080		//0x0F38��3��opcode
#define ThreeOpCode0F3A		0x00000100		//0x0F3A��3��opcode
#define Group				0x00000200		//Group��opcode
#define Reserved			0x00000400		//����
#define MustHave66			0x00000800		//������0x66ǰ׺,ֻ��opcode38/3A������������ָ��
#define MustHaveF2			0x00001000		//Ŀǰֻ��һ��ָ���Ǳ�����0xF2ǰ׺�ģ�0FF0
#define MustHavePrefix		0x00002000		//������ǰ׺
#define MustNo66			0x00004000		//����û��0x66ǰ׺,��ɨ��ָ��ʱ����66��ȡ��־ָ��Ƿ��д˱�־������ֱ�ӷ���1��˵����66ǰ׺�Ƕ����
#define MustNoF2			0x00008000		//����ͬ��
#define MustNoF3			0x00010000		//����ͬ��

#define StringInstruction	0x00020000		//ָ���ظ�ǰ׺0xF2 0xF3(REPNE REP/REPE)��Opcode1����ֻ��������7���ַ���ָ����ϣ�
											// 		0xA4: 0xA5:		MOVS
											// 		0xA6: 0xA7:		CMPS
											// 		0xAE: 0xAF:		SCAS
											// 		0xAC: 0xAD:		LODS
											// 		0xAA: 0xAB:		STOS
											// 		0x6C: 0x6D:		INS
											// 		0x6E: 0x6F:		OUTS
#define Uxx					0x00040000		//rm����ѰXMM��ֻ����mod==11ʱ�ſ��Խ��룬���ܵ�opcode: 66 0F 50/C5/D7/F7	F2 OF D6
#define Nxx					0x00080000		//rm����ѰMMX��ֻ����mod==11ʱ�ſ��Խ��룬���ܵ�opcode: OF C5/D7/F7			F3 OF D6
											//Nxxû�ã���Ϊ��Uxx�����Ѿ�ȫ��������Nxx�Ŀ��� 
#define Mxx					0x00100000		//mod != 11ʱ�ſɽ���
#define Rxx					0x00200000		//mod == 11ʱ�ſɽ���

#define PreSegment			0x00400000		//��ǰ׺
#define	PreOperandSize66	0x00800000		//ָ���Сǰ׺0x66
#define PreAddressSize67	0x01000000		//��ַ��Сǰ׺0x67
#define PreLockF0			0x02000000		//��ǰ׺0xF0
#define PreRep				0x04000000		//�ظ�ǰ׺
#define Prefix				(PreSegment+PreOperandSize66+PreAddressSize67+PreLockF0+PreRep)

#define FPUOpCode			0x08000000		//FPU

//Private
void DecodeImm66(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature);
void DecodeImm8(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature);
void DecodeImm16(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature);
void DecodeModRM(IN BYTE* &pCurOpcode,OUT PINSTRUCTION &pInstruction,IN DWORD dwSignature);

//Public
int  Dissassemble(IN BYTE* pOpcode,OUT PINSTRUCTION pInstruction);









