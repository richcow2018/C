/****************************************************/
/* meio.h		統合I/O共通関数ﾍｯﾀﾞﾌｧｲﾙ				*/
/* 1994.12.19	作成者　西山伸						*/
/*													*/
/* 1995.07.06   修正者　新藤由美				 M01*/
/*				返却値変換テーブルが静的(static)なの*/
/*				を実体が１つになるように変更する	*/
/*				実体は、me_pint()内で宣言している。	*/
/*				テーブル内の値（ｴﾗｰコード)はmeiort.h*/
/*				に宣言されている。					*/
/*				関連故障処理票：ST2911				*/
/* 1995.07.18   修正者　新藤由美				 M02*/
/*				LICPMESS構造体を変更。開発本部とﾈｺﾞ	*/
/*				して、APﾘｸｴｽﾄ識別子を追加。ついでに */
/*				予備に４バイトとっとく				*/
/*				APﾘｸｴｽﾄ識別子を追加した理由は、どの */
/*				LICPからのどの要求に対するリターンか*/
/*				わからないという不具合のため。		*/
/*				関連故障処理票：ST2772				*/
/* 1996.02.08 	修正者　営業店ｼｽﾃﾑ（新藤由美）	 M03*/
/*				4W on X.25のｱﾃﾝｼｮﾝのコマンド種別を  */
/*				0x05から0x06に変更する				*/
/*				関連故障処理票：ST4004				*/
/* 1996.01.08   修正者　新藤由美				 M04*/
/*				関連仕様変更要求書：SSCY0121		*/
/*				コマンド[IRTの発行]を追加する		*/
/*				ただし、実際にコマンドとして設定され*/
/*				て使用はされない。					*/
/* 1996.02.26   修正者　新藤由美				 M05*/
/*				故障処理票：ST4073					*/
/*				4W on X.25のｱﾃﾝｼｮﾝのコマンド種別を  */
/*				0x06から0x05に戻す					*/
/* 1997.04.30   修正者　北西智洋				 M06*/
/*				故障処理票：ST4666					*/
/*				4W-NTM on X.25の同一特殊ファイル２重*/
/*				コネクト処理の修正による変数域の追加*/
/* 1997.08.18   修正者　北西智洋				 M07*/
/*				故障処理票：ST4880					*/
/* 				非同期通知要求数４→２に変更		*/
/* 2003.02.25   修正者　佐治秀保				 M08*/
/* 				Linux移植に伴う修正					*/
/****************************************************/
#include "meiort.h"		/* return code  		 M01*/

/* 出力メッセージ最大長	*/
#define	LENMAX	4096

/* レスポンス待ちタイマ最大値	*/
#define	TIMMAX	127

/* LICP要求ＩＤ	*/
#define	REQMSGID	0x01110000

/* メッセージタイプ */
#define	MSGTREQ	0x01	/* 要求	*/
#define	MSGTFIN	0x02	/* 完了	*/
#define	MSGTNOT	0x03	/* 通知	*/	

/* ファンクションタイプ	*/
#define	FNCTOPN	0x01	/* オープン	*/
#define FNCTCLS	0x02	/* クローズ	*/
#define	FNCTRED 0x03	/* リード	*/
#define	FNCTWRT 0x04	/* ライト	*/
#define	FNCTCNT 0x05	/* ｺﾝﾄﾛｰﾙ	*/
#define	FNCTSNS 0x06	/* センス	*/

/* 中継先ﾌﾟﾛﾄｺﾙ(GWより先がどうなっているが)	*/
#define	GWARVPRK	0x00	/* GWｱﾗｲﾊﾞﾙ		*/
#define TCPIPPRK	0x01	/* TCP/IP		*/
#define	HDLCLPRK	0x02	/* HDLCﾙｰﾌﾟ		*/
#define	L4WIOPRK	0x03	/* 4W			*/

/* メッセージ受信待ち合わせタイマ値	*/
/* 180000 = ３分 */
/* ただしここでこの値を設定するのは間違いかも知れない */
/* （システムコールの引数からもってくる？） */
#define	RCVMSTIM	180000

#ifndef	PINT
extern long **lstrs; 		/* 95.07.06 extern に変更		 M01*/
#endif
/* ＬＩＣＰメッセージ域　形式	*/

struct licpmess {
	long	mesid;			/* ﾒｯｾｰｼﾞ識別子						*/
	long	dataadr;		/* ﾃﾞｰﾀﾊﾞｯﾌｧ相対ｱﾄﾞﾚｽ				*/
	short	datbufsize;		/* ﾃﾞｰﾀﾊﾞｯﾌｧｻｲｽﾞ					*/
	short	mestype;		/* ﾒｯｾｰｼﾞﾀｲﾌﾟ						*/
	short	functype;		/* ﾌｧﾝｸｼｮﾝﾀｲﾌﾟ						*/
	char	mesresinfo;		/* ﾒｯｾｰｼﾞ詳細情報/ﾚｽﾎﾟﾝｽ情報		*/
	char	reswaitime;		/* ﾚｽﾎﾟﾝｽ待ちﾀｲﾏｰ値					*/
	long	meslink;		/* ﾒｯｾｰｼﾞﾘﾝｸ域						*/
	long	passid;			/* ﾊﾟｽID							*/
	long	retcode;		/* ﾘﾀｰﾝｺｰﾄﾞ							*/
	long	promailid;		/* 返信用ﾌﾟﾛｾｽ識別子/ﾒｰﾙﾎﾞｯｸｽ識別子	*/
	long	ap_reqid;		/* APﾘｸｴｽﾄ識別子				 M02*/
	long	yobi1;			/* 予備							 M02*/
};
typedef struct licpmess LICPMESS;

/* ＬＩＣＰデータバッファ域　形式	*/

						/* 要求　論理パスオープン　Ｘ．２５		*/
struct datayopx1 {
	char	hcid;			/* 発着呼識別子						*/
	char	passno;			/* 論理ﾊﾟｽ番号						*/
	short	maxdata;		/* 最大分割ﾃﾞｰﾀ長					*/
	char	winsize;		/* ｳｲﾝﾄﾞｳｻｲｽﾞ						*/
	char	yob1;			/* ﾘｻﾞｰﾌﾞ							*/
	char	prtclid;		/* protocol id						*/
	char  lineif;     /* GW lineno & line kind	*/
	union {
		char secadr;	/* 2jikyoku address					*/
		long ipadr;		/* IP address						*/
		} adr;
	short	yob2;			/* ﾘｻﾞｰﾌﾞ							*/
	long	yob3;			/* ﾘｻﾞｰﾌﾞ							*/
};
typedef struct datayopx1 DATAYOPX1;
							/* 可変ﾃﾞｰﾀ域						*/
struct datayopx2 {
	short	calll;			/* call user data chou(24byte(0x18))*/
	char	year[2];		/* year(1950-2049),year[0]=19or20	*/
	char	month;			/* month							*/
	char	day;			/* day								*/
	char	week;			/* week(00=sun,01=mon,.....06=sat)	*/
	char	hour;			/* hour								*/
	char	minuet;			/* minuet							*/
	char	second;			/* second							*/
	char	gwproto;		/* chuukei class					*/
	char	gwlno;			/* GW kaisen bangou					*/
	char	dummy[2];		/* dummy							*/
	long	portnum;		/* tanmatsu local adress			*/
	long	tsopt;			/* tekiyou system option			*/
	long	yobi;			/* yobi(ALL 0x00)					*/
	char	yob3[200];		/* ﾘｻﾞｰﾌﾞ							*/
	long	x25head;		/* X.25ﾍｯﾀﾞ域						*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayopx2 DATAYOPX2;


						/* 要求　論理パスオープン　ＬＡＮ		*/
struct datayopl {
	char	hcid;			/* 発着呼識別子						*/
	char	passno;			/* 論理ﾊﾟｽ番号						*/
	short	maxdata;		/* 最大分割ﾃﾞｰﾀ長					*/
	char	winsize;		/* ｳｲﾝﾄﾞｳｻｲｽﾞ						*/
	char	yob1;			/* ﾘｻﾞｰﾌﾞ							*/
	short	yob2;			/* ﾘｻﾞｰﾌﾞ							*/
	long	desequno;		/* 相手装置番号(TCPﾎﾟｰﾄ番号)		*/
	char	yob3[16];		/* ﾘｻﾞｰﾌﾞ							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayopl DATAYOPL;
#define DATAYOPLSIZE 34		/* Linux移植に伴う修正			 M08*/

						/* 要求　論理パスクローズ　Ｘ．２５		*/
struct datayclx {
	char	yob1[8];		/* ﾘｻﾞｰﾌﾞ							*/
	long	x25head;		/* X.25ﾍｯﾀﾞ域						*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayclx DATAYCLX;

						/* 要求　論理パスクローズ　ＬＡＮ		*/
struct dataycll {
	char	yob1[16];		/* ﾘｻﾞｰﾌﾞ							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct dataycll DATAYCLL;
#define DATAYCLLSIZE 22		/* Linux移植に伴う修正			 M08*/


						/* 要求　データ書き込み　Ｘ．２５		*/
struct dataywtx {
	long	x25head;		/* X.25ﾍｯﾀﾞ域						*/
	char	msgchn;			/* MSG CHN							*/
	char	dtl;			/* DTL								*/
	char	sqn;			/* SQN								*/
	char	lpn;			/* LPN								*/
							/* ﾃﾞｰﾀ域							*/
};
typedef struct dataywtx DATAYWTX;

						/* 要求　データ書き込み　ＬＡＮ			*/
struct dataywtl {
	char	yob1[16];		/* ﾘｻﾞｰﾌﾞ							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	sqn;			/* SQN								*/
	char	lpn;			/* LPN								*/
							/* ﾃﾞｰﾀ域							*/
};
typedef struct dataywtl DATAYWTL;

						/* 要求　データ読み込み　Ｘ．２５		*/
						/* 要求　論理パス制御　　Ｘ．２５		*/
						/* 完了　データ読み込み　Ｘ．２５		*/
struct datayrdx {
	long	x25head;		/* X.25ﾍｯﾀﾞ域						*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	lpn;			/* LPN								*/
};
typedef struct datayrdx DATAYRDX;
typedef struct datayrdx DATAYCTX;
typedef struct datayrdx DATAKRDX;

						/* 要求　データ読み込み　ＬＡＮ			*/
						/* 要求　論理パス制御　　ＬＡＮ			*/
						/* 完了　データ読み込み　ＬＡＮ			*/
struct datayrdl {
	char	yob1[16];		/* ﾘｻﾞｰﾌﾞ							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	lpn;			/* LPN								*/
};
typedef struct datayrdl DATAYRDL;
typedef struct datayrdl DATAYCTL;
typedef struct datayrdl DATAKRDL;

struct fwcf {
	char cmdk;				/* コマンド種別						*/
	char ionb;				/* I/O番号							*/
	char snsrty;			/* センス回数						*/
	char cmdinf;			/* コマンド情報						*/
	char etbtx;				/* ETB/ETX種別						*/
	char fuka;				/* 付加情報							*/
	short attim;			/* ATT待ちタイマ					*/
	short rsv1;				/* 予備								*/
	short dtsz;				/* 送信データサイズ					*/
};
typedef struct fwcf FWCF;

/* ４ＷｏｎＸ．２５コマンド種別		*/
#define	WCCS	0x10		/* ＷＣ								*/
#define CCCS	0x11		/* ＣＣ								*/
#define RCCS	0x12		/* ＲＣ								*/
#define SCCS	0x13		/* ＳＣ								*/
#define ATCS	0x05		/* ＡＴＴ					 M03 M05*/

/* ４ＷｏｎＸ．２５センス回数		*/
#define SNSRTY	3			/* センス回数						*/

/* ４ＷｏｎＸ．２５　ETB/ETX種別	*/
#define ETB		0x17		/* ETB								*/
#define ETX		0x03		/* ETX								*/

struct head {                           /*  通信ヘッダフォーマット by kaori	*/
    short   pretcode;                   /*  プロトコルリターンコード        */
    short   pretspcd;                   /*  プロトコル詳細リターンコード    */
    char    ctype;                      /*  コマンド種別                    */
    char    ionum;                      /*  Ｉ／Ｏ番号                      */
    char    resinf;                     /*  レスポンス情報                  */
    char    etbetx;                     /*  ETB/ETX種別                     */
    short   datasize;                   /*  受信データサイズ                */
};
typedef struct head HEAD;

#define WWC 0x10
#define WCC 0x11
#define WRC 0x12
#define WSC 0x13
#define WAT 0x05						/* ｱﾃﾝｼｮﾝのコマンド種別		 M03 M05*/
#define IRC 0x20						/* IRTの発行　追加				 M04*/

struct s4wnox {
	short	pathno;						/* 論理パス番号						*/
	short	lgln;						/* LCGN+LCN番号						*/
	char	*facp;						/* TFACｱﾄﾞﾚｽ						*/
};
typedef struct s4wnox S4WNOX;

struct s4wnop {
	long	fd;							/* ファイル記述子				 M06*/
	short	pathno;						/* 論理パス番号					 M06*/
	short	yobi1;						/* 予備１						 M06*/
};
typedef struct s4wnop S4WNOP;

#define	S4WNN	2						/* 4W-NTMonX25ｺﾈｸｼｮﾝ数			M06	*/
#define	S4WHD	2						/* 4W-NTMonX25非同期通知要求数	M07 */


