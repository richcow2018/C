/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		TPBT �Î����� �̎����� (tpbt.h)										 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		�ʎގ��������̎� �̎ގ� �Ύގ؎�-�� ���ݎ� ��-�̎ގ�								 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		������������ : �����ގ� �����ގώ�											 */
/*		������������ : �Ԏώӎ� �Վ�����											 */
/*		�͎ݎ������� : ������          93/11/12  TD-00                 */
/*                (SCSI�؎��ĵ�ǽ���ѹ���ȼ���ѹ�)   TD-61             */
/*				 ���͡��층			 95/04/11	CT1039(ST2764)		 */
/*		�ѹ��� : ���桡����				 95/12/26  TD-N1			 */	
/*                (�ώƎ����ٷ����Îގ������ɲä�ȼ���ѹ�)					 */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ  �������	SSCY0199 */
/*			   �ʥХå����åפΣ�����������ͣ��б���				 */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ  �������	SPCY0146 */
/*			   �ʥХå����åפΣ������͡��ͣ��б���					 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	TPBT ���͎ގ� �̎� �� �������ގ�����											 */
/*********************************************************************/
struct	tpbtpsz {
	char	tpbttype;					/* ������ ���Վ͎ގ�				 */
	char	tpbturae;					/* ΢��PBT���ݎĎ��ֹ�	    TD@1 */
	char	tpbtyob2;					/* �֎ˎ�						 */
	char	tpbtpuno;					/* PU �ʎގݎ��ގ� 				 */
	short	tpbtvbte;					/* �̎ގ� VOL ���ݎĎ� VBT ���ݎĎ�	 */
	char	tpbtacci;					/* ACC ���ގ����Ύ�				 */
	char	tpbtyob4;					/* �֎ˎ�						 */
	char	tpbtvnam[8];				/* �̎ގ� �Ύގ؎�-�� �����͎ގ� �Ҏ�		 */
	char	tpbtfnam[32];				/* ������ �Ď����� �̎����� �Ҏ�			 */
	char	tpbttyno[8];				/* �����ʎގ� 					 */
	short	tpbtsurp;					/* �ӣգҥ���ȥ��ֹ�   TD61 */
	short	tpbtsura;					/* SUR����ȥ��ֹ�(ACC)	 	 */
										/*		CT1039				 */
	char	tpbtyob6[8];				/* �֎ˎ�						 */
	long	tpbtyob7;					/* �֎ˎ�						 */
	char	tpbtyob8[4];				/* �֎ˎ�						 */
	char	tpbtndir[16];				/* �Ȏ��Ď�-�� �Îގ��ڎ��Ď� �Ҏ�		 */
	char	tpbtdivi[64];				/* �Ύގ؎����� �̎ގݎ��� ���ގ����Ύ�		 */
	char	tpbtyob9[16];				/* ͽ��                 TD@1 */
};
typedef	struct	tpbtpsz	TPBTPSZ;

/*********************************************************************/
/*	������ �����͎ގ� ( tpbttype ) �� �Î�����									 */
/*********************************************************************/
#define		TPBTDISK	'D'				/* ����Îގ�����			TD61 */
#define		TPBTODISK	'5'				/* ���Îގ�����(5���ݎ�)		TD61 */
#define		TPBTMDISK	'3'				/* ���Îގ�����(3.5���ݎ�)	SSCY0199 */
#define		TPBTNDISK	'N'				/* �ώƎ����ٷ����Îގ�����(MD)	TDN1 */
#define		TPBT6MODISK	'6'				/* 640M MO�Îގ�����(MC)	SPCY0146 */

/*********************************************************************/
/*	ACC ���ގ����Ύ� ( tpbtacci ) �� �Î�����									 */
/*********************************************************************/
#define		TPBTACC		0x01			/* ACC �� �Îގ�����				 */
#define		TPBTNOACC	0x00			/* ACC �Ŏ� �Îގ�����				 */
