/***************************************/
/*                                     */
/*        mstnstko.h                   */
/*                                     */
/*       TNST ������  ���؎�                 */
/*                                     */
/***************************************/

struct mstnstko {
    char  tnstshyo ;                    /* ���֎������� �ˎ�������            */
    char  tnststts ;                    /* ���Î�����                   */
    short tnstyob1 ;                    /* �� �ˎ�                    */
    long  tnstbadr ;                    /* ������ MIA �ώ�  ��  ���Ďގڎ�    */
    long  tnstaadr ;                    /* ������ MIA ���� ��  ���Ďގڎ�    */
                                        /* ������ MIA                 */
    char  tnstmia[sizeof(MCMIKYO) + sizeof(MSMIAUIP)] ;
    char  tnstmsg[MSMGBFSZ] ;           /* ������ ���ގ����� �Ҏ��������� ���؎�    */
};
typedef struct mstnstko MSNSTK1 ;
