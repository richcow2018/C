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
/* ��⥸�塼��ɣġ�				 os_initEFLC												*/
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
/*	 �ե���������ơ��֥���ΰ���ݤ�����������˳��ݤ��ƽ������»ܤ���					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initEPRC.h>																*/
/*																								*/
/*	   	long	os_initEPRC(TTblPtc *ptEflcTableAdr)											*/
/*																								*/
/* �㲾������																					*/
/*		TTblPtc		*ptEflcTableAdr;		�ե���������ơ��֥���Ƭ���ɥ쥹					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������	NORMAL																		*/
/*		�۾������	̤����																		*/
/*																								*/
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
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initEFLC(TTblInfo *ptEflcTableAdr)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TEprcTableInd *ptEprcTemp = NULL;
	char acSgKeyname[9];						// ��¾��key ������ʸ����
	char acSgKeyTemp[9];
	long lSemAcc;								// ���ޥե��������������
	long lFlcKbt;								// EFLC������
	long lSgSemKey;								// ��ͭ����Key(ntok��)
	long lSemNum;								//���ޥե����������ꤹ�� 1
	long lMaxFileNum;							// �ե����뵭�һҺ���Ŀ�

	long *plRes;
	long lRes;									//�ֵ���
	int iShmId;
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_initEFLC\n" ) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr : %x\n", ptEflcTableAdr ) );
	
	if( NULL == ptEflcTableAdr )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRARG );			//�ե������������γ�Ǽ�ΰ襢�ɥ쥹����
	}
	
	/****************************************/
	/*	SG���ɤ߹���						*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߳���\n"));
	
	lSgSemKey = D_NTOK_ID;	// ��ͭ����Key�ɤ߹���
		
	lSemAcc = D_SEM_ACCESS;	// ���ꥢ������������ɤ߹���

												// 20030307 ���� KL0027
//	lRes = os_getSG(D_SG_EFLC_NUM,&lFlcKbt);	// EFLC�������ɤ߹���
//	if(NORMAL != lRes)
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
//		return( OSERRSG );			//�ӣ��ɹ��۾�
//	}

	#ifdef USESEM
	// �����ѹ� SSLA0007 �ˤ��ҥץ����ǥ��ޥե��ϻ��Ѥ��ʤ�
	lRes = os_getSG(D_SG_EFLC_HAITA_SKY,acSgKeyTemp);	// EFLC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** acSgKeyTemp : %s\n", acSgKeyTemp));
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );          //�ӣ��ɹ��۾�
	}
	lRes = os_KeyGen(acSgKeyTemp, acSgKeyname);
//	DbgMsg01( DLv04, ( OutPut, "***** acSgKeyname : %s\n", acSgKeyname));
	#endif
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);	// ���ޥե�������ɤ߹���
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );          //�ӣ��ɹ��۾�
	}
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߽�λ\n"));
	
									// ���ץ����������ݥ��󥿳�Ǽ
	ptEprcTemp = (TEprcTableInd *)(ptEsys->tMyPrcInfo.ptMyEPRC);
	lMaxFileNum = ptEprcTemp->lMaxFileNum;		// �ե����뵭�һҺ���Ŀ���Ǽ
//	DbgMsg01( DLv04, ( OutPut, "***** �ե����뵭�һҺ���Ŀ�:%d\n", lMaxFileNum));

/****************************************/
/*	�ܽ���								*/
/****************************************/

	/*	�ơ��֥륵�����λ���	*/
	ptEflcTableAdr->lSize = sizeof(TEflcTable) + sizeof(TEflcTableInd) * lMaxFileNum;
//	ptEflcTableAdr->lSize = sizeof(TEflcTable) + sizeof(TEflcTableInd) * lFlcKbt;
//	 DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->lSize : %d\n", ptEflcTableAdr->lSize) );
	 
	/*	�ΰ�γ���			*/
	plRes = calloc(ptEflcTableAdr->lSize, sizeof(char) );
	if( NULL == plRes )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 02:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRCALLOC );					//�ΰ���ݼ���
	}
	ptEflcTableAdr->pvAdr = (void *)plRes;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->pvAdr : %x\n", ptEflcTableAdr->pvAdr) );
	
	#ifdef USESEM
	// �����ѹ� SSLA0007 �ˤ��ҥץ����ǥ��ޥե��ϻ��Ѥ��ʤ�
	/*	���ޥե�key������	*/
	//�ٻ������󶡴ؿ�(ntok)��ȯ�Ԥ���
	lRes = BlpMpf_ntok(acSgKeyname, lSgSemKey);
	if ( -1 == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 03:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRNTOK );					//���ޥե�Key��������
	}
	
	/*	���ޥե�ID�μ���	*/
	iShmId = semget(lRes, lSemNum, lSemAcc | IPC_CREAT | IPC_EXCL );
	if(D_ERR_SYS == iShmId )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04:ErrMess:%s\n", strerror(errno) ) );
		return( OSERRSEMGET );					//���ޥե��ɣļ�������
	}
	ptEflcTableAdr->lSemId = iShmId;					// �ֵ��ͤ򥻥ޥե�ID�˳�Ǽ����
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflcTableAdr->lSemId : %d\n", ptEflcTableAdr->lSemId) );
	
	// ���ޥե����������
	uSem.val = 1;								// uSem��oscom_ins������Ѥ�
	
	lRes = semctl(iShmId, 0, SETVAL, uSem);
	//if(NORMAL != lRes)						// 20021225 ����
	if(D_ERR_SYS == lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04-1:ErrMess:%s\n", strerror(errno) ) );
		return(OSERRSEMCTL);					// 20021225 �ɲ�
	}
	
	#endif

	/****************************************/
	/*	�����������ν����					*/
	/****************************************/

	ptEflc = ptEflcTableAdr->pvAdr;				// ��Ƭ���ɥ쥹��ե���������ơ��֥�����������Ƥ�
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEflc : %x\n", ptEflc ) );
	
	strncpy( ptEflc->acTid, D_EFLC_TID, 4);			// EFLC�ΰ輱�̻Ҥ��Ǽ
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->acTid : %s\n", ptEflc->acTid ) );
	
	ptEflc->lMaxIndNum = lMaxFileNum;					// ���������˥ե����뵭�һҺ���Ŀ����Ǽ
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->lMaxIndNum : %d\n", ptEflc->lMaxIndNum ) );
	
	ptEflc->lEmpIndNum = lMaxFileNum;					// ���������˥ե����뵭�һҺ���Ŀ����Ǽ
//	DbgMsg01( DLv04, ( OutPut, "***** ptEflc->lEmpIndNum : %d\n", ptEflc->lEmpIndNum ) );
	
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initEFLC\n") );
	return(NORMAL);	
}
/************************************************************************************************/
/*	END																							*/
/************************************************************************************************/
