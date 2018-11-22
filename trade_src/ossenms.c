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
/* ��⥸�塼��̾��					 ��å�����������											*/
/* ��⥸�塼��ɣġ�				 ossenms													*/
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
/* �㥽���������ԡ� 			 	 �ã»��ӥ��ͥ����ô��(�᡼��:���ץ饤)					*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ��������� 	�㳲�б���TBCS0067��			*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�ץ������ϡ��ᥤ��ܥå����˥�å��������������롣									*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<ossenms.h>																	*/
/*																								*/
/*      long ossenms(long mpid, long size, char *bufa)                                          */
/*																								*/
/* �㲾������																					*/
/*		long		mpid			�ᥤ��ܥå������ϥץ������̻�							*/
/*		long		size			��å�����Ĺ��1��8192��										*/
/*		char		*bufp			��å�����													*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEACCV			���ɥ쥹�۾郎ȯ��������							*/
/*						OSEEIMPI			�ᥤ��ܥå������ϡ��ץ������̻Ҥ������Ǥ��롣	*/
/*						OSEEISIZ			��å�����Ĺ������Ǥʤ�������Ĺ�����롣			*/
/*						OSEENACC			�������������ʤ����ʣףңɣԣŸ���					*/
/*						OSEENEXS			���ꤷ���ץ������ϥᥤ��ܥå�����¸�ߤ��ʤ���	*/
/*						OSEEWKEX			�����ƥ��Ȱ褬���ݤǤ��ʤ���						*/
/*						OSEEOVRQ			��λ�����׵᤬¿�����ơ�������ǽ�Ǥ��롣			*/
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
#include "ossenms.h"
#include "ossenms_ins.h"


/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	 ossenms.c																		*/
/*																								*/
/*	�㵡ǽ���ס� �ץ������ϡ��ᥤ��ܥå����˥�å���������������                           	*/
/*				 																				*/
/*																								*/
/************************************************************************************************/
long ossenms(long mpid, long size, char *bufa)
{
	/********************************************************************************************/
    /*  �ӣ��������ΰ�                          						 					*/
    /********************************************************************************************/
	long lProRet = 0;							    	// �ץ������̻�
	long lMKyuId = 0;									// ��å��������塼ID
	long lAssort = 0;									// ����
	long lTsuban = 0;									// ����
	long lCnt = 0;										// loop counter
	size_t lAssign = 0;									// ������ƥХ��ȿ�
	char *pcMText = NULL;								// ��å������ǡ���

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	int iRet = 0;										// msgsnd�����ƥॳ������ֵ���
	long lPartStart = 0;								// ���θ���������

	TMsgHed *ptMsgPoint = NULL;							// ��å�������¤�Υݥ���
	TEprcTableInd *ptEprcInd = NULL;					// �ץ�������������
	TEmbcTableInd *ptEmbcInd = NULL;					// �ᥤ��ܥå�������������	


	os_trcget2( D_MD_OSSENMS, D_T_TRA_IN, 3, mpid, size, bufa  );

	/********************************************************************************************/
	/*	 �������																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  �����γ�ǧ                  */
	/*------------------------------*/
														// �ץ��������ơ��֥���������ɥ쥹
	ptEprcInd = (TEprcTableInd *)((long)ptEprc + sizeof(TEprcTable));
														// �ᥤ��ܥå��������ơ��֥���������ɥ쥹
	ptEmbcInd = (TEmbcTableInd *)((long)ptEmbc + sizeof(TEmbcTable));

//	DbgMsg01(DLv01, (OutPut, "****** (1) Start OSSENMS\n"));
//	DbgMsg01(DLv01, (OutPut, "****** (2) mpid: %ld\n", mpid));
//	DbgMsg01(DLv01, (OutPut, "****** (3) size: %ld\n", size));
//	DbgMsg01(DLv01, (OutPut, "****** (4) bufa: %lx\n", bufa));

	if(NULL == bufa)									// ��å������Υ��ɥ쥹���ʤ���
	{
		os_trcget2( D_MD_OSSENMS, D_T_ERR_PRA, 1, OSEEACCV );
		return(OSEEACCV);
	}

	if((size < D_OSSENMS_SIZE_MIN) || 					// ��å�����size���ǧ����	
	   (size > D_OSSENMS_SIZE_MAX))
	{
		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEISIZ );
		return(OSEEISIZ);
	}

	if((0 > mpid))										// ���ѥ�᥿�Υ����å�
	{
		os_trcget2( D_MD_OSSENMS, D_T_ERR_PRA, 1, OSEEIMPI );
		return(OSEEIMPI);
	}

	if(0 == mpid)   									// mpid��0�ξ��
	{
		lProRet = os_MyProSearch(ptEprcInd); 	    	//�ץ������̻Ҥ������������å�
		if(D_ERR_SYS == lProRet)
		{
			os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
			return(OSEENEXS);							// �ץ������̻�¸�ߤ��ʤ���
		}

		lCnt = os_MyMBoxSearch(lProRet, ptEmbcInd);		// �ᥤ��ܥ��å����̻Ҥ������������å�
		if(D_ERR_SYS == lCnt)
		{
			os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
			return(OSEENEXS);							// �ᥤ��ܥ��å����̻�¸�ߤ��ʤ���
		}
		else
		{
			lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;		// ��å��������塼ID�����ꤹ��
		}

		DbgMsg01(DLv02, (OutPut, "&&&&&&  lCnt = %ld\n", lCnt));
	}
	else if(0 != mpid)
	{
		lAssort = os_GetAsso(mpid);     				// ���̤μ���
		lTsuban = os_GetSerNum(mpid);					// ���֤μ���

		switch (lAssort)
		{
			case 1:										// ���̤��ץ����ξ��
														// �ᥤ��ܥå��������ơ��֥�θ���
				lMKyuId = os_PRSearch(mpid, lAssort, ptEmbcInd);	
				DbgMsg01(DLv01, (OutPut, "****** (9) lMKyuId: %ld\n", lMKyuId));

				if(D_ERR_SYS == lMKyuId)				// ���������Ĥ���ʤ��ä�����
				{
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
					return(OSEENEXS);					// ���顼��å�����
				}	  
				break;

			case 2:										// ���̤��ᥤ��ܥå����ξ��
				if((lTsuban < D_OSSENMS_TUBAN_MIN) ||	// ���֤Υ��������ǧ����
			  	   (lTsuban > D_OSSENMS_TUBAN_MAX))
				{
/*****	�㳲�б���TBCS0067��Start										��������2003.04.24	*****/
/************************************************************************************************/
/*	���顼�ֵ��ͤθ���OSEEIMBI �� OSEEIMPI�˽�����											*/
/************************************************************************************************/
//					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMBI );
//					return(OSEEIMBI);					// ���顼��å�����
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMPI );
					return(OSEEIMPI);					// ���顼��å�����
/*****	�㳲�б���TBCS0067�� End										��������2003.04.24	*****/
				}

														// �ᥤ��ܥå��������ơ��֥�θ���
				lCnt = os_MBISearch(ptEmbcInd, lPartStart, ptEmbc->lIndPartNum - 1, mpid);	
				if(D_ERR_SYS == lCnt)					// ���������Ĥ���ʤ��ä����
				{
					os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );

					return(OSEENEXS);					// ���顼��å�����
				}
				else
				{
														// ��å��������塼ID�����ꤹ��
					lMKyuId = (ptEmbcInd + lCnt)->lMsgQId;
				}
				break;

			default:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEIMPI );
				return(OSEEIMPI);						// ���顼��å�����
				break;
		}
	}

	/*------------------------------*/
	/* ��å�����������             */
	/*------------------------------*/
	lAssign = sizeof(TMsgHed) + size;					// ��å������إå���������
         												// ��������ֳ����ƥХ��ȿ��פ����ꤹ��

	os_trcget2( D_MD_OSSENMS, D_T_SYS_MALLOC, 1, lAssign );
	ptMsgPoint = (TMsgHed*)malloc(lAssign);				// �����ΰ�γ���
	os_trcget2( D_MD_OSSENMS, D_T_SYS_END, 1, ptMsgPoint );

	if(ptMsgPoint == NULL)								// �ֵ��ͤ�NULL�ξ��
	{
/*****	�㳲�б���TBCS0067��Start										��������2003.04.24	*****/
/************************************************************************************************/
/*	���顼�ֵ��ͤθ���OSEENEXS �� OSEEWKEX�˽�����											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEENEXS );
		os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, OSEEWKEX );

//		return(OSEENEXS);								// ���顼��å�����
		return(OSEEWKEX);								// ���顼��å�����
/*****	�㳲�б���TBCS0067�� End										��������2003.04.24	*****/
	}

	DbgMsg01(DLv01, (OutPut, "****** (17) lAssort: %ld\n", lAssort));
	DbgMsg01(DLv01, (OutPut, "****** (18) mpid: %ld\n", mpid));

	ptMsgPoint->pcPlBuf= NULL;							// ����bufa���������
														// �֥�å�������¤�Υݥ��󥿡פ�
														// �ס���Хåե������ꤹ��

	ptMsgPoint->lDataSize = size;						// ����size���������
														// �֥�å�������¤�Υݥ��󥿡פ�
														// �Υǡ��������������ꤹ��

	DbgMsg01(DLv01, (OutPut, "****** (19) ptMsgPoint->lDataSize: %d\n", ptMsgPoint->lDataSize));

	if ((0 == mpid) || (1 == lAssort))					// mpid��0���ϡ��ѿ��ּ��̡פ����ξ��
	{
		ptMsgPoint->lMsgType = D_MTYPE06;				// �ץ������ס���Хåե�ͭ���å�����
														// ����������֥�å�������¤�Υݥ��󥿡פ�
														// ��å����������פ����ꤹ��
	}
	else if(2 == lAssort)								// �ѿ��ּ��̡פ�2�ξ��
	{
		ptMsgPoint->lMsgType = D_MTYPE05;				// �ᥤ��ܥå������ס���Хåե�ͭ��
														// ��å��������������
														// �֥�å�������¤�Υݥ��󥿡פ�
														// ��å����������פ����ꤹ��
	}

	pcMText = (char*) (ptMsgPoint + 1);					// ��å������ǡ��������ꤹ��

//	strncpy(pcMText, bufa, size);						// ��å���������������֥�å�������¤�Υ�
	memcpy(pcMText, bufa, size);						// ��å��������������
														// �֥�å�������¤�Υݥ��󥿡פ�
														// ��å������ǡ��������ꤹ��

//	DbgMsg01(DLv01, (OutPut, "****** (21) ptMsgPoint->lDataSize: %ld\n", ptMsgPoint->lDataSize));
	DbgMsg01(DLv01, (OutPut, "****** (22) ptMsgPoint->pcPlBuf: %s\n", ptMsgPoint->pcPlBuf));
	DbgMsg01(DLv01, (OutPut, "****** (23) BUFA: %lx\n", bufa));	
	DbgMsg01(DLv01, (OutPut, "****** (24) lMKyuId: %ld\n", lMKyuId));
	DbgMsg01(DLv01, (OutPut, "****** (25) lAssign: %ld\n", lAssign));
//	DbgMsg01(DLv01, (OutPut, "****** (26) ptMsgPoint: %s\n", ptMsgPoint));
	DbgMsg01(DLv01, (OutPut, "****** (AAA) ptMsgPoint: %x\n", *ptMsgPoint));
	DbgMsg01(DLv01, (OutPut, "****** (AAA) ptMsgPoint: %x\n", ptMsgPoint));

	do
	{
//		os_trcget2( D_MD_OSSENMS, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, 
//														lAssign, IPC_NOWAIT );
//		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign, IPC_NOWAIT);  // msgsnd�����ƥॳ�����ȯ�Ԥ���

														// 20030329 �ѹ�
														// �����������ϥ�å�����������
														// �����������������ꤹ��
		os_trcget2( D_MD_OSSENMS, D_T_SYS_MSGSND, 4, lMKyuId, ptMsgPoint, 
											lAssign - sizeof(long), IPC_NOWAIT );

		iRet = msgsnd(lMKyuId, ptMsgPoint, lAssign - sizeof(long), IPC_NOWAIT);

		os_trcget2( D_MD_OSSENMS, D_T_SYS_END, 1, iRet );

	} while ((D_ERR_SYS == iRet) && (EINTR == errno));

	if(D_ERR_SYS == iRet)								// �����������Ǥ��ʤ����
	{
		os_trcget2( D_MD_OSSENMS,  D_T_SYS_FREE, 1, ptMsgPoint );
		free(ptMsgPoint);								// �����ΰ�����
		os_trcget2( D_MD_OSSENMS,  D_T_SYS_END, 0 );

		switch (errno)									// �۾����
		{
			case EAGAIN:
			case EINVAL:
			case ENOMEM:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEEWKEX);

			case EACCES:
			case EFAULT:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEENACC);

			case EIDRM:
				os_trcget2( D_MD_OSSENMS,  D_T_ERR_SYS, 1, errno );
				return(OSEENEXS);

			default:
                          								// ���ܡ��Ƚ���
				os_trcget2( D_MD_OSSENMS, D_T_ERR_ABT, 1, errno );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSENMS << 16) | D_T_ERR_SYS );
		}
	}


	/********************************************************************************************/
	/*	 ��λ����																				*/
	/*																							*/
	/********************************************************************************************/
	os_trcget2( D_MD_OSSENMS,  D_T_SYS_FREE, 1, ptMsgPoint );
	free(ptMsgPoint);									// �����ΰ�����
	os_trcget2( D_MD_OSSENMS,  D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSSENMS, D_T_TRA_OUT, 1, NORMAL );
	return(NORMAL);
}
