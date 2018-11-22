/*----------------------------------------------------------------------------------------------*/
/* ���оݶ�̳̾��                    �ξ������̳      ����         							*/
/* ���оݶ�̳�ɣġ�                  �ңã�                         							*/
/* �㥵���ӥ�����̾��                �ơ��֥�ꥫ�Х�          ��   							*/
/* �㥵���ӥ����ܣɣġ�              JEDT2                    									*/
/* ��⥸�塼��̾��                  ���򡲣أأأ�												*/
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
/* �㥽��������ǯ������              ��������ǯ���������         							*/
/* �㥽����������̾��                                               							*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�                                 							*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���                ���ƥå�                       							*/
/*---------------------------------------------------------------------------------------------	*/
/* �㵡ǽ���ס�                                                     							*/
/*                                                                  							*/
/*      ���Ѥ�����ե�����ؤξ����������     													*/
/*                                                                  							*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                     							*/
/*		long 	mr_jedt2(short type, char* name, char* datadr, char* data2, long num,			*/
/*						 long size, long offset)												*/
/*                                                                  							*/
/* �㲾������                                                       							*/
/*		short 	type;			���㡼�ʥ���� (̤���ѡ���¸��mr_jedt()�ߴ��Τ���)				*/
/*		char  	*name;			�ơ��֥�̾														*/
/*		char  	*datadr;		�����ǡ�����Ǽ��Ƭ���ɥ쥹										*/
/*		char  	*data2;			�������ǡ������ɥ쥹 (̤���ѡ���¸��mr_jedt()�ߴ��Τ���) 		*/
/*		long  	num;			�������ֹ�                   									*/
/*		long  	size;			�����ǡ���������												*/
/*		long  	offset;			�������֥��ե��å� (TADT�ơ��֥���Ƭ���顢						*/
/*								�������֤ޤǤ����Х��ɥ쥹)										*/
/*		  																						*/
/*              �ʤ�                                                							*/
/* ���ֵ��͡�                                                       							*/
/*		MRNORMAL	  :  ���ｪλ																*/
/*																								*/
/*		MRIVPARM	  :  �ѥ�᡼�� ���顼														*/
/*																								*/
/*		MRNORMX	  	  :  ��������ｪλ(ȯ�Ծ������å����ե����륢���������顼��				*/
/*																								*/
/*		MRENQERR	  :  ����ͭ���顼															*/
/*																								*/
/*		MRMNOMEM      :  �Хåե����ݼ���														*/
/*																								*/
/*		MRMBUFERR     :  �Хåե���������														*/
/*																								*/
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
#include <syslog.h>
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <netinet/in.h>

/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include    "tcom.h"
#include    "psect.h"
#include    "tsst.h"
#include    "tpct.h"	
#include    "mrmac.h"   
#include 	"trcv.h"	
#include    "mrcom.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "mr.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mrmirr.h"
#include    "mopcb.h"	
#include    "mrcode.h"
#include	"mcdebug.h"


/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
/* file access	*/
long mr_intg(long);
long mr_writ(int, char*, long);
void mr_edit(char*, char*, char*, long, long, long);

/* ���Ѥ����֥ե����륨�顼���� */
long mr_sfer(int, char);

/* ���Ѥ�����ե����륨�顼���� */
void mr_ferr(int, char);
long mr_ifer(int, char);

/************************************************************************************************/
/*	�����ؿ����										             							*/
/*																								*/
/************************************************************************************************/
long  mo_gtbf(long, long, long**);
long  mo_frbf(long*);
void  mr_sdwn(long, short, long);
long  ms_wtop(long, short, char, char, long, long);     
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
/*	��ؿ�̾��	 long mr_jedt2(short type, char* name, char* datadr, char* data2, long num, 	*/
/*							   long size, long offset)											*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե�����ؤξ����������  											*/
/*																								*/
/*	������� 																					*/
/*		  short  type;		���㡼�ʥ���� (̤���ѡ���¸��mr_jedt()�ߴ��Τ���)					*/
/*		  char   *name;    	�ơ��֥�̾															*/
/*		  char   *datadr;   �����ǡ�����Ǽ��Ƭ���ɥ쥹											*/
/*		  char   *data2;    �������ǡ������ɥ쥹 (̤���ѡ���¸��mr_jedt()�ߴ��Τ���) 			*/
/*		  long   num;	  	�������ֹ�                   										*/
/*		  long   size;      �����ǡ���������													*/
/*		  long   offset;    �������֥��ե��å� (TADT�ơ��֥���Ƭ���顢							*/
/*		  					�������֤ޤǤ����Х��ɥ쥹)											*/
/*  																							*/	
/*  ���ֵ��͡�																					*/
/*																								*/
/*		MRNORMAL	  :  ���ｪλ																*/
/*																								*/
/*		MRIVPARM	  :  �ѥ�᡼�� ���顼														*/
/*																								*/
/*		MRNORMX	  	  :  ��������ｪλ(ȯ�Ծ������å����ե����륢���������顼��				*/
/*																								*/
/*		MRENQERR	  :  ����ͭ���顼															*/
/*																								*/
/*		MRMNOMEM      :  �Хåե����ݼ���														*/
/*																								*/
/*		MRMBUFERR     :  �Хåե���������														*/
/*																								*/
/************************************************************************************************/
long mr_jedt2(short type, char* name, char* datadr, char* data2, long num, 	
              long size, long offset)											
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lLen = 0;							                /* ���Ѥ�����ơ��֥륵����  		*/
	
	long lRetFunc= 0;										/* �����ƥॳ�����ֵ���				*/

	long lRet = 0;											/* �ֵ���							*/
	
	long iFd = -1;											/* �ե����� �ǥ�������ץ�  		*/
	
	char cSysCall = '0';									/* �����ƥॳ����option				*/
	
	char *pcDataBuf = NULL;									/* �����ǡ����ΰ�					*/

	size_t sBufLen= 0;										/* �ɲý񤭹���ǡ�����Ĺ			*/
	
	TPCTPSZ *tpctp = NULL;		         					/* TPCT�������ܥ��� 				*/

	/********************************************************************************************/
	/*  �����ѿ��ΰ�                                                                            */
	/********************************************************************************************/
	TCOMPAT *tcomrcv;
	long tsubrcv ;											/* TRCV���ֶ�����������				*/
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB �ܥ���   			    */
	extern  PSCPSECT    pscparea;           				/* �����ƥඦ�� TSECT �ΰ� 			*/
	extern  TRCV 		*mrtrcv;							/* ����TRCV���ΰ�					*/
	
	/********************************************************************************************/
	/*	���ϥ����å�																		    */
	/********************************************************************************************/

	PRINTF("jedt2 (0) datadr = %08x\n", datadr);

	PRINTF("jedt2 (1) name = %.4s\n", name);

	PRINTF("jedt2 (2) size = %ld\n", size);
	
	PRINTF("jedt2 (3) offset = %ld\n", offset);
	
	PRINTF("jedt2 (4) num = %ld\n", num);
	
	
   	tcomrcv = mo_tagt("TRCV");								/* TRCV����Ƭ����					*/

	tsubrcv = tcomrcv->tcomsbps ;							/* ���ֶ���������������				*/

	if(tcomrcv == 0)
	{

		lRet = MRNORMX;
		
		PRINTF("(0) mr_trcv - motagt  = %ld\n", lRet);
		
		goto exit_to_main;
	}

	mrtrcv = (TRCV*)((char*)tcomrcv + sizeof(TCOMPAT) + tsubrcv);

	

	PRINTF("jedt2 (4.1) mrtrcv = %08x\n", mrtrcv);
														/* ���Ѥ��ץơ��֥륵����		   		*/
	lLen = mopcbp->mopssstp->tsstrc0l + mopcbp->mopssstp->tsstrc0a;	
	
	PRINTF("jedt2 (5) lLen = %ld\n", lLen);
	
    tpctp = (TPCTPSZ *)MRTBLAD( pscparea.pscpctad, pscparea.pscpctno+1 );
                                       					/* TPCT���������ɥ쥹�����ꤹ��   		*/
                                        					
   	PRINTF("(1.4.1) jedt2 - tpctp = %x\n", tpctp);

	if( (datadr == NULL) || (size <= 0) || (offset >= lLen) || /* �����Υ����å� 		        */ 
	    ((offset + size) > lLen) || (offset < 0) ) 
	{
		lRet = MRIVPARM;
		
		PRINTF("jedt2 (6) lRet=%ld\n", lRet);
		
	
		goto exit_to_main;									/* ��λ����							*/
 	}

	/********************************************************************************************/
    /*  ȯ�Ծ������å��ʥ����ƥ๽���Υ����å���   		                                    */
	/********************************************************************************************/
    if( (mopcbp->mopssstp->tsstsysd == MOYOBIKK) || 
        (mopcbp->mopssstp->tsstsysc == TSSTCING) )
    {      													/* ����ץ�å�����������			*/
                                        					/* �����ƥ๽�����ۥåȥ�����Х��� */
    														/* ͽ���Ϥλ�						*/
        
        lRet = MRNORMX;	                   					/* �꡼���󤹤�                     */

		PRINTF("jedt2 (7) lRet=%ld\n", lRet);
        
        goto exit_to_main;									/* ��λ����							*/
    }
   
    /********************************************************************************************/
    /*  ȯ�Ծ������å��ʣӣͣб�ž�⡼�ɤΥ����å���                   						*/
    /********************************************************************************************/
    if( ( (mopcbp->mopssstp->tsstprmd[0] & 0x0000000FL) != 0x00000000L) )
    { 	    	            								/* �ץ������⡼�ɤ�   			*/
     														/* ����饤��⡼�ɤ��ʤ���			*/
    	lRet = MRNORMX; 			                  		/* �꡼���󤹤�                     */
    	
		PRINTF("jedt2 (8) lRet=%ld\n", lRet);
    	
    	goto exit_to_main;									/* ��λ����							*/
    } 

    /********************************************************************************************/
    /*  ȯ�Ծ������å��ʥꥫ�Х���/���ץ����å���		  					                    */
    /********************************************************************************************/

    if(mopcbp->mopscstp->tcsttrcv != TCSTTRNE)
    {                                    					/* �ꥫ�Х���/���׾���            */
                                     						/* �ꥫ�Х����פλ� 	            */
        lRet = MRNORMX;	                					/* �꡼���󤹤�  					*/
        
 		PRINTF("jedt2 (9) lRet=%ld\n", lRet);
    
    	goto exit_to_main;									/* ��λ����							*/
    }                     				

    /********************************************************************************************/
    /*  ���Ѥ�����ե�������֥����å�				  					                        */
    /********************************************************************************************/
    if(mrtrcv->trcvjfst == TRCVFERR)
    {														/* ���Ѥ�����ե����륹�ơ�������   */
															/* �ξ�Ǥ����			            */
		lRet = MRNORMX;										/* �꡼���󤹤�  					*/

		PRINTF("jedt2 (10) lRet=%ld\n", lRet);

		goto exit_to_main;									/* ��λ����							*/
	} 
    
    /********************************************************************************************/
    /*  TPCT ����󥻥��Բĥե饰(JNL��ͭ)��ON�ˤ���  											*/
    /********************************************************************************************/
   PRINTF("jedt2 (10.1) ltpctp->tpctncaf = %lx\n", tpctp->tpctncaf);     
  
  
    MRBITON(tpctp->tpctncaf, TPCTJNL);						/* TPCT ����󥻥��Բĥե饰		*/
                             							   	/* (JNL��ͭ)��ON�ˤ���     			*/
                             							   	
    PRINTF("jedt2 (10.2) tpctp->tpctncaf = %lx\n", tpctp->tpctncaf);     
    
    /********************************************************************************************/
    /*  �����ơ������Խ�����						  					                        */
    /********************************************************************************************/                                         					
	lRetFunc = mo_gtbf(MOLMPBF, size + INFOSIZE, (long**) &pcDataBuf);
															/* �ǡ����Խ����ΰ�����       	*/
															
	PRINTF("jedt2 (11) lRetFunc = %ld\n", lRetFunc);

	if(lRetFunc < (size + INFOSIZE))
	{
		lRet = MRMNOMEM;
		
		PRINTF("jedt2 (12) lRet = %ld\n", lRet);
		
		goto exit_to_main;									/* ��λ����							*/
	}

	mr_edit(pcDataBuf, name, datadr, num, size, offset);	/* �ǡ�����Խ����������Ԥ�		*/													
				
	/********************************************************************************************/
    /*  ���Ѥ�����ե�����򥪡��ץ󤹤�	  													*/
    /********************************************************************************************/
    iFd = open(mrtrcv->trcvjpnm, O_SYNC | O_WRONLY | O_APPEND);
    														/* �ե�����򥪡��֥󤹤�       	*/
    														
	PRINTF("jedt2 (13) iFD = %ld\n", iFd);
    														
	if(iFd == SYSERROR)										/* �����֥󤬤Ǥ��ʤ��ä���۾ｪλ	*/
    {
		cSysCall =  OPENOPTI;								/* �����ƥॳ����(open)���顼������	*/
		
		lRet = MRNORMX;										/* �꡼���󤹤�  					*/ 
		
		PRINTF("jedt2 (13) lRet = %ld\n", lRet);

		goto error_prc;										/* ���顼������Ԥ�					*/
	}

	/********************************************************************************************/
    /*  ���Ѥ�����ե��������å�����		  													*/
    /********************************************************************************************/
    
    lRetFunc= lockf(iFd, F_LOCK, 0);						/* ���Ѥ�����ե��������å�����   */
    
    														
	PRINTF("jedt2 (14) lRetFunc = %ld\n", lRetFunc);
    
    if(lRetFunc == SYSERROR)								/* �ե�����Υ��å����Ǥ��ʤ��ä���	*/
    {														/* �۾ｪλ                         */

		cSysCall = LOCKOPTI;								/* �����ƥॳ����(lockf)���顼������*/
    
		lRet =  MRENQERR; 

		PRINTF("jedt2 (15) lRet = %ld\n", lRet);
		
		goto error_prc;										/* ���顼������Ԥ�					*/
		
	}
	
	/********************************************************************************************/
    /*  ���Ѥ�����ե�����˹����ǡ������ɲý񤭹���											*/
    /********************************************************************************************/
	sBufLen= mr_intg(size) + BUDASIZE;

	
	lRetFunc = mr_writ(iFd, pcDataBuf, sBufLen);  			/* �ɲý񤭹���ǡ�����ե������   */  
															/* �ɲý񤭹���					    */ 
															
	PRINTF("jedt2 (16) lRetFunc = %ld\n", lRetFunc);
 

	if(lRetFunc != MRNORMAL)								/* ���露��ʤ����۾������¹Ԥ���	*/
	{

		cSysCall = WRITOPTI;								/* �����ƥॳ����(write)���顼������*/
		
		lRet = MRNORMX;										 

		PRINTF("jedt2 (17) lRet = %ld\n", lRet);
						
		goto error_prc;										/* ���顼����	  					*/
	
	}

	lRetFunc = mr_writ(iFd, ENDDPATN, PATNSIZE);  			/* �ǡ�����ü�ѥ������ե������   */
															/* �񤭹���							*/ 	

	PRINTF("jedt2 (18) lRetFunc = %ld\n", lRetFunc);
	
	if(lRetFunc != MRNORMAL)								/* ���露��ʤ����۾������¹Ԥ���	*/
	{
		cSysCall = WRITOPTI;								/* �����ƥॳ����(write)���顼������*/

		lRet = MRNORMX;										 
		
		PRINTF("jedt2 (19) lRet = %ld\n", lRet);
		
		goto error_prc;										/* ���顼����	  					*/
	}
	
	if(iFd >= 0)
	{
		close(iFd);
	}

	goto exit_to_main;										/* ��λ����							*/

	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

error_prc:
	mr_ferr(iFd, cSysCall);									/* ���Ѥ�����ե�����Υ��顼����	*/

	PRINTF("jedt2 (20) ERROR iFd = %ld\n", iFd);

	PRINTF("jedt2 (20.1) mopcbp->mopscstp->tcst2err = %c\n", mopcbp->mopscstp->tcst2err);
	
	if(mopcbp->mopscstp->tcst2err != TCST2NDW)				/* ��Ÿξ�ξ��					*/	 
	{
		mr_sdwn(MRDOWN, MRESYSINT, MRDJNLWERR);				/* mr_sdwn()��ȯ��					*/
	}			
		
exit_to_main:

	MRBITOFF(tpctp->tpctncaf, TPCTJNL);						/* TPCT ����󥻥��Բĥե饰		*/
	                         							   	/* (JNL��ͭ)��OFF�ˤ���	   			*/
	                         							   	
	PRINTF("jedt2 (21) tpctncaf=%lx\n", tpctp->tpctncaf);
                         							   	
	if(pcDataBuf != NULL)									/* ����Ƥ����ΰ���������		*/
	{
		
		lRetFunc = mo_frbf((long *)pcDataBuf);				/* �Хåե����������				*/
	
		PRINTF("jedt2 (22) lRetFunc = %ld\n", lRetFunc);
		
		if(lRetFunc != MRNORMAL)							/* �۾�λ�							*/
		{
			lRet = MRMBUFERR;
			
			PRINTF("jedt2 (23) lRet = %ld\n", lRet);
		}
	}

	PRINTF("jedt2 (24) EXIT lRet = %ld\n", lRet);

	return(lRet);											/* ��λ����							*/
    
}    	
   
 
/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	void mr_edit(char* pcDataBuf, char* name, char* datadr, long num, 				*/
/*							long size, long offset)												*/
/*																								*/
/*	�㵡ǽ���ס�  �����ǡ������Խ�����															*/
/*  																							*/
/*	�꥿����:																					*/
/*			�ʤ�																				*/
/************************************************************************************************/
void mr_edit(char* pcDataBuf, char* name, char* datadr, long num, long size, long offset)
{
	
  	long position = 0;											   /* �����ơ������ܤΰ��� 		*/
	
	long lDatalen = 0;											   /* �����ǡ�����4�ܿ�         */

	long lOffSet = htonl(offset);								   /* �Х���ȿž��offset		*/	
	
	long lSize = htonl(size);									   /* �Х���ȿž��size			*/
	
	long lNum = htonl(num); 									   /* �Х���ȿž��num			*/
	
	memcpy(pcDataBuf, STRTPATN, PATNSIZE);				  		   /* ���ϥѡ�������Խ�    	*/
	
	position += PATNSIZE;										   /* 4 byte��ä���			*/	

	PRINTF("mr_edit (1) size=%ld\n", size);

	memcpy(pcDataBuf+position, &lOffSet, sizeof(long));	  		   /* offset���Խ�  			*/

	position += PATNSIZE;										   /* 4 byte��ä���			*/
	
	PRINTF("mr_edit (2) offset=%ld\n", offset);
	
	memcpy(pcDataBuf+position, &lSize, sizeof(long));			   /* �����ǡ������������Խ�    */

	position += PATNSIZE;										   /* 4 byte��ä���			*/
	
	memcpy(pcDataBuf+position, name, sizeof(long));                /* �ơ��֥�̾                */

	PRINTF("mr_edit (3) name=%.4s\n", name);

	position += PATNSIZE;										   /* 4 byte��ä���            */ 

	memcpy(pcDataBuf+position, &lNum, sizeof(long));	 		   /* �������ֹ�				*/

	position += PATNSIZE;										   /* 4 byte��ä���            */
	
	PRINTF("mr_edit (4) num=%ld\n", num);
	
	memcpy(pcDataBuf + position, datadr, size);					   /* �����ǡ������Խ�			*/

	lDatalen = mr_intg(size);							   		   /* 4�ܿ��ε��				*/

	PRINTF("mr_edit (5) lDatalen=%ld\n", lDatalen);
	
	if((lDatalen - size) > 0);									   /* 4�ܿ��Ǥʤ����ϡ����   */
	{		
		memset(pcDataBuf + (position+size), 0x00, lDatalen-size);
	}

	return;
}
	
	