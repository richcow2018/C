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
/* ��⥸�塼��ɣġ�				 os_MsgQDel													*/
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
/*	 ���ꤵ�줿���֥�å��������塼�Υǡ����������롣											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_MsgQDel.h>																*/
/*																								*/
/*	   	long	os_MsgQDel(TSubMsgQ ptSubMsgQ,TMsgInfo ptMsgInfo)								*/
/*																								*/
/* �㲾������																					*/
/*		TSubMsgQ    ptSubMsgQ;		 ���֥�å��������塼��������								*/
/*		TMsgInfo	ptmsgInfo;		 ������å���������											*/
/*																								*/
/* ���ֵ��͡�																					*/
/*	   ���ｪλ		NORMAL																		*/
/*	   �۾ｪλ		-1																			*/
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
#include	"os_MsgQDel_ins.h"


long	os_MsgQDel(ptSubMsgQ, ptMsgInfo)
TSubMsgQ    *ptSubMsgQ;								/* ���֥�å��������塼��������				*/
TMsgInfo    *ptMsgInfo;								/* ������å��������� 						*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long			lShmId;							/* ��ͭ����ɣ�							*/
	long			lRet;							/* �ֵ���									*/
	TMsgInfo		*tMsgNxt = NULL;				/* ������å������ʰ����ˤΥݥ���		*/
	TMsgInfo		*tMsgBef = NULL;				/* ������å������ʰ�����ˤΥݥ���		*/


	os_trcget2( D_MD_OS_MSGQDEL, D_T_TRA_IN, 2, ptSubMsgQ, ptMsgInfo );
													/* �ؿ�����									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s:Start DbgSubFnc\n", "os_MsgQDel" ) );


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	lShmId = 0;
	lRet = 0;
	errno = 0;

	tMsgNxt = (TMsgInfo *)ptMsgInfo->ptNxtAdr;		/* ������å������ʰ����ˤΥݥ�������	*/
	tMsgBef = (TMsgInfo *)ptMsgInfo->ptBefAdr;		/* ������å������ʰ�����ˤΥݥ�������	*/

	DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ = %08x \n", "os_MsgQDel", ptSubMsgQ));
	DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgInfo = %08x \n", "os_MsgQDel", ptMsgInfo));


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/********************************************/
	/*  �����ξ���ˤ���������ο�ʬ���򤹤�  */
	/********************************************/
	if (ptSubMsgQ->ptNxtAdr == ptSubMsgQ->ptBefAdr)	/* ����оݤμ�����å�������1�Ĥ����ξ��	*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "����оݤμ�����å�������1�Ĥ����ξ��"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt  = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId   = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lShmId));

		ptSubMsgQ->ptNxtAdr = NULL;					/* ���֥�å������μ����ɥ쥹��NULL������	*/
		ptSubMsgQ->ptBefAdr = NULL;					/* ���֥�å������������ɥ쥹��NULL������	*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* ���֥�å������Υ�å�������Ǽ�� -1		*/
		lShmId = ptSubMsgQ->lShmId;					/* ����оݤȤʤ붦ͭ����ɣĤ�����		*/
		ptSubMsgQ->lShmId = 0;						/* ���֥�å������ζ�ͭ����ɣĤ򥯥ꥢ	*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr = %08x \n", "os_MsgQDel",
				ptSubMsgQ->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt  = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId   = %08x \n", "os_MsgQDel",
				ptSubMsgQ->lShmId));
	}
	else if (ptSubMsgQ->ptNxtAdr == ptMsgInfo)		/* ����оݤμ�����å���������Ƭ�ξ��		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "����оݤμ�����å���������Ƭ�ξ��"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgNxt->ptBefAdr  =%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", tMsgNxt->ptBefAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId  =%d, ptMsgInfo->lShmId    =%d \n",
				"os_MsgQDel", ptSubMsgQ->lShmId, ptMsgInfo->lShmId));

													/* ���֥�å������μ����ɥ쥹��				*/
													/* ������å������μ����ɥ쥹������         */
		ptSubMsgQ->ptNxtAdr = (TMsgInfo *)ptMsgInfo->ptNxtAdr;
		tMsgNxt->ptBefAdr = ptMsgInfo->ptNxtAdr;	/* ������å������ΰ����������ɥ쥹��		*/
													/* ������å������μ����ɥ쥹������			*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* ���֥�å������Υ�å�������Ǽ�� -1		*/
		lShmId = ptSubMsgQ->lShmId;					/* ����оݤȤʤ붦ͭ����ɣĤ�����		*/
		ptSubMsgQ->lShmId = ptMsgInfo->lShmId;		/* ������å������ζ�ͭ����ɣĤ�			*/
													/* ���֥�å��������塼������				*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgNxt->ptBefAdr  =%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", tMsgNxt->ptBefAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lShmId  =%d, ptMsgInfo->lShmId    =%d \n",
				"os_MsgQDel", ptSubMsgQ->lShmId, ptMsgInfo->lShmId));
	}
	else if (ptSubMsgQ->ptBefAdr == ptMsgInfo)		/* ����оݤμ�����å��������Ǹ�ξ��		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "����оݤμ�����å��������Ǹ�ξ��"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->ptNxtAdr  =%08x \n",
				"os_MsgQDel", tMsgBef->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));

													/* ���֥�å������������ɥ쥹��				*/
													/* ������å������������ɥ쥹������         */
		ptSubMsgQ->ptBefAdr = (TMsgInfo *)ptMsgInfo->ptBefAdr;
		tMsgBef->ptNxtAdr = NULL;					/* ������å������ΰ����������ɥ쥹��		*/
													/* NULL������								*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* ���֥�å������Υ�å�������Ǽ�� -1		*/
		lShmId = tMsgBef->lShmId;					/* ����оݤȤʤ붦ͭ����ɣĤ�����		*/
		tMsgBef->lShmId = 0;						/* ������å������ΰ�����ζ�ͭ����ɣ�	*/
													/* �򥯥ꥢ									*/

		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->ptNxtAdr  =%08x \n",
				"os_MsgQDel", tMsgBef->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));
	}
	else											/* ����оݤμ�����å�����������ξ��		*/
	{
		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "����оݤμ�����å�����������ξ��"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));

		tMsgBef->ptNxtAdr = ptMsgInfo->ptNxtAdr;	/* ������å������ΰ����������ɥ쥹��		*/
													/* ������å������μ����ɥ쥹������			*/
		tMsgNxt->ptBefAdr = ptMsgInfo->ptBefAdr;	/* ������å������ΰ����������ɥ쥹��		*/
													/* ������å������������ɥ쥹������			*/
		ptSubMsgQ->lMsgCnt = ptSubMsgQ->lMsgCnt -1; /* ���֥�å������Υ�å�������Ǽ�� -1		*/
		lShmId = tMsgBef->lShmId;					/* ����оݤȤʤ붦ͭ����ɣĤ�����		*/
		tMsgBef->lShmId = ptMsgInfo->lShmId;		/* ������å������ΰ�����ζ�ͭ����ɣĤ� */
													/* ������å������ζ�ͭ����ɣĤ�����		*/

		DbgMsg01(DLv04, (OutPut, "***** %s:%s \n",
				"os_MsgQDel", "����оݤμ�����å�����������ξ��"));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptNxtAdr=%08x, ptMsgInfo->ptNxtAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptNxtAdr, ptMsgInfo->ptNxtAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->ptBefAdr=%08x, ptMsgInfo->ptBefAdr=%08x \n",
				"os_MsgQDel", ptSubMsgQ->ptBefAdr, ptMsgInfo->ptBefAdr));
		DbgMsg01(DLv04, (OutPut, "***** %s:ptSubMsgQ->lMsgCnt =%08x \n",
				"os_MsgQDel", ptSubMsgQ->lMsgCnt));
		DbgMsg01(DLv04, (OutPut, "***** %s:tMsgBef->lShmId    =%d \n",
				"os_MsgQDel", tMsgBef->lShmId));
	}


	/********************************************/
	/*  ��ͭ����Υǥ��å�					*/
	/********************************************/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_SHMDT, 1, ptMsgInfo );
	lRet = shmdt(ptMsgInfo);						/* ��ͭ����Υǥå���						*/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_END, 2, lRet, errno );

	if (-1 == lRet)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ptr=%08x, ERRNO:%08x  %s \n",
			"os_MsgQDel", "shmdt() Call Error!!", lShmId, ptMsgInfo, errno, strerror(errno)));
		return(-1);									/* �۾ｪλ									*/
	}


	/********************************************/
	/*  ��ͭ����κ��  						*/
	/********************************************/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_SHMCTL, 1, ptMsgInfo );
	lRet = shmctl(lShmId, IPC_RMID, 0);				/* ��ͭ������							*/
	os_trcget2( D_MD_OS_MSGQDEL, D_T_SYS_END, 2, lRet, errno );
	
	if (-1 == lRet)
	{
													/* �㳲ȯ��									*/
		DbgMsg01(DLv05, (OutPut, "***** %s:%s  lShmId=%#d, ERRNO:%08x  %s \n",
				"os_MsgQDel", "shmctl() Call Error!!", lShmId, errno, strerror(errno)));
		return(-1);								/* �۾ｪλ									*/
	}


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/
													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "os_MsgQDel" ) );
	os_trcget2( D_MD_OS_MSGQDEL, D_T_TRA_OUT, 0 );

	return (NORMAL);								/* ���ｪλ									*/
}


/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
