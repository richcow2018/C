/****************************************************************************/
/*																			*/
/* TPCU	94/09/16 富士通	久保田												*/
/* history:																	*/
/*	96.01.24 K.Kubota ST3937: add tpctmflg									*/
/*	03.04.16 S.Miyawaki LALa-SMP移植							MD001		*/
/****************************************************************************/
struct	tpcusub	{
	long  tpcuopn;						/* オンラインプロセス数				*/
	long  tpcuenp;						/* 起動プロセス数					*/
	long  tpcusm;						/* セマフォ識別子					*/
	char  tpcudry[32];					/* ディレクトリ名					*/
	short tpcureio;						/* 代表端末プロセス番号				*/
	char  tpcusyob[2];					/* 予備								*/
	long  tpcuofp0;						/* Ｐｕ０オフラインプロセス個別部数	*/
};
typedef	 struct	 tpcusub TPCUSUB;
/****************************************************************************/
/*	ＴＰＣＵ個別部															*/
/****************************************************************************/
struct	tpcupsz	{
	long  tpcupid;						/* プロセス識別子					*/
	char  tpcupnm[8];					/* プロセス識別名					*/
	long  tpcuprn;						/* プロセスランク					*/
	long  tpcuuid;						/* ユーザ識別子						*/
	long  tpcufno;						/* ファイル記述子最大個数			*/
	long  tpcuatr;						/* プロセス属性						*/
	long  tpcuacc;						/* プロセスアクセス権				*/
	long  tpcupri;						/* 起動時プロセス優先度				*/
	long  tpcuhpr;						/* 変更上限プロセス優先度			*/
	long  tpcucls;						/* 論理空間のサイズ					*/
	short tpcutabo;						/* タイムスライス値			TD96	*/
	short tpcurno;						/* リクエスト識別子最大個数			*/
	char  tpcupfn[16];					/* プログラムファイル名				*/
	long  tpcupmb;						/* プロセス間通信メイルボックス識別子*/
	long  tpcunmb;						/* 予備（メイルボックス識別子）		*/
	long  tpcusmi;						/* セマフォ識別子					*/
	char  tpcukcl;						/* 起動元ブロック番号				*/
	char  tpcuheis;						/* 閉塞依頼要／不要					*/
	char  tpcuhinf;						/* 閉塞完了情報						*/
	char  tpcuflg;						/* プロセス指示フラグ				*/
	char  tpcuonm[8];					/* 起動元プロセス識別名				*/
	char  tpcusts;						/* プロセス状態						*/
	char  tpcupuno;						/* ＰＵ番号							*/
	char  tpcuhotf;						/* ホットスタンバイ系切替え時		*/
										/*	系切替通知要／不要情報			*/
	char  tpcumflg;						/* ﾒｯｾｰｼﾞ引継要/不要 ST3937			*/
	char  tpcutyp[4];					/* プログラム種別					*/
	long  tpcupkn;						/* プログラム個別番号				*/
	char  tpcugrn[2];					/* グループ名						*/
	char  tpcusgn[2];					/* サブグループ名					*/
	long  tpcuecd;						/* 終了コード						*/
	long  tpcudtl;						/* 詳細情報							*/
	long  tpcuadd;						/* プロセス終了時の付加情報			*/
	char  tpcuabt;						/* アボート時の処理					*/
	char  tpcupst;						/* プロセス開始区分					*/
	short tpcujnl;						/* ＪＮＬ初期獲得バッファサイズ		*/
	long  tpcusno;						/* プロセス起動依頼通番				*/
	short tpcuatsu;						/* 同時編集可能宛先数				*/
	char  tpcuotyp[2];					/* プログラム種別（ＰＳＥＣＴ設定）	*/
	short tpcuant;						/* ＴＡＢＥリスト先頭個別部番号		*/
	short tpcupatn;						/* ＴＰＡＴエントリ番号				*/
	long  tpcuwlg;						/* 障害解析エリアのサイズ			*/
	char  tpcudsts[2];					/* ＤＣＰ使用の色分け				*/
	short tpcuabtn;						/* アボート発生回数					*/
	long  tpcucmx;						/* 一般ファイルの最大コネクト数		*/
	long  tpcuexmo;						/* 起動元関数識別					*/
	long  tpcuntcn;						/* 起動元ＡＣＥノード番号			*/
	short tpcuabtm;						/* 同一プロセスアボート回数許容値	*/
	char  tpcusus;						/* サスペンド起動要／不要			*/
	char  tpcuins;						/* ＩＮＩＴ＿Ｓ発行中フラグ			*/
	char  tpcudwnf;						/* システムダウン回避フラグ			*/
    char  tpcuncaf;                     /* キャンセル不可フラグ        MD001*/
    char  tpcuswf;                      /* スワップアウト禁止フラグ    MD001*/
    char  tpcupap;                      /* apmain先行処理フラグ        MD001*/
	long  tpcudtl2;						/* 詳細情報２						*/
	long  tpcudtl3;						/* 詳細情報３						*/
	unsigned char  tpcuoflg;			/* 起動要ＳＭＰプロセスフラグ		*/
	char  tpcursv4[2];					/* 予備４			ST0079     MD001*/
    char  tpcuetyp;                     /* 終了契機プロセス種別        MD001*/
	char  tpcuonpa[32];					/* 起動パラメタ						*/
	long  tpcuonod;						/* 自ＡＣＥノード番号				*/
	long  tpcuwlgs;						/* 障害解析ｴﾘｱ（ＳＭＰ用）のｻｲｽﾞTD93*/
	long  tpcuapi;						/* ＡＰ用ログ情報				TD93*/
	unsigned short tpcuplsz;			/* Ｐトレース領域サイズ			TD93*/
	char  tpcuplst;						/* Ｐトレース情報取得ステータス	TD93*/
	char  tpcutrcn;                     /* トレースファイル名連番取得用MD001*/
	long  tpcuplab;						/* Ｐトレースアボート要否		TD93*/
	char  tpcusrsf;						/* SCPｺﾏﾝﾄﾞ実行結果送信電文ﾌﾗｸﾞ	TD18*/
    char  tpcudyrc;                     /* ＤＹＲＥＣ対象フラグ        MD001*/
	short tpcuecmt;						/* ＴＣＭＴエントリ番号			TD12*/
};					 
typedef	 struct	 tpcupsz  TPCUPSZ;
