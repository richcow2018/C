/****************************************************************************/
/*      mo.hのインクルードファイル                                          */
/****************************************************************************/
/****************************************************************************/
/*      SMP運転状況構造体                                                   */
/****************************************************************************/
struct mosdinf {
	char  mosdsyd;						/* 系区分							*/
	char  mosdsyc;						/* システム構成情報					*/
	char  mosdstd;						/* 開始区分							*/
	char  mosdrsv;						/* ブロック番号詳細			TD01	*/
	long  mosdpmd;						/* プログラムモード					*/
	char  mosdost;						/* ブロック運転情報			TD01	*/
	char  mosdrv2[3];					/* 予備2							*/
};                                                                     
typedef struct mosdinf MOSDINF;                                        

/****************************************************************************/
/* 		正常返却値		#define												*/
/****************************************************************************/
#define  MONORMAL  0L					/* 正常(に解放した)					*/

/****************************************************************************/
/* 		mo_gtbf 返却値	#define												*/
/****************************************************************************/
#define  MOEEFLBF  0L					/* プールバッファに空きがない		*/
#define  MOIVMEID -1L					/* バッファ種別が異常である			*/
#define  MOIVPBLN -2L					/* バッファ長が異常である			*/

#define  MOCMPBF   0L					/* CMバッファ						*/
#define  MOLMPBF   1L					/* LMバッファ						*/

/****************************************************************************/
/* 		mo_frbf 返却値	#define												*/
/****************************************************************************/
#define  MOEEEXST  1L					/* 既に解放済みである				*/
#define  MOIVPBAD -1L					/* 指定したアドレスが異常である		*/

/****************************************************************************/
/* 		mo_excm			#define												*/
/****************************************************************************/
#define  MOXMEXEC  0x00					/* コマンド実行						*/
#define  MOXMCRPR  0x01					/* プロセス生成						*/

/****************************************************************************/
/* 		mo_excm	返却値	#define												*/
/****************************************************************************/
#define  MOCMOVR  -1L					/* コマンド文字列の長さオーバー		*/
#define  MONOMEM  -2L					/* プールバッファの取得ができない	*/
#define  MOERROR  -3L					/* コマンドorパラメータエラー		*/
#define  MOTIMOU  -6L					/* タイムアウト						*/

/****************************************************************************/
/* 		mo_crpr	返却値	#define												*/
/****************************************************************************/
#define  MOPROMO   1L					/* 該当プロセスは起動中				*/
#define  MONOPCT  -1L					/* 指定プロセス識別名PCTになし		*/
#define  MOPRONG  -2L					/* プロセス生成失敗					*/
#define  MONOBUF  -3L					/* プールバッファが確保できない		*/
#define  MOLNOVR  -4L					/* パラメータの合計長がオーバー		*/
#define  MOPRMIS  -5L					/* 起動パラメータの指定に誤り		*/

/****************************************************************************/
/* 		mo_ipct	返却値	#define												*/
/****************************************************************************/
#define  MOPCTLER  -1L					/* 論理矛盾							*/

/****************************************************************************/
/* 		mo_apdt	返却値	#define												*/
/****************************************************************************/
#define	MONORMX     1L					/* 条件付き正常終了					*/
#define	MOMFERR    -2L					/* 資源関係処理失敗					*/
#define	MONOTAPD   -3L					/* AP日付使用システムでない			*/
#define	MOTRANERR  -4L					/* トランザクション中である			*/
#define	MOMRERR    -5L					/* ジャーナル編集・取得失敗			*/

#define	MOAPGET		0L					/* 取得モード						*/
#define	MOAPSET		1L					/* 設定モード						*/

/****************************************************************************/
/* 		長さ			#define												*/
/****************************************************************************/
#define  MOGTPBFL  384L					/* コマンド編集バッファ長			*/
#define  MOCRPBFL  384L					/* コマンド編集バッファ長			*/
#define  MOLIMCML  256L					/* コマンド文字列制限長				*/

/****************************************************************************/
/* 		プロセス情報取得構造体								STC534			*/
/****************************************************************************/
struct moprinf {
	char  mogtpnam[8];					/* プロセス識別名					*/
	long  mogtpid;						/* プロセス識別子					*/
	long  mogtpmb;						/* メイルボックス識別子				*/
	short mogtpno;						/* プロセスNO.						*/
	char  mogtobno;						/* 起動元ブロック番号詳細	TD01	*/
	char  mogtrcv;						/* 予備						TD01	*/
	char  mogtsts;						/* プロセス状態						*/
	char  mogtabt;						/* アボート時の処理					*/
	char  mogtshu;						/* プロセス種別				TD00	*/
	char  mogtodev;						/* 起動元系区分						*/
	char  mogtopnm[8];					/* 起動元プロセス識別名				*/
};
typedef struct moprinf MOPRINF;

/****************************************************************************/
/* 		mo_prgt	返却値	#define								STC534			*/
/****************************************************************************/
#define  MOPNAMNG  -1L					/* pnam all blank					*/
#define  MONOTPCT  -2L					/* TPCTがない						*/
#define  MONOTFND  -3L					/* TPCTにない						*/

/****************************************************************************/
/* 		mo_prgt	ステータス	#define							STC534			*/
/****************************************************************************/
#define  MOGTNON   '0'					/* 未処理							*/
#define  MOGTREQ   '1'					/* 起動要求中						*/
#define  MOGTING   '2'					/* 起動中							*/
#define  MOGTSUS   '3'					/* 一時停止中						*/
#define  MOGTEND   '4'					/* 終了要求中						*/
#define  MOGTCED   '5'					/* 強制終了要求中					*/
#define  MOGTSSP   '6'					/* サスペンド中				TD02	*/

/****************************************************************************/
/* 		mo_prgt	種別	#define								STC534			*/
/****************************************************************************/
#define  MOGTON   '0'					/* オンラインプロセス				*/
#define  MOGTOFF  '1'					/* オフラインプロセス				*/

/****************************************************************************/
/* 		mo_gptm	返却値	#define								STC???			*/
/****************************************************************************/
#define  MOPARER   -1L					/* パラメタエラー					*/
#define  MONOPTM   -2L					/* 電源制御タイマ未接続				*/
#define  MOCMMOD   -3L					/* パネルがコマンドモード			*/
#define  MOTMOUT   -4L					/* タイムアウト						*/
#define  MOBUGER   -5L					/* バッファ獲得失敗					*/

/****************************************************************************/
/* 		mo_gptm	種別	#define								STC666			*/
/****************************************************************************/
#define  MOPTMON  '0'					/* オンタイマ						*/
#define  MOPTMOFF '1'					/* オフタイマ						*/

/****************************************************************************/
/* 		mo_shgt			#define												*/
/****************************************************************************/
#define  MOIVSHLN  -2L					/* メモリサイズが負である			*/
#define  MOEMPSMT  -3L					/* TSMTがない						*/
#define  MOSMTFUL  -4L					/* TSMTに空きがない					*/

#define  MOCMSHM    0L					/* コモンメモリ						*/
#define  MOLMSHM    1L					/* ローカルメモリ					*/

/****************************************************************************/
/* 		mo_shat			#define												*/
/****************************************************************************/
#define  MOIVSHID  -1L					/* 既に解放済みである				*/

/*******************************************************************TD00*****/
/* 		mo_exct			#define										TD00	*/
/*******************************************************************TD00*****/
#define  MOSEFON    0L					/* オン						TD15	*/
#define  MOSEFOFF   1L					/* オフ						TD15	*/
#define  MOMODERR  -2L					/* オン／オフ以外			TD15	*/

/*******************************************************************TD00*****/
/* 		mo_dyck	返却値	#define										TD00	*/
/*******************************************************************TD00*****/
#define  MOCHKNG   -1L					/* 日付・時刻の値が不当		TD80	*/

/******************************************************	SSCY0074 start ******/
/* 		mo_tbok	返却値	#define												*/
/****************************************************************************/
#define  MOKINDNG  -1L					/* テーブル種別不当					*/
/*  #define  MONOMEM   -2L	プールバッファ確保エラー						*/
/*  MONOMEMはmo_excmの返却値で定義されているので、ここでは定義しない		*/

#define  MOTBLERR  -3L					/* テーブル片系故障発生				*/
#define  MONOLMT   -4L					/* TLMT未存在						*/
#define  MONODRV   -5L					/* システム状態エラー				*/
/*  #define  MOTIMOU   -6L	復旧完了待ちタイムアウト						*/
/*  MOTIMOUはmo_excmの返却値で定義されているので、ここでは定義しない		*/
										/* 					SSCY0074 end	*/

/****************************************************************************/
/*      reboot   終了機能  #define                              PRC-040-21  */
/****************************************************************************/
#define  MORLDCR   "reboot LINUX_DUMP_CMD_RESTART"
#define  MORLRCR   "reboot LINUX_REBOOT_CMD_RESTART"
#define  MORLDCH   "reboot LINUX_DUMP_CMD_HALT"
#define  MORLRCH   "reboot LINUX_REBOOT_CMD_HALT"

