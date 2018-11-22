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
/* ＜サービス項目名＞				 イベント制御												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 イベントの受信待ち											*/
/* ＜モジュールＩＤ＞				 oswaitev													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ江川)				*/
/* ＜ソース作成年月日＞ 			 ２００２年　８月３０日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 イベントの受信待ち																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oswaitev.h>																*/
/*																								*/
/*	   	long	oswaitev( long evn, long count, long limit ) 									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	evn;		イベント番号														*/
/*		long	count;		減算値（未使用：0を指定）											*/
/*		long	limit;		制限時間（-1）														*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEILIM																*/
/*						OSEEIEVN																*/
/*						OSEENEXS																*/
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "oswaitev.h"
#include "oswaitev_ins.h"                         // 内部参照用（個別）

/**************************************************************************************************/
/* 機能：イベントの受信待ち                                                                       */
/* 作成日：2002年8月30日                                                                          */
/* 変更日：                                                                                       */
/* 作成者：江川                                                                                   */
/* 呼出形式：                                                                                     */
/*   long oswaitev( long evn, long count, long limit )                                            */
/*     long evn            イベント番号(0〜1024)                                                  */
/*     long count          減算値（未使用：0を指定）                                              */
/*     long limit          制限時間（-1）                                                         */
/*                                                                                                */
/**************************************************************************************************/
long oswaitev( long evn, long count, long limit )
{
	int  iGetTmDay = 0; 						// gettimeofday返却値
	int  iMsgRcv = 0;							// msgrcv返却値
	long lMsgQId = 0;							// メッセージキューID
	long lMsgType = 0;							// メッセージタイプ 20030330 追加

	struct msgbuf tRcvMsg;						  // 受信バッファ設定情報
	struct timeval tTmVal;						  // 取得時間設定情報
	
	os_trcget2( D_MD_OSWAITEV, D_T_TRA_IN, 3, evn, count, limit );
	
//	DbgMsg01( DLv05, ( OutPut, "***** evn   :%ld\n", evn));
//	DbgMsg01( DLv05, ( OutPut, "***** count :%ld\n", count));
//	DbgMsg01( DLv05, ( OutPut, "***** limit :%ld\n", limit));
    //********************************************
    //***** 引数チェック
    //*****
    if(( D_VALUE_MIN > evn ) || ( D_VALUE_MAX < evn ))
    {                                             // イベント番号
    	DbgMsg01( DLv05, ( OutPut, "***** 01: Parameter Err env \n") );
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_PRA, 1, OSEEIEVN );
    	
        return( OSEEIEVN );
    }

    if( D_VALUE_WAIT != limit )
    {                                             // 制限時間
    	DbgMsg01( DLv05, ( OutPut, "***** 02: Parameter Err limit \n") );
    	
    	os_trcget2( D_MD_OSWAITEV, D_T_ERR_PRA, 1, OSEEIEVN ); 	
    	
        return( OSEEIEVN );
    }

    //**************************************************
    //***** メッセージキューIDの取得
    //*****

	lMsgQId = ptMyEMBC->lMsgQId;				// 自プロセスのメッセージキューを取得
    DbgMsg01( DLv04, ( OutPut, "***** lMsgQId : %lx\n" ,lMsgQId));
    DbgMsg01( DLv04, ( OutPut, "***** lPCode : %lx\n" ,ptMyEMBC->lPCode));
    

    //**************************************************
    //***** メッセージの受信待ち
    //*****
												//20030330 削除 Start
/*
	tRcvMsg.mtype = D_EVENT_MSGTYPE + evn;        // メッセージタイプの設定
	DbgMsg01( DLv04, ( OutPut, "***** tRcvMsg.mtype : %ld\n", tRcvMsg.mtype));

	do{                                           // 受信データの設定
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_GETTIMEOFDAY, 2, &tTmVal, D_VALUE_TZONE );
		iGetTmDay = gettimeofday( &tTmVal, D_VALUE_TZONE );
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_END, 1, iGetTmDay );

		if( D_ERR_GETTMDAY == iGetTmDay && EINTR != errno )
		{
			goto err_oswaitev;
		}
	} while( D_ERR_GETTMDAY == iGetTmDay );
	sprintf( tRcvMsg.mtext, "%ld", tTmVal.tv_sec);
	DbgMsg01( DLv04, ( OutPut, "***** tRcvMsg.mtext : %s\n", tRcvMsg.mtext));
												// 20030330 削除 End
*/
												// 20030330 修正
	lMsgType = D_EVENT_MSGTYPE + evn;        // メッセージタイプの設定
	DbgMsg01( DLv04, ( OutPut, "***** lMsgType : %08lx\n", lMsgType));

	do{                                           // メッセージの受信待ち
//		os_trcget2( D_MD_OSWAITEV, D_T_SYS_MSGRCV, 5, lMsgQId, &tRcvMsg, 
//						sizeof(tRcvMsg.mtext[D_AREA_SIZE]), tRcvMsg.mtype,MSG_NOERROR );
//		iMsgRcv = msgrcv( lMsgQId, &tRcvMsg, sizeof(tRcvMsg.mtext[D_AREA_SIZE]), tRcvMsg.mtype,
//						MSG_NOERROR );
												// 20030330 修正
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_MSGRCV, 5, lMsgQId, &tRcvMsg, 
						sizeof(long), tRcvMsg.mtype,MSG_NOERROR );
		iMsgRcv = msgrcv( lMsgQId, &tRcvMsg, sizeof(long), lMsgType,
						MSG_NOERROR );

		os_trcget2( D_MD_OSWAITEV, D_T_SYS_END, 1, iMsgRcv );

		if( D_ERR_MSGRCV == iMsgRcv && EINTR != errno )
		{
			DbgMsg01( DLv05, ( OutPut, "***** 03:msgrcv Err Mess :%s\n", strerror(errno) ) );
			goto err_oswaitev;
		}
	}while( D_ERR_MSGRCV == iMsgRcv );

//	DbgMsg01( DLv05, ( OutPut, "***** End osevent\n"));
	
	os_trcget2( D_MD_OSWAITEV, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

//**************************************************************************************************
//***** 異常処理
//*****
err_oswaitev:

    switch( errno ){
    case ENOENT: 
    	DbgMsg01( DLv05, ( OutPut, "***** Err OSEENEXS\n"));
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_SYS, 1, errno ); 
    	
	    return( OSEENEXS ); 
	    break;
	case EIDRM: 
    	DbgMsg01( DLv05, ( OutPut, "***** Err OSEEWKEX\n"));
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_SYS, 1, errno ); 
    	
	    return( OSEEWKEX ); 
	    break;
    default:     
    	os_trcget2( D_MD_OSWAITEV, D_T_ERR_ABT, 1, errno ); 
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSWAITEV << 16) | D_T_ERR_SYS );
    }

}
/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
