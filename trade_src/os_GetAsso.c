/************************************************************************************************/
/*	著作権	２００２							                               					*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 共通関数													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ＸＸＸＸＸＸＸ												*/
/* ＜モジュールＩＤ＞				 os_GetAsso													*/
/* ＜モジュール通番＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種名＞					 汎用サーバ													*/
/* ＜適用ＯＳ＞ 					 Ｌｉｎｕｘ 												*/
/* ＜開発環境＞ 					 ＲＨＡＳ２．１												*/
/* ＜記述言語＞ 					 Ｃ言語 													*/
/* ＜モジュール形態＞				 関数														*/
/* ＜機能区分＞ 																				*/
/* ＜対象データ＞																				*/
/* ＜工程・階層区分＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞				 ＬＡＬａ−ＳＭＰシステム									*/
/* ＜開発システム番号＞ 			 ＰＰ４０Ｂ００１２２０										*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ)			    	*/
/* ＜電話番号＞ 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞ 					 ＣＢ事ビジネス企画担当										*/
/* ＜設計年月日＞					 ２００２年　９月２７日 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(:ＸＸＸＸ)						*/
/* 作成者:五味                                                               */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日:2002年10月3日                                                      */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 第一引数mpidより種別を求め,返却する	                                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_GetAsso.h>																*/
/*																								*/
/*	   	long	os_GetAsso(long mpid)													        */
/*																								*/
/* ＜仮引数＞																					*/
/*		long      	mpid;		 		   0又はメイルボックス識別子又はプロセスの識別子		*/
/*													                                            */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了	mpidが0の場合			0													*/
/*					mpidが0以外の場合		種別										    	*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   特になし 																				*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
/*****************************************************************************/
#include "os_GetAsso_ins.h"
/*****************************************************************************/
/* 機能:識別子から種別を取得                                                 */
/* 作成日:2002年10月3日                                                      */
/* 変更日:                                                                   */
/* 作成者:五味                                                               */
/* 呼出形式:                                                                 */
/*   long os_GetAsso( long id )                                              */
/*     long id                識別子                                         */
/*                                                                           */
/*****************************************************************************/
long os_GetAsso( long id )
{
//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_GETASSO ) );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_GETASSO ) );
	return( (id >> 16) & 0x000000ffL );	// 種別を返却する
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

