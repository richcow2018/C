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
/* ＜モジュール名＞					 メッセージの受信											*/
/* ＜モジュールＩＤ＞				 osrcvms													*/
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
/* ＜ソース修正者＞ 			 	 ＣＢ事ビジネス企画担当(メーカー：サプライ新保)				*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月０９日     故障管理番号（ＴＢＣＳ０１１８）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月１３日		故障管理番号（ＴＢＣＳ０１４３）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月１８日		故障管理番号（ＴＢＣＳ０１５４）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 メッセージの受信																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osrcvms.h>																	*/
/*																								*/
/*	   	long osrcvms( long mpid, long limit, long size, char *bufa ) 							*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	mpid;		メイルボックス又はプロセス識別子									*/
/*		long	limit;		制限時間(-1以上)													*/
/*		long	size;		メッセージ長制限値(1〜32768(SG))									*/
/*		char	*bufa;		メッセージ受信バッファ												*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		メッセージ長															*/
/*		異常終了		os_GetEmbcTableIndの返却値												*/
/*						OSEEISIZ			サイズに範囲外の値が設定されている					*/
/*						OSEEILIM			制限時間に範囲外の値が設定されている				*/
/*						OSEENACC																*/
/*						OSEEDELD																*/
/*						OSEETOUT																*/
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
#include <sys/types.h>								/* msgrev()用ヘッダファイル					*/
#include <sys/ipc.h>								/* msgrev()用ヘッダファイル					*/
#include <sys/msg.h>								/* msgrev()用ヘッダファイル					*/
#include <errno.h>									/* errno用ヘッダファイル					*/
#include <string.h>

/* 利用者作成ヘッダファイル */
#include "osrcvms.h"
#include "osrcvms_ins.h"
#include "os_MsgQDel_ins.h"

/*****************************************************************************/
/* 機能：メッセージの受信                                                    */
/* 作成日：2002年10月04日                                                    */
/* 変更日：　　年　月　日                                                    */
/* 作成者：                                                                  */
/* 呼出形式：                                                                */
/*   long osrcvms( long mpid, long limit, long size, char *bufa )            */
/*       long mpid        メイルボックス又はプロセス識別子                   */
/*       long limit       制限時間(-1以上)                                   */
/*       long size        メッセージ長制限値(1〜32768(SG))                   */
/*       char *bufa       メッセージ受信バッファ                             */
/*****************************************************************************/
long osrcvms( long mpid, long limit, long size, char *bufa )
{
	long	lRet = 0;								/* 関数結果返却								*/
	long	lMessageLength = 0;						/* 返却メッセージ長							*/
	long	lAsso = 0;								/* 種別										*/
	long	lMessageType = 0;						/* msgrcv()の第４引数用						*/
	int		iMessageFlag = 0;						/* msgrcv()の第５引数用						*/
	char			*pcWorkPtr = NULL;				/* ワークポインタ							*/
	TMsgHed			*ptMsgHed = NULL;				/* メッセージ本体のアドレス					*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* メイルボックステーブル個別部のアドレス	*/
	TMsgInfo		*tMsgInfo  = NULL;				/* メッセージ情報構造体のアドレス			*/
/*****  障害対応（TBCS0118）	Start									修正日：2003.06.09  *****/
	TEprcTableInd	*ptEprcTblInd;					/* プロセス管理テーブル個別部アドレス		*/
	long			lLimit;							/* プロセス管理テーブル個別部数				*/
	long			lTmpCode;						/* プロセス識別子							*/
	long			lTempId;						/* プロセスID								*/
	long			lCnt;
/*****  障害対応（TBCS0118）	End										修正日：2003.06.09  *****/

	os_trcget2( D_MD_OSRCVMS, D_T_TRA_IN, 4, mpid, limit, size, bufa  );

													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvms" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:mpid =%08lx \n", "osrcvms", mpid));
	DbgMsg01(DLv04, (OutPut, "***** %s:limit=%ld \n", "osrcvms", limit));
	DbgMsg01(DLv04, (OutPut, "***** %s:size =%ld \n", "osrcvms", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:bufa =%08lx \n\n", "osrcvms", (long)bufa));

	/************************************************/
	/*	メイルボックス管理テーブル					*/
	/*	個別部先頭アドレスの取得					*/
	/************************************************/
													/* mpidのチェック、及びメイルボックス管理	*/
													/* テーブル個別部先頭アドレス取得			*/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );
	if( lRet != NORMAL )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  lRet=%08lx \n", "osrcvms",
				"処理異常!!", "指定したメイルボックスが存在しない。又は削除された。", lRet));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, lRet );		
		return( lRet );								/* 返却値が異常の時はその返却値を			*/
													/* そのまま返却する							*/
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvms", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd=%08lx \n", "osrcvms", ptEmbcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvms", ptEmbc->lMaxMsgLng));

	/************************************************/
	/*	引数の確認									*/
	/************************************************/
													/* メッセージ制限長(引数size)の範囲チェック */
	if( size < D_MSGSIZE_MIN || size > ptEmbc->lMaxMsgLng )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  size=%ld \n", "osrcvms",
				"処理異常!!", "メッセージ長制限値が不当である。", size));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, OSEEISIZ );		
		return( OSEEISIZ );							/* サイズに範囲外の値が設定されている		*/
	}

	if( limit < D_TIMELIMIT_NOLIMIT )				/* 制限時間(引数limit)のチェック			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  limit=%ld \n", "osrcvms",
				"処理異常!!", "制限時間が不当である。", limit));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, OSEEILIM );		
		return( OSEEILIM );							/* 制限時間に範囲外の値が設定されている		*/
	}


	/********************************************************************************************/
	/*  本処理                                                                                  */
	/********************************************************************************************/
	/************************************/
	/* サブキューからのメッセージ受信	*/
	/************************************/
	lAsso = os_GetAsso( mpid );						/* 種別を取得								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvms", lAsso));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.lMsgCnt=%ld \n", "osrcvms",
			ptEmbcInd->tSubMsgQ.lMsgCnt));

	/************************************************/
	/*	受信メッセージの有無チェック				*/
	/************************************************/
													/* サブメッセージキューの					*/
													/* メッセージ格納数が0以外の場合			*/
	if( ptEmbcInd->tSubMsgQ.lMsgCnt != 0 )
	{									
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.ptNxtAdr=%08x \n", "osrcvms",
				ptEmbcInd->tSubMsgQ.ptNxtAdr));
	
/*****  障害対応（TBCS0118）	Start									修正日：2003.06.09  *****/
		/********************************************/
		/*  該当プロセスIDの取得					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* プロセス管理テーブル個別部				*/
													/* 先頭アドレスの取得						*/
	
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", "osrcvms",
				ptEprcTblInd));

		lLimit = ptEprc->lIndPartNum;				/* プロセス管理テーブル個別部数取得			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* プロセス管理テーブルの検索				*/
		{
													/* 個別部プロセス識別子の取得				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;

			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", "osrcvms",
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
			os_trcget2( D_MD_OSRCVMS, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS3 );
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
				os_trcget2( D_MD_OSRCVMS, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS4 );
			}
		}
/*****  障害対応（TBCS0118）	End										修正日：2003.06.09  *****/

		/************************************/
		/*  受信対象メッセージの検索		*/
		/************************************/
		while(1)
		{
			/****************************************/
			/*	先頭メッセージの抽出				*/
			/****************************************/
			if (NULL == tMsgInfo)					/* メッセージ情報ポインタがNULLの場合		*/
			{
													/* サブメッセージキューの次アドレスを設定	*/
				tMsgInfo = ptEmbcInd->tSubMsgQ.ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* 受信メッセージのアドレスを設定			*/

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo=%08x, ptMsgHed=%08x \n", "osrcvms",
						tMsgInfo, ptMsgHed));
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

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo=%08x, ptMsgHed=%08x \n", "osrcvms",
						tMsgInfo, ptMsgHed));
			}

			/****************************************/
			/*	対象メッセージ受信					*/
			/****************************************/
//			if( ( lAsso  == D_ASSO_PROCESS && ptMsgHed->lMsgType == D_MTYPE02 ) ||
//				( lAsso  == D_ASSO_MAILBOX && ptMsgHed->lMsgType == D_MTYPE03 ) )
													/* 種別が「１(プロセス識別子)」かつ			*/
													/* 受信したメッセージタイプが				*/
													/* メッセージの受信要求（プロセス宛）の場合	*/
													/* 又は										*/
													/* 第一パラメータが「0」かつ				*/
													/* 受信したメッセージタイプが				*/
													/* メッセージの受信要求（プロセス宛）の場合	*/
													/* 又は										*/
													/* 種別が「２(メイルボックス識別子)」かつ	*/
													/* 受信したメッセージタイプが				*/
													/* メッセージの受信要求（メイルボックス宛） */
													/* の場合									*/
			if( ( ( D_ASSO_PROCESS == lAsso ) && ( D_MTYPE06 == ptMsgHed->lMsgType ) ) ||
			    ( ( 0 == mpid ) && ( D_MTYPE06 == ptMsgHed->lMsgType ) ) ||
				( ( D_ASSO_MAILBOX == lAsso ) && ( D_MTYPE05 == ptMsgHed->lMsgType  ) ) )
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:lAsso =%ld \n", "osrcvms", lAsso));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed->lMsgType=%08lx \n", "osrcvms",
						ptMsgHed->lMsgType));
				DbgMsg01(DLv04, (OutPut, "***** %s:size =%ld, ptMsgHed->lDataSize \n", "osrcvms",
						size, ptMsgHed->lDataSize));

													/* サブメッセージキューに					*/
													/* 該当するメッセージが存在した場合			*/

													/* メッセージ長制限の判定					*/
//				if( size < tMsgInfo->lMsgSize )
				if( size < ptMsgHed->lDataSize )	/* メッセージ長制限有り						*/
				{
					lMessageLength = size;
				}
				else								/* メッセージ長制限無し						*/
				{
//					lMessageLength = tMsgInfo->lMsgSize;
					lMessageLength = ptMsgHed->lDataSize;
				}
													/* メッセージ受信バッファにコピー			*/
				memcpy(bufa, ptMsgHed + 1, lMessageLength);

				/********************************/
				/*  後始末						*/
				/********************************/
													/* サブメッセージキュー削除処理				*/
				lRet = os_MsgQDel(&ptEmbcInd->tSubMsgQ, tMsgInfo);
				if (-1 == lRet)
				{
													/* 障害発生									*/
					DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
							"osrcvms", "os_MsgQDel() Call Error!!  共有メモリ削除で失敗"));
					os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, OSEEWKEX );	
					return(OSEEWKEX);				/* 異常終了（sys work area exhaust）		*/
				}
													/* 関数出口									*/
				DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvms" ) );
				os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, lMessageLength );	
				return( lMessageLength );		/* bufaへコピーした領域長を返却する			*/
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
			os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 0 );	
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS );
                                                	/* アボート処理								*/
		}
	}
													/* msgrcvへ引き渡すメッセージタイプの設定	*/
//	if( lAsso == D_ASSO_PROCESS )
	if( ( lAsso == D_ASSO_PROCESS ) || ( 0 == mpid ) )
	{
//		lMessageType = D_MTYPE02;					/* プロセス宛プールバッファ無し				*/
		lMessageType = D_MTYPE06;					/* メッセージの受信要求（プロセス宛）		*/
	}
	else
	{
//		lMessageType = D_MTYPE03;					/* メイルボックス宛プールバッファ無し		*/
		lMessageType = D_MTYPE05;					/* メッセージの受信要求（メイルボックス宛） */
	}
	/* msgrcvへ引き渡すメッセージフラグの設定 */
	if( limit == D_TIMELIMIT_NOWAIT )				/* 制限時間が「０」の場合					*/
	{
/*****	故障管理番号TBCS0154の対応		Start							修正日：2003.06.18	*****/
/************************************************************************************************/
/*	「IPC_NOWAIT | MSG_NOERROR」で指定するように修正											*/
/************************************************************************************************/
//		iMessageFlag = IPC_NOWAIT;
		iMessageFlag = IPC_NOWAIT | MSG_NOERROR;
/*****	故障管理番号TBCS0154の対応		 End							修正日：2003.06.18	*****/
	}
	else											/* 制限時間が「０以外」の場合				*/
	{
		iMessageFlag = MSG_NOERROR;
	}

	/************************************/
	/*  メッセージの受信 				*/
	/************************************/
//	os_trcget2( D_MD_OSRCVMS, D_T_SYS_MALLOC, 1, size + 1 );
	os_trcget2( D_MD_OSRCVMS, D_T_SYS_MALLOC, 1, size + sizeof(TMsgHed) ); //2003.03.26
													/* メモリ取得サイズは						*/
//	pcWorkPtr = malloc(size);						/* メイルボックス管理部の最大メッセージ長	*/
										/* メイルボックス管理部の最大メッセージ長+ヘッダサイズ	*/
	pcWorkPtr = malloc(size + sizeof(TMsgHed));
	os_trcget2( D_MD_OSRCVMS, D_T_SYS_END, 1, pcWorkPtr );

	if (NULL == pcWorkPtr)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"osrcvmsp", "malloc() Call Error!!", errno, strerror(errno)));
		os_trcget2( D_MD_OSRCVMS,  D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);							/* 異常終了（sys work area exhaust）		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;				/* プロセス間メッセージポインタ設定			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:size              =%ld \n", "osrcvmsp", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08lx \n", "osrcvmsp", ptMsgHed));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08lx \n", "osrcvmsp", ptMsgHed));
	DbgMsg01(DLv04, (OutPut, "***** %s:pcWorkPtr         =%08lx \n", "osrcvmsp", pcWorkPtr));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMBoxId=%08lx \n", "osrcvms",
			ptEmbcInd->lMBoxId));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMsgQId=%ld \n", "osrcvms",
			ptEmbcInd->lMsgQId));

	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		/* システムタイマフラグの初期化				*/

	for( ; ; )
	{
//		lMessageLength = msgrcv( ptEmbcInd->lMsgQId, bufa, size, lMessageType, iMessageFlag );

		DbgDmp02( DLv04, ("### msgrcv前 ptMsgHed sise+sizeof(TMsgHed)",
							 ptMsgHed, size+4+sizeof(TMsgHed),1,0));

//		os_trcget2( D_MD_OSRCVMS, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
//									size+sizeof(TMsgHed), lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMS, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
								size+sizeof(TMsgHed)-sizeof(long), lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size, lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size+sizeof(TMsgHed),
//					lMessageType, iMessageFlag );
														// 20030329 変更
														// 受信サイズはメッセージタイプ
														// を除いたサイズを指定する
		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size+sizeof(TMsgHed) - sizeof(long),
					lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMS, D_T_SYS_END, 1, lRet );
		
		DbgDmp02( DLv04, ("### osrcvms msgrcv後 ", ptMsgHed, lRet,1,0));

		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msqid =%08lx\n","osrcvms",ptEmbcInd->lMsgQId));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() *msgp =%08lx\n","osrcvms",(long)ptMsgHed));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgsz =%ld  \n","osrcvms",size));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgtyp=%08lx\n","osrcvms",lMessageType));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgflg=%d   \n","osrcvms",iMessageFlag));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() Ret   =%08lx\n","osrcvms",lRet));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() ptMsgHed =%08lx\n","osrcvms",ptMsgHed));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() pcWorkPtr =%08lx\n","osrcvms",pcWorkPtr));
		
		/************************************************/
		/*	受信結果の編集								*/
		/************************************************/
//		if( lMessageLength != D_ERR_SYS )			/* システムコール返却値の確認				*/
		if( lRet != D_ERR_SYS )			/* システムコール返却値の確認				*/
		{
													/* 引数に制限時間が設定されている場合、		*/
													/* システムコールタイマを発行する			*/
			if( limit >= 1 )
			{
				lRet = os_tmcan( 0 );
				if( lRet != NORMAL )
				{
					os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 0 );	
			        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS1);
                                                	/* アボート処理								*/
				}
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:size=%d, ptMsgHed->lDataSize=%d \n",
					"osrcvms", size, ptMsgHed->lDataSize));

													/* メッセージ長制限の判定					*/
			if( size < ptMsgHed->lDataSize )		/* メッセージ長制限有り						*/
			{
				lMessageLength = size;
			}
			else									/* メッセージ長制限無し						*/
			{
				lMessageLength = ptMsgHed->lDataSize;
			}
													/* メッセージ受信バッファにコピー			*/
			DbgDmp02( DLv04, ("memcpy前 ", bufa, lMessageLength ,1,0));
			memcpy(bufa, ptMsgHed + 1, lMessageLength);

			DbgDmp02( DLv04, ("memcpy2後 ", bufa, lMessageLength ,1,0));

													/* 関数出口									*/
			DbgMsg01( DLv02, ( OutPut, "***** %s: free pcWorkPtr:%08lx\n", "osrcvms", pcWorkPtr ) );
			DbgMsg01( DLv02, ( OutPut, "***** %s: free ptMsgHed :%08lx\n", "osrcvms", ptMsgHed ) );
			os_trcget2( D_MD_OSRCVMS,  D_T_SYS_FREE, 1, pcWorkPtr );
			free(pcWorkPtr);						/* メモリ解放								*/
			os_trcget2( D_MD_OSRCVMS,  D_T_SYS_END, 0 );
			
			DbgMsg01( DLv02, ( OutPut, "***** %s: End  DbgSubFnc\n", "osrcvms" ) );
			os_trcget2( D_MD_OSRCVMS,  D_T_TRA_OUT, 1, lMessageLength );
			return( lMessageLength );				/* 返却値(メッセージ長)を返却する			*/
		}
		else
		{

/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグの判定処理を修正												*/
/************************************************************************************************/
//			if( errno == EINTR && ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF )

													/* errno が EINTR かつ						*/
													/* システムコールタイマフラグが				*/
													/* 未発行(0)、又は発行中(1)の場合			*/
			if( ( errno == EINTR ) &&
				( ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF ) ||
				  ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_ON  ) ) )
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/

			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvms",
						"EINTRエラー", errno));
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
						"osrcvms", "リトライ処理へ", ptEtmc->cSysTimeFlg));

				continue;							/* システムコールタイマフラグがOFFの場合	*/
													/* 再度メッセージ受信を行う					*/
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvms",
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

	os_trcget2( D_MD_OSRCVMS,  D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);								/* メモリ解放								*/
	os_trcget2( D_MD_OSRCVMS,  D_T_SYS_END, 0 );


	/********************************************************************************************/
	/*  異常処理                                                                                */
	/********************************************************************************************/
	switch( errno )
	{
		case E2BIG :
		case EINVAL :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "処理異常!!", "メッセージ長制限値が不当である。"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEEISIZ );

		case EACCES :
		case EFAULT :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "処理異常!!", "アクセス権がない。"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEENACC );

		case EIDRM :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "処理異常!!", "指定したメイルボックスが削除された。"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEEDELD );

		case ENOMSG :
		case EINTR :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "処理異常!!", "タイムアウトが発生した。"));
 			os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEETOUT );

		default :
			os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS2);
                                                	/* アボート処理								*/
	}
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
