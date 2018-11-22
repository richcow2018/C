/****************************************************************************/
/*	著作権　１９９３														*/
/*			　ＮＴＴデータ通信株式会社										*/
/*				金融システム事業本部										*/
/*																			*/
/*																			*/
/*	収容物　ＡＣＥ−ＳＭＰシステム　										*/
/*				ＲＣＶ　ボリュームリカバリ（ＦＪ無し）	(mr_vxxx系)			*/
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*＜対象業務名＞					 故障回復業務							*/
/*＜対象業務ＩＤ＞					 ＲＣＶ									*/
/*＜サービス項目名＞				 										*/
/*＜サービス項目ＩＤ＞				 										*/
/*＜モジュール名＞					 ＶＲＣＶ（ＦＪ無し）マクロ定義			*/
/*＜モジュールＩＤ＞				 										*/
/*＜モジュール通番＞														*/
/*--------------------------------------------------------------------------*/
/*＜適用機種＞						 ＡＣＥ									*/
/*＜適用ＯＳ＞						 ＴＲＡＤＥ								*/
/*＜開発環境＞						 ＳＵＮ  ＳＰＡＲＣ−ＩＰＸ				*/
/*＜記述言語＞						 Ｃ言語									*/
/*＜モジュール形態＞				 関数									*/
/*＜機能区分＞																*/
/*＜対象データ＞															*/
/*＜工程・階層区分＞				 										*/
/*--------------------------------------------------------------------------*/
/*＜開発システム名＞				 ＡＣＥ−ＳＭＰシステム					*/
/*＜開発システム番号＞				 ５７２６０１４０２１００				*/
/*--------------------------------------------------------------------------*/
/*＜開発担当名＞					 営業店システム担当						*/
/*＜電話番号＞						 169-3537(03-5702-3537)					*/
/*--------------------------------------------------------------------------*/
/*＜設計者名＞						 柴崎　智子								*/
/*＜設計年月日＞					 １９９４年０６月０１日					*/
/*--------------------------------------------------------------------------*/
/*＜ソース作成者名＞				 柴崎　智子								*/
/*＜ソース作成年月日＞				 １９９４年１０月０５日					*/
/*＜ソース修正者名＞				 今井　弘幸						 CT0705 */
/*＜ソース作成年月日＞				 １９９４年１２月１９日					*/
/*＜ソース修正者名＞				 柴崎　智子				CT1093(ST2995)	*/
/*＜ソース作成年月日＞				 １９９５年　７月１４日					*/
/*＜ソース修正者名＞				 柴崎　智子								*/
/*＜ソース修正年月日及び修正ＩＤ＞	 １９９５年　７月１７日	ST2893			*/
/*＜ソース修正者名＞				 柴崎　智子								*/
/*＜ソース修正年月日及び修正ＩＤ＞	 １９９５年　７月２０日	CT1094(ST2996)	*/
/*--------------------------------------------------------------------------*/
/*＜見積ステップ数＞				 ？？？ステップ							*/
/*--------------------------------------------------------------------------*/
/*＜機能概要＞																*/
/*		ＶＲＣＶ（ＦＪ無し）プロセス内で使用する定数の定義					*/
/*		ＶＲＣＶ（ＦＪ無し）プロセス内で使用するマクロの定義				*/
/*--------------------------------------------------------------------------*/
/*＜呼出形式＞																*/
/*																			*/
/*＜仮引き数＞																*/
/*																			*/
/*＜返却値＞   																*/
/*--------------------------------------------------------------------------*/
/*＜入出力データ構造＞														*/
/*																			*/
/*＜制限事項＞																*/
/*	  特になし																*/
/*																			*/
/*＜使用外部モジュールＩＤ＞												*/
/*																			*/
/*＜呼出元のモジュールＩＤ＞												*/
/*																			*/
/****************************************************************************/

/****************************************/
/*	定数								*/
/****************************************/
#define	LNULL		(long *)0L
#define	CNULL		(char *)0L

#define	MRVON		1
#define	MRVOFF		0

#define	MRVLOG		pscparea.pscobsad	/* 障害解析情報エリアアドレスCT0705	*/
#define	MRVRTRY		mopcbp->mopscstp->tcstrtry
										/* ファイルアクセスリトライ回数		*/

/****************************************/
/*	関連プロセスプログラム種別			*/
/****************************************/
#define	MRVMRIT		"C6"				/* ﾘｶﾊﾞﾘﾌｧｲﾙ創成ﾌﾟﾛｾｽﾌﾟﾛｸﾞﾗﾑ種別	*/
#define	MRVMRCT		"C5"				/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽﾌﾟﾛｸﾞﾗﾑ種別		*/
#define	MRVMRKT		"DE"				/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽﾌﾟﾛｸﾞﾗﾑ種別		*/

/****************************************/
/*	領域長定義							*/
/****************************************/
#define	MRVNDIRL	16					/* ネットワークディレクトリ名長		*/
#define	MRVLVSNL	16					/* 特殊装置ファイル名長				*/
#define	MRVMTDRL	16					/* ﾏｳﾝﾄ先ﾌﾞﾛｯｸ特殊ﾌｧｲﾙ名長			*/
#define	MRVGPDRL	16					/* グループディレクトリ名長			*/
#define	MRVSGDRL	16					/* サブグループディレクトリ名長		*/
#define	MRVFLNML	16					/* ファイル名長						*/

#define	MRVSNMLN	MRVNDIRL+MRVLVSNL	/* 特殊装置ファイルパス名長			*/
#define	MRVMNMLN	MRVNDIRL+MRVMTDRL	/* マウント先ディレクトリ名長		*/
#define	MRVDNMLN	MRVMNMLN+MRVGPDRL+MRVSGDRL
										/* ディレクトリパス名長				*/
#define	MRVFNMLN	MRVDNMLN+MRVFLNML	/* ファイルパス名長					*/

#define	MRVCBFL		4096L				/* ﾐﾗｰvol復旧時ｺﾋﾟｰﾊﾞｯﾌｧ域ｻｲｽﾞ		*/

/****************************************/
/*	ファイル生成モード					*/
/****************************************/
#define	MRVCMOD		OSFFCNTN	|		/* 連続領域確保						*/\
					OSFFRDAWT	|		/* read_after_writeチェック実行		*/\
					OSFFCLEAR	|		/* 領域初期化						*/\
					OSFAOEXL	|		/* 排他制御権(所有者)				*/\
					OSFAOCHG	|		/* ファイル保護コード変更権(所有者)	*/\
					OSFAOEXC	|		/* 実行権(所有者)					*/\
					OSFAOEXT	|		/* 拡張権(所有者)					*/\
					OSFAOWRT	|		/* 書き込み権(所有者)				*/\
					OSFAORED	|		/* 読み込み権(所有者)				*/\
					OSFAODEL	|		/* 削除権(所有者)					*/\
					OSFAGEXL	|		/* 排他制御権(ｸﾞﾙｰﾌﾟ)				*/\
					OSFAGCHG	|		/* ファイル保護コード変更権(ｸﾞﾙｰﾌﾟ)	*/\
					OSFAGEXC	|		/* 実行権(ｸﾞﾙｰﾌﾟ)					*/\
					OSFAGEXT	|		/* 拡張権(ｸﾞﾙｰﾌﾟ)					*/\
					OSFAGWRT	|		/* 書き込み権(ｸﾞﾙｰﾌﾟ)				*/\
					OSFAGRED	|		/* 読み込み権(ｸﾞﾙｰﾌﾟ)				*/\
					OSFAGDEL	|		/* 削除権(ｸﾞﾙｰﾌﾟ)					*/\
					OSFACEXL	|		/* 排他制御権(その他)				*/\
					OSFACCHG	|		/* ファイル保護コード変更権(その他)	*/\
					OSFACEXC	|		/* 実行権(その他)					*/\
					OSFACEXT	|		/* 拡張権(その他)					*/\
					OSFACWRT	|		/* 書き込み権(その他)				*/\
					OSFACRED	|		/* 読み込み権(その他)				*/\
					OSFACDEL			/* 削除権(その他)					*/

/****************************************/
/*	ファイルオープンモード				*/
/****************************************/
#define	MRVOMOD		OSFACEXT	|		/* 拡張権(その他)					*/\
					OSFACWRT	|		/* 書き込み権(その他)				*/\
					OSFACRED	|		/* 読み込み権(その他)				*/\
					OSFACDEL			/* 削除権(その他)					*/

#define	MRVEOF		0					/* ＥＯＦ							*/
#define	MRVWVRO		0x14				/* 他系ワークファイルボリューム		*/

/****************************************/
/*	ＴＶＭＴ　ボリューム属性			*/
/****************************************/
#define	MRVVJNL		0x02				/* ＪＮＬファイルボリューム			*/
#define	MRVVRBI		0x01				/* ＲＢＩファイルボリューム			*/

/****************************************/
/*	ＳＭＰ配下ディレクトリ階層			*/
/****************************************/
#define	MRVMNTN		1					/* ﾏｳﾝﾄ先ﾌﾞﾛｯｸ特殊装置ﾌｧｲﾙ名		*/
#define	MRVGDIR		2					/* グループディレクトリ名			*/
#define	MRVSDIR		3					/* サブグループディレクトリ名		*/
#define	MRVFILE		4					/* ファイル名						*/

/****************************************/
/*	回復・リストア制御					*/
/****************************************/
#define	MRVCRNT		mrvpcb.mrvidex		/* 前処理〜待ち合わせ処理中のｖｏｌ	*/
#define	MRVNEXT		((MRVCRNT+1)%2)		/* チェック〜前処理中のｖｏｌ		*/
#define	MRVBFOR		((MRVCRNT+1)%2)		/* 待ち合わせ〜後処理中のｖｏｌ		*/

/****************************************/
/*	Ｓトレースログ詳細情報（任意取得）	*/
/****************************************/
#define	MRVWLG		0x44440000			/* CT1093							*/

/****************************************/
/*	ビット操作共通マクロ				*/
/****************************************/
#define	MRVLBIT	( sizeof(long) * 8 )
#define	MRVBITON( AREA, ENT )												\
					( *( AREA + ( ENT / MRVLBIT ) )							\
					|= ( (unsigned long)0x80000000 >> ( ENT % MRVLBIT ) ) )
#define	MRVBITCK( AREA, ENT )												\
				( 0L != ( *( AREA + ( ENT / MRVLBIT ) )						\
				& ( (unsigned long)0x80000000 >> ( ENT % MRVLBIT ) ) ) ?	\
				MRVON : MRVOFF )

/****************************************/
/*	ＶＭＴ処理フラグ　マクロ			*/
/****************************************/
#define	MRVVMTFON( VMTE )	MRVBITON( mrvpcb.mrvvmtf, VMTE )

#define	MRVVMTFCK( VMTE )	MRVBITCK( mrvpcb.mrvvmtf, VMTE )

/****************************************/
/*	エラー発生時マクロ					*/
/****************************************/
#define	MF_FIOC( CODE )		mf_fioc( CODE, ' ' );

#define	MRVSABT( CODE, DTL1, DTL2, DTL3 )									\
{	mrvpcb.mrvdtl1 = ( (short)0 == mrvpcb.mrvmdid ? DTL1 : mrvpcb.mrvdtl1 );\
	mrvpcb.mrvdtl2 = ( (short)0 == mrvpcb.mrvmdid ? DTL2 : mrvpcb.mrvdtl2 );\
	mrvpcb.mrvdtl3 = ( (short)0 == mrvpcb.mrvmdid ? DTL3 : mrvpcb.mrvdtl3 );\
	mrvpcb.mrvmdid = ( (short)0 == mrvpcb.mrvmdid ? CODE : mrvpcb.mrvmdid );\
}

/****************************************/
/*	ボリュームアンマウント				*/
/****************************************/
										/* ｏｓｕｍｏｕｎｔ発行				*/
#define	mr_vumt( MNTN )		mr_vumc( MNTN, 0 )
										/* ｏｓｕｍｏｕｎｔｆ発行			*/
#define	mr_vumf( MNTN )		mr_vumc( MNTN, 1 )

/****************************************/
/*	ログ取得領域長調整					*/
/****************************************/
										/* CT1093							*/
#define	MRVSIZE( STR )		( ( ( mr_vsiz( STR ) / sizeof( long ) ) + 1 ) * 4 )

/****************************************/
/*	回復結果設定						*/
/****************************************/
										/* CT1094							*/
#define	MR_VVRC( AREA, CODE )	AREA = ( AREA == MRVVERR ? AREA : CODE )

/****************************************/
/*	I/Oｴﾗｰ発生処理種別設定				*/
/****************************************/
										/* ST2893							*/
#define	MR_VSYS( AREA, CODE )	 AREA = ( AREA != 0 ? AREA : CODE )

/****************************************/
/*	Ｉ／Ｏエラー発生処理種別			*/
/****************************************/
#define	MRVCLOSE	(unsigned char)0x01	/* ｏｓｃｌｏｓｅ			ST2893	*/
#define	MRVCONN		(unsigned char)0x02	/* ｏｓｃｏｎｎ				ST2893	*/
#define	MRVCREAT	(unsigned char)0x03	/* ｏｓｃｒｅａｔ			ST2893	*/
#define	MRVDCONN	(unsigned char)0x04	/* ｏｓｄｃｏｎｎ			ST2893	*/
#define	MRVDELET	(unsigned char)0x05	/* ｏｓｄｅｌｅｔ			ST2893	*/
#define	MRVEXTEN	(unsigned char)0x06	/* ｏｓｅｘｔｅｎ			ST2893	*/
#define	MRVMOUNT	(unsigned char)0x07	/* ｏｓｍｏｕｎｔ			ST2893	*/
#define	MRVOPEN		(unsigned char)0x08	/* ｏｓｏｐｅｎ				ST2893	*/
#define	MRVTRUNC	(unsigned char)0x09	/* ｏｓｔｒｕｎｃ			ST2893	*/
#define	MRVUMOUNT	(unsigned char)0x0A	/* ｏｓｕｍｏｕｎｔ			ST2893	*/
#define	MRVUMOUNTF	(unsigned char)0x0B	/* ｏｓｕｍｏｕｎｔｆ		ST2893	*/
#define	MRVREAD		(unsigned char)0x0C	/* ｏｓｒｅａｄ				ST2893	*/
#define	MRVSEEK		(unsigned char)0x0D	/* ｏｓｓｅｅｋ				ST2893	*/
#define	MRVWRITD	(unsigned char)0x0E	/* ｏｓｗｒｉｔｄ			ST2893	*/
#define	MRVGFINF	(unsigned char)0x0F	/* ｏｓｇｆｉｎｆ			ST2893	*/
#define	MRVIOCTL	(unsigned char)0x10	/* ｏｓｉｏｃｔｌ			ST2893	*/
#define	MRVIIOCTL	(unsigned char)0x11	/* ｏｓｉｉｏｃｔｌ			ST2893	*/
#define	MRVCONFIG	(unsigned char)0x12	/* ｏｓｃｏｎｆｉｇ			ST2893	*/
#define	MRVVDI		(unsigned char)0x30	/* ｖｄｉコマンド			ST2893	*/
#define	MRVMRC		(unsigned char)0x40	/* ボリュームコピープロセス	ST2893	*/
#define	MRVMRI		(unsigned char)0x41	/* RCVファイル創成プロセス	ST2893	*/

/****************************************/
/*	Ｉ／Ｏエラー詳細設定				*/
/****************************************/
										/* ST2893							*/
#define	MR_VECD( AREA, CODE )	 AREA = ( AREA != 0 ? AREA : CODE )
