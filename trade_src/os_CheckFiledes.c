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
/* ＜モジュールＩＤ＞				 os_CheckFiledes											*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(ＸＸＸＸ)						*/
/* 作成者:東野                                                              */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日:2002年9月24日                                                     */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 ファイル記述子チェック																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_CheckFiledes.h>															*/
/*																								*/
/*	   	long		os_CheckFiledes( long fildes)												*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		fildes;		 		ファイル記述子											*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了	NORMAL	   																	*/
/*		異常終了	OSFEFILDES																	*/
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
/*                                                                          */
/****************************************************************************/
#include "os_CheckFiledes_ins.h"
/****************************************************************************/
long os_CheckFiledes( long fildes )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    if( ( fildes > D_FILDES_MIN ) && 
                                    ( fildes <= ptEflc->lMaxIndNum ) )
                                        // ０＜ファイル記述子＜＝ファイル管理
                                        // テーブルの個別部数の範囲の時
    {
        DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
        return( NORMAL );               // 正常値を返却する
    }
    
    DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    													D_PROC_NAME, OSFEFILDES ) );
                                        // ０＜ファイル記述子＜＝ファイル管理
                                        // テーブルの個別部数の範囲でない時
    return( OSFEFILDES );               // エラーを返却する
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

