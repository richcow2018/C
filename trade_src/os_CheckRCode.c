/****************************************************************************/
/* 信金システム  システムコール                                             */
/* 機能：リクエスト識別子チェック                                           */
/* 作成日:2002年11月14日                                                    */
/* 変更日:                                                                  */
/* 作成者:                                                                  */
/*                                                                          */
/****************************************************************************/
/******************************** 標準ヘッダ・ファイル **********************/

/***************************** 利用者作成ヘッダ・ファイル *******************/
#include "os_CheckRCode_ins.h"
#include "os_ERDC_ins.h"

/****************************************************************************/
/* 機能:リクエスト識別子チェック                                            */
/* 作成日:2002年11月14日                                                    */
/* 変更日:2003年02月19日                                                    */
/* 作成者:                                                                  */
/* 呼出形式:                                                                */
/*   long os_CheckRCode( long rd )                                          */
/*     long rd              リクエスト識別子                                */
/*                                                                          */
/* ＜返却値＞                                                               */
/*     リクエスト識別子                                                     */
/*                                                                          */
/****************************************************************************/
long os_CheckRCode( long rd )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    TErdcTable *ptTErdcTable = ptErdc;   // rd管理テーブル先頭アドレス
    TErdcTableInd *ptTErdcTableInd = ( void * )ptErdc + sizeof( TErdcTable );
                                        // rd管理テーブル個別部アドレス取得

    int  iIdx;                          // ループのIndex
    long lRCode;                        // 対象リクエスト識別子

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/

    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", 
                                      D_PROC_CHECKLRCODE ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s:psrm rd:%lx\n", 
                                      D_PROC_CHECKLRCODE, rd ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s:ptMyEPRC->lMaxReqNum:%08lx\n", 
                                      D_PROC_CHECKLRCODE, ptMyEPRC->lMaxReqNum ) );

                                        //--- リクエスト識別子チェック ---
    if( rd == D_RD_MIN )                // リクエスト識別子＝０の場合
    {
        //for( iIdx = 0; iIdx < ptTErdcTable->lMaxIndNum; iIdx++ )
        for( iIdx = 0; iIdx < ptMyEPRC->lMaxReqNum; iIdx++ )
        {
                                        // ｒｄ管理テーブル個別部の「予約状態」が
                                        // 「未予約」である個別部を検索
//          if( ptTErdcTableInd[iIdx].tReqStat.cResStat == D_RESSTAT_NO )
													// リクエスト状態が
													// 未予約かつ未使用かつ未要求の場合
			if( D_ERDC_RESSTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cUCompStat )
            {
                lRCode = iIdx;
				DbgMsg01( DLv04, ( OutPut, "***** %s:lRCode:%08lx\n",
						D_PROC_CHECKLRCODE, lRCode ) );
                break;
            }
            DbgMsg01( DLv04, ( OutPut, "***** %s:iIdx:%03dx\n",
						D_PROC_CHECKLRCODE, iIdx ) );
        }
                                        // 「予約未」の個別部が存在しない場合
        //if( iIdx == ptTErdcTable->lMaxIndNum )
        if( iIdx == ptMyEPRC->lMaxReqNum )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEOVRQ ) );
            return( OSEEOVRQ );
        }
    }
                                        // リクエスト識別子:１〜個別部数の場合
    //else if( (rd > D_RD_MIN) && (rd <= ptTErdcTable->lMaxIndNum) )
    else if( (rd > D_RD_MIN) && (rd <= ptMyEPRC->lMaxReqNum) )
    {
                                        // ｒｄ管理テーブル個別部の「予約状態」が
                                        // 「未予約」の場合
        if( D_ERDC_RESSTAT_NONE == ptTErdcTableInd[ rd - 1 ].tReqStat.cResStat )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEIVRD ) );
            return( OSEEIVRD );
        }
                                        // ｒｄ管理テーブル個別部の「非完了要求状態」が
                                        // 「要求済」の場合
        if( D_ERDC_UCOMPSTAT_REQ == ptTErdcTableInd[ rd - 1 ].tReqStat.cUCompStat )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEUSED ) );
            return( OSEEUSED );
        }
        lRCode = rd - 1;                // 「指定リクエスト識別子」を対象とする
    }
    else                                // リクエスト識別子＜０の場合
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEIVRD ) );
        return( OSEEIVRD );
    }
	lRCode++;
	
	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc:%08lx\n",
					D_PROC_CHECKLRCODE, lRCode ) );
    return( lRCode );                   // 対象リクエスト識別子
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

