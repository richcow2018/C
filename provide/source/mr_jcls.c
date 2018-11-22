/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞ ﾊﾟﾂｹ-ｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ														 */
/*		ｼﾞﾔ-ﾅﾙ ｼﾕﾄｸ													 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ														 */
/*		mr_jcls														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		ｼﾞｬｰﾅﾙ ﾍﾉ ｱｸｾｽ ｦ ｼｭｳﾘｮｳ ｼ									 */
/*		ﾊﾞｲﾀｲ ﾉ ｶｲﾎｳ ｦ ｵｺﾅｳ											 */
/*																	 */
/*	5 ﾊﾟﾗﾒ-ﾀ														 */
/*		ﾅｼ															 */
/*																	 */
/*	6 ﾍﾝｷﾔｸﾁ														 */
/*		MRNORMAL : ｾｲｼﾞﾖｳ ｼﾕｳﾘﾖｳ									 */
/*		MRJNLERR : ｸﾛｰｽﾞ ｴﾗｰ										 */
/*		MRNOOPEN : ﾐｵｰﾌﾟﾝ											 */
/*																	 */
/*	7 ﾘﾚｷ															 */
/*		ｾﾂｹｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ											 */
/*		ｻｸｾｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '86/06/24						 */
/*		ﾍﾝｺｳｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '87/01/14 (WLOG)				 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '88/10/05 (L01)				 */
/*				 (ｼﾞｬｰﾅﾙ ﾘｰﾄﾞ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- TC1230			 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		ﾍﾝｺｳｼｬ : 山下　元			 '93/12/20	 					 */
/*				 (ﾛｼﾞｯｸの整理)								TD-@1	 */
/*				 (KJ分離に伴う変更)							TD-42	 */
/*				 (ﾛｸﾞの見直しに伴う修正)					TD-50	 */
/*				 (SCSIﾘｾｯﾄ機能に伴う追加)					TD-61	 */
/*      変更者  : 山本　有司		 '96/02/19 --- CT1211(ST4062)	 */
/*				 (先行リカバリ高速化に伴う変更)						 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*プロジェクト名	:												 */
/*プロセス名		:ＡＰプロセス									 */
/*改造番号			:PRC-034-01										 */
/*改造内容			:NOP対応	リターンコードに正常値を設定し不要	 */
/*								となったロジックは削除する			 */
/*改造日			:2002.10.18										 */
/*改造者			:Χ								 */
/*********************************************************************/
/*********************************************************************/
/*	PRC-034-01  修正 START 											 */
/*  NOP対応															 */
/*********************************************************************/
/*********************************************************************/
/*	ｲﾝｸﾙ-ﾄﾞ ﾌｱｲﾙ													 */
/*********************************************************************/
#include	"mr.h"						/* 返却値の引数定義			 */	/* PRC-034-01 */
/*********************************************************************/
/*	引数の型宣言													 */
/*********************************************************************/
long	mr_jcls()
{
	/*****************************************************************/
	/* ﾘﾀｰﾝ ｽﾙ														 */
	/*****************************************************************/
	return(MRNORMAL);													/* PRC-034-01 */
}
/*********************************************************************/
/*	PRC-034-01  修正 END 											 */
/*  NOP対応															 */
/*********************************************************************/
