/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��					��ž������̳							*/
/*���оݶ�̳�ɣġ�															*/
/*�㥵���ӥ�����̾��														*/
/*�㥵���ӥ����ܣɣġ�														*/
/*��⥸�塼��̾��					�ԣ��£Хơ��֥�						*/
/*��⥸�塼��ɣġ�														*/
/*��⥸�塼�����֡�														*/
/*--------------------------------------------------------------------------*/
/*��Ŭ�ѵ����						���ã�									*/
/*��Ŭ�ѣϣӡ�						�ԣң��ģ�								*/
/*�㳫ȯ�Ķ���						�ӣգΡ��ӣУ��ңáݣɣУ�				*/
/*�㵭�Ҹ����						�ø���									*/
/*��⥸�塼����֡�				��¤��									*/
/*�㵡ǽ��ʬ��																*/
/*���оݥǡ�����															*/
/*�㹩�������ض�ʬ��														*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯ�����ƥ�̾��				���ãšݣӣͣХ����ƥ�					*/
/*�㳫ȯ�����ƥ��ֹ��				������������������������				*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯô��̾��					�Ķ�Ź�����ƥ�ô��						*/
/*�������ֹ��						169-3537(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/*���߷׼�̾��						�ԣģá����͡��층						*/
/*���߷�ǯ������					��������ǯ���������					*/
/*���߷׽�����̾��															*/
/*���߷׽���ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/*�㥽����������̾��				�ԣģá���������						*/
/*�㥽��������ǯ������				��������ǯ���������					*/
/*�㥽����������̾��				�ӣͣС����ܡ�����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ���������	     M05		*/
/*	�ʎ̎ߎ��َʎގ��̎�����ٻ��Υ�å��������� �����ѹ��׵�� SSCY0014�ˡ�			*/
/*�㥽����������̾��				�ӣͣС����ܡ�����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ���������	  st1729		*/
/*	    �ʎ̎ߎ��َʎގ��̎������ԲĻ��Ύ������ގ����̎߾�����ꡡ�ξ����ɼ st1729 )  		*/
/*--------------------------------------------------------------------------*/
/*�㸫�ѥ��ƥåס�															*/
/*--------------------------------------------------------------------------*/
/*�㵡ǽ���ס�																*/
/*--------------------------------------------------------------------------*/
/*��ƽз�����																*/
/*�㲾������																*/
/*���ֵ��͡�																*/
/*--------------------------------------------------------------------------*/
/*�������ϥǡ�����¤��														*/
/*�����»����																*/
/*		�̣ͥơ��֥�Ǥ��롣												*/
/*		�ԣ֣ãԤΥ��ơ������ϰʲ����̤�Ǥ��롣							*/
/*			���ӣͣС����Фν�°			�ӣͣХơ��֥�					*/
/*			���ң£ɼ������ס���			����							*/
/*			�����ȡ�����					�����ơ��֥�					*/
/*			����¾���ס���					��¾����						*/
/*			����������¾��������¾			�ʰ�̣�ʤ���					*/
/*			���ʣΣ̼���ñ�̸�����������	�ʰ�̣�ʤ���					*/
/*����ѳ����⥸�塼��ɣġ�												*/
/*��ƽи��Υ⥸�塼��ɣġ�												*/
/****************************************************************************/
/****************************************************************************/
/*	�ԣ��£Х��ֶ�����														*/
/****************************************************************************/
struct  tabpsub {
	short tabptls;						/* �ȥ�ե��å����³�����			*/
	short tabptle;						/* �ȥ�ե��å����²����			*/
	long  tabprtt;						/* ��ȥ饤�ֳ�						*/
	short tabprtn;						/* ��ȥ饤���						*/
	char  tabpyob[2];					/* ͽ��								*/
	char  tabpcinf;						/* �ãͼ�����̤����					*/
	char  tabpyob2[3];					/* ͽ��								*/
};
typedef  struct  tabpsub  TABPSUB;
/****************************************************************************/
/*	�ԣ��£и�����															*/
/****************************************************************************/
struct  tabppsz {
	long  tabppid;                      /* �Хåե��ס��뼱�̻�				*/
	long  tabpbsz;                      /* �Хåե�������					*/
	long  tabpbno;                      /* �Хåե��θĿ�					*/
	char  tabpmet;                      /* �������						*/
	char  tabppno;                      /* �У��ֹ�							*/
	char  tabptflg;						/* �ȥ�ե��å����¼»ܥե饰		*/
	char  tabpmsf;						/* ������������³��ե饰	  M05  */
	short tabpupno;						/* �������ގ����߲̎��  st1729				*/
	short tabppyob;						/* ͽ��	��st1729					*/
};
typedef  struct  tabppsz  TABPPSZ;

/****************************************************************************/
/*	�������(tabpmet)														*/
/****************************************************************************/
#define  TABPLM 'L'                     /* �����������					*/
#define  TABPCM 'C'                     /* ��������						*/

/****************************************************************************/
/*	�ȥ�ե��å����¼»ܥե饰(tabptflg)									*/
/****************************************************************************/
#define	 TABPON		1L					/* TD10	�ȥ�ե��å����¼»�		*/
#define	 TABPOFF	0L					/* TD10	�ȥ�ե��å����²��		*/
