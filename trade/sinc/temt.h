/*********************************************************************/
/*	TEMT 幓幪庌 幏幹幊幝幊幪庌 幧 幒幊幙庌幊幚幉										 */
/*********************************************************************/
struct	temtsub	{
	short  temttbno;					/* 幟-幪庌庂 幖幑庌庉幪庌 幘庉幠幊 幋庉幠庁 NO */
	short  temtsub1;					/* 幹幩庌						 */
	short  temteno0;					/* PU0幧 幟幇幪庌庂 幧 幘庉幠幊 幙幊幚幉 NO */
	short  temteno1;					/* PU1幧 幟幇幪庌庂 幧 幘庉幠幊 幙幊幚幉 NO */
									    /*Pu戎规猴负の百猴近(6乖)TD06*/
	long   temtintv;					/* 幘幭幪幍 幖幹幏幜				 */
};
typedef	struct	temtsub	TEMTSUB;
/*********************************************************************/
/*	TEMT 幒幫庌幝 幪庌 幧 幒幊幙庌幊幚幉											 */
/*********************************************************************/
struct	temtpsz	{
	long   temtspid;					/* 幘幭幪幍 幖幏幫庌幝幖				 */
	short  temtseq;						/* 幘庉幷幊 幖庌幷庉幉				 */
	short  temtextp;					/* 幎幐幜幹幊 EMT(EXT) 幋庉幠庁 NO	 */
};
typedef	struct	temtpsz	TEMTPSZ;
