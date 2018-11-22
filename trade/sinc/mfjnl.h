/*********************************************************************/
/*		FIP ���ݎڎ� �Î��̎ގ� �֎�											 */
/*		���ގ����Ŏ� �����Ď� �Îގ��� ���֎ˎ� ���׎� �Îގ���								 */
/*********************************************************************/
/*********************************************************************/
/*		WMT �֎� ���ގ����Ŏ� �����Ď� �Îގ���										 */
/*********************************************************************/
#define   MFJWNO    3
struct mfjwmt {							/* WMT �֎� ���ގ����Ŏ� �Îގ���		 */
	char	mfjwid;						/* �����͎ގ�	(0x80) 			 */
	char	mfjwnm[3];					/* �Î��̎ގ� �Ҏ� ("WMT")			 */
	short	mfjwcnt;	 				/* �����Ɏ� ������					 */
	short	mfjwdum;	 				/* �֎ˎ�						 */
	struct    mfjwmth {
		short    mfjwno;				/* ���͎ގ̎� �ʎގݎ��ގ�			 */
										/*	   0 : ���̎� ���������̎�		 */
										/*	 > 0 : ���͎ގ̎�			 */
		short    mfjwlen;				/* �Îގ��� ������					 */
		union {
			TWMTSUB    mfjwsub; 		/* ���̎� ���������̎� �Îގ���			 */
			TWMTPSZ    mfjwpsz; 		/* ���͎ގ̎� �Îގ���				 */
		}mfjw;
	}mfjwdt[MFJWNO];
};
typedef    struct   mfjwmt   MFJWMT;

/*********************************************************************/
/*		FMT �֎� ���ގ����Ŏ� �����Ď� �Îގ���										 */
/*********************************************************************/
#define   MFJFNO    3
struct mfjfmt {							/* FMT �֎� ���ގ����Ŏ� �Îގ���		 */
	char	mfjfid;						/* �����͎ގ�	(0x40) 			 */
	char	mfjfnm[3];					/* �Î��̎ގ� �Ҏ� ("FMT")			 */
	short	mfjfcnt;	 				/* �����Ɏ� ������					 */
	short	mfjfdum;	 				/* �֎ˎ�						 */
	struct    mfjfmth {
		short    mfjfno;				/* ���͎ގ̎� �ʎގݎ��ގ�			 */
										/*	   0 : ���̎� ���������̎�		 */
										/*	 > 0 : ���͎ގ̎�			 */
		short    mfjflen;				/* �Îގ��� ������					 */
		union {
								/* ưŪ�ơ��֥����ΰٺ��(1��) TD60*/
			TFMTPSZ    mfjfpsz; 		/* ���͎ގ̎� �Îގ���				 */
		}mfjf;
	}mfjfdt[MFJFNO];
};
typedef    struct   mfjfmt   MFJFMT;

/*********************************************************************/
/*		���׎� ���ގ����Ύ� ���ݎ� �Îގ���  										 */
/*********************************************************************/

struct mfevmt {					/* ���׎� ���ގ����Ύ� ���ݎ� �Îގ��� 				 */
	char	mfevid; 			/* �����͎ގ�	(0x02) 					 */
	char	mfevnm[3];			/* �Î��̎ގ� �Ҏ� ("VMT")					 */
	long	mfevno;				/* VMT ���ݎĎ� NO( ���������ގ� �ʎ����� �Ύގ؎����� ) */
	long	mfercd;				/* ���׎� �����Ď� (ROS �� ���׎� �����Ď� )		 */
	long	mfefno;				/* FMT ���ݎĎ� NO( ���������ގ� �ʎ����� �̎����� )   */
								/*  >0 : �����ʎߎ� �̎����� ���׎�         	 */
								/*  =0 : �܎��� �̎����� �ώ��� �Ύގ؎����� ���׎� 	 */
	long	mfevmtp;			/* �̎ގ� �Ύގ؎����� �Ŏ� ���ݎĎ� VMT ���ݎĎ� NO   */
								/*   ( �Ύގ؎����� �͎����� ���� �� ���֎� ���� )	 */
};
typedef    struct   mfevmt	 MFEVMT;

/*********************************************************************/
/*		2���ގ����� �̎����� �֎� FMT �� ���ގ�-�Ŏ� �����Ď� �Î�-��                        */
/*********************************************************************/

struct	mfjdfmth	{					/* 2���ގ����� FMT ���ގ�-�ŎَÎ�-�� �͎�����*/
	char	mfjdfid;					/* �����͎ގ�	(0x20)			 */
	char	mfjdfnm[3];					/* ��-�̎ގ� �Ҏ� ("FMT")			 */
	short	mfjdfcnt;					/* �����Ɏ� ������					 */
	short	mfjdfdum;					/* �֎ˎ�						 */
};
typedef	struct	mfjdfmth	MFJDFMTH;

struct	mfjdfmt		{ 					/* 2���ގ����� FMT ���ގ�-�Ŏ� �Î�-�� 	 */
	long	mfjdfmtno;  				/* FMT ���ݎĎ� �ʎގݎ��ގ�  		 */
	char	mfjdstat;					/* ����-����					 */
										/*  0x00 : �������ގ���			 */
										/*  0x80 : �̎����� �������� �Ɏ�		 */
	char	mfjdfdum[3];				/* �֎ˎ�						 */
};
typedef	struct	mfjdfmt		MFJDFMT;

/*********************************************************************/
/*		���׎� ���ގ����Ύ� ���֎ˎ� ���ގ����Ŏ� �����Ď� �� �����͎ގ�						 */
/*********************************************************************/

#define    MFJNLWMT    0x80				/* WMT ���ގ����Ŏ� �����Ď� �֎� �����͎ގ� */
#define    MFJNLFMT    0x40				/* FMT ���ގ����Ŏ� �����Ď� �֎� �����͎ގ� */
#define    MFJNLDFT    0x20				/* 2���ގ����� FMT ���ގ����Ŏ� �����͎ގ�  */
#define    MFERRWMT    0x08				/* WMT ���׎� ������ �֎� �����͎ގ�	 */
#define    MFERRFMT    0x04				/* FMT ���׎� ������ �֎� �����͎ގ�	 */
#define    MFERRVMT    0x02				/* ���׎� ���ގ����Ύ� ���ݎ� �Îގ��� �����͎ގ�*/

/*********************************************************************/
/*		���ގ��� �����Ďގ� ���������� �����Ď� 										 */
/*********************************************************************/

#define    MFDNJPER    0x1C0B 			/* mf_jper					 */
#define    MFDNJWMT    0x1C06 			/* mf_jwmt					 */
#define	   MFDNJFMT	   0x1C07			/* mf_jfmt					 */
#define	   MFDNPRCV	   0x1858			/* mf_prcv				TD48 */
#define	   MFDNJDFT	   0x1C12			/* mf_jdft					 */
#define	   MFDNFCRT	   0x1904			/* mf_fcrt				TD48 */

#define    MFDTJPFMT   0x21000000 		/* mr_jedt(FMT) ���׎� (mf_jper)*/
#define    MFDTJPVMT   0x22000000 		/* mr_jedt(VMT) ���׎� (mf_jper)*/
#define    MFDTJPJNL   0x23000000 		/* mr_jnl  ���׎� 		(mf_jper)*/
#define    MFDTJPCPC   0x24000000 		/* mr_cpca ���׎� 		(mf_jper)*/
#define    MFDTJPJIN   0x25000000 		/* mr_jint ���׎� 		(mf_jper)*/
/***** LINUX�ܿ��б�		Start			��������2002.04.17	  ****/
#define    MFDTJPFMT2  0x26000000 		/* mr_jedt2(FMT)���׎� (mf_jper)*/
#define    MFDTJPVMT2  0x27000000 		/* mr_jedt2(VMT)���׎� (mf_jper)*/
/***** LINUX�ܿ��б�		 End			��������2002.04.17	  ****/

#define    MFDTJWJED   0x21000000 		/* mr_jedt ���׎�		(mf_jwmt)*/
#define    MFDTJWJNL   0x22000000 		/* mr_jnl  ���׎�		(mf_jwmt)*/
#define    MFDTJWCPC   0x23000000 		/* mr_cpca ���׎�		(mf_jwmt)*/
#define    MFDTJWJIN   0x24000000 		/* mr_jint ���׎�		(mf_jwmt)*/
/***** LINUX�ܿ��б�		Start			��������2002.04.17	  ****/
#define    MFDTJWJED2  0x25000000 		/* mr_jedt2���׎�		(mf_jwmt)*/
/***** LINUX�ܿ��б�		 End			��������2002.04.17	  ****/

#define    MFDTJFJED   0x21000000 		/* mr_jedt ���׎� 		(mf_jfmt)*/
#define    MFDTJFJNL   0x22000000 		/* mr_jnl  ���׎� 		(mf_jfmt)*/
#define    MFDTJFCPC   0x23000000 		/* mr_cpca ���׎� 		(mf_jfmt)*/
#define    MFDTJFJIN   0x24000000 		/* mr_jint ���׎� 		(mf_jfmt)*/
/***** LINUX�ܿ��б�		Start			��������2002.04.17	  ****/
#define    MFDTJFJED2  0x25000000 		/* mr_jedt2���׎� 		(mf_jfmt)*/
/***** LINUX�ܿ��б�		 End			��������2002.04.17	  ****/

#define    MFDTPRCV    0x21000000 		/* �̎����� �������������� ���׎� (mf_prcv)*/

#define    MFDTJDJED   0x21000000 		/* mr_jedt ����-      (mf_jdft)*/
#define    MFDTJDJNL   0x22000000 		/* mr_jnl  ����-      (mf_jdft)*/
#define    MFDTJDCPC   0x23000000 		/* mr_cpca ����-      (mf_jdft)*/
#define    MFDTJDJIN   0x24000000 		/* mr_jint ����-      (mf_jdft)*/
/***** LINUX�ܿ��б�		Start			��������2002.04.17	  ****/
#define    MFDTJDJED2  0x25000000 		/* mr_jedt2����-      (mf_jdft)*/
/***** LINUX�ܿ��б�		 End			��������2002.04.17	  ****/

#define    MFDTFCJED   0x21000000 		/* mr_jedt ����-(mf_fcrt) TD30 */
#define    MFDTFCJNL   0x22000000 		/* mr_jnl  ����-(mf_fcrt) TD30 */
#define    MFDTFCCPC   0x23000000 		/* mr_cpca ����-(mf_fcrt) TD30 */
#define    MFDTFCJIN   0x24000000 		/* mr_jint ����-(mf_fcrt) TD30 */
