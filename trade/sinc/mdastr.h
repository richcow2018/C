/************************************************************************/
/* header file for nodekan												*/
/************************************************************************/
typedef struct senms2msg
{
	char	mkcd[4];			// MK������
	long	pmid;				// ������ץ������̻Ҥޤ��ϥ᡼��ܥå������̻�
	long	pid;				// ���ץ���ID
	long	number;				// ����
	long	retcode;			// ��λ������
	long	msglen;				// ��å�����Ĺ
} SENMS2MSG;

