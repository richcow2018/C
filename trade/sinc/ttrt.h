/*********************************************************************/
/*   TRT �� ���ݎ���-�Ď� �̎�����                                              */
/*********************************************************************/
 
/*********************************************************************/
/*   TRT ���̎� ���֎����̎� �� �������ގ�����                                       */
/*********************************************************************/
 
struct  ttrtsub
{
    short  ttrtuse;                     /* ���֎� ���Վ� ���͎ގ̎� �ʎގݎ��ގ�     */
    short  ttrtemp;                     /* �Ў��֎� ���͎ގ̎� �ʎގݎ��ގ�        */
};
typedef  struct  ttrtsub  TTRTSUB;
 
/*********************************************************************/
/*   TRT ���͎ގ̎� �� �������ގ�����                                            */
/*********************************************************************/
 
struct  ttrtpsz
{
    short ttrtorg;                      /* ���͎ގ̎� �ʎގݎ��ގ�             */
    short ttrtnxt;                      /* ���� �� ���͎ގ̎� �ʎގݎ��ގ�       */
    char  ttrtscl;                      /* ���Ďގ�  ���Վ͎ގ�               */
    char  ttrtrv1[3];                   /* �֎Ԏ� 1                     */
    char  ttrtkcl;                      /* ���� ���̎ގ�                   */
    char  ttrtntc;                      /* NTC �ʎގݎ��ގ�                */
    short ttrtpno;                      /* �̎ߎێ��� �ʎގݎ��ގ�              */
    char  ttrtpnm[8];                   /* �̎ߎێ��� �����͎ގ� �Ҏ�            */
    long  ttrtclno;                     /* �̎ߎێ��� ���Ďގ� ���׎� ���ʎގ�      */
    char  ttrttid[8];                   /* �Ď� ���Ďގ� �����͎ގ� �Ҏ�          */
    char  ttrttme[4];                   /* ���Ďގ� ���ގ��� / ���ݎ��� ���ގ���     */
    long  ttrtcyc;                      /* ���ݎ��� ���ގ���                 */
    long  ttrtabs;                      /* �������� ���ގ���                 */
    char  ttrtcmd[76];                  /* ���ώݎĎ� �ӎ��ގڎ�               */
};
typedef  struct  ttrtpsz  TTRTPSZ;
      
#define  TTRTCLK  0x01                  /* ���ގ��� ���Î�                  */
#define  TTRTCYC  0x02                  /* ���Վ��� ���Î�                  */
