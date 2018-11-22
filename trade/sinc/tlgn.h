/*****************************************************************************/
/*                           <TLGN.H>                                        */
/*****************************************************************************/
/*                 TLGN ｺﾍﾞﾂﾌﾞ ﾉ ｺｳｿﾞｳﾀｲ                                     */
/*                 修正　95.9.1　M01 田中宏之                                */
/*                 修正　97.1.7　M02 北西智洋   SSCY0191                     */
/*****************************************************************************/
/*****************************************************************************/

struct  tlgnsub {
        unsigned short  tlgnoptm ;      /* オープンリトライ間隔タイマ       */
        unsigned short  tlgnsyb1 ;      /* サブ共通部予備１                 */
        unsigned long   tlgnsyb2 ;      /* サブ共通部予備２                 */
} ;
typedef struct tlgnsub TLGNSUB ;

struct  tlgnps1 {
        unsigned short  tlgnlgno ;      /* LCGN ﾊﾞﾝｺﾞｳ                      */
        unsigned short  tlgnlcno ;      /* ｼｭｳﾖｳ LCN  ｽｳ                    */
} ;
typedef struct tlgnps1 TLGNPS1 ;

struct  tlgnpsz {
        unsigned short  tlgnlcgn ;      /* LCGN ｽｳ                          */
		unsigned char	tlgnflgs ;		/* 有効／無効フラグ					*/
        unsigned char   tlgnnapo ;      /* ネットワーク管理ＡＰあり/なし    */	
		unsigned short	tlgnlnno ;		/* PU/回線番号						*/
		unsigned char	tlgnx25v ;		/* X.25バージョン 0:80 1:84	     M01*/
		unsigned char	tlgnltyp ;		/* 回線種別 0:専 1:TEL 2:ISDN		*/
		unsigned long	tlgnyob2 ;		/* 予備２							*/
        TLGNPS1         tlgnps1[16] ;   /* LCGN : LCN ｽｳ                    */
} ;
typedef struct tlgnpsz TLGNPSZ ;

