/****************************************************************************/
/* 		OCP�Υ��󥯥롼�ɥե�����											*/
/****************************************************************************/
 
#define  MOSPSIZE 0x00010000L
#define  MOSCMID  0x00060000L

#define  MOSTOP   1L
#define  MORSTAT  2L
#define  MOSTART  3L
#define  MOIPL    4L
#define  MODOWN   5L
#define  MOCHG    6L
#define  MOREV    5L

#define  MOMSGOK  0L
#define  MOMSGNG  1L

#define	 MOSETEXNUM 31L							/* ossetex2������				PRC-055-01 */
#define  MOINITSYS	0x00010001					/* os_initSystem �Ѱ���			PRC-008-04 */

/****************************************************************************/
/* 		��ư���ץ�������													*/
/****************************************************************************/

struct mopinf{
    long             moogrsv;				/* �ꥶ����						*/
    unsigned char    moogkcl;				/* �϶�ʬ						*/
    unsigned char    moogrsv3;				/* �ꥶ����3					*/
    short            moogrsv4;				/* �ꥶ����4					*/
    unsigned char    moogpnm[8];			/* �ץ������̻�				*/
    long             moogclno;				/* ���󥽡�������				*/
    long             moogrsv2;				/* �ꥶ����2					*/
	long			 moontcn;				/* 						TD01	*/
	long			 mooexmo;				/*						TD01	*/
};
typedef  struct  mopinf  MOPINF;

/****************************************************************************/
/* 		��λ����															*/
/****************************************************************************/

struct terminf{
    long             type;					/* ��λ����						*/
    long             code;					/* ��λ������					*/
    long             dtal;					/* �ܺپ���						*/
};

