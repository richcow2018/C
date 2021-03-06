/**********************************/
/*                   V/R = 0/0    */
/*                   88.03.28     */
/*          meisns.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ¡ãÀß·×½¤Àµ¼ÔÌ¾¡ä					±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÃ´Åö(Ò°¶:ºÑ±¯Ìß)*/
/*     ¡ãÀß·×½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä¡¡£±£¹£¹£³Ç¯¡¡£··î¡¡£±Æü     PD01*/
/*                                      rd´ÉÍý¾ðÊóÊÑ¹¹¤Î°Ù            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o º°ÄÞ             */
#define   WLPIO     0x00                 /* Ù°Ìß i/o º°ÄÞ           */
#define   W4WNT     0x40                 /* 4W-NTM i/o º°ÄÞ        **/
#define   W4WSY     0xc1                 /* 4W,4W-NTM ¼®Ø¼­ÍÞÂ      */
#define   WLPSY     0xc2                 /* Ù°Ìß ¼®Ø¼­ÍÞÂ           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* ¾²¼Þ®³                  */
#define   M0OSRETE  -1                   /* OS ÍÝ·¬¸Á ²¼Þ®³         */
/*******************************/
/*          snswork.h          */
/*******************************/
struct snswork {                         /* Ë·½³ Æ­³Ø®¸ ¼Þ®³Î³      */
       short  pathno;                    /* ÛÝØÊß½ ÊÞÝºÞ³           */
       short  yobi1;                     /* ÖËÞ 1                   */
       long   retadd;                    /* ØÀ°Ý ±ÄÞÚ½              */
       char  *argptr;                    /* ±°·Þ­ÒÝÄ ²· Îß²ÝÀ       */
       short  argsize;                   /* ±°·Þ­ÒÝÄ ²· »²½Þ        */
       short  tmvid;                     /* À²ÏÁ ¼·ÍÞÂ¼             */
       long   sysret;                    /* ¼½ÃÑ ÍÝ·¬¸Á             */
       long   usrrd;                     /* Õ°»ÞØ¸´½Ä¼±ÊÌ»Ò		PD01*/
       long   timet;                     /*À²ÏÁ                     */
};
typedef struct snswork SNSWORK;
union sninpret {                       /* ROS ØÀ°Ý ¼Þ®³Î³             */
    long  retdat;                      /* ¾ÞÝÀ²                       */
    char  retros[4];                   /* ¾ÞÝÀ²                       */
    struct {                  /* 4W i/o ¾²¼Þ®³                        */
        unsigned erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned kanr : 31;            /* ¶ÝØ®³ º°ÄÞ                  */
    } ni4w;
    struct {                  /* 4W i/o ²¼Þ®³                         */
        unsigned erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned flag : 1;             /* Ì×¸Þ                        */
        unsigned kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned erco : 4;             /* ´×° ÀÞ²ÌÞÝÙ²                */
        unsigned ersy : 11;            /* ´×° ¼®³»²                   */
        unsigned rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* Ù°Ìß i/o ¾²¼Þ®³                      */
        unsigned erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned fil1 : 15;            /* Ð ¼Ö³                       */
        unsigned wrsz : 16;            /* ×²Ä »²½Þ                    */
    } nilp;
    struct {                  /* Ù°Ìß i/o ²¼Þ®³                       */
        unsigned erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned flag : 1;             /* Ì×¸Þ                        */
        unsigned kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned ersy : 20;            /* ´×° ¼®³»²                   */
    } eilp;
};
typedef union sninpret SNINPRET;
union snoutret {                       /* ØÀ°Ý ¼Þ®³Î³ ²·              */
    char  retdat[8];                   /* ¾ÞÝÀ²                       */
    struct {                  /* 4W i/o ²¼Þ®³                         */
        unsigned fil1 : 32;            /* Ð ¼Ö³                       */
        unsigned val1 : 5;             /* ºÃ²Á                        */
        unsigned kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned val2 : 4;             /* ºÃ²Á                        */
        unsigned erco : 4;             /* ´×° ÀÞ²ÌÞÝÙ²                */
        unsigned val3 : 5;             /* ºÃ²Á                        */
        unsigned ersy : 11;            /* ´×° ¼®³»²                   */
    } eo4w;
    struct {                  /* Ù°Ìß i/o ¾²¼Þ®³                      */
        unsigned fil1 : 16;            /* Ð ¼Ö³                       */
        unsigned wrsz : 16;            /* ×²Ä »²½Þ                    */
        unsigned fil2 : 32;            /* Ð ¼Ö³                       */
    } nolp;
    struct {                  /* Ù°Ìß i/o ²¼Þ®³                       */
        unsigned fil1 : 32;            /* Ð ¼Ö³                       */
        unsigned val1 : 1;             /* ºÃ²Á                        */
        unsigned syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned val2 : 1;             /* ºÃ²Á                        */
        unsigned kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned ersy : 20;            /* ´×° ¼®³»²                   */
    } eolp;
};
typedef union snoutret SNOUTRET;
