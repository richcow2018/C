/****************************************************************************/
/*																			*/
/*	ưŪ�����ƥ��ѹ�				����:94/12/07							*/
/*																			*/
/* Update history:															*/
/*	95.05.28 K.Kubota ST2637: Process cooperation fail						*/
/*	95.06.24 K.Kubota ST2707: mm_dyrec.h rearrange							*/
/*	03.04.16 ���ץ饤���䲼 MD001:Linux�ܿ���ȼ������						*/
/*								  �̿��������HCP-S[V7]�ɲ�					*/
/*																			*/
/****************************************************************************/

										/* ###ST2637 Start					*/
#define TYPFNA			"94"			/* FNA�̎ߎێ��ގ׎Ѽ���					*/
#define TFAH_MHG		0x09			/* FNA���̿��������				*/
#define TFAH_DCS		0x26			/* FNA���̿�������� HCP-S[V7] MD001*/

/****************************************/
/* FNA����ʸ��������¤�� 32B			*/
/****************************************/
typedef struct
{
	char				mkcode[4];		/* ��MK�����Ď� = 0x01010000			*/
#define MMMKFNA			0x01010000		/* mmd <---> mhg [HCP-S(V4)]		*/
	char				aparea[4];		/* AP��Ȱ�							*/
	long				mbox0;			/* ��ȯ�����Ҏ��َΎގ��������̻�			*/
	long				mbox1;			/* ��������Ҏ��َΎގ��������̻�			*/
	char				rsltmode;		/* ������������Ύӎ��Ď�				*/
	char				rsv[3];			/* ͽ��								*/
	long				crctmbox;		/* ������������Ҏ��َΎގ�����ID			*/
	long				failmbox;		/* ���۾�������Ҏ��َΎގ�����ID			*/
	short				srcwsno;		/* ��ȯ����WS�ֹ� = 0x0000			*/
	char				sndpuno;		/* ��������PU�ֹ� = tefxpuno		*/
	char				sndluno;		/* ��������LU�ֹ� = 0x01			*/
										/* (ͭ���ʤ�ʤ�Ǥ⤤��)			*/
										/* (FNA�β���Τ���̤���)			*/
}						FNACIA;			/* Communication Interface Area		*/

/****************************************/
/* LU��������� 2B						*/
/****************************************/
typedef	struct
{
	char				luno;			/* LU�ֹ�							*/
	char				lutype;			/* LU����							*/
}						LUINFO;

/****************************************/
/* LU�������� 4B						*/
/****************************************/
typedef	struct
{
	unsigned char		cmdcd;			/* ���ώݎĎގ����Ď�						*/
#define MMCCFNA1		0xF1		/* ��¾�����������׵᡿��������(FNA)	*/
#define MMCCFNA2		0xF2		/* ��¾��ֽ�λ�����׵᡿��������(FNA)	*/
	char				rsv;			/* ͽ��								*/
	short				entnum;			/* ���ݎĎؿ� (efective num. of LUINFO)	*/
}						LUCOM;

/****************************************/
/* ��ʸ���Τι�¤ 32+4+2*N = 548B		*/
/*  (�׵�/�����Ȥ�Ʊ�칽¤)				*/
/****************************************/
typedef	struct
{
	FNACIA				cia;			/* ���̰�							*/
	LUCOM				lucom;			/* ���Ѽ԰�: ������					*/
#define MAXLUNUM		256				/* ����LU�����						*/
	LUINFO				luinfo[MAXLUNUM]; /* ���Ѽ԰�: ������				*/
}						FNAMSG;
										/* ###ST2637 End					*/
