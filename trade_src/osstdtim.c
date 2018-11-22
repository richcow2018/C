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
/* ＜モジュール名＞					 時刻タイマの設定											*/
/* ＜モジュールＩＤ＞				 osstdtim													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ梶原)				*/
/* ＜ソース作成年月日＞ 			 ２００２年１０月０１日 									*/
/* ＜ソース修正者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００２年１２月１０日 									*/
/* ＜ソース修正者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０３月０３日 	仕様変更番号（ＳＳＬＡ００１５）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０６月１６日     仕様変更番号（ＳＳＬＡ００３１）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		rd管理テーブル（ERDC）からリクエスト識別子に対応する個別部を取得する。					*/
/*		取得した個別部のリクエスト状態をチェックし、その個別部を更新する。						*/
/*		タイムアウト時間を算出しos_tmctlを起動する。											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osstdtim.h>																*/
/*																								*/
/*   long ossdtim( long rd, long day, long time )                                               */
/*																								*/
/* ＜仮引数＞																					*/
/*     long rd             リクエスト識別子                                                     */
/*     long day            日付                                                                 */
/*     long time           時刻                                                                 */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		リクエスト識別子														*/
/*		異常終了		OSEEIVAL			日付又は、時刻の値が不当である。					*/
/*						OSEEIVRD			指定rdは予約されていない。又は、不当な値である。	*/
/*						OSEEUSED			指定rdは使用中である。								*/
/*						OSEEWKEX			システム作業域が不足した。							*/
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
#include "osstdtim.h"
#include "os_tmctl.h"					// タイマ制御
#include "osstdtim_ins.h"				// 内部参照用（個別）
#include "os_ERDC_ins.h"

/****************************************************************************/
/* 機能：時刻タイマの設定                                                   */
/* 作成日：2002年10月1日                                                    */
/* 変更日：2002年12月10日                                                   */
/* 作成者：梶原                                                             */
/* 呼出形式：                                                               */
/*   long ossdtim( long rd, long day, long time )                           */
/*     long rd             リクエスト識別子                                 */
/*     long day            日付                                             */
/*     long time           時刻                                             */
/*                                                                          */
/****************************************************************************/
long osstdtim( long rd, long day, long time )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    int iRet = 0;									// 関数の結果返却値
    int iLoopCnt = 0;								// ループカウンタ
    long lRId = 0;									// リクエスト識別子
    long lMicroSec = 0;								// マイクロ秒
    long lSec = 0;									// 秒
    long lRet = 0;									// 関数の結果返却値
    long lTmp = 0;
    double dTimeOut = 0;							// タイムアウト時間
    time_t lSiteiSec = 0;							// 指定秒
    time_t lStdSec = 0;								// 基準秒
    struct tm tDate;								// 日付格納体
    struct timeval tNowTime;						// 時間格納体
    TErdcTableInd *ptRdIndTopAdr = NULL;			// rd管理テーブル個別部の先頭アドレス
	TErdcTableInd *ptRdIndAdr = NULL;				// rd管理テーブル個別部のアドレス
/*****  仕様変更（SSLA0031）	Start									修正日：2003.06.12  *****/
	long lIndex = 0;								// 個別部のIndex
	long lMsgQId = 0;								// メッセージキューID */
	int iLength = 0;								// メッセージ長
	TMyMessage tMsgBuf;								// メッセージバッファ
/*****  仕様変更（SSLA0031）	End  									修正日：2003.06.12  *****/

	os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_IN, 3, rd, day, time  );


//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	/************************************************/
	/*	引数の確認									*/
	/************************************************/
    												// rd管理テーブル個別部の先頭アドレス取得
    ptRdIndTopAdr = ((TErdcTableInd *)( ptErdc + 1 ));

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
													// 予約状態が予約未の時
//			if( D_RES_OFF == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat )
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
    														D_PROC_NAME, OSEEIVRD ) );
    														
    		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  );												
    														
			return( OSEEIVRD );						// OSEEIVRDを返却
		}
	}
													// リクエスト識別子が最小値から個別部数の間の時
//2003.02.19    else if(( D_RD_MIN <= rd ) && ( ptErdc->lMaxIndNum >= rd ))
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {
		ptRdIndAdr = ptRdIndTopAdr + ( rd - 1 );	// 指定個別部のアドレス取得

    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// 予約状態が予約未の時
		if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
   			os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  );												
    														
			return( OSEEIVRD );						// OSEEIVRDを返却
		}

													// 非完了要求状態が要求済の時
		if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEUSED ) );
    														
			os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEUSED  );   														
    														
			return( OSEEUSED );						// OSEEUSEDを返却
		}

		lRId = rd;									// リクエスト識別子の取得
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRId=%ld )\n", D_PROC_NAME, lRId ) );
	}
	else											// リクエスト識別子がその他の時
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  ); 
    														
		return( OSEEIVRD );							// OSEEIVRDを返却
	}

	/************************************/
	/*	日付の確認						*/
	/************************************/
													// 20030303 仕様変更SSLA0015対応
	if(0 == day)									// 日付が０の時は本日の日付を設定
	{
		lRet = osgtdat(&day, &lTmp);
		if(NORMAL != lRet)
			return(lRet);
	}

	/************************************/
	/*	日付時刻の変換					*/
	/************************************/
	lRet = os_DayTime2Date( day, time, &tDate );	// 日付時刻を日時に変換
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	if( NORMAL != lRet )							// 変換に失敗した時
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEIVAL ) );
    														
   		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_SYS, 1, OSEEIVAL ); 													
		
		return( OSEEIVAL );							// OSEEIVALを返却
	}


/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	/************************************************/
	/*	タイムアウト時間の算出						*/
	/************************************************/
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  

	iRet = gettimeofday( &tNowTime, NULL );			// 現在日時の取得
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 1, iRet ); 

	if( D_ERR_SYS == iRet )							// 日時の取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "gettimeofday", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, errno    ); 							
									
		return( OSEEWKEX );							// OSEEWKEXを返却
	}

	lStdSec = tNowTime.tv_sec;						// 現在日時の秒を設定
	
	os_trcget2( D_MD_OSSTDTIM,  D_T_SYS_MKTIME, 1, &tDate ); 
	
	lSiteiSec = mktime( &tDate );					// 指定日時の取得

	os_trcget2( D_MD_OSSTDTIM,  D_T_SYS_END, 1, lSiteiSec );

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lStdSec=%ld )\n", D_PROC_NAME, lStdSec ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSiteiSec=%ld )\n", D_PROC_NAME, lSiteiSec ) );

	if( D_ERR_SYS == lSiteiSec )					// 指定日時の取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM,  D_T_ERR_SYS, 1, errno    );
									
		return( OSEEIVAL );							// OSEEIVALを返却
	}
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_DIFFTIME, 2, lSiteiSec, lStdSec ); 
	
	dTimeOut = difftime( lSiteiSec, lStdSec );		// 現在日時から指定日時までの時間を取得
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 1, dTimeOut ); 
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( dTimeOut=%lf )\n", D_PROC_NAME, dTimeOut ) );

	if( D_SEC_MIN >= dTimeOut )						// 時間の取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "difftime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, errno    ); 
									
/*****  仕様変更（SSLA0031）	Start									修正日：2003.06.16  *****/
		/********************************************/
		/*  rd管理テーブルの編集					*/
		/********************************************/
													// 非完了要求状態を要求済に設定
		ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
		ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;	// 要求種別にインターバルタイマを設定
		ptRdIndAdr->lReqNum = ptErdc->ulMstReqNum;	// リクエスト番号にマスタリクエスト番号を設定
		ptErdc->ulMstReqNum++;						// マスタリクエスト番号に1加算
		ptRdIndAdr->lPCode = ptMyEPRC->lPCode;		// プロセス識別子を設定
		
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

		/********************************************/
		/*  メッセージバッファの編集				*/
		/********************************************/
		tMsgBuf.lMsgtype = D_TIMEOUT_MSG;			// メッセージタイプに[タイムアウト通知]を
													// 設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
									D_PROC_NAME, tMsgBuf.lMsgtype ) );
		
		tMsgBuf.pcBufAdr = D_PBUF_FIX;				// プールバッファアドレスを設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
									D_PROC_NAME, tMsgBuf.pcBufAdr ) );

		tMsgBuf.lReqid = ptRdIndAdr->lReqNum;		// リクエスト番号を設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
									D_PROC_NAME, tMsgBuf.lReqid ) );

		tMsgBuf.lDatesize = D_DATESIZE_FIX;			// データサイズを設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
									D_PROC_NAME, tMsgBuf.lDatesize ) );

		tMsgBuf.lResult = D_RESULT_NORMAL;			// リザルトを設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
									D_PROC_NAME, tMsgBuf.lResult ) );

		lMsgQId = ptMyEMBC->lMsgQId;				// 自メールボックスのメッセージキューを設定
		
		iLength = sizeof(TMyMessage) - sizeof(long);
													// msgsndのメッセージ長には
													// メッセージタイプ(long)のバイト数
													// を除いた後のバイト数を設定する
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLength=%d )\n",
									D_PROC_NAME, iLength ) );

		/********************************************/
		/*  メッセージの送信						*/
		/********************************************/
		os_trcget2( D_MD_OSSTDTIM, D_T_SYS_MSGSND, 4, lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
		iRet = msgsnd( lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
		os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 2, iRet, errno);
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
		if( iRet == D_ERR_SYS ) 
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: %s\n",
									D_PROC_NAME, strerror(errno)) );

			goto err_msgsnd;
		}
		
		DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
		os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_OUT, 1, lRId  );
		return( lRId );								// リクエスト識別子を返却し終了
//		return( OSEEIVAL );							// OSEEIVALを返却
/*****  仕様変更（SSLA0031）	End  									修正日：2003.06.16  *****/
	}

	lSec = ( long )dTimeOut;						// 秒の設定
	lMicroSec = 0;									// マイクロ秒の設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n", D_PROC_NAME, lSec ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n", D_PROC_NAME, lMicroSec ) );

	/************************************************/
	/*	rd管理テーブルの編集						*/
	/************************************************/
													// 非完了要求状態を要求済に設定
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
//	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS03;		// 要求種別にosstdtimの対応値を設定
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;		// 要求種別にインターバルタイマを設定

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
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_OUT, 1, lRId  );

	return( lRId );									// リクエスト識別子を返却し終了


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
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   			os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, OSEEITIM ); 	
    														
			return( OSEEITIM );						// OSEEITIMを返却
			break;
			
		default:									// その他の時
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
    														D_PROC_NAME, -1 ) );
    		
    		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, -1 ); 												
    		
    		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTDTIM << 16) | D_T_ERR_SYS );
			//return( -1 );							// アボート処理
			break;
	}
/*****  仕様変更（SSLA0031）	Start									修正日：2003.06.16  *****/
err_msgsnd:
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

	os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, -1 );
	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTDTIM << 16) | D_T_ERR_SYS1 );
/*****  仕様変更（SSLA0031）	End  									修正日：2003.06.16  *****/
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/

