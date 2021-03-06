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
/* ＜サービス項目名＞				 リザルト・例外												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 リクエスト識別子の予約										*/
/* ＜モジュールＩＤ＞				 osrsrrd													*/
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
/*		プログラムで使用するリクエスト識別子を複数個、連続的に一括して予約する。				*/
/*		指定範囲のリクエスト識別子は以降、カーネルによる自動割当ての対象とはならない。			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osrsrrd.h>																	*/
/*																								*/
/*	   	long	osrsrrd(long rd,long no)														*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	rd;			リクエスト識別子													*/
/*		long	no;			個数																*/
/*																								*/
/* ＜返却値＞																					*/
/*      NORMAL      ：正常に予約できた                                                          */
/*      OSEEIVNO	：個数が正の値でない、又は値が大きすぎる                                    */
/*      OSEEIVRD    ：リクエスト識別子の値が不当である                                          */
/*      OSEEUSED    ：指定範囲のリクエスト識別子のうち、使用中のものがあるか、                  */
/*                    二重に予約ものがある                                                      */
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


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	"osrsrrd.h"
#include	"osrsrrd_ins.h"


long	osrsrrd(rd, no)
long	rd;											/* リクエスト識別子							*/
long	no;											/* 個数										*/
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long			lCnt1;							/* ループカウンタ1							*/
	long			lCnt2;							/* ループカウンタ2							*/
	long			lCnt3;							/* ループカウンタ3							*/
	long			lCnt4;							/* ループカウンタ4							*/
	long			lRet;							/* 返却値									*/
	TErdcTableInd	*ptErdcp = NULL;				/* ｒｄ管理テーブル個別部ポインタ			*/


	os_trcget2( D_MD_OSRSRRD, D_T_TRA_IN, 2, rd, no );

													/* 関数入口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrsrrd" ) );

	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	lCnt1 = 0;
	lCnt2 = 0;
	lCnt3 = 0;
	lCnt4 = 0;
	lRet = 0;


	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ｒｄ管理個別部の先頭アドレス設定			*/

	DbgMsg01(DLv04, (OutPut, "\n***** %s:%s rd=%08x, no=%#d \n ", "osrsrrd",
			"パラメータ", rd, no));


	/************************************************/
	/*  引数チェック								*/
	/************************************************/
	/****************************************/
	/* リクエスト識別子（rd）のチェック		*/
	/****************************************/
													/* ループ処理								*/
//2003.02.19	for(lCnt1 = 0; lCnt1 < ptErdc->lMaxIndNum; lCnt1++)
	for(lCnt1 = 0; lCnt1 < ptMyEPRC->lMaxReqNum; lCnt1++)
	{
		if (rd == ptErdcp->lRCode)					/* リクエスト識別子が一致した場合			*/
		{
			break;									/* ループを抜ける							*/
		}

//		DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop Count=%#d 回目  ", "osrsrrd", (lCnt1+1)));
//		DbgMsg01(DLv04, (OutPut, "ptErdcp=%08x, lRCode=%08x \n", ptErdcp, ptErdcp->lRCode));

		ptErdcp++;									/* 次アドレスへポインタを進める				*/
	}


//2003.02.19	if (lCnt1 >= ptErdc->lMaxIndNum)				/* ｒｄ管理テーブル個別部の最大値を超過		*/
	if (lCnt1 >= ptMyEPRC->lMaxReqNum)				/* ｒｄ管理テーブル個別部の最大値を超過		*/
	{												/* ｒｄ管理テーブルの個別部が存在しない場合 */
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrsrrd",
			"処理異常!!", "該当するｒｄ管理テーブルの個別部はありません。"));
			
		os_trcget2( D_MD_OSRSRRD, D_T_ERR_PRA, 1, OSEEIVRD );	
			
		return(OSEEIVRD);							/* 異常終了（invalid req descriptor）		*/
	}


	/****************************************/
	/* 個数（no）のチェック					*/
	/****************************************/
//2003.02.19	if ((0 >= no) || (ptErdc->lMaxIndNum < no))		/* 0以下、又はrd管理テーブル個別部数の		*/
	if ((0 >= no) || (ptMyEPRC->lMaxReqNum < no))		/* 0以下、又はrd管理テーブル個別部数の		*/
	{												/* 最大値を超過した場合						*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  no=%#d\n", "osrsrrd",
			"処理異常!!", "指定された個数が「0」以下、又は値が大きすぎる。", no));
			
		os_trcget2( D_MD_OSRSRRD, D_T_ERR_PRA, 1, OSEEIVNO );		

		return(OSEEIVNO);							/* 異常終了（invalid number）				*/
	}

	DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop1 Count=%#d 回目  ", "osrsrrd", lCnt1));
	DbgMsg01(DLv04, (OutPut, "ptErdcp=%08x \n", ptErdcp));


    /********************************************************************************************/
    /*  メイン処理                                                                              */
    /********************************************************************************************/
	/****************************************/
	/*  リクエスト状態の予約状態チェック	*/
	/****************************************/
	for (lCnt2 = 0; lCnt2 < no; lCnt2++)
	{
													/* リクエスト予約状態が予約済み(0x01)の場合 */
		if (D_ERDC_RESSTAT_RES == (ptErdcp + lCnt2)->tReqStat.cResStat)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  no=%#d\n", "osrsrrd",
				"処理異常!!", "指定範囲の中に、二重に予約のものがある。", no));
			
			os_trcget2( D_MD_OSRSRRD, D_T_ERR_SYS, 1, OSEEUSED );		
				
			return(OSEEUSED);						/* 異常終了（used）							*/
		}
	}


	/****************************************/
	/*  リクエスト状態の使用状態チェック	*/
	/****************************************/
	for (lCnt3 = 0; lCnt3 < no; lCnt3++)
	{
													/* リクエスト予約状態が予約済み(0x01)の場合 */
		if (D_ERDC_RESSTAT_RES == (ptErdcp + lCnt3)->tReqStat.cUseStat)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  no=%#d\n", "osrsrrd",
				"処理異常!!", "指定範囲の中に、使用中のものがある。", no));
				
			os_trcget2( D_MD_OSRSRRD, D_T_ERR_SYS, 1, OSEEUSED );		
				
			return(OSEEUSED);						/* 異常終了（used）							*/
		}
	}


	/****************************************************/
	/*  リクエスト状態の予約状態を予約済み(0x01)に設定	*/
	/****************************************************/
	for (lCnt4 = 0; lCnt4 < no; lCnt4++)
	{
													/* リクエスト予約状態を予約済み(0x01)に設定 */
		(ptErdcp + lCnt4)->tReqStat.cResStat = D_ERDC_RESSTAT_RES;

		DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop4 Count=%#d 回目  ", "osrsrrd", lCnt4));
		DbgMsg01(DLv04, (OutPut, "cResStat=%02x \n", (ptErdcp + lCnt4)->tReqStat.cResStat));
	}


    /********************************************************************************************/
    /*  終了処理                                                                                */
    /********************************************************************************************/
													/* 関数出口									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrsrrd" ) );
	
	os_trcget2( D_MD_OSRSRRD, D_T_TRA_OUT, 1, NORMAL );

	return (NORMAL);								/* 正常終了									*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
