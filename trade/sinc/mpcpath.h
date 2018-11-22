/****************************************************************************/
/* ﾌｧｲﾙ名　：　mpcpath.h													*/
/* 機能　　：  制御ステータス												*/
/*			   コンテキストテンプレート 									*/
/* 作成日　：  1993.12.15													*/
/* 更新日　：																*/
/****************************************************************************/

/**************************************/
/* 制御ステータス					  */
/**************************************/
#define  STSPINIT	  0x00				/* S200:未オープン					*/
#define  STSPOWIP	  0x01				/* S201:オープン中／IPｱﾄﾞﾚｽ設定待ち */
#define  STSPOWAT	  0x02				/* S202:オープン中／ATTACH中		*/
#define  STSPOWBD	  0x03				/* S203:オープン中／BIND中			*/
#define  STSPOPEN	  0x04				/* S204:オープン済／ｺﾈｸｼｮﾝ未設定	*/
#define  STSPOWLS	  0x05				/* S205:オープン済／LISTEN中		*/
#define  STSPOELS	  0x06				/* S206:オープン済／LISTEN済		*/
#define  STSPOWAS	  0x07				/* S207:オープン済／非同期通知待ち	*/
#define  STSPOWAC	  0x08				/* S208:オープン済／ACCEPT中		*/
#define  STSPOACT	  0x09				/* S209:オープン済／ACTIVE設定中	*/
#define  STSPOCLW	  0x0A				/* S210:オープン済／ｸﾛｰｽﾞ待ち		*/
#define  STSPDWSC	  0x0B				/* S211:回線DEACT中／ｼｽﾃﾑｺｰﾙ回収中	*/
#define  STSPDWDT	  0x0C				/* S212:回線DEACT中／DETACH中		*/
#define  STSPDFRE	  0x0D				/* S213:回線DEACT中／解放済 		*/
#define  STSPOWSC	  0x0E				/* S214:オープン中／ｼｽﾃﾑｺｰﾙ回収中	*/
#define  STSPOWDT	  0x0F				/* S215:オープン中／DETACH中		*/
#define  STSPCWSC	  0x10				/* S216:クローズ中／ｼｽﾃﾑｺｰﾙ回収中	*/
#define  STSPCWDT	  0x11				/* S217:クローズ中／DETACH中		*/
#define  STSPORCV	  0x12				/* S218:故障回復済み				*/

/**************************************/
/* 制御フラグ定義					  */
/**************************************/
#define FLGPSYN 	0x01				/* 着信フラグ						*/
#define FLGPABRP	0x02				/* アボート通知同期フラグ			*/

#define FLGPNULL	0x00				/* フラグ（初期状態）				*/
/**************************************/
/* コンテキストテンプレート 		  */
/**************************************/
typedef struct {
	long			chead[3];			/* スケジューラ管理域				*/
	short			pathno; 			/* 論理パス番号 					*/
	char			status; 			/* 制御ステータス（論理パス制御）	*/
	unsigned char	flags;				/* 制御フラグ						*/
	unsigned short	lsno;				/* ＬＳ番号 						*/
	unsigned char	cntsyscl;			/* システムコール数 				*/
	char			reserve2;			/* 予備 							*/
	long			lipaddr;			/* ローカルインターネットアドレス	*/
	short			lport;				/* ローカルポート番号				*/
	unsigned short	lsnul;				/* ＬＳ数							*/
	unsigned short	cntctxt;			/* 取得コンテキスト数				*/
	unsigned short	maxctxt;			/* 最大コネクション数				*/
	XQT 			ctxtqt; 			/* コネクションコンテキストＱＴ 	*/
	long			listenqt[2];		/* ＬＩＳＴＥＮ要求ＱＴ 			*/
	long			opnmsgp;			/* オープン要求退避域				*/
	long			clsmsgp;			/* クローズ要求退避域				*/
	long			falmsgp;			/* 故障通知要求退避域				*/
	long			rcvmsgp;			/* 故障回復通知要求退避域			*/
	long			cfremsgp;			/* コネクション解放(ｱﾎﾞｰﾄ)要求退避域*/
	long			linctxtp;			/* 回線制御コンテキストアドレス 	*/
	unsigned long	maxrbuff;			/* 受信バッファサイズ上限値 		*/
	unsigned long	minrbuff;			/* 受信バッファサイズ下限値 		*/
	unsigned long	maxsbuff;			/* 送信バッファサイズ上限値 		*/
	unsigned long	minsbuff;			/* 送信バッファサイズ下限値 		*/
	long			pdacirbp;			/* パスＤＥＡＣＴ通知退避域 		*/
	short			failinfo;			/* 故障情報 						*/
	unsigned char	maxsndrq;			/* 同時送信要求最大数				*/
	unsigned char	maxrcvrq;			/* 同時受信要求最大数				*/
	unsigned short	cntlstrq;			/* ＬＩＳＴＥＮ要求数				*/
	unsigned short	timdetch;			/* ＤＥＴＡＣＨインターバルタイマ	*/
}	MPCPMB;
