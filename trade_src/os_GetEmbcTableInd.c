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
/* �㥵���ӥ�����̾��				 ���̴ؿ�													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �أأأأأأ�												*/
/* ��⥸�塼��ɣġ�				 os_GetEmbcTableInd											*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)						*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ10��04��                                                                       */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �������򸵤ˡ����פ���ץ��������ơ��֥�������ȥᥤ��ܥå��������ơ��֥������		*/
/*	 ��Ƭ���ɥ쥹�򸡺�����������������������Ƭ���ɥ쥹�����ֵѤ���							*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_GetEmbcTableInd.h>														*/
/*															                                    */
/*	   	long	os_GetEmbcTableInd(long mpid,TMbcTableInd **ppEmbcInd)							*/
/*																								*/
/* �㲾������																					*/
/*		long				mpid;		 	0���ϥᥤ��ܥå������̻����ϥץ����μ��̻�		*/
/*		TMbcTableInd		**ppEmbcInd;	�ᥤ��ܥå����ơ��֥�������Υ��ɥ쥹  			*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			NORMAL																*/
/*		�۾ｪλ			OSEENEXS		�ץ��������ơ��֥�˼��ץ���̤��Ͽ				*/
/*							OSEEIMPI		���̤��ϰϳ�										*/
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


/* ���ѼԺ����إå��ե����� */
#include "os_GetEmbcTableInd_ins.h"


/* ������ */


/* �����ѿ���� */


/* �����ؿ���� */


/* �����ؿ���� */


/* static�ѿ������ */


/************************************************************************************************/
/*                                                                                              */
/* ��ǽ���������򸵤ˡ����פ���ץ��������ơ��֥��������                                   */
/*       �ᥤ��ܥå��������ơ��֥��������Ƭ���ɥ쥹�򸡺�����                                 */
/*       ������������������Ƭ���ɥ쥹�����ֵѤ���                                             */
/*                                                                                              */
/* ��������2002ǯ10��04��                                                                       */
/*                                                                                              */
/* �ѹ���������ǯ�����                                                                       */
/*                                                                                              */
/* �����ԡ�                                                                                     */
/*                                                                                              */
/* �ƽз�����                                                                                   */
/*   long os_GetEmbcTableInd( long          mpid,                                               */
/*                            TEmbcTableInd **pptEmbcInd )                                      */
/*                                                                                              */
/*                                                                                              */
/*   long mpid                  0���ϥᥤ��ܥå������̻����ϥץ����μ��̻�                   */
/*   TEmbcTableInd **pptEmbcInd �ᥤ��ܥå����ơ��֥�������Υ��ɥ쥹                          */
/*                                                                                              */
/************************************************************************************************/

long os_GetEmbcTableInd( long mpid, TEmbcTableInd **pptEmbcInd )
{
	long	lLoopCnt;								/* �롼�ץ�����							*/
	long	lAsso;									/* ����										*/
	long	lSequenceNumber;						/* ����										*/
	TEprcTableInd	*ptEprcInd;						/* �ץ��������ơ��֥�������Υ��ɥ쥹		*/
	TEmbcTableInd	*ptEmbcInd;


													/* �ؿ�����									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_GetEmbcTableInd" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	ptEprcInd   = (TEprcTableInd *)(ptEprc + 1 );	/* �ץ�����������������Ƭ���ɥ쥹����		*/
	*pptEmbcInd = (TEmbcTableInd *)(ptEmbc + 1 );	/* �ᥤ��ܥå���������������Ƭ���ɥ쥹���� */

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd =%08lx \n", "os_GetEmbcTableInd",
			(long)ptEprcInd));
	DbgMsg01(DLv04, (OutPut, "***** %s:pptEmbcInd=%08lx \n", "os_GetEmbcTableInd",
			*pptEmbcInd));

													/* �ᥤ��ܥå������̻�����					*/
													/* �ץ������̻Ҥ��������Υ����å�			*/
	if( mpid == D_MPID_MYPROCESS )					/* ����mpid�˼��̻Ҥ����ꤵ��Ƥ��ʤ����	*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%d \n", "os_GetEmbcTableInd", mpid));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
				ptEprc->lIndPartNum));

													/* ���פ���ץ��������ơ��֥�������θ��� */
		for( lLoopCnt = 1; lLoopCnt <= ptEprc->lIndPartNum ; lLoopCnt++ )
		{
//			DbgMsg01(DLv04, (OutPut, "***** %s:Roop1[%ld] \n", "os_GetEmbcTableInd", lLoopCnt));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd=%08lx \n", "os_GetEmbcTableInd",
//					(long)ptEprcInd));
//			DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid=%08lx, ptEprcInd->lPid=%08lx \n",
//					"os_GetEmbcTableInd", lMyPid, ptEprcInd->lPid));

			if( lMyPid == ptEprcInd->lPid )			/* lMyPid��global�ѿ�						*/
			{
				break;								/* �롼�פ�ȴ����							*/
			}

//			*ptEprcInd++;							/* ���θ������Υ��ɥ쥹�����ꤹ�� */
			ptEprcInd++;							/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
		}

		DbgMsg01(DLv04, (OutPut, "\n***** %s:----- Check 1 ----- \n", "os_GetEmbcTableInd"));

		if( lLoopCnt > ptEprc->lIndPartNum )
		{
													/* �ץ��������ơ��֥��					*/
													/* ���ץ���ID����Ͽ���줿��������̵��		*/
			return( OSEENEXS );
		}

		DbgMsg01(DLv04, (OutPut, "***** %s:Roop1[%ld] \n", "os_GetEmbcTableInd", lLoopCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid=%08lx, ptEprcInd->lPid=%08lx \n",
				"os_GetEmbcTableInd", lMyPid, ptEprcInd->lPid));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
				ptEmbc->lIndPartNum));

													/* �ᥤ��ܥå��������ơ��֥�������θ��� 	*/
//		for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
		{
//			DbgMsg01(DLv04, (OutPut, "***** %s:Roop2[%ld] \n", "os_GetEmbcTableInd",
//					lLoopCnt));

			ptEmbcInd = *pptEmbcInd;

//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//					(long)ptEmbcInd));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
//					ptEprcInd->lPCode));
//			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
//					ptEmbcInd->lPCode));

													/* �ץ��������ơ��֥�Υץ������̻Ҥ�	*/
													/* �᡼��ܥå��������ơ��֥��				*/
													/* �ץ������̻Ҥ����פ�����				*/
//			if( ptEprcInd->lPid == ptEmbcInd->lPCode )
			if( ptEprcInd->lPCode == ptEmbcInd->lPCode )
			{
				break;
			}

//			*pptEmbcInd++;							/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
			(*pptEmbcInd)++;						/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
		}

		if( lLoopCnt > ptEmbc->lIndPartNum )
		{
													/* ����Υץ������̻Ҥ���Ͽ���줿			*/
													/* ��������¸�ߤ��ʤ�						*/
			return( OSEENEXS );
		}

		DbgMsg01(DLv04, (OutPut, "***** %s:Roop2[%ld] \n", "os_GetEmbcTableInd",
				lLoopCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
				(long)ptEmbcInd));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEprcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
				ptEprcInd->lPCode));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd->lPCode=%08lx \n", "os_GetEmbcTableInd",
				ptEmbcInd->lPCode));
	}
	else
	{
		DbgMsg01(DLv04, (OutPut, "\n***** %s:----- Check 2 ----- \n", "os_GetEmbcTableInd"));

		lAsso = os_GetAsso( mpid );					/* �裱����������̤��������				*/
		DbgMsg01(DLv04, (OutPut, "***** %s:lAsso=%ld \n", "os_GetEmbcTableInd", lAsso));

		lSequenceNumber = os_GetSerNum( mpid );		/* �裱�����������֤��������				*/
		DbgMsg01(DLv04, (OutPut, "***** %s:lSequenceNumber=%ld \n", "os_GetEmbcTableInd",
				lSequenceNumber));

		if( lAsso == D_ASSO_PROCESS )				/* ���̤�1(�ץ������̻�)�ξ��			*/
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
					ptEmbc->lIndPartNum));
													/* �ᥤ��ܥå��������ơ��֥�������θ���	*/
//			for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
			for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
			{
//				DbgMsg01(DLv04, (OutPut, "***** %s:Roop3[%ld] \n", "os_GetEmbcTableInd",
//						lLoopCnt));

				ptEmbcInd = *pptEmbcInd;

//				DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//						(long)ptEmbcInd));
//				DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lPCode=%08lx \n",
//						"os_GetEmbcTableInd", mpid, ptEmbcInd->lPCode));

				if( mpid == ptEmbcInd->lPCode )
				{
					break;
				}

//				*pptEmbcInd++;						/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
				(*pptEmbcInd)++;					/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
			}

			if( lLoopCnt > ptEmbc->lIndPartNum )
			{
													/* ����Υץ������̻Ҥ���Ͽ���줿			*/
													/* ��������¸�ߤ��ʤ�						*/
				return( OSEENEXS );
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:Roop3[%ld] \n", "os_GetEmbcTableInd",
					lLoopCnt));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
					(long)ptEmbcInd));
			DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lPCode=%08lx \n",
					"os_GetEmbcTableInd", mpid, ptEmbcInd->lPCode));
		}
		else if( lAsso == D_ASSO_MAILBOX )			/* ���̤�2(�ᥤ��ܥå������̻�)�ξ��		*/
		{
													/* ���֤��ϰϥ����å�						*/
			if( lSequenceNumber < D_SEQNUM_MIN || lSequenceNumber > ptEmbc->lIndPartNum )
			{
				return( OSEEIMPI );					/* ���̤��ϰϳ����ͤ����ꤵ��Ƥ���			*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lIndPartNum=%d \n", "os_GetEmbcTableInd",
					ptEmbc->lIndPartNum));
													/* �ᥤ��ܥå��������ơ��֥�������θ���	*/
//			for( lLoopCnt = 1; lLoopCnt < ptEmbc->lIndPartNum; lLoopCnt++ )
			for( lLoopCnt = 1; lLoopCnt <= ptEmbc->lIndPartNum; lLoopCnt++ )
			{
//				DbgMsg01(DLv04, (OutPut, "***** %s:Roop4[%ld] \n", "os_GetEmbcTableInd",
//						lLoopCnt));

				ptEmbcInd = *pptEmbcInd;

//				DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
//						(long)ptEmbcInd));
//				DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lMBoxId=%08lx \n",
//						"os_GetEmbcTableInd", mpid, ptEmbcInd->lMBoxId));

				if( mpid == ptEmbcInd->lMBoxId )
				{
					break;

				}

//				*pptEmbcInd++;						/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
				(*pptEmbcInd)++;					/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
			}

			if( lLoopCnt > ptEmbc->lIndPartNum )
			{
													/* ����Υᥤ��ܥå������̻Ҥ�				*/
													/* ��Ͽ���줿��������¸�ߤ��ʤ�				*/
				return( OSEENEXS );
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:Roop4[%ld] \n", "os_GetEmbcTableInd",
					lLoopCnt));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcInd =%08lx \n", "os_GetEmbcTableInd",
					(long)ptEmbcInd));
			DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx, ptEmbcInd->lMBoxId=%08lx \n",
					"os_GetEmbcTableInd", mpid, ptEmbcInd->lMBoxId));
		}
		else
		{
			return( OSEEIMPI );						/* ���̤��ϰϳ����ͤ����ꤵ��Ƥ���			*/
		}
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_GetEmbcTableInd" ) );
	return( NORMAL );
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
