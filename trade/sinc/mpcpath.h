/****************************************************************************/
/* �̎�����̾������mpcpath.h													*/
/* ��ǽ������  ���楹�ơ�����												*/
/*			   ����ƥ����ȥƥ�ץ졼�� 									*/
/* ����������  1993.12.15													*/
/* ����������																*/
/****************************************************************************/

/**************************************/
/* ���楹�ơ�����					  */
/**************************************/
#define  STSPINIT	  0x00				/* S200:̤�����ץ�					*/
#define  STSPOWIP	  0x01				/* S201:�����ץ��桿IP���Ďގڎ������Ԥ� */
#define  STSPOWAT	  0x02				/* S202:�����ץ��桿ATTACH��		*/
#define  STSPOWBD	  0x03				/* S203:�����ץ��桿BIND��			*/
#define  STSPOPEN	  0x04				/* S204:�����ץ�ѡ����Ȏ�������̤����	*/
#define  STSPOWLS	  0x05				/* S205:�����ץ�ѡ�LISTEN��		*/
#define  STSPOELS	  0x06				/* S206:�����ץ�ѡ�LISTEN��		*/
#define  STSPOWAS	  0x07				/* S207:�����ץ�ѡ���Ʊ�������Ԥ�	*/
#define  STSPOWAC	  0x08				/* S208:�����ץ�ѡ�ACCEPT��		*/
#define  STSPOACT	  0x09				/* S209:�����ץ�ѡ�ACTIVE������	*/
#define  STSPOCLW	  0x0A				/* S210:�����ץ�ѡ����ێ������Ԥ�		*/
#define  STSPDWSC	  0x0B				/* S211:����DEACT�桿�����Îю����ٲ����	*/
#define  STSPDWDT	  0x0C				/* S212:����DEACT�桿DETACH��		*/
#define  STSPDFRE	  0x0D				/* S213:����DEACT�桿������ 		*/
#define  STSPOWSC	  0x0E				/* S214:�����ץ��桿�����Îю����ٲ����	*/
#define  STSPOWDT	  0x0F				/* S215:�����ץ��桿DETACH��		*/
#define  STSPCWSC	  0x10				/* S216:�������桿�����Îю����ٲ����	*/
#define  STSPCWDT	  0x11				/* S217:�������桿DETACH��		*/
#define  STSPORCV	  0x12				/* S218:�ξ�����Ѥ�				*/

/**************************************/
/* ����ե饰���					  */
/**************************************/
#define FLGPSYN 	0x01				/* �忮�ե饰						*/
#define FLGPABRP	0x02				/* ���ܡ�������Ʊ���ե饰			*/

#define FLGPNULL	0x00				/* �ե饰�ʽ�����֡�				*/
/**************************************/
/* ����ƥ����ȥƥ�ץ졼�� 		  */
/**************************************/
typedef struct {
	long			chead[3];			/* �������塼�������				*/
	short			pathno; 			/* �����ѥ��ֹ� 					*/
	char			status; 			/* ���楹�ơ������������ѥ������	*/
	unsigned char	flags;				/* ����ե饰						*/
	unsigned short	lsno;				/* �̣��ֹ� 						*/
	unsigned char	cntsyscl;			/* �����ƥॳ����� 				*/
	char			reserve2;			/* ͽ�� 							*/
	long			lipaddr;			/* �����륤�󥿡��ͥåȥ��ɥ쥹	*/
	short			lport;				/* ������ݡ����ֹ�				*/
	unsigned short	lsnul;				/* �̣ӿ�							*/
	unsigned short	cntctxt;			/* ��������ƥ����ȿ�				*/
	unsigned short	maxctxt;			/* ���祳�ͥ�������				*/
	XQT 			ctxtqt; 			/* ���ͥ�����󥳥�ƥ����ȣѣ� 	*/
	long			listenqt[2];		/* �̣ɣӣԣţ��׵�ѣ� 			*/
	long			opnmsgp;			/* �����ץ��׵������				*/
	long			clsmsgp;			/* �������׵������				*/
	long			falmsgp;			/* �ξ������׵������				*/
	long			rcvmsgp;			/* �ξ���������׵������			*/
	long			cfremsgp;			/* ���ͥ���������(���Ύގ���)�׵������*/
	long			linctxtp;			/* �������楳��ƥ����ȥ��ɥ쥹 	*/
	unsigned long	maxrbuff;			/* �����Хåե������������ 		*/
	unsigned long	minrbuff;			/* �����Хåե������������� 		*/
	unsigned long	maxsbuff;			/* �����Хåե������������ 		*/
	unsigned long	minsbuff;			/* �����Хåե������������� 		*/
	long			pdacirbp;			/* �ѥ��ģţ��ã���������� 		*/
	short			failinfo;			/* �ξ���� 						*/
	unsigned char	maxsndrq;			/* Ʊ�������׵�����				*/
	unsigned char	maxrcvrq;			/* Ʊ�������׵�����				*/
	unsigned short	cntlstrq;			/* �̣ɣӣԣţ��׵��				*/
	unsigned short	timdetch;			/* �ģţԣ��ãȥ��󥿡��Х륿����	*/
}	MPCPMB;
