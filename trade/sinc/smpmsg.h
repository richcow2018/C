/********************************************************************/
/* 修正履歴                                                         */
/********************************************************************/
/* 障害番号   : TBCS0066                                            */
/* 障害内容   : MIA個別域に指定したデータが正しく電文に設定されない */
/* 修正内容   : MIA個別部妥当性チェック処理の追加                   */
/* 修正日付   : 2003.04.24                                          */
/* 修正者     : Supply Sugawara                                     */
/********************************************************************/

/****************************************/
/*	ｉｎｃｌｕｄｅ定義					*/
/****************************************/
#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <ctype.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <sys/ipc.h>
#include    <sys/msg.h>
#include	<fcntl.h>
#include    <errno.h>
#include	"mcmia.h"
#include	"smpmsg_hed.h"
#include	"smpmsg_com.h"
/**/
/****************************************/
/*	コンスタント情報					*/
/****************************************/
/*	電文中継プロセス情報				*/
#define		DEF_MOJ_PROCNM		"moj"
#define		DEF_MOJ_ARRIVE		"ps -a -eo %c | grep moj"
/*	返却値定義							*/
#define		RTN_OK				0		/*  正常						*/
#define		RTN_NG_PRM			-1		/*  異常（パラメータエラー)		*/
#define		RTN_NG_MOJ			-2		/*	異常（ＭＯＪ生存確認失敗）	*/
#define		RTN_NG_FL_OPEN		-3		/*	異常（ファイルオープン失敗）*/
#define		RTN_NG_FL_READ		-4		/*	異常（ファイルリード失敗）	*/
#define		RTN_NG_FL_CLOSE		-5		/*	異常（ファイルクローズ失敗）*/
#define		RTN_NG_MOJ_KEY		-6		/*	異常（ＭＯＪキー取得失敗）	*/
#define		RTN_NG_MOJ_QUE		-7		/*	異常（ＭＯＪキュー取得失敗）*/
#define		RTN_NG_SND_AREA		-8		/*	異常（送信電文域確保失敗）	*/
#define		RTN_NG_MY_KEY		-9		/*	異常（自キー取得失敗）		*/
#define		RTN_NG_MY_QUE		-10		/*	異常（自キュー取得失敗）	*/
#define		RTN_NG_MSG_SND		-11		/*	異常（電文送信失敗）		*/
#define		RTN_NG_ACC_SND		-12		/*	異常（送達確認失敗）		*/
#define		RTN_NG_MSG_RCV		-13		/*	異常（電文受信失敗）		*/
#define     RTN_NG_MIAKDATA     -14		/*  異常 (MIA個別部妥当性異常)	*//* TBCS0066 */
#define     RTN_NG_CHDATA		-15		/*  異常 (データ変換失敗)		*//* TBCS0066 */
/*	パラメータチェック条件定義			*/
#define		CK_PRM_MIN		3			/*	パラメータ最小値			*/
#define		CK_PRM_MAX		10			/*	パラメータ最大値	        */
#define		CK_PRM_LEN1		1			/*	レングス＝１				*/
#define		CK_PRM_LEN8		8			/*	レングス＝８				*/
#define		CK_PRM_MIA_OPT	"-l"		/*	ＭＩＡオプション			*/
#define		CK_PRM_MIA_MIN	4			/*	ＭＩＡ最小値				*/
#define		CK_PRM_SND_OPT	"-n"		/*	送信回数オプション			*/
#define		CK_PRM_SND_MIN	0			/*	送信回数最小値				*/
#define		CK_PRM_SND_MAX	100			/*	送信回数最大値				*/
#define		CK_PRM_CHK_OPT	"-s"		/*	送達確認オプション			*/
#define		CK_PRM_TIM_OPT	"-t"		/*	再送間隔オプション			*/
#define		CK_PRM_TIM_MIN	1			/*	再送間隔最小値				*/
/*	自・相手種別						*/
#define		PROC_TYPE_MY	0			/*	自プロセス					*/
#define		PROC_TYPE_PAT	1			/*	相手プロセス				*/
/*	デフォルト情報						*/
#define		DEF_FLG_ON		1			/*	フラグＯＮ					*/
#define		DEF_FLG_OFF		0			/*	フラグＯＦＦ				*/
#define		DEF_MIA_LEN		168			/*	ＭＩＡデフォルト値			*/
#define		DEF_SND_NUM		1			/*	送信回数デフォルト値		*/
#define		DEF_TIM_SND		5			/*	再送間隔デフォルト値		*/
#define		DEF_SND_UNLIMIT	0			/*	無制限送信					*/
/*	内部関数返却情報					*/
#define		STC_PRC_OK		0			/*	内部関数正常				*/
#define		STC_PRC_NG		-1			/*	内部関数異常				*/
/**/
/****************************************/
/*	持ち回り情報						*/
/****************************************/
typedef	struct {
	long	ua_lenMia;					/*	ＭＩＡ個別域長（引数）		*/
	long	ua_noSend;					/*	送信回数（引数）			*/
	int		ua_fAccChk;					/*	送達確認フラグ（引数）		*/
	int		ua_tmSend;					/*	再送信間隔（引数）			*/
/**/
	long	ua_noRtySend;				/*	再送信回数					*/
	int		ua_Rslt;					/*	エラー詳細情報				*/
	long	ua_idProc;					/*	自プロセスＩＤ				*/
	char	*ua_pSndData;				/*	電文中継依頼電文ポインタ	*/
	SMPMSGHED	ua_pRcvData;			/*	送達確認電文ポインタ		*/
	struct {							/*	自プロセス情報				*/
		long	ua_MyProcMbox;			/*	メイルボックスＩＤ			*/
		int		ua_MyProcPrj;			/*	プロセスプロジェクト情報	*/
		key_t	ua_MyIpcKey;			/*	メッセージキー				*/
		int		ua_MyIpcQid;			/*	メッセージキューＩＤ		*/
	}InfoMyProc;
	struct {							/*	相手プロセス情報			*/
		long	ua_PartProcMbox;		/*	メイルボックスＩＤ			*/
		int		ua_PartProcPrj;			/*	プロセスプロジェクト情報	*/
		key_t	ua_PartIpcKey;			/*	メッセージキー				*/
		int		ua_PartIpcQid;			/*	メッセージキューＩＤ		*/
	}InfoPartProc;
}USER_AREA;
/**/
/****************************************/
/*	関数定義							*/
/****************************************/
int		ParamaterCheck (USER_AREA* ,int ,char**);
int		MojArriveCheck (USER_AREA* ,long*);
void	GetSysLog (char* ,char* ,char*);
int		chcnData(char * , char*, int ) ;			/* TBCS0066			*/
/**/
/****************************************/
/*  メッセージ定義情報                  */
/****************************************/
#define		MSG_COUNT	50
#define		MSG_STOPER	"FFFF"
struct  tabMsg  {
char	*MsgNumber;
char	*MsgInfo;
};
