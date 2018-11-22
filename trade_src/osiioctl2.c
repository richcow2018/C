/************************************************************************************************/
/*	���	��������																			*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�	�ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 �ԣã�/�ɣ�����											*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 TCP/IP���ͥ����������桦�ƻ����λ����					*/
/* ��⥸�塼��ɣġ�				 osiioctl2													*/
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
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô��										*/
/* ���߷�ǯ������					 ��������ǯ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		���ꤵ�줿�ü�ե�������Ф��ưʲ��ν�����Ԥ���										*/
/*			(1) ��Ʊ�������׵�																	*/
/*			(2) ACCEPT																			*/
/*			(3) DETACH																			*/
/*			(4) CONNECT																			*/
/*			(5) DISCONNECT																		*/
/*			(6) ABORT																			*/
/*			(7) ATTACH																			*/
/*			(8) BIND																			*/
/*			(9) LISTEN																			*/
/*			(10) NETCTL																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osiioctl2.h>																*/
/*																								*/
/*		long	osiioctl2(long rd, long fildes, long request, char *arg, long argsiz)			*/
/*																								*/
/* �㲾������																					*/
/*		long		rd				�ꥯ�����ȼ��̻�											*/
/*		long		fildes			�ե�����ǥ�������ץ�										*/
/*		long		request			�������													*/
/*										(1) ��Ʊ�������׵�	��0x00gcf000						*/
/*										(2) ACCEPT			��0x006cf105						*/
/*										(3) DETACH			��0x006c7101						*/
/*										(4) CONNECT			��0x006c7103						*/
/*										(5) DISCONNECT		��0x006c7106						*/
/*										(6) ABORT			��0x006c710a						*/
/*										(7) ATTACH			��0x006c7100						*/
/*										(8) BIND			��0x006c7102						*/
/*										(9) LISTEN			��0x006c7103						*/
/*										(10) NETCTL			��0x006cf150						*/
/*		char		*arg			������ݥ���												*/
/*		long		argsiz			�����襵�����ʣ��ʾ��										*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		�ꥯ�����ȼ��̻�														*/
/*		�۾ｪλ		OSEEIVRD		�ꥯ�����ȼ��̻Ұ۾�ޤ���ͽ����֤�̤ͽ��ǤϤʤ���	*/
/*						OSEEOVRQ		�ꥯ�����ȼ��̻Ҹ����۾�								*/
/*						OSEEUSED		�ꥯ�����ȼ��̻Ҥ����ѺѤߤǤ��롣						*/
/*						OSFEFILDES		���ͥ����������ơ��֥�۾�							*/
/*						0xECF10001		�����襵�����۾�										*/
/*						0xECB00016		������ꡣ												*/
/*						0xECB00140		���ͥ������̤����									*/
/*						0xECB00154		����åɰ۾�											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		�äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <linux/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ipc.h>
#include <sys/msg.h>
/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "osiioctl2.h"
#include "osiioctl2_ins.h"              			// ���������ѡʸ��̡�
#include "os_tcpex.h"                   			// os_tcpex��

/****************************************************************************/
/* ��ǽ��TCP/IP���ͥ����������桦�ƻ����λ����                         */
/* ��������2002ǯ11��18��                                                   */
/* �ѹ�����2002ǯ11��18��                                                   */
/* �����ԡ���̣                                                             */
/* �ƽз�����                                                               */
/*   long osiioctl2( long rd, long fildes, long request,                    */
/*                   char *arg, long argsiz )                               */
/*     long rd                �ꥯ�����ȼ��̻�                              */
/*     long fildes            �ե�����ǥ�������ץ�                        */
/*     long request           �������                                      */
/*                                (1) ��Ʊ�������׵ᡧ0x006CF000            */
/*                                (2) ACCEPT        ��0x006CF105            */
/*                                (3) DETACH        ��0x006C7101            */
/*                                (4) CONNECT       ��0x006C7104            */
/*                                (5) DISCONNECT    ��0x006C7106            */
/*                                (6) ABORT         ��0x006C710A            */
/*                                (7) ATTACH        ��0x006CF100            */
/*                                (8) BIND          ��0x006C7102            */
/*                                (9) LISTEN        ��0x006C7103            */
/*                                (10) NETCTL       ��0x006CF150            */
/*     char *arg              ����������Ȱ�ؤΥݥ���                  */
/*     long argsiz            ����������Ȱ�Υ�����                      */
/*                                                                          */
/****************************************************************************/
long osiioctl2( long rd, long fildes, long request, char *arg, long argsiz )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    struct linger tLinger;              			// linger��¤��
    struct sockaddr_in tSockAddr_In;    			// sockaddr_in��¤��
    TMyMessage tMsgBuf;                 			// ��å������Хåե���¤��
	/*****	�����ѹ���SSLA0012��Start				��������2003.02.25	*****/
    int iOpt;										// setsockopt�ǻ��ꤹ�륪�ץ����
	/*****	�����ѹ���SSLA0012�� End				��������2003.02.25	*****/
    int iLoopCnt;                       			// �롼�ץ�����
    int iRet;                           			// �ֵ���
    long lRet;                          			// �ֵ���
    TErdcTableInd *ptRdIndTopAdr;       			// rd�����ơ��֥����������Ƭ���ɥ쥹
    TErdcTableInd *ptRdIndAdr;          			// rd�����ơ��֥�������Υ��ɥ쥹
    TEcncTableInd *ptEcncIndAdr;        			// ���ͥ����������ơ��֥�������Υ��ɥ쥹
    TArgSyncInfoReq *ptArgSyncInfoReq;  			// ����������ȡ���Ʊ�������׵��
    TArgAccept *ptArgAccept;            			// ����������ȡ�ACCEPT��
    TArgDetach *ptArgDetach;            			// ����������ȡ�DETACH��
    TArgConnect *ptArgConnect;          			// ����������ȡ�CONNECT��
    TArgDisconnect *ptArgDisconnect;    			// ����������ȡ�DISCONNECT��
    TArgAbort *ptArgAbort;              			// ����������ȡ�ABORT��
    TArgAttach *ptArgAttach;            			// ����������ȡ�ATTACH��
    TArgBind *ptArgBind;                			// ����������ȡ�BIND��
    TArgListen *ptArgListen;            			// ����������ȡ�LISTEN��
    TArgThread *ptArgThread;            			// ����å��ѥ����������
    TArgInfo tArgInfo;                  			// �׵�����ѥ����������
    pthread_t thId;                     			// ����å�ID
    void *pvBuf;                        			// ������ѥХåե�
    size_t stCount;                     			// ����ߥХ��ȿ�
    ssize_t sstRet;                     			// �񤭹��ޤ줿�Х��ȿ�
    size_t stMsgSz;                     			// �����ѥ�å�����������


	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_IN, 5, rd, fildes, request, arg, argsiz );

    DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );

	/************************************************/
	/*	���ͥ����������ơ��֥�γ�ǧ				*/
	/************************************************/
    if( ptEcnc == NULL )                			// ���ͥ����������ơ��֥뤬̤�����λ�
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSFEFILDES );
        return( OSFEFILDES );						// OSFEFILDES���ֵ�
    }

    /************************************************/
	/*	rd�����ơ��֥�θ���						*/
	/************************************************/
    ptRdIndTopAdr = (TErdcTableInd *)(ptErdc + 1);	// rd�����ơ��֥����������Ƭ���ɥ쥹����

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndTopAdr=%p )\n",
													D_PROC_NAME, ptRdIndTopAdr ) );

    if( D_RD_NONE == rd )               			// �ꥯ�����ȼ��̻Ҥ��ʤ��λ�
    {
													// rd�����ơ��֥��������Ƭ����ꥯ�����Ⱦ���
													// ��̤ͽ�󤫤�̤���Ѥ���̤�׵�θ������򸡺�
        for( iLoopCnt = 0; iLoopCnt < ptMyEPRC->lMaxReqNum; iLoopCnt++ )
        {
			ptRdIndAdr = ptRdIndTopAdr + iLoopCnt;	// ����������Ƭ���ɥ쥹����

													// ͽ����֤�ͽ��̤�λ�
//			if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
													// �ꥯ�����Ⱦ��֤�
													// ̤ͽ�󤫤�̤���Ѥ���̤�׵�ξ��
			if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat &&
				D_ERDC_USESTAT_NONE == ptRdIndAdr->tReqStat.cUseStat &&
				D_ERDC_UCOMPSTAT_NONE == ptRdIndAdr->tReqStat.cUCompStat )
            {
				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
																D_PROC_NAME, ptRdIndAdr ) );
                break;								// ������ȴ����
            }
        }

        if( iLoopCnt == ptMyEPRC->lMaxReqNum )		// ͽ��̤�����Ĥ���ʤ��ä���
        {                               
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    															D_PROC_NAME, OSEEOVRQ ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEOVRQ );
            return( OSEEOVRQ );						// OSEEOVRQ���ֵ�
        }
    }
													// �ꥯ�����ȼ��̻Ҥ��Ǿ��ͤ�����������δ֤λ�
    else if(( D_RD_MIN <= rd ) && ( ptMyEPRC->lMaxReqNum >= rd ))
    {                                   
        ptRdIndAdr = ptRdIndTopAdr + ( rd - 1 );	// ����������Υ��ɥ쥹����

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr=%p )\n",
														D_PROC_NAME, ptRdIndAdr ) );

													// ͽ����֤�ͽ��̤�λ�
        if( D_ERDC_RESSTAT_NONE == ptRdIndAdr->tReqStat.cResStat )
        {                               
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    															D_PROC_NAME, OSEEIVRD ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEIVRD );
            return( OSEEIVRD );						// OSEEIVRD���ֵ�
        }

													// ��λ�׵���֤��׵�Ѥλ�
        if( D_ERDC_UCOMPSTAT_REQ == ptRdIndAdr->tReqStat.cUCompStat )
        {
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x\n",
																D_PROC_NAME, OSEEUSED ) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEUSED );
			return( OSEEUSED );						// OSEEUSED���ֵ�
        }
    }
    else											// �ꥯ�����ȼ��̻Ҥ�����¾�λ�
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x\n",
    														D_PROC_NAME, OSEEIVRD ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, OSEEIVRD );
        return( OSEEIVRD );							// OSEEIVRD���ֵ�
    }


/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	/********************************************/
	/*  rd�����ơ��֥��оݸ��������Խ�			*/
	/********************************************/
													// ��λ�׵���ˡ��׵�ѡפ�����
	ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_REQ;
													// �׵���̤ˡ�osiioctl2��λ���Ρפ�����
	ptRdIndAdr->cReqClass           = D_ERDC_REQCLASS22;
													// �ꥯ�������ֹ�˥ޥ����ꥯ�������ֹ������
	ptRdIndAdr->lReqNum             = ptErdc->ulMstReqNum++;
													// �ץ������̻Ҥ˼��ץ������̻Ҥ�����
	ptRdIndAdr->lPCode              = ptMyEPRC->lPCode;
	ptRdIndAdr->pvArg1              = arg;			// �����ΰ裱�˥���������Ȱ�ݥ��󥿤�����
	(long)(ptRdIndAdr->pvArg2)      = argsiz;		// �����ΰ裲�˥���������Ȱ襵����������

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->tReqStat.cUCompStat=%hhd )\n",
												D_PROC_NAME, ptRdIndAdr->tReqStat.cUCompStat ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->cReqClass=%hhd )\n",
												D_PROC_NAME, ptRdIndAdr->cReqClass ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lReqNum=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lReqNum ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->lPCode=%ld )\n",
												D_PROC_NAME, ptRdIndAdr->lPCode ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->pvArg1=%p )\n",
												D_PROC_NAME, ptRdIndAdr->pvArg1 ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptRdIndAdr->pvArg2=%ld )\n",
												D_PROC_NAME, (long)(ptRdIndAdr->pvArg2) ) );

    switch( request )								// ������̤ˤ������ο���ʬ��
    {
		case D_TASSO_SYNCINFOREQ:					// ������̤���Ʊ�������׵�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ��Ʊ�������׵� )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgSyncInfoReq) ) // ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}
													// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����
			ptArgSyncInfoReq = (TArgSyncInfoReq *)arg;

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgSyncInfoReq->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgSyncInfoReq->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgSyncInfoReq->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgSyncInfoReq->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x\n",
																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;     			// D_ERR_LOGIC������
//				goto err_iioctl2;       			// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/********************************************/
			/*  ���ͥ����������ơ��֥��оݸ������Խ�	*/
			/********************************************/
                                        			// ���ͥ����������ơ��֥���оݸ������μ���
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgSyncInfoReq->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_ON;
			ptEcncIndAdr->tAsyncInfo.lReqId = ptRdIndAdr->lRCode;
			ptEcncIndAdr->tAsyncInfo.lReqNum = ptRdIndAdr->lReqNum;
			ptEcncIndAdr->tAsyncInfo.pcPara1 = ptRdIndAdr->pvArg1;
			ptEcncIndAdr->tAsyncInfo.lPara2 = (long)ptRdIndAdr->pvArg2;

    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->cAsyncFlg=%hhd )\n",
												D_PROC_NAME, ptEcncIndAdr->cAsyncFlg));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lReqId=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lReqId));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lReqNum=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lReqNum));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.pcPara1=%p )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.pcPara1));
    		DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptEcncIndAdr->tAsyncInfo.lPara2=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->tAsyncInfo.lPara2));

			switch( ptEcncIndAdr->cSCFlg )			// S/C���֤ˤ�äƽ����򿶤�ʬ����
			{
				case D_SCINFO_SERVER:   			// �����Фξ��
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( �����С� )\n",
																		D_PROC_NAME ) );
																		
					/********************************/
					/*	����åɰ����ΰ�γ���		*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MALLOC, 1, sizeof(TArgThread) );
													// ����å��ѥ�����������ΰ�γ���
					ptArgThread = malloc( sizeof(TArgThread) );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, ptArgThread );

					if( ptArgThread == NULL )		// ���ݤǤ��ʤ��ä���
					{
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 08: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "malloc", strerror(errno)));
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//						lRet = D_ERR_NOBUF;			// D_ERR_NOBUF������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ֥���������������פ�����
						tMsgBuf.lResult = D_ERR_NOBUF;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
					}

					/********************************************/
					/*  ����å��ѥ���������Ȥ�����			*/
					/********************************************/
					ptArgThread->lSockDes     = ptEcncIndAdr->lSockDes;
					ptArgThread->cReqClass    = D_REQCLASS_ASYNC;
					ptArgThread->lRCode       = ptRdIndAdr->lRCode;
					ptArgThread->ulReqNum     = ptRdIndAdr->lReqNum;
					ptArgThread->pvArg1       = arg;
					(long)ptArgThread->pvArg2 = argsiz;

					DbgMsg01(DLv04,(OutPut, "***** %s: Display ( ptArgThread->lSockDes=%ld )\n",
														D_PROC_NAME, ptArgThread->lSockDes ) );
					DbgMsg01(DLv04, (OutPut, "***** %s: Display ( ptArgThread->cReqClass=%hhd )\n",
														D_PROC_NAME, ptArgThread->cReqClass ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lRCode=%ld )\n",
														D_PROC_NAME, ptArgThread->lRCode ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->ulReqNum=%ld )\n",
														D_PROC_NAME, ptArgThread->ulReqNum ) );
    				DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg1=%p )\n",
														D_PROC_NAME, ptArgThread->pvArg1 ) );
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg2=%ld )\n",
														D_PROC_NAME, (long)ptArgThread->pvArg2 ) );

					/********************************/
					/*	����åɤκ���				*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_CREATE, 4, 
														&thId, NULL, os_tcpex, ptArgThread );
													// ����åɤκ���
					iRet = pthread_create( &thId, NULL, os_tcpex, ptArgThread );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
					
					if( iRet != NORMAL )			// ����åɤκ����˼��Ԥ�����
					{
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 09: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "pthread_create", strerror(errno)));

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGIC������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ��������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
					}

					/********************************/
					/*	����åɤ�ʬΥ				*/
					/********************************/
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_DETACH, 1, thId );
					pthread_detach( thId );			// ����åɤΥǥ��å�
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 0 );

					lRet = ptRdIndAdr->lRCode;		// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
																D_PROC_NAME, lRet ) );
					break;

				case D_SCINFO_CLIENT:   			// ���饤����Ȥξ��
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ���饤����� )\n",
																		D_PROC_NAME ) );

					lRet = ptRdIndAdr->lRCode;		// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
																	D_PROC_NAME, lRet ) );
                    break;

				default:
    				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//					lRet = D_ERR_LOGIC;				// D_ERR_LOGIC������
//					goto err_iioctl2;				// ���顼����������
					tMsgBuf.lResult = D_ERR_LOGIC;	// �ꥶ��ȷ�̤ˡ��������פ�����
					goto err_iioctl3;				// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}
			break;

		case D_TASSO_ACCEPT:						// ������̤�ACCEPT�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ACCEPT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
            if( argsiz != sizeof(TArgAccept) )		// ����������ȥ������������λ�
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x\n",
																D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
            }

            ptArgAccept = (TArgAccept *)arg;		// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			/****************************************/
			/*	���ͥ����������ơ��֥�θ���		*/
			/****************************************/
													// ���٤Ƥθ��������Ф��ƽ����򷫤��֤�
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                                        			// ���ͥ����������ơ��֥���оݸ������μ���
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;

				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( iLoopCnt=%ld )\n",
																D_PROC_NAME, iLoopCnt ) );
				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%08lx )\n",
																D_PROC_NAME, ptEcncIndAdr ) );
				DbgMsg01(DLv04, ( OutPut, 
						"***** %s: Display ( ptEcncIndAdr->sParentLocalSession=%ld )\n",
												D_PROC_NAME, ptEcncIndAdr->sParentLocalSession ) );
				DbgMsg01(DLv04, ( OutPut, 
						"***** %s: Display ( ptArgAccept->sLocalSession=%ld )\n",
												D_PROC_NAME, ptArgAccept->sLocalSession ) );
				DbgMsg01(DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cAcceptStat=%02x )\n",
														D_PROC_NAME, ptEcncIndAdr->cAcceptStat ) );
													// �����륻������ֹ椬
													// �ƥ����륻������ֹ��Ʊ�줫��
													// accept����֤���accept��פξ��
                if( (ptEcncIndAdr->sParentLocalSession == ptArgAccept->sLocalSession) &&
					(ptEcncIndAdr->cAcceptStat == D_ACCEPTSTAT_ON) )
				{
					break;							// �롼�פ�ȴ����
				}
			}

            if( iLoopCnt == ptEcnc->lMaxIndNum )	// �оݤȤʤ�����������Ĥ���ʤ��ä���
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x\n",
															D_PROC_NAME, D_ERR_NOTCONNECT ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_NOTCONNECT;			// D_ERR_NOTCONNECT������
//				goto err_iioctl2;					// ���顼����������
													// // �ꥶ��ȷ�̤ˡ֥��ͥ������̤�����
													// ������
				tMsgBuf.lResult = D_RESULT_NOTCONNECT;
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/********************************************/
			/*  ����������ȹ�������Υ��å�			*/
			/********************************************/
//			ptArgAccept->sLocalSession  = ptEcncIndAdr->lSockDes;
													// ���ͥ����������ơ��֥���оݸ������ֹ��
													// ���ꤹ��
			ptArgAccept->sLocalSession  = iLoopCnt + 1;
			ptArgAccept->sAddrFamilyId  = D_ADDRFAMILY_ID;
			ptArgAccept->sRemotePortNo  = ptEcncIndAdr->tConnInfo.lPort;
			ptArgAccept->lRemoteAddr    = ptEcncIndAdr->tConnInfo.lIPAdr;

                                        			// ���ͥ����������ơ��֥��������
                                        			// accept����֤�OFF�ˤ���
			ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sLocalSession=%hd )\n",
													D_PROC_NAME, ptArgAccept->sLocalSession ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sAddrFamilyId=%hd )\n",
													D_PROC_NAME, ptArgAccept->sAddrFamilyId ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->sRemotePortNo=%hd )\n",
													D_PROC_NAME, ptArgAccept->sRemotePortNo ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAccept->lRemoteAddr=%ld )\n",
													D_PROC_NAME, ptArgAccept->lRemoteAddr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cAcceptStat=%hhd )\n",
													D_PROC_NAME, ptEcncIndAdr->cAcceptStat ) );

			/********************************************/
			/*  ��å������إå����Խ�					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  ��λ����������						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;              			// -1�ʥ��ܡ��ȡˤ�����
				goto err_iioctl2;       			// ���顼����������
			}

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_DETACH:            			// ������̤�DETACH�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( DETACH )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgDetach) )		// ����������ȥ������������λ�
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    																D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

            ptArgDetach = (TArgDetach *)arg;		// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgDetach->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgDetach->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgDetach->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgDetach->sLocalSession > ptEcnc->lMaxIndNum )
            {
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

													// ���ͥ����������ơ��֥���оݸ������μ���
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgDetach->sLocalSession - 1);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

													// ���ͥ����������ơ��֥���оݸ�������
													// �ѥ����ѥǥ�������ץ����֣��פǤʤ���
			if( ptEcncIndAdr->alPipeDes[1] != 0 )	
			{                           
				/********************************************/
				/*  ����������ȹ�������Υ��å�			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_DETACH;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%ld )\n",
															D_PROC_NAME, (long)tArgInfo.pvArg2 ) );

				/************************************/
				/*	�ѥ��פؤν����				*/
				/************************************/
				for( ; ; )							// �����Ǥ���ޤǽ����򷫤��֤�
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
										ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// DETACH�׵������
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sstRet=%d )\n",
																	D_PROC_NAME, sstRet ) );
					if( sstRet == D_ERR_SYS )		// �۾�λ�
					{
						if( errno != EINTR )		// EINTR�ʳ��λ�
						{
							DbgMsg01(DLv05,(OutPut,"***** %s: Err Function 16: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;  			// -1�ʥ��ܡ��ȡˤ�����
							goto err_iioctl2;		// ���顼����������
						}
					}
					else if( sstRet == stCount )	// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��λ�
					{
						break;						// �롼�פ�ȴ����
					}
					else							// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��
					{								// �Ǥʤ���
													// �Ĥ�Υǡ����ν񤭹��߽���
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// ���ͥ����������ơ��֥���оݸ�������
			{										// �ѥ����ѥǥ�������ץ����֣��פλ�

				/*****	�㳲�б���KL0040��	Start	��������2003.03.24	*****/
				/************************************************************/
				/*  �����åȥǥ�������ץ�����0�ʳ��פξ��ϥ���������	*/
				/*	�褦��Ƚ��������ɲ�									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// �����åȥǥ�������ץ����֣��ʳ��פξ��
				{
					/*****	�����ѹ���SSLA0014��Start	��������2003.02.17	*****/
					/************************************************************/
					/*  �����åȤΥ������������ɲ�							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// �оݸ������Υ����åȥǥ�������ץ�������
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close����
						{
							if( errno == EINTR )	// errno ��EINTR�λ�
							{
								continue;
							}
							else					// errno ��EINTR�Ǥʤ���
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close����
						{
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	�����ѹ���SSLA0014�� End	��������2003.02.17	*****/
				}
				/*****	�㳲�б���KL0040��	 End	��������2003.03.24	*****/

				/************************************/
				/*	���ͥ����������ơ��֥��		*/
				/*				�оݸ������ν����	*/
				/************************************/
													// ���ͥ����������ơ��֥���оݸ������Υ��ꥢ
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  ��å������إå����Խ�					*/
				/********************************************/
//        	    tMsgBuf.lMsgtype = D_MTYPE17;
        	    tMsgBuf.lMsgtype = D_MTYPE22;
            	tMsgBuf.pcBufAdr = NULL;
            	tMsgBuf.lDatesize = D_DATESIZE_FIX;
            	tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
            	tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  ��λ����������						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				
				if( iRet == D_ERR_SYS )				// �۾�λ�
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 17: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1�ʥ��ܡ��ȡˤ�����
					goto err_iioctl2;				// ���顼����������
				}
			}

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_CONNECT:						// ������̤�CONNECT�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( CONNECT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgConnect) )		// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 18: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgConnect = (TArgConnect *)arg;		// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgConnect->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgConnect->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgConnect->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgConnect->sLocalSession > ptEcnc->lMaxIndNum )
			{                           
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 19: 0x%08x\n",
    																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/****************************************/
			/*	���ͥ����������ơ��֥�			*/
			/*					�оݸ�����������	*/
			/****************************************/
													// ���ͥ����������ơ��֥���оݸ������μ���
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgConnect->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

            ptEcncIndAdr->cSCFlg = D_SCINFO_CLIENT; // ���饤����Ȥ�����

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
														D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );

			/****************************************/
			/*	����åɰ����ΰ������				*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MALLOC, 1, sizeof(TArgThread) );
													// ����å��ѥ�����������ΰ�γ���
			ptArgThread = malloc( sizeof(TArgThread) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, ptArgThread );
			
			if( ptArgThread == NULL )				// ���ݤǤ��ʤ��ä���
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 20: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "malloc", strerror(errno) ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_NOBUF;					// D_ERR_NOBUF������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_NOBUF;		// �ꥶ��ȷ�̤ˡ֥Хåե���­�פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/********************************************/
			/*  ����å��ѥ���������Ȥ�����			*/
			/********************************************/
            ptArgThread->lSockDes       = ptEcncIndAdr->lSockDes;
            ptArgThread->cReqClass      = D_REQCLASS_CONN;
            ptArgThread->lRCode         = ptRdIndAdr->lRCode;
            ptArgThread->ulReqNum       = ptRdIndAdr->lReqNum;
            ptArgThread->pvArg1         = arg;
            (long)ptArgThread->pvArg2   = argsiz;

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lSockDes=%ld )\n",
														D_PROC_NAME, ptArgThread->lSockDes ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->cReqClass=%hhd )\n",
														D_PROC_NAME, ptArgThread->cReqClass ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->lRCode=%ld )\n",
														D_PROC_NAME, ptArgThread->lRCode ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->ulReqNum=%ld )\n",
														D_PROC_NAME, ptArgThread->ulReqNum ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg1=%p )\n",
														D_PROC_NAME, ptArgThread->pvArg1 ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgThread->pvArg2=%ld )\n",
														D_PROC_NAME, (long)ptArgThread->pvArg2 ) );

			/****************************************/
			/*	����åɤκ���						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_CREATE, 4, 
														&thId, NULL, os_tcpex, ptArgThread );
													// ����åɤκ���
			iRet = pthread_create( &thId, NULL, os_tcpex, ptArgThread );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet != NORMAL )					// ����åɤκ����˼��Ԥ�����
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
								D_PROC_NAME, D_ERR_LOGIC, "pthread_create", strerror(errno) ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/****************************************/
			/*	����åɤ�ʬΥ						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_PTHREAD_DETACH, 1, thId );
			pthread_detach( thId );					// ����åɤΥǥ��å�
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 0 );

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

		case D_TASSO_DISCONNECT:					// ������̤�DISCONNECT�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( DISCONNECT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgDisconnect) )	// ����������ȥ������������λ�
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 22: 0x%08x\n",
    																D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgDisconnect = (TArgDisconnect *)arg;

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgDisconnect->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgDisconnect->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgDisconnect->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgDisconnect->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 23: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

													// ���ͥ����������ơ��֥���оݸ������μ���
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgDisconnect->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			/****************************************/
			/*	����åɤؤν����					*/
			/****************************************/
													// ���ͥ����������ơ��֥���оݸ�������
													// �ѥ����ѥǥ�������ץ����֣��פǤʤ���
			if( ptEcncIndAdr->alPipeDes[1] != 0 )
			{
				/********************************************/
				/*  ����������ȹ�������Υ��å�			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_DCONN;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%ld )\n",
															D_PROC_NAME, (long)tArgInfo.pvArg2 ) );

				/************************************/
				/*	�ѥ��פؤν����				*/
				/************************************/
				for( ; ; )							// �����Ǥ���ޤǽ����򷫤��֤�
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
											ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// DISCONNECT�׵������
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );

					DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( sstRet=%d )\n",
																	D_PROC_NAME, sstRet ) );
					if( sstRet == D_ERR_SYS )		// �۾�λ�
					{
						if( errno != EINTR )		// EINTR�ʳ��λ�
						{
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 24: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;				// -1�ʥ��ܡ��ȡˤ�����
							goto err_iioctl2;		// ���顼����������
						}
					}
					else if( sstRet == stCount )	// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��λ�
					{
						break;						// �롼�פ�ȴ����
					}
					else							// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��
					{								// �Ǥʤ���
													// �Ĥ�Υǡ����ν񤭹��߽���
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// ���ͥ����������ơ��֥���оݸ�������
			{										// �ѥ����ѥǥ�������ץ����֣��פλ�

				/*****	�㳲�б���KL0040��	Start	��������2003.03.24	*****/
				/************************************************************/
				/*  �����åȥǥ�������ץ�����0�ʳ��פξ��ϥ���������	*/
				/*	�褦��Ƚ��������ɲ�									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// �����åȥǥ�������ץ����֣��ʳ��פξ��
				{
					/*****	�����ѹ���SSLA0014��Start	��������2003.02.17	*****/
					/************************************************************/
					/*  �����åȤΥ������������ɲ�							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// �оݸ������Υ����åȥǥ�������ץ�������
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close����
						{
							if( errno == EINTR )	// errno ��EINTR�λ�
							{
								continue;
							}
							else					// errno ��EINTR�Ǥʤ���
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close����
						{
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	�����ѹ���SSLA0014�� End	��������2003.02.17	*****/
				}
				/*****	�㳲�б���KL0040��	 End	��������2003.03.24	*****/

				/************************************/
				/*	���ͥ����������ơ��֥��		*/
				/*				�оݸ������ν����	*/
				/************************************/
													// ���ͥ����������ơ��֥���оݸ������Υ��ꥢ
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  ��å������إå����Խ�					*/
				/********************************************/
//				tMsgBuf.lMsgtype = D_MTYPE17;
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lDatesize = D_DATESIZE_FIX;
				tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  ��λ����������						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				
				if( iRet == D_ERR_SYS )				// �۾�λ�
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 25: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1�ʥ��ܡ��ȡˤ�����
					goto err_iioctl2;				// ���顼����������
				}
			}
			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_ABORT:							// ������̤�ABORT�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ABORT )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgAbort) )		// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 26: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgAbort = (TArgAbort *)arg;			// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgAbort->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgAbort->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgAbort->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgAbort->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 27: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/****************************************/
			/*	�����ΰ�γ�ǧ						*/
			/****************************************/
													// ���ͥ����������ơ��֥���оݸ������μ���
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgAbort->sLocalSession - 1);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

													// ���ͥ����������ơ��֥���оݸ�������
													// �ѥ����ѥǥ�������ץ����֣��פǤʤ���
			if( ptEcncIndAdr->alPipeDes[1] != 0 )
			{
				/************************************/
				/*	�����åȥ��ץ���������		*/
				/************************************/
				tLinger.l_onoff = 1;
				tLinger.l_linger = 0;
				
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
										SOL_SOCKET, SO_LINGER, &tLinger, sizeof(tLinger) );
													// �����åȥ��ץ���������
				iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_LINGER,
															&tLinger, sizeof(tLinger) );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

				if( iRet == D_ERR_SYS )				// �۾�λ�
				{
					switch( errno )					// ���顼�ֹ�ˤ������ο�ʬ��
					{
						case EBADF:
						case ENOTSOCK:
						case ENOPROTOOPT:
						case EFAULT:
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
									D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//							lRet = D_ERR_LOGIC;		// D_ERR_LOGIC������
//							goto err_iioctl2;		// ���顼����������
													// �ꥶ��ȷ�̤ˡ��������פ�����
							tMsgBuf.lResult = D_ERR_LOGIC;
							goto err_iioctl3;		// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
							break;

						default:
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
									D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

							lRet = -1;				// -1�ʥ��ܡ��ȡˤ�����
							goto err_iioctl2;		// ���顼����������
					}
				}

				/********************************************/
				/*  ����������ȹ�������Υ��å�			*/
				/********************************************/
                tArgInfo.cRecClass = D_REQCLASS_ABORT;
                tArgInfo.lRCode = ptRdIndAdr->lRCode;
                tArgInfo.ulReqNum = ptRdIndAdr->lReqNum;
                tArgInfo.pvArg1 = arg;
                (long)tArgInfo.pvArg2 = argsiz;

                pvBuf = &tArgInfo;
                stCount = sizeof(tArgInfo);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.cRecClass=%hhd )\n",
															D_PROC_NAME, tArgInfo.cRecClass ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.lRCode=%ld )\n",
															D_PROC_NAME, tArgInfo.lRCode ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.ulReqNum=%ld )\n",
															D_PROC_NAME, tArgInfo.ulReqNum ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg1=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg1 ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tArgInfo.pvArg2=%p )\n",
															D_PROC_NAME, tArgInfo.pvArg2 ) );

				/************************************/
				/*	�ѥ��פؤν����				*/
				/************************************/
				for( ; ; )							// �����Ǥ���ޤǽ����򷫤��֤�
				{
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_WRITE, 3, 
									ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
													// ABORT�׵������
					sstRet = write( ptEcncIndAdr->alPipeDes[1], pvBuf, stCount );
					os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, sstRet );
					
					if( sstRet == D_ERR_SYS )		// �۾�λ�
					{
						if( errno != EINTR )		// EINTR�ʳ��λ�
						{
							DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 30: 0x%08x (%s: %s)\n",
													D_PROC_NAME, -1, "write", strerror(errno) ) );
							lRet = -1;				// -1�ʥ��ܡ��ȡˤ�����
							goto err_iioctl2;		// ���顼����������
						}
					}
					else if( sstRet == stCount )	// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��λ�
					{
						break;						// �롼�פ�ȴ����
					}
					else							// ����ޤ줿�Х��ȿ�������ߥХ��ȿ���Ʊ��
					{								// �Ǥʤ���
													// �Ĥ�Υǡ����ν񤭹��߽���
						pvBuf += sstRet;
						stCount -= sstRet;
					}
				}
			}
			else									// ���ͥ����������ơ��֥���оݸ�������
			{										// �ѥ����ѥǥ�������ץ����֣��פλ�

				/*****	�㳲�б���KL0040��	Start	��������2003.03.24	*****/
				/************************************************************/
				/*  �����åȥǥ�������ץ�����0�ʳ��פξ��ϥ���������	*/
				/*	�褦��Ƚ��������ɲ�									*/
				/************************************************************/
				if (0 != ptEcncIndAdr->lSockDes)	// �����åȥǥ�������ץ����֣��ʳ��פξ��
				{
					/*****	�����ѹ���SSLA0014��Start	��������2003.02.17	*****/
					/************************************************************/
					/*  �����åȤΥ������������ɲ�							*/
					/************************************************************/
					while(1)
					{
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_CLOSE, 1, ptEcncIndAdr->lSockDes );
													// �оݸ������Υ����åȥǥ�������ץ�������
						iRet = close( ptEcncIndAdr->lSockDes );
						os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

						if( iRet == D_ERR_SYS )		// close����
						{
							if( errno == EINTR )	// errno ��EINTR�λ�
							{
								continue;
							}
							else					// errno ��EINTR�Ǥʤ���
							{
								DbgMsg01( DLv05, ( OutPut,
										"***** %s: Err Function 21: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "close", strerror(errno) ) );
								os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 2, NULL , errno);
								break;
							}
						}
						else						// close����
						{
													// �оݸ������Υ����åȥǥ�������ץ����ꥢ
							ptEcncIndAdr->lSockDes = 0;
							break;
						}
					}
					/*****	�����ѹ���SSLA0014�� End	��������2003.02.17	*****/
				}
				/*****	�㳲�б���KL0040��	 End	��������2003.03.24	*****/

				/************************************/
				/*	���ͥ����������ơ��֥��		*/
				/*				�оݸ������ν����	*/
				/************************************/
													// ���ͥ����������ơ��֥���оݸ������Υ��ꥢ
                ptEcncIndAdr->cSCFlg = D_SCINFO_NONE;
                ptEcncIndAdr->cAcceptStat = D_ACCEPTSTAT_OFF;
                ptEcncIndAdr->cReadStat = D_READSTAT_OFF;
                ptEcncIndAdr->cAsyncFlg = D_SYNCINFOREQ_OFF;
                ptEcncIndAdr->tReaInfo.lReqId = 0;
                ptEcncIndAdr->tReaInfo.lReqNum = 0;
                ptEcncIndAdr->tReaInfo.pcPara1 = 0;
                ptEcncIndAdr->tReaInfo.lPara2 = 0;
                ptEcncIndAdr->tAsyncInfo.lReqId = 0;
                ptEcncIndAdr->tAsyncInfo.lReqNum = 0;
                ptEcncIndAdr->tAsyncInfo.pcPara1 = 0;
                ptEcncIndAdr->tAsyncInfo.lPara2 = 0;
                ptEcncIndAdr->tConnInfo.lPort = 0;
                ptEcncIndAdr->tConnInfo.lIPAdr = 0;

				/********************************************/
				/*  ��å������إå����Խ�					*/
				/********************************************/
//				tMsgBuf.lMsgtype = D_MTYPE17;
				tMsgBuf.lMsgtype = D_MTYPE22;
				tMsgBuf.pcBufAdr = NULL;
				tMsgBuf.lDatesize = D_DATESIZE_FIX;
				tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
				tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
            	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
															D_PROC_NAME, tMsgBuf.lMsgtype ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
															D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
															D_PROC_NAME, tMsgBuf.lDatesize ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
															D_PROC_NAME, tMsgBuf.lReqid ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
															D_PROC_NAME, tMsgBuf.lResult ) );
    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
															D_PROC_NAME, stMsgSz ) );

				/********************************************/
				/*  ��λ����������						*/
				/********************************************/
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
				iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
				os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
				

				if( iRet == D_ERR_SYS )				// �۾�λ�
				{
					DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 31: 0x%08x ( %s: %s )\n",
											D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
					lRet = -1;						// -1�ʥ��ܡ��ȡˤ�����
					goto err_iioctl2;				// ���顼����������
				}
			}

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

			break;

        case D_TASSO_ATTACH:						// ������̤�ATTACH�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ATTACH )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgAttach) )		// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 32: 0x%08x\n",
																D_PROC_NAME, D_ERR_ARG ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgAttach = (TArgAttach *)arg;		// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			/****************************************/
			/*	���ͥ����������ơ��֥�θ���		*/
			/****************************************/
													// �롼�׽���
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                                        			// ���ͥ����������ơ��֥���оݸ������μ���
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;

    			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
															D_PROC_NAME, ptEcncIndAdr ) );

                if( ptEcncIndAdr->lSockDes == 0 )	// �����åȥǥ�������ץ���0�λ�
                {
                    break;							// �롼�פ�ȴ����
                }
            }

			if( iLoopCnt == ptEcnc->lMaxIndNum )	// �оݤȤʤ�����������Ĥ���ʤ��ä���
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 33: 0x%08x\n",
																D_PROC_NAME, D_ERR_NOBUF ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_NOBUF;					// D_ERR_NOBUF������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_NOBUF;		// �ꥶ��ȷ�̤ˡ֥Хåե���­�פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/****************************************/
			/*	�����åȥǥ�������ץ��κ���		*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SOCKET, 3, PF_INET, SOCK_STREAM, 0 );
													// �����åȤ�����
            iRet = socket( PF_INET, SOCK_STREAM, 0 );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

            if( iRet == D_ERR_SYS )
            {
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
				switch( errno )
				{
                    case EPROTONOSUPPORT:
                    case EAFNOSUPPORT:
                    case EINVAL:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 34: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "socket", strerror(errno) ) );

//						lRet = D_ERR_LOGIC;			// D_ERR_LOGIC������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ��������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
                        break;

                    case ENFILE:
                    case EMFILE:
                    case ENOBUFS:
                    case ENOMEM:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 35: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_NOBUF, "socket", strerror(errno) ) );

//						lRet = D_ERR_NOBUF;			// D_ERR_NOBUF������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ֥Хåե���­�פ�����
						tMsgBuf.lResult = D_ERR_NOBUF;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
                        break;

                    case EACCES:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 36: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, OSFEACC, "socket", strerror(errno)));

						lRet = OSFEACC;				// OSFEACC������
						goto err_iioctl2;			// ���顼����������
                        break;

                    default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 37: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "socket", strerror(errno)));

						lRet = -1;					// -1�ʥ��ܡ��ȡˤ�����
						goto err_iioctl2;			// ���顼����������
				}
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptEcncIndAdr->lSockDes = iRet;			// �����åȥǥ�������ץ�������

													// �оݸ������Υ���ǥå���������
			ptArgAttach->sLocalSession = iLoopCnt + 1;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->lSockDes=%ld )\n",
													D_PROC_NAME, ptEcncIndAdr->lSockDes ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAttach->sLocalSession=%hhd )\n",
													D_PROC_NAME, ptArgAttach->sLocalSession ) );

			/*****	�����ѹ���SSLA0012��Start		��������2003.02.25	*****/
			/****************************************************************/
			/*  TCP/IP�����륢�ɥ쥹�ƻ��ѵ��Ĥ�����						*/
			/****************************************************************/
			iOpt = 1;					// ���ץ���������

			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
										SOL_SOCKET, SO_LINGER, iOpt, sizeof(iOpt) );

													// �����åȥ��ץ���������
			iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_REUSEADDR,
																 &iOpt, sizeof(iOpt) );

			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				switch( errno )						// ���顼�ֹ�ˤ������ο�ʬ��
				{
					case EBADF:
					case ENOTSOCK:
					case ENOPROTOOPT:
					case EFAULT:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
								D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, errno );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGIC������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ��������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
								D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, errno );
						lRet = -1;					// -1�ʥ��ܡ��ȡˤ�����
						goto err_iioctl2;			// ���顼����������
				}
			}
			/*****	�����ѹ���SSLA0012�� End		��������2003.02.25	*****/

			/********************************************/
			/*  ��å������إå����Խ�					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  ��λ����������						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
																// ��å���������
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 38: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1�ʥ��ܡ��ȡˤ�����
				goto err_iioctl2;					// ���顼����������
			}

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		case D_TASSO_BIND:							// ������̤�BIND�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( BIND )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgBind) )		// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 39: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgBind = (TArgBind *)arg;			// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			DbgMsg01( DLv04, ( OutPut, "***** %s:ptArgBind->sLocalSession=%ld \n",
											D_PROC_NAME, ptArgBind->sLocalSession ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEcnc->lMaxIndNum=%ld \n",
											D_PROC_NAME, ptEcnc->lMaxIndNum ) );

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgBind->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgBind->sLocalSession > ptEcnc->lMaxIndNum )
			{
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 40: 0x%08x\n",
    																D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}
													// ���ͥ����������ơ��֥���оݸ������μ���
			ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgBind->sLocalSession - 1);

			/****************************************/
			/*	BIND�ΰ������						*/
			/****************************************/
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );
															
			tSockAddr_In.sin_family = PF_INET;
			tSockAddr_In.sin_port = htons(ptArgBind->sLocalPortNo);
			tSockAddr_In.sin_addr.s_addr = htonl(INADDR_ANY);

			/****************************************/
			/*	�����åȤ���Ͽ						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_BIND, 3, ptEcncIndAdr->lSockDes, 
								(struct sockaddr *)&tSockAddr_In, sizeof(tSockAddr_In) );
													// �����åȤ���Ͽ
			iRet = bind( ptEcncIndAdr->lSockDes, (struct sockaddr *)&tSockAddr_In,
                                                                    sizeof(tSockAddr_In) );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 2, iRet, errno );
                                                                    
			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
				switch( errno )						// ���顼�ֹ�ˤ������ο�ʬ��
				{
					case EBADF:
					case EACCES:
					case ENOTSOCK:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 41: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "bind", strerror(errno) ) );
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGIC������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ֥���������������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
						break;

					case EINVAL:
					case EADDRINUSE:				// 20030307 KL0025 �ɲ�
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 42: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_USEDADDR, "bind", strerror(errno) ) );
//						lRet = D_ERR_USEDADDR;		// D_ERR_USEDADDR������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ֥��ɥ쥹������פ�����
						tMsgBuf.lResult = D_ERR_USEDADDR;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
						break;

                    default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 43: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "bind", strerror(errno) ) );
						lRet = -1;					// -1�ʥ��ܡ��ȡˤ�����
						goto err_iioctl2;			// ���顼����������
				}
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/********************************************/
			/*  ��å������إå����Խ�					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
			stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  ��λ����������						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );


			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 44: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1�ʥ��ܡ��ȡˤ�����
				goto err_iioctl2;					// ���顼����������
			}

			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_LISTEN:						// ������̤�LISTEN�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( LISTEN )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz != sizeof(TArgListen) )		// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 45: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			ptArgListen = (TArgListen *)arg;		// ����������Ȱ�ݥ��󥿤Υ��ɥ쥹����

			/****************************************/
			/*	�����륻�����γ�ǧ				*/
			/****************************************/
													// �����륻������ֹ椬�ϰϳ��λ�
			if( ptArgListen->sLocalSession < D_LOCALSESSNO_MIN ||
				ptArgListen->sLocalSession > ptEcnc->lMaxIndNum )
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 46: 0x%08x\n",
																	D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_LOGIC;					// D_ERR_LOGIC������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_LOGIC;		// �ꥶ��ȷ�̤ˡ��������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}
                                        // ���ͥ����������ơ��֥���оݸ������μ���
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgListen->sLocalSession - 1);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
														D_PROC_NAME, ptEcncIndAdr ) );

			/****************************************/
			/*	�����åȤ�����						*/
			/****************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_LISTEN, 2, ptEcncIndAdr->lSockDes, 
																ptArgListen->sMaxWaitResNum );
													// �����åȤ�����
			iRet = listen( ptEcncIndAdr->lSockDes, ptArgListen->sMaxWaitResNum );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				switch( errno )						// ���顼�ֹ�ˤ������ο�ʬ��
				{
					case EADDRINUSE:
					case EBADF:
					case ENOTSOCK:
					case EOPNOTSUPP:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 47: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, D_ERR_LOGIC, "listen", strerror(errno) ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//						lRet = D_ERR_LOGIC;			// D_ERR_LOGIC������
//						goto err_iioctl2;			// ���顼����������
													// �ꥶ��ȷ�̤ˡ��������פ�����
						tMsgBuf.lResult = D_ERR_LOGIC;
						goto err_iioctl3;			// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 48: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "listen", strerror(errno) ) );
						lRet = -1;					// -1�ʥ��ܡ��ȡˤ�����
						goto err_iioctl2;			// ���顼����������
				}
			}

            ptEcncIndAdr->cSCFlg = D_SCINFO_SERVER;	// �����Ф�����

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
														D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );

			/********************************************/
			/*  ��å������إå����Խ�					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
           	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  ��λ����������						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 49: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1�ʥ��ܡ��ȡˤ�����
				goto err_iioctl2;					// ���顼����������
			}
			lRet = ptRdIndAdr->lRCode;				// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

        case D_TASSO_NETCTL:						// ������̤�NETCTL�λ�
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( NETCTL )\n", D_PROC_NAME ) );

			/****************************************/
			/*	����������							*/
			/****************************************/
			if( argsiz < D_ARG_NETCTL_MIN )			// ����������ȥ������������λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 50: 0x%08x\n",
																	D_PROC_NAME, D_ERR_ARG ) );

/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//				lRet = D_ERR_ARG;					// D_ERR_ARG������
//				goto err_iioctl2;					// ���顼����������
				tMsgBuf.lResult = D_ERR_ARG;		// �ꥶ��ȷ�̤ˡ֥���������������פ�����
				goto err_iioctl3;					// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
			}

			/********************************************/
			/*  ��å������إå����Խ�					*/
			/********************************************/
//			tMsgBuf.lMsgtype = D_MTYPE17;
			tMsgBuf.lMsgtype = D_MTYPE22;
			tMsgBuf.pcBufAdr = NULL;
			tMsgBuf.lDatesize = D_DATESIZE_FIX;
			tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
			tMsgBuf.lResult = D_RD_NORMAL;
													// ��å���������������
            stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lMsgtype=%ld )\n",
														D_PROC_NAME, tMsgBuf.lMsgtype ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.pcBufAdr=%p )\n",
														D_PROC_NAME, tMsgBuf.pcBufAdr ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lDatesize=%ld )\n",
														D_PROC_NAME, tMsgBuf.lDatesize ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lReqid=%ld )\n",
														D_PROC_NAME, tMsgBuf.lReqid ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( tMsgBuf.lResult=%ld )\n",
														D_PROC_NAME, tMsgBuf.lResult ) );
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( stMsgSz=%d )\n",
														D_PROC_NAME, stMsgSz ) );

			/********************************************/
			/*  ��λ����������						*/
			/********************************************/
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId, 
														&tMsgBuf, stMsgSz ,IPC_NOWAIT );
													// ��å���������
			iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
			os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );
			
			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 51: 0x%08x ( %s: %s )\n",
										D_PROC_NAME, -1, "msgsnd", strerror(errno) ) );
				lRet = -1;							// -1�ʥ��ܡ��ȡˤ�����
				goto err_iioctl2;					// ���顼����������
			}

			lRet = NORMAL;							// �ֵ��ͤȤ���NORMAL�����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
			break;

		default:
			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 52: 0x%08x\n",
															D_PROC_NAME, D_ERR_LOGIC ) );
/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
//			lRet = D_ERR_LOGIC;						// D_ERR_LOGIC������
//			goto err_iioctl2;						// ���顼����������
			tMsgBuf.lResult = D_ERR_LOGIC;			// �ꥶ��ȷ�̤ˡ��������פ�����
			goto err_iioctl3;						// ��λ��å������Υ��顼������
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
	}


/****************************************************************************/
/* ��λ����                                                                 */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_OUT, 1, lRet );
    return( lRet );									// ������ֵ�


/****************************************************************************/
/* �۾����                                                                 */
/****************************************************************************/
err_iioctl2:
	/************************************/
	/* rd�����ơ��֥��оݸ��������Խ�	*/
	/************************************/
													// ��λ�׵���֤��׵�̤������
    ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
    												// �׵���̤򥯥ꥢ
    ptRdIndAdr->cReqClass           = D_ERDC_REQCLASS00;
    ptRdIndAdr->lReqNum             = 0;			// �ꥯ�������ֹ�򥯥ꥢ
    ptRdIndAdr->lPCode              = 0;			// �ץ������̻Ҥ򥯥ꥢ
    ptRdIndAdr->pvArg1              = NULL;			// �����ΰ�1�򥯥ꥢ
    ptRdIndAdr->pvArg2              = NULL;			// �����ΰ�2�򥯥ꥢ

    ptErdc->ulMstReqNum--;              			// �ޥ����ꥯ�������ֹ�Υǥ������

	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
													D_PROC_NAME, ptErdc->ulMstReqNum ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, lRet );
/*****	�ξ�����ֹ�TBCS0205���б�		Start							��������2003.07.08	*****/
													// ���ܡ��Ƚ���
	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIIOCTL2 << 16) | D_T_ERR_SYS1 );
/*****	�ξ�����ֹ�TBCS0205���б�		 End							��������2003.07.08	*****/


/*****	�����ѹ���SSLA0019��	Start									��������2003.03.31	*****/
/************************************************************************************************/
/*  ��λ�׵�α������ֵ��ͤ��֤��褦�˽���													*/
/************************************************************************************************/
err_iioctl3:										// ��λ��å������Υ��顼����
	/********************************************/
	/*  ��å������إå����Խ�					*/
	/********************************************/
	tMsgBuf.lMsgtype = D_MTYPE22;
	tMsgBuf.pcBufAdr = NULL;
	tMsgBuf.lDatesize = D_DATESIZE_FIX;
	tMsgBuf.lReqid = ptRdIndAdr->lReqNum;
													// ��å���������������
	stMsgSz = sizeof(tMsgBuf) - sizeof(tMsgBuf.lMsgtype);

	/********************************************/
	/*  ��λ����������						*/
	/********************************************/
	os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_MSGSND, 4, ptMyEMBC->lMsgQId,
										&tMsgBuf, stMsgSz, IPC_NOWAIT );
													// ��å���������
	iRet = msgsnd( ptMyEMBC->lMsgQId, &tMsgBuf, stMsgSz, IPC_NOWAIT );
	os_trcget2( D_MD_OSIIOCTL2, D_T_SYS_END, 1, iRet );

	if( iRet == D_ERR_SYS )							// �۾�λ�
	{
		DbgMsg01(DLv05,(OutPut,"***** %s:Err Function 49: 0x%08x(%s:%s)\n",
								D_PROC_NAME, -1, "msgsnd", strerror(errno)));

		lRet = -1;									// -1�ʥ��ܡ��ȡˤ�����

		/************************************/
		/* rd�����ơ��֥��оݸ��������Խ�	*/
		/************************************/
													// ��λ�׵���֤��׵�̤������
		ptRdIndAdr->tReqStat.cUCompStat = D_ERDC_UCOMPSTAT_NONE;
													// �׵���̤򥯥ꥢ
		ptRdIndAdr->cReqClass			= D_ERDC_REQCLASS00;
		ptRdIndAdr->lReqNum				= 0;		// �ꥯ�������ֹ�򥯥ꥢ
		ptRdIndAdr->lPCode				= 0;		// �ץ������̻Ҥ򥯥ꥢ
		ptRdIndAdr->pvArg1				= NULL;		// �����ΰ�1�򥯥ꥢ
		ptRdIndAdr->pvArg2				= NULL;		// �����ΰ�2�򥯥ꥢ

		ptErdc->ulMstReqNum--;              		// �ޥ����ꥯ�������ֹ�Υǥ������

		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptErdc->ulMstReqNum=%ld )\n",
													D_PROC_NAME, ptErdc->ulMstReqNum ) );
		os_trcget2( D_MD_OSIIOCTL2, D_T_ERR_SYS, 1, lRet );
/*****	�ξ�����ֹ�TBCS0205���б�		Start							��������2003.07.08	*****/
													// ���ܡ��Ƚ���
		os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIIOCTL2 << 16) | D_T_ERR_SYS2 );
/*****	�ξ�����ֹ�TBCS0205���б�		 End							��������2003.07.08	*****/
	}

	lRet = ptRdIndAdr->lRCode;						// �ֵ��ͤȤ��ƥꥯ�����ȼ��̻Ҥ����ꤹ��
	DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n", D_PROC_NAME, lRet ) );

	os_trcget2( D_MD_OSIIOCTL2, D_T_TRA_OUT, 1, lRet );
	return( lRet );									// ������ֵ�
/*****	�����ѹ���SSLA0019��	 End									��������2003.03.31	*****/
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
