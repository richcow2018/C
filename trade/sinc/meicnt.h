/**********************************/
/*                  V/R = 0/0     */
/*                  88.03.28      */
/*          meicnt.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(�Ҏ���:���ю����̎�)*/
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������     PD01*/
/*                                      rd���������ѹ��ΰ�            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o �����Ď�             */
#define   WLPIO     0x00                 /* �َ��̎� i/o �����Ď�           */
#define   W4WNT     0x40                 /* 4W-NTM i/o �����Ď�        **/
#define   W4WSY     0xc1                 /* 4W,4W-NTM �����؎����͎ގ�      */
#define   WLPSY     0xc2                 /* �َ��̎� �����؎����͎ގ�           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* �������ގ���                  */
#define   M0OSRETE  -1                   /* OS �͎ݎ������� �����ގ���         */
/*******************************/
/*          cntwork.h          */
/*******************************/
struct cntwork {                         /* �ˎ����� �Ǝ����؎��� ���ގ����Ύ�      */
       short  pathno;                    /* �ێݎ؎ʎߎ� �ʎގݎ��ގ�           */
       short  yobi1;                     /* �֎ˎ� 1                   */
       long   retadd;                    /* �؎����� ���Ďގڎ�              */
       char  *argptr;                    /* �������ގ��Ҏݎ� ���� �Ύߎ��ݎ�       */
       short  argsize;                   /* �������ގ��Ҏݎ� ���� ��������        */
       short  tmvid;                     /* �����ώ� �����͎ގ�             */
       long   sysret;                    /* �����Î� �͎ݎ�������             */
       long   usrrd;                     /* �Վ����ގ؎������ļ��̻�		PD01*/
       long   timet;                     /*�����ώ�                     */
};
typedef struct cntwork CNTWORK;
union cninpret {                       /* ROS �؎����� ���ގ����Ύ�             */
    long  retdat;                      /* ���ގݎ���                       */
    char  retros[4];                   /* ���ގݎ���                       */
    struct {                  /* 4W i/o �������ގ���                        */
        unsigned erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned kanr : 31;            /* ���ݎ؎��� �����Ď�                  */
    } ni4w;
    struct {                  /* 4W i/o �����ގ���                         */
        unsigned erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned syor : 7;             /* ������ �����͎ގ�                   */
        unsigned flag : 1;             /* �̎׎���                        */
        unsigned kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned erco : 4;             /* ���׎� ���ގ��̎ގݎَ�                */
        unsigned ersy : 11;            /* ���׎� ����������                   */
        unsigned rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* �َ��̎� i/o �������ގ���                      */
        unsigned erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned fil1 : 15;            /* �� ���֎�                       */
        unsigned wrsz : 16;            /* �׎��� ��������                    */
    } nilp;
    struct {                  /* �َ��̎� i/o �����ގ���                       */
        unsigned erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned syor : 7;             /* ������ �����͎ގ�                   */
        unsigned flag : 1;             /* �̎׎���                        */
        unsigned kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned ersy : 20;            /* ���׎� ����������                   */
    } eilp;
};
typedef union cninpret CNINPRET;
union cnoutret {                       /* �؎����� ���ގ����Ύ� ����              */
    char  retdat[8];                   /* ���ގݎ���                       */
    struct {                  /* 4W i/o �����ގ���                         */
        unsigned fil1 : 32;            /* �� ���֎�                       */
        unsigned val1 : 5;             /* ���Î���                        */
        unsigned kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned val2 : 4;             /* ���Î���                        */
        unsigned erco : 4;             /* ���׎� ���ގ��̎ގݎَ�                */
        unsigned val3 : 5;             /* ���Î���                        */
        unsigned ersy : 11;            /* ���׎� ����������                   */
    } eo4w;
    struct {                  /* �َ��̎� i/o �������ގ���                      */
        unsigned fil1 : 16;            /* �� ���֎�                       */
        unsigned wrsz : 16;            /* �׎��� ��������                    */
        unsigned fil2 : 32;            /* �� ���֎�                       */
    } nolp;
    struct {                  /* �َ��̎� i/o �����ގ���                       */
        unsigned fil1 : 32;            /* �� ���֎�                       */
        unsigned val1 : 1;             /* ���Î���                        */
        unsigned syor : 7;             /* ������ �����͎ގ�                   */
        unsigned val2 : 1;             /* ���Î���                        */
        unsigned kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned ersy : 20;            /* ���׎� ����������                   */
    } eolp;
};
typedef union cnoutret CNOUTRET;
