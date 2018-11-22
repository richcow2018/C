/************************************************************************************************/
/*	著作権	２００２																			*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム    ＴＲＡＤＥエミュレータ									*/
/************************************************************************************************/
/* ＜対象業務名＞					 ＴＲＡＤＥエミュレータ										*/
/* ＜対象業務ＩＤ＞ 				 ＴＲＥ 													*/
/* ＜サービス項目名＞				 共通関数		 											*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ 											*/
/* ＜モジュール名＞                  プールバッファアドレスの正当性チェック                     */
/* ＜モジュールＩＤ＞				 os_ChkPB		 											*/
/* ＜モジュール通番＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種名＞					 汎用サーバ 												*/
/* ＜適用ＯＳ＞ 					 Ｌｉｎｕｘ 												*/
/* ＜開発環境＞ 					 ＲＨＡＳ２．１ 											*/
/* ＜記述言語＞ 					 Ｃ言語 													*/
/* ＜モジュール形態＞				 関数														*/
/* ＜機能区分＞ 																				*/
/* ＜対象データ＞																				*/
/* ＜工程・階層区分＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞				 ＬＡＬａ−ＳＭＰシステム									*/
/* ＜開発システム番号＞ 			 ＰＰ４０Ｂ００１２２０ 									*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞					 ＣＢ事ビジネス企画担当(メーカー：サプライ)			    	*/
/* ＜電話番号＞ 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞ 					 ＣＢ事ビジネス企画担当 									*/
/* ＜設計年月日＞					 ２００２年　９月２７日 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ中村)             */
/* ＜ソース作成年月日＞ 			 ２００３年  ３月１４日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカー：サプライ新保)             */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２００３年０８月０６日     故障管理番号（ＴＢＣＳ０２６３）*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*		  プールバッファアドレスの正当性チェック												*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<os_ChkPB_ins.h> 															*/
/*																								*/
/*	 long os_ChkPB(void *pvPbAdr)																*/
/*																								*/
/* ＜仮引数＞																					*/
/*		void *pvPbAdr	プールバッファアドレス													*/
/*		TEbpcTableInd *ptEbpcIndPar EBPC個別部アドレス											*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			NORMAL																*/
/*		異常終了			OSEEIPOL															*/
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

#include "os_ChkPB_ins.h"

/****************************************************************************/
/* 内部用関数プロトタイプ宣言                                               */
/****************************************************************************/
long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr);
long os_Chk_Unit_Adr(TAdrDat *ptAdrDat, long lUnitAdr);
long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr, long size, long unitsize, long maxnum);
/****************************************************************************/
/* 機能：プールバッファアドレスの正当性チェック                             */
/* 作成日：2003年03月14日                                                   */
/* 変更日：                                                                 */
/* 作成者：中村                                                             */
/* 呼出形式：                                                               */
/*   long os_ChkPB(void *pvPbAdr)                                           */
/*     void *pvPbAdr        プールバッファアドレス                          */
/*     TEbpcTableInd *ptEbpcIndPar 指定EBPC個別部アドレス                   */
/*                                                                          */
/****************************************************************************/
long os_ChkPB(void *pvPbAdr, TEbpcTableInd *ptEbpcIndPar)
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
	long lOpFlg = D_SARCH_BPIND;				// 処理振り分けフラグ
	long lCnt = 0;								// カウンタ
	long lRes = 0;
	long lPbInd = 0;
	long lUnit = 0;

	TEbpcTableInd *ptEbpcInd = NULL;			// BP個別部ポインタ
	TEpbcTableInd *ptEpbcInd = NULL;			// PB個別部ポインタ
	
	TAdrDat tBPdat, tPBdat;

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:pvPbAdr:%p\n", D_PROC_NAME, pvPbAdr) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:ptEbpcIndPar:%p\n", D_PROC_NAME, ptEbpcIndPar ));
	
	if(NULL != ptEbpcIndPar)
	{
												// 指定のEBPC個別部がある時
		lOpFlg = D_CHK_MEM_RANGE2;
	}
	
	ptEbpcInd = (TEbpcTableInd *)(ptEbpc + 1);
	
	for(;;)
	{
		switch(lOpFlg)
		{
		case D_SARCH_BPIND:						// BP個別部検索
			DbgMsg01( DLv04, ( OutPut, "***** SARCH_BPIND\n" ));
			if(lCnt >= ptEbpc->lMaxNum)
			{
				lOpFlg = D_ERR;					// 該当個別部無し
				break;
			}
			else if(D_STAT_CREATED != ptEbpcInd->cStat)
			{
				ptEbpcInd += 1;					// 未作成であれば次の個別部を検索
				break;
			}
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEbpcInd:%p\n", D_PROC_NAME, ptEbpcInd) );
												// 使用中個別部発見
			lOpFlg = D_CHK_MEM_RANGE;			// 共有メモリ範囲チェックへ
			break;

		case D_CHK_MEM_RANGE:					// 共有メモリ範囲チェック
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MEM_RANGE\n" ));

			lRes = os_Chk_SetDat(&tBPdat,
								(long)(ptEbpcInd->pvEbpcAdr),	// 先頭アドレス設定
								0,								// 領域サイズ設定
								ptEbpcInd->lUnitSize + 4,		// ユニットサイズ設定
								ptEbpcInd->lMaxUnitNum );		// ユニット最大数設定

												// ユニットアドレスの先頭アドレス設定
			lUnit = (long)pvPbAdr - 4;

			lRes = os_Chk_Mem_Range( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
												//範囲外であれば次の個別部の検索
				lOpFlg = D_SARCH_BPIND;
				ptEbpcInd += 1;
				break;
			}
												// ユニットアドレスチェックへ
			lOpFlg = D_CHK_MUCH_PBADR;
			break;

		case D_CHK_MUCH_PBADR:					// ユニットアドレスチェック
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MUCH_PBADR\n" ));

			lRes = os_Chk_Unit_Adr( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
				lOpFlg = D_ERR;
				break;
			}

												// 該当PB個別部範囲チェックへ
			lOpFlg = D_CHK_PBIND_RANGE;
			break;

		case D_CHK_PBIND_RANGE:					// 該当PB個別部範囲チェック
			DbgMsg01( DLv04, ( OutPut, "***** CHK_PBIND_RANGE\n" ));

			lRes = os_Chk_SetDat(&tPBdat,
								(long)(ptEpbc + 1),				// 個別部領域先頭アドレス設定
																// 個別部領域サイズ設定
								(ptEsys->tMstEPBC.lSize) - sizeof(TEpbcTable),
								sizeof(TEpbcTableInd),			// 個別部サイズ設定
								0 );							// 個別部数設定
												// ユニット-4が示す値をPB個別部アドレスとする
			lPbInd = *((long*)(pvPbAdr -4));

			lRes = os_Chk_Mem_Range( &tPBdat, lPbInd );
			if(NORMAL != lRes)
			{
				lOpFlg = D_ERR;
				break;
			}
												// 該当PBユニットアドレスチェック
			lOpFlg = D_CHK_PBADR;
			break;

		case D_CHK_PBADR:						//PB個別部 ユニットアドレス比較
			DbgMsg01( DLv04, ( OutPut, "***** CHK_PBADR\n" ));
			lRes = os_Chk_Unit_Adr( &tPBdat, lPbInd );
			if(NORMAL == lRes)
			{
				DbgMsg01( DLv04, ( OutPut, "***** ユニットアドレス整合性チェック\n" ));
				ptEpbcInd = (TEpbcTableInd *)lPbInd;
												// ユニットアドレスの比較
				DbgMsg01( DLv04, ( OutPut, "***** %s:ptEpbcInd->pvUnitAdr:%p\n"
								, D_PROC_NAME, ptEpbcInd->pvUnitAdr ));
				DbgMsg01( DLv04, ( OutPut, "***** %s:pvPbAdr:%p\n"
								, D_PROC_NAME, pvPbAdr ));

/*****  障害対応（TBCS0263）	Start									修正日：2003.08.06  *****/
/************************************************************************************************/
/*  ユニット使用状態のチェックを削除                                                            */
/************************************************************************************************/
												// ユニットアドレスをチェック
				if( ptEpbcInd->pvUnitAdr == pvPbAdr )
/*****  障害対応（TBCS0263）	End										修正日：2003.08.06  *****/
				{
					lOpFlg = D_NORMAL;
					break;
				}
			}

			lOpFlg = D_ERR;
			break;

		case D_CHK_MEM_RANGE2:					// 共有メモリ範囲チェック BP個別部指定用
			ptEbpcInd = ptEbpcIndPar;
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MEM_RANGE2\n" ));

			lRes = os_Chk_SetDat(&tBPdat,
								(long)(ptEbpcInd->pvEbpcAdr),	// 先頭アドレス設定
								0,								// 領域サイズ設定
								ptEbpcInd->lUnitSize + 4,		// ユニットサイズ設定
								ptEbpcInd->lMaxUnitNum );		// ユニット最大数設定

												// ユニットアドレスの先頭アドレス
			lUnit = (long)pvPbAdr - 4;

			lRes = os_Chk_Mem_Range( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
												//範囲外であればエラーを返す
				lOpFlg = D_ERR;
				break;
			}
												// ユニットアドレスチェックへ
			lOpFlg = D_CHK_MUCH_PBADR;

			break;

		/****************************************/
		/*  エラー処理                          */
		/****************************************/
		case D_ERR:
			DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc Err\n", D_PROC_NAME ) );
			return(OSEEIPOL);
			break;

		/****************************************/
		/*  正常処理                            */
		/****************************************/
		case D_NORMAL:
			DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc Normal\n", D_PROC_NAME ) );
			return(NORMAL);
			break;
		}
	}

}


/****************************************************************************/
/* 機能：アドレス範囲チェック                                               */
/*   long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)                */
/*     TAdrDat *ptAdrDat    アドレス情報構造体                              */
/*     long lUnitAdr        対象アドレス                                    */
/*                                                                          */
/****************************************************************************/
long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)
{
	// 最初に構造体の欠けている要素を残りのメンバから求める
	// 必須メンバは先頭アドレス それ以外は１だけ欠けても良い
	long lHead = 0;								// 先頭アドレス
	long lLast = 0;								// 終端アドレス
												// 先頭アドレス設定
	lHead = ptAdrDat->lTopAdr;
												// 終端アドレス設定
	lLast = lHead + ptAdrDat->lMemSize;
	
	DbgMsg01( DLv04, ( OutPut, "***** %s:TopAddress   :%p\n", D_PROC_NAME, lHead));
	DbgMsg01( DLv04, ( OutPut, "***** %s:TermAddress  :%p\n", D_PROC_NAME, lLast));
	DbgMsg01( DLv04, ( OutPut, "***** %s:TargetAddress:%p\n", D_PROC_NAME, lUnitAdr));
	
	if( (lHead <= lUnitAdr) && (lLast > lUnitAdr) )
	{
		return(NORMAL);
	}
	
	return(D_ERR_ADR);
}

/****************************************************************************/
/* 機能：アドレス正当性チェック                                             */
/*   long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)                */
/*     TAdrDat *ptAdrDat    アドレス情報構造体                              */
/*     long lUnitAdr        対象アドレス                                    */
/*                                                                          */
/****************************************************************************/
long os_Chk_Unit_Adr(TAdrDat *ptAdrDat, long lUnitAdr)
{
	long lTargtNum = 0;
	long lTargtAdr = 0;
	
	// A = (ユニットアドレス-先頭アドレス)/ユニットサイズ
	lTargtNum = (lUnitAdr - ptAdrDat->lTopAdr) / ptAdrDat->lUnitSize;

	// B = 先頭アドレス + (A * ユニットサイズ)
	lTargtAdr = ptAdrDat->lTopAdr + (lTargtNum * ptAdrDat->lUnitSize);
	
												// ピンポイント式で求めた結果と引数とを比較する
	DbgMsg01( DLv04, ( OutPut, "***** %s:予想アドレス:%p\n", D_PROC_NAME, lTargtAdr));
	DbgMsg01( DLv04, ( OutPut, "***** %s:対象アドレス:%p\n", D_PROC_NAME, lUnitAdr));
	if(lUnitAdr == lTargtAdr)
	{
		return(NORMAL);
	}
	return(D_ERR_ADR);
	
}

/****************************************************************************/
/* 機能：対象情報設定                                                       */
/*   long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr,                     */
/*                      long size, long unitsize, long maxnum)              */
/*     TAdrDat *ptAdrDat    アドレス情報構造体                              */
/*     long topadr          先頭アドレス                                    */
/*     long size            領域サイズ                                      */
/*     long unitsize        ユニットサイズ                                  */
/*     long maxnum          ユニット最大数                                  */
/*                                                                          */
/****************************************************************************/
long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr, long size, long unitsize, long maxnum)
{
	long lSize = 0;								// メモリサイズ
	long lUnit = 0;								// ユニットサイズ
	long lNum = 0;								// ユニット個数
	
	ptAdrDat->lTopAdr = topadr;					// 先頭アドレス設定
	ptAdrDat->lMemSize = size;					// 領域サイズ設定
	ptAdrDat->lUnitSize = unitsize;				// ユニットサイズ設定
	ptAdrDat->lMaxNum = maxnum;					// ユニット個数設定

	if(0 == ptAdrDat->lMemSize)
	{
		lSize = ptAdrDat->lUnitSize * ptAdrDat->lMaxNum;
		ptAdrDat->lMemSize = lSize;
	}
	else if(0 == ptAdrDat->lUnitSize)
	{
		lUnit = ptAdrDat->lMemSize / ptAdrDat->lMaxNum;
		ptAdrDat->lUnitSize = lUnit;
	}
	else if(0 == ptAdrDat->lMaxNum)
	{
		lNum = ptAdrDat->lMemSize / ptAdrDat->lUnitSize;
		ptAdrDat->lMaxNum = lNum;
	}

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lTopAdr   :%p\n"
			, D_PROC_NAME, ptAdrDat->lTopAdr) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lMemSize  :%ld\n"
			, D_PROC_NAME, ptAdrDat->lMemSize) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lUnitSize :%ld\n"
			, D_PROC_NAME, ptAdrDat->lUnitSize) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lMaxNum   :%ld\n"
			, D_PROC_NAME, ptAdrDat->lMaxNum) );

	
	return(NORMAL);

}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
