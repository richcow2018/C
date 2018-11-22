/****************************************************************************/
/*																			*/
/*	ưŪ�����ƥ��ѹ��󶡥����ӥ���������									*/
/*																			*/
/*	����:94/09/16															*/
/*	����:																	*/
/*		95.06.24 K.Kubota ST2707: ��ICP�̎ߎێ�����Ĵư��						*/
/*		95.06.27 K.Kubota ST2706: ��EDP/DCP��Ĵư��							*/
/*		95.07.10 K.Kubota ST2910: activate CheckList						*/
/*		95.07.14 K.Kubota SSCY0073: TNTC�б�								*/
/*	95.08.28 K.Kubota SSCY0100: tfacrxtn�б�								*/
/*	95.08.29 K.Kubota SSCY0095: TFAXʬ��Îގ���Ĺ�б�							*/
/*	95.09.06 K.Kubota SSCY0061: raw mode for mm_diff,						*/
/*								all delete mode for mm_dyrc()				*/
/*	95.09.19 K.Kubota ST3309=AT1084: tel/ISDNno	[10]-->[16]					*/
/*	95.10.06 K.Kubota SSCY0118: ��OSP��Ĵư��								*/
/*	95.12.13 K.Kubota ST3865: add MMELSW									*/
/*	95.12.19 K.Kubota ST3859=AT2081; retry ossenms()						*/
/*	96.02.29 K.Kubota ST4050; �������ǡ���.�ۥ�����������.lnno��ͽ���Ȥ���	*/
/*	96.03.28 K.Kubota SSCY0153: for BTURIREC rep yobi2_2 to apno			*/
/*	96.04.04 K.Kubota SSCY0157: mm_rvrs send request to mme000 on alter ACE	*/
/*	96.05.26 K.Kubota ST4384: on mme's abort, tell MMEPABT to AP			*/
/*	98.11.30 K.Yamagu SPCY0134: mm_rvdf���������ӥ��������Ϣ������ɲ�		*/
/*	03.03.06 ���ץ饤���䲼 MD001: Linux�ܿ���ȼ������						*/
/*							ü�����������쥳���ɤ������������롼���ֹ��ɲ�	*/
/*							�Ρ��ɴ��̿��ѥ��쥳���ɤ�NS����ƥ������ֹ��ɲ�*/
/*	03.08.08 ���ץ饤����¼ TBCS0265:�㳲�б�								*/
/*							�����⥸�塼��ɣ��ɲ�							*/
/****************************************************************************/

										/* ###ST2707 start					*/
/********************************/
/* ��ǽ�ՎƎ���ID					*/
/********************************/
#define MMMODULE1		0x01			/* �¹Դ���: mmd_2000()				*/

/********************************/
/* �ӎ��ގ�����ID [MMD]				*/
/********************************/
#define MM_DYRC			0x79FFDF00
#define MMD_0GEN		0x79FFD001
#define MMD_IRBI		0x79FFD002
#define MMD_SC00		0x79FFD003
#define MMD_SC10		0x79FFD004
#define MMD_0000		0x79FFD000
#define MMD_0700		0x79FFD070
#define MMD_2000		0x79FFD200
#define MMD_2100		0x79FFD210
#define MMD_2200		0x79FFD220
#define MMD_2210		0x79FFD221
#define MMD_2300		0x79FFD230
#define MMD_2400		0x79FFD240
#define MMD_2500		0x79FFD250
#define MMD_3000		0x79FFD300
#define MMD_3100		0x79FFD310
#define MMD_3200		0x79FFD320
#define MMD_3300		0x79FFD330
#define MMD_3400		0x79FFD340
#define MMD_3500		0x79FFD350
#define MMD_3600		0x79FFD360
#define MMD_3700		0x79FFD370
#define MMD_3800		0x79FFD380
#define MMD_3900		0x79FFD390
#define MMD_3A00		0x79FFD3A0
#define MMD_4000		0x79FFD400
#define MMD_4100		0x79FFD410
#define MMD_41A0		0x79FFD41A
#define MMD_41U0		0x79FFD41B
#define MMD_41D0		0x79FFD41D
#define MMD_4200		0x79FFD420
#define MMD_42A0		0x79FFD42A
#define MMD_42U0		0x79FFD42B
#define MMD_42D0		0x79FFD42D
#define MMD_4300		0x79FFD430
#define MMD_43A0		0x79FFD43A
#define MMD_43U0		0x79FFD43B
#define MMD_43D0		0x79FFD43D
#define MMD_4400		0x79FFD440
#define MMD_44A0		0x79FFD44A
#define MMD_44U0		0x79FFD44B
#define MMD_44D0		0x79FFD44D
#define MMD_4700		0x79FFD470
#define MMD_47A0		0x79FFD47A
#define MMD_47U0		0x79FFD47B
#define MMD_47D0		0x79FFD47D
#define MMD_4800		0x79FFD480
#define MMD_48A0		0x79FFD48A
#define MMD_48U0		0x79FFD48B
#define MMD_48D0		0x79FFD48D
#define MMD_4900		0x79FFD490
#define MMD_49A0		0x79FFD49A
#define MMD_49U0		0x79FFD49B
#define MMD_49D0		0x79FFD49D
#define MMD_4A00		0x79FFD4A0
#define MMD_4AA0		0x79FFD4AA
#define MMD_4AU0		0x79FFD4AB
#define MMD_4AD0		0x79FFD4AD
#define MMD_5000		0x79FFD500
#define MMD_5100		0x79FFD510
#define MMD_51A0		0x79FFD51A
#define MMD_51U0		0x79FFD51B
#define MMD_51D0		0x79FFD51D
#define MMD_6000		0x79FFD600
#define MMD_6100		0x79FFD610
#define MMD_61A0		0x79FFD61A
#define MMD_61U0		0x79FFD61B
#define MMD_61D0		0x79FFD61D
#define MMD_7000		0x79FFD700
#define MMD_7110		0x79FFD711
#define MMD_7120		0x79FFD712
#define MMD_7130		0x79FFD713
#define MMD_7140		0x79FFD714
#define MMD_7150		0x79FFD715
#define MMD_7210		0x79FFD721
#define MMD_7220		0x79FFD722
#define MMD_7230		0x79FFD723
#define MMD_7240		0x79FFD724
#define MMD_7250		0x79FFD725
#define MMD_7310		0x79FFD731
#define MMD_7320		0x79FFD732
#define MMD_7330		0x79FFD733			/* ###SSCY0095				*/
#define MMD_7340		0x79FFD734
#define MMD_7350		0x79FFD735
#define MMD_7410		0x79FFD741
#define MMD_7420		0x79FFD742
#define MMD_7430		0x79FFD743
#define MMD_7440		0x79FFD744
#define MMD_7450		0x79FFD745
#define MMD_7510		0x79FFD751
#define MMD_7520		0x79FFD752
#define MMD_7540		0x79FFD754
#define MMD_7550		0x79FFD755
#define MMD_75F0		0x79FFD75F
#define MMD_7610		0x79FFD761
#define MMD_7620		0x79FFD762
#define MMD_7630		0x79FFD763
#define MMD_7640		0x79FFD764
#define MMD_7650		0x79FFD765
#define MMD_7710		0x79FFD771
#define MMD_7720		0x79FFD772
#define MMD_7730		0x79FFD773
#define MMD_7740		0x79FFD774
#define MMD_7750		0x79FFD775
#define MMD_7810		0x79FFD781
#define MMD_7820		0x79FFD782
#define MMD_7840		0x79FFD784
#define MMD_7850		0x79FFD785
#define MMD_7910		0x79FFD791
#define MMD_7920		0x79FFD792
#define MMD_7930		0x79FFD793
#define MMD_7940		0x79FFD794
#define MMD_7950		0x79FFD795
#define MMD_7A10		0x79FFD7A1
#define MMD_7A20		0x79FFD7A2
#define MMD_7A30		0x79FFD7A3
#define MMD_7A40		0x79FFD7A4
#define MMD_7A50		0x79FFD7A5
#define MMD_7B10		0x79FFD7B1
#define MMD_7B20		0x79FFD7B2
#define MMD_7B30		0x79FFD7B3
#define MMD_7B40		0x79FFD7B4
#define MMD_7B50		0x79FFD7B5
#define MMD_7C10		0x79FFD7C1		/* ###SSCY0073 start				*/
#define MMD_7C20		0x79FFD7C2
#define MMD_7C30		0x79FFD7C3
#define MMD_7C40		0x79FFD7C4
#define MMD_7C50		0x79FFD7C5		/* ###SSCY0073 end					*/
#define MMD_8000		0x79FFD800
#define MMD_8110		0x79FFD811
#define MMD_8120		0x79FFD812
#define MMD_8140		0x79FFD814
#define MMD_8150		0x79FFD815
#define MMD_8210		0x79FFD821
#define MMD_8220		0x79FFD822
#define MMD_8230		0x79FFD823
#define MMD_8240		0x79FFD824
#define MMD_8250		0x79FFD825
#define MMD_8310		0x79FFD831
#define MMD_8320		0x79FFD832
#define MMD_8330		0x79FFD833
#define MMD_8340		0x79FFD834
#define MMD_8350		0x79FFD835
#define MMD_8910		0x79FFD891
#define MMD_8A10		0x79FFD8A1		/* ###SSCY0100						*/
#define MMD_9100		0x79FFD910
#define MMD_9200		0x79FFD920
#define MMD_9310		0x79FFD931
#define MMD_9400		0x79FFD940
#define MMD_9600		0x79FFD960
#define MMD_9700		0x79FFD970
#define MMD_9800		0x79FFD980
#define MMD_9999		0x79FFD999
#define MMD_7E10		0x79FFD7e1
#define MMD_7E20		0x79FFD7e2
#define MMD_7E30		0x79FFD7e3
#define MMD_7E40		0x79FFD7e4
#define MMD_7D10		0x79FFD7d1		/* TBCS0265							*/
#define MMD_7D12		0x79FFD7d2		/* TBCS0265							*/

/*********************************/
/*	�⥸�塼��ɣġʶ��̵�ǽ��	 */
/*********************************/
#define MMD_Y200		0x79FFC200
#define MMD_Y210		0x79FFC210
#define MMD_Y500		0x79FFC500
#define MMD_Y911		0x79FFC911
#define MMD_Y912		0x79FFC912
#define MMD_Y913		0x79FFC913
#define MMD_Y914		0x79FFC914
#define MMD_Y915		0x79FFC915
#define MMD_Y916		0x79FFC916
#define MMD_Y917		0x79FFC917
#define MMD_Y918		0x79FFC918

/********************************/
/* MK�����Ď�						*/
/********************************/
#define MMMK_CODE		0x030E0000		/* mm_dyrc <---> mmd/mme			*/

/********************************/
/* ���ݎ��̎����������Ď�					*/
/********************************/
#define MMIFRVRS		0x79A10002		/* mm_rvrs <---> mme				*/
#define MMIFTBL1		0x79A00001		/* �Î��̎ގٹ�����������				*/
#define MMIFTBL2		0x79A00002		/* �Î��̎ގٹ�����λ����				*/
#define MMIFSPU1		0x79A00011		/* ¾LM�Î��̎ގٹ�����������(PU1.mmd)	*/
#define MMIFRPU1		0x79A00012		/* ¾LM�Î��̎ގٹ�����λ����(PU1.mmd)	*/

/********************************/
/* �̎ߎێ��ގ׎Ѽ���					*/
/********************************/
#define DYRCTYP			"F3"			/* ưŪ�����Îѹ����ѹ��̎ߎێ���			*/
#define RVRSTYP			"F4"			/* ���������Îގ��������̎ߎێ���			*/

/********************************/
/* ���Ύގ����װ�					*/
/********************************/
#define MMABTLGC		0x01000000		/* �������顼						*/
#define MMABTPRM		0x04000000		/* �ѥ�᡼�����顼					*/
#define MMABTT_O		0x08000000		/* ��ʡ�Ʊ�����顼					*/
#define MMABTHRD		0x0A000000		/* �ϡ��ɥ��顼						*/
#define MMABTMEM		0x0D000000		/* ����­���顼					*/
#define MMABTETC		0x0E000000		/* ����¾							*/

/********************************/
/* �����ƻ������ [ñ��: �Ў���]		*/
/********************************/
#ifndef MMEWAITTIME
#define MMEWAITTIME		200000			/* OSRCVMSP���Ԥ�����(ñ��ms)		*/
										/*   0: No Wait						*/
#endif
#ifndef MMDWAITTIME
										/* ###SSCY0061 below				*/
#define MMDWAITTIME		1200000L		/* OSRCVMSP���Ԥ�����(ñ��ms)		*/
										/*   0: No Wait						*/
										/*  -1: ̵�����Ԥ�					*/
		/* ͽ����ưŪ�ơ��֥��ѹ����Τ�ͭ�������ѷϤ�̵����̵�����Ԥ���	*/
										/* ###SSCY0061 above				*/
#endif
										/* ###ST3859 start					*/
/************************************/
/* ͽ���������ƻ�Ԏ����� [ñ��: ��]	*/
/************************************/
#ifndef MMDRTIME
#define MMDRTIME		10				/* osdelay()�ΎՎƎ��Ŀ�				*/
#endif
#ifndef MMDRUNIT
#define MMDRUNIT		2				/* osdelay()�ΎՎƎ���ñ�� [��]			*/
#endif
#ifndef MMDRCNT
#define MMDRCNT			10				/* �ƻ�Բ��						*/
#endif
										/* ###ST3859 end					*/
										/* ###SSCY0157 start				*/
#ifndef MMERTIME
#define MMERTIME		10				/* osdelay()�ΎՎƎ��Ŀ�				*/
#endif
#ifndef MMERUNIT
#define MMERUNIT		2				/* osdelay()�ΎՎƎ���ñ�� [��]			*/
#endif
#ifndef MMERCNT
#define MMERCNT			10				/* �ƻ�Բ��						*/
#endif
										/* ###SSCY0157 end					*/
/********************************/
/* �ֵ���						*/
/********************************/
/* ����							*/
#define MMNORMAL		0L				/* ���ｪλ							*/
#define MMNOMEM			-81L			/* �Ҏӎ�(�̎ߎ��َʎގ��̎�)��­				*/
#define MMEOSERR		-82L			/* TRADE�����Îю����َ��׎�					*/
#define MMTIMEOT		-83L			/* �����ƻ�����ڤ�					*/
#define MMFLNO			-84L			/* �ʎߎ�̾1�ʤ�						*/
#define MMFLNULL		-85L			/* �ʎߎ�̾1ʸ�����Ĺ					*/
#define MMLGNO			-86L			/* �ʎߎ�̾2�ʤ�						*/
#define MMLGNULL		-87L			/* �ʎߎ�̾1ʸ�����Ĺ					*/

/* ������						*/
#define MMEERCARD		-1L				/* �����Ď޾���̎�����̾�۾�				*/
#define MMEERREGU		-2L				/* �������Îގ����̎�����̾�۾�				*/
#define MMEERLIST		-3L				/* �����Ď޾�����������؎��Ď̎�����̾�۾�		*/
#define MMEERREAD		-4L				/* �����Ď޾���̎��������ώ��׎�				*/
#define MMEERWRIT		-5L				/* �������Îގ����̎�����̤����				*/
#define MMENOLIST		-6L				/* �����Ď޾�����������؎��Ď̎�����̤����		*/
#define MMENOMEM		-7L				/* �Ҏӎ���­							*/
#define MMENMKPRC		-8L				/* �̎ߎێ�������̾�����۾�				*/
#define MMEERRCRD		-11L			/* �����Ď޾���۾� ###ST2910			*/

/* ��������						*/
#define MMEERRVRS		-1L				/* ���������Îގ����̎�����̾�۾�			*/
#define MMENORVRS		-2L				/* ���������Îގ����̎�����̤����			*/
#define MMENOPRNM		-3L				/* ���������̎ߎێ�����TPCT��̤��Ͽ		*/
										/* ###SSCY0157 above				*/
#define MMETBLERR		-4L				/* SMP�Î��̎ގ��������׎�					*/
										/* ###SSCY0157 start				*/
#define MMENODENM		-5L				/* ���ѡ�ͽ���϶�ʬ����				*/
#define MMEENVDAT		-7L				/* ͽ���������ֹ��������			*/
										/* ###SSCY0157 end					*/
#define MMELSW			-51L			/* BU���������� ###ST3865			*/
#define MMEPABT			-101L			/* MME�ץ��������ܡ��Ȥ���		*/
										/* ###ST4384 above					*/

/* ��ʬ���						*/
#define MMEDWORN		-1L				/* ����դ����ｪλ					*/
#define MMEDERREGU		-2L				/* �������Îގ����̎�����̾�۾�				*/
#define MMEDERRVRS		-3L				/* ���������Îގ����̎�����̾�۾�			*/
#define MMEDERDIFF		-4L				/* �������Îގ���(��ʬ)�̎�����̾�۾�		*/
#define MMEDERRGRD		-5L				/* �������Îގ����̎��������ώ��׎�			*/
#define MMEDERRVRD		-6L				/* ���������Îގ����̎��������ώ��׎�			*/
#define MMEDERWRIT		-7L				/* �������Îގ���(��ʬ)�̎����ٽ��ώ��׎�		*/
#define MMEDERPROC		-8L				/* ��ʬ����IO�̎ߎێ�����¤���ΰ���­	*/
#define MMEDNOMEM		-9L				/* �Ҏӎ���­							*/
#define MMEDERNODE		-10L			/* �Ɏ��Ď޴��̿��ʎߎ���ʬ�����ֵѰ���­	*/
#define MMEJINODE		-11L			/* ���Ɏ��Ď��ѹ��Բ� ###SSCY0073		*/
#define MMDIMDERR		-12L			/* mode error ###SSCY0061			*/
#define MMEDERTBL		-13L			/* SMP����ơ��֥�۾�	SPCY0134*/
#define MMEDERNREC		-14L			/* �������쥳���ɤ˳����ʤ�	SPCY0134*/
#define MMEDERBKUP		-15L			/* �Хå����å����������� SPCY0134*/
#define MMEDERFNA		-16L			/* �ۥ�����³���������� 	SPCY0134*/
#define MMEDERFTAM		-17L			/* FTAM�̿�������������� SPCY0134*/

/* �ơ��֥��ѹ�					*/
#define MMDNODENM		-1L				/* ���ѡ�ͽ���϶�ʬ����				*/
#define MMDNOPRNM		-2L				/* ưŪ�����Î��ѹ��̎ߎێ�����TPCT��̤��Ͽ	*/
#define MMDENVDAT		-3L				/* ͽ���������ֹ��������			*/
#define MMDEXECUT		-4L				/* �����Îѹ����ѹ���					*/
#define MMDUDERR		-5L				/* ��¾������꼺��					*/
#define MMDYMDERR		-6L				/* mode error ###SSCY0061			*/
#define MMDRECKBN		-19L			/* ǧ����ǽ�ڎ����ĎގÎގ��������������׎�			*/
#define MMDBUTSURI		-20L			/* ʪ�������ڎ����ĎގÎގ��������������׎�			*/
#define MMDGWRONRI		-21L			/* GWü�����������ڎ����ĎގÎގ��������������׎�	*/
#define MMDLANRNRI		-22L			/* LANü�����������ڎ����ĎގÎގ��������������׎�	*/
#define MMDTANPASS		-23L			/* ü���ʎߎ��ڎ����ĎގÎގ��������������׎�			*/
#define MMDHOSTRON		-24L			/* �Ύ������������ڎ����ĎގÎގ��������������׎�		*/
#define MMDHOSTPAS		-25L			/* �Ύ��Ďʎߎ�(FNA)�ڎ����ĎގÎގ��������������׎�		*/
#define MMDPROCESS		-26L			/* �̎ߎێ����ڎ����ĎގÎގ��������������׎�			*/
#define MMDRENKETU		-27L			/* �̎ߎێ���Ϣ��ڎ����ĎގÎގ��������������׎�		*/
#define MMNODEPORT		-28L			/* �Ɏ��Ď޴��̿��ڎ����ĎގÎގ��������������׎�		*/
#define MMFTAMPATH		-29L			/* FTAM�̿��ʎߎ��ڎ����ĎގÎގ��������������׎�		*/


/****************************************/
/* �Î��̎ގ��ѹ�������ʸ[mm_dyrc ---> mmd]	*/
/****************************************/
/* MIA���Ѽ԰�				*/
typedef struct
{
	long				ifcode;			/* ���ݎ��̎����������Ď�						*/
	long				reqid;			/* �׵ἱ�̻�						*/
	long				pid;			/* �׵���ʸȯ�Ԏ̎ߎێ������̻�			*/
	long				mbox0;			/* pu0�Ҏ��َΎގ��������̻�				*/
	long				mbox1;			/* pu1�Ҏ��َΎގ��������̻�				*/
	char				prname[8];		/* pu1�̎ߎێ�������̾					*/
	long				code;			/* ��λ�����Ď�							*/
	long				faildet;		/* �۾�ܺ�							*/
	char				filename[64];	/* �������Îގ���(��ʬ)�̎�����̾			*/
	char				logfile[64];	/* �Î��̎ގٹ�������ێ��ގ̎�����̾			*/
										/* ###SSCY0061 start				*/
	char				Node;			/* �϶�ʬ							*/
										/*  0x01...���ѷ�					*/
										/*  0x02...ͽ����					*/
	char				Mode;			/* �����ӎ��Ď�							*/
										/*  0x00...�̾�ӎ��Ď�					*/
										/*  0x01...��ű��ӎ��Ď�				*/
	/* �۾���������ղþ���(^_^;)		   ###SSCY0118 start				*/
	short				ErrRecN;		/* �۾��������ڎ����Ď�����				*/
	char				XBpnm[8];		/* ��¾������꼺�Ԏ̎ߎێ�������̾		*/
	long				FailCode;		/* ��¾������꼺�Ը��������Ď�			*/
	char				dmy1[76];		/* ͽ��	###SSCY0061	end				*/
										/* ###SSCY0118 end					*/
}						DYREC_DC;
typedef DYREC_DC		*PDYREC_DC;

/* MIA��ʸ�����ι�¤		*/
typedef struct
{
	MCMIKYO				set1;			/* MIA���̰�						*/
	DYREC_DC			set2;			/* MIA���Ѽ԰�						*/
}						SET_AREA;

/****************************************/
/* ��������������ʸ[mm_rvrs ---> mme]	*/
/****************************************/
/* MIA���Ѽ԰�				*/
typedef struct
{
	long				ifcode;			/* ���ݎ��̎����������Ď�						*/
	long				pid;			/* �׵���ʸȯ�Ԏ̎ߎێ������̻�			*/
	long				code;			/* ��λ�����Ď�							*/
	long				faildet;		/* �۾�ܺ�							*/
	char				filename[64];	/* 1.�������Îގ���(��ʬ)�̎�����̾			*/
										/* 2.���������Îގ����̎�����̾				*/
	char				logfile[64];	/* 1.�Î��̎ގٹ�������ێ��ގ̎�����̾			*/
										/* 2.ͽ��							*/
	char				dmy1[112];		/* ͽ��								*/
}						RVRS_DC;
typedef RVRS_DC			*PRVRS_DC;

/* MIA��ʸ�����ι�¤		*/
typedef struct
{
	MCMIKYO				set1;			/* MIA���̰�						*/
	RVRS_DC				set2;			/* MIA���Ѽ԰�						*/
}						SET_RAREA;

/************************************/
/* ��ʬ��Ў����ˎގ��������ֵѾ���ι�¤	*/
/************************************/
/* ��ʬ����IO�̎ߎێ�������				*/
typedef struct
{
	long				allen;			/* �����ΰ莻������(���ѼԻ������)		*/
	long				iosu;			/* ������ͭ���Ŀ��ֵѰ�				*/
}						IOPROC;			/* ������							*/

typedef struct
{
	char				prnm[8];		/* IO�̎ߎێ����Ύ̎ߎێ�������̾				*/
	unsigned short		difsts;			/* ��ʬ����							*/
										/*  0x03...����						*/
										/*  0x02...°���ѹ�					*/
										/*  0x01...ű��						*/
	short				yobi;
}						PROCNM;			/* ������							*/

/********************************/
/* �������ڎ����Ďޤ�ñ�̾���¤	*/
/********************************/
/* ������						*/
typedef struct com_rec
{
	unsigned char		rec_kbn;		/* �쥳���ɼ���						*/
										/*  0x10:ʪ������					*/
										/*  0x20:GWü����������				*/
										/*  0x30:LANü����������			*/
										/*  0x40:ü���ʎߎ�					*/
										/*  0x51:�Ύ�����������(FNA)			*/
										/*  0x61:�Ύ��Ďʎߎ�(FNA)				*/
										/*  0x70:�̎ߎێ���						*/
										/*  0x80:�ʎߎ�Ϣ��					*/
										/*  0x90:�Ɏ��Ď޴��̿��ʎߎ�				*/
										/*  0xA0:FTAM_SMP�̿��ʎߎ�			*/
	char				syor_kbn;		/* ������ʬ							*/
#define ZOUSETU			0x03			/*  ����							*/
#define HENKOU			0x02			/*  °���ѹ�						*/
#define TEKKYO			0x01			/*  ű��							*/
										/* ###SSCY0061 start				*/
	char				xcf;			/* ưŪ�оݳ��񸻼���ɽ��			*/
										/*  0x00...���Ƥ��Ƥ��ʤ�			*/
										/*  0x01...���Ƥ��Ƥ���				*/
	/* ���������ǡ�����ͭ���Ǥ��ꡢ�������������ꤷ����ʬ��Ф����Ȥ��롣	*/
	/* �ʲ��ξ���������ʪ�������������������ؤ����ꤵ��롣				*/
	/*  (1). ưŪ�оݳ��ץ�����Ϣ�뤹�������ѥ�����Ƥ������������ޤ���	*/
	/*		 ʪ��������														*/
	/*  (2). �嵭(1)��������������Ƥ���ʪ��������							*/
	/*  (3). �ƣΣ��ʳ��Υۥ���������������Ƥ��Ƥ����.����ʪ��������		*/
	/*		 (�ۥ������������ϣ�.����������ưŪ�о�)						*/
	/* ����ɽ������Ū�ϡ����ƴ郎���Ѱդ�ű��Ƚ�ꤵ���Τ��ɤ����Ȥˤ��롣	*/
	/* ưŪ�оݳ��񸻤���Ƥ��Ƥ�����ƴ��ű��Ǥ��ʤ���������������ߤ�	*/
	/* �Ǥ��ʤ��������ǡ������ɽ�����ղä��Ƶ�����������ΤǤ��롣		*/
	/* ���ƴ���󤬥����ɤ˺ܤäƤ��ʤ����ű����ɤ����ܤäƤ����			*/
	/* �껦������������ߤ��ɤ��ΤǤ��롣									*/
	/* (����μ��ƴ�ϣ����⡼�ɤξ��Ǥ��껦������)					*/
	char				rsv;			/* ͽ��								*/
										/* ###SSCY0061 end					*/
}						COMREC;
typedef COMREC			*PCOMREC;

/* ʪ������ [104B]				*/
typedef struct buturi_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	char				kbst;			/* �������Î�����						*/
										/*  b4: �؎ӎ��Ĳ���ɽ��				*/
										/*		 0:���ݎʎ���					*/
										/*		 1:�؎ӎ���						*/
										/*  b0: ����/BU����					*/
										/*		 0:����						*/
										/*		 1:BU						*/
										/* ###ST3309 below					*/
	unsigned char		teln[16];		/* (���ѤΤ�)�����������ֲ����ֹ�	*/
										/*	[�����ֹ�/ISDN�ֹ�]				*/
	char				tlsu;			/* telnͭ�����						*/
	unsigned char		cld1[21];		/* (telnȯ�ƻ�)�忮¦���̎ގ��Ďގڎ�		*/
										/* ###ST3309 below					*/
	unsigned char		tel2[16];		/* (���ѤΤ�)�����������ֲ����ֹ�	*/
										/*	[�����ֹ�/ISDN�ֹ�]				*/
	char				tls2;			/* tel2ͭ�����						*/
	unsigned char		cld2[21];		/* (tel2ȯ�ƻ�)�忮¦���̎ގ��Ďގڎ�		*/
	unsigned char		forFTAM;		/* FTAM���ю̎׎���	###SSCY0100 start	*/
										/*  0x01...FTAM���Ѥǻ��Ѥ���		*/
										/*		   (=tfacrxtn��ư����ؼ�)	*/
										/*  0x00...FTAM���Ѥǻ��Ѥ��ʤ�		*/
										/* ###SSCY0100 end					*/
	short				xlno;			/* IO�����������ݎĎؿ�					*/
	short				hlno;			/* �Ύ��������������ݎĎؿ�				*/
	short				fapn;			/* IO�����ʎߎ����ݎĎؿ�					*/
	char				apno;      		/* AP.puno ###SSCY0153				*/
	char				prtc;			/* ������TRADE��������				*/
										/*  0x68:X.25						*/
										/*  0x41:4W							*/
										/*  0x42:HDLC�َ��̎�					*/
										/*  0x5B:Q.931 [ISDN_D]				*/
										/*  0x6C:TCP/IP						*/
	char				netw;			/* ��������							*/
										/*  0x00:����ľ�̲���				*/
										/*  0x01:������						*/
										/*  0x10:ISDN-Dch					*/
										/*  0x11:ISDN-B1ch					*/
										/*  0x12:ISDN-B2ch					*/
	char				bulp;			/* (����)���������BU�����̎ߎ���ID		*/
										/* (BU  )��BU������°�̎ߎ���ID			*/
	char				yobi2_3[12];	/* ͽ�� ###ST3309					*/
}						BTURIREC;
typedef BTURIREC		*PBTURIREC;

/* GWü���������� [104B]		*/
typedef struct gate_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	short				loca_lino;		/* ���������ֹ�						*/
	char				yobi3_1[2];		/* ͽ��								*/
	unsigned char		dadl;			/* ��³��GW��DTE���Ďގڎ����			*/
	char				yobi3_2[3];		/* ͽ��								*/
	unsigned char		dadr[8];		/* ��³��GW��DTE���Ďގڎ�				*/
	unsigned char		cxal;			/* ȯ���Ďގڎ���ĥ���					*/
	char				yobi3_3[3];		/* ͽ��								*/
	unsigned char		cxad[20];		/* ȯ���Ďގڎ���ĥ(��NSAP���Ďގڎ�)			*/
	unsigned char		rxal;			/* �厱�Ďގڎ���ĥ���					*/
	char				yobi3_4[3];		/* ͽ��								*/
	unsigned char		rxad[20];		/* �厱�Ďގڎ���ĥ(GW��NSAP���Ďގڎ�)		*/
	unsigned char		clas;			/* ��ю��׎�(GW�����̎ߎێĎ��ټ���)		*/
	unsigned char		gwln;			/* ����ü�������ֹ�					*/
										/*	(GW�����Ў����Ȏ��ֹ�)				*/
	char				yobi3_5[2];		/* ͽ��								*/
	long				dsta;			/* �����ü�����Ďގڎ�					*/
										/*	(�����Ȏ������������ֹ�:�����َՎ����ގÎގ���)*/
	unsigned long		sopt;			/* Ŭ�ю����Îю��̎ߎ�����(APǤ����)			*/
										/* ###SSCY0095 start				*/
	long				maxd;			/* ����ʬ��Îގ���Ĺ					*/
	char				yobi3_6[20];	/* ͽ��								*/
										/* ###SSCY0095 end					*/
}						GATEREC;
typedef GATEREC			*PGATEREC;

/* LANü���������� [ 36B]		*/
typedef struct lan_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	short				loca_lino;		/* ���������ֹ�						*/
/*	char				yobi4_1[2];		/* ͽ��						MD001	*/
	short				group_no;		/* ���롼���ֹ�				MD001	*/
	unsigned long		loca;			/* ���ü���ێ����َ��Ďގڎ�				*/
										/* ###SSCY0095 start				*/
	long				maxd;			/* ����ʬ��Îގ���Ĺ					*/
	char				yobi4_2[20];	/* ͽ��								*/
										/* ###SSCY0095 end					*/

}						LANREC;
typedef LANREC			*PLANREC;

/* ü���ѥ� [44B]				*/
typedef struct wsps_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	char				psnm[8];		/* �����ѥ�����̾					*/
	char				iokd;			/* API���Î��ގ� (LOOP/4WIO/4WNTM)		*/
	char				yobi5_1[1];		/* ͽ��								*/
	short				dvno;			/* �����ֹ�[4W]/					*/
										/* ���������ʎߎ��������������ֹ�		*/
	short				phno;			/* �����ʎߎ��ֹ�						*/
										/*��(API���Î��ގ�=HDLC�َ��̎ߤΤ�)			*/
	char				soft;			/* ���̎ĵ���							*/
	char				prfx;			/* �̎ߎڎ̎�����							*/
										/*  (API���Î��ގ�=4WIO,4WNTM�Τ�)		*/
	char				yobi5_2[24];	/* ͽ��								*/
}						WSPSREC;
typedef WSPSREC			*PWSPSREC;

/* �Ύ��������������� [12B]		*/
typedef struct hstlc_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	short				lnno;			/* ͽ�� ###ST4050					*/
	short				llno;			/* ���������ֹ�						*/
	char				prot_kbn;		/* �̿��������						*/
	char				yobi6_1[3];		/* ͽ��								*/
}						HSTLCREC;
typedef HSTLCREC		*PHSTLCREC;

/* FNA�������� [100B]			*/
typedef struct fnalc_rec
{
	short				fna_puno;		/* FNA.PU�ֹ�						*/
	char				yobi7_1[2];		/* ͽ��								*/
	unsigned char		deln;			/* ���DTE���Ďގڎ����					*/
	unsigned char		hadl;			/* ȯ���Ďގڎ���ĥ���					*/
	unsigned char		cadl;			/* �厱�Ďގڎ���ĥ���					*/
	char				yobi7_2[1];		/* ͽ��								*/
	unsigned char		dead[8];		/* ���DTE���Ďގڎ�						*/
	unsigned char		haad[20];		/* ȯ���Ďގڎ���ĥ						*/
	unsigned char		caad[20];		/* �厱�Ďގڎ���ĥ						*/
	char				yobi7_3[24];	/* ͽ��								*/
}						FNALCREC;
typedef FNALCREC		*PFNALCREC;

/* FTAM�̿��ѥ� [104B]			*/
typedef struct
{
	unsigned short		lnno;			/* �����ֹ� (puno << 8 + chno)		*/
	unsigned short		dstl;			/* �̿�����̾��Ĺ��(�ʎގ��Ŀ�)			*/
	unsigned short		sapl;			/* ���¦FSAP-ID��Ĺ��(�ʎގ��Ŀ�)		*/
	unsigned short		radl;			/* ���¦DTE���Ďގڎ���Ĺ��(�ʎގ��Ŀ�)		*/
	unsigned char		awal;			/* ���¦��ĥ���Ďގڎ���Ĺ��(BCD)		*/
	unsigned char		rsv3[3];		/* ͽ��								*/
	unsigned char		dsid[16];		/* �̿�����̾						*/
	unsigned char		rsap[16];		/* ���¦FSAP-ID					*/
	unsigned char		radr[8];		/* ���¦DTE���Ďގڎ�					*/
	unsigned char		awad[20];		/* ���¦��ĥ���Ďގڎ�					*/
	unsigned char		rsv[64];		/* ͽ��								*/
}						FTAMREC;
typedef FTAMREC			*PFTAMREC;

/* �Ύ��������ʎߎ����� [8B]			*/
typedef struct hstps_rec
{
	short				puno;			/* ��������PU�ֹ�					*/
	short				chno;			/* ����CH�ֹ� [PU������]			*/
	short				loca_lino;		/* ���������ֹ�						*/
	char				prot_kbn;		/* �̿��������						*/
	char				yobi8_1[1];		/* ͽ��								*/
}						HSTPSREC;
typedef HSTPSREC		*PHSTPSREC;

/* FNA�����ʎߎ� [40B]				*/
typedef struct fnaps_rec
{
	char				lusb;			/* LU����[LU0/LU2/LU3]				*/
	char				ttyp;			/* ü�������̎�(ü����Ƴ�����Ύ��ļ�Ƴ��)	*/
	char				yobi9_1[2];		/* ͽ��								*/
	short				puno;			/* FNA.PU�ֹ�						*/
	short				luno;			/* FNA.LU�ֹ�						*/
	char				psnm[8];		/* �����ʎߎ����̻�					*/
	char				yobi8_9[24];	/* ͽ��								*/
}						FNAPSREC;
typedef FNAPSREC		*PFNAPSREC;

/* �̎ߎێ��� [72B]					*/
typedef struct proc_rec
{
	char				pnm[8];			/* �̎ߎێ�������̾						*/
	char				tpfn[16];		/* �̎ߎێ��ގ׎юʎߎ�̾						*/
	char				puno;			/* PU�ֹ�							*/
	char				kbn;			/* EDP/DCP��ʬ						*/
										/*  '0'...EDP						*/
										/*  '1'...DCP						*/
	char				yobi10_1[2];	/* ͽ��								*/
	char				tgrn[2];		/* ���ގَ��̎ߎ����Ď�						*/
	char				tsgn[2];		/* ���̎ގ��ގَ��̎ߎ����Ď�					*/
	unsigned char		grcd[12];		/* ���؎������Ď�							*/
										/*  �Ҏ��ގ������؎������Ď� [4]				*/
										/*  �ώ��Ŏ��؎������Ď�   [4]				*/
										/*  �ێ����َ��؎������Ď�  [4]				*/
	char				ndth;			/* NTC��ɽü��						*/
	char				sdth;			/* �ώ��Ŏ��؎���ɽü��					*/
	short				iokd;			/* �Ҏ��������ގ��ˎގ؎Î�(IO����)				*/
	char				yobi10_2[24];	/* ͽ��								*/
}						PROCREC;
typedef PROCREC			*PPROCREC;

/* �ʎߎ�Ϣ�� [52B]				*/
typedef struct coupl_rec
{
	char				pnm[8];			/* �̎ߎێ�������̾						*/
	short				wsno;			/* WS�ֹ�							*/
	char				wscl;			/* WS����(�����Î�Ǥ����)				*/
	char				yobi11_1[1];	/* ͽ��								*/
	char				tlphpsnm[8];	/* �Ύ��������ʎߎ�����̾					*/
	char				tlptpsnm[8];	/* ü�������ʎߎ�����̾				*/
	long				ssop[2];		/* Ŭ�ю����Îю��̎ߎ�����					*/
	char				yobi11_2[24];	/* ͽ��								*/
}						COUPLREC;
typedef COUPLREC		*PCOUPLREC;

/* �Ɏ��Ď��̿��ʎߎ� [48B]			*/
typedef struct
{
//	char				type;			/* �̿�����					MD001	*/
//										/*  0x00: SCSI				MD001	*/
//										/*  0x01: LAN 				MD001	*/
	unsigned char		netd;			/* �Ȏ��Ď܎�����ɽɽ��					*/
										/*  b0: �Ȏ��Ď܎�����ɽɽ��				*/
										/*   1...�Ȏ��Ď܎�����ɽ�Ǥ���			*/
										/*   0...�Ȏ��Ď܎�����ɽ�Ǥʤ�			*/
										/*  b1: ���Ɏ��Ď�ɽ��					*/
										/*   1...���Ɏ��ĎޤǤ���				*/
										/*   0...���Ɏ��ĎޤǤʤ�				*/
										/* b2-7: ���0						*/
	char				yobi12_1;		/* ͽ��						MD001	*/									
	short				nscn;			/* NS����ƥ������ֹ�		MD001	*/
	short				ndno;			/* ���Ɏ��Ď��ֹ�				MD001	*/
	char				yobi12_2[42];	/* ͽ��						MD001	*/

// MD001
//	char				yobi12_1[2];	/* ͽ��						MD001	*/
//
//	/* LAN�Τ�			*/
//	long				MYipad;			/* ���Ɏ��Ď�IP���Ďގڎ�					*/
//	short				MYapno;			/* ���Ɏ��Ď�ACTIVE���Ȏ������ݻ��юΎߎ����ֹ�	*/
//	short				MYlpno;			/* ���Ɏ��Ď�LISTEN���Ȏ������ݻ��юΎߎ����ֹ�	*/
//	short				ndno;			/* ���Ɏ��Ď��ֹ�						*/
//	char				yobi12_2[2];	/* ͽ��								*/
//	long				ipad;			/* ���Ɏ��Ď�IP���Ďގڎ�					*/
//	short				apno;			/* ���Ɏ��Ď�ACTIVE���Ȏ������ݻ��юΎߎ����ֹ�	*/
//	short				lpno;			/* ���Ɏ��Ď�LISTEN���Ȏ������ݻ��юΎߎ����ֹ�	*/
//
//	/* SCSI�Τ�			*/
//	char				ace1;			/* ���Ɏ��Ď�(���ѷ�)�����ֹ�			*/
//	char				ace2;			/* ���Ɏ��Ď�(ͽ����)�����ֹ�			*/
//	char				yobi12_9[22];	/* ͽ��								*/
}							NODEREC;
typedef	NODEREC				*PNODEREC;

/************************************/
/* �������ڎ����ĎޤΎڎ����Ď޹�¤			*/
/************************************/
#define RECMAXSIZ		256				/* �������ڎ����Ď��ɤ߹��߰莻������		*/
										/* (����ڎ����Ďގ������ްʾ�Ǥ��뤳��)	*/

/* ʪ������ [108B]					*/
typedef struct
{
	COMREC				x;
	BTURIREC			y;
}						REC10;
typedef REC10			*PREC10;

/* GWü���������� [108B]		*/
typedef struct
{
	COMREC				x;
	GATEREC				y;
}						REC20;
typedef REC20			*PREC20;

/* LANü���������� [40B]		*/
typedef struct
{
	COMREC				x;
	LANREC				y;
}						REC30;
typedef REC30			*PREC30;

/* ü���ʎߎ� [48B]				*/
typedef struct
{
	COMREC				x;
	WSPSREC				y;
}						REC40;
typedef REC40			*PREC40;

/* FNA�������� [96B]			*/
typedef struct
{
	COMREC				x;
	HSTLCREC			y;
	FNALCREC			z;
}						REC51;
typedef REC51			*PREC51;

/* FNA�����ʎߎ� [48B]				*/
typedef struct
{
	COMREC				x;
	HSTPSREC			y;
	FNAPSREC			z;
}						REC61;
typedef REC61			*PREC61;

/* �̎ߎێ��� [76B]					*/
typedef struct
{
	COMREC				x;
	PROCREC				y;
}						REC70;
typedef REC70			*PREC70;

/* �ʎߎ�Ϣ�� [56B]				*/
typedef struct
{
	COMREC				x;
	COUPLREC			y;
}						REC80;
typedef REC80			*PREC80;

/* �Ɏ��Ď޴��̿��ʎߎ� [52B]			*/
typedef struct
{
	COMREC				x;
	NODEREC				y;
}						REC90;
typedef REC90			*PREC90;

/* FTAM�̿��ʎߎ� [108B]			*/
typedef struct
{
	COMREC				x;
	FTAMREC				y;
}						RECA0;
typedef RECA0			*PRECA0;

/************************************/
/* �̎ߎ��َʎގ��̎����������� [16B]		*/
/************************************/
typedef struct pool_com
{
	struct pool_com		*next_ptr;		/* ���Ύ̎ߎ��َʎގ��̎����Ďގڎ�				*/
	long				len;			/* �����̎ߎ��َʎގ��̎�Ĺ					*/
	short				max_num;		/* �����̎ߎ��َʎގ��̎�����ڎ����Ď޿�			*/
	short				use_num;		/* �����̎ߎ��َʎގ��̎����юڎ����Ď޿�			*/
	short				max_bnum;		/* �����̎ߎ��َʎގ��̎�����ʎގ��Ŀ�			*/
	short				use_bnum;		/* �����̎ߎ��َʎގ��̎����ѺѤߎʎގ��Ŀ�		*/
}						POOLBUF;
typedef POOLBUF			*PPOOLBUF;
										/* ###ST2707 end					*/

										/* start SPCY0134					*/
										/*----------------------------------*/
										/* mm_rvdf��Ϣ�ǡ�����¤			*/
										/*----------------------------------*/
#define RVDF_TRUE		1				/* �ѹ�ͭ��							*/
#define RVDF_FALSE		0				/* �ѹ��ʤ�							*/

typedef struct {
	short		len;					/* �ΰ�Ĺ							*/
	short		num;					/* �ѹ������ֵѿ�					*/
} RVDFCOM;								/* �ѹ�����������¤��				*/

typedef struct {
	short		puno;					/* PU�ֹ�							*/
	short		chno;					/* CH�ֹ�							*/
	char		tel1;					/* �����ֹ棱�ѹ�̵ͭ				*/
	char		tel2;					/* �����ֹ棲�ѹ�̵ͭ				*/
	short		rsv;
} RVDFBUP;								/* �Хå����å������¤��			*/

typedef struct {
	short		puno;					/* PU�ֹ�							*/
	short		chno;					/* CH�ֹ�							*/
	short		fnapuno;				/* FNA-PU�ֹ�						*/
	char		dead;					/* ���DTE���ɥ쥹�ѹ�̵ͭ			*/
	char		rsv;
} RVDFFNA;								/* �ۥ�����³�����¤��			*/

typedef struct {
	short		puno;					/* PU�ֹ�							*/
	short		chno;					/* CH�ֹ�							*/
	char		dsid[16];				/* �̿���꼱��̾					*/
	char		radr;					/* ���¦DTE���ɥ쥹�ѹ�̵ͭ		*/
	char		awad;					/* ����ĥ���ɥ쥹�ѹ�̵ͭ			*/
	short		rsv;
} RVDFFTAM;								/* FTAM�̿���������¤��			*/
										/* end SPCY0134						*/
