/*--------------------------------------------------------------------------*/
/*																			*/
/*		include	ﾌｧｲﾙ	<< mme_dyr4.h >>									*/
/*																			*/
/*	update history:															*/
/*		95.07.14 K.Kubota SSCY0073: add TNTC								*/
/*		03.03.07 サプライ：岩下 MD001: Linux移植に伴う修正					*/
/*									   TLICテーブル追加						*/
/*									   TMDCテーブル追加						*/
/*																			*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*	ＳＭＰテーブルアドレス管理テーブル										*/
typedef		struct
{
	TCOMPAT		*ppctcom;				/* TPCTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPCTPSZ		*ppctpsz;				/* TPCTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*ppatcom;				/* TPATﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPATPSZ		*ppatpsz;				/* TPATｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
//	TCOMPAT		*plgtcom;				/* TLGTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TLGTPSZ		*plgtpsz;				/* TLGTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	TCOMPAT		*plptcom;				/* TLPTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPTPSZ		*plptpsz;				/* TLPTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*plphcom;				/* TLPHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TLPHPSZ		*plphpsz;				/* TLPHｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*pfapcom;				/* TFAPﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAPPSZ		*pfappsz;				/* TFAPｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*pfahcom;				/* TFAHﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFAHPSZ		*pfahpsz;				/* TFAHｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*pfaccom;				/* TFACﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFACPSZ		*pfacpsz;				/* TFACｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
//	TCOMPAT		*pfaxcom;				/* TFAXﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TFAXPSZ		*pfaxpsz;				/* TFAXｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	TCOMPAT		*pfalcom;				/* TFALﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TFALPSZ		*pfalpsz;				/* TFALｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
//	TCOMPAT		*pdadcom;				/* TDADﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TDADPSZ		*pdadpsz;				/* TDADｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	TCOMPAT		*ppaacom;				/* TPAAﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TPAAPM		*ppaapsz;				/* TPAAｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
//	TCOMPAT		*peftcom;				/* TEFTﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TEFTPSZ		*peftpsz;				/* TEFTｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
//	TCOMPAT		*pmifcom;				/* TMIFﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
//	TMITPSM		*pmifpsz;				/* TMIFｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	TCOMPAT		*pntccom;				/* TNTCﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TNTCPSZ		*pntcpsz;				/* TNTCｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*ptlicom;				/* TTLIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TTLIPSZ		*ptlipsz;				/* TTLIｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*ptsicom;				/* TTSIﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ				*/
	TTSIPSZ		*ptsipsz;				/* TTSIｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ			*/
	TCOMPAT		*pliccom;				/* TLICﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
	TLICIND		*plicpsz;				/* TLICｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
	TCOMPAT		*pmdccom;				/* TMDCﾃｰﾌﾞﾙ ｾﾝﾄｳ ﾎﾟｲﾝﾀ		MD001	*/
	TMDCPSZ		*pmdcpsz;				/* TMDCｺﾍﾞﾂﾌﾞ ｾﾝﾄｳ ﾎﾟｲﾝﾀ	MD001	*/
}TBLSMP;
