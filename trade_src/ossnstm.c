/************************************************************************************************/
/*  ���  ��������                                                                            */
/*            ������ңΣԣԥǡ���                                                              */
/*              ��ͻ�ӥ��ͥ���������                                                            */
/*                                                                                              */
/*                                                                                              */
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��               ����������                                                  */
/* �㥵���ӥ����ܣɣġ�             �أأأأأأ�                                              */
/* ��⥸�塼��̾��                 ���󥿡��Х륿���ޥ�������ͤμ���                          */
/* ��⥸�塼��ɣġ�               ossnstm                                                     */
/* ��⥸�塼�����֡�                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��                   ���ѥ�����                                                  */
/* ��Ŭ�ѣϣӡ�                     �̣�����                                                  */
/* �㳫ȯ�Ķ���                     �ңȣ��ӣ�����                                              */
/* �㵭�Ҹ����                     �ø���                                                      */
/* ��⥸�塼����֡�               �ؿ�                                                        */
/* �㵡ǽ��ʬ��                                                                                 */
/* ���оݥǡ�����                                                                               */
/* �㹩�������ض�ʬ��                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��				 �̣��̣�ݣӣͣХ����ƥ�									*/
/* �㳫ȯ�����ƥ��ֹ�� 			 �УУ����£�����������										*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)			    	*/
/* �������ֹ��                      148-1457(03-5437-1457)                                     */
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾��                      �ã»��ӥ��ͥ����ô��                                     */
/* ���߷�ǯ������                    ��������ǯ  �������                                     */
/* ���߷׽�����̾��                                                                             */
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                                               */
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(:�أأأ�)                          */
/* �����ԡ��Ḷ                                                                                 */
/* �㥽��������ǯ������              ��������ǯ  �������                                     */
/* ��������2002ǯ9��26��                                                                        */
/* �㥽���������ԡ�                                                                             */
/* �㥽������ǯ�����ڤӽ����ɣġ�                                                               */
/* �ѹ�����2002ǯ10��23��                                                                       */
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���                ���ƥå�                                                   */
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                                                 */
/*   ���󥿡��Х륿���ޤΥ�������ͤμ���                                                       */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                                                 */
/*      #include    <ossnstm.h>                                                                 */
/*                                                                                              */
/*      long    ossnstm()                                                                       */
/*                                                                                              */
/* �㲾������                                                                                   */
/*      �ʤ�                                                                                    */
/*                                                                                              */
/* ���ֵ��͡�                                                                                   */
/*      ���ｪλ        �ߥ���(10�ߥ���ñ��)                                                    */
/*      �۾ｪλ        OSEESETE                                                                */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤��                                                                         */
/* �����»����                                                                                 */
/*     �äˤʤ�                                                                                 */
/* ����ѳ����⥸�塼��ɣġ�                                                                   */
/* ��ƽи��Υ⥸�塼��ɣġ�                                                                   */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <sys/time.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "ossnstm.h"
#include "ossnstm_ins.h"							// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ�����󥿡��Х륿���ޤΥ�������ͤμ���                               */
/* ��������2002ǯ9��26��                                                    */
/* �ѹ�����2002ǯ10��23��                                                   */
/* �����ԡ��Ḷ                                                             */
/* �ƽз�����                                                               */
/*   long ossnstm( void )                                                   */
/*                                                                          */
/****************************************************************************/
long ossnstm()
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	int iRet;										// �ؿ��η���ֵ�
	struct timeval tNowTime;						// ���ֳ�Ǽ��
	struct itimerval tTimer;						// ���󥿥Х���ֳ�Ǽ��
/*****	�㳲�б���TBCS0065��	Start									��������2003.04.23	*****/
	long lMSec = 0;									// �ֵ��͡ʥߥ��á�
	long lMusec = 0;								// �ޥ������û��֡ʥߥ��á�
	double dMsec = 0;								// �û��֡ʥߥ��á�
	double dMsec1 = 0;								// �û��֡ʥߥ��á�
	double dMsum = 0;								// ��׻��֡ʥߥ��á�
	double dRetMsec = 0;							// �ֵ��͡�10�ߥ��á�
	long lSSec = 0;
	long lRetTMsec = 0;
	long lMSum = 0;
/*****	�㳲�б���TBCS0065��	 End									��������2003.04.23	*****/


	os_trcget2( D_MD_OSSNSTM, D_T_TRA_IN, 0 );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );


/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
/*****	�㳲�б���TBCS0065��	Start									��������2003.04.23	*****/
//	os_trcget2( D_MD_OSSNSTM, D_T_SYS_GETITIMER, 2, &tTimer, NULL );  
//	iRet = getitimer(ITIMER_REAL, &tTimer);			// ���󥿥Х륿���ޤΥ�������ͤ����
	os_trcget2( D_MD_OSSNSTM, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  
	iRet = gettimeofday(&tNowTime, NULL);			// ���֤����
	os_trcget2( D_MD_OSSNSTM, D_T_SYS_END, 2, iRet, errno ); 

	if( D_ERR_SYS == iRet )							// �����μ����˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_NAME, OSEESETE ) );
		
		os_trcget2( D_MD_OSSNSTM, D_T_ERR_SYS, 1, OSEESETE ); 
		
		return( OSEESETE );							// OSEESETE���ֵ�
	}

//	tNowTime = tTimer.it_value;
/*****	�㳲�б���TBCS0065��	 End									��������2003.04.23	*****/

	DbgMsg01( DLv02, ( OutPut, "***** %s:tNowTime.tv_sec :%ld\n", D_PROC_NAME, tNowTime.tv_sec ) );
	DbgMsg01( DLv02, ( OutPut, "***** %s:tNowTime.tv_usec:%ld\n", D_PROC_NAME, tNowTime.tv_usec) );

/*****	�㳲�б���TBCS0065��	Start									��������2003.04.23	*****/
													// �Ĥ���֤�10�ߥ���ñ�̤��֤�
//	lMSec = (tNowTime.tv_sec * (D_MSEC_VAL/D_DOWNTIME_TEN)) +
//			 (tNowTime.tv_usec / (D_MSEC_VAL * D_DOWNTIME_TEN));

													// ���֤�ߥ���ñ�̤��Ѵ�
	lSSec = tNowTime.tv_sec & 0x000FFFFF;
	lMSec = lSSec * D_MSEC_VAL;
	lMusec = tNowTime.tv_usec / D_MSEC_VAL;
	lMSum = lMSec + lMusec;

/*****	�㳲�б���TBCS0065��	 End									��������2003.04.23	*****/

	DbgMsg01( DLv02, ( OutPut, "***** %s:lMSec    :%ld \n", D_PROC_NAME, lMSec ) );
	DbgMsg01( DLv02, ( OutPut, "***** %s:lMusec   :%ld \n", D_PROC_NAME, lMusec ) );


													// �ޥ������ä�ߥ��ä��Ѵ�
													//  (10�ߥ���̤���ڤ�Τ�)
//	lMSec = ((( long )( tNowTime.tv_usec / D_MSEC_VAL / D_DOWNTIME_TEN )) * D_DOWNTIME_TEN );
//	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );


/*****	�㳲�б���TBCS0065��	Start									��������2003.04.23	*****/
//	os_trcget2( D_MD_OSSNSTM, D_T_TRA_OUT, 1, lMSec );
//	return( lMSec );								// �ߥ��ä��ֵѤ���λ

													// ��׻��֤򣱣��ߥ���ñ�̤��Ѵ�
	lRetTMsec = lMSum / D_DOWNTIME_TEN * D_DOWNTIME_TEN;
	DbgMsg01( DLv02, ( OutPut, "***** %s:lRetTMsec :%d \n", D_PROC_NAME, lRetTMsec ) );

	os_trcget2( D_MD_OSSNSTM, D_T_TRA_OUT, 1, lRetTMsec );
	return( lRetTMsec );
/*****	�㳲�б���TBCS0065��	 End									��������2003.04.23	*****/
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/

