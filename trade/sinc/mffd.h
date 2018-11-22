/****************************************************************************/
/*		ｍｆｆｄ．ｈ　インクルードファイル									*/
/*							'95/03/16			ST1737						*/
/****************************************************************************/

/****************************************/
/*	MFECB(特殊ﾌｧｲﾙ管理ﾌﾞﾛｯｸ)構造体		*/
/****************************************/

struct mfecb {
	short	mfebid;						/*	特殊ファイル管理ブロック識別子	*/
	char	mfemode;					/*	オープンモード					*/
	char	mfestat;					/*	ステータス						*/
	long	mfefdf;						/*	ファイル記述子１				*/
	long	mfefds;						/*	ファイル記述子２				*/
	long	mfefdt;						/*	ファイル記述子３				*/
	long	mfeboe;						/*	ＢＯＥ							*/
	long	mfeeod;						/*	ＥＯＤ							*/
	long	mfeeoe;						/*	ＥＯＥ							*/
	long	mfeted;						/*	仮更新ＥＯＤ情報				*/
	long	mfesta;						/*	読み込み・書き込み開始位置		*/
	long	mfelen;						/*	読み込み・書き込み長（有効）	*/
	long	mfefcb;						/*	ファイル情報位置１				*/
	long	mfefcs;						/*	ファイル情報位置２				*/
	short	mfesec;						/*	レコード長（セクタ長）			*/
	short	mfeblc;						/*	ブロック長						*/
	short	mfesnu;						/*	該当ファイル１トラック内セクタ数*/
	char	mfeefm;						/*	交換ファイル標識				*/
	char	mfeden;						/*	記録密度						*/
};
typedef struct mfecb MFECB; 


/****************************************/
/*	IBM標準形式FD・索引ｼﾘﾝﾀﾞ構造体		*/
/****************************************/

struct fdindx {
	char	fddummy1[75];				/*	ｄｕｍｍｙ１					*/
	char	fdrecd;						/*	物理レコード長					*/
	char	fddummy2[52];				/*	ｄｕｍｍｙ２					*/
};
typedef struct fdindx FDINDX;


/****************************************/
/*	IBM標準形式FD・ﾃﾞｰﾀｾｯﾄﾗﾍﾞﾙ構造体	*/
/****************************************/

struct fdlabl {
	char	fddummy1[5];				/*	ｄｕｍｍｙ１					*/
	char	fddaid[17];					/*	データセット識別名				*/
	char	fdbloc[5];					/*	ブロック長						*/
	char	fddummy2;					/*	ｄｕｍｍｙ２					*/
	char	fdboe[5];					/*	ＢＯＥ							*/
	char	fddummy3;					/*	ｄｕｍｍｙ３					*/
	char	fdeoe[5];					/*	ＥＯＥ							*/
	char	fddummy4[4];				/*	ｄｕｍｍｙ４					*/
	char	fdextyp;					/*	ファイル交換タイプ標識			*/
	char	fdmflag;					/*	複数ボリューム標識				*/
	char	fdbsnum[2];					/*	ボリューム順序番号				*/
	char	fddummy5[27];				/*	ｄｕｍｍｙ５					*/
	char	fdeod[5];					/*	ＥＯＤ							*/
	char	fddummy6[49];				/*	ｄｕｍｍｙ６					*/
};
typedef struct fdlabl FDLABL;

/****************************************/
/*	ＦＤアクセス処理用・LOGｴﾘｱ構造体	*/
/****************************************/

struct fdlog {
	char	fname[8];					/*	関数名							*/
	long	log;						/*	引き数，返却値，ｅｔｃ			*/
};
typedef struct fdlog FDLOG;

/****************************************/
/*	ＦＤアクセス関数固有・define値		*/
/****************************************/

#define  FREEF1   0x00000001			/*	特殊ファイル１					*/
#define  FREEF2   0x00000002			/*	特殊ファイル２					*/
#define  FREEF3   0x00000004			/*	特殊ファイル３					*/
#define  IBMF13   0x00000005			/*	特殊ファイル１と３				*/
#define  IBMF123  0x00000007			/*	特殊ファイル１と２と３			*/
#define  IBMF12   0x00000003			/*	特殊ファイル１と２				*/
#define  IBMF23   0x00000006			/*	特殊ファイル２と３				*/
/*	注意！　ＩＢＭＦ１２とＩＢＭＦ２３は現実には存在しない組み合わせ		*/

#define  FDFREE1  0x01					/*	特殊ファイル１					*/
#define  FDFREE2  0x02					/*	特殊ファイル２					*/
#define  FDFREE3  0x04					/*	特殊ファイル３					*/
#define  FDIBM13  0x05					/*	特殊ファイル１と３				*/
#define  FDIBM123 0x07					/*	特殊ファイル１と２と３			*/

#define  FDLONGF  128L					/*	特殊ファイル１のセクタ長		*/
#define  FDLONGS  256L					/*	特殊ファイル２のセクタ長		*/

#define  FDREAD   0x00					/*	読み込みモード					*/
#define  FDWRIT   0x01					/*	書き込みモード					*/
#define  FDUPDT   0x40					/*	更新１モード					*/
#define  FDUPDA   0x80					/*	更新２モード					*/

#define  FDNULL   0x00					/*	ＮＵＬＬ（ヌル）				*/
#define  BLANK    0x20					/*	スペース						*/
#define  MFECBID  0x4542				/*	特殊ファイル管理ブロック識別子	*/
#define  IBMFD    0x00					/*	ＩＢＭ形式ＦＤ					*/

#define  FDIZZENOTR  0x000d0002			/*	ＦＤ用unit not ready			*/
#define  FDIZZEDELS  0x000e0014			/*	ＦＤ用deleated sector			*/
#define  FDIZZEWRT   0x000d000e			/*	ＦＤ用not writabl				*/
#define  LOGNULL     0L					/*	ＬＯＧ情報取得不要				*/
#define  LOGINF      4L					/*	ＬＯＧ情報の大きさ				*/
#define  FDNOPASS   -1L					/*	オープンしない特殊ファイル		*/

/****************************************/
/*	セクタ長の定義						*/
/****************************************/

#define	FDSEC_128	128					/*　セクタ長（１２８バイト）		*/
#define	FDSEC_256	256					/*　セクタ長（２５６バイト）		*/
#define	FDSEC_512	512					/*　セクタ長（５１２バイト）		*/
#define	FDSEC_1024	1024				/*　セクタ長（１０２４バイト）		*/
