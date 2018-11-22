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
/* ��⥸�塼��ɣġ�				 os_endSG													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼����:�أأأ�)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*      �ӣ�����ե�����ʶ�ͭ����ˤ�ǥ��å����롣                                          */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long    os_endSG()                                                                      */
/*																								*/
/* �㲾������																					*/
/*      �ʤ�                                                                                    */
/*																								*/
/* ���ֵ��͡�																					*/
/*		NORMAL	�����ｪλ                                                                      */
/*      -1		�������ƥॳ���륨�顼                                                          */
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
/*  ���󥯥롼�ɥե�����                                                                        */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include	<stdio.h>
#include	<stdlib.h>
#include 	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	<errno.h>


/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	"os_SG.h"
#include	"os_SG_ins.h"


/************************************ �����ѿ���� **********************************************/
extern	char	*pcCmptr;							/* �����å����벾�ۥ��ɥ쥹�ݥ��� 		*/
extern	long	lCmSize;							/* ��ͭ���ꥵ����							*/


long	os_endSG()
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long	lRet;									/* �ֵ���									*/


													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgSubFnc\n", "os_endSG" ) );

	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lRet = 0;
	errno = 0;


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/********************************/
	/*  ��ͭ����Υǥ��å�		*/
	/********************************/
	lRet = shmdt(pcCmptr);							/* ��ͭ����Υǥå���						*/
	if (-1 == lRet)
	{
		os_trcget2(D_MD_OS_ENDSG, D_T_SYS_SHMDT, 2, lRet, errno );
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
				"os_endSG", "shmdt() Call Error!!", errno, strerror(errno)));
		return(-1);									/* �۾ｪλ									*/
	}

	DbgMsg01(DLv05, (OutPut, "***** %s:shmdt() Call lRet=%08x \n", "os_endSG", lRet));


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End  DbgSubFnc\n", "os_endSG" ) );
	return (NORMAL);								/* ���ｪλ									*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/