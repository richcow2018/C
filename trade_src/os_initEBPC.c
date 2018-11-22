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
/* ��⥸�塼��ɣġ�				 os_initEBPC												*/
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
/*		�Хåե��ס�������ơ��֥���ΰ���ݤ��ѥ�����˳��ݤ��ƽ������»ܤ���			*/
/*		�ס���Хåե���������ν������»ܤ���												*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initEBPC.h>																*/
/*																								*/
/*	   	long os_initEBPC(char *pcEbpcTableAdr)													*/
/*																								*/
/* �㲾������																					*/
/*		char	*pcEbpcTableAdr;		�ץ����ơ��֥�����ơ��֥����Υ��ɥ쥹				*/
/*																								*/
/* ���ֵ��͡�																					*/
/*	   	���ｪλ	NORMAL																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   os_initSystem��ǤΤ߻��Ѥ��롣															*/
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
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
/************************************************************************************************/
/*								���ѼԺ����إå����ե�����             							*/
/*																								*/
/************************************************************************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

/************************************************************************************************/
/*																								*/
/*	��ؿ�̾��	 os_iniEBPC.c																	*/
/*																								*/
/*	�㵡ǽ���ס� �Хåե��ס�������ơ��֥���ΰ���ݤ��ѥ�����˳��ݤ��ƽ������»ܤ���	*/
/*				 �ס���Хåե���������ν������»ܤ���										*/
/*																								*/
/************************************************************************************************/
long os_initEBPC(char *pcEbpcTableAdr)
{
	TEbpcTableInd *ptEbpcInd = NULL;			// �Хåե��ס�������ơ��֥����������
	
	/********************************************************************************************/
    /*  �ӣ��������ΰ�                          						 					*/
    /********************************************************************************************/
	long lEbpcKbt = 0;							// �Хåե��ס����������
	long lBpAdr = 0;							// �Хåե��ס����ΰ���Ƭ���ɥ쥹
	long lBpSize = 0;							// �Хåե��ס����ΰ襵����
	long lBpLMSize = 0;							// buffer�ס���LM�����
	long lKeyId = 0;							// Key������ID(ntok)
	long lMemAccess = 0;						// ���ѥ��ꥢ������������� D_SEM_ACCESS 0666
	long lLmId = 0;								// LM���������̻� ������[0]��
	long lCmId = 0;								// CM���������̻� ������[�Хåե��ס���LM��]��
	long lSemNum = 0;							// ���ޥե������
	char acGenKeyNum[9];						// �Хåե��ס����ΰ趦ͭ����Key(ntok)
	char acBpShmKey[9];							// �Хåե��ס����ΰ襻�ޥե�Key(ntok)
	char acPbShmKey[9];							// �ס���Хåե��ΰ���¾�ѥ��ޥե�Key�Ǿ���
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/	
	long *plShmAdr = NULL;						// ��ͭ������Ƭ���ɥ쥹
	long lMemkey = 0;						// ��ͭ����Key
	long lCnt = 0;								// �롼�ץ�����
	long lRes = 0;
	int iShmId;									// ��ͭ����ID�����
	
	DbgMsg01(DLv02, (OutPut, "***** Start os_initEBPC\n"));
	/********************************************************************************************/
	/*	 �������																				*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/*  �����γ�ǧ                  */
	/*------------------------------*/
	if(NULL == pcEbpcTableAdr)					/* ������NULL�λ��ϰ۾����             */
	{	
		DbgMsg01(DLv05, (OutPut, "***** %s 01:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRARG );						/*���Хåե������ơ��֥���Ƭ���ɥ쥹����*/
	}
	
	/*------------------------------*/
	/*  SG���ɤ߹���                */
	/*------------------------------*/

	lKeyId = D_NTOK_ID;						/* ��ͭ����Key�ɤ߹���                */
	
	lMemAccess = D_SEM_ACCESS;					/* ���ѥ��ꥢ��������������ɤ߹���   */
	
	lCmId = D_EBPC_CM_ID;
//	DbgMsg01( DLv04, ( OutPut, "***** lCmId :%08x\n", lCmId));
	
	lLmId = D_EBPC_LM_ID;
//	DbgMsg01( DLv04, ( OutPut, "***** lLmId :%08x\n", lLmId));

	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);	// EBPC���������ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}

	lRes = os_getSG(D_SG_EBPC_MAX_SIZE,&lBpSize);	// �Хåե��ס����ΰ襵�������ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}

	lRes = os_getSG(D_SG_EBPC_ADR,&lBpAdr);	// �Хåե��ס����ΰ���Ƭ���ɥ쥹�ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}

	lRes = os_getSG(D_SG_EBPC_LM_NUM,&lBpLMSize);	// �Хåե��ס���LM������ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}
//	DbgMsg01( DLv04, ( OutPut, "***** lBpLMSize:%d\n", lBpLMSize));

	lRes = os_getSG(D_SG_EBPC_GKEY,acGenKeyNum);	// Key����ʸ�����ɤ߹��� �Хåե��ס����ΰ趦ͭ����
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}
	
	lRes = os_getSG(D_SG_EBPC_FIL_SKEY,acBpShmKey);	// Key����ʸ�����ɤ߹��� �Хåե��ס����ΰ襻�ޥե�
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}

	lRes = os_getSG(D_SG_EBPC_PB_SKEY,acPbShmKey);	// Key����ʸ�����ɤ߹��� �ס���Хåե��ΰ���¾�ѥ��ޥե�
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);	// Key����ʸ�����ɤ߹��� �ס���Хåե��ΰ���¾�ѥ��ޥե�
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );							/*�ӣ��ɹ����ԡ�*/
	}

	/*------------------------------*/
	/*  �����ΰ�ι�¤��            */
	/*------------------------------*/
	// �֥Хåե��ס�������ơ��֥���Ƭ���ɥ쥹�פˡ֥Хåե��ס�������ơ��֥����������פ�������
	ptEbpc = (TEbpcTable*) pcEbpcTableAdr;		
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc: %x\n", ptEbpc));
	
	// ����������Ƭ���ɥ쥹���ᡢEMBC��������������Ƥ�
	ptEbpcInd = (TEbpcTableInd*) ( (long)ptEbpc + sizeof(TEbpcTable) );
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpcInd: %x\n", ptEbpcInd));

	/********************************************************************************************/
	/*	 �ܽ��� (����������ν����)															*/
	/*																							*/
	/********************************************************************************************/
	/*------------------------------*/
	/* �ͤ�����		                */
	/*------------------------------*/
	// �ΰ輱�̻Ҥ�EBPC���̻Ҥ����
	strncpy(ptEbpc->acTid, D_EBPC_TID, 4 );
	//DbgMsg01(DLv04, (OutPut, "***** EBPC�ΰ輱�̻�: %s\n", ptEbpc->acTid));
	
	ptEbpc->lShmKey = (long)acGenKeyNum;		// �Хåե��ס����ΰ趦ͭ����Key��Ǽ
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lShmKey: %lx\n", ptEbpc->lShmKey));
	
	// �Хåե��ס��륵������BP�ΰ襵�������Ǽ
	ptEbpc->lSize = lBpSize;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSize: %ld\n", ptEbpc->lSize));
	
	ptEbpc->lLmNum = lBpLMSize;					//  �Хåե��ס���LM�������Ǽ
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lLmNum: %ld\n", ptEbpc->lLmNum));
	
	//�Хåե��ס���������EBPC�����������Ǽ
	ptEbpc->lMaxNum = lEbpcKbt;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lMaxNum: %ld\n", ptEbpc->lMaxNum));

	/*------------------------------*/
	/* ���ѥ���key������          */
	/*------------------------------*/
	// ��ͭ����key������
	// �ٻ������󶡴ؿ�(ntok)��ȯ�Ԥ���	
	lMemkey = BlpMpf_ntok(acGenKeyNum, lKeyId);
	
	// �ֵ��ͤ�-1�ξ��ϥ��顼��å�����
	if(-1 == lMemkey)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 02:Err ess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRNTOK );						/*	��ͭ���ꥭ�������۾*/
	}
//	DbgMsg01(DLv04, (OutPut, "***** ntok lMemkey :%x\n", lMemkey));
	
	/*------------------------------*/
	/* ��ͭ����γ���             */
	/*------------------------------*/
	// �����ƥॳ���� (shmget) ��ȯ�Ԥ���
	iShmId = shmget(lMemkey, lBpSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)							// �ֵ��ͤ�-1�ξ��ϥ��顼��å�����
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 03:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSHMGET );						/*����ͭ������ݼ��ԡ�*/
	}
	
	// �ֵ��ͤ�ͭ����ID�˳�Ǽ
	ptEbpc->lShmId = iShmId;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lShmId :%lx\n", ptEbpc->lShmId));
	
	/*------------------------------*/
	/* ��ͭ��������             */
	/*------------------------------*/
	// �����ƥॳ���� (shmat) ��ȯ�Ԥ���

	if(0 == lBpAdr)
	{
		plShmAdr = shmat(iShmId, NULL, 0);
	}
	else
	{
		plShmAdr = shmat(iShmId, (void *)lBpAdr, SHM_RND);
	}
	// �ֵ��ͤ�-1�ξ��ϥ��顼��å�����		
	if(D_ERR_SYS == (long)plShmAdr)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 04:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSHMAT );							/*����ͭ�����ղð۾*/
	}
	
	// �Хåե��ס�����Ƭ���ɥ쥹�˳�Ǽ
	ptEbpc->pvAdr = (void*)plShmAdr;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr));
	
	/*------------------------------*/
	/* �Хåե��ס����ΰ�ν����   */
	/*------------------------------*/
	plShmAdr = memset((void *)(ptEbpc->pvAdr), 0, lBpSize);
	if(-1 == (long)plShmAdr)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 05:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRMEMSET );							/*����ͭ���������۾*/
	}
	
	/*------------------------------*/
	/* �ΰ���¾�ѥ��ޥե�Key����    */
	/*------------------------------*/
	lMemkey = BlpMpf_ntok(acBpShmKey,lKeyId);
	if(-1 == lMemkey)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 06:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRNTOK );							/*����¾�ѥ��ޥե�Key�������ԡ�*/
	}
//	DbgMsg01(DLv04, (OutPut, "***** lMemkey :%x\n", lMemkey));
	
	iShmId = semget(lMemkey, lSemNum, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iShmId)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return( OSERRSEMGET );							/*����¾�ѥ��ޥե��ɣļ������ԡ�*/
	}
	
	ptEbpc->lSemId = iShmId;
//	DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSemId :%d\n", iShmId) );
	
	// ���ޥե����������
	uSem.val = 1;								// uSem��oscom_ins������Ѥ�
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	if(NORMAL != lRes)
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 07-1:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
		return(OSERRSEMCTL);					// 20021226 �ɲ�
	}
	
	/*------------------------------*/
	/* ����������ν����           */
	/*------------------------------*/
//	DbgMsg01(DLv04, (OutPut, "***** �����������\n") );
//	DbgMsg01(DLv04, (OutPut, "***** lBpLMSize:%d\n", lBpLMSize));
	// �ס��뼱�̻Ҥ������EBPC�������˻��ꤹ��
	for(lCnt = 0; lCnt < lEbpcKbt ; lCnt++)
	{
		if(lCnt < lBpLMSize)
		{
			(ptEbpcInd + lCnt)->lPoolId = lLmId + lCnt;	// ������[0]��[LM��]
		}
		else
		{
			(ptEbpcInd + lCnt)->lPoolId = lCmId + (lCnt - lBpLMSize);	// ������[LM��]��[��������]
		}
//		DbgMsg01(DLv04, (OutPut, "***** (ptEbpcInd + %3d)->lPoolId : %08x\n", lCnt, (ptEbpcInd + lCnt)->lPoolId));
		/*------------------------------*/
		/* �ΰ���¾�ѥ��ޥե�Key����    */
		/*------------------------------*/
		lRes = strtol(acPbShmKey, NULL, 16);
		lRes = lRes + lCnt;
		sprintf(acPbShmKey,"%08lx", lRes);
		
		lMemkey = BlpMpf_ntok(acPbShmKey,lKeyId);
		if(-1 == lMemkey)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 08:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return( OSERRNTOK );						/*����¾�ѥ��ޥե�Key�������ԡ�*/
		}
		
//		DbgMsg01(DLv04, (OutPut, "***** lMemkey+%d :%x\n", lCnt, lMemkey));
		iShmId = semget(lMemkey, lSemNum, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
		if(-1 == iShmId)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return( OSERRSEMGET );						/*����¾�ѥ��ޥե��ɣļ������ԡ�*/
		}
		
		(ptEbpcInd + lCnt)->lSemId = iShmId;
//		DbgMsg01(DLv04, (OutPut, "***** ptEbpc->lSemId :%d\n", iShmId) );
		
			// ���ޥե����������
		uSem.val = 1;								// uSem��oscom_ins������Ѥ�
	
		lRes = semctl(iShmId, 0, SETVAL, uSem);
		if(NORMAL != lRes)
		{
			DbgMsg01(DLv05, (OutPut, "***** %s 07-1:Err Mess:%s\n", D_EBPC_TID, strerror(errno)));
			return(OSERRSEMCTL);					// 20021226 �ɲ�
		}
	}
	
	/********************************************************************************************/
	/*	 ��λ����																				*/
	/*																							*/
	/********************************************************************************************/
	DbgMsg01(DLv02, (OutPut, "***** End os_initEBPC\n"));
	return(NORMAL);
}
