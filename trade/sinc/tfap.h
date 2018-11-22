/********************************************************************/ 
/*                                                                  */ 
/*                  tfap.h                                          */ 
/*                                                                  */ 
/*          TFAP �Î��̎ގ� �̎����ώ���   87.12.05                            */ 
/*                       �ѹ�   94.12.20 JJ  �ѹ���  ����  ��       */
/*                       �ѹ�   95.05.28 JK  �ѹ���  ����  ��       */
/*                       �ѹ�   95.07.14 S1  �ѹ���  ��ƣ��ͳ��		*/
/*								AP�׵ἱ�̻Ҥε�ǽ���ɲä��줿����	*/
/*								�ξ����ɼ��ST2772					*/
/*                       �ѹ�   95.07.18 S2  �ѹ���  ��ƣ��ͳ��		*/
/*								tfaprcad tfaprcsz��4WonX25�Ǥ�������*/
/*								���Ƥʤ��ä��褦������LICP�Ύ؎��ĎޤǤ�*/
/*								ή�Ѥ��뤳�ȤȤ��롣				*/
/*								�ξ����ɼ��ST2772					*/
/*                                                                  */
/********************************************************************/

struct mdfapsb {
    short    tfapinen;                  /* ͽ��                  JJ */
    char     tfapricp;                  /* ͽ��                  JJ */
    char     tfapyob0[5];               /* �֎ˎ� 0                 JJ */
};
typedef struct mdfapsb MDFAPSB;         /* DCP �֎�                   */
typedef struct mdfapsb TFAPSUB;         /* FIP �֎�                   */

struct mdfapko {
	char 	tfapkbst;              	/*  ���͎ގ̎� ���Î�����            */
	char	tfapyob1;               /*  �֎ˎ� 1                   */
	short	tfapfacn;               /*  TFAC ���ݎĎ� NO            */
	short	tfaplptn;               /*  TLPT ���ݎĎ� NO            */
	char	tfapiokd;               /*  ���ݎώ� �����͎ގ�              */
	char	tfapyob2;               /*  �֎ˎ� 2                   */
	short	tfapdvno;               /*  ������ �ʎގݎ��ގ�              */
	short	tfapphno;               /*  �ێݎ� �ʎߎ� �ʎގݎ��ގ�          */
	char	tfapsoft;               /*  ���̎� ���ʎގ�                */
	char	tfapprfx;               /*  �̎ߎڎ̎�����                 */
/* *** 87.12.7 *** STC550 *** */
	char	tfapfiln[22];           /*  �Ď����� �̎����� �Ҏ�            */
	long	tfapfdsc;               /*  �̎����� �Îގ������؎̎ߎ�          */
	char	tfapflst;               /*  �̎����� ���Î�����              */
	char	tfaplpws;               /*  �����ݎĎގ� ��������             */
	short   tfapaprd;				/* char	[2] -> short   JJ JK*/
									/* AP�׵ἱ�̻�			 S1 */
	long	tfaprcad;               /*  �����Îގ�����Ǽ�莱�Ďގڎ�  JK */
									/* S2						*/
	long	tfaprcsz;               /*  �����Îގ�����Ǽ�莻������   JK */
									/* S2						*/
	char	tfapyob4[4];            /*  �֎ˎ� 4                JK */
};
typedef struct mdfapko MDFAPKO;         /* DCP �֎�                   */
typedef struct mdfapko TFAPPSZ;         /* FIP �֎�                   */
