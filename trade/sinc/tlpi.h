
/**********************************************************************/
/*																	  */
/*		  TLPI ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ		tlpi.h		(94.09.16)				  */
/*									  ﾍﾝｺｳ	(  .  .	 )				  */
/*									  変更	   .  .					  */
/*									  変更者 久保田					  */
/*																	  */
/**********************************************************************/

struct mdlpisb {
		short	tlpiinen;				/* 予備					   JJ */
		char	tlpiyob0[6];			/* ﾖﾋﾞ0						  */
};
typedef	struct mdlpisb MDLPISB;			/* DCP ﾖｳ					  */
typedef	struct mdlpisb TLPISUB;			/* FIP ﾖｳ					  */

struct	mdlpiko	{
		char	tlpikhyo	  ;			/* ｺﾍﾞﾂﾌﾞ ﾋｮｳｼﾞ				  */
		char	tlpiyob1	  ;			/* ﾖﾋﾞ1						  */
		char	tlpilusb	  ;			/* LU ｼｭﾍﾞﾂ					  */
		char	tlpittyp	  ;			/* ﾀﾝﾏﾂ	ﾀｲﾌﾟ				  */
		short	tlpifahn	  ;			/* TFAH	ｴﾝﾄﾘ NO.			  */
		short	tlpilgtn	  ;			/* TLGT	ｴﾝﾄﾘ NO.			  */
		short	tlpipuno	  ;			/* PU NO.					  */
		short	tlpiluno	  ;			/* LU NO.					  */
		char	tlpihpas	  ;			/* ﾊﾟｽ ｽﾃｰﾀｽ				  */
		char	tlpihopn	  ;			/* ｵｰﾌﾟﾝ ｽﾃｰﾀｽ				  */
		char	tlpihred	  ;			/* ﾘｰﾄﾞ	ｽﾃｰﾀｽ				  */
		char	tlpihwrt	  ;			/* ﾗｲﾄ ｽﾃｰﾀｽ				  */
		char	tlpihscn	  ;			/* ｿｳｼﾝ	ﾁｭｳｼ ｽﾃｰﾀｽ			  */
		char	tlpihrcn	  ;			/* ｼﾞｭｼﾝ ﾁｭｳｼ ｽﾃｰﾀｽ			  */
		char	tlpihres	  ;			/* ｵｳﾄｳ	ｿｳｼﾝ ｽﾃｰﾀｽ			  */
		char	tlpihsht	  ;			/* SHUT	- DOWN ｽﾃｰﾀｽ		 **/
		char	tlpihtex	  ;			/* ﾂｳﾁ ﾃﾞﾝﾌﾞﾝ ｽﾃｰﾀｽ			  */
		char	tlpihhdk	  ;			/* ﾋﾄﾞｳｷ ﾂｳﾁ ｽﾃｰﾀｽ			 **/
		short	tlpiwrtc	  ;			/* ﾗｲﾄ ｶｳﾝﾀ					  */
		char	tlpiblct	  ;			/* ﾌﾞﾗｹﾂﾄ ｼﾖｳ ﾋﾖｳｼﾞ			 **/
		char	tlpiyob2	  ;			/* ﾖﾋﾞ2						 **/
		short	tlpitben	  ;			/* TLPI	ｶｸﾁﾖｳﾌﾞ	ｴﾝﾄﾘｰ ﾊﾞﾝｺﾞｳ **/
		short	tlpipatn	  ;			/* TPAT	ｴﾝﾄﾘｰ ﾊﾞﾝｺﾞｳ	   CC */
		short	tlpiyob3	  ;			/* ﾖﾋﾞ3					   CC */
		char	tlpipsnm[8]	  ;			/* ﾛﾝﾘ ﾊﾟｽ ｼｷﾍﾞﾂﾒｲ		   CC */
		long	tlpiyob4[2]	  ;			/* ﾖﾋﾞ4					   CC */
};
typedef	struct	mdlpiko	MDLPIKO;		/* DCP ﾖｳ					  */
typedef	struct	mdlpiko	TLPIPSZ;		/* FIP ﾖｳ					  */
