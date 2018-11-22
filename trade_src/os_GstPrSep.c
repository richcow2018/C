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
/* �㥵���ӥ�����̾��				 ���̴ؿ�													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �أأأأأأ�												*/
/* ��⥸�塼��ɣġ�				 os_GstPrSep												*/
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
/*	 �ץ���������μ���																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_GstPrSep.h>																*/
/*																								*/
/*	   	long	os_GstPrSep(long type,long inf)													*/
/*																								*/
/* �㲾������																					*/
/*		long		type;		 		1.	�ץ��������̻�										*/
/*										2.	�ץ������ɣ�										*/
/*		long		inf;		 		type 1.	 �ץ��������̻�									*/
/*											 2.  �ץ������ɣ� 									*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�����ֹ�																*/
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
/*****************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "oscom_ins.h"

/*****************************************************************************/
/* ��ǽ���ץ���������μ��� ��                                               */
/* ��������2002ǯ9��27��                                                     */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�����                                                              */
/* �ƽз�����                                                                */
/*   long os_GstPrSep( long type , long inf )                                */
/*       long type �������������ץ��������̻�                                */
/*       �����������������������ץ������ɣġ�                                */
/*       long inf       tyep �����ץ��������̻�                              */
/*       ����������������  �������ץ����� �ɣġ�                             */
/*                                                                           */
/*****************************************************************************/
long os_GstPrSep( long type , long inf  )
{
	int i;					/* �롼�ץ����� */
	TEprcTableInd  *ptprcAdr;		
                              /* �ᥤ��ܥå��������ơ��֥�������Υ��ɥ쥹 */

DbgMsg01( DLv02, ( OutPut, "***** os_GstPrSep tyoe ID:%d inf :%d \n", type,inf));

/* ���������å� */
    if ((type != 1) && (type  != 2)) {
	        return(-1);               /*��type��������������������*/
    }
    ptprcAdr = (TEprcTableInd *)(ptEprc + 1 );                      
    if ((type == 1) && (inf ==0))
    {
        type =2;
    }
    if (type  == 1) {
            for( i=0;i<ptEprc->lIndPartNum;i++){
		if (ptprcAdr->lPCode == inf){
		    break;
		}
                ptprcAdr ++;
            } 
    }
    else {					/* �ץ������������� */
           for( i=0;i<ptEprc->lIndPartNum;i++){
		if (ptprcAdr->lPid == inf){
		    break;
        	}
                ptprcAdr ++;
            } 
    }
    if (i >= ptEprc->lIndPartNum) {
	 i= -1;
    }
DbgMsg01( DLv02, ( OutPut, "***** os_GstPrSep OUT :%d  \n", i));
    return(i);
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/