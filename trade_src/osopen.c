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
/* ＜サービス項目名＞              ファイル／ディレクトリ管理               */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                ファイルのオープン                       */
/* ＜モジュールＩＤ＞              osopen                                   */
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
/* ＜ソース作成年月日＞            ２００２年　９月２７日                   */
/* ＜ソース修正者＞                                                         */
/* ＜ソース正年月日及び修正ＩＤ＞                                           */
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞              ステップ                                 */
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞                                                             */
/*   ＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸ     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long osopen( long fildes, long access, long method,                 */
/*                     long exprsiz, long bsize, long limit )               */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      long        fildes              ファイル記述子                      */
/*                                      「0 < ファイル記述子 <=             */
/*                                              ファイル管理テーブルの      */
/*                                                         管理部個別部数」 */
/*      long        access              アクセスコード                      */
/*                                             0x00000002：読込み           */
/*                                             0x00000004：書込み           */
/*                                             0x00000006：読み書き         */
/*      long        method              アクセス法（使用しない）            */
/*      long        exprsiz             指定レコードサイズ(使用しない)      */
/*      long        bsize               指定ブロックサイズ(使用しない)      */
/*      long        limit               排他オープン競合時最大待ち時間      */
/*                                                        (使用しない)      */
/* ＜返却値＞                                                               */
/*     1L                                                                   */
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
#include <errno.h>                     	// エラーＮｏ取得用
#include <stdio.h>                     	// osopen用
#include <string.h>						// デバッグ用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osopen.h"
#include "osopen_ins.h"                	// 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osopen                                                    */
/*                                                                          */
/*  ＜機能概要＞  ファイルをオープンする。                                  */
/*                                                                          */
/****************************************************************************/
long osopen( long fildes, long access, long method, long exprsiz, 
                                                    long bsize, long limit )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部取得

    long lCommonRet;                    // 共通関数リターン値
    FILE *pFilStm = NULL;               // ファイルポインタ

	os_trcget2( D_MD_OSOPEN, D_T_TRA_IN, 6, fildes, access, 
											method, exprsiz, bsize, limit );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // コネクト中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // コネクトエラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
    if( access & D_FILE_WRITE )			// 書込みモードの時
    {
		os_trcget2( D_MD_OSOPEN, D_T_SYS_FOPEN, 2, ptTEflcTableInd->acFileName, 
																D_CHAR_FILE_RW );
        pFilStm = fopen( ptTEflcTableInd->acFileName, D_CHAR_FILE_RW );
        								// 読書きモードでファイルをオープン
		os_trcget2( D_MD_OSOPEN, D_T_SYS_END, 1, pFilStm );
        								
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );
                                        
    }
    else if( access & D_FILE_READ )		// 読込みモードの時
    {
		os_trcget2( D_MD_OSOPEN, D_T_SYS_FOPEN, 2, ptTEflcTableInd->acFileName, 
															D_CHAR_FILE_READ );
        pFilStm = fopen( ptTEflcTableInd->acFileName, D_CHAR_FILE_READ );
                                        // 読込みモードでファイルをオープン
		os_trcget2( D_MD_OSOPEN, D_T_SYS_END, 1, pFilStm );
                                        
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );
    }
    else								// 上記以外の時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFEACC ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEACC );
        return( OSFEACC );
    }

    if( pFilStm == NULL )               // ファイルオープンエラーの時
    {
        goto err_osopen;
    }

    ptTEflcTableInd->pFilStm = pFilStm;	// ファイル管理テーブルへ
                                        // ファイルストリームを登録する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd->pFilStm=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd->pFilStm ) );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSOPEN, D_T_TRA_OUT, 1, D_RECORD_SIZE );
    return( D_RECORD_SIZE );            // 正常値リターン

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_osopen:
    switch( errno )
    {
        case EACCES:
        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;
        
        case EMFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
            break;  
        
        case ENFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFESFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFESFILRS );
            return( OSFESFILRS );
            break;
    
        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSOPEN << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
