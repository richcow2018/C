/**********************************************************************/
/*																	  */
/* tfai.h 94/09/16 ÉÙ»ÎÄÌ µ×ÊÝÅÄ									  */
/*																	  */
/**********************************************************************/

typedef	struct {
		short	 tfaiinen;				 /*	Í½È÷					  */
		char	 tfaitype;				 /*	Â³¼Ý ¾²·ÞÖ ¼ÕÍÞÂ		  */
		char	 tfaiyob0;				 /*	ÖËÞ0					  */
		short	 tfaipsmx;				 /*	ÛÝØ	Êß½	»²ÀÞ² ½³		  */
		char	 tfaiyob1[6];			 /*	ÖËÞ1					  */
}				 TFAISUB;				 /*	DYRECÖ³					  */

typedef	struct {
		char   tfailnsb		 ;			 /*	¶²¾Ý ¼­ÍÞÂ				  */
		char   tfaipksb		 ;			 /*	Êß¯¹°¼Þ	¼­ÍÞÂ			  */
		char   tfainjid[6]	 ;			 /*	2¼Þ·®¸ ¼·ÍÞÂ ¼Þ®³Î³		  */
		char   tfaipsnm[22]	 ;			 /*	Êß½	Ò²					  */
		short  tfailnno		 ;			 /*	¶²¾Ý ÊÞÝºÞ³				  */
		long   tfaimbid		 ;			 /*	Ò°ÙÎÞ¯¸½ ID				  */
		short  tfaiifrm		 ;			 /*	I ÌÚ°Ñ Á®³				  */
		char   tfaiyuko		 ;			 /*	Õ³º³ Ñº³ Ë®³¼Þ			  */
		char   tfaiyob2		 ;			 /*	ÖËÞ2					  */
		short  tfaisszu		 ;			 /*	¾¸ÞÒÝÄ»²½Þ(ÉÎÞØ)		  */
		short  tfaisszd		 ;			 /*	¾¸ÞÒÝÄ»²½Þ(¸ÀÞØ)		  */
		char   tfaishut		 ;			 /*	SHUT-DOWN ËÖ³¼Þ			  */
		char   tfaidlty		 ;			 /*	ÃÞ°À ØÝ¸ ËÖ³¼Þ			  */
		char   tfaibloc		 ;			 /*	ÌÞÛÂ¸ ½³ ËÖ³¼Þ			  */
		char   tfaibkup		 ;			 /*	ÊÞÂ¸ ±ÂÌß ËÖ³¼Þ			  */
		char   tfaipckb		 ;			 /*	Â³¼Ý ¾²·ÞÖ ¼ÕÍÞÂ		  */
		char   tfailsts		 ;			 /*	¶²¾Ý ½Ã°À½				  */
		char   tfailhdk		 ;			 /*	¶²¾Ý ËÄÞ³· Â³Á ½Ã°À½	  */
		char   tfailkdk		 ;			 /*	¶²¾Ý ¶²Ì¸ ÄÞ³· ½Ã°À½	  */
		short  tfaidadn		 ;			 /*	TDAD ´ÝÄØ ÊÞÝºÞ³		  */
		short  tfaitben		 ;			 /*	¶¸Á®³ Ã°ÌÞÙ	´ÝÄØ ÊÞÝºÞ³	  */
		short  tfaifacn		 ;			 /*	£Ô£Æ£Á£Ã¤Î¥¨¥ó¥È¥êÈÖ¹æ	  */
		char   tfaichst		 ;			 /*							  */
		char   tfaiyob3		 ;			 /*	 Í½È÷					  */
		short  tfailpte		 ;			 /*	TLPH Îß²ÝÀ Õ³º³	´ÝÄØ½³	  */
		short  tfaitplt		 ;			 /*	TPLT ´ÝÄØ ÊÞÝºÞ³		  */
		char   tfaiyob4[4]	 ;			 /*	 Í½È÷					  */
}			   TFAIPSZ;					 /*	DYREC Ö³				  */

typedef	struct {
		short	 tfailphn;				 /*	TLPH ´ÝÄØ ÊÞÝºÞ³		  */
}				 TFAIPS;				 /*	DYRE Ö³					  */
