/*********************************************************************/
/*  �Î��̎ގ� ���֎����̎� �� �������ގ�����                                          */
/*********************************************************************/
 
struct  tcompat {
    char  tcomtbid[4];                  /* ��-�̎ގ� �����͎ގ�              */
    short tcommxno;                     /* �������ގ� ���ݎĎ� ����             */
    short tcomefen;                     /* �Վ����� ���ݎĎ� ����              */
    short tcomprsl;                     /* 1 ���͎ގ̎� �� ��������           */
    unsigned	char  tcomsbps;         /* ���̎� ���֎����̎� �� �������� TC1965 */
    char  tcomstat;                     /* ����-����                     */
};      
typedef  struct  tcompat  TCOMPAT;