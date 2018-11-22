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
/*          <teft.h>                       FTAMﾌﾟﾛｸﾞﾗﾑ SGﾃﾞｰﾀﾃｰﾌﾞﾙ構造体定義*/
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
/*  95.07.22 K.Kubota SSCY0089: FC確立応答監視時間定数の追加              	*/
/*                                                                          */
/*                                                                          */
/****************************************************************************/


/****************************************************************************/
/*********************************** ＤＥＦＩＮＥ部 *************************/
/****************************************************************************/
#define	MLHCCLEN	16					/* 通信識別名ｴﾘｱ長さ				*/
#define	MLHCFLEN	64					/* 自通信識別名ﾌｧｲﾙｴﾘｱ長さ			*/
#define	MLHEXADL	20					/* 拡張アドレスｴﾘｱ長さ				*/
#define	MLHEXMAX	40					/* 拡張アドレス最大長さ		<FJ003>	*/
#define	MLH_PRCNL	8					/* プロセス識別名長さ				*/
#define	MLHFSAPL	16					/* ＦＳＡＰ−ＩＤ長さ				*/
#define	MLHTSAPL	32					/* ＦＳＡＰ−ＩＤ長さ				*/
#define	MLH_ADLN	8					/* アドレス長さ						*/
#define	MLH_PSLL	4					/* ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ				*/


/****************************************************************************/
/*********************************** 構造体　宣言 ***************************/
/****************************************************************************/

/****************************************************************************/
/*  ＴＥＦＴサブ共通部構造　　                                              */
/****************************************************************************/
struct	teftsub							/* ＴＥＦＴサブ共通部構造			*/
{
										/********* ＩＲＢ関連規定値 *********/
	unsigned short	teftirbs ;			/* 固定ＩＲＢ数						*/
	unsigned short	teftkafu ;			/* ＩＲＢ過負荷移行数				*/
	unsigned short	teftkaij ;			/* ＩＲＢ過負荷解除数				*/
										/******** アボート引き継ぎ情報 ******/
	unsigned short	teftoprq ;			/* FSAP登録要求発行数				*/
	unsigned short	teftoprs ;			/* FSAP登録正常確認受信数			*/
	unsigned short	teftclrq ;			/* FSAP削除要求発行数				*/
	unsigned short	teftclrs ;			/* FSAP削除正常確認受信数			*/
	unsigned short	teftfspn ;			/* FSAP番号 						*/
										/***** RALLY 初期設定 ﾀｲﾐﾝｸﾞ調整 ****/
	short			teftrcnt ;			/* rvinitﾘﾄﾗｲ上限値					*/
	short			teftrtms ;			/* rvinit NG 時(ﾘﾄﾗｲ待ち時間秒)		*/
										/******* ACE-SMP･FTAM ＳＧ値 ********/
	unsigned short	teftfmax ;			/* ＦＣ最大値						*/
	unsigned short	teftrsno ;			/* 応答側ＦＣ数						*/
	unsigned short	teftovtm ;			/* 受信待ちﾌﾟﾘﾐﾃｨﾌﾞﾀｲﾑｱｳﾄ値			*/
	unsigned short	teftintv ;			/* 大量データ送信間隔タイマ値		*/
	unsigned short	teftmdid ;			/* 自モジュールＩＤ					*/
	unsigned short	teftacid ;			/* 起動側基本ＡＣＩＤ				*/
	unsigned short	teftownl ;			/* 自通信識別名長さ					*/
	unsigned short	teftfspl ;			/* 自ＦＳＡＰ−ＩＤ長さ				*/
	unsigned char	teftrpnm[MLH_PRCNL];/* ﾚｽﾎﾟﾝﾀﾞ通知先APﾌﾟﾛｾｽ識別名	*/
	unsigned char	teftdfnm[MLHCFLEN];	/* 自通信識別名ファイルパス名		*/
	unsigned char	teftowid[MLHCCLEN];	/* 自通信識別名						*/
	unsigned char	teftfsap[MLHFSAPL];	/* 自ＦＳＡＰ−ＩＤ					*/
	unsigned short	teftsaet ;			/* 発呼側ＡＥタイトル				*/
	unsigned short	teftsnet ;			/* 発呼側網種別						*/
	unsigned short	teftsadl ;			/* 発呼側アドレス長さ				*/
	unsigned short	teftsprl ;			/* 発呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ		*/
	unsigned char	teftsadr[MLH_ADLN] ;/* 発呼側アドレス					*/
	unsigned char	teftsprs[MLH_PSLL] ;/* 発呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ			*/
	unsigned short	tefttpno ;			/* ＴＳＡＰ番号						*/
	unsigned char	teftbdmy ;			/* （予備）							*/
	unsigned char	teftswal ;			/* 自拡張ｱﾄﾞﾚｽ長さ					*/
	unsigned char	teftswad[MLHEXADL];	/* 自拡張ｱﾄﾞﾚｽ						*/
	unsigned short	teftsvcl ;			/* サービスクラス					*/
	unsigned short	teftmaxs ;			/* 最大ストリング長					*/
	unsigned char	teftfunt[2] ;		/* 機能ユニット						*/
	unsigned char	teftagrp[2] ;		/* 属性グループ						*/
										/******** 転送単位基準データ ********/
	unsigned short	teftmaxb ;			/* 最大送受信バッファ長				*/
	unsigned short	teftmins ;			/* 最小ストリング長					*/
										/*** ファイル生成パラメータ初期値 ***/
	long			teftusid ;			/* 生成ﾌｧｲﾙ:新ﾕｰｻﾞID				*/
	long			teftgpid ;			/* 生成ﾌｧｲﾙ:新ｸﾞﾙｰﾌﾟID				*/
	long			teftbsiz ;			/* バイトストリームブロック長		*/
	long			teftf1at ;			/* ＦＴＡＭ−１：属性				*/
	long			teftf1rc ;			/* ＦＴＡＭ−１：レコード長			*/
	unsigned short	teftf1bl ;			/* ＦＴＡＭ−１：ブロック長			*/
	unsigned short	teftf1as ;			/* ＦＴＡＭ−１：初期領域サイズ		*/
	long			teftf3at ;			/* ＦＴＡＭ−３：属性				*/
	long			teftf3rc ;			/* ＦＴＡＭ−３：レコード長			*/
	unsigned short	teftf3bl ;			/* ＦＴＡＭ−３：ブロック長			*/
	unsigned short	teftf3as ;			/* ＦＴＡＭ−３：初期領域サイズ		*/
	long			tefti1at ;			/* ＩＮＴＡＰ−１：属性				*/
	long			tefti1rc ;			/* ＩＮＴＡＰ−１：レコード長		*/
	unsigned short	tefti1bl ;			/* ＩＮＴＡＰ−１：ブロック長		*/
	unsigned short	tefti1as ;			/* ＩＮＴＡＰ−１：初期領域サイズ	*/
						/* F_DATA送信規制関連SG値 @@@SSCY0057 Start			*/
	unsigned char		teftrstf;		/* 送信規制制御指示ﾌﾗｸﾞ				*/
										/*  0x01...送信規制制御要			*/
										/*  0x00...送信規制制御不要			*/
	unsigned char		teftrsts;		/* 送信規制開始CVOSﾊﾞｯﾌｧ使用率(%)	*/
										/*  >=teftrstsのとき規制開始		*/
	unsigned char		teftrste;		/* 送信規制解除CVOSﾊﾞｯﾌｧ使用率(%)	*/
										/*  <teftrsteのとき規制解除			*/
										/*  teftrsts>=teftrsteであること	*/
	unsigned char		teftrsti;		/* 送信規制解除監視間隔(秒)			*/
										/* ###SSCY0089 start				*/
	unsigned short		teftfctm;		/* FC確立応答監視時間(秒)			*/
										/*   0...監視しない					*/
										/*  >0...監視する					*/
	unsigned char		teftrsv[2];		/* 予備								*/
										/* ###SSCY0089 end					*/
										/* @@@SSCY0057 End					*/
};										/* ＴＥＦＴサブ共通部構造			*/
typedef	struct	teftsub		TEFTSUB;	/* ＴＥＦＴサブ共通部構造			*/


/****************************************************************************/
/*  ＴＥＦＴ個別部構造    　　                                              */
/****************************************************************************/
struct	teftpsz							/* ＴＥＦＴ個別部構造				*/
{
	unsigned char	teftpstn ;			/* ＴＥＦＴ個別部ステータス	<FJ003>	*/
	unsigned char	teftdumy[3] ;		/* 予備エリア				<FJ003>	*/
	unsigned short	teftdstl ;			/* 通信相手識別名長さ				*/
	unsigned short	teftsapl ;			/* 相手先ＦＳＡＰ−ＩＤ長さ			*/
	unsigned char	teftdsid[MLHCCLEN];	/* 通信相手識別名					*/
	unsigned char	teftrsap[MLHFSAPL];	/* 相手先ＦＳＡＰ−ＩＤ				*/
	unsigned short	teftraet ;			/* 着呼側ＡＥタイトル				*/
	unsigned short	teftrnet ;			/* 着呼側網種別						*/
	unsigned short	teftradl ;			/* 着呼側アドレス長さ				*/
	unsigned short	teftrprl ;			/* 着呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ長さ		*/
	unsigned char	teftradr[MLH_ADLN] ;/* 着呼側アドレス					*/
	unsigned char	teftrprs[MLH_PSLL] ;/* 着呼側ﾌﾟﾚｾﾞﾝﾃｰｼｮﾝｾﾚｸﾀ			*/
	unsigned short	teftlnno ;			/* ＬＮ								*/
	unsigned short	tefttpln ;			/* 相手ＴＳＡＰ−ＩＤ長さ			*/
	unsigned char	tefttpid[MLHTSAPL];	/* 相手ＴＳＡＰ−ＩＤ				*/
	unsigned char	teftsidl ;			/* ｻﾌﾞ･ｱﾄﾞﾚｽ長さ					*/
	unsigned char	teftpltl ;			/* ﾌﾟﾛﾄｺﾙID長さ						*/
	unsigned char	teftcdws ;			/* 着呼ｳｲﾝﾄﾞｳ･ｻｲｽﾞ					*/
	unsigned char	teftciws ;			/* 発呼ｳｲﾝﾄﾞｳ･ｻｲｽﾞ					*/
	unsigned char	teftsbid[8] ;		/* ｻﾌﾞ･ｱﾄﾞﾚｽ						*/
	unsigned char	teftplid[4] ;		/* ﾌﾟﾛﾄｺﾙID							*/
	unsigned char	tefttpcl ;			/* ｽﾙｰﾌﾟｯﾄ･ｸﾗｽ						*/
	unsigned char	teftcdps ;			/* 着呼ﾊﾟｹｯﾄｻｲｽﾞ					*/
	unsigned char	teftcips ;			/* 発呼ﾊﾟｹｯﾄｻｲｽﾞ					*/
	unsigned char	teftfast ;			/* ﾌｧｽﾄｾﾚｸﾄ							*/
	unsigned char	teftheno[2] ;		/* 閉域相手指定番号					*/
	unsigned char	teftdmy0 ;			/* （予備）							*/
	unsigned char	teftawal ;			/* 相手拡張ｱﾄﾞﾚｽ長さ				*/
	unsigned char	teftawad[MLHEXADL];	/* 相手拡張ｱﾄﾞﾚｽ					*/
};										/* ＴＥＦＴ個別部構造				*/
typedef	struct	teftpsz		TEFTPSZ ;	/* ＴＥＦＴ個別部構造				*/

/*********************** <<<<< end of mlh_0001.h >>>>> **********************/
