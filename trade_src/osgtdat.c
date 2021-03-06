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
/* ＜サービス項目名＞				 タイマ制御													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 システム時刻取得											*/
/* ＜モジュールＩＤ＞				 osgtdat													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)					*/
/* 作成者：梶原                                                             */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年9月26日                                                    */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/* 変更日：2002年10月23日                                                   */
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/* 機能：日付及び時刻の取得                                                 */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*   long osstdat( long *dayp, long *timep )                                */
/*																								*/
/* ＜仮引数＞																					*/
/*     long *dayp          日付格納場所                                     */
/*     long *timep         時刻格納場所                                     */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			iFilId+1(iFilIdはファイル記述子カウント用)							*/
/*		異常終了			-1																	*/
/*																								*/
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
#include <sys/time.h>
#include <time.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osgtdat.h"
#include "osgtdat_ins.h"				// 内部参照用（個別）

/****************************************************************************/
/* 機能：システム日付、時刻の設定                                           */
/* 作成日：2002年9月30日                                                    */
/* 変更日：2002年10月23日                                                   */
/* 作成者：梶原                                                             */
/* 呼出形式：                                                               */
/*   long osstdat( long *dayp, long *timep )                                */
/*     long *dayp          日付格納場所                                     */
/*     long *timep         時刻格納場所                                     */
/*                                                                          */
/****************************************************************************/
long osgtdat( long *dayp, long *timep )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	int iRet;							// 関数の結果返却
	long lRet;							// 共通関数の結果返却
	struct timeval tNowTime;			// 時間格納体
	struct tm *ptDate;					// 日時格納体
	
	os_trcget2( D_MD_OSGTDAT, D_T_TRA_IN, 2, dayp, timep );
	
	DbgInit( D_DEF, D_DEF, D_DEF );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	
	if( NULL == dayp )					// 日付格納場所がNULLの時
	{
		os_trcget2( D_MD_OSGTDAT, D_T_ERR_PRA, 1, OSEEACCV  );
		
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEACCV ) );
		return( OSEEACCV );				// OSEEACCVを返却
	}
	
	if( NULL == timep )					// 時刻格納場所がNULLの時
	{
		os_trcget2( D_MD_OSGTDAT, D_T_ERR_PRA, 1, OSEEACCV  );
		
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEACCV ) );
		return( OSEEACCV );				// OSEEACCVを返却
	}
	
/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSGTDAT, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  
	
	iRet = gettimeofday( &tNowTime, NULL );
										// 現在日時の経過秒数（協定世界時刻）を取得
	
	os_trcget2( D_MD_OSGTDAT, D_T_SYS_END, 1, iRet ); 									
										
	if( D_ERR_SYS == iRet )				// 経過秒数取得に失敗した時
	{
		os_trcget2( D_MD_OSGTDAT, D_T_ERR_SYS, 1, OSEESETE ); 
		
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESETE ) );
		return( OSEESETE );				// OSEESETEを返却
	}
	
	os_trcget2( D_MD_OSGTDAT, D_T_SYS_LOCALTIME, 1, &tNowTime.tv_sec ); 
	
	ptDate = localtime( &tNowTime.tv_sec );
										// 協定世界時刻をローカルタイムに変換
										
	os_trcget2( D_MD_OSGTDAT, D_T_SYS_END, 1, ptDate ); 
										
	if( D_ERR_SYS == ( long )ptDate )	// ローカルタイム変換に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESETE ) );
		
		os_trcget2( D_MD_OSGTDAT, D_T_ERR_SYS, 1, OSEESETE ); 
		
		return( OSEESETE );				// OSEESETEを返却
	}
	
	lRet = os_Date2DayTime( ptDate, dayp, timep );
										// 日時を日付時刻に変換
	if( NORMAL != lRet )				// 変換に失敗した時
	{
		os_trcget2( D_MD_OSGTDAT, D_T_ERR_SYS, 1, OSEESETE );
		
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESETE ) );
		return( OSEESETE );				// OSEESETEを返却
	}
	
	os_trcget2( D_MD_OSGTDAT, D_T_TRA_OUT, 1, NORMAL );
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	return( NORMAL );					// NORMALを返却し終了
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

