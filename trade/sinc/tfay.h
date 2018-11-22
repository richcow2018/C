
/********************************************************************/
/*																	*/
/*					tfay.h											*/
/*																	*/
/*			TFAY ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ	94.09.16	 作成者	 久保田			*/
/*																	*/
/********************************************************************/

struct mdfayko
{
	unsigned char	tfaykbst;		/* ステータス */
	char			tfayyob0[3];	/* 予備	*/
	short			tfayllno;		/* 論理回線番号	*/
	short			tfayfacn;		/* ＴＦＡＣのエントリ番号 */
	unsigned char	tfaydadl;		/* 接続先のＤＴＥアドレス桁数 */
	unsigned char	tfaydadr[8];	/* 接続先のＤＴＥアドレス */
	unsigned char	tfaycpks;		/* 発呼者送信パケットサイズ	*/
	unsigned char	tfayrpks;		/* 着呼者送信パケットサイズ	*/
	unsigned char	tfaycwsz;		/* 発呼者ウインドウサイズ */
	unsigned char	tfayrwsz;		/* 着呼者ウインドウサイズ */
	unsigned char	tfayfslt;		/* ファストセレクト要求	*/
	unsigned char	tfaypchk;		/* 着信課金	*/
	unsigned char	tfayctpc;		/* 発（着）呼者スループットクラス */
	unsigned char	tfaycxal;		/* 発アドレス拡張のアドレス桁数	*/
	unsigned char	tfaycxad[20];	/* 発アドレス拡張のアドレス値 */
	unsigned char	tfayrxal;		/* 着アドレス拡張のアドレス桁数	*/
	unsigned char	tfayrxad[20];	/* 着アドレス拡張のアドレス値 */
	unsigned char	tfayclas;		/* ＧＷでの中継先プロトコル	*/
	unsigned char	tfaygwln;		/* ＧＷ上での収容端末回線番号 */
	long			tfaydsta;		/* 中継先端末のアドレス情報	*/
	unsigned long	tfaysopt;		/* 適用システムオプション */
	unsigned char	tfayrspt;		/* レスポンス待ちタイマ	*/
	char			tfayyob1[3];	/* 予備	*/
	long			tfaymaxd;		/* 最大分割データ長	*/
	char			tfayyob2[8];	/* 予備	*/
};
typedef	struct mdfayko TFAYPSZ;			/* FIP ﾖｳ					*/
