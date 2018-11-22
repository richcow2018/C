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
/* ＜サービス項目名＞				 実行管理													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ＬＭバッファプールの作成									*/
/* ＜モジュールＩＤ＞				 oscrelbp													*/
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
/* 作成者：五味                                                             */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年10月3日                                                    */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 ＬＭバッファプールの作成 																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscrelbp.h>																*/
/*																								*/
/*	   	long	oscrelbp( long poolid, long size, long unit, long access ) 						*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	poolid;		プール識別子														*/
/*		long	size;		プールバッファ個数												*/
/*		long	unit		ユニットサイズ														*/
/*		long	access;		アクセス権															*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEWKEX																*/
/*						semopの返却値															*/
/*						-1																		*/
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
#include "oscrelbp.h"
#include "os_trcget.h"
#include "oscrelbp_ins.h"				// 内部参照用（個別）
#include "os_GetEbpcTableInd_ins.h"		// 内部参照用（個別）

/****************************************************************************/
/* 機能：ＬＭバッファプールの作成                                           */
/* 作成日：2002年10月3日                                                    */
/* 変更日：                                                                 */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long oscrelbp( long poolid, long size, long unit, long access )        */
/*     long poolid         プール識別子                                     */
/*     long size           プールバッファ個数                               */
/*     long unit           ユニットサイズ                                   */
/*     long access         アクセス権                                       */
/*                                                                          */
/****************************************************************************/
long oscrelbp( long poolid, long size, long unit, long access )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// セマフォ構造体
	int iRet;							// 返却値
	int iLoopCnt;						// ループカウンタ
	long lRet;							// 返却値
	long lUnitSize;						// ユニットサイズ
	long lNeedBpSize;					// 必要バッファプールサイズ
	long lNeedPbSize;					// 必要プールバッファサイズ
	void *pvBpAdr;						// バッファプールアドレス
	TEbpcTableInd *ptBpIndAdr;			// バッファプール管理テーブル個別部のアドレス
	TEsbpTableInd *ptEsbpIndTopAdr;		// 空バッファプール管理テーブル個別部の先頭アドレス
	TEsbpTableInd *ptEsbpIndBpAdr;		// 空バッファプール管理テーブル個別部のアドレス（BP用）
	TEsbpTableInd *ptEsbpIndPbAdr;		// 空バッファプール管理テーブル個別部のアドレス（PB用）
	TEpbcTableInd *ptPbIndTopAdr;		// プールバッファ管理テーブル個別部の先頭アドレス
	TEpbcTableInd *ptPbIndAdr;			// プールバッファ管理テーブル個別部のアドレス
	
	
	os_trcget2( D_MD_OSCRELBP, D_T_TRA_IN, 4, poolid, size, unit, access );

	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:poolid : %08lx \n", D_PROC_NAME, poolid));
	DbgMsg01( DLv04, ( OutPut, "***** %s:size   : %ld \n", D_PROC_NAME, size));
	DbgMsg01( DLv04, ( OutPut, "***** %s:unit   : %ld \n", D_PROC_NAME, unit));
	DbgMsg01( DLv04, ( OutPut, "***** %s:access : %lx \n", D_PROC_NAME, access));


	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
		
		if( iRet == D_ERR_SYS )
		{								// ロックできなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
																	D_PROC_NAME, OSEEWKEX ) );
																	
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 1, OSEEWKEX );
																	
	        		return( OSEEWKEX );	// OSEEWKEXを返却
	        }
		}
		else							// バッファプールアクセスのロック成功
		{
			break;						// 処理を抜ける
		}
	}

	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// バッファプール管理テーブルから対象個別部アドレスの取得
	if( lRet != NORMAL )				// 対象個別部のアドレスの取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%lx \n", D_PROC_NAME, lRet ) );
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

	if( ptBpIndAdr->cStat != D_STAT_NOTCREATED )
	{									// 作成状態が未作成でない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
		lRet = OSEEEXST;				// OSEEEXSTを設定
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

	if( (size < D_SIZE_MIN) || (size > D_SIZE_MAX) )
	{									// バッファプールサイズが範囲外である時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISIZ ) );
		lRet = OSEEISIZ;				// OSEEISIZを設定
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

	if( (unit < D_UNIT_MIN) || (unit > D_UNIT_MAX) )
	{									// ユニットサイズが範囲外である時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIUNI ) );
		lRet = OSEEIUNI;				// OSEEIUNIを設定
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

										// ユニットサイズを切り上げ
	lUnitSize = ((long)((unit + D_ROUND_UNIT - 1) / D_ROUND_UNIT)) * D_ROUND_UNIT;
										// 必要バッファプールサイズの算出
	lNeedBpSize = size * (lUnitSize + D_UNITHEAD_SIZE);

	DbgMsg01( DLv04, ( OutPut, "***** %s:llUnitSize :%ld \n", D_PROC_NAME, lUnitSize ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:lNeedBpSize:%ld \n", D_PROC_NAME, lNeedBpSize ) );

										// 空バッファプール管理テーブル個別部の先頭アドレスの取得
	ptEsbpIndTopAdr = (void *)ptEsbp + sizeof(TEsbpTable);
	ptEsbpIndBpAdr = D_ADDRESS_NONE;

										// バッファプールに必要な空き領域がある個別部を検索
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{
		DbgMsg01( DLv04, ( OutPut, "***** %s:iLoopCnt:%d 回目 \n", D_PROC_NAME, (iLoopCnt+1) ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr:%08lx \n",
				D_PROC_NAME, ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize:%ld \n",
				D_PROC_NAME, ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize ) );

		if( ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize >= lNeedBpSize )
		{								//  空き領域がある個別部が見つかった時
			ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
			break;						// ループから抜ける
		}
	}
	if( ptEsbpIndBpAdr == D_ADDRESS_NONE )
	{									//  空き領域がある個別部が見つからなかった時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function 01:%x\n", D_PROC_NAME, OSEEINSF ) );
		lRet = OSEEINSF;				// OSEEINSFを設定
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

	lNeedPbSize = sizeof(TEpbcTableInd) * size;
										// 必要プールバッファサイズの算出
	ptEsbpIndPbAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// プールバッファに必要な空き領域がある個別部を検索
		if( ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize >= lNeedPbSize )
		{								//  空き領域がある個別部が見つかった時
			ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
			break;						// ループから抜ける
		}
	}
	if( ptEsbpIndPbAdr == D_ADDRESS_NONE )
	{									//  空き領域がある個別部が見つからなかった時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function 02:%x\n", D_PROC_NAME, OSEEINSF ) );
		lRet = OSEEINSF;				// OSEEINSFを設定
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// エラー処理へ遷移
	}

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	ptBpIndAdr->cStat				= D_STAT_CREATED;
	ptBpIndAdr->pvEbpcAdr			= ptEsbpIndBpAdr->pvEmpBpAdr;
	ptBpIndAdr->lMaxUnitNum			= size;
	ptBpIndAdr->lEmpUnitNum			= size;
	ptBpIndAdr->lUnitSize			= lUnitSize;
	ptBpIndAdr->lAccess				= access;
	ptBpIndAdr->lGid				= getpgrp();
	ptBpIndAdr->lGetEPBCNum			= 0;
	ptBpIndAdr->tPbInfo.ptNxtAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr;
	ptBpIndAdr->tPbInfo.ptBefAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr
										+ sizeof(TEpbcTableInd) * (size - 1);
	ptBpIndAdr->tPbInfo.lPoolSize	= lNeedPbSize;
	ptBpIndAdr->tPbInfo.ptEpbcAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr;
										// バッファプール管理テーブルの更新

	pvBpAdr = ptBpIndAdr->pvEbpcAdr;	// バッファプールアドレスの取得
	ptPbIndTopAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptEpbcAdr;
										// プールバッファ管理テーブル個別部の先頭アドレス取得
	for( iLoopCnt = 0; iLoopCnt < size; iLoopCnt++ )
	{									// すべてのプールバッファ管理テーブル個別部に対して処理
		ptPbIndAdr = ptPbIndTopAdr + iLoopCnt;
										// プールバッファ管理テーブル個別部アドレスの取得

		*((TEpbcTableInd **)pvBpAdr) = ptPbIndAdr;
										// ユニット管理情報に個別部アドレスを設定
		pvBpAdr += D_UNITHEAD_SIZE;		// プールバッファ領域アドレスの取得

		(TEpbcTableInd *)ptPbIndAdr->ptNxtAdr	= ptPbIndAdr + 1;
		(TEpbcTableInd *)ptPbIndAdr->ptBefAdr	= ptPbIndAdr - 1;
		ptPbIndAdr->lGetPid						= D_PID_NONE;
		ptPbIndAdr->lUsePid						= D_PID_NONE;
		ptPbIndAdr->cUnit						= D_UNITINFO_RELEASE;
		ptPbIndAdr->pvUnitAdr					= pvBpAdr;
										// プールバッファ管理テーブル個別部の更新

		pvBpAdr += lUnitSize;			// プールバッファ領域の最後尾アドレスの取得
	}
	ptPbIndAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptNxtAdr;
	ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// 先頭個別部の前アドレスの更新
	ptPbIndAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptBefAdr;
	ptPbIndAdr->ptNxtAdr = (void *)ptBpIndAdr;
										// 最終個別部の次アドレスの更新

	ptEsbpIndBpAdr->pvEmpBpAdr += lNeedBpSize;
										// バッファプール空き領域開始アドレスに、
										// 必要バッファプールサイズを加算
	ptEsbpIndBpAdr->lEmpBpSize -= lNeedBpSize;
										// バッファプール空き領域サイズから、
										// 必要バッファプールサイズを減算
	(void *)ptEsbpIndPbAdr->pvEmpEpbcAdr += lNeedPbSize;
										// プールバッファ管理空き領域開始アドレスに、
										// 必要プールバッファサイズを加算
	ptEsbpIndPbAdr->lEmpEpbcSize -= lNeedPbSize;
										// プールバッファ管理空き領域サイズから、
										// 必要プールバッファサイズを減算

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック解除
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
		
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 2, -1 , errno );
					
	        		return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSCRELBP, D_T_TRA_OUT, 1, NORMAL  );
	
	return( NORMAL );					// NORMALを返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_oscrelbp:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック解除
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 2, -1 , errno );
					
	        		return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 1, lRet );
	
	return( lRet );						// エラー値を返却
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
