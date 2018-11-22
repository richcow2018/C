/********************************************/
/*		　mearg.h							*/
/*	　　ｱｰｷﾞｭﾒﾝﾄ域ﾌｧｰﾏｯﾄ					*/
/********************************************/

struct radarg{
	long	rapsfd;		/*ﾌｧｲﾙﾃﾞｨｽｸﾘﾌﾟﾀ		*/
	char	*raptr;		/*受信ﾊﾞｯﾌｧｱﾄﾞﾚｽ    */
	long 	rasize;		/*ﾊﾞｯﾌｧｻｲｽﾞ　　　　 */
	long	dosapara;	/*動作ﾊﾟﾗﾒｰﾀ		*/
	char    *rdaptr;	/*受信ﾃﾞｰﾀ格納域ｱﾄﾞﾚｽ*/
	long	rdasize;	/*受信ﾃﾞｰﾀ格納域ｻｲｽﾞ*/
	long 	rarit;		/*ﾘﾄﾗｲ回数          */
	long	pbfadr;		/* ﾌﾟｰﾙﾊﾞｯﾌｧｱﾄﾞﾚｽ	*/
};
typedef struct radarg RADARG;

struct wrtarg{
	long	fildes;		/*ﾌｧｲﾙﾃﾞｨｽｸﾘﾌﾟﾀ		*/
	char	*bufptr;	/*送信ﾊﾞｯﾌｧｱﾄﾞﾚｽ    */
	long 	wrtlen;		/*送信済みﾃﾞｰﾀ長	*/
	long	dosapara;	/*動作ﾊﾟﾗﾒｰﾀ		*/
	char    *outadr;	/*出力域ｱﾄﾞﾚｽ	　　*/
	long	outsize;	/*出力納域ｻｲｽﾞ		*/
	long 	retry;		/*ﾘﾄﾗｲ回数          */
	long    wrqlen;	/*送信要求ｻｲｽﾞ		*/
};
typedef struct wrtarg WRTARG;
