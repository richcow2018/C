/* meiolpb.h	ﾌﾟﾛﾄｺﾙ情報ﾌｧｲﾙ						  */
/* 1994.12.19	作成者　西山伸						  */
/* 1995.5.18    dummyより変更 					  M01 */
/* 1995.6.29    ST2866 バグ修復				      M02 */
/* 1995.7.24    ST2866 me_cgetのLICPﾘｰﾄﾞのバグ改修。  */
/*												  M03 */
/* 1995.7.25    ST2772   4w on X.25のｽﾃｰﾀｽ追加	  M04 */
/* 1995.11.09   SSCY0124 4w on X.25ireadのrd設定  M05 */
/* 1995.11.09   SSCY0124 4w on X.25ireadのrd設定  M05 */
/* 1995.11.30   SSCY0121 4W-NTMonX.25を追加する	  M06 */
/* 1995.11.30   SSCY0121 4W-NTMonX.25のリード長・	  */
/*					ライト長をセットする		  M07 */
/* 1996.01.30   SSCY0121 4W on X.25ﾗｲﾄﾘﾄﾗ回数	  M08 */
/* 1996.01.30   ST3972       dummyを追加する	  M09 */
/* 1996.02.27   ST4087   4W 送受信ｽﾃｰﾀｽの追加	  M10 */
/* 1997.04.30   ST4666   4W-NTMonX.25ｸﾛｰｽﾞﾌﾗｸﾞ追加M11 */
/* 1997.08.18   ST4873   ｸﾛｰｽﾞﾌﾗｸﾞ→ｾｯﾄﾌﾗｸﾞに変更 M12 */

#define uchar  unsigned char
#define ushort unsigned short
#define ulong  unsigned long
#define MELDRV   0x01
#define ME4DRV   0x02
#define MELONX25 0x03
#define MELONLAN 0x04
#define ME4ONX25 0x05
#define ME4NONX25 0x06	/* 4W-NTM on X.25追加					    M06 */

/* M03追加　LICPﾘｰﾄﾞのヘッダ部size */
#define	MELONXHEAD	7					/*                          M03 */
#define MELONLHEAD	23					/*                          M03 */

struct meiolpb {
	char	bname[4];	/* 常に"MEIO"とする。							*/
	uchar	bottom;		/* {MELDRV|ME4DRV|MELONX25|MELONLAN|ME4ONX25}	*/
	char	dummy1[2];	/* 予備１ 										*/
	char	setflg;		/* ｾｯﾄﾌﾗｸﾞ(s4opにｾｯﾄしたら0x10) 			 M12*/
	long	fd;			/* ファイル記述子／ＬＩＣＰ使用時パスＩＤ		*/
	ulong	licpid;		/* ＬＩＣＰプロセスＩＤ							*/
	uchar	ddten;		/* 相手ＤＴＥアドレス桁数						*/
	uchar	ddteadr[8];	/* 相手ＤＴＥアドレス							*/
	uchar	ipksiz;		/* 発呼者送信パケットサイズ						*/
	uchar	rpksiz;		/* 着呼者送信パケットサイズ						*/
	uchar	iwdsiz;		/* 発呼者ウインドウサイズ						*/
	uchar	rwdsiz;		/* 着呼者ウインドウサイズ						*/
	uchar	fstslct;	/* ファストセレクト要求							*/
	uchar	account;	/* 着信課金										*/
	uchar	irtpclas;	/* 発（着）呼者スループットクラス				*/
	uchar	iexadn;		/* 発アドレス拡張桁数							*/
	uchar	iexadr[20];	/* 発アドレス拡張								*/
	uchar	rexadn;		/* 着アドレス拡張桁数							*/
	uchar	rexadr[20];	/* 着アドレス拡張								*/
	uchar	gwproto;	/* 中継先ﾌﾟﾛﾄｺﾙ {GWｱﾗｲﾊﾞﾙ/TCPIP/HDLCﾙｰﾌﾟ/4W}	*/
	uchar	gwlno;		/* ＧＷ内回線番号								*/
	ulong	portnum;	/* 端末ﾛｰｶﾙｱﾄﾞﾚｽ(TCPﾎﾟｰﾄ番号) ／ DLｱﾄﾞﾚｽ		*/
	char	lpn;		/* 論理パス番号									*/
	uchar	prefix;		/* 4WI/Oプレフィクス						M01	*/
	ushort	lgln;		/* LCGN+LCN番号								M01	*/
	long	aplopt;		/* 運用システムオプション						*/
	uchar	ccdctm;		/* ｺﾈｸﾄ/ﾃﾞｨｽｺﾈｸﾄのﾚｽﾎﾟﾝｽ待ちﾀｲﾏ (op/cl)			*/
	char	st_4wX25;	/* 4W on X.25のｽﾃｰﾀｽ						M04 */
	short	seglen;		/* 最大分割データ長								*/
	char	l4wsiz;		/* 装置制御ウインドウサイズ						*/
	char	x25hc;		/* X25の時、発呼(0x01)か着呼(0x02)か			*/
	short	lpteno;		/* TLPTエントリ番号			                M02 */
	long	poolid;		/* プール識別子									*/
	long	us4wread;	/* 4WonX.25の場合のosireadのrd				M05 */
	long	us4wrdad;	/* 4WonX.25の場合のosireadのﾌﾟｰﾙﾊﾞｯﾌｧｱﾄﾞﾚｽ  M05 */
	long	rewrcnt;	/* 4W-NTM on X.25のリード長・ライト長格納	M07 */
	short	retry;		/* 4W-NTM on X.25のライトのリトライ回数		M08 */
	char	rs4w;		/* 4WonX.25ﾘｰﾄﾞｺﾏﾝﾄﾞの送受信ｽﾃｰﾀｽ			M10 */
	char	ws4w;		/* 4WonX.25ﾗｲﾄｺﾏﾝﾄﾞの送受信ｽﾃｰﾀｽ			M10 */
#ifdef OLD
	short	dumm2;		/* dammy									M10 */
#endif
};
typedef struct meiolpb MEIOLPB;
