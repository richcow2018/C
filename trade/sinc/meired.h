/**********************************/
/*                   V/R = 0/0    */
/*                   88.03.25    */
/*          meired.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ¡ãÀß·×½¤Àµ¼ÔÌ¾¡ä					±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÃ´Åö(ŽÒŽ°Ž¶:ŽºŽÑŽ±Ž¯ŽÌŽß)*/
/*     ¡ãÀß·×½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä¡¡£±£¹£¹£³Ç¯¡¡£··î¡¡£±Æü     PD01*/
/*                                      rd´ÉÍý¾ðÊóÊÑ¹¹¤Î°Ù            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o ŽºŽ°ŽÄŽÞ             */
#define   WLPIO     0x00                 /* ŽÙŽ°ŽÌŽß i/o ŽºŽ°ŽÄŽÞ           */
#define   W4WNT     0x40                 /* 4W-NTM i/o ŽºŽ°ŽÄŽÞ         */
#define   W4WSY     0xc1                 /* 4W-NTM Ž´Ž×Ž° ŽºŽ°ŽÄŽÞ         */
#define   WLPSY     0xc2                 /* ŽÙŽ°ŽÌŽß Ž´Ž×Ž° ŽºŽ°ŽÄŽÞ           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* Ž¾Ž²Ž¼ŽÞŽ®Ž³                  */
#define   M0OSRETE  -1                   /* OS ŽÍŽÝŽ·Ž¬Ž¸ŽÁ Ž²Ž¼ŽÞŽ®Ž³         */
/*******************************/
/*          redwork.h          */
/*******************************/
struct redwork {                         /* ŽËŽ·Ž½Ž³ ŽÆŽ­Ž³ŽØŽ®Ž¸ Ž¼ŽÞŽ®Ž³ŽÎŽ³      */
       short  pathno;                    /* ŽÛŽÝŽØŽÊŽßŽ½ ŽÊŽÞŽÝŽºŽÞŽ³           */
       char   syoricod;                  /* Ž¼Ž®ŽØ ŽºŽ°ŽÄŽÞ                */
       char   yobi1;                     /* ŽÖŽËŽÞ  1                  */
       long   retadd;                    /* ŽØŽÀŽ°ŽÝ Ž±ŽÄŽÞŽÚŽ½              */
       short  tmvid;                     /* ŽÀŽ²ŽÏŽÁ Ž¼Ž·ŽÍŽÞŽÂŽ¼             */
       short  rdasize;                   /* Ž¼ŽÞŽ­Ž¼ŽÝŽÃŽÞŽ°ŽÀ Ž¶Ž¸ŽÉŽ³Ž²Ž· Ž»Ž²Ž½ŽÞ   */
       long   rdaptr;                    /* Ž¼ŽÞŽ­Ž¼ŽÝŽÃŽÞŽ°ŽÀ Ž¶Ž¸ŽÉŽ³Ž²Ž· Ž±ŽÄŽÞŽÚŽ½  */
       long   dosapara;                  /* ŽÄŽÞŽ³Ž» ŽÊŽßŽ×ŽÒŽ°ŽÀ             */
       long   sysret;                    /* Ž¼Ž½ŽÃŽÑ ŽÍŽÝŽ·Ž¬Ž¸ŽÁ             */
       long   usrrd;                     /* ŽÕŽ°Ž»ŽÞŽØŽ¸Ž´Ž½ŽÄ¼±ÊÌ»Ò		PD01*/
 };
typedef struct redwork REDWORK;

union reinpret {                       /* ROS ŽØŽÀŽ°ŽÝ Ž¼ŽÞŽ®Ž³ŽÎŽ³             */
    long  retdat;                      /* Ž¾ŽÞŽÝŽÀŽ²                       */
    char  retros[4];                   /* Ž¾ŽÞŽÝŽÀŽ²                       */
    short redsiz[2];                   /* ŽØŽ°ŽÄŽÞ Ž»Ž²Ž½ŽÞ                   */
    struct {                  /* 4W i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                        */
        unsigned int erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned int fil1 : 10;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* ŽØŽ°ŽÄŽÞ Ž»Ž²Ž½ŽÞ                   */
    } ni4w;
    struct {                  /* 4W i/o Ž²Ž¼ŽÞŽ®Ž³                         */
        unsigned int erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned int syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned int flag : 1;             /* ŽÌŽ×Ž¸ŽÞ                        */
        unsigned int kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned int erco : 4;             /* Ž´Ž×Ž° ŽÀŽÞŽ²ŽÌŽÞŽÝŽÙŽ²                */
        unsigned int ersy : 11;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
        unsigned int rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                      */
        unsigned int erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned int fil1 : 7;             /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int resp : 8;             /* ŽÚŽ½ŽÎŽßŽÝŽ½                      */
        unsigned int resz : 16;            /* ŽØŽ°ŽÄŽÞ Ž»Ž²Ž½ŽÞ                   */
    } nilp;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž²Ž¼ŽÞŽ®Ž³                       */
        unsigned int erfl : 1;             /* Ž´Ž×Ž° ŽÌŽ×Ž¸ŽÞ                    */
        unsigned int syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned int flag : 1;             /* ŽÌŽ×Ž¸ŽÞ                        */
        unsigned int kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned int ersy : 20;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eilp;
}; 
typedef union reinpret REINPRET;

union reoutret {                       /* ŽØŽÀŽ°ŽÝ Ž¼ŽÞŽ®Ž³ŽÎŽ³ Ž²Ž·              */
    char  retdat[8];                   /* Ž¾ŽÞŽÝŽÀŽ²                       */
    struct {                  /* 4W i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                        */
        unsigned int fil1 : 8;             /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int val1 : 3;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* ŽØŽ°ŽÄŽÞ Ž»Ž²Ž½ŽÞ                   */
        unsigned int fil2 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
    } no4w;
    struct {                  /* 4W i/o Ž²Ž¼ŽÞŽ®Ž³                         */
        unsigned int fil1 : 8;             /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int val1 : 3;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int fil2 : 16;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int val2 : 5;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned int val3 : 4;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int erco : 4;             /* Ž´Ž×Ž° ŽÀŽÞŽ²ŽÌŽÞŽÝŽÙŽ²                */
        unsigned int val4 : 5;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int ersy : 11;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eo4w;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž¾Ž²Ž¼ŽÞŽ®Ž³                      */
        unsigned int fil1 : 8;             /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int resp : 8;             /* ŽÚŽ½ŽÎŽßŽÝŽ½                      */
        unsigned int resz : 16;            /* ŽØŽ°ŽÄŽÞ Ž»Ž²Ž½ŽÞ                   */
        unsigned int fil2 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
    } nolp;
    struct {                  /* ŽÙŽ°ŽÌŽß i/o Ž²Ž¼ŽÞŽ®Ž³                       */
        unsigned int fil1 : 32;            /* ŽÐ Ž¼ŽÖŽ³                       */
        unsigned int val1 : 1;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int syor : 7;             /* Ž¼Ž®ŽØ Ž¼Ž­ŽÍŽÞŽÂ                   */
        unsigned int val2 : 1;             /* ŽºŽÃŽ²ŽÁ                        */
        unsigned int kens : 3;             /* Ž¹ŽÝŽ¼Ž­ŽÂ ŽÓŽÄ                    */
        unsigned int ersy : 20;            /* Ž´Ž×Ž° Ž¼Ž®Ž³Ž»Ž²                   */
    } eolp;
};
typedef union reoutret REOUTRET;

