/**********************************************************************/
/* �ե�����̾����mpcrqmsg.h 										  */
/* ��ǽ����  ��  �׵᡿������ʸ 									  */
/* ��������  ��  1993.11.22 										  */
/* ��������  �� 													  */
/**********************************************************************/
#include <mehikyo.h>
#include <mpcomand.h>
/**************************************/
/* �׵᡿������ʸ�ƥ�ץ졼��		  */
/**************************************/
typedef struct {
	MDHIKYO 	com;
	MPCOMAND	usr;
} MPCRQMSG;

/**************************************/
/* �����������׵ᡦ�����ƥ�ץ졼��   */
/**************************************/
typedef struct {
	MDHIKYO 	com;					/* ������							*/
	MPCOMAND	usr;					/* ���ޥ���ΰ� 					*/
	struct {
		long	reserve0[4];			/* �إå��� 						*/
	} head;
} MPCMSGRW;

/**************************************/
/* �۵ޥǡ��������ƥ�ץ졼��		  */
/**************************************/
typedef struct {
	MDHIKYO 			com;			/* ������							*/
	MPCOMAND			usr;			/* ���ޥ���ΰ� 					*/
	struct {
		long	reserve0[2];			/* �ꥶ���� 						*/
	} head;
} MPCMSGSO;
/**************************************/
/* �۵ޥǡ��������ƥ�ץ졼��		  */
/**************************************/
typedef struct {
	MDHIKYO 	com;					/* ������							*/
	MPCOMAND	usr;					/* ���ޥ���ΰ� 					*/
	struct {
		short	reserve0[3];			/* �ꥶ���� 						*/
	}	head;
	char	oob_data;					/* �۵ޥǡ���						*/
	char	reserve1;					/* �ꥶ���� 						*/
} MPCMSGRO;

#define PBUFFMAX	0x7ffc				/* �ס���Хåե���˥åȺ���Ĺ 	*/

/**************************************/
/* ��å�����Ĺ 					  */
/**************************************/
#define MPCMSZRQ	sizeof(MPCRQMSG)	/* �׵���ʸĹ						*/
#define MPCMSZRW	sizeof(MPCMSGRW)	/* ��ʸ�����׵�Υ�å�����Ĺ		*/
#define MPCMSZHI	PBUFFMAX			/* �����������Υ�å�����Ĺ�ʾ�¡� */
#define MPCMSZRO	sizeof(MPCMSGRO)	/* �۵ޥǡ��������ǡ��� 			*/
#define MPCMSZSO	sizeof(MPCMSGSO)	/* �۵ޥǡ��������Υ�å�����Ĺ 	*/

/**************************************/
/*	�ǡ���Ĺ						  */
/**************************************/
#define MPCDSZRW	PBUFFMAX - MPCMSZRQ /* ��ʸ�����Υǡ���Ĺ				*/
#define MPCDSZHD	16					/* ��ʸ��������ʸ�����κǾ��ǡ���Ĺ */
#define MPCMAXSO	MPCMSZSO - MPCMSZRQ + 1024
										/* �۵ޥǡ��������Υǡ���Ĺ�κ����� */
#define MPCMINSO	MPCMSZSO - MPCMSZRQ
										/* �۵ޥǡ��������Υǡ���Ĺ�κǾ��� */
#define MPCDSZRO	8					/* �۵ޥǡ��������Υǡ���Ĺ 		*/
