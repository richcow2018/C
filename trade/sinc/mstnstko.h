/***************************************/
/*                                     */
/*        mstnstko.h                   */
/*                                     */
/*       TNST ŽÀŽ²ŽË  Ž´ŽØŽ±                 */
/*                                     */
/***************************************/

struct mstnstko {
    char  tnstshyo ;                    /* Ž¼ŽÖŽ³ŽÁŽ­Ž³ ŽËŽ®Ž³Ž¼ŽÞ            */
    char  tnststts ;                    /* Ž½ŽÃŽ°ŽÀŽ½                   */
    short tnstyob1 ;                    /* ŽÖ ŽËŽÞ                    */
    long  tnstbadr ;                    /* ŽÀŽ²ŽË MIA ŽÏŽ´  ŽÉ  Ž±ŽÄŽÞŽÚŽ½    */
    long  tnstaadr ;                    /* ŽÀŽ²ŽË MIA ŽÂŽ·ŽÞ ŽÉ  Ž±ŽÄŽÞŽÚŽ½    */
                                        /* ŽÀŽ²ŽË MIA                 */
    char  tnstmia[sizeof(MCMIKYO) + sizeof(MSMIAUIP)] ;
    char  tnstmsg[MSMGBFSZ] ;           /* ŽÀŽ²ŽË Ž¼ŽÞŽ­Ž¼ŽÝ ŽÒŽ¯Ž¾Ž°Ž¼ŽÞ Ž´ŽØŽ±    */
};
typedef struct mstnstko MSNSTK1 ;
