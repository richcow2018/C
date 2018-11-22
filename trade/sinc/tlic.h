/****************************************************************************/
/*																			*/
/*					tlic.h													*/
/*																			*/
/*			TLIC テーブル フォーマット	 02.12.18	作成者	寺田 俊彦		*/
/*																			*/
/****************************************************************************/

typedef	struct	mdlicsub{
				short	tlicmaxt;		/* 最大端末数						*/
				char	tlicmaxp;		/* 最大論理パス数					*/
				char	tlicdcon;		/* 切断時操作 1:ABORT 2:DETACH		*/
				long	tlictcbs;		/*下位モジュールコール用バッファサイズ*/
				long	tlichrtm;		/* 強制閉塞要求発行後の応答待ちタイマ */
}TLICSUB;

typedef	struct	mdlicind{
	unsigned	short	tlicport;		/* 当該LICPで使用するポート番号 	*/
				short	tliclgno;		/* 論理パスグループ番号				*/
				long	tlicpcnt;		/* 強制閉塞要求の発行数−応答受信数	*/
}TLICIND;

