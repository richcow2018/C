/************************************************************************************************/
/*	著作権								                               					*/
/*			  																*/
/*																			*/
/*																								*/
/*																								*/
/*	収容物									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 共通関数													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 ＸＸＸＸＸＸＸ												*/
/* ＜モジュールＩＤ＞				 os_trcget													*/
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
/* ＜開発システム名＞				 ＬＡＬａ－ＳＭＰシステム									*/
/* ＜開発システム番号＞ 			 ＰＰ４０Ｂ００１２２０										*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞					 			    	*/
/* ＜電話番号＞ 														*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞ 														*/
/* ＜設計年月日＞					 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 				*/
/* ＜ソース作成年月日＞ 			 									*/
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		ファイルの生成																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*         void os_startTrace( void )                                                           */
/*																								*/
/* ＜仮引数＞																					*/
/*																								*/
/* ＜返却値＞																					*/
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
/************************************************************************************************/
/* 改造番号 ：TBCS0288                                                                          */
/* 改造内容 ：終端コードを必ず残す為に、終端コードを削除する処理を削除                          */
/*          ：終端コード以下（未格納領域）を０で初期化するように初期化処理を追加                */
/* 改造日   ：2003.08.19                                                                        */
/* 改造者   ：Supply    飯田                                                                    */
/************************************************************************************************/

/******************************** 標準ヘッダ・ファイル ******************************************/
// テーブル構造必須項目
// トレース先頭アドレス
// トレース終端アドレス
// トレース領域長
// 次トレース情報取得

/************************************************************************************************/
/*								共通ヘッダ・ファイル                							*/
/*																								*/
/************************************************************************************************/
#include	<stdio.h>
#include	<stdlib.h>
#include	<syslog.h>
#include	<stdarg.h>
#include	<string.h>

/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include "os_trcget.h"
#include "os_trcget_ins.h"

#include "os_SG.h"


void *pvTraceArea = NULL;								// トレース領域先頭アドレス
TTraceInfo	*tTraceInfo = NULL;

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 void os_startTrace( void )														*/
/*																								*/
/*	＜機能概要＞ トレースの初期処理                   											*/
/*  																							*/
/*																								*/
/************************************************************************************************/
void os_startTrace( void )
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	int iRet = 0;										// SG関数の返却値
	
	long lTraceSize = 0;								// トレースサイズ
	
	long lPoint = 0;									// エラー識別子

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* 	初期化								  */
	/******************************************/
	
	iRet = os_getSG(D_SG_TRACE_LEN, &lTraceSize);		// トレースサイズを取り込む
	
	if(iRet != NORMAL)
	{
		lPoint = 1000;
			
		syslog(LOG_ERR, D_SYSLOGMSG, lPoint);
	}
	else if (lTraceSize > 3)
	{
	
														// トレースサイズの領域確保
		pvTraceArea =  calloc(lTraceSize+8, sizeof(long) );	

		if (pvTraceArea == NULL)
		{
			lPoint = 1001;
			
			syslog(LOG_ERR, D_SYSLOGMSG, lPoint);
		}
		else
		{

														// トレースTitleを設定
			strncpy((char*)pvTraceArea, D_TRACEAREA, D_TRCARELEN );	
	
														// トレース先頭アドレス
			*((long*)pvTraceArea+4)  = (long)(((long*)pvTraceArea) + 8);	
	
														// トレース終端アドレス
			*((long*)pvTraceArea+5) = (long)(((long*)pvTraceArea) + (lTraceSize-1));

														// トレース領域長
			*((long*)pvTraceArea+6) = (long)(*((long*)pvTraceArea+5) - *((long*)pvTraceArea+4));

														// 次トレースアドレスを設定	
			*((long*)pvTraceArea+7) = (long)(((long*)pvTraceArea) + 8);
		

			tTraceInfo = pvTraceArea + D_TRCARELEN;
		}

	}
	
}

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 long os_trcget1( short mid, short tid, char *area, long len )					*/
/*																								*/
/*	＜機能概要＞ アドレス指定でトレース情報を取得する  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - モジュールID														    */
/*		パラメーター(2)	- トレース情報ID													    */
/*		パラメーター(3)	- 取得情報先頭アドレス													*/
/*		パラメーター(4) - 取得情報長															*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*																								*/
/************************************************************************************************/
void os_trcget1( short mid, short tid, char *area, long len )
{
	
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lPoint	= 0;
	long lRet	= 0;									// 関数返却情報

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* 引数チェック     					  */
	/******************************************/
	
//	goto end_process;
	
	
	if( NULL == pvTraceArea ){							// トレース領域の確認
		lPoint =1010;
		
		//goto end_trcget2;
		
		// 暫定 20030123 //	
		goto end_process;
	}
	
	
	if( 0 > mid ){										// モジュールIDの確認
		lPoint = 1011;
		goto	err_trcget1;
	}
	
	if( 0 > tid ){										// トレース情報IDの確認
		lPoint = 1020;
		goto	err_trcget1;
	}

	
	if( NULL == area ){									// 取得情報先頭アドレスの確認
		lPoint = 1030;
		goto	err_trcget1;
	}

	
	if( 1 > len ){										// 取得情報長の確認
		lPoint = 1040;
		goto	err_trcget1;
	}
	
	lRet = os_CheckAreaLen( len );						// トレース情報長の確認
	
	
	if( NORMAL != lRet ){
		lPoint = 1050;
		goto	err_trcget1;
	}

	os_setTraceArea( len );								// トレース情報設定位置の確定
	
	lRet = os_setTraceInfo( mid, tid, area, len, D_TRCACGET1);		// トレース情報の設定
	
	if( 0 != lRet ){
		lPoint = 1060;
		goto	err_trcget1;
	}

	os_setNextTraceArea( len );							// 次トレース情報設定位置の設定
	
// 暫定 20030123 //	
end_process:	
	
	return;

/******************************************/
/* エラー処理	     					  */
/******************************************/	
err_trcget1:

	DbgMsg01( DLv04, ( OutPut, "***** Trace Error:Point=%ld\n", lPoint) );
	
	/********************************************************************************************/
	/*	 処理終了																			    */
	/********************************************************************************************/
	return;

}



/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long os_trcget2( short mid, short tid, long count, ... )						*/
/*																								*/
/*	＜機能概要＞ long長の取得データ項目の個数指定でトレース情報を取得する						*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - モジュールID格納アドレス											    */
/*		パラメーター(2)	- トレース情報ID格納アドレス											*/
/*		パラメーター(3) - 取得データ項目数を指定											    */
/*		パラメーター(4) ～ (n) - 取得データ項目数分												*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*																								*/
/************************************************************************************************/
void os_trcget2( short mid, short tid, long count, ... )
{
	
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long	lRet		= 0;							// 関数返却情報
	long	i			= 0;
	long	lDataLen	= 0;
	long	lPoint		= 0;

	long	*plData		= NULL;							// 可変引数格納用
	va_list	args;										// 可変引数展開用

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	/******************************************/
	/* 引数チェック     					  */
	/******************************************/

	/* 暫定 20030127 */	
//	goto end_process;

	
	if( NULL == pvTraceArea ){							// トレース領域の確認
		lPoint =1070;
		
		//goto end_trcget2;
		
		/* 暫定 20030123 */	
		goto end_process;
	}


	if( 0 > mid ){										// モジュールIDの確認
		lPoint =1071;
		
		goto end_trcget2;
	}
	

	if( 0 > tid ){										// トレース情報IDの確認
		lPoint =1080;

		goto end_trcget2;
	}
	
	
	lDataLen = sizeof( long ) * count;					// 可変引数格納領域の確保


	if( 0 < count )
	{	


		lRet = os_CheckAreaLen( lDataLen );				// トレース情報長の確認
		

		if( 0 != lRet ){
			
			lPoint =1100;
			goto end_trcget2;
		}

		plData	= calloc( lDataLen + 1, sizeof( long ) );
		
		va_start( args, count );						// 可変引数の取出し。
	
		for( i = 0 ; i < count ; i++ ){
			*(plData + i) = va_arg( args, long );
		}

		va_end( args );

	}
	
	os_setTraceArea( lDataLen );						// トレース情報設定位置の確定
	
	
														// トレース情報の設定	
	lRet = os_setTraceInfo( mid, tid, plData, lDataLen, D_TRCACGET2 );
	
	if( 0 != lRet ){
		lPoint =1110;
		goto end_trcget2;
	}

	os_setNextTraceArea( lDataLen );					// 次トレース情報設定位置の設定
	
	

/* 暫定 20030127 */	          
end_process:

	if( NULL != plData )								// 可変引数格納領域の解放
	{
		free( plData );
	}
 
	return;
	
/******************************************/
/* エラー処理	     					  */
/******************************************/
end_trcget2:

	DbgMsg01( DLv04, ( OutPut, "***** Trace Error:Point=%ld\n", lPoint) );
	
	if( NULL != plData )								// 可変引数格納領域の解放
	{
		free( plData );
	}
	
	/********************************************************************************************/
	/*	 処理終了																			    */
	/********************************************************************************************/
	return;	
}




/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long os_setTraceInfo( short sMid, short sTid, void *plArea, long lLen)			*/
/*																								*/
/*	＜機能概要＞ 対象トレース情報の設定				  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - モジュールID														    */
/*		パラメーター(2)	- トレース情報ID													    */
/*		パラメーター(3)	- 取得情報先頭アドレス													*/
/*		パラメーター(4) - 取得情報長															*/
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*																								*/
/************************************************************************************************/
long os_setTraceInfo( short sMid, short sTid, void *plArea, long lLen, long lType)
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	short	*psMidArea;
	short	*psTidArea;
	void	*pvTraceInfoArea;
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
									
														// 格納領域取得
	os_getArea(&psMidArea, &psTidArea, &pvTraceInfoArea);
	
	os_setMid(psMidArea, sMid);							// モジュールID格納アドレス
	
	os_setTid(psTidArea, sTid );						// トレース情報ID格納場所
														
														// 取得データサイズ+取得データ	
	os_setTraceData(pvTraceInfoArea, plArea, lLen, lType);		
	

	/********************************************************************************************/
	/*	 処理終了																			    */
	/********************************************************************************************/
	return( NORMAL );
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_setTraceData( void *pvTraceInfoArea, void *plArea, long lLen )			*/
/*																								*/
/*	＜機能概要＞ トレース情報の格納					  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - トレース情報格納アドレス											    */
/*		パラメーター(2)	- 取得情報先頭アドレス													*/
/*		パラメーター(3) - 取得情報長															*/
/*																								*/
/************************************************************************************************/
void os_setTraceData( void *pvTraceInfoArea, void *plArea, long lLen, long lType )
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long	lInfoLen 	= 0;							// 取得データ長（編集用）
	long	lTrmLen		= 0;							// 終端長(0x0の長さ)
	
	void    	*pvNextAdr	= tTraceInfo->pvNextAdr;

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	lInfoLen	= os_getTraceLen( lLen );		
	lTrmLen		= lInfoLen - lLen;
		
	*((long*)pvTraceInfoArea) = lType;					// プロセスIDを設定	
	
	if( lInfoLen > 0 )
	{
		memset( pvTraceInfoArea + sizeof(long), 0, lInfoLen );
		
														// トレース情報エリアを設定					
		memcpy(pvTraceInfoArea + sizeof(long), plArea, lLen );		
		
	
														// トレース情報エリアサイズを設定
		*((long*)pvTraceInfoArea + ((lInfoLen + 4) / 4)) = lInfoLen;		
	}
	else
	{
		memset( pvTraceInfoArea + sizeof(long), 0, sizeof(long) );
		
	}
	

	DbgDmp02( DLv04, ("***** pvTraceInfoArea INFORMATION  *****", 
	          pvNextAdr, lInfoLen + 12,1,0));
	          

	if( lTrmLen < 0 ) 									// トレース情報が４の倍数
	{													// でない時の対処	
		memcpy( pvTraceInfoArea + lLen, 0x0, lInfoLen - lLen );
	}
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_setTid( short *psTidArea, short sTid )									*/
/*																								*/
/*	＜機能概要＞ トレース情報IDの格納				  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - トレース情報ID格納アドレス										    */
/*		パラメーター(2)	- トレース情報ID													    */
/*																								*/
/************************************************************************************************/
void os_setTid( short *psTidArea, short sTid )
{
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	*psTidArea = sTid;									// トレース情報IDを設定
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_setMid( short *psMidArea, short sMid )									*/
/*																								*/
/*	＜機能概要＞ モジュールIDの格納					  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - モジュールID格納アドレス											    */
/*		パラメーター(2)	- モジュールID														    */
/*																								*/
/************************************************************************************************/
void os_setMid( short *psMidArea, short sMid )
{
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
		
	*((long*)psMidArea) = sMid; 						// モジュールIDを設定
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_getArea( short **ppsMidArea, short **ppsTidArea, 						*/
/*								 void **ppvTraceInfoArea )										*/
/*																								*/
/*	＜機能概要＞ 格納先情報の取得					  											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - モジュールID格納アドレス											    */
/*		パラメーター(2)	- トレース情報ID格納アドレス											*/
/*		パラメーター(3) - トレース情報格納アドレス											    */
/*																								*/
/************************************************************************************************/
void os_getArea( short **ppsMidArea, short **ppsTidArea, void **ppvTraceInfoArea )
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	void    	*pvNextAdr	= tTraceInfo->pvNextAdr;

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	
	*ppsMidArea			= pvNextAdr;					// モジュールID格納場所

	*ppsTidArea			= ((short*)pvNextAdr) + 1;		// トレース情報ID格納場所

	*ppvTraceInfoArea	= ((long*)pvNextAdr) + 1;		// プロセスID+取得データ
														// +取得データサイズ
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long os_CheckAreaLen( long lLen)												*/
/*																								*/
/*	＜機能概要＞ 指定されたトレース情報長とトレース領域長との確認								*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - 指定されたトレース情報長											    */
/*																								*/
/*	リターン:																					*/
/*		成功 (NORMAL)																			*/
/*		失敗 (-1)																				*/
/************************************************************************************************/
long os_CheckAreaLen( long lLen)
{
	
	long	lMaxLen = 0;

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	lMaxLen = tTraceInfo->lTraceSize;	
	
	if( lLen > lMaxLen  ) 								// 最大長を超えている時
	{
		return( -1 );
	}

	/********************************************************************************************/
	/*	 処理終了																			    */
	/********************************************************************************************/

	return(NORMAL);										// 最大長の範囲内の時

}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_setTraceArea( long lLen )												*/
/*																								*/
/*	＜機能概要＞ 対象トレース情報が格納可能かの確認												*/
/*																								*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - 指定されたトレース情報長											    */
/*																								*/
/*																								*/
/************************************************************************************************/
void os_setTraceArea( long lLen )
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long	lInfoLen = 0;								// 取得データ長（編集用）
	void	*pvStartAdr;
	void	*pvEndAdr;
	void	*pvNextAdr;

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
//	TTraceInfo	*tTraceInfo = pvTraceArea+16;

	pvStartAdr	= tTraceInfo->pvStartAdr;				// トレース領域の先頭アドレス
	pvEndAdr	= tTraceInfo->pvEndAdr;					// トレース領域の終端アドレス
	pvNextAdr	= tTraceInfo->pvNextAdr;				// 次トレース情報取得アドレス
	
	lInfoLen = os_getTraceLen( lLen ) + 12;				// lLenを4の倍数に整え、
														// 取得データサイズ領域と終端コード
														// 領域分を加える。

	if( (pvNextAdr + lInfoLen)  > pvEndAdr ){			// 取得情報がトレース領域
														// を超過する場合。
														
                                                        // TBCS0288 終端コード削除処理  削除

        if( (long)(pvEndAdr-pvNextAdr) > 0 )            // TBCS0289 格納領域がある場合
		{
                                                        // TBCS0289 終端コード以下を削除する。
		    memset( ( (long*)pvNextAdr + 1 ) , 0 , (long)( pvEndAdr - pvNextAdr ) );
		}	
														// 次回情報取得位置を
		tTraceInfo->pvNextAdr	= pvStartAdr;			// トレース領域の先頭にする。
		
	}
	
}



/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long os_getTraceLen( long lLen )												*/
/*																								*/
/*	＜機能概要＞ 取得情報サイズを4の倍数に整える												*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - 指定されたトレース情報長											    */
/*																								*/
/*	リターン:																					*/
/*		成功 (4の倍数)																			*/
/************************************************************************************************/
long os_getTraceLen( long lLen )
{
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

	long lRetLen = 0;
	
	lRetLen = (( lLen + 3 ) / 4 ) * 4;					// 4倍数の計算		
	
	if( 0 > lRetLen )
	{
		lRetLen = 0;
	}
	
	return( lRetLen );
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void os_setNextTraceArea( long lLen )											*/
/*																								*/
/*	＜機能概要＞ 次トレース情報取得アドレスを設定する。											*/
/*  																							*/
/*  パラメーター:																				*/
/*		パラメーター(1) - 指定されたトレース情報長											    */
/*																								*/
/************************************************************************************************/
void os_setNextTraceArea( long lLen )
{
	long	lInfoLen 	= 0;							// 取得データ長（編集用）
	void	*pvNextAdr	= NULL;

	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/
	
	pvNextAdr = tTraceInfo->pvNextAdr;					// 次トレース情報取得アドレス	
	
	lInfoLen	= os_getTraceLen( lLen ) + 12;			// lLenを4の倍数に整え、
														// 取得データサイズ領域分を加える。
	pvNextAdr	+= lInfoLen;
	
	(long*)tTraceInfo->pvNextAdr = (long)pvNextAdr;		// 次トレース情報取得アドレス

	*((long*)pvNextAdr)	= 0xffffffff;					// 終端コードの格納
	

	
}

