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
/* �㥵���ӥ�����̾��				 ����������													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 ���勵���ޤ�����											*/
/* ��⥸�塼��ɣġ�				 osstdtim													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤�Ḷ)				*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ��������� 	�����ѹ��ֹ�ʣӣӣ̣�����������*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �����ѹ��ֹ�ʣӣӣ̣�����������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		rd�����ơ��֥��ERDC�ˤ���ꥯ�����ȼ��̻Ҥ��б������������������롣					*/
/*		���������������Υꥯ�����Ⱦ��֤�����å��������θ������򹹿����롣						*/
/*		�����ॢ���Ȼ��֤򻻽Ф�os_tmctl��ư���롣											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osstdtim.h>																*/
/*																								*/
/*   long ossdtim( long rd, long day, long time )                                               */
/*																								*/
/* �㲾������																					*/
/*     long rd             �ꥯ�����ȼ��̻�                                                     */
/*     long day            ����                                                                 */
/*     long time           ����                                                                 */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�ꥯ�����ȼ��̻�														*/
/*		�۾ｪλ		OSEEIVAL			�������ϡ�������ͤ������Ǥ��롣					*/
/*						OSEEIVRD			����rd��ͽ�󤵤�Ƥ��ʤ������ϡ��������ͤǤ��롣	*/
/*						OSEEUSED			����rd�ϻ�����Ǥ��롣								*/
/*						OSEEWKEX			�����ƥ��Ȱ褬��­������							*/
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
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osstdtim.h"
#include "os_tmctl.h"					// ����������
#include "osstdtim_ins.h"				// ���������ѡʸ��̡�
#include "os_ERDC_ins.h"

/****************************************************************************/
/* ��ǽ�����勵���ޤ�����                                                   */
/* ��������2002ǯ10��1��                                                    */
/* �ѹ�����2002ǯ12��10��                                                   */
/* �����ԡ��Ḷ                                                             */
/* �ƽз�����                                                               */
/*   long ossdtim( long rd, long day, long time )                           */
/*     long rd             �ꥯ�����ȼ��̻�                                 */
/*     long day            ����                                             */
/*     long time           ����                                             */
/*                                                                          */
/****************************************************************************/
long osstdtim( long rd, long day, long time )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    int iRet = 0;									// �ؿ��η���ֵ���
    int iLoopCnt = 0;								// �롼�ץ�����
    long lRId = 0;									// �ꥯ�����ȼ��̻�
    long lMicroSec = 0;								// �ޥ�������
    long lSec = 0;									// ��
    long lRet = 0;									// �ؿ��η���ֵ���
    long lTmp = 0;
    double dTimeOut = 0;							// �����ॢ���Ȼ���
    time_t lSiteiSec = 0;							// ������
    time_t lStdSec = 0;								// �����
    struct tm tDate;								// ���ճ�Ǽ��
    struct timeval tNowTime;						// ���ֳ�Ǽ��
    TErdcTableInd *ptRdIndTopAdr = NULL;			// rd�����ơ��֥����������Ƭ���ɥ쥹
	TErdcTableInd *ptRdIndAdr = NULL;				// rd�����ơ��֥�������Υ��ɥ쥹
/*****  �����ѹ���SSLA0031��	Start									��������2003.06.12  *****/
	long lIndex = 0;								// ��������Index
	long lMsgQId = 0;								// ��å��������塼ID */
	int iLength = 0;								// ��å�����Ĺ
	TMyMessage tMsgBuf;								// ��å������Хåե�
/*****  �����ѹ���SSLA0031��	End  									��������2003.06.12  *****/

	os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_IN, 3, rd, day, time  );


//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	/************************************************/
	/*	�����γ�ǧ									*/
	/************************************************/
    												// rd�����ơ��֥����������Ƭ���ɥ쥹����
    ptRdIndTopAdr = ((TErdcTableInd *)( ptErdc + 1 ));

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndTopAdr=%p )\n",
														D_PROC_NAME, ptRdIndTopAdr ) );
	/************************************/
	/*	�ꥯ�����ȼ��̻Ҥγ�ǧ			*/
	/************************************/
    if( D_RD_NONE == rd )							// �ꥯ�����ȼ��̻Ҥ��ʤ��λ�
    {
													// rd�����ơ��֥��������Ƭ����ꥯ�����Ⱦ���
													// ��̤ͽ�󤫤�̤���Ѥ���̤�׵�θ������򸡺�
//2003.02.19		for( iLoopCnt = 0; iLoopCnt < ptErdc->lMaxIndNum; iLoopCnt++ )
		for( iLoopCnt = 0; iLoopCnt < ptMyEPRC->lMaxReqNum; iLoopCnt++ )
		{
													// ͽ����֤�ͽ��̤�λ�
//			if( D_RES_OFF == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat )
													// �ꥯ�����Ⱦ��֤�
													// ̤ͽ�󤫤�̤���Ѥ���̤�׵�ξ��
			if( D_ERDC_RESSTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cUCompStat )
			{
													// ����������Ƭ���ɥ쥹����
				ptRdIndAdr = ptRdIndTopAdr + iLoopCnt;

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
    													D_PROC_NAME, ptRdIndAdr ) );

				lRId = ptRdIndAdr->lRCode;			// �������Υꥯ�����ȼ��̻Ҽ���

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRId=%ld )\n", 
														D_PROC_NAME, lRId ) );
				break;								// ������ȴ����
			}
		}
		
		if( lRId == D_RD_NONE )						// ͽ��̤�����Ĥ���ʤ��ä���
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
    		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  );												
    														
			return( OSEEIVRD );						// OSEEIVRD���ֵ�
		}
	}
													// �ꥯ�����ȼ��̻Ҥ��Ǿ��ͤ�����������δ֤λ�
//2003.02.19    else if(( D_RD_MIN <= rd ) && ( ptErdc->lMaxIndNum >= rd ))
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {
		ptRdIndAdr = ptRdIndTopAdr + ( rd - 1 );	// ����������Υ��ɥ쥹����

    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// ͽ����֤�ͽ��̤�λ�
		if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
   			os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  );												
    														
			return( OSEEIVRD );						// OSEEIVRD���ֵ�
		}

													// ��λ�׵���֤��׵�Ѥλ�
		if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEUSED ) );
    														
			os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEUSED  );   														
    														
			return( OSEEUSED );						// OSEEUSED���ֵ�
		}

		lRId = rd;									// �ꥯ�����ȼ��̻Ҥμ���
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRId=%ld )\n", D_PROC_NAME, lRId ) );
	}
	else											// �ꥯ�����ȼ��̻Ҥ�����¾�λ�
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_PRA, 1, OSEEIVRD  ); 
    														
		return( OSEEIVRD );							// OSEEIVRD���ֵ�
	}

	/************************************/
	/*	���դγ�ǧ						*/
	/************************************/
													// 20030303 �����ѹ�SSLA0015�б�
	if(0 == day)									// ���դ����λ������������դ�����
	{
		lRet = osgtdat(&day, &lTmp);
		if(NORMAL != lRet)
			return(lRet);
	}

	/************************************/
	/*	���ջ�����Ѵ�					*/
	/************************************/
	lRet = os_DayTime2Date( day, time, &tDate );	// ���ջ�����������Ѵ�
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	if( NORMAL != lRet )							// �Ѵ��˼��Ԥ�����
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEIVAL ) );
    														
   		os_trcget2(  D_MD_OSSTDTIM, D_T_ERR_SYS, 1, OSEEIVAL ); 													
		
		return( OSEEIVAL );							// OSEEIVAL���ֵ�
	}


/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	/************************************************/
	/*	�����ॢ���Ȼ��֤λ���						*/
	/************************************************/
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  

	iRet = gettimeofday( &tNowTime, NULL );			// ���������μ���
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 1, iRet ); 

	if( D_ERR_SYS == iRet )							// �����μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "gettimeofday", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, errno    ); 							
									
		return( OSEEWKEX );							// OSEEWKEX���ֵ�
	}

	lStdSec = tNowTime.tv_sec;						// �����������ä�����
	
	os_trcget2( D_MD_OSSTDTIM,  D_T_SYS_MKTIME, 1, &tDate ); 
	
	lSiteiSec = mktime( &tDate );					// ���������μ���

	os_trcget2( D_MD_OSSTDTIM,  D_T_SYS_END, 1, lSiteiSec );

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lStdSec=%ld )\n", D_PROC_NAME, lStdSec ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSiteiSec=%ld )\n", D_PROC_NAME, lSiteiSec ) );

	if( D_ERR_SYS == lSiteiSec )					// ���������μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM,  D_T_ERR_SYS, 1, errno    );
									
		return( OSEEIVAL );							// OSEEIVAL���ֵ�
	}
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_DIFFTIME, 2, lSiteiSec, lStdSec ); 
	
	dTimeOut = difftime( lSiteiSec, lStdSec );		// ��������������������ޤǤλ��֤����
	
	os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 1, dTimeOut ); 
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( dTimeOut=%lf )\n", D_PROC_NAME, dTimeOut ) );

	if( D_SEC_MIN >= dTimeOut )						// ���֤μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "difftime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, errno    ); 
									
/*****  �����ѹ���SSLA0031��	Start									��������2003.06.16  *****/
		/********************************************/
		/*  rd�����ơ��֥���Խ�					*/
		/********************************************/
													// ��λ�׵���֤��׵�Ѥ�����
		ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
		ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;	// �׵���̤˥��󥿡��Х륿���ޤ�����
		ptRdIndAdr->lReqNum = ptErdc->ulMstReqNum;	// �ꥯ�������ֹ�˥ޥ����ꥯ�������ֹ������
		ptErdc->ulMstReqNum++;						// �ޥ����ꥯ�������ֹ��1�û�
		ptRdIndAdr->lPCode = ptMyEPRC->lPCode;		// �ץ������̻Ҥ�����
		
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
									D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=0x%02x )\n",
									D_PROC_NAME, ptRdIndAdr->cReqClass ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
									D_PROC_NAME, ptRdIndAdr->lReqNum ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
									D_PROC_NAME, ptErdc->ulMstReqNum ) );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
									D_PROC_NAME, ptRdIndAdr->lPCode ) );

		/********************************************/
		/*  ��å������Хåե����Խ�				*/
		/********************************************/
		tMsgBuf.lMsgtype = D_TIMEOUT_MSG;			// ��å����������פ�[�����ॢ��������]��
													// ���ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
									D_PROC_NAME, tMsgBuf.lMsgtype ) );
		
		tMsgBuf.pcBufAdr = D_PBUF_FIX;				// �ס���Хåե����ɥ쥹�����ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
									D_PROC_NAME, tMsgBuf.pcBufAdr ) );

		tMsgBuf.lReqid = ptRdIndAdr->lReqNum;		// �ꥯ�������ֹ�����ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
									D_PROC_NAME, tMsgBuf.lReqid ) );

		tMsgBuf.lDatesize = D_DATESIZE_FIX;			// �ǡ��������������ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
									D_PROC_NAME, tMsgBuf.lDatesize ) );

		tMsgBuf.lResult = D_RESULT_NORMAL;			// �ꥶ��Ȥ����ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
									D_PROC_NAME, tMsgBuf.lResult ) );

		lMsgQId = ptMyEMBC->lMsgQId;				// ���᡼��ܥå����Υ�å��������塼������
		
		iLength = sizeof(TMyMessage) - sizeof(long);
													// msgsnd�Υ�å�����Ĺ�ˤ�
													// ��å�����������(long)�ΥХ��ȿ�
													// ���������ΥХ��ȿ������ꤹ��
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLength=%d )\n",
									D_PROC_NAME, iLength ) );

		/********************************************/
		/*  ��å�����������						*/
		/********************************************/
		os_trcget2( D_MD_OSSTDTIM, D_T_SYS_MSGSND, 4, lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
		iRet = msgsnd( lMsgQId, &tMsgBuf, iLength, IPC_NOWAIT );
		os_trcget2( D_MD_OSSTDTIM, D_T_SYS_END, 2, iRet, errno);
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
		if( iRet == D_ERR_SYS ) 
		{
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: %s\n",
									D_PROC_NAME, strerror(errno)) );

			goto err_msgsnd;
		}
		
		DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
		os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_OUT, 1, lRId  );
		return( lRId );								// �ꥯ�����ȼ��̻Ҥ��ֵѤ���λ
//		return( OSEEIVAL );							// OSEEIVAL���ֵ�
/*****  �����ѹ���SSLA0031��	End  									��������2003.06.16  *****/
	}

	lSec = ( long )dTimeOut;						// �ä�����
	lMicroSec = 0;									// �ޥ������ä�����

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n", D_PROC_NAME, lSec ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n", D_PROC_NAME, lMicroSec ) );

	/************************************************/
	/*	rd�����ơ��֥���Խ�						*/
	/************************************************/
													// ��λ�׵���֤��׵�Ѥ�����
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
//	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS03;		// �׵���̤�osstdtim���б��ͤ�����
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;		// �׵���̤˥��󥿡��Х륿���ޤ�����

	/*******  U00010 �ꥯ�������ֹ�����������ɲ� 2002��12��10*********/
	ptRdIndAdr->lReqNum = ptErdc->ulMstReqNum;		// �ꥯ�������ֹ�˥ޥ����ꥯ�������ֹ������
	ptErdc->ulMstReqNum++;							// �ޥ����ꥯ�������ֹ��1�û�
	ptRdIndAdr->lPCode = ptMyEPRC->lPCode;			// �ץ������̻Ҥ�����

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=0x%02x )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
													D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
															D_PROC_NAME, ptErdc->ulMstReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
															D_PROC_NAME, ptRdIndAdr->lPCode ) );

	/************************************************/
	/*	����������ε�ư							*/
	/************************************************/
													// ������ȯ��
	lRet = os_tmctl( lRId, ptRdIndAdr->lReqNum, lMicroSec, lSec );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );
															
	if( NORMAL != lRet )							// �����ޤ�����˽�λ����ʤ��ä���
	{
		goto err_os_tmctl;							// �۾����������
	}


/****************************************************************************/
/* ��λ����                                                                 */
/****************************************************************************/
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2(  D_MD_OSSTDTIM, D_T_TRA_OUT, 1, lRId  );

	return( lRId );									// �ꥯ�����ȼ��̻Ҥ��ֵѤ���λ


/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_os_tmctl:
													// ��λ�׵���֤��׵�̤������
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS00;		// �׵���̤˽���ͤ�����
	ptRdIndAdr->lReqNum = 0;						// �ꥯ�������ֹ�˽���ͤ�����
	ptErdc->ulMstReqNum--;							// �ޥ����ꥯ�������ֹ��1����
	ptRdIndAdr->lPCode = D_PCODE_INI;				// �ץ������̻Ҥ˽���ͤ�����

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=%d )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
													D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
												D_PROC_NAME, ptErdc->ulMstReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lPCode ) );

	switch( lRet )
	{
		case OSEEITIM:								// OSEEITIM�λ�
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   			os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, OSEEITIM ); 	
    														
			return( OSEEITIM );						// OSEEITIM���ֵ�
			break;
			
		default:									// ����¾�λ�
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
    														D_PROC_NAME, -1 ) );
    		
    		os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, -1 ); 												
    		
    		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTDTIM << 16) | D_T_ERR_SYS );
			//return( -1 );							// ���ܡ��Ƚ���
			break;
	}
/*****  �����ѹ���SSLA0031��	Start									��������2003.06.16  *****/
err_msgsnd:
													// ��λ�׵���֤��׵�̤������
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS00;		// �׵���̤˽���ͤ�����
	ptRdIndAdr->lReqNum = 0;						// �ꥯ�������ֹ�˽���ͤ�����
	ptErdc->ulMstReqNum--;							// �ޥ����ꥯ�������ֹ��1����
	ptRdIndAdr->lPCode = D_PCODE_INI;				// �ץ������̻Ҥ˽���ͤ�����

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%d )\n",
									D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=%d )\n",
									D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
									D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
									D_PROC_NAME, ptErdc->ulMstReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
									D_PROC_NAME, ptRdIndAdr->lPCode ) );

	os_trcget2( D_MD_OSSTDTIM, D_T_ERR_SYS, 1, -1 );
	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTDTIM << 16) | D_T_ERR_SYS1 );
/*****  �����ѹ���SSLA0031��	End  									��������2003.06.16  *****/
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/

