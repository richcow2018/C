/*********************************************************************/
/* �ץ�������̾����                                                */
/* �ץ���̾      ���ϣã�                                          */
/* ��¤�ֹ桡��������PRC-049-01                                      */
/* ��¤���ơ���������DEBUGʸ�ե�����񤭹��ߵ�ǽ���ɲ�               */
/* ��¤��������������2003.01.07                                      */
/* ��¤�ԡ�����������supply Sugawara                                 */
/*********************************************************************/
#ifdef DEBUG
/* debug console output mode :���󥽡������ */
/*	long osdelay();	*/
#define PRINTF(p1,p2)             {printf(p1,p2); /*osdelay(2L,2L);*/}
#define PRINT0(p1)                {printf(p1); /*osdelay(2L,2L);*/}
#define PRINT1(p1,p2)             {printf(p1,p2); /*osdelay(2L,2L);*/}
#define PRINT2(p1,p2,p3)          {printf(p1,p2,p3); /*osdelay(2L,2L);*/}
#define PRINT3(p1,p2,p3,p4)       {printf(p1,p2,p3,p4); /*osdelay(2L,2L);*/}
#define PRINT4(p1,p2,p3,p4,p5)    {printf(p1,p2,p3,p4,p5); /*osdelay(2L,2L);*/}
#define PRINT5(p1,p2,p3,p4,p5,p6) {printf(p1,p2,p3,p4,p5,p6); /*osdelay(2L,2L);*/}
#else
#ifdef DEBUGF
/* debug file write mode : �ե�����񤭹��� */

	void  mc_debugf(long count, ... ) ;

#define PRINTF(p1,p2)             {mc_debugf(2, p1,p2);}
#define PRINT0(p1)                {mc_debugf(1,p1);}
#define PRINT1(p1,p2)             {mc_debugf(2,p1,p2);}
#define PRINT2(p1,p2,p3)          {mc_debugf(3,p1,p2,p3);}
#define PRINT3(p1,p2,p3,p4)       {mc_debugf(4,p1,p2,p3,p4);}
#define PRINT4(p1,p2,p3,p4,p5)    {mc_debugf(5,p1,p2,p3,p4,p5);}
#define PRINT5(p1,p2,p3,p4,p5,p6) {mc_debugf(6,p1,p2,p3,p4,p5,p6);}

#else
/* debug no print :���֥⡼�� */
#define PRINTF(p1,p2)                 {}
#define PRINT0(p1)                    {}
#define PRINT1(p1,p2)                 {}
#define PRINT2(p1,p2,p3)              {}
#define PRINT3(p1,p2,p3,p4)           {}
#define PRINT4(p1,p2,p3,p4,p5)        {}
#define PRINT5(p1,p2,p3,p4,p5,p6)     {}
#endif

#endif
