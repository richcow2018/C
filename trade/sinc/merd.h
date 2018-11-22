/**********************************************/
/*                                            */
/*                 merd.h                     */
/*                                            */
/*            rd ���ݎ؎��� �̎����ώ���                 */
/*											  */
/*		�ѹ���95.5.18 AA	�ѹ��� ���� �ῥ  */
/*		�ѹ���95.10.20 BB	�ѹ��� ��ƣ ͳ��  */
/*		�ѹ���96.03.26 CC	�ѹ��� ��ƣ ͳ��  */
/*		�ѹ���2003.02.17 DD	�ѹ��� ���� ���  */
/*                                            */
/**********************************************/
#define  RDUSATT  0x0104              /*������Ū(���Îݎ����������׵�)��   */
#define  RDUSHID  0x0105              /*������Ū(��Ʊ�������׵�)��   */
#define  RDUSMAIL 0x0201              /*������Ū(���̎Ҏ��ټ����׵�)    */
#define  RDUSTIM  0x0301              /*������Ū(��������Ͽ)            */
#define  RDUSIOP  0x0101              /*������Ū(�َ��̎�I/O�����̎ߎ�)��  �� */
#define  RDUS4OP  0x0102              /*������Ū(4W-NTM�����̎ߎݴ�λ����)*/
#define  RDUS4AT  0x0103              /*������Ū(4W-NTM�����̎ߎݻ�ATT��) */
#define  RDUSIRE  0x0106              /*������Ū(I/O�؎��Ď�)            */
#define  RDUSIWR  0x0107              /*������Ū(I/O�׎���)����         */
#define  RDUSIWS  0x0108              /*������Ū(I/O�׎���&���ݎ�)         */
#define  RDUSISN  0x0109              /*������Ū(I/O���ݎ�)����         */
#define  RDUSICN  0x010A              /*������Ū(I/O���ݎĎێ���)          */
/******************************/
/* �̎�����������ǽ�ɲäΰ٤��ѹ� */
/******************************/
#define  RDUSFSN  0x0401              /*������Ū(�̎���������)           */
#define  RDUSFRV  0x0402              /*������Ū(�̎����ټ���)           */
/******************************/
/* 4W on X.25 �ΰ٤��ѹ�      */
/******************************/
#define  RDUS4WOP 0x0501              /*������Ū(4WonX.25 osiopen) AA*/
#define  RDUS4WRE 0x0502              /*������Ū(4WonX.25 osiread) AA*/
#define  RDUS4WCT 0x0503              /*������Ū(4WonX.25 control) AA*/
#define  RDUS4WWR 0x0504              /*������Ū(4WonX.25 W.R.�Ԥ�)AA*/
#define  RDUS4WRR 0x0505              /*������Ū(4WonX.25 W.R.�Ԥ�)AA*/
#define  RDUS4WCR 0x0506              /*������Ū(4WonX.25 W.R.�Ԥ�)AA*/
#define  RDUS4WSR 0x0507              /*������Ū(4WonX.25 W.R.�Ԥ�)AA*/
#define  RDUS4WHD 0x0508              /*������Ū(4WonX.25��Ʊ������)AA*/
#define  RDUS4WRCV 0x0509             /*��Ū(��ư�����ю�����) 	   CC*/
#define  RDUS4WROP 0x050a             /*��Ū(�ƥ����ץ��ю�����) 	   CC*/
#define  RDUS4WRCT 0x050b             /*��Ū(�������ȥ饤�ю�����)  CC*/

/***********************************/
/* 4W on X.25(4W-NTM) �ΰ٤��ɲ� BB*/
/***********************************/
#define  RDUS4WNOP 0x0601             /*������Ū(4WonX.25 osiopen) BB*/
#define  RDUS4WNRE 0x0602             /*������Ū(4WonX.25 osiread) BB*/
#define  RDUS4WNCT 0x0603             /*������Ū(4WonX.25 control) BB*/
#define  RDUS4WNWR 0x0604             /*������Ū(4WonX.25 W.R.�Ԥ�)BB*/
#define  RDUS4WNRR 0x0605             /*������Ū(4WonX.25 W.R.�Ԥ�)BB*/
#define  RDUS4WNCR 0x0606             /*������Ū(4WonX.25 W.R.�Ԥ�)BB*/
#define  RDUS4WNSR 0x0607             /*������Ū(4WonX.25 W.R.�Ԥ�)BB*/
#define  RDUS4WNHD 0x0608             /*������Ū(4WonX.25��Ʊ������)BB*/
#define  RDUS4WNIRT 0x0609            /*��Ū(4WonX.25IRT��λ�Ԥ�) BB*/
#define  RDUS4WNRCV 0x060a            /*��Ū(��ư�����ю�����) 	   CC*/
#define  RDUS4WNROP 0x060b            /*��Ū(�ƥ����ץ��ю�����) 	   CC*/
#define  RDUS4WNRCT 0x060c            /*��Ū(�������ȥ饤�ю�����)  CC*/

//**********************************//
// V7�ۥ����̿���					//
//**********************************//
#define	RDUSV7OPTM	0x0701				// �ƥ����ץ��ȥ饤��������	DD

struct merdkyo {
	short	merdmax ;             /* �������ގ� RD ���ݎ؎���              */
	short	merdent ;             /* RD ���ݎ؎���                    */
};
typedef struct merdkyo MERDKYO;

struct merdko {
	short	merduse ;             /*������Ū                     */
	short	merdidno;             /*���̾���                     */
	long	merdrdid;             /*RD                           */
	short	merdsize;             /*��ͭ���󎻎�����                 */
	short	merdtmid;             /*������ ID                       */
	long    merdurid;             /*�Վ����ގ؎������ļ��̻�              */
    char    merdpinf[48];         /*��ͭ���󡡡���               */
};
typedef struct merdko MERDKO;
