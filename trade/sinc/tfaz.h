/**********************************************************************/
/*   TFAZ KOBETSUBU                                                   */
/**********************************************************************/
struct    tfazpsz  {                 /*                               */
    unsigned char  tfazfnam[18] ;    /* �Ď����� �̎����� �Ҏ�                  */
    unsigned char  tfaznull[2]  ;    /* �ʎߎ��Ҏ� ���Ď��ʎߎ�                  */
    unsigned char  tfazcrku     ;    /* �ʎ������� �֎ˎ� ���̎ގ�                */
    unsigned char  tfazyob1[3]  ;    /* �֎ˎ� 1                         */
}   ;                                /*                               */
typedef struct tfazpsz  TFAZPSZ;     /*                               */
