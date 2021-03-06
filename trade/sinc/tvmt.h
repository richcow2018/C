								/* Æ°Åª¥Æ¡¼¥Ö¥ëºï½ü¤Î°Ùºï½ü(7¹Ô) TD60*/
								/* mf_vmnt2¤Ø¤ÎÂÐ±þ				 SM01*/
/*********************************************************************/
/*  TVMT ºÍÞÂ ÌÞ É º³¿Þ³À²											 */
/*********************************************************************/
struct  tvmtpsz {
								/* Æ°Åª¥Æ¡¼¥Ö¥ëºï½ü¤Î°Ùºï½ü(2¹Ô) TD60*/
	char	tvmttype;					/* ¿³Á ¼ÕÍÞÂ				 */
										/*   'D' : ºÃ² ÃÞ¨½¸		 */
										/*   'O' : Ë¶Ø ÃÞ¨½¸		 */
										/*   'F' : ÌÛ¯Ëß° ÃÞ¨½¸		 */
										/*   'M' : ¼Þ· Ã°Ìß			 */
	unsigned char	tvmtrvat;			/* Ø¶ÊÞØ ¿Þ¸¾² 				 */
										/*   1... .... ÊÞ¯¸ ±¯Ìß ¼Þ	 */
										/*			'1' ÊÞ¯¸±¯Ìß½Ù	 */
										/*			'0' ÊÞ¯¸±¯Ìß¼Å²	 */
										/*   .1.. .... Ø×Ý ¼Þ É ¼®Á	 */
										/*			'1' Ø½Ä± ½Ù		 */
										/*			'0' Ø½Ä± ¼Å²	 */
	unsigned char	tvmtattr;			/* ÎÞØÕ-Ñ ¿Þ¸¾²				 */
										/*   1... .... ²Æ¼´°Ä¼Þ Ï³ÝÄ */
										/*			'1' Ï³ÝÄ½Ù		 */
										/*			'0' Ï³ÝÄ¼Å²		 */
										/*   .1.. .... ²Æ¼´°Ä¼Þ Ï³ÝÄ */
										/*				´×° É ¼®Ø	 */
										/*			'1' ´×°¼Þ ¼­³Ø®³ */
										/*			'0' ¼®Ø ¿Þ¯º³	 */
										/*   ..1. .... ÛÝØÎÞØ­°ÑÁª¯¸ */
										/*			'1' Áª¯¸ Ö³		 */
										/*			'0' Áª¯¸ ÌÖ³	 */
										/*   ...1 .... Ì§²Ù ¸ÌÞÝ	 */
										/*			'1' Ü°¸   Ì§²ÙÖ³ */
										/*			'0' ²¯ÊßÝ Ì§²ÙÖ³ */
										/*   .... 11.. Ï³ÝÄ Ó°ÄÞ	 */
										/*		   '01' ÖÐºÐ ÃÞ Ï³ÝÄ */
										/*		   '00' ¶·ºÐ ÃÞ Ï³ÝÄ */
										/*				ST1699		 */
										/*	 .... ..1. JNLÌ§²ÙÎÞØ­°Ñ */
										/*	 .... ...1 RBIÌ§²ÙÎÞØ­°Ñ */
	unsigned char	tvmtstat;			/* ÎÞØÕ-Ñ ½Ã-À½				 */
										/*   1... .... Ï³ÝÄ Ì×¸Þ 	 */
										/*			'1' Ï³ÝÄÁ­³		 */
										/*			'0' ÐÏ³ÝÄ		 */
										/*   .1.. .... ÎÞØ­°Ñ ¼®³¶Þ² */
										/*			'1' ¼®³¶Þ² Á­³	 */
										/*			'0' ¼®³¶Þ²¶Þ Å²	 */
										/*   .... ..11 Ï³ÝÄÓ°ÄÞ2 SM01*/
										/*		   '01' ÖÐºÐ ÃÞ Ï³ÝÄ */
										/*		   '00' ¶·ºÐ ÃÞ Ï³ÝÄ */
										/*   .... ..11 ÖËÞ			 */
	short	tvmtvmtp;					/* ÄÞ³²Â ÌÞÂØ VOL ¼Þ VMT E N */
	short	tvmtmrtp;					/* MRT ´ÝÄØÈÖ¹æ			TD22 */
	char	tvmtspnm[16];				/* ¿³Á Ä¸¼Õ Ì±²Ù Ò²			 */
	char	tvmtmntn[16];				/* Ï³ÝÄ ÃÞ²Ú¸ÄØ Ò²			 */
	char	tvmtvlid[8];				/* ÛÝØ ÎÞØÕ-Ñ ¼·ÍÞÂ Ò²		 */
	long	tvmtercd;					/* ´×- ¼ÞÖ³Î³				 */
	long	tvmtsect;					/* ÛÝØ ¾¸À ÁÖ³				 */
	char	tvmtcsnm[16];				/* Ì§²Ù±Ø ·¬×¸À Ä¸¼­ Ì§²ÙÒ²	 */
	short	tvmtpvtp;					/* À²¼®³ PVT ´ÝÄØ ÊÞÝºÞ³	 */
	short	tvmtvbtp;					/* À²¼®³ VBT ¾ÝÄ³ ´ÝÄØ ÊÞÝºÞ³*/
	short	tvmtoth2;					/* ÖËÞ						 */
	short	tvmtflcb;					/* FLCB º½³ 				 */
	short	tvmtrdsz;					/* Ù°Ä ÃÞ¨Ú¸ÄØ  »²½Þ		 */
	short	tvmtmino;					/* ¿³Á ¼·ÍÞÂ¼ (Ï²Å ÊÞÝºÞ³)	 */
	char	tvmtcnm2[16];				/* Ì§²ÙÅ¼ ·¬×¸À Ä¸¼­ Ì§²ÙÒ²  */
	long	tvmtsize;					/* ÎÞØ­°Ñ »²½Þ				 */
	unsigned char	tvmtheis;			/* ÊÄºÉ½Ã°À½			TD90 */
	char	tvmtcros;					/* ¸Û½º°ÙVOL¾ðÊó		TD90 */
	short	tvmtfmte;					/* ¸Î¾ãFMT´ÝÄØÈÖ¹æ		TD90 */
	char	tvmtrtim[8];				/* ¸Î¾ãÈ¯À¸ÆüÉÕ»þ¹ï		TD90 */
	char	tvmteday[4];				/* ¸Î¾ãÈ¯À¸±¿ÍÑÆüÉÕ		TD90 */
};
typedef	struct	tvmtpsz	TVMTPSZ;

/*********************************************************************/
/*  Ã°ÌÞÙ Å² º°ÄÞ Ã²·Þ												 */
/*********************************************************************/
#define		TVMTMNT		0x80			/* ÎÞØÕ°Ñ½Ã°À½ Ï³ÝÄÁ­³		 */
#define		TVMTMERR	0x00			/* ÎÞØÕ°Ñ½Ã°À½ ÐÏ³ÝÄ		 */
#define		TVMTVERR	0x40			/* ÎÞØ­°Ñ½Ã°À½ ¼®³¶Þ²Á­³	 */
#define		TVMTMMOD	0x0C			/* ÎÞØÕ°Ñ¿Þ¸¾² Ï³ÝÄÓ°ÄÞ		 */
#define		TVMTMT		'M'				/* ÎÞØÕ°Ñ¼ÕÍÞÂ ¼Þ·Ã°Ìß (MT)  */
#define		TVMTDISK	'D'				/* ÎÞØÕ°Ñ¼ÕÍÞÂ ºÃ² ÃÞ¨½¸	 */
#define		TVMTODISK	'O'				/* ÎÞØÕ°Ñ¼ÕÍÞÂ Ë¶Ø ÃÞ¨½¸	 */
#define		TVMTFDISK	'F'				/* ÎÞØÕ°Ñ¼ÕÍÞÂ ÌÛ¯Ëß° ÃÞ¨½¸	 */
#define		TVMTMINIT	0x80			/* ²Æ¼´°Ä¼Þ Ï³ÝÄ ½Ù			 */
#define		TVMTMTERM	0x40			/* Ï³ÝÄ ´×°¼Þ  ¼­³Ø®³		 */
#define		TVMTVCHK	0x20			/* ÛÝØÎÞØ­°ÑÁª¯¸ Ö³			 */
#define		TVMTWKVOL	0x10			/* Ü°¸ Ì§²Ù Ö³ ÎÞØ­°Ñ		 */
#define		TVMTWKFIL	0x1C			/* ÎÞØÕ°Ñ¿Þ¸¾² Ü°¸Ì§²Ù(Áª¯¸) */
#define		TVMTZI		0x10			/* ÎÞØÕ°Ñ¿Þ¸¾² Ü°¸Ì§²Ù(¼Þ)	 */
#define		TVMTTA		0x14			/* ÎÞØÕ°Ñ¿Þ¸¾² Ü°¸Ì§²Ù(À)	 */
#define		TVMTVNLEN    6L	    		/* ÎÞØ­-Ñ ¼·ÍÞÂÒ² É Å¶Þ»     */
#define		TVMTMNTNL	16L				/* VMTÏ³ÝÄÃÞ²Ú¸ÄØÒ² É µµ·»   */
#define		TVMTBKUP	0x80			/* Ø¶ÊÞØ¿Þ¸¾² ÊÞ¯¸±¯ÌßÀ²¼®³  */
#define		TVMTREST	0x40			/* Ø¶ÊÞØ¿Þ¸¾² Ø½Ä±			 */
#define		TVMTCROSS	'C'				/* ¥¯¥í¥¹¥³¡¼¥ëÍ­¤ê		TD90 */
#define		TVMTNOCROS	' '				/* ¥¯¥í¥¹¥³¡¼¥ëÌµ¤·		TD90 */
#define		TVMTHOWN	0x80			/* ¼«·ÏÊÄºÉ´°Î»			TD90 */
#define		TVMTHOTH	0x40			/* Â¾·ÏÊÄºÉ´°Î»			TD90 */
#define		TVMTVVJG	0x20			/* ÎÞØ­°Ñ½Ã°À½ VJ¼èÆÀºÑ	TD90 */
