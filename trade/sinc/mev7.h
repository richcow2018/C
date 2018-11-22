/************************************************************************************************/
/*	著作権	２００２																			*/
/*			  株式会社ＮＴＴデータ																*/
/*				金融ビジネス事業本部															*/
/*																								*/
/*																								*/
/*	収容物	ＬＡＬａ−ＳＭＰシステム	V7通信用定義											*/
/************************************************************************************************/
/* ＜対象業務名＞					 通信制御													*/
/* ＜対象業務ＩＤ＞ 				 ＥＤＰ（ＨＣＰ−Ｓ［Ｖ７］）								*/
/* ＜サービス項目名＞				 ＤＣＳインタフェース										*/
/* ＜サービス項目ＩＤ＞ 			 															*/
/* ＜モジュール名＞					 															*/
/* ＜モジュールＩＤ＞				 															*/
/* ＜モジュール通番＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜適用機種名＞					 汎用サーバ													*/
/* ＜適用ＯＳ＞ 					 Ｌｉｎｕｘ 												*/
/* ＜開発環境＞ 					 ＲＨＡＳ２．１												*/
/* ＜記述言語＞ 					 Ｃ言語 													*/
/* ＜モジュール形態＞				 関数														*/
/* ＜機能区分＞ 																				*/
/* ＜対象データ＞																				*/
/* ＜工程・階層区分＞																			*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発システム名＞				 ＸＸＸ−ＳＭＰシステム 									*/
/* ＜開発システム番号＞ 			 ＰＰ４０Ｂ００１２２０										*/
/*----------------------------------------------------------------------------------------------*/
/* ＜開発担当名＞					 ＣＢ事ビジネス企画担当(メーカ：サプライ)					*/
/* ＜電話番号＞ 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ＜設計者名＞ 					 ＣＢ事ビジネス企画担当										*/
/* ＜設計年月日＞					 ２００２年 １１月０８日 									*/
/* ＜設計修正者名＞ 																			*/
/* ＜設計修正年月日及び修正ＩＤ＞																*/
/*----------------------------------------------------------------------------------------------*/
/* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカ:サプライ)					*/
/* ＜ソース作成年月日＞ 			 ２００２年 １１月０８日 									*/
/* ＜ソース修正者＞                  ＣＢ事ビジネス企画担当(メーカ:サプライ佐伯)                */
/* ＜ソース正年月日及び修正ＩＤ＞    ２００３年　　７月１８日                                   */
/*                                   故障処理票（ＴＢＣＳ０２２９）                         M01 */
/*                                     立ち上げ時刻を追加                                       */
/*----------------------------------------------------------------------------------------------*/
/* ＜入出力データ構造＞ 																		*/
/* ＜制限事項＞ 																				*/
/*	   特になし 																				*/
/* ＜使用外部モジュールＩＤ＞																	*/
/* ＜呼出元のモジュールＩＤ＞																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** 標準ヘッダ・ファイル ******************************************/
#include	<stdio.h>								// 標準入出力関数

/***************************** 利用者作成ヘッダ・ファイル ***************************************/
#include	<dcs_lib.h>								// DCSライブラリ定義

/*********************************** ＤＥＦＩＮＥ部 *********************************************/
// フラグ設定
#define V7FLGOFF	0x00							// フラグ設定：OFF
#define V7FLGON		0x01							// フラグ設定：ON
// データ種別
#define V7DATFST	0x01							// 通知種別：FIRST
#define V7DATMDL	0x02							// 通知種別：MIDDLE
#define V7DATLST	0x03							// 通知種別：LAST
#define V7DATONL	0x00							// 通知種別：ONLY
#define	V7DATNON	0xFF							// 通知種別：無し
// 端末タイプ
#define V7TMT_HOST	0x00							// 端末タイプ：ホスト主導
#define V7TMT_TM	0x01							// 端末タイプ：端末主導

// 切断通知種別
#define V7TRMCLR	0x10							// CLEAR通知
#define V7TRMCLS	0x20							// 閉局通知
#define V7TRMNRS	0x21							// 閉局通知（−ＲＳＰ受信）
#define V7TRMHRD	0x31							// パス異常（ハードエラー）
#define V7TRMSES	0x32							// パス異常（セッションエラー）
// パス状態
#define V7PSCIDL	0x01							// 閉局-アイドル
#define V7PSCOPN	0x02							// 閉局-開局処理中
#define V7PSCROP	0x03							// 閉局-再開局処理中
#define V7PSOIDL	0x11							// 開局-アイドル
#define V7PSOCLS	0x12							// 開局-閉局処理中
#define V7PSODCN	0x13							// 開局-切断中
#define V7PSORCN	0x14							// 開局-再接続中
#define V7PSOTCN	0x15							// 開局-回線制御待ち
#define V7PSOCLR	0x16							// 開局-RCLEAR/SCLEAR待ち
#define V7PSORW		0x17							// 開局-READ/WRITE要求中
#define V7PSORED	0x18							// 開局-READ要求中
#define V7PSOWRT	0x19							// 開局-WRITE要求中
#define	V7PSERR		0x20							// 動作不能

// ホスト論理パスチェック返却値定義
#define V7TRUE		0x00							// ホスト論理パス
#define V7FALSE		0x01							// ホスト論理パス以外
#define V7ERROR		0xFF							// NG

// EDTデータ状態定義
#define	V7EDT_NON	0x00							// 未送信
#define	V7EDT_ING	0x10							// 送信中（dcswrite済み）
#define	V7EDT_WAIT	0x11							// 送信完了通知待ち
#define	V7EDT_WEND	0x20							// WRITE 終了

// DCSインタフェース定義
#define	V7HTBLNUM	256								// １プロセスでのDCS接続数MAX
#define	V7DCSNAME	"u_dcs"							// DCサービス名（先頭5文字）

// コマンドコード
#define	V7MECOPN	0x01							// me_copn
#define	V7MECCLS	0x02							// me_ccls
#define	V7MERSTA	0x07							// me_rsta
#define	V7MECEDT	0x04							// me_cedt
#define	V7METRED	0x03							// me_tred
#define	V7METCNT	0x05							// me_tcnt
#define	V7METCAN	0x06							// me_tcan

//異常要因
#define	V7ERR_HARDNG	0x0101						// ハードエラー

#define	V7ERR_CONLOST	0x0202						// コネクション切断

#define	V7ERR_HILULOST	0x0301						// ＬＵ上位パス切断
#define	V7ERR_NRLULOST	0x0302						// ＬＵパス切断
#define	V7ERR_LURESET	0x0303						// ＬＵパスリセット

#define V7ERR_NRESP		0x0401						// −ＲＳＰ受信
#define V7ERR_READBLK	0x0412						// ブロック順序性エラー
#define V7ERR_CANCEL	0x0413						// ＣＭＤ９受信

#define V7ERR_STSNG		0x0501						// ステータスエラー
#define V7ERR_NOOPN		0x0502						// 論理パス未オープン
#define V7ERR_INOPN		0x0503						// 論理パスオープン処理中
#define V7ERR_INCLS		0x0504						// 論理パスクローズ中
#define	V7ERR_PARAMNG	0x0506						// パラメータエラー
#define V7ERR_FINOPN	0x0505						// 論理パスオープン済み
#define V7ERR_DOUBLE	0x0507						// ２重発行
#define V7ERR_SENDBLK	0x0508						// ブロックエラー
#define V7ERR_SENDLEN	0x0509						// データ長エラー
#define V7ERR_INRSTA	0x050A						// リスタート処理中
#define V7ERR_DCSNG		0x050C						// ＤＣＳエラー

#define V7ERR_CANREC	0x0601						// キャンセルによる回収
#define V7ERR_CLOSEREC	0x0602						// クローズによる回収
#define V7ERR_SSENDREC	0x0603						// 送信中止による回収
#define V7ERR_RECVREC	0x0604						// 受信中止による回収
	
#define V7ERR_CANNG		0x0701						// キャンセル失敗
#define V7ERR_SSENDNG	0x0702						// 送信中止失敗
#define V7ERR_SREADNG	0x0703						// 受信中止失敗

#define V7ERR_ROGINNG	0x0901						// ログイン否定

/************************************ 構造体定義部 **********************************************/
// COPN要求コマンド領域
typedef struct	mev7copcmd {
	char		cmdcode;							// コマンドコード
	char		dummy1[3];							// 予備
	char		lukind;								// LU種別
	char		tmtype;								// 端末タイプ
	char		dummy2[2];							// 予備
	char		dummy3[4];							// 予備
	short		logonsize;							// ログオン情報サイズ
	char		logoninfo[256];						// ログオン情報
}MEV7COPCMD;

// CCLS要求コマンド領域（me_cclsに要求コマンドは無いが、情報保持の為に使用）
typedef struct	mev7cclcmd {
	char		cmdcode;							// コマンドコード
	char		dummy1[3];							// 予備
}MEV7CCLCMD;

// RSTA要求コマンド領域（me_rstaに要求コマンドは無いが、情報保持の為にme_copnと同一構造を使用）
typedef struct	mev7rstcmd {
	char		cmdcode;							// コマンドコード
	char		dummy1[3];							// 予備
	char		lukind;								// LU種別
	char		tmtype;								// 端末タイプ
	char		dummy2[2];							// 予備
	char		dummy3[4];							// 予備
	short		logonsize;							// ログオン情報サイズ
	char		logoninfo[256];						// ログオン情報
}MEV7RSTCMD;

// EDT要求コマンド領域
typedef struct	mev7edtcmd {
	char		cmdcode;							// コマンドコード
	char		dummy1[3];							// 予備
	short		blocknum;							// ブロック数
	short		blocklen;							// 送信データ長
	char		blockkind;							// ブロック種別
	char		dummy2[3];							// 予備
	char		*dataadr;							// データ格納域アドレス
}MEV7EDTCMD;

// TRED要求コマンド領域（me_tredに要求コマンドは無いが、情報保持の為に使用）
typedef struct	mev7trecmd {
	char		cmdcode;							// コマンドコード
	char		dummy1[3];							// 予備
}MEV7TRECMD;

// TCNT要求コマンド領域
typedef struct	mev7tcncmd {
	char		cmdcode;							// コマンドコード
	char		pcode;								// 処理コード
	short		cause;								// 理由
}MEV7TCNCMD;

// TCAN要求コマンド領域
typedef struct	mev7tcacmd {
	char		cmdcode;							// コマンドコード
	char		pcode;								// 処理コード
	char		dummy1[2];							// 予備
}MEV7TCACMD;

//**************************************************//
// DCS通知情報
typedef struct	mev7dcscom {
	char		mkcd[4];							// MKコード
	long		rcvsize;							// 受信データサイズ
}MEV7DCSCOM;

// DCSメッセージ域共通情報
typedef struct	mev7rescom {
	char		mkcd[4];							// MKコード
	short		cmdsize;							// 応答コマンド領域サイズ
	short		pathno;								// 論理パス番号
	unsigned long s_time;							// 立ち上時間	M01
	long		dummy1;								// 予備
}MEV7RESCOM;

// 応答コマンド領域 （共通)
typedef struct	mev7resall {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
}MEV7RESALL;

// 応答コマンド領域 （me_copn)
typedef struct	mev7rescop {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
}MEV7RESCOP;

// 応答コマンド領域 （me_ccls)
typedef struct	mev7resccl {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
}MEV7RESCCL;

// 応答コマンド領域 （me_rsta)
typedef struct	mev7resrst {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
}MEV7RESRST;

// 応答コマンド領域 （me_cedt)
typedef struct	mev7resced {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
}MEV7RESCED;

// 応答コマンド領域 （me_tred)
typedef struct	mev7resred {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
	short		blocknum;							// ブロック数
	short		blocklen;							// ブロック長
	char		blockkind;							// ブロック種別
	char		dummy1[3];							// 予備
	char		*dataadr;							// データ格納域アドレス
}MEV7RESRED;

// 応答コマンド領域 （me_tcnt)
typedef struct	mev7restcn {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
	short		pcode;								// 処理コード
	char		dummy1[2];							// 予備
}MEV7RESTCN;

// 応答コマンド領域 （me_tcan)
typedef struct	mev7restca {
	char		cmdcode;							// コマンドコード
	char		cmpcode;							// 完了コード
	short		errfact;							// 異常要因
	short		pcode;								// 処理コード
	char		dummy1[2];							// 予備
}MEV7RESTCA;

// 応答コマンド領域 （全体）
typedef union	mev7rescmd {
	MEV7RESALL	resall;								// 応答コマンド領域 （共通)
	MEV7RESCOP	rescop;								// 応答コマンド領域 （me_copn)
	MEV7RESCCL	resccl;								// 応答コマンド領域 （me_ccls)
	MEV7RESRST	resrst;								// 応答コマンド領域 （me_rsta)
	MEV7RESCED	resced;								// 応答コマンド領域 （me_cedt)
	MEV7RESRED	resred;								// 応答コマンド領域 （me_tred)
	MEV7RESTCN	restcn;								// 応答コマンド領域 （me_tcnt)
	MEV7RESTCA	restca;								// 応答コマンド領域 （me_tcan)
}MEV7RESCMD;

// ＤＣＳメッセージ領域（完了要求通知）
typedef struct	mev7dcsmsg {
	MEV7RESCOM	rescom;								// DCSメッセージ共通域
	MEV7RESCMD	rescmd;								// 応答コマンド領域
}MEV7DCSMSG;

// 送信データエリア
typedef	struct	mev7senddd {
	void		*nextadr;							// 次データアドレス
	long		status;								// データ状態
	MDHIKYO		*sdata;								// 送信データ
	MEV7DCSMSG	*dcsmsg;							// WRITE結果保持アドレス
}	MEV7SENDD;


//**************************************************//

// ホスト通信管理TBL共通部
typedef struct	mev7hkcm{
	char		tblname[4];							// テーブル名（TV7T）
	long		message;							// メッセージキュー
	BlpDac_PDCB	dcbaddr;							// ｄｃｂアドレス
	long		kbt_num;							// 使用中個別部数
	long		open_rtimer;						// 再オープンリトライタイマ(ミリ)
	unsigned long s_time;							// 立ち上げ時時刻		M01
	long		dummy1[2];							// 予備
}MEV7HKCM;

typedef struct	mev7hkbt{
	char		dcsname[32];						// DCサービス名

	char		pathsts;							// パス状態
	char		reserve1;							// 予備
	short		pathno;								// 論理パス番号

	char		trmkind;							// 切断通知種別
	unsigned char datkind;							// 通知種別
	char		sendkind;							// 送信種別
	char		reserve2;							// 予備

	char		rdprcflg;							// リード処理中フラグ
	char		sdcmpflg;							// 送信完了通知待ちフラグ
	char		edprstflg;							// 再開始フラグ
	char		reserve3;							// 予備

	long		timer_rd;							// リトライタイマのrd（未発行時は0）

	char		dcsptnm[12];						// 論理パス識別名

	DCSLib_PCB*	pcbaddr;							// ｐｃｄアドレス

	long		datseqno;							// シーケンス番号
	long		reserve4[3];						// 予備

	MEV7COPCMD	copncmd;							// me_copn 要求コマンド情報
	MEV7CCLCMD	cclscmd;							// me_ccls 要求コマンド情報
	MEV7RSTCMD	rstacmd;							// me_rsta 要求コマンド情報
	MEV7TRECMD	tredcmd;							// me_tred 要求コマンド情報
	MEV7TCNCMD	tcntcmd	;							// me_tcnt 要求コマンド情報
	MEV7TCACMD	tcancmd;							// me_tcan 要求コマンド情報
	MEV7DCSMSG*	rcvdtinf;							// 受信データ保持情報アドレス
	MEV7SENDD*	edtdtinf[2];						// cedt保持情報アドレス
}MEV7HKBT;

typedef struct mev7kinf{
	MEV7HKBT	*adr;
}MEV7KINF;

// ホスト通信管理TBL
typedef struct mev7htkt{
	MEV7HKCM	hstknkcm;							// ホスト通信管理TBL共通部
	MEV7KINF	hstknkbt[V7HTBLNUM];				// ホスト通信管理TBL個別部
}MEV7HTKT;

// V7通信用PSECT
typedef	struct	mev7psect{
	MEV7HTKT	*mev7htkt;							// ホスト通信管理テーブル先頭アドレス
	long		dummy[3];							// 予備
} MEV7PSECT;
