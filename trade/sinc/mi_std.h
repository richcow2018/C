/****************************************************************************/
/* ファイル名：　mi_std.h                                                   */
/* 機能  　　：  テーブルアドレス位置                                       */
/*               ＩＲコード                                                 */
/*               サブＩＲコード                                             */
/*               モジュールＩＤ                                             */
/*               ＩＲＢテンプレート                                         */
/*               システムコールプロトタイプ                                 */
/*               システムコールアーギュメント域テンプレート                 */
/* 作成日　  ：  1993.12.13                                                 */
/* 変更日　  ：  1994.09.16                                             PD01*/
/*   故障処理票(ST1068) ＩＣＰ返却通知コード修正                            */
/* 変更日　  ：  1994.10.14                                             PD0A*/
/*   故障処理票(ST1761) 統合Ｉ／Ｏ対応                                      */
/* 変更日　　：  1995.06.13                                             PD0C*/
/*   仕様変更要求書(SSCY0062) 動的システム変更対応                          */
/* 変更日　　：  1995.07.27                                              M01*/
/*   故障処理票(ST0713) 回線種別判定修正                                    */
/* 変更日　　：  1995.07.12                                             PD0E*/
/*   仕様変更要求書(SSCY0094) 切替応答変更対応                              */
/* 変更日　　：  1995.08.03                                             PD0F*/
/*   仕様変更要求書(SSCY0097) 初期ｵｰﾌﾟﾝでのﾌﾟﾛｾｽｱﾎﾞｰﾄ回避                   */
/* 変更日　　：  1995.08.09                                             PD0G*/
/*   仕様変更要求書(SSCY0098) 回線種別の無効化                              */
/* 変更日　　：  1995.09.29                                             PD0J*/
/*   仕様変更要求書(SSCY0113) ４Ｗ故障検出変更対応                          */
/* 変更日　　：  1995.11.07                                             PD0N*/
/*   仕様変更要求書(SSCY0126) X.25ｽﾗｲﾄﾞﾘﾄﾗｲ対応                             */
/* 変更日　　：  1995.11.29                                             PD0O*/
/*   仕様変更要求書(SSCY0063) ＬＩＣＰ再起動対応                            */
/* 変更日　　：  1996.03.05                                             PD0R*/ 
/*   仕様変更要求書(SSCY0156) X.25回復監視変更対応                          */ 
/* 変更日　　：  1996.07.12                                             PD02*/ 
/*   故障処理票(ST4483) MIA_BCCN修正                                        */
/* 変更日　　：  1996.12.17                                             PD0V*/ 
/*   仕様変更要求書(SSCY0188) PU,CH番号ﾁｪｯｸ機能修正                         */
/* 変更日　　：  1997.03.05                                             PD0X*/ 
/*   仕様変更要求書(SSCY0194) ﾒｯｾｰｼﾞ追加			                        */
/* 変更日　　：  1997.03.17                                             PD0Y*/ 
/*   故障処理票(ST4810) ISDN非同期通知制御追加                              */
/* 変更日　　：  1997.05.12                                             PD0Z*/ 
/*   故障処理票(ST4834) LICP終了監視変更                                    */
/* 変更日　　：  1997.06.25                                          ST4868 */ 
/*   故障処理票(ST4868) ISDN非同期通知制御修正                              */
/* 変更日　　：  1998.02.16                                        SSCY0203 */ 
/*   仕様変更(SSCY0203) 代行中故障Ｂｕ回線の再使用							*/
/****************************************************************************/
#include <tcom.h>                       /* SMPﾃｰﾌﾞﾙ共通部定義               */
#include <psect.h>                      /* psect                            */
#include <mcs_0000.h>                   /* スケジューラ共通ヘッダファイル   */
#include <mf.h>                         /* ｍｆ．ｈ                         */
#include <mi_log.h>                     /* ﾌﾟﾛｾｽﾛｸﾞ取得関連ﾏｸﾛ              */

extern   PSCPSECT      pscparea;        /* PSECT域ﾎﾟｲﾝﾀ                     */

#ifdef  DMY
#undef  C_IOPEN
#define C_IOPEN(p1,p2,p3,p4,p5,p6,p7) dmy_iopen(p1,p2,p3,p4,p5,p6,p7)  
#undef  C_ICLOSE
#define C_ICLOSE(p1,p2) dmy_iclose(p1,p2)  
#undef  C_IIOCTL
#define C_IIOCTL(p1,p2,p3,p4,p5) dmy_iioctl(p1,p2,p3,p4,p5)
#undef  C_IOCTL
#define C_IOCTL(p1,p2,p3,p4) dmy_ioctl(p1,p2,p3,p4)
#undef  C_CONFIG
#define C_CONFIG(p1,p2,p3) dmy_config(p1,p2,p3)
#endif

/**************************************/
/* ＮＶＴプログラム個別域テンプレート */
/**************************************/
typedef struct {
    long            chead[3];           /* コンテキストヘッダー             */
    short           lctxcnt;            /* 回線制御ｺﾝﾃｷｽﾄ数                 */
    char            battvrn;            /* 一括処理要求元種別               */
    char            mode;               /* 起動モード                       */
    long            lctxa;              /* 回線制御ｺﾝﾃｷｽﾄ先頭ｱﾄﾞﾚｽ          */
    long            rnlpt;              /* TLPT資源番号                     */
    long            batreqa;            /* 一括処理要求ｱﾄﾞﾚｽ退避域          */
    long            tblp;               /* SGﾃｰﾌﾞﾙ先頭ｱﾄﾞﾚｽ                 */
    long            ukeno;              /* 一括処理要求受付番号             */
    long            faceno;             /* 一括処理TFACｴﾝﾄﾘNO               */
    long            hctxa;              /* 排他制御ｺﾝﾃｷｽﾄ先頭ｱﾄﾞﾚｽ      PD0C*/
    char            pcchkf;             /* PU,CHﾁｪｯｸ指定                PD0V*/
	char			rcyflg;				/* 代行中故障回線再使用指定 SSCY0203*/
    short           lp_bueno;           /* 最終選択ＢｕエントリSSCY0203 PD0V*/
										/* (HDLCﾙｰﾌﾟ&-rcy指定時有効)SSCY0203*/
} MINVTP;

/**************************************/
/* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄ上の各種ﾃｰﾌﾞﾙの位置 */
/**************************************/
#define TCST_NO    0                    /* ＴＣＳＴアドレスの位置           */
#define TPCT_NO    1                    /* ＴＰＣＴアドレスの位置           */
#define TPAT_NO    2                    /* ＴＰＡＴアドレスの位置           */
#define TLGT_NO    3                    /* ＴＬＧＴアドレスの位置           */
#define TLPT_NO    4                    /* ＴＬＰＴアドレスの位置           */
#define TFAP_NO    5                    /* ＴＦＡＰアドレスの位置           */
#define TFAC_NO    6                    /* ＴＦＡＣアドレスの位置           */
#define TFAH_NO    7                    /* ＴＦＡＨアドレスの位置           */
#define TFAX_NO    8                    /* ＴＦＡＸアドレスの位置       PD0A*/
#define TSST_NO    9                    /* ＴＳＳＴアドレスの位置       PD0A*/
#define TFAL_NO   10                    /* ＴＦＡＬアドレスの位置       PD0C*/

/**************************************/
/* 返却値定義                         */
/**************************************/
#define MINORMAL     0                  /* 正常                             */
#define MIERR       -1                  /* 異常                             */
#define MINOSING     0                  /* 存在しない                       */
#define ZERO         0                  /* ０                               */
#define MIBUSY       0x9f80000c         /* ﾋﾞｼﾞｰ                            */
#define MIPUOUS      0x9f80000d         /* PU ous (out of service)          */
#define MIDMAOUS     0x9f80000e         /* DMAC ous (out of service)        */
#define MIIOCOUS     0x9f80000f         /* IOC ous (out of service)         */
#define RTN_RETRY    1                  /* ﾘﾄﾗｲ可能                         */
#define RTN_END      2                  /* ﾘﾄﾗｲ不可                         */
#define RTN_ERR      3                  /* エラー                       PD0F*/
#define ERR80        0x80               /* ﾊｰﾄﾞ障害                   stPD0A*/
#define ERR90        0x90               /* ﾓﾃﾞﾑDSU障害                      */
#define ERRA0        0xA0               /* ﾃﾞｰﾀﾘﾝｸﾚﾍﾞﾙ異常              PD0R*/
#define ERRA3        0xA3               /* 装置制御レベル異常               */
#define ERRE5        0xE5               /* 網制御、回線折返し               */
#define ERRCHK       0xffff0000         /* 返却値ﾁｪｯｸ用                     */
#define RTNCHK       0x00f00000         /* 共通ｴﾗｰﾁｪｯｸ用                    */
#define MDCHK        0x00ffffff         /* ﾓｰﾄﾞ切断検出ﾁｪｯｸ用               */
#define ERR_DCON     0x00F00002         /* ﾓｰﾄﾞ切断検出                     */

#define DYR_ERR1     0x00010000         /* 折返し試験中               stPD0C*/
#define DYR_ERR2     0x00020000         /* 切替、切戻し、臨時接続処理中     */
#define DYR_ERR3     0x00030000         /* 排他区間設定中                   */
#define DYR_ERR4     0x00040000         /* 切替元現用回線                   */
#define DYR_ERR5     0x00050000         /* 切替先BU回線                     */
#define DYR_ERR6     0x00060000         /* 臨時接続中　               edPD0C*/

/**************************************/
/* ４Ｗ返却値定義                     */
/**************************************/
#define TOUT1_4W     0xC1E50000         /* 受信ﾃﾞｰﾀﾀｲﾑｱｳﾄ(CDｵﾌ)             */
#define TOUT2_4W     0xC1E50001         /* 受信ﾃﾞｰﾀﾀｲﾑｱｳﾄ(CDｵﾝ)             */
#define ERRC1F0      0xC1F00000         /* 共通ｴﾗｰ                          */
#define ERRC1F2      0xC1F20000         /* 共通ｴﾗｰ                          */
#define ERRC180      0xC1800000         /* ﾊｰﾄﾞ障害                         */
#define ERRC190      0xC1900000         /* ﾓﾃﾞﾑDSU障害                      */
#define ERRC1E4      0xC1E40000         /* 網制御、回線折返し               */
#define ERRC1E5      0xC1E50000         /* 網制御、回線折返し               */
#define ERRC1A2      0xC1A20000         /* 装置制御レベル異常               */
#define ERRC1A3      0xC1A30000         /* 装置制御レベル異常               */
#define ERRC1A0      0xC1A00000         /* 装置制御レベル異常               */

/**************************************/
/* HDLCﾙｰﾌﾟ返却値定義                 */
/**************************************/
#define TOUT_HDLC    0xC2E50000         /* 受信ﾃﾞｰﾀﾀｲﾑｱｳﾄ                   */
#define CHKF_HDLC    0xC2E50001         /* 受信ﾃﾞｰﾀﾁｪｯｸﾌｨｰﾙﾄﾞｴﾗｰ            */
#define ERRC2F0      0xC2F00000         /* 共通ｴﾗｰ                          */
#define ERRC2F1      0xC2F10000         /* 共通ｴﾗｰ                          */
#define ERRC2F2      0xC2F20000         /* 共通ｴﾗｰ                          */
#define ERRC280      0xC2800000         /* ﾊｰﾄﾞ障害                         */
#define ERRC290      0xC2900000         /* ﾓﾃﾞﾑDSU障害                      */
#define ERRC2F3      0xC2F30000         /* 網制御、回線折返し               */
#define ERRC2E4      0xC2E40000         /* 網制御、回線折返し               */

/**************************************/
/* X25返却値定義                      */
/**************************************/
#define ERRE8F0      0xE8F00000         /* 共通ｴﾗｰ                          */
#define ERRE8F1      0xE8F10000         /* 共通ｴﾗｰ                          */
#define ERRE8F2      0xE8F20000         /* 共通ｴﾗｰ                          */
#define ERRE880      0xE8800000         /* ﾊｰﾄﾞ障害                         */
#define ERRE890      0xE8900000         /* ﾓﾃﾞﾑDSU障害                      */
#define ERRE8F3      0xE8F30000         /* 網制御、回線折返し               */
#define ERRE8E5      0xE8E50000         /* 網制御、回線折返し               */
#define ERRE8A0      0xE8A00000         /* ﾃﾞｰﾀﾘﾝｸﾚﾍﾞﾙ異常                  */
#define ERRE8B0      0xE8B00000         /* ﾈｯﾄﾜｰｸﾚﾍﾞﾙ異常                   */
#define ERRE8B1      0xE8B10000         /* ﾈｯﾄﾜｰｸﾚﾍﾞﾙ異常                   */
#define ERRE8B3      0xE8B30000         /* ﾈｯﾄﾜｰｸﾚﾍﾞﾙ異常                   */

/**************************************/
/* ISDN返却値定義                     */
/**************************************/
#define ERRDBF0      0xDBF00000         /* 共通ｴﾗｰ                          */
#define ERRDBF1      0xDBF10000         /* 共通ｴﾗｰ                          */
#define ERRDBF2      0xDBF20000         /* 共通ｴﾗｰ                          */
#define ERRDB80      0xDB800000         /* ﾊｰﾄﾞ障害                         */
#define ERRDBA0      0xDBA00000         /* ﾃﾞｰﾀﾘﾝｸﾚﾍﾞﾙ異常                  */
#define ERRDBB0      0xDBB00000         /* プロトコル障害             edPD0A*/

/**************************************/
/* ＳＣＰ関数用返却値定義             */
/**************************************/
#define SHORING      0x0000f000         /* 処理異常                     PD01*/
#define SIZENG       0x0000f001         /* サイズ異常                   PD01*/

/**************************************/
/* 設定値                             */
/**************************************/
#define SETSYU       0x01               /* 格納域種別                   PD01*/
#define DATASYU      0x10               /* ﾃﾞｰﾀ種別                     PD01*/
#define TDATASZ      64                 /* TFAC折返し試験用ﾃﾞｰﾀｻｲｽﾞ     PD01*/
#define TMIASZ       100                /* 折返し試験時要求電文ｻｲｽﾞ     PD01*/

#define    SUBADDR_MAX  23              /* 着ｻﾌﾞｱﾄﾞﾚｽ最大長                 */
#define    JTQ931     0x08              /* JT-Q931のﾕｰｻﾞ･網制御ﾒｯｾｰｼﾞ stPD0A*/
#define    SETUP      0x05              /* 呼設定(SETUP)                    */
#define    DISCON     0x45              /* 切断(DISCONNECT)                 */
#define    ICAUSESZ   4                 /* 理由表示ｻｲｽﾞ                     */
#define    FRMMAX     260               /* LAPD最大Iﾌﾚｰﾑ長(情報ﾌｨｰﾙﾄﾞ)      */

#define    IBCID      0x04              /* 伝達能力                         */
#define    ICIID      0x18              /* ﾁｬﾈﾙ識別子                       */
#define    IFAID      0x1C              /* ﾌｧｼﾘﾃｨ                           */
#define    ICDID      0x6C              /* 発番号                           */
#define    ICHID      0x6D              /* 発ｻﾌﾞｱﾄﾞﾚｽ                       */
#define    ICGID      0x70              /* 着番号                           */
#define    ICSID      0x71              /* 着ｻﾌﾞｱﾄﾞﾚｽ                       */
#define    ILLID      0x7C              /* 低位ﾚｲﾔ整合性                    */
#define    IHLID      0x7D              /* 高位ﾚｲﾔ整合性                    */
#define    IUUID      0x7E              /* ﾕｰｻﾞ･ﾕｰｻﾞ                  edPD0A*/

#define    ON         0x01              /* ﾌﾗｸﾞｵﾝ                       PD0C*/
#define    OFF        0x00              /* ﾌﾗｸﾞｵﾌ                       PD0C*/

/**************************************/
/* 回線種別                           */
/**************************************/
#define LINECHK      0x60               /* 回線種別ﾁｪｯｸ用                   */
#define LINE_4W      0x40               /* 4W                               */
#define LINE_LOOP    0x00               /* HDLCﾙｰﾌﾟ                         */

/**************************************/
/* 遷移状態定義                       */
/**************************************/
#define DEV_INS      0                  /* 閉塞解除                         */
#define DEV_OUS      1                  /* 閉塞                             */

/**************************************/
/* 排他区間要求変更対象定義           */
/**************************************/
#define CHG_LL       0x01               /* 物理回線                   stPD0C*/
#define CHG_PL       0x02               /* 論理回線                         */
#define CHG_PP       0x03               /* 論理パス                   edPD0C*/

/**************************************/
/* 排他区間要求処理種別定義           */
/**************************************/
#define SY_DEL     0x01                 /* 撤去                       stPD0C*/
#define SY_INS     0x02                 /* 増設                             */
#define SY_CHG     0x03                 /* 属性変更                   edPD0C*/

/**************************************/
/* IRBﾀｲﾌﾟ定義                        */
/**************************************/
#define TYPEN        0x00               /* ﾀｲﾌﾟN                            */

/**************************************/
/* ﾊﾞｯﾌｧ種別定義 　                   */
/**************************************/
#define CMBFPL       0L                 /* CMﾊﾞｯﾌｧﾌﾟｰﾙ                      */

/**************************************/
/* 切替先情報                         */
/**************************************/
#define KO_00        0x00               /* 電話番号１設定               PD0A*/
#define KO_01        0x01               /* 電話番号２設定               PD0A*/
#define KO_SV        0x02               /* 要求時指定番号設定           PD0A*/

/**************************************/
/* ＩＲコード定義                     */
/**************************************/
#define IR_TIMUP   MCSTIME              /* タイマ完了イベント               */
#define IR_TERMP   MCSTERM              /* 強制閉塞                         */

/**************************************/
/* モジュールＩＤ（ＭＩＤ）定義       */
/**************************************/
#define ML_TERMP   0x02                 /* プロセス終了処理                 */
#define ML_4W      0x10                 /* 端末I/Oﾁｬﾈﾙ制御(4W)              */
#define ML_HDLC    0x20                 /* 端末I/Oﾁｬﾈﾙ制御(HDLCﾙｰﾌﾟ)        */
#define ML_TEL     0x30                 /* 端末I/Oﾁｬﾈﾙ制御(TEL)             */
#define ML_BACKUP  0x40                 /* ﾊﾞｯｸｱｯﾌﾟﾁｬﾈﾙ制御                 */
#define ML_LAN     0x50                 /* LANﾁｬﾈﾙ制御                      */
#define ML_BAT     0x60                 /* 一括処理制御                     */
#define ML_X25T    0x70                 /* 端末I/Oﾁｬﾈﾙ制御(X.25)        PD0A*/
#define ML_X25H    0x80                 /* ﾎｽﾄI/Oﾁｬﾈﾙ制御(X.25)         PD0A*/
#define ML_TELH    0x90                 /* ﾎｽﾄI/Oﾁｬﾈﾙ制御(TEL)          PD0A*/
#define ML_HAIT    0xa0                 /* 排他区間制御                 PD0C*/
#define ML_LANT    0xb0                 /* 端末I/Oﾁｬﾈﾙ制御(LAN)         PD0O*/
#define ML_SYNC    0xb1                 /* ISDN非同期通知制御           PD0Y*/

/**************************************/
/* ＩＲコード定義                     */
/**************************************/
#define IR_PROCE   0x10                 /* プロセスイベント                 */
#define IR_LOPEN   0x20                 /* チャネルオープン完了             */
#define IR_LCLOS   0x30                 /* チャネルクローズ完了             */
#define IR_LASYC   0x40                 /* 非同期通知応答                   */
#define IR_ORIST   0x50                 /* 折返試験設定完了                 */
#define IR_ORIDT   0x60                 /* 折返しﾃﾞｰﾀ送信完了               */
#define IR_CEND    0x70                 /* 着呼完了                         */
#define IR_HEND    0x80                 /* 発呼完了   　　                  */
#define IR_LDCON   0x90                 /* 切断完了                     PD0A*/
#define IR_INSID   0xa0                 /* 内部イベント                     */
#define IR_LICP    0xb0                 /* 子ﾌﾟﾛｾｽ終了通知              PD0O*/
#define IR_DLRSET  0xc0                 /* ﾃﾞｰﾀﾘﾝｸ再設定完了            PD0R*/

/**************************************/
/* サブＩＲコード定義                 */
/**************************************/
#define SIR_ORIKA  0x01                 /* 折返試験要求                     */
#define SIR_KIRIK  0x02                 /* 着呼切替要求                     */
#define SIR_HHAKK  0x03                 /* 発呼切替要求                     */
#define SIR_NHAKK  0x04                 /* 発呼切替（許可無）要求           */
#define SIR_HKKRI  0x05                 /* 発呼強制切替要求　　　　　　     */
#define SIR_KKYOK  0x06                 /* 切替許可要求　　　　　　　       */
#define SIR_CANCE  0x07                 /* 切替中止要求　　　               */
#define SIR_MODOS  0x08                 /* 切戻要求     　　                */
#define SIR_KNORM  0x09                 /* 強制閉塞応答（正常）             */
#define SIR_KBUSY  0x0a                 /* 強制閉塞応答（ビジー）           */
#define SIR_IKHKR  0x0b                 /* 発呼一括切替要求                 */
#define SIR_IKAMO  0x0c                 /* 一括切戻要求    　　　　　　     */
#define SIR_HEKAI  0x0d                 /* 閉塞解除要求          　　　     */
#define SIR_IHRTN  0x0e                 /* 発呼一括切替応答（内部通知）     */
#define SIR_IMRTN  0x0f                 /* 一括切戻応答（内部通知）　       */
#define SIR_NSTOK  0x10                 /* 通信停止応答（正常）         PD0A*/
#define SIR_NSTNG  0x11                 /* 通信停止応答（異常）         PD0A*/
#define SIR_RINJI  0x12                 /* 臨時接続要求                 PD0A*/
#define SIR_RINDA  0x13                 /* 臨時切断要求                 PD0A*/
#define SIR_HAISY  0x14                 /* 排他区間設定要求             PD0C*/
#define SIR_HAIKY  0x15                 /* 排他区間解除要求             PD0C*/
#define SIR_HAISR  0x16                 /* 排他区間設定応答（内部通知） PD0C*/
#define SIR_HAIKR  0x17                 /* 排他区間解除応答（内部通知） PD0C*/
#define SIR_SBUSY  0x18                 /* ｾﾝｽ&ｸﾛｰｽﾞ応答（ビジー）      PD0J*/
#define SIR_LICPE  0x19                 /* LICP終了通知                 PD0Z*/
#define SIR_NULL   0x00                 /* ＮＵＬＬ              　　　     */

/**************************************/
/* ＭＫコード                         */
/**************************************/
#define MKMOTI      0x03070100          /* 持ち回り                         */
#define MKCOMD      0x03060000          /* コマンド                         */
#define MKLAN       0x03070200          /* ＬＡＮ                           */
#define MKHOST      0x03070300          /* ホスト                       PD0A*/
#define MKHAIT      0x030e0000          /* 排他区間                     PD0C*/
#define MKLICPEND   0x030c0000          /* LICP終了通知                 PD0Z*/

/**************************************/
/* インターフェースコード             */
/**************************************/
#define IFCOMD      0x58001000          /* ｺﾏﾝﾄﾞ                            */
#define IFORIKAE    0x60000000          /* 折返試験要求                     */
#define IFHESOKU    0x60000001          /* 強制閉塞応答                     */
#define IFOPEN      0x60000002          /* ｵｰﾌﾟﾝ通知                        */
#define IFSC        0x60000003          /* ｾﾝｽ&ｸﾛｰｽﾞ要求/応答           PD0J*/
#define IFIKAMOD    0x60000004          /* 一括切戻し要求                   */
#define IFKIRIKA    0x60000005          /* 着呼切替要求　　                 */
#define IFKKYOKA    0x60000006          /* 切替許可要求　　　               */
#define IFCANCEL    0x60000007          /* 切替中止要求　　　　　　         */
#define IFMODOSI    0x60000008          /* 切戻し要求                       */
#define IFHHAKKI    0x60000009          /* 発呼切替要求                     */
#define IFNHAKKO    0x6000000a          /* 発呼切替（許可無）要求           */
#define IFHKKRIK    0x6000000c          /* 発呼強制切替要求                 */
#define IFIKHKRI    0x6000000d          /* 一括発呼切替要求             PD0R*/
#define IFERR       0x6000000f          /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞ不良通知             */
#define IFLANNG     0x60000010          /* ＬＡＮ回線障害通知               */
#define IFLANOK     0x60000011          /* ＬＡＮ回線障害回復通知           */
#define IFHKIRI     0x60000012          /* 通信停止要求［切替］         PD0A*/
#define IFHKYO      0x60000013          /* 通信停止要求［強制切替］     PD0A*/
#define IFHMODO     0x60000014          /* 通信停止要求［切戻し］       PD0A*/
#define IFHREST     0x60000015          /* 通信再開可能通知             PD0A*/
#define IFRINJI     0x60000016          /* 臨時接続要求                 PD0A*/
#define IFRINDA     0x60000017          /* 臨時切断要求                 PD0A*/
#define IFHAISY     0x79a00041          /* 排他区間設定要求             PD0C*/
#define IFHAIKY     0x79a00042          /* 排他区間解除要求             PD0C*/
#define IFHAISO     0x60002000          /* 排他区間設定応答             PD0C*/
#define IFHAIKO     0x60002001          /* 排他区間解除応答             PD0C*/
#define IFLICPEND   0x10290001          /* LICP終了通知                 PD0Z*/

/**************************************/
/* 通知種別数定義                     */
/**************************************/
#define COMDCNT      12                 /* 通知種別数                       */

/**************************************/
/* 通知種別定義                       */
/**************************************/
#define TU_ORIKA  "-miorikae"           /* 折返試験要求                     */
#define TU_KIRIK  "-mikirika"           /* 着呼切替要求                     */
#define TU_HHAKK  "-mihhakko"           /* 発呼切替要求                     */
#define TU_NHAKK  "-minhakko"           /* 発呼切替（許可無）要求           */
#define TU_HKKRI  "-mihkkrik"           /* 発呼強制切替要求　　　　　　     */
#define TU_KKYOK  "-mikkyoka"           /* 切替許可要求　　　　　　　       */
#define TU_CANCE  "-micancel"           /* 切替中止要求　　　               */
#define TU_MODOS  "-mimodosi"           /* 切戻要求     　　                */
#define TU_IKHKR  "-miikhkri"           /* 発呼一括切替要求                 */
#define TU_IKAMO  "-miikamod"           /* 一括切戻要求    　　　　　　     */
#define TU_LANOR  "-milanori"           /* LAN折り返し試験要求 　  　　     */
#define TU_LANHE  "-milanins"           /* LAN閉塞解除要求                  */

/**************************************/
/* ｺﾏﾝﾄﾞｲﾝﾀｰﾌｪｰｽ電文ﾃﾞｰﾀ域ｻｲｽﾞ定義    */
/**************************************/
#define ORI_D_SZ     15                 /* 折返試験要求                     */
#define CYA_D_SZ     13                 /* 着呼切替要求                     */
#define HAK_D_SZ     15                 /* 発呼切替要求                     */
#define NHAK_D_SZ    15                 /* 発呼切替（許可無）要求           */
#define HAKK_D_SZ    29                 /* 発呼強制切替要求　　　　　　     */
#define KYOKA_D_SZ   13                 /* 切替許可要求　　　　　　　       */
#define CAN_D_SZ     13                 /* 切替中止要求　　　               */
#define MODO_D_SZ    13                 /* 切戻要求     　　                */
#define IHAK_D_SZ    14                 /* 発呼一括切替要求                 */
#define IMODO_D_SZ    9                 /* 一括切戻要求    　　　　　　     */
#define KAIJYO_D_SZ  13                 /* 閉塞解除要求    　　　　　　     */
#define LICPEND_D_SZ 20                 /* LICP終了通知    　　　　　 　PD0Z*/

/**************************************/
/* 持回り電文個別域ｻｲｽﾞ定義           */
/**************************************/
#define ORI_SZ       12                 /* 折返試験要求                     */
#define CYA_SZ       24                 /* 着呼切替要求                     */
#define HAK_SZ       24                 /* 発呼切替要求                     */
#define NHAK_SZ      52                 /* 発呼切替（許可無）要求       PD0A*/
#define HAKK_SZ      52                 /* 発呼強制切替要求　　　　　　 PD0A*/
#define KYOKA_SZ     12                 /* 切替許可要求　　　　　　　       */
#define CAN_SZ       12                 /* 切替中止要求　　　               */
#define MODO_SZ      12                 /* 切戻要求     　　                */
#define IHAK_SZ      12                 /* 発呼一括切替要求                 */
#define IMODO_SZ     12                 /* 一括切戻要求    　　　　　　     */
#define RINJI_SZ     52                 /* 臨時接続要求    　　　　　　 PD0A*/
#define RINDA_SZ     24                 /* 臨時切断要求    　　　　　　 PD0A*/

/**************************************/
/* ﾒｯｾｰｼﾞID                           */
/**************************************/
#define MSG_00      "SI00"              /* 切替開始                         */
#define MSG_01      "SI01"              /* 切替終了                         */
#define MSG_02      "SI02"              /* 切戻し開始                       */
#define MSG_03      "SI03"              /* 切戻し終了                       */
#define MSG_04      "SI04"              /* 該当回線無し                     */
#define MSG_05      "SI05"              /*                                  */
#define MSG_06      "SI06"              /* 空き回線無し                     */
#define MSG_07      "SI07"              /* チャネル故障                     */
#define MSG_08      "SI08"              /*                                  */
#define MSG_09      "SI09"              /* モデム故障                       */
#define MSG_10      "SI10"              /* 回線正常                         */
#define MSG_11      "SI11"              /*                                  */
#define MSG_12      "SI12"              /* キャンセル開始                   */
#define MSG_13      "SI13"              /* 折返開始                         */
#define MSG_14      "SI14"              /* 折返終了                         */
#define MSG_15      "SI15"              /* キャンセル終了                   */
#define MSG_16      "SI16"              /* 故障回復                         */
#define MSG_17      "SI17"              /* 回線故障                         */
#define MSG_18      "SI18"              /* パス刈取失敗                     */
#define MSG_19      "SI19"              /* 回線接続失敗                     */
#define MSG_20      "SI20"              /* パラメーターエラー               */
#define MSG_21      "SI21"              /* パス刈取中                       */
#define MSG_22      "SI22"              /* 発呼要求中                       */
#define MSG_23      "SI23"              /* 切替未処理                       */
#define MSG_24      "SI24"              /* 依頼元相違                       */
#define MSG_25      "SI25"              /* 着呼待                           */
#define MSG_26      "SI26"              /* 対象外回線                       */
#define MSG_27      "SI27"              /* 切替え中                         */
#define MSG_28      "SI28"              /* 切戻し中                         */
#define MSG_29      "SI29"              /* 折返し試験中                     */
#define MSG_30      "SI30"              /* 発呼異常                         */
#define MSG_31      "SI31"              /* 着呼異常                         */
#define MSG_32      "SI32"              /* 折返し異常                       */
#define MSG_33      "SI33"              /* BU回線障害                       */
#define MSG_34      "SI34"              /* パスワードエラー                 */
#define MSG_35      "SI35"              /* 回線組込中                       */
#define MSG_36      "SI36"              /* 組込開始                         */
#define MSG_37      "SI37"              /* 組込終了                         */
#define MSG_38      "SI38"              /* ハード障害                       */
#define MSG_39      "SI39"              /* 回線閉塞                         */
#define MSG_40      "SI40"              /* 回線組込                         */
#define MSG_41      "SI41"              /* 回線非閉塞                       */
#define MSG_42      "SI42"              /* 再起動中                         */
#define MSG_43      "SI43"              /* 実装クラス不正                   */
#define MSG_44      "SI44"              /* PU,CH不正                        */
#define MSG_45      "SI45"              /* チャネル未実装                   */
#define MSG_46      "SI46"              /* 回線閉塞中                       */
#define MSG_47      "SI47"              /* 一括切替開始                     */
#define MSG_48      "SI48"              /* 一括切替終了                     */
#define MSG_49      "SI49"              /* 切替え中                         */
#define MSG_50      "SI50"              /* 切戻し中                         */
#define MSG_51      "SI51"              /* 折返し試験中                     */
#define MSG_52      "SI52"              /* 回線障害                         */
#define MSG_53      "SI53"              /* バッファ障害                     */
#define MSG_54      "SI54"              /* プロトコル障害                   */
#define MSG_55      "SI55"              /* 臨時回線障害               stPD0A*/
#define MSG_56      "SI56"              /* 呼解放通知                       */
#define MSG_57      "SI57"              /* リセット通知                     */
#define MSG_58      "SI58"              /* リスタート通知                   */
#define MSG_59      "SI59"              /* 割込み通知                       */
#define MSG_60      "SI60"              /* 相手ﾋﾞｼﾞｰ通知                    */
#define MSG_61      "SI61"              /* 相手ﾋﾞｼﾞｰ解除                    */
#define MSG_62      "SI62"              /* リセット不完了                   */
#define MSG_63      "SI63"              /* データリンク異常                 */
#define MSG_64      "SI64"              /* モード切断通知                   */
#define MSG_65      "SI65"              /* モード設定通知                   */
#define MSG_66      "SI66"              /* ＦＲＭＲ送信通知                 */
#define MSG_67      "SI67"              /* ＦＲＭＲ受信通知                 */
#define MSG_68      "SI68"              /* 接続通知                         */
#define MSG_69      "SI69"              /* 切断通知                         */
#define MSG_70      "SI70"              /* 初期設定                         */
#define MSG_71      "SI71"              /* ﾘﾝｸ障害１                        */
#define MSG_72      "SI72"              /* ﾘﾝｸ障害２                        */
#define MSG_73      "SI73"              /* BU回線通知                 edPD0A*/
#define MSG_74      "SI74"              /* 排他区間中                   PD0C*/
#define MSG_75      "SI75"              /* 排他区間中                   PD0C*/
#define MSG_76      "SI76"              /* LICP起動失敗                 PD0O*/
#define MSG_77      "SI77"              /* 接続失敗                     PD0X*/
/**************************************/
/* ﾎﾟｽﾄｺｰﾄﾞ                           */
/**************************************/
#define PST_000     0x0000              /* 正常終了                         */
#define PST_010     0x0010              /* 回線状態正常                     */
#define PST_100     0x0100              /* 伝送エラー                       */
#define PST_110     0x0110              /* ＩＣＰ処理中                     */
#define PST_120     0x0120              /* 回線番号不正                     */
#define PST_130     0x0130              /* タイムアウト                     */
#define PST_140     0x0140              /* モデムエラー                     */
#define PST_144     0x0144              /* 回線障害                         */
#define PST_145     0x0145              /* ハード障害                       */
#define PST_146     0x0146              /* ＤＭＡ閉塞                       */
#define PST_147     0x0147              /* ＩＯＣ閉塞                       */
#define PST_148     0x0148              /* Ｐｕ障害                         */
#define PST_149     0x0149              /* コントロール部閉塞移行中         */
#define PST_200     0x0200              /* インターフェースエラー           */
#define PST_300     0x0300              /* 未着呼状態                       */
#define PST_400     0x0400              /* 電話網異常                       */
#define PST_500     0x0500              /* ＩＣＰ処理中                     */
#define PST_600     0x0600              /* 依頼元相違                       */
#define PST_700     0x0700              /* 処理不可能                       */
#define PST_800     0x0800              /* パスワードエラー                 */
/**************************************/
/* ＩＲＢテンプレート                 */
/**************************************/
typedef struct {
    unsigned long       qlink[2];       /* キューリンク                     */
    unsigned char       btyp;           /* ＢＴＹＰ                         */
    unsigned char       gmid;           /* ＧＭＩＤ                         */
    unsigned char       dmid;           /* ＤＭＩＤ                         */
    unsigned char       omid;           /* ＯＭＩＤ                         */
    unsigned char       ir_cd;          /* ＩＲコード                       */
    unsigned char       sir_cd;         /* サブＩＲコード                   */
    short               endcd;          /* 完了コード                       */
    long                ctxtp;          /* コンテキストアドレス   　        */
    long                msglen;         /* 受信電文長／リザルト値           */
    long                msgp;           /* 受信メッセージポインタ           */
    long                rd;             /* ｒｄ値                           */
    long                faceno;         /* TFACｴﾝﾄﾘNO                       */
    long                eventno;        /* ｲﾍﾞﾝﾄ番号　                      */
    long                argarea[5];     /* システムコールアーギュメント域   */
}   MIIRB;
/**************************************/
/* 回線制御コンテキストテンプレート   */
/**************************************/
typedef struct {
    long            chead[3];           /* コンテキストヘッダー             */
    short           lineno;             /* 回線番号                         */
    short           sysrtcnt;           /* ｼｽﾃﾑｺｰﾙﾘﾄﾗｲｶｳﾝﾀ                  */
    long            devid;              /* 装置ID                           */
    long            timerid;            /* ﾀｲﾏID                            */
    long            openirba;           /* ｵｰﾌﾟﾝ要求IRBｱﾄﾞﾚｽ                */
    long            ctrolirba;          /* 非同期要求IRBｱﾄﾞﾚｽ               */
    long            faceno;             /* TFACｴﾝﾄﾘNO                       */
    long            fackop;             /* TFAC個別部ﾎﾟｲﾝﾀ                  */
    long            faheno;             /* TFAHｴﾝﾄﾘNO                       */
    char           *fahkop;             /* TFAH個別部ﾎﾟｲﾝﾀ                  */
    long            sakieno;            /* 切替先TFACｴﾝﾄﾘNO                 */
    long            sakikop;            /* 切替先TFAC個別部ﾎﾟｲﾝﾀ            */
    long            m_id;               /* 対象ﾁｬﾈﾙ制御ﾓｼﾞｭｰﾙID             */
    long            ukeno;              /* 受付番号                         */
    short           postcd;             /* ﾎﾟｽﾄｺｰﾄﾞ                         */
    char            rockf;              /* ｺﾝﾃｷｽﾄﾛｯｸﾌﾗｸﾞ                PD0C*/
    char            ikfg;               /* 一括処理フラグ                   */
    char            telno[22];          /* 切替先電話番号               PD0A*/
    char            isdncno;            /* 呼番号                       PD0A*/
    char            dkei;               /* 切断通知通知先ﾌﾟﾛｾｽ系区分    PD0A*/
    long            telketa;            /* 切替先電話番号桁数               */
    short           wsno;               /* ｗｓ番号                         */
    char            koflg;              /* 発呼先ﾌﾗｸﾞ                   PD0A*/
    char            stopf;              /* 通信停止状態ﾌﾗｸﾞ             PD0A*/
    long            isdnfd;             /* ISDNファイルディスクリプタ   PD0A*/
    char            dprocnm[8];         /* 切断通知通知先ﾌﾟﾛｾｽ名        PD0A*/
    long            r_faceno;           /* TFACｴﾝﾄﾘNO退避域                 */
    long            r_fackop;           /* TFAC個別部ﾎﾟｲﾝﾀ退避域            */
    long            r_m_id;             /* 対象ﾁｬﾈﾙ制御ﾓｼﾞｭｰﾙID退避域       */
    long            r_ukeno;            /* 受付番号退避域                   */
    long            r_miaa;             /* MIA ADDR 退避域                  */
    char            cttno[16];          /* 接続電話番号                 PD0A*/
    long            cttsz;              /* 接続電話番号ｻｲｽﾞ             PD0A*/
    char            chgcd;              /* 変更区分                     PD0C*/
    char            syoricd;            /* 処理種別                     PD0C*/
    char            passc;              /* ﾊﾟｽｸﾛｰｽﾞ状態                 PD0J*/
    char            callcnt;            /* 呼接続ﾘﾄﾗｲｶｳﾝﾀ　             PD0N*/
    long            chldirba;           /* ﾌﾟﾛｾｽ終了通知IRBｱﾄﾞﾚｽ        PD0O*/
    long            dlreirba;           /* ﾃﾞｰﾀﾘﾝｸ再設定IRBｱﾄﾞﾚｽ        PD0R*/
}  MILCTX;
/**************************************/
/* 論理ﾊﾟｽｵｰﾌﾟﾝ/ｸﾛｰｽﾞ処理ﾊﾟﾗﾒｰﾀ       */
/**************************************/
typedef struct {
    unsigned long       qlink[2];       /* キューリンク                     */
    unsigned char       btyp;           /* ＢＴＹＰ                         */
    unsigned char       gmid;           /* ＧＭＩＤ                         */
    unsigned char       dmid;           /* ＤＭＩＤ                         */
    unsigned char       omid;           /* ＯＭＩＤ                         */
    unsigned char       ir_cd;          /* ＩＲコード                       */
    unsigned char       sir_cd;         /* サブＩＲコード                   */
    short               endcd;          /* 完了コード                       */
    long                ctxtp;          /* コンテキストアドレス   　        */
    short    wsno;                      /* ＷＳ番号                         */
    char     timerf;                    /* ﾀｲﾏ発行ﾌﾗｸﾞ                      */
    char     yob1;                      /* 予備                             */
    long     irbp;                      /* IRBﾎﾟｲﾝﾀ                         */
    long     ifcd;                      /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞ                     */
    long     yob3[7];                   /* 予備                             */
} IOPRM;
/**************************************/
/* 非同期通知（４Ｗ）                 */
/**************************************/
typedef struct {
    long     func;                      /* ｆｕｎｃ                         */
    long     errcd;                     /* ｴﾗｰｺｰﾄﾞ                          */
} SYGI4W;
/**************************************/
/* 非同期通知（ＨＤＬＣ）             */
/**************************************/
typedef struct {
    long     func;                      /* ｆｕｎｃ                         */
    long     errcd;                     /* ｴﾗｰｺｰﾄﾞ                          */
} SYGIHDLC;
/**************************************/
/* 非同期通知（電話網）               */
/**************************************/
typedef struct {
    long     func;                      /* ｆｕｎｃ                         */
    long     errcd;                     /* ｴﾗｰｺｰﾄﾞ                          */
} SYGITEL;
/**************************************/
/* 非同期通知（X.25）                 */
/**************************************/
typedef struct {
    long     func;                      /* ｆｕｎｃ                     PD0A*/
    long     errcd;                     /* ｴﾗｰｺｰﾄﾞ                      PD0A*/
} SYGIX25;
/**************************************/
/* ﾃﾞﾊﾞｲｽ制御・監視                   */
/**************************************/
typedef struct {
    long     iprmsz;                    /* 入力ﾊﾟﾗﾒｰﾀ長                 PD0A*/
    long     oprmsz;                    /* 出力ﾊﾟﾗﾒｰﾀ長                 PD0A*/
    long     msgcnt;                    /* ﾒｯｾｰｼﾞ数                     PD0A*/
    char     protid;                    /* ﾌﾟﾛﾄｺﾙ識別子                 PD0A*/
    char     callno[2];                 /* 呼番号                       PD0A*/
    char     msgt;                      /* ﾒｯｾｰｼﾞ種別                   PD0A*/
} ISDNMCOM;
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  COMADDR													*/
/*																			*/
/* ＜機能概要＞  ﾃｰﾌﾞﾙの共通部ｱﾄﾞﾚｽの取得を行う                     		*/
/*																			*/
/* ＜仮引数＞																*/
/*	   TBLNO     対象ﾃｰﾌﾞﾙ番号   											*/
/*	   RTN	     対象共通部ｱﾄﾞﾚｽ     										*/
/****************************************************************************/
#define COMADDR(TBLNO, RTN)                                                   \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT個別部ﾎﾟｲﾝﾀ                   */\
    TCOMPAT  **sgtp;                    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀ             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT個別部ﾎﾟｲﾝﾀを求める           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀを求める     */\
    RTN = (void *)sgtp[TBLNO];          /* 共通部ｱﾄﾞﾚｽを求める              */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  SUBADDR													*/
/*																			*/
/* ＜機能概要＞  ﾃｰﾌﾞﾙのｻﾌﾞ共通部ｱﾄﾞﾚｽの取得を行う                     		*/
/*																			*/
/* ＜仮引数＞																*/
/*	   TBLNO     対象ﾃｰﾌﾞﾙ番号   											*/
/*	   RTN	     対象ｻﾌﾞ共通部ｱﾄﾞﾚｽ   										*/
/****************************************************************************/
#define SUBADDR(TBLNO, RTN)                                                   \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT個別部ﾎﾟｲﾝﾀ                   */\
    TCOMPAT  **sgtp;                    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀ             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT個別部ﾎﾟｲﾝﾀを求める           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀを求める     */\
    RTN = (void *)(sgtp[TBLNO] + 1);    /* ｻﾌﾞ共通部ｱﾄﾞﾚｽを求める           */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  KOADDR		    											*/
/*																			*/
/* ＜機能概要＞  ﾃｰﾌﾞﾙの個別部ｴﾝﾄﾘ番号より個別部ｴﾝﾄﾘｱﾄﾞﾚｽの取得を行う		*/
/*																			*/
/* ＜仮引数＞																*/
/*	   TBLNO     対象ﾃｰﾌﾞﾙ番号   											*/
/*	   ENO       個別部ｴﾝﾄﾘ番号   											*/
/*	   RTN	     個別部ｴﾝﾄﾘｱﾄﾞﾚｽ      										*/
/****************************************************************************/
#define KOADDR(TBLNO, ENO, RTN)                                               \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT個別部ﾎﾟｲﾝﾀ                   */\
    TCOMPAT  **sgtp;                    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀ             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT個別部ﾎﾟｲﾝﾀを求める           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀを求める     */\
    RTN = (void *)((long)(sgtp[TBLNO] + 1) + sgtp[TBLNO]->tcomsbps +          \
                   sgtp[TBLNO]->tcomprsl * (ENO - 1));                        \
                                        /* 個別部ｴﾝﾄﾘｱﾄﾞﾚｽを求める          */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  KOENTNO        											*/
/*																			*/
/* ＜機能概要＞  ﾃｰﾌﾞﾙの個別部ｴﾝﾄﾘｱﾄﾞﾚｽより個別部ｴﾝﾄﾘ番号の取得を行う		*/
/*																			*/
/* ＜仮引数＞																*/
/*	   TBLNO     対象ﾃｰﾌﾞﾙ番号   											*/
/*	   ADDR      個別部ｴﾝﾄﾘｱﾄﾞﾚｽ   											*/
/*	   RTN	     個別部ｴﾝﾄﾘ番号      										*/
/****************************************************************************/
#define KOENTNO(TBLNO, ADDR, RTN)                                             \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT個別部ﾎﾟｲﾝﾀ                   */\
    TCOMPAT  **sgtp;                    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀ             */\
    long     work;                      /* ﾜｰｸｴﾘｱ                           */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT個別部ﾎﾟｲﾝﾀを求める           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SGﾃｰﾌﾞﾙｱﾄﾞﾚｽﾘｽﾄﾎﾟｲﾝﾀを求める     */\
    RTN = (((long)(ADDR) - (long)sgtp[TBLNO]                                  \
		- (long)(sizeof(TCOMPAT)) - (long)sgtp[TBLNO]->tcomsbps)              \
		/ (long)sgtp[TBLNO]->tcomprsl) + 1;                                   \
										/* 個別部ｴﾝﾄﾘNOを求める             */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_IENT        											*/
/*																			*/
/* ＜機能概要＞  (ｻｰﾋﾞｽｺｰﾙ)ICPｺﾏﾝﾄﾞ開始を発行する	                     	*/
/*																			*/
/* ＜仮引数＞																*/
/*	   UKENO     受付番号   	     										*/
/*	   MSGP      電文格納域ｱﾄﾞﾚｽ   											*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_IENT(UKENO, MSGP, M_ID)                                           \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = ms_ient((long)UKENO, (long *)MSGP);                                 \
                                        /* ICPｺﾏﾝﾄﾞ開始                     */\
    if( ret != MINORMAL )               /* 返却値異常時                     */\
    {                                                                         \
        MIAPABT(ABTOIENT, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_IRES        											*/
/*																			*/
/* ＜機能概要＞  (ｻｰﾋﾞｽｺｰﾙ)ICPｺﾏﾝﾄﾞ受付を発行する	                     	*/
/*																			*/
/* ＜仮引数＞																*/
/*	   UKENO     受付番号   	     										*/
/*	   RTN       返却値         											*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_IRES(UKENO, RTN, M_ID)                                            \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = ms_ires((long)UKENO, (long)RTN);                                    \
                                        /* ICPｺﾏﾝﾄﾞ受付通知                 */\
    if( ret != MINORMAL )               /* 返却値異常時                     */\
    {                                                                         \
        MIAPABT(ABTOIRES, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_IEND        											*/
/*																			*/
/* ＜機能概要＞  (ｻｰﾋﾞｽｺｰﾙ)ICPｺﾏﾝﾄﾞ終了を発行する	                     	*/
/*																			*/
/* ＜仮引数＞																*/
/*	   UKENO     受付番号   	     										*/
/*	   RTN       返却値         										PD01*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_IEND(UKENO, RTN, M_ID)                                            \
{                                       /*                              PD01*/\
    long    ret;                        /* 返却値                           */\
    ret = ms_iend((long)UKENO, (long)RTN);                                    \
										/* ICPｺﾏﾝﾄﾞ終了通知             PD01*/\
    if( ret != MINORMAL )               /* 返却値異常時                     */\
    {                                                                         \
        MIAPABT(ABTOIEND, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  TELNO4          											*/
/*																			*/
/* ＜機能概要＞  電話番号の下４桁を取得する                              	*/
/*																			*/
/* ＜仮引数＞																*/
/*	   CTXTP     ｺﾝﾃｷｽﾄﾎﾟｲﾝﾀ        										*/
/*	   RTN       電話番号下４桁   											*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define TELNO4(CTXTP, RTN, M_ID)                                              \
{                                                                             \
    char  *area;                        /* 待避ｴﾘｱ                          */\
    area = (char *)(((MILCTX *)CTXTP)->telno +                                \
                    (long)(((MILCTX *)CTXTP)->telketa - 4));                  \
                                        /* 電話番号下４桁取り出す           */\
    MIA_CBCN(area, &RTN, 4, M_ID);      /* ｷｬﾗｸﾀ/ﾊﾞｲﾅﾘ変換                  */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_FRBF													*/
/*																			*/
/* ＜機能概要＞  プールバッファの解放を行う 								*/
/* ＜仮引数＞																*/
/*	   MSGP		 プールバッファポインタ 									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_FRBF(MSGP, M_ID)                                                  \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mo_frbf((char *)MSGP);        /* ﾊﾞｯﾌｧ解放                        */\
    if( ret != MINORMAL )               /* 返却値異常時                     */\
    {                                                                         \
        /* MIAPABT(ABTOFRBF, ABT_NULL, M_ID, ret); */                         \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                ST4868 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_MBID													*/
/*																			*/
/* ＜機能概要＞  ﾒｰﾙﾎﾞｯｸｽIDの取得を行う      								*/
/* ＜仮引数＞																*/
/*	   SNPN		 ﾌﾟﾛｾｽID                									*/
/*	   MBID	     ﾒｲﾙﾎﾞｯｸｽID                   								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_MBID(SNPN, MBID, M_ID)                                            \
{                                                                             \
    MBID = mi_mbid(SNPN);               /* ﾒｲﾙﾎﾞｯｸｽid取得                   */\
    if( MBID < MINOSING )               /* ﾒﾙﾎﾞｯｸｽID取得ができなかったとき  */\
    {                                                                         \
        MIAPABT(ABTOMBID, ABT_NULL, M_ID, MBID);                              \
                                        /* プロセスアボート                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_COPY													*/
/*																			*/
/* ＜機能概要＞  領域の複写を行う            								*/
/* ＜仮引数＞																*/
/*	   MOTO		 複写元                  									*/
/*	   SAKI	     複写先                      								*/
/*	   LEN	     領域の大きさ        										*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_COPY(MOTO, SAKI, LEN, M_ID)                                       \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mc_copy((char *)MOTO, (char*)SAKI, (long)LEN);                      \
										/* 領域ｺﾋﾟｰ                         */\
    if( ret != MINORMAL )               /* ﾒﾙﾎﾞｯｸｽID取得ができなかったとき  */\
    {                                                                         \
        MIAPABT(ABTOCOPY, ABT_NULL, M_ID, ret);                               \
                                        /* プロセスアボート                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_CCOM													*/
/*																			*/
/* ＜機能概要＞  領域の比較を行う            								*/
/* ＜仮引数＞																*/
/*	   P1		 領域１                  									*/
/*	   P2	     領域２                      								*/
/*	   LEN	     領域の大きさ        										*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_CCOM(P1, P2, LEN, RTN)                                            \
{                                                                             \
    RTN = mc_ccom((char *)P1, (char *)P2, (long)LEN);                         \
                                        /* 領域比較                         */\
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_RENQ													*/
/*																			*/
/* ＜機能概要＞  資源の占有を行う            								*/
/* ＜仮引数＞																*/
/*	   P1		 資源番号                  									*/
/*	   P2	                                								*/
/*	   P3	                        										*/
/*	   P4	             	             									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_RENQ(P1, P2, P3, P4, M_ID)                                        \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mf_renq((long *)P1, (char *)P2, (long)P3, (char)P4);                \
	                                    /* 資源の占有                       */\
    if( ret != MFNORMAL )               /* 正常に資源占有出来なかった時     */\
    {                                                                         \
        MIAPABT(ABTORENQ, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_RDEQ													*/
/*																			*/
/* ＜機能概要＞  資源の占有解除を行う         								*/
/* ＜仮引数＞																*/
/*	   P1		 資源番号                  									*/
/*	   P2	                                								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_RDEQ(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mf_rdeq((long *)P1, (long)P2);                                      \
										/* 資源の占有解除                   */\
    if( ret != MFNORMAL )               /* 正常に資源占有解除出来なかった時 */\
    {                                                                         \
        MIAPABT(ABTORDEQ, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_NCLR													*/
/*																			*/
/* ＜機能概要＞  領域のNULLｸﾘｱを行う         								*/
/* ＜仮引数＞																*/
/*	   P1		 領域ｱﾄﾞﾚｽ                									*/
/*	   P2	     領域ｻｲｽﾞ                     								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_NCLR(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mc_nclr((char *)P1, (long)P2);                                      \
										/* 領域ﾇﾙｸﾘｱ                        */\
    if( ret != MINORMAL )               /* 正常にｸﾘｱ出来なかった時          */\
    {                                                                         \
        MIAPABT(ABTONCLR, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_CBCN													*/
/*																			*/
/* ＜機能概要＞  ｷｬﾗｸﾀﾃﾞｰﾀをﾊﾞｲﾅﾘ変換する     								*/
/* ＜仮引数＞																*/
/*	   P1		 ｷｬﾗｸﾀﾃﾞｰﾀﾎﾟｲﾝﾀ           									*/
/*	   P2	     ﾊﾞｲﾅﾘﾃﾞｰﾀ返却ﾎﾟｲﾝﾀ         								*/
/*	   P3	     ｷｬﾗｸﾀｰﾃﾞｰﾀﾊﾞｲﾄ数            								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_CBCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mc_cbcn((char *)P1, (long *)P2, (long)P3);                          \
										/* ｷｬﾗｸﾀ/ﾊﾞｲﾅﾘ変換                  */\
    if( ret != MCNMAL )                 /* 正常に変換出来なかった時         */\
    {                                                                         \
        MIAPABT(ABTOCBCN, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_BCCN													*/
/*																			*/
/* ＜機能概要＞  ﾊﾞｲﾅﾘﾃﾞｰﾀをｷｬﾗｸﾀ変換する     								*/
/* ＜仮引数＞																*/
/*	   P1		 ﾊﾞｲﾅﾘﾃﾞｰﾀ                									*/
/*	   P2	     ｷｬﾗｸﾀﾃﾞｰﾀ返却ﾎﾟｲﾝﾀ         								*/
/*	   P3	     ｷｬﾗｸﾀｰﾃﾞｰﾀ返却ﾊﾞｲﾄ数         								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_BCCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    long    i;                          /* ｶｳﾝﾀ                       stPD02*/\
    ret = mc_bccn((long)(P1), (char *)(P2), (long)(P3));                      \
										/* ﾊﾞｲﾅﾘ/ｷｬﾗｸﾀ変換                  */\
    if( ret != MCNMAL )                 /* 正常に変換出来なかった時         */\
    {                                                                         \
        MIAPABT(ABTOBCCN, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
    for( i = 0; i < (long)(P3); i++ )   /* 変換バイト数分チェックする       */\
    {                                                                         \
        if( ((char *)(P2))[i] == ' ' )  /* ﾌﾞﾗﾝｸの場合                      */\
		{                                                                     \
			((char *)(P2))[i] = '0';    /* 文字の０を設定する         edPD02*/\
		}                                                                     \
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_HCCN													*/
/*																			*/
/* ＜機能概要＞  ﾍｷｻﾃﾞｰﾀをｷｬﾗｸﾀ変換する     								*/
/* ＜仮引数＞																*/
/*	   P1		 ﾍｷｻﾃﾞｰﾀﾎﾟｲﾝﾀ            									*/
/*	   P2	     ｷｬﾗｸﾀﾃﾞｰﾀ返却ﾎﾟｲﾝﾀ         								*/
/*	   P3	     ｷｬﾗｸﾀｰﾃﾞｰﾀ返却ﾊﾞｲﾄ数         								*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_HCCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    ret = mc_hccn((char *)P1, (char *)P2, (long)P3);                          \
	                                    /* ﾍｷｻ/ｷｬﾗｸﾀ変換                    */\
    if( ret != MCNMAL )                 /* 正常に変換出来なかった時         */\
    {                                                                         \
        MIAPABT(ABTOHCCN, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_SETN													*/
/*																			*/
/* ＜機能概要＞  ﾌﾟﾛｾｽ再起動時のｱﾎﾞｰﾄの通知先を登録する。                   */
/* ＜仮引数＞																*/
/*	   P1		 送信先ﾌﾟﾛｾｽ名            						      stPD0A*/
/*	   P2		 送信先系区分            									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_SETN(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    long    mbid;                       /* ﾒｰﾙﾎﾞｯｸｽID                       */\
    MIA_MBID(P1, mbid, M_ID);           /* ﾒｰﾙﾎﾞｯｸｽID取得                   */\
    ret = mc_setn(mbid, (char)P2, 0x67ff, ZERO, ZERO, ZERO);                  \
	                                    /* ｱﾎﾞｰﾄ通知先登録                  */\
    if( ret != MCNORMAL )               /* 正常に登録出来なかった時         */\
    {                                                                         \
        MIAPABT(ABTOSETN, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_DELN													*/
/*																			*/
/* ＜機能概要＞  登録済みのｱﾎﾞｰﾄ通知の中から、ｱﾎﾞｰﾄ通知先登録を抹消します。 */
/* ＜仮引数＞																*/
/*	   P1		 送信先ﾌﾟﾛｾｽ名            									*/
/*	   P2		 送信先系区分            									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_DELN(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    long    mbid;                       /* ﾒｰﾙﾎﾞｯｸｽID                       */\
    MIA_MBID(P1, mbid, M_ID);           /* ﾒｰﾙﾎﾞｯｸｽID取得                   */\
    ret = mc_deln(mbid, (char)P2, 0x67ff, ZERO, ZERO, ZERO);                  \
	                                    /* ｱﾎﾞｰﾄ通知先抹消            edPD0A*/\
    if( ret != MCNORMAL )               /* 正常に抹消出来なかった時         */\
    {                                                                         \
        MIAPABT(ABTODELN, ABT_NULL, M_ID, ret);                               \
                                        /* ﾌﾟﾛｾｽｱﾎﾞｰﾄ                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_NTAB													*/
/*																			*/
/* ＜機能概要＞  mc_ntabにより登録されたｱﾎﾞｰﾄ通知先に対してｱﾎﾞｰﾄ通知を行なう*/
/* ＜仮引数＞																*/
/*	   なし                                                                 */
/****************************************************************************/
#define MIA_NTAB                                                              \
{                                                                             \
    long    ret;                        /* 返却値                           */\
    long    ntip[5];                    /* 登録時引数返却領域               */\
    for(;;)                                                                   \
    {                                                                         \
        ret = mc_ntab(ntip);            /* ｱﾎﾞｰﾄ通知                        */\
        if( ret != MCNORMAL )           /* 通知終了の場合                   */\
        {                                                                     \
            break;                      /* ﾙｰﾌﾟを抜ける                     */\
        }                                                                     \
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  PRMERR          											*/
/*																			*/
/* ＜機能概要＞  要求電文のﾊﾟﾗﾒｰﾀｴﾗｰ時の応答処理を行う。     				*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   USRP		 mia電文利用者域ﾎﾟｲﾝﾀ    									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define PRMERR(IRBP, USRP, M_ID)                                              \
{                                                                             \
    if( ((MIUSR *)USRP)->miifcd == IFCOMD )                                   \
    {                                   /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞｺﾏﾝﾄﾞの場合          */\
        (void)mcs_za00(MSG_20, ((MIIRB *)IRBP)->rd);                          \
                                        /* ｵﾍﾟﾚｰﾀ通知出力(SI20)             */\
        MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                         \
                                        /* 終了通知処理                 PD01*/\
        MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,                \
                 ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);         \
                                        /* ｱﾎﾞｰﾄ通知先抹消              PD0A*/\
    }                                                                         \
    else                                /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞ持回りの場合         */\
    {                                                                         \
        mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,              \
                 PST_200, M_ID);        /* 持回り応答通知処理(200)          */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_LINECHK     											*/
/*																			*/
/* ＜機能概要＞  要求電文の回線番号のﾁｪｯｸを行う　							*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_LINECHK(IRBP, M_ID)                                               \
{                                                                             \
    long     puno;                      /* ＰＵ番号                         */\
    long     chno;                      /* ﾁｬﾈﾙ番号                         */\
    MIUSR    *usrp;                     /* MIA電文利用者域ﾎﾟｲﾝﾀ             */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA電文利用者域ﾎﾟｲﾝﾀ設定         */\
    if( MCNMAL != mc_cbcn(usrp->milineno, (long *)&puno, 1) )                 \
    {                                   /* 正常に変換出来なかった時         */\
		PRMERR(IRBP, usrp, M_ID);       /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
		return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
    if( MCNMAL != mc_cbcn(&(usrp->milineno[1]), (long *)&chno, 2) )           \
    {                                   /* 正常に変換出来なかった時         */\
		PRMERR(IRBP, usrp, M_ID);       /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
		return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
	if( !(((puno >= 0) && (puno <= 7)) && ((chno >= 0) && (chno <= 99))) )    \
	{                                                                         \
		PRMERR(IRBP, usrp, M_ID);       /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
		return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
    ((MIIRB *)IRBP)->faceno = mia20003((short)puno, (short)chno);             \
                                        /* TFAC個別部検索処理               */\
    if( ((MIIRB *)IRBP)->faceno == MINOSING )                                 \
    {                                   /* TFAC個別部に該当する回線番号が   */\
                                        /* なかった場合                     */\
        if( usrp->miifcd == IFCOMD )    /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞｺﾏﾝﾄﾞの場合          */\
        {                                                                     \
            (void)mcs_za00(MSG_04, ((MIIRB *)IRBP)->rd, puno, chno);          \
                                        /* ｵﾍﾟﾚｰﾀ通知出力(SI04)             */\
            MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                     \
									    /* 終了通知処理                 PD01*/\
            MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,            \
                     ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);     \
                                        /* ｱﾎﾞｰﾄ通知先抹消              PD0A*/\
        }                                                                     \
        else                            /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞ持回りの場合         */\
        {                                                                     \
            mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,          \
                      PST_120, M_ID);   /* 持回り応答通知処理(120)          */\
        }                                                                     \
        return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_KASYCHK     											*/
/*																			*/
/* ＜機能概要＞  要求電文の折返し箇所のﾁｪｯｸを行う　							*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_KASYCHK(IRBP, M_ID)                                               \
{                                                                             \
    MIUSR    *usrp;                     /* MIA電文利用者域ﾎﾟｲﾝﾀ             */\
    TFACPSZ  *fackop;                   /* TFAC個別部ﾎﾟｲﾝﾀ                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA電文利用者域ﾎﾟｲﾝﾀ設定         */\
    KOADDR(TFAC_NO, ((MIIRB *)IRBP)->faceno, fackop);                         \
                                        /* TFAC個別部ｴﾝﾄﾘｱﾄﾞﾚｽを求めるstPD0G*/\
    switch( (unsigned char)fackop->tfacprtc )                                 \
    {                                   /* 回線種別により折返し箇所の正当性 */\
                                        /* をﾁｪｯｸする                       */\
        case PRTC4W :                   /* 4Wの場合                         */\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)) )                              \
            {                           /* 折返し箇所が”ﾁｬﾈﾙ外折返し”、   */\
                                        /* ”ﾁｬﾈﾙ内折返し”以外の場合       */\
                PRMERR(IRBP, usrp, M_ID);                                     \
                                        /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
                return(MIERR);          /* 処理異常終了                     */\
            }                                                                 \
            break;                                                            \
        case PRTCLOOP :                 /* HDLCﾙｰﾌﾟの場合              edM01*/\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)                                 \
               || (usrp->mitpoint == KASYO_3)) )                              \
            {                           /* 折返し箇所が”ﾁｬﾈﾙ外折返し”、   */\
                                        /* ”ﾁｬﾈﾙ内折返し”、”ﾁｬﾈﾙ内通信LSI*/\
                                        /* 外折返し”以外の場合             */\
                PRMERR(IRBP, usrp, M_ID);                                     \
                                        /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
                return(MIERR);          /* 処理異常終了                     */\
            }                                                                 \
            break;                                                            \
        case PRTCTCP :                  /* LANの場合                        */\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)                                 \
               || (usrp->mitpoint == KASYO_3)) )                              \
            {                           /* 折返し箇所が”i82596内部ﾙｰﾌﾟ”、 */\
                                        /* ”PLSﾙｰﾌﾟ”、”ﾄﾗﾝｼｰﾊﾞﾙｰﾌﾟ”     */\
                                        /* 以外の場合                       */\
                (void)mcs_za00(MSG_20, ((MIIRB *)IRBP)->rd);                  \
                                        /* ｵﾍﾟﾚｰﾀ通知出力(SI20)             */\
                MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                 \
                                        /* 終了通知処理                 PD01*/\
                MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,        \
                         ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID); \
                                        /* ｱﾎﾞｰﾄ通知先抹消              PD0A*/\
                return(MIERR);          /* 処理異常終了                     */\
            }                                                                 \
            break;                      /*                            edPD0G*/\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_TELCHK　　    											*/
/*																			*/
/* ＜機能概要＞  要求電文の電話番号のﾁｪｯｸを行う　							*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_TELCHK(IRBP, M_ID)                                                \
{                                                                             \
    MIUSR    *usrp;                     /* MIA電文利用者域ﾎﾟｲﾝﾀ             */\
    TFACPSZ  *fackop;                   /* TFAC個別部ﾎﾟｲﾝﾀ                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA電文利用者域ﾎﾟｲﾝﾀ設定         */\
    KOADDR(TFAC_NO, ((MIIRB *)IRBP)->faceno, fackop);                         \
                                        /* TFAC個別部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    if( !((usrp->miketa == 0) || (usrp->miketa == 0x20)) )                    \
	{                                   /* 電話番号桁数が０以外の場合       */\
        if( (usrp->miketa < 4) || (usrp->miketa > 20) )                       \
        {                               /* 電話番号桁数が４以上２０以下の   */\
                                        /* 範囲以外の場合                   */\
            PRMERR(IRBP, usrp, M_ID);   /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
            return(MIERR);              /* 処理異常終了                     */\
        }                                                                     \
    }                                                                         \
    if( mia20005(usrp->mibuteln, usrp->miketa) != MINORMAL )                  \
	{                                   /* 電話番号ﾆｭｰﾒﾘｯｸﾁｪｯｸ処理          */\
                                        /* 電話番号異常の場合               */\
        PRMERR(IRBP, usrp, M_ID);       /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
        return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_WORDCHK　　   											*/
/*																			*/
/* ＜機能概要＞  要求電文のﾊﾟｽﾜｰﾄﾞのﾁｪｯｸを行う　							*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   WORD		 WORDﾎﾟｲﾝﾀ                									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_WORDCHK(IRBP, WORD, M_ID)                                         \
{                                                                             \
    TFACSUB  *facsbp;                   /* TFACｻﾌﾞ共通部ﾎﾟｲﾝﾀ               */\
    MIKYO    *usrp;                     /* miaﾎﾟｲﾝﾀ                         */\
    long      rtn;                      /* 返却値                           */\
                                                                              \
    usrp = (MIKYO *)((MIIRB *)IRBP)->msgp;                                    \
										/* ﾎﾟｲﾝﾀ設定                        */\
    SUBADDR(TFAC_NO, facsbp);           /* TFACｻﾌﾞ共通部ﾎﾟｲﾝﾀ設定           */\
    MIA_CCOM(facsbp->tfacword, (char *)WORD, 4, rtn);                         \
                                        /* ﾊﾟｽﾜｰﾄﾞをTFACのﾊﾟｽﾜｰﾄﾞと比較     */\
    if( rtn != MINORMAL )               /* 不一致の場合                     */\
    {                                                                         \
        if( (unsigned char)usrp->miifcd == IFCOMD )                           \
		{                               /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞｺﾏﾝﾄﾞの場合          */\
            (void)mcs_za00(MSG_34, ((MIIRB *)IRBP)->rd);                      \
                                        /* ｵﾍﾟﾚｰﾀ通知出力(SI34)             */\
            MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                     \
									    /* 終了通知処理                 PD01*/\
            MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,            \
                     ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);     \
                                        /* ｱﾎﾞｰﾄ通知先抹消              PD0A*/\
        }                                                                     \
        else                            /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞ持回りの場合         */\
        {                                                                     \
            mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,          \
                      PST_800, M_ID);   /* 持回り応答通知処理(800)          */\
        }                                                                     \
        return(MIERR);                  /* 処理異常終了                     */\
    }                                                                         \
}
/*********************************************************************stPD0A*/
/*																			*/
/* ＜マクロ名＞  MIA_DOWN   　　   											*/
/*																			*/
/* ＜機能概要＞  ｼｽﾃﾑ構成がﾎｯﾄｽﾀﾝﾊﾞｲ状態で当該回線がﾀﾞｳﾝ要の場合ｼｽﾃﾑﾀﾞｳﾝ    */
/*               を行なう                                                   */
/* ＜仮引数＞																*/
/*	   P1  		 ＴＦＡＣ個別部ポインタ   									*/
/*	   P2  	     詳細情報                                                   */ 
/****************************************************************************/
#define MIA_DOWN(P1, P2)                                                      \
{                                                                             \
    extern  void  mr_sdwn(long, short, long);                                 \
                                        /* ｼｽﾃﾑﾀﾞｳﾝ処理                     */\
    TSSTPSZ   *sstkop;                  /* TSST個別部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
    KOADDR(TSST_NO, 1, sstkop);         /* TSST個別部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    if( ((unsigned char)((TFACPSZ *)P1)->tfacdown == DOWNON)                  \
     && ((unsigned char)sstkop->tsstsysc == SYSCHOT) )                        \
    {                                   /* 当該回線がﾀﾞｳﾝ要で               */\
                                        /* ｼｽﾃﾑ構成がﾎｯﾄｽﾀﾝﾊﾞｲの場合        */\
        mr_sdwn((long)MRDOWN, 0x67ff, (long)P2);                              \
                                        /* ｼｽﾃﾑﾀﾞｳﾝ処理発行                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIA_SUBADDR　　   											*/
/*																			*/
/* ＜機能概要＞  要求電文の着ｻﾌﾞｱﾄﾞﾚｽのﾁｪｯｸを行う　							*/
/* ＜仮引数＞																*/
/*	   IRBP		 IRBﾎﾟｲﾝﾀ                  									*/
/*	   M_ID	     発行元ﾓｼﾞｭｰﾙID      										*/
/****************************************************************************/
#define MIA_SUBADDR(IRBP, M_ID)                                               \
{                                                                             \
    MIUSR    *usrp;                     /* MIA電文利用者域ﾎﾟｲﾝﾀ             */\
    TFACPSZ  *fackop;                   /* TFAC個別部ﾎﾟｲﾝﾀ                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA電文利用者域ﾎﾟｲﾝﾀ設定         */\
    if( usrp->misadsz > SUBADDR_MAX )   /* 着ｻﾌﾞｱﾄﾞﾚｽが範囲外の場合         */\
    {                                                                         \
        PRMERR(IRBP, usrp, M_ID);       /* ﾊﾟﾗﾒｰﾀｴﾗｰ応答                    */\
        return(MIERR);                  /* 処理異常終了               edPD0A*/\
    }                                                                         \
}
/*********************************************************************stPD0E*/
/*																	  stPD0O*/
/* ＜マクロ名＞  MIA_LICP　　   											*/
/*																			*/
/* ＜機能概要＞  回線切替後のLICPの起動を行う  　							*/
/* ＜仮引数＞																*/
/*	   P1		 切替先TFACﾎﾟｲﾝﾀ           									*/
/*	   P2		 切替元TFACﾎﾟｲﾝﾀ           									*/
/*	   P3		 ｺﾝﾃｷｽﾄﾎﾟｲﾝﾀ              									*/
/*	   P4		 返却値                  									*/
/****************************************************************************/
#define MIA_LICP(P1, P2, P3, P4)                                              \
{                                                                             \
    extern  long  mia12300(long, TCSTPSZ *, TCOMPAT *, TCOMPAT *,             \
                           TCOMPAT *,  TCOMPAT *, MILCTX *);                  \
                                        /* LICP起動処理                     */\
    extern  long  mia12310(long, long, TCSTPSZ *, TCOMPAT *, TCOMPAT *,       \
                           TCOMPAT *,  TCOMPAT *, MILCTX *);                  \
                                        /* 切替後LICP起動処理               */\
    TCSTPSZ *cstkop;                    /* TCST個別部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
    TCOMPAT *faccmp;                    /* TFAC共通部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
    TCOMPAT *fapcmp;                    /* TFAP共通部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
    TCOMPAT *faxcmp;                    /* TFAX共通部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
    TCOMPAT *falcmp;                    /* TFAL共通部ｴﾝﾄﾘｱﾄﾞﾚｽ              */\
                                                                              \
    KOADDR(TCST_NO, 1, cstkop);         /* TCST個別部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    COMADDR(TFAC_NO, faccmp);           /* TFAC共通部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    COMADDR(TFAP_NO, fapcmp);           /* TFAP共通部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    COMADDR(TFAX_NO, faxcmp);           /* TFAX共通部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    COMADDR(TFAL_NO, falcmp);           /* TFAL共通部ｴﾝﾄﾘｱﾄﾞﾚｽを求める      */\
    if( P2 == ZERO )                    /* 切替後の起動以外の時             */\
    {                                                                         \
	    P4 = mia12300((long)P1, cstkop, faccmp, fapcmp, faxcmp, falcmp,       \
                       (MILCTX *)P3);   /* LICP起動処理                     */\
    }                                                                         \
    else                                /* 切替後の起動時                   */\
    {                                                                         \
	    P4 = mia12310((long)P1, (long)P2, cstkop, faccmp, fapcmp, faxcmp,     \
                       falcmp, (MILCTX *)P3);                                 \
                                        /* 切替後LICP起動処理         edPD0E*/\
    }                                   /*                            edPD0O*/\
}
