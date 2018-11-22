/*--------------------------------------------------------------------------*/
/*																			*/
/*		include	�̎�����	<< mme_dyr4.h >>									*/
/*																			*/
/*	update history:															*/
/*		95.07.14 K.Kubota SSCY0073: add TNTC								*/
/*		03.03.07 ���ץ饤���䲼 MD001: Linux�ܿ���ȼ������					*/
/*									   TLIC�ơ��֥��ɲ�						*/
/*									   TMDC�ơ��֥��ɲ�						*/
/*																			*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*	�ӣͣХơ��֥륢�ɥ쥹�����ơ��֥�										*/
typedef		struct
{
	TCOMPAT		*ppctcom;				/* TPCT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPCTPSZ		*ppctpsz;				/* TPCT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*ppatcom;				/* TPAT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPATPSZ		*ppatpsz;				/* TPAT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
//	TCOMPAT		*plgtcom;				/* TLGT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TLGTPSZ		*plgtpsz;				/* TLGT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	TCOMPAT		*plptcom;				/* TLPT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPTPSZ		*plptpsz;				/* TLPT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*plphcom;				/* TLPH�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPHPSZ		*plphpsz;				/* TLPH���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*pfapcom;				/* TFAP�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAPPSZ		*pfappsz;				/* TFAP���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*pfahcom;				/* TFAH�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAHPSZ		*pfahpsz;				/* TFAH���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*pfaccom;				/* TFAC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFACPSZ		*pfacpsz;				/* TFAC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
//	TCOMPAT		*pfaxcom;				/* TFAX�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TFAXPSZ		*pfaxpsz;				/* TFAX���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	TCOMPAT		*pfalcom;				/* TFAL�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFALPSZ		*pfalpsz;				/* TFAL���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
//	TCOMPAT		*pdadcom;				/* TDAD�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TDADPSZ		*pdadpsz;				/* TDAD���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	TCOMPAT		*ppaacom;				/* TPAA�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPAAPM		*ppaapsz;				/* TPAA���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
//	TCOMPAT		*peftcom;				/* TEFT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TEFTPSZ		*peftpsz;				/* TEFT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	TCOMPAT		*pmifcom;				/* TMIF�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TMITPSM		*pmifpsz;				/* TMIF���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	TCOMPAT		*pntccom;				/* TNTC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TNTCPSZ		*pntcpsz;				/* TNTC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*ptlicom;				/* TTLI�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TTLIPSZ		*ptlipsz;				/* TTLI���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*ptsicom;				/* TTSI�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TTSIPSZ		*ptsipsz;				/* TTSI���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	TCOMPAT		*pliccom;				/* TLIC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
	TLICIND		*plicpsz;				/* TLIC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	TCOMPAT		*pmdccom;				/* TMDC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
	TMDCPSZ		*pmdcpsz;				/* TMDC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
}TBLSMP;
