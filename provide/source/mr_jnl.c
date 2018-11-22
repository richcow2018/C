/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ｻﾌﾞ ﾊﾟﾂｹ-ｼﾞ													 */
/*		RCV															 */
/*																	 */
/*	1 ｻﾌﾞ ﾊﾟﾂｹ-ｼﾞ													 */
/*		ｼﾞﾔ-ﾅﾙ ｼﾕﾄｸ													 */
/*																	 */
/*	3 ｶﾝｽｳ ﾒｲ														 */
/*		mr_jnl														 */
/*																	 */
/*	4 ｷﾉｳ ｶﾞｲﾖｳ														 */
/*		ﾍﾝｼﾕｳ ｽﾞﾐ ｼﾞﾔ-ﾅﾙ ﾆ ｷﾖｳﾂｳ ｲﾝﾃﾞﾂｸｽ ｵ							 */
/*		ﾌｶ ｼﾃ ｼﾞﾔ-ﾅﾙ ﾌｱｲﾙ ﾆ ｶｷｺﾑ									 */
/*																	 */
/*	5 ﾊﾟﾗﾒ-ﾀ														 */
/*		type : ﾚｺ-ﾄﾞ ｼﾕﾍﾞﾂ											 */
/*																	 */
/*	6 ﾍﾝｷﾔｸﾁ														 */
/*		MRNORMAL	: ｾｲｼﾞﾖｳ ｼﾕｳﾘﾖｳ									 */
/*		MCEOSERR	: ROS ｼｽﾃﾑｺｰﾙ ｴﾗｰ								 */
/*		MRENQERR	: ｿﾉﾀ ﾉ ENQ ｴﾗｰ									 */
/*		MRNOOPEN	: ﾐｵ-ﾌﾟﾝ										 */
/*		MRIVPARN	: ﾊﾟﾗﾒﾀ ｴﾗ-										 */
/*		MRNOMEM		: ﾒﾓﾘ ﾌﾞｿｸ										 */
/*		MRJNLERR	: ｱｸｾｽ ｴﾗｰ										 */
/*		MRMODEERR	: ﾓｰﾄﾞ ｴﾗｰ										 */
/*		MRNORMX		: ｼﾞﾖｳｹﾝ ﾂｷ ｾｲｼﾞﾖｳ ｼﾕｳﾘﾖｳ (ﾍﾝｼﾕｳ ﾃﾞ-ﾀ ｶﾞ ﾅｲ)	 */
/*																	 */
/*	7 ﾘﾚｷ															 */
/*		ｾﾂｹｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ											 */
/*		ｻｸｾｲｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '86/06/11						 */
/*		ﾍﾝｺｳｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '87/09/01 (L01)				 */
/*				 (ｼｮﾘｹｲ ｳﾝﾃﾝ ｼｭｳﾘｮｳ ｲﾗｲ ｼﾞｬｰﾅﾙ ﾉ 					 */
/*				  ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- STC353						 */
/*		ﾍﾝｺｳｼﾔ : ﾔﾏｸﾞﾁ ﾏｻﾋﾛ			 '87/09/01 (L02)				 */
/*				 (ﾊﾞｯｸｱｯﾌﾟ ﾓｰﾄﾞ ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) --- STC358			 */
/*		ﾍﾝｺｳｼﾔ : ﾉｸﾞﾁ ﾏｽｵ			 '87/09/30 (L03)				 */
/*				 (ｵｲｶｹ ﾘｶﾊﾞﾘ ｶﾝﾚﾝ ｷﾉｳ ﾉ ｻｸｼﾞｮ) --- STC395			 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ				'88/11/20					 */
/*				 (ｼｮｳｶﾞｲ ｶｲｾｷ ｼﾞｮｳﾎｳ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾍﾝｺｳ) --- TC1990	 */
/*		ﾍﾝｺｳｼﾔ : ﾏｴｻﾞﾜ ｱｷﾗ				'89/12/05 (L04)	--- TC2715	 */
/*		ﾍﾝｺｳｼｬ : 山下　元			 '93/12/20	 					 */
/*				 (ﾛｼﾞｯｸの整理)								TD-@1	 */
/*				 (KJ分離に伴う変更)							TD-42	 */
/*				 (ｼｽﾃﾑﾀﾞｳﾝ見直しに伴う変更)					TD-48	 */
/*				 (ﾌﾟﾛｾｽｱﾎﾞｰﾄ見直しに伴う変更)				TD-49	 */
/*				 (ﾛｸﾞの見直しに伴う修正)					TD-50	 */
/*				 (ｼﾞｬｰﾅﾙﾆｱｴﾝﾄﾞ通知処理)						TD-65	 */
/*				 (BKUP中ｼﾞｬｰﾅﾙ取得)							TD-67	 */
/*		変更者 : 杉岡  克也			'95/04/11 --- CT1015(ST2496)     */
/*		変更者 : 山本  智也			'95/05/15 			SSCY0042 	 */
/*		( ＫＪ付加関数への引数追加  仕様変更要求書 ＳＳＣＹ００４２	 */
/*		変更者 : 杉岡  克也			'95/10/09 --- CT1152(ST3674)     */
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
long	mr_jnl(type)
register	char	type;
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
