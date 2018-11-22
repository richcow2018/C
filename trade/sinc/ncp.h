/****************************************************************************/
/* �Ρ��ɴ������ơ��֥�														*/
/****************************************************************************/
/****************************************************************************/
/* (�Ρ��ɴ������¹�)�ץ������ִ����ơ��֥�								*/
/****************************************************************************/
// ������
struct tpsmmng{
	long	tpsmpszcnt;					// ��������
	long	tpsmactpcnt;				// ��ư�ץ�����
	char	tpsmmyob1[8];				// ͽ��
};
typedef	struct	tpsmmng	TPSMMNG;

// ������
struct tpsmpsz{
	long	tpsmpid;					// �Ρ��ɴ������¹ԥץ������̻�
	long	tpsmmbid;					// �Ρ��ɴ������¹ԥᥤ��ܥå������̻�
	char	tpsmpnm[8];					// �Ρ��ɴ������¹ԥץ���̾
	long	tpsmabtm;					// �ץ������ܡ��Ȳ�� 
	char	tpsmactsts;					// �ץ�����ư���� '0':̤��ư '1':��ư '2':��������
	char	tpsmusests;					// �ץ������Ѿ��� '0':̤���� '1':������
	char	tpsmtosts;					// �����ॢ����ȯ������ '0':̤ȯ�� '1':ȯ����
	char	tpsmpyob1[9];				// ͽ��
};
typedef	struct	tpsmpsz	TPSMPSZ;

/****************************************************************************/
/* �����׵���ʸ���ѥơ��֥�													*/
/****************************************************************************/
// ��å�������(������)
typedef	struct	tmsqpsz	TMSQPSZ;
struct tmsqpsz{
	TMSQPSZ	*tmsqbefad;					// ����å��������ɥ쥹
	TMSQPSZ	*tmsqnxtad;					// ����å��������ɥ쥹
	long	tmsqtime;					// ��å���������(��Ǽ)����
	long	tmsqrd;						// �����޴����ѥꥯ�����ȼ��̻�
	char	tmsqmsgsts;					// ��å������������� '0':̤���� '1':������
	char	tmsqmsgtyp;					// ��ʸ������ '0':�Ρ��ɴ��̿� '1':�ϴ��̿� '2':�ü�ϴ��̿�
	char	tmsqpyob1[14];				// ͽ��
	char	tmsqmdxpnm[8];				// ������ץ�������̾(�����¹ԥץ���)
	long	tmsqmsgsz;					// �׵���ʸ������
	long	*tmsqmsgad;					// �����׵���ʸ��Ǽ�ס���Хåե����ɥ쥹
};

// ������
typedef	struct	tmsqmng	TMSQMNG;
struct tmsqmng{
	TMSQPSZ		*tmsqbefad;				// ����å��������ɥ쥹
	TMSQPSZ		*tmsqnxtad;				// ����å��������ɥ쥹
	long	tmsqmsgcnt;					// ���ѥ�å�������
	long	tmsqmsprrd;					// ��å����������׵�ꥯ�����ȼ��̻�
};


/****************************************************************************/
/* �Ρ��ɴ���ʸ�إå�														*/
/****************************************************************************/
// �Ρ��ɴ��̿�����إå�
struct nodehead{
	char	mkcd[4];					// MK������
	long	rcvtime;					// ��������
	char	msgtype;					// ��ʸ������ '0':�Ρ��ɴ��̿� '1':�ϴ��̿� '2':�ü�ϴ��̿�
	char	yob1[3];					// ͽ��
	long	rcode;						// �ֵ���
	char	sndpnm[8];					// ȯ�����ץ�������̾
	char	rcvpnm[8];					// ������ץ�������̾
	long	sndpmid;					// ȯ�����ᥤ��ܥå������ץ������̻�
	long	rcvpmid;					// ������ᥤ��ܥå������ץ������̻�
	long	msglen;						// ��ʸĹ
	char	yob2[4];					// ͽ��
};
typedef	struct	nodehead	NODEHEAD;

// �ϴ��̿�����إå�
struct keihead{
	char	mkcd[4];					// MK������
	long	rcvtime;					// �����դ�����
	long	rcode;						// �ֵ���
	long	corbarc;					// CORBA�ޥ��ʡ������� 
	long	sndpmid;					// ȯ�����ᥤ��ܥå������ץ������̻�
	long	rcvpmid;					// ������ᥤ��ܥå������ץ������̻�
	long	msglen;						// ��ʸĹ
	char	yob2[4];					// ͽ��
};
typedef	struct	keihead	KEIHEAD;

// �Ρ��ɴ��̿���MIA���̰襨�ꥢ
struct mdaparea{
        long      if_code;				// ���󥿥ե�����������
        char      dummy;				// ͽ��
        char      code1;				// ���Υ����ɣ�
        short     code2;				// ���Υ����ɣ�
        short     nodeno;				// �Ρ����ֹ�
        short     idcode;				// ���̥�����
        short     pu_no;				// PU�ֹ�
        short     line_no;				// �����ֹ�
};
typedef struct  mdaparea    MDAPAREA;

// MIA���̰襨�ꥢ
struct miapsz{
        long	if_code;				// ���󥿥ե�����������
        long	code1;					// ���Υ����ɣ�
        long	code2;					// ���Υ����ɣ�
        long	endcd;					// ��λ������
        long	detail;					// �ܺ٥�����
        char	prnm[8];				// �ץ�������̾
};
typedef	struct	miapsz	MIAPSZ;

/****************************************************************************/
/* CORBA�ֵѾ���															*/
/****************************************************************************/
// �ֵѾ����Ǽ��¤��
struct retinfo{
        long	cd1;					//�����Х��ץ괰λ������
        long	cd2;					//�����Х��ץ�ܺٴ�λ������
        long	inf;					//����Ǥ�վ���(�����Х��ץ�ư��϶�ʬ)
        long	major;					//CORBA�᥸�㡼������
        long	minor;					//CORBA�ޥ��ʡ�������
        char	id[129];				//CORBA�㳰����
		char	yobi[15];
};
typedef	struct	retinfo	RETINFO;

/****************************************************************************/
/* ���顼�ơ��֥�															*/
/****************************************************************************/
struct errinf
{
	long	id;							/* �ֹ� */
	char	sysexcep_id[32];			/* CORBA system exception id		*/
	long	minorcd;					/* CORBA minor error code			*/
	long	svaplrc1;					/* server application return code 1	*/
	long	svaplrc2;					/* server application return code 2	*/
	char	noticecd1;					/* ���Υ����� 1						*/
	short	noticecd2;					/* ���Υ����� 2 					*/
	char	kdevacd;					/* �ϴֿ���ʬ���۾�					*/
	long	senms2rc;					/* ossenms2�ֵ���					*/
};
typedef	struct	errinf	ERRINF;

#define ERRTBLNUM	18					/* ���顼�ơ��֥�ιԿ�				*/

#define	ERID_MOCHI	50					/* ���������ʸ����					*/
#define	ERID_SNDND	51					/* ������Ρ����ֹ�����				*/
#define	ERID_TOUT	52					/* �����ॢ����						*/
#define	ERID_ENDMDX	53					/* �������MDX��λ���μ���			*/

/****************************************************************************/
/* �Ρ��ɴ���������														*/
/****************************************************************************/
//�ü�ϴ���ʸMK������
#define	MKCD_SPKEISND	0x01130101		// �ü�ϴ֥ǡ��������׵�
#define	MKCD_SPKEIRCV	0x01130201		// �ü�ϴ֥ǡ�����������

//�Ρ��ɴ�������ʸMK������
#define	MKCD_NDCTLSND	0x01130102		// �Ρ��ɴ֥ǡ��������׵�
#define	MKCD_NDCTLRCV	0x01130202		// �Ρ��ɴ֥ǡ�����������

//�ֵѥ�å������μ���
#define TP_TOUT			1				/* �����ॢ�������Τ����			*/
#define TP_SPKEIREQ		2				/* �ü�ϴ������׵���ʸ(ossenms2)����	*/
#define TP_NDCTLREP		3				/* �Ρ��ɴ���������������ʸ����		*/
#define TP_ENDREQ		4				/* �ץ�����λ�׵���ʸ����			*/
#define TP_ENDNOTICE	5				/* �ץ�����λ������ʸ����			*/
#define TP_NDSNDREQ		6				/* �Ρ��ɴ֥ǡ��������׵���ʸ����	*/
#define TP_KEISNDREQ	7				/* �ϴ֥ǡ��������׵���ʸ����		*/
#define TP_NGMKCD		-1				/* MK����������						*/
#define TP_NGMOCHI		-2				/* ���������ʸ����					*/
#define TP_NGNODENO		-3				/* ������Ρ����ֹ�����				*/

//��ʸ������
#define	MSGTYPE_NODE	'0'				/* �Ρ��ɴ��̿�						*/
#define	MSGTYPE_KEI		'1'				/* �ϴ��̿�							*/
#define	MSGTYPE_SPKEI	'2'				/* �ü�ϴ��̿�(ossenms2)			*/

//�Ρ��ɴ������¹ԥץ�������
#define PRGTYP_MDX		"87"			/* �Ρ��ɴ������¹ԥץ���			*/

//
#define	RESTDLY_MDC		3				/* mdc�ꥹ�����Ȼ����ٱ����		*/

/****************************************************************************/
/* �����Х��ץꥱ��������ޤ��֤�����λ������								*/
/****************************************************************************/
#define SVEND_NGMS	-1					/* ��ס���Хåե���Υ�å����������˼���	*/
#define SVEND_NGPB	-2					/* �ס���Хåե��γ��ݤ˼���		*/
#define SVEND_NGMB	-3					/* �ᥤ��ܥå������̻Ҥμ����˼��� */
#define SVEND_NGMSP	-4					/* �ס���Хåե���Υ�å����������˼��� */
