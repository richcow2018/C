/*--------------------------------------------------------------------------*/
/*＜対象業務名＞					運転管理業務							*/
/*＜対象業務ＩＤ＞															*/
/*＜サービス項目名＞														*/
/*＜サービス項目ＩＤ＞														*/
/*＜モジュール名＞					ＴＡＢＰテーブル						*/
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
/*＜ソース修正者名＞				ＳＭＰ　山本　智也						*/
/*＜ソース修正年月日及び修正ＩＤ＞	１９９４年１１月２２日	     M05		*/
/*	（ﾌﾟｰﾙﾊﾞｯﾌｧ過負荷時のメッセージ出力 仕様変更要求書 SSCY0014）　			*/
/*＜ソース修正者名＞				ＳＭＰ　山本　智也						*/
/*＜ソース修正年月日及び修正ＩＤ＞	１９９５年０３月１３日	  st1729		*/
/*	    （ﾌﾟｰﾙﾊﾞｯﾌｧ確保不可時のｻｲｽﾞｱｯﾌﾟ上限設定　故障処理票 st1729 )  		*/
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
/*		ＬＭテーブルである。												*/
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
/*	ＴＡＢＰサブ共通部														*/
/****************************************************************************/
struct  tabpsub {
	short tabptls;						/* トラフィック制限開始値			*/
	short tabptle;						/* トラフィック制限解除値			*/
	long  tabprtt;						/* リトライ間隔						*/
	short tabprtn;						/* リトライ回数						*/
	char  tabpyob[2];					/* 予備								*/
	char  tabpcinf;						/* ＣＭ実装／未実装					*/
	char  tabpyob2[3];					/* 予備								*/
};
typedef  struct  tabpsub  TABPSUB;
/****************************************************************************/
/*	ＴＡＢＰ個別部															*/
/****************************************************************************/
struct  tabppsz {
	long  tabppid;                      /* バッファプール識別子				*/
	long  tabpbsz;                      /* バッファサイズ					*/
	long  tabpbno;                      /* バッファの個数					*/
	char  tabpmet;                      /* メモリ種別						*/
	char  tabppno;                      /* ＰＵ番号							*/
	char  tabptflg;						/* トラフィック制限実施フラグ		*/
	char  tabpmsf;						/* １００％規制継続中フラグ	  M05  */
	short tabpupno;						/* ｻｲｽﾞｱｯﾌﾟ回数  st1729				*/
	short tabppyob;						/* 予備	　st1729					*/
};
typedef  struct  tabppsz  TABPPSZ;

/****************************************************************************/
/*	メモリ種別(tabpmet)														*/
/****************************************************************************/
#define  TABPLM 'L'                     /* ローカルメモリ					*/
#define  TABPCM 'C'                     /* コモンメモリ						*/

/****************************************************************************/
/*	トラフィック制限実施フラグ(tabptflg)									*/
/****************************************************************************/
#define	 TABPON		1L					/* TD10	トラフィック制限実施		*/
#define	 TABPOFF	0L					/* TD10	トラフィック制限解除		*/

