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
/* ＜モジュール名＞					 セマフォの削除												*/
/* ＜モジュールＩＤ＞				 osdelsp													*/
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
/* 作成者：江川                                                                                   */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年7月26日                                                                          */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 セマフォの削除																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osdelsp.h>																	*/
/*																								*/
/*	   	long	osdelsp( long spid, long udf )													*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	spid;		セマフォ識別子（0以外の正値）										*/
/*		long	udf;		無条件削除フラグ													*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		OSEEISPI																*/
/*						OSEEIVAL																*/
/*						OSEEWAIT																*/
/*						OSEENEXS																*/
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
#include "osdelsp.h"
#include "osdelsp_ins.h"                          // 内部参照用（個別）

/**************************************************************************************************/
/* 機能：セマフォの削除                                                                           */
/* 作成日：2002年7月26日                                                                          */
/* 変更日：                                                                                       */
/* 作成者：江川                                                                                   */
/* 呼出形式：                                                                                     */
/*   long osdelsp( long spid, long udf )                                                          */
/*     long spid           セマフォ識別子（0x000a0000〜0x000affff又は0x00030000〜0x0003ffff）     */
/*     long udf            無条件削除フラグ                                                       */
/*                                                                                                */
/**************************************************************************************************/
long osdelsp( long spid, long udf )
{
    int   iSemId;                                 // セマフォID
    int   iSemCtl;                                // semctl返却値
    char  acSemKey[9];                            // セマフォ用
    long  lSemKey = 0;                            // ntok用

	os_trcget2( D_MD_OSDELSP, D_T_TRA_IN, 2, spid, udf );

//	DbgMsg01( DLv02, ( OutPut, "***** Start osdelsp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** spid:%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** udf :%d\n", udf) );
    //********************************************
    //***** 引数チェック
    //*****
    //if( D_OS_SPIDMIN >= spid )                  // 20021218 修正
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // セマフォ識別子
    	DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEISPI\n") );
    	
    	os_trcget2( D_MD_OSDELSP, D_T_ERR_PRA, 1, OSEEISPI  );
    	
        return( OSEEISPI );
    }

    if(( D_OS_CDDEL != udf ) && ( D_OS_UCDDEL != udf ))
    {                                             // 無条件削除フラグ
    	DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEIVAL\n") );
    	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_PRA, 1, OSEEIVAL  );
    	
        return( OSEEIVAL );
    }

    //********************************************
    //***** セマフォIDの取得（セマフォの存在チェック）
    //*****
    /*------2002/12/18 追加 ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, IPC_EXCL ); // 20021218 修正
		os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, IPC_EXCL );
		os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 03:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08x\n") );
            goto err_osdelsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semget ループ iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08x\n") );

    //********************************************
    //***** セマフォによる待ち状態プロセスチェック
    //*****
    if( D_OS_CDDEL == udf )
    {
        do{                                       // セマフォ値の増加待ちプロセス数チェック
			os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, GETZCNT );
            iSemCtl = semctl( iSemId, D_SEM_NUM, GETNCNT );
			os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
            
            if( D_SEM_NOEXIST != iSemCtl && EINTR != errno )
            {
				DbgMsg01( DLv05, ( OutPut, "***** 04:semctl Err:%s\n", strerror(errno) ) );
				DbgMsg01( DLv05, ( OutPut, "***** 01 Err semctl iSemCtl:%08x\n", iSemCtl) );
				
				os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1, OSEEWAIT  );
				
                return( OSEEWAIT );
            }
            DbgMsg01( DLv04, ( OutPut, "***** Semctl ループ01 iSemCtl:%08x\n", iSemCtl) );
        } while( D_SEM_NOEXIST != iSemCtl );
        DbgMsg01( DLv04, ( OutPut, "***** 01 semctl iSemCtl:%08x\n", iSemCtl) );

        do{                                       // セマフォ値の0待ちプロセス数チェック
			os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, GETZCNT );
            iSemCtl = semctl( iSemId, D_SEM_NUM, GETZCNT );
			os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
            
            if( D_SEM_NOEXIST != iSemCtl && EINTR != errno )
            {
				DbgMsg01( DLv05, ( OutPut, "***** 05:semctl Err:%s\n", strerror(errno) ) );
				DbgMsg01( DLv05, ( OutPut, "***** 02 Err semctl iSemCtl:%08x\n", iSemCtl) );
				
				os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1, OSEEWAIT  );
				
                return( OSEEWAIT );
            }
            DbgMsg01( DLv04, ( OutPut, "***** Semctl ループ02 iSemCtl:%08x\n", iSemCtl) );
        } while( D_SEM_NOEXIST != iSemCtl );
        DbgMsg01( DLv04, ( OutPut, "***** 02 semctl iSemCtl:%08x\n", iSemCtl) );
    }

    //********************************************
    //***** セマフォの削除
    //*****
    do{
		os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, IPC_RMID );
        iSemCtl = semctl( iSemId, D_SEM_NUM, IPC_RMID );
		os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
        
        if( D_ERR_SYS == iSemCtl && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 06:semctl Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** 03 Err semctl iSemCtl:%08x\n", iSemCtl) );
            goto err_osdelsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semctl ループ03 iSemCtl:%08x\n", iSemCtl) );
    } while( D_ERR_SYS == iSemCtl );
    DbgMsg01( DLv04, ( OutPut, "***** 03 semctl iSemCtl:%08x\n", iSemCtl) );

//	DbgMsg01( DLv02, ( OutPut, "***** End osdelsp\n") );
	
	os_trcget2( D_MD_OSDELSP, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

//************************************************
//***** 異常処理
//*****
err_osdelsp:

    switch( errno ){
    case ENOENT:
    	DbgMsg01( DLv05, ( OutPut, "***** 07: Err ENOENT\n") );
    	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1,  errno    );
    	
    	return( OSEENEXS ); 
    	break;
    default:
       	DbgMsg01( DLv05, ( OutPut, "***** 08: Err ABORT\n") );
       	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_ABT, 1,errno );
       	
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELSP << 16) | D_T_ERR_SYS );
    }

}
/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
