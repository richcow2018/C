/****************************************************************************/
/*	著作権	２００２														*/
/*			  株式会社ＮＴＴデータ											*/
/*				金融ビジネス事業本部										*/
/*																			*/
/*																			*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ				*/
/****************************************************************************/
/* ＜対象業務名＞				ＴＲＡＤＥエミュレータ						*/
/* ＜対象業務ＩＤ＞ 			ＴＲＥ 										*/
/* ＜サービス項目名＞			メッセージ通信								*/
/* ＜サービス項目ＩＤ＞ 		ＸＸＸＸＸＸＸ								*/
/* ＜モジュール名＞				メイルボックスの作成						*/
/* ＜モジュールＩＤ＞			oscremb										*/
/* ＜モジュール通番＞			ＸＸＸＸＸＸＸ								*/
/*--------------------------------------------------------------------------*/
/* ＜適用機種名＞				汎用サーバ									*/
/* ＜適用ＯＳ＞ 				Ｌｉｎｕｘ 									*/
/* ＜開発環境＞ 				ＲＨＡＳ２．１								*/
/* ＜記述言語＞ 				Ｃ言語 										*/
/* ＜モジュール形態＞			関数										*/
/* ＜機能区分＞ 															*/
/* ＜対象データ＞															*/
/* ＜工程・階層区分＞														*/
/*--------------------------------------------------------------------------*/
/* ＜開発システム名＞			ＬＡＬａ−ＳＭＰシステム					*/
/* ＜開発システム番号＞ 		ＰＰ４０Ｂ００１２２０						*/
/*--------------------------------------------------------------------------*/
/* ＜開発担当名＞				ＣＢ事ビジネス企画担当(メーカー：サプライ)	*/
/* ＜電話番号＞ 				148-1457(03-5437-1457)						*/
/*--------------------------------------------------------------------------*/
/* ＜設計者名＞ 				ＸＸＸＸＸＸＸ								*/
/* ＜設計年月日＞				ＸＸＸＸＸＸＸ		 						*/
/* ＜設計修正者名＞ 														*/
/* ＜設計修正年月日及び修正ＩＤ＞											*/
/*--------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 五味									*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月１９日 				*/
/* ＜ソース修正者＞ 			 	 										*/
/* ＜ソース修正年月日及び修正ＩＤ＞											*/
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ＸＸＸステップ							*/
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞ 															*/
/*	 メイルボックスの作成  													*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞ 															*/
/*		long	oscremb( long mbid, long access )							*/
/*																			*/
/* ＜仮引数＞																*/
/*		long	mbid					メイルボックス識別子				*/
/*		long	access					アクセス権（未使用）				*/
/*																			*/
/* ＜返却値＞																*/
/*	   メイルボックス識別子													*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 													*/
/* ＜制限事項＞ 															*/
/*	   特になし 															*/
/* ＜使用外部モジュールＩＤ＞												*/
/* ＜呼出元のモジュールＩＤ＞												*/
/*																			*/
/*																			*/
/****************************************************************************/

/******************************** 標準ヘッダ・ファイル **********************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "oscremb.h"
#include "oscremb_ins.h"
#include "u_mpf.h"                      // ntok用


/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    oscremb                                                   */
/*                                                                          */
/*  ＜機能概要＞  メイルボックスの作成                                      */
/*                                                                          */
/****************************************************************************/
long oscremb( long mbid, long access )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
//	BlpMpf_Key_t lIpcKey;				// IPCキー
	BlpMpf_key_t lIpcKey;               // IPCキー
	char acMBoxKey[D_MBKEY_LEN];		// メイルボックス識別子文字列
	long lAsso;							// 種別
	long lSerNum;						// 通番
	int iLoopCnt;						// ループカウンタ
	int iRet;							// 関数結果返却
	TEmbcTableInd *ptIndTopAdr;			// メイルボックス管理テーブル個別部の先頭アドレス
	TEmbcTableInd *ptIndAdr;			// メイルボックス管理テーブル個別部のアドレス
	
	os_trcget2( D_MD_OSCREMB, D_T_TRA_IN, 2, mbid, access );
	

//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	lAsso = os_GetAsso(mbid);			// 種別の取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lAsso=%ld )\n",
    												D_PROC_NAME, lAsso ) );
    												
	lSerNum = os_GetSerNum(mbid);		// 通番の取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSerNum=%ld )\n",
    												D_PROC_NAME, lSerNum ) );
    												
	switch(lAsso)
	{
		case D_ASSO_NONE:				// 種別がなしの時
			if( lSerNum != D_SERNUM_NONE )
			{							// 通番がなし以外の時
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    													D_PROC_NAME, OSEEIMBI ) );
    			
    			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEIMBI );										
    													
				return( OSEEIMBI );		// OSEEIMBIを返却
			}
			break;
		case D_ASSO_MB:					// 種別がメイルボックス識別子の時
			if( (lSerNum < D_SERNUM_MIN) || (lSerNum > ptEmbc->lUserIndNum) )
			{							// 通番がユーザー個別部の範囲外である時
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    													D_PROC_NAME, OSEENEXS ) );
    			
    			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENEXS );											
    													
				return( OSEENEXS );		// OSEENEXSを返却
			}
			break;
		default:						// 種別がその他の時
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    													D_PROC_NAME, OSEEIMBI ) );
    													
   			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEIMBI );
    		
			return( OSEEIMBI );			// OSEEIMBIを返却
	}

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	ptIndTopAdr = ( TEmbcTableInd * )( ptEmbc + 1 );
										// 個別部の先頭アドレスの取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndTopAdr=%p )\n",
    												D_PROC_NAME, ptIndTopAdr ) );
    												
	if( lAsso == D_ASSO_NONE )			// 種別がなしの時
	{
		ptIndAdr = NULL;
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
    												
		for( iLoopCnt = ptEmbc->lUserIndNum; iLoopCnt < ptEmbc->lIndPartNum; iLoopCnt++ )
		{								// システム個別部の先頭から順に処理をする
			if( ( ptIndTopAdr + iLoopCnt )->lMsgQId == D_MSGQID_NONE )
			{							// 個別部が未作成の時
				ptIndAdr = ptIndTopAdr + iLoopCnt;
										// 見つかったシステム個別部を取得
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
				break;					// 繰り返しから抜ける
			}
		}
		if( ptIndAdr == NULL )			// 未作成のシステム個別部が見つからなかった時
		{
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    													D_PROC_NAME, OSEEWKEX ) );
    													
    		os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEWKEX );											
    													
			return( OSEEWKEX ) ;		// OSEEWKEXを返却
		}
	}
	else								// 種別がメイルボックス識別子の時
	{
		ptIndAdr = ptIndTopAdr + lSerNum - 1;
										// 指定のユーザー個別部を取得
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
    												
		if( ptIndAdr->lMsgQId != D_MSGQID_NONE )
		{								// 未作成でない時
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    													D_PROC_NAME, OSEEEXST ) );
    										
    		os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEEXST );												
    													
			return( OSEEEXST );			// OSEEEXSTを返却
		}
	}
	
	sprintf( acMBoxKey, "%08x", (unsigned int)ptIndAdr->lMBoxId );
										// メイルボックス識別子を文字列に変換
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( acMBoxKey=%s )\n",
    												D_PROC_NAME, acMBoxKey ) );
    												
    lIpcKey = BlpMpf_ntok( acMBoxKey, D_NTOK_PID );
    									// IPCキー取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIpcKey=%ld )\n",
    												D_PROC_NAME, lIpcKey ) );
    												
    if( D_ERR_SYS == lIpcKey )			// IPCキー取得に失敗した時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    													D_PROC_NAME, -1 ) );
    											
    	os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, -1 );
    	return( OSEEIMBI );
    	//return( -1 );					// -1を返却
	}

	os_trcget2( D_MD_OSCREMB, D_T_SYS_MSGGET, 2, lIpcKey, D_MSGGET_FLG );

	iRet = msgget( lIpcKey, D_MSGGET_FLG );
										// メッセージキューの作成
										
	os_trcget2( D_MD_OSCREMB, D_T_SYS_END, 1, iRet  );									
										
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
    												D_PROC_NAME, iRet ) );
    												
	if( iRet == D_ERR_SYS )				// 作成に失敗した時
	{
		goto err_oscremb;				// 異常処理に遷移
	}

	ptIndAdr->lMsgQId = iRet;			// 個別部にメッセージキューIDを設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr->lMsgQId=%ld )\n",
    												D_PROC_NAME, ptIndAdr->lMsgQId ) );

//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSCREMB, D_T_TRA_OUT, 1, ptIndAdr->lMBoxId );
	
	return( ptIndAdr->lMBoxId );		// メイルボックス識別子を返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_oscremb:
	switch( errno )
	{
		case EACCES:					// EACCESの時
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEENPRV, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENPRV );
									
			return( OSEENPRV );			// OSEENPRVを返却
			break;
		case EEXIST:					// EEXISTの時
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEEXST, "msgget", strerror(errno) ) );
			
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEEXST );						
									
			return( OSEEEXST );			// OSEEEXSTを返却
			break;
		case EIDRM:						// EIDRM, ENOENTの時
		case ENOENT:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEENEXS, "msgget", strerror(errno) ) );
							
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENEXS );						
									
			return( OSEENEXS );			// OSEENEXSを返却
			break;
		case ENOMEM:					// ENOMEM, ENOSPCの時
		case ENOSPC:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEWKEX );	
									
			return( OSEEWKEX );			// OSEEWKEXを返却
			break;
		default:						// その他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 2, -1 , errno );	
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREMB << 16) | D_T_ERR_SYS );
			//return( -1 );				// ++++++++アボート予定++++++++
	}
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
