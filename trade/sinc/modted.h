#ifdef MOPDTE
#define MOSYSDTE(key,string)	{				\
	osgtdat(&mosysdte[modtecnt%30][1],			\
			&mosysdte[modtecnt%30][2]);			\
	printf("OCP_DATE NO.%2d [%08x:%08x] %s\n",	\
			modtecnt,							\
			mosysdte[modtecnt%30][1],			\
			mosysdte[modtecnt%30][2],			\
			string);							\
	mc_ccpy(key,								\
			(char *)&mosysdte[modtecnt%30][0],	\
			4L);								\
	modtecnt++;									\
	}
#else
#define MOSYSDTE(key,string)	{				\
	osgtdat(&mosysdte[modtecnt%30][1],			\
			&mosysdte[modtecnt%30][2]);			\
	mc_ccpy(key,								\
			(char *)&mosysdte[modtecnt%30][0],	\
			4L);								\
	modtecnt++;									\
	}
#endif
