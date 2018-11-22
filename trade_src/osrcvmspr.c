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
/* ＜モジュール名＞					 プールバッファ上のメッセージ受信要求							*/
/* ＜モジュールＩＤ＞				 osrcvmspr													*/
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
/*	 プールバッファ上のメッセージの受信要求														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osrcvmspr.h>																*/
/*																								*/
/*	   	long	osrcvmspr( long mpid, long rd, char **bufaa )									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	mpid;		メイルボックス又はプロセス識別子									*/
/*		long	rd;			リクエスト識別子(0以上)												*/
/*		char	**bufaa;	プールバッファアドレス格納域										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		リクエスト識別子														*/
/*		異常終了		os_GetEmbcTableIndの返却値												*/
/*						OSEEOVRQ		rd管理テーブルに未予約かつ未使用の個別部が存在しない	*/
/*						OSEEIVRD		当該個別部の予約状態が予約済でない						*/
/*						OSEEUSED		当該個別部の非完了要求状態が要求済みでない				*/
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

/* 利用者作正ヘッダファイル */


/* 外部変数宣言 */
#include "osrcvmspr.h"
#include "osrcvmspr_ins.h"
#include "osrcvmspr_ins.h"
#include	"os_debug.h"


/* 内部関数宣言 */

/* static変数の宣言 */

/*****************************************************************************/
/* 機能：プールバッファ上のメッセージの受信要求                              */
/* 作成日：2002年10月04日                                                    */
/* 変更日：　　年　月　日                                                    */
/* 作成者：                                                                  */
/* 呼出形式：                                                                */
/*   long osrcvmspr( long mpid, long rd, char **bufaa )                      */
/*       long mpid        メイルボックス又はプロセス識別子                   */
/*       long rd          リクエスト識別子(0以上)                            */
/*       char **bufaa     プールバッファアドレス格納域                       */
/*****************************************************************************/
long osrcvmspr( long mpid, long rd, char **bufaa )
{
	long	lLoopCnt;								/* ループカウンタ							*/
	long	lRet;									/* 関数結果返却								*/
	long	lAsso;									/* 種別										*/
	TEmbcTableInd	*ptEmbcInd;						/* メイルボックステーブル個別部のアドレス	*/
	TErdcTableInd	*ptErdcInd;						/* rd管理テーブル個別部のアドレス			*/
	
	
	os_trcget2( D_MD_OSRCVMSPR, D_T_TRA_IN, 3, mpid, rd, *bufaa );

													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvmspr" ) );

/************************************************************************************************/
/*  初期処理																					*/
/************************************************************************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:mpid =%08lx \n", "osrcvmspr", mpid));
	DbgMsg01(DLv04, (OutPut, "***** %s:rd   =%ld \n", "osrcvmspr", rd));
	DbgMsg01(DLv04, (OutPut, "***** %s:bufaa=%08lx \n\n", "osrcvmspr", (long)bufaa));


	/********************************/
	/* 引数チェック					*/
	/********************************/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );
	if( lRet != NORMAL )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  lRet=%08lx \n", "osrcvmsr",
				"処理異常!!", "指定したメイルボックスが存在しない。又は削除された。", lRet));
				
		os_trcget2( D_MD_OSRCVMSPR, D_T_ERR_PRA, 1, lRet );
		
		return( lRet );
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvmspr", lRet));


	ptErdcInd = (TErdcTableInd *)(ptErdc + 1 );		/* rd管理テーブル個別部先頭アドレスを設定	*/

	/********************************/
	/* リクエスト識別子のチェック	*/
	/********************************/
	if( rd == 0 )									/* リクエスト識別子(引数:rd)が「0」の場合	*/
	{
													/* rd管理テーブル個別部の先頭から			*/
													/* リクエスト状態が「未予約」かつ「未使用」	*/
													/* かつ「未要求」の個別部を検索する			*/
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
		if( lLoopCnt > ptMyEPRC->lMaxReqNum )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "非完了処理要求の数が多すぎる。"));
					
			os_trcget2( D_MD_OSRCVMSPR, D_T_ERR_PRA, 1, OSEEOVRQ );		

			return( OSEEOVRQ );						/* 該当する個別部が存在しない				*/
		}
	}
	else
	{												/* リクエスト識別子が0以外(設定)の場合		*/
													/* 引数のリクエスト識別子と同じ				*/
													/* リクエスト識別子を持つ個別を検索する		*/
		for( lLoopCnt = 1; lLoopCnt <= ptMyEPRC->lMaxReqNum; lLoopCnt++ )
		{
			if( rd == ptErdcInd->lRCode )
			{
				break;
			}
			ptErdcInd++;							/* 次の個別部のアドレスを設定する			*/
		}

		if( lLoopCnt > ptMyEPRC->lMaxReqNum )			/* rd管理テーブルにrdと同じリクエスト識別子	*/
		{											/* を持った個別部が存在しない				*/
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "非完了処理要求の数が多すぎる。"));

			os_trcget2( D_MD_OSRCVMSPR, D_T_ERR_PRA, 1, OSEEOVRQ );	

			return( OSEEOVRQ );
		}
		if( ptErdcInd->tReqStat.cResStat != D_ERDC_RESSTAT_RES )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "指定ｒｄは予約されていない。又は不当な値である。"));
					
				os_trcget2( D_MD_OSRCVMSPR, D_T_ERR_PRA, 1, OSEEIVRD );		

				return( OSEEIVRD );					/* 当該個別部の予約状態が予約済でない		*/
		}
		if( ptErdcInd->tReqStat.cUCompStat != D_ERDC_UCOMPSTAT_NONE )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"処理異常!!", "指定ｒｄは非完了要求済である。又は不当な値である。"));
					
				os_trcget2( D_MD_OSRCVMSPR, D_T_ERR_PRA, 1, OSEEUSED );		

				return( OSEEUSED );					/* 当該個別部の非完了要求状態が未要求でない */
		}
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lLoopCnt =%ld \n", "osrcvmspr", lLoopCnt));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd=%08lx \n", "osrcvmspr", (long)ptErdcInd));


/************************************************************************************************/
/*  本処理																						*/
/************************************************************************************************/
	/********************************************/
	/*  rd管理テーブル管理部の					*/
	/*  プロセス間メッセージ要求フラグの編集	*/
	/********************************************/
	lAsso = os_GetAsso( mpid );						/* 種別の取得								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvmspr", lAsso));

													/* 種別が「1」の場合、又は					*/
													/* 第一パラメータが「0」の場合				*/
//	if( lAsso == D_ASSO_PROCESS )
	if((D_ASSO_PROCESS == lAsso) || (0 == mpid))
	{
		ptErdc->tMsgFlg.cPrcPbOn = D_ERDC_MSGFLG_ON;/* プロセス宛プールバッファ有りメッセージ	*/

		DbgMsg01(DLv04, (OutPut, "\n***** %s:%s\n", "osrcvmspr",
				"プールバッファ上のメッセージの受信要求（プロセス宛）"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOn=%02x \n", "osrcvmspr",
				ptErdc->tMsgFlg.cPrcPbOn));
	}
	else											/* 種別が2(メイルボックス識別子)の場合		*/
	{
													/* メイルボックス宛プールバッファ有りの		*/
													/* メッセージ								*/
		ptErdc->tMsgFlg.cMbPbOn = D_ERDC_MSGFLG_ON;

		DbgMsg01(DLv04, (OutPut, "***** %s:%s\n", "osrcvmspr",
				"プールバッファ上のメッセージの受信要求(メイルボックス宛)"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOn=%02x \n", "osrcvmspr",
				ptErdc->tMsgFlg.cMbPbOn));
	}

	/********************************************/
	/*  rd管理テーブル個別部編集				*/
	/********************************************/
													/* リクエスト状態（非完了要求状態）			*/
													/* を要求済に設定							*/
	ptErdcInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->tReqStat.cUCompStat=%02x \n", "osrcvmspr",
			ptErdcInd->tReqStat.cUCompStat));

													/* 種別が「1」の場合、又は					*/
													/* 第一パラメータが「0」の場合				*/
//	if( lAsso == D_ASSO_PROCESS )
	if(( D_ASSO_PROCESS == lAsso ) || ( 0 == mpid ))
	{
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求（プロセス宛）		*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_PRC_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS08;

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmspr",
				ptErdcInd->cReqClass));
	}
	else											/* 種別が2(メイルボックス識別子)の場合		*/
	{
													/* プールバッファ上のメッセージの			*/
													/* 				受信要求(メイルボックス宛)	*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_MB_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS07;

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmspr",
				ptErdcInd->cReqClass));
	}

	ptErdcInd->lReqNum = 0;
	ptErdcInd->pvArg1 = bufaa;

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->pvArg1=%08lx \n", "osrcvmspr",
			ptErdcInd->pvArg1));


/************************************************************************************************/
/*  終了処理																					*/
/************************************************************************************************/
													/* 関数出口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmspr" ) );
	
	os_trcget2( D_MD_OSRCVMSPR, D_T_TRA_OUT, 1, ptErdcInd->lRCode );
	
	return( ptErdcInd->lRCode );
}
/************************************************************************************************/
/*  End																							*/
/************************************************************************************************/
