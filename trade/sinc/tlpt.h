/**********************************************************************/
/*                                                                    */
/*        TLPT ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ     tlpt.h      (61.12.  )                */
/*                                    ﾍﾝｺｳ  (62.12.  )   CC           */
/*                                    変更   94.12.20    JJ           */
/*                                    変更者 西山  伸                 */
/*                                    変更   95.06.08    SS           */
/*                                    変更者 新藤由美	 ST2772		  */
/*                                    変更   95.05.06    KK           */
/*                                    変更者 北西智洋	 SSCY0167  	  */
/*                                                                    */
/**********************************************************************/

struct mdlptsb {
        short    tlptinen;               /* 予備                   JJ */
        char     tlptyob0[6];            /* ﾖﾋﾞ0                   JJ */
};
typedef struct mdlptsb MDLPTSB;          /* DCP ﾖｳ                    */
typedef struct mdlptsb TLPTSUB;          /* FIP ﾖｳ                    */

struct mdlptko {
	char   tlptkhyo    ;                 /* ｺﾍﾞﾂﾌﾞ ﾋｮｳｼﾞ              */
	char   tlptyob1[2] ;                 /* ﾖﾋﾞ1                   KK */
	char   tlptdcfg    ;                 /* ｶｲｾﾝｷﾘｶｴ ﾌﾗｸﾞ          KK */
	short  tlptfapn    ;                 /* TFAP ｴﾝﾄﾘ NO.             */
	short  tlptlgtn    ;                 /* TLGT ｴﾝﾄﾘ NO.             */
	char   tlptipas    ;                 /* ﾊﾟｽ ｽﾃｰﾀｽ                 */
	char   tlptiatt    ;                 /* ATT ｽﾃｰﾀｽ                 */
	char   tlptihdk    ;                 /* ﾋﾄﾞｳｷ ｽﾃｰﾀｽ               */
	char   tlptcomm    ;                 /* コマンド名			   SS */
	short  tlptpatn    ;                 /* TPAT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ       CC */
	short  tlptyob3    ;                 /* ﾖﾋﾞ3                   CC */
	char   tlptpsnm[8] ;                 /* ﾛﾝﾘ ﾊﾟｽ ｼｷﾍﾞﾂﾒｲ        CC */
	char   tlptyob4[4] ;                 /* ﾖﾋﾞ4                   JJ */
};
typedef struct mdlptko MDLPTKO;          /* DCP ﾖｳ                    */
typedef struct mdlptko TLPTPSZ;          /* FIP ﾖｳ                    */
