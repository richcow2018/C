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
/* ＜サービス項目名＞				 リザルト管理												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 特定リザルト受信											*/
/* ＜モジュールＩＤ＞				 osgtnrl													*/
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
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*      特定リザルトの受信                                                                      */
/*      指定した、非完了型処理要求に対する完了通知を待って、その結果を取得する。                */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osgtnrl.h>																	*/
/*																								*/
/*        long	osgtnrl(rd, limit)                                                              */
/*																								*/
/* ＜仮引数＞																					*/
/*      long    rd                                                                              */
/*      long    limit                                                                           */
/*																								*/
/* ＜返却値＞																					*/
/*      リザルト    ：非完了型処理要求の結果                                                    */
/*      OSEEILIM    ：制限時間の値が不当である                                                  */
/*      OSEEIVRD    ：リクエスト識別子の値が不当である                                          */
/*      OSEENREQ    ：当該処理要求が出されていない                                              */
/*      OSEEWKEX    ：システム作業域が確保できない                                              */
/*      OSEEISIZ    ：メッセージ受信のときに指定しているサイズが不当である                      */
/*      OSEENACC    ：アドレス異常が発生した                                                    */
/*      OSEEDELD    ：メッセージキューが削除されている                                          */
/*      OSEETOUT    ：制限時間内に一つの結果も上がってこなかった                                */
/*      OSEEIPOL    ：バッファプールの領域を超過した                                            */
/*      OSEENPOL    ：使用中のプールバッファなし                                                */
/*      OSEEIPLB    ：バッファプールアドレスの異常                                              */
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
/************************************************************************************************/
/*  インクルードファイル                                                                        */
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	"osgtnrl.h"
#include	"osgtnrl_ins.h"
#include	"os_MainMsgQ_ins.h"
#include	"os_SubMsgQ_ins.h"


long	osgtnrl(rd, limit)
long	rd;											/* リクエスト識別子							*/
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


	os_trcget2( D_MD_OSGTNRL, D_T_TRA_IN, 2, rd, limit );

													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osgtnrl" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lMsgFlg = 0;
	lMsgType = 0;
	lCnt = 0;
	lRet = 0;
	errno = 0;

	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ｒｄ管理個別部の先頭アドレス設定			*/

													/* 自プロセスメイルボックス情報ポインタ設定 */
	ptMyEmbcp = (TEmbcTableInd *)ptEsys->tMyPrcInfo.ptMyEMBC;


	/************************************/
	/*  引数チェック					*/
	/************************************/
	if (0 > limit)									/* 「0」を下回る場合						*/
	{
		if (-1 > limit)								/* 「-1」を下回る場合（エラー）				*/
		{
			os_trcget2( D_MD_OSGTNRL, D_T_ERR_PRA, 1, OSEEILIM );
			
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  limit=%#d \n", "osgtnrl",
					"処理異常!!", "引数の指定に誤りがあります。", limit));
			return(OSEEILIM);						/* 異常終了（invalid limit）				*/
		}
	}

	/************************************/
	/*  rd管理テーブル個別部の検索		*/
	/************************************/
													/* ループ処理								*/
	for(lCnt = 0; lCnt < ptMyEPRC->lMaxReqNum; lCnt++)
	{
		DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop1 Count=%d 回目  ", "osgtnrl", lCnt));
		DbgMsg01(DLv04, (OutPut, "ptErdcp=%08x, ptErdcp->lRCode=%08x, rd=%08x \n",
				ptErdcp, ptErdcp->lRCode, rd));

		if (rd == ptErdcp->lRCode)					/* リクエスト識別子が一致した場合			*/
		{
			break;									/* ループを抜ける							*/
		}

		ptErdcp++;									/* 次アドレスへポインタを進める				*/
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lCnt  =%d, ptMyEPRC->lMaxReqNum=%d \n", "osgtnrl",
					lCnt, ptMyEPRC->lMaxReqNum));

													/* ｒｄ管理テーブル個別部の最大値を超過		*/
	if (lCnt >= ptMyEPRC->lMaxReqNum)					/* ｒｄ管理テーブルの個別部が存在しない場合 */
	{
		os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEIVRD );
		
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osgtnrl",
				"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));
		return(OSEEIVRD);							/* 異常終了（invalid req descriptor）		*/
	}
	else
	{
													/* 当該ｒｄ管理テーブル個別部の				*/
													/* リクエスト状態が「要求済(0x01)」以外の場合*/
		if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
		{
			os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEENREQ );
			
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  リクエスト状態=%02x \n", "osgtnrl",
					"処理異常!!", "要求されたデータがありません。", ptErdcp->tReqStat.cUCompStat));
			return(OSEENREQ);						/* 異常終了（no request）					*/
		}
	}

	/************************************/
	/*  メッセージタイプの決定			*/
	/************************************/
	lMsgType = ptErdcp->cReqClass;					/* 当該rd管理テーブル個別部の要求種別を設定 */

	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType=%#x \n", "osgtnrl", lMsgType));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/************************************/
	/*  メッセージタイプのチェック		*/
	/************************************/
													/* メッセージの受信要求（メイルボックス宛） */
													/* 以外かつ									*/
													/* メッセージの受信要求（プロセス宛）		*/
													/* 以外かつ									*/
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
													/* 以外かつ									*/
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求（プロセス宛）		*/
													/* 以外の場合								*/
	if ((D_MTYPE05 != lMsgType) &&
		(D_MTYPE06 != lMsgType) &&
		(D_MTYPE07 != lMsgType) &&
		(D_MTYPE08 != lMsgType))
	{
		// メインメッセージキューの処理へ
		lMsgFlg = 1;
	}


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


	DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%x \n", "osgtnrl",
			ptMyEmbcp->tSubMsgQ.ptNxtAdr));


	/************************************/
	/*  受信要求のメッセージ検索		*/
	/************************************/
	while(1)
	{
													/* 受信メッセージのアドレスチェック			*/
		if (NULL == ptMyEmbcp->tSubMsgQ.ptNxtAdr)	/* サブメッセージキューの次アドレスがNULL	*/
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%08x\n", "osgtnrl",
					ptMyEmbcp->tSubMsgQ.ptNxtAdr));

			lMsgFlg = 1;							/* メッセージフラグに「１」を設定			*/
			break;									/* ループを抜ける							*/
		}

		if (NULL == ptMsgNxt)						/* 次メッセージ情報ポインタがNULLの場合		*/
		{
			ptMsgNxt = ptMyEmbcp->tSubMsgQ.ptNxtAdr;/* サブメッセージキューの次アドレスを設定	*/
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* 受信メッセージのアドレスを設定			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osgtnrl",
					ptMsgNxt, ptMsg));
		}
		else
		{
			if (NULL == ptMsgNxt->ptNxtAdr)			/* 次メッセージ情報の次アドレスがNULLの場合 */
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt->ptNxtAdr = %08x \n", "osgtnrl",
						ptMsgNxt->ptNxtAdr));

				lMsgFlg = 1;						/* メッセージフラグに「１」を設定			*/
				break;								/* ループを抜ける							*/
			}
													/* 次メッセージ情報の次アドレスを設定		*/
			ptMsgNxt = (TMsgInfo *)ptMsgNxt->ptNxtAdr;
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* 受信メッセージのアドレスを設定			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osgtnrl",
					ptMsgNxt, ptMsg));
		}

		/************************************/
		/*  メッセージ内容チェック			*/
		/************************************/
													/* メッセージタイプを比較					*/
		if (lMsgType == ptMsg->lMsgType)			/* メッセージタイプが一致した場合			*/
		{
			// サブメッセージキューの処理へ
			lMsgFlg = 2;							/* メッセージフラグに「２」を設定			*/
			break;									/* ループを抜ける							*/
		}
	}


	/************************************/
	/*  メッセージフラグの判定			*/
	/************************************/
	if (1 == lMsgFlg)								/* メインメッセージキューの処理				*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "osgtnrl", "メインメッセージキューの処理へ"));

		/************************************/
		/*  メインメッセージキュー処理		*/
		/************************************/
		lRet = os_MainMsgQ(limit, lMsgType, ptErdcp, 0, 0);

		switch (lRet)								/* 返却値判定								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "処理異常!!", "システム作業域の処理で失敗。"));

				os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEWKEX );

				return(OSEEWKEX);					/* 異常終了（sys work area exhaust）		*/
				break;

			case	-2:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "メッセージ受信のサイズ指定の誤り。"));
			 			
			 	os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEISIZ );
			 			
				return(OSEEISIZ);					/* 異常終了（invalid size）					*/
				break;

			case	-3:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "アクセス許可なし。"));
			 			
			 	os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEENACC );
			 			
				return(OSEENACC);					/* 異常終了（no access right）				*/
				break;

			case	-4:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "メッセージキューが削除されている。"));
				
				os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEDELD );
				
				return(OSEEDELD);					/* 異常終了（deleted）						*/
				break;

			case	-5:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "タイムアウト。"));
				 		
				os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEETOUT ); 
				 		
				return(OSEETOUT);					/* 異常終了（time out）						*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "バッファプールの領域を超過した。"));
				
				os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEIPOL );  		
				 		
				return(OSEEIPOL);					/* 異常終了（invalid buffer pool）			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "使用中のプールバッファなし。"));
			 			
			 	os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEENPOL );  
			 			
				return(OSEENPOL);					/* 異常終了（not pool buffer）				*/
				break;

			default		:
				// 何もしない
				break;
		}
	}
	else if (2 == lMsgFlg)							/* サブメッセージキューの処理				*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "osgtnrl", "サブメッセージキューの処理へ"));

		/************************************/
		/*  サブメッセージキュー処理		*/
		/************************************/
		lRet = os_SubMsgQ(lMsgType, ptMsg, ptErdcp, ptMyEmbcp, ptMsgNxt);

		switch (lRet)								/* 返却値判定								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "処理異常!!", "システム作業域の処理で失敗。"));
			 		
			 	os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEWKEX );  
			 		
				return(OSEEWKEX);					/* 異常終了（sys work area exhaust）		*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "処理異常!!", "バッファプールの領域を超過した。"));
				 		
				os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEEIPOL );  
				 		
				return(OSEEIPOL);					/* 異常終了（invalid buffer pool）			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "処理異常!!", "使用中のプールバッファなし。"));
			 			
			 	os_trcget2( D_MD_OSGTNRL, D_T_ERR_SYS, 1, OSEENPOL );  
			 			
				return(OSEENPOL);					/* 異常終了（not pool buffer）				*/
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
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osgtnrl" ) );
	
	os_trcget2( D_MD_OSGTNRL, D_T_TRA_OUT, 1, lRet );
	
	return (lRet);									/* 正常終了									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
