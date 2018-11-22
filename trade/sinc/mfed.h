/****************************NTC-SMP FIP******************************/
/*                                                                   */
/*    1.�̎����َҎ�       FIP���ݎ� �����ގ� �͎ݎ����� �� �������ގ�����(mfed.h)             */
/*                                                                   */
/*    2.���̎ގ�                                                         */
/*                                                                   */
/*    3.�؎ڎ�          ������������    ��������                                  */ 
/*                   ������������    ��������        88'10/18                  */
/*********************************************************************/
struct fipred{
    long    emteno;                     /* EMT ���ݎĎ� �Ŏݎʎ�             */
    long    exteno;                     /* ���������� EXT ���ݎĎ� �Ŏݎʎ�       */
    char    rsname[5];                  /* �����ގ� �Ҏ�������                */
    char   *rsfname;                    /* �����ގ� �Ҏ������� (file)         */
    char    *rskind;                    /* �����ގ� �����͎ގ�                */
    long    smphid;                     /* ���ώ̎� �����͎ގ�               */
    short   senq;                       /* ���ݎՎ� ���ގ��ݎ�                */
    short   kenq;                       /* ���͎ގ̎� ���ݎՎ� ���ގ��ݎ�         */
    long    rsno;                       /* �����ގ� �ʎގݎ��ގ�               */
    char    puno;                       /* PU �Ŏݎʎ�                   */
    unsigned char    rsstat;                     /* �����ގ� ���ގ�����                */
    long    lncnt ;                     /* �׎��� �����ݎ�                  */
    long    tblad ;                     /* �Î��̎ގ� �ێݎ� ���Ďގڎ�           */
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
