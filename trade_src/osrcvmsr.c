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
/* ��⥸�塼��̾��					 ��å������μ����׵�										*/
/* ��⥸�塼��ɣġ�				 osrcvmsr													*/
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
/* ��������2002ǯ10��04��                                                    */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ��å������μ������׵� 																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osrcvmsr.h>																*/
/*																								*/
/*	   	long	osrcvmsr( long mpid, long rd, long size, char *bufa ) 							*/
/*																								*/
/* �㲾������																					*/
/*		long	mpid;		�ᥤ��ܥå������ϥץ������̻�									*/
/*		long	rd;			�ꥯ�����ȼ��̻�(1�ʾ�)												*/
/*		long	size;		��å�����Ĺ������(1��8192)											*/
/*		char	*bufa;		��å����������Хåե�												*/
/*																								*/
/* ���ֵ��͡�																					*/
/*	   	���ｪλ		�ꥯ�����ȼ��̻�														*/
/*		�۾ｪλ		os_GetEmbcTableInd���ֵ���												*/
/*						OSEEISIZ					���������ϰϳ�								*/
/*						OSEEOVRQ					rd�����ơ��֥��̤ͽ�󤫤�̤���Ѥ�			*/
/*													��������¸�ߤ��ʤ�							*/
/*						OSEEIVRD					������������ͽ����֤�ͽ��ѤǤʤ�			*/
/*						OSEEUSED					��������������λ�׵���֤��׵�ѤߤǤʤ�	*/
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* ���ѼԺ����إå��ե����� */

/* ������ */

/* �����ѿ���� */
#include "osrcvmsr.h"
#include "osrcvmsr_ins.h"

/* �����ؿ���� */

/* �����ؿ���� */

/* static�ѿ������ */

/*****************************************************************************/
/* ��ǽ����å������μ������׵�                                              */
/* ��������2002ǯ10��04��                                                    */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�                                                                  */
/* �ƽз�����                                                                */
/*   long osrcvmsr( long mpid, long rd, long size, char *bufa )              */
/*       long mpid        �ᥤ��ܥå������ϥץ������̻�                   */
/*       long rd          �ꥯ�����ȼ��̻�(1�ʾ�)                            */
/*       long size        ��å�����Ĺ������(1��8192)                        */
/*       char *bufa       ��å����������Хåե�                             */
/*****************************************************************************/
long osrcvmsr( long mpid, long rd, long size, char *bufa )
{
	long	lLoopCnt;								/* �롼�ץ�����							*/
	long	lAsso;									/* ����										*/
	long	lRet;									/* �ؿ�����ֵ�								*/
	long	*plWorkPtr = NULL;						/* ����ݥ��󥿡�							*/
	TEmbcTableInd	*ptEmbcInd = NULL;				/* �ᥤ��ܥå�������������Υ��ɥ쥹		*/
	TErdcTableInd	*ptErdcInd = NULL;				/* rd��������������Υ��ɥ쥹				*/

	
	os_trcget2( D_MD_OSRCVMSR, D_T_TRA_IN, 4, mpid, rd, size, bufa );
	
													/* �ؿ�����									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osrcvmsr" ) );

/************************************************************************************************/
/*  �������																					*/
/************************************************************************************************/
	lLoopCnt = 0;
	lAsso    = 0;
	lRet     = 0;
	errno    = 0;


	DbgMsg01(DLv04, (OutPut, "***** %s:mpid=%08lx \n", "osrcvmsr", mpid));
	DbgMsg01(DLv04, (OutPut, "***** %s:rd  =%ld \n", "osrcvmsr", rd));
	DbgMsg01(DLv04, (OutPut, "***** %s:size=%ld \n", "osrcvmsr", size));
	DbgMsg01(DLv04, (OutPut, "***** %s:bufa=%08lx \n\n", "osrcvmsr", (long)bufa));


													/* rd���������������Ƭ���ɥ쥹��������	*/
//	ptErdcInd = (TErdcTableInd *)ptErdc + sizeof( TErdcTable );
	ptErdcInd = (TErdcTableInd *)(ptErdc + 1);

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd=%08lx \n", "osrcvmsr", (long)ptErdcInd));


	/****************************************/
	/* ���̻�(����mpid)�Υ����å�			*/
	/****************************************/
	lRet = os_GetEmbcTableInd( mpid, &ptEmbcInd );
	if( lRet != NORMAL )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  lRet=%08lx \n", "osrcvmsr",
				"�����۾�!!", "���ꤷ���ᥤ��ܥå�����¸�ߤ��ʤ������Ϻ�����줿��", lRet));

		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, lRet );	

		return( lRet );
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetEmbcTableInd lRet=%08lx \n", "osrcvmsr", lRet));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%ld \n","osrcvmsr", ptEmbc->lMaxMsgLng));

	/****************************************/
	/* ��å���������Ĺ(����size)�Υ����å� */
	/****************************************/
	if( size < D_MSGSIZE_MIN || size > ptEmbc->lMaxMsgLng )
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  size=%ld \n", "osrcvmsr",
				"�����۾�!!", "��å�����Ĺ�����ͤ������Ǥ��롣", size));
				
		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEISIZ );			

		return( OSEEISIZ );							/* ���������ϰϳ����ͤ����ꤵ��Ƥ��� */
	}

	/****************************************/
	/* �ꥯ�����ȼ��̻ҥ����å�				*/
	/****************************************/
	if( rd == 0 )									/* �ꥯ�����ȼ��̻�(����:rd)����0�פξ��	*/
	{
													/* rd�����ơ��֥����������Ƭ����			*/
													/* �ꥯ�����Ⱦ��֤���̤ͽ��פ��ġ�̤���ѡ�	*/
													/* ���ġ�̤�׵�פθ������򸡺�����			*/
//2003.02.19		for( lLoopCnt = 1; lLoopCnt <= ptErdc->lMaxIndNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptMyEPRC->lMaxReqNum; lLoopCnt++ )
		{
//			if( ptErdcInd->tReqStat.cResStat == D_ERDC_RESSTAT_NONE &&
//				ptErdcInd->tReqStat.cUseStat == D_ERDC_USESTAT_NONE )
													/* �ꥯ�����Ⱦ��֤�							*/
													/* ̤ͽ�󤫤�̤���Ѥ���̤�׵�ξ��			*/
			if( D_ERDC_RESSTAT_NONE == ptErdcInd->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptErdcInd->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptErdcInd->tReqStat.cUCompStat )
			{
				break;
			}
			ptErdcInd++;							/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
		}
//2003.02.19		if( lLoopCnt > ptErdc->lMaxIndNum )
		if( lLoopCnt > ptMyEPRC->lMaxReqNum )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"�����۾�!!", "��λ�����׵�ο���¿�����롣"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEOVRQ );		

			return( OSEEOVRQ );						/* ���������������¸�ߤ��ʤ�				*/
		}
	}
	else
	{
													/* �����Υꥯ�����ȼ��̻Ҥ�Ʊ��				*/
													/* �ꥯ�����ȼ��̻Ҥ���ĸ��̤򸡺�����		*/
//2003.02.19		for( lLoopCnt = 1; lLoopCnt <= ptErdc->lMaxIndNum; lLoopCnt++ )
		for( lLoopCnt = 1; lLoopCnt <= ptMyEPRC->lMaxReqNum; lLoopCnt++ )
		{
			if( rd == ptErdcInd->lRCode )
			{
				break;
			}
			ptErdcInd++;							/* ���θ������Υ��ɥ쥹�����ꤹ��			*/
		}

//2003.02.19		if( lLoopCnt > ptErdc->lMaxIndNum )			/* rd�����ơ��֥��rd��Ʊ���ꥯ�����ȼ��̻� */
		if( lLoopCnt > ptMyEPRC->lMaxReqNum )			/* rd�����ơ��֥��rd��Ʊ���ꥯ�����ȼ��̻� */
		{											/* ����ä���������¸�ߤ��ʤ�				*/
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"�����۾�!!", "��λ�����׵�ο���¿�����롣"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEOVRQ );		

			return( OSEEOVRQ );
		}
		if( ptErdcInd->tReqStat.cResStat != D_ERDC_RESSTAT_RES )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"�����۾�!!", "�������ͽ�󤵤�Ƥ��ʤ��������������ͤǤ��롣"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEIVRD );		

			return( OSEEIVRD );						/* ������������ͽ����֤�ͽ��ѤǤʤ�		*/
		}
		if( ptErdcInd->tReqStat.cUCompStat != D_ERDC_UCOMPSTAT_NONE )
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrcvmsr",
					"�����۾�!!", "���������λ�׵�ѤǤ��롣�����������ͤǤ��롣"));
					
			os_trcget2( D_MD_OSRCVMSR, D_T_ERR_PRA, 1, OSEEUSED );		

			return( OSEEUSED );						/* ��������������λ�׵���֤�̤�׵�Ǥʤ� */
		}
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lLoopCnt =%ld \n", "osrcvmsr", lLoopCnt));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd=%08lx \n", "osrcvmsr", (long)ptErdcInd));


/************************************************************************************************/
/*  �ܽ���																						*/
/************************************************************************************************/
	/********************************************/
	/*  rd�����ơ��֥��������					*/
	/*  �ץ����֥�å������׵�ե饰���Խ�	*/
	/********************************************/
	lAsso = os_GetAsso( mpid );						/* ���̤μ���								*/
	DbgMsg01(DLv04, (OutPut, "***** %s:os_GetAsso()  lAsso=%ld \n", "osrcvmsr", lAsso));

													/* ���̤���1�פξ�硢����					*/
													/* ���ѥ�᡼������0�פξ��				*/
//	if( lAsso == D_ASSO_PROCESS )
	if((D_ASSO_PROCESS == lAsso) || (0 == mpid))
	{												/* �ץ������ס���Хåե�̵��				*/
													/* ��å����������׵�						*/
		ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_ON;

		DbgMsg01(DLv04, (OutPut, "\n***** %s:%s\n", "osrcvmsr",
				"��å������μ����׵�ʥץ�������"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOff=%02x \n", "osrcvmsr",
				ptErdc->tMsgFlg.cPrcPbOff));
	}
	else
	{												/* �ᥤ��ܥå������ס���Хåե�̵��		*/
													/* ��å����������׵�						*/
		ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_ON;

		DbgMsg01(DLv04, (OutPut, "***** %s:%s\n", "osrcvmsr",
				"��å������μ����׵�ʥᥤ��ܥå�������"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOff=%02x \n", "osrcvmsr",
				ptErdc->tMsgFlg.cMbPbOff));
	}

	/********************************************/
	/*  rd�����ơ��֥�������Խ�				*/
	/********************************************/
													/* �ꥯ�����Ⱦ��֡���λ�׵���֡�			*/
													/* ���׵�Ѥ�����							*/
	ptErdcInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;

	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->tReqStat.cUCompStat=%02x \n", "osrcvmsr",
			ptErdcInd->tReqStat.cUCompStat));

													/* ���̤���1�פξ�硢����					*/
													/* ���ѥ�᡼������0�פξ��				*/
//	if( lAsso == D_ASSO_PROCESS )
	if(( D_ASSO_PROCESS == lAsso ) || ( 0 == mpid ))
	{												/* ���̤�1(�ץ������̻�)�ξ��			*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_PRC_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS06;	/* ��å������μ����׵�ʥץ�������		*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmsr",
				ptErdcInd->cReqClass));
	}
	else
	{												/* ���̤�2(�ᥤ��ܥå������̻�)�ξ��		*/
//		ptErdcInd->cReqClass = D_ERDC_REQCLASS_MB_PB;
		ptErdcInd->cReqClass = D_ERDC_REQCLASS05;	/* ��å������μ����׵�ʥᥤ��ܥå������� */

		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->cReqClass=%02x \n", "osrcvmsr",
				ptErdcInd->cReqClass));
	}
	
	os_trcget2( D_MD_OSRCVMSR,  D_T_SYS_MALLOC, 1, 4 );

	plWorkPtr = malloc(4);							/* ���������4�Х��ȡ�					*/
	
	os_trcget2( D_MD_OSRCVMSR,  D_T_SYS_END, 1, plWorkPtr );
	
	if (NULL == plWorkPtr)							/* ���������ݥ��󥿤�NULL�ξ��				*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
				"osrcvmsr", "malloc() Call Error!!", errno, strerror(errno)));
		
		os_trcget2( D_MD_OSRCVMSR, D_T_ERR_SYS, 1, OSEEWKEX );		
				
		return(OSEEWKEX);							/* �۾ｪλ��sys work area exhaust��		*/
	} 

	ptErdcInd->lReqNum = 0;
//	ptErdcInd->pvArg1 = &size;
	*plWorkPtr = size;
	ptErdcInd->pvArg1 = plWorkPtr;
	ptErdcInd->pvArg2 = bufa;

//	DbgMsg01(DLv04, (OutPut, "***** %s:size=%08lx, size=%ld \n", "osrcvmsr",
//			&size, size));
//	DbgMsg01(DLv04, (OutPut, "***** %s:plWorkPtr=%08lx, plWorkPtr=%ld \n", "osrcvmsr",
//			plWorkPtr, *plWorkPtr));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->pvArg1=%ld \n", "osrcvmsr",
			*(long *)ptErdcInd->pvArg1));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcInd->pvArg2=%08lx \n", "osrcvmsr",
			ptErdcInd->pvArg2));


/************************************************************************************************/
/*  ��λ����																					*/
/************************************************************************************************/
													/* �ؿ��и�									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrcvmsr" ) );
	
	os_trcget2( D_MD_OSRCVMSR, D_T_TRA_OUT, 1, ptErdcInd->lRCode );
	
	return( ptErdcInd->lRCode );
}
/************************************************************************************************/
/*  End																							*/
/************************************************************************************************/
