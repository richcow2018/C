/********************************************************************/
/*																	*/
/* tfaq.h  94.09.16	ÉÙ»ÎÄÌ µ×ÊÝÅÄ									*/
/*																	*/
/*																	*/
/********************************************************************/

struct mdfaqsb {
	short	 tfaqinen;					/* Í½È÷					 JJ	*/
	char	 tfaqricp;					/* Í½È÷					 JJ	*/
	char	 tfaqyob0[5];				/* ŽÖŽËŽÞ 0					*/
};
typedef	struct mdfaqsb TFAQSUB;			/* FIP ŽÖŽ³					*/

struct mdfaqko {
	char	tfaqkbst;				/*	ŽºŽÍŽÞŽÂŽÌŽÞ Ž½ŽÃŽ°ŽÀŽ½			*/
	char	tfaqyob1;				/*	ŽÖŽËŽÞ	1					*/
	short	tfaqfacn;				/*	TFAC Ž´ŽÝŽÄŽØ NO			*/
	short	tfaqlptn;				/*	TLPT Ž´ŽÝŽÄŽØ NO			*/
	char	tfaqiokd;				/*	ŽÀŽÝŽÏŽÂ Ž¼Ž­ŽÍŽÞŽÂ				*/
	char	tfaqyob2;				/*	ŽÖŽËŽÞ	2					*/
	short	tfaqdvno;				/*	Ž¿Ž³ŽÁ	ŽÊŽÞŽÝŽºŽÞŽ³				*/
	short	tfaqphno;				/*	ŽÛŽÝŽØ	ŽÊŽßŽ½	ŽÊŽÞŽÝŽºŽÞŽ³			*/
	char	tfaqsoft;				/*	Ž¿ŽÌŽÄ	Ž·ŽÊŽÞŽÝ				*/
	char	tfaqprfx;				/*	ŽÌŽßŽÚŽÌŽ¨Ž¸Ž½					*/
/* *** 87.12.7 *** STC550 *** */
	char	tfaqfiln[22];			/*	ŽÄŽ¸Ž¼Ž­ ŽÌŽ§Ž²ŽÙ ŽÒŽ²			*/
	long	tfaqfdsc;				/*	ŽÌŽ§Ž²ŽÙ ŽÃŽÞŽ¨Ž½Ž¸ŽØŽÌŽßŽÀ			*/
	char	tfaqflst;				/*	ŽÌŽ§Ž²ŽÙ Ž½ŽÃŽ°ŽÀŽ½				*/
	char	tfaqlpws;				/*	Ž³Ž²ŽÝŽÄŽÞŽ³ Ž»Ž²Ž½ŽÞ				*/
	char	tfaqyob3[14];			/*	ŽÖŽËŽÞ	3					*/
};
typedef	struct mdfaqko TFAQPSZ;			/* FIP ŽÖŽ³					*/
