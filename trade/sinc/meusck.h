/**********************************************************************/
/*      MEUSCK (EDP���֎� ���� �������� �ώ���)  �͎����� �̎�����  V/R =  0/0  88.01.08  */
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(�Ҏ���:���ю����̎�)*/
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������     PD03*/
/*                                      EDP���Ѳ��ݎ�����������ѹ�		  */
/*																	  */
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(��ƣͳ��)  */
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������      M01*/
/*		�ξ����ɼ��ȯ�Ը������ֹ桧ST4026)							  */
/*		��ʸ�����ʬ�ˡ�[edp����â��me_cget()�ϻ����Բ�]0x03���ɲ�    */
/**********************************************************************/
/*	�ţģа�ݥ����ͤ��������뤤�ϣţģа���ʸ������Ѷ�ʬ��̵����  */
/*  �����MENOTUSE�פǸƤӽФ�������������							  */

#define MEEBLEDP	0x02			/* ��ʸ�����ʬ��EDP���Ѳġ� PD03 */
#define MEEBLEDP2	0x03			/*  "  ��EDP����(cget�ʳ�)��   M01*/

#define MEUSCK if(((long)mdpsptr <= 0l) || 				  /* PD03  M01*/\
				  ((mdpsptr->mdpsdsts[0] != MEEBLEDP) &&				\
				   (mdpsptr->mdpsdsts[0] != MEEBLEDP2)) ){/* PD03  M01*/\
                   MELOG(0X33331098,&mdpsptr,4l)\
                   return(MENOTUSE);\
               }

/* [EDP���Ѳġ�â��cget()�ʳ� */
#define MEUSCK2 if(((long)mdpsptr <= 0l) || 			   /*     M01*/\
				   (mdpsptr->mdpsdsts[0] != MEEBLEDP) ){   /*     M01*/\
                   MELOG(0X33331098,&mdpsptr,4l)\
                   return(MENOTUSE);\
               }

#define MEUSECHK(NAME){										   			\
			extern void mo_wlg4();										\
			if( ((long)mdpsptr <= 0) ||									\
				(mdpsptr->mdpsdsts[0] != MEEBLEDP) &&		/*     M01*/\
				(mdpsptr->mdpsdsts[0] != MEEBLEDP2) ){ 		/* 	   M01*/\
				mo_wlg4(NAME,0x33331098,&mdpsptr,4);					\
				return(MENOTUSE);										\
			}															\
		}
