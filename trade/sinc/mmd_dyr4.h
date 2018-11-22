/****************************************************************************/
/*																			*/
/*		include	ﾌｧｲﾙ	<< mm_dyrc4.h >>									*/
/*																			*/
/*	update history:															*/
/*		95.07.14 K.Kubota SSCY0073: add TNTC/TNTD							*/
/*	95.08.28 K.Kubota SSCY0100: add RXLT+TLGN								*/
/*	03.03.10 サプライ：岩下 MD001: Linux移植に伴う修正						*/
/*							TLICアドレス管理部追加							*/
/*							TMDCアドレス管理部追加							*/
/*	03.08.08 サプライ：中村 TBCS0265: 障害対応								*/
/*							TSSTアドレス管理部追加							*/
/****************************************************************************/

/****************************************************************************/
/*	ＳＭＰテーブルアドレス管理テーブル										*/
/****************************************************************************/
typedef struct RXLTJ	RXLTPSZ;	/* RXLT個別部(便宜的型定義) ###SSCY0100	*/
typedef struct
{
	TCOMPAT				*ppctcom;		/* TPCTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPCTPSZ				*ppctpsz;		/* TPCTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPCT;			/* TPCTﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ppatcom;		/* TPATﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPATPSZ				*ppatpsz;		/* TPATｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPAT;			/* TPATﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ppaacom;		/* TPAAﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPAAPM				*ppaapsz;		/* TPAAｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPAA;			/* TPAAﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

//	TCOMPAT				*plgtcom;		/* TLGTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TLGTPSZ				*plgtpsz;		/* TLGTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocLGT;			/* TLGTﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

	TCOMPAT				*pfahcom;		/* TFAHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAHPSZ				*pfahpsz;		/* TFAHｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAH;			/* TFAHﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plphcom;		/* TLPHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPHPSZ				*plphpsz;		/* TLPHｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocLPH;			/* TLPHﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plptcom;		/* TLPTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPTPSZ				*plptpsz;		/* TLPTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocLPT;			/* TLPTﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfapcom;		/* TFAPﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAPPSZ				*pfappsz;		/* TFAPｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAP;			/* TFAPﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfaccom;		/* TFACﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFACPSZ				*pfacpsz;		/* TFACｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAC;			/* TFACﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

//	TCOMPAT				*pfaxcom;		/* TFAXﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TFAXPSZ				*pfaxpsz;		/* TFAXｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocFAX;			/* TFAXﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

	TCOMPAT				*pfalcom;		/* TFALﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFALPSZ				*pfalpsz;		/* TFALｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAL;			/* TFALﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

//	TCOMPAT				*peftcom;		/* TEFTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TEFTPSZ				*peftpsz;		/* TEFTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocEFT;			/* TEFTﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

//	TCOMPAT				*pmifcom;		/* TMIFﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TMITPSM				*pmifpsz;		/* TMIFｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocMIF;			/* TMIFﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

										/* ###SSCY0073 start				*/
	TCOMPAT				*pntccom;		/* TNTCﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TNTCPSZ				*pntcpsz;		/* TNTCｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocNTC;			/* TNTCﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/
										/* ###SSCY0073 end					*/

										/* ###SSCY0100 start				*/
//	TCOMPAT				*pxltcom;		/* RXLTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	RXLTPSZ				*pxltpsz;		/* RXLTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocXLT;			/* RXLTﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

//	TCOMPAT				*plgncom;		/* TLGNﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TLGNPSZ				*plgnpsz;		/* TLGNｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	long				LocLGN;			/* TLGNﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/
										
	TCOMPAT				*pliccom;		/* TLICﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
	TLICIND				*plicpsz;		/* TLICｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	long				LocLIC;			/* TLICﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/

	TCOMPAT				*pmdccom;		/* TMDCﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
	TMDCPSZ				*pmdcpsz;		/* TMDCｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	long				LocMDC;			/* TMDCﾃｰﾌﾞﾙ ｼｮｻﾞｲ			MD001	*/
										/* ###SSCY0100 end					*/

	TCOMPAT				*psstcom;		/* TSSTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		TBCS0265*/
	TSSTPSZ				*psstpsz;		/* TSSTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	TBCS0265*/
 	long				LocSST;			/* TSSTﾃｰﾌﾞﾙ ｼｮｻﾞｲ			TBCS0265*/
}						TBLSMP;

/****************************************************************************/
/*	定数テーブルアドレス管理テーブル										*/
/****************************************************************************/
typedef		struct
{
	TCOMPAT				*ppcucom;		/* TPCUﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPCUPSZ				*ppcupsz;		/* TPCUｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPCU;			/* TPCUﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ppaucom;		/* TPAUﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPAUPSZ				*ppaupsz;		/* TPAUｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPAU;			/* TPAUﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ppabcom;		/* TPABﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPABPM				*ppabpsz;		/* TPABｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocPAB;			/* TPABﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plgucom;		/* TLGUﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLGUPSZ				*plgupsz;		/* TLGUｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocLGU;			/* TLGUﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfaicom;		/* TFAIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAIPSZ				*pfaipsz;		/* TFAIｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAI;			/* TFAIﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plpicom;		/* TLPIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPIPSZ				*plpipsz;		/* TLPIｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocLPI;			/* TLPIﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plpucom;		/* TLPUﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPUPSZ				*plpupsz;		/* TLPUｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocLPU;			/* TLPUﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfaqcom;		/* TFAQﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAQPSZ				*pfaqpsz;		/* TFAQｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAQ;			/* TFAQﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfabcom;		/* TFABﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFABPSZ				*pfabpsz;		/* TFABｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAB;			/* TFABﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfaycom;		/* TFAYﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAYPSZ				*pfaypsz;		/* TFAYｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAY;			/* TFAYﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfamcom;		/* TFAMﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAMPSZ				*pfampsz;		/* TFAMｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocFAM;			/* TFAMﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pefucom;		/* TEFUﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TEFUPSZ				*pefupsz;		/* TEFUｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocEFU;			/* TEFUﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pmigcom;		/* TMIGﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TMIGPSM				*pmigpsz;		/* TMIGｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocMIG;			/* TMIGﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

										/* ###SSCY0073 start				*/
	TCOMPAT				*pntdcom;		/* TNTDﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TNTDPSZ				*pntdpsz;		/* TNTDｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	long				LocNTD;			/* TNTDﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/
										/* ###SSCY0073 end					*/
}						TBLDYR;


