/****************************************************************************/
/*		����䡥�衡���󥯥롼�ɥե�����									*/
/*							'95/03/16			ST1737						*/
/****************************************************************************/

/****************************************/
/*	MFECB(�ü�̎����ٴ����̎ގێ���)��¤��		*/
/****************************************/

struct mfecb {
	short	mfebid;						/*	�ü�ե���������֥�å����̻�	*/
	char	mfemode;					/*	�����ץ�⡼��					*/
	char	mfestat;					/*	���ơ�����						*/
	long	mfefdf;						/*	�ե����뵭�һң�				*/
	long	mfefds;						/*	�ե����뵭�һң�				*/
	long	mfefdt;						/*	�ե����뵭�һң�				*/
	long	mfeboe;						/*	�£ϣ�							*/
	long	mfeeod;						/*	�ţϣ�							*/
	long	mfeeoe;						/*	�ţϣ�							*/
	long	mfeted;						/*	�������ţϣľ���				*/
	long	mfesta;						/*	�ɤ߹��ߡ��񤭹��߳��ϰ���		*/
	long	mfelen;						/*	�ɤ߹��ߡ��񤭹���Ĺ��ͭ����	*/
	long	mfefcb;						/*	�ե����������֣�				*/
	long	mfefcs;						/*	�ե����������֣�				*/
	short	mfesec;						/*	�쥳����Ĺ�ʥ�����Ĺ��			*/
	short	mfeblc;						/*	�֥�å�Ĺ						*/
	short	mfesnu;						/*	�����ե����룱�ȥ�å��⥻������*/
	char	mfeefm;						/*	�򴹥ե�����ɸ��				*/
	char	mfeden;						/*	��Ͽ̩��						*/
};
typedef struct mfecb MFECB; 


/****************************************/
/*	IBMɸ�����FD���������؎ݎ��޹�¤��		*/
/****************************************/

struct fdindx {
	char	fddummy1[75];				/*	���������					*/
	char	fdrecd;						/*	ʪ���쥳����Ĺ					*/
	char	fddummy2[52];				/*	���������					*/
};
typedef struct fdindx FDINDX;


/****************************************/
/*	IBMɸ�����FD���Îގ��������Ď׎͎ގٹ�¤��	*/
/****************************************/

struct fdlabl {
	char	fddummy1[5];				/*	���������					*/
	char	fddaid[17];					/*	�ǡ������åȼ���̾				*/
	char	fdbloc[5];					/*	�֥�å�Ĺ						*/
	char	fddummy2;					/*	���������					*/
	char	fdboe[5];					/*	�£ϣ�							*/
	char	fddummy3;					/*	���������					*/
	char	fdeoe[5];					/*	�ţϣ�							*/
	char	fddummy4[4];				/*	���������					*/
	char	fdextyp;					/*	�ե�����򴹥�����ɸ��			*/
	char	fdmflag;					/*	ʣ���ܥ�塼��ɸ��				*/
	char	fdbsnum[2];					/*	�ܥ�塼�����ֹ�				*/
	char	fddummy5[27];				/*	���������					*/
	char	fdeod[5];					/*	�ţϣ�							*/
	char	fddummy6[49];				/*	���������					*/
};
typedef struct fdlabl FDLABL;

/****************************************/
/*	�ƣĥ������������ѡ�LOG���؎���¤��	*/
/****************************************/

struct fdlog {
	char	fname[8];					/*	�ؿ�̾							*/
	long	log;						/*	���������ֵ��͡������			*/
};
typedef struct fdlog FDLOG;

/****************************************/
/*	�ƣĥ��������ؿ���ͭ��define��		*/
/****************************************/

#define  FREEF1   0x00000001			/*	�ü�ե����룱					*/
#define  FREEF2   0x00000002			/*	�ü�ե����룲					*/
#define  FREEF3   0x00000004			/*	�ü�ե����룳					*/
#define  IBMF13   0x00000005			/*	�ü�ե����룱�ȣ�				*/
#define  IBMF123  0x00000007			/*	�ü�ե����룱�ȣ��ȣ�			*/
#define  IBMF12   0x00000003			/*	�ü�ե����룱�ȣ�				*/
#define  IBMF23   0x00000006			/*	�ü�ե����룲�ȣ�				*/
/*	��ա����ɣ£ͣƣ����ȣɣ£ͣƣ����ϸ��¤ˤ�¸�ߤ��ʤ��Ȥ߹�碌		*/

#define  FDFREE1  0x01					/*	�ü�ե����룱					*/
#define  FDFREE2  0x02					/*	�ü�ե����룲					*/
#define  FDFREE3  0x04					/*	�ü�ե����룳					*/
#define  FDIBM13  0x05					/*	�ü�ե����룱�ȣ�				*/
#define  FDIBM123 0x07					/*	�ü�ե����룱�ȣ��ȣ�			*/

#define  FDLONGF  128L					/*	�ü�ե����룱�Υ�����Ĺ		*/
#define  FDLONGS  256L					/*	�ü�ե����룲�Υ�����Ĺ		*/

#define  FDREAD   0x00					/*	�ɤ߹��ߥ⡼��					*/
#define  FDWRIT   0x01					/*	�񤭹��ߥ⡼��					*/
#define  FDUPDT   0x40					/*	�������⡼��					*/
#define  FDUPDA   0x80					/*	�������⡼��					*/

#define  FDNULL   0x00					/*	�Σգ̡̣ʥ̥��				*/
#define  BLANK    0x20					/*	���ڡ���						*/
#define  MFECBID  0x4542				/*	�ü�ե���������֥�å����̻�	*/
#define  IBMFD    0x00					/*	�ɣ£ͷ����ƣ�					*/

#define  FDIZZENOTR  0x000d0002			/*	�ƣ���unit not ready			*/
#define  FDIZZEDELS  0x000e0014			/*	�ƣ���deleated sector			*/
#define  FDIZZEWRT   0x000d000e			/*	�ƣ���not writabl				*/
#define  LOGNULL     0L					/*	�̣ϣǾ����������				*/
#define  LOGINF      4L					/*	�̣ϣǾ�����礭��				*/
#define  FDNOPASS   -1L					/*	�����ץ󤷤ʤ��ü�ե�����		*/

/****************************************/
/*	������Ĺ�����						*/
/****************************************/

#define	FDSEC_128	128					/*��������Ĺ�ʣ������Х��ȡ�		*/
#define	FDSEC_256	256					/*��������Ĺ�ʣ������Х��ȡ�		*/
#define	FDSEC_512	512					/*��������Ĺ�ʣ������Х��ȡ�		*/
#define	FDSEC_1024	1024				/*��������Ĺ�ʣ��������Х��ȡ�		*/
