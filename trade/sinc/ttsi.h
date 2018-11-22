/****************************************************************************/
/*																			*/
/*		ＴＴＳＩテーブルフォーマット  ttsi.h				  (93.11.22)	*/
/*																			*/
/****************************************************************************/

struct	ttsipsz {						/* 個別部							*/
	short  			ttsilpon;			/* ローカルポート番号				*/
	unsigned short  ttsimxcn;			/* コネクション設定最大数			*/
	char			ttsiyob0[8];		/* 予備０							*/
};
typedef struct	ttsipsz MDTSCKO;		/* ＤＣＰ用 						*/
typedef struct	ttsipsz TTSIPSZ;		/* ＦＩＰ用 						*/
