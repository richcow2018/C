/************************************************************************************************/
/*  著作権  ２００２                                                                            */
/*            株式会社ＮＴＴデータ                                                              */
/*              金融ビジネス事業本部                                                            */
/*                                                                                              */
/*                                                                                              */
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				ＴＲＥ 														*/
/* ＜サービス項目名＞               例外制御                                                    */
/* ＜サービス項目ＩＤ＞             ＸＸＸＸＸＸＸ                                              */
/* ＜モジュール名＞                 終了コード収集                                              */
/* ＜モジュールＩＤ＞               os_gttrmcod                                                 */
/* ＜モジュール通番＞                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種名＞                   汎用サーバ                                                  */
/* ＜適用ＯＳ＞                     Ｌｉｎｕｘ                                                  */
/* ＜開発環境＞                     ＲＨＡＳ２．１                                              */
/* ＜記述言語＞                     Ｃ言語                                                      */
/* ＜モジュール形態＞               関数                                                        */
/* ＜機能区分＞                                                                                 */
/* ＜対象データ＞                                                                               */
/* ＜工程・階層区分＞                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞				 ＬＡＬａ−ＳＭＰシステム									*/
/* ＜開発システム番号＞              ＰＰ４０Ｂ００１２２０                                     */
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ)			    	*/
/* ＜電話番号＞                      148-1457(03-5437-1457)                                     */
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞                      ＣＢ事ビジネス企画担当                                     */
/* ＜設計年月日＞                    ２００２年　９月２７日                                     */
/* ＜設計修正者名＞                                                                             */
/* ＜設計修正年月日及び修正ＩＤ＞                                                               */
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞                 ＣＢ事ビジネス企画担当(メーカー:ＸＸＸＸ)                   */
/* ＜ソース作成年月日＞             ２００２年  ９月２７日                                      */
/* ＜ソース修正者＞                 サプライ　藤里                                              */
/* ＜ソース正年月日及び修正ＩＤ＞   ２００３年　６月　２日		故障管理番号（ＴＢＣＳ００８５）*/
/*																故障管理番号（ＴＢＣＳ００８７）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞               ステップ                                                    */
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞                                                                                 */
/*      終了コード収集関数                                                                      */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞                                                                                 */
/*      #include    <oscreat.h>                                                                 */
/*                                                                                              */
/*      void os_gttrmcod(void)                                                                  */
/*                                                                                              */
/* ＜仮引数＞                                                                                   */
/*                                                                                              */
/* ＜返却値＞                                                                                   */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞                                                                         */
/* ＜制限事項＞                                                                                 */
/*     TRADEエミュレータ配下の子プロセスのみを対象とする                                        */
/* ＜使用外部モジュールＩＤ＞                                                                   */
/* ＜呼出元のモジュールＩＤ＞                                                                   */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
/* 標準ヘッダファイル */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>            //memset用ヘッダ
#include <sys/types.h>         //wait用ヘッダ
#include <sys/wait.h>
#include <errno.h>			

/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "os_gttrmcod.h"
#include "os_gttrmcod_ins.h"

/* 定数定義 */

/* 外部変数宣言 */

/* 外部関数宣言 */

/* 内部関数宣言 */

/* static変数の宣言 */

/*****************************************************************************/
/* 機能：終了コード収集関数                                                  */
/* 作成日：2002年11月06日                                                    */
/* 変更日：　　年　月　日                                                    */
/* 作成者：大野　正喜                                                        */
/* 呼出形式：void os_gttrmcod(void)                                          */
/*                                                                           */
/*****************************************************************************/
void os_gttrmcod(void)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	int iChpid = 0;                      //子プロセスのプロセスＩＤ
	pid_t lRetwait = 0;                  //waitの返却値
	long lPinf = 0;                      //プロセス情報
	TEprcTableInd *ptTableInd = NULL;       //プロセス管理テーブル個別部のアドレス
	TSMPFORM smpwork = { 0 , 0 };    //ＳＭＰ通知フォーマット編集域
	long lRetsm = 0;                     //ossmsenの返却値
	long lpcode = 0;                     //プロセス識別子退避域
/*****	障害対応（TBCS0085/TBCS0087）Start								修正日：2003.06.02	*****/
	char acPName[16];								// プロセス名退避領域
/*****	障害対応（TBCS0085/TBCS0087） End								修正日：2003.06.02	*****/


	/********************************************************************************************/
	/*  初期処理                                                                                */
	/********************************************************************************************/
	os_trcget2( D_MD_OS_GTTRMCOD, D_T_TRA_IN, 0 );

	DbgMsg01(DLv02,(OutPut,"**** os_gttrmcod: Start DbgMainFunc\n"));	
	
	/************************************************/
	/*	子プロセスのＰＩＤ取得						*/
	/************************************************/
	while( 1 )
	{
		os_trcget2( D_MD_OS_GTTRMCOD, D_T_SYS_WAIT, 0 );
				
//		lRetwait = wait( &iChpid );          //子プロセスのＩＤ取得
												// 20030402 修正
		lRetwait = waitpid( 0, NULL, WNOHANG );
		
		os_trcget2( D_MD_OS_GTTRMCOD, D_T_SYS_END, 2, lRetwait, errno );
		
//		DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: End wait Ret=%ld Chpid=%d\n",lRetwait,iChpid));
		DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: End wait Ret=%ld Err Mess:%s\n"
						,lRetwait, strerror(errno) ));
/*****	障害対応（TBCS0085/TBCS0087）Start								修正日：2003.06.02	*****/
/************************************************************************************************/
/*	waitpidの返却値が「0」の場合は無条件に終了するように修正									*/
/************************************************************************************************/
												// 20030402 修正
//		if(lRetwait == D_ERR_SYS)          //wait失敗
//		if( (D_ERR_SYS == lRetwait)  || (0 == lRetwait) )
		if (D_ERR_SYS == lRetwait)					// 返却値が異常の場合
		{
			if( errno == EINTR )			//割り込み発生
			{
				continue;					//リトライ
			}
			else							//割り込み以外のエラー
			{
//				DbgMsg01(DLv05,(OutPut,"**** os_gttrmcod: Err wait:%ld\n",lRetwait));  
			
				os_trcget2( D_MD_OS_GTTRMCOD, D_T_ERR_SYS, 1, OSEENEXS );
				//return( OSEENEXS );
				return(0);
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_GTTRMCOD << 16) | D_T_ERR_SYS );
			}
		}
		else if (0 == lRetwait)						// 対象プロセスなし
		{
			os_trcget2( D_MD_OS_GTTRMCOD, D_T_TRA_OUT, 1, NORMAL );
			return;									// 処理終了
		}
/*****	障害対応（TBCS0085/TBCS0087） End								修正日：2003.06.02	*****/

		break;									//wait成功
	}


	/********************************************************************************************/
	/*  本処理																					*/
	/********************************************************************************************/
	/************************************************/
	/*	プロセス管理テーブル個別部の取得			*/
	/************************************************/
	DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: Start os_GstPrSep\n"));
	lPinf = os_GstPrSep( 2 , lRetwait );        //プロセスＩＤからプロセス情報取得
//	lPinf = os_GstPrSep( 2 , iChpid );          //プロセスＩＤからプロセス情報取得
	DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: End os_GstPrSep:Pinf=%ld\n",lPinf));
	if(lPinf == -1)                             //プロセス情報取得失敗
	{
//    	DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: Err os_GstPrSep\n"));
    											// 20030312 SSLA0018 修正
    	//os_trcget2( D_MD_OS_GTTRMCOD, D_T_ERR_SYS, 1, OSEEIMPI );
    	//os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_GTTRMCOD << 16) | D_T_ERR_SYS );
		//return( OSEEIMPI );
		os_trcget2( D_MD_OS_GTTRMCOD, D_T_TRA_OUT, 1, NORMAL );
		return(0);
	}
	ptTableInd = (TEprcTableInd *)(ptEprc+1);  //プロセス管理テーブル個別部の
	                                         //先頭アドレス
	ptTableInd += lPinf;                     //当該プロセス管理テーブル個別部の
	                                         // アドレス
	DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: ptTableInd=%p LaunchFlg=%c\n",
				ptTableInd,ptTableInd->cLaunchFlg));

	/************************************************/
	/*	ＳＭＰ終了通知送信処理						*/
	/************************************************/
	if( ptTableInd->cLaunchFlg == 'S' )          //立ち上げ状態が"立ち上げ正常"
	{
		DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: EndCode=%08lx\n",ptTableInd->lEndCode));

		/********************************************/
		/*	終了コード「重要度」による振り分け		*/
		/********************************************/
		switch( ((ptTableInd->lEndCode) & 0x000F0000) >> 16 )         //終了コードで場合分け
		{        
			case 1:
				DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: case1 EndCode=%08lx\n",
					ptTableInd->lEndCode));
				break;                       //1のときは何もしない
			
			case 0:
			case 2:
			case 3:                        //終了コードが0,2,3のときの処理
						
				DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: case0,2,3 EndCode=%08lx\n",
						ptTableInd->lEndCode));
				/************************************/
				/*	メッセージの編集				*/
				/************************************/
				//smpwork.lSmpCode = 0xc0030000;	// 識別種別、PUID、中分類コード設定
				//smpwork.lSmpCode |= (ptTableInd->lPCode & 0x0000ffff);

				smpwork.cID = 0xc0;					// 識別種別、PUID
				smpwork.cType = 0x03;				// 中分類コード設定
													//詳細分類コードを設定
				smpwork.sBunrui = (short)(ptTableInd->lPCode & 0x0000ffff);
													//要因コードに終了コードを設定
				smpwork.lResCode = ptTableInd->lEndCode;

 				DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: smpwork.cID:%x smpwork.cType:%x \n",
 							smpwork.cID, smpwork.cType));
 								
 			DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: smpwork.sBunrui:%x smpwork.lResCode:%08lx\n"
 							,smpwork.sBunrui, smpwork.lResCode ));

				/************************************/
				/*	メッセージの送信				*/
				/************************************/
				DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: Start ossenms\n"));
				lRetsm = ossenms( ptMyEPRC->lPCode , sizeof(TSMPFORM) , (char *)&smpwork );
				//lRetsm = 0;
				DbgMsg01(DLv03,(OutPut,"**** os_gttrmcod: End ossenms: Ret=%08lx\n",lRetsm));
			                                  //メッセージの送信
				if( lRetsm != NORMAL )        //送信失敗
				{
//					DbgMsg01(DLv05,(OutPut,"**** os_gttrmcod: Err ossenms: Ret=%ld\n",lRetsm));
					
					os_trcget2( D_MD_OS_GTTRMCOD, D_T_ERR_SYS, 1, lRetsm );
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_GTTRMCOD << 16) | D_T_ERR_SYS );
					//return( lRetsm );
					break;
				}
				break;
			
			default :
//				DbgMsg01(DLv04,(OutPut,"**** os_gttrmcod: Err EndCode=%ld\n",ptTableInd->lEndCode));
				
				os_trcget2( D_MD_OS_GTTRMCOD, D_T_ERR_SYS, 1, OSEEICOD );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_GTTRMCOD << 16) | D_T_ERR_SYS );
				//終了コードが0,1,2,3以外の場合のエラー処理
				//return( OSEEICOD );
				break;
		}
	}
	

	/********************************************************************************************/
	/*	終了処理																				*/
	/********************************************************************************************/
	/******************************************/
	/*    プロセス管理テーブル個別部クリア    */
	/******************************************/
/*****	障害対応（TBCS0085/TBCS0087）Start								修正日：2003.06.02	*****/
/************************************************************************************************/
/*	終了コード関連のクリアをやめるように修正													*/
/************************************************************************************************/
	memset( acPName, 0, sizeof( acPName ) );		// プロセス名の退避領域クリア
	strncpy( acPName, ptTableInd->acPName, 8 );		// プロセス名の退避
	lpcode = ptTableInd->lPCode;               //プロセス識別子の退避
//	memset( ptTableInd , 0 , sizeof( TEprcTableInd ) ); //プロセス管理テーブル個別部クリア
	memset( ptTableInd , 0 , sizeof( TEprcTableInd ) - ( 8 + (32 * sizeof(long)) ) );
	ptTableInd->lPCode = lpcode;               //プロセス識別子の設定
	strncpy( ptTableInd->acPName, acPName, 8 );		// プロセス名の設定
                                               // 例外ハンドラ初期化
//	memset( &(ptTableInd->func[0]), -1, 32 * sizeof(long) );
/*****	障害対応（TBCS0085/TBCS0087） End								修正日：2003.06.02	*****/
	
	DbgDmp02( DLv04, ("ptTableInd in os_abort", ptTableInd, sizeof(TEprcTableInd), 1, 0));
//	DbgMsg01(DLv02,(OutPut,"**** os_gttrmcod: End DbgMsgFunc:Pcode=%x\n",ptTableInd->lPCode));
	
	os_trcget2( D_MD_OS_GTTRMCOD, D_T_TRA_OUT, 1, NORMAL );

												// 20030402 追加
	os_gttrmcod();
	//return( NORMAL );
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
