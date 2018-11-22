/************************************************************************************************/
/*	著作権	２００２							                               					*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＸＸＸ−ＳＭＰシステム	共通関数			（mc_xxxx系）							*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 タイマ制御													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 プロセスの遅延												*/
/* ＜モジュールＩＤ＞				 osdelay													*/
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
/* 作成者：梶原                                                             */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年10月21日                                                   */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/* 変更日：2002年12月17日                                                   */
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 プロセスの遅延																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osdelay.h>																	*/
/*																								*/
/*	   	long	osdelay( long times, long unit )												*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	times;			遅延時間（1以上の正値）											*/
/*		long	unit;			単位時間（1：ミリ秒 2：秒 3：分 4：時）							*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEITIM																*/
/*						OSEEIUNI																*/
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
#include <time.h>
#include <string.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osdelay.h"
#include "osdelay_ins.h"				// 内部参照用（個別）

/****************************************************************************/
/* 機能：プロセスの遅延                                                     */
/* 作成日：2002年10月21日                                                   */
/* 変更日：2002年12月17日                                                   */
/* 作成者：梶原                                                             */
/* 呼出形式：                                                               */
/*   long delay( long times, long unit )                                    */
/*     long times              遅延時間                                     */
/*     long unit               単位時間                                     */
/*                                                                          */
/****************************************************************************/
long osdelay( long times, long unit )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    long lNSec;							// ナノ秒
	struct timespec tStopTime;			// 停止時間格納体
    struct timespec tRStopTime;			// 残り停止時間格納体
    int iRet;							// 関数の結果返却
    
	os_trcget2( D_MD_OSDELAY, D_T_TRA_IN, 2, times, unit  );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
    
	/******* 2002.12.16 *********/
	/******* 仕様変更前のため処理追加(0チェック) *******/
		
    if( D_TIME_MIN > times )			// 遅延時間が最小値より小さい時
    {
		if( D_TIME_ZERO == times )		// 遅延時間が0の時
		{
			DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
			
			os_trcget2( D_MD_OSDELAY, D_T_ERR_PRA, 1, NORMAL );
			
			return( NORMAL );
		}
		else							// 遅延時間が負値の時
		{
	    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
	    														D_PROC_NAME, OSEEITIM ) );
	    	
	    	os_trcget2( D_MD_OSDELAY, D_T_ERR_PRA, 1, OSEEITIM );													
	    														
	        return( OSEEITIM );			// OSEEITIMを返却
	    }
    }
    
/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
    switch( unit )
    {
		case D_UNIT_MSEC:				// 単位時間がミリ秒の時
			tStopTime.tv_sec = ( time_t )( times / D_MSEC_VAL );
										// 秒の設定
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );

			lNSec = ((( long )(( times % D_MSEC_VAL ) + ( D_UPTIME_TEN - 1 )) / D_UPTIME_TEN )) 
															     * D_UPTIME_TEN * D_MNSEC_VAL;
										// ナノ秒取得（切上げ処理）
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lNSec=%ld )\n",
																D_PROC_NAME, lNSec ) );

 			if( D_NSEC_VAL > lNSec )	// ナノ秒が1秒あたりのナノ秒より小さい時
			{
				tStopTime.tv_nsec = lNSec;
										// ナノ秒の設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// ナノ秒が1秒あたりのナノ秒より大きい時
			{
				tStopTime.tv_sec++;		// 秒の設定（1加算）
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = lNSec - D_NSEC_VAL;
										// ナノ秒設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			break;
			
		case D_UNIT_SEC:				// 単位時間が秒の時
			tStopTime.tv_sec = times;	// 秒の設定
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
			tStopTime.tv_nsec = 0;		// ナノ秒の設定
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			break;
			
		case D_UNIT_MINUTE:				// 単位時間が分の時
			if( D_MIN_MAX >= times )	// 遅延時間が最大値以下の場合
			{
				tStopTime.tv_sec = ( times * 60 );
										// 秒の設定（分を秒に変換）
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = 0;	// ナノ秒設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// 遅延時間が最大値を超えていた場合
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   				os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEITIM );	
    														
				return( OSEEITIM );		// OSEEITIMを返却
			}
			break;
			
		case D_UNIT_HOUR:				// 単位時間が時の時
			if( D_HOUR_MAX >= times )	// 遅延時間が最大値以下の場合
			{
				tStopTime.tv_sec = ( times * 60 * 60 );
										// 秒の設定（時を秒に変換）
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = 0;	// ナノ秒設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// 遅延時間が最大値を超えていた場合
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    			
    			os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEITIM );									
    														
				return( OSEEITIM );		// OSEEITIMを返却
			}
			break;
			
		default:						// 単位時間がその他の時
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   			os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEIUNI );	
    														
        	return( OSEEIUNI );			// OSEEIUNIを返却
	}
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSDELAY, D_T_SYS_NANOSLEEP, 2, &tStopTime, &tRStopTime );
		iRet = nanosleep( &tStopTime, &tRStopTime );
										// 遅延処理を実行
		os_trcget2( D_MD_OSDELAY, D_T_SYS_END, 2, iRet, errno );
										
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
																D_PROC_NAME, iRet ) );
		if( D_ERR_SYS == iRet )			// 遅延中に割り込みがあった時
		{
			switch( errno )
			{
				case EINTR:				// EINTRの時
					tStopTime.tv_sec = tRStopTime.tv_sec;
										// 残り秒の設定
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: ( %s: %s )\n",
									D_PROC_NAME, "nanosleep", strerror(errno) ) );
									
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
					tStopTime.tv_nsec = tRStopTime.tv_nsec;
										// 残りナノ秒の設定
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );

					break;
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "nanosleep", strerror(errno) ) );
									
					os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 2, -1 , errno );	
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELAY << 16) | D_T_ERR_SYS );
					//return( -1 );		// アボート処理
	        }
	    }
	    else							// 遅延処理が終了した時
	    {
			break;						// 処理を抜ける
		}
	}
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSDELAY, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMALを返却し終了
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

