
/**********************************************************************/
/*																	  */
/* tpau.h  94.09.16	ÉÙ»ÎÄÌ µ×ÊÝÅÄ									  */
/*																	  */
/**********************************************************************/

typedef	struct {
		short  tpauwsmx;			   /* Ž»Ž²ŽÀŽÞŽ²	ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ Ž¶ŽÝŽØŽ½Ž³		  */
		char   tpautint;			   /* md_tint ŽÖŽ³				  */
		char   tpauyob1;			   /* ŽÖŽËŽÞ1						  */
		char   tpauyob2[8];			   /* ŽÖŽËŽÞ2						  */
		short  tpauioen;			   /* Í½È÷					   JJ */
		short  tpauiosu;			   /* Í½È÷					   JJ */
		short  tpaucken;			   /* Í½È÷					   JJ */
		short  tpaucksu;			   /* Í½È÷					   JJ */
		char   tpauyob3[4];			   /* ŽÖŽËŽÞ3						  */
}			   TPAUSUB;				   /* FIP ŽÖŽ³					  */

typedef	struct {
		char   tpaugrcd[12]	 ;		   /* Ž¸ŽÞŽÙŽ°ŽÌŽß ŽºŽ°ŽÄŽÞ				  */
		char   tpaundth		 ;		   /* NTC ŽÀŽÞŽ²ŽËŽÖŽ³ ŽËŽÖŽ³Ž¼ŽÞ			  */
		char   tpausdth		 ;		   /* Ž»ŽÌŽÞ Ž¸ŽÞŽÙŽ°ŽÌŽß ŽÀŽÞŽ²ŽËŽÖŽ³	ŽËŽÖŽ³Ž¼ŽÞ	  */
		short  tpauiokd		 ;		   /* IO Ž¼ŽÕŽÍŽÞŽÂ					  */
		short  tpauwsen		 ;		   /* ŽÕŽ³ŽºŽ³ ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ Ž¶ŽÝŽØŽ½Ž³		  */
		short  tpaupctn		 ;		   /* TPCT Ž´ŽÝŽÄŽØ	NO.				  */
		char   tpauyob4[4];			   /* ŽÖŽËŽÞ4						  */
}			   TPAUPSZ;				   /* FIP ŽÖŽ³					  */

typedef	struct {
		char	tpauwscl;			   /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ	Ž¼Ž­ŽÍŽÞŽÂ			  */
		char	tpauwskb;			   /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼ŽÖŽÝ	NO.	Ž¾Ž¯ŽÃŽ² Ž¸ŽÌŽÞŽÝ  CC */
		short	tpauwsno;			   /* ŽÜŽ°Ž¸Ž½ŽÃŽ°Ž¼Ž®ŽÝ	NO.				  */
		char	tpauyob5[4];		   /* ŽÖŽËŽÞ5						  */
}				TPAUWS;				   /* FIP ŽÖŽ³					  */
