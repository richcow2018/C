/*----------------------------------------------------------------------------------------------*/
/* ���оݶ�̳̾��                    �ξ������̳      ����         							*/
/* ���оݶ�̳�ɣġ�                  �ңã�                         							*/
/* �㥵���ӥ�����̾��                �ơ��֥�ꥫ�Х�          ��   							*/
/* �㥵���ӥ����ܣɣġ�              trcv	                   									*/
/* ��⥸�塼��̾��                  ����ifer													*/
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
/* ���߷�ǯ������                    ��������ǯ���������	         							*/
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
/*      ���Ѥ�����ե�����Υ����������顼����													*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                     							*/
/*		long 	long mr_ifer(int, char)															*/
/*                                                                  							*/
/* �㲾������                                                       							*/
/*		int	 	iFd;			�ե����� �ǥ�������ץ�  										*/
/*		char  	cSysCall;		�����ƥॳ����̾�Υ����å�;										*/
/*		  																						*/
/*              	                                                							*/
/* ���ֵ��͡�                                                       							*/
/*         0 :                  	                                							*/
/*		SYSERROR(-1)	�۾�																	*/
/*		MRNORMAL(0)		����																	*/
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
/* file utility */
long mr_intg(long);
long mr_writ(int, char*, long);
long mr_read(int, char*, long);
void mr_clop(char*, char);


/* ���Ѥ����֥ե����륨�顼���� */
long mr_sfer(int, char);


/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
long mo_date(long*, long*);
long ms_wtop(long, short, char, char, long, long);     


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_ifer(int, char cSysCall)												*/
/*																								*/
/*	�㵡ǽ���ס�  ���Ѥ�����ե�����Υ����������顼											*/
/*  																							*/
/*	�꥿����:																					*/
/*			����(SYSERROR)																		*/
/*			����(MRNORMAL)																		*/
/************************************************************************************************/
long mr_ifer(int iFd, char cSysCall)
{

	int iFp = -1;													/* file descriptor			*/
	
	long lDate = 0;													/* ���դ��ѿ�				*/ 
	
	long lTime = 0;													/* ������ѿ�				*/
	
	long lRet = 0;													/* �ֵ���					*/
	
	char cMsg[MSSGSIZE] = "\0";										/* ��å�������Ǽ��			*/

	char cErrStatus = TRCVFERR;										/* �ե�����ξ���			*/
	
	char cSysName[SCALLSIZ];										/* �����ƥॳ����̾��Ǽ��	*/
	
	char newname[TRCVFIZI + 16];									/* �������ե�����̾			*/
	
	extern  TRCV *mrtrcv;										    /* ����TRCV���ΰ�			*/
	

	PRINTF("(0) mr_ifer - errno = %ld\n", errno);						

	PRINTF("(0.1) mr_ifer - errno name = %s\n", strerror(errno));						

	mr_clop(cSysName , cSysCall);
	
	sprintf(cMsg, "%.4s\t%s\t%d", MRMSRR1, cSysName, errno);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if(iFd >= 0)
	{
		close(iFd);
	}

	PRINTF("(1) mr_ifer - iFd = %ld\n", iFd);						
	
	lRet = mo_date(&lDate, &lTime);									/* ���ߤ����ջ�������		*/
	
	lTime &= 0x00FFFFFF; 									        /* hhmmss�������ѹ�����		*/
	
	sprintf(newname, "%s_%8x%6x", mrtrcv->trcvjpnm, lDate, lTime);	/* ���ߤ����ջ�����Խ�����	*/
	
	PRINTF("(2) mr_ifer - newname = %s\n", newname);						
	
	rename(mrtrcv->trcvjpnm, newname);								/* �ե�������͡��ह��	*/

	iFp = open(mrtrcv->trcvspnm, O_SYNC | O_WRONLY);				/* �ե�����򥪡��ץ󤹤�	*/

	PRINTF("(3) mr_ifer - iFd = %ld\n", iFd);						

	if(iFp >= 0)
	{
		lRet = lseek(iFp, 8, SEEK_SET);								/* �ξ���֤ΰ��֤˰ܤ�		*/
		
		PRINTF("(4) mr_ifer - lRet = %ld\n", lRet);						
		
		cErrStatus = TRCVFERR;
		
		PRINTF("(4.1) mr_ifer - cErrStatus = %c\n", cErrStatus);						
		
		lRet = mr_writ(iFp, &cErrStatus, STATSIZE);					/* �ξ���֤򹹿�����		*/

		PRINTF("(5) mr_ifer - lRet = %ld\n", lRet);						
		
		if(iFp >= 0)
		{
			close(iFp);												/* �ե�����򥯥�����		*/
		}
	}
	else
	{
		lRet = SYSERROR;
	}	

	PRINTF("(6) mr_ifer - lRet = %ld\n", lRet);						
	
	return(lRet);													/* ��λ����					*/
		
}

