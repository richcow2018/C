#include "mlcdef.h"
/*********************************************************************/
/*   ÆÕ³¼ÕÂØÖ¸ ¼ÞÖ³Î³ Ã-ÌÞÙ                                          */
/*********************************************************************/
struct mlnioif {
	long iofrm;                         /* ÆÕ³¼ÕÂØÖ¸¹²¼·             */
	long indes;                         /* ÆÕ³ØÖ¸Ì±²Ù·¼ÞÕÂ¼          */
	long outdes;                        /* ¼ÕÂØÖ¸Ì±²Ù·¼ÞÕÂ¼          */
	long filpos;                        /* ¼ÕÂØÖ¸Ì±²ÙÖÐºÐ²Á          */
};
typedef	struct mlnioif	MLNIOIF;
MLNIOIF ioift;
/*********************************************************************/
/*   ´×-ÒÂ¾-¼ÞÊß×Ò-À Ã-ÌÞÙ                                           */
/*********************************************************************/
struct mlnempr {
	union	{                           /* Êß×Ò-À É Îß²ÝÀ            */
		short	*cngpms;
		long	*cngpml;
		char	*cngpmc;
	} cngprm;
	long cnglen;                        /* Êß×Ò-À É Å¶Þ»             */
};
struct mlnempt {
	long cngn;                          /* Êß×Ò-À É ¶½Þ              */
	struct mlnempr parmdt[MLNMEP];
};
typedef	struct mlnempt	MLNEMPT;
/*********************************************************************/
/*   NDTPÒ¯¾°¼Þ Êß×Ò°À Ã°ÌÞÙ                                         */
/*********************************************************************/
struct mlnmgpr {
	union	{                           /* Êß×Ò-À É Îß²ÝÀ            */
		short	*msgpms;
		long	*msgpml;
		char	*msgpmc;
	} msgprm;
	long msglen;                        /* Êß×Ò-À É Å¶Þ»             */
};
struct mlnmgpt {
	long msgn;                          /* Êß×Ò-À É ¶½Þ              */
	struct mlnmgpr prmdtb[MLNMEP];
};
typedef	struct mlnmgpt	MLNMGPT;
