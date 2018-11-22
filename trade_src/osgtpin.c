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
/* ＜サービス項目名＞				 プロセス制御												*/
/* ＜サービス項目ＩＤ＞ 			 ＸＸＸＸＸＸＸ												*/
/* ＜モジュール名＞					 プロセス情報の取得											*/
/* ＜モジュールＩＤ＞				 osgtpin													*/
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
/* 作成者：高瀬                                                              */
/* ＜ソース作成年月日＞ 			 ２００２年　９月２７日 									*/
/* 作成日：2002年9月30日                                                     */
/* ＜ソース修正者＞ 			 	 															*/
/* ＜ソース正年月日及び修正ＩＤ＞    															*/
/*----------------------------------------------------------------------------------------------*/
/* ＜見積ステップ数＞				 ステップ													*/
/*----------------------------------------------------------------------------------------------*/
/* ＜機能概要＞ 																				*/
/*	 	プロセス情報の取得																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ＜呼出形式＞ 																				*/
/*		#include	<osgtpin.h>																	*/
/*																								*/
/*	   	long		osgtpin( long pid, long *infp)												*/
/*																								*/
/* ＜仮引数＞																					*/
/*		long		pid;		プロセス識別子													*/
/*		oseprinf	*infp;		プロセス情報格納域												*/
/*																								*/
/* ＜返却値＞																					*/
/*		正常終了			NORMAL																*/
/*		異常終了			OSEEIPID				pidが不当									*/
/*							OSEENEXS				プロセスが存在せず							*/
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
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "osgtpin.h"
#include "osgtpin_ins.h"				/* 内部参照用 */

/*****************************************************************************/
/* 機能：プロセス情報の取得 　                                               */
/* 作成日：2002年9月27日                                                     */
/* 変更日：　　年　月　日                                                    */
/* 作成者：高瀬                                                              */
/* 呼出形式：                                                                */
/*   long osgtpin( long pid , long *infp )                                   */
/*       long pid 　　　　プロセス識別子 　　                                */
/*       oseprinf *infp 　プロセス情報格納域　  　　　　　　　　　　　　　　 */
/*                                                                           */
/*****************************************************************************/
long osgtpin( long pid , oseprinf *infp  )
{
	int iRet;					/* 関数結果返却 */
	TEprcTableInd  *ptprcAdr;		
                              /* メイルボックス管理テーブル個別部のアドレス */
                              
	os_trcget2( D_MD_OSGTPIN, D_T_TRA_IN, 2, pid, infp);                          

//   DbgMsg01( DLv02, ( OutPut, "***** gtpin ENT %d\n",pid ) );

   ptprcAdr = (TEprcTableInd *)(ptEprc + 1 );
   DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );

	/* 引数チェック */
   if (((pid & 0x00ff0000) != 0x00010000) 
                     && (pid  != 0x00000000)) {
                DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEEIPID \n" ) );
           
           	os_trcget2( D_MD_OSGTPIN, D_T_ERR_PRA, 1, OSEEIPID);        
                
	        return(OSEEIPID);               /*　pidが不当　　　　　　　*/
    }
   if (infp == NULL) { 
                DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEEIPID \n" ) );
                
           	os_trcget2( D_MD_OSGTPIN, D_T_ERR_PRA, 1, OSEEIPID);  
                
	        return(OSEEIPID);               /*　pidが不当　　　　　　　*/
    }
	/* プロセス情報取得 */
    if (pid  != 0x00000000) {
            iRet = os_GstPrSep(1,pid & 0x00ffffff);
					/* プロセス管理テーブル検索　キー：プロセス識別子   */
	    ptprcAdr +=  iRet;
            if (ptprcAdr->lPid == 0x0) {
                        DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEENEXS \n" ) );
                        
                   	os_trcget2( D_MD_OSGTPIN, D_T_ERR_SYS, 1, OSEENEXS); 
                        
        	        return(OSEENEXS);       /*　プロセス存在せず　　　*/
            } 
    }
    else {					/* 自プロセス情報　　　　 */
//      iRet = getpid();
        iRet = os_GstPrSep(2,ptEsys->tMyPrcInfo.lMyPid);
						/* プロセス管理テーブル検索　キー：プロセスID */
        DbgMsg01( DLv02, ( OutPut, "***** gtpin getpidE%d\n",iRet ) );
		ptprcAdr += iRet;
    }
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lPCode =%08x\n", ptprcAdr->lPCode ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->acPName=%s\n", ptprcAdr->acPName ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lPAttr =%08x\n", ptprcAdr->lPAttr ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lAccess=%08x\n", ptprcAdr->lAccess ) );

    infp->pid = ptprcAdr->lPCode;		        /*　プロセス識別子*/
//    strcpy(infp->pname,ptprcAdr->acPName);	// 20021218 修正
	strncpy(infp->pname,ptprcAdr->acPName, 8);
               				        /*　プロセス名*/
    infp->hpri = ptprcAdr->lModifPriority;	       /*　変更可能最高優先度*/
    infp->atr = ptprcAdr->lPAttr;		        /*　プロセス属性*/
    infp->access = ptprcAdr->lAccess;	        /*　アクセス権*/
    DbgMsg01( DLv02, ( OutPut, "***** gtpin infp %d\n",infp->pid ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin pname %s\n",infp->pname ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin hpri %d\n",infp->hpri ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin atr %d\n",infp->atr ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin access %d\n",infp->access ) );

//    iRet = getppid();
	iRet = os_GstPrSep(1,0x00010001);
//	iRet = os_GstPrSep(2,getppid() );
						/* プロセス管理テーブル検索　キー：プロセスID */
//	ptprcAdr = (TEprcTableInd *)ptEprc + 1 ;
	ptprcAdr = (TEprcTableInd *)(ptEprc + 1);
	DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );
	ptprcAdr += iRet;
	DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );

    infp->ppid = ptprcAdr->lPCode;		        /*　親プロセス識別子*/
//    DbgMsg01( DLv02, ( OutPut, "***** gtpin ppid %d\n",infp->ppid ) );

	os_trcget2( D_MD_OSGTPIN, D_T_TRA_OUT, 1, NORMAL); 

    return(NORMAL);
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
