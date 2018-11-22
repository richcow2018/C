/********************************************************************/
/*                                                                  */
/*                  tfax.h                                          */
/*                                                                  */
/*          TFAX ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ   94.12.20     作成者  西山  伸       */
/*                                                                  */
/********************************************************************/

struct mdfaxko
{
	unsigned char	tfaxkbst;      	/* ステータス */
	char			tfaxyob0[3];    /* 予備 */
	short			tfaxllno;       /* 論理回線番号 */
	short			tfaxfacn;       /* ＴＦＡＣのエントリ番号 */
	unsigned char	tfaxdadl;       /* 接続先のＤＴＥアドレス桁数 */
	unsigned char	tfaxdadr[8];    /* 接続先のＤＴＥアドレス */
	unsigned char	tfaxcpks;       /* 発呼者送信パケットサイズ */
	unsigned char	tfaxrpks;       /* 着呼者送信パケットサイズ */
	unsigned char	tfaxcwsz;       /* 発呼者ウインドウサイズ */
	unsigned char	tfaxrwsz;       /* 着呼者ウインドウサイズ */
	unsigned char	tfaxfslt;       /* ファストセレクト要求 */
	unsigned char	tfaxpchk;       /* 着信課金 */
	unsigned char	tfaxctpc;       /* 発（着）呼者スループットクラス */
	unsigned char	tfaxcxal;       /* 発アドレス拡張のアドレス桁数 */
	unsigned char	tfaxcxad[20];   /* 発アドレス拡張のアドレス値 */
	unsigned char	tfaxrxal;       /* 着アドレス拡張のアドレス桁数 */
	unsigned char	tfaxrxad[20];   /* 着アドレス拡張のアドレス値 */
	unsigned char	tfaxclas;       /* ＧＷでの中継先プロトコル */
	unsigned char	tfaxgwln;       /* ＧＷ上での収容端末回線番号 */
	long			tfaxdsta;       /* 中継先端末のアドレス情報 */
	unsigned long	tfaxsopt;       /* 適用システムオプション */
	unsigned char	tfaxrspt;       /* レスポンス待ちタイマ */
	char			tfaxyob1[3];    /* 予備 */
	long			tfaxmaxd;       /* 最大分割データ長 */
	char			tfaxyob2[8];    /* 予備 */
};
typedef struct mdfaxko TFAXPSZ;         /* FIP ﾖｳ                   */
