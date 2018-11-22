/*****************************************************************/
/*                                                               */
/*              tfac.h                                           */
/*                                                               */
/*        TFAC ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ  87.12.05                            */
/*                     変更  94.10.26 JI  変更者  西山  伸       */
/*                     変更  94.12.20 JJ  変更者  西山  伸       */
/*                     変更  95.03.17 JK  変更者  (株)ｺﾑｱｯﾌﾟ     */
/*                                        故障処理票  ST1761     */
/*                     変更  95.03.23 JL  変更者  田中  宏之     */
/*                                        OSP仕様変更に伴う修正  */
/*                     変更  95.06.13 JM  変更者  北西　智洋　　 */
/*                                        LICP起動に伴う修正　　 */
/*                     変更  95.08.22 JN  変更者  (株)ｺﾑｱｯﾌﾟ     */
/*                                        故障処理票  ST3176     */
/*                     変更  95.10.23 JO  変更者  (株)ｺﾑｱｯﾌﾟ     */
/*                                      仕様変更要求書  SSCY0126 */
/*                     変更  95.12.25 JP  変更者  北西　智洋     */
/*                                        故障処理票  ST3895     */
/*                     変更  95.01.23 JQ  変更者  (株)ｺﾑｱｯﾌﾟ     */
/*                                      仕様変更要求書  SSCY0063 */
/*                     変更  95.12.25 JR  変更者  北西　智洋     */
/*                                        故障処理票  ST3985     */
/*****************************************************************/

struct mdfacsb {
	short	tfacpbdw;				    /* LMﾌﾟｰﾙﾊﾞｯﾌｧID下限値     JM JJ */
	short   tfaccmdw;	                /* LM共用ﾒﾓﾘID下限値       JM JJ */
	long    tfacpbad;	                /* LICPﾊﾞｯﾌｧﾊﾟﾗﾒｰﾀ格納先ｱﾄﾞﾚｽ JR */
	char    tfacprst;                   /* 処理中種別                    */
	char    tfacikfg;	                /* 一括処理フラグ                */
	short   tfacsysc;	                /* システムコールリトライ回数    */
	long    tfacptct;	                /* パスクローズ応答監視タイマ値  */
	long    tfackait;	                /* 回線監視ﾘﾄﾗｲｵｰﾌﾟﾝﾀｲﾏ値        */
	long    tfacrcov;	                /* 回線障害回復検出タイマ値      */
	long    tfacsyst;	                /* システムコールリトライタイマ値*/
	long    tfacrlat;	                /* ＲＬＡ同期タイマ値            */
	char    tfactdat[64];               /* 折り返し試験用データ          */
	char    tfacpuf0;                   /* ﾊﾞｯﾌｧﾊﾟﾗﾒｰﾀ確保管理ﾌﾗｸﾞ PR JJ */
    char    tfacpuf1;                   /* 共用ﾒﾓﾘID使用管理ｶｳﾝﾀ   JQ JM */
	short   tfactcnt;                   /* 折返し試験処理中回線数  JN JJ */
	char    tfacword[4];                /* パスワード                    */
										/* １行削除                   JI */
	long    tfacstrt;                   /* 通信停止要求 応答 待ち時間 JJ */
    short   tfaccllc;                   /* 回線接続ﾘﾄﾗｲ数             JO */
    char    tfacyob0[2];                /* 予備                    J0 JJ */
};
typedef struct mdfacsb MDFACSB;         /* DCP ﾖｳ                        */
typedef struct mdfacsb TFACSUB;         /* FIP ﾖｳ                        */

struct mdfacko {
	char	tfackbst;			        /*  ｺﾍﾞﾂﾌﾞ ｽﾃｰﾀｽ                 */
	char	tfactvrn;                   /*  ｶｲｾﾝ ｵﾘｶｴｼ ｼﾃｲ               */
	short	tfacexen;                   /*  ｷﾘｶｴｻｷ ｴﾝﾄﾘ NO               */
	short	tfacpuno;			        /*  PU ﾊﾞﾝｺﾞｳ                    */
	short	tfacchno;		            /*  ﾁｬﾈﾙ ﾊﾞﾝｺﾞｳ                  */
	char	tfacfiln[22];			    /*  ﾄｸｼｭ ﾌｧｲﾙ ﾒｲ                 */
 	short	tfacpcnt;                   /*  カウンタ                     */
	long	tfacfdsc;           		/*  ﾌｧｲﾙ ﾃﾞｨｽｸﾘﾌﾟﾀ               */
	char	tfacsygi;           		/*  ｼｮｳｶﾞｲ ｽﾃｰﾀｽ                 */
	char	tfacchst;               	/*  ﾌｧｲﾙ ｽﾃｰﾀｽ                   */
	char	tfacchs2;               	/*  物理チャネルステータス       */
	char	tfaccykf;               	/*  着呼状態フラグ               */
	char	tfaclpmg;               	/*  回復メッセージ出力有無       */
	char	tfacuinf;               	/*  チャネル運用情報             */
	char	tfacchcl;               	/*  チャネル閉塞フラグ           */
	char	tfacrecv;               	/*  障害時 回復監視の要・不要 JI */
	short	tfacfapn;               	/*  TFAP ｾﾝﾄｳ ｴﾝﾄﾘ NO            */
	short	tfacpthn;               	/*  ﾛﾝﾘ ﾊﾟｽ ｽｳ                   */
	char	tfacteln[16];        		/*  ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ               JI */
	char	tfactlsu;      				/*  ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ ﾕｳｺｳ ｹﾀｽｳ        */
	char	tfacptcl;               	/*  要求元種別退避域       JJ JK */
	char	tfacyob2[2];               	/*  ﾖﾋﾞ 2                     JI */
	long	tfacmiaa;               	/*  MIA ﾀｲﾋ ｱﾄﾞﾚｽ                */
										/*  １行削除                  JI */
	short	tfacrxtn;   				/*  rxltｴﾝﾄﾘ番号(rallyﾃｰﾌﾞﾙ)  JI */
	char	tfacnapo;   				/*  rally回線管理ＡＰ有無     JL */
	char	tfacapno;   				/*  ＡＰのPU番号        JM JI JL */
	char	tfactel2[16];        		/*  ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ               JJ */
	char	tfactls2;					/*  ﾃﾞﾝﾜ ﾊﾞﾝｺﾞｳ ﾕｳｺｳ ｹﾀｽｳ     JJ */
	char	tfacyob4[3];               	/*  ﾖﾋﾞ 4                     JJ */
	short	tfachlen;               	/*  TFAH ｾﾝﾄｳ ｴﾝﾄﾘ NO         JJ */
	short	tfachlno;               	/*  ｴﾝﾄﾘ ｽｳ                   JJ */
	short	tfacxlen;               	/*  TFAX or TFALｾﾝﾄｳ ｴﾝﾄﾘ NO  JJ */
	short	tfacxlno;               	/*  ｴﾝﾄﾘ ｽｳ                   JJ */
	unsigned	char	tfacprtc;		/*  該当物理回線のTRADE処理種別    JJ */
	unsigned	char	tfacnetw;		/*  該当物理回線種別               JJ */
	unsigned	char	tfacbulp;		/*  ＢＵ回線プールＩＤ             JJ */
	unsigned	char	tfacclgl;		/*  tfacclgnの有効ｵｸﾃｯﾄ数          JJ */
				char	tfacclgn[34];	/*  ISDN回線発呼時発信元識別設定域 JJ */
	unsigned	char	tfaccapl;		/*  tfaccapaの有効ｵｸﾃｯﾄ数          JJ */
				char	tfaccapa[11];	/*  ISDN回線発呼時伝達機能等設定域 JJ */
	unsigned	char	tfacchil;		/*  tfacchidの有効ｵｸﾃｯﾄ数          JJ */
				char	tfacchid;		/*  ISDN回線発呼時ﾁｬﾈﾙ識別設定域   JJ */
	unsigned	char	tfaccl1l;		/*  tfaccld1の有効ｵｸﾃｯﾄ数          JJ */
				char	tfaccld1[21];	/*  ISDN回線発呼時ｻﾌﾞadr識別設定域 JJ */
	unsigned	char	tfaccl2l;		/*  tfaccld2の有効ｵｸﾃｯﾄ数          JJ */
				char	tfaccld2[21];	/*  ISDN回線発呼時ｻﾌﾞadr識別設定域 JJ */
	unsigned	char	tfacllcl;		/*  tfacllcpの有効ｵｸﾃｯﾄ数          JJ */
				char	tfacllcp[14];	/*  ISDN回線発呼時通信可ﾁｪｯｸ設定域 JJ */
	unsigned	char	tfachlcl;		/*  tfachlcpの有効ｵｸﾃｯﾄ数          JJ */
				char	tfachlcp[2];	/*  ISDN回線発呼時通信可ﾁｪｯｸ設定域 JJ */
	unsigned	char	tfacusel;		/*  tfacuserの有効ｵｸﾃｯﾄ数          JJ */
				char	tfacuser[129];	/*  ISDN回線発呼時ﾕｰｻﾞ間情報伝達域 JJ */
	unsigned	long	tfaclpid;		/*  ＬＩＣＰプロセスＩＤ           JJ */
				char	tfaccaln[2];    /*  ＩＳＤＮ呼制御時の呼番号退避域 JJ */
                char    tfacdown;       /*  ｼｽﾃﾑﾀﾞｳﾝｽﾃｰﾀｽ                  JK */
                char    tfacichs;       /*  ISDN回線チャネルステータス     JK */
                long    tfacpidm;       /*  共用ﾒﾓﾘＩＤ			     	JR JK */
                char   tfacyob5[28];    /*  ﾖﾋﾞ 5              JR JQ JM JJ JK */
};
typedef struct mdfacko MDFACKO;         /*  DCP ﾖｳ                       */
typedef struct mdfacko TFACPSZ;         /*  FIP ﾖｳ                       */
