/****************************************************************************/
/*	Ｐトレースログ情報取得用ｄｅｆｉｎｅ名	(1994.02.15)					*/
/****************************************************************************/

/****************************************/
/*	詳細情報define						*/
/****************************************/
#define	CMODE	1L						/* 生成モード						��*/
#define	RD		1L						/* 使用可能リクエスト識別子			*/
#define	EVENT	29L						/* 使用可能イベント番号				*/
#define	CODE	0x0800					/* アボートコード					*/
#define	DETAIL	0x6c666963				/* アボート詳細コード(lfic=6c666963)*/

/****************************************/
/*	返却値define						*/
/****************************************/
#define	MCLNORMAL	0L					/* 正常終了							*/
#define	MCLERPARM	-1L					/* パラメータエラー					*/
#define	MCLEREXS1	-2L					/* ファイル既存(ﾄﾚｰｽ抽出ﾌｧｲﾙ)		*/
#define	MCLEREXS2	-3L					/* ファイル既存(ﾄﾚｰｽ抽出ﾌｧｲﾙ以外)	*/
#define	MCLERGTBF	-4L					/* バッファ確保不可					*/
#define	MCLERDUPR	-5L					/* 二重発行エラー					*/
#define	MCLERIOER	-6L					/* ファイルＩ／Ｏエラー				*/
