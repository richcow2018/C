/***************************************/
/*                                     */
/*              tlgt.h                 */
/*                                     */
/*        TLGT �Î��̎ގ� �̎����ώ���            */
/*                                     */
/* �ѹ�  94.12.20 JJ  �ѹ���  ����  �� */
/*                                     */
/***************************************/

struct mdlgtsb {
    short    tlgtinen;            /* ͽ��                   JJ */
    char     tlgtyob0[6];         /* �֎ˎ�0                   JJ */
};
typedef struct mdlgtsb MDLGTSB;   /* DCP �֎�                    */
typedef struct mdlgtsb TLGTSUB;   /* FIP �֎�                    */

struct mdlgtko {
	char   tlgtkhyo    ;      /* ���͎ގ̎� �ˎ�������               */
	char   tlgtyob1[3] ;      /* �֎ˎ�1                       */
	short  tlgtlphn    ;      /* TLPH ���ݎĎ� NO.              */
	short  tlgtlptn    ;      /* TLPT ���ݎĎ� NO.              */
	short  tlgtpatn    ;      /* TPAT ���ݎĎ� NO.              */
	short  tlgtyob2    ;      /* �֎ˎ�2                       */
	long   *tlgtmiaa   ;      /* �׎��� MIA �����ˎ��� ���Ďގڎ�        */
	long   *tlgtdsad   ;      /* �Ύ؎��� �Îގ��� ������ ���Ďގڎ�        */
	char   tlgtyob3[4] ;      /* �֎ˎ�3                    JJ */
};
typedef struct mdlgtko MDLGTKO;   /* DCP �֎�                     */
typedef struct mdlgtko TLGTPSZ;   /* FIP �֎�                     */
