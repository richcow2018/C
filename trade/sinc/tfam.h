
/****************************************************************************/
/*																			*/
/* tfam.h 94.09.16 作成者 久保田											*/
/*																			*/
/****************************************************************************/

typedef	struct
{
	unsigned	char	tfamkbst;		/* ステータス						*/
				char	tfamyob0[3];	/* 予備								*/
				short	tfamllno;		/* 論理回線番号						*/
				short	tfamfacn;		/* ＴＦＡＣのエントリ番号			*/
	unsigned	long	tfamloca;		/* 相手の端末ローカルアドレス		*/
	unsigned	char	tfamrspt;		/* レスポンス待ちタイマ				*/
				char	tfamyob1[3];	/* 予備								*/
				long	tfammaxd;		/* 最大分割データ長					*/
				char	tfamyob2[4];	/* 予備								*/
}						TFAMPSZ;		/* DYREC ﾖｳ							*/

/**********************	end	of tfam.h ***************************************/
