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
/* ＜サービス項目名＞				 メッセージ通信												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 メッセージの受信要求										*/
/* ＜モジュールＩＤ＞				 osrcvmsr													*/
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
/* 作成日：2002年10月04日                                                    */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 メッセージの受信の要求 																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osrcvmsr.h>																*/
/*																								*/
/*	   	long	osrcvmsr( long mpid, long rd, long size, char *bufa ) 							*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	mpid;		メイルボックス又はプロセス識別子									*/
/*		long	rd;			リクエスト識別子(1以上)												*/
/*		long	size;		メッセージ長制限値(1〜8192)											*/
/*		char	*bufa;		メッセージ受信バッファ												*/
/*																								*/
/* ＜返却値＞																					*/
/*	   	正常終了		リクエスト識別子														*/
/*		異常終了		os_GetEmbcTableIndの返却値												*/
/*						OSEEISIZ					サイズが範囲外								*/
/*						OSEEOVRQ					rd管理テーブルに未予約かつ未使用の			*/
/*													個別部が存在しない							*/
/*						OSEEIVRD					当該個別部の予約状態が予約済でない			*/
/*						OSEEUSED					当該個別部の非完了要求状態が要求済みでない	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   特になし 																				*/
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

/* 利用者作成ヘッダファイル */

/* 定数定義 */

/* 外部変数宣言 */
#include "osrcvmsr.h"
#include "osrcvmsr_ins.h"

/* 外部関数宣言 */

/* 内部関数宣言 */

/* static変数の宣言 */

/*****************************************************************************/
/* 機能：メッセージの受信の要求                                              */
/* 作成日：2002年10月04日                                                    */
/* 変更日：　　年　月　日                                                    */
/* 作成者：                                                                  */
/* 呼出形式：                                                                */
/*   long osrcvmsr( long mpid, long rd, long size, char *bufa )              */
/*       long mpid        メイルボックス又はプロセス識別子                   */
/*       long rd          リクエスト識別子(1以上)                            */
/*       long size        メッセージ長制限値(1〜8192)                        */
/*       char *bufa       メッセージ受信バッファ                             */
/*****************************************************************************/
long osrcvmsr( long mpid, long rd, long size, char *bufa )
{
	long	lLoopCnt;								/* ループカウンタ							*/
	long	lAsso;									/* 種別										*/
	long	lRet;									/* 関数結果返却								*/
	long	*plWorkPtr = NULL;						/* ワークポインター							*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* メイルボックス情報個別部のアドレス		*/
	TErdcTableInd	*ptErdcInd = NULL;				/* rd管理情報個別部のアドレス				*/

	
	os_trcget2( D_MD_OSRCVMSR, D_T_TRA_IN, 4, mpid, rd, size, bufa );
	
													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvmsr" ) );

/************************************************************************************************/
/*  初期処理																					*/
/************************************************************************************************/
	lLoopCnt = 0;
	lAsso    = 0;
	lRet     = 0;
	errno    = 0;


	DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx \n", "osrcvmsr", mpid));
	DbgMsg01(DLv04, (OutPut, "***** %s:rd  =%ld \n", "osrcvmsr", rd));
	DbgMsg01(DLv04, (OutPut, "***** %s:size=%ld \n", "osrcvmsr", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:bufa=%08lx \n\n", "osrcvmsr", (long)bufa));


													/* rd管理情報個別部先頭アドレスを求め設定	*/
//	ptErdcInd = (TErdcTableInd *)ptErdc + sizeof( TErdcTable );
	ptErdcInd = (TErdcTableInd *)(ptErdc + 1);

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd=%08lx \n", "osrcvmsr", (long)ptErdcInd));


	/****************************************/
	/* 識別子(引数mpid)のチェック			*/
	/****************************************/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );
	if( lRet != NORMAL )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  lRet=%08lx \n", "osrcvmsr",
				"処理異常!!", "指定したメイルボックスが存在しない。又は削除された。", lRet));

		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, lRet );	

		return( lRet );
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvmsr", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvmsr", ptEmbc->lMaxMsgLng));

	/****************************************/
	/* メッセージ制限長(引数size)のチェック */
	/****************************************/
	if( size < D_MSGSIZE_MIN || size > ptEmbc->lMaxMsgLng )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  size=%ld \n", "osrcvmsr",
				"処理異常!!", "メッセージ長制限値が不当である。", size));
				
		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEISIZ );			

		return( OSEEISIZ );							/* サイズに範囲外の値が設定されている */
	}

	/****************************************/
	/* リクエスト識別子チェック				*/
	/****************************************/
	if( rd == 0 )									/* リクエスト識別子(引数:rd)が「0」の場合	*/
	{
													/* rd管理テーブル個別部の先頭から			*/
													/* リクエスト状態が「未予約」かつ「未使用」	*/
													/* かつ「未要求」の個別部を検索する			*/
//2003.02.19		for( lLoopCnt = 1; lLoopCnt <= ptErdc->lMaxIndNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptMyEPRC->lMaxReqNum; lLoopCnt++ )
		{
//			if( ptErdcInd->tReqStat.cResStat == D_ERDC_RESSTAT_NONE &&
//				ptErdcInd->tReqStat.cUseStat == D_ERDC_USESTAT_NONE )
													/* リクエスト状態が							*/
													/* 未予約かつ未使用かつ未要求の場合			*/
			if( D_ERDC_RESSTAT_NONE == ptErdcInd->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptErdcInd->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptErdcInd->tReqStat.cUCompStat )
			{
				break;
			}
			ptErdcInd++;							/* 次の個別部のアドレスを設定する			*/
		}
//2003.02.19		if( lLoopCnt > ptErdc->lMaxIndNum )
		if( lLoopCnt > ptMyEPRC->lMaxReqNum )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "非完了処理要求の数が多すぎる。"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEOVRQ );		

			return( OSEEOVRQ );						/* 該当する個別部が存在しない				*/
		}
	}
	else
	{
													/* 引数のリクエスト識別子と同じ				*/
													/* リクエスト識別子を持つ個別を検索する		*/
//2003.02.19		for( lLoopCnt = 1; lLoopCnt <= ptErdc->lMaxIndNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptMyEPRC->lMaxReqNum; lLoopCnt++ )
		{
			if( rd == ptErdcInd->lRCode )
			{
				break;
			}
			ptErdcInd++;							/* 次の個別部のアドレスを設定する			*/
		}

//2003.02.19		if( lLoopCnt > ptErdc->lMaxIndNum )			/* rd管理テーブルにrdと同じリクエスト識別子 */
		if( lLoopCnt > ptMyEPRC->lMaxReqNum )			/* rd管理テーブルにrdと同じリクエスト識別子 */
		{											/* を持った個別部が存在しない				*/
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "非完了処理要求の数が多すぎる。"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEOVRQ );		

			return( OSEEOVRQ );
		}
		if( ptErdcInd->tReqStat.cResStat != D_ERDC_RESSTAT_RES )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "指定ｒｄは予約されていない。又は不当な値である。"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEIVRD );		

			return( OSEEIVRD );						/* 当該個別部の予約状態が予約済でない		*/
		}
		if( ptErdcInd->tReqStat.cUCompStat != D_ERDC_UCOMPSTAT_NONE )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "指定ｒｄは非完了要求済である。又は不当な値である。"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEUSED );		

			return( OSEEUSED );						/* 当該個別部の非完了要求状態が未要求でない */
		}
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lLoopCnt =%ld \n", "osrcvmsr", lLoopCnt));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd=%08lx \n", "osrcvmsr", (long)ptErdcInd));


/************************************************************************************************/
/*  本処理																						*/
/************************************************************************************************/
	/********************************************/
	/*  rd管理テーブル管理部の					*/
	/*  プロセス間メッセージ要求フラグの編集	*/
	/********************************************/
	lAsso = os_GetAsso( mpid );						/* 種別の取得								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvmsr", lAsso));

													/* 種別が「1」の場合、又は					*/
													/* 第一パラメータが「0」の場合				*/
//	if( lAsso == D_ASSO_PROCESS )
	if((D_ASSO_PROCESS == lAsso) || (0 == mpid))
	{												/* プロセス宛プールバッファ無し				*/
													/* メッセージ受信要求						*/
		ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_ON;

		DbgMsg01(DLv04, (OutPut, "\n***** %s:%s\n", "osrcvmsr",
				"メッセージの受信要求（プロセス宛）"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOff=%02x \n", "osrcvmsr",
				ptErdc->tMsgFlg.cPrcPbOff));
	}
	else
	{												/* メイルボックス宛プールバッファ無し		*/
													/* メッセージ受信要求						*/
		ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_ON;

		DbgMsg01(DLv04, (OutPut, "***** %s:%s\n", "osrcvmsr",
				"メッセージの受信要求（メイルボックス宛）"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOff=%02x \n", "osrcvmsr",
				ptErdc->tMsgFlg.cMbPbOff));
	}

	/********************************************/
	/*  rd管理テーブル個別部編集				*/
	/********************************************/
													/* リクエスト状態（非完了要求状態）			*/
													/* を要求済に設定							*/
	ptErdcInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->tReqStat.cUCompStat=%02x \n", "osrcvmsr",
			ptErdcInd->tReqStat.cUCompStat));

													/* 種別が「1」の場合、又は					*/
													/* 第一パラメータが「0」の場合				*/
//	if( lAsso == D_ASSO_PROCESS )
	if(( D_ASSO_PROCESS == lAsso ) || ( 0 == mpid ))
	{												/* 種別が1(プロセス識別子)の場合			*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_PRC_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS06;	/* メッセージの受信要求（プロセス宛）		*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmsr",
				ptErdcInd->cReqClass));
	}
	else
	{												/* 種別が2(メイルボックス識別子)の場合		*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_MB_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS05;	/* メッセージの受信要求（メイルボックス宛） */

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmsr",
				ptErdcInd->cReqClass));
	}
	
	os_trcget2( D_MD_OSRCVMSR,  D_T_SYS_MALLOC, 1, 4 );

	plWorkPtr = malloc(4);							/* メモリ獲得（4バイト）					*/
	
	os_trcget2( D_MD_OSRCVMSR,  D_T_SYS_END, 1, plWorkPtr );
	
	if (NULL == plWorkPtr)							/* 取得したポインタがNULLの場合				*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
				"osrcvmsr", "malloc() Call Error!!", errno, strerror(errno)));
		
		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_SYS, 1, OSEEWKEX );		
				
		return(OSEEWKEX);							/* 異常終了（sys work area exhaust）		*/
	} 

	ptErdcInd->lReqNum = 0;
//	ptErdcInd->pvArg1 = &size;
	*plWorkPtr = size;
	ptErdcInd->pvArg1 = plWorkPtr;
	ptErdcInd->pvArg2 = bufa;

//	DbgMsg01(DLv04, (OutPut, "***** %s:size=%08lx, size=%ld \n", "osrcvmsr",
//			&size, size));
//	DbgMsg01(DLv04, (OutPut, "***** %s:plWorkPtr=%08lx, plWorkPtr=%ld \n", "osrcvmsr",
//			plWorkPtr, *plWorkPtr));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->pvArg1=%ld \n", "osrcvmsr",
			*(long *)ptErdcInd->pvArg1));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->pvArg2=%08lx \n", "osrcvmsr",
			ptErdcInd->pvArg2));


/************************************************************************************************/
/*  終了処理																					*/
/************************************************************************************************/
													/* 関数出口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsr" ) );
	
	os_trcget2( D_MD_OSRCVMSR, D_T_TRA_OUT, 1, ptErdcInd->lRCode );
	
	return( ptErdcInd->lRCode );
}
/************************************************************************************************/
/*  End																							*/
/************************************************************************************************/
