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
/* ��⥸�塼��̾��					 �ס���Хåե���Υ�å���������							*/
/* ��⥸�塼��ɣġ�				 osrcvmsp													*/
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
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ��������� 	�㳲�б���KL0020��				*/
/* �㥽���������ԡ�					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ס���Хåե���Υ�å������μ��� 														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osrcvmsp.h>																*/
/*																								*/
/*	   	long	osrcvmsp( long mpid, long limit, char **bufaa ) 								*/
/*																								*/
/* �㲾������																					*/
/*		long	mpid;		�ᥤ��ܥå������ϥץ������̻�									*/
/*		long	limit;		���»���(-1�ʾ�)													*/
/*		char	**bufaa;	�ס���Хåե����ɥ쥹��Ǽ��     									*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		msgrcv�����ƥॳ������ֵ��ͤ��ֵ�										*/
/*		�۾ｪλ		os_GetEmbcTableInd���ֵ���		mpid���������ϥᥤ��ܥå�������		*/
/*														�ơ��֥��������̵��					*/
/*						OSEEILIM						���»��֤��ϰϳ����ͤ����ꤵ��Ƥ���	*/
/*						OSEENPOL						���ѥץ���ID���������0xffffffff�˰ʳ�*/
/*						OSEENACC						�������������ʤ�(READ��)				*/
/*						OSEEIPOL						��å���������¤�ΤΥ��ɥ쥹���ϰϳ�	*/
/*						OSEEDELD						���ꤷ���ᥤ��ܥå�����������줿		*/
/*						OSEETOUT						���»�����˥�å����������夷�ʤ��ä�	*/
/*						OSEEISIZ																*/
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
#include <sys/types.h>				/* msgrev()�ѥإå��ե����� */
#include <sys/ipc.h>				/* msgrev()�ѥإå��ե����� */
#include <sys/msg.h>				/* msgrev()�ѥإå��ե����� */
#include <stdlib.h>					/* abort()�ѥإå��ե����� */
#include <errno.h>					/* errno�ѥإå��ե����� */
#include <string.h>

/* ���ѼԺ����إå��ե����� */
#include "osrcvmsp.h"
#include "osrcvmsp_ins.h"
#include "os_MsgQDel_ins.h"

/*****************************************************************************/
/* ��ǽ���ס���Хåե���Υ�å������μ���                                  */
/* ��������2002ǯ10��04��                                                    */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�                                                                  */
/* �ƽз�����                                                                */
/*   long osrcvmsp( long mpid, long limit, char **bufaa )                    */
/*       long mpid        �ᥤ��ܥå������ϥץ������̻�                   */
/*       long limit       ���»���(-1�ʾ�)                                   */
/*       char **bufaa     �ס���Хåե����ɥ쥹��Ǽ��                       */
/*****************************************************************************/
long osrcvmsp( long mpid, long limit, char **bufaa )
{
	long	lRet;									/* �ؿ�����ֵ�								*/
	long	lMessageLength;							/* �ֵѥ�å�����Ĺ							*/
	long	lAsso;									/* ����										*/
	long	lMessageType;							/* msgrcv()���裴������						*/
	int		iMessageFlag;							/* msgrcv()���裵������						*/
	long	lBufferPoolTopAddr;						/* �Хåե��ס�����Ƭ���ɥ쥹				*/
	long	lBufferPoolBottomAddr;					/* �Хåե��ס���������ɥ쥹				*/
	char			*pcWorkPtr = NULL;				/* ����ݥ���							*/
	TMsgHed			*ptMsgHed  = NULL;				/* ��å������ݥ���						*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* �ᥤ��ܥå����ơ��֥�������Υ��ɥ쥹	*/
	TMsgInfo		*tMsgInfo  = NULL;				/* ��å���������¤�ΤΥ��ɥ쥹			*/
	TEpbcTableInd	*ptEpbcInd = NULL;				/* ��˥åȴ�������¤�Υ��ɥ쥹			*/
	TPbInfo			*ptPbInfo  = NULL;				/* �ס���Хåե���������ݥ���			*/
/*****  �㳲�б���TBCS0118��	Start									��������2003.06.09  *****/
	TEprcTableInd   *ptEprcTblInd;					/* �ץ��������ơ��֥���������ɥ쥹		*/
	long			lLimit;							/* �ץ��������ơ��֥��������				*/
	long			lTmpCode;						/* �ץ������̻�							*/
	long			lTempId;						/* �ץ���ID								*/
	long			lCnt;
/*****  �㳲�б���TBCS0118��	End										��������2003.06.09  *****/

	os_trcget2( D_MD_OSRCVMSP, D_T_TRA_IN, 3, mpid, limit, *bufaa );


													/* �ؿ�����									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvmsp" ) );

//	DbgMsg01(DLv04, (OutPut, "***** %s:mpid =%08lx \n", "osrcvmsp", mpid));
//	DbgMsg01(DLv04, (OutPut, "***** %s:limit=%ld \n", "osrcvmsp", limit));
//	DbgMsg01(DLv04, (OutPut, "***** %s:bufaa =%08lx \n\n", "osrcvmsp", (long)bufaa));


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	/************************************************/
	/*	�ᥤ��ܥå��������ơ��֥�					*/
	/*	��������Ƭ���ɥ쥹�μ���					*/
	/************************************************/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );	/* ���̻�(����mpid)�Υ����å�				*/
	if( lRet != NORMAL )
	{
		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_PRA, 1, lRet );
		
		return( lRet );								/* mpid������������							*/
													/* �ᥤ��ܥå��������ơ��֥��������̵��	*/
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvmsp", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd=%08lx \n", "osrcvmsp", ptEmbcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvmsp", ptEmbc->lMaxMsgLng));

	/************************************************/
	/*	�����γ�ǧ									*/
	/************************************************/
	if( limit < D_TIMELIMIT_NOLIMIT )				/* ���»���(����limit)�Υ����å�			*/
	{
		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_PRA, 1, OSEEILIM );
		
		return( OSEEILIM );							/* ���»��֤��ϰϳ����ͤ����ꤵ��Ƥ���		*/
	}


	/********************************************************************************************/
	/*  �ܽ���                                                                                  */
	/********************************************************************************************/
	/************************************/
	/* ���֥��塼����Υ�å���������	*/
	/************************************/
	lAsso = os_GetAsso( mpid );						/* ���̤μ���								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvmsp", lAsso));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.lMsgCnt=%ld \n", "osrcvmsp",
			ptEmbcInd->tSubMsgQ.lMsgCnt));

	/************************************************/
	/*	������å�������̵ͭ�����å�				*/
	/************************************************/
													/* ���֥�å��������塼��					*/
													/* ��å�������Ǽ����0�ʳ��ξ��			*/
	if( ptEmbcInd->tSubMsgQ.lMsgCnt != 0 )
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.ptNxtAdr=%08x \n", "osrcvmsp",
				ptEmbcInd->tSubMsgQ.ptNxtAdr));

/*****  �㳲�б���TBCS0118��	Start									��������2003.06.09  *****/
		/********************************************/
		/*  �����ץ���ID�μ���					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* �ץ��������ơ��֥������				*/
													/* ��Ƭ���ɥ쥹�μ���						*/
		
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", "osrcvmsp",
				ptEprcTblInd));
		
		lLimit = ptEprc->lIndPartNum;				/* �ץ��������ơ��֥������������			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* �ץ��������ơ��֥�θ���				*/
		{
													/* �������ץ������̻Ҥμ���				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;
			
			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", "osrcvmsp",
				lTmpCode));
			
			if( lTmpCode == ptEmbcInd->lPCode )		/* �ץ������̻Ҥ�����						*/
			{
													/* �ץ���ID�μ���							*/
				lTempId = (ptEprcTblInd + lCnt)->lPid;
				break;
			}
		}
		if ( lCnt == lLimit )						/* ���פ���ץ������̻Ҥ�¸�ߤ��ʤ�		*/
		{
													/* ���ܡ���									*/
			os_trcget2( D_MD_OSRCVMSP, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS3 );
		}

		/********************************************/
		/*  ���֥�å��������塼�Υ����å�			*/
		/********************************************/
		if( lTempId != lMyPid )						/* �����ץ���ID�����ץ���ID�ʳ�			*/
		{
			lRet = os_SubMsgAtc2(ptEmbcInd);		/* ����Υ����å�							*/
			if( lRet != NORMAL )					/* �۾ｪλ�ξ��							*/
			{
				/* ���ܡ���									*/
				os_trcget2( D_MD_OSRCVMSP, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS4 );
			}
		}
/*****  �㳲�б���TBCS0118��	End										��������2003.06.09  *****/

		/************************************/
		/*  �����оݥ�å������θ���		*/
		/************************************/
		while(1)
		{
			/********************************************/
			/*	��Ƭ��å����������					*/
			/********************************************/
			if (NULL == tMsgInfo)					/* ��å���������ݥ��󥿤�NULL�ξ��		*/
			{
													/* ���֥�å��������塼�μ����ɥ쥹������	*/
				tMsgInfo = ptEmbcInd->tSubMsgQ.ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* ������å������Υ��ɥ쥹������			*/
			}
			else
			{
				if (NULL == tMsgInfo->ptNxtAdr)		/* ��å���������μ����ɥ쥹��NULL�ξ��	*/
				{
					break;							/* �롼�פ�ȴ����							*/
				}
				
													/* ����å���������μ����ɥ쥹������		*/
				tMsgInfo = (TMsgInfo *)tMsgInfo->ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* ������å������Υ��ɥ쥹������			*/

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo = %08x, ptMsg = %08x \n", "osrcvmsp",
						tMsgInfo, ptMsgHed));
			}

			/****************************************/
			/*	�оݥ�å������μ���				*/
			/****************************************/
//			if( ( ( lAsso  == D_ASSO_PROCESS ) && ( ptMsgHed->lMsgType == D_MTYPE04 ) ) ||
//				( ( lAsso  == D_ASSO_MAILBOX ) && ( ptMsgHed->lMsgType == D_MTYPE05 ) ) )
													/* ���̤��֣�(�ץ������̻�)�פ���			*/
													/* ����������å����������פ�				*/
													/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�ʥץ������ˤξ��				*/
													/* ����										*/
													/* ���ѥ�᡼������0�פ���				*/
													/* ����������å����������פ�				*/
													/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�ʥץ������ˤξ��				*/
													/* ����										*/
													/* ���̤��֣�(�ᥤ��ܥå������̻�)�פ���	*/
													/* ����������å����������פ�				*/
													/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�ʥᥤ��ܥå������ˤξ��		*/
			if( ( ( D_ASSO_PROCESS == lAsso ) && ( D_MTYPE08 == ptMsgHed->lMsgType ) ) ||
			    ( ( 0 == mpid ) && ( D_MTYPE08 == ptMsgHed->lMsgType ) ) ||
				( ( D_ASSO_MAILBOX == lAsso ) && ( D_MTYPE07 == ptMsgHed->lMsgType  ) ) )
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:lAsso =%ld \n", "osrcvms", lAsso));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed->lMsgType=%08lx \n", "osrcvms",
						ptMsgHed->lMsgType));

													/* ���֥�å��������塼��					*/
													/* ���������å�������¸�ߤ������			*/
				/****************************************/
				/* ��å���������¤�Τ�				*/
				/* �ס���Хåե����ɥ쥹���ϰϥ����å� */
				/****************************************/
				lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
				lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

				if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
					 ( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
				{
													/* ��˥åȴ�����¤�Τ���Ƭ���ɥ쥹������	*/
//					ptEpbcInd = (TEpbcTableInd *)( lBufferPoolTopAddr - 4 );
													/* �ס���Хåե���������ݥ�������		*/
					ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);

													/* ��˥åȴ�������ݥ�������				*/
					ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

					DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd=%08x \n", "osrcvmsp",
							ptEpbcInd));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd->lUsePid=%08x \n", "osrcvmsp",
							ptEpbcInd->lUsePid));

													/* ���ѥץ���ID���������0xffffffff�˰ʳ� */
					if( D_EPBC_USEPID_SEND != ptEpbcInd->lUsePid )
					{
						os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEENPOL );
						
						return(OSEENPOL);			/* �۾ｪλ��not pool buffer��				*/
					}

					ptEpbcInd->lUsePid = lMyPid;	/* ���ѥץ���ID�˼��ץ���ID������		*/

					*bufaa = ptMsgHed->pcPlBuf;		/* ���������ס���Хåե����ɥ쥹������		*/

													/* �ֵѥ�å�����Ĺ��						*/
													/* ������å�����������������				*/
					lMessageLength = ptMsgHed->lDataSize;

					/********************************/
					/*  �����						*/
					/********************************/
													/* ���֥�å��������塼�������				*/
					lRet = os_MsgQDel(&ptEmbcInd->tSubMsgQ, tMsgInfo);
					if (-1 == lRet)
					{
													/* �㳲ȯ��									*/
						DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
								"osrcvmsp", "os_MsgQDel() Call Error!!  ��ͭ�������Ǽ���"));
								
						os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEWKEX );
								
						return(OSEEWKEX);			/* �۾ｪλ��sys work area exhaust��		*/
					}

													/* �ؿ��и�									*/
					DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsp" ) );
					
					os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, lMessageLength );
					
					return( lMessageLength );
				}
				else
				{
					os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEIPOL );
					
					return( OSEEIPOL );				/* ��å���������¤�ΤΥ��ɥ쥹���ϰϳ�	*/
				}
			}
		}
	}


	/************************************/
	/* �ᥤ���å��������塼����μ��� */
	/************************************/
													/* ���������»��֤����ꤵ��Ƥ����硢		*/
													/* �����ƥॳ���륿���ޤ�ȯ�Ԥ���			*/
	if( limit >= 1 )
	{
		lRet = os_systim( limit, 1, 100 );
		if( lRet != NORMAL )
		{
			os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 0 );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS );
                    								/* ���ܡ��Ƚ���								*/
		}
	}
//	if( lAsso == D_ASSO_PROCESS )
	if( ( lAsso == D_ASSO_PROCESS ) || ( 0 == mpid ) )
	{
//		lMessageType = D_MTYPE04;					/* �ץ������ס���Хåե�ͭ��				*/
		lMessageType = D_MTYPE08;					/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�ʥץ�������		*/
	}
	else
	{
//		lMessageType = D_MTYPE05;					/* �ᥤ��ܥå������ס���Хåե�ͭ��		*/
		lMessageType = D_MTYPE07;					/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ᥤ��ܥå�����)	*/
	}
	if( limit == 0 )
	{												/* msgrcv�ذ����Ϥ���å������ե饰������	*/
		iMessageFlag = IPC_NOWAIT;
	}
	else
	{
		iMessageFlag = MSG_NOERROR;
	}

	/************************************/
	/*  ��å���������					*/
	/************************************/
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_MALLOC, 1, ptEmbc->lMaxMsgLng );	

													/* ���������������						*/
//	pcWorkPtr = malloc(ptEmbc->lMaxMsgLng);			/* �ᥤ��ܥå����������κ����å�����Ĺ	*/
													/* �ᥤ��ܥå����������κ����å�����Ĺ	*/
//	pcWorkPtr = malloc( (ptEmbc->lMaxMsgLng) + sizeof(TMsgHed) );	// 20030127 ����

	pcWorkPtr = calloc(1, sizeof(TMsgHed) );		// 20030305 ����
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 1, pcWorkPtr );	
	
	if (NULL == pcWorkPtr)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"osrcvmsp", "malloc() Call Error!!", errno, strerror(errno)));
			
		os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_SYS, 1, OSEEWKEX );
			
		return(OSEEWKEX);							/* �۾ｪλ��sys work area exhaust��		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;				/* �ץ����֥�å������ݥ�������			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%08x \n",
						"osrcvmsp",ptEmbc->lMaxMsgLng));

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08x \n","osrcvmsp", ptMsgHed));
	
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMBoxId=%08lx \n",
						"osrcvmsp", ptEmbcInd->lMBoxId));

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMsgQId=%ld \n",
						"osrcvmsp", ptEmbcInd->lMsgQId));

	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		/* �����ƥॿ���ޥե饰�ν����				*/

	for( ; ; )
	{
//		DbgDmp02( DLv04, ("## osrcvmsp msgrcv�� ", ptMsgHed, sizeof(TMsgHed),1,0));

//		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
//		                             sizeof(TMsgHed), lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
					sizeof(TMsgHed) - sizeof(long), lMessageType, iMessageFlag );

		/***** �ξ����ɼKL0020���б�	Start							��������2003.02.27	*****/
//		lMessageLength = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, ptEmbc->lMaxMsgLng,
//								 lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, ptEmbc->lMaxMsgLng,
//								 lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, sizeof(TMsgHed),
//								 lMessageType, iMessageFlag );

														// 20030329 �ѹ�
														// �����������ϥ�å�����������
														// �����������������ꤹ��
		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, sizeof(TMsgHed) - sizeof(long),
								 lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMSP, D_T_SYS_END, 2, lRet, errno );

//		DbgDmp02( DLv04, ("## osrcvmsp msgrcv�� ", ptMsgHed, sizeof(TMsgHed),1,0));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msqid =%08lx\n","osrcvmsp",ptEmbcInd->lMsgQId));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() *msgp =%08lx\n","osrcvmsp",(long)ptMsgHed));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgsz =%ld  \n","osrcvmsp",ptEmbc->lMaxMsgLng));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgtyp=%08lx\n","osrcvmsp",lMessageType));
//		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgflg=%d   \n","osrcvmsp",iMessageFlag));

		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() Ret   =%08lx\n","osrcvmsp",lRet));

		/********************************************/
		/*	������̤��Խ�							*/
		/********************************************/
//		if( lMessageLength != D_ERR_SYS )			/* �����ƥॳ������ֵ��ͤ�����ξ��		*/
		if( lRet != D_ERR_SYS )						/* �����ƥॳ������ֵ��ͤ�����ξ��		*/
		{
													/* ���������»��֤����ꤵ��Ƥ����硢		*/
													/* �����ƥॳ���륿���ޤΥ��ꥢ��ȯ�Ԥ���	*/
			if( limit >= 1 )
			{
				lRet = os_tmcan( 0 );				/* �����ޥ���󥻥�							*/
				if( lRet != NORMAL )
				{
					os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 0 );
					
			        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS1);
                    								/* ���ܡ��Ƚ���								*/
				}
			}
													/* ���������Хåե����ɥ쥹���ϰϥ����å�	*/
//			ptMsgHed = (TMsgHed *)*bufaa;
			lBufferPoolTopAddr = (long)ptEbpc->pvAdr;
			lBufferPoolBottomAddr = lBufferPoolTopAddr + ptEbpc->lSize;

			if ( ( (long)ptMsgHed->pcPlBuf >= lBufferPoolTopAddr  ) &&
				 ( (long)ptMsgHed->pcPlBuf <= lBufferPoolBottomAddr ) )
			{
													/* ��˥åȴ�����¤�ΤΥ��ɥ쥹�����ꤹ��	*/
//				ptEpbcInd = (TEpbcTableInd *)( lBufferPoolTopAddr - 4 );
													/* �ס���Хåե���������ݥ�������		*/
				ptPbInfo = (TPbInfo *)(ptMsgHed->pcPlBuf - 4);

													/* ��˥åȴ�������ݥ�������				*/
				ptEpbcInd = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

				DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd=%08x \n", "osrcvmsp",
						ptEpbcInd));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcInd->lUsePid=%08x \n", "osrcvmsp",
						ptEpbcInd->lUsePid));

													/* ���ѥץ���ID���������0xffffffff�˰ʳ� */
				if( D_EPBC_USEPID_SEND != ptEpbcInd->lUsePid )
				{
					os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEENPOL );	
					
					return( OSEENPOL );				/* �۾ｪλ��not pool buffer��				*/
				}

				ptEpbcInd->lUsePid = lMyPid;		/* ���ѥץ���ID�˼��ץ���ID������		*/

				*bufaa = ptMsgHed->pcPlBuf;			/* ���������ס���Хåե����ɥ쥹������		*/

													/* �ֵѥ�å�����Ĺ��						*/
													/* ������å�����������������				*/
				lMessageLength = ptMsgHed->lDataSize;
				DbgMsg01(DLv04,(OutPut,"***** %s:lMessageLength=%ld\n","osrcvmsp",lMessageLength));
			}
			else
			{
				os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_FREE, 1, pcWorkPtr );
				
				free(pcWorkPtr);					/* �������								*/
				
				os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 0 );
				
				os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, OSEEIPOL );		
				
				return( OSEEIPOL );					/* ��å���������¤�ΤΥ��ɥ쥹���ϰϳ�	*/
			}
			break;
		}
		else
		{											/* �����ƥॳ������ֵ��ͤ��۾�ξ��		*/
/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰��Ƚ���������												*/
/************************************************************************************************/
//			if( errno == EINTR && ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF )

													/* errno �� EINTR ����						*/
													/* �����ƥॳ���륿���ޥե饰����̤ȯ�ԡ�	*/
													/* ���ϡ�ȯ����פξ��						*/
			if( ( errno == EINTR ) &&
				( ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF ) ||
				  ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_ON  ) ) )
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvmsp",
						"EINTR���顼", errno));
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
						"osrcvmsp", "��ȥ饤������", ptEtmc->cSysTimeFlg));

				continue;							/* ���٥�å�����������Ԥ�					*/
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvmsp",
						"EINTR�ʳ��Υ��顼", errno));
/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰�Υ��ꥢ���ɲ�													*/
/************************************************************************************************/
													/* �����ƥॿ���ޥե饰�ν����				*/
				ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/
				break;
			}
		}
	}
	
	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_FREE, 1, pcWorkPtr );

	free(pcWorkPtr);								/* �������								*/

	os_trcget2( D_MD_OSRCVMSP,  D_T_SYS_END, 0 );

	/********************************************************************************************/
	/*  ��λ����                                                                                */
	/********************************************************************************************/
//	if( lMessageLength != -1 )
	if( lRet != -1 )
	{												/* �����ƥॳ������ֵ��ͤ�����ξ��		*/
													/* �ؿ��и�									*/
//		DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsp" ) );
//		return( lMessageLength );					/* msgrcv�����ƥॳ������ֵ��ͤ��ֵ�		*/

//		os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, ptMsgHed->lDataSize );
//		return( ptMsgHed->lDataSize );				/* msgrcv�����ƥॳ������ֵ��ͤ��ֵ�		*/

		os_trcget2( D_MD_OSRCVMSP, D_T_TRA_OUT, 1, lMessageLength );
		return( lMessageLength );					/* msgrcv�����ƥॳ������ֵ��ͤ��ֵ�		*/
	}
	/***** �ξ����ɼKL0020���б�	 	 End							��������2003.02.27	*****/


	/********************************************************************************************/
	/*  �۾����                                                                                */
	/********************************************************************************************/
	switch( errno )
	{
		case E2BIG :
		case EINVAL :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "�����۾�!!", "��å����������Υ���������θ�ꡣ"));
		 	
		 	os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );		
		 			
			return( OSEEISIZ );

		case EACCES :
		case EFAULT :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "�����۾�!!", "�����������Ĥʤ���"));
		 			
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );
		 			
			return( OSEENACC );						/* �������������ʤ�(READ��)					*/

		case EIDRM :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "�����۾�!!", "��å��������塼���������Ƥ��롣"));
		 			
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );
		 			
			return( OSEEDELD );						/* ���ꤷ���ᥤ��ܥå�����������줿		*/

		case ENOMSG :
		case EINTR :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvmsp", "�����۾�!!", "�����ॢ���ȡ�"));
		 	
	 		os_trcget2( D_MD_OSRCVMSP, D_T_ERR_SYS, 1, errno );		
		 			
			return( OSEETOUT );						/* ���»�����˥�å����������夷�ʤ��ä�	*/

		default :
			os_trcget2( D_MD_OSRCVMSP,  D_T_ERR_ABT, 1, errno );
		
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMSP << 16) | D_T_ERR_SYS2);
                    								/* ���ܡ��Ƚ���								*/
	}
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
