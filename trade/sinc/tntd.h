/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��															*/
/*���оݶ�̳�ɣġ�															*/
/*�㥵���ӥ�����̾��														*/
/*�㥵���ӥ����ܣɣġ�														*/
/*��⥸�塼��̾��					�ԣΣԣĥơ��֥�						*/
/*��⥸�塼��ɣġ�														*/
/*��⥸�塼�����֡�														*/
/*--------------------------------------------------------------------------*/
/*��Ŭ�ѵ����						���ã�									*/
/*��Ŭ�ѣϣӡ�						�ԣң��ģ�								*/
/*�㳫ȯ�Ķ���																*/
/*�㵭�Ҹ����						�ø���									*/
/*��⥸�塼����֡�				��¤��									*/
/*�㵡ǽ��ʬ��																*/
/*���оݥǡ�����															*/
/*�㹩�������ض�ʬ��														*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯ�����ƥ�̾��				���ãšݣӣͣХ����ƥ�					*/
/*�㳫ȯ�����ƥ��ֹ��														*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯô��̾��					�Ķ�Ź�����ƥ�ô��						*/
/*�������ֹ��						169-3537(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/*���߷׼�̾��																*/
/*���߷�ǯ������					������ǯ������							*/
/*���߷׽�����̾��															*/
/*���߷׽���ǯ�����ڤӽ����ɣġ�											*/
/*--------------------------------------------------------------------------*/
/*�㥽����������̾��														*/
/*�㥽��������ǯ������				������ǯ������							*/
/*�㥽����������̾��														*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�											*/
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
/*����ѳ����⥸�塼��ɣġ�												*/
/*��ƽи��Υ⥸�塼��ɣġ�												*/
/****************************************************************************/
 
/****************************************************************************/
/*	�ԣΣԣĥ��ֶ������ե����ޥå�											*/
/****************************************************************************/
typedef struct
{
	short	 tntdtcno;					/* �Σԣ��ֹ�(���Ρ����ֹ�)			*/
	short	 tntdnesu;					/* �ͥåȥ��������				*/
	unsigned short	tntdmsno;			/* �ޥ����������塼���ѣΣԣ�������	*/
	unsigned short	tntdmsmn;			/* �ޥ����Σԣ������ֺǾ���			*/
	unsigned short	tntdmsmx;			/* �ޥ����Σԣ������ֺ�����			*/
	unsigned short	tntdipno;			/* �ɣã��ѣΣԣ�������				*/
	unsigned short	tntdipmn;			/* �ɣãУΣԣ������ֺǾ���			*/
	unsigned short	tntdipmx;			/* �ɣãУΣԣ������ֺ�����			*/
	unsigned short	tntdmrno;			/* ��å���������ѣΣԣ�������		*/
	unsigned short	tntdmrmn;			/* ��å�������ѣΣԣ������ֺǾ���	*/
	unsigned short	tntdmrmx;			/* ��å�������ѣΣԣ������ֺ�����	*/
	short	tntdsyobi;					/* ���ֶ�����ͽ�����ꥢ				*/
}						TNTDSUB;
 
/****************************************************************************/
/*	�ԣΣԣĸ������ե����ޥå�												*/
/****************************************************************************/
typedef struct
{
	short tntdneno;						/* �ͥåȥ�������Σԣ��ֹ�(NODE)	*/
	short tntdnetd;						/* �ͥåȥ����ɽɽ��				*/
}						TNTDPSZ;
