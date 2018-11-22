/********************************************************************/
/* ��������                                                         */
/********************************************************************/
/* �㳲�ֹ�   : TBCS0066                                            */
/* �㳲����   : MIA���̰�˻��ꤷ���ǡ�������������ʸ�����ꤵ��ʤ� */
/* ��������   : MIA�����������������å��������ɲ�                   */
/* ��������   : 2003.04.24                                          */
/* ������     : Supply Sugawara                                     */
/********************************************************************/

/****************************************/
/*	������������					*/
/****************************************/
#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <ctype.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <sys/ipc.h>
#include    <sys/msg.h>
#include	<fcntl.h>
#include    <errno.h>
#include	"mcmia.h"
#include	"smpmsg_hed.h"
#include	"smpmsg_com.h"
/**/
/****************************************/
/*	���󥹥���Ⱦ���					*/
/****************************************/
/*	��ʸ��ѥץ�������				*/
#define		DEF_MOJ_PROCNM		"moj"
#define		DEF_MOJ_ARRIVE		"ps -a -eo %c | grep moj"
/*	�ֵ������							*/
#define		RTN_OK				0		/*  ����						*/
#define		RTN_NG_PRM			-1		/*  �۾�ʥѥ�᡼�����顼)		*/
#define		RTN_NG_MOJ			-2		/*	�۾�ʣͣϣ���¸��ǧ���ԡ�	*/
#define		RTN_NG_FL_OPEN		-3		/*	�۾�ʥե����륪���ץ��ԡ�*/
#define		RTN_NG_FL_READ		-4		/*	�۾�ʥե�����꡼�ɼ��ԡ�	*/
#define		RTN_NG_FL_CLOSE		-5		/*	�۾�ʥե����륯�������ԡ�*/
#define		RTN_NG_MOJ_KEY		-6		/*	�۾�ʣͣϣʥ����������ԡ�	*/
#define		RTN_NG_MOJ_QUE		-7		/*	�۾�ʣͣϣʥ��塼�������ԡ�*/
#define		RTN_NG_SND_AREA		-8		/*	�۾��������ʸ����ݼ��ԡ�	*/
#define		RTN_NG_MY_KEY		-9		/*	�۾�ʼ������������ԡ�		*/
#define		RTN_NG_MY_QUE		-10		/*	�۾�ʼ����塼�������ԡ�	*/
#define		RTN_NG_MSG_SND		-11		/*	�۾����ʸ�������ԡ�		*/
#define		RTN_NG_ACC_SND		-12		/*	�۾����ã��ǧ���ԡ�		*/
#define		RTN_NG_MSG_RCV		-13		/*	�۾����ʸ�������ԡ�		*/
#define     RTN_NG_MIAKDATA     -14		/*  �۾� (MIA�������������۾�)	*//* TBCS0066 */
#define     RTN_NG_CHDATA		-15		/*  �۾� (�ǡ����Ѵ�����)		*//* TBCS0066 */
/*	�ѥ�᡼�������å�������			*/
#define		CK_PRM_MIN		3			/*	�ѥ�᡼���Ǿ���			*/
#define		CK_PRM_MAX		10			/*	�ѥ�᡼��������	        */
#define		CK_PRM_LEN1		1			/*	��󥰥��ᣱ				*/
#define		CK_PRM_LEN8		8			/*	��󥰥��᣸				*/
#define		CK_PRM_MIA_OPT	"-l"		/*	�ͣɣ����ץ����			*/
#define		CK_PRM_MIA_MIN	4			/*	�ͣɣ��Ǿ���				*/
#define		CK_PRM_SND_OPT	"-n"		/*	����������ץ����			*/
#define		CK_PRM_SND_MIN	0			/*	��������Ǿ���				*/
#define		CK_PRM_SND_MAX	100			/*	�������������				*/
#define		CK_PRM_CHK_OPT	"-s"		/*	��ã��ǧ���ץ����			*/
#define		CK_PRM_TIM_OPT	"-t"		/*	�����ֳ֥��ץ����			*/
#define		CK_PRM_TIM_MIN	1			/*	�����ֳֺǾ���				*/
/*	����������						*/
#define		PROC_TYPE_MY	0			/*	���ץ���					*/
#define		PROC_TYPE_PAT	1			/*	���ץ���				*/
/*	�ǥե���Ⱦ���						*/
#define		DEF_FLG_ON		1			/*	�ե饰�ϣ�					*/
#define		DEF_FLG_OFF		0			/*	�ե饰�ϣƣ�				*/
#define		DEF_MIA_LEN		168			/*	�ͣɣ��ǥե������			*/
#define		DEF_SND_NUM		1			/*	��������ǥե������		*/
#define		DEF_TIM_SND		5			/*	�����ֳ֥ǥե������		*/
#define		DEF_SND_UNLIMIT	0			/*	̵��������					*/
/*	�����ؿ��ֵѾ���					*/
#define		STC_PRC_OK		0			/*	�����ؿ�����				*/
#define		STC_PRC_NG		-1			/*	�����ؿ��۾�				*/
/**/
/****************************************/
/*	����������						*/
/****************************************/
typedef	struct {
	long	ua_lenMia;					/*	�ͣɣ����̰�Ĺ�ʰ�����		*/
	long	ua_noSend;					/*	��������ʰ�����			*/
	int		ua_fAccChk;					/*	��ã��ǧ�ե饰�ʰ�����		*/
	int		ua_tmSend;					/*	�������ֳ֡ʰ�����			*/
/**/
	long	ua_noRtySend;				/*	���������					*/
	int		ua_Rslt;					/*	���顼�ܺپ���				*/
	long	ua_idProc;					/*	���ץ����ɣ�				*/
	char	*ua_pSndData;				/*	��ʸ��Ѱ�����ʸ�ݥ���	*/
	SMPMSGHED	ua_pRcvData;			/*	��ã��ǧ��ʸ�ݥ���		*/
	struct {							/*	���ץ�������				*/
		long	ua_MyProcMbox;			/*	�ᥤ��ܥå����ɣ�			*/
		int		ua_MyProcPrj;			/*	�ץ����ץ������Ⱦ���	*/
		key_t	ua_MyIpcKey;			/*	��å���������				*/
		int		ua_MyIpcQid;			/*	��å��������塼�ɣ�		*/
	}InfoMyProc;
	struct {							/*	���ץ�������			*/
		long	ua_PartProcMbox;		/*	�ᥤ��ܥå����ɣ�			*/
		int		ua_PartProcPrj;			/*	�ץ����ץ������Ⱦ���	*/
		key_t	ua_PartIpcKey;			/*	��å���������				*/
		int		ua_PartIpcQid;			/*	��å��������塼�ɣ�		*/
	}InfoPartProc;
}USER_AREA;
/**/
/****************************************/
/*	�ؿ����							*/
/****************************************/
int		ParamaterCheck (USER_AREA* ,int ,char**);
int		MojArriveCheck (USER_AREA* ,long*);
void	GetSysLog (char* ,char* ,char*);
int		chcnData(char * , char*, int ) ;			/* TBCS0066			*/
/**/
/****************************************/
/*  ��å������������                  */
/****************************************/
#define		MSG_COUNT	50
#define		MSG_STOPER	"FFFF"
struct  tabMsg  {
char	*MsgNumber;
char	*MsgInfo;
};
