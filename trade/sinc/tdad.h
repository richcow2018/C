/**********************************************************************/
/*                                                                    */
/*        TDAD ŽÃŽ°ŽÌŽÞŽÙ ŽÌŽ«Ž°ŽÏŽ¯ŽÄ     tdad.h      (88.01.  )                */
/*                                                                    */
/**********************************************************************/

struct mddadsb {
        short   tdadkbsu;               /* ŽÕŽ³ŽºŽÕ ŽºŽÍŽÞŽÂŽÌŽÞ Ž½Ž³             */
        short   tdadyob0;               /* ŽÖŽËŽÞ0                       */
};
typedef struct mddadsb MDDADSB;         /* DCP ŽÖŽ³                     */
typedef struct mddadsb TDADSUB;         /* FIP ŽÖŽ³                     */

struct  mddadko {
        char    tdadpckb      ;         /* ŽÂŽ³Ž¼ŽÝ Ž¾Ž²Ž·ŽÞŽ® Ž¼ŽÕŽÍŽÞŽÂ           */
        char    tdadyob1[3]   ;         /* ŽÖŽËŽÞ1                       */
        short   tdadread      ;         /* Ž¼ŽÞŽÕŽ¼ŽÝ ŽÃŽÞŽÝŽÌŽÞŽÝ Ž¶Ž¸ŽÉŽ³ Ž±ŽÄŽÞŽÚŽ½ Ž²ŽÁ */
        short   tdadresz      ;         /* Ž¼ŽÞŽÕŽ¼ŽÝ ŽÃŽÞŽÝŽÌŽÞŽÝ Ž»Ž²Ž½ŽÞ Ž²ŽÁ       */
        short   tdadwrad      ;         /* Ž¿Ž±Ž¼ŽÝ ŽÃŽÞŽÝŽÌŽÞŽÝ Ž¶Ž¸ŽÉŽ³ Ž±ŽÄŽÞŽÚŽ½ Ž²ŽÁ  */
        short   tdadwrsz      ;         /* Ž¿Ž³Ž¼ŽÝ ŽÃŽÞŽÝŽÌŽÞŽÝ Ž»Ž²Ž½ŽÞ Ž²ŽÁ        */
};
typedef struct  mddadko MDDADKO;        /* DCP ŽÖŽ³                     */
typedef struct  mddadko TDADPSZ;        /* FIP ŽÖŽ³                     */
