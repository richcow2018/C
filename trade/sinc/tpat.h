/**********************************************************************/
/*                                                                    */
/*        TPAT Ã°ĖŪŲ ĖĢ°Ī¯Ä     tpat.h      (61.12.  )                */
/*                                    ÍŨēŗ  (62.12.  )   CC           */
/*                                    ĘŅšš   94.12.20    JJ           */
/*                                    ĘŅššŧÔ Āžģŗ  ŋ­                 */
/*                                                                    */
/**********************************************************************/

struct mdpatsub {
        short  tpatwsmx;               /* ģ˛ĀŪ˛ Ü°¸ŊÃ°ŧŽŨ ļŨØŊŗ       */
        char   tpattint;               /* md_tint Öŗ                  */
        char   tpatyob1;               /* ÖËŪ1                        */
        char   tpatyob2[8];            /* ÖËŪ2                        */
        short  tpatioen;               /* ÍŊČ÷                     JJ */
        short  tpatiosu;               /* ÍŊČ÷                     JJ */
        short  tpatcken;               /* ÍŊČ÷                     JJ */
        short  tpatcksu;               /* ÍŊČ÷                     JJ */
        char   tpatyob3[4];            /* ÖËŪ3                     JJ */
};
typedef struct mdpatsub MDPATSUB;      /* DCP Öŗ                      */
typedef struct mdpatsub TPATSUB;       /* FIP Öŗ                      */

struct  mdpatko {
        char   tpatgrcd[12]  ;         /* ¸ŪŲ°Ėß ē°ÄŪ                 */
        char   tpatndth      ;         /* NTC ĀŪ˛ËÖŗ ËÖŗŧŪ            */
        char   tpatsdth      ;         /* ģĖŪ ¸ŪŲ°Ėß ĀŪ˛ËÖŗ ËÖŗŧŪ     */
        short  tpatiokd      ;         /* IO ŧÕÍŪÂ                    */
        short  tpatwsen      ;         /* Õŗēŗ Ü°¸ŊÃ°ŧŽŨ ļŨØŊŗ        */
        short  tpatpctn      ;         /* TPCT ´ŨÄØ NO.               */
        char   tpatyob4[4];            /* ÖËŪ4                     JJ */
};
typedef struct mdpatko MDPATKO;        /* DCP Öŗ                      */
typedef struct mdpatko TPATPSZ;        /* FIP Öŗ                      */

struct  mdpatws{
        char    tpatwscl;              /* Ü°¸ŊÃ°ŧŽŨ ŧ­ÍŪÂ             */
        char    tpatwskb;              /* Ü°¸ŊÃ°ŧÖŨ NO. ž¯Ã˛ ¸ĖŪŨ  CC */
        short   tpatwsno;              /* Ü°¸ŊÃ°ŧŽŨ NO.               */
        char   tpatyob5[4];            /* ÖËŪ5                     JJ */
};
typedef struct	mdpatws	MDPATWS;       /* DCP Öŗ                      */
typedef struct	mdpatws	TPATWS;        /* FIP Öŗ                      */
