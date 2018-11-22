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
/* ��⥸�塼��ɣġ�				 os_initESBP												*/
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
/*	 ���Хåե��ס�������ơ��֥���ΰ���ݤ�ͭ������˳��ݤ��ƽ������»ܤ���				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initESBP.h>																*/
/*																								*/
/*	   	long os_initESBP(char *pcEsbpTableAdr,TEbpcTable *ptEbpcTableAdr,						*/
/*						 TEpbcTable *ptEpbcTableAdr)											*/
/*																								*/
/* �㲾������																					*/
/*		char		*pcEsbpTableAdr;			���Хåե������ơ��֥���Ƭ���ɥ쥹				*/
/*		TEbpcTable	*ptEbpcTableAdr;			�Хåե��ס�������ơ��֥���Ƭ���ɥ쥹			*/
/*		TEpbcTable	*ptEpbcTableAdr;			�ס���Хåե������ơ��֥���Ƭ���ɥ쥹			*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������	NORMAL																		*/
/*		�۾������	̤����																		*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	os_initSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���														*/
/*	�����ؿ��ƽ����˥Хåե��ס�������ơ��֥�ν��������λ���Ƥ���							*/
/*	�����ؿ��ƽ����˥ס���Хåե������ơ��֥�ν��������λ���Ƥ���							*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"

long os_initESBP(char *pcEsbpTableAdr, TEbpcTable *ptEbpcTableAdr, TEpbcTable *ptEpbcTableAdr)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TEsbpTableInd *ptEsbpInd;					// ESBP������
	TEsbpTableInd *ptEsbpIndTemp;				// ESBP�����������
	TEbpcTableInd *ptEbpcInd;					// EBPC������
	
	long lEsbpKbt;								// ESBP��������
	long lEbpcKbt;								// EBPC��������
	long lEpbcKbt;								// EPBC��������
	
	long lCnt;
	long lRes;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initESBP\n") );
/****************************************/
/*	�������							*/
/****************************************/
	ptEsbpInd = NULL;
	ptEsbpIndTemp = NULL;
	ptEbpcInd = NULL;
	lEsbpKbt = 0;
	lCnt = 0;
	lRes = 0;
	
	/*	���������å�	*/
	if( 0 == pcEsbpTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 01:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					//�����ס���Хåե������ơ��֥���Ƭ���ɥ쥹����
	}
//	DbgMsg01( DLv04, ( OutPut, "***** pcEsbpTableAdr :%x\n", pcEsbpTableAdr));
	
	if( 0 == ptEbpcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 02:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					// �Хåե��ס�������ơ��֥���Ƭ���ɥ쥹����
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpcTableAdr :%x\n", ptEbpcTableAdr));
	
	if( 0 == ptEpbcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** %s 03:Err Mess:%s\n", D_ESBP_TID, strerror(errno) ) );
		return( OSERRARG );					//�ס���Хåե������ơ��֥���Ƭ���ɥ쥹���� 
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ptEpbcTableAdr :%x\n", ptEpbcTableAdr));

	//***** SG�ɤ߹���
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߳���\n"));
	
	lRes = os_getSG(D_SG_ESBP_NUM,&lEsbpKbt);
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );					//�ӣ��ɹ��۾�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** ESBP��������:%ld\n", lEsbpKbt));
	
	lRes = os_getSG(D_SG_EBPC_NUM,&lEbpcKbt);
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** GetSG Err01:%s\n", strerror(errno) ) );
		return( OSERRSG );                  //�ӣ��ɹ��۾�
	}
//	DbgMsg01( DLv04, ( OutPut, "***** EBPC��������:%ld\n", lEbpcKbt));

	lEpbcKbt = lEbpcKbt * 0x7ffff;
//	DbgMsg01( DLv04, ( OutPut, "***** EPBC��������:%ld\n", lEpbcKbt));
	
//	DbgMsg01( DLv04, ( OutPut, "***** SG�ɤ߹��߽�λ\n"));
	
	/*	�����ΰ�ι�¤��					*/
	ptEsbp = (TEsbpTable *)pcEsbpTableAdr;	// ��������������
	/*	��������������					*/
	ptEsbpInd = (TEsbpTableInd *) ( (long)ptEsbp + sizeof(TEsbpTable) );
	ptEbpcInd = (TEbpcTableInd *) ( (long)ptEbpc + sizeof(TEbpcTable) );
	
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEsbp : %x\n", ptEsbp) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEsbpInd : %x\n", ptEsbpInd) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEbpcInd : %x\n", ptEbpcInd ) );
	
	/*	�Хåե��ס����������������		*/
	ptEbpc = ptEbpcTableAdr;
	/*	�ס���Хåե���������������		*/
	ptEpbc = ptEpbcTableAdr;

//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEbpc : %x\n", ptEbpc ) );
//	DbgMsg01( DLv04, ( OutPut, "***** Addr ptEpbc : %x\n", ptEpbc ) );
	
/****************************************/
/*	�ܽ���								*/
/****************************************/
	/*	����������ν����					*/
	strncpy( ptEsbp->acTid, D_ESBP_TID, 4 );			// �ΰ輱�̻Ҥ�ESBP�Τ����
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbp->acTid:%s\n", ptEsbp->acTid) );
	/*	����������ν����					*/
												/*	������[0]�ν����					*/
//	DbgMsg01( DLv04, ( OutPut, "***** �����������\n" ) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEbpc->pvAdr: %x\n", ptEbpc->pvAdr ) );
	
												/*	�Хåե��ס�����Ƭ���ɥ쥹��Хåե��ס�������ΰ賫�ϥ��ɥ쥹������	*/
	ptEsbpInd->pvEmpBpAdr = (void *)(ptEbpc->pvAdr);
													/*	�Хåե��ס��륵������Хåե��ס�������ΰ襵����������			*/
	ptEsbpInd->lEmpBpSize = ptEbpc->lSize;
													/*	EPBC��Ƭ���ɥ쥹+EPBC��������������ס���Хåե����������ΰ賫�ϥ��ɥ쥹������	*/
	ptEsbpInd->pvEmpEpbcAdr = (void *) ( (long)ptEpbc + sizeof(TEpbcTable) );
													/*	�ס���Хåե���������ס���Хåե����������ΰ襵����������			*/
	ptEsbpInd->lEmpEpbcSize = lEpbcKbt * sizeof(TEpbcTableInd);
	
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->pvEmpBpAdr   : %x\n", ptEsbpInd->pvEmpBpAdr) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->lEmpBpSize   : %d\n", ptEsbpInd->lEmpBpSize) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->pvEmpEpbcAdr : %x\n", ptEsbpInd->pvEmpEpbcAdr) );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd->lEmpEpbcSize : %d\n", ptEsbpInd->lEmpEpbcSize) );
	
	/*	������[1]��[ESBP�������� -1 ]�ν����		*/
	for(lCnt = 1; lCnt < lEsbpKbt ; lCnt++){
		ptEsbpIndTemp = (ptEsbpInd + lCnt);
												/*	�Хåե��ס�������ΰ賫�ϥ��ɥ쥹�˳�Ǽ*/
		ptEsbpIndTemp->pvEmpBpAdr = (void *)D_ESBP_ALL_F;
												/*	�Хåե��ס�������ΰ襵�����˳�Ǽ		*/
		ptEsbpIndTemp->lEmpBpSize = D_ESBP_ALL_Z;
												/*	�ס���Хåե����������ΰ賫�ϥ��ɥ쥹�˳�Ǽ*/
		ptEsbpIndTemp->pvEmpEpbcAdr = (void *)D_ESBP_ALL_F;
												/*	�ס���Хåե����������ΰ襵�����˳�Ǽ	*/
		ptEsbpIndTemp->lEmpEpbcSize = D_ESBP_ALL_Z;
		
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->pvEmpBpAdr:%8x\n",lCnt, ptEsbpIndTemp->pvEmpBpAdr));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->lEmpBpSize:%8x\n",lCnt, ptEsbpIndTemp->lEmpBpSize));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->pvEmpEpbcAdr:%8x\n",lCnt, ptEsbpIndTemp->pvEmpEpbcAdr));
		//DbgMsg01( DLv04, ( OutPut, "***** ptEsbpInd[%3d]->lEmpEpbcSize:%8x\n\n",lCnt, ptEsbpIndTemp->lEmpEpbcSize));
	}

/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_initESBP\n") );
	return (NORMAL);
	
}
