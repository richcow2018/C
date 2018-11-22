/****************************************************************************/
/*	TMRT 個別部の構造体														*/
/****************************************************************************/
																	/* TDZZ */
struct	tmrtpsz	{
	short	tmrtvmtm;			/* VMT ｴﾝﾄﾘ番号（正）						*/
	short	tmrtvmts;			/* VMT ｴﾝﾄﾘ番号（副）						*/
	char	tmrtspnm[16];		/* ﾐﾗｰﾎﾞﾘｭｰﾑ用特殊ﾌｧｲﾙ名					*/
	char	tmrtmntn[16];		/* ﾏｳﾝﾄ先ﾌﾞﾛｯｸ特殊ﾌｧｲﾙ名					*/
	long	tmrtsoch[3];		/* 装置ID									*/
	char	tmrtcsnm[16];		/* ﾌｧｲﾙ有りｷｬﾗｸﾀ特殊ﾌｧｲﾙ名					*/
	char	tmrtcsn2[16];		/* ﾌｧｲﾙ無しｷｬﾗｸﾀ特殊ﾌｧｲﾙ名					*/
};
typedef	struct	tmrtpsz	TMRTPSZ;
