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
/* ＜モジュールＩＤ＞				 os_initTrade												*/
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
/*	 TRADEテーブル管理テーブルの各項目の初期化を行う。											*/
/*	 各テーブルの相対アドレスを算出して格納する。また各テーブルへの書き込み処理実装のため		*/
/*   のセマフォの確保を行い、そのセマフォIDを格納する。											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initTrade.h>															*/
/*																								*/
/*      long    os_initTrade(TEtrdTable *ptRtrdTableAdr)                                        */
/*																								*/
/* ＜仮引数＞																					*/
/*      TEtrdTable *ptEtrdTableAdr  TRADEテーブル管理テーブル先頭アドレス                       */
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値	NORMAL																		*/
/*		異常戻り値	未決定																		*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*  os_initSystem関数内でのみ使用する                                                           */
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initTrade(TEtrdTable *ptEtrdTableAdr)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lSemNum = 0;							// セマフォ集合数
	long lSemAcc = 0;							// セマフォアクセス初期値
	long lEPRCKbt = 0;							// EPRC個別部数
	long lEBPCKbt = 0;							// EBPC個別部数
	long lESBPKbt = 0;							// ESBP個別部数
	long lEPBCKbt = 0;							// EPBC個別部数
	long lEMBCKbt = 0;							// EMBC個別部数
	long lEMMCKbt = 0;							// EMMC個別部数
	long lESMCKbt = 0;							// ESMC個別部数
	long lGenKey = 0;							// Key生成用文字列

	char acEPRCSemKey[9];						// EPRCセマフォKey
	char acEBPCSemKey[9];						// EBPCセマフォKey
	char acESBPSemKey[9];						// ESBPセマフォKey
	char acEPBCSemKey[9];						// EPBCセマフォKey
	char acEMBCSemKey[9];						// EMBCセマフォKey
	char acEMMCSemKey[9];						// EMMCセマフォKey
	char acESMCSemKey[9];						// ESMCセマフォKey
	
	long lCnt = 0;								// カウンタ変数
	long lSemId = 0;							// セマフォID用
	long lSemKey = 0;							// セマフォKey用
	long lEtrdSize = 0;							// TRADEテーブルサイズ用
	long lTblNum = 0;							// patTableサイズ格納用
	long lRes = 0;								// 返却値格納用
	long lTemp = 0;
	
	long *patTable[] = {						// 管理部情報格納用配列
		&(ptEtrdTableAdr->tTrdEPRC.lSemId),
		&(ptEtrdTableAdr->tTrdEBPC.lSemId),
		&(ptEtrdTableAdr->tTrdESBP.lSemId),
		&(ptEtrdTableAdr->tTrdEPBC.lSemId),
		&(ptEtrdTableAdr->tTrdEMMC.lSemId),
		&(ptEtrdTableAdr->tTrdEMBC.lSemId),
		&(ptEtrdTableAdr->tTrdESMC.lSemId)
	};

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initTrade\n" ) );
/************************************/
/*	初期処理						*/
/************************************/
	/*引数のチェック*/
	if( 0 == ptEtrdTableAdr)				//ＴＲＡＤＥテーブル管理テーブルアドレス異常			
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 01:Err Mess:%s\n", "initTrade", strerror(errno) ) );
		return( OSERRARG );					//引数異常を返却
	}

	/************************************/
	/*	SG値の読み込み					*/
	/************************************/
	
	lSemAcc = D_SEM_ACCESS;		// セマフォアクセス初期値読み込み

	lGenKey = D_NTOK_ID;		// 共有Key読み込み
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);		// セマフォ集合数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}

	lRes = os_getSG(D_SG_EPRC_NUM,&lEPRCKbt);	// EPRC個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEBPCKbt);	// EBPC個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lESBPKbt);	// ESBP個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EPBC_NUM,&lEPBCKbt);	// EPBC個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EMBC_NUM,&lEMBCKbt);	// EMBC個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
												// 20030307 修正 KL0027
//	lRes = os_getSG(D_SG_EMMC_NUM,&lEMMCKbt);	// EMMC個別部数読み込み
//	if(NORMAL != lRes)							//ＳＧ読込異常
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
//		return( OSERRSG );						//ＳＧ読込異常を返却
//	}
	
	lRes = os_getSG(D_SG_ESMC_NUM,&lESMCKbt);	// ESMC個別部数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EPRC_SKEY,acEPRCSemKey);		// EPRC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EPRC_SKEY:%s\n",acEPRCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EBPC_SKEY,acEBPCSemKey);		// EBPC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EBPC_SKEY:%s\n",acEBPCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_ESBP_SKEY,acESBPSemKey);		// ESBP生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_ESBP_SKEY:%s\n",acESBPSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EPBC_SKEY,acEPBCSemKey);		// EPBC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EPBC_SKEY:%s\n",acEPBCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EMBC_SKEY,acEMBCSemKey);		// EMBC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EMBC_SKEY:%s\n",acEMBCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EMMC_SKEY,acEMMCSemKey);		// EMMC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EMMC_SKEY:%s\n",acEMMCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_ESMC_SKEY,acESMCSemKey);		// ESMC生成文字列読み込み
//	DbgMsg01( DLv04, ( OutPut, "***** SG_ESMC_SKEY:%s\n",acESMCSemKey) );
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}

	ptEtrd = ptEtrdTableAdr;					/*	引数ptEtrdTableAdrに構造体を割り当てる	*/
//	DbgMsg01( DLv02, ( OutPut, "***** Addr ptEtrd : %x\n", ptEtrd ) );
	lTblNum = 0;
	lTblNum = sizeof(patTable) / sizeof(patTable[0]);	/*	patTableのサイズを求める	*/

/************************************/
/*	本処理							*/
/************************************/
	strncpy(ptEtrd->acTid,D_ETRD_TID, 4 );		/*	ETRD識別子を格納					*/
//	DbgMsg01( DLv02, ( OutPut, "***** ETRD領域識別子 : %4c\n", ptEtrd->acTid ) );

	/************************************************/
	/*	テーブルのサイズを求め各項目に格納する		*/
	/************************************************/
	
	/*	TRADEテーブル管理テーブルサイズ算出		*/
//	DbgMsg01( DLv04, ( OutPut, "***** TRADEテーブル管理テーブルサイズ算出\n") );
	
	lEtrdSize = sizeof(TEtrdTable);
//	DbgMsg01( DLv04, ( OutPut, "***** lEtrdSize:%ld\n", lEtrdSize ) );
		
	/*	プロセス管理テーブルサイズ				*/
	ptEtrd->tTrdEPRC.lSize = sizeof(TEprcTable) + sizeof(TEprcTableInd) * lEPRCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPRC.lSize:%ld\n", ptEtrd->tTrdEPRC.lSize) );
	
	/*	バッファプール管理テーブルサイズ		*/
	ptEtrd->tTrdEBPC.lSize = sizeof(TEbpcTable) + sizeof(TEbpcTableInd) * lEBPCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEBPC.lSize:%ld\n", ptEtrd->tTrdEBPC.lSize) );
	
	/*	空バッファプール管理テーブルサイズ		*/
	ptEtrd->tTrdESBP.lSize = sizeof(TEsbpTable) + sizeof(TEsbpTableInd) * lESBPKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdESBP.lSize:%ld\n", ptEtrd->tTrdESBP.lSize) );
	
	/*	プールバッファ管理テーブルサイズ		*/
	ptEtrd->tTrdEPBC.lSize = sizeof(TEpbcTable) + sizeof(TEpbcTableInd) * lEPBCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPBC.lSize:%ld\n", ptEtrd->tTrdEPBC.lSize) );
	
	/*	メールボックス管理テーブルサイズ		*/
	ptEtrd->tTrdEMBC.lSize = sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * lEMBCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMBC.lSize:%ld\n", ptEtrd->tTrdEMBC.lSize) );
	
	/*	メッセージ管理テーブルサイズ	20021226 追加修正	*/
//	ptEtrd->tTrdEMMC.lSize = sizeof(TEmmcTable) + sizeof(TEmmcTableInd) * lEMMCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMMC.lSize:%ld\n", ptEtrd->tTrdEMMC.lSize) );

	lTemp = 0;
	lRes = os_getEmmcSize(&lTemp);
	if(NORMAL != lRes)
	{
		return( OSERREMMC );
	}
	ptEtrd->tTrdEMMC.lSize = lTemp;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMMC.lSize:%ld\n", ptEtrd->tTrdEMMC.lSize) );

	/*	共有メモリ管理テーブルサイズ			*/
	ptEtrd->tTrdESMC.lSize = sizeof(TEsmcTable) + sizeof(TEsmcTableInd) * lESMCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdESMC.lSize:%ld\n", ptEtrd->tTrdESMC.lSize) );


	/************************************************/
	/*	各テーブルの相対アドレスを求めて格納する	*/
	/************************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** 各テーブルの相対アドレス格納\n") );
	/*	プロセス管理テーブル					*/
	ptEtrd->tTrdEPRC.lRAdr = lEtrdSize;
//	DbgMsg01( DLv04, ( OutPut, "***** EPRC相対アドレス:%lx\n", ptEtrd->tTrdEPRC.lRAdr) );
	
	/*	バッファプール管理テーブル				*/
	ptEtrd->tTrdEBPC.lRAdr = (ptEtrd->tTrdEPRC.lRAdr) + (ptEtrd->tTrdEPRC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EBPC相対アドレス:%lx\n", ptEtrd->tTrdEBPC.lRAdr) );
	
	/*	空バッファプール管理テーブル			*/
	ptEtrd->tTrdESBP.lRAdr = (ptEtrd->tTrdEBPC.lRAdr) + (ptEtrd->tTrdEBPC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESBO相対アドレス:%lx\n", ptEtrd->tTrdESBP.lRAdr) );
	
	/*	プールバッファ管理テーブル				*/
	ptEtrd->tTrdEPBC.lRAdr = (ptEtrd->tTrdESBP.lRAdr) + (ptEtrd->tTrdESBP.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EPBC相対アドレス:%lx\n", ptEtrd->tTrdEPBC.lRAdr) );
	
	/*	メッセージ管理テーブル					*/
	ptEtrd->tTrdEMMC.lRAdr = (ptEtrd->tTrdEPBC.lRAdr) + (ptEtrd->tTrdEPBC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EMMC相対アドレス:%lx\n", ptEtrd->tTrdEMMC.lRAdr) );

	/*	メイルボックス管理テーブル				*/
	ptEtrd->tTrdEMBC.lRAdr = (ptEtrd->tTrdEMMC.lRAdr) + (ptEtrd->tTrdEMMC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EMBC相対アドレス:%lx\n", ptEtrd->tTrdEMBC.lRAdr) );
	
	/*	共有メモリ管理テーブル					*/
	ptEtrd->tTrdESMC.lRAdr = (ptEtrd->tTrdEMBC.lRAdr) + (ptEtrd->tTrdEMBC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESMC相対アドレス:%lx\n", ptEtrd->tTrdESMC.lRAdr) );
	
	/*	SG設定管理テーブル						*/
	ptEtrd->tTrdESGC.lRAdr = (ptEtrd->tTrdESMC.lRAdr) + (ptEtrd->tTrdESMC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESMC相対アドレス:%lx\n", ptEtrd->tTrdESGC.lRAdr) );
	/************************************************/
	/*	セマフォKeyの生成とセマフォIDの取得			*/
	/************************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** セマフォKey取得\n" ) );
	
	for(lCnt = 0; lCnt < lTblNum;lCnt++){
		switch(lCnt)
		{
			case 0:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEPRCSemKey:%s\n",lCnt,acEPRCSemKey) );
				lSemKey = BlpMpf_ntok( acEPRCSemKey, lGenKey );		break;
				
			case 1:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEBPCSemKey:%s\n",lCnt,acEBPCSemKey) );
				lSemKey = BlpMpf_ntok( acEBPCSemKey, lGenKey );		break;
				
			case 2:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acESBPSemKey:%s\n",lCnt,acESBPSemKey) );
				lSemKey = BlpMpf_ntok( acESBPSemKey, lGenKey );		break;
				
			case 3:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEPBCSemKey:%s\n",lCnt,acEPBCSemKey) );
				lSemKey = BlpMpf_ntok( acEPBCSemKey, lGenKey );		break;

			case 4:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEMMCSemKey:%s\n",lCnt,acEMMCSemKey) );
				lSemKey = BlpMpf_ntok( acEMMCSemKey, lGenKey );		break;
			
			case 5:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEMBCSemKey:%s\n",lCnt,acEMBCSemKey) );
				lSemKey = BlpMpf_ntok( acEMBCSemKey, lGenKey );		break;
				
			case 6:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acESMCSemKey:%s\n",lCnt,acESMCSemKey) );
				lSemKey = BlpMpf_ntok( acESMCSemKey, lGenKey );		break;
				
			default:
				lSemKey = 0;	break;
		}
		
		if( -1 == lSemKey )							//セマフォKey生成異常
		{
			DbgMsg01( DLv05, ( OutPut, "***** 02:Err Mess:%s\n", strerror(errno) ) );
			return( OSERRNTOK );					//key生成異常を返却
		}
//		DbgMsg01( DLv04, ( OutPut, "***** lSemKey : %lx\n", lSemKey ) );
		
		/*	セマフォIDの取得	*/
//		DbgMsg01( DLv04, ( OutPut, "***** lSemKey:%lx lSemNum:%ld lSemAcc:%lo\n",lSemKey,lSemNum,lSemAcc) );
		if(0 != lSemKey)
		{
			lSemId = semget( lSemKey, lSemNum, lSemAcc | IPC_CREAT | IPC_EXCL);
			if( -1 == lSemId )							//セマフォＩＤ取得異常
			{
				DbgMsg01( DLv05, ( OutPut, "***** 03 lCnt:%d :Err Mess:%s\n",
								 lCnt, strerror(errno) ) );
				return( OSERRSEMGET );					//セマフォ取得異常を返却
			}
		}
		
//		DbgMsg01( DLv04, ( OutPut, "***** lSemId : %ld\n", lSemId ) );
		/*	返却地を各ファイル管理テーブルセマフォID(iTblSemId)に入れる	*/
		*patTable[lCnt] = lSemId;
		
			// セマフォの制御操作
		uSem.val = 1;								// uSemはoscom_insで定義済み
	
		lRes = semctl((int)lSemId, 0, SETVAL, uSem);
		//if(NORMAL != lRes)						// 20021225 修正
		if(-1 == lRes)
		{
			DbgMsg01( DLv05, ( OutPut, "*****  04-1:Err Mess:%s\n", strerror(errno)) );
			return(OSERRSEMCTL);					// 20021225 追加
		}
	}
	
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initTrade\n" ) );
	return (NORMAL);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
