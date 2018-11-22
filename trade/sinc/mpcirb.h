/****************************************************************************/
/* ファイル名：　mpcirb.h													*/
/* 機能  　　：  テーブルアドレス位置										*/
/*				 ＩＲコード 												*/
/*				 モジュールＩＤ 											*/
/*				 ＩＲＢテンプレート 										*/
/*				 システムコールプロトタイプ 								*/
/*				 システムコールアーギュメント域テンプレート 				*/
/*				 システムコール発行マクロ									*/
/* 作成日　  ：  1993.11.24 												*/
/****************************************************************************/
/**************************************/
/* イベント識別子定義				  */
/**************************************/
#define E100		0					/* E100:ＴＣＰ／ＩＰオープン完了通知*/
#define E101		1					/* E101:障害通知					*/
#define E102		2					/* E102:回復通知					*/
#define E103		3					/* E103:系切り替え通知				*/
#define E104		4					/* E104:パスＤＥＡＣＴ完了通知		*/
#define E105		5					/* E105:NETCTL(ｻﾌﾞﾈｯﾄﾏｽｸ)完了		*/
#define E106		6					/* E106:NETCTL(IPｱﾄﾞﾚｽ)完了 		*/
#define E107		7					/* E107:NETCTLﾘﾄﾗｲｲﾝﾀｰﾊﾞﾙﾀｲﾏ完了	*/
#define E108		8					/* E108:NETCTL(ﾈｯﾄﾜｰｸﾌﾗｸﾞ)完了		*/
#define E200		0					/* E200:論理パスオープン要求		*/
#define E201		1					/* E201:論理パスクローズ要求		*/
#define E202		2					/* E202:電文送信要求				*/
#define E203		3					/* E203:電文受信要求				*/
#define E204		4					/* E204:故障通知要求				*/
#define E205		5					/* E205:故障回復待要求				*/
#define E206		6					/* E206:ＡＣＴＩＶＥ要求			*/
#define E207		7					/* E207:ＬＩＳＴＥＮ要求			*/
#define E208		8					/* E208:コネクション解放要求		*/
#define E209		9					/* E209:コネクションアボート要求	*/
#define E210		10					/* E210:オプション設定要求			*/
#define E211		11					/* E211:緊急データ送信要求			*/
#define E212		12					/* E212:緊急データ受信要求			*/
#define E213		13					/* E213:受信キャンセル要求			*/
#define E214		14					/* E214:緊急データ受信キャンセル要求*/
#define E215		15					/* E215:ＡＴＴＡＣＨ完了			*/
#define E216		16					/* E216:ＢＩＮＤ完了				*/
#define E217		17					/* E217:ＬＩＳＴＥＮ完了			*/
#define E218		18					/* E218:非同期通知要求完了			*/
#define E219		19					/* E219:ＤＥＴＡＣＨ完了			*/
#define E220		20					/* E220:ＡＣＣＥＰＴ完了			*/
#define E221		21					/* E221:パスＡＣＴＩＶＥ通知		*/
#define E222		22					/* E222:パスＤＥＡＣＴ通知			*/
#define E223		23					/* E223:ｺﾈｸｼｮﾝDEACT完了通知 		*/
#define E300		0					/* E300:ＬＩＳＴＥＮ要求通知		*/
#define E301		1					/* E301:ＡＣＴＩＶＥ要求通知		*/
#define E302		2					/* E302:電文送信要求通知			*/
#define E303		3					/* E303:電文受信要求通知			*/
#define E304		4					/* E304:コネクション解放要求通知	*/
#define E305		5					/* E305:コネクションアボート要求通知*/
#define E306		6					/* E306:緊急データキャンセル要求通知*/
#define E307		7					/* E307:電文受信キャンセル要求通知	*/
#define E308		8					/* E308:オプション設定要求通知		*/
#define E309		9					/* E309:緊急データ送信要求通知		*/
#define E310		10					/* E310:緊急データ受信要求通知		*/
#define E311		11					/* E311:コネクションＤＥＡＣＴ通知	*/
#define E312		12					/* E312:ＳＥＴＯＰＴ完了			*/
#define E313		13					/* E313:ｏｓｉｗｒｉｔｄ完了		*/
#define E314		14					/* E314:ｏｓｉｒｅａｄｄ完了		*/
#define E315		15					/* E315:ＲＣＶＯＯＢ完了			*/
#define E316		16					/* E316:ＳＥＮＤＯＯＢ完了			*/
#define E317		17					/* E317:非同期通知要求完了			*/
#define E318		18					/* E318:ＤＥＴＡＣＨ完了			*/
#define E319		19					/* E319:ＡＢＯＲＴ完了				*/
#define E320		20					/* E320:ＤＩＳＣＯＮＮＥＣＴ完了	*/
#define E321		21					/* E321:ＣＯＮＮＥＣＴ完了			*/
#define E322		22					/* E322:DETACHﾘﾄﾗｲﾀｲﾏ完了			*/
/**************************************/
/* 同時使用IRB数					  */
/**************************************/
#define _NIRB_LCNTL 4					/* 回線制御用ＩＲＢ数				*/
#define _NIRB_PCNTL 5					/* パス制御用ＩＲＢ数				*/
#define _NIRB_READ	2					/* 受信用ＩＲＢ数					*/
#define _NIRB_WRIT	2					/* 送信用ＩＲＢ数					*/
/**************************************/
/* ＩＲコード定義					  */
/**************************************/
/**************************************/
/* モジュールＩＤ（ＭＩＤ）定義 	  */
/**************************************/
#define _ML_TERMP	0x02				/* プロセス終了処理 				*/
#define	_ML_E1		0x10				/* E1??:回線制御のＤＭＩＤ			*/
#define _ML_LOPEN	_ML_E1 + E100		/* E100:ＴＣＰ／ＩＰオープン完了通知*/
#define _ML_LFAIL	_ML_E1 + E101		/* E101:障害通知					*/
#define _ML_LRCOV	_ML_E1 + E102		/* E102:回復通知					*/
#define _ML_LKISW	_ML_E1 + E103		/* E103:系切り替え通知				*/
#define _ML_LDACT	_ML_E1 + E104		/* E104:パスＤＥＡＣＴ完了通知		*/
#define _ML_LSMSK	_ML_E1 + E105		/* E105:NETCTL(ｻﾌﾞﾈｯﾄﾏｽｸ)完了		*/
#define _ML_LSIPA	_ML_E1 + E106		/* E106:NETCTL(IPｱﾄﾞﾚｽ)完了 		*/
#define _ML_LNIVT	_ML_E1 + E107		/* E107:NETCTLﾘﾄﾗｲﾀｲﾏ完了			*/
#define _ML_LSFLG	_ML_E1 + E108		/* E105:NETCTL(ﾈｯﾄﾜｰｸﾌﾗｸﾞ)完了		*/
/* RESERVE				0x28...0x1F 										*/
#define	_ML_E2		0x20				/* E2??:パス制御のＤＭＩＤ			*/
#define _ML_POPEN	_ML_E2 + E200		/* E200:論理パスオープン要求		*/
#define _ML_PCLOS	_ML_E2 + E201		/* E201:論理パスクローズ要求		*/
#define _ML_PCPUT	_ML_E2 + E202		/* E202:電文送信要求				*/
#define _ML_PTRED	_ML_E2 + E203		/* E203:電文受信要求				*/
#define _ML_PFALT	_ML_E2 + E204		/* E204:故障通知要求				*/
#define _ML_PRCOV	_ML_E2 + E205		/* E205:故障回復待要求				*/
#define _ML_PACTV	_ML_E2 + E206		/* E206:ＡＣＴＩＶＥ要求			*/
#define _ML_PLIST	_ML_E2 + E207		/* E207:ＬＩＳＴＥＮ要求			*/
#define _ML_PCFRE	_ML_E2 + E208		/* E208:コネクション解放要求		*/
#define _ML_PCABT	_ML_E2 + E209		/* E209:コネクションアボート要求	*/
#define _ML_POPTI	_ML_E2 + E210		/* E210:オプション設定要求			*/
#define _ML_PSURG	_ML_E2 + E211		/* E211:緊急データ送信要求			*/
#define _ML_PRURG	_ML_E2 + E212		/* E212:緊急データ受信要求			*/
#define _ML_PRCAN	_ML_E2 + E213		/* E213:受信キャンセル要求			*/
#define _ML_POCAN	_ML_E2 + E214		/* E214:緊急データ受信キャンセル要求*/
#define _ML_PATCH	_ML_E2 + E215		/* E215:ＡＴＴＡＣＨ完了			*/
#define _ML_PBIND	_ML_E2 + E216		/* E216:ＢＩＮＤ完了				*/
#define _ML_PLISN	_ML_E2 + E217		/* E217:ＬＩＳＴＥＮ完了			*/
#define _ML_PASY0	_ML_E2 + E218		/* E218:非同期通知要求完了			*/
#define _ML_PDECH	_ML_E2 + E219		/* E219:ＤＥＴＡＣＨ完了			*/
#define _ML_PACPT	_ML_E2 + E220		/* E220:ＡＣＣＥＰＴ完了			*/
#define _ML_PACTP	_ML_E2 + E221		/* E221:パスＡＣＴＩＶＥ通知		*/
#define _ML_PDACP	_ML_E2 + E222		/* E222:パスＤＥＡＣＴ通知			*/
#define _ML_PCDCT	_ML_E2 + E223		/* E223:ｺﾈｸｼｮﾝDEACT完了通知 		*/
/* RESERVE				0x38...0x3F 										*/
#define	_ML_E3		0x40				/* E3??:コネクション制御のＤＭＩＤ	*/
#define _ML_CLIST	_ML_E3 + E300		/* E300:ＬＩＳＴＥＮ要求通知		*/
#define _ML_CACTV	_ML_E3 + E301		/* E301:ＡＣＴＩＶＥ要求通知		*/
#define _ML_CCPUT	_ML_E3 + E302		/* E302:電文送信要求通知			*/
#define _ML_CTRED	_ML_E3 + E303		/* E303:電文受信要求通知			*/
#define _ML_CCFRE	_ML_E3 + E304		/* E304:コネクション解放要求通知	*/
#define _ML_CCABT	_ML_E3 + E305		/* E305:コネクションアボート要求通知*/
#define _ML_COCAN	_ML_E3 + E306		/* E306:緊急データキャンセル要求通知*/
#define _ML_CRCAN	_ML_E3 + E307		/* E307:電文受信キャンセル要求通知	*/
#define _ML_COPTI	_ML_E3 + E308		/* E308:オプション設定要求通知		*/
#define _ML_CSURG	_ML_E3 + E309		/* E309:緊急データ送信要求通知		*/
#define _ML_CRURG	_ML_E3 + E310		/* E310:緊急データ受信要求通知		*/
#define _ML_CCDEA	_ML_E3 + E311		/* E311:コネクションＤＥＡＣＴ通知	*/
#define _ML_CSETO	_ML_E3 + E312		/* E312:ＳＥＴＯＰＴ完了			*/
#define _ML_CWRTD	_ML_E3 + E313		/* E313:ｏｓｉｗｒｉｔｄ完了		*/
#define _ML_CREAD	_ML_E3 + E314		/* E314:ｏｓｉｒｅａｄｄ完了		*/
#define _ML_CROOB	_ML_E3 + E315		/* E315:ＲＣＶＯＯＢ完了			*/
#define _ML_CSOOB	_ML_E3 + E316		/* E316:ＳＥＮＤＯＯＢ完了			*/
#define _ML_CASY1	_ML_E3 + E317		/* E317:非同期通知要求完了			*/
#define _ML_CDECH	_ML_E3 + E318		/* E318:ＤＥＴＡＣＨ完了			*/
#define _ML_CABOT	_ML_E3 + E319		/* E319:ＡＢＯＲＴ完了				*/
#define _ML_CDCON	_ML_E3 + E320		/* E320:ＤＩＳＣＯＮＮＥＣＴ完了	*/
#define _ML_CCONN	_ML_E3 + E321		/* E321:ＣＯＮＮＥＣＴ完了			*/
#define _ML_CDTIT	_ML_E3 + E322		/* E322:DETACHﾘﾄﾗｲﾀｲﾏ完了			*/
/**************************************/
/* ＩＲコード定義					  */
/**************************************/
#define _IR_TERMP	MCSTERM 			/* 強制閉塞 						*/
/* RESERVE				0x01...0x01 										*/
#define	_IR_E1		0x10				/* E1??:回線制御のＩＲコード		*/
#define _IR_LOPEN	_IR_E1 + E100		/* E100:ＴＣＰ／ＩＰオープン完了通知*/
#define _IR_LFAIL	_IR_E1 + E101		/* E101:障害通知					*/
#define _IR_LRCOV	_IR_E1 + E102		/* E102:回復通知					*/
#define _IR_LKISW	_IR_E1 + E103		/* E103:系切り替え通知				*/
#define _IR_LDACT	_IR_E1 + E104		/* E104:パスＤＥＡＣＴ完了通知		*/
#define _IR_LSMSK	_IR_E1 + E105		/* E105:NETCTL(ｻﾌﾞﾈｯﾄﾏｽｸ)完了		*/
#define _IR_LSIPA	_IR_E1 + E106		/* E106:NETCTL(IPｱﾄﾞﾚｽ)完了 		*/
#define _IR_LSFLG	_IR_E1 + E108		/* E108:NETCTL(ﾈｯﾄﾜｰｸﾌﾗｸﾞ)完了		*/
/* RESERVE				0x17...0x1F 										*/
#define	_IR_E2		0x20				/* E2??:パス制御のＩＲコード		*/
#define _IR_POPEN	_IR_E2 + E200		/* E200:論理パスオープン要求		*/
#define _IR_PCLOS	_IR_E2 + E201		/* E201:論理パスクローズ要求		*/
#define _IR_PCPUT	_IR_E2 + E202		/* E202:電文送信要求				*/
#define _IR_PTRED	_IR_E2 + E203		/* E203:電文受信要求				*/
#define _IR_PFALT	_IR_E2 + E204		/* E204:故障通知要求				*/
#define _IR_PRCOV	_IR_E2 + E205		/* E205:故障回復待要求				*/
#define _IR_PACTV	_IR_E2 + E206		/* E206:ＡＣＴＩＶＥ要求			*/
#define _IR_PLIST	_IR_E2 + E207		/* E207:ＬＩＳＴＥＮ要求			*/
#define _IR_PCFRE	_IR_E2 + E208		/* E208:コネクション解放要求		*/
#define _IR_PCABT	_IR_E2 + E209		/* E209:コネクションアボート要求	*/
#define _IR_POPTI	_IR_E2 + E210		/* E210:オプション設定要求			*/
#define _IR_PSURG	_IR_E2 + E211		/* E211:緊急データ送信要求			*/
#define _IR_PRURG	_IR_E2 + E212		/* E212:緊急データ受信要求			*/
#define _IR_PRCAN	_IR_E2 + E213		/* E213:受信キャンセル要求			*/
#define _IR_POCAN	_IR_E2 + E214		/* E214:緊急データ受信キャンセル要求*/
#define _IR_PATCH	_IR_E2 + E215		/* E215:ＡＴＴＡＣＨ完了			*/
#define _IR_PBIND	_IR_E2 + E216		/* E216:ＢＩＮＤ完了				*/
#define _IR_PLISN	_IR_E2 + E217		/* E217:ＬＩＳＴＥＮ完了			*/
#define _IR_PASY0	_IR_E2 + E218		/* E218:非同期通知要求完了			*/
#define _IR_PDECH	_IR_E2 + E219		/* E219:ＤＥＴＡＣＨ完了			*/
#define _IR_PACPT	_IR_E2 + E220		/* E220:ＡＣＣＥＰＴ完了			*/
#define _IR_PACTP	_IR_E2 + E221		/* E221:パスＡＣＴＩＶＥ通知		*/
#define _IR_PDACP	_IR_E2 + E222		/* E222:パスＤＥＡＣＴ通知			*/
#define _IR_PCDCT	_IR_E2 + E223		/* E223:ｺﾈｸｼｮﾝDEACT完了通知 		*/
/* RESERVE				0x38...0x3F 										*/
#define	_IR_E3		0x40				/* E3??:コネクション制御のＩＲコード*/
#define _IR_CLIST	_IR_E3 + E300		/* E300:ＬＩＳＴＥＮ要求通知		*/
#define _IR_CACTV	_IR_E3 + E301		/* E301:ＡＣＴＩＶＥ要求通知		*/
#define _IR_CCPUT	_IR_E3 + E302		/* E302:電文送信要求通知			*/
#define _IR_CTRED	_IR_E3 + E303		/* E303:電文受信要求通知			*/
#define _IR_CCFRE	_IR_E3 + E304		/* E304:コネクション解放要求通知	*/
#define _IR_CCABT	_IR_E3 + E305		/* E305:コネクションアボート要求通知*/
#define _IR_COCAN	_IR_E3 + E306		/* E306:緊急データキャンセル要求通知*/
#define _IR_CRCAN	_IR_E3 + E307		/* E307:電文受信キャンセル要求通知	*/
#define _IR_COPTI	_IR_E3 + E308		/* E308:オプション設定要求通知		*/
#define _IR_CSURG	_IR_E3 + E309		/* E309:緊急データ送信要求通知		*/
#define _IR_CRURG	_IR_E3 + E310		/* E310:緊急データ受信要求通知		*/
#define _IR_CCDEA	_IR_E3 + E311		/* E311:コネクションＤＥＡＣＴ通知	*/
#define _IR_CSETO	_IR_E3 + E312		/* E312:ＳＥＴＯＰＴ完了			*/
#define _IR_CWRTD	_IR_E3 + E313		/* E313:ｏｓｉｗｒｉｔｄ完了		*/
#define _IR_CREAD	_IR_E3 + E314		/* E314:ｏｓｉｒｅａｄｄ完了		*/
#define _IR_CROOB	_IR_E3 + E315		/* E315:ＲＣＶＯＯＢ完了			*/
#define _IR_CSOOB	_IR_E3 + E316		/* E316:ＳＥＮＤＯＯＢ完了			*/
#define _IR_CASY1	_IR_E3 + E317		/* E317:非同期通知要求完了			*/
#define _IR_CDECH	_IR_E3 + E318		/* E318:ＤＥＴＡＣＨ完了			*/
#define _IR_CABOT	_IR_E3 + E319		/* E319:ＡＢＯＲＴ完了				*/
#define _IR_CDCON	_IR_E3 + E320		/* E320:ＤＩＳＣＯＮＮＥＣＴ完了	*/
#define _IR_CCONN	_IR_E3 + E321		/* E321:ＣＯＮＮＥＣＴ完了			*/
/**************************************/
/* サブＩＲコード定義				  */
/**************************************/
#define _SIR_NULL	0x00				/* サブＩＲコードを使用しない		*/
#define _SIR_XONL	0x01				/* コンテキストのみ解放 			*/
#define _SIR_LONL	0x02				/* ローカルセッションのみ解放		*/
#define _SIR_XADL	0x03				/* ﾛｰｶﾙｾｯｼｮﾝおよびｺﾝﾃｷｽﾄ解放		*/
#define _SIR_OPEN	0x00				/* オープン済み						*/
#define _SIR_HALT	0x01				/* 回線ＤＥＡＣＴ中					*/
#define _SIR_CLOS	0x02				/* クローズ中						*/

/**************************************/
/* ＩＲＢテンプレート（通知ＩＲＢ）   */
/**************************************/
typedef struct {
	long				ih_qlink[2];	/* ＩＲＢヘッダ：キューリンク		*/
	char				ih_bytp;		/* ＩＲＢヘッダ：ＢＹＴＰ			*/
	char				ih_gmid;		/* ＩＲＢヘッダ：ＧＭＩＤ			*/
	char				ih_dmid;		/* ＩＲＢヘッダ：ＤＭＩＤ			*/
	char				ih_omid;		/* ＩＲＢヘッダ：ＯＭＩＤ			*/
	char				ih_ircd;		/* ＩＲＢヘッダ：ＩＲコード 		*/
	char				ih_subcd;		/* ＩＲＢヘッダ：サブＩＲコード 	*/
	short				ih_cond;		/* ＩＲＢヘッダ：完了コード 		*/
	long				ctxtp;			/* コンテキストアドレス   　		*/
	long				msglen; 		/* 受信電文長						*/
	long				msgp;			/* 受信メッセージポインタ			*/
	long				reserve;		/* 予約 							*/
	long				irblinkp;		/* ＩＲＢリンクアドレス 			*/
	long				srctxtp;		/* 発信元コンテキストアドレス		*/
	short				lsno;			/* ＬＳ番号 						*/
	short				deactsts;		/* 障害要因 						*/
	long				ripaddr;		/* リモートインタネットアドレス 	*/
	short				rportno;		/* リモートポート番号				*/
	short				yobi0;			/* 予備（Ｄｏｎ’ｔＣａｒｅ）		*/
	long				yobi1[3];		/* 予備（Ｄｏｎ’ｔＣａｒｅ）		*/
}	MPCIRB0;
/**************************************/
/* ＩＲＢテンプレート（完了ＩＲＢ）   */
/**************************************/
typedef struct {
	long				ih_qlink[2];	/* ＩＲＢヘッダ：キューリンク		*/
	char				ih_bytp;		/* ＩＲＢヘッダ：ＢＹＴＰ			*/
	char				ih_gmid;		/* ＩＲＢヘッダ：ＧＭＩＤ			*/
	char				ih_dmid;		/* ＩＲＢヘッダ：ＤＭＩＤ			*/
	char				ih_omid;		/* ＩＲＢヘッダ：ＯＭＩＤ			*/
	char				ih_ircd;		/* ＩＲＢヘッダ：ＩＲコード 		*/
	char				ih_subcd;		/* ＩＲＢヘッダ：サブＩＲコード 	*/
	short				ih_cond;		/* ＩＲＢヘッダ：完了コード 		*/
	long				ctxtp;			/* コンテキストアドレス   　		*/
	long				result; 		/* リザルト値						*/
	long				reserve;		/* 予約 							*/
	long				rd; 			/* ｒｄ値							*/
	long				irblinkp;		/* ＩＲＢリンクアドレス 			*/
	long				argarea[7]; 	/* システムコールアーギュメント域	*/
}	MPCIRB1;

