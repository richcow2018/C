/**********************************************************************/
/*                                                                    */
/*        TFAH Ã°ÌÞÙ Ì«°Ï¯Ä       tfah.h           (61.12.  )         */
/*                                       ÍÝº³      (62.12.  ) CC      */
/*                                       ÊÑ¹¹       94.10.26  JI      */
/*                                       ÊÑ¹¹¼Ô     À¾»³  ¿­          */
/*                                       ÊÑ¹¹       94.12.20  JJ      */
/*                                       ÊÑ¹¹¼Ô     À¾»³  ¿­          */
/*                                       ÊÑ¹¹       95.02.14  S0      */
/*                                       ÊÑ¹¹¼Ô     º¬ËÜ(Sazae)¶ÕÇ·   */
/*                                       ÊÑ¹¹       96.06.10  SP      */
/*                                       ÊÑ¹¹¼Ô     ÅÄÃæ¹¨Ç·		  */
/*                                      ÊÑ¹¹       2003.2.28 LA01     */
/*                                      ÊÑ¹¹ÆâÍÆ   linux°Ü¿¢¤ËÈ¼¤¦½¤Àµ*/
/*                                      ÊÑ¹¹¼Ô     ÅÄÃæ¹¨Ç·           */
/*                                                                    */
/**********************************************************************/

struct mdfahsb {
        short    tfahinen;               /* Í½È÷                   JI */
        char     tfahtype;               /* Â³¼Ý ¾²·ÞÖ ¼ÕÍÞÂ        * */
        char     tfahyob0;               /* ÖËÞ0                    * */
        short    tfahpsmx;               /* ÛÝØ Êß½ »²ÀÞ² ½³       CC */
        char     tfahyob1[6];            /* ÖËÞ1                CC JJ */
};
typedef struct mdfahsb MDFAHSB;          /* DCP Ö³                    */
typedef struct mdfahsb TFAHSUB;          /* FIP Ö³                    */

struct  mdfahko {
        char   tfahlnsb      ;           /* ¶²¾Ý ¼­ÍÞÂ                */
        char   tfahpksb      ;           /* Êß¯¹°¼Þ ¼­ÍÞÂ             */
		short  tfahfnpu      ;           /* FNA-PUÈÖ¹æ            LA01*/
		char   tfahyob2[4]   ;           /* Í½È÷                  LA01*/
        char   tfahpsnm[22]  ;           /* Êß½ Ò²                    */
        short  tfahlnno      ;           /* ¶²¾Ý ÊÞÝºÞ³               */
        long   tfahmbid      ;           /* Ò°ÙÎÞ¯¸½ ID               */
        short  tfahifrm      ;           /* I ÌÚ°Ñ Á®³                */
        char   tfahyuko      ;           /* Õ³º³ Ñº³ Ë®³¼Þ         CC */
        unsigned char   tfahlccl;        /* LC¼ïÊÌ                 SP */
        short  tfahsszu      ;           /* ¾¸ÞÒÝÄ»²½Þ(ÉÎÞØ)          */
        short  tfahsszd      ;           /* ¾¸ÞÒÝÄ»²½Þ(¸ÀÞØ)          */
        char   tfahshut      ;           /* SHUT-DOWN ËÖ³¼Þ         * */
        char   tfahdlty      ;           /* ÃÞ°À ØÝ¸ ËÖ³¼Þ          * */
        char   tfahbloc      ;           /* ÌÞÛÂ¸ ½³ ËÖ³¼Þ          * */
        char   tfahbkup      ;           /* ÊÞÂ¸ ±ÂÌß ËÖ³¼Þ         * */
        char   tfahpckb      ;           /* Â³¼Ý ¾²·ÞÖ ¼ÕÍÞÂ        * */
        char   tfahlsts      ;           /* ¶²¾Ý ½Ã°À½              * */
        char   tfahlhdk      ;           /* ¶²¾Ý ËÄÞ³· Â³Á ½Ã°À½    * */
        char   tfahlkdk      ;           /* ¶²¾Ý ¶²Ì¸ ÄÞ³· ½Ã°À½    * */
        short  tfahdadn      ;           /* TDAD ´ÝÄØ ÊÞÝºÞ³       CC */
        short  tfahtben      ;           /* ¶¸Á®³ Ã°ÌÞÙ ´ÝÄØ ÊÞÝºÞ³CC */
        short  tfahfacn      ;           /* £Ô£Æ£Á£Ã¤Î¥¨¥ó¥È¥êÈÖ¹æ JI */
        char   tfahchst      ;           /* Åö³ºÏÀÍý²óÀþ¾õÂÖ       JI */
        char   tfahyob3      ;           /* Í½È÷                CC JI */
        short  tfahlpte      ;           /* TLPH Îß²ÝÀ Õ³º³ ´ÝÄØ½³    */
        short  tfahtplt      ;           /* TPLT ´ÝÄØ ÊÞÝºÞ³       CC */
        short  tfahllno      ;           /* ÏÀÍý²óÀþÈÖ¹æ           S0 */
        short  tfahlctn   	 ;           /* LC´Ð­Ú°À´ÝÄØÈÖ¹æ		SP*/
};
typedef struct  mdfahko MDFAHKO;         /* DCP Ö³                    */
typedef struct  mdfahko TFAHPSZ;         /* FIP Ö³                    */

struct mdfahps {
        short    tfahlphn;               /* TLPH ´ÝÄØ ÊÞÝºÞ³       CC */
};
typedef struct mdfahps MDFAHPS;          /* DCP Ö³                    */
typedef struct mdfahps TFAHPS;           /* FIP Ö³                    */
