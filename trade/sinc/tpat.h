/**********************************************************************/
/*                                                                    */
/*        TPAT �Î��̎ގ� �̎����ώ���     tpat.h      (61.12.  )                */
/*                                    �͎ݎ���  (62.12.  )   CC           */
/*                                    �ѹ�   94.12.20    JJ           */
/*                                    �ѹ��� ����  ��                 */
/*                                                                    */
/**********************************************************************/

struct mdpatsub {
        short  tpatwsmx;               /* �������ގ� �܎������Î������� ���ݎ؎���       */
        char   tpattint;               /* md_tint �֎�                  */
        char   tpatyob1;               /* �֎ˎ�1                        */
        char   tpatyob2[8];            /* �֎ˎ�2                        */
        short  tpatioen;               /* ͽ��                     JJ */
        short  tpatiosu;               /* ͽ��                     JJ */
        short  tpatcken;               /* ͽ��                     JJ */
        short  tpatcksu;               /* ͽ��                     JJ */
        char   tpatyob3[4];            /* �֎ˎ�3                     JJ */
};
typedef struct mdpatsub MDPATSUB;      /* DCP �֎�                      */
typedef struct mdpatsub TPATSUB;       /* FIP �֎�                      */

struct  mdpatko {
        char   tpatgrcd[12]  ;         /* ���ގَ��̎� �����Ď�                 */
        char   tpatndth      ;         /* NTC ���ގ��ˎ֎� �ˎ֎�����            */
        char   tpatsdth      ;         /* ���̎� ���ގَ��̎� ���ގ��ˎ֎� �ˎ֎�����     */
        short  tpatiokd      ;         /* IO ���Վ͎ގ�                    */
        short  tpatwsen      ;         /* �Վ����� �܎������Î������� ���ݎ؎���        */
        short  tpatpctn      ;         /* TPCT ���ݎĎ� NO.               */
        char   tpatyob4[4];            /* �֎ˎ�4                     JJ */
};
typedef struct mdpatko MDPATKO;        /* DCP �֎�                      */
typedef struct mdpatko TPATPSZ;        /* FIP �֎�                      */

struct  mdpatws{
        char    tpatwscl;              /* �܎������Î������� �����͎ގ�             */
        char    tpatwskb;              /* �܎������Î����֎� NO. �����Î� ���̎ގ�  CC */
        short   tpatwsno;              /* �܎������Î������� NO.               */
        char   tpatyob5[4];            /* �֎ˎ�5                     JJ */
};
typedef struct	mdpatws	MDPATWS;       /* DCP �֎�                      */
typedef struct	mdpatws	TPATWS;        /* FIP �֎�                      */
