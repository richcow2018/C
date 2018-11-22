/****************************************************************************/
/* ��ʬ�ǡ������															*/
/*																			*/
/* ����: 94/09/16															*/
/* ����:																	*/
/*		95.06.29 K.Kubota SSCY0076: �Ɏ��Ď޴��̿��ʎߎ���ʬ�����ֵ�				*/
/*	95.09.08 K.Kubota ST3242: New funcs mm_di90[012]()						*/
/*	96.11.06 K.Kubota ST4592: New funcs mm_di94[012]()						*/
/*										mm_di3[23]3(), mm_di3[48]2()		*/
/*	97.02.09 K.Kubota ST4651: delete funcs mm_di94[01]()					*/
/*	03.03.06 ���ץ饤���䲼 MD001: Linux�ܿ���ȼ������						*/
/*							����쥳���ɿ��ѹ�								*/
/****************************************************************************/
#include "mcmia.h"
#include "mm_dyrec.h"
#include "mme_dyr9.h"

/*#define	MAXRECORD	  10L										MD001	*/
#define	MAXRECORD	  6L					/*						MD001	*/
#define	PROCDELETE	  0x01
#define	PROCUPDATE	  0x02
#define	PROCINSERT	  0x03

/**-------------------------------------------------------------------------*/
/*	   ��ʬ�ǡ�����С���¤�����											*/
/**-------------------------------------------------------------------------*/

/**--------------------------------------*/
/*	   ����Î��̎ގ�	  ��������������	 */
/**--------------------------------------*/
typedef	struct {
	PPOOLBUF			regu_ptr[MAXRECORD]; /* �������Îގ����̎ߎ��َʎގ��̎���		*/
	PPOOLBUF			rvrs_ptr[MAXRECORD]; /* ���������Îގ����̎ߎ��َʎގ��̎���		*/
	PPOOLBUF			ddif_ptr[MAXRECORD]; /* ű���Ѻ�ʬ�Îގ����̎ߎ��َʎގ��̎���	*/
	PPOOLBUF			adif_ptr[MAXRECORD]; /* �����Ѻ�ʬ�Îގ����̎ߎ��َʎގ��̎���	*/
	long				ddifNum;			/* ű���Ѻ�ʬ�Îގ����ڎ����Ď޿�		*/
	long				adifNum;			/* �����Ѻ�ʬ�Îގ����ڎ����Ď޿�		*/
	long				reguNum[MAXRECORD];	/* �������Îގ��������ڎ����Ď޿�			*/
	char				**(ReguIndx[MAXRECORD]); /* �������Îގ��������̎ߎ��ٰ�		*/
	long				rvrsNum[MAXRECORD];	/* ���������Îގ��������ڎ����Ď޿�		*/
	char				**(RvrsIndx[MAXRECORD]); /* ���������Îގ��������̎ߎ��ٰ�	*/
}						ADDRTBL;
typedef	ADDRTBL			*PADDRTBL;

/**-------------------------------------------------------------------------*/
/*	   ��ʬ�ǡ�����С��ؿ����											  */
/**-------------------------------------------------------------------------*/
extern long				mm_di100();
extern long				mm_di110();
extern void				mm_di200();
extern long				mm_di210();
extern long				mm_di220();
extern long				mm_di230();
extern long				mm_di240();
extern long				mm_di250();
extern long				mm_di260();
extern long				mm_di270();
extern long				mm_di280();
extern long				mm_di290();
extern long				mm_di2a0();
extern long				mm_di300();
extern long				mm_di301();
extern long				mm_di310();
extern void				mm_di311();
extern long				mm_di320();
extern void				mm_di321();
extern long				mm_di323(); /* ###ST4592							*/
extern long				mm_di330();
extern void				mm_di331();
extern long				mm_di333(); /* ###ST4592							*/
extern long				mm_di340();
extern void				mm_di341();
extern long				mm_di342(); /* ###ST4592							*/
extern long				mm_di350();
extern void				mm_di351();
extern long				mm_di360();
extern void				mm_di361();
extern long				mm_di370();
extern void				mm_di371();
extern long				mm_di380();
extern void				mm_di381();
extern long				mm_di382(); /* ###ST4592							*/
extern long				mm_di390();
extern void				mm_di391();
extern long				mm_di3a0();
extern void				mm_di3a1();
extern long				mm_di400();
extern long				mm_di401();
extern long				mm_di410();		/* ###SSCY0076						*/
extern long				mm_di500();
extern long				mm_di600();
extern void				mm_di900();		/* NewFace ###ST3242				*/
extern long				mm_di901();		/* NewFace ###ST3242				*/
extern short			mm_di902();		/* NewFace ###ST3242				*/
#ifdef DEL_ST4651
extern void				mm_di940();		/* NewFace ###ST4592				*/
extern long				mm_di941();		/* NewFace ###ST4592				*/
#endif
extern long				mm_di942();		/* NewFace ###ST4592				*/
extern long				mm_diff();
