/****************************NTC-SMP FIP******************************/
/*                                                                   */
/*    1.ŽÌŽ§Ž²ŽÙŽÒŽ²       FIPŽ¶ŽÝŽØ Ž¼Ž¹ŽÞŽÝ ŽÍŽÝŽ¼Ž­Ž³ ŽÉ ŽºŽ³Ž¿ŽÞŽ³ŽÀŽ²(mfed.h)             */
/*                                                                   */
/*    2.Ž¸ŽÌŽÞŽÝ                                                         */
/*                                                                   */
/*    3.ŽØŽÚŽ·          Ž¾Ž¯Ž¹Ž²Ž¼Ž¬    Ž³ŽÁŽÀŽÞ                                  */ 
/*                   Ž»Ž¸Ž¾Ž²Ž¼Ž¬    Ž³ŽÁŽÀŽÞ        88'10/18                  */
/*********************************************************************/
struct fipred{
    long    emteno;                     /* EMT Ž´ŽÝŽÄŽØ ŽÅŽÝŽÊŽÞ             */
    long    exteno;                     /* Ž¶Ž¸ŽÁŽ®Ž³ EXT Ž´ŽÝŽÄŽØ ŽÅŽÝŽÊŽÞ       */
    char    rsname[5];                  /* Ž¼Ž¹ŽÞŽÝ ŽÒŽ²Ž¼Ž®Ž³                */
    char   *rsfname;                    /* Ž¼Ž¹ŽÞŽÝ ŽÒŽ²Ž¼Ž®Ž³ (file)         */
    char    *rskind;                    /* Ž¼Ž¹ŽÞŽÝ Ž¼Ž­ŽÍŽÞŽÂ                */
    long    smphid;                     /* Ž¾ŽÏŽÌŽ« Ž¼Ž·ŽÍŽÞŽÂŽ¼               */
    short   senq;                       /* Ž¾ŽÝŽÕŽ³ Ž¼ŽÞŽ­ŽÝŽ²                */
    short   kenq;                       /* ŽºŽÍŽÞŽÂŽÌŽÞ Ž¾ŽÝŽÕŽ³ Ž¼ŽÞŽ­ŽÝŽ²         */
    long    rsno;                       /* Ž¼Ž¹ŽÞŽÝ ŽÊŽÞŽÝŽºŽÞŽ³               */
    char    puno;                       /* PU ŽÅŽÝŽÊŽÞ                   */
    unsigned char    rsstat;                     /* Ž¼Ž¹ŽÞŽÝ Ž¿ŽÞŽ¸Ž¾Ž²                */
    long    lncnt ;                     /* Ž×Ž²ŽÝ Ž¶Ž³ŽÝŽÀ                  */
    long    tblad ;                     /* ŽÃŽ°ŽÌŽÞŽÙ ŽÛŽÝŽØ Ž±ŽÄŽÞŽÚŽ½           */
    long    gtbf;
    long    frbf;
    long    errext ;
    long    errfex ;
    long    bitmapf;
    long    errchain;
    long    adtemt;
    long    erroth;
};
typedef  struct  fipred  FIPRED;
