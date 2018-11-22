/****************************************************************************/
/*	�ޥ����������塼�鳰���ΰ�����إå�									*/
/*																			*/
/*		�ѹ��� : ����  ����				'96/02/07	---	ST3699				*/
/*		�ѹ��� : ����  ����				'96/03/11	---	ST4174				*/
/*		�ѹ��� : ����  ����				'96/04/05	---	ST4207				*/
/*		�ѹ��� : ����  ����				'96/04/22	---	CT1215(ST4306)		*/
/*		�ѹ��� : ����  ����				'96/05/08	---	CT1222(ST4317)		*/
/*		�ѹ��� : Com'App ����			'96/07/11	---	ST4451				*/
/*�㥽����������̾��				Com'App �ⶶ 					 		*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ  �������		ST4861   	*/
/*																			*/
/* �㥽����������̾��				 �Ķ�Ź�����ƥ���������(KSP)			*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������			ST5270	*/
/*	LICP��λ�Ԥ��������Τ�����ѿ�"molidcnt"���ɲä���						*/
/*																			*/
/* �㥽����������̾��               �Ķ�Ź�����ƥ���  ����(KSP)				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ� ��������ǯ���������  		ST5972	*/
/*   ���ｪλ�����¹ԺѤ�ɽ�����ɲä���										*/
/****************************************************************************/
/****************************************************************************/
/* �ץ�������̾����                                                       */
/* �ץ���̾���������ޥ����������塼��                                     */
/* ��¤�ֹ桡��������PRC-008-05                                             */
/* ��¤���ơ����������ԣң��ģť��ߥ�졼�ȤΥ����ƥ൯ư�������������     */
/*                   ����֥͡ơ��֥��Ǽ�Ѷ��ѥ���ID���ɲ�               */
/* ��¤��������������2002.10.30                                             */
/* ��¤�ԡ�����������supply Tanoue                                          */
/****************************************************************************/
/****************************************************************************/
/* �����ѹ��ֹ�	   : SSLA0039												*/
/* ��������		   : ��λ������������Ƴ��ϥե饰���ɲ�					*/
/* ������		   : 2003.06.30												*/
/* ������		   : supply Sugawara										*/
/****************************************************************************/

#include	"mochar.h"

extern	long	modtecnt;				/* ���ա���������Ŀ�				*/
extern	PSCPSECT	pscparea;			/* �Уӣţã�						*/
extern	MOPSCPCB	*mopcbp;			/* �ͣϣУã���Ƭ���ɥ쥹			*/
extern	TCOMPAT	*moadtp;				/* �ԣ��ģ���Ƭ���ɥ쥹				*/
extern	TCOMPAT	*moladtp;				/* �ԣ��ģ���Ƭ���ɥ쥹(LM)			*/
extern	TCOMPAT	*mosstp;				/* �ԣӣӣ���Ƭ���ɥ쥹				*/
extern	TSSTPSZ	*mosstkp;				/* �ԣӣӣԸ��������ɥ쥹			*/
extern	TCOMPAT	*mocstp;				/* �ԣãӣ���Ƭ���ɥ쥹				*/
extern	TCSTPSZ	*mocstkp;				/* �ԣãӣԸ��������ɥ쥹			*/
extern	TCOMPAT	*mopctp;				/* �ԣУã���Ƭ���ɥ쥹				*/
extern	TPCTSUB	*mopctsp;				/* TPCT���ֶ��������ɥ쥹			*/	
extern	TPCTPSZ	*mopctkp;				/* �ԣУãԸ��������ɥ쥹			*/	
extern	TCOMPAT	*mocmtp;				/* �ԣãͣ���Ƭ���ɥ쥹				*/
extern	TCOMPAT	*motrtp;				/* �ԣԣң���Ƭ���ɥ쥹				*/
extern	TCOMPAT	*mobptp;				/* �ԣ£У���Ƭ���ɥ쥹				*/
extern	TCOMPAT	*mosrtp;				/* �ԣӣң���Ƭ���ɥ쥹				*/
extern	TSRTPSZ *mosrtkp;				/* �ԣӣңԸ��������ɥ쥹			*/
extern	TCOMPAT	*moputp;				/* �ԣУգ���Ƭ���ɥ쥹				*/
extern	TCOMPAT	*moshmp;				/* �ԣӣȣ���Ƭ���ɥ쥹				*/
extern	TCOMPAT *molmtp;				/* �ԣ̣ͣ���Ƭ���ɥ쥹				*/
extern	long	momsmb;					/* �ͣӥᥤ��ܥå���ID				*/
extern	long	mokkmb;					/* �ϴִƻ�ᥤ��ܥå���ID			*/
extern	long	moksmb;					/* �ϴ��̿��ᥤ��ܥå���ID			*/
extern	long	moermb;					/* �ӣͣ������ѥᥤ��ܥå���ID		*/
extern	long	momrhkmb;				/* �ӣͣ�������α�ѥᥤ��ܥå���ID	*/
extern	long	modestms[16];			/* ���ϣͣ��ѥᥤ��ܥå���ID		*/
extern	long	modestkk[16];			/* ���Ϸϴִƻ��ѥᥤ��ܥå���ID	*/
extern	MOPINF	moorig;					/* ��ư���ץ�������				*/
extern	UCHR	montc;					/* ���Σԣ��ֹ�						*/
extern	long	modpfid;				/* �ե����뵭�һ�					*/
extern	long	mordtbl[MOMSRDC];		/* MS��ꥯ�����ȼ��̻ҳ�Ǽ�ơ��֥�	*/
extern	UCHR	mordflg[MOMSRDC];		/* MS��ꥯ�����ȼ��̻��׵�ե饰	*/
extern	long	momspid;				/* �ͣӥץ������̻�				*/
extern	long	modpcod;				/* ɽ���ԲĻ������󥳡��ɳ�Ǽ��		*/
extern	long	modpdtl;				/* ɽ���ԲĻ��ܺپ����Ǽ��			*/
extern	UCHR	momrinf;				/* �ߥ顼Ʊ���ס����׾���			*/
extern	UCHR	momstmst;				/* ��λ���ơ�����					*/
extern	UCHR	*mormgp;				/* ��å������������ꥢ�ݥ���		*/
extern	long	mormgl;					/* ��å������������ꥢ��Ĺ��		*/
extern	UCHR	*mosmgp;				/* ��å������������ꥢ�ݥ���		*/
extern	long	mosmgl;					/* ��å������������ꥢ�ݥ���		*/
extern	UCHR	momsdvst;				/* ��ž���ơ�����					*/
extern	UCHR	momsdvst2;				/* ��ž���ơ�����			CT1222	*/
extern	UCHR	*morosmp;				/* �ԣң��ģŤ���Σӣͣ�����		*/
extern	UCHR	modev;					/* Ω���夲�϶�ʬ					*/
extern	long	momode;					/* ���ϥץ����⡼��				*/
extern	long	mopmode[16];			/* ���ϥץ����⡼��			*/
extern	UCHR	moschin;				/* �������ס����׾���				*/
extern	UCHR	mostart;				/* ���϶�ʬ							*/
extern	long	movtpbid;				/* �٥����ơ��֥�ס���Хåե����̻�*/
extern	UCHR	modtl[4];				/* ���顼��å������ɣĳ�Ǽ��		*/
extern	UCHR	mocrpnm[9];				/* �ץ�������̾					*/
extern	TPCTPSZ	*mocrpct;				/* �����ץ����ԣУãԸ�����		*/
extern	long	motrinf[4];				/* ���顼�ܺپ���					*/
extern	UCHR	mocmid[9];				/* �ãͶ��ѥ��꼱�̻�				*/
extern	UCHR	mocmadd[9];				/* �ãͶ��ѥ�����Ƭ���ɥ쥹		*/
extern	long	momsgflg;				/* ��å��������ϲ�ǽ�ե饰			*/
extern	long	monotpu;				/* �У�����							*/
extern	long	mozintrc;				/* STC238							*/
extern	char	momdtbl[16][16];		/* �ץ����⡼�ɥ����å��ơ��֥�	*/
extern	UCHR	modate[15];				/* ���ѷ�������������				*/
extern	UCHR	mochginf;				/* ���ظ��ѷϾ���					*/
extern	SCHR	modatpnm[]; 			/* ���ջ���ե�����ե�ѥ�̾		*/
extern	UCHR	moside;					/* �ҷ�Ω���夲����					*/
extern	UCHR	moform;					/* �����ƥ๽������					*/
extern	UCHR	mocmdtbl[MOCMDNO*16];	/* ���ޥ�ɥե�����̾�ơ��֥�		*/
extern	UCHR	mokinf[15][16];			/* �����ؾ���ơ��֥�				*/
extern	UCHR	mokno[2];				/* ���ϥȥꥬ						*/
extern	UCHR	motfmcnd[3];			/* �ơ��֥�ե���������ˤξ���		*/
extern	UCHR	motfscnd[3];			/* �ơ��֥�ե���������ˤξ���		*/
										/*				ST3431				*/
extern	UCHR	motl0fmcnd[3];			/* �ơ��֥�ե���������ˤξ���(L0)	*/
extern	UCHR	motl0fscnd[3];			/* �ơ��֥�ե���������ˤξ���(L0)	*/
extern	UCHR	motl1fmcnd[3];			/* �ơ��֥�ե���������ˤξ���(L1)	*/
extern	UCHR	motl1fscnd[3];			/* �ơ��֥�ե���������ˤξ���(L1)	*/
										/*				ST3431				*/
extern	UCHR	mosyserr1[9];			/* �ơ��֥���ɥ��顼����(��)		*/
extern	UCHR	mosyserr2[9];			/* �ơ��֥���ɥ��顼����(��)		*/
extern	UCHR	mol0syserr1[9];			/* �ơ��֥���ɥ��顼����(L0��)	*/
extern	UCHR	mol0syserr2[9];			/* �ơ��֥���ɥ��顼����(L0��)	*/
extern	UCHR	mol1syserr1[9];			/* �ơ��֥���ɥ��顼����(L1��)	*/
extern	UCHR	mol1syserr2[9];			/* �ơ��֥���ɥ��顼����(L1��)	*/
extern	UCHR	motfeflg;				/* �ơ��֥���ɥ��顼�ե饰		*/
										/*				ST3431				*/
extern	UCHR	motl0feflg;				/* �ơ��֥���ɥ��顼�ե饰(L0)	*/
extern	UCHR	motl1feflg;				/* �ơ��֥���ɥ��顼�ե饰(L1)	*/
extern	UCHR	modsts;					/* �����󥹥ơ�����		CT0881		*/
extern	long	moutfinf;				/* ���ѥơ��֥�ե�����Σ�			*/
extern	long	mofeinf[2];				/* �ơ��֥�ե����륨�顼����		*/
extern	long	mofidp[2];				/* �ե����뵭�һҥ��ɥ쥹�ꥹ��		*/
extern	long	mofduse;				/* ���ѥե����뵭�һ�				*/
extern	long	mofcnd[2];				/* �ե��������						*/
extern	long	lmfcnd[2];				/* �ե��������				ST4207	*/
extern	long	motldrc;				/* �ơ��֥�����ֵ���				*/
extern	long	morscno;				/* ���ֹ�							*/
extern	long	mosmpbid;				/* �ӣͣХ����ƥ�ե������ѥס���ID	*/
extern	long	momsgbid;				/* �ӣͣ������ѥס���ɣ�			*/
extern	long	mokkpid;				/* �ϴִƻ�ץ����ɣ�				*/
extern	long	modrvmd;				/* ���б�ž�⡼��					*/
extern	SCHR	*movctp;				/* �ԣ֣ã���Ƭ���ɥ쥹				*/
extern	SCHR	*molvctp;				/* �ԣ֣ã���Ƭ���ɥ쥹(LM)			*/
extern	SMPSYSF	*mosysp;				/* SMP�����ƥ�ե�������Ƭ���ɥ쥹	*/
extern	MOTGSAM	*mosamp;				/* Ω���夲Ʊ��������Ƭ���ɥ쥹		*/
extern	MOTGMSG	*morosp;				/* �ԣң��ģŤ����������Ƭ���ɥ쥹	*/
extern	MTPLST	molist;					/* �ơ��֥���ɥѥ�᥿			*/
extern	MTPLST	lmlist;					/* �ơ��֥���ɥѥ�᥿(LM)		*/
extern	long	mocmmid;				/* CM�ơ��֥붦�ѥ���ID(1)		*/
extern	long	mocmmad;				/* CM�ơ��֥�ޥåԥ󥰥��ɥ쥹(1)	*/
extern	UCHR	mommno;					/* ���������ֹ�						*/
extern	UCHR	moomno[16];				/* ���������ֹ�					*/
extern	long	moparmc;				/* �ѥ�᥿�Ŀ�						*/

extern	long	molmparmc;				/* �ѥ�᥿�Ŀ�(LM)					*/
extern	UCHR	modisflg;				/* �У����ץ�����λ�ե饰			*/
extern	UCHR	mokcflg;				/* �����ذ���ե饰					*/
extern	TCOMPAT	*moabpp;				/* �ԣ��£���Ƭ���ɥ쥹				*/
extern	UCHR	modapjflg;				/* JNL��Ÿξ�ե饰				*/
extern	UCHR	modaprflg;				/* RBI��Ÿξ�ե饰				*/
extern	UCHR	modapkflg;				/* KJ��Ÿξ�ե饰					*/
extern	char	*moparent[1024];		/* ��ư�ѥ�᥿����ȥ�				*/
extern	long	moridfast[16];			/* ��Ω���ֲ����Ԥ�					*/
										/* 		�����ޥꥯ������ID�ơ��֥�	*/
extern	UCHR	mochbno;				/* �����оݥ֥�å���ʬ				*/
extern	char	moinit;					/* �ɣΣɣԡ���ȯ����ե饰			*/
extern	char	moinitb[9];				/* �ɣΣɣԡ���ȯ�Ը��ץ�������̾	*/
extern	UCHR	momtrm[4];				/* �㳲����ü�Ҿ���ơ��֥�			*/
extern	UCHR	momotrm[4];				/* ����ü�Ҿ���ơ��֥�	CT1193		*/
extern	UCHR	moupstyp;				/* �գУӥ����׾���					*/
extern	long	mopwwt;					/* �����Ÿ������Ԥ���������			*/
extern	long	mosmsmb;				/* ���֣ͣӥᥤ��ܥå����ɣ�		*/
extern	TPCTPSZ *momgtptr;				/* �ͣӣ�����������ݥ���			*/
extern	UCHR	mosystime[5];			/* �����ƥ�Ω���夲���ѻ���			*/
extern	UCHR	morestime[5];			/* �쥹�ݥ��Ԥ�����				*/
extern	long	modefpmd[16];			/* �ǥե���ȥץ����⡼��		*/
extern	UCHR	moblckno;				/* ���ϥ֥�å��ֹ�					*/
extern	short	mortmgno;				/* ���ޥ�ɼ¹Է���ֵ���ʸ��		*/
extern	long	modispr;				/* ��λ�ץ�����					*/
extern	long	momrhflg;				/* �ξ��������ϣ�ե饰			*/
extern	MSSTSYNC	mssync;				/* Ω���夲Ʊ������ɽ				*/
extern	long	motldflg;				/* �ơ��֥���ɺѤߥե饰			*/
extern	UCHR	mokkpn[48];				/* �ϴִƻ�ץ����ե�����̾		*/
extern	UCHR	mokkpi[8];				/* �ϴִƻ�ץ���̾				*/
extern	UCHR	mosyctime[5];			/* Ʊ���Ԥ�����						*/
extern	MTERRT	mterrtbl;				/* �ơ��֥�LOAD/SAVE���顼����		*/
extern	MTERRT	mtertbcm;				/* �ơ��֥�LOAD/SAVE				*/
										/* 			���顼����(CM)  CT1047	*/
extern	MTERRT	mtertblm;				/* �ơ��֥�LOAD/SAVE				*/
										/* 			���顼����(LM)  CT1047	*/
extern  struct  terminf  termcod;		/* ��λ����							*/
extern	long	molmfidp[2];			/* �ե����뵭�һҳ�Ǽ���ꥢ			*/
extern	long	molpid;					/* LM�٥����ơ��֥��ѥХåե�ID		*/
extern	TLMTPSZ *molmtinp;				/* ��PuLM����LMT�������ݥ���		*/
extern	char	moosti[16];				/* �֥�å����־���					*/
extern	long	*mosyspbp;				/* SMP�����ƥ�ե�������			*/
										/* 			�ס���Хåե����ɥ쥹	*/
extern	TCOMPAT	*movmtp;				/* TVMT��Ƭ���ɥ쥹					*/
extern	TCOMPAT *mofmtp;				/* TFMT��Ƭ���ɥ쥹					*/
extern	TCOMPAT *mowmtp;				/* TWMT��Ƭ���ɥ쥹					*/
extern	UCHR	mosbmsflg;				/* ��ư��λ���κѤߥե饰			*/
extern	TCMTPSZ	*moppcmt;				/* �ԣãͣԸ������ݥ���			*/
extern	long	mosmpkpmb;				/* SMP������α�ѥᥤ��ܥå���ID	*/
extern	TPCTPSZ	*mocprpct;				/* �����ץ���TPCT����ȥꥢ�ɥ쥹	*/
extern	long	motrybms;				/* ͽ���Ͻ�λ��������ե饰			*/
extern	long	moctmnt;				/* �ãͥơ��֥�ޥ���ȥե饰		*/
extern	long	moltmnt;				/* �ãͥơ��֥�ޥ���ȥե饰		*/
extern	short	moecmt;					/* �ԣãͣԥ���ȥ��ֹ�				*/
extern	long	mohsnsp;				/* HSξ�ϥץ����⡼���԰��ץե饰*/
extern	long	mooscprcd;				/* mo_crep�Ǥ�oscrepr�ֵ��� CT0597	*/
extern	long	mooscmdflg;				/* �ϣӥ��ޥ�ɥե饰	CT0597		*/
extern	short	momrmcnt;				/* ��ԥꥫ�Х굯ư��				*/
										/*						CT0881		*/
extern	UCHR	mospmfdk[32];			/* �ӣУ�����ե�����ܥ�塼��̾	*/
extern	UCHR	mospmfdr[32];			/* �ӣУ�����ե�����ǥ��쥯�ȥ�̾	*/
extern	UCHR	mospmfps[32];			/* �ӣУ�����ե�����ե�ѥ�̾		*/
extern	long	momsld2rcd;				/* mr_msld2�꥿���󥳡���			*/
extern	long	momsldrcd;				/* mr_msld�꥿���󥳡���			*/
extern	long	mocdbeflg;				/* ��Է�¸��ǧ���ե饰				*/
extern	long	moybwtime;				/* ͽ�����Ԥ�����			ST3589	*/
extern	long	moadwtime;				/* ���ϥ������Ԥ�����		CT1193	*/
extern	long	moadwflg;				/* ���ϥ������Ԥ��ե饰	CT1193	*/
extern	UCHR	mospmflg;				/* �����ΰ�������Ѥߥե饰 ST3589*/
extern	UCHR	moadwcnui;				/* ���ϥ���������ס����׾���		*/
										/*			CT1193					*/
extern	UCHR	mosmadflg;				/* Ω���夲Ʊ��������				*/
										/*			���������ե饰CT1193	*/
extern	UCHR	mosyflg;				/* ξ��Ʊ��Ω���夲�ե饰	ST3800	*/
extern	char	mojrof;					/* �ʣΣ̺ƥ����ץ�ե饰	ST3699	*/
extern	long	moneflg;				/* ���ｪλ�ե饰			ST4174	*/
#include	"msexmsg.h"					/* �ӣãХ�å�����					*/
extern	char	movdaylm[6];			/* VCT����(LM)				CT1215	*/
extern	long	movdayflg;				/* VCT���եե饰			CT1215	*/
extern	char	momscmskb;				/* VCT���϶�ʬ(CM)			CT1222	*/
extern	char	momslmskb;				/* VCT���϶�ʬ(LM)			CT1222	*/

extern	char	momrsflg;				/* �ߥ顼Ʊ����λɽ��		ST4451	*/

extern	char	moicpflg;				/* �ɣãХץ������֥ե饰	ST4861	*/
extern	long	molidcnt;				/* �̣ɣãн�λ�Ԥ���		ST5270	*/

extern	long	motrfflg;				/* ���ｪλ�¹ԺѤ�ɽ��		ST5972	*/
extern	long	moshmemid;				/* �ơ��֥��Ǽ�Ѷ��ѥ���ID			PRC-008-05 */
extern	long	mostendflg;				/* ��λ������������Ƴ��� SSLA0039*/

