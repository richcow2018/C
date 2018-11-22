/**********************************************************************/
/*																	  */
/* tfai.h 94/09/16 ÉÙ»ÎÄÌ µ×ÊÝÅÄ									  */
/*																	  */
/**********************************************************************/

typedef	struct {
		short	 tfaiinen;				 /*	Í½È÷					  */
		char	 tfaitype;				 /*	ŽÂŽ³Ž¼ŽÝ Ž¾Ž²Ž·ŽÞŽÖ Ž¼ŽÕŽÍŽÞŽÂ		  */
		char	 tfaiyob0;				 /*	ŽÖŽËŽÞ0					  */
		short	 tfaipsmx;				 /*	ŽÛŽÝŽØ	ŽÊŽßŽ½	Ž»Ž²ŽÀŽÞŽ² Ž½Ž³		  */
		char	 tfaiyob1[6];			 /*	ŽÖŽËŽÞ1					  */
}				 TFAISUB;				 /*	DYRECŽÖŽ³					  */

typedef	struct {
		char   tfailnsb		 ;			 /*	Ž¶Ž²Ž¾ŽÝ Ž¼Ž­ŽÍŽÞŽÂ				  */
		char   tfaipksb		 ;			 /*	ŽÊŽßŽ¯Ž¹Ž°Ž¼ŽÞ	Ž¼Ž­ŽÍŽÞŽÂ			  */
		char   tfainjid[6]	 ;			 /*	2Ž¼ŽÞŽ·Ž®Ž¸ Ž¼Ž·ŽÍŽÞŽÂ Ž¼ŽÞŽ®Ž³ŽÎŽ³		  */
		char   tfaipsnm[22]	 ;			 /*	ŽÊŽßŽ½	ŽÒŽ²					  */
		short  tfailnno		 ;			 /*	Ž¶Ž²Ž¾ŽÝ ŽÊŽÞŽÝŽºŽÞŽ³				  */
		long   tfaimbid		 ;			 /*	ŽÒŽ°ŽÙŽÎŽÞŽ¯Ž¸Ž½ ID				  */
		short  tfaiifrm		 ;			 /*	I ŽÌŽÚŽ°ŽÑ ŽÁŽ®Ž³				  */
		char   tfaiyuko		 ;			 /*	ŽÕŽ³ŽºŽ³ ŽÑŽºŽ³ ŽËŽ®Ž³Ž¼ŽÞ			  */
		char   tfaiyob2		 ;			 /*	ŽÖŽËŽÞ2					  */
		short  tfaisszu		 ;			 /*	Ž¾Ž¸ŽÞŽÒŽÝŽÄŽ»Ž²Ž½ŽÞ(ŽÉŽÎŽÞŽØ)		  */
		short  tfaisszd		 ;			 /*	Ž¾Ž¸ŽÞŽÒŽÝŽÄŽ»Ž²Ž½ŽÞ(Ž¸ŽÀŽÞŽØ)		  */
		char   tfaishut		 ;			 /*	SHUT-DOWN ŽËŽÖŽ³Ž¼ŽÞ			  */
		char   tfaidlty		 ;			 /*	ŽÃŽÞŽ°ŽÀ ŽØŽÝŽ¸ ŽËŽÖŽ³Ž¼ŽÞ			  */
		char   tfaibloc		 ;			 /*	ŽÌŽÞŽÛŽÂŽ¸ Ž½Ž³ ŽËŽÖŽ³Ž¼ŽÞ			  */
		char   tfaibkup		 ;			 /*	ŽÊŽÞŽÂŽ¸ Ž±ŽÂŽÌŽß ŽËŽÖŽ³Ž¼ŽÞ			  */
		char   tfaipckb		 ;			 /*	ŽÂŽ³Ž¼ŽÝ Ž¾Ž²Ž·ŽÞŽÖ Ž¼ŽÕŽÍŽÞŽÂ		  */
		char   tfailsts		 ;			 /*	Ž¶Ž²Ž¾ŽÝ Ž½ŽÃŽ°ŽÀŽ½				  */
		char   tfailhdk		 ;			 /*	Ž¶Ž²Ž¾ŽÝ ŽËŽÄŽÞŽ³Ž· ŽÂŽ³ŽÁ Ž½ŽÃŽ°ŽÀŽ½	  */
		char   tfailkdk		 ;			 /*	Ž¶Ž²Ž¾ŽÝ Ž¶Ž²ŽÌŽ¸ ŽÄŽÞŽ³Ž· Ž½ŽÃŽ°ŽÀŽ½	  */
		short  tfaidadn		 ;			 /*	TDAD Ž´ŽÝŽÄŽØ ŽÊŽÞŽÝŽºŽÞŽ³		  */
		short  tfaitben		 ;			 /*	Ž¶Ž¸ŽÁŽ®Ž³ ŽÃŽ°ŽÌŽÞŽÙ	Ž´ŽÝŽÄŽØ ŽÊŽÞŽÝŽºŽÞŽ³	  */
		short  tfaifacn		 ;			 /*	£Ô£Æ£Á£Ã¤Î¥¨¥ó¥È¥êÈÖ¹æ	  */
		char   tfaichst		 ;			 /*							  */
		char   tfaiyob3		 ;			 /*	 Í½È÷					  */
		short  tfailpte		 ;			 /*	TLPH ŽÎŽßŽ²ŽÝŽÀ ŽÕŽ³ŽºŽ³	Ž´ŽÝŽÄŽØŽ½Ž³	  */
		short  tfaitplt		 ;			 /*	TPLT Ž´ŽÝŽÄŽØ ŽÊŽÞŽÝŽºŽÞŽ³		  */
		char   tfaiyob4[4]	 ;			 /*	 Í½È÷					  */
}			   TFAIPSZ;					 /*	DYREC ŽÖŽ³				  */

typedef	struct {
		short	 tfailphn;				 /*	TLPH Ž´ŽÝŽÄŽØ ŽÊŽÞŽÝŽºŽÞŽ³		  */
}				 TFAIPS;				 /*	DYRE ŽÖŽ³					  */
