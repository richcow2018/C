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
/* ＜サービス項目名＞				 データ操作													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 読込み（順アクセス）										*/
/* ＜モジュールＩＤ＞				 osread														*/
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
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 ファイルから要求サイズ分のデータを順次読込む												*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osread.h>																	*/
/*																								*/
/*	   	long osread( long fildes, char *buf, long len )											*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		fildes;				ファイル記述子											*/
/*										「0 < ファイル記述子 <=									*/
/*											ファイル管理テーブルの								*/
/*											管理部個別部数」									*/
/*		char		*buf;				データ格納バッファ										*/
/*		long		len;				読込みレコード数										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		読込んだデータのバイト数												*/
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
#include <stdio.h>                      // freed用
#include <string.h>						// デバッグ用

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osread.h"
#include "osread_ins.h"                 // 内部参照用（個別）

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osread                                                    */
/*                                                                          */
/*  ＜機能概要＞  ファイルから要求サイズ分のデータを順次読込む              */
/*                                                                          */
/****************************************************************************/
long osread( long fildes, char *buf, long len )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部取得

    long lCommonRet;                    // 共通関数リターン値
    size_t stFreadRet;                  // freadの返却値
    int iFerrorRet;                     // ferrorの返却値

	os_trcget2( D_MD_OSREAD, D_T_TRA_IN, 3, fildes, buf, len );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    if( len < D_RECORDLEN_MIN )         // 読込みレコード数のチェック
                                        // 範囲外の時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEOOFB ) );
		os_trcget2( D_MD_OSREAD, D_T_ERR_PRA, 1, OSFEOOFB );
        return( OSFEOOFB );             // 読込みレコード数エラー
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
    lCommonRet = os_IsFileConnect( fildes );
                                        // コネクト中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // コネクトエラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileOpen( fildes );
                                        // オープン中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // オープン中でない場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );

    for(;;)                             // errno がEINTRの間、繰り返す
    {
		os_trcget2( D_MD_OSREAD, D_T_SYS_FREAD, 4, buf, D_READ_BYTE, len, ptTEflcTableInd->pFilStm );
        stFreadRet = fread( buf, D_READ_BYTE, len, ptTEflcTableInd->pFilStm );
        								// ファイルの読み込み
		os_trcget2( D_MD_OSREAD, D_T_SYS_END, 1, stFreadRet );
        								
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stFreadRet=%d )\n",
    												D_PROC_NAME, stFreadRet ) );
    												
		os_trcget2( D_MD_OSREAD, D_T_SYS_FERROR, 1, ptTEflcTableInd->pFilStm );
        iFerrorRet = ferror( ptTEflcTableInd->pFilStm );
        								// errnoを取得する
		os_trcget2( D_MD_OSREAD, D_T_SYS_END, 1, iFerrorRet );
        								
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFerrorRet=0x%08x )\n",
    												D_PROC_NAME, iFerrorRet ) );
    												
        if( iFerrorRet == D_ERROR_NOT ) // ファイルリード成功
        {
            break;
        }

        if( errno != EINTR )            // errno がEINTRでない時 
        {
            goto err_osread;
        }
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSREAD, D_T_TRA_OUT, 1, stFreadRet );
    return( stFreadRet );               // 読込んだレコード数を返す

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_osread:
    switch( errno )
    {
        case EAGAIN:
        case EISDIR:
        case EBADF:
        case EINVAL:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACCCTL, "fread", strerror(errno) ) );
			os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, errno );
            return( OSFEACCCTL );
            break;

        case EFAULT:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fread", strerror(errno) ) );
			os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, errno );
            return( OSFEACC );
            break;

        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSIDKE | OSIZZEDVC, "fread", strerror(errno) ) );
			os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, errno );
            return( OSIDKE | OSIZZEDVC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fread", strerror(errno) ) );
			os_trcget2( D_MD_OSREAD, D_T_ERR_SYS, 1, errno );
            return( OSEEWKEX );
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
