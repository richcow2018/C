/****************************************************************************/
/*																			*/
/*					tlic.h													*/
/*																			*/
/*			TLIC �ơ��֥� �ե����ޥå�	 02.12.18	������	���� ��ɧ		*/
/*																			*/
/****************************************************************************/

typedef	struct	mdlicsub{
				short	tlicmaxt;		/* ����ü����						*/
				char	tlicmaxp;		/* ���������ѥ���					*/
				char	tlicdcon;		/* ���ǻ���� 1:ABORT 2:DETACH		*/
				long	tlictcbs;		/*���̥⥸�塼�륳�����ѥХåե�������*/
				long	tlichrtm;		/* �����ĺ��׵�ȯ�Ը�α����Ԥ������� */
}TLICSUB;

typedef	struct	mdlicind{
	unsigned	short	tlicport;		/* ����LICP�ǻ��Ѥ���ݡ����ֹ� 	*/
				short	tliclgno;		/* �����ѥ����롼���ֹ�				*/
				long	tlicpcnt;		/* �����ĺ��׵��ȯ�Կ��ݱ���������	*/
}TLICIND;

