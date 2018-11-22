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
/* ��⥸�塼��ɣġ�				 os_SubMsgQ													*/
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
/*      ���꡿������ꥶ��ȤΥ��֥�å��������塼�ν����򤹤롣                                */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long    os_SubMsgQ()                                                                    */
/*																								*/
/* �㲾������																					*/
/*      long            lMsgType                                                                */
/*      TMsgHed         *ptMsg                                                                  */
/*      TErdcTableInd   *ptErdcp                                                                */
/*      TEmbcTableInd   *ptEmbcp                                                                */
/*      TMsgInfo        *ptMsgInfo                                                              */
/*																								*/
/* ���ֵ��͡�																					*/
/*      NORMAL      ������                                                                      */
/*      -1          ��sys work area exhaust                                                     */
/*      -6          ��invalid buffer pool                                                       */
/*      -7          ��not pool buffer                                                           */
/*      -8          ��invalid pool buffer                                                       */
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
/*  ���󥯥롼�ɥե�����                                                                        */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/


/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	"os_SubMsgQ_ins.h"


long	os_SubMsgQ(lMsgType, ptMsg, ptErdcp, ptEmbcp, ptMsgInfo)
long			lMsgType;							/* ��å�����������							*/
TMsgHed			*ptMsg;								/* ��å��������Υݥ���					*/
TErdcTableInd	*ptErdcp;							/* �����������������ݥ���				*/
TEmbcTableInd	*ptEmbcp;							/* �����ᥤ��ܥå����������ݥ���			*/
TMsgInfo        *ptMsgInfo;							/* ��å���������ݥ���					*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lRcvPlBuf;						/* �����ס���Хåե����ɥ쥹				*/
	long			lBufPl;							/* �Хåե��ס��륢�ɥ쥹					*/
	long			lRcvRet;						/* ��̤��ֵ��͡ʼ����������ֵѡ�			*/
	long			lRet;							/* �ֵ���									*/
	long			*palPlList[2];					/* �ס���Хåե����ɥ쥹�ꥹ��				*/
	char			*pcWorkPtr   = NULL;			/* ����ݥ���							*/
	TPbInfo			*ptPbInfo    = NULL;			/* �ס���Хåե���������ݥ���			*/
	TEpbcTableInd	*ptEpbcp     = NULL;			/* ��˥åȴ�������ݥ���					*/
	TDcsMsgHed		*ptRcvDcsMsg = NULL;			/* �����ģãӥ�å������ݥ���				*/
	TDcsMsgHed		*ptDcsMsg    = NULL;			/* �ģãӥ�å������ѥݥ���				*/

	os_trcget2( D_MD_OS_SUBMSGQ, D_T_TRA_IN, 5, lMsgType, ptMsg, ptErdcp, ptEmbcp, ptMsgInfo );
													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_SubMsgQ" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lRcvPlBuf = 0;
	lBufPl    = 0;
	lRcvRet   = 0;
	lRet      = 0;
	errno     = 0;

	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType  = %02lx \n", "os_SubMsgQ", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg     = %08lx \n", "os_SubMsgQ", (long)ptMsg));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp   = %08lx \n", "os_SubMsgQ", (long)ptErdcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbcp   = %08lx \n", "os_SubMsgQ", (long)ptEmbcp));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgInfo = %08lx \n", "os_SubMsgQ", (long)ptMsgInfo));


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	switch (lMsgType)								/* ��å����������פǿ���ʬ��				*/
	{
		case	D_MTYPE05:							/* ��å������μ����׵�ʥᥤ��ܥå������� */
		case	D_MTYPE06:							/* ��å������μ����׵�ʥץ�������		*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_SubMsgQ",
					"�ץ����֥�å������ʥס���Хåե�̵����"));

			/********************************/
			/* ������å������Υ��ԡ�		*/
			/********************************/
													/* ��å�����Ĺ���¤�Ƚ��					*/
													/* ��å�����Ĺ����ͭ��						*/
			if (ptMsg->lDataSize > *(long *)ptErdcp->pvArg1)
			{
													/* ��å����������Хåե��˥��ԡ�			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), *(long *)ptErdcp->pvArg1); 
				lRcvRet = *(long *)ptErdcp->pvArg1; /* �ֵ��ͤ˼����ǡ���������������			*/
			}
			else									/* ��å�����Ĺ����̵��						*/
			{
													/* ��å����������Хåե��˥��ԡ�			*/
				memcpy(ptErdcp->pvArg2, (ptMsg + 1), ptMsg->lDataSize); 
				lRcvRet = ptMsg->lDataSize; 		/* �ֵ��ͤ˼����ǡ���������������			*/
			}

			/********************************/
			/* ��å�����Ĺ���¤Υ������ */
			/********************************/
			DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_SubMsgQ",
					ptErdcp->pvArg1));
			
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
			free(ptErdcp->pvArg1);					/* �������								*/
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0 );

			/********************************/
			/* �������ơ��֥���Խ�		*/
			/********************************/
/*			20030225 ����
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

			ptErdcp->pvArg1 = NULL;					/* �����ΰ裱���ꥢ							*/
			ptErdcp->pvArg2 = NULL;					/* �����ΰ裲���ꥢ							*/
			ptErdcp->pvArg3 = NULL;					/* �����ΰ裳���ꥢ							*/
			ptErdcp->pvArg4 = NULL;					/* �����ΰ裴���ꥢ							*/
			ptErdcp->pvArg5 = NULL;					/* �����ΰ裵���ꥢ							*/
			ptErdcp->pvArg6 = NULL;					/* �����ΰ裶���ꥢ							*/
			ptErdcp->pvArg7 = NULL;					/* �����ΰ裷���ꥢ							*/
			ptErdcp->pvArg8 = NULL;					/* �����ΰ裸���ꥢ							*/
			break;

		case	D_MTYPE07:							/* �ᥤ��ܥå������ס���Хåե�ͭ��		*/
		case	D_MTYPE08:							/* �ץ������ס���Хåե�ͭ��				*/

			DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "os_SubMsgQ",
					"�ץ����֥�å������ʥס���Хåե�ͭ���"));

			/********************************/
			/*  �����ס���Хåե����ɥ쥹  */
			/*  �Υ����������å�			*/
			/********************************/
			lRcvPlBuf = (long)ptMsg->pcPlBuf;		/* �����ס���Хåե����ɥ쥹����			*/
			lBufPl = (long)ptEbpc->pvAdr;			/* �Хåե��ס����������Ƭ���ɥ쥹����		*/
			lBufPl = lBufPl + ptEbpc->lSize;		/* �Хåե��ס��������������û�			*/

													/* �����ס���Хåե����ɥ쥹��				*/
			if (lRcvPlBuf > lBufPl)					/* �Хåե��ס���������ΰ��Ķ�ᤷ�����	*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  RcvPlBuf=%08x, BufPl=%08x \n",
				 				"os_SubMsgQ", "�����۾�!!", lRcvPlBuf, lBufPl));
				return(-6);							/* �۾ｪλ��invalid buffer pool��			*/
			}

			/********************************/
			/*  ������˥åȾ����			*/
			/*  ������ץ����ɣĥ����å�	*/
			/********************************/
													/* �ס���Хåե���������ݥ�������		*/
			ptPbInfo = (TPbInfo *)(ptMsg->pcPlBuf - 4);

			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo=%08x \n", "os_SubMsgQ", ptPbInfo));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptPbInfo->ptNxtAdr=%08x \n", "os_SubMsgQ",
					ptPbInfo->ptNxtAdr));

													/* ��˥åȴ�������ݥ�������				*/
			ptEpbcp = (TEpbcTableInd *)ptPbInfo->ptNxtAdr;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp=%08x \n", "os_SubMsgQ", ptEpbcp));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_SubMsgQ",
					ptEpbcp->lUsePid));

													/* ������ץ���ID���֡ݣ��װʳ��ξ��		*/
			if (D_EPBC_USEPID_SEND != ptEpbcp->lUsePid)
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  UsePid=%08x \n", "os_SubMsgQ",
						"�����۾�!!", ptEpbcp->lUsePid));
				return(-7);							/* �۾ｪλ��not pool buffer��				*/
			}
													/* �ּ��ץ���ID������						*/
			ptEpbcp->lUsePid = ptEsys->tMyPrcInfo.lMyPid;;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptEsys->tMyPrcInfo.lMyPid=%08x \n", "os_SubMsgQ",
					ptEsys->tMyPrcInfo.lMyPid));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptEpbcp->lUsePid=%08x \n", "os_SubMsgQ",
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
							"os_SubMsgQ", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* ��å����������Хåե��˥��ԡ�			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, *(long *)ptErdcp->pvArg1);
													/* ��������������							*/
					lRcvRet = *(long *)ptErdcp->pvArg1;
				}
				else								/* ��å�����Ĺ����̵��						*/
				{
					DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg->lDataSize=%d, ptErdcp->pvArg1=%d \n",
							"os_SubMsgQ", ptMsg->lDataSize, *(long *)ptErdcp->pvArg1));

													/* ��å����������Хåե��˥��ԡ�			*/
					memcpy(ptErdcp->pvArg2, ptMsg->pcPlBuf, ptMsg->lDataSize);
					lRcvRet = ptMsg->lDataSize;		/* ��������������							*/
				}

				/********************************/
				/* ��å�����Ĺ���¤Υ������ */
				/********************************/
				DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->pvArg1=%08x \n", "os_MsgRcvEdit",
						ptErdcp->pvArg1));
				
				os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptErdcp->pvArg1 );
				free(ptErdcp->pvArg1);				/* �������								*/
				os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0 );

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
					return(-8);						/* �۾ｪλ��invalid pool buffer��			*/
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
													/* ��å������׵᥯�ꥢ						*/
				if ((D_MTYPE07 == lMsgType) && (D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
				{
													/* �ᥤ��ܥå������ס���Хåե�̵�����ꥢ */
					ptErdc->tMsgFlg.cMbPbOff = D_ERDC_MSGFLG_OFF;
				}
				else if ((D_MTYPE08 == lMsgType) && (D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
				{
													/* �ץ������ס���Хåե�̵�����ꥢ		*/
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
			/********************************/
			/*  �ģãӥ�å��������Խ�		*/
			/********************************/
													/* �������								*/
													/* �����Х��ȥ����� + ���Х���				*/
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_FREE, 1, ptMsg->lDataSize + 8 );
			pcWorkPtr = malloc(ptMsg->lDataSize + 8+ 4);
			os_trcget2( D_MD_OS_SUBMSGQ, D_T_SYS_END, 0);
			
			if (NULL == pcWorkPtr)
			{
													/* �㳲ȯ��									*/
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
				"os_SubMsgQ", "shmdt() Call Error!!", errno, strerror(errno)));
				return(-1);							/* �۾ｪλ��sys work area exhaust��		*/
			} 

			ptRcvDcsMsg = (TDcsMsgHed *)ptMsg;		/* �����ģãӥ�å������ݥ�������			*/
			ptDcsMsg = (TDcsMsgHed *)pcWorkPtr;		/* �ģãӥ�å������ݥ�������				*/

													/* ��å����������פ�����					*/
			ptDcsMsg->lMsgType	= htonl(D_MTYPEDCS_RL);

													/* ��å���������������������               */
			ptDcsMsg->lDataSize	= ptRcvDcsMsg->lDataSize;

			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lMsgType      = %08x \n",
			"os_SubMsgQ", ptDcsMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptDcsMsg->lDataSize     = %08x \n",
			"os_SubMsgQ", ptDcsMsg->lDataSize));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp->lRCode         = %08x \n",
			"os_SubMsgQ", ptErdcp->lRCode));
			DbgMsg01(DLv04, (OutPut, "***** %s:(long *)ptErdcp->pvArg1 = %08x \n",
			"os_SubMsgQ", (long *)ptErdcp->pvArg1));

													/* ����������å������򥳥ԡ�				*/
			memcpy((ptDcsMsg + 1), (ptRcvDcsMsg + 1), ptRcvDcsMsg->lDataSize); 

													/* �ס���Хåե����ɥ쥹��Ǽ��إ��ԡ�		*/
			*(long *)ptErdcp->pvArg1 = (long)pcWorkPtr;

			lRcvRet = ptRcvDcsMsg->lDataSize; 		/* �ֵ��ͤ˼����ǡ���������������			*/

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

		default		:								/* ���⤷�ʤ�								*/
			break;
	}


	/********************************/
	/*  �����						*/
	/********************************/
													/* ���֥�å��������塼�������				*/
	lRet = os_MsgQDel(&ptEmbcp->tSubMsgQ, ptMsgInfo);
	if (-1 == lRet)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s \n",
				"os_SubMsgQ", "os_MsgQDel() Call Error!!  ��ͭ�������Ǽ���"));
		return(-1);									/* �۾ｪλ��sys work area exhaust��		*/
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_SubMsgQ" ) );
	os_trcget2( D_MD_OS_SUBMSGQ, D_T_TRA_OUT, 1, lRcvRet );
	
	return (lRcvRet);								/* ���ｪλ									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
