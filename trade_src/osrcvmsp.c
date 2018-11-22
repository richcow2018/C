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
/* ＜モジュール名＞					 プールバッファ上のメッセージ受信							*/
/* ＜モジュールＩＤ＞				 osrcvmsp													*/
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
/* ＜ソース作成年月日＞ 			 ２００２年１０月０４日 									*/
/* ＜ソース修正者＞ 			 	 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０２月２７日 	障害対応（KL0020）				*/
/* ＜ソース修正者＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ新保)				*/
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０６月０９日     故障管理番号（ＴＢＣＳ０１１８）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月１３日		故障管理番号（ＴＢＣＳ０１４３）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 プールバッファ上のメッセージの受信 														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osrcvmsp.h>																*/
/*																								*/
/*	   	long	osrcvmsp( long mpid, long limit, char **bufaa ) 								*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	mpid;		メイルボックス又はプロセス識別子									*/
/*		long	limit;		制限時間(-1以上)													*/
/*		char	**bufaa;	プールバッファアドレス格納域     									*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		msgrcvシステムコールの返却値を返却										*/
/*		異常終了		os_GetEmbcTableIndの返却値		mpidが不正又はメイルボックス管理		*/
/*														テーブル個別部が無い					*/
/*						OSEEILIM						制限時間に範囲外の値が設定されている	*/
/*						OSEENPOL						使用プロセスIDが送信中（0xffffffff）以外*/
/*						OSEENACC						アクセス権がない(READ権)				*/
/*						OSEEIPOL						メッセージ情報構造体のアドレスが範囲外	*/
/*						OSEEDELD						指定したメイルボックスが削除された		*/
/*						OSEETOUT						制限時間内にメッセージが到着しなかった	*/
/*						OSEEISIZ																*/
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
#include <sys/types.h>				/* msgrev()用ヘッダファイル */
#include <sys/ipc.h>				/* msgrev()用ヘッダファイル */
#include <sys/msg.h>				/* msgrev()用ヘッダファイル */
#include <stdlib.h>					/* abort()用ヘッダファイル */
#include <errno.h>					/* errno用ヘッダファイル */
#include <string.h>

/* 利用者作成ヘッダファイル */
#include "osrcvmsp.h"
#include "osrcvmsp_ins.h"
#include "os_MsgQDel_ins.h"

/*****************************************************************************/
/* 機能：プールバッファ上のメッセージの受信                                  */
/* 作成日：2002年10月04日                                                    */
/* 変更日：　　年　月　日                                                    */
/* 作成者：                                                                  */
/* 呼出形式：                                                                */
/*   long osrcvmsp( long mpid, long limit, char **bufaa )                    */
/*       long mpid        メイルボックス又はプロセス識別子                   */
/*       long limit       制限時間(-1以上)                                   */
/*       char **bufaa     プールバッファアドレス格納域                       */
/*****************************************************************************/
long osrcvmsp( long mpid, long limit, char **bufaa )
{
	long	lRet;									/* 関数結果返却								*/
	long	lMessageLength;							/* 返却メッセージ長							*/
	long	lAsso;									/* 種別										*/
	long	lMessageType;							/* msgrcv()の第４引数用						*/
	int		iMessageFlag;							/* msgrcv()の第５引数用						*/
	long	lBufferPoolTopAddr;						/* バッファプール先頭アドレス				*/
	long	lBufferPoolBottomAddr;					/* バッファプール後尾アドレス				*/
	char			*pcWorkPtr = NULL;				/* ワークポインタ							*/
	TMsgHed			*ptMsgHed  = NULL;				/* メッセージポインタ						*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* メイルボックステーブル個別部のアドレス	*/
	TMsgInfo		*tMsgInfo  = NULL;				/* メッセージ情報構造体のアドレス			*/
	TEpbcTableInd	*ptEpbcInd = NULL;				/* ユニット管理情報構造体アドレス			*/
	TPbInfo			*ptPbInfo  = NULL;				/* プールバッファ管理情報ポインタ			*/
/*****  障害対応（TBCS0118）	Start									修正日：2003.06.09  *****/
	TEprcTableInd   *ptEprcTblInd;					/* プロセス管理テーブル個別部アドレス		*/
	long			lLimit;							/* プロセス管理テーブル個別部数				*/
	long			lTmpCode;						/* プロセス識別子							*/
	long			lTempId;						/* プロセスID								*/
	long			lCnt;
/*****  障害対応（TBCS0118）	End										修正日：2003.06.09  *****/

	os_trcget2( D_MD_OSRCVMSP, D_T_TRA_IN, 3, mpid, limit, *bufaa );


													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvmsp" ) );

//	DbgMsg01(DLv04, (OutPut, "***** %s:mpid =%08lx \n", "osrcvmsp", mpid));
//	DbgMsg01(DLv04, (OutPut, "***** %s:limit=%ld \n", "osrcvmsp", limit));
//	DbgMsg01(DLv04, (OutPut, "***** %s:bufaa =%08lx \n\n", "osrcvmsp", (long)bufaa));


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	/************************************************/
	/*	メイルボックス管理テーブル					*/
	/*	個別部先頭アドレスの取得					*/
	/************************************************/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );	/* 識別子(引数mpid)のチェック				*/
	if( lRet != NORMAL )
	{
		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_PRA, 1, lRet );
		
		return( lRet );								/* mpidが不正、又は							*/
													/* メイルボックス管理テーブル個別部が無い	*/
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvmsp", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd=%08lx \n", "osrcvmsp", ptEmbcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvmsp", ptEmbc->lMaxMsgLng));

	/************************************************/
	/*	引数の確認									*/
	/************************************************/
	if( limit < D_TIMELIMIT_NOLIMIT )				/* 制限時間(引数limit)のチェック			*/
	{
		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_PRA, 1, OSEEILIM );
		
		return( OSEEILIM );							/* 制限時間に範囲外の値が設定されている		*/
	}


	/********************************************************************************************/
	/*  本処理                                                                                  */
	/********************************************************************************************/
	/************************************/
	/* サブキューからのメッセージ受信	*/
	/************************************/
	lAsso = os_GetAsso( mpid );						/* 種別の取得								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvmsp", lAsso));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.lMsgCnt=%ld \n", "osrcvmsp",
			ptEmbcInd->tSubMsgQ.lMsgCnt));

	/************************************************/
	/*	受信メッセージの有無チェック				*/
	/************************************************/
													/* サブメッセージキューの					*/
													/* メッセージ格納数が0以外の場合			*/
	if( ptEmbcInd->tSubMsgQ.lMsgCnt != 0 )
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.ptNxtAdr=%08x \n", "osrcvmsp",
				ptEmbcInd->tSubMsgQ.ptNxtAdr));

/*****  障害対応（TBCS0118）	Start									修正日：2003.06.09  *****/
		/********************************************/
		/*  該当プロセスIDの取得					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* プロセス管理テーブル個別部				*/
													/* 先頭アドレスの取得						*/
		
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", "osrcvmsp",
				ptEprcTblInd));
		
		lLimit = ptEprc->lIndPartNum;				/* プロセス管理テーブル個別部数取得			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* プロセス管理テーブルの検索				*/
		{
													/* 個別部プロセス識別子の取得				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;
			
			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", "osrcvmsp",
				lTmpCode));
			
			if( lTmpCode == ptEmbcInd->lPCode )		/* プロセス識別子が一致						*/
			{
													/* プロセスIDの取得							*/
				lTempId = (ptEprcTblInd + lCnt)->lPid;
				break;
			}
		}
		if ( lCnt == lLimit )						/* 一致するプロセス識別子が存在しない		*/
		{
													/* アボート									*/
			os_trcget2( D_MD_OSRCVMSP, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS3 );
		}

		/********************************************/
		/*  サブメッセージキューのアタッチ			*/
		/********************************************/
		if( lTempId != lMyPid )						/* 該当プロセスIDが自プロセスID以外			*/
		{
			lRet = os_SubMsgAtc2(ptEmbcInd);		/* メモリのアタッチ							*/
			if( lRet != NORMAL )					/* 異常終了の場合							*/
			{
				/* アボート									*/
				os_trcget2( D_MD_OSRCVMSP, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS4 );
			}
		}
/*****  障害対応（TBCS0118）	End										修正日：2003.06.09  *****/

		/************************************/
		/*  受信対象メッセージの検索		*/
		/************************************/
		while(1)
		{
			/********************************************/
			/*	先頭メッセージの抽出					*/
			/********************************************/
			if (NULL == tMsgInfo)					/* メッセージ情報ポインタがNULLの場合		*/
			{
													/* サブメッセージキューの次アドレスを設定	*/
				tMsgInfo = ptEmbcInd->tSubMsgQ.ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* 受信メッセージのアドレスを設定			*/
			}
			else
			{
				if (NULL == tMsgInfo->ptNxtAdr)		/* メッセージ情報の次アドレスがNULLの場合	*/
				{
					break;							/* ループを抜ける							*/
				}
				
													/* 次メッセージ情報の次アドレスを設定		*/
				tMsgInfo = (TMsgInfo *)tMsgInfo->ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* 受信メッセージのアドレスを設定			*/

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo = %08x, ptMsg = %08x \n", "osrcvmsp",
						tMsgInfo, ptMsgHed));
			}

			/****************************************/
			/*	対象メッセージの受信				*/
			/****************************************/
//			if( ( ( lAsso  == D_ASSO_PROCESS ) && ( ptMsgHed->lMsgType == D_MTYPE04 ) ) ||
//				( ( lAsso  == D_ASSO_MAILBOX ) && ( ptMsgHed->lMsgType == D_MTYPE05 ) ) )
													/* 種別が「１(プロセス識別子)」かつ			*/
													/* 受信したメッセージタイプが				*/
													/* プールバッファ上のメッセージの			*/
													/* 受信要求（プロセス宛）の場合				*/
													/* 又は										*/
													/* 第一パラメータが「0」かつ				*/
													/* 受信したメッセージタイプが				*/
													/* プールバッファ上のメッセージの			*/
													/* 受信要求（プロセス宛）の場合				*/
													/* 又は										*/
													/* 種別が「２(メイルボックス識別子)」かつ	*/
													/* 受信したメッセージタイプが				*/
													/* プールバッファ上のメッセージの			*/
													/* 受信要求（メイルボックス宛）の場合		*/
			if( ( ( D_ASSO_PROCESS == lAsso ) && ( D_MTYPE08 == ptMsgHed->lMsgType ) ) ||
			    ( ( 0 == mpid ) && ( D_MTYPE08 == ptMsgHed->lMsgType ) ) ||
				( ( D_ASSO_MAILBOX == lAsso ) && ( D_MTYPE07 == ptMsgHed->lMsgType  ) ) )
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:lAsso =%ld \n", "osrcvms", lAsso));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed->lMsgType=%08lx \n", "osrcvms",
						ptMsgHed->lMsgType));

													/* サブメッセージキューに					*/
													/* 該当するメッセージが存在した場合			*/
				/****************************************/
				/* メッセージ情報構造体の				*/
				/* プールバッファアドレスの範囲チェック */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					 ( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
													/* ユニット管理構造体の先頭アドレスを設定	*/
//					ptEpbcInd = (TEpbcTableInd *)( lBufferPoolTopAddr - 4 );
													/* プールバッファ管理情報ポインタ設定		*/
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);

													/* ユニット管理情報ポインタ設定				*/
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

					DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd=%08x \n", "osrcvmsp",
							ptEpbcInd));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd->lUsePid=%08x \n", "osrcvmsp",
							ptEpbcInd->lUsePid));

													/* 使用プロセスIDが送信中（0xffffffff）以外 */
					if( D_EPBC_USEPID_SEND != ptEpbcInd->lUsePid )
					{
						os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEENPOL );
						
						return(OSEENPOL);			/* 異常終了（not pool buffer）				*/
					}

					ptEpbcInd->lUsePid = lMyPid;	/* 使用プロセスIDに自プロセスIDを設定		*/

					*bufaa = ptMsgHed->pcPlBuf;		/* 受信したプールバッファアドレスを設定		*/

													/* 返却メッセージ長に						*/
													/* 受信メッセージサイズを設定				*/
					lMessageLength = ptMsgHed->lDataSize;

					/********************************/
					/*  後始末						*/
					/********************************/
													/* サブメッセージキュー削除処理				*/
					lRet = os_MsgQDel(&ptEmbcInd->tSubMsgQ, tMsgInfo);
					if (-1 == lRet)
					{
													/* 障害発生									*/
						DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
								"osrcvmsp", "os_MsgQDel() Call Error!!  共有メモリ削除で失敗"));
								
						os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEWKEX );
								
						return(OSEEWKEX);			/* 異常終了（sys work area exhaust）		*/
					}

													/* 関数出口									*/
					DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsp" ) );
					
					os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, lMessageLength );
					
					return( lMessageLength );
				}
				else
				{
					os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEIPOL );
					
					return( OSEEIPOL );				/* メッセージ情報構造体のアドレスが範囲外	*/
				}
			}
		}
	}


	/************************************/
	/* メインメッセージキューからの受信 */
	/************************************/
													/* 引数に制限時間が設定されている場合、		*/
													/* システムコールタイマを発行する			*/
	if( limit >= 1 )
	{
		lRet = os_systim( limit, 1, 100 );
		if( lRet != NORMAL )
		{
			os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 0 );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS );
                    								/* アボート処理								*/
		}
	}
//	if( lAsso == D_ASSO_PROCESS )
	if( ( lAsso == D_ASSO_PROCESS ) || ( 0 == mpid ) )
	{
//		lMessageType = D_MTYPE04;					/* プロセス宛プールバッファ有り				*/
		lMessageType = D_MTYPE08;					/* プールバッファ上のメッセージの			*/
													/* 				受信要求（プロセス宛）		*/
	}
	else
	{
//		lMessageType = D_MTYPE05;					/* メイルボックス宛プールバッファ有り		*/
		lMessageType = D_MTYPE07;					/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
	}
	if( limit == 0 )
	{												/* msgrcvへ引き渡すメッセージフラグの設定	*/
		iMessageFlag = IPC_NOWAIT;
	}
	else
	{
		iMessageFlag = MSG_NOERROR;
	}

	/************************************/
	/*  メッセージ受信					*/
	/************************************/
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_MALLOC, 1, ptEmbc->lMaxMsgLng );	

													/* メモリ取得サイズは						*/
//	pcWorkPtr = malloc(ptEmbc->lMaxMsgLng);			/* メイルボックス管理部の最大メッセージ長	*/
													/* メイルボックス管理部の最大メッセージ長	*/
//	pcWorkPtr = malloc( (ptEmbc->lMaxMsgLng) + sizeof(TMsgHed) );	// 20030127 修正

	pcWorkPtr = calloc(1, sizeof(TMsgHed) );		// 20030305 修正
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 1, pcWorkPtr );	
	
	if (NULL == pcWorkPtr)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"osrcvmsp", "malloc() Call Error!!", errno, strerror(errno)));
			
		os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_SYS, 1, OSEEWKEX );
			
		return(OSEEWKEX);							/* 異常終了（sys work area exhaust）		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;				/* プロセス間メッセージポインタ設定			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%08x \n",
						"osrcvmsp",ptEmbc->lMaxMsgLng));

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08x \n","osrcvmsp", ptMsgHed));
	
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMBoxId=%08lx \n",
						"osrcvmsp", ptEmbcInd->lMBoxId));

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMsgQId=%ld \n",
						"osrcvmsp", ptEmbcInd->lMsgQId));

	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		/* システムタイマフラグの初期化				*/

	for( ; ; )
	{
//		DbgDmp02( DLv04, ("## osrcvmsp msgrcv前 ", ptMsgHed, sizeof(TMsgHed),1,0));

//		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
//		                             sizeof(TMsgHed), lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
					sizeof(TMsgHed) - sizeof(long), lMessageType, iMessageFlag );

		/***** 故障処理票KL0020の対応	Start							修正日：2003.02.27	*****/
//		lMessageLength = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, ptEmbc->lMaxMsgLng,
//								 lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, ptEmbc->lMaxMsgLng,
//								 lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, sizeof(TMsgHed),
//								 lMessageType, iMessageFlag );

														// 20030329 変更
														// 受信サイズはメッセージタイプ
														// を除いたサイズを指定する
		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, sizeof(TMsgHed) - sizeof(long),
								 lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_END, 2, lRet, errno );

//		DbgDmp02( DLv04, ("## osrcvmsp msgrcv後 ", ptMsgHed, sizeof(TMsgHed),1,0));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msqid =%08lx\n","osrcvmsp",ptEmbcInd->lMsgQId));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() *msgp =%08lx\n","osrcvmsp",(long)ptMsgHed));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgsz =%ld  \n","osrcvmsp",ptEmbc->lMaxMsgLng));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgtyp=%08lx\n","osrcvmsp",lMessageType));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgflg=%d   \n","osrcvmsp",iMessageFlag));

		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() Ret   =%08lx\n","osrcvmsp",lRet));

		/********************************************/
		/*	受信結果の編集							*/
		/********************************************/
//		if( lMessageLength != D_ERR_SYS )			/* システムコールの返却値が正常の場合		*/
		if( lRet != D_ERR_SYS )						/* システムコールの返却値が正常の場合		*/
		{
													/* 引数に制限時間が設定されている場合、		*/
													/* システムコールタイマのクリアを発行する	*/
			if( limit >= 1 )
			{
				lRet = os_tmcan( 0 );				/* タイマキャンセル							*/
				if( lRet != NORMAL )
				{
					os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 0 );
					
			        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS1);
                    								/* アボート処理								*/
				}
			}
													/* 取得したバッファアドレスの範囲チェック	*/
//			ptMsgHed = (TMsgHed *)*bufaa;
			lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
			lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

			if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
				 ( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
			{
													/* ユニット管理構造体のアドレスを設定する	*/
//				ptEpbcInd = (TEpbcTableInd *)( lBufferPoolTopAddr - 4 );
													/* プールバッファ管理情報ポインタ設定		*/
				ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);

													/* ユニット管理情報ポインタ設定				*/
				ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

				DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd=%08x \n", "osrcvmsp",
						ptEpbcInd));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd->lUsePid=%08x \n", "osrcvmsp",
						ptEpbcInd->lUsePid));

													/* 使用プロセスIDが送信中（0xffffffff）以外 */
				if( D_EPBC_USEPID_SEND != ptEpbcInd->lUsePid )
				{
					os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEENPOL );	
					
					return( OSEENPOL );				/* 異常終了（not pool buffer）				*/
				}

				ptEpbcInd->lUsePid = lMyPid;		/* 使用プロセスIDに自プロセスIDを設定		*/

				*bufaa = ptMsgHed->pcPlBuf;			/* 受信したプールバッファアドレスを設定		*/

													/* 返却メッセージ長に						*/
													/* 受信メッセージサイズを設定				*/
				lMessageLength = ptMsgHed->lDataSize;
				DbgMsg01(DLv04,(OutPut,"***** %s:lMessageLength=%ld\n","osrcvmsp",lMessageLength));
			}
			else
			{
				os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_FREE, 1, pcWorkPtr );
				
				free(pcWorkPtr);					/* メモリ解放								*/
				
				os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEIPOL );		
				
				return( OSEEIPOL );					/* メッセージ情報構造体のアドレスが範囲外	*/
			}
			break;
		}
		else
		{											/* システムコールの返却値が異常の場合		*/
/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグの判定処理を修正												*/
/************************************************************************************************/
//			if( errno == EINTR && ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF )

													/* errno が EINTR かつ						*/
													/* システムコールタイマフラグが「未発行」	*/
													/* 又は「発行中」の場合						*/
			if( ( errno == EINTR ) &&
				( ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF ) ||
				  ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_ON  ) ) )
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvmsp",
						"EINTRエラー", errno));
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
						"osrcvmsp", "リトライ処理へ", ptEtmc->cSysTimeFlg));

				continue;							/* 再度メッセージ受信を行う					*/
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvmsp",
						"EINTR以外のエラー", errno));
/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグのクリアを追加													*/
/************************************************************************************************/
													/* システムタイマフラグの初期化				*/
				ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/
				break;
			}
		}
	}
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_FREE, 1, pcWorkPtr );

	free(pcWorkPtr);								/* メモリ解放								*/

	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 0 );

	/********************************************************************************************/
	/*  終了処理                                                                                */
	/********************************************************************************************/
//	if( lMessageLength != -1 )
	if( lRet != -1 )
	{												/* システムコールの返却値が正常の場合		*/
													/* 関数出口									*/
//		DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsp" ) );
//		return( lMessageLength );					/* msgrcvシステムコールの返却値を返却		*/

//		os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, ptMsgHed->lDataSize );
//		return( ptMsgHed->lDataSize );				/* msgrcvシステムコールの返却値を返却		*/

		os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, lMessageLength );
		return( lMessageLength );					/* msgrcvシステムコールの返却値を返却		*/
	}
	/***** 故障処理票KL0020の対応	 	 End							修正日：2003.02.27	*****/


	/********************************************************************************************/
	/*  異常処理                                                                                */
	/********************************************************************************************/
	switch( errno )
	{
		case E2BIG :
		case EINVAL :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "処理異常!!", "メッセージ受信のサイズ指定の誤り。"));
		 	
		 	os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );		
		 			
			return( OSEEISIZ );

		case EACCES :
		case EFAULT :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "処理異常!!", "アクセス許可なし。"));
		 			
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );
		 			
			return( OSEENACC );						/* アクセス権がない(READ権)					*/

		case EIDRM :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "処理異常!!", "メッセージキューが削除されている。"));
		 			
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );
		 			
			return( OSEEDELD );						/* 指定したメイルボックスが削除された		*/

		case ENOMSG :
		case EINTR :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "処理異常!!", "タイムアウト。"));
		 	
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );		
		 			
			return( OSEETOUT );						/* 制限時間内にメッセージが到着しなかった	*/

		default :
			os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 1, errno );
		
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS2);
                    								/* アボート処理								*/
	}
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
