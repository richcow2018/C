
/**************************************************************************/
/*																		  */
/*		 TEFY ﾃ-ﾌﾞﾙ	ﾌｫ-ﾏｯﾄ		 tefy.h		   (94.09.16)				  */
/*																		  */
/**************************************************************************/
struct mdefysb {						 /*	 TEFY ｻﾌﾞ共通部				  */
	   long	   tefytmop;				 /*	 再ｵｰﾌﾟﾝﾀｲﾏ	ﾁ				  */
	   long	   tefytmdl;				 /*	 ﾃﾞｰﾀﾘﾝｸﾀｲﾏ	ﾁ				  */
};										 /*								  */
typedef	struct mdefysb TEFYSUB;			 /*								  */
										 /*								  */
struct mdefyko {						 /*	 TEFY 個別部				  */
	   char	   tefypuno;				 /*	 PU番号						  */ 
	   char	   yob1;					 /*	 予備						  */
	   char	   tefykset;				 /*	 発着呼運用フラグ　			  */
	   char	   tefyqbit;				 /*	 QビットON/OFF				  */
	   long	   tefyrtri;				 /*	 ﾘﾄﾗｲ回数					  */
	   char	   tefyhpsz;				 /*	 発呼者ﾊﾟｹｯﾄｻｲｽﾞ （乗数）	  */ 
	   char	   tefycpsz;				 /*	 着呼者ﾊﾟｹｯﾄｻｲｽﾞ （乗数）	  */ 
	   char	   tefypkff;				 /*	 ﾊﾟｹｯﾄｻｲｽﾞ ﾌｧｲｼﾘﾃｨﾌﾗｸﾞ		  */ 
	   char	   yob2;					 /*	 予備						  */ 
	   char	   tefyhwsz;				 /*	 発呼者WSNO					  */ 
	   char	   tefycwsz;				 /*	 着呼者WSNO					  */ 
	   char	   tefywsff;				 /*	 WSNO ﾌｧｲｼﾘﾃｨﾌﾗｸﾞ			  */ 
	   char	   yob3;					 /*	 予備						  */ 
	   char	   tefyfasp;				 /*	 ﾌｧｽﾄｾﾚｸﾄ･ﾊﾟﾗﾒｰﾀ			  */ 
	   char	   tefykinp;				 /*	 着信課金･ﾊﾟﾗﾒｰﾀ			  */ 
	   char	   tefythru;				 /*	 発着呼者ｽﾙｰﾌﾟｯﾄｸﾗｽ			  */ 
	   char	   yob4;					 /*	 予備						  */ 
	   long	   tefydeln;				 /*	 相手DTEｱﾄﾞﾚｽ桁数			  */ 
	   long	   tefyhadl;				 /*	 発ｱﾄﾞﾚｽ桁数				  */ 
	   long	   tefycadl;				 /*	 着ｱﾄﾞﾚｽ桁数				  */ 
	   char	   tefydead[20];			 /*	 相手DTEｱﾄﾞﾚｽ格納域ｱﾄﾞﾚｽ	  */ 
	   char	   tefyhaad[20];			 /*	 発ｱﾄﾞﾚｽ					  */ 
	   char	   tefycaad[20];			 /*	 着ｱﾄﾞﾚｽ					  */ 
};										 /*								  */
typedef	struct mdefyko TEFYPSZ;			 /*								  */
