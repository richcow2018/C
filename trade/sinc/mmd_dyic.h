/****************************************************************************/
/*																			*/
/*	動的システム変更														*/
/*																			*/
/* Created:																	*/
/*	95.05.30 K.Kubota ST2707: ICP Process cooperation release				*/
/*																			*/
/* Update history:															*/
/*	95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange							*/
/*	95.07.05 K.Kubota ST2909: MMCCHN 128 --> 256							*/
/*																			*/
/****************************************************************************/

										/* ###ST2707 Start					*/
#define TYPICP			"82"			/* ICPﾌﾟﾛｸﾞﾗﾑ種別					*/

/****************************************/
/* 対ICPﾌﾟﾛｾｽ電文(MIA持ち回り形式)		*/
/****************************************/
/****************************************/
/* 回線情報共通部 12B					*/
/****************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
#define MMIFICP1		0x79A00041		/* 排他区間設定要求通知(ICP)		*/
#define MMIFICP3		0x79A00042		/* 排他区間解除要求通知(ICP)		*/
	long				reqid;			/* 要求識別子						*/
	short				CHn;			/* 回線情報個別部有効数				*/
	char				dmy1[2];		/* 予備								*/
}						DYIC_KYO;

/************************************/
/* 回線情報個別部 4B				*/
/************************************/
typedef struct
{
	unsigned char		puno;			/* (c)pu番号						*/
	unsigned char		chno;			/* ﾁｬﾈﾙ番号							*/
	unsigned char		target;			/* 変更対象							*/
										/*  0x01...物理回線					*/
										/*  0x02...論理回線					*/
										/*  0x03...論理ﾊﾟｽ					*/
	unsigned char		type;			/* 処理種別							*/
										/*  0x01...撤去						*/
										/*  0x02...増設						*/
										/*  0x03...属性変更					*/
}						DYIC_KO;

/****************************************/
/* 要求電文全体の構造 88+12+4*128=612B	*/
/****************************************/
typedef struct
{
	MCMIKYO				mia;			/* MIA共通部						*/
#define MMMKICP			0x030E0000		/* mmd <---> mia [ICP]				*/
	DYIC_KYO			icpkyo;			/* 回線情報共通部					*/
#define MMCCHN			256				/* 回線情報最大数 ###ST2909			*/
	DYIC_KO				icpko[MMCCHN];	/* 回線情報個別部					*/
}						ICPMSG;
#define MMICPSIZ		sizeof(ICPMSG)

/************************************/
/* 応答電文の構造 16B				*/
/************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
#define MMIFICP2		0x60002000		/* 排他区間設定応答通知(ICP)		*/ 
#define MMIFICP4		0x60002001		/* 排他区間解除応答通知(ICP)		*/ 
	long				reqid;			/* 要求識別子						*/
	long				result;			/* 結果ｺｰﾄﾞ							*/
	long				detail;			/* 詳細ｺｰﾄﾞ							*/
}						DYIC_RSP;
										/* ###ST2707 End					*/
