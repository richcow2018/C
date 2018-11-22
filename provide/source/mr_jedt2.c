/*----------------------------------------------------------------------------------------------*/
/* ＜対象業務名＞                    故障管理業務      　　         							*/
/* ＜対象業務ＩＤ＞                  ＲＣＶ                         							*/
/* ＜サービス項目名＞                テーブルリカバリ          　   							*/
/* ＜サービス項目ＩＤ＞              JEDT2                    									*/
/* ＜モジュール名＞                  ｍｒ＿ＸＸＸＸ												*/
/* ＜モジュールＩＤ＞                ＸＸＸＸＸＸＸＸ               							*/
/* ＜モジュール通番＞                                               							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種＞                      ＡＣＥ                         							*/
/* ＜適用ＯＳ＞                      ＬＩＮＵＸ                     							*/
/* ＜開発環境＞                      ＬＩＮＵＸ                     							*/
/* ＜記述言語＞                      Ｃ言語                         							*/
/* ＜モジュール形態＞                コマンド                       							*/
/* ＜機能区分＞                                                     							*/
/* ＜対象データ＞                                                   							*/
/* ＜工程・階層区分＞                                               							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞                ＡＣＥ−ＳＭＰシステム         							*/
/* ＜開発システム番号＞              ＸＸＸＸＸＸＸＸＸＸＸＸ       							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当者名＞                  Ｓｕｐｐｌｙ                   							*/
/* ＜電話番号＞                                         							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞　　　　　　　　　　　Ｓｕｐｐｌｙ                   							*/
/* ＜設計年月日＞                    ２００３年０４月１０日	         							*/
/* ＜設計修正者名＞                  朱                             							*/
/* ＜設計修正年月日及び修正ＩＤ＞                                  							    */
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者名＞                Ｓｕｐｐｌｙ                   							*/
/* ＜ソース作成年月日＞              ２００３年０４月１０日         							*/
/* ＜ソース修正者名＞                                               							*/
/* ＜ソース修正年月日及び修正ＩＤ＞                                 							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞                ステップ                       							*/
/*---------------------------------------------------------------------------------------------	*/
/* ＜機能概要＞                                                     							*/
/*                                                                  							*/
/*      引継ぎ情報ファイルへの情報取得処理     													*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                     							*/
/*		long 	mr_jedt2(short type, char* name, char* datadr, char* data2, long num,			*/
/*						 long size, long offset)												*/
/*                                                                  							*/
/* ＜仮引数＞                                                       							*/
/*		short 	type;			ジャーナル種別 (未使用、既存のmr_jedt()互換のため)				*/
/*		char  	*name;			テーブル名														*/
/*		char  	*datadr;		更新データ格納先頭アドレス										*/
/*		char  	*data2;			更新前データアドレス (未使用、既存のmr_jedt()互換のため) 		*/
/*		long  	num;			個別部番号                   									*/
/*		long  	size;			更新データサイズ												*/
/*		long  	offset;			更新位置オフセット (TADTテーブル先頭から、						*/
/*								更新位置までの相対アドレス)										*/
/*		  																						*/
/*              なし                                                							*/
/* ＜返却値＞                                                       							*/
/*		MRNORMAL	  :  正常終了																*/
/*																								*/
/*		MRIVPARM	  :  パラメータ エラー														*/
/*																								*/
/*		MRNORMX	  	  :  条件付正常終了(発行条件チェック、ファイルアクセスエラー）				*/
/*																								*/
/*		MRENQERR	  :  資源占有エラー															*/
/*																								*/
/*		MRMNOMEM      :  バッファ確保失敗														*/
/*																								*/
/*		MRMBUFERR     :  バッファ解放失敗														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜制限事項＞         なし                                        							*/
/*                                                                  							*/
/* ＜使用外部モジュールＩＤ＞                                      	                            */
/* ＜呼出モジュールＩＤ＞                                           							*/
/*                                                                  							*/
/************************************************************************************************/

/************************************************************************************************/
/*								共通ヘッダ・ファイル                							*/
/*																								*/
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <netinet/in.h>

/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include    "tcom.h"
#include    "psect.h"
#include    "tsst.h"
#include    "tpct.h"	
#include    "mrmac.h"   
#include 	"trcv.h"	
#include    "mrcom.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "mr.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mrmirr.h"
#include    "mopcb.h"	
#include    "mrcode.h"
#include	"mcdebug.h"


/************************************************************************************************/
/*	内部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
/* file access	*/
long mr_intg(long);
long mr_writ(int, char*, long);
void mr_edit(char*, char*, char*, long, long, long);

/* 引継ぎ状態ファイルエラー処理 */
long mr_sfer(int, char);

/* 引継ぎ情報ファイルエラー処理 */
void mr_ferr(int, char);
long mr_ifer(int, char);

/************************************************************************************************/
/*	外部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
long  mo_gtbf(long, long, long**);
long  mo_frbf(long*);
void  mr_sdwn(long, short, long);
long  ms_wtop(long, short, char, char, long, long);     
TCOMPAT *mo_tagt(unsigned char*);

/************************************************************************************************/
/*		引継ぎ情報構造体							 											*/	
/************************************************************************************************/
typedef struct {
	char msg1[4];
	long offset;
	long size;
	char msg2[4];
	long num;
} TRCVDATA;

/************************************************************************************************/
/*		引継ぎ状態構造体							 							                */	
/************************************************************************************************/
typedef struct {
	long lNowaDay;
	long lNowaTime;
	char cStatus;
	char pcYobi[3];
} TRCVINFODATA;

TRCV 	*mrtrcv;

/************************************************************************************************/
/*																								*/
/*	＜関数名＞	 long mr_jedt2(short type, char* name, char* datadr, char* data2, long num, 	*/
/*							   long size, long offset)											*/
/*																								*/
/*	＜機能概要＞ 引継ぎ情報ファイルへの情報取得処理  											*/
/*																								*/
/*	＜引数＞ 																					*/
/*		  short  type;		ジャーナル種別 (未使用、既存のmr_jedt()互換のため)					*/
/*		  char   *name;    	テーブル名															*/
/*		  char   *datadr;   更新データ格納先頭アドレス											*/
/*		  char   *data2;    更新前データアドレス (未使用、既存のmr_jedt()互換のため) 			*/
/*		  long   num;	  	個別部番号                   										*/
/*		  long   size;      更新データサイズ													*/
/*		  long   offset;    更新位置オフセット (TADTテーブル先頭から、							*/
/*		  					更新位置までの相対アドレス)											*/
/*  																							*/	
/*  ＜返却値＞																					*/
/*																								*/
/*		MRNORMAL	  :  正常終了																*/
/*																								*/
/*		MRIVPARM	  :  パラメータ エラー														*/
/*																								*/
/*		MRNORMX	  	  :  条件付正常終了(発行条件チェック、ファイルアクセスエラー）				*/
/*																								*/
/*		MRENQERR	  :  資源占有エラー															*/
/*																								*/
/*		MRMNOMEM      :  バッファ確保失敗														*/
/*																								*/
/*		MRMBUFERR     :  バッファ解放失敗														*/
/*																								*/
/************************************************************************************************/
long mr_jedt2(short type, char* name, char* datadr, char* data2, long num, 	
              long size, long offset)											
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lLen = 0;							                /* 引継ぎ情報テーブルサイズ  		*/
	
	long lRetFunc= 0;										/* システムコール返却値				*/

	long lRet = 0;											/* 返却値							*/
	
	long iFd = -1;											/* ファイル ディスクリプタ  		*/
	
	char cSysCall = '0';									/* システムコールoption				*/
	
	char *pcDataBuf = NULL;									/* 更新データ領域					*/

	size_t sBufLen= 0;										/* 追加書き込むデータの長			*/
	
	TPCTPSZ *tpctp = NULL;		         					/* TPCT個別部ボインタ 				*/

	/********************************************************************************************/
	/*  外部変数領域                                                                            */
	/********************************************************************************************/
	TCOMPAT *tcomrcv;
	long tsubrcv ;											/* TRCVサブ共通部サイズ				*/
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB ボインタ   			    */
	extern  PSCPSECT    pscparea;           				/* システム共通 TSECT 領域 			*/
	extern  TRCV 		*mrtrcv;							/* 共通TRCVの領域					*/
	
	/********************************************************************************************/
	/*	入力チェック																		    */
	/********************************************************************************************/

	PRINTF("jedt2 (0) datadr = %08x\n", datadr);

	PRINTF("jedt2 (1) name = %.4s\n", name);

	PRINTF("jedt2 (2) size = %ld\n", size);
	
	PRINTF("jedt2 (3) offset = %ld\n", offset);
	
	PRINTF("jedt2 (4) num = %ld\n", num);
	
	
   	tcomrcv = mo_tagt("TRCV");								/* TRCVの先頭を求め					*/

	tsubrcv = tcomrcv->tcomsbps ;							/* サブ共通部サイズ取得				*/

	if(tcomrcv == 0)
	{

		lRet = MRNORMX;
		
		PRINTF("(0) mr_trcv - motagt  = %ld\n", lRet);
		
		goto exit_to_main;
	}

	mrtrcv = (TRCV*)((char*)tcomrcv + sizeof(TCOMPAT) + tsubrcv);

	

	PRINTF("jedt2 (4.1) mrtrcv = %08x\n", mrtrcv);
														/* 引継ぎ要テーブルサイズ		   		*/
	lLen = mopcbp->mopssstp->tsstrc0l + mopcbp->mopssstp->tsstrc0a;	
	
	PRINTF("jedt2 (5) lLen = %ld\n", lLen);
	
    tpctp = (TPCTPSZ *)MRTBLAD( pscparea.pscpctad, pscparea.pscpctno+1 );
                                       					/* TPCT個別部アドレスを設定する   		*/
                                        					
   	PRINTF("(1.4.1) jedt2 - tpctp = %x\n", tpctp);

	if( (datadr == NULL) || (size <= 0) || (offset >= lLen) || /* 引数のチェック 		        */ 
	    ((offset + size) > lLen) || (offset < 0) ) 
	{
		lRet = MRIVPARM;
		
		PRINTF("jedt2 (6) lRet=%ld\n", lRet);
		
	
		goto exit_to_main;									/* 終了処理							*/
 	}

	/********************************************************************************************/
    /*  発行条件チェック（システム構成のチェック）   		                                    */
	/********************************************************************************************/
    if( (mopcbp->mopssstp->tsstsysd == MOYOBIKK) || 
        (mopcbp->mopssstp->tsstsysc == TSSTCING) )
    {      													/* シンプレックス構成或は			*/
                                        					/* システム構成がホットスタンバイの */
    														/* 予備系の時						*/
        
        lRet = MRNORMX;	                   					/* リータンする                     */

		PRINTF("jedt2 (7) lRet=%ld\n", lRet);
        
        goto exit_to_main;									/* 終了処理							*/
    }
   
    /********************************************************************************************/
    /*  発行条件チェック（ＳＭＰ運転モードのチェック）                   						*/
    /********************************************************************************************/
    if( ( (mopcbp->mopssstp->tsstprmd[0] & 0x0000000FL) != 0x00000000L) )
    { 	    	            								/* プログラムモードが   			*/
     														/* オンラインモードがない時			*/
    	lRet = MRNORMX; 			                  		/* リータンする                     */
    	
		PRINTF("jedt2 (8) lRet=%ld\n", lRet);
    	
    	goto exit_to_main;									/* 終了処理							*/
    } 

    /********************************************************************************************/
    /*  発行条件チェック（リカバリ要/不要チェック）		  					                    */
    /********************************************************************************************/

    if(mopcbp->mopscstp->tcsttrcv != TCSTTRNE)
    {                                    					/* リカバリ要/不要情報が            */
                                     						/* リカバリ不要の時 	            */
        lRet = MRNORMX;	                					/* リータンする  					*/
        
 		PRINTF("jedt2 (9) lRet=%ld\n", lRet);
    
    	goto exit_to_main;									/* 終了処理							*/
    }                     				

    /********************************************************************************************/
    /*  引継ぎ情報ファイル状態チェック				  					                        */
    /********************************************************************************************/
    if(mrtrcv->trcvjfst == TRCVFERR)
    {														/* 引継ぎ情報ファイルステータスは   */
															/* 故障である時			            */
		lRet = MRNORMX;										/* リータンする  					*/

		PRINTF("jedt2 (10) lRet=%ld\n", lRet);

		goto exit_to_main;									/* 終了処理							*/
	} 
    
    /********************************************************************************************/
    /*  TPCT キャンセル不可フラグ(JNL占有)をONにする  											*/
    /********************************************************************************************/
   PRINTF("jedt2 (10.1) ltpctp->tpctncaf = %lx\n", tpctp->tpctncaf);     
  
  
    MRBITON(tpctp->tpctncaf, TPCTJNL);						/* TPCT キャンセル不可フラグ		*/
                             							   	/* (JNL占有)をONにする     			*/
                             							   	
    PRINTF("jedt2 (10.2) tpctp->tpctncaf = %lx\n", tpctp->tpctncaf);     
    
    /********************************************************************************************/
    /*  更新テーダを編集する						  					                        */
    /********************************************************************************************/                                         					
	lRetFunc = mo_gtbf(MOLMPBF, size + INFOSIZE, (long**) &pcDataBuf);
															/* デーラ編集の領域を確保       	*/
															
	PRINTF("jedt2 (11) lRetFunc = %ld\n", lRetFunc);

	if(lRetFunc < (size + INFOSIZE))
	{
		lRet = MRMNOMEM;
		
		PRINTF("jedt2 (12) lRet = %ld\n", lRet);
		
		goto exit_to_main;									/* 終了処理							*/
	}

	mr_edit(pcDataBuf, name, datadr, num, size, offset);	/* デーラを編集する処理を行い		*/													
				
	/********************************************************************************************/
    /*  引継ぎ情報ファイルをオープンする	  													*/
    /********************************************************************************************/
    iFd = open(mrtrcv->trcvjpnm, O_SYNC | O_WRONLY | O_APPEND);
    														/* ファイルをオーブンする       	*/
    														
	PRINTF("jedt2 (13) iFD = %ld\n", iFd);
    														
	if(iFd == SYSERROR)										/* オーブンができなかったら異常終了	*/
    {
		cSysCall =  OPENOPTI;								/* システムコール(open)エラーの設定	*/
		
		lRet = MRNORMX;										/* リータンする  					*/ 
		
		PRINTF("jedt2 (13) lRet = %ld\n", lRet);

		goto error_prc;										/* エラー処理を行い					*/
	}

	/********************************************************************************************/
    /*  引継ぎ情報ファイルをロックする		  													*/
    /********************************************************************************************/
    
    lRetFunc= lockf(iFd, F_LOCK, 0);						/* 引継ぎ情報ファイルをロックする   */
    
    														
	PRINTF("jedt2 (14) lRetFunc = %ld\n", lRetFunc);
    
    if(lRetFunc == SYSERROR)								/* ファイルのロックができなかったら	*/
    {														/* 異常終了                         */

		cSysCall = LOCKOPTI;								/* システムコール(lockf)エラーの設定*/
    
		lRet =  MRENQERR; 

		PRINTF("jedt2 (15) lRet = %ld\n", lRet);
		
		goto error_prc;										/* エラー処理を行い					*/
		
	}
	
	/********************************************************************************************/
    /*  引継ぎ情報ファイルに更新データを追加書き込む											*/
    /********************************************************************************************/
	sBufLen= mr_intg(size) + BUDASIZE;

	
	lRetFunc = mr_writ(iFd, pcDataBuf, sBufLen);  			/* 追加書き込むデータをファイルに   */  
															/* 追加書き込む					    */ 
															
	PRINTF("jedt2 (16) lRetFunc = %ld\n", lRetFunc);
 

	if(lRetFunc != MRNORMAL)								/* 正常じゃない時異常処理を実行する	*/
	{

		cSysCall = WRITOPTI;								/* システムコール(write)エラーの設定*/
		
		lRet = MRNORMX;										 

		PRINTF("jedt2 (17) lRet = %ld\n", lRet);
						
		goto error_prc;										/* エラー処理	  					*/
	
	}

	lRetFunc = mr_writ(iFd, ENDDPATN, PATNSIZE);  			/* データ終端パターンをファイルに   */
															/* 書き込む							*/ 	

	PRINTF("jedt2 (18) lRetFunc = %ld\n", lRetFunc);
	
	if(lRetFunc != MRNORMAL)								/* 正常じゃない時異常処理を実行する	*/
	{
		cSysCall = WRITOPTI;								/* システムコール(write)エラーの設定*/

		lRet = MRNORMX;										 
		
		PRINTF("jedt2 (19) lRet = %ld\n", lRet);
		
		goto error_prc;										/* エラー処理	  					*/
	}
	
	if(iFd >= 0)
	{
		close(iFd);
	}

	goto exit_to_main;										/* 終了処理							*/

	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

error_prc:
	mr_ferr(iFd, cSysCall);									/* 引継ぎ情報ファイルのエラー処理	*/

	PRINTF("jedt2 (20) ERROR iFd = %ld\n", iFd);

	PRINTF("jedt2 (20.1) mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);
	
	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* 二重故障の場合					*/	 
	{
		mr_sdwn(MRDOWN, MRESYSINT, MRDJNLWERR);				/* mr_sdwn()を発行					*/
	}			
		
exit_to_main:

	MRBITOFF(tpctp->tpctncaf, TPCTJNL);						/* TPCT キャンセル不可フラグ		*/
	                         							   	/* (JNL占有)をOFFにする	   			*/
	                         							   	
	PRINTF("jedt2 (21) tpctncaf=%lx\n", tpctp->tpctncaf);
                         							   	
	if(pcDataBuf != NULL)									/* 取られている領域を解放する		*/
	{
		
		lRetFunc = mo_frbf((long *)pcDataBuf);				/* バッファを解放する				*/
	
		PRINTF("jedt2 (22) lRetFunc = %ld\n", lRetFunc);
		
		if(lRetFunc != MRNORMAL)							/* 異常の時							*/
		{
			lRet = MRMBUFERR;
			
			PRINTF("jedt2 (23) lRet = %ld\n", lRet);
		}
	}

	PRINTF("jedt2 (24) EXIT lRet = %ld\n", lRet);

	return(lRet);											/* 終了処理							*/
    
}    	
   
 
/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void mr_edit(char* pcDataBuf, char* name, char* datadr, long num, 				*/
/*							long size, long offset)												*/
/*																								*/
/*	＜機能概要＞  更新データを編集する															*/
/*  																							*/
/*	リターン:																					*/
/*			なし																				*/
/************************************************************************************************/
void mr_edit(char* pcDataBuf, char* name, char* datadr, long num, long size, long offset)
{
	
  	long position = 0;											   /* 更新テーダ項目の位置 		*/
	
	long lDatalen = 0;											   /* 更新データの4倍数         */

	long lOffSet = htonl(offset);								   /* バイト反転のoffset		*/	
	
	long lSize = htonl(size);									   /* バイト反転のsize			*/
	
	long lNum = htonl(num); 									   /* バイト反転のnum			*/
	
	memcpy(pcDataBuf, STRTPATN, PATNSIZE);				  		   /* 開始パータンの編集    	*/
	
	position += PATNSIZE;										   /* 4 byteを加える			*/	

	PRINTF("mr_edit (1) size=%ld\n", size);

	memcpy(pcDataBuf+position, &lOffSet, sizeof(long));	  		   /* offsetの編集  			*/

	position += PATNSIZE;										   /* 4 byteを加える			*/
	
	PRINTF("mr_edit (2) offset=%ld\n", offset);
	
	memcpy(pcDataBuf+position, &lSize, sizeof(long));			   /* 更新データサイズの編集    */

	position += PATNSIZE;										   /* 4 byteを加える			*/
	
	memcpy(pcDataBuf+position, name, sizeof(long));                /* テーブル名                */

	PRINTF("mr_edit (3) name=%.4s\n", name);

	position += PATNSIZE;										   /* 4 byteを加える            */ 

	memcpy(pcDataBuf+position, &lNum, sizeof(long));	 		   /* 個別部番号				*/

	position += PATNSIZE;										   /* 4 byteを加える            */
	
	PRINTF("mr_edit (4) num=%ld\n", num);
	
	memcpy(pcDataBuf + position, datadr, size);					   /* 更新データの編集			*/

	lDatalen = mr_intg(size);							   		   /* 4倍数の求め				*/

	PRINTF("mr_edit (5) lDatalen=%ld\n", lDatalen);
	
	if((lDatalen - size) > 0);									   /* 4倍数でない場合は、後ろ   */
	{		
		memset(pcDataBuf + (position+size), 0x00, lDatalen-size);
	}

	return;
}
	
	
