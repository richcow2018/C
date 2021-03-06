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
/* ＜モジュール名＞                強制書出し（全ファイル）                 */
/* ＜モジュールＩＤ＞              ossync                                   */
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
/*   メモリ内情報のディスクへの書込み                                       */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long ossync( char *path, long mflag  )                              */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      char        *path               特殊ファイルを示すパス名            */
/*                                        (使用しない)                      */
/*      long        mflag               書込み後のメモリ有効／無効フラグ    */
/*                                        (使用しない)                      */
/*                                                                          */
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
#include <errno.h>                      // エラーＮｏ取得用
#include <stdio.h>                      // 
#include <unistd.h>                     // fsync用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "ossync.h"
#include "ossync_ins.h"                 // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    ossync                                                    */
/*                                                                          */
/*  ＜機能概要＞  メモリ内情報のディスクへの書込み                          */
/*                                                                          */
/****************************************************************************/
long ossync( char *path, long mflag )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	os_trcget2( D_MD_OSSYNC, D_T_TRA_IN, 2, path, mflag );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSSYNC, D_T_SYS_SYNC, 0 );
    sync();                             // メモリ内情報のディスクへの書込み
	os_trcget2( D_MD_OSSYNC, D_T_SYS_END, 0 );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSSYNC, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // 正常値返却

}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
