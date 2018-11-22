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
/* ＜モジュールＩＤ＞				 os_initEFLC												*/
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
/*	 ファイル管理テーブルの領域確保をローカルメモリ内に確保して初期化を実施する					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initEPRC.h>																*/
/*																								*/
/*	   	long	os_initEPRC(TTblPtc *ptEflcTableAdr)											*/
/*																								*/
/* ＜仮引数＞																					*/
/*		TTblPtc		*ptEflcTableAdr;		ファイル管理テーブル先頭アドレス					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値	NORMAL																		*/
/*		異常戻り値	未決定																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	os_initSystem関数内でのみ使用可能とする														*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initEFLC(TTblInfo *ptEflcTableAdr)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TEprcTableInd *ptEprcTemp = NULL;
	char acSgKeyname[9];						// 排他用key 生成用文字列
	char acSgKeyTemp[9];
	long lSemAcc;								// セマフォアクセス初期値
	long lFlcKbt;								// EFLC個別部
	long lSgSemKey;								// 共有メモリKey(ntok用)
	long lSemNum;								//セマファ集合数を指定する 1
	long lMaxFileNum;							// ファイル記述子最大個数

	long *plRes;
	long lRes;									//返却用
	int iShmId;
/****************************************/
/*	初期処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initEFLC\n" ) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr : %x\n", ptEflcTableAdr ) );
	
	if( NULL == ptEflcTableAdr )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRARG );			//ファイル管理情報の格納領域アドレス不正
	}
	
	/****************************************/
	/*	SGの読み込み						*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み開始\n"));
	
	lSgSemKey = D_NTOK_ID;	// 共有メモリKey読み込み
		
	lSemAcc = D_SEM_ACCESS;	// メモリアクセス初期値読み込み

												// 20030307 修正 KL0027
//	lRes = os_getSG(D_SG_EFLC_NUM,&lFlcKbt);	// EFLC個別部読み込み
//	if(NORMAL != lRes)
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
//		return( OSERRSG );			//ＳＧ読込異常
//	}

	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	lRes = os_getSG(D_SG_EFLC_HAITA_SKY,acSgKeyTemp);	// EFLC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** acSgKeyTemp : %s\n", acSgKeyTemp));
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );          //ＳＧ読込異常
	}
	lRes = os_KeyGen(acSgKeyTemp, acSgKeyname);
//	DbgMsg01( DLv04, ( OutPut, "***** acSgKeyname : %s\n", acSgKeyname));
	#endif
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);	// セマフォ集合数読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );          //ＳＧ読込異常
	}
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み終了\n"));
	
									// 自プロセス管理部ポインタ格納
	ptEprcTemp = (TEprcTableInd *)(ptEsys->tMyPrcInfo.ptMyEPRC);
	lMaxFileNum = ptEprcTemp->lMaxFileNum;		// ファイル記述子最大個数格納
//	DbgMsg01( DLv04, ( OutPut, "***** ファイル記述子最大個数:%d\n", lMaxFileNum));

/****************************************/
/*	本処理								*/
/****************************************/

	/*	テーブルサイズの算出	*/
	ptEflcTableAdr->lSize = sizeof(TEflcTable) + sizeof(TEflcTableInd) * lMaxFileNum;
//	ptEflcTableAdr->lSize = sizeof(TEflcTable) + sizeof(TEflcTableInd) * lFlcKbt;
//	 DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->lSize : %d\n", ptEflcTableAdr->lSize) );
	 
	/*	領域の確保			*/
	plRes = calloc(ptEflcTableAdr->lSize, sizeof(char) );
	if( NULL == plRes )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 02:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRCALLOC );					//領域確保失敗
	}
	ptEflcTableAdr->pvAdr = (void *)plRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->pvAdr : %x\n", ptEflcTableAdr->pvAdr) );
	
	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	/*	セマフォkeyの生成	*/
	//富士通殿提供関数(ntok)を発行する
	lRes = BlpMpf_ntok(acSgKeyname, lSgSemKey);
	if ( -1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 03:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRNTOK );					//セマフォKey作成失敗
	}
	
	/*	セマフォIDの取得	*/
	iShmId = semget(lRes, lSemNum, lSemAcc | IPC_CREAT | IPC_EXCL );
	if(D_ERR_SYS == iShmId )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRSEMGET );					//セマフォＩＤ取得失敗
	}
	ptEflcTableAdr->lSemId = iShmId;					// 返却値をセマフォIDに格納する
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->lSemId : %d\n", ptEflcTableAdr->lSemId) );
	
	// セマフォの制御操作
	uSem.val = 1;								// uSemはoscom_insで定義済み
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	//if(NORMAL != lRes)						// 20021225 修正
	if(D_ERR_SYS == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04-1:ErrMess:%s\n", strerror(errno) ) );
		return(OSERRSEMCTL);					// 20021225 追加
	}
	
	#endif

	/****************************************/
	/*	管理情報部の初期化					*/
	/****************************************/

	ptEflc = ptEflcTableAdr->pvAdr;				// 先頭アドレスをファイル管理テーブル管理部に当てる
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEflc : %x\n", ptEflc ) );
	
	strncpy( ptEflc->acTid, D_EFLC_TID, 4);			// EFLC領域識別子を格納
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->acTid : %s\n", ptEflc->acTid ) );
	
	ptEflc->lMaxIndNum = lMaxFileNum;					// 個別部数にファイル記述子最大個数を格納
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->lMaxIndNum : %d\n", ptEflc->lMaxIndNum ) );
	
	ptEflc->lEmpIndNum = lMaxFileNum;					// 空き部数にファイル記述子最大個数を格納
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->lEmpIndNum : %d\n", ptEflc->lEmpIndNum ) );
	
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initEFLC\n") );
	return(NORMAL);	
}
/************************************************************************************************/
/*	END																							*/
/************************************************************************************************/
