/******************************************/
/*                              V/R = 0/0 */
/*               meretv.h                 */
/*                                        */
/*            SMPｺｰﾙ(EDP)ﾍﾝｷｬｸﾁ           */
/*           １９９５年０４月２２日  M01  */
/*                   仕様変更対応(xxxxxx) */
/*           1995年04月27日          M02  */
/*                   設定値変更(ST2607)   */
/* 修正日：１９９５年６月２０日        M03*/
/* 氏名　：新藤由美					      */
/*	   仕様変更要求書：SSCY0079		 	  */
/*     ﾒﾓﾘﾊﾟｯﾁｴﾗｰを追加した				  */
/*                                        */
/* 修正日：１９９５年１０月１８日      M04*/
/* 氏名　：新藤由美					      */
/*	   仕様変更要求書：SSCY0092		 	  */
/*	   LICPへのﾒｯｾｰｼﾞ送信失敗を追加		  */
/* 修正日：１９９６年　５月３１日      M05*/
/* 氏名　：米倉　洋昭				      */
/*	   故障処理票：ＳＴ４３８１		 	  */
/*	   返却値の見直し		  			  */
/*                                        */
/******************************************/

#define  MENORMAL    0l      	/*  ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ　       */
#define  MEIVPARM   0xffff0001	/*  ﾊﾟﾗﾒｰﾀ ｴﾗｰ            */
#define  MEDUBREQ   0xffff0002	/*  ﾆｼﾞｭｳ ﾖｳｷｭｳ　         */
#define  MENOTRCV   0xffff0003	/*  ｳｹﾂｹ ﾌｶ      　       */
#define  MEMSNDER   0xffff0004	/*  ﾒｯｾｰｼﾞ ｿｳｼﾝ ｲｼﾞｮｳ     */
#define  METBLERR   0xffff0005	/*  ﾃｰﾌﾞﾙ ｴﾗｰ       　    */
#define  MEPBUFER   0xffff0006	/*  ﾌﾟｰﾙﾊﾞｯﾌｧ ｶｸﾎ ｲｼﾞｮｳ   */
#define  MEOVRENT   0xffff0007	/*  ﾄｳﾛｸｽｳ ｵｰﾊﾞｰ          */
#define  MEIFAERR   0xffff0008	/*  ｲﾝﾀｰﾌｪｰｽ ｴﾗｰ      　  */
#define  MEOVRLNG   0xffff0010	/*  ｻｲｽﾞ ﾌﾞｿｸ             */
#define  MEOTHDWN   0xffff0012	/*  ﾀｹｲ ｼｮｳｶﾞｲ            */
#define  MEHRDERR   0xffff0014	/*  ﾊｰﾄﾞ ｼｮｳｶﾞｲ           */
#define  MECHBLOK   0xffff0015	/*  ﾁｬﾈﾙ ﾍｲｿｸ ﾁｭｳ         */
#define  MEDATERR   0xffff0016	/*  ﾖｳｷｭｳ ｼﾞｮｳﾎｳ ﾌｾｲ      */
#define  MENOTUSE   0xffff001c	/*  DCP ｼﾖｳ ﾌｶ            */
#define  MENOTACC   0xffff001e	/*  ｱｸｾｽｹﾝ ﾅｼ             */
								/* memo ffff001fは下	  */
#define  MEINVMIA   0xffff0020	/*  MIA ｾｯﾃｲ ﾅｲﾖｳ ﾌｾｲ     */
#define  MEMISZER   0xffff0021	/*  MIA ｻｲｽﾞ ﾌﾞｿｸ         */
#define  MERSSZER   0xffff0022	/*  ｵｳﾄｳﾘｮｳｲｷ ｻｲｽﾞ ﾌﾞｿｸ   */
#define  MEIVPROC   0xffff0023	/*  指定ﾌﾟﾛｾｽ誤り     M02 */

/**********************************************************/
/* ファイル転送機能の追加により下記定義を追加             */
/*                             １９９４．１０．２１       */
/**********************************************************/
#define  MEINVLPN   0xffff0024          /* 論理ﾊﾟｽ識別名不正                */
#define  MEINVSFL   0xffff0025          /* 転送元ﾌｧｲﾙ名不正                 */
#define  MEINVDFL   0xffff0026          /* 転送先ﾌｧｲﾙ名不正                 */
#define  MEIFEXIS   0xffff0027          /* ﾌｧｲﾙ既存時処理指定不正           */
#define  MEINTVAL   0xffff0028          /* 転送ｲﾝﾀｰﾊﾞﾙﾀｲﾏ値不正             */
#define  MEINVPGN   0xffff0029          /* 起動ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名異常            */
#define  MELPTUSE   0xffff002A          /* TLPT個別部ｽﾃｰﾀｽ不正　            */
#define  MEFAPUSE   0xffff002B          /* TFAP個別部ｽﾃｰﾀｽ不正　            */
#define  MEFACUSE   0xffff002C          /* TFAC個別部ｽﾃｰﾀｽ不正　            */
#define  MEFAXUSE   0xffff002D          /* TFAX個別部ｽﾃｰﾀｽ不正　            */
#define  MEFALUSE   0xffff002E          /* TFAL個別部ｽﾃｰﾀｽ不正　            */
#define  MEFAPAPI   0xffff002F          /* APIｶﾃｺﾞﾘ不正                     */
#define  MEFACGRP   0xffff0030          /* TRADE処理種別不正                */
#define  MEFCPBGT   0xffff0031          /* ｺﾏﾝﾄﾞ起動ﾊﾟﾗﾒｰﾀ編集　　          */
                                        /* ﾊﾞｯﾌｧ確保異常                    */
/* #define  MESNAMCP   0xffff0032          転送元ﾌｧｲﾙ名ｺﾋﾟｰ異常             */
										/* M05 返却値の見直し				*/
/* #define  MEDNAMCP   0xffff0033          転送先ﾌｧｲﾙ名ｺﾋﾟｰ異常             */
										/* M05 返却値の見直し				*/
/* #define  MELPNMCP   0xffff0034          特殊ﾌｧｲﾙ名ｺﾋﾟｰ異常               */
										/* M05 返却値の見直し				*/
/* #define  MEINTMCV   0xffff0035          転送ｲﾝﾀｰﾊﾞﾙﾀｲﾏ変換異常           */
										/* M05 返却値の見直し				*/
/* #define  MEEXISCV   0xffff0036          ﾌｧｲﾙ既存時指定変換異常           */
										/* M05 返却値の見直し				*/
#define  MEFTCRET   0xffff0037          /* FTOS生成異常                     */
#define  MEFWCHLD   0xffff0038          /* FTOS終了通知要求異常             */
#define  MEBUFCLR   0xffff0039          /* ﾌﾟｰﾙﾊﾞｯﾌｧｸﾘｱ異常                 */
/* #define  MEMCCOPY   0xffff003A          文字列ｺﾋﾟｰ異常                   */
										/* M05 返却値の見直し				*/
/* #define  MEIOTYCV   0xffff003B          I/O種別変換異常                  */
										/* M05 返却値の見直し				*/
/* #define  MELPNOCV   0xffff003C          論理ﾊﾟｽ番号変換異常              */
										/* M05 返却値の見直し				*/
/* #define  MEDDTNCV   0xffff003D          DTEｱﾄﾞﾚｽ桁数変換異常             */
										/* M05 返却値の見直し				*/
/* #define  MEIPKSCV   0xffff003E          発呼者送信ﾊﾟｹｯﾄｻｲｽﾞ変換異常      */
										/* M05 返却値の見直し				*/
/* #define  MERPKSCV   0xffff003F          着呼者送信ﾊﾟｹｯﾄｻｲｽﾞ変換異常      */
										/* M05 返却値の見直し				*/
/* #define  MEIWDSCV   0xffff0040          発呼者送信ｳｨﾝﾄﾞｳｻｲｽﾞ変換異常     */
										/* M05 返却値の見直し				*/
/* #define  MERWDSCV   0xffff0041          着呼者送信ｳｨﾝﾄﾞｳｻｲｽﾞ変換異常     */
										/* M05 返却値の見直し				*/
/* #define  MEFSSLCV   0xffff0042          ﾌｧｽﾄｾﾚｸﾄ要求変換異常             */
										/* M05 返却値の見直し				*/
/* #define  MEACCOCV   0xffff0043          着信課金変換異常                 */
										/* M05 返却値の見直し				*/
/* #define  MECLASCV   0xffff0044          発着呼ｽﾙｰﾌﾟｯﾄｸﾗｽ変換異常         */
										/* M05 返却値の見直し				*/
/* #define  MEIXANCV   0xffff0045          発ｱﾄﾞﾚｽ拡張変換異常　　　        */
										/* M05 返却値の見直し				*/
/* #define  MEIXADCV   0xffff0046          発ｱﾄﾞﾚｽ拡張変換異常　　　        */
										/* M05 返却値の見直し				*/
/* #define  MERXANCV   0xffff0047          着ｱﾄﾞﾚｽ拡張変換異常　　　        */
										/* M05 返却値の見直し				*/
/* #define  MERXADCV   0xffff0048          着ｱﾄﾞﾚｽ拡張変換異常　　　        */
										/* M05 返却値の見直し				*/
/* #define  MEGWPRCV   0xffff0049          中継先ﾌﾟﾛﾄｺﾙ変換異常             */
										/* M05 返却値の見直し				*/
/* #define  MEGWLNCV   0xffff004A          ＧＷ内回線番号変換異常           */
										/* M05 返却値の見直し				*/
/* #define  MEPNUMCV   0xffff004B          端末ﾛｰｶﾙｱﾄﾞﾚｽ変換異常            */
										/* M05 返却値の見直し				*/
/* #define  MEAPLOCV   0xffff004C          運用ｼｽﾃﾑｵﾌﾟｼｮﾝ変換異常           */
										/* M05 返却値の見直し				*/
/* #define  MERSPTCV   0xffff004D          ｺﾈｸﾄ/ﾃﾞｨｽｺﾈｸﾄﾚｽﾎﾟﾝｽ待ちﾀｲﾏ変換   */
										/* M05 返却値の見直し				*/
/* #define  MESEGLCV   0xffff004E          最大分割ﾃﾞｰﾀ長変換異常　　　　   */
										/* M05 返却値の見直し				*/
/* #define  MEL4WSCV   0xffff004F          装置制御ｳｨﾝﾄﾞｳｻｲｽﾞ変換異常　　   */
										/* M05 返却値の見直し				*/
#define  MEDTADCV   0xffff0050          /* 相手DTEｱﾄﾞﾚｽ変換異常　　  		*/

#define  MENOEXEC   0xffff0060          /* 処理中ﾌｧｲﾙ転送要求なし           */
#define  MEMCHCCN   0xffff0061          /* ｷｬﾗｸﾀ変換異常                    */
#define  MEODESPR   0xffff0062          /* FTOS強制終了異常                 */
#define  MEFTMUJN   0xffff0063          /* ﾌｧｲﾙ転送処理矛盾                 */
#define  MEFTSEND   0xffff0064          /* 起動ﾊﾟﾗﾒｰﾀ送信異常               */
#define  MEFTCANC   0xffff0065          /* ﾌﾟﾛｾｽ終了通知要求ｷｬﾝｾﾙ           */
                                        /* 異常                             */
#define  MEFTTERM   0xffff0066          /* FTOS強制終了異常                 */
/* #define  MECLERER   0xffff0067          領域ｸﾘｱ異常  					*/
										/* M05 返却値の見直し				*/
#define  METBADGT   0xffff0068          /* SMPﾃｰﾌﾞﾙｱﾄﾞﾚｽ取得異常  */
/********************************/
/* 起動ﾊﾟﾗﾒｰﾀSG値異常			*/
/********************************/
#define  MESGXADL	0xffff0080			/* TFAX相手DTEｱﾄﾞﾚｽ桁数不正			*/
#define  MESGXCWS	0xffff0081			/* TFAX発呼者ｳｨﾝﾄﾞｳｻｲｽﾞ不正			*/
#define  MESGXRWS	0xffff0082			/* TFAX着呼者ｳｨﾝﾄﾞｳｻｲｽﾞ不正			*/
#define  MESGXFSL	0xffff0083			/* ﾌｧｽﾄｾﾚｸﾄ要求SG値不正				*/
#define  MESGPCHK	0xffff0084			/* 着信課金不正						*/
#define  MESGCXAL	0xffff0085			/* 発ｱﾄﾞﾚｽ拡張不正					*/
#define  MESGRXAL	0xffff0086			/* 着ｱﾄﾞﾚｽ拡張不正					*/
#define  MESGCLAS   0xffff0087			/* 中継先ﾌﾟﾛﾄｺﾙ不正					*/
#define  MESGRSPT	0xffff0088			/* ｺﾈｸﾄ､ﾃﾞｨｽｺﾈｸﾄﾚｽﾎﾟﾝｽ待ちﾀｲﾏ不正	*/
#define  MESGMAXD	0xffff0089			/* 最大分割ﾃﾞｰﾀ長不正				*/
#define  MESGLPWS	0xffff008A			/* 装置制御ｳｨﾝﾄﾞｳｻｲｽﾞ不正			*/
#define  MESGLPNO	0xffff008B			/* 論理ﾊﾟｽ番号不正					*/

/********************************/
/* 仕様変更対応　Ｍ０１			*/
/********************************/
#define  MEBPTADR	0xffff0090			/* TBPTｱﾄﾞﾚｽ取得異常          stM01 */
#define  MEBFSERH	0xffff0091			/* ﾊﾞｯﾌｧｻｰﾁｴﾗｰ     					*/
/* #define  MEPLIDCV	0xffff0092			ﾊﾞｯﾌｧﾌﾟｰﾙID変換異常        edM01 */
										/* M05 返却値の見直し				*/
#define  MEOSSNMP	0xffff0093			/* LICPへのﾒｯｾｰｼﾞ送信失敗		M04 */
										/* ^retryをAP側でするように			*/
/********************************/
/* 仕様変更対応　Ｍ０３			*/
/********************************/
#define  MEMEPTER	0xffff001f			/* ﾒﾓﾘﾊﾟｯﾁｴﾗｰ						*/
