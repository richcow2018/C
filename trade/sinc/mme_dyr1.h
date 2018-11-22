/*--------------------------------------------------------------------------*/
/*																			*/
/*	mme_dyr1.h																*/
/*																			*/
/*																			*/
/*																			*/
/*	update history:															*/
/*		95.07.14 K.Kubota SSCY0073: TNTC対応								*/
/*	95.09.13 K.Kubota SSCY0061: 全撤去ﾓｰﾄﾞ対応								*/
/*	96.03.18 K.Kubota ST4148: FG_ID of P_TRACE								*/
/*	03.03.10 サプライ：岩下 MD001: Linux移植に伴う修正						*/
/*								   FNA(V.7) の通信制御種別追加				*/
/*								   mme_0000()関数の型変更					*/
/*								   tlic.hをインクルード						*/
/*								   tmdc.hをインクルード						*/
/*								   不要なヘッダファイル削除					*/
/*--------------------------------------------------------------------------*/
#include "tcom.h"
#include "tadt.h"

#include "tpct.h"
#include "tpat.h"
#include "tpaa.h"
//#include "tlgt.h"						/*							MD001	*/

#include "tfac.h"
#include "tfah.h"
//#include "tdad.h"						/*							MD001	*/
#include "tefx.h"
#include "ttli.h"
#include "tlph.h"
#include "ttsi.h"
//#include "tfax.h"						/*							MD001	*/
#include "tfal.h"
#include "tfap.h"
#include "tlpt.h"

//#include "tmif.h"						/*							MD001	*/
//#include "teft.h"						/*							MD001	*/
#include "tntc.h"
#include "tlic.h"						/*							MD001	*/
#include "tmdc.h"						/*							MD001	*/

#include "psect.h"
#include "mcmia.h"

#include "mm_dyrec.h"
#include "mme_dyr4.h"
#include "mme_dyr5.h"
 
/****************************************************************************/
/*		DEFINE																*/
/****************************************************************************/
/*-----	オペレーション区分	------------------------------------------------*/
#define		ZOUSETU		0x03			/* 増設								*/
#define		HENKOU		0x02			/* 属性変更							*/
#define		TEKKYO		0x01			/* 撤去								*/
/*--------------------------------------------------------------------------*/
#define		TFAC_4W		0x41			/* 通信制御種別(4W)					*/
#define		TFAC_LP		0x42			/* 通信制御種別(HDLC_LOOP)			*/
#define		TFAC_LAN	0x6c			/* 通信制御種別(LAN)				*/
#define		TFAC_GW		0x68			/* 通信制御種別(X.25)				*/
#define		TFAP_LP		0x00			/* ＡＰＩカテゴリ(HDLC_ﾙｰﾌﾟ)		*/
/*--------------------------------------------------------------------------*/
#define		RECMAXSIZ	256				/*									*/
/*--------------------------------------------------------------------------*/
#define		END			-1				/* 終了指示							*/
#define		OK			0x00			/* 異常指示							*/
#define		NG			-1				/* 異常指示							*/
#define		CM			0x01			/* CM指示							*/
#define		LM			0x10			/* LM指示							*/
#define		ON			0x01			/* ON指示							*/
#define		OFF			0x00			/* OFF指示							*/
#define		NOTHING		0				/* 存在しない						*/
/****************************************************************************/
#define		TFAH_MHG	0x09			/* FNA(V.4)	の通信制御種別			*/
#define		TFAH_DCS	0x26			/* FNA(V.7)	の通信制御種別	MD001	*/
#define		TFAH_FTAM	0x06			/* FTAM	の通信制御種別				*/

/****************************************************************************/
/*		アボートマクロ定義													*/
/****************************************************************************/
										/* ###SSCY0073 start				*/
#define MME_ABTN(n,x,y) \
		mme_9999(MODID, (n), __LINE__, (x), (y))
#define MME_ABRT(x,y) \
		MME_ABTN(0,(x),(y))
										/* ###SSCY0073 end					*/

										/* ###ST4148 start					*/
#define TRCID			0x00ffe400		/* BASE P_TRACE ID of mme			*/
#ifdef DBG_SUN
#define MME_TRCA(i,a,b) \
		printf("#### TRACE (%.8X) 0x%.8X,0x%.8X\n", \
							(TRCID | (i)), (a), (b))
#define MME_TRC1(i,a) \
		printf("#### TRACE (%.8X) 0x%.8X\n", \
							(TRCID | (i)), (a))
#define MME_TRC2(i,a,b) \
		printf("#### TRACE (%.8X) 0x%.8X,0x%.8X\n", \
							(TRCID | (i)),  (a), (b))
#define MME_TRC3(i,a,b,c) \
		printf("#### TRACE (%.8X) 0x%.8X,0x%.8X,0x%.8X\n", \
							(TRCID | (i)), (a), (b), (c))
#define MME_TRC4(i,a,b,c,d) \
		printf("#### TRACE (%.8X) 0x%.8X,0x%.8X,0x%.8X,0x%.8X\n", \
							(TRCID | (i)), (a), (b), (c), (d))
#else
										/* ###ST3187 start					*/
#define MME_TRCA(i,a,b) \
		mc_loga((TRCID | (i)), (a), (b))
#define MME_TRC1(i,a) \
		mc_logv((TRCID | (i)), 1, (a))
#define MME_TRC2(i,a,b) \
		mc_logv((TRCID | (i)), 2, (a), (b))
#define MME_TRC3(i,a,b,c) \
		mc_logv((TRCID | (i)), 3, (a), (b), (c))
#define MME_TRC4(i,a,b,c,d) \
		mc_logv((TRCID | (i)), 4, (a), (b), (c), (d))
										/* ###ST3187 end					*/
#endif
										/* ###ST4148 end					*/

										/* ###SSCY0061 start				*/
/****************************************************************************/
/*		構造体型定義														*/
/****************************************************************************/
/********************************/
/* 動的対象外装置番号リスト		*/
/********************************/
typedef struct
{
	short				maxn;			/* dvno最大個数						*/
	short				efen;			/* dvno有効個数						*/
	short				dvno[1];		/* 装置番号ﾘｽﾄ: maxn個分確保のこと	*/
}						DVLST;
										/* ###SSCY0061 end					*/

/****************************************************************************/
/*		関数定義															*/
/****************************************************************************/
/************************************************/
/*	初期処理									*/
/************************************************/
//void					mme_0000();		MD001
long					mme_0000();
void					mme_0700();
/************************************************/
/*	逆正規化作成処理							*/
/************************************************/
long					mme_2000();
long					mme_2100();
long					mme_2200();
long					mme_2300();
long					mme_2400();
long					mme_3110();
long					mme_3200();
long					mme_3300();
long					mme_3400();
long					mme_3500();
long					mme_3600();
long					mme_3700();
long					mme_3800();
long					mme_4100();
long					mme_4200();
long					mme_4300();
long					mme_4400();
long					mme_4500();
long					mme_4600();
long					mme_4700();
long					mme_4800();
long					mme_4900();
long					mme_4a00();
long					mme_5000();
long					mme_6000();
TPCTPSZ*				mme_7701();
TPATWS*					mme_7801();
TNTCPSZ					*mme_7c10();	/* ###SSCY0073						*/
/************************************************/
/*	共通関数									*/
/************************************************/
void					mme_9500();
void					mme_9600();
TCOMPAT*				mme_9610();
char*					mme_9700();

/************************************************/
/*	モジュールＩＤ（逆正規化データ作成）		*/
/************************************************/
#define	MM_RVRS			0x79FFEF00
#define	MM_RVRS2		0x79FFEF01
#define	MME_0GEN		0x79FFE001
#define	MME_IRBI		0x79FFE002
#define	MME_SC00		0x79FFE003
#define	MME_SC10		0x79FFE004
#define	MME_0000		0x79FFE000
#define	MME_0700		0x79FFE070
#define	MME_2000		0x79FFE200
#define	MME_2100		0x79FFE210
#define	MME_2200		0x79FFE220
#define	MME_2300		0x79FFE230
#define	MME_2400		0x79FFE240
#define	MME_3110		0x79FFE311
#define	MME_3120		0x79FFE312
#define	MME_3130		0x79FFE313
#define	MME_3200		0x79FFE320
#define	MME_3300		0x79FFE330
#define	MME_3400		0x79FFE340
#define	MME_3500		0x79FFE350
#define	MME_3600		0x79FFE360
#define	MME_3700		0x79FFE370
#define	MME_3800		0x79FFE380
#define	MME_4100		0x79FFE410
#define	MME_4200		0x79FFE420
#define	MME_4300		0x79FFE430
#define	MME_4400		0x79FFE440
#define	MME_4500		0x79FFE450
#define	MME_4600		0x79FFE460
#define	MME_4700		0x79FFE470
#define	MME_4800		0x79FFE480
#define	MME_4900		0x79FFE490
#define	MME_4A00		0x79FFE4A0
#define	MME_5000		0x79FFE500
#define	MME_6000		0x79FFE600
#define	MME_7800		0x79FFE780
#define	MME_7C10		0x79FFE7C1
#define	MME_9500		0x79FFE950
#define	MME_9600		0x79FFE960
#define	MME_9700		0x79FFE970

/************************************************/
/*	モジュールＩＤ（差分データ抽出）			*/
/************************************************/
#define	MM_DIFF			0x79FFF000
#define	MM_DI100		0x79FFF100
#define	MM_DI200		0x79FFF200
#define	MM_DI300		0x79FFF300
#define	MM_DI400		0x79FFF400
#define	MM_DI500		0x79FFF500
#define	MM_DI600		0x79FFF600
