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
/* ��⥸�塼��ɣġ�				 os_SendTimeOutMsg											*/
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
/* ������:����                                                              */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ������:2002ǯ10��8��                                                     */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �����ॢ���ȥ�å�����������																*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_SendTimeOutMsg.h>														*/
/*																								*/
/*		long	os_SendTimeOutMsg( long lPCode,long lReqNum, long lResult )						*/
/*																								*/
/* �㲾������																					*/
/*		long	lPCode;		�ץ������̻�														*/
/*		long	lReqNum;	�ꥯ�������ֹ�														*/
/*		long	lResult;	�ꥶ���															*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		-1				���ܡ���												*/
/*						OSEEWKEX		msgsnd������											*/
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
#include "os_SendTimeOutMsg_ins.h"
#include <malloc.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

/****************************************************************************/
/* ��ǽ:�����ॢ���ȥ�å�����������                                        */
/* ������:2002ǯ10��8��                                                     */
/* �ѹ���:                                                                  */
/* ������:����                                                              */
/* �ƽз���:                                                                */
/*   long os_SendTimeOutMsg( long lPCode,long lReqNum, long lResult )       */
/*      long lPCode         �ץ������̻�                                  */
/*      long lReqNum        �ꥯ�������ֹ�                                  */
/*      long lResult        �ꥶ���                                        */
/*                                                                          */
/****************************************************************************/
long os_SendTimeOutMsg(long lPCode,long lReqNum, long lResult )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    long lIndex = 0;                        // ��������Index
    long lMsgQId = 0;                       // ��å��������塼ID */
    TEtmcTableInd *ptTimeOut = NULL;           // �����޴����ơ��֥��
                                        // �����ॢ���Ȥ��������
    TEmbcTableInd *ptTEmbcTableInd = NULL;     // �ᥤ��ܥå��������ơ��֥��������
                                        // ��Ƭ���ɥ쥹
    TEmbcTableInd *ptTEmbcTableIndAdr = NULL;  // �ᥤ��ܥå��������ơ��֥��������
                                        // ���ɥ쥹
    int iLength = 0;
    TMyMessage tMsgBuf;          		// ��å������Хåե�
    int iRes = 0;                           // �꥿���󥳡���

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
    os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_TRA_IN, 3, lPCode, lReqNum, lResult );

    ptTEmbcTableInd = ( TEmbcTableInd * )( ptEmbc + 1 );
                                        // ��å�������¤�Υݥ���
//    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEmbcTableInd=%p )\n",
//    												D_PROC_NAME, ptTEmbcTableInd ) );
	DbgMsg01( DLv04, (OutPut, "%s ***** lPCode  : %08lx\n", "os_SendTimeOutMsg", lPCode));
	DbgMsg01( DLv04, (OutPut, "%s ***** lReqNum : %08lx\n", "os_SendTimeOutMsg", lReqNum));
	DbgMsg01( DLv04, (OutPut, "%s ***** lResult : %08lx\n", "os_SendTimeOutMsg", lResult));

    lIndex = 0;                         // �ᥤ��ܥå��������ơ��֥�θ�����
                                        // �������Ƭ���顢�ץ������̻Ҥ�
                                        // lPCode�����פ���������򸡺�����
    while( lIndex < ptEmbc->lIndPartNum )
    {
        if( ( ptTEmbcTableInd + lIndex )->lPCode == lPCode )
        {
            ptTEmbcTableIndAdr = ( TEmbcTableInd * )ptTEmbcTableInd + lIndex;
                                        // �����ƥ����������Ƭ���ɥ쥹�����
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEmbcTableIndAdr=%p )\n",
    												D_PROC_NAME, ptTEmbcTableIndAdr ) );
                                        
            lMsgQId = ptTEmbcTableIndAdr->lMsgQId;
                                        // �����ƥ�������Υ�å��������塼
                                        // �ɣĤ����
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMsgQId=%ld )\n",
    												D_PROC_NAME, lMsgQId ) );

    		DbgDmp02( DLv04, ("ptTEmbcTableInd   �����", ptTEmbcTableInd + lIndex,
    								 sizeof(TEmbcTableInd),1,0));
            DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIndex=%ld )\n",D_PROC_NAME, lIndex ) );
			
			break;
        }
        lIndex++;
//    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lIndex=%ld )\n",
//    												D_PROC_NAME, lIndex ) );
    }
    
    if( lIndex >= ptEmbc->lIndPartNum ) // ptEmbc->lIndPartNum:�����������
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    													D_PROC_NAME, -1 ) );
        return( -1 );                   // ���ܡ��Ƚ���
    }

    tMsgBuf.lMsgtype = D_TIMEOUT_MSG; 	// ��å����������פ�[�����ॢ��������]
                                        // �����ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lMsgtype ) );

    tMsgBuf.pcBufAdr = D_PBUF_FIX;    	// �ס���Хåե����ɥ쥹�����ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
    												D_PROC_NAME, tMsgBuf.pcBufAdr ) );

    tMsgBuf.lReqid = lReqNum;         	// �ꥯ�������ֹ�����ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lReqid ) );

    tMsgBuf.lDatesize = D_DATESIZE_FIX;
                                        // �ǡ��������������ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lDatesize ) );
    												
    tMsgBuf.lResult = lResult;        	// �ꥶ��Ȥ����ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
    												D_PROC_NAME, tMsgBuf.lResult ) );

    iLength = sizeof(TMyMessage) - sizeof(long);
    									// msgsnd�Υ�å�����Ĺ�ˤ�
										// ��å�����������(long)�ΥХ��ȿ�
										// ���������ΥХ��ȿ������ꤹ��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLength=%d )\n",
    												D_PROC_NAME, iLength ) );

	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_SYS_MSGSND, 4,
						lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
	
    iRes = msgsnd( lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
                                        // ��å�����������
	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_SYS_END, 2, iRes, errno);
	
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRes=%d )\n",
    												D_PROC_NAME, iRes ) );

    if( iRes == D_ERR_SYS ) 
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: %s\n", D_PROC_NAME, strerror(errno)) );
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    													D_PROC_NAME, OSEEWKEX ) );
        return( OSEEWKEX );             // msgsnd������
    }

    ptTimeOut = ( TEtmcTableInd * )ptEtmc->ptNxtAdr;
    									// �����ॢ���Ȥ�������������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut=%p )\n",
    												D_PROC_NAME, ptTimeOut ) );

    ptTimeOut->lReqNum = D_REQUESTNO_INI;
                                        // �ꥯ�������ֹ�ν����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut->lReqNum=%ld )\n",
    												D_PROC_NAME, ptTimeOut->lReqNum ) );
                                        
    ptTimeOut->dTimer = D_TIMER_INI;    // �������ͤν����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTimeOut->dTimer=%lf )\n",
    												D_PROC_NAME, ptTimeOut->dTimer ) );

	os_trcget2( D_MD_OS_SENDTIMEOUTMSG, D_T_TRA_OUT, 0);
    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
    return( NORMAL );                   // ���ｪλ
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

