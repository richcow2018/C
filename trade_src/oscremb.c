/****************************************************************************/
/*	���	��������														*/
/*			  ������ңΣԣԥǡ���											*/
/*				��ͻ�ӥ��ͥ���������										*/
/*																			*/
/*																			*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��				*/
/****************************************************************************/
/* ���оݶ�̳̾��				�ԣң��ģť��ߥ�졼��						*/
/* ���оݶ�̳�ɣġ� 			�ԣң� 										*/
/* �㥵���ӥ�����̾��			��å������̿�								*/
/* �㥵���ӥ����ܣɣġ� 		�أأأأأأ�								*/
/* ��⥸�塼��̾��				�ᥤ��ܥå����κ���						*/
/* ��⥸�塼��ɣġ�			oscremb										*/
/* ��⥸�塼�����֡�			�أأأأأأ�								*/
/*--------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��				���ѥ�����									*/
/* ��Ŭ�ѣϣӡ� 				�̣����� 									*/
/* �㳫ȯ�Ķ��� 				�ңȣ��ӣ�����								*/
/* �㵭�Ҹ���� 				�ø��� 										*/
/* ��⥸�塼����֡�			�ؿ�										*/
/* �㵡ǽ��ʬ�� 															*/
/* ���оݥǡ�����															*/
/* �㹩�������ض�ʬ��														*/
/*--------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��			�̣��̣�ݣӣͣХ����ƥ�					*/
/* �㳫ȯ�����ƥ��ֹ�� 		�УУ����£�����������						*/
/*--------------------------------------------------------------------------*/
/* �㳫ȯô��̾��				�ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)	*/
/* �������ֹ�� 				148-1457(03-5437-1457)						*/
/*--------------------------------------------------------------------------*/
/* ���߷׼�̾�� 				�أأأأأأ�								*/
/* ���߷�ǯ������				�أأأأأأ�		 						*/
/* ���߷׽�����̾�� 														*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 ��̣									*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 				*/
/* �㥽���������ԡ� 			 	 										*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 �أأإ��ƥå�							*/
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 															*/
/*	 �ᥤ��ܥå����κ���  													*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* ��ƽз����� 															*/
/*		long	oscremb( long mbid, long access )							*/
/*																			*/
/* �㲾������																*/
/*		long	mbid					�ᥤ��ܥå������̻�				*/
/*		long	access					������������̤���ѡ�				*/
/*																			*/
/* ���ֵ��͡�																*/
/*	   �ᥤ��ܥå������̻�													*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 													*/
/* �����»���� 															*/
/*	   �äˤʤ� 															*/
/* ����ѳ����⥸�塼��ɣġ�												*/
/* ��ƽи��Υ⥸�塼��ɣġ�												*/
/*																			*/
/*																			*/
/****************************************************************************/

/******************************** ɸ��إå����ե����� **********************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "oscremb.h"
#include "oscremb_ins.h"
#include "u_mpf.h"                      // ntok��


/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    oscremb                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ᥤ��ܥå����κ���                                      */
/*                                                                          */
/****************************************************************************/
long oscremb( long mbid, long access )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
//	BlpMpf_Key_t lIpcKey;				// IPC����
	BlpMpf_key_t lIpcKey;               // IPC����
	char acMBoxKey[D_MBKEY_LEN];		// �ᥤ��ܥå������̻�ʸ����
	long lAsso;							// ����
	long lSerNum;						// ����
	int iLoopCnt;						// �롼�ץ�����
	int iRet;							// �ؿ�����ֵ�
	TEmbcTableInd *ptIndTopAdr;			// �ᥤ��ܥå��������ơ��֥����������Ƭ���ɥ쥹
	TEmbcTableInd *ptIndAdr;			// �ᥤ��ܥå��������ơ��֥�������Υ��ɥ쥹
	
	os_trcget2( D_MD_OSCREMB, D_T_TRA_IN, 2, mbid, access );
	

//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	lAsso = os_GetAsso(mbid);			// ���̤μ���
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lAsso=%ld )\n",
    												D_PROC_NAME, lAsso ) );
    												
	lSerNum = os_GetSerNum(mbid);		// ���֤μ���
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSerNum=%ld )\n",
    												D_PROC_NAME, lSerNum ) );
    												
	switch(lAsso)
	{
		case D_ASSO_NONE:				// ���̤��ʤ��λ�
			if( lSerNum != D_SERNUM_NONE )
			{							// ���֤��ʤ��ʳ��λ�
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    													D_PROC_NAME, OSEEIMBI ) );
    			
    			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEIMBI );										
    													
				return( OSEEIMBI );		// OSEEIMBI���ֵ�
			}
			break;
		case D_ASSO_MB:					// ���̤��ᥤ��ܥå������̻Ҥλ�
			if( (lSerNum < D_SERNUM_MIN) || (lSerNum > ptEmbc->lUserIndNum) )
			{							// ���֤��桼�������������ϰϳ��Ǥ����
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    													D_PROC_NAME, OSEENEXS ) );
    			
    			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENEXS );											
    													
				return( OSEENEXS );		// OSEENEXS���ֵ�
			}
			break;
		default:						// ���̤�����¾�λ�
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    													D_PROC_NAME, OSEEIMBI ) );
    													
   			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEIMBI );
    		
			return( OSEEIMBI );			// OSEEIMBI���ֵ�
	}

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptIndTopAdr = ( TEmbcTableInd * )( ptEmbc + 1 );
										// ����������Ƭ���ɥ쥹�μ���
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndTopAdr=%p )\n",
    												D_PROC_NAME, ptIndTopAdr ) );
    												
	if( lAsso == D_ASSO_NONE )			// ���̤��ʤ��λ�
	{
		ptIndAdr = NULL;
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
    												
		for( iLoopCnt = ptEmbc->lUserIndNum; iLoopCnt < ptEmbc->lIndPartNum; iLoopCnt++ )
		{								// �����ƥ����������Ƭ�����˽����򤹤�
			if( ( ptIndTopAdr + iLoopCnt )->lMsgQId == D_MSGQID_NONE )
			{							// ��������̤�����λ�
				ptIndAdr = ptIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������ƥ�����������
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
				break;					// �����֤�����ȴ����
			}
		}
		if( ptIndAdr == NULL )			// ̤�����Υ����ƥ�����������Ĥ���ʤ��ä���
		{
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    													D_PROC_NAME, OSEEWKEX ) );
    													
    		os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEWKEX );											
    													
			return( OSEEWKEX ) ;		// OSEEWKEX���ֵ�
		}
	}
	else								// ���̤��ᥤ��ܥå������̻Ҥλ�
	{
		ptIndAdr = ptIndTopAdr + lSerNum - 1;
										// ����Υ桼���������������
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr=%p )\n",
    												D_PROC_NAME, ptIndAdr ) );
    												
		if( ptIndAdr->lMsgQId != D_MSGQID_NONE )
		{								// ̤�����Ǥʤ���
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    													D_PROC_NAME, OSEEEXST ) );
    										
    		os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEEXST );												
    													
			return( OSEEEXST );			// OSEEEXST���ֵ�
		}
	}
	
	sprintf( acMBoxKey, "%08x", (unsigned int)ptIndAdr->lMBoxId );
										// �ᥤ��ܥå������̻Ҥ�ʸ������Ѵ�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( acMBoxKey=%s )\n",
    												D_PROC_NAME, acMBoxKey ) );
    												
    lIpcKey = BlpMpf_ntok( acMBoxKey, D_NTOK_PID );
    									// IPC��������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIpcKey=%ld )\n",
    												D_PROC_NAME, lIpcKey ) );
    												
    if( D_ERR_SYS == lIpcKey )			// IPC���������˼��Ԥ�����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    													D_PROC_NAME, -1 ) );
    											
    	os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, -1 );
    	return( OSEEIMBI );
    	//return( -1 );					// -1���ֵ�
	}

	os_trcget2( D_MD_OSCREMB, D_T_SYS_MSGGET, 2, lIpcKey, D_MSGGET_FLG );

	iRet = msgget( lIpcKey, D_MSGGET_FLG );
										// ��å��������塼�κ���
										
	os_trcget2( D_MD_OSCREMB, D_T_SYS_END, 1, iRet  );									
										
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
    												D_PROC_NAME, iRet ) );
    												
	if( iRet == D_ERR_SYS )				// �����˼��Ԥ�����
	{
		goto err_oscremb;				// �۾����������
	}

	ptIndAdr->lMsgQId = iRet;			// �������˥�å��������塼ID������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptIndAdr->lMsgQId=%ld )\n",
    												D_PROC_NAME, ptIndAdr->lMsgQId ) );

//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSCREMB, D_T_TRA_OUT, 1, ptIndAdr->lMBoxId );
	
	return( ptIndAdr->lMBoxId );		// �ᥤ��ܥå������̻Ҥ��ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_oscremb:
	switch( errno )
	{
		case EACCES:					// EACCES�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEENPRV, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENPRV );
									
			return( OSEENPRV );			// OSEENPRV���ֵ�
			break;
		case EEXIST:					// EEXIST�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEEXST, "msgget", strerror(errno) ) );
			
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEEXST );						
									
			return( OSEEEXST );			// OSEEEXST���ֵ�
			break;
		case EIDRM:						// EIDRM, ENOENT�λ�
		case ENOENT:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEENEXS, "msgget", strerror(errno) ) );
							
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEENEXS );						
									
			return( OSEENEXS );			// OSEENEXS���ֵ�
			break;
		case ENOMEM:					// ENOMEM, ENOSPC�λ�
		case ENOSPC:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 1, OSEEWKEX );	
									
			return( OSEEWKEX );			// OSEEWKEX���ֵ�
			break;
		default:						// ����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "msgget", strerror(errno) ) );
									
			os_trcget2( D_MD_OSCREMB, D_T_ERR_SYS, 2, -1 , errno );	
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREMB << 16) | D_T_ERR_SYS );
			//return( -1 );				// ++++++++���ܡ���ͽ��++++++++
	}
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
