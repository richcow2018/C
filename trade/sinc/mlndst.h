#include "mf.h"
#include "mlcdef.h"
#include "mlcstr.h"
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
/*   Ã-ÌÞÙ±¸¾½ ¼ÞÖ³Î³ Ã-ÌÞÙ                                          */
/*********************************************************************/
struct mlntlif{
	long tblfrm;                        /* Ã-ÌÞÙ ¹²¼·                */
	long tlfdes;                        /* Ã-ÌÞÙÌ±²Ù ·¼ÞÕÂ¼          */
	long tdofrm;                        /* ¼ÕÂØÖ¸ ¹²¼·               */
	long tdofds;                        /* ÀÞÝÌß¹¯¶¼ÕÂØÖ¸Ì±²Ù ·¼ÞÕÂ¼ */
	char *tbldsc;                       /* Ã-ÌÞÙ¼·ÍÞÂ¼ Îß²ÝÀ         */
	long ykentn;                        /* Õ³º³ ´ÝÄØ½³               */
	long kbtlen;                        /* 1ºÍÞÂÌÞ É µµ·»            */
	long sublen;                        /* »ÌÞ·Ö³Â³ÌÞ É µµ·»         */
	long intbno;                        /* Ã-ÌÞÙ É ¼¹ÞÝÊÞÝºÞ³        */
	long tdtcb;                         /* Ã-ÌÞÙ ¶ÝØ ÌÞÛÂ¸ ±ÄÞÚ½     */
};
typedef	struct mlntlif	MLNTLIF;
/*********************************************************************/
/*  º³¼ÝÊÞÂÌ± Ã-ÌÞÙ                                                  */
/*********************************************************************/
struct mlnbfif{
	char *bufadr;                       /* º³¼ÝÊÞÂÌ± ±ÄÞÚ½           */
	char *bfitmt;                       /* ÊÞÂÌ± ÆÕ³ØÖ¸¼ÞÖ³¹Ý Ã-ÌÞÙ  */
};
struct mlnbuft
{
	long bufn;                          /* º³¼ÝÊÞÂÌ±½³               */
	struct mlnbfif bufitm[MLNMXBF];
};
typedef	struct mlnbuft	MLNBUFT;
/*********************************************************************/
/*   Ã-ÌÞÙÊÞÂÌ± ÆÕ³ØÖ¸¼ÞÖ³¹Ý Ã-ÌÞÙ                                   */
/*********************************************************************/
struct mlntbit{
	long kbtno;                         /* º³¼ÝºÍÞÂÅÝÊÞ-             */
};
typedef	struct mlntbit	MLNTBIT;
/*********************************************************************/
/*   Ì±²ÙÊÞÂÌ± ÆÕ³ØÖ¸¼ÞÖ³¹Ý Ã-ÌÞÙ                                    */
/*********************************************************************/
struct mlnfbit {
	long recno;                         /* º³¼ÝÚº-ÄÞ ÊÞÝºÞ³          */
	long bfpos;                         /* ²Á                        */
	long bflen;                         /* Å¶Þ»                      */
	short bfkeyn;                       /* º³¼ÝÚº-ÄÞ ÆÕ³ØÖ¸¼ÞÖ³¹Ý ½³ */
	short bfdmy;
	MFCOND *itmkey[MLNMXKY];
};
typedef	struct mlnfbit	MLNFBIT;
/*********************************************************************/
/*  Ì±²Ù±¸¾½ ¼ÞÖ³Î³ Ã-ÌÞÙ                                            */
/*********************************************************************/
struct mlnflif {
	long fdofrm;                        /* ¼ÕÂØÖ¸ ¹²¼·               */
	long fdofds;                        /* ÀÞÝÌßÂ¶ ¼ÕÂØÖ¸Ì±²Ù ·¼ÞÕÂ¼*/
	long inflno;                        /* ÆÕ³ØÖ¸Ì±²Ù ¼¹ÞÝÊÞÝºÞ³     */
	long filadr;                        /* Ì±²Ù¶ÝØ ÌÞÛÂ¸±ÄÞÚ½        */
	char *flfnam;                       /* ÌÙÊß½Ì±²ÙÒ²               */
	char *filnam;                       /* Ì±²ÙÒ² Îß²ÝÀ              */
	char filtyp;                        /* Ì±²Ù À²Ìß                 */
	char fildmy[3];                     /* ÀÞÐ-                      */
	long filrdl;                        /* Úº-ÄÞ ÁÖ³                 */
	long filkyn;                        /* ·- ½³                     */
	long filbkl;                        /* ÌÞÛÂ¸ ÁÖ³                 */
	long kmtno;                         /* KMT ´ÝÄØ-ÅÝÊÞ-            */
	char *dmbfad;                       /* ÀÞÐ-ÊÞÂÌ± ±ÄÞÚ½           */
};
typedef	struct mlnflif	MLNFLIF;
/*********************************************************************/
/*   Â²¶Úº-ÄÞ ¾ÂÃ²Á Ã-ÌÞÙ                                            */
/*********************************************************************/
struct mlnespr {
	long addpos;                        /* ²Á                        */
	char *addpri;                       /* ±À²                       */
	long addlen;                        /* Å¶Þ»                      */
};
struct mlnadpr {
	char clear;                         /* ¸Ø±Á                      */
	char dum[3];                        /* ÀÞÐ-                      */
	long eprin;                         /* ¾ÂÃ²Á½³                   */
	struct mlnespr estpri[MLNMAPR];
};
typedef	struct mlnadpr	MLNADPR;
/*********************************************************************/
/*   º³¼ÝÚº-ÄÞ ¼ÞÖ³Î³ Ã-ÌÞÙ                                          */
/*********************************************************************/
struct mlnuddt {
	long rectn1;                        /* Úº-ÄÞ Â³ÊÞÝ1              */
	long rectn2;                        /* Úº-ÄÞ Â³ÊÞÝ2              */
	long updpos;                        /* ²Á                        */
	long updlen;                        /* Å¶Þ»                      */
};
typedef	struct mlnuddt	MLNUDDT;
/*********************************************************************/
/*   Ì±²Ù ÆÕ³ØÖ¸¼ÞÖ³¹Ý Ã-ÌÞÙ                                         */
/*********************************************************************/
struct mlnrkey {
	long recn1;                         /* Úº-ÄÞ ÊÞÝºÞ³1             */
	long recn2;                         /* Úº-ÄÞ ÊÞÝºÞ³2             */
	long fipos;                         /* ²Á                        */
	long filen;                         /* Å¶Þ»                      */
	short fikeyn;                       /* ·- ½³                     */
	short fidmy;
	long	reckln[MLNMXKY];
	MFCOND  reckey[MLNMXKY];
};
typedef	struct mlnrkey	MLNRKEY;
/*********************************************************************/
/*   Ï½¸¼ÞÖ³¹Ý Ã-ÌÞÙ                                                 */
/*********************************************************************/
struct mlnmkdt {
	long recpos;                        /* ²Á                        */
	long recopr;                        /* ´Ý»ÞÝ¼                    */
	char *recky;                        /* ·- Á                      */
	long keylen;                        /* ·- Á ÁÖ³                  */
};
struct mlnmsln {
	long mskitm;                        /* ²Á·ÞÖ³ É Ï½¸¼ÞÖ³¹Ý½³      */
	struct mlnmkdt maskdt[MLNMITN];
};
struct mlnmask {
	long msklnn;                        /* Ï½¸ ·ÞÖ³½³                */
	struct mlnmsln msklin[MLNMLNN];
};
typedef	struct mlnmask	MLNMASK;
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
/*   ´×-ÒÂ¾-¼Þ Ã-ÌÞÙ                                                 */
/*********************************************************************/
struct mlnermg {
	long errno;                         /* ´×- ÒÂ¾-¼ÞNO              */
	char errmg[MLNELN];                 /* ´×- ÒÂ¾-¼Þ                */
	long permn;                         /* Êß×Ò-À ½³                 */
	struct mlcftbl pardat[MLNMEP];
};
typedef	struct mlnermg 	MLNERMG;
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
	struct mlnmgpr prmdtb[MLNMMP];
};
typedef	struct mlnmgpt	MLNMGPT;
/*********************************************************************/
/*   NDTP allÒ¯¾°¼ÞÃ°ÌÞÙ                                             */
/*********************************************************************/
struct mlnalmg {
	long msgno;                         /* NDTPÒÂ¾-¼ÞNO              */
	char allmsg[MLNMLN];                /* NDTPÒÂ¾-¼Þ                */
	long prmn;                          /* Êß×Ò-À ½³                 */
	struct mlcftbl prmdat[MLNMMP];
};
typedef	struct mlnalmg 	MLNALMG;
