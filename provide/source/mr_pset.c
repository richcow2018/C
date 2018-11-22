/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞﾊﾟｯｹｰｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ 													 */
/*		ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘ													 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ														 */
/*		mr_pset														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘ	ｳｹﾂｹｶﾝｽｳ ｦ ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾄ ｼﾃ ﾄｳﾛｸ ｽﾙ 				 */
/*																	 */
/*	5 ﾊﾟﾗﾒｰﾀ														 */
/*		ﾅｼ															 */
/*																	 */
/*	6 ﾍﾝｷｬｸﾁ 														 */
/*		ﾅｼ															 */
/*																	 */
/*	7 ﾘﾚｷ															 */
/*		ｾｯｹｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 											 */
/*		ｻｸｾｲｼｬ : ｺﾐﾔﾏ ｲｸﾖ 				'					 */
/*		ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				'					 */
/*		ﾍﾝｺｳｼｬ : ｳﾁﾀﾞ ﾕｳｽｹ				'		  (L02)		 */
/*				 ( ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ )		---STC978	 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		変更者 : 佐藤　亘				'93/12/24					 */
/*				 (ログの見直しに伴う修正)					TD-50	 */
/*				 (ｼｽﾃﾑｺｰﾙのｲﾝﾀｰﾌｪｰｽ変更による削除)			TD-95	 */
/*				 (内部事情による変更)						TD-@1	 */
/*		変更者 : 杉岡  克也				'					 */
/*				 (ﾛｸﾞ取得方法の誤りに伴う修正)---ST1525				 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	ｲﾝｸﾙｰﾄﾞ ﾌｧｲﾙ													 */
/*********************************************************************/
#include	"tcom.h"
#include	"tpct.h"
#include	"mrmac.h"
#include	"osexdef.h"
#include	"mcdebug.h"
#include	"psect.h"
#include	"mo_wlg.h"					/*						TD50 */

/*********************************************************************/
/*	2003-03-24  修正 START 										     */
/*	osrstex.h を削除												 */
/*********************************************************************/
//#include	"ossetex.h"									/*	   (L02) */

/*********************************************************************/
/*	2003-03-24  修正 START 										     */
/*	osrstex.h を削除												 */
/*********************************************************************/

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
#define	MR_PSET	0x6d725f70,0x73657420

void	mr_pset()
{
	/*****************************************************************/
	/*	mr_pset ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	void	mo_wlg4();					/* 障害解析情報取得		TD50 */
	
	/*****************************************************************/
	/*	2003-03-24  修正 START 										 */
	/*  ossetex()はossetex2()を変更する								 */
	/*  mr_prcv()void型からlong型に変更								 */
	/*  mr_prcx()はmr_prcv()から呼び出しに変更						 */
	/*****************************************************************/
	//long	ossetex();					/* ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾉ ｾｯﾃｲ 		 */
	//void	mr_prcv();					/* ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘ ｳｹﾂｹ ｼｮﾘ		 */
	//void	mr_prcx();					/* ﾌﾟﾛｾｽ ﾚｲｶﾞｲ ｳｹﾂｹ ｼｮﾘ (L02)*/
	
	long	ossetex2();					/* ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ﾉ ｾｯﾃｲ 		 */
	long	mr_prcv();					/* ﾌﾟﾛｾｽ.ﾘｶﾊﾞﾘ ｳｹﾂｹ ｼｮﾘ		 */
	long	mr_prcx();					/* ﾌﾟﾛｾｽ ﾚｲｶﾞｲ ｳｹﾂｹ ｼｮﾘ (L02)*/

	/*****************************************************************/
	/*	2003-03-24  修正 END 										 */
	/*  ossetex()はossetex2()を変更する								 */
	/*  mr_prcv()void型からlong型に変更								 */
	/*  mr_prcx()はmr_prcv()から呼び出しに変更						 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*	mr_pset ﾅｲ ﾜ-ｸ ｴﾘｱ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	register	TPCTPSZ	*tpctp;			/* TPCT ｺﾍﾞﾂﾌﾞ ﾎﾟｲﾝﾀ		 */
				long		mrlog[2];	/* ﾛｸﾞ ｼﾞｮｳﾎｳ ﾍﾝｼｮｳ ﾘｮｳｲｷ	 */
				long		rc;			/* 返却値格納エリア	ST1525   */
				
	/*****************************************************************/
	/*	2003-03-24 追加 START 										 */
	/*****************************************************************/
				long 	lCnt;			/* ループカンウタ			 */
	/*****************************************************************/
	/*	2003-03-24 追加 END 										 */
	/*****************************************************************/	

	PRINT0("mr_pset() : START\n");
	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWOG削除 3行		TD50 */
	mo_wlg4(MR_PSET,WINSC,(long *)0,0L);/*						TD50 */

	/*****************************************************************/
	/*	ﾚｲｶﾞｲﾊﾝﾄﾞﾗ ｦ ｾｯﾃｲ ｽﾙ										 */
	/*****************************************************************/
	tpctp = (TPCTPSZ *)MRTBLAD(pscparea.pscpctad,pscparea.pscpctno+1);
	tpctp->tpctpst = 0;					/* 二重例外ﾌﾗｸﾞの解除	TD@1 */

	
	/*****************************************************************/
	/*	2003-03-24  修正 START 										 */
	/*  ossetex()はossetex2()を変更する								 */
	/*  シグナル番号は(1)〜(31)にセットするため例外ハンドラの		 */
	/*  登録する処理を削除											 */
	/*****************************************************************/
	
	for(lCnt = 1; lCnt < 32; lCnt++) 
	{
										/*				  (L02) TD50 */
		rc = ossetex2(lCnt, mr_prcv);	/* ﾌﾟﾛｾｽ終了例外ﾊﾝﾄﾞﾗ ST1525 */
	}

#ifdef LINUX_ISOKUTAIOU

										/* ﾚｲｶﾞｲ ﾊﾝﾄﾞﾗ ﾉ ﾄｳﾛｸ		 */
										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXITRM;				/*						(L02)*/
	mrlog[1] = (long)mr_prcv;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXITRM, mr_prcv);	/* ﾌﾟﾛｾｽ終了例外ﾊﾝﾄﾞﾗ ST1525 */
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIBUS;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIBUS, mr_prcx); 	/* ﾊﾞｽｴﾗｰ例外ﾊﾝﾄﾞﾗ(L02)ST1525*/
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIADR;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIADR, mr_prcx);	/* ｱﾄﾞﾚｽｴﾗｰﾚｲｶﾞｲﾊﾝﾄﾞﾗ 	(L02)*/
										/* ST1525					 */
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIILL;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIILL, mr_prcx);	/* 不当命令例外ﾊﾝﾄﾞﾗ 	(L02)*/
										/* ST1525					 */
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIDVD;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIDVD, mr_prcx);	/* 0除算例外ﾊﾝﾄﾞﾗ(L02) ST1525*/
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

	/*****************************************************************/
	/*	OSの機能変更に伴い、ｽﾀｯｸ異常に対する例外ﾊﾝﾄﾞﾗの登録を削除	 */
	/*	(削除ｽﾃｯﾌﾟ数 : 7)										TD95 */
	/*****************************************************************/

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIILK;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIILK, mr_prcx);	/* 例外ﾊﾝﾄﾞﾗ	(L02) ST1525 */
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

										/* MRWOG削除 3行		TD50 */
	mrlog[0] = OSEXIUSR;				/*						(L02)*/
	mrlog[1] = (long)mr_prcx;			/*						(L02)*/
	mo_wlg4(MR_PSET,WBSYS | OSSETEX,mrlog,8L);
										/*				  (L02) TD50 */
	rc = ossetex(OSEXIUSR, mr_prcx);	/* ﾕｰｻﾞ定義例外ﾊﾝﾄﾞﾗ    (L02)*/
										/* ST1525					 */
	mrlog[0] = rc;						/* ossetex返却値	ST1525   */
	mo_wlg4(MR_PSET,WASYS | OSSETEX,mrlog,4L);
										/*				  (L02) TD50 */
										/* ossetex発行後	ST1525   */

#endif
		
	/*****************************************************************/
	/*	2003-03-24  修正 END 										 */
	/*  ossetex()はossetex2()を変更する								 */
	/*  シグナル番号は(1)〜(31)にセットするため例外ハンドラの		 */
	/*  登録する処理を削除											 */
	/*****************************************************************/


	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWOG削除 3行		TD50 */
	mo_wlg4(MR_PSET,WOTSC,(long *)0,0L);
	PRINT0("mr_pset() : END\n");
}
