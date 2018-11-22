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
/* ＜モジュールＩＤ＞				 os_SendTimeOutMsg											*/
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
/* 作成者:王旗                                                              */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日:2002年10月8日                                                     */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 タイムアウトメッセージの送信																*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_SendTimeOutMsg.h>														*/
/*																								*/
/*		long	os_SendTimeOutMsg( long lPCode,long lReqNum, long lResult )						*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	lPCode;		プロセス識別子														*/
/*		long	lReqNum;	リクエスト番号														*/
/*		long	lResult;	リザルト															*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		-1				アボート												*/
/*						OSEEWKEX		msgsndが失敗											*/
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
#include "os_SendTimeOutMsg_ins.h"
#include <malloc.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

/****************************************************************************/
/* 機能:タイムアウトメッセージの送信                                        */
/* 作成日:2002年10月8日                                                     */
/* 変更日:                                                                  */
/* 作成者:王旗                                                              */
/* 呼出形式:                                                                */
/*   long os_SendTimeOutMsg( long lPCode,long lReqNum, long lResult )       */
/*      long lPCode         プロセス識別子                                  */
/*      long lReqNum        リクエスト番号                                  */
/*      long lResult        リザルト                                        */
/*                                                                          */
/****************************************************************************/
long os_SendTimeOutMsg(long lPCode,long lReqNum, long lResult )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    long lIndex = 0;                        // 個別部のIndex
    long lMsgQId = 0;                       // メッセージキューID */
    TEtmcTableInd *ptTimeOut = NULL;           // タイマ管理テーブルの
                                        // タイムアウトする個別部
    TEmbcTableInd *ptTEmbcTableInd = NULL;     // メイルボックス管理テーブル個別部の
                                        // 先頭アドレス
    TEmbcTableInd *ptTEmbcTableIndAdr = NULL;  // メイルボックス管理テーブル個別部の
                                        // アドレス
    int iLength = 0;
    TMyMessage tMsgBuf;          		// メッセージバッファ
    int iRes = 0;                           // リターンコード

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
    os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_TRA_IN, 3, lPCode, lReqNum, lResult );

    ptTEmbcTableInd = ( TEmbcTableInd * )( ptEmbc + 1 );
                                        // メッセージ構造体ポインタ
//    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEmbcTableInd=%p )\n",
//    												D_PROC_NAME, ptTEmbcTableInd ) );
	DbgMsg01( DLv04, (OutPut, "%s ***** lPCode  : %08lx\n", "os_SendTimeOutMsg", lPCode));
	DbgMsg01( DLv04, (OutPut, "%s ***** lReqNum : %08lx\n", "os_SendTimeOutMsg", lReqNum));
	DbgMsg01( DLv04, (OutPut, "%s ***** lResult : %08lx\n", "os_SendTimeOutMsg", lResult));

    lIndex = 0;                         // メイルボックス管理テーブルの個別部
                                        // 情報の先頭から、プロセス識別子と
                                        // lPCodeが合致する個別部を検索する
    while( lIndex < ptEmbc->lIndPartNum )
    {
        if( ( ptTEmbcTableInd + lIndex )->lPCode == lPCode )
        {
            ptTEmbcTableIndAdr = ( TEmbcTableInd * )ptTEmbcTableInd + lIndex;
                                        // システム個別部の先頭アドレスを取得
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEmbcTableIndAdr=%p )\n",
    												D_PROC_NAME, ptTEmbcTableIndAdr ) );
                                        
            lMsgQId = ptTEmbcTableIndAdr->lMsgQId;
                                        // システム個別部のメッセージキュー
                                        // ＩＤを取得
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMsgQId=%ld )\n",
    												D_PROC_NAME, lMsgQId ) );

    		DbgDmp02( DLv04, ("ptTEmbcTableInd   ダンプ", ptTEmbcTableInd + lIndex,
    								 sizeof(TEmbcTableInd),1,0));
            DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIndex=%ld )\n",D_PROC_NAME, lIndex ) );
			
			break;
        }
        lIndex++;
//    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIndex=%ld )\n",
//    												D_PROC_NAME, lIndex ) );
    }
    
    if( lIndex >= ptEmbc->lIndPartNum ) // ptEmbc->lIndPartNum:最大個別部数
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    													D_PROC_NAME, -1 ) );
        return( -1 );                   // アボート処理
    }

    tMsgBuf.lMsgtype = D_TIMEOUT_MSG; 	// メッセージタイプに[タイムアウト通知]
                                        // を設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lMsgtype ) );

    tMsgBuf.pcBufAdr = D_PBUF_FIX;    	// プールバッファアドレスを設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
    												D_PROC_NAME, tMsgBuf.pcBufAdr ) );

    tMsgBuf.lReqid = lReqNum;         	// リクエスト番号を設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lReqid ) );

    tMsgBuf.lDatesize = D_DATESIZE_FIX;
                                        // データサイズを設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lDatesize ) );
    												
    tMsgBuf.lResult = lResult;        	// リザルトを設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lResult ) );

    iLength = sizeof(TMyMessage) - sizeof(long);
    									// msgsndのメッセージ長には
										// メッセージタイプ(long)のバイト数
										// を除いた後のバイト数を設定する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLength=%d )\n",
    												D_PROC_NAME, iLength ) );

	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_SYS_MSGSND, 4,
						lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
	
    iRes = msgsnd( lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
                                        // メッセージの送信
	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_SYS_END, 2, iRes, errno);
	
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRes=%d )\n",
    												D_PROC_NAME, iRes ) );

    if( iRes == D_ERR_SYS ) 
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: %s\n", D_PROC_NAME, strerror(errno)) );
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    													D_PROC_NAME, OSEEWKEX ) );
        return( OSEEWKEX );             // msgsndが失敗
    }

    ptTimeOut = ( TEtmcTableInd * )ptEtmc->ptNxtAdr;
    									// タイムアウトする個別部を取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut=%p )\n",
    												D_PROC_NAME, ptTimeOut ) );

    ptTimeOut->lReqNum = D_REQUESTNO_INI;
                                        // リクエスト番号の初期化
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut->lReqNum=%ld )\n",
    												D_PROC_NAME, ptTimeOut->lReqNum ) );
                                        
    ptTimeOut->dTimer = D_TIMER_INI;    // タイマ値の初期化
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut->dTimer=%lf )\n",
    												D_PROC_NAME, ptTimeOut->dTimer ) );

	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_TRA_OUT, 0);
    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
    return( NORMAL );                   // 正常終了
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

