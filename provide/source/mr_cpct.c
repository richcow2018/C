/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞﾊﾟｯｹｰｼﾞ													 */
/*		RCV															 */
/*																 	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ														 */
/*		ｷｮｰﾂｳ ｶﾝｽｳ													 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ													 	 */
/*		mr_cpct														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		PCT ｺﾍﾞﾂﾌﾞ ｱﾄﾞﾚｽ ｦ ﾓﾄﾒﾙ										 */
/*																	 */
/*	5 ﾊﾟﾗﾒｰﾀ														 */
/*		pname	: 	ﾌﾟﾛｾｽｼｷﾍﾞﾒｲ										 */
/*																	 */
/*	6 ﾍﾝｷｬｸﾁ														 */
/*		PCT ｱﾄﾞﾚｽ	:	ｿﾝｻﾞｲ ｽﾙ									 */
/*		(TPCTPSZ *)0:	ｿﾝｻﾞｲ ｼﾅｲ									 */
/*																	 */
/*	7 ﾘﾚｷ															 */
/*		 ｾｯｹｲｼｬ : ﾎｼﾉ ﾋﾛﾄｼ											 */
/*		 ｻｸｾｲｼｬ : ﾎｼﾉ ﾋﾛﾄｼ				'86/06/18					 */
/*		 ﾍﾝｺｳｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ				'					 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		変更者 : 渡邉　基樹				'94/01/17					 */
/*				 （ログの見直しに伴う修正）					TD-50	 */
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
/*  ｲﾝｸﾙｰﾄﾞ ﾌｧｲﾙ													 */
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
#include	"tcom.h"
#include	"psect.h"
#include	"mrmac.h"
#include	"mcdebug.h"
#include	"tpct.h"
#include	"mo_wlg.h"					/*						TD50 */

/*********************************************************************/
/*  ｶﾞｲﾌﾞ ﾍﾝｽｳ ﾘｮｳｲｷ 												 */
/*********************************************************************/
extern		PSCPSECT	pscparea;		/* PSECT ﾘｮｳｲｷ				 */

/*********************************************************************/
/*	ﾃﾞﾌｧｲﾝ ﾁ 														 */
/*********************************************************************/
										/* MRWLOG削除 1行		TD50 */

/*********************************************************************/
/*	define function name for mo_wlg4						TD-50	 */
/*********************************************************************/
#define	MR_CPCT	0x6d725f63,0x70637420

TPCTPSZ 	*mr_cpct(pname)
register	char	*pname;				/*	ﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲ			 */
{
	/*****************************************************************/
	/*  mr_cpct ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ									 */
	/*****************************************************************/
	long	mc_ccom();					/* ﾓｼﾞﾚﾂ ﾉ ﾋｶｸ				 */
	void	mo_wlg4();					/* Sﾄﾚｰｽ情報の取得		TD50 */

	/*****************************************************************/
	/*  mr_cpct ﾅｲ ﾜｰｸ ｴﾘｱ									 		 */
	/*****************************************************************/
	register	long		retcd;		/* ﾘﾀｰﾝﾁ ｶｸﾉｳ ｴﾘｱ			 */
	register	TPCTPSZ		*tpctp;		/* PCT ｺﾍﾞﾂﾌﾞ ｱﾄﾞﾚｽ ﾎﾟｲﾝﾀ	 */
	register	long		pnum;		/*	ﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲ ﾉ ﾅｶﾞｻ		 */
	register	char		*sp;
	register	int			i;
	register	short		efen;
				long		mrlog[2];	/* ﾛｸﾞ ｼﾞｮｳﾎｳ ﾍﾝｼｮｳ ﾘｮｳｲｷ	 */

	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWLOG削除 1行		TD50 */
	/*****************************************************************/
	/*	PRC-005-09  修正 START 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
	mrlog[0] = htonl((long)pname);										/* PRC-005-09 */
	mo_wlg4(MR_CPCT,WINSC,mrlog,4L);	/*						TD50 */
	/*****************************************************************/
	/*	PRC-005-09  修正 END 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
										/* MRWLOG削除 2行		TD50 */

	/*****************************************************************/
	/*	PCT ﾉ ﾌﾟﾛｾｽｼｷﾍﾞﾒｲ ｦ ｹﾝｻｸ ｽﾙ									 */
	/*****************************************************************/
	for (sp=pname; *sp != '\0'; sp++);
	pnum = (long)(sp - pname);
	retcd = mc_ccom(pname,"        ",pnum);
	if (retcd == 0L){
		tpctp = (TPCTPSZ *)0;
		mo_wlg4(MR_CPCT,0x33331000L,(long *)0,0L);
										/*						TD50 */
		goto rtn;
	}
	else;
	efen = pscparea.pscpctad->tcomefen;
	tpctp = (TPCTPSZ *)MRTBLAD(pscparea.pscpctad,1);
	for (i=0; i < efen; i++){
		retcd = mc_ccom(pname,tpctp->tpctpnm,pnum);
		if (retcd == 0L){
			break;
		}
		else;
		tpctp++;
	}

	/*****************************************************************/
	/*	PCT ｶﾞ ﾐﾂｶｯﾀｶ ﾁｪｯｸ ｽﾙ										 */
	/*****************************************************************/
	if (i >= efen){
		tpctp = (TPCTPSZ *)0;
		mo_wlg4(MR_CPCT,0x33331001L,(long *)0,0L);
	}
	else;
rtn:
	/*****************************************************************/
	/*	ﾛｸﾞ ｼﾞｮｳﾎｳ ﾉ ｼｭﾄｸ											 */
	/*****************************************************************/
										/* MRWLOG削除 1行		TD50 */
	/*****************************************************************/
	/*	PRC-005-09  修正 START 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
	mrlog[0] = htonl((long)tpctp);										/* PRC-005-09 */
	mo_wlg4(MR_CPCT,WOTSC,mrlog,4L);
	/*****************************************************************/
	/*	PRC-005-09  修正 END 										 */
	/*  エンディアン問題対応  バイト反転							 */
	/*****************************************************************/
										/* MRWLOG削除 2行		TD50 */

	return(tpctp);
}
