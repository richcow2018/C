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
/* ＜モジュール名＞					 順アクセス開始点設定										*/
/* ＜モジュールＩＤ＞				 osseek														*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(:ＸＸＸＸ)							*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 ファイルアクセスポイントの設定する。														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osseek.h>																	*/
/*																								*/
/*	   	long osseek( long fildes, long skmode, long skrecord ) 									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		fildes;				ファイル記述子											*/
/*                                      「0 < ファイル記述子 <=             					*/
/*                                              ファイル管理テーブルの      					*/
/*                                                         管理部個別部数」 					*/
/*		long		skmode;				アクセスポインタの設定基準点							*/
/*											1:ファイルの先頭									*/
/*											2:ファイルＥＯＦ									*/
/*											3:カレントポジション								*/
/*		long		skrecord;			アクセスポインタの移動オフセット						*/
/*																								*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		カレントポジション														*/
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
#include <sys/stat.h>                   // stat用
#include <stdio.h>                      // seek用 ftell用
#include <string.h>						// デバッグ用
#include <errno.h>

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osseek.h"
#include "osseek_ins.h"

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osseek                                                    */
/*                                                                          */
/*  ＜機能概要＞  ファイルアクセスポイントの設定する。                      */
/*                                                                          */
/****************************************************************************/
long osseek( long fildes, long skmode, long skrecord )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部取得

    long lCommonRet;                    // 共通関数リターン値
    int iFilDes;                        // ファイルディスクプリタ
    long lCurPos;                       // カレントポジション
    int iFstatRet;                      // fstatの返却値
    int ifseekRet;                      // fseekの返却値
    int iWhence;                        // シーク開始位置
    struct stat tStatBuf;               // stat用バッファ
    int iStatStsize;                    // stat.stsize用変数

	os_trcget2( D_MD_OSSEEK, D_T_TRA_IN, 3, fildes, skmode, skrecord );

//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    if( ! ( ( skmode == D_FILE_START ) || ( skmode == D_FILE_END )  
                                       || ( skmode == D_FILE_CURENTPOS ) ) )
                                        // アクセスポインタの
                                        // 設定基準点のチェック
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFESKMODE ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_PRA, 1, OSFESKMODE );
        return( OSFESKMODE );           // アクセスポインタの設定基準点エラー
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
    lCommonRet = os_IsFileOpen( fildes );
                                        // オープン中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // オープン中でない場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // コネクト中のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // コネクトエラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// カレントポジションを取得する
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, lCurPos, errno );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );
    												
    if( lCurPos == D_ERR_SYS )          // 取得に失敗した時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// ファイルストリームから
                                        // ファイルディスクプリタを取得する
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, iFilDes, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=0x%08x )\n",
    												D_PROC_NAME, iFilDes ) );
    												
    if( iFilDes == D_ERR_SYS )          // 取得に失敗した時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FSTAT, 2, iFilDes, &tStatBuf );
    iFstatRet = fstat( iFilDes, &tStatBuf );
                                        // ファイル情報を取得する
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, iFstatRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFstatRet=%08x )\n",
    												D_PROC_NAME, iFstatRet ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStatBuf.st_size=%d )\n",
    												D_PROC_NAME, tStatBuf.st_size ) );
    												
    if( iFstatRet == D_ERR_SYS )        // 取得に失敗した時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

//	iStatStsize = tStatBuf.st_size - 1; // stat.stsizeを取得（０から始まるので−１）
	iStatStsize = tStatBuf.st_size;		// stat.stsizeを取得
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStatStsize=%d )\n",
    												D_PROC_NAME, iStatStsize ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( skrecord=%d )\n",
    												D_PROC_NAME, skrecord ) );

    switch( skmode )                    // シークポインタオーバーエラー
                                        // を判定する
    {
        case D_FILE_START:              // ファイルの先頭
            iWhence = SEEK_SET;         // 先頭指定
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
    												
            if( skrecord > D_OFFSET_ZERO )
                                        // オフセット正
            {
                if( skrecord > iStatStsize ) 
                                        // オフセット＞ファイル末尾
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
                }
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // オフセット負
            {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
            }
            break;

        case D_FILE_END:                // ファイルＥＯＦ
            iWhence = SEEK_END;         // ＥＯＦ指定
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
            if( skrecord > D_OFFSET_ZERO )
                                        // オフセット正
            {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // オフセット負
            {
                if( ( iStatStsize + skrecord ) < 0 )
                                        // （ファイル末尾＋オフセット）＜０
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
                }
            }
            break;

        case D_FILE_CURENTPOS:          // カレントポジション
            iWhence = SEEK_CUR;         // カレントポジション指定
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
    												
            if( skrecord > D_OFFSET_ZERO ) 
                                        // オフセット正
            {
                if( ( lCurPos + skrecord ) > iStatStsize )
                                        // （カレントポジション＋オフセット）
                                        // ＞ ファイル末尾
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
                }
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // オフセット負
            {
                if( ( lCurPos + skrecord ) < D_OFFSET_ZERO )
                                        // （カレントポジション＋オフセット）
                                        // ＜　０
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // オーバーシーク発生
                }
            }
            break;

        default:
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
			//return( -1 );               // アボード処理
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FSEEK, 3, ptTEflcTableInd->pFilStm, skrecord, iWhence );
    ifseekRet = fseek( ptTEflcTableInd->pFilStm, skrecord, iWhence );
                                        // アクセスポインタの移動
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, ifseekRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ifseekRet=0x%08x )\n",
    												D_PROC_NAME, ifseekRet ) );

    if( ifseekRet == D_ERR_SYS )        // fseekに失敗した場合
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fseek", strerror(errno) ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 ); 
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// カレントポジションの取得
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, lCurPos, errno );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );

    if( lCurPos == D_ERR_SYS )          // ftellに失敗した場合
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftell", strerror(errno) ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 ); 
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSSEEK, D_T_TRA_OUT, 1, lCurPos );
    return( lCurPos );                  // カレントポジションを返却する
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
