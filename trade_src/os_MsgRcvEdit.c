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
/* ��⥸�塼��ɣġ�				 os_MsgRcvEdit												*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼����:�أأأ�)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*      ��å�����������̤��Խ������򤹤롣                                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long	os_MsgRcvEdit(lMsgType, lMsgSize, ptMsg, ptErdcp)
/*																								*/
/* �㲾������																					*/
/*      long			lMsgType;					   ��å�����������							*/
/*      long			lMsgSize;					   ��å���������������						*/
/*      TMsgHed			*ptMsg;						   ��å�����								*/
/*      TErdcTableInd	*ptErdcp;					   �����������������ݥ���				*/
/*																								*/
/* ���ֵ��͡�																					*/
/*      NORMAL      ������                                                                      */
/*      -1          ��sys work area exhaust                                                     */
/*      -2          ��invalid buffer pool                                                       */
/*      -3          ��not pool buffer                                                           */
/*      -4          ��invalid pool buffer                                                       */
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
/************************************************************************************************/
/*                                                                                              */
/*  �����������ե�����̾                                                                        */
/*      os_MsgRcvEditEdit.c                                                                     */
/*                                                                                              */
/*                                                                                              */
/*  �����ץ����̾��                                                                          */
/*      ��å�����������̤��Խ�����                                                            */
/*                                                                                              */
/*                                                                                              */
/*  ������ǽ����                                                                                */
/*      ��å�����������̤��Խ������򤹤롣                                                    */
/*                                                                                              */
/*                                                                                              */
/*  �����ƤӽФ�����                                                                            */
/*      long	os_MsgRcvEdit(lMsgType, lMsgSize, ptMsg, ptErdcp)                               */
/*                                                                                              */
/*                                                                                              */
/*  ��������                                                                                    */
/*      long			lMsgType;					   ��å�����������							*/
/*      long			lMsgSize;					   ��å���������������						*/
/*      TMsgHed			*ptMsg;						   ��å�����								*/
/*      TErdcTableInd	*ptErdcp;					   �����������������ݥ���				*/
/*                                                                                              */
/*  �����ֵ���                                                                                  */
/*      NORMAL      ������                                                                      */
/*      -1          ��sys work area exhaust                                                     */
/*      -2          ��invalid buffer pool                                                       */
/*      -3          ��not pool buffer                                                           */
/*      -4          ��invalid pool buffer                                                       */
/*                                                                                              */
/*                                                                                              */
/*  ����������ࡦ�õ�����                                                                      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/


/************************************************************************************************/
/*  ���󥯥롼�ɥե�����                                                                        */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/


/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	"os_MsgRcvEdit_ins.h"


long	os_MsgRcvEdit(lMsgType, lMsgSize, ptMsg, ptErdcp)
long			lMsgType;							/* ��å�����������							*/
long			lMsgSize;							/* ��å���������������						*/
TMsgHed			*ptMsg;								/* ��å�����								*/
TErdcTableInd	*ptErdcp;							/* �����������������ݥ���				*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lRcvPlBuf;						/* �����ס���Хåե����ɥ쥹				*/
	long			lBufPl;							/* �Хåե��ס��륢�ɥ쥹					*/
	long			lRcvRet;						/* ��̤ؤ��ֵ�����							*/
	long			lRet;							/* �ֵ���									*/
	long			*palPlList[2];					/* �ס���Хåե����ɥ쥹�ꥹ��				*/
	char			*pcDcsPtr = NULL;				/* �ģã��ѥݥ���							*/
	TPbInfo			*ptPbInfo = NULL;				/* �ס���Хåե���������ݥ���			*/
	TDcsMsgHed		*ptDcsMsg = NULL;				/* �ģãӥ�å������ݥ���					*/
	TNonEndMsg		*ptNonMsg = NULL;				/* ��λ��å������ݥ���					*/
	TEpbcTableInd	*ptEpbcp  = NULL;				/* ��˥åȴ�������ݥ���					*/

	os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_TRA_IN, 4, lMsgType, lMsgSize, ptMsg, ptErdcp );
													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MsgRcvEdit" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lRcvPlBuf = 0;
	lBufPl    = 0;
	lRcvRet   = 0;
	lRet      = 0;
	errno     = 0;

	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType = %02lx \n", "os_MsgRcvEdit", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgSize = %ld   \n", "os_MsgRcvEdit", lMsgSize));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg    = %08lx \n", "os_MsgRcvEdit", (long)ptMsg));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp  = %08lx \n", "os_MsgRcvEdit", (long)ptErdcp));


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/****************************************/
	/*  ������̤��Խ�						*/
	/*  �ʥ�å����������פǽ����򿶤�ʬ����*/
	/****************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType=%02x \n", "os_MsgRcvEdit", lMsgType));

	switch (lMsgType)								/* ��å����������פǿ���ʬ��				*/
	{
		case	D_MTYPE05:							/* ��å������μ����׵�ʥᥤ��ܥå������� */
		case	D_MTYPE06:							/* ��å������μ����׵�ʥץ�������		*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_MsgRcvEdit",
					"�ץ����֥�å������ʥס���Хåե�̵����"));

			/********************************/
			/*  ������å������Υ��ԡ�		*/
			/********************************/
													/* ��å�����Ĺ���¤�Ƚ��					*/
													/* ��å�����Ĺ����ͭ��						*/
			if (ptMsg->lDataSize > *(long *)ptErdcp->pvArg1)
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
						"os_MsgRcvEdit", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* ��å����������Хåե��˥��ԡ�			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), *(long *)ptErdcp->pvArg1); 
				lRcvRet = *(long *)ptErdcp->pvArg1;	/* ��������������							*/
			}
			else									/* ��å�����Ĺ����̵��						*/
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
						"os_MsgRcvEdit", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* ��å����������Хåե��˥��ԡ�			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), ptMsg->lDataSize);
				lRcvRet = ptMsg->lDataSize;			/* ��������������							*/
			}

			/********************************/
			/* ��å�����Ĺ���¤Υ������ */
			/********************************/
			DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_MsgRcvEdit",
					ptErdcp->pvArg1));
			
			os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
			free(ptErdcp->pvArg1);					/* �������								*/
			os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_END, 0 );

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
/*			20030225����
													// ��å������׵᥯�ꥢ
			if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)
			{
													// �ᥤ��ܥå������ס���Хåե�̵�����ꥢ
				ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
			}
			else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)
			{
													// �ץ������ס���Хåե�̵�����ꥢ
				ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
			}
*/
			if (D_MTYPE05 == lMsgType)
			{
													// �ᥤ��ܥå������ס���Хåե�̵�����ꥢ
				ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
			}
			else if (D_MTYPE06 == lMsgType)
			{
													// �ץ������ס���Хåե�̵�����ꥢ
				ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
			}

													/* ����rd����������λ�׵���֤�			*/
													/* 						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->cReqClass = D_ERDC_REQCLASS00;	/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/
			break;

		case	D_MTYPE07:							/* �ᥤ��ܥå������ס���Хåե�ͭ��		*/
		case	D_MTYPE08:							/* �ץ������ס���Хåե�ͭ��				*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_MsgRcvEdit",
					"�ץ����֥�å������ʥס���Хåե�ͭ���"));

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lMsgType=%02x \n", "os_MsgRcvEdit",
					ptMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->pcPlBuf=%08x \n", "os_MsgRcvEdit",
					ptMsg->pcPlBuf));

			/********************************/
			/*  �����ס���Хåե����ɥ쥹  */
			/*  �Υ����������å�			*/
			/********************************/
			lRcvPlBuf = (long)ptMsg->pcPlBuf;		/* �����ס���Хåե����ɥ쥹����			*/
			lBufPl = (long)ptEbpc->pvAdr;			/* �Хåե��ס����������Ƭ���ɥ쥹����		*/
			lBufPl = lBufPl + ptEbpc->lSize;		/* �Хåե��ס��������������û�			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:lRcvPlBuf=%08x, lBufPl=%08x \n", "os_MsgRcvEdit",
					lRcvPlBuf, lBufPl));

													/* �����ס���Хåե����ɥ쥹��				*/
			if (lRcvPlBuf > lBufPl)					/* �Хåե��ס���������ΰ��Ķ�ᤷ�����	*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  RcvPlBuf=%08x, BufPl=%08x \n",
		 				"os_MsgRcvEdit", "�����۾�!!", lRcvPlBuf, lBufPl));
				return(-2);							/* �۾ｪλ��invalid buffer pool��			*/
			}

			/********************************/
			/*  ������˥åȾ����			*/
			/*  ������ץ����ɣĥ����å�	*/
			/********************************/
													/* �ס���Хåե���������ݥ�������		*/
			ptPbInfo = (TPbInfo *)(ptMsg->pcPlBuf - 4);

			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo=%08x \n", "os_MsgRcvEdit", ptPbInfo));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo->ptNxtAdr=%08x \n", "os_MsgRcvEdit",
					ptPbInfo->ptNxtAdr));

													/* ��˥åȴ�������ݥ�������				*/
			ptEpbcp = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp=%08x \n", "os_MsgRcvEdit", ptEpbcp));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_MsgRcvEdit",
					ptEpbcp->lUsePid));

													/* ������ץ���ID���֡ݣ��װʳ��ξ��		*/
			if (D_EPBC_USEPID_SEND != ptEpbcp->lUsePid)
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  UsePid=%08x \n", "os_MsgRcvEdit",
				 		"�����۾�!!", ptEpbcp->lUsePid));
				return(-3);							/* �۾ｪλ��not pool buffer��				*/
			}

													/* �ּ��ץ����ɣġפ�����					*/
			ptEpbcp->lUsePid = ptEsys->tMyPrcInfo.lMyPid;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEsys->tMyPrcInfo.lMyPid=%08x \n", "os_MsgRcvEdit",
					ptEsys->tMyPrcInfo.lMyPid));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_MsgRcvEdit",
					ptEpbcp->lUsePid));

			/***** �����ѹ���SSLA0001��	Start							��������2002.12.12	*****/
			/************************************************************************************/
			/*  osrcvmsr�Ǥ���ס���Хåե���å������������б�								*/
			/************************************************************************************/
													/* �ס���Хåե�̵���μ����׵�ξ��		*/
			if (((D_MTYPE07 == lMsgType) && (D_ERDC_REQCLASS05 ==ptErdcp->cReqClass)) ||
				((D_MTYPE08 == lMsgType) && (D_ERDC_REQCLASS06 ==ptErdcp->cReqClass)))
			{
				/********************************/
				/*  ������å������Υ��ԡ�		*/
				/********************************/
													/* ��å�����Ĺ���¤�Ƚ��					*/
													/* ��å�����Ĺ����ͭ��						*/
				if (ptMsg->lDataSize > *(long *)ptErdcp->pvArg1)
				{
					DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
							"os_MsgRcvEdit", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));
	
													/* ��å����������Хåե��˥��ԡ�			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, *(long *)ptErdcp->pvArg1);
													/* ��������������							*/
					lRcvRet = *(long *)ptErdcp->pvArg1;
				}
				else								/* ��å�����Ĺ����̵��						*/
				{
					DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
							"os_MsgRcvEdit", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* ��å����������Хåե��˥��ԡ�			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, ptMsg->lDataSize);
					lRcvRet = ptMsg->lDataSize;		/* ��������������							*/
				}

				/********************************/
				/* ��å�����Ĺ���¤Υ������ */
				/********************************/
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_MsgRcvEdit",
						ptErdcp->pvArg1));
				
				os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
				free(ptErdcp->pvArg1);				/* �������								*/
				os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_END, 0 );

				/********************************/
				/* �ס���Хåե��β���			*/
				/********************************/
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->pcPlBuf=%08x \n", "os_MsgRcvEdit",
						ptMsg->pcPlBuf));
													/* �ס���Хåե����ɥ쥹�ꥹ�Ȥ�			*/
													/* ���������ס���Хåե����ɥ쥹������		*/
				palPlList[0] = (long *)ptMsg->pcPlBuf;

				DbgMsg01(DLv04, (OutPut, "***** %s:palPlList[0] =%08x \n", "os_MsgRcvEdit",
						palPlList[0]));
				DbgMsg01(DLv04, (OutPut, "***** %s:&palPlList[0]=%08x \n", "os_MsgRcvEdit",
						&palPlList[0]));

				lRet = osfrpbf(1L, &palPlList[0]);	/* �ס���Хåե��β���						*/
				if (NORMAL != lRet)					/* �����۾�ξ��							*/
				{
					DbgMsg01(DLv05, (OutPut, "***** %s:%s  UsePid=%08x \n",
				 			"os_MsgRcvEdit", "�����۾�!!", ptEpbcp->lUsePid));
					return(-4);						/* �۾ｪλ��invalid pool buffer��			*/
				}

				/********************************/
				/* �������ơ��֥���Խ�		*/
				/********************************/
/*				20030225 ����
													// ��å������׵᥯�ꥢ
				if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)
				{
													// �ᥤ��ܥå������ס���Хåե�̵�����ꥢ
					ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
				}
				else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)
				{
													// �ץ������ס���Хåե�̵�����ꥢ
					ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
				}
*/
													// ��å������׵᥯�ꥢ
				if ( (D_MTYPE07 == lMsgType) && (D_ERDC_REQCLASS05 ==ptErdcp->cReqClass) )
				{
													// �ᥤ��ܥå������ס���Хåե�̵�����ꥢ
					ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
				}
				else if ((D_MTYPE08 == lMsgType) && (D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
				{
													// �ץ������ס���Хåե�̵�����ꥢ
					ptErdc->tMsgFlg.cPrcPbOff = D_ERDC_MSGFLG_OFF;
				}
													/* ����rd����������λ�׵���֤�			*/
													/* 						��̤�׵�פ�����	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

													/* �׵���̥��ꥢ							*/
				ptErdcp->cReqClass = D_ERDC_REQCLASS00;

				ptErdcp->pvArg1 = (void *)NULL;		/* �����ΰ裱���ꥢ							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* �����ΰ裲���ꥢ							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* �����ΰ裳���ꥢ							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* �����ΰ裴���ꥢ							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* �����ΰ裵���ꥢ							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* �����ΰ裶���ꥢ							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* �����ΰ裷���ꥢ							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* �����ΰ裸���ꥢ							*/
			}
			else									/* �ס���Хåե�ͭ��μ����׵�ξ��		*/
			{
													/* �ס���Хåե����ɥ쥹��Ǽ��إ��ԡ�		*/
				*(long *)ptErdcp->pvArg1 = (long)ptMsg->pcPlBuf; 

				lRcvRet = ptMsg->lDataSize;			/* �ֵ��ͤ˼����ǡ���������������			*/

				/********************************/
				/* �������ơ��֥���Խ�		*/
				/********************************/
/*				20030225 ����
													// ��å������׵᥯�ꥢ
				if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn)
				{
													// �ᥤ��ܥå������ס���Хåե�ͭ�ꥯ�ꥢ
					ptErdc->tMsgFlg.cMbPbOn = D_ERDC_MSGFLG_OFF;
				}
				else if (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn)
				{
													// �ץ������ס���Хåե�ͭ�ꥯ�ꥢ
					ptErdc->tMsgFlg.cPrcPbOn = D_ERDC_MSGFLG_OFF;
				}
*/
													// ��å������׵᥯�ꥢ
				if (D_MTYPE07 == lMsgType)
				{
													// �ᥤ��ܥå������ס���Хåե�ͭ�ꥯ�ꥢ
					ptErdc->tMsgFlg.cMbPbOn = D_ERDC_MSGFLG_OFF;
				}
				else if (D_MTYPE08 == lMsgType)
				{
													// �ץ������ס���Хåե�ͭ�ꥯ�ꥢ
					ptErdc->tMsgFlg.cPrcPbOn = D_ERDC_MSGFLG_OFF;
				}
													/* ����rd����������λ�׵���֤�			*/
													/* 						��̤�׵�פ�����	*/
				ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
				ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

													/* �׵���̥��ꥢ							*/
				ptErdcp->cReqClass = D_ERDC_REQCLASS00;

				ptErdcp->pvArg1 = (void *)NULL;		/* �����ΰ裱���ꥢ							*/
				ptErdcp->pvArg2 = (void *)NULL;		/* �����ΰ裲���ꥢ							*/
				ptErdcp->pvArg3 = (void *)NULL;		/* �����ΰ裳���ꥢ							*/
				ptErdcp->pvArg4 = (void *)NULL;		/* �����ΰ裴���ꥢ							*/
				ptErdcp->pvArg5 = (void *)NULL;		/* �����ΰ裵���ꥢ							*/
				ptErdcp->pvArg6 = (void *)NULL;		/* �����ΰ裶���ꥢ							*/
				ptErdcp->pvArg7 = (void *)NULL;		/* �����ΰ裷���ꥢ							*/
				ptErdcp->pvArg8 = (void *)NULL;		/* �����ΰ裸���ꥢ							*/
			}
			/***** �����ѹ���SSLA0001��	 End							��������2002.12.12	*****/
			break;

		case	D_MTYPE25:							/* DCS��å������μ����׵�					*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_MsgRcvEdit", "�ģãӥ�å�����"));

			/********************************/
			/*  �ģãӥ�å��������Խ�		*/
			/********************************/
//			os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_MALLOC, 1, lMsgSize + 8 + 4 );
			os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_MALLOC, 1, lMsgSize + sizeof(TDcsMsgHed) );
													/* �������								*/

//			pcDcsPtr = malloc(lMsgSize + 8 + 4);	/* �����Х��ȥ����� + ���Х���				*/
													/* 20030330 ����*/
													/* �����Х��ȥ����� + �إå�������			*/
			pcDcsPtr = malloc(lMsgSize + sizeof(TDcsMsgHed));
			os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_SYS_END, 2, pcDcsPtr, errno );

			if (NULL == pcDcsPtr)					/* ���������ݥ��󥿤�NULL�ξ��				*/
			{
													/* �㳲ȯ��									*/
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
					"os_MsgRcvEdit", "malloc() Call Error!!", errno, strerror(errno)));
				return(-1);							/* �۾ｪλ��sys work area exhaust��		*/
			} 

			ptDcsMsg = (TDcsMsgHed *)pcDcsPtr;		/* �ģãӥ�å������ݥ�������				*/

													/* ��å����������פ�����					*/
			ptDcsMsg->lMsgType	= htonl(D_MTYPEDCS_RL);

//			ptDcsMsg->lDataSize	= lMsgSize + 4;		/* ��å���������������������				*/
													// 20030330 ����
			ptDcsMsg->lDataSize	= lMsgSize;			/* ��å���������������������				*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lMsgType=%08x \n", "os_MsgRcvEdit",
					ptDcsMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lDataSize=%d \n", "os_MsgRcvEdit",
					ptDcsMsg->lDataSize));

//			memcpy((ptDcsMsg + 1), ptMsg, lMsgSize + 4);/* ����������å������򥳥ԡ�           */
														// 20030330 ����
			memcpy((ptDcsMsg + 1), ptMsg, lMsgSize);	/* ����������å������򥳥ԡ�           */

													/* �ס���Хåե����ɥ쥹��Ǽ��إ��ԡ�		*/
			*(long *)ptErdcp->pvArg1 = (long)pcDcsPtr; 

			lRcvRet = lMsgSize; 					/* �ֵ��ͤ˥�å���������������������		*/

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/* 						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->cReqClass = D_ERDC_REQCLASS00;	/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/
			break;

		default		:								/* ��λ��å�����							*/
			ptNonMsg = (TNonEndMsg *)ptMsg;			/* ��λ��å������ݥ�������				*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg=%08x \n", "os_MsgRcvEdit", ptNonMsg));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptNonMsg->lResult=%d \n",
					"os_MsgRcvEdit", ptNonMsg->lResult));
			DbgMsg01(DLv04, (OutPut, "***** %s:Erdcp->lReqNum=%d, Msg->lReqNum=%d \n",
					"os_MsgRcvEdit", ptErdcp->lReqNum, ptNonMsg->lReqNum));

			/********************************/
			/*  �ꥯ�������ֹ�Υ����å�	*/
			/********************************/
													/* ����rd�����ơ��֥�������Υꥯ�������ֹ� */
													/* �ȼ�����å������Υꥯ�������ֹ椬�԰���	*/
//			if (ptErdcp->lReqNum != ptNonMsg->lReqNum)
//			{
//				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "os_MsgRcvEdit",
//			 			 "�����۾�!!", "����������å��������˴�������ȥ饤���롣"));
//				return(-5);							/* ��ȥ饤������							*/
//			}

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
													/* ����rd����������λ�׵���֤�			*/
													/* 						��̤�׵�פ�����	*/
			ptErdcp->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;

													/* ����rd�������λ��Ѿ��֤��̤���ѡפ�����	*/
			ptErdcp->tReqStat.cUseStat = D_ERDC_USESTAT_NONE;

			ptErdcp->lReqNum = 0;					/* �ꥯ�������ֹ楯�ꥢ						*/

			ptErdcp->cReqClass = D_ERDC_REQCLASS00;	/* �׵���̥��ꥢ							*/

			ptErdcp->pvArg1 = (void *)NULL;			/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = (void *)NULL;			/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = (void *)NULL;			/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = (void *)NULL;			/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = (void *)NULL;			/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = (void *)NULL;			/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = (void *)NULL;			/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = (void *)NULL;			/* �����ΰ裸���ꥢ							*/

			lRcvRet = ptNonMsg->lResult;			/* ������å������Ρ֥ꥶ��ȡפ�����		*/
			break;
	}

 DbgMsg01( DLv04,( OutPut,"***** ptErdc->tMsgFlg.cMbPbOff :%02x\n", ptErdc->tMsgFlg.cMbPbOff));
 DbgMsg01( DLv04,( OutPut,"***** ptErdc->tMsgFlg.cPrcPbOff:%02x\n", ptErdc->tMsgFlg.cPrcPbOff));
 DbgMsg01( DLv04,( OutPut,"***** ptErdc->tMsgFlg.cMbPbOn  :%02x\n", ptErdc->tMsgFlg.cMbPbOn));
 DbgMsg01( DLv04,( OutPut,"***** ptErdc->tMsgFlg.cPrcPbOn :%02x\n", ptErdc->tMsgFlg.cPrcPbOn));
    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_MsgRcvEdit" ) );
	os_trcget2( D_MD_OS_MSGRCVEDIT, D_T_TRA_OUT, 1, lRcvRet );
	
	return (lRcvRet);								/* ���ｪλ									*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
