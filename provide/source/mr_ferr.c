/*----------------------------------------------------------------------------------------------*/
/* ���оݶ�̳̾��                    �ξ������̳      ����         							*/
/* ���оݶ�̳�ɣġ�                  �ңã�                         							*/
/* �㥵���ӥ�����̾��                �ơ��֥�ꥫ�Х�          ��   							*/
/* �㥵���ӥ����ܣɣġ�              trcv                    									*/
/* ��⥸�塼��̾��                  ����ferr													*/
/* ��⥸�塼��ɣġ�                �أأأأأأأ�               							*/
/* ��⥸�塼�����֡�                                               							*/
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ����                      ���ã�                         							*/
/* ��Ŭ�ѣϣӡ�                      �̣ɣΣգ�                     							*/
/* �㳫ȯ�Ķ���                      �̣ɣΣգ�                     							*/
/* �㵭�Ҹ����                      �ø���                         							*/
/* ��⥸�塼����֡�                ���ޥ��                       							*/
/* �㵡ǽ��ʬ��                                                     							*/
/* ���оݥǡ�����                                                   							*/
/* �㹩�������ض�ʬ��                                               							*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��                ���ãšݣӣͣХ����ƥ�         							*/
/* �㳫ȯ�����ƥ��ֹ��              �أأأأأأأأأأأ�       							*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô����̾��                  �ӣ������                   							*/
/* �������ֹ��                                         							*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�䡡���������������������ӣ������                   							*/
/* ���߷�ǯ������                    ��������ǯ���������	        							*/
/* ���߷׽�����̾��                  ��                             							*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                  							    */
/*----------------------------------------------------------------------------------------------*/
/* �㥽����������̾��                �ӣ������                   							*/
/* �㥽��������ǯ������              ��������ǯ���������	         							*/
/* �㥽����������̾��                                               							*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�                                 							*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���                ���ƥå�                       							*/
/*---------------------------------------------------------------------------------------------	*/
/* �㵡ǽ���ס�                                                     							*/
/*                                                                  							*/
/*      ���Ѥ�����ե����륢���������顼���������												*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                     							*/
/*			void mr_ferr(int, char);															*/
/*																								*/                                                              
/* �㲾������                                                       							*/
/*		int	 	iFd;			�ե����� �ǥ�������ץ�  										*/
/*		char  	cSysCall;		�����ƥॳ����̾�Υ����å�;										*/
/*		  																						*/
/*              	                                                							*/
/* ���ֵ��͡�                                                       							*/
/*         �ʤ�		                                                							*/
/*----------------------------------------------------------------------------------------------*/
/* �����»����         �ʤ�                                        							*/
/*                                                                  							*/
/* ����ѳ����⥸�塼��ɣġ�                                      	                            */
/* ��ƽХ⥸�塼��ɣġ�                                           							*/
/*                                                                  							*/
/************************************************************************************************/
/************************************************************************************************/
/*								���̥إå����ե�����                							*/
/*																								*/
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h> 


/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include    "mr.h"
#include 	"trcv.h"
#include	"mrmsg.h"
#include	"mcdebug.h"


/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
/* ���Ѥ����֥ե����륨�顼���� */
long mr_sfer(int, char);

/* ���Ѥ�����ե����륨�顼���� */
void mr_ferr(int, char);
long mr_ifer(int, char);


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	void mr_ferr(int iFd, char cSysCall)											*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե����륨�顼����													*/
/*  																							*/
/*	�꥿����:																					*/
/*		�ʤ�																					*/
/************************************************************************************************/
void mr_ferr(int iFd, char cSysCall)
{
	
	long lRet = MRNORMAL;									/* �ֵ���							*/
	
	extern TRCV *mrtrcv;									/* �ꥫ�Х�ơ��֥����				*/
	
	PRINTF("(1) mr_ferr - iFd = %ld\n", iFd);
	
	lRet = mr_ifer(iFd, cSysCall);							/* ���Ѥ�����ե����륨�顼����		*/ 
	
	PRINTF("(2) mr_ferr - lRet = %ld\n", lRet);

	
	if(lRet != MRNORMAL)									/* ���顼�ξ��						*/
	{														
	
		PRINTF("(3) mr_ferr - lRet = %ld\n", lRet);
	
		lRet = mr_sfer(SYSERROR, cSysCall);					/* ���Ѥ����֥ե����륨�顼����		*/
		
		PRINTF("(4) mr_ferr - lRet = %ld\n", lRet);

		
		mrtrcv->trcvsfst = TRCVFERR;						/* ���Ѥ����֥ե����뤬�ξ���		*/
		
		PRINTF("(4.1) mr_ferr - mrtrcv->trcvsfst = %c\n",	mrtrcv->trcvsfst);
		
	}

	mrtrcv->trcvjfst = TRCVFERR;							/* ���Ѥ�����ե����뤬�ξ���		*/

	PRINTF("(5) mr_ferr EXIT - mrtrcv->trcvjfst = %c\n",	mrtrcv->trcvjfst);
	
	return;
	
}

