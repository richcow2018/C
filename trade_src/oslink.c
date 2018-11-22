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
/* �㥵���ӥ�����̾��              �ե����롿�ǥ��쥯�ȥ�����             */
/* �㥵���ӥ����ܣɣġ�            �أأأأأأ�                           */
/* ��⥸�塼��̾��                �ե�����ؤΥ��                       */
/* ��⥸�塼��ɣġ�              oslink                                   */
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
/* �㥽���������ԡ�                �ã»��ӥ��ͥ����ô��(��ݥ�:�أأأ�)  */
/* �㥽��������ǯ������            ��������ǯ�����������                 */
/* �㥽���������ԡ�                                                         */
/* �㥽������ǯ�����ڤӽ����ɣġ�                                           */
/*--------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���              ���ƥå�                                 */
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                             */
/*   �ե�����ؤΥ��                                                     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long oslink( char *path1, char *path2 )                             */
/*                                                                          */
/* �㲾������                                                               */
/*      char         *path1              ��¸�ե�����ѥ�̾                 */
/*      char         *path2              ������Ϳ����ѥ�̾                 */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*     0L                                                                   */
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
#include <errno.h>                      // ���顼�Σ������
#include <stdio.h>                      // 
#include <unistd.h>                     // link��
#include <sys/stat.h>                   // stat��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "oslink.h"
#include "oslink_ins.h"                // ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    oslink                                                    */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե�����ؤΥ��                                        */
/*                                                                          */
/****************************************************************************/
long oslink( char *path1, char *path2 )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    int iCommonRet;                     // ���̴ؿ����ֵ���
    struct stat tStatBuf;               // stat�ѥХåե�

	os_trcget2( D_MD_OSLINK, D_T_TRA_IN, 2, path1, path2 );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OSLINK, D_T_SYS_STAT, 2, path1, &tStatBuf );
    iCommonRet = stat( path1, &tStatBuf ); 
                                        // �ե�����ξ��֤��������
	os_trcget2( D_MD_OSLINK, D_T_SYS_END, 1, iCommonRet );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );
    												
    if( iCommonRet == D_ERR_SYS )       // �����˼��Ԥ�����
    {
        goto err_oslink_stat;
    }

    if( !S_ISREG(tStatBuf.st_mode) )    // �̾�ե����뤫�����å�
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    												D_PROC_NAME, OSFEPATHDR ) );
		os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
        return( OSFEPATHDR );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSLINK, D_T_SYS_LINK, 2, path1, path2 );
    iCommonRet = link( path1, path2 );  // ��󥯤κ���
	os_trcget2( D_MD_OSLINK, D_T_SYS_END, 1, iCommonRet );
    
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );
    if( iCommonRet == D_ERR_SYS )       // �������Ի�
    {
        goto err_oslink;
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSLINK, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // �������ֵ�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_oslink_stat:
    switch( errno )
    {
        case ENOENT:
        case ENOTDIR:
        case ELOOP:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATHDR, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
            return( OSFEPATHDR );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATH );
            return( OSFEPATH );
            break;

        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "stat", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSLINK << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
   
err_oslink:
    switch( errno )
    {
        case EXDEV:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFELINK, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFELINK );
            return( OSFELINK );
            break;

        case EFAULT:
        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case EACCES:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATH );
            return( OSFEPATH );
            break;

        case ENOMEM:
        case ENOSPC:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;

        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFERDVC, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFERDVC );
            return( OSFERDVC );
            break;

        case EEXIST:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEDUPFIL, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEDUPFIL );
            return( OSFEDUPFIL );
            break;

        case EPERM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATHDR, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 1, OSFEPATHDR );
            return( OSFEPATHDR );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "link", strerror(errno) ) );
			os_trcget2( D_MD_OSLINK, D_T_ERR_SYS, 2, -1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSLINK << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
