#include "mf.h"
#include "mlcdef.h"
#include "mlcstr.h"
/*********************************************************************/
/*   �ƎՎ����Վ؎֎� ���ގ֎��Ύ� ��-�̎ގ�                                          */
/*********************************************************************/
struct mlnioif {
	long iofrm;                         /* �ƎՎ����Վ؎֎���������             */
	long indes;                         /* �ƎՎ��؎֎��̎����َ����ގՎ�          */
	long outdes;                        /* ���Վ؎֎��̎����َ����ގՎ�          */
	long filpos;                        /* ���Վ؎֎��̎����َ֎Ў��Ў���          */
};
typedef	struct mlnioif	MLNIOIF;
MLNIOIF ioift;
/*********************************************************************/
/*   ��-�̎ގَ������� ���ގ֎��Ύ� ��-�̎ގ�                                          */
/*********************************************************************/
struct mlntlif{
	long tblfrm;                        /* ��-�̎ގ� ��������                */
	long tlfdes;                        /* ��-�̎ގَ̎����� �����ގՎ�          */
	long tdofrm;                        /* ���Վ؎֎� ��������               */
	long tdofds;                        /* ���ގݎ̎ߎ��������Վ؎֎��̎����� �����ގՎ� */
	char *tbldsc;                       /* ��-�̎ގَ����͎ގ� �Ύߎ��ݎ�         */
	long ykentn;                        /* �Վ����� ���ݎĎ؎���               */
	long kbtlen;                        /* 1���͎ގ̎� �� ��������            */
	long sublen;                        /* ���̎ގ��֎����̎� �� ��������         */
	long intbno;                        /* ��-�̎ގ� �� �����ގݎʎގݎ��ގ�        */
	long tdtcb;                         /* ��-�̎ގ� ���ݎ� �̎ގێ� ���Ďގڎ�     */
};
typedef	struct mlntlif	MLNTLIF;
/*********************************************************************/
/*  �������ݎʎގ̎� ��-�̎ގ�                                                  */
/*********************************************************************/
struct mlnbfif{
	char *bufadr;                       /* �������ݎʎގ̎� ���Ďގڎ�           */
	char *bfitmt;                       /* �ʎގ̎� �ƎՎ��؎֎����ގ֎����� ��-�̎ގ�  */
};
struct mlnbuft
{
	long bufn;                          /* �������ݎʎގ̎�����               */
	struct mlnbfif bufitm[MLNMXBF];
};
typedef	struct mlnbuft	MLNBUFT;
/*********************************************************************/
/*   ��-�̎ގَʎގ̎� �ƎՎ��؎֎����ގ֎����� ��-�̎ގ�                                   */
/*********************************************************************/
struct mlntbit{
	long kbtno;                         /* �������ݎ��͎ގŎݎʎ�-             */
};
typedef	struct mlntbit	MLNTBIT;
/*********************************************************************/
/*   �̎����َʎގ̎� �ƎՎ��؎֎����ގ֎����� ��-�̎ގ�                                    */
/*********************************************************************/
struct mlnfbit {
	long recno;                         /* �������ݎڎ�-�Ď� �ʎގݎ��ގ�          */
	long bfpos;                         /* ����                        */
	long bflen;                         /* �Ŏ��ގ�                      */
	short bfkeyn;                       /* �������ݎڎ�-�Ď� �ƎՎ��؎֎����ގ֎����� ���� */
	short bfdmy;
	MFCOND *itmkey[MLNMXKY];
};
typedef	struct mlnfbit	MLNFBIT;
/*********************************************************************/
/*  �̎����َ������� ���ގ֎��Ύ� ��-�̎ގ�                                            */
/*********************************************************************/
struct mlnflif {
	long fdofrm;                        /* ���Վ؎֎� ��������               */
	long fdofds;                        /* ���ގݎ̎ߎ� ���Վ؎֎��̎����� �����ގՎ�*/
	long inflno;                        /* �ƎՎ��؎֎��̎����� �����ގݎʎގݎ��ގ�     */
	long filadr;                        /* �̎����َ��ݎ� �̎ގێ����Ďގڎ�        */
	char *flfnam;                       /* �َ̎ʎߎ��̎����َҎ�               */
	char *filnam;                       /* �̎����َҎ� �Ύߎ��ݎ�              */
	char filtyp;                        /* �̎����� �����̎�                 */
	char fildmy[3];                     /* ���ގ�-                      */
	long filrdl;                        /* �ڎ�-�Ď� ���֎�                 */
	long filkyn;                        /* ��- ����                     */
	long filbkl;                        /* �̎ގێ� ���֎�                 */
	long kmtno;                         /* KMT ���ݎĎ�-�Ŏݎʎ�-            */
	char *dmbfad;                       /* ���ގ�-�ʎގ̎� ���Ďގڎ�           */
};
typedef	struct mlnflif	MLNFLIF;
/*********************************************************************/
/*   �����ڎ�-�Ď� ���Î��� ��-�̎ގ�                                            */
/*********************************************************************/
struct mlnespr {
	long addpos;                        /* ����                        */
	char *addpri;                       /* ������                       */
	long addlen;                        /* �Ŏ��ގ�                      */
};
struct mlnadpr {
	char clear;                         /* ���؎���                      */
	char dum[3];                        /* ���ގ�-                      */
	long eprin;                         /* ���Î�������                   */
	struct mlnespr estpri[MLNMAPR];
};
typedef	struct mlnadpr	MLNADPR;
/*********************************************************************/
/*   �������ݎڎ�-�Ď� ���ގ֎��Ύ� ��-�̎ގ�                                          */
/*********************************************************************/
struct mlnuddt {
	long rectn1;                        /* �ڎ�-�Ď� ���ʎގ�1              */
	long rectn2;                        /* �ڎ�-�Ď� ���ʎގ�2              */
	long updpos;                        /* ����                        */
	long updlen;                        /* �Ŏ��ގ�                      */
};
typedef	struct mlnuddt	MLNUDDT;
/*********************************************************************/
/*   �̎����� �ƎՎ��؎֎����ގ֎����� ��-�̎ގ�                                         */
/*********************************************************************/
struct mlnrkey {
	long recn1;                         /* �ڎ�-�Ď� �ʎގݎ��ގ�1             */
	long recn2;                         /* �ڎ�-�Ď� �ʎގݎ��ގ�2             */
	long fipos;                         /* ����                        */
	long filen;                         /* �Ŏ��ގ�                      */
	short fikeyn;                       /* ��- ����                     */
	short fidmy;
	long	reckln[MLNMXKY];
	MFCOND  reckey[MLNMXKY];
};
typedef	struct mlnrkey	MLNRKEY;
/*********************************************************************/
/*   �ώ������ގ֎����� ��-�̎ގ�                                                 */
/*********************************************************************/
struct mlnmkdt {
	long recpos;                        /* ����                        */
	long recopr;                        /* ���ݎ��ގݎ�                    */
	char *recky;                        /* ��- ��                      */
	long keylen;                        /* ��- �� ���֎�                  */
};
struct mlnmsln {
	long mskitm;                        /* �������ގ֎� �� �ώ������ގ֎����ݎ���      */
	struct mlnmkdt maskdt[MLNMITN];
};
struct mlnmask {
	long msklnn;                        /* �ώ��� ���ގ֎�����                */
	struct mlnmsln msklin[MLNMLNN];
};
typedef	struct mlnmask	MLNMASK;
/*********************************************************************/
/*   ����-�Ҏ�-���ގʎߎ׎�-�� ��-�̎ގ�                                           */
/*********************************************************************/
struct mlnempr {
	union	{                           /* �ʎߎ׎�-�� �� �Ύߎ��ݎ�            */
		short	*cngpms;
		long	*cngpml;
		char	*cngpmc;
	} cngprm;
	long cnglen;                        /* �ʎߎ׎�-�� �� �Ŏ��ގ�             */
};
struct mlnempt {
	long cngn;                          /* �ʎߎ׎�-�� �� ������              */
	struct mlnempr parmdt[MLNMEP];
};
typedef	struct mlnempt	MLNEMPT;
/*********************************************************************/
/*   ����-�Ҏ�-���� ��-�̎ގ�                                                 */
/*********************************************************************/
struct mlnermg {
	long errno;                         /* ����- �Ҏ�-����NO              */
	char errmg[MLNELN];                 /* ����- �Ҏ�-����                */
	long permn;                         /* �ʎߎ׎�-�� ����                 */
	struct mlcftbl pardat[MLNMEP];
};
typedef	struct mlnermg 	MLNERMG;
/*********************************************************************/
/*   NDTP�Ҏ��������� �ʎߎ׎Ҏ��� �Î��̎ގ�                                         */
/*********************************************************************/
struct mlnmgpr {
	union	{                           /* �ʎߎ׎�-�� �� �Ύߎ��ݎ�            */
		short	*msgpms;
		long	*msgpml;
		char	*msgpmc;
	} msgprm;
	long msglen;                        /* �ʎߎ׎�-�� �� �Ŏ��ގ�             */
};
struct mlnmgpt {
	long msgn;                          /* �ʎߎ׎�-�� �� ������              */
	struct mlnmgpr prmdtb[MLNMMP];
};
typedef	struct mlnmgpt	MLNMGPT;
/*********************************************************************/
/*   NDTP all�Ҏ��������ގÎ��̎ގ�                                             */
/*********************************************************************/
struct mlnalmg {
	long msgno;                         /* NDTP�Ҏ�-����NO              */
	char allmsg[MLNMLN];                /* NDTP�Ҏ�-����                */
	long prmn;                          /* �ʎߎ׎�-�� ����                 */
	struct mlcftbl prmdat[MLNMMP];
};
typedef	struct mlnalmg 	MLNALMG;
