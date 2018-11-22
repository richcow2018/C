/****************************************************************************/
/*																			*/
/*	動的システム変更				作成:94/12/05							*/
/*																			*/
/* Update history:															*/
/*	95.05.28 K.Kubota ST2637: Process cooperation fail						*/
/*	95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange							*/
/*																			*/
/****************************************************************************/

										/* ###ST2637 Start					*/
/****************************************************************************/
/* ＳＭＰ−ＦＴＡＭプロセス間電文(MIA持ち回り形式)							*/
/****************************************************************************/
#define TYPFTAM			"B5"			/* FTAM_SMPﾌﾟﾛｸﾞﾗﾑ種別				*/

/****************************************/
/* 要求電文利用者域・共通部 12B			*/
/****************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
#define MMIFFTM1		0x79A00031		/* 排他区間設定要求通知(FTAM)		*/
#define MMIFFTM2		0x36000211		/* 排他区間設定応答通知(FTAM)		*/ 
#define MMIFFTM3		0x79A00032		/* 排他区間解除要求通知(FTAM)		*/
#define MMIFFTM4		0x36000212		/* 排他区間解除応答通知(FTAM)		*/ 
	long				reqid;			/* 要求識別子						*/
	short				num;			/* 通信相手識別名の数				*/
	char				dmy1[2];		/* 予備								*/
}						DYFT_KYO;
typedef DYFT_KYO		*PDYFT_KYO;

/****************************************/
/* 要求電文利用者域・個別部 20B			*/
/****************************************/
typedef struct
{
	char				syor_kbn;		/* 処理区分							*/
#define MMDDEL			0x01			/*	撤去							*/
#define MMDUPD			0x02			/*	変更							*/
#define MMDINS			0x03			/*	増設							*/
	char				dmy1[1];		/* 予備								*/
	short				len;			/* 通信相手識別名の長さ				*/
	char				teftdsid[16];	/* 通信相手識別名					*/
}						DYFT_KO;
typedef DYFT_KO			*PDYFT_KO;

/********************************************/
/* 要求電文全体の構造: 88+12+20*192=3940B	*/
/********************************************/
typedef struct
{
	MCMIKYO				mia;			/* MIA共通部						*/
#define MMMKFTAM		0x030E0000		/* mmd <---> mlh [FTAM_SMP]			*/
	DYFT_KYO			ftamkyo;		/* 利用者域共通部					*/
#define MMCIDNUM	192					/* 通信相手情報最大数				*/
	DYFT_KO				ftamko[MMCIDNUM]; /* 通信相手情報					*/
}						FTAMMSG;
#define MMFTMSIZ		sizeof(FTAMMSG)

/****************************************/
/* 応答電文利用者域の構造: 16B			*/
/****************************************/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
	long				reqid;			/* 要求識別子						*/
	long				result;			/* 結果ｺｰﾄﾞ							*/
	long				detail;			/* 詳細ｺｰﾄﾞ							*/
}						DYFT_RSP;
typedef DYFT_RSP		*PDYFT_RSP;
										/* ###ST2637 End					*/
