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
/* �㥵���ӥ�����̾��				 ��å������̿�												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ᥤ��ܥå����κ��										*/
/* ��⥸�塼��ɣġ�				 osdelmb													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤��̣)				*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ᥤ��ܥå����κ��																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osdelmb.h>																	*/
/*																								*/
/*	   	long	osdelmb( long mbid, long udf )													*/
/*																								*/
/* �㲾������																					*/
/*		long	mbid;			�ᥤ��ܥå������̻�											*/
/*		long	udf;			̵������ե饰												*/
/*									0     : ̵��������ʤ�									*/
/*									0�ʳ� : ̵���������										*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ				NORMAL															*/
/*		�۾ｪλ				-1																*/
/*								OSEEEXST		�����å����������롣							*/
/*								OSEEIMBI		�ᥤ��ܥå������̻Ҥ������Ǥ��롣				*/
/*								OSEENEXS		���ꤷ���ᥤ��ܥå�����¸�ߤ��ʤ���			*/
/*								OSEEWKEX		�����ƥ��Ȱ褬���ݤǤ��ʤ���					*/
/*								OSEENACC														*/
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
/******************************** ɸ��إå����ե����� ******************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <errno.h>
/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "osdelmb.h"
#include "osdelmb_ins.h"

/****************************************************************************/
/* ��ǽ���ᥤ��ܥå����κ��                                               */
/* ��������2002ǯ10��4��                                                    */
/* �ѹ�����2002ǯ10��4��                                                    */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long osdelmb( long mbid, long udf )                                    */
/*     long mbid              �ᥤ��ܥå������̻�                          */
/*     long udf               ̵������ե饰                              */
/*                                0     : ̵��������ʤ�                  */
/*                                0�ʳ� : ̵���������                    */
/*                                                                          */
/****************************************************************************/
long osdelmb( long mbid, long udf )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	long lAsso;							// ����
	long lSerNum;						// ����
	int iRet;							// �ؿ�����ֵ�
	TEmbcTableInd *ptIndAdr;			// �ᥤ��ܥå��������ơ��֥�������Υ��ɥ쥹
	struct msqid_ds tMsqid_ds;			// ��å��������塼��Ϣ����
	TMsgInfo *ptMsgInfo;				// ��å���������
	TMsgInfo *ptMsgInfoTmp;				// ��å���������ʰ�����ѡ�
/*****  �㳲�б���TBCS0118��	Start									��������2003.06.10  *****/
	TEprcTableInd	*ptEprcTblInd;					/* �ץ��������ơ��֥���������ɥ쥹		*/
	long			lLimit;							/* �ץ��������ơ��֥��������				*/
	long			lTmpCode;						/* �ץ������̻�							*/
	long			lTempId;						/* �ץ���ID								*/
	long			lCnt;
/*****  �㳲�б���TBCS0118��	End										��������2003.06.10  *****/
/*****  �㳲�б���TBCS0221��	Start									��������2003.07.24  *****/
	long			lWkMsgQId;
	long			lMessageType;					/* msgrcv()���裴������                     */
	int				iMessageFlag;					/* msgrcv()���裵������                     */
	long			lBufferPoolTopAddr;				/* �Хåե��ס�����Ƭ���ɥ쥹               */
	long			lBufferPoolBottomAddr;			/* �Хåե��ס���������ɥ쥹               */
	long			*palPlList[2];					/* �ס���Хåե����ɥ쥹�ꥹ��				*/
	char			*pcWorkPtr = NULL;				/* ����ݥ���							*/
	TMsgHed			*ptMsgHed  = NULL;				/* ��å������ݥ���						*/
	TEpbcTableInd   *ptEpbcInd = NULL;              /* ��˥åȴ�������¤�Υ��ɥ쥹           */
	TPbInfo         *ptPbInfo  = NULL;              /* �ס���Хåե���������ݥ���           */
/*****  �㳲�б���TBCS0221��	End										��������2003.07.24  *****/

	os_trcget2( D_MD_OSDELMB, D_T_TRA_IN, 2, mbid, udf  );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	lAsso = os_GetAsso(mbid);			// ���̤μ���
	lSerNum = os_GetSerNum(mbid);		// ���֤μ���

	if( lAsso != D_ASSO_MB )			// ���̤��ᥤ��ܥå������̻Ұʳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIMBI ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEIMBI );
		
		return( OSEEIMBI );				// OSEEIMBI���ֵ�
	}

	if( (lSerNum < D_SERNUM_MIN) || (lSerNum > ptEmbc->lIndPartNum) )
	{									// ���֤����������ϰϳ��Ǥ����
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEENEXS );
		
		return( OSEENEXS );				// OSEENEXS���ֵ�
	}

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	/************************************************/
	/*	��å��������塼�κ��						*/
	/************************************************/
	ptIndAdr = (void *)ptEmbc + sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * (lSerNum - 1);
										// ����θ����������
	if( ptIndAdr->lMsgQId == D_MSGQID_NONE )
	{									// ̤�����λ�
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEENEXS );
		
		return( OSEENEXS );				// OSEENEXS���ֵ�
	}

	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
	iRet = msgctl( ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
										// ��å��������塼��Ϣ����μ���
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
										
	if( iRet == D_ERR_SYS )				// �����˼��Ԥ�����
	{
		goto err_osdelmb;				// �۾����������
	}

	if( udf == D_UDF_NO )				// ̵������򤷤ʤ���
	{
		if( tMsqid_ds.msg_qnum != D_MSGQNUM_NONE )
										// ��å��������塼�˥�å������������
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEEXST );
			
			return( OSEEEXST );			// OSEEEXST���ֵ�
		}

		if( ptIndAdr->tSubMsgQ.lMsgCnt != D_MSGQNUM_NONE )
		{								// ���֥�å��������塼�˥�å������������
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEEXST );
			
			return( OSEEEXST );			// OSEEEXST���ֵ�
		}
	}

/*****  �㳲�б���TBCS0221��	Start									��������2003.07.24  *****/
/************************************************************************************************/
/*  �������Υ�å��������塼�ɣĥ��ꥢ�ΰ�ư�ˤ���ɲ�                                          */
/************************************************************************************************/
	lWkMsgQId = ptIndAdr->lMsgQId;
	ptIndAdr->lMsgQId = D_MSGQID_NONE;
	
	/************************************/
	/*  ��å���������					*/
	/************************************/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_MALLOC, 1, sizeof(TMsgHed) );
	pcWorkPtr = calloc(1, sizeof(TMsgHed) );
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, pcWorkPtr );	
	if (NULL == pcWorkPtr)
	{
		os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);				/* �۾ｪλ��sys work area exhaust��		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;	/* �ץ����֥�å������ݥ�������			*/

	for( ; ; )
	{
		lMessageType = 0;
/*****  �㳲�б���TBCS0261��	Start									��������2003.08.04  *****/
/************************************************************************************************/
/*  ��IPC_NOWAIT | MSG_NOERROR�פǻ��ꤹ��褦�˽���                                            */
/************************************************************************************************/
		iMessageFlag = IPC_NOWAIT | MSG_NOERROR;
/*****  �㳲�б���TBCS0261��	End										��������2003.08.04  *****/
		
        os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGRCV, 5, lWkMsgQId, ptMsgHed,
		                    sizeof(TMsgHed) - sizeof(long), lMessageType, iMessageFlag );
		iRet = msgrcv( lWkMsgQId, ptMsgHed, sizeof(TMsgHed) - sizeof(long),
						 lMessageType, iMessageFlag );
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 2, iRet, errno );
		/********************************************/
		/*	������̤��Խ�							*/
		/********************************************/
		if( iRet != D_ERR_SYS )			/* �����ƥॳ������ֵ��ͤ�����ξ��		*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
			if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
				( ptMsgHed->lMsgType == D_MTYPE08 ) )
			{
				/****************************************/
				/* ��å���������¤�Τ�               */
				/* �ס���Хåե����ɥ쥹���ϰϥ����å� */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
										/* �ס���Хåե���������ݥ�������       */
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ��˥åȴ�������ݥ�������             */
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* ���ѥץ���ID�˼��ץ���ID������       */
					ptEpbcInd->lUsePid = lMyPid;
										/* ���������ס���Хåե����ɥ쥹������		*/
					palPlList[0] = ptMsgHed->pcPlBuf;
										/* �ס���Хåե��β���						*/
					iRet = osfrpbf(1L, &palPlList[0]);
				}
			}
		}
		else							/* �����ƥॳ������ֵ��ͤ��۾�ξ��		*/
		{
										/* errno �� EINTR �ξ��					*/
			if( errno == EINTR )
			{
				continue;				/* ���٥�å�����������Ԥ�					*/
			}
			else if( errno == ENOMSG )
			{
				break;
			}
			else
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS7);
			}
		}
	}
	os_trcget2( D_MD_OSDELMB,  D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);					/* �������								*/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );

//	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, ptIndAdr->lMsgQId, IPC_STAT, &tMsqid_ds );
//	iRet = msgctl( ptIndAdr->lMsgQId, IPC_RMID, NULL );
	os_trcget2( D_MD_OSDELMB, D_T_SYS_MSGCTL, 3, lWkMsgQId, IPC_RMID, NULL );
	iRet = msgctl( lWkMsgQId, IPC_RMID, NULL );
										// ��å��������塼�κ��
/*****  �㳲�б���TBCS0221��	End										��������2003.07.24  *****/
	os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
										
	if( iRet == D_ERR_SYS )				// ����˼��Ԥ�����
	{
		goto err_osdelmb;				// �۾����������
	}

	
	if( ptIndAdr->tSubMsgQ.ptBefAdr != D_MSGINFO_NONE )
	{									// ��å���������¸�ߤ����
/*****  �㳲�б���TBCS0118��	Start									��������2003.06.10  *****/
		/********************************************/
		/*  �����ץ���ID�μ���					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* �ץ��������ơ��֥������				*/
													/* ��Ƭ���ɥ쥹�μ���						*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", D_PROC_NAME,ptEprcTblInd));

		lLimit = ptEprc->lIndPartNum;				/* �ץ��������ơ��֥������������			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* �ץ��������ơ��֥�θ���				*/
		{
													/* �������ץ������̻Ҥμ���				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;

			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", D_PROC_NAME,lTmpCode));

			if( lTmpCode == ptIndAdr->lPCode )		/* �ץ������̻Ҥ�����						*/
			{
													/* �ץ���ID�μ���							*/
				lTempId = (ptEprcTblInd + lCnt)->lPid;
				break;
			}
		}
		if ( lCnt == lLimit )						/* ���פ���ץ������̻Ҥ�¸�ߤ��ʤ�		*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
													/* ���ܡ���									*/
			os_trcget2( D_MD_OSDELMB, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS5 );
		}
		
		/********************************************/
		/*  ���֥�å��������塼�Υ����å�			*/
		/********************************************/
		if( lTempId != lMyPid )						/* �����ץ���ID�����ץ���ID�ʳ�			*/
		{
			iRet = os_SubMsgAtc2(ptIndAdr);			/* ����Υ����å�							*/
			if( iRet != NORMAL )					/* �۾ｪλ�ξ��							*/
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
													/* ���ܡ���									*/
				os_trcget2( D_MD_OSDELMB, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS6 );
			}
		}
/*****  �㳲�б���TBCS0118��	End										��������2003.06.10  *****/

		ptMsgInfo = ptIndAdr->tSubMsgQ.ptBefAdr;
										// �ǽ���å���������μ���
/*****  �㳲�б���TBCS0144��	Start									��������2003.06.11  *****/
		while( ptMsgInfo != (TMsgInfo *)(ptIndAdr->tSubMsgQ.ptNxtAdr) )
//		while( ptMsgInfo != (TMsgInfo *)ptIndAdr )
		{								// ���٤ƤΥ�å�����������Ф��ƽ���
			ptMsgInfoTmp = (TMsgInfo *)ptMsgInfo->ptBefAdr;
										// ����å��������������

/*****  �㳲�б���TBCS0221��	Start									��������2003.07.24  *****/
										/* ������å������Υ��ɥ쥹������			*/
			ptMsgHed = ptMsgInfo->pvMsgAdr;

			DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
			if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
				( ptMsgHed->lMsgType == D_MTYPE08 ) )
			{
				/****************************************/
				/* ��å���������¤�Τ�               */
				/* �ס���Хåե����ɥ쥹���ϰϥ����å� */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
										/* �ס���Хåե���������ݥ�������       */
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ��˥åȴ�������ݥ�������             */
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* ���ѥץ���ID�˼��ץ���ID������       */
					ptEpbcInd->lUsePid = lMyPid;
										/* ���������ס���Хåե����ɥ쥹������		*/
					palPlList[0] = ptMsgHed->pcPlBuf;
										/* �ס���Хåե��β���						*/
					iRet = osfrpbf(1L, &palPlList[0]);
				}
			}
/*****  �㳲�б���TBCS0221��	End										��������2003.07.24  *****/

			if( ptMsgInfoTmp->lShmId != D_SHMID_NONE )
//			if( ptMsgInfo->lShmId != D_SHMID_NONE )
			{							// ��ͭ����ID�����ꤵ��Ƥ����
				/************************************/
				/*	��ͭ����κ��				*/
				/************************************/
				os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptMsgInfo->ptNxtAdr );
				iRet = shmdt( ptMsgInfo );
//				os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptMsgInfo );
//				iRet = shmdt( ptMsgInfo->ptNxtAdr );
/*****  �㳲�б���TBCS0144��	End										��������2003.06.11  *****/
										// ��ͭ����Υǥ��å�
				os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 2, iRet, errno );
										
				if( iRet == D_ERR_SYS )	// ����˼��Ԥ�����
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS );
					//return( -1 );		// ++++++++���ܡ���ͽ��++++++++
				}
				
/*****  �㳲�б���TBCS0144��	Start									��������2003.06.11  *****/
    			os_trcget2(D_MD_OSDELMB,D_T_SYS_SHMCTL,3,ptMsgInfoTmp->lShmId, IPC_RMID, NULL);
				iRet = shmctl( ptMsgInfoTmp->lShmId, IPC_RMID, NULL );
//    			os_trcget2(D_MD_OSDELMB,D_T_SYS_SHMCTL,3,ptMsgInfo->lShmId, IPC_RMID, NULL);
//				iRet = shmctl( ptMsgInfo->lShmId, IPC_RMID, NULL );
/*****  �㳲�б���TBCS0144��	End										��������2003.06.11  *****/
										// ��ͭ����κ��
    			os_trcget2(D_MD_OSDELMB,D_T_SYS_END,2,iRet, errno);
										
				if( iRet == D_ERR_SYS )	// ����˼��Ԥ�����
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS1);
					//return( -1 );		// ++++++++���ܡ���ͽ��++++++++
				}
			}
			/****************************************/
			/*	��å���������Υ��ꥢ				*/
			/****************************************/
/*****  �㳲�б���TBCS0144��	Start									��������2003.06.11  *****/
//			ptMsgInfo->ptNxtAdr	= D_MSGINFO_NONE;
//			ptMsgInfo->ptBefAdr	= D_MSGINFO_NONE;
//			ptMsgInfo->lShmId	= D_SHMID_NONE;
//			ptMsgInfo->lMsgSize	= 0;
//			ptMsgInfo->pvMsgAdr	= NULL;
/*****  �㳲�б���TBCS0144��	End										��������2003.06.11  *****/
										// ��å���������Υ��ꥢ
			ptMsgInfo = ptMsgInfoTmp;
										// ���򤷤�����å�����������
		}
		
/*****  �㳲�б���TBCS0221��	Start									��������2003.07.24  *****/
										/* ������å������Υ��ɥ쥹������			*/
		ptMsgHed = ptMsgInfo->pvMsgAdr;

		DbgMsg01( DLv05, ( OutPut, "***** %s:MsgType=%08x\n", D_PROC_NAME, ptMsgHed->lMsgType ) );
			
		if( ( ptMsgHed->lMsgType == D_MTYPE07 ) ||
			( ptMsgHed->lMsgType == D_MTYPE08 ) )
		{
			/****************************************/
			/* ��å���������¤�Τ�               */
			/* �ס���Хåե����ɥ쥹���ϰϥ����å� */
			/****************************************/
			lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
			lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

			if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
				( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
			{
										/* �ס���Хåե���������ݥ�������       */
				ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);
										/* ��˥åȴ�������ݥ�������             */
				ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

										/* ���ѥץ���ID�˼��ץ���ID������       */
				ptEpbcInd->lUsePid = lMyPid;
										/* ���������ס���Хåե����ɥ쥹������		*/
				palPlList[0] = ptMsgHed->pcPlBuf;
										/* �ס���Хåե��β���						*/
				iRet = osfrpbf(1L, &palPlList[0]);
			}
		}
/*****  �㳲�б���TBCS0221��	End										��������2003.07.24  *****/

		/********************************************/
		/*	��ͭ����κ��						*/
		/********************************************/
		os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMDT, 1, ptIndAdr->tSubMsgQ.ptNxtAdr );
		
		iRet = shmdt( ptIndAdr->tSubMsgQ.ptNxtAdr );
									
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );			
							
										// ��ͭ����Υǥ��å�
		if( iRet == D_ERR_SYS )			// ����˼��Ԥ�����
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );	
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS2);
			//return( -1 );				// ++++++++���ܡ���ͽ��++++++++
		}
		
		os_trcget2( D_MD_OSDELMB, D_T_SYS_SHMCTL, 3, ptIndAdr->tSubMsgQ.lShmId, IPC_RMID, NULL );
		
		iRet = shmctl( ptIndAdr->tSubMsgQ.lShmId, IPC_RMID, NULL );
		
		os_trcget2( D_MD_OSDELMB, D_T_SYS_END, 1, iRet );
		
										// ��ͭ����κ��
		if( iRet == D_ERR_SYS )			// ����˼��Ԥ�����
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );	
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS3);
			//return( -1 );				// ++++++++���ܡ���ͽ��++++++++
		}
		ptIndAdr->tSubMsgQ.ptNxtAdr	= D_MSGINFO_NONE;
		ptIndAdr->tSubMsgQ.ptBefAdr	= D_MSGINFO_NONE;
		ptIndAdr->tSubMsgQ.lMsgCnt	= 0;
		ptIndAdr->tSubMsgQ.lShmId	= D_SHMID_NONE;
										// ���֥�å��������塼�Υ��ꥢ
	}

/*****  �㳲�б���TBCS0221��	Start									��������2003.07.24  *****/
/************************************************************************************************/
/*  �������Υ�å��������塼�ɣĥ��ꥢ�ΰ�ư�ˤ����                                          */
/************************************************************************************************/
/*****  �㳲�б���TBCS0221��	End										��������2003.07.24  *****/

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSDELMB, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMAL���ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_osdelmb:
	switch( errno )
	{
		case EACCES:					// EACCES�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENACC ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEENACC );			// OSEENACC���ֵ�
			break;
		case EFAULT:					// EFAULT�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEEEXST );			// OSEEEXST���ֵ�
			break;
		case EIDRM:						// EIDRM�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEENEXS );			// OSEENEXS���ֵ�
			break;
		case EINVAL:					// EINVAL�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEWKEX ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1, errno    );
			
			return( OSEEWKEX );			// OSEEWKEX���ֵ�
			break;
		default:						// ����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELMB, D_T_ERR_SYS, 1 , errno );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELMB << 16) | D_T_ERR_SYS4);
			//return( -1 );				// ++++++++���ܡ���ͽ��++++++++
	}
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
