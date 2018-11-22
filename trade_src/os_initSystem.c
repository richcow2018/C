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
/* ��⥸�塼��̾��					 �������ʥ����ƥ൯ư����									*/
/* ��⥸�塼��ɣġ�				 os_initSystem												*/
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
/*	 ���ѥ����˥����ƥ����Τǻ��Ѥ���ơ��֥�(TRADE�ơ��֥�)���ΰ����ݤ��롣				*/
/*   �ơ��֥���ΰ����ݤ�����˳ƥơ��֥���б�����ؿ��θƤӽФ���Ԥ���						*/
/*	 �ƥơ��֥���б�����ؿ���ɬ�פʻ�(�ե�����ʤ�)�ν�����Ƚ���ͤ��������ݤ��롣		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initSystem.h>															*/
/*																								*/
/*      long    os_initSystem(long lPCode)                                                      */
/*																								*/
/* �㲾������																					*/
/*      lPCode  �ץ������̻�(moa)                                                             */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ	��ͭ����ID																*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*  moa��main�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ��롣                                                       */
/*  �����ؿ��Ǥ϶�ͭ������˥ơ��֥��Ÿ������ΤߤǤ��롣���äƼºݤ�TRADE�ơ��֥�����Ѥ��� */
/*  ��硢���Ѥ�������os_initTrade�ؿ��θƽФ�Ԥ�ɬ�פ����롣                                  */
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initSystem.h"
#include "os_initSystem_ins.h"
#include "os_initEXXX_ins.h"

long os_initSystem(long lPCode)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lKMemKey = 0;								/* ��ͭ����Key(ntok��)	*/
	long lEprcKbt = 0;								/* EPRC��������				*/
	long lEbpcKbt = 0;								/* EBPC��������				*/
	long lEsbpKbt = 0;								/* ESBP��������				*/
	long lEpbcKbt = 0;								/* EPBC��������				*/
	long lEmbcKbt = 0;								/* EMBC��������				*/
	long lEmmcKbt = 0;								/* EMMC��������				*/
	long lEsmcKbt = 0;								/* ESMC��������				*/
	long lTblAdr = 0;								/* �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹*/
	char acGenKey[9];							/* Key������ʸ����			*/

	long lAllTableSize = 0;							/* �ơ��֥륵������׳�Ǽ	*/
	long lRes = 0;									/* �ֵ�����					*/
	long lShmKey = 0;								/* ��ͭ����Key��Ǽ��		*/
	long *plMemAdr = NULL;								/* ��ͭ���ꥢ�ɥ쥹��Ǽ��	*/
	long *plTempAdr = NULL;							/* ��ͭ���ꥢ�ɥ쥹��Ǽ��	*/
	int iMemId = 0;									/* ��ͭ����ID��Ǽ��		*/
	long lSgAdr = 0;								/* SG��Ǽ�ΰ���Ƭ���ɥ쥹��	*/
	long lSgSize = 0;							/* SG��Ǽ�ΰ襵������		*/
	long lTemp = 0;
	/******************************************/
	struct sigaction new[D_MAX_SIG_NUM];	// D_MAX_SIG_NUM�����ꥷ���ʥ��:31
	int iSigCnt = 0;
	/******************************************/
	
	/******************************************/
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		switch(iSigCnt+1)
		{
			case SIGILL:                        // ������̿��
			case SIGBUS:                        // �Х����顼
			case SIGFPE:                        // ��ư�������㳰
			case SIGSEGV:                       // �����ʥ��껲��
//			case SIGPIPE:                       // �ѥ����˲�
			case SIGTERM:                       // ��λ�����ʥ�
			case 16:                            // ����
				new[iSigCnt].sa_handler = os_dflact;
				break;
			default:                            // �嵭�ʳ���̵��
				new[iSigCnt].sa_handler = SIG_IGN;
				break;
		}
		new[iSigCnt].sa_flags = 0;
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}
	/******************************************/

/****************************************/
/*	�������							*/
/****************************************/
//	DbgInit( D_DEF, D_DEF, D_DEF );
	DbgMsg01( DLv01, ( OutPut, "***** Start initSystem\n" ) );
	
	
	/****************************************/
	/*	���������å�						*/
	/****************************************/
	if(0 > lPCode)								//�ץ������̻Ұ۾�
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_PRA, 1, OSERRARG );
		
		DbgMsg01( DLv05, ( OutPut, "***** lPCode is NULL\n") );
		return( OSERRARG );						//�����۾���ֵ�
	}
	/****************************************/
	/*	SG�����ͤ��ɤ߹���					*/
	/****************************************/
	/***********************************************************/
	/*  os_initSG�������׽���                                  */
	lRes = os_initSG();									/*	SG����ؿ������Τ߻���	*/
	
//	lRes = os_initSG(D_SG_SYSTEM, (void *)&lSgAdr, &lSgSize);
	
	if(-1 == lRes)								//�ӣǽ�����۾�				
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_PRA, 1, OSERRSG );
		
		DbgMsg01( DLv05, ( OutPut, "***** Err initSG\n") );
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
//	DbgMsg01( DLv04, ( OutPut, "***** lSgAdr :%08x\n", lSgAdr));
//	DbgMsg01( DLv04, ( OutPut, "***** lSgSize :%d\n", lSgSize));
	
	os_startSG();
	os_startTrace();                            // 20030123
	
	os_trcget2( D_MD_OS_INITSYSTEM, D_T_TRA_IN, 1, lPCode );
	/***********************************************************/

	lKMemKey = D_NTOK_ID;		// ��ͭ����Key�ɤ߹���

	lRes = os_getSG(D_SG_EPRC_NUM,&lEprcKbt);	// EPRC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err02:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);	// EBPC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err03:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lEsbpKbt);	// ESBP�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err04:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	//lEpbcKbt = lEbpcKbt * 0x7ffff;				// EPBC������������
	lRes = os_getSG(D_SG_EPBC_NUM,&lEpbcKbt);	// EMBC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err05:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}


	lRes = os_getSG(D_SG_EMBC_NUM,&lEmbcKbt);	// EMBC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err06:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
												// 20030307 KL0027 ���
//	lRes = os_getSG(D_SG_EMMC_NUM,&lEmmcKbt);	// EMMC�������ɤ߹���
//	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
//	{
//		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err07:%s\n", strerror(errno) ) );
//		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
//		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
//	}
	
	lRes = os_getSG(D_SG_ESMC_NUM,&lEsmcKbt);	// ESMC�������ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err08:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_TABLE_ADR,&lTblAdr);	// �ơ��֥��Ǽ�Ѷ�ͭ������Ƭ���ɥ쥹�ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err09:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}
	
	lRes = os_getSG(D_SG_ISYS_SKEY,acGenKey);	// ESYS����ʸ�����ɤ߹���
	if(NORMAL != lRes)							//�ӣ��ɹ��۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err10:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRSG );
		
		return( OSERRSG );						//�ӣ��ɹ��۾���ֵ�
	}

/****************************************/
/*	�ܽ���								*/
/****************************************/
	/****************************************/
	/*	 �ơ��֥륵�����λ���				*/
	/****************************************/
	/*	TRADE�ơ��֥�����ơ��֥륵������¬��									*/
	/*  20021226 �ɲ�  */
	lTemp = sizeof(TEtrdTable);
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEtrdTable:%ld\n", lTemp) );

	/*	�ץ��������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��			*/
	lTemp = sizeof(TEprcTable) + sizeof(TEprcTableInd) * lEprcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEprcTable:%ld\n", lTemp) );

	/*	�Хåե��ס�������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��	*/
	lTemp = sizeof(TEbpcTable) + sizeof(TEbpcTableInd) * lEbpcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEbpcTable:%ld\n", lTemp) );

	/*	���Хåե��ס�������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��	*/
	lTemp = sizeof(TEsbpTable) + sizeof(TEsbpTableInd) * lEsbpKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsbpTable:%ld\n", lTemp) );

	/*	�ס���Хåե������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��	*/
	lTemp = sizeof(TEpbcTable) + sizeof(TEpbcTableInd) * lEpbcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEpbcTable:%ld\n", lTemp) );

	/*	�᡼��ܥå��������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��	*/
	lTemp = sizeof(TEmbcTable) + sizeof(TEmbcTableInd) * lEmbcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEmbcTable:%ld\n", lTemp) );

	/*	��å����������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��		*/
	lTemp = 0;
	lRes = os_getEmmcSize(&lTemp);
	if(NORMAL != lRes)
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMMC );
		
		return( OSERREMMC );
	}

	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEmmcTable:%ld\n", lTemp) );

	/*	��ͭ��������ơ��֥�δ�����������+���̾�����������*�Ŀ���¬��			*/
	lTemp = sizeof(TEsmcTable) + sizeof(TEsmcTableInd) * lEsmcKbt;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsmcTable:%ld\n", lTemp) );

	/*	SG��Ǽ�ΰ襵������û�����			*/
	lTemp = lSgSize;
	lAllTableSize += lTemp;
//	DbgMsg01( DLv04, ( OutPut,"***** TEsgcTable:%ld\n", lSgSize) );
	
	DbgMsg01( DLv04, ( OutPut,"***** lAllTableSize:%ld\n", lAllTableSize) );

	/****************************************/
	/*	��ͭ����ν���					*/
	/****************************************/
	
	/*----------------------*/
	/*	��ͭ����Key������	*/
	/*----------------------*/
	lShmKey = BlpMpf_ntok(acGenKey, lKMemKey);
	if(-1 == lShmKey)								//��ͭ����Key�����۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRNTOK );
		
		return( OSERRNTOK );						//Key�����۾���ֵ�
	}
//	DbgMsg01(DLv04, (OutPut, "***** ��ͭ����Key : %x\n", lShmKey ) );
	
	/*--------------------------------------*/
	/*	��ͭ����γ��� ��ͭ����ID�μ���	*/
	/*--------------------------------------*/
	iMemId = shmget(lShmKey, lAllTableSize, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL);
	if(-1 == iMemId)								//��ͭ������ݰ۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** 02:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 2, OSERRSHMGET, errno );
		
		return( OSERRSHMGET );						//��ͭ������ݰ۾���ֵ�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ��ͭ����ID : %d\n", iMemId ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s:lTblAdr=%08x \n", "os_initSystem", lTblAdr));

	/*--------------------------------------*/
	/*	��ͭ��������(�ղ�)				*/
	/*--------------------------------------*/
	if(0 == lTblAdr)
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 3, iMemId, NULL, 0 );
		
		plMemAdr = shmat(iMemId, NULL, 0);
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 1, plMemAdr );
		
//		DbgMsg01( DLv04, ( OutPut, "***** shmat true\n") );
	}
	else
	{
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 3, iMemId, (void *)lTblAdr, SHM_RND );
		
		plMemAdr = shmat(iMemId, (void *)lTblAdr, SHM_RND);
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_SYS_SHMAT, 1, plMemAdr );
		
//		DbgMsg01( DLv04, ( OutPut, "***** shmat false\n") );
	}
	
	if(D_ERR_SYS == (long)plMemAdr)					//��ͭ�����ղð۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 2, OSERRSHMAT, errno );
		
		return( OSERRSHMAT );					//��ͭ�����ղð۾���ֵ�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ��ͭ������Ƭ���ɥ쥹 : %x\n", plMemAdr ) );

	/*--------------------------------------*/
	/*	��ͭ����ν����					*/
	/*--------------------------------------*/
	plTempAdr = plMemAdr;
	
	plMemAdr = memset(plTempAdr, 0, lAllTableSize);
	if(-1 == (long)plMemAdr)						//��ͭ���������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRMEMSET );
		
		return( OSERRMEMSET );						//��ͭ���������۾���ֵ�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** plMemAdr : %d\n", plMemAdr) );
	/****************************************/
	lTblAdr = (long)plMemAdr;
	/****************************************/
	/*	TRADE�ơ��֥�����ơ��֥�ν����	*/
	/****************************************/
	lRes = os_initTrade((TEtrdTable *)plMemAdr);
	if(NORMAL != lRes)								//�ԣң��ģŴ����ơ��֥������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 04:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRETRD );
		
		return( OSERRETRD );						//�ԣң��ģŴ����ơ��֥������۾���ֵ�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd : %x\n", ptEtrd ) );	/*	�ʸ�ptEtrd�����Ѳ�ǽ	*/

	/****************************************/
	/*	�ƥơ��֥�ν����					*/
	/****************************************/
//	DbgMsg01( DLv04, ( OutPut, "***** �ơ��֥�����\n" ) );
	
	/*	�ץ��������ơ��֥�ν����		*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPRC.lRAdr : %x\n", ptEtrd->tTrdEPRC.lRAdr ) );
	lRes = os_initEPRC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEPRC.lRAdr) ),  lPCode);
	if(NORMAL != lRes)								//�ץ��������ơ��֥������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 05:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREPRC );
		
		return( OSERREPRC );						//�ץ��������ơ��֥������۾�
	}

	/*	�Хåե��ס�������ơ��֥�ν����	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEBPC.lRAdr : %x\n", ptEtrd->tTrdEBPC.lRAdr ) );
	lRes = os_initEBPC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEBPC.lRAdr) ) );
	if(NORMAL != lRes)								//�Хåե������ơ��֥������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 06:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREBPC );
		
		return( OSERREBPC );						//�Хåե������ơ��֥������۾���ֵ�
	}

	/*	�ס���Хåե������ơ��֥�ν����	*/
//	DbgMsg01( DLv04, ( OutPut, "***** ptEtrd->tTrdEPBC.lRAdr : %x\n", ptEtrd->tTrdEPBC.lRAdr ) );

	lRes = os_initEPBC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEPBC.lRAdr) ) );
	if(NORMAL != lRes)								//�Хåե������ơ��֥������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 07:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREPBC );
		
		return( OSERREPBC );						//�Хåե������ơ��֥������۾���ֵ�
	}

	/*	�ᥤ��ܥå��������ơ��֥�ν����	*/
	lRes = os_initEMBC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEMBC.lRAdr) ) );
	if(NORMAL != lRes)								//�ᥤ��ܥå��������ơ��֥������۾�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s 08:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMBC );
		
		return( OSERREMBC );						//�ᥤ��ܥå��������ơ��֥������۾���ֵ�
	}

	//	��å����������ơ��֥�ν����
	lRes = os_initEMMC( (char *) ( (long)ptEtrd + (ptEtrd->tTrdEMMC.lRAdr) ) );
	if(NORMAL != lRes)								//��å����������ơ��֥������۾�
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 09:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERREMMC );
		
		return( OSERREMMC );						//��å����������ơ��֥������۾���ֵ�
	}

	/*	��ͭ��������ơ��֥�ν����		*/
	lRes = os_initESMC((char *) ( (long)ptEtrd + (ptEtrd->tTrdESMC.lRAdr) ) );
	if(NORMAL != lRes)								//��ͭ��������ơ��֥������۾�
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 11:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRESMC );
		
		return( OSERRESMC );						//��ͭ��������ơ��֥������۾���ֵ�
	}

	/*	���Хåե��ס�������ơ��֥�ν����*/
	lRes = os_initESBP( (char *) ( (long)ptEtrd + (ptEtrd->tTrdESBP.lRAdr) ),
						(TEbpcTable *) ( (long)ptEtrd + (ptEtrd->tTrdEBPC.lRAdr) ),
						(TEpbcTable *) ( (long)ptEtrd + (ptEtrd->tTrdEPBC.lRAdr) ) );
						
	if( NORMAL != lRes)								//�����Хåե��ס�������ơ��֥������۾�
	{
		DbgMsg01(DLv05, (OutPut, "***** %s 12:Err Mess:%s\n", "initSystem", strerror(errno) ) );
		
		os_trcget2( D_MD_OS_INITSYSTEM, D_T_ERR_SYS, 1, OSERRESBP );
		
		return( OSERRESBP );				//�����Хåե��ס�������ơ��֥������۾���ֵ�
	}
	
	/*	SG�����ơ��֥��Ÿ��				*/
	ptEtrd->tTrdESGC.lSize = lSgSize;			/* SG��Ǽ�ΰ襵�������Ǽ */
//	DbgMsg01(DLv04, (OutPut, "***** ptEtrd->tTrdESGC.lSize :%d\n", ptEtrd->tTrdESGC.lSize));
	
	/*--------------------------------------*/
	/*  moa�ѤΥץ��������               */
	/*--------------------------------------*/
	lRes = ((lPCode & 0x0000ffff) | 0x00020000);
//	DbgMsg01(DLv04, (OutPut, "***** moa�ѥץ��������\n"));
	os_initProcess(iMemId, (void *)lTblAdr, lRes);


/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01(DLv01, (OutPut, "***** End initSystem\n" ) );
//	DbgDmp02( DLv04, ("ptEPRC ������", (TEprcTableInd *)(ptEprc+1),
//	                                   (sizeof(TEprcTableInd))*3, 1, 0));
	
	os_trcget2( D_MD_OS_INITSYSTEM, D_T_TRA_OUT, 1, iMemId );

	return(iMemId);								/*	shmget������ID���֤�	*/
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
