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
/* ��⥸�塼��̾��					 ���֥�å������ɲ�											*/
/* ��⥸�塼��ɣġ�				 os_MsgQIng													*/
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
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ������ꥶ��ȤǼ���������å������򥵥֥�å��������塼�إ��塼���󥰤���					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_MsgQing>																*/
/*																								*/
/*	   	long		os_MsgQing(long lMsgType, TMsgHed *ptMsg, TSubMsgQ *ptSubmsgQ)				*/
/*																								*/
/* �㲾������																					*/
/*		long		lMsgType;		 	��å�����������										*/
/*      long        lMsgSize                                                                    */
/*		TMsgHed		*ptMsg;		 		��å������ݥ���										*/
/*		TSubMsgQ    *ptSubMsgQ;         ���֥�å��������塼��������							*/
/* ���ֵ��͡�																					*/
/*	    ���ｪλ	NORMAL																		*/
/*		�۾ｪλ	-1																			*/
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
#include	"os_MsgQIng_ins.h"

long	os_MsgQIng(lMsgType, lMsgSize, ptMsg, ptSubMsgQ)
long		lMsgType;								/* ��å�����������							*/
long		lMsgSize;								/* ��å���������������						*/
TMsgHed		*ptMsg;									/* ��å������ݥ���						*/
TSubMsgQ    *ptSubMsgQ;								/* ���֥�å��������塼��������				*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	char			*pcCmptr     = NULL;			/* �����å����벾�ۥ��ɥ쥹�ݥ��� 		*/
	char			acSemKey[16];					/* SemKey��Ǽ���Ntok�ѡ�					*/
	char			acShmKey[16];					/* ShmKey��Ǽ���Ntok�ѡ�					*/
	long			lSemKey;						/* ���ޥե�Key ��Ǽ��						*/
	long			lSemId;							/* ���ޥե�ID  ��Ǽ��						*/
	long			lWorkShmKey;					/* ��ͭ����Key ��Ǽ�ʥ���ѡ�			*/
	long			lShmKey;						/* ��ͭ����Key ��Ǽ��						*/
	long 			lShmId;							/* ��ͭ����ID  ��Ǽ��						*/
	long			lCmSize;						/* ��ͭ���ꥵ����							*/
	long			lRet;							/* �ֵ���									*/
	TMsgInfo		*ptMsgBef    = NULL;			/* ������å������ʰ�����ˤΥݥ���		*/
	TMsgInfo		*ptCmMsgInfo = NULL;			/* ��å���������ʴ���������˶�ͭ������	*/
	TMsgHed			*ptCmMsg     = NULL;			/* ��ͭ�����ѥ�å������ݥ���			*/
	TDcsMsgHed		*ptCmDcsMsg  = NULL;			/* ��ͭ�����ѣģãӥ�å������ݥ���		*/
	struct sembuf	tSem;							/* ���ޥե���								*/

	os_trcget2( D_MD_OS_MSGQING, D_T_TRA_IN, 4, lMsgType, lMsgSize, ptMsg, ptSubMsgQ );
													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MsgQIng" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lSemKey     = 0;
	lSemId      = 0;
	lWorkShmKey = 0;
	lShmKey     = 0;
	lShmId      = 0;
	lCmSize     = 0;
	lRet        = 0;
	errno       = 0;


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgType =%02x \n", "os_MsgQIng", lMsgType));
	DbgMsg01(DLv04, (OutPut, "***** %s:lMsgSize =%d \n", "os_MsgQIng", lMsgSize));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsg    =%08x \n", "os_MsgQIng", ptMsg));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ=%08x \n", "os_MsgQIng", ptSubMsgQ));


	/********************************************/
	/*  �ᥤ��ܥå��������ơ��֥���������    */
	/*  �֥��ޥե��ɣġפΥ����å�				*/
	/********************************************/
	if (0 == ptEmbc->lSemId)						/* ���ޥե��ɣĤ���0�פξ��				*/
	{
													/* �ӣǤ���ǡ������������					*/
		lRet = os_getSG(D_SG_EMBC_SEM_KEY, acSemKey);
		//lRet = os_getSG(D_SG_EMBC_SKEY, acSemKey);	// 20030307 KL0027 ����
		if (-2 == lRet)								/* �ֵ��ͤ���-2�פξ��Ͻ�����λ			*/
		{
			return(-1);								/* �۾ｪλ									*/
		}

		/********************************************/
		/*  ntok�ؿ�������    						*/
		/********************************************/
		lSemKey = BlpMpf_ntok(acSemKey, D_NTOK_ID); /*  �ٻ����󶡴ؿ�(ntok)��ȯ��              */
		DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok() acSemKey=%s \n", "os_MsgQIng", acSemKey));
		DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok() lSemKey =%08lx\n", "os_MsgQIng", lSemKey));

		if (-1 == lSemKey)
		{
			return(-1);								/* �۾ｪλ									*/
		}

		/****************************************/
		/*  ���ޥե��ɣĤ����					*/
		/****************************************/
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMGET, 1, lSemKey );
		lSemId = semget(lSemKey, 1, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lSemId, errno );
		
		if (-1 == lSemId)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
					"os_MsgQIng", "semget() Call Error!!", errno, strerror(errno)));

			return(-1);								/* �۾ｪλ									*/
		} 

		ptEmbc->lSemId = lSemId;					/* �ᥤ��ܥå��������ơ��֥��				*/
													/* ���ޥե��ɣĤ�����						*/

    	DbgMsg01(DLv04, (OutPut, "***** %s:lSemId=%d, ptEmbc->lSemId=%d \n",
    			 "os_MsgQIng", lSemId, ptEmbc->lSemId));

		/****************************************/
		/*  ���ޥե��������                    */
		/****************************************/
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMCTL, 4, lSemId, 0, SETVAL, 1 );
    	if ((-1) == semctl(lSemId, 0, SETVAL, 1))	/* ���Υץ����Υ��ޥե��������ƥ��       */
                                                    /* �ǽ�Τ�ΤǤ��ä��Ȥ������ޥե��ֹ�     */
													/* ���֤ˡɣ��ɤ��ͤ򥻥åȤ���             */
		{
			DbgMsg01(DLv05, (OutPut, "***** %s:%s \n", "os_MsgQIng",
							"�������� Cannot set Semaphore-value."));
    	}
    	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 1, errno );
    }
	else
	{
		lSemId = ptEmbc->lSemId;					/* ���ޥե��ɣĤ����� 						*/

    	DbgMsg01(DLv04, (OutPut, "***** %s:lSemId=%d, ptEmbc->lSemId=%d \n",
    			 "os_MsgQIng", lSemId, ptEmbc->lSemId));
	}

	/************************************/
	/*  ��å����������פˤ�뿶ʬ��	*/
	/************************************/
	switch (lMsgType)								/* ��å����������פǿ���ʬ��				*/
	{
		case	D_MTYPE05:							/* ��å������μ����׵�ʥᥤ��ܥå�������	*/
		case	D_MTYPE06:							/* ��å������μ����׵�ʥץ�������		*/
			/********************************/
			/*  ��ͭ���ꥵ�����λ���		*/
			/********************************/
			/*  ��å����������������� �� �����إå������� + �����ǡ���������		*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TMsgHed) + ptMsg->lDataSize;
			break;

		case	D_MTYPE07:							/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ᥤ��ܥå�����)				*/
		case	D_MTYPE08:							/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ץ�����)						*/
			/********************************/
			/*  ��ͭ���ꥵ�����λ���		*/
			/********************************/
			/*  ��å����������������� �� �����إå�������							*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TMsgHed);
			break;

		case	D_MTYPE25:							/* DCS��å������μ����׵�					*/
			/********************************/
			/*  ��ͭ���ꥵ�����λ���		*/
			/********************************/
			/* ��å����������������� �� �����إå������� + ��å���������������	*/
			lCmSize = sizeof(TMsgInfo) + sizeof(TDcsMsgHed) + lMsgSize;
			break;

		default		:								/* ���⤷�ʤ�								*/
			break;
	}

	/****************************************/
	/* ��ͭ����ID�μ���  20030406�ɲý��� */
	/****************************************/
	lRet = os_Sem(lCmSize);
	if(D_ERR_SYS == lRet)
	{
		return(-1);
	}
	
	lShmId = lRet;

	/****************************************/
	/*  ��ͭ����Υ����å�				*/
	/****************************************/
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SHMAT, 3, lShmId, 0, 0);
	pcCmptr = (char *)shmat(lShmId, 0, 0);			/* ��ͭ����Υ��å���						*/
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, pcCmptr, errno);
	
	if (D_ERR_SYS == pcCmptr)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ERRNO:%08x  %s \n",
				"os_MsgQIng", "shmat() Call Error!!", lShmId, errno, strerror(errno)));
		return(-1);									/* �۾ｪλ									*/
	}

	ptCmMsgInfo = (TMsgInfo *)pcCmptr;				/* ��ͭ�����ѥ�å���������ݥ�������	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:pcCmptr=%08x, lCmSize=%d \n",
			"os_MsgQIng", pcCmptr, lCmSize));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsgInfo=%08x \n", "os_MsgQIng", ptCmMsgInfo));

   	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lShmKey=%08x\n", "os_MsgQIng", ptEmbc->lShmKey));

	/********************************************/
	/*  ��å�������������˥�å�����������    */
	/********************************************/
	switch (lMsgType)								/* ��å����������פǿ���ʬ��				*/
	{
		case	D_MTYPE05:							/* ��å������μ����׵�ʥᥤ��ܥå�������	*/
		case	D_MTYPE06:							/* ��å������μ����׵�ʥץ�������		*/

			ptCmMsg = (TMsgHed *)(ptCmMsgInfo + 1); /* ��ͭ�����å������ݥ�������			*/

			ptCmMsg->lMsgType = ptMsg->lMsgType;	/* ��å����������פ�����					*/

			ptCmMsg->pcPlBuf = ptMsg->pcPlBuf;		/* �ס���Хåե����ɥ쥹������				*/

			ptCmMsg->lDataSize = ptMsg->lDataSize;  /* �ǡ���������������						*/

													/* ������å��������å������ΰ�˥��ԡ�	*/
			memcpy((ptCmMsg + 1), (ptMsg + 1), ptMsg->lDataSize);

			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg=%08x\n", "os_MsgQIng", ptCmMsg));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lMsgType=%02x\n",
					"os_MsgQIng", ptCmMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->pcPlBuf=%08x\n",
					"os_MsgQIng", ptCmMsg->pcPlBuf));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lDataSize=%d\n",
					"os_MsgQIng", ptCmMsg->lDataSize));
			break;

		case	D_MTYPE07:							/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ᥤ��ܥå�����)				*/
		case	D_MTYPE08:							/* �ס���Хåե���Υ�å�������			*/
													/* �����׵�(�ץ�����)						*/

			ptCmMsg = (TMsgHed *)(ptCmMsgInfo + 1); /* ��ͭ�����å������ݥ�������			*/

			ptCmMsg->lMsgType = ptMsg->lMsgType;	/* ��å����������פ�����					*/

			ptCmMsg->pcPlBuf = ptMsg->pcPlBuf;		/* �ס���Хåե����ɥ쥹������				*/

			ptCmMsg->lDataSize = ptMsg->lDataSize;  /* �ǡ���������������						*/

			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg=%08x\n", "os_MsgQIng", ptCmMsg));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lMsgType=%02x\n",
					"os_MsgQIng", ptCmMsg->lMsgType));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->pcPlBuf=%08x\n",
					"os_MsgQIng", ptCmMsg->pcPlBuf));
			DbgMsg01(DLv04, (OutPut, "***** %s:ptCmMsg->lDataSize=%d\n",
					"os_MsgQIng", ptCmMsg->lDataSize));
			break;

		case	D_MTYPE25:							/* DCS��å������μ����׵�					*/

													/* ��ͭ����ģãӥ�å������ݥ�������	*/
			ptCmDcsMsg = (TDcsMsgHed *)(ptCmMsgInfo + 1);

			ptCmDcsMsg->lMsgType = lMsgType;		/* ��å����������פ�����					*/

			ptCmDcsMsg->lDataSize = lMsgSize;		/* ��å���������������������				*/

													/* ������å��������å������ΰ�˥��ԡ�	*/
			memcpy((ptCmDcsMsg + 1), ptMsg, lMsgSize);
			break;

		default		:								/* ���⤷�ʤ�								*/
			break;
	}

	if (0 == ptSubMsgQ->lMsgCnt)					/* ��å�������Ǽ������0�פξ��			*/
	{
		/********************************************/
		/*  ������å������ʴ������ˤ�����          */
		/********************************************/
		ptCmMsgInfo->ptBefAdr = (void *)ptSubMsgQ;	/* ������å������ʼ���������ͭ����ˤ�	*/
													/* �����ɥ쥹�˥��֥�å���������Ƭ���ɥ쥹 */
													/* ������									*/
													/* ��å������������ʥإå��ܥ�å�������	*/
		ptCmMsgInfo->lMsgSize = lCmSize - sizeof(TMsgInfo);
													/* ��å��������ɥ쥹������					*/
		ptCmMsgInfo->pvMsgAdr = (void *)(ptCmMsgInfo + 1);	

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->lMsgSize=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->lMsgSize));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->pvMsgAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->pvMsgAdr));


		/********************************************/
		/*  ���֥�å��������塼������				*/
		/********************************************/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt + 1;/* ���֥�å�������							*/
													/* ��å�������Ǽ���򥫥���ȥ��å�			*/

		ptSubMsgQ->lShmId = lShmId;					/* ���֥�å������ζ�ͭ����ɣĤ�			*/
													/* ����������ͭ����ɣĤ�����				*/

		ptSubMsgQ->ptNxtAdr = (TMsgInfo *)pcCmptr;	/* ���֥�å������μ����ɥ쥹��				*/
													/* ����������ͭ���ꥢ�ɥ쥹������			*/
		
		ptSubMsgQ->ptBefAdr = (TMsgInfo *)pcCmptr;	/* ���֥�å������������ɥ쥹��				*/
													/* ����������ͭ���ꥢ�ɥ쥹������			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->lMsgCnt=%d, ptSubMsgQ->lShmId=%d \n",
    			"os_MsgQIng", ptSubMsgQ->lMsgCnt, ptSubMsgQ->lShmId));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptNxtAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptNxtAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptBefAdr));
	}
	else											/* �嵭�ʳ���1�ʾ�ˤξ��					*/
	{
		/********************************************/
		/*  ������å������ʴ������ˤ�����          */
		/********************************************/
													/* ���֥�å������������ɥ쥹��				*/
													/* ������å������ʼ���������ͭ����ˤ�	*/
													/* �����ɥ쥹������							*/
		ptCmMsgInfo->ptBefAdr = (void *)ptSubMsgQ->ptBefAdr;	
													/* ��å������������ʥإå��ܥ�å�������	*/
		ptCmMsgInfo->lMsgSize = lCmSize - sizeof(TMsgInfo);
													/* ��å��������ɥ쥹������					*/
		ptCmMsgInfo->pvMsgAdr = (void *)(ptCmMsgInfo + 1);	

		ptMsgBef = ptSubMsgQ->ptBefAdr;				/* �������Υ��֥�å������������ɥ쥹������ */
		ptMsgBef->ptNxtAdr = (void *)pcCmptr;		/* �ʹ������˼�����å������μ����ɥ쥹��	*/
													/* ����������ͭ���ꥢ�ɥ쥹������			*/
		ptMsgBef->lShmId = lShmId;					/* �ʹ������˼�����å������ζ�ͭ����ɣ�	*/
													/* �˼���������ͭ����ɣĤ�����			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->lMsgSize=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->lMsgSize));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->pvMsgAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->pvMsgAdr));

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptCmMsgInfo->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptCmMsgInfo->ptBefAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptMsgBef=%08x, ptMsgBef->ptNxtAdr=%08x \n",
    			"os_MsgQIng", ptMsgBef, ptMsgBef->ptNxtAdr));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptMsgBef->lShmId=%08x \n",
    			"os_MsgQIng", ptMsgBef->lShmId));


		/********************************************/
		/*  ���֥�å��������塼������				*/
		/********************************************/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt + 1;/* ���֥�å�������							*/
													/* ��å�������Ǽ���򥫥���ȥ��å�			*/

		ptSubMsgQ->ptBefAdr = (TMsgInfo *)pcCmptr;	/* ���֥�å������������ɥ쥹��				*/
													/* ����������ͭ���ꥢ�ɥ쥹������			*/

    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->lMsgCnt=%d \n",
    			"os_MsgQIng", ptSubMsgQ->lMsgCnt));
    	DbgMsg01(DLv04,(OutPut,"***** %s:ptSubMsgQ->ptBefAdr=%08x \n",
    			"os_MsgQIng", ptSubMsgQ->ptBefAdr));
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_MsgQIng" ) );
	os_trcget2( D_MD_OS_MSGQING, D_T_TRA_OUT, 0 );

	return (NORMAL);								/* ���ｪλ									*/
}


/********************************************/
/*	��ͭ��������ؿ�						*/
/********************************************/
long os_Sem(long lCmSize)
{
	long lRes = 0;
	long lShmId = 0;
	long lFlg = 0;
	short sShmKey = 0;
	
	DbgMsg01(DLv04, (OutPut, "***** %s: Start os_Sem\n", "os_MsgQIng os_Sem" ));
	/****************************************/
	/*  ���ޥե���å�						*/
	/****************************************/
	lRes = os_SemLock(0);
	if(NORMAL != lRes)
	{
		return(lRes);
	}

	/****************************************/
	/*  ��ͭ����������					*/
	/****************************************/
	// �����ǽ������Ԥ��Ƥ��֤������ޥե�������Ƥ���ȴ����
	sShmKey = (short)(ptEmbc->lShmKey & 0x0000ffff);
	
	do
	{
		lFlg = 0;
		lRes = os_Shmget( &sShmKey, lCmSize );
		sShmKey++;
		
		if( ( (ptEmbc->lShmKey & 0x0000ffff) != ( (long)sShmKey & 0x0000ffff) ) &&
			( D_ERR_SYS == lRes ) )
		{
			lFlg = 1;
		}
	}while(lFlg);

													// ����ܥå��������ơ��֥���������
													// �ֶ�ͭ���꼱�̻ҡפ򥫥���ȥ��å�
	ptEmbc->lShmKey = (ptEmbc->lShmKey & 0xffff0000) | ( (long)sShmKey & 0x0000ffff);
	lShmId = lRes;
	
	/****************************************/
	/*  ���ޥե���å����					*/
	/****************************************/
	lRes = os_SemLock(1);
	if(NORMAL != lRes)
	{
		return(lRes);
	}

	if(D_ERR_SYS == lShmId)
	{
		return(-1);
	}

	DbgMsg01(DLv04, (OutPut, "***** %s: End os_Sem\n", "os_MsgQIng os_Sem" ));
	return(lShmId);
}

/********************************************/
/*	���ޥե����							*/
/********************************************/
long os_SemLock(long lFlg)
{
// lFlg 0�ʤ饻�ޥե���å�
// lFlg 1�ʤ��å����

	struct sembuf tSem;
	long lRet = 0;
	long lSemId = 0;
	
	/****************************************/
	/*  ���ޥե�����						*/
	/****************************************/
	lSemId = ptEmbc->lSemId;
													// ��������
	tSem.sem_num = (unsigned short)0;
/*****	�ξ�����ֹ�TBCS0234���б�		Start							��������2003.07.22	*****/
/************************************************************************************************/
/*	sem_flg��������SEM_UNDO�פ��ѹ�															*/
/************************************************************************************************/
	tSem.sem_flg = SEM_UNDO;						// ���ޥե������ե饰����
/*****	�ξ�����ֹ�TBCS0234���б�		 End							��������2003.07.22	*****/

	if(0 == lFlg)
	{	// ���ޥե���å�
		tSem.sem_op  = (short)(-1);
	}
	else
	{	// ���ޥե���å����
		tSem.sem_op  = (short)(1);
	}

	while (1)
	{
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SEMOP, 3, lSemId, &tSem, 1 );
		lRet = semop(lSemId, &tSem, 1);
		os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lRet, errno );

		if (D_ERR_SYS == lRet)
		{
			if (EINTR == errno)
			{										// ������ȯ������ȥ饤
				continue;
			}
			else
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:Err:%08lx %s\n",
									"os_MsgQing", errno, strerror(errno)));
				return(-1);
			}
		}
		break;
	}
	return(NORMAL);
}

/********************************************/
/*	��ͭ����ID����						*/
/********************************************/
long os_Shmget(short* spShmKey, long lCmSize)
{
	long lRet = 0;
	long lWorkShmKey = 0;							// SG������ͭ���꼱�̻�
	long lNtokShmKey = 0;
	long lShmKey = 0;
	long lShmId = 0;								// ��ͭ����ID��Ǽ��
	char acShmKey[16];								// ShmKey��Ǽ���Ntok�ѡ�
	
	DbgMsg01(DLv04, (OutPut, "***** %s: Start os_Shmget\n", "os_MsgQIng os_Shmget" ));
	DbgMsg01(DLv04, (OutPut, "***** %s:sShmKey:%x \n", "os_MsgQIng os_Shmget", *spShmKey ));
	DbgMsg01(DLv04, (OutPut, "***** %s:lCmSize:%ld\n", "os_MsgQIng os_Shmget", lCmSize ));
	/********************************************/
	/*  �ᥤ��ܥå��������ơ��֥���������    */
	/*  �ֶ�ͭ���꼱�̻ҡפΥ����å�			*/
	/********************************************/
	memset(acShmKey, 0, sizeof(acShmKey) );
	
	if (0 == *spShmKey)								// ��ͭ���꼱�̻Ҥ���0�פξ��
	{
													// �ӣǤ������
		lRet = os_getSG(D_SG_EMBC_SHM_KEY, &lWorkShmKey);
		if (NORMAL != lRet)
		{
			return(-1);								// �۾ｪλ
		}
		
		if(0 == ptEmbc->lShmKey)
		{
			ptEmbc->lShmKey = lWorkShmKey;			// ��ͭ���꼱�̻Ҥ�����
		}

		// �����ǰ����˥ޥ������Ƥ����
		*spShmKey = (short)( lWorkShmKey & 0x0000ffff);
		DbgMsg01(DLv04, (OutPut, "***** %s:sShmKey:%x\n", "os_MsgQIng", *spShmKey ));
		lNtokShmKey = ptEmbc->lShmKey;
	}
	lNtokShmKey = (ptEmbc->lShmKey & 0xffff0000) | ( (long)*spShmKey & 0x0000ffff);

	DbgMsg01(DLv04, (OutPut, "***** %s:ptEmbc->lShmKey:%08lx\n", "os_MsgQIng", ptEmbc->lShmKey ));
	DbgMsg01(DLv04, (OutPut, "***** %s:lNtokShmKey:%08lx\n", "os_MsgQIng", lNtokShmKey));
	/********************************************/
	/*  ntok�ؿ�������    						*/
	/********************************************/
													// ��ͭ���꼱�̻Ҥ�ʸ������Ѵ�
	sprintf(acShmKey, "%08lx", lNtokShmKey);

	lShmKey = BlpMpf_ntok(acShmKey, D_NTOK_ID);		// �ٻ����󶡴ؿ�(ntok)��ȯ��
	DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok acShmKey=%s \n", "os_MsgQIng", acShmKey));
	DbgMsg01(DLv04, (OutPut, "***** %s:BlpMpf_ntok lShmKey =%08lx \n", "os_MsgQIng", lShmKey));

	if (-1 == lShmKey)
	{
		return(-1);									// �۾ｪλ
	}
	
	/****************************************/
	/*  ��ͭ����γ���					*/
	/****************************************/
													//  ��ͭ�������
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_SHMGET, 2, lShmKey, lCmSize );
	lShmId = shmget(lShmKey, lCmSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	os_trcget2( D_MD_OS_MSGQING, D_T_SYS_END, 2, lShmId, errno);

	if (-1 == lShmId)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s:ERRNO:%08x %s\n",
				"os_MsgQIng", errno, strerror(errno)));
		return(-1);
	}

	DbgMsg01(DLv04, (OutPut, "***** %s:lShmKey=%08x, lShmId=%d \n",
			"os_MsgQIng", lShmKey, lShmId));
	return(lShmId);
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
