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
/* �㥵���ӥ�����̾��				 ��å������̿�												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ס���Хåե���Υ�å���������							*/
/* ��⥸�塼��ɣġ�				 ossenmsp													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼��:���ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�ᥤ��ܥå������ϥץ����ˡ��ס���Хåե�����֤��줿��å��������������롣			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<ossenmsp_ins.h>															*/
/*																								*/
/*		long	ossenmsp( long mpid, long size, char *bufa )									*/
/*																								*/
/* �㲾������																					*/
/*		long		mpid			�ᥤ��ܥå������ϥץ������̻�							*/
/*		long		size			��å�����Ĺ��1��32768��									*/
/*		char		*bufa			�ס���Хåե����ɥ쥹										*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEACCV			���ɥ쥹�۾郎ȯ��������							*/
/*						OSEEIMPI			�ᥤ��ܥå������ϡ��ץ������̻Ҥ������Ǥ��롣	*/
/*						OSEEIPOL			�ס���Хåե��Ǥʤ���Τ���ꤷ����				*/
/*						OSEEISIZ			��å�����Ĺ������Ǥʤ�������Ĺ�����롣			*/
/*						OSEENACC			�������������ʤ����ʣףңɣԣŸ���					*/
/*						OSEENEXS			���ꤷ���ץ������ϥᥤ��ܥå�����¸�ߤ��ʤ���	*/
/*						OSEENFND			���ץ����Τ�ΤǤʤ��ס���Хåե�����ꤷ����	*/
/*						OSEEWKEX			�����ƥ��Ȱ褬���ݤǤ��ʤ���						*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		�äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/************************************************************************************************/
/*	���󥯥롼�ɥե�����																		*/
/************************************************************************************************/
/************************************************************************************************/
/*								���̥إå����ե�����											*/
/************************************************************************************************/
#include <string.h>
#include <stdio.h>
#include <errno.h>

/************************************************************************************************/
/*								���ѼԺ����إå����ե�����										*/
/************************************************************************************************/
#include "ossenmsp.h"
#include "ossenmsp_ins.h"

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	 ossenmsp.c																		*/
/*																								*/
/*	�㵡ǽ���ס� �ᥤ��ܥå������ϥ֥����ˡ��֡���Хåե�����֤��줿��å���������������	*/
/*				 																				*/
/*																								*/
/************************************************************************************************/
long ossenmsp(long mpid, long size, char *bufa)
{

	/********************************************************************************************/
    /*  �ӣ��������ΰ�                          						 					*/
    /********************************************************************************************/
	long lProRet = 0;									// �ץ������̻�
	long lMKyuId = 0;									// ��å��������塼ID
	long lAssort = 0;									// ����
	long lTsuban = 0;									// ����
	long lCnt = 0;										// loop counter
	size_t lAssign = 0;									// ������ƥХ��ȿ�

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	int iRet = 0;										// msgsnd�����ƥॳ������ֵ���
	long lPartStart = 0;								// ���θ���������
	TMsgHed *ptMsgPoint = NULL;						    // ��å�������¤�Υݥ���
	TEprcTableInd *ptEprcInd = NULL;					// �ץ�������������
	TEbpcTable *ptBPoolAdrFirst = NULL;					// �Хåե��ס�����Ƭ���ɥ쥹
	TEbpcTable *ptBPoolAdrLast = NULL;					// �Хåե��ס���������ɥ쥹
	TEpbcTableInd *ptUtilAdr = NULL;					// ��˥åȴ�������¤�Υ��ɥ쥹
	TEmbcTableInd *ptEmbcInd=NULL;						// �ᥤ��ܥå�������������
	TEpbcTableInd *ptUtilSec = NULL;
	
	os_trcget2( D_MD_OSSENMSP, D_T_TRA_IN, 3, mpid, size, bufa  );

	
	/********************************************************************************************/
	/*	 �������																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  �����γ�ǧ                  */
	/*------------------------------*/
	
	ptEprcInd = (TEprcTableInd *)((long)ptEprc +		// �ץ����������������� 
	            sizeof(TEprcTable));  
	ptEmbcInd = (TEmbcTableInd *)((long)ptEmbc +		// �ᥤ��ܥå�����������������
				sizeof(TEmbcTable));



//	DbgMsg01(DLv01, (OutPut, "****** (1) Start OSSENMS\n"));
//	DbgMsg01(DLv01, (OutPut, "****** (2) mpid: %d\n", mpid));
//	DbgMsg01(DLv01, (OutPut, "****** (3) size: %d\n", size));
//	DbgMsg01(DLv01, (OutPut, "****** (4) bufa: %x\n", bufa)); 
	DbgMsg01(DLv01, (OutPut, "****** (5) (ptEmbcInd + 0)->lMsgQId==%d\n", (ptEmbcInd + 0)->lMsgQId)); 
	DbgMsg01(DLv01, (OutPut, "****** (6) ptEmbc->lIndPartNum==%d\n", ptEmbc->lIndPartNum));
	
	
	if((0 > mpid))										// ���ѥ�᥿�Υ����å�
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEIMPI );
												
		return(OSEEIMPI);
	}

	if((size < D_OSSENMSP_SIZE_MIN) || 					// ��å���������Ĺ(����size)���ϰϥ����å�
	   (size > D_OSSENMSP_SIZE_MAX))					// ���������ϰϳ����ͤ����ꤵ��Ƥ���			 
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEISIZ );
		
		return(OSEEISIZ);								
	}
	
	if(NULL == bufa)									// �ס���Хåե����ɥ쥹���ʤ���
	{
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_PRA, 1, OSEEACCV );
		
		return(OSEEACCV);
	}
		
	if(0 == mpid)   									// �ᥤ��ܥå������ϥץ������̻Ҥ�0
	{													// �ξ��
		
		lProRet = os_MyProSearch(ptEprcInd); 	    	//�ץ������̻Ҥ������������å�
		
		if(D_ERR_SYS == lProRet)
		{
			os_trcget2( D_MD_OSSENMSP,  D_T_ERR_SYS, 1, OSEENEXS );
			
			return(OSEENEXS);							// �ץ������̻�¸�ߤ��ʤ���
		}
		
		lCnt = os_MyMBoxSearch(lProRet, ptEmbcInd);	// �ᥤ��ܥ��å����̻Ҥ������������å�
		
		if(D_ERR_SYS == lCnt)
		{
			os_trcget2( D_MD_OSSENMSP,  D_T_ERR_SYS, 1, OSEENEXS );
			
			return(OSEENEXS);							// �ᥤ��ܥ��å����̻�¸�ߤ��ʤ���
		}
		else
		{
			lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// ��å��������塼ID�����ꤹ��
		}
	
		DbgMsg01(DLv02, (OutPut, "&&&&&&  lCnt = %ld\n", lCnt));
	}	
	else if(0 != mpid)									// �ᥤ��ܥå������ϥץ������̻Ҥ�0
	{													// �ʳ��ξ��
	
		lAssort = os_GetAsso(mpid);     				// ���̤μ���

		lTsuban = os_GetSerNum(mpid);					// ���֤μ���

		switch (lAssort)
		{
			case 1:										// ���̤��ץ����ξ��
														// �ᥤ��ܥå��������ơ��֥�θ���
				lMKyuId = os_PRSearch(mpid, lAssort, ptEmbcInd);	
				DbgMsg01(DLv01, (OutPut, "****** (9) lMKyuId: %x\n", lMKyuId));	
				
				if(D_ERR_SYS == lMKyuId)				// ���������Ĥ���ʤ��ä�����
				{
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
					
					return(OSEENEXS);					// ���顼��å�����
				}	  
				break;
			case 2:										// ���̤��ᥤ��ܥå����ξ��
				if((lTsuban < D_OSSENMSP_TUBAN_MIN) ||	// ���֤Υ��������ǧ����	 
				  (lTsuban > D_OSSENMSP_TUBAN_MAX))
				{
/*****	�㳲�б���TBCS0088��Start										��������2003.05.15	*****/
/************************************************************************************************/
/*	���顼�ֵ��ͤθ���OSEEIMBI �� OSEEIMPI�˽�����											*/
/************************************************************************************************/
//					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMBI );
//					return(OSEEIMBI);					// ���顼��å�����
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMPI );
					return(OSEEIMPI);					// ���顼��å�����
/*****	�㳲�б���TBCS0088�� End										��������2003.05.15	*****/
				}

				DbgMsg01(DLv01, (OutPut, "****** (10) %x\n", mpid));
							
														// �ᥤ��ܥå��������ơ��֥�θ���
				lCnt = os_MBISearch(ptEmbcInd, lPartStart, ptEmbc->lIndPartNum - 1, mpid);	
				
				if(D_ERR_SYS == lMKyuId)				// ���������Ĥ���ʤ��ä�����
				{
					os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
					
					return(OSEENEXS);					// ���顼��å�����
				}
				else
				{
					lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// ��å��������塼ID�����ꤹ��
					
					DbgMsg01(DLv01, (OutPut, "****** (11) lMKyuId: %d\n", lMKyuId));
				}
				break;
			default:
				DbgMsg01(DLv01, (OutPut, "****** (12) RETURN OSEEIMPI\n"));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIMPI );
				
				return(OSEEIMPI);						// ���顼��å�����
				break;
		}		
		
	}
	
	if((size < D_OSSENMSP_SIZE_MIN) || 					// ��å�����size���ǧ����	
	   (size > D_OSSENMSP_SIZE_MAX))
	{
		DbgMsg01(DLv01, (OutPut, "****** (13) RETURN OSEEISIZ\n"));
		
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEISIZ );
		
		return(OSEEISIZ);
	}
	
	 ptBPoolAdrFirst = (TEbpcTable*)(long)(ptEbpc->pvAdr);	// �ѥåե��ס�������ơ��֥��
														// �ѥåե��ס�����Ƭ���ɥ쥹����
														// ��ʬ����������֥ѥåե��ס���
														// ��Ƭ���ɥ쥹�פ����ꤹ��
														
//	ptBPoolAdrFirst = (TEbpcTable*)sizeof(ptEbpc->pvAdr);
	
	DbgMsg01(DLv01, (OutPut, "****** (14) ptBPoolAdrFirst%x\n", ptBPoolAdrFirst));
														
	
	ptBPoolAdrLast = 									// ������ꤵ�줿�֥ѥåե��ס���
	(TEbpcTable*)(ptBPoolAdrFirst + ptEbpc->lSize);		// ��Ƭ���ɥ쥹�ץ֥饹�� �ѥåե��ס���
														// �������פ�ʬ����������֥ѥåե��ס���
														// �������ɥ쥹�פ����ꤹ�롣
	
	DbgMsg01(DLv01, (OutPut, "****** (15) ptBPoolAdrLast%x\n", ptBPoolAdrLast));
	
	
	if(((long)bufa < (long)ptBPoolAdrFirst) 			// �⤷bufa�ϡ֥ѥåե��ס�����Ƭ���ɥ쥹��
		&& ((long)bufa > (long)ptBPoolAdrLast))			// ����֥ѥåե��ס���������ɥ쥹�פޤǤ�	
	{													// �ϰϤǤʤ����ϰ۾�message return
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEIPOL );
		
		return(OSEEIPOL);								// ���顼��å�����
	}
	
	
	
	ptUtilAdr = (TEpbcTableInd*)((long)bufa - 4);		// �֥ѥåե��ס�����Ƭ���ɥ쥹�פϣ��Х��Ȥ�
														// �Ҥ��ơ֥�˥åȴ������ɥ쥹�פ����ꤹ��
	
	DbgMsg01(DLv01, (OutPut, "****** (16) ptUtilSec == %x\n", ptUtilSec ));
														
	ptUtilSec = (TEpbcTableInd *)(ptUtilAdr->ptNxtAdr);	
	
	DbgMsg01(DLv01, (OutPut, "****** (16) ptUtilSec == %x\n", ptUtilSec ));												
	
	DbgMsg01(DLv01, (OutPut, "****** (16.5) ptUtilSec->lUsePid == %x\n", ptUtilSec->lUsePid));

	
														
	//DbgMsg01(DLv01, (OutPut, "****** (17)ptEpbcInd == %ld\n", ptEpbcInd->lUsePid));
	
	DbgMsg01(DLv01, (OutPut, "****** lMyPid  == %ld\n", lMyPid));
	DbgMsg01(DLv01, (OutPut, "****** ptUtilSec->lUsePid  == %ld\n", ptUtilSec ->lUsePid));
														
	if(lMyPid != ptUtilSec ->lUsePid)	// ���֥����ɣĤ����ꤢ��֥�˥åȴ������ɥ쥹��
	{													// �λ��ѥץ����ɣĤ����פ��뤳�Ȥ��ǧ]
	
		DbgMsg01(DLv01, (OutPut, "999999999999 \n"));
		
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENFND );
	
		return(OSEENFND);								// ���顼��å����� 
  	}
	
	DbgMsg01(DLv01, (OutPut, "****** (188888888888888888)"));	 
	/*------------------------------*/
	/* ��å�����������             */
	/*------------------------------*/
	          											
//	lAssign = sizeof(TMsgHed) + size;					// ��å������إå���������
	         											// ��������ֳ����ƥХ��ȿ��פ����ꤹ��

	lAssign = sizeof(TMsgHed);							// 20030325 ����

 	DbgMsg01(DLv01, (OutPut, "****** (17) lAssign: %d\n", lAssign));
	
	os_trcget2( D_MD_OSSENMSP, D_T_SYS_MALLOC, 1, lAssign );
	ptMsgPoint = (TMsgHed*)malloc(lAssign);				// malloc�ؿ���ȯ�Ԥ���
	os_trcget2( D_MD_OSSENMSP, D_T_SYS_END, 1, ptMsgPoint );
	
	if(ptMsgPoint == NULL)								// �ֵ��ͤ�NULL�ξ��
	{
/*****	�㳲�б���TBCS0088��Start										��������2003.05.15	*****/
/************************************************************************************************/
/*	���顼�ֵ��ͤθ���OSEENEXS �� OSEEWKEX�˽�����											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
//		return(OSEENEXS);								// ���顼��å�����
		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);								// ���顼��å�����
/*****	�㳲�б���TBCS0088�� End										��������2003.05.15	*****/
	}

	DbgMsg01(DLv01, (OutPut, "****** (18) ptMsgPoint: %x\n", ptMsgPoint));



	ptUtilSec->lUsePid = D_OSSENMSP_TRANSMIT;			// �������̣�Υ�å�������ʬ���������
														//�֥�˥åȴ������ɥ쥹�פλ��ѥץ����ɣ�
														// �����ꤹ��
	
	ptMsgPoint->pcPlBuf = bufa;							// ����bufa����������֥�å�������¤�Υݥ��󥿡פ�
														// �ס���Хåե����ɥ쥹�����ꤹ��
											
	DbgMsg01(DLv01, (OutPut, "****** (19) ptMsgPoint->pcPlBuf: %x\n", ptMsgPoint->pcPlBuf)); 
			
	ptMsgPoint->lDataSize = size;						// size���ѿ��֥�å�������¤�Υݥ��󥿡פ�
														// �ǡ��������������ꤹ��
		
	if ((0 == mpid) || (1 == lAssort))					// mpid��0���ϡ��ѿ��ּ��̡פ����ξ��
	{
		ptMsgPoint->lMsgType = D_MTYPE08;				// �֥ץ������ס���Хåե�ͭ���å������פ�
														// ��������֥�å�������¤�Υݥ��󥿡פ�
														// ��å����������פ����ꤹ�롣
	}
	else if(2 == lAssort)								// �ѿ��ּ��̡פ�2�ξ��
	{
		ptMsgPoint->lMsgType = D_MTYPE07;				// �ᥤ��֥å������ƥס���Хåե�ͭ���å������פ�
														// ��������֥�å�������¤�Υݥ��󥿡�
														// �Υ�å����������פ����ꤹ�롣
	}
	
	DbgMsg01(DLv01, (OutPut, "****** (20) lAssign: %d\n", lAssign));
	
	do
	{
		DbgDmp02( DLv04, ("### ossenmsp msgsnd ", ptMsgPoint, lAssign,1,0));
		
//		os_trcget2( D_MD_OSSENMSP, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT );
//		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT);  // msgsnd�����ƥॳ�����ȯ�Ԥ���

														// 20030329 �ѹ�
														// �����������ϥ�å�����������
														// �����������������ꤹ��
		os_trcget2( D_MD_OSSENMSP, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint,
										 lAssign - sizeof(long), IPC_NOWAIT );
		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign - sizeof(long), IPC_NOWAIT);

		os_trcget2( D_MD_OSSENMSP, D_T_SYS_END, 1, iRet );
		
		
		
	} while ((D_ERR_SYS == iRet) && (EINTR == errno));	
	

	/****************************************************************************/
	/*	�۾����																*/
	/****************************************************************************/
	if(D_ERR_SYS == iRet)										// 0�ʳ��ξ��
	{
/*****	�ξ�����ֹ�TBCS0180���б�		Start							��������2003.07.08	*****/
														// ��˥åȴ�������Ρֻ��ѥץ����ɣġפ�
		ptUtilSec->lUsePid = lMyPid;					// ��������֤����ʽ�ͭ�Ԥ�PID�������
/*****	�ξ�����ֹ�TBCS0180���б�		 End							��������2003.07.08	*****/
														
		DbgMsg01(DLv05, (OutPut, "****** (21) ptUtilAdr->lUsePid = %d\n", ptUtilAdr->lUsePid));
		
		os_trcget2( D_MD_OSSENMSP,  D_T_SYS_FREE, 1, ptMsgPoint );
			
		free(ptMsgPoint);								// free�����ƥॳ�����ȯ�Ԥ���
		
		os_trcget2( D_MD_OSSENMSP,  D_T_SYS_END, 0 );
		
		switch (errno)									// �۾����
		{
			case EAGAIN:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (29) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case EACCES:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (30) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENACC);
			case EFAULT:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (31) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENACC);
			case EIDRM:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (32) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEENEXS);
			case EINTR:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (33) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case EINVAL:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (34) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			case ENOMEM:
				DbgMsg01(DLv01, (OutPut, "@@@@@@@ (35) 01:Err Mess: %s Num: %d\n", strerror(errno), errno));
				
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, errno    );
				
				return(OSEEWKEX);
			default:
				os_trcget2( D_MD_OSSENMSP, D_T_ERR_ABT, 1, errno );
				
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSENMSP << 16) | D_T_ERR_SYS );
                        								// ���ܡ��Ƚ��� 
		}		
			
//		os_trcget2( D_MD_OSSENMSP, D_T_ERR_SYS, 1, OSEENEXS );
														
//		return(OSEENEXS);								// ���顼��å�����
	}

	/********************************************************************************************/
	/*	 ��λ����																				*/
	/*																							*/
	/********************************************************************************************/
	os_trcget2( D_MD_OSSENMSP,  D_T_SYS_FREE, 1, ptMsgPoint );
	
	free(ptMsgPoint);									// free�����ƥॳ�����ȯ�Ԥ���
	
	os_trcget2( D_MD_OSSENMSP,  D_T_SYS_END, 0 );
		
//	DbgMsg01(DLv01, (OutPut, "****** (38) BEFORE RETURN TO NORMAL \n"));	
	
	os_trcget2( D_MD_OSSENMSP, D_T_TRA_OUT, 1, NORMAL );
	
	return(NORMAL);
}

