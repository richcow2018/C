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
/* �㥵���ӥ�����̾��				 ���Ͻ�����													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �������ʥץ�����ư����									*/
/* ��⥸�塼��ɣġ�				 os_initProcess												*/
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
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣӣ�����������	*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�ץ����������Ĥ������Ѥ򤹤�ơ��֥���ΰ���ݤ���ӽ������Ԥ���					*/
/*		�ΰ���ݤ���ӽ�����ˤϳƥơ��֥���б������ؿ���ƽФ����ȤǼ»ܤ��롣				*/
/*		�ƥơ��֥���б�����ؿ��Ǥ�ɬ�פʻ�(�ե�����ʤ�)�ν�����Ƚ���ͤ������»ܤ��롣	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	"os_initProcess.h"															*/
/*																								*/
/*		long os_initProcess(long lShmId, void *pvShmAdr, long lMBoxId )							*/
/*																								*/
/* �㲾������																					*/
/*		long	lShmId		�ơ��֥��Ǽ��ͭ����ID											*/
/*							(�����ƥ൯ư������������Ǽ���������ͭ����ID)					*/
/*		void	*pvShmAdr	�ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹								*/
/*		long	lMBoxId		�ᥤ��ܥå������̻�												*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������	NORMAL																		*/
/*		�۾������	�ʤ��ʥ��ܡ��ȡ�															*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   os_initSystem��AS���˥��������ǤΤ߻��Ѳ�ǽ�Ȥ��롣										*/
/*	   ���ͥ����������ơ��֥�ˤĤ��Ƥ������ؿ��Ǥν�����ϼ»ܤ��ʤ���osconn2 ��Ǽ»ܤ����	*/
/*     ��ΤȤ��롣â���������Ѥ��ΰ�ˤĤ��Ƥϥ����ƥ�ơ��֥�����ơ��֥���˳��ݤ����ΤȤ�	*/
/*	   �롣																						*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/

/******************************** ɸ��إå����ե����� ******************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initProcess.h"
#include "os_initProcess_ins.h"
#include "os_initEXXX_ins.h"
#include "osanyrl.h"

TEsysTable tEsys;									/* �����ƥ�����ơ��֥��ΰ�					*/


long os_initProcess(long lShmId, void *pvShmAdr, long lMBoxId  )
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long lRes = 0;									/* �ֵ��ͳ�Ǽ��								*/
	long lRda = 0;									/* �ꥯ�����ȼ��̻ҳ�Ǽ��					*/
	long lTblMemAdr = 0;							/* ��ͭ������Ƭ���ɥ쥹��Ǽ��(SG)			*/
	long lBpAdr = 0;								/* �Хåե��ס����ΰ���Ƭ���ɥ쥹��Ǽ��(SG)	*/
	long *plShmAdr = NULL;							/* ��ͭ������Ƭ���ɥ쥹					*/
	long *plKyAdr  = NULL;							/* ��ͭ������Ƭ���ɥ쥹					*/
	struct sigaction new[D_MAX_SIG_NUM];			/* �����ʥ�ϥ�ɥ��Ǽ��					*/
	int  iSigCnt = 0;								/* �����ʥ륫����							*/


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	/****************************************/
	/*  �㳰�ϥ�ɥ������					*/
	/****************************************/
													/* �롼�׽���								*/
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		switch(iSigCnt+1)							/* �����ʥ��ֹ�ǿ���ʬ��					*/
		{
			case SIGILL:                        	/* ������̿��								*/
			case SIGBUS:                        	/* �Х����顼								*/
			case SIGFPE:                        	/* ��ư�������㳰							*/
			case SIGSEGV:                       	/* �����ʥ��껲��							*/
//			case SIGPIPE:                       	/* �ѥ����˲�								*/
			case SIGTERM:                       	/* ��λ�����ʥ�								*/
			case 16:                            	/* ����										*/
													/* �����ʥ�ϥ�ɥ������					*/
				new[iSigCnt].sa_handler = os_sigact;
				break;

//			case SIGALRM:
//				new[iSigCnt].sa_handler = os_timex;
//				break;

			case SIGCHLD:							/* �ҥץ����ΰ�ö��� (stop) �ޤ��Ͻ�λ	*/
				if(NULL != pvShmAdr)				/* ��ͭ������Ƭ���ɥ쥹��NULL�ʳ��ξ��	*/
				{
													/* �����ʥ�ϥ�ɥ������					*/
					new[iSigCnt].sa_handler = os_gttrmcod;
					break;
				}

			default:								/* ����¾									*/
				new[iSigCnt].sa_handler = SIG_IGN;	/* �����ʥ�ϥ�ɥ������					*/
				break;
		}
		new[iSigCnt].sa_flags = 0;					/* �����ʥ�ե饰������						*/
													/* �����ʥ�����							*/
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}


	/****************************************/
	/*  �ǥХå�����						*/
	/****************************************/
	DbgInit( D_DEF, D_DEF, D_DEF );					/* �ǥХå��������							*/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initProcess\n") );

	if(NULL == pvShmAdr)							/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹��	*/
	{												/* NULL�ξ��								*/

		os_startSG();								/* �ӣǳ��Ͻ���								*/
													// 20030330
	    os_startTrace();							/* �ȥ졼�����Ͻ���							*/
	}

//  os_startTrace();                            	// 20030123
//	os_trcget2( D_MD_OS_INITPROCESS, D_T_TRA_IN, 3, lShmId, pvShmAdr, lMBoxId );

	ptEsys = &tEsys;								/* �����ƥ�����ơ��֥���Ƭ���ɥ쥹����		*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys:%x\n", ptEsys));


	/****************************************/
	/*  �����Υ����å�						*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** ���������å�\n"));
	
	if( 0 == lShmId )								/* �ơ��֥��Ǽ�Ѷ�ͭ���ꥨ�顼			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 01:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_PRA );
		//abort();
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lShmId :%x\n", lShmId ) );

	if( NULL == ptEsys )							/*�����ƥ�����ơ��֥���Ƭ���ɥ쥹���顼*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 02:Err Mess:%s\n", "initProccess", strerror(errno) ));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS );
		//abort();									/*	�۾����	*/
		
	}
//	DbgMsg01( DLv04, ( OutPut, "***** pvShmAdr :%x\n", pvShmAdr ) );

	if( 0 == lMBoxId )								/*	�ᥤ��ܥå������̻ҥ��顼	*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 03:Err Mess:%s\n", "initProccess", strerror(errno) ));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS1);
		//abort();
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lMBoxId :%x\n", lMBoxId ) );


	/****************************************/
	/*  �ӣǤμ���							*/
	/****************************************/
	lRes = os_getSG(D_SG_TABLE_ADR, &lTblMemAdr);	/* ��ͭ������Ƭ���ɥ쥹����				*/
	if(NORMAL != lRes)								/* �ӣ��ɹ�����								*/
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01%s\n", strerror(errno) ) );

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS2);
		//abort();									/*	�۾���� */

	}

	lRes = os_getSG(D_SG_EBPC_ADR, &lBpAdr);		/* �Хåե��ס����ΰ���Ƭ���ɥ쥹����		*/
	if(NORMAL != lRes)								/* �ӣ��ɹ�����								*/
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS3);
		//abort();									/*	�۾���� */

	}

    /********************************************************************************************/
    /*  �ܽ���                                                                                  */
    /********************************************************************************************/
	lRes = getpid();								/* ���ץ���ID��������						*/

	tEsys.tMyPrcInfo.lMyPid = lRes;					/* �����ƥ�����ơ��֥�μ��ץ����ɣ�����	*/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMyPrcInfo.lMyPid :%d\n", tEsys.tMyPrcInfo.lMyPid) );

	strncpy( tEsys.acTid, D_ESYS_TID,4);			/* �ΰ輱�̻Ҥ�����							*/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.acTid : %s\n", tEsys.acTid) );
//	DbgMsg01( DLv04, ( OutPut, "***** �����å� pvShmAdr:%x\n", pvShmAdr) );


	/****************************************/
	/*  TRADE�����ơ��֥���Ƭ���ɥ쥹������	*/
	/****************************************/
	if(NULL == pvShmAdr)							/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹��	*/
	{												/* NULL�ξ��								*/

		if(0 == lTblMemAdr)							/* ��ͭ������Ƭ���ɥ쥹��Ǽ��(SG)��		*/
		{											/* �֣��פξ��								*/

													/* ��ͭ����Υ����å��ʥ��ɥ쥹����ʤ���	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, lShmId, NULL, 0 );
			plKyAdr = shmat( lShmId, NULL, 0);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plKyAdr );
		}
		else										/* ��ͭ������Ƭ���ɥ쥹��Ǽ��(SG)��		*/
		{											/* �֣��ʳ��פξ��							*/

													/* ��ͭ����Υ����å��ʥ��ɥ쥹���ꤢ���	*/
			os_trcget2(D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, lShmId, (void *)lTblMemAdr, SHM_RND);
			plKyAdr = shmat( lShmId, (void *)lTblMemAdr, SHM_RND);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plKyAdr );
		}

		if( -1 == (long)plKyAdr)					/* ��ͭ����Υ����å��˼���				*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s 04:Err Mess:%s\n", "initProccess",
					strerror(errno) ) );

													/* ���ܡ���									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS4);
			//abort();
		}

//		DbgMsg01( DLv04, ( OutPut, "***** plKyAdr :%x\n", plKyAdr) );
		ptEtrd = (TEtrdTable *)plKyAdr;				/* TRADE�����ơ��֥���Ƭ���ɥ쥹��			*/
													/* ��ͭ������Ƭ���ɥ쥹�����ꤹ��			*/
	}
	else											/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹��	*/
	{												/* NULL�ξ��								*/

		ptEtrd = pvShmAdr;							/* TRADE�����ơ��֥���Ƭ���ɥ쥹��			*/
													/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹���� */
	}

//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd : %x\n",ptEtrd ) );


	/****************************************/
	/*	TRADE�ơ��֥��Ϣ���ܤ�����			*/
	/*	���Х��ɥ쥹�������Х��ɥ쥹�����*/
	/****************************************/
	/********************************/
	/*	EPRC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstEPRC.pvAdr  = (void *)( ptEtrd->tTrdEPRC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEPRC.lSize  = ptEtrd->tTrdEPRC.lSize;
	ptEsys->tMstEPRC.lSemId = ptEtrd->tTrdEPRC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.pvAdr  :%lx\n", ptEsys->tMstEPRC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.lSize  :%ld\n", ptEsys->tMstEPRC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPRC.lSemId :%ld\n", ptEsys->tMstEPRC.lSemId));

	/********************************/
	/*	EBPC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstEBPC.pvAdr = (void *)( ptEtrd->tTrdEBPC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEBPC.lSize  = ptEtrd->tTrdEBPC.lSize;
	ptEsys->tMstEBPC.lSemId = ptEtrd->tTrdEBPC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.pvAdr  :%lx\n", ptEsys->tMstEBPC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.lSize  :%ld\n", ptEsys->tMstEBPC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEBPC.lSemId :%ld\n", ptEsys->tMstEBPC.lSemId));

	/********************************/
	/*	ESBC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstESBP.pvAdr = (void *)( ptEtrd->tTrdESBP.lRAdr + (long)ptEtrd );
	ptEsys->tMstESBP.lSize  = ptEtrd->tTrdESBP.lSize;
	ptEsys->tMstESBP.lSemId = ptEtrd->tTrdESBP.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.pvAdr  :%lx\n", ptEsys->tMstESBP.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.lSize  :%ld\n", ptEsys->tMstESBP.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESBP.lSemId :%ld\n", ptEsys->tMstESBP.lSemId));

	/********************************/
	/*	EPBC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstEPBC.pvAdr = (void *)( ptEtrd->tTrdEPBC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEPBC.lSize  = ptEtrd->tTrdEPBC.lSize;
	ptEsys->tMstEPBC.lSemId = ptEtrd->tTrdEPBC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.pvAdr  :%lx\n", ptEsys->tMstEPBC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.lSize  :%ld\n", ptEsys->tMstEPBC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEPBC.lSemId :%ld\n", ptEsys->tMstEPBC.lSemId));

	/********************************/
	/*	EMMC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstEMMC.pvAdr = (void *)( ptEtrd->tTrdEMMC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEMMC.lSize  = ptEtrd->tTrdEMMC.lSize;
	ptEsys->tMstEMMC.lSemId = ptEtrd->tTrdEMMC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.pvAdr  :%lx\n", ptEsys->tMstEMMC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.lSize  :%ld\n", ptEsys->tMstEMMC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMMC.lSemId :%ld\n", ptEsys->tMstEMMC.lSemId));

	/********************************/
	/*	EMBC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstEMBC.pvAdr = (void *)( ptEtrd->tTrdEMBC.lRAdr + (long)ptEtrd );
	ptEsys->tMstEMBC.lSize  = ptEtrd->tTrdEMBC.lSize;
	ptEsys->tMstEMBC.lSemId = ptEtrd->tTrdEMBC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.pvAdr  :%lx\n", ptEsys->tMstEMBC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.lSize  :%ld\n", ptEsys->tMstEMBC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstEMBC.lSemId :%ld\n", ptEsys->tMstEMBC.lSemId));

	/********************************/
	/*	ESMC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstESMC.pvAdr = (void *)( ptEtrd->tTrdESMC.lRAdr + (long)ptEtrd );
	ptEsys->tMstESMC.lSize  = ptEtrd->tTrdESMC.lSize;
	ptEsys->tMstESMC.lSemId = ptEtrd->tTrdESMC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.pvAdr  :%lx\n", ptEsys->tMstESMC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.lSize  :%ld\n", ptEsys->tMstESMC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESMC.lSemId :%ld\n", ptEsys->tMstESMC.lSemId));

	/********************************/
	/*	ESGC���Х��ɥ쥹����		*/
	/********************************/
	ptEsys->tMstESGC.pvAdr = (void *)( ptEtrd->tTrdESGC.lRAdr + (long)ptEtrd );
	ptEsys->tMstESGC.lSize  = ptEtrd->tTrdESGC.lSize;
	ptEsys->tMstESGC.lSemId = ptEtrd->tTrdESGC.lSemId;

//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.pvAdr  :%lx\n", ptEsys->tMstESGC.pvAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.lSize  :%ld\n", ptEsys->tMstESGC.lSize));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstESGC.lSemId :%ld\n", ptEsys->tMstESGC.lSemId));


	/****************************************/
	/*	�ƥơ��֥�ν����					*/
	/****************************************/
	/********************************/
	/*	���ץ��������ơ��֥�����	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** os_MyEPRC\n"));
	lRes = os_MyEPRC();								/*	���ץ��������������					*/
	if(NORMAL != lRes)								/*	���ץ�����������������顼			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 05:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS5);
		//abort();
	}


	/********************************/
	/*	�ƥץ����إ����ʥ������	*/
	/********************************/
	if(NULL == pvShmAdr)							/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹��	*/
	{												/* NULL�ξ��								*/
//		os_startSG();
		DbgMsg01( DLv04, ( OutPut, "***** kill ȯ��\n"));

		lRes = kill(getppid(), SIGUSR1);			/* �ƥץ����˥����ʥ������				*/
		if(NORMAL != lRes)							/* �۾ｪλ�ξ��							*/
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s 06:Err Mess kill:%s\n", "initProccess",
					strerror(errno) ) );

													/* ���ܡ���									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS6);
		}
	}


	/********************************/
	/*	���ᥤ��ܥå��������ơ��֥�*/
	/*	�����						*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** lMBoxId :%x\n", lMBoxId));
	lRes = os_MyEMBC(lMBoxId);						/*	���ᥤ��ܥå��������������			*/
	if(NORMAL != lRes)								/*	���ᥤ��ܥå�����������������顼		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS7);
		//abort();
	}

	/********************************/
	/*	�ե���������ơ��֥�����	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstEFLC : %x\n", &(tEsys.tMstEFLC) ) );
	lRes = os_initEFLC( &(tEsys.tMstEFLC) );
	if ( NORMAL != lRes )							/* �ե���������ơ��֥�ν�������顼		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 08:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS8);
		//abort();
	}

	/********************************/
	/*	�������ơ��֥�����		*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstERDC : %x\n", &(tEsys.tMstERDC) ) );
	lRes = os_initERDC( &(tEsys.tMstERDC) );
	if ( NORMAL != lRes )							/* �ꥶ��ȴ����ơ��֥�ν�������顼		*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS9);
		//abort();
	}

	/********************************/
	/*	�����޴����ơ��֥�����	*/
	/********************************/
//	DbgMsg01( DLv04, ( OutPut, "***** tEsys.tMstETMC : %x\n", &(tEsys.tMstETMC) ) );
	lRes = os_initETMC( &(tEsys.tMstETMC) );
	if ( NORMAL != lRes )							/* �����޴����ơ��֥�ν�������顼			*/
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 10:Err Mess:%s\n", "initProccess", strerror(errno)));

													/* ���ܡ���									*/
		os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
		os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS10 );
		//abort();
	}

	/****************************************/
	/*	�ƥݥ��󥿤ν����					*/
	/****************************************/
	ptEprc = tEsys.tMstEPRC.pvAdr;					/* �ץ��������ơ��֥���Ƭ���ɥ쥹����		*/
	ptEbpc = tEsys.tMstEBPC.pvAdr;					/* �Хåե������ơ��֥���Ƭ���ɥ쥹����		*/
	ptEsbp = tEsys.tMstESBP.pvAdr;					/* �����Хåե��ס�������ơ��֥�			*/
													/* ��Ƭ���ɥ쥹����							*/
	ptEpbc = tEsys.tMstEPBC.pvAdr;					/* �ס���Хåե������ơ��֥�				*/
													/* ��Ƭ���ɥ쥹����							*/
	ptEmmc = tEsys.tMstEMMC.pvAdr;					/* ��å����������ơ��֥���Ƭ���ɥ쥹����	*/
	ptEmbc = tEsys.tMstEMBC.pvAdr;					/* �ᥤ��ܥå��������ơ��֥�				*/
													/* ��Ƭ���ɥ쥹����							*/
	ptEsmc = tEsys.tMstESMC.pvAdr;					/* ��ͭ��������ơ��֥���Ƭ���ɥ쥹����	*/
	ptEflc = tEsys.tMstEFLC.pvAdr;					/* �ե���������ơ��֥���Ƭ���ɥ쥹����		*/
	ptErdc = tEsys.tMstERDC.pvAdr;					/* �������ơ��֥���Ƭ���ɥ쥹����			*/
	ptEtmc = tEsys.tMstETMC.pvAdr;					/* �����޴����ơ��֥���Ƭ���ɥ쥹����		*/

	lMyPid = tEsys.tMyPrcInfo.lMyPid;				/* ���ץ���ID����							*/
													/* ���ץ�����������						*/
	ptMyEPRC = (TEprcTableInd *)(tEsys.tMyPrcInfo.ptMyEPRC);
													/* ���ᥤ��ܥå�����������					*/
	ptMyEMBC = (TEmbcTableInd *)(tEsys.tMyPrcInfo.ptMyEMBC);

//	DbgMsg01( DLv04, ( OutPut, "***** ptEprc:%x\n", ptEprc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpc:%x\n", ptEbpc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbp:%x\n", ptEsbp));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEpbc:%x\n", ptEpbc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmmc:%x\n", ptEmmc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmbc:%x\n", ptEmbc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsmc:%x\n", ptEsmc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc:%x\n", ptEflc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc:%x\n", ptErdc));
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtmc:%x\n", ptEtmc));
//	DbgMsg01( DLv04, ( OutPut, "***** lMyPid:%d\n", lMyPid));
//	DbgMsg01( DLv04, ( OutPut, "***** ptMyEPRC:%x\n", ptMyEPRC));
//	DbgMsg01( DLv04, ( OutPut, "***** ptMyEMBC:%x\n", ptMyEMBC));

//	�Хåե��ס�������ơ��֥����������Υ����
//	DbgDmp02( DLv04, ("ptEbpc", ptEbpc, sizeof(TEbpcTable),1,0));
//	DbgDmp01( DLv04, ("ptEbpc", ptEbpc, sizeof(TEbpcTable)));

//	�Хåե��ס�������ơ��֥����������Υ����
//	DbgDmp02( DLv04, ("ptEbpcp", (ptEbpc + 1), (sizeof(TEbpcTableInd) * 10),1,0));
//	DbgDmp01( DLv04, ("ptEbpcp", (ptEbpc + 1), (sizeof(TEbpcTableInd) * 10));

	/****************************************/
	/*	�Хåե��ס�����Ƭ���ɥ쥹������	*/
	/****************************************/
	if(NULL == pvShmAdr)							/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹��	*/
	{												/* NULL�ξ��								*/

		if(0 == lBpAdr)								/* �Хåե��ס����ΰ���Ƭ���ɥ쥹(SG)��		*/
		{											/* �֣��פξ��								*/

													/* ��ͭ����Υ����å��ʥ��ɥ쥹����ʤ���	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3, (int)(ptEbpc->lShmId), NULL, 0 );
			plShmAdr = shmat((int)(ptEbpc->lShmId), NULL, 0);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plShmAdr );
		}
		else										/* �Хåե��ס����ΰ���Ƭ���ɥ쥹(SG)��		*/
		{											/* �֣��ʳ��פξ��							*/

													/* ��ͭ����Υ����å��ʥ��ɥ쥹���ꤢ���	*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_SHMAT, 3,
						(int)(ptEbpc->lShmId), (void *)lBpAdr, SHM_RND );
			plShmAdr = shmat((int)(ptEbpc->lShmId), (void *)lBpAdr, SHM_RND);
			os_trcget2( D_MD_OS_INITPROCESS, D_T_SYS_END, 1, plShmAdr );
		}

		if(D_ERR_SYS == (long)plShmAdr)				/* �����å����۾ｪλ�ξ��					*/
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 11:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));

													/* ���ܡ���									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 0 );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS11 );
			//abort();							// 20021225 �ɲ�
		}

		ptEbpc->pvAdr = (void*)plShmAdr;			/* �Хåե��ס�����Ƭ���ɥ쥹����			*/
//		DbgMsg01(DLv04, (OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr));
	}

//	DbgDmp02( DLv04, ("ptMyEPRC�ʸ����������", ptMyEPRC, sizeof(TEprcTableInd), 1, 0));
//	DbgDmp02( DLv04, ("ptMyEmbc�ʸ����������", ptMyEMBC, sizeof(TEmbcTableInd), 1, 0));


	/****************************************/
	/*	�㳰�ϥ�ɥ������ʥ����ॢ���ȡ�	*/
	/****************************************/
	new[SIGALRM - 1].sa_handler = os_timex;			/* �����ʥ�ϥ�ɥ������					*/
	new[SIGALRM - 1].sa_flags = 0;					/* �����ʥ�ե饰������						*/
	sigaction(SIGALRM, &(new[SIGALRM - 1]), NULL);	/* �����ʥ�����							*/


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/

	/*****	�㳲�б���S00080��	Start									��������2003.05.13	*****/
	/********************************************************************************************/
	/*	�ץ����Ƶ�ư���Υ�å�����������������ɲ�											*/
	/********************************************************************************************/
	if(NULL == pvShmAdr)							/* �ҥץ����������Τ�						*/
	{
		lRes = os_SubMsgAtc();						/* ���֥�å������Υ����å�����				*/
		DbgMsg01(DLv04, (OutPut, "***** %s os_SubMsgAtc() lRes:%08lx\n", "os_initProcess", lRes));

		if (NORMAL != lRes)							/* �۾ｪλ�ξ��							*/
		{
													/* ���ܡ���									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 1, lRes );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS12 );
		}

		lRes = osanyrl(&lRda, 0);					/* ������ꥶ���							*/
													/* �ʥ�å������δ������Ԥ���			*/

													/* �ֵ��ͤ������ॢ���ȡ�����				*/
													/* ��å��������塼����ʳ��ξ��			*/
		if((OSEETOUT != lRes) && (OSEEDELD != lRes))
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 12:Err Mess:%s\n",
					"os_initProcess", strerror(errno) ));

													/* ���ܡ���									*/
			os_trcget2( D_MD_OS_INITPROCESS, D_T_ERR_SYS, 1, lRes );
			os_treterm( os_EndCod(D_END_TYPE1), (D_MD_OS_INITPROCESS << 16) | D_T_ERR_SYS13 );
		}
	}
	/*****	�㳲�б���S00080��	 End									��������2003.05.13	*****/

//	os_endSG();

	DbgMsg01( DLv02, ( OutPut, "***** End os_initProcess\n") );
	os_trcget2( D_MD_OS_INITPROCESS, D_T_TRA_OUT, 1, NORMAL );
	return (NORMAL);
}


/*****	�㳲�б���S00080��		Start									��������2003.05.13	*****/
/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��																					*/
/*		os_SubMsgAtc 																			*/
/*																								*/
/*	�㵡ǽ���ס�																				*/
/*		���ᥤ��ܥå��������ơ��֥�Υ��֥�å������򸡺������������륵�֥�å������������硢*/
/*		���֥�å��������Ф��ƶ�ͭ����Υ����å�������Ԥ���									*/
/*																								*/
/*	�ѥ�᡼��																					*/
/*		�ʤ�																					*/
/*																								*/
/*	�ֵ���																						*/
/*		NORMAL	: ���ｪλ																		*/
/*		-1 		: �۾ｪλ																		*/
/*																								*/
/************************************************************************************************/
long os_SubMsgAtc()
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	char 		*pcCmptr  = NULL;					/* �����å����벾�ۥ��ɥ쥹�ݥ��� 		*/
	TMsgInfo	*ptMsgNxt = NULL;					/* ����å���������ݥ���					*/


	/********************************************************************************************/
	/*  �ܽ���                                                                                  */
	/********************************************************************************************/
	os_trcget2(D_MD_OS_SUBMSGATC, D_T_TRA_IN, 0);
	DbgMsg01(DLv04, (OutPut, "\n***** %s: os_SubMsgAtc() Start \n", "os_SubMsgAtc"));


	/************************************/
	/*  ���֥�å���������				*/
	/************************************/
	while(1)
	{
													/* ������å������Υ��ɥ쥹�����å�			*/
		if (NULL == ptMyEMBC->tSubMsgQ.ptNxtAdr)	/* ���֥�å��������塼�μ����ɥ쥹��NULL	*/
		{
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMyEMBC->tSubMsgQ.ptNxtAdr=%08x\n",
					"os_SubMsgAtc", ptMyEMBC->tSubMsgQ.ptNxtAdr));

			break;									/* �롼�פ�ȴ����							*/
		}

		if (NULL == ptMsgNxt)						/* ����å���������ݥ��󥿤�NULL�ξ��		*/
		{
			/****************************************/
			/*  ��ͭ����Υ����å�				*/
			/****************************************/
													/* ��ͭ����Υ��å���						*/
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_SHMAT, 3, ptMyEMBC->tSubMsgQ.lShmId, 0, 0);
			pcCmptr = (char *)shmat(ptMyEMBC->tSubMsgQ.lShmId,ptMyEMBC->tSubMsgQ.ptNxtAdr,SHM_RND);
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_END, 2, pcCmptr, errno);

			if (D_ERR_SYS == pcCmptr)				/* �۾ｪλ�ξ��							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
						"os_SubMsgAtc", "shmat() Call Error!!", errno, strerror(errno)));
				return(-1);							/* �۾ｪλ									*/
			}

													/* ���֥�å��������塼�μ����ɥ쥹������	*/
			ptMsgNxt = ptMyEMBC->tSubMsgQ.ptNxtAdr;
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x \n", "os_SubMsgAtc", ptMsgNxt));
		}
		else
		{
			if (NULL == ptMsgNxt->ptNxtAdr)			/* ����å���������μ����ɥ쥹��NULL�ξ�� */
			{
				DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt->ptNxtAdr = %08x \n", "os_SubMsgAtc",
						ptMsgNxt->ptNxtAdr));

				break;								/* �롼�פ�ȴ����							*/
			}

			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMsgNxt=%08x\n", "os_SubMsgAtc", ptMsgNxt));
			DbgMsg01(DLv04, (OutPut, "\n***** %s:ptMsgNxt->lShmId=%08x\n", "os_SubMsgAtc",
					ptMsgNxt->lShmId));

			/****************************************/
			/*  ��ͭ����Υ����å�				*/
			/****************************************/
													/* ��ͭ����Υ��å���						*/
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_SHMAT, 3, ptMsgNxt->lShmId, 0, 0);
			pcCmptr = (char *)shmat(ptMsgNxt->lShmId, ptMsgNxt->ptNxtAdr, SHM_RND);
			os_trcget2( D_MD_OS_SUBMSGATC, D_T_SYS_END, 2, pcCmptr, errno);

			if (D_ERR_SYS == pcCmptr)				/* �۾ｪλ�ξ��							*/
			{
				DbgMsg01(DLv05, (OutPut, "***** %s:%s  ERRNO:%08x  %s \n",
						"os_SubMsgAtc", "shmat() Call Error!!", errno, strerror(errno)));
				return(-1);							/* �۾ｪλ									*/
			}

													/* ����å���������μ����ɥ쥹������		*/
			ptMsgNxt = (TMsgInfo *)ptMsgNxt->ptNxtAdr;
			DbgMsg01(DLv04, (OutPut, "***** %s:ptMsgNxt = %08x \n", "os_SubMsgAtc", ptMsgNxt));
		}
	}


	/********************************************************************************************/
	/*  ��λ����                                                                                */
	/********************************************************************************************/
	os_trcget2(D_MD_OS_SUBMSGATC, D_T_TRA_OUT, 1, NORMAL);
	DbgMsg01(DLv04, (OutPut, "\n***** %s: os_SubMsgAtc()  End  \n", "os_SubMsgAtc"));
	return(NORMAL);									/* ���ｪλ									*/
}
/*****	�㳲�б���S00080��		 End									��������2003.05.13	*****/
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
