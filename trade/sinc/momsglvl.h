/****************************************************************************/
/*	マスタスケジューラ外部領域定義ヘッダ									*/
/*																			*/
/*		変更者 : 杉岡  克也				'96/02/07	--- ST3699				*/
/*		変更者 : 杉岡  克也				'96/03/11	--- ST4174				*/
/*		変更者 : 杉岡  克也				'96/03/21	--- ST4194				*/
/*		変更者 : 杉岡  克也				'96/04/05	--- ST4207				*/
/*		変更者 : 杉岡  克也				'96/04/22	--- CT1215(ST4306)		*/
/*		変更者 : 杉岡  克也				'96/05/08	--- CT1222(ST4317)		*/
/*		変更者 : Com'App 山口			'96/07/11	--- ST4451				*/
/*＜ソース修正者名＞				Com'App 高橋 					 		*/
/*＜ソース修正年月日及び修正ＩＤ＞	１９９７年  ６月　４日		ST4861   	*/
/*																			*/
/* ＜ソース修正者名＞				 営業店システム部　山口(KSP)			*/
/* ＜ソース修正年月日及び修正ＩＤ＞  １９９８年１１月１１日			ST5270	*/
/*	LICP終了待ち数管理のための変数"molidcnt"を追加した						*/
/*																			*/
/* ＜ソース修正者名＞               営業店システム部  山口(KSP)             */
/* ＜ソース修正年月日及び修正ＩＤ＞ ２０００年１０月３１日          ST5972  */
/*   正常終了処理実行済み表示を追加した                                     */
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
/* 仕様変更番号    : SSLA0039												*/
/* 修正内容		   : 終了処理中ダウン後再開始フラグの追加				  	*/
/* 修正日		   : 2003.06.30												*/
/* 修正者		   : supply Sugawara										*/
/****************************************************************************/

#include	"mochar.h"

long	mosysdte[30][3];				/* 日付・時刻設定エリア				*/
long	modtecnt;						/* 日付・時刻設定個数				*/
TCOMPAT	*moadtp;						/* ＴＡＤＴ先頭アドレス				*/
TCOMPAT	*moladtp;						/* ＴＡＤＴ先頭アドレス(LM)			*/
TCOMPAT	*mosstp;						/* ＴＳＳＴ先頭アドレス				*/
TSSTPSZ	*mosstkp;						/* ＴＳＳＴ個別部アドレス			*/
TCOMPAT	*mocstp;						/* ＴＣＳＴ先頭アドレス				*/
TCSTPSZ	*mocstkp;						/* ＴＣＳＴ個別部アドレス			*/
TCOMPAT	*mopctp;						/* ＴＰＣＴ先頭アドレス				*/
TPCTSUB	*mopctsp;						/* TPCTサブ共通部アドレス			*/	
TPCTPSZ	*mopctkp;						/* ＴＰＣＴ個別部先頭アドレス		*/	
TCOMPAT	*mocmtp;						/* ＴＣＭＴ先頭アドレス				*/
TCOMPAT	*motrtp;						/* ＴＴＲＴ先頭アドレス				*/
TCOMPAT	*mobptp;						/* ＴＢＰＴ先頭アドレス				*/
TCOMPAT	*mosrtp;						/* ＴＳＲＴ先頭アドレス				*/
TSRTPSZ *mosrtkp;						/* ＴＳＲＴ個別部アドレス			*/
TCOMPAT	*moputp;						/* ＴＰＵＴ先頭アドレス				*/
TCOMPAT	*moshmp;						/* ＴＳＨＭ先頭アドレス				*/
TCOMPAT *molmtp;						/* ＴＬＭＴ先頭アドレス				*/
long	momsmb;							/* ＭＳメイルボックスＩＤ			*/
long	mokkmb;							/* 系間監視メイルボックスＩＤ		*/
long	moksmb;							/* 系間通信メイルボックスＩＤ		*/
long	moermb;							/* ＳＭＰ通知用メイルボックスＩＤ	*/
long	momrhkmb;						/* ＳＭＰ通知保留用ﾒｲﾙﾎﾞｯｸｽＩＤ		*/
long	modestms[16];					/* 相手系ＭＳ用メイルボックスＩＤ	*/
long	modestkk[16];					/* 相手系系間監視用メイルボックスＩＤ*/
MOPINF	moorig;							/* 起動元プロセス情報				*/
UCHR	montc;							/* 自ＮＴＣ番号						*/
long	modpfid;						/* ファイル記述子					*/
long	mordtbl[MOMSRDC];				/* ＭＳ内ﾘｸｴｽﾄ識別子格納テーブル	*/
UCHR	mordflg[MOMSRDC];				/* ＭＳ内ﾘｸｴｽﾄ識別子要求フラグ		*/
long	momspid;						/* ＭＳプロセス識別子				*/
long	modpcod;						/* 表示不可時ダウンコード格納域		*/
long	modpdtl;						/* 表示不可時詳細情報格納域			*/
long	modispr;						/* 終了プロセス数					*/
UCHR	momrinf;						/* ミラー同期要／不要情報			*/
UCHR	momstmst;						/* 終了ステータス					*/
UCHR	*mormgp;						/* メッセージ受信エリアポインタ		*/
long	mormgl;							/* メッセージ受信エリアの長さ		*/
UCHR	*mosmgp;						/* メッセージ送信エリアポインタ		*/
long	mosmgl;							/* メッセージ送信エリアポインタ		*/
UCHR	momsdvst;						/* 運転ステータス					*/
UCHR	momsdvst2;						/* 運転ステータス			CT1223	*/
UCHR	*morosmp;						/* ＴＲＡＤＥからのＳＭＰ通知		*/
UCHR	modev;							/* 立ち上げ系区分					*/
long	momode;							/* 自系プログラムモード				*/
long	mopmode[16];					/* 相手系プログラムモード			*/
UCHR	moschin;						/* 系切替要／不要情報				*/
UCHR	mostart;						/* 開始区分							*/
long	movtpbid;						/* ベクタテーブルプールバッファ識別子*/
UCHR	modtl[4];						/* エラーメッセージＩＤ格納域		*/
UCHR	mocrpnm[9];						/* プロセス識別名					*/
TPCTPSZ	*mocrpct;						/* 生成プロセスＴＰＣＴ個別部		*/
long	motrinf[4];						/* エラー詳細情報					*/
UCHR	mocmid[9];						/* ＣＭ共用メモリ識別子				*/
UCHR	mocmadd[9];						/* ＣＭ共用メモリ先頭アドレス		*/
long	momsgflg;						/* メッセージ出力可能フラグ			*/
long	monotpu;						/* Ｐｕ情報							*/
long	mozintrc;						/* STC238							*/
char	momdtbl[16][16];				/* プログラムモードチェックテーブル	*/
UCHR	modate[15];						/* 現用系前回待避日付				*/
UCHR	mochginf;						/* 切替現用系情報					*/
SCHR	modatpnm[] = "/mosysdte"; 		/* 日付時刻ファイルフルパス名		*/
UCHR	moside;							/* 片系立ち上げ情報					*/
UCHR	moform;							/* システム構成情報					*/
UCHR	mocmdtbl[MOCMDNO*16];			/* コマンドファイル名テーブル		*/
UCHR	mokinf[15][16];					/* 系切替情報テーブル				*/
UCHR	mokno[2];						/* 開始トリガ						*/
UCHR	motfmcnd[3];					/* テーブルファイル（正）の状態		*/
UCHR	motfscnd[3];					/* テーブルファイル（副）の状態		*/
										/*				ST3431				*/
UCHR	motl0fmcnd[3];					/* テーブルファイル（正）の状態(L0)	*/
UCHR	motl0fscnd[3];					/* テーブルファイル（副）の状態(L0)	*/
UCHR	motl1fmcnd[3];					/* テーブルファイル（正）の状態(L1)	*/
UCHR	motl1fscnd[3];					/* テーブルファイル（副）の状態(L1)	*/
										/*				ST3431				*/
UCHR	mosyserr1[9];					/* テーブルロードエラー情報(CM正)	*/
UCHR	mosyserr2[9];					/* テーブルロードエラー情報(CM副)	*/
UCHR	mol0syserr1[9];					/* テーブルロードエラー情報(L0正)	*/
UCHR	mol0syserr2[9];					/* テーブルロードエラー情報(L0副)	*/
UCHR	mol1syserr1[9];					/* テーブルロードエラー情報(L1正)	*/
UCHR	mol1syserr2[9];					/* テーブルロードエラー情報(L1副)	*/
UCHR	motfeflg;						/* テーブルロードエラーフラグ		*/
										/*				ST3431				*/
UCHR	motl0feflg;						/* テーブルロードエラーフラグ(L0)	*/
UCHR	motl1feflg;						/* テーブルロードエラーフラグ(L1)	*/
UCHR	modsts;							/* ダウンステータス		CT0881		*/
long	moutfinf;						/* 採用テーブルファイルＮｏ			*/
long	mofeinf[2];						/* テーブルファイルエラー情報		*/
long	mofidp[2];						/* ファイル記述子アドレスリスト		*/
long	mofduse;						/* 採用ファイル記述子				*/
long	mofcnd[2];						/* ファイル状態						*/
long	lmfcnd[2];						/* 							ST4207	*/
long	motldrc;						/* テーブルロード返却値				*/
long	morscno;						/* 資源番号							*/
long	mosmpbid;						/* ＳＭＰシステムファイル用プールＩＤ*/
long	momsgbid;						/* ＳＭＰ通知用プールＩＤ			*/
long	mokkpid;						/* 系間監視プロセスＩＤ				*/
long	modrvmd;						/* ＡＰ運転モード					*/
SCHR	*movctp;						/* ＴＶＣＴ先頭アドレス				*/
SCHR	*molvctp;						/* ＴＶＣＴ先頭アドレス(LM)			*/
SMPSYSF	*mosysp;						/* ＳＭＰシステムファイル先頭アドレス*/
MOTGSAM	*mosamp;						/* 立ち上げ同期通知先頭アドレス		*/
MOTGMSG	*morosp;						/* ＴＲＡＤＥからの通知先頭アドレス	*/
MTPLST	molist;							/* テーブルロードパラメタ			*/
MTPLST	lmlist;							/* テーブルロードパラメタ(LM)		*/
MTERRT	mtertbcm;						/* ﾃｰﾌﾞﾙLOAD/SAVEｴﾗｰ情報(CM)  CT1047*/
MTERRT	mtertblm;						/* ﾃｰﾌﾞﾙLOAD/SAVEｴﾗｰ情報(LM)  CT1047*/
long	mocmmid;						/* ＣＭテーブル共用メモリＩＤ（１）	*/
long	mocmmad;						/* ＣＭテーブルﾏｯﾋﾟﾝｸﾞｱﾄﾞﾚｽ（１）	*/
UCHR	mommno;							/* 自系装置番号						*/
UCHR	moomno[16];						/* 相手系装置番号					*/
long	moparmc;						/* パラメタ個数						*/

long	molmparmc;						/* パラメタ個数(LM)					*/
UCHR	modisflg;						/* Ｐｕ１プロセス完了フラグ			*/
UCHR	mokcflg;						/* 系切替依頼フラグ					*/
TCOMPAT	*moabpp;						/* ＴＡＢＰ先頭アドレス				*/
UCHR	modapjflg;						/* JNL二重故障フラグ				*/
UCHR	modaprflg;						/* RBI二重故障フラグ				*/
UCHR	modapkflg;						/* KJ二重故障フラグ					*/
char	*moparent[1024];				/* 起動パラメタエントリ				*/
long	moridfast[16];					/* 孤立状態回復待ちﾀｲﾏﾘｸｴｽﾄIDﾃｰﾌﾞﾙ	*/
UCHR	mochbno;						/* 切替対象ブロック区分				*/
char	moinit;							/* ＩＮＩＴ＿Ｓ発行中フラグ			*/
char	moinitb[9];						/* ＩＮＩＴ＿Ｓ発行元プロセス識別名	*/
UCHR	momtrm[4];						/* 障害通知端子情報テーブル			*/
UCHR	momotrm[4];						/* 出力端子情報ﾃｰﾌﾞﾙ	CT1193		*/
UCHR	moupstyp;						/* ＵＰＳタイプ情報					*/
long	mopwwt;							/* 商用電源回復待ちタイマ値			*/
long	mosmsmb;						/* サブＭＳメイルボックスＩＤ		*/
TPCTPSZ	*momgtptr;						/* ＭＳＧ制御個別部ポインタ			*/
UCHR	mosystime[5];					/* システム立ち上げ所用時間			*/
UCHR	morestime[5];					/* レスポンス待ち時間				*/
long	modefpmd[16];					/* デフォルトプログラムモード		*/
UCHR	moblckno;						/* 自系ブロック番号					*/
short	mortmgno;						/* コマンド実行結果返却電文数		*/
long	modispr;						/* 終了プロセス数					*/
long	momrhflg;						/* 故障管理依頼ＯＫフラグ			*/
MSSTSYNC	mssync;						/* 立ち上げ同期制御表				*/
long	motldflg;						/* テーブルロード済みﾌﾗｸﾞ			*/
UCHR	mokkpn[48];						/* 系間監視プログラムファイル名		*/
UCHR	mokkpi[8];						/* 系間監視プロセス名				*/
UCHR	mosyctime[5];					/* 同期待ち時間						*/
long	molmfidp[2];					/* ﾌｧｲﾙ記述子格納エリア				*/
long	molpid;							/* LMﾍﾞｸﾀﾃｰﾌﾞﾙ用ﾊﾞｯﾌｧID				*/
TLMTPSZ *molmtinp;						/* 自PuLM情報LMT個別部ポインタ		*/
char	moosti[16];						/* ﾌﾞﾛｯｸ状態情報					*/
long	*mosyspbp;						/* SMPｼｽﾃﾑﾌｧｲﾙ用ﾌﾟｰﾙﾊﾞｯﾌｧｱﾄﾞﾚｽ		*/
TCOMPAT *movmtp;						/* TVMT先頭ｱﾄﾞﾚｽ					*/
TCOMPAT *mofmtp;						/* TFMT先頭ｱﾄﾞﾚｽ					*/
TCOMPAT *mowmtp;						/* TWMT先頭ｱﾄﾞﾚｽ					*/
UCHR	mosbmsflg;						/* 起動完了通知済みフラグ			*/
long	mosmpkpmb;						/*	SMP通知保留用ﾒｲﾙﾎﾞｯｸｽID			*/
TPCTPSZ	*mocprpct;						/* 生成ﾌﾟﾛｾｽTPCTｴﾝﾄﾘｱﾄﾞﾚｽ			*/
long	motrybms;						/* 予備系終了依頼受信フラグ			*/
long	moctmnt;						/* ＣＭテーブルマウントフラグ		*/
long	moltmnt;						/* ＬＭテーブルマウントフラグ		*/
short	moecmt;							/* ＴＣＭＴエントリ番号				*/
long	mohsnsp;						/* ﾎｯﾄｽﾀﾝﾊﾞｲ両系ﾌﾟﾛｸﾞﾗﾑﾓｰﾄﾞ不一致ﾌﾗｸﾞ*/
long	mooscprcd;						/* mo_crepでのoscrepr返却値 CT0597	*/
long	mooscmdflg;						/* ＯＳコマンドフラグ	CT0597		*/
short	momrmcnt;						/* 先行リカバリ起動数				*/
										/*						CT0881		*/
UCHR	mospmfdk[32];					/* ＳＰＭ待避ﾌｧｲﾙﾎﾞﾘｭｰﾑ名			*/
UCHR	mospmfdr[32];					/* ＳＰＭ待避ﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ名			*/
UCHR	mospmfps[32];					/* ＳＰＭ待避ﾌｧｲﾙﾌﾙﾊﾟｽ名			*/
long	momsld2rcd;						/* mr_msld2リターンコード			*/
long	momsldrcd;						/* mr_msldリターンコード			*/
long	mocdbeflg;						/* 代行系存在認識フラグ				*/
long	moybwtime;						/* 予備系待ち時間	ST3589			*/
long	moadwtime;						/* 相手系ﾀﾞｳﾝ待ち時間	CT1193		*/
long	moadwflg;						/* 相手系ﾀﾞｳﾝ待ちフラグ	CT1193		*/
UCHR	mospmflg;						/* 更新領域ログ処理済みフラグ ST3589*/
UCHR	moadwcnui;						/* 相手系ダウン処理要／不要情報		*/
										/*			CT1193					*/
UCHR	mosmadflg;						/* 立ち上げ同期時相手系ﾀﾞｳﾝ確定ﾌﾗｸﾞ	*/
										/*			CT1193					*/
UCHR	mosyflg;						/* 両系同時立ち上げフラグ	ST3800	*/
char	mojrof;							/* ＪＮＬ再オープンフラグ	ST3699	*/
long	moneflg;						/* 正常終了フラグ			ST4174	*/
										/* mspcmsg.h削除			ST4194	*/
char	movdaylm[6];					/* VCT日付(LM)				CT1215	*/
long	movdayflg;						/* VCT日付ﾌﾗｸﾞ				CT1215	*/
char	momscmskb;						/* VCT開始区分(CM)			CT1222	*/
char	momslmskb;						/* VCT開始区分(LM)			CT1222	*/

char	momrsflg;						/* ミラー同期完了表示		ST4451	*/

char	moicpflg;						/* ＩＣＰプロセス状態フラグ	ST4861	*/
long	molidcnt;						/* ＬＩＣＰ終了待ち数		ST5270	*/

long	motrfflg;						/* 正常終了実行済み表示		ST5972	*/
										/* テーブル退避終了後に現用系ダウン	*/
										/* したことにより正常終了処理を既に	*/
										/* 実行した事を示す					*/
long	moshmemid;						/* テーブル格納用共用メモリID	PRC-008-05 */
long	mostendflg;						/* 終了処理中ダウン後再開始 SSLA0039*/

