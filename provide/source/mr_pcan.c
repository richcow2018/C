/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞﾊﾟｯｹｰｼﾞ													 */
/*		RCV															 */
/*																	 */
/*  2 ｶﾝｽｳ ｸﾌﾞﾝ 													 */
/*		ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘ													 */
/*																	 */
/*  3 ｶﾝｽｳ ﾒｲ													 	 */
/*		mr_pcan														 */
/*																	 */
/*  4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		ｼﾞｾﾞﾝ ﾆ ﾄｳﾛｸ ｻﾚﾀ ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘｳｹﾂｹｶﾝｽｳ ｦ ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ｶﾗ		 */
/*		ｶｲﾎｳ ｽﾙ														 */
/*																	 */
/*	5 ﾊﾟﾗﾒｰﾀ														 */
/*		ﾅｼ															 */
/*																	 */
/*	6 ﾍﾝｷｬｸﾁ 														 */
/*		ﾅｼ															 */
/*																	 */
/*  7 ﾘﾚｷ															 */
/*		ｾｯｹｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 											 */
/*		ｻｸｾｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 				'					 */
/*		ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				'		  (WLOG)	 */
/*		ﾍﾝｺｳｼｬ : ｳﾁﾀﾞ ﾕｳｽｹ				'88/08/11		  (L02)		 */
/*				 ( ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ ) --- STC978		 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ)  --- TC1990	 */
/*		変更者 : 佐藤　亘				'93/12/24					 */
/*				 (ログの見直しに伴う修正)					TD-50	 */
/*				 (ｼｽﾃﾑｺｰﾙのｲﾝﾀｰﾌｪｰｽ変更による削除)			TD-95	 */
/*				 (内部事情による変更)						TD-@1	 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*  ｲﾝｸﾙｰﾄﾞ ﾌｧｲﾙ													 */
/*********************************************************************/
#include	"tcom.h"
#include	"tpct.h"
#include	"mrmac.h"
#include	"osexdef.h"
/* #include	"osrstex.h"									*/	/* (L02) */
#include	"mcdebug.h"
#include	"psect.h"
#include	"mo_wlg.h"					/*						TD50 */

/*********************************************************************/
/*	ｶﾞｲﾌﾞ ﾍﾝｽｳ ﾘｮｳｲｷ												 */
/*********************************************************************/
extern	PSCPSECT	pscparea;

/*********************************************************************/
/*	ﾃﾞﾌｧｲﾝ ﾁ 														 */
/*********************************************************************/
#define	MRWLOG	pscparea.pscobaad

/*********************************************************************/
/*	define function name for mo_wlg4						TD-50	 */
/*********************************************************************/
#define	MR_PCAN	0x6d725f70,0x63616e20

void	mr_pcan()
{
	/*****************************************************************/
	/*  mr_pcan ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	
	
	/*****************************************************************/
	/*	2003-02-18  修正 START 										 */
	/*  osrstex()からosrstex2()に変更								 */
	/*****************************************************************/
	//long	osrstex();					/* ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾉ ｶｲｼﾞｮ		 */

	long	osrstex2();					/* ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾉ ｶｲｼﾞｮ		 */
	/*****************************************************************/
	/*	2003-02-18  修正 END 										 */
	/*  osrstex()からosrstex2()に変更								 */
	/*****************************************************************/
	
	void	mo_wlg4();					/* 障害解析情報取得		TD50 */

	/*****************************************************************/
	/*  mr_pcan ﾅｲ ﾜ-ｸ ｴﾘｱ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	register	TPCTPSZ	*tpctp;			/* TPCT ｺﾍﾞﾂﾌﾞ ﾎﾟｲﾝﾀ		 */
				long		mrlog[1];	/* ﾛｸﾞ情報編集領域		TD50 */
				
	/*****************************************************************/
	/*	2003-02-18 追加 START 										 */
	/*****************************************************************/
				long 	lCnt;			/* ループカンウタ			 */
	/*****************************************************************/
	/*	2003-02-18 追加 END 										 */
	/*****************************************************************/	

	PRINT0("mr_pcan() : START\n");
	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWLOG削除 3行		TD50 */
	mo_wlg4(MR_PCAN,WINSC,(long *)0,0L);/*						TD50 */

	/*****************************************************************/
	/*  ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾉ ｶｲｼﾞｮ ｦ ｵｺﾅｳ 									 */
	/*****************************************************************/

	/*****************************************************************/
	/*	ﾌﾟﾛｾｽ終了例外ﾊﾝﾄﾞﾗの解除を、例外ﾊﾝﾄﾞﾗ解除処理の最後尾へ移動	 */
	/*	(削除ｽﾃｯﾌﾟ数 : 4)										TD@1 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*	2003-02-18  修正 END 										 */
	/*  osrstex()はosrstex2()を変更する								 */
	/*  シグナル番号は(1)〜(31)にセットするため例外ハンドラの		 */
	/*  登録する処理を削除											 */
	/*****************************************************************/

	for(lCnt = 1; lCnt < 32; lCnt++) 
	{
										/*				  (L03) TD50 */
		osrstex2(lCnt);				/* ﾌﾟﾛｾｽ ｼｭｳﾘｮｳ ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L03)*/
	}
	
#ifdef LINUX_ISOKUTAIOU
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIBUS;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIBUS);					/* ﾊﾞｽｴﾗｰ   ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIADR;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIADR);					/* ｱﾄﾞﾚｽｴﾗｰ ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIILL;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIILL);					/* ﾌﾄｳ ﾒｲﾚｲ ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIDVD;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIDVD);					/* 0 ｼﾞｮｻﾞﾝ ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */

	/*****************************************************************/
	/*	OSの機能変更に伴い、ｽﾀｯｸ異常に対する例外ﾊﾝﾄﾞﾗの解除を削除	 */
	/*	(削除ｽﾃｯﾌﾟ数 : 6)										TD95 */
	/*****************************************************************/

										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIILK;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIILK);					/* ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ 			(L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXIUSR;				/*						(L02)*/
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*				  (L02) TD50 */
	osrstex(OSEXIUSR);					/* ﾕｰｻﾞﾃｲｷﾞ ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ (L02)*/
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
										/* MRWLOG削除 3行		TD50 */
	mrlog[0] = OSEXITRM;				/*						TD@1 */
	mo_wlg4(MR_PCAN,WBSYS | OSRSTEX,mrlog,4L);
										/*						TD50 */
	osrstex(OSEXITRM);					/* ﾌﾟﾛｾｽ終了例外ﾊﾝﾄﾞﾗ	TD@1 */
	mo_wlg4(MR_PCAN,WASYS | OSRSTEX,(long *)0,0L);
										/*						TD50 */
#endif

	/*****************************************************************/
	/*	2003-02-18  修正 END 										 */
	/*  osrstex()はosrstex2()を変更する								 */
	/*  シグナル番号は(1)〜(31)にセットするため例外ハンドラの		 */
	/*  登録する処理を削除											 */
	/*****************************************************************/

	tpctp = (TPCTPSZ *)MRTBLAD(pscparea.pscpctad,pscparea.pscpctno+1);
	tpctp->tpctpst = 1;					/* ﾆｼﾞｭｳ ﾚｲｶﾞｲ ﾌﾗｸﾞ ｾｯﾃｲ	 */

	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWLOG削除 3行		TD50 */
	mo_wlg4(MR_PCAN,WOTSC,(long *)0,0L);/*						TD50 */
	PRINT0("mr_pcan() : END\n");
}
