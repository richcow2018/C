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
/* ＜サービス項目名＞              ファイル／ディレクトリの操作             */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                ファイルへのリンク                       */
/* ＜モジュールＩＤ＞              oslink                                   */
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
/*   ファイルへのリンク                                                     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long oslink( char *path1, char *path2 )                             */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      char         *path1              既存ファイルパス名                 */
/*      char         *path2              新たに与えるパス名                 */
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
#include <unistd.h>                     // link用
#include <sys/stat.h>                   // stat用
#include <string.h>						// デバッグ用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "oslink.h"
#include "oslink_ins.h"                // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    oslink                                                    */
/*                                                                          */
/*  ＜機能概要＞  ファイルへのリンク                                        */
/*                                                                          */
/****************************************************************************/
long oslink( char *path1, char *path2 )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    int iCommonRet;                     // 共通関数の返却値
    struct stat tStatBuf;               // stat用バッファ

	os_trcget2( D_MD_OSLINK, D_T_TRA_IN, 2, path1, path2 );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OSLINK, D_T_SYS_STAT, 2, path1, &tStatBuf );
    iCommonRet = stat( path1, &tStatBuf ); 
                                        // ファイルの状態を取得する
	os_trcget2( D_MD_OSLINK, D_T_SYS_END, 1, iCommonRet );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );
    												
    if( iCommonRet == D_ERR_SYS )       // 取得に失敗した時
    {
        goto err_oslink_stat;
    }

    if( !S_ISREG(tStatBuf.st_mode) )    // 通常ファイルかチェック
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    												D_PROC_NAME, OSFEPATHDR ) );
		os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
        return( OSFEPATHDR );
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSLINK, D_T_SYS_LINK, 2, path1, path2 );
    iCommonRet = link( path1, path2 );  // リンクの作成
	os_trcget2( D_MD_OSLINK, D_T_SYS_END, 1, iCommonRet );
    
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );
    if( iCommonRet == D_ERR_SYS )       // 作成失敗時
    {
        goto err_oslink;
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSLINK, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // 正常値返却

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_oslink_stat:
    switch( errno )
    {
        case ENOENT:
        case ENOTDIR:
        case ELOOP:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATHDR, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
            return( OSFEPATHDR );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATH );
            return( OSFEPATH );
            break;

        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSLINK << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
   
err_oslink:
    switch( errno )
    {
        case EXDEV:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFELINK, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFELINK );
            return( OSFELINK );
            break;

        case EFAULT:
        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATH );
            return( OSFEPATH );
            break;

        case ENOMEM:
        case ENOSPC:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFERDVC, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFERDVC );
            return( OSFERDVC );
            break;

        case EEXIST:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEDUPFIL, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEDUPFIL );
            return( OSFEDUPFIL );
            break;

        case EPERM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATHDR, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
            return( OSFEPATHDR );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSLINK << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
