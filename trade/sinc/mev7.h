/************************************************************************************************/
/*	���	��������																			*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�	V7�̿������											*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �̿�����													*/
/* ���оݶ�̳�ɣġ� 				 �ţģСʣȣãСݣӡΣ֣��ϡ�								*/
/* �㥵���ӥ�����̾��				 �ģãӥ��󥿥ե�����										*/
/* �㥵���ӥ����ܣɣġ� 			 															*/
/* ��⥸�塼��̾��					 															*/
/* ��⥸�塼��ɣġ�				 															*/
/* ��⥸�塼�����֡�																			*/
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��					 ���ѥ�����													*/
/* ��Ŭ�ѣϣӡ� 					 �̣����� 												*/
/* �㳫ȯ�Ķ��� 					 �ңȣ��ӣ�����												*/
/* �㵭�Ҹ���� 					 �ø��� 													*/
/* ��⥸�塼����֡�				 �ؿ�														*/
/* �㵡ǽ��ʬ�� 																				*/
/* ���оݥǡ�����																				*/
/* �㹩�������ض�ʬ��																			*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��				 �أأءݣӣͣХ����ƥ� 									*/
/* �㳫ȯ�����ƥ��ֹ�� 			 �УУ����£�����������										*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼�������ץ饤)					*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô��										*/
/* ���߷�ǯ������					 ��������ǯ ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼��:���ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼��:���ץ饤����)                */
/* �㥽������ǯ�����ڤӽ����ɣġ�    ��������ǯ�����������                                   */
/*                                   �ξ����ɼ�ʣԣ£ãӣ���������                         M01 */
/*                                     Ω���夲������ɲ�                                       */
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   �äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include	<stdio.h>								// ɸ�������ϴؿ�

/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	<dcs_lib.h>								// DCS�饤�֥�����

/*********************************** �ģţƣɣΣ��� *********************************************/
// �ե饰����
#define V7FLGOFF	0x00							// �ե饰���ꡧOFF
#define V7FLGON		0x01							// �ե饰���ꡧON
// �ǡ�������
#define V7DATFST	0x01							// ���μ��̡�FIRST
#define V7DATMDL	0x02							// ���μ��̡�MIDDLE
#define V7DATLST	0x03							// ���μ��̡�LAST
#define V7DATONL	0x00							// ���μ��̡�ONLY
#define	V7DATNON	0xFF							// ���μ��̡�̵��
// ü��������
#define V7TMT_HOST	0x00							// ü�������ס��ۥ��ȼ�Ƴ
#define V7TMT_TM	0x01							// ü�������ס�ü����Ƴ

// �������μ���
#define V7TRMCLR	0x10							// CLEAR����
#define V7TRMCLS	0x20							// �Ķ�����
#define V7TRMNRS	0x21							// �Ķ����Ρʡݣңӣм�����
#define V7TRMHRD	0x31							// �ѥ��۾�ʥϡ��ɥ��顼��
#define V7TRMSES	0x32							// �ѥ��۾�ʥ��å���󥨥顼��
// �ѥ�����
#define V7PSCIDL	0x01							// �Ķ�-�����ɥ�
#define V7PSCOPN	0x02							// �Ķ�-���ɽ�����
#define V7PSCROP	0x03							// �Ķ�-�Ƴ��ɽ�����
#define V7PSOIDL	0x11							// ����-�����ɥ�
#define V7PSOCLS	0x12							// ����-�Ķɽ�����
#define V7PSODCN	0x13							// ����-������
#define V7PSORCN	0x14							// ����-����³��
#define V7PSOTCN	0x15							// ����-���������Ԥ�
#define V7PSOCLR	0x16							// ����-RCLEAR/SCLEAR�Ԥ�
#define V7PSORW		0x17							// ����-READ/WRITE�׵���
#define V7PSORED	0x18							// ����-READ�׵���
#define V7PSOWRT	0x19							// ����-WRITE�׵���
#define	V7PSERR		0x20							// ư����ǽ

// �ۥ��������ѥ������å��ֵ������
#define V7TRUE		0x00							// �ۥ��������ѥ�
#define V7FALSE		0x01							// �ۥ��������ѥ��ʳ�
#define V7ERROR		0xFF							// NG

// EDT�ǡ����������
#define	V7EDT_NON	0x00							// ̤����
#define	V7EDT_ING	0x10							// �������dcswrite�Ѥߡ�
#define	V7EDT_WAIT	0x11							// ������λ�����Ԥ�
#define	V7EDT_WEND	0x20							// WRITE ��λ

// DCS���󥿥ե��������
#define	V7HTBLNUM	256								// ���ץ����Ǥ�DCS��³��MAX
#define	V7DCSNAME	"u_dcs"							// DC�����ӥ�̾����Ƭ5ʸ����

// ���ޥ�ɥ�����
#define	V7MECOPN	0x01							// me_copn
#define	V7MECCLS	0x02							// me_ccls
#define	V7MERSTA	0x07							// me_rsta
#define	V7MECEDT	0x04							// me_cedt
#define	V7METRED	0x03							// me_tred
#define	V7METCNT	0x05							// me_tcnt
#define	V7METCAN	0x06							// me_tcan

//�۾��װ�
#define	V7ERR_HARDNG	0x0101						// �ϡ��ɥ��顼

#define	V7ERR_CONLOST	0x0202						// ���ͥ����������

#define	V7ERR_HILULOST	0x0301						// �̣վ�̥ѥ�����
#define	V7ERR_NRLULOST	0x0302						// �̣եѥ�����
#define	V7ERR_LURESET	0x0303						// �̣եѥ��ꥻ�å�

#define V7ERR_NRESP		0x0401						// �ݣңӣм���
#define V7ERR_READBLK	0x0412						// �֥�å���������顼
#define V7ERR_CANCEL	0x0413						// �ãͣģ�����

#define V7ERR_STSNG		0x0501						// ���ơ��������顼
#define V7ERR_NOOPN		0x0502						// �����ѥ�̤�����ץ�
#define V7ERR_INOPN		0x0503						// �����ѥ������ץ������
#define V7ERR_INCLS		0x0504						// �����ѥ���������
#define	V7ERR_PARAMNG	0x0506						// �ѥ�᡼�����顼
#define V7ERR_FINOPN	0x0505						// �����ѥ������ץ�Ѥ�
#define V7ERR_DOUBLE	0x0507						// ����ȯ��
#define V7ERR_SENDBLK	0x0508						// �֥�å����顼
#define V7ERR_SENDLEN	0x0509						// �ǡ���Ĺ���顼
#define V7ERR_INRSTA	0x050A						// �ꥹ�����Ƚ�����
#define V7ERR_DCSNG		0x050C						// �ģãӥ��顼

#define V7ERR_CANREC	0x0601						// ����󥻥�ˤ����
#define V7ERR_CLOSEREC	0x0602						// �������ˤ����
#define V7ERR_SSENDREC	0x0603						// ������ߤˤ����
#define V7ERR_RECVREC	0x0604						// ������ߤˤ����
	
#define V7ERR_CANNG		0x0701						// ����󥻥뼺��
#define V7ERR_SSENDNG	0x0702						// ������߼���
#define V7ERR_SREADNG	0x0703						// ������߼���

#define V7ERR_ROGINNG	0x0901						// ����������

/************************************ ��¤������� **********************************************/
// COPN�׵ᥳ�ޥ���ΰ�
typedef struct	mev7copcmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		dummy1[3];							// ͽ��
	char		lukind;								// LU����
	char		tmtype;								// ü��������
	char		dummy2[2];							// ͽ��
	char		dummy3[4];							// ͽ��
	short		logonsize;							// ��������󥵥���
	char		logoninfo[256];						// ���������
}MEV7COPCMD;

// CCLS�׵ᥳ�ޥ���ΰ��me_ccls���׵ᥳ�ޥ�ɤ�̵�����������ݻ��ΰ٤˻��ѡ�
typedef struct	mev7cclcmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		dummy1[3];							// ͽ��
}MEV7CCLCMD;

// RSTA�׵ᥳ�ޥ���ΰ��me_rsta���׵ᥳ�ޥ�ɤ�̵�����������ݻ��ΰ٤�me_copn��Ʊ�칽¤����ѡ�
typedef struct	mev7rstcmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		dummy1[3];							// ͽ��
	char		lukind;								// LU����
	char		tmtype;								// ü��������
	char		dummy2[2];							// ͽ��
	char		dummy3[4];							// ͽ��
	short		logonsize;							// ��������󥵥���
	char		logoninfo[256];						// ���������
}MEV7RSTCMD;

// EDT�׵ᥳ�ޥ���ΰ�
typedef struct	mev7edtcmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		dummy1[3];							// ͽ��
	short		blocknum;							// �֥�å���
	short		blocklen;							// �����ǡ���Ĺ
	char		blockkind;							// �֥�å�����
	char		dummy2[3];							// ͽ��
	char		*dataadr;							// �ǡ�����Ǽ�襢�ɥ쥹
}MEV7EDTCMD;

// TRED�׵ᥳ�ޥ���ΰ��me_tred���׵ᥳ�ޥ�ɤ�̵�����������ݻ��ΰ٤˻��ѡ�
typedef struct	mev7trecmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		dummy1[3];							// ͽ��
}MEV7TRECMD;

// TCNT�׵ᥳ�ޥ���ΰ�
typedef struct	mev7tcncmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		pcode;								// ����������
	short		cause;								// ��ͳ
}MEV7TCNCMD;

// TCAN�׵ᥳ�ޥ���ΰ�
typedef struct	mev7tcacmd {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		pcode;								// ����������
	char		dummy1[2];							// ͽ��
}MEV7TCACMD;

//**************************************************//
// DCS���ξ���
typedef struct	mev7dcscom {
	char		mkcd[4];							// MK������
	long		rcvsize;							// �����ǡ���������
}MEV7DCSCOM;

// DCS��å������趦�̾���
typedef struct	mev7rescom {
	char		mkcd[4];							// MK������
	short		cmdsize;							// �������ޥ���ΰ襵����
	short		pathno;								// �����ѥ��ֹ�
	unsigned long s_time;							// Ω�������	M01
	long		dummy1;								// ͽ��
}MEV7RESCOM;

// �������ޥ���ΰ� �ʶ���)
typedef struct	mev7resall {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
}MEV7RESALL;

// �������ޥ���ΰ� ��me_copn)
typedef struct	mev7rescop {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
}MEV7RESCOP;

// �������ޥ���ΰ� ��me_ccls)
typedef struct	mev7resccl {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
}MEV7RESCCL;

// �������ޥ���ΰ� ��me_rsta)
typedef struct	mev7resrst {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
}MEV7RESRST;

// �������ޥ���ΰ� ��me_cedt)
typedef struct	mev7resced {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
}MEV7RESCED;

// �������ޥ���ΰ� ��me_tred)
typedef struct	mev7resred {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
	short		blocknum;							// �֥�å���
	short		blocklen;							// �֥�å�Ĺ
	char		blockkind;							// �֥�å�����
	char		dummy1[3];							// ͽ��
	char		*dataadr;							// �ǡ�����Ǽ�襢�ɥ쥹
}MEV7RESRED;

// �������ޥ���ΰ� ��me_tcnt)
typedef struct	mev7restcn {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
	short		pcode;								// ����������
	char		dummy1[2];							// ͽ��
}MEV7RESTCN;

// �������ޥ���ΰ� ��me_tcan)
typedef struct	mev7restca {
	char		cmdcode;							// ���ޥ�ɥ�����
	char		cmpcode;							// ��λ������
	short		errfact;							// �۾��װ�
	short		pcode;								// ����������
	char		dummy1[2];							// ͽ��
}MEV7RESTCA;

// �������ޥ���ΰ� �����Ρ�
typedef union	mev7rescmd {
	MEV7RESALL	resall;								// �������ޥ���ΰ� �ʶ���)
	MEV7RESCOP	rescop;								// �������ޥ���ΰ� ��me_copn)
	MEV7RESCCL	resccl;								// �������ޥ���ΰ� ��me_ccls)
	MEV7RESRST	resrst;								// �������ޥ���ΰ� ��me_rsta)
	MEV7RESCED	resced;								// �������ޥ���ΰ� ��me_cedt)
	MEV7RESRED	resred;								// �������ޥ���ΰ� ��me_tred)
	MEV7RESTCN	restcn;								// �������ޥ���ΰ� ��me_tcnt)
	MEV7RESTCA	restca;								// �������ޥ���ΰ� ��me_tcan)
}MEV7RESCMD;

// �ģãӥ�å������ΰ�ʴ�λ�׵����Ρ�
typedef struct	mev7dcsmsg {
	MEV7RESCOM	rescom;								// DCS��å��������̰�
	MEV7RESCMD	rescmd;								// �������ޥ���ΰ�
}MEV7DCSMSG;

// �����ǡ������ꥢ
typedef	struct	mev7senddd {
	void		*nextadr;							// ���ǡ������ɥ쥹
	long		status;								// �ǡ�������
	MDHIKYO		*sdata;								// �����ǡ���
	MEV7DCSMSG	*dcsmsg;							// WRITE����ݻ����ɥ쥹
}	MEV7SENDD;


//**************************************************//

// �ۥ����̿�����TBL������
typedef struct	mev7hkcm{
	char		tblname[4];							// �ơ��֥�̾��TV7T��
	long		message;							// ��å��������塼
	BlpDac_PDCB	dcbaddr;							// ���⥢�ɥ쥹
	long		kbt_num;							// �������������
	long		open_rtimer;						// �ƥ����ץ��ȥ饤������(�ߥ�)
	unsigned long s_time;							// Ω���夲������		M01
	long		dummy1[2];							// ͽ��
}MEV7HKCM;

typedef struct	mev7hkbt{
	char		dcsname[32];						// DC�����ӥ�̾

	char		pathsts;							// �ѥ�����
	char		reserve1;							// ͽ��
	short		pathno;								// �����ѥ��ֹ�

	char		trmkind;							// �������μ���
	unsigned char datkind;							// ���μ���
	char		sendkind;							// ��������
	char		reserve2;							// ͽ��

	char		rdprcflg;							// �꡼�ɽ�����ե饰
	char		sdcmpflg;							// ������λ�����Ԥ��ե饰
	char		edprstflg;							// �Ƴ��ϥե饰
	char		reserve3;							// ͽ��

	long		timer_rd;							// ��ȥ饤�����ޤ�rd��̤ȯ�Ի���0��

	char		dcsptnm[12];						// �����ѥ�����̾

	DCSLib_PCB*	pcbaddr;							// ���䥢�ɥ쥹

	long		datseqno;							// ���������ֹ�
	long		reserve4[3];						// ͽ��

	MEV7COPCMD	copncmd;							// me_copn �׵ᥳ�ޥ�ɾ���
	MEV7CCLCMD	cclscmd;							// me_ccls �׵ᥳ�ޥ�ɾ���
	MEV7RSTCMD	rstacmd;							// me_rsta �׵ᥳ�ޥ�ɾ���
	MEV7TRECMD	tredcmd;							// me_tred �׵ᥳ�ޥ�ɾ���
	MEV7TCNCMD	tcntcmd	;							// me_tcnt �׵ᥳ�ޥ�ɾ���
	MEV7TCACMD	tcancmd;							// me_tcan �׵ᥳ�ޥ�ɾ���
	MEV7DCSMSG*	rcvdtinf;							// �����ǡ����ݻ����󥢥ɥ쥹
	MEV7SENDD*	edtdtinf[2];						// cedt�ݻ����󥢥ɥ쥹
}MEV7HKBT;

typedef struct mev7kinf{
	MEV7HKBT	*adr;
}MEV7KINF;

// �ۥ����̿�����TBL
typedef struct mev7htkt{
	MEV7HKCM	hstknkcm;							// �ۥ����̿�����TBL������
	MEV7KINF	hstknkbt[V7HTBLNUM];				// �ۥ����̿�����TBL������
}MEV7HTKT;

// V7�̿���PSECT
typedef	struct	mev7psect{
	MEV7HTKT	*mev7htkt;							// �ۥ����̿������ơ��֥���Ƭ���ɥ쥹
	long		dummy[3];							// ͽ��
} MEV7PSECT;
