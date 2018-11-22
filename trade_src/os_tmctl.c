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
/* ＜サービス項目名＞				 タイマ制御													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 タイマの制御												*/
/* ＜モジュールＩＤ＞				 os_tmctl													*/
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
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月０４日		故障管理番号（ＴＢＣＳ０２０２）*/
/* ＜ソース修正者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ新保)				*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月１５日		故障管理番号（ＴＢＣＳ０２０３）*/
/* ＜ソース修正者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ新保)				*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月１７日		故障管理番号（ＴＢＣＳ０２３５）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 タイマのスタートを行う																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_tmctl.h>																*/
/*																								*/
/*	   	long	os_tmctl( long rd, long r_no, long usec, long sec )								*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		rd;					リクエスト識別子（０以上）								*/
/*		long		r_no;				リクエスト番号											*/
/*		long		usec;				マイクロ秒（０以上）									*/
/*		long		sec;				秒（０以上）											*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		-1																		*/
/*						OSEEWKEX																*/
/*						OSEEITIM																*/
/*						OSEEIVRD																*/
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
#include <sys/time.h>                   // settimer用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "os_tmctl_ins.h"               // 内部参照用（個別）
#include "os_tmctl.h"

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    os_tmctl                                                  */
/*                                                                          */
/*  ＜機能概要＞  タイマのスタートを行う                                    */
/*                                                                          */
/****************************************************************************/
long os_tmctl( long rd, long r_no, long usec, long sec )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEtmcTable *ptTEtmcTable = ptEtmc;  // タイマ管理テーブル先頭アドレス
    TEtmcTableInd *ptTEtmcTableInd = ( void * )ptEtmc + sizeof( TEtmcTable );
                                        // タイマ管理テーブル個別部アドレス

    TEtmcTableInd *ptTEtmcTableIndIntact = NULL;
                                        // 未使用アドレス（タイマ挿入アドレス）
    TEtmcTableInd *ptTEtmcTableIndReference = NULL;
                                        // 検索用アドレス
    TEtmcTableInd *ptTEtmcTableIndNext = NULL; // タイマ挿入アドレスの次のアドレス
    long lTemp = 0;                     // 作業用変数
    double dThisTime = 0;               // 今回のタイマ値
    int iSetitimerRet = 0;              // setitimerの返却値
    double dTotal = 0;                  // トータル時間
    struct itimerval tOvalue;           // 残り時間
    
    
	os_trcget2( D_MD_OS_TMCTL , D_T_TRA_IN, 4, rd, r_no, usec, sec );
    
/*****	故障管理番号TBCS0202の対応		Start							修正日：2003.07.04	*****/
	memset(&tOvalue, 0, sizeof(struct itimerval));	// 残り時間 クリア
/*****	故障管理番号TBCS0202の対応		 End							修正日：2003.07.04	*****/

//    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

/*****  障害対応（TBCS0203）    Start                                   修正日：2003.07.15  *****/
//    if( rd < D_REQID_MIN || rd >= ptTEtmcTable->lTimeMaxCnt )
    if( rd < D_REQID_MIN || rd > ptMyEPRC->lMaxReqNum )
/*****  障害対応（TBCS0203）    End                                     修正日：2003.07.15  *****/
                                        // リクエスト識別子の確認
    {
		os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEIVRD );
		
        return( OSEEIVRD );
    }

    if( usec < D_USEC_MIN )             // マイクロ秒が範囲内でない時
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
       	os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );
                                              
        return( OSEEITIM );
    }

    if( sec < D_SEC_MIN )               // 秒が範囲内でない時
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );
                                              
        return( OSEEITIM );
    }

    if( ( usec == D_USEC_MIN ) && ( sec == D_SEC_MIN ) ) 
                                        // 秒とマイクロ秒のチェックエラー時
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );                                      
                                              
        return( OSEEITIM );
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	/************************************************/
	/*	タイマ管理テーブルの検索					*/
	/************************************************/
    for( lTemp = 0; lTemp < ptTEtmcTable->lTimeMaxCnt; lTemp++ )
                                        // 空き個別部を検索
    {
        if( ptTEtmcTableInd[ lTemp ].lReqId == D_REQUESTID_INI )
                                        // 未使用が見つかった場合
        {
            ptTEtmcTableIndIntact = &ptTEtmcTableInd[ lTemp ];
                                        // 変数「未使用アドレス」に設定
            break;
        }
    }
    if( lTemp ==  ptTEtmcTable->lTimeMaxCnt )
                                        // 個別部に空きがなかった場合
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEWKEX ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_SYS, 1, OSEEWKEX );                                           
                                              
        return( OSEEWKEX );
    }
    
/*****  障害対応（TBCS0235）    Start                                   修正日：2003.07.17  *****/
    if( ptTEtmcTable->ptNxtAdr != NULL )
										// 「管理部の次タイマ」がNULL以外の時
    {
	    /********************************************/
		/*	タイマのキャンセル						*/
		/********************************************/
	    os_trcget2( D_MD_OS_TMCTL, D_T_SYS_SETITIMER, 3, ITIMER_REAL, NULL, &tOvalue );    
		
        iSetitimerRet = setitimer( ITIMER_REAL, NULL, &tOvalue );
                                        // タイマのキャンセル
		//os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 1, iSetitimerRet );
		os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 4,
				iSetitimerRet, errno, tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec  );
		DbgMsg01( DLv05, ( OutPut, "***** キャンセル残タイマ値:%ld:%ld\n",
						 tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec));

        if( iSetitimerRet == D_ERR_SYS )// タイマセット失敗
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
                                              D_PROC_NAME, -1 ) );
                                              
            os_trcget2( D_MD_OS_TMCTL, D_T_ERR_SYS, 1, -1 );
                                              
            return( -1 );               // アボード処理
        }
	}
/*****  障害対応（TBCS0235）    End                                     修正日：2003.07.17  *****/

	/************************************************/
	/*	タイマ管理テーブルの編集					*/
	/************************************************/
    ptTEtmcTableIndIntact->lReqId = rd; // 「未使用アドレス」のリクエスト番号
                                        // に引数「リクエスト識別子」を設定
    ptTEtmcTableIndIntact->lReqNum = r_no;
                                        // 「未使用アドレス」のリクエスト番号
                                        // に引数「リクエスト番号」を設定
    if( ptTEtmcTable->ptNxtAdr == NULL )
                                        // 「管理部の次タイマ」がNULLの時
    {
        dThisTime = sec + ( usec * D_USEC );
                                        //「今回のタイマ値」を設定する
        ptTEtmcTableIndIntact->dTimer = dThisTime;
                                        //「未使用アドレス」のタイマ値
                                        // に「今回のタイマ値」を設定
        ptTEtmcTableIndIntact->ptPrevAdr = ( void * )ptTEtmcTable;
                                        //「未使用アドレス」の前タイマ値
                                        // 管理部のアドレスを設定
        ptTEtmcTableIndIntact->ptNextAdr = ( void * )ptTEtmcTable;
                                        //「未使用アドレス」の次タイマ値
                                        // 管理部のアドレスを設定
		DbgMsg01( DLv04, ( OutPut, "***** %s:発行タイマ:%lf\n",
										D_PROC_NAME, ptTEtmcTableIndIntact->dTimer) );
    }
    else                                // 「管理部の次タイマ」がNULL以外の時
    {
/*****  障害対応（TBCS0235）    Start                                   修正日：2003.07.17  *****/
//	    /********************************************/
//		/*	タイマのキャンセル						*/
//		/********************************************/
//	    os_trcget2( D_MD_OS_TMCTL, D_T_SYS_SETITIMER, 3, ITIMER_REAL, NULL, &tOvalue );    
//		
//        iSetitimerRet = setitimer( ITIMER_REAL, NULL, &tOvalue );
//                                        // タイマのキャンセル
//		//os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 1, iSetitimerRet );
//		os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 4,
//				iSetitimerRet, errno, tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec  );
//		DbgMsg01( DLv05, ( OutPut, "***** キャンセル残タイマ値:%ld:%ld\n",
//						 tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec));
//
//        if( iSetitimerRet == D_ERR_SYS )// タイマセット失敗
//        {
//            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, -1 ) );
//                                              
//            os_trcget2( D_MD_OS_TMCTL, D_T_ERR_SYS, 1, -1 );
//                                              
//            return( -1 );               // アボード処理
//        }
/*****  障害対応（TBCS0235）    End                                     修正日：2003.07.17  *****/

        /********************************************/
		/*	次タイマに現在のタイマを設定			*/
		/********************************************/
        ptTEtmcTableIndReference = ( void * )ptTEtmcTable->ptNxtAdr;
                                        // 「検索用アドレス」に
                                        // 管理部の次アドレスを設定
		os_trcget2( D_MD_OS_TMCTL, D_MM_OSSETTIMER, 4, ptTEtmcTableIndReference,
					ptTEtmcTableIndReference->lReqId, ptTEtmcTableIndReference->lReqNum,
					ptTEtmcTableIndReference->dTimer);

        ptTEtmcTableIndReference->dTimer 
               = tOvalue.it_value.tv_sec + ( tOvalue.it_value.tv_usec * D_USEC );
                                        // 現発行中のアドレスのタイマを設定
		os_trcget2( D_MD_OS_TMCTL, D_MM_OSSETTIMER, 4, ptTEtmcTableIndReference,
					ptTEtmcTableIndReference->lReqId, ptTEtmcTableIndReference->lReqNum,
					ptTEtmcTableIndReference->dTimer);

		DbgDmp02( DLv04, ("発行中のタイマを設定", ptTEtmcTableIndReference, sizeof(TEtmcTableInd),1,0));
		
        dThisTime = sec + ( usec * D_USEC );
                                        //「今回のタイマ値」を設定
		DbgMsg01( DLv04, ( OutPut, "*****%s 今回のタイマ値 dThisTime:%f\n", D_PROC_NAME, dThisTime));
		
        /********************************************/
		/*	タイマの差分算出						*/
		/********************************************/
        for(;;)                         // 今回の時間を超えるまでの合計時間を
                                        // 求める
        {
			DbgMsg01( DLv04, ( OutPut, "*****%s dTotal:%f\n", D_PROC_NAME, dTotal));
			DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference->dTimer:%f\n", D_PROC_NAME,
					ptTEtmcTableIndReference->dTimer));
			DbgMsg01( DLv04, ( OutPut, "*****%s 合計値:%f\n", D_PROC_NAME,
					 dTotal + ptTEtmcTableIndReference->dTimer));

            if( dTotal + ptTEtmcTableIndReference->dTimer > dThisTime )
                                        // 合計時間と今回の時間を比べる
            {
                ptTEtmcTableIndReference = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptPrevAdr;
                                        // 合計を出した後なので、
                                        //「検索用アドレス」に
                                        // 前タイマのアドレスを設定
                break;
            }
            dTotal = dTotal + ptTEtmcTableIndReference->dTimer;
                                        // 合計に現アドレスの残り時間を足す

			DbgMsg01( DLv04, ( OutPut, "*****%s 残り時間 dTotal:%f\n", D_PROC_NAME, dTotal));
			//DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference->ptNextAdr:%lx\n",
			//								D_PROC_NAME,ptTEtmcTableIndReference->ptNextAdr ));
			//DbgMsg01( DLv04, ( OutPut,"*****%s ptTEtmcTable:%08lx\n", D_PROC_NAME, ptTEtmcTable));

            if( ptTEtmcTableIndReference->ptNextAdr == ( void * )ptTEtmcTable )
                                        // 次タイマのアドレスが管理部の時
            {
                break;
            }
            ptTEtmcTableIndReference = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptNextAdr;
                                        // 次タイマのアドレスを設定
        }

                                        //「未使用アドレス」の前タイマに
                                        //前アドレスを設定
        ( TEtmcTableInd * )ptTEtmcTableIndIntact->ptPrevAdr = ptTEtmcTableIndReference;

		DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference:%lx\n", D_PROC_NAME,
				ptTEtmcTableIndReference));

		//DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTable:%f\n", D_PROC_NAME, ptTEtmcTable));

        if( ptTEtmcTableIndReference == ( void * )ptTEtmcTable )//管理部なら
        {
            ptTEtmcTableIndIntact->ptNextAdr = ptTEtmcTable->ptNxtAdr;
                                        //「未使用アドレス」の次タイマに
                                        //次アドレスを設定
            ptTEtmcTableIndNext = ( TEtmcTableInd * )ptTEtmcTable->ptNxtAdr;
                                        // 次アドレス
        }
        else                            // 管理部でない時
        {
            ptTEtmcTableIndIntact->ptNextAdr 
                               = ptTEtmcTableIndReference->ptNextAdr;
                                        //「未使用アドレス」の次タイマに
                                        //次アドレスを設定
            ptTEtmcTableIndNext = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptNextAdr;
                                        // 次アドレス
        }
        ptTEtmcTableIndIntact->dTimer = dThisTime - dTotal;
        
                                        // 未使用アドレスのタイマを計算
		// タイマの差が0.01以下の時はタイマ値を0.01に再設定
										// 20030303 故障処理票KL0026 対応

		if( 0.01 > ptTEtmcTableIndIntact->dTimer )
		{								// 差が０の時は最小時間単位(10ms)を設定
			//ptTEtmcTableIndIntact->dTimer = 0.01;
										// 20030320 故障処理票KL0026 対応
			ptTEtmcTableIndIntact->dTimer = D_TIMEOUT;
		}

		DbgMsg01( DLv04, ( OutPut, "***** %s: 発行要求タイマ:%f\n", D_PROC_NAME,
						ptTEtmcTableIndIntact->dTimer ) );

        if( ptTEtmcTableIndNext != ( void * )ptTEtmcTable )
                                        // 管理部以外なら
        {

			DbgMsg01( DLv04, ( OutPut, "***** %s: ptTEtmcTableIndNext->dTimer:%f\n", D_PROC_NAME,
						ptTEtmcTableIndNext->dTimer ) );

			ptTEtmcTableIndNext->dTimer
					 = ptTEtmcTableIndNext->dTimer - ptTEtmcTableIndIntact->dTimer;
										// 次アドレスのタイマを計算
										// 20030310 故障処理票KL0026 暫定対応

			if( 0.01 > ptTEtmcTableIndNext->dTimer )
			{
				//ptTEtmcTableIndNext->dTimer = 0.01;
										// 20030320 故障処理票KL0026 対応
				ptTEtmcTableIndNext->dTimer = D_TIMEOUT;
			}

			DbgMsg01( DLv04, ( OutPut, "***** %s: ptTEtmcTableIndNext->dTimer:%f\n", D_PROC_NAME,
						ptTEtmcTableIndNext->dTimer ) );
        }

    }
    
    /************************************************/
	/*	タイマの発行								*/
	/************************************************/
    os_SetTimer( ptTEtmcTableIndIntact );
                                        // タイマの発行    
//    DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
    
   	os_trcget2( D_MD_OS_TMCTL , D_T_TRA_OUT, 1, NORMAL );
    
    return( NORMAL );
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
