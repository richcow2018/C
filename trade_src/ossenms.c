/************************************************************************************************/
/*	著作権	２００２																			*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 メッセージ通信												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 メッセージの送信											*/
/* ＜モジュールＩＤ＞				 ossenms													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカ:サプライ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 ＣＢ事ビジネス企画担当(メーカ:サプライ)					*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０４月２４日 	障害対応（TBCS0067）			*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		プロセス又は、メイルボックスにメッセージを送信する。									*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<ossenms.h>																	*/
/*																								*/
/*      long ossenms(long mpid, long size, char *bufa)                                          */
/*																								*/
/* ＜仮引数＞																					*/
/*		long		mpid			メイルボックス又はプロセス識別子							*/
/*		long		size			メッセージ長（1〜8192）										*/
/*		char		*bufp			メッセージ													*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEACCV			アドレス異常が発生した。							*/
/*						OSEEIMPI			メイルボックス又は、プロセス識別子が不当である。	*/
/*						OSEEISIZ			メッセージ長が正常でない。又は長すぎる。			*/
/*						OSEENACC			アクセス権がない。（ＷＲＩＴＥ権）					*/
/*						OSEENEXS			指定したプロセス又はメイルボックスが存在しない。	*/
/*						OSEEWKEX			システム作業域が確保できない。						*/
/*						OSEEOVRQ			非完了処理要求が多すぎて、処理不能である。			*/
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
/*								共通ヘッダ・ファイル                							*/
/*																								*/
/************************************************************************************************/
#include <string.h>
#include <stdio.h>
#include <errno.h>

/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include "ossenms.h"
#include "ossenms_ins.h"


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 ossenms.c																		*/
/*																								*/
/*	＜機能概要＞ プロセス又は、メイルボックスにメッセージを送信する                           	*/
/*				 																				*/
/*																								*/
/************************************************************************************************/
long ossenms(long mpid, long size, char *bufa)
{
	/********************************************************************************************/
    /*  ＳＧ設定ワーク領域                          						 					*/
    /********************************************************************************************/
	long lProRet = 0;							    	// プロセス識別子
	long lMKyuId = 0;									// メッセージキューID
	long lAssort = 0;									// 種別
	long lTsuban = 0;									// 通番
	long lCnt = 0;										// loop counter
	size_t lAssign = 0;									// 割り当てバイト数
	char *pcMText = NULL;								// メッセージデータ

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	int iRet = 0;										// msgsndシステムコールの返却値
	long lPartStart = 0;								// 初めの個別部位置

	TMsgHed *ptMsgPoint = NULL;							// メッセージ構造体ポインタ
	TEprcTableInd *ptEprcInd = NULL;					// プロセス個別部情報
	TEmbcTableInd *ptEmbcInd = NULL;					// メイルボックス個別部情報	


	os_trcget2( D_MD_OSSENMS, D_T_TRA_IN, 3, mpid, size, bufa  );

	/********************************************************************************************/
	/*	 初期処理																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  引数の確認                  */
	/*------------------------------*/
														// プロセス管理テーブル個別部アドレス
	ptEprcInd = (TEprcTableInd *)((long)ptEprc + sizeof(TEprcTable));
														// メイルボックス管理テーブル個別部アドレス
	ptEmbcInd = (TEmbcTableInd *)((long)ptEmbc + sizeof(TEmbcTable));

//	DbgMsg01(DLv01, (OutPut, "****** (1) Start OSSENMS\n"));
//	DbgMsg01(DLv01, (OutPut, "****** (2) mpid: %ld\n", mpid));
//	DbgMsg01(DLv01, (OutPut, "****** (3) size: %ld\n", size));
//	DbgMsg01(DLv01, (OutPut, "****** (4) bufa: %lx\n", bufa));

	if(NULL == bufa)									// メッセージのアドレスがない時
	{
		os_trcget2( D_MD_OSSENMS, D_T_ERR_PRA, 1, OSEEACCV );
		return(OSEEACCV);
	}

	if((size < D_OSSENMS_SIZE_MIN) || 					// メッセージsizeを確認する	
	   (size > D_OSSENMS_SIZE_MAX))
	{
		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEISIZ );
		return(OSEEISIZ);
	}

	if((0 > mpid))										// 第一パラメタのチェック
	{
		os_trcget2( D_MD_OSSENMS, D_T_ERR_PRA, 1, OSEEIMPI );
		return(OSEEIMPI);
	}

	if(0 == mpid)   									// mpidが0の場合
	{
		lProRet = os_MyProSearch(ptEprcInd); 	    	//プロセス識別子の妥当性チェック
		if(D_ERR_SYS == lProRet)
		{
			os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
			return(OSEENEXS);							// プロセス識別子存在しない時
		}

		lCnt = os_MyMBoxSearch(lProRet, ptEmbcInd);		// メイルボクッス識別子の妥当性チェック
		if(D_ERR_SYS == lCnt)
		{
			os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
			return(OSEENEXS);							// メイルボクッス識別子存在しない時
		}
		else
		{
			lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// メッセージキューIDを設定する
		}

		DbgMsg01(DLv02, (OutPut, "&&&&&&  lCnt = %ld\n", lCnt));
	}
	else if(0 != mpid)
	{
		lAssort = os_GetAsso(mpid);     				// 種別の取得
		lTsuban = os_GetSerNum(mpid);					// 通番の取得

		switch (lAssort)
		{
			case 1:										// 種別がプロセスの場合
														// メイルボックス管理テーブルの検索
				lMKyuId = os_PRSearch(mpid, lAssort, ptEmbcInd);	
				DbgMsg01(DLv01, (OutPut, "****** (9) lMKyuId: %ld\n", lMKyuId));

				if(D_ERR_SYS == lMKyuId)				// 検索が見つからなかった場合は
				{
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
					return(OSEENEXS);					// エラーメッセージ
				}	  
				break;

			case 2:										// 種別がメイルボックスの場合
				if((lTsuban < D_OSSENMS_TUBAN_MIN) ||	// 通番のサイズを確認する
			  	   (lTsuban > D_OSSENMS_TUBAN_MAX))
				{
/*****	障害対応（TBCS0067）Start										修正日：2003.04.24	*****/
/************************************************************************************************/
/*	エラー返却値の誤り（OSEEIMBI → OSEEIMPIに修正）											*/
/************************************************************************************************/
//					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMBI );
//					return(OSEEIMBI);					// エラーメッセージ
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMPI );
					return(OSEEIMPI);					// エラーメッセージ
/*****	障害対応（TBCS0067） End										修正日：2003.04.24	*****/
				}

														// メイルボックス管理テーブルの検索
				lCnt = os_MBISearch(ptEmbcInd, lPartStart, ptEmbc->lIndPartNum - 1, mpid);	
				if(D_ERR_SYS == lCnt)					// 検索が見つからなかった場合
				{
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );

					return(OSEENEXS);					// エラーメッセージ
				}
				else
				{
														// メッセージキューIDを設定する
					lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;
				}
				break;

			default:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMPI );
				return(OSEEIMPI);						// エラーメッセージ
				break;
		}
	}

	/*------------------------------*/
	/* メッセージの送信             */
	/*------------------------------*/
	lAssign = sizeof(TMsgHed) + size;					// メッセージヘッダサイズを
         												// 定義した「割当てバイト数」に設定する

	os_trcget2( D_MD_OSSENMS, D_T_SYS_MALLOC, 1, lAssign );
	ptMsgPoint = (TMsgHed*)malloc(lAssign);				// メモリ領域の確保
	os_trcget2( D_MD_OSSENMS, D_T_SYS_END, 1, ptMsgPoint );

	if(ptMsgPoint == NULL)								// 返却値がNULLの場合
	{
/*****	障害対応（TBCS0067）Start										修正日：2003.04.24	*****/
/************************************************************************************************/
/*	エラー返却値の誤り（OSEENEXS → OSEEWKEXに修正）											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEWKEX );

//		return(OSEENEXS);								// エラーメッセージ
		return(OSEEWKEX);								// エラーメッセージ
/*****	障害対応（TBCS0067） End										修正日：2003.04.24	*****/
	}

	DbgMsg01(DLv01, (OutPut, "****** (17) lAssort: %ld\n", lAssort));
	DbgMsg01(DLv01, (OutPut, "****** (18) mpid: %ld\n", mpid));

	ptMsgPoint->pcPlBuf= NULL;							// 指定bufaを定義した
														// 「メッセージ構造体ポインタ」の
														// プールバッファに設定する

	ptMsgPoint->lDataSize = size;						// 指定sizeを定義した
														// 「メッセージ構造体ポインタ」の
														// のデータサイズに設定する

	DbgMsg01(DLv01, (OutPut, "****** (19) ptMsgPoint->lDataSize: %d\n", ptMsgPoint->lDataSize));

	if ((0 == mpid) || (1 == lAssort))					// mpidが0又は、変数「種別」が１の場合
	{
		ptMsgPoint->lMsgType = D_MTYPE06;				// プロセス宛プールバッファ有りメッセージ
														// を定義した「メッセージ構造体ポインタ」の
														// メッセージタイプに設定する
	}
	else if(2 == lAssort)								// 変数「種別」が2の場合
	{
		ptMsgPoint->lMsgType = D_MTYPE05;				// メイルボックス宛プールバッファ有り
														// メッセージを定義した
														// 「メッセージ構造体ポインタ」の
														// メッセージタイプに設定する
	}

	pcMText = (char*) (ptMsgPoint + 1);					// メッセージデータを設定する

//	strncpy(pcMText, bufa, size);						// メッセージを定義した「メッセージ構造体ポ
	memcpy(pcMText, bufa, size);						// メッセージを定義した
														// 「メッセージ構造体ポインタ」の
														// メッセージデータに設定する

//	DbgMsg01(DLv01, (OutPut, "****** (21) ptMsgPoint->lDataSize: %ld\n", ptMsgPoint->lDataSize));
	DbgMsg01(DLv01, (OutPut, "****** (22) ptMsgPoint->pcPlBuf: %s\n", ptMsgPoint->pcPlBuf));
	DbgMsg01(DLv01, (OutPut, "****** (23) BUFA: %lx\n", bufa));	
	DbgMsg01(DLv01, (OutPut, "****** (24) lMKyuId: %ld\n", lMKyuId));
	DbgMsg01(DLv01, (OutPut, "****** (25) lAssign: %ld\n", lAssign));
//	DbgMsg01(DLv01, (OutPut, "****** (26) ptMsgPoint: %s\n", ptMsgPoint));
	DbgMsg01(DLv01, (OutPut, "****** (AAA) ptMsgPoint: %x\n", *ptMsgPoint));
	DbgMsg01(DLv01, (OutPut, "****** (AAA) ptMsgPoint: %x\n", ptMsgPoint));

	do
	{
//		os_trcget2( D_MD_OSSENMS, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, 
//														lAssign, IPC_NOWAIT );
//		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT);  // msgsndシステムコールを発行する

														// 20030329 変更
														// 受信サイズはメッセージタイプ
														// を除いたサイズを指定する
		os_trcget2( D_MD_OSSENMS, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, 
											lAssign - sizeof(long), IPC_NOWAIT );

		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign - sizeof(long), IPC_NOWAIT);

		os_trcget2( D_MD_OSSENMS, D_T_SYS_END, 1, iRet );

	} while ((D_ERR_SYS == iRet) && (EINTR == errno));

	if(D_ERR_SYS == iRet)								// 送信処理ができない場合
	{
		os_trcget2( D_MD_OSSENMS,  D_T_SYS_FREE, 1, ptMsgPoint );
		free(ptMsgPoint);								// メモリ領域を解放
		os_trcget2( D_MD_OSSENMS,  D_T_SYS_END, 0 );

		switch (errno)									// 異常処理
		{
			case EAGAIN:
			case EINVAL:
			case ENOMEM:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEEWKEX);

			case EACCES:
			case EFAULT:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEENACC);

			case EIDRM:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEENEXS);

			default:
                          								// アボート処理
				os_trcget2( D_MD_OSSENMS, D_T_ERR_ABT, 1, errno );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSENMS << 16) | D_T_ERR_SYS );
		}
	}


	/********************************************************************************************/
	/*	 終了処理																				*/
	/*																							*/
	/********************************************************************************************/
	os_trcget2( D_MD_OSSENMS,  D_T_SYS_FREE, 1, ptMsgPoint );
	free(ptMsgPoint);									// メモリ領域を解放
	os_trcget2( D_MD_OSSENMS,  D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSSENMS, D_T_TRA_OUT, 1, NORMAL );
	return(NORMAL);
}
