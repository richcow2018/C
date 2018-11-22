/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ���̎� �ʎߎ�������													 */
/*		RCV															 */
/*																	 */
/*	2 ���ݎ��� ���̎ގ�														 */
/*		���ގ�-�Ŏ� ���ՎĎ� ���׎� 											 */
/*																	 */
/*	3 ���ݎ��� �Ҏ�														 */
/*		mr_ejrq														 */
/*																	 */
/*	4 ���Ɏ� ���ގ��֎�														 */
/*      �̎����ٸξ�ȯ�������뤤�ώÎ��̎ގ��ѹ��������ގ����Ŏټ����ڤ�     (TD00) */
/*      ���׎��Ҏ��������޽�������ξ�����̎ߎێ����ذ��ꤹ�롣            (TD00) */
/*																	 */
/*	5 �ʎߎ׎�-��														 */
/*		type	: ���׎� �����͎ގ�											 */
/*		len		: ���������� ���ގ����Ύ� ������									 */
/*		detail	: ���������� ���ގ����Ύ�										 */
/*																	 */
/*	6 �͎ݎ��Ԏ���														 */
/*		MRNORMAL	:	�������ގ֎� ���Վ��؎֎�								 */
/*		MRIVPARM	:	�ʎߎ׎�-�� ����-							  		 */
/*		MCEOSERR	:	TRADE �����Îю�-�� ����-					  (TD00) */
/*		MRNOMEM 	:	�Ҏӎ� �̎ގ���									 */
/*		MRETERM 	:	�����Î� �������؎��� ������ ������							 */
/*																	 */
/*	7 �؎ڎ�															 */
/*		���������� : �ώ����ގ� ������											 */
/*		������������ : �ώ����ގ� ������				'87/03/11					 */
/*		�͎ݎ������� : �ώ��� ��������				'87/12/24 (L01)				 */
/*				(�Îގݎ̎ގ� �������� �����ގ������� �� �̎ߎ��َʎގ��̎� �����Ύ�)	---	STC569	 */
/*		�͎ݎ������� : �Ԏώӎ� �Վ�����				'88/05/11 (L02)				 */
/*				(�Ύގ؎�-�� �͎����� ���Ɏ� ���� �� �ĎӎŎ� �͎ݎ���) --- STC911		 */
/*		�͎ݎ������� : �ώ��� ��������				'88/11/20					 */
/*				 (���������ގ� �������� ���ގ����Ύ� �����Ď� ���ݎ��� �� �͎ݎ���) --- TC1990	 */
/*		�͎ݎ������� : �����ގ� ������ 				'90/03/15 (L03)				 */
/*				 (�Ǝ��ގ��� �ʎ����� ���� ���ގ��� �����Ŏ�) --- TCXXXX				 */
/*      �ѹ��� : ���桡����                  (TD-02) (TD-50) (TD-59) */
/*               (�Ύ��Ď����ݎʎގ��ѹ���ȼ���ѹ�)   (TD-02) 				 */
/*				 (�ێ��ޤθ�ľ����ȼ������)			 (TD-50)		 */
/*               (PU����Ω����ȼ���ѹ�)                      (TD-59) */
/*                                 '93/11/01 (TD-50) (TD-02) (TD-59) */
/*		�ѹ��� : ����  ����				'96/05/26	---	ST4395		 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*�ץ���������̾	:												 */
/*�ץ�����̾		:���Хץ�����									 */
/*��¤�ֹ�			:PRC-005-09										 */
/*��¤����			:�Х���ȿž�б�									 */
/*��¤��			:2002.11.05										 */
/*��¤��			:��								 */
/*********************************************************************/
/*********************************************************************/
/*�ץ���������̾	:												 */
/*�ץ�����̾		:���Хץ�����									 */
/*��¤�ֹ�			:KL0004 										 */
/*��¤����			:TABP��Ϣ������ϳ��							 */
/*��¤��			:2003.02.19										 */
/*��¤��			:��								 */
/*********************************************************************/

/*********************************************************************/
/*	���ݎ���-�Ď� �̎�����													 */
/*********************************************************************/
/*********************************************************************/
/*	PRC-005-09  ���� START 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/
#include	"mosmpcom.h"												/* PRC-005-09 */
/*********************************************************************/
/*	PRC-005-09  ���� END 											 */
/*  ����ǥ����������б�  �Х���ȿž								 */
/*********************************************************************/
#include	"mr.h"													 
#include	"mo.h"													 
#include	"mc.h"													 
#include	"tcom.h"					/* �Î��̎ގٶ�����				 */
#include	"psect.h"					/* PSECT					 */
#include	"mrcom.h"					/* RCV ��������				 */
#include	"tbpt.h"					/* BPT						 */
#include	"tsst.h"					/* SST						 */
#include	"tcst.h"					/* CST						 */
#include	"tsrt.h"					/* SRT						 */
#include	"tpct.h"					/* PCT						 */
/*********************************************************************/
/*	KL0004  ���� START 												 */
/*  TABP��Ϣ������(tabp.h)										 */
/*********************************************************************/
/*********************************************************************/
/*	KL0004  ���� END 												 */
/*  TABP��Ϣ������(tabp.h)										 */
/*********************************************************************/
#include	"mopcb.h"					/* OCP �̎ߎێ��� ���ݎ� �̎ގێ�		 */
#include	"mcmia.h"					/* �Îގݎ̎ގ� ���������̎�			 */
#include	"mrmuse.h"					/* RCV �Îގݎ̎ގ� �̎�-�ώ���		 */
#include	"mrcode.h"					/* RCV ���ގ��ݎ�-�Ď� 			 */
#include	"mrmac.h"
#include	"mcdebug.h"
#include	"ossenmsp.h"
#include	"mre.h"										 
#include    "osgtpin.h"                 /*                    (TD59) */
#include	"mo_wlg.h"					/*					  (TD50) */

/*********************************************************************/
/*	���ގ��̎� �͎ݎ���														 */
/*********************************************************************/
extern	PSCPSECT	pscparea;
extern	MOPSCPCB	*mopcbp;
												 
/*********************************************************************/
/*	�Îގ̎����ݎ� 														 */
/*********************************************************************/
										/* MRWLOG���(1��)			  (TD50)*/
#define SYSNG1			1				/* �ێ��޴�Ϣ�����Îю����َ��׎��ܺپ���1 (TD50)*/
#define SYSNG2			2				/* �ێ��޴�Ϣ�����Îю����َ��׎��ܺپ���2 (TD50)*/
#define SYSNG3			3				/* �ێ��޴�Ϣ�����Îю����َ��׎��ܺپ���3 (TD50)*/

/*********************************************************************/
/*	define function name for mo_wlg4						(TD-50)	 */
/*********************************************************************/
#define	MR_EJRQ	0x6d725f65,0x6a727120

long	mr_ejrq( type, len, detail )
char	type;
short	len;
char	*detail;
{
	
	
/*********************************************************************/
/*	03-26-2003 NOP�ؿ����ѹ�	START								 */
/*********************************************************************/	
#ifdef LINUX_ISOKUTAIOU	

/*********************************************************************/
/*	03-26-2003 NOP�ؿ����ѹ�	END									 */
/*********************************************************************/


	/*****************************************************************/
	/*	mr_ejrq �Ŏ� ���֎� ���ݎ��� �� �Î�����									 */
	/*****************************************************************/
	TPCTPSZ	*mr_cpct();					/* PCT ��-�� ������				 */
	void	mr_sdwn();					/* �����Î� ���ގ���				 */
	long	mr_cgbf();					/* �̎�-�َʎގ̎� �� �����Ď�    (L02) */
	long	ossnsev();					/* ���͎ގݎ� ���ގ������� �� �����Ď�		 */
	long	ossenmsp();					/* �Ҏ���-���� �� �ʎގ��̎� ��������		 */
	long	mc_copy();					/* �Î�-�� ���ˎ�-				 */
	long	mc_clea();					/* �ʎގ��̎� ���؎�-				 */
										/* STC569 87-12-24	   (L01) */
	long	mo_frbf();					/* �̎ߎ��َʎގ��̎� �� �����Ύ�	   (L01) */
	void	mr_sabt();					/* �̎ߎێ��� ���Ύގ���		   (L01) */
										/* STC569 87-12-24	   (L01) */
	long	osgtpin();					/* �̎ߎێ����ξ���μ���  (TD59) */
	void	mo_wlg4();					/* P�Ďڎ�������μ���    (TD50) */

	/*****************************************************************/
	/*	mr_ejrq �Ŏ� ��-�� ���؎�											 */
	/*****************************************************************/
	register	TPCTPSZ *pctp;			/* PCT ���͎ގ̎� �Ύߎ��ݎ� 		 */
				char	pname[sizeof(mopcbp->mopscstp->tcsterrp)+1];
										/* �ξ�����̎ߎێ���̾    (TD00) */
	register	long	eventno;		/* �Ďގ����ώ� �֎� ���͎ގݎ� �ʎގݎ��ގ�	 */
	register	long	rcode;			/* �؎�-�ݎ�-�Ď� ���؎� 			 */
	register	long	mbid;			/* �������ݎ��� �Ҏ��َΎގ����� ID		 */
	register	long	rtn;			/* �Ď����ގ� ���ݎ��� ���׎� �͎ݎ������� ���؎� */
				long	*buff;			/* �ʎގ��̎� �����Ď� �֎� ��-�����؎� 	 */
	register	MCMIKYO *miap;			/* MIA �Ύߎ��ݎ� 		   (L02) */
	register	MRMERUSE *musep;		/* �؎֎����� ���� �Ύߎ��ݎ�	   (L02) */
	register	long	blen;			/* �Îގݎ̎ގ� ������		   (L02) */
				long	mrlog[3];
				long	puno;			/* mr_cgbf�ΰ���	  (TD59) */
				oseprinf	prinfp;		/* �̎ߎێ��������Ǽ��    (TD59) */
	/*****************************************************************/
	/*	PRC-005-09  ���� START 										 */
	/*  ����ǥ����������б�  �Х���ȿž							 */
	/*****************************************************************/
	register	MRMUMK34_U muinf;		/* ���ݎ��̎����������Ď� �Ύߎ��ݎ�		 */ /* PRC-005-09 */
	/*****************************************************************/
	/*	PRC-005-09  ���� END 										 */
	/*  ����ǥ����������б�  �Х���ȿž							 */
	/*****************************************************************/

	PRINT0("*** mr_ejrq(type,len,detail) invoked ***\n");
	PRINT1("            type   = 0x%02x\n",type);
	PRINT1("            len    = %d\n",len);
	PRINT1("            detail = %s\n",detail);
	/*****************************************************************/
	/*	  �֎ˎގ��ގ� ���ގ��������� �� �������� ����									 */
	/*****************************************************************/
	/* MRWLOG��� ��3�ԡ�									 		(TD50) */
	mrlog[0] = (long) type;
	mrlog[1] = (long) len;
	mrlog[2] = (long) detail;
	mo_wlg4( MR_EJRQ,WINSC,mrlog,12L ); /*					  (TD50) */
    /*
����/************************************************************************/
	/*	  �����ƥ๽���Υ����å�                                     (TD00) */
	/************************************************************************/
	if ( (mopcbp->mopssstp->tsstsysc == 'H')
		&&(mopcbp->mopssstp->tsstsysd == 'F') )
										/* �����Îѹ������󤬎Ύ��Ď����ݎʎގ�   (TD02) */
										/* ���Ď̎ގێ�����ʬ��ͽ���ϤΡ� (TD02) */
										/* ��                        (TD02)	*/
	{
		mr_sabt( MREEJRQ,MRDEHOTWAIT ); /* �̎ߎێ������Ύގ��ġ�����			 (TD02) */
	}                                   /*                           (TD02) */
	
	if ( len <= 0 ) {					/* �Î�-�������� ���ݎ������� ��������		 */
		rtn = MRIVPARM;
		goto error;
	}
	else;
	if ( ( mopcbp->mopssrtp->tsrtdvst == TSRTEND ) ||			/*	ST4395	*/
		 ( mopcbp->mopssrtp->tsrtdvst == TSRTQST ) ){ 	/* �����Î� �������؎��������� 	*/
		rtn = MRETERM;
		goto error;
	}
	else;
	if ( pscparea.pscpctno == 0 ) {		/* �֎ˎގ��ގ��ӎ� �ώ����������ގ����� �� ?	 */
		mr_sdwn( MRSTART,MREEJRQ,MRDMSCALL );
	}
	else								/*                           (TD59) */
	{                                   /*                           (TD59) */
		if (1 == pscparea.pscpctno )    /* �ƽи������̎ގώ����������ގ����פ�?  (TD59) */
		{                               /*                           (TD59) */
			mr_sdwn( MRSTART,MREEJRQ,MRDSMSCALL );
			                            /* �ҎӎغƳ��ϤΎ����Îю��ގ���       (TD59) */
		}                               /*                           (TD59) */
	}                                   /*                           (TD59) */
	
	/*****************************************************************/
	/*	 TPCT�����􎱎Ďގڎ��γ���						 ����������������*/
	/*****************************************************************/
	mc_copy( mopcbp->mopscstp->tcsterrp,/* �ξ�����̎ߎێ�������̾��ʣ�� (TD00) */
			 pname,
			 (long)sizeof(mopcbp->mopscstp->tcsterrp) );
	pname[sizeof(mopcbp->mopscstp->tcsterrp)] = '\0';

	pctp = mr_cpct( pname );
	
	/************************************************************************/
	/*	  �̎ߎێ���¸�ߎ�������				��     ��		 ����������������		 */
	/************************************************************************/
	mrlog[0] = pctp->tpctpid;			/*							 (TD50) */
	mrlog[1] = (long)&prinfp;			/*							 (TD50) */
	mo_wlg4(MR_EJRQ,WBSYS | OSGTPIN,mrlog,8L);
										/*							 (TD50) */
	if ( osgtpin( pctp->tpctpid,&prinfp ) != NORMAL )
	                                    /* �ξ�����̎ߎێ�����¸�ߤ��뤫?(TD59) */
	{
		mo_wlg4(MR_EJRQ,WASYS | OSGTPIN,(long *)0,0L);	
										/*							 (TD50) */
		mr_sdwn( MRDOWN,MREEJRQ,MRDNOMRH );
										/* �ҎӎغƳ��Ϥʤ��Ύ����Îю��ގ��ݡ� (TD59) */
	}
	mo_wlg4(MR_EJRQ,WASYS | OSGTPIN,(long *)0,0L);
										/*							 (TD50) */

	/* PU����Ω���б��ΰٺ����14�ԡˡ���������������������������    (TD59) */

    /************************************************************************/
	/*	  �̎ߎێ������֥����å�					 ���������������� 		 (TD59) */
	/************************************************************************/
	switch ( pctp->tpctsts ) {			/* �̎ߎێ��� ���ގ������� �� ��������		 */
	case TPCTING :
	case TPCTSUS :
		break;
	default :
		mr_sdwn( MRSTART,MREEJRQ,MRDERRPDEAD );
	}
	mbid = pctp->tpctpmb;
	eventno = mopcbp->mopscstp->tcstevnt;

	/* MRWLOG�����3�ԡ�									����	 (TD50) */
	mrlog[0] = eventno;
	mo_wlg4( MR_EJRQ,WBSYS | OSSNSEV,mrlog,4L );
										/*							 (TD50) */

	rcode = ossnsev( eventno );			/* ���͎ގݎ� �� ���ގ������� �� �����Ď� ����	 */
	mrlog[0] = rcode;					/*							 (TD50) */
	mo_wlg4( MR_EJRQ,WASYS | OSSNSEV,mrlog,4L );
										/*							 (TD50) */
	if ( rcode != 0 ) {
		rtn = MCEOSERR;
		MROSERR( MCEOSSNSEV, rcode );

		mrlog[0] = SYSNG1;				/*							 (TD50) */
		mo_wlg4( MR_EJRQ,WNGSC,mrlog,4L );
										/*							 (TD50) */

		goto error;
	}
	else;
	
	/*			���פʥ����å��Τ�����							 (TD00) */
	
	blen = (long)(sizeof(MCMIKYO)+sizeof(MRMERUSE)+len);	/* (L02) */
	if( 0 == pscparea.pscpuno ){		/* ���ץ��������Уգ��λ� 	 (TD59) */
		puno = 1;						/* mr_cgbf�ΰ����ˣ�������   (TD59) */
	}									/*							 (TD59) */
	else								/*							 (TD59) */
	{									/* 							 (TD59) */
		if( 1 == pscparea.pscpuno ){	/* ���ץ��������Уգ��λ�    (TD59) */
			puno = 0;					/* mr_cgbf�ΰ����ˣ�������	 (TD59) */
		}								/*							 (TD59) */
	}									/* 							 (TD59) */
	rcode = mr_cgbf( puno,		/* �Ҏ���-���� �������ݎ֎� �ʎގ��̎� �� �����Ď�  (L02) (TD59) */
					 blen,									/* (L02) */
					 &buff );

	if ( rcode >= blen ) { 				/* ���Î��ڎݎ��ގ� �̎ގ� �������Ď�  (L02) */
	}
	else if ( rcode == MRNOMEM ) {		/* �Ҏӎ�-�̎ގ��� �� �Ď�	   (L02) */
		rtn = MRNOMEM;
		mrlog[0] = rcode;
		mo_wlg4( MR_EJRQ,0x33331000L,mrlog,4L );
										/*							 (TD50) */
		goto error;
	}
	else {								/* TRADE �����Îю�-�� ����- �� �Ď�    (TD00) */
		rtn = MCEOSERR;
		mrlog[0] = rcode;
		mo_wlg4( MR_EJRQ,0x33331001L,mrlog,4L );
										/*							 (TD50) */
		goto error;
	}
	miap = ( MCMIKYO * ) buff;								/* (L02) */
	musep = ( MRMERUSE * )( (char *)miap+sizeof(MCMIKYO) );	/* (L02) */
	
	/*****************************************************************/
	/*	  �������� �Ҏ���-���� �� �͎ݎ����� ����									 */
	/*****************************************************************/
	mc_clea( (char *) miap,									/* (L02) */
			 '\0',
			 blen );										/* (L02) */
	miap->mcmimkcd[0] = MRMK1;								/* (L02) */
	miap->mcmimkcd[1] = MRMK2;								/* (L02) */
	miap->mcmidtsz	= len;									/* (L02) */
	miap->mcmimisz	= sizeof(MCMIKYO) + sizeof(MRMERUSE);	/* (L02) */
	mc_copy( pscparea.pscprsnm,
			 miap->mcmisnpn,								/* (L02) */
			 (long)sizeof(miap->mcmisnpn) );				/* (L02) */
	mc_copy( pname,
			 miap->mcmirvpn,								/* (L02) */
			 (long)sizeof(miap->mcmirvpn) );				/* (L02) */
	/*****************************************************************/
	/*	PRC-005-09  ���� START 										 */
	/*  ����ǥ����������б�  �Х���ȿž							 */
	/*****************************************************************/
	muinf.mrmumk_s.mrmumk3  = htons(MRMUIRMAN);							/* PRC-005-09 */
	musep->mrmeuse.mrmumk34 = ntohl(muinf.mrmumk_l);					/* PRC-005-09 */
	/*****************************************************************/
	/*	PRC-005-09  ���� END 										 */
	/*  ����ǥ����������б�  �Х���ȿž							 */
	/*****************************************************************/
	musep->mrmeuse.mrmudis = MRMUDASK;						/* (L02) */
	musep->mrmeuse.mrmucod = MRMUAJNL;						/* (L02) */
	musep->mrmertyp = MREREJRQ;								/* (L02) */
	musep->mrmedtyp = type;									/* (L02) */
	musep->mrmeevnt = eventno;								/* (L02) */

	mc_copy( detail,
			 (char *)musep + sizeof(MRMERUSE),				/* (L02) */
			 (long) len );

	/************************************************************************/
	/*	 �Ҏ��������ޤ�����											            */
	/************************************************************************/
	/* MRWLOG��� ��3�ԡ�											 (TD50) */
	mrlog[0] = mbid;					/* 							 		*/
	mrlog[1] = blen;					/*                     		  (L02) */
	mrlog[2] = (long) ( (char *) miap );
	             						/*          		   		  (L02) */
	mo_wlg4( MR_EJRQ,WBSYS | OSSENMSP,mrlog,12L );
		                            	/* 							 (TD50)	*/
		
	rcode = ossenmsp( mbid,     		/* �ξ�����̎ߎێ����ؤ�		 (TD00) */
					  blen,				/* �Ҏ�������������          		  (L02) */
					  (char *) miap );
							            /*                            (L02) */
	mrlog[0] = rcode;					/*          		   		 (TD50) */
	mo_wlg4( MR_EJRQ,WASYS | OSSENMSP,mrlog,4L );
		                            	/* 							 (TD50)	*/
	if ( rcode != NORMAL )          	/* �������������ʤ��ä�����		*/
	{                               	/* 							   		*/
		rtn = MCEOSERR;
		MROSERR( MCEOSSENMSP,rcode );

		mrlog[0] = SYSNG2;				/*							 (td50) */
		mo_wlg4( MR_EJRQ,WNGSC,mrlog,4L );
										/*							 (TD50) */
		rcode = mo_frbf( buff );		/* STC569 87-12-24     		  (L01) */
		if ( rcode != MONORMAL )		/* �̎ߎ��َʎގ��̎� �����Ύ�	   		  (L01) */
		{
			mrlog[0] = rcode;			/* �ێ��� ���ގ����Ύ�		   		  (L01) */
			mo_wlg4( MR_EJRQ,0x33331002L,mrlog,4L );
			                    		/* �ێ��޼���             		 (TD50) */
			mr_sabt( MREEJRQ,MRDFBUFERR );
			                    		/* �̎ߎێ��� ���Ύގ���	       		  (L01) */
		}								/*                     		  (L01) */
		else;							/* STC569 87-12-24	   		  (L01) */

		goto error;
	}
	else;
	
	/************************************************************************/
	/*	 ���͎ގݎĤ��Ԥ���碌 								              		*/
	/************************************************************************/
	/* MRWLOG��� ��3�ԡ�											 (TD50) */
	mrlog[0] = eventno;
	mrlog[1] = 1L;
	mrlog[2] = -1L;
	mo_wlg4( MR_EJRQ,WBSYS | OSWAITEV,mrlog,12L );
										/*							 (TD50) */

	rcode = oswaitev( eventno,
					  1L,
					  -1L );
	mrlog[0] = rcode;					/*							 (TD50) */
								
	mo_wlg4( MR_EJRQ,WASYS | OSWAITEV,mrlog,4L );
										/*							 (TD50) */
	if ( rcode != NORMAL ) {
		MROSERR( MCEOSWAITEV,rcode );

		mrlog[0] = SYSNG3;				/*							 (td50) */
		mo_wlg4( MR_EJRQ,WNGSC,mrlog,4L );
										/*							 (TD50) */

		mr_sdwn( MRSTART,MREEJRQ,MRDWAITEV );
	}
	else;

	/*			���פʥ����å��Τ�����							 (TD00) */

	/* MRWLOG��� ��3�ԡ�											 (TD50) */	
	mrlog[0] = MRNORMAL;
	mo_wlg4( MR_EJRQ,WOTSC,mrlog,4L );
										/*							 (TD50) */

	return( MRNORMAL );
error:
	/*			���פʥ����å��Τ�����						     (TD00) */

	/* MRWLOG��� ��3�ԡ�											 (TD50) */	
	mrlog[0] = rtn;
	mo_wlg4( MR_EJRQ,WOTSC,mrlog,4L );
										/*							 (TD50) */
	PRINT1("*** mr_ejrq end return code = %ld ***\n",rtn);


	return( rtn );



/*********************************************************************/
/*	03-26-2003 NOP�ؿ����ѹ�	START								 */
/*********************************************************************/	
#endif	
	
	return(MRNORMAL);

/*********************************************************************/
/*	03-26-2003 NOP�ؿ����ѹ�	END									 */
/*********************************************************************/
		
}