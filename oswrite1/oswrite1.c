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
/* �㥵���ӥ�����̾��				 ������													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 ��å���������												*/
/* ��⥸�塼��ɣġ�				 oswrite1													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 ���ץ饤����												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤����												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*																�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤����												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*                                                              								*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�֥ǡ�����Ǽ�Хåե��פ˳�Ǽ���줿��å���������ʸ������Ƭ�����ʸ���ˤ�KEY�Ȥ���		*/
/*		��ͭ������Ÿ������Ƥ��륳�󥽡�������ѡ����ե���������ѡ�����ץ��������Ѥ�	*/
/*		��å������ե����ޥåȤ�����������줾����ϥ�å������Խ���Ԥ���						*/
/*		�Խ���λ��˽��ϥ�å������򡢡֥�å��������ϻؼ�ʸ���פ˽�����						*/
/*		���󥽡��롿���ե����롿����Υץ������Ф��ƥ�å��������Ϥ�Ԥ���					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oswrite1.h>																*/
/*																								*/
/*      long oswrite1(long fildes, char *buf, long len)                                         */
/*																								*/
/* �㲾������																					*/
/*      long fildes        �ե����뵭�һ�                     							        */
/*      char *buf          �ǡ�����Ǽ�Хåե���NULL�ʳ���                              			*/
/*      long len           ����ǡ�����������0�ʾ��                              				*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			0x0000XXXX															*/
/*		�۾ｪλ			0x940dXXXX															*/
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
#include <sys/time.h>
#include <syslog.h> 
#include <errno.h>


/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include "oswrite1.h"
#include "oswrite1_ins.h"


/************************************************************************************************/
/*	�����ؿ�											             							*/
/*																								*/
/************************************************************************************************/
void os_GetBufMsg(char*, long);
void os_EditString(char*, char*, long, long);
void os_GetStrPos(char*, char, long*, long*, long);
void os_ChangeCode(char*, short*, long, long, char*);
void os_GetLogMsg(char*, char*, char*, long);
void os_GetMsg(char*, char*, char**, long, short*, long);
long os_SeekStr(char*, char, long, long);
long os_Time(long*, long*);
long os_SearchJIS(short*, long, long, long);
long os_MsgOut(char*, char*, char*);
long os_SearchMsgID(TEmmcTableInd*, long, char*);
long os_SendCon(char*, char[], long, long, long);
long os_SendLog(char*, char[], long, long, long);
long os_SendProc(char*, char[], long, long, long);
int  os_ChgFacCode(int);
int  os_ChgPriority(char*);

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	 oswrite1(long fildes, char *buf, long len)										*/
/*																								*/
/*	�㵡ǽ���ס� ��å���������                     											*/
/*  																							*/
/*  �ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1) - �ե����뵭�һ�														*/
/*		�ѥ�᡼����(2)	- �ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(3)	- ����ǡ���������														*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (NORMAL)																			*/
/*		���� (D_OSWRITE1_NULL_BUFFER) or (OSEEWKEX) or (D_OSWRITE1_OUTPUT_ERROR)				*/
/*																								*/
/*																								*/
/************************************************************************************************/
long oswrite1(long fildes, char *buf, long len)
{

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lResult = 0x00000000;								// �꡼������
		
	long lRetForLog = 0x00000000;							// sendlog()���ֵ���
	
	long lRetForPrc = 0x00000000;							// sendProc()���ֵ���
	
	long lRetForCon = 0x00000000;							// sendCon()���ֵ���
	
	long lRetForTime = 0;									// Time()���ֵ���
	
	long lmm = 0;											// ʬ�ο���
	
	long lhr = 0;											// ���ο���
	
	char pcTmpBufMsgId[4];									// ��å��������̻�
	

//	DbgMsg01( DLv04, ( OutPut, " (1) IN ****\n" ) );

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_IN, 3, fildes, buf, len );
	
	/********************************************************************************************/
	/*	 �������																				*/
	/********************************************************************************************/
	/*---------------------------------------*/
	/*  �����γ�ǧ                           */
	/*---------------------------------------*/
	if (NULL == buf)										// �ǡ�����Ǽ�Хåե���NULL�ξ��
	{
		lResult = ERR_HEADER | DAT_ERROR;
		
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, lResult );
		
		return(lResult);									// �۾��å��������ֵ�
	} 
	
	if (len < 1)											// �񤭹��ߥХ��ȿ���1�ʾ�ʤ����
	{
		lResult = ERR_HEADER | SIZ_ERROR;
		
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, lResult );
		
		return(lResult);									// �۾��å��������ֵ�
	}  

	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	/******************************************/
	/* ��å������Խ����Ͻ��� 				  */
	/******************************************/
	
	lRetForTime = os_Time(&lhr, &lmm);						// �����ƥ���֤���
	
//	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (2)\n" ) );
	
	if(lRetForTime !=NORMAL)								// ���֤����ʤ����
	{
		lResult = ERR_HEADER | INV_ERROR;
	
		os_trcget2( D_MD_OSWRITE1, D_T_ERR_SYS, 1, lResult );
	
		return(lResult);									// ���顼����
	}
	
//	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (3)\n" ) );

	
	memset(pcTmpBufMsgId, 0x00, 4);						// TBCS0153/TBCS0155
	
	if(len >= 4)										// TBCS0153/TBCS0155
	{
		strncpy(pcTmpBufMsgId, buf, 4);					// �ǡ�����Ǽ�Хåե�����
														// ��å��������̻Ҥ���
	}
	else												// TBCS0153/TBCS0155
	{
		strncpy(pcTmpBufMsgId, buf, len);				// TBCS0153/TBCS0155
	}

	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (5) pcTmpBufMsgId == %c%c%c%c\n", 
	         pcTmpBufMsgId[0], pcTmpBufMsgId[1], pcTmpBufMsgId[2], pcTmpBufMsgId[3] ) );

	/********************************************/
	/* ���ե���������ѥ�å������Խ����Ͻ��� */
	/********************************************/
															// ���ե��������
															// ��å������ν���
	lRetForLog = os_SendLog(buf, pcTmpBufMsgId, lhr, lmm, len);
	
	
	if(lRetForLog > LOG_NORMAL)							// ���ϤǤ��ʤ����
	{
		lRetForLog = lRetForLog | LOG_ERROR;
	}
	
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (6) lRetForLog == %08lx\n", lRetForLog) );

	
	/********************************************/
	/* ����ץ����̿��ѥ�å������Խ����Ͻ��� */
	/********************************************/		
															// ����ץ�������
															// ��å������ν���
	lRetForPrc = os_SendProc(buf, pcTmpBufMsgId, lhr, lmm, len);
	
	
	if(lRetForPrc > PRC_NORMAL)								// ���ϤǤ��ʤ����
	{
		lRetForPrc = lRetForPrc | PRC_ERROR ;		
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (7) lRetForPrc == %08lx\n", lRetForPrc) );
	
	/********************************************/
	/* ���󥽡�������ѥ�å������Խ����Ͻ���   */
	/********************************************/
															// ����ץ�������
															// ��å������ν���
	lRetForCon = os_SendCon(buf, pcTmpBufMsgId, lhr, lmm, len);		
	
	
	if(lRetForCon > CON_NORMAL)								// ���ϤǤ��ʤ����
	{
		lRetForCon = lRetForCon | CON_ERROR;
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (8) lRetForCon == %08lx\n", lRetForCon) );
	
	/********************************************************************************************/
	/*	 ������λ																				*/
	/********************************************************************************************/
	
	 lResult = lRetForCon | lRetForPrc | lRetForLog;
	
	 //if(0x00000007 != lResult)
	 if(lResult > 0x00000007)
	 {
	 	lResult = lResult | ERR_HEADER;
	 } 
	 

	DbgMsg01( DLv04, ( OutPut, "*** oswrite1 (9) lResult  == %08lx\n", lResult ) );

//	DbgMsg01( DLv04, ( OutPut, "**** oswrite1 (10) OUT ****\n" ) ); 

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, lResult );
	
	return (lResult);


}




/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��long os_SendCon(char *buf, char pcTmpBufMsgId[], long lhr, 						*/
/*                            long lmm, long lBufLen)											*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���󥽡�������ѥ�å������Խ����Ͻ���											*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1) - �ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(2)	- ��å��������̻�														*/
/*		�ѥ�᡼����(3)	- ���ο���																*/
/*		�ѥ�᡼����(4)	- ʬ�ο���																*/
/*		�ѥ�᡼����(5)	- �ǡ�����Ǽ�Хåե�������												*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (NORMAL)																			*/
/*		���� (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendCon(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	
	long lRet = 0;											// ��å��������̻Ҹ������ֵ���
	
	long lRetForSend = 0x00000000;							// ��å������������ֵ���
	
	long lRetForSPrintf = 0;								// sprintf���ֵ���
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// ��å��������ϻؼ�ʸ��

	char *pcTmpMsg = NULL;									// ���ϥ�å�����
	
	char *pcFormatMsg = NULL;								// ��å��������ɥ쥹
	
	char pcPriority[8];										// �ץ饤����ǥ�
		
	char cNotFoundMsg[100];									// ���̻Ҥ��ʤ��Ȥ���
															// ���ϥ�å�����

	char *pcTmpForMsg = NULL;	
	
	TEmmcTableInd *ptEmmcInd = NULL;						// ��å����������ơ��֥�
	
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	/******************************************/
	/* ��å������򸡺�����					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptConAdr; 			// ���󥽡������
															// ��å��������ɥ쥹������
															
//	DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (1)\n" ) );						
										
															// ��å��������̻Ҥθ���
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lConCnt, pcTmpBufMsgId);
	
	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendCon (1.1) after os_SearchMsgID\n") );
	
	if(lRet < 0)											// ��å��������̻Ҥ����Ĥ���
	{														// �ʤ��ä����
	
															// ���ϥ�å��������ΰ��Ȥ�
//		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (3)\n" ) );
		
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (4) Get into Not Found \n") );	
		
		
															// not found��å��������Խ�
		lRetForSPrintf = sprintf(cNotFoundMsg, "[ERR    ] %.2d:%.2d KO00* CMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], pcTmpBufMsgId[2],
		                         pcTmpBufMsgId[3]);
		
		if(lRetForSPrintf < 0)
		{
			
			return(CON_ERROR);
		}
	
															// ���Ϥ���
		lRetForSend = os_MsgOut(cNotFoundMsg, D_SG_EMMC_CONSOLE, "ERR"); 
		
		if(lRetForSend != NORMAL)							// ���ϤǤ��ʤ����
		{
			return(lRetForSend);							// ���顼����		
		}
	
	}
	else
	{
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (5)\n") );

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// ���󥽡�������ѥ�å�����
															// ���ɥ쥹������

		lMsgLen = strlen(pcFormatMsg);						// ��å����������ơ��ָ�������
															// ��å������ե����ޥåȾ���
															// ���ɥ쥹�Υ�����
															
															
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );		
															
															// TBCS0123	
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
		
															// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// ���Ѥ��Խ����륵����ʬ=����*2
															// ����,���ڡ���,[]�Υ�����ʬ=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );	
															
		/******************************************/
		/* ��å��������Խ�����					  */
		/******************************************/
															// ��å��������Խ�
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sConAfter, lMsgLen);
		
		cMsgOutFlg = pcFormatMsg[12];						// ��å��������ϻؼ�ʸ��������

		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (6) pcTmpMsg == %s\n", pcTmpMsg) );
		
															// �ץ饤����ǥ����ΰ�����

		strncpy(pcPriority, pcFormatMsg, 7);				// �ץ饤����Ǥ����
		
		pcPriority[7]='\0';


		
		lRetForSPrintf = sprintf( pcTmpForMsg, "[%s] %.2d:%.2d %s", 
								pcPriority, lhr, lmm, pcTmpMsg);
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (7) pcFormatMsg == %s\n", pcFormatMsg) );
		
		if(lRetForSPrintf < 0)								// ���ϥ�å��������Խ�
		{													// ���Ǥ��ʤ��ä����
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );

			free(pcTmpMsg);									// �ΰ�����
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
			
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(CON_ERROR);								// ���顼����
			
		} 
		
		/******************************************/
		/* ��å����������						  */
		/******************************************/
		if(cMsgOutFlg == '*')								// ���ϻؼ�ʸ����������
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendCon  (8) cMsgOutFlg == %c\n", 
					cMsgOutFlg) );	
			
															// ��å���������Ϥ���	
			lRetForSend = os_MsgOut(pcTmpForMsg, D_SG_EMMC_CONSOLE, pcPriority);
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendCon (9) lRetForSend == %ld\n", 
					lRetForSend) );	
			
			if(lRetForSend != NORMAL)						// ���ϤǤ��ʤ����
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );

				free(pcTmpMsg);								// �ΰ�����
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
				
				free(pcTmpForMsg);
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
				return(lRetForSend);						// ���顼����
			}
		}
		else
		{
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// �ΰ�����
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(NO_MSGSEND);
		}	
				
	}	
	
	
//	DbgMsg01( DLv04, ( OutPut, "#### os_SendCon return to Normal(10) pcTmpMsg == %s\n", 
//				pcTmpMsg) );
															
	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// �ΰ�����
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
			
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	return(CON_NORMAL);
	
}




/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��long os_SendLog(char *buf, char pcTmpBufMsgId[], long lhr, long lmm,              */
/*                            long lBufLen)	                                                    */
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���ե���������ѥ�å������Խ����Ͻ���										*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1) - �ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(2)	- ��å��������̻�														*/
/*		�ѥ�᡼����(3)	- ���ο���																*/
/*		�ѥ�᡼����(4)	- ʬ�ο���																*/
/*		�ѥ�᡼����(5)	- �ǡ�����Ǽ�Хåե�������												*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (NORMAL)																			*/
/*		���� (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendLog(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRet = 0;											// ��å��������̻Ҹ������ֵ���
	
	long lRetForSend = 0x00000000;							// ��å������������ֵ���
	
	long lRetForSPrintf = 0;								// sprintf���ֵ���
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// ��å��������ϻؼ�ʸ��

	char *pcFormatMsg = NULL;								// ��å��������ɥ쥹
	
	char pcPriority[8];										// �ץ饤����ǥ�
		
	char *pcTmpMsg = NULL;									// ���ϥ�å�����

	char cNotFoundMsg[100];									// ���̻Ҥ��ʤ��Ȥ��ν��ϥ�å�����

	TEmmcTableInd *ptEmmcInd = NULL;						// ��å����������ơ��֥�
	
	char *pcTmpForMsg = NULL;	
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	/******************************************/
	/* ��å������򸡺�����					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptLogAdr; 			// ���ե��������
															// ��å��������ɥ쥹������
															
//	DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (1)\n" ) );	
															// ��å��������̻Ҥθ���
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lLogCnt, pcTmpBufMsgId);

//	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendLog (2) After os_SearchMsgID\n" ) );

	
	if(lRet < 0)											// ��å��������̻Ҥ�
	{														// ���Ĥ���ʤ��ä����

		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (3) Get into Not Found \n") );	
		
	
		
															// not found��å��������Խ�
		lRetForSPrintf = sprintf(cNotFoundMsg, 
								 "[ERR    ] %.2d:%.2d KO00* LMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], 
								 pcTmpBufMsgId[2], pcTmpBufMsgId[3]);
		
		if(lRetForSPrintf < 0)
		{
			return(LOG_ERROR);
		}
					
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (5) pcTmpMsg == %s\n", pcTmpMsg) );

															//����
		lRetForSend = os_MsgOut(cNotFoundMsg, D_SG_EMMC_SYSLOG, "ERR"); 
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (6) lRetForSend == %d\n", lRetForSend) );

		if(lRetForSend != NORMAL)							// ���ϤǤ��ʤ����
		{
						
			return(lRetForSend);
		}
	
	}
	else
	{

		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7)\n") );
			

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// ���ե���������ѥ�å��������ɥ쥹
															// ������
															
		lMsgLen = strlen(pcFormatMsg);						// ��å����������ơ��ָ�������
															// ��å������ե����ޥåȾ��󥢥ɥ쥹
															// �Υ�����
		
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
		
															// TBCS0123
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);

																	// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// ���Ѥ��Խ����륵����ʬ=����*2
															// ����,���ڡ���,[]�Υ�����ʬ=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );	
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7.1) lMsgLen == %ld\n", lMsgLen) );	
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (7.2) lBufLen == %ld\n", lBufLen) );	
													
		/******************************************/
		/* ��å��������Խ�����					  */
		/******************************************/
		cMsgOutFlg = pcFormatMsg[12];						// ��å��������ϻؼ�ʸ��������
		
															// ��å��������Խ�
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sConAfter, lMsgLen);
		
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (8) pcTmpMsg == %s\n", pcTmpMsg) );
		
		if( (cMsgOutFlg == '$') || (cMsgOutFlg == '&') )	// ���ϻؼ�ʸ����������
		{ 
			os_GetLogMsg(buf, pcFormatMsg, pcTmpMsg, lBufLen);	// ���վ�������
		}
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (9) pcTmpMsg == %s\n", pcTmpMsg) );
		
		strncpy(pcPriority, pcFormatMsg, 7);				// �ץ饤����Ǥ����
		
		pcPriority[7]='\0';
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (10) pcPriority == %s\n", pcPriority) );
		
															// ���ϥ�å��������Խ�
		lRetForSPrintf = sprintf( pcTmpForMsg, "[%s] %.2d:%.2d %s", 
								pcPriority, lhr, lmm, pcTmpMsg);
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (11) pcTmpForMsg == %s\n", 
				pcTmpForMsg) );	
			
		if(lRetForSPrintf < 0)								// ���ϥ�å��������Խ���
		{													// �Ǥ��ʤ��ä����
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// �ΰ�����
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );	
				
			free(pcTmpForMsg);
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(LOG_ERROR);								// ���顼����
		} 
		
		
		/******************************************/
		/* ��å����������						  */
		/******************************************/
		
		if( (cMsgOutFlg == '$') || (cMsgOutFlg == '&') )	// ���ϻؼ�ʸ����������
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (12) cMsgOutFlg == %c\n", cMsgOutFlg) );	
															
															// ��å���������Ϥ���	
			lRetForSend = os_MsgOut(pcTmpForMsg, D_SG_EMMC_SYSLOG, pcPriority);
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendLog (13) lRetForSend == %ld\n", 
					lRetForSend) );	
			
			
			if(lRetForSend != NORMAL)							// ���ϤǤ��ʤ����
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
				free(pcTmpMsg);									// �ΰ�����
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
				
				free(pcTmpForMsg);
			
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

				return(lRetForSend);							// ���顼����
			}
		}
		else
		{
			/******************************************/
			/* ��å���������Ϥ��ʤ�				  */
			/******************************************/
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);										// �ΰ�����
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			return(NO_MSGSEND);
		}
		
	}	

															
	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// �ΰ�����
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	return(LOG_NORMAL);
	
}

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��long os_SendProc(char *buf, char pcTmpBufMsgId[], long lhr, 						*/
/*							  long lmm, long lBufLen)											*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ����֥��������ѥ�å������Խ����Ͻ���										*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1) - �ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(2)	- ��å��������̻�														*/
/*		�ѥ�᡼����(3)	- ���ο���																*/
/*		�ѥ�᡼����(4)	- ʬ�ο���																*/
/*		�ѥ�᡼����(5)	- �ǡ�����Ǽ�Хåե�������												*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (NORMAL)																			*/
/*		���� (D_OSWRITE1_OUTPUT_ERROR) 															*/
/*																								*/
/*																								*/
/************************************************************************************************/
long os_SendProc(char *buf, char pcTmpBufMsgId[], long lhr, long lmm, long lBufLen)	
{
		
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/

	long lRet = 0;											// ��å��������̻Ҹ������ֵ���
	
	long lRetForSend = 0;									// ��å������������ֵ���
	
	long lRetForSPrintf = 0;								// sprintf���ֵ���
	
	long lTmpProcOutLen = 0;
	
	long lMsgLen = 0;
	
	char cMsgOutFlg;										// ��å��������ϻؼ�ʸ��

	char *pcTmpMsg = NULL;									// ���ϥ�å�����
	
	char *pcFormatMsg = NULL;								// ��å��������ɥ쥹
	
	char cNotFoundMsg[100];									// ���̻Ҥ��ʤ��Ȥ��ν��ϥ�å�����
	
	TEmmcTableInd *ptEmmcInd = NULL;						// ��å����������ơ��֥�
	
	char *pcTmpForMsg = NULL;	
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	/******************************************/
	/* ��å������򸡺�����					  */
	/******************************************/
	ptEmmcInd = (TEmmcTableInd*)ptEmmc->ptProcAdr; 			// ����֥�������
															// ��å��������ɥ쥹������
															
	DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1.1) \n" ) );						
										
															// ��å��������̻Ҥθ���
	lRet = os_SearchMsgID(ptEmmcInd, ptEmmc->lProcCnt, pcTmpBufMsgId);
	
//	DbgMsg01( DLv04, ( OutPut, "\n*** os_SendProc (1.2) after os_SearchMsgID\n") );
	
	if(lRet < 0)											// ��å��������̻Ҥ�
	{														// ���Ĥ���ʤ��ä����

		/******************************************/
		/* ����ץ������̻ҥ���å�			  */
		/******************************************/
	
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (0) \n" ) );	
	
		if(0 == ptEmmc->lPCode)
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1) ptEmmc->lPCode == %ld\n", 
					ptEmmc->lPCode ) );	
		
			os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, PRC_ERROR );
			
			return(PRC_ERROR);
		}	

	
//		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (2)\n" ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (3) Get into Not Found \n") );	

		memset(cNotFoundMsg, 0x00, 1);

															// not found��å��������Խ�
		lRetForSPrintf = sprintf(cNotFoundMsg+1, "%.2d:%.2dKO00* SMES %c%c%c%c not found", 
								 lhr, lmm, pcTmpBufMsgId[0], pcTmpBufMsgId[1], 
								 pcTmpBufMsgId[2], pcTmpBufMsgId[3]);
					
		DbgDmp02( DLv04, ("## sprintf�� ", cNotFoundMsg, lRetForSPrintf+1,1,0));						 

		if(lRetForSPrintf < 0)								// ���ϥ�å��������Խ�
		{													// ���Ǥ��ʤ��ä����
			os_trcget2( D_MD_OS_SENDPROC, D_T_ERR_SYS, 1, PRC_ERROR );
			
			return(PRC_ERROR);
		}

		lTmpProcOutLen = lRetForSPrintf + 1;
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (3.1) lTmpProcOutLen == %ld\n", lTmpProcOutLen) );
		
															// �����ؿ��ǥ�å�����������
		lRetForSend = ossenms(ptEmmc->lPCode, lTmpProcOutLen, cNotFoundMsg);
		

		if(lRetForSend != NORMAL)							// ���ϤǤ��ʤ����
		{
			os_trcget2( D_MD_OS_SENDPROC, D_T_ERR_SYS, 1, INV_ERROR );
			
			return(INV_ERROR);								// ���顼����
		}
	
	}
	else
	{

		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (4)\n") );

		pcFormatMsg = (ptEmmcInd + lRet)->pcFormatAdr;		// ����֥���������
															// ��å��������ɥ쥹������
															
		lMsgLen = strlen(pcFormatMsg);						// ��å����������ơ��ָ�������
															// ��å������ե����ޥå�
															// ���󥢥ɥ쥹�Υ�����
															
															
//		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
		
															// TBCS0123
//		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);


															// TBCS0153/TBCS0155
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
															// TBCS0153/TBCS0155
															// ���Ѥ��Խ����륵����ʬ=����*2
															// ����,���ڡ���,[]�Υ�����ʬ=9
		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
		
		os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpForMsg );		
		
															
		/******************************************/
		/* ��å��������Խ�����					  */
		/******************************************/
															// ��å��������Խ�
		os_GetMsg(pcFormatMsg, buf, &pcTmpMsg, lBufLen, sProAfter, lMsgLen);
		
		cMsgOutFlg = pcFormatMsg[12];
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (6) cMsgOutFlg == %c\n", cMsgOutFlg) );
		
		
		memset(pcTmpForMsg, 0x00, 1);
		
															// ���ϥ�å��������Խ�
		lRetForSPrintf = sprintf(pcTmpForMsg+1, "%.2d:%.2d%s", lhr, lmm, pcTmpMsg);
		
		DbgDmp02( DLv04, ("## sprintf�� ", pcTmpForMsg, lRetForSPrintf+1,1,0));
		
		DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (7) pcTmpForMsg == %s\n", 
				pcTmpForMsg) );
				
		
		if(lRetForSPrintf < 0)								// ���ϥ�å��������Խ�
		{													// ���Ǥ��ʤ��ä����
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
			
			free(pcTmpMsg);									// �ΰ�����
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
				
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
			
			return(PRC_ERROR);								// ���顼����
			
		} 
		
		/******************************************/
		/* ��å����������						  */
		/******************************************/
		if(cMsgOutFlg == '*')								// ���ϻؼ�ʸ����������
		{
	
			/******************************************/
			/* ����ץ������̻ҥ���å�			  */
			/******************************************/
	
//			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (0) \n" ) );	
	
			if(0 == ptEmmc->lPCode)
			{
				DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (1) ptEmmc->lPCode == %ld\n", ptEmmc->lPCode ) );	
		
				os_trcget2( D_MD_OSWRITE1, D_T_ERR_PRA, 1, PRC_ERROR );
			
				return(PRC_ERROR);
			}	
	
	
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8) lTmpProcOutLen  == %d\n", 
					lTmpProcOutLen ) );
					
					
			lTmpProcOutLen = lRetForSPrintf + 1;			// ���ϥ�å������Υ���������			
			
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8.1) lTmpProcOutLen == %ld\n", lTmpProcOutLen) );			
					
			DbgMsg01( DLv04, ( OutPut, "*** os_SendProc (8.2) ptEmmc->lPCode  == %08x\n", 
					ptEmmc->lPCode ) );	
					
			
															// �����ؿ��ǥ�å����������� 
			lRetForSend = ossenms(ptEmmc->lPCode, lTmpProcOutLen, pcTmpForMsg);
			
					
			if(lRetForSend != NORMAL)						// ���ϤǤ��ʤ����
			{
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
				free(pcTmpMsg);								// �ΰ�����
	
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
				free(pcTmpForMsg);
			
				os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

					
				return(INV_ERROR);							// ���顼����
			}
		}
		else
		{
			/******************************************/
			/* ��å���������Ϥ��ʤ�				  */
			/******************************************/
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
			free(pcTmpMsg);									// �ΰ�����
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
			free(pcTmpForMsg);
			
			os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

			os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, PRC_NORMAL );
	
			return(NO_MSGSEND);
			
		}
	
	}	
	
		
//	DbgMsg01( DLv04, ( OutPut, "#### os_SendProc return to Normal (11) pcTmpMsg == %s\n", 
//	                   pcTmpMsg) );
	
	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/

	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpMsg );
	
	free(pcTmpMsg);									// �ΰ�����
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_FREE, 1, pcTmpForMsg );
	
	free(pcTmpForMsg);
			
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSWRITE1, D_T_TRA_OUT, 1, PRC_NORMAL );
	
	return(PRC_NORMAL);
	
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 			*/
/*                              short *sCode, long lMsgLen)										*/
/*	                             	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���ϥ�å����������															*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	��å������ե����ޥåȾ��󥢥ɥ쥹									*/
/*		�ѥ�᡼����(2)	 - 	�ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(3)	 -	�Խ���Υ�å�����													*/
/*		�ѥ�᡼����(4)	 -	�ǡ�����Ǽ�Хåե��Υ�����											*/
/*		�ѥ�᡼����(5)	 -	�������Ѵ�����														*/
/*		�ѥ�᡼����(6)	 -	�ơ��֥�Υ�å�����������											*/
/*																								*/
/*																								*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 
				short *sCode, long lMsgLen)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	
	long lMsgStart = 0;										// ��å������ե����ޥåȾ����Ѥ���Ƭ
	
	long lMsgEnd = 0;										// ��å������ե����ޥåȾ����Ѥν�ü
	
	long lBufStart = 0;										// �ǡ�����Ǽ�Хåե��Ѥ���Ƭ
	
	long lBufEnd = 0;										// �ǡ�����Ǽ�Хåե��Ѥν�ü 
	
	long ltemp = 0;
	
	long lFlg = 0;
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/

//	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
															// ��å������ե����ޥåȾ����
															// �ǡ�����Ǽ�Хåե�����ݤ��뤿��
//	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// ���ΰ����ޤ�
															// TBCS0123
															
															// TBCS0153 / TBCS0155
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );

	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // �ǡ����Խ����ΰ�����
															// ���Ѥ��Խ����륵����ʬ=����*2
															// ����,���ڡ���,[]�Υ�����ʬ=9
															// TBCS0153 / TBCS0155





	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );

//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0) lMsgLen == %ld\n", lMsgLen) );	
		
//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.1) lBufLen == %ld\n", lBufLen) );	


															// TBCS0172		Start	2003.06.27
	/****************************************/
	/*	�Խ�����ʸ����������				*/
	/****************************************/
	lMsgStart = 8;											// ����ʸ�����֤�����
	while(lMsgStart > 0)
	{ 
															// �Խ�����ʸ���򸡺�
		lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);

		if(lMsgStart != -1)
		{
			if( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') )
			{
				break;
			}
			else
			{
				lMsgStart ++;
			}
		}
	}

//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
	
	if ( lMsgStart != -1) 									// �Խ�����ʸ�������ä����
	{
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgStart - 8); 	// �����ϰϤ��줿��å��������󤫤�
															// ���ϥ�å������˲ä�
															
		ltemp = lMsgStart - 8;
		
		strncpy((*pcMsg+ltemp), "\0", 1); 
		
		ltemp = lMsgStart + 1; 
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.3) *pcMsg\n ") );

		while(lMsgEnd != -1)								// ��å������ǡ������ʤ��ʤ�ޤǥ롼��
		{
			/****************************************/
			/*	������ʸ������Խ�����			*/
			/****************************************/
			if( (pcFmtAdr[lMsgStart] == '%') &&
			  ( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') ) )
			{
															// �ǡ�����Ǽ�Хåե���������ʸ����
															// ���ϰϤ����
				os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);

														// �Խ�����ʸ����%z�ξ�祳�����Ѵ�
				if( ( pcFmtAdr[lMsgStart] == '%' ) && ( pcFmtAdr[lMsgStart+1] == 'z' ) )
				{
															// TBCS0123
				 	os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);
				}
				else										// TBCS0123
				{											// �ǡ�����Ǽ�Хåե�����
															// ���ϥ�å��������Խ�
					os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
				
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.5) lBufStart = %ld\n", lBufStart));
				}
			
					lMsgStart ++;
			}
			
		//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (3) lBufStart == %d\n", lBufStart ) ); 
			
		//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(4) lBufEnd == %d\n", lBufEnd ) ); 

			/****************************************/
			/*	�Խ�����ʸ����������				*/
			/****************************************/
			lMsgEnd = os_SeekStr(pcFmtAdr, '%', ltemp, lMsgLen);
			if(lMsgEnd != -1)  
			{
				if( (pcFmtAdr[lMsgEnd + 1 ] == 'z') || (pcFmtAdr[lMsgEnd + 1] == 's') ) 
				{
															// ��å������ե����ޥåȾ��󤫤�
															// ���ϥ�å��������Խ�
					os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgEnd);
					
					lMsgStart = lMsgEnd;
				}
					
				ltemp = lMsgEnd + 1;
					
			}
			else
			{
															// ��å������ե����ޥåȾ��󤫤�
															// ���ϥ�å��������Խ�
					os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgLen);
			}
															
	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (6) lBufStart == %ld\n", lBufStart ) );	
			
	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (7) pcFmtAdr[lMsgStart]  == %c\n", 
	//				pcFmtAdr[lMsgStart]  ) );
		}
	}														// TBCS0172      End    2003.06.27
	else
	{
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (8) pcFmtAdr == %s\n", pcFmtAdr) );	
		
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgLen); 			// �����ϰϤ��줿��å���������
															// ���ϥ�å������˲ä�
	} 

}



/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� long os_SearchMsgID(TEmmcTableInd *pcEmmcIndAdr, long lTEmmcCnt, 				*/
/*								   char pcTmpBufMsgId[])				 						*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ��å��������̻Ҥθ���															*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	��å������ե����ޥåȾ��󥢥ɥ쥹									*/
/*		�ѥ�᡼����(2)	 - 	��å��������Х��ɥ쥹												*/
/*		�ѥ�᡼����(3)	 -	��å��������̻�													*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (��å����������ơ��֥����������													*/
/*		���� (-1)																				*/
/*																								*/
/************************************************************************************************/
long os_SearchMsgID(TEmmcTableInd *pcEmmcIndAdr, long lTEmmcCnt, char pcTmpBufMsgId[])
{

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	
	long lRet = -1;											// strncmp���ֵ���	
	
	long lCounter = 0;										// �롼�ץ�����
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) lTEmmcCnt == %d\n", lTEmmcCnt) );
	
	do														// �ǡ�����Ǽ�Хåե��ˤ���
	{														// ��å��������̻Ҥ���å�����	
															// �����ơ��֥�Υ�å�����	
															// ���̻Ҥȹ���
															
		lRet = strncmp(pcTmpBufMsgId, (pcEmmcIndAdr + lCounter)->acMsgID, 4);
		
		lCounter += 1;									
		
	}while((lRet != 0) && (lCounter < lTEmmcCnt));			// ���פ���ޤ�	

	if(lRet == 0)											
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) lCounter == %ld\n", lCounter) );
		
		lCounter--;
		
		return(lCounter);									// ��å����������ơ��֥���������ֵ�
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** os_SearchMsgID (1) return to -1") );
	
	return(-1);												// ���顼����
}



/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� void os_GetStrPos(char *pcBuf, char cTarget, long *lStart, long *lEnd,			*/
/*								 long lLen)							 							*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ��å���������λ����ϰϤ����													*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	�ǡ�����Ǽ�Хåե�													*/
/*  	�ѥ�᡼����(2)	 -	��ɸ																*/
/*		�ѥ�᡼����(3)	 -  ��Ƭ�ΰ���															*/
/*		�ѥ�᡼����(4)	 -  ��ü�ΰ���															*/
/*		�ѥ�᡼����(5)	 -  �ǡ�����Ǽ�Хåե�������											*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetStrPos(char *pcMessage, char cTarget, long *lStart, long *lEnd, long lLen)
{
	
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	
	long lRetForStart = 0;									// ��Ƭ�ΰ��֤򸡺����ֵ���
	
	long lRetForEnd = -1;									// ��ü�ΰ��֤򸡺����ֵ���
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
															// ��Ƭ�ΰ��֤򸡺�
	lRetForStart = os_SeekStr(pcMessage, cTarget, *lStart, lLen);		
	
	if(lRetForStart != -1)									// ���Ĥ��ä����
	{
	
		if(pcMessage[lRetForStart] != pcMessage[lRetForStart+1])
		{
															// TBCS0172		Start	2003.06.27
			*lStart = lRetForStart + 1;						// ��ɸ����Ƭ���֤�����
		
															// ��ɸ�ν�ü���֤򸡺�
			lRetForEnd = os_SeekStr(pcMessage, cTarget, lRetForStart + 1, lLen);
		
			if(lRetForEnd != -1)
			{
				*lEnd = lRetForEnd;
			}
			else
			{
				*lEnd = lLen;

			}
		}
		else
		{
			*lEnd = -1;
		}	
															
		return;
				
	}
	
	*lEnd = lRetForStart;									
															// TBCS0172		 End	2003.06.27
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� void os_GetLogMsg(char *pcBuf, char *pcFmtAdr, char *pcMsg, long lBufLen)		*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���վ����������ƽ��ϥ�å�����������										*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)	 -  �ǡ�����Ǽ�Хåե�													*/
/*		�ѥ�᡼����(2)  - 	��å������ե����ޥåȾ��󥢥ɥ쥹									*/
/*		�ѥ�᡼����(3)	 -  ���ϥ�å�����														*/
/*		�ѥ�᡼����(4)	 -  �ǡ�����Ǽ�Хåե�������											*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetLogMsg(char *pcBuf, char *pcFmtAdr, char *pcMsg, long lBufLen)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	
	long lStartPos = 0;										// �롼�ץ�����
	
	long lMsgLen = 0;
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	
															// '\t\t'�򸫤Ĥ���ޤǷ����֤�
	while( (pcBuf[lStartPos] != '\t' || pcBuf[lStartPos + 1] != '\t') && lStartPos != -1 )
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (1) lStartPos == %d\n", lStartPos) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (2) pcBuf[lStartPos]  == %c\n", 
				pcBuf[lStartPos] ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (3) pcBuf[lStartPos + 1]  == %c\n", 
				pcBuf[lStartPos + 1] ) );
															
															// '\t'�򸡺�
		lStartPos  = os_SeekStr(pcBuf, '\t', lStartPos + 1, lBufLen);
	
	}
	
	if( (lStartPos != -1 ) && (pcBuf[lStartPos] == '\t') && (pcBuf[lStartPos + 1] == '\t'))
	{
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (4) pcBuf[lStartPos + 1]  == %c\n", 
				pcBuf[lStartPos + 1] ) );
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5) pcBuf[lStartPos]  == %c\n", 
				pcBuf[lStartPos] ) );	

		lMsgLen = strlen(pcMsg);

		strncpy(pcMsg+lMsgLen, " \0", 2);
		
		if(pcFmtAdr[12] == '$') 							// ���ϻؼ�ʸ����'$'�ξ��
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.2) lMsgLen=%ld\n", 
				 	lMsgLen) );
				 	
		 	DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.3) lStartPos=%ld\n", 
				 	lStartPos + 2) );
			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.4) lBufLen=%ld\n", 
				 	lBufLen) );
															// �������Ѵ�
			os_ChangeCode(pcBuf, sConAfter, lStartPos + 2, lBufLen, pcMsg);
		}	
		else
		{
			DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (5.4)\n" ) );
			
															// ���ϥ�å�����������
			os_EditString(pcBuf, pcMsg, lStartPos + 2, lBufLen);
		}
		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (6) pcMsg == %s\n", pcMsg ) );
	}	
	
	DbgMsg01( DLv04, ( OutPut, "*** os_GetLogMsg (7) \n") );
	
}		
	


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� void os_EditString(char *pcInPtr, char *pcOutPtr, long lInPtrStart, 				*/
/*								  long lInPtrEnd)	  											*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���ꤵ�줿�ϰϤ�ʸ���������ϥ�å�����������									*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	INPUTʸ������														*/
/*  	�ѥ�᡼����(2)	 -	OUTPUTʸ������														*/
/*		�ѥ�᡼����(3)	 -  ��Ƭ�ΰ���															*/
/*		�ѥ�᡼����(4)	 -  ��ü�ΰ���															*/
/*																								*/
/************************************************************************************************/
void os_EditString(char *pcInPtr, char *pcOutPtr, long lInPtrStart, long lInPtrEnd)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	int iCnt = 0;											// �롼�ץ�����
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/

	if(lInPtrStart < lInPtrEnd)
	{
	
		while(pcOutPtr[iCnt] != '\0')						// ouputʸ������ν�üʸ����
		{													// ã����ޤǥ������
			iCnt++;
		}
	
		while(lInPtrStart < lInPtrEnd)
		{
	
			pcOutPtr[iCnt] = pcInPtr[lInPtrStart];			// inputʸ�����󤫤�ouput
															// ʸ�����������
			iCnt++;
		
			lInPtrStart++;

		} 
	
		pcOutPtr[iCnt++] = '\0';							// ��üʸ��������
	}
	
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� long os_MsgOut(char *pcMsgFormat, char *pcKey, char *pcPriority)	   				*/
/*																								*/
/*	�㵡ǽ���ס�  - ��å���������										                        */
/* 				   																				*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - �Խ��ѤߤΥ�å�����													*/
/*		�ѥ�᡼����(2)	 - �ե�����ƥ�															*/
/*		�ѥ�᡼����(3)	 - �ץ饤����ǥ�														*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (NORMAL)																			*/
/*		���� (D_OSWRITE1_OUTPUT_ERROR)															*/
/************************************************************************************************/
long os_MsgOut(char *pcMsgFormat, char *pcKey, char *pcPriority)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRetSg = 0;									// SG���ֵ���
	
	long lRetSys = 0;									// priority
	
	long lStr = 0;										// SG��
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	lRetSg = os_getSG(pcKey, &lStr);					// SG�ǡ����μ���
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (1) lRetSg == %ld\n", lStr) );
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (2) pcKey == %s\n", pcKey) );		
	
	if(lRetSg == -1)									// �۾��
	{

		return(INV_ERROR);				
	}
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (2) lFacility[lStr] == %ld\n", 
			lFacility[lStr]) );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_OPENLOG, 3, NULL, LOG_ODELAY, lFacility[lStr] );
	
	openlog(SYS_IDENT, LOG_ODELAY, lFacility[lStr]);			// openlog �����ƥॳ����
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (3) pcPriority == %s\n", pcPriority) );	
	
	lRetSys = os_ChgPriority(pcPriority);				// priority�Υ����ɤ��Ѵ�����
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (4) lRetSys == %ld\n", lRetSys) );	
	
	if (lRetSys == -1)
	{
		 return(INV_ERROR);
	}	 
	
	DbgMsg01( DLv04, ( OutPut, "*** os_MsgOut (5) pcMsgFormat == %s\n", pcMsgFormat) );	
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_SYSLOG, 2, lRetSys, pcMsgFormat );
															// TBCS0172		Start	2003.06.27
	syslog(lRetSys, "%s", pcMsgFormat);						// syslog �����ƥॳ���� 
															// TBCS0172		 End	2003.06.27
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_CLOSELOG, 0 );
	
	closelog();											// closelog �����ƥॳ����
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 0 );
	
	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	
	return (NORMAL); 	
	
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� int os_ChgPriority(char* pcPrioCode)												*/
/*																								*/
/*	�㵡ǽ���ס� - syslog�Υץ饤����ǥ��������Ѵ���Ԥ�										*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - �Ѵ����Υץ饤����ǥ�������											*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (syslog�Υץ饤����ǥ�������)														*/
/*		���� (-1)  																				*/
/*																								*/
/************************************************************************************************/
int os_ChgPriority(char *pcPrioCode)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long len = 0;										// �ץ饤����ǥ������ɤΥ�����
	
	char *pcTmpPriCode = NULL;							// �����ѤΥץ饤����ǥ�������
	
	int iCnt = 0;										// �롼�ץ����� 
	
	int iCnt1 = 0;										// �롼�ץ�����
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	len = strlen(pcPrioCode);							// �ץ饤����ǥ������ɤΥ�����

	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (1) len == %ld\n", len) );	
	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (2) pcPrioCode == %s\n", pcPrioCode) );
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, len+1 );
														// �����ѤΥץ饤����ǥ������ɤ�malloc
	pcTmpPriCode = (char*)malloc(len+1);  
	
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcTmpPriCode );
	
	while(pcPrioCode[iCnt] != '\0' && iCnt < len)		// �����ѤΥץ饤����ǥ�������
	{													// �����ꤹ��
		if(pcPrioCode[iCnt] != ' ')						
		{
			pcTmpPriCode[iCnt1] = pcPrioCode[iCnt];

			iCnt1 += 1;
		}		
			
		iCnt += 1;
		
	}
	
	pcTmpPriCode[iCnt1] = '\0';							// ʸ����Υ����ߥ͡����������� 
	
	DbgMsg01( DLv04, ( OutPut, "*** os_ChgPriority (3) pcTmpPriCode == %s\n", 
			pcTmpPriCode) );
	
	/******************************************/
	/* 	�ץ饤����ǥ������ɤ��Ѵ���Ԥ�	  */
	/******************************************/
	
	if( (strcmp(pcTmpPriCode, "EMERG") ) == 0 )			
	{
		return(LOG_EMERG);
	}
	
	if( (strcmp(pcTmpPriCode, "ALERT") ) == 0 )
	{
		return(LOG_ALERT);
	}	
	
	if( (strcmp(pcTmpPriCode, "CRIT") ) == 0 )
	{
		return(LOG_CRIT);
	}	
	
	if( (strcmp(pcTmpPriCode, "ERR") ) == 0 )
	{
		return(LOG_ERR);
	}
	
	if( (strcmp(pcTmpPriCode, "WARNING") ) == 0 )
	{
		return(LOG_WARNING);
	}
	
	if( (strcmp(pcTmpPriCode, "NOTICE") ) == 0 )
	{
		return(LOG_NOTICE);
	}
	
	if( (strcmp(pcTmpPriCode, "INFO") ) == 0 )
	{
		return(LOG_INFO);
	}

	if( (strcmp(pcTmpPriCode, "DEBUG") ) == 0 )
	{
		return(LOG_DEBUG);
	}

	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	
	return(-1);											// SYSLOG�Υץ饤����ǥ������ɤ�
														// ���פ��ʤ��Ȥ����顼��å��������ֵ�

}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� os_SearchJIS(short* ptr, long start, long end, long target)					  	*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� JIS code�򥵡�������															*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	ʸ������															*/
/*  	�ѥ�᡼����(2)	 -  ʸ���������Ƭ�ΰ���												*/
/*		�ѥ�᡼����(3)	 -  ʸ������ǺǸ�ΰ���												*/
/*		�ѥ�᡼����(4)	 -  ��ɸ																*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (������ɸ��ʸ������ˤϤ�����֡�													*/
/*		���� (-1)																				*/
/*																								*/
/************************************************************************************************/
long os_SearchJIS(short* ptr, long start, long end, long target)
{
	
	long mid;											// ��ɸ�ΰ���
	
	if (start == end)									// �ǽ�ΰ��֤��Ǹ�ΰ��֤ȹ��פ�����
	{
		
		if (target == ptr[start])						// ����κǽ�ΰ���
		{
	
			return start;								// ��ɸ�����Ĥ��ä����ֵѤ���
		}
		else
		{
			
			return (-1);
		}
	}
	else
	{
		
		mid = (start + end) / 2;						// ����ΤȤ���

		if (target == ptr[mid])							// ��ɸ�����Ĥ��ä����ֵѤ���
		{
			
			return mid;
		}
		else
		{
			if (target > ptr[mid])						// ��ɸ�����Ĥ���ʤ��ä����ֵѤ���
			{
														// ���ΤȤ����
				return os_SearchJIS(ptr,mid+1,end,target);
			}
			else
			{
														// ���ΤȤ����	
				return os_SearchJIS(ptr,start,mid-1,target);
			}
		}
	}
}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� os_ChangeCode(char *pcMsgSig, short *after, long lBufStart, long lBufEnd,		*/ 
/*							 char *pcMsg)													  	*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ʸ��������Υơ������ž����													*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	������ʸ����													*/
/*  	�ѥ�᡼����(2)	 -  EUC������															*/
/*		�ѥ�᡼����(3)	 -  �Ѵ��ϰϤ���Ƭ														*/
/*		�ѥ�᡼����(4)	 -  �Ѵ��ϰϤκǸ�														*/
/*		�ѥ�᡼����(5)	 -  �ǡ�����Ǽ�Хåե�													*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_ChangeCode(char *pcMsgSig, short *after, long lBufStart, long lBufEnd, char *pcMsg)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRet = 0;										// �ֵ���	

	long lCnt = 0;										// ������
	
	short sTemp = 0;									// �Ѵ������� TBCS0123
	
	long lSize = 0;										// �Ѵ����줿�Х��ȿ� TBCS0123
	
	char *pcWork = NULL;								// �Ѵ��Ѥ��ΰ� TBCS0123
	
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	
	pcWork = (char*)malloc( lBufEnd * 2 );				// TBCS0123
		
	for (lCnt = lBufStart; lCnt < lBufEnd; lCnt++)
	{													// JIS�����ɤ򸡺�
		
		sTemp = 0x00ff & pcMsgSig[lCnt]; 				// TBCS0123
		
		lRet=os_SearchJIS(before, 0, 89, sTemp);    

		DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (5) lRet == %ld\n", lRet) );	

		if(lRet != -1)									// ��ä���ţգä��Ѵ�
		{

			if( (after[lRet] & 0xff00) != 0x0000 )		// TBCS0123
			{
					
				pcWork[lSize] = after[lRet] >> 8;		// TBCS0123
				
				pcWork[lSize+1] = after[lRet];			// TBCS0123
				
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (9) pcWork == %08x\n", pcWork[lSize]) );
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (10) pcWork == %08x\n", pcWork[lSize+1]) );
				
				lSize += 2;								// TBCS0123
			}
			else
			{
				pcWork[lSize] = after[lRet];			// TBCS0123
				
				DbgMsg01( DLv04, ( OutPut, "*** os_SearchJIS (11) pcWork == %08x\n", pcWork[lSize]) );
				
				lSize += 1;								// TBCS0123
			}
			
		}
		else
		{
			pcWork[lSize] = pcMsgSig[lCnt];
			
			lSize += 1;
		}
		
	}
	
	os_EditString(pcWork, pcMsg, 0, lSize);				// TBCS0123

 	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	
	free(pcWork);										// TBCS0123

}


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� long os_Time( long lHour, long lMin)											  	*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ���֤μ���																		*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	��																	*/
/*  	�ѥ�᡼����(2)	 -  ʬ																	*/
/*																								*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (���ߤλ��֡�																		*/
/*		���� (D_OSWRITE1_OUTPUT_ERROR)															*/
/*																								*/
/************************************************************************************************/
long os_Time( long *lHour, long *lMin)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lDay = 0;										// ����

	long lTime = 0;										// ����

	long lRet = 0;										// ���߻��֤��ֵ���
	
		
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/

	lRet = osgtdat(&lDay, &lTime);						// ���յڤӻ���μ���
	
	if(lRet !=NORMAL)									// �۾��
	{
		return(0x940d);				// ���顼��å��������ֵ�
	}
	
    *lHour = ( lTime >> 16 ) & 0x0000000f;				// ����1�ΰ̤����
    
    *lHour += ( ( lTime >> 20 ) & 0x0000000f) * 10;		// ����10�ΰ̤����
   
    *lMin = ( lTime  >> 8 ) & 0x0000000f;				// ʬ��1�ΰ̤����
    									
    *lMin += ( ( ( lTime >> 12 ) & 0x0000000f ) * 10 );	// ʬ��10�ΰ̤����			
   
 
   	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	
	return(lRet);										// ������ֵ�
	
} 


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾�� long os_SeekStr(char *pcPtr, char cTarget, long lStart, long lEnd)				*/
/*                                	     			    										*/
/*																								*/
/*	�㵡ǽ���ס� ��å���������λ����ϰϤ����													*/
/*																								*/
/*																								*/
/*	�ѥ�᡼����:																				*/
/*		�ѥ�᡼����(1)  - 	ʸ������															*/
/*  	�ѥ�᡼����(2)	 -	��ɸ																*/
/*		�ѥ�᡼����(3)	 -  ��Ƭ�ΰ���															*/
/*		�ѥ�᡼����(4)	 -  �Ǹ�ΰ���															*/
/*																								*/
/*	�꥿����:																					*/
/*		���� (���ϻؼ�ʸ��)																		*/
/*		���� (D_OSWRITE1_ERROR)																	*/
/*																								*/
/************************************************************************************************/
long os_SeekStr(char *pcPtr, char cTarget, long lStart, long lEnd)
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lCnt;											// �롼�פΥ�����
	 
    
	/********************************************************************************************/
	/*	 �ܽ���																				    */
	/********************************************************************************************/
	
	if(lStart >= 0)
	{													//��ɸ�򸡺�
		for(lCnt = lStart; lCnt < lEnd; lCnt++) 
		{
			if(pcPtr[lCnt] == cTarget) 					// ���פ�����
			{
				
				return(lCnt);							// ���֤��ֵ�
			}
		
		}
	}


 	/********************************************************************************************/
	/*  ������λ				                                                                */
	/********************************************************************************************/
	
	return(-1);											// ���顼��å��������ֵ�
	
}	

