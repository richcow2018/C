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
/* ��⥸�塼��̾��					 �ס���Хåե��γ���										*/
/* ��⥸�塼��ɣġ�				 osfrpbf													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼����:�أأأ�)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*        �ס���Хåե��β���                                               */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*   long osfrpbf( long no, long *bufp[] )                                  */
/*																								*/
/* �㲾������																					*/
/*     long no             �ס���Хåե��Ŀ�                               */
/*     long *bufp[]        �ס���Хåե����ɥ쥹�ꥹ��                     */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			iFilId+1(iFilId�ϥե����뵭�һҥ��������)							*/
/*		�۾ｪλ			-1																	*/
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
#include "osfrpbf.h"
#include "osfrpbf_ins.h"				// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ���ס���Хåե��β���                                               */
/* ��������2002ǯ10��11��                                                   */
/* �ѹ�����                                                                 */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long osfrpbf( long no, long *bufp[] )                                  */
/*     long no             �ס���Хåե��Ŀ�                               */
/*     long *bufp[]        �ס���Хåե����ɥ쥹�ꥹ��                     */
/*                                                                          */
/****************************************************************************/
long osfrpbf( long no, long *bufp[] )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// ���ޥե���¤��
	int iRet;							// �ֵ���
	int iLoopCnt;						// �롼�ץ�����
	long lRet;							// �ֵ���
	long lBpSize;						// �Хåե��ס��륵����
	void *pvBpAdr;						// �Хåե��ס��륢�ɥ쥹
	TEbpcTableInd *ptBpIndTopAdr;		// �Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹
	TEbpcTableInd *ptBpIndAdr;			// �Хåե��ס�������ơ��֥�������Υ��ɥ쥹
	TEpbcTableInd *ptPbIndAdr;			// �ס���Хåե������ơ��֥�������Υ��ɥ쥹

	os_trcget2( D_MD_OSFRPBF, D_T_TRA_IN, 2, no, bufp );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s:no   = %ld \n", D_PROC_NAME, no ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:bufp = %08lx \n", D_PROC_NAME, (long)bufp[0] ) );
	os_trcget2( D_MD_OSFRPBF, D_MM_OSFRPBF, 1,bufp[0] );


	if( no < D_PBNUM_MIN )				// �ס���Хåե������Ǿ��ͤ�꾮������
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_PRA, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNO���ֵ�
	}

	ptBpIndTopAdr = (void *)ptEbpc + sizeof(TEbpcTable);
										// �Хåե��ס�������ơ��֥����������Ƭ���ɥ쥹����
	ptBpIndAdr = D_ADDRESS_NONE;
	for( iLoopCnt = 0; iLoopCnt < ptEbpc->lMaxNum; iLoopCnt++ )
	{									// ���٤ƤΥХåե��ס�������ơ��֥���������Ф��ƽ���
		pvBpAdr = ptBpIndTopAdr[iLoopCnt].pvEbpcAdr;
										// �Хåե��ס��륢�ɥ쥹�μ���
		lBpSize = ptBpIndTopAdr[iLoopCnt].lMaxUnitNum
					* (ptBpIndTopAdr[iLoopCnt].lUnitSize + D_UNITHEAD_SIZE);
										// �Хåե��ס��륵�����λ���
		if( ((void *)bufp[0] >= pvBpAdr)
			&& ((void *)bufp[0] <= (pvBpAdr + lBpSize)) )
		{								// �ס���Хåե����ɥ쥹(������)���������δ������λ�
			ptBpIndAdr = ptBpIndTopAdr + iLoopCnt;
										// ���Ĥ��ä������������
										/***** 20030317 SSLA0016 Start *****/
			lRet = os_ChkPB((void *)bufp[0], ptBpIndAdr);
			if(NORMAL != lRet)
			{
				return(lRet);
				break;
			}
										/***** 20030317 SSLA0016 End   *****/
			break;						// �롼�פ���ȴ����
		}
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr = %08lx \n", D_PROC_NAME, (long)ptBpIndAdr ) );

	if( ptBpIndAdr == D_ADDRESS_NONE )	// �ס���Хåե����ɥ쥹(������)���ɤθ������δ�����
	{									// �Ǥ�ʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIADR );
		return( OSEEIADR );				// OSEEIADR���ֵ�
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->cStat = %02x \n", D_PROC_NAME,
//			ptBpIndAdr->cStat ) );

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// �������֤������ѤǤʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENEXS ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEENEXS );
		return( OSEENEXS );				// OSEENEXS���ֵ�
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lMaxUnitNum = %ld \n", D_PROC_NAME,
//			ptBpIndAdr->lMaxUnitNum ) );

	if( no > ptBpIndAdr->lMaxUnitNum )	// �ס���Хåե������оݸ������Υ�˥åȿ�����礭����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNO���ֵ�
	}

//	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lEmpUnitNum = %ld \n", D_PROC_NAME,
//			ptBpIndAdr->lEmpUnitNum ) );

	if( no > (ptBpIndAdr->lMaxUnitNum - ptBpIndAdr->lEmpUnitNum) )
	{									// �ס���Хåե������оݸ������λ��ѥ�˥åȿ�����礭����
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
//		return( OSEEFLBF );				// OSEEFLBF���ֵ�
		os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIVNO );
		return( OSEEIVNO );				// OSEEIVNO���ֵ�
	}

	for( iLoopCnt = 1; iLoopCnt < no; iLoopCnt++ )
	{									// �ס���Хåե����ɥ쥹(�����ܰʹ�)�Υ����å�
		if( ((void *)bufp[iLoopCnt] < pvBpAdr)
			|| ((void *)bufp[iLoopCnt] > (pvBpAdr + lBpSize)) )
		{								// �ס���Хåե����ɥ쥹���������δ������ˤʤ���
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIADR ) );
			os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEIADR );
			return( OSEEIADR );			// OSEEIADR���ֵ�
		}
										/***** 20030317 SSLA0016 Start *****/
		lRet = os_ChkPB((void *)bufp[iLoopCnt], ptBpIndAdr);
		if(NORMAL != lRet)
		{
			return(lRet);
			break;
		}
										/***** 20030317 SSLA0016 End   *****/
		
	}


	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lPoolId     = %#08lx \n", D_PROC_NAME,
			ptBpIndAdr->lPoolId ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->pvEbpcAdr   = %#08lx \n", D_PROC_NAME,
			ptBpIndAdr->pvEbpcAdr ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lMaxUnitNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lMaxUnitNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lEmpUnitNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lEmpUnitNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lGetEPBCNum = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lGetEPBCNum ) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lUnitSize   = %ld \n", D_PROC_NAME,
			ptBpIndAdr->lUnitSize ) );

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å�
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ��å��Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, OSEEWKEX );
	        		return( OSEEWKEX );	// OSEEWKEX���ֵ�
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å�����
		{
			break;						// ������ȴ����
		}
	}
										// ����ס���Хåե��Υ�˥åȴ�������Υ����å�
	for( iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{
//		DbgMsg01(DLv04, (OutPut, "\n***** %s:Roop Count=%d ���� \n", D_PROC_NAME, (iLoopCnt+1)));

		os_trcget2( D_MD_OSFRPBF, D_MM_OSFRPBF, 1,bufp[iLoopCnt] );
										// �ס���Хåե������ơ��֥�������μ���
		ptPbIndAdr = *((TEpbcTableInd **)((void *)bufp[iLoopCnt] - 4));

/***********************************************/

		DbgMsg01(DLv04, (OutPut, "***** %s:bufp = %#08lx \n", D_PROC_NAME, bufp[iLoopCnt]));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr = %#08lx \n", D_PROC_NAME, ptPbIndAdr));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->pvUnitAdr = %#08lx \n", D_PROC_NAME,
				ptPbIndAdr->pvUnitAdr));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->lUsePid = %ld \n", D_PROC_NAME,
				ptPbIndAdr->lUsePid));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->lGetPid = %ld \n", D_PROC_NAME,
				ptPbIndAdr->lGetPid));

		DbgMsg01(DLv04, (OutPut, "***** %s:ptPbIndAdr->cUnit = %#02lx \n", D_PROC_NAME,
				ptPbIndAdr->cUnit));

		DbgMsg01(DLv04, (OutPut, "***** %s:lMyPid = %ld \n", D_PROC_NAME, lMyPid));
/***********************************************/
												// 20030115 ����

		if( ptPbIndAdr->cUnit != D_UNITINFO_GET )
		{								// ��˥åȾ��֤�������Ǥʤ���
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEALRD ) );
			lRet = OSEEALRD;			// OSEEALRD������
			goto err_osfrpbf;			// ���顼����������
		}

										// ���ѥץ���ID�ȼ����ץ���ID�����˼��ץ���ID�Ǥʤ���
		//if( (ptPbIndAdr->lGetPid != lMyPid) && (ptPbIndAdr->lUsePid != lMyPid) )
												// 20030226 SSLA0013 �����ѹ�
		if( ptPbIndAdr->lUsePid != lMyPid )
		{
//			DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->lGetPid = %lx \n", D_PROC_NAME,
//					ptPbIndAdr->lGetPid ) );
//			DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->lUsePid = %lx \n", D_PROC_NAME,
//					ptPbIndAdr->lUsePid ) );
//			DbgMsg01( DLv04, ( OutPut, "***** %s:lMyPid = %lx \n", D_PROC_NAME, lMyPid ) );
//			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEENFND ) );
			lRet = OSEENFND;			// OSEENFND������
			goto err_osfrpbf;			// ���顼����������
		}

	}

	for( iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// ����ס���Хåե��β���
		ptPbIndAdr = *((TEpbcTableInd **)((void *)bufp[iLoopCnt] - 4));
										// �ס���Хåե������ơ��֥�������μ���
		ptPbIndAdr->cUnit = D_UNITINFO_RELEASE;
										// ��˥åȾ��֤�����ˤ��롣
		ptPbIndAdr->lGetPid = D_PID_NONE;
										// �����ץ���ID�򥯥ꥢ���롣
		ptPbIndAdr->lUsePid = D_PID_NONE;
										// ���ѥץ���ID�򥯥ꥢ���롣
		if( ptBpIndAdr->tPbInfo.ptNxtAdr == D_ADDRESS_NONE )
		{								// ������˥åȤ�¸�ߤ��ʤ���
			DbgMsg01(DLv04, (OutPut, "***** %s: UNIT NASI\n", D_PROC_NAME ));
			ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndAdr;
										// �ס���Хåե���������μ����ɥ쥹�˲�������������������
			ptBpIndAdr->tPbInfo.ptBefAdr = (void *)ptPbIndAdr;
										// �ס���Хåե���������������ɥ쥹�˲�������������������
			ptPbIndAdr->ptNxtAdr = (void *)ptBpIndAdr;
										// ���������������μ����ɥ쥹�˥ס���Хåե���������
										// ���ɥ쥹������
			ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// ���������������������ɥ쥹�˥ס���Хåե���������
										// ���ɥ쥹������
		}
		else							// ������˥åȤ�¸�ߤ����
		{
			DbgMsg01(DLv04, (OutPut, "***** %s: UNIT ARI\n", D_PROC_NAME ));
			ptPbIndAdr->ptNxtAdr = ptBpIndAdr->tPbInfo.ptNxtAdr;
										// ���������������μ����ɥ쥹�˥ס���Хåե����������
										// �����ɥ쥹������
			ptPbIndAdr->ptBefAdr = (void *)ptBpIndAdr;
										// ���������������������ɥ쥹�˥ס���Хåե���������
										// ���ɥ쥹������
			((TEpbcTableInd *)ptBpIndAdr->tPbInfo.ptNxtAdr)->ptBefAdr = (void *)ptPbIndAdr;
										// ���������������μ����ɥ쥹���ؤ��������������ɥ쥹��
										// ��������������������
			ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndAdr;
										// �ס���Хåե���������μ����ɥ쥹�˲�������������������
		}
		++(ptBpIndAdr->lEmpUnitNum);	// ������˥åȿ��򥤥󥯥����
		--(ptBpIndAdr->lGetEPBCNum);	// �ס���Хåե��������Υǥ������
	}

	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å����
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 2, -1 , errno );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSFRPBF << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s: ID:%08lx ALL:%ld EMP:%ld GET:%ld\n", D_PROC_NAME,
			ptBpIndAdr->lPoolId,ptBpIndAdr->lMaxUnitNum, 
                        ptBpIndAdr->lEmpUnitNum, ptBpIndAdr->lGetEPBCNum ) );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSFRPBF, D_T_TRA_OUT, 1, NORMAL );
	return( NORMAL );					// NORMAL���ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_osfrpbf:
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å����
		os_trcget2( D_MD_OSFRPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 2, -1 , errno );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCONN << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}
	
	os_trcget2( D_MD_OSFRPBF, D_T_ERR_SYS, 1, lRet );
	return( lRet );						// ���顼�ͤ��ֵ�
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
