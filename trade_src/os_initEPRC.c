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
/* ＜モジュール名＞					 プロセス管理テーブルの初期化								*/
/* ＜モジュールＩＤ＞				 os_initEPRC												*/
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
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月２８日		故障管理番号（ＴＢＣＳ０２４６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 プロセス管理テーブルの各項目の初期化を行う													*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initEXXX_ins.h>															*/
/*																								*/
/*		long os_initEPRC(char *pcEprcTableAdr, long lPCode)										*/
/*																								*/
/* ＜仮引数＞																					*/
/*		char *pcEprcTableAdr	プロセス管理テーブル先頭アドレス								*/
/*		long lPCode				プロセス識別子													*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値	NORMAL																		*/
/*		異常戻り値	OSERRARG		引数異常													*/
/*					OSERRSG			SG読込異常													*/
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/*****	故障管理番号TBCS0246の対応		Start							修正日：2003.07.28	*****/
#include <sys/time.h>
#include <sys/resource.h>
/*****	故障管理番号TBCS0246の対応		 End							修正日：2003.07.28	*****/

/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initEPRC(char *pcEprcTableAdr, long lPCode)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	TEprcTableInd *ptEprcInd;					/*	EPRC個別部				*/
	long lEPRCKbt = 0;							/*	EPRC個別部数			*/
	//moa 設定
	char acPrcName[9];							/* プロセス名				*/
	long lLank = 0;								/* ランク 					*/
	long lMaxFileNum = 0;						/* ファイル記述子最大個数	*/
	long lUserIdCode = 0;						/* ユーザ識別コード			*/
	long lPAttr = 0;							/* プロセス属性				*/
	long lAccess = 0;							/* アクセス権				*/
	long lPPriority = 0;						/* 起動時プロセス優先度		*/
	long lModifPriority = 0;					/* 変更可能最高優先度		*/
	long lLogicSpace = 0;						/* 論理空間のサイズ			*/
	long lTimeSlice = 0;						/* タイムスライス値			*/
	long lReqIdMax = 0;							/* リクエスト識別子最大個数	*/
	
	long lRes = 0;								/*	返却値格納用			*/
	long lCnt = 0;
	long lTemp = 0;
	
/****************************************/
/*	初期処理							*/
/****************************************/
	/*	引数の確認							*/
	DbgMsg01( DLv01, ( OutPut, "***** Start os_initEPRC\n" ) );
	
	if( 0 == pcEprcTableAdr )					//プロセス管理テーブル先頭アドレス異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		return( OSERRARG );						//引数異常を返却
	}
	
	if( 0 == lPCode )							//プロセス識別子異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		return( OSERRARG );						//引数異常を返却	
	}
	/*------------------------------*/
	/*	設定領域の構造化			*/
	/*------------------------------*/
	
	/* 管理部情報の構造化		*/
	ptEprcInd = NULL;
	ptEprc = (TEprcTable *)pcEprcTableAdr;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprc アドレス:%lx\n", ptEprc ) );
	
	/*	個別部情報の定義						*/
	ptEprcInd = (TEprcTableInd *) ( (long)ptEprc + sizeof(TEprcTable) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEprcInd %x\n", ptEprcInd ) );

	/****************************************/
	/*	SGの読み込み						*/
	/****************************************/

	lRes = os_getSG(D_SG_EPRC_NUM,&lEPRCKbt);	// EPRC個別部読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_PRC_NAME,acPrcName);	// プロセス名読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err02:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_LANK,&lLank);	// ランク読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_FILE_ID_MAX,&lMaxFileNum);	// ファイル記述子最大個数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err04:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_ID_CODE,&lUserIdCode);	// ユーザ識別コード読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err05:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_PRC_PAT,&lPAttr);	// プロセス属性読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err06:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lAccess = D_SEM_ACCESS;                     // アクセス権読み込み

	lRes = os_getSG(D_SG_MOA_PRC_USEN,&lPPriority);	// 起動時プロセス優先度読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err07:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_HENKO,&lModifPriority);	// 変更可能最高優先度読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err08:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_LOGI_SIZE,&lLogicSpace);	// 論理空間のサイズ読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err09:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_TIME_SLI,&lTimeSlice);	// タイムスライス値読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err10:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
	
	lRes = os_getSG(D_SG_MOA_REQ_MAX,&lReqIdMax);	// リクエスト識別子最大個数読み込み
	if(NORMAL != lRes)							//ＳＧ読込異常
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err11:%s\n", strerror(errno) ) );
		return( OSERRSG );						//ＳＧ読込異常を返却
	}
/****************************************/
/*	本処理								*/
/****************************************/

	strncpy( ptEprc->acTid, D_EPRC_TID, 4 );	/*	領域識別子の設定		*/
//	DbgMsg01( DLv04, ( OutPut, "***** 領域識別子:%s\n", ptEprc->acTid ) );

	ptEprc->lIndPartNum = lEPRCKbt;				/*	個別部数の設定			*/
//	DbgMsg01( DLv04, ( OutPut, "***** 個別部数の個数:%ld\n", ptEprc->lIndPartNum ) );

	/*--------------------------------------*/
	/* 個別部情報の初期化                   */
	/*--------------------------------------*/
//	DbgMsg01( DLv04, ( OutPut, "***** moa情報の設定\n"));
	
	ptEprcInd->lPCode = lPCode;					/* プロセス識別子格納			*/
//	DbgMsg01( DLv04, ( OutPut, "***** moaプロセス識別子x :%lx\n", ptEprcInd->lPCode));
	
	ptEprcInd->cLaunchFlg = 'S';				/* 立ち上げ状態に"S"を格納		*/
//	DbgMsg01( DLv04, ( OutPut, "***** 立ち上げ状態c :%c\n", ptEprcInd->cLaunchFlg));
	
//	strcpy(ptEprcInd->acPName, "moa");				// 20021218 修正
//	strncpy(ptEprcInd->acPName, "moa000  ", 8);		// 20030307 修正
	strncpy(ptEprcInd->acPName, acPrcName, 8);		/* プロセス名にmoaを格納		*/
//	DbgMsg01( DLv04, ( OutPut, "***** プロセス名s :%s\n", ptEprcInd->acPName));
	
	ptEprcInd->lLank = lLank;					/* ランクを格納)				*/
//	DbgMsg01( DLv04, ( OutPut, "***** ランクx :%lx\n", ptEprcInd->lLank));
	
													// 20030310 KL0028 追加
	if(D_ERR_SYS == lMaxFileNum)
	{
													// ファイル記述子最大個数読み込み
		lRes = os_getSG(D_SG_EFLC_NUM,&lMaxFileNum);
		if(NORMAL != lRes)							//ＳＧ読込異常
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err12:%s\n", strerror(errno) ) );
			return( OSERRSG );						//ＳＧ読込異常を返却
		}
	}
	ptEprcInd->lMaxFileNum = lMaxFileNum;			/* ファイル記述子最大個数格納	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ファイル記述子最大個数x :%lx\n", ptEprcInd->lMaxFileNum));
	
	ptEprcInd->lUid = lUserIdCode;					/* ユーザ識別コード格納			*/
//	DbgMsg01( DLv04, ( OutPut, "***** ユーザ識別コードx :%lx\n", ptEprcInd->lUid));
	
	ptEprcInd->lPAttr = lPAttr;					/* プロセス属性格納				*/
//	DbgMsg01( DLv04, ( OutPut, "***** プロセス属性x :%lx\n", ptEprcInd->lPAttr));
	
	ptEprcInd->lAccess = lAccess;					/* アクセス権格納				*/
//	DbgMsg01( DLv04, ( OutPut, "***** アクセス権o :%lo\n", ptEprcInd->lAccess));
	
	ptEprcInd->lPPriority = lPPriority;			/* 起動時プロセス優先権格納		*/
//	DbgMsg01( DLv04, ( OutPut, "***** 起動時プロセス優先権x :%lx\n", ptEprcInd->lPPriority));
	
	ptEprcInd->lModifPriority = lModifPriority;	/* 変更可能最高優先度格納			*/
//	DbgMsg01( DLv04, ( OutPut, "***** 変更可能最高優先度x :%lx\n", ptEprcInd->lModifPriority));
	
													// 20030312 追加
	if(D_ERR_SYS == lLogicSpace)
	{
		lRes = os_getSG(D_SG_LOGI_SIZE,&lLogicSpace);	// 論理空間サイズ読み込み
		if(NORMAL != lRes)							//ＳＧ読込異常
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err13:%s\n", strerror(errno) ) );
			return( OSERRSG );						//ＳＧ読込異常を返却
		}
	}
	ptEprcInd->lLogSpaceSize = lLogicSpace;		/* 論理空間サイズ格納			*/
//	DbgMsg01( DLv04, ( OutPut, "***** 論理空間サイズx :%lx\n", ptEprcInd->lLogSpaceSize));

													// 20030312 追加
	if( (D_ERR_SYS == lTimeSlice) || (0 == lTimeSlice) )
	{
		lRes = os_getSG(D_SG_TIME_SLI,&lTimeSlice);	// タイムスライス値読み込み
		if(NORMAL != lRes)							//ＳＧ読込異常
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err14:%s\n", strerror(errno) ) );
			return( OSERRSG );						//ＳＧ読込異常を返却
		}
	}
	ptEprcInd->lTimeSlice = lTimeSlice;			/* タイムスライス値格納			*/
//	DbgMsg01( DLv04, ( OutPut, "***** タイムスライス値x :%lx\n", ptEprcInd->lTimeSlice));
	
													// 20030310 KL0028 追加
	if(D_ERR_SYS == lReqIdMax)
	{
		lRes = os_getSG(D_SG_ERDC_NUM,&lReqIdMax);	// リクエスト識別子最大個数読み込み
		if(NORMAL != lRes)							//ＳＧ読込異常
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err15:%s\n", strerror(errno) ) );
			return( OSERRSG );						//ＳＧ読込異常を返却
		}
	}
	ptEprcInd->lMaxReqNum = lReqIdMax;				/* リクエスト識別子最大個数格納		*/
//	DbgMsg01( DLv04, ( OutPut, "***** リクエスト識別子最大個数x :%lx\n", ptEprcInd->lMaxReqNum));
	
	ptEprcInd->lEndCode = D_END_CODE1;			/* 終了コード初期値設定 */
	ptEprcInd->lDetailCode = 0;					/* 詳細情報初期化       */
	memset( &(ptEprcInd->func[0]), -1, 32 * sizeof(long) );	/* 例外ハンドラ初期化 */
	
	/*----------------------------------*/
	/* moaのプロセスIDの取得            */
	/*----------------------------------*/
	lRes = (long)getpid();
	if(0 > lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		//getpidで異常系はなし
	}
	
	ptEprcInd->lPid = lRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd->lPid :%d\n", ptEprcInd->lPid));
	
	/*----------------------------------*/
	/* moaのグループIDの取得            */
	/*----------------------------------*/
	lRes = (long)getgid();
	if(0 > lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		//getgidで異常系はなし
	}
	
	ptEprcInd->lGid = lRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd->lGid :%d\n", ptEprcInd->lGid));

/*****	故障管理番号TBCS0246の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	moaの起動時プロセス優先度の設定処理を追加													*/
/************************************************************************************************/
	/*----------------------------------*/
	/* moaの起動時プロセス優先度の設定  */
	/*----------------------------------*/
	errno = 0;										// errno クリア

	os_trcget2( D_MD_OS_INITEPRC, D_T_SYS_SETPRIORITY, 3,
				PRIO_PROCESS, ptEprcInd->lPid, lPPriority );
													// moaのスケジューリングの優先度を設定
	lRes = setpriority(PRIO_PROCESS, ptEprcInd->lPid, lPPriority);
	os_trcget2( D_MD_OS_INITEPRC, D_T_SYS_END, 2, lRes, errno );

	DbgMsg01(DLv04, (OutPut, "***** os_initEPRC:lPPriority=%ld\n", lPPriority));
	DbgMsg01(DLv04, (OutPut, "***** os_initEPRC:setpriority() lRes=%ld, errno=%d\n", lRes, errno));
/*****	故障管理番号TBCS0246の対応		 End							修正日：2003.07.28	*****/

	/*----------------------------------*/
	/* プロセス識別子の初期化           */
	/*----------------------------------*/
	
	lTemp = 0x00010002;
	
	for(lCnt = 1;lCnt < lEPRCKbt;lCnt++,lTemp++)
	{
		if(lPCode == lTemp)
		{
			(ptEprcInd + lCnt)->lPCode = 0x00010001;
		}
		else
		{
			(ptEprcInd + lCnt)->lPCode = lTemp;
		}
//		DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd[%d]->lCode :%x\n",lCnt, (ptEprcInd + lCnt)->lPCode));
	}
	
/****************************************/
/*	終了処理							*/
/****************************************/
	DbgMsg01( DLv01, ( OutPut, "***** End os_initEPRC\n" ) );
	return (NORMAL);
}
