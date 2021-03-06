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
/* ＜サービス項目名＞				 終了処理													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 プロセス終了												*/
/* ＜モジュールＩＤ＞				 os_endProcess												*/
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
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７４）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		プロセスで確保しているテーブルの解放を行う。											*/
/*		又はプロセスが保持しているプールバッファを解放。										*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_endProcess.h>															*/
/*																								*/
/*		long	os_endProcess()																	*/
/*																								*/
/* ＜仮引数＞																					*/
/*		なし																					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		なし																	*/
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>


/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include "os_endProcess.h"
#include "os_endProcess_ins.h"

/************************************************************************************************/
/*	内部関数											             							*/
/*																								*/
/************************************************************************************************/
long os_freeEmbc();
long os_freePb();


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 os_endProcess()																*/
/*																								*/
/*	＜機能概要＞ プロセスで確保しているテーブルの解放を行う。                 				    */
/*		 		 又はプロセスが保持しているプールバッファを解放。  								*/
/*  																							*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*																								*/
/*																								*/
/************************************************************************************************/

long os_endProcess()
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/	
	long lRet[D_RETNCOUNT] = {0, 0, 0, 0, 0};				// 返却値	
	
	long lCnt = 0;											// for ルーブカウンタ
	
	long lEflcSemId = 0;									// ファイル管理情報セマファID
	
	long lErdcSemId = 0;									// rd管理情報セマファID
	
	long lEtmcSemId = 0;									// タイマ管理情報セマファID
	
	long lDetailCode = 0;									// 詳細コード
	
	long lEndCode = 0;										// 終了コード
	
															// 関数入口
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", "os_endProcess" ) ); 
	os_trcget2(D_MD_OS_ENDPROCESS, D_T_TRA_IN, 0 );
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/	
	/********************************************/
	/* 入力情報を設定							*/
	/********************************************/

	
	lEflcSemId = ptEsys->tMstEFLC.lSemId;					// ファイル管理情報セマファIDを設定
	lErdcSemId = ptEsys->tMstERDC.lSemId;					// rd管理情報セマファIDを設定
	lEtmcSemId = ptEsys->tMstETMC.lSemId;					// タイマ管理情報セマファIDを設定
	
	/********************************************/
	/* メイルボックスの解放					    */
	/********************************************/
	DbgMsg01( DLv03, ( OutPut, "***** %s:Call Function:\n", "os_freeEmbc" ) );
															// 子関数呼出前
															
	//lRet[0] = os_freeEmbc();								//メイルボックスの解放
	lRet[0] = NORMAL;										//は行わない
	
	if(lRet[0] != NORMAL)									// エラーの時 
	{
		lRet[0] = D_MD_OS_FREEEMBC;							// モジュールIDを設定
	}	
	
	DbgMsg01( DLv03, ( OutPut, "***** :Return Function:%s Ret[0]=%08lx\n", "os_freeEmbc", lRet[0] ) );
															// 子関数呼出後
		
	DbgMsg01( DLv04, ( OutPut, "*****  メイルボックスの解放 == %08lx\n", lRet[0]) );
	
	/********************************************/
	/* プールバッファの解放					    */
	/********************************************/
	DbgMsg01( DLv03, ( OutPut, "***** Call Function:%s\n", "os_freePb" ) );
															// 子関数呼出前
															
	lRet[1] = os_freePb();									//プールバッフの解放
	
	if(lRet[1] != NORMAL)									// エラーの時
	{
		lRet[1] = D_MD_OS_FREEPB;							// モジュールIDを設定
	}
	
	DbgMsg01( DLv03, ( OutPut, "***** Return Function:%s Ret[1]=%08lx\n", "os_freePb", lRet[1] ) );
															// 子関数呼出後
	
	DbgMsg01( DLv04, ( OutPut, "*****  プールバッフの解放 == %08lx\n", lRet[1]) );	

	/********************************************/
	/* セマフォＩＤの削除						*/
	/********************************************/
#ifdef USESEM

	lRet[2] = semctl(lEflcSemId, 0, IPC_RMID, NULL);		//ファイル管理情報セマファIDを削除
	
	if(lRet[2] != NORMAL)									// エラーの時
	{
		lRet[2] = D_T_SYS_SEMCTL;							// モジュールIDを設定
	}

	DbgMsg01( DLv04, ( OutPut, "*****  ファイル管理情報セマファIDを削除 == %ld\n", lRet) );
	
	lRet[3] = semctl(lErdcSemId, 0, IPC_RMID, NULL);		// rd管理情報セマファIDを削除
	
	if(lRet[3] != NORMAL)									// エラーの時
	{
		lRet[3] = D_T_SYS_SEMCTL;							// モジュールIDを設定
	}

	DbgMsg01( DLv04, ( OutPut, "*****  rd管理情報セマファIDを削除 == %ld\n", lRet) );
	
	lRet[4] = semctl(lEtmcSemId, 0, IPC_RMID, NULL);		// タイマ管理情報セマファIDを削除
	
	if(lRet[4] != NORMAL)									// エラーの時
	{
		lRet[4] = D_T_SYS_SEMCTL;							// モジュールIDを設定
	}
	
	DbgMsg01( DLv04, ( OutPut, "*****  タイマ管理情報セマファIDを削除 == %ld\n", lRet) );

#endif	

	/********************************************************************************************/
	/*	 処理終了																				*/
	/********************************************************************************************/	
															// 関数出口
	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", "os_endProcess" ) );		
	
	
	for(lCnt = 0; lCnt < D_RETNCOUNT; lCnt++)				// 正常じゃない場合	
	{
		if(lRet[lCnt] != NORMAL)
		{
			lDetailCode = (D_MD_OS_ENDPROCESS << 16) | lRet[lCnt];
			
			lEndCode = os_EndCod(D_END_TYPE1);
			
			os_trcget2( D_MD_OS_ENDPROCESS, D_T_ERR_ABT, 0 );
			
			os_abort(lEndCode, lDetailCode, 1);				// os_abort()
		}
	}
	
	os_trcget2( D_MD_OS_ENDPROCESS, D_T_TRA_OUT, 0);
	return(NORMAL);
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 os_freeEmbc()																	*/
/*																								*/
/*	＜機能概要＞ 当該プロセスが確保したままのサブメッセージキューを確認し、						*/
/*  			 確保中のものを全て解放する。													*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (OSERRSHMCTL) or (OSERRMSGCTL)														*/
/*																								*/
/************************************************************************************************/
long os_freeEmbc()
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/	
	long lRet = 0;											// 返却値

	TMsgInfo *ptMsgInfoBef = NULL;							// 前メッセージアドレス
	
	TMsgInfo *ptMsgInfoBefTemp = NULL;						// 前メッセージアドレス
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	if(ptMyEMBC->lMsgQId != 0)
	{
		DbgMsg01( DLv04, ( OutPut, "***** (A) !=0  ptMyEMBC->lMsgQId == %ld\n", 
				ptMyEMBC->lMsgQId) );
		
		lRet = msgctl(ptMyEMBC->lMsgQId, IPC_RMID, NULL);	// メッセージキューを削除
		
		DbgMsg01( DLv04, ( OutPut, "***** (B) メッセージキューを削除 == %ld\n", lRet) );
	
	}	
	
	DbgMsg01( DLv04, ( OutPut, "***** (C) ==0  ptMyEMBC->lMsgQId == %lx\n", 
			ptMyEMBC->lMsgQId) );
	
	ptMsgInfoBef = ptMyEMBC->tSubMsgQ.ptBefAdr; 			// 最後メッセージアドレス
	
	DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (0) ptMsgInfoBef == %x\n", ptMsgInfoBef) );

	while(ptMsgInfoBef != NULL) 
	{
															// 次メッセージアドレス
		ptMsgInfoBefTemp = (TMsgInfo*)ptMsgInfoBef->ptBefAdr;
					
		DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (0.1) ptMsgInfoBefTemp == %x\n", ptMsgInfoBefTemp) );
		
		if(ptMsgInfoBefTemp != NULL)
		{
															// サブメッセージキューを削除
			lRet = shmctl(ptMsgInfoBefTemp->lShmId, IPC_RMID, NULL);
			
			DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (0.2) lRet == %x\n", lRet) );		
			
			if(lRet != NORMAL)
			{
				DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (0.3) lRet == %x\n", lRet) );	
				
				os_trcget2( D_MD_OS_FREEEMBC, D_T_SYS_SHMCTL, 1, ptMsgInfoBefTemp->lShmId);
			}
			else
			{
				
				DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (1) before lMsgCnt == %ld\n", ptMyEMBC->tSubMsgQ.lMsgCnt) );
				
				DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (2) == %08x\n", lRet) );
				
				ptMyEMBC->tSubMsgQ.lMsgCnt -= 1;			// メッセージ格納数1個を減る
				
				DbgMsg01( DLv04, ( OutPut, "\n######## FREEEMBC (3) after lMsgCnt == %ld\n", ptMyEMBC->tSubMsgQ.lMsgCnt) );
			}
						
			ptMsgInfoBef = (TMsgInfo*)ptMsgInfoBefTemp;		
			
		}
		else
		{
			ptMsgInfoBef = (TMsgInfo*)ptMsgInfoBef->ptBefAdr;
		}
		
	}

	DbgMsg01( DLv04, ( OutPut, "***** (D) ptMyEMBC->tSubMsgQ.lMsgCnt == %ld\n", 
			ptMyEMBC->tSubMsgQ.lMsgCnt) );											   
		
	ptMyEMBC->acPName[0] = '\0';							// プロセス名を初期化
		
	DbgMsg01( DLv04, ( OutPut, "***** (E) ptMyEMBC->acPName == %s\n", ptMyEMBC->acPName) );

	DbgMsg01( DLv04, ( OutPut, "***** (F) os_freeEmbc() 処理終了\n") );
	
	/********************************************************************************************/
	/*	 処理終了																				*/
	/********************************************************************************************/	
	return(lRet);
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 os_freePb()																	*/
/*																								*/
/*	＜機能概要＞ 当該プロセスが確保したままのをプールバッファ確認し、							*/
/*  			 確保中のものを全て解放する。													*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (OSERRARG) 																		*/
/*																								*/
/************************************************************************************************/
long os_freePb()
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lCnt1 = 0;											// for ループカウンタ
	
	long lRet = 0;											// 返却値
	
	long lPbfNum = 0;										// プールバッファ個数
	
	void *ptEpbcAdrLst = NULL;								// ユニットアドレス
	
	TEpbcTableInd *ptEpbcInd = NULL;						// プールバッファアドレス
/*****  障害対応（TBCS0274）    Start                                   修正日：2003.08.11  *****/
	long lCommonRet = 0;
/*****  障害対応（TBCS0274）    End                                     修正日：2003.08.11  *****/

	/********************************************************************************************/
	/*	 初期処理																				*/
	/********************************************************************************************/
	/*------------------------------------------*/
	/* バッファプール確認					    */
	/*------------------------------------------*/
	if(ptEbpc == NULL)										// テーブルの確認
	{
		return(OSERRARG);
	}

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	lRet = os_getSG(D_SG_EPBC_NUM, &lPbfNum);
	
	if(lRet != NORMAL)
	{
		return(lRet);
	}	
	
	if(lPbfNum <= 0)
	{
		return(OSERRARG);
	}
	 
	ptEpbcInd = (TEpbcTableInd *)(ptEpbc +	1);				// プールバッファ管理部情報の定義
	
	for(lCnt1=0; lCnt1 < lPbfNum; lCnt1++)
	{
															// プールバッファの使用プロセスIDが
															// 自プロセスIDと合致する場合と
															// 使用中の時
		if((((TEpbcTableInd *)ptEpbcInd+lCnt1)->lUsePid == lMyPid) &&
			(((TEpbcTableInd *)ptEpbcInd+lCnt1)->cUnit != 0))				
		{													
															// ユニット管理情報の
															// ユニットアドレスを設定
			ptEpbcAdrLst = ((TEpbcTableInd *)ptEpbcInd+lCnt1)->pvUnitAdr;	
			
			lRet = osfrpbf(1, &ptEpbcAdrLst);				// プールバッファを解放
					
			DbgMsg01( DLv04, ( OutPut, "***** os_freePb (1) lRet == %08x\n", lRet) );
/*****  障害対応（TBCS0274）    Start                                   修正日：2003.08.11  *****/
			if( lRet != NORMAL )
			{
				lCommonRet = lRet;
			}
		}		
	}
	/********************************************************************************************/
	/*	 処理終了																				*/
	/********************************************************************************************/	
	return(lCommonRet);
/*****  障害対応（TBCS0274）    End                                     修正日：2003.08.11  *****/
}

