/********************************************************************/
/*                                                                  */
/*                  tfax.h                                          */
/*                                                                  */
/*          TFAX �Î��̎ގ� �̎����ώ���   94.12.20     ������  ����  ��       */
/*                                                                  */
/********************************************************************/

struct mdfaxko
{
	unsigned char	tfaxkbst;      	/* ���ơ����� */
	char			tfaxyob0[3];    /* ͽ�� */
	short			tfaxllno;       /* ���������ֹ� */
	short			tfaxfacn;       /* �ԣƣ��äΥ���ȥ��ֹ� */
	unsigned char	tfaxdadl;       /* ��³��Σģԣť��ɥ쥹��� */
	unsigned char	tfaxdadr[8];    /* ��³��Σģԣť��ɥ쥹 */
	unsigned char	tfaxcpks;       /* ȯ�Ƽ������ѥ��åȥ����� */
	unsigned char	tfaxrpks;       /* ��Ƽ������ѥ��åȥ����� */
	unsigned char	tfaxcwsz;       /* ȯ�Ƽԥ�����ɥ������� */
	unsigned char	tfaxrwsz;       /* ��Ƽԥ�����ɥ������� */
	unsigned char	tfaxfslt;       /* �ե����ȥ��쥯���׵� */
	unsigned char	tfaxpchk;       /* �忮�ݶ� */
	unsigned char	tfaxctpc;       /* ȯ����˸Ƽԥ��롼�ץåȥ��饹 */
	unsigned char	tfaxcxal;       /* ȯ���ɥ쥹��ĥ�Υ��ɥ쥹��� */
	unsigned char	tfaxcxad[20];   /* ȯ���ɥ쥹��ĥ�Υ��ɥ쥹�� */
	unsigned char	tfaxrxal;       /* �奢�ɥ쥹��ĥ�Υ��ɥ쥹��� */
	unsigned char	tfaxrxad[20];   /* �奢�ɥ쥹��ĥ�Υ��ɥ쥹�� */
	unsigned char	tfaxclas;       /* �ǣפǤ������ץ�ȥ��� */
	unsigned char	tfaxgwln;       /* �ǣ׾�Ǥμ���ü�������ֹ� */
	long			tfaxdsta;       /* �����ü���Υ��ɥ쥹���� */
	unsigned long	tfaxsopt;       /* Ŭ�ѥ����ƥ४�ץ���� */
	unsigned char	tfaxrspt;       /* �쥹�ݥ��Ԥ������� */
	char			tfaxyob1[3];    /* ͽ�� */
	long			tfaxmaxd;       /* ����ʬ��ǡ���Ĺ */
	char			tfaxyob2[8];    /* ͽ�� */
};
typedef struct mdfaxko TFAXPSZ;         /* FIP �֎�                   */
