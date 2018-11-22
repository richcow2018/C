/*********************************************************************/
/*		FIP ｶﾝﾚﾝ ﾃｰﾌﾞﾙ ﾖｳ											 */
/*		ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾃﾞｰﾀ ｵﾖﾋﾞ ｴﾗｰ ﾃﾞｰﾀ								 */
/*********************************************************************/
/*********************************************************************/
/*		WMT ﾖｳ ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾃﾞｰﾀ										 */
/*********************************************************************/
#define   MFJWNO    3
struct mfjwmt {							/* WMT ﾖｳ ｼﾞｬｰﾅﾙ ﾃﾞｰﾀ		 */
	char	mfjwid;						/* ｼｷﾍﾞﾂｼ	(0x80) 			 */
	char	mfjwnm[3];					/* ﾃｰﾌﾞﾙ ﾒｲ ("WMT")			 */
	short	mfjwcnt;	 				/* ｶｸﾉｳ ｺｽｳ					 */
	short	mfjwdum;	 				/* ﾖﾋﾞ						 */
	struct    mfjwmth {
		short    mfjwno;				/* ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ			 */
										/*	   0 : ｻﾌﾞ ｷｮｳﾂｳﾌﾞ		 */
										/*	 > 0 : ｺﾍﾞﾂﾌﾞ			 */
		short    mfjwlen;				/* ﾃﾞｰﾀ ﾁｮｳ					 */
		union {
			TWMTSUB    mfjwsub; 		/* ｻﾌﾞ ｷｮｳﾂｳﾌﾞ ﾃﾞｰﾀ			 */
			TWMTPSZ    mfjwpsz; 		/* ｺﾍﾞﾂﾌﾞ ﾃﾞｰﾀ				 */
		}mfjw;
	}mfjwdt[MFJWNO];
};
typedef    struct   mfjwmt   MFJWMT;

/*********************************************************************/
/*		FMT ﾖｳ ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾃﾞｰﾀ										 */
/*********************************************************************/
#define   MFJFNO    3
struct mfjfmt {							/* FMT ﾖｳ ｼﾞｬｰﾅﾙ ﾃﾞｰﾀ		 */
	char	mfjfid;						/* ｼｷﾍﾞﾂｼ	(0x40) 			 */
	char	mfjfnm[3];					/* ﾃｰﾌﾞﾙ ﾒｲ ("FMT")			 */
	short	mfjfcnt;	 				/* ｶｸﾉｳ ｺｽｳ					 */
	short	mfjfdum;	 				/* ﾖﾋﾞ						 */
	struct    mfjfmth {
		short    mfjfno;				/* ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ			 */
										/*	   0 : ｻﾌﾞ ｷｮｳﾂｳﾌﾞ		 */
										/*	 > 0 : ｺﾍﾞﾂﾌﾞ			 */
		short    mfjflen;				/* ﾃﾞｰﾀ ﾁｮｳ					 */
		union {
								/* 動的テーブル削除の為削除(1行) TD60*/
			TFMTPSZ    mfjfpsz; 		/* ｺﾍﾞﾂﾌﾞ ﾃﾞｰﾀ				 */
		}mfjf;
	}mfjfdt[MFJFNO];
};
typedef    struct   mfjfmt   MFJFMT;

/*********************************************************************/
/*		ｴﾗｰ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾃﾞｰﾀ  										 */
/*********************************************************************/

struct mfevmt {					/* ｴﾗｰ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾃﾞｰﾀ 				 */
	char	mfevid; 			/* ｼｷﾍﾞﾂｼ	(0x02) 					 */
	char	mfevnm[3];			/* ﾃｰﾌﾞﾙ ﾒｲ ("VMT")					 */
	long	mfevno;				/* VMT ｴﾝﾄﾘ NO( ｼｮｳｶﾞｲ ﾊｯｾｲ ﾎﾞﾘｭｰﾑ ) */
	long	mfercd;				/* ｴﾗｰ ｺｰﾄﾞ (ROS ﾉ ｴﾗｰ ｺｰﾄﾞ )		 */
	long	mfefno;				/* FMT ｴﾝﾄﾘ NO( ｼｮｳｶﾞｲ ﾊｯｾｲ ﾌｧｲﾙ )   */
								/*  >0 : ｲｯﾊﾟﾝ ﾌｧｲﾙ ｴﾗｰ         	 */
								/*  =0 : ﾜｰｸ ﾌｧｲﾙ ﾏﾀﾊ ﾎﾞﾘｭｰﾑ ｴﾗｰ 	 */
	long	mfevmtp;			/* ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ﾅｲ ｾﾝﾄｳ VMT ｴﾝﾄﾘ NO   */
								/*   ( ﾎﾞﾘｭｰﾑ ﾍｲｿｸ ｼﾞ ﾆ ｼﾖｳ ｽﾙ )	 */
};
typedef    struct   mfevmt	 MFEVMT;

/*********************************************************************/
/*		2ｼﾞｭｳｶ ﾌｧｲﾙ ﾖｳ FMT ﾉ ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ﾃﾞ-ﾀ                        */
/*********************************************************************/

struct	mfjdfmth	{					/* 2ｼﾞｭｳｶ FMT ｼﾞｬ-ﾅﾙﾃﾞ-ﾀ ﾍｯﾀﾞ*/
	char	mfjdfid;					/* ｼｷﾍﾞﾂｼ	(0x20)			 */
	char	mfjdfnm[3];					/* ﾃ-ﾌﾞﾙ ﾒｲ ("FMT")			 */
	short	mfjdfcnt;					/* ｶｸﾉｳ ｺｽｳ					 */
	short	mfjdfdum;					/* ﾖﾋﾞ						 */
};
typedef	struct	mfjdfmth	MFJDFMTH;

struct	mfjdfmt		{ 					/* 2ｼﾞｭｳｶ FMT ｼﾞｬ-ﾅﾙ ﾃﾞ-ﾀ 	 */
	long	mfjdfmtno;  				/* FMT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ  		 */
	char	mfjdstat;					/* ｽﾃ-ﾀｽ					 */
										/*  0x00 : ｾｲｼﾞｮｳ			 */
										/*  0x80 : ﾌｧｲﾙ ｿｳｾｲ ﾉﾐ		 */
	char	mfjdfdum[3];				/* ﾖﾋﾞ						 */
};
typedef	struct	mfjdfmt		MFJDFMT;

/*********************************************************************/
/*		ｴﾗｰ ｼﾞｮｳﾎｳ ｵﾖﾋﾞ ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾉ ｼｷﾍﾞﾂｼ						 */
/*********************************************************************/

#define    MFJNLWMT    0x80				/* WMT ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾖｳ ｼｷﾍﾞﾂｼ */
#define    MFJNLFMT    0x40				/* FMT ｼﾞｬｰﾅﾙ ｼｭﾄｸ ﾖｳ ｼｷﾍﾞﾂｼ */
#define    MFJNLDFT    0x20				/* 2ｼﾞｭｳｶ FMT ｼﾞｬｰﾅﾙ ｼｷﾍﾞﾂｼ  */
#define    MFERRWMT    0x08				/* WMT ｴﾗｰ ｼｮﾘ ﾖｳ ｼｷﾍﾞﾂｼ	 */
#define    MFERRFMT    0x04				/* FMT ｴﾗｰ ｼｮﾘ ﾖｳ ｼｷﾍﾞﾂｼ	 */
#define    MFERRVMT    0x02				/* ｴﾗｰ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾃﾞｰﾀ ｼｷﾍﾞﾂｼ*/

/*********************************************************************/
/*		ﾀﾞｳﾝ ｺｰﾄﾞ､ ｼｮｳｻｲ ｺｰﾄﾞ 										 */
/*********************************************************************/

#define    MFDNJPER    0x1C0B 			/* mf_jper					 */
#define    MFDNJWMT    0x1C06 			/* mf_jwmt					 */
#define	   MFDNJFMT	   0x1C07			/* mf_jfmt					 */
#define	   MFDNPRCV	   0x1858			/* mf_prcv				TD48 */
#define	   MFDNJDFT	   0x1C12			/* mf_jdft					 */
#define	   MFDNFCRT	   0x1904			/* mf_fcrt				TD48 */

#define    MFDTJPFMT   0x21000000 		/* mr_jedt(FMT) ｴﾗｰ (mf_jper)*/
#define    MFDTJPVMT   0x22000000 		/* mr_jedt(VMT) ｴﾗｰ (mf_jper)*/
#define    MFDTJPJNL   0x23000000 		/* mr_jnl  ｴﾗｰ 		(mf_jper)*/
#define    MFDTJPCPC   0x24000000 		/* mr_cpca ｴﾗｰ 		(mf_jper)*/
#define    MFDTJPJIN   0x25000000 		/* mr_jint ｴﾗｰ 		(mf_jper)*/
/***** LINUX移植対応		Start			修正日：2002.04.17	  ****/
#define    MFDTJPFMT2  0x26000000 		/* mr_jedt2(FMT)ｴﾗｰ (mf_jper)*/
#define    MFDTJPVMT2  0x27000000 		/* mr_jedt2(VMT)ｴﾗｰ (mf_jper)*/
/***** LINUX移植対応		 End			修正日：2002.04.17	  ****/

#define    MFDTJWJED   0x21000000 		/* mr_jedt ｴﾗｰ		(mf_jwmt)*/
#define    MFDTJWJNL   0x22000000 		/* mr_jnl  ｴﾗｰ		(mf_jwmt)*/
#define    MFDTJWCPC   0x23000000 		/* mr_cpca ｴﾗｰ		(mf_jwmt)*/
#define    MFDTJWJIN   0x24000000 		/* mr_jint ｴﾗｰ		(mf_jwmt)*/
/***** LINUX移植対応		Start			修正日：2002.04.17	  ****/
#define    MFDTJWJED2  0x25000000 		/* mr_jedt2ｴﾗｰ		(mf_jwmt)*/
/***** LINUX移植対応		 End			修正日：2002.04.17	  ****/

#define    MFDTJFJED   0x21000000 		/* mr_jedt ｴﾗｰ 		(mf_jfmt)*/
#define    MFDTJFJNL   0x22000000 		/* mr_jnl  ｴﾗｰ 		(mf_jfmt)*/
#define    MFDTJFCPC   0x23000000 		/* mr_cpca ｴﾗｰ 		(mf_jfmt)*/
#define    MFDTJFJIN   0x24000000 		/* mr_jint ｴﾗｰ 		(mf_jfmt)*/
/***** LINUX移植対応		Start			修正日：2002.04.17	  ****/
#define    MFDTJFJED2  0x25000000 		/* mr_jedt2ｴﾗｰ 		(mf_jfmt)*/
/***** LINUX移植対応		 End			修正日：2002.04.17	  ****/

#define    MFDTPRCV    0x21000000 		/* ﾌｧｲﾙ ｶｸﾁｮｳｼﾞ ｴﾗｰ (mf_prcv)*/

#define    MFDTJDJED   0x21000000 		/* mr_jedt ｴﾗ-      (mf_jdft)*/
#define    MFDTJDJNL   0x22000000 		/* mr_jnl  ｴﾗ-      (mf_jdft)*/
#define    MFDTJDCPC   0x23000000 		/* mr_cpca ｴﾗ-      (mf_jdft)*/
#define    MFDTJDJIN   0x24000000 		/* mr_jint ｴﾗ-      (mf_jdft)*/
/***** LINUX移植対応		Start			修正日：2002.04.17	  ****/
#define    MFDTJDJED2  0x25000000 		/* mr_jedt2ｴﾗ-      (mf_jdft)*/
/***** LINUX移植対応		 End			修正日：2002.04.17	  ****/

#define    MFDTFCJED   0x21000000 		/* mr_jedt ｴﾗ-(mf_fcrt) TD30 */
#define    MFDTFCJNL   0x22000000 		/* mr_jnl  ｴﾗ-(mf_fcrt) TD30 */
#define    MFDTFCCPC   0x23000000 		/* mr_cpca ｴﾗ-(mf_fcrt) TD30 */
#define    MFDTFCJIN   0x24000000 		/* mr_jint ｴﾗ-(mf_fcrt) TD30 */
