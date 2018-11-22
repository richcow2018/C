/****************************NTC-SMP FIP******************************/
/*                                                                   */
/*    1.Ì§²ÙÒ²       FIP¶ÝØ ¼¹ÞÝ ÍÝ¼­³ É º³¿Þ³À²(mfed.h)             */
/*                                                                   */
/*    2.¸ÌÞÝ                                                         */
/*                                                                   */
/*    3.ØÚ·          ¾¯¹²¼¬    ³ÁÀÞ                                  */ 
/*                   »¸¾²¼¬    ³ÁÀÞ        88'10/18                  */
/*********************************************************************/
struct fipred{
    long    emteno;                     /* EMT ´ÝÄØ ÅÝÊÞ             */
    long    exteno;                     /* ¶¸Á®³ EXT ´ÝÄØ ÅÝÊÞ       */
    char    rsname[5];                  /* ¼¹ÞÝ Ò²¼®³                */
    char   *rsfname;                    /* ¼¹ÞÝ Ò²¼®³ (file)         */
    char    *rskind;                    /* ¼¹ÞÝ ¼­ÍÞÂ                */
    long    smphid;                     /* ¾ÏÌ« ¼·ÍÞÂ¼               */
    short   senq;                       /* ¾ÝÕ³ ¼Þ­Ý²                */
    short   kenq;                       /* ºÍÞÂÌÞ ¾ÝÕ³ ¼Þ­Ý²         */
    long    rsno;                       /* ¼¹ÞÝ ÊÞÝºÞ³               */
    char    puno;                       /* PU ÅÝÊÞ                   */
    unsigned char    rsstat;                     /* ¼¹ÞÝ ¿Þ¸¾²                */
    long    lncnt ;                     /* ×²Ý ¶³ÝÀ                  */
    long    tblad ;                     /* Ã°ÌÞÙ ÛÝØ ±ÄÞÚ½           */
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
