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
/* �㥵���ӥ�����̾��				 ���ѥ������												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 ���ѥ���γ���											*/
/* ��⥸�塼��ɣġ�				 osgtshm													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)							*/
/*									 ���ץ饤���Ḷ												*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 ���ץ饤����¼												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�����ѹ��ֹ�ʣӣӣ̣�����������*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ã�����������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/* ��ǽ����ͭ�������                                                     					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osgtshm.h>																	*/
/*																								*/
/*		long osgtshm( long shmid, long size, long access, char *addr )							*/
/*																								*/
/* �㲾������																					*/
/*		long shmid			��ͭ���꼱�̻�													*/
/*		long size			����Х��ȿ�														*/
/*		long access			����������															*/
/*		char *addr			��Ƭ�������ɥ쥹													*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			��ͭ���ꡦ�������ȤΥ��ɥ쥹									*/
/*		�۾ｪλ			OSEEISHM															*/
/*							OSEEIADR															*/
/*							OSEEEXST															*/
/*							OSEESHMS															*/
/*							OSEEDBLM															*/
/*							OSEENRPG															*/
/*																								*/
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
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <u_mpf.h>									// ntok��


/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "osgtshm.h"
#include "osgtshm_ins.h"							// ���������ѡʸ��̡�


/***************************** ���ѼԺ����إå����ե����� ***************************************/
/* ��ǽ		����ͭ����γ���																	*/
/* ������	��2002ǯ10�� 3��																	*/
/* �ѹ���	��2002ǯ10��12��																	*/
/* ������	���Ḷ																				*/
/* �ƽз���	��																					*/
/*	long osgtshm( long shmid, long size, long access, char *addr )								*/
/*		long shmid		��ͭ���꼱�̻�														*/
/*		long size		����Х��ȿ�															*/
/*		long access		����������																*/
/*		char *addr		��Ƭ�������ɥ쥹														*/
/*																								*/
/***************************** ���ѼԺ����إå����ե����� ***************************************/
long osgtshm( long shmid, long size, long access, char *addr )
{

	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
//	long lAsso;										// ����
	long lSerNum;									// ����
	char acShmKey[D_SHMKEY_LEN];					// ��ͭ���꼱�̻�ʸ����
//	BlpMpf_Key_t lIpcKey;							// IPC����
	BlpMpf_key_t lIpcKey;							// IPC����
	int iRet;										// �ؿ�����ֵ���
	int iErrNum;									// errno������
	int iShmId;										// ��ͭ����ID
	long lIndNum;									// ��������
    void  *pvSegAddr;								// ��ͭ���ꥻ�����ȥ��ɥ쥹
    TEsmcTableInd *ptIndAdr;						// ��ͭ��������ơ��֥�������Υ��ɥ쥹


	/********************************************************************************************/
	/*	�������																				*/
	/********************************************************************************************/
    os_trcget2(D_MD_OSGTSHM,D_T_TRA_IN,4, shmid, size, access, addr);
//  DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );


//	lAsso = os_GetAsso( shmid );					// ���̤μ���
	lSerNum = os_GetSerNum( shmid );				// ���֤μ���

    lIndNum = ptEsmc->lIndPartNum;					// ������������

													// ���֤������λ�
//  if(( D_SHMKEY_MIN > lSerNum ) || ( lIndNum < lSerNum ))
/*****  �㳲�б���TBCS0210��    Start                                   ��������2003.07.15  *****/
    if(( -1 > lSerNum ) || ( lIndNum <= lSerNum ))
//    if(( -1 > lSerNum ) || ( lIndNum < lSerNum ))
/*****  �㳲�б���TBCS0210��    End                                     ��������2003.07.15  *****/
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISHM ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_PRA,1, OSEEISHM);
        return( OSEEISHM );							// OSEEISHM���ֵ�
    }

    if( D_MSIZE_MIN > size )						// ����Х��ȿ����Ǿ��ͤ�꾮������
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_PRA,1, OSEEIADR);
		return( OSEEIADR );							// OSEEIADR���ֵ�
	}

	/*****	�㳲�б���TBCA0027��	Start								��������2003.05.09	*****/
	/********************************************************************************************/
	/*	�������Υ��ɥ쥹���н��������ʼ����������֤ǻ��ꤹ���								*/
	/********************************************************************************************/
//	ptIndAdr = ( void * )ptEsmc + sizeof( TEsmcTable ) + sizeof( TEsmcTableInd ) * ( lSerNum - 1 );
	ptIndAdr = ( void * )ptEsmc + sizeof( TEsmcTable ) + (sizeof( TEsmcTableInd ) * lSerNum);
    												// ����������Υ��ɥ쥹����
	/*****	�㳲�б���TBCA0027��	 End								��������2003.05.09	*****/

    if( D_SHMID_NONE != ptIndAdr->lShmId )
    {									// ��ͭ���꤬���ݺѤߤλ�
    	DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEEXST);
		return( OSEEEXST );							// OSEEEXST���ֵ�
	}


	/********************************************************************************************/
	/*	�ܽ���																					*/
	/********************************************************************************************/
													// ��ͭ���꼱�̻Ҥ�ʸ������Ѵ�
	sprintf( acShmKey, "%08x", (unsigned int)shmid );
    lIpcKey = BlpMpf_ntok( acShmKey, D_NTOK_PID );	// IPC��������
    if( D_ERR_SYS == lIpcKey )						// IPC���������˼��Ԥ�����
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
        os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, -1);
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS );
		//return( -1 );					// -1���ֵ�
	}

    iShmId = shmget( lIpcKey, size, D_SHMGET_FLG );	// ��ͭ����γ������
    if( D_ERR_SYS == iShmId )						// ��ͭ����γ�����Ƥ˼��Ԥ�����
    {
		goto err_shmget;							// �۾����������
	}

													// ��ͭ����Υ����å�
	os_trcget2(D_MD_OSGTSHM,D_T_SYS_SHMAT,3, iShmId, addr, D_SHMAT_FLG);
	pvSegAddr = shmat( iShmId, addr, D_SHMAT_FLG );
	os_trcget2(D_MD_OSGTSHM,D_T_SYS_END,1, pvSegAddr);

	if( D_ERR_SYS == ( long )pvSegAddr )			// ��ͭ����Υ����å��˼��Ԥ�����
	{
		iErrNum = errno;							// errno���ѿ�������

													// ��ͭ�����̵����
        os_trcget2(D_MD_OSGTSHM,D_T_SYS_SHMCTL,3, iShmId, IPC_RMID, NULL);
		iRet = shmctl( iShmId, IPC_RMID, NULL );
        os_trcget2(D_MD_OSGTSHM,D_T_SYS_END,1, iRet);

		if( D_ERR_SYS == iRet )						// ��ͭ�����̵�����˼��Ԥ�����
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS1);
			//return( -1 );							// ���ܡ���
		}
		goto err_shmat;								// �۾����������
	}

	/************************************************/
	/*	��ͭ��������ơ��֥������������������	*/
	/************************************************/
	ptIndAdr->lShmId = ( long )iShmId;				// ��ͭ����ID����
	ptIndAdr->lShmSize = size;						// ��ͭ���ꥵ��������
	ptIndAdr->lAttach++;							// ���Ѿ����򥤥󥯥����20030122 �ɲ�

	DbgMsg01( DLv04, ( OutPut, "***** %s: ptIndAdr->lAttach:%ld\n",
			D_PROC_NAME, ptIndAdr->lAttach ) );


	/********************************************************************************************/
	/*	��λ����																				*/
	/********************************************************************************************/
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
    os_trcget2(D_MD_OSGTSHM,D_T_TRA_OUT,1, pvSegAddr);
	return( ( long )pvSegAddr );					// pvSegAddr���ֵ�


	/********************************************************************************************/
	/*	�۾����																				*/
	/********************************************************************************************/
err_shmget:
	switch( errno )
	{
		case EINVAL:								// EINVAL�λ�
		case ENOSPC:								// ENOSPC�λ�
		case ENOMEM:								// ENOMEM�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESHMS ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEESHMS);
			return( OSEESHMS );						// OSEESHMS���ֵ�
			break;
				
		case EEXIST:								// EEXIST�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEEXST);
			return( OSEEEXST );						// OSEEEXST���ֵ�
			break;
				
		case EIDRM:									// EIDRM�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEDBLM ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEDBLM);
			return( OSEEDBLM );						// OSEEDBLM���ֵ�
			break;
			
		default:									// ����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS2);
			//return( -1 );							// -1���ֵ�
	}


err_shmat:
	switch( iErrNum )
	{
		case EINVAL:								// EINVAL�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISHM ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEEISHM);
			return( OSEEISHM );						// OSEEISHM���ֵ�
			break;
			
		case ENOMEM:								// ENOMEM�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENRPG ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,1, OSEENRPG);
			return( OSEENRPG );						// OSEENRPG���ֵ�
			break;

		default:									// ����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
            os_trcget2(D_MD_OSGTSHM,D_T_ERR_SYS,2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTSHM << 16) | D_T_ERR_SYS3);
			//return( -1 );							// -1���ֵ�
	}
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
