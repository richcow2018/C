/************************************************************************************************/
/* ��ƽз����� 																				*/
/*		#include	"os_endSystem.h"															*/
/*																								*/
/*		long	os_endSystem(void)																*/
/*																								*/
/* �㲾������																					*/
/*		long lShmId �ơ��֥��Ǽ��ͭ����ID													*/
/*																								*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ																				*/
/*			NORMAL																				*/
/*																								*/
/*		�ʾ彪λ																				*/
/*			OSERRARG	�����۾�																*/
/*			OSERRESMC	��ͭ��������ơ��֥뽪λ�۾�											*/
/*			OSERREMBC	�᡼��ܥå��������ơ��֥뽪λ�۾�										*/
/*			OSERREBPC	�Хåե��ס�������ơ��֥뽪λ�۾�										*/
/*			OSERRETRD	TRADE�ơ��֥�����ơ��֥뽪λ�۾�										*/
/*			OSERRSHMCTL	�ơ��֥��Ǽ�ΰ賫���۾�												*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	moa�ν�λ�����ǤΤ߻��Ѳ�ǽ�Ȥ��롣															*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	�㵡ǽ���ס� 																				*/
/*		�����ƥ����Τǻ��Ѥ��Ƥ���ơ��֥�γ�����Ԥ�											*/
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
#include <sys/sem.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_endSystem.h"
#include "os_endSystem_ins.h"


long os_endSystem(long lShmId)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lRes = 0;
	long lErrFlg = NORMAL;

	struct sigaction new[D_MAX_SIG_NUM];	// D_MAX_SIG_NUM�����ꥷ���ʥ��:31
	int iSigCnt = 0;
	
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endSystem\n"));
	os_trcget2(D_MD_OS_ENDSYSTEM, D_T_TRA_IN, 1, lShmId );
	
	//	���������å�
	if(0 == lShmId)
	{
		//	�۾����
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endSystem" ) );
		return(OSERRARG);
	}

/****************************************/
/*	�ܽ���								*/
/****************************************/
	//	�ƥơ��֥�ν�λ����
	//	��ͭ��������ơ��֥�ν�λ
	DbgMsg01( DLv03, ( OutPut, "***** In os_endESMC\n"));
	lRes = os_endESMC();
	if(NORMAL != lRes)
	{
		//	�۾����
		DbgMsg01( DLv05, ( OutPut, "***** Err02:%s\n", "os_endSystem" ) );
		//return(OSERRESMC);
		lErrFlg = OSERRESMC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endESMC\n"));
	
	//	�᡼��ܥå��������ơ��֥�ν�λ
	DbgMsg01( DLv03, ( OutPut, "***** In os_endEMBC\n"));
	lRes = os_endEMBC();
	if(NORMAL != lRes)
	{
		//	�۾����
		DbgMsg01( DLv05, ( OutPut, "***** Err03:%s\n", "os_endSystem" ) );
		//return(OSERREMBC);
		lErrFlg = OSERREMBC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endEMBC\n"));
	
	//	�Хåե��ס�������ơ��֥�ν�λ
	DbgMsg01( DLv03, ( OutPut, "***** In os_endEBPC\n"));
	lRes = os_endEBPC();
	if(NORMAL != lRes)
	{
		//	�۾����
		DbgMsg01( DLv05, ( OutPut, "***** Err04:%s\n", "os_endSystem" ) );
		//return(OSERREBPC);
		lErrFlg = OSERREBPC;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endEBPC\n"));
	
	//	TRADE�ơ��֥�����ơ��֥�ν�λ
	DbgMsg01( DLv03, ( OutPut, "***** In os_endTrade\n"));
	lRes = os_endTrade();
	if(NORMAL != lRes)
	{
		//	�۾����
		DbgMsg01( DLv05, ( OutPut, "***** Err05:%s\n", "os_endSystem" ) );
		//return(OSERRETRD);
		lErrFlg = OSERRETRD;
	}
	DbgMsg01( DLv03, ( OutPut, "***** Out os_endTrade\n"));
	
	//	�ơ��֥��Ǽ�ΰ�γ���
	DbgMsg01( DLv04, ( OutPut, "***** ��ͭ����γ�������\n"));
	lRes = shmctl( (int)lShmId, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err06:%s:%s\n", strerror(errno), "os_endSystem" ) );
			//return(OSERRSHMCTL);
			lErrFlg = OSERRSHMCTL;
		}
	}
	DbgMsg01( DLv04, ( OutPut, "***** ��ͭ����γ�����λ\n"));
	
	lRes = os_endSG();
	if(NORMAL != lRes)
	{
		lErrFlg = lRes;
	}
	
	lRes = os_freeSG();
	if(NORMAL != lRes)
	{
		lErrFlg = lRes;
	}
												// �������ʥ��ǥե���Ȥ��᤹
	for(iSigCnt = 0; iSigCnt < D_MAX_SIG_NUM ; iSigCnt++)
	{
		new[iSigCnt].sa_handler = SIG_DFL;
		new[iSigCnt].sa_flags = 0;
		sigaction(iSigCnt + 1, &(new[iSigCnt]), NULL);
	}

/****************************************/
/*	��λ����							*/
/****************************************/
	os_trcget2(D_MD_OS_ENDSYSTEM, D_T_TRA_OUT, 0 );
	DbgMsg01( DLv02, ( OutPut, "***** End os_endSystem\n"));
	
	//return(NORMAL);
	return(lErrFlg);

}


/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ��ƽз����� 																				*/
/*																								*/
/*		long	os_endEsmc(void)																*/
/*																								*/
/* �㲾������																					*/
/*		�ʤ�																					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ																				*/
/*			NORAML																				*/
/*		�۾ｪλ																				*/
/*			OSERRARG	�����۾�																*/
/*			OSERRSHMCTL	��ͭ���곫���۾�														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		os_endSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���													*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	�㵡ǽ���ס�  																				*/
/*		��ͭ��������ơ��֥���ΰ���������������Բ�ǽ�ʾ��֤ˤ��롣						*/
/*																								*/
/************************************************************************************************/

long os_endESMC(void)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TEsmcTableInd *ptEsmcInd = NULL;
	TEsmcTableInd *ptEsmcIndTemp = NULL;
	long lCnt = 0;
	long lRes = 0;
	long lMaxNum = 0;
	long lErrFlg = NORMAL;
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endESMC\n"));
	
	if(NULL == ptEsmc)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endESMC" ) );
		return(OSERRARG);
	}

/****************************************/
/*	�ܽ���								*/
/****************************************/
	ptEsmcInd = (TEsmcTableInd *)(ptEsmc + 1);
	
	lMaxNum = ptEsmc->lIndPartNum;
	
	for(lCnt = 0; lCnt < lMaxNum; lCnt++)
	{
		ptEsmcIndTemp = ptEsmcInd + lCnt;
		
		if(0 != ptEsmcIndTemp->lShmId)
		{
			lRes = shmctl(ptEsmcIndTemp->lShmId, IPC_RMID, NULL);
			if(NORMAL != lRes)
			{
				if( (EIDRM != errno) && (EINVAL != errno) )
				{
					DbgMsg01( DLv04, ( OutPut, "***** ptEsmcInd[%ld]->lShmId:%ld\n",
								lCnt, ptEsmcIndTemp->lShmId));
					DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n", strerror(errno),
								"os_endESMC" ) );
					//return(OSERRSHMCTL);
					lErrFlg = OSERRSHMCTL;
				}
			}
		}
	}
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endESMC\n"));
	
	//return(NORMAL);
	return(lErrFlg);

}

/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ��ƽз����� 																				*/
/*																								*/
/*		long	os_endEMBC(void)																*/
/*																								*/
/* �㲾������																					*/
/*		�ʤ�																					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ																				*/
/*			NORMAL																				*/
/*		�۾ｪλ																				*/
/*			OSWRRARG	�����۾�																*/
/*			OSERRSEMCTL	���ޥե�ID����۾�														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		os_endSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ��롣												*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	�㵡ǽ���ס�  																				*/
/*		�ᥤ��ܥå��������ơ��֥���ΰ���������������Բ�ǽ���֤ˤ��롣						*/
/*																								*/
/************************************************************************************************/

long os_endEMBC(void)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lRes = 0;
	long lErrFlg = NORMAL;
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endEMBC\n"));
	
	if(NULL == ptEmbc)							// ���������å�
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endEMBC" ) );
		return(OSERRARG);
	}
	
/****************************************/
/*	�ܽ���								*/
/****************************************/
	/*--------------------------------------*/
	/*  ����������ν����                  */
	/*--------------------------------------*/
	lRes = semctl(ptEmbc->lSemId, 0, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n", strerror(errno), "os_endEMBC" ) );
			//return(OSERRSEMCTL);
			lErrFlg = OSERRSEMCTL;
		}
	}
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endEMBC\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ��ƽз����� 																				*/
/*																								*/
/*		long	os_endEBPC(void)																*/
/*																								*/
/* �㲾������																					*/
/*		�ʤ�																					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		OSERRARG	�����۾�																	*/
/*		OSERRSEMCTL	���ޥե�ID����۾�															*/
/*		OSERRSHMCTL	��ͭ�������۾�															*/
/*																								*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		os_endSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���													*/
/*																								*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	�㵡ǽ���ס�  																				*/
/*		�Хåե��ס�������ơ��֥���ΰ���������������Բ�ǽ�ʾ��֤ˤ��롣					*/
/*																								*/
/************************************************************************************************/

long os_endEBPC(void)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	TEbpcTableInd *ptEbpcInd = NULL;			// EBPC��������
	TEbpcTableInd *ptEbpcIndTemp = NULL;		// EBPC�����������
	long lRes = 0;
	long lCnt = 0;
	long lMaxKbt = 0;
	long lErrFlg = NORMAL;
	
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endEBPC\n"));
	
	if(NULL == ptEbpc)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endEBPC" ) );
		return(OSERRARG);
	}
	
	ptEbpcInd = (TEbpcTableInd *)(ptEbpc + 1);	//	EBPC�����������

/****************************************/
/*	�ܽ���								*/
/****************************************/
	/*----------------------------------------*/
	/*  �������ν����                        */
	/*----------------------------------------*/
	lMaxKbt = ptEbpc->lMaxNum;					//	���������������

	for(lCnt = 0; lCnt < lMaxKbt; lCnt++)
	{
		ptEbpcIndTemp = ptEbpcInd + lCnt;
		if(0 != ptEbpcIndTemp->lSemId)
		{
			//	���ޥե�ID��¸�ߤ�����ϥ��ޥե��ν����
			lRes = semctl(ptEbpcIndTemp->lSemId, 0,IPC_RMID, NULL);
			if( NORMAL != lRes)
			{
				if( (EIDRM != errno) && (EINVAL != errno) )
				{
					DbgMsg01( DLv05, ( OutPut, "***** Err02:%s:%s\n",
							strerror(errno), "os_endEBPC" ) );
					//return(OSERRSEMCTL);
					lErrFlg = OSERRSEMCTL;
				}
			}
		}
	}
	/*----------------------------------------*/
	/*  �������ν����                        */
	/*----------------------------------------*/
	lRes = shmctl(ptEbpc->lShmId, IPC_RMID, NULL);	// ��ͭ����κ��
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err03:%s:%s\n", strerror(errno), "os_endEBPC" ) );
			//return(OSERRSHMCTL);
			lErrFlg = OSERRSHMCTL;
		}
	}
	
	lRes = semctl(ptEbpc->lSemId, 0, IPC_RMID, NULL);
	if(NORMAL != lRes)
	{
		if( (EIDRM != errno) && (EINVAL != errno) )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err04:%s:%s\n", strerror(errno), "os_endEBPC" ) );
			//return(OSERRSEMCTL);
			lErrFlg = OSERRSEMCTL;
		}
	}
	
/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endEBPC\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/

/************************************************************************************************/
/* ��ƽз����� 																				*/
/*																								*/
/*		long	os_endTrade(void)																*/
/*																								*/
/* �㲾������																					*/
/*		�ʤ�																					*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ																				*/
/*			NORMAL																				*/
/*		�۾ｪλ																				*/
/*			OSERRARG																			*/
/*			OSERRSEMCTL																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		os_endSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���													*/
/*																								*/
/************************************************************************************************/
/*																								*/
/*	�㵡ǽ���ס�  																				*/
/*		TRADE�ơ��֥�����ơ��֥���ΰ�������������Ѳ�ǽ�ʾ��֤ˤ���							*/
/*																								*/
/************************************************************************************************/

long os_endTrade(void)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lRes = 0;
	long lCnt = 0;
	long laSemId[MAX_DEL_SIZE];			//	���ޥե�ID��Ǽ����
	long lErrFlg = NORMAL;
/****************************************/
/*	�������							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** Start os_endTrade\n"));
	//	���������å�
	if(NULL == ptEtrd)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err01:%s\n", "os_endTrade" ) );
		return(OSERRARG);
	}
	
		//	�ƥơ��֥�Υ��ޥե�ID���Ǽ
	laSemId[0] = ptEtrd->tTrdEPRC.lSemId;
	laSemId[1] = ptEtrd->tTrdEBPC.lSemId;
	laSemId[2] = ptEtrd->tTrdESBP.lSemId;
	laSemId[3] = ptEtrd->tTrdEPBC.lSemId;
	laSemId[4] = ptEtrd->tTrdEMBC.lSemId;
	laSemId[5] = ptEtrd->tTrdEMMC.lSemId;
	laSemId[6] = ptEtrd->tTrdESMC.lSemId;
	
/****************************************/
/*	�ܽ���								*/
/****************************************/
	for(lCnt = 0; lCnt < MAX_DEL_SIZE; lCnt++)
	{
		DbgMsg01( DLv05, ( OutPut, "***** ���ޥե�ID : %ld\n", laSemId[lCnt]));
		lRes = semctl(laSemId[lCnt],0,IPC_RMID, NULL);
		if(NORMAL != lRes)
		{
			if( (EIDRM != errno) || (EINVAL != errno) )
			{
				DbgMsg01( DLv05, ( OutPut, "***** laSemId[%ld]:%ld\n", lCnt, laSemId[lCnt]));
				DbgMsg01( DLv05, ( OutPut, "***** Err02:%s :%s\n", strerror(errno),"os_endTrade"));
				//return(OSERRSEMCTL);
				lErrFlg = OSERRSEMCTL;
			}
		}
	}

/****************************************/
/*	��λ����							*/
/****************************************/
	DbgMsg01( DLv02, ( OutPut, "***** End os_endTrade\n"));
	//return(NORMAL);
	return(lErrFlg);
}
/************************************************************************************************/
/*	End																							*/
/************************************************************************************************/
