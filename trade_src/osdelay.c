/************************************************************************************************/
/*	���	��������							                               					*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�أأءݣӣͣХ����ƥ�	���̴ؿ�			��mc_xxxx�ϡ�							*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 ����������													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ץ������ٱ�												*/
/* ��⥸�塼��ɣġ�				 osdelay													*/
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
/* �����ԡ��Ḷ                                                             */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ10��21��                                                   */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/* �ѹ�����2002ǯ12��17��                                                   */
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ץ������ٱ�																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osdelay.h>																	*/
/*																								*/
/*	   	long	osdelay( long times, long unit )												*/
/*																								*/
/* �㲾������																					*/
/*		long	times;			�ٱ���֡�1�ʾ�����͡�											*/
/*		long	unit;			ñ�̻��֡�1���ߥ��� 2���� 3��ʬ 4������							*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEITIM																*/
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
#include <time.h>
#include <string.h>
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osdelay.h"
#include "osdelay_ins.h"				// ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ���ץ������ٱ�                                                     */
/* ��������2002ǯ10��21��                                                   */
/* �ѹ�����2002ǯ12��17��                                                   */
/* �����ԡ��Ḷ                                                             */
/* �ƽз�����                                                               */
/*   long delay( long times, long unit )                                    */
/*     long times              �ٱ����                                     */
/*     long unit               ñ�̻���                                     */
/*                                                                          */
/****************************************************************************/
long osdelay( long times, long unit )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    long lNSec;							// �ʥ���
	struct timespec tStopTime;			// ��߻��ֳ�Ǽ��
    struct timespec tRStopTime;			// �Ĥ���߻��ֳ�Ǽ��
    int iRet;							// �ؿ��η���ֵ�
    
	os_trcget2( D_MD_OSDELAY, D_T_TRA_IN, 2, times, unit  );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
    
	/******* 2002.12.16 *********/
	/******* �����ѹ����Τ�������ɲ�(0�����å�) *******/
		
    if( D_TIME_MIN > times )			// �ٱ���֤��Ǿ��ͤ�꾮������
    {
		if( D_TIME_ZERO == times )		// �ٱ���֤�0�λ�
		{
			DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
			
			os_trcget2( D_MD_OSDELAY, D_T_ERR_PRA, 1, NORMAL );
			
			return( NORMAL );
		}
		else							// �ٱ���֤����ͤλ�
		{
	    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
	    														D_PROC_NAME, OSEEITIM ) );
	    	
	    	os_trcget2( D_MD_OSDELAY, D_T_ERR_PRA, 1, OSEEITIM );													
	    														
	        return( OSEEITIM );			// OSEEITIM���ֵ�
	    }
    }
    
/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
    switch( unit )
    {
		case D_UNIT_MSEC:				// ñ�̻��֤��ߥ��äλ�
			tStopTime.tv_sec = ( time_t )( times / D_MSEC_VAL );
										// �ä�����
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );

			lNSec = ((( long )(( times % D_MSEC_VAL ) + ( D_UPTIME_TEN - 1 )) / D_UPTIME_TEN )) 
															     * D_UPTIME_TEN * D_MNSEC_VAL;
										// �ʥ��ü������ھ夲������
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lNSec=%ld )\n",
																D_PROC_NAME, lNSec ) );

 			if( D_NSEC_VAL > lNSec )	// �ʥ��ä�1�ä�����Υʥ��ä�꾮������
			{
				tStopTime.tv_nsec = lNSec;
										// �ʥ��ä�����
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// �ʥ��ä�1�ä�����Υʥ��ä���礭����
			{
				tStopTime.tv_sec++;		// �ä������1�û���
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = lNSec - D_NSEC_VAL;
										// �ʥ�������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			break;
			
		case D_UNIT_SEC:				// ñ�̻��֤��äλ�
			tStopTime.tv_sec = times;	// �ä�����
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
			tStopTime.tv_nsec = 0;		// �ʥ��ä�����
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			break;
			
		case D_UNIT_MINUTE:				// ñ�̻��֤�ʬ�λ�
			if( D_MIN_MAX >= times )	// �ٱ���֤������Ͱʲ��ξ��
			{
				tStopTime.tv_sec = ( times * 60 );
										// �ä������ʬ���ä��Ѵ���
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = 0;	// �ʥ�������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// �ٱ���֤������ͤ�Ķ���Ƥ������
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   				os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEITIM );	
    														
				return( OSEEITIM );		// OSEEITIM���ֵ�
			}
			break;
			
		case D_UNIT_HOUR:				// ñ�̻��֤����λ�
			if( D_HOUR_MAX >= times )	// �ٱ���֤������Ͱʲ��ξ��
			{
				tStopTime.tv_sec = ( times * 60 * 60 );
										// �ä�����ʻ����ä��Ѵ���
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
				tStopTime.tv_nsec = 0;	// �ʥ�������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );
			}
			else						// �ٱ���֤������ͤ�Ķ���Ƥ������
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    			
    			os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEITIM );									
    														
				return( OSEEITIM );		// OSEEITIM���ֵ�
			}
			break;
			
		default:						// ñ�̻��֤�����¾�λ�
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    														D_PROC_NAME, OSEEITIM ) );
    														
   			os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 1, OSEEIUNI );	
    														
        	return( OSEEIUNI );			// OSEEIUNI���ֵ�
	}
	
	for( ; ; )
	{
		os_trcget2( D_MD_OSDELAY, D_T_SYS_NANOSLEEP, 2, &tStopTime, &tRStopTime );
		iRet = nanosleep( &tStopTime, &tRStopTime );
										// �ٱ������¹�
		os_trcget2( D_MD_OSDELAY, D_T_SYS_END, 2, iRet, errno );
										
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
																D_PROC_NAME, iRet ) );
		if( D_ERR_SYS == iRet )			// �ٱ���˳����ߤ����ä���
		{
			switch( errno )
			{
				case EINTR:				// EINTR�λ�
					tStopTime.tv_sec = tRStopTime.tv_sec;
										// �Ĥ��ä�����
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: ( %s: %s )\n",
									D_PROC_NAME, "nanosleep", strerror(errno) ) );
									
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_sec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_sec ) );
					tStopTime.tv_nsec = tRStopTime.tv_nsec;
										// �Ĥ�ʥ��ä�����
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStopTime.tv_nsec=%ld )\n",
																D_PROC_NAME, tStopTime.tv_nsec ) );

					break;
					
				default:				// ����¾�λ�
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "nanosleep", strerror(errno) ) );
									
					os_trcget2( D_MD_OSDELAY, D_T_ERR_SYS, 2, -1 , errno );	
					os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELAY << 16) | D_T_ERR_SYS );
					//return( -1 );		// ���ܡ��Ƚ���
	        }
	    }
	    else							// �ٱ��������λ������
	    {
			break;						// ������ȴ����
		}
	}
	
//	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	
	os_trcget2( D_MD_OSDELAY, D_T_TRA_OUT, 1, NORMAL );
	
	return( NORMAL );					// NORMAL���ֵѤ���λ
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

