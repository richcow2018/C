/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞﾊﾟｯｹｰｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ														 */
/*		ﾌﾟﾛｾｽ ｼｮｷｶ / ｼｭｳﾘｮｳ ｼｮﾘ										 */
/*																	 */
/*  3 ｶﾝｽｳ ﾒｲ													 	 */
/*		mr_ptbl														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ 													 */
/*		ﾘｶﾊﾞﾘ ｻﾝｼｮｳ ﾃｰﾌﾞﾙ ﾉ ｱﾄﾞﾚｽ ﾉ ｾｯﾃｲ	 						 */
/*		ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ ﾃｰﾌﾞﾙ ﾉ ｱﾄﾞﾚｽ ﾉ ｾｯﾃｲ	 						 */
/*																	 */
/*	5 ﾊﾟﾗﾒｰﾀ														 */
/*		ﾅｼ															 */
/*																	 */
/*	6 ﾍﾝｷｬｸﾁ														 */
/*		MRNORMAL	:	ｾｲｼﾞｮｳ										 */
/*		MRTBLERR	:	必要なﾃｰﾌﾞﾙがない					TD-00	 */
/*																	 */
/*  7 ﾘﾚｷ															 */
/*	 	ｾｯｹｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 											 */
/*	 	ｻｸｾｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 				'86/07/16					 */
/*	 	ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				' (WLOG)			 */
/*	 	ﾍﾝｺｳｼｬ : ﾏﾂｼﾀ ｴｲｼﾞ				'87/09/24 (L01)				 */
/*			 	 (ｲｯﾊﾟﾝ ﾌｧｲﾙ ｿｳｻ ﾓｰﾄﾞ ｼﾝｾﾂ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- STC357	 */
/*	 	ﾍﾝｺｳｼｬ : ｽｽﾞｷ ｵｻﾑ 				'87/09/28 (L02)				 */
/*			 	 (ｵｲｶｹ ﾘｶﾊﾞﾘ ｶﾝﾚﾝ ｷﾉｳ ﾉ ｻｸｼﾞｮ)          --- STC395	 */
/*		ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				' (L03)				 */
/*			 	 (AP ﾌﾞﾝｻﾝ ﾀｲｵｳ ﾉ ｶｲｿﾞｳ) 				--- STC448	 */
/*		ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				'88/06/16 (L04)				 */
/*			 	 (ﾎﾘｭｳ ﾃﾞ-ﾀ ｼｭﾄｸ ｶﾝﾚﾝ ｷﾉｳ ﾉ ｻｸｼﾞｮ) --- TC1350		 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		ﾍﾝｺｳｼｬ : 渡邉　基樹				'93/11/04					 */	
/*														   TD-@1	 */
/*														   TD-00	 */
/*				 （JNLｱｸｾｽ時間短縮の変更に伴う修正）	   TD-41	 */
/*				 （ログの見直しに伴う修正）				   TD-50	 */
/*				 （ＰＵの独立化の変更に伴う修正）		   TD-59 	 */
/*				 （SCSIﾘｾｯﾄ機能の変更に伴う修正）		   TD-61 	 */
/*				 （ﾘｶﾊﾞﾘ不要時VRCVの変更に伴う修正）	   TD-76  	 */
/*		変更者 : 杉岡  克也				'95/04/05 --- CT1010(ST2495) */
/*		変更者 : 杉岡  克也				'95/05/02 --- CT1039(ST2764) */
/*				 （SCSIﾘｾｯﾄ機能の変更に伴う修正）		   TD-61 	 */
/*		変更者 : 杉岡  克也				'95/09/11 --- ST3249		 */
/*																	 */
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
/*  ｲﾝｸﾙｰﾄﾞ ﾌｧｲﾙ													 */
/*********************************************************************/
#include	"tcom.h"
#include	"mrcom.h"
#include	"mrmac.h"
#include	"mr.h"
#include	"ttct.h"
#include	"tsst.h"
#include	"tcst.h"
#include	"tadt.h"
#include	"tpct.h"
#include	"tbpt.h"
#include	"tsrt.h"
/*********************************************************************/
/*	KL0004  修正 START 												 */
/*  TABP関連情報削除(tabp.h)										 */
/*********************************************************************/
/*********************************************************************/
/*	KL0004  修正 END 												 */
/*  TABP関連情報削除(tabp.h)										 */
/*********************************************************************/
#include	"tbkt.h"					/* 						TD@1 */
#include	"tjct.h"					/* 						TD@1 */
#include	"psect.h"					/* 						TD@1 */
#include	"mf.h"						/* 						TD@1 */
#include	"mrj.h"
#include	"mopcb.h"
#include	"mo_wlg.h"					/*						TD50 */
#include	"mcdebug.h"
										/* 未使用のため mcdebug.h を */
										/* 削除する 1行         TD@1 */
									
																  /*%*/
/*********************************************************************/
/*  ｶﾞｲﾌﾞ ﾍﾝｽｳ ﾘｮｳｲｷ 												 */
/*********************************************************************/
extern		PSCPSECT	pscparea;		/* PSECT ﾘｮｳｲｷ				 */
extern		MOPSCPCB	*mopcbp;		/* MOPSCPCB ﾘｮｳｲｷ			 */

/*********************************************************************/
/*	ﾃﾞﾌｧｲﾝ ﾁ 														 */
/*********************************************************************/
#define		MRRSTNO		0x00008000L		/* ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｻｸｾｲ ﾖｳ  		 */
#define		MRIDSIZE	4				/* MRPCB ｼｷﾍﾞﾂﾒｲ	 		 */
#define		MRID		"RPB "			/* MRPCB ｼｷﾍﾞﾂﾒｲ	 		 */
										/* MRSSTT 未使用のため削除	 */
#define		CM			0L				/* ｺﾓﾝﾒﾓﾘ			    TD59 */
#define		LM			1L				/* ﾛｰｶﾙﾒﾓﾘ			    TD59 */
#define		MRNO		mopcbp->mopssstp->tsstsysd		   	 /* TD01 */
#define		MRCMADT		pscparea.psccmadt				   	 /* TD59 */
#define		MRLMADT		pscparea.psclmadt			    	 /* TD59 */
										/* MRWLOG削除(1行)		TD50 */
#define		TTCTIDX 	0				/* TTCT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ		 */
#define		TJCTIDX 	1				/* TJCT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ		 */
#define		TBKTIDX 	2				/* TBKT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ		 */
#define		TTDTIDX 	3				/* TTDT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ  (L04) */
#define		TSSTIDX 	4				/* TSST ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ  (L04) */
#define		TRCTIDX 	5				/* TRCT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ  (L04) */
#define		TPBTIDX 	6				/* TPBT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ  (L04) */
#define		TVBTIDX 	7				/* TVBT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ  (L04) */
#define		TRBTIDX 	8				/* TRBT ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ   TD59 */
#define		TSURIDX 	9				/* TSUR ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ   TD61 */
#define		TSBRIDX    10				/* TSBR ﾃ-ﾌﾞﾙ ｲﾝﾃﾞｯｸｽ   TD61 */

/*********************************************************************/
/*	define function name for mo_wlg4						TD-50	 */
/*********************************************************************/
#define	MR_PTBL	0x6d725f70,0x74626c20

long	mr_ptbl()						/* ﾃｰﾌﾞﾙ ｱﾄﾞﾚｽ ｾｯﾃｲ ｼｮﾘ		 */
{
	/*****************************************************************/
	/*  mr_ptbl ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	long	mc_clea();					/* ｸﾘｱ ｦ ｽﾙ					 */
	long	mc_ccom();					/* ﾓｼﾞﾚﾂ ﾋｶｸ 		 		 */
	long	mc_copy();					/* ﾓｼﾞﾚﾂ ｺﾋﾟｰ 		 		 */
	void	mo_wlg4();					/* Sﾄﾚｰｽ情報の取得		TD50 */

	/*****************************************************************/
	/*	03-24-2003  修正 START 										 */
	/*  mr_cpct2を使用している個所をｺﾒﾝﾄ   					 		 */
	/*****************************************************************/
	//TPCTPSZ	*mr_cpct2();			/* TPCT個別部ｱﾄﾞﾚｽ獲得CT1039 */

	/*****************************************************************/
	/*	03-24-2003  修正 END 										 */
	/*  mr_cpct2を使用している個所をｺﾒﾝﾄ   					 		 */
	/*****************************************************************/

	/*****************************************************************/
	/*  ﾃｰﾌﾞﾙ ｹﾝｻｸﾖｳ ﾃｰﾌﾞﾙ 								 			 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*	03-24-2003  修正 START 										 */
	/*  TSURとTSBR関連の処理を削除する    					 		 */
	/*****************************************************************/
	
	static	struct	mrpidx	{
		char		*mrptbln;			/* ｹﾝｻｸ ｽﾙ ﾃｰﾌﾞﾙ ﾒｲ			 */
		TCOMPAT		**mrptbsa;			/* ﾃｰﾌﾞﾙ ｱﾄﾞﾚｽ ｾｯﾃｲ ｱﾄﾞﾚｽ	 */
		long		*mrprsta;			/* ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ ｾｯﾃｲ ｱﾄﾞﾚｽ	 */
		long		mrpcmlm;			/* CM･LM情報		    TD59 */
	} idx[] = {	{"TTCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TJCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TBKT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TTDT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TSST", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TRCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TPBT", 	(TCOMPAT **)0, (long *)0, LM },
										/* 				  (L03) TD59 */
				{"TVBT", 	(TCOMPAT **)0, (long *)0, CM },
										/* 				  (L03) TD59 */
				{"TRBT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				//{"TSUR", 	(TCOMPAT **)0, (long *)0, CM },  
										/* 				 TD59 CT1039 */
				//{"TSBR", 	(TCOMPAT **)0, (long *)0, LM },  /* TD59 */
				{(char *)0, (TCOMPAT **)0, (long *)0 } };
										/*						TD59 */
	
	/*****************************************************************/
	/*	03-24-2003  修正 END 										 */
	/*  TSURとTSBR関連の処理を削除する    					 		 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*  mr_ptbl ﾅｲ ﾜｰｸ ｴﾘｱ									 		 */
	/*****************************************************************/
	register	long		retcd;		/* ﾘﾀｰﾝﾁ ｶｸﾉｳ ｴﾘｱ			 */
	register	TADTPSZ		*tadtp;		/* ADT ｺﾍﾞﾂﾌﾞ ｱﾄﾞﾚｽ ﾎﾟｲﾝﾀ	 */
	register	TADTPSZ		*tp;
	register	TCOMPAT		*tblp;		/* ﾃｰﾌﾞﾙ ｾﾝﾄｳ ｱﾄﾞﾚｽ			 */
	register	long		pszno;		/* ADT ｺﾍﾞﾂﾌﾞ ｶｳﾝﾀ	 		 */
	register	int			efen;		/* ｶｳﾝﾀ						 */
	register	struct 		mrpidx	*idxp;	/* ｹﾝｻｸﾖｳﾃｰﾌﾞﾙ ﾎﾟｲﾝﾀ	 */
				long		rstno;		/* ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ ｻｸｾｲ ｴﾘｱ		 */

				void		(*dfunc)();	/* modified for bug			 */
				long		mrlog[1];	/* ﾛｸﾞ ｼﾞｮｳﾎｳ ﾍﾝｼｮｳ ﾘｮｳｲｷ	 */
				TCOMPAT		*padt;		/* ADT先頭ｱﾄﾞﾚｽ			TD59 */
				TPCTPSZ		*pctp;		/* PCT個別部ｱﾄﾞﾚｽ	CT1039   */
				int			i;		    /* ﾃｰﾌﾞﾙ存在ﾁｪｯｸ時使用	TD@1 */
				int			no;		    /* ﾌﾞﾛｯｸ番号			TD01 */

	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWLOG削除 3行		TD50 */
	mo_wlg4(MR_PTBL,WINSC,(long *)0,0L);/*						TD50 */

	/*****************************************************************/
	/*  ｼｮｷｾｯﾃｲ ｦ ｵｺﾅｳ 		 										 */
	/*****************************************************************/
	PRINT0("**  mr_ptbl  Start  **\n");
										/* ADTﾎﾟｲﾝﾀ取得 削除    TD59 */
										/* MRPCB,MRJCF ﾎﾟｲﾝﾀｾｯﾃｲ	 */
	mrpcbp = (MRPCB *)pscparea.pscmrpcb;
	mrjcfp = (MRJCF *)pscparea.pscmrjcf;
										/* MRPCB ﾉ ｼｮｷｾｯﾃｲ 			 */
	dfunc = mrpcbp->mrpsexf;			/* modified for bug			 */

	mc_copy(MRID,
			mrpcbp->mrpcbid,
			4L);
	mc_clea((char *)((char *)mrpcbp + MRIDSIZE),
			0,
			(long)(sizeof(MRPCB) - MRIDSIZE));

	mrpcbp->mrpsexf = dfunc;			/* modified for bug			 */

	PRINT1("**  mr_ptbl tsstsysc = %c  **\n",mopcbp->mopssstp->tsstsysc);
	/*****************************************************************/
	/*	03-24-2003  修正 START 										 */
	/*  コールドスタンバイ構成のルートを削除する		 			 */
	/*****************************************************************/
#ifdef LINUX_ISOKUTAIOU
	
	if(mopcbp->mopssstp->tsstsysc == 'C'){	/* ｺｰﾙﾄﾞｽﾀﾝﾊﾞｲ時    TD01 */	
		if(MRNO <= '9'){				    /* ﾌﾞﾛｯｸ区分算出	TD01 */
			no = MRNO - '0';				/* 					TD01 */
		}									/* 					TD01 */
		else{								/*					TD01 */
			no = MRNO - 'A' + 10;			/* 					TD01 */
		}									/* 					TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[no];	 
										/* ﾌﾟﾛｸﾞﾗﾑﾓｰﾄﾞ設定		TD01 */
		PRINT1("** mr_ptbl tsstprmd[ %d ]  **\n",no);
	}									   	/* 					TD01 */
	else{								/* ｼﾝﾌﾟﾚｯｸｽ,ﾎｯﾄｽﾀﾝﾊﾞｲ時 TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[0];
	}								   	/* ﾌﾟﾛｸﾞﾗﾑﾓｰﾄﾞ設定		TD01 */

#endif	

	if(mopcbp->mopssstp->tsstsysc != 'C')
	{
										/* ｼﾝﾌﾟﾚｯｸｽ,ﾎｯﾄｽﾀﾝﾊﾞｲ時 TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[0];
	}								   	/* ﾌﾟﾛｸﾞﾗﾑﾓｰﾄﾞ設定		TD01 */


	/*****************************************************************/
	/*	03-24-2003  修正 END 										 */
	/*  コールドスタンバイ構成のルートを削除する		 			 */
	/*****************************************************************/
	
	PRINT1("**  mr_ptbl mrppgmd( 0x%08x ) Set  **\n",mrpcbp->mrppgmd);

	/*****************************************************************/
	/*	ﾘｶﾊﾞﾘ / ｵｲｶｹ ﾘｶﾊﾞﾘ ﾖｳ/ﾌﾖｳ ｼﾞｮｳﾎｳ ﾉ ｾｯﾃｲ						 */
	/*****************************************************************/
	if( ((mrpcbp->mrppgmd & 0x0000000FL)	/* ﾃﾞﾊﾞｯｸﾞ		   (L01) */
						== 0x0000000FL) ||	/* ﾓｰﾄﾞ			   (L01) */
		((mrpcbp->mrppgmd & 0x0000000FL)	/* ｲｯﾊﾟﾝ ﾌｧｲﾙ	   (L01) */
						== 0x0000000DL) ){	/* ｿｳｻ ﾓｰﾄﾞ		   (L01) */
		mrpcbp->mrpnsrc = MRPNRUEC;
	}
	else {
		if (mopcbp->mopscstp->tcstrnui==TCSTRNEC) {
			mrpcbp->mrpnsrc = MRPNRNEC;
		}
		else {
			mrpcbp->mrpnsrc = MRPNRUEC;
		}
	}
										/* MRJCF ﾉ ｼｮｷｾｯﾃｲ 			 */

	mc_clea((char *)mrjcfp,
			0,
			(long)(sizeof(MRJCF)));
	mrjcfp->mrjcfd1 = -1L;			    /* JNL fd の初期化		TD41 */
	mrjcfp->mrjcfd2 = -1L;			    /* KJ  fd の初期化		TD41 */
	mrjcfp->mrjcfd3 = -1L;			    /* 前日KJ fd の初期化	TD41 */

	/*****************************************************************/
	/* ﾃｰﾌﾞﾙｱﾄﾞﾚｽ ｾｯﾃｲ ｱﾄﾞﾚｽ / ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｾｯﾃｲ ｱﾄﾞﾚｽ ﾉ ｾｯﾃｲ			 */
	/*****************************************************************/
	/************************************/
	/* SCSIﾘｾﾂﾄﾌﾟﾛｾｽ個別部ｱﾄﾞﾚｽ			*/
	/************************************/
	
	/*****************************************************************/
	/*	03-24-2003  修正 START 										 */
	/*  SCSIﾘｾﾂﾄﾌﾟﾛｾｽ個別部を求める処理を削除			 			 */
	/*****************************************************************/

#ifdef LINUX_ISOKUTAIOU

	pctp = mr_cpct2( "CE", 0 );			/*					CT1039	 */
	if ( pctp == ( TPCTPSZ* )0L )		/*					CT1039   */
	{									/* PU0には未存在	ST3249	 */
		pctp = mr_cpct2( "CE", 1 );		/*					ST3249	 */
		if ( pctp == ( TPCTPSZ* )0L )	/*					ST3249	 */
		{								/* 該当個別部なし	CT1039   */
			mo_wlg4(MR_PTBL,0x33331002L,(long*)0,0L);
										/* mr_cpct2ｴﾗ-時点  CT1039	 */
			goto	error;				/*					CT1039   */
		}								/*					ST3249	 */
		else;							/*					ST3249	 */
	}
	
#endif	

	/*****************************************************************/
	/*	03-24-2003  修正 END 										 */
	/*  SCSIﾘｾﾂﾄﾌﾟﾛｾｽ個別部を求める処理を削除			 			 */
	/*****************************************************************/

	
	for (idxp=idx; idxp->mrptbln!=(char *)0; idxp++){
		idxp->mrptbsa = (TCOMPAT **)0;
		idxp->mrprsta = (long *)0;
	}

	idx[TRCTIDX].mrptbsa = &(mrpcbp->mrprcta);		 	     /* TD59 */
	idx[TSSTIDX].mrprsta = &(mrpcbp->mrpsstn);

	/*****************************************************************/
	/*	03-24-2003  修正 START 										 */
	/*  TSURとTSBR関連の処理を削除する    					 		 */
	/*****************************************************************/

#ifdef LINUX_ISOKUTAIOU

	idx[TSURIDX].mrptbsa = &(mrpcbp->mrpsura);		 	     /* TD61 */

	idx[TSURIDX].mrprsta = &(mrpcbp->mrpsurn);		 	     /* TD61 */
	
	if ( pscparea.pscpuno == pctp->tpctpuno )			/*	CT1039   */
	{									/* mrgと同一PUの時	CT1039   */
		idx[TSBRIDX].mrptbsa = &(mrpcbp->mrpsbra);	 	     /* TD61 */
		idx[TSBRIDX].mrprsta = &(mrpcbp->mrpsbrn);		     /* TD61 */
	}									/*					CT1039   */

#endif
	
	/*****************************************************************/
	/*	03-24-2003  修正 END 										 */
	/*  TSURとTSBR関連の処理を削除する 					 			 */
	/*****************************************************************/
	
	
	idx[TRCTIDX].mrprsta = &(mrpcbp->mrprctn);		 	     /* TD59 */
	PRINT1("*** mr_ptbl(mrpssta)= 0x%08x  ***\n",idx[TSSTIDX].mrptbsa);
//	PRINT1("*** mr_ptbl(mrpsura)= 0x%08x  ***\n",idx[TSURIDX].mrptbsa);
//	PRINT1("*** mr_ptbl(mrpsbra)= 0x%08x  ***\n",idx[TSBRIDX].mrptbsa);
	PRINT1("*** mr_ptbl(mrprcta)= 0x%08x  ***\n",idx[TRCTIDX].mrptbsa);
	PRINT1("*** mr_ptbl(mrpsstn)= 0x%08x  ***\n",idx[TSSTIDX].mrprsta);
//	PRINT1("*** mr_ptbl(mrpsurn)= 0x%08x  ***\n",idx[TSURIDX].mrprsta);
//	PRINT1("*** mr_ptbl(mrpsbrn)= 0x%08x  ***\n",idx[TSBRIDX].mrprsta);
	PRINT1("*** mr_ptbl(mrprctn)= 0x%08x  ***\n",idx[TRCTIDX].mrprsta);
										/* CT1010					 */

	if (mrpcbp->mrpnsrc == MRPNRNEC){	/* CSTﾘｶﾊﾞﾘ ﾖｳ ﾀﾞｯﾀﾗ?		 */
		idx[TTCTIDX].mrptbsa = &(mrpcbp->mrptcta);
		idx[TJCTIDX].mrptbsa = &(mrpcbp->mrpjcta);
		idx[TRBTIDX].mrptbsa = &(mrpcbp->mrprbta);		     /* TD59 */
		idx[TBKTIDX].mrptbsa = &(mrpcbp->mrpbkta);
		idx[TTCTIDX].mrprsta = &(mrpcbp->mrptctn);
		idx[TTDTIDX].mrprsta = &(mrpcbp->mrptdtn);
	}
										/* ﾊﾞｯｸｱｯﾌﾟ ﾖｳ ﾀﾞｯﾀﾗ ?		 */
	if (mopcbp->mopscstp->tcstbnui == TCSTBNEC){		    /* (L03) */
		idx[TPBTIDX].mrptbsa = &(mrpcbp->mrppbta);			/* (L03) */
		idx[TVBTIDX].mrptbsa = &(mrpcbp->mrpvbta);			/* (L03) */
		idx[TPBTIDX].mrprsta = &(mrpcbp->mrppbtn);			/* (L03) */
		idx[TVBTIDX].mrprsta = &(mrpcbp->mrpvbtn);			/* (L03) */
	}														/* (L03) */

	/*****************************************************************/
	/*  ADT ﾖﾘ ｶﾞｲﾄｳ ﾃｰﾌﾞﾙ ｦ ｹﾝｻｸ ｽﾙ   					 			 */
	/*****************************************************************/
										/* ｹﾝｻｸｽﾙﾃｰﾌﾞﾙﾒｲ ﾃﾞ ﾌﾘﾜｹﾙ	 */
	for (idxp=idx; idxp->mrptbln!=(char *)0; idxp++) {
										/* ｹﾝｻｸ ｽﾙ ｶ ﾄﾞｳｶ ﾁｪｯｸ ｽﾙ	 */
		if (idxp->mrptbsa == (TCOMPAT **)0
		 && idxp->mrprsta == (long *)0){
			continue;
		}
		else;
										/* ADTﾖﾘｶﾞｲﾄｳﾃｰﾌﾞﾙ ｦ ﾐﾂｹﾙ	 */
		if(idxp->mrpcmlm == CM){							 /* TD59 */
			tadtp = (TADTPSZ *)MRTBLAD(MRCMADT, 1);			 /* TD59 */
			padt = MRCMADT;									 /* TD59 */
			efen = MRCMADT->tcomefen;						 /* TD59 */
		}													 /* TD59 */
		else{												 /* TD59 */
			tadtp = (TADTPSZ *)MRTBLAD(MRLMADT, 1);			 /* TD59 */
			padt = MRLMADT;									 /* TD59 */
			efen = MRLMADT->tcomefen;						 /* TD59 */
		}													 /* TD59 */
		PRINT2(" *  mr_ptbl Sarch TableName = %s  *\n *  mr_ptbl Sarch CM(0) or LM(1) = %d  *\n",
				idxp->mrptbln, idxp->mrpcmlm);

		for (pszno=1; pszno <= efen; tadtp++) {				 /* TD59 */
										/* ﾃｰﾌﾞﾙ先頭ｱﾄﾞﾚｽを求める	 */
			tblp = (TCOMPAT *)((char *)padt + tadtp->tadtadr);
										/* 						TD59 */
										/* 該当ﾃｰﾌﾞﾙは見つかったか?	 */
			PRINT1("*** mr_ptbl(tcomtbid)= %s  ***\n",tblp->tcomtbid);
			PRINT1("*** mr_ptbl(mrptbln)= %s  ***\n",idxp->mrptbln);
										/* CT1010					 */
			retcd = mc_ccom(tblp->tcomtbid,
							idxp->mrptbln,
							4L);
			if (retcd == 0L) {
				/*****************************************************/
				/*  ﾃｰﾌﾞﾙｱﾄﾞﾚｽ.ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｦ ｾｯﾃｲ ｽﾙ					 */
				/*****************************************************/
				if(idxp->mrptbsa != (TCOMPAT **)0) {
										/* ２重定義チェック省略の	 */
										/* ため削除 6行	 		TD@1 */ 
										/* ﾃｰﾌﾞﾙｱﾄﾞﾚｽ ｦ ｾｯﾃｲ ｽﾙ		 */
					*(idxp->mrptbsa) = tblp;
					PRINT1("**  mr_ptbl Set TableAddress( 0x%x ) in MRPCB  *\n",tblp);
				}
										/* ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｦ ｻｸｾｲ ｼ 		 */
										/* 				ｾｯﾃｲ ｽﾙ		 */
				PRINT1("*** mr_ptbl(mrprsta)= 0x%08x  ***\n",idxp->mrprsta);
										/* CT1010					 */
				if(idxp->mrprsta != (long *)0) {
										/* ２重定義チェック省略の	 */
										/* ため削除 6行	 		TD@1 */ 
										/* 資源番号を求め		TD00 */	
										/* 				設定する	 */
					PRINT0("**  mr_ptbl Call mf_rtgt  **\n");
					rstno = mf_rtgt(idxp->mrptbln);		     /* TD@1 */
					if(rstno == MFNOEXIST){		       	     /* TD@1 */
						PRINT0("**  mr_ptbl mf_rtgt  error **\n");
						goto error;			  			     /* TD@1 */
					}			   						     /* TD@1 */
					*(idxp->mrprsta) = rstno;	
					PRINT1("**  mr_ptbl Set SigenNo( 0x%x ) in MRPCB *\n",rstno);
					break;	  							     /* TD@1 */
				}
			}
			else;
			pszno++;
		}
	}

	/*****************************************************************/
	/*  ﾃｰﾌﾞﾙ ｿﾝｻﾞｲ ｴﾗｰ ﾁｪｯｸ 	 						 	   		 */
	/*****************************************************************/
	PRINT0("**  mr_ptbl Table sonnzai check  **\n");
	for(i = 0; idx[i].mrptbln != (char *)0; i++){
										/* ﾃｰﾌﾞﾙｱﾄﾞﾚｽの存在ﾁｪｯｸ TD@1 */
		if(idx[i].mrptbsa == (TCOMPAT **)0){				 /* TD@1 */	
			continue;										 /* TD@1 */	
		}													 /* TD@1 */	
		else{												 /* TD@1 */	
			if (*(idx[i].mrptbsa)==(TCOMPAT *)0){			
				PRINT1("**  mr_ptbl Tableaddress( %s ) Check Error(0)  **\n",idx[i].mrptbln);
				mc_copy(idx[i].mrptbln,(char *)mrlog,4L);
				mo_wlg4(MR_PTBL,0x33331000L,mrlog,4L);		
										/*						TD50 */
				goto error;							
			}									
			else;							
		}													 /* TD@1 */	
	}				 										 /* TD@1 */	

	PRINT0("**  mr_ptbl SigenNo sonnzai check  **\n");
	for(i = 0; idx[i].mrptbln != (char *)0; i++){
										/* 資源番号の存在ﾁｪｯｸ 	TD@1 */
		if(idx[i].mrprsta == (long *)0){					 /* TD@1 */	
			continue;				 						 /* TD@1 */	
		}				 									 /* TD@1 */	
		else{												 /* TD@1 */	
			if (*(idx[i].mrprsta) == 0L){		
				PRINT1("**  mr_ptbl SigenNo( %s ) Check Error(0)  **\n",idx[i].mrptbln);
				mc_copy(idx[i].mrptbln,(char *)mrlog,4L);
				mo_wlg4(MR_PTBL,0x33331001L,mrlog,4L);	
										/* 						TD50 */
				goto error;							
			}									
			else;							
		}				 									 /* TD@1 */	
	}				 										 /* TD@1 */	
										/* 簡略化のため存在ﾁｪｯｸ処理  */
										/* 変更					TD00 */

	/*****************************************************************/
	/*  ﾍﾝｷｬｸﾁ ｦ ｾｯﾃｲ ｽﾙ											 */
	/*****************************************************************/
										/* MRWLOG削除 3行		TD50 */
	PRINT0("**  mr_ptbl Normal End  **\n");		
	mrlog[0] = MRNORMAL;
	mo_wlg4(MR_PTBL,WOTSC,mrlog,4L);
	return(MRNORMAL);

error:
										/* MRWLOG削除 3行		TD50 */
	PRINT0("**  mr_ptbl Error End  **\n");		
	mrlog[0] = MRTBLERR;
	mo_wlg4(MR_PTBL,WOTSC,mrlog,4L);
	return(MRTBLERR);
}
