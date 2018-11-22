/***************************************/
/*                                     */
/*              tlgt.h                 */
/*                                     */
/*        TLGT ŽÃŽ°ŽÌŽÞŽÙ ŽÌŽ«Ž°ŽÏŽ¯ŽÄ            */
/*                                     */
/* ÊÑ¹¹  94.12.20 JJ  ÊÑ¹¹¼Ô  À¾»³  ¿­ */
/*                                     */
/***************************************/

struct mdlgtsb {
    short    tlgtinen;            /* Í½È÷                   JJ */
    char     tlgtyob0[6];         /* ŽÖŽËŽÞ0                   JJ */
};
typedef struct mdlgtsb MDLGTSB;   /* DCP ŽÖŽ³                    */
typedef struct mdlgtsb TLGTSUB;   /* FIP ŽÖŽ³                    */

struct mdlgtko {
	char   tlgtkhyo    ;      /* ŽºŽÍŽÞŽÂŽÌŽÞ ŽËŽ®Ž³Ž¼ŽÞ               */
	char   tlgtyob1[3] ;      /* ŽÖŽËŽÞ1                       */
	short  tlgtlphn    ;      /* TLPH Ž´ŽÝŽÄŽØ NO.              */
	short  tlgtlptn    ;      /* TLPT Ž´ŽÝŽÄŽØ NO.              */
	short  tlgtpatn    ;      /* TPAT Ž´ŽÝŽÄŽØ NO.              */
	short  tlgtyob2    ;      /* ŽÖŽËŽÞ2                       */
	long   *tlgtmiaa   ;      /* Ž×Ž²ŽÄ MIA ŽÀŽ²ŽËŽ²Ž· Ž±ŽÄŽÞŽÚŽ½        */
	long   *tlgtdsad   ;      /* ŽÎŽØŽ­Ž³ ŽÃŽÞŽ°ŽÀ ŽÀŽ²ŽË Ž±ŽÄŽÞŽÚŽ½        */
	char   tlgtyob3[4] ;      /* ŽÖŽËŽÞ3                    JJ */
};
typedef struct mdlgtko MDLGTKO;   /* DCP ŽÖŽ³                     */
typedef struct mdlgtko TLGTPSZ;   /* FIP ŽÖŽ³                     */
