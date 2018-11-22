/*****************************************************************/
/*																 */
/*				tfab.h											 */
/*																 */
/*		  TFAB ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ	 94.09.16							 */
/*					   変更	   .  .		  変更者				 */
/*																 */
/*****************************************************************/

struct mdfadsb {
	short	tfabssen;					/* 予備						  JJ */
	short	tfabslsu;					/* 予備						  JJ */
	short	tfabbsen;					/* 予備						  JJ */
	short	tfabblsu;					/* 予備						  JJ */
	char	tfabprst;					/* 処理中種別					 */
	char	tfabikfg;					/* 一括処理フラグ				 */
	short	tfabsysc;					/* システムコールリトライ回数	 */
	long	tfabptct;					/* パスクローズ応答監視タイマ値	 */
	long	tfabkait;					/* 回線監視ﾘﾄﾗｲｵｰﾌﾟﾝﾀｲﾏ値		 */
	long	tfabrcov;					/* 回線障害回復検出タイマ値		 */
	long	tfabsyst;					/* システムコールリトライタイマ値*/
	long	tfabrlat;					/* ＲＬＡ同期タイマ値			 */
	char	tfabtdat[64];				/* 折り返し試験用データ			 */
	short	tfabsien;					/* 予備							 */
	short	tfabbien;					/*	予備						 */
	char	tfabword[4];				/* パスワード					 */
										/* ２行削除					  JJ */
	long	tfabstrt;					/*								 */
	char	tfabyob0[4];				/*	予備						 */
};
typedef	struct mdfadsb MDFABSB;			/* DCP ﾖｳ						 */
typedef	struct mdfadsb TFABSUB;			/* FIP ﾖｳ						 */

struct mdfadko {
	char	tfabkbst;					/*	ｺﾍﾞﾂﾌﾞ ｽﾃｰﾀｽ				 */
	char	tfabtvrn;					/*	ｶｲｾﾝ ｵﾘｶｴｼ ｼﾃｲ				 */
	short	tfabexen;					/*	ｷﾘｶｴｻｷ ｴﾝﾄﾘ	NO				 */
	short	tfabpuno;					/*	PU ﾊﾞﾝｺﾞｳ					 */
	short	tfabchno;					/*	ﾁｬﾈﾙ ﾊﾞﾝｺﾞｳ					 */
	char	tfabfiln[22];				/*	ﾄｸｼｭ ﾌｧｲﾙ ﾒｲ				 */
	short	tfabpcnt;					/*	カウンタ					 */
	long	tfabfdsc;					/*	ﾌｧｲﾙ ﾃﾞｨｽｸﾘﾌﾟﾀ				 */
	char	tfabsygi;					/*	ｼｮｳｶﾞｲ ｽﾃｰﾀｽ				 */
	char	tfabchst;					/*	ﾌｧｲﾙ ｽﾃｰﾀｽ					 */
	char	tfabchs2;					/*	物理チャネルステータス		 */
	char	tfabcykf;					/*	着呼状態フラグ				 */
	char	tfablpmg;					/*	回復メッセージ出力有無		 */
	char	tfabuinf;					/*	チャネル運用情報			 */
	char	tfabchcl;					/*	チャネル閉塞フラグ			 */
	char	tfabrecv;					/*								 */
	short	tfabfapn;					/*	TFAP ｾﾝﾄｳ ｴﾝﾄﾘ NO			 */
	short	tfabpthn;					/*	ﾛﾝﾘ	ﾊﾟｽ	ｽｳ					 */
	char	tfabteln[16];				/*	ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ				  JJ */
	char	tfabtlsu;					/*	ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ	ﾕｳｺｳ ｹﾀｽｳ		 */
	char	tfabptcl;					/*							  JJ */
	char	tfabyob2[2];				/*	ﾖﾋﾞ	2					  JJ */
	long	tfabmiaa;					/*	MIA	ﾀｲﾋ	ｱﾄﾞﾚｽ				 */
										/*	２行削除				  JJ */
	short	tfabrxtn;					/*							  JJ */
	char	tfabyob3[2];				/*	ﾖﾋﾞ	3					  JJ */
	char	tfabtel2[16];				/*	ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ				  JJ */
	char	tfabtls2;					/*	ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ	ﾕｳｺｳ ｹﾀｽｳ		 */
	char	tfabyob4[3];				/*	ﾖﾋﾞ	4						 */
	short	tfabhlen;					/*	TFAH ｾﾝﾄｳ ｴﾝﾄﾘ NO			 */
	short	tfabhlno;					/*	ｴﾝﾄﾘ ｽｳ						 */
	short	tfabxlen;					/*	TFAX or	TFALｾﾝﾄｳ ｴﾝﾄﾘ NO	 */
	short	tfabxlno;					/*	ｴﾝﾄﾘ ｽｳ						 */
	unsigned	char	tfabprtc;		/*							  JJ */
	unsigned	char	tfabnetw;		/*							  JJ */
	unsigned	char	tfabbulp;		/*							  JJ */
	unsigned	char	tfabclgl;		/*							  JJ */
				char	tfabclgn[34];	/*							  JJ */
	unsigned	char	tfabcapl;		/*							  JJ */
				char	tfabcapa[11];	/*							  JJ */
	unsigned	char	tfabchil;		/*							  JJ */
				char	tfabchid;		/*							  JJ */
	unsigned	char	tfabcl1l;		/*							  JJ */
				char	tfabcld1[21];	/*							  JJ */
	unsigned	char	tfabcl2l;		/*							  JJ */
				char	tfabcld2[21];	/*							  JJ */
	unsigned	char	tfabllcl;		/*							  JJ */
				char	tfabllcp[14];	/*							  JJ */
	unsigned	char	tfabhlcl;		/*							  JJ */
				char	tfabhlcp[2];	/*							  JJ */
	unsigned	char	tfabusel;		/*							  JJ */
				char	tfabuser[129];	/*							  JJ */
	unsigned	long	tfablpid;		/*	ＬＩＣＰプロセスＩＤ	  JJ */
				char	tfabcaln[2];	/*							  JJ */
				char	tfabyob5[34];	/*	予備					  JJ */
};
typedef	struct mdfadko MDFABKO;			/*	DCP	ﾖｳ						 */
typedef	struct mdfadko TFABPSZ;			/*	FIP	ﾖｳ						 */
