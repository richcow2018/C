/**********************************************************************/
/*                                                                    */
/*             me_cedt        �͎����ގ̎�����       (mecedt.h)               */
/*                                                                    */
/**********************************************************************/
/**************************************/
/*           edt���ݎ��̎����������؎� �̎����ώ���    */
/**************************************/
struct edifarea {
    char       edifscod;                /* �����؎����Ď�                    */
    char       ediftkbn;                /* �͎ݎ����� ���̎ގ�                 */
    short      edifptno;                /* �ێݎ؎ʎߎ� �ʎގݎ��ގ�              */
    long       edifedad;                /* MIA���Ďގڎ�                   */
    short      edifedsz;                /* MIA��������                    */
    short      edifyob1;                /* �֎ˎ�1                       */
    long       edifatkb;                /* ���Î��� ���ݎ؎��� ���͎ގ̎� ���Ďގڎ�    */
    long       edifmskn;                /* �Ҏ��������� ���ݎ؎��� ���Ďގڎ�         */
    long       edifhkak;                /* �ˎ��� ���ގ����Ύ����� ���Ďގڎ�         */
    long       ediftuci;                /* ���Î��� �������ގ����Ύ� ���Ďގڎ�       */
    long       edifhttb;                /* �Ύ��� �Î��̎ގَ��ގ����Ύ� ���Ďގڎ�      */
    long      *edifdtad;                /* �Îގ������Ďގڎ� �����Ɏ����� ��  ���Ďގڎ�  */
    short     *edifdtsz;                /* �Îގ�����������  �����Ɏ����� ��  ���Ďގڎ�  */
};
typedef struct edifarea EDIFAREA;
/**************************************/
/*        �ˎ��� ���ގ����Ύ����� �̎����ώ���         */
/**************************************/
struct hkakarea {
    char       hkakedst;                /* �͎ݎ����� ���Î�����                */
    char       hkakakbn;                /* ���Î��� ���̎ގ�                  */
    char       hkakfndt;                /* ���������� �Îގ������̎ގ�             */
    char       hkakkkst;                /* �������� ���Î�����                 */
    short      hkakptno;                /* �ێݎ؎ʎߎ� �ʎގݎ��ގ�              */
    short      hkakanod;                /* ���Î��� �Ɏ��Ď� �ʎގݎ��ގ�           */
    char       hkakfwcd[2];             /* �������� �̎؎܎� �����Ď�             */
    char       hkakyobi[2];             /* �֎ˎ�                        */
    char       hkakpsid[8];             /* �̎ߎێ��� �����͎ގҎ�              */
    long       hkakmsad;                /* �Ҏ��������� ���ݎ؎��� ���Ďގڎ�         */
};
typedef struct hkakarea HKAKAREA;
/**************************************/
/*        �ˎ��� ���ݎ��ގ� �֎�                */
/**************************************/
struct longdata {
    long longdt1;
    long longdt2;
};
typedef struct longdata LONGDATA;
/**************************************/
/*        �͎ݎ�������                      */
/**************************************/
#define  MEEQUAL    01
#define  MENOTEQ  -100
#define  SPACE     ' '