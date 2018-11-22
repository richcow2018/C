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
/* ��⥸�塼��ɣġ�				 osgtpbf													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤��̣)				*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�����ѹ��ֹ�ʣӣӣ̣�����������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/* ��ǽ���ס���Хåե��γ���                                               					*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osgtpbf.h>																	*/
/*																								*/
/*   long osgtpbf( long poolid, long no, long *bufp[] )                     					*/
/*																								*/
/* �㲾������																					*/
/*     long poolid         �ס��뼱�̻�                                     					*/
/*     long no             �ס���Хåե��Ŀ�                               					*/
/*     long *bufp[]        �ס���Хåե����ɥ쥹�ꥹ��                     					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEACCV		���ɥ쥹�۾郎ȯ��������								*/
/*						OSEEFLBF		�Хåե��ס���˶������ʤ���							*/
/*						OSEEIPLI		�ס��뼱�̻Ҥ������Ǥ��롣								*/
/*						OSEEIPOL		�ס���Хåե���̤�������֤Ǥ��롣						*/
/*						OSEEIVNO		�ס���Хåե��θĿ��������Ǥ��롣						*/
/*						OSEENEXS		�ס���Хåե����̻Ҥ����֤�SG�ϰϤ�Ķ���Ƥ��ơ�		*/
/*										¸�ߤ��ʤ���											*/
/*						OSEENMAP		�Хåե��ס����ޥåԥ󥰤��Ƥ��ʤ���					*/
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
/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "osgtpbf.h"
#include "osgtpbf_ins.h"				// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ���ס���Хåե��γ���                                               */
/* ��������2002ǯ10��10��                                                   */
/* �ѹ�����                                                                 */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long osgtpbf( long poolid, long no, long *bufp[] )                     */
/*     long poolid         �ס��뼱�̻�                                     */
/*     long no             �ס���Хåե��Ŀ�                               */
/*     long *bufp[]        �ס���Хåե����ɥ쥹�ꥹ��                     */
/*                                                                          */
/****************************************************************************/
long osgtpbf( long poolid, long no, long *bufp[] )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	struct sembuf tSembuf;				// ���ޥե���¤��
	int iRet;							// �ֵ���
	int iLoopCnt;						// �롼�ץ�����
	long lRet;							// �ֵ���
	long lBpSize;						// �Хåե��ס��륵����
	TEbpcTableInd *ptBpIndAdr;			// �Хåե��ס�������ơ��֥�������Υ��ɥ쥹
	TEpbcTableInd *ptPbIndAdr;			// �ס���Хåե������ơ��֥�������Υ��ɥ쥹
	TEpbcTableInd *ptPbIndNxtAdr;		// �ס���Хåե������ơ��֥�������Υ��ɥ쥹�ʼ����ɥ쥹��
	TEpbcTableInd *ptPbIndTmpAdr;		// �ס���Хåե������ơ��֥�������Υ��ɥ쥹�ʰ�����ѡ�
	void *pvBpAdr = NULL;				// �Хåե��ס��륢�ɥ쥹
/*****	�����ѹ��ֹ�SSLA0035���б�		Start							��������2003.07.04	*****/
	struct	timeval		tTmVal;			// ���ּ����ѹ�¤��
/*****	�����ѹ��ֹ�SSLA0035���б�		 End							��������2003.07.04	*****/

	os_trcget2( D_MD_OSGTPBF, D_T_TRA_IN, 3, poolid, no, bufp );

//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	�оݸ��������ɥ쥹�μ���					*/
	/************************************************/
	lRet = os_GetEbpcTableInd( poolid, (void **)&ptBpIndAdr );
										// �Хåե��ס�������ơ��֥뤫���оݸ��������ɥ쥹�μ���
	if( lRet != NORMAL )				// �оݸ������Υ��ɥ쥹�μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, lRet ) );
		
		os_trcget2( D_MD_OSGTPBF,  D_T_ERR_PRA, 1, lRet );
		
		return( lRet );					// �ֵ��ͤ��ֵ�
	}

	/************************************************/
	/*	�Хåե��ס���������Υ�å�				*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_LOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å�
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 1, iRet );
										
		if( iRet == D_ERR_SYS )
		{								// ��å��Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
					                                                 D_PROC_NAME, OSEEWKEX ) );
					                                                 
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 1, OSEEWKEX );                                                 
					                                                 
	        		return( OSEEWKEX );	// OSEEWKEX���ֵ�
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å�����
		{
			break;						// ������ȴ����
		}
	}

	/************************************************/
	/*	�ס���Хåե����Υ����å�					*/
	/************************************************/
	if( no < D_PBNUM_MIN )				// �ס���Хåե������Ǿ��ͤ�꾮������
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		lRet = OSEEIVNO;				// OSEEIVNO������
		goto err_osgtpbf;				// ���顼����������
	}

	if( no > ptBpIndAdr->lMaxUnitNum )	// �ס���Хåե������оݸ������Υ�˥åȿ�����礭����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIVNO ) );
		lRet = OSEEIVNO;				// OSEEIVNO������
		goto err_osgtpbf;				// ���顼����������
	}

	if( no > ptBpIndAdr->lEmpUnitNum )	// �ס���Хåե������оݸ������ζ�����˥åȿ�����礭����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEFLBF ) );
		lRet = OSEEFLBF;				// OSEEFLBF������
		goto err_osgtpbf;				// ���顼����������
	}

	if( ptBpIndAdr->cStat != D_STAT_CREATED )
	{									// �������֤������ѤǤʤ���
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEIPOL ) );
		lRet = OSEEIPOL;				// OSEEIPOL������
		goto err_osgtpbf;				// ���顼����������
	}

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	lBpSize = ptBpIndAdr->lMaxUnitNum * (ptBpIndAdr->lUnitSize + D_UNITHEAD_SIZE);
										// �Хåե��ס��륵�����λ���

	/************************************************/
	/*	��˥åȥ��ɥ쥹���ϰϥ����å�				*/
	/************************************************/
	ptPbIndAdr = (void *)ptBpIndAdr->tPbInfo.ptNxtAdr;
										// ��Ƭ�Υ�˥åȥ��ɥ쥹�����
										
	for(iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// ����Ŀ��Υ�˥åȥ��ɥ쥹���ϰϥ����å�
		if( (ptPbIndAdr->pvUnitAdr < ptBpIndAdr->pvEbpcAdr)
			|| (ptPbIndAdr->pvUnitAdr > ptBpIndAdr->pvEbpcAdr + lBpSize) )
		{								// ��˥åȥ��ɥ쥹���Хåե��ס����ϰ���Ǥʤ���
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEEACCV ) );
			lRet = OSEEACCV;			// OSEEACCV������
			goto err_osgtpbf;			// ���顼����������
		}
		ptPbIndAdr = (TEpbcTableInd *)ptPbIndAdr->ptNxtAdr;
										// ����˥åȥ��ɥ쥹�����
	}

	/************************************************/
	/*	�Хåե��ס������������������				*/
	/************************************************/
	ptPbIndNxtAdr = ptPbIndAdr;			// ����˥åȥ��ɥ쥹������ʿ�������˥åȤȤʤ��
	ptPbIndAdr = (void *)ptBpIndAdr->tPbInfo.ptNxtAdr;
										// ��Ƭ�Υ�˥åȥ��ɥ쥹�����
	ptBpIndAdr->tPbInfo.ptNxtAdr = (void *)ptPbIndNxtAdr;
										// ���򤷤���������˥åȥ��ɥ쥹������
	if( (void *)ptBpIndAdr->tPbInfo.ptNxtAdr == (void *)ptBpIndAdr )
	{									// ��������˥åȤ��ʤ����ʶ�����˥åȤ��ʤ�����
		ptBpIndAdr->tPbInfo.ptNxtAdr = D_ADDRESS_NONE;
										// �Хåե��ס����������μ����ɥ쥹�򥯥ꥢ
		ptBpIndAdr->tPbInfo.ptBefAdr = D_ADDRESS_NONE;
										// �Хåե��ס����������������ɥ쥹�򥯥ꥢ
	}
	else								// ��������˥åȤ�������ʶ�����˥åȤ��������
	{
		((TEpbcTableInd *)(ptBpIndAdr->tPbInfo.ptNxtAdr))->ptBefAdr = (void *)ptBpIndAdr;
										// ��������˥åȤ������ɥ쥹�˥Хåե��ס����������
										// ���ɥ쥹������
	}

	for(iLoopCnt = 0; iLoopCnt < no; iLoopCnt++ )
	{									// ����Ŀ��Υ�˥åȤγ���
		ptPbIndTmpAdr = (TEpbcTableInd *)ptPbIndAdr->ptNxtAdr;
										// ���Υ�˥åȥ��ɥ쥹������
		bufp[iLoopCnt] = ptPbIndAdr->pvUnitAdr;
										// �ס���Хåե����ɥ쥹�ꥹ�Ȥ˥�˥åȥ��ɥ쥹������
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptPbIndAdr->pvUnitAdr:%08lx\n",
				 D_PROC_NAME, ptPbIndAdr->pvUnitAdr ) );

		os_trcget2( D_MD_OSGTPBF, D_MM_OSGTPBF, 1,ptPbIndAdr->pvUnitAdr );

		--(ptBpIndAdr->lEmpUnitNum);	// ������˥åȿ��Υǥ������
		++(ptBpIndAdr->lGetEPBCNum);	// �ס���Хåե��������Υ��󥯥����

/*****	�����ѹ��ֹ�SSLA0035���б�		Start							��������2003.07.04	*****/
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lGetEPBCNum=%08lx\n",
				 D_PROC_NAME, ptBpIndAdr->lGetEPBCNum ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s:ptBpIndAdr->lPeakCnt=%08lx\n",
				 D_PROC_NAME, ptBpIndAdr->lPeakCnt ) );
										// �ס���Хåե�������������ԡ�������Ķ�ᤷ�����
		if (ptBpIndAdr->lGetEPBCNum > ptBpIndAdr->lPeakCnt)
		{
			/****************************************/
			/*  ����ԡ������Ⱥ���ԡ������֤ε�Ͽ	*/
			/****************************************/
			os_trcget2( D_MD_OSGTPBF, D_T_SYS_GETTIMEOFDAY, 2, &tTmVal, NULL );
			gettimeofday(&tTmVal, NULL);// ���֤����
			os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 1, tTmVal.tv_sec);

			DbgMsg01( DLv04, ( OutPut, "***** %s:tTmVal.tv_sec=%d\n",
				 	D_PROC_NAME, tTmVal.tv_sec ) );

										// ����ԡ������˥ס���Хåե�������������
			ptBpIndAdr->lPeakCnt = ptBpIndAdr->lGetEPBCNum;
										// ����ԡ������֤˼����������֡��áˤ�����
			ptBpIndAdr->lPeakTime = tTmVal.tv_sec;
			os_trcget2( D_MD_OSGTPBF, D_MM_OSGTPBF, 2, ptBpIndAdr->lPeakCnt, ptBpIndAdr->lPeakTime);
		}
/*****	�����ѹ��ֹ�SSLA0035���б�		 End							��������2003.07.04	*****/

		ptPbIndAdr->cUnit = D_UNITINFO_GET;
										// ��˥åȾ��֤ˡּ����פ�����
		ptPbIndAdr->lGetPid = lMyPid;
										// �����ץ����ɣĤ˼��ץ����ɣĤ�����
		ptPbIndAdr->lUsePid = lMyPid;
										// ���ѥץ����ɣĤ˼��ץ����ɣĤ�����
		ptPbIndAdr->ptNxtAdr = D_ADDRESS_NONE;
										// �����ɥ쥹�򥯥ꥢ
		ptPbIndAdr->ptBefAdr = D_ADDRESS_NONE;
										// 20030305 �ɲ�
										// ��˥åȴ����ΰ襢�ɥ쥹�˴������󥢥ɥ쥹�ɲ�
		*((long *)(ptPbIndAdr->pvUnitAdr - 4)) = (long)ptPbIndAdr;
										// �����ɥ쥹�򥯥ꥢ
		ptPbIndAdr = ptPbIndTmpAdr;		// ���Υ�˥åȤ˰�ư
	}

	/************************************************/
	/*	�Хåե��ס���������Υ�å����			*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å����
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 2, -1 , errno ); 
					
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
	        		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTPBF << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s:ID:%08lx ALL:%ld EMP:%ld GET:%ld\n", D_PROC_NAME,
			ptBpIndAdr->lPoolId,ptBpIndAdr->lMaxUnitNum, 
                        ptBpIndAdr->lEmpUnitNum, ptBpIndAdr->lGetEPBCNum ) );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSGTPBF, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMAL���ֵ�

/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_osgtpbf:
	/************************************************/
	/*	�Хåե��ס���������Υ�å����			*/
	/************************************************/
	tSembuf.sem_num	= D_SEMNUM_NONE;
	tSembuf.sem_op	= D_SEMOP_UNLOCK;
	tSembuf.sem_flg	= SEM_UNDO;
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_SEMOP, 3, ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
		iRet = semop( ptBpIndAdr->lSemId, &tSembuf, D_SEM_NSOPS );
										// �Хåե��ס���������Υ�å����
		os_trcget2( D_MD_OSGTPBF, D_T_SYS_END, 2, iRet, errno );
										
		if( iRet == D_ERR_SYS )
		{								// ��å�����Ǥ��ʤ��ä���
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					break;				// ��ȥ饤
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, -1 ) );
					
					os_trcget2( D_MD_OSGTPBF,  D_T_ERR_SYS, 2, -1 , errno );     
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGTPBF << 16) | D_T_ERR_SYS1);
	        		//return( -1 );		// -1���ֵѡʥ��ܡ��Ƚ�����ͽ���
	        }
		}
		else							// �Хåե��ס��륢�������Υ�å��������
		{
			break;						// ������ȴ����
		}
	}

	os_trcget2( D_MD_OSGTPBF,  D_T_ERR_PRA, 1, lRet );     

	return( lRet );						// ���顼�ͤ��ֵ�
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
