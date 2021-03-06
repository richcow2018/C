/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		�ξ��������ե����� (mre.h)								 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		�؎��ʎގ� ��������													 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		�������� ���� : �ώ����ގ� ������											 */
/*		�������� ���� : �ώ����ގ� ������							 				 */
/*		�͎ݎ��� ���� : �Ԏώӎ� �Վ�����				'88/05/10 (L01)				 */
/*				  (�Ύގ؎�-�� �͎����� ���Ɏ� ���� �� �ĎӎŎ� �͎ݎ���) --- STC911		 */
/*		�͎ݎ��� ���� : �����ގ� ������ 				'89/04/15 (L02)				 */
/*				  (SCSI �ʎގ� �؎����� ������ ���� �� �ĎӎŎ� �͎ݎ���) --- TC2466	 */
/*      �ѹ���  : ����������             93/11/12  TD-00             */
/*                 (¾TCư��ƻ��ȼ���ѹ�)        TD-01             */
/*                 (�Ύގ؎�-���ĺ����κ����ȼ���ѹ�)  TD-47             */
/*                 (SCSI�؎��ĵ�ǽ���ѹ���ȼ���ѹ�)  TD-61             */
/*                 (JNL��RBI�ν����Ƴ����ȼ���ѹ�)TD-79             */
/*		�ѹ���  : ���桡����			 95/03/28	  CT0977(ST2646) */
/*				  ��2�Ÿξ�������ص�ǽ�ɲä�ȼ���ѹ�				 */ 
/*					�����ѹ��׵�� SSCYXXXX��						 */
/*      �ѹ���  : ����������             95/07/19 --- CT1096(ST2997) */
/*                 (VRCV�ΎЎ׎��Ύގ؎�������������н�)					 */
/*      �ѹ���  : ����  ����             96/02/26 --- CT1213(ST4078) */
/*                 (MREUMNTERR���)				 					 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*		�Ҏ�-���� �������ݎӎ� ���ݎ��� �����͎ގ�									 */
/*********************************************************************/
#define	MREREJRQ	0x01			/* ���ގ�-�Ŏ� �����Ď� ���׎� (mr_ejrq)	 */
#define	MRERESRQ	0x02			/* TRADE�ξ�����   (mr_esrq)TD00 */
#define MREREARQ    0x03            /* JNL��RBI���ذ���(mr_earq)TD79 */

/*********************************************************************/
/*		�֎ˎގ��ގ� �̎� �̎׎��� �ώ��� 											 */
/*********************************************************************/
									/* ���פʽ����κ����ȼ�����   */
									/* (2��)                    TD00 */

/*********************************************************************/
/*		�ξ�����̎ߎێ��� �����ؿ����ֵ���                          TD-00*/
/*********************************************************************/
#define	MRENORMAL	0L				/* �������ގ��� �������؎���		   (L01) */
#define	MRENORMX	1L				/* ���ގ������� �� �������ގ��� �������؎��� (L01) */
#define	MRERCVVH    2L				/* RCV�Ύގ؎������ĺ�		 CTO671  */
#define	MREONVRCV	3L				/* VRCV��				 CT1096  */
#define MRERBIMSG   9L              /* RBI��λ������ʸ       CT0977	 */
#define MREEJCMSG   10L             /* JNL���������ذ�����ʸ CT0977	 */
#define MREJRCMSG   11L             /* JNL��RBI���ذ�����ʸ     TD79 */
#define MREERRMSG   12L             /* JNL2�Ÿξ����ΰ�����ʸ   TD02 */
#define MRECISMSG   13L             /* ���ؾ����׵���ʸ         TD79 */
#define MREMRIMSG   14L             /* �̎ߎێ�����λ������ʸ        TD79 */
#define	MREJNLMSG	17L				/* ���ގ�-�Ŏ� �����Ď� ������ �Îގݎ̎ގ�  (L01) */
#define	MREROSMSG	18L				/* TRADE�ξ�������ʸ        TD00 */
									/* �Ύގ؎�-���ĺ����κ����ȼ�����  */
									/* (1��)                    TD47 */
#define	MREOBRMSG	20L				/* ������ �͎����� ���׎� �Îގݎ̎ގ�     (L01) */
#define	MREOBFMSG	21L				/* ������ �͎����� ���ݎ؎��� �Îގݎ̎ގ�   (L01) */
#define	MREOSTMSG	22L				/* ������ ������ ���� �Îގݎ̎ގ� 	   (L01) */
#define	MRETRMMSG	23L				/* �̎ߎێ��� �������؎��� ���׎� �Îގݎ̎ގ� (L01) */
									/* SCSI�؎��ĵ�ǽ���ѹ���ȼ�����  */
									/* (2��)                    TD61 */
#define	MREOTHBLK	33L				/* ���ގ��� �͎����� �Ў��ݎ؎��� ���ގ������� (L01) */
#define	MREOWNBLK	34L				/* ������ �͎����� �Ў��ݎ؎��� ���ގ�������  (L01) */
#define	MRENOTBLK	35L				/* �͎����� �Ў��ݎ؎��� ���ގ�������	   (L01) */
#define	MREFINBLK	36L				/* �͎����� ���ݎ؎��� ���ގ�������	   (L01) */
#define	MREERROR	-1L				/* �����ގ���  �������؎��� ���ގ�������    (L01) */
#define	MRENOMEM	-2L				/* �Ҏӎ� �̎ގ���				   (L01) */
#define	MREALREADY	-3L				/* ���Îގ� �Ď��ێ� ���ގ�		   (L01) */
#define	MRERTRYOV	-4L				/* �͎����� �ώ� �؎Ď׎� ��-�ʎ�-	   (L01) */
#define	MRENOEXST	-5L				/* �� ���ݎ��ގ� ����-			   (L01) */
#define	MREOTHDWN	-6L				/* ������ ���ގ��� ������			   (L01) */
#define MREOTHCHG   -7L             /* ���ѷ������             TD01 */
/*	����ʣ��ԡ�											CT1213	 */
#define	MREECONN	-9L             /* ���Ȏ��ļ���				CT0977   */
#define	MREEOPEN	-10L            /* �����̎ߎݼ���			CT0977   */
#define	MREEWRIT	-11L            /* �񤭹��߼���			CT0977   */
#define	MREEFLSH	-12L            /* �ٱ�Îގ����񤭹��߼���	CT0977   */

/*********************************************************************/
/*		�ξ�����̎ߎێ��� ����̎ގێ���								    TD-00*/
/*********************************************************************/
struct	mrecb {						/*						   (L01) */
	char	mrecbid[4];				/* �̎ގێ��� �����͎ގ�('ECB ')	   (L01) */
									/* �Ύގ؎�-���ĺ����κ����ȼ�����  */
									/* (4��)                    TD47 */
	long	mremsrd;				/* �Ҏ����������ю؎������ļ��̻�			 */
	char	*mremsad;				/* ���ގ����� �Ҏ���-���� ���Ďގڎ�	   (L01) */
	long	mremsln;				/* ���ގ����� �Ҏ���-���� ������ 	   (L01) */
									/* SCSI�؎��ĵ�ǽ���ѹ���ȼ�����  */
									/* (1��)                    TD61 */
    unsigned	char	mrejrif;   	/* �������̎׎���             TD79 */
	char	mreyob1[3];				/* ͽ��						TD79 */
	long	mresdtj1;				/* ���JNL���SMP����1    CT0977 */
	long	mresdtj2;				/* ���JNL���SMP����2    CT0977 */
	long	mresdtk1;				/* ���JNL���SMP����1	  CT0977 */
	long	mresdtk2;				/* ���JNL���SMP����2    CT0977 */
};															/* (L01) */
typedef	struct	mrecb	MRECB;								/* (L01) */

/*******************************/
/* �������̎׎���(mrejrif)����� */
/*******************************/
#define MREINTJNL   0x80          	/* JNL�������              TD79 */
#define MREINTRBI   0x40          	/* RBI�������              TD79 */
#define MREINTKJ    0x20          	/* KJ�������               TD79 */
#define MRENOINT    0x00            /* ��������               TD79 */
