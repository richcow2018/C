/****************************************/
/*	ＭＯＪコンスタント情報				*/
/****************************************/
#define	REGIST	0x01
#define	COMMSG	0x02
#define	PSCOM	"ps -a -eo %s | grep %d"
#define	ENDREQ	0x10000600
#define	ENDCODE	1
#define	RCVCODE	0

/************************************/
/*	モジュールＩＤ					*/
/************************************/
#define		MOTRANS		0x1620
#define		MOMKQ		0x1621
#define		MOMSGRCV	0x1622
#define		MOPROCMS	0x1623
#define		MOMBMS		0x1624
#define		MOENDTR		0x1625


/************************************/
/*	詳細コード１					*/
/************************************/
#define		LDMSCTLE	0x10000000
#define		LDFRBFR		0x11000000
#define		LDFRBFS		0x12000000
#define		LDFRBFC		0x13000000
#define		LDNTOK		0x14000000
#define		LDMSGETO	0x15000000
#define		LDMSCTLM	0x16000000
#define		LDMSGETM	0x17000000
#define		LDOPEN		0x18000000
#define		LDWRITE		0x19000000
#define		LDCLOSE		0x20000000
#define		LDGTBFR		0x21000000
#define		LDGTBFS		0x22000000
#define		LDGTBFC		0x23000000
#define		LDRCVRP		0x24000000
#define		LDRCVRM		0x25000000
#define		LDANYRL		0x26000000
#define		LDCPUT		0x27000000
#define		LDCEDT		0x28000000
#define		LDPOPEN		0x29000000
#define		LDFGETS		0x30000000
#define		LDPCLSE		0x31000000
#define		LDMSSND		0x32000000

/************************************/
/*	詳細コード２					*/
/************************************/
#define		DECODE2		0x00000000
