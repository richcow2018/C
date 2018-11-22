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
/* ＜サービス項目名＞				 リザルト・例外												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 不特定リザルトの受信										*/
/* ＜モジュールＩＤ＞				 osanyrl													*/
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
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 不特定に非完了型処理要求の結果を取得する。													*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osanyrl.h>																	*/
/*																								*/
/*	   	long	osanyrl(long *rda,long limit)													*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	*rda;																			*/
/*		long	limit																			*/
/*																								*/
/* ＜返却値＞																					*/
/*      リザルト    ：非完了型処理要求の結果                                                    */
/*      OSEEACCV    ：アドレス異常が発生した                                                    */
/*      OSEEILIM    ：制限時間の値が不当である                                                  */
/*      OSEEWKEX    ：システム作業域が確保できない                                              */
/*      OSEEISIZ    ：メッセージ受信のときに指定しているサイズが不当である                      */
/*      OSEENACC    ：アクセス許可がなかった                                                    */
/*      OSEEDELD    ：メッセージキューが削除されている                                          */
/*      OSEETOUT    ：制限時間内に一つの結果も上がってこなかった                                */
/*      OSEEIPOL    ：バッファプールの領域を超過した                                            */
/*      OSEENPOL    ：使用中のプールバッファなし                                                */
/*      OSEEIPLB    ：バッファプールアドレスの異常                                              */
/*      OSEEIVRD    ：要求種別の値が不当である                                                  */
/*      OSEENREQ    ：リクエストが一つも出されていない                                          */
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


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	"osanyrl.h"
#include	"osanyrl_ins.h"
#include	"os_MainMsgQ_ins.h"
#include	"os_SubMsgQ_ins.h"


long	osanyrl(rda, limit)
long	*rda;										/* リクエスト識別子格納域					*/
long	limit;										/* 制限時間									*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lMsgFlg;						/* サブメッセージ判定フラグ					*/
													/* 値=1：メインメッセージキューの処理		*/
													/* 値=2：サブメッセージキューの処理			*/
	long			lMsgType;						/* メッセージタイプ							*/
	long			lCnt;							/* ループカウンタ							*/
	long			lRet;							/* 返却値									*/
	TErdcTableInd	*ptErdcp = NULL;				/* ｒｄ管理テーブル個別部ポインタ			*/
	TEmbcTableInd	*ptMyEmbcp = NULL;				/* 自プロセスメイルボックス管理情報ポインタ */
	TMsgInfo		*ptMsgNxt = NULL;				/* 次メッセージ情報ポインタ					*/
	TMsgHed			*ptMsg = NULL;					/* メッセージ本体ポインタ					*/


	os_trcget2( D_MD_OSANYRL, D_T_TRA_IN, 2, rda, limit );

													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osanyrl" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lMsgFlg  = 0;
	lMsgType = 0;
	lCnt     = 0;
	lRet     = 0;


	/************************************/
	/*  引数チェック					*/
	/************************************/
	if (0 == rda)									/* 「0」の場合								*/
	{
		os_trcget2( D_MD_OSANYRL, D_T_ERR_PRA , 1, OSEEACCV );
		
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  rda=%08lx \n", "osanyrl",
				"処理異常!!", "アドレス異常。", (long)rda));
		return(OSEEACCV);							/* 異常終了（アドレス異常）					*/
	}

	if (0 > limit)									/* 「0」以下の場合							*/
	{
		if (-1 > limit)								/* 「-1」以下の場合エラー					*/
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  limit=%ld \n", "osanyrl",
					"処理異常!!", "引数の指定に誤りがあります。", limit));
			
			os_trcget2( D_MD_OSANYRL, D_T_ERR_PRA , 1, OSEEILIM );		
					
			return(OSEEILIM);						/* 異常終了（invalid limit）				*/
		}
	}

	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ｒｄ管理個別部の先頭アドレス設定			*/

													/* 自プロセスメイルボックス情報ポインタ設定 */
	ptMyEmbcp = (TEmbcTableInd *)ptEsys->tMyPrcInfo.ptMyEMBC;


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/************************************/
	/*  ｒｄ管理テーブル管理部の		*/
	/*  メッセージ要求フラグのチェック	*/
	/************************************/
													/* メイルボックス宛プールバッファ無し = OFF	*/
													/* メイルボックス宛プールバッファ有り = OFF */
													/* プロセス宛プールバッファ無し = OFF		*/
													/* プロセス宛プールバッファ有り = OFF		*/
	if ((D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cMbPbOff)  &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cMbPbOn)   &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cPrcPbOff) &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cPrcPbOn))
	{
		// メインメッセージキューの処理へ
		lMsgFlg = 1;
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:&ptMyEmbcp->tSubMsgQ=%08x\n", "osanyrl",
			&ptMyEmbcp->tSubMsgQ));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%08x\n", "osanyrl",
			ptMyEmbcp->tSubMsgQ.ptNxtAdr));

    //  メイルボックス管理テーブル管理部情報のダンプ
//	tol_dump("ptEmbc（管理部情報）", ptEmbc, sizeof(TEmbcTable), 1, 0);
	DbgDmp02( DLv04, ("ptEmbc（管理部情報）", ptEmbc, sizeof(TEmbcTable),1,0));

    //  メイルボックス管理テーブル個別部情報のダンプ
//	tol_dump("ptMyEmbcp（個別部情報）", ptMyEmbcp, sizeof(TEmbcTableInd), 1, 0);
	DbgDmp02( DLv04, ("ptMyEmbcp（個別部情報）", ptMyEmbcp, sizeof(TEmbcTableInd),1,0));


	/************************************/
	/*  受信要求のメッセージ検索		*/
	/************************************/
	while(1)
	{
													/* 受信メッセージのアドレスチェック			*/
		if (NULL == ptMyEmbcp->tSubMsgQ.ptNxtAdr)	/* サブメッセージキューの次アドレスがNULL	*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%08x\n", "osanyrl",
					ptMyEmbcp->tSubMsgQ.ptNxtAdr));

			lMsgFlg = 1;							/* メッセージフラグに「１」を設定			*/
			break;									/* ループを抜ける							*/
		}

		if (NULL == ptMsgNxt)						/* 次メッセージ情報ポインタがNULLの場合		*/
		{
			ptMsgNxt = ptMyEmbcp->tSubMsgQ.ptNxtAdr;/* サブメッセージキューの次アドレスを設定	*/
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* 受信メッセージのアドレスを設定			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osanyrl",
					ptMsgNxt, ptMsg));
		}
		else
		{
			if (NULL == ptMsgNxt->ptNxtAdr)			/* 次メッセージ情報の次アドレスがNULLの場合 */
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt->ptNxtAdr = %08x \n", "osanyrl",
						ptMsgNxt->ptNxtAdr));

				lMsgFlg = 1;						/* メッセージフラグに「１」を設定			*/
				break;								/* ループを抜ける							*/
			}
													/* 次メッセージ情報の次アドレスを設定		*/
			ptMsgNxt = (TMsgInfo *)ptMsgNxt->ptNxtAdr;
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* 受信メッセージのアドレスを設定			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osanyrl",
					ptMsgNxt, ptMsg));
		}

		/************************************/
		/*  メッセージ内容チェック			*/
		/************************************/
													/* メッセージタイプとrd管理テーブル管理部の */
													/* メッセージ要求フラグの内容が一致する場合 */

													/* メッセージの受信要求（メイルボックス宛）	*/
		if ((D_MTYPE05 == ptMsg->lMsgType) &&
			(D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"メッセージの受信要求（メイルボックス宛）", ptMyEmbcp));

			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}
													/* メッセージの受信要求（プロセス宛）		*/
		else if ((D_MTYPE06 == ptMsg->lMsgType) &&
				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"メッセージの受信要求（プロセス宛）", ptMyEmbcp));

			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}

		/***** 仕様変更（SSLA0001）	Start								修正日：2002.12.12	*****/
		/****************************************************************************************/
		/*  osrcvmsrでの非プールバッファメッセージ受信の対応									*/
		/****************************************************************************************/
													/* プールバッファ上のメッセージの			*/
													/* 受信要求(メイルボックス宛)				*/
//		else if ((D_MTYPE07 == ptMsg->lMsgType) &&
//				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
		else if ((D_MTYPE07 == ptMsg->lMsgType) &&
				 ((D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn) ||
				  (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"プールバッファ上のメッセージの受信要求(メイルボックス宛)", ptMyEmbcp));

			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}
													/* プールバッファ上のメッセージの			*/
													/* 受信要求(プロセス宛)						*/
//		else if ((D_MTYPE08 == ptMsg->lMsgType) &&
//				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn))
		else if ((D_MTYPE08 == ptMsg->lMsgType) &&
				 ((D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn) ||
				  (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"プールバッファ上のメッセージの受信要求(プロセス宛)", ptMyEmbcp));

			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}
		/***** 仕様変更（SSLA0001）	 End								修正日：2002.12.12	*****/

													/* DCSメッセージの受信要求					*/
		else if ((D_MTYPE25 == ptMsg->lMsgType) &&
			 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"DCSメッセージの受信要求", ptMyEmbcp));

			ptMsg->lMsgType = D_MTYPE25;			/* 受信メッセージのメッセージタイプに		*/
													/* メイルボックス宛プールバッファ有りを設定 */
			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}
	}


	/************************************/
	/*  メッセージフラグの判定			*/
	/************************************/
	if (1 == lMsgFlg)								/* メインメッセージキューの処理				*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "osanyrl", "メインメッセージキューの処理へ"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n", "osanyrl", ptErdcp));

		/************************************/
		/*  メインメッセージキュー処理		*/
		/************************************/
		lRet = os_MainMsgQ(limit, lMsgType, ptErdcp, rda, 1);

		switch (lRet)								/* 返却値判定								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "処理異常!!", "システム作業域の処理で失敗。"));
			 		
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEWKEX );	
			 		
				return(OSEEWKEX);					/* 異常終了（sys work area exhaust）		*/
				break;

			case	-2:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "メッセージ受信のサイズ指定の誤り。"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEISIZ );	
			 			
				return(OSEEISIZ);					/* 異常終了（invalid size）					*/
				break;

			case	-3:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "アクセス許可なし。"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENACC );	
			 			
				return(OSEENACC);					/* 異常終了（no access right）				*/
				break;

			case	-4:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "メッセージキューが削除されている。"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEDELD );	
			 			
				return(OSEEDELD);					/* 異常終了（deleted）						*/
				break;

			case	-5:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "タイムアウト。"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEETOUT );	 
				 		
				return(OSEETOUT);					/* 異常終了（time out）						*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "バッファプールの領域を超過した。"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPOL );	
				 		
				return(OSEEIPOL);					/* 異常終了（invalid buffer pool）			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "使用中のプールバッファなし。"));
			 	
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENPOL );			
			 			
				return(OSEENPOL);					/* 異常終了（not pool buffer）				*/
				break;

			case	-8:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"処理異常!!", "バッファプールアドレス異常。"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPLB );	
						
				return(OSEEIPLB);					/* 異常終了（invalid pool buffer）			*/
				break;

			case	-9:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));
				
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIVRD );			
						
				return(OSEEIVRD);					/* 異常終了（invalid req descriptor）		*/
				break;

			case	-10:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"処理異常!!", "要求されたデータがありません。"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENREQ );	
						
				return(OSEENREQ);					/* 異常終了（no request）					*/
				break;

			default		:
				// 何もしない
				break;
		}
	}
	else if (2 == lMsgFlg)							/* サブメッセージキューの処理				*/
	{
		/************************************/
		/*  ｒｄ管理テーブル個別部検索		*/
		/************************************/
													/* ループ処理								*/
		//for(lCnt = 0; lCnt < ptErdc->lMaxIndNum; lCnt++)
		for(lCnt = 0; lCnt < ptMyEPRC->lMaxReqNum; lCnt++)
		{
													/* メッセージタイプと要求種別が一致した場合 */
			if (ptErdcp->cReqClass == ptMsg->lMsgType)
			{
				*rda = ptErdcp->lRCode;				/* 当該個別部のリクエスト識別子を設定  		*/
				break;								/* ループを抜ける							*/
			}
			/***** 仕様変更（SSLA0001）	Start							修正日：2002.12.12	*****/
			/************************************************************************************/
			/*  osrcvmsrでの非プールバッファメッセージ受信の対応								*/
			/************************************************************************************/
			else									/* 一致しなかった場合						*/
			{
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（メイルボックス宛） */
													/* の場合									*/
				if ((D_MTYPE07 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
				{
					break;							/* ｒｄ管理テーブル個別部の検索を終了する	*/
				}
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(プロセス宛)		*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（プロセス宛）の場合 */
				if ((D_MTYPE08 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
				{
					break;							/* ｒｄ管理テーブル個別部の検索を終了する	*/
				}
													/* ＤＣＳメッセージの受信要求				*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（メイルボックス宛） */
													/* の場合									*/
				if ((D_MTYPE25 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS07 ==ptErdcp->cReqClass))
				{
					break;							/* ｒｄ管理テーブル個別部の検索を終了する	*/
				}
			}
			/***** 仕様変更（SSLA0001）	 End							修正日：2002.12.12	*****/

			ptErdcp++;								/* 次アドレスへポインタを進める				*/
		}

		//if (lCnt >= ptErdc->lMaxIndNum)			/* ｒｄ管理テーブル個別部の最大値を超過		*/
		if (lCnt >= ptMyEPRC->lMaxReqNum)
		{											/* ｒｄ管理テーブルの個別部が存在しない場合 */
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osgtnrl",
					"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));
					
			os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIVRD );	
					
			return(OSEEIVRD);						/* 異常終了（invalid req descriptor）		*/
		}

		*rda = ptErdcp->lRCode;						/* 当該個別部のリクエスト識別子を設定  		*/


		/************************************/
		/*  サブメッセージキュー処理		*/
		/************************************/
		lRet = os_SubMsgQ(ptMsg->lMsgType, ptMsg, ptErdcp, ptMyEmbcp, ptMsgNxt);

		switch (lRet)								/* 返却値判定								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "処理異常!!", "システム作業域の処理で失敗。"));
			 		
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEWKEX );	
			 		
				return(OSEEWKEX);					/* 異常終了（sys work area exhaust）		*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "バッファプールの領域を超過した。"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPOL );	
				 		
				return(OSEEIPOL);					/* 異常終了（invalid buffer pool）			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "使用中のプールバッファなし。"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENPOL );	
			 			
				return(OSEENPOL);					/* 異常終了（not pool buffer）				*/
				break;

			case	-8:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"処理異常!!", "バッファプールアドレス異常。"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPLB );	
						
				return(OSEEIPLB);					/* 異常終了（invalid pool buffer）			*/
				break;

			default		:
				// 何もしない
				break;
		}
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osanyrl" ) );
	
	os_trcget2( D_MD_OSANYRL, D_T_TRA_OUT, 1, lRet );
	
	return (lRet);									/* 正常終了									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
