/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ���̎ގʎߎ���������													 */
/*		RCV															 */
/*																	 */
/*	2 ���ݎ��� ���̎ގ�														 */
/*		�̎ߎێ��� �������� / �������؎��� ������										 */
/*																	 */
/*  3 ���ݎ��� �Ҏ�													 	 */
/*		mr_ptbl														 */
/*																	 */
/*	4 ���Ɏ� ���ގ��֎� 													 */
/*		�؎��ʎގ� ���ݎ����� �Î��̎ގ� �� ���Ďގڎ� �� �����Î�	 						 */
/*		�����ގ� �ʎގݎ��ގ� �Î��̎ގ� �� ���Ďގڎ� �� �����Î�	 						 */
/*																	 */
/*	5 �ʎߎ׎Ҏ���														 */
/*		�Ŏ�															 */
/*																	 */
/*	6 �͎ݎ�������														 */
/*		MRNORMAL	:	�������ގ���										 */
/*		MRTBLERR	:	ɬ�פʎÎ��̎ގ٤��ʤ�					TD-00	 */
/*																	 */
/*  7 �؎ڎ�															 */
/*	 	������������ : ���ЎԎ� ������ 											 */
/*	 	������������ : ���ЎԎ� ������ 				'86/07/16					 */
/*	 	�͎ݎ������� : �Ԏώӎ� �Վ�����				' (WLOG)			 */
/*	 	�͎ݎ������� : �ώ��� ��������				'87/09/24 (L01)				 */
/*			 	 (�����ʎߎ� �̎����� ������ �ӎ��Ď� ���ݎ��� �� �ĎӎŎ� �͎ݎ���) --- STC357	 */
/*	 	�͎ݎ������� : �����ގ� ������ 				'87/09/28 (L02)				 */
/*			 	 (�������� �؎��ʎގ� ���ݎڎ� ���Ɏ� �� �������ގ�)          --- STC395	 */
/*		�͎ݎ������� : �Ԏώӎ� �Վ�����				' (L03)				 */
/*			 	 (AP �̎ގݎ��� �������� �� �������ގ�) 				--- STC448	 */
/*		�͎ݎ������� : �Ԏώӎ� �Վ�����				'88/06/16 (L04)				 */
/*			 	 (�Ύ؎��� �Î�-�� �����Ď� ���ݎڎ� ���Ɏ� �� �������ގ�) --- TC1350		 */
/*		�͎ݎ������� : �ώ��� ��������				'88/11/20					 */
/*				 (���������ގ� �������� ���ގ����Ύ� �����Ď� ���ݎ��� �� �͎ݎ���) --- TC1990	 */
/*		�͎ݎ������� : ������				'93/11/04					 */	
/*														   TD-@1	 */
/*														   TD-00	 */
/*				 ��JNL������������û�̤��ѹ���ȼ��������	   TD-41	 */
/*				 �ʥ��θ�ľ����ȼ��������				   TD-50	 */
/*				 �ʣУդ���Ω�����ѹ���ȼ��������		   TD-59 	 */
/*				 ��SCSI�؎����ĵ�ǽ���ѹ���ȼ��������		   TD-61 	 */
/*				 �ʎ؎��ʎގ����׻�VRCV���ѹ���ȼ��������	   TD-76  	 */
/*		�ѹ��� : ����  ����				'95/04/05 --- CT1010(ST2495) */
/*		�ѹ��� : ����  ����				'95/05/02 --- CT1039(ST2764) */
/*				 ��SCSI�؎����ĵ�ǽ���ѹ���ȼ��������		   TD-61 	 */
/*		�ѹ��� : ����  ����				'95/09/11 --- ST3249		 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*�ץ�������̾	:												 */
/*�ץ���̾		:���Хץ���									 */
/*��¤�ֹ�			:KL0004 										 */
/*��¤����			:TABP��Ϣ������ϳ��							 */
/*��¤��			:2003.02.19										 */
/*��¤��			:��								 */
/*********************************************************************/

/*********************************************************************/
/*  ���ݎ��َ��Ď� �̎�����													 */
/*********************************************************************/
#include	"tcom.h"
#include	"mrcom.h"
#include	"mrmac.h"
#include	"mr.h"
#include	"ttct.h"
#include	"tsst.h"
#include	"tcst.h"
#include	"tadt.h"
#include	"tpct.h"
#include	"tbpt.h"
#include	"tsrt.h"
/*********************************************************************/
/*	KL0004  ���� START 												 */
/*  TABP��Ϣ������(tabp.h)										 */
/*********************************************************************/
/*********************************************************************/
/*	KL0004  ���� END 												 */
/*  TABP��Ϣ������(tabp.h)										 */
/*********************************************************************/
#include	"tbkt.h"					/* 						TD@1 */
#include	"tjct.h"					/* 						TD@1 */
#include	"psect.h"					/* 						TD@1 */
#include	"mf.h"						/* 						TD@1 */
#include	"mrj.h"
#include	"mopcb.h"
#include	"mo_wlg.h"					/*						TD50 */
#include	"mcdebug.h"
										/* ̤���ѤΤ��� mcdebug.h �� */
										/* ������� 1��         TD@1 */
									
																  /*%*/
/*********************************************************************/
/*  ���ގ��̎� �͎ݎ��� �؎������� 												 */
/*********************************************************************/
extern		PSCPSECT	pscparea;		/* PSECT �؎�������				 */
extern		MOPSCPCB	*mopcbp;		/* MOPSCPCB �؎�������			 */

/*********************************************************************/
/*	�Îގ̎����� �� 														 */
/*********************************************************************/
#define		MRRSTNO		0x00008000L		/* �����ގݎʎގݎ��ގ� �������� �֎�  		 */
#define		MRIDSIZE	4				/* MRPCB �����͎ގҎ�	 		 */
#define		MRID		"RPB "			/* MRPCB �����͎ގҎ�	 		 */
										/* MRSSTT ̤���ѤΤ�����	 */
#define		CM			0L				/* ���ӎݎҎӎ�			    TD59 */
#define		LM			1L				/* �ێ����َҎӎ�			    TD59 */
#define		MRNO		mopcbp->mopssstp->tsstsysd		   	 /* TD01 */
#define		MRCMADT		pscparea.psccmadt				   	 /* TD59 */
#define		MRLMADT		pscparea.psclmadt			    	 /* TD59 */
										/* MRWLOG���(1��)		TD50 */
#define		TTCTIDX 	0				/* TTCT ��-�̎ގ� ���ݎÎގ�����		 */
#define		TJCTIDX 	1				/* TJCT ��-�̎ގ� ���ݎÎގ�����		 */
#define		TBKTIDX 	2				/* TBKT ��-�̎ގ� ���ݎÎގ�����		 */
#define		TTDTIDX 	3				/* TTDT ��-�̎ގ� ���ݎÎގ�����  (L04) */
#define		TSSTIDX 	4				/* TSST ��-�̎ގ� ���ݎÎގ�����  (L04) */
#define		TRCTIDX 	5				/* TRCT ��-�̎ގ� ���ݎÎގ�����  (L04) */
#define		TPBTIDX 	6				/* TPBT ��-�̎ގ� ���ݎÎގ�����  (L04) */
#define		TVBTIDX 	7				/* TVBT ��-�̎ގ� ���ݎÎގ�����  (L04) */
#define		TRBTIDX 	8				/* TRBT ��-�̎ގ� ���ݎÎގ�����   TD59 */
#define		TSURIDX 	9				/* TSUR ��-�̎ގ� ���ݎÎގ�����   TD61 */
#define		TSBRIDX    10				/* TSBR ��-�̎ގ� ���ݎÎގ�����   TD61 */

/*********************************************************************/
/*	define function name for mo_wlg4						TD-50	 */
/*********************************************************************/
#define	MR_PTBL	0x6d725f70,0x74626c20

long	mr_ptbl()						/* �Î��̎ގ� ���Ďގڎ� �����Î� ������		 */
{
	/*****************************************************************/
	/*  mr_ptbl �Ŏ� ���֎� ���ݎ��� �� �Î�����									 */
	/*****************************************************************/
	long	mc_clea();					/* ���؎� �� ����					 */
	long	mc_ccom();					/* �ӎ��ގڎ� �ˎ��� 		 		 */
	long	mc_copy();					/* �ӎ��ގڎ� ���ˎߎ� 		 		 */
	void	mo_wlg4();					/* S�Ďڎ�������μ���		TD50 */

	/*****************************************************************/
	/*	03-24-2003  ���� START 										 */
	/*  mr_cpct2����Ѥ��Ƥ���Ľ�򎺎Ҏݎ�   					 		 */
	/*****************************************************************/
	//TPCTPSZ	*mr_cpct2();			/* TPCT�����􎱎Ďގڎ�����CT1039 */

	/*****************************************************************/
	/*	03-24-2003  ���� END 										 */
	/*  mr_cpct2����Ѥ��Ƥ���Ľ�򎺎Ҏݎ�   					 		 */
	/*****************************************************************/

	/*****************************************************************/
	/*  �Î��̎ގ� ���ݎ����֎� �Î��̎ގ� 								 			 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*	03-24-2003  ���� START 										 */
	/*  TSUR��TSBR��Ϣ�ν�����������    					 		 */
	/*****************************************************************/
	
	static	struct	mrpidx	{
		char		*mrptbln;			/* ���ݎ��� ���� �Î��̎ގ� �Ҏ�			 */
		TCOMPAT		**mrptbsa;			/* �Î��̎ގ� ���Ďގڎ� �����Î� ���Ďގڎ�	 */
		long		*mrprsta;			/* �����ގ� �ʎގݎ��ގ� �����Î� ���Ďގڎ�	 */
		long		mrpcmlm;			/* CM��LM����		    TD59 */
	} idx[] = {	{"TTCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TJCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TBKT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TTDT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TSST", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TRCT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				{"TPBT", 	(TCOMPAT **)0, (long *)0, LM },
										/* 				  (L03) TD59 */
				{"TVBT", 	(TCOMPAT **)0, (long *)0, CM },
										/* 				  (L03) TD59 */
				{"TRBT", 	(TCOMPAT **)0, (long *)0, CM },  /* TD59 */
				//{"TSUR", 	(TCOMPAT **)0, (long *)0, CM },  
										/* 				 TD59 CT1039 */
				//{"TSBR", 	(TCOMPAT **)0, (long *)0, LM },  /* TD59 */
				{(char *)0, (TCOMPAT **)0, (long *)0 } };
										/*						TD59 */
	
	/*****************************************************************/
	/*	03-24-2003  ���� END 										 */
	/*  TSUR��TSBR��Ϣ�ν�����������    					 		 */
	/*****************************************************************/
	
	/*****************************************************************/
	/*  mr_ptbl �Ŏ� �܎��� ���؎�									 		 */
	/*****************************************************************/
	register	long		retcd;		/* �؎����ݎ� �����Ɏ� ���؎�			 */
	register	TADTPSZ		*tadtp;		/* ADT ���͎ގ̎� ���Ďގڎ� �Ύߎ��ݎ�	 */
	register	TADTPSZ		*tp;
	register	TCOMPAT		*tblp;		/* �Î��̎ގ� ���ݎĎ� ���Ďގڎ�			 */
	register	long		pszno;		/* ADT ���͎ގ̎� �����ݎ�	 		 */
	register	int			efen;		/* �����ݎ�						 */
	register	struct 		mrpidx	*idxp;	/* ���ݎ����֎��Î��̎ގ� �Ύߎ��ݎ�	 */
				long		rstno;		/* �����ގ� �ʎގݎ��ގ� �������� ���؎�		 */

				void		(*dfunc)();	/* modified for bug			 */
				long		mrlog[1];	/* �ێ��� ���ގ����Ύ� �͎ݎ����� �؎�������	 */
				TCOMPAT		*padt;		/* ADT��Ƭ���Ďގڎ�			TD59 */
				TPCTPSZ		*pctp;		/* PCT�����􎱎Ďގڎ�	CT1039   */
				int			i;		    /* �Î��̎ގ�¸�ߎ�������������	TD@1 */
				int			no;		    /* �̎ގێ����ֹ�			TD01 */

	/*****************************************************************/
	/*	�ێ��� ���ގ����Ύ� �� �����Ď�											 */
	/*****************************************************************/
										/* MRWLOG��� 3��		TD50 */
	mo_wlg4(MR_PTBL,WINSC,(long *)0,0L);/*						TD50 */

	/*****************************************************************/
	/*  �����������Î� �� �����Ŏ� 		 										 */
	/*****************************************************************/
	PRINT0("**  mr_ptbl  Start  **\n");
										/* ADT�Ύߎ��ݎ����� ���    TD59 */
										/* MRPCB,MRJCF �Ύߎ��ݎ������Î�	 */
	mrpcbp = (MRPCB *)pscparea.pscmrpcb;
	mrjcfp = (MRJCF *)pscparea.pscmrjcf;
										/* MRPCB �� �����������Î� 			 */
	dfunc = mrpcbp->mrpsexf;			/* modified for bug			 */

	mc_copy(MRID,
			mrpcbp->mrpcbid,
			4L);
	mc_clea((char *)((char *)mrpcbp + MRIDSIZE),
			0,
			(long)(sizeof(MRPCB) - MRIDSIZE));

	mrpcbp->mrpsexf = dfunc;			/* modified for bug			 */

	PRINT1("**  mr_ptbl tsstsysc = %c  **\n",mopcbp->mopssstp->tsstsysc);
	/*****************************************************************/
	/*	03-24-2003  ���� START 										 */
	/*  ������ɥ�����Х������Υ롼�Ȥ�������		 			 */
	/*****************************************************************/
#ifdef LINUX_ISOKUTAIOU
	
	if(mopcbp->mopssstp->tsstsysc == 'C'){	/* �����َĎގ����ݎʎގ���    TD01 */	
		if(MRNO <= '9'){				    /* �̎ގێ�����ʬ����	TD01 */
			no = MRNO - '0';				/* 					TD01 */
		}									/* 					TD01 */
		else{								/*					TD01 */
			no = MRNO - 'A' + 10;			/* 					TD01 */
		}									/* 					TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[no];	 
										/* �̎ߎێ��ގ׎юӎ��Ď�����		TD01 */
		PRINT1("** mr_ptbl tsstprmd[ %d ]  **\n",no);
	}									   	/* 					TD01 */
	else{								/* ���ݎ̎ߎڎ�����,�Ύ��Ď����ݎʎގ��� TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[0];
	}								   	/* �̎ߎێ��ގ׎юӎ��Ď�����		TD01 */

#endif	

	if(mopcbp->mopssstp->tsstsysc != 'C')
	{
										/* ���ݎ̎ߎڎ�����,�Ύ��Ď����ݎʎގ��� TD01 */
		mrpcbp->mrppgmd = mopcbp->mopssstp->tsstprmd[0];
	}								   	/* �̎ߎێ��ގ׎юӎ��Ď�����		TD01 */


	/*****************************************************************/
	/*	03-24-2003  ���� END 										 */
	/*  ������ɥ�����Х������Υ롼�Ȥ�������		 			 */
	/*****************************************************************/
	
	PRINT1("**  mr_ptbl mrppgmd( 0x%08x ) Set  **\n",mrpcbp->mrppgmd);

	/*****************************************************************/
	/*	�؎��ʎގ� / �������� �؎��ʎގ� �֎�/�̎֎� ���ގ����Ύ� �� �����Î�						 */
	/*****************************************************************/
	if( ((mrpcbp->mrppgmd & 0x0000000FL)	/* �Îގʎގ�����		   (L01) */
						== 0x0000000FL) ||	/* �ӎ��Ď�			   (L01) */
		((mrpcbp->mrppgmd & 0x0000000FL)	/* �����ʎߎ� �̎�����	   (L01) */
						== 0x0000000DL) ){	/* ������ �ӎ��Ď�		   (L01) */
		mrpcbp->mrpnsrc = MRPNRUEC;
	}
	else {
		if (mopcbp->mopscstp->tcstrnui==TCSTRNEC) {
			mrpcbp->mrpnsrc = MRPNRNEC;
		}
		else {
			mrpcbp->mrpnsrc = MRPNRUEC;
		}
	}
										/* MRJCF �� �����������Î� 			 */

	mc_clea((char *)mrjcfp,
			0,
			(long)(sizeof(MRJCF)));
	mrjcfp->mrjcfd1 = -1L;			    /* JNL fd �ν����		TD41 */
	mrjcfp->mrjcfd2 = -1L;			    /* KJ  fd �ν����		TD41 */
	mrjcfp->mrjcfd3 = -1L;			    /* ����KJ fd �ν����	TD41 */

	/*****************************************************************/
	/* �Î��̎ގَ��Ďގڎ� �����Î� ���Ďގڎ� / �����ގݎʎގݎ��ގ� �����Î� ���Ďގڎ� �� �����Î�			 */
	/*****************************************************************/
	/************************************/
	/* SCSI�؎��Ď̎ߎێ��������􎱎Ďގڎ�			*/
	/************************************/
	
	/*****************************************************************/
	/*	03-24-2003  ���� START 										 */
	/*  SCSI�؎��Ď̎ߎێ���������������������			 			 */
	/*****************************************************************/

#ifdef LINUX_ISOKUTAIOU

	pctp = mr_cpct2( "CE", 0 );			/*					CT1039	 */
	if ( pctp == ( TPCTPSZ* )0L )		/*					CT1039   */
	{									/* PU0�ˤ�̤¸��	ST3249	 */
		pctp = mr_cpct2( "CE", 1 );		/*					ST3249	 */
		if ( pctp == ( TPCTPSZ* )0L )	/*					ST3249	 */
		{								/* �����������ʤ�	CT1039   */
			mo_wlg4(MR_PTBL,0x33331002L,(long*)0,0L);
										/* mr_cpct2����-����  CT1039	 */
			goto	error;				/*					CT1039   */
		}								/*					ST3249	 */
		else;							/*					ST3249	 */
	}
	
#endif	

	/*****************************************************************/
	/*	03-24-2003  ���� END 										 */
	/*  SCSI�؎��Ď̎ߎێ���������������������			 			 */
	/*****************************************************************/

	
	for (idxp=idx; idxp->mrptbln!=(char *)0; idxp++){
		idxp->mrptbsa = (TCOMPAT **)0;
		idxp->mrprsta = (long *)0;
	}

	idx[TRCTIDX].mrptbsa = &(mrpcbp->mrprcta);		 	     /* TD59 */
	idx[TSSTIDX].mrprsta = &(mrpcbp->mrpsstn);

	/*****************************************************************/
	/*	03-24-2003  ���� START 										 */
	/*  TSUR��TSBR��Ϣ�ν�����������    					 		 */
	/*****************************************************************/

#ifdef LINUX_ISOKUTAIOU

	idx[TSURIDX].mrptbsa = &(mrpcbp->mrpsura);		 	     /* TD61 */

	idx[TSURIDX].mrprsta = &(mrpcbp->mrpsurn);		 	     /* TD61 */
	
	if ( pscparea.pscpuno == pctp->tpctpuno )			/*	CT1039   */
	{									/* mrg��Ʊ��PU�λ�	CT1039   */
		idx[TSBRIDX].mrptbsa = &(mrpcbp->mrpsbra);	 	     /* TD61 */
		idx[TSBRIDX].mrprsta = &(mrpcbp->mrpsbrn);		     /* TD61 */
	}									/*					CT1039   */

#endif
	
	/*****************************************************************/
	/*	03-24-2003  ���� END 										 */
	/*  TSUR��TSBR��Ϣ�ν����������� 					 			 */
	/*****************************************************************/
	
	
	idx[TRCTIDX].mrprsta = &(mrpcbp->mrprctn);		 	     /* TD59 */
	PRINT1("*** mr_ptbl(mrpssta)= 0x%08x  ***\n",idx[TSSTIDX].mrptbsa);
//	PRINT1("*** mr_ptbl(mrpsura)= 0x%08x  ***\n",idx[TSURIDX].mrptbsa);
//	PRINT1("*** mr_ptbl(mrpsbra)= 0x%08x  ***\n",idx[TSBRIDX].mrptbsa);
	PRINT1("*** mr_ptbl(mrprcta)= 0x%08x  ***\n",idx[TRCTIDX].mrptbsa);
	PRINT1("*** mr_ptbl(mrpsstn)= 0x%08x  ***\n",idx[TSSTIDX].mrprsta);
//	PRINT1("*** mr_ptbl(mrpsurn)= 0x%08x  ***\n",idx[TSURIDX].mrprsta);
//	PRINT1("*** mr_ptbl(mrpsbrn)= 0x%08x  ***\n",idx[TSBRIDX].mrprsta);
	PRINT1("*** mr_ptbl(mrprctn)= 0x%08x  ***\n",idx[TRCTIDX].mrprsta);
										/* CT1010					 */

	if (mrpcbp->mrpnsrc == MRPNRNEC){	/* CST�؎��ʎގ� �֎� ���ގ�����?		 */
		idx[TTCTIDX].mrptbsa = &(mrpcbp->mrptcta);
		idx[TJCTIDX].mrptbsa = &(mrpcbp->mrpjcta);
		idx[TRBTIDX].mrptbsa = &(mrpcbp->mrprbta);		     /* TD59 */
		idx[TBKTIDX].mrptbsa = &(mrpcbp->mrpbkta);
		idx[TTCTIDX].mrprsta = &(mrpcbp->mrptctn);
		idx[TTDTIDX].mrprsta = &(mrpcbp->mrptdtn);
	}
										/* �ʎގ��������̎� �֎� ���ގ����� ?		 */
	if (mopcbp->mopscstp->tcstbnui == TCSTBNEC){		    /* (L03) */
		idx[TPBTIDX].mrptbsa = &(mrpcbp->mrppbta);			/* (L03) */
		idx[TVBTIDX].mrptbsa = &(mrpcbp->mrpvbta);			/* (L03) */
		idx[TPBTIDX].mrprsta = &(mrpcbp->mrppbtn);			/* (L03) */
		idx[TVBTIDX].mrprsta = &(mrpcbp->mrpvbtn);			/* (L03) */
	}														/* (L03) */

	/*****************************************************************/
	/*  ADT �֎� ���ގ��Ď� �Î��̎ގ� �� ���ݎ��� ����   					 			 */
	/*****************************************************************/
										/* ���ݎ������َÎ��̎ގَҎ� �Î� �̎؎܎���	 */
	for (idxp=idx; idxp->mrptbln!=(char *)0; idxp++) {
										/* ���ݎ��� ���� �� �Ďގ��� �������� ����	 */
		if (idxp->mrptbsa == (TCOMPAT **)0
		 && idxp->mrprsta == (long *)0){
			continue;
		}
		else;
										/* ADT�֎؎��ގ��Ď��Î��̎ގ� �� �Ў���	 */
		if(idxp->mrpcmlm == CM){							 /* TD59 */
			tadtp = (TADTPSZ *)MRTBLAD(MRCMADT, 1);			 /* TD59 */
			padt = MRCMADT;									 /* TD59 */
			efen = MRCMADT->tcomefen;						 /* TD59 */
		}													 /* TD59 */
		else{												 /* TD59 */
			tadtp = (TADTPSZ *)MRTBLAD(MRLMADT, 1);			 /* TD59 */
			padt = MRLMADT;									 /* TD59 */
			efen = MRLMADT->tcomefen;						 /* TD59 */
		}													 /* TD59 */
		PRINT2(" *  mr_ptbl Sarch TableName = %s  *\n *  mr_ptbl Sarch CM(0) or LM(1) = %d  *\n",
				idxp->mrptbln, idxp->mrpcmlm);

		for (pszno=1; pszno <= efen; tadtp++) {				 /* TD59 */
										/* �Î��̎ގ���Ƭ���Ďގڎ������	 */
			tblp = (TCOMPAT *)((char *)padt + tadtp->tadtadr);
										/* 						TD59 */
										/* �����Î��̎ގ٤ϸ��Ĥ��ä���?	 */
			PRINT1("*** mr_ptbl(tcomtbid)= %s  ***\n",tblp->tcomtbid);
			PRINT1("*** mr_ptbl(mrptbln)= %s  ***\n",idxp->mrptbln);
										/* CT1010					 */
			retcd = mc_ccom(tblp->tcomtbid,
							idxp->mrptbln,
							4L);
			if (retcd == 0L) {
				/*****************************************************/
				/*  �Î��̎ގَ��Ďގڎ�.�����ގݎʎގݎ��ގ� �� �����Î� ����					 */
				/*****************************************************/
				if(idxp->mrptbsa != (TCOMPAT **)0) {
										/* ������������å���ά��	 */
										/* ������ 6��	 		TD@1 */ 
										/* �Î��̎ގَ��Ďގڎ� �� �����Î� ����		 */
					*(idxp->mrptbsa) = tblp;
					PRINT1("**  mr_ptbl Set TableAddress( 0x%x ) in MRPCB  *\n",tblp);
				}
										/* �����ގݎʎގݎ��ގ� �� �������� �� 		 */
										/* 				�����Î� ����		 */
				PRINT1("*** mr_ptbl(mrprsta)= 0x%08x  ***\n",idxp->mrprsta);
										/* CT1010					 */
				if(idxp->mrprsta != (long *)0) {
										/* ������������å���ά��	 */
										/* ������ 6��	 		TD@1 */ 
										/* ���ֹ����		TD00 */	
										/* 				���ꤹ��	 */
					PRINT0("**  mr_ptbl Call mf_rtgt  **\n");
					rstno = mf_rtgt(idxp->mrptbln);		     /* TD@1 */
					if(rstno == MFNOEXIST){		       	     /* TD@1 */
						PRINT0("**  mr_ptbl mf_rtgt  error **\n");
						goto error;			  			     /* TD@1 */
					}			   						     /* TD@1 */
					*(idxp->mrprsta) = rstno;	
					PRINT1("**  mr_ptbl Set SigenNo( 0x%x ) in MRPCB *\n",rstno);
					break;	  							     /* TD@1 */
				}
			}
			else;
			pszno++;
		}
	}

	/*****************************************************************/
	/*  �Î��̎ގ� ���ݎ��ގ� ���׎� �������� 	 						 	   		 */
	/*****************************************************************/
	PRINT0("**  mr_ptbl Table sonnzai check  **\n");
	for(i = 0; idx[i].mrptbln != (char *)0; i++){
										/* �Î��̎ގَ��Ďގڎ���¸�ߎ������� TD@1 */
		if(idx[i].mrptbsa == (TCOMPAT **)0){				 /* TD@1 */	
			continue;										 /* TD@1 */	
		}													 /* TD@1 */	
		else{												 /* TD@1 */	
			if (*(idx[i].mrptbsa)==(TCOMPAT *)0){			
				PRINT1("**  mr_ptbl Tableaddress( %s ) Check Error(0)  **\n",idx[i].mrptbln);
				mc_copy(idx[i].mrptbln,(char *)mrlog,4L);
				mo_wlg4(MR_PTBL,0x33331000L,mrlog,4L);		
										/*						TD50 */
				goto error;							
			}									
			else;							
		}													 /* TD@1 */	
	}				 										 /* TD@1 */	

	PRINT0("**  mr_ptbl SigenNo sonnzai check  **\n");
	for(i = 0; idx[i].mrptbln != (char *)0; i++){
										/* ���ֹ��¸�ߎ������� 	TD@1 */
		if(idx[i].mrprsta == (long *)0){					 /* TD@1 */	
			continue;				 						 /* TD@1 */	
		}				 									 /* TD@1 */	
		else{												 /* TD@1 */	
			if (*(idx[i].mrprsta) == 0L){		
				PRINT1("**  mr_ptbl SigenNo( %s ) Check Error(0)  **\n",idx[i].mrptbln);
				mc_copy(idx[i].mrptbln,(char *)mrlog,4L);
				mo_wlg4(MR_PTBL,0x33331001L,mrlog,4L);	
										/* 						TD50 */
				goto error;							
			}									
			else;							
		}				 									 /* TD@1 */	
	}				 										 /* TD@1 */	
										/* ��ά���Τ���¸�ߎ�����������  */
										/* �ѹ�					TD00 */

	/*****************************************************************/
	/*  �͎ݎ������� �� �����Î� ����											 */
	/*****************************************************************/
										/* MRWLOG��� 3��		TD50 */
	PRINT0("**  mr_ptbl Normal End  **\n");		
	mrlog[0] = MRNORMAL;
	mo_wlg4(MR_PTBL,WOTSC,mrlog,4L);
	return(MRNORMAL);

error:
										/* MRWLOG��� 3��		TD50 */
	PRINT0("**  mr_ptbl Error End  **\n");		
	mrlog[0] = MRTBLERR;
	mo_wlg4(MR_PTBL,WOTSC,mrlog,4L);
	return(MRTBLERR);
}
