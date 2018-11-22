/*****************************************************************/
/*                                                               */
/*              tfac.h                                           */
/*                                                               */
/*        TFAC �Î��̎ގ� �̎����ώ���  87.12.05                            */
/*                     �ѹ�  94.10.26 JI  �ѹ���  ����  ��       */
/*                     �ѹ�  94.12.20 JJ  �ѹ���  ����  ��       */
/*                     �ѹ�  95.03.17 JK  �ѹ���  (��)���ю����̎�     */
/*                                        �ξ����ɼ  ST1761     */
/*                     �ѹ�  95.03.23 JL  �ѹ���  ����  ��Ƿ     */
/*                                        OSP�����ѹ���ȼ������  */
/*                     �ѹ�  95.06.13 JM  �ѹ���  ���������Ρ��� */
/*                                        LICP��ư��ȼ���������� */
/*                     �ѹ�  95.08.22 JN  �ѹ���  (��)���ю����̎�     */
/*                                        �ξ����ɼ  ST3176     */
/*                     �ѹ�  95.10.23 JO  �ѹ���  (��)���ю����̎�     */
/*                                      �����ѹ��׵��  SSCY0126 */
/*                     �ѹ�  95.12.25 JP  �ѹ���  ����������     */
/*                                        �ξ����ɼ  ST3895     */
/*                     �ѹ�  95.01.23 JQ  �ѹ���  (��)���ю����̎�     */
/*                                      �����ѹ��׵��  SSCY0063 */
/*                     �ѹ�  95.12.25 JR  �ѹ���  ����������     */
/*                                        �ξ����ɼ  ST3985     */
/*****************************************************************/

struct mdfacsb {
	short	tfacpbdw;				    /* LM�̎ߎ��َʎގ��̎�ID������     JM JJ */
	short   tfaccmdw;	                /* LM���юҎӎ�ID������       JM JJ */
	long    tfacpbad;	                /* LICP�ʎގ��̎��ʎߎ׎Ҏ�����Ǽ�莱�Ďގڎ� JR */
	char    tfacprst;                   /* ���������                    */
	char    tfacikfg;	                /* �������ե饰                */
	short   tfacsysc;	                /* �����ƥॳ�����ȥ饤���    */
	long    tfacptct;	                /* �ѥ������������ƻ륿������  */
	long    tfackait;	                /* �����ƻ�؎Ď׎������̎ߎݎ�������        */
	long    tfacrcov;	                /* �����㳲�������Х�������      */
	long    tfacsyst;	                /* �����ƥॳ�����ȥ饤��������*/
	long    tfacrlat;	                /* �ң̣�Ʊ����������            */
	char    tfactdat[64];               /* �ޤ��֤���ѥǡ���          */
	char    tfacpuf0;                   /* �ʎގ��̎��ʎߎ׎Ҏ������ݴ����̎׎��� PR JJ */
    char    tfacpuf1;                   /* ���юҎӎ�ID���Ѵ��������ݎ�   JQ JM */
	short   tfactcnt;                   /* ���֤�������������  JN JJ */
	char    tfacword[4];                /* �ѥ����                    */
										/* ���Ժ��                   JI */
	long    tfacstrt;                   /* �̿�����׵� ���� �Ԥ����� JJ */
    short   tfaccllc;                   /* ������³�؎Ď׎���             JO */
    char    tfacyob0[2];                /* ͽ��                    J0 JJ */
};
typedef struct mdfacsb MDFACSB;         /* DCP �֎�                        */
typedef struct mdfacsb TFACSUB;         /* FIP �֎�                        */

struct mdfacko {
	char	tfackbst;			        /*  ���͎ގ̎� ���Î�����                 */
	char	tfactvrn;                   /*  �������� ���؎����� ���Î�               */
	short	tfacexen;                   /*  ���؎������� ���ݎĎ� NO               */
	short	tfacpuno;			        /*  PU �ʎގݎ��ގ�                    */
	short	tfacchno;		            /*  �����Ȏ� �ʎގݎ��ގ�                  */
	char	tfacfiln[22];			    /*  �Ď����� �̎����� �Ҏ�                 */
 	short	tfacpcnt;                   /*  ������                     */
	long	tfacfdsc;           		/*  �̎����� �Îގ������؎̎ߎ�               */
	char	tfacsygi;           		/*  ���������ގ� ���Î�����                 */
	char	tfacchst;               	/*  �̎����� ���Î�����                   */
	char	tfacchs2;               	/*  ʪ������ͥ륹�ơ�����       */
	char	tfaccykf;               	/*  ��ƾ��֥ե饰               */
	char	tfaclpmg;               	/*  ������å���������̵ͭ       */
	char	tfacuinf;               	/*  ����ͥ뱿�Ѿ���             */
	char	tfacchcl;               	/*  ����ͥ��ĺɥե饰           */
	char	tfacrecv;               	/*  �㳲�� �����ƻ���ס����� JI */
	short	tfacfapn;               	/*  TFAP ���ݎĎ� ���ݎĎ� NO            */
	short	tfacpthn;               	/*  �ێݎ� �ʎߎ� ����                   */
	char	tfacteln[16];        		/*  �Îގݎ� �ʎގݎ��ގ�               JI */
	char	tfactlsu;      				/*  �Îގݎ� �ʎގݎ��ގ� �Վ����� ��������        */
	char	tfacptcl;               	/*  �׵ḵ���������       JJ JK */
	char	tfacyob2[2];               	/*  �֎ˎ� 2                     JI */
	long	tfacmiaa;               	/*  MIA ������ ���Ďގڎ�                */
										/*  ���Ժ��                  JI */
	short	tfacrxtn;   				/*  rxlt���ݎĎ��ֹ�(rally�Î��̎ގ�)  JI */
	char	tfacnapo;   				/*  rally������������̵ͭ     JL */
	char	tfacapno;   				/*  ���Ф�PU�ֹ�        JM JI JL */
	char	tfactel2[16];        		/*  �Îގݎ� �ʎގݎ��ގ�               JJ */
	char	tfactls2;					/*  �Îގݎ� �ʎގݎ��ގ� �Վ����� ��������     JJ */
	char	tfacyob4[3];               	/*  �֎ˎ� 4                     JJ */
	short	tfachlen;               	/*  TFAH ���ݎĎ� ���ݎĎ� NO         JJ */
	short	tfachlno;               	/*  ���ݎĎ� ����                   JJ */
	short	tfacxlen;               	/*  TFAX or TFAL���ݎĎ� ���ݎĎ� NO  JJ */
	short	tfacxlno;               	/*  ���ݎĎ� ����                   JJ */
	unsigned	char	tfacprtc;		/*  ����ʪ��������TRADE��������    JJ */
	unsigned	char	tfacnetw;		/*  ����ʪ����������               JJ */
	unsigned	char	tfacbulp;		/*  �£ղ����ס���ɣ�             JJ */
	unsigned	char	tfacclgl;		/*  tfacclgn��ͭ�������Î��Ŀ�          JJ */
				char	tfacclgn[34];	/*  ISDN����ȯ�ƻ�ȯ������������� JJ */
	unsigned	char	tfaccapl;		/*  tfaccapa��ͭ�������Î��Ŀ�          JJ */
				char	tfaccapa[11];	/*  ISDN����ȯ�ƻ���ã��ǽ������� JJ */
	unsigned	char	tfacchil;		/*  tfacchid��ͭ�������Î��Ŀ�          JJ */
				char	tfacchid;		/*  ISDN����ȯ�ƻ������Ȏټ��������   JJ */
	unsigned	char	tfaccl1l;		/*  tfaccld1��ͭ�������Î��Ŀ�          JJ */
				char	tfaccld1[21];	/*  ISDN����ȯ�ƻ����̎�adr��������� JJ */
	unsigned	char	tfaccl2l;		/*  tfaccld2��ͭ�������Î��Ŀ�          JJ */
				char	tfaccld2[21];	/*  ISDN����ȯ�ƻ����̎�adr��������� JJ */
	unsigned	char	tfacllcl;		/*  tfacllcp��ͭ�������Î��Ŀ�          JJ */
				char	tfacllcp[14];	/*  ISDN����ȯ�ƻ��̿��Ď������������ JJ */
	unsigned	char	tfachlcl;		/*  tfachlcp��ͭ�������Î��Ŀ�          JJ */
				char	tfachlcp[2];	/*  ISDN����ȯ�ƻ��̿��Ď������������ JJ */
	unsigned	char	tfacusel;		/*  tfacuser��ͭ�������Î��Ŀ�          JJ */
				char	tfacuser[129];	/*  ISDN����ȯ�ƻ��Վ����޴־�����ã�� JJ */
	unsigned	long	tfaclpid;		/*  �̣ɣãХץ����ɣ�           JJ */
				char	tfaccaln[2];    /*  �ɣӣģθ�������θ��ֹ������ JJ */
                char    tfacdown;       /*  �����Îю��ގ��ݎ��Î�����                  JK */
                char    tfacichs;       /*  ISDN��������ͥ륹�ơ�����     JK */
                long    tfacpidm;       /*  ���юҎӎأɣ�			     	JR JK */
                char   tfacyob5[28];    /*  �֎ˎ� 5              JR JQ JM JJ JK */
};
typedef struct mdfacko MDFACKO;         /*  DCP �֎�                       */
typedef struct mdfacko TFACPSZ;         /*  FIP �֎�                       */
