/**********************************/
/*                   V/R = 0/0    */
/*                   88.03.25    */
/*          meired.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ¡ãÀß·×½¤Àµ¼ÔÌ¾¡ä					±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÃ´Åö(Ò°¶:ºÑ±¯Ìß)*/
/*     ¡ãÀß·×½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä¡¡£±£¹£¹£³Ç¯¡¡£··î¡¡£±Æü     PD01*/
/*                                      rd´ÉÍý¾ðÊóÊÑ¹¹¤Î°Ù            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o º°ÄÞ             */
#define   WLPIO     0x00                 /* Ù°Ìß i/o º°ÄÞ           */
#define   W4WNT     0x40                 /* 4W-NTM i/o º°ÄÞ         */
#define   W4WSY     0xc1                 /* 4W-NTM ´×° º°ÄÞ         */
#define   WLPSY     0xc2                 /* Ù°Ìß ´×° º°ÄÞ           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* ¾²¼Þ®³                  */
#define   M0OSRETE  -1                   /* OS ÍÝ·¬¸Á ²¼Þ®³         */
/*******************************/
/*          redwork.h          */
/*******************************/
struct redwork {                         /* Ë·½³ Æ­³Ø®¸ ¼Þ®³Î³      */
       short  pathno;                    /* ÛÝØÊß½ ÊÞÝºÞ³           */
       char   syoricod;                  /* ¼®Ø º°ÄÞ                */
       char   yobi1;                     /* ÖËÞ  1                  */
       long   retadd;                    /* ØÀ°Ý ±ÄÞÚ½              */
       short  tmvid;                     /* À²ÏÁ ¼·ÍÞÂ¼             */
       short  rdasize;                   /* ¼Þ­¼ÝÃÞ°À ¶¸É³²· »²½Þ   */
       long   rdaptr;                    /* ¼Þ­¼ÝÃÞ°À ¶¸É³²· ±ÄÞÚ½  */
       long   dosapara;                  /* ÄÞ³» Êß×Ò°À             */
       long   sysret;                    /* ¼½ÃÑ ÍÝ·¬¸Á             */
       long   usrrd;                     /* Õ°»ÞØ¸´½Ä¼±ÊÌ»Ò		PD01*/
 };
typedef struct redwork REDWORK;

union reinpret {                       /* ROS ØÀ°Ý ¼Þ®³Î³             */
    long  retdat;                      /* ¾ÞÝÀ²                       */
    char  retros[4];                   /* ¾ÞÝÀ²                       */
    short redsiz[2];                   /* Ø°ÄÞ »²½Þ                   */
    struct {                  /* 4W i/o ¾²¼Þ®³                        */
        unsigned int erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned int fil1 : 10;            /* Ð ¼Ö³                       */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* Ø°ÄÞ »²½Þ                   */
    } ni4w;
    struct {                  /* 4W i/o ²¼Þ®³                         */
        unsigned int erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned int syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned int flag : 1;             /* Ì×¸Þ                        */
        unsigned int kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned int erco : 4;             /* ´×° ÀÞ²ÌÞÝÙ²                */
        unsigned int ersy : 11;            /* ´×° ¼®³»²                   */
        unsigned int rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* Ù°Ìß i/o ¾²¼Þ®³                      */
        unsigned int erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned int fil1 : 7;             /* Ð ¼Ö³                       */
        unsigned int resp : 8;             /* Ú½ÎßÝ½                      */
        unsigned int resz : 16;            /* Ø°ÄÞ »²½Þ                   */
    } nilp;
    struct {                  /* Ù°Ìß i/o ²¼Þ®³                       */
        unsigned int erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned int syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned int flag : 1;             /* Ì×¸Þ                        */
        unsigned int kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned int ersy : 20;            /* ´×° ¼®³»²                   */
    } eilp;
}; 
typedef union reinpret REINPRET;

union reoutret {                       /* ØÀ°Ý ¼Þ®³Î³ ²·              */
    char  retdat[8];                   /* ¾ÞÝÀ²                       */
    struct {                  /* 4W i/o ¾²¼Þ®³                        */
        unsigned int fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned int val1 : 3;             /* ºÃ²Á                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* Ø°ÄÞ »²½Þ                   */
        unsigned int fil2 : 32;            /* Ð ¼Ö³                       */
    } no4w;
    struct {                  /* 4W i/o ²¼Þ®³                         */
        unsigned int fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned int val1 : 3;             /* ºÃ²Á                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int fil2 : 16;            /* Ð ¼Ö³                       */
        unsigned int val2 : 5;             /* ºÃ²Á                        */
        unsigned int kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned int val3 : 4;             /* ºÃ²Á                        */
        unsigned int erco : 4;             /* ´×° ÀÞ²ÌÞÝÙ²                */
        unsigned int val4 : 5;             /* ºÃ²Á                        */
        unsigned int ersy : 11;            /* ´×° ¼®³»²                   */
    } eo4w;
    struct {                  /* Ù°Ìß i/o ¾²¼Þ®³                      */
        unsigned int fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned int resp : 8;             /* Ú½ÎßÝ½                      */
        unsigned int resz : 16;            /* Ø°ÄÞ »²½Þ                   */
        unsigned int fil2 : 32;            /* Ð ¼Ö³                       */
    } nolp;
    struct {                  /* Ù°Ìß i/o ²¼Þ®³                       */
        unsigned int fil1 : 32;            /* Ð ¼Ö³                       */
        unsigned int val1 : 1;             /* ºÃ²Á                        */
        unsigned int syor : 7;             /* ¼®Ø ¼­ÍÞÂ                   */
        unsigned int val2 : 1;             /* ºÃ²Á                        */
        unsigned int kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned int ersy : 20;            /* ´×° ¼®³»²                   */
    } eolp;
};
typedef union reoutret REOUTRET;

