/****************************************************************************/
/*																			*/
/* tlgu.h 94/09/16 ÉÙ»ÎÄÌ µ×ÊÝÅÄ											*/
/*																			*/
/****************************************************************************/
typedef	struct {
	short				tlguinen;		/* Í½È÷								*/
	char				tlguyob0[6];	/* ŽÖŽËŽÞ0								*/
}						TLGUSUB;		/* FIP ŽÖŽ³							*/

struct mdlguko {
	char   tlgukhyo	   ;	  /* ŽºŽÍŽÞŽÂŽÌŽÞ	ŽËŽ®Ž³Ž¼ŽÞ				*/
	char   tlguyob1[3] ;	  /* ŽÖŽËŽÞ1						*/
	short  tlgulphn	   ;	  /* TLPH Ž´ŽÝŽÄŽØ NO.				*/
	short  tlgulptn	   ;	  /* TLPT Ž´ŽÝŽÄŽØ NO.				*/
	short  tlgupatn	   ;	  /* TPAT Ž´ŽÝŽÄŽØ NO.				*/
	short  tlguyob2	   ;	  /* ŽÖŽËŽÞ2						*/
	long   *tlgumiaa   ;	  /* Ž×Ž²ŽÄ MIA ŽÀŽ²ŽËŽ²Ž· Ž±ŽÄŽÞŽÚŽ½		*/
	long   *tlgudsad   ;	  /* ŽÎŽØŽ­Ž³ ŽÃŽÞŽ°ŽÀ ŽÀŽ²ŽË Ž±ŽÄŽÞŽÚŽ½		*/
	char   tlguyob3[4] ;	  /* ŽÖŽËŽÞ3						*/
};
typedef	struct mdlguko TLGUPSZ;	  /* FIP ŽÖŽ³						*/
