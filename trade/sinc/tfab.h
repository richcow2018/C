/*****************************************************************/
/*																 */
/*				tfab.h											 */
/*																 */
/*		  TFAB �Î��̎ގ� �̎����ώ���	 94.09.16							 */
/*					   �ѹ�	   .  .		  �ѹ���				 */
/*																 */
/*****************************************************************/

struct mdfadsb {
	short	tfabssen;					/* ͽ��						  JJ */
	short	tfabslsu;					/* ͽ��						  JJ */
	short	tfabbsen;					/* ͽ��						  JJ */
	short	tfabblsu;					/* ͽ��						  JJ */
	char	tfabprst;					/* ���������					 */
	char	tfabikfg;					/* �������ե饰				 */
	short	tfabsysc;					/* �����ƥॳ�����ȥ饤���	 */
	long	tfabptct;					/* �ѥ������������ƻ륿������	 */
	long	tfabkait;					/* �����ƻ�؎Ď׎������̎ߎݎ�������		 */
	long	tfabrcov;					/* �����㳲�������Х�������		 */
	long	tfabsyst;					/* �����ƥॳ�����ȥ饤��������*/
	long	tfabrlat;					/* �ң̣�Ʊ����������			 */
	char	tfabtdat[64];				/* �ޤ��֤���ѥǡ���			 */
	short	tfabsien;					/* ͽ��							 */
	short	tfabbien;					/*	ͽ��						 */
	char	tfabword[4];				/* �ѥ����					 */
										/* ���Ժ��					  JJ */
	long	tfabstrt;					/*								 */
	char	tfabyob0[4];				/*	ͽ��						 */
};
typedef	struct mdfadsb MDFABSB;			/* DCP �֎�						 */
typedef	struct mdfadsb TFABSUB;			/* FIP �֎�						 */

struct mdfadko {
	char	tfabkbst;					/*	���͎ގ̎� ���Î�����				 */
	char	tfabtvrn;					/*	�������� ���؎����� ���Î�				 */
	short	tfabexen;					/*	���؎������� ���ݎĎ�	NO				 */
	short	tfabpuno;					/*	PU �ʎގݎ��ގ�					 */
	short	tfabchno;					/*	�����Ȏ� �ʎގݎ��ގ�					 */
	char	tfabfiln[22];				/*	�Ď����� �̎����� �Ҏ�				 */
	short	tfabpcnt;					/*	������					 */
	long	tfabfdsc;					/*	�̎����� �Îގ������؎̎ߎ�				 */
	char	tfabsygi;					/*	���������ގ� ���Î�����				 */
	char	tfabchst;					/*	�̎����� ���Î�����					 */
	char	tfabchs2;					/*	ʪ������ͥ륹�ơ�����		 */
	char	tfabcykf;					/*	��ƾ��֥ե饰				 */
	char	tfablpmg;					/*	������å���������̵ͭ		 */
	char	tfabuinf;					/*	����ͥ뱿�Ѿ���			 */
	char	tfabchcl;					/*	����ͥ��ĺɥե饰			 */
	char	tfabrecv;					/*								 */
	short	tfabfapn;					/*	TFAP ���ݎĎ� ���ݎĎ� NO			 */
	short	tfabpthn;					/*	�ێݎ�	�ʎߎ�	����					 */
	char	tfabteln[16];				/*	�Îގݎ� �ʎގݎ��ގ�				  JJ */
	char	tfabtlsu;					/*	�Îގݎ� �ʎގݎ��ގ�	�Վ����� ��������		 */
	char	tfabptcl;					/*							  JJ */
	char	tfabyob2[2];				/*	�֎ˎ�	2					  JJ */
	long	tfabmiaa;					/*	MIA	������	���Ďގڎ�				 */
										/*	���Ժ��				  JJ */
	short	tfabrxtn;					/*							  JJ */
	char	tfabyob3[2];				/*	�֎ˎ�	3					  JJ */
	char	tfabtel2[16];				/*	�Îގݎ� �ʎގݎ��ގ�				  JJ */
	char	tfabtls2;					/*	�Îގݎ� �ʎގݎ��ގ�	�Վ����� ��������		 */
	char	tfabyob4[3];				/*	�֎ˎ�	4						 */
	short	tfabhlen;					/*	TFAH ���ݎĎ� ���ݎĎ� NO			 */
	short	tfabhlno;					/*	���ݎĎ� ����						 */
	short	tfabxlen;					/*	TFAX or	TFAL���ݎĎ� ���ݎĎ� NO	 */
	short	tfabxlno;					/*	���ݎĎ� ����						 */
	unsigned	char	tfabprtc;		/*							  JJ */
	unsigned	char	tfabnetw;		/*							  JJ */
	unsigned	char	tfabbulp;		/*							  JJ */
	unsigned	char	tfabclgl;		/*							  JJ */
				char	tfabclgn[34];	/*							  JJ */
	unsigned	char	tfabcapl;		/*							  JJ */
				char	tfabcapa[11];	/*							  JJ */
	unsigned	char	tfabchil;		/*							  JJ */
				char	tfabchid;		/*							  JJ */
	unsigned	char	tfabcl1l;		/*							  JJ */
				char	tfabcld1[21];	/*							  JJ */
	unsigned	char	tfabcl2l;		/*							  JJ */
				char	tfabcld2[21];	/*							  JJ */
	unsigned	char	tfabllcl;		/*							  JJ */
				char	tfabllcp[14];	/*							  JJ */
	unsigned	char	tfabhlcl;		/*							  JJ */
				char	tfabhlcp[2];	/*							  JJ */
	unsigned	char	tfabusel;		/*							  JJ */
				char	tfabuser[129];	/*							  JJ */
	unsigned	long	tfablpid;		/*	�̣ɣãХץ����ɣ�	  JJ */
				char	tfabcaln[2];	/*							  JJ */
				char	tfabyob5[34];	/*	ͽ��					  JJ */
};
typedef	struct mdfadko MDFABKO;			/*	DCP	�֎�						 */
typedef	struct mdfadko TFABPSZ;			/*	FIP	�֎�						 */
