/*********************************************************************/
/****************< tmig.h >*******************************************/
/*********************************************************************/

/**********************************/
/*  TMIG ｻﾌﾞ共通部定義            */
/**********************************/
typedef struct   tmigsub{
        long     tmigtim1;              /* セットアップリトライタイマ       */
        long     tmigtim2;              /* 送達確認待ちタイマ               */
        long     tmigtim3;              /* 系間応答待ちタイマ               */
        long     tmigtim4;              /* 次電文待ちタイマ                 */
        short    tmignnum;              /* ネットワーク内ノード数           */
        short    tmiglnnd;              /* ＬＡＮ接続ノード数               */
        short    tmigevmx;              /* 送受信最大数                     */
        char     tmigrtmx;              /* セットアップリトライ回数         */
        char     tmiglinn;              /* 回線数                           */
} TMIGSUB;

/**********************************/
/*  TMIG 個別部定義               */
/**********************************/
/*-------------------*/
/* 個別部管理域      */
/*-------------------*/
typedef struct   tmigpsm{
        short    tmiglnno;              /* 回線番号                         */
        short    tmigrpno;              /* 受信論理パス番号                 */
        char     tmigtype;              /* 通信方式                         */
        char     tmigdmy2;              /* 予備２                           */
        short    tmigentn;              /* エントリノード数                 */
} TMIGPSM;

/*-------------------*/
/* 個別部情報域      */
/*-------------------*/
typedef struct   tmigpsp{
        short    tmigndno;              /* ノード番号                       */
        short    tmigspno;              /* 送信論理パス番号                 */
        long     tmigipad;              /* 相手ノードＩＰアドレス           */
        short    tmiglpno;              /* 相手ノードＬＩＳＴＥＮポート番号 */
        short    tmigapno;              /* 相手ノードＡＣＴＩＶＥポート番号 */
        char     tmigace1;              /* 現用装置番号                     */
        char     tmigace2;              /* 予備装置番号                     */
        char     tmigdmy[2];            /* 予備３                           */
} TMIGPSP;
