/**********************************************************************/
/*      MEPSCK (�ێݎ؎ʎߎ� ���֎� ���� �������� �ώ���) �͎����ގ̎����� V/R =  0/0 88.03.15  */
/*     ���߷׽�����̾��					�Ķ�Ź�����ƥ�ô��(�Ҏ���:���ю����̎�)*/
/*     ���߷׽���ǯ�����ڤӽ����ɣġ䡡��������ǯ���������     PD04*/
/*                                      �����ʎߎ����Ѳ��ݎ�����������ѹ�   */
/**********************************************************************/
/*	�ţģа���ʸ������Ѷ�ʬ�������ѥ����Ѷ�ʬ��̵���Ǥ����		  */
/*����MENOTUSE�פǸƤӽФ�������������								  */
#define MEPSCK if(mdpsptr->mdpsdsts[1] <= 0l){				  /* PD04*/\
                   MELOG(0X33331099,mdpsptr->mdpsdsts,4l);    /* PD04*/\
                   return(MENOTUSE);\
               }

#define MEPTHCHK(NAME){												   \
			extern void mo_wlg4();									   \
			if(mdpsptr->mdpsdsts[1] == 0){							   \
            	mo_wlg4(NAME,0X33331099,mdpsptr->mdpsdsts,4);		   \
            	return(MENOTUSE);								       \
			}														   \
		}