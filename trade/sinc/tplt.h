/**********************************************************************/
/*                                                                    */
/*       TPLT ��-�̎ގ� �̎�-�ώ���        tplt.h      (63.02.01)              */
/*                                                                    */
/**********************************************************************/

struct mdpltsb {
       short   tpltinen;                 /* ���Ǝ����� �͎ݎ������͎ގ̎� ���ݎĎ����ݎĎ� */
       short   tpltyob0;                 /* �֎ˎ�                       */
};
typedef struct mdpltsb TPLTSUB;

struct mdpltko {
       char    tpltyuko;                 /* �Վ�����/�ю��� �ˎ�������            */
       char    tpltbkup;                 /* �ʎގ��������̎� �ˎ�������            */
       char    tpltlnsb;                 /* �������� �����͎ގ�                */
       char    tpltpksb;                 /* �ʎߎ���-���� �����͎ގ�             */
       char    tpltpckb;                 /* �����ݎ������ގ� �����͎ގ�           */
       char    tpltyob1;                 /* �֎ˎ�                       */
       short   tpltlnno;                 /* �������� �ʎގݎ��ގ�               */
       char    tpltpsnm[22];             /* �ʎߎ��Ҏ�                     */
       short   tpltyob2;                 /* �֎ˎ�                       */
       long    tpltmbid;                 /* ��-�َΎގ����� �����͎ގ�           */
       char    tpltgadd;                 /* ���ގ�-�ʎގَ��Ďގڎ� ���ގ����ݎ� �ˎ������� */
       char    tpltyob3;                 /* �֎ˎ�                       */
       short   tpltdlnk;                 /* �������֎� �Î�-���؎ݎ�����           */
       short   tpltfahh;                 /* TFAH�� ���ݎĎ����ݎĎ�            */
       short   tpltfaht;                 /* TFAH �� �������������ݎĎ�          */
       char    tpltresv[20];             /* �֎ˎ�                       */
};
typedef struct mdpltko TPLTPSZ;




