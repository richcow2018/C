/******************< mpcomand.h >********************************************/
/*	データ名 : ﾖｳｷｭｳ / ｵｳﾄｳ ｺﾏﾝﾄﾞ ﾘｮｳｲｷ 									*/
/*	コメント : ﾖｳｷｭｳ / ｵｳﾄｳ ｺﾏﾝﾄﾞ ﾘｮｳｲｷ ｺｳｿﾞｳﾀｲ ﾃｲｽｳ ﾃｲｷﾞ					*/
/*	作成日	 : 1993.11.22													*/
/****************************************************************************/
/*	修正 : １９９６年１１月２６日 営業店ｼｽﾃﾑ担当 米倉 ST4606				*/
/*				要求ｺﾏﾝﾄﾞに｢AP要求識別番号｣追加								*/
/****************************************************************************/
/**************************************/
/* 要求／応答電文コマンド域 		  */
/**************************************/
struct mpcomand{						/*									*/
	char  	 		mpcococd ;			/* コマンドコード 					*/
	char   			mpcokan1 ;			/* 完了コード						*/
	short 			mpcokan2 ;			/* 異常要因 						*/
	char   			mpcotype ;			/* タイプ							*/
	char   			mpcoapcd ;			/* AP要求識別番号					*/
										/* ST4606 予備1を変更				*/
	char   			mpcocanc ;			/* キャンセルコマンドコード 		*/
	char   			mpcocant ;			/* キャンセルタイプ 				*/
	long   			mpcocnnd ;			/* コネクション識別子				*/
	long   			mpcolipa ;			/* ローカルインターネットアドレス	*/
	long   			mpcoripa ;			/* リモートインターネットアドレス	*/
	short  			mpcolpon ;			/* ローカルポート番号				*/
	short  			mpcorpon ;			/* リモートポート番号				*/
	long   			mpcodatp ;			/* データ格納域アドレス　			*/
	short  			mpcodtsz ;			/* データ長 						*/
	char   			mpcopthf ;			/* コネクション状態 				*/
	char   			mpcoyob2 ;			/* 予備２							*/
	char   			mpcooptk ;			/* オプション種別					*/
	char   			mpcooptf ;			/* オプション指定フラグ 			*/
	unsigned short  mpcooptv ;			/* オプション指定値 				*/
	long   			mpcotsp1 ;			/* ＴＳＰ使用域１					*/
	long   			mpcotsp2 ;			/* ＴＳＰ使用域２　 				*/
	long   			mpcotsp3 ;			/* ＴＳＰ使用域３					*/
};										/*									*/
typedef struct mpcomand MPCOMAND ;		/*									*/

/**************************************/
/* 電文サイズ						  */
/**************************************/
#define  MPCMSIZE	sizeof(MPCOMAND)	/* 要求コマンド域サイズ 			*/
#define  MPRCMSZ1	sizeof(MPCOMAND)	/* 応答コマンド域サイズ 			*/

/**************************************/
/* コマンドコード					  */
/**************************************/
#define   CMDCOPN	 0x01				/* me_copn							*/
#define   CMDCCLS	 0x02				/* me_ccls							*/
#define   CMDTRED	 0x03				/* me_tred							*/
#define   CMDCPUT	 0x04				/* me_cput							*/
#define   CMDTCNT	 0x05				/* me_tcnt							*/
#define   CMDTCAN	 0x06				/* me_tcan							*/


/**************************************/
/* コマンドタイプ					  */
/**************************************/
#define   TYPTKOSY	  0x01				/* 故障通知要求 					*/
#define   TYPTRCOV	  0x02				/* 故障回復待ち要求 				*/
#define   TYPTACTV	  0x03				/* ＡＣＴＩＶＥ要求 				*/
#define   TYPTLIST	  0x04				/* ＬＩＳＴＥＮ要求 				*/
#define   TYPTDCNN	  0x05				/* コネクション解放要求 			*/
#define   TYPTABOT	  0x06				/* コネクションアボート要求 		*/
#define   TYPTSOPT	  0x07				/* オプション設定要求				*/
#define   TYPTSOOB	  0x08				/* 緊急データ送信要求				*/
#define   TYPTROOB	  0x09				/* 緊急データ受信要求				*/

/**************************************/
/* オプション種別					  */
/**************************************/
#define   SOKEEPAL	   0x03 			/* コネクション保存オプション		*/
#define   SODNTRTE	   0x04 			/* 経路選択オプション				*/
#define   SOLINGER	   0x07 			/* リンガーオプション				*/
#define   SOOOBINL	   0x08 			/* 緊急データオプション 			*/
#define   SOSNDBUF	   0x09 			/* 送信バッファオプション			*/
#define   SORCVBUF	   0x0a 			/* 受信バッファオプション			*/
/**************************************/
/* オプション指定					  */
/**************************************/
#define   SOPTFLG	   0x01 			/* オプション設定／解除フラグ		*/

/**************************************/
/* コネクション状態 				  */
/**************************************/
#define   FLGRVFIN	   0x01 			/* 受信側のシャットダウン（ＦＩＮ受 */
										/* 信）を検出しました				*/
/**************************************/
/* 異常要因 						  */
/**************************************/
#define   ERRNORML	0x0000				/* 正常終了							*/

#define   ERRPHARD	0x0101				/* ハ−ド故障						*/
#define   ERRPKIRI	0x010C				/* 系切り替え						*/
#define   ERRPWAIT	0x010D				/* 待機中							*/

#define   ERRLNCNN	0x0332				/* 該当コネクションなし 			*/
#define   ERRLREFU	0x0333				/* コネクションの設定が拒否された	*/
#define   ERRLAUSE	0x0334				/* アドレスは既に使用されている 	*/
#define   ERRLANAV	0x0335				/* アドレスの使用が不可能			*/
#define   ERRLNDWN	0x0336				/* ネットワークがダウン 			*/
#define   ERRLNURH	0x0337				/* ネットワークへの到達不可能		*/
#define   ERRLHURH	0x0338				/* ホストの到達不可能				*/
#define   ERRLSHDN	0x0339				/* 既にｺﾈｸｼｮﾝはｼｬｯﾄﾀﾞｳﾝ済み 		*/
#define   ERRLTOUT	0x033A				/* コネクションのタイムアウト発生	*/
#define   ERRLCABT	0x033B				/* コネクションがアボートした		*/
#define   ERRLCRST	0x033C				/* コネクションがリセットされた 	*/
#define   ERRLNPTH	0x033d				/* 該当論理パスなし（ﾊﾟﾗﾒｰﾀｴﾗｰ）	*/

#define   ERRINTOP	0x0502				/* 未オープン						*/
#define   ERRINOPN	0x0503				/* オ−プン処理中					*/
#define   ERRICLOS	0x0504				/* クロ−ズ処理中					*/
#define   ERRIOPEN	0x0505				/* オ−プン済						*/
#define   ERRIPARM	0x0506				/* パラメ−タエラ− 				*/
#define   ERRIDUPR	0x0507				/* 二重発行エラー					*/
#define   ERRILNUM	0x0530				/* 回線正常 						*/
#define   ERRIFREE	0x0540				/* コネクション解放処理中			*/
#define   ERRIABOT	0x0541				/* コネクションアボート処理中		*/
#define   ERRICLWT	0x0542				/* クローズ待ち 					*/
#define   ERRINACT	0x0544				/* ＡＣＴＩＶＥ要求受付不可 		*/
#define   ERRINLST	0x0545				/* ＬＩＳＴＥＮ要求受付不可 		*/
#define   ERRINOPT	0x0546				/* オプション設定不可				*/
#define   ERRINROB	0x0547				/* 緊急データ受信不可				*/
#define   ERRIECMD	0x0548				/* コマンドエラー（ﾊﾟﾗﾒｰﾀｴﾗｰ）		*/

#define   ERRRCANC	0x0601				/* キャンセルによる回収 			*/
#define   ERRRFREE	0x0610				/* コネクション解放要求による回収	*/
#define   ERRRABOT	0x0611				/* ｺﾈｸｼｮﾝｱﾎﾞｰﾄ要求による回収		*/

#define   ERRNGCAN	0x0613				/* キャンセル失敗					*/

#define   ERRKPCKG	0x0F02				/* パッケ−ジ未実装 				*/
#define   ERRKBUFF	0x0F04				/* ＯＳ資源不足 					*/
#define   ERRKSDOV	0x0F05				/* 送信要求数オ−バ−				*/
#define   ERRKRVOV	0x0F06				/* 受信要求数オ−バ−				*/
#define   ERRKLSTN	0x0F07				/* ＬＩＳＴＥＮ要求数オーバー		*/
