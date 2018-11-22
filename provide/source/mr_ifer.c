/*----------------------------------------------------------------------------------------------*/
/* ＜対象業務名＞                    故障管理業務      　　         							*/
/* ＜対象業務ＩＤ＞                  ＲＣＶ                         							*/
/* ＜サービス項目名＞                テーブルリカバリ          　   							*/
/* ＜サービス項目ＩＤ＞              trcv	                   									*/
/* ＜モジュール名＞                  ｍｒ＿ifer													*/
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
/* ＜ソース作成年月日＞              ２００３年０４月１０日	         							*/
/* ＜ソース修正者名＞                                               							*/
/* ＜ソース修正年月日及び修正ＩＤ＞                                 							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞                ステップ                       							*/
/*---------------------------------------------------------------------------------------------	*/
/* ＜機能概要＞                                                     							*/
/*                                                                  							*/
/*      引継ぎ情報ファイルのアクセスエラー処理													*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                     							*/
/*		long 	long mr_ifer(int, char)															*/
/*                                                                  							*/
/* ＜仮引数＞                                                       							*/
/*		int	 	iFd;			ファイル ディスクリプタ  										*/
/*		char  	cSysCall;		システムコール名のスイッチ;										*/
/*		  																						*/
/*              	                                                							*/
/* ＜返却値＞                                                       							*/
/*         0 :                  	                                							*/
/*		SYSERROR(-1)	異常																	*/
/*		MRNORMAL(0)		正常																	*/
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
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h> 


/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include    "mr.h"
#include 	"trcv.h"
#include	"mrmsg.h"
#include	"mcdebug.h"


/************************************************************************************************/
/*	内部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
/* file utility */
long mr_intg(long);
long mr_writ(int, char*, long);
long mr_read(int, char*, long);
void mr_clop(char*, char);


/* 引継ぎ状態ファイルエラー処理 */
long mr_sfer(int, char);


/************************************************************************************************/
/*	外部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
long mo_date(long*, long*);
long ms_wtop(long, short, char, char, long, long);     


/************************************************************************************************/
/*																								*/
/*	＜関数名＞	long mr_ifer(int, char cSysCall)												*/
/*																								*/
/*	＜機能概要＞  引継ぎ情報ファイルのアクセスエラー											*/
/*  																							*/
/*	リターン:																					*/
/*			失敗(SYSERROR)																		*/
/*			成功(MRNORMAL)																		*/
/************************************************************************************************/
long mr_ifer(int iFd, char cSysCall)
{

	int iFp = -1;													/* file descriptor			*/
	
	long lDate = 0;													/* 日付の変数				*/ 
	
	long lTime = 0;													/* 時刻の変数				*/
	
	long lRet = 0;													/* 返却値					*/
	
	char cMsg[MSSGSIZE] = "\0";										/* メッセージ格納体			*/

	char cErrStatus = TRCVFERR;										/* ファイル故障中			*/
	
	char cSysName[SCALLSIZ];										/* システムコール名格納体	*/
	
	char newname[TRCVFIZI + 16];									/* 新しいファイル名			*/
	
	extern  TRCV *mrtrcv;										    /* 共通TRCVの領域			*/
	

	PRINTF("(0) mr_ifer - errno = %ld\n", errno);						

	PRINTF("(0.1) mr_ifer - errno name = %s\n", strerror(errno));						

	mr_clop(cSysName , cSysCall);
	
	sprintf(cMsg, "%.4s\t%s\t%d", MRMSRR1, cSysName, errno);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if(iFd >= 0)
	{
		close(iFd);
	}

	PRINTF("(1) mr_ifer - iFd = %ld\n", iFd);						
	
	lRet = mo_date(&lDate, &lTime);									/* 現在の日付時刻を取得		*/
	
	lTime &= 0x00FFFFFF; 									        /* hhmmss形式を変更する		*/
	
	sprintf(newname, "%s_%8x%6x", mrtrcv->trcvjpnm, lDate, lTime);	/* 現在の日付時刻を編集する	*/
	
	PRINTF("(2) mr_ifer - newname = %s\n", newname);						
	
	rename(mrtrcv->trcvjpnm, newname);								/* ファイルをリネームする	*/

	iFp = open(mrtrcv->trcvspnm, O_SYNC | O_WRONLY);				/* ファイルをオープンする	*/

	PRINTF("(3) mr_ifer - iFd = %ld\n", iFd);						

	if(iFp >= 0)
	{
		lRet = lseek(iFp, 8, SEEK_SET);								/* 故障状態の位置に移る		*/
		
		PRINTF("(4) mr_ifer - lRet = %ld\n", lRet);						
		
		cErrStatus = TRCVFERR;
		
		PRINTF("(4.1) mr_ifer - cErrStatus = %c\n", cErrStatus);						
		
		lRet = mr_writ(iFp, &cErrStatus, STATSIZE);					/* 故障状態を更新する		*/

		PRINTF("(5) mr_ifer - lRet = %ld\n", lRet);						
		
		if(iFp >= 0)
		{
			close(iFp);												/* ファイルをクローズ		*/
		}
	}
	else
	{
		lRet = SYSERROR;
	}	

	PRINTF("(6) mr_ifer - lRet = %ld\n", lRet);						
	
	return(lRet);													/* 終了処理					*/
		
}


