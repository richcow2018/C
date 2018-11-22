/****************************************************************************/
/*		include ﾌｧｲﾙ	<< mmd_dyr1.h >>									*/
/*																			*/
/*		UPDATE HISTORY:														*/
/*		  95.04.04 K.Kubota ST1894: Delete DEVIC							*/
/*		  95.04.04 K.Kubota ST2636: Change Interface of mmd_7114()			*/
/*									(AddUp Type Parameter)					*/
/*		  95.06.12 K.Kubota ST2708: Kill MDA								*/
/*		  95.06.15 K.Kubota ST2815: mmd_7a15() interface					*/
/*		  95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange					*/
/*		  95.06.27 K.Kubota ST2706: EDP/DCP cooperation 					*/
/*		  95.06.29 K.Kubota SSCY0069: ISDN回線生成方式変更					*/
/*		  95.07.14 K.Kubota SSCY0073: TNTC対応								*/
/*		  95.07.26 K.Kubota SSCY0073-2: TNTC対応							*/
/*	95.08.28 K.Kubota SSCY0100: RXLT+TLGN型取込み, 関数型宣言変更			*/
/*	95.08.29 K.Kubota SSCY0095: add mmd_7330()'s declaration				*/
/*	95.08.31 K.Kubota ST3187(AT0948): enrich CLOG							*/
/*	95.09.13 K.Kubota SSCY0061: 全撤去ﾓｰﾄﾞ対応								*/
/*	95.10.04 K.Kubota ST3490=AT1347: TFAC_X25/TFAC_4W/TFAC_LOOP追加			*/
/*	95.10.16 K.Kubota SSCY0115: TMIFｻﾌﾞ共通部更新処理追加					*/
/*	96.02.29 K.Kubota ST4050: 内部インタフェース変更						*/
/*	96.03.18 K.Kubota ST4148: FG_ID of P_TRACE								*/
/*	96.04.17 K.Kubota ST4290: add wskb as parameter of mmd_7715()			*/
/*	96.11.08 S.Miyawaki ST4549: add mmd_8116()'s declaration 				*/
/*	03.03.10 サプライ：岩下 MD001: Linux移植に伴う修正						*/
/*								   動的システム構成変更開始／終了メッセージ	*/
/*								   追加										*/
/*								   不要なヘッダファイル削除					*/
/*	03.08.08 サプライ：中村 TBCS0265:障害対応								*/
/*							TSST処理モジュール追加							*/
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
/* 定数定義						*/
/********************************/
										/* ###ST3490 start					*/
#define TFAC_4W			0x41			/* TRADE処理種別(4W)				*/
#define TFAC_LOOP		0x42			/* TRADE処理種別(LOOP)				*/
#define TFAC_X25		0x68			/* TRADE処理種別(X.25)				*/
#define TFAC_GW			TFAC_X25		/* TRADE処理種別(GW)				*/
		/* GWという名前は部分しか表現してないのでそのうちX.25に併呑しよう。	*/
#define TFAC_LAN		0x6C			/* TRADE処理種別(LAN)				*/
#define TFAP_LP			0x00			/* APIｶﾃｺﾞﾘ(LOOP)					*/
										/* ###ST3490 end					*/

#define END				-1				/* 終了指示							*/
#define OK				0x00			/* 異常指示							*/
#define NG				-1				/* 異常指示							*/
#define ON				0x01			/* ON指示							*/
#define OFF				0x00			/* OFF指示							*/
#define NOTHING			0				/* 存在しない						*/

/********************************/
/* ｱﾎﾞｰﾄﾏｸﾛ定義					*/
/********************************/
#define MMD_ABTN(n,x,y) \
		mmd_9999( MODID, (n), __LINE__, (x), (y) );
#define MMD_ABRT(x,y) \
		MMD_ABTN(0,x,y)

/********************************/
/* ﾌﾟﾛｾｽﾄﾚｰｽ取得ﾏｸﾛ				*/
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
/* メッセージＩＤ定義												MD001	*/
/****************************************************************************/
#define	MSGID_SMD1	"SMD1"				/* 動的システム構成変更開始	MD001	*/
#define	MSGID_SMD2	"SMD2"				/* 動的システム構成変更終了	MD001	*/

/****************************************************************************/
/* ﾃｰﾌﾞﾙ更新ﾛｸﾞ共通部														*/
/****************************************************************************/
typedef struct{
	unsigned char		SyrKbn;			/* 処理区分							*/
										/* (正規化ﾚｺｰﾄﾞ処理区分と同じ)		*/
										/*  0xFF...EOF						*/
										/*  (EOF以降にﾃｰﾌﾞﾙ更新ﾛｸﾞﾚｺｰﾄﾞは	*/
										/*	 存在しない)					*/

	unsigned char		LogKbn;			/* ﾛｸﾞ区分							*/
#define BEF				0x00			/*  ﾃｰﾌﾞﾙ更新前ﾛｸﾞ					*/
#define AFT				0x01			/*  ﾃｰﾌﾞﾙ更新後ﾛｸﾞ					*/

	unsigned char		Loc;			/* ﾃｰﾌﾞﾙ所在						*/
#define CM				0x00			/*  CMﾃｰﾌﾞﾙ							*/
#define LM				0x01			/*  LMﾃｰﾌﾞﾙ[LMﾃｰﾌﾞﾙはPU0/PU1で対称]	*/

	unsigned char		Part;			/* 更新部位							*/
#define SUB				0x01			/*  ｻﾌﾞ共通部						*/
#define PSZ				0x10			/*  個別部							*/
#define PS				0x11			/*  ｻﾌﾞ個別部						*/

	unsigned char		tbid[4];		/* ﾃｰﾌﾞﾙ識別子(4桁の英大文字)		*/
	short				kno;			/* 個別部番号						*/
	short				sno;			/* ｻﾌﾞ個別部番号					*/
	short				Size;			/* 更新部位ｻｲｽﾞ						*/
	short				DiffNo;			/* 正規化ﾚｺｰﾄﾞ(差分)ﾚｺｰﾄﾞ番号		*/
										/* (先頭ﾚｺｰﾄﾞを１とする)			*/
	/* 本構造の直後に更新部位のﾊﾞｲﾅﾘﾀﾞﾝﾌﾟが出力される						*/
}						TLOG;

/****************************************************************************/
/* 関数定義																	*/
/****************************************************************************/
//void					mmd_2400( );	/* release FNA & kill MDA	MD001	*/
//void					mmd_2401( );	/* clear soon				MD001	*/
//void					mmd_2402( );	/* release FNA soon			MD001	*/
//void					mmd_2403( );	/* kill MDA soon			MD001	*/
/* 正規化ﾚｺｰﾄﾞ処理振り分け			*/
void					mmd_4000(/*LogPath*/);

/* 物理回線処理						*/
//void					mmd_4100(/*q*/);/*							MD001	*/	
/* 物理回線増設処理					*/
//void					mmd_41a0(/*q*/);/*							MD001	*/
/* 物理回線属性変更処理				*/
//void					mmd_41u0(/*q*/);/*							MD001	*/
/* 物理回線撤去処理					*/
//void					mmd_41d0(/*q*/);/*							MD001	*/
/* GW端末論理回線処理				*/
//void					mmd_4200(/*q*/);/*							MD001	*/
/* GW端末論理回線増設処理			*/
//void					mmd_42a0(/*q*/);/*							MD001	*/
/* GW端末論理回線属性変更処理		*/
//void					mmd_42u0(/*q*/);/*							MD001	*/
/* GW端末論理回線撤去処理			*/
//void					mmd_42d0(/*q*/);/*							MD001	*/
/* LAN端末論理回線処理				*/
void					mmd_4300(/*q*/);
/* LAN端末論理回線増設処理			*/
void					mmd_43a0(/*q*/);
/* LAN端末論理回線属性変更処理		*/
void					mmd_43u0(/*q*/);
/* LAN端末論理回線撤去処理			*/
void					mmd_43d0(/*q*/);
/* 端末ﾊﾟｽ処理						*/
void					mmd_4400(/*q*/);
/* 端末ﾊﾟｽ増設処理					*/
void					mmd_44a0(/*q*/);
/* 端末ﾊﾟｽ属性変更処理				*/
void					mmd_44u0(/*q*/);
/* 端末ﾊﾟｽ撤去処理					*/
void					mmd_44d0(/*q*/);
/* プロセス処理						*/
void					mmd_4700(/*q*/);
/* ﾌﾟﾛｾｽ増設処理					*/
void					mmd_47a0(/*q*/);
/* ﾌﾟﾛｾｽ属性変更処理				*/
void					mmd_47u0(/*q*/);
/* ﾌﾟﾛｾｽ撤去処理					*/
void					mmd_47d0(/*q*/);
/* パス連結処理						*/
void					mmd_4800(/*q*/);
/* ﾊﾟｽ連結増設処理					*/
void					mmd_48a0(/*q*/);
/* ﾊﾟｽ連結属性変更処理				*/
void					mmd_48u0(/*q*/);
/* ﾊﾟｽ連結撤去処理					*/
void					mmd_48d0(/*q*/);
/* ノード間通信パス処理				*/
void					mmd_4900(/*q*/);
/* ノード間通信パス増設処理			*/
void					mmd_49a0(/*q*/);
/* ノード間通信パス属性変更処理		*/
void					mmd_49u0(/*q*/);
/* ノード間通信パス撤去処理			*/
void					mmd_49d0(/*q*/);
/* パス連結処理						*/
//void					mmd_4a00(/*q*/);/*							MD001	*/
/* ﾊﾟｽ連結増設処理					*/
//void					mmd_4aa0(/*q*/);/*							MD001	*/
/* ﾊﾟｽ連結属性変更処理				*/
//void					mmd_4au0(/*q*/);/*							MD001	*/
/* ﾊﾟｽ連結撤去処理					*/
//void					mmd_4ad0(/*q*/);/*							MD001	*/
/* ホスト論理回線更新処理			*/
void					mmd_5000(/*q*/);
/* ホストパス更新処理				*/
void					mmd_6000(/*q*/);
/* TFAC空き個別部検索処理			*/
TFACPSZ					*mmd_7110(/*pNO*/);
/* TFAC個別部キー検索処理 ###ST2636	*/
TFACPSZ					*mmd_7114(/*Type, puno, chno, netw, pNO*/);
/* TFAC個別部更新処理				*/
void					mmd_7120(/*q, pFAC, FACn, FAXn, FAPn, FAHn,
						XLTn*/);		/* ###SSCY0100						*/
/* TFAC個別部変更処理				*/
void					mmd_7130(/*q, pFAC, FACn*/);
/* TFAC個別部削除処理				*/
void					mmd_7150(/*pFAC, FACn*/);
/* TFAX連続空き個別部検索処理		*/
//TFAXPSZ					*mmd_7211(/*Num, pNO*/);/*				MD001	*/
/* TFAX空き予約個別部検索処理		*/
//TFAXPSZ					*mmd_7212(/*pFAX, Num, Top, pNO*/);/*	MD001	*/
/* TFAX個別部更新処理 ###ST4050 below */
//void					mmd_7220(/*q, pFAX, FAXn, FACBUn*/);/*		MD001	*/
/* TFAX個別部予約処理				*/
//void					mmd_7221(/*pFAX, FAXn, FACn*/);/*			MD001	*/
/* TFAX個別部変更処理				*/
//void					mmd_7230(/*q, pFAX, FAXn*/);/*				MD001	*/
/* TFAX個別部削除処理				*/
//void					mmd_7250(/*pFAX, FAXn*/);/*					MD001	*/
/* TFAX個別部予約解除処理			*/
//void					mmd_7251(/*pFAX, FAXn*/);/*					MD001	*/
/* TFAL連続空き個別部検索処理		*/
TFALPSZ					*mmd_7311(/*Num, pNO*/);
/* TFAL空き予約個別部検索処理		*/
TFALPSZ					*mmd_7312(/*pFAL, Num, Top, pNO*/);
/* TFAL個別部更新処理				*/
void					mmd_7320(/*q, pFAL, FALn*/);
/* TFAL個別部予約処理				*/
void					mmd_7321(/*pFAL, FALn, FACn*/);
/* TLICエントリ番号取得処理			*/
long					mmd_7322(/*gno*/);		/*					MD001	*/
/* TFAX個別部変更処理 ###SSCY0095	*/
//void					mmd_7330(/*q, pFAL, FALn*/);	/*			MD001	*/
/* TFAL個別部削除処理				*/
void					mmd_7350(/*pFAL, FALn*/);
/* TFAL個別部予約解除処理			*/
void					mmd_7351(/*pFAL, FALn, FACn*/);
/* TFAP連続空き個別部検索処理		*/
TFAPPSZ					*mmd_7411(/*Num, pNO*/);
/* TFAP空き予約個別部検索処理		*/
TFAPPSZ					*mmd_7412(/*pFAP, Num, Top, pNO*/);
/* TFAP個別部更新処理 ###ST4050 below */
void					mmd_7420(/*q, pFAP, FAPn, LPTn, pFAC, pFACBU, FACBUn*/);
/* TFAP個別部予約処理				*/
void					mmd_7421(/*pFAP, FAPn, FACn*/);
/* TFAP個別部変更処理				*/
void					mmd_7430(/*q, pFAP, FAPn*/);
/* TFAP個別部削除処理				*/
void					mmd_7450(/*pFAP, FAPn*/);
/* TFAP個別部予約解除処理			*/
void					mmd_7451(/*pFAP, FAPn*/);
/* TLPT空き個別部検索処理			*/
TLPTPSZ					*mmd_7510(/*pNO*/);
/* TLPT個別部キー検索処理			*/
TLPTPSZ					*mmd_7514(/*psnm, pNO*/);
/* TLPT個別部更新処理[端末ﾊﾟｽ増設]	*/
void					mmd_7520(/*q, pLPT, LPTn, FAPn*/);
/* TLPT個別部更新処理２[ﾊﾟｽ連結]	*/
void					mmd_7523(/*pLPT, LPTn, PATn, LGTn*/);
/* TLPT個別部削除処理[端末ﾊﾟｽ増設]	*/
void					mmd_7550(/*pLPT, LPTn*/);
/* get resource number of TLPT ###ST2706 start	*/
void					mmd_75f0( );
/* enq TLPTPSZ						*/
void					mmd_75f1(/*pLPT, LPTn*/);
/* deq TLPTPSZ						*/
void					mmd_75f2(/*LPTn*/);	/* ###ST2706 end				*/
/* TPCT空き個別部検索処理			*/
TPCTPSZ					*mmd_7610(/*pNO*/);
/* TPCT通信ﾌﾟﾛｾｽ用予約個別部検索処理*/
TPCTPSZ					*mmd_7613(/*PType, pNO*/); /* ###SSCY0061			*/
/* TPCT通信ﾌﾟﾛｾｽ用使用個別部検索処理			###SSCY0061					*/
TPCTPSZ					*mmd_761d(/*PType, FAHn, pNO*/); /* ###SSCY0061		*/
/* TPCT個別部キー検索処理			*/
TPCTPSZ					*mmd_7614(/*PName, pNO*/);
/* TPCT個別部更新処理				*/
void					mmd_7620(/*q, pPCT, PCTn, PATn*/);
/* TPCTｻﾌﾞ共通部更新処理			*/
void					mmd_7622(/*pSUB, PCTn*/);
/* SMPﾌﾟﾛｾｽｻｽﾍﾟﾝﾄﾞ解除設定処理		*/
void					mmd_7623(/*pPCT, PCTn, FAHn*/);
/* TPCT個別部変更処理				*/
void					mmd_7630(/*q, pPCT, PCTn*/);
/* TPCT個別部削除処理				*/
void					mmd_7650(/*pPCT, PCTn*/);
/* TPAT空き個別部検索処理			*/
TPATPSZ					*mmd_7710(/*pNO*/);
/* TPAT空きｻﾌﾞ個別部検索処理		*/
TPATWS					*mmd_7713(/*pPAT, pNO*/);
/* TPATｻﾌﾞ個別部検索処理 ###ST4290 below */
TPATWS					*mmd_7715(/*wskb, wsno, pPAT, pNO*/);
/* TPAT個別部更新処理				*/
void					mmd_7720(/*q, pPAT, PATn, PCTn*/);
/* TPATｻﾌﾞ個別部更新処理			*/
void					mmd_7722(/*q, pWS, WSn, PATn, wskb, wsno*/);
/* TPAT個別部更新処理２				*/
void					mmd_7723(/*pPAT, PATn*/);
/* TPAT個別部変更処理				*/
void					mmd_7730(/*q, pPAT, PATn*/);
/* TPATｻﾌﾞ個別部変更処理			*/
void					mmd_7731(/*q, pWS, WSn, PATn*/);
/* TPAT個別部削除処理				*/
void					mmd_7750(/*pPAT, PATn*/);
/* TPATｻﾌﾞ個別部削除処理			*/
void					mmd_7752(/*pWS, WSn, PATn*/);
/* TPAT個別部削除処理２				*/
void					mmd_7753(/*pPAT, PATn*/);
/* TLGT空き個別部検索処理			*/
//TLGTPSZ					*mmd_7810(/*pNO*/);	/*					MD001	*/
/* TLGT個別部更新処理[ﾊﾟｽ連結]		*/
//void					mmd_7820(/*q, pLGT, LGTn, PATn, LPHn, LPTn*/);/*MD001*/
/* TLGT個別部削除処理[ﾊﾟｽ連結]		*/
//void					mmd_7850(/*LGTn*/);		/*					MD001	*/
/* TPAA空き個別部検索処理			*/
TPAAPM					*mmd_7910(/*pNO*/);
/* TPAA空きｻﾌﾞ個別部検索処理		*/
TPAAPS					*mmd_7913(/*pPAA, pNO*/);
/* TPAAｻﾌﾞ個別部検索処理			*/
TPAAPS					*mmd_7915(/*LGTn, LPHn, LPTn, pPAA, pNO*/);
/* TPAAｻﾌﾞ個別部更新処理			*/
void					mmd_7922(/*q, pPS, PSn, PAAn, LGTn, LPHn, LPTn*/);
/* TPAA個別部更新処理２				*/
void					mmd_7923(/*pPAA, PAAn*/);
/* TPAAｻﾌﾞ個別部変更処理			*/
void					mmd_7931(/*q, pPS, PSn, PAAn*/);
/* TPAAｻﾌﾞ個別部削除処理			*/
void					mmd_7952(/*pPS, PSn, PAAn*/);
/* TPAA個別部削除処理２				*/
void					mmd_7953(/*pPAA, PAAn*/);
/* TMIF個別部検索処理				*/
//TMITPSM					*mmd_7a10(/*q, MIFn*/);	/*				MD001	*/
/* TMIF空きｻﾌﾞ個別部検索処理		*/
//TMITPSP					*mmd_7a13(/*pMIF, pNO*/);/*				MD001	*/
/* TMIFｻﾌﾞ個別部検索処理 ###ST2815	*/
//TMITPSP					*mmd_7a15(/*ndno, pMIF, pNO*/);	/*		MD001	*/
/* TMIFｻﾌﾞ共通部更新処理 ###SSCY0115 */
//void					mmd_7a21(/*q*/);/*							MD001	*/
/* TMIFｻﾌﾞ個別部更新処理			*/
//void					mmd_7a22(/*q, pMIF, MIFn, pSP, SPn*/);/*	MD001	*/
/* TMIF個別部更新処理２				*/
//void					mmd_7a23(/*q, pMIF, MIFn*/);/*				MD001	*/
/* TMIFｻﾌﾞ個別部変更処理			*/
//void					mmd_7a31(/*q, pMIF, MIFn, pSP, SPn*/);/*	MD001	*/
/* TMIFｻﾌﾞ個別部削除処理			*/
//void					mmd_7a52(/*q, pSP, SPn, MIFn*/);/*			MD001	*/
/* TMIF個別部削除処理２				*/
//void					mmd_7a53(/*pMIF, MIFn*/);	/*				MD001	*/
/* TEFT空き個別部検索処理			*/
//TEFTPSZ					*mmd_7b10(/*pNO*/);/*					MD001	*/
/* TEFT個別部検索処理				*/
//TEFTPSZ					*mmd_7b14(/*dsid, pNO*/);/*				MD001	*/
/* TEFT個別部更新処理			*/
//void					mmd_7b20(/*q, pEFT, EFTn*/);/*				MD001	*/
/* TEFT個別部変更処理			*/
//void					mmd_7b30(/*q, pEFT, EFTn*/);/*				MD001	*/
/* TEFT個別部削除処理			*/
//void					mmd_7b50(/*pEFT, EFTn*/);/*					MD001	*/
/* TNTC空き個別部検索処理						###SSCY0073 start			*/
TNTCPSZ					*mmd_7c10(/*pNO*/);
/* TNTC個別部検索処理				*/
TNTCPSZ					*mmd_7c14(/*ndno, pNO*/);
/* TNTC個別部更新処理			*/
void					mmd_7c20(/*q, pNTC, NTCn*/);
/* TNTCｻﾌﾞ共通部更新処理			*/
void					mmd_7c22(/*q, pSUB*/);
/* TNTC個別部変更処理			*/
void					mmd_7c30(/*q, pNTC, NTCn*/);
/* TNTC個別部削除処理			*/
void					mmd_7c50(/*pNTC, NTCn*/);
										/* ###SSCY0073 end					*/
/* TMDC空き個別部検索処理											MD001	*/
TMDCPSZ                 *mmd_7e10(/*pNO*/);	/*						MD001	*/
/* TMDC個別部検索処理												MD001	*/
TMDCPSZ                 *mmd_7e11(/*ndno*/);/*						MD001	*/
/* TMDC個別部更新処理												MD001	*/
long                    mmd_7e20(/*q, pMDC, MDCn*/);	/*			MD001	*/
/* TMDC個別部変更処理												MD001	*/
long                    mmd_7e30(/*q, pMDC, MDCn*/);	/*			MD001	*/
/* TMDC個別部削除処理												MD001	*/
long                    mmd_7e40(/*pMDC, MDCn*/);		/*			MD001	*/
/* TFAH連続空き個別部検索処理		*/
TFAHPSZ					*mmd_8111(/*Num, pNO*/);
/* TFAH空き予約個別部検索処理		*/
TFAHPSZ					*mmd_8112(/*pFAH, Num, Top, pNO*/);
/* TFAH空きｻﾌﾞ個別部検索処理		*/
TFAHPS					*mmd_8113(/*pFAH, pNO*/);
/* FNA.PU検索処理					*/
TFAHPSZ					*mmd_8114(/*cpu, ch, pu, pNO, ppEFX, pEFXn*/);
/* TLPH対応ｻﾌﾞ個別部検索処理		*/
TFAHPS					*mmd_8115(/*pFAH, LPHn, pNO*/);
/* TFAH有効ｻﾌﾞ個別部検索処理 						 ###ST4569		*/
TFAHPS					*mmd_8116(/*pFAH, pNO, LPHn*/);
/* TFAH個別部更新処理 ###ST4050 below */
void					mmd_8120(/*q, pFAH, FAHn, pFAC, FACn, EFXn, pFACBU, FACBUn*/);
/* TFAH個別部予約処理				*/
void					mmd_8121(/*q, pFAH, FACn*/);
/* TFAHｻﾌﾞ個別部更新処理			*/
void					mmd_8122(/*q, pPS, PSn, FAHn, LPHn*/);
/* TFAH個別部更新処理[論理ﾊﾟｽ増設]	*/
void					mmd_8123(/*q, pFAH, FAHn*/);
/* TFAHｻﾌﾞ個別部埋め合わせ処理 						 ###ST4569		*/
void					mmd_8124(/*Mode*/);		  /* ###ST4569		*/
/* TFAH個別部削除処理								 ###SSCY0061	*/
void					mmd_8150(/*pFAH, FAHn*/); /* ###SSCY0061	*/
/* TFAHｻﾌﾞ個別部削除処理			*/
void					mmd_8152(/*pPS, FAHn*/);
/* TFAH個別部更新処理[論理ﾊﾟｽ撤去]	*/
void					mmd_8153(/*pFAH, FAHn*/);
/* TLPH空き個別部取得処理			*/
TLPHPSZ					*mmd_8210(/*pNO*/);
/* TLPH個別部キー検索処理			*/
TLPHPSZ					*mmd_8214(/*psnm, pNO*/);
/* TLPH個別部更新処理				*/
void					mmd_8220(/*q, pLPH, LPHn, FAHn*/);
/* TLPH個別部更新処理[ﾊﾟｽ連結]		*/
void					mmd_8223(/*pLPH, LPHn, PATn, LGTn*/);
/* TLPH個別部変更処理				*/
void					mmd_8230(/*q, pLPH, LPHn*/);
/* TLPH個別部削除処理				*/
void					mmd_8250(/*pLPH, LPHn*/);
/* RXLT+TLGN検索処理					   ###SSCY0100 start				*/
//short					mmd_8a14(/*puno, chno, netw, ver*/);/*		MD001	*/
										/* ###SSCY0100 end					*/

/* 正規化データ(差分)アクセス処理	*/
long					mmd_9100(/*Pos*/);
/* 論理回線番号変換表初期設定		*/
void					mmd_9200(/**/);
/* 論理回線番号登録					*/
void					mmd_9201(/*Type, lchnN, lchnT*/);
/* 論理回線番号取得					*/
short					mmd_9202(/*Type, lchnN*/);
/* プールバッファ確保処理			*/
void					mmd_9300(/*MemKbn, Size, ppB*/);
/* プールバッファ解放処理			*/
void					mmd_9310(/**/);
/* 特殊ファイル名作成処理 ###ST4050 below */
void					mmd_9400(/*CType, pFAC, pFAP, Name, pFACBU*/);

void  		mmd_7000();					/* ﾃｰﾌﾞﾙ複写処理振り分け			*/	
void  		mmd_7140();					/* TFAC個別部複写処理				*/
void  		mmd_7240();					/* TFAX個別部複写処理				*/
void  		mmd_7340();					/* TFAL個別部複写処理				*/
void  		mmd_7440();					/* TFAP個別部複写処理				*/
void  		mmd_7540();					/* TLPT個別部複写処理				*/
void  		mmd_7640();					/* TPCT個別部複写処理				*/
void  		mmd_7642();					/* TPCTｻﾌﾞ共通部複写処理			*/
void  		mmd_7740();					/* TPAT個別部複写処理				*/
void  		mmd_7741();					/* TPATｻﾌﾞ個別部複写処理			*/
void  		mmd_7840();					/* TLGT個別部複写処理				*/
void  		mmd_7940(/*pTL,qPAA*/);		/* TPAA個別部複写処理				*/
void  		mmd_7941(/*pTL,qPS*/);		/* TPAAｻﾌﾞ個別部複写処理			*/
void  		mmd_7a40(/*pTL,qMIF*/);		/* TMIF個別部複写処理				*/
void  		mmd_7a41(/*pTL,qSP*/);		/* TMIFｻﾌﾞ個別部複写処理			*/
void  		mmd_7b40(/*pTL,qEFT*/);		/* TEFT個別部複写処理				*/
void  		mmd_7c40(/*pTL,qNTC*/);		/* TNTC個別部複写処理				*/
void  		mmd_7c42(/*pSUB,qSUB*/);	/* TNTCｻﾌﾞ共通部複写処理			*/
										/* ###SSCY0073						*/	
void  		mmd_8140();					/* TFAH個別部複写処理				*/
void  		mmd_8141();					/* TFAHｻﾌﾞ個別部複写処理			*/
void  		mmd_8240();					/* TLPH個別部複写処理				*/
TCOMPAT    *mmd_9600();					/* TFAC個別部複写処理				*/
char  	   *mmd_9700();					/* TFAC個別部複写処理				*/
void  		mmd_9800();					/* ﾃｰﾌﾞﾙ更新ﾛｸﾞｵｰﾌﾟﾝ				*/
void  		mmd_9810();					/* ﾃｰﾌﾞﾙ更新ﾛｸﾞｸﾛｰｽﾞ				*/
long  		mmd_9820();					/* ﾃｰﾌﾞﾙ更新ﾛｸﾞ共通部読み込み		*/
void  		mmd_9821();					/* ﾃｰﾌﾞﾙ更新ﾛｸﾞ読み込み				*/
void  		mmd_9830();					/* ﾃｰﾌﾞﾙ更新ﾛｸﾞ出力					*/
void  		mmd_9999();					/* 動的ｼｽﾃﾑ構成変更ﾌﾟﾛｾｽｱﾎﾞｰﾄ		*/
										/* ###ST2707 end					*/

 										/* TBCS0265							*/
TSSTPSZ		*mmd_7d10(void);			/* TSST個別部検索処理				*/
void		mmd_7d20(/*q, pSST*/);		/* TSST個別部更新処理				*/
 										/* TBCS0265 end						*/
