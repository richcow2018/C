#include "mlcdef.h"
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
	struct mlnmgpr prmdtb[MLNMEP];
};
typedef	struct mlnmgpt	MLNMGPT;
