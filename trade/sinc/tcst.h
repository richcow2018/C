
/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��					��ž������̳							*/
/*���оݶ�̳�ɣġ�															*/
/*�㥵���ӥ�����̾��														*/
/*�㥵���ӥ����ܣɣġ�														*/
/*��⥸�塼��̾��					�ԣãӣԥơ��֥�						*/
/*��⥸�塼��ɣġ�														*/
/*��⥸�塼�����֡�														*/
/*--------------------------------------------------------------------------*/
/*��Ŭ�ѵ����						���ã�									*/
/*��Ŭ�ѣϣӡ�						�ԣң��ģ�								*/
/*�㳫ȯ�Ķ���						�ӣգΡ��ӣУ��ңáݣɣУ�				*/
/*�㵭�Ҹ����						�ø���									*/
/*��⥸�塼����֡�				��¤��									*/
/*�㵡ǽ��ʬ��																*/
/*���оݥǡ�����															*/
/*�㹩�������ض�ʬ��														*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯ�����ƥ�̾��				���ãšݣӣͣХ����ƥ�					*/
/*�㳫ȯ�����ƥ��ֹ��				������������������������				*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯô��̾��					�Ķ�Ź�����ƥ�ô��						*/
/*�������ֹ��						169-3537(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/*���߷׼�̾��						�ԣģá����͡��층						*/
/*���߷�ǯ������					��������ǯ���������					*/
/*���߷׽�����̾��															*/
/*���߷׽���ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/*�㥽����������̾��				�ԣģá���������						*/
/*�㥽��������ǯ������				��������ǯ���������					*/
/*�㥽����������̾��				�ԣģá����桡����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ  �������	CT0809 ST1748   */
/*�㥽����������̾��				�ԣģá�����  ����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ  �������	CT0868 ST1749	*/
/*�㥽����������̾��				�ԣģá����桡����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ  �������	CT1107 ST3143	*/
/*�㥽����������̾��				�ԣģá�����  ͭ��						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������	CT1211(ST4062)	*/
/*�㥽����������̾��				NTT-D�� ���ܡ�����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������	SSCY0198		*/
/*�㥽����������̾��				NTT-D�� ����������					M01	*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������	ST4896			*/
/*--------------------------------------------------------------------------*/
/*�㸫�ѥ��ƥåס�															*/
/*--------------------------------------------------------------------------*/
/*�㵡ǽ���ס�																*/
/*--------------------------------------------------------------------------*/
/*��ƽз�����																*/
/*�㲾������																*/
/*���ֵ��͡�																*/
/*--------------------------------------------------------------------------*/
/*�������ϥǡ�����¤��														*/
/*�����»����																*/
/*		�̣ͥơ��֥�Ǥ��롣												*/
/*		�ԣ֣ãԤΥ��ơ������ϰʲ����̤�Ǥ��롣							*/
/*			���ӣͣС����Фν�°			�ӣͣХơ��֥�					*/
/*			���ң£ɼ������ס���			����							*/
/*			�����ȡ�����					�����ơ��֥�					*/
/*			����¾���ס���					��¾��							*/
/*			����������¾��������¾			������¾						*/
/*			���ʣΣ̼���ñ�̸�����������	�ʰ�̣�ʤ���					*/
/*����ѳ����⥸�塼��ɣġ�												*/
/*��ƽи��Υ⥸�塼��ɣġ�												*/
/****************************************************************************/
/****************************************************************************/
/*�ץ���������̾	:												 		*/
/*�ץ�����̾		:���Хץ�����									 		*/
/*��¤�ֹ�			:PRC-031-01										 		*/
/*��¤����			:����̾�Τ���Ū�˱�ä�̾�Τ˽���     			 		*/
/*��¤��			:2002.11.07										 		*/
/*��¤��			:supply Taguchi									 		*/
/****************************************************************************/
/****************************************************************************/
/*�ץ���������̾	:												 		*/
/*�ץ�����̾		:mob											 		*/
/*��¤�ֹ�			:PRC-057-01										 		*/
/*��¤����			:mob���������ѹ��б�			     			 		*/
/*��¤��			:2003.3.31										 		*/
/*��¤��			:supply Kajiwara								 		*/
/****************************************************************************/
/****************************************************************************/
/*�ץ���������̾	:												 		*/
/*�ץ�����̾		:rcv											 		*/
/*��¤�ֹ�			:PRC-058-01										 		*/
/*��¤����			:rcv���������ѹ��б�			     			 		*/
/*��¤��			:2003.4.04										 		*/
/*��¤��			:supply 										 		*/
/****************************************************************************/
/****************************************************************************/
/*	�ԣãӣԸ�����															*/
/****************************************************************************/
struct  tcstpsz {
	char  tcststat[4];                  /* �����ƥॹ�ơ�����				*/
	long  tcstedwt;                     /* ��λ�Ԥ�����						*/
	long  tcstmfwt;                     /* ����ͭ�����Ԥ�����				*/
	long  tcstmrbi;                     /* �ң£ɼ����ֳֻ���				*/
	long  tcstdktm;                     /* �����ǥ������񤭹��ߥ�����		*/
    long  tcstmrlb;						/* �ܥ�塼�ॳ�ԡ��Хåե�������	*/
    char  tcstutyd[16];					/* �ԣң��ģš��գΣɣإ��ޥ�ɳ�Ǽ	*/
										/*	�ͥåȥ���ǥ��쥯�ȥ�̾		*/
    short tcstmrec;						/* �ܥ�塼���ĺɴ�λ�Ԥ����		*/
    char  tcstfptp;						/* �ե�����ž���ѥ����楿����		*/
    char  tcstcid;                      /* ����ü���ֹ�						*/
    long  tcsttktm;						/* �������������󥿥Х륿������	*/
	long  tcstcewt;                     /* ����������¹��Ԥ�����		*/
	long  tcstcpwt;                     /* ��������¹��Ԥ�����		*/
	char  tcstlvl;                      /* ��å�������٥�					*/
	char  tcstansr;                     /* �ţΣѥ������󥹱�����������	*/
    short tcstifsz;                     /* �ɥե졼��Ĺ�ʣΣãС�			*/
	long  tcstevnt;                     /* �ξ�������٥���ֹ�				*/
	char  tcsterrp[8];                  /* �ξ�����ץ���������̾			*/
    char  tcstmrra[8];					/* �ܥ�塼�����������				*/
										/*	���Хץ���������̾				*/
    char  tcstzerm[8];                  /* ���䶨���顼��å���������������	*/
										/*	���Хץ���������̾				*/
    char  tcstdaap[8];                  /* ��ɽ���Хץ���������̾			*/
    char  tcstsmpa[8];                  /* �ӣͣХե����룲�Ÿξ�ȯ��������	*/
										/*	��������Хץ���������̾		*/
    char  tcstsyoa[8];                  /* ͽ���ϥ�����ȯ��������������		*/
										/*	���Хץ���������̾				*/
    char  tcstntca[8];                  /* �Σԣôֲ����ξ�ȯ��������������	*/
										/*	���Хץ���������̾				*/
    char  tcstmria[8];					/* �ܥ�塼���������������			*/
										/*	���Хץ���������̾				*/
    char  tcstzena[8];                  /* ���䶨�����ξ�ȯ��������������	*/
										/*	���Хץ���������̾				*/
    char  tcstgyoa[8];                  /* ��̳�ե�����ξ�ȯ��������������	*/
										/*	���Хץ���������̾				*/
    char  tcstresa[8];                  /* �ꥹ�ȥ����ϡ���λ������			*/
										/*	���Хץ���������̾				*/
    char  tcstdcpp[8];                  /* �ϴ��̿�����ץ���������̾		*/
    char  tcstncpp[8];                  /* �Σԣô��̿�����ץ���������̾	*/
    char  tcstzcpp[8];                  /* ���䶨��굯ư�ץ���������̾		*/
    char  tcsticpp[8];                  /* �ɡ��ϥ���ͥ�����ץ���������̾	*/
    char  tcstzcpq[8];                  /* ���䶨������ư�ץ���������̾		*/
    long  tcstmrwt;                     /* ����ң£ɼ�������				*/
	long  tcstjsiz;                     /* �ʣΣ��Խ����ĥ������			*/
    long  tcstfnat;                     /* �����ƥ��Ȱ����ٻ���������	*/
    short tcstfnar;                     /* �����ƥ��Ȱ����ٻ���ȥ饤���*/
    short tcstslfn;                     /* ���Ρ����ֹ�						*/
    long  tcstopnt;						/* ��ǥࡿ�ģӣոξ��				*/
										/*	��ȥ饤��������				*/
    char  tcstrnui;                     /* �ꥫ�Х��ס����׾���				*/
	char  tcstmrjb;                     /* �ʣΣ̥Хå����åץ⡼��			*/
	char  tcst2err;                     /* ���Ÿξ���ν���					*/
    char  tcstsnui;                     /* ��ư�Ƴ��ס����׾���				*/
    char  tcstlnui;                     /* ���������ס����׾���				*/
    char  tcstinsg;                     /* �����ϥơ��֥������ˡ			*/
    char  tcstbnui;                     /* �Хå����å��ס����׾���			*/
/*  ���ǥ������֤Υ��ԡ��ѻߤ�ȼ�����(1��)									*/
	char  tcstkjus;						/* �ˣʻ��Ѿ���	   		 	 CT0809 */
    char  tcstascp[8];					/* ���ϥץ���������̾				*/
    short tcstmisz;                     /* ����ͣɣ�������					*/
    short tcstrbsg;                     /* ���䡲������Ѽ����Хåե�����	*/
										/*	������							*/
    short tcstrbsi;                     /* ���䡲������Ѽ����Хåե�����	*/
										/*	������							*/
    short tcstabtn;                     /* Ʊ��ץ��������ܡ��Ȳ��������	*/
    char  tcstlpmg;                     /* ������å���������̵ͭ			*/
    char  tcstmrvm;                     /* �֣ңã�����⡼��				*/
    short tcstedsu;                     /* Ʊ�참���Խ���ǽ��				*/
    long  tcstkyot;                     /* �����ĺɱ����ƻ륿������			*/
    long  tcstkait;                     /* ���������ƻ륿������				*/
    char  tcstscpp[8];                  /* ��å�������ѥץ���������̾		*/
    long  tcstnlt1;                     /* ���������ץ��ȥ饤�����ޡ��̣ԣ�*/
    long  tcstnlt2;                     /* �⡼�ɥ��åȥ�ȥ饤�����ޡ��̣ԣ�*/
    long  tcstnt1n;                     /* �����ƻ륿����	���ԣ�			*/
    long  tcstnt2n;                     /* �ӥ����ƻ륿����	���ԣ�			*/
    long  tcstnt3n;                     /* �ң��Դƻ륿����	���ԣ�			*/
    long  tcstnt5n;                     /* �ӣ��Դƻ륿����	���ԣ�			*/
    long  tcstnft1;                     /* �ģձ�����ǧ�����ޡ��ƣԣ�		*/
    long  tcstnft2;                     /* �Ρ��ɿ��ǳ�ǧ�����ޡ��ƣԣ�		*/
    long  tcstnft3;                     /* �Ρ��ɿ��ǥ�ȥ饤�����ޡ��ƣԣ�	*/
    long  tcstnft4;                     /* �ѥ���³��ǧ�����ޡ��ƣԣ�		*/
    long  tcstnft5;                     /* �ѥ���³��ȥ饤�����ޡ��ƣԣ�	*/
    long  tcstnft6;                     /* �ѥ����ǳ�ǧ�����ޡ��ƣԣ�		*/
    long  tcstnft7;                     /* �ԥѥ�ʧ�Х�ȥ饤�����ޡ��ƣԣ�	*/
    long  tcstnct1;                     /* �ϴֱ�����ǧ�����ޡ��ãԣ�		*/
    long  tcstsbin;						/* ���֣ͣӽ������λ�Ԥ�����		*/
    long  tcstsbtr;						/* ���֣ͣӽ�λ�Ԥ�����				*/
    long  tcstrcov;						/* �����㳲�������Х�������			*/
    long  tcstrunt;						/* �����㳲�������Х������ͤ�ñ��	*/
    long  tcsthctm;                     /* �ͣɣ¥��󥿡��Х륿����	 		*/
    long  tcstcntm;                     /* �̎ߎێ��������ݎ����Ԥ����֡���SSCY0198	*/
    short tcstnn1n;						/* �ģԥѥ��å�̵����				*/
										/*	��ȥ饤������Σ�				*/
    short tcstnn2n;						/* �ģԥѥ��åȥӥ���				*/
										/*	��ȥ饤������Σ�				*/
    short tcstnn3n;						/* �ң���̵������ȥ饤������Σ�	*/
    short tcstrt4w;                     /* ���������Ͻ����۾���Υ�ȥ饤���*/
    short tcstexrs;						/* ���ϥѥ������ѹ�ɽ���ʣԣң��ģš�*/
    short tcstexsm;						/* ���ϥѥ������ѹ�ɽ���ʣӣͣС�	*/
	long  tcstwivl;						/* ͽ���ϴƻ�ֳ�		PRC-057-01	*/
	char  tcsttrcv;						/* �ơ��֥�ꥫ�Х��ס�����			*/
    									/* 						PRC-058-01	*/
	char  tcstyob21;					/* ͽ����short->char���ѹ���		*/
										/* 						PRC-058-01	*/
    short tcstyob22;                    /* ͽ��								*/
    short tcstyob23;                    /* ͽ��								*/
    short tcstyob24;                    /* ͽ��								*/
    short tcstnwsn;                     /* ������ɥ�������					*/
    char  tcstutyp;						/* �ԣң��ģš��գΣɣإ��ޥ��		*/
										/*	��Ǽ�У��ֹ�					*/
	char  tcstmsgh;						/* ��å���������ɽ��				*/
	long  tcstmfrw;                     /* �ƣɣ���λ���������ꥶ����Ի���*/
	char  tcstmfeq;                     /* �ƣɣ���¾�����å��ס�����		*/
	char  tcststnd;						/* �Ρ����ֹ���Ϳɽ��				*/
	short tcstkmsg;                     /* ����ϴ֥�å�����Ĺ				*/
	long  tcstlopt;                     /* ���ڥ졼���Ȥβ��û������Ԥ�����	*/
    long  tcstmrbt;                     /* �Хå����å��ѣ֣ңãִƻ륿����	*/
	long  tcstjrsz;						/* ���ގ����Ŏٰ���ɤ߹���Ĺ		CT1211	*/
	short tcsttrcf;                    	/* �ȥ졼�������ס�����	PRC-031-01	*/
	short tcstyob34;                    /* ͽ��								*/
	char  tcstmran[8];					/* ���ãá�����ͭ������������		*/
										/*	���Хץ���������̾				*/
	short tcstmrat;                     /* ���ãû��ѵ��ı����ƻ륿����		*/
    char  tcstmrpu;						/* ��������ֳ�Ǽ�У��ֹ�			*/
	/************************************************************************/
	/*	TDC�ɲ�																*/
	/************************************************************************/
	char  tcstjnui;                   	/* ���㡼�ʥ������ס����׾���		*/
	/************************************************************************/
	long  tcstyob36;                    /* ͽ��								*/
    long  tcstyob37;                    /* ͽ��								*/
	short tcsttend;						/* ����Ź��ɽ�Ρ����ֹ�				*/
	char  tcstmrby;                     /* �Хå����å׻��У֣ңã�ͥ����	*/
	char  tcstbunh;						/* ����ʬ��ɽ��						*/
	long  tcstmrev;                     /* �ܥ�塼���ĺɴ�λ�Ԥ�����		*/
	char  tcstzcpn[8];                  /* ���䶨���Ѵ����ץ���������̾		*/
	long  tcst1siz;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�1��������		M01	*/
	long  tcst2siz;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�2��������		M01	*/
	long  tcst3siz;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�3��������		M01	*/
	long  tcst4siz;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�4��������		M01	*/
	long  tcst1unt;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�1�Ŀ�		M01	*/
	long  tcst2unt;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�2�Ŀ�		M01	*/
	long  tcst3unt;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�3�Ŀ�		M01	*/
	long  tcst4unt;						/* LICP�Îގ����ю̎ߎ��َʎގ��̎�4�Ŀ�		M01	*/
	char  tcstpsno;						/* LICP��ư�������������ʎߎ���	M01 */
    char  tcstyob38[31];				/* ͽ��								*/
/****************************************************************************/
/*	�������ԣģ��ɲ�ʬ													*/
/****************************************************************************/
	long  tcstlytm;						/* ��Ω���ֲ����Ԥ������ޡ��á�		*/
	long  tcstbftm;						/* �Хåե����ݥ�ȥ饤�ֳֻ��֡��á�*/
	long  tcstevno;						/* �Ύ��Ď����ݎʎގ�ͽ���ώ����͎ߎݎĎ޲�����͎ގݎ��ֹ�*/
	unsigned  char  tcstmtcl;			/* ���ƥʥ󥹥����ͥ��ס����׾���	*/
	char  tcstprch;						/* �������ԥץ������⡼��			*/
										/*	�����å��ס�����				*/
	char  tcstrber;						/* �ң£ɥե�����ξ������			*/
	char  tcstkjer;						/* �ˣʣ��Ÿξ������				*/
	char  tcstsrcv;						/* �ӣңãּ��Ի�����				*/
	char  tcstcnui;						/* ���Ÿξ��������ס����׾���	    */
    char  tcstityp;						/* �֣ңã���ʸ�������	TD90 CT1107 */
	char  tcstamdt;						/* �ޥ������ա����������������		*/
										/* �ޥ������ա������ǣ͡�			*/
										/* �������ա��������ǣ���			*/
	char  tcstvekd[8];					/* ���顼����������ʸ������			*/
										/*	���Хץ���������̾				*/
	short tcstrtry;						/* �ե����륢��������ȥ饤���		*/
	short tcstdely;						/* �ꥻ�åȻ���Ĺ����				*/
    char  tcstmclp[8];                  /* ��å���������ץ���������̾	TD18*/
	long  tcstmhwt;						/* ������ȴ����                 TD90*/
	long  tcstjnle;						/* ���㡼�ʥ�˥���������Ύ������� TD65*/
	long  tcstconn;						/* mc_conn��ȥ饤�ֳ�				*/
	char  tcstmrsp[8];					/* �Ў�-�����Ύގ؎�-�������ǽ��ʸ������AP*/
										/* �̎ߎێ�������̾				CT0868  */
};
typedef  struct  tcstpsz  TCSTPSZ;

/****************************************************************************/
/*  ���Ÿξ��������ס����׾���(tcstcnui)									*/
/****************************************************************************/
#define  TCSTJINT  0x80					/* JNL�������                      */
#define  TCSTRINT  0x40					/* RBI�������                      */
/****************************************************************************/
/*	�ӣңãּ��Ի����Ω���夲�ס�����(tcstsrcv)							*/
/****************************************************************************/
#define	 TCSTINEC  '0'					/* ���Ω���夲��					*/
#define  TCSTIUEC  '1'					/* ���Ω���夲����					*/
/****************************************************************************/
/*	�ꥫ�Х��ס����׾���(tcstrnui)											*/
/****************************************************************************/
#define  TCSTRNEC  '0'                  /* �ꥫ�Х���						*/
#define  TCSTRUEC  '1'                  /* �ꥫ�Х�����						*/
/****************************************************************************/
/*	���Ÿξ���ν���(tcst2err)												*/
/****************************************************************************/
#define  TCST2DWN  '0'                  /* �����ƥ�����󤹤�				*/
#define  TCST2NDW  '1'                  /* �����ƥ�����󤷤ʤ�				*/
/****************************************************************************/
/*	��ư�Ƴ��ס����׾���(tcstsnui)											*/
/****************************************************************************/
#define  TCSTSNEC  '0'                  /* ��ư�Ƴ�����						*/
#define  TCSTSUEC  '1'                  /* ��ư�Ƴ�������					*/
#define  TCSTSOEC  '2'					/* ����դ���ư�Ƴ�����				*/
/****************************************************************************/
/*	���������ס����׾���(tcstlnui)											*/
/****************************************************************************/
#define  TCSTLNEC  '0'                  /* ����������						*/
#define  TCSTLUEC  '1'                  /* ������������						*/
/****************************************************************************/
/****************************************************************************/
#define  TCSTMNEC  '0'                  /* �ʎގ��������̎�JNL �ώ��ݎĎ֎�        		*/
#define  TCSTMUEC  '1'                  /* �ʎގ��������̎�JNL �ώ��ݎĎ̎֎�       		*/
/****************************************************************************/
/*	�Хå����å��ס����׾���(tcstbnui)										*/
/****************************************************************************/
#define  TCSTBNEC  '0'                  /* �Хå����å���					*/
#define  TCSTBUEC  '1'                  /* �Хå����å�����					*/
/****************************************************************************/
/*	�Хå����å׻��У֣ңã�ͥ����(tcstmrby)								*/
/****************************************************************************/
#define  TCSTBKVR  '1'                  /* �Хå����å�ͥ��					*/
#define  TCSTVRBK  '0'                  /* �֣ңã�ͥ��						*/
/****************************************************************************/
/*	�ܥ�塼�ॳ�ԡ���Ӹ����ѥե饰(tcstmrbv)								*/
/****************************************************************************/
/*  ���ǥ������֤Υ��ԡ��ѻߤ�ȼ�����(2��)									*/
/****************************************************************************/
/*	�ʣΣ̥Хå����åץ⡼��(tcstmrjb)										*/
/****************************************************************************/
#define  TCSTJBKS  'S'                  /* �ҷϣʣΣ̤ΤߥХå����å�		*/
#define  TCSTJBKD  'D'                  /* ξ�ϣʣΣ̤�Хå����å�			*/
/****************************************************************************/
/*	�֣ңã�����⡼��(tcstmrvm)											*/
/****************************************************************************/
#define  TCSTVMRJ  '0'                  /* �ꥹ�ȥ����ƣ�����Ϣ³			*/
#define  TCSTVMOL  '1'                  /* �ꥹ�ȥ����ƣ�����ñ��			*/
/****************************************************************************/
/*	���ƥʥ󥹥����ͥ��ס����׾���										*/
/****************************************************************************/
#define	 TCSTMKNE  '1'					/*	���ƥʥ󥹥����ͥ���			*/
#define	 TCSTMKNN  '0'					/*	���ƥʥ󥹥����ͥ�����		*/
/****************************************************************************/
/*	�������ԥץ������⡼�ɥ����å��ס����׾���							*/
/****************************************************************************/
#define  TCSTPRNE  '1'					/*	�����å���						*/
#define	 TCSTPRNN  '0'					/*	�����å�����					*/
/****************************************************************************/
/*	�ң£ɥե�����ξ������												*/
/****************************************************************************/
#define  TCSTRDWN  '0'					/*	�����ƥ�����󤹤�				*/
#define	 TCSTRNDW  '1'					/*	�����ƥ�����󤷤ʤ�			*/
/****************************************************************************/
/*	�ˣʻ��Ѿ���(tcstkjus)													*/
/****************************************************************************/
#define	 TCSTKJUSE	0x01				/*  �ˣʤ���Ѥ���		TD42 CT0809	*/
/****************************************************************************/
/*	�֣ңã���ʸ�������(tcstityp)											*/
/****************************************************************************/
#define	 TCSTPVIF	0x00				/*  �����Ύގ؎����Ѿ���ʤ�TD90 CT1107	*/
#define	 TCSTVMIF	0x01				/*  �����Ύގ؎����Ѿ��󤢤�TD90 CT1107	*/
/****************************************************************************/
/*	�ơ��֥�ꥫ�Х��ס����׾���(tcsttrcv)						PRC-058-01	*/
/****************************************************************************/
#define	 TCSTTRNE  'Y'					/* �ơ��֥�ꥫ�Х���				*/
#define	 TCSTTRNN  'N'					/* �ơ��֥�ꥫ�Х�����				*/