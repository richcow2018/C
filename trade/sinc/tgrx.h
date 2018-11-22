/*****************************/
/*                           */
/*     tgrx.h                */
/*                           */
/*  Ž¸ŽÞŽÙŽ°ŽÌŽß ŽÃŽ°ŽÌŽÞŽÙ             */
/*          ŽÍŽ¯ŽÀŽÞ ŽÌŽ§Ž²ŽÙ        */
/*                           */
/*****************************/
struct  tgrxsub {
          short  tgrxserh;              /*   Ž» Ž° ŽÁ Ž¶ Ž² Ž¼ Ž² ŽÁ          */
          short  tgrxyobi;              /*     ŽÖ        ŽËŽÞ            */
};
typedef  struct tgrxsub  TGRXSUB;
struct  tgrxpsz {
          char  tgrxpnam[8];            /*    ŽÌŽß ŽÛ Ž¾ Ž½ Ž¼ Ž· ŽÍŽÞ ŽÂ ŽÒ Ž²   */
          char  tgrxkftp;               /*    ŽÌ ŽØ ŽÜ Ž¹ ŽÀ Ž² ŽÌŽß          */
          char  tgrxblok;               /*    Ž» Ž² Ž¼ ŽÝ ŽÌŽÞ ŽÛ Ž¯ Ž¸        */
          short tgrxnode;               /*  ŽÊŽ¯Ž¼ŽÝ ŽÓŽÄ ŽÉŽ°ŽÄŽÞ ŽÊŽÞŽÝŽºŽÞŽ³       */
          char  tgrxkfky[12];           /*     ŽÌ ŽØ ŽÜ Ž¹   Ž·Ž°           */
          char  tgrxsnpn[8];            /*  ŽÊŽ¯Ž¼ŽÝ ŽÓŽÄ ŽÌŽßŽÛŽ¾Ž½ Ž¼Ž·ŽÍŽÞŽÂ ŽÒŽ²    */
          long  tgrxsmid;               /*  Ž¿Ž³Ž¼ŽÝ Ž»Ž· ŽÒŽ°ŽÙŽÎŽÞŽ¯Ž¸Ž½ ID       */
};
typedef struct tgrxpsz  TGRXPSZ;
