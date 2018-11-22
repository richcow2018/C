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
/* ＜サービス項目名＞				 運用管理													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 プログラムモード設定／取得									*/
/* ＜モジュールＩＤ＞				 osprgmd													*/
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
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月１１日     故障管理番号（ＴＢＣＳ０２７２）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 パネルに対してプログラムモードの設定/読取を行う。											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osprgmd.h>																	*/
/*																								*/
/*	   	long	osprgmd(long lMode, long *plInf)												*/
/*																								*/
/* ＜仮引数＞																					*/
/*		clong	lMode;		設定／読取の識別													*/
/*		long	*plInf;		プログラムモード格納エリア											*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常戻り値																				*/
/*			NORMAL		正常に設定読取を行った													*/
/*																								*/
/*		異常戻り値																				*/
/*			OSSIVMD		MODEの誤り。(設定／読取は行われない)									*/
/*			OSSERR		設定の異常終了。(設定は行われない)										*/
/*			OSSNOACC	指定された格納領域がサイズ不足か、もしくはアクセスできない				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*		モード指定の引数が「プログラムモードの設定(OSSPUTPG)」の場合、何も処理をしない			*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "osprgmd.h"
#include "osprgmd_ins.h"

long osprgmd(long lMode, long *plInf)
{
/****************************************/
/*	変数定義							*/
/****************************************/
	long lRes = 0;								/*	返却値用				*/
	long lModeNum = 0;							/*	モード変換後格納用		*/
	long lCnt = 0;								/*	カウンタ				*/
	char acPass[128];							/*	プログラムモードファイルのパス	*/
	char acModeDat[16];							/*	プログラムモード数値読込先		*/
	char acTemp[16];							/*	一次読み込み用			*/
	FILE *pfPassAdr = NULL;
	
	
	os_trcget2( D_MD_OSPRGMD, D_T_TRA_IN, 2, lMode, plInf );

	
//	DbgMsg01( DLv01, ( OutPut, "***** Start osprgmd *****\n" ) );
//	DbgMsg01( DLv02, ( OutPut, "***** lMode:%lx\n", lMode) );
//	DbgMsg01( DLv02, ( OutPut, "***** plInf:%08lx\n", plInf) );
	
/****************************************/
/*	初期処理							*/
/****************************************/
	
	memset( (void *)acPass,0,128);				/* 文字配列の初期化	*/
	
	memset( (void *)acModeDat,0,16);
	
	memset( (void *)acTemp,0,16);

	/*	引数チェック	*/
	if(OSSPUTPG == lMode)						/*	OSSPUTPG の時は何もせず正常終了する	*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, NORMAL );
		
		DbgMsg01( DLv05, ( OutPut, "***** 01:Parameter OSSPUTPG return NORMAL\n") );
		return(NORMAL);
	}
	else if(OSSGETPG != lMode)					/*	OSSGETPG 以外は異常終了		*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, OSSIVMD );
		
		DbgMsg01( DLv05, ( OutPut, "***** 02:パラメタ Err return OSSIVMD\n") );
		
		return(OSSIVMD);
	}
	
	if(NULL == plInf)							/*	plInf NULLなら異常終了		*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, OSSNOACC );
		
		DbgMsg01( DLv05, ( OutPut, "***** 03:Parameter Err return OSSNOACC\n") );
		
		return(OSSNOACC);
	}
	
	DbgMsg01( DLv04, ( OutPut, "***** SG 読み込み\n"));
	lRes = os_getSG(D_SG_PRGMD_PASS,acPass);	/*	SGからパスを読み込む		*/
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04:SG Read Err \n") );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSNOACC );
		
		return(OSSNOACC);
	}
	DbgMsg01( DLv04, ( OutPut, "***** 読込先パス : %s\n", acPass) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FOPEN, 2, acPass, "r" );
	
	pfPassAdr = fopen(acPass, "r");
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 1, pfPassAdr );
	
	if(NULL == pfPassAdr)
	{											/*	ファイルオープン失敗		*/
		DbgMsg01( DLv05, ( OutPut, "***** ファイルオープン失敗\n") );
		DbgMsg01( DLv05, ( OutPut, "***** 05:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSNOACC );
		
		return(OSSNOACC);
	}
	DbgMsg01( DLv04, ( OutPut, "***** pfPassAdr : %lx\n", pfPassAdr) );
	
/****************************************/
/*	本処理								*/
/****************************************/
/*****  障害対応（TBCS0272）    Start                                   修正日：2003.08.11  *****/
/************************************************************************************************/
/*  fgets()からfread()に修正                                                                    */
/************************************************************************************************/
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FREAD, 4, acTemp, D_READ_BYTE, 16, pfPassAdr );
	lRes = fread(acTemp, D_READ_BYTE, 16, pfPassAdr);
/*****  障害対応（TBCS0272）    End                                     修正日：2003.08.11  *****/
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 1, acTemp );
		
	if(NULL == acTemp)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 読み込み失敗\n") );
		DbgMsg01( DLv05, ( OutPut, "***** 06:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_SYS_FCLOSE, 1, pfPassAdr );	
		
		fclose(pfPassAdr);
		
		os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 0 );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
		
		return(OSSERR);
	}
	DbgMsg01( DLv04, ( OutPut, "***** 読み込んだ文字列 :%s\n", acTemp) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FCLOSE, 1, pfPassAdr );	
	
	fclose(pfPassAdr);
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 0 );
	
	for(lCnt = 0;lCnt < 6;lCnt++)				/*	先頭から6文字目迄順に読み込みチェックする	*/
	{
		if( 0 != isxdigit( acTemp[lCnt] ))	/*	0〜9,a〜f,A〜Fのみを読み込む	*/
		{
			acModeDat[lCnt] = acTemp[lCnt];
			DbgMsg01( DLv04, ( OutPut, "***** acModeDat[%ld]:", lCnt) );
			DbgMsg01( DLv04, ( OutPut, "%x:%c\n", acModeDat[lCnt], acModeDat[lCnt]) );
		}
		else
		{
			acModeDat[0] = '\0';				/*	 それ以外は不正処理		*/
			DbgMsg01( DLv04, ( OutPut, "***** 07:Err Mess:%s\n", strerror(errno) ) );
			
			os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
			
			return(OSSERR);
		}
		
	}
	acModeDat[lCnt] = '\0';

	lRes = strtol(acModeDat, NULL, 16);			//	文字→数値変換 文字列→16進数
	if( (ERANGE  == errno) ||
		(EINVAL  == errno) )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 08:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
		
		return(OSSERR);
	}
	
	lModeNum = lRes;
	DbgMsg01( DLv04, ( OutPut, "***** 変換された値(16進):%08lx\n", lModeNum ) );
	
/****************************************/
/*	終了処理							*/
/****************************************/
	*plInf = lModeNum;							/*	引数に値を代入する	*/
//	DbgMsg01( DLv01, ( OutPut, "***** End osprgmd *****\n" ) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_TRA_OUT, 1, NORMAL );	
	
	return(NORMAL);
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
