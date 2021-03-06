#define	MLNNML	0x00000000				/* ¾²¼ÞÖ³					 */
#define	MLNERR	0x00000010				/* ²¼ÞÖ³					 */
#define	MLNCMD	-1						/* ºÏÝÄÞ´×-					 */
#define	MLNEND	-12						/* END						 */
#define	MLNCAN	-13						/* CAN						 */
#define	MLNCKP	0x00000011				/* ·ÄÞ³ºÏÝÄÞ ·-Êß×´×-		 */
#define	MLNCCF	0x00000012				/* ·ÄÞ³ºÏÝÄÞ ºÏÝÄÞÌ±²Ù´×-	 */
#define	MLNCPF	0x00000013				/* ·ÄÞ³ºÏÝÄÞ ÌßÛÝÌßÄÌ±²Ù´×-  */
#define	MLNCKE	0x00000014				/* ·ÄÞ³ºÏÝÄÞ ¹²¼·´×-		 */
#define	MLNCOE	0x00000015				/* ºÏÝÄÞÌ±²Ù µ-ÌßÝ´×-		 */
#define	MLNPOE	0x00000016				/* ÌßÛÝÌßÄÌ±²Ù µ-ÌßÝ´×-		 */
#define	MLNTBE	-2						/* Ã-ÌÞÙ´×-					 */
#define	MLNNCE	-3						/* ¸Û-½ÞÅ¼ ´×-				 */
#define	MLNFLE	-4						/* Ì±²Ù ´×-					 */
#define	MLNBFE	-5						/* ÊÞÂÌ±ÌÞ¿¸				 */
#define	MLNNOVL -6						/* ¶Þ²Ä³ ÎÞØ­³Ñ Å¼			 */
#define	MLNNSV	-7						/* NSV ºÏÝÄÞ Æ­³Ø®¸	TC1239	 */
#define	MLNCMP	-10						/* Ï½¸¾²ØÂ					 */
#define	MLNNCM	-11						/* Ï½¸Ì¾²ØÂ					 */
#define	MLNRDL	80L						/* ÖÐºÐÃÞ-ÀÁÖ³				 */
#define	MLNMXBF 100						/* MAX ÊÞ¯Ì§½³				 */
#define	MLNMXKY 16						/* MAX·-½³					 */
#define	MLNMITN 8						/* MAXÏ½¸¼ÞÖ³¹Ý½³			 */
#define	MLNMLNN 8						/* MAXÏ½¸·ÞÖ³½³				 */
#define	MLNMAPR 256						/* MAXÂ²¶¾ÂÃ²Á½³			 */
#define	MLNMEP	3						/* MAX´×-ÒÂ¾-¼ÞÊß×Ò-À½³		 */
#define	MLNMMP	50						/* MAXÒÂ¾-¼ÞÊß×Ò-À½³		 */
#define	MLNELN	80						/* MAX´×-ÒÂ¾-¼ÞÓ¼Þ½³		 */
#define	MLNMLN	512						/* MAXÒÂ¾-¼ÞÓ¼Þ½³	TC1239	 */
#define	MLNKLN	512						/* MAX·-ÁÖ³			TC1239	 */
#define	MLNFLN	128						/* MAXÌ§²ÙÒ²Á®³		TC1239	 */
#define MLNCLN	512						/* ºÏÝÄÞÓ¼ÞÚÂÅ¶Þ»			 */
#define MLNCDL	4096					/* ºÏÝÄÞÓ¼ÞÚÂÅ¶Þ»	TC1239	 */
#define MLNUCH	unsigned char
#define MLNKETA 512
										/*S 88-07-07	TC1239		 */
/*********************************************************************/
/*	¼­ÂØ®¸ ¹²¼· É define											 */
/*********************************************************************/
#define	MLNWW	0						/* Æ­³¼­ÂØ®¸ ¶Þ WTO/WTOR	 */
#define	MLNFF	1						/* Æ­³¼­ÂØ®¸ ¶Þ FILE/FILE	 */
#define	MLNFW	2						/* Æ­³¼­ÂØ®¸ ¶Þ FILE/WTO	 */

#define	MLNLP	0						/* LP Î³¼·					 */
#define	MLNBS	1						/* ÊÞ²Ä½ÄØ°Ñ Î³¼·			 */

#define	MLNMTBL	0						/* ÒÓØ  Ã°ÌÞÙ				 */
#define	MLNFTBL	1						/* Ì§²Ù Ã°ÌÞÙ				 */

#define	MLN_K	0						/* ºÍÞÂÌÞ ¼Ã² (-K)			 */
#define	MLN_A	1						/* Ã°ÌÞÙ ¾ÞÝÀ² ¼Ã² (-A)		 */
#define	MLN_S	1						/* ½Ã°À½ Êß¯Á  ¼Ã² (-S)		 */
										/*E 88-07-07	TC1239		 */
																  /*%*/
										/*S 88-07-07	TC1239		 */
/*********************************************************************/
/*	´×° Ò¯¾°¼ÞÖ³ ¶Ý½³Ò² ²ÝÃÞ¯¸½										 */
/*********************************************************************/
#define		MLMFFCON	0
#define		MLMFFGET	1
#define		MLMFFOPN	2
#define		MLMFFRED	3
#define		MLMFFSRH	4
#define		MLMFFUPD	5
#define		MLMFFWRT	6
#define		MLMFFWTX	7
#define		MLMFRENQ	8
#define		MLMFTOPN	9
#define		MLMFWOPN	10
#define		MLMLCDWT	11
#define		MLMLCPCT	12
#define		MLMLCPOP	13
#define		MLMLCPRT	14
#define		MLMLCPWT	15
#define		MLMLNGBF	16
#define		MLMOGTBF	17
										/*E 88-07-07	TC1239		 */
