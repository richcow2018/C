/**-------------------------------------------------------------------------*/
/*																			*/
/*	   動的システム変更(ｽｹｼﾞｭｰﾗ関連) 作成:94/09/28							*/
/*																			*/
/*	96.04.04 K.Kubota SSCY0157: mm_rvrs Requests to mme000 on alter ACE		*/
/**-------------------------------------------------------------------------*/

/****************************************************************************/
/*																			*/
/*								 ＩＲコード宣言								*/
/*																			*/
/****************************************************************************/

#define	 IR01	   0x01
#define	 IR02	   0x02
#define	 IR03	   0x03
#define	 IR04	   0x04
#define	 IR05	   0x05
#define	 IR06	   0x06
#define	 IR07	   0x07
#define	 IR08	   0x08
#define	 IR09	   0x09
#define	 IR0A	   0x0A
#define	 IR0B	   0x0B
/****************************************************************************/
/*																			*/
/*							  サブＩＲコード宣言							*/
/*																			*/
/****************************************************************************/

#define	 SIR00	   0x00
#define	 SIR01	   0x01
#define	 SIR02	   0x02
#define	 SIR03	   0x03
/****************************************************************************/
/* UNIT ID for SCHEDULER Control ###SSCY0157								*/
#define	 UID_RVR   0x01					/* 逆正規化（とりあえず）　			*/
										/* ###SSCY0157						*/

/****************************************************************************/
/*								一般定数定義								*/
/****************************************************************************/
#define	DYREC_EVNUM	   3				/* 受信電文							*/
/****************************************************************************/
/*						　　　　　			  　　　　　　　　　　　　　　　*/
/*						　　　　　構造体宣言  　　　　　　　　　　　　　　　*/
/*						　　　　　			  　　　　　　　　　　　　　　　*/
/****************************************************************************/

/****************************************************************************/
/*				  リモートメンテナンス受信電文解析用構造体					*/
/****************************************************************************/
typedef	struct
{
	long				mkcode;			/* ＭＫコード						*/
	long				ifcode;			/* インタフェースコード				*/
	unsigned char		ircode;			/* ＩＲコード						*/
	unsigned char		subcode;		/* サブＩＲコード					*/
	unsigned char		dmid;			/* 送信先機能ユニットＩＤ			*/
} ANALYSIS;
/****************************************************************************/
/*	状態遷移マトリクス作成用構造体											*/
/*	  ※  各機能ユニット毎に必要なサービス項目を要素とするテーブルを作る。	*/
/****************************************************************************/
typedef	struct
{
	long	(* fnc)();
} COMMTX ;

/****************************************************************************/
/*						ＩＲＢ−ＲＭＮ用専用構造(１)						*/
/*			 ※	 ＲＭＮプロセス機能ユニット間ＩＲＢフォーマット				*/
/*			 ※	 メッセージハンドラ付加ルーチンも使用する。					*/
/****************************************************************************/

typedef	struct
{
	long		dumy1[5] ;				/* IRB固定部相当					*/
	short		info1 ;					/* 情報１							*/
	short		info2 ;					/* 情報２							*/
	long		info3 ;					/* 情報３							*/
	long		info4 ;					/* 情報４							*/
	long	   *adrs1 ;					/* アドレス１						*/
	long	   *adrs2 ;					/* アドレス２						*/
	long	   *adrs3 ;					/* アドレス３						*/
	long		dumy2[5] ;				/* Varriable Area					*/
} DYRECIRB ;
