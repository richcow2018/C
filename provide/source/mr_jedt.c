/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞ ﾊﾟﾂｹ-ｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	2 ｶﾝｽｳ ｸﾌﾞﾝ														 */
/*		ｼﾞﾔ-ﾅﾙ ｼﾕﾄｸ													 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ														 */
/*		mr_jedt														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		ｼﾞﾔ-ﾅﾙ ｼﾕﾄｸ ﾉ ﾀﾒ ﾉ											 */
/*		ﾃﾞ-ﾀ ﾍﾝｼﾕｳ ｦ ｵｺﾅｳ											 */
/*																	 */
/*	5 ﾊﾟﾗﾒ-ﾀ														 */
/*		type  : ｼﾞﾔ-ﾅﾙ ｼﾕﾍﾞﾂ										 */
/*		name  : ﾌｱｲﾙ ﾒｲ or ﾃ-ﾌﾞﾙ ﾒｲ									 */
/*		data1 : ﾃﾞ-ﾀ ｱﾄﾞﾚｽ 1										 */
/*		data2 : ﾃﾞ-ﾀ ｱﾄﾞﾚｽ 2										 */
/*		num   : FMTｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ or ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ						 */
/*		len1  : ﾃﾞ-ﾀ ﾁﾖｳ 1											 */
/*		len2  : ﾃﾞ-ﾀ ﾁﾖｳ 2											 */
/*																	 */
/*	6 ﾍﾝｷﾔｸﾁ														 */
/*		MRMODEERR	: ﾓｰﾄﾞ ｴﾗｰ										 */
/*		MRNOMEM		: ﾒﾓﾘ ﾌﾞｿｸ										 */
/*		MRNOOPEN	: ﾐｵｰﾌﾟﾝ										 */
/*		MCEOSERR	: ﾊﾞｯﾌｧ ｶｸﾄｸ ｴﾗｰ								 */
/*		MRIVPARAM	: ﾊﾟﾗﾒﾀ ｴﾗ-										 */
/*		ｿﾉﾀ ﾉ ｾｲ ﾉ ｱﾀｲ : ｾｲｼﾞﾖｳ ｼﾕｳﾘﾖｳ (ﾃﾞ-ﾀ ﾉ ｾﾝﾄｳ ｱﾄﾞﾚｽ)			 */
/*																	 */
/* 	7 ﾘﾚｷ															 */
/*		ｾﾂｹｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ											 */
/*		ｻｸｾｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '86/06/16						 */
/*		ﾍﾝｺｳｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '87/09/01 (L01) 				 */
/*				 (VJ ﾃﾞｰﾀ ﾍﾝｼｭｳ ｷﾉｳ ﾉ ﾂｲｶ) --- STC347				 */
/*		ﾍﾝｺｳｼﾔ : ﾉｸﾞﾁ ﾏｽｵ			 '87/09/30 (L02)				 */
/*				 (ｵｲｶｹ ﾘｶﾊﾞﾘ ｶﾝﾚｶ ｷﾉｳ ﾉ ｻｸｼﾞｮ) --- STC395			 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ			 '88/07/04 (L03)				 */
/*				  (ﾎﾞﾘｭ-ﾑ ﾍｲｿｸ ｷﾉｳ ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- STC911		 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '88/10/05 (L04)				 */
/*				 (ｼﾞｬｰﾅﾙ ﾘｰﾄﾞ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- TC1230			 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		ﾍﾝｺｳｼｬ : 山下　元			 '93/12/20	 					 */
/*				 (ﾛｼﾞｯｸの整理)								TD-@1	 */
/*				 (AJの廃止に伴う削除)						TD-41	 */
/*				 (KJ分離に伴う変更)							TD-42	 */
/*				 (ﾛｸﾞの見直しに伴う修正)					TD-50	 */
/*		変更者 : 杉岡  克也			'95/06/03 --- ST2767			 */
/*		変更者 : 杉岡  克也			'95/10/22 --- ST3629			 */
/*		変更者 : 杉岡  克也			'95/10/24 --- ST3634			 */
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
long	mr_jedt(type, name, data1, data2, num, len1, len2)
short	type;
char	*name;
char	*data1;
char	*data2;
long	num;
long	len1;
long	len2;
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
