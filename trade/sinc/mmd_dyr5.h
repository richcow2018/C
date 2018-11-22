/****************************************************************************/
/*																			*/
/*		include	ﾌｧｲﾙ	<< mm_dyrc5.h (DLL)	>>								*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*	ＳＭＰテーブルアドレス管理テーブル										*/
/****************************************************************************/
typedef struct
{
	TCOMPAT				*ppctcom;		/* TPCTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPCTPSZ				*ppctpsz;		/* TPCTｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocPCT;			/* TPCTﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfaccom;		/* TFACﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFACPSZ				*pfacpsz;		/* TFACｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocFAC;			/* TFACﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pfahcom;		/* TFAHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAHPSZ				*pfahpsz;		/* TFAHｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocFAH;			/* TFAHﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pefxcom;		/* TEFXﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TEFXPSZ				*pefxpsz;		/* TEFXｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocEFX;			/* TEFXﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pdadcom;		/* TDADﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TDADPSZ				*pdadpsz;		/* TDADｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocDAD;			/* TDADﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*plphcom;		/* TLPHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPHPSZ				*plphpsz;		/* TLPHｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocLPH;			/* TLPHﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ptlicom;		/* TTLIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TTLIPSZ				*ptlipsz;		/* TTLIｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocTLI;			/* TTLIﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*ptsicom;		/* TTSIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TTSIPSZ				*ptsipsz;		/* TTSIｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocTSI;			/* TTSIﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/
}						DLLSMP;

/****************************************************************************/
/*	定数テーブルアドレス管理テーブル										*/
/****************************************************************************/
typedef struct
{
	TCOMPAT				*pfaicom;		/* TFAIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAIPSZ				*pfaipsz;		/* TFAIｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocFAI;			/* TFAIﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/

	TCOMPAT				*pefycom;		/* TEFYﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TEFYPSZ				*pefypsz;		/* TEFYｺﾍﾞﾂﾌﾞﾃｰﾌﾞﾙ ｾﾝﾄｳ	ﾎﾟｲﾝﾀ		*/
	long				LocEFY;			/* TEFYﾃｰﾌﾞﾙ ｼｮｻﾞｲ					*/
}						DLLDYR;
