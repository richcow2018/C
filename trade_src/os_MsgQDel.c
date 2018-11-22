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
/* ＜モジュールＩＤ＞				 os_MsgQDel													*/
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
/*	 指定されたサブメッセージキューのデータを削除する。											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_MsgQDel.h>																*/
/*																								*/
/*	   	long	os_MsgQDel(TSubMsgQ ptSubMsgQ,TMsgInfo ptMsgInfo)								*/
/*																								*/
/* ＜仮引数＞																					*/
/*		TSubMsgQ    ptSubMsgQ;		 サブメッセージキュー管理情報								*/
/*		TMsgInfo	ptmsgInfo;		 受信メッセージ情報											*/
/*																								*/
/* ＜返却値＞																					*/
/*	   正常終了		NORMAL																		*/
/*	   異常終了		-1																			*/
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
#include	"os_MsgQDel_ins.h"


long	os_MsgQDel(ptSubMsgQ, ptMsgInfo)
TSubMsgQ    *ptSubMsgQ;								/* サブメッセージキュー管理情報				*/
TMsgInfo    *ptMsgInfo;								/* 受信メッセージ情報 						*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lShmId;							/* 共有メモリＩＤ							*/
	long			lRet;							/* 返却値									*/
	TMsgInfo		*tMsgNxt = NULL;				/* 受信メッセージ（一つ先）のポインタ		*/
	TMsgInfo		*tMsgBef = NULL;				/* 受信メッセージ（一つ前）のポインタ		*/


	os_trcget2( D_MD_OS_MSGQDEL, D_T_TRA_IN, 2, ptSubMsgQ, ptMsgInfo );
													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MsgQDel" ) );


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lShmId = 0;
	lRet = 0;
	errno = 0;

	tMsgNxt = (TMsgInfo *)ptMsgInfo->ptNxtAdr;		/* 受信メッセージ（一つ先）のポインタ設定	*/
	tMsgBef = (TMsgInfo *)ptMsgInfo->ptBefAdr;		/* 受信メッセージ（一つ前）のポインタ設定	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ = %08x \n", "os_MsgQDel", ptSubMsgQ));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgInfo = %08x \n", "os_MsgQDel", ptMsgInfo));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/********************************************/
	/*  引数の情報により削除処理の振分けをする  */
	/********************************************/
	if (ptSubMsgQ->ptNxtAdr == ptSubMsgQ->ptBefAdr)	/* 削除対象の受信メッセージが1個だけの場合	*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "削除対象の受信メッセージが1個だけの場合"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt  = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId   = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lShmId));

		ptSubMsgQ->ptNxtAdr = NULL;					/* サブメッセージの次アドレスにNULLを設定	*/
		ptSubMsgQ->ptBefAdr = NULL;					/* サブメッセージの前アドレスにNULLを設定	*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* サブメッセージのメッセージ格納数 -1		*/
		lShmId = ptSubMsgQ->lShmId;					/* 削除対象となる共有メモリＩＤを設定		*/
		ptSubMsgQ->lShmId = 0;						/* サブメッセージの共有メモリＩＤをクリア	*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt  = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId   = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lShmId));
	}
	else if (ptSubMsgQ->ptNxtAdr == ptMsgInfo)		/* 削除対象の受信メッセージが先頭の場合		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "削除対象の受信メッセージが先頭の場合"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgNxt->ptBefAdr  =%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", tMsgNxt->ptBefAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId  =%d, ptMsgInfo->lShmId    =%d \n",
				"os_MsgQDel", ptSubMsgQ->lShmId, ptMsgInfo->lShmId));

													/* サブメッセージの次アドレスに				*/
													/* 受信メッセージの次アドレスを設定         */
		ptSubMsgQ->ptNxtAdr = (TMsgInfo *)ptMsgInfo->ptNxtAdr;
		tMsgNxt->ptBefAdr = ptMsgInfo->ptNxtAdr;	/* 受信メッセージの一つ先の前アドレスに		*/
													/* 受信メッセージの次アドレスを設定			*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* サブメッセージのメッセージ格納数 -1		*/
		lShmId = ptSubMsgQ->lShmId;					/* 削除対象となる共有メモリＩＤを設定		*/
		ptSubMsgQ->lShmId = ptMsgInfo->lShmId;		/* 受信メッセージの共有メモリＩＤを			*/
													/* サブメッセージキューに設定				*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgNxt->ptBefAdr  =%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", tMsgNxt->ptBefAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId  =%d, ptMsgInfo->lShmId    =%d \n",
				"os_MsgQDel", ptSubMsgQ->lShmId, ptMsgInfo->lShmId));
	}
	else if (ptSubMsgQ->ptBefAdr == ptMsgInfo)		/* 削除対象の受信メッセージが最後の場合		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "削除対象の受信メッセージが最後の場合"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->ptNxtAdr  =%08x \n",
				"os_MsgQDel", tMsgBef->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));

													/* サブメッセージの前アドレスに				*/
													/* 受信メッセージの前アドレスを設定         */
		ptSubMsgQ->ptBefAdr = (TMsgInfo *)ptMsgInfo->ptBefAdr;
		tMsgBef->ptNxtAdr = NULL;					/* 受信メッセージの一つ先の前アドレスに		*/
													/* NULLを設定								*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* サブメッセージのメッセージ格納数 -1		*/
		lShmId = tMsgBef->lShmId;					/* 削除対象となる共有メモリＩＤを設定		*/
		tMsgBef->lShmId = 0;						/* 受信メッセージの一つ前の共有メモリＩＤ	*/
													/* をクリア									*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->ptNxtAdr  =%08x \n",
				"os_MsgQDel", tMsgBef->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));
	}
	else											/* 削除対象の受信メッセージが途中の場合		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "削除対象の受信メッセージが途中の場合"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));

		tMsgBef->ptNxtAdr = ptMsgInfo->ptNxtAdr;	/* 受信メッセージの一つ先の前アドレスに		*/
													/* 受信メッセージの次アドレスを設定			*/
		tMsgNxt->ptBefAdr = ptMsgInfo->ptBefAdr;	/* 受信メッセージの一つ先の前アドレスに		*/
													/* 受信メッセージの前アドレスを設定			*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* サブメッセージのメッセージ格納数 -1		*/
		lShmId = tMsgBef->lShmId;					/* 削除対象となる共有メモリＩＤを設定		*/
		tMsgBef->lShmId = ptMsgInfo->lShmId;		/* 受信メッセージの一つ前の共有メモリＩＤに */
													/* 受信メッセージの共有メモリＩＤを設定		*/

		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "削除対象の受信メッセージが途中の場合"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));
	}


	/********************************************/
	/*  共有メモリのデタッチ					*/
	/********************************************/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_SHMDT, 1, ptMsgInfo );
	lRet = shmdt(ptMsgInfo);						/* 共有メモリのデッタチ						*/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_END, 2, lRet, errno );

	if (-1 == lRet)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ptr=%08x, ERRNO:%08x  %s \n",
			"os_MsgQDel", "shmdt() Call Error!!", lShmId, ptMsgInfo, errno, strerror(errno)));
		return(-1);									/* 異常終了									*/
	}


	/********************************************/
	/*  共有メモリの削除  						*/
	/********************************************/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_SHMCTL, 1, ptMsgInfo );
	lRet = shmctl(lShmId, IPC_RMID, 0);				/* 共有メモリ削除							*/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_END, 2, lRet, errno );
	
	if (-1 == lRet)
	{
													/* 障害発生									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ERRNO:%08x  %s \n",
				"os_MsgQDel", "shmctl() Call Error!!", lShmId, errno, strerror(errno)));
		return(-1);								/* 異常終了									*/
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_MsgQDel" ) );
	os_trcget2( D_MD_OS_MSGQDEL, D_T_TRA_OUT, 0 );

	return (NORMAL);								/* 正常終了									*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
