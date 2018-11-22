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
/* �������ֹ��                      03-3341-5504                   							*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�䡡���������������������ӣ������                   							*/
/* ���߷�ǯ������                    ��������ǯ���������	         							*/
/* ���߷׽�����̾��                  ��                             							*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                  							    */
/*----------------------------------------------------------------------------------------------*/
/* �㥽����������̾��                �ӣ������                   							*/
/* �㥽��������ǯ������              ��������ǯ���������	        							*/
/* �㥽����������̾��                ��                     	      							*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������  (TBCS0119)							*/
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
/*															�����Ⱥ�� SSLA0036				*/
/*																								*/
/*		SYSERROR:   FIP�ե����������票�顼														*/
/*																								*/
/*		MRFILERR:   �ե����륢���������顼														*/
/*																								*/
/*		MRNOMEM		�Хåե����ݼ���						�������ɲ� TBCS0156				*/
/*																								*/
/*		MRNORRCV:   �ơ��֥�ꥫ�Х�����»�				�������ɲ� SSLA0038				*/
/*----------------------------------------------------------------------------------------------*/
/* �����»����         �ʤ�                                        							*/
/*                                                                  							*/
/* ����ѳ����⥸�塼��ɣġ�                                      	                            */
/* ��ƽХ⥸�塼��ɣġ�                                           							*/
/*                                                                  							*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0119                                                      					*/
/* ��¤���� ��S�ȥ졼����ǽ���ɲá��楶���½������ɲ�                          					*/
/* ��¤��   ��2003.06.05                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0156                                                                          */
/* ��¤���� ���ե����륢���������顼�����ֵ��ͤ��������ͤǤʤ��Τ��������ͤ��֤��褦�˽���      */
/*            �ơ��֥����������ǽ�����ή�줬PD��ɤ���ˤʤäƤ��ʤ��Τ�PD��ɤ���˽���        */
/* ��¤��   ��2003.06.20                                                    					*/
/* ��¤��   ��Supply    ����                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0163                                                                          */
/* ��¤���� ��SMP�ؿ����顼��å�����(SRRC)�����ջ�����Ϥ�Ƚ�ǽ������ɲ�						*/
/* ��¤��   ��2003.06.24                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0187                                                                          */
/* ��¤���� ��SMP�ؿ����顼��å�����(SRRC)���������ؿ�̾����									*/
/* ��¤��   ��2003.07.02                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0188                                                                          */
/* ��¤���� ��mf_srcv�ֵ��ͤ�Ƚ�ǽ�������														*/
/* ��¤��   ��2003.07.02                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��SSLA0036                                                                          */
/* ��¤���� ��mo_gtbf()/mo_frbf()�ǳ���/�������Ƥ�������									*/
/*			  malloc()/free()�ǳ���/��������褦�˽���											*/
/* ��¤��   ��2003.07.04                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��SSLA0038                                                                          */
/* ��¤���� ���ֵ��ͤˡ֥ơ��֥�ꥫ�Х�����»�(MRNORRCV)�פ��ɲ�								*/
/* ��¤��   ��2003.07.08                                                    					*/
/* ��¤��   ��Supply    ��	                                                					*/
/************************************************************************************************/
/************************************************************************************************/
/* ��¤�ֹ� ��TBCS0200                                                                          */
/* ��¤���� ������������ǥե����륢���������顼�ֹ椬���Ϥ���Ƥ��ʤ��Τǽ��Ϥ���褦�˽���    */
/* ��¤��   ��2003.07.09                                                                        */
/* ��¤��   ��Supply   ����                                                                     */
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
//#include    "mrmirr.h"
#include    "mrcode.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mopcb.h"
#include	"mcdebug.h"
#include	"mrmsg.h"
#include    "mo_wlg.h"
#include    "mf.h"														/* TBCS0188				*/

/************************************************************************************************/
/*      define function name for mo_wlg4							 							*/
/*                													 							*/
/************************************************************************************************/
#define MR_TRCV		0x6d725f74, 0x72637620								/* TBCS0119				*/
#define	MR_REST		0x6d725f72, 0x65737420								/* TBCS0119				*/
#define	MR_RECV		0x6d725f72, 0x65637620								/* TBCS0119				*/
#define	MR_KAIH		0x6d725f6b, 0x61696820								/* TBCS0119				*/
#define	MR_FRCE		0x6d725f66, 0x72636520								/* TBCS0119				*/
#define MR_INFF		0x6d725f69, 0x6e666620								/* TBCS0119				*/
#define MR_STTF		0x6d725f73, 0x74746620								/* TBCS0119				*/
#define MR_STPR		0x6d725f73, 0x74707220								/* TBCS0119				*/


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
char 	syscom_get_bootmode();
long 	mf_srcv();
long 	mo_gtbf(long, long, long**);
long 	mo_frbf(long*);
long 	mo_date(long*, long*);
long 	ms_wtop(long, short, char, char, long, long);     
TCOMPAT *mo_tagt(unsigned char*);
void	mo_wlg4();        

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
/*																�����Ⱥ�� SSLA0036			*/
/*																								*/
/*		SYSERROR:   FIP�ե����������票�顼														*/
/*																								*/
/*		MRFILERR:   �ե����륢���������顼														*/
/*																								*/
/*		MRNORRCV:   �ơ��֥�ꥫ�Х�����»�					�������ɲ� SSLA0038			*/
/*																								*/
/************************************************************************************************/
long mr_trcv()
{

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRet = MRNORMAL;									/* �ֵ���							*/
	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/
	
	/********************************************************************************************/
	/*  �����ѿ��ΰ�                                                                            */
	/********************************************************************************************/
	TCOMPAT *tcomrcv;
	extern  MOPSCPCB    *mopcbp;            				/* MOPSCPCB �ܥ���         		*/
	extern TRCV *mrtrcv;									/* ����TRCV���ΰ�					*/
	long tsubrcv;											/* TRCV���ֶ�����������				*/
	
	char cMsg[MSSGSIZE] = "\0";								/* ��å�����	TBCS0163			*/

		
    /********************************************************************************************/
    /*  ȯ�Ծ������å��ʣӣͣб�ž�⡼�ɤΥ����å���                   						*/
    /********************************************************************************************/

	mo_wlg4(MR_TRCV, WINSC, 0, 0);							/* TBCS0119							*/
    
   	tcomrcv = mo_tagt("TRCV");								/* TRCV����Ƭ���ɥ쥹����			*/

	if(tcomrcv == 0)
	{
		mo_wlg4(MR_TRCV, 0x44440001, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		
		sprintf(cMsg, "%.4s\tmo_tagt\t%08x", MRMSRRC, tcomrcv); /* TBCS0163						*/
		
															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
													
															
		lRet = MRNORMX;
		
		PRINTF("(0) mr_trcv - motagt  = %ld\n", lRet);
		
		goto exit_to_main;
	}

	tsubrcv = tcomrcv->tcomsbps ;							/* ���ֶ���������������				*/ 

	mrtrcv = (TRCV*)((char*)tcomrcv + sizeof(TCOMPAT) + tsubrcv);
		
	PRINTF("(0.0) mr_trcv - tcomrcv  = %08x\n", tcomrcv);
	PRINTF("(0.1) mr_trcv - mrtrcv  = %08x\n", mrtrcv);
	PRINTF("(0.2) mr_trcv - sizeof(TCOMPAT)  = %ld\n", sizeof(TCOMPAT));
	PRINTF("(0.3) mr_trcv - tcomrcv->tcomsbps  = %08x\n", tcomrcv->tcomsbps);
	PRINTF("(0.4) mr_trcv - tcomrcv->tcomsbps  = %.20s\n", tcomrcv->tcomsbps);


    if( ( (mopcbp->mopssstp->tsstprmd[0] & 0x0000000FL) != 0x00000000L) )
    { 	    	            								/* �ץ����⡼�ɤ�   			*/
     														/* ����饤��⡼�ɤ��ʤ���			*/
    	
    	mrlog[0] = mopcbp->mopssstp->tsstprmd[0];			/* TBCS0119							*/
		
		mo_wlg4(MR_TRCV, WNGPM, mrlog, 4L);		 			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
   	
    	
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
       
  		mrlog[0] = (long)mopcbp->mopscstp->tcsttrcv;		/* TBCS0119							*/
 
   		mo_wlg4(MR_TRCV, WNGPM, mrlog, 4L); 	 			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
        
        lRet = MRNORMX;
    
    	goto exit_to_main;
    }                     				

  
    /********************************************************************************************/
    /*  ���϶�ʬ�����å�							  					                        */
    /********************************************************************************************/

	PRINTF("(2) mr_trcv - tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);
	
#ifndef debug_test
	mopcbp->mopssstp->tsststd0 = KAISHIKU;
#endif

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
			
			mrlog[0] = lRet;								/* TBCS0119							*/
	
			mo_wlg4(MR_TRCV, 0x44440002, mrlog, 4L); 		/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

			if(lRet == MRNORMX)								/* �ե����륢���������顼�ξ��		*/
			{
				lRet = mr_stpr();							/* ���Ͻ���							*/
				
				if(lRet == MRNORMAL)						/* TBCS0156							*/
				{											/* ���ｪλ�Ǥ��äƤ��������ｪλ	*/
					lRet = MRNORMX;							/* TBCS0156							*/
				}
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

	mrlog[0] = lRet;										/* TBCS0119							*/
	
	
	mo_wlg4(MR_TRCV, WOTSC, mrlog, 4L); 					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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
	
	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/

	
 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

	mo_wlg4(MR_REST, WINSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
	mrlog[0] = (long)mrtrcv->trcvspnm;						/* TBCS0119							*/
	
	mrlog[1] = O_RDONLY;									/* TBCS0119							*/
	
	mo_wlg4(MR_REST, WBSYS | OSOPEN, mrlog, 8L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
															

	iFd = open(mrtrcv->trcvspnm, O_RDONLY);					/* �ե�����򥪡��֥󤹤�       	*/

	mrlog[0] = iFd;											/* TBCS0119							*/
	
	mo_wlg4(MR_REST, WASYS | OSOPEN, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_rest - iFd = %ld\n", iFd);			



	if(iFd < MRNORMAL )										/* �ե�����򥪡��ץ󥨥顼			*/
	{
		mo_wlg4(MR_REST, WNGSC, 0, 0);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/
		
		goto error_proc;
	}
	
	lRet = mr_read(iFd, (char*)&lDayTime, STTDATSI);		/* �ե����뤫��ǡ������ɤ߽Ф�		*/
	
	PRINTF("(2) mr_rest - lNowaDay = %lx\n", htonl(lDayTime.lNowaDay));			

	PRINTF("(3) mr_rest - lNowaTime = %lx\n", htonl(lDayTime.lNowaTime));			

	PRINTF("(4) mr_rest - lRet = %ld\n", lRet);			

	

	if(lRet != MRNORMAL)									/* mr_read()�ǥ��顼���Ф����		*/
	{
		mo_wlg4(MR_REST, 0x44440001, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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
	
		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
		mo_wlg4(MR_REST, 0x44440002, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
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

	mrlog[0] = lRet;										/* TBCS0119							*/

	mo_wlg4(MR_REST, WOTSC, mrlog, 4L);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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
/*		MRNOMEM(�Хåե����ݼ���)						�������ɲ� TBCS0156					*/
/*		SYSERROR (FIP�ե����������票�顼)				�������ɲ� TBCS0156					*/
/*														�������ɲ� TBCS0156	SSLA0036 ���	*/
/*		MRNORRCV(�ơ��֥�ꥫ�Х�����»�)				�������ɲ� SSLA0038					*/
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
	
	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/
	
	long lFntRet = 0;										/* TBCS0163							*/
	
 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/
	mo_wlg4(MR_RECV, WINSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	lLen = mopcbp->mopssstp->tsstrc0l;  					/* ���Ѥ��ץơ��֥륵����������		*/

	mrlog[0] = lLen;										/* TBCS0119							*/

	mo_wlg4(MR_RECV, 0x44440001, mrlog, 4L);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_recv - lLen = %ld\n", lLen);			

	sprintf(cMsg, "%.4s", MRMSRR8);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

															/* ���Ѥ��ץơ��֥����Ƭ���ե��å�	*/
	pcTrc0a = (char *)pscparea.psccmadt + mopcbp->mopssstp->tsstrc0a;

	mrlog[0] = (long)pcTrc0a;								/* TBCS0119							*/

	mo_wlg4(MR_RECV, 0x44440002, mrlog, 4L);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
	PRINTF("(2) mr_recv - pcTrc0a = %lx\n", pcTrc0a);			

	lDayTime.lNowaDay = -1;									/* TBCS0163							*/
	
	lDayTime.lNowaTime = -1;								/* TBCS0163							*/

	pcDatabuf = (char*)malloc(lLen);						/* �ꥫ�Х��ѥס���Хåե�			*/
															/* ����ݤ���		SSLA0036 ����	*/

	if(pcDatabuf == NULL)									/* ���ݤ����Ԥλ�	SSLA0036 ����	*/
	{
															/* 					SSLA0036 ���	*/
		
															/* TBCS0119			SSLA0036 ���	*/
		
		mo_wlg4(MR_RECV, 0x44440003, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119			SSLA0036 ����	*/
															
		sprintf(cMsg, "%.4s\tmalloc()\t%08x", MRMSRRC, 0); 	/* TBCS0163			SSLA0036 ����	*/

															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

		lRet = MRNOMEM;

		goto exit_from_recv; 								/* ��λ����							*/
	}
	else
	{
		memset(pcDatabuf, 0x00, lLen); 						/* �ꥫ�Х��ѥס���Хåե���		*/
	}														/* ���������		SSLA0036 �ɲ�	*/


	pcNewData = (char*)malloc(lLen);						/*�����ǡ����Խ��ѥס���Хåե�	*/
															/* ����ݤ���		SSLA0036 ����	*/

															/* 					SSLA0036 ���	*/
	
	if(pcNewData == NULL)									/* ���ݤ����Ԥλ�	SSLA0036 ����	*/
	{
															/* TBCS0119							*/
		
		mo_wlg4(MR_RECV, 0x44440004, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119			SSLA0036 ����	*/
															
		sprintf(cMsg, "%.4s\tmalloc()\t%08x", MRMSRRC, 0);  /* TBCS0163			SSLA0036 ����	*/
		
															/* TBCS0163							*/
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

		lRet = MRNOMEM;
	
		goto exit_from_recv; 								/* ��λ����							*/
	}

	memcpy(pcDatabuf, pcTrc0a, lLen);						/* �����Ѥ��ץơ��֥�����Ƥ򥳥ԡ�	*/

	mrlog[0] = (long)mrtrcv->trcvjpnm;						/* TBCS0119							*/
	
	mrlog[1] = O_RDONLY;									/* TBCS0119							*/
	
	mo_wlg4(MR_RECV, WBSYS | OSOPEN, mrlog, 8L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	iFd = open(mrtrcv->trcvjpnm, O_RDONLY);					/* ���Ѥ�����ե�����򥪡��ץ󤹤�	*/
	
	mrlog[0] = iFd;											/* TBCS0119							*/
		
	mo_wlg4(MR_RECV, WASYS | OSOPEN, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
	PRINTF("(5) mr_recv - iFd = %ld\n", iFd);					

	if(iFd < MRNORMAL )
	{
		mo_wlg4(MR_RECV, WNGSC, 0, 0);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		
		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;
	}

	lRet = mr_read(iFd, (char*)&lDayTime, DATETIME);		/* ���ߤ����դȻ�����ɤ߽Ф�		*/

	PRINTF("(6) mr_recv - lRet = %ld\n", lRet);					

	
	if(lRet < MRNORMAL)
	{
		mrlog[0] = lRet;									/* TBCS0119							*/

		mo_wlg4(MR_RECV, 0x44440005, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		cSysCall = READOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼��							*/
	}

	do 
	{
		memset(pcNewData, 0x00, lLen); 						/* �����ǡ����Խ��ѥ������������*/
															/*					SSLA0036 �ɲ�	*/
		
		memset(&trcvinfo, 0x00, BUDASIZE);					/* ���Ѥ��ǡ����쥳���ɹ�¤�ν����	*/

		lRet = mr_read(iFd, (char*)&trcvinfo, BUDASIZE);	/* ���Ѥ��ǡ������ɹ���				*/
		
		PRINTF("(7) mr_recv - lRet = %ld\n", lRet);					

		if(lRet == SYSERROR)								/* ���Ѥ�����ե����뤬���顼��		*/
		{
			
			mo_wlg4(MR_RECV, 0x44440006, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
			
			memcpy(pcTrc0a, pcDatabuf, lLen);				/* �ơ��֥����������				*/
			
			cSysCall = READOPTI;							/* �����ƥॳ����option				*/
		
			PRINTF("(8) mr_recv - pcTrc0a = %lx\n", pcTrc0a);					
			
			lCount = 0;										/* �쥳���ɿ�����������			*/ 
			
			goto error_proc;								/* ���顼����						*/

		}
		else if(lRet == MRNORMX)	 						/* ���Ѥ�����ե����뤬EOF			*/
		{

			mo_wlg4(MR_RECV, 0x44440007, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

			PRINTF("(9) mr_recv - lRet = %ld\n", lRet);			
			
			lRet = MRNORMAL;
	
			goto exit_from_recv;							/* ��λ����							*/
		}			
		
		lRet = memcmp(&trcvinfo.msg1, STRTPATN, PATNSIZE);	/* ��Ƭ�ѥ����������å�			*/
		
		PRINTF("(10) mr_recv - lRet = %ld\n", lRet);

		 
		if(lRet != MRNORMAL)								/* ��Ƭ�ѥ����󤬽Фʤ����			*/
		{
			mo_wlg4(MR_RECV, 0x44440008, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
															
			lRet = MRNORMAL;								/* SSLA0038	�ɲ�					*/
			
			goto exit_from_recv;							/* ��λ����							*/
		}

		trcvinfo.size = htonl(trcvinfo.size);
		
		trcvinfo.offset = htonl(trcvinfo.offset);
		
		trcvinfo.num = htonl(trcvinfo.num);
		
		mrlog[0] = trcvinfo.size;							/* TBCS0119							*/
		
		mrlog[1] = trcvinfo.offset;							/* TBCS0119							*/
		
		mrlog[2] = trcvinfo.num;							/* TBCS0119							*/
		
		mo_wlg4(MR_RECV, 0x44440009, mrlog, 12L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		
		PRINTF("(10.1) mr_recv - trcvinfo.size = %lx\n", trcvinfo.size);	
		

		lDataSize = mr_intg(trcvinfo.size);					/* 4�ܿ���Ĵ��						*/
		
		PRINTF("(11) mr_recv - lDataSize = %lx\n", lDataSize);					

															/* �����ǡ������ɹ���				*/
		lRet = mr_read(iFd, pcNewData, (lDataSize + PATNSIZE));

		PRINTF("(12) mr_recv - lRet = %ld\n", lRet);					


		if(lRet == SYSERROR)								/* ���Ѥ�����ե����뤬���顼��		*/
		{
			mo_wlg4(MR_RECV, 0x4444000a, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
			
			memcpy(pcTrc0a, pcDatabuf, lLen);
			
			cSysCall = READOPTI;							/* �����ƥॳ����option				*/
	
			PRINTF("(13) mr_recv - lRet = %ld\n", lRet);

			lCount = 0;										/* �쥳���ɿ�����������			*/ 
			
			goto error_proc;								/* ���顼����						*/
			
		}
		else if(lRet == MRNORMX)							/* ���Ѥ�����ե����뤬EOF			*/
		{
			mo_wlg4(MR_RECV, 0x4444000b, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

			PRINTF("(14) mr_recv - lRet = %ld\n", lRet);
			
			lRet = MRNORMAL;

			goto exit_from_recv;							/* ��λ����							*/
		}			

															/* ��ü�ѥ�����Υ����å�			*/
		lRet = memcmp((pcNewData + lDataSize), ENDDPATN, PATNSIZE);

		PRINTF("(15) mr_recv - lRet = %ld\n", lRet);


		if(lRet != MRNORMAL)								/* ��ü�ѥ����󤬤Ǥʤ����			*/
		{
			mo_wlg4(MR_RECV, 0x4444000c, 0, 0);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
			
			lRet = MRNORMAL;
			
			goto exit_from_recv;							/* ��λ����							*/

		}
															/* �ꥫ�Хꤹ��						*/ 
		memcpy( ( (char *)pscparea.psccmadt + trcvinfo.offset ), pcNewData, trcvinfo.size);

		lCount += 1;										/* �쥳���ɿ��򥫥��󥿥��å�		*/
		
		PRINTF("(16) mr_recv - lCount = %ld\n", lCount);
		 
#ifdef debug_test
		PRINTF("(16.1)******recvy trcvinfo.offset = %08x\n", trcvinfo.offset);
		PRINTF("(16.2)******recvy trcvinfo.size = %ld\n", trcvinfo.size);
		PRINTF("(16.3)******recvy lLen = %ld\n", lLen);
		PRINTF("(16.4) mr_recv - pcTrc0a = %08x\n", pcTrc0a);	
		PRINTF("(16.5) mr_recv - pscparea.psccmadt = %08x\n", pscparea.psccmadt);
				
#endif			 
		 
	}while( (long)( (char *)pscparea.psccmadt + trcvinfo.offset ) < (long) (lLen + pcTrc0a) );

	lRet = MRNORMAL;

	mo_wlg4(MR_RECV, 0x4444000d, 0, 0);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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

		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/

		mo_wlg4(MR_RECV, 0x4444000e, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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

	PRINTF("(17.4) mr_recv - lRet = %ld\n", lRet);	


	if( (lRet != MRFILERR) && (lRet != MRNOMEM) )			/* ��Ÿξ�ʳ��ξ���	 TBCS0163	*/
	{
		PRINTF("(18) mr_recv - lRet = %ld\n", lRet);

		lFntRet = mf_srcv(); 								/* TBCS0188							*/

		if(lFntRet == MFERROR)	 							/* FIP�ե������������������ 		*/
		{													/* TBCS0156, TBCS0188				*/
		 	
		//	if(lFntRet != MFNORMX))							/* TBCS0188							*/
		//	{	
				mo_wlg4(MR_RECV, 0x4444000f, 0, 0);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
			
															/* TBCS0156							*/
				PRINTF("(18.1) mr_recv - mf_srcv = %ld\n", lRet);
				
															/* TBCS0163, TBCS0187				*/
				sprintf(cMsg, "%.4s\tmf_srcv\t%08x", MRMSRRC, lFntRet); 

															/* TBCS0163							*/
				ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
				
				lRet = SYSERROR;
		//  }												/* TBCS0188							*/
		
		}
		else if(lFntRet == MFNORMX)							/* TBCS0188							*/
		{
			lRet = MRNORMX;									/* TBCS0188							*/
		}

		/****************************************************************************************/
		/*               SSLA0036 ���� START	2003/07/03                                      */
		/****************************************************************************************/

		if(pcDatabuf != NULL)								/*                      TBCS0156    */
		{
			//lRet = mo_frbf((long*)pcDatabuf);				/* �ס���Хåե��β���	TBCS0156	*/
			
			free(pcDatabuf);								/* 					SSLA0036 �ɲ�	*/

															/* �ס���Хåե��β���	TBCS0156	*/
															/* 					SSLA0036 ���	*/
															/* TBCS0163			SSLA0036 ���	*/

															/* TBCS0163			SSLA0036 ���	*/

															/* �������Ի��ϥ��顼   TBCS0156	*/
															/* 					SSLA0036 ���	*/
		}
		
		if(pcNewData != NULL)								/*                      TBCS0156    */
		{
			//lRet = mo_frbf((long*)pcNewData);				/* �ס���Хåե��β��� TBCS0156    */
						
			free(pcNewData);								/* 					SSLA0036 �ɲ�	*/
			
															/* �ס���Хåե��β��� TBCS0156    */
										 					/*					SSLA0036 ���	*/

															/* TBCS0163			SSLA0036 ���	*/

															/* TBCS0163			SSLA0036 ���	*/

															/* �������Ի��ϥ��顼   TBCS0156	*/
															/* 					SSLA0036 ���	*/
		
		}
	
	}														/*                      TBCS0156    */
		/****************************************************************************************/
		/*               SSLA0036 ���� END	2003/07/03 		                                    */
		/****************************************************************************************/
		
	
	sprintf(cMsg, "%.4s\t%08x\t%06x\t%ld", 
			MRMSRR9, htonl(lDayTime.lNowaDay), htonl(lDayTime.lNowaTime), lCount);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	if( (lRet == MRNORMAL) && (lCount > 0) )				/* SSLA0038	�ɲ�					*/
	{
		lRet = MRNORRCV;									/* SSLA0038	�ɲ�					*/
	}

	PRINTF("(19) mr_recv - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_RECV, WOTSC, mrlog, 4L);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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
    
    
   	mo_wlg4(MR_KAIH, WINSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	sprintf(cMsg, "%.4s", MRMSRRA);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	mopcbp->mopssstp->tsststd0 = KAISHIKU;					/* ���Ω���夲						*/
	
	PRINTF("(1) mr_kaih - EXIT tsststd0 = %c\n", mopcbp->mopssstp->tsststd0);

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

	mo_wlg4(MR_KAIH, WOTSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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

	long mrlog[2];											/* �������Խ��ΰ� TBCS0119		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/
   	mo_wlg4(MR_FRCE, WINSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/


	lRet = syscom_get_bootmode();							/* ���Ѽԥ⡼��Ƚ��					*/
	
	PRINTF("(1) mr_frce - lRet = %c\n", lRet);
	

	if(lRet == ENDONWAY)
	{
		
		mrlog[0] = lRet;									/* TBCS0119							*/

	   	mo_wlg4(MR_FRCE, 0x44440001, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		
		sprintf(cMsg, "%.4s", MRMSRRB);
	
		ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
		
		mopcbp->mopssrtp->tsrtdvst = TSRTEND;				/* �Ÿ��Ǥ����ꤹ��					*/
		
		PRINTF("(2) mr_frce - tsrtdvst = %c\n", mopcbp->mopssrtp->tsrtdvst);
	}

	PRINTF("(3) mr_frce - EXIT lRet = %c\n", lRet);
	
	mo_wlg4(MR_FRCE, WOTSC, 0, 0);							/* TBCS0119							*/

	return;
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	long	 mr_inff()																*/
/*																								*/
/*	�㵡ǽ���ס� ���Ѥ�����ե�����γ��Ͻ���													*/
/*  																							*/
/*	�꥿����:																					*/
/*		MRNORMAL																				*/
/*		MRFILERR																				*/
/*		MRNORMX		��������ｪλ									�������ɲ� TBCS0156		*/
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

	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/

    
   	mo_wlg4(MR_INFF, WINSC, 0, 0);							/* TBCS0119							*/
    
    														/*	TBCS0119						*/
   // iFd = open(mrtrcv->trcvjpnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);
   
    mrlog[0] = (long)mrtrcv->trcvjpnm;						/* TBCS0119							*/
   	
    mrlog[1] = (O_WRONLY | O_TRUNC | O_CREAT | O_SYNC); 	/* TBCS0119						*/
	
	mrlog[2] = (S_IRWXU | S_IROTH | S_IRGRP);				/* TBCS0119							*/
	
	mo_wlg4(MR_INFF, WBSYS | OSOPEN, mrlog, 12L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

    sprintf(cMsg, "%.4s\t%s", MRMSRR4, mrtrcv->trcvjpnm);	/* TBCS0200 						*/

															/* TBCS0200 						*/
    ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN); 

    
    														/* TBCS0119							*/
    iFd = open(mrtrcv->trcvjpnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC, S_IRWXU | S_IROTH | S_IRGRP);
    
    mrlog[0] = iFd;											/*	TBCS0119						*/
    
  	mo_wlg4(MR_INFF, WASYS | OSOPEN, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	PRINTF("(1) mr_inff - iFd = %ld\n", iFd);

	PRINTF("(1.2) mr_inff - mrtrcv = %08x\n", mrtrcv);

															/* TBCS0200 ���					*/
	
															/* TBCS0200 ���					*/

	if(iFd < MRNORMAL )										/* �ե����뤬���顼�ξ��			*/
	{

	  	mo_wlg4(MR_INFF, WNGSC, 0, 0);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		PRINTF("(2) mr_inff - iFd = %ld\n", iFd);

		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼����						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* �������ջ�������				*/
	
	mrlog[0] = lRet;										/* TBCS0119							*/

   	mo_wlg4(MR_INFF, 0x44440001, mrlog, 4L);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
	lTime &= 0x00FFFFFF; 									/* hhmmss�������ѹ�����				*/
	
	PRINTF("(3) mr_inff - lDay = %.8x\n", htonl(lDay));

	PRINTF("(4) mr_inff - lTime = %.6x\n", htonl(lTime));

	lDayTime.lNowaDay = htonl(lDay);						/* ���դ����ꤹ��					*/
	
	lDayTime.lNowaTime = htonl(lTime);						/* ��������ꤹ��					*/

	lRet = mr_writ(iFd, (char*)&lDayTime, DATETIME);		/* �������ջ����ե�����˽񤭹��� */
	 
	PRINTF("(5) mr_inff - lRet = %ld\n", lRet);
	

 	if(lRet  != MRNORMAL)									/* �ե����뤬���顼�ξ��			*/
 	{
	  	mo_wlg4(MR_INFF, 0x44440002, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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

		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
	  	mo_wlg4(MR_INFF, 0x44440003, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		lRet = MRFILERR;
		
		PRINTF("(7.2) mr_inff - lRet = %ld\n", lRet);

	}
	else
	{
		
		//lRet = MRNORMAL;
		lRet = MRNORMX;										/* TBCS0156							*/
		
		PRINTF("(7.3) mr_inff - lRet = %ld\n", lRet);
	}

//	lRet = (mopcbp->mopscstp->tcst2err != TCST2NDW) ? MRFILERR : MRNORMAL;
	
	PRINTF("(7.4) mr_inff - lRet = %ld\n", lRet);

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_from_inff:

	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_INFF, WOTSC, mrlog, 4L);						/* TBCS0119							*/

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
/*		MRNORMX		��������ｪλ									�������ɲ� TBCS0156		*/
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
	
	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/


 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/
    
   	mo_wlg4(MR_STTF, WINSC, 0, 0);							/* TBCS0119							*/

															
  	// iFd = open(mrtrcv->trcvspnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC);
  	
  		
    mrlog[0] = (long)mrtrcv->trcvspnm;						/* TBCS0119							*/
   	
    mrlog[1] = (O_WRONLY | O_TRUNC | O_CREAT | O_SYNC); 	/* TBCS0119						*/
	
	mrlog[2] = (S_IRWXU | S_IRWXG | S_IRWXO);				/* TBCS0119							*/
	
	mo_wlg4(MR_STTF, WBSYS | OSOPEN, mrlog, 12L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

    sprintf(cMsg, "%.4s\t%s", MRMSRR6, mrtrcv->trcvspnm);	/* TBCS0200        					*/

															/* TBCS0200 						*/
    ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN); 


															/* TBCS0119							*/
    iFd = open(mrtrcv->trcvspnm, O_WRONLY | O_TRUNC | O_CREAT | O_SYNC, S_IRWXU | S_IROTH | S_IRGRP);
    
    mrlog[0] = iFd;
    
  	mo_wlg4(MR_STTF, WASYS | OSOPEN, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
  
  	PRINTF("(1) mr_sttf - iFd = %ld\n", iFd);
  	
	PRINTF("(1.1) mr_stff - filename = %s\n", mrtrcv->trcvspnm);
	
	PRINTF("(1.3) mr_stff - mrtrcv = %08x\n", mrtrcv);

															/*TBCS0200	���					*/
	
															/*TBCS0200	���					*/


	if(iFd < MRNORMAL )										/* �ե����뤬���顼�ξ��			*/
	{

	  	mo_wlg4(MR_STTF, WNGSC, 0, 0);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		cSysCall = OPENOPTI;								/* �����ƥॳ����option				*/

		goto error_proc;									/* ���顼����						*/
	}

	lRet = mo_date(&lDay, &lTime);							/* ���ջ������					*/
	
	mrlog[0] = lRet;										/* TBCS0119							*/

   	mo_wlg4(MR_STTF, 0x44440001, mrlog, 4L);				/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
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
	  	mo_wlg4(MR_STTF, 0x44440002, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		
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
		
		mrlog[0] = (long)mopcbp->mopscstp->tcst2err;		/* TBCS0119							*/
		
	  	mo_wlg4(MR_INFF, 0x44440003, mrlog, 4L);			/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
		lRet = MRFILERR;
		
		PRINTF("(9.2) mr_sttf - lRet = %ld\n", lRet);

	}
	else
	{
		//lRet = MRNORMAL;
		lRet = MRNORMX;										/* TBCS0156							*/
		PRINTF("(9.3) mr_sttf - lRet = %ld\n", lRet);
	}

															
	PRINTF("(9.4) mr_sttf - lRet = %ld\n", lRet);
														
 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_from_sttf:

	PRINTF("(10) mr_sttf - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;										/* TBCS0119							*/
	
	mo_wlg4(MR_STTF, WOTSC, mrlog, 4L);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

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
/*			MRFILERR	�ե����륢���������顼							�������ɲ� TBCS0156	*/
/*			MRNORMX		��������ｪλ									�������ɲ� TBCS0156	*/
/************************************************************************************************/
long mr_stpr()
{

	long lRet = MRNORMAL;									/* �ֵ���							*/

	long lRet1 = MRNORMAL;									/* ���֥ե�������ֵ��� TBCS156		*/
	
	long mrlog[5];											/* �������Խ��ΰ�	TBCS0119		*/

 	/********************************************************************************************/
    /*  �ܽ���																					*/
    /********************************************************************************************/
    
   	mo_wlg4(MR_STPR, WINSC, 0, 0);							/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/
	
	lRet = mr_inff();										/* ���Ѥ�����ե�����ν��������	*/
	
	PRINTF("(1) mr_stpr - lRet = %ld\n", lRet);



	//if(lRet != MRNORMAL)
	if(lRet == MRFILERR)									/* TBCS0156							*/
	{
  	 	mo_wlg4(MR_STPR, 0x44440001, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		goto exit_to_main;									/* ��λ����							*/
	}

	lRet1 = mr_sttf();										/* ���Ѥ����֥ե�����ν��������	*/
	
	PRINTF("(2) mr_stpr - lRet = %ld\n", lRet);
	

	//f(lRet != MRNORMAL)									
	if(lRet1 == MRFILERR)									/* TBCS0156							*/
	{
 	 	mo_wlg4(MR_STPR, 0x44440002, 0, 0);					/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

		goto exit_to_main;									/* ��λ����							*/
	}

	mr_frce();												/* SMP ������λ����					*/

 	/********************************************************************************************/
    /*  ��λ����																				*/
    /********************************************************************************************/

exit_to_main:

	
	lRet |= lRet1; 											/* TBCS0156							*/
	
	if(lRet > MRNORMX)										/* TBCS0156							*/
	{
		lRet = MRNORMX;										/* TBCS0156							*/
	}

	PRINTF("(2) mr_stpr - EXIT lRet = %ld\n", lRet);
	
	mrlog[0] = lRet;

	mo_wlg4(MR_STPR, WOTSC, mrlog, 4L);						/* �ؿ�̾�������̻ҡ�				*/
															/* ����������Ƭ���ɥ쥹����������Ĺ	*/
															/* TBCS0119							*/

	//return(MRNORMAL); 
	return( lRet );											/* TBCS0156							*/
	
}

