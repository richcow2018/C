/**********************************************************************/
/*                                                                    */
/*       TPLT ŽÃ-ŽÌŽÞŽÙ ŽÌŽ«-ŽÏŽ¯ŽÄ        tplt.h      (63.02.01)              */
/*                                                                    */
/**********************************************************************/

struct mdpltsb {
       short   tpltinen;                 /* Ž²ŽÆŽ¼Ž¬ŽÙ ŽÍŽÝŽºŽ³ŽºŽÍŽÞŽÂŽÌŽÞ Ž¾ŽÝŽÄŽ³Ž´ŽÝŽÄŽØ */
       short   tpltyob0;                 /* ŽÖŽËŽÞ                       */
};
typedef struct mdpltsb TPLTSUB;

struct mdpltko {
       char    tpltyuko;                 /* ŽÕŽ³ŽºŽ³/ŽÑŽºŽ³ ŽËŽ®Ž³Ž¼ŽÞ            */
       char    tpltbkup;                 /* ŽÊŽÞŽ¯Ž¸Ž±Ž¯ŽÌŽß ŽËŽ®Ž³Ž¼ŽÞ            */
       char    tpltlnsb;                 /* Ž¶Ž²Ž¾ŽÝ Ž¼Ž­ŽÍŽÞŽÂ                */
       char    tpltpksb;                 /* ŽÊŽßŽ¯Ž¹-Ž¼ŽÞ Ž¼Ž­ŽÍŽÞŽÂ             */
       char    tpltpckb;                 /* ŽÂŽ³Ž¼ŽÝŽ¾Ž²Ž·ŽÞŽ® Ž¼Ž­ŽÍŽÞŽÂ           */
       char    tpltyob1;                 /* ŽÖŽËŽÞ                       */
       short   tpltlnno;                 /* Ž¶Ž²Ž¾ŽÝ ŽÊŽÞŽÝŽºŽÞŽ³               */
       char    tpltpsnm[22];             /* ŽÊŽßŽ½ŽÒŽ²                     */
       short   tpltyob2;                 /* ŽÖŽËŽÞ                       */
       long    tpltmbid;                 /* ŽÒ-ŽÙŽÎŽÞŽ¯Ž¸Ž½ Ž¼Ž·ŽÍŽÞŽÂŽ¼           */
       char    tpltgadd;                 /* Ž¸ŽÞŽÛ-ŽÊŽÞŽÙŽ±ŽÄŽÞŽÚŽ½ Ž¼ŽÞŽ­Ž¼ŽÝŽ¶ ŽËŽ®Ž³Ž¼ŽÞ */
       char    tpltyob3;                 /* ŽÖŽËŽÞ                       */
       short   tpltdlnk;                 /* Ž¼Ž­Ž³ŽÖŽ³ ŽÃŽÞ-ŽÀŽØŽÝŽ¸Ž½Ž³           */
       short   tpltfahh;                 /* TFAHŽÉ Ž¾ŽÝŽÄŽ³Ž´ŽÝŽÄŽØ            */
       short   tpltfaht;                 /* TFAH ŽÉ Ž»Ž²Ž¼Ž­Ž³Ž´ŽÝŽÄŽØ          */
       char    tpltresv[20];             /* ŽÖŽËŽÞ                       */
};
typedef struct mdpltko TPLTPSZ;




