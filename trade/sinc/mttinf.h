/****************************************************************************/
/*  ���  ��������                                                        */
/*            �Σԣԥǡ����̿��������                                      */
/*              ��ͻ�����ƥ��������                                        */
/*  ����ʪ  ���ãšݣӣͣХ������ץ������									*/
/****************************************************************************/
/* ���оݶ�̳̾��                   ���ãšݣӣͣ�                          */
/* ���оݶ�̳�ɣġ�                 ��ž������̳							*/
/* �㥵���ӥ�����̾��               �ӣͣХơ��֥�����						*/
/* �㥵���ӥ����ܣɣġ�             �ԣ£�									*/
/* ��⥸�塼��̾��                 �ơ��֥�ե�������ƾ���				*/
/* ��⥸�塼��ɣġ�				���ᣳ��								*/
/* ��⥸�塼�����֡�                                                       */
/*--------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��                   ���ã�                                  */
/* ��Ŭ�ѣϣӡ�                     �ԣң��ģ�                              */
/* �㳫ȯ�Ķ���                     �ӣգΡ��ӣУ��ң�                      */
/* �㵭�Ҹ����                     �ø���                                  */
/* ��⥸�塼����֡�               �إå��ե�����							*/
/*--------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��               ���ãšݣӣͣХ����ƥ�                  */
/* �㳫ȯ�����ƥ��ֹ��             ����������������������                  */
/*--------------------------------------------------------------------------*/
/* �㳫ȯô��̾��                   �Ķ�Ź�����ƥ�ô��                      */
/* �������ֹ��                     169-3573(03-5702-3573)                  */
/*--------------------------------------------------------------------------*/
/* ���߷׼�̾��                     �ˣӣСʳ��ˡ�����������				*/
/* ���߷�ǯ������					��������ǯ���������			ST4970	*/
/* ���߷׽����ԡ�															*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/* �㥽���������ԡ䡡��             �ˣӣСʳ��ˡ�����������				*/
/* �㥽��������ǯ������				��������ǯ���������			ST4970	*/
/* �㥽���������ԡ�															*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                             */
/*	���ơ��֥�ե�������ƾ����Ϣ											*/
/*--------------------------------------------------------------------------*/
/* �����»����                                                             */
/*     �äˤʤ�                                                             */
/****************************************************************************/
#if MTTINFINC
#else
#define MTTINFINC 1
/****************************************************************************/

#if MTINC
#else
#include "mt.h"
#endif

#ifndef MCNMAL
#include <mc.h>
#endif
/*----------------------------------*/
/* �ơ��֥�ե�������ƾ���			*/
/*----------------------------------*/
#define MTTBLNUM	6					/* �ơ��֥�ե���������			*/

#define MTPU0IDX	0					/* PU0¦������Ƭ��Ǽ����			*/
#define MTPU1IDX	4					/* PU1¦������Ƭ��Ǽ����			*/

#define MTSKTFD		0					/* �������̡��ե�����ǥ�������ץ�	*/
#define MTSKMDR		1					/* �������̡��ޥ���ȥǥ��쥯�ȥ�	*/
#define MTSKTFP		2					/* �������̡��ơ��֥�ե�����		*/

										/*----------------------------------*/
typedef struct {						/* �ơ��֥�ե�������ƾ���			*/
	char	*volpath;					/* �ü�ե�����ѥ�̾				*/
	char	*mntpath;					/* �ޥ������ǥ��쥯�ȥ�ѥ�̾		*/
	char	*tblpath;					/* �ơ��֥�ե�����ѥ�̾			*/
	char	*filename;					/* �ơ��֥�ե�����̾				*/
	long	bsdevid;					/* SCSI�Х�major|minor				*/
	long	uidevid;					/* ���֎��ݎ��܎�����major|minor			*/
	long	urdevid;					/* ���֎؎�����major|minor				*/
	char	etype;						/* ���ּ���							*/
	char	rsv[3];						/* ̤����							*/
} MTTFINF;

										/*----------------------------------*/
typedef struct{							/* �ꥻ�å��ѥѥ�̾���å�			*/
	char	bspath[32];					/* SCSI�Х�INQUERY|RESET			*/
	char	uipath[32];					/* ����INQUERY						*/
	char	urpath[32];					/* ����RESET						*/
	char	etype;						/* ���ּ���							*/
} MTSPLST;

/*------------------------------------------------------*/
/* �Х��ꥻ�åȡ����󥯥磻�������ü�ե��������֣ɣ�	*/
/* PU(PU�ֹ�) CN(����ȥ������ֹ�) SI(SCSI ID)			*/
/* ��������major�������ֹ��ޤޤʤ�					*/
/*------------------------------------------------------*/
#define	MTBSDEVID(PU, CN, SI) \
	( 0x002C0000L | ((((long)(PU)) << 24) & 0x01000000L) \
				  | ((((long)(CN)) << 12) & 0x0000F000L) \
				  |	((((long)(SI)) <<  8) & 0x00000700L) )

/*------------------------------------------------------*/
/* ���֥��󥯥磻�������ü�ե��������֣ɣ�				*/
/* PU(PU�ֹ�) CN(����ȥ������ֹ�) SI(SCSI ID) LN(LUN)	*/
/* ��������major�������ֹ��ޤޤʤ�					*/
/*------------------------------------------------------*/
#define MTUIDEVID(PU, CN, SI, LN) \
	( 0x002C0000L | ((((long)(PU)) << 24) & 0x01000000L) \
				  | ((((long)(CN)) << 12) & 0x0000F000L) \
				  | ((((long)(SI)) <<  8) & 0x00000700L) \
				  | ((((long)(LN)) <<  4) & 0x00000030L) )

/*------------------------------------------------------*/
/* ���֥ꥻ�å����ü�ե��������֣ɣ�					*/
/* MJ(major#) MN(minor#)								*/
/* ��������major�������ֹ��ޤޤʤ�					*/
/*------------------------------------------------------*/
#define MTURDEVID(MJ, MN) \
	( ((((long)(MJ)) << 16) & 0x01FF0000L) | (((long)(MN)) & 0x0000FFFFL) )


#define MTMRSOK		"ST00"				/* SCSI�ꥻ�å������ͣӣ�			*/
#define MTMRSNG		"ST01"				/* SCSI�ꥻ�åȼ��ԣͣӣ�			*/
/*------------------------------------------------------*/
/* SCSI�ꥻ�å������ͣӣǽ���							*/
/* P1(�ꥻ�å��о��ü�ե�����ѥ�̾					*/
/*------------------------------------------------------*/
#define MTSOKMSG(P1) {\
extern long mt_cwtm();\
char	msg[128];\
char	*path = (char *)(P1);\
	strcpy(msg, MTMRSOK);\
	strcat(msg, "\t");\
	strcat(msg, ((0 == path) || (path[0] == '\0'))? \
				"Unknown............." : path);\
	(void)mt_cwtm(msg);\
}

/*------------------------------------------------------*/
/* SCSI�ꥻ�åȼ��ԣͣӣǽ���							*/
/* P1(�ꥻ�å��о��ü�ե�����ѥ�̾					*/
/* P2(�����ƥॳ�������) P3(�����ƥॳ�����ֵ���)		*/
/*------------------------------------------------------*/
#define MTSNGMSG(P1,P2,P3) {\
extern long mt_cwtm();\
char	msg[128];\
char	func[sizeof(long)*2+1];\
char	result[sizeof(long)*2+1];\
char	*path = (char *)(P1);\
long	id = (long)(P2);\
long	ret = (long)(P3);\
	func[8] = '\0';\
	result[8] = '\0';\
	strcpy(msg, MTMRSNG);\
	strcat(msg, "\t");\
	if ((0 == path) || (path[0] == '\0')){ \
		strcat(msg, "Unknown.............");\
	}\
	else{\
		strcat(msg, path);\
		strcat(msg, "\t");\
		(void)mc_hccn(&id, func, sizeof(long)*2);\
		strcat(msg, (func[0])? func : "********");\
		strcat(msg, "\t");\
		(void)mc_hccn(&ret, result, sizeof(long)*2);\
		strcat(msg, (result[0])? result : "********");\
	}\
	(void)mt_cwtm(msg);\
}

/*------------------------------*/
/* mt_srtn�ؿ��ֵ���			*/
/*------------------------------*/
#define MTSRTNETC	0					/* �ꥻ�å�����						*/
#define MTSRTNBR	1					/* �Х��ꥻ�å���					*/
#define MTSRTNUR	2					/* ���֥ꥻ�å���					*/
#define MTSRTNRE	3					/* �ٱ��ȥ饤��					*/
/****************************************************************************/
#endif