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
/* ��⥸�塼��̾��                �ե����������                           */
/* ��⥸�塼��ɣġ�              oscreat                                  */
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
/*   �ե����������                                                         */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/* ��ƽз�����                                                             */
/*      long oscreat( char *path, long aflags, long forg, long rorg,        */
/*                    long rsize, long bsize,  long exlen )                 */
/*                                                                          */
/* �㲾������                                                               */
/*      char        *path               �����оݥե�����ѥ�̾              */
/*                                      ����Ƭʸ���֡���                    */
/*                                        128ʸ������                       */
/*      long        aflags              �ե�����°���ե饰�ʻ��Ѥ��ʤ���    */
/*      long        forg                �ե����������ʻ��Ѥ��ʤ���          */
/*      long        rorg                �쥳���ɷ���(���Ѥ��ʤ�)            */
/*      long        rsize               �쥳���ɥ�����(���ʾ�)              */
/*      long        bsize               �֥�å�������(���Ѥ��ʤ�)          */
/*      long        exlen               ����ΰ襵����(���ʾ�)              */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*     �ե����뵭�һ�                                                       */
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
#include <errno.h>                     // ���顼�Σ������
#include <stdio.h>                     // fopen�ѡ�fflush�ѡ�fileno��
#include <string.h>                    // str��
#include <stdlib.h>                    // �ΰ������
#include <unistd.h>                    // fsync��

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "oscreat.h"
#include "oscreat_ins.h"               // ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    oscreat                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե�������������롣                                      */
/*                                                                          */
/****************************************************************************/
long oscreat( char *path, long aflags, long forg, long rorg, 
                                       long rsize, long bsize,  long exlen )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥������

    FILE *pFilStm = NULL;               // �ե�����ݥ���
    int iFilDes;                        // �ե�����ǥ������ץ꥿
    int iFilId;                         // �ե����뵭�һҥ��������
    int iStrcmpRet;                     // strcmp���ֵ���
    char *pcWbuf = NULL;                // �񤭹����ѥ��ꥢ
    size_t stStrlenRet;                 // �ե�����̾��Ĺ��
    int iConect = D_CONECT_FLAG_OFF;    // ���ͥ������ǧ�ѿ�
    size_t stFwriteRet;                 // fwrite���ֵ���

	os_trcget2( D_MD_OSCREAT, D_T_TRA_IN, 7, path, aflags, forg, 
												rorg, rsize, bsize, exlen );
    
	DbgMsg01( DLv02, ( OutPut, "***** %s:S Start Function\n", D_PROC_NAME ) );

    if( path[ 0 ] != D_FILE_PASS_SLASH )// ���Хե�����ѥ��Υ����å�
                                        // ����Ƭʸ����/���Ǥʤ�����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFEPATH );
        return( OSFEPATH );
    }

    stStrlenRet = strlen( path ) + 1;   // �ե�����ѥ��Υ��������������
                                        // NULL��ޤ�١ܣ�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stStrlenRet=%d )\n",
    												D_PROC_NAME, stStrlenRet ) );

    if( stStrlenRet > D_PATH_MAX )
                                        // �ե�����ѥ��Υ����å���Ĺ����
                                        // �����ϰ���Ǥʤ����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEPATH ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPATH );
        return( OSFEPATH );
    }

    if( rsize < D_RECORD_SIZE )         // �쥳����Ĺ�Υ����å�
                                        // (���ʾ�)
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    												D_PROC_NAME, OSFERSIZE ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFERSIZE );
        return( OSFERSIZE );
    }

    if( exlen < D_EXLEN )               // ����ΰ襵�����Υ����å�
                                        // (���ʾ�)
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
    												D_PROC_NAME, OSFEFSIZE ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_PRA, 1, OSFEFSIZE );
        return( OSFEFSIZE );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
										// �ե���������ơ��֥����������Ƭ���ɥ쥹����
	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 );

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( path=%s )\n",
    												D_PROC_NAME, path ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lMaxIndNum=%ld )\n",
    												D_PROC_NAME, ptEflc->lMaxIndNum ) );

                                        // ���ͥ��Ⱦ��֤Υ����å�
                                        // �ե�����̾���ե���������ơ��֥��
                                        // ¸�ߤ��뤫�����å�����
    for( iFilId = 0; iFilId < ptEflc->lMaxIndNum; iFilId++ )
    {
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilId=%d ���� )\n", D_PROC_NAME, iFilId));
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( acFileName=%s )\n",
    						D_PROC_NAME, ( ptTEflcTableInd + iFilId )->acFileName ) );

                                        // �ե�����̾�����
        iStrcmpRet = strcmp( ( ptTEflcTableInd + iFilId )->acFileName, path );

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStrcmpRet=%d )\n",
    													D_PROC_NAME, iStrcmpRet ) );

        if( iStrcmpRet == D_STR_EQUAL ) // �ե�����̾���פ����
        {
            if( ( ptTEflcTableInd + iFilId )->pFilStm != NULL )
                                        // �ե����륹�ȥ꡼�ब�ե��������
                                        // �ơ��֥��¸�ߤ��뤫�����å�
            {
        		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    												D_PROC_NAME, OSFEACC ) );
				os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEACC );
                return( OSFEACC );
            }
            
            iConect = D_CONECT_FLAG_ON; // ���ͥ��Ⱦ��֤˥��å�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iConect=%d )\n",
    												D_PROC_NAME, iConect ) );
            break;
        }
    }

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iConect=%d )\n",
   													D_PROC_NAME, iConect ) );

    if( iConect != D_CONECT_FLAG_ON )   // ���ͥ��Ȥ���Ƥ��ʤ��ä���
    {
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lEmpIndNum=%d )\n",
   													D_PROC_NAME, ptEflc->lEmpIndNum ) );
        if( ptEflc->lEmpIndNum < D_OPENING_MIN )
                                        // ���������Υ����å�
                                        // �����������ʤ��ä����
        {
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, OSFEPFILRS ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
        }
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FOPEN, 2, path, D_CHAR_FILE_WRITE );
                                        // �ե�����Υ����ץ�(����ߥ⡼��) 
    pFilStm = fopen( path, D_CHAR_FILE_WRITE );
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 1, pFilStm );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pFilStm=%p )\n",
    												D_PROC_NAME, pFilStm ) );

    if( pFilStm == NULL )               // �ե����륪���ץ󥨥顼�λ�
    {
        goto err_oscreat;
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_MALLOC, 1, exlen );
    pcWbuf = ( char * )malloc( exlen ); // �񤭹��ߥ��ꥢ����
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 2, pcWbuf, errno );
    
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( pcWbuf=%p )\n",
    												D_PROC_NAME, pcWbuf ) );
    if( pcWbuf == NULL )
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

    memset( pcWbuf, 0x00, exlen );      // �����
    
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FWRITE, 4, pcWbuf, 
								D_WRITE_BYTE, (exlen * rsize), pFilStm );
    stFwriteRet = fwrite( pcWbuf, D_WRITE_BYTE, (exlen * rsize), pFilStm );
                                        // �ե�����ν����
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 1, stFwriteRet );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stFwriteRet=%d )\n",
    												D_PROC_NAME, stFwriteRet ) );

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FREE, 1, pcWbuf );
    free( pcWbuf );                     // ���ꥢ����
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
    
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FFLUSH, 1, pFilStm );
    fflush( pFilStm );                  // �Хåե���󥰤���Ƥ������Ƥ�
                                        // �ǥ������˽����
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FILENO, 1, pFilStm );
    iFilDes = fileno( pFilStm );        // �ե����륹�ȥ꡼�फ��
                                        // �ե�����ǥ������ץ꥿���������
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 2, iFilDes, errno );
                                        
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=%d )\n",
    												D_PROC_NAME, iFilDes ) );

    if( iFilDes == D_ERR_SYS )          // �����˼��Ԥ����ä���
    {
		os_trcget2( D_MD_OSCREAT, D_T_SYS_FCLOSE, 1, pFilStm );
        fclose( pFilStm );				// �ե�����򥯥�������
		os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
        
		os_trcget2( D_MD_OSCREAT, D_T_SYS_REMOVE, 1, path );
        remove( path );                 // �ե������������
		os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
        
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 2, -1 , errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
		//return ( -1 );                  // ���ܡ��ɽ���
    }

	os_trcget2( D_MD_OSCREAT, D_T_SYS_FSYNC, 1, iFilDes );
    fsync( iFilDes );                   // �Хåե���󥰤���Ƥ������Ƥ�
                                        // �ǥ������ؽ񤭹��ޤ��ޤ��Ԥ�
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );
	
	os_trcget2( D_MD_OSCREAT, D_T_SYS_FCLOSE, 1, pFilStm );
    fclose( pFilStm );                  // �ե�����򥯥�������
	os_trcget2( D_MD_OSCREAT, D_T_SYS_END, 0 );

/****************************************************************************/
/* �����                                                                   */
/****************************************************************************/
    if( iConect != D_CONECT_FLAG_ON )   // ���ͥ��Ȥ���Ƥ��ʤ��ä���
    {
        for( iFilId = 0; iFilId < ptEflc->lMaxIndNum; iFilId++ )
                                        // ��������������Ͽ����
        {
            if( ( ptTEflcTableInd + iFilId )->acFileName[ 0 ] == '\0' )
                                        // �ե�����̾���Σգ̣̤λ� 
            {
                strcpy( ( ptTEflcTableInd + iFilId )->acFileName, path );
                                        // �������Υե�����̾�����ꤹ��
                ( ptEflc->lEmpIndNum )--;
                                        // �������ζ���������ǥ�����Ȥ���
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEflc->lEmpIndNum=%ld )\n",
    												D_PROC_NAME, ptEflc->lEmpIndNum ) );
                break;
            }
        }

        if( iFilId == ptEflc->lMaxIndNum )
                                        // �������˶������ʤ��ä����
        {
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, -1 );
			return( OSFEPFILRS );
			//return( -1 );                   // ���ܡ��Ƚ���
        }
    }

    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
   	os_trcget2( D_MD_OSCREAT, D_T_TRA_OUT, 1, iFilId + 1 );
    return( iFilId + 1 );               // ��Ͽ�����ե����뵭�һҤ��֤�
                                        // �ե����뵭�һҤϡ������ֹ� ��1

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_oscreat:
    switch( errno )
    {
        case EACCES:
        case EROFS:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEACC );
            return( OSFEACC );
            break;

        case ENOENT:
        case ENOTDIR:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFENOFILE, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFENOFILE );
            return( OSFENOFILE );
            break;

        case ENOMEM:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSEEWKEX );
            return( OSEEWKEX );
            break;
        
        case EMFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEPFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFEPFILRS );
            return( OSFEPFILRS );
            break;  
        
        case ENFILE:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFESFILRS, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 1, OSFESFILRS );
            return( OSFESFILRS );
            break;
    
        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fopen", strerror(errno) ) );
			os_trcget2( D_MD_OSCREAT, D_T_ERR_SYS, 2, -1 , errno );
			
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCREAT << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
