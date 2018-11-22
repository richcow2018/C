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
/* ＜モジュールＩＤ＞				 os_Date2DayTime											*/
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
/* 作成者:梶原                                                               */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日:2002年10月3日                                                      */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 日時を日付時刻に変更																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_Date2DayTime.h>															*/
/*																								*/
/*	   	long	os_Date2DayTime( const struct tm *ptdate, long *dayp, long *timep)				*/
/*																								*/
/* ＜仮引数＞																					*/
/*		const struct tm 	*ptDate;			日時構造体										*/
/*		long 				*dayp;				日付格納場所									*/
/*		long 				*timep;				時刻格納場所									*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			NORMAL																*/
/*		異常終了			OSEEIVAL															*/
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
#include "os_Date2DayTime_ins.h"

/*****************************************************************************/
/* 機能:日時を日付時刻に変換                                                 */
/* 作成日:2002年10月3日                                                      */
/* 変更日:                                                                   */
/* 作成者:梶原                                                               */
/* 呼出形式:                                                                 */
/*   long os_Date2DayTime( const struct tm *ptDate, long *dayp, long *timep )*/
/*     const struct tm *ptDate          // 日時構造体                        */
/*     long *dayp                       // 日付格納場所                      */
/*     long *timep						// 時刻格納場所                      */
/*                                                                           */
/*****************************************************************************/
long os_Date2DayTime( const struct tm *ptDate, long *dayp, long *timep )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	long lDay = 0;						// 日付格納変数
	long lTime = 0;						// 時刻格納変数
	
/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_DATE2DAYTIME ) );
	
	if(( D_YEAR_MID <= ptDate->tm_year ) && ( D_YEAR_MAX >= ptDate->tm_year ))
	{									// 年の値がD_YEAR_MID〜D_YEAR_MAXの時
		lDay += ( long )( ptDate->tm_year / 10 );
										// 年の10の位設定
		lDay <<= 4;
		lDay += ( long )( ptDate->tm_year % 10 );
										// 年の1の位設定
	}
	else if(( D_Y2K_MIN <= ptDate->tm_year ) && ( D_Y2K_MAX >= ptDate->tm_year ))
	{									// 年の値がD_Y2K_MIN〜D_Y2K_MAXの時
		lDay += ( long )(( ptDate->tm_year - 100 ) / 10 );
										// 年の10の位設定
		lDay <<= 4;
		lDay += ( long )(( ptDate->tm_year - 100 ) % 10 );
										// 年の1の位設定
	}
	else								// 年の値が範囲以外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	switch( ptDate->tm_mon )
	{
		case 0:							// 月の値が0の時
		case 2:							// 月の値が2の時
		case 4:							// 月の値が4の時
		case 6:							// 月の値が6の時
		case 7:							// 月の値が7の時
		case 9:							// 月の値が9の時
		case 11:						// 月の値が11の時
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// 月の10の位設定
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// 月の1の位設定
		
			if(( 1 <= ptDate->tm_mday ) && ( 31 >= ptDate->tm_mday ))
			{							// 日の値が1〜31の時
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday / 10 );
										// 日の10の位設定
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday % 10 );
										// 日の1の位設定
			}
			else						// 日の値が範囲外の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
													 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
				return( OSEEIVAL );		// OSEEIVALを返却
			}
			break;
			
		case 3:							// 月の値が3の時
		case 5:							// 月の値が5の時
		case 8:							// 月の値が8の時
		case 10:						// 月の値が10の時
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// 月の10の位設定
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// 月の1の位設定
			if(( 1 <= ptDate->tm_mday ) && ( 30 >= ptDate->tm_mday ))
			{							// 日の値が1〜30の時
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday / 10 );
										// 日の10の位設定
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday % 10 );
										// 日の1の位設定
			}
			else						// 日の値が範囲外の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
													 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
				return( OSEEIVAL );
			}
			break;
			
		case 1:							// 月の値が1の時
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// 月の10の位設定
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// 月の1の位設定
			if( 0 == ( ptDate->tm_year % 4))
			{							// 年が4で割り切れる時
				if(( 1 <= ptDate->tm_mday ) && ( 29 >= ptDate->tm_mday ))
				{						// 日の値が1〜29の時
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday / 10 );
										// 日の10の位設定
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday % 10 );
										// 日の1の位設定
				}
				else					// 日が範囲外の時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
														 D_PROC_DATE2DAYTIME, OSEEIVAL ));
					return( OSEEIVAL );	// OSEEIVALを返却
				}
				break;
			}
			else						// 年が4で割り切れない時
			{
				if(( 1 <= ptDate->tm_mday ) && ( 28 >= ptDate->tm_mday ))
				{						// 日の値が1〜28の時
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday / 10 );
										// 日の10の位設定
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday % 10 );
										// 日の1の位設定
				}
				else					// 日が範囲外の時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
														 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
					return( OSEEIVAL );	// OSEEIVALを返却
				}
				break;
			}
			
		default:						// 月の値がその他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
												 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
			return( OSEEIVAL );			// OSEEIVALを返却
	}
	
	if(( D_WEEK_MIN <= ptDate->tm_wday ) && ( D_WEEK_MAX >= ptDate->tm_wday ))
	{									// 曜日の値が0〜6の時
		lDay <<= 8;
		lDay += ( long )( ptDate->tm_wday );
										// 曜日を設定
	}
	else								// 曜日の値が範囲外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	if(( 0 <= ptDate->tm_hour ) && ( 23 >= ptDate->tm_hour ))
	{									// 時の値が0〜23の時
		lTime <<= 8;
		lTime += ( long )( ptDate->tm_hour / 10 );
										// 時の10の位設定
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_hour % 10 );
										// 時の1の位設定
	}
	else								// 時の値が範囲外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	if(( 0 <= ptDate->tm_min ) && ( 59 >= ptDate->tm_min ))
	{									// 分の値が0〜59の時
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_min / 10 );
										// 分の10の位設定
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_min % 10 );
										// 分の1の位設定
	}
	else								// 分の値が範囲外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	if(( 0 <= ptDate->tm_sec ) && ( 59 >= ptDate->tm_sec ))
	{									// 秒の値が0〜59の時
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_sec / 10 );
										// 秒の10の位設定
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_sec % 10 );
										// 秒の1の位設定
	}
	else								// 分の値が範囲外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVALを返却
	}
	
	*dayp = lDay;						// lDayのアドレス設定
	
	*timep = lTime;						// lTimeのアドレス設定
	
	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_DATE2DAYTIME ) );
	return( NORMAL );					// NORMALを返却し終了
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

