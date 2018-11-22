#ifdef DBG
/* デバッグ文標準出力 */
#define DPRINT(p1)				{printf(p1);}
#define DPRINT1(p1,p2)			{printf(p1,p2);}
#define DPRINT2(p1,p2,p3)		{printf(p1,p2,p3);}
#define DPRINT3(p1,p2,p3,p4)	{printf(p1,p2,p3,p4);}
#define DPRINT4(p1,p2,p3,p4,p5)	{printf(p1,p2,p3,p4,p5);}
#define	DDMP(p1,p2)				{t_dmp(p1,p2);}

#else
#ifdef DBGF
/* デバッグ文ファイル書き込み */
    void  mc_debugf(long count, ... ) ;
#define DPRINTF(p1,p2)				{mc_debugf(2, p1,p2);}
#define DPRINT(p1)					{mc_debugf(1,p1);}
#define DPRINT1(p1,p2)				{mc_debugf(2,p1,p2);}
#define DPRINT2(p1,p2,p3)			{mc_debugf(3,p1,p2,p3);}
#define DPRINT3(p1,p2,p3,p4)		{mc_debugf(4,p1,p2,p3,p4);}
#define DPRINT4(p1,p2,p3,p4,p5)		{mc_debugf(5,p1,p2,p3,p4,p5);}
#define DPRINT5(p1,p2,p3,p4,p5,p6)	{mc_debugf(6,p1,p2,p3,p4,p5,p6);}
#define DDMP(p1,p2)					{t_dmp(p1,p2);}

#else
/* 本番 */
#define DPRINT(p1)				{}
#define DPRINT1(p1,p2)			{}
#define DPRINT2(p1,p2,p3)		{}
#define DPRINT3(p1,p2,p3,p4)	{}
#define DPRINT4(p1,p2,p3,p4,p5)	{}
#define	DDMP(p1,p2)				{}
#endif

#endif
