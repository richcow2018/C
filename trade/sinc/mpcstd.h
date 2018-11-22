/****************************************************************************/
/* ファイル名：　mpcstd.h													*/
/* 機能  　　：  テーブルアドレス位置										*/
/*				 システムコールプロトタイプ 								*/
/*				 システムコールアーギュメント域テンプレート 				*/
/*				 システムコール発行マクロ									*/
/* 作成日　  ：  1993.11.24 												*/
/* 修正　　　：  ST4626		96.12.11	NVTの予備域をmemtypに変更			*/
/* ＜ソース修正者＞                  営業店システム担当(山口 KSP)			*/
/* ＜ソース正年月日及び修正ＩＤ＞    １９９８年０５月２５日			ST5160	*/
/*   システムコールエラーのハンドリングを一部変更する（エラー値追加）		*/
/* ＜ソース修正者＞                  本田信幸								*/
/* ＜ソース正年月日及び修正ＩＤ＞    ２００２年１２月１２日			M01		*/
/*	Linux化による修正														*/
/*		osxxxx2シリーズの追加												*/
/*		動作パラメータ構造体変更											*/
/****************************************************************************/
#include <mcs_0000.h>					/* スケジューラ共通ヘッダファイル	*/

/**************************************/
/* インタフェースコード定義 		  */
/**************************************/
#define IFLANNG   0x60000010			/* ＬＡＮ回線障害通知				*/
#define IFLANOK   0x60000011			/* ＬＡＮ回線障害回復通知			*/
#define IFKEISW   0x10000e00			/* 系切り替え通知					*/

/**************************************/
/* コンテキストキューターミナル 	  */
/**************************************/
typedef struct{
	long	xqt[2]; 					/* ｺﾝﾃｷｽﾄｷｭｰの先頭ｱﾄﾞﾚｽ／最終ｱﾄﾞﾚｽ	*/
} XQT;

/**************************************/
/* コンテキストキュー情報			  */
/**************************************/
typedef struct{
	long	xqlink[2];				   /* ｺﾝﾃｷｽﾄｷｭｰﾘﾝｸの前方向／後方向ｱﾄﾞﾚｽ*/
} XQLINK;

/**************************************/
/* ＮＶＴプログラム固有部テンプレート */
/**************************************/
typedef struct {
	long				chead[3];		/* スケジューラ管理域				*/
	char				flags;			/* 制御フラグ						*/
	char				memtyp;			/* メモリ種別 						*/
										/* ST4626 予備をメモリ種別に変更 	*/
	unsigned short		rtytimnc;		/* リトライタイマ					*/
	long				fildes; 		/* ファイルディスクリプタ			*/
	unsigned short		linenum;		/* 回線数							*/
	unsigned short		pathnum;		/* 論理パス数						*/
	unsigned short		connnum;		/* コネクション数					*/
	char				reserve2[2];	/* 予備 							*/
	long				msgcntam;		/* 刈取メッセージ数 				*/
	long				lmtp;			/* 回線コンテキスト先頭アドレス 	*/
	long				pmtp;			/* パスコンテキスト先頭アドレス 	*/
	long				cmtp;			/* ｺﾈｸｼｮﾝｺﾝﾃｷｽﾄ先頭アドレス 		*/
	XQT 				ctxtqt; 		/* コネクションコンテキストＱＴ 	*/
} MPCNVTP;

#define FLGNSYSF	0x01				/* システム構成情報 				*/
#define FLGNKEIK	0x02				/* 稼働系構成情報					*/
#define FLGNRSTA	0x04				/* 稼働系構成情報					*/

/**************************************/
/* 各デフォルト値					  */
/**************************************/
#define _DF_MAXCONN 1					/* コネクション設定最大数デフォルト */
#define _DF_MAXTRED 1					/* 同時送信要求最大数デフォルト 	*/
#define _DF_MAXCEDT 1					/* 同時送信要求最大数デフォルト 	*/
#define _DF_TMNETCT 3					/* ＮＥＴＣＴＬリトライタイマデフォ */
										/* ルト 							*/
#define _DF_TMDETCH 3					/* ＤＥＴＡＣＨリトライタイマデフォ */
										/* ルト 							*/
#define _DF_MAXRBUF 32764				/* 受信バッファサイズ上限値 		*/
#define _DF_MAXSBUF 32764				/* 送信バッファサイズ上限値 		*/
#define _DF_MINRBUF  4096				/* 受信バッファサイズ下限値 		*/
#define _DF_MINSBUF  4096				/* 送信バッファサイズ下限値 		*/
/**************************************/
/* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄ上の各種ﾃｰﾌﾞﾙの位置 */
/**************************************/
#define _TPLM_NO	2					/* ＴＰＬＭアドレスの位置			*/
#define _TFAH_NO	3					/* ＴＦＡＨアドレスの位置			*/
#define _TTLI_NO	4					/* ＴＴＬＩアドレスの位置			*/
#define _TTSI_NO	5					/* ＴＴＳＩアドレスの位置			*/
#define _TLPH_NO	6					/* ＴＬＰＨアドレスの位置			*/

/**************************************/
/* リクエスト値 					  */
/**************************************/
#define Q_ASYNC		0x006cf000			/* 非同期通知要求					*/
#define Q_ATTACH	0x006cf100			/* ＡＴＴＡＣＨ要求 				*/
#define Q_DETACH	0x006c7101			/* ＤＥＴＡＣＨ要求 				*/
#define Q_BIND 		0x006c7102			/* ＢＩＮＤ要求 					*/
#define Q_LISTEN	0x006c7103			/* ＬＩＳＴＥＮ要求 				*/
#define Q_CONNCT 	0x006c7104			/* ＣＯＮＮＥＣＴ要求				*/
#define Q_DISCON	0x006c7106			/* ＤＩＳＣＯＮＮＥＣＴ要求 		*/
#define Q_ACCEPT	0x006cf105			/* ＡＣＣＥＰＴ要求 				*/
#define Q_ABORT		0x006c710a			/* ＡＢＯＲＴ要求					*/
#define Q_RCVOOB	0x006cf10d			/* ＲＣＶＯＯＢ要求 				*/
#define Q_SNDOOB	0x006c710e			/* ＳＥＮＤＯＯＢ要求				*/
#define Q_SETOPT	0x006c7130			/* ＳＥＴＯＰＴ要求 				*/
#define Q_NETCTL	0x006cf150			/* ＮＥＴＣＴＬ要求 				*/

/**************************************/
/* 非同期通知ｆｕｎｃ値 			  */
/**************************************/
#define _ASYN_FUNC	0x2L				/* 非同期通知要求ｆｕｎｃ値 		*/

/**************************************/
/* プロトコル識別子 				  */
/**************************************/
#define IPP_TCP 	0x0006				/* プロトコル識別子：ＴＣＰ 		*/

/**************************************/
/* アドレスファミリィ識別子 		  */
/**************************************/
#define AF_INET    0x0002			   /* アドレスファミリィ識別子		   */

/**************************************/
/* 最大接続待ち保留数				  */
/**************************************/
#define SOMAXCONN  5				   /* 最大接続待ち保留数：ＬＩＳＴＥＮ */

/**************************************/
/* ＮＥＴＣＴＬパラメータ			  */
/**************************************/
#define NTSIFADDR		0x0000000c	   /* ローカルアドレス登録			   	*/
#define NTSIFNETMASK	0x00000016	   /* サブネットマスク登録			   	*/
#define NTSIFNETFLAG	0x00000010	   /* ネットワークフラグ登録		   	*/

#define NETFLAGON		0x00000001	   /* ネットワークフラグＯＮ 			*/
/**************************************/
/* システムコールプロトタイプ		  */
/**************************************/
extern long 	osconn();
extern long 	osgetios();
extern long 	osgfinf();
extern long 	osdconn();
extern long 	osopen();
extern long 	osclose();
extern long 	osireadd();
extern long 	osiwritd();
extern long 	osiioctl();
extern long 	osioctl();
extern long 	ossenmsp();
extern long 	ossnsms();				/* ﾒｯｾｰｼﾞ受信状態の取得				*/
extern long 	osconn2();				/*								M01	*/
extern long 	osopen2();				/*								M01	*/
extern long 	osclose2();				/*								M01	*/
extern long 	osireadd2();			/*								M01	*/
extern long 	osiwritd2();			/*								M01	*/
extern long 	osiioctl2();			/*								M01	*/
extern long 	osdconn2();				/*								M01	*/

/**************************************/
/* 各種システムコールアーギュメント   */
/**************************************/
typedef struct {						/* NETCTL							*/
	long	rdev;						/* 装置識別子						*/
	long	reserve0[3];				/* リザーブ 						*/
	long	netflags;					/* ネットワークフラク゛				*/
	long	reserve1[3];				/* リザーブ 						*/
}	ARG_NETFLAGS;
typedef struct {						/* NETCTL							*/
	long	rdev;						/* 装置識別子						*/
	long	reserve0[3];				/* リザーブ 						*/
	short	a_family;					/* オプション種別					*/
	short	reserve1;					/* リザーブ 						*/
	long	address;					/* ローカルインターネットアドレスお */
										/* よびサブネットマスク 			*/
	long	reserve2[2];				/* リザーブ 						*/
}	ARG_ADDRESS;
typedef struct {						/* ATTACH/DETACH/DISCONNECT/ABORT	*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
}	ARG_TYP0;
typedef struct {						/* BIND 							*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	a_family;					/* アドレスファミリー識別子 		*/
	short	l_port; 					/* ローカルポート番号				*/
	long	l_ipaddr;					/* ローカルアドレス 				*/
	long	reserve0[2];				/* リザーブ 						*/
}	ARG_TYP1;
typedef struct {						/* LISTEN							*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	reserve0;					/* リザーブ 						*/
	short	backlog;					/* 最大接続待ち保留数				*/
}	ARG_LIST;
typedef struct {						/* CONNECT/ACCEPT					*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	a_family;					/* アドレスファミリー識別子 		*/
	short	r_port; 					/* リモートポート番号				*/
	long	r_ipaddr;					/* リモートアドレス 				*/
	long	reserve0[2];				/* リザーブ 						*/
}	ARG_CONN;
typedef struct {						/* RCVOOB							*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	optoob; 					/* 緊急データオプション 			*/
	char	oob_data;					/* 緊急データ						*/
	char	reserve0;					/* リザーブ 						*/
}	ARG_ROOB;
typedef struct {						/* SENDOOB							*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	oob_size;					/* 緊急データサイズ 				*/
	short	reserve0;					/* リザーブ 						*/
}	ARG_SOOB;
typedef struct {						/* SETOPT							*/
	short	proto_id;					/* プロトコル識別子 				*/
	short	sesno;						/* ローカルセッション番号			*/
	short	option; 					/* オプション種別					*/
	short	optset; 					/* 処理種別 						*/
	long	optval; 					/* データ							*/
}	ARG_SOPT;
typedef struct {						/* NETCTL							*/
	long	cmd;						/* コマンド 						*/
	ARG_ADDRESS  addr;					/* データ域 						*/
}	ARG_NETC;
typedef struct {						/* NETCTL							*/
	long	cmd;						/* コマンド 						*/
	ARG_NETFLAGS flag;					/* データ域 						*/
}	ARG_NETF;
typedef struct {						/* NETCTL							*/
	short	a_family;					/* アドレスファミリー識別子 		*/
	short	r_port; 					/* リモートポート番号				*/
	long	r_ipaddr;					/* リモートインタネットアドレス 	*/
	char	reserve0[8];				/* リザーブ 						*/
}	ARG_RW;
typedef struct {						/* 非同期通知要求					*/
	long	func;						/* ｆｕｎｃ 						*/
	short	sesno;						/* ローカルセッション番号			*/
	short	detail; 					/* 詳細情報 						*/
}	ARG_ASYN;

typedef struct {						/* 動作パラメータ					*/
	short	option; 					/* オプション					M01	*/
	short	sesno;						/* ローカルセッション番号		M01	*/
}	ARG_PRM;

/**************************************/
/* 非同期通知要求の詳細情報ビット定義 */
/**************************************/
#define AS_SCONN	0x0001				/* コネクションの設定を検出した 	*/
#define AS_FCONN	0x0002				/* コネクションの解放を検出した 	*/
#define AS_RDATA	0x0004				/* 通常データを受信した 			*/
#define AS_SCFRM	0x0008				/* 送信したﾃﾞｰﾀの送達確認が得られた */
#define AS_RVOOB	0x0010				/* 緊急データを受信した 			*/
#define AS_SDOWN	0x0020				/* 受信側のｼｬｯﾄﾀﾞｳﾝを検出した		*/
/**************************************/
/* ＳＥＴＯＰＴのオプション種別 	  */
/**************************************/
#define SO_KEEPALIVE	0x0008			/* コネクション保存ビット			*/
#define SO_DONTROUTE	0x0010			/* 経路選択不可ビット				*/
#define SO_LINGER		0x0080			/* 保持中データ送信ビット			*/
#define SO_OOBINLINE	0x0100			/* 緊急データ保持ビット 			*/
#define SO_SNDBUF		0x0200			/* 送信バッファサイズ変更ビット 	*/
#define SO_RCVBUF		0x0400			/* 受信バッファサイズ変更ビット 	*/
/**************************************/
/* ＳＥＴＯＰＴの処理種別			  */
/**************************************/
#define SO_SETOFF		0x0000			/* 解除 							*/
#define SO_SETON		0x0001			/* 設定（叉は変更） 				*/
/**************************************/
/* ＳＥＴＯＰＴのバッファサイズ 	  */
/**************************************/
#define SO_SBUFSIZE 	4096			/* 送信バッファサイズデフォルト値	*/
#define SO_RBUFSIZE 	4096			/* 受信バッファサイズデフォルト値	*/
/**************************************/
/* システムコールのリザルトコード	  */
/**************************************/
#define R_NORMAL	0x00000000			/* 正常終了 						*/
#define R_LERROR	0xecb00016			/* ﾛﾝﾘｱﾔﾏﾘ */
#define R_WLDBLK	0xecb00140			/* まだコネクションが着信していない */
#define R_ICMP3_4	0xecb00145			/* ICMP type=3 code=4を受信	  ST5160*/
#define R_ADDNOT	0xecb0014e			/* アドレスの使用が不可能			*/
#define R_NETDWN	0xecb0014f			/* ネットワークがダウン 			*/
#define R_NUNRCH	0xecb00150			/* ネットワークへの到達不可能		*/
#define R_CABOTD	0xecb00152			/* コネクションがアボートした		*/
#define R_CRESET	0xecb00153			/* コネクションがリセットされた 	*/
#define R_NOBUFS	0xecb00154			/* ﾊﾞｯﾌｧ不足／ﾌﾟﾛｾｽid管理用ﾊﾞｯﾌｧ不足*/
#define R_NOTCON	0xecb00156			/* コネクション未設定				*/
#define R_SHUTDN	0xecb00157			/* 既にｺﾈｸｼｮﾝはｼｬｯﾄﾀﾞｳﾝ済み 		*/
#define R_TIMOUT	0xecb00159			/* コネクションのタイムアウト発生	*/
#define R_CREFUS	0xecb0015a			/* コネクション設定が拒否された 	*/
#define R_ICMP3_2	0xecb0015a			/* ICMP type=3 code=2を受信	  ST5160*/
#define R_HUNRCH	0xecb0015e			/* ホストへの到達不可能 			*/
#define R_CFFCAN	0xecf00001			/* 切断によりキャンセル 			*/
#define R_IOERR 	0xecb00005			/* Ｉ／Ｏエラー 					*/
#define R_LSNFRE	0xecf00006			/* 切断中の為、ﾛｰｶﾙｾｯｼｮﾝは解放不可	*/
#define R_EMAJOR	0xecf20000			/* ｍａｊｏｒ番号不正				*/
#define R_EMINOR	0xecf20001			/* ｍｉｎｏｒ番号不正				*/
#define R_AINUSE	0xecb0014d			/* アドレスは既に使用されている 	*/
/**************************************/
/* データ初期値 					  */
/**************************************/
#define NOMSG	0L						/* メッセージポインタ変数初期値 	*/
#define NOIRB	0L						/* ＩＲＢポインタ変数初期値 		*/
#define NOTMID	0L						/* タイマＩＤ変数初期値 			*/
#define NORMAL	0L						/* 処理結果正常 					*/
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  TBLENTRY													*/
/*																			*/
/* ＜機能概要＞  指定した個別部エントリ番号のＳＧテーブル個別部の先頭アドレ */
/*				 スを算出する												*/
/* ＜仮引数＞																*/
/*	   P1	   　外部参照テーブルアドレスリストの配列番号					*/
/*	   P2	   　個別部エントリ番号 										*/
/****************************************************************************/
#define TBLENTRY(P1, P2)				/* ＳＧテーブル個別部エントリ算出	*/\
	( (long)tblp[(P1)] + sizeof(TCOMPAT) + tblp[(P1)]->tcomsbps 			  \
		+ (tblp[(P1)]->tcomprsl * (P2 - 1)) )								  \
										/*	 ＳＧテーブル先頭アドレス		*/\
										/* ＋共通部サイズ					*/\
										/* ＋サブ共通部サイズ				*/\
										/* ＋個別部サイズ × 個別部ｴﾝﾄﾘ番号 */\
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  BITCHECK													*/
/*																			*/
/* ＜機能概要＞  ビットが設定されているかチェックする						*/
/*																			*/
/* ＜仮引数＞																*/
/*	   FLAGS   　ビットをチェックするデータ 								*/
/*	   BIT	   　チェックするビット 										*/
/****************************************************************************/
#define BITCHECK(FLAGS, BIT)			/* ビット判定						*/\
	(FLAGS & BIT)
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  BITON													 	*/
/*																			*/
/* ＜機能概要＞  ビットを設定する											*/
/*																			*/
/* ＜仮引数＞																*/
/*	   FLAGS   　ビットを設定するデータ 									*/
/*	   BIT	   　設定するビット 											*/
/****************************************************************************/
#define BITON(FLAGS, NBIT)			 	/* ビット設定						 */\
	FLAGS=(FLAGS | NBIT)
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  BITOFF 												  	*/
/*																			*/
/* ＜機能概要＞  ビットを解除する											*/
/*																			*/
/* ＜仮引数＞																*/
/*	   FLAGS   　ビットを解除するデータ 									*/
/*	   BIT	   　解除するビット 											*/
/****************************************************************************/
#define BITOFF(FLAGS, NBIT) 		  	/* ビット解除 					  	*/\
	FLAGS=(FLAGS & (~NBIT))

#include <mc.h>							/* ｍｃ．ｈ							*/
#include <mc_logx.h>					/* Pﾄﾚｰｽ情報取得ﾍｯﾀﾞﾌｧｲﾙ使用宣言	*/
#ifndef DOS								/* MS-DOS(FATｼｽﾃﾑ以外)でのｺﾝﾊﾟｲﾙの	*/
										/* 以外								*/
#include <mc_logmac.h>					/* ｼｽﾃﾑｺｰﾙﾏｸﾛ宣言ﾍｯﾀﾞﾌｧｲﾙ使用宣言	*/
#else									/* MS-DOS上でのｺﾝﾊﾟｲﾙの場合(FAT対応)*/
#include <mc_logma.h>					/* ｼｽﾃﾑｺｰﾙﾏｸﾛ宣言ﾍｯﾀﾞﾌｧｲﾙ使用宣言	*/
#endif
#include <mpcirb.h> 					/* ＩＲＢ定義ファイル				*/
#include <mpcmac.h> 					/* マクロ定義ファイル				*/
#include <mpcdebug.h> 					/* デバック用マクロ定義				*/
