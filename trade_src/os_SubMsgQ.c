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
/* ＜モジュールＩＤ＞				 os_SubMsgQ													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*      特定／不特定リザルトのサブメッセージキューの処理をする。                                */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long    os_SubMsgQ()                                                                    */
/*																								*/
/* ＜仮引数＞																					*/
/*      long            lMsgType                                                                */
/*      TMsgHed         *ptMsg                                                                  */
/*      TErdcTableInd   *ptErdcp                                                                */
/*      TEmbcTableInd   *ptEmbcp                                                                */
/*      TMsgInfo        *ptMsgInfo                                                              */
/*																								*/
/* ＜返却値＞																					*/
/*      NORMAL      ：正常                                                                      */
/*      -1          ：sys work area exhaust                                                     */
/*      -6          ：invalid buffer pool                                                       */
/*      -7          ：not pool buffer                                                           */
/*      -8          ：invalid pool buffer                                                       */
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
#include	"os_SubMsgQ_ins.h"


long	os_SubMsgQ(lMsgType, ptMsg, ptErdcp, ptEmbcp, ptMsgInfo)
long			lMsgType;							/* メッセージタイプ							*/
TMsgHed			*ptMsg;								/* メッセージ本体ポインタ					*/
TErdcTableInd	*ptErdcp;							/* 当該ｒｄ管理個別部ポインタ				*/
TEmbcTableInd	*ptEmbcp;							/* 当該メイルボックス個別部ポインタ			*/
TMsgInfo        *ptMsgInfo;							/* メッセージ情報ポインタ					*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lRcvPlBuf;						/* 受信プールバッファアドレス				*/
	long			lBufPl;							/* バッファプールアドレス					*/
	long			lRcvRet;						/* 上位の返却値（受信サイズ返却）			*/
	long			lRet;							/* 返却値									*/
	long			*palPlList[2];					/* プールバッファアドレスリスト				*/
	char			*pcWorkPtr   = NULL;			/* ワークポインタ							*/
	TPbInfo			*ptPbInfo    = NULL;			/* プールバッファ管理情報ポインタ			*/
	TEpbcTableInd	*ptEpbcp     = NULL;			/* ユニット管理情報ポインタ					*/
	TDcsMsgHed		*ptRcvDcsMsg = NULL;			/* 受信ＤＣＳメッセージポインタ				*/
	TDcsMsgHed		*ptDcsMsg    = NULL;			/* ＤＣＳメッセージ用ポインタ				*/

	os_trcget2( D_MD_OS_SUBMSGQ, D_T_TRA_IN, 5, lMsgType, ptMsg, ptErdcp, ptEmbcp, ptMsgInfo );
													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_SubMsgQ" ) );


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lRcvPlBuf = 0;
	lBufPl    = 0;
	lRcvRet   = 0;
	lRet      = 0;
	errno     = 0;

	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType  = %02lx \n", "os_SubMsgQ", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg     = %08lx \n", "os_SubMsgQ", (long)ptMsg));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp   = %08lx \n", "os_SubMsgQ", (long)ptErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcp   = %08lx \n", "os_SubMsgQ", (long)ptEmbcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgInfo = %08lx \n", "os_SubMsgQ", (long)ptMsgInfo));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	switch (lMsgType)								/* メッセージタイプで振り分け				*/
	{
		case	D_MTYPE05:							/* メッセージの受信要求（メイルボックス宛） */
		case	D_MTYPE06:							/* メッセージの受信要求（プロセス宛）		*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_SubMsgQ",
					"プロセス間メッセージ（プールバッファ無し）"));

			/********************************/
			/* 受信メッセージのコピー		*/
			/********************************/
													/* メッセージ長制限の判定					*/
													/* メッセージ長制限有り						*/
			if (ptMsg->lDataSize > *(long *)ptErdcp->pvArg1)
			{
													/* メッセージ受信バッファにコピー			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), *(long *)ptErdcp->pvArg1); 
				lRcvRet = *(long *)ptErdcp->pvArg1; /* 返却値に受信データサイズを設定			*/
			}
			else									/* メッセージ長制限無し						*/
			{
													/* メッセージ受信バッファにコピー			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), ptMsg->lDataSize); 
				lRcvRet = ptMsg->lDataSize; 		/* 返却値に受信データサイズを設定			*/
			}

			/********************************/
			/* メッセージ長制限のメモリ解放 */
			/********************************/
			DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_SubMsgQ",
					ptErdcp->pvArg1));
			
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
			free(ptErdcp->pvArg1);					/* メモリ解放								*/
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0 );

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
/*			20030225 修正
													// メッセージ要求クリア
			if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)
			{
													// メイルボックス宛プールバッファ無しクリア
				ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
			}
			else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)
			{
													// プロセス宛プールバッファ無しクリア
				ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
			}
*/
													// メッセージ要求クリア
			if (D_MTYPE05 == lMsgType)
			{
													// メイルボックス宛プールバッファ無しクリア
				ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
			}
			else if (D_MTYPE06 == lMsgType)
			{
													// プロセス宛プールバッファ無しクリア
				ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
			}
													/* 当該rd個別部の非完了要求状態を			*/
													/* 						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->cReqClass = D_ERDC_REQCLASS00;	/* 要求種別クリア							*/

			ptErdcp->pvArg1 = NULL;					/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = NULL;					/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = NULL;					/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = NULL;					/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = NULL;					/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = NULL;					/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = NULL;					/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = NULL;					/* 引数領域８クリア							*/
			break;

		case	D_MTYPE07:							/* メイルボックス宛プールバッファ有り		*/
		case	D_MTYPE08:							/* プロセス宛プールバッファ有り				*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_SubMsgQ",
					"プロセス間メッセージ（プールバッファ有り）"));

			/********************************/
			/*  受信プールバッファアドレス  */
			/*  のサイズチェック			*/
			/********************************/
			lRcvPlBuf = (long)ptMsg->pcPlBuf;		/* 受信プールバッファアドレス設定			*/
			lBufPl = (long)ptEbpc->pvAdr;			/* バッファプール管理の先頭アドレス設定		*/
			lBufPl = lBufPl + ptEbpc->lSize;		/* バッファプール管理サイズを加算			*/

													/* 受信プールバッファアドレスが				*/
			if (lRcvPlBuf > lBufPl)					/* バッファプール管理の領域を超過した場合	*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  RcvPlBuf=%08x, BufPl=%08x \n",
				 				"os_SubMsgQ", "処理異常!!", lRcvPlBuf, lBufPl));
				return(-6);							/* 異常終了（invalid buffer pool）			*/
			}

			/********************************/
			/*  当該ユニット情報の			*/
			/*  使用中プロセスＩＤチェック	*/
			/********************************/
													/* プールバッファ管理情報ポインタ設定		*/
			ptPbInfo = (TPbInfo *)(ptMsg->pcPlBuf - 4);

			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo=%08x \n", "os_SubMsgQ", ptPbInfo));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo->ptNxtAdr=%08x \n", "os_SubMsgQ",
					ptPbInfo->ptNxtAdr));

													/* ユニット管理情報ポインタ設定				*/
			ptEpbcp = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp=%08x \n", "os_SubMsgQ", ptEpbcp));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_SubMsgQ",
					ptEpbcp->lUsePid));

													/* 使用中プロセスIDが「−１」以外の場合		*/
			if (D_EPBC_USEPID_SEND != ptEpbcp->lUsePid)
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  UsePid=%08x \n", "os_SubMsgQ",
						"処理異常!!", ptEpbcp->lUsePid));
				return(-7);							/* 異常終了（not pool buffer）				*/
			}
													/* 「自プロセスID」設定						*/
			ptEpbcp->lUsePid = ptEsys->tMyPrcInfo.lMyPid;;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEsys->tMyPrcInfo.lMyPid=%08x \n", "os_SubMsgQ",
					ptEsys->tMyPrcInfo.lMyPid));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_SubMsgQ",
					ptEpbcp->lUsePid));

			/***** 仕様変更（SSLA0001）	Start							修正日：2002.12.12	*****/
			/************************************************************************************/
			/*  osrcvmsrでの非プールバッファメッセージ受信の対応								*/
			/************************************************************************************/
													/* プールバッファ無しの受信要求の場合		*/
			if (((D_MTYPE07 == lMsgType) && (D_ERDC_REQCLASS05 ==ptErdcp->cReqClass)) ||
				((D_MTYPE08 == lMsgType) && (D_ERDC_REQCLASS06 ==ptErdcp->cReqClass)))
			{
				/********************************/
				/*  受信メッセージのコピー		*/
				/********************************/
													/* メッセージ長制限の判定					*/
													/* メッセージ長制限有り						*/
				if (ptMsg->lDataSize > *(long *)ptErdcp->pvArg1)
				{
					DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
							"os_SubMsgQ", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* メッセージ受信バッファにコピー			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, *(long *)ptErdcp->pvArg1);
													/* 受信サイズ設定							*/
					lRcvRet = *(long *)ptErdcp->pvArg1;
				}
				else								/* メッセージ長制限無し						*/
				{
					DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
							"os_SubMsgQ", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* メッセージ受信バッファにコピー			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, ptMsg->lDataSize);
					lRcvRet = ptMsg->lDataSize;		/* 受信サイズ設定							*/
				}

				/********************************/
				/* メッセージ長制限のメモリ解放 */
				/********************************/
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_MsgRcvEdit",
						ptErdcp->pvArg1));
				
				os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
				free(ptErdcp->pvArg1);				/* メモリ解放								*/
				os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0 );

				/********************************/
				/* プールバッファの解放			*/
				/********************************/
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->pcPlBuf=%08x \n", "os_MsgRcvEdit",
						ptMsg->pcPlBuf));
													/* プールバッファアドレスリストに			*/
													/* 受信したプールバッファアドレスを設定		*/
				palPlList[0] = (long *)ptMsg->pcPlBuf;

				DbgMsg01(DLv04, (OutPut, "***** %s:palPlList[0] =%08x \n", "os_MsgRcvEdit",
						palPlList[0]));
				DbgMsg01(DLv04, (OutPut, "***** %s:&palPlList[0]=%08x \n", "os_MsgRcvEdit",
						&palPlList[0]));

				lRet = osfrpbf(1L, &palPlList[0]);	/* プールバッファの解放						*/
				if (NORMAL != lRet)					/* 処理異常の場合							*/
				{
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  UsePid=%08x \n",
				 			"os_MsgRcvEdit", "処理異常!!", ptEpbcp->lUsePid));
					return(-8);						/* 異常終了（invalid pool buffer）			*/
				}

				/********************************/
				/* ｒｄ管理テーブルの編集		*/
				/********************************/
/*				20030225 修正
													// メッセージ要求クリア
				if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)
				{
													// メイルボックス宛プールバッファ無しクリア
					ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
				}
				else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)
				{
													// プロセス宛プールバッファ無しクリア
					ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
				}
*/
													/* メッセージ要求クリア						*/
				if ((D_MTYPE07 == lMsgType) && (D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
				{
													/* メイルボックス宛プールバッファ無しクリア */
					ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
				}
				else if ((D_MTYPE08 == lMsgType) && (D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
				{
													/* プロセス宛プールバッファ無しクリア		*/
					ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
				}
													/* 当該rd個別部の非完了要求状態を			*/
													/* 						「未要求」に設定	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

													/* 要求種別クリア							*/
				ptErdcp->cReqClass = D_ERDC_REQCLASS00;

				ptErdcp->pvArg1 = (void *)NULL;		/* 引数領域１クリア							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* 引数領域２クリア							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* 引数領域３クリア							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* 引数領域４クリア							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* 引数領域５クリア							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* 引数領域６クリア							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* 引数領域７クリア							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* 引数領域８クリア							*/
			}
			else									/* プールバッファ有りの受信要求の場合		*/
			{
													/* プールバッファアドレス格納域へコピー		*/
				*(long *)ptErdcp->pvArg1 = (long)ptMsg->pcPlBuf; 

				lRcvRet = ptMsg->lDataSize;			/* 返却値に受信データサイズを設定			*/

				/********************************/
				/* ｒｄ管理テーブルの編集		*/
				/********************************/
/*				20030225 修正
													// メッセージ要求クリア
				if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn)
				{
													// メイルボックス宛プールバッファ有りクリア
					ptErdc->tMsgFlg.cMbPbOn = D_ERDC_MSGFLG_OFF;
				}
				else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn)
				{
													// プロセス宛プールバッファ有りクリア
					ptErdc->tMsgFlg.cPrcPbOn = D_ERDC_MSGFLG_OFF;
				}
*/
													// メッセージ要求クリア
				if (D_MTYPE07 == lMsgType)
				{
													// メイルボックス宛プールバッファ有りクリア
					ptErdc->tMsgFlg.cMbPbOn = D_ERDC_MSGFLG_OFF;
				}
				else if (D_MTYPE08 == lMsgType)
				{
													// プロセス宛プールバッファ有りクリア
					ptErdc->tMsgFlg.cPrcPbOn = D_ERDC_MSGFLG_OFF;
				}
													/* 当該rd個別部の非完了要求状態を			*/
													/* 						「未要求」に設定	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

													/* 要求種別クリア							*/
				ptErdcp->cReqClass = D_ERDC_REQCLASS00;

				ptErdcp->pvArg1 = (void *)NULL;		/* 引数領域１クリア							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* 引数領域２クリア							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* 引数領域３クリア							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* 引数領域４クリア							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* 引数領域５クリア							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* 引数領域６クリア							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* 引数領域７クリア							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* 引数領域８クリア							*/
			}
			/***** 仕様変更（SSLA0001）	 End							修正日：2002.12.12	*****/
			break;

		case	D_MTYPE25:							/* DCSメッセージの受信要求					*/
			/********************************/
			/*  ＤＣＳメッセージの編集		*/
			/********************************/
													/* メモリ獲得								*/
													/* 受信バイトサイズ + ８バイト				*/
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptMsg->lDataSize + 8 );
			pcWorkPtr = malloc(ptMsg->lDataSize + 8+ 4);
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0);
			
			if (NULL == pcWorkPtr)
			{
													/* 障害発生									*/
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
				"os_SubMsgQ", "shmdt() Call Error!!", errno, strerror(errno)));
				return(-1);							/* 異常終了（sys work area exhaust）		*/
			} 

			ptRcvDcsMsg = (TDcsMsgHed *)ptMsg;		/* 受信ＤＣＳメッセージポインタ設定			*/
			ptDcsMsg = (TDcsMsgHed *)pcWorkPtr;		/* ＤＣＳメッセージポインタ設定				*/

													/* メッセージタイプを設定					*/
			ptDcsMsg->lMsgType	= htonl(D_MTYPEDCS_RL);

													/* メッセージ受信サイズを設定               */
			ptDcsMsg->lDataSize	= ptRcvDcsMsg->lDataSize;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lMsgType      = %08x \n",
			"os_SubMsgQ", ptDcsMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lDataSize     = %08x \n",
			"os_SubMsgQ", ptDcsMsg->lDataSize));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode         = %08x \n",
			"os_SubMsgQ", ptErdcp->lRCode));
			DbgMsg01(DLv04, (OutPut, "***** %s:(long *)ptErdcp->pvArg1 = %08x \n",
			"os_SubMsgQ", (long *)ptErdcp->pvArg1));

													/* 受信したメッセージをコピー				*/
			memcpy((ptDcsMsg + 1), (ptRcvDcsMsg + 1), ptRcvDcsMsg->lDataSize); 

													/* プールバッファアドレス格納域へコピー		*/
			*(long *)ptErdcp->pvArg1 = (long)pcWorkPtr;

			lRcvRet = ptRcvDcsMsg->lDataSize; 		/* 返却値に受信データサイズを設定			*/

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
													/* 当該rd個別部の非完了要求状態を			*/
													/* 						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->cReqClass = D_ERDC_REQCLASS00;	/* 要求種別クリア							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* 引数領域８クリア							*/
			break;

		default		:								/* 何もしない								*/
			break;
	}


	/********************************/
	/*  後始末						*/
	/********************************/
													/* サブメッセージキュー削除処理				*/
	lRet = os_MsgQDel(&ptEmbcp->tSubMsgQ, ptMsgInfo);
	if (-1 == lRet)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
				"os_SubMsgQ", "os_MsgQDel() Call Error!!  共有メモリ削除で失敗"));
		return(-1);									/* 異常終了（sys work area exhaust）		*/
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_SubMsgQ" ) );
	os_trcget2( D_MD_OS_SUBMSGQ, D_T_TRA_OUT, 1, lRcvRet );
	
	return (lRcvRet);								/* 正常終了									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
