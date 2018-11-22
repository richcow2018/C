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
/* ��⥸�塼��̾��                �ե����롿�ǥ��쥯�ȥ�κ��             */
/* ��⥸�塼��ɣġ�              osdelet                                  */
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
/*   �ե����롦�ü�ե�����κ��                                           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long osdelet( long fildes )                                         */
/*                                                                          */
/* �㲾������                                                               */
/*      long        fildes              �ե����뵭�һ�                      */
/*                                      ��0 < �ե����뵭�һ� <=             */
/*                                              �ե���������ơ��֥��      */
/*                                                         ���������������� */
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
#include <stdio.h>                      // remove��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osdelet.h"
#include "osdelet_ins.h"                // ���������ѡʸ��̡�
#include "osclose.h"
#include "osdconn.h"

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osdelet                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե����롦�ü�ե�����κ��                              */
/*                                                                          */
/****************************************************************************/
long osdelet( long fildes )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥������

    long lCommonRet;                    // ���̴ؿ��꥿������
    int  iRemoveRet;                    // ���̴ؿ��꥿������

	os_trcget2( D_MD_OSDELET, D_T_TRA_IN, 1, fildes );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileOpen( fildes );
                                        // �����ץ���Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet == NORMAL )          // �����ץ���λ�
    {
        lCommonRet = osclose( fildes ); // �ե����륯����
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
        
        if( lCommonRet != NORMAL )      // �۾ｪλ��
        {
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx ( %s: %s )\n",
									D_PROC_NAME, lCommonRet, "osclose", strerror(errno) ) );
			os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, lCommonRet );
            return( lCommonRet );
        }
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // ���ͥ�����Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ���ͥ��ȥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
	os_trcget2( D_MD_OSDELET, D_T_SYS_REMOVE, 1, ptTEflcTableInd->acFileName );
    iRemoveRet = remove( ptTEflcTableInd->acFileName );
                                        // �ե�����κ��
	os_trcget2( D_MD_OSDELET, D_T_SYS_END, 1, iRemoveRet );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRemoveRet=%d )\n",
    												D_PROC_NAME, iRemoveRet ) );
    												
    if( iRemoveRet == D_ERR_SYS )
    {
        goto err_osdelet;
    }

    lCommonRet = osdconn( fildes );     // �ե�����ȥץ�����Ϣ����ڤ�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    if( lCommonRet != NORMAL )
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx ( %s: %s )\n",
									D_PROC_NAME, lCommonRet, "osdconn", strerror(errno) ) );
		os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSDELET, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // �������ֵ�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_osdelet:
    switch( errno )
    {
        case EACCES:
        case EPERM:
        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACCD, "remove", strerror(errno) ) );
			os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, errno    );
            return( OSFEACCD );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "remove", strerror(errno) ) );
			os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, errno  );
            return( OSFENOFILE );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "remove", strerror(errno) ) );
			os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1, errno    );
            return( OSEEWKEX );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "remove", strerror(errno) ) );
			os_trcget2( D_MD_OSDELET, D_T_ERR_SYS, 1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELET << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
