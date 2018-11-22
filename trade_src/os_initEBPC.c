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
/* ＜モジュールＩＤ＞				 os_initEBPC												*/
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
/*		バッファプール管理テーブルの領域確保を共用メモリ内に確保して初期化を実施する			*/
/*		プールバッファ管理情報の初期化を実施する												*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initEBPC.h>																*/
/*																								*/
/*	   	long os_initEBPC(char *pcEbpcTableAdr)													*/
/*																								*/
/* ＜仮引数＞																					*/
/*		char	*pcEbpcTableAdr;		プロセステーブル管理テーブル情報のアドレス				*/
/*																								*/
/* ＜返却値＞																					*/
/*	   	正常終了	NORMAL																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   os_initSystem内でのみ使用する。															*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 os_iniEBPC.c																	*/
/*																								*/
/*	＜機能概要＞ バッファプール管理テーブルの領域確保を共用メモリ内に確保して初期化を実施する	*/
/*				 プールバッファ管理情報の初期化を実施する										*/
/*																								*/
/************************************************************************************************/
long os_initEBPC(char *pcEbpcTableAdr)
{
	TEbpcTableInd *ptEbpcInd = NULL;			// バッファプール管理テーブル個別部情報
	
	/********************************************************************************************/
    /*  ＳＧ設定ワーク領域                          						 					*/
    /********************************************************************************************/
	long lEbpcKbt = 0;							// バッファプール個別部数
	long lBpAdr = 0;							// バッファプール領域先頭アドレス
	long lBpSize = 0;							// バッファプール領域サイズ
	long lBpLMSize = 0;							// bufferプールLM最大数
	long lKeyId = 0;							// Key生成用ID(ntok)
	long lMemAccess = 0;						// 共用メモリアクセス権初期値 D_SEM_ACCESS 0666
	long lLmId = 0;								// LM個別部識別子 個別部[0]〜
	long lCmId = 0;								// CM個別部識別子 個別部[バッファプールLM数]〜
	long lSemNum = 0;							// セマフォ集合数
	char acGenKeyNum[9];						// バッファプール領域共有メモリKey(ntok)
	char acBpShmKey[9];							// バッファプール領域セマフォKey(ntok)
	char acPbShmKey[9];							// プールバッファ領域排他用セマフォKey最小値
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/	
	long *plShmAdr = NULL;						// 共有メモリ先頭アドレス
	long lMemkey = 0;						// 共有メモリKey
	long lCnt = 0;								// ループカウンタ
	long lRes = 0;
	int iShmId;									// 共有メモリIDを指定
	
	DbgMsg01(DLv02, (OutPut, "***** Start os_initEBPC\n"));
	/********************************************************************************************/
	/*	 初期処理																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  引数の確認                  */
	/*------------------------------*/
	if(NULL == pcEbpcTableAdr)					/* 引数がNULLの時は異常処理             */
	{	
		DbgMsg01(DLv05, (OutPut, "***** %s 01:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRARG );						/*　バッファ管理テーブル先頭アドレス不正*/
	}
	
	/*------------------------------*/
	/*  SGの読み込み                */
	/*------------------------------*/

	lKeyId = D_NTOK_ID;						/* 共有メモリKey読み込み                */
	
	lMemAccess = D_SEM_ACCESS;					/* 共用メモリアクセス権初期値読み込み   */
	
	lCmId = D_EBPC_CM_ID;
//	DbgMsg01( DLv04, ( OutPut, "***** lCmId :%08x\n", lCmId));
	
	lLmId = D_EBPC_LM_ID;
//	DbgMsg01( DLv04, ( OutPut, "***** lLmId :%08x\n", lLmId));

	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);	// EBPC個別部数読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}

	lRes = os_getSG(D_SG_EBPC_MAX_SIZE,&lBpSize);	// バッファプール領域サイズの読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}

	lRes = os_getSG(D_SG_EBPC_ADR,&lBpAdr);	// バッファプール領域先頭アドレス読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}

	lRes = os_getSG(D_SG_EBPC_LM_NUM,&lBpLMSize);	// バッファプールLM最大数読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lBpLMSize:%d\n", lBpLMSize));

	lRes = os_getSG(D_SG_EBPC_GKEY,acGenKeyNum);	// Key生成文字列読み込み バッファプール領域共有メモリ
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}
	
	lRes = os_getSG(D_SG_EBPC_FIL_SKEY,acBpShmKey);	// Key生成文字列読み込み バッファプール領域セマフォ
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}

	lRes = os_getSG(D_SG_EBPC_PB_SKEY,acPbShmKey);	// Key生成文字列読み込み プールバッファ領域排他用セマフォ
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);	// Key生成文字列読み込み プールバッファ領域排他用セマフォ
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*ＳＧ読込失敗　*/
	}

	/*------------------------------*/
	/*  設定領域の構造化            */
	/*------------------------------*/
	// 「バッファプール管理テーブル先頭アドレス」に「バッファプール管理テーブル管理部情報」を割り当て
	ptEbpc = (TEbpcTable*) pcEbpcTableAdr;		
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc: %x\n", ptEbpc));
	
	// 個別部の先頭アドレスを求め、EMBC個別部情報に当てる
	ptEbpcInd = (TEbpcTableInd*) ( (long)ptEbpc + sizeof(TEbpcTable) );
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpcInd: %x\n", ptEbpcInd));

	/********************************************************************************************/
	/*	 本処理 (管理部情報の初期化)															*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/* 値の設定		                */
	/*------------------------------*/
	// 領域識別子にEBPC識別子を指定
	strncpy(ptEbpc->acTid, D_EBPC_TID, 4 );
	//DbgMsg01(DLv04, (OutPut, "***** EBPC領域識別子: %s\n", ptEbpc->acTid));
	
	ptEbpc->lShmKey = (long)acGenKeyNum;		// バッファプール領域共有メモリKey格納
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lShmKey: %lx\n", ptEbpc->lShmKey));
	
	// バッファプールサイズにBP領域サイズを格納
	ptEbpc->lSize = lBpSize;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSize: %ld\n", ptEbpc->lSize));
	
	ptEbpc->lLmNum = lBpLMSize;					//  バッファプールLM最大数格納
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lLmNum: %ld\n", ptEbpc->lLmNum));
	
	//バッファプール最大数にEBPC個別部数を格納
	ptEbpc->lMaxNum = lEbpcKbt;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lMaxNum: %ld\n", ptEbpc->lMaxNum));

	/*------------------------------*/
	/* 共用メモリkeyの生成          */
	/*------------------------------*/
	// 共有メモリkeyの生成
	// 富士通殿提供関数(ntok)を発行する	
	lMemkey = BlpMpf_ntok(acGenKeyNum, lKeyId);
	
	// 返却値が-1の場合はエラーメッセージ
	if(-1 == lMemkey)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 02:Err ess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRNTOK );						/*	共有メモリキー作成異常　*/
	}
//	DbgMsg01(DLv04, (OutPut, "***** ntok lMemkey :%x\n", lMemkey));
	
	/*------------------------------*/
	/* 共有メモリの確保             */
	/*------------------------------*/
	// システムコール (shmget) を発行する
	iShmId = shmget(lMemkey, lBpSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)							// 返却値が-1の場合はエラーメッセージ
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 03:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSHMGET );						/*　共有メモリ確保失敗　*/
	}
	
	// 返却値を共有メモリIDに格納
	ptEbpc->lShmId = iShmId;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lShmId :%lx\n", ptEbpc->lShmId));
	
	/*------------------------------*/
	/* 共有メモリの操作             */
	/*------------------------------*/
	// システムコール (shmat) を発行する

	if(0 == lBpAdr)
	{
		plShmAdr = shmat(iShmId, NULL, 0);
	}
	else
	{
		plShmAdr = shmat(iShmId, (void *)lBpAdr, SHM_RND);
	}
	// 返却値が-1の場合はエラーメッセージ		
	if(D_ERR_SYS == (long)plShmAdr)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 04:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSHMAT );							/*　共有メモリ付加異常　*/
	}
	
	// バッファプール先頭アドレスに格納
	ptEbpc->pvAdr = (void*)plShmAdr;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr));
	
	/*------------------------------*/
	/* バッファプール領域の初期化   */
	/*------------------------------*/
	plShmAdr = memset((void *)(ptEbpc->pvAdr), 0, lBpSize);
	if(-1 == (long)plShmAdr)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 05:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRMEMSET );							/*　共有メモリ初期化異常　*/
	}
	
	/*------------------------------*/
	/* 領域排他用セマフォKey生成    */
	/*------------------------------*/
	lMemkey = BlpMpf_ntok(acBpShmKey,lKeyId);
	if(-1 == lMemkey)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 06:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRNTOK );							/*　排他用セマフォKey生成失敗　*/
	}
//	DbgMsg01(DLv04, (OutPut, "***** lMemkey :%x\n", lMemkey));
	
	iShmId = semget(lMemkey, lSemNum, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSEMGET );							/*　排他用セマフォＩＤ取得失敗　*/
	}
	
	ptEbpc->lSemId = iShmId;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSemId :%d\n", iShmId) );
	
	// セマフォの制御操作
	uSem.val = 1;								// uSemはoscom_insで定義済み
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	if(NORMAL != lRes)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07-1:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return(OSERRSEMCTL);					// 20021226 追加
	}
	
	/*------------------------------*/
	/* 個別部情報の初期化           */
	/*------------------------------*/
//	DbgMsg01(DLv04, (OutPut, "***** 個別部初期化\n") );
//	DbgMsg01(DLv04, (OutPut, "***** lBpLMSize:%d\n", lBpLMSize));
	// プール識別子の設定でEBPC個別部に指定する
	for(lCnt = 0; lCnt < lEbpcKbt ; lCnt++)
	{
		if(lCnt < lBpLMSize)
		{
			(ptEbpcInd + lCnt)->lPoolId = lLmId + lCnt;	// 個別部[0]〜[LM数]
		}
		else
		{
			(ptEbpcInd + lCnt)->lPoolId = lCmId + (lCnt - lBpLMSize);	// 個別部[LM数]〜[個別部数]
		}
//		DbgMsg01(DLv04, (OutPut, "***** (ptEbpcInd + %3d)->lPoolId : %08x\n", lCnt, (ptEbpcInd + lCnt)->lPoolId));
		/*------------------------------*/
		/* 領域排他用セマフォKey生成    */
		/*------------------------------*/
		lRes = strtol(acPbShmKey, NULL, 16);
		lRes = lRes + lCnt;
		sprintf(acPbShmKey,"%08lx", lRes);
		
		lMemkey = BlpMpf_ntok(acPbShmKey,lKeyId);
		if(-1 == lMemkey)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 08:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return( OSERRNTOK );						/*　排他用セマフォKey生成失敗　*/
		}
		
//		DbgMsg01(DLv04, (OutPut, "***** lMemkey+%d :%x\n", lCnt, lMemkey));
		iShmId = semget(lMemkey, lSemNum, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
		if(-1 == iShmId)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return( OSERRSEMGET );						/*　排他用セマフォＩＤ取得失敗　*/
		}
		
		(ptEbpcInd + lCnt)->lSemId = iShmId;
//		DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSemId :%d\n", iShmId) );
		
			// セマフォの制御操作
		uSem.val = 1;								// uSemはoscom_insで定義済み
	
		lRes = semctl(iShmId, 0, SETVAL, uSem);
		if(NORMAL != lRes)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 07-1:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return(OSERRSEMCTL);					// 20021226 追加
		}
	}
	
	/********************************************************************************************/
	/*	 終了処理																				*/
	/*																							*/
	/********************************************************************************************/
	DbgMsg01(DLv02, (OutPut, "***** End os_initEBPC\n"));
	return(NORMAL);
}
