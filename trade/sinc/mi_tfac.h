/****************************************************************************/
/* ファイル名：　mi_tfac.h                                                  */
/* 機能  　　：  ＴＦＡＣテーブルテンプレート                               */
/*               ＴＦＡＣ定数情報                                           */
/*               ＴＦＡＣ更新マクロ                                         */
/* 作成日　  ：  1993.12.14                                                 */
/* 変更日　  ：  1994.10.14                                             PD0A*/
/*   故障処理票(ST1761) 統合Ｉ／Ｏ対応                                      */
/* 変更日　  ：  1995.06.13                                             PD0C*/
/*   仕様変更要求書(SSCY0062) 動的システム変更対応                          */
/* 変更日　  ：  1995.10.13                                             PD01*/
/*   故障処理票(ST3572) 障害検出時ｸﾛｰｽﾞ待ち追加                             */
/* 変更日　　：  1995.11.29                                             PD0O*/
/*   仕様変更要求書(SSCY0063) ＬＩＣＰ再起動対応                            */
/* 変更日　  ：  1996.06.12                                             PD02*/
/*   故障処理票(ST4423) 物理ｽﾃｰﾀｽ選択中追加                                 */
/****************************************************************************/
#include    <tfac.h>                    /* ＴＦＡＣテーブルテンプレート     */

/**************************************/
/* ＴＦＡＣ処理中種別                 */
/**************************************/
#define PRSTINIT    0x00                /* 初期状態                         */
#define PRSTKIRI    0x01                /* 切替処理中                       */
#define PRSTMODO    0x02                /* 切戻し処理中                     */
#define PRSTTEST    0x03                /* 折返試験中                   PD0C*/
#define PRSTHAIT    0x04                /* 排他区間設定中               PD0C*/

/**************************************/
/* ＴＦＡＣ一括処理フラグ             */
/**************************************/
#define IKFGNORM    0x00                /* 通常処理                         */
#define IKFGBAT     0x01                /* 一括処理                         */

/**************************************/
/* ＴＦＡＣ要求元種別                 */
/**************************************/
#define TVRNINIT    0x00                /* 初期状態                         */
#define TVRNCOMD    0x01                /* コマンド                         */
#define TVRNMOTI    0x02                /* 持回り                           */

/**************************************/
/* ＴＦＡＣ障害ステータス             */
/**************************************/
#define SYGINORM    0x00                /* 正常                             */
#define SYGISYGI    0x10                /* 障害                             */

/**************************************/
/* ＴＦＡＣ着呼状態フラグ             */
/**************************************/
#define CYKFOK      0x00                /* 着呼正常終了                     */
#define CYKFNG      0x01                /* 着呼異常終了                     */

/**************************************/
/* ＴＦＡＣ回復メッセージ出力有無     */
/**************************************/
#define LPMGOFF     0x00                /* 無                               */
#define LPMGON      0x01                /* 有                               */

/**************************************/
/* ＴＦＡＣチャネル運用情報           */
/**************************************/
#define UINFCOM     0x00                /* 共用回線                     PD0A*/

/**************************************/
/* ＴＦＡＣチャネル閉塞フラグ         */
/**************************************/
#define CHCLINS     0x00                /* 非閉塞                           */
#define CHCLOUS     0x01                /* 閉塞中                           */

/**************************************/
/* ＴＦＡＣ障害メッセージ出力有無     */
/**************************************/
#define LPMGOFF     0x00                /* 無                               */
#define LPMGON      0x01                /* 有                               */

/**************************************/
/* ＴＦＡＣドライバ種別               */
/**************************************/
#define PRTC4W      0x41                /* ４Ｗ                         PD0A*/
#define PRTCLOOP    0x42                /* ＨＤＬＣループ               PD0A*/
#define PRTCZEN     0x4A                /* 全銀協ベーシック             PD0A*/
#define PRTCSYN     0x4B                /* ＳＹＮ同期全２重             PD0A*/
#define PRTCQ931    0x5B                /* Ｑ．９３１                   PD0A*/
#define PRTCX25     0x68                /* Ｘ．２５                     PD0A*/
#define PRTCTCP     0x6C                /* ＴＣＰ／ＩＰ                 PD0A*/

/**************************************/
/* ＴＦＡＣ回線種別                   */
/**************************************/
#define NETWSEN     0x00                /* 専用直通回線                 PD0A*/
#define NETWTEL     0x01                /* 電話網                       PD0A*/
#define NETWDCH     0x10                /* ISDN-Dch                     PD0A*/
#define NETWB1CH    0x11                /* ISDN-B1ch                    PD0A*/
#define NETWB2CH    0x12                /* ISDN-B2ch                    PD0A*/

/**************************************/
/* ＴＦＡＣ回復監視要不要             */
/**************************************/
#define RECVOFF     0x00                /* 回復監視を行わない           PD0A*/
#define RECVON      0x01                /* 回復監視を行う               PD0A*/

/**************************************/
/* ＴＦＡＣISDNチャネルステータス     */
/**************************************/
#define PTCLINIT    0x00                /* チャネル未オープン           PD0A*/
#define PTCLONE     0x01                /* チャネルオープン済み         PD0A*/
#define PTCLTWO     0x02                /* チャネルオープン済み         PD0A*/

/**************************************/
/* ＴＦＡＣｼｽﾃﾑﾀﾞｳﾝｽﾃｰﾀｽ              */
/**************************************/
#define DOWNOFF     0x00                /* ｼｽﾃﾑﾀﾞｳﾝは行なわない         PD0A*/
#define DOWNON      0x01                /* ﾊｰﾄﾞ障害時ｼｽﾃﾑﾀﾞｳﾝを行なう   PD0A*/

/***************************************/
/* 論理ﾁｬﾈﾙｽﾃｰﾀｽ（4W､HDLCﾙｰﾌﾟ､TEL対応）*/
/***************************************/
#define STSL00      0x00                /* S00:初期状態                     */
#define STSL01      0x01                /* S01:ﾁｬﾈﾙｵｰﾌﾟﾝ完了待              */
#define STSL02      0x02                /* S02:非同期通知完了待             */
#define STSL03      0x03                /* S03:障害中                       */
#define STSL04      0x04                /* S04:切断状態                     */
#define STSL05      0x05                /* S05:回復監視時ﾁｬﾈﾙｸﾛｰｽﾞ完了待    */
#define STSL06      0x06                /* S06:回復監視時ﾊﾟｽｸﾛｰｽﾞ応答       */
                                        /*     &ﾀｲﾑｱｳﾄ待                    */
#define STSL07      0x07                /* S07:回復監視時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL08      0x08                /* S08:回復監視時　　　             */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL09      0x09                /* S09:回復監視時非同期通知完了     */
                                        /*     &ﾀｲﾑｱｳﾄ待                    */
#define STSL10      0x0a                /* S10:折返試験時ﾁｬﾈﾙｸﾛｰｽﾞ完了待    */
#define STSL11      0x0b                /* S11:折返試験時ﾊﾟｽｸﾛｰｽﾞ応答       */
                                        /*     &ﾀｲﾑｱｳﾄ待                    */
#define STSL12      0x0c                /* S12:折返試験時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL13      0x0d                /* S13:折返試験時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL14      0x0e                /* S14:折返試験時RLA同期合わせ      */
                                        /*     ﾀｲﾏ完了待                    */
#define STSL15      0x0f                /* S15:折返試験時設定完了待         */
#define STSL16      0x10                /* S16:折返試験時ﾃﾞｰﾀ送信完了待     */
#define STSL17      0x11                /* S17:折返試験終了時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL18      0x12                /* S18:着呼切替時ﾁｬﾈﾙｸﾛｰｽﾞ完了待    */
#define STSL19      0x13                /* S19:着呼切替時ﾊﾟｽｸﾛｰｽﾞ応答       */
                                        /*     &ﾀｲﾑｱｳﾄ待                    */
#define STSL20      0x14                /* S20:着呼切替時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL21      0x15                /* S21:着呼切替時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL22      0x16                /* S22:着呼切替時時着呼完了待       */
#define STSL23      0x17                /* S23:着呼切替時時                 */
                                        /*     着呼ﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待        */
#define STSL24      0x18                /* S24:着呼切替時切替許可待         */
#define STSL25      0x19                /* S25:着呼切替終了時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL26      0x1a                /* S26:発呼切替時ﾁｬﾈﾙｸﾛｰｽﾞ完了待    */
#define STSL27      0x1b                /* S27:発呼切替時ﾊﾟｽｸﾛｰｽﾞ応答       */
                                        /*     &ﾀｲﾑｱｳﾄ待                    */
#define STSL28      0x1c                /* S28:発呼切替時切替許可           */
#define STSL29      0x1d                /* S29:発呼切替時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL30      0x1e                /* S30:発呼切替時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL31      0x1f                /* S31:発呼切替時発呼完了待         */
#define STSL32      0x20                /* S32:発呼切替時時                 */
                                        /*     発呼ﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待        */
#define STSL33      0x21                /* S33:発呼切替終了時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL34      0x22                /* S34:発呼切替（許可無）時         */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL35      0x23                /* S35:発呼切替（許可無）時         */
                                        /*     ﾊﾟｽｸﾛｰｽﾞ応答&ﾀｲﾑｱｳﾄ待        */
#define STSL36      0x24                /* S36:発呼切替（許可無）時         */
                                        /*     ﾁｬﾈﾙｵｰﾌﾟﾝ完了待              */
#define STSL37      0x25                /* S37:発呼切替（許可無）時         */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL38      0x26                /* S38:発呼切替（許可無）時         */
                                        /*     発呼完了待                   */
#define STSL39      0x27                /* S39:発呼切替（許可無）時         */
                                        /*     発呼ﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙﾀｲﾏ待         */
#define STSL40      0x28                /* S40:発呼切替（許可無）           */
                                        /*     終了時ﾁｬﾈﾙｸﾛｰｽﾞ完了待        */
#define STSL41      0x29                /* S41:発呼強制切替時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL42      0x2a                /* S42:発呼強制切替時               */
                                        /*     ﾊﾟｽｸﾛｰｽﾞ応答&ﾀｲﾑｱｳﾄ待        */
#define STSL43      0x2b                /* S43:発呼強制切替時               */
                                        /*     ﾁｬﾈﾙｵｰﾌﾟﾝ完了待              */
#define STSL44      0x2c                /* S44:発呼強制切替時               */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL45      0x2d                /* S45:発呼強制切替時               */
                                        /*     発呼完了待                   */
#define STSL46      0x2e                /* S46:発呼強制切替時               */
                                        /*     発呼ﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙﾀｲﾏ待         */
#define STSL47      0x2f                /* S47:発呼強制切替時               */
                                        /*     終了時ﾁｬﾈﾙｸﾛｰｽﾞ完了待        */
#define STSL48      0x30                /* S48:切戻時ﾁｬﾈﾙｸﾛｰｽﾞ完了待        */
#define STSL49      0x31                /* S49:切戻時ﾊﾟｽｸﾛｰｽﾞ応答&ﾀｲﾑｱｳﾄ待  */
#define STSL50      0x32                /* S50:障害中再起動時               */
                                        /*     ﾊﾟｽｸﾛｰｽﾞ応答&ﾀｲﾑｱｳﾄ待        */
#define STSL51      0x33                /* S51:非障害再起動時               */
                                        /*     ﾊﾟｽｸﾛｰｽﾞ応答&ﾀｲﾑｱｳﾄ待        */
#define STSL52      0x34                /* S52:チャネル閉塞中               */
#define STSL53      0x35                /* S53:発呼切替(許可無)時       PD0A*/
                                        /*     呼切断完了待             PD0A*/
#define STSL54      0x36                /* S54:発呼切替(許可無)時       PD0A*/
                                        /*     臨時呼切断要求完了待     PD0A*/
#define STSL55      0x37                /* S55:発呼強制切替時           PD0A*/
                                        /*     呼切断完了待             PD0A*/
#define STSL56      0x38                /* S56:発呼強制切替時           PD0A*/
                                        /*     臨時呼切断要求完了待     PD0A*/
#define STSL57      0x39                /* S57:切戻時呼切断完了待       PD0A*/
#define STSL58      0x3a                /* S58:                         PD0C*/
#define STSL59      0x3b                /* S59:                         PD0C*/
#define STSL60      0x3c                /* S60:                         PD0O*/
#define STSL61      0x3d                /* S61:                         PD0O*/
#define STSL62      0x3e                /* S62:                         PD0O*/
/***************************************/
/* 物理ﾁｬﾈﾙｽﾃｰﾀｽ（ﾊﾞｯｸｱｯﾌﾟ対応）       */
/***************************************/
#define STSP00      0x00                /* S00:初期状態                     */
#define STSP01      0x01                /* S01:折返試験時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSP02      0x02                /* S02:折返試験時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSP03      0x03                /* S03:折返試験時RLA同期合わせ      */
                                        /*     ﾀｲﾏ完了待                    */
#define STSP04      0x04                /* S04:折返試験時設定完了待         */
#define STSP05      0x05                /* S05:折返試験時ﾃﾞｰﾀ送信完了待     */
#define STSP06      0x06                /* S06:折返試験終了時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSP07      0x07                /* S07:臨時接続時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSP08      0x08                /* S08:臨時接続時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSP09      0x09                /* S09:臨時接続時発呼完了待         */
#define STSP10      0x0a                /* S10:臨時接続時                   */
                                        /*     発呼ﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙﾀｲﾏ待         */
#define STSP11      0x0b                /* S11:臨時接続時                   */
                                        /*     終了時ﾁｬﾈﾙｸﾛｰｽﾞ完了待        */
#define STSP12      0x0c                /* S12:臨時接続状態             PD0A*/
#define STSP13      0x0d                /* S13:臨時切断時               PD0A*/
                                        /*     呼切断完了待             PD0A*/
#define STSP14      0x0e                /* S14:臨時切断時               PD0A*/
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待          PD0A*/
#define STSP15      0x0f                /* S15:障害検出時             stPD01*/
                                        /*     呼切断完了待                 */
#define STSP16      0x10                /* S16:障害検出時                   */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待        edPD01*/
#define STSPFB      0xfb                /* Sfb:選択中                   PD02*/
#define STSPFC      0xfc                /* Sfc:LICP起動失敗             PD0O*/
#define STSPFD      0xfd                /* Sfd:PU,CH不整                    */
#define STSPFE      0xfe                /* Sfe:運用対象外                   */
#define STSPFF      0xff                /* Sff:パッケージ未実装             */
/***************************************/
/* 論理ﾁｬﾈﾙｽﾃｰﾀｽ（LAN対応）            */
/***************************************/
#define STSL00L     0x00                /* S00:初期状態                     */
#define STSL01L     0x01                /* S01:ﾁｬﾈﾙｵｰﾌﾟﾝ完了待              */
#define STSL02L     0x02                /* S02:ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙﾀｲﾏ完了待    */
#define STSL03L     0x03                /* S03:非同期通知完了待             */
#define STSL04L     0x04                /* S04:ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL05L     0x05                /* S05:チャネル閉塞中               */
#define STSL06L     0x06                /* S06:チャネル非閉塞               */
#define STSL07L     0x07                /* S07:折返試験時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL08L     0x08                /* S08:折返試験時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL09L     0x09                /* S09:折返試験時設定完了待         */
#define STSL10L     0x0a                /* S10:折返試験時ﾃﾞｰﾀ送信完了待     */
#define STSL11L     0x0b                /* S11:折返試験終了時               */
                                        /*     ﾁｬﾈﾙｸﾛｰｽﾞ完了待              */
#define STSL12L     0x0c                /* S12:閉塞解除時ﾁｬﾈﾙｵｰﾌﾟﾝ完了待    */
#define STSL13L     0x0d                /* S13:閉塞解除時                   */
                                        /*     ｵｰﾌﾟﾝﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙ完了待       */
#define STSL14L     0x0e                /* S14:                         PD0C*/
