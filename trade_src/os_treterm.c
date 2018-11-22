/************************************************************************************************/
/* ��ƽз�����                                                                                 */
/*      #include    "os_tretrm.h"                                                               */
/*                                                                                              */
/*      void    os_treterm(long lEndCod, long lDetailCode)                                      */
/*                                                                                              */
/* �㲾������                                                                                   */
/*      long lEndCod����λ������                                                                */
/*      long lDetailCode���ܺپ���                                                              */
/*                                                                                              */
/* ���ֵ��͡�                                                                                   */
/*      ̵��                                                                                    */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/*                                                                                              */
/* �����»����                                                                                 */
/*  TRADE�����Ǥ�����Ū�ʰ۾ｪλ������                                                         */
/************************************************************************************************/
#include "os_treterm.h"
#include "os_treterm_ins.h"

void os_treterm(long lEndCod, long lDetailCode)
{
	/******************/
	/*    �ѿ����    */
	/******************/
	long lRes = 0;
	
	os_trcget2( D_MD_OS_TRETERM, D_T_TRA_IN, 2, lEndCod, lDetailCode );
	/* ���������å� */
	
	if(ptMyEPRC == NULL)
	{
		os_trcget2( D_MD_OS_TRETERM, D_T_ERR_PRA, 0 );
		os_abort(lEndCod, lDetailCode, 1);		//core�ե�������������
	}
	
	/******************/
	/*     �ܽ���     */
	/******************/
	// ���ץ����ơ��֥� �־ܺپ���ס��ֽ�λ�����ɡפذ������ͤ��Ǽ
	
	ptMyEPRC->lEndCode = lEndCod;				// ��λ�����ɳ�Ǽ
	ptMyEPRC->lDetailCode = lDetailCode;		// �ܺپ����Ǽ

	os_trcget2( D_MD_OS_TRETERM, D_T_SYS_KILL, 2, lMyPid, SIGTERM);
	lRes = kill(lMyPid, SIGTERM);				// �����ʥ� kill(��pid, SIGTERM); ȯ��
	if(NORMAL != lRes)
	{
		os_trcget2( D_MD_OS_TRETERM, D_T_ERR_SYS, 1, errno);
		os_sigact(SIGTERM);						// kill����ʤ��ʤ�ľ�Ƥ�
	}
	
	/******************/
	/*    ��λ����    */
	/******************/
	os_trcget2( D_MD_OS_TRETERM, D_T_TRA_OUT, 0);
	do
	{
		lRes = pause();							// ̵�½����Ԥ���碌
	}while(1);

}

/************************************************************************************************/
/* ��λ                                                                                         */
/************************************************************************************************/
