/**************************************/
/*                                    */
/*        mdc_wspn.h                  */
/*                                    */
/**************************************/
struct mdwspnf {                        /* TPCT ���ގ����Ύ� �����Ɏ����� �̎����ώ���  */
         char      mdwspnm[8] ;         /* �̎ߎێ��� �����͎ގҎ�              */
         long      mdwsnmb ;            /* �Ҏ��َΎގ����� �����͎ގ�            */
         long      mdwspkn ;            /* �̎ߎێ��ގ׎� ���͎ގ� �ʎގݎ��ގ�        */
};
typedef struct mdwspnf  MDWSPNF;


/**************************************/
/*                                    */
/*    �͎ݎ������� �؎���                      */
/*                                    */
/**************************************/
#define   WSPNOMAL    0l                /* �������ގ��� �������؎���              */
#define   WSPIVPRM   0xff130001         /* �ʎߎ׎Ҏ��� ���׎�                 */
#define   WSPTELGT   0xff130002         /* TLGT ���׎�                   */
#define   WSPTEPAT   0xff130003         /* TPAT ���׎�                   */
