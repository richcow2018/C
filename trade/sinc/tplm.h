/**********************************************************************/
/*                                                                    */
/*        TPLM �Î��̎ގ� �̎����ώ���       tplm.h           (62.02.  )         */
/*                                                                    */
/**********************************************************************/


struct  tplmpsz {
        short  tplmlpte      ;           /* TFAH �Վ����� ���ݎĎ� ����         */
        short  tplmsyob      ;           /* �֎ˎ� 1                     */
        short  tplmphn[64]   ;           /* TFAH ���ݎĎ� �ʎގݎ��ގ�          */
};
typedef struct  tplmpsz TPLMPSZ;         /* BCP �֎�                    */
typedef struct  tplmpsz MDPLMKO;         /* DCP �֎�                    */
