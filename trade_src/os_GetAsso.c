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
/* ��⥸�塼��ɣġ�				 os_GetAsso													*/
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
/* ������:��̣                                                               */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ������:2002ǯ10��3��                                                      */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ������mpid�����̤���,�ֵѤ���	                                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_GetAsso.h>																*/
/*																								*/
/*	   	long	os_GetAsso(long mpid)													        */
/*																								*/
/* �㲾������																					*/
/*		long      	mpid;		 		   0���ϥᥤ��ܥå������̻����ϥץ������μ��̻�		*/
/*													                                            */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ	mpid��0�ξ��			0													*/
/*					mpid��0�ʳ��ξ��		����										    	*/
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
#include "os_GetAsso_ins.h"
/*****************************************************************************/
/* ��ǽ:���̻Ҥ�����̤����                                                 */
/* ������:2002ǯ10��3��                                                      */
/* �ѹ���:                                                                   */
/* ������:��̣                                                               */
/* �ƽз���:                                                                 */
/*   long os_GetAsso( long id )                                              */
/*     long id                ���̻�                                         */
/*                                                                           */
/*****************************************************************************/
long os_GetAsso( long id )
{
//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_GETASSO ) );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_GETASSO ) );
	return( (id >> 16) & 0x000000ffL );	// ���̤��ֵѤ���
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
