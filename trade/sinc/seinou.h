#ifdef SEINOU
	long 	gtdt[200];       	/* ���ջ����Ǽ��			 */
	long 	gttm[200];       	/* �¹Ի����Ǽ��			 */
	long	adress;				/* ���ɥ쥹�����ѥ�����ꥢ */
#endif
#define GETTIME(no) { 	osgtdat(&gtdt[no],&gttm[no]); }
