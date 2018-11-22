/****************************************************************************/
/*     mc.h   ��  ���ݎ���-�Ď� �̎�����('94.01.12 ����)								*/
/****************************************************************************/

/****************************************************************************/
/* �㽤���ԡ�	���ץ饤 �������											*/
/* �㽤������	2003.07.08													*/
/* �㽤��ID��	********   CORBA�ؿ��μ��̤��ɲ�							*/
/****************************************************************************/
/****************************************************************************/
/* �㽤���ԡ�	NTT-D�����ܡ�����											*/
/* �㽤������	2003.5.15													*/
/* �㽤��ID��	TBCS0086   TRADE���Ў��ڎ��Ĵؿ��򎼎��Îѥ�������̤��ɲ�			*/
/****************************************************************************/

 
/****************************************************************************/
/*                                                                   		*/
/*        ���֎������ݎ��� �� �͎ݎ��Ԏ��� �� �Î�����          START                   		*/
/*                                                                   		*/
/****************************************************************************/

#define MCNMAL		0					/* �������ގ��� �������؎���					*/
#define MCERR		-100				/* �����ގ���  �������؎���					*/
#define	MCOVER		-104				/* �����ʎގ� �̎ێ�						*/
#define	MCNOTEQU	-108				/* NULL �ώÎ� �� �ӎ��ގڎˎ��� �� �͎ݎ��Ԏ���		*/
#define	MCNONM		-112
/************************************************/
/*  �ؿ��ֵ���	 �ɲ�94.7.14  ���桡��Ƿ(NTT-D) */
/************************************************/
#define		MCNORMAL		0x0
#define		MCOVRENT		-120
#define		MCIVPARM		-124
#define		MCNOENTR		-128
  
/****************************************************************************/
/*																			*/
/*        ���֎������ݎ��� �� �͎ݎ��Ԏ��� �� �Î�����           END							*/
/*                                                                   		*/
/****************************************************************************/

/****************************************************************************/
/*        SMP CALL CODE														*/
/****************************************************************************/
#define MCEOSERR   -10000L

/****************************************/
/*	�����ƥॳ�������					*/
/****************************************/
										/* �¹Դ������̎ߎێ�������				*/
#define	MCEOSCREPR		0x01
#define	MCEOSDESPR		0x02
#define	MCEOSTERM		0x03
#define	MCEOSRESPR		0x04
#define	MCEOSSLEEP		0x05
#define	MCEOSWAKEUP		0x06
#define	MCEOSRSCHD		0x07
#define	MCEOSSUSPR		0x08
#define	MCEOSWCHLD		0x09
#define	MCEOSWCHLDR		0x0a
#define	MCEOSSTUIC		0x0b
#define	MCEOSSTPGR		0x0c
#define	MCEOSCHPRI		0x0d
#define	MCEOSCHOPRI		0x0e
#define	MCEOSGTPIN		0x0f
#define	MCEOSGTPRI		0x10
#define	MCEOSGTOPRI		0x11
#define	MCEOSGTSTS		0x12
#define	MCEOSGTUIC		0x13
#define	MCEOSGTPGR		0x14
#define	MCEOSCREMPR		0x15
										/* 0x16��1f��ͽ��					*/
										/* �¹Դ��������͎ގݎ�����				*/
#define	MCEOSCRESP		0x20
#define	MCEOSDELSP		0x21
#define	MCEOSWAITSP		0x22
#define	MCEOSWAITEV		0x23
#define	MCEOSSIGSP		0x24
#define	MCEOSEVENT		0x25
#define	MCEOSSNSSP		0x26
#define	MCEOSSNSEV		0x27
#define	MCEOSRSTEV		0x28
										/* 0x29��2f��ͽ��					*/
										/* �¹Դ������Ҏ����������̿�				*/
#define	MCEOSCREMB		0x30
#define	MCEOSDELMB		0x31
#define	MCEOSSENMS		0x32
#define	MCEOSSENMSP		0x33
#define	MCEOSRCVMS		0x34
#define	MCEOSRCVMSR		0x35
#define	MCEOSRCVMSP		0x36
#define	MCEOSRCVMSPR	0x37
#define	MCEOSSNSMS		0x38
#define	MCEOSSTMS		0x39
#define	MCEOSSENMS2		0x3a
										/* 0x3a��3f��ͽ��					*/
										/* �¹Դ������؎��ގَĎ��㳰				*/
#define	MCEOSGTNRL		0x40
#define	MCEOSGTNRLA		0x41
#define	MCEOSANYRL		0x42
#define	MCEOSCANRQ		0x43
#define	MCEOSSNSRL		0x44
#define	MCEOSATRQEV		0x45
#define	MCEOSATRQEVI	0x46
#define	MCEOSDTRQEV		0x47
#define	MCEOSRSRRD		0x48
#define	MCEOSRELRD		0x49
#define	MCEOSSTPIR		0x4a
#define	MCEOSSTPIRI		0x4b
#define	MCEOSSETEX		0x4c
#define	MCEOSSETEXI		0x4d
#define	MCEOSRSTPIR		0x4e
#define	MCEOSRSTEX		0x4f
#define	MCEOSGTCPIR		0x50
#define	MCEOSGTEX		0x51
#define	MCEOSRTNPIR		0x52
#define	MCEOSEXITH		0x53
#define	MCEOSRAIEX		0x54
										/* 0x55��5f��ͽ��					*/
										/* �¹Դ������ʎގ��̎��̎ߎ��ٴ��� 			*/
#define	MCEOSCRELBP		0x60
#define	MCEOSCRECBP		0x61
#define	MCEOSDELBP		0x62
#define	MCEOSGTPBF		0x63
#define	MCEOSFRPBF		0x64
#define	MCEOSSNSFU		0x65
#define	MCEOSSNSAU		0x66
#define	MCEOSSNSUS		0x67
#define	MCEOSSNSLC		0x68
#define	MCEOSSNSPBI		0x69
#define	MCEOSSNSADI		0x6a
#define	MCEOSATBP		0x6b
#define	MCEOSDTBP		0x6c
										/* 0x6d��6f��ͽ��					*/
										/* �¹Դ��������юҎӎش��� 			*/
#define	MCEOSGTSHM		0x70
#define	MCEOSATSHM		0x71
#define	MCEOSDTSHM		0x72
										/* 0x73��78��ͽ��					*/
										/* �¹Դ����������ϴ��� 				*/
#define	MCEOSDELAY		0x79
#define	MCEOSSLPUM		0x7a
#define	MCEOSSTTIM		0x7b
#define	MCEOSSTDTIM		0x7c
#define	MCEOSSTDAT		0x7d
#define	MCEOSGTDAT		0x7e
#define	MCEOSSNSTM		0x7f
										/* �¹Դ���������¾ 				*/
#define	MCEOSLTORAD		0x80
#define	MCEOSGETINF		0x81
#define	MCEOSRSTINF		0x82
#define	MCEOSSTINF		0x83
#define	MCEOSTMINF		0x84
#define	MCEOSGTPRCINF	0x85
#define	MCEOSGTKTRINF	0x86
#define	MCEOSPATHOPN	0x87
#define	MCEOSPATHCLS	0x88
#define	MCEOSSYMTOAD	0x89
										/* 0x8a��8f��ͽ��					*/
										/* �ե�����������̎����َ��Îގ��ڎ��Ď���� 	*/
#define	MCEOSCHROOT		0x90
#define	MCEOSCHWKD		0x91
#define	MCEOSCLOSE		0x92
#define	MCEOSICLOSE		0x93
#define	MCEOSCONN		0x94
#define	MCEOSCREAT		0x95
#define	MCEOSDCONN		0x96
#define	MCEOSDELET		0x97
#define	MCEOSEXTEN		0x98
#define	MCEOSLINK		0x99
#define	MCEOSMKNOD		0x9a
#define	MCEOSMOUNT		0x9b
#define	MCEOSOPEN		0x9c
#define	MCEOSIOPEN		0x9d
#define	MCEOSRENAM		0x9e
#define	MCEOSTRUNC		0x9f
#define	MCEOSUMOUNT		0xa0
#define	MCEOSUMOUNTF	0xa1
										/* 0xa2��a7��ͽ��					*/
										/* �ե�����������Îގ������ 			*/
#define	MCEOSFLUSH		0xa8
#define	MCEOSFREE		0xa9
#define	MCEOSREAD		0xaa
#define	MCEOSIREAD		0xab
#define	MCEOSREADD		0xac
#define	MCEOSIREADD		0xad
#define	MCEOSREADDL		0xae
#define	MCEOSIREADDL	0xaf
#define	MCEOSSEEK		0xb0
#define	MCEOSISEEK		0xb1
#define	MCEOSSYNC		0xb2
#define	MCEOSWRITE		0xb3
#define	MCEOSIWRIT		0xb4
#define	MCEOSWRITD		0xb5
#define	MCEOSIWRITD		0xb6
										/* 0xb7��ͽ��						*/
										/* �ե�������������� 				*/
#define	MCEOSACCESS		0xb8
#define	MCEOSCHACC		0xb9
#define	MCEOSCHOWN		0xba
#define	MCEOSDUP		0xbb
#define	MCEOSFCNTL		0xbc
#define	MCEOSGFINF		0xbd
										/* 0xbd������						*/
#define	MCEOSGLOCK		0xbf
#define	MCEOSGTACC		0xc0
#define	MCEOSGTIDN		0xc1
#define	MCEOSGTWKD		0xc2
#define	MCEOSGUNLOCK	0xc3
#define	MCEOSIOCTL		0xc4
#define	MCEOSIIOCTL		0xc5
#define	MCEOSUMASK		0xc6
										/* 0xc7�����֢�0xa1(osumountf)¸��	*/
										/* 0xc8��cf��ͽ��					*/
										/* �����ƥ����桦���� 				*/
#define	MCEOSIPL		0xd0
#define	MCEOSIPL2		0xd1
#define	MCEOSRESTART	0xd2
#define	MCEOSRESTART2	0xd3
										/* �����ƥ����桦��λ 				*/
#define	MCEOSSYSOFF		0xd4
										/* �����ƥ����桦�㳲 				*/
#define	MCEOSSYSDOWN	0xd5
#define	MCEOSSYSDOWN2	0xd6
#define	MCEOSCHGACT		0xd7
#define	MCEOSCHGACT2	0xd8
										/* �����ƥ����桦���ִ��� 			*/
#define	MCEOSCONFIG		0xd9
#define	MCEOSCFPCON		0xda
#define	MCEOSDSPINF		0xdb
#define	MCEOSCFPRSLT	0xdc
										/* 0xdd������						*/
#define	MCEOSGETPTH		0xde
#define	MCEOSEXCHGPTH	0xdf
										/* �����ƥ���������Ѵ��� 			*/
#define	MCEOSGETAPMD	0xe0
#define	MCEOSGETHSW		0xe1
#define	MCEOSGETSSW		0xe2
#define	MCEOSSYSRCVR	0xe3
#define	MCEOSMBINF		0xe4
#define	MCEOSGETMBID	0xe5
#define	MCEOSPRGMD		0xe6
#define	MCEOSGETPUC		0xe7
#define	MCEOSGETIOS		0xe8
#define	MCEOSGETBNO		0xe9
#define	MCEOSSYSMD		0xea
										/* �����ƥ����������¾ 			*/
#define	MCEOSSETPTM		0xeb
#define	MCEOSGETPTM		0xec
#define	MCEOSENBPTM		0xed
#define	MCEOSDSBPTM		0xee
#define	MCEOSEXCNTRL	0xef
#define	MCEOSGETSRV		0xf0
#define	MCEOSCMDMD		0xf1
#define	MCEOSTELREG		0xf2
#define	MCEOSTELDEL		0xf3
#define	MCEOSTELGET		0xf4
#define	MCEOSTELCAL		0xf5
#define	MCEOSABTMD		0xf6
										/* 0xf7��fa��TRADE���Ў��ڎ��Ľ��������λ TBCS0086 */
#define	MCEOSINITSYSTEM		0xf7
#define	MCEOSINITPROCESS	0xf8
#define	MCEOSENDSYSTEM		0xf9
#define	MCEOSENDPROCESS		0xfa
										/* TBCS0086 end */

										/* 0xfb��ff��ͽ��					*/

/****************************/
/*	��꡼(Rally)�ؿ�����	*/
/****************************/
#define	CF_RVINIT		0x00003000
#define	CF_RVEND		0x00003001
#define	CF_RVBGET		0x00003100
#define	CF_RVBFREE		0x00003101
#define	CF_RVBINQ		0x00003102
#define	CF_RVPOST		0x00003200
#define	CF_RVL3OPN		0x00003300
#define	CF_RVL3CLS		0x00003301
#define	CF_RVRSTRT		0x00003302
#define	CF_RVRST		0x00003303
#define	CF_RVECHO		0x00003304
#define	CF_RVECHOE		0x00003305
#define	CF_RVIPT		0x00003306
#define	CF_RVIPTR		0x00003307
#define	CF_RVL3CNF		0x00003308
#define	CF_RVL3ADD		0x00003309
/****************************/
/*	�ϣӣɡݣƣԣ��ʹؿ�����*/
/****************************/
#define	CF_ACTOPEN		0x00003401
#define	CF_ACTCLOS 		0x00003402
#define	CF_ACTPSET 		0x00003403 
#define	CF_ACTPRSP  	0x00003404
#define	CF_ACTPFRE  	0x00003405
#define	CF_ACTPFRS   	0x00003406
#define	CF_ACTPSND  	0x00003407
#define	CF_ACKMANA		0x00003408
#define	CF_ACKMANB  	0x00003409
#define	CF_ACKMANC  	0x0000340a
#define	CF_ACKMAND 		0x0000340b
#define	CF_ACKMANE      0x0000340c
#define	CF_ACKMANF 		0x0000340d 
#define	CF_ACKMANG      0x0000340e

/* ����ID: ********  CORBA �ؿ������ɲ� start */
/*****************/
/* CORBA�ؿ����� */
/*****************/
#define	FID_CORBA_ORB_init								\
							0x00009700	//ORB�����
#define	FID_CORBA_ORB_BOA_init							\
							0x00009701	//���ܥ��֥������ȥ����ץ������
#define	FID_CORBA_ORB_resolve_initial_references		\
							0x00009702	//����ץ���ơ�������ݥ��ȥ�Υ��֥������ȥ�ե���󥹤γ���
#define	FID_FJ_ImplementationRep_lookup_id				\
							0x00009703	//ImplementationDef���֥������ȤΥ��֥������ȥ�ե���󥹤θ���
#define	FID_CORBA_BOA_impl_is_ready						\
							0x00009704	//�����Фγ�����
#define	FID_CORBA_BOA_deactivate_impl					\
							0x00009705	//�����Ф��������
#define	FID_CosNaming_NamingContext_resolve				\
							0x00009706	//�����Х��ץꥱ�������Υ��֥������ȥ�ե���󥹤γ���
#define	FID_CORBA_ORB_set_client_timer					\
							0x00009707	//�����Х᥽�å��Ե����֤�����
#define	FID_lala_nodekan_Octets_alloc					\
							0x00009708	//�������󥹹�¤�Τ��ΰ����
#define	FID_lala_nodekan_Octets_allocbuf				\
							0x00009709	//�ǡ�������ΰ����
#define	FID_lala_nodekan_msgsnd							\
							0x0000970a	//�᥽�åɥ�����
#define	FID_CORBA_sequence_set_release					\
							0x0000970b	//��꡼���ե饰������
#define	FID_CORBA_free									\
							0x0000970c	//�����ΰ�β���
#define	FID_CORBA_Object_release						\
							0x0000970d	//�����Х��ץꥱ�������Υ��֥������ȥ�ե���󥹤β���
/* ����ID: ********  CORBA �ؿ������ɲ� end */
