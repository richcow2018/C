/****************************************************************************/
/*  著作権  ２００２                                                        */
/*            株式会社ＮＴＴデータ                                          */
/*              金融ビジネス事業本部                                        */
/*                                                                          */
/*                                                                          */
/*  収容物  ＬＡＬａ−ＳＭＰシステム  ＴＲＡＤＥエミュレータ                */
/****************************************************************************/
/* ＜対象業務名＞                  ＴＲＡＤＥエミュレータ                   */
/* ＜対象業務ＩＤ＞                ＴＲＥ                                   */
/* ＜サービス項目名＞              ＴＣＰ/ＩＰ制御                          */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                ＴＣＰ/ＩＰの送受信スレッド              */
/* ＜モジュールＩＤ＞              os_tcpex                                 */
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
/* ＜開発システム名＞              ＸＸＸ−ＳＭＰシステム                   */
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
/* ＜ソース作成者＞                ＣＢ事ビジネス企画担当(メ−カ:サプライ)  */
/* ＜ソース作成年月日＞            ２００２年　９月２７日                   */
/* ＜ソース修正者＞                サプライ　藤里                           */
/* ＜ソース正年月日及び修正ＩＤ＞  ２００３年　６月　９日                   */
/*                                         故障管理番号（ＴＢＣＳ０１２６） */
/* ＜ソース正年月日及び修正ＩＤ＞  ２００３年　６月３０日                   */
/*                                         故障管理番号（ＴＢＣＳ０１８５） */
/* ＜ソース正年月日及び修正ＩＤ＞  ２００３年　７月　２日                   */
/*                                         故障管理番号（ＴＢＣＳ０１９４） */
/*                                         故障管理番号（ＴＢＣＳ０１９５） */
/* ＜ソース正年月日及び修正ＩＤ＞  ２００３年　７月　８日                   */
/*                                         故障管理番号（ＴＢＣＳ０２０６） */
/* ＜ソース正年月日及び修正ＩＤ＞  ２００３年　７月１７日                   */
/*                                         故障管理番号（ＴＢＣＳ０２１１） */
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞              ステップ                                 */
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞                                                             */
/*   スレッドとして起動し、TCP/IPの非同期通知要求、又はCONNECT要求を行う。  */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      #include    <os_tcpex.h>                                            */
/*                                                                          */
/*      void os_tcpex( void *arg )                                          */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      void *arg       アーギュメント域へのポインタ                        */
/*                                                                          */
/* ＜返却値＞                                                               */
/*      なし                                                                */
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
#include <errno.h>						// エラーＮｏ取得用
#include <stdio.h>
#include <unistd.h> 					// pipe,select用
#include <sys/time.h>					// FD_ZERO,FD_SET用
#include <sys/types.h>					// FD_ZERO,FD_SET用
#include <sys/socket.h> 				// socket用
#include <netinet/in.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <netdb.h>
#include <string.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "os_tcpex.h"
#include "os_tcpex_ins.h"							// 内部参照用（個別）

/*****	障害対応（KL0051）	Start					修正日：2003.04.11	*****/
//TMyMessage tMsgBuf; 								// メッセージヘッダー構造体
/*****	障害対応（KL0051）	 End					修正日：2003.04.11	*****/

/***************************** 関数プロトタイプ宣言 *************************/
long os_tcpex_karitori();				// 要求刈り取り処理
long os_tcpex_msgsnd(); 				// 完了メッセージの送信

/****************************************************************************/
/*																			*/
/*	＜関数名＞	  os_tcpex													*/
/*																			*/
/*	＜機能概要＞  TCP/IPコネクション　スレッド処理							*/
/*																			*/
/****************************************************************************/
void *os_tcpex( void *arg )
{
	int		iIdx;									// ループのIndex
	int		iCommonRet;								// 共通関数リターン値
	int		iAddrLen;								// addr構造体のバイト数 
	int		iSockDes;								// ソケット用のディスクリプタ
	short	sParentLocalSession;					// 親ローカルセション番号
	long	lCommonRet;								// 共通関数リターン値
	long	iMsgsndRet;								// 完了メッセージ送信関数リターン値
	long	lHedSize;								// read/writdヘッダサイズ
	/*****	仕様変更（KL0036）	Start				修正日：2003.03.18	*****/
	long	lReadFlg = 0;							// read要求フラグ  （0:通知なし/1:通知あり）
	long	lReadReqid = 0;							// read要求リクエスト番号
	long	lAsyncFlg = 0;							// 非同期通知フラグ（0:通知なし/1:通知あり）
	long	lAsyncReqid = 0;						// 非同期通知リクエスト番号
	/*****	仕様変更（KL0036）	 End				修正日：2003.03.18	*****/
	fd_set	fsSet;									// ディスクリプタ集合
	struct	sockaddr_in serv_addr;					// サーバソケットのアドレス(CONNECT)
	struct	sockaddr_in addr;						// サーバソケットのアドレス(ACCEPT)
	ssize_t lSndBytes;								// 一回送信成功のバイト数
	ssize_t lTotalSndBytes; 						// 現在までに全部の送信バイト数
	TTcpexArgInfo	tTcpexArgInfo;					// アーギュメント
	TArgInfo		tArgInfo; 						// 要求情報用アーギュメント
	/*****	仕様変更（SSLA0006）Start				修正日：2003.01.30	*****/
	TArgHed			tReadHed; 						// read用ヘッダ領域
	/*****	仕様変更（SSLA0006） End				修正日：2003.01.30	*****/
	/*****	障害対応（KL0051）	Start				修正日：2003.04.11	*****/
	TMyMessage tMsgBuf; 							// メッセージヘッダー構造体
	/*****	障害対応（KL0051）	 End				修正日：2003.04.11	*****/
	TEcncTableInd	*ptEcncTableTopInd = NULL;		// コネクション管理テーブル先頭個別部のアドレス
	TEcncTableInd	*ptEcncTableInd = NULL;			// コネクション管理テーブルの対象個別部
	TEcncTableInd	*ptNewEcncTableInd = NULL;		// コネクション管理テーブルの新規対象個別部
	TArgConnect		*ptArgConnect = NULL; 			// アーギュメント構成（CONNECT）
	TArgSyncInfoReq *ptArgSyncInfoReq = NULL;		// 非同期通知要求用アーギュメント

	os_trcget2( D_MD_OS_TCPEX, D_T_TRA_IN, 1, arg );

	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );


/****************************************************************************/
/* 初期処理 																*/
/****************************************************************************/
	tTcpexArgInfo = *(TTcpexArgInfo *)arg;			// アーギュメントをローカルに退避
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FREE, 1, arg );
	free( arg );									// アーギュメント域解放
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

													// コネクション管理テーブル先頭個別部の
													// アドレス取得
	ptEcncTableTopInd = (TEcncTableInd *)(ptEcnc + 1);

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableTopInd=%p )\n",
													D_PROC_NAME, ptEcncTableTopInd ) );

													// コネクションテーブルの対象個別部設定
	for( iIdx = 0; iIdx < ptEcnc->lMaxIndNum; iIdx++ )
	{
		ptEcncTableInd = ptEcncTableTopInd + iIdx;

										// コネクション管理テーブル個別部のソケットディスクリプタが
										// 引数のソケットディスクリプタと同じである個別部を検索
		if( ptEcncTableInd->lSockDes == tTcpexArgInfo.lSockDes )
		{
			break;
		}
	}

	if( iIdx == ptEcnc->lMaxIndNum )	// 同一の個別部が存在しない場合
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
															D_PROC_NAME, -1 ) );

		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS1 );
//2003.04.10		return( NULL ); 				// アボート処理
	}

	sParentLocalSession = iIdx + 1;		// 親ローカルセション番号の取得
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sParentLocalSession=%hd )\n",
													D_PROC_NAME, sParentLocalSession ) );

	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_PIPE, 1, (int *)ptEcncTableInd->alPipeDes );

										// パイプの作成
	iCommonRet = pipe( (int *)ptEcncTableInd->alPipeDes );

	if( iCommonRet == D_ERR_SYS )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "pipe", strerror(errno) ) );

		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS2 );
//2003.04.10		return( NULL ); 				// アボート処理
	}

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->alPipeDes[1]=%hd )\n",
												D_PROC_NAME, ptEcncTableInd->alPipeDes[0] ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->alPipeDes[1]=%hd )\n",
												D_PROC_NAME, ptEcncTableInd->alPipeDes[1] ) );
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );


	/****************************************/
	/*  メッセージヘッダの編集（クリア）	*/
	/****************************************/
	tMsgBuf.lMsgtype	= 0;
	tMsgBuf.pcBufAdr	= NULL;
	tMsgBuf.lDatesize	= D_DATESIZE_FIX;
	tMsgBuf.lReqid		= tTcpexArgInfo.lReqNum;
	tMsgBuf.lResult		= D_RD_NORMAL;

//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lMsgtype ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
//												D_PROC_NAME, tMsgBuf.pcBufAdr ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lDatesize ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lReqid ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lResult ) );


/****************************************************************************/
/* 本処理																	*/
/****************************************************************************/

	switch( tTcpexArgInfo.cAsyncFlg )	// 要求種別による処理の振り分け
	{
	case D_REQCLASS_ASYNC:				// 非同期通知要求の場合

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ZERO, 1, &fsSet );
		FD_ZERO( &fsSet );				// 読込み用ディスクリプタ集合初期化
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );
		
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );
										// ディスクリプタ集合にパイプ用ディスクリプタ
										// 読み込みチャネル側を加える
		FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->lSockDes, &fsSet );
										// ディスクリプタ集合に引数の
										// 対象個別部のソケットディスクリプタを加える
		FD_SET( ptEcncTableInd->lSockDes, &fsSet );	   
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		while(1)
		{
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, NULL );
										// ディスクリプタ状態変化待ち
			iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, NULL); 
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet == D_ERR_SYS )
			{
//				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
//											D_PROC_NAME, -1, "select", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS3 );
//2003.04.10				return( NULL ); 		// アボート処理
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->alPipeDes[0], &fsSet );
										// パイプ用ディスクリプタ状態変化確認
			iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet != 0 )		// --- パイプからの読み込み処理(非同期通知要求) ---
			{
				lTotalSndBytes = 0;
				lSndBytes = 0;

				while( lTotalSndBytes < sizeof(TArgInfo) )
				{
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, 
							ptEcncTableInd->alPipeDes[0],
									 (void *)&tArgInfo + lTotalSndBytes,
									  sizeof(TArgInfo) - lTotalSndBytes );
										// パイプ用ディスクリプタからの読込
					lSndBytes = read( ptEcncTableInd->alPipeDes[0],
									 (void *)&tArgInfo + lTotalSndBytes,
									  sizeof(TArgInfo) - lTotalSndBytes );
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

										// パイプ用ディスクリプタからの読込に失敗した時
					if( lSndBytes == D_ERR_SYS )
					{
										// errno がEINTRでない時
						if( errno != EINTR )
						{				
							DbgMsg01( DLv05, ( OutPut, 
									"***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "read", strerror(errno) ) );

										// アボート処理
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                       (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS4 );
//2003.04.10							return( NULL );
						}
					}
					else				// パイプ用ディスクリプタからの読込に成功した時
					{
										// 全部の送信バイト数に今回の分をインクリメント
						lTotalSndBytes += lSndBytes;
					}
				}

										// 要求種別による処理の振り分け
				switch( tArgInfo.cRecClass )
				{
				case D_REQCLASS_READ:	// read要求
/*****	故障管理番号TBCS0206の対応		Start							修正日：2003.07.08	*****/
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE23;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid   = ptEcncTableInd->tReaInfo.lReqNum;
													// コネクション未設定
					tMsgBuf.lResult  = D_RESULT_NOTCONNECT;
/*****	故障管理番号TBCS0206の対応		 End							修正日：2003.07.08	*****/

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();	// 完了メッセージ送信
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
					/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS5 );
//2003.04.10						return( NULL ); // アボート
					}
					break;

				case D_REQCLASS_WRITE:	// write要求
/*****	故障管理番号TBCS0206の対応		Start							修正日：2003.07.08	*****/
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE24;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid   = tArgInfo.ulReqNum;
													// コネクション未設定
					tMsgBuf.lResult  = D_RESULT_NOTCONNECT;
/*****	故障管理番号TBCS0206の対応		 End							修正日：2003.07.08	*****/

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

				/*****	障害対応（KL0051）	Start			修正日：2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// 完了メッセージ送信
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	障害対応（KL0051）	 End			修正日：2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS6 );
//2003.04.10						return( NULL ); // アボート
					}
					break;

										// 非同期通知キャンセル要求
				case D_REQCLASS_ASYNC_CANCEL:
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( 非同期通知要求キャンセル )\n",
																				D_PROC_NAME ) );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );

										// パイプ用ディスクリプタ読込用クローズ
					iCommonRet = close( ptEcncTableInd->alPipeDes[0] );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

					if( iCommonRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS7 );
//2003.04.10						return( NULL ); // アボート処理
					}

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );

										// パイプ用ディスクリプタ書込用クローズ
					iCommonRet = close( ptEcncTableInd->alPipeDes[1] );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

					if( iCommonRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS8 );
//2003.04.10						return( NULL ) ;// アボート処理
					}

										// コネクション管理テーブル個別対象部の
										// パイプ用ディスクリプタを0クリア
					ptEcncTableInd->alPipeDes[0] = 0;
					ptEcncTableInd->alPipeDes[1] = 0;

					os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
					return( NULL ); 	// スレッド終了
					break;

				/*****	仕様変更（SSLA0014）Start	修正日：2003.02.17	*****/
//				default:
//					break;				// 何もしない

				case D_REQCLASS_DETACH: 			// DETACH要求
				case D_REQCLASS_DCONN: 				// DISCONNECT要求
				case D_REQCLASS_ABORT:				// ABORT要求
					while(1)
					{
													// 対象個別部のソケットディスクリプタクローズ
						os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->lSockDes );
						iCommonRet = close( ptEcncTableInd->lSockDes );
						os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

													// close失敗
						if( iCommonRet == D_ERR_SYS )
						{
							if( errno == EINTR )	// errno がEINTRの時
							{
								continue;			// リトライ処理へ
							}
							else					// errno がEINTRでない時
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                                os_treterm(os_EndCod(D_END_TYPE1), 
                                           (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS9 );
//2003.04.10								return( NULL );		// アボート処理
							}
						}
						else						// close成功
						{
/*****	故障管理番号TBCS0194の対応		Start							修正日：2003.07.02	*****/
													// 対象個別部のソケットディスクリプタクリア
							ptEcncTableInd->lSockDes = 0;
/*****	故障管理番号TBCS0194の対応		 End							修正日：2003.07.02	*****/
							break;
						}
					}

					/*****	障害対応（KL0036）Start	修正日：2003.03.18	*****/
					/********************************************************/
					/* 刈取り処理を行った後に、完了メッセージを送信する		*/
					/* ように修正											*/
					/********************************************************/
					/********************************************/
					/*  非同期通知要求の判定					*/
					/********************************************/
													// 対象個別部の非同期通知フラグ=ONの場合
					if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
					{
						lAsyncFlg = 1;				// 非同期通知フラグを設定
													// 非同期通知リクエスト番号を退避
						lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
					}

					/********************************/
					/*  要求刈り取り処理			*/
					/********************************/
					lCommonRet = os_tcpex_karitori( ptEcncTableInd );
					if( lCommonRet !=0 )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
/*****	故障管理番号TBCS0195の対応		Start							修正日：2003.07.02	*****/
//						return( NULL );				// アボート
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS48);
/*****	故障管理番号TBCS0195の対応		 End							修正日：2003.07.02	*****/
					}

					/********************************************/
					/*  当該コネクション管理テーブルのクリア	*/
					/*  （パイプ用ディスクリプタを除く）		*/
					/********************************************/
					ptEcncTableInd->lSockDes			= 0;
					ptEcncTableInd->sParentLocalSession	= 0;
					ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
					ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
					ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
					ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
					memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
					memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
					memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );

					/********************************************/
					/*  非同期通知処理							*/
					/********************************************/
					if (1 == lAsyncFlg)				// 非同期通知フラグが「１（通知あり）」の場合
					{
						/********************************/
						/*  メッセージヘッダの編集		*/
						/********************************/
						tMsgBuf.lMsgtype = D_MTYPE22;
						tMsgBuf.pcBufAdr = NULL;
						tMsgBuf.lReqid =  lAsyncReqid;
													// 切断によるキャンセル
						tMsgBuf.lResult = D_RESULT_CUTCANCEL;

						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

						/********************************/
						/*  メッセージの送信			*/
						/********************************/
				/*****	障害対応（KL0051）	Start			修正日：2003.04.11	*****/
//						iMsgsndRet = os_tcpex_msgsnd();	// 完了メッセージ送信
						iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	障害対応（KL0051）	 End			修正日：2003.04.11	*****/

						if( iMsgsndRet == D_ERR_SYS )
						{
							DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                      (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS10);
//2003.04.10							return( NULL );			// アボート
						}
					}

					/********************************************/
					/*  完了メッセージ送信処理					*/
					/********************************************/
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = tArgInfo.ulReqNum;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  メッセージの送信			*/
					/********************************/
				/*****	障害対応（KL0051）	Start			修正日：2003.04.11	*****/
//						iMsgsndRet = os_tcpex_msgsnd();	// 完了メッセージ送信
						iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	障害対応（KL0051）	 End			修正日：2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )	// 異常の場合
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS11);
//2003.04.10						return( NULL ); 			// アボート
					}
					/*****	障害対応（KL0036） End	修正日：2003.03.18	*****/

					os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
					return( NULL ); 				// スレッド終了
					break;
				/*****	仕様変更（SSLA0014） End	修正日：2003.02.17	*****/
				}
				continue;							// 処理要求に戻る
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->lSockDes, &fsSet );
													// ソケットディスクリプタ状態変化確認
			iCommonRet = FD_ISSET( ptEcncTableInd->lSockDes, &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet != 0 )					// --- 接続要求の受入れ処理(非同期通知要求) ---
			{
				for( iIdx = 0; iIdx < ptEcnc->lMaxIndNum; iIdx++ )
				{
													// コネクションテーブルの対象新規個別部設定
					ptNewEcncTableInd = ptEcncTableTopInd + iIdx;
										// コネクション管理テーブル個別部のソケットディスクリプタが
										// 0である個別部を検索
					if( ptNewEcncTableInd->lSockDes == 0 )
					{
						break;
					}
				}
										// 「ソケットディスクリプタ」が0の個別部が存在しない場合
				if( iIdx == ptEcnc->lMaxIndNum )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_ERR_NOBUF );
/*****	故障管理番号TBCS0211の対応		Start							修正日：2003.07.17	*****/
/************************************************************************************************/
/*	対象のコネクション管理テーブル個別部が存在しない場合はリザルトにて							*/
/*	「バッファ不足」を返却するように修正														*/
/************************************************************************************************/
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
					tMsgBuf.lResult = D_ERR_NOBUF;	// バッファ不足

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  非同期通知要求情報クリア	*/
					/********************************/
													// 非同期通知フラグにOFFを設定
					ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
													// 非同期通知要求情報クリア
					memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );

					/********************************/
					/*  メッセージの送信			*/
					/********************************/
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
					if( iMsgsndRet == D_ERR_SYS )		// メッセージ送信が異常の場合
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, iMsgsndRet );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS12);
					}

					return;							// スレッド終了
/*****	故障管理番号TBCS0211の対応		End								修正日：2003.07.17	*****/
				}

										// 接続処理
				iAddrLen = sizeof(addr);
				
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_ACCEPT, 3, ptEcncTableInd->lSockDes,
								   (struct sockaddr *)&addr,
								   &iAddrLen );
				iSockDes = accept( ptEcncTableInd->lSockDes,
								   (struct sockaddr *)&addr,
								   &iAddrLen ); 
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iSockDes );

				if( iSockDes < 0 )
				{
					goto err_tcpex_accept;
				}

				/************************************************/
				/*  コネクションテーブルの対象新規個別部更新	*/
				/************************************************/
										// ソケットディスクリプタに
										// 取得したソケットディスクリプタを設定
				ptNewEcncTableInd->lSockDes = iSockDes;
										// 「S/Cフラグ」に'S'を設定
//				ptNewEcncTableInd->cSCFlg = D_SCINFO_SERVER;
										// 「S/Cフラグ」に'C'を設定
				ptNewEcncTableInd->cSCFlg = D_SCINFO_CLIENT;
				ptNewEcncTableInd->alPipeDes[0] = ptEcncTableInd->alPipeDes[0];
				ptNewEcncTableInd->alPipeDes[1] = ptEcncTableInd->alPipeDes[1];

				ptEcncTableInd->alPipeDes[0] = 0;
				ptEcncTableInd->alPipeDes[1] = 0;

				DbgMsg01(DLv04,( OutPut,"***** %s: Display ( ptNewEcncTableInd->lSockDes=%ld )\n",
													D_PROC_NAME, ptNewEcncTableInd->lSockDes ) );
				DbgMsg01( DLv04, ( OutPut,"***** %s: Display ( ptNewEcncTableInd->cSCFlg=%hhd )\n",
													D_PROC_NAME, ptNewEcncTableInd->cSCFlg ) );
				DbgMsg01( DLv04, ( OutPut,
						"***** %s: Display ( ptNewEcncTableInd->alPipeDes[0]=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->alPipeDes[0] ) );
				DbgMsg01( DLv04, ( OutPut,
						"***** %s: Display ( ptNewEcncTableInd->alPipeDes[1]=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->alPipeDes[1] ) );

				/****************************************************/
				/*  対象新規個別部「パイプ用ディスクリプタ」に		*/
				/*  対象個別部「パイプ用ディスクリプタ」を移管する	*/
				/****************************************************/
										// 「ACCEPT中状態」にACCEPT中を設定
				ptNewEcncTableInd->cAcceptStat = D_ACCEPTSTAT_ON;
										// 「親ローカルセッション番号」に
										// 対象個別部のローカルセッション番号を設定
				ptNewEcncTableInd->sParentLocalSession = sParentLocalSession;
										// 「ポート番号」に取得したポート番号を設定
				ptNewEcncTableInd->tConnInfo.lPort = ntohs(addr.sin_port);
										// 「アドレス」に取得したアドレスを設定
				ptNewEcncTableInd->tConnInfo.lIPAdr = ntohl(addr.sin_addr.s_addr );
										// 非同期通知要求用アーギュメント構造体に
										// コネクションテーブル対象個別部
										// 非同期通知要求情報の引数情報１を設定
				ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;
										// コネクションテーブル対象個別部更新
										// 非同期通知要求情報の引数情報１の
										// 0ビット目をONに設定
				ptArgSyncInfoReq->sDetailInfo |= 0x01;

				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->cAcceptStat=%hhd )\n",
						D_PROC_NAME, ptNewEcncTableInd->cAcceptStat ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->sParentLocalSession=%hd )\n",
						D_PROC_NAME, ptNewEcncTableInd->sParentLocalSession ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->tConnInfo.lPort=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->tConnInfo.lPort ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->tConnInfo.lIPAdr=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->tConnInfo.lIPAdr ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
															D_PROC_NAME, ptArgSyncInfoReq ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
						D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );

				/*****	障害対応（KL0036）Start	修正日：2003.03.18	*****/
				/********************************************************/
				/* 完了メッセージの送信を最後に行うように修正			*/
				/********************************************************/
				/********************************/
				/*  メッセージヘッダの編集		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

													// コネクションテーブル対象個別部更新
													// 非同期通知フラグにOFFを設定
				ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
				ptEcncTableInd = ptNewEcncTableInd;	// 対象新規個別部を対象個別部とする

				/********************************/
				/*  メッセージの送信			*/
				/********************************/
				/*****	障害対応（KL0051）	Start			修正日：2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();				// 完了メッセージ送信
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	障害対応（KL0051）	 End			修正日：2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS13);
//2003.04.10					return( NULL ); 				// アボート
				}
				/*****	障害対応（KL0036） End	修正日：2003.03.18	*****/
				break;					// Loopを抜ける -> 処理要求／接続先状態の監視処理へ
			}
		}
		break;

	case D_REQCLASS_CONN: 				// 要求種別がCONNECT要求の場合

		memset( &serv_addr, 0,	sizeof(serv_addr) );
										// 構造体初期化
										
		serv_addr.sin_family = PF_INET;
										// プロトコルファミリに「AF_INET」を設定
		ptArgConnect = (TArgConnect *)tTcpexArgInfo.pcPara1;
										// CONNECTのアーギュメント域ポインタ取得
										
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_HTONS, 1, ptArgConnect->sRemotePortNo );
		serv_addr.sin_port = htons(ptArgConnect->sRemotePortNo);
										// ポート番号にアーギュメント域の
										// リモートポート番号を設定
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, serv_addr.sin_port );
										
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_HTONL, 1, ptArgConnect->lRemoteAddr );
		serv_addr.sin_addr.s_addr  = htonl(ptArgConnect->lRemoteAddr);
										// アドレスにアーギュメント域の
										// リモートアドレスを設定
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, serv_addr.sin_addr.s_addr );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CONNECT, 3, ptEcncTableInd->lSockDes, 
							  (const struct sockaddr *)&serv_addr, 
							  sizeof(serv_addr) );
		iCommonRet = connect( ptEcncTableInd->lSockDes, 
							  (const struct sockaddr *)&serv_addr, 
							  sizeof(serv_addr) );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		if(iCommonRet == D_ERR_SYS)
		{
										// メッセージヘッダの編集
//			tMsgBuf.lMsgtype = D_MTYPE22;
//			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
//														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, iCommonRet, errno);
			goto err_tcpex_connect;		// エラー処理へ
		}

										// コネクション管理テーブル対象個別部
										// ポート番号設定
		ptEcncTableInd->tConnInfo.lPort = serv_addr.sin_port;
										// コネクション管理テーブル対象個別部
										// アドレス設定
		ptEcncTableInd->tConnInfo.lIPAdr = serv_addr.sin_addr.s_addr;
										// コネクション管理テーブル対象個別部
										// S/Cフラグ設定
		ptEcncTableInd->cSCFlg = D_SCINFO_CLIENT;

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tConnInfo.lPort=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->tConnInfo.lPort ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tConnInfo.lIPAdr=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->tConnInfo.lIPAdr ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->cSCFlg=%hhd )\n",
													D_PROC_NAME, ptEcncTableInd->cSCFlg ) );

		tMsgBuf.lMsgtype = D_MTYPE22;	// メッセージヘッダの編集
		tMsgBuf.lResult = D_RD_NORMAL;	// メッセージヘッダの編集

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
													D_PROC_NAME, tMsgBuf.lMsgtype ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
													D_PROC_NAME, tMsgBuf.lReqid ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
													D_PROC_NAME, tMsgBuf.lResult ) );

		/*****	障害対応（KL0051）	Start			修正日：2003.04.11	*****/
//		iMsgsndRet = os_tcpex_msgsnd();				// 完了メッセージ送信
		iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
		/*****	障害対応（KL0051）	 End			修正日：2003.04.11	*****/

		if( iMsgsndRet == D_ERR_SYS )
		{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS14);
//2003.04.10			return( NULL ); 			// アボート
		}
										// --- 処理要求／接続先状態の監視処理へ ---
		break;
		
	default:
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
															D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS15);
//2003.04.10		return( NULL ) ;				// アボート処理
	}

	while(1)							// --- 処理要求／接続先状態の監視 ---
	{
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ZERO, 1, &fsSet );
		FD_ZERO( &fsSet );				// 読込み用ディスクリプタ集合初期化
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );
										// ディスクリプタ集合にパイプ用ディスクリプタ
										// 読み込みチャネル側を加える
		FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );	
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );


		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->cReadStat=%02x )\n",
												D_PROC_NAME, ptEcncTableInd->cReadStat ) );

										// コネクション管理テーブル対象個別部
										// resd要求状態が「済」の場合
		if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ソケットの変化も監視する )\n",
																		D_PROC_NAME ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->lSockDes=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->lSockDes ) );

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->lSockDes, &fsSet );
										// ディスクリプタ集合に対象個別部の
										// ソケットディスクリプタを加える
			FD_SET( ptEcncTableInd->lSockDes, &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );
			
		}

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, NULL );
										// ディスクリプタ状態変化待ち
		iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, NULL ); 
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
		
		if( iCommonRet == D_ERR_SYS )
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "select", strerror(errno) ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS16);
//2003.04.10			return( NULL ); 			// アボート処理
		}

		/********************************/
		/*  パイプからの状態変化		*/
		/********************************/
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, ptEcncTableInd->alPipeDes[0], &fsSet );
													// パイプ用ディスクリプタ状態変化確認
		iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		if( iCommonRet != 0 )						// パイプからの読み込み処理(CONNECT要求)
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( パイプからの状態変化確認 )\n",
																		D_PROC_NAME ) );

			lTotalSndBytes = 0;
			lSndBytes = 0;
													// パイプ用ディスクリプタからの読込
			while( lTotalSndBytes < sizeof(TArgInfo) )
			{
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, ptEcncTableInd->alPipeDes[0],
								 (void *)&tArgInfo + lTotalSndBytes,
								  sizeof(TArgInfo) - lTotalSndBytes );
				lSndBytes = read( ptEcncTableInd->alPipeDes[0],
								 (void *)&tArgInfo + lTotalSndBytes,
								  sizeof(TArgInfo) - lTotalSndBytes );
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

				if( lSndBytes == D_ERR_SYS )		// パイプ用ディスクリプタからの読込に失敗した時
				{
					if( errno != EINTR )			// errno がEINTRでない時
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "read", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL, errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS17);
//2003.04.10						return( NULL );				// アボート処理
					}
				}
				else								// パイプ用ディスクリプタからの読込に成功した時
				{
					lTotalSndBytes += lSndBytes;	// 全部の送信バイト数に今回の分をインクリメント
				}
			}

			switch( tArgInfo.cRecClass )
			{										// 要求状態による処理の振り分け
			case D_REQCLASS_READ:					// read要求
													// 監視状態の継続(何もしない)
				break;

			case D_REQCLASS_WRITE:					// write要求
				/********************************/
				/*  write処理					*/
				/********************************/
				lTotalSndBytes = 0;
				lSndBytes = 0;

				/*****	仕様変更（SSLA0006）Start	修正日：2003.01.30	*****/
//				while( lTotalSndBytes < (long)tArgInfo.pvArg2 )
				while( lTotalSndBytes < ((long)tArgInfo.pvArg2 - sizeof(TArgHed)) )
				/*****	仕様変更（SSLA0006） End	修正日：2003.01.30	*****/
				{
													// write要求送信
													// (対象個別部ソケットディスクリプタ)
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_WRITE, 3, 
												ptEcncTableInd->lSockDes, 
								(void *)((long)tArgInfo.pvArg1 + sizeof(TArgHed)) + lTotalSndBytes,
								((long)tArgInfo.pvArg2 - sizeof(TArgHed)) - lTotalSndBytes );

					/*****	仕様変更（SSLA0006）Start	修正日：2003.01.30	*****/
//					lSndBytes = write( ptEcncTableInd->lSockDes, 
//									  (void *)tArgInfo.pvArg1 + lTotalSndBytes, 
//									  (long)tArgInfo.pvArg2 - lTotalSndBytes );
					lSndBytes = write( ptEcncTableInd->lSockDes, 
								(void *)((long)tArgInfo.pvArg1 + sizeof(TArgHed)) + lTotalSndBytes,
								((long)tArgInfo.pvArg2 - sizeof(TArgHed)) - lTotalSndBytes );
					/*****	仕様変更（SSLA0006） End	修正日：2003.01.30	*****/

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%ld )\n",
															D_PROC_NAME, lSndBytes ) );

					if( lSndBytes == D_ERR_SYS )	// write要求送信に失敗した時
					{
						if( errno == EINTR )		// errno がEINTRの時
						{
							continue;				// リトライ処理へ
						}
													// errno がECONNRESETの時
						else if( errno == ECONNRESET )
						{
							while(1)
							{
								os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, 
														ptEcncTableInd->lSockDes );
													// 対象個別部のソケットディスクリプタクローズ
								iCommonRet = close( ptEcncTableInd->lSockDes );

								os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
													// close失敗
								if( iCommonRet == D_ERR_SYS )
								{
													// errno がEINTRの時
									if( errno == EINTR )
									{
										continue;
									}
									else			// errno がEINTRでない時
									{	
										DbgMsg01( DLv05, ( OutPut,
												"***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
												D_PROC_NAME, -1, "close", strerror(errno) ) );

													// アボート処理
										os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1,NULL );
                                        os_treterm(os_EndCod(D_END_TYPE1), 
                                                  (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS18);
//2003.04.10										return( NULL );
									}
								}
								else				// close成功
								{
													// 対象個別部のソケットディスクリプタクリア
//									ptEcncTableInd->lSockDes = 0;
									break;
								}
							}

							/*****	障害対応（KL0036）Start	修正日：2003.03.18	*****/
							/********************************************************/
							/* 刈取り処理を行った後に、完了メッセージを送信する		*/
							/* ように修正											*/
							/********************************************************/
							/********************************************/
							/*  read要求情報の設定						*/
							/********************************************/
													// 対象個別部のread要求状態=ONの場合
							if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
							{
								lReadFlg = 1;		// read要求フラグを設定
													// read要求リクエスト番号を退避
								lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;
							}

							/********************************************/
							/*  コネクション切断の設定					*/
							/********************************************/
													// 対象個別部の非同期通知フラグ=ONの場合
							if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
							{
								lAsyncFlg = 1;		// 非同期通知フラグを設定
													// 非同期通知リクエスト番号を退避
								lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// 非同期通知要求用アーギュメント構造体に
													// コネクションテーブル対象個別部
													// 非同期通知要求情報の引数情報１を設定
								ptArgSyncInfoReq =
									(TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// コネクションテーブル対象個別部更新
													// 非同期通知要求情報の引数情報１の
													// コネクション切断をONに設定
								ptArgSyncInfoReq->sDetailInfo |= 0x02;

								DbgMsg01( DLv04, ( OutPut,
									"***** %s: Display ( ptArgSyncInfoReq=%p )\n",
									D_PROC_NAME, ptArgSyncInfoReq ) );
								DbgMsg01( DLv04, ( OutPut,
							 		"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
									D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
							}

							/********************************************/
							/*  要求刈り取り処理						*/
							/********************************************/
							lCommonRet = os_tcpex_karitori( ptEcncTableInd );
							if( lCommonRet !=0 )
							{
								DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
								os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                os_treterm(os_EndCod(D_END_TYPE1), 
                                          (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS19);
//2003.04.10								return( NULL );
							}

							/********************************************/
							/*  read要求通知処理						*/
							/********************************************/
							if (1 == lReadFlg)		// read要求フラグが「１（通知あり）」の場合
							{
								/********************************/
								/*  メッセージヘッダの編集		*/
								/********************************/
								tMsgBuf.lMsgtype = D_MTYPE23;
								tMsgBuf.pcBufAdr = NULL;
								tMsgBuf.lReqid = lReadReqid;
								tMsgBuf.lResult = D_RESULT_DISCONNECT;

								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
										D_PROC_NAME, tMsgBuf.lMsgtype ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
										D_PROC_NAME, tMsgBuf.lReqid ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lResult=%ld )\n",
										D_PROC_NAME, tMsgBuf.lResult ) );

								/********************************/
								/*  メッセージの送信			*/
								/********************************/
								/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//								iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
								iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
								/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

								if( iMsgsndRet == D_ERR_SYS ) 
								{
									DbgMsg01(DLv05,( OutPut, "***** %s: Err Function 17: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
									os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                    os_treterm(os_EndCod(D_END_TYPE1), 
                                              (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS20);
//2003.04.10									return( NULL );
								 		// アボート
								}
							}

							/********************************************/
							/*  非同期通知（コネクション切断）処理		*/
							/********************************************/
							if (1 == lAsyncFlg)		// 非同期通知フラグが「１（通知あり）」の場合
							{
								/********************************/
								/*  メッセージヘッダの編集		*/
								/********************************/
								tMsgBuf.lMsgtype = D_MTYPE22;
								tMsgBuf.pcBufAdr = NULL;
								tMsgBuf.lReqid = lAsyncReqid;
								tMsgBuf.lResult = D_RD_NORMAL;

								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
										D_PROC_NAME, tMsgBuf.lMsgtype ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
										D_PROC_NAME, tMsgBuf.lReqid ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lResult=%ld )\n",
										D_PROC_NAME, tMsgBuf.lResult ) );

								/********************************/
								/*  メッセージの送信			*/
								/********************************/
								/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//								iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
								iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
								/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

								if( iMsgsndRet == D_ERR_SYS ) 
								{
									DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 18: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
													// アボート
									os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                    os_treterm(os_EndCod(D_END_TYPE1), 
                                               (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS21 );
//2003.04.10									return( NULL );
								}
							}
													// スレッドの終了
							os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
							return( NULL );
						}
						else						// errno がEINTR,ECONNRESETでない時
						{
							DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 19: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
													// アボート処理
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                      (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS22 );
//2003.04.10							return( NULL );
						}
					}

					lTotalSndBytes += lSndBytes;	// 全部の送信バイト数に今回の分をインクリメント
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lTotalSndBytes=%d )\n",
																D_PROC_NAME, lTotalSndBytes ) );
				}

				/********************************/
				/*  メッセージヘッダの編集		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE24;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = tArgInfo.ulReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 20: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS23);
//2003.04.10					return( NULL ); 	// アボート
				}
				break;

			case D_REQCLASS_DETACH: 	// DETACH要求
			case D_REQCLASS_DCONN: 		// DISCONNECT要求
			case D_REQCLASS_ABORT:		// ABORT要求
				while(1)
				{
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->lSockDes );
										// 対象個別部のソケットディスクリプタクローズ
					iCommonRet = close( ptEcncTableInd->lSockDes );
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

										// close失敗
					if( iCommonRet == D_ERR_SYS )
					{
										// errno がEINTRの時
						if( errno == EINTR )
						{
							continue;
						}
						else			// errno がEINTRでない時
						{
							DbgMsg01( DLv05, ( OutPut,
									"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "close", strerror(errno) ) );

										// アボート処理
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                   (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS24 );
//2003.04.10							return( NULL );
						}
					}
					else							// close成功
					{
													// 対象個別部のソケットディスクリプタクリア
//						ptEcncTableInd->lSockDes = 0;
						break;
					}
				}

				/*****	障害対応（KL0036）Start	修正日：2003.03.18	*****/
				/********************************************************/
				/* 刈取り処理を行った後に、完了メッセージを送信する		*/
				/* ように修正											*/
				/********************************************************/
				/********************************************/
				/*  read要求情報の設定						*/
				/********************************************/
													// read要求状態が「ON」の場合
				if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
				{
					lReadFlg = 1;					// read要求フラグを設定
													// read要求リクエスト番号を退避
					lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;
				}

				/********************************************/
				/*  コネクション切断の設定					*/
				/********************************************/
													// 対象個別部の非同期通知フラグ=ONの場合
				if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
				{
					lAsyncFlg = 1;					// 非同期通知フラグを設定
													// 非同期通知リクエスト番号を退避
					lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// 非同期通知要求用アーギュメント構造体に
													// コネクションテーブル対象個別部
													// 非同期通知要求情報の引数情報１を設定
					ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// コネクションテーブル対象個別部更新
													// 非同期通知要求情報の引数情報１の
													// コネクション切断をONに設定
					ptArgSyncInfoReq->sDetailInfo |= 0x02;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
																D_PROC_NAME, ptArgSyncInfoReq ) );
					DbgMsg01( DLv04, ( OutPut, 
							"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
							D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
				}

				/********************************************/
				/*  要求刈り取り処理						*/
				/********************************************/
				lCommonRet = os_tcpex_karitori( ptEcncTableInd );

				if( lCommonRet !=0 )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS25);
//2003.04.10					return( NULL );
				}

				/********************************************/
				/*  当該コネクション管理テーブルのクリア	*/
				/*  （パイプ用ディスクリプタを除く）		*/
				/********************************************/
				ptEcncTableInd->lSockDes			= 0;
				ptEcncTableInd->sParentLocalSession	= 0;
				ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
				ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
				ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
				ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
				memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
				memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );

				/********************************************/
				/*  read要求通知処理						*/
				/********************************************/
				if (1 == lReadFlg)					// read要求フラグが「１（通知あり）」の場合
				{
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE23;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = lReadReqid;
					tMsgBuf.lResult = D_RESULT_DISCONNECT;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  メッセージの送信			*/
					/********************************/
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/
					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 23: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS26);
//2003.04.10						return( NULL ); // アボート
					}
				}

				/********************************************/
				/*  非同期通知（コネクション切断）処理		*/
				/********************************************/
				if (1 == lAsyncFlg)					// 非同期通知フラグが「１（通知あり）」の場合
				{
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid =  lAsyncReqid;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  メッセージの送信			*/
					/********************************/
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS27);
//2003.04.10						return( NULL ); // アボート
					}
				}

				/********************************************/
				/*  完了メッセージ送信処理					*/
				/********************************************/
				/********************************/
				/*  メッセージヘッダの編集		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = tArgInfo.ulReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/********************************/
				/*  メッセージの送信			*/
				/********************************/
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS28);
//2003.04.10					return( NULL ); 				// アボート
				}
				/*****	障害対応（KL0036） End	修正日：2003.03.18	*****/

				os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
				return( NULL ); 					// スレッドの終了
				break;

										// READ要求キャンセル
			case D_REQCLASS_READ_CANCEL:
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( READ要求キャンセル )\n",
																			D_PROC_NAME ) );
										// 対象個別部read要求状態OFF設定
				ptEcncTableInd->cReadStat = D_READSTAT_OFF;
										// 対象個別部read要求情報クリア
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
				break;

										// 非同期通知キャンセル要求
			case D_REQCLASS_ASYNC_CANCEL:
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( 非同期通知要求キャンセル要求 )\n",
																			D_PROC_NAME ) );
										// 対象個別部非同期通知フラグOFF設定
				ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
										// 対象個別部非同期通知要求情報クリア
				memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
				break;

			default:
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 26: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS29);
//2003.04.10				return( NULL ); 		// アボート処理
			}
			continue;					// 処理要求／接続先状態の監視に戻る
		}

		/********************************/
		/*  ソケットからの状態変化		*/
		/********************************/
													// ソケットディスクリプタ状態変化確認
//		iCommonRet = FD_ISSET( tTcpexArgInfo.lSockDes, &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, ptEcncTableInd->lSockDes, &fsSet );
		iCommonRet = FD_ISSET( ptEcncTableInd->lSockDes, &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=%ld )\n",
														D_PROC_NAME, iCommonRet ) );

		if( iCommonRet != 0 )						// --- 接続要求の受入れ処理(CONNECT要求) ---
		{											// 「ソケット」の状態変化後の処理

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ソケットからの状態変化確認 )\n",
																		D_PROC_NAME ) );
			/*****	仕様変更（SSLA0006）	Start	修正日：2003.01.30	*****/
			/********************************/
			/*  read用ヘッダ情報編集		*/
			/********************************/
													// アドレスファミリー識別子を設定
			tReadHed.sAddrFamilyId = D_ADRFAMILY_ID;
			tReadHed.sRtPortNo = D_RTPORT_NO;		// リモートポート番号を設定
			tReadHed.lRtIenetAddr = D_RTIENET_ADDR;	// リモートインターネットアドレスを設定
													// リザーブを設定
			memset(tReadHed.acReserve, 0, sizeof(tReadHed.acReserve));

													// read用バッファにヘッダ情報をコピー
			memcpy(ptEcncTableInd->tReaInfo.pcPara1, &tReadHed, sizeof(TArgHed)); 
			lHedSize = sizeof(TArgHed);				// read用ヘッダサイズを設定
			/*****	仕様変更（SSLA0006）	 End	修正日：2003.01.30	*****/

			/********************************/
			/*  read処理					*/
			/********************************/
			lSndBytes = 0;
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, ptEcncTableInd->lSockDes,
					  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
							  ptEcncTableInd->tReaInfo.lPara2 );

			for( ; ; )
			{
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ソケットからのデータ読込み )\n",
																		D_PROC_NAME ) );

													// 対象個別部ソケットディスクリプタからの読込
				/*****	仕様変更（SSLA0006）Start	修正日：2003.01.30	*****/
//				lSndBytes = read( ptEcncTableInd->lSockDes,
//								  ptEcncTableInd->tReaInfo.pcPara1,
//								  ptEcncTableInd->tReaInfo.lPara2 );
				/*****	障害対応（TBCS0126）Start	修正日：2003.06.09	*****/
//				lSndBytes = read( ptEcncTableInd->lSockDes,
//								  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
//								  ptEcncTableInd->tReaInfo.lPara2 );
				lSndBytes = read( ptEcncTableInd->lSockDes,
								  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
								  (ptEcncTableInd->tReaInfo.lPara2  - sizeof(TArgHed)));
				/*****	障害対応（TBCS0126） End	修正日：2003.06.09	*****/
				/*****	仕様変更（SSLA0006） End	修正日：2003.01.30	*****/

				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%ld )\n",
															D_PROC_NAME, lSndBytes ) );

										// 対象個別部ソケットディスクリプタからの読込に失敗した時
				if( lSndBytes == D_ERR_SYS )
				{
					/*****	障害対応（TBCA0029）Start		修正日：2003.04.24	*****/
					if( ECONNRESET == errno )		// errnoがECONNRESETの場合
					{
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, D_ERR_SYS, errno );
						lSndBytes = 0;				// リードサイズに「0」を設定
					}
					/*****	障害対応（TBCA0029） End		修正日：2003.04.24	*****/
					else if( EINTR != errno )		// errnoがEINTR以外の場合
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 27: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "read", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL, errno );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS30);
//2003.04.10						return( NULL );				// アボート処理
					}
				}
				else					// 対象個別部ソケットディスクリプタからの読込に成功した時
				{
					break;
				}
			}

			if( lSndBytes >= 1 )		// 正常
			{
				/********************************/
				/*  メッセージヘッダの編集		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE23;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tReaInfo.lReqNum;
				/*****	仕様変更（SSLA0006）Start	修正日：2003.01.30	*****/
//				tMsgBuf.lResult = D_RD_NORMAL;
				tMsgBuf.lResult = lHedSize + lSndBytes;
				/*****	仕様変更（SSLA0006） End	修正日：2003.01.30	*****/

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/*****	故障処理票KL0018対応 Start	修正日：2003.02.19	*****/
				/************************************************************/
				/*  完了メッセージを送信前に、コネクション管理テーブルの	*/
				/*  対象個別部を編集するように修正							*/
				/************************************************************/

				/************************************************/
				/*  対象コネクション管理テーブル個別部の編集	*/
				/************************************************/
										// read要求状態をOFF
				ptEcncTableInd->cReadStat = D_READSTAT_OFF;
										// read要求情報をクリア
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 28: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS31);
//2003.04.10					return( NULL ); 	// アボート
				}
				/*****	故障処理票KL0018対応  End	修正日：2003.02.19	*****/

				continue;				// 監視状態の継続
			}
			else if( lSndBytes == 0 )	// 読み込んだデータが「0」の場合
			{
				/*****	障害対応（KL0036）Start	修正日：2003.03.18	*****/
				/********************************************************/
				/* 刈取り処理を行った後に、完了メッセージを送信する		*/
				/* ように修正											*/
				/********************************************************/
				/********************************************/
				/*  read要求情報の設定						*/
				/********************************************/
													// read要求リクエスト番号を退避
				lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;

				/********************************************/
				/*  コネクション切断の設定					*/
				/********************************************/
										// 対象個別部の非同期通知フラグ=ONの場合
				if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
				{
					lAsyncFlg = 1;					// 非同期通知フラグを設定
													// 非同期通知リクエスト番号を退避
					lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// 非同期通知要求用アーギュメント構造体に
													// コネクションテーブル対象個別部
													// 非同期通知要求情報の引数情報１を設定
					ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// コネクションテーブル対象個別部更新
													// 非同期通知要求情報の引数情報１の
													// コネクション切断をONに設定
					ptArgSyncInfoReq->sDetailInfo |= 0x02;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
																D_PROC_NAME, ptArgSyncInfoReq ) );
					DbgMsg01( DLv04, ( OutPut, 
							"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
							D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
				}

				/********************************************/
				/*  要求刈り取り処理						*/
				/*  （パイプディスクリプのみクリア）		*/
				/********************************************/
				lCommonRet = os_tcpex_karitori( ptEcncTableInd );
				if( lCommonRet !=0 )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS32);
//2003.04.10					return( NULL );
				}

				/********************************************/
				/*  read要求通知処理						*/
				/********************************************/
				/********************************/
				/*  メッセージヘッダの編集		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE23;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tReaInfo.lReqNum;
				tMsgBuf.lResult = D_RESULT_DISCONNECT;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/********************************/
				/*  メッセージの送信			*/
				/********************************/
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// メッセージ送信処理
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS33);
//2003.04.10					return( NULL ); 	// アボート
				}

				/********************************************/
				/*  非同期通知（コネクション切断）処理		*/
				/********************************************/
				if (1 == lAsyncFlg)					// 非同期通知フラグが「１（通知あり）」の場合
				{
					/********************************/
					/*  メッセージヘッダの編集		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid =  ptEcncTableInd->tAsyncInfo.lReqNum;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  メッセージの送信			*/
					/********************************/
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();	// メッセージ送信処理
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS34);
//2003.04.10						return( NULL );				// アボート
					}
				}

				os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
				return( NULL ); 					// スレッドの終了
			}
			else									// errno がEINTRでない時
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 29: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS35);
//2003.04.10				return( NULL ); 					// アボート処理
			}
		}
	}												// Loop END

	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
	return( NULL );


/****************************************************************************/
/* エラー処理																*/
/****************************************************************************/
err_tcpex_connect:						// connectシステムコールエラー
/*****	故障管理番号TBCS0185の対応		Start							修正日：2003.06.30	*****/
/************************************************************************************************/
/*	「要求刈り取り処理」を追加																	*/
/************************************************************************************************/
	/********************************/
	/*  要求刈り取り処理			*/
	/********************************/
	lCommonRet = os_tcpex_karitori( ptEcncTableInd );
	if( lCommonRet !=0 )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
														D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
													// アボート
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS49);
	}
/*****	故障管理番号TBCS0185の対応		 End							修正日：2003.06.30	*****/

	switch( errno )
	{
		case EBADF:
		case EFAULT:
		case ENOTSOCK:
		case EINPROGRESS:
		case EAGAIN:
		case EAFNOSUPPORT:
		case EACCES:
		case EPERM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 30: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_LOGIC, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// メッセージヘッダの編集(リザルト:論理誤り)
			tMsgBuf.lResult = D_RESULT_LOGIC;

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 31: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS36);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_LOGIC );
//			return( NULL ) ;			// 論理誤り
			break;

		case EISCONN:
		case EALREADY:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 32: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_CONNECT, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.lResult = D_RESULT_CONNECT;
										// メッセージヘッダの編集(リザルト:設定済)

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 33: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS37);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_CONNECT );
//			return( NULL ); 			// 設定済み
			break;

		case ECONNREFUSED:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 34: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_NOHOST, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// メッセージヘッダの編集(リザルト:ホスト到達不可)
			tMsgBuf.lResult = D_RESULT_NOHOST;

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 35: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS38);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_NOHOST );
//			return( NULL ); 			// ホスト到達不可
			break;

		case ETIMEDOUT:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 36: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_TIMEOUT, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
									// メッセージヘッダの編集(リザルト:コネクションタイムアウト)
			tMsgBuf.lResult = D_RESULT_TIMEOUT;

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 37: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS39);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_TIMEOUT );
//			return( NULL ); 			// コネクションタイムアウト
			break;

		case ENETUNREACH:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 38: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, D_RESULT_NONETWORK, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// メッセージヘッダの編集(リザルト:NETWORK到達不可)
			tMsgBuf.lResult = D_RESULT_NONETWORK;

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 39: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS40);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_NONETWORK );
//			return( NULL ); 			// NETWORK到達不可
			break;

		case EADDRINUSE:
		/*****	故障処理票KL0029の対応	Start			修正日：2003.03.19	*****/
		case EADDRNOTAVAIL:
		/*****	故障処理票KL0029の対応	 End			修正日：2003.03.19	*****/
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 40: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_USEDADDR, "connect", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// メッセージヘッダの編集(リザルト:アドレス使用済)
			tMsgBuf.lResult = D_RESULT_USEDADDR;

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 41: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS41 );
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_USEDADDR );
//			return( NULL ); 			// アドレス使用済み
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 42: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "connect", strerror(errno) ) );

//			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
//			return( NULL ); 			// アボート処理
			break;
   }

/*****	故障管理番号TBCS0185の対応		Start							修正日：2003.06.30	*****/
/************************************************************************************************/
/*	「要求刈り取り処理」の追加によりパイプのクローズ処理を削除									*/
/************************************************************************************************/
/*****	故障管理番号TBCS0185の対応		 End							修正日：2003.06.30	*****/
	return( NULL );						// スレッド終了


err_tcpex_accept:						// acceptシステムコールエラー
	switch( errno )
	{
		case EAGAIN:					// EWOULDBLOCKはEAGAINと同値
		case EBADF:
		case ENOTSOCK:
		case EOPNOTSUPP:
		case EFAULT:
		case EPERM:
		case EINTR:
		case ENOBUFS:
		case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 43: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "accept", strerror(errno) ) );

			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
			tMsgBuf.lResult = D_RESULT_LOGIC;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 44: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS44);
//2003.04.10				return( NULL ); 		// アボート
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );
										// パイプ用ディスクリプタ読込用クローズ
			iCommonRet = close( ptEcncTableInd->alPipeDes[0] );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
			
			if( iCommonRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 45: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS45);
//2003.04.10				return( NULL ); 		// アボート処理
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );
										// パイプ用ディスクリプタ書込用クローズ
			iCommonRet = close( ptEcncTableInd->alPipeDes[1] );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
			
			if( iCommonRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 46: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS46);
//2003.04.10				return( NULL ); 		// アボート処理
			} 

										// 対象個別部のパイプ用ディスクリプタクリア
			ptEcncTableInd->alPipeDes[0] = 0;
			ptEcncTableInd->alPipeDes[1] = 0;

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
			return( NULL ); 			// 論理誤り
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 47: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "accept", strerror(errno) ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS47);
//2003.04.10			return( NULL ); 			// アボート処理
   }
}


/****************************************************************************/
/*																			*/
/*	＜関数名＞	  os_tcpex_msgsnd											*/
/*																			*/
/*	＜機能概要＞  完了メッセージ送信処理									*/
/*																			*/
/*	＜仮引数＞																*/
/*		TMyMessage *ptMsgBuf : メッセージ情報アドレス 						*/
/*																			*/
/*	＜返却値＞																*/
/*		 NORMAL：正常　　D_ERR_SYS：異常									*/
/*																			*/
/****************************************************************************/
/*****	障害対応（KL0051）	Start					修正日：2003.04.11	*****/
long os_tcpex_msgsnd(TMyMessage *ptMsgBuf)
{
	int  iCommonRet;								// 共通関数リターン値
	size_t stMsgSz; 								// 送信用メッセージサイズ


	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_TRA_IN, 0 );

										// メッセージサイズの編集
//	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);
	stMsgSz = sizeof(TMyMessage) - sizeof(long);

//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lMsgtype=%d )\n",
//			D_PROC_NAME, ptMsgBuf->lMsgtype ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lReqid  =%d )\n",
//			D_PROC_NAME, ptMsgBuf->lReqid ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lResult =%d )\n",
//			D_PROC_NAME, ptMsgBuf->lResult ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz           =%d )\n",
//			D_PROC_NAME, stMsgSz ) );

	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
//												&tMsgBuf, stMsgSz, IPC_NOWAIT );
												ptMsgBuf, stMsgSz, IPC_NOWAIT );

													// 非完了通知の送信
//	iCommonRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	iCommonRet = msgsnd( ptMyEMBC->lMsgQId, ptMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_SYS_END, 1, iCommonRet );
	if( iCommonRet == D_ERR_SYS )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 48: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "msgsnd", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_ERR_SYS, 2, D_ERR_SYS , errno);
		return( D_ERR_SYS );
	}
	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );
}
/*****	障害対応（KL0051）	 End					修正日：2003.04.11	*****/


/****************************************************************************/
/*																			*/
/*	＜関数名＞	  os_tcpex_karitori 										*/
/*																			*/
/*	＜機能概要＞  要求の刈り取り処理										*/
/*																			*/
/*	＜仮引数＞																*/
/*		void *arg : コネクション管理テーブル対象個別部先頭アドレス 			*/
/*																			*/
/*	＜返却値＞																*/
/*		 NORMAL：正常　　D_ERR_SYS：異常									*/
/*																			*/
/****************************************************************************/
long os_tcpex_karitori(void *arg)
{
	TEcncTableInd *ptEcncTableInd = arg;			// コネクション管理テーブルの対象個別部
	fd_set fsSet;									// ディスクリプタ集合
	struct timeval tvTimeout;
	TArgInfo tArgInfo; 								// 要求情報用アーギュメント
	int  iCommonRet;								// 共通関数リターン値
	long iMsgsndRet;								// 完了メッセージ送信関数リターン値
	ssize_t lSndBytes;								// 一回送信成功のバイト数
	ssize_t lTotalSndBytes; 						// 現在までに全部の送信バイト数
	/*****	障害対応（KL0051）	Start				修正日：2003.04.11	*****/
	TMyMessage tMsgBuf;								// メッセージヘッダー構造体
	/*****	障害対応（KL0051）	 End				修正日：2003.04.11	*****/


	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_TRA_IN, 1, arg );

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_ZERO, 1, &fsSet );

										// --- 要求の刈り取り ---
	FD_ZERO( &fsSet );					// 読込み用ディスクリプタ集合初期化
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );

										// ディスクリプタ集合にパイプ用ディスクリプタ
										// 読み込みチャネル側[0]を加える
	FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 0 );

	tvTimeout.tv_sec = 0;				// select返却時間に0を設定
	tvTimeout.tv_usec = 0;				// select返却時間に0を設定

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, &tvTimeout );

										// ディスクリプタ状態変化待ち
	iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, &tvTimeout ); 
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display (select iCommonRet=%ld )\n",
												"os_tcpex_karitori", iCommonRet ) );

	if( iCommonRet == D_ERR_SYS )		// 異常の場合
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 49: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "select", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
		return( D_ERR_SYS ); 			// エラー終了
	}

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->alPipeDes[0], &fsSet );
										// パイプ用ディスクリプタ状態変化確認
	iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display (FD_ISSET iCommonRet=%ld )\n",
												"os_tcpex_karitori", iCommonRet ) );

	if( iCommonRet != 0 )				// 状態変化確認あり
	{									// --- パイプからの読み込み処理(CONNECT要求) ---
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( パイプからの状態変化確認 )\n",
																	D_PROC_NAME ) );

		lTotalSndBytes = 0;
		lSndBytes = 0;

		while( lTotalSndBytes < sizeof(TArgInfo) )
		{
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_READ, 3, 
											ptEcncTableInd->alPipeDes[0],
							 (void *)&tArgInfo + lTotalSndBytes,
							  sizeof(TArgInfo) - lTotalSndBytes );
										// パイプ用ディスクリプタからの読込
			lSndBytes = read( ptEcncTableInd->alPipeDes[0],
							 (void *)&tArgInfo + lTotalSndBytes,
							  sizeof(TArgInfo) - lTotalSndBytes );
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, lSndBytes );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%d )\n",
												"os_tcpex_karitori", lSndBytes ) );

										// パイプ用ディスクリプタからの読込に失敗した時
			if( lSndBytes == D_ERR_SYS )
			{
				if( errno != EINTR )	// errno がEINTRでない時
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 50: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, D_ERR_SYS, "read", strerror(errno) ) );

										// エラー終了
					os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS, errno );
					return( D_ERR_SYS ); 			  
				}
			}
			else						// パイプ用ディスクリプタからの読込に成功した時
			{
										// 全部の送信バイト数に今回の分をインクリメント
				lTotalSndBytes += lSndBytes;
			}
		}

		switch( tArgInfo.cRecClass )	// 要求種別による処理の振り分け
		{
		case D_REQCLASS_WRITE:			// write要求
			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE24;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = tArgInfo.ulReqNum;
			tMsgBuf.lResult = D_RESULT_DISCONNECT;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 51: 0x%08x\n",
																	D_PROC_NAME, D_ERR_SYS ) );
				os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
				return( D_ERR_SYS ); 	// エラー終了
			}
			break;

		case D_REQCLASS_DETACH: 		// DETACH要求
		case D_REQCLASS_DCONN: 			// DISCONNECT要求
		case D_REQCLASS_ABORT:			// ABORT要求
			/********************************/
			/*  メッセージヘッダの編集		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = tArgInfo.ulReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lResult ) );

										// 完了メッセージ送信
			/*****	障害対応（KL0051）	Start		修正日：2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	障害対応（KL0051）	 End		修正日：2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 52: 0x%08x\n",
																	D_PROC_NAME, D_ERR_SYS ) );
				os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
				return( D_ERR_SYS ); 	// エラー終了
			}

			/************************************************/
			/*  対象コネクション管理テーブル個別部のクリア	*/
			/*  （パイプ用ディスクリプタ以外をクリア）		*/
			/************************************************/
			ptEcncTableInd->lSockDes			= 0;
			ptEcncTableInd->sParentLocalSession	= 0;
			ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
			ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
			ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
			ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
			memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
			memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
			memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );
			break;

		case D_REQCLASS_READ_CANCEL:	// READ要求キャンセル
		case D_REQCLASS_ASYNC_CANCEL:	// 非同期通知キャンセル要求
			break;						// 何もしない

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 53: 0x%08x\n",
																D_PROC_NAME, D_ERR_SYS ) );
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
			return( D_ERR_SYS ); 		// エラー終了
		}
	}
	
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );
										// 対象個別部のパイプ用ディスクリプタ[0]クローズ
	iCommonRet = close( ptEcncTableInd->alPipeDes[0] );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	if( iCommonRet == D_ERR_SYS )		// close失敗
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 54: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "close", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS , errno);
		return( D_ERR_SYS ); 			// エラー終了
	}

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );
										// 対象個別部のパイプ用ディスクリプタ[1]クローズ
	iCommonRet = close( ptEcncTableInd->alPipeDes[1] );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	if( iCommonRet == D_ERR_SYS )		// close失敗
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 55: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "close", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS , errno );
		return( D_ERR_SYS ); 			// エラー終了
	}

										// 対象個別部のパイプ用ディスクリプタクリア
	ptEcncTableInd->alPipeDes[0] = 0;
	ptEcncTableInd->alPipeDes[1] = 0;

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );
}
/****************************************************************************/
/* End																		*/
/****************************************************************************/
