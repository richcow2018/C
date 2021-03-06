/******************************************/
/*                                        */
/*               mdretv.h                 */
/*                                        */
/*            SMPº°Ù(DCP)ÍÝ·¬¸Á           */
/*                                        */
/* ½¤Àµ¤·¤¿Æü¡§£±£¹£¹£µÇ¯£¶·î£²£°Æü    M01*/
/* »áÌ¾¡¡¡¡¡¡¡§¿·Æ£Í³Èþ					  */
/*     ÒÓØÊß¯Á´×°¤òÄÉ²Ã¤·¤¿				  */
/*	   »ÅÍÍÊÑ¹¹Í×µá½ñ¡§SSCY0079		   	  */
/******************************************/

#define  MDNORMAL    0l      	/*  ¾²¼Þ®³ ¼­³Ø®³¡¡       */
#define  MDIVPARM   0xffff0001	/*  Êß×Ò°À ´×°            */
#define  MDDUBREQ   0xffff0002	/*  Æ¼Þ­³ Ö³·­³¡¡         */
#define  MDNOTRCV   0xffff0003	/*  ³¹Â¹ Ì¶      ¡¡       */
#define  MDMSNDER   0xffff0004	/*  Ò¯¾°¼Þ ¿³¼Ý ²¼Þ®³     */
#define  MDTBLERR   0xffff0005	/*  Ã°ÌÞÙ ´×°       ¡¡    */
#define  MDPBUFER   0xffff0006	/*  Ìß°ÙÊÞ¯Ì§ ¶¸Î ²¼Þ®³   */
#define  MDOVRENT   0xffff0007	/*  Ä³Û¸½³ µ°ÊÞ°          */
#define  MDIFAERR   0xffff0008	/*  ²ÝÀ°Ìª°½ ´×°      ¡¡  */
#define  MDDIVSEQ   0xffff0009	/*  ÌÞÝ¶Â ¼°¹Ý½ ´×°       */
#define  MDINVENT   0xffff000a	/*  Ä³Û¸ Ñº³    ¡¡        */
#define  MDLPCHNG   0xffff000b	/*  ÛÝØÊß½ ·Ø¶´Á­³        */
#define  MDLPRSTR   0xffff000c	/*  ÛÝØÊß½ »²¶²¼Á­³       */
#define  MDLPCLSE   0xffff000d	/*  ÛÝØÊß½ ¸Û°½ÞÁ­³       */
#define  MDLPUNUS   0xffff000e	/*  ÛÝØÊß½ Ð¼Ö³           */
#define  MDOVRLNG   0xffff0010	/*  »²½Þ ÌÞ¿¸             */
#define  MDOTHDWN   0xffff0012	/*  À¹² ¼®³¶Þ²            */
#define  MDNOTONL   0xffff0013	/*  ³ÝÃÝ Ó°ÄÞ ´×°         */
#define  MDHRDERR   0xffff0014	/*  Ê°ÄÞ ¼®³¶Þ²           */
#define  MDCHBLOK   0xffff0015	/*  Á¬ÈÙ ¼Ö³Á­³           */
#define  MDDATERR   0xffff0016	/*  Ö³·Õ³ ¼ÞÖ³Î³ Ì¾²      */
#define  MDNOTCLS   0xffff0017	/*  ÛÝØÊß½ Ð¸Û°½Þ         */
#define  MDCDEXER   0xffff0018	/*  ¶¸Á®³Î³ ´×°(¿Þ¯º³Ì¶)  */
#define  MDEXTRER   0xffff0019	/*  ¶¸Á®³Î³ ´×°(¿Þ¯º³¶)   */
#define  MDNCNNLN   0xffff001a	/*  ÃÞÝÜÓ³ Ð¾Â¿Þ¸         */
#define  MDNOUSLN   0xffff001b	/*  ¶²¾Ý Ñ¼ÞÕÝ            */
#define  MDNOTUSE   0xffff001c	/*  DCP ¼Ö³ Ì¶            */
#define  MDINTLER   0xffff001d	/*  TINT ÛÝØ Ñ¼ÞÕÝ        */
#define  MDNOTACC   0xffff001e	/*  ±¸¾½¹Ý Å¼             */
#define  MDMEPTER   0xffff001f	/*  ÒÓØÊß¯Á´×°         M01*/
#define  MDUNDFCD   0xffff8000	/*  ÐÃ²·Þ º°ÄÞ ¹Ý¼­Â      */
#define  MDUDFOLG   0xffff8010	/*  »²½ÞÌÞ¿¸ & ÐÃ²·Þ º°ÄÞ */
#define  MDUDCDER   0xffff8018	/*  ¶¸Á®³Î³ ´×°(¿Þ¯º³Ì¶)  */
                                /*   & ÐÃ²·Þ º°ÄÞ         */
#define  MDUDEXER   0xffff8019	/*  ¶¸Á®³Î³ ´×°(¿Þ¯º³¶)   */
                                /*   & ÐÃ²·Þ º°ÄÞ         */
