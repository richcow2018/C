/************************************************************************************************/
/*	���	��������							                               					*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 �ץ���������												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ץ���������μ���											*/
/* ��⥸�塼��ɣġ�				 osgtpin													*/
/* ��⥸�塼�����֡�																			*/
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��					 ���ѥ�����													*/
/* ��Ŭ�ѣϣӡ� 					 �̣����� 												*/
/* �㳫ȯ�Ķ��� 					 �ңȣ��ӣ�����												*/
/* �㵭�Ҹ���� 					 �ø��� 													*/
/* ��⥸�塼����֡�				 �ؿ�														*/
/* �㵡ǽ��ʬ�� 																				*/
/* ���оݥǡ�����																				*/
/* �㹩�������ض�ʬ��																			*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��				 �̣��̣�ݣӣͣХ����ƥ�									*/
/* �㳫ȯ�����ƥ��ֹ�� 			 �УУ����£�����������										*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)			    	*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô��										*/
/* ���߷�ǯ������					 ��������ǯ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)						*/
/* �����ԡ�����                                                              */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ9��30��                                                     */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 	�ץ���������μ���																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osgtpin.h>																	*/
/*																								*/
/*	   	long		osgtpin( long pid, long *infp)												*/
/*																								*/
/* �㲾������																					*/
/*		long		pid;		�ץ��������̻�													*/
/*		oseprinf	*infp;		�ץ����������Ǽ��												*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			NORMAL																*/
/*		�۾ｪλ			OSEEIPID				pid������									*/
/*							OSEENEXS				�ץ�������¸�ߤ���							*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   �äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "osgtpin.h"
#include "osgtpin_ins.h"				/* ���������� */

/*****************************************************************************/
/* ��ǽ���ץ���������μ��� ��                                               */
/* ��������2002ǯ9��27��                                                     */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�����                                                              */
/* �ƽз�����                                                                */
/*   long osgtpin( long pid , long *infp )                                   */
/*       long pid ���������ץ��������̻� ����                                */
/*       oseprinf *infp ���ץ����������Ǽ�衡  ���������������������������� */
/*                                                                           */
/*****************************************************************************/
long osgtpin( long pid , oseprinf *infp  )
{
	int iRet;					/* �ؿ�����ֵ� */
	TEprcTableInd  *ptprcAdr;		
                              /* �ᥤ��ܥå��������ơ��֥�������Υ��ɥ쥹 */
                              
	os_trcget2( D_MD_OSGTPIN, D_T_TRA_IN, 2, pid, infp);                          

//   DbgMsg01( DLv02, ( OutPut, "***** gtpin ENT %d\n",pid ) );

   ptprcAdr = (TEprcTableInd *)(ptEprc + 1 );
   DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );

	/* ���������å� */
   if (((pid & 0x00ff0000) != 0x00010000) 
                     && (pid  != 0x00000000)) {
                DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEEIPID \n" ) );
           
           	os_trcget2( D_MD_OSGTPIN, D_T_ERR_PRA, 1, OSEEIPID);        
                
	        return(OSEEIPID);               /*��pid��������������������*/
    }
   if (infp == NULL) { 
                DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEEIPID \n" ) );
                
           	os_trcget2( D_MD_OSGTPIN, D_T_ERR_PRA, 1, OSEEIPID);  
                
	        return(OSEEIPID);               /*��pid��������������������*/
    }
	/* �ץ������������ */
    if (pid  != 0x00000000) {
            iRet = os_GstPrSep(1,pid & 0x00ffffff);
					/* �ץ����������ơ��֥븡�����������ץ��������̻�   */
	    ptprcAdr +=  iRet;
            if (ptprcAdr->lPid == 0x0) {
                        DbgMsg01( DLv02, ( OutPut, "***** gtpin OSEENEXS \n" ) );
                        
                   	os_trcget2( D_MD_OSGTPIN, D_T_ERR_SYS, 1, OSEENEXS); 
                        
        	        return(OSEENEXS);       /*���ץ�����¸�ߤ���������*/
            } 
    }
    else {					/* ���ץ��������󡡡����� */
//      iRet = getpid();
        iRet = os_GstPrSep(2,ptEsys->tMyPrcInfo.lMyPid);
						/* �ץ����������ơ��֥븡�����������ץ�����ID */
        DbgMsg01( DLv02, ( OutPut, "***** gtpin getpidE%d\n",iRet ) );
		ptprcAdr += iRet;
    }
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lPCode =%08x\n", ptprcAdr->lPCode ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->acPName=%s\n", ptprcAdr->acPName ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lPAttr =%08x\n", ptprcAdr->lPAttr ) );
    DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr->lAccess=%08x\n", ptprcAdr->lAccess ) );

    infp->pid = ptprcAdr->lPCode;		        /*���ץ��������̻�*/
//    strcpy(infp->pname,ptprcAdr->acPName);	// 20021218 ����
	strncpy(infp->pname,ptprcAdr->acPName, 8);
               				        /*���ץ�����̾*/
    infp->hpri = ptprcAdr->lModifPriority;	       /*���ѹ���ǽ�ǹ�ͥ����*/
    infp->atr = ptprcAdr->lPAttr;		        /*���ץ�����°��*/
    infp->access = ptprcAdr->lAccess;	        /*������������*/
    DbgMsg01( DLv02, ( OutPut, "***** gtpin infp %d\n",infp->pid ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin pname %s\n",infp->pname ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin hpri %d\n",infp->hpri ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin atr %d\n",infp->atr ) );
    DbgMsg01( DLv02, ( OutPut, "***** gtpin access %d\n",infp->access ) );

//    iRet = getppid();
	iRet = os_GstPrSep(1,0x00010001);
//	iRet = os_GstPrSep(2,getppid() );
						/* �ץ����������ơ��֥븡�����������ץ�����ID */
//	ptprcAdr = (TEprcTableInd *)ptEprc + 1 ;
	ptprcAdr = (TEprcTableInd *)(ptEprc + 1);
	DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );
	ptprcAdr += iRet;
	DbgMsg01( DLv04, ( OutPut, "***** gtpin ptprcAdr=%08x \n", ptprcAdr ) );

    infp->ppid = ptprcAdr->lPCode;		        /*���ƥץ��������̻�*/
//    DbgMsg01( DLv02, ( OutPut, "***** gtpin ppid %d\n",infp->ppid ) );

	os_trcget2( D_MD_OSGTPIN, D_T_TRA_OUT, 1, NORMAL); 

    return(NORMAL);
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/