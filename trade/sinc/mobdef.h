/****************************************************************************/
/*	予備系監視プロセス　ｄｅｆ　定義ヘッダー								*/
/****************************************************************************/
/****************************************************************************/
/* 改造番号	：SSLA0023												 		*/
/* 改造内容	：仕様変更対応											 		*/
/* 改造日	：2002.04.25											 		*/
/* 改造者	：Supply	梶原										 		*/
/****************************************************************************/
/************************************/
/*	モジュールID					*/
/************************************/
#define	MO_ACTC		0x1100
#define	MO_GTEV		0x1120
#define	MO_GTAD		0x1121
#define	MO_GTMN		0x1122
#define	MO_GTPN		0x1123
#define	MO_GTPR		0x1124
#define	MO_ASPR		0x1125
#define	MO_CSTS		0x1126
#define	MO_SPST		0x1127
#define	MO_CTBL		0x1128
#define	MO_SPOF		0x1129
#define	MO_MSGMK	0x112A
#define	MO_SSPR		0x112B

/************************************/
/*	詳細コード１					*/
/************************************/
#define	LDACTCA		0x10000000
#define	LDACTCD		0x11000000
#define	LDASPRC		0x12000000
#define	LDASPRT		0x13000000
#define	LDCSTSS		0x14000000
#define	LDGTAD		0x15000000
#define	LDGTEVH		0x16000000
#define	LDGTEVA		0x17000000
#define	LDGTEVS		0x18000000
#define	LDGTEVO		0x19000000
#define	LDGTMNP		0x20000000
#define	LDGTMNF		0x21000000
#define	LDGTPNP		0x22000000
#define	LDGTPNF		0x23000000
#define	LDGTPNS		0x24000000
#define	LDGTPRP		0x25000000
#define	LDGTPRF		0x26000000
#define	LDGTPRS		0x27000000
#define	LDGTPRA		0x28000000
#define	LDSPOFE		0x29000000
#define	LDSPOFP		0x30000000
#define	LDSSPRE		0x31000000
#define	LDSSPRP		0x32000000
#define	LDSSPRT		0x33000000
#define	LDSSPRF		0x34000000
#define	LDSSPRFF	0x35000000
#define	LDASPRF		0x36000000
#define	LDSSPRW		0x37000000			/* SSLA0023 */

/************************************/
/*	詳細コード２					*/
/************************************/
#define	DECODE2		0x00000000

/************************************/
/*	詳細コード３					*/
/************************************/
#define	DECODE3		0x00000000

/************************************/
/*	定数宣言						*/
/************************************/
#define	HVAPSZ		64
#define	SCRIPTSZ	128
#define	NODESZ		64
#define	RSSZ		64
#define	CMDSZ		256
#define	MSGSZ		256
#define	SYSCMD		128
#define	NODE		2
#define	ALLRS		10

#define	SYORIP		0x01
#define	MSGP		0x02
#define	PATHNO		0

#define	DEF			"%s\%c\%s\%c\%s\%s"
#define	DEF2		"%s\%c\%s\%c\%s\%s"
#define DEF3		"%s\%c\%s\%s\%c\%s\%s"
#define	DEF4		"%s\%s\%s\%c\%s\%c\%s\%c\%s\%c\%s"
#define DEF5		"%s\%s\%s\%s\%c\%s"
#define	HVDISP		"hvdisp -a | grep "
#define	HVASSERT	"hvassert -h "
#define	HVDISPR		"hvdisp " 

#define	LOCALSYS	"Local System"
#define	SYSNODE		"SysNode"
#define	ONSCRIPT	"OnlineScript"
#define	GREP		" | grep "
#define	AWK			" | awk "
#define	CMD			"_Cmd_"
#define	P			"'{print $1}'"
#define	P3			"'{print $3}'"
#define	WC			'"'
#define	OPTION		" -s "
#define	NOPRINT		" > /dev/null"
#define	SPACE		' '

#define YOBISTBY	1
#define	YOBIOFF		2

#define	KEIKANERR	"SODE"				/* SSLA0023 */
