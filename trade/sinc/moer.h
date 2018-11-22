/****************************************************************************/
/* 		��¤�Τ���� (ROS����ΰ۾�������)									*/
/****************************************************************************/
#include "mochar.h"
struct motgmsg {                        /* ROS����ΰ۾�����				*/
	UCHR mopuid;                        /* PU�ֹ�							*/
	UCHR mocode;                        /* ��ʬ�ॳ����						*/
	short modetal;                      /* �ܺپ���							*/
	long mofactr;                       /* ��λ������						*/
	long mozisho1;						/* ���Υ�����1						*/
	long mozisho2;						/* ���Υ�����2						*/
};
typedef struct motgmsg MOTGMSG;

/****************************************************************************/
/* 		���̼���		define												*/
/****************************************************************************/

#define		MOOBSTAC	(UCHR)0xC0		/* �㳲����							*/
#define		MOPHENOM	(UCHR)0xD0		/* ��������							*/

/****************************************************************************/
/* 		��ʬ�ॳ����	define												*/
/****************************************************************************/

/*	�㳲����																*/
#define		MOOPROBS	(UCHR)0x01		/* ��������ǽ�㳲					*/
#define		MOPUEROR	(UCHR)0x02		/* Pu�㳲					CT0541	*/
#define		MOCLDEND	(UCHR)0x03		/* �ҥץ����۾ｪλ				*/
#define		MOPUBLOC	(UCHR)0x04		/* Pu�ĺ�							*/
#define		MOIOOBST	(UCHR)0x05		/* I/O�㳲����						*/
#define		MOLINOBS	(UCHR)0x06		/* �����㳲����						*/
#define		MONVMOBS	(UCHR)0x08		/* NVM�㳲							*/
#define		MOLM2OBS	(UCHR)0x09		/* LM2�ӥåȾ㳲					*/
#define		MOCIOINS	(UCHR)0x0A		/* ���ޥ�ɤˤ��I/Oͽ�ĺɻؼ�		*/
#define		MOCIOCNL	(UCHR)0x0B		/* ���ޥ�ɤˤ��I/O�ĺɲ��		*/
										/* ��λ����							*/
#define		MOCIOCMP	(UCHR)0x0C		/* ���ޥ�ɤˤ��I/O�����ĺ�		*/
										/* ��λ����							*/
#define		MOIOCNCL	(UCHR)0x0D		/* I/O�ĺɲ����λ����				*/
#define		MOIOBLOC	(UCHR)0x0E		/* I/O�ĺɴ�λ����					*/
#define		MOCLNINS	(UCHR)0x0F		/* ���ޥ�ɤˤ�����ͽ�ĺɻؼ�		*/
#define		MOCLNCNL	(UCHR)0x10		/* ���ޥ�ɤˤ������ĺɲ��		*/
										/* ��λ����							*/
#define		MOCLNCMP	(UCHR)0x11		/* ���ޥ�ɤˤ����������ĺ�		*/
										/* ��λ����							*/
#define		MOLNCNCL	(UCHR)0x12		/* �����ĺɲ����λ����				*/
#define		MOLNBLOC	(UCHR)0x13		/* �����ĺɴ�λ����					*/
#define		MOBTRALM	(UCHR)0x14		/* �Хåƥ꡼���顼��				*/
#define		MOCMDINT	(UCHR)0x15		/* ���ޥ�ɥ⡼�ɽ�λ������		*/
#define		MOCIOECN	(UCHR)0x16		/* ���ޥ�ɤˤ��I/O�ĺɴ�λ����	*/
#define		MOCLNECN	(UCHR)0x17		/* ���ޥ�ɤˤ������ĺ�			*/
										/* ��λ����							*/
#define		MOFANALM	(UCHR)0x1A		/* FAN���顼��ȯ��					*/
#define		MOUPSNOR	(UCHR)0x1B		/* UPS���ž���̤����				*/
#define		MORQPOFF	(UCHR)0x1C		/* �ѥ�����׵�					*/
#define		MOOBTERM	(UCHR)0x1D		/* �㳲����ü�Ҽ���					*/
#define		MOSTTSMP	(UCHR)0x20		/* ���Ͻ������SMP����				*/

