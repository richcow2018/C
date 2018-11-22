/****************************************************************************/
/*  著作権  ２００２                                                        */
/*            株式会社ＮＴＴデータ                                          */
/*              金融ビジネス事業本部                                        */
/*                                                                          */
/*                                                                          */
/*  収容物  ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ              */
/****************************************************************************/
/* ＜対象業務名＞                  ＴＲＡＤＥエミュレータ                   */
/* ＜対象業務ＩＤ＞                ＴＲＥ                                   */
/* ＜サービス項目名＞              ファイル／ディレクトリ操作               */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                ファイル領域の切り捨て                   */
/* ＜モジュールＩＤ＞              ostrunc                                  */
/* ＜モジュール通番＞                                                       */
/*--------------------------------------------------------------------------*/
/* ＜適用機種名＞                  汎用サーバ                               */
/* ＜適用ＯＳ＞                    Ｌｉｎｕｘ                               */
/* ＜開発環境＞                    ＲＨＡＳ２．１                           */
/* ＜記述言語＞                    Ｃ言語                                   */
/* ＜モジュール形態＞              関数                                     */
/* ＜機能区分＞                                                             */
/* ＜対象データ＞                                                           */
/* ＜工程・階層区分＞                                                       */
/*--------------------------------------------------------------------------*/
/* ＜開発システム名＞              ＬＡＬａ−ＳＭＰシステム                 */
/* ＜開発システム番号＞            ＰＰ４０Ｂ００１２２０                   */
/*--------------------------------------------------------------------------*/
/* ＜開発担当名＞                  ＣＢ事ビジネス企画担当(メ−カ：サプライ) */
/* ＜電話番号＞                    148-1457(03-5437-1457)                   */
/*--------------------------------------------------------------------------*/
/* ＜設計者名＞                    ＣＢ事ビジネス企画担当                   */
/* ＜設計年月日＞                  ２００２年　９月２７日                   */
/* ＜設計修正者名＞                                                         */
/* ＜設計修正年月日及び修正ＩＤ＞                                           */
/*--------------------------------------------------------------------------*/
/* ＜ソース作成者＞                ＣＢ事ビジネス企画担当(メ−カ:ＸＸＸＸ)  */
/* ＜ソース作成年月日＞            ２００２年　１１月０１日                 */
/* ＜ソース修正者＞                                                         */
/* ＜ソース正年月日及び修正ＩＤ＞                                           */
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞              ステップ                                 */
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞                                                             */
/*   ファイル領域の切り捨て                                                 */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long ostrunc( long fildes )                                         */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      long        fildes              ファイル記述子                      */
/*                                      「0 < ファイル記述子 <=             */
/*                                              ファイル管理テーブルの      */
/*                                                         管理部個別部数」 */
/*                                                                          */
/* ＜返却値＞                                                               */
/*     0L                                                                   */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜入出力データ構造＞                                                     */
/* ＜制限事項＞                                                             */
/*     特になし                                                             */
/* ＜使用外部モジュールＩＤ＞                                               */
/* ＜呼出元のモジュールＩＤ＞                                               */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/******************************** 標準ヘッダ・ファイル **********************/
#include <errno.h>                      // エラーＮｏ取得用
#include <stdio.h>                      // 
#include <unistd.h>                     // ftruncate用
#include <string.h>						// デバッグ用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "ostrunc.h"
#include "ostrunc_ins.h"                // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    ostrunc                                                   */
/*                                                                          */
/*  ＜機能概要＞  ファイル領域の切り捨て                                    */
/*                                                                          */
/****************************************************************************/
long ostrunc( long fildes )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部

    long lCommonRet;                    // 共通関数リターン値
    int  iCommonRet;                    // 共通関数リターン値
    int iFilDes;                        // ファイルディスクプリタ
    long lCurPos;                       // カレントポジション

	os_trcget2( D_MD_OSTRUNC, D_T_TRA_IN, 1, fildes );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
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
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
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
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// カレントポジションを取得する
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 1, lCurPos );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );
    
    if( lCurPos == D_ERR_SYS )          // 取得に失敗した時
    {
        goto err_ostrunc_ftell;
    }

	os_trcget2( D_MD_OSTRUNC, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// ファイルストリームから
                                        // ファイルディスクプリタを取得する
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 2, iFilDes, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=0x%08x )\n",
    												D_PROC_NAME, iFilDes ) );
    												
    if( iFilDes == D_ERR_SYS )          // 取得に失敗した時
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fileno", strerror(errno) ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

    for(;;)                             // errno がEINTRの間、繰り返す
    {
		os_trcget2( D_MD_OSTRUNC, D_T_SYS_FTRUNCATE, 2, iFilDes, lCurPos );
        iCommonRet = ftruncate( iFilDes, lCurPos );
                                        // ファイルの切り捨て
		os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 1, iCommonRet );
                                        
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );

        if( iCommonRet != D_ERR_SYS )   // ファイルの切り捨て成功
        {
            break;
        }

        if( errno != EINTR )
        {
            goto err_ostrunc;
        }
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSTRUNC, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // 正常値返却

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_ostrunc_ftell:
    switch( errno )
    {
        case EBADF:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEOOFB, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEOOFB );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
			//return( -1 );               // アボード処理
   }
   
err_ostrunc:
    switch( errno )
    {
        case EACCES:
        case EROFS:
        case EBADF:
        case EINVAL:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEACC );
            break;

        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, OSIDKE | OSIZZEDVC, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSIDKE | OSIZZEDVC );
            break;

        case EISDIR:
        case ELOOP:
        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEPATH );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFENOFILE );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
