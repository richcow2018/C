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
/* ＜モジュール名＞					 セマフォの信号待ち											*/
/* ＜モジュールＩＤ＞				 oswaitsp													*/
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
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０６月１３日		故障管理番号（ＴＢＣＳ０１４３）*/
/* ＜ソース修正者＞ 			 	 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月２２日		故障管理番号（ＴＢＣＳ０２３４）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 セマフォの信号待ち 																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<oswaitsp.h>																*/
/*																								*/
/*	   	long	oswaitsp( long spid, long count, long limit )									*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long	spid;		セマフォ識別子（0以外の正値）										*/
/*		long	count;		減算値（0x0000〜0x7ffff）											*/
/*		long	limit;		制限時間（-1又は0以外の整数値）  									*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常処理		NORMAL																	*/
/*		終了処理		OSEEISPI																*/
/*						OSEEICNT																*/
/*						OSEEILIM																*/
/*						OSEENEXS																*/
/*						OSEEWKEX																*/
/*						OSEEDELD																*/
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
#include "oswaitsp.h"
#include "oswaitsp_ins.h"                         // 内部参照用（個別）

/************************************************************************************************/
/* 機能：セマフォの信号待ち                                                                     */
/* 作成日：2002年8月14日                                                                        */
/* 変更日：                                                                                     */
/* 作成者：江川                                                                                 */
/* 呼出形式：                                                                                   */
/*   long oswaitsp( long spid, long count, long limit )                                         */
/*     long spid           セマフォ識別子（0x000a0000〜0x000affff又は0x00030000〜0x0003ffff）   */
/*     long count          減算値（0x0000〜0x7ffff）                                            */
/*     long limit          制限時間（-1又は0以外の整数値）                                      */
/*                                                                                              */
/************************************************************************************************/
long oswaitsp( long spid, long count, long limit )
{
    int  iSemId;                                  // セマフォID
    long lUnLimWt;                                // os_unlimwtの返却値
    long lLimWt;                                  // os_limwtの返却値
	char  acSemKey[9];                            // セマフォ用
    long  lSemKey = 0;                            // ntok用
    
    
	os_trcget2( D_MD_OSWAITSP, D_T_TRA_IN, 3, spid, count, limit );
    
	DbgMsg01( DLv02, ( OutPut, "***** Start oswaitsp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** spid  :%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** count :%04x\n", count) );
//	DbgMsg01( DLv04, ( OutPut, "***** limit :%d\n", limit) );
    //********************************************
    //***** 引数チェック
    //*****
    //if( D_OS_SPIDMIN >= spid )                  // 20021218 修正
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // セマフォ識別子
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEISPI\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEISPI );
		
        return( OSEEISPI );
    }

    if(( D_OS_SUBMIN > count ) || ( D_OS_SUBMAX < count))
    {                                             // 減算値
		DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEICNT\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEICNT );
		
        return( OSEEICNT );
    }

    if( (D_OS_WAIT != limit) && (D_OS_NOWAIT >= limit) )
    {                                             // 制限時間
		DbgMsg01( DLv05, ( OutPut, "***** 03:Err OSEEILIM\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEILIM );
		
        return( OSEEILIM );
    }
    //********************************************
    //***** セマフォIDの取得
    //*****
    /*------2002/12/18 追加 ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, IPC_EXCL ); // 20021218 修正
		os_trcget2( D_MD_OSWAITSP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, IPC_EXCL );
		os_trcget2( D_MD_OSWAITSP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 04:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08lx\n", iSemId) );
            goto err_oswaitsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semget ループ iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08lx\n") );

    //********************************************
    //***** セマフォ値の減算
    //*****
    if( D_OS_WAIT == limit )
    {                                             // 無条件待ち
        lUnLimWt = os_unlimwt( iSemId, count );
        //if( D_ERR_OSUNLIMWT == lUnLimWt )
        if( NORMAL != lUnLimWt )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 05:os_unlimwt Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err os_unlimwt lUnLimWt:%08lx\n", lUnLimWt) );
            goto err_oswaitsp;
        }
    }
    else
    {
        lLimWt = os_limwt( iSemId, count, limit );	// 制限時間待ち
//      if( D_ERR_OSLIMWT == lLimWt )
        if( NORMAL != lLimWt )						// 返却値が正常以外の場合
        {
			DbgMsg01( DLv05, ( OutPut, "***** 06:os_limwt Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err os_limwt lLimWt:%08lx\n", lLimWt) );
			
													// 20030317 追加
			if(OSEETOUT == lLimWt)					// タイムアウトによるエラーの場合
			{
				DbgMsg01( DLv02, ( OutPut, "***** End oswaitsp\n") );
				os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 1, OSEELOST );
				return(OSEETOUT);					// time outを返却
			}

            goto err_oswaitsp;						// その他のエラーの場合
        }
    }

    DbgMsg01( DLv04, ( OutPut, "***** limit:%d\n", limit) );
	DbgMsg01( DLv02, ( OutPut, "***** End oswaitsp\n") );

	os_trcget2( D_MD_OSWAITSP, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );


//************************************************
//***** 異常処理
//*****
err_oswaitsp:

    switch( errno ){
    case ENOENT:
    	DbgMsg01( DLv05, ( OutPut, "***** 07:Err ENOENT\n") );
   		
   		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEENEXS );
    	
    	return( OSEENEXS ); 
    	break;
    	
    case ENOMEM:
    	DbgMsg01( DLv05, ( OutPut, "***** 08:Err ENOMEM\n") );
    case ENOSPC:
    	DbgMsg01( DLv05, ( OutPut, "***** 09:Err ENOSPC\n") );
    case ERANGE:
    	DbgMsg01( DLv05, ( OutPut, "***** 10:Err ERANGE\n") );
    	
    	os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEWKEX );
    	
    	return( OSEEWKEX ); 
    	break;
    	
    case EIDRM :
    	DbgMsg01( DLv05, ( OutPut, "***** 11:Err EIDRM\n") );
    
    	os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEDELD );
    
    	return( OSEEDELD ); 
    	break;
    	
    case EINVAL:
    	DbgMsg01( DLv05, ( OutPut, "***** 12:Err EINVAL\n") );
    	
   		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEISPI );
    	
    	return( OSEEISPI ); 
    	break;
    default:
		/***** 故障処理票KL0044の対応	Start							修正日：2003.03.26	*****/
		DbgMsg01( DLv05, ( OutPut, "***** 13:Err default\n") );
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 1, errno );
//		abort();
		break;
		/***** 故障処理票KL0044の対応	 End							修正日：2003.03.26	*****/
  }
}

/************************************************************************************************/
/* 機能：セマフォ値の減算（無条件待ち）                                                         */
/* 作成日：2002年8月14日                                                                        */
/* 変更日：                                                                                     */
/* 作成者：江川                                                                                 */
/* 呼出形式：                                                                                   */
/*   long os_unlimwt( long iSemId, long count )                                                 */
/*     long iSemId         セマフォID（0以外の正値）                                            */
/*     long count          減算値（0x0000〜0x7ffff）                                            */
/*                                                                                              */
/************************************************************************************************/
long os_unlimwt( long iSemId, long count )
{
    int  iSemOp;                                  // semopの返却値
    long lCnt;                                    // tSemBuf.sem_opの設定値
    
	os_trcget2( D_MD_OS_UNLIMWT, D_T_TRA_IN, 2, iSemId, count );
    
	DbgMsg01( DLv02, ( OutPut, "***** Start-Sub os_unlimwt\n") );
    //********************************************
    //***** 初期値の設定
    //***** sem_flgの設定については要調査
    lCnt = count * D_SIGN_CHANGE;                 // 引数（count）の符号変換
    tSemBuf.sem_num = D_SEM_NUM;                  // セマフォ配列の要素番号設定
    tSemBuf.sem_op = lCnt;                        // セマフォの加算値設定
/*****	故障管理番号TBCS0243の対応		Start							修正日：2003.07.22	*****/
/************************************************************************************************/
/*	sem_flgの設定を「SEM_UNDO」に変更															*/
/************************************************************************************************/
	tSemBuf.sem_flg = SEM_UNDO;					  // セマフォの操作フラグ設定
/*****	故障管理番号TBCS0243の対応		 End							修正日：2003.07.22	*****/

    //********************************************
    //***** セマフォ値の減算
    //*****
    do{                                           // セマフォ値の減算
		os_trcget2( D_MD_OS_UNLIMWT, D_T_SYS_SEMOP, 3, iSemId, &tSemBuf, D_SEM_SIZE );
        iSemOp = semop( iSemId, &tSemBuf, D_SEM_SIZE );
		os_trcget2( D_MD_OS_UNLIMWT, D_T_SYS_END, 1, iSemOp );
        
        if( D_ERR_SYS == iSemOp && EINTR != errno )
        {
		DbgMsg01( DLv05, ( OutPut, "***** Sub-01:semop Err:%s\n", strerror(errno) ) );
		DbgMsg01( DLv05, ( OutPut, "***** Err semop iSemOp:%08lx\n", iSemOp) );
		DbgMsg01( DLv05, ( OutPut, "***** return D_ERR_OSUNLIMWT:%08lx\n", D_ERR_OSUNLIMWT) );
			
			//os_trcget2( D_MD_OS_UNLIMWT, D_T_ERR_SYS, 1, D_ERR_OSUNLIMWT );
			os_trcget2( D_MD_OS_UNLIMWT, D_T_ERR_SYS, 1, errno );
		
            return( D_ERR_OSUNLIMWT );
        }
//			DbgMsg01( DLv04, ( OutPut, "***** semop ループ iSemOp:%d\n", iSemOp) );
    } while( D_ERR_SYS == iSemOp );

	DbgMsg01( DLv02, ( OutPut, "***** End-Sub os_unlimwt\n") );
	
	os_trcget2( D_MD_OS_UNLIMWT, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

}

/************************************************************************************************/
/* 機能：セマフォ値の減算（制限時間待ち）                                                       */
/* 作成日：2002年8月14日                                                                        */
/* 変更日：                                                                                     */
/* 作成者：江川                                                                                 */
/* 呼出形式：                                                                                   */
/*   long os_limwt( long iSemId, long count, long limit )                                       */
/*     long iSemId         セマフォID（0以外の正値）                                            */
/*     long count          減算値（0x0000〜0x7ffff）                                            */
/*                                                                                              */
/************************************************************************************************/
long os_limwt( long iSemId, long count, long limit )
{
    int  iSemOp;                                  	// semopの返却値
    long lCnt;                                    	// tSemBuf.sem_opの設定値
    long lSysTmCl;                                	// os_systimの返却値
    
	os_trcget2( D_MD_OS_LIMWT, D_T_TRA_IN, 3, iSemId, count, limit );

	DbgMsg01( DLv02, ( OutPut, "***** Start-Sub os_limwt\n") );


	/****************************************/
	/*  セマフォ値の設定					*/
	/****************************************/
    lCnt = count * D_SIGN_CHANGE;                 	// 引数（count）の符号変換
    tSemBuf.sem_num = D_SEM_NUM;                  	// セマフォ配列の要素番号設定
    tSemBuf.sem_op = lCnt;                        	// セマフォの加算値設定
/*****	故障管理番号TBCS0243の対応		Start							修正日：2003.07.22	*****/
/************************************************************************************************/
/*	sem_flgの設定を「SEM_UNDO」に変更															*/
/************************************************************************************************/
	tSemBuf.sem_flg = SEM_UNDO;						// セマフォの操作フラグ設定
/*****	故障管理番号TBCS0243の対応		 End							修正日：2003.07.22	*****/


	/****************************************/
	/*  タイマ発行							*/
	/****************************************/
/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグのクリアを追加													*/
/************************************************************************************************/
	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		// システムタイマフラグの初期化
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/

    lSysTmCl = os_systim( limit, D_TIMER_UNIT, D_TIMER_UPTIME );
    //if( D_ERR_OSSYSTIM == lSysTmCl )				// 200030317 修正
	if(NORMAL != lSysTmCl)							// 返却値が正常以外の場合
	{
		/***** 故障処理票KL0044の対応	Start							修正日：2003.03.26	*****/
		/****************************************************************************************/
		/*	システムコールタイマによるエラーの場合は「OSEEWKEX」を返却するように修正			*/
		/****************************************************************************************/
		errno = ERANGE ;

		DbgMsg01( DLv05, ( OutPut, "***** Err os_systim lSysTmCl:%08lx\n", lSysTmCl) );
		DbgMsg01( DLv05, ( OutPut, "***** Sub-02:01 os_systim Err:%s\n", strerror(errno) ) );

		os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 2, lSysTmCl, errno );
//		return( lSysTmCl );
		return( D_ERR_OSLIMWT );					// −１を返却
		/***** 故障処理票KL0044の対応	 End							修正日：2003.03.26	*****/
	}


	/***** 故障処理票KL0043の対応	Start								修正日：2003.03.26	*****/
	/********************************************************************************************/
	/*	タイムアウトの判定処理を修正															*/
	/********************************************************************************************/
	/****************************************/
	/*  制限時間になるまで繰り返す			*/
	/****************************************/
    while( 1 )
    {
		errno  = 0;
		iSemOp = 0;

		/****************************************/
		/*  セマフォ値の減算					*/
		/****************************************/
		os_trcget2( D_MD_OS_LIMWT, D_T_SYS_SEMOP, 3, iSemId, &tSemBuf, D_SEM_SIZE );
        iSemOp = semop( iSemId, &tSemBuf, D_SEM_SIZE );
		os_trcget2( D_MD_OS_LIMWT, D_T_SYS_END, 1, iSemOp );

		DbgMsg01( DLv05, ( OutPut, "***** Err semop iSemOp:%08lx\n", iSemOp) );

		if ( D_ERR_SYS == iSemOp )					// 返却値がエラーの場合
		{
			if (EINTR == errno)						// errnoが「EINTR」の場合
			{
				DbgMsg01( DLv05, ( OutPut, "***** ptEtmc->cSysTimeFlg:%x\n",ptEtmc->cSysTimeFlg) );

/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグの判定処理を修正												*/
/************************************************************************************************/
//				if (0x00 == ptEtmc->cSysTimeFlg)	// システムコールタイマフラグが「OFF」の場合

													// システムコールタイマフラグが「未発行」
													// 又は「発行中」の場合
				if ((0x00 == ptEtmc->cSysTimeFlg) || (0x01 == ptEtmc->cSysTimeFlg))
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/
				{
					DbgMsg01( DLv05, ( OutPut, "***** Sub-02:02 semop Err:%s\n", strerror(errno)));

					continue;						// リトライ処理へ
				}
				else								// システムコールタイマフラグが
				{									// 「タイムアウト」の場合
					DbgMsg01( DLv05, ( OutPut, "***** Sub-02:03 semop Err:%s\n", strerror(errno)));
/*****	故障管理番号TBCS0143の対応		Start							修正日：2003.06.13	*****/
/************************************************************************************************/
/*	システムコールタイマーフラグのクリアを追加													*/
/************************************************************************************************/
													/* システムタイマフラグの初期化				*/
					ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;	
/*****	故障管理番号TBCS0143の対応		 End							修正日：2003.06.13	*****/
					os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 2, OSEETOUT, errno );
					return( OSEETOUT );				// タイムアウトを返却
				}
			}
			else									// errnoが「EINTR以外」の場合
			{
				DbgMsg01( DLv05, ( OutPut, "***** Sub-02:04 semop Err:%s\n", strerror(errno) ) );

				os_tmcan(0);						// タイマキャンセル

				os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 1, errno );
				return( D_ERR_OSLIMWT );			// −１を返却
			}
		}
		else										// 返却値が正常の場合
		{
			os_tmcan(0);							// タイマキャンセル

			os_trcget2( D_MD_OS_LIMWT, D_T_TRA_OUT, 1, NORMAL );
			return( NORMAL );						// 正常終了
		}
	}
	/***** 故障処理票KL0043の対応	 End								修正日：2003.03.26	*****/
}
/************************************************************************************************/
/* End                                                                                          */
/************************************************************************************************/
