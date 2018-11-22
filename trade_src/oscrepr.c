/************************************************************************************************/
/*  著作権  ２００２                                                                            */
/*            株式会社ＮＴＴデータ                                                              */
/*              金融ビジネス事業本部                                                            */
/*                                                                                              */
/*                                                                                              */
/*  収容物  ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ                                  */
/************************************************************************************************/
/* ＜対象業務名＞                    ＴＲＡＤＥエミュレータ                                     */
/* ＜対象業務ＩＤ＞                  ＴＲＥ                                                     */
/* ＜サービス項目名＞                プロセス制御                                               */
/* ＜サービス項目ＩＤ＞              ＸＸＸＸＸＸＸ                                             */
/* ＜モジュール名＞                  プロセスの生成                                             */
/* ＜モジュールＩＤ＞                oscrepr                                                    */
/* ＜モジュール通番＞                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種名＞                    汎用サーバ                                                 */
/* ＜適用ＯＳ＞                      Ｌｉｎｕｘ                                                 */
/* ＜開発環境＞                      ＲＨＡＳ２．１                                             */
/* ＜記述言語＞                      Ｃ言語                                                     */
/* ＜モジュール形態＞                関数                                                       */
/* ＜機能区分＞                                                                                 */
/* ＜対象データ＞                                                                               */
/* ＜工程・階層区分＞                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞                ＬＡＬａ−ＳＭＰシステム                                   */
/* ＜開発システム番号＞              ＰＰ４０Ｂ００１２２０                                     */
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞                    ＣＢ事ビジネス企画担当(メーカー：サプライ)                 */
/* ＜電話番号＞                      148-1457(03-5437-1457)                                     */
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞                      ＣＢ事ビジネス企画担当                                     */
/* ＜設計年月日＞                    ２００２年  ９月２７日                                     */
/* ＜設計修正者名＞                                                                             */
/* ＜設計修正年月日及び修正ＩＤ＞                                                               */
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞					ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
/* ＜ソース作成年月日＞              ２００２年  ９月２７日                                     */
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月２８日		故障管理番号（ＴＢＣＳ０２３１）*/
/*																故障管理番号（ＴＢＣＳ０２３２）*/
/*																故障管理番号（ＴＢＣＳ０２３３）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞                ステップ                                                   */
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞                                                                                 */
/*      プロセスの作成                                                                          */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                                                 */
/*		#include	<oscrepr_ins.h>																*/
/*                                                                                              */
/*   long oscrepr( char *fn , long pid , long flag ,                                            */
/*                 osepib *pibp , osearg *argp )                                                */
/*                                                                                              */
/* ＜仮引数＞                                                                                   */
/*      char *fn        プログラムファイル名                                                    */
/*      long pid        プロセス識別子                                                          */
/*      long flag       指示フラグ（未使用）                                                    */
/*      osepib *pibp    プロセス生成情報ブロック                                                */
/*      osearg *argp    パラメタ構造体                                                          */
/*                                                                                              */
/* ＜返却値＞                                                                                   */
/*		正常終了		プロセス識別子（生成した子プロセスのプロセス識別子）					*/
/*		異常終了		OSEENOFL		プロセス識別子で指定したファイル名がない。				*/
/*						OSEEIPID		プロセス識別子の値が不当である。						*/
/*						OSEEEXST		プロセス識別子で指定したプロセスがすでに存在する。		*/
/*						OSEENEXS		プロセス識別子で指定したプロセステーブルが存在しない。	*/
/*						OSEEWKEX		システム作業域が確保できない。							*/
/*						OSEEILMF		ファイルの形式が異常である。							*/
/*						OSEEACCV		アドレス異常が発生した。								*/
/*						OSEEOPEN		ファイルのオープンに失敗した。							*/
/*						OSEEFAIL		子プロセスが初期化中に異常終了した。					*/
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞                                                                         */
/* ＜制限事項＞                                                                                 */
/*     特になし                                                                                 */
/* ＜使用外部モジュールＩＤ＞                                                                   */
/* ＜呼出元のモジュールＩＤ＞                                                                   */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
/*****	故障管理番号TBCS0231の対応		Start							修正日：2003.07.28	*****/
#include <sys/time.h>
#include <sys/resource.h>
/*****	故障管理番号TBCS0231の対応		 End							修正日：2003.07.28	*****/

/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "oscrepr.h"
#include "oscrepr_ins.h"				/* 内部参照用 */

/*****************************************************************************/
/* 機能：プロセスの作成 　　　                                               */
/* 作成日：2002年9月27日                                                     */
/* 変更日：　　年　月　日                                                    */
/* 作成者：高瀬                                                              */
/* 呼出形式：                                                                */
/*   long oscrepr( char *fn , long pid , long flag ,　　　　　　　　　　　　 */
/*                 osepib *pibp , osearg *argp )                             */
/*       char *fn         プログラムファイル名　　　　　　　　     　　　　　*/
/*       long pid 　　　　プロセス識別子 　　                                */
/*       long flag 　　　 指示フラグ（未使用）  　　　　　　　　　　　　　　 */
/*       osepib *pibp 　　プロセス生成情報ブロック                           */
/*       osearg *argp 　　パラメタ構造体                                     */
/*                                                                           */
/*****************************************************************************/
long oscrepr( char *fn , long pid , long flag , osepib *pibp , osearg *argp )
{
/****************************************************************************/
/*	変数定義																*/
/****************************************************************************/
    struct stat iiStat;                     /* ファイル情報域 */
    int iRet;                               /* 関数結果返却 */
    int iPno;                               /* 関数結果返却 */
    TEprcTableInd  *ptmoaAdr;
    TEprcTableInd  *ptprcAdr;
                                            /* プロセス管理テーブル個別部のアドレス */
    long lMaxFileNum;                       /* ファイル記述子最大 個数              */
    long lLogicSpace;                       /* 論理空間のサイズ                     */
    long lTimeSlice;                        /* タイムスライス値                     */
    long lReqIdMax;                         /* リクエスト識別子最 大個数            */
    long lPPriority;                        /* 起動時プロセス優先度                 */

    char *pacArgc[256];
    long lCnt = 0;
    /****************************************/
	void func();
	struct sigaction new, old;
	
/****************************************************************************/
/*	初期処理																*/
/****************************************************************************/
    new.sa_handler = func;
    new.sa_flags = SA_NOMASK ;
//	sigaction(SIGUSR1,&new,&old);
	/****************************************/
	os_trcget2( D_MD_OSCREPR, D_T_TRA_IN, 5, fn , pid , flag , pibp , argp );

       DbgMsg01( DLv02, ( OutPut, "***** oscrepr START ptEprc=%x\n",ptEprc) );
    ptmoaAdr = (TEprcTableInd *)(ptEprc + 1) ;
    ptprcAdr = ptmoaAdr;
	/* 引数チェック */
    iRet = strlen(fn);
    if (iRet == 0) {
       DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 01:%d\n",iRet) );
       
	   os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEENOFL );
       
       return(OSEENOFL);               /*　ファイルなし　　　　　*/
    }

	
	if( NULL == argp)							//パラメタ構造体アドレスチェック
	{
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Par Err argp\n"));
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEACCV );
		
		return(OSEEACCV);
	}

	/****************************************/
	/*	引数領域の取得						*/
	/****************************************/
	for(lCnt = 0; lCnt < argp->argc; lCnt++)
	{
		pacArgc[lCnt] = argp->argv[lCnt];
	}
	
	pacArgc[lCnt] = NULL;
	
	argp->argv = pacArgc;
	
	/****************************************/
	/*	ファイルの存在チェック				*/
	/****************************************/
	os_trcget2( D_MD_OSCREPR, D_T_SYS_STAT, 2, fn, &iiStat );
	
    iRet =  stat(fn, &iiStat);
    
    os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
    
    if (iRet == D_ERR_SYS)
    {
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 02:%d\n",iRet) );
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENOFL );
		
		return(OSEENOFL);               /*　ファイルなし　　　　　*/
    }

	/****************************************/
	/*	プロセスIDのチェック				*/
	/****************************************/
    if (((pid & 0x00ff0000) != 0x00010000) 
                     && (pid  != 0x00000000))
    {
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 03:%d\n",iRet) );
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEIPID );
		
		return(OSEEIPID);               /*　pidが不当　　　　　　　*/
    }
    iPno = os_GstPrSep(1,pid & 0x00ffffff);
					/* プロセス管理テーブル検索　キー：プロセス識別子  */
    DbgMsg01( DLv02, ( OutPut, "***** oscrepr IPNO=%d\n",iPno) );
    if(NORMAL > iPno)
    {
        DbgMsg01( DLv05, ( OutPut, "***** GetPR Err01:%d\n", iPno ) );
            
        os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEIPID );
            
	    return(OSEEIPID);               /*　pidが不当　　　　　　　*/
            //*     異常処理
    }

	/****************************************/
	/*	プロセスの存在チェック				*/
	/****************************************/
    ptprcAdr +=  iPno;
    if (ptprcAdr->lPid != 0x0) {
		DbgMsg01( DLv05, ( OutPut, "***** GetPR Err02:%d\n", iPno ) );
		
        os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEEXST );
		
		return(OSEEEXST);       /*　プロセス既に存在　　　*/
    }

/****************************************************************************/
/*	本処理																	*/
/****************************************************************************/
	/************************************************/
	/*	SGの読み込み								*/
	/************************************************/
	// プロセス情報退避
    os_startSG();
    //iRet = os_getSG(D_SG_MOA_FILE_ID_MAX,&lMaxFileNum);     // ファイル記述子最大個数読み込み
    iRet = os_getSG(D_SG_EFLC_NUM,&lMaxFileNum);		// 20030306 修正
    if(NORMAL != iRet)								// 返却値が異常の場合
    {
/*****	故障管理番号TBCS0233の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	返却値（OSERRSG） → 返却値（OSEENEXS） に変更												*/
/************************************************************************************************/
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// 異常終了
    }
    //iRet = os_getSG(D_SG_MOA_LOGI_SIZE,&lLogicSpace);       // 論理空間のサイズ読み込み
    iRet = os_getSG( D_SG_LOGI_SIZE,&lLogicSpace);							// 20030306 修正
    if(NORMAL != iRet)								// 返却値が異常の場合
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// 異常終了
    }
    //iRet = os_getSG(D_SG_MOA_TIME_SLI,&lTimeSlice); // タイムスライス値読み込み
    iRet = os_getSG( D_SG_TIME_SLI,&lTimeSlice);				// 20030306 修正
    if(NORMAL != iRet)								// 返却値が異常の場合
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// 異常終了
    }
    //iRet = os_getSG(D_SG_MOA_REQ_MAX,&lReqIdMax);   // リクエスト識別子最大個数読み込み
    iRet = os_getSG(D_SG_ERDC_NUM,&lReqIdMax);				// 20030306 修正
    if(NORMAL != iRet)								// 返却値が異常の場合
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// 異常終了
/*****	故障管理番号TBCS0233の対応		 End							修正日：2003.07.28	*****/
    }
       DbgMsg01( DLv02, ( OutPut, "***** oscrepr SGEND\n") );

	/************************************************/
	/*	プロセス情報の退避							*/
	/************************************************/
    if (pibp == 0x0) {
            ptprcAdr->lLank = ptmoaAdr->lLank;
            ptprcAdr->lUid = ptmoaAdr->lUid;
            ptprcAdr->lMaxFileNum = ptmoaAdr->lMaxFileNum;
            ptprcAdr->lPAttr = ptmoaAdr->lPAttr;
            ptprcAdr->lAccess = ptmoaAdr->lAccess;
            ptprcAdr->lPPriority = ptmoaAdr->lPPriority;
            ptprcAdr->lModifPriority = ptmoaAdr->lModifPriority  ;
            ptprcAdr->lLogSpaceSize = ptmoaAdr->lLogSpaceSize;
            ptprcAdr->lTimeSlice = ptmoaAdr->lTimeSlice;
            ptprcAdr->lMaxReqNum = ptmoaAdr->lMaxReqNum;
    }
    else
    {
//		strcpy(ptprcAdr->acPName,pibp->pname) ;		// 20021218修正
		strncpy(ptprcAdr->acPName,pibp->pname, 8) ;
		
        if (pibp->rank == -1)						// ランク設定
        {
            ptprcAdr->lLank = ptmoaAdr->lLank ;
        }
        else
        {
            ptprcAdr->lLank = pibp->rank;
        }
        
        if (pibp->uic == -1)						// ユーザ識別コード
        {
            ptprcAdr->lUid = ptmoaAdr->lUid;
        }
        else
        {
            ptprcAdr->lUid = pibp->uic ;
        }
        
        //if (pibp->fdno == -1)						// ファイル記述子最大個数
        if (pibp->fdno <= 0)
        {
            //ptprcAdr->lMaxFileNum = ptmoaAdr->lMaxFileNum;	// 20030306 修正
            ptprcAdr->lMaxFileNum = lMaxFileNum;
        }
        else
        {
            ptprcAdr->lMaxFileNum = pibp->fdno ;
        }
        
        if (pibp->atr == -1)						// プロセス属性
        {
            ptprcAdr->lPAttr = ptmoaAdr->lPAttr  ;
        }
        else
        {
            ptprcAdr->lPAttr = pibp->atr ;
        }
        
        if (pibp->acc == -1)						// アクセス権
        {
            ptprcAdr->lAccess = ptmoaAdr->lAccess;
        }
        else
        {
            ptprcAdr->lAccess = pibp->acc ;
        }

        if (pibp->pri == -22)						// 起動時プロセス優先度
        {
            ptprcAdr->lPPriority = ptmoaAdr->lPPriority;
        }        
        else
        {
            ptprcAdr->lPPriority = pibp->pri ;
        }
        
        if (pibp->hpri == -1)					// 変更上限プロセス優先度
        {
            ptprcAdr->lModifPriority = ptmoaAdr->lModifPriority  ;
        }
        else
        {
            ptprcAdr->lModifPriority = pibp->hpri ;
        }
        
        if (pibp->spclass == -1)						// 論理空間のサイズ
        {
            //ptprcAdr->lLogSpaceSize = ptmoaAdr->lLogSpaceSize;
            ptprcAdr->lLogSpaceSize = lLogicSpace;		// 20030306 修正
        }
        else
        {
            ptprcAdr->lLogSpaceSize = pibp->spclass;
        }
        
        if ( (pibp->tabort == 0) || (pibp->tabort == -1) )	// タイムスライス値
        {
            //ptprcAdr->lTimeSlice = ptmoaAdr->lTimeSlice;
            ptprcAdr->lTimeSlice = lTimeSlice;	// 20030306 修正
        }
        else 
        {
            ptprcAdr->lTimeSlice = pibp->tabort ;
        }
        
        //if (pibp->rdno == -1)						// リクエスト識別子最大個数
        if (pibp->rdno <= 0)
        {
            //ptprcAdr->lMaxReqNum = ptmoaAdr->lMaxReqNum;
            ptprcAdr->lMaxReqNum = lReqIdMax;	// 20030306 修正
        }
        else
        {
            ptprcAdr->lMaxReqNum = pibp->rdno ;
        }
    }
    ptprcAdr->lEndCode = D_END_CODE1;
    ptprcAdr->lDetailCode = 0;
    memset( &(ptprcAdr->func[0]), -1, 32 * sizeof(long) );
	/* 子プロセス生成　*/

	ptprcAdr->cLaunchFlg = 'W';  	/* 立上げ状態  立上中  */
	
	sigaction(SIGUSR1,&new,&old);

	os_trcget2( D_MD_OSCREPR, D_T_SYS_FORK, 0 );
	
	iRet =	fork();
	
//	os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, iRet );
	
	if (iRet == D_ERR_SYS)
	{
		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, OSEEWKEX );
		
		return(OSEEWKEX);				/*　作業域不足　　　　　*/
	}
	/* プロセス生成　*/
	DbgMsg01( DLv02, ( OutPut, "***** oscrepr FORK :%d\n",iRet) );
	DbgMsg01( DLv02, ( OutPut, "***** oscrepr FORK2 :%x\n",ptprcAdr) );

	if (iRet == 0)
	{	
	
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_GETPID, 0 );	

			/*　子プロセス			   */
		/********************************************/
		/*	プロセスIDの取得						*/
		/********************************************/
		iRet = getpid();
		
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
		
		ptEsys->tMyPrcInfo.lMyPid = iRet;
		ptprcAdr->lPid = iRet;
		DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC1 :%d\n",iRet) );

		/********************************************/
		/*	プライオリティの設定					*/
		/********************************************/
		if(NULL == pibp)
		{
			lPPriority = ptprcAdr->lPPriority;
		}
		else
		{
/*****	故障管理番号TBCS0231の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	hpri → pri に変更																			*/
/************************************************************************************************/
			lPPriority = pibp->pri;					// 起動時プロセス優先度を設定
/*****	故障管理番号TBCS0231の対応		 End							修正日：2003.07.28	*****/
		}
		if ( lPPriority != -22 )
		{
/*****	故障管理番号TBCS0231の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	nice → setpriority に変更																	*/
/************************************************************************************************/
			errno = 0;								// errno クリア

			os_trcget2( D_MD_OSCREPR, D_T_SYS_SETPRIORITY, 3,
						PRIO_PROCESS, ptprcAdr->lPid, lPPriority );
													// プロセスのスケジューリングの優先度を設定
			iRet = setpriority(PRIO_PROCESS, ptprcAdr->lPid, lPPriority);
			os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 2, iRet, errno );

			DbgMsg01( DLv04, ( OutPut, "***** oscrepr lPPriority=%ld\n", lPPriority) );
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr setpriority() iRet=%d, errno=%d\n",
					iRet, errno) );
/*****	故障管理番号TBCS0231の対応		 End							修正日：2003.07.28	*****/
		}

		/********************************************/
		/*	プロセスの生成							*/
		/********************************************/
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : fn   :%s\n", fn ) );	
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : argv :%p\n", argp->argv ) );	
		for(lCnt = 0; lCnt < (argp->argc);lCnt++)
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : argv :%s\n", *(argp->argv+lCnt) ));	
		}

//		os_trcget2( D_MD_OSCREPR, D_T_SYS_EXECVP, 2, fn, argp->argv );	

		iRet = execvp(fn, argp->argv);
		
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
		
		DbgMsg01( DLv04, ( OutPut, "*****  Err Mess:%s\n", strerror(errno)) );
		if (iRet == D_ERR_SYS)
		{
			DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC3 :%d\n",iRet) );
			DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC3 errno :%s\n",strerror(errno) ) );
			ptprcAdr->cLaunchFlg = 'E';  	/* 立上げ状態　異常　 */
/*****	故障管理番号TBCS0232の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	execvpの返却値 → errno に変更																*/
/************************************************************************************************/
			ptprcAdr->lEndCode = errno;				// errnoを設定
/*****	故障管理番号TBCS0232の対応		 End							修正日：2003.07.28	*****/
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_KILL, 2, getppid(), SIGUSR1 );
		
			iRet = kill(getppid(), SIGUSR1);				// 親プロセスにシグナルを送る
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_EXIT, 0 );
			
			exit(0);
		}
	}
	else
	{ 					/*　親プロセス			   */
		/********************************************/
		/*	プロセスの生成							*/
		/********************************************/
		DbgMsg01( DLv04, ( OutPut, "***** sigsuspend 直前 :\n") );
		
		while( ('W' == ptprcAdr->cLaunchFlg) )
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr sigsuspend\n"));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr A ptprcAdr->cLaunchFlg:%c\n"
					, ptprcAdr->cLaunchFlg ));
			pause();
		}
		
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr C ptprcAdr->cLaunchFlg:%x\n"
					, ptprcAdr->cLaunchFlg ));

		sigaction(SIGUSR1, &old, NULL);
		if('S' == ptprcAdr->cLaunchFlg)
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT NORMAL\n"));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT  :%08lx\n",ptprcAdr->lPCode) );
			os_trcget2( D_MD_OSCREPR, D_T_TRA_OUT, 1, ptprcAdr->lPCode );
			return(ptprcAdr->lPCode);
		}
		else
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT ERROR\n" ));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT  :%08lx\n",ptprcAdr->lPCode) );
/*****	故障管理番号TBCS0232の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	返却値（OSEEILMF） → 異常処理へ遷移するように修正											*/
/************************************************************************************************/
			goto err_oscrepr;						// 異常処理へ
/*****	故障管理番号TBCS0232の対応		 End							修正日：2003.07.28	*****/
		}
	}

err_oscrepr:
	/* 異常処理 */
/*****	故障管理番号TBCS0232の対応		Start							修正日：2003.07.28	*****/
/************************************************************************************************/
/*	errno → ptprcAdr->lEndCode に変更															*/
/************************************************************************************************/
	switch(ptprcAdr->lEndCode) {					// プロセス管理テーブルの終了コードの判定
	case EACCES:
	case ENOEXEC:
	case ELIBBAD:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEILMF, ptprcAdr->lEndCode );
		return (OSEEILMF); 
		break;
	case EFAULT:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEACCV, ptprcAdr->lEndCode );
		return (OSEEACCV);
		break;
	case ENOMEM:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEWKEX, ptprcAdr->lEndCode );	
		return (OSEEWKEX);
		break;
	case ENFILE:
	case EMFILE:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEOPEN, ptprcAdr->lEndCode );	
		return (OSEEOPEN);
		break;
	default:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEFAIL, ptprcAdr->lEndCode );
		return (OSEEFAIL);
	}
/*****	故障管理番号TBCS0232の対応		 End							修正日：2003.07.28	*****/
}


void func()
{
	DbgMsg01( DLv04, ( OutPut, "***** Call func in oscrepr\n") );
}


/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
