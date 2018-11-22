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
/* ＜サービス項目名＞				 メッセージ通信												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 メイルボックスの削除										*/
/* ＜モジュールＩＤ＞				 osdelmb													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ五味)				*/
/* ＜ソース作成年月日＞ 			 ２００２年１０月０４日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０６月１０日     故障管理番号（ＴＢＣＳ０１１８）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０６月１１日     故障管理番号（ＴＢＣＳ０１４４）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０７月２４日     故障管理番号（ＴＢＣＳ０２２１）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月０４日     故障管理番号（ＴＢＣＳ０２６１）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 メイルボックスの削除																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osdelmb.h>																	*/
/*																								*/
/*	   	long	osdelmb( long mbid, long udf )													*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	mbid;			メイルボックス識別子											*/
/*		long	udf;			無条件削除フラグ												*/
/*									0     : 無条件削除しない									*/
/*									0以外 : 無条件削除する										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了				NORMAL															*/
/*		異常終了				-1																*/
/*								OSEEEXST		到着メッセージがある。							*/
/*								OSEEIMBI		メイルボックス識別子が不当である。				*/
/*								OSEENEXS		指定したメイルボックスが存在しない。			*/
/*								OSEEWKEX		システム作業域が確保できない。					*/
/*								OSEENACC														*/
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <errno.h>
/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "osdelmb.h"
#include "osdelmb_ins.h"

/****************************************************************************/
/* 機能：メイルボックスの削除                                               */
/* 作成日：2002年10月4日                                                    */
/* 変更日：2002年10月4日                                                    */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long osdelmb( long mbid, long udf )                                    */
/*     long mbid              メイルボックス識別子                          */
/*     long udf               無条件削除フラグ                              */
/*                                0     : 無条件削除しない                  */
/*                                0以外 : 無条件削除する                    */
/*                                                                          */
/****************************************************************************/
long osdelmb( long mbid, long udf )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	long lAsso;							// 種別
	long lSerNum;						// 通番
	int iRet;							// 関数結果返却
	TEmbcTableInd *ptIndAdr;			// メイルボックス管理テーブル個別部のアドレス
	struct msqid_ds tMsqid_ds;			// メッセージキュー関連情報
	TMsgInfo *ptMsgInfo;				// メッセージ情報
	TMsgInfo *ptMsgInfoTmp;				// メッセージ情報（一時使用）
/*****  障害対応（TBCS0118）	Start									修正日：2003.06.10  *****/
	TEprcTableInd	*ptEprcTblInd;					/* プロセス管理テーブル個別部アドレス		*/
	long			lLimit;							/* プロセス管理テーブル個別部数				*/
	long			lTmpCode;						/* プロセス識別子							*/
	long			lTempId;						/* プロセスID								*/
	long			lCnt;
/*****  障害対応（TBCS0118）	End										修正日：2003.06.10  *****/
/*****  障害対応（TBCS0221）	Start									修正日：2003.07.24  *****/
	long			lWkMsgQId;
	long			lMessageType;					/* msgrcv()の第４引数用                     */
	int				iMessageFlag;					/* msgrcv()の第５引数用                     */
	long			lBufferPoolTopAddr;				/* バッファプール先頭アドレス               */
	long			lBufferPoolBottomAddr;			/* バッファプール後尾アドレス               */
	long			*palPlList[2];					/* プールバッファアドレスリスト				*/
	char			*pcWorkPtr = NULL;				/* ワークポインタ							*/
	TMsgHed			*ptMsgHed  = NULL;				/* メッセージポインタ						*/
	TEpbcTableInd   *ptEpbcInd = NULL;              /* ユニット管理情報構造体アドレス           */
	TPbInfo         *ptPbInfo  = NULL;              /* プールバッファ管理情報ポインタ           */
/*****  障害対応（TBCS0221）	End										修正日：2003.07.24  *****/

	os_trcget2( D_MD_OSDELMB, D_T_TRA_IN, 2, mbid, udf  );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	lAsso = os_GetAsso(mbid);			// 種別の取得
	lSerNum = os_GetSerNum(mbid);		// 通番の取得

	if( lAsso != D_ASSO_MB )			// 種別がメイルボックス識別子以外の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIMBI ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEIMBI );
		
		return( OSEEIMBI );				// OSEEIMBIを返却
	}

	if( (lSerNum < D_SERNUM_MIN) || (lSerNum > ptEmbc->lIndPartNum) )
	{									// 通番が個別部の範囲外である時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEENEXS );
		
		return( OSEENEXS );				// OSEENEXSを返却
	}

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	/************************************************/
	/*	メッセージキューの削除						*/
	/************************************************/
	ptIndAdr = (void *)ptEmbc + sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * (lSerNum - 1);
										// 指定の個別部を取得
	if( ptIndAdr->lMsgQId == D_MSGQID_NONE )
	{									// 未作成の時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEENEXS );
		
		return( OSEENEXS );				// OSEENEXSを返却
	}

	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
	iRet = msgctl( ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
										// メッセージキュー関連情報の取得
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
										
	if( iRet == D_ERR_SYS )				// 取得に失敗した時
	{
		goto err_osdelmb;				// 異常処理に遷移
	}

	if( udf == D_UDF_NO )				// 無条件削除をしない時
	{
		if( tMsqid_ds.msg_qnum != D_MSGQNUM_NONE )
										// メッセージキューにメッセージがある時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEEXST );
			
			return( OSEEEXST );			// OSEEEXSTを返却
		}

		if( ptIndAdr->tSubMsgQ.lMsgCnt != D_MSGQNUM_NONE )
		{								// サブメッセージキューにメッセージがある時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEEXST );
			
			return( OSEEEXST );			// OSEEEXSTを返却
		}
	}

/*****  障害対応（TBCS0221）	Start									修正日：2003.07.24  *****/
/************************************************************************************************/
/*  個別部のメッセージキューＩＤクリアの移動により追加                                          */
/************************************************************************************************/
	lWkMsgQId = ptIndAdr->lMsgQId;
	ptIndAdr->lMsgQId = D_MSGQID_NONE;
	
	/************************************/
	/*  メッセージ受信					*/
	/************************************/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_MALLOC, 1, sizeof(TMsgHed) );
	pcWorkPtr = calloc(1, sizeof(TMsgHed) );
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, pcWorkPtr );	
	if (NULL == pcWorkPtr)
	{
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);				/* 異常終了（sys work area exhaust）		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;	/* プロセス間メッセージポインタ設定			*/

	for( ; ; )
	{
		lMessageType = 0;
/*****  障害対応（TBCS0261）	Start									修正日：2003.08.04  *****/
/************************************************************************************************/
/*  「IPC_NOWAIT | MSG_NOERROR」で指定するように修正                                            */
/************************************************************************************************/
		iMessageFlag = IPC_NOWAIT | MSG_NOERROR;
/*****  障害対応（TBCS0261）	End										修正日：2003.08.04  *****/
		
        os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGRCV, 5, lWkMsgQId, ptMsgHed,
		                    sizeof(TMsgHed) - sizeof(long), lMessageType, iMessageFlag );
		iRet = msgrcv( lWkMsgQId, ptMsgHed, sizeof(TMsgHed) - sizeof(long),
						 lMessageType, iMessageFlag );
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 2, iRet, errno );
		/********************************************/
		/*	受信結果の編集							*/
		/********************************************/
		if( iRet != D_ERR_SYS )			/* システムコールの返却値が正常の場合		*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
			if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
				( ptMsgHed->lMsgType == D_MTYPE08 ) )
			{
				/****************************************/
				/* メッセージ情報構造体の               */
				/* プールバッファアドレスの範囲チェック */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
										/* プールバッファ管理情報ポインタ設定       */
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ユニット管理情報ポインタ設定             */
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* 使用プロセスIDに自プロセスIDを設定       */
					ptEpbcInd->lUsePid = lMyPid;
										/* 受信したプールバッファアドレスを設定		*/
					palPlList[0] = ptMsgHed->pcPlBuf;
										/* プールバッファの解放						*/
					iRet = osfrpbf(1L, &palPlList[0]);
				}
			}
		}
		else							/* システムコールの返却値が異常の場合		*/
		{
										/* errno が EINTR の場合					*/
			if( errno == EINTR )
			{
				continue;				/* 再度メッセージ受信を行う					*/
			}
			else if( errno == ENOMSG )
			{
				break;
			}
			else
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS7);
			}
		}
	}
	os_trcget2( D_MD_OSDELMB,  D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);					/* メモリ解放								*/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );

//	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
//	iRet = msgctl( ptIndAdr->lMsgQId, IPC_RMID, NULL );
	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, lWkMsgQId, IPC_RMID, NULL );
	iRet = msgctl( lWkMsgQId, IPC_RMID, NULL );
										// メッセージキューの削除
/*****  障害対応（TBCS0221）	End										修正日：2003.07.24  *****/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
										
	if( iRet == D_ERR_SYS )				// 削除に失敗した時
	{
		goto err_osdelmb;				// 異常処理に遷移
	}

	
	if( ptIndAdr->tSubMsgQ.ptBefAdr != D_MSGINFO_NONE )
	{									// メッセージ情報が存在する時
/*****  障害対応（TBCS0118）	Start									修正日：2003.06.10  *****/
		/********************************************/
		/*  該当プロセスIDの取得					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* プロセス管理テーブル個別部				*/
													/* 先頭アドレスの取得						*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", D_PROC_NAME,ptEprcTblInd));

		lLimit = ptEprc->lIndPartNum;				/* プロセス管理テーブル個別部数取得			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* プロセス管理テーブルの検索				*/
		{
													/* 個別部プロセス識別子の取得				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;

			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", D_PROC_NAME,lTmpCode));

			if( lTmpCode == ptIndAdr->lPCode )		/* プロセス識別子が一致						*/
			{
													/* プロセスIDの取得							*/
				lTempId = (ptEprcTblInd + lCnt)->lPid;
				break;
			}
		}
		if ( lCnt == lLimit )						/* 一致するプロセス識別子が存在しない		*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
													/* アボート									*/
			os_trcget2( D_MD_OSDELMB, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS5 );
		}
		
		/********************************************/
		/*  サブメッセージキューのアタッチ			*/
		/********************************************/
		if( lTempId != lMyPid )						/* 該当プロセスIDが自プロセスID以外			*/
		{
			iRet = os_SubMsgAtc2(ptIndAdr);			/* メモリのアタッチ							*/
			if( iRet != NORMAL )					/* 異常終了の場合							*/
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
													/* アボート									*/
				os_trcget2( D_MD_OSDELMB, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS6 );
			}
		}
/*****  障害対応（TBCS0118）	End										修正日：2003.06.10  *****/

		ptMsgInfo = ptIndAdr->tSubMsgQ.ptBefAdr;
										// 最終メッセージ情報の取得
/*****  障害対応（TBCS0144）	Start									修正日：2003.06.11  *****/
		while( ptMsgInfo != (TMsgInfo *)(ptIndAdr->tSubMsgQ.ptNxtAdr) )
//		while( ptMsgInfo != (TMsgInfo *)ptIndAdr )
		{								// すべてのメッセージ情報に対して処理
			ptMsgInfoTmp = (TMsgInfo *)ptMsgInfo->ptBefAdr;
										// 前メッセージ情報の退避

/*****  障害対応（TBCS0221）	Start									修正日：2003.07.24  *****/
										/* 受信メッセージのアドレスを設定			*/
			ptMsgHed = ptMsgInfo->pvMsgAdr;

			DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
			if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
				( ptMsgHed->lMsgType == D_MTYPE08 ) )
			{
				/****************************************/
				/* メッセージ情報構造体の               */
				/* プールバッファアドレスの範囲チェック */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
										/* プールバッファ管理情報ポインタ設定       */
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ユニット管理情報ポインタ設定             */
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* 使用プロセスIDに自プロセスIDを設定       */
					ptEpbcInd->lUsePid = lMyPid;
										/* 受信したプールバッファアドレスを設定		*/
					palPlList[0] = ptMsgHed->pcPlBuf;
										/* プールバッファの解放						*/
					iRet = osfrpbf(1L, &palPlList[0]);
				}
			}
/*****  障害対応（TBCS0221）	End										修正日：2003.07.24  *****/

			if( ptMsgInfoTmp->lShmId != D_SHMID_NONE )
//			if( ptMsgInfo->lShmId != D_SHMID_NONE )
			{							// 共有メモリIDが設定されている時
				/************************************/
				/*	共有メモリの削除				*/
				/************************************/
				os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptMsgInfo->ptNxtAdr );
				iRet = shmdt( ptMsgInfo );
//				os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptMsgInfo );
//				iRet = shmdt( ptMsgInfo->ptNxtAdr );
/*****  障害対応（TBCS0144）	End										修正日：2003.06.11  *****/
										// 共有メモリのデタッチ
				os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 2, iRet, errno );
										
				if( iRet == D_ERR_SYS )	// 削除に失敗した時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS );
					//return( -1 );		// ++++++++アボート予定++++++++
				}
				
/*****  障害対応（TBCS0144）	Start									修正日：2003.06.11  *****/
    			os_trcget2(D_MD_OSDELMB,D_T_SYS_SHMCTL,3,ptMsgInfoTmp->lShmId, IPC_RMID, NULL);
				iRet = shmctl( ptMsgInfoTmp->lShmId, IPC_RMID, NULL );
//    			os_trcget2(D_MD_OSDELMB,D_T_SYS_SHMCTL,3,ptMsgInfo->lShmId, IPC_RMID, NULL);
//				iRet = shmctl( ptMsgInfo->lShmId, IPC_RMID, NULL );
/*****  障害対応（TBCS0144）	End										修正日：2003.06.11  *****/
										// 共有メモリの削除
    			os_trcget2(D_MD_OSDELMB,D_T_SYS_END,2,iRet, errno);
										
				if( iRet == D_ERR_SYS )	// 削除に失敗した時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS1);
					//return( -1 );		// ++++++++アボート予定++++++++
				}
			}
			/****************************************/
			/*	メッセージ情報のクリア				*/
			/****************************************/
/*****  障害対応（TBCS0144）	Start									修正日：2003.06.11  *****/
//			ptMsgInfo->ptNxtAdr	= D_MSGINFO_NONE;
//			ptMsgInfo->ptBefAdr	= D_MSGINFO_NONE;
//			ptMsgInfo->lShmId	= D_SHMID_NONE;
//			ptMsgInfo->lMsgSize	= 0;
//			ptMsgInfo->pvMsgAdr	= NULL;
/*****  障害対応（TBCS0144）	End										修正日：2003.06.11  *****/
										// メッセージ情報のクリア
			ptMsgInfo = ptMsgInfoTmp;
										// 退避した前メッセージを設定
		}
		
/*****  障害対応（TBCS0221）	Start									修正日：2003.07.24  *****/
										/* 受信メッセージのアドレスを設定			*/
		ptMsgHed = ptMsgInfo->pvMsgAdr;

		DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
		if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
			( ptMsgHed->lMsgType == D_MTYPE08 ) )
		{
			/****************************************/
			/* メッセージ情報構造体の               */
			/* プールバッファアドレスの範囲チェック */
			/****************************************/
			lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
			lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

			if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
				( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
			{
										/* プールバッファ管理情報ポインタ設定       */
				ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ユニット管理情報ポインタ設定             */
				ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* 使用プロセスIDに自プロセスIDを設定       */
				ptEpbcInd->lUsePid = lMyPid;
										/* 受信したプールバッファアドレスを設定		*/
				palPlList[0] = ptMsgHed->pcPlBuf;
										/* プールバッファの解放						*/
				iRet = osfrpbf(1L, &palPlList[0]);
			}
		}
/*****  障害対応（TBCS0221）	End										修正日：2003.07.24  *****/

		/********************************************/
		/*	共有メモリの削除						*/
		/********************************************/
		os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptIndAdr->tSubMsgQ.ptNxtAdr );
		
		iRet = shmdt( ptIndAdr->tSubMsgQ.ptNxtAdr );
									
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );			
							
										// 共有メモリのデタッチ
		if( iRet == D_ERR_SYS )			// 削除に失敗した時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );	
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS2);
			//return( -1 );				// ++++++++アボート予定++++++++
		}
		
		os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMCTL, 3, ptIndAdr->tSubMsgQ.lShmId, IPC_RMID, NULL );
		
		iRet = shmctl( ptIndAdr->tSubMsgQ.lShmId, IPC_RMID, NULL );
		
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
		
										// 共有メモリの削除
		if( iRet == D_ERR_SYS )			// 削除に失敗した時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );	
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS3);
			//return( -1 );				// ++++++++アボート予定++++++++
		}
		ptIndAdr->tSubMsgQ.ptNxtAdr	= D_MSGINFO_NONE;
		ptIndAdr->tSubMsgQ.ptBefAdr	= D_MSGINFO_NONE;
		ptIndAdr->tSubMsgQ.lMsgCnt	= 0;
		ptIndAdr->tSubMsgQ.lShmId	= D_SHMID_NONE;
										// サブメッセージキューのクリア
	}

/*****  障害対応（TBCS0221）	Start									修正日：2003.07.24  *****/
/************************************************************************************************/
/*  個別部のメッセージキューＩＤクリアの移動により削除                                          */
/************************************************************************************************/
/*****  障害対応（TBCS0221）	End										修正日：2003.07.24  *****/

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSDELMB, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMALを返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_osdelmb:
	switch( errno )
	{
		case EACCES:					// EACCESの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENACC ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEENACC );			// OSEENACCを返却
			break;
		case EFAULT:					// EFAULTの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEEEXST );			// OSEEEXSTを返却
			break;
		case EIDRM:						// EIDRMの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEENEXS );			// OSEENEXSを返却
			break;
		case EINVAL:					// EINVALの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEWKEX ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEEWKEX );			// OSEEWKEXを返却
			break;
		default:						// その他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS4);
			//return( -1 );				// ++++++++アボート予定++++++++
	}
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
