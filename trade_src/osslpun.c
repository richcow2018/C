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
/* ��⥸�塼��̾��					 ���������ޤǤ��ٱ�											*/
/* ��⥸�塼��ɣġ�				 osslpun													*/
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
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ10��21��                                                   */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���������ޤǤ��ٱ�																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osslpun.h>																	*/
/*																								*/
/*	   	long	osslpun( long day, long time )													*/
/*																								*/
/* �㲾������																					*/
/*		long	day;		����																*/
/*		long	time;		����																*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEIVAL																*/
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
#include "osslpun.h"
#include "osslpun_ins.h"				// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ�����������ޤǤ��ٱ�                                                 */
/* ��������2002ǯ10��21��                                                   */
/* �ѹ�����                                                                 */
/* �����ԡ��Ḷ                                                             */
/* �ƽз�����                                                               */
/*   long osslpun( long day, long time )                                    */
/*     long day            ����                                             */
/*     long time           ����                                             */
/*                                                                          */
/****************************************************************************/
long osslpun( long day, long time )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	int iRet;							// �ؿ��η���ֵ�
	long lRet;							// ���̴ؿ��η���ֵ�
	time_t lDelayTime;					// �ٱ���������ηв��ÿ�
	struct timeval tNowTime;			// ���ֳ�Ǽ��
	long lNowTime;						// ��������
	struct tm tDate;					// ������Ǽ��
	struct tm *ptDate;					// ������Ǽ�Υݥ���
	struct timespec tStopTime;			// ��߻��ֳ�Ǽ��
    struct timespec tRStopTime;			// �Ĥ���߻��ֳ�Ǽ��
    long lTmp = 0;
    
	os_trcget2( D_MD_OSSLPUN , D_T_TRA_IN, 2, day, time );
    
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
	
										// 20030313 �����ѹ�SSLA0017
	if(0 == day)						// ���դ����λ������������դ�����
	{
		lRet = osgtdat(&day, &lTmp);
		if(NORMAL != lRet)
			return(lRet);
	}
	
	lRet = os_DayTime2Date( day, time, &tDate );
										// ���ջ�����������Ѵ�
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );
	
	if( NORMAL != lRet )				// �����Ѵ��˼��Ԥ�����
	{
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSEEIVAL ) );
    														
		os_trcget2( D_MD_OSSLPUN , D_T_ERR_PRA, 1, OSEEIVAL );    														
    														
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	
 	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_MKTIME, 1, &tDate );    
		
	lDelayTime = mktime( &tDate );		// �ٱ���������ηв��ÿ�����
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_END, 1, lDelayTime );
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lDelayTime=%ld )\n",
														D_PROC_NAME, lDelayTime ) );
	if( D_ERR_SYS == lDelayTime )		// �в��ÿ������˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN,  D_T_ERR_SYS, 1, errno    );
									
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_GETTIMEOFDAY, 2, &tNowTime, NULL );  
	
	iRet = gettimeofday( &tNowTime, NULL );
										// ���������ηв��ÿ��ʶ�����������ˤ����
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n", D_PROC_NAME, iRet ) );
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, iRet ); 
	
	if( D_ERR_SYS == iRet )				// �в��ÿ������˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEESETE, "gettimeofday", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, errno    ); 
									
		return( OSEESETE );				// OSEESETE���ֵ�
	}
	
	
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_LOCALTIME, 1, &tNowTime.tv_sec ); 
	
	ptDate = localtime( &tNowTime.tv_sec );
										// �����������狼������륿������Ѵ�
										
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, ptDate ); 
										
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptDate=%p )\n", D_PROC_NAME, ptDate ) );
	
	if( D_ERR_SYS == ( long )ptDate )	// �����륿�����Ѵ��˼��Ԥ�����
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "localtime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, errno    ); 
									
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_MKTIME, 1, ptDate ); 
	
	lNowTime = mktime( ptDate );		// ���������ηв��ÿ��μ���
	
	os_trcget2( D_MD_OSSLPUN,  D_T_SYS_END, 1, lNowTime ); 
	
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lNowTime=%ld )\n",
														D_PROC_NAME, lNowTime ) );
	if( D_ERR_SYS == lNowTime )			// �в��ÿ������˼��Ԥ�����
	{
		os_trcget2( D_MD_OSSLPUN,  D_T_ERR_SYS, 1, OSEEIVAL ); 
		
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "mktime", strerror(errno) ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_DIFFTIME, 2, lDelayTime, lNowTime ); 
	
	tStopTime.tv_sec = difftime( lDelayTime, lNowTime );
										// �ä�������ٱ��ÿ��򻻽С�
										
	os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 1, tStopTime.tv_sec ); 
										
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
														D_PROC_NAME, tStopTime.tv_sec ) );
	if( D_TIME_MIN > tStopTime.tv_sec )	// �ä�1̤���λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEIVAL, "difftime", strerror(errno) ) );
									
		os_trcget2( D_MD_OSSLPUN, D_T_ERR_SYS, 1, OSEEIVAL ); 
									
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	tStopTime.tv_nsec = 0;				// �ʥ��ä�����
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
														D_PROC_NAME, tStopTime.tv_nsec ) );
	for( ; ; )
	{
		os_trcget2( D_MD_OSSLPUN, D_T_SYS_NANOSLEEP, 2, &tStopTime, &tRStopTime );
		iRet = nanosleep( &tStopTime, &tRStopTime );
										// �ٱ�����μ¹�
		os_trcget2( D_MD_OSSLPUN, D_T_SYS_END, 2, iRet, errno );
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
																D_PROC_NAME, iRet ) );
		if( D_ERR_SYS == iRet )			// �ٱ���˳����ߤ����ä���
		{
			switch( errno )
			{
				case EINTR:
					tStopTime.tv_sec = tRStopTime.tv_sec;
										// �Ĥ��ä�����
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: ( %s: %s )\n",
									D_PROC_NAME, "nanosleep", strerror(errno) ) );
									
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
					tStopTime.tv_nsec = tRStopTime.tv_nsec;
										// �Ĥ�ʥ��ä�����
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
					break;
					
				default:
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "nanosleep", strerror(errno) ) );
									
					os_trcget2( D_MD_OSSLPUN , D_T_ERR_SYS, 1, errno );  
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSLPUN << 16) | D_T_ERR_SYS );
	        		//return( -1 );		// ���ܡ��Ƚ���
	        }
	    }
		else							// �ٱ��������λ������
		{
			break;						// ������ȴ����
		}
	}
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSSLPUN , D_T_TRA_OUT, 1, NORMAL );  
	
	return( NORMAL );					// NORMAL���ֵѤ���λ
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/

