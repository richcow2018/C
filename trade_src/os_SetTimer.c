/************************************************************************************************/
/*	���	��������														   					*/
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
/* ��⥸�塼��̾��					 �����ޤ�ȯ��												*/
/* ��⥸�塼��ɣġ�				 os_SetTimer												*/
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
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�����޴����ơ��֥��ETMC�ˤλ���θ��������Ф��ơ�setitimer�ǥ����ޤ�ȯ�Ԥ��롣			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_SetTimer_ins.h>															*/
/*																								*/
/*	   	long	os_SetTimer( TEtmcTableInd *ptAdr )												*/
/*																								*/
/* �㲾������																					*/
/*		TEtmcTableInd	*ptAdr;		�����ޤ�ȯ�Ԥ���������Υ��ɥ쥹							*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		-1																		*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   �äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "os_SetTimer_ins.h"
/****************************************************************************/
/* ��ǽ�����̴ؿ��������ޤ�ȯ�� 											*/
/* ��������2002ǯ10��														*/
/* �ѹ����� 																*/
/* �����ԡ����� 															*/
/* �ƽз�����																*/
/*	 long os_SetTimer( TEtmcTableInd *ptAdr );								*/
/*	   TEtmcTableInd *ptAdr 	   �����ޤ�ȯ�Ԥ���������Υ��ɥ쥹 		*/
/****************************************************************************/
long os_SetTimer( TEtmcTableInd *ptAdr )
{
/****************************************************************************/
/* ������� 																*/
/****************************************************************************/
	TEtmcTableInd		*ptPrevAdr = NULL; 	// �������ޥ��ɥ쥹
	TEtmcTableInd		*ptNextAdr = NULL; 	// �������ޥ��ɥ쥹
	TEtmcTableInd		*ptStartAdr = NULL;	// ȯ�Ԥ����륿���ޤΥ��ɥ쥹
	TEtmcTableInd		*ptTEtmcTableInd = NULL; 
										// �����޴����ơ��֥��
										// ����������Ƭ���ɥ쥹
	TErdcTableInd		*ptTErdcTableInd = NULL; 
										// rd�����ơ��֥�θ�������Ƭ���ɥ쥹
	struct itimerval	tValue; 		// �������͹�¤��
	long				lSec = NULL;			// ���������ѿ�
	long				lUSec = NULL;			// �ޥ��������������ѿ�
	int 				iFlg = NULL;			// ��������ʬ���ե饰
	int 				iRet = NULL;			// �ֵ��ͽ������ѿ�
	long				lRet = NULL;			// �����ƥॳ�����ֵ��ͽ������ѿ�
	int 				iSysCnt = NULL;		// �����ƥॳ���륿���ޤο�
	int 				iItvCnt = NULL;		// ���󥿡��Х륿���ޤο�
	int 				iNowCnt = NULL;		// ���ߤΥ�����ȿ�


/*****	�ξ�����ֹ�TBCS0202���б�		Start							��������2003.07.04	*****/
	memset(&tValue, 0, sizeof(struct itimerval));	// �������͹�¤�� ���ꥢ
/*****	�ξ�����ֹ�TBCS0202���б�		 End							��������2003.07.04	*****/


/****************************************************************************/
/* �ܽ���																	*/
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OS_SETTIMER, D_T_TRA_IN, 1, ptAdr );

	DbgMsg01( DLv04, ( OutPut, "***** %s: ptAdr->dTimer:%f\n", D_PROC_NAME, ptAdr->dTimer ) );

	for( ; ; )							// �����޽��������ｪλ����ޤ�
	{									// �����򷫤��֤�
		/********************************************/
		/*	��������ʬ���ե饰������				*/
		/********************************************/
		if( ptAdr->lReqNum == D_REQUESTNO_INI )
		{								// �ꥯ�������ֹ椬
										// ���������Ƥ����
			iFlg = D_TIMER_CLEAR;		// �����޺�������ե饰������
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );

		}
		else
		{
			ptPrevAdr = ( TEtmcTableInd * )ptAdr->ptPrevAdr;
										// �������ޥ��ɥ쥹�μ���
			if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc
				&& ( TEtmcTableInd * )ptEtmc->ptNxtAdr == ptAdr )
			{							// �������ޥ��ɥ쥹���������λ� 
				iFlg = D_TIMER_START;	// �����޵�ư�ե饰������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
			else if( ptPrevAdr->lReqNum == D_REQUESTNO_INI )
			{							// �������ޥ��ɥ쥹�Υꥯ�������ֹ�
				iFlg = D_TIMER_START;	// �����������Ƥ����
										// �����޵�ư�ե饰������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
			else
			{
				iFlg = D_TIMER_INSERT;	// �����������ե饰������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iFlg=%d )\n",
													D_PROC_NAME, iFlg ) );
			}
		}

		if( iFlg == D_TIMER_CLEAR ) 	// �����޺�����ΤĤʤ���������
		{
			DbgMsg01( DLv04, ( OutPut, "***** %s: ������Ĥʤ��Ѥ� ����\n",D_PROC_NAME) );
			ptPrevAdr = ( TEtmcTableInd * )ptAdr->ptPrevAdr;
										// �������ޥ��ɥ쥹�μ���
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr ) );
													
			ptNextAdr = ( TEtmcTableInd * )ptAdr->ptNextAdr;
										// �������ޥ��ɥ쥹�μ���
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr=%p )\n",
													D_PROC_NAME, ptNextAdr ) );

			/****************************************/
			/*	�����޴��������������				*/
			/****************************************/
			if( ptAdr->ptPrevAdr == ptAdr->ptNextAdr )
			{							// �����ޤ���Ĥ����ʤ����
				ptEtmc->ptBefAdr = NULL;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
													
				ptEtmc->ptNxtAdr = NULL;
										// ���������������ޤȼ������ޤ򥯥ꥢ
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			}
			else
			{
				if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc )
				{						// �������ޤ��������λ�
										// �������μ����ɥ쥹�˼������ޤ�����
					ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptNextAdr;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
				}
				else
				{
					ptPrevAdr->ptNextAdr = ( struct TEtmcTableInd * )ptNextAdr;
										// ��������ޤ��������ޤμ����ɥ쥹��
										// ��������ޤμ������ޤΥ��ɥ쥹������
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr->ptNextAdr ) );
				}

				if( ptNextAdr == ( TEtmcTableInd * )ptEtmc )
				{						// �������ޤ��������λ�
										// �������������ɥ쥹���������ޤ�����
					ptEtmc->ptBefAdr = ( struct TEtmcTableInd * )ptPrevAdr;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
				}
				else
				{
					ptNextAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptPrevAdr;
										// ��������ޤμ������ޤ������ɥ쥹��
										// ��������ޤ��������ޤΥ��ɥ쥹������
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptNextAdr->ptPrevAdr ) );
				}
			}
			
			DbgMsg01( DLv04, ( OutPut, "***** %s: ������Ĥʤ��Ѥ� ��λ\n",D_PROC_NAME) );
		}
		else if( iFlg == D_TIMER_INSERT )
		{								// �������������ΤĤʤ���������
			DbgMsg01( DLv04, ( OutPut, "***** %s: �������Ĥʤ��Ѥ� ����\n",D_PROC_NAME) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: ptEtmc:%p\n",D_PROC_NAME, ptEtmc) );
			
			ptNextAdr = ( TEtmcTableInd * )ptAdr->ptNextAdr;
										// �������ޥ��ɥ쥹�μ���
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptAdr->ptNextAdr ) );

			/****************************************/
			/*	�����޴��������������				*/
			/****************************************/
			if( ptPrevAdr == ( TEtmcTableInd * )ptEtmc )
			{							// �������ޤ��������λ�
				ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptAdr;
										// ���������ޤ��������ޤμ����ɥ쥹��
										// ���������ޤΥ��ɥ쥹������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			}
			else
			{
				ptPrevAdr->ptNextAdr = ( struct TEtmcTableInd * )ptAdr;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptPrevAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptPrevAdr->ptNextAdr ) );
			}

			if( ptNextAdr == ( TEtmcTableInd * )ptEtmc )
			{							// ���Υ����ޤ��������λ�
				ptEtmc->ptBefAdr = ( struct TEtmcTableInd * )ptAdr;
										// ���������ޤμ������ޤ������ɥ쥹��
										// ���������ޤΥ��ɥ쥹������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptBefAdr ) );
			}
			else
			{
				ptNextAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptAdr;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptNextAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptNextAdr->ptPrevAdr ) );
			}
			DbgMsg01( DLv04, ( OutPut, "***** %s: �������Ĥʤ��Ѥ� ��λ\n",D_PROC_NAME) );
		}

		/********************************************/
		/*	�����ޤ�¸�ߥ����å�					*/
		/********************************************/
		if( ptEtmc->ptBefAdr == NULL && ptEtmc->ptNxtAdr == NULL )
		{								// ȯ�Ԥ����륿���ޤ���Ĥ�ʤ���
										// �����ޤ�ȯ�Ԥ����˽�λ����
			
			break;
		}
		else
		{
			ptStartAdr = ( TEtmcTableInd * )ptEtmc->ptNxtAdr;
										// ȯ�Ԥ����륿���ޤΥ��ɥ쥹�����
			os_trcget2( D_MD_OS_SETTIMER, D_MM_OSSETTIMER, 3,
					ptStartAdr, ptStartAdr->lReqId, ptStartAdr->lReqNum);

			DbgMsg01( DLv04, ( OutPut, "***** %s: ȯ���оݸ���������\n",D_PROC_NAME) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr=%p )\n",
													D_PROC_NAME, ptStartAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->dTimer=%12.9f )\n",
													D_PROC_NAME, ptStartAdr->dTimer ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->ptNextAdr=%p )\n",
													D_PROC_NAME, ptStartAdr->ptNextAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptStartAdr->ptPrevAdr ) );

			DbgMsg01( DLv04, ( OutPut, "***** %s:�����ޥ�����:%ld\n"
													,D_PROC_NAME, ptEtmc->lTimeNowCnt ));

			DbgDmp02( DLv04, ("ptStartAdr �оݥ����޾���", ptStartAdr, sizeof(TEtmcTableInd),1,0));

			/****************************************/
			/*	�������ͤΥ����å�					*/
			/****************************************/
			if( ptStartAdr->dTimer == D_TIMEOUT )
			{							// �����ॢ���Ȥλ�
				ptTErdcTableInd = ( TErdcTableInd * )( ptErdc + 1 );
										// rd�����ơ��֥��
										// ����������Ƭ���ɥ쥹�����
				DbgMsg01( DLv04, ( OutPut, "***** %s: �����ޥ����Ƚ���\n", D_PROC_NAME ));
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTErdcTableInd=%p )\n",
													D_PROC_NAME, ptTErdcTableInd ) );

				/************************************/
				/*	�ꥯ������ID�Υ����å�			*/
				/************************************/
				if( ptStartAdr->lReqId == D_TIMETYPE_SYS )
				{						// �����ƥॳ���륿���ޤλ�
					ptStartAdr->lReqNum = D_REQUESTNO_INI;
										// �ꥯ�������ֹ����������
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptStartAdr->lReqNum=%ld )\n",
													D_PROC_NAME, ptStartAdr->lReqNum ) );
				}
				else
				{						// ���󥿡��Х륿���ޤλ�
					lRet = os_SendTimeOutMsg( 
				   		( ptTErdcTableInd + ( ptStartAdr->lReqId - 1 ))->lPCode,
				   	 	ptStartAdr->lReqNum, D_RESULT_NORMAL );
										// rd�����ơ��֥��������
										// �ꥯ�����ȼ��̻����ܤΥץ������̻�
										// ��ȯ�Ԥ����륿���ޤΥꥯ�������ֹ�
										// ������ ������
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
													D_PROC_NAME, lRet ) );

					if( lRet != NORMAL )	
					{					// ��å����������˼��Ԥ�����	
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
														D_PROC_NAME, -1 ) );
						return( -1 );	// ���ܡ��Ƚ���
					}
				}
				DbgMsg01( DLv04, ( OutPut, "***** %s: �����ޥ����Ƚ�����λ\n", D_PROC_NAME ));
			}
			else						// ������ȯ�Խ�����Ԥ�
			{
				DbgMsg01( DLv04, ( OutPut, "***** %s: ������ȯ�Խ���\n", D_PROC_NAME ));
				/************************************/
				/*	�������ͤ�����					*/
				/************************************/
				//lSec = ( long )ptAdr->dTimer;
				lSec = ( long )(ptStartAdr->dTimer);			//20030121 ����
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lSec=%ld )\n",
													D_PROC_NAME, lSec ) );
				tValue.it_value.tv_sec = lSec;
										// �������͹�¤�Τ�������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tValue.it_value.tv_sec=%ld )\n",
													D_PROC_NAME, tValue.it_value.tv_sec ) );

				//lUSec = ( long )( ( ptAdr->dTimer - lSec) * D_MILLION);
				lUSec = ( long )( ( ptStartAdr->dTimer - lSec) * D_MILLION);	// 20030121 ����
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lUSec=%ld )\n",
													D_PROC_NAME, lUSec ) );
				tValue.it_value.tv_usec = lUSec;
										// �������͹�¤�ΤΥޥ�����������
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tValue.it_value.tv_usec=%ld )\n",
													D_PROC_NAME, tValue.it_value.tv_usec ) );

				/************************************/
				/*	�����ޤ�ȯ��					*/
				/************************************/
				os_trcget2( D_MD_OS_SETTIMER, D_T_SYS_SETITIMER, 3, ptStartAdr,
							tValue.it_value.tv_sec, tValue.it_value.tv_usec );
				iRet = setitimer( ITIMER_REAL, &tValue, NULL );
										// �����ޤ�ȯ�Ԥ�����
				os_trcget2( D_MD_OS_SETTIMER, D_T_SYS_END, 2, iRet, errno);
				
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iRet=%d )\n",
													D_PROC_NAME, iRet ) );
													
				DbgMsg01( DLv04, ( OutPut, "***** %s: ������ȯ�Դ�λ\n", D_PROC_NAME ));
				if( iRet != D_ERR_SYS )    
				{						// ������ȯ�Ԥ�����������
					break;				// ������λ����	
				}
				else					// ������ȯ�Ԥ˼��Ԥ�����
				{
					lRet = os_ErrorSetTimer();
										// ������ȯ�ԥ��顼�����򤹤�
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
													D_PROC_NAME, lRet ) );
										
					if( lRet != NORMAL )
					{
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
														D_PROC_NAME, -1 ) );
						return( -1 );	// ���ܡ��Ƚ���
					}
				}
			}

			/****************************************/
			/*	�������ޤ�����						*/
			/****************************************/
										// 20030326 KL0042 ����
			//if( ptAdr->ptNextAdr == ( struct TEtmcTableInd * )ptEtmc )
			if( ptStartAdr->ptNextAdr == ( struct TEtmcTableInd * )ptEtmc )
			{							// ����ȯ�Ԥ����륿���ޤ��ʤ���
				ptEtmc->ptNxtAdr = NULL;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
				ptEtmc->ptBefAdr = NULL;
										// �������μ������ޤ��������ޤν����
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display (  ptEtmc->ptBefAdr=%p )\n",
													D_PROC_NAME,  ptEtmc->ptBefAdr ) );
				break;
			}
			
			DbgMsg01( DLv04, ( OutPut, "***** %s: �¤��ؤ� ����\n",D_PROC_NAME) );
			ptAdr = ( TEtmcTableInd * )ptStartAdr->ptNextAdr;
										// ����ȯ�Ԥ����륿���ޤ�����򤹤�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr=%p )\n",
													D_PROC_NAME, ptAdr ) );
			ptAdr->ptPrevAdr = ( struct TEtmcTableInd * )ptEtmc;
										// �������ˤĤʤ�������
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->ptPrevAdr=%p )\n",
													D_PROC_NAME, ptAdr->ptPrevAdr ) );
			ptEtmc->ptNxtAdr = ( struct TEtmcTableInd * )ptAdr;
										// ����������Ĥʤ�������
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->ptNxtAdr=%p )\n",
													D_PROC_NAME, ptEtmc->ptNxtAdr ) );
			ptAdr->dTimer += ptStartAdr->dTimer;
										// ȯ�Ԥ˼��Ԥ��������ޤΥ������ͤ�
										// ����ȯ�Ԥ����륿���ޤ˲ä���
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptAdr->dTimer=%lf )\n",
													D_PROC_NAME, ptAdr->dTimer ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: �¤��ؤ� ��λ\n",D_PROC_NAME) );
		}
	}

/****************************************************************************/
/* ��λ����																	*/
/****************************************************************************/
	iSysCnt = 0;
	iItvCnt = 0;

	/************************************************/
	/*	�����޴����ơ��֥�ν缡����				*/
	/************************************************/
										// �����޴����ơ��֥��������
										// ��Ƭ���ɥ쥹�����
	for( iNowCnt = 0; iNowCnt < ptEtmc->lTimeMaxCnt; iNowCnt++ )
	{
		ptTEtmcTableInd = ( TEtmcTableInd * )( ptEtmc + 1 ) + iNowCnt;
//		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd=%p )\n",
//													D_PROC_NAME, ptTEtmcTableInd ) );
		
		if( ptTEtmcTableInd->lReqId == D_TIMETYPE_SYS )
		{								// �����޼��̤������ƥॳ����λ�
			if( ptTEtmcTableInd->lReqNum == D_REQUESTNO_INI )
			{							// �ꥯ�������ֹ椬���������Ƥ���� 
				if( ptTEtmcTableInd->dTimer == D_TIMEOUT )
				{						// �������ͤ����������Ƥ����
					ptEtmc->cSysTimeFlg = D_TIMEFLG_OUT;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				}
				else					// �����޺��������
				{
					ptEtmc->cSysTimeFlg = D_TIMEFLG_OFF;
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				}
			}
			else
			{
				ptEtmc->cSysTimeFlg = D_TIMEFLG_ON;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cSysTimeFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cSysTimeFlg ) );
				iSysCnt++;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iSysCnt=%d )\n",
													D_PROC_NAME, iSysCnt ) );
			}
		}
		else
		{
			if( ptTEtmcTableInd->lReqId != D_REQUESTID_INI
				&& ptTEtmcTableInd->lReqNum != D_REQUESTNO_INI )
			{						// �����޼��̤����󥿡��Х륿���ޤǤ���
									// �ꥯ�������ֹ椬���������Ƥʤ���
				iItvCnt++;
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( iItvCnt=%d )\n",
													D_PROC_NAME, iItvCnt ) );
			}
		}

		if( ptTEtmcTableInd->lReqNum == D_REQUESTNO_INI )
		{								// �ꥯ�������ֹ椬���������Ƥ����
			ptTEtmcTableInd->lReqId = D_REQUESTID_INI;
										// �ꥯ�����ȵ��һҤν����
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->lReqId=%ld )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->lReqId ) );
			ptTEtmcTableInd->ptNextAdr = NULL;
										// �������ޥ��ɥ쥹�ν����
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->ptNextAdr=%p )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->ptNextAdr ) );
			ptTEtmcTableInd->ptPrevAdr = NULL;
										// �������ޥ��ɥ쥹�ν����
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->ptPrevAdr=%p )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->ptPrevAdr ) );
			ptTEtmcTableInd->dTimer = D_TIMER_INI;
										// �����ޤν����
//		  	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptTEtmcTableInd->dTimer=%lf )\n",
//	  												D_PROC_NAME, ptTEtmcTableInd->dTimer ) );
		}
	}

	if( iItvCnt > 0 )					// ���󥿡��Х륿���ޤ������
	{
		ptEtmc->cIntervalFlg = D_TIMEFLG_ON;
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cIntervalFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cIntervalFlg ) );
	}
	else								// ���󥿡��Х륿���ޤ��ʤ���
	{
		ptEtmc->cIntervalFlg = D_TIMEFLG_OFF;
		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->cIntervalFlg=%d )\n",
													D_PROC_NAME, ptEtmc->cIntervalFlg ) );
	}
	ptEtmc->lTimeNowCnt = iSysCnt + iItvCnt;
										// �������ѿ�������
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEtmc->lTimeNowCnt=%ld )\n",
													D_PROC_NAME, ptEtmc->lTimeNowCnt ) );

	os_trcget2( D_MD_OS_SETTIMER, D_T_TRA_OUT, 0 );
	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	return( NORMAL );					// ���ｪλ
}

/****************************************************************************/
/* End																		*/
/****************************************************************************/

