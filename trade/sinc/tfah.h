/**********************************************************************/
/*                                                                    */
/*        TFAH ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ       tfah.h           (61.12.  )         */
/*                                       ﾍﾝｺｳ      (62.12.  ) CC      */
/*                                       変更       94.10.26  JI      */
/*                                       変更者     西山  伸          */
/*                                       変更       94.12.20  JJ      */
/*                                       変更者     西山  伸          */
/*                                       変更       95.02.14  S0      */
/*                                       変更者     根本(Sazae)欣之   */
/*                                       変更       96.06.10  SP      */
/*                                       変更者     田中宏之		  */
/*                                      変更       2003.2.28 LA01     */
/*                                      変更内容   linux移植に伴う修正*/
/*                                      変更者     田中宏之           */
/*                                                                    */
/**********************************************************************/

struct mdfahsb {
        short    tfahinen;               /* 予備                   JI */
        char     tfahtype;               /* ﾂｳｼﾝ ｾｲｷﾞﾖ ｼﾕﾍﾞﾂ        * */
        char     tfahyob0;               /* ﾖﾋﾞ0                    * */
        short    tfahpsmx;               /* ﾛﾝﾘ ﾊﾟｽ ｻｲﾀﾞｲ ｽｳ       CC */
        char     tfahyob1[6];            /* ﾖﾋﾞ1                CC JJ */
};
typedef struct mdfahsb MDFAHSB;          /* DCP ﾖｳ                    */
typedef struct mdfahsb TFAHSUB;          /* FIP ﾖｳ                    */

struct  mdfahko {
        char   tfahlnsb      ;           /* ｶｲｾﾝ ｼｭﾍﾞﾂ                */
        char   tfahpksb      ;           /* ﾊﾟｯｹｰｼﾞ ｼｭﾍﾞﾂ             */
		short  tfahfnpu      ;           /* FNA-PU番号            LA01*/
		char   tfahyob2[4]   ;           /* 予備                  LA01*/
        char   tfahpsnm[22]  ;           /* ﾊﾟｽ ﾒｲ                    */
        short  tfahlnno      ;           /* ｶｲｾﾝ ﾊﾞﾝｺﾞｳ               */
        long   tfahmbid      ;           /* ﾒｰﾙﾎﾞｯｸｽ ID               */
        short  tfahifrm      ;           /* I ﾌﾚｰﾑ ﾁｮｳ                */
        char   tfahyuko      ;           /* ﾕｳｺｳ ﾑｺｳ ﾋｮｳｼﾞ         CC */
        unsigned char   tfahlccl;        /* LC種別                 SP */
        short  tfahsszu      ;           /* ｾｸﾞﾒﾝﾄｻｲｽﾞ(ﾉﾎﾞﾘ)          */
        short  tfahsszd      ;           /* ｾｸﾞﾒﾝﾄｻｲｽﾞ(ｸﾀﾞﾘ)          */
        char   tfahshut      ;           /* SHUT-DOWN ﾋﾖｳｼﾞ         * */
        char   tfahdlty      ;           /* ﾃﾞｰﾀ ﾘﾝｸ ﾋﾖｳｼﾞ          * */
        char   tfahbloc      ;           /* ﾌﾞﾛﾂｸ ｽｳ ﾋﾖｳｼﾞ          * */
        char   tfahbkup      ;           /* ﾊﾞﾂｸ ｱﾂﾌﾟ ﾋﾖｳｼﾞ         * */
        char   tfahpckb      ;           /* ﾂｳｼﾝ ｾｲｷﾞﾖ ｼﾕﾍﾞﾂ        * */
        char   tfahlsts      ;           /* ｶｲｾﾝ ｽﾃｰﾀｽ              * */
        char   tfahlhdk      ;           /* ｶｲｾﾝ ﾋﾄﾞｳｷ ﾂｳﾁ ｽﾃｰﾀｽ    * */
        char   tfahlkdk      ;           /* ｶｲｾﾝ ｶｲﾌｸ ﾄﾞｳｷ ｽﾃｰﾀｽ    * */
        short  tfahdadn      ;           /* TDAD ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ       CC */
        short  tfahtben      ;           /* ｶｸﾁｮｳ ﾃｰﾌﾞﾙ ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳCC */
        short  tfahfacn      ;           /* ＴＦＡＣのエントリ番号 JI */
        char   tfahchst      ;           /* 当該論理回線状態       JI */
        char   tfahyob3      ;           /* 予備                CC JI */
        short  tfahlpte      ;           /* TLPH ﾎﾟｲﾝﾀ ﾕｳｺｳ ｴﾝﾄﾘｽｳ    */
        short  tfahtplt      ;           /* TPLT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ       CC */
        short  tfahllno      ;           /* 論理回線番号           S0 */
        short  tfahlctn   	 ;           /* LCｴﾐｭﾚｰﾀｴﾝﾄﾘ番号		SP*/
};
typedef struct  mdfahko MDFAHKO;         /* DCP ﾖｳ                    */
typedef struct  mdfahko TFAHPSZ;         /* FIP ﾖｳ                    */

struct mdfahps {
        short    tfahlphn;               /* TLPH ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ       CC */
};
typedef struct mdfahps MDFAHPS;          /* DCP ﾖｳ                    */
typedef struct mdfahps TFAHPS;           /* FIP ﾖｳ                    */
