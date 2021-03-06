/************************************************************************************************/
/*                                                                                              */
/*  １．ソースファイル名                                                                        */
/*      os_dflact.c                                                                             */
/*                                                                                              */
/*                                                                                              */
/*  ２．プログラム名称                                                                          */
/*      デフォルトシグナルハンドラ                                                              */
/*                                                                                              */
/*                                                                                              */
/*  ３．機能概要                                                                                */
/*      シグナルハンドラの設定（シグナルの無視）を行い、終了処理をする。                        */
/*                                                                                              */
/*                                                                                              */
/*  ４．呼び出し形式                                                                            */
/*      void    os_dflact()                                                                     */
/*                                                                                              */
/*                                                                                              */
/*  ５．引数                                                                                    */
/*      int     sig                                                                             */
/*                                                                                              */
/*                                                                                              */
/*  ６．返却値                                                                                  */
/*      なし                                                                                    */
/*                                                                                              */
/*                                                                                              */
/*  ７．前提事項・特記事項                                                                      */
/*      ＴＲＡＤＥエミュレート内のみ利用可能とする。                                            */
/*      本処理はＴＲＡＤＥプロセス初期化処理にて各シグナルにシグナルハンドラとして登録される。  */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/


/************************************************************************************************/
/*  インクルードファイル                                                                        */
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	"os_dflact_ins.h"


void	os_dflact(sig)
int		sig;										/* シグナル									*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long	lEndCode;								/* 終了コード								*/
	long	lDetail;								/* 詳細情報									*/
//  struct sigaction	tAct;						/* シグナル用								*/
	struct sigaction	atAct[D_MAX_SIG_NUM];		/* シグナル用								*/
	long	lCnt;

	os_trcget2( D_MD_OS_DFLACT, D_T_TRA_IN, 1, sig );
													/* 関数入口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_dflact" ) );

//	DbgMsg01(DLv04, (OutPut, "***** %s:sig = %d \n", "os_dflact", sig));


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lEndCode = 0;									/* 終了コード クリア						*/
	lDetail = 0;									/* 詳細情報   クリア						*/
	//errno = 0;									/* errno      クリア						*/
	lCnt	= 0;


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/****************************************/
	/*  シグナルハンドラの設定				*/
	/*  （シグナル無視）					*/
	/****************************************/
													/* 20030228 修正							*/
	//tAct.sa_handler = SIG_IGN;					/* シグナルハンドラの設定					*/
	//tAct.sa_flags = 0;							/* シグナルフラグの設定						*/
	//sigaction(sig, &tAct, NULL);					/* シグナルの操作							*/
	
													// 20030228 追加
	for(lCnt = 0; lCnt < D_MAX_SIG_NUM; lCnt++)
	{
		atAct[lCnt].sa_handler = SIG_IGN;			// シグナルハンドラの設定
		atAct[lCnt].sa_flags = 0;					// シグナルフラグの設定
		sigaction(lCnt + 1, &atAct[lCnt], NULL);	// シグナルの操作
	}

	/****************************************/
	/*  終了コード、詳細情報の作成			*/
	/****************************************/
	lEndCode = D_END_CODE2 & (0xffffff00 | sig);	/* 終了コードを設定							*/
													/* （シグナル番号でマスク）					*/

	lDetail = D_DETAIL_NON;							/* 詳細情報を設定（未使用）					*/

	DbgMsg01(DLv04, (OutPut, "***** %s:lEndCode = %08lx \n", "os_dflact", lEndCode));


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
	/****************************************/
	/*  プロセス終了手続き					*/
	/****************************************/
	os_abort(lEndCode, lDetail, 1);					/* アボート関数								*/


													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_dflact" ) );
	os_trcget2( D_MD_OS_DFLACT, D_T_TRA_OUT, 0 );
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
