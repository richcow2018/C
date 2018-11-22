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
/* ＜モジュールＩＤ＞				 os_initERDC												*/
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
/*	 os_initERDC	ダミー関数																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initERDC.h>																*/
/*																								*/
/*	   	long	os_initERDC(TTblInfo *ptErdcTableAdr);											*/
/*																								*/
/* ＜仮引数＞																					*/
/*		TTblInfo *ptErdcTableAdr	rd管理情報の格納アドレス									*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   os_initProcess内でのみ使用する。															*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/

/************************************************************************************************/
/*								標準ヘッダ・ファイル                  							*/
/*																								*/
/************************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initERDC(TTblInfo *ptErdcTableAdr)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TErdcTableInd *ptErdcTblInd = NULL;		// ERDC個別部
	TEprcTableInd *ptEprcTblInd = NULL;		// EPRC個別部
	long lKeyId;							// Key生成用ID(ntok)
	long lMemAccess;						// 共用メモリアクセス権初期値 D_SEM_ACCESS 0666
	char acRdShmKey[9];						// rd管理テーブル排他用セマフォKey(ntok)
	char acSgKeyTemp[9];
	long lSemNum;							// セマフォ集合数
	
	long lMaxReqNum;						// 自プロセス リクエスト識別子最大個数格納用
	long lRes;
	long lTemp;
	long *plRes = NULL;
	long lCnt = 0;
	long lReqId = 0;							// リクエスト識別子格納用
	int iShmId;
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initERDC\n" ) );
	
	/*	引数チェック	*/
	if(NULL == ptErdcTableAdr)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  01:Err Mess:%s\n", strerror(errno)) );
		return( OSERRARG );						//rd管理情報の格納アドレス不正
	}
	
	/*--------------------------------------*/
	/*  SG読み込み                          */
	/*--------------------------------------*/
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み開始\n"));
	
	lKeyId = D_NTOK_ID;						/* 共有メモリKey読み込み                */
	
	lMemAccess = D_SEM_ACCESS;					/* 共用メモリアクセス権初期値読み込み   */
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);		// セマフォ集合数読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常
	}
	
	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	lRes = os_getSG(D_SG_ERDC_HAITA_SKEY,acSgKeyTemp);		// ERDC排他用み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                      //ＳＧ読込異常
	}
	lRes = os_KeyGen(acSgKeyTemp, acRdShmKey);
//	DbgMsg01( DLv04, ( OutPut, "***** acRdShmKey : %s\n", acRdShmKey));
	#endif
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み終了\n"));
/****************************************/
/*	本処理								*/
/****************************************/
	ptEprcTblInd = (TEprcTableInd *)(ptEsys->tMyPrcInfo.ptMyEPRC);
	lMaxReqNum = ptEprcTblInd->lMaxReqNum;	/*	リクエスト識別子最大個数格納 */
//	DbgMsg01( DLv04, ( OutPut, "***** lMaxReqNum :%d\n", lMaxReqNum) );

	/*	rd管理情報のサイズに管理部と個別部最大数のサイズを格納する*/
	ptErdcTableAdr->lSize = sizeof(TErdcTable) + sizeof(TErdcTableInd) * lMaxReqNum;
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdcTableAdr->lSize :%d\n", ptErdcTableAdr->lSize) );
	
	/*	領域の確保	*/
	plRes = calloc((ptErdcTableAdr->lSize), sizeof(char));
	if(NULL == plRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  02:Err Mess:%s\n", strerror(errno)) );
		return( OSERRCALLOC );					//領域確保失敗
	}
	
	ptErdcTableAdr->pvAdr = (void *)plRes;		/*	アドレスを割り当てる	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdcTableAdr->pvAdr :%x\n", ptErdcTableAdr->pvAdr));
	
	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	/*	セマフォの生成	*/
	lRes = BlpMpf_ntok(acRdShmKey, lKeyId);
	if(-1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  03:Err Mess:%s\n", strerror(errno)) );
		return( OSERRNTOK );						//セマフォKey作成失敗
	}
	
	lTemp = lRes;
	
	/*	セマフォIDの取得	*/
	iShmId = semget(lTemp, lSemNum, lMemAccess | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  04:Err Mess:%s\n", strerror(errno)) );
		return( OSERRSEMGET );						//セマフォＩＤ取得失敗
	}
	
	ptEsys->tMstERDC.lSemId = iShmId;				/*	ERDC管理部情報セマフォIDに格納	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstERDC.lSemId :%x\n", ptEsys->tMstERDC.lSemId));
	
		// セマフォの制御操作
	uSem.val = 1;								// uSemはoscom_insで定義済み
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	//if(NORMAL != lRes)						// 20021225 修正
	if(-1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  04-1:Err Mess:%s\n", strerror(errno)) );
		return(OSERRSEMCTL);					// 20021225 追加
	}
	
	#endif
	/*----------------------*/
	/*	管理部情報の初期化	*/
	/*----------------------*/
	
	/*	設定領域の構造化	*/
	ptErdc = (TErdcTable *)(ptEsys->tMstERDC.pvAdr);
	
	strncpy(ptErdc->acTid, D_ERDC_TID, 4);		/*	領域識別子登録	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc->acTid:%s\n", ptErdc->acTid));
	
	ptErdc->lMaxIndNum = lMaxReqNum;
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc->lMaxIndNum:%d\n", ptErdc->lMaxIndNum));
	
	/*----------------------*/
	/*	個別部情報の初期化	*/
	/*----------------------*/
	lTemp = lMaxReqNum;							/*	リクエスト識別子最大個数格納	*/
	ptErdcTblInd = (TErdcTableInd *)(ptErdc +1);/*	個別部先頭アドレス格納	*/
	for(lCnt = 0;lCnt < lTemp;lCnt++)
	{
		lReqId = lCnt + 1;						/*	１から順に入れていく	*/
		(ptErdcTblInd + lCnt)->lRCode = lReqId;	/*	リクエスト識別子格納	*/
//		DbgMsg01( DLv04, ( OutPut, "***** ptErdcTblInd[%d]->lRCode:%d\n", lCnt, (ptErdcTblInd + lCnt)->lRCode) );
	}
	
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initERDC\n" ) );
	return(NORMAL);
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
