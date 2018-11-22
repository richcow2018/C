/****************************************************************************/
/*																			*/
/*	ưŪ�����ƥ��ѹ�														*/
/*																			*/
/* Created:																	*/
/*	95.05.30 K.Kubota ST2707: ICP Process cooperation release				*/
/*																			*/
/* Update history:															*/
/*	95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange							*/
/*	95.07.05 K.Kubota ST2909: MMCCHN 128 --> 256							*/
/*																			*/
/****************************************************************************/

										/* ###ST2707 Start					*/
#define TYPICP			"82"			/* ICP�̎ߎێ��ގ׎Ѽ���					*/

/****************************************/
/* ��ICP�̎ߎێ�����ʸ(MIA����������)		*/
/****************************************/
/****************************************/
/* ������������ 12B					*/
/****************************************/
typedef struct
{
	long				ifcode;			/* ���ݎ��̎����������Ď�						*/
#define MMIFICP1		0x79A00041		/* ��¾��������׵�����(ICP)		*/
#define MMIFICP3		0x79A00042		/* ��¾��ֲ���׵�����(ICP)		*/
	long				reqid;			/* �׵ἱ�̻�						*/
	short				CHn;			/* �������������ͭ����				*/
	char				dmy1[2];		/* ͽ��								*/
}						DYIC_KYO;

/************************************/
/* ������������� 4B				*/
/************************************/
typedef struct
{
	unsigned char		puno;			/* (c)pu�ֹ�						*/
	unsigned char		chno;			/* �����Ȏ��ֹ�							*/
	unsigned char		target;			/* �ѹ��о�							*/
										/*  0x01...ʪ������					*/
										/*  0x02...��������					*/
										/*  0x03...�����ʎߎ�					*/
	unsigned char		type;			/* ��������							*/
										/*  0x01...ű��						*/
										/*  0x02...����						*/
										/*  0x03...°���ѹ�					*/
}						DYIC_KO;

/****************************************/
/* �׵���ʸ���Τι�¤ 88+12+4*128=612B	*/
/****************************************/
typedef struct
{
	MCMIKYO				mia;			/* MIA������						*/
#define MMMKICP			0x030E0000		/* mmd <---> mia [ICP]				*/
	DYIC_KYO			icpkyo;			/* ������������					*/
#define MMCCHN			256				/* ������������ ###ST2909			*/
	DYIC_KO				icpko[MMCCHN];	/* �������������					*/
}						ICPMSG;
#define MMICPSIZ		sizeof(ICPMSG)

/************************************/
/* ������ʸ�ι�¤ 16B				*/
/************************************/
typedef struct
{
	long				ifcode;			/* ���ݎ��̎����������Ď�						*/
#define MMIFICP2		0x60002000		/* ��¾��������������(ICP)		*/ 
#define MMIFICP4		0x60002001		/* ��¾��ֲ����������(ICP)		*/ 
	long				reqid;			/* �׵ἱ�̻�						*/
	long				result;			/* ��̎����Ď�							*/
	long				detail;			/* �َܺ����Ď�							*/
}						DYIC_RSP;
										/* ###ST2707 End					*/