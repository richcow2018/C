/*****************************/
/*                           */
/*     tgrx.h                */
/*                           */
/*  ���ގَ��̎� �Î��̎ގ�             */
/*          �͎����� �̎�����        */
/*                           */
/*****************************/
struct  tgrxsub {
          short  tgrxserh;              /*   �� �� �� �� �� �� �� ��          */
          short  tgrxyobi;              /*     ��        �ˎ�            */
};
typedef  struct tgrxsub  TGRXSUB;
struct  tgrxpsz {
          char  tgrxpnam[8];            /*    �̎� �� �� �� �� �� �͎� �� �� ��   */
          char  tgrxkftp;               /*    �� �� �� �� �� �� �̎�          */
          char  tgrxblok;               /*    �� �� �� �� �̎� �� �� ��        */
          short tgrxnode;               /*  �ʎ����� �ӎ� �Ɏ��Ď� �ʎގݎ��ގ�       */
          char  tgrxkfky[12];           /*     �� �� �� ��   ����           */
          char  tgrxsnpn[8];            /*  �ʎ����� �ӎ� �̎ߎێ��� �����͎ގ� �Ҏ�    */
          long  tgrxsmid;               /*  �������� ���� �Ҏ��َΎގ����� ID       */
};
typedef struct tgrxpsz  TGRXPSZ;
