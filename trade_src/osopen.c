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
/* ��⥸�塼��̾��                �ե�����Υ����ץ�                       */
/* ��⥸�塼��ɣġ�              osopen                                   */
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
/* �㥽��������ǯ������            ��������ǯ���������                   */
/* �㥽���������ԡ�                                                         */
/* �㥽������ǯ�����ڤӽ����ɣġ�                                           */
/*--------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���              ���ƥå�                                 */
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                             */
/*   �أأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأ�     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long osopen( long fildes, long access, long method,                 */
/*                     long exprsiz, long bsize, long limit )               */
/*                                                                          */
/* �㲾������                                                               */
/*      long        fildes              �ե����뵭�һ�                      */
/*                                      ��0 < �ե����뵭�һ� <=             */
/*                                              �ե���������ơ��֥��      */
/*                                                         ���������������� */
/*      long        access              ��������������                      */
/*                                             0x00000002���ɹ���           */
/*                                             0x00000004�������           */
/*                                             0x00000006���ɤ߽�         */
/*      long        method              ��������ˡ�ʻ��Ѥ��ʤ���            */
/*      long        exprsiz             ����쥳���ɥ�����(���Ѥ��ʤ�)      */
/*      long        bsize               ����֥�å�������(���Ѥ��ʤ�)      */
/*      long        limit               ��¾�����ץ󶥹�������Ԥ�����      */
/*                                                        (���Ѥ��ʤ�)      */
/* ���ֵ��͡�                                                               */
/*     1L                                                                   */
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
#include <errno.h>                     	// ���顼�Σ������
#include <stdio.h>                     	// osopen��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osopen.h"
#include "osopen_ins.h"                	// ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osopen                                                    */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե�����򥪡��ץ󤹤롣                                  */
/*                                                                          */
/****************************************************************************/
long osopen( long fildes, long access, long method, long exprsiz, 
                                                    long bsize, long limit )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥����������

    long lCommonRet;                    // ���̴ؿ��꥿������
    FILE *pFilStm = NULL;               // �ե�����ݥ���

	os_trcget2( D_MD_OSOPEN, D_T_TRA_IN, 6, fildes, access, 
											method, exprsiz, bsize, limit );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileConnect( fildes );
                                        // ���ͥ�����Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // ���ͥ��ȥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
    if( access & D_FILE_WRITE )			// ����ߥ⡼�ɤλ�
    {
		os_trcget2( D_MD_OSOPEN, D_T_SYS_FOPEN, 2, ptTEflcTableInd->acFileName, 
																D_CHAR_FILE_RW );
        pFilStm = fopen( ptTEflcTableInd->acFileName, D_CHAR_FILE_RW );
        								// �ɽ񤭥⡼�ɤǥե�����򥪡��ץ�
		os_trcget2( D_MD_OSOPEN, D_T_SYS_END, 1, pFilStm );
        								
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );
                                        
    }
    else if( access & D_FILE_READ )		// �ɹ��ߥ⡼�ɤλ�
    {
		os_trcget2( D_MD_OSOPEN, D_T_SYS_FOPEN, 2, ptTEflcTableInd->acFileName, 
															D_CHAR_FILE_READ );
        pFilStm = fopen( ptTEflcTableInd->acFileName, D_CHAR_FILE_READ );
                                        // �ɹ��ߥ⡼�ɤǥե�����򥪡��ץ�
		os_trcget2( D_MD_OSOPEN, D_T_SYS_END, 1, pFilStm );
                                        
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );
    }
    else								// �嵭�ʳ��λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFEACC ) );
		os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEACC );
        return( OSFEACC );
    }

    if( pFilStm == NULL )               // �ե����륪���ץ󥨥顼�λ�
    {
        goto err_osopen;
    }

    ptTEflcTableInd->pFilStm = pFilStm;	// �ե���������ơ��֥��
                                        // �ե����륹�ȥ꡼�����Ͽ����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd->pFilStm=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd->pFilStm ) );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSOPEN, D_T_TRA_OUT, 1, D_RECORD_SIZE );
    return( D_RECORD_SIZE );            // �����ͥ꥿����

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_osopen:
    switch( errno )
    {
        case EACCES:
        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;
        
        case EMFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
            break;  
        
        case ENFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFESFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, OSFESFILRS );
            return( OSFESFILRS );
            break;
    
        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSOPEN, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSOPEN << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
