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
/* ＜サービス項目名＞				 共用メモリ管理												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 共用メモリの確保											*/
/* ＜モジュールＩＤ＞				 osgtshm													*/
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
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(:ＸＸＸＸ)							*/
/*									 サプライ　梶原												*/
/* ＜ソース作成年月日＞ 			 ２００２年１０月　３日 									*/
/* ＜ソース修正者＞ 				 サプライ　中村												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　１月２２日		仕様変更番号（ＳＳＬＡ０００５）*/
/* ＜ソース修正者＞ 				 サプライ　藤里												*/
/* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　５月　９日		故障管理番号（ＴＢＣＡ００２７）*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０７月１５日     故障管理番号（ＴＢＣＳ０２１０）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/* 機能：共有メモリ確保                                                     					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osgtshm.h>																	*/
/*																								*/
/*		long osgtshm( long shmid, long size, long access, char *addr )							*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long shmid			共有メモリ識別子													*/
/*		long size			メモリバイト数														*/
/*		long access			アクセス権															*/
/*		char *addr			先頭論理アドレス													*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			共有メモリ・セグメントのアドレス									*/
/*		異常終了			OSEEISHM															*/
/*							OSEEIADR															*/
/*							OSEEEXST															*/
/*							OSEESHMS															*/
/*							OSEEDBLM															*/
/*							OSEENRPG															*/
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <u_mpf.h>									// ntok用


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include "osgtshm.h"
#include "osgtshm_ins.h"							// 内部参照用（個別）


/***************************** 利用者作成ヘッダ・ファイル ***************************************/
/* 機能		：共有メモリの確保																	*/
/* 作成日	：2002年10月 3日																	*/
/* 変更日	：2002年10月12日																	*/
/* 作成者	：梶原																				*/
/* 呼出形式	：																					*/
/*	long osgtshm( long shmid, long size, long access, char *addr )								*/
/*		long shmid		共有メモリ識別子														*/
/*		long size		メモリバイト数															*/
/*		long access		アクセス権																*/
/*		char *addr		先頭論理アドレス														*/
/*																								*/
/***************************** 利用者作成ヘッダ・ファイル ***************************************/
long osgtshm( long shmid, long size, long access, char *addr )
{

	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
//	long lAsso;										// 種別
	long lSerNum;									// 通番
	char acShmKey[D_SHMKEY_LEN];					// 共有メモリ識別子文字列
//	BlpMpf_Key_t lIpcKey;							// IPCキー
	BlpMpf_key_t lIpcKey;							// IPCキー
	int iRet;										// 関数結果返却値
	int iErrNum;									// errno退避値
	int iShmId;										// 共有メモリID
	long lIndNum;									// 個別部数
    void  *pvSegAddr;								// 共有メモリセグメントアドレス
    TEsmcTableInd *ptIndAdr;						// 共有メモリ管理テーブル個別部のアドレス


	/********************************************************************************************/
	/*	初期処理																				*/
	/********************************************************************************************/
    os_trcget2(D_MD_OSGTSHM,D_T_TRA_IN,4, shmid, size, access, addr);
//  DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );


//	lAsso = os_GetAsso( shmid );					// 種別の取得
	lSerNum = os_GetSerNum( shmid );				// 通番の取得

    lIndNum = ptEsmc->lIndPartNum;					// 個別部数取得

													// 通番が不正の時
//  if(( D_SHMKEY_MIN > lSerNum ) || ( lIndNum < lSerNum ))
/*****  障害対応（TBCS0210）    Start                                   修正日：2003.07.15  *****/
    if(( -1 > lSerNum ) || ( lIndNum <= lSerNum ))
//    if(( -1 > lSerNum ) || ( lIndNum < lSerNum ))
/*****  障害対応（TBCS0210）    End                                     修正日：2003.07.15  *****/
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISHM ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_PRA,1, OSEEISHM);
        return( OSEEISHM );							// OSEEISHMを返却
    }

    if( D_MSIZE_MIN > size )						// メモリバイト数が最小値より小さい時
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_PRA,1, OSEEIADR);
		return( OSEEIADR );							// OSEEIADRを返却
	}

	/*****	障害対応（TBCA0027）	Start								修正日：2003.05.09	*****/
	/********************************************************************************************/
	/*	個別部のアドレス算出処理を修正（取得した通番で指定する）								*/
	/********************************************************************************************/
//	ptIndAdr = ( void * )ptEsmc + sizeof( TEsmcTable ) + sizeof( TEsmcTableInd ) * ( lSerNum - 1 );
	ptIndAdr = ( void * )ptEsmc + sizeof( TEsmcTable ) + (sizeof( TEsmcTableInd ) * lSerNum);
    												// 指定個別部のアドレス取得
	/*****	障害対応（TBCA0027）	 End								修正日：2003.05.09	*****/

    if( D_SHMID_NONE != ptIndAdr->lShmId )
    {									// 共有メモリが確保済みの時
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEEXST);
		return( OSEEEXST );							// OSEEEXSTを返却
	}


	/********************************************************************************************/
	/*	本処理																					*/
	/********************************************************************************************/
													// 共有メモリ識別子を文字列に変換
	sprintf( acShmKey, "%08x", (unsigned int)shmid );
    lIpcKey = BlpMpf_ntok( acShmKey, D_NTOK_PID );	// IPCキー取得
    if( D_ERR_SYS == lIpcKey )						// IPCキー取得に失敗した時
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, -1);
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS );
		//return( -1 );					// -1を返却
	}

    iShmId = shmget( lIpcKey, size, D_SHMGET_FLG );	// 共有メモリの割り当て
    if( D_ERR_SYS == iShmId )						// 共有メモリの割り当てに失敗した時
    {
		goto err_shmget;							// 異常処理に遷移
	}

													// 共有メモリのアタッチ
	os_trcget2(D_MD_OSGTSHM,D_T_SYS_SHMAT,3, iShmId, addr, D_SHMAT_FLG);
	pvSegAddr = shmat( iShmId, addr, D_SHMAT_FLG );
	os_trcget2(D_MD_OSGTSHM,D_T_SYS_END,1, pvSegAddr);

	if( D_ERR_SYS == ( long )pvSegAddr )			// 共有メモリのアタッチに失敗した時
	{
		iErrNum = errno;							// errnoを変数に退避

													// 共有メモリの無効化
        os_trcget2(D_MD_OSGTSHM,D_T_SYS_SHMCTL,3, iShmId, IPC_RMID, NULL);
		iRet = shmctl( iShmId, IPC_RMID, NULL );
        os_trcget2(D_MD_OSGTSHM,D_T_SYS_END,1, iRet);

		if( D_ERR_SYS == iRet )						// 共有メモリの無効化に失敗した時
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS1);
			//return( -1 );							// アボート
		}
		goto err_shmat;								// 異常処理に遷移
	}

	/************************************************/
	/*	共有メモリ管理テーブルの当該個別部を設定	*/
	/************************************************/
	ptIndAdr->lShmId = ( long )iShmId;				// 共有メモリID設定
	ptIndAdr->lShmSize = size;						// 共有メモリサイズ設定
	ptIndAdr->lAttach++;							// 利用状況をインクリメント20030122 追加

	DbgMsg01( DLv04, ( OutPut, "***** %s: ptIndAdr->lAttach:%ld\n",
			D_PROC_NAME, ptIndAdr->lAttach ) );


	/********************************************************************************************/
	/*	終了処理																				*/
	/********************************************************************************************/
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
    os_trcget2(D_MD_OSGTSHM,D_T_TRA_OUT,1, pvSegAddr);
	return( ( long )pvSegAddr );					// pvSegAddrを返却


	/********************************************************************************************/
	/*	異常処理																				*/
	/********************************************************************************************/
err_shmget:
	switch( errno )
	{
		case EINVAL:								// EINVALの時
		case ENOSPC:								// ENOSPCの時
		case ENOMEM:								// ENOMEMの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESHMS ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEESHMS);
			return( OSEESHMS );						// OSEESHMSを返却
			break;
				
		case EEXIST:								// EEXISTの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEEXST);
			return( OSEEEXST );						// OSEEEXSTを返却
			break;
				
		case EIDRM:									// EIDRMの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEDBLM ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEDBLM);
			return( OSEEDBLM );						// OSEEDBLMを返却
			break;
			
		default:									// その他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS2);
			//return( -1 );							// -1を返却
	}


err_shmat:
	switch( iErrNum )
	{
		case EINVAL:								// EINVALの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISHM ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEISHM);
			return( OSEEISHM );						// OSEEISHMを返却
			break;
			
		case ENOMEM:								// ENOMEMの時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENRPG ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEENRPG);
			return( OSEENRPG );						// OSEENRPGを返却
			break;

		default:									// その他の時
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS3);
			//return( -1 );							// -1を返却
	}
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
