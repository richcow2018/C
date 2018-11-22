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
/* �㥵���ӥ�����̾��				 �¹Դ���													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �̣ͥХåե��ס���κ���									*/
/* ��⥸�塼��ɣġ�				 oscrelbp													*/
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
/* �����ԡ���̣                                                             */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ10��3��                                                    */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �̣ͥХåե��ס���κ��� 																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscrelbp.h>																*/
/*																								*/
/*	   	long	oscrelbp( long poolid, long size, long unit, long access ) 						*/
/*																								*/
/* �㲾������																					*/
/*		long	poolid;		�ס��뼱�̻�														*/
/*		long	size;		�ס���Хåե��Ŀ�												*/
/*		long	unit		��˥åȥ�����														*/
/*		long	access;		����������															*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEWKEX																*/
/*						semop���ֵ���															*/
/*						-1																		*/
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
#include <unistd.h>
#include <errno.h>
#include "oscrelbp.h"
#include "os_trcget.h"
#include "oscrelbp_ins.h"				// ���������ѡʸ��̡�
#include "os_GetEbpcTableInd_ins.h"		// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ���̣ͥХåե��ס���κ���                                           */
/* ��������2002ǯ10��3��                                                    */
/* �ѹ�����                                                                 */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long oscrelbp( long poolid, long size, long unit, long access )        */
/*     long poolid         �ס��뼱�̻�                                     */
/*     long size           �ס���Хåե��Ŀ�                               */
/*     long unit           ��˥åȥ�����                                   */
/*     long access         ����������                                       */
/*                                                                          */
/****************************************************************************/
long oscrelbp( long poolid, long size, long unit, long access )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// ���ޥե���¤��
	int iRet;							// �ֵ���
	int iLoopCnt;						// �롼�ץ�����
	long lRet;							// �ֵ���
	long lUnitSize;						// ��˥åȥ�����
	long lNeedBpSize;					// ɬ�ץХåե��ס��륵����
	long lNeedPbSize;					// ɬ�ץס���Хåե�������
	void *pvBpAdr;						// �Хåե��ס��륢�ɥ쥹
	TEbpcTableInd *ptBpIndAdr;			// �Хåե��ס�������ơ��֥�������Υ��ɥ쥹
	TEsbpTableInd *ptEsbpIndTopAdr;		// ���Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹
	TEsbpTableInd *ptEsbpIndBpAdr;		// ���Хåե��ס�������ơ��֥�������Υ��ɥ쥹��BP�ѡ�
	TEsbpTableInd *ptEsbpIndPbAdr;		// ���Хåե��ס�������ơ��֥�������Υ��ɥ쥹��PB�ѡ�
	TEpbcTableInd *ptPbIndTopAdr;		// �ס���Хåե������ơ��֥����������Ƭ���ɥ쥹
	TEpbcTableInd *ptPbIndAdr;			// �ס���Хåե������ơ��֥�������Υ��ɥ쥹
	
	
	os_trcget2( D_MD_OSCRELBP, D_T_TRA_IN, 4, poolid, size, unit, access );

	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:poolid : %08lx \n", D_PROC_NAME, poolid));
	DbgMsg01( DLv04, ( OutPut, "***** %s:size   : %ld \n", D_PROC_NAME, size));
	DbgMsg01( DLv04, ( OutPut, "***** %s:unit   : %ld \n", D_PROC_NAME, unit));
	DbgMsg01( DLv04, ( OutPut, "***** %s:access : %lx \n", D_PROC_NAME, access));


	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å�
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
		
		if( iRet == D_ERR_SYS )
		{								// ��å��Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
																	D_PROC_NAME, OSEEWKEX ) );
																	
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 1, OSEEWKEX );
																	
	        		return( OSEEWKEX );	// OSEEWKEX���ֵ�
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å�����
		{
			break;						// ������ȴ����
		}
	}

	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// �Хåե��ס�������ơ��֥뤫���оݸ��������ɥ쥹�μ���
	if( lRet != NORMAL )				// �оݸ������Υ��ɥ쥹�μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%lx \n", D_PROC_NAME, lRet ) );
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

	if( ptBpIndAdr->cStat != D_STAT_NOTCREATED )
	{									// �������֤�̤�����Ǥʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEEXST ) );
		lRet = OSEEEXST;				// OSEEEXST������
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

	if( (size < D_SIZE_MIN) || (size > D_SIZE_MAX) )
	{									// �Хåե��ס��륵�������ϰϳ��Ǥ����
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEISIZ ) );
		lRet = OSEEISIZ;				// OSEEISIZ������
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

	if( (unit < D_UNIT_MIN) || (unit > D_UNIT_MAX) )
	{									// ��˥åȥ��������ϰϳ��Ǥ����
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIUNI ) );
		lRet = OSEEIUNI;				// OSEEIUNI������
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

										// ��˥åȥ��������ڤ�夲
	lUnitSize = ((long)((unit + D_ROUND_UNIT - 1) / D_ROUND_UNIT)) * D_ROUND_UNIT;
										// ɬ�ץХåե��ס��륵�����λ���
	lNeedBpSize = size * (lUnitSize + D_UNITHEAD_SIZE);

	DbgMsg01( DLv04, ( OutPut, "***** %s:llUnitSize :%ld \n", D_PROC_NAME, lUnitSize ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:lNeedBpSize:%ld \n", D_PROC_NAME, lNeedBpSize ) );

										// ���Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹�μ���
	ptEsbpIndTopAdr = (void *)ptEsbp + sizeof(TEsbpTable);
	ptEsbpIndBpAdr = D_ADDRESS_NONE;

										// �Хåե��ס����ɬ�פʶ����ΰ褬����������򸡺�
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{
		DbgMsg01( DLv04, ( OutPut, "***** %s:iLoopCnt:%d ���� \n", D_PROC_NAME, (iLoopCnt+1) ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr:%08lx \n",
				D_PROC_NAME, ptEsbpIndTopAdr[iLoopCnt].pvEmpBpAdr ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize:%ld \n",
				D_PROC_NAME, ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize ) );

		if( ptEsbpIndTopAdr[iLoopCnt].lEmpBpSize >= lNeedBpSize )
		{								//  �����ΰ褬��������������Ĥ��ä���
			ptEsbpIndBpAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
			break;						// �롼�פ���ȴ����
		}
	}
	if( ptEsbpIndBpAdr == D_ADDRESS_NONE )
	{									//  �����ΰ褬��������������Ĥ���ʤ��ä���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function 01:%x\n", D_PROC_NAME, OSEEINSF ) );
		lRet = OSEEINSF;				// OSEEINSF������
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

	lNeedPbSize = sizeof(TEpbcTableInd) * size;
										// ɬ�ץס���Хåե��������λ���
	ptEsbpIndPbAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++)
	{									// �ס���Хåե���ɬ�פʶ����ΰ褬����������򸡺�
		if( ptEsbpIndTopAdr[iLoopCnt].lEmpEpbcSize >= lNeedPbSize )
		{								//  �����ΰ褬��������������Ĥ��ä���
			ptEsbpIndPbAdr = ptEsbpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
			break;						// �롼�פ���ȴ����
		}
	}
	if( ptEsbpIndPbAdr == D_ADDRESS_NONE )
	{									//  �����ΰ褬��������������Ĥ���ʤ��ä���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function 02:%x\n", D_PROC_NAME, OSEEINSF ) );
		lRet = OSEEINSF;				// OSEEINSF������
		
		os_trcget2( D_MD_OSCRELBP, D_T_ERR_PRA, 1, lRet );
		
		goto err_oscrelbp;				// ���顼����������
	}

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptBpIndAdr->cStat				= D_STAT_CREATED;
	ptBpIndAdr->pvEbpcAdr			= ptEsbpIndBpAdr->pvEmpBpAdr;
	ptBpIndAdr->lMaxUnitNum			= size;
	ptBpIndAdr->lEmpUnitNum			= size;
	ptBpIndAdr->lUnitSize			= lUnitSize;
	ptBpIndAdr->lAccess				= access;
	ptBpIndAdr->lGid				= getpgrp();
	ptBpIndAdr->lGetEPBCNum			= 0;
	ptBpIndAdr->tPbInfo.ptNxtAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr;
	ptBpIndAdr->tPbInfo.ptBefAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr
										+ sizeof(TEpbcTableInd) * (size - 1);
	ptBpIndAdr->tPbInfo.lPoolSize	= lNeedPbSize;
	ptBpIndAdr->tPbInfo.ptEpbcAdr	= ptEsbpIndPbAdr->pvEmpEpbcAdr;
										// �Хåե��ס�������ơ��֥�ι���

	pvBpAdr = ptBpIndAdr->pvEbpcAdr;	// �Хåե��ס��륢�ɥ쥹�μ���
	ptPbIndTopAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptEpbcAdr;
										// �ס���Хåե������ơ��֥����������Ƭ���ɥ쥹����
	for( iLoopCnt = 0; iLoopCnt < size; iLoopCnt++ )
	{									// ���٤ƤΥס���Хåե������ơ��֥���������Ф��ƽ���
		ptPbIndAdr = ptPbIndTopAdr + iLoopCnt;
										// �ס���Хåե������ơ��֥���������ɥ쥹�μ���

		*((TEpbcTableInd **)pvBpAdr) = ptPbIndAdr;
										// ��˥åȴ�������˸��������ɥ쥹������
		pvBpAdr += D_UNITHEAD_SIZE;		// �ס���Хåե��ΰ襢�ɥ쥹�μ���

		(TEpbcTableInd *)ptPbIndAdr->ptNxtAdr	= ptPbIndAdr + 1;
		(TEpbcTableInd *)ptPbIndAdr->ptBefAdr	= ptPbIndAdr - 1;
		ptPbIndAdr->lGetPid						= D_PID_NONE;
		ptPbIndAdr->lUsePid						= D_PID_NONE;
		ptPbIndAdr->cUnit						= D_UNITINFO_RELEASE;
		ptPbIndAdr->pvUnitAdr					= pvBpAdr;
										// �ס���Хåե������ơ��֥�������ι���

		pvBpAdr += lUnitSize;			// �ס���Хåե��ΰ�κǸ������ɥ쥹�μ���
	}
	ptPbIndAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptNxtAdr;
	ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// ��Ƭ�������������ɥ쥹�ι���
	ptPbIndAdr = (TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptBefAdr;
	ptPbIndAdr->ptNxtAdr = (void *)ptBpIndAdr;
										// �ǽ��������μ����ɥ쥹�ι���

	ptEsbpIndBpAdr->pvEmpBpAdr += lNeedBpSize;
										// �Хåե��ס�������ΰ賫�ϥ��ɥ쥹�ˡ�
										// ɬ�ץХåե��ס��륵������û�
	ptEsbpIndBpAdr->lEmpBpSize -= lNeedBpSize;
										// �Хåե��ס�������ΰ襵�������顢
										// ɬ�ץХåե��ס��륵�����򸺻�
	(void *)ptEsbpIndPbAdr->pvEmpEpbcAdr += lNeedPbSize;
										// �ס���Хåե����������ΰ賫�ϥ��ɥ쥹�ˡ�
										// ɬ�ץס���Хåե���������û�
	ptEsbpIndPbAdr->lEmpEpbcSize -= lNeedPbSize;
										// �ס���Хåե����������ΰ襵�������顢
										// ɬ�ץס���Хåե��������򸺻�

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å����
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
		
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 2, -1 , errno );
					
	        		return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSCRELBP, D_T_TRA_OUT, 1, NORMAL  );
	
	return( NORMAL );					// NORMAL���ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_oscrelbp:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_SEMOP, 3, ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptEbpc->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס��륢�������Υ�å����
		os_trcget2( D_MD_OSCRELBP, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 2, -1 , errno );
					
	        		return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	os_trcget2( D_MD_OSCRELBP, D_T_ERR_SYS, 1, lRet );
	
	return( lRet );						// ���顼�ͤ��ֵ�
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
