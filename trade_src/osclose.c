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
/* ＜サービス項目名＞				 ファイル管理												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ファイルのクローズ											*/
/* ＜モジュールＩＤ＞				 osclose													*/
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
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７１）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 ファイルのクローズ																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osclose.h>																	*/
/*																								*/
/*		long	osclose( long fildes )															*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long fildes;			ファイル記述子													*/
/*								「0 < ファイル記述子 <=ファイル管理テーブルの管理部個別部数」	*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了 		-1 																		*/
/*						OSFEFILDES																*/
/*						lCommmonRet																*/
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
#include <errno.h>                      // エラーＮｏ取得用
#include <stdio.h>                      // osclose用　fflush用　fileno用
#include <unistd.h>                     // fsync用
#include <string.h>						// デバッグ用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osclose.h"
#include "osclose_ins.h"                // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osclose　                                                 */
/*                                                                          */
/*  ＜機能概要＞  ファイルをクローズする                                    */
/*                                                                          */
/****************************************************************************/
long osclose( long fildes )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部
    long lCommonRet;                    // 共通関数リターン値
    int iFilDes;                        // ファイルディスクプリタ
    int iFcloseRet;                     // fcloseの返却値
    
	os_trcget2( D_MD_OSCLOSE, D_T_TRA_IN, 1, fildes );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );

    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileOpen( fildes );
                                        // オープン中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );

    if( lCommonRet != NORMAL )          // オープン中でない時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // コネクト中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );

    if( lCommonRet != NORMAL )          // コネクトエラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );


/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FFLUSH, 1, ptTEflcTableInd->pFilStm );    
	fflush( ptTEflcTableInd->pFilStm ); // バッファリングされている内容を
                                        // ディスクに書込む
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// ファイルストリームから
                                        // ファイルディスクプリタを取得する
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 1, iFilDes );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=%d )\n",
    												D_PROC_NAME, iFilDes ) );


    if( iFilDes == D_ERR_SYS )          // 取得に失敗があった時
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fileno", strerror(errno) ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 2, -1 , errno );
		
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCLOSE << 16) | D_T_ERR_SYS );
        //return( -1 );                   // アボード処理
    }

	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FSYNC, 1, iFilDes );
    fsync( iFilDes );                   // バッファリングされている内容が
                                        // ディスクへ書き込まれるまで待つ
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 0 );
                                        
    for(;;)                             // errno がEINTRの間、繰り返す
    {
		os_trcget2( D_MD_OSCLOSE, D_T_SYS_FCLOSE, 1, ptTEflcTableInd->pFilStm );
        iFcloseRet = fclose( ptTEflcTableInd->pFilStm );
        								// ファイルをクローズする
		os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 2, iFcloseRet, errno );
        								
     	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFcloseRet=%d )\n",
    												D_PROC_NAME, iFcloseRet ) );

        if( iFcloseRet == D_CLOSE_OK )  // ファイルクローズ成功
        {
            break;
        }
        
        if( errno != EINTR )            // errno がEINTRでない時
        {
            goto err_osclose;
        }
    }         

    ptTEflcTableInd->pFilStm = NULL;	// ファイル管理テーブルをクリアする
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd->pFilStm=%p )\n",
    													D_PROC_NAME, ptTEflcTableInd->pFilStm ) );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSCLOSE, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // 正常値返却

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_osclose:
    switch( errno )
    {
/*****  障害対応（TBCS0271）    Start                                   修正日：2003.08.11  *****/
//        case EBADF:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, OSFEFILDES, "fclose", strerror(errno) ) );
//			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, OSFEFILDES );
//            return( OSFEFILDES );
//            break;
/*****  障害対応（TBCS0271）    End                                     修正日：2003.08.11  *****/
            
        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSIDKE | OSIZZEDVC, "fclose", strerror(errno) ) );
			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, OSIDKE | OSIZZEDVC );
            return( OSIDKE | OSIZZEDVC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fclose", strerror(errno) ) );
			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCLOSE << 16) | D_T_ERR_SYS1);
			//return( -1 );               // バスエラー処理
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
