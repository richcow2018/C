/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��					��ž������̳							*/
/*���оݶ�̳�ɣġ�															*/
/*�㥵���ӥ�����̾��														*/
/*�㥵���ӥ����ܣɣġ�														*/
/*��⥸�塼��̾��					�ԣ̣ͣԥơ��֥�						*/
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
/*�㥽��������ǯ�����ڤӽ����ɣġ�	��������ǯ�������	ST4325 			*/
/* �㥽����������̾��				 �ˣӣСʳ��ˡ�����������				*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������			ST4970	*/
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
/*		�ãͥơ��֥�Ǥ��롣												*/
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
/*	�ԣ̣ͣԸ�����															*/
/****************************************************************************/
struct  tlmtpsz {
    char  tlmtpuno;                     /* �У��ֹ�							*/
    char  tlmtstat;                     /* Ÿ������							*/
    short tlmtsize;                     /* ���ꥵ�����ʣΣ֣͡�			*/
    long  tlmtlmid;                     /* ���ѥ��꼱�̻�					*/
    long  tlmtlmad;                     /* ���ѥ�����Ƭ���ɥ쥹			*/
    char  tlmtmdrn[32];                 /* �̣ͥơ��֥�ե����������		*/
										/* �ޥ���ȸ�						*/
										/* �����ü�ե�����̾ ST4325		*/
    char  tlmtmvnm[32];                 /* �̣ͥơ��֥�ե����������		*/
										/* �ޥ������						*/
										/*	�ޥ���ȥǥ��쥯�ȥ�̾ ST4325	*/
    char  tlmtmfnm[32];                 /* �̣ͥơ��֥�ե����������		*/
										/*	�ե�ѥ�̾	ST4325				*/
	char  tlmtxsts;						/* �ơ��֥�ե�����(��)���ơ�����	*/
	char  tlmtyob1[3];					/* SCSI�ꥻ�åȾ���(��)ST4970 start	*/
										/* [0] ���ּ���						*/
										/* [1] �����ü�ե�����У��ֹ�		*/
										/* [2] SCSI����ȥ����� SCSI ID		*/
										/*					ST4970 end		*/
    char  tlmtsdrn[32];                 /* �̣ͥơ��֥�ե����������		*/
										/* �ޥ���ȸ�						*/
										/*	�����ü�ե�����̾ ST4325		*/
    char  tlmtsvnm[32];                 /* �̣ͥơ��֥�ե����������		*/
										/* �ޥ������						*/
										/*	�ޥ���ȥǥ��쥯�ȥ�̾ ST4325	*/
    char  tlmtsfnm[32];                 /* �̣ͥơ��֥�ե����������		*/
										/*	�ե�ѥ�̾	ST4325				*/
	char  tlmtysts;						/* �ơ��֥�ե�����(��)���ơ�����	*/
	char  tlmtyob2[3];					/* SCSI�ꥻ�åȾ���(��)ST4970 start	*/
										/* [0] ���ּ���						*/
										/* [1] �����ü�ե�����У��ֹ�		*/
										/* [2] SCSI����ȥ����� SCSI ID		*/
										/*					ST4970 end		*/
};
typedef  struct  tlmtpsz  TLMTPSZ;
 
/****************************************************************************/
/*	Ÿ������(tlmtstat)														*/
/****************************************************************************/
#define  TLMTNOEX  0x00                 /* ̤Ÿ��							*/
#define  TLMTEXST  0x01                 /* Ÿ���Ѥ�							*/
/****************************************************************************/
/*	�У��ֹ�(tlmtpuno)														*/
/****************************************************************************/
#define  TLMTNVM   0x7F                 /* �Σ֣�Ÿ������					*/
/****************************************************************************/
/*	�ơ��֥�ե����륹�ơ�����(tlmtxsts, tlmtysts)							*/
/****************************************************************************/
#define	 TLMTOK	'O'						/*	����							*/
#define	 TLMTNG	'N'						/*	�۾�							*/