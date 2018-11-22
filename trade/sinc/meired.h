/**********************************/
/*                   V/R = 0/0    */
/*                   88.03.25    */
/*          meired.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(�Ҏ���:���ю����̎�)*/
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������     PD01*/
/*                                      rd���������ѹ��ΰ�            */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o �����Ď�             */
#define   WLPIO     0x00                 /* �َ��̎� i/o �����Ď�           */
#define   W4WNT     0x40                 /* 4W-NTM i/o �����Ď�         */
#define   W4WSY     0xc1                 /* 4W-NTM ���׎� �����Ď�         */
#define   WLPSY     0xc2                 /* �َ��̎� ���׎� �����Ď�           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* �������ގ���                  */
#define   M0OSRETE  -1                   /* OS �͎ݎ������� �����ގ���         */
/*******************************/
/*          redwork.h          */
/*******************************/
struct redwork {                         /* �ˎ����� �Ǝ����؎��� ���ގ����Ύ�      */
       short  pathno;                    /* �ێݎ؎ʎߎ� �ʎގݎ��ގ�           */
       char   syoricod;                  /* ������ �����Ď�                */
       char   yobi1;                     /* �֎ˎ�  1                  */
       long   retadd;                    /* �؎����� ���Ďގڎ�              */
       short  tmvid;                     /* �����ώ� �����͎ގ�             */
       short  rdasize;                   /* ���ގ����ݎÎގ��� �����Ɏ����� ��������   */
       long   rdaptr;                    /* ���ގ����ݎÎގ��� �����Ɏ����� ���Ďގڎ�  */
       long   dosapara;                  /* �Ďގ��� �ʎߎ׎Ҏ���             */
       long   sysret;                    /* �����Î� �͎ݎ�������             */
       long   usrrd;                     /* �Վ����ގ؎������ļ��̻�		PD01*/
 };
typedef struct redwork REDWORK;

union reinpret {                       /* ROS �؎����� ���ގ����Ύ�             */
    long  retdat;                      /* ���ގݎ���                       */
    char  retros[4];                   /* ���ގݎ���                       */
    short redsiz[2];                   /* �؎��Ď� ��������                   */
    struct {                  /* 4W i/o �������ގ���                        */
        unsigned int erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned int fil1 : 10;            /* �� ���֎�                       */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* �؎��Ď� ��������                   */
    } ni4w;
    struct {                  /* 4W i/o �����ގ���                         */
        unsigned int erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned int syor : 7;             /* ������ �����͎ގ�                   */
        unsigned int flag : 1;             /* �̎׎���                        */
        unsigned int kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned int erco : 4;             /* ���׎� ���ގ��̎ގݎَ�                */
        unsigned int ersy : 11;            /* ���׎� ����������                   */
        unsigned int rvda : 5;             /* RV                          */
    } ei4w;
    struct {                  /* �َ��̎� i/o �������ގ���                      */
        unsigned int erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned int fil1 : 7;             /* �� ���֎�                       */
        unsigned int resp : 8;             /* �ڎ��Ύߎݎ�                      */
        unsigned int resz : 16;            /* �؎��Ď� ��������                   */
    } nilp;
    struct {                  /* �َ��̎� i/o �����ގ���                       */
        unsigned int erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned int syor : 7;             /* ������ �����͎ގ�                   */
        unsigned int flag : 1;             /* �̎׎���                        */
        unsigned int kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned int ersy : 20;            /* ���׎� ����������                   */
    } eilp;
}; 
typedef union reinpret REINPRET;

union reoutret {                       /* �؎����� ���ގ����Ύ� ����              */
    char  retdat[8];                   /* ���ގݎ���                       */
    struct {                  /* 4W i/o �������ގ���                        */
        unsigned int fil1 : 8;             /* �� ���֎�                       */
        unsigned int val1 : 3;             /* ���Î���                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int resz : 16;            /* �؎��Ď� ��������                   */
        unsigned int fil2 : 32;            /* �� ���֎�                       */
    } no4w;
    struct {                  /* 4W i/o �����ގ���                         */
        unsigned int fil1 : 8;             /* �� ���֎�                       */
        unsigned int val1 : 3;             /* ���Î���                        */
        unsigned int rvda : 5;             /* RV                          */
        unsigned int fil2 : 16;            /* �� ���֎�                       */
        unsigned int val2 : 5;             /* ���Î���                        */
        unsigned int kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned int val3 : 4;             /* ���Î���                        */
        unsigned int erco : 4;             /* ���׎� ���ގ��̎ގݎَ�                */
        unsigned int val4 : 5;             /* ���Î���                        */
        unsigned int ersy : 11;            /* ���׎� ����������                   */
    } eo4w;
    struct {                  /* �َ��̎� i/o �������ގ���                      */
        unsigned int fil1 : 8;             /* �� ���֎�                       */
        unsigned int resp : 8;             /* �ڎ��Ύߎݎ�                      */
        unsigned int resz : 16;            /* �؎��Ď� ��������                   */
        unsigned int fil2 : 32;            /* �� ���֎�                       */
    } nolp;
    struct {                  /* �َ��̎� i/o �����ގ���                       */
        unsigned int fil1 : 32;            /* �� ���֎�                       */
        unsigned int val1 : 1;             /* ���Î���                        */
        unsigned int syor : 7;             /* ������ �����͎ގ�                   */
        unsigned int val2 : 1;             /* ���Î���                        */
        unsigned int kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned int ersy : 20;            /* ���׎� ����������                   */
    } eolp;
};
typedef union reoutret REOUTRET;

