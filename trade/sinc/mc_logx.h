/****************************************************************************/
/* Define struture associated mc_logx,mc_lcxf.('94.01.12 ����)			*/
/* �㥽����������̾��						��  �ơ�  ��		: SM01		*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�			'94.02.23    ST1649	: SM01		*/
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
/* ���ݎ� �̎ގێ��� ���������̎� �������ގ�����			*/
/****************************************/
struct mclcom {
    unsigned char	filnm[12] ;			/* �̎����� �����͎ގӎ���					*/
    long	yymmdd ;					/* �����̎ߎ� �Ȏݎ��ގ��ˎ�					*/
    long	hhmmss ;					/* �����̎ߎ� ���ގ̎ݎˎގ���					*/
    long	tmstmp ;					/* �����̎ߎݎ��� �� �����ю����ݎ̎�				*/
    unsigned short	blklen ;			/* �̎ގێ���������							*/
    short	dummy1 ;					/* �֎ˎ�								*/
    long	dummy2 ;					/* �֎ˎ�								*/
    unsigned short	cflags ;			/* ���ݎ؎̎ގێ��� �̎׎���					*/
    unsigned short	blkcnt ;			/* �����̎ގێ�������						*/
    long	dummy3[7] ;					/* �֎ˎ�								*/
} ;

/****************************************/
/* ���ݎ� �̎ގێ��� �Îގ������ڎҎݎ� �������ގ�����			*/
/****************************************/
struct mclelm {
    unsigned short	lblkno ;			/* �ێݎ؎̎ގێ������ʎގ�					*/
    unsigned short	eflags ;			/* �Îގ������ڎҎݎĎ̎׎���					*/
    long	otmstmp ;					/* �����������ێ��� �� �����ю����ݎ̎�				*/
    long	ntmstmp ;					/* �������ݎێ��� �� �����ю����ݎ̎�				*/
    long	dummy1[5] ;					/* �֎ˎ�								*/
} ;
/****************************************/
/* �ێ��ގ����������̎����� ���ݎ؎̎ގێ��� �������ގ�����		*/
/****************************************/
typedef struct {
    struct mclcom	com ;				/* ���������̎�							*/
    struct mclelm	elmnt;				/* �Îގ������ڎҎݎ�						*/
} MCLCOM ;

/****************************************/
/* �ێ��ގڎ����Ď� ���������̎�						*/
/****************************************/
typedef struct{
    unsigned char	ll ;				/* �ڎ����Ď� ������						*/
    unsigned char	marker ;			/* �ώ�����								*/
    unsigned char	fg_id;				/* FG-ID							*/
    unsigned char	rs_id ;				/* �֎����� ID							*/
    unsigned long	adr ;				/* �����َӎ� ���Ďގڎ�						*/
    unsigned long	t_stmp ;			/* ������ �����ݎ̎�						*/
             long	udat[60] ;			/* ���͎ݎ���							*/
} MCLREC ;

/****************************************/
/*  constant							*/
/****************************************/
										/* Loging Status "M" bit			*/
#define	FREEZE	0x00 
#define	AUTO	0x01
#define	DEMAND	0x02
										/* #define ABORT 0x03 ����    SM01*/
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
#define	CL_BSYS		0x00ff0000			/* osanyrl�ʳ��Ύ����Îю�-��ȯ����		*/
#define	CL_ASYS		0x00ff0001			/* osanyrl�ʳ��Ύ����Îю�-��ȯ�Ը�		*/
#define	CL_BANY		0x00ff0002			/* osanyrlȯ����					*/
#define	CL_AANY		0x00ff0003			/* osanyrlȯ�Ը�					*/
#define	CL_WSYS		0x00ff0004			/* ��λ���Ύ����Îю�-��ȯ��			*/
#define	CL_RVSMP	0x00ff000a			/* �ӣͣ����μ�����					*/
#define	CL_RVNTFY	0x00ff000b			/* �ϣӤ������Ʊ�����μ�����		*/
#define	CL_RVMIAMSG	0x00ff0011			/* �ͣɣ���ʸ������					*/
#define	CL_SDMIAMSG	0x00ff0013			/* �ͣɣ���ʸ������					*/
#define	CL_RVCMMSG	0x00ff0110			/* �̿������׵᡿������ʸ������		*/
#define	CL_SDCMMSG	0x00ff0112			/* �̿������׵᡿������ʸ������		*/
#define	CL_RDDT		0x00ff0021			/* osreadȯ�Ի�						*/
#define	CL_WTDT		0x00ff0022			/* oswriteȯ�Ի�					*/
