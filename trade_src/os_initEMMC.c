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
/* ＜サービス項目名＞				 共通関数													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ＸＸＸＸＸＸＸ												*/
/* ＜モジュールＩＤ＞				 os_initEMMC												*/
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
/*  メッセージ管理テーブルの初期化を実施する                                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_initEMMC.h>																*/
/*																								*/
/*	   	long	os_initEMMC(char *pcEmmcTableAdr)												*/
/*																								*/
/* ＜仮引数＞																					*/
/*      char *pcEmmcTablAdr     メッセージ管理テーブル先頭アドレス                              */
/*																								*/
/* ＜返却値＞																					*/
/*      正常戻り値  NORMAL                                                                      */
/*      異常戻り値  OSERREMMC                                                                   */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*  os_initSystem関数内でのみ使用可能とする                                                     */
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include	<stdio.h>			// fopen, fread, fclose, fgets
#include	<stdlib.h>			// calloc, free
#include	<string.h>			// strcpy, strtok
#include	<sys/types.h>		// stat
#include	<sys/stat.h>		// stat
#include	<unistd.h>			// stat
#include	<errno.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"
// EMMCの初期化
long os_initEMMC( char *pcEmmcTableAdr )
{
	long	lRet = 0;
	long os_MainEMMC( void );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initEMMC\n") );		// 引数確認
	if( NULL == pcEmmcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_initEMMC\n") );
		return( OSERRARG );
	}
	
	ptEmmc = (TEmmcTable *)pcEmmcTableAdr;

	lRet	= os_MainEMMC(  );
	if(NORMAL != lRet)
	{
		return(OSERREMMC);
	}
	
//	DbgDmp02( DLv04, ("ptEmmc   ダンプ", ptEmmc, sizeof(TEmmcTable),1,0));
//	DbgDmp02( DLv04, ("ptEmmcIndダンプ", ptEmmc->ptConAdr, (sizeof(TEmmcTableInd) * 40),1,0));
//	DbgDmp02( DLv04, ("ptEmmcIndダンプ", ptEmmc->ptLogAdr, (sizeof(TEmmcTableInd) * 40),1,0));
//	DbgDmp02( DLv04, ("ptEmmcIndダンプ", ptEmmc->ptProcAdr, (sizeof(TEmmcTableInd) * 40),1,0));
	
	DbgMsg01( DLv02, ( OutPut, "***** End os_initEMMC\n") );

	return( lRet );		// 下位からの返却値をそのまま返却する。
}

/****************************************************/
/*   共有メモリ上に必要なEMMCのサイズ容量を求める。 */
/****************************************************/
long os_getEmmcSize( long *lSize )
// long *lSize  結果返却先アドレス
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// ファイル名取得用SGKey
	long	i				= 0;
	long	lRet			= 0;
	TFileInfo	tBufInfo[ 3 ];												// 各ファイル情報
//	TEmmcInfo	iInfo;
	
	DbgMsg01( DLv02, ( OutPut, "***** Start os_getEmmcSize\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	
//	tBufInfo->lSize = sizeof( TEmmcTable );	// 管理部のサイズを加算する。
	*lSize = sizeof( TEmmcTable );	// 管理部のサイズを加算する。
	if(NULL == lSize)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_getEmmcSize\n") );
		return( OSERRARG );					//引数異常を返却
	}

	for( i = 0 ; i < 3 ; i++ ){
		lRet = os_getFileInfo( pcMsgFileName[ i ], &tBufInfo[ i ] );
		if( NORMAL != lRet ){
			DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_getEmmcSize\n") );
			return( OSERREMMC );
		}
		
//		DbgMsg01( DLv04, ( OutPut, "***** tBufInfo[ i ].lLine :%ld\n", tBufInfo[ i ].lLine));
//		DbgMsg01( DLv04, ( OutPut, "***** tBufInfo[ i ].lSize :%ld\n", tBufInfo[ i ].lSize));
		*lSize
			+= ( tBufInfo[ i ].lSize + ( tBufInfo[ i ].lLine + 1 ) * ( sizeof( TEmmcTableInd )));
			// 1MSGで必要な管理情報分の領域を追加した値を算出する。+1は終端記号用。
//		DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	}

//	DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	DbgMsg01( DLv02, ( OutPut, "***** End os_getEmmcSize\n") );

	return( NORMAL );
}
/**************************/
/*   EMMCの初期化の主処理 */
/**************************/
long os_MainEMMC( void )
{
	long	lRet = 0;
	long os_setEmmcMng( void );
	long os_setEmmcInd( void );
	
	lRet = os_setEmmcMng(  );	// 管理部の設定
	if( NORMAL != lRet ){
		return( lRet );
	}

	lRet = os_setEmmcInd(  );
	if( NORMAL != lRet ){
		return( lRet );
	}

	return( NORMAL );
}

/**************************/
/*    管理部の設定        */
/**************************/
long os_setEmmcMng( void )
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// ファイル名取得用SGKey
	long	lRet			= 0;
	long	i				= 0;
	long	j				= 0;
	long	lHead			= 0;
	long	*palLine[ 3 ];
	long	lLen			= 0;
	long	lSize			= 0;
	long	lHsize			= 0;

	TEmmcTableInd	**patEmmcInd[ 3 ];
	TFileInfo		tInfo[ 3 ];
	long os_getFileInfo( const char *pcFileSgId, TFileInfo *tInfo  );
	
	DbgMsg01( DLv02, ( OutPut, "***** Start os_setEmmcMng\n") );

	palLine[ 0 ]	= &(ptEmmc->lConCnt);	// カウンタの配列化
	palLine[ 1 ]	= &(ptEmmc->lLogCnt);	//
	palLine[ 2 ]	= &(ptEmmc->lProcCnt);	//

	patEmmcInd[ 0 ]	= (TEmmcTableInd **)&(ptEmmc->ptConAdr);		// アドレスの配列化
	patEmmcInd[ 1 ]	= (TEmmcTableInd **)&(ptEmmc->ptLogAdr);		//
	patEmmcInd[ 2 ]	= (TEmmcTableInd **)&(ptEmmc->ptProcAdr);		//

	lHead = (long)(ptEmmc + 1);// 個別部先頭アドレス

	strncpy( ptEmmc->acTid, D_EMMC_TID, 4 );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmmc->acTid : %s\n", ptEmmc->acTid) );

	for( i = 0 ; i < 3 ; i++ )
	{
		lRet	= os_getFileInfo( pcMsgFileName[ i ], &tInfo[ i ]  );
		if( NORMAL != lRet )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_setEmmcMng\n"));
			return(lRet);
		}
		
		*(palLine[ i ])	= tInfo[ i ].lLine;
		j = ( i - 1 ) < 0 ? 0 : ( i - 1 );	// iより1減算した値を求める。マイナスの時は0固定とする。
		lLen = *(palLine[ j ]);
		lSize = (tInfo[ j ].lSize);
		lHsize = (long)( *(patEmmcInd[ j ]) );
		if(0 == i)
		{
			lLen = 0;
			lSize = 0;
			lHsize = lHead;
		}
		
		if(0 != lLen)
		{
			lLen += 1;							// 空白個別部管理情報分追加20030106追加
		}
		
		*(patEmmcInd[ i ]) = (TEmmcTableInd *)(lHsize + lSize + lLen * sizeof( TEmmcTableInd ) );
//		DbgMsg01( DLv04, ( OutPut, "***** patEmmcInd[ %ld ]:%p\n", i, *(patEmmcInd[ i ]) ));
		
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setEmmcMng\n") );
	return( NORMAL );
}

/**************************/
/*    個別部の設定        */
/**************************/
long os_setEmmcInd( void )
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// ファイル名取得用SGKey
	long			*palTableLine[ 3 ];
	TEmmcTableInd	*patEmmcInd[ 3 ];
	long i;
	long lRet;
	long os_setMsg( const char *pcFileSgId, TEmmcTableInd *ptEmmcInd, long lLine );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_setEmmcInd\n") );
	patEmmcInd[ 0 ]	= (TEmmcTableInd *)(ptEmmc->ptConAdr);			// アドレスの配列化
	patEmmcInd[ 1 ]	= (TEmmcTableInd *)(ptEmmc->ptLogAdr);			//
	patEmmcInd[ 2 ]	= (TEmmcTableInd *)(ptEmmc->ptProcAdr);		//

	palTableLine[ 0 ]	= &(ptEmmc->lConCnt );	// カウンタの配列化
	palTableLine[ 1 ]	= &(ptEmmc->lLogCnt );	//
	palTableLine[ 2 ]	= &(ptEmmc->lProcCnt);	//

	for( i = 0 ; i < 3 ; i++ ){
//		DbgMsg01( DLv04, ( OutPut, "***** patEmmcInd[%ld]:%08lx\n", i, patEmmcInd[ i ]));
//		DbgMsg01( DLv04, ( OutPut, "***** palTableLine[%ld]:%ld\n", i, *(palTableLine[ i ]) ));

		lRet = os_setMsg( pcMsgFileName[ i ], patEmmcInd[ i ], *palTableLine[ i ] );
		if( NORMAL != lRet ){
			DbgMsg01( DLv05, ( OutPut, "***** Err:05 os_initEMMC\n"));
			return( lRet );
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setEmmcInd\n") );
	return( NORMAL );
}
/************************************************/
/*  GSで指定されているファイルの情報を取得する。*/
/************************************************/
long os_getFileInfo( const char *pcFileSgId, TFileInfo *tInfo  )
// const char *pcFileSgId SGKey
// TFileInfo *tInfo 結果返却用構造体
{
	char	acFileName[ 256 ];
	long	lRet = 0;
	long	lTemp = 0;
	struct	stat tBuf;
	long os_getFileLine( const char *pcFileName, const long lSize );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_getFileInfo\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** pcFileSgId:%s\n", pcFileSgId));

	lRet = os_getSG( (char *)pcFileSgId, acFileName );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:03 os_getFileInfo\n") );
		return( OSERRSG );
	}
//	DbgMsg01( DLv04, ( OutPut, "***** getSG:%s\n", acFileName));

	lRet = stat( acFileName, &tBuf );			// ファイルの状態やサイズの取得
	if( -1 == lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:04 os_getFileInfo:%s\n", strerror(errno)) );
		return( OSERRFILE );
	}

	tInfo->lSize = ((tBuf.st_size + 15) / 16) * 16;	//読み込みデータのバウンダリ調整
	
//	DbgMsg01( DLv04, ( OutPut, "***** tInfo->lSize :%ld\n", tInfo->lSize));
	
	tInfo->lLine = os_getFileLine( acFileName, tBuf.st_size );
	if( 0 == tInfo->lLine ){					// 返却値が零の時は失敗の意
		DbgMsg01( DLv05, ( OutPut, "***** Err:08 os_initEMMC\n") );
		return( OSERRFILE );
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_getFileInfo\n") );
	return( NORMAL );
}

/**************************/
/*   メッセージの格納     */
/**************************/
long os_setMsg( const char *pcFileSgId, TEmmcTableInd *ptEmmcInd, long lLine )
// const char *pcFileSgId SGKey
// TEmmcTableInd *ptEmmcInd 該当個別部先頭アドレス
// long lLine 読み込みファイル行数
{
	long	i				= 0;
	long	lRet			= 0;
	long	lBuadr			= 0;
	char	*pcMsgAdr		= NULL;
	char	*pcSearchStr	= NULL;
	char	*pcHitStr		= NULL;
	long os_ReadFile( const char *pcFileSgId, char *pcBuf );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_setMsg\n") );
	pcMsgAdr = (char *)( ptEmmcInd + lLine + 1 );	// メッセージ格納場所を指定する。

	lRet = os_ReadFile( pcFileSgId, pcMsgAdr );
	if(NORMAL != lRet)
	{
		return( lRet );
	}

	pcSearchStr	= pcMsgAdr;							// 参照先
	pcHitStr	= pcMsgAdr;							// 検索結果格納
	
//	DbgMsg01( DLv04, ( OutPut, "***** pcSearchStr :%08lx\n", pcSearchStr));
//	DbgMsg01( DLv04, ( OutPut, "***** pcHitStr    :%08lx\n", pcHitStr));
//	DbgMsg01( DLv04, ( OutPut, "***** pcHitStr    :\n%s\n", pcHitStr));
	
	for( i = 0 ; i < lLine ; i++ )
	{
		pcHitStr	= strtok( pcSearchStr, D_LF );	// 改行コードごとに切り出して格納する
		pcSearchStr	= NULL;							// 2回目以降はNULLを格納する。
		if( NULL == pcHitStr )
			break;
		
		(ptEmmcInd+i)->pcFormatAdr	= pcHitStr;
		strncpy( (ptEmmcInd+i)->acMsgID, pcHitStr + D_MSGID_POS, D_MSGID_SIZE );

//		DbgMsg01( DLv04, ( OutPut, "***** ptEmmcInd + %d:%lx\n", i, ptEmmcInd+i));
//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->acMsgID :%c%c%c%c\n", i,
//		(ptEmmcInd+i)->acMsgID[0], (ptEmmcInd+i)->acMsgID[1], (ptEmmcInd+i)->acMsgID[2], (ptEmmcInd+i)->acMsgID[3] ));

//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->pcFormatAdr:%08lx\n", i, (ptEmmcInd+i)->pcFormatAdr));
//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->pcFormatAdr:%s\n\n", i, (ptEmmcInd+i)->pcFormatAdr));
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setMsg\n") );
	return( NORMAL );
}
/**************************/
/*  ファイル内容の読込    */
/**************************/
long os_ReadFile( const char *pcFileSgId, char *pcBuf )
// const char *pcFileSgId  SGKey
// char *pcBuf  読み出しデータ格納アドレス
{
	char		acFileName[ 256 ];
	long		lRet	= 0;
	TFileInfo	tInfo;
	FILE		*fp = NULL;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_ReadFile\n") );
	lRet	= os_getFileInfo( pcFileSgId, &tInfo );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_ReadFile\n"));
		goto err_os_ReadFile;
	}

	lRet	= os_getSG( (char *)pcFileSgId, acFileName );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_ReadFile\n"));
		goto err_os_ReadFile;
	}

	fp	= fopen( acFileName, D_MODE_R );
//	DbgMsg01( DLv04, ( OutPut, "***** fp:%lx\n", fp));
	if(NULL == fp)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:03 os_ReadFile\n"));
		goto err_os_ReadFile;
	}
	
	clearerr( fp );
	lRet = fread( pcBuf, sizeof( char ), tInfo.lSize, fp );
	lRet = ferror( fp );
	if( 0 != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:04 os_ReadFile\n"));
		fclose( fp );
		goto err_os_ReadFile;
	}

	lRet = fclose( fp );
	if( EOF == lRet)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:05 os_ReadFile\n"));
		goto err_os_ReadFile;
	}
	

	DbgMsg01( DLv02, ( OutPut, "***** End os_ReadFile\n") );
	return( NORMAL );

	err_os_ReadFile:
		return( OSERRFILE );
}

/******************************/
/*  ファイルの行数を取得する。*/
/******************************/
long os_getFileLine( const char *pcFileName, const long lSize )
// const char *pcFileName  対象ファイルのパス
// const long lSize  該当ファイルの行数
{
	char	*pcBuf	= NULL; 
	long	i		= 0;
	long	lCnt	= 0;
	long	lRet	= 0;
	size_t	size	= 0;
	FILE	*fp		=NULL;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_getFileLine\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** pcFileName:%s\n", pcFileName));
	
	fp	= fopen( pcFileName, D_MODE_R );
	if( NULL == fp )
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_getFileLine\n") );
		goto end_os_getFileSize;
	}

	pcBuf	= calloc( lSize, sizeof( char ));

	clearerr( fp );
	size	= fread( pcBuf, sizeof( char ), lSize, fp );
	lRet	= ferror( fp );
	if( 0 != lRet )
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_getFileLine\n") );
		goto end_os_getFileSize;
	}

	for( i = 0 ; i < lSize ; i++ )
	{
		if( '\n' == *(pcBuf+i) )
			lCnt++;	// D_LFの数を数える=行数の計上
	}
	
	if(0 != lCnt)
		lCnt-=1;								// 終端行は余分なので1引く

	end_os_getFileSize:

		if( NULL != pcBuf ){
			free( pcBuf );
			pcBuf = NULL;
		}

		fclose( fp );

//		DbgMsg01( DLv05, ( OutPut, "***** lCnt:%ld\n", lCnt));
		DbgMsg01( DLv02, ( OutPut, "***** End os_getFileLine\n") );
		return( lCnt );
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
