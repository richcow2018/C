/****************************************************************************/
/*      mo.h�Υ��󥯥롼�ɥե�����                                          */
/****************************************************************************/
/****************************************************************************/
/*      SMP��ž������¤��                                                   */
/****************************************************************************/
struct mosdinf {
	char  mosdsyd;						/* �϶�ʬ							*/
	char  mosdsyc;						/* �����ƥ๽������					*/
	char  mosdstd;						/* ���϶�ʬ							*/
	char  mosdrsv;						/* �֥��å��ֹ�ܺ�			TD01	*/
	long  mosdpmd;						/* �ץ������⡼��					*/
	char  mosdost;						/* �֥��å���ž����			TD01	*/
	char  mosdrv2[3];					/* ͽ��2							*/
};                                                                     
typedef struct mosdinf MOSDINF;                                        

/****************************************************************************/
/* 		�����ֵ���		#define												*/
/****************************************************************************/
#define  MONORMAL  0L					/* ����(�˲�������)					*/

/****************************************************************************/
/* 		mo_gtbf �ֵ���	#define												*/
/****************************************************************************/
#define  MOEEFLBF  0L					/* �ס���Хåե��˶������ʤ�		*/
#define  MOIVMEID -1L					/* �Хåե����̤��۾�Ǥ���			*/
#define  MOIVPBLN -2L					/* �Хåե�Ĺ���۾�Ǥ���			*/

#define  MOCMPBF   0L					/* CM�Хåե�						*/
#define  MOLMPBF   1L					/* LM�Хåե�						*/

/****************************************************************************/
/* 		mo_frbf �ֵ���	#define												*/
/****************************************************************************/
#define  MOEEEXST  1L					/* ���˲����ѤߤǤ���				*/
#define  MOIVPBAD -1L					/* ���ꤷ�����ɥ쥹���۾�Ǥ���		*/

/****************************************************************************/
/* 		mo_excm			#define												*/
/****************************************************************************/
#define  MOXMEXEC  0x00					/* ���ޥ�ɼ¹�						*/
#define  MOXMCRPR  0x01					/* �ץ���������						*/

/****************************************************************************/
/* 		mo_excm	�ֵ���	#define												*/
/****************************************************************************/
#define  MOCMOVR  -1L					/* ���ޥ��ʸ�����Ĺ�������С�		*/
#define  MONOMEM  -2L					/* �ס���Хåե��μ������Ǥ��ʤ�	*/
#define  MOERROR  -3L					/* ���ޥ��or�ѥ�᡼�����顼		*/
#define  MOTIMOU  -6L					/* �����ॢ����						*/

/****************************************************************************/
/* 		mo_crpr	�ֵ���	#define												*/
/****************************************************************************/
#define  MOPROMO   1L					/* �����ץ������ϵ�ư��				*/
#define  MONOPCT  -1L					/* ����ץ���������̾PCT�ˤʤ�		*/
#define  MOPRONG  -2L					/* �ץ�������������					*/
#define  MONOBUF  -3L					/* �ס���Хåե������ݤǤ��ʤ�		*/
#define  MOLNOVR  -4L					/* �ѥ�᡼���ι��Ĺ�������С�		*/
#define  MOPRMIS  -5L					/* ��ư�ѥ�᡼���λ���˸���		*/

/****************************************************************************/
/* 		mo_ipct	�ֵ���	#define												*/
/****************************************************************************/
#define  MOPCTLER  -1L					/* ����̷��							*/

/****************************************************************************/
/* 		mo_apdt	�ֵ���	#define												*/
/****************************************************************************/
#define	MONORMX     1L					/* ����դ����ｪλ					*/
#define	MOMFERR    -2L					/* �񸻴ط���������					*/
#define	MONOTAPD   -3L					/* AP���ջ��ѥ����ƥ�Ǥʤ�			*/
#define	MOTRANERR  -4L					/* �ȥ�󥶥��������Ǥ���			*/
#define	MOMRERR    -5L					/* ���㡼�ʥ��Խ�����������			*/

#define	MOAPGET		0L					/* �����⡼��						*/
#define	MOAPSET		1L					/* ����⡼��						*/

/****************************************************************************/
/* 		Ĺ��			#define												*/
/****************************************************************************/
#define  MOGTPBFL  384L					/* ���ޥ���Խ��Хåե�Ĺ			*/
#define  MOCRPBFL  384L					/* ���ޥ���Խ��Хåե�Ĺ			*/
#define  MOLIMCML  256L					/* ���ޥ��ʸ��������Ĺ				*/

/****************************************************************************/
/* 		�ץ��������������¤��								STC534			*/
/****************************************************************************/
struct moprinf {
	char  mogtpnam[8];					/* �ץ���������̾					*/
	long  mogtpid;						/* �ץ��������̻�					*/
	long  mogtpmb;						/* �ᥤ��ܥå������̻�				*/
	short mogtpno;						/* �ץ�����NO.						*/
	char  mogtobno;						/* ��ư���֥��å��ֹ�ܺ�	TD01	*/
	char  mogtrcv;						/* ͽ��						TD01	*/
	char  mogtsts;						/* �ץ���������						*/
	char  mogtabt;						/* ���ܡ��Ȼ��ν���					*/
	char  mogtshu;						/* �ץ���������				TD00	*/
	char  mogtodev;						/* ��ư���϶�ʬ						*/
	char  mogtopnm[8];					/* ��ư���ץ���������̾				*/
};
typedef struct moprinf MOPRINF;

/****************************************************************************/
/* 		mo_prgt	�ֵ���	#define								STC534			*/
/****************************************************************************/
#define  MOPNAMNG  -1L					/* pnam all blank					*/
#define  MONOTPCT  -2L					/* TPCT���ʤ�						*/
#define  MONOTFND  -3L					/* TPCT�ˤʤ�						*/

/****************************************************************************/
/* 		mo_prgt	���ơ�����	#define							STC534			*/
/****************************************************************************/
#define  MOGTNON   '0'					/* ̤����							*/
#define  MOGTREQ   '1'					/* ��ư�׵���						*/
#define  MOGTING   '2'					/* ��ư��							*/
#define  MOGTSUS   '3'					/* ��������						*/
#define  MOGTEND   '4'					/* ��λ�׵���						*/
#define  MOGTCED   '5'					/* ������λ�׵���					*/
#define  MOGTSSP   '6'					/* �����ڥ����				TD02	*/

/****************************************************************************/
/* 		mo_prgt	����	#define								STC534			*/
/****************************************************************************/
#define  MOGTON   '0'					/* ����饤��ץ�����				*/
#define  MOGTOFF  '1'					/* ���ե饤��ץ�����				*/

/****************************************************************************/
/* 		mo_gptm	�ֵ���	#define								STC???			*/
/****************************************************************************/
#define  MOPARER   -1L					/* �ѥ�᥿���顼					*/
#define  MONOPTM   -2L					/* �Ÿ����楿����̤��³				*/
#define  MOCMMOD   -3L					/* �ѥͥ뤬���ޥ�ɥ⡼��			*/
#define  MOTMOUT   -4L					/* �����ॢ����						*/
#define  MOBUGER   -5L					/* �Хåե���������					*/

/****************************************************************************/
/* 		mo_gptm	����	#define								STC666			*/
/****************************************************************************/
#define  MOPTMON  '0'					/* ���󥿥���						*/
#define  MOPTMOFF '1'					/* ���ե�����						*/

/****************************************************************************/
/* 		mo_shgt			#define												*/
/****************************************************************************/
#define  MOIVSHLN  -2L					/* ���ꥵ��������Ǥ���			*/
#define  MOEMPSMT  -3L					/* TSMT���ʤ�						*/
#define  MOSMTFUL  -4L					/* TSMT�˶������ʤ�					*/

#define  MOCMSHM    0L					/* ��������						*/
#define  MOLMSHM    1L					/* �����������					*/

/****************************************************************************/
/* 		mo_shat			#define												*/
/****************************************************************************/
#define  MOIVSHID  -1L					/* ���˲����ѤߤǤ���				*/

/*******************************************************************TD00*****/
/* 		mo_exct			#define										TD00	*/
/*******************************************************************TD00*****/
#define  MOSEFON    0L					/* ����						TD15	*/
#define  MOSEFOFF   1L					/* ����						TD15	*/
#define  MOMODERR  -2L					/* ���󡿥��հʳ�			TD15	*/

/*******************************************************************TD00*****/
/* 		mo_dyck	�ֵ���	#define										TD00	*/
/*******************************************************************TD00*****/
#define  MOCHKNG   -1L					/* ���ա�������ͤ�����		TD80	*/

/******************************************************	SSCY0074 start ******/
/* 		mo_tbok	�ֵ���	#define												*/
/****************************************************************************/
#define  MOKINDNG  -1L					/* �ơ��֥��������					*/
/*  #define  MONOMEM   -2L	�ס���Хåե����ݥ��顼						*/
/*  MONOMEM��mo_excm���ֵ��ͤ��������Ƥ���Τǡ������Ǥ�������ʤ�		*/

#define  MOTBLERR  -3L					/* �ơ��֥��ҷϸξ�ȯ��				*/
#define  MONOLMT   -4L					/* TLMT̤¸��						*/
#define  MONODRV   -5L					/* �����ƥ���֥��顼				*/
/*  #define  MOTIMOU   -6L	���촰λ�Ԥ������ॢ����						*/
/*  MOTIMOU��mo_excm���ֵ��ͤ��������Ƥ���Τǡ������Ǥ�������ʤ�		*/
										/* 					SSCY0074 end	*/

/****************************************************************************/
/*      reboot   ��λ��ǽ  #define                              PRC-040-21  */
/****************************************************************************/
#define  MORLDCR   "reboot LINUX_DUMP_CMD_RESTART"
#define  MORLRCR   "reboot LINUX_REBOOT_CMD_RESTART"
#define  MORLDCH   "reboot LINUX_DUMP_CMD_HALT"
#define  MORLRCH   "reboot LINUX_REBOOT_CMD_HALT"
