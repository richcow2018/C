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
/* ＜サービス項目名＞				 制御														*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ファイル情報取得											*/
/* ＜モジュールＩＤ＞				 osgfinf													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*    ファイル情報を取得する                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long osgfinf( long fildes, long attr,struct osf_info *info,         */
/*                                                        long bufsiz )     */
/*																								*/
/* ＜仮引数＞																					*/
/*      long        fildes              ファイル記述子                      */
/*                                      「0 < ファイル記述子 <=             */
/*                                              ファイル管理テーブルの      */
/*                                                         管理部個別部数」 */
/*      long        *path               生成対象ファイルパス名              */
/*      long        attr                属性種別コード                      */
/*      struct osf_info *info           ファイル情報格納バッファ            */
/*      long        bufsiz              バッファサイズ                      */
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了	                                               				*/
/*                         情報サイズ                                                           */
/*		異常終了			-1																	*/
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
/******************************** 標準ヘッダ・ファイル **********************/
#include <sys/stat.h>                   // ファイル情報取得用
#include <string.h>                     // strcpy用
#include <time.h>                       // Time関係用
#include <errno.h>                      // エラーＮｏ取得用
/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "osgfinf_ins.h"                // 内部参照用（個別）
#include "osgfinf.h"

/****************************************************************************/
/*                                                                          */
/*  ＜関数名＞    osgfinf                                                   */
/*                                                                          */
/*  ＜機能概要＞  ファイル情報を取得する                                    */
/*                                                                          */
/****************************************************************************/
long osgfinf( long fildes, long attr, struct osf_info *info, long bufsiz )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// ファイル管理テーブル個別部

    long lCommonRet;                    // 共通関数リターン値
    long lDate;                         // ２進化１０進化数値を
                                        // 設定する変数（日付）
    long lTime;                         // ２進化１０進化数値を
                                        // 設定する変数（時間）
    int iStatRet;                       // statの返却値
    long lOs_Date2DayTimeRet;           // os_Date2DayTimeRetの返却値
    long lRetSize;                      // 作業用変数
    char *pcCtimeRet;                   // Ctimeの返却値
    struct stat tStatbuf;               // stat構造体
    char acFilename[ D_FILENAME_MAX ];  // ファイル名用文字列

    char acWday[ D_WDAY_MAX ][ D_CHAR_SIZE ] = { D_SUN, D_MON, D_TRU, D_WED, 
                                                        D_THU, D_FRI, D_SAT };
                                        // 曜日用の配列（日から土）
    char acMon[ D_MON_MAX ][ D_CHAR_SIZE ] = { D_JAN, D_FEB, D_MAR, D_APR, 
                                               D_MAY, D_JUN, D_JUL, D_AUG,
                                               D_SEP, D_OCT, D_NOV, D_DEC };
                                        // 月用の配列（１月から１２月）
    int iTemp;                          // 作業用変数
    
    struct tm tStTime;                  // tm構造体
    char acWdaySet[ D_CHAR_SIZE ];      // 曜日
    char acMonSet[ D_CHAR_SIZE ];       // 月
    int iDay;                           // 日
    char acTimeSet[ D_TIME_SIZE ];      // 時間 hh:mm:ss
    int iYear;                          // 年
    int iHour;                          // 時
    int iMin;                           // 分
    int iSec;                           // 秒

	os_trcget2( D_MD_OSGFINF, D_T_TRA_IN, 4, fildes, attr, info, bufsiz );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // ファイル記述子のチェック
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ファイル記述子エラーの時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );           // ファイル記述子エラーの時
    }

    if( attr != D_ATTR_OK )             // 属性種別のチェック 範囲の時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEPARMV ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_PRA, 1, OSFEPARMV );
        return( OSFEPARMV );            // 属性エラー
    }

    if( sizeof( struct osf_info ) > bufsiz )
                                        // バッファサイズのチェック
                                        // osf_info構造体以下の時
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFEIOBUF ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_PRA, 1, OSFEIOBUF );
        return( OSFEIOBUF );            // バッファサイズ
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
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }
	
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // ファイル管理テーブルの対象個別部取得
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
    strcpy( acFilename, ptTEflcTableInd->acFileName );
                                        // 対応するファイル名を取得する

	os_trcget2( D_MD_OSGFINF, D_T_SYS_STAT, 2, acFilename, &tStatbuf );
    iStatRet = stat( acFilename, &tStatbuf );
                                        // ファイルの情報を取得する
	os_trcget2( D_MD_OSGFINF, D_T_SYS_END, 1, iStatRet );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStatRet=0x%08x )\n",
    												D_PROC_NAME, iStatRet ) );
    												
    if( iStatRet == D_ERR_SYS )         // 取得エラー時
    {
        goto err_osgfinf;
    }

	os_trcget2( D_MD_OSGFINF, D_T_SYS_CTIME, 1, &tStatbuf.st_mtime );
    pcCtimeRet = ctime( &tStatbuf.st_mtime );
                                        // ファイル更新日時を文字列に変更する
	os_trcget2( D_MD_OSGFINF, D_T_SYS_END, 2, pcCtimeRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pcCtimeRet=%p )\n",
    												D_PROC_NAME, pcCtimeRet ) );
    												
    if( pcCtimeRet == NULL )            // 変更失敗の時
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ctime", strerror(errno) ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, -1 );
		
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

    sscanf( pcCtimeRet,"%s %s %d %s %d", acWdaySet, acMonSet, 
                                                    &iDay, acTimeSet, &iYear );
                                        // 文字列を空白区切りで変数に設定する    
    sscanf( acTimeSet,"%d:%d:%d", &iHour, &iMin, &iSec );
                                        // 文字列を:区切りで変数に設定する

    tStTime.tm_sec = iSec;              // ファイル格納バッファ　秒　設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_sec=%d )\n",
    												D_PROC_NAME, tStTime.tm_sec ) );
    tStTime.tm_min = iMin;              // ファイル格納バッファ　分　設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_min=%d )\n",
    												D_PROC_NAME, tStTime.tm_min ) );
    tStTime.tm_hour = iHour;            // ファイル格納バッファ　時　設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_hour=%d )\n",
    												D_PROC_NAME, tStTime.tm_hour ) );
    tStTime.tm_mday = iDay;             // ファイル格納バッファ　日　設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_mday=%d )\n",
    												D_PROC_NAME, tStTime.tm_mday ) );

    for( iTemp = D_MON_MIN - 1; iTemp < D_MON_MAX; iTemp++ )
                                        // 文字列　月が同一のものを探す
    {
       if( strcmp( acMonSet, acMon[ iTemp ] ) == D_STRING_EQUAL ) 
                                        // 同一の場合
       {
			tStTime.tm_mon = iTemp;      // ファイル格納バッファ　月　設定
                                        // 月（月は−１の値を設定する）
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_mon=%d )\n",
    												D_PROC_NAME, tStTime.tm_mon ) );
           break;
       }
    }

    tStTime.tm_year = iYear - D_YEAR_1900;           
                                        // os_Date2DayTimeの年フォーマットに
                                        // 合わせる
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_year=%d )\n",
    												D_PROC_NAME, tStTime.tm_year ) );

    for( iTemp = D_WDAY_MIN - 1; iTemp < D_WDAY_MAX; iTemp++ )
                                        // 文字列　曜日が同一のものを探す
    {
        if( strcmp( acWdaySet, acWday[ iTemp ] ) == D_STRING_EQUAL )  
                                        // 同一の場合
        {
            tStTime.tm_wday = iTemp;    // ファイル格納バッファ　曜日　設定
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_wday=%d )\n",
    												D_PROC_NAME, tStTime.tm_wday ) );
            break;
        }
    }

    lOs_Date2DayTimeRet = os_Date2DayTime( &tStTime, &lDate, &lTime );
                                        // 日時を日付時刻に変換する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lOs_Date2DayTimeRet=0x%08lx )\n",
    												D_PROC_NAME, lOs_Date2DayTimeRet ) );
    												
    if( lOs_Date2DayTimeRet != NORMAL )	// 日時変換に失敗した時
                                        // 年エラーはここでエラーとなる
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
		//return( -1 );                   // アボード処理
    }

    info->mdate = lDate;                // ファイル更新日付を設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->mdate=%ld )\n",
    												D_PROC_NAME, info->mdate ) );
    info->mtime = lTime;                // ファイル更新時間を設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->mtime=%ld )\n",
    												D_PROC_NAME, info->mtime ) );
    info->rsize = D_RECORD_SIZE;        // レコードサイズを設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->rsize=%ld )\n",
    												D_PROC_NAME, info->rsize ) );
    info->filsiz = tStatbuf.st_size;    // ファイルサイズを設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->filsiz=%ld )\n",
    												D_PROC_NAME, info->filsiz ) );
    info->datsiz = tStatbuf.st_size;    // 物理領域サイズを設定
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->datsiz=%ld )\n",
    												D_PROC_NAME, info->datsiz ) );
    strcpy( info->fname ,acFilename );  // ファイル名を設定

    lRetSize = sizeof( info->mdate ) + sizeof( info->mtime )
               + sizeof( info->rsize ) + sizeof( info->filsiz )
               + sizeof( info->datsiz ) + sizeof( info->fname );
                                        // 正常返却値の値を計算する
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRetSize=%ld )\n",
    												D_PROC_NAME, lRetSize ) );
    												
//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSGFINF, D_T_TRA_OUT, 1, lRetSize );
    return( lRetSize );                 // 正常値リターン

/****************************************************************************/
/* エラー処理                                                               */
/****************************************************************************/
err_osgfinf:
    switch( errno )
    {
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;
        
        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;
        
        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
			//return( -1 );               // バスエラー処理
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
