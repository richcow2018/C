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
/* ＜モジュール名＞					 指定日時までの遅延											*/
/* ＜モジュールＩＤ＞				 osslpun													*/
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
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年10月21日                                                   */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 指定日時までの遅延																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osslpun.h>																	*/
/*																								*/
/*	   	long	osslpun( long day, long time )													*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	day;		日付																*/
/*		long	time;		時刻																*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEIVAL																*/
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
#include <sys/time.h>
#include <string.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osslpun.h"
#include "osslpun_ins.h"				// 内部参照用（個別）

/****************************************************************************/
/* 機能：指定日時までの遅延                                                 */
/* 作成日：2002年10月21日                                                   */
/* 変更日：                                                                 */
/* 作成者：梶原                                                             */
/* 呼出形式：                                                               */
/*   long osslpun( long day, long time )                                    */
/*     long day            日付                                             */
/*     long time           時刻                                             */
/*                                                                          */
/****************************************************************************/
long osslpun( long day, long time )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	int iRet;							// 関数の結果返却
	long lRet;							// 共通関数の結果返却
	time_t lDelayTime;					// 遅延指定日時の経過秒数
	struct timeval tNowTime;			// 時間格納体
	long lNowTime;						// 現在日時
	struct tm tDate;					// 日時格納体
	struct tm *ptDate;					// 日時格納体ポインタ
	struct timespec tStopTime;			// 停止時間格納体
    struct timespec tRStopTime;			// 残り停止時間格納体
    long lTmp = 0;
    
	os_trcget2( D_MD_OSSLPUN , D_T_TRA_IN, 2, day, time );
    
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
	
										// 20030313 仕様変更SSLA0017
	if(0 == day)						// 日付が０の時は本日の日付を設定
	{
		lRet = osgtdat(&day, &lTmp);
		if(NORMAL != lRet)
			return(lRet);
	}
	
	lRet = os_DayTime2Date( day, time, &tDate );
										// 日付時刻を日時に変換
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );
	
	if( NORMAL != lRet )				// 日時変換に失敗した時
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSEEIVAL ) );
    														
		os_trcget2( D_MD_OSSLPUN , D_T_ERR_PRA, 1, OSEEIVAL );    														
    														
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	
 	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_MKTIME, 1, &tDate );    
		
	lDelayTime = mktime( &tDate );		// 遅延指定日時の経過秒数取得
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_END, 1, lDelayTime );
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lDelayTime=%ld )\n",
														D_PROC_NAME, lDelayTime ) );
	if( D_ERR_SYS == lDelayTime )		// 経過秒数取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN,  D_T_ERR_SYS, 1, errno    );
									
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  
	
	iRet = gettimeofday( &tNowTime, NULL );
										// 現在日時の経過秒数（協定世界時刻）を取得
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, iRet ); 
	
	if( D_ERR_SYS == iRet )				// 経過秒数取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEESETE, "gettimeofday", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, errno    ); 
									
		return( OSEESETE );				// OSEESETEを返却
	}
	
	
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_LOCALTIME, 1, &tNowTime.tv_sec ); 
	
	ptDate = localtime( &tNowTime.tv_sec );
										// 協定世界時刻からローカルタイムへ変換
										
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, ptDate ); 
										
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptDate=%p )\n", D_PROC_NAME, ptDate ) );
	
	if( D_ERR_SYS == ( long )ptDate )	// ローカルタイム変換に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "localtime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, errno    ); 
									
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_MKTIME, 1, ptDate ); 
	
	lNowTime = mktime( ptDate );		// 現在日時の経過秒数の取得
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_END, 1, lNowTime ); 
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lNowTime=%ld )\n",
														D_PROC_NAME, lNowTime ) );
	if( D_ERR_SYS == lNowTime )			// 経過秒数取得に失敗した時
	{
		os_trcget2( D_MD_OSSLPUN,  D_T_ERR_SYS, 1, OSEEIVAL ); 
		
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_DIFFTIME, 2, lDelayTime, lNowTime ); 
	
	tStopTime.tv_sec = difftime( lDelayTime, lNowTime );
										// 秒の設定（遅延秒数を算出）
										
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, tStopTime.tv_sec ); 
										
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
														D_PROC_NAME, tStopTime.tv_sec ) );
	if( D_TIME_MIN > tStopTime.tv_sec )	// 秒が1未満の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "difftime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, OSEEIVAL ); 
									
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	tStopTime.tv_nsec = 0;				// ナノ秒の設定
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
														D_PROC_NAME, tStopTime.tv_nsec ) );
	for( ; ; )
	{
		os_trcget2( D_MD_OSSLPUN, D_T_SYS_NANOSLEEP, 2, &tStopTime, &tRStopTime );
		iRet = nanosleep( &tStopTime, &tRStopTime );
										// 遅延処理の実行
		os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 2, iRet, errno );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
																D_PROC_NAME, iRet ) );
		if( D_ERR_SYS == iRet )			// 遅延中に割り込みがあった時
		{
			switch( errno )
			{
				case EINTR:
					tStopTime.tv_sec = tRStopTime.tv_sec;
										// 残り秒の設定
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: ( %s: %s )\n",
									D_PROC_NAME, "nanosleep", strerror(errno) ) );
									
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
					tStopTime.tv_nsec = tRStopTime.tv_nsec;
										// 残りナノ秒の設定
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
					break;
					
				default:
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "nanosleep", strerror(errno) ) );
									
					os_trcget2( D_MD_OSSLPUN , D_T_ERR_SYS, 1, errno );  
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSLPUN << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// アボート処理
	        }
	    }
		else							// 遅延処理が終了した時
		{
			break;						// 処理を抜ける
		}
	}
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSSLPUN , D_T_TRA_OUT, 1, NORMAL );  
	
	return( NORMAL );					// NORMALを返却し終了
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/

