/*------------------------------------------------------------------*/
/* ���оݶ�̳̾��                    ��ž������̳                   */
/* ���оݶ�̳�ɣġ�                  �ϣã�                         */
/* �㥵���ӥ�����̾��                ��ʸ����                       */
/* �㥵���ӥ����ܣɣġ�              �أأ�                         */
/* ��⥸�塼��̾��                  �أأأأأأأأأ�           */
/* ��⥸�塼��ɣġ�                �أأأأأأأ�               */
/* ��⥸�塼�����֡�                                               */
/*------------------------------------------------------------------*/
/* ��Ŭ�ѵ����                      ���ã�                         */
/* ��Ŭ�ѣϣӡ�                      �̣ɣΣգ�                     */
/* �㳫ȯ�Ķ���                      �̣ɣΣգ�                     */
/* �㵭�Ҹ����                      �ø���                         */
/* ��⥸�塼����֡�                ���ޥ��                       */
/* �㵡ǽ��ʬ��                                                     */
/* ���оݥǡ�����                                                   */
/* �㹩�������ض�ʬ��                                               */
/*------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��                ���ãšݣӣͣХ����ƥ�         */
/* �㳫ȯ�����ƥ��ֹ��              �أأأأأأأأأأأ�       */
/*------------------------------------------------------------------*/
/* �㳫ȯô����̾��                  �ӣ������                   */
/* �������ֹ��                      03-3341-5504                   */
/*------------------------------------------------------------------*/
/* ���߷׼�̾��                      �ӣ������                   */
/* ���߷�ǯ������                    ��������ǯ���������         */
/* ���߷׽�����̾��                                                 */
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                   */
/*------------------------------------------------------------------*/
/* �㥽����������̾��                �ӣ������                   */
/* �㥽��������ǯ������              ��������ǯ���������         */
/* �㥽����������̾��                                               */
/* �㥽��������ǯ�����ڤӽ����ɣġ�                                 */
/*------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���                ���ƥå�                       */
/*------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                     */
/*                                                                  */
/*       �ӣͣ��۲�����ʸ��ѥץ����˰��ꤵ�줿��ʸ����������     */
/*                                                                  */
/*------------------------------------------------------------------*/
/* ��ƽз�����                                                     */
/*     int     smpmsg( pCdMk                                        */
/*                     pNmSendPoint                                 */
/*                     pDtMia                                       */
/*                     [-l lenDtMia]                                */
/*                     [-n noSend] )                                */
/*                     [-s ]                                        */
/*                     [-t timRtySnd ]                              */
/*                                                                  */
/* �㲾������                                                       */
/*		pCdMk			:	�ͣ˥����ɡ�ɬ�ܡ�						*/
/*		pNmSendPoint	:	ȯ����ץ���̾��ɬ�ܡ�				*/
/*		pDtMia			:	�ͣɣ����̰�����ǡ�����ɬ�ܡ�			*/
/*		-l				:	�ͣɣ����̰�����ǡ���Ĺ���ץ����		*/
/*		lenDtMia		:	�ͣɣ����̰�����ǡ���Ĺ				*/
/*		-n				:	����������ץ����						*/
/*		noSend			:	�������								*/
/*		-s				:	��ã��ǧ�ؼ�							*/
/*		-t				:	������ȥ饤�ֳ֥��ץ����				*/
/*		timRtySnd		:	������ȥ饤�ֳ�						*/
/*              �ʤ�                                                */
/* ���ֵ��͡�                                                       */
/*		0	:	����												*/
/*		-1	:	�۾�ʰ������顼��									*/
/*		-2	:	�۾����ʸ��ѥץ�����¸��ǧ���ԡ�				*/
/*		-3	:	�۾����ʸ��ѥᥤ��ܥå������̻�					*/
/*								�����ե����륪���ץ��ԡ�			*/
/*		-4	:	�۾����ʸ��ѥᥤ��ܥå������̻�					*/
/*								�����ե����륪���ץ��ԡ�			*/
/*		-5	:	�۾����ʸ��ѥᥤ��ܥå������̻�					*/
/*								�����ե����륪���ץ��ԡ�			*/
/*		-6	:	�۾������å����������������ԡ�					*/
/*		-7	:	�۾������å��������塼�������ԡ�				*/
/*		-8	:	�۾��������ʸ�Խ��ΰ���ݼ��ԡ�					*/
/*		-9	:	�۾�ʼ���å����������������ԡ�					*/
/*		-10	:	�۾�ʼ���å��������塼�������ԡ�					*/
/*		-11	:	�۾����ʸ��Ѱ�����ʸ�������ԡ�					*/
/*		-12	:	�۾����ã��ǧ���ԡ�								*/
/*		-13	:	�۾����ã��ǧ��ʸ�������ԡ�						*/
/*------------------------------------------------------------------*/
/* �����»����         �ʤ�                                        */
/*                                                                  */
/* ����ѳ����⥸�塼��ɣġ�                                       */
/* ��ƽХ⥸�塼��ɣġ�                                           */
/*                                                                  */
/********************************************************************/
/* ��������															*/
/********************************************************************/
/* �㳲�ֹ�	  : TBCS0066											*/
/* �㳲����	  : MIA���̰�˻��ꤷ���ǡ�������������ʸ�����ꤵ��ʤ� */
/* ��������	  : MIA�����������������å��������ɲ�					*/
/* ��������	  : 2003.04.24           	                            */
/* ������	  : Supply Sugawara										*/
/********************************************************************/
#include	"smpmsg.h"
/**/
char	infoSysLog[256];
/****************************************/
/*	����ΰ�							*/
/****************************************/
char	*pGetLog;						/*	���Խ���				*/
/**/
int
main (argc ,argv)
int		argc;
char	*argv[];
{
	USER_AREA	UA;						/*	I/F���ꥢ				*/
	int			cLP;					/*	�롼�ץ�����			*/
	int			ckRslt;					/*	�ֵѾ����				*/
	int			flgLogOut;				/*	�����ϻؼ��ե饰		*/
	int			hF;						/*	�ե�����ϥ�ɥ�		*/
	int			lenData;				/*	�ɤ߹��ߥ�����			*/
	long		pBuf;					/*	�ɤ߹��߰�				*/
	key_t		keyIpc;					/*	�ɣУå�������			*/
	int			queIpc;					/*	�ɣУå��塼����		*/
	long		cPrc;					/*	�ͣϣʿ�				*/
/****************************************/
/*	�����								*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Start (%s) ***\n" ,argv[0]);
#endif
	memset ((char*)&UA ,0x00 ,sizeof(USER_AREA));
	UA.ua_Rslt			=	RTN_OK;
/****************************************/
/*	���ץ����ɣļ���					*/
/****************************************/
	UA.ua_idProc	=	getpid();
#ifdef	DEBUGF
printf ("*** smpmsg getpid (%d) ***\n" ,UA.ua_idProc);
#endif
/****************************************/
/*	�ѥ�᡼�������å�					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call ParamaterCheck ***\n");
#endif
	ckRslt	=	ParamaterCheck (&UA ,argc ,argv);
										/*	�ѥ�᡼�������å�����	*/
	if (ckRslt == STC_PRC_OK);			/*	�ѥ�᡼������			*/
	else {								/*	�ѥ�᡼������			*/
#ifdef	DEBUGF
printf ("*** smpmsg PrmaterError (%d ,%d) ***\n" ,RTN_NG_PRM ,ckRslt );
#endif
										/* TBCS0066 				*/
		sprintf (infoSysLog ,"%s  Paramater Error (%d, %d)" ,argv[0] ,RTN_NG_PRM, ckRslt);
		GetSysLog ("SOH1" ,"ERR" ,infoSysLog);

		return	RTN_NG_PRM;
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call ParamaterCheck Success ***\n");
#endif
/****************************************/
/*	��ʸ��ѥץ�����¸��ǧ			*/
/****************************************/
	UA.ua_noRtySend		=	1;
	while (1) {							/*	��¸����ޤǷ����֤�	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call MojArriveCheck ***\n");
#endif
		ckRslt	=	MojArriveCheck (&UA ,&cPrc);
										/*	��¸��ǧ����			*/
		if (ckRslt == STC_PRC_OK) {		/*	���������λ�			*/
			if (cPrc >= 1) {			/*	��¸������			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck MojRunning (%d) ***\n" ,cPrc);
#endif
				break;					/*	while��ȴ����			*/
			}
			else {						/*	��¸���ʤ����			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck MojNotRunning (%d) ***\n" ,cPrc);
#endif
				sprintf (infoSysLog ,"%s  MOJ_NotRunning (SendCount=%d)" ,argv[0] ,UA.ua_noRtySend);
				GetSysLog ("SOH2" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	��ȥ饤�����ϰ�		*/
					sleep(UA.ua_tmSend);/*	�ף��ɣ�				*/
					UA.ua_noRtySend++;	/*	����������գ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	��ȥ饤�����С�		*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck RetryOver (%d ,%d) ***\n" ,ckRslt ,RTN_NG_MOJ);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MOJ);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MOJ;
				}
			}
		}
		else {							/*	�۾������λ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck Error (%d ,%d) ***\n" ,ckRslt ,RTN_NG_MOJ);
#endif
			sprintf (infoSysLog ,"%s  MOJ_ArriveCheck Error (rc=%d)" ,argv[0] ,RTN_NG_MOJ);
			GetSysLog ("SOH4" ,"ERR" ,infoSysLog);
			return	RTN_NG_MOJ;
		}
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call MojArriveCheck Success ***\n");
#endif
/****************************************/
/*	��ʸ��ѥᥤ��ܥå������̻Ҥμ���	*/
/****************************************/
	while (1) {							/*	���󤬼����Ǥ���ޤ�	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call File Open (%s) ***\n" ,DEF_MOJ_MBOX_PATH);
#endif
		hF	=	open (DEF_MOJ_MBOX_PATH ,O_RDONLY);
		if (hF != -1) {					/*	�����ץ�����			*/
			break;
		}
		else {							/*	�����ץ���			*/
			if (errno == ENOENT) {		/*	�ե�����̵��			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open FileNothing ***\n");
#endif
				sprintf (infoSysLog ,"%s  WatchFile Nothing (SendCount=%d)" ,argv[0] ,UA.ua_noRtySend);
				GetSysLog ("SOH5" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	��ȥ饤�����ϰ�		*/
					sleep(UA.ua_tmSend);/*	�ף��ɣ�				*/
					UA.ua_noRtySend++;	/*	����������գ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	��ȥ饤�����С�		*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open RtryOver (%d) ***\n" ,RTN_NG_FL_OPEN);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_FL_OPEN);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_FL_OPEN;
				}
			}
			else {						/*	�ե�����̵���ʳ�		*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open Error (%d ,%d ,%s) ***\n" ,RTN_NG_FL_OPEN ,errno ,strerror(errno));
#endif
				sprintf (infoSysLog ,"%s  WatchFile OPEN Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_FL_OPEN);
				GetSysLog ("SOH6" ,"ERR" ,infoSysLog);
				return	RTN_NG_FL_OPEN;
			}
		}
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call File Open Success ***\n");
#endif
/**/
	while (1) {
#ifdef	DEBUGF
printf ("*** smpmsg Call File Read ***\n");
#endif
		lenData	=	read (hF ,(char*)&pBuf ,sizeof(pBuf));
#ifdef	RDERR
printf ("*** smpmsg File Read Rslt errNG_Set Start (%d) ***\n" ,lenData);
lenData	=	-1;
errno	=	EIO;
printf ("*** smpmsg File Read Rslt errNG_Set End (%d ,%d(%s)) ***\n" ,
						lenData ,errno ,strerror(errno));
#endif
#ifdef	RDSIG
printf ("*** smpmsg File Read Rslt sigNG_Set Start (%d) ***\n" ,lenData);
lenData	=	-1;
errno	=	EINTR;
printf ("*** smpmsg File Read Rslt sigNG_Set End (%d ,%d(%s)) ***\n" ,
						lenData ,errno ,strerror(errno));
#endif
		if (lenData == -1) {			/*	�ɤ߹��߰۾�			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Read Error (%d(%s) ,%d) ***\n" ,errno ,strerror(errno) ,RTN_NG_FL_READ);
#endif
			if (errno == EINTR) {		/*	�����ʥ�ȯ��			*/
				continue;				/*	while�����				*/
			}
			sprintf (infoSysLog ,"%s  WatchFile READ Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_FL_READ);
			GetSysLog ("SOH7" ,"ERR" ,infoSysLog);
			close (hF);					/*	�ե����륯����		*/
			return	RTN_NG_FL_READ;
		}
		if (lenData == 0) {				/*	EOF						*/
#ifdef	DEBUGF
printf ("*** smpmsg File Read EOF (%d ,%d) ***\n" ,errno ,RTN_NG_FL_READ);
#endif
			close (hF);						/*	�ե����륯����		*/
			return	RTN_NG_FL_READ;
		}
		UA.InfoPartProc.ua_PartProcMbox	=	pBuf;
		break;
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call File Read Success ***\n");
#endif
/**/
	while (1) {
#ifdef	DEBUGF
printf ("*** smpmsg Call File Close ***\n");
#endif
		ckRslt	=	close (hF);			/*	�ե����륯����		*/
#ifdef	CLERR
printf ("*** smpmsg File Close Rslt errNG_Set Start (%d) ***\n" ,ckRslt);
ckRslt	=	-1;
errno	=	EBADF;
printf ("*** smpmsg File Close Rslt errNG_Set End (%d ,%d(%s)) ***\n" ,
						ckRslt ,errno ,strerror(errno));
#endif
#ifdef	CLSIG
printf ("*** smpmsg File Close Rslt sigNG_Set Start (%d) ***\n" ,ckRslt);
ckRslt	=	-1;
errno	=	EINTR;
printf ("*** smpmsg File Close Rslt sigNG_Set End (%d ,%d(%s)) ***\n" ,
						ckRslt ,errno ,strerror(errno));
#endif
		if (ckRslt == -1) {				/*	����������			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Close Error (%d(%s) ,%d) ***\n" ,errno ,strerror(errno) ,RTN_NG_FL_CLOSE);
#endif
			if (errno == EINTR) {		/*	�����ʥ�ȯ��			*/
				continue;				/*	while�����				*/
			}
			sprintf (infoSysLog ,"%s  WatchFile CLOSE Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_FL_CLOSE);
			GetSysLog ("SOH8" ,"ERR" ,infoSysLog);
			return	RTN_NG_FL_CLOSE;
		}
		break;
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call File Close Success ***\n");
#endif
/****************************************/
/*	��ꥭ�塼�����ץ�					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(Part) ***\n");
#endif
	ckRslt	=	GetKey_IPC (&UA ,UA.InfoPartProc.ua_PartProcMbox ,
								DEF_MOJ_PRJ_ID ,&UA.InfoPartProc.ua_PartIpcKey);
										/*	�ɣУå�������			*/
	if (ckRslt == STC_PRC_OK);			/*	��������				*/
	else {								/*	��������				*/
#ifdef	DEBUGF
printf ("*** smpmsg GetKey_IPC(Part) Error (%d ,%d) ***\n" ,ckRslt ,RTN_NG_MOJ_KEY);
#endif
		sprintf (infoSysLog ,"%s  MOJ_IPC_KEY Get Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MOJ_KEY);
		GetSysLog ("SOH9" ,"ERR" ,infoSysLog);
		return	RTN_NG_MOJ_KEY;
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(Part) Success ***\n");
#endif
/**/
	while (1) {							/*	�����ɣУå��塼�������Ǥ���ޤ�	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(Part) ***\n");
#endif
		ckRslt	=	CreOpn_IPC (&UA ,UA.InfoPartProc.ua_PartIpcKey ,
									&UA.InfoPartProc.ua_PartIpcQid);
		if (ckRslt == STC_PRC_OK) {		/*	�ɣУå��塼��������	*/
			break;						/*	whileȴ����				*/
		}
		else {							/*	�ɣУå��塼��������	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(Part) Fail ***\n");
#endif
			if (errno == ENOENT) {		/*	�ɣУå��塼̤����		*/
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE NotCreate (errno=%d ,SendCount=%d)" ,argv[0] ,errno ,UA.ua_noRtySend);
				GetSysLog ("SOHA" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	��ȥ饤�����ϰ�		*/
					sleep(UA.ua_tmSend);/*	�ף��ɣ�				*/
					UA.ua_noRtySend++;	/*	����������գ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(Part) Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	��ȥ饤�����С�		*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(Part) RtryOver (%d) ***\n" ,RTN_NG_MOJ_QUE);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MOJ_QUE);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MOJ_QUE;
				}
			}
			else {						/*	�ɣУå��塼�����ץ���*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(Part) Error (%d) ***\n" ,RTN_NG_MOJ_QUE);
#endif
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE OPEN Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MOJ_QUE);
				GetSysLog ("SOHB" ,"ERR" ,infoSysLog);
				return	RTN_NG_MOJ_QUE;
			}
		}
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(Part) Success ***\n");
#endif
/****************************************/
/*	��ʸ�Խ��ΰ�γ���					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetDataArea ***\n");
#endif
	ckRslt	=	GetDataArea (&UA);		/*	�ΰ���ݽ���			*/
	if (ckRslt == STC_PRC_OK);			/*	�ΰ��������			*/
	else {								/*	�ΰ���ݼ���			*/
#ifdef	DEBUGF
printf ("*** smpmsg GetDataArea Error (%d ,%d) ***\n" ,ckRslt ,RTN_NG_SND_AREA);
#endif
		sprintf (infoSysLog ,"%s  DataArea Alloc Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_SND_AREA);
		GetSysLog ("SOHC" ,"ERR" ,infoSysLog);
		return	RTN_NG_SND_AREA;
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call GetDataArea Success ***\n");
#endif
/****************************************/
/*	�����塼����						*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg ResponsMsgInfo (%d) ***\n" ,UA.ua_fAccChk);
#endif
	if (UA.ua_fAccChk == DEF_FLG_ON) {	/*	��ã��ǧ��				*/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(My) ***\n");
#endif
		ckRslt	=	GetKey_IPC (&UA ,DEF_SMPMSG_MBOX_ID ,
									DEF_SMPMSG_PRJ_ID ,&UA.InfoMyProc.ua_MyIpcKey);
										/*	�ɣУå�������			*/
#ifdef	GETKEYERR
printf ("*** smpmsg GetKey_IPC(My) Rslt NG_Set Start (%d) ***\n" ,ckRslt);
ckRslt	=	STC_PRC_NG;
printf ("*** smpmsg GetKey_IPC(My) Rslt NG_Set End (%d) ***\n" ,ckRslt);
#endif
		if (ckRslt == STC_PRC_OK);		/*	��������				*/
		else {							/*	��������				*/
#ifdef	DEBUGF
printf ("*** smpmsg GetKey_IPC(My) Error (%d) ***\n" ,ckRslt);
#endif
			sprintf (infoSysLog ,"%s  My IPC_KEY Get Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MY_KEY);
			GetSysLog ("SOHD" ,"ERR" ,infoSysLog);
			return	RTN_NG_MY_KEY;
		}
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(My) Success ***\n");
#endif
/**/
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(My) ***\n");
#endif
		ckRslt	=	CreOpn_IPC (&UA ,UA.InfoMyProc.ua_MyIpcKey ,
									&UA.InfoMyProc.ua_MyIpcQid);
		if (ckRslt == STC_PRC_OK);		/*	�ɣУå��塼��������	*/
		else {							/*	�ɣУå��塼�����ץ���*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(My) Error (%d) ***\n" ,ckRslt);
#endif
			sprintf (infoSysLog ,"%s  My IPC_QUE OPEN Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MY_QUE);
			GetSysLog ("SOHE" ,"ERR" ,infoSysLog);
			return	RTN_NG_MY_QUE;
		}
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(My) Success ***\n");
#endif
	}
	else {								/*	��ã��ǧ����			*/
#ifdef	DEBUGF
printf ("*** smpmsg ResponsMsgInfo Nothing ***\n");
#endif
	}
/****************************************/
/*	��ʸ��Ѱ�����ʸ�Խ�				*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call EditData ***\n");
#endif
	EditData (&UA ,argv);
/**/
/****************************************/
/*	��ʸ��������						*/
/****************************************/
	while (1) {							/*	�����Ǥ���ޤ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg Call Send_IPC ***\n");
#endif
		ckRslt	=	Send_IPC (&UA);
		if (ckRslt == STC_PRC_OK) {		/*	��������				*/
			break;						/*	whileȴ����				*/
		}
		else {							/*	��������				*/
			if (errno == EINTR) {		/*	�����ʥ�ȯ��			*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC SndError Signal ***\n");
#endif
				continue;				/*	while�����				*/
			}
			if (errno == EAGAIN) {		/*	���塼����				*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC SndError QueFull ***\n");
#endif
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE FULL (errno=%d ,SendCount=%d)" ,argv[0] ,errno ,UA.ua_noRtySend);
				GetSysLog ("SOHF" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	��ȥ饤�����ϰ�		*/
					sleep(UA.ua_tmSend);/*	�ף��ɣ�				*/
					UA.ua_noRtySend++;	/*	����������գ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	��ȥ饤�����С�		*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC RtryOver (%d) ***\n" ,RTN_NG_MSG_SND);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MSG_SND);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MSG_SND;
				}
			}
			else {						/*	��̿Ū����������		*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC Error (%d) ***\n" ,RTN_NG_MSG_SND);
#endif
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE SEND Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MSG_SND);
				GetSysLog ("SOHG" ,"ERR" ,infoSysLog);
				return	RTN_NG_MSG_SND;
			}
		}
	}
#ifdef	DEBUGF
printf ("*** smpmsg Call Send_IPC Success ***\n");
#endif
/****************************************/
/*	��ʸ��������						*/
/****************************************/
	while (UA.ua_fAccChk == DEF_FLG_ON) {
										/*	��ã��ǧ��ʸ���������ޤ�	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call Rcv_IPC ***\n");
#endif
		ckRslt	=	Rcv_IPC (&UA);
		if (ckRslt == STC_PRC_OK) {		/*	��������					*/;
#ifdef	DEBUGF
printf ("*** smpmsg Call Rcv_IPC Success ***\n");
#endif
			if (UA.ua_pRcvData.msg_type == UA.ua_idProc) {
										/*	�ץ����ɣİ���			*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_type (%d ,%d) OK ***\n" ,UA.ua_pRcvData.msg_type ,UA.ua_idProc);
#endif
				if (UA.ua_pRcvData.msg_rslt == 0) {
										/*	��ã��ǧ����				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_rslt (%d) OK ***\n" ,UA.ua_pRcvData.msg_rslt);
#endif
					break;				/*	while��ȴ����				*/
				}
				else {					/*	��ã��ǧ�۾�				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_rslt (%d) NG ***\n" ,UA.ua_pRcvData.msg_rslt);
#endif
					sprintf (infoSysLog ,"%s  MessageSend Rslt Error (RcvRslt=%d ,rc=%d)" ,argv[0] ,UA.ua_pRcvData.msg_rslt ,RTN_NG_ACC_SND);
					GetSysLog ("SOHH" ,"ERR" ,infoSysLog);
					return	RTN_NG_ACC_SND;
				}
			}
			else {						/*	�ץ����ɣ��԰���			*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_type (%d ,%d) NG ***\n" ,UA.ua_pRcvData.msg_type ,UA.ua_idProc);
#endif
				sprintf (infoSysLog ,"%s  MessageType UnMatch (MyType=%d ,RcvMsgType=%d)" ,argv[0] ,UA.ua_idProc ,UA.ua_pRcvData.msg_type);
				GetSysLog ("SOHI" ,"ERR" ,infoSysLog);
				continue;				/*	while�����					*/
			}
		}
		else {							/*	��������					*/
			if (errno == EINTR) {		/*	�����ʥ�ȯ��				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC RcvError Signal ***\n");
#endif
				continue;				/*	while�����					*/
			}
			else {						/*	��̿Ū�ʼ�������			*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC RcvError (%d ,%d) ***\n" ,ckRslt ,errno);
#endif
				sprintf (infoSysLog ,"%s  My_IPC_QUE RCV Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_MSG_RCV);
				GetSysLog ("SOHJ" ,"ERR" ,infoSysLog);
				return	RTN_NG_MSG_RCV;
			}
		}
	}
/**/
#ifdef	DEBUGF
printf ("*** smpmsg End (%s) ***\n" ,argv[0]);
#endif
	sprintf (infoSysLog ,"%s  NORMAL END (rc=%d)" ,argv[0] ,RTN_OK);
	GetSysLog ("SOHK" ,"INFO" ,infoSysLog);
	return	RTN_OK;
}
/**/
/********************************************************************/
/*	���ϥ����å�													*/
/********************************************************************/
int		ParamaterCheck (pUA ,argc ,argv)
USER_AREA	*pUA;						/*	����������			*/
int			argc;						/*	�ѥ�᡼����			*/
char		*argv[];					/*	�ѥ�᡼������			*/
{
	long	cLP;						/*	�롼�ץ�����			*/
	long	cFreePrm;					/*	Ǥ�եѥ�᡼������		*/
	long	cMiaKlen;					/*  MIA������������			*/
	char	*endptr;					/*	strtol���顼����		*/
	int		i;							/*	������				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck Start ***\n");
#endif
/*	�ѥ�᡼���������å�				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck CountPram=%d ***\n" ,argc);
#endif
	if (((argc - 1) >= CK_PRM_MIN)	&&	/*	�ѥ�᡼���������ʾ�	*/
		((argc - 1) <= CK_PRM_MAX)) {	/*	��ģ����ʲ�			*/
		cFreePrm	=	argc - CK_PRM_MIN - 1;
	}
	else {								/*	�ѥ�᡼��������		*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck CountPramError ***\n");
#endif
		return	STC_PRC_NG;
	}
/****************************************/
/*	ɬ�ܥѥ�᡼����������å�			*/
/****************************************/
/***�ͣ˥����ɥ����å�				*****/
	if (strlen(argv[1]) == CK_PRM_LEN8);/*	����λ�				*/
	else {								/*	����ʳ�				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MkCode LengthError (%d) ***\n" ,strlen(argv[1]));
#endif
		return	STC_PRC_NG;
	}
	strtol (argv[1] ,&endptr ,16);		/*	�£ã��Ѵ������å�		*/
	if (endptr[0] == '\0');				/*	�£ã��Ѵ���ǽ������	*/
	else {								/*	�£ã��Ѵ��Բ�ǽ������	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MkCode BcdError (%s) ***\n" ,argv[1]);
#endif
		return	STC_PRC_NG;
	}
/***ȯ����ץ���̾�����å�		*****/
	if ((strlen(argv[2]) >= CK_PRM_LEN1)	&&	(strlen(argv[2]) <= CK_PRM_LEN8));
										/*	�ϰ���ʣ����飸���	*/
	else {								/*	�ϰϳ�					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck nmSend LengthError (%d) ***\n" ,strlen(argv[2]));
#endif
		return	STC_PRC_NG;
	}
/***�ͣɣ����̰�����ǡ��������å�	*****/
	if ((strlen(argv[3]) % 2) == 0);	/*	��������λ�			*/
	else {								/*	�������λ�			*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaData LengthError (%d) ***\n" ,strlen(argv[3]));
#endif
		return	STC_PRC_NG;
	}
/****************************************/
/*	Ǥ�եѥ�᡼����������å�			*/
/****************************************/
	for (i = 0 ,pUA->ua_lenMia = DEF_MIA_LEN ,pUA->ua_noSend = DEF_SND_NUM ,
				pUA->ua_fAccChk = DEF_FLG_OFF ,pUA->ua_tmSend = DEF_TIM_SND ;i < cFreePrm ;i++) {
		if ((strcmp(argv[i+4] ,CK_PRM_MIA_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_SND_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_CHK_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_TIM_OPT) == 0));
										/*	���ץ����������		*/
		else {							/*	���ץ����������		*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck OptionError (%s) ***\n" ,argv[i+4]);
#endif
			return	STC_PRC_NG;
		}
/*	�ͣɣ����̰�����ǡ���Ĺ���ץ����	*/
		if (strcmp(argv[i+4] ,CK_PRM_MIA_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	�����󤢤�				*/
			else {								/*	������ʤ�				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_lenMia	=	strtol (argv[i+4] ,&endptr ,10);
												/*	�£ã��Ѵ�				*/
			if (endptr[0] == '\0');				/*	�£ã��Ѵ���ǽ������	*/
			else {								/*	�£ã��Ѵ��Բ�ǽ������	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if (pUA->ua_lenMia >= CK_PRM_MIA_MIN);
												/*	�ϰ���ʣ��ʾ��		*/
			else {								/*	�ϰϳ�					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaLengthError (%d) ***\n" ,pUA->ua_lenMia);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
/*	����������ץ����					*/
		if (strcmp(argv[i+4] ,CK_PRM_SND_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	�����󤢤�				*/
			else {								/*	������ʤ�				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_noSend	=	strtol (argv[i+4] ,&endptr ,10);
												/*	�£ã��Ѵ�				*/
			if (endptr[0] == '\0');				/*	�£ã��Ѵ���ǽ������	*/
			else {								/*	�£ã��Ѵ��Բ�ǽ������	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if ((pUA->ua_noSend >= CK_PRM_SND_MIN)	&&	(pUA->ua_noSend <= CK_PRM_SND_MAX));
										/*	�ϰ���ʣ����飱������	*/
			else {						/*	�ϰϳ�					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountLengthError (%d) ***\n" ,pUA->ua_noSend);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
/*	��ã��ǧ���ץ����					*/
		if (strcmp(argv[i+4] ,CK_PRM_CHK_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendChekOption (%s) ***\n" ,argv[i+4]);
#endif
			pUA->ua_fAccChk	=	DEF_FLG_ON;
			continue;
		}
/*	�����ֳ֥��ץ����					*/
		if (strcmp(argv[i+4] ,CK_PRM_TIM_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	�����󤢤�				*/
			else {								/*	������ʤ�				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_tmSend	=	strtol (argv[i+4] ,&endptr ,10);
												/*	�£ã��Ѵ�				*/
			if (endptr[0] == '\0');				/*	�£ã��Ѵ���ǽ������	*/
			else {								/*	�£ã��Ѵ��Բ�ǽ������	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if (pUA->ua_tmSend >= CK_PRM_TIM_MIN);
												/*	�ϰ���ʣ��ʾ��		*/
			else {								/*	�ϰϳ�					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryLengthError (%d) ***\n" ,pUA->ua_tmSend);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
	}
	/* TBCS0066 Start */
	/* MIA�������ǡ��������������å��ɲ� : BCD�Ѵ���ǽ�ʥ����ɤǤ��뤳��*/

	cMiaKlen = strlen(argv[3]) ;		/*  MIA������������         */
#ifdef DEBUGF
printf( "*** smpmsg ParamaterCheck cMiaKlen= %d ***\n", cMiaKlen );
#endif
	for( i=0 ; i <  cMiaKlen ; i++ ){
		if( ( argv[3][i] >= '0' && argv[3][i]  <= '9') ||
			( argv[3][i] >= 'A' && argv[3][i]  <= 'F') ||
			( argv[3][i] >= 'a' && argv[3][i]  <= 'f') ) {
		}
		else {

#ifdef DEBUGF
printf( "*** smpmsg ParamaterCheck argv[3][%d] NG = 0x%2x ***\n", i, argv[3][i] );
#endif
			return RTN_NG_MIAKDATA ;
		}

	}
#ifdef DEBUGF
printf( "*** smpmsg ParamaterCheck argv[3] Data OK ***\n" );
#endif
	/* TBCS0066 end */

#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck End ***\n");
#endif
	return	STC_PRC_OK;
}
/********************************************************************/
/*	��ʸ��ѥץ�����¸��ǧ										*/
/********************************************************************/
int		MojArriveCheck (pUA ,cPrc)
USER_AREA	*pUA;						/*	����������			*/
long		*cPrc;						/*	��¸��					*/
{
	int			cdRt;					/*	�ֵѾ���				*/
	FILE		*pF;					/*	popen�ե�����ݥ���	*/
	char		infGet[64];				/*	popen��̾������		*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck Start ***\n");
#endif
/**/
	if ((pF = popen (DEF_MOJ_ARRIVE ,"r")) == NULL) {
										/*	���ޥ�ɼ���			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck CommandError ***\n");
#endif
		cdRt	=	STC_PRC_NG;
	}
	else {								/*	���ޥ������			*/
		while (1) {						/*	�ͣϣʤ򸡺�����ޤ�	*/
			if ((fgets (infGet ,sizeof(infGet) ,pF)) == NULL) {
										/*	�����������			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck InfomationNothing ***\n");
#endif
				*cPrc	=	0;
				cdRt	=	STC_PRC_OK;
				break;
			}
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck InfomationCheck Start ***\n");
#endif
			if ((strncmp(infGet ,DEF_MOJ_PROCNM ,strlen(infGet)-1)) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck InfomationCheck Mach ***\n");
#endif
				*cPrc	=	1;
				cdRt	=	STC_PRC_OK;
				break;
			}
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck InfomationCheck UnMach (%s) ***\n" ,infGet);
#endif
		}
		pclose (pF);
	}
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck End (%d) ***\n" ,cdRt);
#endif
	return	cdRt;
}
