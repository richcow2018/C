/************************************************************************/
/*	FTOS情報管理領域		FIMA (FTOS Information Management Area)		*/
/*																		*/
/*	作成者		佐治 秀保												*/
/*				2003.04.09												*/
/************************************************************************/

/************************************************************************/
/*	ＦＴＯＳ情報管理領域												*/
/************************************************************************/
typedef struct mefima MEFIMA;
struct mefima {
	MEFIMA			*qlink[2];			/* Queue Link					*/
	unsigned short	lpath_no;			/* 論理ﾊﾟｽ番号格納域			*/
	char			dummy[2];			/* 予備							*/
	long			ftos_id;			/* ﾌｧｲﾙ転送ｺﾏﾝﾄﾞﾌﾟﾛｾｽ識別子格納域*/
	char			ftosname[8];		/* ﾌｧｲﾙ転送ｺﾏﾝﾄﾞﾌﾟﾛｾｽ識別名格納域*/
};

/************************************************************************/
/*	ＦＴＯＳ用キューターミナル											*/
/************************************************************************/
typedef struct ft_fima {				/* キューターミナル				*/
	char			*tbl_id[4];			/* テーブルＩＤ					*/
	MEFIMA			*qlink[2];			/* Queue Link					*/
	long			ftqueno;			/* FTOS情報域キュー数			*/
	unsigned char	serialno;			/* プロセス識別名のための通番	*/
	char			dummy[3];			/* 予備							*/
} MEFTQUE;								/*								*/

/************************************************************************/
/*	ＦＩＭＡ操作マクロ１												*/
/*	処理：キューターミナルを初期化する									*/
/*	引数： p1 = キューターミナルポインタ								*/
/************************************************************************/
#define MEF_QINIT(p1) {((MEFIMA *)p1)->qlink[0] = (MEFIMA *)p1 ; \
					   ((MEFIMA *)p1)->qlink[1] = (MEFIMA *)p1 ;}

/************************************************************************/
/*	ＦＩＭＡ操作マクロ２												*/
/*	処理：ＦＩＭＡをキューターミナルの最後尾にエンキューする			*/
/*	引数： p1 = キューターミナルポインタ								*/
/*		   p2 = ＦＩＭＡポインタ										*/
/************************************************************************/
#define MEF_TENQ(p1,p2) {((MEFIMA *)p2) -> qlink[0] = (MEFIMA *)p1;\
						 ((MEFIMA *)p2) -> qlink[1] = \
											((MEFIMA *)p1) -> qlink[1];\
						 ((MEFIMA *)p2) -> qlink[1] -> qlink[0] = \
														 (MEFIMA *)p2;\
						 ((MEFIMA *)p1) -> qlink[1] = (MEFIMA *)p2;}

/************************************************************************/
/*	ＦＩＭＡ操作マクロ３												*/
/*	処理：任意のＦＩＭＡをデキューする									*/
/*	引数： p1 = ＦＩＭＡポインタ										*/
/************************************************************************/
#define MEF_ADEQ(p1) {((MEFIMA *)p1) -> qlink[0] -> qlink[1] \
										= ((MEFIMA *)p1) -> qlink[1];\
					  ((MEFIMA *)p1) -> qlink[1] -> qlink[0] \
										 = ((MEFIMA *)p1) -> qlink[0];\
					  ((MEFIMA *)p1) -> qlink[0] = (MEFIMA *)0;\
					  ((MEFIMA *)p1) -> qlink[1] = (MEFIMA *)0;}
