/*----------------------------------------------------------------------------------------------*/
/* ���оݶ�̳̾��                    �ξ������̳      ����         							*/
/* ���оݶ�̳�ɣġ�                  �ңã�                         							*/
/* �㥵���ӥ�����̾��                �ơ��֥�ꥫ�Х�          ��   							*/
/* �㥵���ӥ����ܣɣġ�              trcv	                 									*/
/* ��⥸�塼��̾��                  ��򡲣أأأ�												*/
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
/*                                                                  							*/
/* �㵡ǽ���ס� ���Ѥ�����ե����뤫��Υơ��֥���������										*/
/*																								*/
/*	������� 																					*/
/*				 �ʤ�																			*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                     							*/
/*			long 	mr_trcv()																	*/
/*                                                                  							*/
/* �㲾������                                                       							*/
/*		  																						*/
/*              �ʤ�                                                							*/
/* ���ֵ��͡�                                                       							*/
/*		MRNORMAL��	���ｪλ																	*/
/*																								*/
/*		MRIVPARM��	�ѥ�᡼�� ���顼															*/
/*																								*/
/*		MRNORMX	��	��������ｪλ																*/
/*																								*/
/*		MRMBUFERR:  �Хåե���������															*/
/*																								*/
/*		SYSERROR:   FIP�ե����������票�顼														*/
/*																								*/
/*		MRFILERR:   �ե����륢���������顼														*/
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
#include <string.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <netinet/in.h>


/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include    "tcom.h"
#include    "psect.h"
#include    "mr.h"
#include    "tsst.h"	
#include    "tpct.h"	
#include    "mrmac.h"   
#include 	"trcv.h"	
#include    "mrcom.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "mrmirr.h"
#include    "mrcode.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mopcb.h"
#include	"mcdebug.h"
#include	"mrmsg.h"


/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
/* file utility */
long mr_intg(long);
long mr_writ(int, char*, long);
long mr_read(int, char*, long);

/* �Ƴ��Ͻ��� */
long mr_rest();
void mr_kaih();
long mr_recv();
void mr_frce();

/* ���Ѥ����֥ե����륨�顼���� */
long mr_sfer(int, char);

/* ���Ѥ�����ե����륨�顼���� */
void mr_ferr(int, char);
long mr_ifer(int, char);

/* ���Ͻ��� */
long mr_stpr();
long mr_inff();												
long mr_sttf();

/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
char syscom_get_bootmode();
long mf_srcv();
long mo_gtbf(long, long, long**);
long mo_frbf(long*);
long mo_date(long*, long*);
long ms_wtop(long, short, char, char, long, long);     
TCOMPAT *mo_tagt(unsigned char*);

/************************************************************************************************/
/*		���Ѥ�����¤��							 											*/	
/************************************************************************************************/
typedef struct {
	char msg1[4];
	long offset;
	long size;
	char msg2[4];
	long num;
} TRCVDATA;

/************************************************************************************************/
/*		���Ѥ����ֹ�¤��							 							                */	
/************************************************************************************************/
typedef struct {
	long lNowaDay;
	long lNowaTime;
	char cStatus;
	char pcYobi[3];
} TRCVINFODATA;

TRCV 	*mrtrcv;

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	 long mr_trcv()																	*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե����뤫��Υơ��֥���������										*/
/*																								*/
/*	������� 																					*/
/*				 �ʤ�																			*/
/*  																							*/	
/*																								*/
/*  ���ֵ��͡�																					*/
/*																								*/
/*		MRNORMAL��	���ｪλ�ʡ�																*/
/*																								*/
/*		MRIVPARM��	�ѥ�᡼�� ���顼															*/
/*																								*/
/*		MRNORMX	��	��������ｪλ																*/
/*																								*/
/*		MRMBUFERR:  �Хåե���������															*/
/*																								*/
/*		SYSERROR:   FIP�ե����������票�顼														*/
/*																								*/
/*		MRFILERR:   �ե����륢���������顼														*/
/*																								*/
/************************************************************************************************/
long mr_trcv()
{

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRet = MRNORMAL;									/* �ֵ���							*/
	
	/********************************************************************************************/
	/*  �����ѿ��ΰ�                                                                            */
	/********************************************************************************************/
	TCOMPAT *tcomrcv;
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB �ܥ���         		*/
	extern TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/
	long tsubrcv ;											/* TRCV���ֶ�����������				*/
		
    /********************************************************************************************/
    /*  ȯ�Ծ������å��ʣӣͣб�ž�⡼�ɤΥ����å���                   						*/
    /********************************************************************************************/
    
   	tcomrcv = mo_tagt("TRCV");								/* TRCV����Ƭ����					*/
	tsubrcv = tcomrcv->tcomsbps ;							/* ���ֶ���������������				*/

	if(tcomrcv == 0)
	{

		lRet = MRNORMX;
		
		PRINTF("(0) mr_trcv - motagt  = %ld\n", lRet);
		
		goto exit_to_main;
	}

	mrtrcv = (TRCV*)((char*)tcomrcv + sizeof(TCOMPAT) + tsubrcv);
		
	PRINTF("(0.0) mr_trcv - mrtrcv  = %08x\n", tcomrcv);
	PRINTF("(0.1) mr_trcv - mrtrcv  = %08x\n", mrtrcv);
	PRINTF("(0.2) mr_trcv - sizeof(TCOMPAT)  = %ld\n", sizeof(TCOMPAT));
	PRINTF("(0.3) mr_trcv - tcomrcv->tcomsbps  = %08x\n", tcomrcv->tcomsbps);
	PRINTF("(0.4) mr_trcv - tcomrcv->tcomsbps  = %.20s\n", tcomrcv->tcomsbps);
/*	
	mrtrcv = (void*)(tcomrcv + 136);

	PRINTF("(0.5) mr_trcv - mrtrcv  = %08x\n", mrtrcv);
	
	PRINTF("(0.6) mr_trcv - mrtrcv  = %.20s\n", mrtrcv);

	PRINTF("(0.7) mr_trcv - tcomrcv->tcomsbps = %08x\n", tcomrcv->tcomsbps);

	PRINTF("(0.8) mr_trcv - mrtrcv = %08x\n", mrtrcv);
	
	mrtrcv = (tcomrcv + sizeof(TCOMPAT));

	PRINTF("(0.9) mr_trcv - mrtrcv  = %08x\n", mrtrcv);

	PRINTF("(0.10) mr_trcv - mrtrcv  = %.20s\n", mrtrcv);
	
	mrtrcv+=sizeof(mrtrcv);

	PRINTF("(0.9) mr_trcv - mrtrcv  = %08x\n", mrtrcv);

	PRINTF("(0.10) mr_trcv - mrtrcv  = %.20s\n", mrtrcv);

*/	


    if( ( (mopcbp->mopssstp->tsstprmd[0] & 0x0000000FL) != 0x00000000L) )
    { 	    	            								/* �ץ����⡼�ɤ�   			*/
     														/* ����饤��⡼�ɤ��ʤ���			*/
    	lRet = MRNORMX; 			                  		/* �꡼���󤹤�                     */
    
    	goto exit_to_main;
    } 

	PRINTF("(1) mr_trcv - tcsttrcv = %c\n", mopcbp->mopscstp->tcsttrcv);

    /********************************************************************************************/
    /*  ȯ�Ծ������å��ʥꥫ�Х���/���ץ����å���		  					                    */
    /********************************************************************************************/
  
    if(mopcbp->mopscstp->tcsttrcv != TCSTTRNE)
    {                                    					/* �ꥫ�Х���/���׾���            */
                                     						/* �ꥫ�Х����פλ� 	            */
        				                					/* �꡼���󤹤�  					*/
        lRet = MRNORMX;
    
    	goto exit_to_main;
    }                     				
    
    /********************************************************************************************/
    /*  ���϶�ʬ�����å�							  					                        */
    /********************************************************************************************/
 
    
	PRINTF("(2) mr_trcv - tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);

    if(mopcbp->mopssstp->tsststd0 == KAISHIKU)				/* ���϶�ʬ��'N'�ξ��			    */
    {
		PRINTF("(3.0) mr_trcv - filename = %.127s\n", mrtrcv->trcvjpnm);
		PRINTF("(3.1) mr_trcv - filename = %s\n", mrtrcv->trcvjpnm);
		PRINTF("(3.2) mr_trcv - filename = %.127s\n", mrtrcv->trcvspnm);
		PRINTF("(3.3) mr_trcv - filename = %s\n", mrtrcv->trcvspnm);
		PRINTF("(3.4) mr_trcv - filename = %c\n", mrtrcv->trcvjfst);
		PRINTF("(3.5) mr_trcv - filename = %c\n", mrtrcv->trcvsfst);
		
		lRet = mr_stpr();									/* ���Ѥ�����ե�������������		*/
		
		PRINTF("(3) mr_trcv - lRet = %ld\n", lRet);
		
	} 
	else													/* ���϶�ʬ��'R'�ξ��			    */
	{
		lRet = mr_rest();									/* ���Ѥ�����ե�����ξ����		*/
															/* �Υ����å�						*/
		
		PRINTF("(4) mr_trcv - lRet = %ld\n", lRet);
		
		if(lRet != MRNORMAL)
		{
			PRINTF("(5) mr_trcv - lRet = %ld\n", lRet);		

			if(lRet == MRNORMX)								/* �ե����륢���������顼�ξ��		*/
			{
				lRet = mr_stpr();							/* ���Ͻ���							*/

				PRINTF("(6) mr_trcv - lRet = %ld\n", lRet);		
			}	
					
			goto exit_to_main;								/* ��λ����							*/
		}

		PRINTF("(7) mr_trcv - lRet = %ld\n", lRet);			
		
		lRet = mr_recv();									/* �ơ��֥���������					*/

	}	
		
 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/
exit_to_main:

	PRINTF("(8) mr_trcv - EXIT lRet = %ld\n", lRet);			
	
	return(lRet);
   
}    	


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_rest()																	*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե�����ξ���֤Υ����å�											*/
/*  																							*/
/*	�꥿����:																					*/
/*		MRFILERR(��Ÿξ�)																		*/
/*		MRNORMAL(����)																			*/
/*		MRNORMX(�ե����륢���������顼)															*/
/************************************************************************************************/
long mr_rest()
{
	
	int iFd = -1;											/* file descriptor					*/
	
	long lRet = 0;											/* �ؿ����ֵ���						*/
	
	char cMsg[MSSGSIZE] = "\0";								/* ��å�������Ǽ��					*/
	
	char cSysCall = '0';									/* �����ƥॳ����option				*/
	
	TRCVINFODATA lDayTime;									/* ���ջ���ι�¤��					*/

	extern  TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/

	extern MOPSCPCB *mopcbp;								/* MOPSCPCB �ܥ���         		*/
	
 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

	iFd = open(mrtrcv->trcvspnm, O_RDONLY);					/* �ե�����򥪡��֥󤹤�       	*/

	PRINTF("(1) mr_rest - iFd = %ld\n", iFd);			

	if(iFd < MRNORMAL )										/* �ե�����򥪡��ץ󥨥顼			*/
	{
		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/
		
		goto error_proc;
	}

	lRet = mr_read(iFd, (char*)&lDayTime, STTDATSI);		/* �ե����뤫��ǡ������ɤ߽Ф�		*/	
	
	PRINTF("(2) mr_rest - lNowaDay = %lx\n", htonl(lDayTime.lNowaDay));			

	PRINTF("(3) mr_rest - lNowaTime = %lx\n", htonl(lDayTime.lNowaTime));			

	PRINTF("(4) mr_rest - lRet = %ld\n", lRet);			
	
	if(lRet != MRNORMAL)									/* mr_read()�ǥ��顼���Ф����		*/	
	{
		cSysCall = READOPTI;								/* �����ƥॳ����option				*/
		
		goto error_proc;									/* ���顼����						*/
	}

	PRINTF("(5) mr_rest - iFd = %ld\n", iFd);			
	
	if(iFd >= MRNORMAL)
	{
		close(iFd);											/* �ե�����򥯥�������			*/
	}

	sprintf(cMsg, "%.4s\t%c\t%08x\t%06x", 					/* ������å��������Խ�����			*/
			MRMSRR3, lDayTime.cStatus, htonl(lDayTime.lNowaDay), htonl(lDayTime.lNowaTime));
	
															/* ��å���������������				*/
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if(lDayTime.cStatus == TRCVFERR)						/* �ξ���ξ��						*/
	{
		mr_kaih();											/* �ơ��֥�ꥫ�Х�������			*/
	
		lRet = 	MRNORMX;
	}
	else
	{
		lRet = MRNORMAL;
	}

	goto exit_from_rest;									/* ��λ����							*/

 	/********************************************************************************************/
    /*  ���顼����																				*/
    /********************************************************************************************/

error_proc:

	lRet = mr_sfer(iFd, cSysCall);							/* ���Ѥ����֥ե����륨�顼����		*/
	
	PRINTF("(6) mr_rest - lRet = %ld\n", lRet);			

	if(mopcbp->mopscstp->tcst2err != TCST2NDW) 				/* ��Ÿξ�ξ��					*/
	{	
		lRet = MRFILERR;
	}
	else
	{
		mr_kaih();											/* �ơ��֥�ꥫ�Х�������			*/
	
		lRet = 	MRNORMX;
		
		PRINTF("(7) mr_rest - lRet = %ld\n", lRet);			
	}

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/
	
exit_from_rest:

	PRINTF("(8) mr_rest - EXIT lRet = %ld\n", lRet);			

	return(lRet);											/* ��λ����							*/
	
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_recv()																	*/
/*																								*/
/*	�㵡ǽ���ס� �ơ��֥���������																*/
/*  																							*/
/*	�꥿����:																					*/
/*		MRFILERR(��Ÿξ�)																		*/
/*		MRNORMAL(����)																			*/
/*		MRNORMX(�ե����륢���������顼)															*/
/************************************************************************************************/
long mr_recv()
{
	
	long lLen = 0;											/* ���Ѥ��ץơ��֥륵����			*/

	char *pcTrc0a = NULL; 									/* ���Ѥ��ץơ��֥���Ƭ���ɥ쥹		*/
	
	char *pcDatabuf = NULL;									/* ���Ѥ��ץơ��֥����򥢥ɥ쥹		*/
	
	char *pcNewData = NULL;									/* �����ǡ���						*/

	char cSysCall = '0';									/* �����ƥॳ����option				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* ��å�����						*/
	
	TRCVINFODATA lDayTime;									/* ���Ѥ�����¤��					*/
	
	int iFd = -1;											/* file descriptor					*/
	
	long lCount = 0;										/* �쥳���ɿ�						*/
	
	TRCVDATA trcvinfo;										/* ���Ѥ��ǡ����쥳���ɹ�¤�����	*/		
	
	long lRet = 0;											/* �ؿ����ֵ���						*/
	
	long lDataSize = 0;										/* �����ǡ�����������4�ܿ���		*/

	extern  MOPSCPCB *mopcbp;            					/* MOPSCPCB �ܥ���         		*/

	extern  TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/
	
	extern  PSCPSECT pscparea;        					    /* �����ƥ� ���� TSECT �ΰ�         */

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

	lLen = mopcbp->mopssstp->tsstrc0l;  					/* ���Ѥ��ץơ��֥륵����������		*/

	PRINTF("(1) mr_recv - lLen = %ld\n", lLen);			


	sprintf(cMsg, "%.4s", MRMSRR8);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

															/* ���Ѥ��ץơ��֥����Ƭ���ե��å�	*/
	pcTrc0a = (char *)pscparea.psccmadt + mopcbp->mopssstp->tsstrc0a;
	
	PRINTF("(2) mr_recv - pcTrc0a = %lx\n", pcTrc0a);			

	lRet = mo_gtbf(MOLMPBF, lLen, (long**) &pcDatabuf);		/*�ꥫ�Х��ѥס���Хåե�			*/
															/* ����ݤ���						*/

	PRINTF("(3) mr_recv - lRet = %ld\n", lRet);			
	
	if(lRet < lLen)
	{
		lRet = MRMNOMEM;
	
		goto exit_from_recv; 								/* ��λ����							*/
	}
	
	lRet = mo_gtbf(MOLMPBF, lLen, (long**) &pcNewData); 	/* �����ǡ����ס���Хåե�			*/
															/* ����ݤ���						*/

	PRINTF("(4) mr_recv - lRet = %ld\n", lRet);			

	if(lRet < lLen )
	{
		lRet = MRMNOMEM;
	
		goto exit_from_recv; 								/* ��λ����							*/
	}

	memcpy(pcDatabuf, pcTrc0a, lLen);						/* �����Ѥ��ץơ��֥�����Ƥ򥳥ԡ�	*/
	
	iFd = open(mrtrcv->trcvjpnm, O_RDONLY);					/* ���Ѥ�����ե�����򥪡��ץ󤹤�	*/
	
	PRINTF("(5) mr_recv - iFd = %ld\n", iFd);					
	
	if(iFd < MRNORMAL )
	{
		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;
	}
	
	lRet = mr_read(iFd, (char*)&lDayTime, DATETIME);		/* ���ߤ����դȻ�����ɤ߽Ф�		*/

	PRINTF("(6) mr_recv - lRet = %ld\n", lRet);					
	
	if(lRet < MRNORMAL)
	{
		cSysCall = READOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼��							*/
	}

	do 
	{
		memset(&trcvinfo, 0x00, BUDASIZE);					/* ���Ѥ��ǡ����쥳���ɹ�¤�ν����	*/

#ifndef DEBUGTEST
		
		if(lCount == 8)
		{
			iFd = -1;
		}

#endif
		
		
		lRet = mr_read(iFd, (char*)&trcvinfo, BUDASIZE);	/* ���Ѥ��ǡ������ɹ���				*/			
		
		PRINTF("(7) mr_recv - lRet = %ld\n", lRet);					

		if(lRet == SYSERROR)								/* ���Ѥ�����ե����뤬���顼��		*/
		{
			
			memcpy(pcTrc0a, pcDatabuf, lLen);				/* �ơ��֥����������				*/
			
			cSysCall = READOPTI;							/* �����ƥॳ����option				*/
		
			PRINTF("(8) mr_recv - pcTrc0a = %lx\n", pcTrc0a);					
			
			lCount = 0;										/* �쥳���ɿ�����������			*/ 
			
			goto error_proc;								/* ���顼����						*/

		}
		else if(lRet == MRNORMX)	 						/* ���Ѥ�����ե����뤬EOF			*/
		{
			PRINTF("(9) mr_recv - lRet = %ld\n", lRet);			
			
			lRet = MRNORMAL;
	
			goto exit_from_recv;							/* ��λ����							*/
		}			
		
		lRet = memcmp(&trcvinfo.msg1, STRTPATN, PATNSIZE);	/* ��Ƭ�ѥ����������å�			*/

		PRINTF("(10) mr_recv - lRet = %ld\n", lRet);					
		 
		if(lRet != MRNORMAL)								/* ��Ƭ�ѥ����󤬽Фʤ����			*/
		{
			goto exit_from_recv;							/* ��λ����							*/
		}

		trcvinfo.size = htonl(trcvinfo.size);
		
		trcvinfo.offset = htonl(trcvinfo.offset);
		
		trcvinfo.num = htonl(trcvinfo.num);
		
		PRINTF("(10.1) mr_recv - trcvinfo.size = %lx\n", trcvinfo.size);	


		lDataSize = mr_intg(trcvinfo.size);					/* 4�ܿ���Ĵ��						*/
		
		PRINTF("(11) mr_recv - lDataSize = %lx\n", lDataSize);					
		 
															/* �����ǡ������ɹ���				*/ 
		lRet = mr_read(iFd, pcNewData, (lDataSize + PATNSIZE));

		PRINTF("(12) mr_recv - lRet = %ld\n", lRet);					


		if(lRet == SYSERROR)								/* ���Ѥ�����ե����뤬���顼��		*/
		{
			memcpy(pcTrc0a, pcDatabuf, lLen);
			
			cSysCall = READOPTI;							/* �����ƥॳ����option				*/
	
			PRINTF("(13) mr_recv - lRet = %ld\n", lRet);

			lCount = 0;										/* �쥳���ɿ�����������			*/ 
			
			goto error_proc;								/* ���顼����						*/
			
		}
		else if(lRet == MRNORMX)							/* ���Ѥ�����ե����뤬EOF			*/
		{
			PRINTF("(14) mr_recv - lRet = %ld\n", lRet);
			
			lRet = MRNORMAL;

			goto exit_from_recv;							/* ��λ����							*/
		}			

															/* ��ü�ѥ�����Υ����å�			*/
		lRet = memcmp((pcNewData + lDataSize), ENDDPATN, PATNSIZE);

		PRINTF("(15) mr_recv - lRet = %ld\n", lRet);

		if(lRet != MRNORMAL)								/* ��ü�ѥ����󤬤Ǥʤ����			*/
		{
			lRet = MRNORMAL;
			
			goto exit_from_recv;							/* ��λ����							*/

		}
															/* �ꥫ�Хꤹ��						*/ 
		memcpy( ( (char *)pscparea.psccmadt + trcvinfo.offset ), pcNewData, trcvinfo.size);

		lCount += 1;										/* �쥳���ɿ��򥫥��󥿥��å�		*/
		
		PRINTF("(16) mr_recv - lCount = %ld\n", lCount);
		 
#ifndef debug
		PRINTF("(16.1)******recvy trcvinfo.offset = %08x\n", trcvinfo.offset);
		PRINTF("(16.2)******recvy trcvinfo.size = %ld\n", trcvinfo.size);
		PRINTF("(16.3)******recvy lLen = %ld\n", lLen);
		PRINTF("(16.4) mr_recv - pcTrc0a = %08x\n", pcTrc0a);	
		PRINTF("(16.5) mr_recv - pscparea.psccmadt = %08x\n", pscparea.psccmadt);
				
#endif			 
		 
	}while( (long)( (char *)pscparea.psccmadt + trcvinfo.offset ) < (long) (lLen + pcTrc0a) );

	lRet = MRNORMAL;

	goto exit_from_recv;									/* ��λ����							*/

 	/********************************************************************************************/
    /*  ���顼����																				*/
    /********************************************************************************************/

error_proc:

	mr_ferr(iFd, cSysCall);									/* ���Ѥ�����ե����륨�顼����		*/
	
															/* ��Ÿξ�Υ����å�				*/
//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMX;
	
	
	PRINTF("(17) mr_recv - mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);


	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* ��Ÿξ�Υ����å�				*/
	{
		lRet = MRFILERR;
		
		PRINTF("(17.1) mr_recv  - lRet = %ld\n", lRet);

	}
	else
	{
		lRet = MRNORMX;
		
		PRINTF("(17.2) mr_recv - lRet = %ld\n", lRet);
	}


	PRINTF("(17.3) mr_recv - lRet = %ld\n", lRet);

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_from_recv:

	if(iFd >= MRNORMAL)										/* �ե�����򥯥���				*/		
	{	
		close(iFd);									
	}

	if(lRet != MRFILERR)									/* ��Ÿξ�ʳ��ξ���				*/
	{
		PRINTF("(18) mr_recv - lRet = %ld\n", lRet);
		
		if(mf_srcv() != MRNORMAL) 							/* FIP�ե������������������		*/		
		{ 	

			if(lRet != MRNORMX)
			{	
				PRINTF("(18.1) mr_recv - lRet = %ld\n", lRet);
				
				lRet = SYSERROR;
			}
		}
	}
	
	if(pcDatabuf != NULL)
	{
		lRet = mo_frbf((long*)pcDatabuf);					/* �ס���Хåե��β���				*/
	}
	
	if(pcNewData != NULL)
	{
		lRet = mo_frbf((long*)pcNewData);					/* �ס���Хåե��β���				*/
	}

	sprintf(cMsg, "%.4s\t%08x\t%06x\t%ld", 
			MRMSRR9, htonl(lDayTime.lNowaDay), htonl(lDayTime.lNowaTime), lCount);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	PRINTF("(19) mr_recv - EXIT lRet = %ld\n", lRet);

	return(lRet);
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	void mr_kaih()																	*/
/*																								*/
/*	�㵡ǽ���ס� �ơ��֥�ꥫ�Х�������														*/
/*  																							*/
/*	�꥿����:																					*/
/*		�ʤ�																					*/
/************************************************************************************************/
void mr_kaih()
{
	char cMsg[MSSGSIZE] = "\0";								/* ��å�������Ǽ��					*/

	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB �ܥ���         		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

	sprintf(cMsg, "%.4s", MRMSRRA);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	mopcbp->mopssstp->tsststd0 = KAISHIKU;					/* ���Ω���夲						*/
	
	PRINTF("(1) mr_kaih - EXIT tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

	return;
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	void mr_frce()																	*/
/*																								*/
/*	�㵡ǽ���ס� SMP������λ����																*/
/*  																							*/
/*	�꥿����:																					*/
/*		�ʤ�																					*/
/************************************************************************************************/
void mr_frce()
{
	
	char lRet = '0';										/* syscom_get_bootmode()���ֵ���	*/

	char cMsg[MSSGSIZE] = "\0";								/* ��å�������Ǽ��					*/
	
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB �ܥ���         		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

	lRet = syscom_get_bootmode();							/* ���Ѽԥ⡼��Ƚ��					*/
	
	PRINTF("(1) mr_frce - lRet = %c\n", lRet);
	
	if(lRet == ENDONWAY)
	{
		sprintf(cMsg, "%.4s", MRMSRRB);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
		
		mopcbp->mopssrtp->tsrtdvst = TSRTEND;				/* �Ÿ��Ǥ����ꤹ��					*/
		
		PRINTF("(2) mr_frce - tsrtdvst = %c\n", mopcbp->mopssrtp->tsrtdvst);
	}

	PRINTF("(3) mr_frce - EXIT lRet = %c\n", lRet);

	return;
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_inff()																	*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե�����γ��Ͻ���													*/
/*  																							*/
/*	�꥿����:																					*/
/*		MRNORMAL																				*/
/*		MRFILERR																				*/
/************************************************************************************************/
long mr_inff()
{

	char cSysCall = '0';									/* �����ƥॳ����option				*/

	int iFd = -1;											/* file descriptor					*/
	
	long lDay = 0;											/* ���դ��ѿ�						*/
	
	long lTime = 0;											/* ���֤��ѿ�						*/
	
	long lRet = 0;											/* �ؿ����ֵ���						*/
	
	TRCVINFODATA lDayTime;									/* ���ջ��ﹽ¤�Τ����				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* ��å�������Ǽ��					*/

	extern TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/
	
	extern MOPSCPCB *mopcbp; 								/* MOPSCPCB �ܥ���         		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

    iFd = open(mrtrcv->trcvjpnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);

	PRINTF("(1) mr_inff - iFd = %ld\n", iFd);

	PRINTF("(1.2) mr_inff - mrtrcv = %08x\n", mrtrcv);

	
	sprintf(cMsg, "%.4s\t%s", MRMSRR4, mrtrcv->trcvjpnm);

	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if(iFd < MRNORMAL )										/* �ե����뤬���顼�ξ��			*/
	{
		PRINTF("(2) mr_inff - iFd = %ld\n", iFd);

		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼����						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* �������ջ�������				*/
	
	lTime &= 0x00FFFFFF; 									/* hhmmss�������ѹ�����				*/
	
	PRINTF("(3) mr_inff - lDay = %.8x\n", htonl(lDay));

	PRINTF("(4) mr_inff - lTime = %.6x\n", htonl(lTime));

	lDayTime.lNowaDay = htonl(lDay);						/* ���դ����ꤹ��					*/
	
	lDayTime.lNowaTime = htonl(lTime);						/* ��������ꤹ��					*/

	lRet = mr_writ(iFd, (char*)&lDayTime, DATETIME);		/* �������ջ����ե�����˽񤭹��� */
	 
	PRINTF("(5) mr_inff - lRet = %ld\n", lRet);

 	if(lRet  != MRNORMAL)									/* �ե����뤬���顼�ξ��			*/
 	{
		cSysCall = WRITOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼����						*/
	 
 	}
 	else
 	{
		if (iFd >= MRNORMAL)								
		{	
			close(iFd);										/* �ե����륯����					*/	
		}

		mrtrcv->trcvjfst = TRCVFNML;						/* ����򹹿�����					*/

		PRINTF("(6) mr_inff - trcvjfst = %c\n", mrtrcv->trcvjfst);

		sprintf(cMsg, "%.4s\t%08x\t%06x", MRMSRR5, lDay, lTime);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
        
        lRet = MRNORMAL;
        
        goto exit_from_inff;								/* ��λ����							*/
	 }

 	/********************************************************************************************/
    /*  ���顼����																				*/
    /********************************************************************************************/

error_proc:

	mr_ferr(iFd, cSysCall);									/* ���Ѥ�����ե����륨�顼����		*/

	PRINTF("(%ld) mr_inff - lRet = %ld\n", 7);
	
	PRINTF("(7.1) mr_inff - mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);

	if(mopcbp->mopscstp->tcst2err != TCST2NDW)
	{
		lRet = MRFILERR;
		
		PRINTF("(7.2) mr_inff - lRet = %ld\n", lRet);

	}
	else
	{
		lRet = MRNORMAL;
		
		PRINTF("(7.3) mr_inff - lRet = %ld\n", lRet);
	}

//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMAL;
	
	PRINTF("(7.4) mr_inff - lRet = %ld\n", lRet);

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_from_inff:

	PRINTF("(8) mr_inff - lRet = %ld\n", lRet);

	return(lRet);											/* �꡼���󤹤�  					*/ 

}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_sttf()																	*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ����֥ե�����γ��Ͻ���													*/
/*  																							*/
/*	�꥿����:																					*/
/*		MRNORMAL																				*/
/*		MRFILERR																				*/
/************************************************************************************************/
long mr_sttf()
{
	int iFd = -1;											/* file descriptor					*/ 	

	char cSysCall = '0';									/* �����ƥॳ����option				*/
	
	long lDay = 0;											/* �����ѿ�							*/
	
	long lTime = 0;											/* �����ѿ�							*/
	
	long lRet = 0;											/* �ؿ����ֵ���						*/

	char cMsg[MSSGSIZE] = "\0";								/* ��å�������Ǽ��					*/

	TRCVINFODATA InputData;									/* ���Ѥ����ֹ�¤�Τ����			*/
	
	extern  TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/
	
	extern MOPSCPCB *mopcbp; 								/* MOPSCPCB �ܥ���         		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

    iFd = open(mrtrcv->trcvspnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);
  
  	PRINTF("(1) mr_sttf - iFd = %ld\n", iFd);
  	
	PRINTF("(1.1) mr_stff - filename = %s\n", mrtrcv->trcvspnm);
	
	PRINTF("(1.3) mr_stff - mrtrcv = %08x\n", mrtrcv);

	sprintf(cMsg, "%.4s\t%s", MRMSRR6, mrtrcv->trcvspnm);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if(iFd < MRNORMAL )										/* �ե����뤬���顼�ξ��			*/
	{
		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼����						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* ���ջ������					*/
	
	lTime &= 0x00FFFFFF; 									/* hhmmss�������ѹ�����				*/

	PRINTF("(3) mr_sttf - lDay = %08x\n", htonl(lDay));

	PRINTF("(4) mr_sttf - lTime = %06x\n", htonl(lTime));

	InputData.lNowaDay = htonl(lDay);						/* ���դ����ꤹ��					*/

	InputData.lNowaTime = htonl(lTime);						/* ��������ꤹ��					*/
	 
	InputData.cStatus = mrtrcv->trcvjfst;					/* �ξ���򹹿�����					*/
	
	memset(InputData.pcYobi, 0x00, 3);						/* 0x00��ͽ�������ꤹ��				*/

	PRINTF("(5) mr_sttf - InputData.cStatus = %c\n", InputData.cStatus);

	lRet = mr_writ(iFd, (char*) &InputData, STTDATSI);		/* ���ջ���ȸξ���֤�񤯹���		*/

	PRINTF("(6) mr_sttf - lRet = %ld\n", lRet);
	 
 	if(lRet != MRNORMAL)									/* �ե����뤬���顼�ξ��			*/
 	{
		PRINTF("(7) mr_sttf - lRet = %ld\n", lRet);

		cSysCall = WRITOPTI;								/* �����ƥॳ����option				*/
	
		goto error_proc;									/* ���顼����						*/
	}
 	else
 	{
		if (iFd >= MRNORMAL)
		{	
			close(iFd);
		}

		mrtrcv->trcvsfst = TRCVFNML;						/* ���Ѥ����֤�����򹹿�����		*/
		
		sprintf(cMsg, "%.4s\t%08x\t%06x\t%c", MRMSRR7, lDay, lTime, InputData.cStatus);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

        lRet = MRNORMAL;
        
  		PRINTF("(8) mr_sttf - lRet = %ld\n", lRet);			

        goto exit_from_sttf;								/* ��λ����							*/
	
	}

 	/********************************************************************************************/
    /*  ���顼����																				*/
    /********************************************************************************************/

error_proc:

	lRet = mr_sfer(iFd, cSysCall);							/* ���Ѥ����֥ե�����Υ��顼����	*/
	
	mrtrcv->trcvsfst =  TRCVFERR;		   					/* �ξ���򹹿�����					*/

															/* ��Ÿξ�Υ����å�				*/
//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMAL;


	PRINTF("(9) mr_sttf - lRet = %ld\n", lRet);

	PRINTF("(9.1) mr_sttf - mopcbp->mopscstp->tcsttrcv = %c\n", mopcbp->mopscstp->tcst2err);


	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* ��Ÿξ�Υ����å�				*/
	{
		lRet = MRFILERR;
		
		PRINTF("(9.2) mr_sttf - lRet = %ld\n", lRet);

	}
	else
	{
		lRet = MRNORMAL;
		
		PRINTF("(9.3) mr_sttf - lRet = %ld\n", lRet);
	}



															
	PRINTF("(9.4) mr_sttf - lRet = %ld\n", lRet);
														
 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_from_sttf:

	PRINTF("(10) mr_sttf - EXIT lRet = %ld\n", lRet);

	return(lRet);											/* �꡼���󤹤�  					*/ 
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long mr_stpr()																	*/
/*																								*/
/*	�㵡ǽ���ס�  ���Ͻ���																		*/
/*  																							*/
/*	�꥿����:																					*/
/*			MRNORMAL																			*/
/************************************************************************************************/
long mr_stpr()
{

	long lRet = MRNORMAL;									/* �ֵ���							*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/
	
	lRet = mr_inff();										/* ���Ѥ�����ե�����ν��������	*/							
	
	PRINTF("(1) mr_stpr - lRet = %ld\n", lRet);

	if(lRet != MRNORMAL)
	{
		goto exit_to_main;									/* ��λ����							*/
	}

	lRet = mr_sttf();										/* ���Ѥ����֥ե�����ν��������	*/
	
	PRINTF("(2) mr_stpr - lRet = %ld\n", lRet);

	if(lRet != MRNORMAL)									
	{
		goto exit_to_main;									/* ��λ����							*/
	}

	mr_frce();												/* SMP ������λ����					*/

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_to_main:
		
	PRINTF("(2) mr_stpr - EXIT lRet = %ld\n", lRet);

	return(MRNORMAL); 
	
}

