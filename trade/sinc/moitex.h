/*********************************************************************/
/*   ���ώݎĎގ��ݎ��̎ߎ؎� ���ގ��� �֎� ���ݎ���-�Ď� �̎�����                              */
/*********************************************************************/


#define  REQUEST    0x00000001L         /* �؎������� �����͎ގ�              */
#define  EVENT      0x00000001L         /* ���͎ގݎ� �ʎގݎ��ގ�              */



extern struct tgon ptrarea[50];         /* �܎؎��� ��-�̎ގ�                */
extern UCHR reqidflg[31];               /* �؎������� �����͎ގ� ��-�̎ގ�        */
extern UCHR evenflg[31];                /* ���͎ގݎ� �ʎގݎ��ގ� ���֎� �̎׎���     */
extern UCHR msgflg[3];                  /* �Ҏ�-���� �̎׎���               */
extern UCHR deverr;                     /* �܎؎��� �����ގ֎� �̎׎���           */
extern UCHR mrhmsg;                     /* mrh MSG ���ގ����� �̎׎���		 */
extern UCHR message[sizeof(struct momhead)+sizeof(MOCMDMSG)];
										/* �Ҏ�-���� ���ގՎ��� �؎֎�����        */
extern int onno;                        /* ���ގ� ON �̎ގ� �ʎގݎ��ގ�         */
extern long *rcdpoi;                    /* rcode ���Î� ���� �Ύߎ��ݎ�       */
extern long srttblno;                   /* SRT ��-�̎ގ� �����ގ� �ʎގݎ��ގ�     */
