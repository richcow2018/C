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
/* �㥵���ӥ�����̾��              �ե����롿�ǥ��쥯�ȥ����               */
/* �㥵���ӥ����ܣɣġ�            �أأأأأأ�                           */
/* ��⥸�塼��̾��                �ե������ΰ���ڤ�Τ�                   */
/* ��⥸�塼��ɣġ�              ostrunc                                  */
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
/*   �ե������ΰ���ڤ�Τ�                                                 */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long ostrunc( long fildes )                                         */
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
#include <stdio.h>                      // 
#include <unistd.h>                     // ftruncate��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "ostrunc.h"
#include "ostrunc_ins.h"                // ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    ostrunc                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե������ΰ���ڤ�Τ�                                    */
/*                                                                          */
/****************************************************************************/
long ostrunc( long fildes )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥������

    long lCommonRet;                    // ���̴ؿ��꥿������
    int  iCommonRet;                    // ���̴ؿ��꥿������
    int iFilDes;                        // �ե�����ǥ������ץ꥿
    long lCurPos;                       // �����ȥݥ������

	os_trcget2( D_MD_OSTRUNC, D_T_TRA_IN, 1, fildes );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileOpen( fildes );
                                        // �����ץ���Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �����ץ���Ǥʤ���
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // ���ͥ�����Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ���ͥ��ȥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// �����ȥݥ��������������
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 1, lCurPos );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );
    
    if( lCurPos == D_ERR_SYS )          // �����˼��Ԥ�����
    {
        goto err_ostrunc_ftell;
    }

	os_trcget2( D_MD_OSTRUNC, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// �ե����륹�ȥ꡼�फ��
                                        // �ե�����ǥ������ץ꥿���������
	os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 2, iFilDes, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=0x%08x )\n",
    												D_PROC_NAME, iFilDes ) );
    												
    if( iFilDes == D_ERR_SYS )          // �����˼��Ԥ�����
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fileno", strerror(errno) ) );
		os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

    for(;;)                             // errno ��EINTR�δ֡������֤�
    {
		os_trcget2( D_MD_OSTRUNC, D_T_SYS_FTRUNCATE, 2, iFilDes, lCurPos );
        iCommonRet = ftruncate( iFilDes, lCurPos );
                                        // �ե�������ڤ�Τ�
		os_trcget2( D_MD_OSTRUNC, D_T_SYS_END, 1, iCommonRet );
                                        
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iCommonRet=0x%08x )\n",
    												D_PROC_NAME, iCommonRet ) );

        if( iCommonRet != D_ERR_SYS )   // �ե�������ڤ�Τ�����
        {
            break;
        }

        if( errno != EINTR )
        {
            goto err_ostrunc;
        }
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSTRUNC, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // �������ֵ�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_ostrunc_ftell:
    switch( errno )
    {
        case EBADF:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEOOFB, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEOOFB );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftell", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
			//return( -1 );               // ���ܡ��ɽ���
   }
   
err_ostrunc:
    switch( errno )
    {
        case EACCES:
        case EROFS:
        case EBADF:
        case EINVAL:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEACC );
            break;

        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, OSIDKE | OSIZZEDVC, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSIDKE | OSIZZEDVC );
            break;

        case EISDIR:
        case ELOOP:
        case ENAMETOOLONG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPATH, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFEPATH );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
            return( OSFENOFILE );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftruncate", strerror(errno) ) );
			os_trcget2( D_MD_OSTRUNC, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSTRUNC << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
