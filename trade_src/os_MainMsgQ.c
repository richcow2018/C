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
/* ＜モジュール名＞					 メインメッセージ処理										*/
/* ＜モジュールＩＤ＞				 os_MainMsgQ												*/
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
/* ＜ソース修正者＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００２年１２月１２日		仕様変更	（ＳＳＬＡ０００１）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月１３日		故障管理番号（ＴＢＣＳ０１４３）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 特定／不特定リザルトのメインメッセージキュー処理											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_MainMsgQ.h>														        */
/*																								*/
/*	   	long		os_MainMsgQ(long lLimit,long lMsgType,TErdcTableInd *ptErdcp,long lMsgFlg)	*/
/*																								*/
/* ＜仮引数＞																					*/
/*      long            lLimit                                                                  */
/*      long            lMsgType                                                                */
/*      TErdcTableInd   *ptErdcp                                                                */
/*      long            *rda                                                                    */
/*      long            lMsgFlg     （0：特定リザルト 1：不特定リザルト）                       */
/*																								*/
/* ＜返却値＞																					*/
/*      NORMAL      ：正常終了                                                                  */
/*      -1          ：sys work area exhaust                                                     */
/*      -2          ：invalid size                                                              */
/*      -3          ：no access right                                                           */
/*      -4          ：deleted                                                                   */
/*      -5          ：time out                                                                  */
/*      -6          ：invalid buffer pool                                                       */
/*      -7          ：not pool buffer                                                           */
/*      -8          ：invalid pool buffer                                                       */
/*      -9          ：invalid req descriptor                                                    */
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

/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	"os_MainMsgQ_ins.h"


long	os_MainMsgQ(lLimit, lMsgType, ptErdcp, rda, lMsgFlg)
long			lLimit;								/* 制限時間									*/
long			lMsgType;							/* メッセージタイプ							*/
TErdcTableInd	*ptErdcp;							/* 当該ｒｄ管理個別部ポインタ				*/
long			*rda;								/* リクエスト識別子格納域					*/
long			lMsgFlg;							/* メッセージフラグ							*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lMsgqID;						/* メッセージキューＩＤ						*/
	long			lMsgSize;						/* メッセージ受信サイズ						*/
	long			lRcvRet;						/* 上位への返却値用							*/
	long			lRet;							/* 返却値									*/
	long			lCnt1;							/* ループカウント1							*/
	long			lCnt2;							/* ループカウント2							*/
	char			*pcWorkPtr = NULL;				/* ワークポインタ							*/
	TMsgHed			*ptMsg;							/* メッセージポインタ						*/
	TNonEndMsg		*ptNonMsg = NULL;				/* 非完了メッセージポインタ					*/
	TEmbcTableInd	*ptMyEmbcp = NULL;				/* 自プロセスメイルボックス管理情報ポインタ */
	TErdcTableInd	*ptWorkErdcp = NULL;			/* ｒｄ管理個別部のワークポインタ			*/

	os_trcget2( D_MD_OS_MAINMSGQ, D_T_TRA_IN, 5, lLimit, lMsgType, ptErdcp, rda, lMsgFlg);
													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MainMsgQ" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lMsgqID  = 0;									/* メッセージキューＩＤ						*/
	lMsgSize = 0;									/* メッセージ受信サイズ						*/
	lRcvRet  = 0;									/* 上位への返却値用							*/
	lRet  = 0;										/* 返却値									*/
	lCnt1 = 0;										/* ループカウント1							*/
	lCnt2 = 0;										/* ループカウント2							*/
	errno = 0;										/* errno クリア								*/


	DbgMsg01(DLv04, (OutPut, "***** %s:lLimit   = %ld   \n", "os_MainMsgQ", lLimit));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType = %08lx \n", "os_MainMsgQ", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp  = %08lx \n", "os_MainMsgQ", (long)ptErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:rda      = %08lx \n", "os_MainMsgQ", (long)rda));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgFlg  = %ld   \n\n", "os_MainMsgQ", lMsgFlg));


	ptWorkErdcp = ptErdcp;							/* rd管理テーブル個別部のワークポインタ設定	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptWorkErdcp=%08x \n", "os_MainMsgQ", ptWorkErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc=%08x \n", "os_MainMsgQ", ptEmbc));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%08x \n", "os_MainMsgQ",
			ptEmbc->lMaxMsgLng));


	/****************************************/
	/*  メモリ取得							*/
	/****************************************/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_MALLOC, 1, ptEmbc->lMaxMsgLng );
													/* メモリ取得サイズは						*/
	pcWorkPtr = malloc(ptEmbc->lMaxMsgLng);			/* メイルボックス管理部の最大メッセージ長	*/
	
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 2, pcWorkPtr, errno );

	if (NULL == pcWorkPtr)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"os_MainMsgQ", "shmdt() Call Error!!", errno, strerror(errno)));
		return(-1);									/* 異常終了（sys work area exhaust）		*/
	}

	ptMsg = (TMsgHed *)pcWorkPtr;					/* プロセス間メッセージポインタ設定			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg=%08x \n", "os_MainMsgQ", ptMsg));


	/****************************************/
	/*  メッセージキューＩＤの設定			*/
	/****************************************/
													/* 自プロセスメイルボックス情報ポインタ設定 */
	ptMyEmbcp = (TEmbcTableInd *)ptEsys->tMyPrcInfo.ptMyEMBC;
	lMsgqID = ptMyEmbcp->lMsgQId;					/* 自プロセスのメッセージキューＩＤ設定		*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp=%08lx, lMsgqID=%ld \n", "os_MainMsgQ",
			(long)ptMyEmbcp, lMsgqID));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマー発行処理の移動により追加												*/
/*	（os_MsgRcv → os_MainMsgQ）																*/
/************************************************************************************************/
	if (0 < lLimit)									/* 制限時間が０以上の場合					*/
	{
		ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;	/* システムコールタイマフラグのクリア		*/

		os_systim(lLimit, 1, 100);					/* タイマ発行（100m秒単位）					*/
	}
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/

	while(1)										/* ループ処理								*/
	{
		/****************************************/
		/*  クリア								*/
		/****************************************/
		if (1 == lMsgFlg)							/* 不特定リザルト処理の場合					*/
		{
			lMsgType = 0;							/* メッセージタイプ クリア					*/
		}
		lMsgSize = 0;								/* メッセージ受信サイズ						*/
		lRet = 0;									/* 返却値									*/
		lCnt1 = 0;									/* ループカウント1							*/
		lCnt2 = 0;									/* ループカウント2							*/
		errno = 0;									/* errno クリア								*/
		ptErdcp = ptWorkErdcp;						/* rd管理テーブル個別部のポインタ位置初期化 */

		memset(ptMsg, 0, ptEmbc->lMaxMsgLng);		/* メッセージクリア							*/


		/****************************************/
		/*  メッセージ受信						*/
		/****************************************/
													/* メッセージ受信処理						*/
//		lRet = os_MsgRcv(lMsgqID, ptMsg, ptEmbc->lMaxMsgLng, lMsgType, lLimit);
//		lMsgSize = lRet;							/* メッセージ受信サイズを設定				*/
																// 20030330 修正
		lRet = os_MsgRcv(lMsgqID, ptMsg, ptEmbc->lMaxMsgLng - sizeof(long), lMsgType, lLimit);
		lMsgSize = lRet + sizeof(long);				/* メッセージ受信サイズを設定				*/

		DbgMsg01(DLv04, (OutPut, "***** %s:os_MsgRcv  lRet=%08x \n", "os_MainMsgQ", lRet));

		if (-1 == lRet)								/* 返却値がエラーの場合						*/
		{
			if (EINTR == errno)						/* 「ＥＩＮＴＲエラー」の場合				*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "os_MainMsgQ",
																 "EINTRエラー", errno));

/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグの判定処理を修正												*/
/************************************************************************************************/
//				if (0x00 == ptEtmc->cSysTimeFlg)	/* システムコールタイマフラグのクリア		*/

													/* システムコールタイマフラグが「未発行」	*/
													/* 又は「発行中」の場合						*/
				if ((0x00 == ptEtmc->cSysTimeFlg) || (0x01 == ptEtmc->cSysTimeFlg))
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/
				{
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
							 "os_MainMsgQ", "リトライ処理へ", ptEtmc->cSysTimeFlg));

					continue;						/* リトライ処理へ							*/
				}
				else								/* システムコールタイマフラグが				*/
				{									/* 「タイムアウト」の場合					*/
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
							 "os_MainMsgQ", "TIMEOUT ERR", ptEtmc->cSysTimeFlg));

					os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
					free(pcWorkPtr);				/* メモリ解放								*/
					os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグのクリアを追加													*/
/************************************************************************************************/
													/* システムタイマフラグの初期化				*/
					ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/

					return(-5);						/* OSEETOUT									*/
				}
			}
			else if (EINTR != errno)				/* エラー処理をする							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "os_MainMsgQ",
														 "EINTR以外のエラー", errno));

				if (0 < lLimit)						/* 制限時間が０以上の場合					*/
				{
					os_tmcan(0);					/* タイマキャンセル							*/
				}

				/****************************************/
				/*  errno の判定						*/
				/****************************************/
				switch (errno)
				{
					case	E2BIG:					/* OSEEISIZ									*/
					case	EINVAL:					/* OSEEISIZ									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* メモリ解放								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-2);
						break;

					case	EACCES:					/* OSEENACC									*/
					case	EFAULT:					/* OSEENACC									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* メモリ解放								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-3);
						break;

					case	EIDRM:					/* OSEEDELD									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* メモリ解放								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-4);
						break;

					case	ENOMSG:					/* OSEETOUT									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* メモリ解放								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-5);
						break;

					default		:					/* 何もしない								*/
						break;
				}
			}
		}

		if (1 == lMsgFlg)							/* 不特定リザルト処理の場合					*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "os_MainMsgQ", "不特定リザルト処理"));

			/************************************/
			/*  メッセージ内容チェック			*/
			/************************************/
													/* ＤＣＳメッセージのチェック				*/
			if ((D_MTYPEDCS_MIN <= ptMsg->lMsgType) && (D_MTYPEDCS_MAX >= ptMsg->lMsgType))
			{
				lMsgType = D_MTYPE25;				/* メッセージタイプにＤＣＳメッセージを設定 */
			}
			else
			{
				lMsgType = ptMsg->lMsgType;			/* 受信したメッセージタイプを設定			*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lMsgType = %08x, lMsgType = %02x \n",
					"os_MainMsgQ", ptMsg->lMsgType, lMsgType));


			switch (lMsgType)						/* メッセージタイプで振り分け				*/
			{
				case	D_MTYPE05:					/* メッセージの受信要求（メイルボックス宛） */
				case	D_MTYPE06:					/* メッセージの受信要求（プロセス宛）		*/
				case	D_MTYPE07:					/* メイルボックス宛プールバッファ有り		*/
				case	D_MTYPE08:					/* プロセス宛プールバッファ有り				*/
				case	D_MTYPE25:					/* ＤＣＳメッセージの受信要求				*/

					/************************************************************************/
					/*  受信メッセージタイプとrd管理テーブルの要求種別の一致する			*/
					/*  当該の個別部を検索する												*/
					/************************************************************************/
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOff  = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cMbPbOff));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOff = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cPrcPbOff));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOn   = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cMbPbOn));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOn  = %02x \n\n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cPrcPbOn));

					/***** 仕様変更（SSLA0001）	Start					修正日：2002.12.12	*****/
					/****************************************************************************/
					/*  osrcvmsrでの非プールバッファメッセージ受信の対応						*/
					/****************************************************************************/
													/* メッセージタイプとrd管理テーブル管理部の */
													/* メッセージ要求フラグの内容が一致する場合 */
//					if (((D_MTYPE05 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
//					|| ((D_MTYPE06 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
//					|| ((D_MTYPE07 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
//					|| ((D_MTYPE08 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn)))

													/* メッセージの受信要求（メイルボックス宛）	*/
													/* かつメイルボックス宛プールバッファ無しON */
													/* 又は										*/
													/* メッセージの受信要求（プロセス宛）		*/
													/* かつプロセス宛プールバッファ無しON		*/
													/* 又は										*/
													/* プールバッファ上のメッセージの			*/
													/* 			受信要求（メイルボックス宛）	*/
													/* かつメイルボックス宛プールバッファ有りON */
													/* 又は										*/
													/* プールバッファ上のメッセージの			*/
													/* 			受信要求（メイルボックス宛）	*/
													/* かつメイルボックス宛プールバッファ無しON */
													/* 又は										*/
													/* プールバッファ上のメッセージの			*/
													/* 			受信要求（プロセス宛）			*/
													/* かつプロセス宛プールバッファ有りON		*/
													/* 又は										*/
													/* プールバッファ上のメッセージの			*/
													/* 			受信要求（プロセス宛）			*/
													/* かつプロセス宛プールバッファ無しON		*/
													/* 又は										*/
													/* ＤＣＳメッセージの受信要求				*/
													/* かつメイルボックス宛プールバッファ有りON */
					if (((D_MTYPE05 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
					 || ((D_MTYPE06 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
					 || ((D_MTYPE07 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
					 || ((D_MTYPE07 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
					 || ((D_MTYPE08 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn))
					 || ((D_MTYPE08 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
					 || ((D_MTYPE25 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn)))
					/***** 仕様変更（SSLA0001）	 End					修正日：2002.12.12	*****/
					{
						DbgMsg01(DLv04,(OutPut,"***** %s:%s \n","os_MainMsgQ", "対象データあり"));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp=%08x \n","os_MainMsgQ", ptErdcp));

						/************************************/
						/*  ｒｄ管理テーブル個別部検索		*/
						/************************************/
						//for(lCnt1 = 0; lCnt1 < ptErdc->lMaxIndNum; lCnt1++)
						for(lCnt1 = 0; lCnt1 < ptMyEPRC->lMaxReqNum; lCnt1++)
						{
							DbgMsg01(DLv04,(OutPut,"***** %s:lMsgType=%x,cReqClass=%02x,lCnt1=%d\n"
									, "os_MainMsgQ", lMsgType, ptErdcp->cReqClass, lCnt1));
							DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n",
									"os_MainMsgQ", ptErdcp));

													/* メッセージタイプと要求種別が一致した場合 */
							if (lMsgType == ptErdcp->cReqClass)
							{
													/* 当該個別部のリクエスト識別子を設定  		*/
//								*rda = ptErdcp->lRCode;		
								break;				/* ｒｄ管理テーブル個別部の検索を終了する	*/
							}
							/***** 仕様変更（SSLA0001）	Start			修正日：2002.12.12	*****/
							/********************************************************************/
							/*  osrcvmsrでの非プールバッファメッセージ受信の対応				*/
							/********************************************************************/
							else					/* 一致しなかった場合						*/
							{
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（メイルボックス宛） */
													/* の場合									*/
								if ((D_MTYPE07 == lMsgType) &&
									(D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
								{
									break;			/* ｒｄ管理テーブル個別部の検索を終了する	*/
								}
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(プロセス宛)		*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（プロセス宛）の場合 */
								if ((D_MTYPE08 == lMsgType) &&
									(D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
								{
									break;			/* ｒｄ管理テーブル個別部の検索を終了する	*/
								}
													/* ＤＣＳメッセージの受信要求				*/
													/* かつｒｄ管理テーブル個別部の要求種別が	*/
													/* メッセージの受信要求（メイルボックス宛） */
													/* の場合									*/
								if ((D_MTYPE25 == lMsgType) &&
									(D_ERDC_REQCLASS07 ==ptErdcp->cReqClass))
								{
									break;			/* ｒｄ管理テーブル個別部の検索を終了する	*/
								}
							}
							/***** 仕様変更（SSLA0001）	 End			修正日：2002.12.12	*****/

							ptErdcp++;				/* 次アドレスへポインタを進める				*/
						}

													/* ｒｄ管理テーブル個別部の最大値を超過		*/
						//if (lCnt1 >= ptErdc->lMaxIndNum)
						if (lCnt1 >= ptMyEPRC->lMaxReqNum)
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
								"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));

							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
							free(pcWorkPtr);		/* メモリ解放								*/
							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

							return(-9);				/* 異常終了（invalid req descriptor）		*/
						}
						else
						{
													/* 当該ｒｄ管理テーブル個別部の				*/
													/* リクエスト状態が「要求済(0x01)」以外の場合*/
							if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
							{
								DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
										"処理異常!!", "要求されたデータがありません。"));

								os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
								free(pcWorkPtr);	/* メモリ解放								*/
								os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

								return(-10);		/* 異常終了（no request）					*/
							}
						}
						*rda = ptErdcp->lRCode;		/* 当該個別部のリクエスト識別子を設定  		*/
					}
					else							/* 対象データなし							*/
					{
						/************************************/
						/*  メッセージキューイング処理		*/
						/************************************/
						lRet = os_MsgQIng(lMsgType, lMsgSize, ptMsg, &ptMyEmbcp->tSubMsgQ);
						if (-1 == lRet)				/* 異常の場合								*/
						{
													/* 障害発生									*/
							DbgMsg01(DLv05, (OutPut, "***** %s:os_MsgQing Call Err lRet=%08x \n",
									 "os_MainMsgQ", lRet));

							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
							free(pcWorkPtr);		/* メモリ解放								*/
							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
							
							return(-1);				/* 異常終了（sys work area exhaust）		*/
						}

						DbgMsg01(DLv04, (OutPut, "***** %s:%s  lRet=%08x\n", "os_MainMsgQ",
								"メッセージキューイング処理正常。リトライ処理へ", lRet));

						continue;					/* リトライ									*/
					}
					break;

				default		:						/* 非完了メッセージ							*/
					ptNonMsg = (TNonEndMsg *)ptMsg;	/* 非完了メッセージポインタ設定				*/

					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg=%08x \n",
							"os_MainMsgQ", ptNonMsg));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->tMsgHed.lMsgType=%02lx \n",
							"os_MainMsgQ", ptNonMsg->tMsgHed.lMsgType));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->lReqNum=%d \n",
							"os_MainMsgQ", ptNonMsg->lReqNum));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->lResult=%d \n",
							"os_MainMsgQ", ptNonMsg->lResult));

					/************************************/
					/*  ｒｄ管理テーブル個別部検索		*/
					/************************************/
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n", "os_MainMsgQ", ptErdcp));

					//for(lCnt2 = 0; lCnt2 < ptErdc->lMaxIndNum; lCnt2++)
					for(lCnt2 = 0; lCnt2 < ptMyEPRC->lMaxReqNum; lCnt2++)
					{
						DbgMsg01(DLv04,(OutPut,"***** %s:lMsgType=%02x,cReqClass=%02x,lCnt2=%d \n",
								"os_MainMsgQ", ptMsg->lMsgType, ptErdcp->cReqClass, lCnt2));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp=%08x \n","os_MainMsgQ",ptErdcp));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp->lReqNum=%08x \n",
								"os_MainMsgQ",ptErdcp->lReqNum));

													/* メッセージタイプと要求種別が一致した場合 */
//						if (lMsgType == ptErdcp->cReqClass)
													/* 受信したメッセージタイプと				*/
													/* ｒｄ管理テーブルの要求種別が一致 かつ	*/
													/* 受信したリクエスト番号とｒｄ管理テーブル */
													/* のリクエスト番号が一致する場合			*/
						if ((lMsgType == ptErdcp->cReqClass) &&
							(ptNonMsg->lReqNum == ptErdcp->lReqNum))
						{
							break;					/* ｒｄ管理テーブル個別部の検索を終了する	*/
						}
						ptErdcp++;					/* 次アドレスへポインタを進める				*/
					}
													
					//if(lCnt2 >= ptErdc->lMaxIndNum)/*ｒｄ管理テーブル個別部の最大値を超過	*/
					if(lCnt2 >= ptMyEPRC->lMaxReqNum)
					{
//						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
//								"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));

//						free(pcWorkPtr);			/* メモリ解放								*/
//						return(-9);					/* 異常終了（invalid req descriptor）		*/
						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
			 					"処理異常!!", "受信したメッセージを破棄し、リトライする。"));
						continue;					/* リトライ									*/
					}
													/* リクエスト状態が非完了要求済み以外の場合 */
					if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
					{
						DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->tReqStat.cUCompStat=%02x\n",
								"os_MainMsgQ", ptErdcp->tReqStat.cUCompStat));
						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
			 					"処理異常!!", "受信したメッセージを破棄し、リトライする。"));
						continue;					/* リトライ									*/
					}

					*rda = ptErdcp->lRCode;			/* 当該個別部のリクエスト識別子を設定  		*/
					break;
			}
		}


		/****************************************/
		/*  受信結果の編集						*/
		/****************************************/
		if (0 < lLimit)								/* 制限時間が「0」より大きいの場合			*/
		{
			os_tmcan(0);							/* タイマキャンセル							*/
		}

													/* 受信結果の編集							*/
		lRet = os_MsgRcvEdit(lMsgType, lMsgSize, ptMsg, ptErdcp);

		DbgMsg01(DLv04, (OutPut, "***** %s:os_MsgRcvEdit  lRet=%08x\n", "os_MainMsgQ", lRet));

		if (0 <= lRet)								/* 返却値が0以上の場合						*/
		{
			lRcvRet = lRet;							/* 上位への返却値に返却値を設定				*/
			break;									/* ループ処理を抜ける						*/
		}
		else										/* 返却値がマイナスの場合					*/
		{
			if ((D_MTYPE05 == lMsgType) ||			/* プロセス間メッセージの場合				*/
				(D_MTYPE06 == lMsgType) ||
				(D_MTYPE07 == lMsgType) ||
				(D_MTYPE08 == lMsgType) ||
				(D_MTYPE25 == lMsgType))
			{
				/* 特に何もしない		*/
			}
			else									/* プロセス間メッセージ以外の場合			*/
			{										/* （非完了型メッセージの場合）				*/
				lRcvRet = lRet;						/* 上位への返却値に返却値を設定				*/
				break;								/* ループ処理を抜ける						*/
			}
		}
		if (1 == lMsgFlg)							/* 不特定リザルト処理の場合					*/
		{
			*rda = 0;								/* リクエスト識別子格納域をクリア  			*/
		}

		/****************************************/
		/*  エラー判定							*/
		/****************************************/
		switch (lRet)
		{
			case	-1:								/* sys work area exhaust					*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* メモリ解放								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* リクエスト識別子格納域をクリア  			*/
				return(-1);
				break;

			case	-2:								/* invalid buffer pool						*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* メモリ解放								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* リクエスト識別子格納域をクリア  			*/
				return(-6);
				break;

			case	-3:								/* not pool buffer							*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* メモリ解放								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* リクエスト識別子格納域をクリア  			*/
				return(-7);
				break;

			case	-4:								/* invalid pool buffer						*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* メモリ解放								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* リクエスト識別子格納域をクリア  			*/
				return(-8);
				break;

			default		:							/* 非完了型メッセージ（異常の場合）			*/
				break;
		}
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
	/********************************/
	/*  メモリ解放					*/
	/********************************/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);								/* メモリ解放								*/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End  DbgSubFnc\n", "os_MainMsgQ" ) );
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_TRA_OUT, 0 );
	return (lRcvRet);								/* 正常終了									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
