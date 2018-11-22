
/**********************************************************************/
/*																	  */
/*		  TLPU ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ		tlpu.h		(94.09.16)				  */
/*									  ﾍﾝｺｳ	(  .  .	 )				  */
/*									  変更	   .  .					  */
/*									  変更者						  */
/*																	  */
/**********************************************************************/

struct mdlpusb {
		short	 tlpuinen;				 /*	予備				   JJ */
		char	 tlpuyob0[6];			 /*	ﾖﾋﾞ0					  */
};
typedef	struct mdlpusb MDLPUSB;			 /*	DCP	ﾖｳ					  */
typedef	struct mdlpusb TLPUSUB;			 /*	FIP	ﾖｳ					  */

struct mdlpuko {
	char   tlpukhyo	   ;				 /*	ｺﾍﾞﾂﾌﾞ ﾋｮｳｼﾞ			  */
	char   tlpuyob1[3] ;				 /*	ﾖﾋﾞ1					  */
	short  tlpufapn	   ;				 /*	TFAP ｴﾝﾄﾘ NO.			  */
	short  tlpulgtn	   ;				 /*	TLGT ｴﾝﾄﾘ NO.			  */
	char   tlpuipas	   ;				 /*	ﾊﾟｽ	ｽﾃｰﾀｽ				  */
	char   tlpuiatt	   ;				 /*	ATT	ｽﾃｰﾀｽ				  */
	char   tlpuihdk	   ;				 /*	ﾋﾄﾞｳｷ ｽﾃｰﾀｽ				  */
	char   tlpuyob2	   ;				 /*	ﾖﾋﾞ2					  */
	short  tlpupatn	   ;				 /*	TPAT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ	   CC */
	short  tlpuyob3	   ;				 /*	ﾖﾋﾞ3				   CC */
	char   tlpupsnm[8] ;				 /*	ﾛﾝﾘ	ﾊﾟｽ	ｼｷﾍﾞﾂﾒｲ		   CC */
	char   tlpuyob4[4] ;				 /*	ﾖﾋﾞ4					  */
};
typedef	struct mdlpuko MDLPUKO;			 /*	DCP	ﾖｳ					  */
typedef	struct mdlpuko TLPUPSZ;			 /*	FIP	ﾖｳ					  */
