/**********************************************************************/
/*                                                                    */
/*          msabt.h                                                   */
/*                                                                    */
/*         ���Ύގ���  ���ގ����Ύ�                                              */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*      ���Ύގ���  ���ގ����Ύ�  �̎����ώ���  &  �����؎���                              */
/**********************************************************************/
struct msabt {
    unsigned short abcod ;           /* ���Ύގ��� �����Ď�                    */
    long           abdtl ;           /* ���Ύގ��� ���������� ���ގ����Ύ�            */
} ;
typedef struct msabt MSABT ;

#define FABT(id)   flog(id, (char *)&msabt, sizeof(MSABT))

#define MS_ABT     mr_sabt(msabt.abcod, msabt.abdtl)

#define MS_ABTK    chrptr = (char *)&msret;\
                   msbptr = (char *)&(msabt.abdtl);\
                   *(msbptr + 1) = *(chrptr + 1);\
                   *(msbptr + 2) = *(chrptr + 2);\
                   *(msbptr + 3) = *(chrptr + 3);\
                   mr_sabt(msabt.abcod, msabt.abdtl)

/**********************************************************************/
/*      ���Ύގ���  �����Ď�                                                   */
/**********************************************************************/
#define BCMAIN00    0x5800           /* apmain                        */
#define BCIN1000    0x5810           /* msin1000                      */
#define BCFM1000    0x5820           /* msfm1000                      */
#define BCFM1100    0x5821           /* msfm1100                      */
#define BCFM1110    0x5823           /* msfm1110                      */
#define BCFM1111    0x5825           /* msfm1111                      */
#define BCFM1112    0x5826           /* msfm1112                      */
#define BCFM1113    0x5827           /* msfm1113                      */
#define BCFM1114    0x5828           /* msfm1114                      */
#define BCFM1120    0x5824           /* msfm1120                      */
#define BCFM1200    0x5822           /* msfm1200                      */
#define BCED1100    0x5831           /* msed1100                      */
#define BCED1200    0x5832           /* msed1200                      */
#define BCMO1000    0x5840           /* msmo1000                      */
#define BCMO1100    0x5841           /* msmo1100                      */
#define BCMO1200    0x5842           /* msmo1200                      */
#define BCMO1300    0x5843           /* msmo1300                      */
#define BCKK3020    0x58FB           /* mskk3020                      */
#define BCKK3100    0x58FC           /* mskk3100                      */

/**********************************************************************/
/*      ���Ύގ���  ���ގ����Ύ�                                                 */
/**********************************************************************/
#define BDOSCNNG    0x10000000       /* osconn   NG                   */
#define BDOSOPNG    0x11000000       /* osopen   NG                   */
#define BDOSIWNG    0x12000000       /* osiwrite NG                   */
#define BDOSCLNG    0x13000000       /* osclose  NG                   */
#define BDOSDCNG    0x14000000       /* osdconn  NG                   */
#define BDOSITNG    0x15000000       /* osioctl  NG                   */
#define BDOSRVNG    0x16000000       /* osrcvmsr NG                   */
#define BDOSDLNG    0x18000000       /* osdelay  NG                   */
#define BDOSRSNG    0x1B000000       /* osrsrrrd NG                   */
#define BDOSCQNG    0x1C000000       /* oscanrq  NG                   */
#define BDCGETNG    0x30000000       /* md_cget  NG                   */
#define BDCCNVNG    0x31000000       /* md_ccnv  NG                   */
#define BDCEMTNG    0x34000000       /* mi_cemt  NG                   */
#define BDGCELNG    0x35000000       /* mi_gcel  NG                   */
#define BDFCELNG    0x36000000       /* mi_fcel  NG                   */
#define BDIVNTNG    0x37000000       /* ���͎ގݎ� ���ݎ� �Ď��ێ� �̎Ɏ�            */
#define BDMOFBNG    0x38000000       /* mo_frbf  NG                   */
#define BDSCELNG    0x39000000       /* mi_scel  NG                   */
#define BDMCCPNG    0x3B000000       /* mc_copy  NG                   */
#define BDMSRET     0x50000000       /* ���ݎ��� �� �͎ݎ������� �����ގ���           */
#define BDMSTBL     0x51000000       /* �Î��̎ގ� �Ҏ�  NG                  */
#define BDOPTNNG    0x52000000       /* �����؎��� �ʎߎ�����  �����ގ���           */
#define BDTRRCNG    0x55000000       /* trrc rd ���� �Ŏ�                 */
#define BDNTCDNG    0x56000000       /* NTC  ����  ���ގ��ˎ��� �Ŏ�            */
#define BDSYRCOD    0x70000000       /* �����؎����Ď� �����ގ���                 */
#define BDOUKUBN    0x71000000       /* �����؎��� ���̎ގ� �����ގ���             */
#define BDRQIDNG    0x72000000       /* �؎������� �����͎ގ� �����ގ���            */
#define BDMKCOD     0x73000000       /* MK �����Ď� �����ގ���                 */
#define BDMIKFNG    0x74000000       /* �������� �̎؎܎� �����ގ���               */
#define BDMO1300    0x75000000       /* msmo1300  �����ގ���               */
#define BDKK2210    0xE0000000       /* mskk2210  �����ގ���               */
#define BDLGCLER    0xF0000000       /* scp �ێݎ� �ю��ގ���                 */


/**********************************************************************/
