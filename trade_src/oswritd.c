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
/* �㥵���ӥ�����̾��              �ǡ������                               */
/* �㥵���ӥ����ܣɣġ�            �أأأأأأ�                           */
/* ��⥸�塼��̾��                �ե�����ؤ�ľ�ܽ����                   */
/* ��⥸�塼��ɣġ�              oswritd                                  */
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
/*   �ǡ���ľ�ܽ����                                                       */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long oswritd( long fildes, char *buf, long len, long pos )          */
/*                                                                          */
/* �㲾������                                                               */
/*      long        fildes              �ե����뵭�һ�                      */
/*                                      ��0 < �ե����뵭�һ� <=             */
/*                                              �ե���������ơ��֥��      */
/*                                                         ���������������� */
/*      char        *buf                �ǡ�����Ǽ�Хåե�                  */
/*      long        len                 ����ߥ쥳���ɿ�(���ʾ�)            */
/*      long        pos                 ����߰���(���ʾ�)                  */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*     �������ǡ����ΥХ��ȿ�                                             */
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
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "oswritd.h"
#include "oswritd_ins.h"                // ���������ѡʸ��̡�
#include "osseek.h"                     // osseek��
#include "oswrite.h"                    // oswrite��

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    oswritd                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ǡ���ľ�ܽ����                                          */
/*                                                                          */
/****************************************************************************/
long oswritd( long fildes, char *buf, long len, long pos )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥����������

    long lCommonRet;                    // ���̴ؿ��꥿������
    long lWriteRet;                     // oswrite�꥿������
    long lCurPos;                       // �����ȥݥ������

	os_trcget2( D_MD_OSWRITD, D_T_TRA_IN, 4, fildes, buf, len, pos );

    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    if( len < D_RECORD_NUM )            // ����ߥ쥳���ɿ��Υ����å�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITD, D_T_ERR_PRA, 1, OSFEOOFB );
        return( OSFEOOFB );
    }
    
    lCommonRet = os_IsFileOpen( fildes );
                                        // �����ץ���Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �����ץ���Ǥʤ���
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // ���ͥ�����Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ���ͥ��ȥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITD, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������

    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( fildes=%d )\n", D_PROC_NAME, fildes ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd->pFilStm=%p )\n",
//    										D_PROC_NAME, ptTEflcTableInd->pFilStm ) );
    												
	os_trcget2( D_MD_OSWRITD, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
	lCurPos = ftell( ptTEflcTableInd->pFilStm );         // �����ȥݥ��������������
	os_trcget2( D_MD_OSWRITD, D_T_SYS_END, 1, lCurPos );
    
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ftell lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );

    if( lCurPos == D_ERR_SYS )          // �����˼��Ԥ�����
    {
        goto err_oswrit_ftell;
    }

//	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek)fildes=0x%ld \n",
//													D_PROC_NAME, fildes ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek)skmode=0x%ld \n",
//													D_PROC_NAME, D_SKMODE_TOP ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek1)pos=0x%08lx \n",
													D_PROC_NAME, pos ) );

                                        // ����߰��֤�����
    lCommonRet = osseek( fildes, D_SKMODE_TOP, pos );
	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek1)lCommonRet=0x%08lx \n",
													D_PROC_NAME, lCommonRet ) );

    if ( lCommonRet < D_NOT_SUCCESS )   // osseek�ֵ��ͤ��۾�ξ��
                                        // OSFERECPOS:�����С�������
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08lx ( %s: %s )\n",
									D_PROC_NAME, lCommonRet, "osseek", strerror(errno) ) );
        return( lCommonRet );
    }

//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( (oswrite)fildes=0x%ld )\n",
//													D_PROC_NAME, fildes ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( (oswrite)buf=0x%08lx )\n",
//													D_PROC_NAME, buf ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( (oswrite)len=0x%ld )\n",
//													D_PROC_NAME, len ) );

                                        // �ե���������
	lWriteRet = oswrite( fildes, buf, len ); 
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lWriteRet=0x%08lx )\n",
    												D_PROC_NAME, lWriteRet ) );

//	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek)fildes=0x%ld \n",
//	   												D_PROC_NAME, fildes ) );
//	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek)skmode=0x%ld \n",
//													D_PROC_NAME, D_SKMODE_TOP ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek2)pos=0x%08lx \n",
													D_PROC_NAME, lCurPos ) );

                                        // ����߰��֤�����(����������᤹)
	lCommonRet = osseek( fildes, D_SKMODE_TOP, lCurPos );
	DbgMsg01( DLv04, ( OutPut, "***** %s: (osseek2)lCommonRet=0x%08lx \n",
													D_PROC_NAME, lCommonRet ) );

    if ( lCommonRet < D_NOT_SUCCESS )   // osseek�ֵ��ͤ��۾�ξ��
                                        // OSFERECPOS:�����С�������
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08lx ( %s: %s )\n",
									D_PROC_NAME, lCommonRet, "osseek", strerror(errno) ) );
        return( lCommonRet );
    }

	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSWRITD, D_T_TRA_OUT, 1, lWriteRet );
    return( lWriteRet );                // oswrite���ֵ���

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_oswrit_ftell:
    switch( errno )
    {
        case EBADF:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEOOFB, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITD, D_T_ERR_SYS, 1, errno    );
            return( OSFEOOFB );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITD, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSWRITD << 16) | D_T_ERR_SYS );
			//return( -1 );               // ���ܡ��ɽ���
   }
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/