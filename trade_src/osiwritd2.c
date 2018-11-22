/****************************************************************************/
/*  ���  ��������                                                        */
/*            ������ңΣԣԥǡ���                                          */
/*              ��ͻ�ӥ��ͥ���������                                        */
/*                                                                          */
/*                                                                          */
/*  ����ʪ  �̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��              */
/****************************************************************************/
/* ���оݶ�̳̾��                  �ԣң��ģť��ߥ�졼��                   */
/* ���оݶ�̳�ɣġ�                �ԣң�                                   */
/* �㥵���ӥ�����̾��              �ԣã�/�ɣ�����                          */
/* �㥵���ӥ����ܣɣġ�            �أأأأأأ�                           */
/* ��⥸�塼��̾��                ��λ�� �ե�����ؤ�ľ�ܽ񤭹���        */
/* ��⥸�塼��ɣġ�              osiwritd2                                */
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
/* �㳫ȯ�����ƥ�̾��              �̣��̣�ݣӣͣХ����ƥ�                 */
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
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ������ץ饤) */
/* �㥽��������ǯ������            ��������ǯ���������                   */
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ������ץ饤) */
/* �㥽��������ǯ�����ڤӽ����ɣġ䣲������ǯ��������� �����ѹ�(SSLA0019)*/
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ������ץ饤) */
/* �㥽��������ǯ�����ڤӽ����ɣġ䣲������ǯ��������� �㳲�б�(KL0048)  */
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ������ץ饤) */
/* �㥽��������ǯ�����ڤӽ����ɣġ䣲������ǯ��������� �㳲�б�(TBCS0276)*/
/*--------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���              ���ƥå�                                 */
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                             */
/*   TCP/IP�饤��                                                           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*		#include	<osiwritd2.h>											*/
/*                                                                          */
/*      long osiwritd2( long rd, long fildes, char *buf,                    */
/*                                            long len, long prm )          */
/*                                                                          */
/* �㲾������                                                               */
/*      long rd         �ꥯ�����ȼ��̻ҡ�0�ʾ��                           */
/*      long fildes     �ե�����ǥ�������ץ� �ʻ��Ѥ��ʤ���               */
/*      char *buf       ���ϰ�ؤΥݥ���                                  */
/*      long len        ���ϰ�ؤΥ�������16�ʾ��                          */
/*      long prm        ư��ѥ�᡼��	��                                  */
/*                              (1) 00bit��15bit��:��read���ץ����         */
/*                              (2) 16bit��31bit��:  �����륻�å�����ֹ� */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*		���ｪλ		�ꥯ�����ȼ��̻�									*/
/*		�۾ｪλ		OSEEOVRQ	rd�����ơ��֥�������Ρ�ͽ����֡פ�	*/
/*									��ͽ��̤�פθ�������¸�ߤ��ʤ���		*/
/*						OSEEIVRD	rd�����ơ��֥�������Ρ�ͽ����֡פ�	*/
/*									��ͽ��̤�פǤ��롣						*/
/*									�����Υꥯ�����ȼ��̻Ҥ��ͤ�0̤���Ǥ��� */
/*						OSEEUSED	rd�����ơ��֥��������					*/
/*									����λ�׵���֡פ�					*/
/*									����λ�׵�ѡפǤ��롣				*/
/*						OSFEFILDES	���ͥ����������ơ��֥�۾�			*/
/*						0xECF10001	�����륻�å�����ֹ�۾�				*/
/*						0xECB00156	���ͥ������̤���ꡣ					*/
/*						0xECB00016	�ѥ��׽���߰۾						*/
/*						0xECF00009	�ѥ����ѥǥ�������ץ��۾�				*/
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
#include <unistd.h> 					// write��
#include <string.h> 					// memset��

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osiwritd2.h"
#include "osiwritd2_ins.h"				// ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osiwritd2                                                 */
/*                                                                          */
/*  �㵡ǽ���ס�  TCP/IP�饤��                                              */
/*                                                                          */
/****************************************************************************/
long osiwritd2( long rd, long fildes, char *buf, long len, long prm )
{
	TErdcTableInd *ptErdcTableInd;					// rd�����ơ��֥���оݸ�����
	TEcncTableInd *ptEcncTableInd;					// ���ͥ����������ơ��֥���оݸ�����
	TArgInfo tTArgInfo; 							// �׵�����ѥ����������
	int			iLocalSes;							// �����륻�å�����ֹ�
	long		lRCode;								// �оݥꥯ�����ȼ��̻�
	ssize_t		lSndBytes;							// ������������ΥХ��ȿ�
	ssize_t		lTotalSndBytes; 					// ���ߤޤǤ������������Х��ȿ�
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
	int			iRet;								// �ֵ���
	long		lRet;								// �ֵ���
	TMyMessage	tMsgBuf;							// ��å������Хåե���¤��
	size_t		stMsgSz;							// �����ѥ�å�����������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/


/************************************************************************************************/
/* �������                                                                                     */
/************************************************************************************************/
	os_trcget2( D_MD_OSIWRITD2, D_T_TRA_IN, 5, rd, fildes, buf, len, prm );
	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );


	if( ptEcnc == NULL )							// ���ͥ����������ơ��֥뤬̤�����λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, OSFEFILDES );
		return( OSFEFILDES );						// OSFEFILDES���ֵ�
	}

	lRCode = os_CheckRCode( rd );					// �ꥯ�����ȼ��̻ҥ����å�
	if( lRCode <= D_CHECKRCODE_ERR )				// �ꥯ�����ȼ��̻Ҥ��۾��ͤλ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
														D_PROC_NAME, lRCode ) );
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, lRCode );
		return( lRCode );							// �ꥯ�����ȼ��̻Ҥ��ֵ�
	}
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRCode=%ld )\n", D_PROC_NAME, lRCode ) );

	if( len < D_LEN_MIN )							// ���ϰ�ؤΥ��������Ǿ��ͤ�꾮������
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
														D_PROC_NAME, D_ERR_ARG ) );
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_PRA, 1, D_ERR_ARG );
		return( D_ERR_ARG );						// D_ERR_ARG���ֵ�
	}

													// �����륻�å�����ֹ�μ���
	iLocalSes =  ( int )(( prm >> 16 ) & 0x0000ffff );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iLocalSes=%d )\n", D_PROC_NAME, iLocalSes ) );

													// ���ͥ����������ơ��֥���������ϰϳ��ξ��
	if( ( iLocalSes < D_INDNUM_MIN ) || ( iLocalSes > ptEcnc->lMaxIndNum ) )
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
														D_PROC_NAME, D_ERR_REQ ) );
/*****	�㳲�б���KL0048��		Start									��������2003.04.25	*****/
/************************************************************************************************/
/*	�ֵ��ͤ�D_RESULT_NOTCONNECT �� D_ERR_REQ���ѹ�												*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_NOTCONNECT );
//		return( D_RESULT_NOTCONNECT );				// D_RESULT_NOTCONNECT���ֵ�
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_ERR_REQ );
		return( D_ERR_REQ );						// �ꥯ�������������ʥѥ�᡼�����顼�ˤ��ֵ�
/*****	�㳲�б���KL0048��		 End									��������2003.04.25	*****/
	} 

													// ���ͥ������ơ��֥��оݸ�����������
	ptEcncTableInd = (TEcncTableInd *)( ptEcnc + 1 ) + iLocalSes - 1;
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncTableInd=%p )\n",
														D_PROC_NAME, ptEcncTableInd ) );

													// 'S'��'C'�ʳ��ξ��
	if( ( ptEcncTableInd->cSCFlg != D_SCINFO_SERVER ) && 
		( ptEcncTableInd->cSCFlg != D_SCINFO_CLIENT ) ) 
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
														D_PROC_NAME, D_ERR_TABLE ) );
/*****	�㳲�б���KL0048��		Start									��������2003.04.25	*****/
/************************************************************************************************/
/*	�ֵ��ͤ�D_RESULT_NOTCONNECT �� D_ERR_TABLE���ѹ�											*/
/************************************************************************************************/
//		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_NOTCONNECT );
//		return( D_RESULT_NOTCONNECT );				// D_RESULT_NOTCONNECT���ֵ�
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_ERR_TABLE );
		return( D_ERR_TABLE );						// �ơ��֥륨�顼���ֵ�
/*****	�㳲�б���KL0048��		 End									��������2003.04.25	*****/
	}

/*****	�㳲�б���KL0048��		Start									��������2003.04.25	*****/
/************************************************************************************************/
/*	�ֵ��ͤ�ꥶ��Ȥα������ֵѤ���١�����Ƚ�������rd�����ơ��֥�������˰�ư������		*/
/************************************************************************************************/
//	if( ptEcncTableInd->alPipeDes[1] == 0 )
//	{									// �оݸ������Υѥ����ѥǥ�������ץ����֣��פǤ����
//		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
//														D_PROC_NAME, D_RESULT_ELOCALSES ) );
//		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_ELOCALSES );
//		return( D_RESULT_ELOCALSES );	// D_RESULT_ELOCALSES���ֵ�
//	}
/*****	�㳲�б���KL0048��		 End									��������2003.04.25	*****/


/************************************************************************************************/
/* �ܽ���                                                                                       */
/************************************************************************************************/
	/****************************************/
	/*  rd�����ơ��֥���оݸ���������		*/
	/****************************************/
													// rd�����ơ��֥��оݸ������Υ��ɥ쥹������
	ptErdcTableInd = (TErdcTableInd *)( ptErdc + 1 ) + lRCode - 1;

													// ����λ�׵���֡פ���׵�ѡפ�����
	ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;

	ptErdcTableInd->cReqClass = D_ERDC_REQCLASS24;	// rd���׵��������

	ptErdcTableInd->lReqNum = ptErdc->ulMstReqNum;	// rd�Υꥯ�������ֹ��
													// rd�������Υޥ����ꥯ�������ֹ������

	ptErdc->ulMstReqNum++;							// rd�������Υޥ����ꥯ�������ֹ楤�󥯥����

	ptErdcTableInd->lPCode = ptMyEPRC->lPCode;		// �������ơ��֥�������Υץ������̻Ҥ�
													// ���ץ������̻Ҥ�����

	ptErdcTableInd->pvArg1 = buf;					// �����ΰ裱��(������)���ϰ�ؤΥݥ��󥿤�����
	ptErdcTableInd->pvArg2 = (void *)len;			// �����ΰ裲��(������)���ϰ襵����������

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd=%p )\n",
							D_PROC_NAME, ptErdcTableInd ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->tReqStat.cUCompStat=%hhd )\n",
							D_PROC_NAME, ptErdcTableInd->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->cReqClass=%hhd )\n",
							D_PROC_NAME, ptErdcTableInd->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->lReqNum=%ld )\n",
							D_PROC_NAME, ptErdcTableInd->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->lPCode=%ld )\n",
							D_PROC_NAME, ptErdcTableInd->lPCode ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->pvArg1=%p )\n",
							D_PROC_NAME, ptErdcTableInd->pvArg1 ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdcTableInd->pvArg2=%p )\n",
							D_PROC_NAME, ptErdcTableInd->pvArg2 ) );

/*****	�㳲�б���KL0048��		Start									��������2003.04.25	*****/
	if( ptEcncTableInd->alPipeDes[1] == 0 )			// �оݸ������Υѥ����ѥǥ�������ץ������ξ��
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
														D_PROC_NAME, D_RESULT_DISCONNECT ) );
		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_DISCONNECT );

		tMsgBuf.lResult = D_RESULT_DISCONNECT;		// ���ͥ�����󤬥ꥻ�åȤ��줿
		goto err_osiwritd2;							// ��λ��å������Υ��顼������
	}
/*****	�㳲�б���KL0048��		 End									��������2003.04.25	*****/

	/************************************/
	/*  write�׵���������				*/
	/************************************/
	tTArgInfo.cRecClass = D_REQCLASS_WRITE;			// �׵����
	tTArgInfo.lRCode = ptErdcTableInd->lRCode;		// �֥ꥯ�����ȼ��̻ҡפ�����
	tTArgInfo.ulReqNum = ptErdcTableInd->lReqNum;	// �֥ꥯ�������ֹ�פ�����
	tTArgInfo.pvArg1 = buf; 						// �ְ������󣱡פ�����
	tTArgInfo.pvArg2 = (void *)len; 				// �ְ������󣲡פ�����

	/************************************/
	/*  write�׵������					*/
	/************************************/
	lTotalSndBytes = 0;
	lSndBytes = 0;

	while( lTotalSndBytes < sizeof(long) )
	{
													// �ѥ����ѥǥ�������ץ����Ф���
													// write�׵��񤭹���
		os_trcget2( D_MD_OSIWRITD2, D_T_SYS_WRITE, 3, ptEcncTableInd->alPipeDes[1], 
							(const void *)&tTArgInfo + lTotalSndBytes, 
							sizeof(tTArgInfo) - lTotalSndBytes );
		lSndBytes = write( ptEcncTableInd->alPipeDes[1], 
							(const void *)&tTArgInfo + lTotalSndBytes, 
							sizeof(tTArgInfo) - lTotalSndBytes );
		os_trcget2( D_MD_OSIWRITD2, D_T_SYS_END, 1, lSndBytes );

		if( lSndBytes == D_ERR_SYS )				// write����
		{
			if( errno == EINTR )					// errno ��EINTR�λ�
			{
				continue;
			}
			else									// errno ��EINTR�Ǥʤ���
			{
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
													// ���ꤷ���������ơ��֥�Υ��ꥢ
//				ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
//				ptErdcTableInd->cReqClass = D_ERDC_REQCLASS00;
//				ptErdcTableInd->lReqNum = 0;
//				ptErdcTableInd->lPCode = 0;
//				ptErdcTableInd->pvArg1 = NULL;
//				ptErdcTableInd->pvArg2 = NULL;

//				ptErdc->ulMstReqNum--;				// rd�������Υޥ����ꥯ�������ֹ��ǥ������

//				goto err_osiwritd2;					// �۾����������

				switch( errno )						// errno�ˤ������ο�ʬ��
				{
					case EBADF:
					case EINVAL:
					case EFAULT:
					case EFBIG:
					case EAGAIN:
					case ENOSPC:
					case EIO:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "write", strerror(errno) ) );
						os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_ERR_LOGIC );

													// �ꥶ��ȷ�̤ˡ��������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_osiwritd2;			// ��λ��å������Υ��顼������
						break;

					case EPIPE:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_RESULT_DISCONNECT, "write", strerror(errno) ) );
						os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_DISCONNECT );

													// ���Ǥˤ�륭��󥻥�
						tMsgBuf.lResult = D_RESULT_DISCONNECT;
						goto err_osiwritd2;			// ��λ��å������Υ��顼������
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "write", strerror(errno) ) );
						os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, -1 );
						return( -1 );				// ���ܡ��Ƚ���
				}
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}
		}

		lTotalSndBytes += lSndBytes;	// �����������Х��ȿ��˺����ʬ�򥤥󥯥����
	}

	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSIWRITD2, D_T_TRA_OUT, 1, lRCode );
	return( lRCode );					// �������ơ��֥��оݸ������ꥯ�����ȼ��̻�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_osiwritd2:
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//	switch( errno )
//	{
//		case EBADF:
//		case EINVAL:
//		case EFAULT:
//		case EFBIG:
//		case EAGAIN:
//		case ENOSPC:
//		case EIO:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, D_ERR_LOGIC, "write", strerror(errno) ) );
//			os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
//			return( D_ERR_LOGIC );		// �������
//			break;
//
//		case EPIPE:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, D_RESULT_DISCONNECT, "write", strerror(errno) ) );
//			os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, D_RESULT_DISCONNECT );
//			return( D_RESULT_DISCONNECT );
//										// ���Ǥˤ�륭��󥻥�
//			break;
//
//		default:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, -1, "write", strerror(errno) ) );
//			os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, -1 );
//			return( -1 );				// ���ܡ��Ƚ���
//	}

	/********************************************/
	/*  ��å������إå����Խ�					*/
	/********************************************/
	tMsgBuf.lMsgtype  = D_MTYPE24;
	tMsgBuf.pcBufAdr  = NULL;
	tMsgBuf.lDatesize = D_DATESIZE_FIX;
	tMsgBuf.lReqid    = ptErdcTableInd->lReqNum;
													// ��å���������������
	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

	/********************************************/
	/*  ��λ����������						*/
	/********************************************/
	os_trcget2( D_MD_OSIWRITD2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId,
										&tMsgBuf, stMsgSz, IPC_NOWAIT );
													// ��å���������
	iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OSIWRITD2, D_T_SYS_END, 1, iRet );

	if( iRet == D_ERR_SYS )							// �۾�λ�
	{
		DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 10: 0x%08x(%s:%s)\n",
								D_PROC_NAME, -1, "msgsnd", strerror(errno)));

		lRet = -1;									// -1�ʥ��ܡ��ȡˤ�����

		/************************************************/
		/*	rd�����ơ��֥��оݸ������Υ��ꥢ			*/
		/************************************************/
													// ��λ�׵���֤��׵�̤������
		ptErdcTableInd->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
													// �׵���̤򥯥ꥢ
		ptErdcTableInd->cReqClass			= D_ERDC_REQCLASS00;
		ptErdcTableInd->lReqNum				= 0;	// �ꥯ�������ֹ�򥯥ꥢ
		ptErdcTableInd->lPCode				= 0;	// �ץ������̻Ҥ򥯥ꥢ
		ptErdcTableInd->pvArg1				= NULL;	// �����ΰ�1�򥯥ꥢ
		ptErdcTableInd->pvArg2				= NULL;	// �����ΰ�2�򥯥ꥢ

		ptErdc->ulMstReqNum--;						// rd�������Υޥ����ꥯ�������ֹ��ǥ������

		/************************************************/
		/*	���ͥ����������ơ��֥��оݸ������Υ��ꥢ	*/
		/************************************************/
		ptEcncTableInd->cReadStat = '\0';
		memset( &ptEcncTableInd->tReaInfo, 0, sizeof(TReqInfo) );

		os_trcget2( D_MD_OSIWRITD2, D_T_ERR_SYS, 1, lRet );
		return( lRet );								// ���顼�ͤ��ֵ�
	}

	lRet = ptErdcTableInd->lRCode;					// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	os_trcget2( D_MD_OSIWRITD2, D_T_TRA_OUT, 1, lRet );
	return( lRet );									// ������ֵ�
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
