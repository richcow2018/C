/**********************************************************************/
/*                                                                    */
/*        TPLM ŽÃŽ°ŽÌŽÞŽÙ ŽÌŽ«Ž°ŽÏŽ¯ŽÄ       tplm.h           (62.02.  )         */
/*                                                                    */
/**********************************************************************/


struct  tplmpsz {
        short  tplmlpte      ;           /* TFAH ŽÕŽ³ŽºŽ³ Ž´ŽÝŽÄŽØ Ž½Ž³         */
        short  tplmsyob      ;           /* ŽÖŽËŽÞ 1                     */
        short  tplmphn[64]   ;           /* TFAH Ž´ŽÝŽÄŽØ ŽÊŽÞŽÝŽºŽÞŽ³          */
};
typedef struct  tplmpsz TPLMPSZ;         /* BCP ŽÖŽ³                    */
typedef struct  tplmpsz MDPLMKO;         /* DCP ŽÖŽ³                    */
