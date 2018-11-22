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
/* �㥵���ӥ�����̾��				 �ǡ������													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ե�����ؤν񤭹���										*/
/* ��⥸�塼��ɣġ�				 oswrite													*/
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
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ե�������׵᥵����ʬ�Υǡ��������� 													*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oswrite.h>																	*/
/*																								*/
/*	   	long	oswrite( long fildes, char *buf, long len )										*/
/*																								*/
/* �㲾������																					*/
/*		long		fildes;				�ե����뵭�һ�											*/
/*										��0 < �ե����뵭�һ� <=									*/
/*											�ե���������ơ��֥�δ���������������				*/
/*		char		*buf;				�ǡ�����Ǽ�Хåե�										*/
/*		long		len;				����ߥ쥳���ɿ�										*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�񤭹����������														*/
/*		�۾ｪλ		-1																		*/
/*						os_CheckFiledes���ֵ���													*/
/*						OSFEOOFB																*/
/*						os_IsFileConnect���ֵ���												*/
/*						OSFEACCCTL																*/
/*						OSFEACC																	*/
/*						OSEEWKEX																*/
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
#include <errno.h>                      // ���顼�Σ������
#include <stdio.h>                      // fwrite��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "oswrite.h"
#include "oswrite_ins.h"                // ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    oswrite                                                   */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե�������׵᥵����ʬ�Υǡ���������                    */
/*                                                                          */
/****************************************************************************/
long oswrite( long fildes, char *buf, long len )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥����������

    long lCommonRet;                    // ���̴ؿ��꥿������
    size_t stFwriteRet;                 // fwrite���ֵ���
    int iFerrorRet;                     // ferror���ֵ���
    
	os_trcget2( D_MD_OSWRITE, D_T_TRA_IN, 3, fildes, buf, len );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    if( len < D_RECORDLEN_MIN )         // ����ߥ쥳���ɿ��Υ����å�
                                        // �ϰϥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFEOOFB ) );
		os_trcget2( D_MD_OSWRITE, D_T_ERR_PRA, 1, OSFEOOFB );
        return( OSFEOOFB );             // ����ߥ쥳���ɿ����顼
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
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    lCommonRet = os_IsFileOpen( fildes );
                                        // �����ץ���Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �����ץ���Ǥʤ���
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );
    												
    for(;;)                             // errno ��EINTR�δ֡������֤�
    {
		os_trcget2( D_MD_OSWRITE, D_T_SYS_FWRITE, 4, buf, D_WRITE_BYTE, len, 
															ptTEflcTableInd->pFilStm );
        stFwriteRet = fwrite( buf, D_WRITE_BYTE, len, ptTEflcTableInd->pFilStm );
                                        // �ե�����ν����
		os_trcget2( D_MD_OSWRITE, D_T_SYS_END, 1, stFwriteRet );
                                        
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stFwriteRet=%d )\n",
    												D_PROC_NAME, stFwriteRet ) );

		os_trcget2( D_MD_OSWRITE, D_T_SYS_FERROR, 1, ptTEflcTableInd->pFilStm );
        iFerrorRet = ferror( ptTEflcTableInd->pFilStm );
        								// errno���������
		os_trcget2( D_MD_OSWRITE, D_T_SYS_END, 1, iFerrorRet );
        								
    	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFerrorRet=0x%08x )\n",
    												D_PROC_NAME, iFerrorRet ) );

        if( iFerrorRet == D_ERROR_NOT ) // �ե�����饤������
        {
            break;
        }

        if( errno != EINTR )            // errno ��EINTR�Ǥʤ���
        {
            goto err_oswrite;
        }
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSWRITE, D_T_TRA_OUT, 1, stFwriteRet );
    return( stFwriteRet );              // �������쥳���ɿ����֤�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_oswrite:
    switch( errno )
    {
        case EBADF:
        case EINVAL:
        case EAGAIN:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACCCTL, "fwrite", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, errno );
            return( OSFEACCCTL );
            break;

        case EFAULT:
        case EFBIG:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "fwrite", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, errno );
            return( OSFEACC );
            break;

        case ENOSPC:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSEEWKEX, "fwrite", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, errno );
            return( OSEEWKEX );
            break;

        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSIDKE | OSIZZEDVC, "fwrite", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, errno );
            return( OSIDKE | OSIZZEDVC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fwrite", strerror(errno) ) );
			os_trcget2( D_MD_OSWRITE, D_T_ERR_SYS, 1, errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSWRITE << 16) | D_T_ERR_SYS );
			//return( -1 );               // �Х����顼����
   }
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
