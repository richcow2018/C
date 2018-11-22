/****************************************************************************/
/*		include �̎�����	<< mmd_dyr1.h >>									*/
/*																			*/
/*		UPDATE HISTORY:														*/
/*		  95.04.04 K.Kubota ST1894: Delete DEVIC							*/
/*		  95.04.04 K.Kubota ST2636: Change Interface of mmd_7114()			*/
/*									(AddUp Type Parameter)					*/
/*		  95.06.12 K.Kubota ST2708: Kill MDA								*/
/*		  95.06.15 K.Kubota ST2815: mmd_7a15() interface					*/
/*		  95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange					*/
/*		  95.06.27 K.Kubota ST2706: EDP/DCP cooperation 					*/
/*		  95.06.29 K.Kubota SSCY0069: ISDN�������������ѹ�					*/
/*		  95.07.14 K.Kubota SSCY0073: TNTC�б�								*/
/*		  95.07.26 K.Kubota SSCY0073-2: TNTC�б�							*/
/*	95.08.28 K.Kubota SSCY0100: RXLT+TLGN�������, �ؿ�������ѹ�			*/
/*	95.08.29 K.Kubota SSCY0095: add mmd_7330()'s declaration				*/
/*	95.08.31 K.Kubota ST3187(AT0948): enrich CLOG							*/
/*	95.09.13 K.Kubota SSCY0061: ��ű��ӎ��Ď��б�								*/
/*	95.10.04 K.Kubota ST3490=AT1347: TFAC_X25/TFAC_4W/TFAC_LOOP�ɲ�			*/
/*	95.10.16 K.Kubota SSCY0115: TMIF���̎޶��������������ɲ�					*/
/*	96.02.29 K.Kubota ST4050: �������󥿥ե������ѹ�						*/
/*	96.03.18 K.Kubota ST4148: FG_ID of P_TRACE								*/
/*	96.04.17 K.Kubota ST4290: add wskb as parameter of mmd_7715()			*/
/*	96.11.08 S.Miyawaki ST4549: add mmd_8116()'s declaration 				*/
/*	03.03.10 ���ץ饤���䲼 MD001: Linux�ܿ���ȼ������						*/
/*								   ưŪ�����ƥ๽���ѹ����ϡ���λ��å�����	*/
/*								   �ɲ�										*/
/*								   ���פʥإå��ե�������					*/
/*	03.08.08 ���ץ饤����¼ TBCS0265:�㳲�б�								*/
/*							TSST�����⥸�塼���ɲ�							*/
/****************************************************************************/
										/* ###ST2707 start					*/
#include "tcom.h"
#include "tadt.h"
#include "tpct.h"
#include "tpcu.h"
#include "tpat.h"
#include "tpau.h"
#include "tpaa.h"
#include "tpab.h"
//#include "tlgt.h"						/*							MD001	*/
#include "tlgu.h"
#include "tlpt.h"
#include "tlpu.h"
#include "tfap.h"
#include "tfaq.h"
#include "tfac.h"
#include "tfab.h"
#include "tlph.h"
#include "tlpi.h"
#include "tfah.h"
#include "tfai.h"
//#include "tfax.h"						/*							MD001	*/
#include "tfay.h"
#include "tfal.h"
#include "tfam.h"
//#include "teft.h"						/*							MD001	*/
#include "tefu.h"
//#include "tmif.h"						/*							MD001	*/
#include "tmig.h"
#include "tntc.h"						/* ###SSCY0073						*/
#include "tntd.h"						/* ###SSCY0073						*/
//#include "rxlt.h"						/* RXLT ###SSCY0100			MD001	*/
//#include "tlgn.h"						/* ###SSCY0100				MD001	*/
#include "tlic.h"						/* 							MD001	*/
#include "tmdc.h"						/*							MD001	*/
#include "tsst.h"						/* 						TBCS0265	*/

#include "psect.h"
#include "mm_dyrec.h"
#include "mmd_dyr4.h"

/********************************/
/* ������						*/
/********************************/
										/* ###ST3490 start					*/
#define TFAC_4W			0x41			/* TRADE��������(4W)				*/
#define TFAC_LOOP		0x42			/* TRADE��������(LOOP)				*/
#define TFAC_X25		0x68			/* TRADE��������(X.25)				*/
#define TFAC_GW			TFAC_X25		/* TRADE��������(GW)				*/
		/* GW�Ȥ���̾������ʬ����ɽ�����Ƥʤ��ΤǤ��Τ���X.25��ʻ�ݤ��褦��	*/
#define TFAC_LAN		0x6C			/* TRADE��������(LAN)				*/
#define TFAP_LP			0x00			/* API���Î��ގ�(LOOP)					*/
										/* ###ST3490 end					*/

#define END				-1				/* ��λ�ؼ�							*/
#define OK				0x00			/* �۾�ؼ�							*/
#define NG				-1				/* �۾�ؼ�							*/
#define ON				0x01			/* ON�ؼ�							*/
#define OFF				0x00			/* OFF�ؼ�							*/
#define NOTHING			0				/* ¸�ߤ��ʤ�						*/

/********************************/
/* ���Ύގ��Ďώ������					*/
/********************************/
#define MMD_ABTN(n,x,y) \
		mmd_9999( MODID, (n), __LINE__, (x), (y) );
#define MMD_ABRT(x,y) \
		MMD_ABTN(0,x,y)

/********************************/
/* �̎ߎێ����Ďڎ��������ώ���				*/
/********************************/
										/* ###ST4148 start					*/
#define TRCID			0x00ffe300		/* BASE P_TRACE ID of mmd			*/
#ifdef DBG_SUN
#define MMD_TRCA(i,a,b) \
		printf("#### TRACE (%.8X) 0x%.8X,0x%.8X\n", \
							(a), (b))
#define MMD_TRC1(i,a) \
		printf("#### TRACE (%.8X) %.8X_%d : 0x%.8X\n", \
							MODID, __LINE__, (a))
#define MMD_TRC2(i,a,b) \
		printf("#### TRACE (%.8X) %.8X_%d : 0x%.8X,0x%.8X\n", \
							MODID, __LINE__, (a), (b))
#define MMD_TRC3(i,a,b,c) \
		printf("#### TRACE (%.8X) %.8X_%d : 0x%.8X,0x%.8X,0x%.8X\n", \
							MODID, __LINE__, (a), (b), (c))
#define MMD_TRC4(i,a,b,c,d) \
		printf("#### TRACE (%.8X) %.8X_%d : 0x%.8X,0x%.8X,0x%.8X,0x%.8X\n", \
							MODID, __LINE__, (a), (b), (c), (d))
#else
										/* ###ST3187 start					*/
#define MMD_TRCA(i,a,b) \
		mc_loga((TRCID | (i)), (a), (b))
#define MMD_TRC1(i,a) \
		mc_logv((TRCID | (i)), 1, (a))
#define MMD_TRC2(i,a,b) \
		mc_logv((TRCID | (i)), 2, (a), (b))
#define MMD_TRC3(i,a,b,c) \
		mc_logv((TRCID | (i)), 3, (a), (b), (c))
#define MMD_TRC4(i,a,b,c,d) \
		mc_logv((TRCID | (i)), 4, (a), (b), (c), (d))
										/* ###ST3187 end					*/
#endif
										/* ###ST4148 end					*/
/****************************************************************************/
/* ��å������ɣ����												MD001	*/
/****************************************************************************/
#define	MSGID_SMD1	"SMD1"				/* ưŪ�����ƥ๽���ѹ�����	MD001	*/
#define	MSGID_SMD2	"SMD2"				/* ưŪ�����ƥ๽���ѹ���λ	MD001	*/

/****************************************************************************/
/* �Î��̎ގٹ����ێ��޶�����														*/
/****************************************************************************/
typedef struct{
	unsigned char		SyrKbn;			/* ������ʬ							*/
										/* (�������ڎ����Ď޽�����ʬ��Ʊ��)		*/
										/*  0xFF...EOF						*/
										/*  (EOF�ʹߤˎÎ��̎ގٹ����ێ��ގڎ����Ďޤ�	*/
										/*	 ¸�ߤ��ʤ�)					*/

	unsigned char		LogKbn;			/* �ێ��޶�ʬ							*/
#define BEF				0x00			/*  �Î��̎ގٹ������ێ���					*/
#define AFT				0x01			/*  �Î��̎ގٹ�����ێ���					*/

	unsigned char		Loc;			/* �Î��̎ގٽ��						*/
#define CM				0x00			/*  CM�Î��̎ގ�							*/
#define LM				0x01			/*  LM�Î��̎ގ�[LM�Î��̎ގ٤�PU0/PU1���о�]	*/

	unsigned char		Part;			/* ��������							*/
#define SUB				0x01			/*  ���̎޶�����						*/
#define PSZ				0x10			/*  ������							*/
#define PS				0x11			/*  ���̎޸�����						*/

	unsigned char		tbid[4];		/* �Î��̎ގټ��̻�(4��α���ʸ��)		*/
	short				kno;			/* �������ֹ�						*/
	short				sno;			/* ���̎޸������ֹ�					*/
	short				Size;			/* �������̎�������						*/
	short				DiffNo;			/* �������ڎ����Ď�(��ʬ)�ڎ����Ď��ֹ�		*/
										/* (��Ƭ�ڎ����Ďޤ򣱤Ȥ���)			*/
	/* �ܹ�¤��ľ��˹������̤Ύʎގ��Ŏ؎��ގݎ̎ߤ����Ϥ����						*/
}						TLOG;

/****************************************************************************/
/* �ؿ����																	*/
/****************************************************************************/
//void					mmd_2400( );	/* release FNA & kill MDA	MD001	*/
//void					mmd_2401( );	/* clear soon				MD001	*/
//void					mmd_2402( );	/* release FNA soon			MD001	*/
//void					mmd_2403( );	/* kill MDA soon			MD001	*/
/* �������ڎ����Ď޽�������ʬ��			*/
void					mmd_4000(/*LogPath*/);

/* ʪ����������						*/
//void					mmd_4100(/*q*/);/*							MD001	*/	
/* ʪ���������߽���					*/
//void					mmd_41a0(/*q*/);/*							MD001	*/
/* ʪ������°���ѹ�����				*/
//void					mmd_41u0(/*q*/);/*							MD001	*/
/* ʪ������ű�����					*/
//void					mmd_41d0(/*q*/);/*							MD001	*/
/* GWü��������������				*/
//void					mmd_4200(/*q*/);/*							MD001	*/
/* GWü�������������߽���			*/
//void					mmd_42a0(/*q*/);/*							MD001	*/
/* GWü����������°���ѹ�����		*/
//void					mmd_42u0(/*q*/);/*							MD001	*/
/* GWü����������ű�����			*/
//void					mmd_42d0(/*q*/);/*							MD001	*/
/* LANü��������������				*/
void					mmd_4300(/*q*/);
/* LANü�������������߽���			*/
void					mmd_43a0(/*q*/);
/* LANü����������°���ѹ�����		*/
void					mmd_43u0(/*q*/);
/* LANü����������ű�����			*/
void					mmd_43d0(/*q*/);
/* ü���ʎߎ�����						*/
void					mmd_4400(/*q*/);
/* ü���ʎߎ����߽���					*/
void					mmd_44a0(/*q*/);
/* ü���ʎߎ�°���ѹ�����				*/
void					mmd_44u0(/*q*/);
/* ü���ʎߎ�ű�����					*/
void					mmd_44d0(/*q*/);
/* �ץ�������						*/
void					mmd_4700(/*q*/);
/* �̎ߎێ������߽���					*/
void					mmd_47a0(/*q*/);
/* �̎ߎێ���°���ѹ�����				*/
void					mmd_47u0(/*q*/);
/* �̎ߎێ���ű�����					*/
void					mmd_47d0(/*q*/);
/* �ѥ�Ϣ�����						*/
void					mmd_4800(/*q*/);
/* �ʎߎ�Ϣ�����߽���					*/
void					mmd_48a0(/*q*/);
/* �ʎߎ�Ϣ��°���ѹ�����				*/
void					mmd_48u0(/*q*/);
/* �ʎߎ�Ϣ��ű�����					*/
void					mmd_48d0(/*q*/);
/* �Ρ��ɴ��̿��ѥ�����				*/
void					mmd_4900(/*q*/);
/* �Ρ��ɴ��̿��ѥ����߽���			*/
void					mmd_49a0(/*q*/);
/* �Ρ��ɴ��̿��ѥ�°���ѹ�����		*/
void					mmd_49u0(/*q*/);
/* �Ρ��ɴ��̿��ѥ�ű�����			*/
void					mmd_49d0(/*q*/);
/* �ѥ�Ϣ�����						*/
//void					mmd_4a00(/*q*/);/*							MD001	*/
/* �ʎߎ�Ϣ�����߽���					*/
//void					mmd_4aa0(/*q*/);/*							MD001	*/
/* �ʎߎ�Ϣ��°���ѹ�����				*/
//void					mmd_4au0(/*q*/);/*							MD001	*/
/* �ʎߎ�Ϣ��ű�����					*/
//void					mmd_4ad0(/*q*/);/*							MD001	*/
/* �ۥ�������������������			*/
void					mmd_5000(/*q*/);
/* �ۥ��ȥѥ���������				*/
void					mmd_6000(/*q*/);
/* TFAC������������������			*/
TFACPSZ					*mmd_7110(/*pNO*/);
/* TFAC������������������ ###ST2636	*/
TFACPSZ					*mmd_7114(/*Type, puno, chno, netw, pNO*/);
/* TFAC��������������				*/
void					mmd_7120(/*q, pFAC, FACn, FAXn, FAPn, FAHn,
						XLTn*/);		/* ###SSCY0100						*/
/* TFAC�������ѹ�����				*/
void					mmd_7130(/*q, pFAC, FACn*/);
/* TFAC�������������				*/
void					mmd_7150(/*pFAC, FACn*/);
/* TFAXϢ³������������������		*/
//TFAXPSZ					*mmd_7211(/*Num, pNO*/);/*				MD001	*/
/* TFAX����ͽ���������������		*/
//TFAXPSZ					*mmd_7212(/*pFAX, Num, Top, pNO*/);/*	MD001	*/
/* TFAX�������������� ###ST4050 below */
//void					mmd_7220(/*q, pFAX, FAXn, FACBUn*/);/*		MD001	*/
/* TFAX������ͽ�����				*/
//void					mmd_7221(/*pFAX, FAXn, FACn*/);/*			MD001	*/
/* TFAX�������ѹ�����				*/
//void					mmd_7230(/*q, pFAX, FAXn*/);/*				MD001	*/
/* TFAX�������������				*/
//void					mmd_7250(/*pFAX, FAXn*/);/*					MD001	*/
/* TFAX������ͽ��������			*/
//void					mmd_7251(/*pFAX, FAXn*/);/*					MD001	*/
/* TFALϢ³������������������		*/
TFALPSZ					*mmd_7311(/*Num, pNO*/);
/* TFAL����ͽ���������������		*/
TFALPSZ					*mmd_7312(/*pFAL, Num, Top, pNO*/);
/* TFAL��������������				*/
void					mmd_7320(/*q, pFAL, FALn*/);
/* TFAL������ͽ�����				*/
void					mmd_7321(/*pFAL, FALn, FACn*/);
/* TLIC����ȥ��ֹ��������			*/
long					mmd_7322(/*gno*/);		/*					MD001	*/
/* TFAX�������ѹ����� ###SSCY0095	*/
//void					mmd_7330(/*q, pFAL, FALn*/);	/*			MD001	*/
/* TFAL�������������				*/
void					mmd_7350(/*pFAL, FALn*/);
/* TFAL������ͽ��������			*/
void					mmd_7351(/*pFAL, FALn, FACn*/);
/* TFAPϢ³������������������		*/
TFAPPSZ					*mmd_7411(/*Num, pNO*/);
/* TFAP����ͽ���������������		*/
TFAPPSZ					*mmd_7412(/*pFAP, Num, Top, pNO*/);
/* TFAP�������������� ###ST4050 below */
void					mmd_7420(/*q, pFAP, FAPn, LPTn, pFAC, pFACBU, FACBUn*/);
/* TFAP������ͽ�����				*/
void					mmd_7421(/*pFAP, FAPn, FACn*/);
/* TFAP�������ѹ�����				*/
void					mmd_7430(/*q, pFAP, FAPn*/);
/* TFAP�������������				*/
void					mmd_7450(/*pFAP, FAPn*/);
/* TFAP������ͽ��������			*/
void					mmd_7451(/*pFAP, FAPn*/);
/* TLPT������������������			*/
TLPTPSZ					*mmd_7510(/*pNO*/);
/* TLPT������������������			*/
TLPTPSZ					*mmd_7514(/*psnm, pNO*/);
/* TLPT��������������[ü���ʎߎ�����]	*/
void					mmd_7520(/*q, pLPT, LPTn, FAPn*/);
/* TLPT����������������[�ʎߎ�Ϣ��]	*/
void					mmd_7523(/*pLPT, LPTn, PATn, LGTn*/);
/* TLPT�������������[ü���ʎߎ�����]	*/
void					mmd_7550(/*pLPT, LPTn*/);
/* get resource number of TLPT ###ST2706 start	*/
void					mmd_75f0( );
/* enq TLPTPSZ						*/
void					mmd_75f1(/*pLPT, LPTn*/);
/* deq TLPTPSZ						*/
void					mmd_75f2(/*LPTn*/);	/* ###ST2706 end				*/
/* TPCT������������������			*/
TPCTPSZ					*mmd_7610(/*pNO*/);
/* TPCT�̿��̎ߎێ�����ͽ���������������*/
TPCTPSZ					*mmd_7613(/*PType, pNO*/); /* ###SSCY0061			*/
/* TPCT�̿��̎ߎێ����ѻ��Ѹ�������������			###SSCY0061					*/
TPCTPSZ					*mmd_761d(/*PType, FAHn, pNO*/); /* ###SSCY0061		*/
/* TPCT������������������			*/
TPCTPSZ					*mmd_7614(/*PName, pNO*/);
/* TPCT��������������				*/
void					mmd_7620(/*q, pPCT, PCTn, PATn*/);
/* TPCT���̎޶�������������			*/
void					mmd_7622(/*pSUB, PCTn*/);
/* SMP�̎ߎێ��������͎ߎݎĎ޲���������		*/
void					mmd_7623(/*pPCT, PCTn, FAHn*/);
/* TPCT�������ѹ�����				*/
void					mmd_7630(/*q, pPCT, PCTn*/);
/* TPCT�������������				*/
void					mmd_7650(/*pPCT, PCTn*/);
/* TPAT������������������			*/
TPATPSZ					*mmd_7710(/*pNO*/);
/* TPAT�������̎޸�������������		*/
TPATWS					*mmd_7713(/*pPAT, pNO*/);
/* TPAT���̎޸������������� ###ST4290 below */
TPATWS					*mmd_7715(/*wskb, wsno, pPAT, pNO*/);
/* TPAT��������������				*/
void					mmd_7720(/*q, pPAT, PATn, PCTn*/);
/* TPAT���̎޸�������������			*/
void					mmd_7722(/*q, pWS, WSn, PATn, wskb, wsno*/);
/* TPAT����������������				*/
void					mmd_7723(/*pPAT, PATn*/);
/* TPAT�������ѹ�����				*/
void					mmd_7730(/*q, pPAT, PATn*/);
/* TPAT���̎޸������ѹ�����			*/
void					mmd_7731(/*q, pWS, WSn, PATn*/);
/* TPAT�������������				*/
void					mmd_7750(/*pPAT, PATn*/);
/* TPAT���̎޸������������			*/
void					mmd_7752(/*pWS, WSn, PATn*/);
/* TPAT���������������				*/
void					mmd_7753(/*pPAT, PATn*/);
/* TLGT������������������			*/
//TLGTPSZ					*mmd_7810(/*pNO*/);	/*					MD001	*/
/* TLGT��������������[�ʎߎ�Ϣ��]		*/
//void					mmd_7820(/*q, pLGT, LGTn, PATn, LPHn, LPTn*/);/*MD001*/
/* TLGT�������������[�ʎߎ�Ϣ��]		*/
//void					mmd_7850(/*LGTn*/);		/*					MD001	*/
/* TPAA������������������			*/
TPAAPM					*mmd_7910(/*pNO*/);
/* TPAA�������̎޸�������������		*/
TPAAPS					*mmd_7913(/*pPAA, pNO*/);
/* TPAA���̎޸�������������			*/
TPAAPS					*mmd_7915(/*LGTn, LPHn, LPTn, pPAA, pNO*/);
/* TPAA���̎޸�������������			*/
void					mmd_7922(/*q, pPS, PSn, PAAn, LGTn, LPHn, LPTn*/);
/* TPAA����������������				*/
void					mmd_7923(/*pPAA, PAAn*/);
/* TPAA���̎޸������ѹ�����			*/
void					mmd_7931(/*q, pPS, PSn, PAAn*/);
/* TPAA���̎޸������������			*/
void					mmd_7952(/*pPS, PSn, PAAn*/);
/* TPAA���������������				*/
void					mmd_7953(/*pPAA, PAAn*/);
/* TMIF��������������				*/
//TMITPSM					*mmd_7a10(/*q, MIFn*/);	/*				MD001	*/
/* TMIF�������̎޸�������������		*/
//TMITPSP					*mmd_7a13(/*pMIF, pNO*/);/*				MD001	*/
/* TMIF���̎޸������������� ###ST2815	*/
//TMITPSP					*mmd_7a15(/*ndno, pMIF, pNO*/);	/*		MD001	*/
/* TMIF���̎޶������������� ###SSCY0115 */
//void					mmd_7a21(/*q*/);/*							MD001	*/
/* TMIF���̎޸�������������			*/
//void					mmd_7a22(/*q, pMIF, MIFn, pSP, SPn*/);/*	MD001	*/
/* TMIF����������������				*/
//void					mmd_7a23(/*q, pMIF, MIFn*/);/*				MD001	*/
/* TMIF���̎޸������ѹ�����			*/
//void					mmd_7a31(/*q, pMIF, MIFn, pSP, SPn*/);/*	MD001	*/
/* TMIF���̎޸������������			*/
//void					mmd_7a52(/*q, pSP, SPn, MIFn*/);/*			MD001	*/
/* TMIF���������������				*/
//void					mmd_7a53(/*pMIF, MIFn*/);	/*				MD001	*/
/* TEFT������������������			*/
//TEFTPSZ					*mmd_7b10(/*pNO*/);/*					MD001	*/
/* TEFT��������������				*/
//TEFTPSZ					*mmd_7b14(/*dsid, pNO*/);/*				MD001	*/
/* TEFT��������������			*/
//void					mmd_7b20(/*q, pEFT, EFTn*/);/*				MD001	*/
/* TEFT�������ѹ�����			*/
//void					mmd_7b30(/*q, pEFT, EFTn*/);/*				MD001	*/
/* TEFT�������������			*/
//void					mmd_7b50(/*pEFT, EFTn*/);/*					MD001	*/
/* TNTC������������������						###SSCY0073 start			*/
TNTCPSZ					*mmd_7c10(/*pNO*/);
/* TNTC��������������				*/
TNTCPSZ					*mmd_7c14(/*ndno, pNO*/);
/* TNTC��������������			*/
void					mmd_7c20(/*q, pNTC, NTCn*/);
/* TNTC���̎޶�������������			*/
void					mmd_7c22(/*q, pSUB*/);
/* TNTC�������ѹ�����			*/
void					mmd_7c30(/*q, pNTC, NTCn*/);
/* TNTC�������������			*/
void					mmd_7c50(/*pNTC, NTCn*/);
										/* ###SSCY0073 end					*/
/* TMDC������������������											MD001	*/
TMDCPSZ                 *mmd_7e10(/*pNO*/);	/*						MD001	*/
/* TMDC��������������												MD001	*/
TMDCPSZ                 *mmd_7e11(/*ndno*/);/*						MD001	*/
/* TMDC��������������												MD001	*/
long                    mmd_7e20(/*q, pMDC, MDCn*/);	/*			MD001	*/
/* TMDC�������ѹ�����												MD001	*/
long                    mmd_7e30(/*q, pMDC, MDCn*/);	/*			MD001	*/
/* TMDC�������������												MD001	*/
long                    mmd_7e40(/*pMDC, MDCn*/);		/*			MD001	*/
/* TFAHϢ³������������������		*/
TFAHPSZ					*mmd_8111(/*Num, pNO*/);
/* TFAH����ͽ���������������		*/
TFAHPSZ					*mmd_8112(/*pFAH, Num, Top, pNO*/);
/* TFAH�������̎޸�������������		*/
TFAHPS					*mmd_8113(/*pFAH, pNO*/);
/* FNA.PU��������					*/
TFAHPSZ					*mmd_8114(/*cpu, ch, pu, pNO, ppEFX, pEFXn*/);
/* TLPH�б����̎޸�������������		*/
TFAHPS					*mmd_8115(/*pFAH, LPHn, pNO*/);
/* TFAHͭ�����̎޸������������� 						 ###ST4569		*/
TFAHPS					*mmd_8116(/*pFAH, pNO, LPHn*/);
/* TFAH�������������� ###ST4050 below */
void					mmd_8120(/*q, pFAH, FAHn, pFAC, FACn, EFXn, pFACBU, FACBUn*/);
/* TFAH������ͽ�����				*/
void					mmd_8121(/*q, pFAH, FACn*/);
/* TFAH���̎޸�������������			*/
void					mmd_8122(/*q, pPS, PSn, FAHn, LPHn*/);
/* TFAH��������������[�����ʎߎ�����]	*/
void					mmd_8123(/*q, pFAH, FAHn*/);
/* TFAH���̎޸���������碌���� 						 ###ST4569		*/
void					mmd_8124(/*Mode*/);		  /* ###ST4569		*/
/* TFAH�������������								 ###SSCY0061	*/
void					mmd_8150(/*pFAH, FAHn*/); /* ###SSCY0061	*/
/* TFAH���̎޸������������			*/
void					mmd_8152(/*pPS, FAHn*/);
/* TFAH��������������[�����ʎߎ�ű��]	*/
void					mmd_8153(/*pFAH, FAHn*/);
/* TLPH������������������			*/
TLPHPSZ					*mmd_8210(/*pNO*/);
/* TLPH������������������			*/
TLPHPSZ					*mmd_8214(/*psnm, pNO*/);
/* TLPH��������������				*/
void					mmd_8220(/*q, pLPH, LPHn, FAHn*/);
/* TLPH��������������[�ʎߎ�Ϣ��]		*/
void					mmd_8223(/*pLPH, LPHn, PATn, LGTn*/);
/* TLPH�������ѹ�����				*/
void					mmd_8230(/*q, pLPH, LPHn*/);
/* TLPH�������������				*/
void					mmd_8250(/*pLPH, LPHn*/);
/* RXLT+TLGN��������					   ###SSCY0100 start				*/
//short					mmd_8a14(/*puno, chno, netw, ver*/);/*		MD001	*/
										/* ###SSCY0100 end					*/

/* �������ǡ���(��ʬ)������������	*/
long					mmd_9100(/*Pos*/);
/* ���������ֹ��Ѵ�ɽ�������		*/
void					mmd_9200(/**/);
/* ���������ֹ���Ͽ					*/
void					mmd_9201(/*Type, lchnN, lchnT*/);
/* ���������ֹ����					*/
short					mmd_9202(/*Type, lchnN*/);
/* �ס���Хåե����ݽ���			*/
void					mmd_9300(/*MemKbn, Size, ppB*/);
/* �ס���Хåե���������			*/
void					mmd_9310(/**/);
/* �ü�ե�����̾�������� ###ST4050 below */
void					mmd_9400(/*CType, pFAC, pFAP, Name, pFACBU*/);

void  		mmd_7000();					/* �Î��̎ގ�ʣ�̽�������ʬ��			*/	
void  		mmd_7140();					/* TFAC������ʣ�̽���				*/
void  		mmd_7240();					/* TFAX������ʣ�̽���				*/
void  		mmd_7340();					/* TFAL������ʣ�̽���				*/
void  		mmd_7440();					/* TFAP������ʣ�̽���				*/
void  		mmd_7540();					/* TLPT������ʣ�̽���				*/
void  		mmd_7640();					/* TPCT������ʣ�̽���				*/
void  		mmd_7642();					/* TPCT���̎޶�����ʣ�̽���			*/
void  		mmd_7740();					/* TPAT������ʣ�̽���				*/
void  		mmd_7741();					/* TPAT���̎޸�����ʣ�̽���			*/
void  		mmd_7840();					/* TLGT������ʣ�̽���				*/
void  		mmd_7940(/*pTL,qPAA*/);		/* TPAA������ʣ�̽���				*/
void  		mmd_7941(/*pTL,qPS*/);		/* TPAA���̎޸�����ʣ�̽���			*/
void  		mmd_7a40(/*pTL,qMIF*/);		/* TMIF������ʣ�̽���				*/
void  		mmd_7a41(/*pTL,qSP*/);		/* TMIF���̎޸�����ʣ�̽���			*/
void  		mmd_7b40(/*pTL,qEFT*/);		/* TEFT������ʣ�̽���				*/
void  		mmd_7c40(/*pTL,qNTC*/);		/* TNTC������ʣ�̽���				*/
void  		mmd_7c42(/*pSUB,qSUB*/);	/* TNTC���̎޶�����ʣ�̽���			*/
										/* ###SSCY0073						*/	
void  		mmd_8140();					/* TFAH������ʣ�̽���				*/
void  		mmd_8141();					/* TFAH���̎޸�����ʣ�̽���			*/
void  		mmd_8240();					/* TLPH������ʣ�̽���				*/
TCOMPAT    *mmd_9600();					/* TFAC������ʣ�̽���				*/
char  	   *mmd_9700();					/* TFAC������ʣ�̽���				*/
void  		mmd_9800();					/* �Î��̎ގٹ����ێ��ގ����̎ߎ�				*/
void  		mmd_9810();					/* �Î��̎ގٹ����ێ��ގ��ێ�����				*/
long  		mmd_9820();					/* �Î��̎ގٹ����ێ��޶������ɤ߹���		*/
void  		mmd_9821();					/* �Î��̎ގٹ����ێ����ɤ߹���				*/
void  		mmd_9830();					/* �Î��̎ގٹ����ێ��޽���					*/
void  		mmd_9999();					/* ưŪ�����Îѹ����ѹ��̎ߎێ������Ύގ���		*/
										/* ###ST2707 end					*/

 										/* TBCS0265							*/
TSSTPSZ		*mmd_7d10(void);			/* TSST��������������				*/
void		mmd_7d20(/*q, pSST*/);		/* TSST��������������				*/
 										/* TBCS0265 end						*/
