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
/* ＜モジュール名＞					 サブメッセージ追加											*/
/* ＜モジュールＩＤ＞				 os_MsgQIng													*/
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
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月２２日		故障管理番号（ＴＢＣＳ０２３４）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 不特定リザルトで受信したメッセージをサブメッセージキューへキューイングする					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_MsgQing>																*/
/*																								*/
/*	   	long		os_MsgQing(long lMsgType, TMsgHed *ptMsg, TSubMsgQ *ptSubmsgQ)				*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		lMsgType;		 	メッセージタイプ										*/
/*      long        lMsgSize                                                                    */
/*		TMsgHed		*ptMsg;		 		メッセージポインタ										*/
/*		TSubMsgQ    *ptSubMsgQ;         サブメッセージキュー管理情報							*/
/* ＜返却値＞																					*/
/*	    正常終了	NORMAL																		*/
/*		異常終了	-1																			*/
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
#include	"os_MsgQIng_ins.h"

long	os_MsgQIng(lMsgType, lMsgSize, ptMsg, ptSubMsgQ)
long		lMsgType;								/* メッセージタイプ							*/
long		lMsgSize;								/* メッセージ受信サイズ						*/
TMsgHed		*ptMsg;									/* メッセージポインタ						*/
TSubMsgQ    *ptSubMsgQ;								/* サブメッセージキュー管理情報				*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	char			*pcCmptr     = NULL;			/* アタッチする仮想アドレスポインタ 		*/
	char			acSemKey[16];					/* SemKey格納域（Ntok用）					*/
	char			acShmKey[16];					/* ShmKey格納域（Ntok用）					*/
	long			lSemKey;						/* セマフォKey 格納用						*/
	long			lSemId;							/* セマフォID  格納用						*/
	long			lWorkShmKey;					/* 共有メモリKey 格納（ワーク用）			*/
	long			lShmKey;						/* 共有メモリKey 格納用						*/
	long 			lShmId;							/* 共有メモリID  格納用						*/
	long			lCmSize;						/* 共有メモリサイズ							*/
	long			lRet;							/* 返却値									*/
	TMsgInfo		*ptMsgBef    = NULL;			/* 受信メッセージ（一つ前）のポインタ		*/
	TMsgInfo		*ptCmMsgInfo = NULL;			/* メッセージ情報（管理部情報）共有メモリ用	*/
	TMsgHed			*ptCmMsg     = NULL;			/* 共有メモリ用メッセージポインタ			*/
	TDcsMsgHed		*ptCmDcsMsg  = NULL;			/* 共有メモリ用ＤＣＳメッセージポインタ		*/
	struct sembuf	tSem;							/* セマフォ用								*/

	os_trcget2( D_MD_OS_MSGQING, D_T_TRA_IN, 4, lMsgType, lMsgSize, ptMsg, ptSubMsgQ );
													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MsgQIng" ) );


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lSemKey     = 0;
	lSemId      = 0;
	lWorkShmKey = 0;
	lShmKey     = 0;
	lShmId      = 0;
	lCmSize     = 0;
	lRet        = 0;
	errno       = 0;


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType =%02x \n", "os_MsgQIng", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgSize =%d \n", "os_MsgQIng", lMsgSize));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg    =%08x \n", "os_MsgQIng", ptMsg));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ=%08x \n", "os_MsgQIng", ptSubMsgQ));


	/********************************************/
	/*  メイルボックス管理テーブル管理情報の    */
	/*  「セマフォＩＤ」のチェック				*/
	/********************************************/
	if (0 == ptEmbc->lSemId)						/* セマフォＩＤが「0」の場合				*/
	{
													/* ＳＧからデータを取得する					*/
		lRet = os_getSG(D_SG_EMBC_SEM_KEY, acSemKey);
		//lRet = os_getSG(D_SG_EMBC_SKEY, acSemKey);	// 20030307 KL0027 修正
		if (-2 == lRet)								/* 返却値が「-2」の場合は処理終了			*/
		{
			return(-1);								/* 異常終了									*/
		}

		/********************************************/
		/*  ntok関数コール    						*/
		/********************************************/
		lSemKey = BlpMpf_ntok(acSemKey, D_NTOK_ID); /*  富士通提供関数(ntok)を発行              */
		DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok() acSemKey=%s \n", "os_MsgQIng", acSemKey));
		DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok() lSemKey =%08lx\n", "os_MsgQIng", lSemKey));

		if (-1 == lSemKey)
		{
			return(-1);								/* 異常終了									*/
		}

		/****************************************/
		/*  セマフォＩＤを取得					*/
		/****************************************/
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMGET, 1, lSemKey );
		lSemId = semget(lSemKey, 1, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lSemId, errno );
		
		if (-1 == lSemId)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
					"os_MsgQIng", "semget() Call Error!!", errno, strerror(errno)));

			return(-1);								/* 異常終了									*/
		} 

		ptEmbc->lSemId = lSemId;					/* メイルボックス管理テーブルに				*/
													/* セマフォＩＤを設定						*/

    	DbgMsg01(DLv04, (OutPut, "***** %s:lSemId=%d, ptEmbc->lSemId=%d \n",
    			 "os_MsgQIng", lSemId, ptEmbc->lSemId));

		/****************************************/
		/*  セマフォ初期処理                    */
		/****************************************/
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMCTL, 4, lSemId, 0, SETVAL, 1 );
    	if ((-1) == semctl(lSemId, 0, SETVAL, 1))	/* このプロセスのセマフォがシステムで       */
                                                    /* 最初のものであったとき、セマフォ番号     */
													/* ０番に”１”の値をセットする             */
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s \n", "os_MsgQIng",
							"★★★★ Cannot set Semaphore-value."));
    	}
    	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 1, errno );
    }
	else
	{
		lSemId = ptEmbc->lSemId;					/* セマフォＩＤを設定 						*/

    	DbgMsg01(DLv04, (OutPut, "***** %s:lSemId=%d, ptEmbc->lSemId=%d \n",
    			 "os_MsgQIng", lSemId, ptEmbc->lSemId));
	}

	/************************************/
	/*  メッセージタイプによる振分け	*/
	/************************************/
	switch (lMsgType)								/* メッセージタイプで振り分け				*/
	{
		case	D_MTYPE05:							/* メッセージの受信要求（メイルボックス宛）	*/
		case	D_MTYPE06:							/* メッセージの受信要求（プロセス宛）		*/
			/********************************/
			/*  共有メモリサイズの算出		*/
			/********************************/
			/*  メッセージ管理部サイズ ＋ 受信ヘッダサイズ + 受信データサイズ		*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TMsgHed) + ptMsg->lDataSize;
			break;

		case	D_MTYPE07:							/* プールバッファ上のメッセージの			*/
													/* 受信要求(メイルボックス宛)				*/
		case	D_MTYPE08:							/* プールバッファ上のメッセージの			*/
													/* 受信要求(プロセス宛)						*/
			/********************************/
			/*  共有メモリサイズの算出		*/
			/********************************/
			/*  メッセージ管理部サイズ ＋ 受信ヘッダサイズ							*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TMsgHed);
			break;

		case	D_MTYPE25:							/* DCSメッセージの受信要求					*/
			/********************************/
			/*  共有メモリサイズの算出		*/
			/********************************/
			/* メッセージ管理部サイズ ＋ 受信ヘッダサイズ + メッセージ受信サイズ	*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TDcsMsgHed) + lMsgSize;
			break;

		default		:								/* 何もしない								*/
			break;
	}

	/****************************************/
	/* 共有メモリIDの取得  20030406追加修正 */
	/****************************************/
	lRet = os_Sem(lCmSize);
	if(D_ERR_SYS == lRet)
	{
		return(-1);
	}
	
	lShmId = lRet;

	/****************************************/
	/*  共有メモリのアタッチ				*/
	/****************************************/
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SHMAT, 3, lShmId, 0, 0);
	pcCmptr = (char *)shmat(lShmId, 0, 0);			/* 共有メモリのアッタチ						*/
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, pcCmptr, errno);
	
	if (D_ERR_SYS == pcCmptr)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ERRNO:%08x  %s \n",
				"os_MsgQIng", "shmat() Call Error!!", lShmId, errno, strerror(errno)));
		return(-1);									/* 異常終了									*/
	}

	ptCmMsgInfo = (TMsgInfo *)pcCmptr;				/* 共有メモリ用メッセージ情報ポインタ設定	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:pcCmptr=%08x, lCmSize=%d \n",
			"os_MsgQIng", pcCmptr, lCmSize));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsgInfo=%08x \n", "os_MsgQIng", ptCmMsgInfo));

   	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lShmKey=%08x\n", "os_MsgQIng", ptEmbc->lShmKey));

	/********************************************/
	/*  メッセージタイプ毎にメッセージを設定    */
	/********************************************/
	switch (lMsgType)								/* メッセージタイプで振り分け				*/
	{
		case	D_MTYPE05:							/* メッセージの受信要求（メイルボックス宛）	*/
		case	D_MTYPE06:							/* メッセージの受信要求（プロセス宛）		*/

			ptCmMsg = (TMsgHed *)(ptCmMsgInfo + 1); /* 共有メモリメッセージポインタ設定			*/

			ptCmMsg->lMsgType = ptMsg->lMsgType;	/* メッセージタイプを設定					*/

			ptCmMsg->pcPlBuf = ptMsg->pcPlBuf;		/* プールバッファアドレスを設定				*/

			ptCmMsg->lDataSize = ptMsg->lDataSize;  /* データサイズを設定						*/

													/* 受信メッセージをメッセージ領域にコピー	*/
			memcpy((ptCmMsg + 1), (ptMsg + 1), ptMsg->lDataSize);

			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg=%08x\n", "os_MsgQIng", ptCmMsg));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lMsgType=%02x\n",
					"os_MsgQIng", ptCmMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->pcPlBuf=%08x\n",
					"os_MsgQIng", ptCmMsg->pcPlBuf));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lDataSize=%d\n",
					"os_MsgQIng", ptCmMsg->lDataSize));
			break;

		case	D_MTYPE07:							/* プールバッファ上のメッセージの			*/
													/* 受信要求(メイルボックス宛)				*/
		case	D_MTYPE08:							/* プールバッファ上のメッセージの			*/
													/* 受信要求(プロセス宛)						*/

			ptCmMsg = (TMsgHed *)(ptCmMsgInfo + 1); /* 共有メモリメッセージポインタ設定			*/

			ptCmMsg->lMsgType = ptMsg->lMsgType;	/* メッセージタイプを設定					*/

			ptCmMsg->pcPlBuf = ptMsg->pcPlBuf;		/* プールバッファアドレスを設定				*/

			ptCmMsg->lDataSize = ptMsg->lDataSize;  /* データサイズを設定						*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg=%08x\n", "os_MsgQIng", ptCmMsg));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lMsgType=%02x\n",
					"os_MsgQIng", ptCmMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->pcPlBuf=%08x\n",
					"os_MsgQIng", ptCmMsg->pcPlBuf));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lDataSize=%d\n",
					"os_MsgQIng", ptCmMsg->lDataSize));
			break;

		case	D_MTYPE25:							/* DCSメッセージの受信要求					*/

													/* 共有メモリＤＣＳメッセージポインタ設定	*/
			ptCmDcsMsg = (TDcsMsgHed *)(ptCmMsgInfo + 1);

			ptCmDcsMsg->lMsgType = lMsgType;		/* メッセージタイプを設定					*/

			ptCmDcsMsg->lDataSize = lMsgSize;		/* メッセージ受信サイズを設定				*/

													/* 受信メッセージをメッセージ領域にコピー	*/
			memcpy((ptCmDcsMsg + 1), ptMsg, lMsgSize);
			break;

		default		:								/* 何もしない								*/
			break;
	}

	if (0 == ptSubMsgQ->lMsgCnt)					/* メッセージ格納数が「0」の場合			*/
	{
		/********************************************/
		/*  受信メッセージ（管理部）の設定          */
		/********************************************/
		ptCmMsgInfo->ptBefAdr = (void *)ptSubMsgQ;	/* 受信メッセージ（取得した共有メモリ）の	*/
													/* 前アドレスにサブメッセージの先頭アドレス */
													/* を設定									*/
													/* メッセージサイズ（ヘッダ＋メッセージ）	*/
		ptCmMsgInfo->lMsgSize = lCmSize - sizeof(TMsgInfo);
													/* メッセージアドレスを設定					*/
		ptCmMsgInfo->pvMsgAdr = (void *)(ptCmMsgInfo + 1);	

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->lMsgSize=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->lMsgSize));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->pvMsgAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->pvMsgAdr));


		/********************************************/
		/*  サブメッセージキューの設定				*/
		/********************************************/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt + 1;/* サブメッセージの							*/
													/* メッセージ格納数をカウントアップ			*/

		ptSubMsgQ->lShmId = lShmId;					/* サブメッセージの共有メモリＩＤに			*/
													/* 取得した共有メモリＩＤを設定				*/

		ptSubMsgQ->ptNxtAdr = (TMsgInfo *)pcCmptr;	/* サブメッセージの次アドレスに				*/
													/* 取得した共有メモリアドレスを設定			*/
		
		ptSubMsgQ->ptBefAdr = (TMsgInfo *)pcCmptr;	/* サブメッセージの前アドレスに				*/
													/* 取得した共有メモリアドレスを設定			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->lMsgCnt=%d, ptSubMsgQ->lShmId=%d \n",
    			"os_MsgQIng", ptSubMsgQ->lMsgCnt, ptSubMsgQ->lShmId));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptNxtAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptNxtAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptBefAdr));
	}
	else											/* 上記以外（1以上）の場合					*/
	{
		/********************************************/
		/*  受信メッセージ（管理部）の設定          */
		/********************************************/
													/* サブメッセージの前アドレスを				*/
													/* 受信メッセージ（取得した共有メモリ）の	*/
													/* 前アドレスに設定							*/
		ptCmMsgInfo->ptBefAdr = (void *)ptSubMsgQ->ptBefAdr;	
													/* メッセージサイズ（ヘッダ＋メッセージ）	*/
		ptCmMsgInfo->lMsgSize = lCmSize - sizeof(TMsgInfo);
													/* メッセージアドレスを設定					*/
		ptCmMsgInfo->pvMsgAdr = (void *)(ptCmMsgInfo + 1);	

		ptMsgBef = ptSubMsgQ->ptBefAdr;				/* 更新前のサブメッセージの前アドレスを設定 */
		ptMsgBef->ptNxtAdr = (void *)pcCmptr;		/* （更新前）受信メッセージの次アドレスに	*/
													/* 取得した共有メモリアドレスを設定			*/
		ptMsgBef->lShmId = lShmId;					/* （更新前）受信メッセージの共有メモリＩＤ	*/
													/* に取得した共有メモリＩＤを設定			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->lMsgSize=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->lMsgSize));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->pvMsgAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->pvMsgAdr));

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptMsgBef=%08x, ptMsgBef->ptNxtAdr=%08x \n",
    			"os_MsgQIng", ptMsgBef, ptMsgBef->ptNxtAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptMsgBef->lShmId=%08x \n",
    			"os_MsgQIng", ptMsgBef->lShmId));


		/********************************************/
		/*  サブメッセージキューの設定				*/
		/********************************************/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt + 1;/* サブメッセージの							*/
													/* メッセージ格納数をカウントアップ			*/

		ptSubMsgQ->ptBefAdr = (TMsgInfo *)pcCmptr;	/* サブメッセージの前アドレスに				*/
													/* 取得した共有メモリアドレスを設定			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->lMsgCnt=%d \n",
    			"os_MsgQIng", ptSubMsgQ->lMsgCnt));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptBefAdr));
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_MsgQIng" ) );
	os_trcget2( D_MD_OS_MSGQING, D_T_TRA_OUT, 0 );

	return (NORMAL);								/* 正常終了									*/
}


/********************************************/
/*	共有メモリ取得関数						*/
/********************************************/
long os_Sem(long lCmSize)
{
	long lRes = 0;
	long lShmId = 0;
	long lFlg = 0;
	short sShmKey = 0;
	
	DbgMsg01(DLv04, (OutPut, "***** %s: Start os_Sem\n", "os_MsgQIng os_Sem" ));
	/****************************************/
	/*  セマフォロック						*/
	/****************************************/
	lRes = os_SemLock(0);
	if(NORMAL != lRes)
	{
		return(lRes);
	}

	/****************************************/
	/*  共有メモリ取得操作					*/
	/****************************************/
	// ここで処理失敗しても返さずセマフォ解除してから抜ける
	sShmKey = (short)(ptEmbc->lShmKey & 0x0000ffff);
	
	do
	{
		lFlg = 0;
		lRes = os_Shmget( &sShmKey, lCmSize );
		sShmKey++;
		
		if( ( (ptEmbc->lShmKey & 0x0000ffff) != ( (long)sShmKey & 0x0000ffff) ) &&
			( D_ERR_SYS == lRes ) )
		{
			lFlg = 1;
		}
	}while(lFlg);

													// メモリボックス管理テーブル管理情報の
													// 「共有メモリ識別子」をカウントアップ
	ptEmbc->lShmKey = (ptEmbc->lShmKey & 0xffff0000) | ( (long)sShmKey & 0x0000ffff);
	lShmId = lRes;
	
	/****************************************/
	/*  セマフォロック解除					*/
	/****************************************/
	lRes = os_SemLock(1);
	if(NORMAL != lRes)
	{
		return(lRes);
	}

	if(D_ERR_SYS == lShmId)
	{
		return(-1);
	}

	DbgMsg01(DLv04, (OutPut, "***** %s: End os_Sem\n", "os_MsgQIng os_Sem" ));
	return(lShmId);
}

/********************************************/
/*	セマフォ操作							*/
/********************************************/
long os_SemLock(long lFlg)
{
// lFlg 0ならセマフォロック
// lFlg 1ならロック解除

	struct sembuf tSem;
	long lRet = 0;
	long lSemId = 0;
	
	/****************************************/
	/*  セマフォ開始						*/
	/****************************************/
	lSemId = ptEmbc->lSemId;
													// 状態設定
	tSem.sem_num = (unsigned short)0;
/*****	故障管理番号TBCS0234の対応		Start							修正日：2003.07.22	*****/
/************************************************************************************************/
/*	sem_flgの設定を「SEM_UNDO」に変更															*/
/************************************************************************************************/
	tSem.sem_flg = SEM_UNDO;						// セマフォの操作フラグ設定
/*****	故障管理番号TBCS0234の対応		 End							修正日：2003.07.22	*****/

	if(0 == lFlg)
	{	// セマフォロック
		tSem.sem_op  = (short)(-1);
	}
	else
	{	// セマフォロック解除
		tSem.sem_op  = (short)(1);
	}

	while (1)
	{
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMOP, 3, lSemId, &tSem, 1 );
		lRet = semop(lSemId, &tSem, 1);
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lRet, errno );

		if (D_ERR_SYS == lRet)
		{
			if (EINTR == errno)
			{										// 割り込み発生時リトライ
				continue;
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:Err:%08lx %s\n",
									"os_MsgQing", errno, strerror(errno)));
				return(-1);
			}
		}
		break;
	}
	return(NORMAL);
}

/********************************************/
/*	共有メモリID取得						*/
/********************************************/
long os_Shmget(short* spShmKey, long lCmSize)
{
	long lRet = 0;
	long lWorkShmKey = 0;							// SG取得共有メモリ識別子
	long lNtokShmKey = 0;
	long lShmKey = 0;
	long lShmId = 0;								// 共有メモリID格納用
	char acShmKey[16];								// ShmKey格納域（Ntok用）
	
	DbgMsg01(DLv04, (OutPut, "***** %s: Start os_Shmget\n", "os_MsgQIng os_Shmget" ));
	DbgMsg01(DLv04, (OutPut, "***** %s:sShmKey:%x \n", "os_MsgQIng os_Shmget", *spShmKey ));
	DbgMsg01(DLv04, (OutPut, "***** %s:lCmSize:%ld\n", "os_MsgQIng os_Shmget", lCmSize ));
	/********************************************/
	/*  メイルボックス管理テーブル管理情報の    */
	/*  「共有メモリ識別子」のチェック			*/
	/********************************************/
	memset(acShmKey, 0, sizeof(acShmKey) );
	
	if (0 == *spShmKey)								// 共有メモリ識別子が「0」の場合
	{
													// ＳＧから取得
		lRet = os_getSG(D_SG_EMBC_SHM_KEY, &lWorkShmKey);
		if (NORMAL != lRet)
		{
			return(-1);								// 異常終了
		}
		
		if(0 == ptEmbc->lShmKey)
		{
			ptEmbc->lShmKey = lWorkShmKey;			// 共有メモリ識別子を設定
		}

		// ここで引数にマスクしてもダメ
		*spShmKey = (short)( lWorkShmKey & 0x0000ffff);
		DbgMsg01(DLv04, (OutPut, "***** %s:sShmKey:%x\n", "os_MsgQIng", *spShmKey ));
		lNtokShmKey = ptEmbc->lShmKey;
	}
	lNtokShmKey = (ptEmbc->lShmKey & 0xffff0000) | ( (long)*spShmKey & 0x0000ffff);

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lShmKey:%08lx\n", "os_MsgQIng", ptEmbc->lShmKey ));
	DbgMsg01(DLv04, (OutPut, "***** %s:lNtokShmKey:%08lx\n", "os_MsgQIng", lNtokShmKey));
	/********************************************/
	/*  ntok関数コール    						*/
	/********************************************/
													// 共有メモリ識別子を文字列に変換
	sprintf(acShmKey, "%08lx", lNtokShmKey);

	lShmKey = BlpMpf_ntok(acShmKey, D_NTOK_ID);		// 富士通提供関数(ntok)を発行
	DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok acShmKey=%s \n", "os_MsgQIng", acShmKey));
	DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok lShmKey =%08lx \n", "os_MsgQIng", lShmKey));

	if (-1 == lShmKey)
	{
		return(-1);									// 異常終了
	}
	
	/****************************************/
	/*  共有メモリの確保					*/
	/****************************************/
													//  共有メモリ確保
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SHMGET, 2, lShmKey, lCmSize );
	lShmId = shmget(lShmKey, lCmSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lShmId, errno);

	if (-1 == lShmId)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:ERRNO:%08x %s\n",
				"os_MsgQIng", errno, strerror(errno)));
		return(-1);
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lShmKey=%08x, lShmId=%d \n",
			"os_MsgQIng", lShmKey, lShmId));
	return(lShmId);
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
