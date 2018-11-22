/****************************************************************************/
/*	�ޥ����������塼�鳰���ΰ�����إå�									*/
/*																			*/
/*		�ѹ��� : ����  ����				'96/02/07	--- ST3699				*/
/*		�ѹ��� : ����  ����				'96/03/11	--- ST4174				*/
/*		�ѹ��� : ����  ����				'96/03/21	--- ST4194				*/
/*		�ѹ��� : ����  ����				'96/04/05	--- ST4207				*/
/*		�ѹ��� : ����  ����				'96/04/22	--- CT1215(ST4306)		*/
/*		�ѹ��� : ����  ����				'96/05/08	--- CT1222(ST4317)		*/
/*		�ѹ��� : Com'App ����			'96/07/11	--- ST4451				*/
/*�㥽����������̾��				Com'App �ⶶ 					 		*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ  �������		ST4861   	*/
/*																			*/
/* �㥽����������̾��				 �Ķ�Ź�����ƥ���������(KSP)			*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������			ST5270	*/
/*	LICP��λ�Ԥ��������Τ�����ѿ�"molidcnt"���ɲä���						*/
/*																			*/
/* �㥽����������̾��               �Ķ�Ź�����ƥ���  ����(KSP)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ� ��������ǯ���������          ST5972  */
/*   ���ｪλ�����¹ԺѤ�ɽ�����ɲä���                                     */
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
/* �����ѹ��ֹ�    : SSLA0039												*/
/* ��������		   : ��λ������������Ƴ��ϥե饰���ɲ�				  	*/
/* ������		   : 2003.06.30												*/
/* ������		   : supply Sugawara										*/
/****************************************************************************/

#include	"mochar.h"

long	mosysdte[30][3];				/* ���ա��������ꥨ�ꥢ				*/
long	modtecnt;						/* ���ա���������Ŀ�				*/
TCOMPAT	*moadtp;						/* �ԣ��ģ���Ƭ���ɥ쥹				*/
TCOMPAT	*moladtp;						/* �ԣ��ģ���Ƭ���ɥ쥹(LM)			*/
TCOMPAT	*mosstp;						/* �ԣӣӣ���Ƭ���ɥ쥹				*/
TSSTPSZ	*mosstkp;						/* �ԣӣӣԸ��������ɥ쥹			*/
TCOMPAT	*mocstp;						/* �ԣãӣ���Ƭ���ɥ쥹				*/
TCSTPSZ	*mocstkp;						/* �ԣãӣԸ��������ɥ쥹			*/
TCOMPAT	*mopctp;						/* �ԣУã���Ƭ���ɥ쥹				*/
TPCTSUB	*mopctsp;						/* TPCT���ֶ��������ɥ쥹			*/	
TPCTPSZ	*mopctkp;						/* �ԣУãԸ�������Ƭ���ɥ쥹		*/	
TCOMPAT	*mocmtp;						/* �ԣãͣ���Ƭ���ɥ쥹				*/
TCOMPAT	*motrtp;						/* �ԣԣң���Ƭ���ɥ쥹				*/
TCOMPAT	*mobptp;						/* �ԣ£У���Ƭ���ɥ쥹				*/
TCOMPAT	*mosrtp;						/* �ԣӣң���Ƭ���ɥ쥹				*/
TSRTPSZ *mosrtkp;						/* �ԣӣңԸ��������ɥ쥹			*/
TCOMPAT	*moputp;						/* �ԣУգ���Ƭ���ɥ쥹				*/
TCOMPAT	*moshmp;						/* �ԣӣȣ���Ƭ���ɥ쥹				*/
TCOMPAT *molmtp;						/* �ԣ̣ͣ���Ƭ���ɥ쥹				*/
long	momsmb;							/* �ͣӥᥤ��ܥå����ɣ�			*/
long	mokkmb;							/* �ϴִƻ�ᥤ��ܥå����ɣ�		*/
long	moksmb;							/* �ϴ��̿��ᥤ��ܥå����ɣ�		*/
long	moermb;							/* �ӣͣ������ѥᥤ��ܥå����ɣ�	*/
long	momrhkmb;						/* �ӣͣ�������α�юҎ��َΎގ������ɣ�		*/
long	modestms[16];					/* ���ϣͣ��ѥᥤ��ܥå����ɣ�	*/
long	modestkk[16];					/* ���Ϸϴִƻ��ѥᥤ��ܥå����ɣ�*/
MOPINF	moorig;							/* ��ư���ץ�������				*/
UCHR	montc;							/* ���Σԣ��ֹ�						*/
long	modpfid;						/* �ե����뵭�һ�					*/
long	mordtbl[MOMSRDC];				/* �ͣ���؎������ļ��̻ҳ�Ǽ�ơ��֥�	*/
UCHR	mordflg[MOMSRDC];				/* �ͣ���؎������ļ��̻��׵�ե饰		*/
long	momspid;						/* �ͣӥץ������̻�				*/
long	modpcod;						/* ɽ���ԲĻ������󥳡��ɳ�Ǽ��		*/
long	modpdtl;						/* ɽ���ԲĻ��ܺپ����Ǽ��			*/
long	modispr;						/* ��λ�ץ�����					*/
UCHR	momrinf;						/* �ߥ顼Ʊ���ס����׾���			*/
UCHR	momstmst;						/* ��λ���ơ�����					*/
UCHR	*mormgp;						/* ��å������������ꥢ�ݥ���		*/
long	mormgl;							/* ��å������������ꥢ��Ĺ��		*/
UCHR	*mosmgp;						/* ��å������������ꥢ�ݥ���		*/
long	mosmgl;							/* ��å������������ꥢ�ݥ���		*/
UCHR	momsdvst;						/* ��ž���ơ�����					*/
UCHR	momsdvst2;						/* ��ž���ơ�����			CT1223	*/
UCHR	*morosmp;						/* �ԣң��ģŤ���Σӣͣ�����		*/
UCHR	modev;							/* Ω���夲�϶�ʬ					*/
long	momode;							/* ���ϥץ����⡼��				*/
long	mopmode[16];					/* ���ϥץ����⡼��			*/
UCHR	moschin;						/* �������ס����׾���				*/
UCHR	mostart;						/* ���϶�ʬ							*/
long	movtpbid;						/* �٥����ơ��֥�ס���Хåե����̻�*/
UCHR	modtl[4];						/* ���顼��å������ɣĳ�Ǽ��		*/
UCHR	mocrpnm[9];						/* �ץ�������̾					*/
TPCTPSZ	*mocrpct;						/* �����ץ����ԣУãԸ�����		*/
long	motrinf[4];						/* ���顼�ܺپ���					*/
UCHR	mocmid[9];						/* �ãͶ��ѥ��꼱�̻�				*/
UCHR	mocmadd[9];						/* �ãͶ��ѥ�����Ƭ���ɥ쥹		*/
long	momsgflg;						/* ��å��������ϲ�ǽ�ե饰			*/
long	monotpu;						/* �У�����							*/
long	mozintrc;						/* STC238							*/
char	momdtbl[16][16];				/* �ץ����⡼�ɥ����å��ơ��֥�	*/
UCHR	modate[15];						/* ���ѷ�������������				*/
UCHR	mochginf;						/* ���ظ��ѷϾ���					*/
SCHR	modatpnm[] = "/mosysdte"; 		/* ���ջ���ե�����ե�ѥ�̾		*/
UCHR	moside;							/* �ҷ�Ω���夲����					*/
UCHR	moform;							/* �����ƥ๽������					*/
UCHR	mocmdtbl[MOCMDNO*16];			/* ���ޥ�ɥե�����̾�ơ��֥�		*/
UCHR	mokinf[15][16];					/* �����ؾ���ơ��֥�				*/
UCHR	mokno[2];						/* ���ϥȥꥬ						*/
UCHR	motfmcnd[3];					/* �ơ��֥�ե���������ˤξ���		*/
UCHR	motfscnd[3];					/* �ơ��֥�ե���������ˤξ���		*/
										/*				ST3431				*/
UCHR	motl0fmcnd[3];					/* �ơ��֥�ե���������ˤξ���(L0)	*/
UCHR	motl0fscnd[3];					/* �ơ��֥�ե���������ˤξ���(L0)	*/
UCHR	motl1fmcnd[3];					/* �ơ��֥�ե���������ˤξ���(L1)	*/
UCHR	motl1fscnd[3];					/* �ơ��֥�ե���������ˤξ���(L1)	*/
										/*				ST3431				*/
UCHR	mosyserr1[9];					/* �ơ��֥���ɥ��顼����(CM��)	*/
UCHR	mosyserr2[9];					/* �ơ��֥���ɥ��顼����(CM��)	*/
UCHR	mol0syserr1[9];					/* �ơ��֥���ɥ��顼����(L0��)	*/
UCHR	mol0syserr2[9];					/* �ơ��֥���ɥ��顼����(L0��)	*/
UCHR	mol1syserr1[9];					/* �ơ��֥���ɥ��顼����(L1��)	*/
UCHR	mol1syserr2[9];					/* �ơ��֥���ɥ��顼����(L1��)	*/
UCHR	motfeflg;						/* �ơ��֥���ɥ��顼�ե饰		*/
										/*				ST3431				*/
UCHR	motl0feflg;						/* �ơ��֥���ɥ��顼�ե饰(L0)	*/
UCHR	motl1feflg;						/* �ơ��֥���ɥ��顼�ե饰(L1)	*/
UCHR	modsts;							/* �����󥹥ơ�����		CT0881		*/
long	moutfinf;						/* ���ѥơ��֥�ե�����Σ�			*/
long	mofeinf[2];						/* �ơ��֥�ե����륨�顼����		*/
long	mofidp[2];						/* �ե����뵭�һҥ��ɥ쥹�ꥹ��		*/
long	mofduse;						/* ���ѥե����뵭�һ�				*/
long	mofcnd[2];						/* �ե��������						*/
long	lmfcnd[2];						/* 							ST4207	*/
long	motldrc;						/* �ơ��֥�����ֵ���				*/
long	morscno;						/* ���ֹ�							*/
long	mosmpbid;						/* �ӣͣХ����ƥ�ե������ѥס���ɣ�*/
long	momsgbid;						/* �ӣͣ������ѥס���ɣ�			*/
long	mokkpid;						/* �ϴִƻ�ץ����ɣ�				*/
long	modrvmd;						/* ���б�ž�⡼��					*/
SCHR	*movctp;						/* �ԣ֣ã���Ƭ���ɥ쥹				*/
SCHR	*molvctp;						/* �ԣ֣ã���Ƭ���ɥ쥹(LM)			*/
SMPSYSF	*mosysp;						/* �ӣͣХ����ƥ�ե�������Ƭ���ɥ쥹*/
MOTGSAM	*mosamp;						/* Ω���夲Ʊ��������Ƭ���ɥ쥹		*/
MOTGMSG	*morosp;						/* �ԣң��ģŤ����������Ƭ���ɥ쥹	*/
MTPLST	molist;							/* �ơ��֥���ɥѥ�᥿			*/
MTPLST	lmlist;							/* �ơ��֥���ɥѥ�᥿(LM)		*/
MTERRT	mtertbcm;						/* �Î��̎ގ�LOAD/SAVE���׎�����(CM)  CT1047*/
MTERRT	mtertblm;						/* �Î��̎ގ�LOAD/SAVE���׎�����(LM)  CT1047*/
long	mocmmid;						/* �ãͥơ��֥붦�ѥ���ɣġʣ���	*/
long	mocmmad;						/* �ãͥơ��֥�ώ��ˎߎݎ��ގ��Ďގڎ��ʣ���	*/
UCHR	mommno;							/* ���������ֹ�						*/
UCHR	moomno[16];						/* ���������ֹ�					*/
long	moparmc;						/* �ѥ�᥿�Ŀ�						*/

long	molmparmc;						/* �ѥ�᥿�Ŀ�(LM)					*/
UCHR	modisflg;						/* �У����ץ�����λ�ե饰			*/
UCHR	mokcflg;						/* �����ذ���ե饰					*/
TCOMPAT	*moabpp;						/* �ԣ��£���Ƭ���ɥ쥹				*/
UCHR	modapjflg;						/* JNL��Ÿξ�ե饰				*/
UCHR	modaprflg;						/* RBI��Ÿξ�ե饰				*/
UCHR	modapkflg;						/* KJ��Ÿξ�ե饰					*/
char	*moparent[1024];				/* ��ư�ѥ�᥿����ȥ�				*/
long	moridfast[16];					/* ��Ω���ֲ����Ԥ������ώ؎�������ID�Î��̎ގ�	*/
UCHR	mochbno;						/* �����оݥ֥�å���ʬ				*/
char	moinit;							/* �ɣΣɣԡ���ȯ����ե饰			*/
char	moinitb[9];						/* �ɣΣɣԡ���ȯ�Ը��ץ�������̾	*/
UCHR	momtrm[4];						/* �㳲����ü�Ҿ���ơ��֥�			*/
UCHR	momotrm[4];						/* ����ü�Ҿ���Î��̎ގ�	CT1193		*/
UCHR	moupstyp;						/* �գУӥ����׾���					*/
long	mopwwt;							/* �����Ÿ������Ԥ���������			*/
long	mosmsmb;						/* ���֣ͣӥᥤ��ܥå����ɣ�		*/
TPCTPSZ	*momgtptr;						/* �ͣӣ�����������ݥ���			*/
UCHR	mosystime[5];					/* �����ƥ�Ω���夲���ѻ���			*/
UCHR	morestime[5];					/* �쥹�ݥ��Ԥ�����				*/
long	modefpmd[16];					/* �ǥե���ȥץ����⡼��		*/
UCHR	moblckno;						/* ���ϥ֥�å��ֹ�					*/
short	mortmgno;						/* ���ޥ�ɼ¹Է���ֵ���ʸ��		*/
long	modispr;						/* ��λ�ץ�����					*/
long	momrhflg;						/* �ξ��������ϣ˥ե饰			*/
MSSTSYNC	mssync;						/* Ω���夲Ʊ������ɽ				*/
long	motldflg;						/* �ơ��֥���ɺѤߎ̎׎���			*/
UCHR	mokkpn[48];						/* �ϴִƻ�ץ����ե�����̾		*/
UCHR	mokkpi[8];						/* �ϴִƻ�ץ���̾				*/
UCHR	mosyctime[5];					/* Ʊ���Ԥ�����						*/
long	molmfidp[2];					/* �̎����ٵ��һҳ�Ǽ���ꥢ				*/
long	molpid;							/* LM�͎ގ����Î��̎ގ��юʎގ��̎�ID				*/
TLMTPSZ *molmtinp;						/* ��PuLM����LMT�������ݥ���		*/
char	moosti[16];						/* �̎ގێ������־���					*/
long	*mosyspbp;						/* SMP�����Îю̎������ю̎ߎ��َʎގ��̎����Ďގڎ�		*/
TCOMPAT *movmtp;						/* TVMT��Ƭ���Ďގڎ�					*/
TCOMPAT *mofmtp;						/* TFMT��Ƭ���Ďގڎ�					*/
TCOMPAT *mowmtp;						/* TWMT��Ƭ���Ďގڎ�					*/
UCHR	mosbmsflg;						/* ��ư��λ���κѤߥե饰			*/
long	mosmpkpmb;						/*	SMP������α�юҎ��َΎގ�����ID			*/
TPCTPSZ	*mocprpct;						/* �����̎ߎێ���TPCT���ݎĎ؎��Ďގڎ�			*/
long	motrybms;						/* ͽ���Ͻ�λ��������ե饰			*/
long	moctmnt;						/* �ãͥơ��֥�ޥ���ȥե饰		*/
long	moltmnt;						/* �̣ͥơ��֥�ޥ���ȥե饰		*/
short	moecmt;							/* �ԣãͣԥ���ȥ��ֹ�				*/
long	mohsnsp;						/* �Ύ��Ď����ݎʎގ�ξ�ώ̎ߎێ��ގ׎юӎ��Ď��԰��׎̎׎���*/
long	mooscprcd;						/* mo_crep�Ǥ�oscrepr�ֵ��� CT0597	*/
long	mooscmdflg;						/* �ϣӥ��ޥ�ɥե饰	CT0597		*/
short	momrmcnt;						/* ��ԥꥫ�Х굯ư��				*/
										/*						CT0881		*/
UCHR	mospmfdk[32];					/* �ӣУ�����̎����َΎގ؎�����̾			*/
UCHR	mospmfdr[32];					/* �ӣУ�����̎����َÎގ��ڎ��Ď�̾			*/
UCHR	mospmfps[32];					/* �ӣУ�����̎����ََ̎ʎߎ�̾			*/
long	momsld2rcd;						/* mr_msld2�꥿���󥳡���			*/
long	momsldrcd;						/* mr_msld�꥿���󥳡���			*/
long	mocdbeflg;						/* ��Է�¸��ǧ���ե饰				*/
long	moybwtime;						/* ͽ�����Ԥ�����	ST3589			*/
long	moadwtime;						/* ���ώ��ގ����Ԥ�����	CT1193		*/
long	moadwflg;						/* ���ώ��ގ����Ԥ��ե饰	CT1193		*/
UCHR	mospmflg;						/* �����ΰ�������Ѥߥե饰 ST3589*/
UCHR	moadwcnui;						/* ���ϥ���������ס����׾���		*/
										/*			CT1193					*/
UCHR	mosmadflg;						/* Ω���夲Ʊ�������ώ��ގ��ݳ���̎׎���	*/
										/*			CT1193					*/
UCHR	mosyflg;						/* ξ��Ʊ��Ω���夲�ե饰	ST3800	*/
char	mojrof;							/* �ʣΣ̺ƥ����ץ�ե饰	ST3699	*/
long	moneflg;						/* ���ｪλ�ե饰			ST4174	*/
										/* mspcmsg.h���			ST4194	*/
char	movdaylm[6];					/* VCT����(LM)				CT1215	*/
long	movdayflg;						/* VCT���Վ̎׎���				CT1215	*/
char	momscmskb;						/* VCT���϶�ʬ(CM)			CT1222	*/
char	momslmskb;						/* VCT���϶�ʬ(LM)			CT1222	*/

char	momrsflg;						/* �ߥ顼Ʊ����λɽ��		ST4451	*/

char	moicpflg;						/* �ɣãХץ������֥ե饰	ST4861	*/
long	molidcnt;						/* �̣ɣãн�λ�Ԥ���		ST5270	*/

long	motrfflg;						/* ���ｪλ�¹ԺѤ�ɽ��		ST5972	*/
										/* �ơ��֥�����λ��˸��ѷϥ�����	*/
										/* �������Ȥˤ�����ｪλ���������	*/
										/* �¹Ԥ������򼨤�					*/
long	moshmemid;						/* �ơ��֥��Ǽ�Ѷ��ѥ���ID	PRC-008-05 */
long	mostendflg;						/* ��λ������������Ƴ��� SSLA0039*/

