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
/* ��⥸�塼��ɣġ�				 os_initERDC												*/
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
/*	 os_initERDC	���ߡ��ؿ�																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initERDC.h>																*/
/*																								*/
/*	   	long	os_initERDC(TTblInfo *ptErdcTableAdr);											*/
/*																								*/
/* �㲾������																					*/
/*		TTblInfo *ptErdcTableAdr	rd��������γ�Ǽ���ɥ쥹									*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   os_initProcess��ǤΤ߻��Ѥ��롣															*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/

/************************************************************************************************/
/*								ɸ��إå����ե�����                  							*/
/*																								*/
/************************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initERDC(TTblInfo *ptErdcTableAdr)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TErdcTableInd *ptErdcTblInd = NULL;		// ERDC������
	TEprcTableInd *ptEprcTblInd = NULL;		// EPRC������
	long lKeyId;							// Key������ID(ntok)
	long lMemAccess;						// ���ѥ��ꥢ������������� D_SEM_ACCESS 0666
	char acRdShmKey[9];						// rd�����ơ��֥���¾�ѥ��ޥե�Key(ntok)
	char acSgKeyTemp[9];
	long lSemNum;							// ���ޥե������
	
	long lMaxReqNum;						// ���ץ��� �ꥯ�����ȼ��̻Һ���Ŀ���Ǽ��
	long lRes;
	long lTemp;
	long *plRes = NULL;
	long lCnt = 0;
	long lReqId = 0;							// �ꥯ�����ȼ��̻ҳ�Ǽ��
	int iShmId;
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initERDC\n" ) );
	
	/*	���������å�	*/
	if(NULL == ptErdcTableAdr)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  01:Err Mess:%s\n", strerror(errno)) );
		return( OSERRARG );						//rd��������γ�Ǽ���ɥ쥹����
	}
	
	/*--------------------------------------*/
	/*  SG�ɤ߹���                          */
	/*--------------------------------------*/
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߳���\n"));
	
	lKeyId = D_NTOK_ID;						/* ��ͭ����Key�ɤ߹���                */
	
	lMemAccess = D_SEM_ACCESS;					/* ���ѥ��ꥢ��������������ɤ߹���   */
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);		// ���ޥե�������ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾�
	}
	
	#ifdef USESEM
	// �����ѹ� SSLA0007 �ˤ��ҥץ����ǥ��ޥե��ϻ��Ѥ��ʤ�
	lRes = os_getSG(D_SG_ERDC_HAITA_SKEY,acSgKeyTemp);		// ERDC��¾�Ѥ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                      //�ӣ��ɹ��۾�
	}
	lRes = os_KeyGen(acSgKeyTemp, acRdShmKey);
//	DbgMsg01( DLv04, ( OutPut, "***** acRdShmKey : %s\n", acRdShmKey));
	#endif
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߽�λ\n"));
/****************************************/
/*	�ܽ���								*/
/****************************************/
	ptEprcTblInd = (TEprcTableInd *)(ptEsys->tMyPrcInfo.ptMyEPRC);
	lMaxReqNum = ptEprcTblInd->lMaxReqNum;	/*	�ꥯ�����ȼ��̻Һ���Ŀ���Ǽ */
//	DbgMsg01( DLv04, ( OutPut, "***** lMaxReqNum :%d\n", lMaxReqNum) );

	/*	rd��������Υ������˴������ȸ�����������Υ��������Ǽ����*/
	ptErdcTableAdr->lSize = sizeof(TErdcTable) + sizeof(TErdcTableInd) * lMaxReqNum;
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdcTableAdr->lSize :%d\n", ptErdcTableAdr->lSize) );
	
	/*	�ΰ�γ���	*/
	plRes = calloc((ptErdcTableAdr->lSize), sizeof(char));
	if(NULL == plRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  02:Err Mess:%s\n", strerror(errno)) );
		return( OSERRCALLOC );					//�ΰ���ݼ���
	}
	
	ptErdcTableAdr->pvAdr = (void *)plRes;		/*	���ɥ쥹�������Ƥ�	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdcTableAdr->pvAdr :%x\n", ptErdcTableAdr->pvAdr));
	
	#ifdef USESEM
	// �����ѹ� SSLA0007 �ˤ��ҥץ����ǥ��ޥե��ϻ��Ѥ��ʤ�
	/*	���ޥե�������	*/
	lRes = BlpMpf_ntok(acRdShmKey, lKeyId);
	if(-1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  03:Err Mess:%s\n", strerror(errno)) );
		return( OSERRNTOK );						//���ޥե�Key��������
	}
	
	lTemp = lRes;
	
	/*	���ޥե�ID�μ���	*/
	iShmId = semget(lTemp, lSemNum, lMemAccess | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  04:Err Mess:%s\n", strerror(errno)) );
		return( OSERRSEMGET );						//���ޥե��ɣļ�������
	}
	
	ptEsys->tMstERDC.lSemId = iShmId;				/*	ERDC���������󥻥ޥե�ID�˳�Ǽ	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsys->tMstERDC.lSemId :%x\n", ptEsys->tMstERDC.lSemId));
	
		// ���ޥե����������
	uSem.val = 1;								// uSem��oscom_ins������Ѥ�
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	//if(NORMAL != lRes)						// 20021225 ����
	if(-1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "*****  04-1:Err Mess:%s\n", strerror(errno)) );
		return(OSERRSEMCTL);					// 20021225 �ɲ�
	}
	
	#endif
	/*----------------------*/
	/*	����������ν����	*/
	/*----------------------*/
	
	/*	�����ΰ�ι�¤��	*/
	ptErdc = (TErdcTable *)(ptEsys->tMstERDC.pvAdr);
	
	strncpy(ptErdc->acTid, D_ERDC_TID, 4);		/*	�ΰ輱�̻���Ͽ	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc->acTid:%s\n", ptErdc->acTid));
	
	ptErdc->lMaxIndNum = lMaxReqNum;
//	DbgMsg01( DLv04, ( OutPut, "***** ptErdc->lMaxIndNum:%d\n", ptErdc->lMaxIndNum));
	
	/*----------------------*/
	/*	����������ν����	*/
	/*----------------------*/
	lTemp = lMaxReqNum;							/*	�ꥯ�����ȼ��̻Һ���Ŀ���Ǽ	*/
	ptErdcTblInd = (TErdcTableInd *)(ptErdc +1);/*	��������Ƭ���ɥ쥹��Ǽ	*/
	for(lCnt = 0;lCnt < lTemp;lCnt++)
	{
		lReqId = lCnt + 1;						/*	������������Ƥ���	*/
		(ptErdcTblInd + lCnt)->lRCode = lReqId;	/*	�ꥯ�����ȼ��̻ҳ�Ǽ	*/
//		DbgMsg01( DLv04, ( OutPut, "***** ptErdcTblInd[%d]->lRCode:%d\n", lCnt, (ptErdcTblInd + lCnt)->lRCode) );
	}
	
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initERDC\n" ) );
	return(NORMAL);
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
