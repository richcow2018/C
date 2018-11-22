/*********************************************************************/
/*  OCP PCB ﾉ ｺｳｿﾞｳﾀｲ                                                */
/*＜ソース修正者名＞				ＴＤＣ　小島　明				 */
/*＜ソース修正年月日及び修正ＩＤ＞	１９９３年１２月１３日 TD-10 TD-12*/
/*-------------------------------------------------------------------*/
/*＜ソース修正者名＞				ＴＤＣ　杉岡  克也				 */
/*＜ソース修正年月日及び修正ＩＤ＞	１９９５年　３月  １日 CT0890    */
/*														  (ST2489)   */
/*********************************************************************/
struct  mopscpcb {
    TCOMPAT  *mopssst;                  /* SST ｾﾝﾄｳ ｱﾄﾞﾚｽ            */
    TSSTPSZ  *mopssstp;                 /* SST ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ     */
    TCOMPAT  *mopscst;                  /* CST ｾﾝﾄｳ ｱﾄﾞﾚｽ            */
    TCSTPSZ  *mopscstp;                 /* CST ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ     */
    TCOMPAT  *mopsbpt;                  /* BPT ｾﾝﾄｳ ｱﾄﾞﾚｽ            */
    TBPTPSZ  *mopsbptp;                 /* BPT ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ     */
    TCOMPAT  *mopssrt;                  /* SRT ｾﾝﾄｳ ｱﾄﾞﾚｽ            */
    TSRTPSZ  *mopssrtp;                 /* SRT ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ     */
    TPCTSUB  *mopspcts;                 /* PCT ｻﾌﾞ ｷｮｳﾂｳﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ*/
    TPCTPSZ  *mopspctp;                 /* PCT ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ     */
    long  mopssrto;                     /* SRT ｵﾌｾｯﾄ ﾁ               */
    long  mopssern;                     /* ｺﾏﾝﾄﾞ ﾂｳﾊﾞﾝ               */
    long  mopsrsv[4];                   /* ﾖﾋﾞ                       */
	char	*mopsicp;					/* ＩＣＰ用コマンド管理	TD12 */
										/*	ブロックアドレス	TD00 */
	/* 2003.01.08 障害番号 : KL0004 */
	/* TABPテーブル構造体の削除	    */
										/*	先頭アドレス		TD00 */
	long	*mopsatad;					/* アタッチ情報管理アドレス TD10 */
    TBPTSUB *mopsbpts;                  /* BPT ｻﾌﾞ ｷｮｳﾂｳﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ TD10 */
	/* 2003.01.08 障害番号 : KL0004 */
	/* TABPテーブル構造体の削除	    */
    TCOMPAT	*mopsntc;					/* ＮＴＣ共通部先頭ｱﾄﾞﾚｽTD12 */
    TCOMPAT	*mopscmt;					/* ＣＭＴ共通部先頭ｱﾄﾞﾚｽTD12 */
	long	mopsmcsfd[7];				/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ用ｷﾔﾗｸﾀ特殊ﾌｱｲﾙ  */
										/* 用fd(RCVﾎﾞﾘﾕ-ﾑ)    CT0890 */
	short	mopsvolno;					/* 対象装置TVMT/TVBT個別部番号 CT1037 */
	unsigned char mopsttype;			/* テーブル種別フラグ CT1037 */
    char	mopsrsv2;					/* 予備					TD10 */
};
typedef  struct  mopscpcb  MOPSCPCB;
