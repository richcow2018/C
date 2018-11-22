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
/* ＜モジュール名＞					 ファイルとプロセスの連結									*/
/* ＜モジュールＩＤ＞				 osconn														*/
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
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月２６日		仕様変更番号（ＳＳＬＡ００３４）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		statでファイルパス名が示すファイルが存在するかをチェックし、							*/
/*		ファイルパス名をファイル管理テーブル(EFLC)の空き個別部に登録する。						*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osconn.h>																	*/
/*																								*/
/*	   	long	osconn( char *path )															*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		*path;				生成対象ファイルパス名									*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		iFilId+1(iFilIdはファイル記述子用カウンタ)								*/
/*		異常終了		OSFENOFILE																*/
/*						OSFEPATHDR																*/
/*						OSEEWKEX																*/
/*						OSFEPATH																*/
/*						OSFEPATH																*/
/*						OSFEPFILRS																*/
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
#include <errno.h>                      // エラーＮｏ取得用
#include <sys/stat.h>                   // stat用
#include <string.h>                     // str用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osconn.h"
#include "os_treterm.h"
#include "os_EndCod.h"
#include "osconn_ins.h"                 // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osconn                                                    */
/*                                                                          */
/*  ＜機能概要＞  ファイルとプロセスを連結する                              */
/*                                                                          */
/****************************************************************************/
long osconn( char *path )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部
    int iFilId;                         // ファイル記述子カウント用
    int iStatRet;                       // statの返却値
    struct stat tStatBuf;               // stat用バッファ
    size_t stStrlenRet;                 // ファイル名の長さ
/*****	仕様変更番号SSLA0034の対応		Start							修正日：2003.06.26	*****/
    long	lCnt  = 0;					// ループカウンタ
    long    lLen2 = 0;					// ディレクトリ名の長さ
	char	acDir[128];					// ディレクトリ名
/*****	仕様変更番号SSLA0034の対応		 End							修正日：2003.06.26	*****/

	os_trcget2( D_MD_OSCONN, D_T_TRA_IN, 1, path );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	errno = 0;							// errno クリア
	memset(acDir, 0, sizeof(acDir));	// ディレクトリ名 クリア

	/************************************************/
	/*	引数チェック								*/
	/************************************************/
    if( path[ 0 ] != D_FILE_PASS_SLASH )// 絶対ファイルパスのチェック
                                        // （先頭文字　/　でない時）
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCONN, D_T_ERR_PRA, 1, OSFEPATH );
        return( OSFEPATH );
    }

    stStrlenRet = strlen( path ) +1;    // ファイルパスのサイズを取得する
                                        // NULLを含む為＋１
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stStrlenRet=%d )\n",
    												D_PROC_NAME, stStrlenRet ) );
    												
    if( stStrlenRet > D_PATH_MAX )		// ファイルパスのチェック（長さ）
                                        // 指定範囲内でない場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 1, OSFEPATH );
        return( OSFEPATH );
    }

    if( ptEflc->lEmpIndNum < D_OPENING_MIN )
                                        // 空き部数のチェック
                                        // 空き部数がなかった場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFEPFILRS ) );
		os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 1, OSFEPFILRS );
        return( OSFEPFILRS );
    }

/*****	仕様変更番号SSLA0034の対応		Start							修正日：2003.06.26	*****/
/************************************************************************************************/
/*	ディレクトリのチェック処理を追加															*/
/************************************************************************************************/
	/************************************************/
	/*	ディレクトリ名の切り出し					*/
	/************************************************/
	lCnt = (stStrlenRet - 1);			// ループカウンタにファイルパス名の長さを設定
	while(lCnt > 0)						// ループ処理（pathの最後から検索）
	{
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( *path[%ld] = %c )\n",
				D_PROC_NAME, lCnt-1, *(path + (lCnt-1)) ) );

		if ('/' == *(path + (lCnt-1)))		// pathの当該文字が'/'の場合
		{
			lLen2 = lCnt;				// ディレクトリの長さにループカウンタを設定
			break;						// ループを抜ける
		}
		lCnt--;							// デクリメント
	}

	strncpy(acDir, path, lLen2);		// ディレクトリ名を設定
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display (acDir=%s lLen2=%ld)\n",
			D_PROC_NAME, acDir, lLen2 ) );

	/************************************************/
	/*	ディレクトリの存在チェック					*/
	/************************************************/
	os_trcget2( D_MD_OSCONN, D_T_SYS_STAT, 2, acDir, &tStatBuf );
	iStatRet = stat(acDir, &tStatBuf);	// ディレクトリの存在チェック
	os_trcget2( D_MD_OSCONN, D_T_SYS_END, 2, iStatRet, errno );

	if( iStatRet == D_ERR_SYS )         // ディレクトリが存在しない場合
	{
		os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 2, OSFEPATHDR, errno );
		return( OSFEPATHDR );			// 異常終了を返却
	}
/*****	仕様変更番号SSLA0034の対応		 End							修正日：2003.06.26	*****/

	/************************************************/
	/*	ファイルの存在チェック						*/
	/************************************************/
	os_trcget2( D_MD_OSCONN, D_T_SYS_STAT, 2, path, &tStatBuf );
    iStatRet = stat( path, &tStatBuf ); // ファイルの存在をチェックする
	os_trcget2( D_MD_OSCONN, D_T_SYS_END, 1, iStatRet );
    
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStatRet=%d )\n",
    												D_PROC_NAME, iStatRet ) );

    if( iStatRet == D_ERR_SYS )         // ファイルが存在しない場合
    {
        goto err_osconn;
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 );
										// ファイル管理テーブル個別部の先頭アドレス取得
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );

	/************************************************/
	/*	ファイル管理テーブルへの登録				*/
	/************************************************/
    for( iFilId = 0; iFilId < ptEflc->lMaxIndNum; iFilId++ )
                                        // 空き個別部に登録する
    {
        if( ( ptTEflcTableInd + iFilId )->acFileName[ 0 ] == '\0' )
                                        // ファイル名がＮＵＬＬの時 
        {
            strcpy( ( ptTEflcTableInd + iFilId )->acFileName, path );
                                        // 個別部のファイル名を設定する
            ( ptEflc->lEmpIndNum )--;	// 管理部の空き部数をデクリメントする
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lEmpIndNum=%ld )\n",
    												D_PROC_NAME, ptEflc->lEmpIndNum ) );
            break;
        }
    }

    if( iFilId == ptEflc->lMaxIndNum )	// 管理部に空きがなかった場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 1, -1 );
		return( OSFEPFILRS );
		//return( -1 );                   // アボート処理
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSCONN, D_T_TRA_OUT, 1, iFilId + 1 );
    return( iFilId + 1 );               // 登録したファイル記述子を返す
                                        // ファイル記述子は　配列番号 ＋1

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_osconn:
    switch( errno )
    {
        case ENOENT:
        case ENOTDIR:
        case ELOOP:
/*****	仕様変更番号SSLA0034の対応		Start							修正日：2003.06.26	*****/
/************************************************************************************************/
/*	返却値「OSFEPATHDR」→「OSFENOFILE」に変更													*/
/************************************************************************************************/
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 2, OSFENOFILE, errno);
            return( OSFENOFILE );
/*****	仕様変更番号SSLA0034の対応		 End							修正日：2003.06.26	*****/
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 2, OSEEWKEX, errno );
            return( OSEEWKEX );
            break;

        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 2, OSFEPATH, errno );
            return( OSFEPATH );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSCONN, D_T_ERR_SYS, 2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCONN << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
