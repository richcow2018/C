/**********************************/
/*                     V/R = 0/0  */
/*                     88.03.30   */
/*          meiwrt.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ¡ãÀß·×½¤Àµ¼ÔÌ¾¡ä					±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÃ´Åö(Ò°¶:ºÑ±¯Ìß)*/
/*     ¡ãÀß·×½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä¡¡£±£¹£¹£³Ç¯¡¡£··î¡¡£±Æü     PD01*/
/*                                      rd´ÉÍý¾ðÊóÊÑ¹¹¤Î°Ù            */
/*     								   £±£¹£¹£´Ç¯¡¡£´·î£±£²Æü     M02 */
/*                                      ËÞ¯ÄÌ¨°ÙÄÞ¤ÎÊäÀµ(v684ccÂÐ±þ)  */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o º°ÄÞ             */
#define   WLPIO     0x00                 /* Ù°Ìß i/o º°ÄÞ           */
#define   W4WNT     0x40                 /* 4W-NTM i/o º°ÄÞ         */
#define   W4WSY     0xc1                 /* 4W,4W-NTM ¼®Ø¼­ÍÞÂ      */
#define   WLPSY     0xc2                 /* Ù°Ìß ¼®Ø¼­ÍÞÂ           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* ¾²¼Þ®³                  */
#define   M0OSRETE  -1                   /* OS ÍÝ·¬¸Á ²¼Þ®³         */
#define   M0IFAERR  -2                  /* ¼¹ÞÝ ¾ÝÕ³ ºÞ ²ÝÀÌª°½ ´×° */
/*******************************/
/*          wrtwork.h          */
/*******************************/
struct wrtwork {                         /* Ë·½³ Æ­³Ø®¸ ¼Þ®³Î³      */
       short  pathno;                    /* ÛÝØÊß½ ÊÞÝºÞ³           */
       char   syoricod;                  /* ¼®Ø º°ÄÞ                */
       char   yobi1;                     /* ÖËÞ                     */
       short  tmvid;                     /* À²ÏÁ ¼·ÍÞÂ¼             */
       long   retadd;                    /* ØÀ°Ý ±ÄÞÚ½              */
       long   outadd;                    /* ¼­ÂØ®¸ ²· ±ÄÞÚ½         */
       short  outsize;                   /* ¼­ÂØ®¸ ²· »²½Þ          */
       long   dosapara;                  /* ÄÞ³» Êß×Ò°À             */
       long   sysret;                    /* ¼½ÃÑ ÍÝ·¬¸Á             */
       long   usrrd;                     /* Õ°»ÞØ¸´½Ä¼±ÊÌ»Ò		PD01*/
};
typedef struct wrtwork WRTWORK;
union wrinpret {                       /* ROS ØÀ°Ý ¼Þ®³Î³             */
    long  retdat;                      /* ¾ÞÝÀ²                       */
    char  retros[4];                   /* ¾ÞÝÀ²                       */
    struct {                  /* 4W i/o ¾²¼Þ®³                        */
        unsigned erfl : 1;             /* ´×° Ì×¸Þ                    */
        unsigned fil1 : 10;            /* Ð ¼Ö³                       */
        unsigned rvda : 5;             /* RV                          */
        unsigned syda : 11;            /* ¼®³»² ¼Þ®³Î³                */
        unsigned fil2 : 5;             /* Ð ¼Ö³                       */
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
        unsigned fil1 : 7;             /* Ð ¼Ö³                       */
        unsigned resp : 8;             /* Ú½ÎßÝ½                      */
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
typedef union wrinpret WRINPRET;
union wroutret {                       /* ØÀ°Ý ¼Þ®³Î³ ²·              */
    char  retdat[8];                   /* ¾ÞÝÀ²                       */
    struct {                  /* 4W i/o ¾²¼Þ®³                        */
        unsigned fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned val1 : 3;             /* ºÃ²Á                        */
        unsigned rvda : 5;             /* RV                          */
        unsigned fil2 : 16;            /* Ð ¼Ö³                   M02 */
        unsigned fil3 : 16;            /* Ð ¼Ö³                   M02 */
        unsigned val2 : 5;             /* ºÃ²Á                        */
        unsigned syda : 11;            /* ¼®³»² ¼Þ®³Î³                */
    } no4w;
    struct {                  /* 4W i/o ²¼Þ®³                         */
        unsigned fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned val1 : 3;             /* ºÃ²Á                        */
        unsigned rvda : 5;             /* RV                          */
        unsigned fil2 : 16;            /* Ð ¼Ö³                       */
        unsigned val2 : 5;             /* ºÃ²Á                        */
        unsigned kens : 3;             /* ¹Ý¼­Â ÓÄ                    */
        unsigned val3 : 4;             /* ºÃ²Á                        */
        unsigned erco : 4;             /* ´×° ÀÞ²ÌÞÝÙ²                */
        unsigned val4 : 5;             /* ºÃ²Á                        */
        unsigned ersy : 11;            /* ´×° ¼®³»²                   */
    } eo4w;
    struct {                  /* Ù°Ìß i/o ¾²¼Þ®³                      */
        unsigned fil1 : 8;             /* Ð ¼Ö³                       */
        unsigned resp : 8;             /* Ú½ÎßÝ½                      */
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
typedef union wroutret WROUTRET;
