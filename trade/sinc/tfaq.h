/********************************************************************/
/*																	*/
/* tfaq.h  94.09.16	�ٻ��� ������									*/
/*																	*/
/*																	*/
/********************************************************************/

struct mdfaqsb {
	short	 tfaqinen;					/* ͽ��					 JJ	*/
	char	 tfaqricp;					/* ͽ��					 JJ	*/
	char	 tfaqyob0[5];				/* �֎ˎ� 0					*/
};
typedef	struct mdfaqsb TFAQSUB;			/* FIP �֎�					*/

struct mdfaqko {
	char	tfaqkbst;				/*	���͎ގ̎� ���Î�����			*/
	char	tfaqyob1;				/*	�֎ˎ�	1					*/
	short	tfaqfacn;				/*	TFAC ���ݎĎ� NO			*/
	short	tfaqlptn;				/*	TLPT ���ݎĎ� NO			*/
	char	tfaqiokd;				/*	���ݎώ� �����͎ގ�				*/
	char	tfaqyob2;				/*	�֎ˎ�	2					*/
	short	tfaqdvno;				/*	������	�ʎގݎ��ގ�				*/
	short	tfaqphno;				/*	�ێݎ�	�ʎߎ�	�ʎގݎ��ގ�			*/
	char	tfaqsoft;				/*	���̎�	���ʎގ�				*/
	char	tfaqprfx;				/*	�̎ߎڎ̎�����					*/
/* *** 87.12.7 *** STC550 *** */
	char	tfaqfiln[22];			/*	�Ď����� �̎����� �Ҏ�			*/
	long	tfaqfdsc;				/*	�̎����� �Îގ������؎̎ߎ�			*/
	char	tfaqflst;				/*	�̎����� ���Î�����				*/
	char	tfaqlpws;				/*	�����ݎĎގ� ��������				*/
	char	tfaqyob3[14];			/*	�֎ˎ�	3					*/
};
typedef	struct mdfaqko TFAQPSZ;			/* FIP �֎�					*/
