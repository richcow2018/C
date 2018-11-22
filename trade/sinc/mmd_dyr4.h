/****************************************************************************/
/*																			*/
/*		include	�̎�����	<< mm_dyrc4.h >>									*/
/*																			*/
/*	update history:															*/
/*		95.07.14 K.Kubota SSCY0073: add TNTC/TNTD							*/
/*	95.08.28 K.Kubota SSCY0100: add RXLT+TLGN								*/
/*	03.03.10 ���ץ饤���䲼 MD001: Linux�ܿ���ȼ������						*/
/*							TLIC���ɥ쥹�������ɲ�							*/
/*							TMDC���ɥ쥹�������ɲ�							*/
/*	03.08.08 ���ץ饤����¼ TBCS0265: �㳲�б�								*/
/*							TSST���ɥ쥹�������ɲ�							*/
/****************************************************************************/

/****************************************************************************/
/*	�ӣͣХơ��֥륢�ɥ쥹�����ơ��֥�										*/
/****************************************************************************/
typedef struct RXLTJ	RXLTPSZ;	/* RXLT������(�ص�Ū�����) ###SSCY0100	*/
typedef struct
{
	TCOMPAT				*ppctcom;		/* TPCT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPCTPSZ				*ppctpsz;		/* TPCT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPCT;			/* TPCT�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*ppatcom;		/* TPAT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPATPSZ				*ppatpsz;		/* TPAT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPAT;			/* TPAT�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*ppaacom;		/* TPAA�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPAAPM				*ppaapsz;		/* TPAA���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPAA;			/* TPAA�Î��̎ގ� �������ގ�					*/

//	TCOMPAT				*plgtcom;		/* TLGT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TLGTPSZ				*plgtpsz;		/* TLGT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocLGT;			/* TLGT�Î��̎ގ� �������ގ�			MD001	*/

	TCOMPAT				*pfahcom;		/* TFAH�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAHPSZ				*pfahpsz;		/* TFAH���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAH;			/* TFAH�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*plphcom;		/* TLPH�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPHPSZ				*plphpsz;		/* TLPH���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocLPH;			/* TLPH�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*plptcom;		/* TLPT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPTPSZ				*plptpsz;		/* TLPT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocLPT;			/* TLPT�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfapcom;		/* TFAP�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAPPSZ				*pfappsz;		/* TFAP���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAP;			/* TFAP�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfaccom;		/* TFAC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFACPSZ				*pfacpsz;		/* TFAC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAC;			/* TFAC�Î��̎ގ� �������ގ�					*/

//	TCOMPAT				*pfaxcom;		/* TFAX�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TFAXPSZ				*pfaxpsz;		/* TFAX���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocFAX;			/* TFAX�Î��̎ގ� �������ގ�			MD001	*/

	TCOMPAT				*pfalcom;		/* TFAL�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFALPSZ				*pfalpsz;		/* TFAL���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAL;			/* TFAL�Î��̎ގ� �������ގ�					*/

//	TCOMPAT				*peftcom;		/* TEFT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TEFTPSZ				*peftpsz;		/* TEFT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocEFT;			/* TEFT�Î��̎ގ� �������ގ�			MD001	*/

//	TCOMPAT				*pmifcom;		/* TMIF�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TMITPSM				*pmifpsz;		/* TMIF���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocMIF;			/* TMIF�Î��̎ގ� �������ގ�			MD001	*/

										/* ###SSCY0073 start				*/
	TCOMPAT				*pntccom;		/* TNTC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TNTCPSZ				*pntcpsz;		/* TNTC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocNTC;			/* TNTC�Î��̎ގ� �������ގ�					*/
										/* ###SSCY0073 end					*/

										/* ###SSCY0100 start				*/
//	TCOMPAT				*pxltcom;		/* RXLT�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	RXLTPSZ				*pxltpsz;		/* RXLT���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocXLT;			/* RXLT�Î��̎ގ� �������ގ�			MD001	*/

//	TCOMPAT				*plgncom;		/* TLGN�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
//	TLGNPSZ				*plgnpsz;		/* TLGN���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
//	long				LocLGN;			/* TLGN�Î��̎ގ� �������ގ�			MD001	*/
										
	TCOMPAT				*pliccom;		/* TLIC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
	TLICIND				*plicpsz;		/* TLIC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	long				LocLIC;			/* TLIC�Î��̎ގ� �������ގ�			MD001	*/

	TCOMPAT				*pmdccom;		/* TMDC�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		MD001	*/
	TMDCPSZ				*pmdcpsz;		/* TMDC���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	MD001	*/
	long				LocMDC;			/* TMDC�Î��̎ގ� �������ގ�			MD001	*/
										/* ###SSCY0100 end					*/

	TCOMPAT				*psstcom;		/* TSST�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�		TBCS0265*/
	TSSTPSZ				*psstpsz;		/* TSST���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�	TBCS0265*/
 	long				LocSST;			/* TSST�Î��̎ގ� �������ގ�			TBCS0265*/
}						TBLSMP;

/****************************************************************************/
/*	����ơ��֥륢�ɥ쥹�����ơ��֥�										*/
/****************************************************************************/
typedef		struct
{
	TCOMPAT				*ppcucom;		/* TPCU�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPCUPSZ				*ppcupsz;		/* TPCU���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPCU;			/* TPCU�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*ppaucom;		/* TPAU�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPAUPSZ				*ppaupsz;		/* TPAU���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPAU;			/* TPAU�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*ppabcom;		/* TPAB�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TPABPM				*ppabpsz;		/* TPAB���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocPAB;			/* TPAB�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*plgucom;		/* TLGU�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLGUPSZ				*plgupsz;		/* TLGU���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocLGU;			/* TLGU�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfaicom;		/* TFAI�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAIPSZ				*pfaipsz;		/* TFAI���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAI;			/* TFAI�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*plpicom;		/* TLPI�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPIPSZ				*plpipsz;		/* TLPI���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocLPI;			/* TLPI�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*plpucom;		/* TLPU�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TLPUPSZ				*plpupsz;		/* TLPU���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocLPU;			/* TLPU�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfaqcom;		/* TFAQ�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAQPSZ				*pfaqpsz;		/* TFAQ���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAQ;			/* TFAQ�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfabcom;		/* TFAB�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFABPSZ				*pfabpsz;		/* TFAB���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAB;			/* TFAB�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfaycom;		/* TFAY�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAYPSZ				*pfaypsz;		/* TFAY���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAY;			/* TFAY�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pfamcom;		/* TFAM�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TFAMPSZ				*pfampsz;		/* TFAM���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocFAM;			/* TFAM�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pefucom;		/* TEFU�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TEFUPSZ				*pefupsz;		/* TEFU���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocEFU;			/* TEFU�Î��̎ގ� �������ގ�					*/

	TCOMPAT				*pmigcom;		/* TMIG�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TMIGPSM				*pmigpsz;		/* TMIG���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocMIG;			/* TMIG�Î��̎ގ� �������ގ�					*/

										/* ###SSCY0073 start				*/
	TCOMPAT				*pntdcom;		/* TNTD�Î��̎ގ� ���ݎĎ� �Ύߎ��ݎ�				*/
	TNTDPSZ				*pntdpsz;		/* TNTD���͎ގ̎� ���ݎĎ� �Ύߎ��ݎ�			*/
	long				LocNTD;			/* TNTD�Î��̎ގ� �������ގ�					*/
										/* ###SSCY0073 end					*/
}						TBLDYR;


