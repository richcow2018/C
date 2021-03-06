/**********************************************************************/
/*                                                                    */
/*        TLPT Ć°ĢŽŁ Ģ«°ĻÆÄ     tlpt.h      (61.12.  )                */
/*                                    ĶŻŗ³  (62.12.  )   CC           */
/*                                    ŹŃ¹¹   94.12.20    JJ           */
/*                                    ŹŃ¹¹¼Ō Ą¾»³  æ­                 */
/*                                    ŹŃ¹¹   95.06.08    SS           */
/*                                    ŹŃ¹¹¼Ō æ·Ę£Ķ³Čž	 ST2772		  */
/*                                    ŹŃ¹¹   95.05.06    KK           */
/*                                    ŹŃ¹¹¼Ō ĖĢĄ¾ĆŅĶĪ	 SSCY0167  	  */
/*                                                                    */
/**********************************************************************/

struct mdlptsb {
        short    tlptinen;               /* Ķ½Č÷                   JJ */
        char     tlptyob0[6];            /* ÖĖŽ0                   JJ */
};
typedef struct mdlptsb MDLPTSB;          /* DCP Ö³                    */
typedef struct mdlptsb TLPTSUB;          /* FIP Ö³                    */

struct mdlptko {
	char   tlptkhyo    ;                 /* ŗĶŽĀĢŽ Ė®³¼Ž              */
	char   tlptyob1[2] ;                 /* ÖĖŽ1                   KK */
	char   tlptdcfg    ;                 /* ¶²¾Ż·Ų¶“ Ģ×øŽ          KK */
	short  tlptfapn    ;                 /* TFAP “ŻÄŲ NO.             */
	short  tlptlgtn    ;                 /* TLGT “ŻÄŲ NO.             */
	char   tlptipas    ;                 /* Źß½ ½Ć°Ą½                 */
	char   tlptiatt    ;                 /* ATT ½Ć°Ą½                 */
	char   tlptihdk    ;                 /* ĖÄŽ³· ½Ć°Ą½               */
	char   tlptcomm    ;                 /* „³„Ž„ó„ÉĢ¾			   SS */
	short  tlptpatn    ;                 /* TPAT “ŻÄŲ ŹŽŻŗŽ³       CC */
	short  tlptyob3    ;                 /* ÖĖŽ3                   CC */
	char   tlptpsnm[8] ;                 /* ŪŻŲ Źß½ ¼·ĶŽĀŅ²        CC */
	char   tlptyob4[4] ;                 /* ÖĖŽ4                   JJ */
};
typedef struct mdlptko MDLPTKO;          /* DCP Ö³                    */
typedef struct mdlptko TLPTPSZ;          /* FIP Ö³                    */
