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
/* ＜サービス項目名＞              データ操作                               */
/* ＜サービス項目ＩＤ＞            ＸＸＸＸＸＸＸ                           */
/* ＜モジュール名＞                データ強制書き込み                       */
/* ＜モジュールＩＤ＞              osflush                                  */
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

/*   遅延データの制御書込み                                                 */

/*                                                                          */

/*--------------------------------------------------------------------------*/

/* ＜呼出形式＞                                                             */

/*      long osflush( long fildes, long invalid )                           */

/*                                                                          */

/* ＜仮引数＞                                                               */

/*      long        fildes              ファイル記述子                      */

/*                                      「0 < ファイル記述子 <=             */

/*                                              ファイル管理テーブルの      */

/*                                                         管理部個別部数」 */

/*      long        invalid             ファイル関連情報無効化フラグ        */

/*                                      (使用しない)                        */

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

#include <stdio.h>

#include <string.h>						// デバッグ用



/***************************** 利用者作成ヘッダ・ファイル *******************/

#include "osflush.h"

#include "osflush_ins.h"                // 内部参照用（個別）



/****************************************************************************/

/*                                                                          */

/*  ＜関数名＞    osflush                                                   */

/*                                                                          */

/*  ＜機能概要＞  遅延データの制御書込み                                    */

/*                                                                          */

/****************************************************************************/

long osflush( long fildes, long invalid )

{

/****************************************************************************/

/* 初期処理                                                                 */

/****************************************************************************/

    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部



    long lCommonRet;                    // 共通関数リターン値

    int  iCommonRet;                    // 共通関数リターン値



	os_trcget2( D_MD_OSFLUSH, D_T_TRA_IN, 2, fildes, invalid );



//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );



    lCommonRet = os_CheckFiledes( fildes );

                                        // ファイル記述子のチェック

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",

    												D_PROC_NAME, lCommonRet ) );

    												

    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時

    {

        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",

    												D_PROC_NAME, lCommonRet ) );

		os_trcget2( D_MD_OSFLUSH, D_T_ERR_SYS, 1, lCommonRet );

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

		os_trcget2( D_MD_OSFLUSH, D_T_ERR_SYS, 1, lCommonRet );

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

		os_trcget2( D_MD_OSFLUSH, D_T_ERR_SYS, 1, lCommonRet );

        return( lCommonRet );

    }

    

/****************************************************************************/

/* 本処理                                                                   */

/****************************************************************************/

	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;

                                        // ファイル管理テーブルの対象個別部取得

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",

    												D_PROC_NAME, ptTEflcTableInd ) );

    												

	os_trcget2( D_MD_OSFLUSH, D_T_SYS_FFLUSH, 1, ptTEflcTableInd->pFilStm );

    iCommonRet = fflush( ptTEflcTableInd->pFilStm );

                                        // バッファのフラッシュ

	os_trcget2( D_MD_OSFLUSH, D_T_SYS_END, 1, iCommonRet );

                                        

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",

    												D_PROC_NAME, iCommonRet ) );

    												

    if( iCommonRet == EOF )

    {

        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",

    												D_PROC_NAME, OSEEWKEX ) );

		os_trcget2( D_MD_OSFLUSH, D_T_ERR_SYS, 1, OSEEWKEX );

        return( OSEEWKEX );

    }



//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OSFLUSH, D_T_TRA_OUT, 1, NORMAL );

    return( NORMAL );                   // 正常値返却

}



/*****************************************************************************/

/* End                                                                       */

/*****************************************************************************/

