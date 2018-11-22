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
/* �㥵���ӥ�����̾��				 �ꥶ��ȡ��㳰												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 ��λ�������׵�μ�ä�									*/
/* ��⥸�塼��ɣġ�				 oscanrq													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)							*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �������׵��Ф�������λ�������׵���Ф�������μ��ä����׵᤹�롣						*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscanrq.h>																	*/
/*																								*/
/*	   	long	oscanrq(long rd)																*/
/*																								*/
/* �㲾������																					*/
/*		long		rd;																			*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		OSEEIVNO	���ꥯ�����ȼ��̻Ҥ��ͤ�����   												*/
/*		OSEENREQ	��̤�׵�																	*/
/*		OSEEIGNR	������󥻥�����															*/
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
#include	"oscanrq.h"
#include	"oscanrq_ins.h"


long	oscanrq(rd)
long	rd;											/* �ꥯ�����ȼ��̻�							*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lCnt1;							/* �롼�ץ�����1							*/
	long			lCnt2;							/* �롼�ץ�����2							*/
	long			lCnt3;							/* �롼�ץ�����3							*/
	long			lCnt4;							/* �롼�ץ�����4							*/
	long			lRet;							/* �ֵ���									*/
	long			lBufSize;						/* ���ϥХåե�������						*/
	char			*pcBuf = NULL;					/* �����ѥХåե��ΰ�						*/
//	TMsgHed			tMsgBuf;						/* �����ѥХåե��ΰ�						*/
	TArgInfo		tTArgInfo; 						/* �׵�����ѥ����������					*/
	TErdcTableInd	*ptErdcp = NULL;				/* �������ơ��֥�������ݥ���			*/
	TEcncTableInd	*ptEcncp = NULL;				/* ���ͥ����������ơ��֥�������ݥ���	*/


	os_trcget2( D_MD_OSCANRQ, D_T_TRA_IN, 1, rd );

													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "oscanrq" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lCnt1 = 0;
	lCnt2 = 0;
	lCnt3 = 0;
	lCnt4 = 0;
	lRet  = 0;
	errno = 0;

	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ����������������Ƭ���ɥ쥹����         */
	ptEcncp = (TEcncTableInd *)(ptEcnc + 1);		/* ���ͥ�������������������Ƭ���ɥ쥹���� */


	/************************************/
	/*  ���������å�					*/
	/************************************/

	/* �ꥯ�����ȼ��̻ҡ�rd�ˤΥ����å� */
													/* �롼�׽���								*/
	//for (lCnt1 = 0; lCnt1 < ptErdc->lMaxIndNum; lCnt1++)
	for (lCnt1 = 0; lCnt1 < ptMyEPRC->lMaxReqNum; lCnt1++)
	{
		if (rd == ptErdcp->lRCode)					/* �ꥯ�����ȼ��̻Ҥ����פ������			*/
		{
			break;									/* �롼�פ�ȴ����							*/
		}

		ptErdcp++;									/* �����ɥ쥹�إݥ��󥿤�ʤ��				*/
	}

	//if (lCnt1 >= ptErdc->lMaxIndNum)				/* �������ơ��֥�������κ����ͤ�Ķ��		*/
	if (lCnt1 >= ptMyEPRC->lMaxReqNum)
	{												/* �������ơ��֥�θ�������¸�ߤ��ʤ���� */
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "oscanrq",
			"�����۾�!!", "��������������ơ��֥�θ������Ϥ���ޤ���"));
			
		os_trcget2( D_MD_OSCANRQ, D_T_ERR_PRA, 1, OSEEIVRD );
			
		return(OSEEIVRD);							/* �۾ｪλ��invalid req descriptor��		*/
	}
	else
	{
													/* �����������ơ��֥��������				*/
													/* �ꥯ�����Ⱦ��֤����׵��(0x01)�װʳ��ξ��*/
		if (D_ERDC_UCOMPSTAT_REQ != ptErdcp->tReqStat.cUCompStat)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  �ꥯ�����Ⱦ���=%02x \n", "oscanrq",
					"�����۾�!!", "�׵ᤵ�줿�ǡ���������ޤ���", ptErdcp->tReqStat.cUCompStat));
					
			os_trcget2( D_MD_OSCANRQ, D_T_ERR_PRA, 1, OSEENREQ );
			
			return(OSEENREQ);						/* �۾ｪλ��no request��					*/
		}
	}

	DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop1 Count=%#d ����  ", "oscanrq", lCnt1));
	DbgMsg01(DLv04, (OutPut, "ptErdcp=%08x \n", ptErdcp));


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/********************************************************/
	/*  ��λ�׵�μ��ä����׵������˽�����ʬ����	*/
	/********************************************************/
	switch (ptErdcp->cReqClass)						/* �׵������˽�����ʬ��					*/
	{
		case	D_ERDC_REQCLASS02:					/* ���󥿡��Х륿����						*/
		case	D_ERDC_REQCLASS03:					/* ���勵����								*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s �׵����=%02x \n", "oscanrq",
					"���󥿡��Х륿�������ϻ��勵���ޤν���", ptErdcp->cReqClass));

			os_tmcan(rd);							/* �����ޥ���󥻥��ȯ��					*/

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* 20030227 �ɲ�							*/
													/* ����rd����������λ�׵���֤�			*/
													/*						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* �ꥯ�������ֹ楯�ꥢ						*/

			ptErdcp->cReqClass = 0x00;				/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/

			break;

		case	D_ERDC_REQCLASS05:					/* ��å������μ����׵�ʥᥤ��ܥå�������	*/
		case	D_ERDC_REQCLASS06:					/* ��å������μ����׵�ʥץ�������		*/
		case	D_ERDC_REQCLASS07:					/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ᥤ��ܥå�����)	*/
		case	D_ERDC_REQCLASS08:					/* �ץ������ס���Хåե�ͭ��				*/
													/* 				�����׵�ʥץ�������		*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq",
					"�ץ����֥�å������ν���", ptErdcp->cReqClass));
			break;

//		case	D_ERDC_REQCLASS17:					/* TCP/IP���ͥ����������桦�ƻ�(osiioct2)	*/
		case	D_ERDC_REQCLASS22:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq",
					"TCP/IP���ͥ����������桦�ƻ�ν���"));

													/* ��Ʊ�������׵���󤫤鸡��				*/
			for (lCnt2 = 0; lCnt2 < ptEcnc->lMaxIndNum; lCnt2++)
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lCnt2=%d \n", "oscanrq", lCnt2));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode=%08x \n", "oscanrq",
						ptErdcp->lRCode));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->tAsyncInfo.lReqId=%08x \n",
						"oscanrq", ptEcncp->tAsyncInfo.lReqId));

													/* �ꥯ�����ȼ��̻Ҥ����פ������			*/
				if (ptErdcp->lRCode == ptEcncp->tAsyncInfo.lReqId)
				{
					break;							/* �롼�פ�ȴ����							*/
				}
				ptEcncp++;
			}

			if (lCnt2 >= ptEcnc->lMaxIndNum)		/* ���ͥ����������κ������������Ķ��		*/
			{
				DbgMsg01(DLv05, (OutPut, "\n***** %s:%s  %s \n", "oscanrq",
					"�����۾�!!", "�������륳�ͥ����������ơ��֥�θ������Ϥ���ޤ���"));
					
				os_trcget2( D_MD_OSCANRQ, D_T_ERR_SYS, 1, OSEENREQ );	

				return(OSEENREQ);					/* �۾ｪλ��invalid req descriptor��		*/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->alPipeDes[1]=%d \n", "oscanrq",
					ptEcncp->alPipeDes[1]));

			/*  �ѥ��ץǥ�������ץ��Υ����å� */
			if (0 != ptEcncp->alPipeDes[1])			/* �����ѥѥ��ץǥ�������ץ���0�ʳ��ξ��  */
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "����󥻥�����"));

				/********************************/
				/*  ����󥻥�����				*/
				/********************************/
//				tMsgBuf.lMsgType = D_MTYPE18;		/* ��å�����������							*/
//				tMsgBuf.pcPlBuf = NULL;				/* �ס���Хåե�							*/
//				tMsgBuf.lDataSize = 0;				/* �ǡ���������								*/

				/********************************/
				/*  ����������Ⱦ�������		*/
				/********************************/
													/* �׵���̡���Ʊ�������׵ᥭ��󥻥��		*/
				tTArgInfo.cRecClass = D_REQCLASS_ASYNC_CANCEL;
				tTArgInfo.lRCode = 0;				/* �ꥯ�����ȼ��̻�							*/
				tTArgInfo.ulReqNum = 0;				/* �ꥯ�������ֹ�							*/
				tTArgInfo.pvArg1 = NULL; 			/* ��������								*/
				tTArgInfo.pvArg2 = NULL; 			/* ��������								*/

				pcBuf = &tTArgInfo;					/* �����ѥХåե��ΰ������					*/
				lBufSize = sizeof(TArgInfo);		/* ���ϥХåե�������������					*/

				DbgMsg01(DLv04, (OutPut, "\n***** %s:tTArgInfo.cRecClass=%02x \n",
						"oscanrq", tTArgInfo.cRecClass));
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lBufSize=%ld \n", "oscanrq", lBufSize));

				while (1)							/* �롼�׽���								*/
				{
													/* �ե�����ǥ�������ץ��˽񤭹���			*/
//					lRet = write(ptEcncp->alPipeDes[1], &tMsgBuf, sizeof(TMsgHed));
					lRet = write(ptEcncp->alPipeDes[1], pcBuf, lBufSize);
					DbgMsg01(DLv04, (OutPut, "\n***** %s:write lRet=%08x \n", "oscanrq", lRet));

					if (D_ERR_SYS == lRet)			/* �ֵ��ͤ��۾�ξ��						*/
					{
						if (EINTR == errno)			/* ������ȯ��								*/
						{
							continue;				/* ��ȥ饤									*/
						}
						else						/* �㳲ȯ��                                 */
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
							"oscanrq", "write() Call Error!!", errno, strerror(errno)));
							break;
						}
					}
					else if (lBufSize == lRet)		/* ���ϥХåե����������ֵ��ͤ�Ʊ��ξ��	*/
					{
						break;						// �롼�פ�ȴ����
					}
					else							/* �Ĥ�Υǡ�����������					*/
					{
						pcBuf = pcBuf + lRet;		/* ���ϥХåե��Υ��ɥ쥹���֤򹹿�			*/
						lBufSize = lBufSize - lRet; /* ���ϥ���������Ĥ�Υ������򸺻�			*/
					}
				}
			}

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/*						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* �ꥯ�������ֹ楯�ꥢ						*/

			ptErdcp->cReqClass = 0x00;				/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/
			break;

//		case	D_ERDC_REQCLASS19:					/* TCP/IP�꡼��(osireadd2)					*/
		case	D_ERDC_REQCLASS23:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "TCP/IP�꡼�ɤν���"));

													/* read�׵���󤫤鸡��						*/
			for (lCnt3 = 0; lCnt3 < ptEcnc->lMaxIndNum; lCnt3++)
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lCnt3=%d \n", "oscanrq", lCnt3));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode=%08x \n", "oscanrq",
						ptErdcp->lRCode));
				DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->tReaInfo.lReqId=%08x \n",
						"oscanrq", ptEcncp->tReaInfo.lReqId));

													/* �ꥯ�����ȼ��̻Ҥ����פ������			*/
				if (ptErdcp->lRCode == ptEcncp->tReaInfo.lReqId)
				{
					break;							/* �롼�פ�ȴ����							*/
				}
				ptEcncp++;
			}

			if (lCnt3 >= ptEcnc->lMaxIndNum)		/* ���ͥ����������κ������������Ķ��		*/
			{
				DbgMsg01(DLv05, (OutPut, "\n***** %s:%s  %s \n", "oscanrq",
					"�����۾�!!", "�������륳�ͥ����������ơ��֥�θ������Ϥ���ޤ���"));
		
				os_trcget2( D_MD_OSCANRQ, D_T_ERR_SYS, 1, OSEENREQ );
					
	/*****	�㳲�б���TBCS0120��	Start								��������2003.06.16	*****/
	/********************************************************************************************/
	/*	OSEENREQ�Υ��顼�ֵѤ��ᡢ�������ơ��֥�򥯥ꥢ����褦�˽���						*/
	/********************************************************************************************/
//				return(OSEENREQ);					/* �۾ｪλ��invalid req descriptor��		*/

				/********************************/
				/* �������ơ��֥���Խ�		*/
				/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/*						��̤�׵�פ�����	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

				ptErdcp->lReqNum = 0L;				/* �ꥯ�������ֹ楯�ꥢ						*/

				ptErdcp->cReqClass = 0x00;			/* �׵���̥��ꥢ							*/

				ptErdcp->pvArg1 = (void *)NULL;		/* �����ΰ裱���ꥢ							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* �����ΰ裲���ꥢ							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* �����ΰ裳���ꥢ							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* �����ΰ裴���ꥢ							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* �����ΰ裵���ꥢ							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* �����ΰ裶���ꥢ							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* �����ΰ裷���ꥢ							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* �����ΰ裸���ꥢ							*/
				break;
	/*****	�㳲�б���TBCS0120��	 End								��������2003.06.16	*****/
			}

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEcncp->alPipeDes[1]=%d \n", "oscanrq",
					ptEcncp->alPipeDes[1]));

			/*  �ѥ��ץǥ�������ץ��Υ����å� */
			if (0 != ptEcncp->alPipeDes[1])			/* �����ѥѥ��ץǥ�������ץ���0�ʳ��ξ��  */
			{
				DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "����󥻥�����"));

				/********************************/
				/*  ����󥻥�����				*/
				/********************************/
//				tMsgBuf.lMsgType = D_MTYPE20;		/* ��å�����������							*/
//				tMsgBuf.pcPlBuf = NULL;				/* �ס���Хåե�							*/
//				tMsgBuf.lDataSize = 0;				/* �ǡ���������								*/

				/********************************/
				/*  ����������Ⱦ�������		*/
				/********************************/
													/* �׵���̡�READ�׵ᥭ��󥻥��			*/
				tTArgInfo.cRecClass = D_REQCLASS_READ_CANCEL;
				tTArgInfo.lRCode = 0;				/* �ꥯ�����ȼ��̻�							*/
				tTArgInfo.ulReqNum = 0;				/* �ꥯ�������ֹ�							*/
				tTArgInfo.pvArg1 = NULL; 			/* ��������								*/
				tTArgInfo.pvArg2 = NULL; 			/* ��������								*/

				pcBuf = &tTArgInfo;					/* �����ѥХåե��ΰ������					*/
				lBufSize = sizeof(TArgInfo);		/* ���ϥХåե�������������					*/

				DbgMsg01(DLv04, (OutPut, "\n***** %s:tTArgInfo.cRecClass=%02x \n",
						"oscanrq", tTArgInfo.cRecClass));
				DbgMsg01(DLv04, (OutPut, "\n***** %s:lBufSize=%ld \n", "oscanrq", lBufSize));

				while (1)							/* �롼�׽���								*/
				{
													/* �ե�����ǥ�������ץ��˽񤭹���			*/
//					lRet = write(ptEcncp->alPipeDes[1], &tMsgBuf, sizeof(TMsgHed));
					lRet = write(ptEcncp->alPipeDes[1], pcBuf, lBufSize);
					DbgMsg01(DLv04, (OutPut, "\n***** %s:write lRet=%08x \n", "oscanrq", lRet));

					if (D_ERR_SYS == lRet)
					{
						if (EINTR == errno)			/* ������ȯ��								*/
						{
							continue;				/* ��ȥ饤									*/
						}
						else						/* �㳲ȯ��                                 */
						{
							DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
							"oscanrq", "write() Call Error!!", errno, strerror(errno)));
							break;
						}
					}
					else if (lBufSize == lRet)		/* ���ϥХåե����������ֵ��ͤ�Ʊ��ξ��	*/
					{
						break;						// �롼�פ�ȴ����
					}
					else							/* �Ĥ�Υǡ�����������					*/
					{
						pcBuf = pcBuf + lRet;		/* ���ϥХåե��Υ��ɥ쥹���֤򹹿�			*/
						lBufSize = lBufSize - lRet; /* ���ϥ���������Ĥ�Υ������򸺻�			*/
					}
				}
			}

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/*						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* �ꥯ�������ֹ楯�ꥢ						*/

			ptErdcp->cReqClass = 0x00;				/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/
			break;

	/*****	�㳲�б���TBCS0078��	Start								��������2003.05.07	*****/
	/********************************************************************************************/
	/*	osiwritd2�Ρʣ������ơ��֥�Υ��ꥢ�˽������ɲ�										*/
	/********************************************************************************************/
//		case	D_ERDC_REQCLASS21:					/* TCP/IP�饤��(osiwritd2)					*/
		case	D_ERDC_REQCLASS24:
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "TCP/IP�饤�Ȥν���"));

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/*						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0L;					/* �ꥯ�������ֹ楯�ꥢ						*/

			ptErdcp->cReqClass = 0x00;				/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/
	/*****	�㳲�б���TBCS0078��	 End								��������2003.05.07	*****/
			break;

		default		:								/* ����¾����λ�׵�						*/
			DbgMsg01(DLv04, (OutPut, "\n***** %s:%s \n", "oscanrq", "����¾��λ�ν���"));
			break;
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "oscanrq" ) );


	os_trcget2( D_MD_OSCANRQ, D_T_TRA_OUT, 1, OSEEIGNR );

	return (OSEEIGNR);								/* ����󥻥�����							*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
