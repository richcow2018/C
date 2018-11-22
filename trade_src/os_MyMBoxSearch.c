/************************************************************************************************/
/*	���	��������																			*/
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
/* ��⥸�塼��ɣġ�				 os_MyMBoxSearch											*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼��:�أأأ�)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �أأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأ�						*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<XXXXX.h>																	*/
/*																								*/
/*	   	void	XXXXXXX(XXXXXXX, XXXXXXXX)														*/
/*																								*/
/* �㲾������																					*/
/*		XXXXXX		XXXXX;		 		<XXXXXXXXXX>											*/
/*		XXXXXX		XXXXX;		 		<XXXXXXXXXX>											*/
/*																								*/
/* ���ֵ��͡�																					*/
/*	   0L																						*/
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

/************************************************************************************************/
/*								���̥إå����ե�����                							*/
/*																								*/
/************************************************************************************************/
#include <string.h>
#include <stdio.h>
#include <errno.h>

/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include "os_debug.h"
#include "osexpcode.h"
#include "oscom_ins.h"

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� long os_MyMBoxSearch(long lPCode, TEmbcTableInd* ptEmbcInd)					  	*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� �ᥤ��ܥå������̻Ҥ������������å�                                          	*/
/* 				   - �ᥤ��ܥå��������ơ��֥�θ������������Ƭ���顢�ץ��������̻Ҥ�		    */
/*					�ץ������������ˤ���ץ��������̻Ҥȹ��פ�����ϰ��֡����Υᥤ��ܥå���  */
/*					�Υץ��������̻Ұ��֤��ֵѡ����ϸ��Ĥ���ʤ��ä����D_ERR_SYS���ֵ�  		*/
/*																								*/
/************************************************************************************************/
long os_MyMBoxSearch(long lPCode, TEmbcTableInd* ptEmbcInd)
{
	long lCntLp;							// �롼�ץ�����
	long lTmpMQID; 							// �ֵ��Ѥο���
	
	for(lCntLp = 0; lCntLp < ptEmbc->lIndPartNum ; lCntLp++)
	{
		if(lPCode == (ptEmbcInd + lCntLp)->lPCode)	// �ᥤ��ܥå����������Υץ��������̤�
		{											// �ץ������������ˤ���ץ��������̻Ҥȹ���
		
			lTmpMQID = lCntLp;                     // �ᥤ��ܥå��������ơ��֥�θ���
												   // ������ˤ���ץ��������̤ΰ��֤��ֵ�
			return(lTmpMQID);
		}
	}
	
	return(D_ERR_SYS);						// ���פ��ʤ����
}	
