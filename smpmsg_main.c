/*------------------------------------------------------------------*/
/* ＜対象業務名＞                    運転管理業務                   */
/* ＜対象業務ＩＤ＞                  ＯＣＰ                         */
/* ＜サービス項目名＞                電文通知                       */
/* ＜サービス項目ＩＤ＞              ＸＸＸ                         */
/* ＜モジュール名＞                  ＸＸＸＸＸＸＸＸＸＸ           */
/* ＜モジュールＩＤ＞                ＸＸＸＸＸＸＸＸ               */
/* ＜モジュール通番＞                                               */
/*------------------------------------------------------------------*/
/* ＜適用機種＞                      ＡＣＥ                         */
/* ＜適用ＯＳ＞                      ＬＩＮＵＸ                     */
/* ＜開発環境＞                      ＬＩＮＵＸ                     */
/* ＜記述言語＞                      Ｃ言語                         */
/* ＜モジュール形態＞                コマンド                       */
/* ＜機能区分＞                                                     */
/* ＜対象データ＞                                                   */
/* ＜工程・階層区分＞                                               */
/*------------------------------------------------------------------*/
/* ＜開発システム名＞                ＡＣＥ−ＳＭＰシステム         */
/* ＜開発システム番号＞              ＸＸＸＸＸＸＸＸＸＸＸＸ       */
/*------------------------------------------------------------------*/
/* ＜開発担当者名＞                  Ｓｕｐｐｌｙ                   */
/* ＜電話番号＞                      03-3341-5504                   */
/*------------------------------------------------------------------*/
/* ＜設計者名＞                      Ｓｕｐｐｌｙ                   */
/* ＜設計年月日＞                    ２００３年０１月２９日         */
/* ＜設計修正者名＞                                                 */
/* ＜設計修正年月日及び修正ＩＤ＞                                   */
/*------------------------------------------------------------------*/
/* ＜ソース作成者名＞                Ｓｕｐｐｌｙ                   */
/* ＜ソース作成年月日＞              ２００３年０２月０２日         */
/* ＜ソース修正者名＞                                               */
/* ＜ソース修正年月日及び修正ＩＤ＞                                 */
/*------------------------------------------------------------------*/
/* ＜見積ステップ数＞                ステップ                       */
/*------------------------------------------------------------------*/
/* ＜機能概要＞                                                     */
/*                                                                  */
/*       ＳＭＰ配下の電文中継プロセスに依頼された電文を送信する     */
/*                                                                  */
/*------------------------------------------------------------------*/
/* ＜呼出形式＞                                                     */
/*     int     smpmsg( pCdMk                                        */
/*                     pNmSendPoint                                 */
/*                     pDtMia                                       */
/*                     [-l lenDtMia]                                */
/*                     [-n noSend] )                                */
/*                     [-s ]                                        */
/*                     [-t timRtySnd ]                              */
/*                                                                  */
/* ＜仮引数＞                                                       */
/*		pCdMk			:	ＭＫコード（必須）						*/
/*		pNmSendPoint	:	発信先プロセス名（必須）				*/
/*		pDtMia			:	ＭＩＡ個別域設定データ（必須）			*/
/*		-l				:	ＭＩＡ個別域設定データ長オプション		*/
/*		lenDtMia		:	ＭＩＡ個別域設定データ長				*/
/*		-n				:	送信回数オプション						*/
/*		noSend			:	送信回数								*/
/*		-s				:	送達確認指示							*/
/*		-t				:	送信リトライ間隔オプション				*/
/*		timRtySnd		:	送信リトライ間隔						*/
/*              なし                                                */
/* ＜返却値＞                                                       */
/*		0	:	正常												*/
/*		-1	:	異常（引数エラー）									*/
/*		-2	:	異常（電文中継プロセス生存確認失敗）				*/
/*		-3	:	異常（電文中継メイルボックス識別子					*/
/*								管理ファイルオープン失敗）			*/
/*		-4	:	異常（電文中継メイルボックス識別子					*/
/*								管理ファイルオープン失敗）			*/
/*		-5	:	異常（電文中継メイルボックス識別子					*/
/*								管理ファイルオープン失敗）			*/
/*		-6	:	異常（相手メッセージキー取得失敗）					*/
/*		-7	:	異常（相手メッセージキュー取得失敗）				*/
/*		-8	:	異常（送信電文編集領域確保失敗）					*/
/*		-9	:	異常（自メッセージキー取得失敗）					*/
/*		-10	:	異常（自メッセージキュー取得失敗）					*/
/*		-11	:	異常（電文中継依頼電文送信失敗）					*/
/*		-12	:	異常（送達確認失敗）								*/
/*		-13	:	異常（送達確認電文受信失敗）						*/
/*------------------------------------------------------------------*/
/* ＜制限事項＞         なし                                        */
/*                                                                  */
/* ＜使用外部モジュールＩＤ＞                                       */
/* ＜呼出モジュールＩＤ＞                                           */
/*                                                                  */
/********************************************************************/
/* 修正履歴															*/
/********************************************************************/
/* 障害番号	  : TBCS0066											*/
/* 障害内容	  : MIA個別域に指定したデータが正しく電文に設定されない */
/* 修正内容	  : MIA個別部妥当性チェック処理の追加					*/
/* 修正日付	  : 2003.04.24           	                            */
/* 修正者	  : Supply Sugawara										*/
/********************************************************************/
#include	"smpmsg.h"
/**/
char	infoSysLog[256];
/****************************************/
/*	作業領域							*/
/****************************************/
char	*pGetLog;						/*	ログ編集域				*/
/**/
int
main (argc ,argv)
int		argc;
char	*argv[];
{
	USER_AREA	UA;						/*	I/Fエリア				*/
	int			cLP;					/*	ループカウンタ			*/
	int			ckRslt;					/*	返却情報域				*/
	int			flgLogOut;				/*	ログ出力指示フラグ		*/
	int			hF;						/*	ファイルハンドル		*/
	int			lenData;				/*	読み込みサイズ			*/
	long		pBuf;					/*	読み込み域				*/
	key_t		keyIpc;					/*	ＩＰＣキー情報			*/
	int			queIpc;					/*	ＩＰＣキュー情報		*/
	long		cPrc;					/*	ＭＯＪ数				*/
/****************************************/
/*	初期化								*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Start (%s) ***\n" ,argv[0]);
#endif
	memset ((char*)&UA ,0x00 ,sizeof(USER_AREA));
	UA.ua_Rslt			=	RTN_OK;
/****************************************/
/*	自プロセスＩＤ取得					*/
/****************************************/
	UA.ua_idProc	=	getpid();
#ifdef	DEBUGF
printf ("*** smpmsg getpid (%d) ***\n" ,UA.ua_idProc);
#endif
/****************************************/
/*	パラメータチェック					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call ParamaterCheck ***\n");
#endif
	ckRslt	=	ParamaterCheck (&UA ,argc ,argv);
										/*	パラメータチェック処理	*/
	if (ckRslt == STC_PRC_OK);			/*	パラメータ正常			*/
	else {								/*	パラメータ不正			*/
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
/*	電文中継プロセス生存確認			*/
/****************************************/
	UA.ua_noRtySend		=	1;
	while (1) {							/*	生存するまで繰り返す	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call MojArriveCheck ***\n");
#endif
		ckRslt	=	MojArriveCheck (&UA ,&cPrc);
										/*	生存確認処理			*/
		if (ckRslt == STC_PRC_OK) {		/*	正常復帰の時			*/
			if (cPrc >= 1) {			/*	生存する場合			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck MojRunning (%d) ***\n" ,cPrc);
#endif
				break;					/*	whileを抜ける			*/
			}
			else {						/*	生存しない場合			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck MojNotRunning (%d) ***\n" ,cPrc);
#endif
				sprintf (infoSysLog ,"%s  MOJ_NotRunning (SendCount=%d)" ,argv[0] ,UA.ua_noRtySend);
				GetSysLog ("SOH2" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	リトライ許容範囲		*/
					sleep(UA.ua_tmSend);/*	ＷＡＩＴ				*/
					UA.ua_noRtySend++;	/*	再送信回数ＵＰ			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	リトライオーバー		*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck RetryOver (%d ,%d) ***\n" ,ckRslt ,RTN_NG_MOJ);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MOJ);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MOJ;
				}
			}
		}
		else {							/*	異常復帰の時			*/
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
/*	電文中継メイルボックス識別子の取得	*/
/****************************************/
	while (1) {							/*	情報が取得できるまで	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call File Open (%s) ***\n" ,DEF_MOJ_MBOX_PATH);
#endif
		hF	=	open (DEF_MOJ_MBOX_PATH ,O_RDONLY);
		if (hF != -1) {					/*	オープン成功			*/
			break;
		}
		else {							/*	オープン失敗			*/
			if (errno == ENOENT) {		/*	ファイル無し			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open FileNothing ***\n");
#endif
				sprintf (infoSysLog ,"%s  WatchFile Nothing (SendCount=%d)" ,argv[0] ,UA.ua_noRtySend);
				GetSysLog ("SOH5" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	リトライ許容範囲		*/
					sleep(UA.ua_tmSend);/*	ＷＡＩＴ				*/
					UA.ua_noRtySend++;	/*	再送信回数ＵＰ			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	リトライオーバー		*/
#ifdef	DEBUGF
printf ("*** smpmsg File Open RtryOver (%d) ***\n" ,RTN_NG_FL_OPEN);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_FL_OPEN);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_FL_OPEN;
				}
			}
			else {						/*	ファイル無し以外		*/
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
		if (lenData == -1) {			/*	読み込み異常			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Read Error (%d(%s) ,%d) ***\n" ,errno ,strerror(errno) ,RTN_NG_FL_READ);
#endif
			if (errno == EINTR) {		/*	シグナル発生			*/
				continue;				/*	whileに戻る				*/
			}
			sprintf (infoSysLog ,"%s  WatchFile READ Error (errno=%d ,rc=%d)" ,argv[0] ,errno ,RTN_NG_FL_READ);
			GetSysLog ("SOH7" ,"ERR" ,infoSysLog);
			close (hF);					/*	ファイルクローズ		*/
			return	RTN_NG_FL_READ;
		}
		if (lenData == 0) {				/*	EOF						*/
#ifdef	DEBUGF
printf ("*** smpmsg File Read EOF (%d ,%d) ***\n" ,errno ,RTN_NG_FL_READ);
#endif
			close (hF);						/*	ファイルクローズ		*/
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
		ckRslt	=	close (hF);			/*	ファイルクローズ		*/
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
		if (ckRslt == -1) {				/*	クローズ失敗			*/
#ifdef	DEBUGF
printf ("*** smpmsg File Close Error (%d(%s) ,%d) ***\n" ,errno ,strerror(errno) ,RTN_NG_FL_CLOSE);
#endif
			if (errno == EINTR) {		/*	シグナル発生			*/
				continue;				/*	whileに戻る				*/
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
/*	相手キューオープン					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(Part) ***\n");
#endif
	ckRslt	=	GetKey_IPC (&UA ,UA.InfoPartProc.ua_PartProcMbox ,
								DEF_MOJ_PRJ_ID ,&UA.InfoPartProc.ua_PartIpcKey);
										/*	ＩＰＣキー取得			*/
	if (ckRslt == STC_PRC_OK);			/*	取得成功				*/
	else {								/*	取得失敗				*/
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
	while (1) {							/*	送信ＩＰＣキューが取得できるまで	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(Part) ***\n");
#endif
		ckRslt	=	CreOpn_IPC (&UA ,UA.InfoPartProc.ua_PartIpcKey ,
									&UA.InfoPartProc.ua_PartIpcQid);
		if (ckRslt == STC_PRC_OK) {		/*	ＩＰＣキュー取得成功	*/
			break;						/*	while抜ける				*/
		}
		else {							/*	ＩＰＣキュー取得失敗	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call CreOpn_IPC(Part) Fail ***\n");
#endif
			if (errno == ENOENT) {		/*	ＩＰＣキュー未生成		*/
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE NotCreate (errno=%d ,SendCount=%d)" ,argv[0] ,errno ,UA.ua_noRtySend);
				GetSysLog ("SOHA" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	リトライ許容範囲		*/
					sleep(UA.ua_tmSend);/*	ＷＡＩＴ				*/
					UA.ua_noRtySend++;	/*	再送信回数ＵＰ			*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(Part) Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	リトライオーバー		*/
#ifdef	DEBUGF
printf ("*** smpmsg CreOpn_IPC(Part) RtryOver (%d) ***\n" ,RTN_NG_MOJ_QUE);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MOJ_QUE);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MOJ_QUE;
				}
			}
			else {						/*	ＩＰＣキューオープン失敗*/
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
/*	電文編集領域の確保					*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetDataArea ***\n");
#endif
	ckRslt	=	GetDataArea (&UA);		/*	領域確保処理			*/
	if (ckRslt == STC_PRC_OK);			/*	領域確保成功			*/
	else {								/*	領域確保失敗			*/
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
/*	自キュー作成						*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg ResponsMsgInfo (%d) ***\n" ,UA.ua_fAccChk);
#endif
	if (UA.ua_fAccChk == DEF_FLG_ON) {	/*	送達確認要				*/
#ifdef	DEBUGF
printf ("*** smpmsg Call GetKey_IPC(My) ***\n");
#endif
		ckRslt	=	GetKey_IPC (&UA ,DEF_SMPMSG_MBOX_ID ,
									DEF_SMPMSG_PRJ_ID ,&UA.InfoMyProc.ua_MyIpcKey);
										/*	ＩＰＣキー取得			*/
#ifdef	GETKEYERR
printf ("*** smpmsg GetKey_IPC(My) Rslt NG_Set Start (%d) ***\n" ,ckRslt);
ckRslt	=	STC_PRC_NG;
printf ("*** smpmsg GetKey_IPC(My) Rslt NG_Set End (%d) ***\n" ,ckRslt);
#endif
		if (ckRslt == STC_PRC_OK);		/*	取得成功				*/
		else {							/*	取得失敗				*/
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
		if (ckRslt == STC_PRC_OK);		/*	ＩＰＣキュー取得成功	*/
		else {							/*	ＩＰＣキューオープン失敗*/
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
	else {								/*	送達確認不要			*/
#ifdef	DEBUGF
printf ("*** smpmsg ResponsMsgInfo Nothing ***\n");
#endif
	}
/****************************************/
/*	電文中継依頼電文編集				*/
/****************************************/
#ifdef	DEBUGF
printf ("*** smpmsg Call EditData ***\n");
#endif
	EditData (&UA ,argv);
/**/
/****************************************/
/*	電文送信処理						*/
/****************************************/
	while (1) {							/*	送信できるまで			*/
#ifdef	DEBUGF
printf ("*** smpmsg Call Send_IPC ***\n");
#endif
		ckRslt	=	Send_IPC (&UA);
		if (ckRslt == STC_PRC_OK) {		/*	送信成功				*/
			break;						/*	while抜ける				*/
		}
		else {							/*	送信失敗				*/
			if (errno == EINTR) {		/*	シグナル発生			*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC SndError Signal ***\n");
#endif
				continue;				/*	whileに戻る				*/
			}
			if (errno == EAGAIN) {		/*	キュー一杯				*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC SndError QueFull ***\n");
#endif
				sprintf (infoSysLog ,"%s  MOJ_IPC_QUE FULL (errno=%d ,SendCount=%d)" ,argv[0] ,errno ,UA.ua_noRtySend);
				GetSysLog ("SOHF" ,"ERR" ,infoSysLog);
				if ((UA.ua_noSend == DEF_SND_UNLIMIT)	||
					((UA.ua_noSend != DEF_SND_UNLIMIT)	&&	(UA.ua_noSend > UA.ua_noRtySend))) {
										/*	リトライ許容範囲		*/
					sleep(UA.ua_tmSend);/*	ＷＡＩＴ				*/
					UA.ua_noRtySend++;	/*	再送信回数ＵＰ			*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC Retry (%d ,%d) ***\n" ,UA.ua_noSend, UA.ua_noRtySend);
#endif
				}
				else {					/*	リトライオーバー		*/
#ifdef	DEBUGF
printf ("*** smpmsg Send_IPC RtryOver (%d) ***\n" ,RTN_NG_MSG_SND);
#endif
					sprintf (infoSysLog ,"%s  Retry Over (rc=%d)" ,argv[0] ,RTN_NG_MSG_SND);
					GetSysLog ("SOH3" ,"ERR" ,infoSysLog);
					return	RTN_NG_MSG_SND;
				}
			}
			else {						/*	致命的な送信失敗		*/
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
/*	電文受信処理						*/
/****************************************/
	while (UA.ua_fAccChk == DEF_FLG_ON) {
										/*	送達確認電文を受信するまで	*/
#ifdef	DEBUGF
printf ("*** smpmsg Call Rcv_IPC ***\n");
#endif
		ckRslt	=	Rcv_IPC (&UA);
		if (ckRslt == STC_PRC_OK) {		/*	受信成功					*/;
#ifdef	DEBUGF
printf ("*** smpmsg Call Rcv_IPC Success ***\n");
#endif
			if (UA.ua_pRcvData.msg_type == UA.ua_idProc) {
										/*	プロセスＩＤ一致			*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_type (%d ,%d) OK ***\n" ,UA.ua_pRcvData.msg_type ,UA.ua_idProc);
#endif
				if (UA.ua_pRcvData.msg_rslt == 0) {
										/*	送達確認成功				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_rslt (%d) OK ***\n" ,UA.ua_pRcvData.msg_rslt);
#endif
					break;				/*	whileを抜ける				*/
				}
				else {					/*	送達確認異常				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_rslt (%d) NG ***\n" ,UA.ua_pRcvData.msg_rslt);
#endif
					sprintf (infoSysLog ,"%s  MessageSend Rslt Error (RcvRslt=%d ,rc=%d)" ,argv[0] ,UA.ua_pRcvData.msg_rslt ,RTN_NG_ACC_SND);
					GetSysLog ("SOHH" ,"ERR" ,infoSysLog);
					return	RTN_NG_ACC_SND;
				}
			}
			else {						/*	プロセスＩＤ不一致			*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC msg_type (%d ,%d) NG ***\n" ,UA.ua_pRcvData.msg_type ,UA.ua_idProc);
#endif
				sprintf (infoSysLog ,"%s  MessageType UnMatch (MyType=%d ,RcvMsgType=%d)" ,argv[0] ,UA.ua_idProc ,UA.ua_pRcvData.msg_type);
				GetSysLog ("SOHI" ,"ERR" ,infoSysLog);
				continue;				/*	whileに戻る					*/
			}
		}
		else {							/*	受信失敗					*/
			if (errno == EINTR) {		/*	シグナル発生				*/
#ifdef	DEBUGF
printf ("*** smpmsg Rcv_IPC RcvError Signal ***\n");
#endif
				continue;				/*	whileに戻る					*/
			}
			else {						/*	致命的な受信失敗			*/
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
/*	入力チェック													*/
/********************************************************************/
int		ParamaterCheck (pUA ,argc ,argv)
USER_AREA	*pUA;						/*	持ち回り情報			*/
int			argc;						/*	パラメータ数			*/
char		*argv[];					/*	パラメータ内容			*/
{
	long	cLP;						/*	ループカウンタ			*/
	long	cFreePrm;					/*	任意パラメータ数域		*/
	long	cMiaKlen;					/*  MIA個別部サイズ			*/
	char	*endptr;					/*	strtolエラー情報		*/
	int		i;							/*	カウンタ				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck Start ***\n");
#endif
/*	パラメータ数チェック				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck CountPram=%d ***\n" ,argc);
#endif
	if (((argc - 1) >= CK_PRM_MIN)	&&	/*	パラメータ数が３以上	*/
		((argc - 1) <= CK_PRM_MAX)) {	/*	且つ１０以下			*/
		cFreePrm	=	argc - CK_PRM_MIN - 1;
	}
	else {								/*	パラメータ数不正		*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck CountPramError ***\n");
#endif
		return	STC_PRC_NG;
	}
/****************************************/
/*	必須パラメータ情報チェック			*/
/****************************************/
/***ＭＫコードチェック				*****/
	if (strlen(argv[1]) == CK_PRM_LEN8);/*	８桁の時				*/
	else {								/*	８桁以外				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MkCode LengthError (%d) ***\n" ,strlen(argv[1]));
#endif
		return	STC_PRC_NG;
	}
	strtol (argv[1] ,&endptr ,16);		/*	ＢＣＤ変換チェック		*/
	if (endptr[0] == '\0');				/*	ＢＣＤ変換可能コード	*/
	else {								/*	ＢＣＤ変換不可能コード	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MkCode BcdError (%s) ***\n" ,argv[1]);
#endif
		return	STC_PRC_NG;
	}
/***発信先プロセス名チェック		*****/
	if ((strlen(argv[2]) >= CK_PRM_LEN1)	&&	(strlen(argv[2]) <= CK_PRM_LEN8));
										/*	範囲内（１から８桁）	*/
	else {								/*	範囲外					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck nmSend LengthError (%d) ***\n" ,strlen(argv[2]));
#endif
		return	STC_PRC_NG;
	}
/***ＭＩＡ個別域設定データチェック	*****/
	if ((strlen(argv[3]) % 2) == 0);	/*	偶数桁数の時			*/
	else {								/*	奇数桁数の時			*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaData LengthError (%d) ***\n" ,strlen(argv[3]));
#endif
		return	STC_PRC_NG;
	}
/****************************************/
/*	任意パラメータ情報チェック			*/
/****************************************/
	for (i = 0 ,pUA->ua_lenMia = DEF_MIA_LEN ,pUA->ua_noSend = DEF_SND_NUM ,
				pUA->ua_fAccChk = DEF_FLG_OFF ,pUA->ua_tmSend = DEF_TIM_SND ;i < cFreePrm ;i++) {
		if ((strcmp(argv[i+4] ,CK_PRM_MIA_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_SND_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_CHK_OPT) == 0)	||
			(strcmp(argv[i+4] ,CK_PRM_TIM_OPT) == 0));
										/*	オプション妥当時		*/
		else {							/*	オプション不正時		*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck OptionError (%s) ***\n" ,argv[i+4]);
#endif
			return	STC_PRC_NG;
		}
/*	ＭＩＡ個別域設定データ長オプション	*/
		if (strcmp(argv[i+4] ,CK_PRM_MIA_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	次情報あり				*/
			else {								/*	次情報なし				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_lenMia	=	strtol (argv[i+4] ,&endptr ,10);
												/*	ＢＣＤ変換				*/
			if (endptr[0] == '\0');				/*	ＢＣＤ変換可能コード	*/
			else {								/*	ＢＣＤ変換不可能コード	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if (pUA->ua_lenMia >= CK_PRM_MIA_MIN);
												/*	範囲内（４以上）		*/
			else {								/*	範囲外					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck MiaLengthError (%d) ***\n" ,pUA->ua_lenMia);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
/*	送信回数オプション					*/
		if (strcmp(argv[i+4] ,CK_PRM_SND_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	次情報あり				*/
			else {								/*	次情報なし				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_noSend	=	strtol (argv[i+4] ,&endptr ,10);
												/*	ＢＣＤ変換				*/
			if (endptr[0] == '\0');				/*	ＢＣＤ変換可能コード	*/
			else {								/*	ＢＣＤ変換不可能コード	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if ((pUA->ua_noSend >= CK_PRM_SND_MIN)	&&	(pUA->ua_noSend <= CK_PRM_SND_MAX));
										/*	範囲内（０から１００）	*/
			else {						/*	範囲外					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendCountLengthError (%d) ***\n" ,pUA->ua_noSend);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
/*	送達確認オプション					*/
		if (strcmp(argv[i+4] ,CK_PRM_CHK_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck SendChekOption (%s) ***\n" ,argv[i+4]);
#endif
			pUA->ua_fAccChk	=	DEF_FLG_ON;
			continue;
		}
/*	再送間隔オプション					*/
		if (strcmp(argv[i+4] ,CK_PRM_TIM_OPT) == 0) {
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryOption (%s) ***\n" ,argv[i+4]);
#endif
			i++;
			if (argv[i+4] != NULL);				/*	次情報あり				*/
			else {								/*	次情報なし				*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryOption DataNothing ***\n");
#endif
				return	STC_PRC_NG;
			}
			pUA->ua_tmSend	=	strtol (argv[i+4] ,&endptr ,10);
												/*	ＢＣＤ変換				*/
			if (endptr[0] == '\0');				/*	ＢＣＤ変換可能コード	*/
			else {								/*	ＢＣＤ変換不可能コード	*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryLength BcdError (%s) ***\n" ,argv[i+4]);
#endif
				return	STC_PRC_NG;
			}
			if (pUA->ua_tmSend >= CK_PRM_TIM_MIN);
												/*	範囲内（１以上）		*/
			else {								/*	範囲外					*/
#ifdef	DEBUGF
printf ("*** smpmsg ParamaterCheck RetryLengthError (%d) ***\n" ,pUA->ua_tmSend);
#endif
				return	STC_PRC_NG;
			}
			continue;
		}
	}
	/* TBCS0066 Start */
	/* MIA個別部データ妥当性チェック追加 : BCD変換可能なコードであること*/

	cMiaKlen = strlen(argv[3]) ;		/*  MIA個別部サイズ         */
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
/*	電文中継プロセス生存確認										*/
/********************************************************************/
int		MojArriveCheck (pUA ,cPrc)
USER_AREA	*pUA;						/*	持ち回り情報			*/
long		*cPrc;						/*	生存数					*/
{
	int			cdRt;					/*	返却情報				*/
	FILE		*pF;					/*	popenファイルポインタ	*/
	char		infGet[64];				/*	popen結果情報取得		*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck Start ***\n");
#endif
/**/
	if ((pF = popen (DEF_MOJ_ARRIVE ,"r")) == NULL) {
										/*	コマンド失敗			*/
#ifdef	DEBUGF
printf ("*** smpmsg MojArriveCheck CommandError ***\n");
#endif
		cdRt	=	STC_PRC_NG;
	}
	else {								/*	コマンド成功			*/
		while (1) {						/*	ＭＯＪを検索するまで	*/
			if ((fgets (infGet ,sizeof(infGet) ,pF)) == NULL) {
										/*	検索情報取得			*/
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
