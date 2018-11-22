/**********************************/
/*                     V/R = 0/0  */
/*                     88.03.30   */
/*          meiwrt.h              */
/*                                */
/**********************************/
/**********************************************************************/
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(�Ҏ���:���ю����̎�)*/
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������     PD01*/
/*                                      rd���������ѹ��ΰ�            */
/*     								   ��������ǯ���������     M02 */
/*                                      �ˎގ��Ď̎����َĎޤ�����(v684cc�б�)  */
/**********************************************************************/
#define   W4WIO     0x44                 /* 4W i/o �����Ď�             */
#define   WLPIO     0x00                 /* �َ��̎� i/o �����Ď�           */
#define   W4WNT     0x40                 /* 4W-NTM i/o �����Ď�         */
#define   W4WSY     0xc1                 /* 4W,4W-NTM �����؎����͎ގ�      */
#define   WLPSY     0xc2                 /* �َ��̎� �����؎����͎ގ�           */
#define   NULL      0                    /* NULL                    */
#define   M0NORMAL  0                    /* �������ގ���                  */
#define   M0OSRETE  -1                   /* OS �͎ݎ������� �����ގ���         */
#define   M0IFAERR  -2                  /* �����ގ� ���ݎՎ� ���� ���ݎ��̎����� ���׎� */
/*******************************/
/*          wrtwork.h          */
/*******************************/
struct wrtwork {                         /* �ˎ����� �Ǝ����؎��� ���ގ����Ύ�      */
       short  pathno;                    /* �ێݎ؎ʎߎ� �ʎގݎ��ގ�           */
       char   syoricod;                  /* ������ �����Ď�                */
       char   yobi1;                     /* �֎ˎ�                     */
       short  tmvid;                     /* �����ώ� �����͎ގ�             */
       long   retadd;                    /* �؎����� ���Ďގڎ�              */
       long   outadd;                    /* �����؎��� ���� ���Ďގڎ�         */
       short  outsize;                   /* �����؎��� ���� ��������          */
       long   dosapara;                  /* �Ďގ��� �ʎߎ׎Ҏ���             */
       long   sysret;                    /* �����Î� �͎ݎ�������             */
       long   usrrd;                     /* �Վ����ގ؎������ļ��̻�		PD01*/
};
typedef struct wrtwork WRTWORK;
union wrinpret {                       /* ROS �؎����� ���ގ����Ύ�             */
    long  retdat;                      /* ���ގݎ���                       */
    char  retros[4];                   /* ���ގݎ���                       */
    struct {                  /* 4W i/o �������ގ���                        */
        unsigned erfl : 1;             /* ���׎� �̎׎���                    */
        unsigned fil1 : 10;            /* �� ���֎�                       */
        unsigned rvda : 5;             /* RV                          */
        unsigned syda : 11;            /* ���������� ���ގ����Ύ�                */
        unsigned fil2 : 5;             /* �� ���֎�                       */
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
        unsigned fil1 : 7;             /* �� ���֎�                       */
        unsigned resp : 8;             /* �ڎ��Ύߎݎ�                      */
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
typedef union wrinpret WRINPRET;
union wroutret {                       /* �؎����� ���ގ����Ύ� ����              */
    char  retdat[8];                   /* ���ގݎ���                       */
    struct {                  /* 4W i/o �������ގ���                        */
        unsigned fil1 : 8;             /* �� ���֎�                       */
        unsigned val1 : 3;             /* ���Î���                        */
        unsigned rvda : 5;             /* RV                          */
        unsigned fil2 : 16;            /* �� ���֎�                   M02 */
        unsigned fil3 : 16;            /* �� ���֎�                   M02 */
        unsigned val2 : 5;             /* ���Î���                        */
        unsigned syda : 11;            /* ���������� ���ގ����Ύ�                */
    } no4w;
    struct {                  /* 4W i/o �����ގ���                         */
        unsigned fil1 : 8;             /* �� ���֎�                       */
        unsigned val1 : 3;             /* ���Î���                        */
        unsigned rvda : 5;             /* RV                          */
        unsigned fil2 : 16;            /* �� ���֎�                       */
        unsigned val2 : 5;             /* ���Î���                        */
        unsigned kens : 3;             /* ���ݎ����� �ӎ�                    */
        unsigned val3 : 4;             /* ���Î���                        */
        unsigned erco : 4;             /* ���׎� ���ގ��̎ގݎَ�                */
        unsigned val4 : 5;             /* ���Î���                        */
        unsigned ersy : 11;            /* ���׎� ����������                   */
    } eo4w;
    struct {                  /* �َ��̎� i/o �������ގ���                      */
        unsigned fil1 : 8;             /* �� ���֎�                       */
        unsigned resp : 8;             /* �ڎ��Ύߎݎ�                      */
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
typedef union wroutret WROUTRET;
