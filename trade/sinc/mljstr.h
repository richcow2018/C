/*****************************NTC-SMP-TOOL****************************/
/*                                                                   */
/*   1 �̎����َҎ�                                                        */
/*      �������ގ����� �Î����ގ̎�����(mljstr.h)                                   */
/*                                                                   */
/*   2 ���̎ގ�                                                          */
/*      ���ގ����Ŏ� ���ގݎ̎�                                                 */
/*                                                                   */
/*   3 �؎ڎ�                                                           */
/*      �������� ���� : ���ގĎ� �����ގ�                        			         */
/*      �������� ���� : ���ʎގ� �Ď���                          			     */
/*      �͎ݎ��� ���� :                                                    */
/*                                                                   */
/*********************************************************************/
/*  �̎����� �������ގ��Î��̎ގ�                                                  */
/*********************************************************************/
struct mljfctb{
	 char  *mljofnm;          /* �����؎��� �̎����َҎ� 						 */
	 long   mljofd;           /* �����؎��� �̎����� �����ގ��� 				 */
	 char  *mljjfnm;          /* ���ގ����Ŏ� �̎����َҎ�                       */
	 long   mljjfd;           /* ���ގ����Ŏ� �̎����� �����ގ���                  */
};
typedef  struct mljfctb  MLJFCTB;

/*********************************************************************/
/*  �����؎��� �ӎ��ĎގÎ��̎ގ�(A or S or D)                                    */
/*********************************************************************/
struct  mljdpmt{
	 char   mljdmpm;          /* �����؎��� �������� 						 */
	 char   mljdumy[3];       /* ���ގЎ� 								 */
};
typedef  struct  mljdpmt  MLJDPMT;

/*********************************************************************/
/*  �ˎ��ގ����ގ��� ���������Î��̎ގ�                                               */
/*********************************************************************/
struct  mljhcct{
	 unsigned char   mljstrh[4];       /* ������ �ˎ��ގ� 							 */
	 unsigned char   mljendh[4];       /* �������؎��� �ˎ��ގ� 						 */
	 unsigned char   mljstrc[4];       /* ������ ���ގ��� 							 */
	 unsigned char   mljendc[4];       /* �������؎��� ���ގ��� 						 */
	 long   mljscfg;          /* ������ ���ގ��� �������� �̎׎���                  */
};
typedef  struct  mljhcct  MLJHCCT;

/*********************************************************************/
/*  �ڎ����Ďގ��ʎގ� ���������Î��̎ގ�                                             */
/*********************************************************************/
struct  mljrckt{
	 long   mljstrr;          /* �������ڎ����Ď� ���ʎގ� 					 */
	 long   mljendr;          /* �������؎����ڎ����Ď� ���ʎގ� 					 */
 };
typedef  struct  mljrckt  MLJRCKT;

/*********************************************************************/
/*  �ڎ����Ďގ��ݎÎގ����� ���������Î��̎ގ�                                           */
/*********************************************************************/
struct  mljrict{
	 short  mljpnum;          /* -P ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljknum;          /* -K ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljbnum;          /* -B ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljnnum;          /* -N ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljmnum;          /* -M ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljpron[3];       /* �̎ߎێ��� �ʎގݎ��ގ� 						 */
	 char   mljgcd[3][4];     /* ���ގَ��̎� �����Ď� 						 */
	 char   mljisgc[4][4];    /* �Ǝ����؎��� ���̎ގ��ގَ��̎� �����Ď� 				 */
	 char   mljusgc[4][4];    /* �������� ���̎ގ��ގَ��̎� �����Ď� 				 */
	 short   mljwsnm[4];       /* ���ݎώ� �ʎގݎ��ގ� 						 */
};
typedef  struct  mljrict  MLJRICT;

/*********************************************************************/
/*  �Îގ����̎� ���������Î��̎ގ�                                                 */
/*********************************************************************/
struct  mljdtct{
	 short  mljinum;          /* -I ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljtnum;          /* -T ���͎ߎ׎ݎĎގ��� 						 */
	 short  mljfnum;          /* -F ���͎ߎ׎ݎĎގ��� 						 */
	 char   mljdaid[3][2];    /* �Îގ��� ID 							 */
	 char   mljtbnm[3][4];    /* �Î��̎ގ� �Ҏ� 							 */
	 char   mljflnm[3][16];   /* �̎����� �Ҏ� 							 */
};
typedef  struct  mljdtct  MLJDTCT;

/*********************************************************************/
/*  ���Ďގڎ� ���ݎ����ʎߎ׎Ҏ��� �Î��̎ގ�                                           */
/*********************************************************************/
struct  mljadpt{
	 long   mljaddr;          /* �������� ���Ďގڎ� 						 */
	 char   mljopr[2];        /* ���ݎ��ގ� �� 							 */
	 char   mljdmmy[2];       /* ���ގЎ� 								 */
	 long   mljdlen;          /* ������ �� �Ŏ��ގ� 					 	 */
	 char   mljdata[32];      /* ������ 								 */
};
typedef   struct  mljadpt  MLJADPT;

/*********************************************************************/
/*  -X�ʎߎ׎Ҏ��� ���������Î��̎ގ�                                               */
/*********************************************************************/
struct  mljxpct{
	 long   mljxnum;          /* -X ���͎ߎ׎ݎĎގ��� 						 */
  MLJADPT   mljxtbl[3];       /* ���Ďގڎ����ݎ��� �ʎߎ׎Ҏ�����-�̎ގ� 				 */
};
typedef  struct  mljxpct  MLJXPCT;

/*********************************************************************/
/*  -V�ʎߎ׎Ҏ��� ���������Î��̎ގ�                                               */
/*********************************************************************/
struct  mljvpct{
	 long   mljvnum;          /* -V ���͎ߎ׎ݎĎގ��� 						 */
  MLJADPT   mljvtbl[3];       /* ���Ďގڎ����ݎ��� �ʎߎ׎Ҏ�����-�̎ގ� 				 */
};
typedef  struct  mljvpct  MLJVPCT;

/*********************************************************************/
/*  �ڎ����Ďގ������؎��� ���������Î��̎ގ�                                            */
/*********************************************************************/
struct  mljrect{
	 char    mljyyhh[8];      /* �ˎ��ގ� ���ގ��� 							 */
};
typedef  struct  mljrect  MLJRECT;

/*********************************************************************/
/*  ���׎��Ҏ��������� �ʎߎ׎Ҏ��� �Î��̎ގ�                                           */
/*********************************************************************/
struct  mljempr{
	 union{
		  short *mljcsht;	/* short �͎� �Ύߎ��ݎ�						 */
		  long  *mljclng;	/* long �͎� �Ύߎ��ݎ�						 */
		  char  *mljcchr;	/* char �͎� �Ύߎ��ݎ�						 */
	 } mljchpr;
	 long   mljcnln;		/* �ʎߎ׎Ҏ��� �� �Ŏ��ގ�						 */
};
struct  mljempt{
	 long   mljprnm;		/* �ʎߎ׎Ҏ��� ����							 */
	 struct mljempr emprt[MLJPNOM];	/* �ʎߎ׎Ҏ��� �� �ʎ��ڎ�			 	 */
};
typedef  struct  mljempt  MLJEMPT;

/*********************************************************************/
/*  ���׎��Ҏ��������� �Î��̎ގ�                                                  */
/*********************************************************************/
struct  mljermg{
	 long   errno;            /* ���׎��Ҏ��������� NO 						 */
	 char   errmg[MLJMLN];    /* ���׎��Ҏ��������� 							 */
	 long   permn;            /* �ʎߎ׎Ҏ��� ���� 							 */
	 struct mlcftbl pardat[MLJPNOM];	/* �͎ݎ��ݎʎߎ׎Ҏ��� �� �ʎ��ڎ�		 */
};
typedef  struct  mljermg  MLJERMG;

/*****************************NTC-SMP-TOOL****************************/
/*                                                                   */
/*   1 �̎����َҎ�                                                        */
/*      �������ގ����� �Î����ގ̎�����(mljstr.h)                                   */
/*                                                                   */
/*   2 ���̎ގ�                                                          */
/*      ���ގ����Ŏ� �ʎߎ���                                                  */
/*                                                                   */
/*   3 �؎ڎ�                                                           */
/*      �������� ���� : ���ގĎ� �����ގ�                        			         */
/*      �������� ���� : �Ǝڎݎ��� �Ɏ̎ގˎ�                       			     */
/*      �͎ݎ��� ���� :                                                    */
/*                                                                   */
/*********************************************************************/
/*  �̎����� ���ގ����Ύ��Î��̎ގ�                                                 */
/*********************************************************************/
struct  mljfitb{
	 char   *mljifnm;         /* �Ǝ����؎����̎����َҎ�   					 */
	 long   mljifd;           /* �Ǝ����؎����̎����َ����ގ���	                 */
	 char   *mljofnm;         /* �������̎����َҎ�   	     				 */
	 long   mljofd;           /* �������̎����َ����ގ���	                     */
	 char   *mljjfnm;         /* ���ގ����Ŏَ̎����َҎ�   					 */
	 long   mljjfd;           /* ���ގ����Ŏَ̎����َ����ގ���	                 */
};
typedef  struct  mljfitb  MLJFITB;

/*********************************************************************/
/*  �ڎ����Ďގ������ގ� �Î��̎ގ�                                                 */
/*********************************************************************/
struct  mljrctb{
	 long   mljrlen;          /* ���ގ����Ŏَڎ����Ďގ�����                      */
	 char   *mljprbf;         /* �ʎߎ����֎��ڎ����Ďގʎގ��̎�   				 */
	 char   *mljcrbf;         /* �����ݎ��َ֎��ڎ����Ďގʎގ��̎�	         		 */
	 long   mljrflg;          /* �ڎ����Ďގ��ގ������ݎ̎׎���	                 */
};
typedef  struct  mljrctb  MLJRCTB;

/*********************************************************************/
/*  �Îގ������ݎ��� ���ގ����Ύ��Î��̎ގ�                                             */
/*********************************************************************/
struct  mljdsit{
	 long   mljsrmd;          /* ���ݎ����ӎ��Ď�                            */
	 long   mljdlen;          /* �Îގ���������                             */
	 char   *mljdadr;         /* �ʎߎ��������������Îގ����ڎ����ĎގŎ� �����������Ďގڎ�      */
	 long   mljdflg;          /* �Îގ������ގ������ݎ̎׎��� 	                 */
};
typedef  struct  mljdsit  MLJDSIT;

/*********************************************************************/
/*  �Îގ������ݎÎގ����� �ˎ������ގ֎� �Î��̎ގ�                                        */
/*********************************************************************/
struct  mljdidt{
	 char   mljddid[2];       /* �ˎ������ގ��� �Îގ���ID                      */
	 char   mljdumy[2];       /* ���ގЎ�                                */
	 long   mljdrcn;          /* �ˎ������ގ��� �ڎ����Ďގ��ʎގ�                  */
};
typedef  struct  mljdidt  MLJDIDT;

/*********************************************************************/
/*  ���ގ����Ύ��̎׎��� �Î��̎ގ�                                                 */
/*********************************************************************/
struct  mljifft{
	 long   mljkmod;          /* ���Ďގ� �ӎ��Ď�                           */
	 long   mljomod;          /* �����؎��� �ӎ��Ď�                         */
	 long   mljofif;          /* �����؎����̎����� �Վ���                      */
	 long   mljjfc;           /* ���ގ����Ŏَ̎����� ���Ȏ��Ď̎׎���                 */
	 long   mljjfo;           /* ���ގ����Ŏَ̎����� �����̎ߎݎ̎׎���                */
};
typedef  struct  mljifft  MLJIFFT;

/*********************************************************************/
/*  �Ҏ��������ގʎߎ׎Ҏ� �Î��̎ގ�                                                */
/*********************************************************************/
struct  mljmgpr{
	 union{                   /* �ʎߎ׎Ҏ� �� �Ύߎ��ݎ�                       */
		  short    *mljpsht;
		  long     *mljplng;
		  char     *mljpchr;
	  } mljperm;
	  long	    mljplen;	  /* �ʎߎ׎Ҏ��� �� �Ŏ��ގ�						 */
};
typedef  struct  mljmgpr  MLJMGPR;

struct  mljmsgt{
	 long   mljprnm;          /* �ʎߎ׎Ҏ� �� ������                         */
	 MLJMGPR   mljmsgp[MLJPNOM];
};
typedef  struct  mljmsgt  MLJMSGT;

/*********************************************************************/
/*   �Ҏ��������� �Î��̎ގ�                                                   */
/*********************************************************************/
struct  mljmesg{
	 long   msgno;            /* �Ҏ��������� NO 	    					 */
	 char   messg[MLJMGL];    /* �Ҏ��������� 							 */
	 long   permn;            /* �ʎߎ׎Ҏ��� ���� 							 */
	 struct mlcftbl pardat[MLJPNOM];	/* �͎ݎ��ݎʎߎ׎Ҏ��� �� �ʎ��ڎ�		 */
};
typedef  struct  mljmesg  MLJMESG;

/*********************************************************************/
/*  ���������Î��̎ގ� ���Ďގڎ��Î��̎ގ�                                            */
/*********************************************************************/
struct  mljctat{
	 MLJFCTB   *mljfctbp;     /* �̎����� �������ގ��Î��̎ގ� �͎� �Ύߎ��ݎ� 			 */
	 MLJDPMT   *mljdpmtp;     /* �����؎����ӎ��Ď� �Î��̎ގ� �͎� �Ύߎ��ݎ� 			 */
	 MLJHCCT   *mljhcctp;     /* �ˎ��ގ����ގ��� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 		 */
	 MLJRCKT   *mljrcktp;     /* �ڎ����Ďގ��ʎގ� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 		 */
	 MLJRICT   *mljrictp;     /* �ڎ����Ďގ��ݎÎގ������̎� ���������Î��̎ގ� �͎� �Ύߎ��ݎ�   */
	 MLJDTCT   *mljdtctp;     /* �Îގ����̎� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 			 */
	 MLJXPCT   *mljxpctp;     /* -X�ʎߎ׎Ҏ��� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 		 */
	 MLJVPCT   *mljvpctp;     /* -V�ʎߎ׎Ҏ��� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 		 */
	 MLJRECT   *mljrectp;     /* �ڎ����Ďގ������؎��� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 	 */
	 MLCKTBL   *mljktblp;     /* �����ʎߎ׎Ҏ��� ���������Î��̎ގ� �͎� �Ύߎ��ݎ� 		 */
	 MLJFITB   *mljfitbp;     /* �̎����� ���ގ����Ύ� �Î��̎ގ�                   */
	 MLJRCTB   *mljrctbp;     /* �ڎ����Ďގ������ގ� �Î��̎ގ�                    */
	 MLJDSIT   *mljdsitp;     /* �Îގ������ݎ��� ���ގ����Ύ� �Î��̎ގ�               */
	 MLJDIDT   *mljdidtp;     /* �Îގ������ݎÎގ������̎� �ˎ������� �Î��̎ގ�           */
	 MLJIFFT   *mljifftp;     /* ���ގ����Ύ� �̎׎��� �Î��̎ގ�                   */
};
typedef  struct  mljctat  MLJCTAT;