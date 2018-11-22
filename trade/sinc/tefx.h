/**************************************************************************/
/*                                                                        */
/*       TEFX ﾃ-ﾌﾞﾙ ﾌｫ-ﾏｯﾄ       tefx.h        (06.06.27)                 */
/*                                                                        */
/*       95.5.29 呼設定リトライ間隔設定による修正(ST2638)   田中宏之  M01 */
/*                                                                        */
/**************************************************************************/
struct mdefxsb {                         /*  TEFX ｻﾌﾞ共通部               */
       long    tefxtmop;                 /*  再ｵｰﾌﾟﾝﾀｲﾏ ﾁ                 */
       long    tefxtmdl;                 /*  ﾃﾞｰﾀﾘﾝｸﾀｲﾏ ﾁ                 */
	   long	   tefxtmko;				 /*	 呼設定リトライ間隔タイマ  M01*/ 
};                                       /*                               */
typedef struct mdefxsb TEFXSUB;          /*                               */
                                         /*                               */
struct mdefxko {                         /*  TEFX 個別部                  */
       char    tefxpuno;                 /*  PU番号                       */ 
       char    yob1;                     /*  予備                         */
       char    tefxkset;                 /*  発着呼運用フラグ　           */
       char    tefxqbit;                 /*  QビットON/OFF                */
       long    tefxrtri;                 /*  ﾘﾄﾗｲ回数                     */
       char    tefxhpsz;                 /*  発呼者ﾊﾟｹｯﾄｻｲｽﾞ （乗数）     */ 
       char    tefxcpsz;                 /*  着呼者ﾊﾟｹｯﾄｻｲｽﾞ （乗数）     */ 
       char    tefxpkff;                 /*  ﾊﾟｹｯﾄｻｲｽﾞ ﾌｧｲｼﾘﾃｨﾌﾗｸﾞ        */ 
       char    yob2;                     /*  予備                         */ 
       char    tefxhwsz;                 /*  発呼者WSNO                   */ 
       char    tefxcwsz;                 /*  着呼者WSNO                   */ 
       char    tefxwsff;                 /*  WSNO ﾌｧｲｼﾘﾃｨﾌﾗｸﾞ             */ 
       char    yob3;                     /*  予備                         */ 
       char    tefxfasp;                 /*  ﾌｧｽﾄｾﾚｸﾄ･ﾊﾟﾗﾒｰﾀ              */ 
       char    tefxkinp;                 /*  着信課金･ﾊﾟﾗﾒｰﾀ              */ 
       char    tefxthru;                 /*  発着呼者ｽﾙｰﾌﾟｯﾄｸﾗｽ           */ 
       char    yob4;                     /*  予備                         */ 
       long    tefxdeln;                 /*  相手DTEｱﾄﾞﾚｽ桁数             */ 
       long    tefxhadl;                 /*  発ｱﾄﾞﾚｽ桁数                  */ 
       long    tefxcadl;                 /*  着ｱﾄﾞﾚｽ桁数                  */ 
       char    tefxdead[20];             /*  相手DTEｱﾄﾞﾚｽ格納域ｱﾄﾞﾚｽ      */ 
       char    tefxhaad[20];             /*  発ｱﾄﾞﾚｽ                      */ 
       char    tefxcaad[20];             /*  着ｱﾄﾞﾚｽ                      */ 
};                                       /*                               */
typedef struct mdefxko TEFXPSZ;          /*                               */
