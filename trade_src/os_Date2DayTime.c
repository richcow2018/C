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
/* �㥵���ӥ�����̾��				 ���̴ؿ�													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �أأأأأأ�												*/
/* ��⥸�塼��ɣġ�				 os_Date2DayTime											*/
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
/* ������:�Ḷ                                                               */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ������:2002ǯ10��3��                                                      */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���������ջ�����ѹ�																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_Date2DayTime.h>															*/
/*																								*/
/*	   	long	os_Date2DayTime( const struct tm *ptdate, long *dayp, long *timep)				*/
/*																								*/
/* �㲾������																					*/
/*		const struct tm 	*ptDate;			������¤��										*/
/*		long 				*dayp;				���ճ�Ǽ���									*/
/*		long 				*timep;				�����Ǽ���									*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			NORMAL																*/
/*		�۾ｪλ			OSEEIVAL															*/
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
#include "os_Date2DayTime_ins.h"

/*****************************************************************************/
/* ��ǽ:���������ջ�����Ѵ�                                                 */
/* ������:2002ǯ10��3��                                                      */
/* �ѹ���:                                                                   */
/* ������:�Ḷ                                                               */
/* �ƽз���:                                                                 */
/*   long os_Date2DayTime( const struct tm *ptDate, long *dayp, long *timep )*/
/*     const struct tm *ptDate          // ������¤��                        */
/*     long *dayp                       // ���ճ�Ǽ���                      */
/*     long *timep						// �����Ǽ���                      */
/*                                                                           */
/*****************************************************************************/
long os_Date2DayTime( const struct tm *ptDate, long *dayp, long *timep )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	long lDay = 0;						// ���ճ�Ǽ�ѿ�
	long lTime = 0;						// �����Ǽ�ѿ�
	
/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_DATE2DAYTIME ) );
	
	if(( D_YEAR_MID <= ptDate->tm_year ) && ( D_YEAR_MAX >= ptDate->tm_year ))
	{									// ǯ���ͤ�D_YEAR_MID��D_YEAR_MAX�λ�
		lDay += ( long )( ptDate->tm_year / 10 );
										// ǯ��10�ΰ�����
		lDay <<= 4;
		lDay += ( long )( ptDate->tm_year % 10 );
										// ǯ��1�ΰ�����
	}
	else if(( D_Y2K_MIN <= ptDate->tm_year ) && ( D_Y2K_MAX >= ptDate->tm_year ))
	{									// ǯ���ͤ�D_Y2K_MIN��D_Y2K_MAX�λ�
		lDay += ( long )(( ptDate->tm_year - 100 ) / 10 );
										// ǯ��10�ΰ�����
		lDay <<= 4;
		lDay += ( long )(( ptDate->tm_year - 100 ) % 10 );
										// ǯ��1�ΰ�����
	}
	else								// ǯ���ͤ��ϰϰʳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	switch( ptDate->tm_mon )
	{
		case 0:							// ����ͤ�0�λ�
		case 2:							// ����ͤ�2�λ�
		case 4:							// ����ͤ�4�λ�
		case 6:							// ����ͤ�6�λ�
		case 7:							// ����ͤ�7�λ�
		case 9:							// ����ͤ�9�λ�
		case 11:						// ����ͤ�11�λ�
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// ���10�ΰ�����
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// ���1�ΰ�����
		
			if(( 1 <= ptDate->tm_mday ) && ( 31 >= ptDate->tm_mday ))
			{							// �����ͤ�1��31�λ�
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday / 10 );
										// ����10�ΰ�����
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday % 10 );
										// ����1�ΰ�����
			}
			else						// �����ͤ��ϰϳ��λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
													 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
				return( OSEEIVAL );		// OSEEIVAL���ֵ�
			}
			break;
			
		case 3:							// ����ͤ�3�λ�
		case 5:							// ����ͤ�5�λ�
		case 8:							// ����ͤ�8�λ�
		case 10:						// ����ͤ�10�λ�
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// ���10�ΰ�����
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// ���1�ΰ�����
			if(( 1 <= ptDate->tm_mday ) && ( 30 >= ptDate->tm_mday ))
			{							// �����ͤ�1��30�λ�
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday / 10 );
										// ����10�ΰ�����
				lDay <<= 4;
				lDay += ( long )( ptDate->tm_mday % 10 );
										// ����1�ΰ�����
			}
			else						// �����ͤ��ϰϳ��λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
													 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
				return( OSEEIVAL );
			}
			break;
			
		case 1:							// ����ͤ�1�λ�
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) / 10 );
										// ���10�ΰ�����
			lDay <<= 4;
			lDay += ( long )(( ptDate->tm_mon + 1 ) % 10 );
										// ���1�ΰ�����
			if( 0 == ( ptDate->tm_year % 4))
			{							// ǯ��4�ǳ���ڤ���
				if(( 1 <= ptDate->tm_mday ) && ( 29 >= ptDate->tm_mday ))
				{						// �����ͤ�1��29�λ�
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday / 10 );
										// ����10�ΰ�����
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday % 10 );
										// ����1�ΰ�����
				}
				else					// �����ϰϳ��λ�
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
														 D_PROC_DATE2DAYTIME, OSEEIVAL ));
					return( OSEEIVAL );	// OSEEIVAL���ֵ�
				}
				break;
			}
			else						// ǯ��4�ǳ���ڤ�ʤ���
			{
				if(( 1 <= ptDate->tm_mday ) && ( 28 >= ptDate->tm_mday ))
				{						// �����ͤ�1��28�λ�
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday / 10 );
										// ����10�ΰ�����
					lDay <<= 4;
					lDay += ( long )( ptDate->tm_mday % 10 );
										// ����1�ΰ�����
				}
				else					// �����ϰϳ��λ�
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
														 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
					return( OSEEIVAL );	// OSEEIVAL���ֵ�
				}
				break;
			}
			
		default:						// ����ͤ�����¾�λ�
			DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
												 D_PROC_DATE2DAYTIME, OSEEIVAL ) );
			return( OSEEIVAL );			// OSEEIVAL���ֵ�
	}
	
	if(( D_WEEK_MIN <= ptDate->tm_wday ) && ( D_WEEK_MAX >= ptDate->tm_wday ))
	{									// �������ͤ�0��6�λ�
		lDay <<= 8;
		lDay += ( long )( ptDate->tm_wday );
										// ����������
	}
	else								// �������ͤ��ϰϳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	if(( 0 <= ptDate->tm_hour ) && ( 23 >= ptDate->tm_hour ))
	{									// �����ͤ�0��23�λ�
		lTime <<= 8;
		lTime += ( long )( ptDate->tm_hour / 10 );
										// ����10�ΰ�����
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_hour % 10 );
										// ����1�ΰ�����
	}
	else								// �����ͤ��ϰϳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	if(( 0 <= ptDate->tm_min ) && ( 59 >= ptDate->tm_min ))
	{									// ʬ���ͤ�0��59�λ�
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_min / 10 );
										// ʬ��10�ΰ�����
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_min % 10 );
										// ʬ��1�ΰ�����
	}
	else								// ʬ���ͤ��ϰϳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	if(( 0 <= ptDate->tm_sec ) && ( 59 >= ptDate->tm_sec ))
	{									// �ä��ͤ�0��59�λ�
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_sec / 10 );
										// �ä�10�ΰ�����
		lTime <<= 4;
		lTime += ( long )( ptDate->tm_sec % 10 );
										// �ä�1�ΰ�����
	}
	else								// ʬ���ͤ��ϰϳ��λ�
	{
		DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", D_PROC_DATE2DAYTIME, OSEEIVAL ) );
		return( OSEEIVAL );				// OSEEIVAL���ֵ�
	}
	
	*dayp = lDay;						// lDay�Υ��ɥ쥹����
	
	*timep = lTime;						// lTime�Υ��ɥ쥹����
	
	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_DATE2DAYTIME ) );
	return( NORMAL );					// NORMAL���ֵѤ���λ
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

