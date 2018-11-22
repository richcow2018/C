/*********************************************************************/
/*	TERT »ÌÞ ·®³Â³ÌÞ É º³¿Þ³À²										 */
/*********************************************************************/
/*-------------------------------------------------------------------*/
/* ¡ã¥½¡¼¥¹½¤Àµ¼ÔÌ¾¡ä				 ±Ä¶ÈÅ¹¥·¥¹¥Æ¥àÉô¡¡µÜÏÆ		  	 */
/* ¡ã¥½¡¼¥¹½¤ÀµÇ¯·îÆüµÚ¤Ó½¤Àµ£É£Ä¡ä  £±£¹£¹£¹Ç¯£°£³·î£³£±Æü SPCY0146 */
/*			     640MOÁõÃÖ¤Ø¤ÎÂÐ±þ									 */
/*-------------------------------------------------------------------*/
struct	tertsub	{
	long	tertacnt;					/* ÌßÛ¾½ ±ÎÞ°Ä ¶³ÝÀ			 */
};
typedef	struct	tertsub TERTSUB;
/*********************************************************************/
/*	TERT ºÍÞÂ ÌÞ É º³¿Þ³À²											 */
/*********************************************************************/
struct	tertpsz	{
	long	tertercd;					/* I/O ´×° º°ÄÞ				 */

	char	tertodk;					/* ACC´×° ¼­ÍÞÂ 		TD00 */
										/* .... ...1  ÊÞ²À² ´×°		 */
										/* .... ..1.  ¿³Á ´×°		 */
										/* .... .1..  ¼Ö³ Ì¶ ´×°	 */
										/* .... 1...  ¿ÉÀ ´×°		 */
										/* 1111 ....  Ø»Þ°ÌÞ		 */
	char	tertdk;						/* ¼Þ· ÃÞ¨½¸ ´×° ¼­ÍÞÂ 		 */
										/* tertodk Ä µÅ¼Þ 			 */
	char	tertfd;						/* ÌÛ¯Ëß° ÃÞ¨½¸ ´×° ¼­ÍÞÂ 	 */
										/* tertodk Ä µÅ¼Þ 			 */
	char	tertmt;						/* ¼Þ· Ã°Ìß ´×° ¼­ÍÞÂ 		 */
										/* tertodk Ä µÅ¼Þ 			 */
	char	tert3od;					/* 3.5OD´×°¼ïÊÌ			TDN1 */
	char	tert5od;					/* 5OD´×°¼ïÊÌ			TDN1 */
	char	tert5md;					/* 5MD´×°¼ïÊÌ			TDN1 */
	char	tert6mo;					/* 640MMO´×°¼ïÊÌ	SPCY0146 */
};
typedef	struct	tertpsz	TERTPSZ;

#define	TERTMDERR	0x01				/* ÊÞ²À² ´×°  (Media error)	 */
#define	TERTDRERR	0x02				/* ¿³Á ´×°	  (Drive error)	 */
#define	TERTNRERR	0x04				/* ¼Ö³ Ì¶ ´×° (Not ready  )	 */
#define	TERTOTERR	0x08				/* ¿ÉÀ ´×°	  (Other error)	 */
