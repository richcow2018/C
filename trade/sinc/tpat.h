/**********************************************************************/
/*                                                                    */
/*        TPAT ŽÃŽ°ŽÌŽÞŽÙ ŽÌŽ«Ž°ŽÏŽ¯ŽÄ     tpat.h      (61.12.  )                */
/*                                    ŽÍŽÝŽºŽ³  (62.12.  )   CC           */
/*                                    ÊÑ¹¹   94.12.20    JJ           */
/*                                    ÊÑ¹¹¼Ô À¾»³  ¿­                 */
/*                                                                    */
/**********************************************************************/

struct mdpatsub {
        short  tpatwsmx;               /* Ž»Ž²ŽÀŽÞŽ² ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ Ž¶ŽÝŽØŽ½Ž³       */
        char   tpattint;               /* md_tint ŽÖŽ³                  */
        char   tpatyob1;               /* ŽÖŽËŽÞ1                        */
        char   tpatyob2[8];            /* ŽÖŽËŽÞ2                        */
        short  tpatioen;               /* Í½È÷                     JJ */
        short  tpatiosu;               /* Í½È÷                     JJ */
        short  tpatcken;               /* Í½È÷                     JJ */
        short  tpatcksu;               /* Í½È÷                     JJ */
        char   tpatyob3[4];            /* ŽÖŽËŽÞ3                     JJ */
};
typedef struct mdpatsub MDPATSUB;      /* DCP ŽÖŽ³                      */
typedef struct mdpatsub TPATSUB;       /* FIP ŽÖŽ³                      */

struct  mdpatko {
        char   tpatgrcd[12]  ;         /* Ž¸ŽÞŽÙŽ°ŽÌŽß ŽºŽ°ŽÄŽÞ                 */
        char   tpatndth      ;         /* NTC ŽÀŽÞŽ²ŽËŽÖŽ³ ŽËŽÖŽ³Ž¼ŽÞ            */
        char   tpatsdth      ;         /* Ž»ŽÌŽÞ Ž¸ŽÞŽÙŽ°ŽÌŽß ŽÀŽÞŽ²ŽËŽÖŽ³ ŽËŽÖŽ³Ž¼ŽÞ     */
        short  tpatiokd      ;         /* IO Ž¼ŽÕŽÍŽÞŽÂ                    */
        short  tpatwsen      ;         /* ŽÕŽ³ŽºŽ³ ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ Ž¶ŽÝŽØŽ½Ž³        */
        short  tpatpctn      ;         /* TPCT Ž´ŽÝŽÄŽØ NO.               */
        char   tpatyob4[4];            /* ŽÖŽËŽÞ4                     JJ */
};
typedef struct mdpatko MDPATKO;        /* DCP ŽÖŽ³                      */
typedef struct mdpatko TPATPSZ;        /* FIP ŽÖŽ³                      */

struct  mdpatws{
        char    tpatwscl;              /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ Ž¼Ž­ŽÍŽÞŽÂ             */
        char    tpatwskb;              /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼ŽÖŽÝ NO. Ž¾Ž¯ŽÃŽ² Ž¸ŽÌŽÞŽÝ  CC */
        short   tpatwsno;              /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ NO.               */
        char   tpatyob5[4];            /* ŽÖŽËŽÞ5                     JJ */
};
typedef struct	mdpatws	MDPATWS;       /* DCP ŽÖŽ³                      */
typedef struct	mdpatws	TPATWS;        /* FIP ŽÖŽ³                      */
