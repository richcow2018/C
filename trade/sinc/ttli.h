/****************************************************************************/
/*                                                                          */
/*      ＴＴＬＩテーブルフォーマット  ttli.h                  (93.11.22)    */
/*                                                                          */
/*  修正   :  ST4626　96.12.11　ｻﾌﾞ共通部の予備をttlimetに変更              */
/****************************************************************************/

struct  ttlisub {                       /* サブ共通部                       */
    char   ttlipsnm[2][22];             /* ＴＣＰ／ＩＰ特殊ファイル名       */
    unsigned short  ttlinivt;           /* ＮＥＴＣＴＬリトライタイマ       */
    char   ttlimet;                 	/* メモリ種別                       */
										/* ST4626 予備をメモリ種別に変更	*/
    char   ttliyob0;                    /* 予備                             */
};
typedef struct ttlisub MDTLIPS;         /* ＤＣＰ用                         */
typedef struct ttlisub TTLIPS;          /* ＦＩＰ用                         */

struct  ttlipsz {                       /* 個別部                           */
    long   			ttliipa0;           /* ＩＰアドレス０                   */
    unsigned char   ttlimca0[6];        /* ＭＡＣアドレス０                 */
    short  			ttlimct0;           /* ＭＡＣタイプ０                   */
    long   			ttliipa1;           /* ＩＰアドレス１                   */
    unsigned char   ttlimca1[6];        /* ＭＡＣアドレス１                 */
    short  			ttlimct1;           /* ＭＡＣタイプ１                   */
    long   			ttlismsk;           /* サブネットマスク                 */
    unsigned long	ttlirbfh;           /* 受信バッファ上限値               */
    unsigned long	ttlirbfl;           /* 受信バッファ下限値               */
    unsigned long	ttlisbfh;           /* 送信バッファ上限値               */
    unsigned long	ttlisbfl;           /* 送信バッファ下限値               */
    unsigned char	ttliwrmx;           /* 同時送信要求最大数               */
    unsigned char	ttliremx;           /* 同時受信要求最大数               */
    unsigned short	ttliivtd;           /* ＤＥＴＡＣＨ発行リトライタイマ   */
    char   			ttliecdt[8];        /* エコー試験データ                 */
    unsigned char	ttliecdc;           /* エコー試験データ繰り返し回数     */
    char   			ttliyob0[3];        /* 予備０                           */
};
typedef struct  ttlipsz MDTLIKO;        /* ＤＣＰ用                         */
typedef struct  ttlipsz TTLIPSZ;        /* ＦＩＰ用                         */
