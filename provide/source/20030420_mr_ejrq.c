/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞ ﾊﾟﾂｹｰｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ														 */
/*		ｼﾞｬ-ﾅﾙ ｼﾕﾄｸ ｲﾗｲ 											 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ														 */
/*		mr_ejrq														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*      ﾌｧｲﾙ故障発生時あるいはﾃｰﾌﾞﾙ変更時、ｼﾞｬｰﾅﾙ取得及び     (TD00) */
/*      ｴﾗｰﾒｯｾｰｼﾞ出力等を故障管理ﾌﾟﾛｾｽへ依頼する。            (TD00) */
/*																	 */
/*	5 ﾊﾟﾗﾒ-ﾀ														 */
/*		type	: ｲﾗｲ ｼｭﾍﾞﾂ											 */
/*		len		: ｼｮｳｻｲ ｼﾞｮｳﾎｳ ﾁｮｳ									 */
/*		detail	: ｼｮｳｻｲ ｼﾞｮｳﾎｳ										 */
/*																	 */
/*	6 ﾍﾝｷﾔｸﾁ														 */
/*		MRNORMAL	:	ｾｲｼﾞﾖｳ ｼﾕｳﾘﾖｳ								 */
/*		MRIVPARM	:	ﾊﾟﾗﾒ-ﾀ ｴﾗ-							  		 */
/*		MCEOSERR	:	TRADE ｼｽﾃﾑｺ-ﾙ ｴﾗ-					  (TD00) */
/*		MRNOMEM 	:	ﾒﾓﾘ ﾌﾞｿｸ									 */
/*		MRETERM 	:	ｼｽﾃﾑ ｼｭｳﾘｮｳ ｼｮﾘ ﾁｭｳ							 */
/*																	 */
/*	7 ﾘﾚｷ															 */
/*		ｾﾂｹｲｼﾔ : ﾏｴｻﾞﾜ ｱｷﾗ											 */
/*		ｻｸｾｲｼﾔ : ﾏｴｻﾞﾜ ｱｷﾗ				'87/03/11					 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'87/12/24 (L01)				 */
/*				(ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｲｼﾞｮｳｼﾞ ﾉ ﾌﾟｰﾙﾊﾞｯﾌｧ ｶｲﾎｳ)	---	STC569	 */
/*		ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				'88/05/11 (L02)				 */
/*				(ﾎﾞﾘｭ-ﾑ ﾍｲｿｸ ｷﾉｳ ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- STC911		 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ 				'90/03/15 (L03)				 */
/*				 (ﾆｼﾞｭｳ ﾊｯｺｳ ｼﾞ ﾀﾞｳﾝ ｻｾﾅｲ) --- TCXXXX				 */
/*      変更者 : 今井　弘幸                  (TD-02) (TD-50) (TD-59) */
/*               (ﾎｯﾄｽﾀﾝﾊﾞｲ変更に伴う変更)   (TD-02) 				 */
/*				 (ﾛｸﾞの見直しに伴う修正)			 (TD-50)		 */
/*               (PUの独立化に伴う変更)                      (TD-59) */
/*                                 '93/11/01 (TD-50) (TD-02) (TD-59) */
/*		変更者 : 杉岡  克也				'96/05/26	---	ST4395		 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*プロジェクト名	:												 */
/*プロセス名		:ＡＰプロセス									 */
/*改造番号			:PRC-005-09										 */
/*改造内容			:バイト反転対応									 */
/*改造日			:2002.11.05										 */
/*改造者			:Χ								 */
/*********************************************************************/
/*********************************************************************/
/*プロジェクト名	:												 */
/*プロセス名		:ＡＰプロセス									 */
/*改造番号			:KL0004 										 */
/*改造内容			:TABP関連情報削除漏れ							 */
/*改造日			:2003.02.19										 */
/*改造者			:Χ								 */
/*********************************************************************/

/*********************************************************************/
/*	ｲﾝｸﾙ-ﾄﾞ ﾌｱｲﾙ													 */
/*********************************************************************/
/*********************************************************************/
/*	PRC-005-09  修正 START 											 */
/*  エンディアン問題対応  バイト反転								 */
/*********************************************************************/
#include	"mosmpcom.h"												/* PRC-005-09 */
/*********************************************************************/
/*	PRC-005-09  修正 END 											 */
/*  エンディアン問題対応  バイト反転								 */
/*********************************************************************/
#include	"mr.h"													 
#include	"mo.h"													 
#include	"mc.h"													 
#include	"tcom.h"					/* ﾃｰﾌﾞﾙ共通部				 */
#include	"psect.h"					/* PSECT					 */
#include	"mrcom.h"					/* RCV ｷｮｳﾂｳ				 */
#include	"tbpt.h"					/* BPT						 */
#include	"tsst.h"					/* SST						 */
#include	"tcst.h"					/* CST						 */
#include	"tsrt.h"					/* SRT						 */
#include	"tpct.h"					/* PCT						 */
/*********************************************************************/
/*	KL0004  修正 START 												 */
/*  TABP関連情報削除(tabp.h)										 */
/*********************************************************************/
/*********************************************************************/
/*	KL0004  修正 END 												 */
/*  TABP関連情報削除(tabp.h)										 */
/*********************************************************************/
#include	"mopcb.h"					/* OCP ﾌﾟﾛｾｽ ｶﾝﾘ ﾌﾞﾛﾂｸ		 */
#include	"mcmia.h"					/* ﾃﾞﾝﾌﾞﾝ ｷｮｳﾂｳﾌﾞ			 */
#include	"mrmuse.h"					/* RCV ﾃﾞﾝﾌﾞﾝ ﾌｫ-ﾏｯﾄ		 */
#include	"mrcode.h"					/* RCV ﾀﾞｳﾝｺ-ﾄﾞ 			 */
#include	"mrmac.h"
#include	"mcdebug.h"
#include	"ossenmsp.h"
#include	"mre.h"										 
#include    "osgtpin.h"                 /*                    (TD59) */
#include	"mo_wlg.h"					/*					  (TD50) */

/*********************************************************************/
/*	ｶﾞｲﾌﾞ ﾍﾝｽｳ														 */
/*********************************************************************/
extern	PSCPSECT	pscparea;
extern	MOPSCPCB	*mopcbp;
												 
/*********************************************************************/
/*	ﾃﾞﾌｧｲﾝﾁ 														 */
/*********************************************************************/
										/* MRWLOG削除(1行)			  (TD50)*/
#define SYSNG1			1				/* ﾛｸﾞ関連ｼｽﾃﾑｺｰﾙｴﾗｰ詳細情報1 (TD50)*/
#define SYSNG2			2				/* ﾛｸﾞ関連ｼｽﾃﾑｺｰﾙｴﾗｰ詳細情報2 (TD50)*/
#define SYSNG3			3				/* ﾛｸﾞ関連ｼｽﾃﾑｺｰﾙｴﾗｰ詳細情報3 (TD50)*/

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
/*	03-26-2003 NOP関数に変更	START								 */
/*********************************************************************/	
#ifdef LINUX_ISOKUTAIOU	

/*********************************************************************/
/*	03-26-2003 NOP関数に変更	END									 */
/*********************************************************************/


	/*****************************************************************/
	/*	mr_ejrq ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	TPCTPSZ	*mr_cpct();					/* PCT ｻ-ﾁ ｼｮﾘ				 */
	void	mr_sdwn();					/* ｼｽﾃﾑ ﾀﾞｳﾝ				 */
	long	mr_cgbf();					/* ﾌﾟ-ﾙﾊﾞﾂﾌｧ ﾉ ｶｸﾄｸ    (L02) */
	long	ossnsev();					/* ｲﾍﾞﾝﾄ ｼﾞｮｳﾀｲ ﾉ ｼｭﾄｸ		 */
	long	ossenmsp();					/* ﾒｯｾ-ｼﾞ ﾉ ﾊﾞｯﾌｧ ｿｳｼﾝ		 */
	long	mc_copy();					/* ﾃﾞ-ﾀ ｺﾋﾟ-				 */
	long	mc_clea();					/* ﾊﾞｯﾌｧ ｸﾘｱ-				 */
										/* STC569 87-12-24	   (L01) */
	long	mo_frbf();					/* ﾌﾟｰﾙﾊﾞｯﾌｧ ﾉ ｶｲﾎｳ	   (L01) */
	void	mr_sabt();					/* ﾌﾟﾛｾｽ ｱﾎﾞｰﾄ		   (L01) */
										/* STC569 87-12-24	   (L01) */
	long	osgtpin();					/* ﾌﾟﾛｾｽの情報の取得  (TD59) */
	void	mo_wlg4();					/* Pﾄﾚｰｽ情報の取得    (TD50) */

	/*****************************************************************/
	/*	mr_ejrq ﾅｲ ﾜ-ｸ ｴﾘｱ											 */
	/*****************************************************************/
	register	TPCTPSZ *pctp;			/* PCT ｺﾍﾞﾂﾌﾞ ﾎﾟｲﾝﾀ 		 */
				char	pname[sizeof(mopcbp->mopscstp->tcsterrp)+1];
										/* 故障管理ﾌﾟﾛｾｽ名    (TD00) */
	register	long	eventno;		/* ﾄﾞｳｷﾏﾁ ﾖｳ ｲﾍﾞﾝﾄ ﾊﾞﾝｺﾞｳ	 */
	register	long	rcode;			/* ﾘﾀ-ﾝｺ-ﾄﾞ ｴﾘｱ 			 */
	register	long	mbid;			/* ｿｳｼﾝｻｷ ﾒｲﾙﾎﾞｯｸｽ ID		 */
	register	long	rtn;			/* ﾄｳｶﾞｲ ｶﾝｽｳ ｶﾗﾉ ﾍﾝｷｬｸﾁ ｴﾘｱ */
				long	*buff;			/* ﾊﾞｯﾌｧ ｶｸﾄｸ ﾖｳ ﾜ-ｸｴﾘｱ 	 */
	register	MCMIKYO *miap;			/* MIA ﾎﾟｲﾝﾀ 		   (L02) */
	register	MRMERUSE *musep;		/* ﾘﾖｳｼｬ ｲｷ ﾎﾟｲﾝﾀ	   (L02) */
	register	long	blen;			/* ﾃﾞﾝﾌﾞﾝ ﾁｮｳ		   (L02) */
				long	mrlog[3];
				long	puno;			/* mr_cgbfの引数	  (TD59) */
				oseprinf	prinfp;		/* ﾌﾟﾛｾｽ情報格納域    (TD59) */
	/*****************************************************************/
	/*	PRC-005-09  修正 START 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
	register	MRMUMK34_U muinf;		/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ ﾎﾟｲﾝﾀ		 */ /* PRC-005-09 */
	/*****************************************************************/
	/*	PRC-005-09  修正 END 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/

	PRINT0("*** mr_ejrq(type,len,detail) invoked ***\n");
	PRINT1("            type   = 0x%02x\n",type);
	PRINT1("            len    = %d\n",len);
	PRINT1("            detail = %s\n",detail);
	/*****************************************************************/
	/*	  ﾖﾋﾞﾀﾞｼ ｼﾞｮｳｷｮｳ ｦ ﾁｪｯｸ ｽﾙ									 */
	/*****************************************************************/
	/* MRWLOG削除 （3行）									 		(TD50) */
	mrlog[0] = (long) type;
	mrlog[1] = (long) len;
	mrlog[2] = (long) detail;
	mo_wlg4( MR_EJRQ,WINSC,mrlog,12L ); /*					  (TD50) */
    /*
　　/************************************************************************/
	/*	  システム構成のチェック                                     (TD00) */
	/************************************************************************/
	if ( (mopcbp->mopssstp->tsstsysc == 'H')
		&&(mopcbp->mopssstp->tsstsysd == 'F') )
										/* ｼｽﾃﾑ構成情報がﾎｯﾄｽﾀﾝﾊﾞｲ   (TD02) */
										/* かつﾌﾞﾛｯｸ区分が予備系の　 (TD02) */
										/* 時                        (TD02)	*/
	{
		mr_sabt( MREEJRQ,MRDEHOTWAIT ); /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ　　　			 (TD02) */
	}                                   /*                           (TD02) */
	
	if ( len <= 0 ) {					/* ﾃﾞ-ﾀﾁｮｳ ｼﾝﾀｯｸｽ ﾁｪｯｸ		 */
		rtn = MRIVPARM;
		goto error;
	}
	else;
	if ( ( mopcbp->mopssrtp->tsrtdvst == TSRTEND ) ||			/*	ST4395	*/
		 ( mopcbp->mopssrtp->tsrtdvst == TSRTQST ) ){ 	/* ｼｽﾃﾑ ｼｭｳﾘｮｳﾁｭｳ 	*/
		rtn = MRETERM;
		goto error;
	}
	else;
	if ( pscparea.pscpctno == 0 ) {		/* ﾖﾋﾞﾀﾞｼﾓﾄ ﾏｽﾀｽｹｼﾞｭｳﾗ ｶ ?	 */
		mr_sdwn( MRSTART,MREEJRQ,MRDMSCALL );
	}
	else								/*                           (TD59) */
	{                                   /*                           (TD59) */
		if (1 == pscparea.pscpctno )    /* 呼出元がｻﾌﾞﾏｽﾀｽｹｼﾞｭｰﾗか?  (TD59) */
		{                               /*                           (TD59) */
			mr_sdwn( MRSTART,MREEJRQ,MRDSMSCALL );
			                            /* ﾒﾓﾘ再開始のｼｽﾃﾑﾀﾞｳﾝ       (TD59) */
		}                               /*                           (TD59) */
	}                                   /*                           (TD59) */
	
	/*****************************************************************/
	/*	 TPCT個別部ｱﾄﾞﾚｽの獲得						 　　　　　　　　*/
	/*****************************************************************/
	mc_copy( mopcbp->mopscstp->tcsterrp,/* 故障管理ﾌﾟﾛｾｽ識別名を複写 (TD00) */
			 pname,
			 (long)sizeof(mopcbp->mopscstp->tcsterrp) );
	pname[sizeof(mopcbp->mopscstp->tcsterrp)] = '\0';

	pctp = mr_cpct( pname );
	
	/************************************************************************/
	/*	  ﾌﾟﾛｾｽ存在ﾁｪｯｸ				　     　		 　　　　　　　　		 */
	/************************************************************************/
	mrlog[0] = pctp->tpctpid;			/*							 (TD50) */
	mrlog[1] = (long)&prinfp;			/*							 (TD50) */
	mo_wlg4(MR_EJRQ,WBSYS | OSGTPIN,mrlog,8L);
										/*							 (TD50) */
	if ( osgtpin( pctp->tpctpid,&prinfp ) != NORMAL )
	                                    /* 故障管理ﾌﾟﾛｾｽが存在するか?(TD59) */
	{
		mo_wlg4(MR_EJRQ,WASYS | OSGTPIN,(long *)0,0L);	
										/*							 (TD50) */
		mr_sdwn( MRDOWN,MREEJRQ,MRDNOMRH );
										/* ﾒﾓﾘ再開始なしのｼｽﾃﾑﾀﾞｳﾝ　 (TD59) */
	}
	mo_wlg4(MR_EJRQ,WASYS | OSGTPIN,(long *)0,0L);
										/*							 (TD50) */

	/* PUの独立化対応の為削除（14行）　　　　　　　　　　　　　　    (TD59) */

    /************************************************************************/
	/*	  ﾌﾟﾛｾｽ状態チェック					 　　　　　　　　 		 (TD59) */
	/************************************************************************/
	switch ( pctp->tpctsts ) {			/* ﾌﾟﾛｾｽ ｼﾞｮｳﾀｲ ﾉ ﾁｪｯｸ		 */
	case TPCTING :
	case TPCTSUS :
		break;
	default :
		mr_sdwn( MRSTART,MREEJRQ,MRDERRPDEAD );
	}
	mbid = pctp->tpctpmb;
	eventno = mopcbp->mopscstp->tcstevnt;

	/* MRWLOG削除（3行）									　　	 (TD50) */
	mrlog[0] = eventno;
	mo_wlg4( MR_EJRQ,WBSYS | OSSNSEV,mrlog,4L );
										/*							 (TD50) */

	rcode = ossnsev( eventno );			/* ｲﾍﾞﾝﾄ ﾉ ｼﾞｮｳﾀｲ ｦ ｼｭﾄｸ ｽﾙ	 */
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
	
	/*			不要なロジックのため削除							 (TD00) */
	
	blen = (long)(sizeof(MCMIKYO)+sizeof(MRMERUSE)+len);	/* (L02) */
	if( 0 == pscparea.pscpuno ){		/* 自プロセスがＰＵ０の時 	 (TD59) */
		puno = 1;						/* mr_cgbfの引数に１を設定   (TD59) */
	}									/*							 (TD59) */
	else								/*							 (TD59) */
	{									/* 							 (TD59) */
		if( 1 == pscparea.pscpuno ){	/* 自プロセスがＰＵ１の時    (TD59) */
			puno = 0;					/* mr_cgbfの引数に０を設定	 (TD59) */
		}								/*							 (TD59) */
	}									/* 							 (TD59) */
	rcode = mr_cgbf( puno,		/* ﾒｯｾ-ｼﾞ ｿｳｼﾝﾖｳ ﾊﾞｯﾌｧ ﾉ ｶｸﾄｸ  (L02) (TD59) */
					 blen,									/* (L02) */
					 &buff );

	if ( rcode >= blen ) { 				/* ｼﾃｲﾚﾝｸﾞｽ ﾌﾞﾝ ｱｯﾀﾄｷ  (L02) */
	}
	else if ( rcode == MRNOMEM ) {		/* ﾒﾓﾘ-ﾌﾞｿｸ ﾉ ﾄｷ	   (L02) */
		rtn = MRNOMEM;
		mrlog[0] = rcode;
		mo_wlg4( MR_EJRQ,0x33331000L,mrlog,4L );
										/*							 (TD50) */
		goto error;
	}
	else {								/* TRADE ｼｽﾃﾑｺ-ﾙ ｴﾗ- ﾉ ﾄｷ    (TD00) */
		rtn = MCEOSERR;
		mrlog[0] = rcode;
		mo_wlg4( MR_EJRQ,0x33331001L,mrlog,4L );
										/*							 (TD50) */
		goto error;
	}
	miap = ( MCMIKYO * ) buff;								/* (L02) */
	musep = ( MRMERUSE * )( (char *)miap+sizeof(MCMIKYO) );	/* (L02) */
	
	/*****************************************************************/
	/*	  ｿｳｼﾝ ﾒｯｾ-ｼﾞ ｦ ﾍﾝｼｭｳ ｽﾙ									 */
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
	/*	PRC-005-09  修正 START 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
	muinf.mrmumk_s.mrmumk3  = htons(MRMUIRMAN);							/* PRC-005-09 */
	musep->mrmeuse.mrmumk34 = ntohl(muinf.mrmumk_l);					/* PRC-005-09 */
	/*****************************************************************/
	/*	PRC-005-09  修正 END 										 */
	/*  エンディアン問題対応  バイト反転							 */
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
	/*	 ﾒｯｾｰｼﾞの送信											            */
	/************************************************************************/
	/* MRWLOG削除 （3行）											 (TD50) */
	mrlog[0] = mbid;					/* 							 		*/
	mrlog[1] = blen;					/*                     		  (L02) */
	mrlog[2] = (long) ( (char *) miap );
	             						/*          		   		  (L02) */
	mo_wlg4( MR_EJRQ,WBSYS | OSSENMSP,mrlog,12L );
		                            	/* 							 (TD50)	*/
		
	rcode = ossenmsp( mbid,     		/* 故障管理ﾌﾟﾛｾｽへの		 (TD00) */
					  blen,				/* ﾒｯｾｰｼﾞ送信          		  (L02) */
					  (char *) miap );
							            /*                            (L02) */
	mrlog[0] = rcode;					/*          		   		 (TD50) */
	mo_wlg4( MR_EJRQ,WASYS | OSSENMSP,mrlog,4L );
		                            	/* 							 (TD50)	*/
	if ( rcode != NORMAL )          	/* 正常に送信出来なかった時　		*/
	{                               	/* 							   		*/
		rtn = MCEOSERR;
		MROSERR( MCEOSSENMSP,rcode );

		mrlog[0] = SYSNG2;				/*							 (td50) */
		mo_wlg4( MR_EJRQ,WNGSC,mrlog,4L );
										/*							 (TD50) */
		rcode = mo_frbf( buff );		/* STC569 87-12-24     		  (L01) */
		if ( rcode != MONORMAL )		/* ﾌﾟｰﾙﾊﾞｯﾌｧ ｶｲﾎｳ	   		  (L01) */
		{
			mrlog[0] = rcode;			/* ﾛｸﾞ ｼﾞｮｳﾎｳ		   		  (L01) */
			mo_wlg4( MR_EJRQ,0x33331002L,mrlog,4L );
			                    		/* ﾛｸﾞ取得             		 (TD50) */
			mr_sabt( MREEJRQ,MRDFBUFERR );
			                    		/* ﾌﾟﾛｾｽ ｱﾎﾞｰﾄ	       		  (L01) */
		}								/*                     		  (L01) */
		else;							/* STC569 87-12-24	   		  (L01) */

		goto error;
	}
	else;
	
	/************************************************************************/
	/*	 ｲﾍﾞﾝﾄの待ち合わせ 								              		*/
	/************************************************************************/
	/* MRWLOG削除 （3行）											 (TD50) */
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

	/*			不要なロジックのため削除							 (TD00) */

	/* MRWLOG削除 （3行）											 (TD50) */	
	mrlog[0] = MRNORMAL;
	mo_wlg4( MR_EJRQ,WOTSC,mrlog,4L );
										/*							 (TD50) */

	return( MRNORMAL );
error:
	/*			不要なロジックのため削除						     (TD00) */

	/* MRWLOG削除 （3行）											 (TD50) */	
	mrlog[0] = rtn;
	mo_wlg4( MR_EJRQ,WOTSC,mrlog,4L );
										/*							 (TD50) */
	PRINT1("*** mr_ejrq end return code = %ld ***\n",rtn);


	return( rtn );



/*********************************************************************/
/*	03-26-2003 NOP関数に変更	START								 */
/*********************************************************************/	
#endif	
	
	return(MRNORMAL);

/*********************************************************************/
/*	03-26-2003 NOP関数に変更	END									 */
/*********************************************************************/
		
}
