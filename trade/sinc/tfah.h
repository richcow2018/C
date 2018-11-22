/**********************************************************************/
/*                                                                    */
/*        TFAH �Î��̎ގ� �̎����ώ���       tfah.h           (61.12.  )         */
/*                                       �͎ݎ���      (62.12.  ) CC      */
/*                                       �ѹ�       94.10.26  JI      */
/*                                       �ѹ���     ����  ��          */
/*                                       �ѹ�       94.12.20  JJ      */
/*                                       �ѹ���     ����  ��          */
/*                                       �ѹ�       95.02.14  S0      */
/*                                       �ѹ���     ����(Sazae)��Ƿ   */
/*                                       �ѹ�       96.06.10  SP      */
/*                                       �ѹ���     ���湨Ƿ		  */
/*                                      �ѹ�       2003.2.28 LA01     */
/*                                      �ѹ�����   linux�ܿ���ȼ������*/
/*                                      �ѹ���     ���湨Ƿ           */
/*                                                                    */
/**********************************************************************/

struct mdfahsb {
        short    tfahinen;               /* ͽ��                   JI */
        char     tfahtype;               /* ������ �������ގ� ���Վ͎ގ�        * */
        char     tfahyob0;               /* �֎ˎ�0                    * */
        short    tfahpsmx;               /* �ێݎ� �ʎߎ� �������ގ� ����       CC */
        char     tfahyob1[6];            /* �֎ˎ�1                CC JJ */
};
typedef struct mdfahsb MDFAHSB;          /* DCP �֎�                    */
typedef struct mdfahsb TFAHSUB;          /* FIP �֎�                    */

struct  mdfahko {
        char   tfahlnsb      ;           /* �������� �����͎ގ�                */
        char   tfahpksb      ;           /* �ʎߎ��������� �����͎ގ�             */
		short  tfahfnpu      ;           /* FNA-PU�ֹ�            LA01*/
		char   tfahyob2[4]   ;           /* ͽ��                  LA01*/
        char   tfahpsnm[22]  ;           /* �ʎߎ� �Ҏ�                    */
        short  tfahlnno      ;           /* �������� �ʎގݎ��ގ�               */
        long   tfahmbid      ;           /* �Ҏ��َΎގ����� ID               */
        short  tfahifrm      ;           /* I �̎ڎ��� ������                */
        char   tfahyuko      ;           /* �Վ����� �ю��� �ˎ�������         CC */
        unsigned char   tfahlccl;        /* LC����                 SP */
        short  tfahsszu      ;           /* �����ގҎݎĎ�������(�ɎΎގ�)          */
        short  tfahsszd      ;           /* �����ގҎݎĎ�������(�����ގ�)          */
        char   tfahshut      ;           /* SHUT-DOWN �ˎ֎�����         * */
        char   tfahdlty      ;           /* �Îގ��� �؎ݎ� �ˎ֎�����          * */
        char   tfahbloc      ;           /* �̎ގێ� ���� �ˎ֎�����          * */
        char   tfahbkup      ;           /* �ʎގ� ���̎� �ˎ֎�����         * */
        char   tfahpckb      ;           /* ������ �������ގ� ���Վ͎ގ�        * */
        char   tfahlsts      ;           /* �������� ���Î�����              * */
        char   tfahlhdk      ;           /* �������� �ˎĎގ��� ���� ���Î�����    * */
        char   tfahlkdk      ;           /* �������� �����̎� �Ďގ��� ���Î�����    * */
        short  tfahdadn      ;           /* TDAD ���ݎĎ� �ʎގݎ��ގ�       CC */
        short  tfahtben      ;           /* ���������� �Î��̎ގ� ���ݎĎ� �ʎގݎ��ގ�CC */
        short  tfahfacn      ;           /* �ԣƣ��äΥ���ȥ��ֹ� JI */
        char   tfahchst      ;           /* ����������������       JI */
        char   tfahyob3      ;           /* ͽ��                CC JI */
        short  tfahlpte      ;           /* TLPH �Ύߎ��ݎ� �Վ����� ���ݎĎ؎���    */
        short  tfahtplt      ;           /* TPLT ���ݎĎ� �ʎގݎ��ގ�       CC */
        short  tfahllno      ;           /* ���������ֹ�           S0 */
        short  tfahlctn   	 ;           /* LC���Ў��ڎ������ݎĎ��ֹ�		SP*/
};
typedef struct  mdfahko MDFAHKO;         /* DCP �֎�                    */
typedef struct  mdfahko TFAHPSZ;         /* FIP �֎�                    */

struct mdfahps {
        short    tfahlphn;               /* TLPH ���ݎĎ� �ʎގݎ��ގ�       CC */
};
typedef struct mdfahps MDFAHPS;          /* DCP �֎�                    */
typedef struct mdfahps TFAHPS;           /* FIP �֎�                    */
