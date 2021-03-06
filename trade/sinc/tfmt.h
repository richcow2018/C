								/* Æ°Åª¥Æ¡¼¥Ö¥ëºï½ü¤Î°Ùºï½ü(7¹Ô) TD60*/
/*********************************************************************/
/*	TFMT ºÍÞÂ ÌÞ É º³¿Þ³À²											 */
/*********************************************************************/
struct	tfmtpsz	{
								/* Æ°Åª¥Æ¡¼¥Ö¥ëºï½ü¤Î°Ùºï½ü(2¹Ô) TD60*/
	unsigned char	tfmtattr;	/* Ì±²Ù ¿Þ¸¾²						 */
								/*   1... ....  Ø¶ÊÞØ Ö³.ÌÖ³ ¼Þ®³Î³  */
								/*			'1'  Ø¶ÊÞØ À²¼®³		 */
								/*						TFMTRCV		 */
								/*			'0'  Ø¶ÊÞØ À²¼®³ ÃÞÅ²    */
								/*   .1.. ....  ¼Þ¬°ÅÙ ¼­Ä¸ ÀÝ²		 */
								/*			'1'  ¼Þ¬°ÅÙ¼­Ä¸ º³Ó¸ÀÝ²  */
								/*						TFMTJNL		 */
								/*			'0'  ¼Þ¬°ÅÙ¼­Ä¸ Úº°ÄÞÀÝ² */
								/*   ..1. ....  Ì§²Ù ¼Þ®³Î³			 */
								/*			'1'  2¼Þ­³¶ Ì§²Ù		 */
								/*						TFMTDUPF	 */
								/*			'0'  Ë 2¼Þ­³¶ Ì§²Ù		 */
								/*   ...1 ....  FIP¶ÝØÀ²¼®³Ì§²Ù¼Þ®³Î³*/
								/*			'1'  FIP¶ÝØÀ²¼®³¶Þ²Ì§²Ù  */
								/*						TFMTNFIP	 */
								/*			'0'  FIP¶ÝØÀ²¼®³Ì§²Ù	 */
								/*   .... 1...  ÖËÞ					 */
								/*   .... .111  Ì§²Ù À²Ìß			 */
								/*						TFMTFTYPE	 */
								/*			'000'  ½ÄØ°Ñ ±¸¾½    (E) */
								/*						TFMTETYPE	 */
								/*			'001'  ¼Þ­Ý Úº°ÄÞ    (A) */
								/*						TFMTATYPE	 */
								/*			'010'  Á®¸¾Â Úº°ÄÞ   (B) */
								/*						TFMTBTYPE 	 */
								/*			'011'  ×ÝÀÞÏ²½Þ Î³¼· (C) */
								/*						TFMTCTYPE	 */
								/*			'100'  ·°¹Ý»¸ Î³¼·   (D) */
								/*						TFMTDTYPE	 */
	unsigned char	tfmtstat;	/* Ì±²Ù ½Ã-À½						 */
								/*   1... ....  ÎÞØ­°Ñ ¼Þ®³Î³		 */
								/*			'1'  ¼®³¶Þ² Á­³			 */
								/*						TFMTVERR	 */
								/*			'0'  ¼®³¶Þ² Á­³ ÃÞÅ²	 */
								/*   .1.. ....  Ì§²Ù ¼Þ®³Î³			 */
								/*			'1'  ¿³¾² ½ÞÐ			 */
								/*						TFMTCRT		 */
								/*			'0'  Ð ¿³¾²				 */
								/*   ..1. ....  Ì§²Ù ¼Þ®³Î³			 */
								/*			'1'  Ì§²Ù Í²¿¸Á­³		 */
								/*						TFMTFERR	 */
								/*			'0'  Ì§²Ù Í²¿¸Á­³ ÃÞÅ²	 */
								/*	 .... 1...	Ì§²Ù ¶¸Á®³			 */
								/*			'1'	Ì§²Ù ¶¸Á®³ Á­³		 */
								/*						TFMTEXTN	 */
								/*			'0'	Ì§²Ù ¶¸Á®³ Á­³ ÃÞÅ²	 */
								/*   ...1 .111  ÖËÞ					 */
	short	tfmtoth1;			/* ÖËÞ								 */
	char	tfmtname[16];		/* ÛÝØ Ì±²Ù Ò²						 */
	short	tfmtvmtp;			/* ¶¸É³ ÎÞØÕ-Ñ VMT ´ÝÄØ NO			 */
	short	tfmtsgtp;			/* ¼Ö¿Þ¸ ¸ÞÙ-Ìß SGT ´ÝÄØ NO			 */
	short	tfmtfmtp;			/* ÄÞ³²Â ¸ÞÙ-Ìß ¼Þ FMT ´ÝÄØNO		 */
	short	tfmtdupp;			/* Æ¼ÞÕ³¶ Ì±²Ù ±²Ã FMT ´ÝÄØNO Ì¤»ÈÍÑ */
	long	tfmtinsp;			/* Ì±²Ù ¼Ö· Ö³ØÖ³					 */
	long	tfmtexsp;			/* Ì±²Ù ¶¸ÁÖ³ Ö³ØÖ³					 */
	short	tfmtexno;			/* Ì±²Ù ¶¸ÁÖ³ ¶²½³					 */
	short	tfmtnear;			/* Æ± ´ÝÄÞ Â³Á ÜØ±²					 */
	short	tfmtblks;			/* ÌÞÛÂ¸ ÁÖ³						 */
	short	tfmtrecs;			/* Úº-ÄÞ ÁÖ³						 */
	short	tfmtkmtp;			/* KMT ´ÝÄØ NO						 */
	short	tfmtkeyn;			/* ·- ½³							 */
	long	tfmteof;			/* EOF ¼ÞÖ³Î³						 */
	long	tfmtercd;			/* ´×- ¼ÞÖ³Î³						 */
	char	tfmtctim[8];		/* ÁÏÀ®»þ¹ï						TD30 */
};
typedef	struct	tfmtpsz	TFMTPSZ;

/*********************************************************************/
/*	Ã-ÌÞÙ Å² º-ÄÞ Ã²·Þ												 */
/*********************************************************************/
#define		TFMTRCV		0x80	/* FMTÌ§²Ù¿Þ¸¾² Ø¶ÊÞØÀ²¼®³Ì§²Ù       */
#define		TFMTJNL		0x40	/* FMTÌ§²Ù¿Þ¸¾² ¼Þ¬°ÅÙ¼­Ä¸ÀÝ²º³Ó¸    */
#define		TFMTDUPF	0x20	/* FMTÌ§²Ù¿Þ¸¾² 2¼Þ­³¶ Ì§²Ù          */
#define		TFMTNFIP	0x10	/* FMTÌ§²Ù¿Þ¸¾² FIP¶ÝØÀ²¼®³¶Þ²Ì§²Ù   */
#define		TFMTFTYPE	0x07	/* FMTÌ±²Ù¿Þ¸¾² Ì±²ÙÀ²Ìß             */
#define		TFMTETYPE	0x00	/* FMTÌ±²Ù¿Þ¸¾² ½ÄØ°Ñ ±¸¾½    (E)    */
#define		TFMTATYPE	0x01	/* FMTÌ±²Ù¿Þ¸¾² ¼Þ­Ý Úº°ÄÞ    (A)    */
#define		TFMTBTYPE	0x02	/* FMTÌ±²Ù¿Þ¸¾² Á®¸¾Â Úº°ÄÞ   (B)    */
#define		TFMTCTYPE	0x03	/* FMTÌ±²Ù¿Þ¸¾² ×ÝÀÞÏ²½Þ Î³¼· (C)    */
#define		TFMTDTYPE	0x04	/* FMTÌ±²Ù¿Þ¸¾² ·°¹Ý»¸ Î³¼·   (D)    */

#define		TFMTVERR	0x80	/* FMTÌ§²Ù½Ã°À½ ¼®³¶Þ²Á­³            */
#define		TFMTCRT		0x40	/* FMTÌ§²Ù½Ã°À½ ¿³¾²½ÞÐ              */
#define		TFMTFERR	0x20	/* FMTÌ§²Ù½Ã°À½ Í²¿¸Á­³              */
#define		TFMTEXTN	0x08	/* FMTÌ§²Ù½Ã°À½ Ì§²Ù ¶¸Á®³ Á­³		 */
