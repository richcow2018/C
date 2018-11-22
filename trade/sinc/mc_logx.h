/****************************************************************************/
/* Define struture associated mc_logx,mc_lcxf.('94.01.12 仮提供)			*/
/* ＜ソース修正者名＞						宮  脇　  伸		: SM01		*/
/* ＜ソース修正年月日及び修正ＩＤ＞			'94.02.23    ST1649	: SM01		*/
/****************************************************************************/
typedef struct clogst	MCLOG;
typedef struct plvst	MCPLV;
typedef struct svcbst	MCSVCB;

/****************************************/
/* Log-area structure					*/
/****************************************/
struct clogst{
	char	areaid[4];					/* "CLOG"							*/
	short	lbn;						/* Logical Block Number				*/
	short	dmy1;						/* (dummy)							*/
	unsigned char	lf;					/* Loging Flag						*/
	unsigned char	tf;					/* Time Stamp Flag					*/
	unsigned char	ls;					/* Loging Status					*/
	unsigned char	sq;					/* Seguence							*/
	long	dtsize;						/* Log-data Area Size				*/
	unsigned char	*ldtpt;				/* Log-data Trailer Pointer			*/
	unsigned char	*ldhpt;				/* Log-data header  Pointer			*/
	unsigned char	*ldapt;				/* Log-data Area    Pointer			*/
	long	pid;						/* Proccess ID						*/
	MCLOG	*altpt;						/* Alternate Pointer				*/
	long	dmy2[7];					/* (dummy)							*/
	unsigned char	ldata[4096];		/* Log-data Area					*/
};

/****************************************/
/* Proccess Log Vector structure		*/
/****************************************/
struct plvst{
	char	areaid[4];					/* "PLV"							*/
	unsigned char	lf;					/* Loging Flag						*/
	unsigned char	tf;					/* Time Stamp Flag					*/
	short	logsize;					/* Log-area Size					*/
	MCLOG	*logapt;					/* Log-area A Pointer				*/
	MCLOG	*logbpt;					/* Log-area B Pointer				*/
	MCLOG	*logcpt;					/* Current Log-area Pointer			*/
	MCSVCB	*svcbpt;					/* SVCB Pointer						*/
};

/****************************************/
/* Saving Control Block structure		*/
/****************************************/
struct svcbst{
	char	areaid[4];					/* "SVCB"							*/
	unsigned short	svcbst;				/* SVCB Status						*/
	char	cmode;						/* Creation Mode					*/
	char	dmy1;						/* (dummy)							*/
	char	path[32];					/* Log-file Path name				*/
	long	fd;							/* Log-file fdis					*/
	long	bno;						/* Log-file Size (n block)			*/
	long	rd;							/* Using rd							*/
	long	event;						/* Using Event Number				*/
	long	abort;						/* Using Abort Code					*/
	long	detail;						/* Using Abort Detail Code			*/
	MCLOG	*bufpt;						/* Buffer Pointer of writing		*/
	long	result;						/* Error Result Value				*/
	long	lbnctr;						/* Logical Block Number Counter		*/
	long	posctr;						/* Write Block Position Counter		*/
	long	dmy2[4];					/* (dummy)							*/
};

/****************************************/
/* ｶﾝﾘ ﾌﾞﾛｯｸ ｷｮｳﾂｳﾌﾞ ｺｳｿﾞｳﾀｲ			*/
/****************************************/
struct mclcom {
    unsigned char	filnm[12] ;			/* ﾌｧｲﾙ ｼｷﾍﾞﾂﾓｼﾞ					*/
    long	yymmdd ;					/* ｵｰﾌﾟﾝ ﾈﾝｶﾞｯﾋﾟ					*/
    long	hhmmss ;					/* ｵｰﾌﾟﾝ ｼﾞﾌﾝﾋﾞｮｳ					*/
    long	tmstmp ;					/* ｵｰﾌﾟﾝｼﾞ ﾉ ﾀｲﾑｽﾀﾝﾌﾟ				*/
    unsigned short	blklen ;			/* ﾌﾞﾛｯｸﾁｮｳ							*/
    short	dummy1 ;					/* ﾖﾋﾞ								*/
    long	dummy2 ;					/* ﾖﾋﾞ								*/
    unsigned short	cflags ;			/* ｶﾝﾘﾌﾞﾛｯｸ ﾌﾗｸﾞ					*/
    unsigned short	blkcnt ;			/* ｿｳﾌﾞﾛｯｸｽｳ						*/
    long	dummy3[7] ;					/* ﾖﾋﾞ								*/
} ;

/****************************************/
/* ｶﾝﾘ ﾌﾞﾛｯｸ ﾃﾞｰﾀｴﾚﾒﾝﾄ ｺｳｿﾞｳﾀｲ			*/
/****************************************/
struct mclelm {
    unsigned short	lblkno ;			/* ﾛﾝﾘﾌﾞﾛｯｸﾂｳﾊﾞﾝ					*/
    unsigned short	eflags ;			/* ﾃﾞｰﾀｴﾚﾒﾝﾄﾌﾗｸﾞ					*/
    long	otmstmp ;					/* ｻｲｷｭｳﾛｸﾞ ﾉ ﾀｲﾑｽﾀﾝﾌﾟ				*/
    long	ntmstmp ;					/* ｻｲｼﾝﾛｸﾞ ﾉ ﾀｲﾑｽﾀﾝﾌﾟ				*/
    long	dummy1[5] ;					/* ﾖﾋﾞ								*/
} ;
/****************************************/
/* ﾛｸﾞﾁｭｳｼｭﾂﾌｧｲﾙ ｶﾝﾘﾌﾞﾛｯｸ ｺｳｿﾞｳﾀｲ		*/
/****************************************/
typedef struct {
    struct mclcom	com ;				/* ｷｮｳﾂｳﾌﾞ							*/
    struct mclelm	elmnt;				/* ﾃﾞｰﾀｴﾚﾒﾝﾄ						*/
} MCLCOM ;

/****************************************/
/* ﾛｸﾞﾚｺｰﾄﾞ ｷｮｳﾂｳﾌﾞ						*/
/****************************************/
typedef struct{
    unsigned char	ll ;				/* ﾚｺｰﾄﾞ ﾁｮｳ						*/
    unsigned char	marker ;			/* ﾏｰｶｰ								*/
    unsigned char	fg_id;				/* FG-ID							*/
    unsigned char	rs_id ;				/* ﾖｳｲﾝ ID							*/
    unsigned long	adr ;				/* ｺｰﾙﾓﾄ ｱﾄﾞﾚｽ						*/
    unsigned long	t_stmp ;			/* ﾀｲﾑ ｽﾀﾝﾌﾟ						*/
             long	udat[60] ;			/* ｶﾍﾝｲｷ							*/
} MCLREC ;

/****************************************/
/*  constant							*/
/****************************************/
										/* Loging Status "M" bit			*/
#define	FREEZE	0x00 
#define	AUTO	0x01
#define	DEMAND	0x02
										/* #define ABORT 0x03 を削除    SM01*/
#define	LOST	0x04

										/* Saving Mode						*/
#define	SMINIT	0x0000					/* save mode is init				*/
#define	SMDMND	0x0001					/* demand mode						*/
#define	SMAUTO	0x0002					/* auto mode						*/

#define	CLF_ID	"CLOG-FILE"				/* logfile identifer				*/
#define	SVCB_ID	"SVCB"					/* SVCB identifer					*/

										/* Loging Flags						*/
#define	LFNLOG	0x00					/* loging needless					*/
#define	LFDMND	0x01					/* demand save						*/
#define	LFAUTO	0x02					/* auto save						*/

/****************************************************************************/
/*  System-call Log-ID define('94.01.22)									*/
/****************************************************************************/
#define	CL_BSYS		0x00ff0000			/* osanyrl以外のｼｽﾃﾑｺ-ﾙ発行前		*/
#define	CL_ASYS		0x00ff0001			/* osanyrl以外のｼｽﾃﾑｺ-ﾙ発行後		*/
#define	CL_BANY		0x00ff0002			/* osanyrl発行前					*/
#define	CL_AANY		0x00ff0003			/* osanyrl発行後					*/
#define	CL_WSYS		0x00ff0004			/* 非完了型のｼｽﾃﾑｺ-ﾙ発行			*/
#define	CL_RVSMP	0x00ff000a			/* ＳＭＰ通知受信時					*/
#define	CL_RVNTFY	0x00ff000b			/* ＯＳからの非同期通知受信時		*/
#define	CL_RVMIAMSG	0x00ff0011			/* ＭＩＡ電文受信時					*/
#define	CL_SDMIAMSG	0x00ff0013			/* ＭＩＡ電文送信時					*/
#define	CL_RVCMMSG	0x00ff0110			/* 通信制御要求／応答電文受信時		*/
#define	CL_SDCMMSG	0x00ff0112			/* 通信制御要求／応答電文送信時		*/
#define	CL_RDDT		0x00ff0021			/* osread発行時						*/
#define	CL_WTDT		0x00ff0022			/* oswrite発行時					*/
