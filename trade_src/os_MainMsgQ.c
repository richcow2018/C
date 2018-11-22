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
/* �㥵���ӥ�����̾��				 �ꥶ��ȴ���												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ᥤ���å���������										*/
/* ��⥸�塼��ɣġ�				 os_MainMsgQ												*/
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
/* �㥽���������ԡ�					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�����ѹ�	�ʣӣӣ̣�����������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���꡿������ꥶ��ȤΥᥤ���å��������塼����											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_MainMsgQ.h>														        */
/*																								*/
/*	   	long		os_MainMsgQ(long lLimit,long lMsgType,TErdcTableInd *ptErdcp,long lMsgFlg)	*/
/*																								*/
/* �㲾������																					*/
/*      long            lLimit                                                                  */
/*      long            lMsgType                                                                */
/*      TErdcTableInd   *ptErdcp                                                                */
/*      long            *rda                                                                    */
/*      long            lMsgFlg     ��0������ꥶ��� 1��������ꥶ��ȡ�                       */
/*																								*/
/* ���ֵ��͡�																					*/
/*      NORMAL      �����ｪλ                                                                  */
/*      -1          ��sys work area exhaust                                                     */
/*      -2          ��invalid size                                                              */
/*      -3          ��no access right                                                           */
/*      -4          ��deleted                                                                   */
/*      -5          ��time out                                                                  */
/*      -6          ��invalid buffer pool                                                       */
/*      -7          ��not pool buffer                                                           */
/*      -8          ��invalid pool buffer                                                       */
/*      -9          ��invalid req descriptor                                                    */
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

/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	"os_MainMsgQ_ins.h"


long	os_MainMsgQ(lLimit, lMsgType, ptErdcp, rda, lMsgFlg)
long			lLimit;								/* ���»���									*/
long			lMsgType;							/* ��å�����������							*/
TErdcTableInd	*ptErdcp;							/* �����������������ݥ���				*/
long			*rda;								/* �ꥯ�����ȼ��̻ҳ�Ǽ��					*/
long			lMsgFlg;							/* ��å������ե饰							*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lMsgqID;						/* ��å��������塼�ɣ�						*/
	long			lMsgSize;						/* ��å���������������						*/
	long			lRcvRet;						/* ��̤ؤ��ֵ�����							*/
	long			lRet;							/* �ֵ���									*/
	long			lCnt1;							/* �롼�ץ������1							*/
	long			lCnt2;							/* �롼�ץ������2							*/
	char			*pcWorkPtr = NULL;				/* ����ݥ���							*/
	TMsgHed			*ptMsg;							/* ��å������ݥ���						*/
	TNonEndMsg		*ptNonMsg = NULL;				/* ��λ��å������ݥ���					*/
	TEmbcTableInd	*ptMyEmbcp = NULL;				/* ���ץ����ᥤ��ܥå�����������ݥ��� */
	TErdcTableInd	*ptWorkErdcp = NULL;			/* �������������Υ���ݥ���			*/

	os_trcget2( D_MD_OS_MAINMSGQ, D_T_TRA_IN, 5, lLimit, lMsgType, ptErdcp, rda, lMsgFlg);
													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MainMsgQ" ) );

	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lMsgqID  = 0;									/* ��å��������塼�ɣ�						*/
	lMsgSize = 0;									/* ��å���������������						*/
	lRcvRet  = 0;									/* ��̤ؤ��ֵ�����							*/
	lRet  = 0;										/* �ֵ���									*/
	lCnt1 = 0;										/* �롼�ץ������1							*/
	lCnt2 = 0;										/* �롼�ץ������2							*/
	errno = 0;										/* errno ���ꥢ								*/


	DbgMsg01(DLv04, (OutPut, "***** %s:lLimit   = %ld   \n", "os_MainMsgQ", lLimit));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType = %08lx \n", "os_MainMsgQ", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp  = %08lx \n", "os_MainMsgQ", (long)ptErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:rda      = %08lx \n", "os_MainMsgQ", (long)rda));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgFlg  = %ld   \n\n", "os_MainMsgQ", lMsgFlg));


	ptWorkErdcp = ptErdcp;							/* rd�����ơ��֥�������Υ���ݥ�������	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptWorkErdcp=%08x \n", "os_MainMsgQ", ptWorkErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc=%08x \n", "os_MainMsgQ", ptEmbc));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lMaxMsgLng=%08x \n", "os_MainMsgQ",
			ptEmbc->lMaxMsgLng));


	/****************************************/
	/*  �������							*/
	/****************************************/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_MALLOC, 1, ptEmbc->lMaxMsgLng );
													/* ���������������						*/
	pcWorkPtr = malloc(ptEmbc->lMaxMsgLng);			/* �ᥤ��ܥå����������κ����å�����Ĺ	*/
	
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 2, pcWorkPtr, errno );

	if (NULL == pcWorkPtr)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
			"os_MainMsgQ", "shmdt() Call Error!!", errno, strerror(errno)));
		return(-1);									/* �۾ｪλ��sys work area exhaust��		*/
	}

	ptMsg = (TMsgHed *)pcWorkPtr;					/* �ץ����֥�å������ݥ�������			*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg=%08x \n", "os_MainMsgQ", ptMsg));


	/****************************************/
	/*  ��å��������塼�ɣĤ�����			*/
	/****************************************/
													/* ���ץ����ᥤ��ܥå�������ݥ������� */
	ptMyEmbcp = (TEmbcTableInd *)ptEsys->tMyPrcInfo.ptMyEMBC;
	lMsgqID = ptMyEmbcp->lMsgQId;					/* ���ץ����Υ�å��������塼�ɣ�����		*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp=%08lx, lMsgqID=%ld \n", "os_MainMsgQ",
			(long)ptMyEmbcp, lMsgqID));


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ�ȯ�Խ����ΰ�ư�ˤ���ɲ�												*/
/*	��os_MsgRcv �� os_MainMsgQ��																*/
/************************************************************************************************/
	if (0 < lLimit)									/* ���»��֤����ʾ�ξ��					*/
	{
		ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;	/* �����ƥॳ���륿���ޥե饰�Υ��ꥢ		*/

		os_systim(lLimit, 1, 100);					/* ������ȯ�ԡ�100m��ñ�̡�					*/
	}
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/

	while(1)										/* �롼�׽���								*/
	{
		/****************************************/
		/*  ���ꥢ								*/
		/****************************************/
		if (1 == lMsgFlg)							/* ������ꥶ��Ƚ����ξ��					*/
		{
			lMsgType = 0;							/* ��å����������� ���ꥢ					*/
		}
		lMsgSize = 0;								/* ��å���������������						*/
		lRet = 0;									/* �ֵ���									*/
		lCnt1 = 0;									/* �롼�ץ������1							*/
		lCnt2 = 0;									/* �롼�ץ������2							*/
		errno = 0;									/* errno ���ꥢ								*/
		ptErdcp = ptWorkErdcp;						/* rd�����ơ��֥�������Υݥ��󥿰��ֽ���� */

		memset(ptMsg, 0, ptEmbc->lMaxMsgLng);		/* ��å��������ꥢ							*/


		/****************************************/
		/*  ��å���������						*/
		/****************************************/
													/* ��å�������������						*/
//		lRet = os_MsgRcv(lMsgqID, ptMsg, ptEmbc->lMaxMsgLng, lMsgType, lLimit);
//		lMsgSize = lRet;							/* ��å���������������������				*/
																// 20030330 ����
		lRet = os_MsgRcv(lMsgqID, ptMsg, ptEmbc->lMaxMsgLng - sizeof(long), lMsgType, lLimit);
		lMsgSize = lRet + sizeof(long);				/* ��å���������������������				*/

		DbgMsg01(DLv04, (OutPut, "***** %s:os_MsgRcv  lRet=%08x \n", "os_MainMsgQ", lRet));

		if (-1 == lRet)								/* �ֵ��ͤ����顼�ξ��						*/
		{
			if (EINTR == errno)						/* �֣ţɣΣԣҥ��顼�פξ��				*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "os_MainMsgQ",
																 "EINTR���顼", errno));

/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰��Ƚ���������												*/
/************************************************************************************************/
//				if (0x00 == ptEtmc->cSysTimeFlg)	/* �����ƥॳ���륿���ޥե饰�Υ��ꥢ		*/

													/* �����ƥॳ���륿���ޥե饰����̤ȯ�ԡ�	*/
													/* ���ϡ�ȯ����פξ��						*/
				if ((0x00 == ptEtmc->cSysTimeFlg) || (0x01 == ptEtmc->cSysTimeFlg))
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/
				{
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
							 "os_MainMsgQ", "��ȥ饤������", ptEtmc->cSysTimeFlg));

					continue;						/* ��ȥ饤������							*/
				}
				else								/* �����ƥॳ���륿���ޥե饰��				*/
				{									/* �֥����ॢ���ȡפξ��					*/
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  ptEtmc->cSysTimeFlg=%02x \n",
							 "os_MainMsgQ", "TIMEOUT ERR", ptEtmc->cSysTimeFlg));

					os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
					free(pcWorkPtr);				/* �������								*/
					os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰�Υ��ꥢ���ɲ�													*/
/************************************************************************************************/
													/* �����ƥॿ���ޥե饰�ν����				*/
					ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/

					return(-5);						/* OSEETOUT									*/
				}
			}
			else if (EINTR != errno)				/* ���顼�����򤹤�							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  errno=%08x \n", "os_MainMsgQ",
														 "EINTR�ʳ��Υ��顼", errno));

				if (0 < lLimit)						/* ���»��֤����ʾ�ξ��					*/
				{
					os_tmcan(0);					/* �����ޥ���󥻥�							*/
				}

				/****************************************/
				/*  errno ��Ƚ��						*/
				/****************************************/
				switch (errno)
				{
					case	E2BIG:					/* OSEEISIZ									*/
					case	EINVAL:					/* OSEEISIZ									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* �������								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-2);
						break;

					case	EACCES:					/* OSEENACC									*/
					case	EFAULT:					/* OSEENACC									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* �������								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-3);
						break;

					case	EIDRM:					/* OSEEDELD									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* �������								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-4);
						break;

					case	ENOMSG:					/* OSEETOUT									*/

						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
						free(pcWorkPtr);			/* �������								*/
						os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

						return(-5);
						break;

					default		:					/* ���⤷�ʤ�								*/
						break;
				}
			}
		}

		if (1 == lMsgFlg)							/* ������ꥶ��Ƚ����ξ��					*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "os_MainMsgQ", "������ꥶ��Ƚ���"));

			/************************************/
			/*  ��å��������ƥ����å�			*/
			/************************************/
													/* �ģãӥ�å������Υ����å�				*/
			if ((D_MTYPEDCS_MIN <= ptMsg->lMsgType) && (D_MTYPEDCS_MAX >= ptMsg->lMsgType))
			{
				lMsgType = D_MTYPE25;				/* ��å����������פˣģãӥ�å����������� */
			}
			else
			{
				lMsgType = ptMsg->lMsgType;			/* ����������å����������פ�����			*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lMsgType = %08x, lMsgType = %02x \n",
					"os_MainMsgQ", ptMsg->lMsgType, lMsgType));


			switch (lMsgType)						/* ��å����������פǿ���ʬ��				*/
			{
				case	D_MTYPE05:					/* ��å������μ����׵�ʥᥤ��ܥå������� */
				case	D_MTYPE06:					/* ��å������μ����׵�ʥץ�������		*/
				case	D_MTYPE07:					/* �ᥤ��ܥå������ס���Хåե�ͭ��		*/
				case	D_MTYPE08:					/* �ץ������ס���Хåե�ͭ��				*/
				case	D_MTYPE25:					/* �ģãӥ�å������μ����׵�				*/

					/************************************************************************/
					/*  ������å����������פ�rd�����ơ��֥���׵���̤ΰ��פ���			*/
					/*  �����θ������򸡺�����												*/
					/************************************************************************/
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOff  = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cMbPbOff));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOff = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cPrcPbOff));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cMbPbOn   = %02x \n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cMbPbOn));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdc->tMsgFlg.cPrcPbOn  = %02x \n\n",
							"os_MainMsgQ", ptErdc->tMsgFlg.cPrcPbOn));

					/***** �����ѹ���SSLA0001��	Start					��������2002.12.12	*****/
					/****************************************************************************/
					/*  osrcvmsr�Ǥ���ס���Хåե���å������������б�						*/
					/****************************************************************************/
													/* ��å����������פ�rd�����ơ��֥�������� */
													/* ��å������׵�ե饰�����Ƥ����פ����� */
//					if (((D_MTYPE05 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
//					|| ((D_MTYPE06 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
//					|| ((D_MTYPE07 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
//					|| ((D_MTYPE08 == lMsgType) && (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn)))

													/* ��å������μ����׵�ʥᥤ��ܥå�������	*/
													/* ���ĥᥤ��ܥå������ס���Хåե�̵��ON */
													/* ����										*/
													/* ��å������μ����׵�ʥץ�������		*/
													/* ���ĥץ������ס���Хåե�̵��ON		*/
													/* ����										*/
													/* �ס���Хåե���Υ�å�������			*/
													/* 			�����׵�ʥᥤ��ܥå�������	*/
													/* ���ĥᥤ��ܥå������ס���Хåե�ͭ��ON */
													/* ����										*/
													/* �ס���Хåե���Υ�å�������			*/
													/* 			�����׵�ʥᥤ��ܥå�������	*/
													/* ���ĥᥤ��ܥå������ס���Хåե�̵��ON */
													/* ����										*/
													/* �ס���Хåե���Υ�å�������			*/
													/* 			�����׵�ʥץ�������			*/
													/* ���ĥץ������ס���Хåե�ͭ��ON		*/
													/* ����										*/
													/* �ס���Хåե���Υ�å�������			*/
													/* 			�����׵�ʥץ�������			*/
													/* ���ĥץ������ס���Хåե�̵��ON		*/
													/* ����										*/
													/* �ģãӥ�å������μ����׵�				*/
													/* ���ĥᥤ��ܥå������ס���Хåե�ͭ��ON */
					if (((D_MTYPE05 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
					 || ((D_MTYPE06 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
					 || ((D_MTYPE07 == lMsgType) &&
						 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
					 || ((D_MTYPE07 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
					 || ((D_MTYPE08 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn))
					 || ((D_MTYPE08 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
					 || ((D_MTYPE25 == lMsgType) &&
					 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn)))
					/***** �����ѹ���SSLA0001��	 End					��������2002.12.12	*****/
					{
						DbgMsg01(DLv04,(OutPut,"***** %s:%s \n","os_MainMsgQ", "�оݥǡ�������"));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp=%08x \n","os_MainMsgQ", ptErdcp));

						/************************************/
						/*  �������ơ��֥����������		*/
						/************************************/
						//for(lCnt1 = 0; lCnt1 < ptErdc->lMaxIndNum; lCnt1++)
						for(lCnt1 = 0; lCnt1 < ptMyEPRC->lMaxReqNum; lCnt1++)
						{
							DbgMsg01(DLv04,(OutPut,"***** %s:lMsgType=%x,cReqClass=%02x,lCnt1=%d\n"
									, "os_MainMsgQ", lMsgType, ptErdcp->cReqClass, lCnt1));
							DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n",
									"os_MainMsgQ", ptErdcp));

													/* ��å����������פ��׵���̤����פ������ */
							if (lMsgType == ptErdcp->cReqClass)
							{
													/* �����������Υꥯ�����ȼ��̻Ҥ�����  		*/
//								*rda = ptErdcp->lRCode;		
								break;				/* �������ơ��֥�������θ�����λ����	*/
							}
							/***** �����ѹ���SSLA0001��	Start			��������2002.12.12	*****/
							/********************************************************************/
							/*  osrcvmsr�Ǥ���ס���Хåե���å������������б�				*/
							/********************************************************************/
							else					/* ���פ��ʤ��ä����						*/
							{
													/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ᥤ��ܥå�����)	*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥᥤ��ܥå������� */
													/* �ξ��									*/
								if ((D_MTYPE07 == lMsgType) &&
									(D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
								{
									break;			/* �������ơ��֥�������θ�����λ����	*/
								}
													/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ץ�����)		*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥץ������ˤξ�� */
								if ((D_MTYPE08 == lMsgType) &&
									(D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
								{
									break;			/* �������ơ��֥�������θ�����λ����	*/
								}
													/* �ģãӥ�å������μ����׵�				*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥᥤ��ܥå������� */
													/* �ξ��									*/
								if ((D_MTYPE25 == lMsgType) &&
									(D_ERDC_REQCLASS07 ==ptErdcp->cReqClass))
								{
									break;			/* �������ơ��֥�������θ�����λ����	*/
								}
							}
							/***** �����ѹ���SSLA0001��	 End			��������2002.12.12	*****/

							ptErdcp++;				/* �����ɥ쥹�إݥ��󥿤�ʤ��				*/
						}

													/* �������ơ��֥�������κ����ͤ�Ķ��		*/
						//if (lCnt1 >= ptErdc->lMaxIndNum)
						if (lCnt1 >= ptMyEPRC->lMaxReqNum)
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
								"�����۾�!!", "��������������ơ��֥�θ������Ϥ���ޤ���"));

							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
							free(pcWorkPtr);		/* �������								*/
							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

							return(-9);				/* �۾ｪλ��invalid req descriptor��		*/
						}
						else
						{
													/* �����������ơ��֥��������				*/
													/* �ꥯ�����Ⱦ��֤����׵��(0x01)�װʳ��ξ��*/
							if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
							{
								DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
										"�����۾�!!", "�׵ᤵ�줿�ǡ���������ޤ���"));

								os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
								free(pcWorkPtr);	/* �������								*/
								os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

								return(-10);		/* �۾ｪλ��no request��					*/
							}
						}
						*rda = ptErdcp->lRCode;		/* �����������Υꥯ�����ȼ��̻Ҥ�����  		*/
					}
					else							/* �оݥǡ����ʤ�							*/
					{
						/************************************/
						/*  ��å��������塼���󥰽���		*/
						/************************************/
						lRet = os_MsgQIng(lMsgType, lMsgSize, ptMsg, &ptMyEmbcp->tSubMsgQ);
						if (-1 == lRet)				/* �۾�ξ��								*/
						{
													/* �㳲ȯ��									*/
							DbgMsg01(DLv05, (OutPut, "***** %s:os_MsgQing Call Err lRet=%08x \n",
									 "os_MainMsgQ", lRet));

							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
							free(pcWorkPtr);		/* �������								*/
							os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
							
							return(-1);				/* �۾ｪλ��sys work area exhaust��		*/
						}

						DbgMsg01(DLv04, (OutPut, "***** %s:%s  lRet=%08x\n", "os_MainMsgQ",
								"��å��������塼���󥰽��������ȥ饤������", lRet));

						continue;					/* ��ȥ饤									*/
					}
					break;

				default		:						/* ��λ��å�����							*/
					ptNonMsg = (TNonEndMsg *)ptMsg;	/* ��λ��å������ݥ�������				*/

					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg=%08x \n",
							"os_MainMsgQ", ptNonMsg));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->tMsgHed.lMsgType=%02lx \n",
							"os_MainMsgQ", ptNonMsg->tMsgHed.lMsgType));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->lReqNum=%d \n",
							"os_MainMsgQ", ptNonMsg->lReqNum));
					DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->lResult=%d \n",
							"os_MainMsgQ", ptNonMsg->lResult));

					/************************************/
					/*  �������ơ��֥����������		*/
					/************************************/
					DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n", "os_MainMsgQ", ptErdcp));

					//for(lCnt2 = 0; lCnt2 < ptErdc->lMaxIndNum; lCnt2++)
					for(lCnt2 = 0; lCnt2 < ptMyEPRC->lMaxReqNum; lCnt2++)
					{
						DbgMsg01(DLv04,(OutPut,"***** %s:lMsgType=%02x,cReqClass=%02x,lCnt2=%d \n",
								"os_MainMsgQ", ptMsg->lMsgType, ptErdcp->cReqClass, lCnt2));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp=%08x \n","os_MainMsgQ",ptErdcp));
						DbgMsg01(DLv04,(OutPut,"***** %s:ptErdcp->lReqNum=%08x \n",
								"os_MainMsgQ",ptErdcp->lReqNum));

													/* ��å����������פ��׵���̤����פ������ */
//						if (lMsgType == ptErdcp->cReqClass)
													/* ����������å����������פ�				*/
													/* �������ơ��֥���׵���̤����� ����	*/
													/* ���������ꥯ�������ֹ�ȣ������ơ��֥� */
													/* �Υꥯ�������ֹ椬���פ�����			*/
						if ((lMsgType == ptErdcp->cReqClass) &&
							(ptNonMsg->lReqNum == ptErdcp->lReqNum))
						{
							break;					/* �������ơ��֥�������θ�����λ����	*/
						}
						ptErdcp++;					/* �����ɥ쥹�إݥ��󥿤�ʤ��				*/
					}
													
					//if(lCnt2 >= ptErdc->lMaxIndNum)/*�������ơ��֥�������κ����ͤ�Ķ��	*/
					if(lCnt2 >= ptMyEPRC->lMaxReqNum)
					{
//						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
//								"�����۾�!!", "��������������ơ��֥�θ������Ϥ���ޤ���"));

//						free(pcWorkPtr);			/* �������								*/
//						return(-9);					/* �۾ｪλ��invalid req descriptor��		*/
						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
			 					"�����۾�!!", "����������å��������˴�������ȥ饤���롣"));
						continue;					/* ��ȥ饤									*/
					}
													/* �ꥯ�����Ⱦ��֤���λ�׵�Ѥ߰ʳ��ξ�� */
					if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
					{
						DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->tReqStat.cUCompStat=%02x\n",
								"os_MainMsgQ", ptErdcp->tReqStat.cUCompStat));
						DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MainMsgQ",
			 					"�����۾�!!", "����������å��������˴�������ȥ饤���롣"));
						continue;					/* ��ȥ饤									*/
					}

					*rda = ptErdcp->lRCode;			/* �����������Υꥯ�����ȼ��̻Ҥ�����  		*/
					break;
			}
		}


		/****************************************/
		/*  ������̤��Խ�						*/
		/****************************************/
		if (0 < lLimit)								/* ���»��֤���0�פ���礭���ξ��			*/
		{
			os_tmcan(0);							/* �����ޥ���󥻥�							*/
		}

													/* ������̤��Խ�							*/
		lRet = os_MsgRcvEdit(lMsgType, lMsgSize, ptMsg, ptErdcp);

		DbgMsg01(DLv04, (OutPut, "***** %s:os_MsgRcvEdit  lRet=%08x\n", "os_MainMsgQ", lRet));

		if (0 <= lRet)								/* �ֵ��ͤ�0�ʾ�ξ��						*/
		{
			lRcvRet = lRet;							/* ��̤ؤ��ֵ��ͤ��ֵ��ͤ�����				*/
			break;									/* �롼�׽�����ȴ����						*/
		}
		else										/* �ֵ��ͤ��ޥ��ʥ��ξ��					*/
		{
			if ((D_MTYPE05 == lMsgType) ||			/* �ץ����֥�å������ξ��				*/
				(D_MTYPE06 == lMsgType) ||
				(D_MTYPE07 == lMsgType) ||
				(D_MTYPE08 == lMsgType) ||
				(D_MTYPE25 == lMsgType))
			{
				/* �ä˲��⤷�ʤ�		*/
			}
			else									/* �ץ����֥�å������ʳ��ξ��			*/
			{										/* ����λ����å������ξ���				*/
				lRcvRet = lRet;						/* ��̤ؤ��ֵ��ͤ��ֵ��ͤ�����				*/
				break;								/* �롼�׽�����ȴ����						*/
			}
		}
		if (1 == lMsgFlg)							/* ������ꥶ��Ƚ����ξ��					*/
		{
			*rda = 0;								/* �ꥯ�����ȼ��̻ҳ�Ǽ��򥯥ꥢ  			*/
		}

		/****************************************/
		/*  ���顼Ƚ��							*/
		/****************************************/
		switch (lRet)
		{
			case	-1:								/* sys work area exhaust					*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* �������								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* �ꥯ�����ȼ��̻ҳ�Ǽ��򥯥ꥢ  			*/
				return(-1);
				break;

			case	-2:								/* invalid buffer pool						*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* �������								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* �ꥯ�����ȼ��̻ҳ�Ǽ��򥯥ꥢ  			*/
				return(-6);
				break;

			case	-3:								/* not pool buffer							*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* �������								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* �ꥯ�����ȼ��̻ҳ�Ǽ��򥯥ꥢ  			*/
				return(-7);
				break;

			case	-4:								/* invalid pool buffer						*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
				free(pcWorkPtr);					/* �������								*/
				os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );
				*rda = 0;							/* �ꥯ�����ȼ��̻ҳ�Ǽ��򥯥ꥢ  			*/
				return(-8);
				break;

			default		:							/* ��λ����å������ʰ۾�ξ���			*/
				break;
		}
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
	/********************************/
	/*  �������					*/
	/********************************/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_FREE, 1, pcWorkPtr );
	free(pcWorkPtr);								/* �������								*/
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_SYS_END, 0 );

													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End  DbgSubFnc\n", "os_MainMsgQ" ) );
	os_trcget2( D_MD_OS_MAINMSGQ, D_T_TRA_OUT, 0 );
	return (lRcvRet);								/* ���ｪλ									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
