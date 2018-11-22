/********************************************************************/
/*                                                                  */
/*                  tfal.h                                          */
/*                                                                  */
/*          TFAL ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ   94.12.20     作成者  西山  伸       */
/*                       変更	03.01.17	 変更者	 佐治  秀保	    */
/*																	*/
/********************************************************************/

struct mdfalko
{
	unsigned	char	tfalkbst;		/* ステータス */
				char	tfalyob0[3];	/* 予備 */
				short	tfalllno;		/* 論理回線番号 */
				short	tfalfacn;		/* ＴＦＡＣのエントリ番号 */
	unsigned	long	tfalloca;		/* 相手の端末ローカルアドレス */
	unsigned	char	tfalrspt;		/* レスポンス待ちタイマ */
				char	tfalyob1;		/* 予備 */
				short	tfallicn;		/* ＴＬＩＣエントリ番号 */
				long	tfalmaxd;		/* 最大分割データ長 */
				char	tfalyob2[4];	/* 予備 */
};
typedef struct mdfalko TFALPSZ;			/* FIP ﾖｳ                   */
