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
/* ＜モジュール名＞					 プールバッファの開放										*/
/* ＜モジュールＩＤ＞				 osfrpbf													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*        プールバッファの解放                                               */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*   long osfrpbf( long no, long *bufp[] )                                  */
/*																								*/
/* ＜仮引数＞																					*/
/*     long no             プールバッファ個数                               */
/*     long *bufp[]        プールバッファアドレスリスト                     */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			iFilId+1(iFilIdはファイル記述子カウント用)							*/
/*		異常終了			-1																	*/
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
#include "osfrpbf.h"
#include "osfrpbf_ins.h"				// 内部参照用（個別）

/****************************************************************************/
/* 機能：プールバッファの解放                                               */
/* 作成日：2002年10月11日                                                   */
/* 変更日：                                                                 */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long osfrpbf( long no, long *bufp[] )                                  */
/*     long no             プールバッファ個数                               */
/*     long *bufp[]        プールバッファアドレスリスト                     */
/*                                                                          */
/****************************************************************************/
long osfrpbf( long no, long *bufp[] )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// セマフォ構造体
	int iRet;							// 返却値
	int iLoopCnt;						// ループカウンタ
	long lRet;							// 返却値
	long lBpSize;						// バッファプールサイズ
	void *pvBpAdr;						// バッファプールアドレス
	TEbpcTableInd *ptBpIndTopAdr;		// バッファプール管理テーブル個別部の先頭アドレス
	TEbpcTableInd *ptBpIndAdr;			// バッファプール管理テーブル個別部のアドレス
	TEpbcTableInd *ptPbIndAdr;			// プールバッファ管理テーブル個別部のアドレス

	os_trcget2( D_MD_OSFRPBF, D_T_TRA_IN, 2, no, bufp );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s:no   = %ld \n", D_PROC_NAME, no ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:bufp = %08lx \n", D_PROC_NAME, (long)bufp[0] ) );
	os_trcget2( D_MD_OSFRPBF, D_MM_OSFRPBF, 1,bufp[0] );


	if( no < D_PBNUM_MIN )				// プールバッファ数が最小値より小さい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_PRA, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNOを返却
	}

	ptBpIndTopAdr = (void *)ptEbpc + sizeof(TEbpcTable);
										// バッファプール管理テーブル個別部の先頭アドレス取得
	ptBpIndAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++ )
	{									// すべてのバッファプール管理テーブル個別部に対して処理
		pvBpAdr = ptBpIndTopAdr[iLoopCnt].pvEbpcAdr;
										// バッファプールアドレスの取得
		lBpSize = ptBpIndTopAdr[iLoopCnt].lMaxUnitNum
					* (ptBpIndTopAdr[iLoopCnt].lUnitSize + D_UNITHEAD_SIZE);
										// バッファプールサイズの算出
		if( ((void *)bufp[0] >= pvBpAdr)
			&& ((void *)bufp[0] <= (pvBpAdr + lBpSize)) )
		{								// プールバッファアドレス(１つ目)が個別部の管理下の時
			ptBpIndAdr = ptBpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
										/***** 20030317 SSLA0016 Start *****/
			lRet = os_ChkPB((void *)bufp[0], ptBpIndAdr);
			if(NORMAL != lRet)
			{
				return(lRet);
				break;
			}
										/***** 20030317 SSLA0016 End   *****/
			break;						// ループから抜ける
		}
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr = %08lx \n", D_PROC_NAME, (long)ptBpIndAdr ) );

	if( ptBpIndAdr == D_ADDRESS_NONE )	// プールバッファアドレス(１つ目)がどの個別部の管理下
	{									// でもない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIADR );
		return( OSEEIADR );				// OSEEIADRを返却
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->cStat = %02x \n", D_PROC_NAME,
//			ptBpIndAdr->cStat ) );

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// 作成状態が作成済でない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEENEXS );
		return( OSEENEXS );				// OSEENEXSを返却
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lMaxUnitNum = %ld \n", D_PROC_NAME,
//			ptBpIndAdr->lMaxUnitNum ) );

	if( no > ptBpIndAdr->lMaxUnitNum )	// プールバッファ数が対象個別部のユニット数より大きい時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNOを返却
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lEmpUnitNum = %ld \n", D_PROC_NAME,
//			ptBpIndAdr->lEmpUnitNum ) );

	if( no > (ptBpIndAdr->lMaxUnitNum - ptBpIndAdr->lEmpUnitNum) )
	{									// プールバッファ数が対象個別部の使用ユニット数より大きい時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
//		return( OSEEFLBF );				// OSEEFLBFを返却
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNOを返却
	}

	for( iLoopCnt = 1; iLoopCnt < no; iLoopCnt++ )
	{									// プールバッファアドレス(２つ目以降)のチェック
		if( ((void *)bufp[iLoopCnt] < pvBpAdr)
			|| ((void *)bufp[iLoopCnt] > (pvBpAdr + lBpSize)) )
		{								// プールバッファアドレスが個別部の管理下にない時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
			os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIADR );
			return( OSEEIADR );			// OSEEIADRを返却
		}
										/***** 20030317 SSLA0016 Start *****/
		lRet = os_ChkPB((void *)bufp[iLoopCnt], ptBpIndAdr);
		if(NORMAL != lRet)
		{
			return(lRet);
			break;
		}
										/***** 20030317 SSLA0016 End   *****/
		
	}


	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lPoolId     = %#08lx \n", D_PROC_NAME,
			ptBpIndAdr->lPoolId ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->pvEbpcAdr   = %#08lx \n", D_PROC_NAME,
			ptBpIndAdr->pvEbpcAdr ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lMaxUnitNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lMaxUnitNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lEmpUnitNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lEmpUnitNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lGetEPBCNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lGetEPBCNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lUnitSize   = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lUnitSize ) );

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ロックできなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEWKEX );
	        		return( OSEEWKEX );	// OSEEWKEXを返却
	        }
		}
		else							// バッファプールアクセスのロック成功
		{
			break;						// 処理を抜ける
		}
	}
										// 指定プールバッファのユニット管理情報のチェック
	for( iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{
//		DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop Count=%d 回目 \n", D_PROC_NAME, (iLoopCnt+1)));

		os_trcget2( D_MD_OSFRPBF, D_MM_OSFRPBF, 1,bufp[iLoopCnt] );
										// プールバッファ管理テーブル個別部の取得
		ptPbIndAdr = *((TEpbcTableInd **)((void *)bufp[iLoopCnt] - 4));

/***********************************************/

		DbgMsg01(DLv04, (OutPut, "***** %s:bufp = %#08lx \n", D_PROC_NAME, bufp[iLoopCnt]));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr = %#08lx \n", D_PROC_NAME, ptPbIndAdr));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->pvUnitAdr = %#08lx \n", D_PROC_NAME,
				ptPbIndAdr->pvUnitAdr));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->lUsePid = %ld \n", D_PROC_NAME,
				ptPbIndAdr->lUsePid));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->lGetPid = %ld \n", D_PROC_NAME,
				ptPbIndAdr->lGetPid));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->cUnit = %#02lx \n", D_PROC_NAME,
				ptPbIndAdr->cUnit));

		DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid = %ld \n", D_PROC_NAME, lMyPid));
/***********************************************/
												// 20030115 修正

		if( ptPbIndAdr->cUnit != D_UNITINFO_GET )
		{								// ユニット状態が取得中でない時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEALRD ) );
			lRet = OSEEALRD;			// OSEEALRDを設定
			goto err_osfrpbf;			// エラー処理へ遷移
		}

										// 使用プロセスIDと取得プロセスIDが共に自プロセスIDでない時
		//if( (ptPbIndAdr->lGetPid != lMyPid) && (ptPbIndAdr->lUsePid != lMyPid) )
												// 20030226 SSLA0013 仕様変更
		if( ptPbIndAdr->lUsePid != lMyPid )
		{
//			DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->lGetPid = %lx \n", D_PROC_NAME,
//					ptPbIndAdr->lGetPid ) );
//			DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->lUsePid = %lx \n", D_PROC_NAME,
//					ptPbIndAdr->lUsePid ) );
//			DbgMsg01( DLv04, ( OutPut, "***** %s:lMyPid = %lx \n", D_PROC_NAME, lMyPid ) );
//			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENFND ) );
			lRet = OSEENFND;			// OSEENFNDを設定
			goto err_osfrpbf;			// エラー処理へ遷移
		}

	}

	for( iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// 指定プールバッファの解放
		ptPbIndAdr = *((TEpbcTableInd **)((void *)bufp[iLoopCnt] - 4));
										// プールバッファ管理テーブル個別部の取得
		ptPbIndAdr->cUnit = D_UNITINFO_RELEASE;
										// ユニット状態を解放にする。
		ptPbIndAdr->lGetPid = D_PID_NONE;
										// 取得プロセスIDをクリアする。
		ptPbIndAdr->lUsePid = D_PID_NONE;
										// 使用プロセスIDをクリアする。
		if( ptBpIndAdr->tPbInfo.ptNxtAdr == D_ADDRESS_NONE )
		{								// 空きユニットが存在しない時
			DbgMsg01(DLv04, (OutPut, "***** %s: UNIT NASI\n", D_PROC_NAME ));
			ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndAdr;
										// プールバッファ管理情報の次アドレスに解放した個別部を設定
			ptBpIndAdr->tPbInfo.ptBefAdr = (void *)ptPbIndAdr;
										// プールバッファ管理情報の前アドレスに解放した個別部を設定
			ptPbIndAdr->ptNxtAdr = (void *)ptBpIndAdr;
										// 解放した個別部の次アドレスにプールバッファ個別部の
										// アドレスを設定
			ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// 解放した個別部の前アドレスにプールバッファ個別部の
										// アドレスを設定
		}
		else							// 空きユニットが存在する時
		{
			DbgMsg01(DLv04, (OutPut, "***** %s: UNIT ARI\n", D_PROC_NAME ));
			ptPbIndAdr->ptNxtAdr = ptBpIndAdr->tPbInfo.ptNxtAdr;
										// 解放した個別部の次アドレスにプールバッファ管理情報の
										// 次アドレスを設定
			ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// 解放した個別部の前アドレスにプールバッファ個別部の
										// アドレスを設定
			((TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptNxtAdr)->ptBefAdr = (void *)ptPbIndAdr;
										// 解放した個別部の次アドレスが指す個別部の前アドレスに
										// 解放した個別部を設定
			ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndAdr;
										// プールバッファ管理情報の次アドレスに解放した個別部を設定
		}
		++(ptBpIndAdr->lEmpUnitNum);	// 空きユニット数をインクリメント
		--(ptBpIndAdr->lGetEPBCNum);	// プールバッファ取得数のデクリメント
	}

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック解除
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 2, -1 , errno );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSFRPBF << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s: ID:%08lx ALL:%ld EMP:%ld GET:%ld\n", D_PROC_NAME,
			ptBpIndAdr->lPoolId,ptBpIndAdr->lMaxUnitNum, 
                        ptBpIndAdr->lEmpUnitNum, ptBpIndAdr->lGetEPBCNum ) );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSFRPBF, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );					// NORMALを返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_osfrpbf:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプール個別部のロック解除
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 2, -1 , errno );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCONN << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}
	
	os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, lRet );
	return( lRet );						// エラー値を返却
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
