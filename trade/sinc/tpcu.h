/****************************************************************************/
/*																			*/
/* TPCU	94/09/16 �ٻ���	������												*/
/* history:																	*/
/*	96.01.24 K.Kubota ST3937: add tpctmflg									*/
/*	03.04.16 S.Miyawaki LALa-SMP�ܿ�							MD001		*/
/****************************************************************************/
struct	tpcusub	{
	long  tpcuopn;						/* ����饤��ץ�����				*/
	long  tpcuenp;						/* ��ư�ץ�����					*/
	long  tpcusm;						/* ���ޥե����̻�					*/
	char  tpcudry[32];					/* �ǥ��쥯�ȥ�̾					*/
	short tpcureio;						/* ��ɽü���ץ����ֹ�				*/
	char  tpcusyob[2];					/* ͽ��								*/
	long  tpcuofp0;						/* �У������ե饤��ץ�����������	*/
};
typedef	 struct	 tpcusub TPCUSUB;
/****************************************************************************/
/*	�ԣУãո�����															*/
/****************************************************************************/
struct	tpcupsz	{
	long  tpcupid;						/* �ץ������̻�					*/
	char  tpcupnm[8];					/* �ץ�������̾					*/
	long  tpcuprn;						/* �ץ������					*/
	long  tpcuuid;						/* �桼�����̻�						*/
	long  tpcufno;						/* �ե����뵭�һҺ���Ŀ�			*/
	long  tpcuatr;						/* �ץ���°��						*/
	long  tpcuacc;						/* �ץ�������������				*/
	long  tpcupri;						/* ��ư���ץ���ͥ����				*/
	long  tpcuhpr;						/* �ѹ���¥ץ���ͥ����			*/
	long  tpcucls;						/* �������֤Υ�����					*/
	short tpcutabo;						/* �����ॹ�饤����			TD96	*/
	short tpcurno;						/* �ꥯ�����ȼ��̻Һ���Ŀ�			*/
	char  tpcupfn[16];					/* �ץ����ե�����̾				*/
	long  tpcupmb;						/* �ץ������̿��ᥤ��ܥå������̻�*/
	long  tpcunmb;						/* ͽ���ʥᥤ��ܥå������̻ҡ�		*/
	long  tpcusmi;						/* ���ޥե����̻�					*/
	char  tpcukcl;						/* ��ư���֥�å��ֹ�				*/
	char  tpcuheis;						/* �ĺɰ����ס�����					*/
	char  tpcuhinf;						/* �ĺɴ�λ����						*/
	char  tpcuflg;						/* �ץ����ؼ��ե饰				*/
	char  tpcuonm[8];					/* ��ư���ץ�������̾				*/
	char  tpcusts;						/* �ץ�������						*/
	char  tpcupuno;						/* �У��ֹ�							*/
	char  tpcuhotf;						/* �ۥåȥ�����Х������ؤ���		*/
										/*	�����������ס����׾���			*/
	char  tpcumflg;						/* �Ҏ��������ް�����/���� ST3937			*/
	char  tpcutyp[4];					/* �ץ�������					*/
	long  tpcupkn;						/* �ץ��������ֹ�				*/
	char  tpcugrn[2];					/* ���롼��̾						*/
	char  tpcusgn[2];					/* ���֥��롼��̾					*/
	long  tpcuecd;						/* ��λ������						*/
	long  tpcudtl;						/* �ܺپ���							*/
	long  tpcuadd;						/* �ץ�����λ�����ղþ���			*/
	char  tpcuabt;						/* ���ܡ��Ȼ��ν���					*/
	char  tpcupst;						/* �ץ������϶�ʬ					*/
	short tpcujnl;						/* �ʣΣ̽�������Хåե�������		*/
	long  tpcusno;						/* �ץ�����ư��������				*/
	short tpcuatsu;						/* Ʊ���Խ���ǽ�����				*/
	char  tpcuotyp[2];					/* �ץ������̡ʣУӣţã������	*/
	short tpcuant;						/* �ԣ��£ťꥹ����Ƭ�������ֹ�		*/
	short tpcupatn;						/* �ԣУ��ԥ���ȥ��ֹ�				*/
	long  tpcuwlg;						/* �㳲���ϥ��ꥢ�Υ�����			*/
	char  tpcudsts[2];					/* �ģãл��Ѥο�ʬ��				*/
	short tpcuabtn;						/* ���ܡ���ȯ�����					*/
	long  tpcucmx;						/* ���̥ե�����κ��祳�ͥ��ȿ�		*/
	long  tpcuexmo;						/* ��ư���ؿ�����					*/
	long  tpcuntcn;						/* ��ư�����ãťΡ����ֹ�			*/
	short tpcuabtm;						/* Ʊ��ץ������ܡ��Ȳ��������	*/
	char  tpcusus;						/* �����ڥ�ɵ�ư�ס�����			*/
	char  tpcuins;						/* �ɣΣɣԡ���ȯ����ե饰			*/
	char  tpcudwnf;						/* �����ƥ���������ե饰			*/
    char  tpcuncaf;                     /* ����󥻥��Բĥե饰        MD001*/
    char  tpcuswf;                      /* ����åץ����ȶػߥե饰    MD001*/
    char  tpcupap;                      /* apmain��Խ����ե饰        MD001*/
	long  tpcudtl2;						/* �ܺپ���						*/
	long  tpcudtl3;						/* �ܺپ���						*/
	unsigned char  tpcuoflg;			/* ��ư�ףӣͣХץ����ե饰		*/
	char  tpcursv4[2];					/* ͽ����			ST0079     MD001*/
    char  tpcuetyp;                     /* ��λ�����ץ�������        MD001*/
	char  tpcuonpa[32];					/* ��ư�ѥ�᥿						*/
	long  tpcuonod;						/* �����ãťΡ����ֹ�				*/
	long  tpcuwlgs;						/* �㳲���ώ��؎��ʣӣͣ��ѡˤΎ�������TD93*/
	long  tpcuapi;						/* �����ѥ�����				TD93*/
	unsigned short tpcuplsz;			/* �Хȥ졼���ΰ襵����			TD93*/
	char  tpcuplst;						/* �Хȥ졼������������ơ�����	TD93*/
	char  tpcutrcn;                     /* �ȥ졼���ե�����̾Ϣ�ּ�����MD001*/
	long  tpcuplab;						/* �Хȥ졼�����ܡ�������		TD93*/
	char  tpcusrsf;						/* SCP���ώݎĎ޼¹Է��������ʸ�̎׎���	TD18*/
    char  tpcudyrc;                     /* �ģ٣ңţ��оݥե饰        MD001*/
	short tpcuecmt;						/* �ԣãͣԥ���ȥ��ֹ�			TD12*/
};					 
typedef	 struct	 tpcupsz  TPCUPSZ;
