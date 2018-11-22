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
/* �㥵���ӥ�����̾��				 ����������													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �����ޤ�����												*/
/* ��⥸�塼��ɣġ�				 os_tmctl													*/
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
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �����ޤΥ������Ȥ�Ԥ�																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_tmctl.h>																*/
/*																								*/
/*	   	long	os_tmctl( long rd, long r_no, long usec, long sec )								*/
/*																								*/
/* �㲾������																					*/
/*		long		rd;					�ꥯ�����ȼ��̻ҡʣ��ʾ��								*/
/*		long		r_no;				�ꥯ�������ֹ�											*/
/*		long		usec;				�ޥ������áʣ��ʾ��									*/
/*		long		sec;				�áʣ��ʾ��											*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		-1																		*/
/*						OSEEWKEX																*/
/*						OSEEITIM																*/
/*						OSEEIVRD																*/
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
#include <sys/time.h>                   // settimer��

/***************************** ���ѼԺ����إå����ե����� *******************/
#include "os_tmctl_ins.h"               // ���������ѡʸ��̡�
#include "os_tmctl.h"

/****************************************************************************/
/*                                                                          */
/*  ��ؿ�̾��    os_tmctl                                                  */
/*                                                                          */
/*  �㵡ǽ���ס�  �����ޤΥ������Ȥ�Ԥ�                                    */
/*                                                                          */
/****************************************************************************/
long os_tmctl( long rd, long r_no, long usec, long sec )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    TEtmcTable *ptTEtmcTable = ptEtmc;  // �����޴����ơ��֥���Ƭ���ɥ쥹
    TEtmcTableInd *ptTEtmcTableInd = ( void * )ptEtmc + sizeof( TEtmcTable );
                                        // �����޴����ơ��֥���������ɥ쥹

    TEtmcTableInd *ptTEtmcTableIndIntact = NULL;
                                        // ̤���ѥ��ɥ쥹�ʥ������������ɥ쥹��
    TEtmcTableInd *ptTEtmcTableIndReference = NULL;
                                        // �����ѥ��ɥ쥹
    TEtmcTableInd *ptTEtmcTableIndNext = NULL; // �������������ɥ쥹�μ��Υ��ɥ쥹
    long lTemp = 0;                     // ������ѿ�
    double dThisTime = 0;               // ����Υ�������
    int iSetitimerRet = 0;              // setitimer���ֵ���
    double dTotal = 0;                  // �ȡ��������
    struct itimerval tOvalue;           // �Ĥ����
    
    
	os_trcget2( D_MD_OS_TMCTL , D_T_TRA_IN, 4, rd, r_no, usec, sec );
    
/*****	�ξ�����ֹ�TBCS0202���б�		Start							��������2003.07.04	*****/
	memset(&tOvalue, 0, sizeof(struct itimerval));	// �Ĥ���� ���ꥢ
/*****	�ξ�����ֹ�TBCS0202���б�		 End							��������2003.07.04	*****/

//    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

/*****  �㳲�б���TBCS0203��    Start                                   ��������2003.07.15  *****/
//    if( rd < D_REQID_MIN || rd >= ptTEtmcTable->lTimeMaxCnt )
    if( rd < D_REQID_MIN || rd > ptMyEPRC->lMaxReqNum )
/*****  �㳲�б���TBCS0203��    End                                     ��������2003.07.15  *****/
                                        // �ꥯ�����ȼ��̻Ҥγ�ǧ
    {
		os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEIVRD );
		
        return( OSEEIVRD );
    }

    if( usec < D_USEC_MIN )             // �ޥ������ä��ϰ���Ǥʤ���
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
       	os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );
                                              
        return( OSEEITIM );
    }

    if( sec < D_SEC_MIN )               // �ä��ϰ���Ǥʤ���
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );
                                              
        return( OSEEITIM );
    }

    if( ( usec == D_USEC_MIN ) && ( sec == D_SEC_MIN ) ) 
                                        // �äȥޥ������äΥ����å����顼��
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEITIM ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_PRA, 1, OSEEITIM );                                      
                                              
        return( OSEEITIM );
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	/************************************************/
	/*	�����޴����ơ��֥�θ���					*/
	/************************************************/
    for( lTemp = 0; lTemp < ptTEtmcTable->lTimeMaxCnt; lTemp++ )
                                        // �����������򸡺�
    {
        if( ptTEtmcTableInd[ lTemp ].lReqId == D_REQUESTID_INI )
                                        // ̤���Ѥ����Ĥ��ä����
        {
            ptTEtmcTableIndIntact = &ptTEtmcTableInd[ lTemp ];
                                        // �ѿ���̤���ѥ��ɥ쥹�פ�����
            break;
        }
    }
    if( lTemp ==  ptTEtmcTable->lTimeMaxCnt )
                                        // �������˶������ʤ��ä����
    {
//        DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, OSEEWKEX ) );
                                              
        os_trcget2( D_MD_OS_TMCTL , D_T_ERR_SYS, 1, OSEEWKEX );                                           
                                              
        return( OSEEWKEX );
    }
    
/*****  �㳲�б���TBCS0235��    Start                                   ��������2003.07.17  *****/
    if( ptTEtmcTable->ptNxtAdr != NULL )
										// �ִ������μ������ޡפ�NULL�ʳ��λ�
    {
	    /********************************************/
		/*	�����ޤΥ���󥻥�						*/
		/********************************************/
	    os_trcget2( D_MD_OS_TMCTL, D_T_SYS_SETITIMER, 3, ITIMER_REAL, NULL, &tOvalue );    
		
        iSetitimerRet = setitimer( ITIMER_REAL, NULL, &tOvalue );
                                        // �����ޤΥ���󥻥�
		//os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 1, iSetitimerRet );
		os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 4,
				iSetitimerRet, errno, tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec  );
		DbgMsg01( DLv05, ( OutPut, "***** ����󥻥�ĥ�������:%ld:%ld\n",
						 tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec));

        if( iSetitimerRet == D_ERR_SYS )// �����ޥ��åȼ���
        {
            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
                                              D_PROC_NAME, -1 ) );
                                              
            os_trcget2( D_MD_OS_TMCTL, D_T_ERR_SYS, 1, -1 );
                                              
            return( -1 );               // ���ܡ��ɽ���
        }
	}
/*****  �㳲�б���TBCS0235��    End                                     ��������2003.07.17  *****/

	/************************************************/
	/*	�����޴����ơ��֥���Խ�					*/
	/************************************************/
    ptTEtmcTableIndIntact->lReqId = rd; // ��̤���ѥ��ɥ쥹�פΥꥯ�������ֹ�
                                        // �˰����֥ꥯ�����ȼ��̻ҡפ�����
    ptTEtmcTableIndIntact->lReqNum = r_no;
                                        // ��̤���ѥ��ɥ쥹�פΥꥯ�������ֹ�
                                        // �˰����֥ꥯ�������ֹ�פ�����
    if( ptTEtmcTable->ptNxtAdr == NULL )
                                        // �ִ������μ������ޡפ�NULL�λ�
    {
        dThisTime = sec + ( usec * D_USEC );
                                        //�ֺ���Υ������͡פ����ꤹ��
        ptTEtmcTableIndIntact->dTimer = dThisTime;
                                        //��̤���ѥ��ɥ쥹�פΥ�������
                                        // �ˡֺ���Υ������͡פ�����
        ptTEtmcTableIndIntact->ptPrevAdr = ( void * )ptTEtmcTable;
                                        //��̤���ѥ��ɥ쥹�פ�����������
                                        // �������Υ��ɥ쥹������
        ptTEtmcTableIndIntact->ptNextAdr = ( void * )ptTEtmcTable;
                                        //��̤���ѥ��ɥ쥹�פμ���������
                                        // �������Υ��ɥ쥹������
		DbgMsg01( DLv04, ( OutPut, "***** %s:ȯ�ԥ�����:%lf\n",
										D_PROC_NAME, ptTEtmcTableIndIntact->dTimer) );
    }
    else                                // �ִ������μ������ޡפ�NULL�ʳ��λ�
    {
/*****  �㳲�б���TBCS0235��    Start                                   ��������2003.07.17  *****/
//	    /********************************************/
//		/*	�����ޤΥ���󥻥�						*/
//		/********************************************/
//	    os_trcget2( D_MD_OS_TMCTL, D_T_SYS_SETITIMER, 3, ITIMER_REAL, NULL, &tOvalue );    
//		
//        iSetitimerRet = setitimer( ITIMER_REAL, NULL, &tOvalue );
//                                        // �����ޤΥ���󥻥�
//		//os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 1, iSetitimerRet );
//		os_trcget2( D_MD_OS_TMCTL, D_T_SYS_END, 4,
//				iSetitimerRet, errno, tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec  );
//		DbgMsg01( DLv05, ( OutPut, "***** ����󥻥�ĥ�������:%ld:%ld\n",
//						 tOvalue.it_value.tv_sec, tOvalue.it_value.tv_usec));
//
//        if( iSetitimerRet == D_ERR_SYS )// �����ޥ��åȼ���
//        {
//            DbgMsg01( DLv05, ( OutPut, "***** %s:Err Function:%x\n", 
//                                              D_PROC_NAME, -1 ) );
//                                              
//            os_trcget2( D_MD_OS_TMCTL, D_T_ERR_SYS, 1, -1 );
//                                              
//            return( -1 );               // ���ܡ��ɽ���
//        }
/*****  �㳲�б���TBCS0235��    End                                     ��������2003.07.17  *****/

        /********************************************/
		/*	�������ޤ˸��ߤΥ����ޤ�����			*/
		/********************************************/
        ptTEtmcTableIndReference = ( void * )ptTEtmcTable->ptNxtAdr;
                                        // �ָ����ѥ��ɥ쥹�פ�
                                        // �������μ����ɥ쥹������
		os_trcget2( D_MD_OS_TMCTL, D_MM_OSSETTIMER, 4, ptTEtmcTableIndReference,
					ptTEtmcTableIndReference->lReqId, ptTEtmcTableIndReference->lReqNum,
					ptTEtmcTableIndReference->dTimer);

        ptTEtmcTableIndReference->dTimer 
               = tOvalue.it_value.tv_sec + ( tOvalue.it_value.tv_usec * D_USEC );
                                        // ��ȯ����Υ��ɥ쥹�Υ����ޤ�����
		os_trcget2( D_MD_OS_TMCTL, D_MM_OSSETTIMER, 4, ptTEtmcTableIndReference,
					ptTEtmcTableIndReference->lReqId, ptTEtmcTableIndReference->lReqNum,
					ptTEtmcTableIndReference->dTimer);

		DbgDmp02( DLv04, ("ȯ����Υ����ޤ�����", ptTEtmcTableIndReference, sizeof(TEtmcTableInd),1,0));
		
        dThisTime = sec + ( usec * D_USEC );
                                        //�ֺ���Υ������͡פ�����
		DbgMsg01( DLv04, ( OutPut, "*****%s ����Υ������� dThisTime:%f\n", D_PROC_NAME, dThisTime));
		
        /********************************************/
		/*	�����ޤκ�ʬ����						*/
		/********************************************/
        for(;;)                         // ����λ��֤�Ķ����ޤǤι�׻��֤�
                                        // ����
        {
			DbgMsg01( DLv04, ( OutPut, "*****%s dTotal:%f\n", D_PROC_NAME, dTotal));
			DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference->dTimer:%f\n", D_PROC_NAME,
					ptTEtmcTableIndReference->dTimer));
			DbgMsg01( DLv04, ( OutPut, "*****%s �����:%f\n", D_PROC_NAME,
					 dTotal + ptTEtmcTableIndReference->dTimer));

            if( dTotal + ptTEtmcTableIndReference->dTimer > dThisTime )
                                        // ��׻��֤Ⱥ���λ��֤���٤�
            {
                ptTEtmcTableIndReference = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptPrevAdr;
                                        // ��פ�Ф�����ʤΤǡ�
                                        //�ָ����ѥ��ɥ쥹�פ�
                                        // �������ޤΥ��ɥ쥹������
                break;
            }
            dTotal = dTotal + ptTEtmcTableIndReference->dTimer;
                                        // ��פ˸����ɥ쥹�λĤ���֤�­��

			DbgMsg01( DLv04, ( OutPut, "*****%s �Ĥ���� dTotal:%f\n", D_PROC_NAME, dTotal));
			//DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference->ptNextAdr:%lx\n",
			//								D_PROC_NAME,ptTEtmcTableIndReference->ptNextAdr ));
			//DbgMsg01( DLv04, ( OutPut,"*****%s ptTEtmcTable:%08lx\n", D_PROC_NAME, ptTEtmcTable));

            if( ptTEtmcTableIndReference->ptNextAdr == ( void * )ptTEtmcTable )
                                        // �������ޤΥ��ɥ쥹���������λ�
            {
                break;
            }
            ptTEtmcTableIndReference = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptNextAdr;
                                        // �������ޤΥ��ɥ쥹������
        }

                                        //��̤���ѥ��ɥ쥹�פ��������ޤ�
                                        //�����ɥ쥹������
        ( TEtmcTableInd * )ptTEtmcTableIndIntact->ptPrevAdr = ptTEtmcTableIndReference;

		DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTableIndReference:%lx\n", D_PROC_NAME,
				ptTEtmcTableIndReference));

		//DbgMsg01( DLv04, ( OutPut, "*****%s ptTEtmcTable:%f\n", D_PROC_NAME, ptTEtmcTable));

        if( ptTEtmcTableIndReference == ( void * )ptTEtmcTable )//�������ʤ�
        {
            ptTEtmcTableIndIntact->ptNextAdr = ptTEtmcTable->ptNxtAdr;
                                        //��̤���ѥ��ɥ쥹�פμ������ޤ�
                                        //�����ɥ쥹������
            ptTEtmcTableIndNext = ( TEtmcTableInd * )ptTEtmcTable->ptNxtAdr;
                                        // �����ɥ쥹
        }
        else                            // �������Ǥʤ���
        {
            ptTEtmcTableIndIntact->ptNextAdr 
                               = ptTEtmcTableIndReference->ptNextAdr;
                                        //��̤���ѥ��ɥ쥹�פμ������ޤ�
                                        //�����ɥ쥹������
            ptTEtmcTableIndNext = ( TEtmcTableInd * )ptTEtmcTableIndReference->ptNextAdr;
                                        // �����ɥ쥹
        }
        ptTEtmcTableIndIntact->dTimer = dThisTime - dTotal;
        
                                        // ̤���ѥ��ɥ쥹�Υ����ޤ�׻�
		// �����ޤκ���0.01�ʲ��λ��ϥ������ͤ�0.01�˺�����
										// 20030303 �ξ����ɼKL0026 �б�

		if( 0.01 > ptTEtmcTableIndIntact->dTimer )
		{								// �������λ��ϺǾ�����ñ��(10ms)������
			//ptTEtmcTableIndIntact->dTimer = 0.01;
										// 20030320 �ξ����ɼKL0026 �б�
			ptTEtmcTableIndIntact->dTimer = D_TIMEOUT;
		}

		DbgMsg01( DLv04, ( OutPut, "***** %s: ȯ���׵᥿����:%f\n", D_PROC_NAME,
						ptTEtmcTableIndIntact->dTimer ) );

        if( ptTEtmcTableIndNext != ( void * )ptTEtmcTable )
                                        // �������ʳ��ʤ�
        {

			DbgMsg01( DLv04, ( OutPut, "***** %s: ptTEtmcTableIndNext->dTimer:%f\n", D_PROC_NAME,
						ptTEtmcTableIndNext->dTimer ) );

			ptTEtmcTableIndNext->dTimer
					 = ptTEtmcTableIndNext->dTimer - ptTEtmcTableIndIntact->dTimer;
										// �����ɥ쥹�Υ����ޤ�׻�
										// 20030310 �ξ����ɼKL0026 �����б�

			if( 0.01 > ptTEtmcTableIndNext->dTimer )
			{
				//ptTEtmcTableIndNext->dTimer = 0.01;
										// 20030320 �ξ����ɼKL0026 �б�
				ptTEtmcTableIndNext->dTimer = D_TIMEOUT;
			}

			DbgMsg01( DLv04, ( OutPut, "***** %s: ptTEtmcTableIndNext->dTimer:%f\n", D_PROC_NAME,
						ptTEtmcTableIndNext->dTimer ) );
        }

    }
    
    /************************************************/
	/*	�����ޤ�ȯ��								*/
	/************************************************/
    os_SetTimer( ptTEtmcTableIndIntact );
                                        // �����ޤ�ȯ��    
//    DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc\n", D_PROC_NAME ) );
    
   	os_trcget2( D_MD_OS_TMCTL , D_T_TRA_OUT, 1, NORMAL );
    
    return( NORMAL );
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
