/****************************************************************************/
/*  ���  ��������                                                        */
/*            ������ңΣԣԥǡ���                                          */
/*              ��ͻ�ӥ��ͥ���������                                        */
/*                                                                          */
/*                                                                          */
/*  ����ʪ  �̣��̣�ݣӣͣХ����ƥ�  �ԣң��ģť��ߥ�졼��                */
/****************************************************************************/
/* ���оݶ�̳̾��                  �ԣң��ģť��ߥ�졼��                   */
/* ���оݶ�̳�ɣġ�                �ԣң�                                   */
/* �㥵���ӥ�����̾��              �ԣã�/�ɣ�����                          */
/* �㥵���ӥ����ܣɣġ�            �أأأأأأ�                           */
/* ��⥸�塼��̾��                �ԣã�/�ɣФ�����������å�              */
/* ��⥸�塼��ɣġ�              os_tcpex                                 */
/* ��⥸�塼�����֡�                                                       */
/*--------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��                  ���ѥ�����                               */
/* ��Ŭ�ѣϣӡ�                    �̣�����                               */
/* �㳫ȯ�Ķ���                    �ңȣ��ӣ�����                           */
/* �㵭�Ҹ����                    �ø���                                   */
/* ��⥸�塼����֡�              �ؿ�                                     */
/* �㵡ǽ��ʬ��                                                             */
/* ���оݥǡ�����                                                           */
/* �㹩�������ض�ʬ��                                                       */
/*--------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��              �أأءݣӣͣХ����ƥ�                   */
/* �㳫ȯ�����ƥ��ֹ��            �УУ����£�����������                   */
/*--------------------------------------------------------------------------*/
/* �㳫ȯô��̾��                  �ã»��ӥ��ͥ����ô��(��ݥ������ץ饤) */
/* �������ֹ��                    148-1457(03-5437-1457)                   */
/*--------------------------------------------------------------------------*/
/* ���߷׼�̾��                    �ã»��ӥ��ͥ����ô��                   */
/* ���߷�ǯ������                  ��������ǯ���������                   */
/* ���߷׽�����̾��                                                         */
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                           */
/*--------------------------------------------------------------------------*/
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ�:���ץ饤)  */
/* �㥽��������ǯ������            ��������ǯ���������                   */
/* �㥽���������ԡ�                ���ץ饤��ƣΤ                           */
/* �㥽������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������                   */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/* �㥽������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������                   */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/* �㥽������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������                   */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/* �㥽������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������                   */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/* �㥽������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������                   */
/*                                         �ξ�����ֹ�ʣԣ£ãӣ��������� */
/*--------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���              ���ƥå�                                 */
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                             */
/*   ����åɤȤ��Ƶ�ư����TCP/IP����Ʊ�������׵ᡢ����CONNECT�׵��Ԥ���  */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      #include    <os_tcpex.h>                                            */
/*                                                                          */
/*      void os_tcpex( void *arg )                                          */
/*                                                                          */
/* �㲾������                                                               */
/*      void *arg       ����������Ȱ�ؤΥݥ���                        */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*      �ʤ�                                                                */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* �������ϥǡ�����¤��                                                     */
/* �����»����                                                             */
/*     �äˤʤ�                                                             */
/* ����ѳ����⥸�塼��ɣġ�                                               */
/* ��ƽи��Υ⥸�塼��ɣġ�                                               */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/******************************** ɸ��إå����ե����� **********************/
#include <errno.h>						// ���顼�Σ������
#include <stdio.h>
#include <unistd.h> 					// pipe,select��
#include <sys/time.h>					// FD_ZERO,FD_SET��
#include <sys/types.h>					// FD_ZERO,FD_SET��
#include <sys/socket.h> 				// socket��
#include <netinet/in.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <netdb.h>
#include <string.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "os_tcpex.h"
#include "os_tcpex_ins.h"							// ���������ѡʸ��̡�

/*****	�㳲�б���KL0051��	Start					��������2003.04.11	*****/
//TMyMessage tMsgBuf; 								// ��å������إå�����¤��
/*****	�㳲�б���KL0051��	 End					��������2003.04.11	*****/

/***************************** �ؿ��ץ�ȥ�������� *************************/
long os_tcpex_karitori();				// �׵ᴢ�������
long os_tcpex_msgsnd(); 				// ��λ��å�����������

/****************************************************************************/
/*																			*/
/*	��ؿ�̾��	  os_tcpex													*/
/*																			*/
/*	�㵡ǽ���ס�  TCP/IP���ͥ�����󡡥���åɽ���							*/
/*																			*/
/****************************************************************************/
void *os_tcpex( void *arg )
{
	int		iIdx;									// �롼�פ�Index
	int		iCommonRet;								// ���̴ؿ��꥿������
	int		iAddrLen;								// addr��¤�ΤΥХ��ȿ� 
	int		iSockDes;								// �����å��ѤΥǥ�������ץ�
	short	sParentLocalSession;					// �ƥ����륻������ֹ�
	long	lCommonRet;								// ���̴ؿ��꥿������
	long	iMsgsndRet;								// ��λ��å����������ؿ��꥿������
	long	lHedSize;								// read/writd�إå�������
	/*****	�����ѹ���KL0036��	Start				��������2003.03.18	*****/
	long	lReadFlg = 0;							// read�׵�ե饰  ��0:���Τʤ�/1:���Τ����
	long	lReadReqid = 0;							// read�׵�ꥯ�������ֹ�
	long	lAsyncFlg = 0;							// ��Ʊ�����Υե饰��0:���Τʤ�/1:���Τ����
	long	lAsyncReqid = 0;						// ��Ʊ�����Υꥯ�������ֹ�
	/*****	�����ѹ���KL0036��	 End				��������2003.03.18	*****/
	fd_set	fsSet;									// �ǥ�������ץ�����
	struct	sockaddr_in serv_addr;					// �����Х����åȤΥ��ɥ쥹(CONNECT)
	struct	sockaddr_in addr;						// �����Х����åȤΥ��ɥ쥹(ACCEPT)
	ssize_t lSndBytes;								// ������������ΥХ��ȿ�
	ssize_t lTotalSndBytes; 						// ���ߤޤǤ������������Х��ȿ�
	TTcpexArgInfo	tTcpexArgInfo;					// �����������
	TArgInfo		tArgInfo; 						// �׵�����ѥ����������
	/*****	�����ѹ���SSLA0006��Start				��������2003.01.30	*****/
	TArgHed			tReadHed; 						// read�ѥإå��ΰ�
	/*****	�����ѹ���SSLA0006�� End				��������2003.01.30	*****/
	/*****	�㳲�б���KL0051��	Start				��������2003.04.11	*****/
	TMyMessage tMsgBuf; 							// ��å������إå�����¤��
	/*****	�㳲�б���KL0051��	 End				��������2003.04.11	*****/
	TEcncTableInd	*ptEcncTableTopInd = NULL;		// ���ͥ����������ơ��֥���Ƭ�������Υ��ɥ쥹
	TEcncTableInd	*ptEcncTableInd = NULL;			// ���ͥ����������ơ��֥���оݸ�����
	TEcncTableInd	*ptNewEcncTableInd = NULL;		// ���ͥ����������ơ��֥�ο����оݸ�����
	TArgConnect		*ptArgConnect = NULL; 			// ����������ȹ�����CONNECT��
	TArgSyncInfoReq *ptArgSyncInfoReq = NULL;		// ��Ʊ�������׵��ѥ����������

	os_trcget2( D_MD_OS_TCPEX, D_T_TRA_IN, 1, arg );

	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );


/****************************************************************************/
/* ������� 																*/
/****************************************************************************/
	tTcpexArgInfo = *(TTcpexArgInfo *)arg;			// ����������Ȥ�����������
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FREE, 1, arg );
	free( arg );									// ����������Ȱ����
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

													// ���ͥ����������ơ��֥���Ƭ��������
													// ���ɥ쥹����
	ptEcncTableTopInd = (TEcncTableInd *)(ptEcnc + 1);

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableTopInd=%p )\n",
													D_PROC_NAME, ptEcncTableTopInd ) );

													// ���ͥ������ơ��֥���оݸ���������
	for( iIdx = 0; iIdx < ptEcnc->lMaxIndNum; iIdx++ )
	{
		ptEcncTableInd = ptEcncTableTopInd + iIdx;

										// ���ͥ����������ơ��֥�������Υ����åȥǥ�������ץ���
										// �����Υ����åȥǥ�������ץ���Ʊ���Ǥ���������򸡺�
		if( ptEcncTableInd->lSockDes == tTcpexArgInfo.lSockDes )
		{
			break;
		}
	}

	if( iIdx == ptEcnc->lMaxIndNum )	// Ʊ��θ�������¸�ߤ��ʤ����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
															D_PROC_NAME, -1 ) );

		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS1 );
//2003.04.10		return( NULL ); 				// ���ܡ��Ƚ���
	}

	sParentLocalSession = iIdx + 1;		// �ƥ����륻������ֹ�μ���
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sParentLocalSession=%hd )\n",
													D_PROC_NAME, sParentLocalSession ) );

	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_PIPE, 1, (int *)ptEcncTableInd->alPipeDes );

										// �ѥ��פκ���
	iCommonRet = pipe( (int *)ptEcncTableInd->alPipeDes );

	if( iCommonRet == D_ERR_SYS )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "pipe", strerror(errno) ) );

		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS2 );
//2003.04.10		return( NULL ); 				// ���ܡ��Ƚ���
	}

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->alPipeDes[1]=%hd )\n",
												D_PROC_NAME, ptEcncTableInd->alPipeDes[0] ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->alPipeDes[1]=%hd )\n",
												D_PROC_NAME, ptEcncTableInd->alPipeDes[1] ) );
	os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );


	/****************************************/
	/*  ��å������إå����Խ��ʥ��ꥢ��	*/
	/****************************************/
	tMsgBuf.lMsgtype	= 0;
	tMsgBuf.pcBufAdr	= NULL;
	tMsgBuf.lDatesize	= D_DATESIZE_FIX;
	tMsgBuf.lReqid		= tTcpexArgInfo.lReqNum;
	tMsgBuf.lResult		= D_RD_NORMAL;

//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lMsgtype ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
//												D_PROC_NAME, tMsgBuf.pcBufAdr ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lDatesize ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lReqid ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
//												D_PROC_NAME, tMsgBuf.lResult ) );


/****************************************************************************/
/* �ܽ���																	*/
/****************************************************************************/

	switch( tTcpexArgInfo.cAsyncFlg )	// �׵���̤ˤ������ο���ʬ��
	{
	case D_REQCLASS_ASYNC:				// ��Ʊ�������׵�ξ��

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ZERO, 1, &fsSet );
		FD_ZERO( &fsSet );				// �ɹ����ѥǥ�������ץ���������
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );
		
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );
										// �ǥ�������ץ�����˥ѥ����ѥǥ�������ץ�
										// �ɤ߹��ߥ���ͥ�¦��ä���
		FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->lSockDes, &fsSet );
										// �ǥ�������ץ�����˰�����
										// �оݸ������Υ����åȥǥ�������ץ���ä���
		FD_SET( ptEcncTableInd->lSockDes, &fsSet );	   
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		while(1)
		{
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, NULL );
										// �ǥ�������ץ������Ѳ��Ԥ�
			iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, NULL); 
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet == D_ERR_SYS )
			{
//				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
//											D_PROC_NAME, -1, "select", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS3 );
//2003.04.10				return( NULL ); 		// ���ܡ��Ƚ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->alPipeDes[0], &fsSet );
										// �ѥ����ѥǥ�������ץ������Ѳ���ǧ
			iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet != 0 )		// --- �ѥ��פ�����ɤ߹��߽���(��Ʊ�������׵�) ---
			{
				lTotalSndBytes = 0;
				lSndBytes = 0;

				while( lTotalSndBytes < sizeof(TArgInfo) )
				{
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, 
							ptEcncTableInd->alPipeDes[0],
									 (void *)&tArgInfo + lTotalSndBytes,
									  sizeof(TArgInfo) - lTotalSndBytes );
										// �ѥ����ѥǥ�������ץ�������ɹ�
					lSndBytes = read( ptEcncTableInd->alPipeDes[0],
									 (void *)&tArgInfo + lTotalSndBytes,
									  sizeof(TArgInfo) - lTotalSndBytes );
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

										// �ѥ����ѥǥ�������ץ�������ɹ��˼��Ԥ�����
					if( lSndBytes == D_ERR_SYS )
					{
										// errno ��EINTR�Ǥʤ���
						if( errno != EINTR )
						{				
							DbgMsg01( DLv05, ( OutPut, 
									"***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "read", strerror(errno) ) );

										// ���ܡ��Ƚ���
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                       (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS4 );
//2003.04.10							return( NULL );
						}
					}
					else				// �ѥ����ѥǥ�������ץ�������ɹ�������������
					{
										// �����������Х��ȿ��˺����ʬ�򥤥󥯥����
						lTotalSndBytes += lSndBytes;
					}
				}

										// �׵���̤ˤ������ο���ʬ��
				switch( tArgInfo.cRecClass )
				{
				case D_REQCLASS_READ:	// read�׵�
/*****	�ξ�����ֹ�TBCS0206���б�		Start							��������2003.07.08	*****/
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE23;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid   = ptEcncTableInd->tReaInfo.lReqNum;
													// ���ͥ������̤����
					tMsgBuf.lResult  = D_RESULT_NOTCONNECT;
/*****	�ξ�����ֹ�TBCS0206���б�		 End							��������2003.07.08	*****/

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();	// ��λ��å���������
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
					/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS5 );
//2003.04.10						return( NULL ); // ���ܡ���
					}
					break;

				case D_REQCLASS_WRITE:	// write�׵�
/*****	�ξ�����ֹ�TBCS0206���б�		Start							��������2003.07.08	*****/
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE24;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid   = tArgInfo.ulReqNum;
													// ���ͥ������̤����
					tMsgBuf.lResult  = D_RESULT_NOTCONNECT;
/*****	�ξ�����ֹ�TBCS0206���б�		 End							��������2003.07.08	*****/

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

				/*****	�㳲�б���KL0051��	Start			��������2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// ��λ��å���������
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	�㳲�б���KL0051��	 End			��������2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS6 );
//2003.04.10						return( NULL ); // ���ܡ���
					}
					break;

										// ��Ʊ�����Υ���󥻥��׵�
				case D_REQCLASS_ASYNC_CANCEL:
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ��Ʊ�������׵ᥭ��󥻥� )\n",
																				D_PROC_NAME ) );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );

										// �ѥ����ѥǥ�������ץ��ɹ��ѥ�����
					iCommonRet = close( ptEcncTableInd->alPipeDes[0] );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

					if( iCommonRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS7 );
//2003.04.10						return( NULL ); // ���ܡ��Ƚ���
					}

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );

										// �ѥ����ѥǥ�������ץ�����ѥ�����
					iCommonRet = close( ptEcncTableInd->alPipeDes[1] );

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

					if( iCommonRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS8 );
//2003.04.10						return( NULL ) ;// ���ܡ��Ƚ���
					}

										// ���ͥ����������ơ��֥�����о�����
										// �ѥ����ѥǥ�������ץ���0���ꥢ
					ptEcncTableInd->alPipeDes[0] = 0;
					ptEcncTableInd->alPipeDes[1] = 0;

					os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
					return( NULL ); 	// ����åɽ�λ
					break;

				/*****	�����ѹ���SSLA0014��Start	��������2003.02.17	*****/
//				default:
//					break;				// ���⤷�ʤ�

				case D_REQCLASS_DETACH: 			// DETACH�׵�
				case D_REQCLASS_DCONN: 				// DISCONNECT�׵�
				case D_REQCLASS_ABORT:				// ABORT�׵�
					while(1)
					{
													// �оݸ������Υ����åȥǥ�������ץ�������
						os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->lSockDes );
						iCommonRet = close( ptEcncTableInd->lSockDes );
						os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

													// close����
						if( iCommonRet == D_ERR_SYS )
						{
							if( errno == EINTR )	// errno ��EINTR�λ�
							{
								continue;			// ��ȥ饤������
							}
							else					// errno ��EINTR�Ǥʤ���
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                                os_treterm(os_EndCod(D_END_TYPE1), 
                                           (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS9 );
//2003.04.10								return( NULL );		// ���ܡ��Ƚ���
							}
						}
						else						// close����
						{
/*****	�ξ�����ֹ�TBCS0194���б�		Start							��������2003.07.02	*****/
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
							ptEcncTableInd->lSockDes = 0;
/*****	�ξ�����ֹ�TBCS0194���б�		 End							��������2003.07.02	*****/
							break;
						}
					}

					/*****	�㳲�б���KL0036��Start	��������2003.03.18	*****/
					/********************************************************/
					/* ����������Ԥä���ˡ���λ��å���������������		*/
					/* �褦�˽���											*/
					/********************************************************/
					/********************************************/
					/*  ��Ʊ�������׵��Ƚ��					*/
					/********************************************/
													// �оݸ���������Ʊ�����Υե饰=ON�ξ��
					if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
					{
						lAsyncFlg = 1;				// ��Ʊ�����Υե饰������
													// ��Ʊ�����Υꥯ�������ֹ������
						lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
					}

					/********************************/
					/*  �׵ᴢ�������			*/
					/********************************/
					lCommonRet = os_tcpex_karitori( ptEcncTableInd );
					if( lCommonRet !=0 )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
/*****	�ξ�����ֹ�TBCS0195���б�		Start							��������2003.07.02	*****/
//						return( NULL );				// ���ܡ���
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS48);
/*****	�ξ�����ֹ�TBCS0195���б�		 End							��������2003.07.02	*****/
					}

					/********************************************/
					/*  �������ͥ����������ơ��֥�Υ��ꥢ	*/
					/*  �ʥѥ����ѥǥ�������ץ��������		*/
					/********************************************/
					ptEcncTableInd->lSockDes			= 0;
					ptEcncTableInd->sParentLocalSession	= 0;
					ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
					ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
					ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
					ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
					memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
					memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
					memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );

					/********************************************/
					/*  ��Ʊ�����ν���							*/
					/********************************************/
					if (1 == lAsyncFlg)				// ��Ʊ�����Υե饰���֣������Τ���ˡפξ��
					{
						/********************************/
						/*  ��å������إå����Խ�		*/
						/********************************/
						tMsgBuf.lMsgtype = D_MTYPE22;
						tMsgBuf.pcBufAdr = NULL;
						tMsgBuf.lReqid =  lAsyncReqid;
													// ���Ǥˤ�륭��󥻥�
						tMsgBuf.lResult = D_RESULT_CUTCANCEL;

						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
						DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

						/********************************/
						/*  ��å�����������			*/
						/********************************/
				/*****	�㳲�б���KL0051��	Start			��������2003.04.11	*****/
//						iMsgsndRet = os_tcpex_msgsnd();	// ��λ��å���������
						iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	�㳲�б���KL0051��	 End			��������2003.04.11	*****/

						if( iMsgsndRet == D_ERR_SYS )
						{
							DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                      (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS10);
//2003.04.10							return( NULL );			// ���ܡ���
						}
					}

					/********************************************/
					/*  ��λ��å�������������					*/
					/********************************************/
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = tArgInfo.ulReqNum;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  ��å�����������			*/
					/********************************/
				/*****	�㳲�б���KL0051��	Start			��������2003.04.11	*****/
//						iMsgsndRet = os_tcpex_msgsnd();	// ��λ��å���������
						iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	�㳲�б���KL0051��	 End			��������2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )	// �۾�ξ��
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS11);
//2003.04.10						return( NULL ); 			// ���ܡ���
					}
					/*****	�㳲�б���KL0036�� End	��������2003.03.18	*****/

					os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
					return( NULL ); 				// ����åɽ�λ
					break;
				/*****	�����ѹ���SSLA0014�� End	��������2003.02.17	*****/
				}
				continue;							// �����׵�����
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->lSockDes, &fsSet );
													// �����åȥǥ�������ץ������Ѳ���ǧ
			iCommonRet = FD_ISSET( ptEcncTableInd->lSockDes, &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

			if( iCommonRet != 0 )					// --- ��³�׵�μ��������(��Ʊ�������׵�) ---
			{
				for( iIdx = 0; iIdx < ptEcnc->lMaxIndNum; iIdx++ )
				{
													// ���ͥ������ơ��֥���оݿ�������������
					ptNewEcncTableInd = ptEcncTableTopInd + iIdx;
										// ���ͥ����������ơ��֥�������Υ����åȥǥ�������ץ���
										// 0�Ǥ���������򸡺�
					if( ptNewEcncTableInd->lSockDes == 0 )
					{
						break;
					}
				}
										// �֥����åȥǥ�������ץ��פ�0�θ�������¸�ߤ��ʤ����
				if( iIdx == ptEcnc->lMaxIndNum )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_ERR_NOBUF );
/*****	�ξ�����ֹ�TBCS0211���б�		Start							��������2003.07.17	*****/
/************************************************************************************************/
/*	�оݤΥ��ͥ����������ơ��֥��������¸�ߤ��ʤ����ϥꥶ��Ȥˤ�							*/
/*	�֥Хåե���­�פ��ֵѤ���褦�˽���														*/
/************************************************************************************************/
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
					tMsgBuf.lResult = D_ERR_NOBUF;	// �Хåե���­

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  ��Ʊ�������׵���󥯥ꥢ	*/
					/********************************/
													// ��Ʊ�����Υե饰��OFF������
					ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
													// ��Ʊ�������׵���󥯥ꥢ
					memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );

					/********************************/
					/*  ��å�����������			*/
					/********************************/
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
					if( iMsgsndRet == D_ERR_SYS )		// ��å������������۾�ξ��
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, iMsgsndRet );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS12);
					}

					return;							// ����åɽ�λ
/*****	�ξ�����ֹ�TBCS0211���б�		End								��������2003.07.17	*****/
				}

										// ��³����
				iAddrLen = sizeof(addr);
				
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_ACCEPT, 3, ptEcncTableInd->lSockDes,
								   (struct sockaddr *)&addr,
								   &iAddrLen );
				iSockDes = accept( ptEcncTableInd->lSockDes,
								   (struct sockaddr *)&addr,
								   &iAddrLen ); 
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iSockDes );

				if( iSockDes < 0 )
				{
					goto err_tcpex_accept;
				}

				/************************************************/
				/*  ���ͥ������ơ��֥���оݿ�������������	*/
				/************************************************/
										// �����åȥǥ�������ץ���
										// �������������åȥǥ�������ץ�������
				ptNewEcncTableInd->lSockDes = iSockDes;
										// ��S/C�ե饰�פ�'S'������
//				ptNewEcncTableInd->cSCFlg = D_SCINFO_SERVER;
										// ��S/C�ե饰�פ�'C'������
				ptNewEcncTableInd->cSCFlg = D_SCINFO_CLIENT;
				ptNewEcncTableInd->alPipeDes[0] = ptEcncTableInd->alPipeDes[0];
				ptNewEcncTableInd->alPipeDes[1] = ptEcncTableInd->alPipeDes[1];

				ptEcncTableInd->alPipeDes[0] = 0;
				ptEcncTableInd->alPipeDes[1] = 0;

				DbgMsg01(DLv04,( OutPut,"***** %s: Display ( ptNewEcncTableInd->lSockDes=%ld )\n",
													D_PROC_NAME, ptNewEcncTableInd->lSockDes ) );
				DbgMsg01( DLv04, ( OutPut,"***** %s: Display ( ptNewEcncTableInd->cSCFlg=%hhd )\n",
													D_PROC_NAME, ptNewEcncTableInd->cSCFlg ) );
				DbgMsg01( DLv04, ( OutPut,
						"***** %s: Display ( ptNewEcncTableInd->alPipeDes[0]=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->alPipeDes[0] ) );
				DbgMsg01( DLv04, ( OutPut,
						"***** %s: Display ( ptNewEcncTableInd->alPipeDes[1]=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->alPipeDes[1] ) );

				/****************************************************/
				/*  �оݿ����������֥ѥ����ѥǥ�������ץ��פ�		*/
				/*  �оݸ������֥ѥ����ѥǥ�������ץ��פ�ܴɤ���	*/
				/****************************************************/
										// ��ACCEPT����֡פ�ACCEPT�������
				ptNewEcncTableInd->cAcceptStat = D_ACCEPTSTAT_ON;
										// �ֿƥ����륻�å�����ֹ�פ�
										// �оݸ������Υ����륻�å�����ֹ������
				ptNewEcncTableInd->sParentLocalSession = sParentLocalSession;
										// �֥ݡ����ֹ�פ˼��������ݡ����ֹ������
				ptNewEcncTableInd->tConnInfo.lPort = ntohs(addr.sin_port);
										// �֥��ɥ쥹�פ˼����������ɥ쥹������
				ptNewEcncTableInd->tConnInfo.lIPAdr = ntohl(addr.sin_addr.s_addr );
										// ��Ʊ�������׵��ѥ���������ȹ�¤�Τ�
										// ���ͥ������ơ��֥��оݸ�����
										// ��Ʊ�������׵����ΰ������󣱤�����
				ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;
										// ���ͥ������ơ��֥��оݸ���������
										// ��Ʊ�������׵����ΰ������󣱤�
										// 0�ӥå��ܤ�ON������
				ptArgSyncInfoReq->sDetailInfo |= 0x01;

				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->cAcceptStat=%hhd )\n",
						D_PROC_NAME, ptNewEcncTableInd->cAcceptStat ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->sParentLocalSession=%hd )\n",
						D_PROC_NAME, ptNewEcncTableInd->sParentLocalSession ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->tConnInfo.lPort=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->tConnInfo.lPort ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptNewEcncTableInd->tConnInfo.lIPAdr=%ld )\n",
						D_PROC_NAME, ptNewEcncTableInd->tConnInfo.lIPAdr ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
															D_PROC_NAME, ptArgSyncInfoReq ) );
				DbgMsg01( DLv04, ( OutPut, 
						"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
						D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );

				/*****	�㳲�б���KL0036��Start	��������2003.03.18	*****/
				/********************************************************/
				/* ��λ��å�������������Ǹ�˹Ԥ��褦�˽���			*/
				/********************************************************/
				/********************************/
				/*  ��å������إå����Խ�		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

													// ���ͥ������ơ��֥��оݸ���������
													// ��Ʊ�����Υե饰��OFF������
				ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
				ptEcncTableInd = ptNewEcncTableInd;	// �оݿ������������оݸ������Ȥ���

				/********************************/
				/*  ��å�����������			*/
				/********************************/
				/*****	�㳲�б���KL0051��	Start			��������2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();				// ��λ��å���������
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
				/*****	�㳲�б���KL0051��	 End			��������2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS13);
//2003.04.10					return( NULL ); 				// ���ܡ���
				}
				/*****	�㳲�б���KL0036�� End	��������2003.03.18	*****/
				break;					// Loop��ȴ���� -> �����׵᡿��³����֤δƻ������
			}
		}
		break;

	case D_REQCLASS_CONN: 				// �׵���̤�CONNECT�׵�ξ��

		memset( &serv_addr, 0,	sizeof(serv_addr) );
										// ��¤�ν����
										
		serv_addr.sin_family = PF_INET;
										// �ץ�ȥ���ե��ߥ�ˡ�AF_INET�פ�����
		ptArgConnect = (TArgConnect *)tTcpexArgInfo.pcPara1;
										// CONNECT�Υ���������Ȱ�ݥ��󥿼���
										
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_HTONS, 1, ptArgConnect->sRemotePortNo );
		serv_addr.sin_port = htons(ptArgConnect->sRemotePortNo);
										// �ݡ����ֹ�˥���������Ȱ��
										// ��⡼�ȥݡ����ֹ������
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, serv_addr.sin_port );
										
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_HTONL, 1, ptArgConnect->lRemoteAddr );
		serv_addr.sin_addr.s_addr  = htonl(ptArgConnect->lRemoteAddr);
										// ���ɥ쥹�˥���������Ȱ��
										// ��⡼�ȥ��ɥ쥹������
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, serv_addr.sin_addr.s_addr );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CONNECT, 3, ptEcncTableInd->lSockDes, 
							  (const struct sockaddr *)&serv_addr, 
							  sizeof(serv_addr) );
		iCommonRet = connect( ptEcncTableInd->lSockDes, 
							  (const struct sockaddr *)&serv_addr, 
							  sizeof(serv_addr) );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		if(iCommonRet == D_ERR_SYS)
		{
										// ��å������إå����Խ�
//			tMsgBuf.lMsgtype = D_MTYPE22;
//			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
//														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, iCommonRet, errno);
			goto err_tcpex_connect;		// ���顼������
		}

										// ���ͥ����������ơ��֥��оݸ�����
										// �ݡ����ֹ�����
		ptEcncTableInd->tConnInfo.lPort = serv_addr.sin_port;
										// ���ͥ����������ơ��֥��оݸ�����
										// ���ɥ쥹����
		ptEcncTableInd->tConnInfo.lIPAdr = serv_addr.sin_addr.s_addr;
										// ���ͥ����������ơ��֥��оݸ�����
										// S/C�ե饰����
		ptEcncTableInd->cSCFlg = D_SCINFO_CLIENT;

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tConnInfo.lPort=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->tConnInfo.lPort ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->tConnInfo.lIPAdr=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->tConnInfo.lIPAdr ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->cSCFlg=%hhd )\n",
													D_PROC_NAME, ptEcncTableInd->cSCFlg ) );

		tMsgBuf.lMsgtype = D_MTYPE22;	// ��å������إå����Խ�
		tMsgBuf.lResult = D_RD_NORMAL;	// ��å������إå����Խ�

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
													D_PROC_NAME, tMsgBuf.lMsgtype ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
													D_PROC_NAME, tMsgBuf.lReqid ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
													D_PROC_NAME, tMsgBuf.lResult ) );

		/*****	�㳲�б���KL0051��	Start			��������2003.04.11	*****/
//		iMsgsndRet = os_tcpex_msgsnd();				// ��λ��å���������
		iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
		/*****	�㳲�б���KL0051��	 End			��������2003.04.11	*****/

		if( iMsgsndRet == D_ERR_SYS )
		{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS14);
//2003.04.10			return( NULL ); 			// ���ܡ���
		}
										// --- �����׵᡿��³����֤δƻ������ ---
		break;
		
	default:
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
															D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS15);
//2003.04.10		return( NULL ) ;				// ���ܡ��Ƚ���
	}

	while(1)							// --- �����׵᡿��³����֤δƻ� ---
	{
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ZERO, 1, &fsSet );
		FD_ZERO( &fsSet );				// �ɹ����ѥǥ�������ץ���������
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );
										// �ǥ�������ץ�����˥ѥ����ѥǥ�������ץ�
										// �ɤ߹��ߥ���ͥ�¦��ä���
		FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );	
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );


		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->cReadStat=%02x )\n",
												D_PROC_NAME, ptEcncTableInd->cReadStat ) );

										// ���ͥ����������ơ��֥��оݸ�����
										// resd�׵���֤��ֺѡפξ��
		if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �����åȤ��Ѳ���ƻ뤹�� )\n",
																		D_PROC_NAME ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd->lSockDes=%ld )\n",
												D_PROC_NAME, ptEcncTableInd->lSockDes ) );

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->lSockDes, &fsSet );
										// �ǥ�������ץ�������оݸ�������
										// �����åȥǥ�������ץ���ä���
			FD_SET( ptEcncTableInd->lSockDes, &fsSet );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 0 );
			
		}

		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, NULL );
										// �ǥ�������ץ������Ѳ��Ԥ�
		iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, NULL ); 
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
		
		if( iCommonRet == D_ERR_SYS )
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "select", strerror(errno) ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS16);
//2003.04.10			return( NULL ); 			// ���ܡ��Ƚ���
		}

		/********************************/
		/*  �ѥ��פ���ξ����Ѳ�		*/
		/********************************/
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, ptEcncTableInd->alPipeDes[0], &fsSet );
													// �ѥ����ѥǥ�������ץ������Ѳ���ǧ
		iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		if( iCommonRet != 0 )						// �ѥ��פ�����ɤ߹��߽���(CONNECT�׵�)
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �ѥ��פ���ξ����Ѳ���ǧ )\n",
																		D_PROC_NAME ) );

			lTotalSndBytes = 0;
			lSndBytes = 0;
													// �ѥ����ѥǥ�������ץ�������ɹ�
			while( lTotalSndBytes < sizeof(TArgInfo) )
			{
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, ptEcncTableInd->alPipeDes[0],
								 (void *)&tArgInfo + lTotalSndBytes,
								  sizeof(TArgInfo) - lTotalSndBytes );
				lSndBytes = read( ptEcncTableInd->alPipeDes[0],
								 (void *)&tArgInfo + lTotalSndBytes,
								  sizeof(TArgInfo) - lTotalSndBytes );
				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

				if( lSndBytes == D_ERR_SYS )		// �ѥ����ѥǥ�������ץ�������ɹ��˼��Ԥ�����
				{
					if( errno != EINTR )			// errno ��EINTR�Ǥʤ���
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "read", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL, errno);
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS17);
//2003.04.10						return( NULL );				// ���ܡ��Ƚ���
					}
				}
				else								// �ѥ����ѥǥ�������ץ�������ɹ�������������
				{
					lTotalSndBytes += lSndBytes;	// �����������Х��ȿ��˺����ʬ�򥤥󥯥����
				}
			}

			switch( tArgInfo.cRecClass )
			{										// �׵���֤ˤ������ο���ʬ��
			case D_REQCLASS_READ:					// read�׵�
													// �ƻ���֤η�³(���⤷�ʤ�)
				break;

			case D_REQCLASS_WRITE:					// write�׵�
				/********************************/
				/*  write����					*/
				/********************************/
				lTotalSndBytes = 0;
				lSndBytes = 0;

				/*****	�����ѹ���SSLA0006��Start	��������2003.01.30	*****/
//				while( lTotalSndBytes < (long)tArgInfo.pvArg2 )
				while( lTotalSndBytes < ((long)tArgInfo.pvArg2 - sizeof(TArgHed)) )
				/*****	�����ѹ���SSLA0006�� End	��������2003.01.30	*****/
				{
													// write�׵�����
													// (�оݸ����������åȥǥ�������ץ�)
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_WRITE, 3, 
												ptEcncTableInd->lSockDes, 
								(void *)((long)tArgInfo.pvArg1 + sizeof(TArgHed)) + lTotalSndBytes,
								((long)tArgInfo.pvArg2 - sizeof(TArgHed)) - lTotalSndBytes );

					/*****	�����ѹ���SSLA0006��Start	��������2003.01.30	*****/
//					lSndBytes = write( ptEcncTableInd->lSockDes, 
//									  (void *)tArgInfo.pvArg1 + lTotalSndBytes, 
//									  (long)tArgInfo.pvArg2 - lTotalSndBytes );
					lSndBytes = write( ptEcncTableInd->lSockDes, 
								(void *)((long)tArgInfo.pvArg1 + sizeof(TArgHed)) + lTotalSndBytes,
								((long)tArgInfo.pvArg2 - sizeof(TArgHed)) - lTotalSndBytes );
					/*****	�����ѹ���SSLA0006�� End	��������2003.01.30	*****/

					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%ld )\n",
															D_PROC_NAME, lSndBytes ) );

					if( lSndBytes == D_ERR_SYS )	// write�׵������˼��Ԥ�����
					{
						if( errno == EINTR )		// errno ��EINTR�λ�
						{
							continue;				// ��ȥ饤������
						}
													// errno ��ECONNRESET�λ�
						else if( errno == ECONNRESET )
						{
							while(1)
							{
								os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, 
														ptEcncTableInd->lSockDes );
													// �оݸ������Υ����åȥǥ�������ץ�������
								iCommonRet = close( ptEcncTableInd->lSockDes );

								os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
													// close����
								if( iCommonRet == D_ERR_SYS )
								{
													// errno ��EINTR�λ�
									if( errno == EINTR )
									{
										continue;
									}
									else			// errno ��EINTR�Ǥʤ���
									{	
										DbgMsg01( DLv05, ( OutPut,
												"***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
												D_PROC_NAME, -1, "close", strerror(errno) ) );

													// ���ܡ��Ƚ���
										os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1,NULL );
                                        os_treterm(os_EndCod(D_END_TYPE1), 
                                                  (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS18);
//2003.04.10										return( NULL );
									}
								}
								else				// close����
								{
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
//									ptEcncTableInd->lSockDes = 0;
									break;
								}
							}

							/*****	�㳲�б���KL0036��Start	��������2003.03.18	*****/
							/********************************************************/
							/* ����������Ԥä���ˡ���λ��å���������������		*/
							/* �褦�˽���											*/
							/********************************************************/
							/********************************************/
							/*  read�׵���������						*/
							/********************************************/
													// �оݸ�������read�׵����=ON�ξ��
							if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
							{
								lReadFlg = 1;		// read�׵�ե饰������
													// read�׵�ꥯ�������ֹ������
								lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;
							}

							/********************************************/
							/*  ���ͥ���������Ǥ�����					*/
							/********************************************/
													// �оݸ���������Ʊ�����Υե饰=ON�ξ��
							if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
							{
								lAsyncFlg = 1;		// ��Ʊ�����Υե饰������
													// ��Ʊ�����Υꥯ�������ֹ������
								lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// ��Ʊ�������׵��ѥ���������ȹ�¤�Τ�
													// ���ͥ������ơ��֥��оݸ�����
													// ��Ʊ�������׵����ΰ������󣱤�����
								ptArgSyncInfoReq =
									(TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// ���ͥ������ơ��֥��оݸ���������
													// ��Ʊ�������׵����ΰ������󣱤�
													// ���ͥ���������Ǥ�ON������
								ptArgSyncInfoReq->sDetailInfo |= 0x02;

								DbgMsg01( DLv04, ( OutPut,
									"***** %s: Display ( ptArgSyncInfoReq=%p )\n",
									D_PROC_NAME, ptArgSyncInfoReq ) );
								DbgMsg01( DLv04, ( OutPut,
							 		"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
									D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
							}

							/********************************************/
							/*  �׵ᴢ�������						*/
							/********************************************/
							lCommonRet = os_tcpex_karitori( ptEcncTableInd );
							if( lCommonRet !=0 )
							{
								DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
								os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                os_treterm(os_EndCod(D_END_TYPE1), 
                                          (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS19);
//2003.04.10								return( NULL );
							}

							/********************************************/
							/*  read�׵����ν���						*/
							/********************************************/
							if (1 == lReadFlg)		// read�׵�ե饰���֣������Τ���ˡפξ��
							{
								/********************************/
								/*  ��å������إå����Խ�		*/
								/********************************/
								tMsgBuf.lMsgtype = D_MTYPE23;
								tMsgBuf.pcBufAdr = NULL;
								tMsgBuf.lReqid = lReadReqid;
								tMsgBuf.lResult = D_RESULT_DISCONNECT;

								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
										D_PROC_NAME, tMsgBuf.lMsgtype ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
										D_PROC_NAME, tMsgBuf.lReqid ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lResult=%ld )\n",
										D_PROC_NAME, tMsgBuf.lResult ) );

								/********************************/
								/*  ��å�����������			*/
								/********************************/
								/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//								iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
								iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
								/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

								if( iMsgsndRet == D_ERR_SYS ) 
								{
									DbgMsg01(DLv05,( OutPut, "***** %s: Err Function 17: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
									os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                    os_treterm(os_EndCod(D_END_TYPE1), 
                                              (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS20);
//2003.04.10									return( NULL );
								 		// ���ܡ���
								}
							}

							/********************************************/
							/*  ��Ʊ�����Ρʥ��ͥ���������ǡ˽���		*/
							/********************************************/
							if (1 == lAsyncFlg)		// ��Ʊ�����Υե饰���֣������Τ���ˡפξ��
							{
								/********************************/
								/*  ��å������إå����Խ�		*/
								/********************************/
								tMsgBuf.lMsgtype = D_MTYPE22;
								tMsgBuf.pcBufAdr = NULL;
								tMsgBuf.lReqid = lAsyncReqid;
								tMsgBuf.lResult = D_RD_NORMAL;

								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
										D_PROC_NAME, tMsgBuf.lMsgtype ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
										D_PROC_NAME, tMsgBuf.lReqid ) );
								DbgMsg01( DLv04, ( OutPut,
										"***** %s: Display ( tMsgBuf.lResult=%ld )\n",
										D_PROC_NAME, tMsgBuf.lResult ) );

								/********************************/
								/*  ��å�����������			*/
								/********************************/
								/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//								iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
								iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
								/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

								if( iMsgsndRet == D_ERR_SYS ) 
								{
									DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 18: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
													// ���ܡ���
									os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                                    os_treterm(os_EndCod(D_END_TYPE1), 
                                               (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS21 );
//2003.04.10									return( NULL );
								}
							}
													// ����åɤν�λ
							os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
							return( NULL );
						}
						else						// errno ��EINTR,ECONNRESET�Ǥʤ���
						{
							DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 19: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "close", strerror(errno) ) );
													// ���ܡ��Ƚ���
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                      (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS22 );
//2003.04.10							return( NULL );
						}
					}

					lTotalSndBytes += lSndBytes;	// �����������Х��ȿ��˺����ʬ�򥤥󥯥����
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lTotalSndBytes=%d )\n",
																D_PROC_NAME, lTotalSndBytes ) );
				}

				/********************************/
				/*  ��å������إå����Խ�		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE24;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = tArgInfo.ulReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 20: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS23);
//2003.04.10					return( NULL ); 	// ���ܡ���
				}
				break;

			case D_REQCLASS_DETACH: 	// DETACH�׵�
			case D_REQCLASS_DCONN: 		// DISCONNECT�׵�
			case D_REQCLASS_ABORT:		// ABORT�׵�
				while(1)
				{
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->lSockDes );
										// �оݸ������Υ����åȥǥ�������ץ�������
					iCommonRet = close( ptEcncTableInd->lSockDes );
					os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

										// close����
					if( iCommonRet == D_ERR_SYS )
					{
										// errno ��EINTR�λ�
						if( errno == EINTR )
						{
							continue;
						}
						else			// errno ��EINTR�Ǥʤ���
						{
							DbgMsg01( DLv05, ( OutPut,
									"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "close", strerror(errno) ) );

										// ���ܡ��Ƚ���
							os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL , errno);
                            os_treterm(os_EndCod(D_END_TYPE1), 
                                   (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS24 );
//2003.04.10							return( NULL );
						}
					}
					else							// close����
					{
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
//						ptEcncTableInd->lSockDes = 0;
						break;
					}
				}

				/*****	�㳲�б���KL0036��Start	��������2003.03.18	*****/
				/********************************************************/
				/* ����������Ԥä���ˡ���λ��å���������������		*/
				/* �褦�˽���											*/
				/********************************************************/
				/********************************************/
				/*  read�׵���������						*/
				/********************************************/
													// read�׵���֤���ON�פξ��
				if( ptEcncTableInd->cReadStat == D_READSTAT_ON )
				{
					lReadFlg = 1;					// read�׵�ե饰������
													// read�׵�ꥯ�������ֹ������
					lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;
				}

				/********************************************/
				/*  ���ͥ���������Ǥ�����					*/
				/********************************************/
													// �оݸ���������Ʊ�����Υե饰=ON�ξ��
				if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
				{
					lAsyncFlg = 1;					// ��Ʊ�����Υե饰������
													// ��Ʊ�����Υꥯ�������ֹ������
					lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// ��Ʊ�������׵��ѥ���������ȹ�¤�Τ�
													// ���ͥ������ơ��֥��оݸ�����
													// ��Ʊ�������׵����ΰ������󣱤�����
					ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// ���ͥ������ơ��֥��оݸ���������
													// ��Ʊ�������׵����ΰ������󣱤�
													// ���ͥ���������Ǥ�ON������
					ptArgSyncInfoReq->sDetailInfo |= 0x02;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
																D_PROC_NAME, ptArgSyncInfoReq ) );
					DbgMsg01( DLv04, ( OutPut, 
							"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
							D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
				}

				/********************************************/
				/*  �׵ᴢ�������						*/
				/********************************************/
				lCommonRet = os_tcpex_karitori( ptEcncTableInd );

				if( lCommonRet !=0 )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS25);
//2003.04.10					return( NULL );
				}

				/********************************************/
				/*  �������ͥ����������ơ��֥�Υ��ꥢ	*/
				/*  �ʥѥ����ѥǥ�������ץ��������		*/
				/********************************************/
				ptEcncTableInd->lSockDes			= 0;
				ptEcncTableInd->sParentLocalSession	= 0;
				ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
				ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
				ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
				ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
				memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
				memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );

				/********************************************/
				/*  read�׵����ν���						*/
				/********************************************/
				if (1 == lReadFlg)					// read�׵�ե饰���֣������Τ���ˡפξ��
				{
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE23;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid = lReadReqid;
					tMsgBuf.lResult = D_RESULT_DISCONNECT;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  ��å�����������			*/
					/********************************/
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/
					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 23: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS26);
//2003.04.10						return( NULL ); // ���ܡ���
					}
				}

				/********************************************/
				/*  ��Ʊ�����Ρʥ��ͥ���������ǡ˽���		*/
				/********************************************/
				if (1 == lAsyncFlg)					// ��Ʊ�����Υե饰���֣������Τ���ˡפξ��
				{
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid =  lAsyncReqid;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  ��å�����������			*/
					/********************************/
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS27);
//2003.04.10						return( NULL ); // ���ܡ���
					}
				}

				/********************************************/
				/*  ��λ��å�������������					*/
				/********************************************/
				/********************************/
				/*  ��å������إå����Խ�		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = tArgInfo.ulReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/********************************/
				/*  ��å�����������			*/
				/********************************/
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS28);
//2003.04.10					return( NULL ); 				// ���ܡ���
				}
				/*****	�㳲�б���KL0036�� End	��������2003.03.18	*****/

				os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
				return( NULL ); 					// ����åɤν�λ
				break;

										// READ�׵ᥭ��󥻥�
			case D_REQCLASS_READ_CANCEL:
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( READ�׵ᥭ��󥻥� )\n",
																			D_PROC_NAME ) );
										// �оݸ�����read�׵����OFF����
				ptEcncTableInd->cReadStat = D_READSTAT_OFF;
										// �оݸ�����read�׵���󥯥ꥢ
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
				break;

										// ��Ʊ�����Υ���󥻥��׵�
			case D_REQCLASS_ASYNC_CANCEL:
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ��Ʊ�������׵ᥭ��󥻥��׵� )\n",
																			D_PROC_NAME ) );
										// �оݸ�������Ʊ�����Υե饰OFF����
				ptEcncTableInd->cAsyncFlg = D_SYNCINFOREQ_OFF;
										// �оݸ�������Ʊ�������׵���󥯥ꥢ
				memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
				break;

			default:
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 26: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS29);
//2003.04.10				return( NULL ); 		// ���ܡ��Ƚ���
			}
			continue;					// �����׵᡿��³����֤δƻ�����
		}

		/********************************/
		/*  �����åȤ���ξ����Ѳ�		*/
		/********************************/
													// �����åȥǥ�������ץ������Ѳ���ǧ
//		iCommonRet = FD_ISSET( tTcpexArgInfo.lSockDes, &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_FD_ISSET, 2, ptEcncTableInd->lSockDes, &fsSet );
		iCommonRet = FD_ISSET( ptEcncTableInd->lSockDes, &fsSet );
		os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=%ld )\n",
														D_PROC_NAME, iCommonRet ) );

		if( iCommonRet != 0 )						// --- ��³�׵�μ��������(CONNECT�׵�) ---
		{											// �֥����åȡפξ����Ѳ���ν���

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �����åȤ���ξ����Ѳ���ǧ )\n",
																		D_PROC_NAME ) );
			/*****	�����ѹ���SSLA0006��	Start	��������2003.01.30	*****/
			/********************************/
			/*  read�ѥإå������Խ�		*/
			/********************************/
													// ���ɥ쥹�ե��ߥ꡼���̻Ҥ�����
			tReadHed.sAddrFamilyId = D_ADRFAMILY_ID;
			tReadHed.sRtPortNo = D_RTPORT_NO;		// ��⡼�ȥݡ����ֹ������
			tReadHed.lRtIenetAddr = D_RTIENET_ADDR;	// ��⡼�ȥ��󥿡��ͥåȥ��ɥ쥹������
													// �ꥶ���֤�����
			memset(tReadHed.acReserve, 0, sizeof(tReadHed.acReserve));

													// read�ѥХåե��˥إå�����򥳥ԡ�
			memcpy(ptEcncTableInd->tReaInfo.pcPara1, &tReadHed, sizeof(TArgHed)); 
			lHedSize = sizeof(TArgHed);				// read�ѥإå�������������
			/*****	�����ѹ���SSLA0006��	 End	��������2003.01.30	*****/

			/********************************/
			/*  read����					*/
			/********************************/
			lSndBytes = 0;
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_READ, 3, ptEcncTableInd->lSockDes,
					  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
							  ptEcncTableInd->tReaInfo.lPara2 );

			for( ; ; )
			{
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �����åȤ���Υǡ����ɹ��� )\n",
																		D_PROC_NAME ) );

													// �оݸ����������åȥǥ�������ץ�������ɹ�
				/*****	�����ѹ���SSLA0006��Start	��������2003.01.30	*****/
//				lSndBytes = read( ptEcncTableInd->lSockDes,
//								  ptEcncTableInd->tReaInfo.pcPara1,
//								  ptEcncTableInd->tReaInfo.lPara2 );
				/*****	�㳲�б���TBCS0126��Start	��������2003.06.09	*****/
//				lSndBytes = read( ptEcncTableInd->lSockDes,
//								  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
//								  ptEcncTableInd->tReaInfo.lPara2 );
				lSndBytes = read( ptEcncTableInd->lSockDes,
								  (ptEcncTableInd->tReaInfo.pcPara1 + sizeof(TArgHed)),
								  (ptEcncTableInd->tReaInfo.lPara2  - sizeof(TArgHed)));
				/*****	�㳲�б���TBCS0126�� End	��������2003.06.09	*****/
				/*****	�����ѹ���SSLA0006�� End	��������2003.01.30	*****/

				os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, lSndBytes );

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%ld )\n",
															D_PROC_NAME, lSndBytes ) );

										// �оݸ����������åȥǥ�������ץ�������ɹ��˼��Ԥ�����
				if( lSndBytes == D_ERR_SYS )
				{
					/*****	�㳲�б���TBCA0029��Start		��������2003.04.24	*****/
					if( ECONNRESET == errno )		// errno��ECONNRESET�ξ��
					{
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, D_ERR_SYS, errno );
						lSndBytes = 0;				// �꡼�ɥ������ˡ�0�פ�����
					}
					/*****	�㳲�б���TBCA0029�� End		��������2003.04.24	*****/
					else if( EINTR != errno )		// errno��EINTR�ʳ��ξ��
					{
						DbgMsg01( DLv05, ( OutPut,"***** %s: Err Function 27: 0x%08x ( %s: %s )\n",
													D_PROC_NAME, -1, "read", strerror(errno) ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 2, NULL, errno );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS30);
//2003.04.10						return( NULL );				// ���ܡ��Ƚ���
					}
				}
				else					// �оݸ����������åȥǥ�������ץ�������ɹ�������������
				{
					break;
				}
			}

			if( lSndBytes >= 1 )		// ����
			{
				/********************************/
				/*  ��å������إå����Խ�		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE23;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tReaInfo.lReqNum;
				/*****	�����ѹ���SSLA0006��Start	��������2003.01.30	*****/
//				tMsgBuf.lResult = D_RD_NORMAL;
				tMsgBuf.lResult = lHedSize + lSndBytes;
				/*****	�����ѹ���SSLA0006�� End	��������2003.01.30	*****/

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/*****	�ξ����ɼKL0018�б� Start	��������2003.02.19	*****/
				/************************************************************/
				/*  ��λ��å��������������ˡ����ͥ����������ơ��֥��	*/
				/*  �оݸ��������Խ�����褦�˽���							*/
				/************************************************************/

				/************************************************/
				/*  �оݥ��ͥ����������ơ��֥���������Խ�	*/
				/************************************************/
										// read�׵���֤�OFF
				ptEcncTableInd->cReadStat = D_READSTAT_OFF;
										// read�׵����򥯥ꥢ
				memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 28: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS31);
//2003.04.10					return( NULL ); 	// ���ܡ���
				}
				/*****	�ξ����ɼKL0018�б�  End	��������2003.02.19	*****/

				continue;				// �ƻ���֤η�³
			}
			else if( lSndBytes == 0 )	// �ɤ߹�����ǡ�������0�פξ��
			{
				/*****	�㳲�б���KL0036��Start	��������2003.03.18	*****/
				/********************************************************/
				/* ����������Ԥä���ˡ���λ��å���������������		*/
				/* �褦�˽���											*/
				/********************************************************/
				/********************************************/
				/*  read�׵���������						*/
				/********************************************/
													// read�׵�ꥯ�������ֹ������
				lReadReqid = ptEcncTableInd->tReaInfo.lReqNum;

				/********************************************/
				/*  ���ͥ���������Ǥ�����					*/
				/********************************************/
										// �оݸ���������Ʊ�����Υե饰=ON�ξ��
				if( ptEcncTableInd->cAsyncFlg == D_SYNCINFOREQ_ON )
				{
					lAsyncFlg = 1;					// ��Ʊ�����Υե饰������
													// ��Ʊ�����Υꥯ�������ֹ������
					lAsyncReqid = ptEcncTableInd->tAsyncInfo.lReqNum;

													// ��Ʊ�������׵��ѥ���������ȹ�¤�Τ�
													// ���ͥ������ơ��֥��оݸ�����
													// ��Ʊ�������׵����ΰ������󣱤�����
					ptArgSyncInfoReq = (TArgSyncInfoReq *)ptEcncTableInd->tAsyncInfo.pcPara1;

													// ���ͥ������ơ��֥��оݸ���������
													// ��Ʊ�������׵����ΰ������󣱤�
													// ���ͥ���������Ǥ�ON������
					ptArgSyncInfoReq->sDetailInfo |= 0x02;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgSyncInfoReq=%p )\n",
																D_PROC_NAME, ptArgSyncInfoReq ) );
					DbgMsg01( DLv04, ( OutPut, 
							"***** %s: Display ( ptArgSyncInfoReq->sDetailInfo=%hd )\n",
							D_PROC_NAME, ptArgSyncInfoReq->sDetailInfo ) );
				}

				/********************************************/
				/*  �׵ᴢ�������						*/
				/*  �ʥѥ��ץǥ�������פΤߥ��ꥢ��		*/
				/********************************************/
				lCommonRet = os_tcpex_karitori( ptEcncTableInd );
				if( lCommonRet !=0 )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS32);
//2003.04.10					return( NULL );
				}

				/********************************************/
				/*  read�׵����ν���						*/
				/********************************************/
				/********************************/
				/*  ��å������إå����Խ�		*/
				/********************************/
				tMsgBuf.lMsgtype = D_MTYPE23;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lReqid = ptEcncTableInd->tReaInfo.lReqNum;
				tMsgBuf.lResult = D_RESULT_DISCONNECT;

				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );

				/********************************/
				/*  ��å�����������			*/
				/********************************/
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//				iMsgsndRet = os_tcpex_msgsnd();		// ��å�������������
				iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

				if( iMsgsndRet == D_ERR_SYS )
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
																		D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                    os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS33);
//2003.04.10					return( NULL ); 	// ���ܡ���
				}

				/********************************************/
				/*  ��Ʊ�����Ρʥ��ͥ���������ǡ˽���		*/
				/********************************************/
				if (1 == lAsyncFlg)					// ��Ʊ�����Υե饰���֣������Τ���ˡפξ��
				{
					/********************************/
					/*  ��å������إå����Խ�		*/
					/********************************/
					tMsgBuf.lMsgtype = D_MTYPE22;
					tMsgBuf.pcBufAdr = NULL;
					tMsgBuf.lReqid =  ptEcncTableInd->tAsyncInfo.lReqNum;
					tMsgBuf.lResult = D_RD_NORMAL;

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
																D_PROC_NAME, tMsgBuf.lMsgtype ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
																D_PROC_NAME, tMsgBuf.lReqid ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
																D_PROC_NAME, tMsgBuf.lResult ) );

					/********************************/
					/*  ��å�����������			*/
					/********************************/
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//					iMsgsndRet = os_tcpex_msgsnd();	// ��å�������������
					iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

					if( iMsgsndRet == D_ERR_SYS )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 24: 0x%08x\n",
																			D_PROC_NAME, -1 ) );
						os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                        os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS34);
//2003.04.10						return( NULL );				// ���ܡ���
					}
				}

				os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
				return( NULL ); 					// ����åɤν�λ
			}
			else									// errno ��EINTR�Ǥʤ���
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 29: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS35);
//2003.04.10				return( NULL ); 					// ���ܡ��Ƚ���
			}
		}
	}												// Loop END

	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OS_TCPEX, D_T_TRA_OUT, 1, NULL );
	return( NULL );


/****************************************************************************/
/* ���顼����																*/
/****************************************************************************/
err_tcpex_connect:						// connect�����ƥॳ���륨�顼
/*****	�ξ�����ֹ�TBCS0185���б�		Start							��������2003.06.30	*****/
/************************************************************************************************/
/*	���׵ᴢ��������פ��ɲ�																	*/
/************************************************************************************************/
	/********************************/
	/*  �׵ᴢ�������			*/
	/********************************/
	lCommonRet = os_tcpex_karitori( ptEcncTableInd );
	if( lCommonRet !=0 )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x\n",
														D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
													// ���ܡ���
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS49);
	}
/*****	�ξ�����ֹ�TBCS0185���б�		 End							��������2003.06.30	*****/

	switch( errno )
	{
		case EBADF:
		case EFAULT:
		case ENOTSOCK:
		case EINPROGRESS:
		case EAGAIN:
		case EAFNOSUPPORT:
		case EACCES:
		case EPERM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 30: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_LOGIC, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// ��å������إå����Խ�(�ꥶ���:�������)
			tMsgBuf.lResult = D_RESULT_LOGIC;

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 31: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS36);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_LOGIC );
//			return( NULL ) ;			// �������
			break;

		case EISCONN:
		case EALREADY:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 32: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_CONNECT, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.lResult = D_RESULT_CONNECT;
										// ��å������إå����Խ�(�ꥶ���:�����)

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 33: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS37);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_CONNECT );
//			return( NULL ); 			// ����Ѥ�
			break;

		case ECONNREFUSED:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 34: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_NOHOST, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// ��å������إå����Խ�(�ꥶ���:�ۥ�����ã�Բ�)
			tMsgBuf.lResult = D_RESULT_NOHOST;

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 35: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS38);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_NOHOST );
//			return( NULL ); 			// �ۥ�����ã�Բ�
			break;

		case ETIMEDOUT:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 36: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_TIMEOUT, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
									// ��å������إå����Խ�(�ꥶ���:���ͥ�����󥿥��ॢ����)
			tMsgBuf.lResult = D_RESULT_TIMEOUT;

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 37: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS39);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_TIMEOUT );
//			return( NULL ); 			// ���ͥ�����󥿥��ॢ����
			break;

		case ENETUNREACH:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 38: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, D_RESULT_NONETWORK, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// ��å������إå����Խ�(�ꥶ���:NETWORK��ã�Բ�)
			tMsgBuf.lResult = D_RESULT_NONETWORK;

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 39: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS40);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_NONETWORK );
//			return( NULL ); 			// NETWORK��ã�Բ�
			break;

		case EADDRINUSE:
		/*****	�ξ����ɼKL0029���б�	Start			��������2003.03.19	*****/
		case EADDRNOTAVAIL:
		/*****	�ξ����ɼKL0029���б�	 End			��������2003.03.19	*****/
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 40: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_USEDADDR, "connect", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
										// ��å������إå����Խ�(�ꥶ���:���ɥ쥹���Ѻ�)
			tMsgBuf.lResult = D_RESULT_USEDADDR;

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 41: 0x%08x\n",
																	D_PROC_NAME, -1 ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS41 );
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, D_RESULT_USEDADDR );
//			return( NULL ); 			// ���ɥ쥹���ѺѤ�
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 42: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "connect", strerror(errno) ) );

//			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
//			return( NULL ); 			// ���ܡ��Ƚ���
			break;
   }

/*****	�ξ�����ֹ�TBCS0185���б�		Start							��������2003.06.30	*****/
/************************************************************************************************/
/*	���׵ᴢ��������פ��ɲäˤ��ѥ��פΥ�������������									*/
/************************************************************************************************/
/*****	�ξ�����ֹ�TBCS0185���б�		 End							��������2003.06.30	*****/
	return( NULL );						// ����åɽ�λ


err_tcpex_accept:						// accept�����ƥॳ���륨�顼
	switch( errno )
	{
		case EAGAIN:					// EWOULDBLOCK��EAGAIN��Ʊ��
		case EBADF:
		case ENOTSOCK:
		case EOPNOTSUPP:
		case EFAULT:
		case EPERM:
		case EINTR:
		case ENOBUFS:
		case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 43: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "accept", strerror(errno) ) );

			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = ptEcncTableInd->tAsyncInfo.lReqNum;
			tMsgBuf.lResult = D_RESULT_LOGIC;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 44: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS44);
//2003.04.10				return( NULL ); 		// ���ܡ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );
										// �ѥ����ѥǥ�������ץ��ɹ��ѥ�����
			iCommonRet = close( ptEcncTableInd->alPipeDes[0] );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
			
			if( iCommonRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 45: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS45);
//2003.04.10				return( NULL ); 		// ���ܡ��Ƚ���
			}

			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );
										// �ѥ����ѥǥ�������ץ�����ѥ�����
			iCommonRet = close( ptEcncTableInd->alPipeDes[1] );
			os_trcget2( D_MD_OS_TCPEX, D_T_SYS_END, 1, iCommonRet );
			
			if( iCommonRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 46: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "accept", strerror(errno) ) );
				os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
                os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS46);
//2003.04.10				return( NULL ); 		// ���ܡ��Ƚ���
			} 

										// �оݸ������Υѥ����ѥǥ�������ץ����ꥢ
			ptEcncTableInd->alPipeDes[0] = 0;
			ptEcncTableInd->alPipeDes[1] = 0;

			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
			return( NULL ); 			// �������
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 47: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "accept", strerror(errno) ) );
			os_trcget2( D_MD_OS_TCPEX, D_T_ERR_SYS, 1, NULL );
            os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OS_TCPEX << 16) | D_T_ERR_SYS47);
//2003.04.10			return( NULL ); 			// ���ܡ��Ƚ���
   }
}


/****************************************************************************/
/*																			*/
/*	��ؿ�̾��	  os_tcpex_msgsnd											*/
/*																			*/
/*	�㵡ǽ���ס�  ��λ��å�������������									*/
/*																			*/
/*	�㲾������																*/
/*		TMyMessage *ptMsgBuf : ��å��������󥢥ɥ쥹 						*/
/*																			*/
/*	���ֵ��͡�																*/
/*		 NORMAL�������D_ERR_SYS���۾�									*/
/*																			*/
/****************************************************************************/
/*****	�㳲�б���KL0051��	Start					��������2003.04.11	*****/
long os_tcpex_msgsnd(TMyMessage *ptMsgBuf)
{
	int  iCommonRet;								// ���̴ؿ��꥿������
	size_t stMsgSz; 								// �����ѥ�å�����������


	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_TRA_IN, 0 );

										// ��å��������������Խ�
//	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);
	stMsgSz = sizeof(TMyMessage) - sizeof(long);

//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lMsgtype=%d )\n",
//			D_PROC_NAME, ptMsgBuf->lMsgtype ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lReqid  =%d )\n",
//			D_PROC_NAME, ptMsgBuf->lReqid ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptMsgBuf->lResult =%d )\n",
//			D_PROC_NAME, ptMsgBuf->lResult ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz           =%d )\n",
//			D_PROC_NAME, stMsgSz ) );

	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
//												&tMsgBuf, stMsgSz, IPC_NOWAIT );
												ptMsgBuf, stMsgSz, IPC_NOWAIT );

													// ��λ���Τ�����
//	iCommonRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	iCommonRet = msgsnd( ptMyEMBC->lMsgQId, ptMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_SYS_END, 1, iCommonRet );
	if( iCommonRet == D_ERR_SYS )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 48: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "msgsnd", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_ERR_SYS, 2, D_ERR_SYS , errno);
		return( D_ERR_SYS );
	}
	os_trcget2( D_MD_OS_TCPEX_MSGSND, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );
}
/*****	�㳲�б���KL0051��	 End					��������2003.04.11	*****/


/****************************************************************************/
/*																			*/
/*	��ؿ�̾��	  os_tcpex_karitori 										*/
/*																			*/
/*	�㵡ǽ���ס�  �׵�δ��������										*/
/*																			*/
/*	�㲾������																*/
/*		void *arg : ���ͥ����������ơ��֥��оݸ�������Ƭ���ɥ쥹 			*/
/*																			*/
/*	���ֵ��͡�																*/
/*		 NORMAL�������D_ERR_SYS���۾�									*/
/*																			*/
/****************************************************************************/
long os_tcpex_karitori(void *arg)
{
	TEcncTableInd *ptEcncTableInd = arg;			// ���ͥ����������ơ��֥���оݸ�����
	fd_set fsSet;									// �ǥ�������ץ�����
	struct timeval tvTimeout;
	TArgInfo tArgInfo; 								// �׵�����ѥ����������
	int  iCommonRet;								// ���̴ؿ��꥿������
	long iMsgsndRet;								// ��λ��å����������ؿ��꥿������
	ssize_t lSndBytes;								// ������������ΥХ��ȿ�
	ssize_t lTotalSndBytes; 						// ���ߤޤǤ������������Х��ȿ�
	/*****	�㳲�б���KL0051��	Start				��������2003.04.11	*****/
	TMyMessage tMsgBuf;								// ��å������إå�����¤��
	/*****	�㳲�б���KL0051��	 End				��������2003.04.11	*****/


	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_TRA_IN, 1, arg );

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_ZERO, 1, &fsSet );

										// --- �׵�δ����� ---
	FD_ZERO( &fsSet );					// �ɹ����ѥǥ�������ץ���������
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_SET, 2, 
											ptEcncTableInd->alPipeDes[0], &fsSet );

										// �ǥ�������ץ�����˥ѥ����ѥǥ�������ץ�
										// �ɤ߹��ߥ���ͥ�¦[0]��ä���
	FD_SET( ptEcncTableInd->alPipeDes[0], &fsSet );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 0 );

	tvTimeout.tv_sec = 0;				// select�ֵѻ��֤�0������
	tvTimeout.tv_usec = 0;				// select�ֵѻ��֤�0������

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_SELECT, 5, 
											FD_SETSIZE, &fsSet, NULL, NULL, &tvTimeout );

										// �ǥ�������ץ������Ѳ��Ԥ�
	iCommonRet = select( FD_SETSIZE, &fsSet, NULL, NULL, &tvTimeout ); 
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display (select iCommonRet=%ld )\n",
												"os_tcpex_karitori", iCommonRet ) );

	if( iCommonRet == D_ERR_SYS )		// �۾�ξ��
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 49: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "select", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
		return( D_ERR_SYS ); 			// ���顼��λ
	}

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_FD_ISSET, 2, 
													ptEcncTableInd->alPipeDes[0], &fsSet );
										// �ѥ����ѥǥ�������ץ������Ѳ���ǧ
	iCommonRet = FD_ISSET( ptEcncTableInd->alPipeDes[0], &fsSet );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display (FD_ISSET iCommonRet=%ld )\n",
												"os_tcpex_karitori", iCommonRet ) );

	if( iCommonRet != 0 )				// �����Ѳ���ǧ����
	{									// --- �ѥ��פ�����ɤ߹��߽���(CONNECT�׵�) ---
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �ѥ��פ���ξ����Ѳ���ǧ )\n",
																	D_PROC_NAME ) );

		lTotalSndBytes = 0;
		lSndBytes = 0;

		while( lTotalSndBytes < sizeof(TArgInfo) )
		{
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_READ, 3, 
											ptEcncTableInd->alPipeDes[0],
							 (void *)&tArgInfo + lTotalSndBytes,
							  sizeof(TArgInfo) - lTotalSndBytes );
										// �ѥ����ѥǥ�������ץ�������ɹ�
			lSndBytes = read( ptEcncTableInd->alPipeDes[0],
							 (void *)&tArgInfo + lTotalSndBytes,
							  sizeof(TArgInfo) - lTotalSndBytes );
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, lSndBytes );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSndBytes=%d )\n",
												"os_tcpex_karitori", lSndBytes ) );

										// �ѥ����ѥǥ�������ץ�������ɹ��˼��Ԥ�����
			if( lSndBytes == D_ERR_SYS )
			{
				if( errno != EINTR )	// errno ��EINTR�Ǥʤ���
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 50: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, D_ERR_SYS, "read", strerror(errno) ) );

										// ���顼��λ
					os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS, errno );
					return( D_ERR_SYS ); 			  
				}
			}
			else						// �ѥ����ѥǥ�������ץ�������ɹ�������������
			{
										// �����������Х��ȿ��˺����ʬ�򥤥󥯥����
				lTotalSndBytes += lSndBytes;
			}
		}

		switch( tArgInfo.cRecClass )	// �׵���̤ˤ������ο���ʬ��
		{
		case D_REQCLASS_WRITE:			// write�׵�
			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE24;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = tArgInfo.ulReqNum;
			tMsgBuf.lResult = D_RESULT_DISCONNECT;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 51: 0x%08x\n",
																	D_PROC_NAME, D_ERR_SYS ) );
				os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
				return( D_ERR_SYS ); 	// ���顼��λ
			}
			break;

		case D_REQCLASS_DETACH: 		// DETACH�׵�
		case D_REQCLASS_DCONN: 			// DISCONNECT�׵�
		case D_REQCLASS_ABORT:			// ABORT�׵�
			/********************************/
			/*  ��å������إå����Խ�		*/
			/********************************/
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lReqid = tArgInfo.ulReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lMsgtype ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lReqid ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														"os_tcpex_karitori", tMsgBuf.lResult ) );

										// ��λ��å���������
			/*****	�㳲�б���KL0051��	Start		��������2003.04.11	*****/
//			iMsgsndRet = os_tcpex_msgsnd();
			iMsgsndRet = os_tcpex_msgsnd(&tMsgBuf);
			/*****	�㳲�б���KL0051��	 End		��������2003.04.11	*****/

			if( iMsgsndRet == D_ERR_SYS )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 52: 0x%08x\n",
																	D_PROC_NAME, D_ERR_SYS ) );
				os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
				return( D_ERR_SYS ); 	// ���顼��λ
			}

			/************************************************/
			/*  �оݥ��ͥ����������ơ��֥�������Υ��ꥢ	*/
			/*  �ʥѥ����ѥǥ�������ץ��ʳ��򥯥ꥢ��		*/
			/************************************************/
			ptEcncTableInd->lSockDes			= 0;
			ptEcncTableInd->sParentLocalSession	= 0;
			ptEcncTableInd->cSCFlg				= D_SCINFO_NONE;
			ptEcncTableInd->cAcceptStat			= D_ACCEPTSTAT_OFF;
			ptEcncTableInd->cReadStat			= D_READSTAT_OFF;
			ptEcncTableInd->cAsyncFlg			= D_SYNCINFOREQ_OFF;
			memset( &ptEcncTableInd->tReaInfo, 0x00, sizeof(TReqInfo) );
			memset( &ptEcncTableInd->tAsyncInfo, 0x00, sizeof(TReqInfo) );
			memset( &ptEcncTableInd->tConnInfo, 0x00, sizeof(TConnInfo) );
			break;

		case D_REQCLASS_READ_CANCEL:	// READ�׵ᥭ��󥻥�
		case D_REQCLASS_ASYNC_CANCEL:	// ��Ʊ�����Υ���󥻥��׵�
			break;						// ���⤷�ʤ�

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 53: 0x%08x\n",
																D_PROC_NAME, D_ERR_SYS ) );
			os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 1, D_ERR_SYS );
			return( D_ERR_SYS ); 		// ���顼��λ
		}
	}
	
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[0] );
										// �оݸ������Υѥ����ѥǥ�������ץ�[0]������
	iCommonRet = close( ptEcncTableInd->alPipeDes[0] );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	if( iCommonRet == D_ERR_SYS )		// close����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 54: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "close", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS , errno);
		return( D_ERR_SYS ); 			// ���顼��λ
	}

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_CLOSE, 1, ptEcncTableInd->alPipeDes[1] );
										// �оݸ������Υѥ����ѥǥ�������ץ�[1]������
	iCommonRet = close( ptEcncTableInd->alPipeDes[1] );
	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_SYS_END, 1, iCommonRet );

	if( iCommonRet == D_ERR_SYS )		// close����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 55: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_SYS, "close", strerror(errno) ) );
		os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_ERR_SYS, 2, D_ERR_SYS , errno );
		return( D_ERR_SYS ); 			// ���顼��λ
	}

										// �оݸ������Υѥ����ѥǥ�������ץ����ꥢ
	ptEcncTableInd->alPipeDes[0] = 0;
	ptEcncTableInd->alPipeDes[1] = 0;

	os_trcget2( D_MD_OS_TCPEX_KARITORI, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );
}
/****************************************************************************/
/* End																		*/
/****************************************************************************/
