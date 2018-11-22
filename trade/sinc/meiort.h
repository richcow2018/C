/********************************************************/
/* 1995.07.07 LICP-TRADE　返却値変換のコンスタント		*/
/* 		作成者：営業店システム担当　（新藤由美）		*/
/*			故障処理票：ST2911							*/
/*			meio.h内において、変換テーブルをstaticで持っ*/
/*			ていたものを、変更したことに起因する。		*/
/*			実体は、me_pint()に存在する。meio.hでは、ex */
/*			tern で参照する。							*/
/********************************************************/
/*　TRADE LOOP(1jikyoku) RETURN VALUE	*/
#define	TIMERR	0xc2b20000	/* タイマ値が規定外			*/
#define PRMERR	0xc2f10000	/* パラメータエラー			*/
#define	RSPERR	0xc2b00100	/* 異常レスポンス受信	1xx	*/
#define	STSERR	0xc2b30001	/* 論理ﾊﾟｽ未設定			*/
#define	RSTERR	0xc2b00200	/* ﾚｽﾎﾟﾝｽ待ちﾀｲﾏﾀｲﾑｱｳﾄ		*/
#define	DLIERR	0xc2b00300	/* ﾊﾟﾜｰｵﾌｱﾃﾝｼｮﾝ受信			*/
#define	CHNERR	0xc2a10000	/* ループ断を検出した		*/
#define	HRDERR	0xc2800400	/* I/Oﾚｼﾞｽﾀｱｸｾｽ時ﾊﾞｽｴﾗｰ発生	*/
#define	OVFERR	0xc2b00020	/* オーバーフロー			*/
#define	SQCERR	0xc2a00027	/* シーケンスエラー			*/
#define	CHAERR	0xc2f00005	/* 回線未接続によるｷｬﾝｾﾙ	*/
#define	RPNERR	0xc2b30003	/* 論理ﾊﾟｽ番号が違った		*/
#define	RPMERR	0xc2b30002	/* 最大接続論理ﾊﾟｽ数ｵｰﾊﾞｰ	*/
#define	KSFERR	0xc2b20001	/* 回線種別不正				*/

/*　TRADE 4WI/O RETURN VALUE	*/
#define FPMERR	0xc1a20000	/* パラメータエラー			*/

/*  LICP RETURN CODE 				*/
#define	LICP01	0x01000001	/* メッセージ識別子不正		*/
#define	LICP02	0x01000002	/* ﾃﾞｰﾀﾊﾞｯﾌｧ相対ｱﾄﾞﾚｽ不正	*/
#define	LICP03	0x01000003	/* ﾃﾞｰﾀﾊﾞｯﾌｧｻｲｽﾞ不正		*/
#define	LICP04	0x01000004	/* ﾒｯｾｰｼﾞﾀｲﾌﾟ不正			*/
#define	LICP05	0x01000005	/* ﾌｧﾝｸｼｮﾝﾀｲﾌﾟ不正			*/
#define	LICP06	0x01000006	/* ﾊﾟｽID不正				*/
#define	LICP07	0x01000007	/* タイマ値不正				*/
#define	LICP08	0x01000008	/* シーケンスエラー			*/
#define	LICP09	0x01000009	/* 障害中によるキャンセル	*/
#define	LICP0a	0x0100000a	/* 論理ﾊﾟｽ未設定状態		*/
#define	LICP0b	0x0100000b	/* 論理ﾊﾟｽ番号不正			*/
#define	LICP0c	0x0100000c	/* 最大接続論理ﾊﾟｽ数ｵｰﾊﾞｰ	*/
#define	LICP0d	0x0100000d	/* 発着呼識別子不正			*/
#define	LICP0e	0x0100000e	/* 相手ＤＴＥｱﾄﾞﾚｽ長不正	*/
#define	LICP0f	0x0100000f	/* ｺｰﾙﾕｰｻﾞﾃﾞｰﾀ長不正		*/
#define	LICP10	0x01000010	/* ｺｰﾙﾕｰｻﾞﾃﾞｰﾀ内回線種別不正*/
#define	LICP11	0x01000011	/* 最大分割ﾃﾞｰﾀ長不正		*/
#define	LICP12	0x01000012	/* ｳｲﾝﾄﾞｳｻｲｽﾞ不正			*/
#define	LICP13	0x01000013	/* 最大ｺﾈｸｼｮﾝ数ｵｰﾊﾞｰ		*/
#define	LICP50	0x01000050	/* 発呼識別子未サポート		*/
#define	LPERNC	0x02000001	/* 未定義コマンド受信		*/
#define	LPERUR	0x02000002	/* 異常レスポンス受信		*/
#define	LPERSE	0x02000003	/* status error				*/
#define	LPEROV	0x02000004	/* over flow				*/
#define	LPERTO	0x02000005	/* responce time out		*/
#define	X25ERR	0x03000000	/* X.25 error				*/
#define	TCPERR	0x04000000	/* TCP/IP error				*/
#define	DLLERR	0x0a000000	/* data link error			*/
#define	LINERR	0x0b000000	/* line error				*/
#define HADERR	0x0c000000	/* hard error				*/
#define	SYSERR	0x0f000000	/* trade system call error	*/
