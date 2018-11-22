/*********************************************************************/
/*	ﾌｱｲﾙ ﾚﾝｹﾂ ｼﾞﾖｳﾎｳ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFCCB >							 */
/*********************************************************************/
struct	mfccb {
	char	mfcbid[2];			/*	ﾌｱｲﾙﾚﾝｹﾂ ｼﾞﾖｳﾎｳｶﾝﾘ ﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ  */
	short	mfcdum1;			/*	ﾖﾋﾞ								 */
	short	mfcfmax;			/*	ﾌﾟﾛｾｽﾅｲ ﾌｱｲﾙｷｼﾞﾕﾂｼ ｻｲﾀﾞｲｽｳ		 */
	short	mfcfnum;			/*	ｹﾞﾝ ﾚﾝｹﾂﾌｱｲﾙ ｽｳ					 */
};
typedef struct mfccb MFCCB;
/*********************************************************************/
/*	MFCCB ﾅｲ ｶﾍﾝ ｴﾘｱ												 */
/*********************************************************************/
struct	mfccbh {
	short	mfcfmtn;			/*	FMT ｴﾝﾄﾘﾊﾞﾝｺﾞｳ					 */
	short	mfcdum2;			/*	ﾖﾋﾞ								 */
	long	mfcffd;				/*	ﾌｱｲﾙｷｼﾞﾕﾂｼ						 */
};
typedef struct mfccbh MFCCBH;
/*********************************************************************/
/*	ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFDCB >									 */
/*********************************************************************/
#define	MFDCBNO		7			/*	MFDCB ﾉ ﾊｲﾚﾂｽｳ					 */

struct mfdcb {
	char	mfdbid[2];			/*	ｶﾘｺｳｼﾝ ﾃﾞｰﾀｶﾝﾘﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ		 */
								/*	 ( = 'DB' )						 */
	short	mfddnum;			/*	ﾕｳｺｳ ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ｽｳ				 */
	struct	mfdcb	*mfdnexp;	/*	NEXT ｶﾘｺｳｼﾝ ﾃﾞｰﾀｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ	 */
	struct	mfdcbh {
		long	mfddtno;		/*	ｶﾘｺｳｼﾝﾚｺｰﾄﾞ ﾊﾞﾝｺﾞｳ				 */
								/*	 (ﾌｧｨﾙ ﾀｲﾌﾟ ﾃﾞ ｺﾄﾅﾙ)			 */
		char	*mfddtad;		/*	ｶﾘｺｳｼﾝﾃﾞｰﾀ ｱﾄﾞﾚｽ				 */
	} mfddt[MFDCBNO];
};
typedef struct mfdcbh MFDCBH;
typedef struct mfdcb MFDCB;

/*********************************************************************/
/*	ｹﾝｻｸ ﾃﾞｰﾀ ｶﾝﾘ ﾌﾞﾛﾂｸ	< MFSCB >									 */
/*********************************************************************/
#define	MFSCBNO 	64			/*	MFSCB ﾉ ﾊｲﾚﾂｽｳ					 */

struct mfscb {
	char	mfsbid[2];			/*	ｹﾝｻｸﾃﾞｰﾀ ｶﾝﾘﾌﾞﾛｸ ｼｷﾍﾞﾂｼ			 */
	short	mfsdum1;			/*	ﾖﾋﾞ								 */
	struct	mfscb	*mfsnexp;	/*	NEXT MFSCB ｱﾄﾞﾚｽ				 */
	struct	mfscb	*mfsbakp;	/*	BACK MFSCB ｱﾄﾞﾚｽ				 */
	char	*mfsbsgp[MFSCBNO];	/*	ﾋﾞﾂﾄﾏﾂﾌﾟｾｸﾞﾒﾝﾄ ｱﾄﾞﾚｽ			 */
};
typedef struct mfscb MFSCB;
																  /*%*/
/*********************************************************************/
/*	ﾌｱｲﾙ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFFCB >										 */
/*********************************************************************/
struct mffcb {
	char	mffbid[2];			/*	ﾌｱｲﾙｶﾝﾘﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ ( = 'FB' )	 */
	char	mffmode;			/*	ｵｰﾌﾟﾝ ﾓｰﾄﾞ						 */
								/*	 11.. .... ｼｮﾘ ﾓｰﾄﾞ				 */
								/*				   MFFBMODE 		 */
								/*			'00' : ﾖﾐｺﾐ 			 */
								/*				   MFFBREAD 		 */
								/*			'10' : ﾂｲｶ ｶｷｺﾐ 		 */
								/*				   MFFBWRITE		 */
								/*	 ..1. .... ｱｸｾｽ ﾓｰﾄﾞ			 */
								/*			'1' : ｺｳｿｸ ｱｸｾｽ 		 */
								/*				  MFFBHACS			 */
								/*			'0' : ﾂｳｼﾞｮｳ ｱｸｾｽ		 */
								/*	 ...1 .... ﾌｧｨﾙ ｸﾌﾞﾝ			 */
								/*			'1' : ﾜｰｸ ﾌｧｲﾙ			 */
								/*				  MFFBWFIL			 */
								/*			'0' : ｲｯﾊﾟﾝ ﾌｧｲﾙ		 */
								/*				  MFFBNFIL			 */
								/*	 .... .111 ｱｸｾｽ ﾎｳ				 */
								/*					MFFBACCESS		 */
								/*			'000' : ｽﾄﾘｰﾑ ｱｸｾｽ (E)	 */
								/*					MFFBETYPE		 */
								/*			'001' : ｼﾞｭﾝ ﾚｺｰﾄﾞ (A)	 */
								/*					MFFBATYPE		 */
								/*			'010' : ﾁｮｸｾﾂ ﾚｺｰﾄﾞ (B)  */
								/*					MFFBBTYPE		 */
								/*			'011' : ﾗﾝﾀﾞﾏｲｽﾞ ﾎｳｼｷ (C)*/
								/*					MFFBCTYPE		 */
								/*			'100' : ｷｰ ｹﾝｻｸ ﾎｳｼｷ (D) */
								/*					MFFBDTYPE		 */
	char	mffstat;			/*	ｽﾃｰﾀｽ							 */
								/*	 1... .... ｼﾞｬｰﾅﾙ ｼｮﾄｸ ｽﾃｰﾀｽ	 */
								/*			'1' : ｼﾞｬｰﾅﾙ ｦ ﾄﾙ		 */
								/*				  MFFBJGET			 */
								/*			'0' : ｼﾞｬｰﾅﾙ ﾊ ﾄﾗﾅｲ		 */
								/*	 .1.. .... ｼﾞｬｰﾅﾙ ｼｮﾄｸ ｸﾌﾞﾝ 	 */
								/*			'1' : ｺｳﾓｸ ﾀﾝｲ			 */
								/*				  MFFBJITM			 */
								/*			'0' : ﾚｺｰﾄﾞ ﾀﾝｲ			 */
								/*	 ..1. .... ｶﾘｺｳｼﾝ ﾁｭｳ ﾌﾗｸﾞ		 */
								/*			'1' : ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ｱﾘ	 */
								/*				  MFFBRNDAT 		 */
								/*			'0' : ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ﾅｼ	 */
								/*	 ...1 .... ｸﾛｰｽﾞ ﾖｳｷｭｳ ﾌﾗｸﾞ		 */
								/*			'1' : ｸﾛｰｽﾞ ﾖｳｷｭｳ ｱﾘ	 */
								/*				  MFFBCLOSE 		 */
								/*			'0' : ｸﾛｰｽﾞ ﾖｳｷｭｳ ﾅｼ	 */
								/*	 .... 1... ｸﾛｰｽﾞ ｼﾞ ｻｸｼﾞｮ ﾌﾗｸﾞ	 */
								/*			'1' : ｸﾛｰｽﾞ ｼﾞ ｻｸｼﾞｮ ｽﾙ  */
								/*				  MFFBCDEL			 */
								/*			'0' : ｸﾛｰｽﾞ ｼﾞ ｻｸｼﾞｮ ｼﾅｲ */
								/*	 .... .1.. ﾋｶﾝﾘｮｳ ｶﾞﾀ ｱｸｾｽﾌﾗｸﾞ	 */
								/*			'1' : ﾋｶﾝﾘｮｳｶﾞﾀ ｱｸｾｽﾁｭｳ  */
								/*				  MFFBICMP			 */
								/*			'0' : ﾋｶﾝﾘｮｳｶﾞﾀ ﾃﾞ ﾊ ﾅｲ  */
								/*	 .... ..11 ﾖﾐｺﾐ ｱｸｾｽ ｼﾞｭﾝ		 */
								/*			   MFFBSEQ				 */
								/*			'00' : DIRECT ｼﾃｲ		 */
								/*				   MFFBDIRCT		 */
								/*			'01' : NEXT   ｼﾃｲ		 */
								/*				   MFFBNEXT			 */
								/*			'10' : BACK   ｼﾃｲ		 */
								/*				   MFFBBACK			 */
								/*			'11' : START  ｼﾃｲ		 */
								/*				   MFFBSTART		 */
	char	mffopst;			/*	ｼﾞｮｳﾀｲ							 */
								/*	 .... 1... ｵｰﾌﾟﾝｼﾞ ﾉ ｼﾞｮｳﾀｲ 	 */
								/*			'1' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*				  MFFBTRNOPN		 */
								/*			'0' : ﾄﾗﾝｻﾞｸｼｮﾝ ｶﾞｲ		 */
								/*	 .... .1.. ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｱｸｾｽﾌﾗｸﾞ */
								/*			'1' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*							ｱｸｾｽ ｱﾘ	 */
								/*				  MFFBTRNACS		 */
								/*			'0' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*							ｱｸｾｽ ﾅｼ	 */
								/*	 .... ..1. ENQ ﾁｪｯｸ ﾌﾗｸﾞ		 */
								/*			'1' : ｵｰﾌﾟﾝ ｶﾗ ENQ ｻﾚﾃｲﾙ */
								/*				  MFFBENQOP			 */
								/*			'0' : ｵｰﾌﾟﾝｺﾞ DEQ ｻﾚﾀ	 */
	char	mffdum1;			/*	ﾖﾋﾞ 1							 */
	short	mffvmtp;			/*	VMT ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ                */
	long	mffrnum;			/*	ｼｹﾞﾝﾊﾞﾝｺﾞｳ						 */
	MFDCB	*mffdcbp;			/*	ｶﾘｺｳｼﾝﾃﾞｰﾀ ｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ		 */
	long	mffeof;				/*	ｶﾘｺｳｼﾝ ｼﾞ EOF ｼﾞﾖｳﾎｳ			 */
	MFSCB	*mffscbp;			/*	ｹﾝｻｸﾃﾞｰﾀ ｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ			 */
	long	mffdad1;			/*	ﾃﾞｰﾀ ｶｸﾉｳｲﾁ	1					 */
	long	mffdad2;			/*	ﾃﾞｰﾀ ｶｸﾉｳｲﾁ	2					 */
	short	mffrlen;			/*	ﾚｺｰﾄﾞ ﾁﾖｳ						 */
	short	mffblen;			/*	ﾌﾞﾛﾂｸ ﾁﾖｳ						 */
	char	*mffbufp;			/*	ｹﾞﾝ ﾖﾐｺﾐ ﾃﾞｰﾀ ｶｸﾉｳﾊﾞﾂﾌｱ ｱﾄﾞﾚｽ	 */
	long	mfffd[2];			/*	ﾌｱｲﾙｷｼﾞﾕﾂｼ (ｾｲ, ﾌｸ)				 */
	long	mffspac;			/*	ｹﾞﾝ ﾌｱｲﾙ ﾖｳﾘﾖｳ					 */
	short	mffnear;			/*	ﾆｱ.ｴﾝﾄﾞ ﾂｳﾁ ﾜﾘｱｲ				 */
	short	mffwmtp;			/*	WMT ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ				 */
	short	mffmaxs;			/*	ｻｲﾀﾞｲ ｱｸｾｽ ｻｲｽﾞ					 */
	short	mffklen;			/*	ﾚｺ-ﾄﾞ ﾅｲ ｷ- ﾁｮｳ ﾄ-ﾀﾙ			 */
	long	mffrcnt;			/*	ｹﾞﾝ ｱｸｾｽ ﾚｺｰﾄﾞｽｳ		  TC3714 */
	long	mffrecn;			/*	ｹﾞﾝ ﾖﾐｺﾐ ﾚｺｰﾄﾞｽｳ		  TC3714 */
	long	mffcurn;			/*	ｹﾞﾝ ｱｸｾｽ ﾚｺｰﾄﾞﾊﾞﾝｺﾞｳ			 */
	long	mffrno;				/*	ｹﾞﾝ ﾖﾐｺﾐ ﾚｺｰﾄﾞﾊﾞﾝｺﾞｳ			 */
	long	mffosrd;			/*	ROS ﾉ ﾖｳｷｭｳ ｼｷﾍﾞﾂｼ				 */
	char	*mffkbf1;			/*	ｷｰ ｶﾝﾘﾌﾞ ｼﾕﾂﾘﾖｸﾖｳﾊﾞﾂﾌｱ ｱﾄﾞﾚｽ 1	 */
	char	*mffkbf2;			/*	ｷｰ ｶﾝﾘﾌﾞ ｼﾕﾂﾘﾖｸﾖｳﾊﾞﾂﾌｱ ｱﾄﾞﾚｽ 2	 */
	short	mffkeyn;			/*	ｷｰ ｽｳ							 */
	short	mffkmtp;			/*	KMT ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ				 */
	short	mffkpos;			/*	ｹﾞﾝ ﾖﾐｺﾐｷｰ ｲﾁ					 */
	short	mffdum2;			/*	予備２						TD24 */
	long	mffkrno;			/*	ｹﾞﾝ ﾖﾐｺﾐﾃﾞｰﾀ ｷｰﾅｲﾚｺｰﾄﾞ ﾊﾞﾝｺﾞｳ	 */
														   /* TC3714 */
	long	(*mffrand)();		/*	ﾗﾝﾀﾞﾏｲｽﾞ ﾍﾝｶﾝﾙｰﾁﾝ ｱﾄﾞﾚｽ			 */
};	  
typedef struct mffcb MFFCB;

#define	MFFBMODE	0xC0		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｼｮﾘﾓｰﾄﾞ				 */
#define	MFFBREAD	0x00		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｼｮﾘﾓｰﾄﾞ ﾖﾐｺﾐ			 */
#define	MFFBWRITE	0x80		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｼｮﾘﾓｰﾄﾞ ﾂｲｶｶｷｺﾐ		 */
#define	MFFBHACS	0x20		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾓｰﾄﾞ ｺｳｿｸｱｸｾｽ		 */
#define	MFFBWFIL	0x10		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ﾌｧｲﾙｸﾌﾞﾝ ﾜｰｸﾌｧｲﾙ		 */
#define	MFFBNFIL	0x00		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ﾌｧｲﾙｸﾌﾞﾝ ｲｯﾊﾟﾝﾌｧｲﾙ	 */
#define	MFFBACCESS	0x07		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ				 */
#define	MFFBETYPE	0x00		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ Eﾀｲﾌﾟ			 */
#define	MFFBATYPE	0x01		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ Aﾀｲﾌﾟ			 */
#define	MFFBBTYPE	0x02		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ Bﾀｲﾌﾟ			 */
#define	MFFBCTYPE	0x03		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ Cﾀｲﾌﾟ			 */
#define	MFFBDTYPE	0x04		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ Dﾀｲﾌﾟ			 */
#define	MFFBDDTYPE	0x05		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ.ｱｸｾｽﾎｳ D'ﾀｲﾌﾟ     TD24 */
#define	MFFBJGET	0x80		/*	ｽﾃｰﾀｽ.ｼﾞｬｰﾅﾙｽﾃｰﾀｽ  ｼﾞｬｰﾅﾙｦ ﾄﾙ	 */
#define	MFFBJITM	0x40		/*	ｽﾃｰﾀｽ.ｼﾞｬｰﾅﾙｼｭﾄｸｸﾌﾞﾝ ｺｳﾓｸﾀﾝｲ	 */
#define	MFFBRNDAT	0x20		/*	ｽﾃｰﾀｽ.ｶﾘｺｳｼﾝﾁｭｳﾌﾗｸﾞ ｶﾘｺｳｼﾝﾃﾞｰﾀｱﾘ */
#define	MFFBCLOSE	0x10		/*	ｽﾃｰﾀｽ.ｸﾛｰｽﾞﾖｳｷｭｳﾌﾗｸﾞ ﾖｳｷｭｳｱﾘ	 */
#define	MFFBCDEL	0x08		/*	ｽﾃｰﾀｽ.ｸﾛｰｽﾞｼﾞｻｸｼﾞｮﾌﾗｸﾞ ｻｸｼﾞｮｽﾙ	 */
#define	MFFBICMP	0x04		/*	ｽﾃｰﾀｽ.ﾋｶﾝﾘｮｳｶﾞﾀﾌﾗｸﾞ ｱｸｾｽﾁｭｳ		 */
#define	MFFBSEQ		0x03		/*	ｽﾃｰﾀｽ.ﾖﾐｺﾐｱｸｾｽｼﾞｭﾝ				 */
#define	MFFBDIRCT	0x00		/*	ｽﾃｰﾀｽ.ﾖﾐｺﾐｱｸｾｽｼﾞｭﾝ DIRECT ｼﾃｲ	 */
#define	MFFBNEXT	0x01		/*	ｽﾃｰﾀｽ.ﾖﾐｺﾐｱｸｾｽｼﾞｭﾝ NEXT   ｼﾃｲ	 */
#define	MFFBBACK	0x02		/*	ｽﾃｰﾀｽ.ﾖﾐｺﾐｱｸｾｽｼﾞｭﾝ BACK   ｼﾃｲ	 */
#define	MFFBSTART	0x03		/*	ｽﾃｰﾀｽ.ﾖﾐｺﾐｱｸｾｽｼﾞｭﾝ START  ｼﾃｲ	 */
#define	MFFBTRNOPN	0x08		/*	ｵｰﾌﾟﾝｽﾃｰﾀｽ.ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｵｰﾌﾟﾝ	 */
#define	MFFBTRNACS	0x04		/*	ｵｰﾌﾟﾝｽﾃｰﾀｽ.ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｱｸｾｽ ｱﾘ	 */
#define	MFFBENQOP	0x02		/*	ｵｰﾌﾟﾝｽﾃｰﾀｽ.ｵｰﾌﾟﾝｶﾗ ENQ ｻﾚﾃｲﾙ	 */
																  /*%*/
/*********************************************************************/
/*	ﾃｰﾌﾞﾙ ｶﾝﾘ ﾌﾞﾛﾂｸ	< MFTCB >										 */
/*********************************************************************/
struct mftcb {
	char	mftbid[2];			/*	ﾃｰﾌﾞﾙｶﾝﾘﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ ( = 'TB' )  */
	char	mftmode;			/*	ｵｰﾌﾟﾝ ﾓｰﾄﾞ						 */
								/*	 11.. .... ｵｰﾌﾟﾝ ﾓｰﾄﾞ			 */
								/*			   MFTBOPMD				 */
								/*			'00' : ｻﾝｼｮｳ			 */
								/*				   MFTBRFMD			 */
								/*			'10' : ｺｳｼﾝ				 */
								/*				   MFTBUPMD			 */
	char	mftstat;			/*	ｽﾃｰﾀｽ							 */
								/*	 1... .... ｼﾞｬｰﾅﾙ ｼｮﾄｸ ｽﾃｰﾀｽ	 */
								/*			'1' : ｼﾞｬｰﾅﾙ ｦ ﾄﾙ		 */
								/*				   MFTBJGET			 */
								/*			'0' : ｼﾞｬｰﾅﾙ ﾊ ﾄﾗﾅｲ 	 */
								/*	 .1.. .... ｼﾞｬｰﾅﾙ ｼｮﾄｸ ｸﾌﾞﾝ 	 */
								/*			'1' : ｺｳﾓｸ ﾀﾝｲ			 */
								/*				   MFTBJITM			 */
								/*			'0' : ｺﾍﾞﾂﾌﾞ ﾀﾝｲ		 */
								/*	 ..1. .... ｶﾘｺｳｼﾝ ﾁｭｳ ﾌﾗｸﾞ		 */
								/*			'1' : ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ｱﾘ	 */
								/*				   MFTBRNDAT		 */
								/*			'0' : ｶﾘｺｳｼﾝ ﾃﾞｰﾀ ﾅｼ	 */
								/*	 ...1 .... ｸﾛｰｽﾞ ﾖｳｷｭｳﾌﾗｸﾞ		 */
								/*			'1' : ｸﾛｰｽﾞ ﾖｳｷｭｳ ｱﾘ	 */
								/*				   MFTBCLOSE		 */
								/*			'0' : ｸﾛｰｽﾞ ﾖｳｷｭｳ ﾅｼ	 */
								/*	 .... ..11 ﾖﾐｺﾐ ｱｸｾｽ ｼﾞｭﾝ		 */
								/*			   MFTBSEQ				 */
								/*			'00' : DIRECT ｼﾃｲ		 */
								/*				   MFTBDIRCT		 */
								/*			'01' : NEXT   ｼﾃｲ		 */
								/*				   MFTBNEXT 		 */
								/*			'10' : BACK   ｼﾃｲ		 */
								/*				   MFTBBACK 		 */
								/*			'11' : START  ｼﾃｲ		 */
								/*				   MFTBSTART		 */
	char	mftopst;			/*	ｼﾞｮｳﾀｲ							 */
								/*	 .... 1... ｵｰﾌﾟﾝｼﾞ ﾉ ｼﾞｮｳﾀｲ 	 */
								/*			'1' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*				  MFTBTRNOPN		 */
								/*			'0' : ﾄﾗﾝｻﾞｸｼｮﾝ ｶﾞｲ		 */
								/*	 .... .1.. ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｱｸｾｽﾌﾗｸﾞ */
								/*			'1' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*							ｱｸｾｽ ｱﾘ	 */
								/*				  MFTBTRNACS		 */
								/*			'0' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*							ｱｸｾｽ ﾅｼ	 */
	char	mftdum1;			/*	ﾖﾋﾞ 1							 */
	short	mftdum2;			/*	ﾖﾋﾞ 2							 */
	long	mftrnum;			/*	ｼｹﾞﾝﾊﾞﾝｺﾞｳ						 */
	MFDCB	*mftdcbp;			/*	ｶﾘｺｳｼﾝﾃﾞｰﾀ ｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ		 */
	long	mftent;				/*	ｺﾍﾞﾂﾌﾞ ﾕｳｺｳ ｴﾝﾄﾘ ｽｳ				 */
	MFSCB	*mftscbp;			/*	ｹﾝｻｸﾃﾞｰﾀ ｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ			 */
	TCOMPAT *mftcomp;			/*	ﾃｰﾌﾞﾙ ｾﾝﾄｳ ｱﾄﾞﾚｽ				 */
	char	*mftpvtp;			/*	ｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ｱﾄﾞﾚｽ				 */
	short	mftklen;			/*	ｺﾍﾞﾂﾌﾞ ﾁﾖｳ						 */
	short	mftslen;			/*	ｻﾌﾞｷﾖｳﾂｳﾌﾞ ﾁﾖｳ					 */
	char	*mftbufp;			/*	ｼﾞﾔｰﾅﾙﾍﾝｼﾕｳﾖｳ ﾊﾞﾂﾌｱ ｱﾄﾞﾚｽ		 */
	short	mftkno;				/*	ｹﾞﾝﾖﾐｺﾐ ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ			 */
	short	mftkcnt;			/*	ｹﾞﾝﾖﾐｺﾐ ｺﾍﾞﾂﾌﾞ ｽｳ				 */
};
typedef struct mftcb MFTCB;

#define	MFTBOPMD	0xC0		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ						 */
#define	MFTBRFMD	0x00		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ. ｻﾝｼｮｳ				 */
#define	MFTBUPMD	0x80		/*	ｵｰﾌﾟﾝﾓｰﾄﾞ. ｺｳｼﾝ 				 */
#define	MFTBJGET	0x80		/*	ｽﾃｰﾀｽ.ｼﾞｬｰﾅﾙｽﾃｰﾀｽ ｼﾞｬｰﾅﾙｦ ﾄﾙ	 */
#define	MFTBJITM	0x40		/*	ｽﾃｰﾀｽ.ｼﾞｬｰﾅﾙｼｭﾄｸｸﾌﾞﾝ ｺｳﾓｸﾀﾝｲ	 */
#define	MFTBRNDAT	0x20		/*	ｽﾃｰﾀｽ.ｶﾘｺｳｼﾝﾁｭｳﾌﾗｸﾞ ｶﾘｺｳｼﾝﾃﾞｰﾀｱﾘ */
#define	MFTBCLOSE	0x10		/*	ｽﾃｰﾀｽ.ｸﾛｰｽﾞﾖｳｷｭｳﾌﾗｸﾞ ﾖｳｷｭｳｱﾘ	 */
#define	MFTBSEQ		0x03		/*	ﾖﾐｺﾐ ｱｸｾｽｼﾞｭﾝ					 */
#define	MFTBDIRCT	0x00		/*	ﾖﾐｺﾐ ｱｸｾｽｼﾞｭﾝ .  DIRECT ｼﾃｲ 	 */
#define	MFTBNEXT	0x01		/*	ﾖﾐｺﾐ ｱｸｾｽｼﾞｭﾝ .  NEXT	ｼﾃｲ 	 */
#define	MFTBBACK	0x02		/*	ﾖﾐｺﾐ ｱｸｾｽｼﾞｭﾝ .  BACK	ｼﾃｲ 	 */
#define	MFTBSTART	0x03		/*	ﾖﾐｺﾐ ｱｸｾｽｼﾞｭﾝ .  START	ｼﾃｲ 	 */
#define	MFTBTRNOPN	0x08		/*	ｵｰﾌﾟﾝｽﾃｰﾀｽ.ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｵｰﾌﾟﾝ	 */
#define	MFTBTRNACS	0x04		/*	ｵｰﾌﾟﾝｽﾃｰﾀｽ.ﾄﾗﾝｻﾞｸｼｮﾝﾁｭｳ ｱｸｾｽ ｱﾘ	 */
																  /*%*/
/*********************************************************************/
/*	ｼｹﾞﾝ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFMCB >										 */
/*********************************************************************/
#define	MFMCBNO		15			/*	MFMCB ﾉ ﾊｲﾚﾂｽｳ					 */

struct mfmcb {
	char	mfmbid[2];			/*	ｾｲｷﾞｮ ﾌﾞﾛﾂｸ ｼｷﾍﾞﾂ ﾒｲ ( = 'MB' )	 */
	short	mfmdnum;			/*	ﾕｳｺｳ ｼｹﾞﾝ ｽｳ					 */
	struct	mfmcb	*mfmnexp;	/*	NEXT MFMCB ｱﾄﾞﾚｽ				 */
	struct	mfmcbh {			/*	ｼｹﾞﾝ ｶﾝﾘﾌﾞ						 */
		long	mfmrno;			/*	ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ 					 */
		union {					/*	ｼｹﾞﾝ ｱﾄﾞﾚｽ						 */
			MFTCB	*mfmtcbp;	/*	MFTCB ｱﾄﾞﾚｽ						 */
			MFFCB	*mfmfcbp;	/*	MFFCB ｱﾄﾞﾚｽ						 */
		} mfmbp;
	} mfmdt[MFMCBNO];
};
typedef struct mfmcbh	MFMCBH;
typedef struct mfmcb	MFMCB;

/*********************************************************************/
/*	ファイル操作管理ブロック < MFOCB >	 							 */
/*********************************************************************/
struct mfocb {					/* 								TD30 */
	char	mfobid[2];			/* ﾌｧｲﾙ操作管理ﾌﾞﾛｯｸ識別子		TD30 */
	short	mfodum1;			/* 予備1						TD30 */
	long	mforno;				/* ﾌｧｲﾙ資源番号					TD30 */
	long	mfofd;				/* ﾌｧｲﾙ記述子					TD30 */
	long	mfosts;				/* 返却値						TD30 */
	short	mfoopst;			/* ﾌｧｲﾙ操作種別					TD30 */
								/* 操作ﾌﾗｸﾞ						TD30 */
								/* 0x0080 : ﾌｧｲﾙ操作中			TD30 */
								/*		  MFOBFOP				TD30 */
								/* 操作種別						TD30 */
								/* 0x0010 : ﾌｧｲﾙ創成			TD30 */
								/* 		  MFOBCRT				TD30 */
								/* 0x0020 : ﾌｧｲﾙ削除			TD30 */
								/* 		  MFOBRMV				TD30 */
	short	mfophs;				/* ﾌｧｲﾙ操作情報					TD30 */
								/* 0x0001 : ﾌｪｰｽﾞ1				TD30 */
								/* 		  MFOBPHS1				TD30 */
								/* 0x0002 : ﾌｪｰｽﾞ2				TD30 */
								/* 		  MFOBPHS2				TD30 */
								/* 0x0003 : ﾌｪｰｽﾞ3				TD30 */
								/* 		  MFOBPHS3				TD30 */
								/* 0x0004 : ﾌｪｰｽﾞ4				TD30 */
								/* 		  MFOBPHS4				TD30 */
								/* 0x0005 : ﾌｪｰｽﾞ5				TD30 */
								/* 		  MFOBPHS5				TD30 */
								/* 0x0006 : ﾌｪｰｽﾞ6				TD30 */
								/* 		  MFOBPHS6				TD30 */
	short	mfocln;				/* ﾌｧｲﾙ制御更新ﾃﾞｰﾀ長			TD30 */
	short	mfodum2;			/* 予備2						TD30 */
};								/*								TD30 */
typedef struct mfocb	MFOCB;	/*								TD30 */

#define	MFOBFOP		0x0080		/* ﾌｧｲﾙ操作中					TD30 */
#define	MFOBCRT		0x0010		/* ﾌｧｲﾙ創成						TD30 */
#define	MFOBRMV		0x0020		/* ﾌｧｲﾙ削除						TD30 */
#define	MFOBPHS1	0x0001		/* ﾌｪｰｽﾞ1						TD30 */
#define	MFOBPHS2	0x0002		/* ﾌｪｰｽﾞ2						TD30 */
#define	MFOBPHS3	0x0003		/* ﾌｪｰｽﾞ3						TD30 */
#define	MFOBPHS4	0x0004		/* ﾌｪｰｽﾞ4						TD30 */
#define	MFOBPHS5	0x0005		/* ﾌｪｰｽﾞ5						TD30 */
#define	MFOBPHS6	0x0006		/* ﾌｪｰｽﾞ6						TD30 */

																  /*%*/
/*********************************************************************/
/*	ﾌﾟﾛｾｽ ﾅｲ ｼﾞﾖｳﾎｳ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFPCB > 							 */
/*********************************************************************/
struct mfpcb {
	char	mfpbid[2];			/*	ﾌﾟﾛｾｽﾅｲ ｼﾞﾖｳﾎｳ ｶﾝﾘ ﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ	 */
								/*	 ( ='PB' )						 */
	char	mfptrst;			/*	ﾄﾗﾝｻﾞｸｼﾖﾝ ｽﾃｰﾀｽ					 */
								/*	 1... .... ﾄﾗﾝｻﾞｸｼｮﾝ ﾓｰﾄﾞ		 */
								/*		   '1' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ		 */
								/*				 MFPBTRON			 */
								/*		   '0' : ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳﾃﾞ ﾅｲ	 */
								/*	 .... 1111 I/O ｴﾗ-	ｴﾗ- ｼｭﾍﾞﾂ	 */
								/*				 MFPBERTYPE			 */
								/*		'0001' : ﾊﾞｲﾀｲ	ｴﾗ- 		 */
								/*				 MFPBMDERR			 */
								/*		'0010' : ｿｳﾁ	ｴﾗ- 		 */
								/*				 MFPBDRERR			 */
								/*		'0100' : ｼﾖｳ ﾌｶ ｴﾗ- 		 */
								/*				 MFPBNRERR			 */
								/*		'1000' : ｿﾉﾀ ﾉ	ｴﾗ- 		 */
								/*				 MFPBOTERR			 */
	char	mfpstat;			/*	ｽﾃｰﾀｽ							 */
								/*	 1... .... ENQ ﾁｪｯｸ ﾋﾞｯﾄ		 */
								/*		   '1' : ENQ ﾁｪｯｸ ﾖｳ		 */
								/*				 MFPECHK			 */
								/*		   '0' : ENQ ﾁｪｯｸ ﾌﾖｳ		 */
								/*	 .1.. .... ｼｽﾃﾑ ｼｮｷｶ			 */
								/*		   '1' : ｼｽﾃﾑ ｼｮｷｶ ﾁｭｳ		 */
								/*				 MFSINT 			 */
								/*		   '0' : ｼｽﾃﾑ ｼｮｷｶ ﾁｭｳﾃﾞ ﾅｲ  */
								/*	 ..1. .... ｼｽﾃﾑ ｼｭｳﾘｮｳ			 */
								/*		   '1' : ｼｽﾃﾑ ｼｭｳﾘｮｳ ﾁｭｳ	 */
								/*				 MFSTRM				 */
								/*		   '0' : ｼｽﾃﾑ ｼｭｳﾘｮｳ ﾁｭｳﾃﾞ ﾅｲ*/
								/*	 ...1 .... ｼｽﾃﾑ  ﾘｶﾊﾞﾘ			 */
								/*		   '1' : ｼｽﾃﾑ  ﾘｶﾊﾞﾘ ﾁｭｳ	 */
								/*				 MFSRCV				 */
								/*		   '0' : ｼｽﾃﾑ  ﾘｶﾊﾞﾘ ﾁｭｳﾃﾞ ﾅｲ*/
								/*									 */
								/*	 .... 1... ﾌｧｲﾙ ｶｸﾁｮｳ ｼｮﾘ		 */
								/*		   '1' : ﾌｧｲﾙ ｶｸﾁｮｳ ｼｮﾘ ﾁｭｳ	 */
								/*				 MFPBEXTN			 */
								/*		   '0' : ﾌｧｲﾙｶｸﾁｮｳ ｼｮﾘﾁｭｳﾃﾞﾅｲ*/
								/*									 */
								/*	 .... .1.. ｲｯﾊﾟﾝﾌｧｲﾙ ｿｳｻﾓｰﾄﾞ	 */
								/*		   '1' : ｲｯﾊﾟﾝﾌｧｲﾙ ｿｳｻﾓｰﾄﾞ	 */ 
								/*				 MFPFMODE			 */
								/*		   '0' : ｲｯﾊﾟﾝﾌｧｲﾙｿｳｻﾓｰﾄﾞﾃﾞﾅｲ*/
								/*									 */
								/*	 .... ..1. ENQ ﾑｹﾞﾝﾏﾁ ﾌﾗｸﾞ		 */
								/*		   '1' : ENQ ﾑｹﾞﾝﾏﾁ			 */
								/*				 MFPBIENQ			 */
								/*		   '0' : ENQ ｾｯﾃｲ ｼﾞｶﾝﾏﾁ	 */
								/*									 */
	TCOMPAT	*mfpvmtp;			/*	VMT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpgmtp;			/*	GMT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpsgtp;			/*	SGT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpfmtp;			/*	FMT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpkmtp;			/*	KMT ﾛﾝﾘ ｱﾄﾞﾚｽ	(未使用)		 */
	TCOMPAT	*mfpwmtp;			/*	WMT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpemtp;			/*	EMT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpextp;			/*	EXT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	TCOMPAT	*mfpertp;			/*	TERT論理ｱﾄﾞﾚｽ				TD49 */
	TCOMPAT	*mfpmrtp;			/*	TMRT論理ｱﾄﾞﾚｽ				TD22 */
	long	mfpttop;			/*	EMTﾅｲ ﾃｰﾌﾞﾙﾌﾞ ｾﾝﾄｳ ｴﾝﾄﾘﾊﾞﾝｺﾞｳ	 */
	long	mfpcmtb;			/*	CM ﾆ ﾃﾝｶｲ ｻﾚﾙ ﾃｰﾌﾞﾙ ﾉ ｺｽｳ		 */
	long	mfplmno;			/*	ｼﾞ PU ﾉ ﾃｰﾌﾞﾙ ﾉ ｾﾝﾄｳ ｿｳﾀｲ NO	 */
	long	mfpsint;			/*	ｾﾏﾌｵ ｼﾖｷﾁ						 */
	MFCCB	*mfpccbp;			/*	ﾌｱｲﾙﾚﾝｹﾂ ｼﾞﾖｳﾎｳｶﾝﾘ ﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ	 */
	long	mfpwmtr;			/*	WMT ｼｹﾞﾝﾊﾞﾝｺﾞｳ					 */
	long	mfpfmtr;			/*	FMT ｼｹﾞﾝﾊﾞﾝｺﾞｳ					 */
	long	mfpwait;			/*	ｼｹﾞﾝ ｷﾖｳｺﾞｳｼﾞ ｻｲﾀﾞｲ ﾏﾁｼﾞｶﾝ		 */
	TCOMPAT	*mfppvtp;			/*	PVT ﾛﾝﾘ ｱﾄﾞﾚｽ					 */
	MFMCB	*mfpmtcbp;			/*	MFMCB ｱﾄﾞﾚｽ (ﾃｰﾌﾞﾙ)				 */
	MFMCB	*mfpmfcbp;			/*	MFMCB ｱﾄﾞﾚｽ (ﾌｧｲﾙ)				 */
	MFOCB	*mfpocbp;			/*	MFOCB ｱﾄﾞﾚｽ				 	TD30 */
	short	mfpvmtno;			/*  SCSIﾘｾｯﾄ用TVMTｴﾝﾄﾘ番号		TD61 */
	short	mfpdum;				/*  予  備						TD61 */
};
typedef struct mfpcb MFPCB;

#define	MFPBTRON	0x80		/*	ﾄﾗﾝｻﾞｸｼｮﾝ ﾁｭｳ					 */
#define	MFPBERTYPE	0x0F		/*	ｴﾗ- ｼｭﾍﾞﾂ						 */
#define	MFPBMDERR	0x01		/*	ﾊﾞｲﾀｲ	ｴﾗ-						 */
#define	MFPBDRERR	0x02		/*	ｿｳﾁ		ｴﾗ-						 */
#define	MFPBNRERR	0x04		/*	ｼﾖｳ ﾌｶ	ｴﾗ-						 */
#define	MFPBOTERR	0x08		/*	ｿﾉﾀ ﾉ	ｴﾗ-						 */
#define	MFPECHK 	0x80		/*	ENQ ﾁｪｯｸ ﾓｰﾄﾞ					 */
#define	MFSINT		0x40		/*	ｼｽﾃﾑ ｼｮｷｶ ﾁｭｳ					 */
#define	MFSTRM		0x20		/*	ｼｽﾃﾑ ｼｭｳﾘｮｳ ﾁｭｳ					 */
#define	MFSRCV		0x10		/*	ｼｽﾃﾑ  ﾘｶﾊﾞﾘ ﾁｭｳ					 */
#define	MFPBEXTN	0x08		/*	ﾌｧｲﾙ ｶｸﾁｮｳ ｼｮﾘ ﾁｭｳ				 */
#define	MFPFMODE	0x04		/*	ｲｯﾊﾟﾝﾌｧｲﾙ ｿｳｻﾓｰﾄﾞ				 */
#define	MFPBIENQ	0x02		/*	ENQ ﾑｹﾞﾝﾏﾁ (infinity)			 */
																  /*%*/
/*********************************************************************/
/*	ｶﾘｺｳｼﾝ ｼｹﾞﾝ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFZCB > 								 */
/*********************************************************************/
#define	MFZCBNO		14			/*	MFZCB ﾉ ﾊｲﾚﾂ ｽｳ					 */

struct mfzcb {
	char	mfzbid[2];			/*	ｶﾘｺｳｼﾝ ｼｹﾞﾝ ｶﾝﾘﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ 	 */
								/*	 ( = 'ZB' )						 */
	short	mfzrnum;			/*	ﾕｳｺｳｶﾘｺｳｼﾝ ｼｹﾞﾝｽｳ				 */
	struct	mfzcb	*mfznexp;	/*	NEXT ｶﾘｺｳｼﾝ ｼｹﾞﾝｶﾝﾘﾌﾞﾛﾂｸ ｱﾄﾞﾚｽ	 */
	union {						/*	ｶﾘｺｳｼﾝ ｼｹﾞﾝ ｱﾄﾞﾚｽ				 */
		MFFCB	*mfzfcbp;		/*	MFFCB ﾉ ﾎﾟｲﾝﾀ					 */
		MFTCB	*mfztcbp;		/*	MFTCB ﾉ ﾎﾟｲﾝﾀ					 */
	} mfzrad[MFZCBNO];
};
typedef struct mfzcb MFZCB;
					
/*********************************************************************/
/*	ﾆﾕｳｼﾕﾂﾘﾖｸ ｶﾝﾘﾖｳ ﾄﾞｳｷｶﾝﾘ ﾌﾞﾛﾂｸ < MFRCB > 						 */
/*********************************************************************/
struct mfrcb {
	char	mfrbid[2];			/*	ﾆﾕｳｼﾕﾂﾘﾖｸｶﾝﾘﾖｳﾄﾞｳｷ ｶﾝﾘﾌﾞﾛﾂｸｼｷﾍﾞﾂｼ*/
								/*	 ( = 'RB' ) 					 */
	char	mfrtype;			/*	ｲﾗｲ ｼﾕﾍﾞﾂ						 */
								/*	 0x01 : ﾚｺｰﾄﾞ ﾖﾐｺﾐ				 */
								/*			MFRBRCRD				 */
								/*	 0x02 : ﾂｲｶ ｶｷｺﾐ				 */
								/*			MFRBWITE				 */
								/*	 0x04 : ｲﾁ ｼﾃｲ ﾉ ｶｷｺﾐ			 */
								/*			MFRBWITX				 */
								/*	 0x08 : ﾚｺｰﾄﾞ ｺｳｼﾝ				 */
								/*			MFRBRCUP				 */
								/*	 0x10 : ﾚｺｰﾄﾞ ｻｸｼﾞｮ				 */
								/*			MFRBRCDT				 */
	char	mfracsq;			/*	ｱｸｾｽ ｼﾞﾕﾝ						 */
	MFFCB	*mfrfcbp;			/*	MFFCB ｱﾄﾞﾚｽ						 */
	char	*mfrbufp;			/*	ﾕｰｻﾞ ﾆﾕｳｼﾕﾂﾘﾖｸﾘﾖｳｲｷ ｱﾄﾞﾚｽ		 */
	union {
		long	mfrdpos;		/*	ｱｸｾｽ ｶｲｼｲﾁ						 */
		long	*mfrposp;		/*	ｱｸｾｽ ｶｲｼｲﾁ ｱﾄﾞﾚｽ				 */
	} mfrpos;
	long	mfrdlen;			/*	ｱｸｾｽ ﾃﾞｰﾀ ﾁﾖｳ					 */
	long	mfrrqno;			/*	ﾖｳｷﾕｳ ｼｷﾍﾞﾂｼ ｽｳ					 */
};
typedef struct mfrcb MFRCB;
/*********************************************************************/
/*	MFRCB ﾅｲ ｶﾍﾝ ｴﾘｱ												 */
/*********************************************************************/
struct mfrcbh {
	long	mfrrqid;			/*	ﾖｳｷﾕｳ ｼｷﾍﾞﾂｼ					 */
	long	mfrrcod;			/*	ﾍﾝｷﾔｸﾁ							 */
};
typedef struct mfrcbh MFRCBH;

#define	MFRBRCRD	0x01		/*	ｲﾗｲ ｼｭﾍﾞﾂ. ﾚｺｰﾄﾞ ﾖﾐｺﾐ			 */ 
#define	MFRBWITE	0x02		/*	ｲﾗｲ ｼｭﾍﾞﾂ. ﾂｲｶ ｶｷｺﾐ 			 */
#define	MFRBWITX	0x04		/*	ｲﾗｲ ｼｭﾍﾞﾂ. ｲﾁ ｼﾃｲ ﾉ ｶｷｺﾐ		 */
#define	MFRBRCUP	0x08		/*	ｲﾗｲ ｼｭﾍﾞﾂ. ﾚｺｰﾄﾞ ｺｳｼﾝ			 */
#define	MFRBRCDT	0x10		/*	ｲﾗｲ ｼｭﾍﾞﾂ. ﾚｺｰﾄﾞ ｻｸｼﾞｮ			 */
																  /*%*/
/*********************************************************************/
/*	ｼｹﾞﾝ ｾﾝﾕｳ ﾖｳｷﾕｳ ｶﾝﾘ ﾌﾞﾛﾂｸ < MFQCB > 							 */
/*********************************************************************/
#define	MFQCBNO 	14			/*	MFQCB ﾉ ﾊｲﾚﾂ ｽｳ					 */

struct	mfqcb {
	char	mfqbid[2];			/*	ｼｹﾞﾝｾﾝﾕｳﾖｳｷﾕｳ ｶﾝﾘ ﾌﾞﾛﾂｸ ｼｷﾍﾞﾂｼ	 */
								/*	 ( = 'QB' )						 */
	short	mfqrcnt;			/*	ﾌﾞﾛﾂｸﾅｲ ｾﾝﾕｳﾁﾕｳ ｼｹﾞﾝｽｳ			 */
	struct	mfqcb	*mfqnexp;	/*	NEXT MFQCB ｱﾄﾞﾚｽ				 */
	struct	mfqcb	*mfqbakp;	/*	BACK MFQCB ｱﾄﾞﾚｽ				 */
	long	mfqdum1;			/*	ﾖﾋﾞ								 */
	struct	mfqcbh {
		long	mfqrnum;		/*	ｼｹﾞﾝﾊﾞﾝｺﾞｳ						 */
		short	mfqrseq;		/*	ｾﾝﾕｳ ｼﾞﾕﾝｲ						 */
		char	mfqtype;		/*	ｾﾝﾕｳ ｼﾕﾍﾞﾂ						 */
		char	mfqdum2;		/*	ﾖﾋﾞ 							 */
	} mfqdt[MFQCBNO];	
};
typedef struct mfqcbh	MFQCBH;
typedef struct mfqcb	MFQCB;
/*********************************************************************/
/*	ﾌｧｲﾙ ｾｲｷﾞｮ ｼﾞｮｳﾎｳ (ﾌｧｲﾙ ｼｮｷｶｼｮﾘ ﾃﾞ ｼﾖｳｽﾙ)						 */
/*********************************************************************/
struct	mfccrt {
	char		mfccat;			/* ﾌｧｲﾙ ｿﾞｸｾｲ						 */
	char		mfccdm1;		/* ﾖﾋﾞ								 */
	short		mfccky;			/* ｷｰｽｳ								 */
	short		mfccbs;			/* ﾌﾞﾛｯｸ ﾁｮｳ						 */
	short		mfccrs;			/* ﾚｺｰﾄﾞ ﾁｮｳ						 */
	unsigned	long	mfccdt;	/* ﾎｿﾞﾝ ｷｼﾞﾂ						 */
	char		mfccctim[8];	/* 創成期日						TD30 */
};
typedef struct mfccrt	MFCCRT;

/*********************************************************************/
/*	ﾛﾝﾘﾎﾞﾘﾕｰﾑ ﾐﾀﾞｼ ﾗﾍﾞﾙ												 */
/*********************************************************************/
struct	mfvlabl {
	char	mfvname[6];			/*	ﾛﾝﾘﾎﾞﾘﾕｰﾑ ｼｷﾍﾞﾂﾒｲ				 */
	short	mfvdum1;			/*	ﾖﾋﾞ								 */
	long	mfvvadd;			/*	VTOC ｱﾄﾞﾚｽ						 */
	long	mfvtbls;			/*	FLCB ｶﾝﾘﾃｰﾌﾞﾙ ｻｲｽﾞ				 */
	long	mfvnum;				/*	FLCB ｺｽｳ						 */
	short	mfvsize;			/*	FLCB ｻｲｽﾞ						 */
	short	mfvsect;			/*	ﾛﾝﾘ ｾｸﾀ ｻｲｽﾞ					 */
	long	mfvextn[2];			/*	ﾘﾖｳｲｷｶﾝﾘﾌｱｲﾙ EXTENT ｼﾞﾖｳﾎｳ		 */
};
typedef struct mfvlabl	MFVLABL;
																  /*%*/
/*********************************************************************/
/*	ﾃﾞｨﾚｸﾄﾘ ﾉ ｴﾚﾒﾝﾄ 												 */
/*********************************************************************/
struct mfdirel{					/*	ﾃﾞｨﾚｸﾄﾘ ﾉ ｴﾚﾒﾝﾄ					 */
	union {
		char	mfdinm[16];		/*	ﾌｧｲﾙ / ﾃﾞｨﾚｸﾄﾘ ﾒｲ				 */
		long	mfdiuse;		/*	ｴﾚﾒﾝﾄ ｼﾖｳ/ﾐｼﾖｳ					 */
	} mfdidf;
	long	mfdifn;				/*	FLCB ﾊﾞﾝｺﾞｳ						 */
	long	mfdiflg;			/*	ｴﾚﾒﾝﾄ ｶﾝﾘ ﾌﾗｸﾞ					 */
								/*	ｻｲｶｲ ﾊﾞｲﾄ ﾉ ﾋﾞｯﾄ ﾃﾞｰﾀ ﾉ ｲﾁ		 */
								/*	.... ...1 : ｼﾞ､ｵﾔ ﾃﾞｨﾚｸﾄﾘ ｴﾚﾒﾝﾄ	 */
								/*	.... ...0 : ﾊｲｶ ﾉ ﾌｧｲﾙ､ﾃﾞｨﾚｸﾄﾘ	 */
								/*	.... ..1. : ﾊｲｶ ﾉ ﾃﾞｨﾚｸﾄﾘ ｴﾚﾒﾝﾄ	 */
								/*	.... ..0. : ﾊｲｶ ﾉ ﾌｧｲﾙ ｴﾚﾒﾝﾄ	 */
								/*	.... .1.. : ﾘﾝｸ ﾃﾞ ｻｸｾｲ ｻﾚﾀ ｴﾚﾒﾝﾄ*/
};
typedef    struct	mfdirel  MFDIREL;
#define	MFDIRFG		0x00000007	/*	ｼﾞ､ｵﾔ ﾃﾞｨﾚｸﾄﾘ ｴﾚﾒﾝﾄ ﾃﾞｱﾙ		 */
#define	MFDIRY		0x00000002	/*	ﾊｲｶ ﾉ ﾃﾞｨﾚｸﾄﾘ ｴﾚﾒﾝﾄ ﾃﾞｱﾙ		 */
#define	MFDIOAP		0x00000001	/*	ｵﾔ ﾉ ﾃﾞｨﾚｸﾄﾘ ｴﾚﾒﾝﾄ ﾃﾞｱﾙ			 */
#define	MFDIFIL		0x00000000	/*	ﾊｲｶ ﾉ ﾌｧｲﾙ ｴﾚﾒﾝﾄ ﾃﾞｱﾙ			 */
/*********************************************************************/
/*	MFKEY															 */
/*********************************************************************/
union  mfkey {
	char			mfkck[4];
	short			mfksk;		/*	2 ﾊﾞｲﾄ ﾉ ﾌｺﾞｳﾂｷ ｽｳﾁ				 */
	unsigned short	mfkusk;		/*	2 ﾊﾞｲﾄ ﾉ ﾌｺﾞｳﾅｼ ｽｳﾁ				 */
	long			mfklk;		/*	4 ﾊﾞｲﾄ ﾉ ﾌｺﾞｳﾂｷ ｽｳﾁ				 */
	unsigned long	mfkulk;		/*	4 ﾊﾞｲﾄ ﾉ ﾌｺﾞｳﾅｼ ｽｳﾁ				 */
};
typedef	union mfkey	MFKEY;
/*********************************************************************/
/*	MFBINF	Cﾀｲﾌﾟ  ﾌﾞﾛｯｸ ｺﾃｲ ｼﾞｮｳﾎｳ 								 */
/*********************************************************************/
struct	mfbinf {
	short	mfbuscnt;			/*	ｼﾖｳ ﾊﾞｲﾄｽｳ						 */
	short	mfbkcnt;			/*	ｶｸﾉｳ ｷｰｽｳ						 */
	long	mfbovern;			/*	ｵｰﾊﾞｰﾌﾛｰ ﾌﾞﾛｯｸ ﾊﾞﾝｺﾞｳ			 */
};
typedef	struct mfbinf	MFBINF;
/*********************************************************************/
/*	MFVINF	EOF ｼﾞｮｳﾎｳ ｶｸﾉｳ ﾊﾞｯﾌｧ  (ｸﾘｶｴｼ ﾌﾞﾌﾞﾝ)					 */
/*********************************************************************/
struct	mfvinf {
	long	mfvfmtn;			/*	FMT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ					 */
	long	mfveof;				/*	EOF ｲﾁ (ﾌｧｲﾙ ﾉ ｾﾝﾄｳ ｶﾗﾉ ｵﾌｾｯﾄ)	 */
};
typedef	struct mfvinf	MFVINF;

/*********************************************************************/
/*	MFGKEY	 ｼﾞｮｳﾎｳ ｶｸﾉｳ ﾊﾞｯﾌｧ										 */
/*********************************************************************/
struct	mfgkey {
	long	mfgkof;				/*	ｷｰ ﾅｲ ｵﾌｾｯﾄ (ｷｰ ﾅｲｾﾝﾄｳ ｶﾗﾉ ｵﾌｾｯﾄ)*/
	long	mfgklen;			/*	ｷｰ ﾁｮｳ							 */
};
typedef	struct mfgkey	MFGKEY;

/*********************************************************************/
/*	ﾃｲｽｳ ﾉ ﾃｲｷﾞ 													 */
/*********************************************************************/
#ifndef	MFNULL
#define	MFNULL		0			/*	NULL ﾉ ﾃｲｷﾞ						 */
#endif
#define	MFMAXLEN	32767L		/*	FIP ﾉ ｻｲﾀﾞｲｱｸｾｽｻｲｽﾞ				 */
#define	MFZERO		0L			/*	0 ﾉ ﾃｲｷﾞ						 */
#define	MFONE		1L			/*	1 ﾉ ﾃｲｷﾞ						 */
#define	MFFOUR		4L			/*	4 ﾉ ﾃｲｷﾞ						 */
#define	MFEIGHT		8L			/*	8 ﾉ ﾃｲｷﾞ						 */
#define	MFTWOF		24L			/*	24 ﾉ ﾃｲｷﾞ						 */
#define	MFFOT		512L		/*	512 ﾉ ﾃｲｷﾞ						 */
#define	MFPATHLEN	80L			/*	ﾊﾟｽﾒｲ ﾉ ｻｲﾀﾞｲ ｻｲｽﾞ				 */

/*********************************************************************/
/*	mf_rchk ｺﾕｳ ﾉ define ﾁ											 */
/*********************************************************************/
#define	MFOTHER		'0'			/*	ｾﾝﾕｳ ｲｶﾞｲ ﾉ ﾁｪｯｸ 				 */
#define	MFENQ		'1'			/*	ｾﾝﾕｳ ｼｹﾞﾝ ﾁｪｯｸ					 */
#define	MFTRNUM		1L			/*	ﾃｰﾌﾞﾙ ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ				 */
#define	MFFRNUM		2L			/*	ﾌｧｲﾙ ｼｹﾞﾝ ﾊﾞﾝｺﾞｳ 				 */

/*********************************************************************/
/*	mf_reqc ｺﾕｳ ﾉ define ﾁ											 */
/*********************************************************************/
#define	MFREQCR		'r'			/*	ﾖﾐｺﾐ,ｻｰﾁ  ﾉ ﾁｪｯｸ 				 */
#define	MFREQCW		'w'			/*	ｶｷｺﾐ,ｺｳｼﾝ ﾉ ﾁｪｯｸ 				 */

/*********************************************************************/
/*	mf_fopn ｺﾕｳ ﾉ define ﾁ											 */
/*********************************************************************/
#define	MFACNRED	0x00000002	/*	ﾖﾐｺﾐ ﾃﾞ ﾂｳｼﾞｮｳ ﾓｰﾄﾞ				 */
#define	MFACNWRT	0x0000000E	/*	ｶｷｺﾐ ﾃﾞ ﾂｳｼﾞｮｳ ﾓｰﾄﾞ				 */
#define	MFACHRED	0x00000042	/*	ﾖﾐｺﾐ ﾃﾞ ﾊｲﾀ ﾓｰﾄﾞ				 */
#define	MFACHWRT	0x0000004E	/*	ｶｷｺﾐ ﾃﾞ ﾊｲﾀ ﾓｰﾄﾞ				 */

/*********************************************************************/
/*	ｼｹﾞﾝﾊﾞﾝｺﾞｳ ﾆ ｶﾝｽﾙ define ﾁ										 */
/*********************************************************************/
#define	MFRTABLE	0x00008000	/*	ﾃｰﾌﾞﾙ ﾌｧｲﾙ ｼｷﾍﾞﾂ ﾋﾞｯﾄ			 */

/*********************************************************************/
/*	oscreat  ﾌｧｲﾙ ｿﾞｸｾｲ ﾌﾗｸﾞ define ﾁ								 */
/*********************************************************************/
#define	MFCREAT		0x201FFFFF	/*	ﾌｧｲﾙ ｿﾞｸｾｲ ﾌﾗｸﾞ 				 */

/*********************************************************************/
/*	mf_tjud ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ										 */
/*********************************************************************/
#define	MFHIT		 0L			/*	ｹﾝｻｸ ｼﾞｮｳｹﾝ ｦ ﾏﾝｿﾞｸｽﾙ			 */
#define	MFNON		-1L			/*	ｹﾝｻｸ ｼﾞｮｳｹﾝ ｦ ﾏﾝｿﾞｸｼﾅｲ			 */

/*********************************************************************/
/*	mf_fksh ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ										 */
/*********************************************************************/
#define	MFOVFLOW	-99L		/*	ｲｺｳ ﾉ ｵｰﾊﾞﾌﾛｰﾌﾞﾛｯｸ ﾆ ｿﾝｻﾞｲ		 */
								/*	ｽﾙ ｶﾉｳｾｲ ｶﾞ ｱﾙ					 */

/*********************************************************************/
/*	mf_fwpc ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ										 */
/*********************************************************************/
#define	MFFCKEY		(long)'K'	/*	ｷ- ﾉ ｶｸﾉｳ						 */
#define	MFFCDATA	(long)'D'	/*	ﾃﾞ-ﾀ ﾉﾐ ﾉ ｶｸﾉｳ					 */
#define	MFFCNEXT	(long)'N'	/*	ﾂｷﾞ ﾉ ﾌﾞﾛｯｸ ﾊﾞｯﾌｧ ﾖｳｷｭｳ			 */

/*********************************************************************/
/*	mf_tcck ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ										 */
/*********************************************************************/
#define	MFIVOFF		-1L			/*	ｷｰ ｵﾌｾｯﾄ ﾌﾄｳ					 */
#define	MFIVLEN		-2L			/*	ｷｰ ﾁｮｳ ﾌﾄｳ						 */
#define	MFIVATR		-3L			/*	ｷｰ ｿﾞｸｾｲ ﾌﾄｳ					 */
#define	MFIVOPR		-4L			/*	ｹﾝｻｸ ｴﾝｻﾞﾝｼ ﾌﾄｳ					 */
#define	MFIVPACK	-5L			/*	ﾕｳｺｳ ﾅ ﾊﾟｯｸ ﾃﾞｰﾀ ﾃﾞ ﾅｲ			 */
#define	MFIVKEYX	-6L			/*	ｹﾝｻｸ ｷｰ ﾌﾄｳ						 */

/*********************************************************************/
/*	mf_fpck ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ 									 */
/*********************************************************************/
#define MFALLFIL	1L			/*	ｾﾞﾝ ｸﾞﾙｰﾌﾟ ﾌｧｲﾙ ｼﾃｲ				 */
#define MFGRPFIL	2L			/*	ｸﾞｰﾌﾟﾅｲ ｾﾞﾝ ﾌｧｲﾙ ｼﾃｲ			 */
#define MFSUBFIL	3L			/*	ｻﾌﾞ ｸﾞﾙｰﾌﾟ ﾅｲ ｾﾞﾝ ﾌｧｲﾙ ｼﾃｲ		 */
#define MFONEFIL	4L			/*	ﾌｧｲﾙ ｼﾃｲ 						 */

/*********************************************************************/
/*	mf_vfck ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ 									 */
/*********************************************************************/
#define MFNOVMT		-1L			/*	ｶﾞｲﾄｳ ﾎﾞﾘｭｰﾑ ﾉ ﾌｧｲﾙ ﾃﾞﾅｲ		 */
#define MFNOFIP		-2L			/*	FIP ｶﾝﾘ ｶﾞｲ						 */
#define MFNOEXT		-3L			/*	ﾌｧｲﾙ ﾐｿｳｾｲ						 */

/*********************************************************************/
/*	mf_bchk ﾉ ﾍﾝｷｬｸﾁ ﾉ define ﾁ										 */
/*********************************************************************/
#define	MFBON		1L			/*	ｼﾃｲ ﾋﾞｯﾄ ﾊ ON					 */
#define	MFBOFF		0L			/*	ｼﾃｲ ﾋﾞｯﾄ ﾊ OFF					 */

/*********************************************************************/
/*	ｶﾞｲﾌﾞ ﾍﾝｽｳ ﾘﾖｳｲｷ												 */
/*********************************************************************/
extern	MFPCB		*mfpcbp;	/*	ﾌﾟﾛｾｽ ｼﾞﾖｳﾎｳｶﾝﾘ ﾌﾞﾛﾂｸ			 */
extern	MFZCB		*mfzcbp;	/*	ｶﾘｺｳｼﾝ ｼｹﾞﾝｶﾝﾘ ﾌﾞﾛｯｸ 			 */
extern	MFQCB		*mfqcbp;	/*	ｼｹﾞﾝｾﾝﾕｳﾖｳｷｭｳ ｶﾝﾘﾌﾞﾛｯｸ			 */
extern	PSCPSECT	pscparea;	/*	PSECT ﾘｮｳｲｷ						 */

/*********************************************************************/
/*	ﾃｰﾌﾞﾙ ｱﾄﾞﾚｽ ﾉ ﾃｲｷﾞ												 */
/*********************************************************************/
#define	MFPCMADT	pscparea.psccmadt	/*	CM ADT ﾎﾟｲﾝﾀｰ			 */
#define	MFPLMADT	pscparea.psclmadt	/*	LM ADT ﾎﾟｲﾝﾀｰ			 */
#define	MFPVMTP		mfpcbp->mfpvmtp		/*	VMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPGMTP		mfpcbp->mfpgmtp		/*	GMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPSGTP		mfpcbp->mfpsgtp		/*	SGT ﾎﾟｲﾝﾀｰ				 */
#define	MFPFMTP		mfpcbp->mfpfmtp		/*	FMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPKMTP		mfpcbp->mfpkmtp		/*	KMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPWMTP		mfpcbp->mfpwmtp		/*	WMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPEMTP		mfpcbp->mfpemtp		/*	EMT ﾎﾟｲﾝﾀｰ				 */
#define	MFPEXTP		mfpcbp->mfpextp		/*	EXT ﾎﾟｲﾝﾀｰ				 */
#define	MFPPVTP		mfpcbp->mfppvtp		/*	PVT ﾎﾟｲﾝﾀｰ				 */
#define	MFPERTP		mfpcbp->mfpertp		/* TERT ｱﾄﾞﾚｽ			TD59 */
#define	MFPMRTP		mfpcbp->mfpmrtp		/* TMRT ｱﾄﾞﾚｽ			TD22 */
#define	MFPMTCBP	mfpcbp->mfpmtcbp
								   /* ﾃｰﾌﾞﾙ用資源管理ﾌﾞﾛｯｸｱﾄﾞﾚｽ TD59 */
#define	MFPMFCBP	mfpcbp->mfpmfcbp
								   /* ﾌｧｲﾙ用資源管理ﾌﾞﾛｯｸｱﾄﾞﾚｽ  TD59 */
#define	MFPOCBP		mfpcbp->mfpocbp		/*ﾌｧｲﾙ操作管理ﾌﾞﾛｯｸｱﾄﾞﾚｽTD30 */
																  /*%*/
/*********************************************************************/
/*	PSECT ﾅｲ LOG ｼｭﾄｸ ﾖｳ/ﾋ ｱﾄﾞﾚｽ ﾉ ﾃｲｷﾞ < =0 LOG ｼｭﾄｸ ﾌﾖｳ > 		 */
/*********************************************************************/
#define	MFWLOG		pscparea.pscobsad	/* LOGｼｭﾄｸ ﾖｳ/ﾋ ｱﾄﾞﾚｽ		 */
										/*		ST1672				 */

/*********************************************************************/
/*	ﾌﾟﾛｾｽ ｱﾎﾞｰﾄ ﾉ ﾊﾟﾗﾒﾀ ﾉ ﾃｲｷﾞ										 */
/*********************************************************************/
#define	MFABLERR	0x10000000	/*	ｼｮｳｻｲ ｺｰﾄﾞ						 */
								/*	ｱﾎﾞｰﾄ ｺｰﾄﾞ						 */
#define	MFABFFFB	0x1A0C		/*	mf_fffb 					TD49 */
#define	MFABTFTB	0x1A86		/*	mf_tftb 					TD49 */
#define	MFABRFQB	0x1B8B		/*	mf_rfqb						TD49 */
#define	MFABBFRE	0x1A6A		/*	mf_bfre 					TD49 */
#define	MFABBCLR	0x1A6B		/*	mf_bclr 					TD49 */
#define	MFABBRMV	0x1A6E		/*	mf_brmv 					TD49 */
#define	MFABCRND	0x196B		/*	mf_crnd 					TD49 */
#define	MFABCFZB	0x196D		/*	mf_cfzb						TD49 */
#define	MFABCFDB	0x196F		/*	mf_cfdb 					TD49 */
#define	MFABFCHK	0x1A0A		/*	mf_fchk 					TD49 */
#define	MFABSRVW	0x1805		/*	mf_srvw 					TD49 */
#define	MFABSRMF	0x1812		/*	mf_srmf 					TD49 */
#define	MFABFSRR	0x1A22		/*	mf_fsrr 					TD49 */
#define	MFABVJFE	0x194D		/*	mf_vjfe 						 */
#define	MFABVRFE	0x194E		/*	mf_vrfe 						 */
#define	MFABVRND	0x1954		/*	mf_vrnd 						 */
#define	MFABFRRS	0x1A4D		/*	mf_frrs 					TD49 */
#define	MFABFRKY	0x1A4F		/*	mf_frky 					TD49 */
#define	MFABWRCM	0x198B		/*	mf_wrcm 					TD49 */
#define	MFABDRCV	0x1FC5		/*	mf_drcv 						 */
#define	MFABDRMS	0x1FC8		/*	mf_drms 						 */
#define	MFABFCRT	0x1904		/*	mf_fcrt 					TD49 */
#define	MFABFRMV	0x1905		/*	mf_frmv 					TD49 */
#define	MFABZEND	0x1B02		/*	mf_zend 					TD49 */
#define	MFABFFOP	0x1E01		/*	mf_ffop						TD49 */
#define	MFABFFCL	0x1E02		/*	mf_ffcl						TD49 */

/*#define	MFABVGLS	0x1907	*/	/*	mf_vgls 					 */

/*********************************************************************/
/*	FIP ﾅｲ ﾏｸﾛ ﾃｲｷﾞ 												 */
/*********************************************************************/
#define	MFRNOCRT(p1)   (p1 << 16)			/*	ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｻｸｾｲ 	 */
#define	MFRMAIN(p1)	   (p1 >> 16)
#define	MFRSUB(p1)	   (p1 & 0x0000FFFFL)
#define	MFTBLAD(p1,p2) (p2 ? (char *)p1 + sizeof(TCOMPAT) \
										+ (unsigned char)(p1->tcomsbps) \
										+ (p1->tcomprsl * (p2 - 1)) \
						   : (char *)p1 + sizeof(TCOMPAT)) 

											/*	ﾃｰﾌﾞﾙｱﾄﾞﾚｽ	TC1965   */
#define	MFRPSZNO(p1)	(p1 & 0x00007FFFL)	/*	ﾃｰﾌﾞﾙｼｹﾞﾝﾊﾞﾝｺﾞｳｺﾍﾞﾂﾌﾞ*/
#define	MFBITON(p1,P2)	(p1 |= P2)			/*	ﾋﾞﾂﾄ ｵ ON ﾆ ｽﾙ		 */
#define	MFBITOFF(p1,P2)	(p1 &= ~(P2))		/*	ﾋﾞﾂﾄ ｵ OFF ﾆ ｽﾙ 	 */
											/*	ROS ﾉ ｼｽﾃﾑｺｰﾙ ｴﾗｰ	 */
#define MFOSERR(p1,p2) (pscparea.pscoseki = p1, \
						pscparea.pscosede = p2)
#define	MFCHKON		1
#define	MFCHKOFF	0
#define	MFENQCHK(p)		if ( p == MFCHKON ) {					\
							MFBITON(mfpcbp->mfpstat,MFPECHK);	\
						}										\
						else {									\
							MFBITOFF(mfpcbp->mfpstat,MFPECHK);	\
						}
											/*S 87-12-28	STC536	 */
long	mc_clea();
long	mc_ccpy();
#define MC_COPY(p1,p2,p3)	mc_clea(p2,0x00,p3); \
							mc_ccpy(p1,p2,p3);
											/*E 87-12-28	STC536	 */
#define	MFPU0		0x00					/* Ｐｕ番号０		TD06 */
#define	MFPU1		0x01					/* Ｐｕ番号１		TD06 */
#define	MFSPPU		0x01000000	/* ｾﾏﾌｫ識別子  装置内Ｐｕ番号   TD59 */
#define	MFSETVMT(p1)	( mfpcbp->mfpvmtno = p1 )
							/* SCSIﾘｾｯﾄ用TVMTｴﾝﾄﾘ番号設定用ﾏｸﾛ  TD61 */
#define MFFILDES	1			/* SCSIﾘｾｯﾄ時ﾌｧｲﾙ記述子指定 	TD61 */
#define MFTVMTNO	2			/* SCSIﾘｾｯﾄ時TVMTｴﾝﾄﾘ番号指定 	TD61 */
