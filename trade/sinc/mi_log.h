/****************************************************************************/
/* ファイル名：　mi_log.h                                                   */
/* 機能  　　：  ﾌﾟﾛｾｽﾛｸﾞ取得関連ﾏｸﾛ                                        */
/* 作成日　  ：  1993.12.13                                                 */
/* 変更日　  ：  1994.10.14                                             PD0A*/
/*   故障処理票(ST1761) 統合Ｉ／Ｏ対応                                      */
/* 変更日　　：  1996.03.05                                             PD0R*/ 
/*   仕様変更要求書(SSCY0156) X.25回復監視変更対応                          */ 
/****************************************************************************/
#include <mc.h>                         /* mc.h                             */
#include <mc_logx.h>                    /* Pﾄﾚｰｽ情報取得ﾍｯﾀﾞﾌｧｲﾙ使用宣言    */
#include <mc_logmac.h>                  /* ｼｽﾃﾑｺｰﾙﾏｸﾛ宣言ﾍｯﾀﾞﾌｧｲﾙ使用宣言   */

#define MILOGA00    0x00ff9000          /* 関数TRACEﾛｸﾞID(SI_1)             */
#define MILOGV01    0x00ff9001          /* 受信ﾒｯｾｰｼﾞﾛｸﾞ                    */
#define MILOGV12    0x00ff9012          /* 非完了ｵｰﾌﾟﾝ完了ﾛｸﾞ               */
#define MILOGV13    0x00ff9013          /* 非完了ｸﾛｰｽﾞ完了ﾛｸﾞ               */
#define MILOGV20    0x00ff9020          /* 折返設定完了ﾛｸﾞ                  */
#define MILOGV22    0x00ff9022          /* 着呼完了ﾛｸﾞ                      */
#define MILOGV23    0x00ff9023          /* 発呼完了ﾛｸﾞ                      */
#define MILOGV24    0x00ff9024          /* 非同期通知完了ﾛｸﾞ                */
#define MILOGV25    0x00ff9025          /* 折返試験ﾃﾞｰﾀ送信完了ﾛｸﾞ          */
#define MILOGV26    0x00ff9026          /* 切断完了ﾛｸﾞ                  PD0A*/
#define MILOGV27    0x00ff9027          /* ﾃﾞｰﾀﾘﾝｸ再設定完了ﾛｸﾞ         PD0R*/
#define MILOGVSS    0x00ff90f0          /* 入口ﾁｬﾈﾙｽﾃｰﾀｽﾛｸﾞ                 */
#define MILOGVSE    0x00ff90f1          /* 出口ﾁｬﾈﾙｽﾃｰﾀｽﾛｸﾞ                 */
#define MILOGVLP    0x00ff90ff          /* 論理ﾊﾟｽｽﾃｰﾀｽ更新時ﾛｸﾞ            */

#define POF_MKCODE           0
#define POF_SENDPROCESS     32
#define POF_RCVPROCESS      40
#define POF_IFCODE          88
#define POF_SYBETU         144

extern   long   mc_logv();              /* ﾄﾚｰｽ情報取得                     */
extern   long   mc_loga(long, long, char *);
                                        /* ﾄﾚｰｽ情報取得                     */

typedef struct {
    char    pnm[8];                     /* 送信元メールボックス識別子       */
    long    mkcd;                       /* コマンドコード                   */
    long    ifcd;                       /* インタフェースコード             */
    long    msgsize;                    /* メッセージ長サイズ               */
    char    sybetu[9];                  /* 通知種別                         */
    char    lineno[3];                  /* 回線番号／論理ﾊﾟｽ番号            */
} MMSGTR;                               /* ＭＩＡ電文トレース情報           */

#define PLOG_RVNTFY(P1, P2)             /* Pﾄﾚｰｽ取得（OSからの非同期通知受  */\
                                        /* 信時）                           */\
    mc_loga(CL_RVNTFY, P1, (char *)P2)

#define PLOG_RVMIAMSG(P1, P2)           /* Pﾄﾚｰｽ取得（ＭＩＡ電文受信時）    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* ＭＩＡ電文トレース情報           */\
    int i;                              /* ループカウンタ                   */\
    for( i = 0; i < 8; i++)             /* 送信元プロセス識別名を取り出す   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_SENDPROCESS + i);            \
                                        /* １オクテットスずつ取り出す       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* ＭＫコードを取り出す             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* インタフェースコードを取り出す   */\
    mmsgtr.msgsize = P1;                /* メッセージ長を取り出す           */\
    if( mmsgtr.ifcd == 0x58001000 )     /* ｲﾝﾀｰﾌｪｰｽｺｰﾄﾞがﾕｰﾃｨﾘﾃｨ起動依頼時　*/\
    {                                                                         \
        for( i = 0; i < 9; i++)         /* 通知種別を取り出す               */\
        {                                                                     \
            mmsgtr.sybetu[i] = *(char *)((long)P2 + POF_SYBETU + i);          \
                                        /* １オクテットスずつ取り出す       */\
        }                                                                     \
    }                                                                         \
    mc_loga(                                                                  \
        CL_RVMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
		(char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* Ｐトレース取得                   */\
                                        /*   ＭＩＡ電文受信のログ           */\
                                        /*   ＭＩＡ電文トレース情報のサイズ */\
                                        /*   ＭＩＡ電文トレース情報の格納域 */\
                                        /*   受信電文長                     */\
}
#define PLOG_SDMIAMSG(P1, P2)           /* Pﾄﾚｰｽ取得（ＭＩＡ電文送信時）    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* ＭＩＡ電文トレース情報           */\
    int i;                              /* ループカウンタ                   */\
    for( i = 0; i < 8; i++)             /* 送信先プロセス識別名を取り出す   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_RCVPROCESS + i);             \
                                        /* １オクテットスずつ取り出す       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* ＭＫコードを取り出す             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* インタフェースコードを取り出す   */\
    mmsgtr.msgsize = P1;                /* メッセージ長を取り出す           */\
    mc_loga(                                                                  \
        CL_SDMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
        (char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* Ｐトレース取得                   */\
                                        /*   ＭＩＡ電文送信のログ           */\
                                        /*   ＭＩＡ電文トレース情報のサイズ */\
                                        /*   ＭＩＡ電文トレース情報の格納域 */\
                                        /*   送信電文長                     */\
}
/****************************************/
/* IRB情報取得ﾏｸﾛ　　                   */
/* <取得情報>                           */
/*  �　�IRｺｰﾄﾞ                          */
/*  �◆�ｻﾌﾞIRｺｰﾄﾞ                       */
/*  ��  ﾒｯｾｰｼﾞｱﾄﾞﾚｽ                     */
/*  ��  ﾒｯｾｰｼﾞ長　                      */
/****************************************/
#define LOG_IRB(p1)                                                           \
{                                                                             \
    mc_logv(MILOGV01, 5L,                                                     \
            (long)((MIIRB *)p1)->ir_cd,                                       \
            (long)((MIIRB *)p1)->sir_cd,                                      \
            (long)(((MIIRB *)p1)->msgp),                                      \
            (long)((MIIRB *)p1)->msglen,                                      \
            (long)((MILCTX *)((MIIRB *)p1)->ctxtp)->lineno);                  \
                                        /* ﾛｸﾞ取得関数実行              PD0A*/\
}
/****************************************/
/* 論理ﾊﾟｽｽﾃｰﾀｽ更新情報取得ﾏｸﾛ          */
/* <取得情報>                           */
/*      更新前論理ﾊﾟｽｽﾃｰﾀｽ              */
/*      更新後論理ﾊﾟｽｽﾃｰﾀｽ              */
/*      ﾓｼﾞｭｰﾙID                        */
/****************************************/
#define LOG_LPT(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* ﾛｸﾞ取得関数実行                  */\
}
/****************************************/
/* ｼｽﾃﾑｺｰﾙ返却値情報取得ﾏｸﾛ             */
/* <取得情報>                           */
/*      非完了ｼｽﾃﾑｺｰﾙ返却値             */
/*      ﾓｼﾞｭｰﾙID                        */
/****************************************/
#define LOG_RTN(p1, p2, p3)                                                   \
{                                                                             \
    mc_logv(p1, 2L,(long)p2, (long)(0x67ff0000 | ((long)p3)));                \
								        /* ﾛｸﾞ取得関数実行                  */\
}
/****************************************/
/* ｽﾃｰﾀｽ情報取得ﾏｸﾛ                     */
/* <取得情報>                           */
/*      論理ﾁｬﾈﾙｽﾃｰﾀｽ                   */
/*      物理ﾁｬﾈﾙｽﾃｰﾀｽ                   */
/*      ﾓｼﾞｭｰﾙID                        */
/****************************************/
#define LOG_STS(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* ﾛｸﾞ取得関数実行                  */\
}
/****************************************/
/* 関数ﾄﾚｰｽ情報取得ﾏｸﾛ(SI1ﾃｽﾄ用)        */
/****************************************/
#ifdef  SI_1
#define DBGTRACE(P1)                                                          \
{                                                                             \
    printf(P1);                                                               \
    printf("\n");                                                             \
}
#else
#define DBGTRACE(P1)                                                          \
{                                                                             \
    mc_loga(MILOGA00, 8, (char *)P1);   /* ﾛｸﾞ取得関数実行              PD0A*/\
}
#endif
/****************************************/
/* ﾀﾞﾝﾌﾟ取得ﾏｸﾛ(SI1ﾃｽﾄ用)               */
/****************************************/
#ifdef  SI_D
#define DBGDMP(P1, P2)                                                        \
{                                                                             \
    extern  long   DumpHex();                                                 \
	DumpHex(P1, P2);                    /* ﾀﾞﾝﾌﾟ取得関数実行                */\
}
#else
#define DBGDMP(P1, P2)
#endif
