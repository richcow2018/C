
/**********************************************************************/
/*																	  */
/*		  TLPI Ã°ĖŪŲ ĖĢ°Ī¯Ä		tlpi.h		(94.09.16)				  */
/*									  ÍŨēŗ	(  .  .	 )				  */
/*									  ĘŅšš	   .  .					  */
/*									  ĘŅššŧÔ ĩ×ĘŨÅÄ					  */
/*																	  */
/**********************************************************************/

struct mdlpisb {
		short	tlpiinen;				/* ÍŊČ÷					   JJ */
		char	tlpiyob0[6];			/* ÖËŪ0						  */
};
typedef	struct mdlpisb MDLPISB;			/* DCP Öŗ					  */
typedef	struct mdlpisb TLPISUB;			/* FIP Öŗ					  */

struct	mdlpiko	{
		char	tlpikhyo	  ;			/* ēÍŪÂĖŪ ËŽŗŧŪ				  */
		char	tlpiyob1	  ;			/* ÖËŪ1						  */
		char	tlpilusb	  ;			/* LU ŧ­ÍŪÂ					  */
		char	tlpittyp	  ;			/* ĀŨĪÂ	Ā˛Ėß				  */
		short	tlpifahn	  ;			/* TFAH	´ŨÄØ NO.			  */
		short	tlpilgtn	  ;			/* TLGT	´ŨÄØ NO.			  */
		short	tlpipuno	  ;			/* PU NO.					  */
		short	tlpiluno	  ;			/* LU NO.					  */
		char	tlpihpas	  ;			/* ĘßŊ ŊÃ°ĀŊ				  */
		char	tlpihopn	  ;			/* ĩ°ĖßŨ ŊÃ°ĀŊ				  */
		char	tlpihred	  ;			/* Ø°ÄŪ	ŊÃ°ĀŊ				  */
		char	tlpihwrt	  ;			/* ×˛Ä ŊÃ°ĀŊ				  */
		char	tlpihscn	  ;			/* ŋŗŧŨ	Á­ŗŧ ŊÃ°ĀŊ			  */
		char	tlpihrcn	  ;			/* ŧŪ­ŧŨ Á­ŗŧ ŊÃ°ĀŊ			  */
		char	tlpihres	  ;			/* ĩŗÄŗ	ŋŗŧŨ ŊÃ°ĀŊ			  */
		char	tlpihsht	  ;			/* SHUT	- DOWN ŊÃ°ĀŊ		 **/
		char	tlpihtex	  ;			/* ÂŗÁ ÃŪŨĖŪŨ ŊÃ°ĀŊ			  */
		char	tlpihhdk	  ;			/* ËÄŪŗˇ ÂŗÁ ŊÃ°ĀŊ			 **/
		short	tlpiwrtc	  ;			/* ×˛Ä ļŗŨĀ					  */
		char	tlpiblct	  ;			/* ĖŪ×šÂÄ ŧÖŗ ËÖŗŧŪ			 **/
		char	tlpiyob2	  ;			/* ÖËŪ2						 **/
		short	tlpitben	  ;			/* TLPI	ļ¸ÁÖŗĖŪ	´ŨÄØ° ĘŪŨēŪŗ **/
		short	tlpipatn	  ;			/* TPAT	´ŨÄØ° ĘŪŨēŪŗ	   CC */
		short	tlpiyob3	  ;			/* ÖËŪ3					   CC */
		char	tlpipsnm[8]	  ;			/* ÛŨØ ĘßŊ ŧˇÍŪÂŌ˛		   CC */
		long	tlpiyob4[2]	  ;			/* ÖËŪ4					   CC */
};
typedef	struct	mdlpiko	MDLPIKO;		/* DCP Öŗ					  */
typedef	struct	mdlpiko	TLPIPSZ;		/* FIP Öŗ					  */
