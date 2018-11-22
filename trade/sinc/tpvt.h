/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		TPVT �Î����� �̎����� (tpvt.h)										 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		�̎ގ� �Ύގ؎�-�� ���ݎ� ��-�̎ގ�										 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		������������ : �����ގ� �����ގώ�											 */
/*		������������ : �Ԏώӎ� �Վ�����											 */
/*		�͎ݎ������� : �Ԏώӎ� �Վ����� (L01)									 */
/*				 (�Ύގ؎�-�� �͎����� ������ ���� �� �ĎӎŎ� �͎ݎ���) --- STC911		 */
/*		�͎ݎ������� : �����ގ� ������ 				'89/04/17 (L02)				 */
/*				 (SCSI �ʎގ� �؎����� ������ ���� �� �ĎӎŎ� �͎ݎ���) --- TC2466		 */
/*      �ѹ��� : ������              93/11/12  TD-00             */
/*                (¾TCư��ƻ��ȼ���ѹ�)         TD-01             */
/*                (�ΎĎ����ݎʎގ��ѹ���ȼ���ѹ�)        TD-02             */
/*                (SCSI�؎��ĵ�ǽ���ѹ���ȼ���ѹ�)   TD-61             */
/*                (�Ύގ؎�-���ĺ�ñ���ѹ���ȼ���ѹ�)   TD-90             */
/*				 ���͡��층				 95/04/11  CT1039(ST2764)	 */
/*		�ѹ��� : ����  ����				 95/11/??	ST3684			 */
/*		�ѹ��� : ���桡����				 95/12/26  TD-N1			 */	
/*                (�ώƎ����ٷ����Îގ������ɲä�ȼ���ѹ�)					 */
/*																	 */
/*		�ѹ��� : ���桡����				 95/02/15  ST3754			 */	
/*                (ST3684�ĺɎ��Î������κ��)					 		 */
/*		�ѹ��� : ���ơ���				 99/03/31  SPCY0146			 */	
/*                (640M MO�ɲä�ȼ���ѹ�)							 */
/*********************************************************************/

/*********************************************************************/
/*	TPVT ���͎ގ� �̎� �� �������ގ�����											 */
/*********************************************************************/
struct	tpvtpsz {
	char	tpvttype;					/* ������ ���Վ͎ގ�				 */
	unsigned char tpvtvsta;				/* �Ύގ؎�-�� ����-����				 */
	char	tpvtyob3;					/* ͽ����	ST3684	ST3754	 */
	char	tpvtpuno;					/* PU �ʎގݎ��ގ�				 */
	short	tpvtvmte;					/* �̎ގ� VOL ���ݎĎ� VMT ���ݎĎ�	 */
	char	tpvtacci;					/* ACC ���ގ����Ύ�				 */
                                        /* �Ύގ؎�-���ĺ�ñ�̤��ѹ���ȼ��*/
										/* ���(1��)            TD90 */
	char	tpvtyob1;					/* ͽ����				TD@1 */
	char	tpvtvnam[8];				/* �̎ގ� �Ύގ؎�-�� �����͎ގ� �Ҏ�		 */
	char	tpvtfnam[32];				/* ������ �Ď����� �̎����� �Ҏ�			 */
	char	tpvttyno[8];				/* �����ʎގ� 					 */
                                        /* �Ύގ؎�-���ĺ�ñ�̤��ѹ���ȼ��*/
										/* ���(4��)            TD90 */
										/* SCSI�؎��ĵ�ǽ���ѹ���ȼ��  */
										/* ���(2��)            TD61 */
	short	tpvtsura;					/* SUR����ȥ��ֹ�(ACC) 	 */
										/*			CT1039			 */
    short   tpvtsurp;                   /* �ӣգҥ���ȥ��ֹ�   TD61 */
    short   tpvtsurp2;                  /* �ӣգҥ���ȥ��ֹ棲		 */
										/*			CT1039			 */
	short	tpvtyob2;					/* ͽ��						 */
	char	tpvtndb1[16];				/* �ȎĎ�-���Îގ��ڎ��Ď�̾(¾��1)    */
										/*                      TD02 */
	char	tpvtndir[16];				/* �Ȏ��Ď�-�� �Îގ��ڎ��Ď� �Ҏ�		 */
	char	tpvtdivi[64];				/* �Ύގ؎����� �̎ގݎ��� ���ގ����Ύ�		 */
	char    tpvtndb2[16];               /* �ȎĎ�-���Îގ��ڎ��Ď�̾(¾��2)    */
										/*                      TD02 */
};
typedef	struct	tpvtpsz	TPVTPSZ;

/*********************************************************************/
/*	������ �����͎ގ� ( tpvttype ) �� �Î�����									 */
/*********************************************************************/
#define		TPVTDISK	'D'				/* �Ύގ؎Վ��ю��Վ͎ގ� ���Î� �Îގ�����	 */
#define		TPVTMDISK	'3'				/* 3.5���ݎ����Îގ�����		TD61 */
#define		TPVTODISK	'5'				/* 5���ݎ����Îގ�����			TD61 */
#define		TPVTMT		'M'				/* �Ύގ؎Վ��ю��Վ͎ގ� ���ގ� �Î��̎�		 */
#define		TPVTFDISK	'F'				/* �Ύގ؎Վ��ю��Վ͎ގ� �̎ێ��ˎߎ� �Îގ�����  */
#define		TPVTNDISK	'N'				/* �ώƎ����ٷ����Îގ�����(MD)	TDN1 */ 
#define		TPVT6MODISK	'6'				/* 640M MO�Îގ�����(MC)	SPCY0146 */ 

/*********************************************************************/
/*	�Ύގ؎�-�� ����-���� ( tpvtvsta ) �� �Î�����								 */
/*********************************************************************/
#define		TPVTVERR	0x80			/* �Ύގ؎����ю��Î����� ���������ގ�������	 */
#define		TPVTVRCV	0x40			/* �Ύގ؎����ю��Î����� �؎��ʎގ� ������	 */
#define		TPVTVVJG	0x10			/* �Ύގ؎����ю��Î����� VJ �����Ď� ���ގ� 	 */

/* ����ʣ��ԡ�												ST3754	 */

/*********************************************************************/
/*	ACC ���ގ����Ύ� ( tpvtacci ) �� �Î�����									 */
/*********************************************************************/
#define		TPVTACC		0x01			/* ACC �� �Îގ�����				 */
#define		TPVTNOACC	0x00			/* ACC �Ŏ� �Îގ�����				 */

/*********************************************************************/
/*	���ێ���-�� �Ύގ؎�-�� ���ގ����Ύ� ( tpvtcros ) �� �Î����޺��(2��)           TD90 */
/*********************************************************************/

/*********************************************************************/
/*	�͎����� ����-���� ( tpvtheis ) �� �Î����޺��(2��)                     TD90 */
/*********************************************************************/

/*********************************************************************/
/*	������ ������ �ʎ����� �ˎ������� ( tpvttout ) �� �Î����޺��(1��)             TD61 */
/*********************************************************************/