/****************************************************************************/
/*																			*/
/*	動的システム変更				作成:94/12/07							*/
/*																			*/
/* Update history:															*/
/*	95.05.28 K.Kubota ST2637: Process cooperation fail						*/
/*	95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange							*/
/*	03.04.16 サプライ：岩下 MD001:Linux移植に伴う修正						*/
/*								  通信制御種別HCP-S[V7]追加					*/
/*																			*/
/****************************************************************************/

										/* ###ST2637 Start					*/
#define TYPFNA			"94"			/* FNAﾌﾟﾛｸﾞﾗﾑ種別					*/
#define TFAH_MHG		0x09			/* FNAの通信制御種別				*/
#define TFAH_DCS		0x26			/* FNAの通信制御種別 HCP-S[V7] MD001*/

/****************************************/
/* FNA間電文共通部構造体 32B			*/
/****************************************/
typedef struct
{
	char				mkcode[4];		/* ◎MKｺｰﾄﾞ = 0x01010000			*/
#define MMMKFNA			0x01010000		/* mmd <---> mhg [HCP-S(V4)]		*/
	char				aparea[4];		/* AP作業域							*/
	long				mbox0;			/* ◎発信元ﾒｰﾙﾎﾞｯｸｽ識別子			*/
	long				mbox1;			/* ◎送信先ﾒｰﾙﾎﾞｯｸｽ識別子			*/
	char				rsltmode;		/* ◎処理結果通知ﾓｰﾄﾞ				*/
	char				rsv[3];			/* 予備								*/
	long				crctmbox;		/* ◎正常通知先ﾒｰﾙﾎﾞｯｸｽID			*/
	long				failmbox;		/* ◎異常通知先ﾒｰﾙﾎﾞｯｸｽID			*/
	short				srcwsno;		/* ◎発信元WS番号 = 0x0000			*/
	char				sndpuno;		/* ◎送信先PU番号 = tefxpuno		*/
	char				sndluno;		/* ◎送信先LU番号 = 0x01			*/
										/* (有効ならなんでもいい)			*/
										/* (FNAの横着のしりぬぐい)			*/
}						FNACIA;			/* Communication Interface Area		*/

/****************************************/
/* LU情報個別部 2B						*/
/****************************************/
typedef	struct
{
	char				luno;			/* LU番号							*/
	char				lutype;			/* LU種別							*/
}						LUINFO;

/****************************************/
/* LU情報共通部 4B						*/
/****************************************/
typedef	struct
{
	unsigned char		cmdcd;			/* ｺﾏﾝﾄﾞｺｰﾄﾞ						*/
#define MMCCFNA1		0xF1		/* 排他区間設定許可要求／応答通知(FNA)	*/
#define MMCCFNA2		0xF2		/* 排他区間終了許可要求／応答通知(FNA)	*/
	char				rsv;			/* 予備								*/
	short				entnum;			/* ｴﾝﾄﾘ数 (efective num. of LUINFO)	*/
}						LUCOM;

/****************************************/
/* 電文全体の構造 32+4+2*N = 548B		*/
/*  (要求/応答とも同一構造)				*/
/****************************************/
typedef	struct
{
	FNACIA				cia;			/* 共通域							*/
	LUCOM				lucom;			/* 利用者域: 共通部					*/
#define MAXLUNUM		256				/* 最大LU情報数						*/
	LUINFO				luinfo[MAXLUNUM]; /* 利用者域: 個別部				*/
}						FNAMSG;
										/* ###ST2637 End					*/
