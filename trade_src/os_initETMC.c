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
/* ＜モジュールＩＤ＞				 os_initETMC												*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		タイマ管理テーブルの領域確保をローカルメモリ内に確保して初期化を実施する。              */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*		long    os_initETMC( ptEtmcTableAdr )                                                   */
/*																								*/
/* ＜仮引数＞																					*/
/*		TTblInfo	*ptEtmcTableAdr;			タイマ管理情報格納領域のアドレス	            */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			                                        							*/
/*	       NORMAL                                                                               */
/*		異常終了			-1																	*/
/*		        OSERRARG 				タイマ管理情報格納領域のアドレス不正                    */
/*		        OSERRSG 				ＳＧ読込失敗                                            */
/*		       	OSERRCALLOC 			領域の確保失敗                                          */
/*		        OSERRNTOK 				セマフォKey作成失敗                                     */
/*		        OSERRSEMGET 			セマフォＩＤ取得失敗                                    */
/*		        OSERRSEMCTL			                                                            */	
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		プロセス起動時初期化関数（os_prcinit）内でのみ使用可能とする。                          */
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/


/************************************************************************************************/
/*  インクルードファイル                                                                        */
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

/**********************************************/
/*  引数の名称を変更する必要がある            */
/*  ptEtmcTableAdr → ???                     */
/**********************************************/
long os_initETMC(ptEtmcTableAdr)
TTblInfo		*ptEtmcTableAdr;
{
    /********************************************************************************************/
    /*  ＳＧ設定ワーク領域                                                                      */
    /********************************************************************************************/
	char 	acCreatKey[9];							/* Key生成用文字列							*/
	char	acSgKeyTemp[9];
	long 	lSemSets = 0;								/* セマフォ集合数						*/
	long 	lSemAcces = 0;								/* セマフォアクセス初期値				*/
	long 	lEtmcKbs = 0;								/* ETMC 個別部数						*/
	long 	lEtmcSemKey = 0;							/* ETMC 排他用セマフォKey (ntok用)		*/
	long	lKMemKey = 0;								/* 共有メモリKey(ntok用)				*/

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long	lRet = 0;									/* 返却値								*/
	long	lTblSize = 0;								/* テーブルサイズ						*/
	char	*pcWorkp = 0;								/* ワークポインタ						*/
	TEtmcTableInd	*ptEtmcp = NULL;                       /* ETMC個別部ポインタ				*/
	TEtmcTableInd	*ptEtmcTemp = NULL;
	long	lRes = 0;
	long	lCnt = 0;
	int		iShmId = 0;

													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_initETMC" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	/********************************/
	/*  引数チェック                */
	/********************************/
	/*  タイマ管理情報格納領域のアドレスが「０」の場合は処理を終了する	*/
	if (NULL == ptEtmcTableAdr)
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 01:Err Mess:%s\n", "os_initETMC", strerror(errno)) );
		return( OSERRARG );							//タイマ管理情報格納領域のアドレス不正
	}

	/********************************/
	/*  ＳＧ読み込み                */
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み開始\n"));

	lSemAcces = D_SEM_ACCESS;	// アクセス初期値読み込み
	
	lKMemKey = D_NTOK_ID;	// 共有メモリKey読み込み

	
	lRes = os_getSG(D_SG_ETMC_NUM,&lEtmcKbs);	// ETMC個別部読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );						//	ＳＧ読込失敗
	}
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemSets);	// セマフォ集合数読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                      //  ＳＧ読込失敗
	}

	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	lRes = os_getSG(D_SG_ETMC_HAITA_SKEY,acSgKeyTemp);	// ETMCセマフォKey生成文字列読み込み
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                      //  ＳＧ読込失敗
	}
	lRes = os_KeyGen(acSgKeyTemp, acCreatKey);
//	DbgMsg01( DLv04, ( OutPut, "***** acCreatKey : %s\n", acCreatKey));
	#endif
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み終了\n"));
    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/

	/********************************/
	/*  テーブルサイズの算出        */
	/********************************/
	/*  算出：「ETMC 管理部情報」 + 「ETMC 個別部情報」 *  個別部数		*/
	lTblSize = sizeof(TEtmcTable) + sizeof(TEtmcTableInd) * lEtmcKbs;
//	DbgMsg01(DLv04, (OutPut, "***** %s:lTblSize = %08x\n", "os_initETMC", lTblSize));

	/********************************/
	/*  領域の確保                  */
	/********************************/
	pcWorkp = calloc(lTblSize, sizeof(char));
	if (NULL == pcWorkp)
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 02:Err Mess:%s\n", "os_initETMC", strerror(errno)) );
		return(	OSERRCALLOC );							//領域の確保失敗
	} 

//	DbgMsg01(DLv04, (OutPut, "***** %s:pcWorkp  = %08x\n", "os_initETMC", pcWorkp));

	/*  プロセステーブル管理テーブル情報の「先頭アドレス」に取得したアドレスを設定	*/

	ptEtmcTableAdr->pvAdr = pcWorkp;
//	DbgMsg01(DLv04, (OutPut, "***** %s:pvRAdr    = %08x\n", "os_initETMC", ptEtmcTableAdr->pvAdr));

	/*  プロセステーブル管理テーブル情報の「サイズ」に算出した値を設定	*/
	ptEtmcTableAdr->lSize = lTblSize;
//	DbgMsg01(DLv04, (OutPut, "***** %s:lSize    = %08x\n", "os_initETMC", ptEtmcTableAdr->lSize));

	#ifdef USESEM
	// 仕様変更 SSLA0007 により子プロセスでセマフォは使用しない
	/********************************/
	/*  セマフォ Key の生成         */
	/********************************/
	lRet = BlpMpf_ntok(acCreatKey, lKMemKey);

	if (-1 == lRet)
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", "os_initETMC", strerror(errno)) );
		return( OSERRNTOK );							//セマフォKey作成失敗
	} 

	lEtmcSemKey = lRet;										/* セマフォ Key 設定				*/

//	DbgMsg01(DLv04, (OutPut, "***** %s:lEtmcSemKey = %08x\n", "os_initETMC", lEtmcSemKey));


	/********************************/
	/*  セマフォ ID の取得          */
	/********************************/
	iShmId = semget(lEtmcSemKey, lSemSets, lSemAcces | IPC_CREAT | IPC_EXCL);
	if (-1 == iShmId)
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 04:Err Mess:%s\n", "os_initETMC", strerror(errno)) );
		return( OSERRSEMGET );							//セマフォＩＤ取得失敗
	} 
	/*  プロセステーブル管理テーブル情報の「セマフォ」に返却値を設定	*/
	ptEtmcTableAdr->lSemId = iShmId;
//	DbgMsg01(DLv04, (OutPut, "***** %s:lSemId = %ld\n", "os_initETMC", ptEtmcTableAdr->lSemId));
	
		// セマフォの制御操作
	uSem.val = 1;								// uSemはoscom_insで定義済み
	
	lRet = semctl(iShmId, 0, SETVAL, uSem);
	//if(NORMAL != lRet)						// 20021225 修正
	if(-1 == lRet)
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 05:Err Mess:%s\n", "os_initETMC", strerror(errno)) );
		return(OSERRSEMCTL);					// 20021225 追加
	}
	
	#endif

	/********************************/
	/*  管理情報部の初期化          */
	/********************************/
	/*  タイマ管理テーブル管理部情報の先頭アドレス設定		*/
	ptEtmc = (TEtmcTable *)ptEtmcTableAdr->pvAdr;
//	DbgMsg01(DLv04, (OutPut, "***** %s:ptEtmc = %08x\n", "os_initETMC", ptEtmc));

	/*  タイマ管理テーブル管理部情報の「領域識別子」設定	*/
	strncpy( ptEtmc->acTid, D_ETMC_TID,4);						/* ETMC領域識別子を設定             */
//	DbgMsg01(DLv04, (OutPut, "***** ptEtmc->acTid:%s\n", ptEtmc->acTid));
	
	/*  タイマ最大利用数にETMC個別部数格納		*/
	ptEtmc->lTimeMaxCnt = lEtmcKbs;
//	DbgMsg01(DLv04, (OutPut, "***** ptEtmc->lTimeMaxCnt :%d\n", ptEtmc->lTimeMaxCnt));
	
	/********************************/
	/*  個別部情報の初期化          */
	/********************************/
	/*  タイマ管理テーブル個別部情報の先頭アドレス設定			*/
	ptEtmcp = (TEtmcTableInd *)(ptEtmc + 1);
	
	for(lCnt = 0; lCnt < lEtmcKbs; lCnt++)
	{
		ptEtmcTemp = ptEtmcp + lCnt;
//		DbgMsg01(DLv04, (OutPut,"***** ptEtmcTemp[%d] = %08x\n", lCnt, ptEtmcTemp));
		
		/*  タイマ管理テーブル個別部情報の「リクエスト識別子」設定	*/
		ptEtmcTemp->lReqId = D_REQ_ID;
		
		/*  タイマ管理テーブル個別部情報の「リクエスト番号」設定	*/
		ptEtmcTemp->lReqNum = D_REQ_NO;
	}
	
//	DbgMsg01(DLv04,(OutPut,"***** ptEtmcTemp[%d]->lReqId  = %08lx\n", lCnt, ptEtmcTemp->lReqId));
//	DbgMsg01(DLv04,(OutPut,"***** ptEtmcTemp[%d]->lReqNum = %08lx\n", lCnt, ptEtmcTemp->lReqNum));

    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_initETMC" ) );
	return (NORMAL);
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
