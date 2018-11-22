/*********************************************************************/
/*	TWMT ｻﾌﾞ ｷﾖｳﾂｳﾌﾞ ﾉ ｺｳｿﾞｳﾀｲ										 */
/*********************************************************************/
struct	twmtsub	{
	short	twmtpu1;					/* PU1用WMT先頭ｴﾝﾄﾘ番号	 TD33*/
	short	twmtsub1;					/* ﾖﾋﾞ						 */
								/* 動的テーブル削除の為削除(2行) TD60*/
};
typedef	struct	twmtsub	TWMTSUB;
/*********************************************************************/
/*	TWMT ｺﾍﾞﾂ ﾌﾞ ﾉ ｺｳｿﾞｳﾀｲ											 */
/*********************************************************************/
struct	twmtpsz	{
								/* 動的テーブル削除の為削除(2行) TD60*/
	short	twmtvmtp;					/* ｼﾖｿﾞｸﾎﾞﾘﾕ-ﾑ VMT ｴﾝﾄﾘ NO   */
	short	twmtsgtp;					/* ｼﾖｿﾞｸｸﾞﾙ-ﾌﾟ SGT ｴﾝﾄﾘ NO   */
	unsigned long	twmtdate;			/* ﾎｿﾞﾝ ｷｼﾞﾂ (YYYYMMDD)		 */
	char	twmtname[16];				/* ﾛﾝﾘ ﾌｱｲﾙﾒｲ				 */
	unsigned char	twmtstat;      		/* 個別部 ｽﾃ-ﾀｽ	        		 */
									/*   11.. ....  処理中 ﾌﾗｸﾞ  	 */
									/*     '10'  使用中(処理中)  	 */
									/*     '01'  創成中(処理中) 	 */
									/*     '00'  未使用(未処理) 	 */
	char	twmtoth1[3];    			/* ﾖﾋﾞ                       */
};
typedef	struct	twmtpsz	TWMTPSZ;
/*********************************************************************/
/*	ﾃ-ﾌﾞﾙ ﾅｲ ｺ-ﾄﾞ ﾃｲｷﾞ      										 */
/*********************************************************************/
#define		TWMTOPON	0x80			/* 個別部ｽﾃｰﾀｽ "使用中"		 */
#define		TWMTOPCR	0x40			/* 個別部ｽﾃｰﾀｽ "創成中" TD33 */
#define		TWMTOPOF	0x00			/* 個別部ｽﾃｰﾀｽ "未使用" TD33 */
#define		TWMTDCLS	0x00000000		/* 保存期日 CLOSE時削除	TD31 */
#define		TWMTDSYS	0x99999999		/* 保存期日 ｼｽﾃﾑ終了時削除 TD31*/
