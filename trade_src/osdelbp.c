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
/* ＜モジュール名＞					 バッファプールの削除										*/
/* ＜モジュールＩＤ＞				 osdelbp													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ五味）			*/
/* ＜ソース作成年月日＞ 			 ２００２年１０月０９日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７６）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 バッファプールの削除																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osdelbp.h>																	*/
/*																								*/
/*	   	long	osdelbp( long poolid )															*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	poolid;			プール識別子													*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			NORMAL																*/
/*		異常終了			-1																	*/
/*							OSEEWKEX															*/
/*							semopの返却値														*/
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
#include <errno.h>
#include "osdelbp.h"
#include "os_trcget.h"
#include "osdelbp_ins.h"				// 内部参照用（個別）
#include "os_GetEbpcTableInd_ins.h"		// 内部参照用（個別）

/****************************************************************************/
/* 機能：バッファプールの削除                                               */
/* 作成日：2002年10月9日                                                    */
/* 変更日：                                                                 */
/* 作成者：五味                                                             */
/* 呼出形式：                                                               */
/*   long osdelbp( long poolid )                                            */
/*     long poolid         プール識別子                                     */
/*                                                                          */
/****************************************************************************/
long osdelbp( long poolid )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// セマフォ構造体
	int iRet;							// 返却値
	int iLoopCnt;						// ループカウンタ
	long lRet;							// 返却値
	long lBpSize;						// バッファプールサイズ
	long lPbSize;						// プールバッファサイズ
	void *pvBpAdr;						// バッファプールアドレス
	void *pvPbAdr;						// プールバッファアドレス
	TEbpcTableInd *ptBpIndAdr;			// バッファプール管理テーブル個別部のアドレス
	TEsbpTableInd *ptEsbpIndTopAdr;		// 空バッファプール管理テーブル個別部の先頭アドレス
	TEsbpTableInd *ptEsbpIndBpAdr;		// 空バッファプール管理テーブル個別部のアドレス（BP用）
	TEsbpTableInd *ptEsbpIndPbAdr;		// 空バッファプール管理テーブル個別部のアドレス（PB用）
	

	os_trcget2( D_MD_OSDELBP, D_T_TRA_IN, 1, poolid  );

	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:poolid:%08lx \n", D_PROC_NAME, poolid ) );


	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
	for( ; ; )
	{
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック
										
		if( iRet == D_ERR_SYS )
		{								// ロックできなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					                                                 
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, errno );
					                                                 
	        		return( OSEEWKEX );	// OSEEWKEXを返却
	        }
		}
		else							// バッファプールアクセスのロック成功
		{
			break;						// 処理を抜ける
		}
	}
	os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 1, iRet );

	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// バッファプール管理テーブルから対象個別部アドレスの取得
	if( lRet != NORMAL )				// 対象個別部のアドレスの取得に失敗した時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%08lx \n", D_PROC_NAME, lRet ) );
		
		goto err_osdelbp;				// エラー処理へ遷移
	}

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// 作成状態が作成済でない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		lRet = OSEENEXS;				// OSEENEXSを設定
		
		goto err_osdelbp;				// エラー処理へ遷移
	}

	if( ptBpIndAdr->lPoolId != poolid )	// プール識別子が対象個別部のプール識別子と一致しない時
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		lRet = OSEENEXS;				// OSEENEXSを設定
		
		goto err_osdelbp;				// エラー処理へ遷移
	}

	if( ptBpIndAdr->lMaxUnitNum != ptBpIndAdr->lEmpUnitNum )
	{									// 空きユニット数とユニット数が一致しない時
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEUSED ) );
		lRet = OSEEUSED;				// OSEEUSEDを設定
		
		goto err_osdelbp;				// エラー処理へ遷移
	}

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	pvBpAdr = ptBpIndAdr->pvEbpcAdr;	// バッファプールアドレスの取得
	lBpSize = ptBpIndAdr->lMaxUnitNum * (ptBpIndAdr->lUnitSize + D_UNITHEAD_SIZE);
										// バッファプールサイズの算出
	pvPbAdr = ptBpIndAdr->tPbInfo.ptEpbcAdr;
										// プールバッファアドレスの取得
	lPbSize = ptBpIndAdr->tPbInfo.lPoolSize;
										// プールバッファサイズの算出
	ptEsbpIndTopAdr = (void *)ptEsbp + sizeof(TEsbpTable);
										// 空バッファプール管理テーブル個別部の先頭アドレスの取得

	ptEsbpIndBpAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// すべての空きバッファプール管理テーブル個別部に対して処理
		if( ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr == (pvBpAdr + lBpSize) )
		{								// 空き領域アドレスがバッファプールアドレスの後方アドレスと
										// 一致する個別部が見つかった時
			ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
			break;						// ループから抜ける
		}
	}
	if( ptEsbpIndBpAdr == D_ADDRESS_NONE )
										//  空き領域がある個別部が見つからなかった時
	{
		for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
		{								// 未使用の個別部の検索
			if( ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr == (TEsbpTableInd *)D_EMPBPADR_NOUSE )
			{							// 未使用の個別部が見つかった時
				ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
				break;					// ループから抜ける
			}
		}
		if( ptEsbpIndBpAdr != D_ADDRESS_NONE )
		{								// 未使用の個別部が見つかった時
			ptEsbpIndBpAdr->pvEmpBpAdr = pvBpAdr;
										// バッファプール空き領域開始アドレスの取得
			ptEsbpIndBpAdr->lEmpBpSize = lBpSize;
										// バッファプールサイズの取得
		}
		else							// 未使用の個別部が見つからなかった時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS );
			//return( -1 );				// -1を返却（アボート予定）
		}
	}
	else
	{
		ptEsbpIndBpAdr->pvEmpBpAdr = pvBpAdr;
										// バッファプール空き領域開始アドレスに、
										// バッファプールアドレスを設定
		ptEsbpIndBpAdr->lEmpBpSize += lBpSize;
										// バッファプール空き領域サイズに、
										// バッファプールサイズを加算
		for( ; ; )						// 結合できる空き領域がなくなるまで繰り返す
		{
			for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
			{							// 結合できる空き領域の検索
				if( (ptEsbpIndBpAdr->pvEmpBpAdr
						+ ptEsbpIndBpAdr->lEmpBpSize) == ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr )
				{						// 結合元個別部の後方アドレスが空き領域のバッファプール
										// アドレスと一致する個別部が見つかった時
					ptEsbpIndBpAdr->lEmpBpSize += ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize;
										// 結合元個別部のサイズに見つかった個別部のサイズを加算
					ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr = (TEsbpTableInd *)D_EMPBPADR_NOUSE;
										// 見つかった個別部のアドレスをクリア
					ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize = D_EMPBPSIZE_NOUSE;
										// 見つかった個別部のサイズをクリア
					break;				// ループから抜ける
				}
			}
			if( iLoopCnt == ptEbpc->lMaxNum )
			{							// 結合できる空き領域が見つからなかった時
				break;					// ループを抜ける
			}
		}
	}

	ptEsbpIndPbAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// すべての空きバッファプール管理テーブル個別部に対して処理
		if( ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr == (pvPbAdr + lPbSize) )
		{								// 空き領域アドレスがプールバッファアドレスの後方アドレスと
										// 一致する個別部が見つかった時
			ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
			break;						// ループから抜ける
		}
	}

	if( ptEsbpIndPbAdr == D_ADDRESS_NONE )
										//  空き領域がある個別部が見つからなかった時
	{
		for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
		{								// 未使用の個別部の検索
			if( ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr == (void *)D_EMPPBADR_NOUSE )
			{							// 未使用の個別部が見つかった時
				ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// 見つかった個別部を取得
				break;					// ループから抜ける
			}
		}
		if( ptEsbpIndPbAdr != D_ADDRESS_NONE )
		{								// 未使用の個別部が見つかった時
			ptEsbpIndPbAdr->pvEmpEpbcAdr = pvPbAdr;
										// プールバッファ管理空き領域開始アドレスの取得
			ptEsbpIndPbAdr->lEmpEpbcSize = lPbSize;
										// プールバッファサイズの取得
		}
		else							// 未使用の個別部が見つからなかった時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS1);
			//return( -1 );				// -1を返却（アボート予定）
		}
	}
	else
	{
		ptEsbpIndPbAdr->pvEmpEpbcAdr = pvPbAdr;
										// プールバッファ管理空き領域開始アドレスに、
										// プールバッファアドレスを設定
		ptEsbpIndPbAdr->lEmpEpbcSize += lPbSize;
										// プールバッファ管理空き領域サイズに、
										// プールバッファサイズを加算
		for( ; ; )						// 結合できる空き領域がなくなるまで繰り返す
		{
			for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
			{							// 結合できる空き領域の検索
				if( (ptEsbpIndBpAdr->pvEmpEpbcAdr
						+ ptEsbpIndBpAdr->lEmpEpbcSize) == ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr )
				{						// 結合元個別部の後方アドレスが空き領域のプールバッファ
										// アドレスと一致する個別部が見つかった時
					ptEsbpIndBpAdr->lEmpEpbcSize += ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize;
										// 結合元個別部のサイズに見つかった個別部のサイズを加算
					ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr = (TEsbpTableInd *)D_EMPBPADR_NOUSE;
										// 見つかった個別部のアドレスをクリア
					ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize = D_EMPBPSIZE_NOUSE;
										// 見つかった個別部のサイズをクリア
					break;				// ループから抜ける
				}
			}
			if( iLoopCnt == ptEbpc->lMaxNum )
			{							// 結合できる空き領域が見つからなかった時
				break;					// ループを抜ける
			}
		}
	}

	ptBpIndAdr->cStat				= D_STAT_NOTCREATED;
	ptBpIndAdr->pvEbpcAdr			= D_ADDRESS_NONE;
	ptBpIndAdr->lMaxUnitNum			= 0;
	ptBpIndAdr->lEmpUnitNum			= 0;
	ptBpIndAdr->lUnitSize			= 0;
	ptBpIndAdr->lAccess				= 0;
	ptBpIndAdr->lGid				= 0;
	ptBpIndAdr->lGetEPBCNum			= 0;
	ptBpIndAdr->tPbInfo.ptNxtAdr	= D_ADDRESS_NONE;
	ptBpIndAdr->tPbInfo.ptBefAdr	= D_ADDRESS_NONE;
	ptBpIndAdr->tPbInfo.lPoolSize	= 0;
	ptBpIndAdr->tPbInfo.ptEpbcAdr	= D_ADDRESS_NONE;
										// バッファプール管理テーブルの更新（クリア）

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック解除
		os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS2);
					return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSDELBP, D_T_TRA_OUT, 1, NORMAL  );
	return( NORMAL );					// NORMALを返却

/****************************************************************************/
/* 異常処理                                                                 */
/****************************************************************************/
err_osdelbp:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
	for( ; ; )
	{
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// バッファプールアクセスのロック解除
		os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ロック解除できなかった時
			switch( errno )
			{
				case EINTR:				// EINTRの時
					break;				// リトライ
					
				default:				// その他の時
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS3);
					//return( -1 );		// -1を返却（アボート処理を予定）
	        }
		}
		else							// バッファプールアクセスのロック解除成功
		{
			break;						// 処理を抜ける
		}
	}

	os_trcget2( D_MD_OSDELBP, D_T_ERR_PRA, 1, lRet );

	return( lRet );						// エラー値を返却
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
