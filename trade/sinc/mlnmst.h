#include "mlcdef.h"
/*********************************************************************/
/*   ŽÆŽÕŽ³Ž¼ŽÕŽÂŽØŽÖŽ¸ Ž¼ŽÞŽÖŽ³ŽÎŽ³ ŽÃ-ŽÌŽÞŽÙ                                          */
/*********************************************************************/
struct mlnioif {
	long iofrm;                         /* ŽÆŽÕŽ³Ž¼ŽÕŽÂŽØŽÖŽ¸Ž¹Ž²Ž¼Ž·             */
	long indes;                         /* ŽÆŽÕŽ³ŽØŽÖŽ¸ŽÌŽ±Ž²ŽÙŽ·Ž¼ŽÞŽÕŽÂŽ¼          */
	long outdes;                        /* Ž¼ŽÕŽÂŽØŽÖŽ¸ŽÌŽ±Ž²ŽÙŽ·Ž¼ŽÞŽÕŽÂŽ¼          */
	long filpos;                        /* Ž¼ŽÕŽÂŽØŽÖŽ¸ŽÌŽ±Ž²ŽÙŽÖŽÐŽºŽÐŽ²ŽÁ          */
};
typedef	struct mlnioif	MLNIOIF;
MLNIOIF ioift;
/*********************************************************************/
/*   Ž´Ž×-ŽÒŽÂŽ¾-Ž¼ŽÞŽÊŽßŽ×ŽÒ-ŽÀ ŽÃ-ŽÌŽÞŽÙ                                           */
/*********************************************************************/
struct mlnempr {
	union	{                           /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ ŽÎŽßŽ²ŽÝŽÀ            */
		short	*cngpms;
		long	*cngpml;
		char	*cngpmc;
	} cngprm;
	long cnglen;                        /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ ŽÅŽ¶ŽÞŽ»             */
};
struct mlnempt {
	long cngn;                          /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ Ž¶Ž½ŽÞ              */
	struct mlnempr parmdt[MLNMEP];
};
typedef	struct mlnempt	MLNEMPT;
/*********************************************************************/
/*   NDTPŽÒŽ¯Ž¾Ž°Ž¼ŽÞ ŽÊŽßŽ×ŽÒŽ°ŽÀ ŽÃŽ°ŽÌŽÞŽÙ                                         */
/*********************************************************************/
struct mlnmgpr {
	union	{                           /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ ŽÎŽßŽ²ŽÝŽÀ            */
		short	*msgpms;
		long	*msgpml;
		char	*msgpmc;
	} msgprm;
	long msglen;                        /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ ŽÅŽ¶ŽÞŽ»             */
};
struct mlnmgpt {
	long msgn;                          /* ŽÊŽßŽ×ŽÒ-ŽÀ ŽÉ Ž¶Ž½ŽÞ              */
	struct mlnmgpr prmdtb[MLNMEP];
};
typedef	struct mlnmgpt	MLNMGPT;
