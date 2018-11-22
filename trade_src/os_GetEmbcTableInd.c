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
/* ＜モジュールＩＤ＞				 os_GetEmbcTableInd											*/
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
/* 作成日：2002年10月04日                                                                       */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 第一引数を元に、合致するプロセス管理テーブル個別部とメイルボックス管理テーブル個別部		*/
/*	 先頭アドレスを検索し、該当した個別部の先頭アドレスを求め返却する							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_GetEmbcTableInd.h>														*/
/*															                                    */
/*	   	long	os_GetEmbcTableInd(long mpid,TMbcTableInd **ppEmbcInd)							*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long				mpid;		 	0又はメイルボックス識別子又はプロセスの識別子		*/
/*		TMbcTableInd		**ppEmbcInd;	メイルボックステーブル個別部のアドレス  			*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			NORMAL																*/
/*		異常終了			OSEENEXS		プロセス管理テーブルに自プロセス未登録				*/
/*							OSEEIMPI		種別が範囲外										*/
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


/* 利用者作正ヘッダファイル */
#include "os_GetEmbcTableInd_ins.h"


/* 定数定義 */


/* 外部変数宣言 */


/* 外部関数宣言 */


/* 内部関数宣言 */


/* static変数の宣言 */


/************************************************************************************************/
/*                                                                                              */
/* 機能：第一引数を元に、合致するプロセス管理テーブル個別部と                                   */
/*       メイルボックス管理テーブル個別部先頭アドレスを検索し、                                 */
/*       該当した個別部の先頭アドレスを求め返却する                                             */
/*                                                                                              */
/* 作成日：2002年10月04日                                                                       */
/*                                                                                              */
/* 変更日：　　年　月　日                                                                       */
/*                                                                                              */
/* 作成者：                                                                                     */
/*                                                                                              */
/* 呼出形式：                                                                                   */
/*   long os_GetEmbcTableInd( long          mpid,                                               */
/*                            TEmbcTableInd **pptEmbcInd )                                      */
/*                                                                                              */
/*                                                                                              */
/*   long mpid                  0又はメイルボックス識別子又はプロセスの識別子                   */
/*   TEmbcTableInd **pptEmbcInd メイルボックステーブル個別部のアドレス                          */
/*                                                                                              */
/************************************************************************************************/

long os_GetEmbcTableInd( long mpid, TEmbcTableInd **pptEmbcInd )
{
	long	lLoopCnt;								/* ループカウンタ							*/
	long	lAsso;									/* 種別										*/
	long	lSequenceNumber;						/* 通番										*/
	TEprcTableInd	*ptEprcInd;						/* プロセス管理テーブル個別部のアドレス		*/
	TEmbcTableInd	*ptEmbcInd;


													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_GetEmbcTableInd" ) );


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	ptEprcInd   = (TEprcTableInd *)(ptEprc + 1 );	/* プロセス管理個別部の先頭アドレス設定		*/
	*pptEmbcInd = (TEmbcTableInd *)(ptEmbc + 1 );	/* メイルボックス管理個別部先頭アドレス設定 */

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd =%08lx \n", "os_GetEmbcTableInd",
			(long)ptEprcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:pptEmbcInd=%08lx \n", "os_GetEmbcTableInd",
			*pptEmbcInd));

													/* メイルボックス識別子又は					*/
													/* プロセス識別子の妥当性のチェック			*/
	if( mpid == D_MPID_MYPROCESS )					/* 引数mpidに識別子が設定されていない場合	*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%d \n", "os_GetEmbcTableInd", mpid));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
				ptEprc->lIndPartNum));

													/* 合致するプロセス管理テーブル個別部の検索 */
		for( lLoopCnt = 1; lLoopCnt <= ptEprc->lIndPartNum ; lLoopCnt++ )
		{
//			DbgMsg01(DLv04, (OutPut, "***** %s:Roop1[%ld] \n", "os_GetEmbcTableInd", lLoopCnt));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd=%08lx \n", "os_GetEmbcTableInd",
//					(long)ptEprcInd));
//			DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid=%08lx, ptEprcInd->lPid=%08lx \n",
//					"os_GetEmbcTableInd", lMyPid, ptEprcInd->lPid));

			if( lMyPid == ptEprcInd->lPid )			/* lMyPidはglobal変数						*/
			{
				break;								/* ループを抜ける							*/
			}

//			*ptEprcInd++;							/* 次の個別部のアドレスを設定する */
			ptEprcInd++;							/* 次の個別部のアドレスを設定する			*/
		}

		DbgMsg01(DLv04, (OutPut, "\n***** %s:----- Check 1 ----- \n", "os_GetEmbcTableInd"));

		if( lLoopCnt > ptEprc->lIndPartNum )
		{
													/* プロセス管理テーブルに					*/
													/* 自プロセスIDが登録された個別部が無い		*/
			return( OSEENEXS );
		}

		DbgMsg01(DLv04, (OutPut, "***** %s:Roop1[%ld] \n", "os_GetEmbcTableInd", lLoopCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid=%08lx, ptEprcInd->lPid=%08lx \n",
				"os_GetEmbcTableInd", lMyPid, ptEprcInd->lPid));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
				ptEmbc->lIndPartNum));

													/* メイルボックス管理テーブル個別部の検索 	*/
//		for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
		{
//			DbgMsg01(DLv04, (OutPut, "***** %s:Roop2[%ld] \n", "os_GetEmbcTableInd",
//					lLoopCnt));

			ptEmbcInd = *pptEmbcInd;

//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//					(long)ptEmbcInd));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
//					ptEprcInd->lPCode));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
//					ptEmbcInd->lPCode));

													/* プロセス管理テーブルのプロセス識別子と	*/
													/* メールボックス管理テーブルの				*/
													/* プロセス識別子が一致する場合				*/
//			if( ptEprcInd->lPid == ptEmbcInd->lPCode )
			if( ptEprcInd->lPCode == ptEmbcInd->lPCode )
			{
				break;
			}

//			*pptEmbcInd++;							/* 次の個別部のアドレスを設定する			*/
			(*pptEmbcInd)++;						/* 次の個別部のアドレスを設定する			*/
		}

		if( lLoopCnt > ptEmbc->lIndPartNum )
		{
													/* 指定のプロセス識別子が登録された			*/
													/* 個別部が存在しない						*/
			return( OSEENEXS );
		}

		DbgMsg01(DLv04, (OutPut, "***** %s:Roop2[%ld] \n", "os_GetEmbcTableInd",
				lLoopCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
				(long)ptEmbcInd));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
				ptEprcInd->lPCode));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
				ptEmbcInd->lPCode));
	}
	else
	{
		DbgMsg01(DLv04, (OutPut, "\n***** %s:----- Check 2 ----- \n", "os_GetEmbcTableInd"));

		lAsso = os_GetAsso( mpid );					/* 第１引数から種別を取得する				*/
		DbgMsg01(DLv04, (OutPut, "***** %s:lAsso=%ld \n", "os_GetEmbcTableInd", lAsso));

		lSequenceNumber = os_GetSerNum( mpid );		/* 第１引数から通番を取得する				*/
		DbgMsg01(DLv04, (OutPut, "***** %s:lSequenceNumber=%ld \n", "os_GetEmbcTableInd",
				lSequenceNumber));

		if( lAsso == D_ASSO_PROCESS )				/* 種別が1(プロセス識別子)の場合			*/
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
					ptEmbc->lIndPartNum));
													/* メイルボックス管理テーブル個別部の検索	*/
//			for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
			for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
			{
//				DbgMsg01(DLv04, (OutPut, "***** %s:Roop3[%ld] \n", "os_GetEmbcTableInd",
//						lLoopCnt));

				ptEmbcInd = *pptEmbcInd;

//				DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//						(long)ptEmbcInd));
//				DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lPCode=%08lx \n",
//						"os_GetEmbcTableInd", mpid, ptEmbcInd->lPCode));

				if( mpid == ptEmbcInd->lPCode )
				{
					break;
				}

//				*pptEmbcInd++;						/* 次の個別部のアドレスを設定する			*/
				(*pptEmbcInd)++;					/* 次の個別部のアドレスを設定する			*/
			}

			if( lLoopCnt > ptEmbc->lIndPartNum )
			{
													/* 指定のプロセス識別子が登録された			*/
													/* 個別部が存在しない						*/
				return( OSEENEXS );
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:Roop3[%ld] \n", "os_GetEmbcTableInd",
					lLoopCnt));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
					(long)ptEmbcInd));
			DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lPCode=%08lx \n",
					"os_GetEmbcTableInd", mpid, ptEmbcInd->lPCode));
		}
		else if( lAsso == D_ASSO_MAILBOX )			/* 種別が2(メイルボックス識別子)の場合		*/
		{
													/* 通番の範囲チェック						*/
			if( lSequenceNumber < D_SEQNUM_MIN || lSequenceNumber > ptEmbc->lIndPartNum )
			{
				return( OSEEIMPI );					/* 種別に範囲外の値が設定されている			*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
					ptEmbc->lIndPartNum));
													/* メイルボックス管理テーブル個別部の検索	*/
//			for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
			for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
			{
//				DbgMsg01(DLv04, (OutPut, "***** %s:Roop4[%ld] \n", "os_GetEmbcTableInd",
//						lLoopCnt));

				ptEmbcInd = *pptEmbcInd;

//				DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//						(long)ptEmbcInd));
//				DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lMBoxId=%08lx \n",
//						"os_GetEmbcTableInd", mpid, ptEmbcInd->lMBoxId));

				if( mpid == ptEmbcInd->lMBoxId )
				{
					break;

				}

//				*pptEmbcInd++;						/* 次の個別部のアドレスを設定する			*/
				(*pptEmbcInd)++;					/* 次の個別部のアドレスを設定する			*/
			}

			if( lLoopCnt > ptEmbc->lIndPartNum )
			{
													/* 指定のメイルボックス識別子が				*/
													/* 登録された個別部が存在しない				*/
				return( OSEENEXS );
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:Roop4[%ld] \n", "os_GetEmbcTableInd",
					lLoopCnt));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
					(long)ptEmbcInd));
			DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lMBoxId=%08lx \n",
					"os_GetEmbcTableInd", mpid, ptEmbcInd->lMBoxId));
		}
		else
		{
			return( OSEEIMPI );						/* 種別に範囲外の値が設定されている			*/
		}
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_GetEmbcTableInd" ) );
	return( NORMAL );
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
