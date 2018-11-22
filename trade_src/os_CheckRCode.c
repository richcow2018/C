/****************************************************************************/
/* ���⥷���ƥ�  �����ƥॳ����                                             */
/* ��ǽ���ꥯ�����ȼ��̻ҥ����å�                                           */
/* ������:2002ǯ11��14��                                                    */
/* �ѹ���:                                                                  */
/* ������:                                                                  */
/*                                                                          */
/****************************************************************************/
/******************************** ɸ��إå����ե����� **********************/

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "os_CheckRCode_ins.h"
#include "os_ERDC_ins.h"

/****************************************************************************/
/* ��ǽ:�ꥯ�����ȼ��̻ҥ����å�                                            */
/* ������:2002ǯ11��14��                                                    */
/* �ѹ���:2003ǯ02��19��                                                    */
/* ������:                                                                  */
/* �ƽз���:                                                                */
/*   long os_CheckRCode( long rd )                                          */
/*     long rd              �ꥯ�����ȼ��̻�                                */
/*                                                                          */
/* ���ֵ��͡�                                                               */
/*     �ꥯ�����ȼ��̻�                                                     */
/*                                                                          */
/****************************************************************************/
long os_CheckRCode( long rd )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TErdcTable *ptTErdcTable = ptErdc;   // rd�����ơ��֥���Ƭ���ɥ쥹
    TErdcTableInd *ptTErdcTableInd = ( void * )ptErdc + sizeof( TErdcTable );
                                        // rd�����ơ��֥���������ɥ쥹����

    int  iIdx;                          // �롼�פ�Index
    long lRCode;                        // �оݥꥯ�����ȼ��̻�

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/

    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", 
                                      D_PROC_CHECKLRCODE ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s:psrm rd:%lx\n", 
                                      D_PROC_CHECKLRCODE, rd ) );
    DbgMsg01( DLv04, ( OutPut, "***** %s:ptMyEPRC->lMaxReqNum:%08lx\n", 
                                      D_PROC_CHECKLRCODE, ptMyEPRC->lMaxReqNum ) );

                                        //--- �ꥯ�����ȼ��̻ҥ����å� ---
    if( rd == D_RD_MIN )                // �ꥯ�����ȼ��̻ҡᣰ�ξ��
    {
        //for( iIdx = 0; iIdx < ptTErdcTable->lMaxIndNum; iIdx++ )
        for( iIdx = 0; iIdx < ptMyEPRC->lMaxReqNum; iIdx++ )
        {
                                        // �������ơ��֥�������Ρ�ͽ����֡פ�
                                        // ��̤ͽ��פǤ���������򸡺�
//          if( ptTErdcTableInd[iIdx].tReqStat.cResStat == D_RESSTAT_NO )
													// �ꥯ�����Ⱦ��֤�
													// ̤ͽ�󤫤�̤���Ѥ���̤�׵�ξ��
			if( D_ERDC_RESSTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptTErdcTableInd[iIdx].tReqStat.cUCompStat )
            {
                lRCode = iIdx;
				DbgMsg01( DLv04, ( OutPut, "***** %s:lRCode:%08lx\n",
						D_PROC_CHECKLRCODE, lRCode ) );
                break;
            }
            DbgMsg01( DLv04, ( OutPut, "***** %s:iIdx:%03dx\n",
						D_PROC_CHECKLRCODE, iIdx ) );
        }
                                        // ��ͽ��̤�פθ�������¸�ߤ��ʤ����
        //if( iIdx == ptTErdcTable->lMaxIndNum )
        if( iIdx == ptMyEPRC->lMaxReqNum )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEOVRQ ) );
            return( OSEEOVRQ );
        }
    }
                                        // �ꥯ�����ȼ��̻�:�������������ξ��
    //else if( (rd > D_RD_MIN) && (rd <= ptTErdcTable->lMaxIndNum) )
    else if( (rd > D_RD_MIN) && (rd <= ptMyEPRC->lMaxReqNum) )
    {
                                        // �������ơ��֥�������Ρ�ͽ����֡פ�
                                        // ��̤ͽ��פξ��
        if( D_ERDC_RESSTAT_NONE == ptTErdcTableInd[ rd - 1 ].tReqStat.cResStat )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEIVRD ) );
            return( OSEEIVRD );
        }
                                        // �������ơ��֥�������Ρ���λ�׵���֡פ�
                                        // ���׵�ѡפξ��
        if( D_ERDC_UCOMPSTAT_REQ == ptTErdcTableInd[ rd - 1 ].tReqStat.cUCompStat )
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEUSED ) );
            return( OSEEUSED );
        }
        lRCode = rd - 1;                // �ֻ���ꥯ�����ȼ��̻ҡפ��оݤȤ���
    }
    else                                // �ꥯ�����ȼ��̻ҡ㣰�ξ��
    {
        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n",
                                              D_PROC_CHECKLRCODE, OSEEIVRD ) );
        return( OSEEIVRD );
    }
	lRCode++;
	
	DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc:%08lx\n",
					D_PROC_CHECKLRCODE, lRCode ) );
    return( lRCode );                   // �оݥꥯ�����ȼ��̻�
}

/****************************************************************************/
/* End                                                                      */
/****************************************************************************/

