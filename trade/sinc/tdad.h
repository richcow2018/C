/**********************************************************************/
/*                                                                    */
/*        TDAD �Î��̎ގ� �̎����ώ���     tdad.h      (88.01.  )                */
/*                                                                    */
/**********************************************************************/

struct mddadsb {
        short   tdadkbsu;               /* �Վ����� ���͎ގ̎� ����             */
        short   tdadyob0;               /* �֎ˎ�0                       */
};
typedef struct mddadsb MDDADSB;         /* DCP �֎�                     */
typedef struct mddadsb TDADSUB;         /* FIP �֎�                     */

struct  mddadko {
        char    tdadpckb      ;         /* ������ �������ގ� ���Վ͎ގ�           */
        char    tdadyob1[3]   ;         /* �֎ˎ�1                       */
        short   tdadread      ;         /* ���ގՎ��� �Îގݎ̎ގ� �����Ɏ� ���Ďގڎ� ���� */
        short   tdadresz      ;         /* ���ގՎ��� �Îގݎ̎ގ� �������� ����       */
        short   tdadwrad      ;         /* �������� �Îގݎ̎ގ� �����Ɏ� ���Ďގڎ� ����  */
        short   tdadwrsz      ;         /* �������� �Îގݎ̎ގ� �������� ����        */
};
typedef struct  mddadko MDDADKO;        /* DCP �֎�                     */
typedef struct  mddadko TDADPSZ;        /* FIP �֎�                     */
