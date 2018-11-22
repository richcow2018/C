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
/* ＜サービス項目名＞				 イベント制御												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 セマフォの生成												*/
/* ＜モジュールＩＤ＞				 oscresp													*/
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
/* 作成者：深水                                                                                   */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年7月26日                                                                          */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 セマフォの生成																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oscresp.h>																	*/
/*																								*/
/*	   	long	oscresp( long value, long spid, long access )  									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	value;		セマフォの初期値（0x0000〜0x7ffff）									*/
/*		long	spid;		セマフォ識別子（0以外の正値）										*/
/*		long	access;		アクセス権（未使用：0を指定）										*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		セマフォ識別子															*/
/*		異常終了		OSEEIVAL																*/
/*	   					OSEEISPI																*/
/*						OSEEEXST																*/
/*						OSEEWKEX																*/
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include "oscresp.h"
#include "oscresp_ins.h"

/**************************************************************************************************/
/* 機能：セマフォの生成                                                                           */
/* 作成日：2002年7月26日                                                                          */
/* 変更日：                                                                                       */
/* 作成者：深水                                                                                   */
/* 呼出形式：                                                                                     */
/*   long oscresp( long value, long spid, long access )                                           */
/*     long value          セマフォの初期値（0x0000〜0x7ffff）                                    */
/*     long spid           セマフォ識別子（0x000a0000〜0x000affff又は0x00030000〜0x0003ffff）     */
/*     long access         アクセス権（未使用：0を指定）                                          */
/*                                                                                                */
/**************************************************************************************************/
long oscresp( long value, long spid, long access )
{
    int   iSemId;                                 // セマフォID
    int   iSemCtl;                                // semctl返却値
    char  acSemKey[9];                            // セマフォ用
    long  lSemKey = 0;                            // ntok用


	os_trcget2( D_MD_OSCRESP, D_T_TRA_IN, 3, value, spid, access);
    

//	DbgMsg01( DLv02, ( OutPut, "***** Start oscresp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** value :%x\n", value) );
//	DbgMsg01( DLv04, ( OutPut, "***** spid  :%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** access:%x\n", access) );
    //********************************************
    //***** 引数チェック
    //*****
    if(( D_OS_SPMIN > value ) || ( D_OS_SPMAX < value))
    {                                             // セマフォの初期値
    	DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEIVAL\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_PRA, 1, OSEEIVAL);
    	
        return( OSEEIVAL );
    }

    //if( D_OS_SPIDMIN >= spid )                  // 20021218修正
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // セマフォ識別子
    	DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEISPI\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_PRA, 1, OSEEISPI);
    	
        return( OSEEISPI );
    }

    //********************************************
    //***** セマフォIDの取得
    //*****
    /*------2002/12/18 追加 ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL ); // 20021218 修正
		os_trcget2( D_MD_OSCRESP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, 
														D_SEM_ACCESS | IPC_CREAT | IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL );
		os_trcget2( D_MD_OSCRESP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 03:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08x\n") );
            goto err_oscresp;
        }
		DbgMsg01( DLv04, ( OutPut, "***** Semget ループ iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08x\n") );

    //********************************************
    //***** セマフォの初期化
    //*****
    uSem.val = value;                             // セマフォの初期値設定

    do{
		os_trcget2( D_MD_OSCRESP, D_T_SYS_SEMCTL, 4, iSemId, D_SEM_NUM, SETVAL, uSem );
        iSemCtl = semctl( iSemId, D_SEM_NUM, SETVAL, uSem );
		os_trcget2( D_MD_OSCRESP, D_T_SYS_END, 1, iSemCtl );
        
        if( D_ERR_SYS == iSemCtl && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 04:semctl Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semctl iSemCtl:%08x\n", iSemCtl) );
            goto err_oscresp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semctl ループ iSemCtl:%08x\n", iSemCtl) );
    } while( D_ERR_SYS == iSemCtl );
    DbgMsg01( DLv04, ( OutPut, "***** semctl iSemCtl:%08x\n", iSemCtl) );

//	DbgMsg01( DLv02, ( OutPut, "***** End oscresp\n") );
	
	os_trcget2( D_MD_OSCRESP, D_T_TRA_OUT, 1, spid);
	
    return( spid );

//************************************************
//***** 異常処理
//*****
err_oscresp:

    switch( errno ){
    case EEXIST:
    	DbgMsg01( DLv05, ( OutPut, "***** 05:Err OSEEEXST\n") );
   		
   		os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEEXST);
   		
    	return( OSEEEXST ); 
    	break;
    	
    case ENOMEM:
    	DbgMsg01( DLv05, ( OutPut, "***** 06:Err ENOMEM\n") );
    case ENOSPC:
    	DbgMsg01( DLv05, ( OutPut, "***** 07:Err OSEEWKEX\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEWKEX);
    	
    	return( OSEEWKEX ); 
    	break;
    	
    case ERANGE:
    	DbgMsg01( DLv05, ( OutPut, "***** 08:Err OSEEIVAL\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEIVAL);
    	
    	return( OSEEIVAL ); 
    	break;
    default:
    	DbgMsg01( DLv05, ( OutPut, "***** 09:Err ABORT\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_ABT, 0);
    	
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCRESP << 16) | D_T_ERR_SYS );
    }

}

/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
