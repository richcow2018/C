/**************************************/
/*                                    */
/*               mdmk.h               */
/*                                    */
/*        Ö³·Õ³ÒÂ¾-¼Þ ¶ÝØ²· Ìµ-ÏÂÄ    */
/*                                    */
/**************************************/
struct mdmkkyo {
    short   mdmkmxen;                   /* »²ÀÞ² ´ÝÄØ½³           */
    short   mdmkeden;                   /* ÍÝ¼Õ³ ´ÝÄØ½³           */
    long    mdmkmiad;                   /* MIAÀ²Ë²· ±ÄÞÚ½         */
};
typedef struct mdmkkyo MDMKKYO;
struct mdmkkob {
    long    mdmkmsad;                   /* ÒÂ¾-¼Þ ±ÄÞÚ½           */
    short   mdmkmssz;                   /* ÒÂ¾-¼Þ »²½Þ            */
    char    mdmkyob1;                   /* ÖËÞ 1                  */
};
typedef struct mdmkkob MDMKKOB;
