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
/* ＜モジュール名＞					 プールバッファ上のメッセージ送信							*/
/* ＜モジュールＩＤ＞				 ossenmsp													*/
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
/* ＜設計年月日＞					 ２００２年０９月２７日 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカ:サプライ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年０９月２７日 									*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年０５月１５日		故障管理番号（ＴＢＣＳ００８８）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年０７月０８日		故障管理番号（ＴＢＣＳ０１８０）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		メイルボックス又はプロセスに、プールバッファ上に置かれたメッセージを送信する。			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<ossenmsp_ins.h>															*/
/*																								*/
/*		long	ossenmsp( long mpid, long size, char *bufa )									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		mpid			メイルボックス又はプロセス識別子							*/
/*		long		size			メッセージ長（1〜32768）									*/
/*		char		*bufa			プールバッファアドレス										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEACCV			アドレス異常が発生した。							*/
/*						OSEEIMPI			メイルボックス又は、プロセス識別子が不当である。	*/
/*						OSEEIPOL			プールバッファでないものを指定した。				*/
/*						OSEEISIZ			メッセージ長が正常でない。又は長すぎる。			*/
/*						OSEENACC			アクセス権がない。（ＷＲＩＴＥ権）					*/
/*						OSEENEXS			指定したプロセス又はメイルボックスが存在しない。	*/
/*						OSEENFND			自プロセスのものでないプールバッファを指定した。	*/
/*						OSEEWKEX			システム作業域が確保できない。						*/
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
/************************************************************************************************/
/*	インクルードファイル																		*/
/************************************************************************************************/
/************************************************************************************************/
/*								共通ヘッダ・ファイル											*/
/************************************************************************************************/
#include <string.h>
#include <stdio.h>
#include <errno.h>

/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル										*/
/************************************************************************************************/
#include "ossenmsp.h"
#include "ossenmsp_ins.h"

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 ossenmsp.c																		*/
/*																								*/
/*	＜機能概要＞ メイルボックス又はブロセスに、ブールバッファ上に置かれたメッセージを送信する	*/
/*				 																				*/
/*																								*/
/************************************************************************************************/
long ossenmsp(long mpid, long size, char *bufa)
{

	/********************************************************************************************/
    /*  ＳＧ設定ワーク領域                          						 					*/
    /********************************************************************************************/
	long lProRet = 0;									// プロセス識別子
	long lMKyuId = 0;									// メッセージキューID
	long lAssort = 0;									// 種別
	long lTsuban = 0;									// 通番
	long lCnt = 0;										// loop counter
	size_t lAssign = 0;									// 割り当てバイト数

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	int iRet = 0;										// msgsndシステムコールの返却値
	long lPartStart = 0;								// 初めの個別部位置
	TMsgHed *ptMsgPoint = NULL;						    // メッセージ構造体ポインタ
	TEprcTableInd *ptEprcInd = NULL;					// プロセス個別部情報
	TEbpcTable *ptBPoolAdrFirst = NULL;					// バッファプール先頭アドレス
	TEbpcTable *ptBPoolAdrLast = NULL;					// バッファプール後尾アドレス
	TEpbcTableInd *ptUtilAdr = NULL;					// ユニット管理情報構造体アドレス
	TEmbcTableInd *ptEmbcInd=NULL;						// メイルボックス個別部情報
	TEpbcTableInd *ptUtilSec = NULL;
	
	os_trcget2( D_MD_OSSENMSP, D_T_TRA_IN, 3, mpid, size, bufa  );

	
	/********************************************************************************************/
	/*	 初期処理																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  引数の確認                  */
	/*------------------------------*/
	
	ptEprcInd = (TEprcTableInd *)((long)ptEprc +		// プロセス個別部情報の定義 
	            sizeof(TEprcTable));  
	ptEmbcInd = (TEmbcTableInd *)((long)ptEmbc +		// メイルボックス個別部情報の定義
				sizeof(TEmbcTable));



//	DbgMsg01(DLv01, (OutPut, "****** (1) Start OSSENMS\n"));
//	DbgMsg01(DLv01, (OutPut, "****** (2) mpid: %d\n", mpid));
//	DbgMsg01(DLv01, (OutPut, "****** (3) size: %d\n", size));
//	DbgMsg01(DLv01, (OutPut, "****** (4) bufa: %x\n", bufa)); 
	DbgMsg01(DLv01, (OutPut, "****** (5) (ptEmbcInd + 0)->lMsgQId==%d\n", (ptEmbcInd + 0)->lMsgQId)); 
	DbgMsg01(DLv01, (OutPut, "****** (6) ptEmbc->lIndPartNum==%d\n", ptEmbc->lIndPartNum));
	
	
	if((0 > mpid))										// 第一パラメタのチェック
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEIMPI );
												
		return(OSEEIMPI);
	}

	if((size < D_OSSENMSP_SIZE_MIN) || 					// メッセージ制限長(引数size)の範囲チェック
	   (size > D_OSSENMSP_SIZE_MAX))					// サイズに範囲外の値が設定されている			 
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEISIZ );
		
		return(OSEEISIZ);								
	}
	
	if(NULL == bufa)									// プールバッファアドレスがない時
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEACCV );
		
		return(OSEEACCV);
	}
		
	if(0 == mpid)   									// メイルボックス又はプロセス識別子が0
	{													// の場合
		
		lProRet = os_MyProSearch(ptEprcInd); 	    	//プロセス識別子の妥当性チェック
		
		if(D_ERR_SYS == lProRet)
		{
			os_trcget2( D_MD_OSSENMSP,  D_T_ERR_SYS, 1, OSEENEXS );
			
			return(OSEENEXS);							// プロセス識別子存在しない時
		}
		
		lCnt = os_MyMBoxSearch(lProRet, ptEmbcInd);	// メイルボクッス識別子の妥当性チェック
		
		if(D_ERR_SYS == lCnt)
		{
			os_trcget2( D_MD_OSSENMSP,  D_T_ERR_SYS, 1, OSEENEXS );
			
			return(OSEENEXS);							// メイルボクッス識別子存在しない時
		}
		else
		{
			lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// メッセージキューIDを設定する
		}
	
		DbgMsg01(DLv02, (OutPut, "&&&&&&  lCnt = %ld\n", lCnt));
	}	
	else if(0 != mpid)									// メイルボックス又はプロセス識別子が0
	{													// 以外の場合
	
		lAssort = os_GetAsso(mpid);     				// 種別の取得

		lTsuban = os_GetSerNum(mpid);					// 通番の取得

		switch (lAssort)
		{
			case 1:										// 種別がプロセスの場合
														// メイルボックス管理テーブルの検索
				lMKyuId = os_PRSearch(mpid, lAssort, ptEmbcInd);	
				DbgMsg01(DLv01, (OutPut, "****** (9) lMKyuId: %x\n", lMKyuId));	
				
				if(D_ERR_SYS == lMKyuId)				// 検索が見つからなかった場合は
				{
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
					
					return(OSEENEXS);					// エラーメッセージ
				}	  
				break;
			case 2:										// 種別がメイルボックスの場合
				if((lTsuban < D_OSSENMSP_TUBAN_MIN) ||	// 通番のサイズを確認する	 
				  (lTsuban > D_OSSENMSP_TUBAN_MAX))
				{
/*****	障害対応（TBCS0088）Start										修正日：2003.05.15	*****/
/************************************************************************************************/
/*	エラー返却値の誤り（OSEEIMBI → OSEEIMPIに修正）											*/
/************************************************************************************************/
//					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMBI );
//					return(OSEEIMBI);					// エラーメッセージ
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMPI );
					return(OSEEIMPI);					// エラーメッセージ
/*****	障害対応（TBCS0088） End										修正日：2003.05.15	*****/
				}

				DbgMsg01(DLv01, (OutPut, "****** (10) %x\n", mpid));
							
														// メイルボックス管理テーブルの検索
				lCnt = os_MBISearch(ptEmbcInd, lPartStart, ptEmbc->lIndPartNum - 1, mpid);	
				
				if(D_ERR_SYS == lMKyuId)				// 検索が見つからなかった場合は
				{
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
					
					return(OSEENEXS);					// エラーメッセージ
				}
				else
				{
					lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// メッセージキューIDを設定する
					
					DbgMsg01(DLv01, (OutPut, "****** (11) lMKyuId: %d\n", lMKyuId));
				}
				break;
			default:
				DbgMsg01(DLv01, (OutPut, "****** (12) RETURN OSEEIMPI\n"));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMPI );
				
				return(OSEEIMPI);						// エラーメッセージ
				break;
		}		
		
	}
	
	if((size < D_OSSENMSP_SIZE_MIN) || 					// メッセージsizeを確認する	
	   (size > D_OSSENMSP_SIZE_MAX))
	{
		DbgMsg01(DLv01, (OutPut, "****** (13) RETURN OSEEISIZ\n"));
		
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEISIZ );
		
		return(OSEEISIZ);
	}
	
	 ptBPoolAdrFirst = (TEbpcTable*)(long)(ptEbpc->pvAdr);	// パッファプール管理テーブルの
														// パッファプール先頭アドレスから
														// 自分を定義した「パッファプール
														// 先頭アドレス」に設定する
														
//	ptBPoolAdrFirst = (TEbpcTable*)sizeof(ptEbpc->pvAdr);
	
	DbgMsg01(DLv01, (OutPut, "****** (14) ptBPoolAdrFirst%x\n", ptBPoolAdrFirst));
														
	
	ptBPoolAdrLast = 									// 上で設定された「パッファプール
	(TEbpcTable*)(ptBPoolAdrFirst + ptEbpc->lSize);		// 先頭アドレス」ブラス「 パッファプール
														// サイズ」を自分を定義した「パッファプール
														// 後尾アドレス」に設定する。
	
	DbgMsg01(DLv01, (OutPut, "****** (15) ptBPoolAdrLast%x\n", ptBPoolAdrLast));
	
	
	if(((long)bufa < (long)ptBPoolAdrFirst) 			// もしbufaは「パッファプール先頭アドレス」
		&& ((long)bufa > (long)ptBPoolAdrLast))			// から「パッファプール後尾アドレス」までの	
	{													// 範囲でない場合は異常message return
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIPOL );
		
		return(OSEEIPOL);								// エラーメッセージ
	}
	
	
	
	ptUtilAdr = (TEpbcTableInd*)((long)bufa - 4);		// 「パッファプール先頭アドレス」は４バイトを
														// ひいて「ユニット管理アドレス」に設定する
	
	DbgMsg01(DLv01, (OutPut, "****** (16) ptUtilSec == %x\n", ptUtilSec ));
														
	ptUtilSec = (TEpbcTableInd *)(ptUtilAdr->ptNxtAdr);	
	
	DbgMsg01(DLv01, (OutPut, "****** (16) ptUtilSec == %x\n", ptUtilSec ));												
	
	DbgMsg01(DLv01, (OutPut, "****** (16.5) ptUtilSec->lUsePid == %x\n", ptUtilSec->lUsePid));

	
														
	//DbgMsg01(DLv01, (OutPut, "****** (17)ptEpbcInd == %ld\n", ptEpbcInd->lUsePid));
	
	DbgMsg01(DLv01, (OutPut, "****** lMyPid  == %ld\n", lMyPid));
	DbgMsg01(DLv01, (OutPut, "****** ptUtilSec->lUsePid  == %ld\n", ptUtilSec ->lUsePid));
														
	if(lMyPid != ptUtilSec ->lUsePid)	// 自ブロセスＩＤと設定ある「ユニット管理アドレス」
	{													// の使用プロセスＩＤが一致することを確認]
	
		DbgMsg01(DLv01, (OutPut, "999999999999 \n"));
		
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENFND );
	
		return(OSEENFND);								// エラーメッセージ 
  	}
	
	DbgMsg01(DLv01, (OutPut, "****** (188888888888888888)"));	 
	/*------------------------------*/
	/* メッセージの送信             */
	/*------------------------------*/
	          											
//	lAssign = sizeof(TMsgHed) + size;					// メッセージヘッダサイズを
	         											// 定義した「割当てバイト数」に設定する

	lAssign = sizeof(TMsgHed);							// 20030325 修正

 	DbgMsg01(DLv01, (OutPut, "****** (17) lAssign: %d\n", lAssign));
	
	os_trcget2( D_MD_OSSENMSP, D_T_SYS_MALLOC, 1, lAssign );
	ptMsgPoint = (TMsgHed*)malloc(lAssign);				// malloc関数を発行する
	os_trcget2( D_MD_OSSENMSP, D_T_SYS_END, 1, ptMsgPoint );
	
	if(ptMsgPoint == NULL)								// 返却値がNULLの場合
	{
/*****	障害対応（TBCS0088）Start										修正日：2003.05.15	*****/
/************************************************************************************************/
/*	エラー返却値の誤り（OSEENEXS → OSEEWKEXに修正）											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
//		return(OSEENEXS);								// エラーメッセージ
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);								// エラーメッセージ
/*****	障害対応（TBCS0088） End										修正日：2003.05.15	*****/
	}

	DbgMsg01(DLv01, (OutPut, "****** (18) ptMsgPoint: %x\n", ptMsgPoint));



	ptUtilSec->lUsePid = D_OSSENMSP_TRANSMIT;			// 送信中意味のメッセージを自分を定義した
														//「ユニット管理アドレス」の使用プロセスＩＤ
														// に設定する
	
	ptMsgPoint->pcPlBuf = bufa;							// 指定bufaを定義した「メッセージ構造体ポインタ」の
														// プールバッファアドレスに設定する
											
	DbgMsg01(DLv01, (OutPut, "****** (19) ptMsgPoint->pcPlBuf: %x\n", ptMsgPoint->pcPlBuf)); 
			
	ptMsgPoint->lDataSize = size;						// sizeが変数「メッセージ構造体ポインタ」の
														// データサイズに設定する
		
	if ((0 == mpid) || (1 == lAssort))					// mpidが0又は、変数「種別」が１の場合
	{
		ptMsgPoint->lMsgType = D_MTYPE08;				// 「プロセス宛プールバッファ有りメッセージ」を
														// 定義した「メッセージ構造体ポインタ」の
														// メッセージタイプに設定する。
	}
	else if(2 == lAssort)								// 変数「種別」が2の場合
	{
		ptMsgPoint->lMsgType = D_MTYPE07;				// メイルブックス宛てプールバッファ有りメッセージ」を
														// 定義した「メッセージ構造体ポインタ」
														// のメッセージタイプに設定する。
	}
	
	DbgMsg01(DLv01, (OutPut, "****** (20) lAssign: %d\n", lAssign));
	
	do
	{
		DbgDmp02( DLv04, ("### ossenmsp msgsnd ", ptMsgPoint, lAssign,1,0));
		
//		os_trcget2( D_MD_OSSENMSP, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT );
//		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT);  // msgsndシステムコールを発行する

														// 20030329 変更
														// 受信サイズはメッセージタイプ
														// を除いたサイズを指定する
		os_trcget2( D_MD_OSSENMSP, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint,
										 lAssign - sizeof(long), IPC_NOWAIT );
		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign - sizeof(long), IPC_NOWAIT);

		os_trcget2( D_MD_OSSENMSP, D_T_SYS_END, 1, iRet );
		
		
		
	} while ((D_ERR_SYS == iRet) && (EINTR == errno));	
	

	/****************************************************************************/
	/*	異常処理																*/
	/****************************************************************************/
	if(D_ERR_SYS == iRet)										// 0以外の場合
	{
/*****	故障管理番号TBCS0180の対応		Start							修正日：2003.07.08	*****/
														// ユニット管理情報の「使用プロセスＩＤ」の
		ptUtilSec->lUsePid = lMyPid;					// 送信中状態を解除（所有者のPIDを設定）
/*****	故障管理番号TBCS0180の対応		 End							修正日：2003.07.08	*****/
														
		DbgMsg01(DLv05, (OutPut, "****** (21) ptUtilAdr->lUsePid = %d\n", ptUtilAdr->lUsePid));
		
		os_trcget2( D_MD_OSSENMSP,  D_T_SYS_FREE, 1, ptMsgPoint );
			
		free(ptMsgPoint);								// freeシステムコールを発行する
		
		os_trcget2( D_MD_OSSENMSP,  D_T_SYS_END, 0 );
		
		switch (errno)									// 異常処理
		{
			case EAGAIN:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (29) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case EACCES:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (30) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENACC);
			case EFAULT:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (31) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENACC);
			case EIDRM:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (32) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENEXS);
			case EINTR:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (33) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case EINVAL:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (34) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case ENOMEM:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (35) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			default:
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_ABT, 1, errno );
				
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSENMSP << 16) | D_T_ERR_SYS );
                        								// アボート処理 
		}		
			
//		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
														
//		return(OSEENEXS);								// エラーメッセージ
	}

	/********************************************************************************************/
	/*	 終了処理																				*/
	/*																							*/
	/********************************************************************************************/
	os_trcget2( D_MD_OSSENMSP,  D_T_SYS_FREE, 1, ptMsgPoint );
	
	free(ptMsgPoint);									// freeシステムコールを発行する
	
	os_trcget2( D_MD_OSSENMSP,  D_T_SYS_END, 0 );
		
//	DbgMsg01(DLv01, (OutPut, "****** (38) BEFORE RETURN TO NORMAL \n"));	
	
	os_trcget2( D_MD_OSSENMSP, D_T_TRA_OUT, 1, NORMAL );
	
	return(NORMAL);
}

