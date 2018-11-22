/************************************************************************************************/
/* ＜呼出形式＞ 																				*/
/*		#include	"os_endSystem.h"															*/
/*																								*/
/*		long	os_endSystem(void)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long lShmId テーブル格納共有メモリID													*/
/*																								*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了																				*/
/*			NORMAL																				*/
/*																								*/
/*		以上終了																				*/
/*			OSERRARG	引数異常																*/
/*			OSERRESMC	共有メモリ管理テーブル終了異常											*/
/*			OSERREMBC	メールボックス管理テーブル終了異常										*/
/*			OSERREBPC	バッファプール管理テーブル終了異常										*/
/*			OSERRETRD	TRADEテーブル管理テーブル終了異常										*/
/*			OSERRSHMCTL	テーブル格納領域開放異常												*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	moaの終了処理でのみ使用可能とする。															*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	＜機能概要＞ 																				*/
/*		システム全体で使用しているテーブルの開放を行う											*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_endSystem.h"
#include "os_endSystem_ins.h"


long os_endSystem(long lShmId)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lRes = 0;
	long lErrFlg = NORMAL;

	struct sigaction new[D_MAX_SIG_NUM];	// D_MAX_SIG_NUMは設定シグナル数:31
	int iSigCnt = 0;
	
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endSystem\n"));
	os_trcget2(D_MD_OS_ENDSYSTEM, D_T_TRA_IN, 1, lShmId );
	
	//	引数チェック
	if(0 == lShmId)
	{
		//	異常処理
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endSystem" ) );
		return(OSERRARG);
	}

/****************************************/
/*	本処理								*/
/****************************************/
	//	各テーブルの終了処理
	//	共有メモリ管理テーブルの終了
	DbgMsg01( DLv03, ( OutPut, "***** In os_endESMC\n"));
	lRes = os_endESMC();
	if(NORMAL != lRes)
	{
		//	異常処理
		DbgMsg01( DLv05, ( OutPut, "***** Err02:%s\n", "os_endSystem" ) );
		//return(OSERRESMC);
		lErrFlg = OSERRESMC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endESMC\n"));
	
	//	メールボックス管理テーブルの終了
	DbgMsg01( DLv03, ( OutPut, "***** In os_endEMBC\n"));
	lRes = os_endEMBC();
	if(NORMAL != lRes)
	{
		//	異常処理
		DbgMsg01( DLv05, ( OutPut, "***** Err03:%s\n", "os_endSystem" ) );
		//return(OSERREMBC);
		lErrFlg = OSERREMBC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endEMBC\n"));
	
	//	バッファプール管理テーブルの終了
	DbgMsg01( DLv03, ( OutPut, "***** In os_endEBPC\n"));
	lRes = os_endEBPC();
	if(NORMAL != lRes)
	{
		//	異常処理
		DbgMsg01( DLv05, ( OutPut, "***** Err04:%s\n", "os_endSystem" ) );
		//return(OSERREBPC);
		lErrFlg = OSERREBPC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endEBPC\n"));
	
	//	TRADEテーブル管理テーブルの終了
	DbgMsg01( DLv03, ( OutPut, "***** In os_endTrade\n"));
	lRes = os_endTrade();
	if(NORMAL != lRes)
	{
		//	異常処理
		DbgMsg01( DLv05, ( OutPut, "***** Err05:%s\n", "os_endSystem" ) );
		//return(OSERRETRD);
		lErrFlg = OSERRETRD;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endTrade\n"));
	
	//	テーブル格納領域の開放
	DbgMsg01( DLv04, ( OutPut, "***** 共有メモリの開放開始\n"));
	lRes = shmctl( (int)lShmId, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err06:%s:%s\n", strerror(errno), "os_endSystem" ) );
			//return(OSERRSHMCTL);
			lErrFlg = OSERRSHMCTL;
		}
	}
	DbgMsg01( DLv04, ( OutPut, "***** 共有メモリの開放完了\n"));
	
	lRes = os_endSG();
	if(NORMAL != lRes)
	{
		lErrFlg = lRes;
	}
	
	lRes = os_freeSG();
	if(NORMAL != lRes)
	{
		lErrFlg = lRes;
	}
												// 全シグナルをデフォルトに戻す
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		new[iSigCnt].sa_handler = SIG_DFL;
		new[iSigCnt].sa_flags = 0;
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}

/****************************************/
/*	終了処理							*/
/****************************************/
	os_trcget2(D_MD_OS_ENDSYSTEM, D_T_TRA_OUT, 0 );
	DbgMsg01( DLv02, ( OutPut, "***** End os_endSystem\n"));
	
	//return(NORMAL);
	return(lErrFlg);

}


/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ＜呼出形式＞ 																				*/
/*																								*/
/*		long	os_endEsmc(void)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		なし																					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了																				*/
/*			NORAML																				*/
/*		異常終了																				*/
/*			OSERRARG	引数異常																*/
/*			OSERRSHMCTL	共有メモリ開放異常														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		os_endSystem関数内でのみ使用可能とする													*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	＜機能概要＞  																				*/
/*		共有メモリ管理テーブルの領域を初期化し、使用不可能な状態にする。						*/
/*																								*/
/************************************************************************************************/

long os_endESMC(void)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TEsmcTableInd *ptEsmcInd = NULL;
	TEsmcTableInd *ptEsmcIndTemp = NULL;
	long lCnt = 0;
	long lRes = 0;
	long lMaxNum = 0;
	long lErrFlg = NORMAL;
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endESMC\n"));
	
	if(NULL == ptEsmc)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endESMC" ) );
		return(OSERRARG);
	}

/****************************************/
/*	本処理								*/
/****************************************/
	ptEsmcInd = (TEsmcTableInd *)(ptEsmc + 1);
	
	lMaxNum = ptEsmc->lIndPartNum;
	
	for(lCnt = 0; lCnt < lMaxNum; lCnt++)
	{
		ptEsmcIndTemp = ptEsmcInd + lCnt;
		
		if(0 != ptEsmcIndTemp->lShmId)
		{
			lRes = shmctl(ptEsmcIndTemp->lShmId, IPC_RMID, NULL);
			if(NORMAL != lRes)
			{
				if( (EIDRM != errno) && (EINVAL != errno) )
				{
					DbgMsg01( DLv04, ( OutPut, "***** ptEsmcInd[%ld]->lShmId:%ld\n",
								lCnt, ptEsmcIndTemp->lShmId));
					DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n", strerror(errno),
								"os_endESMC" ) );
					//return(OSERRSHMCTL);
					lErrFlg = OSERRSHMCTL;
				}
			}
		}
	}
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endESMC\n"));
	
	//return(NORMAL);
	return(lErrFlg);

}

/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ＜呼出形式＞ 																				*/
/*																								*/
/*		long	os_endEMBC(void)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		なし																					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了																				*/
/*			NORMAL																				*/
/*		異常終了																				*/
/*			OSWRRARG	引数異常																*/
/*			OSERRSEMCTL	セマフォID削除異常														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		os_endSystem関数内でのみ使用可能とする。												*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	＜機能概要＞  																				*/
/*		メイルボックス管理テーブルの領域を初期化し、使用不可能状態にする。						*/
/*																								*/
/************************************************************************************************/

long os_endEMBC(void)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lRes = 0;
	long lErrFlg = NORMAL;
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endEMBC\n"));
	
	if(NULL == ptEmbc)							// 引数チェック
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endEMBC" ) );
		return(OSERRARG);
	}
	
/****************************************/
/*	本処理								*/
/****************************************/
	/*--------------------------------------*/
	/*  管理部情報の初期化                  */
	/*--------------------------------------*/
	lRes = semctl(ptEmbc->lSemId, 0, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n", strerror(errno), "os_endEMBC" ) );
			//return(OSERRSEMCTL);
			lErrFlg = OSERRSEMCTL;
		}
	}
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endEMBC\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ＜呼出形式＞ 																				*/
/*																								*/
/*		long	os_endEBPC(void)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		なし																					*/
/*																								*/
/* ＜返却値＞																					*/
/*		OSERRARG	引数異常																	*/
/*		OSERRSEMCTL	セマフォID削除異常															*/
/*		OSERRSHMCTL	共有メモリ削除異常															*/
/*																								*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		os_endSystem関数内でのみ使用可能とする													*/
/*																								*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	＜機能概要＞  																				*/
/*		バッファプール管理テーブルの領域を初期化し、使用不可能な状態にする。					*/
/*																								*/
/************************************************************************************************/

long os_endEBPC(void)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TEbpcTableInd *ptEbpcInd = NULL;			// EBPC個別部用
	TEbpcTableInd *ptEbpcIndTemp = NULL;		// EBPC個別部ワーク用
	long lRes = 0;
	long lCnt = 0;
	long lMaxKbt = 0;
	long lErrFlg = NORMAL;
	
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endEBPC\n"));
	
	if(NULL == ptEbpc)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endEBPC" ) );
		return(OSERRARG);
	}
	
	ptEbpcInd = (TEbpcTableInd *)(ptEbpc + 1);	//	EBPC個別部を取得

/****************************************/
/*	本処理								*/
/****************************************/
	/*----------------------------------------*/
	/*  個別部の初期化                        */
	/*----------------------------------------*/
	lMaxKbt = ptEbpc->lMaxNum;					//	最大個別部数取得

	for(lCnt = 0; lCnt < lMaxKbt; lCnt++)
	{
		ptEbpcIndTemp = ptEbpcInd + lCnt;
		if(0 != ptEbpcIndTemp->lSemId)
		{
			//	セマフォIDが存在する時はセマフォの初期化
			lRes = semctl(ptEbpcIndTemp->lSemId, 0,IPC_RMID, NULL);
			if( NORMAL != lRes)
			{
				if( (EIDRM != errno) && (EINVAL != errno) )
				{
					DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n",
							strerror(errno), "os_endEBPC" ) );
					//return(OSERRSEMCTL);
					lErrFlg = OSERRSEMCTL;
				}
			}
		}
	}
	/*----------------------------------------*/
	/*  管理部の初期化                        */
	/*----------------------------------------*/
	lRes = shmctl(ptEbpc->lShmId, IPC_RMID, NULL);	// 共有メモリの削除
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err03:%s:%s\n", strerror(errno), "os_endEBPC" ) );
			//return(OSERRSHMCTL);
			lErrFlg = OSERRSHMCTL;
		}
	}
	
	lRes = semctl(ptEbpc->lSemId, 0, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err04:%s:%s\n", strerror(errno), "os_endEBPC" ) );
			//return(OSERRSEMCTL);
			lErrFlg = OSERRSEMCTL;
		}
	}
	
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endEBPC\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ＜呼出形式＞ 																				*/
/*																								*/
/*		long	os_endTrade(void)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		なし																					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了																				*/
/*			NORMAL																				*/
/*		異常終了																				*/
/*			OSERRARG																			*/
/*			OSERRSEMCTL																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		os_endSystem関数内でのみ使用可能とする													*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	＜機能概要＞  																				*/
/*		TRADEテーブル管理テーブルの領域を初期化し、使用可能な状態にする							*/
/*																								*/
/************************************************************************************************/

long os_endTrade(void)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lRes = 0;
	long lCnt = 0;
	long laSemId[MAX_DEL_SIZE];			//	セマフォID格納配列
	long lErrFlg = NORMAL;
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endTrade\n"));
	//	引数チェック
	if(NULL == ptEtrd)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endTrade" ) );
		return(OSERRARG);
	}
	
		//	各テーブルのセマフォIDを格納
	laSemId[0] = ptEtrd->tTrdEPRC.lSemId;
	laSemId[1] = ptEtrd->tTrdEBPC.lSemId;
	laSemId[2] = ptEtrd->tTrdESBP.lSemId;
	laSemId[3] = ptEtrd->tTrdEPBC.lSemId;
	laSemId[4] = ptEtrd->tTrdEMBC.lSemId;
	laSemId[5] = ptEtrd->tTrdEMMC.lSemId;
	laSemId[6] = ptEtrd->tTrdESMC.lSemId;
	
/****************************************/
/*	本処理								*/
/****************************************/
	for(lCnt = 0; lCnt < MAX_DEL_SIZE; lCnt++)
	{
		DbgMsg01( DLv05, ( OutPut, "***** セマフォID : %ld\n", laSemId[lCnt]));
		lRes = semctl(laSemId[lCnt],0,IPC_RMID, NULL);
		if(NORMAL != lRes)
		{
			if( (EIDRM != errno) || (EINVAL != errno) )
			{
				DbgMsg01( DLv05, ( OutPut, "***** laSemId[%ld]:%ld\n", lCnt, laSemId[lCnt]));
				DbgMsg01( DLv05, ( OutPut, "***** Err02:%s :%s\n", strerror(errno),"os_endTrade"));
				//return(OSERRSEMCTL);
				lErrFlg = OSERRSEMCTL;
			}
		}
	}

/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endTrade\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
