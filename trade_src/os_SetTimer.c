/************************************************************************************************/
/*	著作権	２００２														   					*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 タイマ制御													*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 タイマの発行												*/
/* ＜モジュールＩＤ＞				 os_SetTimer												*/
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
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース修正年月日及び修正ＩＤ＞	 ２００３年０７月０４日		故障管理番号（ＴＢＣＳ０２０２）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		タイマ管理テーブル（ETMC）の指定の個別部に対して、setitimerでタイマを発行する。			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_SetTimer_ins.h>															*/
/*																								*/
/*	   	long	os_SetTimer( TEtmcTableInd *ptAdr )												*/
/*																								*/
/* ＜仮引数＞																					*/
/*		TEtmcTableInd	*ptAdr;		タイマを発行する個別部のアドレス							*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了		NORMAL																	*/
/*		異常終了		-1																		*/
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   特になし 																				*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/*****************************  利用者作成ヘッダ・ファイル  *************************************/
#include "os_SetTimer_ins.h"
/****************************************************************************/
/* 機能：共通関数：タイマの発行 											*/
/* 作成日：2002年10月														*/
/* 変更日： 																*/
/* 作成者：中野 															*/
/* 呼出形式：																*/
/*	 long os_SetTimer( TEtmcTableInd *ptAdr );								*/
/*	   TEtmcTableInd *ptAdr 	   タイマを発行する個別部のアドレス 		*/
/****************************************************************************/
long os_SetTimer( TEtmcTableInd *ptAdr )
{
/****************************************************************************/
/* 初期処理 																*/
/****************************************************************************/
	TEtmcTableInd		*ptPrevAdr = NULL; 	// 前タイマアドレス
	TEtmcTableInd		*ptNextAdr = NULL; 	// 次タイマアドレス
	TEtmcTableInd		*ptStartAdr = NULL;	// 発行させるタイマのアドレス
	TEtmcTableInd		*ptTEtmcTableInd = NULL; 
										// タイマ管理テーブルの
										// 個別部の先頭アドレス
	TErdcTableInd		*ptTErdcTableInd = NULL; 
										// rd管理テーブルの個別部先頭アドレス
	struct itimerval	tValue; 		// タイマ値構造体
	long				lSec = NULL;			// 秒設定用変数
	long				lUSec = NULL;			// マイクロ秒設定用変数
	int 				iFlg = NULL;			// 処理振り分けフラグ
	int 				iRet = NULL;			// 返却値処理用変数
	long				lRet = NULL;			// システムコール返却値処理用変数
	int 				iSysCnt = NULL;		// システムコールタイマの数
	int 				iItvCnt = NULL;		// インターバルタイマの数
	int 				iNowCnt = NULL;		// 現在のカウント数


/*****	故障管理番号TBCS0202の対応		Start							修正日：2003.07.04	*****/
	memset(&tValue, 0, sizeof(struct itimerval));	// タイマ値構造体 クリア
/*****	故障管理番号TBCS0202の対応		 End							修正日：2003.07.04	*****/


/****************************************************************************/
/* 本処理																	*/
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OS_SETTIMER, D_T_TRA_IN, 1, ptAdr );

	DbgMsg01( DLv04, ( OutPut, "***** %s: ptAdr->dTimer:%f\n", D_PROC_NAME, ptAdr->dTimer ) );

	for( ; ; )							// タイマ処理が正常終了するまで
	{									// 処理を繰り返す
		/********************************************/
		/*	処理振り分けフラグの設定				*/
		/********************************************/
		if( ptAdr->lReqNum == D_REQUESTNO_INI )
		{								// リクエスト番号が
										// 初期化されている時
			iFlg = D_TIMER_CLEAR;		// タイマ削除処理フラグを設定
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );

		}
		else
		{
			ptPrevAdr = ( TEtmcTableInd * )ptAdr->ptPrevAdr;
										// 前タイマアドレスの取得
			if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc
				&& ( TEtmcTableInd * )ptEtmc->ptNxtAdr == ptAdr )
			{							// 前タイマアドレスが管理部の時 
				iFlg = D_TIMER_START;	// タイマ起動フラグを設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
			else if( ptPrevAdr->lReqNum == D_REQUESTNO_INI )
			{							// 前タイマアドレスのリクエスト番号
				iFlg = D_TIMER_START;	// が初期化されている時
										// タイマ起動フラグを設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
			else
			{
				iFlg = D_TIMER_INSERT;	// タイマ挿入フラグを設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
		}

		if( iFlg == D_TIMER_CLEAR ) 	// タイマ削除時のつなぎかえ処理
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: 削除時つなぎ変え 開始\n",D_PROC_NAME) );
			ptPrevAdr = ( TEtmcTableInd * )ptAdr->ptPrevAdr;
										// 前タイマアドレスの取得
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr ) );
													
			ptNextAdr = ( TEtmcTableInd * )ptAdr->ptNextAdr;
										// 次タイマアドレスの取得
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr=%p )\n",
													D_PROC_NAME, ptNextAdr ) );

			/****************************************/
			/*	タイマ管理部情報の設定				*/
			/****************************************/
			if( ptAdr->ptPrevAdr == ptAdr->ptNextAdr )
			{							// タイマが一つしかない場合
				ptEtmc->ptBefAdr = NULL;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
													
				ptEtmc->ptNxtAdr = NULL;
										// 管理部の前タイマと次タイマをクリア
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			}
			else
			{
				if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc )
				{						// 前タイマが管理部の時
										// 管理部の次アドレスに次タイマを設定
					ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptNextAdr;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
				}
				else
				{
					ptPrevAdr->ptNextAdr = ( struct TEtmcTableInd * )ptNextAdr;
										// 削除タイマの前タイマの次アドレスに
										// 削除タイマの次タイマのアドレスを設定
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr->ptNextAdr ) );
				}

				if( ptNextAdr == ( TEtmcTableInd * )ptEtmc )
				{						// 次タイマが管理部の時
										// 管理部の前アドレスに前タイマを設定
					ptEtmc->ptBefAdr = ( struct TEtmcTableInd * )ptPrevAdr;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
				}
				else
				{
					ptNextAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptPrevAdr;
										// 削除タイマの次タイマの前アドレスに
										// 削除タイマの前タイマのアドレスを設定
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptNextAdr->ptPrevAdr ) );
				}
			}
			
			DbgMsg01( DLv04, ( OutPut, "***** %s: 削除時つなぎ変え 終了\n",D_PROC_NAME) );
		}
		else if( iFlg == D_TIMER_INSERT )
		{								// タイマ挿入時のつなぎかえ処理
			DbgMsg01( DLv04, ( OutPut, "***** %s: 挿入時つなぎ変え 開始\n",D_PROC_NAME) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: ptEtmc:%p\n",D_PROC_NAME, ptEtmc) );
			
			ptNextAdr = ( TEtmcTableInd * )ptAdr->ptNextAdr;
										// 次タイマアドレスの取得
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptAdr->ptNextAdr ) );

			/****************************************/
			/*	タイマ管理部情報の設定				*/
			/****************************************/
			if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc )
			{							// 前タイマが管理部の時
				ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptAdr;
										// 挿入タイマの前タイマの次アドレスに
										// 挿入タイマのアドレスを設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			}
			else
			{
				ptPrevAdr->ptNextAdr = ( struct TEtmcTableInd * )ptAdr;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr->ptNextAdr ) );
			}

			if( ptNextAdr == ( TEtmcTableInd * )ptEtmc )
			{							// 次のタイマが管理部の時
				ptEtmc->ptBefAdr = ( struct TEtmcTableInd * )ptAdr;
										// 挿入タイマの次タイマの前アドレスに
										// 挿入タイマのアドレスを設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
			}
			else
			{
				ptNextAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptAdr;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptNextAdr->ptPrevAdr ) );
			}
			DbgMsg01( DLv04, ( OutPut, "***** %s: 挿入時つなぎ変え 終了\n",D_PROC_NAME) );
		}

		/********************************************/
		/*	タイマの存在チェック					*/
		/********************************************/
		if( ptEtmc->ptBefAdr == NULL && ptEtmc->ptNxtAdr == NULL )
		{								// 発行させるタイマが一つもない時
										// タイマを発行せずに終了する
			
			break;
		}
		else
		{
			ptStartAdr = ( TEtmcTableInd * )ptEtmc->ptNxtAdr;
										// 発行させるタイマのアドレスを取得
			os_trcget2( D_MD_OS_SETTIMER, D_MM_OSSETTIMER, 3,
					ptStartAdr, ptStartAdr->lReqId, ptStartAdr->lReqNum);

			DbgMsg01( DLv04, ( OutPut, "***** %s: 発行対象個別部情報\n",D_PROC_NAME) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr=%p )\n",
													D_PROC_NAME, ptStartAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->dTimer=%12.9f )\n",
													D_PROC_NAME, ptStartAdr->dTimer ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptStartAdr->ptNextAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptStartAdr->ptPrevAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s:タイマカウンタ:%ld\n"
													,D_PROC_NAME, ptEtmc->lTimeNowCnt ));

			DbgDmp02( DLv04, ("ptStartAdr 対象タイマ情報", ptStartAdr, sizeof(TEtmcTableInd),1,0));

			/****************************************/
			/*	タイマ値のチェック					*/
			/****************************************/
			if( ptStartAdr->dTimer == D_TIMEOUT )
			{							// タイムアウトの時
				ptTErdcTableInd = ( TErdcTableInd * )( ptErdc + 1 );
										// rd管理テーブルの
										// 個別部の先頭アドレスを取得
				DbgMsg01( DLv04, ( OutPut, "***** %s: タイマアウト処理\n", D_PROC_NAME ));
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTErdcTableInd=%p )\n",
													D_PROC_NAME, ptTErdcTableInd ) );

				/************************************/
				/*	リクエストIDのチェック			*/
				/************************************/
				if( ptStartAdr->lReqId == D_TIMETYPE_SYS )
				{						// システムコールタイマの時
					ptStartAdr->lReqNum = D_REQUESTNO_INI;
										// リクエスト番号を初期化する
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->lReqNum=%ld )\n",
													D_PROC_NAME, ptStartAdr->lReqNum ) );
				}
				else
				{						// インターバルタイマの時
					lRet = os_SendTimeOutMsg( 
				   		( ptTErdcTableInd + ( ptStartAdr->lReqId - 1 ))->lPCode,
				   	 	ptStartAdr->lReqNum, D_RESULT_NORMAL );
										// rd管理テーブル個別部の
										// リクエスト識別子番目のプロセス識別子
										// 、発行させるタイマのリクエスト番号
										// 、正常 を設定
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
													D_PROC_NAME, lRet ) );

					if( lRet != NORMAL )	
					{					// メッセージ送信に失敗した時	
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
														D_PROC_NAME, -1 ) );
						return( -1 );	// アボート処理
					}
				}
				DbgMsg01( DLv04, ( OutPut, "***** %s: タイマアウト処理完了\n", D_PROC_NAME ));
			}
			else						// タイマ発行処理を行う
			{
				DbgMsg01( DLv04, ( OutPut, "***** %s: タイマ発行処理\n", D_PROC_NAME ));
				/************************************/
				/*	タイマ値の設定					*/
				/************************************/
				//lSec = ( long )ptAdr->dTimer;
				lSec = ( long )(ptStartAdr->dTimer);			//20030121 修正
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
													D_PROC_NAME, lSec ) );
				tValue.it_value.tv_sec = lSec;
										// タイマ値構造体の秒設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tValue.it_value.tv_sec=%ld )\n",
													D_PROC_NAME, tValue.it_value.tv_sec ) );

				//lUSec = ( long )( ( ptAdr->dTimer - lSec) * D_MILLION);
				lUSec = ( long )( ( ptStartAdr->dTimer - lSec) * D_MILLION);	// 20030121 修正
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lUSec=%ld )\n",
													D_PROC_NAME, lUSec ) );
				tValue.it_value.tv_usec = lUSec;
										// タイマ値構造体のマイクロ秒設定
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tValue.it_value.tv_usec=%ld )\n",
													D_PROC_NAME, tValue.it_value.tv_usec ) );

				/************************************/
				/*	タイマの発行					*/
				/************************************/
				os_trcget2( D_MD_OS_SETTIMER, D_T_SYS_SETITIMER, 3, ptStartAdr,
							tValue.it_value.tv_sec, tValue.it_value.tv_usec );
				iRet = setitimer( ITIMER_REAL, &tValue, NULL );
										// タイマを発行させる
				os_trcget2( D_MD_OS_SETTIMER, D_T_SYS_END, 2, iRet, errno);
				
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
													D_PROC_NAME, iRet ) );
													
				DbgMsg01( DLv04, ( OutPut, "***** %s: タイム発行完了\n", D_PROC_NAME ));
				if( iRet != D_ERR_SYS )    
				{						// タイマ発行に成功した時
					break;				// 処理を終了する	
				}
				else					// タイマ発行に失敗した時
				{
					lRet = os_ErrorSetTimer();
										// タイマ発行エラー処理をする
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
													D_PROC_NAME, lRet ) );
										
					if( lRet != NORMAL )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
														D_PROC_NAME, -1 ) );
						return( -1 );	// アボート処理
					}
				}
			}

			/****************************************/
			/*	次タイマの設定						*/
			/****************************************/
										// 20030326 KL0042 修正
			//if( ptAdr->ptNextAdr == ( struct TEtmcTableInd * )ptEtmc )
			if( ptStartAdr->ptNextAdr == ( struct TEtmcTableInd * )ptEtmc )
			{							// 次に発行させるタイマがない時
				ptEtmc->ptNxtAdr = NULL;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
				ptEtmc->ptBefAdr = NULL;
										// 管理部の次タイマと前タイマの初期化
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display (  ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME,  ptEtmc->ptBefAdr ) );
				break;
			}
			
			DbgMsg01( DLv04, ( OutPut, "***** %s: 並び替え 開始\n",D_PROC_NAME) );
			ptAdr = ( TEtmcTableInd * )ptStartAdr->ptNextAdr;
										// 次に発行させるタイマの設定をする
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr=%p )\n",
													D_PROC_NAME, ptAdr ) );
			ptAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptEtmc;
										// 管理部につなぎかえる
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptAdr->ptPrevAdr ) );
			ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptAdr;
										// 管理部からつなぎかえる
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			ptAdr->dTimer += ptStartAdr->dTimer;
										// 発行に失敗したタイマのタイマ値を
										// 次に発行させるタイマに加える
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->dTimer=%lf )\n",
													D_PROC_NAME, ptAdr->dTimer ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: 並び替え 終了\n",D_PROC_NAME) );
		}
	}

/****************************************************************************/
/* 終了処理																	*/
/****************************************************************************/
	iSysCnt = 0;
	iItvCnt = 0;

	/************************************************/
	/*	タイマ管理テーブルの順次参照				*/
	/************************************************/
										// タイマ管理テーブル個別部の
										// 先頭アドレスを取得
	for( iNowCnt = 0; iNowCnt < ptEtmc->lTimeMaxCnt; iNowCnt++ )
	{
		ptTEtmcTableInd = ( TEtmcTableInd * )( ptEtmc + 1 ) + iNowCnt;
//		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd=%p )\n",
//													D_PROC_NAME, ptTEtmcTableInd ) );
		
		if( ptTEtmcTableInd->lReqId == D_TIMETYPE_SYS )
		{								// タイマ種別がシステムコールの時
			if( ptTEtmcTableInd->lReqNum == D_REQUESTNO_INI )
			{							// リクエスト番号が初期化されている時 
				if( ptTEtmcTableInd->dTimer == D_TIMEOUT )
				{						// タイマ値が初期化されている時
					ptEtmc->cSysTimeFlg = D_TIMEFLG_OUT;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				}
				else					// タイマ削除した時
				{
					ptEtmc->cSysTimeFlg = D_TIMEFLG_OFF;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				}
			}
			else
			{
				ptEtmc->cSysTimeFlg = D_TIMEFLG_ON;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				iSysCnt++;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iSysCnt=%d )\n",
													D_PROC_NAME, iSysCnt ) );
			}
		}
		else
		{
			if( ptTEtmcTableInd->lReqId != D_REQUESTID_INI
				&& ptTEtmcTableInd->lReqNum != D_REQUESTNO_INI )
			{						// タイマ種別がインターバルタイマであり
									// リクエスト番号が初期化されてない時
				iItvCnt++;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iItvCnt=%d )\n",
													D_PROC_NAME, iItvCnt ) );
			}
		}

		if( ptTEtmcTableInd->lReqNum == D_REQUESTNO_INI )
		{								// リクエスト番号が初期化されている時
			ptTEtmcTableInd->lReqId = D_REQUESTID_INI;
										// リクエスト記述子の初期化
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->lReqId=%ld )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->lReqId ) );
			ptTEtmcTableInd->ptNextAdr = NULL;
										// 次タイマアドレスの初期化
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->ptNextAdr=%p )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->ptNextAdr ) );
			ptTEtmcTableInd->ptPrevAdr = NULL;
										// 前タイマアドレスの初期化
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->ptPrevAdr=%p )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->ptPrevAdr ) );
			ptTEtmcTableInd->dTimer = D_TIMER_INI;
										// タイマの初期化
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->dTimer=%lf )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->dTimer ) );
		}
	}

	if( iItvCnt > 0 )					// インターバルタイマがある時
	{
		ptEtmc->cIntervalFlg = D_TIMEFLG_ON;
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cIntervalFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cIntervalFlg ) );
	}
	else								// インターバルタイマがない時
	{
		ptEtmc->cIntervalFlg = D_TIMEFLG_OFF;
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cIntervalFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cIntervalFlg ) );
	}
	ptEtmc->lTimeNowCnt = iSysCnt + iItvCnt;
										// 現在利用数を設定
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->lTimeNowCnt=%ld )\n",
													D_PROC_NAME, ptEtmc->lTimeNowCnt ) );

	os_trcget2( D_MD_OS_SETTIMER, D_T_TRA_OUT, 0 );
	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	return( NORMAL );					// 正常終了
}

/****************************************************************************/
/* End																		*/
/****************************************************************************/

