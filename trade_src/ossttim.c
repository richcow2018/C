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
/* ＜モジュール名＞					 インタバルタイマの設定										*/
/* ＜モジュールＩＤ＞				 ossttim													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年０９月３０日 									*/
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月１５日		仕様変更番号（ＳＳＬＡ００４２）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 インターバルタイマの設定																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<ossttim.h>																	*/
/*																								*/
/*	   	long	ossttim( long rd, long times, long unit )										*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	rd;			リクエスト識別子													*/
/*		long	times;		時間																*/
/*		long	unit;		単位時間															*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		リクエスト識別子														*/
/*		異常終了		OSEEITIM																*/
/*						OSEEOVRQ																*/
/*						OSEEIVRD																*/
/*						OSEEUSED																*/
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
#include <string.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "ossttim.h"
#include "os_tmctl.h"					// タイマ制御
#include "ossttim_ins.h"				// 内部参照用（個別）
#include "os_ERDC_ins.h"

/****************************************************************************/
/* 機能：インターバルタイマの設定                                           */
/* 作成日：2002年9月30日                                                    */
/* 変更日：2002年12月10日                                                   */
/* 作成者：梶原                                                             */
/* 呼出形式：                                                               */
/*   long ossttim( long rd, long times, long unit )                         */
/*     long rd             リクエスト識別子                                 */
/*     long times          時間                                             */
/*     long unit           単位時間                                         */
/*                                                                          */
/****************************************************************************/
long ossttim( long rd, long times, long unit )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    long lRId = 0;									// リクエスト識別子
    long lMicroSec = 0;								// マイクロ秒
    long lSec = 0;									// 秒
    int iLoopCnt = 0;								// ループカウンタ
    long lRet = 0;									// 関数の結果返却値
    TErdcTableInd *ptRdIndTopAdr = NULL;			// rd管理テーブル個別部の先頭アドレス
	TErdcTableInd *ptRdIndAdr = NULL;				// rd管理テーブル個別部のアドレス
/*****	仕様変更番号SSLA0042の対応		Start							修正日：2003.07.15	*****/
	long lMilliSec = 0;								// ミリ秒
/*****	仕様変更番号SSLA0042の対応		 End							修正日：2003.07.15	*****/
	
	os_trcget2( D_MD_OSSTTIM, D_T_TRA_IN, 3, rd, times, unit );


//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	引数の確認									*/
	/************************************************/
    ptRdIndTopAdr = (TErdcTableInd *)(ptErdc + 1 ); // rd管理テーブル個別部の先頭アドレス取得

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndTopAdr=%p )\n",
														D_PROC_NAME, ptRdIndTopAdr ) );

    /************************************/
	/*	リクエスト識別子の確認			*/
	/************************************/
    if( D_RD_NONE == rd )							// リクエスト識別子がなしの時
    {
													// rd管理テーブル個別部先頭からリクエスト状態
													// が未予約かつ未使用かつ未要求の個別部を検索
//2003.02.19		for( iLoopCnt = 0; iLoopCnt < ptErdc->lMaxIndNum; iLoopCnt++ )
		for( iLoopCnt = 0; iLoopCnt < ptMyEPRC->lMaxReqNum; iLoopCnt++ )
		{
//			if( D_RES_OFF ==  ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat )
													// リクエスト状態が
													// 未予約かつ未使用かつ未要求の場合
			if( D_ERDC_RESSTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cUCompStat )
			{
													// 個別部の先頭アドレス取得
				ptRdIndAdr = ptRdIndTopAdr + iLoopCnt;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

				lRId = ptRdIndAdr->lRCode;			// 個別部のリクエスト識別子取得

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRId=%ld )\n",
														D_PROC_NAME, lRId ) );
				break;								// 処理を抜ける
			}
		}

		if( lRId == D_RD_NONE )						// 予約未が見つからなかった時
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSEEOVRQ ) );
    														
    		os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEOVRQ );
    														
			return( OSEEOVRQ );						// OSEEOVRQを返却
		}
	}
													// リクエスト識別子が最小値から個別部数の間の時
//2003.02.19    else if(( D_RD_MIN <= rd ) && ( ptErdc->lMaxIndNum >= rd ))
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {
		ptRdIndAdr = ptRdIndTopAdr + rd - 1;		// 指定個別部のアドレス取得

    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// 予約状態が予約未の時
		if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
    		os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEIVRD );
    														
			return( OSEEIVRD );						// OSEEIVRDを返却
		}
													// 非完了要求状態が要求済の時
		if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEUSED ) );
    														
   			os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEUSED );
    		
			return( OSEEUSED );						// OSEEUSEDを返却
		}
		
		lRId = rd;									// リクエスト識別子の取得
	}
	else											// リクエスト識別子がその他の時
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
    	os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEIVRD );
    	
		return( OSEEIVRD );							// OSEEIVRDを返却
	}

    /************************************/
	/*	時間の確認						*/
	/************************************/
    if( D_TIME_MIN > times )						// 時間が最小値より小さい場合
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
    	os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEITIM );
    														
		return( OSEEITIM );							// OSEEITIMを返却
	}


/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	/************************************************/
	/*	タイムアウト時間の算出						*/
	/************************************************/
	switch( unit )
	{
		case D_UNIT_MSEC:							// 単位時間がミリ秒の時
/*****	仕様変更番号SSLA0042の対応		Start							修正日：2003.07.15	*****/
/************************************************************************************************/
/*	仕様変更により時間の最大値チェック処理を削除												*/
/************************************************************************************************/
													// マイクロ秒の設定（値の切上げ処理）
//			lMicroSec = ((( long )(( times + ( D_UPMSEC_TEN - 1 )) / D_UPMSEC_TEN )) 
//			                                                 * D_UPMSEC_TEN * 1000 );
//			lSec = 0;								// 秒の設定

			lSec      = times / 1000;				// 秒の算出
			lMilliSec = times % 1000;				// ミリ秒の算出
													// マイクロ秒の設定（値の切上げ処理）
			lMicroSec = ((lMilliSec + ( D_UPTIME_TEN - 1 )) / D_UPTIME_TEN)
														   * D_UPMSEC_TEN * 1000;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMilliSec=%ld )\n",
															D_PROC_NAME, lMilliSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
/*****	仕様変更番号SSLA0042の対応		 End							修正日：2003.07.15	*****/
			break;
			
		case D_UNIT_SEC:							// 単位時間が秒の時
			lMicroSec = 0;							// マイクロ秒の設定
			lSec = times;							// 秒の設定

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		case D_UNIT_MINUTE:							// 単位時間が分の時
			if( D_MIN_MAX < times )					// 時間が分の最大値を超えている時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
												
				os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );											
															
				return( OSEEITIM );					// OSEEITIMを返却
			}

			lMicroSec = 0;							// マイクロ秒の設定
			lSec = times * 60;						// 秒の設定（分を秒に変換）

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		case D_UNIT_HOUR:							// 単位時間が時の時
			if( D_HOUR_MAX < times )				// 時間が時の最大値を超えている時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
															
				os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );
															
				return( OSEEITIM );					// OSEEITIMを返却
			}

			lMicroSec = 0;							// マイクロ秒の設定
			lSec = times * 60 * 60;					// 秒の設定（時を秒に変換）

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		default:									// 単位時間がその他の時
	 		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
															D_PROC_NAME, OSEEIUNI ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEIUNI );												
															
			return( OSEEIUNI );						// OSEEIUNIを返却
	}

	/************************************************/
	/*	rd管理テーブルの編集						*/
	/************************************************/
	ptRdIndAdr->tReqStat.cUCompStat = D_UCOMP_ON;	// 非完了要求状態を要求済に設定
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;		// 要求種別にossttimの対応値を設定

	/*******  U00010 リクエスト番号設定処理を追加 2002．12．10*********/
	ptRdIndAdr->lReqNum = ptErdc->ulMstReqNum;		// リクエスト番号にマスタリクエスト番号を設定
	ptErdc->ulMstReqNum++;							// マスタリクエスト番号に1加算
	ptRdIndAdr->lPCode = ptMyEPRC->lPCode;			// プロセス識別子を設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=0x%02x )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
														D_PROC_NAME, ptErdc->ulMstReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
															D_PROC_NAME, ptRdIndAdr->lPCode ) );

	/************************************************/
	/*	タイマ制御の起動							*/
	/************************************************/
													// タイマ発行
	lRet = os_tmctl( lRId, ptRdIndAdr->lReqNum, lMicroSec, lSec );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	if( NORMAL != lRet )							// タイマが正常に終了されなかった時
	{
		goto err_os_tmctl;							// 異常処理に遷移
	}


/****************************************************************************/
/* 終了処理                                                                 */
/****************************************************************************/
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSSTTIM, D_T_TRA_OUT, 1, lRId );

	return( lRId );									// リクエスト識別子を返却


/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_os_tmctl:
													// 非完了要求状態を要求未に設定
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS00;		// 要求種別に初期値を設定
	ptRdIndAdr->lReqNum = 0;						// リクエスト番号に初期値を設定
	ptErdc->ulMstReqNum--;							// マスタリクエスト番号を1減算
	ptRdIndAdr->lPCode = D_PCODE_INI;				// プロセス識別子に初期値を設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=%d )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
												D_PROC_NAME, ptErdc->ulMstReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lPCode ) );

	switch( lRet )
	{
		case OSEEITIM:								// OSEEITIMの時
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );
															
			return( OSEEITIM );						// OSEEITIMを返却
			break;
			
		default:									// その他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
															D_PROC_NAME, -1 ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, -1 );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTTIM << 16) | D_T_ERR_SYS );
			//return( -1 );;							// アボート処理
			break;
	}
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
