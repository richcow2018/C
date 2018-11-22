/****************************************************/
/* meio.h		����I/O���̴ؿ�͎����ގ̎�����				*/
/* 1994.12.19	�����ԡ�������						*/
/*													*/
/* 1995.07.06   �����ԡ���ƣͳ��				 M01*/
/*				�ֵ����Ѵ��ơ��֥뤬��Ū(static)�ʤ�*/
/*				����Τ����Ĥˤʤ�褦���ѹ�����	*/
/*				���Τϡ�me_pint()���������Ƥ��롣	*/
/*				�ơ��֥�����͡ʎ��׎�������)��meiort.h*/
/*				���������Ƥ��롣					*/
/*				��Ϣ�ξ����ɼ��ST2911				*/
/* 1995.07.18   �����ԡ���ƣͳ��				 M02*/
/*				LICPMESS��¤�Τ��ѹ�����ȯ�����ȎȎ���	*/
/*				���ơ�AP�؎������ļ��̻Ҥ��ɲá��Ĥ��Ǥ� */
/*				ͽ���ˣ��Х��ȤȤäȤ�				*/
/*				AP�؎������ļ��̻Ҥ��ɲä�����ͳ�ϡ��ɤ� */
/*				LICP����Τɤ��׵���Ф���꥿����*/
/*				�狼��ʤ��Ȥ����Զ��Τ��ᡣ		*/
/*				��Ϣ�ξ����ɼ��ST2772				*/
/* 1996.02.08 	�����ԡ��Ķ�Ź�����Îѡʿ�ƣͳ����	 M03*/
/*				4W on X.25�Ύ��Îݎ����ݤΥ��ޥ�ɼ��̤�  */
/*				0x05����0x06���ѹ�����				*/
/*				��Ϣ�ξ����ɼ��ST4004				*/
/* 1996.01.08   �����ԡ���ƣͳ��				 M04*/
/*				��Ϣ�����ѹ��׵��SSCY0121		*/
/*				���ޥ��[IRT��ȯ��]���ɲä���		*/
/*				���������ºݤ˥��ޥ�ɤȤ������ꤵ��*/
/*				�ƻ��ѤϤ���ʤ���					*/
/* 1996.02.26   �����ԡ���ƣͳ��				 M05*/
/*				�ξ����ɼ��ST4073					*/
/*				4W on X.25�Ύ��Îݎ����ݤΥ��ޥ�ɼ��̤�  */
/*				0x06����0x05���᤹					*/
/* 1997.04.30   �����ԡ���������				 M06*/
/*				�ξ����ɼ��ST4666					*/
/*				4W-NTM on X.25��Ʊ���ü�ե����룲��*/
/*				���ͥ��Ƚ����ν����ˤ���ѿ�����ɲ�*/
/* 1997.08.18   �����ԡ���������				 M07*/
/*				�ξ����ɼ��ST4880					*/
/* 				��Ʊ�������׵�����������ѹ�		*/
/* 2003.02.25   �����ԡ���������				 M08*/
/* 				Linux�ܿ���ȼ������					*/
/****************************************************/
#include "meiort.h"		/* return code  		 M01*/

/* ���ϥ�å���������Ĺ	*/
#define	LENMAX	4096

/* �쥹�ݥ��Ԥ������޺�����	*/
#define	TIMMAX	127

/* LICP�׵�ɣ�	*/
#define	REQMSGID	0x01110000

/* ��å����������� */
#define	MSGTREQ	0x01	/* �׵�	*/
#define	MSGTFIN	0x02	/* ��λ	*/
#define	MSGTNOT	0x03	/* ����	*/	

/* �ե��󥯥���󥿥���	*/
#define	FNCTOPN	0x01	/* �����ץ�	*/
#define FNCTCLS	0x02	/* ������	*/
#define	FNCTRED 0x03	/* �꡼��	*/
#define	FNCTWRT 0x04	/* �饤��	*/
#define	FNCTCNT 0x05	/* ���ݎĎێ���	*/
#define	FNCTSNS 0x06	/* ����	*/

/* �����̎ߎێĎ���(GW����褬�ɤ��ʤäƤ��뤬)	*/
#define	GWARVPRK	0x00	/* GW���׎��ʎގ�		*/
#define TCPIPPRK	0x01	/* TCP/IP		*/
#define	HDLCLPRK	0x02	/* HDLC�َ��̎�		*/
#define	L4WIOPRK	0x03	/* 4W			*/

/* ��å����������Ԥ���碌��������	*/
/* 180000 = ��ʬ */
/* �����������Ǥ����ͤ����ꤹ��Τϴְ㤤�����Τ�ʤ� */
/* �ʥ����ƥॳ����ΰ��������äƤ��롩�� */
#define	RCVMSTIM	180000

#ifndef	PINT
extern long **lstrs; 		/* 95.07.06 extern ���ѹ�		 M01*/
#endif
/* �̣ɣãХ�å������衡����	*/

struct licpmess {
	long	mesid;			/* �Ҏ��������޼��̻�						*/
	long	dataadr;		/* �Îގ����ʎގ��̎����Ў��Ďގڎ�				*/
	short	datbufsize;		/* �Îގ����ʎގ��̎���������					*/
	short	mestype;		/* �Ҏ��������ގ����̎�						*/
	short	functype;		/* �̎��ݎ������ݎ����̎�						*/
	char	mesresinfo;		/* �Ҏ��������޾ܺپ���/�ڎ��Ύߎݎ�����		*/
	char	reswaitime;		/* �ڎ��Ύߎݎ��Ԥ������ώ���					*/
	long	meslink;		/* �Ҏ��������ގ؎ݎ���						*/
	long	passid;			/* �ʎߎ�ID							*/
	long	retcode;		/* �؎����ݎ����Ď�							*/
	long	promailid;		/* �ֿ��ю̎ߎێ������̻�/�Ҏ��َΎގ��������̻�	*/
	long	ap_reqid;		/* AP�؎������ļ��̻�				 M02*/
	long	yobi1;			/* ͽ��							 M02*/
};
typedef struct licpmess LICPMESS;

/* �̣ɣãХǡ����Хåե��衡����	*/

						/* �׵ᡡ�����ѥ������ץ󡡣ء�����		*/
struct datayopx1 {
	char	hcid;			/* ȯ��Ƽ��̻�						*/
	char	passno;			/* �����ʎߎ��ֹ�						*/
	short	maxdata;		/* ����ʬ��Îގ���Ĺ					*/
	char	winsize;		/* �����ݎĎގ���������						*/
	char	yob1;			/* �؎��ގ��̎�							*/
	char	prtclid;		/* protocol id						*/
	char  lineif;     /* GW lineno & line kind	*/
	union {
		char secadr;	/* 2jikyoku address					*/
		long ipadr;		/* IP address						*/
		} adr;
	short	yob2;			/* �؎��ގ��̎�							*/
	long	yob3;			/* �؎��ގ��̎�							*/
};
typedef struct datayopx1 DATAYOPX1;
							/* ���юÎގ�����						*/
struct datayopx2 {
	short	calll;			/* call user data chou(24byte(0x18))*/
	char	year[2];		/* year(1950-2049),year[0]=19or20	*/
	char	month;			/* month							*/
	char	day;			/* day								*/
	char	week;			/* week(00=sun,01=mon,.....06=sat)	*/
	char	hour;			/* hour								*/
	char	minuet;			/* minuet							*/
	char	second;			/* second							*/
	char	gwproto;		/* chuukei class					*/
	char	gwlno;			/* GW kaisen bangou					*/
	char	dummy[2];		/* dummy							*/
	long	portnum;		/* tanmatsu local adress			*/
	long	tsopt;			/* tekiyou system option			*/
	long	yobi;			/* yobi(ALL 0x00)					*/
	char	yob3[200];		/* �؎��ގ��̎�							*/
	long	x25head;		/* X.25�͎����ް�						*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayopx2 DATAYOPX2;


						/* �׵ᡡ�����ѥ������ץ󡡣̣���		*/
struct datayopl {
	char	hcid;			/* ȯ��Ƽ��̻�						*/
	char	passno;			/* �����ʎߎ��ֹ�						*/
	short	maxdata;		/* ����ʬ��Îގ���Ĺ					*/
	char	winsize;		/* �����ݎĎގ���������						*/
	char	yob1;			/* �؎��ގ��̎�							*/
	short	yob2;			/* �؎��ގ��̎�							*/
	long	desequno;		/* ��������ֹ�(TCP�Ύߎ����ֹ�)		*/
	char	yob3[16];		/* �؎��ގ��̎�							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayopl DATAYOPL;
#define DATAYOPLSIZE 34		/* Linux�ܿ���ȼ������			 M08*/

						/* �׵ᡡ�����ѥ����������ء�����		*/
struct datayclx {
	char	yob1[8];		/* �؎��ގ��̎�							*/
	long	x25head;		/* X.25�͎����ް�						*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct datayclx DATAYCLX;

						/* �׵ᡡ�����ѥ����������̣���		*/
struct dataycll {
	char	yob1[16];		/* �؎��ގ��̎�							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSG CHN							*/
	char	lpn;			/* LPN								*/
};
typedef struct dataycll DATAYCLL;
#define DATAYCLLSIZE 22		/* Linux�ܿ���ȼ������			 M08*/


						/* �׵ᡡ�ǡ����񤭹��ߡ��ء�����		*/
struct dataywtx {
	long	x25head;		/* X.25�͎����ް�						*/
	char	msgchn;			/* MSG CHN							*/
	char	dtl;			/* DTL								*/
	char	sqn;			/* SQN								*/
	char	lpn;			/* LPN								*/
							/* �Îގ�����							*/
};
typedef struct dataywtx DATAYWTX;

						/* �׵ᡡ�ǡ����񤭹��ߡ��̣���			*/
struct dataywtl {
	char	yob1[16];		/* �؎��ގ��̎�							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	sqn;			/* SQN								*/
	char	lpn;			/* LPN								*/
							/* �Îގ�����							*/
};
typedef struct dataywtl DATAYWTL;

						/* �׵ᡡ�ǡ����ɤ߹��ߡ��ء�����		*/
						/* �׵ᡡ�����ѥ����桡���ء�����		*/
						/* ��λ���ǡ����ɤ߹��ߡ��ء�����		*/
struct datayrdx {
	long	x25head;		/* X.25�͎����ް�						*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	lpn;			/* LPN								*/
};
typedef struct datayrdx DATAYRDX;
typedef struct datayrdx DATAYCTX;
typedef struct datayrdx DATAKRDX;

						/* �׵ᡡ�ǡ����ɤ߹��ߡ��̣���			*/
						/* �׵ᡡ�����ѥ����桡���̣���			*/
						/* ��λ���ǡ����ɤ߹��ߡ��̣���			*/
struct datayrdl {
	char	yob1[16];		/* �؎��ގ��̎�							*/
	long	length;			/* length							*/
	char	msgchn;			/* MSGCHN							*/
	char	dtl;			/* DTL								*/
	char	lpn;			/* LPN								*/
};
typedef struct datayrdl DATAYRDL;
typedef struct datayrdl DATAYCTL;
typedef struct datayrdl DATAKRDL;

struct fwcf {
	char cmdk;				/* ���ޥ�ɼ���						*/
	char ionb;				/* I/O�ֹ�							*/
	char snsrty;			/* ���󥹲��						*/
	char cmdinf;			/* ���ޥ�ɾ���						*/
	char etbtx;				/* ETB/ETX����						*/
	char fuka;				/* �ղþ���							*/
	short attim;			/* ATT�Ԥ�������					*/
	short rsv1;				/* ͽ��								*/
	short dtsz;				/* �����ǡ���������					*/
};
typedef struct fwcf FWCF;

/* ���ף��ء��������ޥ�ɼ���		*/
#define	WCCS	0x10		/* �ף�								*/
#define CCCS	0x11		/* �ã�								*/
#define RCCS	0x12		/* �ң�								*/
#define SCCS	0x13		/* �ӣ�								*/
#define ATCS	0x05		/* ���ԣ�					 M03 M05*/

/* ���ף��ء��������󥹲��		*/
#define SNSRTY	3			/* ���󥹲��						*/

/* ���ף��ء�������ETB/ETX����	*/
#define ETB		0x17		/* ETB								*/
#define ETX		0x03		/* ETX								*/

struct head {                           /*  �̿��إå��ե����ޥå� by kaori	*/
    short   pretcode;                   /*  �ץ�ȥ���꥿���󥳡���        */
    short   pretspcd;                   /*  �ץ�ȥ���ܺ٥꥿���󥳡���    */
    char    ctype;                      /*  ���ޥ�ɼ���                    */
    char    ionum;                      /*  �ɡ����ֹ�                      */
    char    resinf;                     /*  �쥹�ݥ󥹾���                  */
    char    etbetx;                     /*  ETB/ETX����                     */
    short   datasize;                   /*  �����ǡ���������                */
};
typedef struct head HEAD;

#define WWC 0x10
#define WCC 0x11
#define WRC 0x12
#define WSC 0x13
#define WAT 0x05						/* ���Îݎ����ݤΥ��ޥ�ɼ���		 M03 M05*/
#define IRC 0x20						/* IRT��ȯ�ԡ��ɲ�				 M04*/

struct s4wnox {
	short	pathno;						/* �����ѥ��ֹ�						*/
	short	lgln;						/* LCGN+LCN�ֹ�						*/
	char	*facp;						/* TFAC���Ďގڎ�						*/
};
typedef struct s4wnox S4WNOX;

struct s4wnop {
	long	fd;							/* �ե����뵭�һ�				 M06*/
	short	pathno;						/* �����ѥ��ֹ�					 M06*/
	short	yobi1;						/* ͽ����						 M06*/
};
typedef struct s4wnop S4WNOP;

#define	S4WNN	2						/* 4W-NTMonX25���Ȏ������ݿ�			M06	*/
#define	S4WHD	2						/* 4W-NTMonX25��Ʊ�������׵��	M07 */


