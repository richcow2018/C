/**********************************************************************/
/*                                                                    */
/*        TLPH Ć°ĢŽŁ Ģ«°ĻÆÄ     tlph.h      (61.12.  )                */
/*                                    ĶŻŗ³  (62.12.  )   CC           */
/*                                    ŹŃ¹¹   94.12.20    JJ           */
/*                                    ŹŃ¹¹¼Ō Ą¾»³  æ­                 */
/*                                    ŹŃ¹¹   96.04.24    SS(ST4310)   */
/*                                    ŹŃ¹¹¼Ō µÜĻĘ  æ­                 */
/*                                                                    */
/**********************************************************************/

struct mdlphsb {
        short   tlphinen;               /* Ķ½Č÷                    JJ */
        char    tlphyob0[6];            /* ÖĖŽ0                    JJ */
};
typedef struct mdlphsb MDLPHSB;         /* DCP Ö³                     */
typedef struct mdlphsb TLPHSUB;         /* FIP Ö³                     */

struct  mdlphko {
        char    tlphkhyo      ;         /* ŗĶŽĀĢŽ Ė®³¼Ž               */
        char    tlphdyrc      ;         /* £Ä£ł£ņ£å£ćĀŠ¾ŻÉ½¼Ø    SS   */
        char    tlphlusb      ;         /* LU ¼­ĶŽĀ                   */
        char    tlphttyp      ;         /* ĄŻĻĀ Ą²Ģß                  */
        short   tlphfahn      ;         /* TFAH “ŻÄŲ NO.              */
        short   tlphlgtn      ;         /* TLGT “ŻÄŲ NO.              */
        short   tlphpuno      ;         /* PU NO.                     */
        short   tlphluno      ;         /* LU NO.                     */
        char    tlphhpas      ;         /* Źß½ ½Ć°Ą½                  */
        char    tlphhopn      ;         /* µ°ĢßŻ ½Ć°Ą½                */
        char    tlphhred      ;         /* Ų°ÄŽ ½Ć°Ą½                 */
        char    tlphhwrt      ;         /* ×²Ä ½Ć°Ą½                  */
        char    tlphhscn      ;         /* æ³¼Ż Į­³¼ ½Ć°Ą½            */
        char    tlphhrcn      ;         /* ¼Ž­¼Ż Į­³¼ ½Ć°Ą½           */
        char    tlphhres      ;         /* µ³Ä³ æ³¼Ż ½Ć°Ą½            */
        char    tlphhsht      ;         /* SHUT - DOWN ½Ć°Ą½         **/
        char    tlphhtex      ;         /* Ā³Į ĆŽŻĢŽŻ ½Ć°Ą½           */
        char    tlphhhdk      ;         /* ĖÄŽ³· Ā³Į ½Ć°Ą½           **/
        short   tlphwrtc      ;         /* ×²Ä ¶³ŻĄ                   */
        char    tlphblct      ;         /* ĢŽ×¹ĀÄ ¼Ö³ ĖÖ³¼Ž          **/
        char    tlphyob2      ;         /* ÖĖŽ2                      **/
        short   tlphtben      ;         /* TLPH ¶øĮÖ³ĢŽ “ŻÄŲ° ŹŽŻŗŽ³ **/
        short   tlphpatn      ;         /* TPAT “ŻÄŲ° ŹŽŻŗŽ³       CC */
        short   tlphyob3      ;         /* ÖĖŽ3                    CC */
        char    tlphpsnm[8]   ;         /* ŪŻŲ Źß½ ¼·ĶŽĀŅ²         CC */
        long    tlphyob4[2]   ;         /* ÖĖŽ4                 CC JJ */
};
typedef struct  mdlphko MDLPHKO;        /* DCP Ö³                     */
typedef struct  mdlphko TLPHPSZ;        /* FIP Ö³                     */
