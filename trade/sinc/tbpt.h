/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��					��ž������̳							*/
/*���оݶ�̳�ɣġ�															*/
/*�㥵���ӥ�����̾��														*/
/*�㥵���ӥ����ܣɣġ�														*/
/*��⥸�塼��̾��					�ԣ£Уԥơ��֥�						*/
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
/*���߷׽�����̾��															*/
/*--------------------------------------------------------------------------*/
/*�㥽����������̾��				�ԣģá���������						*/
/*�㥽��������ǯ������				��������ǯ���������					*/
/*�㥽����������̾��				�ӣͣС����ܡ�����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ���������	     M05		*/
/*	    �ʎ̎ߎ��َʎގ��̎�����ٻ��Υ�å���������  �����ѹ��׵�� SSCY0014��  	*/
/*�㥽����������̾��				�ӣͣС����ܡ�����						*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ���������	     st1729		*/
/*	    �ʎ̎ߎ��َʎގ��̎������ԲĻ��Ύ������ގ����̎߾�����ꡡ�ξ����ɼ st1729 )  		*/
/*�㥽����������̾��				�ԣģá����桡����			 TDN9		*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ���������					*/
/*      �ʥХåե��ס���ɣ����֣ӣǲ���ȼ���ѹ���							*/
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
/*	�ԣ£Уԥ��ֶ�����														*/
/****************************************************************************/
struct  tbptsub {
	short tbpttls;						/* �ȥ�ե��å����³�����			*/
	short tbpttle;						/* �ȥ�ե��å����²����			*/
	long  tbptrtt;						/* ��ȥ饤�ֳ�						*/
	short tbptrtn;						/* ��ȥ饤���						*/
	short tbptlpid;						/* �̣��ѥХåե��ס������ɣ� TDN9*/
	char  tbptcinf;						/* �ãͼ�����̤����					*/
	char  tbptyob2[3];					/* ͽ��								*/
};
typedef  struct  tbptsub  TBPTSUB;
/****************************************************************************/
/*	�ԣ£УԸ�����															*/
/****************************************************************************/
struct  tbptpsz {
	long  tbptpid;                      /* �Хåե��ס��뼱�̻�				*/
	long  tbptbsz;                      /* �Хåե�������					*/
	long  tbptbno;                      /* �Хåե��θĿ�					*/
	char  tbptmet;                      /* �������						*/
	char  tbptpno;                      /* �У��ֹ�							*/
	char  tbpttflg;						/* �ȥ�ե��å����¼»ܥե饰		*/
	char  tbptmsf;						/* ������������³��ե饰	  M05   */
	short tbptupno;						/* �������ގ����߲̎��  st1729 			*/
	short tbptpyob;						/* ͽ��	��st1729					*/
};
typedef  struct  tbptpsz  TBPTPSZ;

/****************************************************************************/
/*	�������(tbptmet)														*/
/****************************************************************************/
#define  TBPTLM 'L'                     /* �����������					*/
#define  TBPTCM 'C'                     /* ��������						*/