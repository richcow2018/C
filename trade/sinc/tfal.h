/********************************************************************/
/*                                                                  */
/*                  tfal.h                                          */
/*                                                                  */
/*          TFAL �Î��̎ގ� �̎����ώ���   94.12.20     ������  ����  ��       */
/*                       �ѹ�	03.01.17	 �ѹ���	 ����  ����	    */
/*																	*/
/********************************************************************/

struct mdfalko
{
	unsigned	char	tfalkbst;		/* ���ơ����� */
				char	tfalyob0[3];	/* ͽ�� */
				short	tfalllno;		/* ���������ֹ� */
				short	tfalfacn;		/* �ԣƣ��äΥ���ȥ��ֹ� */
	unsigned	long	tfalloca;		/* ����ü�������륢�ɥ쥹 */
	unsigned	char	tfalrspt;		/* �쥹�ݥ��Ԥ������� */
				char	tfalyob1;		/* ͽ�� */
				short	tfallicn;		/* �ԣ̣ɣå���ȥ��ֹ� */
				long	tfalmaxd;		/* ����ʬ��ǡ���Ĺ */
				char	tfalyob2[4];	/* ͽ�� */
};
typedef struct mdfalko TFALPSZ;			/* FIP �֎�                   */
