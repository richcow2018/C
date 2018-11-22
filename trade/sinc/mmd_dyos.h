/****************************************************************************/
/*																			*/
/*	動的システム変更														*/
/*																			*/
/* Created:																	*/
/*	95.10.09 K.Kubota SSCY0118: OSP Process cooperation release				*/
/*																			*/
/* Update history:															*/
/*																			*/
/****************************************************************************/

										/* ###SSCY0118 Start				*/
#ifdef TEST1011
#define TYPOSP			"F2"			/* OSPﾌﾟﾛｸﾞﾗﾑ種別					*/
#else
#define TYPOSP			"9E"			/* OSPﾌﾟﾛｸﾞﾗﾑ種別					*/
#endif

/****************************************/
/* 対OSPﾌﾟﾛｾｽ電文(MIA持ち回り形式)		*/
/****************************************/
/****************************************/
/* 共通部 16B							*/
/****************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
#define MMIFOSP1		0x79A00051		/* 排他区間設定要求通知(OSP)		*/
#define MMIFOSP3		0x79A00052		/* 排他区間解除要求通知(OSP)		*/
	long				reqid;			/* 要求識別子						*/
	long				rsv[2];			/* 予備								*/
}						DYOS_KYO;

/****************************************/
/* 要求電文全体の構造 88+16=104B		*/
/****************************************/
typedef struct
{
	MCMIKYO				mia;			/* MIA共通部						*/
#define MMMKOSP			0x030E0000		/* mmd <---> mia [OSP]				*/
	DYOS_KYO			ospkyo;			/* 回線情報共通部					*/
}						OSPMSG;
#define MMOSPSIZ		sizeof(OSPMSG)

/************************************/
/* 応答電文の構造 16B				*/
/************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
#define MMIFOSP2		0x00f30001		/* 排他区間設定応答通知(OSP)		*/
#define MMIFOSP4		0x00f30002		/* 排他区間解除応答通知(OSP)		*/
	long				reqid;			/* 要求識別子						*/
	long				rsv[2];			/* 予備								*/
}						DYOS_RSP;
										/* ###SSCY0118 End					*/
