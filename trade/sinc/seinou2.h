#ifdef SEINOU
	extern long 	gtdt[200];       	/* ���ջ����Ǽ��			 */
	extern long 	gttm[200];       	/* �¹Ի����Ǽ��			 */
#endif
#define GETTIME(no)	{	osgtdat(&gtdt[no],&gttm[no]); }
