/**************************************/
/*                                    */
/*               mdmk.h               */
/*                                    */
/*        ŽÖŽ³Ž·ŽÕŽ³ŽÒŽÂŽ¾-Ž¼ŽÞ Ž¶ŽÝŽØŽ²Ž· ŽÌŽµ-ŽÏŽÂŽÄ    */
/*                                    */
/**************************************/
struct mdmkkyo {
    short   mdmkmxen;                   /* Ž»Ž²ŽÀŽÞŽ² Ž´ŽÝŽÄŽØŽ½Ž³           */
    short   mdmkeden;                   /* ŽÍŽÝŽ¼ŽÕŽ³ Ž´ŽÝŽÄŽØŽ½Ž³           */
    long    mdmkmiad;                   /* MIAŽÀŽ²ŽËŽ²Ž· Ž±ŽÄŽÞŽÚŽ½         */
};
typedef struct mdmkkyo MDMKKYO;
struct mdmkkob {
    long    mdmkmsad;                   /* ŽÒŽÂŽ¾-Ž¼ŽÞ Ž±ŽÄŽÞŽÚŽ½           */
    short   mdmkmssz;                   /* ŽÒŽÂŽ¾-Ž¼ŽÞ Ž»Ž²Ž½ŽÞ            */
    char    mdmkyob1;                   /* ŽÖŽËŽÞ 1                  */
};
typedef struct mdmkkob MDMKKOB;
