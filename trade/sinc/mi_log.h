/****************************************************************************/
/* ¥Õ¥¡¥¤¥ëÌ¾¡§¡¡mi_log.h                                                   */
/* µ¡Ç½  ¡¡¡¡¡§  ŽÌŽßŽÛŽ¾Ž½ŽÛŽ¸ŽÞ¼èÆÀ´ØÏ¢ŽÏŽ¸ŽÛ                                        */
/* ºîÀ®Æü¡¡  ¡§  1993.12.13                                                 */
/* ÊÑ¹¹Æü¡¡  ¡§  1994.10.14                                             PD0A*/
/*   ¸Î¾ã½èÍýÉ¼(ST1761) Åý¹ç£É¡¿£ÏÂÐ±þ                                      */
/* ÊÑ¹¹Æü¡¡¡¡¡§  1996.03.05                                             PD0R*/ 
/*   »ÅÍÍÊÑ¹¹Í×µá½ñ(SSCY0156) X.25²óÉü´Æ»ëÊÑ¹¹ÂÐ±þ                          */ 
/****************************************************************************/
#include <mc.h>                         /* mc.h                             */
#include <mc_logx.h>                    /* PŽÄŽÚŽ°Ž½¾ðÊó¼èÆÀŽÍŽ¯ŽÀŽÞŽÌŽ§Ž²ŽÙ»ÈÍÑÀë¸À    */
#include <mc_logmac.h>                  /* Ž¼Ž½ŽÃŽÑŽºŽ°ŽÙŽÏŽ¸ŽÛÀë¸ÀŽÍŽ¯ŽÀŽÞŽÌŽ§Ž²ŽÙ»ÈÍÑÀë¸À   */

#define MILOGA00    0x00ff9000          /* ´Ø¿ôTRACEŽÛŽ¸ŽÞID(SI_1)             */
#define MILOGV01    0x00ff9001          /* ¼õ¿®ŽÒŽ¯Ž¾Ž°Ž¼ŽÞŽÛŽ¸ŽÞ                    */
#define MILOGV12    0x00ff9012          /* Èó´°Î»ŽµŽ°ŽÌŽßŽÝ´°Î»ŽÛŽ¸ŽÞ               */
#define MILOGV13    0x00ff9013          /* Èó´°Î»Ž¸ŽÛŽ°Ž½ŽÞ´°Î»ŽÛŽ¸ŽÞ               */
#define MILOGV20    0x00ff9020          /* ÀÞÊÖÀßÄê´°Î»ŽÛŽ¸ŽÞ                  */
#define MILOGV22    0x00ff9022          /* Ãå¸Æ´°Î»ŽÛŽ¸ŽÞ                      */
#define MILOGV23    0x00ff9023          /* È¯¸Æ´°Î»ŽÛŽ¸ŽÞ                      */
#define MILOGV24    0x00ff9024          /* ÈóÆ±´üÄÌÃÎ´°Î»ŽÛŽ¸ŽÞ                */
#define MILOGV25    0x00ff9025          /* ÀÞÊÖ»î¸³ŽÃŽÞŽ°ŽÀÁ÷¿®´°Î»ŽÛŽ¸ŽÞ          */
#define MILOGV26    0x00ff9026          /* ÀÚÃÇ´°Î»ŽÛŽ¸ŽÞ                  PD0A*/
#define MILOGV27    0x00ff9027          /* ŽÃŽÞŽ°ŽÀŽØŽÝŽ¸ºÆÀßÄê´°Î»ŽÛŽ¸ŽÞ         PD0R*/
#define MILOGVSS    0x00ff90f0          /* Æþ¸ýŽÁŽ¬ŽÈŽÙŽ½ŽÃŽ°ŽÀŽ½ŽÛŽ¸ŽÞ                 */
#define MILOGVSE    0x00ff90f1          /* ½Ð¸ýŽÁŽ¬ŽÈŽÙŽ½ŽÃŽ°ŽÀŽ½ŽÛŽ¸ŽÞ                 */
#define MILOGVLP    0x00ff90ff          /* ÏÀÍýŽÊŽßŽ½Ž½ŽÃŽ°ŽÀŽ½¹¹¿·»þŽÛŽ¸ŽÞ            */

#define POF_MKCODE           0
#define POF_SENDPROCESS     32
#define POF_RCVPROCESS      40
#define POF_IFCODE          88
#define POF_SYBETU         144

extern   long   mc_logv();              /* ŽÄŽÚŽ°Ž½¾ðÊó¼èÆÀ                     */
extern   long   mc_loga(long, long, char *);
                                        /* ŽÄŽÚŽ°Ž½¾ðÊó¼èÆÀ                     */

typedef struct {
    char    pnm[8];                     /* Á÷¿®¸µ¥á¡¼¥ë¥Ü¥Ã¥¯¥¹¼±ÊÌ»Ò       */
    long    mkcd;                       /* ¥³¥Þ¥ó¥É¥³¡¼¥É                   */
    long    ifcd;                       /* ¥¤¥ó¥¿¥Õ¥§¡¼¥¹¥³¡¼¥É             */
    long    msgsize;                    /* ¥á¥Ã¥»¡¼¥¸Ä¹¥µ¥¤¥º               */
    char    sybetu[9];                  /* ÄÌÃÎ¼ïÊÌ                         */
    char    lineno[3];                  /* ²óÀþÈÖ¹æ¡¿ÏÀÍýŽÊŽßŽ½ÈÖ¹æ            */
} MMSGTR;                               /* £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó           */

#define PLOG_RVNTFY(P1, P2)             /* PŽÄŽÚŽ°Ž½¼èÆÀ¡ÊOS¤«¤é¤ÎÈóÆ±´üÄÌÃÎ¼õ  */\
                                        /* ¿®»þ¡Ë                           */\
    mc_loga(CL_RVNTFY, P1, (char *)P2)

#define PLOG_RVMIAMSG(P1, P2)           /* PŽÄŽÚŽ°Ž½¼èÆÀ¡Ê£Í£É£ÁÅÅÊ¸¼õ¿®»þ¡Ë    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó           */\
    int i;                              /* ¥ë¡¼¥×¥«¥¦¥ó¥¿                   */\
    for( i = 0; i < 8; i++)             /* Á÷¿®¸µ¥×¥í¥»¥¹¼±ÊÌÌ¾¤ò¼è¤ê½Ð¤¹   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_SENDPROCESS + i);            \
                                        /* £±¥ª¥¯¥Æ¥Ã¥È¥¹¤º¤Ä¼è¤ê½Ð¤¹       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* £Í£Ë¥³¡¼¥É¤ò¼è¤ê½Ð¤¹             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* ¥¤¥ó¥¿¥Õ¥§¡¼¥¹¥³¡¼¥É¤ò¼è¤ê½Ð¤¹   */\
    mmsgtr.msgsize = P1;                /* ¥á¥Ã¥»¡¼¥¸Ä¹¤ò¼è¤ê½Ð¤¹           */\
    if( mmsgtr.ifcd == 0x58001000 )     /* Ž²ŽÝŽÀŽ°ŽÌŽªŽ°Ž½ŽºŽ°ŽÄŽÞ¤¬ŽÕŽ°ŽÃŽ¨ŽØŽÃŽ¨µ¯Æ°°ÍÍê»þ¡¡*/\
    {                                                                         \
        for( i = 0; i < 9; i++)         /* ÄÌÃÎ¼ïÊÌ¤ò¼è¤ê½Ð¤¹               */\
        {                                                                     \
            mmsgtr.sybetu[i] = *(char *)((long)P2 + POF_SYBETU + i);          \
                                        /* £±¥ª¥¯¥Æ¥Ã¥È¥¹¤º¤Ä¼è¤ê½Ð¤¹       */\
        }                                                                     \
    }                                                                         \
    mc_loga(                                                                  \
        CL_RVMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
		(char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* £Ð¥È¥ì¡¼¥¹¼èÆÀ                   */\
                                        /*   £Í£É£ÁÅÅÊ¸¼õ¿®¤Î¥í¥°           */\
                                        /*   £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó¤Î¥µ¥¤¥º */\
                                        /*   £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó¤Î³ÊÇ¼°è */\
                                        /*   ¼õ¿®ÅÅÊ¸Ä¹                     */\
}
#define PLOG_SDMIAMSG(P1, P2)           /* PŽÄŽÚŽ°Ž½¼èÆÀ¡Ê£Í£É£ÁÅÅÊ¸Á÷¿®»þ¡Ë    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó           */\
    int i;                              /* ¥ë¡¼¥×¥«¥¦¥ó¥¿                   */\
    for( i = 0; i < 8; i++)             /* Á÷¿®Àè¥×¥í¥»¥¹¼±ÊÌÌ¾¤ò¼è¤ê½Ð¤¹   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_RCVPROCESS + i);             \
                                        /* £±¥ª¥¯¥Æ¥Ã¥È¥¹¤º¤Ä¼è¤ê½Ð¤¹       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* £Í£Ë¥³¡¼¥É¤ò¼è¤ê½Ð¤¹             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* ¥¤¥ó¥¿¥Õ¥§¡¼¥¹¥³¡¼¥É¤ò¼è¤ê½Ð¤¹   */\
    mmsgtr.msgsize = P1;                /* ¥á¥Ã¥»¡¼¥¸Ä¹¤ò¼è¤ê½Ð¤¹           */\
    mc_loga(                                                                  \
        CL_SDMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
        (char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* £Ð¥È¥ì¡¼¥¹¼èÆÀ                   */\
                                        /*   £Í£É£ÁÅÅÊ¸Á÷¿®¤Î¥í¥°           */\
                                        /*   £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó¤Î¥µ¥¤¥º */\
                                        /*   £Í£É£ÁÅÅÊ¸¥È¥ì¡¼¥¹¾ðÊó¤Î³ÊÇ¼°è */\
                                        /*   Á÷¿®ÅÅÊ¸Ä¹                     */\
}
/****************************************/
/* IRB¾ðÊó¼èÆÀŽÏŽ¸ŽÛ¡¡¡¡                   */
/* <¼èÆÀ¾ðÊó>                           */
/*  ­¡¡¡IRŽºŽ°ŽÄŽÞ                          */
/*  ­¢¡¡Ž»ŽÌŽÞIRŽºŽ°ŽÄŽÞ                       */
/*  ­£  ŽÒŽ¯Ž¾Ž°Ž¼ŽÞŽ±ŽÄŽÞŽÚŽ½                     */
/*  ­¤  ŽÒŽ¯Ž¾Ž°Ž¼ŽÞÄ¹¡¡                      */
/****************************************/
#define LOG_IRB(p1)                                                           \
{                                                                             \
    mc_logv(MILOGV01, 5L,                                                     \
            (long)((MIIRB *)p1)->ir_cd,                                       \
            (long)((MIIRB *)p1)->sir_cd,                                      \
            (long)(((MIIRB *)p1)->msgp),                                      \
            (long)((MIIRB *)p1)->msglen,                                      \
            (long)((MILCTX *)((MIIRB *)p1)->ctxtp)->lineno);                  \
                                        /* ŽÛŽ¸ŽÞ¼èÆÀ´Ø¿ô¼Â¹Ô              PD0A*/\
}
/****************************************/
/* ÏÀÍýŽÊŽßŽ½Ž½ŽÃŽ°ŽÀŽ½¹¹¿·¾ðÊó¼èÆÀŽÏŽ¸ŽÛ          */
/* <¼èÆÀ¾ðÊó>                           */
/*      ¹¹¿·Á°ÏÀÍýŽÊŽßŽ½Ž½ŽÃŽ°ŽÀŽ½              */
/*      ¹¹¿·¸åÏÀÍýŽÊŽßŽ½Ž½ŽÃŽ°ŽÀŽ½              */
/*      ŽÓŽ¼ŽÞŽ­Ž°ŽÙID                        */
/****************************************/
#define LOG_LPT(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* ŽÛŽ¸ŽÞ¼èÆÀ´Ø¿ô¼Â¹Ô                  */\
}
/****************************************/
/* Ž¼Ž½ŽÃŽÑŽºŽ°ŽÙÊÖµÑÃÍ¾ðÊó¼èÆÀŽÏŽ¸ŽÛ             */
/* <¼èÆÀ¾ðÊó>                           */
/*      Èó´°Î»Ž¼Ž½ŽÃŽÑŽºŽ°ŽÙÊÖµÑÃÍ             */
/*      ŽÓŽ¼ŽÞŽ­Ž°ŽÙID                        */
/****************************************/
#define LOG_RTN(p1, p2, p3)                                                   \
{                                                                             \
    mc_logv(p1, 2L,(long)p2, (long)(0x67ff0000 | ((long)p3)));                \
								        /* ŽÛŽ¸ŽÞ¼èÆÀ´Ø¿ô¼Â¹Ô                  */\
}
/****************************************/
/* Ž½ŽÃŽ°ŽÀŽ½¾ðÊó¼èÆÀŽÏŽ¸ŽÛ                     */
/* <¼èÆÀ¾ðÊó>                           */
/*      ÏÀÍýŽÁŽ¬ŽÈŽÙŽ½ŽÃŽ°ŽÀŽ½                   */
/*      ÊªÍýŽÁŽ¬ŽÈŽÙŽ½ŽÃŽ°ŽÀŽ½                   */
/*      ŽÓŽ¼ŽÞŽ­Ž°ŽÙID                        */
/****************************************/
#define LOG_STS(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* ŽÛŽ¸ŽÞ¼èÆÀ´Ø¿ô¼Â¹Ô                  */\
}
/****************************************/
/* ´Ø¿ôŽÄŽÚŽ°Ž½¾ðÊó¼èÆÀŽÏŽ¸ŽÛ(SI1ŽÃŽ½ŽÄÍÑ)        */
/****************************************/
#ifdef  SI_1
#define DBGTRACE(P1)                                                          \
{                                                                             \
    printf(P1);                                                               \
    printf("\n");                                                             \
}
#else
#define DBGTRACE(P1)                                                          \
{                                                                             \
    mc_loga(MILOGA00, 8, (char *)P1);   /* ŽÛŽ¸ŽÞ¼èÆÀ´Ø¿ô¼Â¹Ô              PD0A*/\
}
#endif
/****************************************/
/* ŽÀŽÞŽÝŽÌŽß¼èÆÀŽÏŽ¸ŽÛ(SI1ŽÃŽ½ŽÄÍÑ)               */
/****************************************/
#ifdef  SI_D
#define DBGDMP(P1, P2)                                                        \
{                                                                             \
    extern  long   DumpHex();                                                 \
	DumpHex(P1, P2);                    /* ŽÀŽÞŽÝŽÌŽß¼èÆÀ´Ø¿ô¼Â¹Ô                */\
}
#else
#define DBGDMP(P1, P2)
#endif
