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
/* ＜モジュール名＞                ファイルの生成                           */
/* ＜モジュールＩＤ＞              oscreat                                  */
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
/*   ファイルの生成                                                         */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                             */
/*      long oscreat( char *path, long aflags, long forg, long rorg,        */
/*                    long rsize, long bsize,  long exlen )                 */
/*                                                                          */
/* ＜仮引数＞                                                               */
/*      char        *path               生成対象ファイルパス名              */
/*                                      　先頭文字「／」                    */
/*                                        128文字以内                       */
/*      long        aflags              ファイル属性フラグ（使用しない）    */
/*      long        forg                ファイル編成（使用しない）          */
/*      long        rorg                レコード形式(使用しない)            */
/*      long        rsize               レコードサイズ(１以上)              */
/*      long        bsize               ブロックサイズ(使用しない)          */
/*      long        exlen               初期領域サイズ(１以上)              */
/*                                                                          */
/* ＜返却値＞                                                               */
/*     ファイル記述子                                                       */
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
#include <errno.h>                     // エラーＮｏ取得用
#include <stdio.h>                     // fopen用　fflush用　fileno用
#include <string.h>                    // str用
#include <stdlib.h>                    // 領域確保用
#include <unistd.h>                    // fsync用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "oscreat.h"
#include "oscreat_ins.h"               // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    oscreat                                                   */
/*                                                                          */
/*  ＜機能概要＞  ファイルを生成する。                                      */
/*                                                                          */
/****************************************************************************/
long oscreat( char *path, long aflags, long forg, long rorg, 
                                       long rsize, long bsize,  long exlen )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部

    FILE *pFilStm = NULL;               // ファイルポインタ
    int iFilDes;                        // ファイルディスクプリタ
    int iFilId;                         // ファイル記述子カウント用
    int iStrcmpRet;                     // strcmpの返却値
    char *pcWbuf = NULL;                // 書き込み用エリア
    size_t stStrlenRet;                 // ファイル名の長さ
    int iConect = D_CONECT_FLAG_OFF;    // コネクト中確認変数
    size_t stFwriteRet;                 // fwriteの返却値

	os_trcget2( D_MD_OSCREAT, D_T_TRA_IN, 7, path, aflags, forg, 
												rorg, rsize, bsize, exlen );
    
	DbgMsg01( DLv02, ( OutPut, "***** %s:S Start Function\n", D_PROC_NAME ) );

    if( path[ 0 ] != D_FILE_PASS_SLASH )// 絶対ファイルパスのチェック
                                        // （先頭文字　/　でない時）
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFEPATH );
        return( OSFEPATH );
    }

    stStrlenRet = strlen( path ) + 1;   // ファイルパスのサイズを取得する
                                        // NULLを含む為＋１
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stStrlenRet=%d )\n",
    												D_PROC_NAME, stStrlenRet ) );

    if( stStrlenRet > D_PATH_MAX )
                                        // ファイルパスのチェック（長さ）
                                        // 指定範囲内でない場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPATH );
        return( OSFEPATH );
    }

    if( rsize < D_RECORD_SIZE )         // レコード長のチェック
                                        // (１以上)
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFERSIZE ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFERSIZE );
        return( OSFERSIZE );
    }

    if( exlen < D_EXLEN )               // 初期領域サイズのチェック
                                        // (１以上)
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    												D_PROC_NAME, OSFEFSIZE ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFEFSIZE );
        return( OSFEFSIZE );
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
										// ファイル管理テーブル個別部の先頭アドレス取得
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 );

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( path=%s )\n",
    												D_PROC_NAME, path ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lMaxIndNum=%ld )\n",
    												D_PROC_NAME, ptEflc->lMaxIndNum ) );

                                        // コネクト状態のチェック
                                        // ファイル名がファイル管理テーブルに
                                        // 存在するかチェックする
    for( iFilId = 0; iFilId < ptEflc->lMaxIndNum; iFilId++ )
    {
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilId=%d 回目 )\n", D_PROC_NAME, iFilId));
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( acFileName=%s )\n",
    						D_PROC_NAME, ( ptTEflcTableInd + iFilId )->acFileName ) );

                                        // ファイル名の比較
        iStrcmpRet = strcmp( ( ptTEflcTableInd + iFilId )->acFileName, path );

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStrcmpRet=%d )\n",
    													D_PROC_NAME, iStrcmpRet ) );

        if( iStrcmpRet == D_STR_EQUAL ) // ファイル名一致する時
        {
            if( ( ptTEflcTableInd + iFilId )->pFilStm != NULL )
                                        // ファイルストリームがファイル管理
                                        // テーブルに存在するかチェック
            {
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    												D_PROC_NAME, OSFEACC ) );
				os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEACC );
                return( OSFEACC );
            }
            
            iConect = D_CONECT_FLAG_ON; // コネクト状態にセット
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iConect=%d )\n",
    												D_PROC_NAME, iConect ) );
            break;
        }
    }

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iConect=%d )\n",
   													D_PROC_NAME, iConect ) );

    if( iConect != D_CONECT_FLAG_ON )   // コネクトされていなかった時
    {
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lEmpIndNum=%d )\n",
   													D_PROC_NAME, ptEflc->lEmpIndNum ) );
        if( ptEflc->lEmpIndNum < D_OPENING_MIN )
                                        // 空き部数のチェック
                                        // 空き部数がなかった場合
        {
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, OSFEPFILRS ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
        }
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FOPEN, 2, path, D_CHAR_FILE_WRITE );
                                        // ファイルのオープン(書込みモード) 
    pFilStm = fopen( path, D_CHAR_FILE_WRITE );
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 1, pFilStm );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );

    if( pFilStm == NULL )               // ファイルオープンエラーの時
    {
        goto err_oscreat;
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_MALLOC, 1, exlen );
    pcWbuf = ( char * )malloc( exlen ); // 書き込みエリア確保
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 2, pcWbuf, errno );
    
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pcWbuf=%p )\n",
    												D_PROC_NAME, pcWbuf ) );
    if( pcWbuf == NULL )
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

    memset( pcWbuf, 0x00, exlen );      // 初期化
    
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FWRITE, 4, pcWbuf, 
								D_WRITE_BYTE, (exlen * rsize), pFilStm );
    stFwriteRet = fwrite( pcWbuf, D_WRITE_BYTE, (exlen * rsize), pFilStm );
                                        // ファイルの書込み
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 1, stFwriteRet );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stFwriteRet=%d )\n",
    												D_PROC_NAME, stFwriteRet ) );

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FREE, 1, pcWbuf );
    free( pcWbuf );                     // エリア解放
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
    
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FFLUSH, 1, pFilStm );
    fflush( pFilStm );                  // バッファリングされている内容を
                                        // ディスクに書込む
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FILENO, 1, pFilStm );
    iFilDes = fileno( pFilStm );        // ファイルストリームから
                                        // ファイルディスクプリタを取得する
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 2, iFilDes, errno );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=%d )\n",
    												D_PROC_NAME, iFilDes ) );

    if( iFilDes == D_ERR_SYS )          // 取得に失敗があった時
    {
		os_trcget2( D_MD_OSCREAT, D_T_SYS_FCLOSE, 1, pFilStm );
        fclose( pFilStm );				// ファイルをクローズする
		os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
        
		os_trcget2( D_MD_OSCREAT, D_T_SYS_REMOVE, 1, path );
        remove( path );                 // ファイルを削除する
		os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
        
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 2, -1 , errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
		//return ( -1 );                  // アボード処理
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FSYNC, 1, iFilDes );
    fsync( iFilDes );                   // バッファリングされている内容が
                                        // ディスクへ書き込まれるまで待つ
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FCLOSE, 1, pFilStm );
    fclose( pFilStm );                  // ファイルをクローズする
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );

/****************************************************************************/
/* 後処理                                                                   */
/****************************************************************************/
    if( iConect != D_CONECT_FLAG_ON )   // コネクトされていなかった時
    {
        for( iFilId = 0; iFilId < ptEflc->lMaxIndNum; iFilId++ )
                                        // 空き個別部に登録する
        {
            if( ( ptTEflcTableInd + iFilId )->acFileName[ 0 ] == '\0' )
                                        // ファイル名がＮＵＬＬの時 
            {
                strcpy( ( ptTEflcTableInd + iFilId )->acFileName, path );
                                        // 個別部のファイル名を設定する
                ( ptEflc->lEmpIndNum )--;
                                        // 管理部の空き部数をデクリメントする
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lEmpIndNum=%ld )\n",
    												D_PROC_NAME, ptEflc->lEmpIndNum ) );
                break;
            }
        }

        if( iFilId == ptEflc->lMaxIndNum )
                                        // 個別部に空きがなかった場合
        {
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, -1 );
			return( OSFEPFILRS );
			//return( -1 );                   // アボート処理
        }
    }

    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSCREAT, D_T_TRA_OUT, 1, iFilId + 1 );
    return( iFilId + 1 );               // 登録したファイル記述子を返す
                                        // ファイル記述子は　配列番号 ＋1

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_oscreat:
    switch( errno )
    {
        case EACCES:
        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;
        
        case EMFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
            break;  
        
        case ENFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFESFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFESFILRS );
            return( OSFESFILRS );
            break;
    
        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 2, -1 , errno );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
