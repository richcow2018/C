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
/* ��⥸�塼��̾��					 ���󥿥Х륿���ޤ�����										*/
/* ��⥸�塼��ɣġ�				 ossttim													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�����ѹ��ֹ�ʣӣӣ̣�����������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���󥿡��Х륿���ޤ�����																	*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<ossttim.h>																	*/
/*																								*/
/*	   	long	ossttim( long rd, long times, long unit )										*/
/*																								*/
/* �㲾������																					*/
/*		long	rd;			�ꥯ�����ȼ��̻�													*/
/*		long	times;		����																*/
/*		long	unit;		ñ�̻���															*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�ꥯ�����ȼ��̻�														*/
/*		�۾ｪλ		OSEEITIM																*/
/*						OSEEOVRQ																*/
/*						OSEEIVRD																*/
/*						OSEEUSED																*/
/*						OSEEIUNI																*/
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
#include <string.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "ossttim.h"
#include "os_tmctl.h"					// ����������
#include "ossttim_ins.h"				// ���������ѡʸ��̡�
#include "os_ERDC_ins.h"

/****************************************************************************/
/* ��ǽ�����󥿡��Х륿���ޤ�����                                           */
/* ��������2002ǯ9��30��                                                    */
/* �ѹ�����2002ǯ12��10��                                                   */
/* �����ԡ��Ḷ                                                             */
/* �ƽз�����                                                               */
/*   long ossttim( long rd, long times, long unit )                         */
/*     long rd             �ꥯ�����ȼ��̻�                                 */
/*     long times          ����                                             */
/*     long unit           ñ�̻���                                         */
/*                                                                          */
/****************************************************************************/
long ossttim( long rd, long times, long unit )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    long lRId = 0;									// �ꥯ�����ȼ��̻�
    long lMicroSec = 0;								// �ޥ�������
    long lSec = 0;									// ��
    int iLoopCnt = 0;								// �롼�ץ�����
    long lRet = 0;									// �ؿ��η���ֵ���
    TErdcTableInd *ptRdIndTopAdr = NULL;			// rd�����ơ��֥����������Ƭ���ɥ쥹
	TErdcTableInd *ptRdIndAdr = NULL;				// rd�����ơ��֥�������Υ��ɥ쥹
/*****	�����ѹ��ֹ�SSLA0042���б�		Start							��������2003.07.15	*****/
	long lMilliSec = 0;								// �ߥ���
/*****	�����ѹ��ֹ�SSLA0042���б�		 End							��������2003.07.15	*****/
	
	os_trcget2( D_MD_OSSTTIM, D_T_TRA_IN, 3, rd, times, unit );


//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	�����γ�ǧ									*/
	/************************************************/
    ptRdIndTopAdr = (TErdcTableInd *)(ptErdc + 1 ); // rd�����ơ��֥����������Ƭ���ɥ쥹����

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
//			if( D_RES_OFF ==  ( ptRdIndTopAdr + iLoopCnt )->tReqStat.cResStat )
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
    														D_PROC_NAME, OSEEOVRQ ) );
    														
    		os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEOVRQ );
    														
			return( OSEEOVRQ );						// OSEEOVRQ���ֵ�
		}
	}
													// �ꥯ�����ȼ��̻Ҥ��Ǿ��ͤ�����������δ֤λ�
//2003.02.19    else if(( D_RD_MIN <= rd ) && ( ptErdc->lMaxIndNum >= rd ))
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {
		ptRdIndAdr = ptRdIndTopAdr + rd - 1;		// ����������Υ��ɥ쥹����

    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// ͽ����֤�ͽ��̤�λ�
		if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
    		os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEIVRD );
    														
			return( OSEEIVRD );						// OSEEIVRD���ֵ�
		}
													// ��λ�׵���֤��׵�Ѥλ�
		if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
		{
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEUSED ) );
    														
   			os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEUSED );
    		
			return( OSEEUSED );						// OSEEUSED���ֵ�
		}
		
		lRId = rd;									// �ꥯ�����ȼ��̻Ҥμ���
	}
	else											// �ꥯ�����ȼ��̻Ҥ�����¾�λ�
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
    														
    	os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEIVRD );
    	
		return( OSEEIVRD );							// OSEEIVRD���ֵ�
	}

    /************************************/
	/*	���֤γ�ǧ						*/
	/************************************/
    if( D_TIME_MIN > times )						// ���֤��Ǿ��ͤ�꾮�������
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
    	os_trcget2( D_MD_OSSTTIM, D_T_ERR_PRA, 1, OSEEITIM );
    														
		return( OSEEITIM );							// OSEEITIM���ֵ�
	}


/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	/************************************************/
	/*	�����ॢ���Ȼ��֤λ���						*/
	/************************************************/
	switch( unit )
	{
		case D_UNIT_MSEC:							// ñ�̻��֤��ߥ��äλ�
/*****	�����ѹ��ֹ�SSLA0042���б�		Start							��������2003.07.15	*****/
/************************************************************************************************/
/*	�����ѹ��ˤ����֤κ����ͥ����å���������												*/
/************************************************************************************************/
													// �ޥ������ä�������ͤ��ھ夲������
//			lMicroSec = ((( long )(( times + ( D_UPMSEC_TEN - 1 )) / D_UPMSEC_TEN )) 
//			                                                 * D_UPMSEC_TEN * 1000 );
//			lSec = 0;								// �ä�����

			lSec      = times / 1000;				// �äλ���
			lMilliSec = times % 1000;				// �ߥ��äλ���
													// �ޥ������ä�������ͤ��ھ夲������
			lMicroSec = ((lMilliSec + ( D_UPTIME_TEN - 1 )) / D_UPTIME_TEN)
														   * D_UPMSEC_TEN * 1000;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMilliSec=%ld )\n",
															D_PROC_NAME, lMilliSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
/*****	�����ѹ��ֹ�SSLA0042���б�		 End							��������2003.07.15	*****/
			break;
			
		case D_UNIT_SEC:							// ñ�̻��֤��äλ�
			lMicroSec = 0;							// �ޥ������ä�����
			lSec = times;							// �ä�����

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		case D_UNIT_MINUTE:							// ñ�̻��֤�ʬ�λ�
			if( D_MIN_MAX < times )					// ���֤�ʬ�κ����ͤ�Ķ���Ƥ����
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
												
				os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );											
															
				return( OSEEITIM );					// OSEEITIM���ֵ�
			}

			lMicroSec = 0;							// �ޥ������ä�����
			lSec = times * 60;						// �ä������ʬ���ä��Ѵ���

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		case D_UNIT_HOUR:							// ñ�̻��֤����λ�
			if( D_HOUR_MAX < times )				// ���֤����κ����ͤ�Ķ���Ƥ����
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
															
				os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );
															
				return( OSEEITIM );					// OSEEITIM���ֵ�
			}

			lMicroSec = 0;							// �ޥ������ä�����
			lSec = times * 60 * 60;					// �ä�����ʻ����ä��Ѵ���

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lMicroSec=%ld )\n",
															D_PROC_NAME, lMicroSec ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
															D_PROC_NAME, lSec ) );
			break;

		default:									// ñ�̻��֤�����¾�λ�
	 		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
															D_PROC_NAME, OSEEIUNI ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEIUNI );												
															
			return( OSEEIUNI );						// OSEEIUNI���ֵ�
	}

	/************************************************/
	/*	rd�����ơ��֥���Խ�						*/
	/************************************************/
	ptRdIndAdr->tReqStat.cUCompStat = D_UCOMP_ON;	// ��λ�׵���֤��׵�Ѥ�����
	ptRdIndAdr->cReqClass = D_ERDC_REQCLASS02;		// �׵���̤�ossttim���б��ͤ�����

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
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSSTTIM, D_T_TRA_OUT, 1, lRId );

	return( lRId );									// �ꥯ�����ȼ��̻Ҥ��ֵ�


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
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
															D_PROC_NAME, OSEEITIM ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, OSEEITIM );
															
			return( OSEEITIM );						// OSEEITIM���ֵ�
			break;
			
		default:									// ����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
															D_PROC_NAME, -1 ) );
															
			os_trcget2( D_MD_OSSTTIM, D_T_ERR_SYS, 1, -1 );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSTTIM << 16) | D_T_ERR_SYS );
			//return( -1 );;							// ���ܡ��Ƚ���
			break;
	}
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
