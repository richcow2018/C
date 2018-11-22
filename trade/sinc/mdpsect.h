/***************************************/
/*                                     */
/*            mdpsect.h                */
/*                                     */
/*        PSECT(DCPｲｷ) ﾉ ﾌｫｰﾏｯﾄ        */
/*                                     */
/*            ﾍﾝｺｳ     88.01.       CC */
/***************************************/
/**********************************************************************/
/* 変更者は注目！！                                                   */
/*     PSECT DCP域は、psect.hにて128ﾊﾞｲﾄの実領域を割り当てられている。*/
/*     従って、項目を増やす場合に、全体長がそれを超えないように注意。 */
/*                                                                    */
/*     ＜設計修正者名＞					営業店システム担当(ﾒｰｶ:ｺﾑｱｯﾌﾟ)*/
/*     ＜設計修正年月日及び修正ＩＤ＞　１９９３年　７月　１日     PD03*/
/*                                      EDP使用可否ﾁｪｯｸ条件変更       */
/*                                     １９９５年　２月　９日      S01*/
/*                                      SACY0012その他  Sazae         */
/*                                     １９９５年１０月　２日      S02*/
/*                                      ST3521(改善)    Sazae         */
/**********************************************************************/

struct  mdpsect {
        long    mdpstpat;                /* TPAT ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstlgt;                /* TLGT ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstlph;                /* TLPH ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstfah;                /* TFAH ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstlpt;                /* TLPT ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstfap;                /* TFAP ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpstfac;                /* TFAC ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpsttvi;                /* TTVI ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
        long    mdpsrymd;                /* ﾘﾘｰｽ YYYYMMDD             */
        long    mdpsenad;                /* TPAT ｺﾍﾞﾂﾌﾞ ｱﾄﾞﾚｽ         */
        short   mdpsmisz;                /* MIA ｻｲﾀﾞｲ ｻｲｽﾞ            */
        short   mdpsrbsz;                /* ｼﾞｭｼﾝﾊﾞｯﾌｧ ｻｲﾀﾞｲ ｻｲｽﾞ     */
        long    mdpsrdad;                /* RDｶﾝﾘｲｷ ｱﾄﾞﾚｽ             */
        long    mdpsatad;                /* ｱﾃｻｷｼﾞｮｳﾎｳ ｶﾝﾘｲｷ ｱﾄﾞﾚｽ    */
        long    mdpsagad;                /* ｱｰｷﾞｭﾒﾝﾄ ｶﾝﾘｲｷ ｱﾄﾞﾚｽ      */
										 /* 注.EDPでは未使用	  PD03*/
        short   mdpsrdsz;                /* RDｶﾝﾘｲｷ ｻｲｽﾞ              */
        short   mdpsatsz;                /* ｱﾃｻｷｼﾞｮｳﾎｳ ｶﾝﾘｲｷ ｻｲｽﾞ     */
        short   mdpsagsz;                /* ｱｰｷﾞｭﾒﾝﾄ ｶﾝﾘｲｷ ｻｲｽﾞ       */
										 /* 注.EDPでは未使用	  PD03*/
        char    mdpsmail;                /* ﾒｰﾙﾎﾞｯｸｽ ｶﾝﾘ ﾓｰﾄﾞ         */
        char    mdpsyob1;                /* ﾖﾋﾞ1                      */
        short   mdpsrtly;                /* ﾘﾄﾗｲ ｶｲｽｳ ( 4W - NTM ﾖｳ ) */
        char    mdpsdsts[2];             /* 電文制御使用区分	  PD03*/
        long    mdpstdad;                /* TDAD ｾﾝﾄｳ ｱﾄﾞﾚｽ        CC */
        long    mdpsrnph;                /* TLPH ｼｹﾞﾝﾊﾞﾝｺﾞｳ           */
        long    mdpsrnpt;                /* TLPT ｼｹﾞﾝﾊﾞﾝｺﾞｳ           */
        long	mdpstfax;                /* TFAX 先頭ｱﾄﾞﾚｽ         S01*/
        long	mdpstfal;                /* TFAL 先頭ｱﾄﾞﾚｽ         S01*/
        long	mdpstpaa;                /* TPAA 先頭ｱﾄﾞﾚｽ         S01*/
        long	mdpsopct;                /* 自ﾌﾟﾛｾｽTPCT個別部ｱﾄﾞﾚｽ S01*/
										 /* (以上96バイト)            */
        long	mdpspvct;                /* 各種ﾌﾟﾛｾｽ内部ﾃｰﾌﾞﾙ     S02*/
										 /* ﾙｰﾄｱﾄﾞﾚｽ               S02*/
};
typedef struct mdpsect MDPSECT;
