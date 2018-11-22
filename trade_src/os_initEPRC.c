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
/* ��⥸�塼��̾��					 �ץ��������ơ��֥�ν����								*/
/* ��⥸�塼��ɣġ�				 os_initEPRC												*/
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
/*	 �ץ��������ơ��֥�γƹ��ܤν������Ԥ�													*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initEXXX_ins.h>															*/
/*																								*/
/*		long os_initEPRC(char *pcEprcTableAdr, long lPCode)										*/
/*																								*/
/* �㲾������																					*/
/*		char *pcEprcTableAdr	�ץ��������ơ��֥���Ƭ���ɥ쥹								*/
/*		long lPCode				�ץ������̻�													*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������	NORMAL																		*/
/*		�۾������	OSERRARG		�����۾�													*/
/*					OSERRSG			SG�ɹ��۾�													*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	os_initSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���														*/
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
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/*****	�ξ�����ֹ�TBCS0246���б�		Start							��������2003.07.28	*****/
#include <sys/time.h>
#include <sys/resource.h>
/*****	�ξ�����ֹ�TBCS0246���б�		 End							��������2003.07.28	*****/

/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initEPRC(char *pcEprcTableAdr, long lPCode)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TEprcTableInd *ptEprcInd;					/*	EPRC������				*/
	long lEPRCKbt = 0;							/*	EPRC��������			*/
	//moa ����
	char acPrcName[9];							/* �ץ���̾				*/
	long lLank = 0;								/* ��� 					*/
	long lMaxFileNum = 0;						/* �ե����뵭�һҺ���Ŀ�	*/
	long lUserIdCode = 0;						/* �桼�����̥�����			*/
	long lPAttr = 0;							/* �ץ���°��				*/
	long lAccess = 0;							/* ����������				*/
	long lPPriority = 0;						/* ��ư���ץ���ͥ����		*/
	long lModifPriority = 0;					/* �ѹ���ǽ�ǹ�ͥ����		*/
	long lLogicSpace = 0;						/* �������֤Υ�����			*/
	long lTimeSlice = 0;						/* �����ॹ�饤����			*/
	long lReqIdMax = 0;							/* �ꥯ�����ȼ��̻Һ���Ŀ�	*/
	
	long lRes = 0;								/*	�ֵ��ͳ�Ǽ��			*/
	long lCnt = 0;
	long lTemp = 0;
	
/****************************************/
/*	�������							*/
/****************************************/
	/*	�����γ�ǧ							*/
	DbgMsg01( DLv01, ( OutPut, "***** Start os_initEPRC\n" ) );
	
	if( 0 == pcEprcTableAdr )					//�ץ��������ơ��֥���Ƭ���ɥ쥹�۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		return( OSERRARG );						//�����۾���ֵ�
	}
	
	if( 0 == lPCode )							//�ץ������̻Ұ۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		return( OSERRARG );						//�����۾���ֵ�	
	}
	/*------------------------------*/
	/*	�����ΰ�ι�¤��			*/
	/*------------------------------*/
	
	/* ����������ι�¤��		*/
	ptEprcInd = NULL;
	ptEprc = (TEprcTable *)pcEprcTableAdr;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprc ���ɥ쥹:%lx\n", ptEprc ) );
	
	/*	��������������						*/
	ptEprcInd = (TEprcTableInd *) ( (long)ptEprc + sizeof(TEprcTable) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEprcInd %x\n", ptEprcInd ) );

	/****************************************/
	/*	SG���ɤ߹���						*/
	/****************************************/

	lRes = os_getSG(D_SG_EPRC_NUM,&lEPRCKbt);	// EPRC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_PRC_NAME,acPrcName);	// �ץ���̾�ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err02:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_LANK,&lLank);	// ����ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_FILE_ID_MAX,&lMaxFileNum);	// �ե����뵭�һҺ���Ŀ��ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err04:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_ID_CODE,&lUserIdCode);	// �桼�����̥������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err05:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_PRC_PAT,&lPAttr);	// �ץ���°���ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err06:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lAccess = D_SEM_ACCESS;                     // �����������ɤ߹���

	lRes = os_getSG(D_SG_MOA_PRC_USEN,&lPPriority);	// ��ư���ץ���ͥ�����ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err07:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_HENKO,&lModifPriority);	// �ѹ���ǽ�ǹ�ͥ�����ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err08:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_LOGI_SIZE,&lLogicSpace);	// �������֤Υ������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err09:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_TIME_SLI,&lTimeSlice);	// �����ॹ�饤�����ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err10:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_MOA_REQ_MAX,&lReqIdMax);	// �ꥯ�����ȼ��̻Һ���Ŀ��ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err11:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
/****************************************/
/*	�ܽ���								*/
/****************************************/

	strncpy( ptEprc->acTid, D_EPRC_TID, 4 );	/*	�ΰ輱�̻Ҥ�����		*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ΰ輱�̻�:%s\n", ptEprc->acTid ) );

	ptEprc->lIndPartNum = lEPRCKbt;				/*	��������������			*/
//	DbgMsg01( DLv04, ( OutPut, "***** ���������θĿ�:%ld\n", ptEprc->lIndPartNum ) );

	/*--------------------------------------*/
	/* ����������ν����                   */
	/*--------------------------------------*/
//	DbgMsg01( DLv04, ( OutPut, "***** moa���������\n"));
	
	ptEprcInd->lPCode = lPCode;					/* �ץ������̻ҳ�Ǽ			*/
//	DbgMsg01( DLv04, ( OutPut, "***** moa�ץ������̻�x :%lx\n", ptEprcInd->lPCode));
	
	ptEprcInd->cLaunchFlg = 'S';				/* Ω���夲���֤�"S"���Ǽ		*/
//	DbgMsg01( DLv04, ( OutPut, "***** Ω���夲����c :%c\n", ptEprcInd->cLaunchFlg));
	
//	strcpy(ptEprcInd->acPName, "moa");				// 20021218 ����
//	strncpy(ptEprcInd->acPName, "moa000  ", 8);		// 20030307 ����
	strncpy(ptEprcInd->acPName, acPrcName, 8);		/* �ץ���̾��moa���Ǽ		*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ץ���̾s :%s\n", ptEprcInd->acPName));
	
	ptEprcInd->lLank = lLank;					/* ��󥯤��Ǽ)				*/
//	DbgMsg01( DLv04, ( OutPut, "***** ���x :%lx\n", ptEprcInd->lLank));
	
													// 20030310 KL0028 �ɲ�
	if(D_ERR_SYS == lMaxFileNum)
	{
													// �ե����뵭�һҺ���Ŀ��ɤ߹���
		lRes = os_getSG(D_SG_EFLC_NUM,&lMaxFileNum);
		if(NORMAL != lRes)							//�ӣ��ɹ��۾�
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err12:%s\n", strerror(errno) ) );
			return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
		}
	}
	ptEprcInd->lMaxFileNum = lMaxFileNum;			/* �ե����뵭�һҺ���Ŀ���Ǽ	*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ե����뵭�һҺ���Ŀ�x :%lx\n", ptEprcInd->lMaxFileNum));
	
	ptEprcInd->lUid = lUserIdCode;					/* �桼�����̥����ɳ�Ǽ			*/
//	DbgMsg01( DLv04, ( OutPut, "***** �桼�����̥�����x :%lx\n", ptEprcInd->lUid));
	
	ptEprcInd->lPAttr = lPAttr;					/* �ץ���°����Ǽ				*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ץ���°��x :%lx\n", ptEprcInd->lPAttr));
	
	ptEprcInd->lAccess = lAccess;					/* ������������Ǽ				*/
//	DbgMsg01( DLv04, ( OutPut, "***** ����������o :%lo\n", ptEprcInd->lAccess));
	
	ptEprcInd->lPPriority = lPPriority;			/* ��ư���ץ���ͥ�踢��Ǽ		*/
//	DbgMsg01( DLv04, ( OutPut, "***** ��ư���ץ���ͥ�踢x :%lx\n", ptEprcInd->lPPriority));
	
	ptEprcInd->lModifPriority = lModifPriority;	/* �ѹ���ǽ�ǹ�ͥ���ٳ�Ǽ			*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ѹ���ǽ�ǹ�ͥ����x :%lx\n", ptEprcInd->lModifPriority));
	
													// 20030312 �ɲ�
	if(D_ERR_SYS == lLogicSpace)
	{
		lRes = os_getSG(D_SG_LOGI_SIZE,&lLogicSpace);	// �������֥������ɤ߹���
		if(NORMAL != lRes)							//�ӣ��ɹ��۾�
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err13:%s\n", strerror(errno) ) );
			return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
		}
	}
	ptEprcInd->lLogSpaceSize = lLogicSpace;		/* �������֥�������Ǽ			*/
//	DbgMsg01( DLv04, ( OutPut, "***** �������֥�����x :%lx\n", ptEprcInd->lLogSpaceSize));

													// 20030312 �ɲ�
	if( (D_ERR_SYS == lTimeSlice) || (0 == lTimeSlice) )
	{
		lRes = os_getSG(D_SG_TIME_SLI,&lTimeSlice);	// �����ॹ�饤�����ɤ߹���
		if(NORMAL != lRes)							//�ӣ��ɹ��۾�
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err14:%s\n", strerror(errno) ) );
			return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
		}
	}
	ptEprcInd->lTimeSlice = lTimeSlice;			/* �����ॹ�饤���ͳ�Ǽ			*/
//	DbgMsg01( DLv04, ( OutPut, "***** �����ॹ�饤����x :%lx\n", ptEprcInd->lTimeSlice));
	
													// 20030310 KL0028 �ɲ�
	if(D_ERR_SYS == lReqIdMax)
	{
		lRes = os_getSG(D_SG_ERDC_NUM,&lReqIdMax);	// �ꥯ�����ȼ��̻Һ���Ŀ��ɤ߹���
		if(NORMAL != lRes)							//�ӣ��ɹ��۾�
		{
			DbgMsg01( DLv05, ( OutPut, "***** GetSG Err15:%s\n", strerror(errno) ) );
			return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
		}
	}
	ptEprcInd->lMaxReqNum = lReqIdMax;				/* �ꥯ�����ȼ��̻Һ���Ŀ���Ǽ		*/
//	DbgMsg01( DLv04, ( OutPut, "***** �ꥯ�����ȼ��̻Һ���Ŀ�x :%lx\n", ptEprcInd->lMaxReqNum));
	
	ptEprcInd->lEndCode = D_END_CODE1;			/* ��λ�����ɽ�������� */
	ptEprcInd->lDetailCode = 0;					/* �ܺپ�������       */
	memset( &(ptEprcInd->func[0]), -1, 32 * sizeof(long) );	/* �㳰�ϥ�ɥ����� */
	
	/*----------------------------------*/
	/* moa�Υץ���ID�μ���            */
	/*----------------------------------*/
	lRes = (long)getpid();
	if(0 > lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		//getpid�ǰ۾�ϤϤʤ�
	}
	
	ptEprcInd->lPid = lRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd->lPid :%d\n", ptEprcInd->lPid));
	
	/*----------------------------------*/
	/* moa�Υ��롼��ID�μ���            */
	/*----------------------------------*/
	lRes = (long)getgid();
	if(0 > lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		//getgid�ǰ۾�ϤϤʤ�
	}
	
	ptEprcInd->lGid = lRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd->lGid :%d\n", ptEprcInd->lGid));

/*****	�ξ�����ֹ�TBCS0246���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	moa�ε�ư���ץ���ͥ���٤�����������ɲ�													*/
/************************************************************************************************/
	/*----------------------------------*/
	/* moa�ε�ư���ץ���ͥ���٤�����  */
	/*----------------------------------*/
	errno = 0;										// errno ���ꥢ

	os_trcget2( D_MD_OS_INITEPRC, D_T_SYS_SETPRIORITY, 3,
				PRIO_PROCESS, ptEprcInd->lPid, lPPriority );
													// moa�Υ������塼��󥰤�ͥ���٤�����
	lRes = setpriority(PRIO_PROCESS, ptEprcInd->lPid, lPPriority);
	os_trcget2( D_MD_OS_INITEPRC, D_T_SYS_END, 2, lRes, errno );

	DbgMsg01(DLv04, (OutPut, "***** os_initEPRC:lPPriority=%ld\n", lPPriority));
	DbgMsg01(DLv04, (OutPut, "***** os_initEPRC:setpriority() lRes=%ld, errno=%d\n", lRes, errno));
/*****	�ξ�����ֹ�TBCS0246���б�		 End							��������2003.07.28	*****/

	/*----------------------------------*/
	/* �ץ������̻Ҥν����           */
	/*----------------------------------*/
	
	lTemp = 0x00010002;
	
	for(lCnt = 1;lCnt < lEPRCKbt;lCnt++,lTemp++)
	{
		if(lPCode == lTemp)
		{
			(ptEprcInd + lCnt)->lPCode = 0x00010001;
		}
		else
		{
			(ptEprcInd + lCnt)->lPCode = lTemp;
		}
//		DbgMsg01( DLv04, ( OutPut, "***** ptEprcInd[%d]->lCode :%x\n",lCnt, (ptEprcInd + lCnt)->lPCode));
	}
	
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv01, ( OutPut, "***** End os_initEPRC\n" ) );
	return (NORMAL);
}
