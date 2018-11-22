/**************************** NTC-SMP-RCV ****************************/
/*																 	 */
/*	1 �̎����َҎ�														 */
/*		�Ҏ��������� �͎����ގ� �؎֎� ���� ���� �Î�����(mrmuse.h)						 */
/*																 	 */
/*	2 ���̎ގ�															 */
/*		RCV ��������													 */
/*																 	 */
/*	3 �؎ڎ�														 	 */
/*		�������� ���� : �������� ���ݎ���											 */
/*		�������� ���� : �������� ���ݎ���						 					 */
/*		�͎ݎ��� ���� : �Ԏώӎ� �Վ�����				'87/10/01 (L01)				 */
/*				  (�������� �؎��ʎގ� ���ݎڎ� ���Ɏ� �� �������ގ�) --- STC395			 */
/*		�͎ݎ��� ���� : �ώ��� ��������				'87/12/24 (L02)				 */
/*				  (���������ގ� ���� ������ �̎ߎێ��� ���Ɏ� ����)	--- STC559			 */
/*		�͎ݎ��� ���� : �Ԏώӎ� �Վ�����				'88/03/23 (L03)				 */
/*				  (�Ύގ؎�-�� �͎����� ���Ɏ� ���� �� �ĎӎŎ� �͎ݎ���) --- STC911		 */
/*      �͎ݎ��� ���� : �������� �Վ�����             '88/07/29 (L04)				 */
/*                (RBI �ю����� ���Ɏ� ����)			    --- TC1229       */
/*		�͎ݎ�������  : �����ގ� ������				'89/02/10 (L05)				 */
/*				  (�Ύގ؎����� ���������ގ� ���ގ����Ύ� ���� ���Ɏ� ����) --- TC2368		 */
/*		�͎ݎ��� ���� : �����ގ� ������ 				'89/04/15 (L06)				 */
/*				  (SCSI �ʎގ� �؎����� ������ ���� �� �ĎӎŎ� �͎ݎ���) --- TC2466	 */
/*		�͎ݎ������� : �����ގ� ������			 	'89/11/02 (L07)				 */
/*			 	  (���������ގ� �Ύގ؎����� ���׎������͎ގ� ���� ���Ɏ� �� ���� --- TCXXXX	 */
/*      �ѹ��� : ����������              93/11/12  TD-00             */
/*                (¾TCư��ƻ��ȼ���ѹ�)         TD-01             */
/*                (�Ύގ؎�-���ĺ����κ����ȼ���ѹ�)   TD-47             */
/*                (SCSI�؎��ĵ�ǽ���ѹ���ȼ���ѹ�)   TD-61             */
/*                (SRCV���Ի������ȼ���ѹ�)       TD-78             */
/*                (JNL��RBI�ν������ȼ���ѹ�)     TD-79             */
/*                (KJñ�Ȏʎގ����̎ߤ�ȼ���ѹ�)       TD-83             */
/*                (�Ύގ؎�-���ĺ�ñ���ѹ���ȼ���ѹ�)   TD-90             */
/*      �ѹ��� : ���ܡ�����              94/11/07  M06               */
/*      (�ξ�Ύގ؎�-�ю��׎��������Τؤθξ������Ύގ؎����Ѽ���̾�ɲ�			)*/
/*      (�ξ����ɼ ST1248											)*/
/*		�ѹ��� : ����  ����				 95/ 2/ 6 					 */
/*                (mr_efcl�����ȼ������			ST1550)			 */
/*		�ѹ��� : ���ġ�Ʃ				 95/ 3/ 2 --- CT0894(ST2490) */
/*				  (�Ў׎�Ʊ���ݾڵ�ǽ�ɲä�ȼ������)  TD-22	 		 */
/*		�ѹ��� : ���桡����				 95/ 3/28 					 */
/*				  (2�Ÿξ�������ص�ǽ�ɲä�ȼ������			 	 */
/*				  �����ѹ��׵�� SSCYXXXX ��		  CT0977(ST2646) */
/*		�ѹ��� : ����  ����				 95/04/18 --- ST1766/ST1767  */
/*                (���ݎ�-�̎�-����-�Ď�1�ڤ�2���ɲ�)						 */
/*		�ѹ��� : ���桡����				 95/04/21 --- CT0990(ST2652) */
/*				  (���ݎ����̎����������Ď�2���ɲ�)								 */
/*		�ѹ��� : ���͡��층				 95/05/16 --- CT1039(ST2764) */
/*      �ѹ��� : ���ܡ�����              95/05/18 --- ST2703 		 */
/*           ( �ξ�ܥ�塼�२�顼�������Τ�I/F�����Ď�2�ɲ�			)*/
/*           ( �ܥ�塼���ĺɽ��������I/F�����Ď�2�ѹ�					)*/
/*		�ѹ��� : ����  ����				 95/06/28 --- ST2895		 */
/*		�ѹ��� : ���͡��층				 95/08/16 --- CT1106(ST3142) */
/*		�ѹ��� : ���桡����				 95/12/11 					 */
/*				  (�̾���VRCV�ю��ݎ����̎����������Ď�2���ɲ�)   TD-90			 */
/*�㥽����������̾��				 Com'App ����		 			 */
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ�������	ST4008	 */
/*									 (���ִ��̿��ѥХ��ꥻ�åȵ�ǽ)	 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*�ץ���������̾	:												 */
/*�ץ�����̾		:���Хץ�����									 */
/*��¤�ֹ�			:PRC-005-09										 */
/*��¤����			:�Х���ȿž�б�									 */
/*��¤��			:2002.11.06										 */
/*��¤��			:supply watanabe								 */
/*********************************************************************/

/*********************************************************************/
/*		�Ҏ��������� �͎����ގ� �������̎ގ� �����͎ގ�									 */
/*********************************************************************/
#define     MRMKOWN     0x00        /* ���ϼ��̻�               TD01 */
#define		MRMKTU		0x01		/* ���ѷϼ��̻�             TD01 */
#define		MRMKSH		0x02		/* ͽ���ϼ��̻�             TD01 */

/*********************************************************************/
/*		�Ҏ��������� �����͎ގ�												 */
/*********************************************************************/
#define		MRMK1		0x03		/* �ӎ��ώ܎� �Ҏ���������					 */
#define		MRMK2		0x0D		/* �؎��ʎގ� �Ҏ���������					 */

/*********************************************************************/
/*		�Îގ��� �����Ɏ����� �����͎ގ�											 */
/*********************************************************************/
#define		MRMDUSBF	0x01		/* �؎֎��������ގ� �� �������ގ����� �ʎގ��̎�		 */

/*********************************************************************/
/*		�Îގ��� �����͎ގ�													 */
/*********************************************************************/
#define		MRMDSGLM	0x10		/* ���ݎ��� �Îގݎ̎ގ�					 */

/*********************************************************************/
/*		�������� �̎؎܎� �����̎�												 */
/*********************************************************************/
#define		MRMKPRO		0x01		/* �̎ߎێ��� �����͎ގҎ� �� �֎� �̎؎܎�		 */

/*********************************************************************/
/*		�Ҏ��������� �͎����ގ� �؎֎��������� RCV �������� �̎�-�ώ���						 */
/*********************************************************************/
struct	mrmuse	{
/*********************************************************************/
/*	PRC-005-09  ���� START 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/
	long	mrmumk34;				/* ���ݎ��̎����������Ď�					 */	/* PRC-005-09 */
/*********************************************************************/
/*	PRC-005-09  ���� END 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/
	char	mrmudis;				/* ���� ���̎ގ�						 */
	char	mrmucod;				/* ���� �����Ď�						 */
	short	mrmuent;				/* ���ݎĎ��ֹ�						 */
};
typedef	struct	mrmuse	MRMUSE;
/*********************************************************************/
/*	PRC-005-09  ���� START 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/
union mrmumk_u	{														/* PRC-005-09 */
	long mrmumk_l;														/* PRC-005-09 */
	struct{																/* PRC-005-09 */
			short			mrmumk3;									/* PRC-005-09 */
			short			mrmumk4;									/* PRC-005-09 */
	} mrmumk_s;															/* PRC-005-09 */
};																		/* PRC-005-09 */
typedef	union	mrmumk_u	MRMUMK34_U;									/* PRC-005-09 */
/*********************************************************************/
/*	PRC-005-09  ���� END 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/

/*********************************************************************/
/*	���󥿡��ե����������ɣ�								    TD01 */
/*********************************************************************/
#define		MRMSMSG		0x1000		/* �ώ������������ގ����� ���� �� �Îގݎ̎ގ�(OCP)	 */
#define		MRMUISRCV	0x2000		/* �����Î� �؎��ʎގ�					 */
#define		MRMUIVRCV	0x2010		/* �Ύގ؎����� �؎��ʎގ�                  */
#define		MRMUIBKUP	0x2020		/* �ʎގ��� �����̎�                     */
#define		MRMUIRBI	0x2030		/* RBI �����Ď�			             */
#define		MRMUIAVRCV	0x2040		/* VRCV������		             */
#define		MRMUISERP	0x2050		/* ���̎޸ξ�����̎ߎێ���				 */
#define		MRMUIMIRR	0x2060		/* �ߥ顼���Ʊ���ݾ�	CT0894	 */
#define		MRMUIRMAN	0x2070		/* �ξ����                 TD01 */
#define		MRMUIJNL	0x2080		/* ���ގ����Ŏ� �����Ď�	                 */
#define		MRMUIERRP	0x2090		/* �ξ�����̎ߎێ���            TD01 */
#define		MRMUICERR	0x2326		/* mr_cerr		ST1766/ST1767    */
#define		MRMUICSMP	0x2327		/*	mr_csmp		CT1039			 */

/*********************************************************************/
/*	���󥿡��ե����������ɣ�                                    TD01 */
/*********************************************************************/
#define		MRTRMPR		0x0600		/* �̎ߎێ��� �������؎��� ���׎� �Îގݎ̎ގ�(OCP)	 */
#define		MRMUICRERR	0x1000		/* RBI��Ÿξ�			ST1766   */
#define		MRMUIJEND	0x1000		/* JNL�Ǝ����ݎĎ�			ST1767   */
#define		MRMUIKJEND	0x1001		/* KJ�Ǝ����ݎĎ�				ST1767   */
#define		MRMUIEFCL	0x0000 		/* �Ύގ؎�-���ĺɽ�������	ST2703   */
#define		MRMUIFALT	0x0001 		/* �ξ�Ύގ؎�-�ю��׎��������� ST2703  */
#define		MRMUIJRIC	0x0002		/* JNL��RBI�������λ����CT0990   */
#define		MRMUISRA1	0x0003		/*	�����ӣͣ����Σ�	CT1039	 */
#define		MRMUISRA2	0x0004		/*	�����ӣͣ����Σ�	CT1039	 */
#define		MRMUISRA3	0x0005		/*	�����ӣͣ����Σ�	CT1106	 */
#define		MRMUISRA4	0x0006		/*	�����ӣͣ����Σ�	ST4008	 */
#define		MRMUIRMS1	0x0001		/*	�ξ�Ύގ؎����Ѳ�������		TD90 */
									/*  �������Ύގ؎����Ѿ���̵����	TD00 */
#define		MRMUIIMS1	0x0002		/*	�Ύގ؎����������������		TD90 */
									/*  �������Ύގ؎����Ѿ���̵����	TD00 */
#define		MRMUIRMS2	0x0003		/*	�ξ�Ύގ؎����Ѳ�������		TD90 */
									/*  �������Ύގ؎����Ѿ���ͭ��	TD00 */
#define		MRMUIIMS2	0x0004		/*	�Ύގ؎����������������		TD90 */
									/*  �������Ύގ؎����Ѿ���ͭ���	TD00 */

/*********************************************************************/
/*	���� ���̎ގ� �Î�����													 */
/*********************************************************************/
#define		MRMUDASK	0x00		/* ���׎� ����						 */
#define		MRMUDCOM	0x01		/* ���ݎ؎��� ����					 */
#define		MRMUDSTA	0x02		/* ������ ����						 */
#define		MRMUDEND	0x03		/* �������؎��� ����					 */
#define		MRMUDTRV	0x04		/* �������� ����						 */
#define		MRMUDREV	0x05		/* �����̎� ����						 */

/*********************************************************************/
/*	���� �����Ď� �Î�����(���׎� ����)											 */
/*********************************************************************/
#define		MRMUARBGET	0x00		/* RBI ���������� �����Ď� ���׎�			 */
#define		MRMUARBSTA	0x01		/* RBI �Î��������� �����Ď� ������ ���׎�		 */
#define		MRMUARBSTP	0X02		/* RBI �Î��������� �����Ď� �������؎��� ���׎�	 */
#define		MRMUARBEND	0X03		/* RBI �����Ď� �������؎��� ���׎�			 */
#define		MRMUAACC6A	0x04		/* ACC#6 �����Ď� ���׎�				 */
#define		MRMUAACC6R	0x05		/* ACC#6 �����Ď� �����Ύ� ���׎�			 */
#define		MRMUACROS	0x06		/* ���ێ� ��-�� �Ύގ؎�-�� �͎�����	   (L03) */
#define		MRMUAJNL	0x07		/* ���ގ�-�Ŏ� �����Ď� ���׎�		   (L03) */
#define		MRMUAROS	0x08		/* TRADE�ξ����ΰ���        TD00 */
#define		MRMUARBINV  0X09		/* RBI �ю����� ������ ���׎�        (L04) */
#define		MRMUAPVHR   0X0A		/* RBI �ю����� ������ ���׎�        (L04) */
#define		MRMUAPVNR   0X0B		/* RBI �ю����� ������ ���׎�        (L04) */
									/* SCSI�؎��ĵ�ǽ���ѹ���ȼ�����  */
									/* (2��)                    TD61 */
#define		MRMUMRCV	0x0C		/* �Ў׎��Ύގ؎������������	CT0894	 */
#define     MRMUAJRC    0X11        /* JNL��RBI���������       TD79 */

/*********************************************************************/
/*	���� �����Ď� �Î�����(���ݎ؎��� ����)										 */
/*********************************************************************/
#define		MRMUCRBNOM	0x00		/* RBI ���׎� �������ގ���				 */
#define		MRMUCRBFAE	0x01		/* RBI �̎����� �������� ���׎�			 */
#define		MRMUCRBTME	0x02		/* RBI �����ώ� �����Î� ���׎�			 */
#define		MRMUCRBTDE	0x03		/* RBI 2 ���ގ��� �����ώ� �����Î� ���׎�		 */
#define		MRMUCRBTCE	0x04		/* RBI �����ώ� �������ގ� ���׎�			 */
#define		MRMUCRBTNO	0x05		/* RBI �����ώ� �� �����Î� ���׎�			 */
#define		MRMUCRBNTB	0x06		/* RBI �������� ���׎�					 */
#define		MRMUCRBSDE	0x07		/* RBI �Î��������� ������ 2 ���ގ��� �ʎ�����	 */
#define		MRMUCRBEDE	0x08		/* RBI �� �Î��������� ������ ���ގ�������		 */
#define		MRMUCVBLK	0x09		/* �Ύގ؎�-�� �͎����� ���ݎ؎���	   (L03) */
#define		MRMUCPVHR   0X0A		/* ʪ���Ύގ؎������ĺɴ�λ 		TD02 */
#define		MRMUCPVNR   0X0B		/* ʪ���Ύގ؎������ĺɲ����λ 	TD02 */
#define		MRMUCACC6R	0x10		/* ACC#6 ���֎� ������ ����			 */
#define		MRMUCRBREJ  0x11		/* RBI �ю����� ������            (L04) */
#define     MRMUCJRC    0x12        /* JNL��RBI�������λ       TD79 */

/*********************************************************************/
/*	���� �����Ď� �Î�����(������ ����)											 */
/*********************************************************************/
#define		MRMUSSRCV	0x00		/* �����Î� �؎��ʎގ� ������				 */
#define		MRMUSVRCV	0x01		/* �Ύގ؎����� �؎��ʎގ� ������				 */
#define		MRMUSBKUP	0x03		/* �ʎގ��������̎� ������					 */
#define		MRMUSRMAN	0x06		/* �ξ��������             TD00 */

/*********************************************************************/
/*	���� �����Ď� �Î�����(�������؎��� ����)										 */
/*********************************************************************/
#define		MRMUESRCV	0x00		/* �����Î� �؎��ʎގ� �������؎���			 */
#define		MRMUEVRCV	0x01		/* �Ύގ؎����� �؎��ʎގ� �������؎���			 */
#define		MRMUEBKUP	0x03		/* �ʎގ��������̎� �������؎���				 */
#define		MRMUERMAN	0x06		/* �ξ������λ             TD00 */

/*********************************************************************/
/*	���� �����Ď� �Î�����(�������� ����)											 */
/*********************************************************************/
#define		MRMUTSYS	0x00		/* �����Î� ��������					 */
#define		MRMUTSYSF	0x01		/* �����Î� �̎����� ��������				 */
#define		MRMUTVOL	0x02		/* �Ύގ؎����� ��������					 */
#define		MRMUTBKER	0x03		/* �ʎގ��������̎� �����ʎߎ�		   (L05) */
#define		MRMUTRCVF	0x04		/* RCV�̎����ٸξ�				TD00 */
#define		MRMUTJEND	0x05		/* ���ގ����Ŏ� �Ǝ����ݎĎ�			TD65 */
#define		MRMUTBAT	0x09		/* �ʎގ��Î؎� ���׎���			   (L02) */

/*********************************************************************/
/*	���� �����Ď� �Î�����(�����̎� ����)											 */
/*********************************************************************/
#define		MRMURSYS	0x00		/* �����Î� �����̎�					 */
#define		MRMURSYSF	0x01		/* �����Î� �̎����� �����̎�				 */
#define		MRMURVOL	0x02		/* �Ύގ؎����� �����̎�					 */

/*-------------------------------------------------------------------*/
/*  �ξ�����ץ�����������ʸ                                    TD-00*/
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*		�Ύގ؎����� �͎����� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���							 */
/*********************************************************************/
                                    /* �������ݎώ��ݎĤκ��Ѥ�ȼ�����    */
									/* (8��)                    TD47 */
									/* mr_efcl�����ȼ������  ST1550 */
struct	mrvoluse {
	MRMUSE	mrvluse;				/* RCV�������Ѽ԰�				 */
    short	mrvlptn;				/* �ξ�PVT���ݎĎ��ֹ�               */
    short	mrvlvtn;				/* �ξ�VMT���ݎĎ��ֹ�			TD90 */
	char	mrvlvnm[6];				/* �ξ�ʪ���Ύގ؎�-�Ѽ���̾ 		 */
	short	mrvlyb1;				/* ͽ��1					TD@1 */
	char	mrvlrvnm[6];			/* �ξ������Ύގ؎�-�Ѽ���̾ 	TD90 */
	short	mrvlyb2;				/* ͽ��2					TD90 */
};
typedef	struct	mrvoluse MRVOLUSE;

/*********************************************************************/
/*		�ʎގ� �؎����� �֎������� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���						 */
/*********************************************************************/
									/* SCSI�؎��ĵ�ǽ���ѹ���ȼ�����  */
									/* (5��)                    TD61 */
/*********************************************************************/
/*		�ξ�Ύގ؎����� ���׎� �����͎ގ� ���� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���			 	 */
/*********************************************************************/
struct	mreiduse {					/*						   (L07) */
	MRMUSE  mreiuse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	   (L07) */
	char    mrervnm[8];     		/* ���������ގ� �̎ގ؎Ύގ؎����ю����͎ގҎ�(L07) */
	char	mrerrid;				/* ���׎� �����͎ގ�  			   (L07) */
	char	mreryob[3];	        	/* �֎ˎ� 		 			   (L07) */
	char    mrerlvnm[8];     		/* �ξ������Ύގ؎����Ѽ���̾    (M06) */
};															/* (L07) */
typedef	struct	mreiduse MREIDUSE;							/* (L07) */
/*******************************/
/*  ���顼���̤����      TD-00*/
/*******************************/
#define		MRMEUEC		0x00		/* �ʎގ����� �������� �̎֎�		   (L07) */
#define		MRMENEC		0x01    	/* �ʎގ����� �������� �֎�		   (L07) */

/*********************************************************************/
/*		������ �͎����� ���׎� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���							 */
/*********************************************************************/
struct	mrvrquse {					/*						   (L03) */
	MRMUSE	mrvruse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	   (L03) */
	char	mrvrvnm[6];				/* �����Ύގ؎�-�Ѽ���̾         TD90 */
	short	mrvryb1;				/* �֎ˎ�1					   (L03) */
	long	mrvrcod;				/* ����- ���������� ��-�Ď�		   (L03) */
};															/* (L03) */
typedef	struct	mrvrquse MRVRQUSE;							/* (L03) */

/*********************************************************************/
/*		���ގ��� �͎����� ���ݎ؎��� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���						 */
/*********************************************************************/
struct	mrvfnuse {					/*						   (L03) */
	MRMUSE	mrvfuse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	   (L03) */
	char	mrvfvnm[6];				/* �����Ύގ؎�-�Ѽ���̾         TD90 */
	short	mrvfyb1;				/* �֎ˎ�1					   (L03) */
};															/* (L03) */
typedef	struct	mrvfnuse MRVFNUSE;							/* (L03) */

/*********************************************************************/
/*      �ʣΣ̡��ң£ɽ������λ��ʸ���Ѽ԰�                    TD00 */
/*********************************************************************/
struct  mriecuse {                  /*                          TD79 */
	MRMUSE 	 mrieuse;               /* RCV�������Ѽ԰�          TD79 */
    unsigned char	mrieekbn;       /* ��λ��ʬ                 TD79 */
	char	mrieyobi[3];            /* ͽ��                     TD79 */
};                                                           /* TD79 */
typedef struct mriecuse MRIECUSE;                            /* TD79 */
/*******************************/
/*  ��λ��ʬ�����(mrieekbn)   */
/*******************************/
#define     MRIEJNLCHG     0x80      /* JNL�ν������λ          TD79 */
#define     MRIERBICHG     0x40      /* RBI�ν������λ          TD79 */
#define     MRIEKJCHG      0x20      /* KJ �ν������λ          TD83 */
#define     MRIEJNLERR     0x81      /* JNL�ν��������          TD79 */
#define     MRIERBIERR     0x41      /* RBI�ν��������          TD79 */
#define     MRIEKJERR      0x21      /* KJ �ν��������          TD83 */
#define     MRIEJNLINT     0x82      /* JNL�ν������            TD79 */
#define     MRIERBIINT     0x42      /* RBI�ν������            TD79 */
#define     MRIEKJINT      0x22      /* KJ �ν������            TD83 */
#define     MRIESWH        0x10      /* JNL�����̤����ش�λ    CT0977 */
#define     MRIESWHERR     0x11      /* JNL�����̤����ؼ���    CT0977 */

/*-------------------------------------------------------------------*/
/*  �֣ңã��������ץ�����������ʸ                              TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*	ʪ���ܥ�塼���ĺ�/�ĺɲ��������ʸ���Ѽ԰�                 TD00 */
/*********************************************************************/
struct	mrprcuse {					/*						    TD02 */
	MRMUSE	mrpruse;				/* �Ҏ��������ގ͎����ގ�				TD02 */
	long	mrprsoch;				/* ����ID					TD02 */	
	short	mrprpvte;				/* PVT���ݎĎ��ֹ�				TD02 */
	short	mrpryob1;				/* �֎ˎ�1					   	TD02 */
	long	mrprwhtm[2];			/* �ĺɻ���				   	TD02 */
};									/* 							TD02 */
typedef	struct	mrprcuse MRPRCUSE;	/* 							TD02 */

/*********************************************************************/
/*  �ܥ�塼���ĺ�������ʸ���Ѽ԰�                              TD00 */
/*********************************************************************/
struct	mrhvnuse {					/*						    TD90 */
	MRMUSE  mrhvuse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	    TD90 */
	char    mrhvvnm[8];     		/* �ĺɎΎގ؎����Ѽ���̾         TD90 */
};															 /* TD90 */
typedef	struct	mrhvnuse MRHVNUSE;							 /* TD90 */

/*-------------------------------------------------------------------*/
/*  ���ָξ�����ץ�����������ʸ	                            TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*	ʪ���ܥ�塼���ĺ�/�ĺɲ����λ��ʸ���Ѽ԰�                 TD00 */
/*********************************************************************/
struct	mrpecuse {					/*						    TD02 */
	MRMUSE	mrpeuse;				/* �Ҏ��������ގ͎����ގ�				TD02 */
	unsigned char	mrpeekbn;		/* ��λ��ʬ					TD02 */
	char	mrpeyob1[3];			/* �֎ˎ�1					   	TD02 */
	long	mrpewhtm[2];			/* �ĺɻ���				   	TD02 */
};									/* 							TD02 */
typedef	struct	mrpecuse MRPECUSE;	/* 							TD02 */

/*******************************/
/*  ��λ��ʬ(mrpeekbn)�����   */
/*******************************/
#define     MRPEHEND	   0x80      /* �ĺɴ�λ				 TD02 */
#define     MRPENEND       0x40      /* �ĺɲ����λ	         TD02 */
#define     MRPEHERR       0x81      /* �ĺɼ���		         TD02 */
#define     MRPENERR       0x41      /* �ĺɲ������	         TD02 */
#define     MRPEHUNO       0x82      /* �ĺɻ�����̤����         TD02 */
#define     MRPENUNO       0x42      /* �ĺɲ��������̤����     TD02 */

/*-------------------------------------------------------------------*/
/*  �ξ�����󶡴ؿ�������ʸ                                    TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*		�ξ�����󶡴ؿ����Ѽ԰�                                TD00 */
/*********************************************************************/
struct mrmeruse {					/*						   (L03) */
	MRMUSE	mrmeuse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	   (L03) */
	char	mrmertyp;				/* ���׎� �����͎ގ� 			   (L03) */
	char	mrmedtyp;				/* ������ �����͎ގ�			   (L03) */
									/*	FIP ���� �� ���׎� : MREJFIP('F')	 */
	char	mrmeyobi[2];			/* �؎��ގ��̎�				   (L03) */
	long	mrmeevnt;				/* ���͎ގݎ� �ʎގݎ��ގ�			   (L03) */
};															/* (L03) */
typedef struct mrmeruse MRMERUSE;							/* (L03) */

/*********************************************************************/
/*		�ʣΣ̡��ң£ɽ����������ʸ���Ѽ԰�                    TD00 */
/*********************************************************************/
struct  mrearuse {                  /*                          TD79 */
    MRMERUSE  mrmeause;             /* �ξ�����󶡴ؿ����Ѽ԰� TD79 */
	char      mreartyp;             /* �����ʬ                 TD79 */
	char      mrearyob[3];          /* ͽ��		                TD79 */
};															 /* TD79 */
typedef struct mrearuse MREARUSE;							 /* TD79 */

/*-------------------------------------------------------------------*/
/*  �ߥ顼�������Ʊ����ǽ������ʸ					CT0894	TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*		�ߥ顼�����ܥ�塼�������ǽ�������Ѽ԰�ե����ޥå�	TD00 */
/*********************************************************************/
struct	mrmlvuse {											/*	TD22 */
	MRMUSE	mrmluse;				/* �Ҏ��������ގ͎��������Ѽ԰�		TD22 */
	char	mlvvnam[8];				/* �����Ύގ؎����Ѽ���̾			TD22 */
	char	mlvfkbn;				/* �����ʬ					TD22 */
	char	mlverr;					/* ���顼����				TD22 */
	char	mlvyobi[2];				/* ͽ��						TD22 */
	long	mlvercd;				/* ���顼������				TD22 */
};															/*	TD22 */
typedef	struct	mrmlvuse MRMLVUSE;							/*	TD22 */

/*********************************************************************/
/*		�����ʬ												TD00 */
/*********************************************************************/
#define	MRRSTIMP		0x00		/* �����Բ�ǽ				TD22 */
#define	MRRSTPOS		0x01		/* �����ǽ					TD22 */

/*********************************************************************/
/*		���顼����												TD00 */
/*********************************************************************/
#define	MRMLCON			0x01		/* �Ў׎��ü�̎����َ��Ȏ��ļ���		TD22 */
#define	MRMLOPN			0x02		/* �Ў׎��ü�̎����َ����̎ߎݼ���		TD22 */
#define	MRMLINF			0x03		/* �Ў׎����ּ�������			TD22 */
#define	MRMLGET			0x04		/* �����ΰ������������		TD22 */
#define	MRMLSET			0x05		/* �����ΰ�������꼺��		TD22 */
#define	MRMLERR			0x0F		/* �����ΰ�����Գ��������Բ�TD22 */

/*-------------------------------------------------------------------*/
/*  ����¾�󶡴ؿ�������ʸ                                      TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*      �ʣΣ̡��ң£ɣ��Ÿξ��������ʸ���Ѽ԰�                TD00 */
/*********************************************************************/
struct  mrceruse {                  /*                          TD78 */
	MRMUSE 	 mrceuse;               /* RCV�������Ѽ԰�          TD78 */
	char     mrcertyp;              /* �����ʬ                 TD78 */
	         /* ���μ��̺��(1��)							ST2895	 */
	char     mrcermen;              /* �����о���               TD78 */
	char     mrcerrid;              /* ����-����                  TD78 */
	char	 mrceryob;				/* ͽ��					ST2895	 */
};                                                           /* TD78 */
typedef struct mrceruse MRCERUSE;                            /* TD78 */

/*-------------------------------------------------------------------*/
/*  �֣ңã֥ץ������ʣ����˽�����ʸ							TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*		�ܥ�塼����������������Ѽ԰�							TD00 */
/*********************************************************************/
struct	mrvecuse
{
	MRMUSE	mrvmuse;				/* RCV�������Ѽ԰�				 */
	char	mrvbkid[8];				/* �Хå����å�ID				 */
	char	mrvrvmd;				/* ����⡼��					 */
	unsigned char	mrvrcvf;		/* RCV�̎����پ���					 */
	char	mrvrsv1[2];				/* ͽ��							 */
	long	mrvrcod;				/* �������						 */
	short	mrvpvte;				/* ����TPVT���ݎĎ��ֹ�				 */
	short	mrvvmte;				/* ����TVMT���ݎĎ��ֹ�				 */
	char	mrvpnam[8];				/* ʪ���Ύގ؎�-�Ѽ���̾				 */
	char	mrvvnam[8];				/* �����Ύގ؎�-�Ѽ���̾				 */
};
typedef	struct	mrvecuse	MRVECUSE;

/*********************************************************************/
/*		����⡼��												TD00 */
/*********************************************************************/
#define	MRVNBVL		'0'				/* �ʎގ��������̎ߎÎގ�������Ύ؎��Ď�		 */ 
#define	MRVUBVL		'1'				/* �ʎގ��������̎����׎Ύގ؎����Ѥβ���		 */
#define	MRVMRVL		'2'				/* �Ў׎��Ύގ؎���������				 */
#define	MRVWKVL		'3'				/* �܎����̎����َΎގ؎����Ѥβ���			 */
#define	MRVRVVL		'4'				/* �؎��ʎގ؎̎����َΎގ؎����Ѥβ���		 */

/*********************************************************************/
/*		�������												TD00 */
/*********************************************************************/
#define	MRVVNRM		0L				/* ��������						 */
#define	MRVVFLT		-1L				/* ���켺��						 */

/*-------------------------------------------------------------------*/
/*  �Хå����åץץ������ʣ����˽�����ʸ						TD00 */
/*-------------------------------------------------------------------*/
/*********************************************************************/
/*		�Ύގ؎����� ���������ގ� �Îގݎ̎ގ� �؎֎��������� �̎�-�ώ���							 */
/*********************************************************************/
struct	mrveruse {					/*						   (L05) */
	MRMUSE	mrveuse;				/* �Ҏ��������� �͎����ގ� �؎֎���������	   (L05) */
	char	mrvenam[8];				/* ���������ގ� �ێݎ؎Ύގ؎����� �����͎ގҎ�(L05) */
	short	mrveent;				/* VMT �ώ��� VBT ���ݎĎ� �ʎގݎ��ގ� (L05) */
	char	mrveid;					/* ���ˎߎ� �ӎ�/���� �����͎ގ�	   (L05) */
	char	mrveyb1;				/* �֎ˎ�1					   (L05) */
};
typedef	struct	mrveruse MRVERUSE;

/*----------------------------------------------------------------------*/
/*	�ӣãӣɥꥻ�åȵ�ǽ��Ϣ������ʸ			TD61					*/
/*----------------------------------------------------------------------*/
/************************************************************************/
/*	�����ӣͣ��������Ѽ԰�ե����ޥå�									*/
/************************************************************************/
struct	mrmcesmp	{					/*					CT1039		*/
	MRMUSE	mrmceuse;					/*	��å������إå����Ѽ԰�	*/
	char	mrmcrecd;					/*	���̼���		CT1039		*/
	char	mrmcencd;					/*	��ʬ�ॳ����	CT1039		*/
	char	mrmcdtcd;					/*	�ܺ�ʬ�ॳ����	CT1039		*/
	unsigned char	mrmcrctb;			/*	�ơ��֥���̥ե饰	CT1039	*/
	long	mrmcsrcd;					/*	�����ƥॳ�����ֵ��� CT1039	*/
	short	mrmcmbnm;					/*	TVMT/TVBT�������ֹ�	 CT1039	*/
};										/*					CT1039		*/
typedef	struct	mrmcesmp	MRMCESMP;	/*					CT1039		*/

/************************************************************************/
/*	���̼���															*/
/************************************************************************/
#define		MRMCSMPRE		0x0C		/*	���̼���		CT1039		*/

/************************************************************************/
/*	��ʬ�ॳ����														*/
/************************************************************************/
#define		MRMCSMPCE		0x05		/*	��ʬ�ॳ����	CT1039		*/

/************************************************************************/
/*	�ܺ�ʬ�ॳ����														*/
/************************************************************************/
#define		MRMCSMPDE1		0x05		/*	�����ӣͣ����Σ�	CT1039	*/
#define		MRMCSMPDE2		0x03		/*	�����ӣͣ����Σ�	CT1039	*/
#define		MRMCSMPDE3		0x07		/*	�����ӣͣ����Σ�	CT1106	*/

