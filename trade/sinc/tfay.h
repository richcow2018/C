
/********************************************************************/
/*																	*/
/*					tfay.h											*/
/*																	*/
/*			TFAY �Î��̎ގ� �̎����ώ���	94.09.16	 ������	 ������			*/
/*																	*/
/********************************************************************/

struct mdfayko
{
	unsigned char	tfaykbst;		/* ���ơ����� */
	char			tfayyob0[3];	/* ͽ��	*/
	short			tfayllno;		/* ���������ֹ�	*/
	short			tfayfacn;		/* �ԣƣ��äΥ���ȥ��ֹ� */
	unsigned char	tfaydadl;		/* ��³��Σģԣť��ɥ쥹��� */
	unsigned char	tfaydadr[8];	/* ��³��Σģԣť��ɥ쥹 */
	unsigned char	tfaycpks;		/* ȯ�Ƽ������ѥ��åȥ�����	*/
	unsigned char	tfayrpks;		/* ��Ƽ������ѥ��åȥ�����	*/
	unsigned char	tfaycwsz;		/* ȯ�Ƽԥ�����ɥ������� */
	unsigned char	tfayrwsz;		/* ��Ƽԥ�����ɥ������� */
	unsigned char	tfayfslt;		/* �ե����ȥ��쥯���׵�	*/
	unsigned char	tfaypchk;		/* �忮�ݶ�	*/
	unsigned char	tfayctpc;		/* ȯ����˸Ƽԥ��롼�ץåȥ��饹 */
	unsigned char	tfaycxal;		/* ȯ���ɥ쥹��ĥ�Υ��ɥ쥹���	*/
	unsigned char	tfaycxad[20];	/* ȯ���ɥ쥹��ĥ�Υ��ɥ쥹�� */
	unsigned char	tfayrxal;		/* �奢�ɥ쥹��ĥ�Υ��ɥ쥹���	*/
	unsigned char	tfayrxad[20];	/* �奢�ɥ쥹��ĥ�Υ��ɥ쥹�� */
	unsigned char	tfayclas;		/* �ǣפǤ������ץ�ȥ���	*/
	unsigned char	tfaygwln;		/* �ǣ׾�Ǥμ���ü�������ֹ� */
	long			tfaydsta;		/* �����ü���Υ��ɥ쥹����	*/
	unsigned long	tfaysopt;		/* Ŭ�ѥ����ƥ४�ץ���� */
	unsigned char	tfayrspt;		/* �쥹�ݥ��Ԥ�������	*/
	char			tfayyob1[3];	/* ͽ��	*/
	long			tfaymaxd;		/* ����ʬ��ǡ���Ĺ	*/
	char			tfayyob2[8];	/* ͽ��	*/
};
typedef	struct mdfayko TFAYPSZ;			/* FIP �֎�					*/
