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
/* ��⥸�塼��̾��					 ��å������μ���											*/
/* ��⥸�塼��ɣġ�				 osrcvms													*/
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
/* �㥽���������ԡ� 			 	 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ��å������μ���																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osrcvms.h>																	*/
/*																								*/
/*	   	long osrcvms( long mpid, long limit, long size, char *bufa ) 							*/
/*																								*/
/* �㲾������																					*/
/*		long	mpid;		�ᥤ��ܥå������ϥץ������̻�									*/
/*		long	limit;		���»���(-1�ʾ�)													*/
/*		long	size;		��å�����Ĺ������(1��32768(SG))									*/
/*		char	*bufa;		��å����������Хåե�												*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		��å�����Ĺ															*/
/*		�۾ｪλ		os_GetEmbcTableInd���ֵ���												*/
/*						OSEEISIZ			���������ϰϳ����ͤ����ꤵ��Ƥ���					*/
/*						OSEEILIM			���»��֤��ϰϳ����ͤ����ꤵ��Ƥ���				*/
/*						OSEENACC																*/
/*						OSEEDELD																*/
/*						OSEETOUT																*/
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
#include <sys/types.h>								/* msgrev()�ѥإå��ե�����					*/
#include <sys/ipc.h>								/* msgrev()�ѥإå��ե�����					*/
#include <sys/msg.h>								/* msgrev()�ѥإå��ե�����					*/
#include <errno.h>									/* errno�ѥإå��ե�����					*/
#include <string.h>

/* ���ѼԺ����إå��ե����� */
#include "osrcvms.h"
#include "osrcvms_ins.h"
#include "os_MsgQDel_ins.h"

/*****************************************************************************/
/* ��ǽ����å������μ���                                                    */
/* ��������2002ǯ10��04��                                                    */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�                                                                  */
/* �ƽз�����                                                                */
/*   long osrcvms( long mpid, long limit, long size, char *bufa )            */
/*       long mpid        �ᥤ��ܥå������ϥץ������̻�                   */
/*       long limit       ���»���(-1�ʾ�)                                   */
/*       long size        ��å�����Ĺ������(1��32768(SG))                   */
/*       char *bufa       ��å����������Хåե�                             */
/*****************************************************************************/
long osrcvms( long mpid, long limit, long size, char *bufa )
{
	long	lRet = 0;								/* �ؿ�����ֵ�								*/
	long	lMessageLength = 0;						/* �ֵѥ�å�����Ĺ							*/
	long	lAsso = 0;								/* ����										*/
	long	lMessageType = 0;						/* msgrcv()���裴������						*/
	int		iMessageFlag = 0;						/* msgrcv()���裵������						*/
	char			*pcWorkPtr = NULL;				/* ����ݥ���							*/
	TMsgHed			*ptMsgHed = NULL;				/* ��å��������ΤΥ��ɥ쥹					*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* �ᥤ��ܥå����ơ��֥�������Υ��ɥ쥹	*/
	TMsgInfo		*tMsgInfo  = NULL;				/* ��å���������¤�ΤΥ��ɥ쥹			*/
/*****  �㳲�б���TBCS0118��	Start									��������2003.06.09  *****/
	TEprcTableInd	*ptEprcTblInd;					/* �ץ��������ơ��֥���������ɥ쥹		*/
	long			lLimit;							/* �ץ��������ơ��֥��������				*/
	long			lTmpCode;						/* �ץ������̻�							*/
	long			lTempId;						/* �ץ���ID								*/
	long			lCnt;
/*****  �㳲�б���TBCS0118��	End										��������2003.06.09  *****/

	os_trcget2( D_MD_OSRCVMS, D_T_TRA_IN, 4, mpid, limit, size, bufa  );

													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvms" ) );

	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:mpid =%08lx \n", "osrcvms", mpid));
	DbgMsg01(DLv04, (OutPut, "***** %s:limit=%ld \n", "osrcvms", limit));
	DbgMsg01(DLv04, (OutPut, "***** %s:size =%ld \n", "osrcvms", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:bufa =%08lx \n\n", "osrcvms", (long)bufa));

	/************************************************/
	/*	�ᥤ��ܥå��������ơ��֥�					*/
	/*	��������Ƭ���ɥ쥹�μ���					*/
	/************************************************/
													/* mpid�Υ����å����ڤӥᥤ��ܥå�������	*/
													/* �ơ��֥��������Ƭ���ɥ쥹����			*/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );
	if( lRet != NORMAL )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  lRet=%08lx \n", "osrcvms",
				"�����۾�!!", "���ꤷ���ᥤ��ܥå�����¸�ߤ��ʤ������Ϻ�����줿��", lRet));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, lRet );		
		return( lRet );								/* �ֵ��ͤ��۾�λ��Ϥ����ֵ��ͤ�			*/
													/* ���Τޤ��ֵѤ���							*/
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvms", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd=%08lx \n", "osrcvms", ptEmbcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvms", ptEmbc->lMaxMsgLng));

	/************************************************/
	/*	�����γ�ǧ									*/
	/************************************************/
													/* ��å���������Ĺ(����size)���ϰϥ����å� */
	if( size < D_MSGSIZE_MIN || size > ptEmbc->lMaxMsgLng )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  size=%ld \n", "osrcvms",
				"�����۾�!!", "��å�����Ĺ�����ͤ������Ǥ��롣", size));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, OSEEISIZ );		
		return( OSEEISIZ );							/* ���������ϰϳ����ͤ����ꤵ��Ƥ���		*/
	}

	if( limit < D_TIMELIMIT_NOLIMIT )				/* ���»���(����limit)�Υ����å�			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  limit=%ld \n", "osrcvms",
				"�����۾�!!", "���»��֤������Ǥ��롣", limit));

		os_trcget2( D_MD_OSRCVMS, D_T_ERR_PRA, 1, OSEEILIM );		
		return( OSEEILIM );							/* ���»��֤��ϰϳ����ͤ����ꤵ��Ƥ���		*/
	}


	/********************************************************************************************/
	/*  �ܽ���                                                                                  */
	/********************************************************************************************/
	/************************************/
	/* ���֥��塼����Υ�å���������	*/
	/************************************/
	lAsso = os_GetAsso( mpid );						/* ���̤����								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvms", lAsso));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.lMsgCnt=%ld \n", "osrcvms",
			ptEmbcInd->tSubMsgQ.lMsgCnt));

	/************************************************/
	/*	������å�������̵ͭ�����å�				*/
	/************************************************/
													/* ���֥�å��������塼��					*/
													/* ��å�������Ǽ����0�ʳ��ξ��			*/
	if( ptEmbcInd->tSubMsgQ.lMsgCnt != 0 )
	{									
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->tSubMsgQ.ptNxtAdr=%08x \n", "osrcvms",
				ptEmbcInd->tSubMsgQ.ptNxtAdr));
	
/*****  �㳲�б���TBCS0118��	Start									��������2003.06.09  *****/
		/********************************************/
		/*  �����ץ���ID�μ���					*/
		/********************************************/
		ptEprcTblInd = (TEprcTableInd *)(ptEprc+1); /* �ץ��������ơ��֥������				*/
													/* ��Ƭ���ɥ쥹�μ���						*/
	
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcTblInd=%08x \n", "osrcvms",
				ptEprcTblInd));

		lLimit = ptEprc->lIndPartNum;				/* �ץ��������ơ��֥������������			*/
		lTempId = lMyPid;

		for( lCnt = 0; lCnt < lLimit; lCnt++ )		/* �ץ��������ơ��֥�θ���				*/
		{
													/* �������ץ������̻Ҥμ���				*/
			lTmpCode = (ptEprcTblInd + lCnt)->lPCode;

			DbgMsg01(DLv04, (OutPut, "***** %s:lPCode=%08x \n", "osrcvms",
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
			os_trcget2( D_MD_OSRCVMS, D_T_ERR_ABT, 0 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS3 );
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
				os_trcget2( D_MD_OSRCVMS, D_T_ERR_ABT, 0 );
				os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS4 );
			}
		}
/*****  �㳲�б���TBCS0118��	End										��������2003.06.09  *****/

		/************************************/
		/*  �����оݥ�å������θ���		*/
		/************************************/
		while(1)
		{
			/****************************************/
			/*	��Ƭ��å����������				*/
			/****************************************/
			if (NULL == tMsgInfo)					/* ��å���������ݥ��󥿤�NULL�ξ��		*/
			{
													/* ���֥�å��������塼�μ����ɥ쥹������	*/
				tMsgInfo = ptEmbcInd->tSubMsgQ.ptNxtAdr;
				ptMsgHed = tMsgInfo->pvMsgAdr;		/* ������å������Υ��ɥ쥹������			*/

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo=%08x, ptMsgHed=%08x \n", "osrcvms",
						tMsgInfo, ptMsgHed));
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

				DbgMsg01(DLv04, (OutPut, "***** %s:tMsgInfo=%08x, ptMsgHed=%08x \n", "osrcvms",
						tMsgInfo, ptMsgHed));
			}

			/****************************************/
			/*	�оݥ�å���������					*/
			/****************************************/
//			if( ( lAsso  == D_ASSO_PROCESS && ptMsgHed->lMsgType == D_MTYPE02 ) ||
//				( lAsso  == D_ASSO_MAILBOX && ptMsgHed->lMsgType == D_MTYPE03 ) )
													/* ���̤��֣�(�ץ������̻�)�פ���			*/
													/* ����������å����������פ�				*/
													/* ��å������μ����׵�ʥץ������ˤξ��	*/
													/* ����										*/
													/* ���ѥ�᡼������0�פ���				*/
													/* ����������å����������פ�				*/
													/* ��å������μ����׵�ʥץ������ˤξ��	*/
													/* ����										*/
													/* ���̤��֣�(�ᥤ��ܥå������̻�)�פ���	*/
													/* ����������å����������פ�				*/
													/* ��å������μ����׵�ʥᥤ��ܥå������� */
													/* �ξ��									*/
			if( ( ( D_ASSO_PROCESS == lAsso ) && ( D_MTYPE06 == ptMsgHed->lMsgType ) ) ||
			    ( ( 0 == mpid ) && ( D_MTYPE06 == ptMsgHed->lMsgType ) ) ||
				( ( D_ASSO_MAILBOX == lAsso ) && ( D_MTYPE05 == ptMsgHed->lMsgType  ) ) )
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:lAsso =%ld \n", "osrcvms", lAsso));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed->lMsgType=%08lx \n", "osrcvms",
						ptMsgHed->lMsgType));
				DbgMsg01(DLv04, (OutPut, "***** %s:size =%ld, ptMsgHed->lDataSize \n", "osrcvms",
						size, ptMsgHed->lDataSize));

													/* ���֥�å��������塼��					*/
													/* ���������å�������¸�ߤ������			*/

													/* ��å�����Ĺ���¤�Ƚ��					*/
//				if( size < tMsgInfo->lMsgSize )
				if( size < ptMsgHed->lDataSize )	/* ��å�����Ĺ����ͭ��						*/
				{
					lMessageLength = size;
				}
				else								/* ��å�����Ĺ����̵��						*/
				{
//					lMessageLength = tMsgInfo->lMsgSize;
					lMessageLength = ptMsgHed->lDataSize;
				}
													/* ��å����������Хåե��˥��ԡ�			*/
				memcpy(bufa, ptMsgHed + 1, lMessageLength);

				/********************************/
				/*  �����						*/
				/********************************/
													/* ���֥�å��������塼�������				*/
				lRet = os_MsgQDel(&ptEmbcInd->tSubMsgQ, tMsgInfo);
				if (-1 == lRet)
				{
													/* �㳲ȯ��									*/
					DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
							"osrcvms", "os_MsgQDel() Call Error!!  ��ͭ�������Ǽ���"));
					os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, OSEEWKEX );	
					return(OSEEWKEX);				/* �۾ｪλ��sys work area exhaust��		*/
				}
													/* �ؿ��и�									*/
				DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvms" ) );
				os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, lMessageLength );	
				return( lMessageLength );		/* bufa�إ��ԡ������ΰ�Ĺ���ֵѤ���			*/
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
			os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 0 );	
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS );
                                                	/* ���ܡ��Ƚ���								*/
		}
	}
													/* msgrcv�ذ����Ϥ���å����������פ�����	*/
//	if( lAsso == D_ASSO_PROCESS )
	if( ( lAsso == D_ASSO_PROCESS ) || ( 0 == mpid ) )
	{
//		lMessageType = D_MTYPE02;					/* �ץ������ס���Хåե�̵��				*/
		lMessageType = D_MTYPE06;					/* ��å������μ����׵�ʥץ�������		*/
	}
	else
	{
//		lMessageType = D_MTYPE03;					/* �ᥤ��ܥå������ס���Хåե�̵��		*/
		lMessageType = D_MTYPE05;					/* ��å������μ����׵�ʥᥤ��ܥå������� */
	}
	/* msgrcv�ذ����Ϥ���å������ե饰������ */
	if( limit == D_TIMELIMIT_NOWAIT )				/* ���»��֤��֣��פξ��					*/
	{
/*****	�ξ�����ֹ�TBCS0154���б�		Start							��������2003.06.18	*****/
/************************************************************************************************/
/*	��IPC_NOWAIT | MSG_NOERROR�פǻ��ꤹ��褦�˽���											*/
/************************************************************************************************/
//		iMessageFlag = IPC_NOWAIT;
		iMessageFlag = IPC_NOWAIT | MSG_NOERROR;
/*****	�ξ�����ֹ�TBCS0154���б�		 End							��������2003.06.18	*****/
	}
	else											/* ���»��֤��֣��ʳ��פξ��				*/
	{
		iMessageFlag = MSG_NOERROR;
	}

	/************************************/
	/*  ��å������μ��� 				*/
	/************************************/
//	os_trcget2( D_MD_OSRCVMS, D_T_SYS_MALLOC, 1, size + 1 );
	os_trcget2( D_MD_OSRCVMS, D_T_SYS_MALLOC, 1, size + sizeof(TMsgHed) ); //2003.03.26
													/* ���������������						*/
//	pcWorkPtr = malloc(size);						/* �ᥤ��ܥå����������κ����å�����Ĺ	*/
										/* �ᥤ��ܥå����������κ����å�����Ĺ+�إå�������	*/
	pcWorkPtr = malloc(size + sizeof(TMsgHed));
	os_trcget2( D_MD_OSRCVMS, D_T_SYS_END, 1, pcWorkPtr );

	if (NULL == pcWorkPtr)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"osrcvmsp", "malloc() Call Error!!", errno, strerror(errno)));
		os_trcget2( D_MD_OSRCVMS,  D_T_ERR_SYS, 1, OSEEWKEX );
		return(OSEEWKEX);							/* �۾ｪλ��sys work area exhaust��		*/
	}

	ptMsgHed = (TMsgHed *)pcWorkPtr;				/* �ץ����֥�å������ݥ�������			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:size              =%ld \n", "osrcvmsp", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08lx \n", "osrcvmsp", ptMsgHed));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgHed          =%08lx \n", "osrcvmsp", ptMsgHed));
	DbgMsg01(DLv04, (OutPut, "***** %s:pcWorkPtr         =%08lx \n", "osrcvmsp", pcWorkPtr));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMBoxId=%08lx \n", "osrcvms",
			ptEmbcInd->lMBoxId));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lMsgQId=%ld \n", "osrcvms",
			ptEmbcInd->lMsgQId));

	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		/* �����ƥॿ���ޥե饰�ν����				*/

	for( ; ; )
	{
//		lMessageLength = msgrcv( ptEmbcInd->lMsgQId, bufa, size, lMessageType, iMessageFlag );

		DbgDmp02( DLv04, ("### msgrcv�� ptMsgHed sise+sizeof(TMsgHed)",
							 ptMsgHed, size+4+sizeof(TMsgHed),1,0));

//		os_trcget2( D_MD_OSRCVMS, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
//									size+sizeof(TMsgHed), lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMS, D_T_SYS_MSGRCV, 5, ptEmbcInd->lMsgQId, ptMsgHed, 
								size+sizeof(TMsgHed)-sizeof(long), lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size, lMessageType, iMessageFlag );

//		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size+sizeof(TMsgHed),
//					lMessageType, iMessageFlag );
														// 20030329 �ѹ�
														// �����������ϥ�å�����������
														// �����������������ꤹ��
		lRet = msgrcv( ptEmbcInd->lMsgQId, ptMsgHed, size+sizeof(TMsgHed) - sizeof(long),
					lMessageType, iMessageFlag );

		os_trcget2( D_MD_OSRCVMS, D_T_SYS_END, 1, lRet );
		
		DbgDmp02( DLv04, ("### osrcvms msgrcv�� ", ptMsgHed, lRet,1,0));

		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msqid =%08lx\n","osrcvms",ptEmbcInd->lMsgQId));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() *msgp =%08lx\n","osrcvms",(long)ptMsgHed));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgsz =%ld  \n","osrcvms",size));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgtyp=%08lx\n","osrcvms",lMessageType));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() msgflg=%d   \n","osrcvms",iMessageFlag));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() Ret   =%08lx\n","osrcvms",lRet));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() ptMsgHed =%08lx\n","osrcvms",ptMsgHed));
		DbgMsg01(DLv04, (OutPut, "***** %s:msgrcv() pcWorkPtr =%08lx\n","osrcvms",pcWorkPtr));
		
		/************************************************/
		/*	������̤��Խ�								*/
		/************************************************/
//		if( lMessageLength != D_ERR_SYS )			/* �����ƥॳ�����ֵ��ͤγ�ǧ				*/
		if( lRet != D_ERR_SYS )			/* �����ƥॳ�����ֵ��ͤγ�ǧ				*/
		{
													/* ���������»��֤����ꤵ��Ƥ����硢		*/
													/* �����ƥॳ���륿���ޤ�ȯ�Ԥ���			*/
			if( limit >= 1 )
			{
				lRet = os_tmcan( 0 );
				if( lRet != NORMAL )
				{
					os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 0 );	
			        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS1);
                                                	/* ���ܡ��Ƚ���								*/
				}
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:size=%d, ptMsgHed->lDataSize=%d \n",
					"osrcvms", size, ptMsgHed->lDataSize));

													/* ��å�����Ĺ���¤�Ƚ��					*/
			if( size < ptMsgHed->lDataSize )		/* ��å�����Ĺ����ͭ��						*/
			{
				lMessageLength = size;
			}
			else									/* ��å�����Ĺ����̵��						*/
			{
				lMessageLength = ptMsgHed->lDataSize;
			}
													/* ��å����������Хåե��˥��ԡ�			*/
			DbgDmp02( DLv04, ("memcpy�� ", bufa, lMessageLength ,1,0));
			memcpy(bufa, ptMsgHed + 1, lMessageLength);

			DbgDmp02( DLv04, ("memcpy2�� ", bufa, lMessageLength ,1,0));

													/* �ؿ��и�									*/
			DbgMsg01( DLv02, ( OutPut, "***** %s: free pcWorkPtr:%08lx\n", "osrcvms", pcWorkPtr ) );
			DbgMsg01( DLv02, ( OutPut, "***** %s: free ptMsgHed :%08lx\n", "osrcvms", ptMsgHed ) );
			os_trcget2( D_MD_OSRCVMS,  D_T_SYS_FREE, 1, pcWorkPtr );
			free(pcWorkPtr);						/* �������								*/
			os_trcget2( D_MD_OSRCVMS,  D_T_SYS_END, 0 );
			
			DbgMsg01( DLv02, ( OutPut, "***** %s: End  DbgSubFnc\n", "osrcvms" ) );
			os_trcget2( D_MD_OSRCVMS,  D_T_TRA_OUT, 1, lMessageLength );
			return( lMessageLength );				/* �ֵ���(��å�����Ĺ)���ֵѤ���			*/
		}
		else
		{

/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰��Ƚ���������												*/
/************************************************************************************************/
//			if( errno == EINTR && ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF )

													/* errno �� EINTR ����						*/
													/* �����ƥॳ���륿���ޥե饰��				*/
													/* ̤ȯ��(0)������ȯ����(1)�ξ��			*/
			if( ( errno == EINTR ) &&
				( ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_OFF ) ||
				  ( ptEtmc->cSysTimeFlg == D_ETMC_SYSTIMFLG_ON  ) ) )
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/

			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvms",
						"EINTR���顼", errno));
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
						"osrcvms", "��ȥ饤������", ptEtmc->cSysTimeFlg));

				continue;							/* �����ƥॳ���륿���ޥե饰��OFF�ξ��	*/
													/* ���٥�å�����������Ԥ�					*/
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "osrcvms",
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

	os_trcget2( D_MD_OSRCVMS,  D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);								/* �������								*/
	os_trcget2( D_MD_OSRCVMS,  D_T_SYS_END, 0 );


	/********************************************************************************************/
	/*  �۾����                                                                                */
	/********************************************************************************************/
	switch( errno )
	{
		case E2BIG :
		case EINVAL :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "�����۾�!!", "��å�����Ĺ�����ͤ������Ǥ��롣"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEEISIZ );

		case EACCES :
		case EFAULT :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "�����۾�!!", "�������������ʤ���"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEENACC );

		case EIDRM :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "�����۾�!!", "���ꤷ���ᥤ��ܥå�����������줿��"));
	 		os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEEDELD );

		case ENOMSG :
		case EINTR :
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
		 			"osrcvms", "�����۾�!!", "�����ॢ���Ȥ�ȯ��������"));
 			os_trcget2( D_MD_OSRCVMS, D_T_ERR_SYS, 1, errno );
			return( OSEETOUT );

		default :
			os_trcget2( D_MD_OSRCVMS,  D_T_ERR_ABT, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSRCVMS << 16) | D_T_ERR_SYS2);
                                                	/* ���ܡ��Ƚ���								*/
	}
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
