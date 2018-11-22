/**********************************************************************/
/*                                                                    */
/*        TLPH ŽÃŽ°ŽÌŽÞŽÙ ŽÌŽ«Ž°ŽÏŽ¯ŽÄ     tlph.h      (61.12.  )                */
/*                                    ŽÍŽÝŽºŽ³  (62.12.  )   CC           */
/*                                    ÊÑ¹¹   94.12.20    JJ           */
/*                                    ÊÑ¹¹¼Ô À¾»³  ¿­                 */
/*                                    ÊÑ¹¹   96.04.24    SS(ST4310)   */
/*                                    ÊÑ¹¹¼Ô µÜÏÆ  ¿­                 */
/*                                                                    */
/**********************************************************************/

struct mdlphsb {
        short   tlphinen;               /* Í½È÷                    JJ */
        char    tlphyob0[6];            /* ŽÖŽËŽÞ0                    JJ */
};
typedef struct mdlphsb MDLPHSB;         /* DCP ŽÖŽ³                     */
typedef struct mdlphsb TLPHSUB;         /* FIP ŽÖŽ³                     */

struct  mdlphko {
        char    tlphkhyo      ;         /* ŽºŽÍŽÞŽÂŽÌŽÞ ŽËŽ®Ž³Ž¼ŽÞ               */
        char    tlphdyrc      ;         /* £Ä£ù£ò£å£ãÂÐ¾ÝÉ½¼¨    SS   */
        char    tlphlusb      ;         /* LU Ž¼Ž­ŽÍŽÞŽÂ                   */
        char    tlphttyp      ;         /* ŽÀŽÝŽÏŽÂ ŽÀŽ²ŽÌŽß                  */
        short   tlphfahn      ;         /* TFAH Ž´ŽÝŽÄŽØ NO.              */
        short   tlphlgtn      ;         /* TLGT Ž´ŽÝŽÄŽØ NO.              */
        short   tlphpuno      ;         /* PU NO.                     */
        short   tlphluno      ;         /* LU NO.                     */
        char    tlphhpas      ;         /* ŽÊŽßŽ½ Ž½ŽÃŽ°ŽÀŽ½                  */
        char    tlphhopn      ;         /* ŽµŽ°ŽÌŽßŽÝ Ž½ŽÃŽ°ŽÀŽ½                */
        char    tlphhred      ;         /* ŽØŽ°ŽÄŽÞ Ž½ŽÃŽ°ŽÀŽ½                 */
        char    tlphhwrt      ;         /* Ž×Ž²ŽÄ Ž½ŽÃŽ°ŽÀŽ½                  */
        char    tlphhscn      ;         /* Ž¿Ž³Ž¼ŽÝ ŽÁŽ­Ž³Ž¼ Ž½ŽÃŽ°ŽÀŽ½            */
        char    tlphhrcn      ;         /* Ž¼ŽÞŽ­Ž¼ŽÝ ŽÁŽ­Ž³Ž¼ Ž½ŽÃŽ°ŽÀŽ½           */
        char    tlphhres      ;         /* ŽµŽ³ŽÄŽ³ Ž¿Ž³Ž¼ŽÝ Ž½ŽÃŽ°ŽÀŽ½            */
        char    tlphhsht      ;         /* SHUT - DOWN Ž½ŽÃŽ°ŽÀŽ½         **/
        char    tlphhtex      ;         /* ŽÂŽ³ŽÁ ŽÃŽÞŽÝŽÌŽÞŽÝ Ž½ŽÃŽ°ŽÀŽ½           */
        char    tlphhhdk      ;         /* ŽËŽÄŽÞŽ³Ž· ŽÂŽ³ŽÁ Ž½ŽÃŽ°ŽÀŽ½           **/
        short   tlphwrtc      ;         /* Ž×Ž²ŽÄ Ž¶Ž³ŽÝŽÀ                   */
        char    tlphblct      ;         /* ŽÌŽÞŽ×Ž¹ŽÂŽÄ Ž¼ŽÖŽ³ ŽËŽÖŽ³Ž¼ŽÞ          **/
        char    tlphyob2      ;         /* ŽÖŽËŽÞ2                      **/
        short   tlphtben      ;         /* TLPH Ž¶Ž¸ŽÁŽÖŽ³ŽÌŽÞ Ž´ŽÝŽÄŽØŽ° ŽÊŽÞŽÝŽºŽÞŽ³ **/
        short   tlphpatn      ;         /* TPAT Ž´ŽÝŽÄŽØŽ° ŽÊŽÞŽÝŽºŽÞŽ³       CC */
        short   tlphyob3      ;         /* ŽÖŽËŽÞ3                    CC */
        char    tlphpsnm[8]   ;         /* ŽÛŽÝŽØ ŽÊŽßŽ½ Ž¼Ž·ŽÍŽÞŽÂŽÒŽ²         CC */
        long    tlphyob4[2]   ;         /* ŽÖŽËŽÞ4                 CC JJ */
};
typedef struct  mdlphko MDLPHKO;        /* DCP ŽÖŽ³                     */
typedef struct  mdlphko TLPHPSZ;        /* FIP ŽÖŽ³                     */
