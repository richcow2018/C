/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 Ì§²ÙÒ²														 */
/*		ÎÞØ­°Ñ ºËß° Ã²·Þ Ì§²Ù (mrl.h)								 */
/*																	 */
/*	2 ¸ÌÞÝ															 */
/*		ÎÞØ­°Ñ ºËß° ¼®Ø												 */
/*																	 */
/*	3 ØÚ·															 */
/*		¾¯¹² ¼¬ : À¹³Á ¼Ý²Á											 */
/*		»¸¾² ¼¬ : À¹³Á ¼Ý²Á											 */
/*		ÍÝº³¼Ô : ½½Þ· µ»Ñ			    '89/03/01 (L01)				 */
/*				(²¼Þ®³ ¼­³Ø®³¼Þ ±ÎÞ°Ä ·É³ É Â²¶)		--- TC2419	 */
/*      ÊÑ¹¹¼Ô : ¿ù²¬¡¡¹îÌé              94/02/03                    */
/*      ÊÑ¹¹¼Ô : ¿ù²¬¡¡¹îÌé              95/02/22                    */
/*				(ÎÞØÕ-ÑÊÄºÉÄÌÃÎºï½ü¤ËÈ¼¤¦ÊÑ¹¹)	TD-47(CT0880)ST1751	 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	¼­³Ø®³ º°ÄÞ 													 */
/*********************************************************************/
#define MRLNORMAL	0L		/*	¾²¼Þ®³ ¼­³Ø®³						 */
#define MRLNORCV	-1L		/*	Ø¶ÊÞØ ÌÖ³ ¼½ÃÑ						 */
#define MRLIVPARM	-2L		/*	·ÄÞ³ Êß×ÒÀ ´×°						 */
#define MRLTYPERR	-3L		/*	²½ÞÚ¶É ÎÞØ­°Ñ É ¿³Á¼­ÍÞÂ ¶Þ ÌÃ·		 */
#define MRLVOLERR	-4L		/*	ÎÞØ­°Ñ ¼®³¶Þ²Á­³					 */
#define MRLSIZERR	-5L		/*	ÛÝØ¾¸ÀÁ®³ ÏÀÊ ÎÞØ­°Ñ»²½Þ ¶Þ Á¶Þ³	 */
#define MRLMNTERR	-6L		/*	ºËß°»· ÎÞØ­°Ñ ¶Þ Ï³ÝÄ Á­³			 */
#define MRLTBLERR	-7L		/*	Ã°ÌÞÙ ´×°							 */
							/*  ÎÞØÕ-ÑÊÄºÉÄÌÃÎºï½ü¤ËÈ¼¤¦ºï½ü(1¹Ô)	 */
							/*  						TD47(CT0880) */
#define MRLCPSTOP	-9L		/*	ÌßÛ¾½ ·®³¾² ¼­³Ø®³					 */
#define MRLMIOERR	-10L	/*	ºËß°ÓÄ I/O ´×°						 */
#define MRLSIOERR	-11L	/*	ºËß°»· I/O ´×°						 */
#define MRLOTHERR	-12L	/*	ÎÞØ­°Ñ±¸¾½¼Þ É ´×°(I/O´×° ²¶Þ²)		 */
#define MRLOSERR	-13L	/*	ROS ¼½ÃÑ º°Ù ´×°					 */
#define MRLNOMEM	-14L	/*	ÒÓØ ÌÞ¿¸							 */
#define	MRLSCSIHNG	-15L	/*	SCSIÊÝ¸Þ(ØÄ×²²ó¿ôÆâ)			TD61 */
#define	MRLRTRYOVER	-16L	/*	SCSIÊÝ¸Þ(ØÄ×²µ°ÊÞ°)				TD61 */

/*********************************************************************/
/*	ÍÝ·¬¸Á															 */
/*********************************************************************/
#define MRLMSGNOM	-20L	/*	À ÌßÛ¾½ ¶×É ¼Þ­¼Ý					 */
#define MRLGETCPY1	-21L	/*	ºËß° ¼®Ø 1 É ¹¯¶ ¦ ¼Þ­¼Ý			 */
#define MRLGETCPY2	-22L	/*	ºËß° ¼®Ø 2 É ¹¯¶ ¦ ¼Þ­¼Ý			 */
#define MRLIOERR	-23L	/*	I/O ´×°								 */

/*********************************************************************/
/*	MRLCB (·®³Â³ ¼Þ®³Î³ ¾¯Ã² Ø®³²·)									 */
/*********************************************************************/
struct mrlcb{
	 char		mrlcblid[4];	/* ÌÞÛ¯¸ ¼·ÍÞÂ¼						 */
	 char		*mrlcfnm1;		/* ºËß°ÓÄ Ì§²ÙÒ² ±ÄÞÚ½				 */
	 char		*mrlcfnm2;		/* ºËß°»· Ì§²ÙÒ² ±ÄÞÚ½				 */
	 short		mrlcmote;		/* ºËß°ÓÄ ´ÝÄØ ÊÞÝºÞ³				 */
	 short		mrlcsake;		/* ºËß°»· ´ÝÄØ ÊÞÝºÞ³				 */
	 char		mrlctyp1;		/* ºËß°ÓÄ ¿³Á ¼­ÍÞÂ					 */ 
	 char		mrlctyp2;		/* ºËß°»· ¿³Á ¼­ÍÞÂ					 */
	 short		mrlcmdid;		/* Ó¼Þ­°ÙID						TD?? */
	 long		mrlcsize;		/* ÎÞØ­°Ñ »²½Þ						 */
	 long		mrlcsect;		/* ÛÝØ ¾¸À Á®³						 */
	 short		mrlcmino;		/* ¿³Á ¼·ÍÞÂ¼						 */
	 short		mrlcyob1;		/* ÖËÞ1								 */
	 long		mrlcrqt1;		/* Ø¸´½Ä ¼·ÍÞÂ¼ 1					 */
	 long		mrlcrqt2;		/* Ø¸´½Ä ¼·ÍÞÂ¼ 2					 */
	 long		mrlcrqt3;		/* Ø¸´½Ä ¼·ÍÞÂ¼ 3					 */
	 char		*mrlcmgbf;		/* ÃÞÝÌÞÝ ¼Þ­¼Ý ÊÞ¯Ì§ ±ÄÞÚ½			 */
	 char		*mrlcpbf1;		/* ºËß° ÊÞ¯Ì§1 ±ÄÞÚ½				 */
	 char		*mrlcpbf2;		/* ºËß° ÊÞ¯Ì§2 ±ÄÞÚ½				 */
	 long		mrlccprs;		/* ºËß° ¼®Ø Ø»ÞÙÄ					 */
	 long		mrlcioer;		/* I/O ´×° º°ÄÞ						 */
	 long		mrlcdtal;		/* ¾ÜºÙ¾ðÊó						TD?? */
};
typedef struct mrlcb MRLCB;


/*********************************************************************/
/*	¼½ÃÑ º°Ù ´×° º°ÄÞ ¶¸É³ ²·										 */
/*********************************************************************/
extern	long	mrlroserr;									/* (L01) */
#define	MRLSETCOD(p1)	mrlroserr = p1						/* (L01) */
