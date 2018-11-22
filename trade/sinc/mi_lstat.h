/****************************************************************************/
/* ファイル名：　mi_lstat.h                                                 */
/* 機能  　　：  LANﾁｬﾈﾙ状態用ﾍｯﾀﾞｰﾌｧｲﾙ                                     */
/* 作成日　  ：  1993.12.30                                                 */
/****************************************************************************/
typedef struct {
    short   lineno;                     /* 回線番号                         */
    short   class;                      /* 回線インタフェースクラス         */
    char    data[64];                   /* 回線インタフェースデータ         */
}   MILINF;

#define LDACT   0x0000                  /* 初期状態                         */
#define LHALT   0x0001                  /* 回線障害中                       */
#define LTEST   0x0002                  /* 試験中                           */
#define LPUNE   0x0003                  /* 回線パッケージ未実装             */
#define LACTV   0x0004                  /* アクセス可                       */
#define LERR1   -1                      /* ＴＦＡＣテーブル取得エラー       */
#define LERR2   -2                      /* ＴＦＡＣステータスエラー         */
#define LERR3   -3                      /* ＴＦＡＣサーチエラー             */
