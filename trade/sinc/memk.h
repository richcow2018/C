/**************************************/
/*                                    */
/*               mdmk.h               */
/*                                    */
/*        �֎����Վ��Ҏ�-���� ���ݎ؎��� �̎�-�ώ�    */
/*                                    */
/**************************************/
struct mdmkkyo {
    short   mdmkmxen;                   /* �������ގ� ���ݎĎ؎���           */
    short   mdmkeden;                   /* �͎ݎ��Վ� ���ݎĎ؎���           */
    long    mdmkmiad;                   /* MIA�����ˎ��� ���Ďގڎ�         */
};
typedef struct mdmkkyo MDMKKYO;
struct mdmkkob {
    long    mdmkmsad;                   /* �Ҏ�-���� ���Ďގڎ�           */
    short   mdmkmssz;                   /* �Ҏ�-���� ��������            */
    char    mdmkyob1;                   /* �֎ˎ� 1                  */
};
typedef struct mdmkkob MDMKKOB;
