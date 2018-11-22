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
/* ＜モジュール名＞					 非完了型処理要求の取消し									*/
/* ＜モジュールＩＤ＞				 oscanrq													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(:ＸＸＸＸ)							*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　５月　７日		故障管理番号（ＴＢＣＳ００７８）*/
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月１６日		故障管理番号（ＴＢＣＳ０１２０）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 以前に要求を出した、非完了型処理要求に対する処理の取り消しを要求する。						*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscanrq.h>																	*/
/*																								*/
/*	   	long	oscanrq(long rd)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		rd;																			*/
/*																								*/
/* ＜返却値＞																					*/
/*		OSEEIVNO	：リクエスト識別子の値が不正   												*/
/*		OSEENREQ	：未要求																	*/
/*		OSEEIGNR	：キャンセル不定															*/
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
#include	"oscanrq.h"
#include	"oscanrq_ins.h"


long	oscanrq(rd)
long	rd;											/* リクエスト識別子							*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lCnt1;							/* ループカウンタ1							*/
	long			lCnt2;							/* ループカウンタ2							*/
	long			lCnt3;							/* ループカウンタ3							*/
	long			lCnt4;							/* ループカウンタ4							*/
	long			lRet;							/* 返却値									*/
	long			lBufSize;						/* 出力バッファサイズ						*/
	char			*pcBuf = NULL;					/* 出力用バッファ領域						*/
//	TMsgHed			tMsgBuf;						/* 出力用バッファ領域						*/
	TArgInfo		tTArgInfo; 						/* 要求情報用アーギュメント					*/
	TErdcTableInd	*ptErdcp = NULL;				/* ｒｄ管理テーブル個別部ポインタ			*/
	TEcncTableInd	*ptEcncp = NULL;				/* コネクション管理テーブル個別部ポインタ	*/


	os_trcget2( D_MD_OSCANRQ, D_T_TRA_IN, 1, rd );

													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "oscanrq" ) );


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lCnt1 = 0;
	lCnt2 = 0;
	lCnt3 = 0;
	lCnt4 = 0;
	lRet  = 0;
	errno = 0;

	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ｒｄ管理個別部の先頭アドレス設定         */
	ptEcncp = (TEcncTableInd *)(ptEcnc + 1);		/* コネクション管理個別部の先頭アドレス設定 */


	/************************************/
	/*  引数チェック					*/
	/************************************/

	/* リクエスト識別子（rd）のチェック */
													/* ループ処理								*/
	//for (lCnt1 = 0; lCnt1 < ptErdc->lMaxIndNum; lCnt1++)
	for (lCnt1 = 0; lCnt1 < ptMyEPRC->lMaxReqNum; lCnt1++)
	{
		if (rd == ptErdcp->lRCode)					/* リクエスト識別子が一致した場合			*/
		{
			break;									/* ループを抜ける							*/
		}

		ptErdcp++;									/* 次アドレスへポインタを進める				*/
	}

	//if (lCnt1 >= ptErdc->lMaxIndNum)				/* ｒｄ管理テーブル個別部の最大値を超過		*/
	if (lCnt1 >= ptMyEPRC->lMaxReqNum)
	{												/* ｒｄ管理テーブルの個別部が存在しない場合 */
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "oscanrq",
			"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));
			
		os_trcget2( D_MD_OSCANRQ, D_T_ERR_PRA, 1, OSEEIVRD );
			
		return(OSEEIVRD);							/* 異常終了（invalid req descriptor）		*/
	}
	else
	{
													/* 当該ｒｄ管理テーブル個別部の				*/
													/* リクエスト状態が「要求済(0x01)」以外の場合*/
		if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  リクエスト状態=%02x \n", "oscanrq",
					"処理異常!!", "要求されたデータがありません。", ptErdcp->tReqStat.cUCompStat));
					
			os_trcget2( D_MD_OSCANRQ, D_T_ERR_PRA, 1, OSEENREQ );
			
			return(OSEENREQ);						/* 異常終了（no request）					*/
		}
	}

	DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop1 Count=%#d 回目  ", "oscanrq", lCnt1));
	DbgMsg01(DLv04, (OutPut, "ptErdcp=%08x \n", ptErdcp));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/********************************************************/
	/*  非完了要求の取り消し（要求種別毎に処理を振分け）	*/
	/********************************************************/
	switch (ptErdcp->cReqClass)						/* 要求種別毎に処理を振分け					*/
	{
		case	D_ERDC_REQCLASS02:					/* インターバルタイマ						*/
		case	D_ERDC_REQCLASS03:					/* 時刻タイマ								*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s 要求種別=%02x \n", "oscanrq",
					"インターバルタイマ又は時刻タイマの処理", ptErdcp->cReqClass));

			os_tmcan(rd);							/* タイマキャンセルを発行					*/

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
													/* 20030227 追加							*/
													/* 当該rd個別部の非完了要求状態を			*/
													/*						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* リクエスト番号クリア						*/

			ptErdcp->cReqClass = 0x00;				/* 要求種別クリア							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* 引数領域８クリア							*/

			break;

		case	D_ERDC_REQCLASS05:					/* メッセージの受信要求（メイルボックス宛）	*/
		case	D_ERDC_REQCLASS06:					/* メッセージの受信要求（プロセス宛）		*/
		case	D_ERDC_REQCLASS07:					/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
		case	D_ERDC_REQCLASS08:					/* プロセス宛プールバッファ有り				*/
													/* 				受信要求（プロセス宛）		*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq",
					"プロセス間メッセージの処理", ptErdcp->cReqClass));
			break;

//		case	D_ERDC_REQCLASS17:					/* TCP/IPコネクションの制御・監視(osiioct2)	*/
		case	D_ERDC_REQCLASS22:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq",
					"TCP/IPコネクションの制御・監視の処理"));

													/* 非同期通知要求情報から検索				*/
			for (lCnt2 = 0; lCnt2 < ptEcnc->lMaxIndNum; lCnt2++)
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lCnt2=%d \n", "oscanrq", lCnt2));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode=%08x \n", "oscanrq",
						ptErdcp->lRCode));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->tAsyncInfo.lReqId=%08x \n",
						"oscanrq", ptEcncp->tAsyncInfo.lReqId));

													/* リクエスト識別子が一致した場合			*/
				if (ptErdcp->lRCode == ptEcncp->tAsyncInfo.lReqId)
				{
					break;							/* ループを抜ける							*/
				}
				ptEcncp++;
			}

			if (lCnt2 >= ptEcnc->lMaxIndNum)		/* コネクション管理の最大個別部数を超過		*/
			{
				DbgMsg01(DLv05, (OutPut, "\n***** %s:%s  %s \n", "oscanrq",
					"処理異常!!", "該当するコネクション管理テーブルの個別部はありません。"));
					
				os_trcget2( D_MD_OSCANRQ, D_T_ERR_SYS, 1, OSEENREQ );	

				return(OSEENREQ);					/* 異常終了（invalid req descriptor）		*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->alPipeDes[1]=%d \n", "oscanrq",
					ptEcncp->alPipeDes[1]));

			/*  パイプディスクリプタのチェック */
			if (0 != ptEcncp->alPipeDes[1])			/* 出力用パイプディスクリプタが0以外の場合  */
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "キャンセル通知"));

				/********************************/
				/*  キャンセル通知				*/
				/********************************/
//				tMsgBuf.lMsgType = D_MTYPE18;		/* メッセージタイプ							*/
//				tMsgBuf.pcPlBuf = NULL;				/* プールバッファ							*/
//				tMsgBuf.lDataSize = 0;				/* データサイズ								*/

				/********************************/
				/*  アーギュメント情報設定		*/
				/********************************/
													/* 要求種別（非同期通知要求キャンセル）		*/
				tTArgInfo.cRecClass = D_REQCLASS_ASYNC_CANCEL;
				tTArgInfo.lRCode = 0;				/* リクエスト識別子							*/
				tTArgInfo.ulReqNum = 0;				/* リクエスト番号							*/
				tTArgInfo.pvArg1 = NULL; 			/* 引数情報１								*/
				tTArgInfo.pvArg2 = NULL; 			/* 引数情報２								*/

				pcBuf = &tTArgInfo;					/* 出力用バッファ領域を設定					*/
				lBufSize = sizeof(TArgInfo);		/* 出力バッファサイズを設定					*/

				DbgMsg01(DLv04, (OutPut, "\n***** %s:tTArgInfo.cRecClass=%02x \n",
						"oscanrq", tTArgInfo.cRecClass));
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lBufSize=%ld \n", "oscanrq", lBufSize));

				while (1)							/* ループ処理								*/
				{
													/* ファイルディスクリプタに書き込む			*/
//					lRet = write(ptEcncp->alPipeDes[1], &tMsgBuf, sizeof(TMsgHed));
					lRet = write(ptEcncp->alPipeDes[1], pcBuf, lBufSize);
					DbgMsg01(DLv04, (OutPut, "\n***** %s:write lRet=%08x \n", "oscanrq", lRet));

					if (D_ERR_SYS == lRet)			/* 返却値が異常の場合						*/
					{
						if (EINTR == errno)			/* 割り込み発生								*/
						{
							continue;				/* リトライ									*/
						}
						else						/* 障害発生                                 */
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
							"oscanrq", "write() Call Error!!", errno, strerror(errno)));
							break;
						}
					}
					else if (lBufSize == lRet)		/* 出力バッファサイズと返却値が同一の場合	*/
					{
						break;						// ループを抜ける
					}
					else							/* 残りのデータがある場合					*/
					{
						pcBuf = pcBuf + lRet;		/* 出力バッファのアドレス位置を更新			*/
						lBufSize = lBufSize - lRet; /* 出力サイズから残りのサイズを減算			*/
					}
				}
			}

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
													/* 当該rd個別部の非完了要求状態を			*/
													/*						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* リクエスト番号クリア						*/

			ptErdcp->cReqClass = 0x00;				/* 要求種別クリア							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* 引数領域８クリア							*/
			break;

//		case	D_ERDC_REQCLASS19:					/* TCP/IPリード(osireadd2)					*/
		case	D_ERDC_REQCLASS23:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "TCP/IPリードの処理"));

													/* read要求情報から検索						*/
			for (lCnt3 = 0; lCnt3 < ptEcnc->lMaxIndNum; lCnt3++)
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lCnt3=%d \n", "oscanrq", lCnt3));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode=%08x \n", "oscanrq",
						ptErdcp->lRCode));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->tReaInfo.lReqId=%08x \n",
						"oscanrq", ptEcncp->tReaInfo.lReqId));

													/* リクエスト識別子が一致した場合			*/
				if (ptErdcp->lRCode == ptEcncp->tReaInfo.lReqId)
				{
					break;							/* ループを抜ける							*/
				}
				ptEcncp++;
			}

			if (lCnt3 >= ptEcnc->lMaxIndNum)		/* コネクション管理の最大個別部数を超過		*/
			{
				DbgMsg01(DLv05, (OutPut, "\n***** %s:%s  %s \n", "oscanrq",
					"処理異常!!", "該当するコネクション管理テーブルの個別部はありません。"));
		
				os_trcget2( D_MD_OSCANRQ, D_T_ERR_SYS, 1, OSEENREQ );
					
	/*****	障害対応（TBCS0120）	Start								修正日：2003.06.16	*****/
	/********************************************************************************************/
	/*	OSEENREQのエラー返却をやめ、ｒｄ管理テーブルをクリアするように修正						*/
	/********************************************************************************************/
//				return(OSEENREQ);					/* 異常終了（invalid req descriptor）		*/

				/********************************/
				/* ｒｄ管理テーブルの編集		*/
				/********************************/
													/* 当該rd個別部の非完了要求状態を			*/
													/*						「未要求」に設定	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

				ptErdcp->lReqNum = 0L;				/* リクエスト番号クリア						*/

				ptErdcp->cReqClass = 0x00;			/* 要求種別クリア							*/

				ptErdcp->pvArg1 = (void *)NULL;		/* 引数領域１クリア							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* 引数領域２クリア							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* 引数領域３クリア							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* 引数領域４クリア							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* 引数領域５クリア							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* 引数領域６クリア							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* 引数領域７クリア							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* 引数領域８クリア							*/
				break;
	/*****	障害対応（TBCS0120）	 End								修正日：2003.06.16	*****/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->alPipeDes[1]=%d \n", "oscanrq",
					ptEcncp->alPipeDes[1]));

			/*  パイプディスクリプタのチェック */
			if (0 != ptEcncp->alPipeDes[1])			/* 出力用パイプディスクリプタが0以外の場合  */
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "キャンセル通知"));

				/********************************/
				/*  キャンセル通知				*/
				/********************************/
//				tMsgBuf.lMsgType = D_MTYPE20;		/* メッセージタイプ							*/
//				tMsgBuf.pcPlBuf = NULL;				/* プールバッファ							*/
//				tMsgBuf.lDataSize = 0;				/* データサイズ								*/

				/********************************/
				/*  アーギュメント情報設定		*/
				/********************************/
													/* 要求種別（READ要求キャンセル）			*/
				tTArgInfo.cRecClass = D_REQCLASS_READ_CANCEL;
				tTArgInfo.lRCode = 0;				/* リクエスト識別子							*/
				tTArgInfo.ulReqNum = 0;				/* リクエスト番号							*/
				tTArgInfo.pvArg1 = NULL; 			/* 引数情報１								*/
				tTArgInfo.pvArg2 = NULL; 			/* 引数情報２								*/

				pcBuf = &tTArgInfo;					/* 出力用バッファ領域を設定					*/
				lBufSize = sizeof(TArgInfo);		/* 出力バッファサイズを設定					*/

				DbgMsg01(DLv04, (OutPut, "\n***** %s:tTArgInfo.cRecClass=%02x \n",
						"oscanrq", tTArgInfo.cRecClass));
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lBufSize=%ld \n", "oscanrq", lBufSize));

				while (1)							/* ループ処理								*/
				{
													/* ファイルディスクリプタに書き込む			*/
//					lRet = write(ptEcncp->alPipeDes[1], &tMsgBuf, sizeof(TMsgHed));
					lRet = write(ptEcncp->alPipeDes[1], pcBuf, lBufSize);
					DbgMsg01(DLv04, (OutPut, "\n***** %s:write lRet=%08x \n", "oscanrq", lRet));

					if (D_ERR_SYS == lRet)
					{
						if (EINTR == errno)			/* 割り込み発生								*/
						{
							continue;				/* リトライ									*/
						}
						else						/* 障害発生                                 */
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
							"oscanrq", "write() Call Error!!", errno, strerror(errno)));
							break;
						}
					}
					else if (lBufSize == lRet)		/* 出力バッファサイズと返却値が同一の場合	*/
					{
						break;						// ループを抜ける
					}
					else							/* 残りのデータがある場合					*/
					{
						pcBuf = pcBuf + lRet;		/* 出力バッファのアドレス位置を更新			*/
						lBufSize = lBufSize - lRet; /* 出力サイズから残りのサイズを減算			*/
					}
				}
			}

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
													/* 当該rd個別部の非完了要求状態を			*/
													/*						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* リクエスト番号クリア						*/

			ptErdcp->cReqClass = 0x00;				/* 要求種別クリア							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* 引数領域８クリア							*/
			break;

	/*****	障害対応（TBCS0078）	Start								修正日：2003.05.07	*****/
	/********************************************************************************************/
	/*	osiwritd2の（ｒｄ管理テーブルのクリア）処理を追加										*/
	/********************************************************************************************/
//		case	D_ERDC_REQCLASS21:					/* TCP/IPライト(osiwritd2)					*/
		case	D_ERDC_REQCLASS24:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "TCP/IPライトの処理"));

			/********************************/
			/* ｒｄ管理テーブルの編集		*/
			/********************************/
													/* 当該rd個別部の非完了要求状態を			*/
													/*						「未要求」に設定	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* 当該rd個別部の使用状態を「未使用」に設定	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* リクエスト番号クリア						*/

			ptErdcp->cReqClass = 0x00;				/* 要求種別クリア							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* 引数領域１クリア							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* 引数領域２クリア							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* 引数領域３クリア							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* 引数領域４クリア							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* 引数領域５クリア							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* 引数領域６クリア							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* 引数領域７クリア							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* 引数領域８クリア							*/
	/*****	障害対応（TBCS0078）	 End								修正日：2003.05.07	*****/
			break;

		default		:								/* その他の非完了要求						*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "その他非完了の処理"));
			break;
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "oscanrq" ) );


	os_trcget2( D_MD_OSCANRQ, D_T_TRA_OUT, 1, OSEEIGNR );

	return (OSEEIGNR);								/* キャンセル不定							*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
