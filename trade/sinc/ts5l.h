/****************************************************************************/
/*　著作権　１９９６                                                        */
/*            ＮＴＴデータ通信株式会社                                      */
/*              金融システム事業本部                                        */
/*  収容物　                                                                */
/****************************************************************************/
/*　ファイル名：ts5l.h                                                      */
/*  機能      ：ＬＵ制御テーブル                                            */
/*  作成日　　：                                                            */
/*  変更日    ：                                                            */
/****************************************************************************/
#if TS5L_INCLUDE
#else
#define TS5L_INCLUDE 1
/*--------------------------------*/
/* サブ共通部                     */
/*--------------------------------*/
struct mds5lsb {
	long        ts5lwait;               /* 送信系切断待ちタイマ値           */
	long        ts5lrspt;               /* 未解決応答監視タイマ値           */
	long		ts5lldas;				/* LWS非活性化時応答ｾﾝｽｺｰﾄﾞ			*/
	long		ts5llkss;				/* LWS強制終了時応答ｾﾝｽｺｰﾄﾞ			*/
	long		ts5lrtos;				/* 未解決応答監視ﾀｲﾑｱｳﾄ時応答ｾﾝｽｺｰﾄﾞ*/
	long		ts5lnors;				/* readなし時応答ｾﾝｽｺｰﾄﾞ			*/
	char        ts5lyobi[12];           /* 予備                             */
};

typedef struct mds5lsb TS5LSUB;         /* FIP ﾖｳ                           */

/*--------------------------------*/
/* 個別部                         */
/*--------------------------------*/
struct mds5lko {
	long        ts5lkbst;               /* 個別部ステータス                 */
	short       ts5lluno;               /* ＬＵ番号                         */
	short       ts5llugn;               /* ＬＵグループ番号                 */
	short		ts5lfahe;				/* TFAHｴﾝﾄﾘ番号						*/
	short		ts5lyob2;				/* 予備								*/
	unsigned long	ts5lrcvs;			/* 最大受信RU長上限値				*/
	unsigned char	ts5lrcvp;			/* 受信WS上限値						*/
	unsigned char	ts5llufg;			/* 特定LWS振り分けﾌﾗｸﾞ(1:特定 0:他)	*/
	unsigned char	ts5lyob3[2];		/* 予備								*/
	unsigned long	ts5lsnds;			/* 最大送信RU長下限値				*/
	unsigned short	ts5lwrmx;			/* LUﾗｲﾄ多重限度					*/
	unsigned short	ts5lyob4;			/* 予備								*/
	char        ts5lyob5[12];           /* 予備                             */
};

typedef struct mds5lko TS5LPSZ;         /* FIP ﾖｳ                           */


#define  TS5LSBSZ   (sizeof(TS5LSUB))   /* TS5Lｻﾌﾞ共通部ｻｲｽﾞ                */
#define  TS5LKOSZ   (sizeof(TS5LPSZ))   /* TS5L個別部ｻｲｽﾞ                   */

#endif
