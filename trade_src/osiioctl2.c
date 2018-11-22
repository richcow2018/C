/************************************************************************************************/
/*	著作権	２００２																			*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム	ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 ＴＣＰ/ＩＰ制御											*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 TCP/IPコネクションの制御・監視（非完了型）					*/
/* ＜モジュールＩＤ＞				 osiioctl2													*/
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
/* ＜開発担当名＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜電話番号＞ 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞ 					 ＣＢ事ビジネス企画担当										*/
/* ＜設計年月日＞					 ２００２年０９月２７日 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年１１月１８日 									*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年０７月０８日		故障管理番号（ＴＢＣＳ０２０５）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		指定された特殊ファイルに対して以下の処理を行う。										*/
/*			(1) 非同期通知要求																	*/
/*			(2) ACCEPT																			*/
/*			(3) DETACH																			*/
/*			(4) CONNECT																			*/
/*			(5) DISCONNECT																		*/
/*			(6) ABORT																			*/
/*			(7) ATTACH																			*/
/*			(8) BIND																			*/
/*			(9) LISTEN																			*/
/*			(10) NETCTL																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osiioctl2.h>																*/
/*																								*/
/*		long	osiioctl2(long rd, long fildes, long request, char *arg, long argsiz)			*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		rd				リクエスト識別子											*/
/*		long		fildes			ファイルディスクリプタ										*/
/*		long		request			制御種別													*/
/*										(1) 非同期通知要求	：0x00gcf000						*/
/*										(2) ACCEPT			：0x006cf105						*/
/*										(3) DETACH			：0x006c7101						*/
/*										(4) CONNECT			：0x006c7103						*/
/*										(5) DISCONNECT		：0x006c7106						*/
/*										(6) ABORT			：0x006c710a						*/
/*										(7) ATTACH			：0x006c7100						*/
/*										(8) BIND			：0x006c7102						*/
/*										(9) LISTEN			：0x006c7103						*/
/*										(10) NETCTL			：0x006cf150						*/
/*		char		*arg			引数域ポインタ												*/
/*		long		argsiz			引数域サイズ（０以上）										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		リクエスト識別子														*/
/*		異常終了		OSEEIVRD		リクエスト識別子異常または予約状態が未予約ではない。	*/
/*						OSEEOVRQ		リクエスト識別子検索異常								*/
/*						OSEEUSED		リクエスト識別子が使用済みである。						*/
/*						OSFEFILDES		コネクション管理テーブル異常							*/
/*						0xECF10001		引数域サイズ異常										*/
/*						0xECB00016		論理誤り。												*/
/*						0xECB00140		コネクションが未設定									*/
/*						0xECB00154		スレッド異常											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		特になし 																				*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <linux/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ipc.h>
#include <sys/msg.h>
/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "osiioctl2.h"
#include "osiioctl2_ins.h"              			// 内部参照用（個別）
#include "os_tcpex.h"                   			// os_tcpex用

/****************************************************************************/
/* 機能：TCP/IPコネクションの制御・監視（非完了型）                         */
/* 作成日：2002年11月18日                                                   */
/* 変更日：2002年11月18日                                                   */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long osiioctl2( long rd, long fildes, long request,                    */
/*                   char *arg, long argsiz )                               */
/*     long rd                リクエスト識別子                              */
/*     long fildes            ファイルディスクリプタ                        */
/*     long request           制御種別                                      */
/*                                (1) 非同期通知要求：0x006CF000            */
/*                                (2) ACCEPT        ：0x006CF105            */
/*                                (3) DETACH        ：0x006C7101            */
/*                                (4) CONNECT       ：0x006C7104            */
/*                                (5) DISCONNECT    ：0x006C7106            */
/*                                (6) ABORT         ：0x006C710A            */
/*                                (7) ATTACH        ：0x006CF100            */
/*                                (8) BIND          ：0x006C7102            */
/*                                (9) LISTEN        ：0x006C7103            */
/*                                (10) NETCTL       ：0x006CF150            */
/*     char *arg              アーギュメント域へのポインタ                  */
/*     long argsiz            アーギュメント域のサイズ                      */
/*                                                                          */
/****************************************************************************/
long osiioctl2( long rd, long fildes, long request, char *arg, long argsiz )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    struct linger tLinger;              			// linger構造体
    struct sockaddr_in tSockAddr_In;    			// sockaddr_in構造体
    TMyMessage tMsgBuf;                 			// メッセージバッファ構造体
	/*****	仕様変更（SSLA0012）Start				修正日：2003.02.25	*****/
    int iOpt;										// setsockoptで指定するオプション
	/*****	仕様変更（SSLA0012） End				修正日：2003.02.25	*****/
    int iLoopCnt;                       			// ループカウンタ
    int iRet;                           			// 返却値
    long lRet;                          			// 返却値
    TErdcTableInd *ptRdIndTopAdr;       			// rd管理テーブル個別部の先頭アドレス
    TErdcTableInd *ptRdIndAdr;          			// rd管理テーブル個別部のアドレス
    TEcncTableInd *ptEcncIndAdr;        			// コネクション管理テーブル個別部のアドレス
    TArgSyncInfoReq *ptArgSyncInfoReq;  			// アーギュメント（非同期通知要求）
    TArgAccept *ptArgAccept;            			// アーギュメント（ACCEPT）
    TArgDetach *ptArgDetach;            			// アーギュメント（DETACH）
    TArgConnect *ptArgConnect;          			// アーギュメント（CONNECT）
    TArgDisconnect *ptArgDisconnect;    			// アーギュメント（DISCONNECT）
    TArgAbort *ptArgAbort;              			// アーギュメント（ABORT）
    TArgAttach *ptArgAttach;            			// アーギュメント（ATTACH）
    TArgBind *ptArgBind;                			// アーギュメント（BIND）
    TArgListen *ptArgListen;            			// アーギュメント（LISTEN）
    TArgThread *ptArgThread;            			// スレッド用アーギュメント
    TArgInfo tArgInfo;                  			// 要求情報用アーギュメント
    pthread_t thId;                     			// スレッドID
    void *pvBuf;                        			// 書込み用バッファ
    size_t stCount;                     			// 書込みバイト数
    ssize_t sstRet;                     			// 書き込まれたバイト数
    size_t stMsgSz;                     			// 送信用メッセージサイズ


	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_IN, 5, rd, fildes, request, arg, argsiz );

    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	コネクション管理テーブルの確認				*/
	/************************************************/
    if( ptEcnc == NULL )                			// コネクション管理テーブルが未作成の時
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSFEFILDES );
        return( OSFEFILDES );						// OSFEFILDESを返却
    }

    /************************************************/
	/*	rd管理テーブルの検索						*/
	/************************************************/
    ptRdIndTopAdr = (TErdcTableInd *)(ptErdc + 1);	// rd管理テーブル個別部の先頭アドレス取得

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndTopAdr=%p )\n",
													D_PROC_NAME, ptRdIndTopAdr ) );

    if( D_RD_NONE == rd )               			// リクエスト識別子がなしの時
    {
													// rd管理テーブル個別部先頭からリクエスト状態
													// が未予約かつ未使用かつ未要求の個別部を検索
        for( iLoopCnt = 0; iLoopCnt < ptMyEPRC->lMaxReqNum; iLoopCnt++ )
        {
			ptRdIndAdr = ptRdIndTopAdr + iLoopCnt;	// 個別部の先頭アドレス取得

													// 予約状態が予約未の時
//			if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
													// リクエスト状態が
													// 未予約かつ未使用かつ未要求の場合
			if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptRdIndAdr->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptRdIndAdr->tReqStat.cUCompStat )
            {
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
																D_PROC_NAME, ptRdIndAdr ) );
                break;								// 処理を抜ける
            }
        }

        if( iLoopCnt == ptMyEPRC->lMaxReqNum )		// 予約未が見つからなかった時
        {                               
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    															D_PROC_NAME, OSEEOVRQ ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEOVRQ );
            return( OSEEOVRQ );						// OSEEOVRQを返却
        }
    }
													// リクエスト識別子が最小値から個別部数の間の時
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {                                   
        ptRdIndAdr = ptRdIndTopAdr + ( rd - 1 );	// 指定個別部のアドレス取得

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// 予約状態が予約未の時
        if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
        {                               
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    															D_PROC_NAME, OSEEIVRD ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEIVRD );
            return( OSEEIVRD );						// OSEEIVRDを返却
        }

													// 非完了要求状態が要求済の時
        if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
        {
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
																D_PROC_NAME, OSEEUSED ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEUSED );
			return( OSEEUSED );						// OSEEUSEDを返却
        }
    }
    else											// リクエスト識別子がその他の時
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEIVRD );
        return( OSEEIVRD );							// OSEEIVRDを返却
    }


/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	/********************************************/
	/*  rd管理テーブル対象個別部の編集			*/
	/********************************************/
													// 非完了要求状に「要求済」を設定
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
													// 要求種別に「osiioctl2完了通知」を設定
	ptRdIndAdr->cReqClass           = D_ERDC_REQCLASS22;
													// リクエスト番号にマスタリクエスト番号を設定
	ptRdIndAdr->lReqNum             = ptErdc->ulMstReqNum++;
													// プロセス識別子に自プロセス識別子を設定
	ptRdIndAdr->lPCode              = ptMyEPRC->lPCode;
	ptRdIndAdr->pvArg1              = arg;			// 引数領域１にアーギュメント域ポインタを設定
	(long)(ptRdIndAdr->pvArg2)      = argsiz;		// 引数領域２にアーギュメント域サイズを設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%hhd )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=%hhd )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lPCode ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->pvArg1=%p )\n",
												D_PROC_NAME, ptRdIndAdr->pvArg1 ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->pvArg2=%ld )\n",
												D_PROC_NAME, (long)(ptRdIndAdr->pvArg2) ) );

    switch( request )								// 制御種別による処理の振り分け
    {
		case D_TASSO_SYNCINFOREQ:					// 制御種別が非同期通知要求の時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( 非同期通知要求 )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgSyncInfoReq) ) // アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}
													// アーギュメント域ポインタのアドレス設定
			ptArgSyncInfoReq = (TArgSyncInfoReq *)arg;

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgSyncInfoReq->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgSyncInfoReq->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgSyncInfoReq->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgSyncInfoReq->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;     			// D_ERR_LOGICを設定
//				goto err_iioctl2;       			// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/********************************************/
			/*  コネクション管理テーブル対象個別部編集	*/
			/********************************************/
                                        			// コネクション管理テーブルの対象個別部の取得
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgSyncInfoReq->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_ON;
			ptEcncIndAdr->tAsyncInfo.lReqId = ptRdIndAdr->lRCode;
			ptEcncIndAdr->tAsyncInfo.lReqNum = ptRdIndAdr->lReqNum;
			ptEcncIndAdr->tAsyncInfo.pcPara1 = ptRdIndAdr->pvArg1;
			ptEcncIndAdr->tAsyncInfo.lPara2 = (long)ptRdIndAdr->pvArg2;

    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->cAsyncFlg=%hhd )\n",
												D_PROC_NAME, ptEcncIndAdr->cAsyncFlg));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lReqId=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lReqId));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lReqNum=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lReqNum));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.pcPara1=%p )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.pcPara1));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lPara2=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lPara2));

			switch( ptEcncIndAdr->cSCFlg )			// S/C状態によって処理を振り分ける
			{
				case D_SCINFO_SERVER:   			// サーバの場合
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( サーバー )\n",
																		D_PROC_NAME ) );
																		
					/********************************/
					/*	スレッド引数領域の確保		*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MALLOC, 1, sizeof(TArgThread) );
													// スレッド用アーギュメント領域の確保
					ptArgThread = malloc( sizeof(TArgThread) );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, ptArgThread );

					if( ptArgThread == NULL )		// 確保できなかった時
					{
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "malloc", strerror(errno)));
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//						lRet = D_ERR_NOBUF;			// D_ERR_NOBUFを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「アーギュメント不正」を設定
						tMsgBuf.lResult = D_ERR_NOBUF;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
					}

					/********************************************/
					/*  スレッド用アーギュメントの設定			*/
					/********************************************/
					ptArgThread->lSockDes     = ptEcncIndAdr->lSockDes;
					ptArgThread->cReqClass    = D_REQCLASS_ASYNC;
					ptArgThread->lRCode       = ptRdIndAdr->lRCode;
					ptArgThread->ulReqNum     = ptRdIndAdr->lReqNum;
					ptArgThread->pvArg1       = arg;
					(long)ptArgThread->pvArg2 = argsiz;

					DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptArgThread->lSockDes=%ld )\n",
														D_PROC_NAME, ptArgThread->lSockDes ) );
					DbgMsg01(DLv04, (OutPut, "***** %s: Display ( ptArgThread->cReqClass=%hhd )\n",
														D_PROC_NAME, ptArgThread->cReqClass ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lRCode=%ld )\n",
														D_PROC_NAME, ptArgThread->lRCode ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->ulReqNum=%ld )\n",
														D_PROC_NAME, ptArgThread->ulReqNum ) );
    				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg1=%p )\n",
														D_PROC_NAME, ptArgThread->pvArg1 ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg2=%ld )\n",
														D_PROC_NAME, (long)ptArgThread->pvArg2 ) );

					/********************************/
					/*	スレッドの作成				*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_CREATE, 4, 
														&thId, NULL, os_tcpex, ptArgThread );
													// スレッドの作成
					iRet = pthread_create( &thId, NULL, os_tcpex, ptArgThread );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
					
					if( iRet != NORMAL )			// スレッドの作成に失敗した時
					{
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "pthread_create", strerror(errno)));

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGICを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「論理誤り」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
					}

					/********************************/
					/*	スレッドの分離				*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_DETACH, 1, thId );
					pthread_detach( thId );			// スレッドのデタッチ
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 0 );

					lRet = ptRdIndAdr->lRCode;		// 返却値としてリクエスト識別子を設定する
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
																D_PROC_NAME, lRet ) );
					break;

				case D_SCINFO_CLIENT:   			// クライアントの場合
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( クライアント )\n",
																		D_PROC_NAME ) );

					lRet = ptRdIndAdr->lRCode;		// 返却値としてリクエスト識別子を設定する
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
																	D_PROC_NAME, lRet ) );
                    break;

				default:
    				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//					lRet = D_ERR_LOGIC;				// D_ERR_LOGICを設定
//					goto err_iioctl2;				// エラー処理へ遷移
					tMsgBuf.lResult = D_ERR_LOGIC;	// リザルト結果に「論理誤り」を設定
					goto err_iioctl3;				// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}
			break;

		case D_TASSO_ACCEPT:						// 制御種別がACCEPTの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ACCEPT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
            if( argsiz != sizeof(TArgAccept) )		// アーギュメントサイズが不正の時
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
            }

            ptArgAccept = (TArgAccept *)arg;		// アーギュメント域ポインタのアドレス設定

			/****************************************/
			/*	コネクション管理テーブルの検索		*/
			/****************************************/
													// すべての個別部に対して処理を繰り返す
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                                        			// コネクション管理テーブルの対象個別部の取得
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;

				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( iLoopCnt=%ld )\n",
																D_PROC_NAME, iLoopCnt ) );
				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%08lx )\n",
																D_PROC_NAME, ptEcncIndAdr ) );
				DbgMsg01(DLv04, ( OutPut, 
						"***** %s: Display ( ptEcncIndAdr->sParentLocalSession=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->sParentLocalSession ) );
				DbgMsg01(DLv04, ( OutPut, 
						"***** %s: Display ( ptArgAccept->sLocalSession=%ld )\n",
												D_PROC_NAME, ptArgAccept->sLocalSession ) );
				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cAcceptStat=%02x )\n",
														D_PROC_NAME, ptEcncIndAdr->cAcceptStat ) );
													// ローカルセション番号が
													// 親ローカルセション番号と同一かつ
													// accept中状態が「accept中」の場合
                if( (ptEcncIndAdr->sParentLocalSession == ptArgAccept->sLocalSession) &&
					(ptEcncIndAdr->cAcceptStat == D_ACCEPTSTAT_ON) )
				{
					break;							// ループを抜ける
				}
			}

            if( iLoopCnt == ptEcnc->lMaxIndNum )	// 対象となる個別部が見つからなかった時
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
															D_PROC_NAME, D_ERR_NOTCONNECT ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_NOTCONNECT;			// D_ERR_NOTCONNECTを設定
//				goto err_iioctl2;					// エラー処理へ遷移
													// // リザルト結果に「コネクション未設定」
													// を設定
				tMsgBuf.lResult = D_RESULT_NOTCONNECT;
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/********************************************/
			/*  アーギュメント構成情報のセット			*/
			/********************************************/
//			ptArgAccept->sLocalSession  = ptEcncIndAdr->lSockDes;
													// コネクション管理テーブルの対象個別部番号を
													// 設定する
			ptArgAccept->sLocalSession  = iLoopCnt + 1;
			ptArgAccept->sAddrFamilyId  = D_ADDRFAMILY_ID;
			ptArgAccept->sRemotePortNo  = ptEcncIndAdr->tConnInfo.lPort;
			ptArgAccept->lRemoteAddr    = ptEcncIndAdr->tConnInfo.lIPAdr;

                                        			// コネクション管理テーブル個別部の
                                        			// accept中状態をOFFにする
			ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sLocalSession=%hd )\n",
													D_PROC_NAME, ptArgAccept->sLocalSession ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sAddrFamilyId=%hd )\n",
													D_PROC_NAME, ptArgAccept->sAddrFamilyId ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sRemotePortNo=%hd )\n",
													D_PROC_NAME, ptArgAccept->sRemotePortNo ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->lRemoteAddr=%ld )\n",
													D_PROC_NAME, ptArgAccept->lRemoteAddr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cAcceptStat=%hhd )\n",
													D_PROC_NAME, ptEcncIndAdr->cAcceptStat ) );

			/********************************************/
			/*  メッセージヘッダの編集					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  非完了応答の送信						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// 異常の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;              			// -1（アボート）を設定
				goto err_iioctl2;       			// エラー処理へ遷移
			}

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_DETACH:            			// 制御種別がDETACHの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( DETACH )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgDetach) )		// アーギュメントサイズが不正の時
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    																D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

            ptArgDetach = (TArgDetach *)arg;		// アーギュメント域ポインタのアドレス設定

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgDetach->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgDetach->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgDetach->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgDetach->sLocalSession > ptEcnc->lMaxIndNum )
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

													// コネクション管理テーブルの対象個別部の取得
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgDetach->sLocalSession - 1);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

													// コネクション管理テーブルの対象個別部の
													// パイプ用ディスクリプタが「０」でない時
			if( ptEcncIndAdr->alPipeDes[1] != 0 )	
			{                           
				/********************************************/
				/*  アーギュメント構成情報のセット			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_DETACH;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%ld )\n",
															D_PROC_NAME, (long)tArgInfo.pvArg2 ) );

				/************************************/
				/*	パイプへの書込み				*/
				/************************************/
				for( ; ; )							// 送信できるまで処理を繰り返す
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
										ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// DETACH要求の送信
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sstRet=%d )\n",
																	D_PROC_NAME, sstRet ) );
					if( sstRet == D_ERR_SYS )		// 異常の時
					{
						if( errno != EINTR )		// EINTR以外の時
						{
							DbgMsg01(DLv05,(OutPut,"***** %s: Err Function 16: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;  			// -1（アボート）を設定
							goto err_iioctl2;		// エラー処理へ遷移
						}
					}
					else if( sstRet == stCount )	// 書込まれたバイト数が書込みバイト数と同一の時
					{
						break;						// ループを抜ける
					}
					else							// 書込まれたバイト数が書込みバイト数と同一
					{								// でない時
													// 残りのデータの書き込み準備
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// コネクション管理テーブルの対象個別部の
			{										// パイプ用ディスクリプタが「０」の時

				/*****	障害対応（KL0040）	Start	修正日：2003.03.24	*****/
				/************************************************************/
				/*  ソケットディスクリプタが「0以外」の場合はクローズする	*/
				/*	ように判定処理を追加									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// ソケットディスクリプタが「０以外」の場合
				{
					/*****	仕様変更（SSLA0014）Start	修正日：2003.02.17	*****/
					/************************************************************/
					/*  ソケットのクローズ処理を追加							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// 対象個別部のソケットディスクリプタクローズ
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close失敗
						{
							if( errno == EINTR )	// errno がEINTRの時
							{
								continue;
							}
							else					// errno がEINTRでない時
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close成功
						{
													// 対象個別部のソケットディスクリプタクリア
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	仕様変更（SSLA0014） End	修正日：2003.02.17	*****/
				}
				/*****	障害対応（KL0040）	 End	修正日：2003.03.24	*****/

				/************************************/
				/*	コネクション管理テーブルの		*/
				/*				対象個別部の初期化	*/
				/************************************/
													// コネクション管理テーブルの対象個別部のクリア
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  メッセージヘッダの編集					*/
				/********************************************/
//        	    tMsgBuf.lMsgtype = D_MTYPE17;
        	    tMsgBuf.lMsgtype = D_MTYPE22;
            	tMsgBuf.pcBufAdr = NULL;
            	tMsgBuf.lDatesize = D_DATESIZE_FIX;
            	tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
            	tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  非完了応答の送信						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				
				if( iRet == D_ERR_SYS )				// 異常の時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 17: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1（アボート）を設定
					goto err_iioctl2;				// エラー処理へ遷移
				}
			}

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_CONNECT:						// 制御種別がCONNECTの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( CONNECT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgConnect) )		// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 18: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgConnect = (TArgConnect *)arg;		// アーギュメント域ポインタのアドレス設定

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgConnect->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgConnect->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgConnect->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgConnect->sLocalSession > ptEcnc->lMaxIndNum )
			{                           
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 19: 0x%08x\n",
    																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/****************************************/
			/*	コネクション管理テーブル			*/
			/*					対象個別部の設定	*/
			/****************************************/
													// コネクション管理テーブルの対象個別部の取得
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgConnect->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

            ptEcncIndAdr->cSCFlg = D_SCINFO_CLIENT; // クライアントを設定

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
														D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );

			/****************************************/
			/*	スレッド引数領域の設定				*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MALLOC, 1, sizeof(TArgThread) );
													// スレッド用アーギュメント領域の確保
			ptArgThread = malloc( sizeof(TArgThread) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, ptArgThread );
			
			if( ptArgThread == NULL )				// 確保できなかった時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 20: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "malloc", strerror(errno) ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_NOBUF;					// D_ERR_NOBUFを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_NOBUF;		// リザルト結果に「バッファ不足」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/********************************************/
			/*  スレッド用アーギュメントの設定			*/
			/********************************************/
            ptArgThread->lSockDes       = ptEcncIndAdr->lSockDes;
            ptArgThread->cReqClass      = D_REQCLASS_CONN;
            ptArgThread->lRCode         = ptRdIndAdr->lRCode;
            ptArgThread->ulReqNum       = ptRdIndAdr->lReqNum;
            ptArgThread->pvArg1         = arg;
            (long)ptArgThread->pvArg2   = argsiz;

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lSockDes=%ld )\n",
														D_PROC_NAME, ptArgThread->lSockDes ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->cReqClass=%hhd )\n",
														D_PROC_NAME, ptArgThread->cReqClass ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lRCode=%ld )\n",
														D_PROC_NAME, ptArgThread->lRCode ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->ulReqNum=%ld )\n",
														D_PROC_NAME, ptArgThread->ulReqNum ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg1=%p )\n",
														D_PROC_NAME, ptArgThread->pvArg1 ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg2=%ld )\n",
														D_PROC_NAME, (long)ptArgThread->pvArg2 ) );

			/****************************************/
			/*	スレッドの作成						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_CREATE, 4, 
														&thId, NULL, os_tcpex, ptArgThread );
													// スレッドの作成
			iRet = pthread_create( &thId, NULL, os_tcpex, ptArgThread );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet != NORMAL )					// スレッドの作成に失敗した時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, D_ERR_LOGIC, "pthread_create", strerror(errno) ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/****************************************/
			/*	スレッドの分離						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_DETACH, 1, thId );
			pthread_detach( thId );					// スレッドのデタッチ
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 0 );

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

		case D_TASSO_DISCONNECT:					// 制御種別がDISCONNECTの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( DISCONNECT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgDisconnect) )	// アーギュメントサイズが不正の時
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
    																D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgDisconnect = (TArgDisconnect *)arg;

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgDisconnect->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgDisconnect->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgDisconnect->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgDisconnect->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 23: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

													// コネクション管理テーブルの対象個別部の取得
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgDisconnect->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			/****************************************/
			/*	スレッドへの書込み					*/
			/****************************************/
													// コネクション管理テーブルの対象個別部の
													// パイプ用ディスクリプタが「０」でない時
			if( ptEcncIndAdr->alPipeDes[1] != 0 )
			{
				/********************************************/
				/*  アーギュメント構成情報のセット			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_DCONN;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%ld )\n",
															D_PROC_NAME, (long)tArgInfo.pvArg2 ) );

				/************************************/
				/*	パイプへの書込み				*/
				/************************************/
				for( ; ; )							// 送信できるまで処理を繰り返す
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
											ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// DISCONNECT要求の送信
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sstRet=%d )\n",
																	D_PROC_NAME, sstRet ) );
					if( sstRet == D_ERR_SYS )		// 異常の時
					{
						if( errno != EINTR )		// EINTR以外の時
						{
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 24: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;				// -1（アボート）を設定
							goto err_iioctl2;		// エラー処理へ遷移
						}
					}
					else if( sstRet == stCount )	// 書込まれたバイト数が書込みバイト数と同一の時
					{
						break;						// ループを抜ける
					}
					else							// 書込まれたバイト数が書込みバイト数と同一
					{								// でない時
													// 残りのデータの書き込み準備
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// コネクション管理テーブルの対象個別部の
			{										// パイプ用ディスクリプタが「０」の時

				/*****	障害対応（KL0040）	Start	修正日：2003.03.24	*****/
				/************************************************************/
				/*  ソケットディスクリプタが「0以外」の場合はクローズする	*/
				/*	ように判定処理を追加									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// ソケットディスクリプタが「０以外」の場合
				{
					/*****	仕様変更（SSLA0014）Start	修正日：2003.02.17	*****/
					/************************************************************/
					/*  ソケットのクローズ処理を追加							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// 対象個別部のソケットディスクリプタクローズ
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close失敗
						{
							if( errno == EINTR )	// errno がEINTRの時
							{
								continue;
							}
							else					// errno がEINTRでない時
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close成功
						{
													// 対象個別部のソケットディスクリプタクリア
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	仕様変更（SSLA0014） End	修正日：2003.02.17	*****/
				}
				/*****	障害対応（KL0040）	 End	修正日：2003.03.24	*****/

				/************************************/
				/*	コネクション管理テーブルの		*/
				/*				対象個別部の初期化	*/
				/************************************/
													// コネクション管理テーブルの対象個別部のクリア
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  メッセージヘッダの編集					*/
				/********************************************/
//				tMsgBuf.lMsgtype = D_MTYPE17;
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lDatesize = D_DATESIZE_FIX;
				tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  非完了応答の送信						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				
				if( iRet == D_ERR_SYS )				// 異常の時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1（アボート）を設定
					goto err_iioctl2;				// エラー処理へ遷移
				}
			}
			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_ABORT:							// 制御種別がABORTの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ABORT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgAbort) )		// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 26: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgAbort = (TArgAbort *)arg;			// アーギュメント域ポインタのアドレス設定

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgAbort->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgAbort->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgAbort->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgAbort->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 27: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/****************************************/
			/*	設定領域の確認						*/
			/****************************************/
													// コネクション管理テーブルの対象個別部の取得
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgAbort->sLocalSession - 1);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

													// コネクション管理テーブルの対象個別部の
													// パイプ用ディスクリプタが「０」でない時
			if( ptEcncIndAdr->alPipeDes[1] != 0 )
			{
				/************************************/
				/*	ソケットオプションの設定		*/
				/************************************/
				tLinger.l_onoff = 1;
				tLinger.l_linger = 0;
				
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
										SOL_SOCKET, SO_LINGER, &tLinger, sizeof(tLinger) );
													// ソケットオプションの設定
				iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_LINGER,
															&tLinger, sizeof(tLinger) );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

				if( iRet == D_ERR_SYS )				// 異常の時
				{
					switch( errno )					// エラー番号による処理の振分け
					{
						case EBADF:
						case ENOTSOCK:
						case ENOPROTOOPT:
						case EFAULT:
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
									D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//							lRet = D_ERR_LOGIC;		// D_ERR_LOGICを設定
//							goto err_iioctl2;		// エラー処理へ遷移
													// リザルト結果に「論理誤り」を設定
							tMsgBuf.lResult = D_ERR_LOGIC;
							goto err_iioctl3;		// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
							break;

						default:
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
									D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

							lRet = -1;				// -1（アボート）を設定
							goto err_iioctl2;		// エラー処理へ遷移
					}
				}

				/********************************************/
				/*  アーギュメント構成情報のセット			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_ABORT;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg2 ) );

				/************************************/
				/*	パイプへの書込み				*/
				/************************************/
				for( ; ; )							// 送信できるまで処理を繰り返す
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
									ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// ABORT要求の送信
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );
					
					if( sstRet == D_ERR_SYS )		// 異常の時
					{
						if( errno != EINTR )		// EINTR以外の時
						{
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 30: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;				// -1（アボート）を設定
							goto err_iioctl2;		// エラー処理へ遷移
						}
					}
					else if( sstRet == stCount )	// 書込まれたバイト数が書込みバイト数と同一の時
					{
						break;						// ループを抜ける
					}
					else							// 書込まれたバイト数が書込みバイト数と同一
					{								// でない時
													// 残りのデータの書き込み準備
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// コネクション管理テーブルの対象個別部の
			{										// パイプ用ディスクリプタが「０」の時

				/*****	障害対応（KL0040）	Start	修正日：2003.03.24	*****/
				/************************************************************/
				/*  ソケットディスクリプタが「0以外」の場合はクローズする	*/
				/*	ように判定処理を追加									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// ソケットディスクリプタが「０以外」の場合
				{
					/*****	仕様変更（SSLA0014）Start	修正日：2003.02.17	*****/
					/************************************************************/
					/*  ソケットのクローズ処理を追加							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// 対象個別部のソケットディスクリプタクローズ
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close失敗
						{
							if( errno == EINTR )	// errno がEINTRの時
							{
								continue;
							}
							else					// errno がEINTRでない時
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close成功
						{
													// 対象個別部のソケットディスクリプタクリア
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	仕様変更（SSLA0014） End	修正日：2003.02.17	*****/
				}
				/*****	障害対応（KL0040）	 End	修正日：2003.03.24	*****/

				/************************************/
				/*	コネクション管理テーブルの		*/
				/*				対象個別部の初期化	*/
				/************************************/
													// コネクション管理テーブルの対象個別部のクリア
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  メッセージヘッダの編集					*/
				/********************************************/
//				tMsgBuf.lMsgtype = D_MTYPE17;
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lDatesize = D_DATESIZE_FIX;
				tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  非完了応答の送信						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				

				if( iRet == D_ERR_SYS )				// 異常の時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 31: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1（アボート）を設定
					goto err_iioctl2;				// エラー処理へ遷移
				}
			}

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

			break;

        case D_TASSO_ATTACH:						// 制御種別がATTACHの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ATTACH )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgAttach) )		// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 32: 0x%08x\n",
																D_PROC_NAME, D_ERR_ARG ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgAttach = (TArgAttach *)arg;		// アーギュメント域ポインタのアドレス設定

			/****************************************/
			/*	コネクション管理テーブルの検索		*/
			/****************************************/
													// ループ処理
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                                        			// コネクション管理テーブルの対象個別部の取得
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
															D_PROC_NAME, ptEcncIndAdr ) );

                if( ptEcncIndAdr->lSockDes == 0 )	// ソケットディスクリプタが0の時
                {
                    break;							// ループを抜ける
                }
            }

			if( iLoopCnt == ptEcnc->lMaxIndNum )	// 対象となる個別部が見つからなかった時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 33: 0x%08x\n",
																D_PROC_NAME, D_ERR_NOBUF ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_NOBUF;					// D_ERR_NOBUFを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_NOBUF;		// リザルト結果に「バッファ不足」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/****************************************/
			/*	ソケットディスクリプタの作成		*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SOCKET, 3, PF_INET, SOCK_STREAM, 0 );
													// ソケットの生成
            iRet = socket( PF_INET, SOCK_STREAM, 0 );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

            if( iRet == D_ERR_SYS )
            {
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
				switch( errno )
				{
                    case EPROTONOSUPPORT:
                    case EAFNOSUPPORT:
                    case EINVAL:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 34: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "socket", strerror(errno) ) );

//						lRet = D_ERR_LOGIC;			// D_ERR_LOGICを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「論理誤り」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
                        break;

                    case ENFILE:
                    case EMFILE:
                    case ENOBUFS:
                    case ENOMEM:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 35: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "socket", strerror(errno) ) );

//						lRet = D_ERR_NOBUF;			// D_ERR_NOBUFを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「バッファ不足」を設定
						tMsgBuf.lResult = D_ERR_NOBUF;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
                        break;

                    case EACCES:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 36: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, OSFEACC, "socket", strerror(errno)));

						lRet = OSFEACC;				// OSFEACCを設定
						goto err_iioctl2;			// エラー処理へ遷移
                        break;

                    default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 37: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "socket", strerror(errno)));

						lRet = -1;					// -1（アボート）を設定
						goto err_iioctl2;			// エラー処理へ遷移
				}
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptEcncIndAdr->lSockDes = iRet;			// ソケットディスクリプタの設定

													// 対象個別部のインデックスを設定
			ptArgAttach->sLocalSession = iLoopCnt + 1;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->lSockDes=%ld )\n",
													D_PROC_NAME, ptEcncIndAdr->lSockDes ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAttach->sLocalSession=%hhd )\n",
													D_PROC_NAME, ptArgAttach->sLocalSession ) );

			/*****	仕様変更（SSLA0012）Start		修正日：2003.02.25	*****/
			/****************************************************************/
			/*  TCP/IPローカルアドレス再使用許可の設定						*/
			/****************************************************************/
			iOpt = 1;					// オプションを設定

			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
										SOL_SOCKET, SO_LINGER, iOpt, sizeof(iOpt) );

													// ソケットオプションの設定
			iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_REUSEADDR,
																 &iOpt, sizeof(iOpt) );

			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// 異常の時
			{
				switch( errno )						// エラー番号による処理の振分け
				{
					case EBADF:
					case ENOTSOCK:
					case ENOPROTOOPT:
					case EFAULT:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
								D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, errno );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGICを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「論理誤り」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
								D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, errno );
						lRet = -1;					// -1（アボート）を設定
						goto err_iioctl2;			// エラー処理へ遷移
				}
			}
			/*****	仕様変更（SSLA0012） End		修正日：2003.02.25	*****/

			/********************************************/
			/*  メッセージヘッダの編集					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  非完了応答の送信						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
																// メッセージ送信
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// 異常の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 38: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1（アボート）を設定
				goto err_iioctl2;					// エラー処理へ遷移
			}

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_BIND:							// 制御種別がBINDの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( BIND )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgBind) )		// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 39: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgBind = (TArgBind *)arg;			// アーギュメント域ポインタのアドレス設定

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgBind->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgBind->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgBind->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgBind->sLocalSession > ptEcnc->lMaxIndNum )
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 40: 0x%08x\n",
    																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}
													// コネクション管理テーブルの対象個別部の取得
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgBind->sLocalSession - 1);

			/****************************************/
			/*	BIND領域の設定						*/
			/****************************************/
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );
															
			tSockAddr_In.sin_family = PF_INET;
			tSockAddr_In.sin_port = htons(ptArgBind->sLocalPortNo);
			tSockAddr_In.sin_addr.s_addr = htonl(INADDR_ANY);

			/****************************************/
			/*	ソケットの登録						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_BIND, 3, ptEcncIndAdr->lSockDes, 
								(struct sockaddr *)&tSockAddr_In, sizeof(tSockAddr_In) );
													// ソケットの登録
			iRet = bind( ptEcncIndAdr->lSockDes, (struct sockaddr *)&tSockAddr_In,
                                                                    sizeof(tSockAddr_In) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 2, iRet, errno );
                                                                    
			if( iRet == D_ERR_SYS )					// 異常の時
			{
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
				switch( errno )						// エラー番号による処理の振分け
				{
					case EBADF:
					case EACCES:
					case ENOTSOCK:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 41: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "bind", strerror(errno) ) );
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGICを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「アーギュメント不正」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
						break;

					case EINVAL:
					case EADDRINUSE:				// 20030307 KL0025 追加
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 42: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_USEDADDR, "bind", strerror(errno) ) );
//						lRet = D_ERR_USEDADDR;		// D_ERR_USEDADDRを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「アドレス使用中」を設定
						tMsgBuf.lResult = D_ERR_USEDADDR;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
						break;

                    default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 43: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "bind", strerror(errno) ) );
						lRet = -1;					// -1（アボート）を設定
						goto err_iioctl2;			// エラー処理へ遷移
				}
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/********************************************/
			/*  メッセージヘッダの編集					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
			stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  非完了応答の送信						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );


			if( iRet == D_ERR_SYS )					// 異常の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 44: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1（アボート）を設定
				goto err_iioctl2;					// エラー処理へ遷移
			}

			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_LISTEN:						// 制御種別がLISTENの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( LISTEN )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz != sizeof(TArgListen) )		// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 45: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			ptArgListen = (TArgListen *)arg;		// アーギュメント域ポインタのアドレス設定

			/****************************************/
			/*	ローカルセションの確認				*/
			/****************************************/
													// ローカルセション番号が範囲外の時
			if( ptArgListen->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgListen->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 46: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGICを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_LOGIC;		// リザルト結果に「論理誤り」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}
                                        // コネクション管理テーブルの対象個別部の取得
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgListen->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			/****************************************/
			/*	ソケットの設定						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_LISTEN, 2, ptEcncIndAdr->lSockDes, 
																ptArgListen->sMaxWaitResNum );
													// ソケットの設定
			iRet = listen( ptEcncIndAdr->lSockDes, ptArgListen->sMaxWaitResNum );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// 異常の時
			{
				switch( errno )						// エラー番号による処理の振分け
				{
					case EADDRINUSE:
					case EBADF:
					case ENOTSOCK:
					case EOPNOTSUPP:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 47: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "listen", strerror(errno) ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGICを設定
//						goto err_iioctl2;			// エラー処理へ遷移
													// リザルト結果に「論理誤り」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 48: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "listen", strerror(errno) ) );
						lRet = -1;					// -1（アボート）を設定
						goto err_iioctl2;			// エラー処理へ遷移
				}
			}

            ptEcncIndAdr->cSCFlg = D_SCINFO_SERVER;	// サーバを設定

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
														D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );

			/********************************************/
			/*  メッセージヘッダの編集					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
           	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  非完了応答の送信						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// 異常の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 49: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1（アボート）を設定
				goto err_iioctl2;					// エラー処理へ遷移
			}
			lRet = ptRdIndAdr->lRCode;				// 返却値としてリクエスト識別子を設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

        case D_TASSO_NETCTL:						// 制御種別がNETCTLの時
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( NETCTL )\n", D_PROC_NAME ) );

			/****************************************/
			/*	引数の設定							*/
			/****************************************/
			if( argsiz < D_ARG_NETCTL_MIN )			// アーギュメントサイズが不正の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 50: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );

/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARGを設定
//				goto err_iioctl2;					// エラー処理へ遷移
				tMsgBuf.lResult = D_ERR_ARG;		// リザルト結果に「アーギュメント不正」を設定
				goto err_iioctl3;					// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}

			/********************************************/
			/*  メッセージヘッダの編集					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// メッセージサイズ算出
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  非完了応答の送信						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// メッセージ送信
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// 異常の時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 51: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1（アボート）を設定
				goto err_iioctl2;					// エラー処理へ遷移
			}

			lRet = NORMAL;							// 返却値としてNORMALを設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 52: 0x%08x\n",
															D_PROC_NAME, D_ERR_LOGIC ) );
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//			lRet = D_ERR_LOGIC;						// D_ERR_LOGICを設定
//			goto err_iioctl2;						// エラー処理へ遷移
			tMsgBuf.lResult = D_ERR_LOGIC;			// リザルト結果に「論理誤り」を設定
			goto err_iioctl3;						// 非完了メッセージのエラー処理へ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
	}


/****************************************************************************/
/* 終了処理                                                                 */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_OUT, 1, lRet );
    return( lRet );									// 正常を返却


/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_iioctl2:
	/************************************/
	/* rd管理テーブル対象個別部の編集	*/
	/************************************/
													// 非完了要求状態を要求未に設定
    ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
    												// 要求種別をクリア
    ptRdIndAdr->cReqClass           = D_ERDC_REQCLASS00;
    ptRdIndAdr->lReqNum             = 0;			// リクエスト番号をクリア
    ptRdIndAdr->lPCode              = 0;			// プロセス識別子をクリア
    ptRdIndAdr->pvArg1              = NULL;			// 引数領域1をクリア
    ptRdIndAdr->pvArg2              = NULL;			// 引数領域2をクリア

    ptErdc->ulMstReqNum--;              			// マスタリクエスト番号のデクリメント

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
													D_PROC_NAME, ptErdc->ulMstReqNum ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, lRet );
/*****	故障管理番号TBCS0205の対応		Start							修正日：2003.07.08	*****/
													// アボート処理
	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIIOCTL2 << 16) | D_T_ERR_SYS1 );
/*****	故障管理番号TBCS0205の対応		 End							修正日：2003.07.08	*****/


/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
err_iioctl3:										// 非完了メッセージのエラー処理
	/********************************************/
	/*  メッセージヘッダの編集					*/
	/********************************************/
	tMsgBuf.lMsgtype = D_MTYPE22;
	tMsgBuf.pcBufAdr = NULL;
	tMsgBuf.lDatesize = D_DATESIZE_FIX;
	tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
													// メッセージサイズ算出
	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

	/********************************************/
	/*  非完了応答の送信						*/
	/********************************************/
	os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId,
										&tMsgBuf, stMsgSz, IPC_NOWAIT );
													// メッセージ送信
	iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

	if( iRet == D_ERR_SYS )							// 異常の時
	{
		DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 49: 0x%08x(%s:%s)\n",
								D_PROC_NAME, -1, "msgsnd", strerror(errno)));

		lRet = -1;									// -1（アボート）を設定

		/************************************/
		/* rd管理テーブル対象個別部の編集	*/
		/************************************/
													// 非完了要求状態を要求未に設定
		ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
													// 要求種別をクリア
		ptRdIndAdr->cReqClass			= D_ERDC_REQCLASS00;
		ptRdIndAdr->lReqNum				= 0;		// リクエスト番号をクリア
		ptRdIndAdr->lPCode				= 0;		// プロセス識別子をクリア
		ptRdIndAdr->pvArg1				= NULL;		// 引数領域1をクリア
		ptRdIndAdr->pvArg2				= NULL;		// 引数領域2をクリア

		ptErdc->ulMstReqNum--;              		// マスタリクエスト番号のデクリメント

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
													D_PROC_NAME, ptErdc->ulMstReqNum ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, lRet );
/*****	故障管理番号TBCS0205の対応		Start							修正日：2003.07.08	*****/
													// アボート処理
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIIOCTL2 << 16) | D_T_ERR_SYS2 );
/*****	故障管理番号TBCS0205の対応		 End							修正日：2003.07.08	*****/
	}

	lRet = ptRdIndAdr->lRCode;						// 返却値としてリクエスト識別子を設定する
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_OUT, 1, lRet );
	return( lRet );									// 正常を返却
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
