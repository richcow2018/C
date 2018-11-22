/**********************************************************************/
/*   TFAZ KOBETSUBU                                                   */
/**********************************************************************/
struct    tfazpsz  {                 /*                               */
    unsigned char  tfazfnam[18] ;    /* ŽÄŽ¸Ž¼Ž­ ŽÌŽ§Ž²ŽÙ ŽÒŽ²                  */
    unsigned char  tfaznull[2]  ;    /* ŽÊŽßŽ½ŽÒŽ² Ž½ŽÄŽ¯ŽÊŽßŽ°                  */
    unsigned char  tfazcrku     ;    /* ŽÊŽ¯ŽÁŽ¬Ž¸ ŽÖŽËŽÞ Ž¸ŽÌŽÞŽÝ                */
    unsigned char  tfazyob1[3]  ;    /* ŽÖŽËŽÞ 1                         */
}   ;                                /*                               */
typedef struct tfazpsz  TFAZPSZ;     /*                               */
