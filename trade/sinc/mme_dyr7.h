/****************************************************************************/
/* 差分データ抽出															*/
/*																			*/
/* 作成: 94/09/16															*/
/* 更新:																	*/
/*		95.06.29 K.Kubota SSCY0076: ﾉｰﾄﾞ間通信ﾊﾟｽ差分情報返却				*/
/*	95.09.08 K.Kubota ST3242: New funcs mm_di90[012]()						*/
/*	96.11.06 K.Kubota ST4592: New funcs mm_di94[012]()						*/
/*										mm_di3[23]3(), mm_di3[48]2()		*/
/*	97.02.09 K.Kubota ST4651: delete funcs mm_di94[01]()					*/
/*	03.03.06 サプライ：岩下 MD001: Linux移植に伴う修正						*/
/*							最大レコード数変更								*/
/****************************************************************************/
#include "mcmia.h"
#include "mm_dyrec.h"
#include "mme_dyr9.h"

/*#define	MAXRECORD	  10L										MD001	*/
#define	MAXRECORD	  6L					/*						MD001	*/
#define	PROCDELETE	  0x01
#define	PROCUPDATE	  0x02
#define	PROCINSERT	  0x03

/**-------------------------------------------------------------------------*/
/*	   差分データ抽出　構造体定義											*/
/**-------------------------------------------------------------------------*/

/**--------------------------------------*/
/*	   情報ﾃｰﾌﾞﾙ	  　　　　　　　	 */
/**--------------------------------------*/
typedef	struct {
	PPOOLBUF			regu_ptr[MAXRECORD]; /* 正規化ﾃﾞｰﾀﾌﾟｰﾙﾊﾞｯﾌｧ域		*/
	PPOOLBUF			rvrs_ptr[MAXRECORD]; /* 逆正規化ﾃﾞｰﾀﾌﾟｰﾙﾊﾞｯﾌｧ域		*/
	PPOOLBUF			ddif_ptr[MAXRECORD]; /* 撤去用差分ﾃﾞｰﾀﾌﾟｰﾙﾊﾞｯﾌｧ域	*/
	PPOOLBUF			adif_ptr[MAXRECORD]; /* 増設用差分ﾃﾞｰﾀﾌﾟｰﾙﾊﾞｯﾌｧ域	*/
	long				ddifNum;			/* 撤去用差分ﾃﾞｰﾀﾚｺｰﾄﾞ数		*/
	long				adifNum;			/* 増設用差分ﾃﾞｰﾀﾚｺｰﾄﾞ数		*/
	long				reguNum[MAXRECORD];	/* 正規化ﾃﾞｰﾀｷｰﾚｺｰﾄﾞ数			*/
	char				**(ReguIndx[MAXRECORD]); /* 正規化ﾃﾞｰﾀｷｰﾌﾟｰﾙ域		*/
	long				rvrsNum[MAXRECORD];	/* 逆正規化ﾃﾞｰﾀｷｰﾚｺｰﾄﾞ数		*/
	char				**(RvrsIndx[MAXRECORD]); /* 逆正規化ﾃﾞｰﾀｷｰﾌﾟｰﾙ域	*/
}						ADDRTBL;
typedef	ADDRTBL			*PADDRTBL;

/**-------------------------------------------------------------------------*/
/*	   差分データ抽出　関数定義											  */
/**-------------------------------------------------------------------------*/
extern long				mm_di100();
extern long				mm_di110();
extern void				mm_di200();
extern long				mm_di210();
extern long				mm_di220();
extern long				mm_di230();
extern long				mm_di240();
extern long				mm_di250();
extern long				mm_di260();
extern long				mm_di270();
extern long				mm_di280();
extern long				mm_di290();
extern long				mm_di2a0();
extern long				mm_di300();
extern long				mm_di301();
extern long				mm_di310();
extern void				mm_di311();
extern long				mm_di320();
extern void				mm_di321();
extern long				mm_di323(); /* ###ST4592							*/
extern long				mm_di330();
extern void				mm_di331();
extern long				mm_di333(); /* ###ST4592							*/
extern long				mm_di340();
extern void				mm_di341();
extern long				mm_di342(); /* ###ST4592							*/
extern long				mm_di350();
extern void				mm_di351();
extern long				mm_di360();
extern void				mm_di361();
extern long				mm_di370();
extern void				mm_di371();
extern long				mm_di380();
extern void				mm_di381();
extern long				mm_di382(); /* ###ST4592							*/
extern long				mm_di390();
extern void				mm_di391();
extern long				mm_di3a0();
extern void				mm_di3a1();
extern long				mm_di400();
extern long				mm_di401();
extern long				mm_di410();		/* ###SSCY0076						*/
extern long				mm_di500();
extern long				mm_di600();
extern void				mm_di900();		/* NewFace ###ST3242				*/
extern long				mm_di901();		/* NewFace ###ST3242				*/
extern short			mm_di902();		/* NewFace ###ST3242				*/
#ifdef DEL_ST4651
extern void				mm_di940();		/* NewFace ###ST4592				*/
extern long				mm_di941();		/* NewFace ###ST4592				*/
#endif
extern long				mm_di942();		/* NewFace ###ST4592				*/
extern long				mm_diff();
