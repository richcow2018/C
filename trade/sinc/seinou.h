#ifdef SEINOU
	long 	gtdt[200];       	/* 日付時刻格納域			 */
	long 	gttm[200];       	/* 実行時刻格納域			 */
	long	adress;				/* アドレス設定用ワークエリア */
#endif
#define GETTIME(no) { 	osgtdat(&gtdt[no],&gttm[no]); }
