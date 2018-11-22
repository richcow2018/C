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
/* ��⥸�塼��̾��					 �祢����������������										*/
/* ��⥸�塼��ɣġ�				 osseek														*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)							*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ե����륢�������ݥ���Ȥ����ꤹ�롣														*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osseek.h>																	*/
/*																								*/
/*	   	long osseek( long fildes, long skmode, long skrecord ) 									*/
/*																								*/
/* �㲾������																					*/
/*		long		fildes;				�ե����뵭�һ�											*/
/*                                      ��0 < �ե����뵭�һ� <=             					*/
/*                                              �ե���������ơ��֥��      					*/
/*                                                         ���������������� 					*/
/*		long		skmode;				���������ݥ��󥿤���������							*/
/*											1:�ե��������Ƭ									*/
/*											2:�ե�����ţϣ�									*/
/*											3:�����ȥݥ������								*/
/*		long		skrecord;			���������ݥ��󥿤ΰ�ư���ե��å�						*/
/*																								*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�����ȥݥ������														*/
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
#include <sys/stat.h>                   // stat��
#include <stdio.h>                      // seek�� ftell��
#include <string.h>						// �ǥХå���
#include <errno.h>

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "osseek.h"
#include "osseek_ins.h"

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    osseek                                                    */
/*                                                                          */
/*  �㵡ǽ���ס�  �ե����륢�������ݥ���Ȥ����ꤹ�롣                      */
/*                                                                          */
/****************************************************************************/
long osseek( long fildes, long skmode, long skrecord )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEflcTableInd *ptTEflcTableInd;		// �ե���������ơ��֥����������

    long lCommonRet;                    // ���̴ؿ��꥿������
    int iFilDes;                        // �ե�����ǥ������ץ꥿
    long lCurPos;                       // �����ȥݥ������
    int iFstatRet;                      // fstat���ֵ���
    int ifseekRet;                      // fseek���ֵ���
    int iWhence;                        // ���������ϰ���
    struct stat tStatBuf;               // stat�ѥХåե�
    int iStatStsize;                    // stat.stsize���ѿ�

	os_trcget2( D_MD_OSSEEK, D_T_TRA_IN, 3, fildes, skmode, skrecord );

//	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    lCommonRet = os_CheckFiledes( fildes );
                                        // �ե����뵭�һҤΥ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �ե����뵭�һҥ��顼�λ�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

    if( ! ( ( skmode == D_FILE_START ) || ( skmode == D_FILE_END )  
                                       || ( skmode == D_FILE_CURENTPOS ) ) )
                                        // ���������ݥ��󥿤�
                                        // ���������Υ����å�
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    												D_PROC_NAME, OSFESKMODE ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_PRA, 1, OSFESKMODE );
        return( OSFESKMODE );           // ���������ݥ��󥿤������������顼
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
    lCommonRet = os_IsFileOpen( fildes );
                                        // �����ץ���Υ����å�
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCommonRet=0x%08lx )\n",
    												D_PROC_NAME, lCommonRet ) );
    												
    if( lCommonRet != NORMAL )          // �����ץ���Ǥʤ����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08lx\n",
    												D_PROC_NAME, lCommonRet ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
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
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, lCommonRet );
        return( lCommonRet );
    }

	ptTEflcTableInd = ( TEflcTableInd * )( ptEflc + 1 ) + fildes - 1;
                                        // �ե���������ơ��֥���оݸ���������
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEflcTableInd=%p )\n",
    												D_PROC_NAME, ptTEflcTableInd ) );

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// �����ȥݥ��������������
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, lCurPos, errno );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );
    												
    if( lCurPos == D_ERR_SYS )          // �����˼��Ԥ�����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FILENO, 1, ptTEflcTableInd->pFilStm );
    iFilDes = fileno( ptTEflcTableInd->pFilStm );
    									// �ե����륹�ȥ꡼�फ��
                                        // �ե�����ǥ������ץ꥿���������
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, iFilDes, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFilDes=0x%08x )\n",
    												D_PROC_NAME, iFilDes ) );
    												
    if( iFilDes == D_ERR_SYS )          // �����˼��Ԥ�����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FSTAT, 2, iFilDes, &tStatBuf );
    iFstatRet = fstat( iFilDes, &tStatBuf );
                                        // �ե����������������
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, iFstatRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFstatRet=%08x )\n",
    												D_PROC_NAME, iFstatRet ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tStatBuf.st_size=%d )\n",
    												D_PROC_NAME, tStatBuf.st_size ) );
    												
    if( iFstatRet == D_ERR_SYS )        // �����˼��Ԥ�����
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 );                   // ���ܡ��ɽ���
    }

//	iStatStsize = tStatBuf.st_size - 1; // stat.stsize������ʣ�����Ϥޤ�Τǡݣ���
	iStatStsize = tStatBuf.st_size;		// stat.stsize�����
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iStatStsize=%d )\n",
    												D_PROC_NAME, iStatStsize ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( skrecord=%d )\n",
    												D_PROC_NAME, skrecord ) );

    switch( skmode )                    // �������ݥ��󥿥����С����顼
                                        // ��Ƚ�ꤹ��
    {
        case D_FILE_START:              // �ե��������Ƭ
            iWhence = SEEK_SET;         // ��Ƭ����
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
    												
            if( skrecord > D_OFFSET_ZERO )
                                        // ���ե��å���
            {
                if( skrecord > iStatStsize ) 
                                        // ���ե��åȡ�ե���������
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
                }
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // ���ե��å���
            {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
            }
            break;

        case D_FILE_END:                // �ե�����ţϣ�
            iWhence = SEEK_END;         // �ţϣƻ���
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
            if( skrecord > D_OFFSET_ZERO )
                                        // ���ե��å���
            {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // ���ե��å���
            {
                if( ( iStatStsize + skrecord ) < 0 )
                                        // �ʥե����������ܥ��ե��åȡˡ㣰
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
                }
            }
            break;

        case D_FILE_CURENTPOS:          // �����ȥݥ������
            iWhence = SEEK_CUR;         // �����ȥݥ���������
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iWhence=0x%08x )\n",
    												D_PROC_NAME, iWhence ) );
    												
            if( skrecord > D_OFFSET_ZERO ) 
                                        // ���ե��å���
            {
                if( ( lCurPos + skrecord ) > iStatStsize )
                                        // �ʥ����ȥݥ������ܥ��ե��åȡ�
                                        // �� �ե���������
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
                }
            }
            if( skrecord < D_OFFSET_ZERO )
                                        // ���ե��å���
            {
                if( ( lCurPos + skrecord ) < D_OFFSET_ZERO )
                                        // �ʥ����ȥݥ������ܥ��ե��åȡ�
                                        // �㡡��
                {
        			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
    												D_PROC_NAME, OSFERECPOS ) );
					os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, OSFERECPOS );
                    return( OSFERECPOS );
                                        // �����С�������ȯ��
                }
            }
            break;

        default:
        	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    												D_PROC_NAME, -1 ) );
			os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, -1 );
			os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
			//return( -1 );               // ���ܡ��ɽ���
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FSEEK, 3, ptTEflcTableInd->pFilStm, skrecord, iWhence );
    ifseekRet = fseek( ptTEflcTableInd->pFilStm, skrecord, iWhence );
                                        // ���������ݥ��󥿤ΰ�ư
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, ifseekRet, errno );
                                        
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ifseekRet=0x%08x )\n",
    												D_PROC_NAME, ifseekRet ) );

    if( ifseekRet == D_ERR_SYS )        // fseek�˼��Ԥ������
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "fseek", strerror(errno) ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 ); 
    }

	os_trcget2( D_MD_OSSEEK, D_T_SYS_FTELL, 1, ptTEflcTableInd->pFilStm );
    lCurPos = ftell( ptTEflcTableInd->pFilStm );
    									// �����ȥݥ������μ���
	os_trcget2( D_MD_OSSEEK, D_T_SYS_END, 2, lCurPos, errno );
    									
    DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lCurPos=0x%08lx )\n",
    												D_PROC_NAME, lCurPos ) );

    if( lCurPos == D_ERR_SYS )          // ftell�˼��Ԥ������
    {
		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "ftell", strerror(errno) ) );
		os_trcget2( D_MD_OSSEEK, D_T_ERR_SYS, 1, errno );
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSSEEK << 16) | D_T_ERR_SYS );
		//return( -1 ); 
    }

//    DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSSEEK, D_T_TRA_OUT, 1, lCurPos );
    return( lCurPos );                  // �����ȥݥ��������ֵѤ���
}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
