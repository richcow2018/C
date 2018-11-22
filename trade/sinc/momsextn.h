/****************************************************************************/
/*	マスタスケジューラ外部領域宣言ヘッダ									*/
/*																			*/
/*		変更者 : 杉岡  克也				'96/02/07	---	ST3699				*/
/*		変更者 : 杉岡  克也				'96/03/11	---	ST4174				*/
/*		変更者 : 杉岡  克也				'96/04/05	---	ST4207				*/
/*		変更者 : 杉岡  克也				'96/04/22	---	CT1215(ST4306)		*/
/*		変更者 : 杉岡  克也				'96/05/08	---	CT1222(ST4317)		*/
/*		変更者 : Com'App 山口			'96/07/11	---	ST4451				*/
/*＜ソース修正者名＞				Com'App 高橋 					 		*/
/*＜ソース修正年月日及び修正ＩＤ＞	１９９７年  ６月　４日		ST4861   	*/
/*																			*/
/* ＜ソース修正者名＞				 営業店システム部　山口(KSP)			*/
/* ＜ソース修正年月日及び修正ＩＤ＞  １９９８年１１月１１日			ST5270	*/
/*	LICP終了待ち数管理のための変数"molidcnt"を追加した						*/
/*																			*/
/* ＜ソース修正者名＞               営業店システム部  山口(KSP)				*/
/* ＜ソース修正年月日及び修正ＩＤ＞ ２０００年１０月３１日  		ST5972	*/
/*   正常終了処理実行済み表示を追加した										*/
/****************************************************************************/
/****************************************************************************/
/* プロジェクト名　：                                                       */
/* プロセス名　　　：マスタスケジューラ                                     */
/* 改造番号　　　　：PRC-008-05                                             */
/* 改造内容　　　　：ＴＲＡＤＥエミュレートのシステム起動時初期化処理の     */
/*                   戻り値「テーブル格納用共用メモリID」追加               */
/* 改造日　　　　　：2002.10.30                                             */
/* 改造者　　　　　：supply Tanoue                                          */
/****************************************************************************/
/****************************************************************************/
/* 仕様変更番号	   : SSLA0039												*/
/* 修正内容		   : 終了処理中ダウン後再開始フラグの追加					*/
/* 修正日		   : 2003.06.30												*/
/* 修正者		   : supply Sugawara										*/
/****************************************************************************/

#include	"mochar.h"

extern	long	modtecnt;				/* 日付・時刻設定個数				*/
extern	PSCPSECT	pscparea;			/* ＰＳＥＣＴ						*/
extern	MOPSCPCB	*mopcbp;			/* ＭＯＰＣＢ先頭アドレス			*/
extern	TCOMPAT	*moadtp;				/* ＴＡＤＴ先頭アドレス				*/
extern	TCOMPAT	*moladtp;				/* ＴＡＤＴ先頭アドレス(LM)			*/
extern	TCOMPAT	*mosstp;				/* ＴＳＳＴ先頭アドレス				*/
extern	TSSTPSZ	*mosstkp;				/* ＴＳＳＴ個別部アドレス			*/
extern	TCOMPAT	*mocstp;				/* ＴＣＳＴ先頭アドレス				*/
extern	TCSTPSZ	*mocstkp;				/* ＴＣＳＴ個別部アドレス			*/
extern	TCOMPAT	*mopctp;				/* ＴＰＣＴ先頭アドレス				*/
extern	TPCTSUB	*mopctsp;				/* TPCTサブ共通部アドレス			*/	
extern	TPCTPSZ	*mopctkp;				/* ＴＰＣＴ個別部アドレス			*/	
extern	TCOMPAT	*mocmtp;				/* ＴＣＭＴ先頭アドレス				*/
extern	TCOMPAT	*motrtp;				/* ＴＴＲＴ先頭アドレス				*/
extern	TCOMPAT	*mobptp;				/* ＴＢＰＴ先頭アドレス				*/
extern	TCOMPAT	*mosrtp;				/* ＴＳＲＴ先頭アドレス				*/
extern	TSRTPSZ *mosrtkp;				/* ＴＳＲＴ個別部アドレス			*/
extern	TCOMPAT	*moputp;				/* ＴＰＵＴ先頭アドレス				*/
extern	TCOMPAT	*moshmp;				/* ＴＳＨＭ先頭アドレス				*/
extern	TCOMPAT *molmtp;				/* ＴＬＭＴ先頭アドレス				*/
extern	long	momsmb;					/* ＭＳメイルボックスID				*/
extern	long	mokkmb;					/* 系間監視メイルボックスID			*/
extern	long	moksmb;					/* 系間通信メイルボックスID			*/
extern	long	moermb;					/* ＳＭＰ通知用メイルボックスID		*/
extern	long	momrhkmb;				/* ＳＭＰ通知保留用メイルボックスID	*/
extern	long	modestms[16];			/* 相手系ＭＳ用メイルボックスID		*/
extern	long	modestkk[16];			/* 相手系系間監視用メイルボックスID	*/
extern	MOPINF	moorig;					/* 起動元プロセス情報				*/
extern	UCHR	montc;					/* 自ＮＴＣ番号						*/
extern	long	modpfid;				/* ファイル記述子					*/
extern	long	mordtbl[MOMSRDC];		/* MS内リクエスト識別子格納テーブル	*/
extern	UCHR	mordflg[MOMSRDC];		/* MS内リクエスト識別子要求フラグ	*/
extern	long	momspid;				/* ＭＳプロセス識別子				*/
extern	long	modpcod;				/* 表示不可時ダウンコード格納域		*/
extern	long	modpdtl;				/* 表示不可時詳細情報格納域			*/
extern	UCHR	momrinf;				/* ミラー同期要／不要情報			*/
extern	UCHR	momstmst;				/* 終了ステータス					*/
extern	UCHR	*mormgp;				/* メッセージ受信エリアポインタ		*/
extern	long	mormgl;					/* メッセージ受信エリアの長さ		*/
extern	UCHR	*mosmgp;				/* メッセージ送信エリアポインタ		*/
extern	long	mosmgl;					/* メッセージ送信エリアポインタ		*/
extern	UCHR	momsdvst;				/* 運転ステータス					*/
extern	UCHR	momsdvst2;				/* 運転ステータス			CT1222	*/
extern	UCHR	*morosmp;				/* ＴＲＡＤＥからのＳＭＰ通知		*/
extern	UCHR	modev;					/* 立ち上げ系区分					*/
extern	long	momode;					/* 自系プログラムモード				*/
extern	long	mopmode[16];			/* 相手系プログラムモード			*/
extern	UCHR	moschin;				/* 系切替要／不要情報				*/
extern	UCHR	mostart;				/* 開始区分							*/
extern	long	movtpbid;				/* ベクタテーブルプールバッファ識別子*/
extern	UCHR	modtl[4];				/* エラーメッセージＩＤ格納域		*/
extern	UCHR	mocrpnm[9];				/* プロセス識別名					*/
extern	TPCTPSZ	*mocrpct;				/* 生成プロセスＴＰＣＴ個別部		*/
extern	long	motrinf[4];				/* エラー詳細情報					*/
extern	UCHR	mocmid[9];				/* ＣＭ共用メモリ識別子				*/
extern	UCHR	mocmadd[9];				/* ＣＭ共用メモリ先頭アドレス		*/
extern	long	momsgflg;				/* メッセージ出力可能フラグ			*/
extern	long	monotpu;				/* Ｐｕ情報							*/
extern	long	mozintrc;				/* STC238							*/
extern	char	momdtbl[16][16];		/* プログラムモードチェックテーブル	*/
extern	UCHR	modate[15];				/* 現用系前回待避日付				*/
extern	UCHR	mochginf;				/* 切替現用系情報					*/
extern	SCHR	modatpnm[]; 			/* 日付時刻ファイルフルパス名		*/
extern	UCHR	moside;					/* 片系立ち上げ情報					*/
extern	UCHR	moform;					/* システム構成情報					*/
extern	UCHR	mocmdtbl[MOCMDNO*16];	/* コマンドファイル名テーブル		*/
extern	UCHR	mokinf[15][16];			/* 系切替情報テーブル				*/
extern	UCHR	mokno[2];				/* 開始トリガ						*/
extern	UCHR	motfmcnd[3];			/* テーブルファイル（正）の状態		*/
extern	UCHR	motfscnd[3];			/* テーブルファイル（副）の状態		*/
										/*				ST3431				*/
extern	UCHR	motl0fmcnd[3];			/* テーブルファイル（正）の状態(L0)	*/
extern	UCHR	motl0fscnd[3];			/* テーブルファイル（副）の状態(L0)	*/
extern	UCHR	motl1fmcnd[3];			/* テーブルファイル（正）の状態(L1)	*/
extern	UCHR	motl1fscnd[3];			/* テーブルファイル（副）の状態(L1)	*/
										/*				ST3431				*/
extern	UCHR	mosyserr1[9];			/* テーブルロードエラー情報(正)		*/
extern	UCHR	mosyserr2[9];			/* テーブルロードエラー情報(副)		*/
extern	UCHR	mol0syserr1[9];			/* テーブルロードエラー情報(L0正)	*/
extern	UCHR	mol0syserr2[9];			/* テーブルロードエラー情報(L0副)	*/
extern	UCHR	mol1syserr1[9];			/* テーブルロードエラー情報(L1正)	*/
extern	UCHR	mol1syserr2[9];			/* テーブルロードエラー情報(L1副)	*/
extern	UCHR	motfeflg;				/* テーブルロードエラーフラグ		*/
										/*				ST3431				*/
extern	UCHR	motl0feflg;				/* テーブルロードエラーフラグ(L0)	*/
extern	UCHR	motl1feflg;				/* テーブルロードエラーフラグ(L1)	*/
extern	UCHR	modsts;					/* ダウンステータス		CT0881		*/
extern	long	moutfinf;				/* 採用テーブルファイルＮｏ			*/
extern	long	mofeinf[2];				/* テーブルファイルエラー情報		*/
extern	long	mofidp[2];				/* ファイル記述子アドレスリスト		*/
extern	long	mofduse;				/* 採用ファイル記述子				*/
extern	long	mofcnd[2];				/* ファイル状態						*/
extern	long	lmfcnd[2];				/* ファイル状態				ST4207	*/
extern	long	motldrc;				/* テーブルロード返却値				*/
extern	long	morscno;				/* 資源番号							*/
extern	long	mosmpbid;				/* ＳＭＰシステムファイル用プールID	*/
extern	long	momsgbid;				/* ＳＭＰ通知用プールＩＤ			*/
extern	long	mokkpid;				/* 系間監視プロセスＩＤ				*/
extern	long	modrvmd;				/* ＡＰ運転モード					*/
extern	SCHR	*movctp;				/* ＴＶＣＴ先頭アドレス				*/
extern	SCHR	*molvctp;				/* ＴＶＣＴ先頭アドレス(LM)			*/
extern	SMPSYSF	*mosysp;				/* SMPシステムファイル先頭アドレス	*/
extern	MOTGSAM	*mosamp;				/* 立ち上げ同期通知先頭アドレス		*/
extern	MOTGMSG	*morosp;				/* ＴＲＡＤＥからの通知先頭アドレス	*/
extern	MTPLST	molist;					/* テーブルロードパラメタ			*/
extern	MTPLST	lmlist;					/* テーブルロードパラメタ(LM)		*/
extern	long	mocmmid;				/* CMテーブル共用メモリID(1)		*/
extern	long	mocmmad;				/* CMテーブルマッピングアドレス(1)	*/
extern	UCHR	mommno;					/* 自系装置番号						*/
extern	UCHR	moomno[16];				/* 相手系装置番号					*/
extern	long	moparmc;				/* パラメタ個数						*/

extern	long	molmparmc;				/* パラメタ個数(LM)					*/
extern	UCHR	modisflg;				/* Ｐｕ１プロセス完了フラグ			*/
extern	UCHR	mokcflg;				/* 系切替依頼フラグ					*/
extern	TCOMPAT	*moabpp;				/* ＴＡＢＰ先頭アドレス				*/
extern	UCHR	modapjflg;				/* JNL二重故障フラグ				*/
extern	UCHR	modaprflg;				/* RBI二重故障フラグ				*/
extern	UCHR	modapkflg;				/* KJ二重故障フラグ					*/
extern	char	*moparent[1024];		/* 起動パラメタエントリ				*/
extern	long	moridfast[16];			/* 孤立状態回復待ち					*/
										/* 		タイマリクエストIDテーブル	*/
extern	UCHR	mochbno;				/* 切替対象ブロック区分				*/
extern	char	moinit;					/* ＩＮＩＴ＿Ｓ発行中フラグ			*/
extern	char	moinitb[9];				/* ＩＮＩＴ＿Ｓ発行元プロセス識別名	*/
extern	UCHR	momtrm[4];				/* 障害通知端子情報テーブル			*/
extern	UCHR	momotrm[4];				/* 出力端子情報テーブル	CT1193		*/
extern	UCHR	moupstyp;				/* ＵＰＳタイプ情報					*/
extern	long	mopwwt;					/* 商用電源回復待ちタイマ値			*/
extern	long	mosmsmb;				/* サブＭＳメイルボックスＩＤ		*/
extern	TPCTPSZ *momgtptr;				/* ＭＳＧ制御個別部ポインタ			*/
extern	UCHR	mosystime[5];			/* システム立ち上げ所用時間			*/
extern	UCHR	morestime[5];			/* レスポンス待ち時間				*/
extern	long	modefpmd[16];			/* デフォルトプログラムモード		*/
extern	UCHR	moblckno;				/* 自系ブロック番号					*/
extern	short	mortmgno;				/* コマンド実行結果返却電文数		*/
extern	long	modispr;				/* 終了プロセス数					*/
extern	long	momrhflg;				/* 故障管理依頼Ｏｋフラグ			*/
extern	MSSTSYNC	mssync;				/* 立ち上げ同期制御表				*/
extern	long	motldflg;				/* テーブルロード済みフラグ			*/
extern	UCHR	mokkpn[48];				/* 系間監視プログラムファイル名		*/
extern	UCHR	mokkpi[8];				/* 系間監視プロセス名				*/
extern	UCHR	mosyctime[5];			/* 同期待ち時間						*/
extern	MTERRT	mterrtbl;				/* テーブルLOAD/SAVEエラー情報		*/
extern	MTERRT	mtertbcm;				/* テーブルLOAD/SAVE				*/
										/* 			エラー情報(CM)  CT1047	*/
extern	MTERRT	mtertblm;				/* テーブルLOAD/SAVE				*/
										/* 			エラー情報(LM)  CT1047	*/
extern  struct  terminf  termcod;		/* 終了情報							*/
extern	long	molmfidp[2];			/* ファイル記述子格納エリア			*/
extern	long	molpid;					/* LMベクタテーブル用バッファID		*/
extern	TLMTPSZ *molmtinp;				/* 自PuLM情報LMT個別部ポインタ		*/
extern	char	moosti[16];				/* ブロック状態情報					*/
extern	long	*mosyspbp;				/* SMPシステムファイル用			*/
										/* 			プールバッファアドレス	*/
extern	TCOMPAT	*movmtp;				/* TVMT先頭アドレス					*/
extern	TCOMPAT *mofmtp;				/* TFMT先頭アドレス					*/
extern	TCOMPAT *mowmtp;				/* TWMT先頭アドレス					*/
extern	UCHR	mosbmsflg;				/* 起動完了通知済みフラグ			*/
extern	TCMTPSZ	*moppcmt;				/* ＴＣＭＴ個別部ポインタ			*/
extern	long	mosmpkpmb;				/* SMP通知保留用メイルボックスID	*/
extern	TPCTPSZ	*mocprpct;				/* 生成プロセスTPCTエントリアドレス	*/
extern	long	motrybms;				/* 予備系終了依頼受信フラグ			*/
extern	long	moctmnt;				/* ＣＭテーブルマウントフラグ		*/
extern	long	moltmnt;				/* ＣＭテーブルマウントフラグ		*/
extern	short	moecmt;					/* ＴＣＭＴエントリ番号				*/
extern	long	mohsnsp;				/* HS両系プログラムモード不一致フラグ*/
extern	long	mooscprcd;				/* mo_crepでのoscrepr返却値 CT0597	*/
extern	long	mooscmdflg;				/* ＯＳコマンドフラグ	CT0597		*/
extern	short	momrmcnt;				/* 先行リカバリ起動数				*/
										/*						CT0881		*/
extern	UCHR	mospmfdk[32];			/* ＳＰＭ待避ファイルボリューム名	*/
extern	UCHR	mospmfdr[32];			/* ＳＰＭ待避ファイルディレクトリ名	*/
extern	UCHR	mospmfps[32];			/* ＳＰＭ待避ファイルフルパス名		*/
extern	long	momsld2rcd;				/* mr_msld2リターンコード			*/
extern	long	momsldrcd;				/* mr_msldリターンコード			*/
extern	long	mocdbeflg;				/* 代行系存在認識フラグ				*/
extern	long	moybwtime;				/* 予備系待ち時間			ST3589	*/
extern	long	moadwtime;				/* 相手系ダウン待ち時間		CT1193	*/
extern	long	moadwflg;				/* 相手系ダウン待ちフラグ	CT1193	*/
extern	UCHR	mospmflg;				/* 更新領域ログ処理済みフラグ ST3589*/
extern	UCHR	moadwcnui;				/* 相手系ダウン処理要／不要情報		*/
										/*			CT1193					*/
extern	UCHR	mosmadflg;				/* 立ち上げ同期時相手系				*/
										/*			ダウン確定フラグCT1193	*/
extern	UCHR	mosyflg;				/* 両系同時立ち上げフラグ	ST3800	*/
extern	char	mojrof;					/* ＪＮＬ再オープンフラグ	ST3699	*/
extern	long	moneflg;				/* 正常終了フラグ			ST4174	*/
#include	"msexmsg.h"					/* ＳＣＰメッセージ					*/
extern	char	movdaylm[6];			/* VCT日付(LM)				CT1215	*/
extern	long	movdayflg;				/* VCT日付フラグ			CT1215	*/
extern	char	momscmskb;				/* VCT開始区分(CM)			CT1222	*/
extern	char	momslmskb;				/* VCT開始区分(LM)			CT1222	*/

extern	char	momrsflg;				/* ミラー同期完了表示		ST4451	*/

extern	char	moicpflg;				/* ＩＣＰプロセス状態フラグ	ST4861	*/
extern	long	molidcnt;				/* ＬＩＣＰ終了待ち数		ST5270	*/

extern	long	motrfflg;				/* 正常終了実行済み表示		ST5972	*/
extern	long	moshmemid;				/* テーブル格納用共用メモリID			PRC-008-05 */
extern	long	mostendflg;				/* 終了処理中ダウン後再開始 SSLA0039*/

