#ifdef MOLOG
	void mo_xlog();
#define MOXLOG(p1,p2,p3,p4)  {mo_xlog(p1,p2,p3,p4);}
#else
#define MOXLOG(p1,p2,p3,p4)  {}
#endif
