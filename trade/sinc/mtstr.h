#define  UCHAR	unsigned char
/*********************************************************************/
/*	 �����Ɏ� �� �׎Ҏ� ���ގ֎��Ύ� ��-�̎ގ�										 */
/*********************************************************************/
struct	mtparat  {
	long  mtprcnt;						/*	�� �׎Ҏ� �� ������ 			 */
	char  *mtpradr[MTPARA]; 			/*	�� �׎Ҏ� �����ӎ� �� ���Ďގڎ�		 */
};
typedef  struct  mtparat  MTPARAT;
/*********************************************************************/
/*	 �̎�-�ώ� ���ގ֎��Ύ� ��-�̎ގ�											 */
/*********************************************************************/
struct	mtitem{
	short mtitmsz;						/*	1�����ӎ� �� ��������			 */
	UCHAR mtitmfm;						/*	1�����ӎ� �� ��������			 */
	UCHAR mtitdmy;						/*	���ގ�- �؎Վ�����				 */
};
struct	mtfmttl  {
	long  mtitemc;						/*	�� �׎Ҏ� �����ӎ� �� ������		 */
	long  mtfckct;						/*	�̎�-�ώ� ������ �����ݎ�		 */
	struct	mtitem	mtitmst[MTITEM];
};
typedef  struct  mtfmttl  MTFMTTL;
/*********************************************************************/
/*	 ��-�̎ގ� �������� ���ގ֎��Ύ� ��-�̎ގ�										 */
/*********************************************************************/
struct	mttable  {
	long  mtmsgid;						/*	�Ҏ�-���� �����ގՎ�			 */
	UCHAR mttname[MTTBID];				/*	��-�̎ގ� �����͎ގ�			 */
	UCHAR mtpraid;						/*	�� �׎Ҏ� ���Վ͎ގ� 			 */
	UCHAR mtctflg;						/*	�������ގ� �̎׎���				 */
	UCHAR mtminer;						/*	����- �̎׎���(1) 			 */
	UCHAR mterflg;						/*	����- �̎׎���(2) 			 */
	short mtalitm;						/*	�����ӎ� ���� 				 */
	short mtckcnt;						/*	������ ���ގ� �����ӎ� ����		 */
	short mtstcnt;						/*	���� ���ގ� �����ݎ�			 */
	short mtckcra;						/*	������ ���ގ� �ӎ��ގ���			 */
	char  *mtvctad; 					/*	vct �� ���Ďގڎ� 			 */
	UCHAR mtcctfg;						/*	�ӎ��ގ������ގ� �̎׎���			 */
	UCHAR mtbctflg; 					/*	�ώ� �� �ӎ��ގ������ގ� �̎׎���		 */
	UCHAR mtfmtfg;						/*	�̎�-�ώ� �̎׎��� 			 */
	UCHAR mthexfg;						/*	hex �̎׎���				 */
	long  mtline;						/*	�׎��� �Ŏݎʎގ�				 */
	short mtcmtfg ;						/*	���Ҏݎ� �̎׎���				 */
	short mtcmtcnt ;					/*	���Ҏݎ� �����ݎ�				 */
};
typedef  struct  mttable  MTTABLE;
/*********************************************************************/
/*	 �ʎގ̎� �������� ��-�̎ގ�												 */
/*********************************************************************/
struct	mtbftbl  {
	long  mtpolid;						/*	�� -�� �����͎ގ� 			 */
	long  mtbfcnt;						/*	�ʎގ̎� �� ������ 			 */
	long  mtbufid[MTITEM];				/*	�� -�� �����͎ގ� 			 */
	char  *mtbufad[MTITEM]; 			/*	�ʎގ��̎� ���Ďގڎ� 			 */
};
typedef  struct  mtbftbl  MTBFTBL;
/*********************************************************************/
/*	 ����-�Ҏ�-���ގʎߎ׎�-�� ��-�̎ގ�											 */
/*********************************************************************/
struct mtempr {
	union	{							/* �ʎߎ׎�-�� �� �Ύߎ��ݎ�			 */
		short	*cngpms;
		long	*cngpml;
		char	*cngpmc;
	} cngprm;
	long cnglen;						/* �ʎߎ׎�-�� �� �Ŏ��ގ�			 */
};
struct mtempt {
	long cngn;							/* �ʎߎ׎�-�� �� ������ 			 */
	struct mtempr parmdt[MTMSPT];
};
typedef	struct mtempt	MTEMPT;
/*********************************************************************/
/*	 ����-�Ҏ�-���� ��-�̎ގ�												 */
/*********************************************************************/
struct mtermsg {
	long errno; 						/* ����- �Ҏ�-����NO 			 */
	UCHAR errmg[MTMSG]; 				/* ����- �Ҏ�-����				 */
	long permn; 						/* �ʎߎ׎�-�� ����				 */
	struct mlcftbl pardat[MTMSPT];
};
typedef	struct mtermsg	MTERMSG;
