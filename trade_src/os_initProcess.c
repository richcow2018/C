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
/* ＜サービス項目名＞				 開始処理２													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 初期設定（プロセス起動時）									*/
/* ＜モジュールＩＤ＞				 os_initProcess												*/
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
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　５月１３日		故障管理番号（Ｓ０００８０）	*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		プロセス内部で閉じた利用をするテーブルの領域確保および初期化を行う。					*/
/*		領域確保および初期化には各テーブルに対応した関数を呼出すことで実施する。				*/
/*		各テーブルに対応する関数では必要な資源(ファイルなど)の初期化と初期値の設定を実施する。	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	"os_initProcess.h"															*/
/*																								*/
/*		long os_initProcess(long lShmId, void *pvShmAdr, long lMBoxId )							*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	lShmId		テーブル格納共有メモリID											*/
/*							(システム起動時初期化処理で取得した共有メモリID)					*/
/*		void	*pvShmAdr	テーブル格納用共有メモリ先頭アドレス								*/
/*		long	lMBoxId		メイルボックス識別子												*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値	NORMAL																		*/
/*		異常戻り値	なし（アボート）															*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   os_initSystemとASイニシエータでのみ使用可能とする。										*/
/*	   コネクション管理テーブルについては当該関数での初期化は実施しない。osconn2 内で実施される	*/
/*     ものとする。但し、管理用の領域についてはシステムテーブル管理テーブル内に確保するものとす	*/
/*	   る。																						*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/

/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initProcess.h"
#include "os_initProcess_ins.h"
#include "os_initEXXX_ins.h"
#include "osanyrl.h"

TEsysTable tEsys;									/* システム管理テーブル領域					*/


long os_initProcess(long lShmId, void *pvShmAdr, long lMBoxId  )
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lRes = 0;									/* 返却値格納用								*/
	long lRda = 0;									/* リクエスト識別子格納用					*/
	long lTblMemAdr = 0;							/* 共有メモリ先頭アドレス格納用(SG)			*/
	long lBpAdr = 0;								/* バッファプール領域先頭アドレス格納用(SG)	*/
	long *plShmAdr = NULL;							/* 共有メモリ先頭アドレス					*/
	long *plKyAdr  = NULL;							/* 共有メモリ先頭アドレス					*/
	struct sigaction new[D_MAX_SIG_NUM];			/* シグナルハンドラ格納用					*/
	int  iSigCnt = 0;								/* シグナルカウンタ							*/


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	/****************************************/
	/*  例外ハンドラの設定					*/
	/****************************************/
													/* ループ処理								*/
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		switch(iSigCnt+1)							/* シグナル番号で振り分け					*/
		{
			case SIGILL:                        	/* 不正な命令								*/
			case SIGBUS:                        	/* バスエラー								*/
			case SIGFPE:                        	/* 浮動小数点例外							*/
			case SIGSEGV:                       	/* 不正なメモリ参照							*/
//			case SIGPIPE:                       	/* パイプ破壊								*/
			case SIGTERM:                       	/* 終了シグナル								*/
			case 16:                            	/* 空き										*/
													/* シグナルハンドラの設定					*/
				new[iSigCnt].sa_handler = os_sigact;
				break;

//			case SIGALRM:
//				new[iSigCnt].sa_handler = os_timex;
//				break;

			case SIGCHLD:							/* 子プロセスの一旦停止 (stop) または終了	*/
				if(NULL != pvShmAdr)				/* 共有メモリ先頭アドレスがNULL以外の場合	*/
				{
													/* シグナルハンドラの設定					*/
					new[iSigCnt].sa_handler = os_gttrmcod;
					break;
				}

			default:								/* その他									*/
				new[iSigCnt].sa_handler = SIG_IGN;	/* シグナルハンドラの設定					*/
				break;
		}
		new[iSigCnt].sa_flags = 0;					/* シグナルフラグの設定						*/
													/* シグナルの操作							*/
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}


	/****************************************/
	/*  デバッグ設定						*/
	/****************************************/
	DbgInit( D_DEF, D_DEF, D_DEF );					/* デバッグ初期設定							*/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initProcess\n") );

	if(NULL == pvShmAdr)							/* テーブル格納用共有メモリ先頭アドレスが	*/
	{												/* NULLの場合								*/

		os_startSG();								/* ＳＧ開始処理								*/
													// 20030330
	    os_startTrace();							/* トレース開始処理							*/
	}

//  os_startTrace();                            	// 20030123
//	os_trcget2( D_MD_OS_INITPROCESS, D_T_TRA_IN, 3, lShmId, pvShmAdr, lMBoxId );

	ptEsys = &tEsys;								/* システム管理テーブル先頭アドレス設定		*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys:%x\n", ptEsys));


	/****************************************/
	/*  引数のチェック						*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** 引数チェック\n"));
	
	if( 0 == lShmId )								/* テーブル格納用共有メモリエラー			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 01:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_PRA );
		//abort();
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lShmId :%x\n", lShmId ) );

	if( NULL == ptEsys )							/*システム管理テーブル先頭アドレスエラー*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 02:Err Mess:%s\n", "initProccess", strerror(errno) ));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS );
		//abort();									/*	異常処理	*/
		
	}
//	DbgMsg01( DLv04, ( OutPut, "***** pvShmAdr :%x\n", pvShmAdr ) );

	if( 0 == lMBoxId )								/*	メイルボックス識別子エラー	*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 03:Err Mess:%s\n", "initProccess", strerror(errno) ));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS1);
		//abort();
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lMBoxId :%x\n", lMBoxId ) );


	/****************************************/
	/*  ＳＧの取得							*/
	/****************************************/
	lRes = os_getSG(D_SG_TABLE_ADR, &lTblMemAdr);	/* 共有メモリ先頭アドレス取得				*/
	if(NORMAL != lRes)								/* ＳＧ読込失敗								*/
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01%s\n", strerror(errno) ) );

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS2);
		//abort();									/*	異常処理 */

	}

	lRes = os_getSG(D_SG_EBPC_ADR, &lBpAdr);		/* バッファプール領域先頭アドレス取得		*/
	if(NORMAL != lRes)								/* ＳＧ読込失敗								*/
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS3);
		//abort();									/*	異常処理 */

	}

    /********************************************************************************************/
    /*  本処理                                                                                  */
    /********************************************************************************************/
	lRes = getpid();								/* 自プロセスID取得設定						*/

	tEsys.tMyPrcInfo.lMyPid = lRes;					/* システム管理テーブルの自プロセスＩＤ設定	*/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMyPrcInfo.lMyPid :%d\n", tEsys.tMyPrcInfo.lMyPid) );

	strncpy( tEsys.acTid, D_ESYS_TID,4);			/* 領域識別子の設定							*/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.acTid : %s\n", tEsys.acTid) );
//	DbgMsg01( DLv04, ( OutPut, "***** アタッチ pvShmAdr:%x\n", pvShmAdr) );


	/****************************************/
	/*  TRADE管理テーブル先頭アドレスの設定	*/
	/****************************************/
	if(NULL == pvShmAdr)							/* テーブル格納用共有メモリ先頭アドレスが	*/
	{												/* NULLの場合								*/

		if(0 == lTblMemAdr)							/* 共有メモリ先頭アドレス格納用(SG)が		*/
		{											/* 「０」の場合								*/

													/* 共有メモリのアタッチ（アドレス指定なし）	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, lShmId, NULL, 0 );
			plKyAdr = shmat( lShmId, NULL, 0);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plKyAdr );
		}
		else										/* 共有メモリ先頭アドレス格納用(SG)が		*/
		{											/* 「０以外」の場合							*/

													/* 共有メモリのアタッチ（アドレス指定あり）	*/
			os_trcget2(D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, lShmId, (void *)lTblMemAdr, SHM_RND);
			plKyAdr = shmat( lShmId, (void *)lTblMemAdr, SHM_RND);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plKyAdr );
		}

		if( -1 == (long)plKyAdr)					/* 共有メモリのアタッチに失敗				*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s 04:Err Mess:%s\n", "initProccess",
					strerror(errno) ) );

													/* アボート									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS4);
			//abort();
		}

//		DbgMsg01( DLv04, ( OutPut, "***** plKyAdr :%x\n", plKyAdr) );
		ptEtrd = (TEtrdTable *)plKyAdr;				/* TRADE管理テーブル先頭アドレスに			*/
													/* 共有メモリ先頭アドレスを設定する			*/
	}
	else											/* テーブル格納用共有メモリ先頭アドレスが	*/
	{												/* NULLの場合								*/

		ptEtrd = pvShmAdr;							/* TRADE管理テーブル先頭アドレスに			*/
													/* テーブル格納用共有メモリ先頭アドレス設定 */
	}

//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd : %x\n",ptEtrd ) );


	/****************************************/
	/*	TRADEテーブル関連項目の設定			*/
	/*	相対アドレスから絶対アドレスを求める*/
	/****************************************/
	/********************************/
	/*	EPRC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstEPRC.pvAdr  = (void *)( ptEtrd->tTrdEPRC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEPRC.lSize  = ptEtrd->tTrdEPRC.lSize;
	ptEsys->tMstEPRC.lSemId = ptEtrd->tTrdEPRC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.pvAdr  :%lx\n", ptEsys->tMstEPRC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.lSize  :%ld\n", ptEsys->tMstEPRC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.lSemId :%ld\n", ptEsys->tMstEPRC.lSemId));

	/********************************/
	/*	EBPC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstEBPC.pvAdr = (void *)( ptEtrd->tTrdEBPC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEBPC.lSize  = ptEtrd->tTrdEBPC.lSize;
	ptEsys->tMstEBPC.lSemId = ptEtrd->tTrdEBPC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.pvAdr  :%lx\n", ptEsys->tMstEBPC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.lSize  :%ld\n", ptEsys->tMstEBPC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.lSemId :%ld\n", ptEsys->tMstEBPC.lSemId));

	/********************************/
	/*	ESBC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstESBP.pvAdr = (void *)( ptEtrd->tTrdESBP.lRAdr + (long)ptEtrd );
	ptEsys->tMstESBP.lSize  = ptEtrd->tTrdESBP.lSize;
	ptEsys->tMstESBP.lSemId = ptEtrd->tTrdESBP.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.pvAdr  :%lx\n", ptEsys->tMstESBP.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.lSize  :%ld\n", ptEsys->tMstESBP.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.lSemId :%ld\n", ptEsys->tMstESBP.lSemId));

	/********************************/
	/*	EPBC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstEPBC.pvAdr = (void *)( ptEtrd->tTrdEPBC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEPBC.lSize  = ptEtrd->tTrdEPBC.lSize;
	ptEsys->tMstEPBC.lSemId = ptEtrd->tTrdEPBC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.pvAdr  :%lx\n", ptEsys->tMstEPBC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.lSize  :%ld\n", ptEsys->tMstEPBC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.lSemId :%ld\n", ptEsys->tMstEPBC.lSemId));

	/********************************/
	/*	EMMC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstEMMC.pvAdr = (void *)( ptEtrd->tTrdEMMC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEMMC.lSize  = ptEtrd->tTrdEMMC.lSize;
	ptEsys->tMstEMMC.lSemId = ptEtrd->tTrdEMMC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.pvAdr  :%lx\n", ptEsys->tMstEMMC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.lSize  :%ld\n", ptEsys->tMstEMMC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.lSemId :%ld\n", ptEsys->tMstEMMC.lSemId));

	/********************************/
	/*	EMBC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstEMBC.pvAdr = (void *)( ptEtrd->tTrdEMBC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEMBC.lSize  = ptEtrd->tTrdEMBC.lSize;
	ptEsys->tMstEMBC.lSemId = ptEtrd->tTrdEMBC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.pvAdr  :%lx\n", ptEsys->tMstEMBC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.lSize  :%ld\n", ptEsys->tMstEMBC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.lSemId :%ld\n", ptEsys->tMstEMBC.lSemId));

	/********************************/
	/*	ESMC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstESMC.pvAdr = (void *)( ptEtrd->tTrdESMC.lRAdr + (long)ptEtrd );
	ptEsys->tMstESMC.lSize  = ptEtrd->tTrdESMC.lSize;
	ptEsys->tMstESMC.lSemId = ptEtrd->tTrdESMC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.pvAdr  :%lx\n", ptEsys->tMstESMC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.lSize  :%ld\n", ptEsys->tMstESMC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.lSemId :%ld\n", ptEsys->tMstESMC.lSemId));

	/********************************/
	/*	ESGC絶対アドレス算出		*/
	/********************************/
	ptEsys->tMstESGC.pvAdr = (void *)( ptEtrd->tTrdESGC.lRAdr + (long)ptEtrd );
	ptEsys->tMstESGC.lSize  = ptEtrd->tTrdESGC.lSize;
	ptEsys->tMstESGC.lSemId = ptEtrd->tTrdESGC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.pvAdr  :%lx\n", ptEsys->tMstESGC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.lSize  :%ld\n", ptEsys->tMstESGC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.lSemId :%ld\n", ptEsys->tMstESGC.lSemId));


	/****************************************/
	/*	各テーブルの初期化					*/
	/****************************************/
	/********************************/
	/*	自プロセス管理テーブル設定	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** os_MyEPRC\n"));
	lRes = os_MyEPRC();								/*	自プロセス管理情報取得					*/
	if(NORMAL != lRes)								/*	自プロセス管理情報取得エラー			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 05:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS5);
		//abort();
	}


	/********************************/
	/*	親プロセスへシグナルを送信	*/
	/********************************/
	if(NULL == pvShmAdr)							/* テーブル格納用共有メモリ先頭アドレスが	*/
	{												/* NULLの場合								*/
//		os_startSG();
		DbgMsg01( DLv04, ( OutPut, "***** kill 発行\n"));

		lRes = kill(getppid(), SIGUSR1);			/* 親プロセスにシグナルを送る				*/
		if(NORMAL != lRes)							/* 異常終了の場合							*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s 06:Err Mess kill:%s\n", "initProccess",
					strerror(errno) ) );

													/* アボート									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS6);
		}
	}


	/********************************/
	/*	自メイルボックス管理テーブル*/
	/*	初期化						*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** lMBoxId :%x\n", lMBoxId));
	lRes = os_MyEMBC(lMBoxId);						/*	自メイルボックス管理情報取得			*/
	if(NORMAL != lRes)								/*	自メイルボックス管理情報取得エラー		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS7);
		//abort();
	}

	/********************************/
	/*	ファイル管理テーブル初期化	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstEFLC : %x\n", &(tEsys.tMstEFLC) ) );
	lRes = os_initEFLC( &(tEsys.tMstEFLC) );
	if ( NORMAL != lRes )							/* ファイル管理テーブルの初期化エラー		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 08:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS8);
		//abort();
	}

	/********************************/
	/*	ｒｄ管理テーブル初期化		*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstERDC : %x\n", &(tEsys.tMstERDC) ) );
	lRes = os_initERDC( &(tEsys.tMstERDC) );
	if ( NORMAL != lRes )							/* リザルト管理テーブルの初期化エラー		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS9);
		//abort();
	}

	/********************************/
	/*	タイマ管理テーブル初期化	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstETMC : %x\n", &(tEsys.tMstETMC) ) );
	lRes = os_initETMC( &(tEsys.tMstETMC) );
	if ( NORMAL != lRes )							/* タイマ管理テーブルの初期化エラー			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 10:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* アボート									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS10 );
		//abort();
	}

	/****************************************/
	/*	各ポインタの初期化					*/
	/****************************************/
	ptEprc = tEsys.tMstEPRC.pvAdr;					/* プロセス管理テーブル先頭アドレス設定		*/
	ptEbpc = tEsys.tMstEBPC.pvAdr;					/* バッファ管理テーブル先頭アドレス設定		*/
	ptEsbp = tEsys.tMstESBP.pvAdr;					/* 空きバッファプール管理テーブル			*/
													/* 先頭アドレス設定							*/
	ptEpbc = tEsys.tMstEPBC.pvAdr;					/* プールバッファ管理テーブル				*/
													/* 先頭アドレス設定							*/
	ptEmmc = tEsys.tMstEMMC.pvAdr;					/* メッセージ管理テーブル先頭アドレス設定	*/
	ptEmbc = tEsys.tMstEMBC.pvAdr;					/* メイルボックス管理テーブル				*/
													/* 先頭アドレス設定							*/
	ptEsmc = tEsys.tMstESMC.pvAdr;					/* 共有メモリ管理テーブル先頭アドレス設定	*/
	ptEflc = tEsys.tMstEFLC.pvAdr;					/* ファイル管理テーブル先頭アドレス設定		*/
	ptErdc = tEsys.tMstERDC.pvAdr;					/* ｒｄ管理テーブル先頭アドレス設定			*/
	ptEtmc = tEsys.tMstETMC.pvAdr;					/* タイマ管理テーブル先頭アドレス設定		*/

	lMyPid = tEsys.tMyPrcInfo.lMyPid;				/* 自プロセスID設定							*/
													/* 自プロセス管理情報						*/
	ptMyEPRC = (TEprcTableInd *)(tEsys.tMyPrcInfo.ptMyEPRC);
													/* 自メイルボックス管理情報					*/
	ptMyEMBC = (TEmbcTableInd *)(tEsys.tMyPrcInfo.ptMyEMBC);

//	DbgMsg01( DLv04, ( OutPut, "***** ptEprc:%x\n", ptEprc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpc:%x\n", ptEbpc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbp:%x\n", ptEsbp));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEpbc:%x\n", ptEpbc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmmc:%x\n", ptEmmc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmbc:%x\n", ptEmbc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsmc:%x\n", ptEsmc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc:%x\n", ptEflc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc:%x\n", ptErdc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtmc:%x\n", ptEtmc));
//	DbgMsg01( DLv04, ( OutPut, "***** lMyPid:%d\n", lMyPid));
//	DbgMsg01( DLv04, ( OutPut, "***** ptMyEPRC:%x\n", ptMyEPRC));
//	DbgMsg01( DLv04, ( OutPut, "***** ptMyEMBC:%x\n", ptMyEMBC));

//	バッファプール管理テーブル管理部情報のダンプ
//	DbgDmp02( DLv04, ("ptEbpc", ptEbpc, sizeof(TEbpcTable),1,0));
//	DbgDmp01( DLv04, ("ptEbpc", ptEbpc, sizeof(TEbpcTable)));

//	バッファプール管理テーブル個別部情報のダンプ
//	DbgDmp02( DLv04, ("ptEbpcp", (ptEbpc + 1), (sizeof(TEbpcTableInd) * 10),1,0));
//	DbgDmp01( DLv04, ("ptEbpcp", (ptEbpc + 1), (sizeof(TEbpcTableInd) * 10));

	/****************************************/
	/*	バッファプール先頭アドレスの設定	*/
	/****************************************/
	if(NULL == pvShmAdr)							/* テーブル格納用共有メモリ先頭アドレスが	*/
	{												/* NULLの場合								*/

		if(0 == lBpAdr)								/* バッファプール領域先頭アドレス(SG)が		*/
		{											/* 「０」の場合								*/

													/* 共有メモリのアタッチ（アドレス指定なし）	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, (int)(ptEbpc->lShmId), NULL, 0 );
			plShmAdr = shmat((int)(ptEbpc->lShmId), NULL, 0);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plShmAdr );
		}
		else										/* バッファプール領域先頭アドレス(SG)が		*/
		{											/* 「０以外」の場合							*/

													/* 共有メモリのアタッチ（アドレス指定あり）	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3,
						(int)(ptEbpc->lShmId), (void *)lBpAdr, SHM_RND );
			plShmAdr = shmat((int)(ptEbpc->lShmId), (void *)lBpAdr, SHM_RND);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plShmAdr );
		}

		if(D_ERR_SYS == (long)plShmAdr)				/* アタッチが異常終了の場合					*/
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 11:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));

													/* アボート									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS11 );
			//abort();							// 20021225 追加
		}

		ptEbpc->pvAdr = (void*)plShmAdr;			/* バッファプール先頭アドレス設定			*/
//		DbgMsg01(DLv04, (OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr));
	}

//	DbgDmp02( DLv04, ("ptMyEPRC（個別部情報）", ptMyEPRC, sizeof(TEprcTableInd), 1, 0));
//	DbgDmp02( DLv04, ("ptMyEmbc（個別部情報）", ptMyEMBC, sizeof(TEmbcTableInd), 1, 0));


	/****************************************/
	/*	例外ハンドラの設定（タイムアウト）	*/
	/****************************************/
	new[SIGALRM - 1].sa_handler = os_timex;			/* シグナルハンドラの設定					*/
	new[SIGALRM - 1].sa_flags = 0;					/* シグナルフラグの設定						*/
	sigaction(SIGALRM, &(new[SIGALRM - 1]), NULL);	/* シグナルの操作							*/


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/

	/*****	障害対応（S00080）	Start									修正日：2003.05.13	*****/
	/********************************************************************************************/
	/*	プロセス再起動時のメッセージ刈り取り処理を追加											*/
	/********************************************************************************************/
	if(NULL == pvShmAdr)							/* 子プロセス生成時のみ						*/
	{
		lRes = os_SubMsgAtc();						/* サブメッセージのアタッチ処理				*/
		DbgMsg01(DLv04, (OutPut, "***** %s os_SubMsgAtc() lRes:%08lx\n", "os_initProcess", lRes));

		if (NORMAL != lRes)							/* 異常終了の場合							*/
		{
													/* アボート									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 1, lRes );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS12 );
		}

		lRes = osanyrl(&lRda, 0);					/* 不特定リザルト							*/
													/* （メッセージの刈り取りを行う）			*/

													/* 返却値がタイムアウト、又は				*/
													/* メッセージキュー削除以外の場合			*/
		if((OSEETOUT != lRes) && (OSEEDELD != lRes))
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 12:Err Mess:%s\n",
					"os_initProcess", strerror(errno) ));

													/* アボート									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 1, lRes );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS13 );
		}
	}
	/*****	障害対応（S00080）	 End									修正日：2003.05.13	*****/

//	os_endSG();

	DbgMsg01( DLv02, ( OutPut, "***** End os_initProcess\n") );
	os_trcget2( D_MD_OS_INITPROCESS, D_T_TRA_OUT, 1, NORMAL );
	return (NORMAL);
}


/*****	障害対応（S00080）		Start									修正日：2003.05.13	*****/
/************************************************************************************************/
/*																								*/
/*	＜関数名＞																					*/
/*		os_SubMsgAtc 																			*/
/*																								*/
/*	＜機能概要＞																				*/
/*		自メイルボックス管理テーブルのサブメッセージを検索し、該当するサブメッセージがある場合、*/
/*		サブメッセージに対して共有メモリのアタッチ処理を行う。									*/
/*																								*/
/*	パラメータ																					*/
/*		なし																					*/
/*																								*/
/*	返却値																						*/
/*		NORMAL	: 正常終了																		*/
/*		-1 		: 異常終了																		*/
/*																								*/
/************************************************************************************************/
long os_SubMsgAtc()
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	char 		*pcCmptr  = NULL;					/* アタッチする仮想アドレスポインタ 		*/
	TMsgInfo	*ptMsgNxt = NULL;					/* 次メッセージ情報ポインタ					*/


	/********************************************************************************************/
	/*  本処理                                                                                  */
	/********************************************************************************************/
	os_trcget2(D_MD_OS_SUBMSGATC, D_T_TRA_IN, 0);
	DbgMsg01(DLv04, (OutPut, "\n***** %s: os_SubMsgAtc() Start \n", "os_SubMsgAtc"));


	/************************************/
	/*  サブメッセージ検索				*/
	/************************************/
	while(1)
	{
													/* 受信メッセージのアドレスチェック			*/
		if (NULL == ptMyEMBC->tSubMsgQ.ptNxtAdr)	/* サブメッセージキューの次アドレスがNULL	*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMyEMBC->tSubMsgQ.ptNxtAdr=%08x\n",
					"os_SubMsgAtc", ptMyEMBC->tSubMsgQ.ptNxtAdr));

			break;									/* ループを抜ける							*/
		}

		if (NULL == ptMsgNxt)						/* 次メッセージ情報ポインタがNULLの場合		*/
		{
			/****************************************/
			/*  共有メモリのアタッチ				*/
			/****************************************/
													/* 共有メモリのアッタチ						*/
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_SHMAT, 3, ptMyEMBC->tSubMsgQ.lShmId, 0, 0);
			pcCmptr = (char *)shmat(ptMyEMBC->tSubMsgQ.lShmId,ptMyEMBC->tSubMsgQ.ptNxtAdr,SHM_RND);
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_END, 2, pcCmptr, errno);

			if (D_ERR_SYS == pcCmptr)				/* 異常終了の場合							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
						"os_SubMsgAtc", "shmat() Call Error!!", errno, strerror(errno)));
				return(-1);							/* 異常終了									*/
			}

													/* サブメッセージキューの次アドレスを設定	*/
			ptMsgNxt = ptMyEMBC->tSubMsgQ.ptNxtAdr;
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x \n", "os_SubMsgAtc", ptMsgNxt));
		}
		else
		{
			if (NULL == ptMsgNxt->ptNxtAdr)			/* 次メッセージ情報の次アドレスがNULLの場合 */
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt->ptNxtAdr = %08x \n", "os_SubMsgAtc",
						ptMsgNxt->ptNxtAdr));

				break;								/* ループを抜ける							*/
			}

			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMsgNxt=%08x\n", "os_SubMsgAtc", ptMsgNxt));
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMsgNxt->lShmId=%08x\n", "os_SubMsgAtc",
					ptMsgNxt->lShmId));

			/****************************************/
			/*  共有メモリのアタッチ				*/
			/****************************************/
													/* 共有メモリのアッタチ						*/
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_SHMAT, 3, ptMsgNxt->lShmId, 0, 0);
			pcCmptr = (char *)shmat(ptMsgNxt->lShmId, ptMsgNxt->ptNxtAdr, SHM_RND);
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_END, 2, pcCmptr, errno);

			if (D_ERR_SYS == pcCmptr)				/* 異常終了の場合							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
						"os_SubMsgAtc", "shmat() Call Error!!", errno, strerror(errno)));
				return(-1);							/* 異常終了									*/
			}

													/* 次メッセージ情報の次アドレスを設定		*/
			ptMsgNxt = (TMsgInfo *)ptMsgNxt->ptNxtAdr;
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x \n", "os_SubMsgAtc", ptMsgNxt));
		}
	}


	/********************************************************************************************/
	/*  終了処理                                                                                */
	/********************************************************************************************/
	os_trcget2(D_MD_OS_SUBMSGATC, D_T_TRA_OUT, 1, NORMAL);
	DbgMsg01(DLv04, (OutPut, "\n***** %s: os_SubMsgAtc()  End  \n", "os_SubMsgAtc"));
	return(NORMAL);									/* 正常終了									*/
}
/*****	障害対応（S00080）		 End									修正日：2003.05.13	*****/
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
