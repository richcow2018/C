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
/* ＜サービス項目名＞				 バッファプール管理											*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 プールバッファの確保										*/
/* ＜モジュールＩＤ＞				 osgtpbf													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ五味)				*/
/* ＜ソース作成年月日＞ 			 ２００２年１０月１０日 									*/
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月０４日		仕様変更番号（ＳＳＬＡ００３５）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/* 機能：プールバッファの確保                                               					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osgtpbf.h>																	*/
/*																								*/
/*   long osgtpbf( long poolid, long no, long *bufp[] )                     					*/
/*																								*/
/* ＜仮引数＞																					*/
/*     long poolid         プール識別子                                     					*/
/*     long no             プールバッファ個数                               					*/
/*     long *bufp[]        プールバッファアドレスリスト                     					*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEACCV		アドレス異常が発生した。								*/
/*						OSEEFLBF		バッファプールに空きがない。							*/
/*						OSEEIPLI		プール識別子が不当である。								*/
/*						OSEEIPOL		プールバッファが未作成状態である。						*/
/*						OSEEIVNO		プールバッファの個数が不当である。						*/
/*						OSEENEXS		プールバッファ識別子の通番がSG範囲を超えていて、		*/
/*										存在しない。											*/
/*						OSEENMAP		バッファプールをマッピングしていない。					*/
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>
/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "osgtpbf.h"
#include "osgtpbf_ins.h"				// 内部参照用（個別）

/****************************************************************************/
/* 機能：プールバッファの確保                                               */
/* 作成日：2002年10月10日                                                   */
/* 変更日：                                                                 */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long osgtpbf( long poolid, long no, long *bufp[] )                     */
/*     long poolid         プール識別子                                     */
/*     long no             プールバッファ個数                               */
/*     long *bufp[]        プールバッファアドレスリスト                     */
/*                                                                          */
/****************************************************************************/
long osgtpbf( long poolid, long no, long *bufp[] )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// セマフォ構造体
	int iRet;							// 返却値
	int iLoopCnt;						// ループカウンタ
	long lRet;							// 返却値
	long lBpSize;						// バッファプールサイズ
	TEbpcTableInd *ptBpIndAdr;			// バッファプール管理テーブル個別部のアドレス
	TEpbcTableInd *ptPbIndAdr;			// プールバッファ管理テーブル個別部のアドレス
	TEpbcTableInd *ptPbIndNxtAdr;		// プールバッファ管理テーブル個別部のアドレス（次アドレス）
	TEpbcTableInd *ptPbIndTmpAdr;		// プールバッファ管理テーブル個別部のアドレス（一時使用）
	void *pvBpAdr = NULL;				// バッファプールアドレス
/*****	仕様変更番号SSLA0035の対応		Start							修正日：2003.07.04	*****/
	struct	timeval		tTmVal;			// 時間取得用構造体
/*****	仕様変更番号SSLA0035の対応		 End							修正日：2003.07.04	*****/

	os_trcget2( D_MD_OSGTPBF, D_T_TRA_IN, 3, poolid, no, bufp );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	対象個別部アドレスの取得					*/
	/************************************************/
	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// バッファプール管理テーブルから対象個別部アドレスの取得
	if( lRet != NORMAL )				// 対象個別部のアドレスの取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, lRet ) );
		
		os_trcget2( D_MD_OSGTPBF,  D_T_ERR_PRA, 1, lRet );
		
		return( lRet );					// 返却値を返却
	}

	/************************************************/
	/*	バッファプール個別部のロック				*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ロックできなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					                                                 
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 1, OSEEWKEX );                                                 
					                                                 
	        		return( OSEEWKEX );	// OSEEWKEXを返却
	        }
		}
		else							// バッファプールアクセスのロック成功
		{
			break;						// 処理を抜ける
		}
	}

	/************************************************/
	/*	プールバッファ数のチェック					*/
	/************************************************/
	if( no < D_PBNUM_MIN )				// プールバッファ数が最小値より小さい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		lRet = OSEEIVNO;				// OSEEIVNOを設定
		goto err_osgtpbf;				// エラー処理へ遷移
	}

	if( no > ptBpIndAdr->lMaxUnitNum )	// プールバッファ数が対象個別部のユニット数より大きい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		lRet = OSEEIVNO;				// OSEEIVNOを設定
		goto err_osgtpbf;				// エラー処理へ遷移
	}

	if( no > ptBpIndAdr->lEmpUnitNum )	// プールバッファ数が対象個別部の空きユニット数より大きい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEFLBF ) );
		lRet = OSEEFLBF;				// OSEEFLBFを設定
		goto err_osgtpbf;				// エラー処理へ遷移
	}

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// 作成状態が作成済でない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIPOL ) );
		lRet = OSEEIPOL;				// OSEEIPOLを設定
		goto err_osgtpbf;				// エラー処理へ遷移
	}

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	lBpSize = ptBpIndAdr->lMaxUnitNum * (ptBpIndAdr->lUnitSize + D_UNITHEAD_SIZE);
										// バッファプールサイズの算出

	/************************************************/
	/*	ユニットアドレスの範囲チェック				*/
	/************************************************/
	ptPbIndAdr = (void *)ptBpIndAdr->tPbInfo.ptNxtAdr;
										// 先頭のユニットアドレスを取得
										
	for(iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// 指定個数のユニットアドレスの範囲チェック
		if( (ptPbIndAdr->pvUnitAdr < ptBpIndAdr->pvEbpcAdr)
			|| (ptPbIndAdr->pvUnitAdr > ptBpIndAdr->pvEbpcAdr + lBpSize) )
		{								// ユニットアドレスがバッファプール範囲内でない時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEACCV ) );
			lRet = OSEEACCV;			// OSEEACCVを設定
			goto err_osgtpbf;			// エラー処理へ遷移
		}
		ptPbIndAdr = (TEpbcTableInd *)ptPbIndAdr->ptNxtAdr;
										// 次ユニットアドレスを取得
	}

	/************************************************/
	/*	バッファプール管理個別部の設定				*/
	/************************************************/
	ptPbIndNxtAdr = ptPbIndAdr;			// 次ユニットアドレスの退避（新規次ユニットとなる）
	ptPbIndAdr = (void *)ptBpIndAdr->tPbInfo.ptNxtAdr;
										// 先頭のユニットアドレスを取得
	ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndNxtAdr;
										// 退避した新規次ユニットアドレスの設定
	if( (void *)ptBpIndAdr->tPbInfo.ptNxtAdr == (void *)ptBpIndAdr )
	{									// 新規次ユニットがない時（空きユニットがない時）
		ptBpIndAdr->tPbInfo.ptNxtAdr = D_ADDRESS_NONE;
										// バッファプール管理情報の次アドレスをクリア
		ptBpIndAdr->tPbInfo.ptBefAdr = D_ADDRESS_NONE;
										// バッファプール管理情報の前アドレスをクリア
	}
	else								// 新規次ユニットがある時（空きユニットがある時）
	{
		((TEpbcTableInd *)(ptBpIndAdr->tPbInfo.ptNxtAdr))->ptBefAdr = (void *)ptBpIndAdr;
										// 新規次ユニットの前アドレスにバッファプール個別部の
										// アドレスを設定
	}

	for(iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// 指定個数のユニットの確保
		ptPbIndTmpAdr = (TEpbcTableInd *)ptPbIndAdr->ptNxtAdr;
										// 次のユニットアドレスを退避
		bufp[iLoopCnt] = ptPbIndAdr->pvUnitAdr;
										// プールバッファアドレスリストにユニットアドレスを設定
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->pvUnitAdr:%08lx\n",
				 D_PROC_NAME, ptPbIndAdr->pvUnitAdr ) );

		os_trcget2( D_MD_OSGTPBF, D_MM_OSGTPBF, 1,ptPbIndAdr->pvUnitAdr );

		--(ptBpIndAdr->lEmpUnitNum);	// 空きユニット数のデクリメント
		++(ptBpIndAdr->lGetEPBCNum);	// プールバッファ取得数のインクリメント

/*****	仕様変更番号SSLA0035の対応		Start							修正日：2003.07.04	*****/
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lGetEPBCNum=%08lx\n",
				 D_PROC_NAME, ptBpIndAdr->lGetEPBCNum ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lPeakCnt=%08lx\n",
				 D_PROC_NAME, ptBpIndAdr->lPeakCnt ) );
										// プールバッファ取得数が最大ピーク数を超過した場合
		if (ptBpIndAdr->lGetEPBCNum > ptBpIndAdr->lPeakCnt)
		{
			/****************************************/
			/*  最大ピーク数と最大ピーク時間の記録	*/
			/****************************************/
			os_trcget2( D_MD_OSGTPBF, D_T_SYS_GETTIMEOFDAY, 2, &tTmVal, NULL );
			gettimeofday(&tTmVal, NULL);// 時間を取得
			os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 1, tTmVal.tv_sec);

			DbgMsg01( DLv04, ( OutPut, "***** %s:tTmVal.tv_sec=%d\n",
				 	D_PROC_NAME, tTmVal.tv_sec ) );

										// 最大ピーク数にプールバッファ取得数を設定
			ptBpIndAdr->lPeakCnt = ptBpIndAdr->lGetEPBCNum;
										// 最大ピーク時間に取得した時間（秒）を設定
			ptBpIndAdr->lPeakTime = tTmVal.tv_sec;
			os_trcget2( D_MD_OSGTPBF, D_MM_OSGTPBF, 2, ptBpIndAdr->lPeakCnt, ptBpIndAdr->lPeakTime);
		}
/*****	仕様変更番号SSLA0035の対応		 End							修正日：2003.07.04	*****/

		ptPbIndAdr->cUnit = D_UNITINFO_GET;
										// ユニット状態に「取得」を設定
		ptPbIndAdr->lGetPid = lMyPid;
										// 取得プロセスＩＤに自プロセスＩＤを設定
		ptPbIndAdr->lUsePid = lMyPid;
										// 使用プロセスＩＤに自プロセスＩＤを設定
		ptPbIndAdr->ptNxtAdr = D_ADDRESS_NONE;
										// 次アドレスをクリア
		ptPbIndAdr->ptBefAdr = D_ADDRESS_NONE;
										// 20030305 追加
										// ユニット管理領域アドレスに管理情報アドレス追加
		*((long *)(ptPbIndAdr->pvUnitAdr - 4)) = (long)ptPbIndAdr;
										// 前アドレスをクリア
		ptPbIndAdr = ptPbIndTmpAdr;		// 次のユニットに移動
	}

	/************************************************/
	/*	バッファプール個別部のロック解除			*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック解除
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 2, -1 , errno ); 
					
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTPBF << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s:ID:%08lx ALL:%ld EMP:%ld GET:%ld\n", D_PROC_NAME,
			ptBpIndAdr->lPoolId,ptBpIndAdr->lMaxUnitNum, 
                        ptBpIndAdr->lEmpUnitNum, ptBpIndAdr->lGetEPBCNum ) );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSGTPBF, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMALを返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_osgtpbf:
	/************************************************/
	/*	バッファプール個別部のロック解除			*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック解除
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 2, -1 , errno );     
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTPBF << 16) | D_T_ERR_SYS1);
	        		//return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	os_trcget2( D_MD_OSGTPBF,  D_T_ERR_PRA, 1, lRet );     

	return( lRet );						// エラー値を返却
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
