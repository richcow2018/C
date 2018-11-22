/**********************************/
/*                  V/R = 0/0     */
/*                  88.03.28      */
/*          meicnt.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ¡ãÀß·×½¤Àµ¼ÔÌ¾¡ä					±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÃ´Åö(ŽÒŽ°Ž¶:ŽºŽÑŽ±Ž¯ŽÌŽß)*/
/*     ¡ãÀß·×½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä¡¡£±£¹£¹£³Ç¯¡¡£··î¡¡£±Æü     PD01*/
/*                                      rd´ÉÍý¾ðÊóÊÑ¹¹¤Î°Ù            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o ŽºŽ°ŽÄŽÞ             */
#define   WLPIO     0x00                 /* ŽÙŽ°ŽÌŽß i/o ŽºŽ°ŽÄŽÞ           */
#define   W4WNT     0x40                 /* 4W-NTM i/o ŽºŽ°ŽÄŽÞ        **/
#define   W4WSY     0xc1                 /* 4W,4W-NTM Ž¼Ž®ŽØŽ¼Ž­ŽÍŽÞŽÂ      */
#define   WLPSY     0xc2                 /* ŽÙŽ°ŽÌŽß Ž¼Ž®ŽØŽ¼Ž­ŽÍŽÞŽÂ           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* Ž¾Ž²Ž¼ŽÞŽ®Ž³                  */
#define   M0OSRETE  -1                   /* OS ŽÍŽÝŽ·Ž¬Ž¸ŽÁ Ž²Ž¼ŽÞŽ®Ž³         */
/*******************************/
/*          cntwork.h          */
/*******************************/
struct cntwork {                         /* ŽËŽ·Ž½Ž³ ŽÆŽ­Ž³ŽØŽ®Ž¸ Ž¼ŽÞŽ®Ž³ŽÎŽ³      */
       short  pathno;                    /* ŽÛŽÝŽØŽÊŽßŽ½ ŽÊŽÞŽÝŽºŽÞŽ³           */
       short  yobi1;                     /* ŽÖŽËŽÞ 1                   */
       long   retadd;                    /* ŽØŽÀŽ°ŽÝ Ž±ŽÄŽÞŽÚŽ½              */
       char  *argptr;                    /* Ž±Ž°Ž·ŽÞŽ­ŽÒŽÝŽÄ Ž²Ž· ŽÎŽßŽ²ŽÝŽÀ       */
       short  argsize;                   /* Ž±Ž°Ž·ŽÞŽ­ŽÒŽÝŽÄ Ž²Ž· Ž»Ž²Ž½ŽÞ        */
       short  tmvid;                     /* ŽÀŽ²ŽÏŽÁ Ž¼Ž·ŽÍŽÞŽÂŽ¼             */
       long   sysret;                    /* Ž¼Ž½ŽÃŽÑ ŽÍŽÝŽ·Ž¬Ž¸ŽÁ             */
       long   usrrd;                     /* ŽÕŽ°Ž»ŽÞŽØŽ¸Ž´Ž½ŽÄ¼±ÊÌ»Ò		PD01*/
       long   timet;                     /*ŽÀŽ²ŽÏŽÁ                     */
};
typedef struct cntwork CNTWORK;
union cninpret {                       /* ROS ŽØŽÀŽ°ŽÝ Ž¼ŽÞŽ®Ž³ŽÎŽ³             */
    long  retdat;                      /* Ž¾ŽÞŽÝŽÀŽ²                       */
    char  retros[4];                   /* Ž¾ŽÞŽÝŽÀŽ²                       */
    struct {                  /* 4W i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                        */
        unsigned erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned kanr : 31;            /* Ž¶ŽÝŽØŽ®Ž³ ŽºŽ°ŽÄŽÞ                  */
    } ni4w;
    struct {                  /* 4W i/o Ž²Ž¼ŽÞŽ®Ž³                         */
        unsigned erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned flag : 1;             /* ŽÌŽ×Ž¸ŽÞ                        */
        unsigned kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned erco : 4;             /* Ž´Ž×Ž° ŽÀŽÞŽ²ŽÌŽÞŽÝŽÙŽ²                */
        unsigned ersy : 11;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
        unsigned rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                      */
        unsigned erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned fil1 : 15;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned wrsz : 16;            /* Ž×Ž²ŽÄ Ž»Ž²Ž½ŽÞ                    */
    } nilp;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž²Ž¼ŽÞŽ®Ž³                       */
        unsigned erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned flag : 1;             /* ŽÌŽ×Ž¸ŽÞ                        */
        unsigned kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned ersy : 20;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eilp;
};
typedef union cninpret CNINPRET;
union cnoutret {                       /* ŽØŽÀŽ°ŽÝ Ž¼ŽÞŽ®Ž³ŽÎŽ³ Ž²Ž·              */
    char  retdat[8];                   /* Ž¾ŽÞŽÝŽÀŽ²                       */
    struct {                  /* 4W i/o Ž²Ž¼ŽÞŽ®Ž³                         */
        unsigned fil1 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned val1 : 5;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned val2 : 4;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned erco : 4;             /* Ž´Ž×Ž° ŽÀŽÞŽ²ŽÌŽÞŽÝŽÙŽ²                */
        unsigned val3 : 5;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned ersy : 11;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eo4w;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                      */
        unsigned fil1 : 16;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned wrsz : 16;            /* Ž×Ž²ŽÄ Ž»Ž²Ž½ŽÞ                    */
        unsigned fil2 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
    } nolp;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž²Ž¼ŽÞŽ®Ž³                       */
        unsigned fil1 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned val1 : 1;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned val2 : 1;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned ersy : 20;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eolp;
};
typedef union cnoutret CNOUTRET;
