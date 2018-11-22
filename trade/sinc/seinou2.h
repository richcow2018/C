#ifdef SEINOU
	extern long 	gtdt[200];       	/* ÆüÉÕ»þ¹ï³ÊÇ¼°è			 */
	extern long 	gttm[200];       	/* ¼Â¹Ô»þ¹ï³ÊÇ¼°è			 */
#endif
#define GETTIME(no)	{	osgtdat(&gtdt[no],&gttm[no]); }
