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
/* ＜サービス項目名＞				 操作管理													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 メッセージ出力												*/
/* ＜モジュールＩＤ＞				 oswrite1													*/
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
/* ＜ソース作成年月日＞ 			 ２００３年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 サプライ　朱												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月　４日     故障管理番号（ＴＢＣＳ０１２３）*/
/* ＜ソース修正者＞ 			 	 サプライ　朱												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月１７日     故障管理番号（ＴＢＣＳ０１５３）*/
/*																故障管理番号（ＴＢＣＳ０１５５）*/
/* ＜ソース修正者＞ 			 	 サプライ　朱												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月２７日     故障管理番号（ＴＢＣＳ０１７２）*/
/*                                                              								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		「データ格納バッファ」に格納されたメッセージ識別文字（先頭４桁の文字）をKEYとして		*/
/*		共有メモリ上に展開されているコンソール出力用／ログファイル出力用／特定プロセス出力用の	*/
/*		メッセージフォーマットを取得し、それぞれ出力メッセージ編集を行う。						*/
/*		編集完了後に出力メッセージを、「メッセージ出力指示文字」に従い、						*/
/*		コンソール／ログファイル／特定のプロセスに対してメッセージ出力を行う。					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oswrite1.h>																*/
/*																								*/
/*      long oswrite1(long fildes, char *buf, long len)                                         */
/*																								*/
/* ＜仮引数＞																					*/
/*      long fildes        ファイル記述子                     							        */
/*      char *buf          データ格納バッファ（NULL以外）                              			*/
/*      long len           指定データサイズ（0以上）                              				*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			0x0000XXXX															*/
/*		異常終了			0x940dXXXX															*/
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
#include <sys/time.h>
#include <syslog.h> 
#include <errno.h>


/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include "oswrite1.h"
#include "oswrite1_ins.h"


/************************************************************************************************/
/*	内部関数											             							*/
/*																								*/
/************************************************************************************************/
void os_GetBufMsg(char*, long);
void os_EditString(char*, char*, long, long);
void os_GetStrPos(char*, char, long*, long*, long);
void os_ChangeCode(char*, short*, long, long, char*);
void os_GetLogMsg(char*, char*, char*, long);
void os_GetMsg(char*, char*, char**, long, short*, long);
long os_SeekStr(char*, char, long, long);
long os_Time(long*, long*);
long os_SearchJIS(short*, long, long, long);
long os_MsgOut(char*, char*, char*);
long os_SearchMsgID(TEmmcTableInd*, long, char*);
long os_SendCon(char*, char[], long, long, long);
long os_SendLog(char*, char[], long, long, long);
long os_SendProc(char*, char[], long, long, long);
int  os_ChgFacCode(int);
int  os_ChgPriority(char*);

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 oswrite1(long fildes, char *buf, long len)										*/
/*																								*/
/*	＜機能概要＞ メッセージ出力                     											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - ファイル記述子														*/
/*		パラメーター(2)	- データ格納バッファ													*/
/*		パラメーター(3)	- 指定データサイズ														*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (D_OSWRITE1_NULL_BUFFER) or (OSEEWKEX) or (D_OSWRITE1_OUTPUT_ERROR)				*/
/*																								*/
/*																								*/
/************************************************************************************************/
long oswrite1(long fildes, char *buf, long len)
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lResult = 0x00000000;								// リータン値
		
	long lRetForLog = 0x00000000;							// sendlog()の返却値
	
	long lRetForPrc = 0x00000000;							// sendProc()の返却値
	
	long lRetForCon = 0x00000000;							// sendCon()の返却値
	
	long lRetForTime = 0;									// Time()の返却値
	
	long lmm = 0;											// 分の数値
	
	long lhr = 0;											// 時の数値
	
	char pcTmpBufMsgId[4];									// メッセージ識別子
	

//	DbgMsg01( DLv04, ( OutPut, " (1) IN ****\n" ) );

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_IN, 3, fildes, buf, len );
	
	/********************************************************************************************/
	/*	 初期処理																				*/
	/********************************************************************************************/
	/*---------------------------------------*/
	/*  引数の確認                           */
	/*---------------------------------------*/
	if (NULL == buf)										// データ格納バッファがNULLの場合
	{
		lResult = ERR_HEADER | DAT_ERROR;
		
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, lResult );
		
		return(lResult);									// 異常メッセージを返却
	} 
	
	if (len < 1)											// 書き込みバイト数が1以上ない場合
	{
		lResult = ERR_HEADER | SIZ_ERROR;
		
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, lResult );
		
		return(lResult);									// 異常メッセージを返却
	}  

	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* メッセージ編集出力処理 				  */
	/******************************************/
	
	lRetForTime = os_Time(&lhr, &lmm);						// システム時間を求め
	
//	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (2)\n" ) );
	
	if(lRetForTime !=NORMAL)								// 時間を得ない場合
	{
		lResult = ERR_HEADER | INV_ERROR;
	
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_SYS, 1, lResult );
	
		return(lResult);									// エラー処理
	}
	
//	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (3)\n" ) );

	
	memset(pcTmpBufMsgId, 0x00, 4);						// TBCS0153/TBCS0155
	
	if(len >= 4)										// TBCS0153/TBCS0155
	{
		strncpy(pcTmpBufMsgId, buf, 4);					// データ格納バッファから
														// メッセージ識別子を取る
	}
	else												// TBCS0153/TBCS0155
	{
		strncpy(pcTmpBufMsgId, buf, len);				// TBCS0153/TBCS0155
	}

	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (5) pcTmpBufMsgId == %c%c%c%c\n", 
	         pcTmpBufMsgId[0], pcTmpBufMsgId[1], pcTmpBufMsgId[2], pcTmpBufMsgId[3] ) );

	/********************************************/
	/* ログファイル出力用メッセージ編集出力処理 */
	/********************************************/
															// ログファイル出力
															// メッセージの処理
	lRetForLog = os_SendLog(buf, pcTmpBufMsgId, lhr, lmm, len);
	
	
	if(lRetForLog > LOG_NORMAL)							// 出力できない場合
	{
		lRetForLog = lRetForLog | LOG_ERROR;
	}
	
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (6) lRetForLog == %08lx\n", lRetForLog) );

	
	/********************************************/
	/* 特定プロセス通信用メッセージ編集出力処理 */
	/********************************************/		
															// 特定プロセス出力
															// メッセージの処理
	lRetForPrc = os_SendProc(buf, pcTmpBufMsgId, lhr, lmm, len);
	
	
	if(lRetForPrc > PRC_NORMAL)								// 出力できない場合
	{
		lRetForPrc = lRetForPrc | PRC_ERROR ;		
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (7) lRetForPrc == %08lx\n", lRetForPrc) );
	
	/********************************************/
	/* コンソール出力用メッセージ編集出力処理   */
	/********************************************/
															// 特定プロセス出力
															// メッセージの処理
	lRetForCon = os_SendCon(buf, pcTmpBufMsgId, lhr, lmm, len);		
	
	
	if(lRetForCon > CON_NORMAL)								// 出力できない場合
	{
		lRetForCon = lRetForCon | CON_ERROR;
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (8) lRetForCon == %08lx\n", lRetForCon) );
	
	/********************************************************************************************/
	/*	 処理終了																				*/
	/********************************************************************************************/
	
	 lResult = lRetForCon | lRetForPrc | lRetForLog;
	
	 //if(0x00000007 != lResult)
	 if(lResult > 0x00000007)
	 {
	 	lResult = lResult | ERR_HEADER;
	 } 
	 

	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (9) lResult  == %08lx\n", lResult ) );

//	DbgMsg01( DLv04, ( OutPut, "**** oswrite1 (10) OUT ****\n" ) ); 

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, lResult );
	
	return (lResult);


}




/************************************************************************************************/
/*																								*/
/*	＜関数名＞long os_SendCon(char *buf, char pcTmpBufMsgId[], long lhr, 						*/
/*                            long lmm, long lBufLen)											*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ コンソール出力用メッセージ編集出力処理											*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1) - データ格納バッファ													*/
/*		パラメーター(2)	- メッセージ識別子														*/
/*		パラメーター(3)	- 時の数値																*/
/*		パラメーター(4)	- 分の数値																*/
/*		パラメーター(5)	- データ格納バッファサイズ												*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendCon(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lRet = 0;											// メッセージ識別子検索の返却値
	
	long lRetForSend = 0x00000000;							// メッセージ送信の返却値
	
	long lRetForSPrintf = 0;								// sprintfの返却値
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// メッセージ出力指示文字

	char *pcTmpMsg = NULL;									// 出力メッセージ
	
	char *pcFormatMsg = NULL;								// メッセージアドレス
	
	char pcPriority[8];										// プライオリディ
		
	char cNotFoundMsg[100];									// 識別子がないときの
															// 出力メッセージ

	char *pcTmpForMsg = NULL;	
	
	TEmmcTableInd *ptEmmcInd = NULL;						// メッセージ管理テーブル
	
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* メッセージを検索処理					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptConAdr; 			// コンソール出力
															// メッセージアドレスを設定
															
//	DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (1)\n" ) );						
										
															// メッセージ識別子の検索
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lConCnt, pcTmpBufMsgId);
	
	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendCon (1.1) after os_SearchMsgID\n") );
	
	if(lRet < 0)											// メッセージ識別子が見つから
	{														// なかった場合
	
															// 出力メッセージの領域をとる
//		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (3)\n" ) );
		
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (4) Get into Not Found \n") );	
		
		
															// not foundメッセージを編集
		lRetForSPrintf = sprintf(cNotFoundMsg, "[ERR    ] %.2d:%.2d KO00* CMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], pcTmpBufMsgId[2],
		                         pcTmpBufMsgId[3]);
		
		if(lRetForSPrintf < 0)
		{
			
			return(CON_ERROR);
		}
	
															// 出力する
		lRetForSend = os_MsgOut(cNotFoundMsg, D_SG_EMMC_CONSOLE, "ERR"); 
		
		if(lRetForSend != NORMAL)							// 出力できない場合
		{
			return(lRetForSend);							// エラー処理		
		}
	
	}
	else
	{
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (5)\n") );

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// コンソール出力用メッセージ
															// アドレスを設定

		lMsgLen = strlen(pcFormatMsg);						// メッセージ管理テーブ個別部の
															// メッセージフォーマット情報
															// アドレスのサイズ
															
															
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );		
															
															// TBCS0123	
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
		
															// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// 全角に編集するサイズ分=引数*2
															// 時間,スペース,[]のサイズ分=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );	
															
		/******************************************/
		/* メッセージを編集する					  */
		/******************************************/
															// メッセージを編集
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sConAfter, lMsgLen);
		
		cMsgOutFlg = pcFormatMsg[12];						// メッセージ出力指示文字を設定

		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (6) pcTmpMsg == %s\n", pcTmpMsg) );
		
															// プライオリディの領域を確保

		strncpy(pcPriority, pcFormatMsg, 7);				// プライオリデを取得
		
		pcPriority[7]='\0';


		
		lRetForSPrintf = sprintf( pcTmpForMsg, "[%s] %.2d:%.2d %s", 
								pcPriority, lhr, lmm, pcTmpMsg);
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (7) pcFormatMsg == %s\n", pcFormatMsg) );
		
		if(lRetForSPrintf < 0)								// 出力メッセージの編集
		{													// ができなかった場合
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );

			free(pcTmpMsg);									// 領域を解放
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
			
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(CON_ERROR);								// エラー処理
			
		} 
		
		/******************************************/
		/* メッセージを出力						  */
		/******************************************/
		if(cMsgOutFlg == '*')								// 出力指示文字がある場合
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendCon  (8) cMsgOutFlg == %c\n", 
					cMsgOutFlg) );	
			
															// メッセージを出力する	
			lRetForSend = os_MsgOut(pcTmpForMsg, D_SG_EMMC_CONSOLE, pcPriority);
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (9) lRetForSend == %ld\n", 
					lRetForSend) );	
			
			if(lRetForSend != NORMAL)						// 出力できない場合
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );

				free(pcTmpMsg);								// 領域を解放
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
				
				free(pcTmpForMsg);
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
				return(lRetForSend);						// エラー処理
			}
		}
		else
		{
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// 領域を解放
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(NO_MSGSEND);
		}	
				
	}	
	
	
//	DbgMsg01( DLv04, ( OutPut, "#### os_SendCon return to Normal(10) pcTmpMsg == %s\n", 
//				pcTmpMsg) );
															
	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// 領域を解放
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
			
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	return(CON_NORMAL);
	
}




/************************************************************************************************/
/*																								*/
/*	＜関数名＞long os_SendLog(char *buf, char pcTmpBufMsgId[], long lhr, long lmm,              */
/*                            long lBufLen)	                                                    */
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ ログファイル出力用メッセージ編集出力処理										*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1) - データ格納バッファ													*/
/*		パラメーター(2)	- メッセージ識別子														*/
/*		パラメーター(3)	- 時の数値																*/
/*		パラメーター(4)	- 分の数値																*/
/*		パラメーター(5)	- データ格納バッファサイズ												*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendLog(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lRet = 0;											// メッセージ識別子検索の返却値
	
	long lRetForSend = 0x00000000;							// メッセージ送信の返却値
	
	long lRetForSPrintf = 0;								// sprintfの返却値
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// メッセージ出力指示文字

	char *pcFormatMsg = NULL;								// メッセージアドレス
	
	char pcPriority[8];										// プライオリディ
		
	char *pcTmpMsg = NULL;									// 出力メッセージ

	char cNotFoundMsg[100];									// 識別子がないときの出力メッセージ

	TEmmcTableInd *ptEmmcInd = NULL;						// メッセージ管理テーブル
	
	char *pcTmpForMsg = NULL;	
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* メッセージを検索処理					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptLogAdr; 			// ログファイル出力
															// メッセージアドレスを設定
															
//	DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (1)\n" ) );	
															// メッセージ識別子の検索
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lLogCnt, pcTmpBufMsgId);

//	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendLog (2) After os_SearchMsgID\n" ) );

	
	if(lRet < 0)											// メッセージ識別子が
	{														// 見つからなかった場合

		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (3) Get into Not Found \n") );	
		
	
		
															// not foundメッセージを編集
		lRetForSPrintf = sprintf(cNotFoundMsg, 
								 "[ERR    ] %.2d:%.2d KO00* LMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], 
								 pcTmpBufMsgId[2], pcTmpBufMsgId[3]);
		
		if(lRetForSPrintf < 0)
		{
			return(LOG_ERROR);
		}
					
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (5) pcTmpMsg == %s\n", pcTmpMsg) );

															//出力
		lRetForSend = os_MsgOut(cNotFoundMsg, D_SG_EMMC_SYSLOG, "ERR"); 
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (6) lRetForSend == %d\n", lRetForSend) );

		if(lRetForSend != NORMAL)							// 出力できない場合
		{
						
			return(lRetForSend);
		}
	
	}
	else
	{

		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7)\n") );
			

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// ログファイル出力用メッセージアドレス
															// を設定
															
		lMsgLen = strlen(pcFormatMsg);						// メッセージ管理テーブ個別部の
															// メッセージフォーマット情報アドレス
															// のサイズ
		
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
		
															// TBCS0123
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);

																	// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// 全角に編集するサイズ分=引数*2
															// 時間,スペース,[]のサイズ分=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );	
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7.1) lMsgLen == %ld\n", lMsgLen) );	
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7.2) lBufLen == %ld\n", lBufLen) );	
													
		/******************************************/
		/* メッセージを編集する					  */
		/******************************************/
		cMsgOutFlg = pcFormatMsg[12];						// メッセージ出力指示文字を設定
		
															// メッセージを編集
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sConAfter, lMsgLen);
		
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (8) pcTmpMsg == %s\n", pcTmpMsg) );
		
		if( (cMsgOutFlg == '$') || (cMsgOutFlg == '&') )	// 出力指示文字がある場合
		{ 
			os_GetLogMsg(buf, pcFormatMsg, pcTmpMsg, lBufLen);	// ログ付情報を取得
		}
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (9) pcTmpMsg == %s\n", pcTmpMsg) );
		
		strncpy(pcPriority, pcFormatMsg, 7);				// プライオリデを取得
		
		pcPriority[7]='\0';
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (10) pcPriority == %s\n", pcPriority) );
		
															// 出力メッセージを編集
		lRetForSPrintf = sprintf( pcTmpForMsg, "[%s] %.2d:%.2d %s", 
								pcPriority, lhr, lmm, pcTmpMsg);
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (11) pcTmpForMsg == %s\n", 
				pcTmpForMsg) );	
			
		if(lRetForSPrintf < 0)								// 出力メッセージの編集が
		{													// できなかった場合
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// 領域を解放
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );	
				
			free(pcTmpForMsg);
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(LOG_ERROR);								// エラー処理
		} 
		
		
		/******************************************/
		/* メッセージを出力						  */
		/******************************************/
		
		if( (cMsgOutFlg == '$') || (cMsgOutFlg == '&') )	// 出力指示文字がある場合
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (12) cMsgOutFlg == %c\n", cMsgOutFlg) );	
															
															// メッセージを出力する	
			lRetForSend = os_MsgOut(pcTmpForMsg, D_SG_EMMC_SYSLOG, pcPriority);
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (13) lRetForSend == %ld\n", 
					lRetForSend) );	
			
			
			if(lRetForSend != NORMAL)							// 出力できない場合
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
				free(pcTmpMsg);									// 領域を解放
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
				
				free(pcTmpForMsg);
			
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

				return(lRetForSend);							// エラー処理
			}
		}
		else
		{
			/******************************************/
			/* メッセージを出力しない				  */
			/******************************************/
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);										// 領域を解放
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(NO_MSGSEND);
		}
		
	}	

															
	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// 領域を解放
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	return(LOG_NORMAL);
	
}

/************************************************************************************************/
/*																								*/
/*	＜関数名＞long os_SendProc(char *buf, char pcTmpBufMsgId[], long lhr, 						*/
/*							  long lmm, long lBufLen)											*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ 特定ブロセス出力用メッセージ編集出力処理										*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1) - データ格納バッファ													*/
/*		パラメーター(2)	- メッセージ識別子														*/
/*		パラメーター(3)	- 時の数値																*/
/*		パラメーター(4)	- 分の数値																*/
/*		パラメーター(5)	- データ格納バッファサイズ												*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendProc(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/

	long lRet = 0;											// メッセージ識別子検索の返却値
	
	long lRetForSend = 0;									// メッセージ送信の返却値
	
	long lRetForSPrintf = 0;								// sprintfの返却値
	
	long lTmpProcOutLen = 0;
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// メッセージ出力指示文字

	char *pcTmpMsg = NULL;									// 出力メッセージ
	
	char *pcFormatMsg = NULL;								// メッセージアドレス
	
	char cNotFoundMsg[100];									// 識別子がないときの出力メッセージ
	
	TEmmcTableInd *ptEmmcInd = NULL;						// メッセージ管理テーブル
	
	char *pcTmpForMsg = NULL;	
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* メッセージを検索処理					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptProcAdr; 			// 特定ブロセス出力
															// メッセージアドレスを設定
															
	DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1.1) \n" ) );						
										
															// メッセージ識別子の検索
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lProcCnt, pcTmpBufMsgId);
	
//	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendProc (1.2) after os_SearchMsgID\n") );
	
	if(lRet < 0)											// メッセージ識別子が
	{														// 見つからなかった場合

		/******************************************/
		/* 特定プロセス識別子チュック			  */
		/******************************************/
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (0) \n" ) );	
	
		if(0 == ptEmmc->lPCode)
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1) ptEmmc->lPCode == %ld\n", 
					ptEmmc->lPCode ) );	
		
			os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, PRC_ERROR );
			
			return(PRC_ERROR);
		}	

	
//		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (2)\n" ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (3) Get into Not Found \n") );	

		memset(cNotFoundMsg, 0x00, 1);

															// not foundメッセージを編集
		lRetForSPrintf = sprintf(cNotFoundMsg+1, "%.2d:%.2dKO00* SMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], 
								 pcTmpBufMsgId[2], pcTmpBufMsgId[3]);
					
		DbgDmp02( DLv04, ("## sprintf後 ", cNotFoundMsg, lRetForSPrintf+1,1,0));						 

		if(lRetForSPrintf < 0)								// 出力メッセージの編集
		{													// ができなかった場合
			os_trcget2( D_MD_OS_SENDPROC, D_T_ERR_SYS, 1, PRC_ERROR );
			
			return(PRC_ERROR);
		}

		lTmpProcOutLen = lRetForSPrintf + 1;
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (3.1) lTmpProcOutLen == %ld\n", lTmpProcOutLen) );
		
															// 送信関数でメッセージを送る
		lRetForSend = ossenms(ptEmmc->lPCode, lTmpProcOutLen, cNotFoundMsg);
		

		if(lRetForSend != NORMAL)							// 出力できない場合
		{
			os_trcget2( D_MD_OS_SENDPROC, D_T_ERR_SYS, 1, INV_ERROR );
			
			return(INV_ERROR);								// エラー処理
		}
	
	}
	else
	{

		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (4)\n") );

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// 特定ブロセス出力用
															// メッセージアドレスを設定
															
		lMsgLen = strlen(pcFormatMsg);						// メッセージ管理テーブ個別部の
															// メッセージフォーマット
															// 情報アドレスのサイズ
															
															
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
		
															// TBCS0123
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);


															// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// 全角に編集するサイズ分=引数*2
															// 時間,スペース,[]のサイズ分=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );		
		
															
		/******************************************/
		/* メッセージを編集する					  */
		/******************************************/
															// メッセージを編集
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sProAfter, lMsgLen);
		
		cMsgOutFlg = pcFormatMsg[12];
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (6) cMsgOutFlg == %c\n", cMsgOutFlg) );
		
		
		memset(pcTmpForMsg, 0x00, 1);
		
															// 出力メッセージを編集
		lRetForSPrintf = sprintf(pcTmpForMsg+1, "%.2d:%.2d%s", lhr, lmm, pcTmpMsg);
		
		DbgDmp02( DLv04, ("## sprintf後 ", pcTmpForMsg, lRetForSPrintf+1,1,0));
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (7) pcTmpForMsg == %s\n", 
				pcTmpForMsg) );
				
		
		if(lRetForSPrintf < 0)								// 出力メッセージの編集
		{													// ができなかった場合
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
			
			free(pcTmpMsg);									// 領域を解放
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			return(PRC_ERROR);								// エラー処理
			
		} 
		
		/******************************************/
		/* メッセージを出力						  */
		/******************************************/
		if(cMsgOutFlg == '*')								// 出力指示文字がある場合
		{
	
			/******************************************/
			/* 特定プロセス識別子チュック			  */
			/******************************************/
	
//			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (0) \n" ) );	
	
			if(0 == ptEmmc->lPCode)
			{
				DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1) ptEmmc->lPCode == %ld\n", ptEmmc->lPCode ) );	
		
				os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, PRC_ERROR );
			
				return(PRC_ERROR);
			}	
	
	
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8) lTmpProcOutLen  == %d\n", 
					lTmpProcOutLen ) );
					
					
			lTmpProcOutLen = lRetForSPrintf + 1;			// 出力メッセージのサイズを求め			
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8.1) lTmpProcOutLen == %ld\n", lTmpProcOutLen) );			
					
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8.2) ptEmmc->lPCode  == %08x\n", 
					ptEmmc->lPCode ) );	
					
			
															// 送信関数でメッセージを送る 
			lRetForSend = ossenms(ptEmmc->lPCode, lTmpProcOutLen, pcTmpForMsg);
			
					
			if(lRetForSend != NORMAL)						// 出力できない場合
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
				free(pcTmpMsg);								// 領域を解放
	
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
				free(pcTmpForMsg);
			
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

					
				return(INV_ERROR);							// エラー処理
			}
		}
		else
		{
			/******************************************/
			/* メッセージを出力しない				  */
			/******************************************/
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// 領域を解放
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, PRC_NORMAL );
	
			return(NO_MSGSEND);
			
		}
	
	}	
	
		
//	DbgMsg01( DLv04, ( OutPut, "#### os_SendProc return to Normal (11) pcTmpMsg == %s\n", 
//	                   pcTmpMsg) );
	
	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/

	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// 領域を解放
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
			
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, PRC_NORMAL );
	
	return(PRC_NORMAL);
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 			*/
/*                              short *sCode, long lMsgLen)										*/
/*	                             	     			    										*/
/*																								*/
/*	＜機能概要＞ 出力メッセージを取得															*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	メッセージフォーマット情報アドレス									*/
/*		パラメーター(2)	 - 	データ格納バッファ													*/
/*		パラメーター(3)	 -	編集後のメッセージ													*/
/*		パラメーター(4)	 -	データ格納バッファのサイズ											*/
/*		パラメーター(5)	 -	コード変換情報														*/
/*		パラメーター(6)	 -	テーブルのメッセージサイズ											*/
/*																								*/
/*																								*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 
				short *sCode, long lMsgLen)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lMsgStart = 0;										// メッセージフォーマット情報用の先頭
	
	long lMsgEnd = 0;										// メッセージフォーマット情報用の終端
	
	long lBufStart = 0;										// データ格納バッファ用の先頭
	
	long lBufEnd = 0;										// データ格納バッファ用の終端 
	
	long ltemp = 0;
	
	long lFlg = 0;
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

//	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
															// メッセージフォーマット情報と
															// データ格納バッファを確保するため
//	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// の領域を取ります
															// TBCS0123
															
															// TBCS0153 / TBCS0155
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );

	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // データ編集の領域を確保
															// 全角に編集するサイズ分=引数*2
															// 時間,スペース,[]のサイズ分=9
															// TBCS0153 / TBCS0155





	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );

//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0) lMsgLen == %ld\n", lMsgLen) );	
		
//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.1) lBufLen == %ld\n", lBufLen) );	


															// TBCS0172		Start	2003.06.27
	/****************************************/
	/*	編集制御文字検索処理				*/
	/****************************************/
	lMsgStart = 8;											// 検索文字位置を設定
	while(lMsgStart > 0)
	{ 
															// 編集制御文字を検索
		lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);

		if(lMsgStart != -1)
		{
			if( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') )
			{
				break;
			}
			else
			{
				lMsgStart ++;
			}
		}
	}

//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
	
	if ( lMsgStart != -1) 									// 編集制御文字があった場合
	{
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgStart - 8); 	// 指定範囲されたメッセージ情報から
															// 出力メッセージに加え
															
		ltemp = lMsgStart - 8;
		
		strncpy((*pcMsg+ltemp), "\0", 1); 
		
		ltemp = lMsgStart + 1; 
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.3) *pcMsg\n ") );

		while(lMsgEnd != -1)								// メッセージデータがなくなるまでループ
		{
			/****************************************/
			/*	埋め込み文字列の編集処理			*/
			/****************************************/
			if( (pcFmtAdr[lMsgStart] == '%') &&
			  ( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') ) )
			{
															// データ格納バッファの埋め込み文字列
															// の範囲を取得
				os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);

														// 編集制御文字は%zの場合コード変換
				if( ( pcFmtAdr[lMsgStart] == '%' ) && ( pcFmtAdr[lMsgStart+1] == 'z' ) )
				{
															// TBCS0123
				 	os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);
				}
				else										// TBCS0123
				{											// データ格納バッファから
															// 出力メッセージに編集
					os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
				
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.5) lBufStart = %ld\n", lBufStart));
				}
			
					lMsgStart ++;
			}
			
		//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (3) lBufStart == %d\n", lBufStart ) ); 
			
		//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(4) lBufEnd == %d\n", lBufEnd ) ); 

			/****************************************/
			/*	編集制御文字検索処理				*/
			/****************************************/
			lMsgEnd = os_SeekStr(pcFmtAdr, '%', ltemp, lMsgLen);
			if(lMsgEnd != -1)  
			{
				if( (pcFmtAdr[lMsgEnd + 1 ] == 'z') || (pcFmtAdr[lMsgEnd + 1] == 's') ) 
				{
															// メッセージフォーマット情報から
															// 出力メッセージに編集
					os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgEnd);
					
					lMsgStart = lMsgEnd;
				}
					
				ltemp = lMsgEnd + 1;
					
			}
			else
			{
															// メッセージフォーマット情報から
															// 出力メッセージに編集
					os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgLen);
			}
															
	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (6) lBufStart == %ld\n", lBufStart ) );	
			
	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (7) pcFmtAdr[lMsgStart]  == %c\n", 
	//				pcFmtAdr[lMsgStart]  ) );
		}
	}														// TBCS0172      End    2003.06.27
	else
	{
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (8) pcFmtAdr == %s\n", pcFmtAdr) );	
		
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgLen); 			// 指定範囲されたメッセージ情報か
															// 出力メッセージに加え
	} 

}



/************************************************************************************************/
/*																								*/
/*	＜関数名＞ long os_SearchMsgID(TEmmcTableInd *pcEmmcIndAdr, long lTEmmcCnt, 				*/
/*								   char pcTmpBufMsgId[])				 						*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ メッセージ識別子の検索															*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	メッセージフォーマット情報アドレス									*/
/*		パラメーター(2)	 - 	メッセージ相対アドレス												*/
/*		パラメーター(3)	 -	メッセージ識別子													*/
/*																								*/
/*	リターン:																					*/
/*		成功 (メッセージ管理テーブル個別部数）													*/
/*		失敗 (-1)																				*/
/*																								*/
/************************************************************************************************/
long os_SearchMsgID(TEmmcTableInd *pcEmmcIndAdr, long lTEmmcCnt, char pcTmpBufMsgId[])
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lRet = -1;											// strncmpの返却値	
	
	long lCounter = 0;										// ループカウンタ
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) lTEmmcCnt == %d\n", lTEmmcCnt) );
	
	do														// データ格納バッファにある
	{														// メッセージ識別子がメッセージ	
															// 管理テーブルのメッセージ	
															// 識別子と合致
															
		lRet = strncmp(pcTmpBufMsgId, (pcEmmcIndAdr + lCounter)->acMsgID, 4);
		
		lCounter += 1;									
		
	}while((lRet != 0) && (lCounter < lTEmmcCnt));			// 合致するまで	

	if(lRet == 0)											
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) lCounter == %ld\n", lCounter) );
		
		lCounter--;
		
		return(lCounter);									// メッセージ管理テーブル個別部数返却
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) return to -1") );
	
	return(-1);												// エラー処理
}



/************************************************************************************************/
/*																								*/
/*	＜関数名＞ void os_GetStrPos(char *pcBuf, char cTarget, long *lStart, long *lEnd,			*/
/*								 long lLen)							 							*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ メッセージ配列の指定範囲を取得													*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	データ格納バッファ													*/
/*  	パラメーター(2)	 -	目標																*/
/*		パラメーター(3)	 -  先頭の位置															*/
/*		パラメーター(4)	 -  終端の位置															*/
/*		パラメーター(5)	 -  データ格納バッファサイズ											*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetStrPos(char *pcMessage, char cTarget, long *lStart, long *lEnd, long lLen)
{
	
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lRetForStart = 0;									// 先頭の位置を検索の返却値
	
	long lRetForEnd = -1;									// 終端の位置を検索の返却値
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
															// 先頭の位置を検索
	lRetForStart = os_SeekStr(pcMessage, cTarget, *lStart, lLen);		
	
	if(lRetForStart != -1)									// 見つかった場合
	{
	
		if(pcMessage[lRetForStart] != pcMessage[lRetForStart+1])
		{
															// TBCS0172		Start	2003.06.27
			*lStart = lRetForStart + 1;						// 目標の先頭位置を設定
		
															// 目標の終端位置を検索
			lRetForEnd = os_SeekStr(pcMessage, cTarget, lRetForStart + 1, lLen);
		
			if(lRetForEnd != -1)
			{
				*lEnd = lRetForEnd;
			}
			else
			{
				*lEnd = lLen;

			}
		}
		else
		{
			*lEnd = -1;
		}	
															
		return;
				
	}
	
	*lEnd = lRetForStart;									
															// TBCS0172		 End	2003.06.27
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ void os_GetLogMsg(char *pcBuf, char *pcFmtAdr, char *pcMsg, long lBufLen)		*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ ログ付情報を取得して出力メッセージに編入										*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)	 -  データ格納バッファ													*/
/*		パラメーター(2)  - 	メッセージフォーマット情報アドレス									*/
/*		パラメーター(3)	 -  出力メッセージ														*/
/*		パラメーター(4)	 -  データ格納バッファサイズ											*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetLogMsg(char *pcBuf, char *pcFmtAdr, char *pcMsg, long lBufLen)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lStartPos = 0;										// ループカウンタ
	
	long lMsgLen = 0;
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	
															// '\t\t'を見つけるまで繰り返し
	while( (pcBuf[lStartPos] != '\t' || pcBuf[lStartPos + 1] != '\t') && lStartPos != -1 )
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (1) lStartPos == %d\n", lStartPos) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (2) pcBuf[lStartPos]  == %c\n", 
				pcBuf[lStartPos] ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (3) pcBuf[lStartPos + 1]  == %c\n", 
				pcBuf[lStartPos + 1] ) );
															
															// '\t'を検索
		lStartPos  = os_SeekStr(pcBuf, '\t', lStartPos + 1, lBufLen);
	
	}
	
	if( (lStartPos != -1 ) && (pcBuf[lStartPos] == '\t') && (pcBuf[lStartPos + 1] == '\t'))
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (4) pcBuf[lStartPos + 1]  == %c\n", 
				pcBuf[lStartPos + 1] ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5) pcBuf[lStartPos]  == %c\n", 
				pcBuf[lStartPos] ) );	

		lMsgLen = strlen(pcMsg);

		strncpy(pcMsg+lMsgLen, " \0", 2);
		
		if(pcFmtAdr[12] == '$') 							// 出力指示文字は'$'の場合
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.2) lMsgLen=%ld\n", 
				 	lMsgLen) );
				 	
		 	DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.3) lStartPos=%ld\n", 
				 	lStartPos + 2) );
			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.4) lBufLen=%ld\n", 
				 	lBufLen) );
															// コード変換
			os_ChangeCode(pcBuf, sConAfter, lStartPos + 2, lBufLen, pcMsg);
		}	
		else
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.4)\n" ) );
			
															// 出力メッセージに編入
			os_EditString(pcBuf, pcMsg, lStartPos + 2, lBufLen);
		}
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (6) pcMsg == %s\n", pcMsg ) );
	}	
	
	DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (7) \n") );
	
}		
	


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ void os_EditString(char *pcInPtr, char *pcOutPtr, long lInPtrStart, 				*/
/*								  long lInPtrEnd)	  											*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ 指定された範囲の文字配列を出力メッセージに編入									*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	INPUT文字配列														*/
/*  	パラメーター(2)	 -	OUTPUT文字配列														*/
/*		パラメーター(3)	 -  先頭の位置															*/
/*		パラメーター(4)	 -  終端の位置															*/
/*																								*/
/************************************************************************************************/
void os_EditString(char *pcInPtr, char *pcOutPtr, long lInPtrStart, long lInPtrEnd)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	int iCnt = 0;											// ループカウンタ
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	if(lInPtrStart < lInPtrEnd)
	{
	
		while(pcOutPtr[iCnt] != '\0')						// ouput文字配列の終端文字を
		{													// 達するまでカウント
			iCnt++;
		}
	
		while(lInPtrStart < lInPtrEnd)
		{
	
			pcOutPtr[iCnt] = pcInPtr[lInPtrStart];			// input文字配列からouput
															// 文字配列に編入
			iCnt++;
		
			lInPtrStart++;

		} 
	
		pcOutPtr[iCnt++] = '\0';							// 終端文字を設定
	}
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ long os_MsgOut(char *pcMsgFormat, char *pcKey, char *pcPriority)	   				*/
/*																								*/
/*	＜機能概要＞  - メッセージ出力										                        */
/* 				   																				*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 編集済みのメッセージ													*/
/*		パラメーター(2)	 - ファシリティ															*/
/*		パラメーター(3)	 - プライオリディ														*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (D_OSWRITE1_OUTPUT_ERROR)															*/
/************************************************************************************************/
long os_MsgOut(char *pcMsgFormat, char *pcKey, char *pcPriority)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lRetSg = 0;									// SGの返却値
	
	long lRetSys = 0;									// priority
	
	long lStr = 0;										// SG値
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	lRetSg = os_getSG(pcKey, &lStr);					// SGデータの取得
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (1) lRetSg == %ld\n", lStr) );
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (2) pcKey == %s\n", pcKey) );		
	
	if(lRetSg == -1)									// 異常時
	{

		return(INV_ERROR);				
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (2) lFacility[lStr] == %ld\n", 
			lFacility[lStr]) );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_OPENLOG, 3, NULL, LOG_ODELAY, lFacility[lStr] );
	
	openlog(SYS_IDENT, LOG_ODELAY, lFacility[lStr]);			// openlog システムコール
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (3) pcPriority == %s\n", pcPriority) );	
	
	lRetSys = os_ChgPriority(pcPriority);				// priorityのコードを変換する
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (4) lRetSys == %ld\n", lRetSys) );	
	
	if (lRetSys == -1)
	{
		 return(INV_ERROR);
	}	 
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (5) pcMsgFormat == %s\n", pcMsgFormat) );	
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_SYSLOG, 2, lRetSys, pcMsgFormat );
															// TBCS0172		Start	2003.06.27
	syslog(lRetSys, "%s", pcMsgFormat);						// syslog システムコール 
															// TBCS0172		 End	2003.06.27
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_CLOSELOG, 0 );
	
	closelog();											// closelog システムコール
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	
	return (NORMAL); 	
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ int os_ChgPriority(char* pcPrioCode)												*/
/*																								*/
/*	＜機能概要＞ - syslogのプライオリディコード変換を行う										*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 変換前のプライオリディコード											*/
/*																								*/
/*	リターン:																					*/
/*		成功 (syslogのプライオリディコード)														*/
/*		失敗 (-1)  																				*/
/*																								*/
/************************************************************************************************/
int os_ChgPriority(char *pcPrioCode)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long len = 0;										// プライオリディコードのサイズ
	
	char *pcTmpPriCode = NULL;							// 検索用のプライオリディコード
	
	int iCnt = 0;										// ループカウンタ 
	
	int iCnt1 = 0;										// ループカウンタ
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	len = strlen(pcPrioCode);							// プライオリディコードのサイズ

	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (1) len == %ld\n", len) );	
	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (2) pcPrioCode == %s\n", pcPrioCode) );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, len+1 );
														// 検索用のプライオリディコードをmalloc
	pcTmpPriCode = (char*)malloc(len+1);  
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpPriCode );
	
	while(pcPrioCode[iCnt] != '\0' && iCnt < len)		// 検索用のプライオリディコード
	{													// に設定する
		if(pcPrioCode[iCnt] != ' ')						
		{
			pcTmpPriCode[iCnt1] = pcPrioCode[iCnt];

			iCnt1 += 1;
		}		
			
		iCnt += 1;
		
	}
	
	pcTmpPriCode[iCnt1] = '\0';							// 文字列のターミネーターを設定 
	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (3) pcTmpPriCode == %s\n", 
			pcTmpPriCode) );
	
	/******************************************/
	/* 	プライオリディコードの変換を行う	  */
	/******************************************/
	
	if( (strcmp(pcTmpPriCode, "EMERG") ) == 0 )			
	{
		return(LOG_EMERG);
	}
	
	if( (strcmp(pcTmpPriCode, "ALERT") ) == 0 )
	{
		return(LOG_ALERT);
	}	
	
	if( (strcmp(pcTmpPriCode, "CRIT") ) == 0 )
	{
		return(LOG_CRIT);
	}	
	
	if( (strcmp(pcTmpPriCode, "ERR") ) == 0 )
	{
		return(LOG_ERR);
	}
	
	if( (strcmp(pcTmpPriCode, "WARNING") ) == 0 )
	{
		return(LOG_WARNING);
	}
	
	if( (strcmp(pcTmpPriCode, "NOTICE") ) == 0 )
	{
		return(LOG_NOTICE);
	}
	
	if( (strcmp(pcTmpPriCode, "INFO") ) == 0 )
	{
		return(LOG_INFO);
	}

	if( (strcmp(pcTmpPriCode, "DEBUG") ) == 0 )
	{
		return(LOG_DEBUG);
	}

	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	
	return(-1);											// SYSLOGのプライオリディコードと
														// 合致しないときエラーメッセージを返却

}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ os_SearchJIS(short* ptr, long start, long end, long target)					  	*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ JIS codeをサーチする															*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	文字配列															*/
/*  	パラメーター(2)	 -  文字配列で先頭の位置												*/
/*		パラメーター(3)	 -  文字配列で最後の位置												*/
/*		パラメーター(4)	 -  目標																*/
/*																								*/
/*	リターン:																					*/
/*		成功 (その目標は文字配列にはいる位置）													*/
/*		失敗 (-1)																				*/
/*																								*/
/************************************************************************************************/
long os_SearchJIS(short* ptr, long start, long end, long target)
{
	
	long mid;											// 目標の位置
	
	if (start == end)									// 最初の位置が最後の位置と合致する場合
	{
		
		if (target == ptr[start])						// 配列の最初の位置
		{
	
			return start;								// 目標が見つかったら返却する
		}
		else
		{
			
			return (-1);
		}
	}
	else
	{
		
		mid = (start + end) / 2;						// 間中のところ

		if (target == ptr[mid])							// 目標が見つかったら返却する
		{
			
			return mid;
		}
		else
		{
			if (target > ptr[mid])						// 目標が見つからなかったら返却する
			{
														// 右のところへ
				return os_SearchJIS(ptr,mid+1,end,target);
			}
			else
			{
														// 左のところへ	
				return os_SearchJIS(ptr,start,mid-1,target);
			}
		}
	}
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ os_ChangeCode(char *pcMsgSig, short *after, long lBufStart, long lBufEnd,		*/ 
/*							 char *pcMsg)													  	*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ 文字配列中のテーダを逆転する													*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	埋め込み文字列１													*/
/*  	パラメーター(2)	 -  EUCコード															*/
/*		パラメーター(3)	 -  変換範囲の先頭														*/
/*		パラメーター(4)	 -  変換範囲の最後														*/
/*		パラメーター(5)	 -  データ格納バッファ													*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_ChangeCode(char *pcMsgSig, short *after, long lBufStart, long lBufEnd, char *pcMsg)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lRet = 0;										// 返却値	

	long lCnt = 0;										// カウンタ
	
	short sTemp = 0;									// 変換コード TBCS0123
	
	long lSize = 0;										// 変換されたバイト数 TBCS0123
	
	char *pcWork = NULL;								// 変換用の領域 TBCS0123
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	
	pcWork = (char*)malloc( lBufEnd * 2 );				// TBCS0123
		
	for (lCnt = lBufStart; lCnt < lBufEnd; lCnt++)
	{													// JISコードを検索
		
		sTemp = 0x00ff & pcMsgSig[lCnt]; 				// TBCS0123
		
		lRet=os_SearchJIS(before, 0, 89, sTemp);    

		DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (5) lRet == %ld\n", lRet) );	

		if(lRet != -1)									// 合ったらＥＵＣを変換
		{

			if( (after[lRet] & 0xff00) != 0x0000 )		// TBCS0123
			{
					
				pcWork[lSize] = after[lRet] >> 8;		// TBCS0123
				
				pcWork[lSize+1] = after[lRet];			// TBCS0123
				
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (9) pcWork == %08x\n", pcWork[lSize]) );
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (10) pcWork == %08x\n", pcWork[lSize+1]) );
				
				lSize += 2;								// TBCS0123
			}
			else
			{
				pcWork[lSize] = after[lRet];			// TBCS0123
				
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (11) pcWork == %08x\n", pcWork[lSize]) );
				
				lSize += 1;								// TBCS0123
			}
			
		}
		else
		{
			pcWork[lSize] = pcMsgSig[lCnt];
			
			lSize += 1;
		}
		
	}
	
	os_EditString(pcWork, pcMsg, 0, lSize);				// TBCS0123

 	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	
	free(pcWork);										// TBCS0123

}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ long os_Time( long lHour, long lMin)											  	*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ 時間の取得																		*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	時																	*/
/*  	パラメーター(2)	 -  分																	*/
/*																								*/
/*																								*/
/*	リターン:																					*/
/*		成功 (現在の時間）																		*/
/*		失敗 (D_OSWRITE1_OUTPUT_ERROR)															*/
/*																								*/
/************************************************************************************************/
long os_Time( long *lHour, long *lMin)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lDay = 0;										// 日日

	long lTime = 0;										// 時間

	long lRet = 0;										// 現在時間の返却値
	
		
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	lRet = osgtdat(&lDay, &lTime);						// 日付及び時刻の取得
	
	if(lRet !=NORMAL)									// 異常時
	{
		return(0x940d);				// エラーメッセージを返却
	}
	
    *lHour = ( lTime >> 16 ) & 0x0000000f;				// 時の1の位を取得
    
    *lHour += ( ( lTime >> 20 ) & 0x0000000f) * 10;		// 時の10の位を取得
   
    *lMin = ( lTime  >> 8 ) & 0x0000000f;				// 分の1の位を取得
    									
    *lMin += ( ( ( lTime >> 12 ) & 0x0000000f ) * 10 );	// 分の10の位を取得			
   
 
   	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	
	return(lRet);										// 時刻を返却
	
} 


/************************************************************************************************/
/*																								*/
/*	＜関数名＞ long os_SeekStr(char *pcPtr, char cTarget, long lStart, long lEnd)				*/
/*                                	     			    										*/
/*																								*/
/*	＜機能概要＞ メッセージ配列の指定範囲を取得													*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	文字配列															*/
/*  	パラメーター(2)	 -	目標																*/
/*		パラメーター(3)	 -  先頭の位置															*/
/*		パラメーター(4)	 -  最後の位置															*/
/*																								*/
/*	リターン:																					*/
/*		成功 (出力指示文字)																		*/
/*		失敗 (D_OSWRITE1_ERROR)																	*/
/*																								*/
/************************************************************************************************/
long os_SeekStr(char *pcPtr, char cTarget, long lStart, long lEnd)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lCnt;											// ループのカウンタ
	 
    
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	
	if(lStart >= 0)
	{													//目標を検索
		for(lCnt = lStart; lCnt < lEnd; lCnt++) 
		{
			if(pcPtr[lCnt] == cTarget) 					// 合致したら
			{
				
				return(lCnt);							// 位置を返却
			}
		
		}
	}


 	/********************************************************************************************/
	/*  処理終了				                                                                */
	/********************************************************************************************/
	
	return(-1);											// エラーメッセージを返却
	
}	

