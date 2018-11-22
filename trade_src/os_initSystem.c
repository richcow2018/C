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
/* ＜サービス項目名＞				 開始処理１													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 初期設定（システム起動時）									*/
/* ＜モジュールＩＤ＞				 os_initSystem												*/
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
/*	 共用メモリ上にシステム全体で使用するテーブル(TRADEテーブル)の領域を確保する。				*/
/*   テーブルの領域を確保した後に各テーブルに対応する関数の呼び出しを行う。						*/
/*	 各テーブルに対応する関数で必要な資源(ファイルなど)の初期化と初期値の設定を確保する。		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initSystem.h>															*/
/*																								*/
/*      long    os_initSystem(long lPCode)                                                      */
/*																								*/
/* ＜仮引数＞																					*/
/*      lPCode  プロセス識別子(moa)                                                             */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了	共有メモリID																*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*  moaのmain関数内でのみ使用可能とする。                                                       */
/*  当該関数では共有メモリ内にテーブルを展開するのみである。従って実際にTRADEテーブルを利用する */
/*  場合、利用する前にos_initTrade関数の呼出を行う必要がある。                                  */
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
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
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initSystem.h"
#include "os_initSystem_ins.h"
#include "os_initEXXX_ins.h"

long os_initSystem(long lPCode)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lKMemKey = 0;								/* 共有メモリKey(ntok用)	*/
	long lEprcKbt = 0;								/* EPRC個別部数				*/
	long lEbpcKbt = 0;								/* EBPC個別部数				*/
	long lEsbpKbt = 0;								/* ESBP個別部数				*/
	long lEpbcKbt = 0;								/* EPBC個別部数				*/
	long lEmbcKbt = 0;								/* EMBC個別部数				*/
	long lEmmcKbt = 0;								/* EMMC個別部数				*/
	long lEsmcKbt = 0;								/* ESMC個別部数				*/
	long lTblAdr = 0;								/* テーブル格納用共有メモリ先頭アドレス*/
	char acGenKey[9];							/* Key生成用文字列			*/

	long lAllTableSize = 0;							/* テーブルサイズ合計格納	*/
	long lRes = 0;									/* 返却地用					*/
	long lShmKey = 0;								/* 共有メモリKey格納用		*/
	long *plMemAdr = NULL;								/* 共有メモリアドレス格納用	*/
	long *plTempAdr = NULL;							/* 共有メモリアドレス格納用	*/
	int iMemId = 0;									/* 共有メモリID格納用		*/
	long lSgAdr = 0;								/* SG格納領域先頭アドレス用	*/
	long lSgSize = 0;							/* SG格納領域サイズ用		*/
	long lTemp = 0;
	/******************************************/
	struct sigaction new[D_MAX_SIG_NUM];	// D_MAX_SIG_NUMは設定シグナル数:31
	int iSigCnt = 0;
	/******************************************/
	
	/******************************************/
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		switch(iSigCnt+1)
		{
			case SIGILL:                        // 不正な命令
			case SIGBUS:                        // バスエラー
			case SIGFPE:                        // 浮動小数点例外
			case SIGSEGV:                       // 不正なメモリ参照
//			case SIGPIPE:                       // パイプ破壊
			case SIGTERM:                       // 終了シグナル
			case 16:                            // 空き
				new[iSigCnt].sa_handler = os_dflact;
				break;
			default:                            // 上記以外は無視
				new[iSigCnt].sa_handler = SIG_IGN;
				break;
		}
		new[iSigCnt].sa_flags = 0;
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}
	/******************************************/

/****************************************/
/*	初期処理							*/
/****************************************/
//	DbgInit( D_DEF, D_DEF, D_DEF );
	DbgMsg01( DLv01, ( OutPut, "***** Start initSystem\n" ) );
	
	
	/****************************************/
	/*	引数チェック						*/
	/****************************************/
	if(0 > lPCode)								//プロセス識別子異常
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_PRA, 1, OSERRARG );
		
		DbgMsg01( DLv05, ( OutPut, "***** lPCode is NULL\n") );
		return( OSERRARG );						//引数異常を返却
	}
	/****************************************/
	/*	SG設定値の読み込み					*/
	/****************************************/
	/***********************************************************/
	/*  os_initSG実装後要修正                                  */
	lRes = os_initSG();									/*	SG設定関数ここのみ使用	*/
	
//	lRes = os_initSG(D_SG_SYSTEM, (void *)&lSgAdr, &lSgSize);
	
	if(-1 == lRes)								//ＳＧ初期化異常				
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_PRA, 1, OSERRSG );
		
		DbgMsg01( DLv05, ( OutPut, "***** Err initSG\n") );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
//	DbgMsg01( DLv04, ( OutPut, "***** lSgAdr :%08x\n", lSgAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** lSgSize :%d\n", lSgSize));
	
	os_startSG();
	os_startTrace();                            // 20030123
	
	os_trcget2( D_MD_OS_INITSYSTEM, D_T_TRA_IN, 1, lPCode );
	/***********************************************************/

	lKMemKey = D_NTOK_ID;		// 共有メモリKey読み込み

	lRes = os_getSG(D_SG_EPRC_NUM,&lEprcKbt);	// EPRC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err02:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);	// EBPC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lEsbpKbt);	// ESBP個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err04:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	//lEpbcKbt = lEbpcKbt * 0x7ffff;				// EPBC個別部数設定
	lRes = os_getSG(D_SG_EPBC_NUM,&lEpbcKbt);	// EMBC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err05:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}


	lRes = os_getSG(D_SG_EMBC_NUM,&lEmbcKbt);	// EMBC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err06:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
												// 20030307 KL0027 削除
//	lRes = os_getSG(D_SG_EMMC_NUM,&lEmmcKbt);	// EMMC個別部読み込み
//	if(NORMAL != lRes)							//ＳＧ読込異常
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err07:%s\n", strerror(errno) ) );
//		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
//		return( OSERRSG );						//ＳＧ読込異常を返却
//	}
	
	lRes = os_getSG(D_SG_ESMC_NUM,&lEsmcKbt);	// ESMC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err08:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_TABLE_ADR,&lTblAdr);	// テーブル格納用共有メモリ先頭アドレス読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err09:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_ISYS_SKEY,acGenKey);	// ESYS生成文字列読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err10:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//ＳＧ読込異常を返却
	}

/****************************************/
/*	本処理								*/
/****************************************/
	/****************************************/
	/*	 テーブルサイズの算出				*/
	/****************************************/
	/*	TRADEテーブル管理テーブルサイズを測る									*/
	/*  20021226 追加  */
	lTemp = sizeof(TEtrdTable);
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEtrdTable:%ld\n", lTemp) );

	/*	プロセス管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る			*/
	lTemp = sizeof(TEprcTable) + sizeof(TEprcTableInd) * lEprcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEprcTable:%ld\n", lTemp) );

	/*	バッファプール管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る	*/
	lTemp = sizeof(TEbpcTable) + sizeof(TEbpcTableInd) * lEbpcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEbpcTable:%ld\n", lTemp) );

	/*	空バッファプール管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る	*/
	lTemp = sizeof(TEsbpTable) + sizeof(TEsbpTableInd) * lEsbpKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsbpTable:%ld\n", lTemp) );

	/*	プールバッファ管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る	*/
	lTemp = sizeof(TEpbcTable) + sizeof(TEpbcTableInd) * lEpbcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEpbcTable:%ld\n", lTemp) );

	/*	メールボックス管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る	*/
	lTemp = sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * lEmbcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEmbcTable:%ld\n", lTemp) );

	/*	メッセージ管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る		*/
	lTemp = 0;
	lRes = os_getEmmcSize(&lTemp);
	if(NORMAL != lRes)
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMMC );
		
		return( OSERREMMC );
	}

	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEmmcTable:%ld\n", lTemp) );

	/*	共有メモリ管理テーブルの管理部サイズ+個別情報部サイズ*個数を測る			*/
	lTemp = sizeof(TEsmcTable) + sizeof(TEsmcTableInd) * lEsmcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsmcTable:%ld\n", lTemp) );

	/*	SG格納領域サイズを加算する			*/
	lTemp = lSgSize;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsgcTable:%ld\n", lSgSize) );
	
	DbgMsg01( DLv04, ( OutPut,"***** lAllTableSize:%ld\n", lAllTableSize) );

	/****************************************/
	/*	共有メモリの処理					*/
	/****************************************/
	
	/*----------------------*/
	/*	共有メモリKeyの生成	*/
	/*----------------------*/
	lShmKey = BlpMpf_ntok(acGenKey, lKMemKey);
	if(-1 == lShmKey)								//共有メモリKey生成異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRNTOK );
		
		return( OSERRNTOK );						//Key生成異常を返却
	}
//	DbgMsg01(DLv04, (OutPut, "***** 共有メモリKey : %x\n", lShmKey ) );
	
	/*--------------------------------------*/
	/*	共有メモリの確保 共有メモリIDの取得	*/
	/*--------------------------------------*/
	iMemId = shmget(lShmKey, lAllTableSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iMemId)								//共有メモリ確保異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** 02:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 2, OSERRSHMGET, errno );
		
		return( OSERRSHMGET );						//共有メモリ確保異常を返却
	}
//	DbgMsg01( DLv04, ( OutPut, "***** 共有メモリID : %d\n", iMemId ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s:lTblAdr=%08x \n", "os_initSystem", lTblAdr));

	/*--------------------------------------*/
	/*	共有メモリの操作(付加)				*/
	/*--------------------------------------*/
	if(0 == lTblAdr)
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 3, iMemId, NULL, 0 );
		
		plMemAdr = shmat(iMemId, NULL, 0);
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 1, plMemAdr );
		
//		DbgMsg01( DLv04, ( OutPut, "***** shmat true\n") );
	}
	else
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 3, iMemId, (void *)lTblAdr, SHM_RND );
		
		plMemAdr = shmat(iMemId, (void *)lTblAdr, SHM_RND);
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 1, plMemAdr );
		
//		DbgMsg01( DLv04, ( OutPut, "***** shmat false\n") );
	}
	
	if(D_ERR_SYS == (long)plMemAdr)					//共有メモリ付加異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 2, OSERRSHMAT, errno );
		
		return( OSERRSHMAT );					//共有メモリ付加異常を返却
	}
//	DbgMsg01( DLv04, ( OutPut, "***** 共有メモリ先頭アドレス : %x\n", plMemAdr ) );

	/*--------------------------------------*/
	/*	共有メモリの初期化					*/
	/*--------------------------------------*/
	plTempAdr = plMemAdr;
	
	plMemAdr = memset(plTempAdr, 0, lAllTableSize);
	if(-1 == (long)plMemAdr)						//共有メモリ初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRMEMSET );
		
		return( OSERRMEMSET );						//共有メモリ初期化異常を返却
	}
//	DbgMsg01( DLv04, ( OutPut, "***** plMemAdr : %d\n", plMemAdr) );
	/****************************************/
	lTblAdr = (long)plMemAdr;
	/****************************************/
	/*	TRADEテーブル管理テーブルの初期化	*/
	/****************************************/
	lRes = os_initTrade((TEtrdTable *)plMemAdr);
	if(NORMAL != lRes)								//ＴＲＡＤＥ管理テーブル初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 04:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRETRD );
		
		return( OSERRETRD );						//ＴＲＡＤＥ管理テーブル初期化異常を返却
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd : %x\n", ptEtrd ) );	/*	以後ptEtrdが使用可能	*/

	/****************************************/
	/*	各テーブルの初期化					*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** テーブル初期化\n" ) );
	
	/*	プロセス管理テーブルの初期化		*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPRC.lRAdr : %x\n", ptEtrd->tTrdEPRC.lRAdr ) );
	lRes = os_initEPRC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEPRC.lRAdr) ),  lPCode);
	if(NORMAL != lRes)								//プロセス管理テーブル初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 05:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREPRC );
		
		return( OSERREPRC );						//プロセス管理テーブル初期化異常
	}

	/*	バッファプール管理テーブルの初期化	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEBPC.lRAdr : %x\n", ptEtrd->tTrdEBPC.lRAdr ) );
	lRes = os_initEBPC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEBPC.lRAdr) ) );
	if(NORMAL != lRes)								//バッファ管理テーブル初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 06:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREBPC );
		
		return( OSERREBPC );						//バッファ管理テーブル初期化異常を返却
	}

	/*	プールバッファ管理テーブルの初期化	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPBC.lRAdr : %x\n", ptEtrd->tTrdEPBC.lRAdr ) );

	lRes = os_initEPBC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEPBC.lRAdr) ) );
	if(NORMAL != lRes)								//バッファ管理テーブル初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 07:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREPBC );
		
		return( OSERREPBC );						//バッファ管理テーブル初期化異常を返却
	}

	/*	メイルボックス管理テーブルの初期化	*/
	lRes = os_initEMBC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEMBC.lRAdr) ) );
	if(NORMAL != lRes)								//メイルボックス管理テーブル初期化異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 08:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMBC );
		
		return( OSERREMBC );						//メイルボックス管理テーブル初期化異常を返却
	}

	//	メッセージ管理テーブルの初期化
	lRes = os_initEMMC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEMMC.lRAdr) ) );
	if(NORMAL != lRes)								//メッセージ管理テーブル初期化異常
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMMC );
		
		return( OSERREMMC );						//メッセージ管理テーブル初期化異常を返却
	}

	/*	共有メモリ管理テーブルの初期化		*/
	lRes = os_initESMC((char *) ( (long)ptEtrd + (ptEtrd->tTrdESMC.lRAdr) ) );
	if(NORMAL != lRes)								//共有メモリ管理テーブル初期化異常
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 11:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRESMC );
		
		return( OSERRESMC );						//共有メモリ管理テーブル初期化異常を返却
	}

	/*	空バッファプール管理テーブルの初期化*/
	lRes = os_initESBP( (char *) ( (long)ptEtrd + (ptEtrd->tTrdESBP.lRAdr) ),
						(TEbpcTable *) ( (long)ptEtrd + (ptEtrd->tTrdEBPC.lRAdr) ),
						(TEpbcTable *) ( (long)ptEtrd + (ptEtrd->tTrdEPBC.lRAdr) ) );
						
	if( NORMAL != lRes)								//空きバッファプール管理テーブル初期化異常
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 12:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRESBP );
		
		return( OSERRESBP );				//空きバッファプール管理テーブル初期化異常を返却
	}
	
	/*	SG管理テーブルの展開				*/
	ptEtrd->tTrdESGC.lSize = lSgSize;			/* SG格納領域サイズを格納 */
//	DbgMsg01(DLv04, (OutPut, "***** ptEtrd->tTrdESGC.lSize :%d\n", ptEtrd->tTrdESGC.lSize));
	
	/*--------------------------------------*/
	/*  moa用のプロセス初期化               */
	/*--------------------------------------*/
	lRes = ((lPCode & 0x0000ffff) | 0x00020000);
//	DbgMsg01(DLv04, (OutPut, "***** moa用プロセス初期化\n"));
	os_initProcess(iMemId, (void *)lTblAdr, lRes);


/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01(DLv01, (OutPut, "***** End initSystem\n" ) );
//	DbgDmp02( DLv04, ("ptEPRC 個別部", (TEprcTableInd *)(ptEprc+1),
//	                                   (sizeof(TEprcTableInd))*3, 1, 0));
	
	os_trcget2( D_MD_OS_INITSYSTEM, D_T_TRA_OUT, 1, iMemId );

	return(iMemId);								/*	shmgetで得たIDを返す	*/
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
