/*----------------------------------------------------------------------------------------------*/
/* ＜対象業務名＞                    故障管理業務      　　         							*/
/* ＜対象業務ＩＤ＞                  ＲＣＶ                         							*/
/* ＜サービス項目名＞                テーブルリカバリ          　   							*/
/* ＜サービス項目ＩＤ＞              trcv	                 									*/
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
/* ＜電話番号＞                      03-3341-5504                   							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞　　　　　　　　　　　Ｓｕｐｐｌｙ                   							*/
/* ＜設計年月日＞                    ２００３年０４月１０日	         							*/
/* ＜設計修正者名＞                  朱                             							*/
/* ＜設計修正年月日及び修正ＩＤ＞                                  							    */
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者名＞                Ｓｕｐｐｌｙ                   							*/
/* ＜ソース作成年月日＞              ２００３年０４月１０日	        							*/
/* ＜ソース修正者名＞                朱                     	      							*/
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０６月０５日  (TBCS0119)							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞                ステップ                       							*/
/*---------------------------------------------------------------------------------------------	*/
/*                                                                  							*/
/* ＜機能概要＞ 引継ぎ情報ファイルからのテーブル復元処理										*/
/*																								*/
/*	＜引数＞ 																					*/
/*				 なし																			*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                     							*/
/*			long 	mr_trcv()																	*/
/*                                                                  							*/
/* ＜仮引数＞                                                       							*/
/*		  																						*/
/*              なし                                                							*/
/* ＜返却値＞                                                       							*/
/*		MRNORMAL：	正常終了																	*/
/*																								*/
/*		MRIVPARM：	パラメータ エラー															*/
/*																								*/
/*		MRNORMX	：	条件付正常終了																*/
/*																								*/
/*															コメント削除 SSLA0036				*/
/*																								*/
/*		SYSERROR:   FIPファイル不整合エラー														*/
/*																								*/
/*		MRFILERR:   ファイルアクセスエラー														*/
/*																								*/
/*		MRNOMEM		バッファ確保失敗						コメント追加 TBCS0156				*/
/*																								*/
/*		MRNORRCV:   テーブルリカバリ処理実施				コメント追加 SSLA0038				*/
/*----------------------------------------------------------------------------------------------*/
/* ＜制限事項＞         なし                                        							*/
/*                                                                  							*/
/* ＜使用外部モジュールＩＤ＞                                      	                            */
/* ＜呼出モジュールＩＤ＞                                           							*/
/*                                                                  							*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0119                                                      					*/
/* 改造内容 ：Sトレース機能を追加、ユザ権限処理を追加                          					*/
/* 改造日   ：2003.06.05                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0156                                                                          */
/* 改造内容 ：ファイルアクセスエラー時の返却値が正しい値でないので正しい値を返すように修正      */
/*            テーブル復元処理で処理の流れがPD書どおりになっていないのでPD書どおりに修正        */
/* 改造日   ：2003.06.20                                                    					*/
/* 改造者   ：Supply    飯田                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0163                                                                          */
/* 改造内容 ：SMP関数エラーメッセージ(SRRC)、日付時刻出力の判断処理を追加						*/
/* 改造日   ：2003.06.24                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0187                                                                          */
/* 改造内容 ：SMP関数エラーメッセージ(SRRC)で正しい関数名を修正									*/
/* 改造日   ：2003.07.02                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0188                                                                          */
/* 改造内容 ：mf_srcv返却値の判断処理を修正														*/
/* 改造日   ：2003.07.02                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：SSLA0036                                                                          */
/* 改造内容 ：mo_gtbf()/mo_frbf()で確保/解放しているメモリを									*/
/*			  malloc()/free()で確保/解放するように修正											*/
/* 改造日   ：2003.07.04                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：SSLA0038                                                                          */
/* 改造内容 ：返却値に「テーブルリカバリ処理実施(MRNORRCV)」を追加								*/
/* 改造日   ：2003.07.08                                                    					*/
/* 改造者   ：Supply    朱	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* 改造番号 ：TBCS0200                                                                          */
/* 改造内容 ：初期化処理でファイルアクセスエラー番号が出力されていないので出力するように修正    */
/* 改造日   ：2003.07.09                                                                        */
/* 改造者   ：Supply   飯田                                                                     */
/************************************************************************************************/
/************************************************************************************************/
/*								共通ヘッダ・ファイル                							*/
/*																								*/
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <netinet/in.h>


/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include    "tcom.h"
#include    "psect.h"
#include    "mr.h"
#include    "tsst.h"	
#include    "tpct.h"	
#include    "mrmac.h"   
#include 	"trcv.h"	
#include    "mrcom.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
//#include    "mrmirr.h"
#include    "mrcode.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mopcb.h"
#include	"mcdebug.h"
#include	"mrmsg.h"
#include    "mo_wlg.h"
#include    "mf.h"														/* TBCS0188				*/

/************************************************************************************************/
/*      define function name for mo_wlg4							 							*/
/*                													 							*/
/************************************************************************************************/
#define MR_TRCV		0x6d725f74, 0x72637620								/* TBCS0119				*/
#define	MR_REST		0x6d725f72, 0x65737420								/* TBCS0119				*/
#define	MR_RECV		0x6d725f72, 0x65637620								/* TBCS0119				*/
#define	MR_KAIH		0x6d725f6b, 0x61696820								/* TBCS0119				*/
#define	MR_FRCE		0x6d725f66, 0x72636520								/* TBCS0119				*/
#define MR_INFF		0x6d725f69, 0x6e666620								/* TBCS0119				*/
#define MR_STTF		0x6d725f73, 0x74746620								/* TBCS0119				*/
#define MR_STPR		0x6d725f73, 0x74707220								/* TBCS0119				*/


/************************************************************************************************/
/*	内部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
/* file utility */
long mr_intg(long);
long mr_writ(int, char*, long);
long mr_read(int, char*, long);

/* 再開始処理 */
long mr_rest();
void mr_kaih();
long mr_recv();
void mr_frce();

/* 引継ぎ状態ファイルエラー処理 */
long mr_sfer(int, char);

/* 引継ぎ情報ファイルエラー処理 */
void mr_ferr(int, char);
long mr_ifer(int, char);

/* 開始処理 */
long mr_stpr();
long mr_inff();												
long mr_sttf();

/************************************************************************************************/
/*	外部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
char 	syscom_get_bootmode();
long 	mf_srcv();
long 	mo_gtbf(long, long, long**);
long 	mo_frbf(long*);
long 	mo_date(long*, long*);
long 	ms_wtop(long, short, char, char, long, long);     
TCOMPAT *mo_tagt(unsigned char*);
void	mo_wlg4();        

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
/*	＜関数名＞	 long mr_trcv()																	*/
/*																								*/
/*	＜機能概要＞ 引継ぎ情報ファイルからのテーブル復元処理										*/
/*																								*/
/*	＜引数＞ 																					*/
/*				 なし																			*/
/*  																							*/
/*																								*/
/*  ＜返却値＞																					*/
/*																								*/
/*		MRNORMAL：	正常終了（）																*/
/*																								*/
/*		MRIVPARM：	パラメータ エラー															*/
/*																								*/
/*		MRNORMX	：	条件付正常終了																*/
/*																								*/
/*																コメント削除 SSLA0036			*/
/*																								*/
/*		SYSERROR:   FIPファイル不整合エラー														*/
/*																								*/
/*		MRFILERR:   ファイルアクセスエラー														*/
/*																								*/
/*		MRNORRCV:   テーブルリカバリ処理実施					コメント追加 SSLA0038			*/
/*																								*/
/************************************************************************************************/
long mr_trcv()
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	long lRet = MRNORMAL;									/* 返却値							*/
	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/
	
	/********************************************************************************************/
	/*  外部変数領域                                                                            */
	/********************************************************************************************/
	TCOMPAT *tcomrcv;
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB ボインタ         		*/
	extern TRCV *mrtrcv;									/* 共通TRCVの領域					*/
	long tsubrcv;											/* TRCVサブ共通部サイズ				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* メッセージ	TBCS0163			*/

		
    /********************************************************************************************/
    /*  発行条件チェック（ＳＭＰ運転モードのチェック）                   						*/
    /********************************************************************************************/

	mo_wlg4(MR_TRCV, WINSC, 0, 0);							/* TBCS0119							*/
    
   	tcomrcv = mo_tagt("TRCV");								/* TRCVの先頭アドレスを求め			*/

	if(tcomrcv == 0)
	{
		mo_wlg4(MR_TRCV, 0x44440001, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		
		sprintf(cMsg, "%.4s\tmo_tagt\t%08x", MRMSRRC, tcomrcv); /* TBCS0163						*/
		
															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
													
															
		lRet = MRNORMX;
		
		PRINTF("(0) mr_trcv - motagt  = %ld\n", lRet);
		
		goto exit_to_main;
	}

	tsubrcv = tcomrcv->tcomsbps ;							/* サブ共通部サイズ取得				*/ 

	mrtrcv = (TRCV*)((char*)tcomrcv + sizeof(TCOMPAT) + tsubrcv);
		
	PRINTF("(0.0) mr_trcv - tcomrcv  = %08x\n", tcomrcv);
	PRINTF("(0.1) mr_trcv - mrtrcv  = %08x\n", mrtrcv);
	PRINTF("(0.2) mr_trcv - sizeof(TCOMPAT)  = %ld\n", sizeof(TCOMPAT));
	PRINTF("(0.3) mr_trcv - tcomrcv->tcomsbps  = %08x\n", tcomrcv->tcomsbps);
	PRINTF("(0.4) mr_trcv - tcomrcv->tcomsbps  = %.20s\n", tcomrcv->tcomsbps);


    if( ( (mopcbp->mopssstp->tsstprmd[0] & 0x0000000FL) != 0x00000000L) )
    { 	    	            								/* プログラムモードが   			*/
     														/* オンラインモードがない時			*/
    	
    	mrlog[0] = mopcbp->mopssstp->tsstprmd[0];			/* TBCS0119							*/
		
		mo_wlg4(MR_TRCV, WNGPM, mrlog, 4L);		 			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
   	
    	
    	lRet = MRNORMX; 			                  		/* リータンする                     */
    	
    
    	goto exit_to_main;
    } 

	PRINTF("(1) mr_trcv - tcsttrcv = %c\n", mopcbp->mopscstp->tcsttrcv);

    /********************************************************************************************/
    /*  発行条件チェック（リカバリ要/不要チェック）		  					                    */
    /********************************************************************************************/

    if(mopcbp->mopscstp->tcsttrcv != TCSTTRNE)
    {                                    					/* リカバリ要/不要情報が            */
                                     						/* リカバリ不要の時 	            */
        				                					/* リータンする  					*/
       
  		mrlog[0] = (long)mopcbp->mopscstp->tcsttrcv;		/* TBCS0119							*/
 
   		mo_wlg4(MR_TRCV, WNGPM, mrlog, 4L); 	 			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
        
        lRet = MRNORMX;
    
    	goto exit_to_main;
    }                     				

  
    /********************************************************************************************/
    /*  開始区分チェック							  					                        */
    /********************************************************************************************/

	PRINTF("(2) mr_trcv - tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);
	
#ifndef debug_test
	mopcbp->mopssstp->tsststd0 = KAISHIKU;
#endif

    if(mopcbp->mopssstp->tsststd0 == KAISHIKU)				/* 開始区分が'N'の場合			    */
    {
		PRINTF("(3.0) mr_trcv - filename = %.127s\n", mrtrcv->trcvjpnm);
		PRINTF("(3.1) mr_trcv - filename = %s\n", mrtrcv->trcvjpnm);
		PRINTF("(3.2) mr_trcv - filename = %.127s\n", mrtrcv->trcvspnm);
		PRINTF("(3.3) mr_trcv - filename = %s\n", mrtrcv->trcvspnm);
		PRINTF("(3.4) mr_trcv - filename = %c\n", mrtrcv->trcvjfst);
		PRINTF("(3.5) mr_trcv - filename = %c\n", mrtrcv->trcvsfst);
		
		lRet = mr_stpr();									/* 引継ぎ情報ファイル初期化処理		*/
		
		PRINTF("(3) mr_trcv - lRet = %ld\n", lRet);
		
	} 
	else													/* 開始区分が'R'の場合			    */
	{
		lRet = mr_rest();									/* 引継ぎ情報ファイル故障状態		*/
															/* のチェック						*/
		
		PRINTF("(4) mr_trcv - lRet = %ld\n", lRet);
		
		
		if(lRet != MRNORMAL)
		{
			PRINTF("(5) mr_trcv - lRet = %ld\n", lRet);		
			
			mrlog[0] = lRet;								/* TBCS0119							*/
	
			mo_wlg4(MR_TRCV, 0x44440002, mrlog, 4L); 		/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

			if(lRet == MRNORMX)								/* ファイルアクセスエラーの場合		*/
			{
				lRet = mr_stpr();							/* 開始処理							*/
				
				if(lRet == MRNORMAL)						/* TBCS0156							*/
				{											/* 正常終了であっても条件付正常終了	*/
					lRet = MRNORMX;							/* TBCS0156							*/
				}
				PRINTF("(6) mr_trcv - lRet = %ld\n", lRet);		
			}	
					
			goto exit_to_main;								/* 終了処理							*/
		}

		PRINTF("(7) mr_trcv - lRet = %ld\n", lRet);			
		
		lRet = mr_recv();									/* テーブル復元処理					*/

	}	
		
 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/
exit_to_main:

	mrlog[0] = lRet;										/* TBCS0119							*/
	
	
	mo_wlg4(MR_TRCV, WOTSC, mrlog, 4L); 					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	PRINTF("(8) mr_trcv - EXIT lRet = %ld\n", lRet);			
	
	return(lRet);
   
}    	


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long mr_rest()																	*/
/*																								*/
/*	＜機能概要＞ 引継ぎ情報ファイル故障状態のチェック											*/
/*  																							*/
/*	リターン:																					*/
/*		MRFILERR(二重故障)																		*/
/*		MRNORMAL(正常)																			*/
/*		MRNORMX(ファイルアクセスエラー)															*/
/************************************************************************************************/
long mr_rest()
{
	
	int iFd = -1;											/* file descriptor					*/
	
	long lRet = 0;											/* 関数の返却値						*/
	
	char cMsg[MSSGSIZE] = "\0";								/* メッセージ格納体					*/
	
	char cSysCall = '0';									/* システムコールoption				*/
	
	TRCVINFODATA lDayTime;									/* 日付時刻の構造体					*/

	extern  TRCV *mrtrcv;									/* 共通TRCVの領域					*/

	extern MOPSCPCB *mopcbp;								/* MOPSCPCB ボインタ         		*/
	
	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/

	
 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/

	mo_wlg4(MR_REST, WINSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	mrlog[0] = (long)mrtrcv->trcvspnm;						/* TBCS0119							*/
	
	mrlog[1] = O_RDONLY;									/* TBCS0119							*/
	
	mo_wlg4(MR_REST, WBSYS | OSOPEN, mrlog, 8L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
															

	iFd = open(mrtrcv->trcvspnm, O_RDONLY);					/* ファイルをオーブンする       	*/

	mrlog[0] = iFd;											/* TBCS0119							*/
	
	mo_wlg4(MR_REST, WASYS | OSOPEN, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_rest - iFd = %ld\n", iFd);			



	if(iFd < MRNORMAL )										/* ファイルをオープンエラー			*/
	{
		mo_wlg4(MR_REST, WNGSC, 0, 0);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
		cSysCall = OPENOPTI;								/* システムコールoption				*/
		
		goto error_proc;
	}
	
	lRet = mr_read(iFd, (char*)&lDayTime, STTDATSI);		/* ファイルからデータを読み出す		*/
	
	PRINTF("(2) mr_rest - lNowaDay = %lx\n", htonl(lDayTime.lNowaDay));			

	PRINTF("(3) mr_rest - lNowaTime = %lx\n", htonl(lDayTime.lNowaTime));			

	PRINTF("(4) mr_rest - lRet = %ld\n", lRet);			

	

	if(lRet != MRNORMAL)									/* mr_read()でエラーが出た場合		*/
	{
		mo_wlg4(MR_REST, 0x44440001, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		cSysCall = READOPTI;								/* システムコールoption				*/
		
		goto error_proc;									/* エラー処理						*/
	}

	PRINTF("(5) mr_rest - iFd = %ld\n", iFd);			
	
	if(iFd >= MRNORMAL)
	{
		close(iFd);											/* ファイルをクローズする			*/
	}

	sprintf(cMsg, "%.4s\t%c\t%08x\t%06x", 					/* 送信メッセージを編集する			*/
			MRMSRR3, lDayTime.cStatus, htonl(lDayTime.lNowaDay), htonl(lDayTime.lNowaTime));
	
															/* メッセージを送信する				*/
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);


	if(lDayTime.cStatus == TRCVFERR)						/* 故障中の場合						*/
	{
		mr_kaih();											/* テーブルリカバリ回避処理			*/
	
		lRet = 	MRNORMX;
	}
	else
	{
		lRet = MRNORMAL;
	}

	goto exit_from_rest;									/* 終了処理							*/

 	/********************************************************************************************/
    /*  エラー処理																				*/
    /********************************************************************************************/

error_proc:

	lRet = mr_sfer(iFd, cSysCall);							/* 引継ぎ状態ファイルエラー処理		*/
	
	PRINTF("(6) mr_rest - lRet = %ld\n", lRet);			
	

	if(mopcbp->mopscstp->tcst2err != TCST2NDW) 				/* 二重故障の場合					*/
	{	
	
		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
		mo_wlg4(MR_REST, 0x44440002, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
		lRet = MRFILERR;
	}
	else
	{
		mr_kaih();											/* テーブルリカバリ回避処理			*/
	
		lRet = 	MRNORMX;
		
		PRINTF("(7) mr_rest - lRet = %ld\n", lRet);			
	}

 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/
	
exit_from_rest:

	PRINTF("(8) mr_rest - EXIT lRet = %ld\n", lRet);			

	mrlog[0] = lRet;										/* TBCS0119							*/

	mo_wlg4(MR_REST, WOTSC, mrlog, 4L);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	return(lRet);											/* 終了処理							*/
	
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long mr_recv()																	*/
/*																								*/
/*	＜機能概要＞ テーブル復元処理																*/
/*  																							*/
/*	リターン:																					*/
/*		MRFILERR(二重故障)																		*/
/*		MRNORMAL(正常)																			*/
/*		MRNORMX(ファイルアクセスエラー)															*/
/*		MRNOMEM(バッファ確保失敗)						コメント追加 TBCS0156					*/
/*		SYSERROR (FIPファイル不整合エラー)				コメント追加 TBCS0156					*/
/*														コメント追加 TBCS0156	SSLA0036 削除	*/
/*		MRNORRCV(テーブルリカバリ処理実施)				コメント追加 SSLA0038					*/
/************************************************************************************************/
long mr_recv()
{
	
	long lLen = 0;											/* 引継ぎ要テーブルサイズ			*/

	char *pcTrc0a = NULL; 									/* 引継ぎ要テーブル先頭アドレス		*/
	
	char *pcDatabuf = NULL;									/* 引継ぎ要テーブル退避アドレス		*/
	
	char *pcNewData = NULL;									/* 更新データ						*/

	char cSysCall = '0';									/* システムコールoption				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* メッセージ						*/
	
	TRCVINFODATA lDayTime;									/* 引継ぎ情報構造体					*/
	
	int iFd = -1;											/* file descriptor					*/
	
	long lCount = 0;										/* レコード数						*/
	
	TRCVDATA trcvinfo;										/* 引継ぎデータレコード構造体宣言	*/
	
	long lRet = 0;											/* 関数の返却値						*/
	
	long lDataSize = 0;										/* 更新データサイズ（4倍数）		*/

	extern  MOPSCPCB *mopcbp;            					/* MOPSCPCB ボインタ         		*/

	extern  TRCV *mrtrcv;									/* 共通TRCVの領域					*/
	
	extern  PSCPSECT pscparea;        					    /* システム 共通 TSECT 領域         */
	
	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/
	
	long lFntRet = 0;										/* TBCS0163							*/
	
 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/
	mo_wlg4(MR_RECV, WINSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	lLen = mopcbp->mopssstp->tsstrc0l;  					/* 引継ぎ要テーブルサイズを設定		*/

	mrlog[0] = lLen;										/* TBCS0119							*/

	mo_wlg4(MR_RECV, 0x44440001, mrlog, 4L);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_recv - lLen = %ld\n", lLen);			

	sprintf(cMsg, "%.4s", MRMSRR8);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

															/* 引継ぎ要テーブルの先頭オフセット	*/
	pcTrc0a = (char *)pscparea.psccmadt + mopcbp->mopssstp->tsstrc0a;

	mrlog[0] = (long)pcTrc0a;								/* TBCS0119							*/

	mo_wlg4(MR_RECV, 0x44440002, mrlog, 4L);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	PRINTF("(2) mr_recv - pcTrc0a = %lx\n", pcTrc0a);			

	lDayTime.lNowaDay = -1;									/* TBCS0163							*/
	
	lDayTime.lNowaTime = -1;								/* TBCS0163							*/

	pcDatabuf = (char*)malloc(lLen);						/* リカバリ用プールバッファ			*/
															/* を確保する		SSLA0036 修正	*/

	if(pcDatabuf == NULL)									/* 確保が失敗の時	SSLA0036 修正	*/
	{
															/* 					SSLA0036 削除	*/
		
															/* TBCS0119			SSLA0036 削除	*/
		
		mo_wlg4(MR_RECV, 0x44440003, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119			SSLA0036 修正	*/
															
		sprintf(cMsg, "%.4s\tmalloc()\t%08x", MRMSRRC, 0); 	/* TBCS0163			SSLA0036 修正	*/

															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

		lRet = MRNOMEM;

		goto exit_from_recv; 								/* 終了処理							*/
	}
	else
	{
		memset(pcDatabuf, 0x00, lLen); 						/* リカバリ用プールバッファを		*/
	}														/* 初期化する		SSLA0036 追加	*/


	pcNewData = (char*)malloc(lLen);						/*更新データ編集用プールバッファ	*/
															/* を確保する		SSLA0036 修正	*/

															/* 					SSLA0036 削除	*/
	
	if(pcNewData == NULL)									/* 確保が失敗の時	SSLA0036 修正	*/
	{
															/* TBCS0119							*/
		
		mo_wlg4(MR_RECV, 0x44440004, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119			SSLA0036 修正	*/
															
		sprintf(cMsg, "%.4s\tmalloc()\t%08x", MRMSRRC, 0);  /* TBCS0163			SSLA0036 修正	*/
		
															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

		lRet = MRNOMEM;
	
		goto exit_from_recv; 								/* 終了処理							*/
	}

	memcpy(pcDatabuf, pcTrc0a, lLen);						/* 全引継ぎ要テーブルの内容をコピー	*/

	mrlog[0] = (long)mrtrcv->trcvjpnm;						/* TBCS0119							*/
	
	mrlog[1] = O_RDONLY;									/* TBCS0119							*/
	
	mo_wlg4(MR_RECV, WBSYS | OSOPEN, mrlog, 8L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	iFd = open(mrtrcv->trcvjpnm, O_RDONLY);					/* 引継ぎ情報ファイルをオープンする	*/
	
	mrlog[0] = iFd;											/* TBCS0119							*/
		
	mo_wlg4(MR_RECV, WASYS | OSOPEN, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	PRINTF("(5) mr_recv - iFd = %ld\n", iFd);					

	if(iFd < MRNORMAL )
	{
		mo_wlg4(MR_RECV, WNGSC, 0, 0);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		
		cSysCall = OPENOPTI;								/* システムコールoption				*/

		goto error_proc;
	}

	lRet = mr_read(iFd, (char*)&lDayTime, DATETIME);		/* 現在の日付と時刻を読み出す		*/

	PRINTF("(6) mr_recv - lRet = %ld\n", lRet);					

	
	if(lRet < MRNORMAL)
	{
		mrlog[0] = lRet;									/* TBCS0119							*/

		mo_wlg4(MR_RECV, 0x44440005, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		cSysCall = READOPTI;								/* システムコールoption				*/

		goto error_proc;									/* エラー理							*/
	}

	do 
	{
		memset(pcNewData, 0x00, lLen); 						/* 更新データ編集用メモリを初期化する*/
															/*					SSLA0036 追加	*/
		
		memset(&trcvinfo, 0x00, BUDASIZE);					/* 引継ぎデータレコード構造体初期化	*/

		lRet = mr_read(iFd, (char*)&trcvinfo, BUDASIZE);	/* 引継ぎデータを読込み				*/
		
		PRINTF("(7) mr_recv - lRet = %ld\n", lRet);					

		if(lRet == SYSERROR)								/* 引継ぎ情報ファイルがエラー時		*/
		{
			
			mo_wlg4(MR_RECV, 0x44440006, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
			
			memcpy(pcTrc0a, pcDatabuf, lLen);				/* テーブルの復元処理				*/
			
			cSysCall = READOPTI;							/* システムコールoption				*/
		
			PRINTF("(8) mr_recv - pcTrc0a = %lx\n", pcTrc0a);					
			
			lCount = 0;										/* レコード数を初期化する			*/ 
			
			goto error_proc;								/* エラー処理						*/

		}
		else if(lRet == MRNORMX)	 						/* 引継ぎ情報ファイルがEOF			*/
		{

			mo_wlg4(MR_RECV, 0x44440007, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

			PRINTF("(9) mr_recv - lRet = %ld\n", lRet);			
			
			lRet = MRNORMAL;
	
			goto exit_from_recv;							/* 終了処理							*/
		}			
		
		lRet = memcmp(&trcvinfo.msg1, STRTPATN, PATNSIZE);	/* 先頭パターンをチェック			*/
		
		PRINTF("(10) mr_recv - lRet = %ld\n", lRet);

		 
		if(lRet != MRNORMAL)								/* 先頭パターンが出ない場合			*/
		{
			mo_wlg4(MR_RECV, 0x44440008, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
															
			lRet = MRNORMAL;								/* SSLA0038	追加					*/
			
			goto exit_from_recv;							/* 終了処理							*/
		}

		trcvinfo.size = htonl(trcvinfo.size);
		
		trcvinfo.offset = htonl(trcvinfo.offset);
		
		trcvinfo.num = htonl(trcvinfo.num);
		
		mrlog[0] = trcvinfo.size;							/* TBCS0119							*/
		
		mrlog[1] = trcvinfo.offset;							/* TBCS0119							*/
		
		mrlog[2] = trcvinfo.num;							/* TBCS0119							*/
		
		mo_wlg4(MR_RECV, 0x44440009, mrlog, 12L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		
		PRINTF("(10.1) mr_recv - trcvinfo.size = %lx\n", trcvinfo.size);	
		

		lDataSize = mr_intg(trcvinfo.size);					/* 4倍数の調整						*/
		
		PRINTF("(11) mr_recv - lDataSize = %lx\n", lDataSize);					

															/* 更新データを読込み				*/
		lRet = mr_read(iFd, pcNewData, (lDataSize + PATNSIZE));

		PRINTF("(12) mr_recv - lRet = %ld\n", lRet);					


		if(lRet == SYSERROR)								/* 引継ぎ情報ファイルがエラー時		*/
		{
			mo_wlg4(MR_RECV, 0x4444000a, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
			
			memcpy(pcTrc0a, pcDatabuf, lLen);
			
			cSysCall = READOPTI;							/* システムコールoption				*/
	
			PRINTF("(13) mr_recv - lRet = %ld\n", lRet);

			lCount = 0;										/* レコード数を初期化する			*/ 
			
			goto error_proc;								/* エラー処理						*/
			
		}
		else if(lRet == MRNORMX)							/* 引継ぎ情報ファイルがEOF			*/
		{
			mo_wlg4(MR_RECV, 0x4444000b, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

			PRINTF("(14) mr_recv - lRet = %ld\n", lRet);
			
			lRet = MRNORMAL;

			goto exit_from_recv;							/* 終了処理							*/
		}			

															/* 終端パターンのチェック			*/
		lRet = memcmp((pcNewData + lDataSize), ENDDPATN, PATNSIZE);

		PRINTF("(15) mr_recv - lRet = %ld\n", lRet);


		if(lRet != MRNORMAL)								/* 終端パターンがでない場合			*/
		{
			mo_wlg4(MR_RECV, 0x4444000c, 0, 0);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
			
			lRet = MRNORMAL;
			
			goto exit_from_recv;							/* 終了処理							*/

		}
															/* リカバリする						*/ 
		memcpy( ( (char *)pscparea.psccmadt + trcvinfo.offset ), pcNewData, trcvinfo.size);

		lCount += 1;										/* レコード数をカウンタアップ		*/
		
		PRINTF("(16) mr_recv - lCount = %ld\n", lCount);
		 
#ifdef debug_test
		PRINTF("(16.1)******recvy trcvinfo.offset = %08x\n", trcvinfo.offset);
		PRINTF("(16.2)******recvy trcvinfo.size = %ld\n", trcvinfo.size);
		PRINTF("(16.3)******recvy lLen = %ld\n", lLen);
		PRINTF("(16.4) mr_recv - pcTrc0a = %08x\n", pcTrc0a);	
		PRINTF("(16.5) mr_recv - pscparea.psccmadt = %08x\n", pscparea.psccmadt);
				
#endif			 
		 
	}while( (long)( (char *)pscparea.psccmadt + trcvinfo.offset ) < (long) (lLen + pcTrc0a) );

	lRet = MRNORMAL;

	mo_wlg4(MR_RECV, 0x4444000d, 0, 0);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	goto exit_from_recv;									/* 終了処理							*/

 	/********************************************************************************************/
    /*  エラー処理																				*/
    /********************************************************************************************/

error_proc:

	mr_ferr(iFd, cSysCall);									/* 引継ぎ情報ファイルエラー処理		*/
	
															/* 二重故障のチェック				*/
//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMX;
	
	PRINTF("(17) mr_recv - mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);



	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* 二重故障のチェック				*/
	{

		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/

		mo_wlg4(MR_RECV, 0x4444000e, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		lRet = MRFILERR;
		
		PRINTF("(17.1) mr_recv  - lRet = %ld\n", lRet);

	}
	else
	{
		lRet = MRNORMX;
		
		PRINTF("(17.2) mr_recv - lRet = %ld\n", lRet);
	}


	PRINTF("(17.3) mr_recv - lRet = %ld\n", lRet);

 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

exit_from_recv:

	if(iFd >= MRNORMAL)										/* ファイルをクローズ				*/
	{	
		close(iFd);									
	}

	PRINTF("(17.4) mr_recv - lRet = %ld\n", lRet);	


	if( (lRet != MRFILERR) && (lRet != MRNOMEM) )			/* 二重故障以外の場合は	 TBCS0163	*/
	{
		PRINTF("(18) mr_recv - lRet = %ld\n", lRet);

		lFntRet = mf_srcv(); 								/* TBCS0188							*/

		if(lFntRet == MFERROR)	 							/* FIPファイル不整合復旧処理 		*/
		{													/* TBCS0156, TBCS0188				*/
		 	
		//	if(lFntRet != MFNORMX))							/* TBCS0188							*/
		//	{	
				mo_wlg4(MR_RECV, 0x4444000f, 0, 0);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
			
															/* TBCS0156							*/
				PRINTF("(18.1) mr_recv - mf_srcv = %ld\n", lRet);
				
															/* TBCS0163, TBCS0187				*/
				sprintf(cMsg, "%.4s\tmf_srcv\t%08x", MRMSRRC, lFntRet); 

															/* TBCS0163							*/
				ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
				
				lRet = SYSERROR;
		//  }												/* TBCS0188							*/
		
		}
		else if(lFntRet == MFNORMX)							/* TBCS0188							*/
		{
			lRet = MRNORMX;									/* TBCS0188							*/
		}

		/****************************************************************************************/
		/*               SSLA0036 修正 START	2003/07/03                                      */
		/****************************************************************************************/

		if(pcDatabuf != NULL)								/*                      TBCS0156    */
		{
			//lRet = mo_frbf((long*)pcDatabuf);				/* プールバッファの解放	TBCS0156	*/
			
			free(pcDatabuf);								/* 					SSLA0036 追加	*/

															/* プールバッファの解放	TBCS0156	*/
															/* 					SSLA0036 削除	*/
															/* TBCS0163			SSLA0036 削除	*/

															/* TBCS0163			SSLA0036 削除	*/

															/* 解放失敗時はエラー   TBCS0156	*/
															/* 					SSLA0036 削除	*/
		}
		
		if(pcNewData != NULL)								/*                      TBCS0156    */
		{
			//lRet = mo_frbf((long*)pcNewData);				/* プールバッファの解放 TBCS0156    */
						
			free(pcNewData);								/* 					SSLA0036 追加	*/
			
															/* プールバッファの解放 TBCS0156    */
										 					/*					SSLA0036 削除	*/

															/* TBCS0163			SSLA0036 削除	*/

															/* TBCS0163			SSLA0036 削除	*/

															/* 解放失敗時はエラー   TBCS0156	*/
															/* 					SSLA0036 削除	*/
		
		}
	
	}														/*                      TBCS0156    */
		/****************************************************************************************/
		/*               SSLA0036 修正 END	2003/07/03 		                                    */
		/****************************************************************************************/
		
	
	sprintf(cMsg, "%.4s\t%08x\t%06x\t%ld", 
			MRMSRR9, htonl(lDayTime.lNowaDay), htonl(lDayTime.lNowaTime), lCount);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if( (lRet == MRNORMAL) && (lCount > 0) )				/* SSLA0038	追加					*/
	{
		lRet = MRNORRCV;									/* SSLA0038	追加					*/
	}

	PRINTF("(19) mr_recv - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_RECV, WOTSC, mrlog, 4L);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	return(lRet);
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void mr_kaih()																	*/
/*																								*/
/*	＜機能概要＞ テーブルリカバリ回避処理														*/
/*  																							*/
/*	リターン:																					*/
/*		なし																					*/
/************************************************************************************************/
void mr_kaih()
{
	char cMsg[MSSGSIZE] = "\0";								/* メッセージ格納体					*/

	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB ボインタ         		*/

 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/
    
    
   	mo_wlg4(MR_KAIH, WINSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	sprintf(cMsg, "%.4s", MRMSRRA);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	mopcbp->mopssstp->tsststd0 = KAISHIKU;					/* 初期立ち上げ						*/
	
	PRINTF("(1) mr_kaih - EXIT tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);

 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

	mo_wlg4(MR_KAIH, WOTSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	return;
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	void mr_frce()																	*/
/*																								*/
/*	＜機能概要＞ SMP強制終了処理																*/
/*  																							*/
/*	リターン:																					*/
/*		なし																					*/
/************************************************************************************************/
void mr_frce()
{
	
	char lRet = '0';										/* syscom_get_bootmode()の返却値	*/

	char cMsg[MSSGSIZE] = "\0";								/* メッセージ格納体					*/
	
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB ボインタ         		*/

	long mrlog[2];											/* ログ情報編集領域 TBCS0119		*/

 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/
   	mo_wlg4(MR_FRCE, WINSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/


	lRet = syscom_get_bootmode();							/* 利用者モード判定					*/
	
	PRINTF("(1) mr_frce - lRet = %c\n", lRet);
	

	if(lRet == ENDONWAY)
	{
		
		mrlog[0] = lRet;									/* TBCS0119							*/

	   	mo_wlg4(MR_FRCE, 0x44440001, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		
		sprintf(cMsg, "%.4s", MRMSRRB);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
		
		mopcbp->mopssrtp->tsrtdvst = TSRTEND;				/* 電源断を設定する					*/
		
		PRINTF("(2) mr_frce - tsrtdvst = %c\n", mopcbp->mopssrtp->tsrtdvst);
	}

	PRINTF("(3) mr_frce - EXIT lRet = %c\n", lRet);
	
	mo_wlg4(MR_FRCE, WOTSC, 0, 0);							/* TBCS0119							*/

	return;
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long	 mr_inff()																*/
/*																								*/
/*	＜機能概要＞ 引継ぎ情報ファイルの開始処理													*/
/*  																							*/
/*	リターン:																					*/
/*		MRNORMAL																				*/
/*		MRFILERR																				*/
/*		MRNORMX		条件付正常終了									コメント追加 TBCS0156		*/
/************************************************************************************************/
long mr_inff()
{

	char cSysCall = '0';									/* システムコールoption				*/

	int iFd = -1;											/* file descriptor					*/
	
	long lDay = 0;											/* 日付の変数						*/
	
	long lTime = 0;											/* 時間の変数						*/
	
	long lRet = 0;											/* 関数の返却値						*/
	
	TRCVINFODATA lDayTime;									/* 日付時刻構造体の宣言				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* メッセージ格納体					*/

	extern TRCV *mrtrcv;									/* 共通TRCVの領域					*/
	
	extern MOPSCPCB *mopcbp; 								/* MOPSCPCB ボインタ         		*/

	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/

 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/

    
   	mo_wlg4(MR_INFF, WINSC, 0, 0);							/* TBCS0119							*/
    
    														/*	TBCS0119						*/
   // iFd = open(mrtrcv->trcvjpnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);
   
    mrlog[0] = (long)mrtrcv->trcvjpnm;						/* TBCS0119							*/
   	
    mrlog[1] = (O_WRONLY | O_TRUNC | O_CREAT | O_SYNC); 	/* TBCS0119						*/
	
	mrlog[2] = (S_IRWXU | S_IROTH | S_IRGRP);				/* TBCS0119							*/
	
	mo_wlg4(MR_INFF, WBSYS | OSOPEN, mrlog, 12L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

    sprintf(cMsg, "%.4s\t%s", MRMSRR4, mrtrcv->trcvjpnm);	/* TBCS0200 						*/

															/* TBCS0200 						*/
    ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN); 

    
    														/* TBCS0119							*/
    iFd = open(mrtrcv->trcvjpnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC, S_IRWXU | S_IROTH | S_IRGRP);
    
    mrlog[0] = iFd;											/*	TBCS0119						*/
    
  	mo_wlg4(MR_INFF, WASYS | OSOPEN, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_inff - iFd = %ld\n", iFd);

	PRINTF("(1.2) mr_inff - mrtrcv = %08x\n", mrtrcv);

															/* TBCS0200 削除					*/
	
															/* TBCS0200 削除					*/

	if(iFd < MRNORMAL )										/* ファイルがエラーの場合			*/
	{

	  	mo_wlg4(MR_INFF, WNGSC, 0, 0);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		PRINTF("(2) mr_inff - iFd = %ld\n", iFd);

		cSysCall = OPENOPTI;								/* システムコールoption				*/

		goto error_proc;									/* エラー処理						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* 現在日付時刻を取得				*/
	
	mrlog[0] = lRet;										/* TBCS0119							*/

   	mo_wlg4(MR_INFF, 0x44440001, mrlog, 4L);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	lTime &= 0x00FFFFFF; 									/* hhmmss形式を変更する				*/
	
	PRINTF("(3) mr_inff - lDay = %.8x\n", htonl(lDay));

	PRINTF("(4) mr_inff - lTime = %.6x\n", htonl(lTime));

	lDayTime.lNowaDay = htonl(lDay);						/* 日付を設定する					*/
	
	lDayTime.lNowaTime = htonl(lTime);						/* 時刻を設定する					*/

	lRet = mr_writ(iFd, (char*)&lDayTime, DATETIME);		/* 現在日付時刻をファイルに書き込み */
	 
	PRINTF("(5) mr_inff - lRet = %ld\n", lRet);
	

 	if(lRet  != MRNORMAL)									/* ファイルがエラーの場合			*/
 	{
	  	mo_wlg4(MR_INFF, 0x44440002, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		cSysCall = WRITOPTI;								/* システムコールoption				*/

		goto error_proc;									/* エラー処理						*/
	 
 	}
 	else
 	{
		if (iFd >= MRNORMAL)								
		{	
			close(iFd);										/* ファイルクローズ					*/	
		}

		mrtrcv->trcvjfst = TRCVFNML;						/* 正常を更新する					*/

		PRINTF("(6) mr_inff - trcvjfst = %c\n", mrtrcv->trcvjfst);

		sprintf(cMsg, "%.4s\t%08x\t%06x", MRMSRR5, lDay, lTime);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
        
		lRet = MRNORMAL;
	
        goto exit_from_inff;								/* 終了処理							*/
	 }

 	/********************************************************************************************/
    /*  エラー処理																				*/
    /********************************************************************************************/

error_proc:

	mr_ferr(iFd, cSysCall);									/* 引継ぎ情報ファイルエラー処理		*/

	PRINTF("(%ld) mr_inff - lRet = %ld\n", 7);
	
	PRINTF("(7.1) mr_inff - mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);


	if(mopcbp->mopscstp->tcst2err != TCST2NDW)
	{

		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
	  	mo_wlg4(MR_INFF, 0x44440003, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		lRet = MRFILERR;
		
		PRINTF("(7.2) mr_inff - lRet = %ld\n", lRet);

	}
	else
	{
		
		//lRet = MRNORMAL;
		lRet = MRNORMX;										/* TBCS0156							*/
		
		PRINTF("(7.3) mr_inff - lRet = %ld\n", lRet);
	}

//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMAL;
	
	PRINTF("(7.4) mr_inff - lRet = %ld\n", lRet);

 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

exit_from_inff:

	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_INFF, WOTSC, mrlog, 4L);						/* TBCS0119							*/

	PRINTF("(8) mr_inff - lRet = %ld\n", lRet);

	return(lRet);											/* リータンする  					*/ 

}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long mr_sttf()																	*/
/*																								*/
/*	＜機能概要＞ 引継ぎ状態ファイルの開始処理													*/
/*  																							*/
/*	リターン:																					*/
/*		MRNORMAL																				*/
/*		MRFILERR																				*/
/*		MRNORMX		条件付正常終了									コメント追加 TBCS0156		*/
/************************************************************************************************/
long mr_sttf()
{
	int iFd = -1;											/* file descriptor					*/ 	

	char cSysCall = '0';									/* システムコールoption				*/
	
	long lDay = 0;											/* 日付変数							*/
	
	long lTime = 0;											/* 時刻変数							*/
	
	long lRet = 0;											/* 関数の返却値						*/

	char cMsg[MSSGSIZE] = "\0";								/* メッセージ格納体					*/

	TRCVINFODATA InputData;									/* 引継ぎ状態構造体を宣言			*/
	
	extern  TRCV *mrtrcv;									/* 共通TRCVの領域					*/
	
	extern MOPSCPCB *mopcbp; 								/* MOPSCPCB ボインタ         		*/
	
	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/


 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/
    
   	mo_wlg4(MR_STTF, WINSC, 0, 0);							/* TBCS0119							*/

															
  	// iFd = open(mrtrcv->trcvspnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);
  	
  		
    mrlog[0] = (long)mrtrcv->trcvspnm;						/* TBCS0119							*/
   	
    mrlog[1] = (O_WRONLY | O_TRUNC | O_CREAT | O_SYNC); 	/* TBCS0119						*/
	
	mrlog[2] = (S_IRWXU | S_IRWXG | S_IRWXO);				/* TBCS0119							*/
	
	mo_wlg4(MR_STTF, WBSYS | OSOPEN, mrlog, 12L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

    sprintf(cMsg, "%.4s\t%s", MRMSRR6, mrtrcv->trcvspnm);	/* TBCS0200        					*/

															/* TBCS0200 						*/
    ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN); 


															/* TBCS0119							*/
    iFd = open(mrtrcv->trcvspnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC, S_IRWXU | S_IROTH | S_IRGRP);
    
    mrlog[0] = iFd;
    
  	mo_wlg4(MR_STTF, WASYS | OSOPEN, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
  
  	PRINTF("(1) mr_sttf - iFd = %ld\n", iFd);
  	
	PRINTF("(1.1) mr_stff - filename = %s\n", mrtrcv->trcvspnm);
	
	PRINTF("(1.3) mr_stff - mrtrcv = %08x\n", mrtrcv);

															/*TBCS0200	削除					*/
	
															/*TBCS0200	削除					*/


	if(iFd < MRNORMAL )										/* ファイルがエラーの場合			*/
	{

	  	mo_wlg4(MR_STTF, WNGSC, 0, 0);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		cSysCall = OPENOPTI;								/* システムコールoption				*/

		goto error_proc;									/* エラー処理						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* 日付時刻を求め					*/
	
	mrlog[0] = lRet;										/* TBCS0119							*/

   	mo_wlg4(MR_STTF, 0x44440001, mrlog, 4L);				/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	lTime &= 0x00FFFFFF; 									/* hhmmss形式を変更する				*/

	PRINTF("(3) mr_sttf - lDay = %08x\n", htonl(lDay));

	PRINTF("(4) mr_sttf - lTime = %06x\n", htonl(lTime));

	InputData.lNowaDay = htonl(lDay);						/* 日付を設定する					*/

	InputData.lNowaTime = htonl(lTime);						/* 時刻を設定する					*/
	 
	InputData.cStatus = mrtrcv->trcvjfst;					/* 故障中を更新する					*/
	
	memset(InputData.pcYobi, 0x00, 3);						/* 0x00を予備に設定する				*/

	PRINTF("(5) mr_sttf - InputData.cStatus = %c\n", InputData.cStatus);


	lRet = mr_writ(iFd, (char*) &InputData, STTDATSI);		/* 日付時刻と故障状態を書く込み		*/

	PRINTF("(6) mr_sttf - lRet = %ld\n", lRet);

	 
 	if(lRet != MRNORMAL)									/* ファイルがエラーの場合			*/
 	{
	  	mo_wlg4(MR_STTF, 0x44440002, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		
		PRINTF("(7) mr_sttf - lRet = %ld\n", lRet);

		cSysCall = WRITOPTI;								/* システムコールoption				*/
	
		goto error_proc;									/* エラー処理						*/
	}
 	else
 	{
		if (iFd >= MRNORMAL)
		{	
			close(iFd);
		}

		mrtrcv->trcvsfst = TRCVFNML;						/* 引継ぎ状態に正常を更新する		*/
		
		sprintf(cMsg, "%.4s\t%08x\t%06x\t%c", MRMSRR7, lDay, lTime, InputData.cStatus);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

        lRet = MRNORMAL;
        
  		PRINTF("(8) mr_sttf - lRet = %ld\n", lRet);			
  
        goto exit_from_sttf;								/* 終了処理							*/
	
	}

 	/********************************************************************************************/
    /*  エラー処理																				*/
    /********************************************************************************************/

error_proc:

	lRet = mr_sfer(iFd, cSysCall);							/* 引継ぎ状態ファイルのエラー処理	*/
	
	mrtrcv->trcvsfst =  TRCVFERR;		   					/* 故障中を更新する					*/

															/* 二重故障のチェック				*/
//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMAL;


	PRINTF("(9) mr_sttf - lRet = %ld\n", lRet);

	PRINTF("(9.1) mr_sttf - mopcbp->mopscstp->tcsttrcv = %c\n", mopcbp->mopscstp->tcst2err);


	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* 二重故障のチェック				*/
	{
		
		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
	  	mo_wlg4(MR_INFF, 0x44440003, mrlog, 4L);			/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
		lRet = MRFILERR;
		
		PRINTF("(9.2) mr_sttf - lRet = %ld\n", lRet);

	}
	else
	{
		//lRet = MRNORMAL;
		lRet = MRNORMX;										/* TBCS0156							*/
		PRINTF("(9.3) mr_sttf - lRet = %ld\n", lRet);
	}

															
	PRINTF("(9.4) mr_sttf - lRet = %ld\n", lRet);
														
 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

exit_from_sttf:

	PRINTF("(10) mr_sttf - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_STTF, WOTSC, mrlog, 4L);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	return(lRet);											/* リータンする  					*/ 
}


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long mr_stpr()																	*/
/*																								*/
/*	＜機能概要＞  開始処理																		*/
/*  																							*/
/*	リターン:																					*/
/*			MRNORMAL																			*/
/*			MRFILERR	ファイルアクセスエラー							コメント追加 TBCS0156	*/
/*			MRNORMX		条件付正常終了									コメント追加 TBCS0156	*/
/************************************************************************************************/
long mr_stpr()
{

	long lRet = MRNORMAL;									/* 返却値							*/

	long lRet1 = MRNORMAL;									/* 状態ファイルの返却値 TBCS156		*/
	
	long mrlog[5];											/* ログ情報編集領域	TBCS0119		*/

 	/********************************************************************************************/
    /*  本処理																					*/
    /********************************************************************************************/
    
   	mo_wlg4(MR_STPR, WINSC, 0, 0);							/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/
	
	lRet = mr_inff();										/* 引継ぎ情報ファイルの初期化処理	*/
	
	PRINTF("(1) mr_stpr - lRet = %ld\n", lRet);



	//if(lRet != MRNORMAL)
	if(lRet == MRFILERR)									/* TBCS0156							*/
	{
  	 	mo_wlg4(MR_STPR, 0x44440001, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		goto exit_to_main;									/* 終了処理							*/
	}

	lRet1 = mr_sttf();										/* 引継ぎ状態ファイルの初期化処理	*/
	
	PRINTF("(2) mr_stpr - lRet = %ld\n", lRet);
	

	//f(lRet != MRNORMAL)									
	if(lRet1 == MRFILERR)									/* TBCS0156							*/
	{
 	 	mo_wlg4(MR_STPR, 0x44440002, 0, 0);					/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

		goto exit_to_main;									/* 終了処理							*/
	}

	mr_frce();												/* SMP 強制終了処理					*/

 	/********************************************************************************************/
    /*  終了処理																				*/
    /********************************************************************************************/

exit_to_main:

	
	lRet |= lRet1; 											/* TBCS0156							*/
	
	if(lRet > MRNORMX)										/* TBCS0156							*/
	{
		lRet = MRNORMX;										/* TBCS0156							*/
	}

	PRINTF("(2) mr_stpr - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;

	mo_wlg4(MR_STPR, WOTSC, mrlog, 4L);						/* 関数名、情報識別子、				*/
															/* 取得情報先頭アドレス、取得情報長	*/
															/* TBCS0119							*/

	//return(MRNORMAL); 
	return( lRet );											/* TBCS0156							*/
	
}

