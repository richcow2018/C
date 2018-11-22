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
/* �㥵���ӥ�����̾��				 �Хåե��ס������											*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �Хåե��ס���κ��										*/
/* ��⥸�塼��ɣġ�				 osdelbp													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤��̣��			*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �Хåե��ס���κ��																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osdelbp.h>																	*/
/*																								*/
/*	   	long	osdelbp( long poolid )															*/
/*																								*/
/* �㲾������																					*/
/*		long	poolid;			�ס��뼱�̻�													*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			NORMAL																*/
/*		�۾ｪλ			-1																	*/
/*							OSEEWKEX															*/
/*							semop���ֵ���														*/
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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include "osdelbp.h"
#include "os_trcget.h"
#include "osdelbp_ins.h"				// ���������ѡʸ��̡�
#include "os_GetEbpcTableInd_ins.h"		// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ���Хåե��ס���κ��                                               */
/* ��������2002ǯ10��9��                                                    */
/* �ѹ�����                                                                 */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long osdelbp( long poolid )                                            */
/*     long poolid         �ס��뼱�̻�                                     */
/*                                                                          */
/****************************************************************************/
long osdelbp( long poolid )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// ���ޥե���¤��
	int iRet;							// �ֵ���
	int iLoopCnt;						// �롼�ץ�����
	long lRet;							// �ֵ���
	long lBpSize;						// �Хåե��ס��륵����
	long lPbSize;						// �ס���Хåե�������
	void *pvBpAdr;						// �Хåե��ס��륢�ɥ쥹
	void *pvPbAdr;						// �ס���Хåե����ɥ쥹
	TEbpcTableInd *ptBpIndAdr;			// �Хåե��ס�������ơ��֥�������Υ��ɥ쥹
	TEsbpTableInd *ptEsbpIndTopAdr;		// ���Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹
	TEsbpTableInd *ptEsbpIndBpAdr;		// ���Хåե��ס�������ơ��֥�������Υ��ɥ쥹��BP�ѡ�
	TEsbpTableInd *ptEsbpIndPbAdr;		// ���Хåե��ס�������ơ��֥�������Υ��ɥ쥹��PB�ѡ�
	

	os_trcget2( D_MD_OSDELBP, D_T_TRA_IN, 1, poolid  );

	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:poolid:%08lx \n", D_PROC_NAME, poolid ) );


	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
	for( ; ; )
	{
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å�
										
		if( iRet == D_ERR_SYS )
		{								// ��å��Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					                                                 
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, errno );
					                                                 
	        		return( OSEEWKEX );	// OSEEWKEX���ֵ�
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å�����
		{
			break;						// ������ȴ����
		}
	}
	os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 1, iRet );

	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// �Хåե��ס�������ơ��֥뤫���оݸ��������ɥ쥹�μ���
	if( lRet != NORMAL )				// �оݸ������Υ��ɥ쥹�μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%08lx \n", D_PROC_NAME, lRet ) );
		
		goto err_osdelbp;				// ���顼����������
	}

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// �������֤������ѤǤʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		lRet = OSEENEXS;				// OSEENEXS������
		
		goto err_osdelbp;				// ���顼����������
	}

	if( ptBpIndAdr->lPoolId != poolid )	// �ס��뼱�̻Ҥ��оݸ������Υס��뼱�̻ҤȰ��פ��ʤ���
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		lRet = OSEENEXS;				// OSEENEXS������
		
		goto err_osdelbp;				// ���顼����������
	}

	if( ptBpIndAdr->lMaxUnitNum != ptBpIndAdr->lEmpUnitNum )
	{									// ������˥åȿ��ȥ�˥åȿ������פ��ʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEUSED ) );
		lRet = OSEEUSED;				// OSEEUSED������
		
		goto err_osdelbp;				// ���顼����������
	}

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	pvBpAdr = ptBpIndAdr->pvEbpcAdr;	// �Хåե��ס��륢�ɥ쥹�μ���
	lBpSize = ptBpIndAdr->lMaxUnitNum * (ptBpIndAdr->lUnitSize + D_UNITHEAD_SIZE);
										// �Хåե��ס��륵�����λ���
	pvPbAdr = ptBpIndAdr->tPbInfo.ptEpbcAdr;
										// �ס���Хåե����ɥ쥹�μ���
	lPbSize = ptBpIndAdr->tPbInfo.lPoolSize;
										// �ס���Хåե��������λ���
	ptEsbpIndTopAdr = (void *)ptEsbp + sizeof(TEsbpTable);
										// ���Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹�μ���

	ptEsbpIndBpAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// ���٤Ƥζ����Хåե��ס�������ơ��֥���������Ф��ƽ���
		if( ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr == (pvBpAdr + lBpSize) )
		{								// �����ΰ襢�ɥ쥹���Хåե��ס��륢�ɥ쥹�θ������ɥ쥹��
										// ���פ�������������Ĥ��ä���
			ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
			break;						// �롼�פ���ȴ����
		}
	}
	if( ptEsbpIndBpAdr == D_ADDRESS_NONE )
										//  �����ΰ褬��������������Ĥ���ʤ��ä���
	{
		for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
		{								// ̤���Ѥθ������θ���
			if( ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr == (TEsbpTableInd *)D_EMPBPADR_NOUSE )
			{							// ̤���Ѥθ����������Ĥ��ä���
				ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
				break;					// �롼�פ���ȴ����
			}
		}
		if( ptEsbpIndBpAdr != D_ADDRESS_NONE )
		{								// ̤���Ѥθ����������Ĥ��ä���
			ptEsbpIndBpAdr->pvEmpBpAdr = pvBpAdr;
										// �Хåե��ס�������ΰ賫�ϥ��ɥ쥹�μ���
			ptEsbpIndBpAdr->lEmpBpSize = lBpSize;
										// �Хåե��ס��륵�����μ���
		}
		else							// ̤���Ѥθ����������Ĥ���ʤ��ä���
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS );
			//return( -1 );				// -1���ֵѡʥ��ܡ���ͽ���
		}
	}
	else
	{
		ptEsbpIndBpAdr->pvEmpBpAdr = pvBpAdr;
										// �Хåե��ס�������ΰ賫�ϥ��ɥ쥹�ˡ�
										// �Хåե��ס��륢�ɥ쥹������
		ptEsbpIndBpAdr->lEmpBpSize += lBpSize;
										// �Хåե��ס�������ΰ襵�����ˡ�
										// �Хåե��ס��륵������û�
		for( ; ; )						// ���Ǥ�������ΰ褬�ʤ��ʤ�ޤǷ����֤�
		{
			for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
			{							// ���Ǥ�������ΰ�θ���
				if( (ptEsbpIndBpAdr->pvEmpBpAdr
						+ ptEsbpIndBpAdr->lEmpBpSize) == ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr )
				{						// ��縵�������θ������ɥ쥹�������ΰ�ΥХåե��ס���
										// ���ɥ쥹�Ȱ��פ�������������Ĥ��ä���
					ptEsbpIndBpAdr->lEmpBpSize += ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize;
										// ��縵�������Υ������˸��Ĥ��ä��������Υ�������û�
					ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr = (TEsbpTableInd *)D_EMPBPADR_NOUSE;
										// ���Ĥ��ä��������Υ��ɥ쥹�򥯥ꥢ
					ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize = D_EMPBPSIZE_NOUSE;
										// ���Ĥ��ä��������Υ������򥯥ꥢ
					break;				// �롼�פ���ȴ����
				}
			}
			if( iLoopCnt == ptEbpc->lMaxNum )
			{							// ���Ǥ�������ΰ褬���Ĥ���ʤ��ä���
				break;					// �롼�פ�ȴ����
			}
		}
	}

	ptEsbpIndPbAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// ���٤Ƥζ����Хåե��ס�������ơ��֥���������Ф��ƽ���
		if( ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr == (pvPbAdr + lPbSize) )
		{								// �����ΰ襢�ɥ쥹���ס���Хåե����ɥ쥹�θ������ɥ쥹��
										// ���פ�������������Ĥ��ä���
			ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
			break;						// �롼�פ���ȴ����
		}
	}

	if( ptEsbpIndPbAdr == D_ADDRESS_NONE )
										//  �����ΰ褬��������������Ĥ���ʤ��ä���
	{
		for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
		{								// ̤���Ѥθ������θ���
			if( ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr == (void *)D_EMPPBADR_NOUSE )
			{							// ̤���Ѥθ����������Ĥ��ä���
				ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
				break;					// �롼�פ���ȴ����
			}
		}
		if( ptEsbpIndPbAdr != D_ADDRESS_NONE )
		{								// ̤���Ѥθ����������Ĥ��ä���
			ptEsbpIndPbAdr->pvEmpEpbcAdr = pvPbAdr;
										// �ס���Хåե����������ΰ賫�ϥ��ɥ쥹�μ���
			ptEsbpIndPbAdr->lEmpEpbcSize = lPbSize;
										// �ס���Хåե��������μ���
		}
		else							// ̤���Ѥθ����������Ĥ���ʤ��ä���
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
			
			os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS1);
			//return( -1 );				// -1���ֵѡʥ��ܡ���ͽ���
		}
	}
	else
	{
		ptEsbpIndPbAdr->pvEmpEpbcAdr = pvPbAdr;
										// �ס���Хåե����������ΰ賫�ϥ��ɥ쥹�ˡ�
										// �ס���Хåե����ɥ쥹������
		ptEsbpIndPbAdr->lEmpEpbcSize += lPbSize;
										// �ס���Хåե����������ΰ襵�����ˡ�
										// �ס���Хåե���������û�
		for( ; ; )						// ���Ǥ�������ΰ褬�ʤ��ʤ�ޤǷ����֤�
		{
			for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
			{							// ���Ǥ�������ΰ�θ���
				if( (ptEsbpIndBpAdr->pvEmpEpbcAdr
						+ ptEsbpIndBpAdr->lEmpEpbcSize) == ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr )
				{						// ��縵�������θ������ɥ쥹�������ΰ�Υס���Хåե�
										// ���ɥ쥹�Ȱ��פ�������������Ĥ��ä���
					ptEsbpIndBpAdr->lEmpEpbcSize += ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize;
										// ��縵�������Υ������˸��Ĥ��ä��������Υ�������û�
					ptEsbpIndTopAdr[iLoopCnt].pvEmpEpbcAdr = (TEsbpTableInd *)D_EMPBPADR_NOUSE;
										// ���Ĥ��ä��������Υ��ɥ쥹�򥯥ꥢ
					ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize = D_EMPBPSIZE_NOUSE;
										// ���Ĥ��ä��������Υ������򥯥ꥢ
					break;				// �롼�פ���ȴ����
				}
			}
			if( iLoopCnt == ptEbpc->lMaxNum )
			{							// ���Ǥ�������ΰ褬���Ĥ���ʤ��ä���
				break;					// �롼�פ�ȴ����
			}
		}
	}

	ptBpIndAdr->cStat				= D_STAT_NOTCREATED;
	ptBpIndAdr->pvEbpcAdr			= D_ADDRESS_NONE;
	ptBpIndAdr->lMaxUnitNum			= 0;
	ptBpIndAdr->lEmpUnitNum			= 0;
	ptBpIndAdr->lUnitSize			= 0;
	ptBpIndAdr->lAccess				= 0;
	ptBpIndAdr->lGid				= 0;
	ptBpIndAdr->lGetEPBCNum			= 0;
	ptBpIndAdr->tPbInfo.ptNxtAdr	= D_ADDRESS_NONE;
	ptBpIndAdr->tPbInfo.ptBefAdr	= D_ADDRESS_NONE;
	ptBpIndAdr->tPbInfo.lPoolSize	= 0;
	ptBpIndAdr->tPbInfo.ptEpbcAdr	= D_ADDRESS_NONE;
										// �Хåե��ס�������ơ��֥�ι����ʥ��ꥢ��

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å����
		os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 2, -1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS2);
					return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSDELBP, D_T_TRA_OUT, 1, NORMAL  );
	return( NORMAL );					// NORMAL���ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_osdelbp:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	os_trcget2( D_MD_OSDELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
	for( ; ; )
	{
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å����
		os_trcget2( D_MD_OSDELBP, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSDELBP, D_T_ERR_SYS, 1 , errno );
					
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELBP << 16) | D_T_ERR_SYS3);
					//return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	os_trcget2( D_MD_OSDELBP, D_T_ERR_PRA, 1, lRet );

	return( lRet );						// ���顼�ͤ��ֵ�
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
