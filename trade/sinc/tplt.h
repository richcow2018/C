/**********************************************************************/
/*                                                                    */
/*       TPLT Ã-ÌÞÙ Ì«-Ï¯Ä        tplt.h      (63.02.01)              */
/*                                                                    */
/**********************************************************************/

struct mdpltsb {
       short   tpltinen;                 /* ²Æ¼¬Ù ÍÝº³ºÍÞÂÌÞ ¾ÝÄ³´ÝÄØ */
       short   tpltyob0;                 /* ÖËÞ                       */
};
typedef struct mdpltsb TPLTSUB;

struct mdpltko {
       char    tpltyuko;                 /* Õ³º³/Ñº³ Ë®³¼Þ            */
       char    tpltbkup;                 /* ÊÞ¯¸±¯Ìß Ë®³¼Þ            */
       char    tpltlnsb;                 /* ¶²¾Ý ¼­ÍÞÂ                */
       char    tpltpksb;                 /* Êß¯¹-¼Þ ¼­ÍÞÂ             */
       char    tpltpckb;                 /* Â³¼Ý¾²·Þ® ¼­ÍÞÂ           */
       char    tpltyob1;                 /* ÖËÞ                       */
       short   tpltlnno;                 /* ¶²¾Ý ÊÞÝºÞ³               */
       char    tpltpsnm[22];             /* Êß½Ò²                     */
       short   tpltyob2;                 /* ÖËÞ                       */
       long    tpltmbid;                 /* Ò-ÙÎÞ¯¸½ ¼·ÍÞÂ¼           */
       char    tpltgadd;                 /* ¸ÞÛ-ÊÞÙ±ÄÞÚ½ ¼Þ­¼Ý¶ Ë®³¼Þ */
       char    tpltyob3;                 /* ÖËÞ                       */
       short   tpltdlnk;                 /* ¼­³Ö³ ÃÞ-ÀØÝ¸½³           */
       short   tpltfahh;                 /* TFAHÉ ¾ÝÄ³´ÝÄØ            */
       short   tpltfaht;                 /* TFAH É »²¼­³´ÝÄØ          */
       char    tpltresv[20];             /* ÖËÞ                       */
};
typedef struct mdpltko TPLTPSZ;




