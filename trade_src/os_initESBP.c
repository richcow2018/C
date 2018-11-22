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
/* ＜モジュールＩＤ＞				 os_initESBP												*/
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
/*	 空バッファプール管理テーブルの領域確保を共有メモリ内に確保して初期化を実施する				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initESBP.h>																*/
/*																								*/
/*	   	long os_initESBP(char *pcEsbpTableAdr,TEbpcTable *ptEbpcTableAdr,						*/
/*						 TEpbcTable *ptEpbcTableAdr)											*/
/*																								*/
/* ＜仮引数＞																					*/
/*		char		*pcEsbpTableAdr;			空バッファ管理テーブル先頭アドレス				*/
/*		TEbpcTable	*ptEbpcTableAdr;			バッファプール管理テーブル先頭アドレス			*/
/*		TEpbcTable	*ptEpbcTableAdr;			プールバッファ管理テーブル先頭アドレス			*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値	NORMAL																		*/
/*		異常戻り値	未決定																		*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	os_initSystem関数内でのみ使用可能とする														*/
/*	当該関数呼出前にバッファプール管理テーブルの初期化が完了している							*/
/*	当該関数呼出前にプールバッファ管理テーブルの初期化が完了している							*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initESBP(char *pcEsbpTableAdr, TEbpcTable *ptEbpcTableAdr, TEpbcTable *ptEpbcTableAdr)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TEsbpTableInd *ptEsbpInd;					// ESBP個別部
	TEsbpTableInd *ptEsbpIndTemp;				// ESBP個別部作業用
	TEbpcTableInd *ptEbpcInd;					// EBPC個別部
	
	long lEsbpKbt;								// ESBP個別部数
	long lEbpcKbt;								// EBPC個別部数
	long lEpbcKbt;								// EPBC個別部数
	
	long lCnt;
	long lRes;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initESBP\n") );
/****************************************/
/*	初期処理							*/
/****************************************/
	ptEsbpInd = NULL;
	ptEsbpIndTemp = NULL;
	ptEbpcInd = NULL;
	lEsbpKbt = 0;
	lCnt = 0;
	lRes = 0;
	
	/*	引数チェック	*/
	if( 0 == pcEsbpTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 01:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					//空きプールバッファ管理テーブル先頭アドレス不正
	}
//	DbgMsg01( DLv04, ( OutPut, "***** pcEsbpTableAdr :%x\n", pcEsbpTableAdr));
	
	if( 0 == ptEbpcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 02:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					// バッファプール管理テーブル先頭アドレス不正
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpcTableAdr :%x\n", ptEbpcTableAdr));
	
	if( 0 == ptEpbcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					//プールバッファ管理テーブル先頭アドレス不正 
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEpbcTableAdr :%x\n", ptEpbcTableAdr));

	//***** SG読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み開始\n"));
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lEsbpKbt);
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );					//ＳＧ読込異常
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ESBP個別部数:%ld\n", lEsbpKbt));
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                  //ＳＧ読込異常
	}
//	DbgMsg01( DLv04, ( OutPut, "***** EBPC個別部数:%ld\n", lEbpcKbt));

	lEpbcKbt = lEbpcKbt * 0x7ffff;
//	DbgMsg01( DLv04, ( OutPut, "***** EPBC個別部数:%ld\n", lEpbcKbt));
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG読み込み終了\n"));
	
	/*	設定領域の構造化					*/
	ptEsbp = (TEsbpTable *)pcEsbpTableAdr;	// 管理部を割り当て
	/*	個別部情報の定義					*/
	ptEsbpInd = (TEsbpTableInd *) ( (long)ptEsbp + sizeof(TEsbpTable) );
	ptEbpcInd = (TEbpcTableInd *) ( (long)ptEbpc + sizeof(TEbpcTable) );
	
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEsbp : %x\n", ptEsbp) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEsbpInd : %x\n", ptEsbpInd) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEbpcInd : %x\n", ptEbpcInd ) );
	
	/*	バッファプール管理部情報の定義		*/
	ptEbpc = ptEbpcTableAdr;
	/*	プールバッファ管理部情報の定義		*/
	ptEpbc = ptEpbcTableAdr;

//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEbpc : %x\n", ptEbpc ) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEpbc : %x\n", ptEpbc ) );
	
/****************************************/
/*	本処理								*/
/****************************************/
	/*	管理部情報の初期化					*/
	strncpy( ptEsbp->acTid, D_ESBP_TID, 4 );			// 領域識別子にESBPのを指定
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbp->acTid:%s\n", ptEsbp->acTid) );
	/*	個別部情報の初期化					*/
												/*	個別部[0]の初期化					*/
//	DbgMsg01( DLv04, ( OutPut, "***** 個別部初期化\n" ) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr ) );
	
												/*	バッファプール先頭アドレスをバッファプール空き領域開始アドレスに代入	*/
	ptEsbpInd->pvEmpBpAdr = (void *)(ptEbpc->pvAdr);
													/*	バッファプールサイズをバッファプール空き領域サイズに代入			*/
	ptEsbpInd->lEmpBpSize = ptEbpc->lSize;
													/*	EPBC先頭アドレス+EPBC管理部サイズをプールバッファ管理空き領域開始アドレスに代入	*/
	ptEsbpInd->pvEmpEpbcAdr = (void *) ( (long)ptEpbc + sizeof(TEpbcTable) );
													/*	プールバッファサイズをプールバッファ管理空き領域サイズに代入			*/
	ptEsbpInd->lEmpEpbcSize = lEpbcKbt * sizeof(TEpbcTableInd);
	
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->pvEmpBpAdr   : %x\n", ptEsbpInd->pvEmpBpAdr) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->lEmpBpSize   : %d\n", ptEsbpInd->lEmpBpSize) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->pvEmpEpbcAdr : %x\n", ptEsbpInd->pvEmpEpbcAdr) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->lEmpEpbcSize : %d\n", ptEsbpInd->lEmpEpbcSize) );
	
	/*	個別部[1]〜[ESBP個別部数 -1 ]の初期化		*/
	for(lCnt = 1; lCnt < lEsbpKbt ; lCnt++){
		ptEsbpIndTemp = (ptEsbpInd + lCnt);
												/*	バッファプール空き領域開始アドレスに格納*/
		ptEsbpIndTemp->pvEmpBpAdr = (void *)D_ESBP_ALL_F;
												/*	バッファプール空き領域サイズに格納		*/
		ptEsbpIndTemp->lEmpBpSize = D_ESBP_ALL_Z;
												/*	プールバッファ管理空き領域開始アドレスに格納*/
		ptEsbpIndTemp->pvEmpEpbcAdr = (void *)D_ESBP_ALL_F;
												/*	プールバッファ管理空き領域サイズに格納	*/
		ptEsbpIndTemp->lEmpEpbcSize = D_ESBP_ALL_Z;
		
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->pvEmpBpAdr:%8x\n",lCnt, ptEsbpIndTemp->pvEmpBpAdr));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->lEmpBpSize:%8x\n",lCnt, ptEsbpIndTemp->lEmpBpSize));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->pvEmpEpbcAdr:%8x\n",lCnt, ptEsbpIndTemp->pvEmpEpbcAdr));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->lEmpEpbcSize:%8x\n\n",lCnt, ptEsbpIndTemp->lEmpEpbcSize));
	}

/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initESBP\n") );
	return (NORMAL);
	
}
