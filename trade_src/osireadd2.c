/****************************************************************************/
/*  著作権  ２００２                                                        */
/*            株式会社ＮＴＴデータ                                          */
/*              金融ビジネス事業本部                                        */
/*                                                                          */
/*                                                                          */
/*  収容物  ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ              */
/****************************************************************************/
/* ＜対象業務名＞                  ＴＲＡＤＥエミュレータ                   */
/* ＜対象業務ＩＤ＞                ＴＲＥ                                   */
/* ＜サービス項目名＞              ＴＣＰ/ＩＰ制御                          */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                非完了型 直接読み込み                    */
/* ＜モジュールＩＤ＞              osireadd2                                */
/* ＜モジュール通番＞                                                       */
/*--------------------------------------------------------------------------*/
/* ＜適用機種名＞                  汎用サーバ                               */
/* ＜適用ＯＳ＞                    Ｌｉｎｕｘ                               */
/* ＜開発環境＞                    ＲＨＡＳ２．１                           */
/* ＜記述言語＞                    Ｃ言語                                   */
/* ＜モジュール形態＞              関数                                     */
/* ＜機能区分＞                                                             */
/* ＜対象データ＞                                                           */
/* ＜工程・階層区分＞                                                       */
/*--------------------------------------------------------------------------*/
/* ＜開発システム名＞              ＬＡＬａ−ＳＭＰシステム                 */
/* ＜開発システム番号＞            ＰＰ４０Ｂ００１２２０                   */
/*--------------------------------------------------------------------------*/
/* ＜開発担当名＞                  ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜電話番号＞                    148-1457(03-5437-1457)                   */
/*--------------------------------------------------------------------------*/
/* ＜設計者名＞                    ＣＢ事ビジネス企画担当                   */
/* ＜設計年月日＞                  ２００２年　９月２７日                   */
/* ＜設計修正者名＞                                                         */
/* ＜設計修正年月日及び修正ＩＤ＞                                           */
/*--------------------------------------------------------------------------*/
/* ＜ソース作成者＞                ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜ソース作成年月日＞            ２００２年　９月２７日                   */
/* ＜ソース修正者＞                ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜ソース修正年月日及び修正ＩＤ＞２００３年０３月３１日 仕様変更(SSLA0019)*/
/* ＜ソース修正者＞                ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜ソース修正年月日及び修正ＩＤ＞２００３年０４月２５日 障害対応(KL0048)  */
/* ＜ソース修正者＞                ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜ソース修正年月日及び修正ＩＤ＞２００３年０８月１１日 障害対応(TBCS0276)*/
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞              ステップ                                 */
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞                                                             */
/*   TCP/IPリード                                                           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long osireadd2( long rd, long fildes, char *buf,                    */
/*                                            long len, long prm )          */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      long rd         リクエスト識別子（0以上）                           */
/*      long fildes     ファイルディスクリプタ （使用しない）               */
/*      char *buf       入力域へのポインタ                                  */
/*      long len        入力域へのサイズ（16以上）                          */
/*      long prm        動作パラメータ	⇒                                  */
/*                              (1) 00bit〜15bit　:　readオプション         */
/*                              (2) 16bit〜31bit　:  ローカルセッション番号 */
/*                                                                          */
/* ＜返却値＞                                                               */
/*		正常終了		リクエスト識別子									*/
/*		異常終了		OSEEOVRQ	ｒｄ管理テーブル個別部の「予約状態」が	*/
/*									「予約未」の個別部が存在しない。		*/
/*						OSEEIVRD	ｒｄ管理テーブル個別部の「予約状態」が	*/
/*									「予約未」である。						*/
/*									引数のリクエスト識別子の値が0未満である	*/
/*						OSEEUSED	ｒｄ管理テーブル個別部の				*/
/*									「非完了要求状態」が					*/
/*									「非完了要求済」である					*/
/*						OSFEFILDES	コネクション管理テーブル異常			*/
/*						0xECF10001	入力域サイズ異常						*/
/*									ローカルセッション番号異常				*/
/*						0xECB00156	コネクションが未設定					*/
/*						0xECB00016	パイプ書込み異常						*/
/*						0xECF00009	パイプ用ディスクリプタ異常				*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜入出力データ構造＞                                                     */
/* ＜制限事項＞                                                             */
/*     特になし                                                             */
/* ＜使用外部モジュールＩＤ＞                                               */
/* ＜呼出元のモジュールＩＤ＞                                               */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/******************************** 標準ヘッダ・ファイル **********************/
#include <errno.h>									// エラーＮｏ取得用
#include <unistd.h> 								// write用
#include <string.h> 								// memset用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osireadd2.h"
#include "osireadd2_ins.h"							// 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osireadd2                                                 */
/*                                                                          */
/*  ＜機能概要＞  TCP/IPリード                                              */
/*                                                                          */
/****************************************************************************/
long osireadd2( long rd, long fildes, char *buf, long len, long prm )
{
	TErdcTableInd *ptErdcTableInd;					// rd管理テーブルの対象個別部
	TEcncTableInd *ptEcncTableInd;					// コネクション管理テーブルの対象個別部
	TArgInfo tTArgInfo; 							// 要求情報用アーギュメント
	int			iLocalSes;							// ローカルセッション番号
	long		lRCode;								// 対象リクエスト識別子
	ssize_t		lSndBytes;							// 一回送信成功のバイト数
	ssize_t		lTotalSndBytes; 					// 現在までに全部の送信バイト数
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
//	int			iErrno;								// エラー番号
	int			iRet;								// 返却値
	long		lRet;								// 返却値
	TMyMessage	tMsgBuf;                 			// メッセージバッファ構造体
	size_t	stMsgSz;                     			// 送信用メッセージサイズ
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/


/************************************************************************************************/
/* 初期処理                                                                                     */
/************************************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSIREADD2, D_T_TRA_IN, 5, rd, fildes, buf, len, prm );


	if( ptEcnc == NULL )							// コネクション管理テーブルが未作成の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, OSFEFILDES );
		return( OSFEFILDES );						// OSFEFILDESを返却
	}

	lRCode = os_CheckRCode( rd );					// リクエスト識別子チェック
	if( lRCode <= D_CHECKRCODE_ERR )				// リクエスト識別子が異常値の時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
														D_PROC_NAME, lRCode ) );
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, lRCode );
		return( lRCode );							// リクエスト識別子を返却
	}

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRCode=%ld )\n", D_PROC_NAME, lRCode ) );

	if( len < D_LEN_MIN )							// 入力域へのサイズが最小値より小さい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
														D_PROC_NAME, D_ERR_ARG ) );
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_PRA, 1, D_ERR_ARG );
		return( D_ERR_ARG );						// D_ERR_ARGを返却
	}

													// ローカルセッション番号の取得
	iLocalSes =  ( int )(( prm >> 16 ) & 0x0000ffff );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLocalSes=%d )\n", D_PROC_NAME, iLocalSes ) );

													// コネクション管理テーブル個別部数範囲外の場合
	if( ( iLocalSes < D_INDNUM_MIN ) || ( iLocalSes > ptEcnc->lMaxIndNum ) )
	{									
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
														D_PROC_NAME, D_ERR_REQ ) );
/*****	障害対応（KL0048）		Start									修正日：2003.04.25	*****/
/************************************************************************************************/
/*	返却値をD_RESULT_NOTCONNECT → D_ERR_REQに変更												*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_RESULT_NOTCONNECT );
//		return( D_RESULT_NOTCONNECT );				// D_RESULT_NOTCONNECTを返却
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_ERR_REQ );
		return( D_ERR_REQ );						// リクエスト値不正（パラメータエラー）を返却
/*****	障害対応（KL0048）		 End									修正日：2003.04.25	*****/
	}

													// コネクションテーブル対象個別部の設定
	ptEcncTableInd = (TEcncTableInd *)( ptEcnc + 1 ) + iLocalSes - 1;
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd=%p )\n",
														D_PROC_NAME, ptEcncTableInd ) );

													// 'S'と'C'以外の場合
	if( ( ptEcncTableInd->cSCFlg != D_SCINFO_SERVER ) && 
		( ptEcncTableInd->cSCFlg != D_SCINFO_CLIENT ) ) 
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
														D_PROC_NAME, D_ERR_TABLE ) );
/*****	障害対応（KL0048）		Start									修正日：2003.04.25	*****/
/************************************************************************************************/
/*	返却値をD_RESULT_NOTCONNECT → D_ERR_TABLEに変更											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_RESULT_NOTCONNECT );
//		return( D_RESULT_NOTCONNECT );				// D_RESULT_NOTCONNECTを返却
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_ERR_TABLE );
		return( D_ERR_TABLE );						// テーブルエラーを返却
/*****	障害対応（KL0048）		 End									修正日：2003.04.25	*****/
	}

/*****	障害対応（KL0048）		Start									修正日：2003.04.25	*****/
/************************************************************************************************/
/*	返却値をリザルトの応答で返却する為、この判定処理をrd管理テーブルの設定後に移動させる		*/
/************************************************************************************************/
//	if( ptEcncTableInd->alPipeDes[1] == 0 )			// 対象個別部のパイプ用ディスクリプタが０の場合
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
//														D_PROC_NAME, D_RESULT_ELOCALSES ) );
//		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_RESULT_ELOCALSES );
//		return( D_RESULT_ELOCALSES );				// D_RESULT_ELOCALSESを返却
//	}
/*****	障害対応（KL0048）		 End									修正日：2003.04.25	*****/


/************************************************************************************************/
/* 本処理                                                                                       */
/************************************************************************************************/
	/****************************************/
	/*  rd管理テーブルの対象個別部設定		*/
	/****************************************/
													// rd管理テーブル対象個別部のアドレスを設定
	ptErdcTableInd = (TErdcTableInd *)( ptErdc + 1 ) + (lRCode - 1);

													// 「非完了要求状態」を「要求済」に設定
	ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;

	ptErdcTableInd->cReqClass = D_ERDC_REQCLASS23;	// rdの要求種別設定

	ptErdcTableInd->lReqNum = ptErdc->ulMstReqNum;	// rdのリクエスト番号に
													// rd管理部のマスタリクエスト番号を設定

	ptErdc->ulMstReqNum++;							// rd管理部のマスタリクエスト番号インクリメント

	ptErdcTableInd->lPCode = ptMyEPRC->lPCode;		// ｒｄ管理テーブル個別部のプロセス識別子に
													// 自プロセス識別子を設定

	ptErdcTableInd->pvArg1 = buf;					// 引数領域１に(引数の)入力域へのポインタを設定
	ptErdcTableInd->pvArg2 = (void *)len;			// 引数領域２に(引数の)入力域サイズを設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd=%p )\n",
							D_PROC_NAME, ptErdcTableInd ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->tReqStat.cUCompStat=%hhd )\n",
							D_PROC_NAME, ptErdcTableInd->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->cReqClass=%hhd )\n",
							D_PROC_NAME, ptErdcTableInd->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->lReqNum=%ld )\n",
							D_PROC_NAME, ptErdcTableInd->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->lPCode=%ld )\n",
							D_PROC_NAME, ptErdcTableInd->lPCode ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->pvArg1=%p )\n",
							D_PROC_NAME, ptErdcTableInd->pvArg1 ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->pvArg2=%p )\n",
							D_PROC_NAME, ptErdcTableInd->pvArg2 ) );

/*****	障害対応（KL0048）		Start									修正日：2003.04.25	*****/
	if( ptEcncTableInd->alPipeDes[1] == 0 )			// 対象個別部のパイプ用ディスクリプタが０の場合
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
														D_PROC_NAME, D_RESULT_DISCONNECT ) );
		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, D_RESULT_DISCONNECT );

		tMsgBuf.lResult = D_RESULT_DISCONNECT;		// コネクションがリセットされた
		goto err_osireadd2;							// 非完了メッセージのエラー処理へ
	}
/*****	障害対応（KL0048）		 End									修正日：2003.04.25	*****/

	/****************************************/
	/*  コネクション管理テーブルの			*/
	/*  対象個別部設定						*/
	/****************************************/
	ptEcncTableInd->cReadStat = D_READSTAT_ON;		// read要求状態を「要求済」と設定

													// 「リクエスト識別子」の設定
	ptEcncTableInd->tReaInfo.lReqId = ptErdcTableInd->lRCode;

													// 「リクエスト番号」の設定
	ptEcncTableInd->tReaInfo.lReqNum = ptErdcTableInd->lReqNum;

													// 「引数情報１」の設定
	ptEcncTableInd->tReaInfo.pcPara1 = ptErdcTableInd->pvArg1;

													// 「引数情報２」の設定
	ptEcncTableInd->tReaInfo.lPara2 = (long)ptErdcTableInd->pvArg2;

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->cReadStat=%hhd )\n",
							D_PROC_NAME, ptEcncTableInd->cReadStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tReaInfo.lReqId=%ld )\n",
							D_PROC_NAME, ptEcncTableInd->tReaInfo.lReqId ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tReaInfo.lReqNum=%ld )\n",
							D_PROC_NAME, ptEcncTableInd->tReaInfo.lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tReaInfo.pcPara1=%p )\n",
							D_PROC_NAME, ptEcncTableInd->tReaInfo.pcPara1 ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tReaInfo.lPara2=%ld )\n",
							D_PROC_NAME, ptEcncTableInd->tReaInfo.lPara2 ) );

	/************************************/
	/*  read要求情報の設定				*/
	/************************************/
	tTArgInfo.cRecClass = D_REQCLASS_READ;			// 要求種別の設定
	tTArgInfo.lRCode = ptErdcTableInd->lRCode;		// 「リクエスト識別子」の設定
	tTArgInfo.ulReqNum = ptErdcTableInd->lReqNum;	// 「リクエスト番号」の設定
	tTArgInfo.pvArg1 = buf; 						// 「引数情報１」の設定
	tTArgInfo.pvArg2 = (void *)len; 				// 「引数情報２」の設定

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tTArgInfo.cRecClass=%lx )\n",
							D_PROC_NAME, tTArgInfo.cRecClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tTArgInfo.lRCode=%ld )\n",
							D_PROC_NAME, tTArgInfo.lRCode ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tTArgInfo.ulReqNum=%lx )\n",
							D_PROC_NAME, tTArgInfo.ulReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tTArgInfo.pvArg1=%08lx )\n",
							D_PROC_NAME, buf ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tTArgInfo.pvArg2=%ld )\n",
							D_PROC_NAME, len ) );

	/************************************/
	/*  read要求の送信					*/
	/************************************/
	lTotalSndBytes = 0;
	lSndBytes = 0;

	while( lTotalSndBytes < sizeof(long) )
	{
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( read要求の送信 )\n", D_PROC_NAME ) );

													// パイプ用ディスクリプタに対して
													// read要求を書き込む
		os_trcget2( D_MD_OSIREADD2, D_T_SYS_WRITE, 3, ptEcncTableInd->alPipeDes[1], 
							(const void *)&tTArgInfo + lTotalSndBytes,
							sizeof(tTArgInfo) - lTotalSndBytes );
		lSndBytes = write( ptEcncTableInd->alPipeDes[1], 
							(const void *)&tTArgInfo + lTotalSndBytes, 
							sizeof(tTArgInfo) - lTotalSndBytes );
		os_trcget2( D_MD_OSIREADD2, D_T_SYS_END, 1, lSndBytes );

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%ld )\n",
							D_PROC_NAME, lSndBytes ) );

		if( lSndBytes == D_ERR_SYS )				// read要求が失敗した時
		{
			if( errno == EINTR )					// errno がEINTRの時
			{
				continue;
			}
			else									// errno がEINTRでない時
			{
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//				iErrno = errno;						// エラー番号の退避
				/****************************************/
				/*	rd管理テーブルの対象個別部のクリア	*/
				/****************************************/
//				ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
//				ptErdcTableInd->cReqClass = D_ERDC_REQCLASS00;
//				ptErdcTableInd->lReqNum = 0;
//				ptErdcTableInd->lPCode = 0;
//				ptErdcTableInd->pvArg1 = NULL;
//				ptErdcTableInd->pvArg2 = NULL;
//				ptErdc->ulMstReqNum--;				// rd管理部のマスタリクエスト番号をデクリメント
//				ptEcncTableInd->cReadStat = '\0';
													// 設定したコネクション管理テーブルクリア
//				memset( &ptEcncTableInd->tReaInfo, 0, sizeof(TReqInfo) );

//				goto err_osireadd2;					// 異常処理へ遷移

				switch( errno )						// errnoによる処理の振分け
				{
					case EBADF:
					case EINVAL:
					case EFAULT:
					case EFBIG:
					case EAGAIN:
					case ENOSPC:
					case EIO:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "write", strerror(errno)));
						os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, errno );

													// リザルト結果に「論理誤り」を設定
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_osireadd2;			// 非完了メッセージのエラー処理へ
						break;

					case EPIPE:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_DISCONNECT, "write", strerror(errno)));
						os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, errno );

													// 切断によるキャンセル
						tMsgBuf.lResult = D_RESULT_DISCONNECT;
						goto err_osireadd2;			// 非完了メッセージのエラー処理へ
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "write", strerror(errno) ) );
						os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, errno );

						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIREADD2 << 16) | D_T_ERR_SYS );
						//return( -1 );				// アボート処理
				}
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
			}
		}

		lTotalSndBytes += lSndBytes;  				// 全部の送信バイト数に今回の分をインクリメント
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lTotalSndBytes=%ld )\n",
							D_PROC_NAME, lTotalSndBytes ) );
	}


/************************************************************************************************/
/* 終了処理                                                                                     */
/************************************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSIREADD2, D_T_TRA_OUT, 1, ptErdcTableInd->lRCode );
	return( ptErdcTableInd->lRCode );				// ｒｄ管理テーブル対象個別部リクエスト識別子


/************************************************************************************************/
/* エラー処理                                                                                   */
/************************************************************************************************/
err_osireadd2:
/*****	仕様変更（SSLA0019）	Start									修正日：2003.03.31	*****/
/************************************************************************************************/
/*  非完了要求の応答で返却値を返すように修正													*/
/************************************************************************************************/
//	switch( iErrno )
//	{
//		case EBADF:
//		case EINVAL:
//		case EFAULT:
//		case EFBIG:
//		case EAGAIN:
//		case ENOSPC:
//		case EIO:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, D_ERR_LOGIC, "write", strerror(iErrno) ) );
//			os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, iErrno );
//			return( D_ERR_LOGIC );		// 論理誤り
//			break;
//
//		case EPIPE:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, D_RESULT_DISCONNECT, "write", strerror(iErrno)));
//			os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, iErrno );
//			return( D_RESULT_DISCONNECT );
//										// 切断によるキャンセル
//			break;
//
//		default:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, -1, "write", strerror(iErrno) ) );
//			os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, iErrno );
//			return( -1 );				// アボート処理
//	}
	/********************************************/
	/*  メッセージヘッダの編集					*/
	/********************************************/
	tMsgBuf.lMsgtype  = D_MTYPE23;
	tMsgBuf.pcBufAdr  = NULL;
	tMsgBuf.lDatesize = D_DATESIZE_FIX;
	tMsgBuf.lReqid    = ptErdcTableInd->lReqNum;
													// メッセージサイズ算出
	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

	/********************************************/
	/*  非完了応答の送信						*/
	/********************************************/
	os_trcget2( D_MD_OSIREADD2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId,
										&tMsgBuf, stMsgSz, IPC_NOWAIT );
													// メッセージ送信
	iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OSIREADD2, D_T_SYS_END, 2, iRet, errno );

	if( iRet == D_ERR_SYS )							// 異常の時
	{
		DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 10: 0x%08x(%s:%s)\n",
								D_PROC_NAME, -1, "msgsnd", strerror(errno)));

		lRet = -1;									// -1（アボート）を設定

		/************************************************/
		/*	rd管理テーブル対象個別部のクリア			*/
		/************************************************/
													// 非完了要求状態を要求未に設定
		ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
													// 要求種別をクリア
		ptErdcTableInd->cReqClass			= D_ERDC_REQCLASS00;
		ptErdcTableInd->lReqNum				= 0;	// リクエスト番号をクリア
		ptErdcTableInd->lPCode				= 0;	// プロセス識別子をクリア
		ptErdcTableInd->pvArg1				= NULL;	// 引数領域1をクリア
		ptErdcTableInd->pvArg2				= NULL;	// 引数領域2をクリア

		ptErdc->ulMstReqNum--;						// rd管理部のマスタリクエスト番号をデクリメント

		/************************************************/
		/*	コネクション管理テーブル対象個別部のクリア	*/
		/************************************************/
		ptEcncTableInd->cReadStat = '\0';
		memset( &ptEcncTableInd->tReaInfo, 0, sizeof(TReqInfo) );

		os_trcget2( D_MD_OSIREADD2, D_T_ERR_SYS, 1, lRet );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIREADD2 << 16) | D_T_ERR_SYS1);
		//return( lRet );								// エラー値を返却
	}

	lRet = ptErdcTableInd->lRCode;					// 返却値としてリクエスト識別子を設定する
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	os_trcget2( D_MD_OSIREADD2, D_T_TRA_OUT, 1, lRet );
	return( lRet );									// 正常を返却
/*****	仕様変更（SSLA0019）	 End									修正日：2003.03.31	*****/
}
/************************************************************************************************/
/* End                                                                                          */
/************************************************************************************************/
