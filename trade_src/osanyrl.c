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
/* ��⥸�塼��̾��					 ������ꥶ��Ȥμ���										*/
/* ��⥸�塼��ɣġ�				 osanyrl													*/
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
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���������λ�������׵�η�̤�������롣													*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osanyrl.h>																	*/
/*																								*/
/*	   	long	osanyrl(long *rda,long limit)													*/
/*																								*/
/* �㲾������																					*/
/*		long	*rda;																			*/
/*		long	limit																			*/
/*																								*/
/* ���ֵ��͡�																					*/
/*      �ꥶ���    ����λ�������׵�η��                                                    */
/*      OSEEACCV    �����ɥ쥹�۾郎ȯ������                                                    */
/*      OSEEILIM    �����»��֤��ͤ������Ǥ���                                                  */
/*      OSEEWKEX    �������ƥ��Ȱ褬���ݤǤ��ʤ�                                              */
/*      OSEEISIZ    ����å����������ΤȤ��˻��ꤷ�Ƥ��륵�����������Ǥ���                      */
/*      OSEENACC    �������������Ĥ��ʤ��ä�                                                    */
/*      OSEEDELD    ����å��������塼���������Ƥ���                                          */
/*      OSEETOUT    �����»�����˰�Ĥη�̤�夬�äƤ��ʤ��ä�                                */
/*      OSEEIPOL    ���Хåե��ס�����ΰ��Ķ�ᤷ��                                            */
/*      OSEENPOL    ��������Υס���Хåե��ʤ�                                                */
/*      OSEEIPLB    ���Хåե��ס��륢�ɥ쥹�ΰ۾�                                              */
/*      OSEEIVRD    ���׵���̤��ͤ������Ǥ���                                                  */
/*      OSEENREQ    ���ꥯ�����Ȥ���Ĥ�Ф���Ƥ��ʤ�                                          */
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
#include	"osanyrl.h"
#include	"osanyrl_ins.h"
#include	"os_MainMsgQ_ins.h"
#include	"os_SubMsgQ_ins.h"


long	osanyrl(rda, limit)
long	*rda;										/* �ꥯ�����ȼ��̻ҳ�Ǽ��					*/
long	limit;										/* ���»���									*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lMsgFlg;						/* ���֥�å�����Ƚ��ե饰					*/
													/* ��=1���ᥤ���å��������塼�ν���		*/
													/* ��=2�����֥�å��������塼�ν���			*/
	long			lMsgType;						/* ��å�����������							*/
	long			lCnt;							/* �롼�ץ�����							*/
	long			lRet;							/* �ֵ���									*/
	TErdcTableInd	*ptErdcp = NULL;				/* �������ơ��֥�������ݥ���			*/
	TEmbcTableInd	*ptMyEmbcp = NULL;				/* ���ץ����ᥤ��ܥå�����������ݥ��� */
	TMsgInfo		*ptMsgNxt = NULL;				/* ����å���������ݥ���					*/
	TMsgHed			*ptMsg = NULL;					/* ��å��������Υݥ���					*/


	os_trcget2( D_MD_OSANYRL, D_T_TRA_IN, 2, rda, limit );

													/* �ؿ�����									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "osanyrl" ) );

	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lMsgFlg  = 0;
	lMsgType = 0;
	lCnt     = 0;
	lRet     = 0;


	/************************************/
	/*  ���������å�					*/
	/************************************/
	if (0 == rda)									/* ��0�פξ��								*/
	{
		os_trcget2( D_MD_OSANYRL, D_T_ERR_PRA , 1, OSEEACCV );
		
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  rda=%08lx \n", "osanyrl",
				"�����۾�!!", "���ɥ쥹�۾", (long)rda));
		return(OSEEACCV);							/* �۾ｪλ�ʥ��ɥ쥹�۾��					*/
	}

	if (0 > limit)									/* ��0�װʲ��ξ��							*/
	{
		if (-1 > limit)								/* ��-1�װʲ��ξ�票�顼					*/
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s  limit=%ld \n", "osanyrl",
					"�����۾�!!", "�����λ���˸�꤬����ޤ���", limit));
			
			os_trcget2( D_MD_OSANYRL, D_T_ERR_PRA , 1, OSEEILIM );		
					
			return(OSEEILIM);						/* �۾ｪλ��invalid limit��				*/
		}
	}

	ptErdcp = (TErdcTableInd *)(ptErdc + 1);		/* ����������������Ƭ���ɥ쥹����			*/

													/* ���ץ����ᥤ��ܥå�������ݥ������� */
	ptMyEmbcp = (TEmbcTableInd *)ptEsys->tMyPrcInfo.ptMyEMBC;


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/************************************/
	/*  �������ơ��֥��������		*/
	/*  ��å������׵�ե饰�Υ����å�	*/
	/************************************/
													/* �ᥤ��ܥå������ס���Хåե�̵�� = OFF	*/
													/* �ᥤ��ܥå������ס���Хåե�ͭ�� = OFF */
													/* �ץ������ס���Хåե�̵�� = OFF		*/
													/* �ץ������ס���Хåե�ͭ�� = OFF		*/
	if ((D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cMbPbOff)  &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cMbPbOn)   &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cPrcPbOff) &&
		(D_ERDC_MSGFLG_OFF == ptErdc->tMsgFlg.cPrcPbOn))
	{
		// �ᥤ���å��������塼�ν�����
		lMsgFlg = 1;
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:&ptMyEmbcp->tSubMsgQ=%08x\n", "osanyrl",
			&ptMyEmbcp->tSubMsgQ));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%08x\n", "osanyrl",
			ptMyEmbcp->tSubMsgQ.ptNxtAdr));

    //  �ᥤ��ܥå��������ơ��֥����������Υ����
//	tol_dump("ptEmbc�ʴ����������", ptEmbc, sizeof(TEmbcTable), 1, 0);
	DbgDmp02( DLv04, ("ptEmbc�ʴ����������", ptEmbc, sizeof(TEmbcTable),1,0));

    //  �ᥤ��ܥå��������ơ��֥����������Υ����
//	tol_dump("ptMyEmbcp�ʸ����������", ptMyEmbcp, sizeof(TEmbcTableInd), 1, 0);
	DbgDmp02( DLv04, ("ptMyEmbcp�ʸ����������", ptMyEmbcp, sizeof(TEmbcTableInd),1,0));


	/************************************/
	/*  �����׵�Υ�å���������		*/
	/************************************/
	while(1)
	{
													/* ������å������Υ��ɥ쥹�����å�			*/
		if (NULL == ptMyEmbcp->tSubMsgQ.ptNxtAdr)	/* ���֥�å��������塼�μ����ɥ쥹��NULL	*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMyEmbcp->tSubMsgQ.ptNxtAdr=%08x\n", "osanyrl",
					ptMyEmbcp->tSubMsgQ.ptNxtAdr));

			lMsgFlg = 1;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}

		if (NULL == ptMsgNxt)						/* ����å���������ݥ��󥿤�NULL�ξ��		*/
		{
			ptMsgNxt = ptMyEmbcp->tSubMsgQ.ptNxtAdr;/* ���֥�å��������塼�μ����ɥ쥹������	*/
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* ������å������Υ��ɥ쥹������			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osanyrl",
					ptMsgNxt, ptMsg));
		}
		else
		{
			if (NULL == ptMsgNxt->ptNxtAdr)			/* ����å���������μ����ɥ쥹��NULL�ξ�� */
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt->ptNxtAdr = %08x \n", "osanyrl",
						ptMsgNxt->ptNxtAdr));

				lMsgFlg = 1;						/* ��å������ե饰�ˡ֣��פ�����			*/
				break;								/* �롼�פ�ȴ����							*/
			}
													/* ����å���������μ����ɥ쥹������		*/
			ptMsgNxt = (TMsgInfo *)ptMsgNxt->ptNxtAdr;
			ptMsg = (TMsgHed *)ptMsgNxt->pvMsgAdr;	/* ������å������Υ��ɥ쥹������			*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x, ptMsg = %08x \n", "osanyrl",
					ptMsgNxt, ptMsg));
		}

		/************************************/
		/*  ��å��������ƥ����å�			*/
		/************************************/
													/* ��å����������פ�rd�����ơ��֥�������� */
													/* ��å������׵�ե饰�����Ƥ����פ����� */

													/* ��å������μ����׵�ʥᥤ��ܥå�������	*/
		if ((D_MTYPE05 == ptMsg->lMsgType) &&
			(D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"��å������μ����׵�ʥᥤ��ܥå�������", ptMyEmbcp));

			lMsgFlg = 2;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}
													/* ��å������μ����׵�ʥץ�������		*/
		else if ((D_MTYPE06 == ptMsg->lMsgType) &&
				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"��å������μ����׵�ʥץ�������", ptMyEmbcp));

			lMsgFlg = 2;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}

		/***** �����ѹ���SSLA0001��	Start								��������2002.12.12	*****/
		/****************************************************************************************/
		/*  osrcvmsr�Ǥ���ס���Хåե���å������������б�									*/
		/****************************************************************************************/
													/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ᥤ��ܥå�����)				*/
//		else if ((D_MTYPE07 == ptMsg->lMsgType) &&
//				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
		else if ((D_MTYPE07 == ptMsg->lMsgType) &&
				 ((D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn) ||
				  (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOff)))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"�ס���Хåե���Υ�å������μ����׵�(�ᥤ��ܥå�����)", ptMyEmbcp));

			lMsgFlg = 2;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}
													/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ץ�����)						*/
//		else if ((D_MTYPE08 == ptMsg->lMsgType) &&
//				 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn))
		else if ((D_MTYPE08 == ptMsg->lMsgType) &&
				 ((D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOn) ||
				  (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cPrcPbOff)))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"�ס���Хåե���Υ�å������μ����׵�(�ץ�����)", ptMyEmbcp));

			lMsgFlg = 2;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}
		/***** �����ѹ���SSLA0001��	 End								��������2002.12.12	*****/

													/* DCS��å������μ����׵�					*/
		else if ((D_MTYPE25 == ptMsg->lMsgType) &&
			 	 (D_ERDC_MSGFLG_ON == ptErdc->tMsgFlg.cMbPbOn))
		{
			DbgMsg01(DLv04, (OutPut, "***** %s:%s ptMyEmbcp=%08x\n", "osanyrl",
					"DCS��å������μ����׵�", ptMyEmbcp));

			ptMsg->lMsgType = D_MTYPE25;			/* ������å������Υ�å����������פ�		*/
													/* �ᥤ��ܥå������ס���Хåե�ͭ������� */
			lMsgFlg = 2;							/* ��å������ե饰�ˡ֣��פ�����			*/
			break;									/* �롼�פ�ȴ����							*/
		}
	}


	/************************************/
	/*  ��å������ե饰��Ƚ��			*/
	/************************************/
	if (1 == lMsgFlg)								/* �ᥤ���å��������塼�ν���				*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n", "osanyrl", "�ᥤ���å��������塼�ν�����"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptErdcp=%08x \n", "osanyrl", ptErdcp));

		/************************************/
		/*  �ᥤ���å��������塼����		*/
		/************************************/
		lRet = os_MainMsgQ(limit, lMsgType, ptErdcp, rda, 1);

		switch (lRet)								/* �ֵ���Ƚ��								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "�����۾�!!", "�����ƥ��Ȱ�ν����Ǽ��ԡ�"));
			 		
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEWKEX );	
			 		
				return(OSEEWKEX);					/* �۾ｪλ��sys work area exhaust��		*/
				break;

			case	-2:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "�����۾�!!", "��å����������Υ���������θ�ꡣ"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEISIZ );	
			 			
				return(OSEEISIZ);					/* �۾ｪλ��invalid size��					*/
				break;

			case	-3:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "�����۾�!!", "�����������Ĥʤ���"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENACC );	
			 			
				return(OSEENACC);					/* �۾ｪλ��no access right��				*/
				break;

			case	-4:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "�����۾�!!", "��å��������塼���������Ƥ��롣"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEDELD );	
			 			
				return(OSEEDELD);					/* �۾ｪλ��deleted��						*/
				break;

			case	-5:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "�����۾�!!", "�����ॢ���ȡ�"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEETOUT );	 
				 		
				return(OSEETOUT);					/* �۾ｪλ��time out��						*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "�����۾�!!", "�Хåե��ס�����ΰ��Ķ�ᤷ����"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPOL );	
				 		
				return(OSEEIPOL);					/* �۾ｪλ��invalid buffer pool��			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "�����۾�!!", "������Υס���Хåե��ʤ���"));
			 	
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENPOL );			
			 			
				return(OSEENPOL);					/* �۾ｪλ��not pool buffer��				*/
				break;

			case	-8:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"�����۾�!!", "�Хåե��ס��륢�ɥ쥹�۾"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPLB );	
						
				return(OSEEIPLB);					/* �۾ｪλ��invalid pool buffer��			*/
				break;

			case	-9:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"�����۾�!!", "��������������ơ��֥�θ������Ϥ���ޤ���"));
				
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIVRD );			
						
				return(OSEEIVRD);					/* �۾ｪλ��invalid req descriptor��		*/
				break;

			case	-10:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"�����۾�!!", "�׵ᤵ�줿�ǡ���������ޤ���"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENREQ );	
						
				return(OSEENREQ);					/* �۾ｪλ��no request��					*/
				break;

			default		:
				// ���⤷�ʤ�
				break;
		}
	}
	else if (2 == lMsgFlg)							/* ���֥�å��������塼�ν���				*/
	{
		/************************************/
		/*  �������ơ��֥����������		*/
		/************************************/
													/* �롼�׽���								*/
		//for(lCnt = 0; lCnt < ptErdc->lMaxIndNum; lCnt++)
		for(lCnt = 0; lCnt < ptMyEPRC->lMaxReqNum; lCnt++)
		{
													/* ��å����������פ��׵���̤����פ������ */
			if (ptErdcp->cReqClass == ptMsg->lMsgType)
			{
				*rda = ptErdcp->lRCode;				/* �����������Υꥯ�����ȼ��̻Ҥ�����  		*/
				break;								/* �롼�פ�ȴ����							*/
			}
			/***** �����ѹ���SSLA0001��	Start							��������2002.12.12	*****/
			/************************************************************************************/
			/*  osrcvmsr�Ǥ���ס���Хåե���å������������б�								*/
			/************************************************************************************/
			else									/* ���פ��ʤ��ä����						*/
			{
													/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ᥤ��ܥå�����)	*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥᥤ��ܥå������� */
													/* �ξ��									*/
				if ((D_MTYPE07 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS05 ==ptErdcp->cReqClass))
				{
					break;							/* �������ơ��֥�������θ�����λ����	*/
				}
													/* �ס���Хåե���Υ�å�������			*/
													/* 				�����׵�(�ץ�����)		*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥץ������ˤξ�� */
				if ((D_MTYPE08 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS06 ==ptErdcp->cReqClass))
				{
					break;							/* �������ơ��֥�������θ�����λ����	*/
				}
													/* �ģãӥ�å������μ����׵�				*/
													/* ���ģ������ơ��֥���������׵���̤�	*/
													/* ��å������μ����׵�ʥᥤ��ܥå������� */
													/* �ξ��									*/
				if ((D_MTYPE25 == ptMsg->lMsgType) &&
					(D_ERDC_REQCLASS07 ==ptErdcp->cReqClass))
				{
					break;							/* �������ơ��֥�������θ�����λ����	*/
				}
			}
			/***** �����ѹ���SSLA0001��	 End							��������2002.12.12	*****/

			ptErdcp++;								/* �����ɥ쥹�إݥ��󥿤�ʤ��				*/
		}

		//if (lCnt >= ptErdc->lMaxIndNum)			/* �������ơ��֥�������κ����ͤ�Ķ��		*/
		if (lCnt >= ptMyEPRC->lMaxReqNum)
		{											/* �������ơ��֥�θ�������¸�ߤ��ʤ���� */
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osgtnrl",
					"�����۾�!!", "��������������ơ��֥�θ������Ϥ���ޤ���"));
					
			os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIVRD );	
					
			return(OSEEIVRD);						/* �۾ｪλ��invalid req descriptor��		*/
		}

		*rda = ptErdcp->lRCode;						/* �����������Υꥯ�����ȼ��̻Ҥ�����  		*/


		/************************************/
		/*  ���֥�å��������塼����		*/
		/************************************/
		lRet = os_SubMsgQ(ptMsg->lMsgType, ptMsg, ptErdcp, ptMyEmbcp, ptMsgNxt);

		switch (lRet)								/* �ֵ���Ƚ��								*/
		{
			case	-1:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 		"osanyrl", "�����۾�!!", "�����ƥ��Ȱ�ν����Ǽ��ԡ�"));
			 		
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEWKEX );	
			 		
				return(OSEEWKEX);					/* �۾ｪλ��sys work area exhaust��		*/
				break;

			case	-6:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
				 		"osanyrl", "�����۾�!!", "�Хåե��ס�����ΰ��Ķ�ᤷ����"));
				 		
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPOL );	
				 		
				return(OSEEIPOL);					/* �۾ｪλ��invalid buffer pool��			*/
				break;

			case	-7:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n",
			 			"osanyrl", "�����۾�!!", "������Υס���Хåե��ʤ���"));
			 			
			 	os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEENPOL );	
			 			
				return(OSEENPOL);					/* �۾ｪλ��not pool buffer��				*/
				break;

			case	-8:
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osanyrl",
						"�����۾�!!", "�Хåե��ס��륢�ɥ쥹�۾"));
						
				os_trcget2( D_MD_OSANYRL, D_T_ERR_SYS , 1, OSEEIPLB );	
						
				return(OSEEIPLB);					/* �۾ｪλ��invalid pool buffer��			*/
				break;

			default		:
				// ���⤷�ʤ�
				break;
		}
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
//	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osanyrl" ) );
	
	os_trcget2( D_MD_OSANYRL, D_T_TRA_OUT, 1, lRet );
	
	return (lRet);									/* ���ｪλ									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
