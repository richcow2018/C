/************************************************************************************************/
/* ＜呼出形式＞                                                                                 */
/*      #include    "os_tretrm.h"                                                               */
/*                                                                                              */
/*      void    os_treterm(long lEndCod, long lDetailCode)                                      */
/*                                                                                              */
/* ＜仮引数＞                                                                                   */
/*      long lEndCod：終了コード                                                                */
/*      long lDetailCode：詳細情報                                                              */
/*                                                                                              */
/* ＜返却値＞                                                                                   */
/*      無し                                                                                    */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/*                                                                                              */
/* ＜制限事項＞                                                                                 */
/*  TRADE内部での明示的な異常終了時使用                                                         */
/************************************************************************************************/
#include "os_treterm.h"
#include "os_treterm_ins.h"

void os_treterm(long lEndCod, long lDetailCode)
{
	/******************/
	/*    変数定義    */
	/******************/
	long lRes = 0;
	
	os_trcget2( D_MD_OS_TRETERM, D_T_TRA_IN, 2, lEndCod, lDetailCode );
	/* 引数チェック */
	
	if(ptMyEPRC == NULL)
	{
		os_trcget2( D_MD_OS_TRETERM, D_T_ERR_PRA, 0 );
		os_abort(lEndCod, lDetailCode, 1);		//coreファイルを取得する
	}
	
	/******************/
	/*     本処理     */
	/******************/
	// 自プロセステーブル 「詳細情報」、「終了コード」へ引数の値を格納
	
	ptMyEPRC->lEndCode = lEndCod;				// 終了コード格納
	ptMyEPRC->lDetailCode = lDetailCode;		// 詳細情報格納

	os_trcget2( D_MD_OS_TRETERM, D_T_SYS_KILL, 2, lMyPid, SIGTERM);
	lRes = kill(lMyPid, SIGTERM);				// シグナル kill(自pid, SIGTERM); 発行
	if(NORMAL != lRes)
	{
		os_trcget2( D_MD_OS_TRETERM, D_T_ERR_SYS, 1, errno);
		os_sigact(SIGTERM);						// kill出来ないなら直呼び
	}
	
	/******************/
	/*    終了処理    */
	/******************/
	os_trcget2( D_MD_OS_TRETERM, D_T_TRA_OUT, 0);
	do
	{
		lRes = pause();							// 無限処理待ち合わせ
	}while(1);

}

/************************************************************************************************/
/* 終了                                                                                         */
/************************************************************************************************/
