/*****************************NTC-SMP-RCV*****************************/
/*                                                                   */
/*   1 ﾌｧｲﾙﾒｲ                                                        */
/*      ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ ﾌｧｲﾙ (mrprcv.h)                                  */
/*                                                                   */
/*   2 ｸﾌﾞﾝ                                                          */
/*      ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ ﾌｧｲﾙ                                             */
/*                                                                   */
/*   3 ﾘﾚｷ                                                           */
/*      ｾｯｹｲ ｼｬ : ﾀｹｳﾁ ｼﾝｲﾁ                        			         */
/*      ｻｸｾｲ ｼｬ : ﾀｹｳﾁ ｼﾝｲﾁ                         			     */
/*      ﾍﾝｺｳ ｼｬ : 佐藤　亘            93/11/12          TD-00        */
/*				  (終了ｺｰﾄﾞの拡張による変更)			TD-64		 */
/*				  (内部事情による変更)					TD-@1		 */
/*                                                                   */
/*********************************************************************/

/*********************************************************************/
/*    MRPRB (ｷｮｳﾂｳ ｼﾞｮｳﾎｳ ｾｯﾃｲ ﾘｮｳｲｷ)                                */
/*********************************************************************/
struct mrprb{
	 long    mrprabc;          /* 故障ｺｰﾄﾞ						TD00 */
	 long    mrprabd;          /* ｱﾎﾞｰﾄ時の詳細情報				TD00 */
	 long    mrprabd2;		   /* ｱﾎﾞｰﾄ時の詳細情報２			TD64 */
	 long    mrprabd3;		   /* ｱﾎﾞｰﾄ時の詳細情報３			TD64 */
	 char    mrprsta;          /* ﾄﾗﾝｻﾞｸｼｮﾝ状態					TD00 */
	 char    mrpryob[3];       /* 予備							TD@1 */
	 long	 mrprdwd;		   /* 異常情報						TD00 */
};
typedef struct mrprb MRPRB;

