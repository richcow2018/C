/****************************************************************************/
/* ＜対象業務名＞					運転管理業務							*/
/* ＜対象業務ＩＤ＞					ＯＣＰ（ＳＣＰ）						*/
/* ＜サービス項目名＞														*/
/* ＜サービス項目ＩＤ＞														*/
/* ＜モジュール名＞															*/
/* ＜モジュールＩＤ＞				ｍｓ．ｈ								*/
/* ＜モジュール通番＞														*/
/*--------------------------------------------------------------------------*/
/* ＜適用機種＞						ＡＣＥ									*/
/* ＜適用ＯＳ＞						ＴＲＡＤＥ								*/
/* ＜開発環境＞						ＳＵＮ　ＳＰＡＲＣ−ＩＰＸ				*/
/* ＜記述言語＞						Ｃ言語									*/
/* ＜モジュール形態＞				ヘッダファイル							*/
/* ＜機能区分＞																*/
/* ＜対象データ＞															*/
/* ＜工程・階層区分＞														*/
/*--------------------------------------------------------------------------*/
/* ＜開発システム名＞				ＡＣＥ−ＳＭＰシステム					*/
/* ＜開発システム番号＞				５７２６０１４０２１００				*/
/*--------------------------------------------------------------------------*/
/* ＜開発担当者名＞					営業点システム担当						*/
/* ＜電話番号＞						169-3573(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/* ＜設計者名＞						高橋　智彦								*/
/* ＜設計年月日＞					１９９４年　１月１０日					*/
/* ＜設計修正者名＞															*/
/* ＜設計修正年月日及び修正ＩＤ＞											*/
/*--------------------------------------------------------------------------*/
/* ＜ソース作成者名＞				高橋　智彦								*/
/* ＜ソース作成年月日＞				１９９４年　１月２１日					*/
/* ＜ソース修正者名＞														*/
/* ＜ソース修正年月日及び修正ＩＤ＞											*/
/*--------------------------------------------------------------------------*/
/* ＜見積ステップ数＞						ステップ						*/
/*--------------------------------------------------------------------------*/
/* ＜機能概要＞																*/
/*--------------------------------------------------------------------------*/
/* ＜呼出形式＞																*/
/* ＜引数＞																	*/
/* ＜返却値＞																*/
/*--------------------------------------------------------------------------*/
/* ＜入出力データ構成＞														*/
/* ＜制限事項＞																*/
/* ＜使用外部モジュールＩＤ＞												*/
/* ＜呼出モジュールＩＤ＞													*/
/****************************************************************************/
/*3456789*123456789*123456789*123456789*/


/****************************************************************************/
/*	返却値																	*/
/****************************************************************************/
#define	MSNORMAL	0L					/* 正常終了							*/
#define	MSSNDNML	1L					/* 正常送信							*/
#define	MSTIHNML	2L					/* 正常退避							*/
#define	MSMGED		3L					/* 正常メッセージ編集済				*/
#define	MSPRED		4L					/* メッセージ出力済					*/
#define	MSMOUTOK	5L					/* メッセージ出力可能				*/
#define	MSMOUTNG	6L					/* メッセージ出力不可能				*/
#define	MSEDTERR	7L					/* メッセージ編集不可能				*/
#define	MSEEACCV	-51L				/* アドレス異常						*/
#define	MSEEWKEX	-52L				/* 作業域確保不能					*/
#define	MSEEIMPI	-53L				/* メイルボックス不正				*/
#define	MSEEIPOL	-54L				/* プールバッファ不正				*/
#define	MSIVPARM	-55L				/* パラメータエラー					*/
#define	MSEENACC	-56L				/* アクセス権無						*/
#define	MSEENEXS	-57L				/* メイルボックス無					*/
#define	MSEENFND	-58L				/* 自プロセス以外プールバッファ指定	*/
#define	MSSRCOUT	-59L				/* サーチアウト						*/
#define	MSIFAERR	-60L				/* インタフェースエラー				*/
#define	MSTIMOUT	-61L				/* タイムアウト						*/
#define	MSSNDERR	-62L				/* 異常送信							*/
#define	MSTBLERT	0xF5770001			/* 該当テーブル無					*/
#define	MSALLENT	0xF5780001			/* テーブル全てを使用中				*/

#define	MSEDITER	0xF6310100			/* ｍｄ＿ｃｅｄｔエラー				*/
#define	MSIVPAED	0xF6310100			/* パラメータエラー					*/
#define	MSNOTRED	0xF6310200			/* 受付不可							*/
#define	MSTBLEED	0xF6310300			/* テーブル矛盾						*/
#define	MSPBUFED	0xF6310400			/* バッファ確保異常					*/
#define	MSOVREED	0xF6310500			/* 登録数オーバー					*/
#define	MSDIVSED	0xF6310600			/* シーケンスエラー					*/
#define	MSINVEED	0xF6310700			/* 登録無効							*/
#define	MSITFCED	0xF6E00000			/* インタフェースエラー				*/

#define	MSCPUTER	0xF6320100			/* ｍｄ＿ｃｐｕｔエラー				*/
#define	MSNOTRPU	0xF6320100			/* 受付不可							*/
#define	MSMSNDPU	0xF6320200			/* 送信異常							*/
#define	MSTBLEPU	0xF6320300			/* テーブル矛盾						*/
#define	MSPBUFPU	0xF6320400			/* バッファ確保異常					*/
#define	MSIFAEPU	0xF6320500			/* インタフェースエラー				*/
#define	MSOTHDPU	0xF6320601			/* 相手系ダウン中					*/
#define	MSITFCPU	0xF6E00100			/* インタフェースエラー				*/

#define	MSNODERU	0XF8790001			/**/
#define	MSINFERU	0xF8520001			/* インフォメーションエラー			*/
#define	MSPARMDC	0xF23A0000			/* データ変換異常終了				*/
#define	MSTBLERF	0xFA770001			/* テーブル矛盾						*/
#define	MSINFERA	0xF1520001			/* インフォメーションエラー			*/

#define	MSCVDFCD	0x84330200			/* サイズ不足						*/
#define	MSCVRLNG	0x84330300			/* 符号拡張エラー					*/
#define	MSCVFOLG	0x84330400			/* 符号拡張エラー					*/
#define	MSCVIFER	0x84E00200			/* インタフェースエラー				*/

#define	MSRCTOVR	0x85780001			/* 個別部全て使用中					*/
#define	MSRCTERR	0x85770000			/* 該当個別部無し					*/

#define	MSOSCRER	0x85190100			/* ｏｓｃｒｅｐｒ異常				*/
#define	MSCPACCV	0x85190100			/* アドレス異常						*/
#define	MSCPEXST	0x85190200			/* 指定プロセスが既に存在			*/
#define	MSCPFAIL	0x85190300			/* 子プロセス異常終了				*/
#define	MSCPIPID	0x85190400			/* ｐｉｄ不当						*/
#define	MSCPIPIB	0x85190500			/* パラメータ不当					*/
#define	MSCPIPRI	0x85190600			/* 優先度不当						*/
#define	MSCPIRNK	0x85190700			/* ランク不当						*/
#define	MSCPNEXS	0x85190800			/* プロセステーブル不在				*/
#define	MSCPOSPU	0x85190900			/* 他ｐｕへの要求					*/
#define	MSCPOUNI	0x85190A00			/* 他装置への要求					*/
#define	MSCPWKEX	0x85190B00			/* システム作業領域確保できず		*/
#define	MSCPIFER	0x85E00300			/* インタフェースエラー				*/

#define	MSOSWCER	0x86780001			/* ｏｓｗｃｈｌｄｒエラー			*/
#define	MSRCTOV1	0x86780001			/* 個別部全て使用中					*/
#define	MSRCTER1	0x86770000			/* 該当個別部無						*/

#define	MSCPACC1	0x86190100			/* アドレス異常						*/
#define	MSCPEXS1	0x86190200			/* 指定プロセスが既に存在			*/
#define	MSCPFAI1	0x86190300			/* 子プロセス異常終了				*/
#define	MSCPIPI1	0x86190400			/* ｐｉｄ不当						*/
#define	MSCPIPM1	0x86190500			/* パラメータ不当					*/
#define	MSCPIPR1	0x86190600			/* 優先度不当						*/
#define	MSCPIRN1	0x86190700			/* ランク不当						*/
#define	MSCPNEX1	0x86190800			/* プロセステーブル不在				*/
#define	MSCPOSP1	0x86190900			/* 他ｐｕへの要求					*/
#define	MSCPOUN1	0x86190A00			/* 他装置への要求					*/
#define	MSCPWKE1	0x86190B00			/* システム作業領域確保できず		*/
#define	MSCPIFE1	0x86E00300			/* インタフェースエラー				*/

#define	MSWCACCV	0x851A0100			/* 終了情報確保できず				*/
#define	MSWCIPID	0x851A0200			/* ｐｉｄ不当						*/
#define	MSWCIVRD	0x851A0300			/* ｒｄ不当							*/
#define	MSWCNCHL	0x851A0400			/* 子プロセスではない				*/
#define	MSWCNEXS	0x851A0500			/* 指定プロセスが無い				*/
#define	MSWCOSPU	0x851A0600			/* 他ｐｕへの要求					*/
#define	MSWCOUNI	0x851A0700			/* 他装置への要求					*/
#define	MSWCUSED	0x851A0800			/* ｒｄ使用中						*/
#define	MSWCWKEX	0x851A0900			/* システム作業領域確保できず		*/
#define	MSWCIFER	0x85E00400			/* インタフェースエラー				*/

#define	MSWCACC1	0x861A0100			/* 終了情報確保できず				*/
#define	MSWCIPI1	0x861A0200			/* ｐｉｄ不当						*/
#define	MSWCIVR1	0x861A0300			/* ｒｄ不当							*/
#define	MSWCNCH1	0x861A0400			/* 子プロセスではない				*/
#define	MSWCNEX1	0x861A0500			/* 指定プロセスが無い				*/
#define	MSWCOSP1	0x861A0600			/* 他ｐｕへの要求					*/
#define	MSWCOUN1	0x861A0700			/* 他装置への要求					*/
#define	MSWCUSE1	0x861A0800			/* ｒｄ使用中						*/
#define	MSWCWKE1	0x861A0900			/* システム作業領域確保できず		*/
#define	MSWCIFE1	0x86E00400			/* インタフェースエラー				*/

#define	MSGCELER	0x85350100			/* ｍｉ＿ｇｃｅｌエラー				*/
#define	MSGCPARM	0x85350100			/* パラメータエラー					*/
#define	MSGCTEXT	0x85350200			/* エリア拡張不能					*/
#define	MSGCMANG	0x85350300			/* エリア管理部不当					*/
#define	MSGCTDEF	0x85350400			/* エリア無し						*/

#define	MSGCPAR1	0x86350100			/* パラメータエラー					*/
#define	MSGCTEX1	0x86350200			/* エリア拡張不能					*/
#define	MSGCMAN1	0x86350300			/* エリア管理部不当					*/
#define	MSGCTDE1	0x86350400			/* エリア無し						*/


/****************************************************************************/
/*	メッセージ出力区分														*/
/****************************************************************************/
#define	MSEDIRI		0x10				/* ﾍﾝｼｭｳ ｲﾗｲ                     */
#define	MSEDSUM		0x20				/* ﾍﾝｼｭｳ ｽﾞﾐ                     */
#define	MSEDSUMR	0x30				/* 編集済(ＴＲＡＤＥ)				*/


/****************************************************************************/
/*	メッセージ出力パターン													*/
/****************************************************************************/
#define	MSSYSIO		0x10				/* ｼｽﾃﾑ ﾃﾞ ｷﾒﾀ                      */
#define	MSNTCSGP	0x20				/* ｼﾃｲｸﾞﾙｰﾌﾟ ｶﾂ ｼﾃｲ ｻﾌﾞｸﾞﾙｰﾌﾟ ﾉ ﾀﾞｲﾋ*/
#define	MSNTCGPD	0x30				/* NTC ﾅｲ ｽﾍﾞﾃﾉ ｻﾌﾞｸﾞﾙｰﾌﾟ ﾉ ﾀﾞｲﾋｮｳ  */
#define	MSNTCNDH	0x40				/* NTC ﾅｲ ﾉ ﾀﾞｲﾋｮｳ   i/o            */
#define	MSNTCKDH	0x50				/* NTC ｶﾝ ﾉ ﾀﾞｲﾋｮｳ   i/o            */
#define	MSNTCSDH	0x60				/* ｾｯﾁﾃﾝ  ﾉ ﾀﾞｲﾋｮｳ   i/o            */
