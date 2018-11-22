/*********************************************/
/*                                           */
/*               mdat.h                      */
/*                                           */
/*          Ž±ŽÃŽ»Ž· Ž¶ŽÝŽØŽ²Ž· ŽÌŽ«Ž°ŽÏŽ¯ŽÄ                */
/*                                           */
/*********************************************/

struct mdatkyo {
	short	mdatmxen;           /* Ž»Ž²ŽÀŽÞŽ² Ž´ŽÝŽÄŽØŽ½Ž³           */
	short	mdateden;           /* ŽÍŽÝŽ¼Ž­Ž³ Ž´ŽÝŽÄŽØŽ½Ž³           */
};
typedef struct mdatkyo MDATKYO;

struct mdatko {
	char	mdatedst;           /* ŽÍŽÝŽ¼Ž­Ž³ Ž½ŽÃŽ°ŽÀŽ½            */
	char	mdatakbn;           /* Ž±ŽÃŽ»Ž· Ž¸ŽÌŽÞŽÝ              */
	char	mdatfndt;           /* Ž»Ž²Ž¼Ž­Ž³ ŽÃŽÞŽ°ŽÀ Ž¼Ž­ŽÍŽÞŽÂ       */
	char	mdatkkst;           /* Ž¹Ž²Ž¶ŽÝ Ž½ŽÃŽ°ŽÀŽ½             */
	short	mdatwsno;           /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ NO.          */
	short 	mdatanod;           /* Ž±ŽÃŽ»Ž· ŽÉŽ°ŽÄŽÞ              */
	char 	mdatfwcd[2];        /* ŽÌŽØŽÜŽ¹ ŽºŽ°ŽÄŽÞ              */
	char 	mdatyob1[2];        /* ŽÖŽËŽÞ1                   */
	char 	mdatpsid[8];        /* ŽÌŽßŽÛŽ¾Ž½ Ž¼Ž·ŽÍŽÞŽÂŽÒŽ²          */
	long	mdatmsad;           /* ŽÒŽ¯Ž¾Ž°Ž¼ŽÞ Ž¶ŽÝŽØŽ²Ž· Ž±ŽÄŽÞŽÚŽ½     */
};
typedef struct mdatko MDATKO;
