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
/* �㥵���ӥ�����̾��				 �ե��������												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ե�����Υ�����											*/
/* ��⥸�塼��ɣġ�				 osclose													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ե�����Υ�����																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osclose.h>																	*/
/*																								*/
/*		long	osclose( long fildes )															*/
/*																								*/
/* �㲾������																					*/
/*		long fildes;			�ե����뵭�һ�													*/
/*								��0 < �ե����뵭�һ� <=�ե���������ơ��֥�δ���������������	*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ 		-1 																		*/
/*						OSFEFILDES																*/
/*						lCommmonRet																*/
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
#include <stdio.h>                      // osclose�ѡ�fflush�ѡ�fileno��
#include <unistd.h>                     // fsync��
#include <string.h>						// �ǥХå���

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osclose.h"
#include "osclose_ins.h"                // ���������ѡʸ��̡�

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osclose��                                                 */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե�����򥯥�������                                    */
/*                                                                          */
/****************************************************************************/
long osclose( long fildes )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥������
    long lCommonRet;                    // ���̴ؿ��꥿������
    int iFilDes;                        // �ե�����ǥ������ץ꥿
    int iFcloseRet;                     // fclose���ֵ���
    
	os_trcget2( D_MD_OSCLOSE, D_T_TRA_IN, 1, fildes );
    
//    DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );

    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
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
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
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
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );


/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FFLUSH, 1, ptTEflcTableInd->pFilStm );    
	fflush( ptTEflcTableInd->pFilStm ); // �Хåե���󥰤���Ƥ������Ƥ�
                                        // �ǥ������˽����
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 0 );

	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// �ե����륹�ȥ꡼�फ��
                                        // �ե�����ǥ������ץ꥿���������
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 1, iFilDes );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=%d )\n",
    												D_PROC_NAME, iFilDes ) );


    if( iFilDes == D_ERR_SYS )          // �����˼��Ԥ����ä���
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fileno", strerror(errno) ) );
		os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 2, -1 , errno );
		
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCLOSE << 16) | D_T_ERR_SYS );
        //return( -1 );                   // ���ܡ��ɽ���
    }

	os_trcget2( D_MD_OSCLOSE, D_T_SYS_FSYNC, 1, iFilDes );
    fsync( iFilDes );                   // �Хåե���󥰤���Ƥ������Ƥ�
                                        // �ǥ������ؽ񤭹��ޤ��ޤ��Ԥ�
	os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 0 );
                                        
    for(;;)                             // errno ��EINTR�δ֡������֤�
    {
		os_trcget2( D_MD_OSCLOSE, D_T_SYS_FCLOSE, 1, ptTEflcTableInd->pFilStm );
        iFcloseRet = fclose( ptTEflcTableInd->pFilStm );
        								// �ե�����򥯥�������
		os_trcget2( D_MD_OSCLOSE, D_T_SYS_END, 2, iFcloseRet, errno );
        								
     	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFcloseRet=%d )\n",
    												D_PROC_NAME, iFcloseRet ) );

        if( iFcloseRet == D_CLOSE_OK )  // �ե����륯��������
        {
            break;
        }
        
        if( errno != EINTR )            // errno ��EINTR�Ǥʤ���
        {
            goto err_osclose;
        }
    }         

    ptTEflcTableInd->pFilStm = NULL;	// �ե���������ơ��֥�򥯥ꥢ����
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd->pFilStm=%p )\n",
    													D_PROC_NAME, ptTEflcTableInd->pFilStm ) );

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSCLOSE, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );                   // �������ֵ�

/****************************************************************************/
/* ���顼����                                                               */
/****************************************************************************/
err_osclose:
    switch( errno )
    {
/*****  �㳲�б���TBCS0271��    Start                                   ��������2003.08.11  *****/
//        case EBADF:
//			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
//									D_PROC_NAME, OSFEFILDES, "fclose", strerror(errno) ) );
//			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, OSFEFILDES );
//            return( OSFEFILDES );
//            break;
/*****  �㳲�б���TBCS0271��    End                                     ��������2003.08.11  *****/
            
        case EIO:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSIDKE | OSIZZEDVC, "fclose", strerror(errno) ) );
			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 1, OSIDKE | OSIZZEDVC );
            return( OSIDKE | OSIZZEDVC );
            break;

        default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fclose", strerror(errno) ) );
			os_trcget2( D_MD_OSCLOSE, D_T_ERR_SYS, 2, -1 , errno );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCLOSE << 16) | D_T_ERR_SYS1);
			//return( -1 );               // �Х����顼����
   }
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
