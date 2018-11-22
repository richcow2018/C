/**************************************/
/*                                    */
/*      miretv.h                      */
/*                                    */
/**************************************/
/**************************************/
/*      �͎ݎ�������                        */
/**************************************/
#define MINORMAL     0                  /* �������ގ���                     */
#define MIIVPARM    -1                  /* �ʎߎ׎Ҏ��� ���׎�                 */
#define MIMEMANG    -2                  /* ���͎ގݎĎ��ݎ؎��؎� ���ݎ؎̎ގ��׎�       */
#define MIPBUFER    -3                  /* �̎ߎ��َʎގ��̎� ������ ���׎�          */
#define MIIFAERR    -4                  /* ���ݎ��̎����� ���׎�                */
#define MINOARID    -5                  /* ���؎������͎ގ� �Ў����Î�            */
#define MINOTEXT    -6                  /* ���͎ގݎĎ��ݎ؎��؎� �������������׎�       */
#define MINOTDEF    -7                  /* ���͎ގݎĎ��ݎ؎��؎� ���� �Ŏ�          */
#define MINOEVID    -8                  /* ���Î� ���͎ގݎ� �����͎ގ� �Ŏ�        */
#define MINOKEY     -9                  /* ���Î� ���� �Ŏ�                  */
#define MITBLERR   -10                  /* �Î��̎ގ� �����ގ���                */
#define MIMSNDER   -11                  /* �Ҏ��������� �����ގ���               */
#define MISENDOK   -12                  /* �����͎ގ����ގ���                 */
#define MITIMEOUT  -13                  /* ���������ގ��ώ� ���ގ��� �����ʎގ�        */
#define MIEOSERR   -14                  /* ros �����Î� ������ ���׎�           */
#define MINOMEM    -15                  /* �Ҏӎ� �̎ގ���                   */
#define MISEQERR   -16                  /* ���Ǝ��� ���ގ��� ���׎�              */
#define MISRTOUT   -17                  /* ���ގ��Ď� ���ݎĎ� �Ŏ�              */
#define MIBUFBSY   -18                  /* �ʎގ��̎� �� �����Ŏ�               */
#define MIDELERR   -19                  /* osdelay ���׎�                */
#define MIFACERR   -20                  /* FAC ���׎�                    */
#define MIFAPERR   -21                  /* FAP ���׎�                    */
#define MILPTERR   -22                  /* LPT ���׎�                    */
#define MILGTERR   -23                  /* LGT ���׎�                    */
#define MINOFILE   -24                  /* ���Î� ���� �̎����َ��� �Ŏ�           */
#define MIPATHDR   -25                  /* ���Î� ���� �Îގ��ڎ��Ď؎� �Ŏ�         */
#define MIPATH     -26                  /* �̎����� ���Î��� �Վَ��ڎŎ� �ӎ���       */
#define MISFILRS   -27                  /* �Ďގ����ގƎ��֎��Îގ��َ̎����َ� ������(SYS)*/
#define MIPFILRS   -28                  /* �Ďގ����ގƎ��֎��Îގ��َ̎����َ� ������(PRC)*/
#define MIMOUNT    -29                  /* ���������� �ώ��ݎĎ��ڎ� ���Ŏ�          */
#define MIFILDES   -30                  /* �̎����� �����ގ��� ���Ԏώ�           */
#define MIACCD     -31                  /* �̎����� �������ގ����� �Ŏ�            */
#define MINOTEMP   -32                  /* �ʎ����� �Îގ��ڎ��Ď� ����            */
#define MIBUSY     -33                  /* ���̎ߎێ����� �֎� ���Ȏ��� ������        */
#define MIPTSROT   -34                  /* PCT ������ ������                */
#define MICVTERR   -35                  /* �����Ď� �͎ݎ��� �����ގ���   GG       */
#define MIYHNERR   -36                  /* ifa ���׎�       0201         */
#define MIHRDERR   -37                  /* ifa ���׎�       0202         */
#define MIMODERR   -38                  /* ifa ���׎�       0203         */
#define MIDUPFIL   -39                  /* ifa ���׎�       0204         */
#define MIMSSAGE   -40                  /* ifa ���׎�       0205         */
#define MIHEISOK   -41                  /* ifa ���׎�       0206         */
#define MINTLPNO   -42                  /* ifa ���׎�       0206         */
#define MICNOCV    -43                  /* ifa ���׎�       0206         */
#define MISHIKEN   -44                  /* ���؎����������ݎ�����              PP*/
/**************************************/
/*    �Ύߎ��� �����Ď�                       */
/**************************************/
#define MIPTNML      0                  /* ���؎����� �������ގ���  0000         */
#define MIPTLOK     16                  /* �������ݎ������ގ���    0010         */
#define MIPTERR    256                  /* �Îގݎ���  ����-    0100         */
#define MIPTEVT    272                  /* event �����؎�����  0110         */
#define MIPTLER    288                  /* �������ݎ��Ԏώ�      0120         */
#define MIPTTOV    304                  /* ������ ������       0130       EE*/
#define MIPTMOD    320                  /* �ӎÎގ� ���׎�      0140         */
#define MIPTHRD    325                  /* �ʎ��Ď� ���������ގ�   0145         */
#define MIPTDMA    326                  /* DMA �͎�����      0146         */
#define MIPTIOC    327                  /* IOC �͎�����      0147         */
#define MIPTCPU    328                  /* pu ���������ގ�     0148         */
#define MIPTBSY    329                  /* ���ݎĎێ��� �͎�����������0149         */
#define MIPTIFA    512                  /* ifa ���׎�       0200         */
#define MIPTCHK    768                  /* �� ��������        0300       EE*/
#define MIPTTEL   1024                  /* �Îގݎ܎ӎ� �����ގ���  0400       EE*/
#define MIPTNOE   1280                  /* ������ ������       0500       EE*/
#define MIPTSHB   1536                  /* ���׎��ӎ� ������     0600       EE*/
#define MIPTLIN   1792                  /* ������ �̎��Ɏ�      0700       EE*/
