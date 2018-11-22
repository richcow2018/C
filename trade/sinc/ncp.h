/****************************************************************************/
/* ノード間内部テーブル														*/
/****************************************************************************/
/****************************************************************************/
/* (ノード間送信実行)プロセス状態管理テーブル								*/
/****************************************************************************/
// 管理部
struct tpsmmng{
	long	tpsmpszcnt;					// 個別部数
	long	tpsmactpcnt;				// 起動プロセス数
	char	tpsmmyob1[8];				// 予備
};
typedef	struct	tpsmmng	TPSMMNG;

// 個別部
struct tpsmpsz{
	long	tpsmpid;					// ノード間送信実行プロセス識別子
	long	tpsmmbid;					// ノード間送信実行メイルボックス識別子
	char	tpsmpnm[8];					// ノード間送信実行プロセス名
	long	tpsmabtm;					// プロセスアボート回数 
	char	tpsmactsts;					// プロセス起動状態 '0':未起動 '1':起動 '2':状態不明
	char	tpsmusests;					// プロセス使用状態 '0':未使用 '1':使用中
	char	tpsmtosts;					// タイムアウト発生状態 '0':未発生 '1':発生済
	char	tpsmpyob1[9];				// 予備
};
typedef	struct	tpsmpsz	TPSMPSZ;

/****************************************************************************/
/* 送信要求電文蓄積テーブル													*/
/****************************************************************************/
// メッセージ部(個別部)
typedef	struct	tmsqpsz	TMSQPSZ;
struct tmsqpsz{
	TMSQPSZ	*tmsqbefad;					// 前メッセージアドレス
	TMSQPSZ	*tmsqnxtad;					// 次メッセージアドレス
	long	tmsqtime;					// メッセージ受信(格納)時間
	long	tmsqrd;						// タイマ管理用リクエスト識別子
	char	tmsqmsgsts;					// メッセージ送信状態 '0':未送信 '1':送信済
	char	tmsqmsgtyp;					// 電文タイプ '0':ノード間通信 '1':系間通信 '2':特殊系間通信
	char	tmsqpyob1[14];				// 予備
	char	tmsqmdxpnm[8];				// 送信先プロセス識別名(送信実行プロセス)
	long	tmsqmsgsz;					// 要求電文サイズ
	long	*tmsqmsgad;					// 送信要求電文格納プールバッファアドレス
};

// 管理部
typedef	struct	tmsqmng	TMSQMNG;
struct tmsqmng{
	TMSQPSZ		*tmsqbefad;				// 前メッセージアドレス
	TMSQPSZ		*tmsqnxtad;				// 次メッセージアドレス
	long	tmsqmsgcnt;					// 蓄積メッセージ数
	long	tmsqmsprrd;					// メッセージ受信要求リクエスト識別子
};


/****************************************************************************/
/* ノード間電文ヘッダ														*/
/****************************************************************************/
// ノード間通信制御ヘッダ
struct nodehead{
	char	mkcd[4];					// MKコード
	long	rcvtime;					// 受信時刻
	char	msgtype;					// 電文タイプ '0':ノード間通信 '1':系間通信 '2':特殊系間通信
	char	yob1[3];					// 予備
	long	rcode;						// 返却値
	char	sndpnm[8];					// 発信元プロセス識別名
	char	rcvpnm[8];					// 送信先プロセス識別名
	long	sndpmid;					// 発信元メイルボックス、プロセス識別子
	long	rcvpmid;					// 送信先メイルボックス、プロセス識別子
	long	msglen;						// 電文長
	char	yob2[4];					// 予備
};
typedef	struct	nodehead	NODEHEAD;

// 系間通信制御ヘッダ
struct keihead{
	char	mkcd[4];					// MKコード
	long	rcvtime;					// 受け付け時刻
	long	rcode;						// 返却値
	long	corbarc;					// CORBAマイナーコード 
	long	sndpmid;					// 発信元メイルボックス、プロセス識別子
	long	rcvpmid;					// 送信先メイルボックス、プロセス識別子
	long	msglen;						// 電文長
	char	yob2[4];					// 予備
};
typedef	struct	keihead	KEIHEAD;

// ノード間通信用MIA個別域エリア
struct mdaparea{
        long      if_code;				// インタフェースコード
        char      dummy;				// 予備
        char      code1;				// 通知コード１
        short     code2;				// 通知コード２
        short     nodeno;				// ノード番号
        short     idcode;				// 識別コード
        short     pu_no;				// PU番号
        short     line_no;				// 回線番号
};
typedef struct  mdaparea    MDAPAREA;

// MIA個別域エリア
struct miapsz{
        long	if_code;				// インタフェースコード
        long	code1;					// 通知コード１
        long	code2;					// 通知コード２
        long	endcd;					// 終了コード
        long	detail;					// 詳細コード
        char	prnm[8];				// プロセス識別名
};
typedef	struct	miapsz	MIAPSZ;

/****************************************************************************/
/* CORBA返却情報															*/
/****************************************************************************/
// 返却情報格納構造体
struct retinfo{
        long	cd1;					//サーバアプリ完了コード
        long	cd2;					//サーバアプリ詳細完了コード
        long	inf;					//応答任意情報(サーバアプリ動作系区分)
        long	major;					//CORBAメジャーコード
        long	minor;					//CORBAマイナーコード
        char	id[129];				//CORBA例外種別
		char	yobi[15];
};
typedef	struct	retinfo	RETINFO;

/****************************************************************************/
/* エラーテーブル															*/
/****************************************************************************/
struct errinf
{
	long	id;							/* 番号 */
	char	sysexcep_id[32];			/* CORBA system exception id		*/
	long	minorcd;					/* CORBA minor error code			*/
	long	svaplrc1;					/* server application return code 1	*/
	long	svaplrc2;					/* server application return code 2	*/
	char	noticecd1;					/* 通知コード 1						*/
	short	noticecd2;					/* 通知コード 2 					*/
	char	kdevacd;					/* 系間振り分け異常					*/
	long	senms2rc;					/* ossenms2返却値					*/
};
typedef	struct	errinf	ERRINF;

#define ERRTBLNUM	18					/* エラーテーブルの行数				*/

#define	ERID_MOCHI	50					/* 持ち回り電文不正					*/
#define	ERID_SNDND	51					/* 送信先ノード番号不正				*/
#define	ERID_TOUT	52					/* タイムアウト						*/
#define	ERID_ENDMDX	53					/* 送信中にMDX終了通知受信			*/

/****************************************************************************/
/* ノード間定数定義部														*/
/****************************************************************************/
//特殊系間電文MKコード
#define	MKCD_SPKEISND	0x01130101		// 特殊系間データ送信要求
#define	MKCD_SPKEIRCV	0x01130201		// 特殊系間データ送信応答

//ノード間制御電文MKコード
#define	MKCD_NDCTLSND	0x01130102		// ノード間データ送信要求
#define	MKCD_NDCTLRCV	0x01130202		// ノード間データ送信応答

//返却メッセージの種類
#define TP_TOUT			1				/* タイムアウト通知を受信			*/
#define TP_SPKEIREQ		2				/* 特殊系間送信要求電文(ossenms2)受信	*/
#define TP_NDCTLREP		3				/* ノード間制御送信応答電文受信		*/
#define TP_ENDREQ		4				/* プロセス終了要求電文受信			*/
#define TP_ENDNOTICE	5				/* プロセス終了通知電文受信			*/
#define TP_NDSNDREQ		6				/* ノード間データ送信要求電文受信	*/
#define TP_KEISNDREQ	7				/* 系間データ送信要求電文受信		*/
#define TP_NGMKCD		-1				/* MKコード不正						*/
#define TP_NGMOCHI		-2				/* 持ち回り電文不正					*/
#define TP_NGNODENO		-3				/* 送信先ノード番号不正				*/

//電文タイプ
#define	MSGTYPE_NODE	'0'				/* ノード間通信						*/
#define	MSGTYPE_KEI		'1'				/* 系間通信							*/
#define	MSGTYPE_SPKEI	'2'				/* 特殊系間通信(ossenms2)			*/

//ノード間送信実行プログラム種別
#define PRGTYP_MDX		"87"			/* ノード間送信実行プロセス			*/

//
#define	RESTDLY_MDC		3				/* mdcリスタート時の遅延時間		*/

/****************************************************************************/
/* サーバアプリケーション折り返し情報完了コード								*/
/****************************************************************************/
#define SVEND_NGMS	-1					/* 非プールバッファ上のメッセージ送信に失敗	*/
#define SVEND_NGPB	-2					/* プールバッファの確保に失敗		*/
#define SVEND_NGMB	-3					/* メイルボックス識別子の取得に失敗 */
#define SVEND_NGMSP	-4					/* プールバッファ上のメッセージ送信に失敗 */
