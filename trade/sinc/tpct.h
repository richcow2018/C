/*--------------------------------------------------------------------------*/
/*＜対象業務名＞					運転管理業務							*/
/*＜対象業務ＩＤ＞															*/
/*＜サービス項目名＞														*/
/*＜サービス項目ＩＤ＞														*/
/*＜モジュール名＞					ＴＰＣＴテーブル						*/
/*＜モジュールＩＤ＞														*/
/*＜モジュール通番＞														*/
/*--------------------------------------------------------------------------*/
/*＜適用機種＞						ＡＣＥ									*/
/*＜適用ＯＳ＞						ＴＲＡＤＥ								*/
/*＜開発環境＞						ＳＵＮ　ＳＰＡＲＣ−ＩＰＸ				*/
/*＜記述言語＞						Ｃ言語									*/
/*＜モジュール形態＞				構造体									*/
/*＜機能区分＞																*/
/*＜対象データ＞															*/
/*＜工程・階層区分＞														*/
/*--------------------------------------------------------------------------*/
/*＜開発システム名＞				ＡＣＥ−ＳＭＰシステム					*/
/*＜開発システム番号＞				５７２６０１４０２１００				*/
/*--------------------------------------------------------------------------*/
/*＜開発担当名＞					営業店システム担当						*/
/*＜電話番号＞						169-3537(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/*＜設計者名＞						ＴＤＣ　赤塚　一元						*/
/*＜設計年月日＞					１９９３年１１月　８日					*/
/*＜設計修正者名＞															*/
/*＜設計修正年月日及び修正ＩＤ＞											*/
/*--------------------------------------------------------------------------*/
/*＜ソース作成者名＞				ＴＤＣ　前沢　晃						*/
/*＜ソース作成年月日＞				１９９３年１１月１０日					*/
/*＜ソース修正者名＞				ＴＤＣ　赤塚　一元						*/
/*＜ソース修正年月日及び修正ＩＤ＞											*/
/*									'94/05/10					ST0079		*/
/*									'94/12/13					ST1223		*/
/*＜ソース修正者名＞				ＮＴＴ−Ｄ　宮脇　伸					*/
/*＜ソース修正年月日及び修正ＩＤ＞  '95/03/13					SM01		*/
/*＜ソース修正者名＞                Com'App 高橋							*/
/*＜ソース修正年月日及び修正ＩＤ＞  １９９７年  ６月１１日		SSCY0197 	*/
/*	（プロセスキャンセル追加による  キャンセル不可フラグ追加）				*/
/*--------------------------------------------------------------------------*/
/*＜見積ステップ＞															*/
/*--------------------------------------------------------------------------*/
/*＜機能概要＞																*/
/*--------------------------------------------------------------------------*/
/*＜呼出形式＞																*/
/*＜仮引数＞																*/
/*＜返却値＞																*/
/*--------------------------------------------------------------------------*/
/*＜入出力データ構造＞														*/
/*＜制限事項＞																*/
/*		ＣＭテーブルである。												*/
/*		ＴＶＣＴのステータスは以下の通りである。							*/
/*			�。咤唯弌殖腺个僚蠡�			ＳＭＰテーブル					*/
/*			�■劭贈票萋隻塒廖人�			不要							*/
/*			��参照／更新					更新テーブル					*/
/*			�で啾症塒廖人�					排他不要						*/
/*			�ジ鎚棉�排他／全体排他			（意味なし）					*/
/*			�Γ複裡娘萋醒碓霧鎚棉堯森猝�	（意味なし）					*/
/*＜使用外部モジュールＩＤ＞												*/
/*＜呼出元のモジュールＩＤ＞												*/
/****************************************************************************/
/****************************************************************************/
/*プロジェクト名	:														*/
/*プロセス名		:ＡＰプロセス											*/
/*改造番号			:PRC-025-01												*/
/*改造内容			:スワップアウト禁止仕様変更対応     					*/
/*改造日			:2002.10.21												*/
/*改造者			:supply Taguchi											*/
/****************************************************************************/
/****************************************************************************/
/*プロジェクト名	:												 		*/
/*プロセス名		:ＡＰプロセス									 		*/
/*改造番号			:PRC-031-01										 		*/
/*改造内容			:項目名称を目的に沿った名称に修正     			 		*/
/*改造日			:2002.11.07										 		*/
/*改造者			:supply Taguchi									 		*/
/****************************************************************************/
/****************************************************************************/
/*プロジェクト名	:												 		*/
/*プロセス名		:ＡＰプロセス									 		*/
/*改造番号			:PRC-014-01										 		*/
/*改造内容			:ａｐｍａｉｎ先行処理フラグ追加     			 		*/
/*改造日			:2003.01.07										 		*/
/*改造者			:supply Taguchi									 		*/
/****************************************************************************/
/****************************************************************************/
/*プロジェクト名	:														*/
/*プロセス名		:マスタスケジューラ										*/
/*改造番号			:PRC-040-14												*/
/*改造内容			:終了契機プロセス種別									*/
/*改造日			:2003.02.14												*/
/*改造者			:supply K.Fujii											*/
/****************************************************************************/
/****************************************************************************/
/*仕様変更番号		:SSLA0029												*/
/*修正内容			:スワップ種別の追加										*/
/*修正日			:2003.06.02												*/
/*修正者			:supply Sugawara										*/
/****************************************************************************/
/****************************************************************************/
/*	ＴＰＣＴサブ共通部														*/
/****************************************************************************/
struct  tpctsub {
    long  tpctopn;                      /* オンラインプロセス数				*/
    long  tpctenp;                      /* 起動プロセス数					*/
    long  tpctsm;                       /* セマフォ識別子					*/
    char  tpctdry[32];                  /* ディレクトリ名					*/
    short tpctreio;                     /* 代表端末プロセス番号				*/
    char  tpctsyob[2];                  /* 予備								*/
	long  tpctofp0;						/* Ｐｕ０オフラインプロセス個別部数	*/
};
typedef  struct  tpctsub TPCTSUB;
/****************************************************************************/
/*	ＴＰＣＴ個別部															*/
/****************************************************************************/
struct  tpctpsz {
    long  tpctpid;                      /* プロセス識別子					*/
    char  tpctpnm[8];                   /* プロセス識別名					*/
    long  tpctprn;                      /* プロセスランク					*/
    long  tpctuid;                      /* ユーザ識別子						*/
    long  tpctfno;                      /* ファイル記述子最大個数			*/
    long  tpctatr;                      /* プロセス属性						*/
    long  tpctacc;                      /* プロセスアクセス権				*/
    long  tpctpri;                      /* 起動時プロセス優先度				*/
    long  tpcthpr;                      /* 変更上限プロセス優先度			*/
    long  tpctcls;                      /* 論理空間のサイズ					*/
	short tpcttabo;						/* タイムスライス値			TD96	*/
    short tpctrno;                      /* リクエスト識別子最大個数			*/
    char  tpctpfn[16];                  /* プログラムファイル名				*/
    long  tpctpmb;                      /* プロセス間通信メイルボックス識別子*/
    long  tpctnmb;                      /* 予備（メイルボックス識別子）		*/
    long  tpctsmi;                      /* セマフォ識別子					*/
    char  tpctkcl;                      /* 起動元ブロック番号				*/
    char  tpctheis;						/* 閉塞依頼要／不要					*/
    char  tpcthinf;						/* 閉塞完了情報						*/
    char  tpctflg;     	                /* プロセス指示フラグ				*/
    char  tpctonm[8];                   /* 起動元プロセス識別名				*/
    char  tpctsts;                      /* プロセス状態						*/
    char  tpctpuno;                     /* ＰＵ番号							*/
    char  tpcthotf;                     /* ホットスタンバイ系切替え時		*/
										/*	系切替通知要／不要情報			*/
    char  tpctmflg;                     /* メッセージ引継要／不要情報 ST1223*/
    char  tpcttyp[4];                   /* プログラム種別					*/
    long  tpctpkn;                      /* プログラム個別番号				*/
    char  tpctgrn[2];                   /* グループ名						*/
    char  tpctsgn[2];                   /* サブグループ名					*/
    long  tpctecd;                      /* 終了コード						*/
    long  tpctdtl;                      /* 詳細情報							*/
	long  tpctadd;						/* プロセス終了時の付加情報			*/
    char  tpctabt;                      /* アボート時の処理					*/
    char  tpctpst;                      /* プロセス開始区分					*/
    short tpctjnl;                      /* ＪＮＬ初期獲得バッファサイズ		*/
    long  tpctsno;                      /* プロセス起動依頼通番				*/
    short tpctatsu;						/* 同時編集可能宛先数				*/
    char  tpctotyp[2];					/* プログラム種別（ＰＳＥＣＴ設定）	*/
	short tpctant;						/* ＴＡＢＥリスト先頭個別部番号		*/
    short tpctpatn;						/* ＴＰＡＴエントリ番号				*/
    long  tpctwlg;						/* 障害解析エリアのサイズ			*/
    char  tpctdsts[2];					/* ＤＣＰ使用の色分け				*/
    short tpctabtn;						/* アボート発生回数					*/
    long  tpctcmx;						/* 一般ファイルの最大コネクト数		*/
	long  tpctexmo;						/* 起動元関数識別					*/
	long  tpctntcn;						/* 起動元ＡＣＥノード番号			*/
	short tpctabtm;						/* 同一プロセスアボート回数許容値	*/
	char  tpctsus;						/* サスペンド起動要／不要			*/
	char  tpctins;						/* ＩＮＩＴ＿Ｓ発行中フラグ			*/
	char  tpctdwnf;						/* システムダウン回避フラグ			*/
	char  tpctncaf;						/* キャンセル不可フラグ		SSCY0197*/
	char  tpctswf;						/* スワップアウト禁止フラグ PRC-025 */
	char  tpctpap;						/* apmain先行処理フラグ     PRC-014 */
/*	char  tpctrsv3[1];					   予備				ST0079	SSCY0197*/
	long  tpctdtl2;						/* 詳細情報２						*/
	long  tpctdtl3;						/* 詳細情報３						*/
	unsigned char  tpctoflg;			/* 起動要ＳＭＰプロセスフラグ		*/
	char  tpctrsv4[2];					/* 予備４					ST0079	*/
	char  tpctetyp;						/* 終了契機プロセス種別				*/
										/* 						 PRC-040-14 */
	char  tpctonpa[32];					/* 起動パラメタ						*/
	long  tpctonod;						/* 自ＡＣＥノード番号				*/
	long  tpctwlgs;						/* 障害解析エリア(SMP用)のサイズTD93*/
	long  tpctapi;						/* ＡＰ用ログ情報				TD93*/
	unsigned short tpctplsz;			/* Ｐトレース領域サイズ 		TD93*/
	char  tpctplst;						/* Ｐトレース情報取得ステータス TD93*/
	char  tpcttrcn;						/* トレースファイル名連番取得用		*/
										/* 						 PRC-031-01 */
	long  tpctplab;						/* Ｐトレースアボート要否		TD93*/
	char  tpctsrsf;						/* SCPコマンド実行結果送信電文フラグ*/
										/*								TD18*/
	char  tpctdyrc;						/* ＤＹＲＥＣ対象フラグ			SM01*/
	short tpctecmt;						/* ＴＣＭＴエントリ番号			TD12*/
};                   
typedef  struct  tpctpsz  TPCTPSZ;
  
/****************************************************************************/
/*	プロセス状態(tpctsts)													*/
/****************************************************************************/
#define  TPCTNON  '0'                   /* 未処理							*/
#define  TPCTREQ  '1'                   /* 起動要求							*/
#define  TPCTING  '2'                   /* 起動中							*/
#define  TPCTSUS  '3'                   /* 一時停止中						*/
#define  TPCTEND  '4'                   /* 終了要求中						*/
#define  TPCTCED  '5'                   /* 強制終了要求中					*/
/****************************************************************************/
/*	閉塞依頼要／不要情報(tpctheis)											*/
/****************************************************************************/
#define  TPCTHNEC 0x00					/* 閉塞依頼要						*/
#define  TPCTHUEC 0x01					/* 閉塞依頼不要						*/
/****************************************************************************/
/*	閉塞完了情報(tpcthinf)													*/
/****************************************************************************/
#define  TPCTHFIN 0x00					/* 閉塞完了							*/
#define  TPCTHUNF 0x01					/* 閉塞未完了						*/
/****************************************************************************/
/*	ホットスタンバイ系切替え時 系切替通知要／不要情報(tpcthotf)				*/
/****************************************************************************/
#define  TPCTHOTN 0x00					/* ホットスタンバイ通知要			*/
#define  TPCTHOTU 0x01					/* ホットスタンバイ通知不要			*/
/****************************************************************************/
/*	プロセス指示フラグ(tpctflg)												*/
/****************************************************************************/
#define  TPCTFLAG 0x01					/* 指示フラグ(oscrepr)				*/
/****************************************************************************/
/*	起動要ＳＭＰプロセスフラグ(tpctoflg)									*/
/****************************************************************************/
#define	 TPCTDRNE 0x01					/* 起動要							*/
/****************************************************************************/
/*  終了契機プロセス種別(tpctetyp)                                          */
/****************************************************************************/
#define  TPCTUSUP 0x00					/* 通常プロセス						*/
#define  TPCTSPCP 0x01					/* 特定プロセス						*/
#define  TPCTNOEP 0x02					/* 終了契機不要プロセス				*/
/****************************************************************************/
/*	起動元関数識別子(tpctexmo)												*/
/****************************************************************************/
#define	 TPCTNCMD 0L					/*	コマンド以外					*/
#define	 TPCTESCP 1L					/*	ＳＣＰコマンド					*/
#define	 TPCTEOCP 2L					/*	ＯＣＰコマンド					*/
/****************************************************************************/
/*	サスペンド起動要／不要(tpctsus)											*/
/****************************************************************************/
#define	 TPCTHING '0'					/*	不要							*/
#define	 TPCTHSUS '1'					/*	要								*/
/****************************************************************************/
/*	メッセージ引継要／不要（tpctmflg）										*/
/****************************************************************************/
#define	 TPCTMKNE	'1'					/*	要						ST1223	*/
#define	 TPCTMKNN	'0'					/*	不要					ST1223	*/
/****************************************************************************/
/*	キャンセル不可フラグ（tpctncaf）								SSCY0197*/
/****************************************************************************/
#define	 TPCTCOFF	0x00				/*	キャンセル不可BIT OFF	SSCY0197*/
#define	 TPCTNCAN	0x70				/*	キャンセル不可BIT ON	SSCY0197*/
#define	 TPCTJNL	0x10				/*	ＪＮＬファイル占有		SSCY0197*/
#define	 TPCTTDT	0x20				/*	ＴＤＴ占有				SSCY0197*/
#define	 TPCTFEX	0x40				/*  ファイル拡張中			SSCY0197*/
/****************************************************************************/
/*	スワップアウト禁止フラグ（tpctswf）										*/
/****************************************************************************/
#define  TPCTSWNN  '0'					/* スワップあり			    SSLA0029*/
#define  TPCTSWNE  '1'					/* スワップなし				SSLA0029*/
#define  TPCTSWNU  '2'					/* 確保中メモリスワップなし	SSLA0029*/
/****************************************************************************/
/*	apmain先行処理フラグ（tpctpap）											*/
/****************************************************************************/
#define  TPCTPAPC  '1'                  /* 呼び出しあり             PRC-014 */
#define  TPCTPAPN  '0'                  /* 呼び出しなし             PRC-014 */
