/**********************************************************************/
/*                                                                    */
/*        TLPH �Î��̎ގ� �̎����ώ���     tlph.h      (61.12.  )                */
/*                                    �͎ݎ���  (62.12.  )   CC           */
/*                                    �ѹ�   94.12.20    JJ           */
/*                                    �ѹ��� ����  ��                 */
/*                                    �ѹ�   96.04.24    SS(ST4310)   */
/*                                    �ѹ��� ����  ��                 */
/*                                                                    */
/**********************************************************************/

struct mdlphsb {
        short   tlphinen;               /* ͽ��                    JJ */
        char    tlphyob0[6];            /* �֎ˎ�0                    JJ */
};
typedef struct mdlphsb MDLPHSB;         /* DCP �֎�                     */
typedef struct mdlphsb TLPHSUB;         /* FIP �֎�                     */

struct  mdlphko {
        char    tlphkhyo      ;         /* ���͎ގ̎� �ˎ�������               */
        char    tlphdyrc      ;         /* �ģ������о�ɽ��    SS   */
        char    tlphlusb      ;         /* LU �����͎ގ�                   */
        char    tlphttyp      ;         /* ���ݎώ� �����̎�                  */
        short   tlphfahn      ;         /* TFAH ���ݎĎ� NO.              */
        short   tlphlgtn      ;         /* TLGT ���ݎĎ� NO.              */
        short   tlphpuno      ;         /* PU NO.                     */
        short   tlphluno      ;         /* LU NO.                     */
        char    tlphhpas      ;         /* �ʎߎ� ���Î�����                  */
        char    tlphhopn      ;         /* �����̎ߎ� ���Î�����                */
        char    tlphhred      ;         /* �؎��Ď� ���Î�����                 */
        char    tlphhwrt      ;         /* �׎��� ���Î�����                  */
        char    tlphhscn      ;         /* �������� �������� ���Î�����            */
        char    tlphhrcn      ;         /* ���ގ����� �������� ���Î�����           */
        char    tlphhres      ;         /* �����Ď� �������� ���Î�����            */
        char    tlphhsht      ;         /* SHUT - DOWN ���Î�����         **/
        char    tlphhtex      ;         /* ���� �Îގݎ̎ގ� ���Î�����           */
        char    tlphhhdk      ;         /* �ˎĎގ��� ���� ���Î�����           **/
        short   tlphwrtc      ;         /* �׎��� �����ݎ�                   */
        char    tlphblct      ;         /* �̎ގ׎��� ���֎� �ˎ֎�����          **/
        char    tlphyob2      ;         /* �֎ˎ�2                      **/
        short   tlphtben      ;         /* TLPH �������֎��̎� ���ݎĎ؎� �ʎގݎ��ގ� **/
        short   tlphpatn      ;         /* TPAT ���ݎĎ؎� �ʎގݎ��ގ�       CC */
        short   tlphyob3      ;         /* �֎ˎ�3                    CC */
        char    tlphpsnm[8]   ;         /* �ێݎ� �ʎߎ� �����͎ގҎ�         CC */
        long    tlphyob4[2]   ;         /* �֎ˎ�4                 CC JJ */
};
typedef struct  mdlphko MDLPHKO;        /* DCP �֎�                     */
typedef struct  mdlphko TLPHPSZ;        /* FIP �֎�                     */
