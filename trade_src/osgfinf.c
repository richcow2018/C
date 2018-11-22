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
/* �㥵���ӥ�����̾��				 ����														*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ե�����������											*/
/* ��⥸�塼��ɣġ�				 osgfinf													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼����:�أأأ�)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*    �ե����������������                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscreat.h>																	*/
/*																								*/
/*      long osgfinf( long fildes, long attr,struct osf_info *info,         */
/*                                                        long bufsiz )     */
/*																								*/
/* �㲾������																					*/
/*      long        fildes              �ե����뵭�һ�                      */
/*                                      ��0 < �ե����뵭�һ� <=             */
/*                                              �ե���������ơ��֥��      */
/*                                                         ���������������� */
/*      long        *path               �����оݥե�����ѥ�̾              */
/*      long        attr                °�����̥�����                      */
/*      struct osf_info *info           �ե���������Ǽ�Хåե�            */
/*      long        bufsiz              �Хåե�������                      */
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ	                                               				*/
/*                         ���󥵥���                                                           */
/*		�۾ｪλ			-1																	*/
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
/******************************** ɸ��إå����ե����� **********************/
#include <sys/stat.h>                   // �ե�������������
#include <string.h>                     // strcpy��
#include <time.h>                       // Time�ط���
#include <errno.h>                      // ���顼�Σ������
/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osgfinf_ins.h"                // ���������ѡʸ��̡�
#include "osgfinf.h"

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osgfinf                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե����������������                                    */
/*                                                                          */
/****************************************************************************/
long osgfinf( long fildes, long attr, struct osf_info *info, long bufsiz )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥������

    long lCommonRet;                    // ���̴ؿ��꥿������
    long lDate;                         // ���ʲ������ʲ����ͤ�
                                        // ���ꤹ���ѿ������ա�
    long lTime;                         // ���ʲ������ʲ����ͤ�
                                        // ���ꤹ���ѿ��ʻ��֡�
    int iStatRet;                       // stat���ֵ���
    long lOs_Date2DayTimeRet;           // os_Date2DayTimeRet���ֵ���
    long lRetSize;                      // ������ѿ�
    char *pcCtimeRet;                   // Ctime���ֵ���
    struct stat tStatbuf;               // stat��¤��
    char acFilename[ D_FILENAME_MAX ];  // �ե�����̾��ʸ����

    char acWday[ D_WDAY_MAX ][ D_CHAR_SIZE ] = { D_SUN, D_MON, D_TRU, D_WED, 
                                                        D_THU, D_FRI, D_SAT };
                                        // �����Ѥ�������������ڡ�
    char acMon[ D_MON_MAX ][ D_CHAR_SIZE ] = { D_JAN, D_FEB, D_MAR, D_APR, 
                                               D_MAY, D_JUN, D_JUL, D_AUG,
                                               D_SEP, D_OCT, D_NOV, D_DEC };
                                        // ���Ѥ�����ʣ���飱�����
    int iTemp;                          // ������ѿ�
    
    struct tm tStTime;                  // tm��¤��
    char acWdaySet[ D_CHAR_SIZE ];      // ����
    char acMonSet[ D_CHAR_SIZE ];       // ��
    int iDay;                           // ��
    char acTimeSet[ D_TIME_SIZE ];      // ���� hh:mm:ss
    int iYear;                          // ǯ
    int iHour;                          // ��
    int iMin;                           // ʬ
    int iSec;                           // ��

	os_trcget2( D_MD_OSGFINF, D_T_TRA_IN, 4, fildes, attr, info, bufsiz );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );           // �ե����뵭�һҥ��顼�λ�
    }

    if( attr != D_ATTR_OK )             // °�����̤Υ����å� �ϰϤλ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEPARMV ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_PRA, 1, OSFEPARMV );
        return( OSFEPARMV );            // °�����顼
    }

    if( sizeof( struct osf_info ) > bufsiz )
                                        // �Хåե��������Υ����å�
                                        // osf_info��¤�ΰʲ��λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFEIOBUF ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_PRA, 1, OSFEIOBUF );
        return( OSFEIOBUF );            // �Хåե�������
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
    lCommonRet = os_IsFileConnect( fildes );
                                        // ���ͥ�����Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ���ͥ��ȥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }
	
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
    strcpy( acFilename, ptTEflcTableInd->acFileName );
                                        // �б�����ե�����̾���������

	os_trcget2( D_MD_OSGFINF, D_T_SYS_STAT, 2, acFilename, &tStatbuf );
    iStatRet = stat( acFilename, &tStatbuf );
                                        // �ե�����ξ�����������
	os_trcget2( D_MD_OSGFINF, D_T_SYS_END, 1, iStatRet );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStatRet=0x%08x )\n",
    												D_PROC_NAME, iStatRet ) );
    												
    if( iStatRet == D_ERR_SYS )         // �������顼��
    {
        goto err_osgfinf;
    }

	os_trcget2( D_MD_OSGFINF, D_T_SYS_CTIME, 1, &tStatbuf.st_mtime );
    pcCtimeRet = ctime( &tStatbuf.st_mtime );
                                        // �ե����빹��������ʸ������ѹ�����
	os_trcget2( D_MD_OSGFINF, D_T_SYS_END, 2, pcCtimeRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pcCtimeRet=%p )\n",
    												D_PROC_NAME, pcCtimeRet ) );
    												
    if( pcCtimeRet == NULL )            // �ѹ����Ԥλ�
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ctime", strerror(errno) ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, -1 );
		
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

    sscanf( pcCtimeRet,"%s %s %d %s %d", acWdaySet, acMonSet, 
                                                    &iDay, acTimeSet, &iYear );
                                        // ʸ����������ڤ���ѿ������ꤹ��    
    sscanf( acTimeSet,"%d:%d:%d", &iHour, &iMin, &iSec );
                                        // ʸ�����:���ڤ���ѿ������ꤹ��

    tStTime.tm_sec = iSec;              // �ե������Ǽ�Хåե����á�����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_sec=%d )\n",
    												D_PROC_NAME, tStTime.tm_sec ) );
    tStTime.tm_min = iMin;              // �ե������Ǽ�Хåե���ʬ������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_min=%d )\n",
    												D_PROC_NAME, tStTime.tm_min ) );
    tStTime.tm_hour = iHour;            // �ե������Ǽ�Хåե�����������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_hour=%d )\n",
    												D_PROC_NAME, tStTime.tm_hour ) );
    tStTime.tm_mday = iDay;             // �ե������Ǽ�Хåե�����������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_mday=%d )\n",
    												D_PROC_NAME, tStTime.tm_mday ) );

    for( iTemp = D_MON_MIN - 1; iTemp < D_MON_MAX; iTemp++ )
                                        // ʸ���󡡷Ʊ��Τ�Τ�õ��
    {
       if( strcmp( acMonSet, acMon[ iTemp ] ) == D_STRING_EQUAL ) 
                                        // Ʊ��ξ��
       {
			tStTime.tm_mon = iTemp;      // �ե������Ǽ�Хåե��������
                                        // ��ʷ�ϡݣ����ͤ����ꤹ���
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_mon=%d )\n",
    												D_PROC_NAME, tStTime.tm_mon ) );
           break;
       }
    }

    tStTime.tm_year = iYear - D_YEAR_1900;           
                                        // os_Date2DayTime��ǯ�ե����ޥåȤ�
                                        // ��碌��
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_year=%d )\n",
    												D_PROC_NAME, tStTime.tm_year ) );

    for( iTemp = D_WDAY_MIN - 1; iTemp < D_WDAY_MAX; iTemp++ )
                                        // ʸ����������Ʊ��Τ�Τ�õ��
    {
        if( strcmp( acWdaySet, acWday[ iTemp ] ) == D_STRING_EQUAL )  
                                        // Ʊ��ξ��
        {
            tStTime.tm_wday = iTemp;    // �ե������Ǽ�Хåե�������������
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStTime.tm_wday=%d )\n",
    												D_PROC_NAME, tStTime.tm_wday ) );
            break;
        }
    }

    lOs_Date2DayTimeRet = os_Date2DayTime( &tStTime, &lDate, &lTime );
                                        // ���������ջ�����Ѵ�����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lOs_Date2DayTimeRet=0x%08lx )\n",
    												D_PROC_NAME, lOs_Date2DayTimeRet ) );
    												
    if( lOs_Date2DayTimeRet != NORMAL )	// �����Ѵ��˼��Ԥ�����
                                        // ǯ���顼�Ϥ����ǥ��顼�Ȥʤ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

    info->mdate = lDate;                // �ե����빹�����դ�����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->mdate=%ld )\n",
    												D_PROC_NAME, info->mdate ) );
    info->mtime = lTime;                // �ե����빹�����֤�����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->mtime=%ld )\n",
    												D_PROC_NAME, info->mtime ) );
    info->rsize = D_RECORD_SIZE;        // �쥳���ɥ�����������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->rsize=%ld )\n",
    												D_PROC_NAME, info->rsize ) );
    info->filsiz = tStatbuf.st_size;    // �ե����륵����������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->filsiz=%ld )\n",
    												D_PROC_NAME, info->filsiz ) );
    info->datsiz = tStatbuf.st_size;    // ʪ���ΰ襵����������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( info->datsiz=%ld )\n",
    												D_PROC_NAME, info->datsiz ) );
    strcpy( info->fname ,acFilename );  // �ե�����̾������

    lRetSize = sizeof( info->mdate ) + sizeof( info->mtime )
               + sizeof( info->rsize ) + sizeof( info->filsiz )
               + sizeof( info->datsiz ) + sizeof( info->fname );
                                        // �����ֵ��ͤ��ͤ�׻�����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRetSize=%ld )\n",
    												D_PROC_NAME, lRetSize ) );
    												
//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSGFINF, D_T_TRA_OUT, 1, lRetSize );
    return( lRetSize );                 // �����ͥ꥿����

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_osgfinf:
    switch( errno )
    {
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;
        
        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;
        
        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSGFINF, D_T_ERR_SYS, 2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSGFINF << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
