/****************************************************************************/
/*  著作権　１９９４                                                        */
/*            ＮＴＴデータ通信株式会社                                      */
/*              金融システム事業本部                                        */
/*                                                                          */
/*                                                                          */
/*  収容物  ＡＣＥ−ＳＭＰシステム                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*        ＡＣＥ−ＳＭＰ　ＦＴＡＭ  ＳＧデ−タテーブル構造体定義            */
/*                                                                          */
/*                                                                          */
/*          <tefu.h>                       FTAMﾌﾟﾛｸﾞﾗﾑ SGﾃﾞｰﾀﾃｰﾌﾞﾙ構造体定義*/
/*                                                                          */
/*                                                                          */
/*＜作成：ＩＤ／年月日／氏名＞                                              */
/*  <     > : １９９４年１１月２５日        楠田英幸                        */
/*＜修正：ＩＤ／年月日／氏名＞                                              */
/*  <FJ003> : １９９４年１２月　８日        楠田英幸                        */
/*            　仕様変更：ＣＶＯＳイベント追加                              */
/*            　仕様変更：動的システム変更対処                              */
/*--------------------------------------------------------------------------*/
/*  95.06.05 K.Kubota SSCY0057: F_DATA送信規制制御用定数の追加              */
/*                                                                          */
/*                                                                          */
/****************************************************************************/


/****************************************************************************/
/*********************************** ＤＥＦＩＮＥ部 *************************/
/* teft.hと同時にincludeするときは本ファイルを後ろに配置すること (K.Kubota)	*/
/****************************************************************************/
#ifndef MLHCCLEN						/* SSCY0057 Start					*/
	#define MLHCCLEN	16				/* 通信識別名ｴﾘｱ長さ				*/
	#define MLHCFLEN	64				/* 自通信識別名ﾌｧｲﾙｴﾘｱ長さ			*/
	#define MLHEXADL	20				/* 拡張アドレスｴﾘｱ長さ				*/
	#define MLHEXMAX	40				/* 拡張アドレス最大長さ		<FJ003>	*/
	#define MLH_PRCNL	8				/* プロセス識別名長さ				*/
	#define MLHFSAPL	16				/* ＦＳＡＰ−ＩＤ長さ				*/
	#define MLHTSAPL	32				/* ＦＳＡＰ−ＩＤ長さ				*/
	#define MLH_ADLN	8				/* アドレス長さ						*/
	#define MLH_PSLL	4				/* ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ				*/
#endif									/* SSCY0057 End						*/

/****************************************************************************/
/*********************************** 構造体　宣言 ***************************/
/****************************************************************************/

/****************************************************************************/
/*  ＴＥＦＵサブ共通部構造　　                                              */
/****************************************************************************/
struct	tefusub							/* ＴＥＦＵサブ共通部構造			*/
{
										/********* ＩＲＢ関連規定値 *********/
	unsigned short	tefuirbs ;			/* 固定ＩＲＢ数						*/
	unsigned short	tefukafu ;			/* ＩＲＢ過負荷移行数				*/
	unsigned short	tefukaij ;			/* ＩＲＢ過負荷解除数				*/
										/******** アボート引き継ぎ情報 ******/
	unsigned short	tefuoprq ;			/* FSAP登録要求発行数				*/
	unsigned short	tefuoprs ;			/* FSAP登録正常確認受信数			*/
	unsigned short	tefuclrq ;			/* FSAP削除要求発行数				*/
	unsigned short	tefuclrs ;			/* FSAP削除正常確認受信数			*/
	unsigned short	tefufspn ;			/* FSAP番号 						*/
										/***** RALLY 初期設定 ﾀｲﾐﾝｸﾞ調整 ****/
	short			tefurcnt ;			/* rvinitﾘﾄﾗｲ上限値					*/
	short			tefurtms ;			/* rvinit NG 時(ﾘﾄﾗｲ待ち時間秒)		*/
										/******* ACE-SMP･FTAM ＳＧ値 ********/
	unsigned short	tefufmax ;			/* ＦＣ最大値						*/
	unsigned short	tefursno ;			/* 応答側ＦＣ数						*/
	unsigned short	tefuovtm ;			/* 受信待ちﾌﾟﾘﾐﾃｨﾌﾞﾀｲﾑｱｳﾄ値			*/
	unsigned short	tefuintv ;			/* 大量データ送信間隔タイマ値		*/
	unsigned short	tefumdid ;			/* 自モジュールＩＤ					*/
	unsigned short	tefuacid ;			/* 起動側基本ＡＣＩＤ				*/
	unsigned short	tefuownl ;			/* 自通信識別名長さ					*/
	unsigned short	tefufspl ;			/* 自ＦＳＡＰ−ＩＤ長さ				*/
	unsigned char	tefurpnm[MLH_PRCNL];/* ﾚｽﾎﾟﾝﾀﾞ通知先APﾌﾟﾛｾｽ識別名	*/
	unsigned char	tefudfnm[MLHCFLEN];	/* 自通信識別名ファイルパス名		*/
	unsigned char	tefuowid[MLHCCLEN];	/* 自通信識別名						*/
	unsigned char	tefufsap[MLHFSAPL];	/* 自ＦＳＡＰ−ＩＤ					*/
	unsigned short	tefusaet ;			/* 発呼側ＡＥタイトル				*/
	unsigned short	tefusnet ;			/* 発呼側網種別						*/
	unsigned short	tefusadl ;			/* 発呼側アドレス長さ				*/
	unsigned short	tefusprl ;			/* 発呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ		*/
	unsigned char	tefusadr[MLH_ADLN] ;/* 発呼側アドレス					*/
	unsigned char	tefusprs[MLH_PSLL] ;/* 発呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ			*/
	unsigned short	tefutpno ;			/* ＴＳＡＰ番号						*/
	unsigned char	tefubdmy ;			/* （予備）							*/
	unsigned char	tefuswal ;			/* 自拡張ｱﾄﾞﾚｽ長さ					*/
	unsigned char	tefuswad[MLHEXADL];	/* 自拡張ｱﾄﾞﾚｽ						*/
	unsigned short	tefusvcl ;			/* サービスクラス					*/
	unsigned short	tefumaxs ;			/* 最大ストリング長					*/
	unsigned char	tefufunt[2] ;		/* 機能ユニット						*/
	unsigned char	tefuagrp[2] ;		/* 属性グループ						*/
										/******** 転送単位基準データ ********/
	unsigned short	tefumaxb ;			/* 最大送受信バッファ長				*/
	unsigned short	tefumins ;			/* 最小ストリング長					*/
										/*** ファイル生成パラメータ初期値 ***/
	long			tefuusid ;			/* 生成ﾌｧｲﾙ:新ﾕｰｻﾞID				*/
	long			tefugpid ;			/* 生成ﾌｧｲﾙ:新ｸﾞﾙｰﾌﾟID				*/
	long			tefubsiz ;			/* バイトストリームブロック長		*/
	long			tefuf1at ;			/* ＦＴＡＭ−１：属性				*/
	long			tefuf1rc ;			/* ＦＴＡＭ−１：レコード長			*/
	unsigned short	tefuf1bl ;			/* ＦＴＡＭ−１：ブロック長			*/
	unsigned short	tefuf1as ;			/* ＦＴＡＭ−１：初期領域サイズ		*/
	long			tefuf3at ;			/* ＦＴＡＭ−３：属性				*/
	long			tefuf3rc ;			/* ＦＴＡＭ−３：レコード長			*/
	unsigned short	tefuf3bl ;			/* ＦＴＡＭ−３：ブロック長			*/
	unsigned short	tefuf3as ;			/* ＦＴＡＭ−３：初期領域サイズ		*/
	long			tefui1at ;			/* ＩＮＴＡＰ−１：属性				*/
	long			tefui1rc ;			/* ＩＮＴＡＰ−１：レコード長		*/
	unsigned short	tefui1bl ;			/* ＩＮＴＡＰ−１：ブロック長		*/
	unsigned short	tefui1as ;			/* ＩＮＴＡＰ−１：初期領域サイズ	*/
						/* F_DATA送信規制関連SG値 @@@SSCY0057 Start			*/
	unsigned char		tefurstf;		/* 送信規制制御指示ﾌﾗｸﾞ				*/
										/*  0x01...送信規制制御要			*/
										/*  0x00...送信規制制御不要			*/
	unsigned char		tefursts;		/* 送信規制開始CVOSﾊﾞｯﾌｧ使用率(%)	*/
										/*  >=tefurstsのとき規制開始		*/
	unsigned char		tefurste;		/* 送信規制解除CVOSﾊﾞｯﾌｧ使用率(%)	*/
										/*  <tefursteのとき規制解除			*/
										/*  tefursts>=tefursteであること	*/
	unsigned char		tefursti;		/* 送信規制解除監視間隔(秒)			*/
	unsigned char		tefursv[4];		/* 予備								*/
										/* @@@SSCY0057 End					*/
};										/* ＴＥＦＵサブ共通部構造			*/
typedef	struct	tefusub		TEFUSUB;	/* ＴＥＦＵサブ共通部構造			*/


/****************************************************************************/
/*  ＴＥＦＵ個別部構造    　　                                              */
/****************************************************************************/
struct	tefupsz							/* ＴＥＦＵ個別部構造				*/
{
	unsigned char	tefupstn ;			/* ＴＥＦＵ個別部ステータス	<FJ003>	*/
	unsigned char	tefudumy[3] ;		/* 予備エリア				<FJ003>	*/
	unsigned short	tefudstl ;			/* 通信相手識別名長さ				*/
	unsigned short	tefusapl ;			/* 相手先ＦＳＡＰ−ＩＤ長さ			*/
	unsigned char	tefudsid[MLHCCLEN];	/* 通信相手識別名					*/
	unsigned char	tefursap[MLHFSAPL];	/* 相手先ＦＳＡＰ−ＩＤ				*/
	unsigned short	tefuraet ;			/* 着呼側ＡＥタイトル				*/
	unsigned short	tefurnet ;			/* 着呼側網種別						*/
	unsigned short	tefuradl ;			/* 着呼側アドレス長さ				*/
	unsigned short	tefurprl ;			/* 着呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ		*/
	unsigned char	tefuradr[MLH_ADLN] ;/* 着呼側アドレス					*/
	unsigned char	tefurprs[MLH_PSLL] ;/* 着呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ			*/
	unsigned short	tefulnno ;			/* ＬＮ								*/
	unsigned short	tefutpln ;			/* 相手ＴＳＡＰ−ＩＤ長さ			*/
	unsigned char	tefutpid[MLHTSAPL];	/* 相手ＴＳＡＰ−ＩＤ				*/
	unsigned char	tefusidl ;			/* ｻﾌﾞ･ｱﾄﾞﾚｽ長さ					*/
	unsigned char	tefupltl ;			/* ﾌﾟﾛﾄｺﾙID長さ						*/
	unsigned char	tefucdws ;			/* 着呼ｳｲﾝﾄﾞｳ･ｻｲｽﾞ					*/
	unsigned char	tefuciws ;			/* 発呼ｳｲﾝﾄﾞｳ･ｻｲｽﾞ					*/
	unsigned char	tefusbid[8] ;		/* ｻﾌﾞ･ｱﾄﾞﾚｽ						*/
	unsigned char	tefuplid[4] ;		/* ﾌﾟﾛﾄｺﾙID							*/
	unsigned char	tefutpcl ;			/* ｽﾙｰﾌﾟｯﾄ･ｸﾗｽ						*/
	unsigned char	tefucdps ;			/* 着呼ﾊﾟｹｯﾄｻｲｽﾞ					*/
	unsigned char	tefucips ;			/* 発呼ﾊﾟｹｯﾄｻｲｽﾞ					*/
	unsigned char	tefufast ;			/* ﾌｧｽﾄｾﾚｸﾄ							*/
	unsigned char	tefuheno[2] ;		/* 閉域相手指定番号					*/
	unsigned char	tefudmy0 ;			/* （予備）							*/
	unsigned char	tefuawal ;			/* 相手拡張ｱﾄﾞﾚｽ長さ				*/
	unsigned char	tefuawad[MLHEXADL];	/* 相手拡張ｱﾄﾞﾚｽ					*/
};										/* ＴＥＦＵ個別部構造				*/
typedef	struct	tefupsz		TEFUPSZ ;	/* ＴＥＦＵ個別部構造				*/

/*********************** <<<<< end of mlh_0001.h >>>>> **********************/
