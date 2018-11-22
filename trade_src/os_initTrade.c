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
/* ��⥸�塼��ɣġ�				 os_initTrade												*/
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
/*	 TRADE�ơ��֥�����ơ��֥�γƹ��ܤν������Ԥ���											*/
/*	 �ƥơ��֥�����Х��ɥ쥹�򻻽Ф��Ƴ�Ǽ���롣�ޤ��ƥơ��֥�ؤν񤭹��߽��������Τ���		*/
/*   �Υ��ޥե��γ��ݤ�Ԥ������Υ��ޥե�ID���Ǽ���롣											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initTrade.h>															*/
/*																								*/
/*      long    os_initTrade(TEtrdTable *ptRtrdTableAdr)                                        */
/*																								*/
/* �㲾������																					*/
/*      TEtrdTable *ptEtrdTableAdr  TRADE�ơ��֥�����ơ��֥���Ƭ���ɥ쥹                       */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������	NORMAL																		*/
/*		�۾������	̤����																		*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*  os_initSystem�ؿ���ǤΤ߻��Ѥ���                                                           */
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initTrade(TEtrdTable *ptEtrdTableAdr)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lSemNum = 0;							// ���ޥե������
	long lSemAcc = 0;							// ���ޥե��������������
	long lEPRCKbt = 0;							// EPRC��������
	long lEBPCKbt = 0;							// EBPC��������
	long lESBPKbt = 0;							// ESBP��������
	long lEPBCKbt = 0;							// EPBC��������
	long lEMBCKbt = 0;							// EMBC��������
	long lEMMCKbt = 0;							// EMMC��������
	long lESMCKbt = 0;							// ESMC��������
	long lGenKey = 0;							// Key������ʸ����

	char acEPRCSemKey[9];						// EPRC���ޥե�Key
	char acEBPCSemKey[9];						// EBPC���ޥե�Key
	char acESBPSemKey[9];						// ESBP���ޥե�Key
	char acEPBCSemKey[9];						// EPBC���ޥե�Key
	char acEMBCSemKey[9];						// EMBC���ޥե�Key
	char acEMMCSemKey[9];						// EMMC���ޥե�Key
	char acESMCSemKey[9];						// ESMC���ޥե�Key
	
	long lCnt = 0;								// �������ѿ�
	long lSemId = 0;							// ���ޥե�ID��
	long lSemKey = 0;							// ���ޥե�Key��
	long lEtrdSize = 0;							// TRADE�ơ��֥륵������
	long lTblNum = 0;							// patTable��������Ǽ��
	long lRes = 0;								// �ֵ��ͳ�Ǽ��
	long lTemp = 0;
	
	long *patTable[] = {						// �����������Ǽ������
		&(ptEtrdTableAdr->tTrdEPRC.lSemId),
		&(ptEtrdTableAdr->tTrdEBPC.lSemId),
		&(ptEtrdTableAdr->tTrdESBP.lSemId),
		&(ptEtrdTableAdr->tTrdEPBC.lSemId),
		&(ptEtrdTableAdr->tTrdEMMC.lSemId),
		&(ptEtrdTableAdr->tTrdEMBC.lSemId),
		&(ptEtrdTableAdr->tTrdESMC.lSemId)
	};

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initTrade\n" ) );
/************************************/
/*	�������						*/
/************************************/
	/*�����Υ����å�*/
	if( 0 == ptEtrdTableAdr)				//�ԣң��ģťơ��֥�����ơ��֥륢�ɥ쥹�۾�			
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 01:Err Mess:%s\n", "initTrade", strerror(errno) ) );
		return( OSERRARG );					//�����۾���ֵ�
	}

	/************************************/
	/*	SG�ͤ��ɤ߹���					*/
	/************************************/
	
	lSemAcc = D_SEM_ACCESS;		// ���ޥե���������������ɤ߹���

	lGenKey = D_NTOK_ID;		// ��ͭKey�ɤ߹���
	
	lRes = os_getSG(D_SG_SEM_NUM,&lSemNum);		// ���ޥե�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}

	lRes = os_getSG(D_SG_EPRC_NUM,&lEPRCKbt);	// EPRC���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEBPCKbt);	// EBPC���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lESBPKbt);	// ESBP���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EPBC_NUM,&lEPBCKbt);	// EPBC���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EMBC_NUM,&lEMBCKbt);	// EMBC���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
												// 20030307 ���� KL0027
//	lRes = os_getSG(D_SG_EMMC_NUM,&lEMMCKbt);	// EMMC���������ɤ߹���
//	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
//		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
//	}
	
	lRes = os_getSG(D_SG_ESMC_NUM,&lESMCKbt);	// ESMC���������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EPRC_SKEY,acEPRCSemKey);		// EPRC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EPRC_SKEY:%s\n",acEPRCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EBPC_SKEY,acEBPCSemKey);		// EBPC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EBPC_SKEY:%s\n",acEBPCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_ESBP_SKEY,acESBPSemKey);		// ESBP����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_ESBP_SKEY:%s\n",acESBPSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EPBC_SKEY,acEPBCSemKey);		// EPBC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EPBC_SKEY:%s\n",acEPBCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EMBC_SKEY,acEMBCSemKey);		// EMBC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EMBC_SKEY:%s\n",acEMBCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EMMC_SKEY,acEMMCSemKey);		// EMMC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_EMMC_SKEY:%s\n",acEMMCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_ESMC_SKEY,acESMCSemKey);		// ESMC����ʸ�����ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG_ESMC_SKEY:%s\n",acESMCSemKey) );
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}

	ptEtrd = ptEtrdTableAdr;					/*	����ptEtrdTableAdr�˹�¤�Τ������Ƥ�	*/
//	DbgMsg01( DLv02, ( OutPut, "***** Addr ptEtrd : %x\n", ptEtrd ) );
	lTblNum = 0;
	lTblNum = sizeof(patTable) / sizeof(patTable[0]);	/*	patTable�Υ����������	*/

/************************************/
/*	�ܽ���							*/
/************************************/
	strncpy(ptEtrd->acTid,D_ETRD_TID, 4 );		/*	ETRD���̻Ҥ��Ǽ					*/
//	DbgMsg01( DLv02, ( OutPut, "***** ETRD�ΰ輱�̻� : %4c\n", ptEtrd->acTid ) );

	/************************************************/
	/*	�ơ��֥�Υ���������ƹ��ܤ˳�Ǽ����		*/
	/************************************************/
	
	/*	TRADE�ơ��֥�����ơ��֥륵��������		*/
//	DbgMsg01( DLv04, ( OutPut, "***** TRADE�ơ��֥�����ơ��֥륵��������\n") );
	
	lEtrdSize = sizeof(TEtrdTable);
//	DbgMsg01( DLv04, ( OutPut, "***** lEtrdSize:%ld\n", lEtrdSize ) );
		
	/*	�ץ��������ơ��֥륵����				*/
	ptEtrd->tTrdEPRC.lSize = sizeof(TEprcTable) + sizeof(TEprcTableInd) * lEPRCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPRC.lSize:%ld\n", ptEtrd->tTrdEPRC.lSize) );
	
	/*	�Хåե��ס�������ơ��֥륵����		*/
	ptEtrd->tTrdEBPC.lSize = sizeof(TEbpcTable) + sizeof(TEbpcTableInd) * lEBPCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEBPC.lSize:%ld\n", ptEtrd->tTrdEBPC.lSize) );
	
	/*	���Хåե��ס�������ơ��֥륵����		*/
	ptEtrd->tTrdESBP.lSize = sizeof(TEsbpTable) + sizeof(TEsbpTableInd) * lESBPKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdESBP.lSize:%ld\n", ptEtrd->tTrdESBP.lSize) );
	
	/*	�ס���Хåե������ơ��֥륵����		*/
	ptEtrd->tTrdEPBC.lSize = sizeof(TEpbcTable) + sizeof(TEpbcTableInd) * lEPBCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPBC.lSize:%ld\n", ptEtrd->tTrdEPBC.lSize) );
	
	/*	�᡼��ܥå��������ơ��֥륵����		*/
	ptEtrd->tTrdEMBC.lSize = sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * lEMBCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMBC.lSize:%ld\n", ptEtrd->tTrdEMBC.lSize) );
	
	/*	��å����������ơ��֥륵����	20021226 �ɲý���	*/
//	ptEtrd->tTrdEMMC.lSize = sizeof(TEmmcTable) + sizeof(TEmmcTableInd) * lEMMCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMMC.lSize:%ld\n", ptEtrd->tTrdEMMC.lSize) );

	lTemp = 0;
	lRes = os_getEmmcSize(&lTemp);
	if(NORMAL != lRes)
	{
		return( OSERREMMC );
	}
	ptEtrd->tTrdEMMC.lSize = lTemp;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEMMC.lSize:%ld\n", ptEtrd->tTrdEMMC.lSize) );

	/*	��ͭ��������ơ��֥륵����			*/
	ptEtrd->tTrdESMC.lSize = sizeof(TEsmcTable) + sizeof(TEsmcTableInd) * lESMCKbt;
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdESMC.lSize:%ld\n", ptEtrd->tTrdESMC.lSize) );


	/************************************************/
	/*	�ƥơ��֥�����Х��ɥ쥹����Ƴ�Ǽ����	*/
	/************************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** �ƥơ��֥�����Х��ɥ쥹��Ǽ\n") );
	/*	�ץ��������ơ��֥�					*/
	ptEtrd->tTrdEPRC.lRAdr = lEtrdSize;
//	DbgMsg01( DLv04, ( OutPut, "***** EPRC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdEPRC.lRAdr) );
	
	/*	�Хåե��ס�������ơ��֥�				*/
	ptEtrd->tTrdEBPC.lRAdr = (ptEtrd->tTrdEPRC.lRAdr) + (ptEtrd->tTrdEPRC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EBPC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdEBPC.lRAdr) );
	
	/*	���Хåե��ס�������ơ��֥�			*/
	ptEtrd->tTrdESBP.lRAdr = (ptEtrd->tTrdEBPC.lRAdr) + (ptEtrd->tTrdEBPC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESBO���Х��ɥ쥹:%lx\n", ptEtrd->tTrdESBP.lRAdr) );
	
	/*	�ס���Хåե������ơ��֥�				*/
	ptEtrd->tTrdEPBC.lRAdr = (ptEtrd->tTrdESBP.lRAdr) + (ptEtrd->tTrdESBP.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EPBC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdEPBC.lRAdr) );
	
	/*	��å����������ơ��֥�					*/
	ptEtrd->tTrdEMMC.lRAdr = (ptEtrd->tTrdEPBC.lRAdr) + (ptEtrd->tTrdEPBC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EMMC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdEMMC.lRAdr) );

	/*	�ᥤ��ܥå��������ơ��֥�				*/
	ptEtrd->tTrdEMBC.lRAdr = (ptEtrd->tTrdEMMC.lRAdr) + (ptEtrd->tTrdEMMC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** EMBC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdEMBC.lRAdr) );
	
	/*	��ͭ��������ơ��֥�					*/
	ptEtrd->tTrdESMC.lRAdr = (ptEtrd->tTrdEMBC.lRAdr) + (ptEtrd->tTrdEMBC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESMC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdESMC.lRAdr) );
	
	/*	SG��������ơ��֥�						*/
	ptEtrd->tTrdESGC.lRAdr = (ptEtrd->tTrdESMC.lRAdr) + (ptEtrd->tTrdESMC.lSize);
//	DbgMsg01( DLv04, ( OutPut, "***** ESMC���Х��ɥ쥹:%lx\n", ptEtrd->tTrdESGC.lRAdr) );
	/************************************************/
	/*	���ޥե�Key�������ȥ��ޥե�ID�μ���			*/
	/************************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** ���ޥե�Key����\n" ) );
	
	for(lCnt = 0; lCnt < lTblNum;lCnt++){
		switch(lCnt)
		{
			case 0:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEPRCSemKey:%s\n",lCnt,acEPRCSemKey) );
				lSemKey = BlpMpf_ntok( acEPRCSemKey, lGenKey );		break;
				
			case 1:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEBPCSemKey:%s\n",lCnt,acEBPCSemKey) );
				lSemKey = BlpMpf_ntok( acEBPCSemKey, lGenKey );		break;
				
			case 2:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acESBPSemKey:%s\n",lCnt,acESBPSemKey) );
				lSemKey = BlpMpf_ntok( acESBPSemKey, lGenKey );		break;
				
			case 3:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEPBCSemKey:%s\n",lCnt,acEPBCSemKey) );
				lSemKey = BlpMpf_ntok( acEPBCSemKey, lGenKey );		break;

			case 4:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEMMCSemKey:%s\n",lCnt,acEMMCSemKey) );
				lSemKey = BlpMpf_ntok( acEMMCSemKey, lGenKey );		break;
			
			case 5:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acEMBCSemKey:%s\n",lCnt,acEMBCSemKey) );
				lSemKey = BlpMpf_ntok( acEMBCSemKey, lGenKey );		break;
				
			case 6:
//			DbgMsg01( DLv04, ( OutPut, "***** lCnt:%d acESMCSemKey:%s\n",lCnt,acESMCSemKey) );
				lSemKey = BlpMpf_ntok( acESMCSemKey, lGenKey );		break;
				
			default:
				lSemKey = 0;	break;
		}
		
		if( -1 == lSemKey )							//���ޥե�Key�����۾�
		{
			DbgMsg01( DLv05, ( OutPut, "***** 02:Err Mess:%s\n", strerror(errno) ) );
			return( OSERRNTOK );					//key�����۾���ֵ�
		}
//		DbgMsg01( DLv04, ( OutPut, "***** lSemKey : %lx\n", lSemKey ) );
		
		/*	���ޥե�ID�μ���	*/
//		DbgMsg01( DLv04, ( OutPut, "***** lSemKey:%lx lSemNum:%ld lSemAcc:%lo\n",lSemKey,lSemNum,lSemAcc) );
		if(0 != lSemKey)
		{
			lSemId = semget( lSemKey, lSemNum, lSemAcc | IPC_CREAT | IPC_EXCL);
			if( -1 == lSemId )							//���ޥե��ɣļ����۾�
			{
				DbgMsg01( DLv05, ( OutPut, "***** 03 lCnt:%d :Err Mess:%s\n",
								 lCnt, strerror(errno) ) );
				return( OSERRSEMGET );					//���ޥե������۾���ֵ�
			}
		}
		
//		DbgMsg01( DLv04, ( OutPut, "***** lSemId : %ld\n", lSemId ) );
		/*	�ֵ��Ϥ�ƥե���������ơ��֥륻�ޥե�ID(iTblSemId)�������	*/
		*patTable[lCnt] = lSemId;
		
			// ���ޥե����������
		uSem.val = 1;								// uSem��oscom_ins������Ѥ�
	
		lRes = semctl((int)lSemId, 0, SETVAL, uSem);
		//if(NORMAL != lRes)						// 20021225 ����
		if(-1 == lRes)
		{
			DbgMsg01( DLv05, ( OutPut, "*****  04-1:Err Mess:%s\n", strerror(errno)) );
			return(OSERRSEMCTL);					// 20021225 �ɲ�
		}
	}
	
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initTrade\n" ) );
	return (NORMAL);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
