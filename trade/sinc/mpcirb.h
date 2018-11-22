/****************************************************************************/
/* �ե�����̾����mpcirb.h													*/
/* ��ǽ  ������  �ơ��֥륢�ɥ쥹����										*/
/*				 �ɣҥ����� 												*/
/*				 �⥸�塼��ɣ� 											*/
/*				 �ɣң¥ƥ�ץ졼�� 										*/
/*				 �����ƥॳ����ץ�ȥ����� 								*/
/*				 �����ƥॳ���륢��������Ȱ�ƥ�ץ졼�� 				*/
/*				 �����ƥॳ����ȯ�ԥޥ���									*/
/* ��������  ��  1993.11.24 												*/
/****************************************************************************/
/**************************************/
/* ���٥�ȼ��̻����				  */
/**************************************/
#define E100		0					/* E100:�ԣãС��ɣХ����ץ�λ����*/
#define E101		1					/* E101:�㳲����					*/
#define E102		2					/* E102:��������					*/
#define E103		3					/* E103:���ڤ��ؤ�����				*/
#define E104		4					/* E104:�ѥ��ģţ��ãԴ�λ����		*/
#define E105		5					/* E105:NETCTL(���̎ގȎ��Ďώ���)��λ		*/
#define E106		6					/* E106:NETCTL(IP���Ďގڎ�)��λ 		*/
#define E107		7					/* E107:NETCTL�؎Ď׎����ݎ����ʎގَ����ϴ�λ	*/
#define E108		8					/* E108:NETCTL(�Ȏ��Ď܎����̎׎���)��λ		*/
#define E200		0					/* E200:�����ѥ������ץ��׵�		*/
#define E201		1					/* E201:�����ѥ��������׵�		*/
#define E202		2					/* E202:��ʸ�����׵�				*/
#define E203		3					/* E203:��ʸ�����׵�				*/
#define E204		4					/* E204:�ξ������׵�				*/
#define E205		5					/* E205:�ξ�������׵�				*/
#define E206		6					/* E206:���ãԣɣ֣��׵�			*/
#define E207		7					/* E207:�̣ɣӣԣţ��׵�			*/
#define E208		8					/* E208:���ͥ����������׵�		*/
#define E209		9					/* E209:���ͥ�����󥢥ܡ����׵�	*/
#define E210		10					/* E210:���ץ���������׵�			*/
#define E211		11					/* E211:�۵ޥǡ��������׵�			*/
#define E212		12					/* E212:�۵ޥǡ��������׵�			*/
#define E213		13					/* E213:��������󥻥��׵�			*/
#define E214		14					/* E214:�۵ޥǡ�����������󥻥��׵�*/
#define E215		15					/* E215:���ԣԣ��ãȴ�λ			*/
#define E216		16					/* E216:�£ɣΣĴ�λ				*/
#define E217		17					/* E217:�̣ɣӣԣţδ�λ			*/
#define E218		18					/* E218:��Ʊ�������׵ᴰλ			*/
#define E219		19					/* E219:�ģţԣ��ãȴ�λ			*/
#define E220		20					/* E220:���ããţУԴ�λ			*/
#define E221		21					/* E221:�ѥ����ãԣɣ֣�����		*/
#define E222		22					/* E222:�ѥ��ģţ��ã�����			*/
#define E223		23					/* E223:���Ȏ�������DEACT��λ���� 		*/
#define E300		0					/* E300:�̣ɣӣԣţ��׵�����		*/
#define E301		1					/* E301:���ãԣɣ֣��׵�����		*/
#define E302		2					/* E302:��ʸ�����׵�����			*/
#define E303		3					/* E303:��ʸ�����׵�����			*/
#define E304		4					/* E304:���ͥ����������׵�����	*/
#define E305		5					/* E305:���ͥ�����󥢥ܡ����׵�����*/
#define E306		6					/* E306:�۵ޥǡ�������󥻥��׵�����*/
#define E307		7					/* E307:��ʸ��������󥻥��׵�����	*/
#define E308		8					/* E308:���ץ���������׵�����		*/
#define E309		9					/* E309:�۵ޥǡ��������׵�����		*/
#define E310		10					/* E310:�۵ޥǡ��������׵�����		*/
#define E311		11					/* E311:���ͥ������ģţ��ã�����	*/
#define E312		12					/* E312:�ӣţԣϣУԴ�λ			*/
#define E313		13					/* E313:����������䴰λ		*/
#define E314		14					/* E314:��������䴰λ		*/
#define E315		15					/* E315:�ңã֣ϣϣ´�λ			*/
#define E316		16					/* E316:�ӣţΣģϣϣ´�λ			*/
#define E317		17					/* E317:��Ʊ�������׵ᴰλ			*/
#define E318		18					/* E318:�ģţԣ��ãȴ�λ			*/
#define E319		19					/* E319:���£ϣңԴ�λ				*/
#define E320		20					/* E320:�ģɣӣãϣΣΣţãԴ�λ	*/
#define E321		21					/* E321:�ãϣΣΣţãԴ�λ			*/
#define E322		22					/* E322:DETACH�؎Ď׎������ϴ�λ			*/
/**************************************/
/* Ʊ������IRB��					  */
/**************************************/
#define _NIRB_LCNTL 4					/* ���������ѣɣң¿�				*/
#define _NIRB_PCNTL 5					/* �ѥ������ѣɣң¿�				*/
#define _NIRB_READ	2					/* �����ѣɣң¿�					*/
#define _NIRB_WRIT	2					/* �����ѣɣң¿�					*/
/**************************************/
/* �ɣҥ��������					  */
/**************************************/
/**************************************/
/* �⥸�塼��ɣġʣͣɣġ���� 	  */
/**************************************/
#define _ML_TERMP	0x02				/* �ץ�����λ���� 				*/
#define	_ML_E1		0x10				/* E1??:��������Σģͣɣ�			*/
#define _ML_LOPEN	_ML_E1 + E100		/* E100:�ԣãС��ɣХ����ץ�λ����*/
#define _ML_LFAIL	_ML_E1 + E101		/* E101:�㳲����					*/
#define _ML_LRCOV	_ML_E1 + E102		/* E102:��������					*/
#define _ML_LKISW	_ML_E1 + E103		/* E103:���ڤ��ؤ�����				*/
#define _ML_LDACT	_ML_E1 + E104		/* E104:�ѥ��ģţ��ãԴ�λ����		*/
#define _ML_LSMSK	_ML_E1 + E105		/* E105:NETCTL(���̎ގȎ��Ďώ���)��λ		*/
#define _ML_LSIPA	_ML_E1 + E106		/* E106:NETCTL(IP���Ďގڎ�)��λ 		*/
#define _ML_LNIVT	_ML_E1 + E107		/* E107:NETCTL�؎Ď׎������ϴ�λ			*/
#define _ML_LSFLG	_ML_E1 + E108		/* E105:NETCTL(�Ȏ��Ď܎����̎׎���)��λ		*/
/* RESERVE				0x28...0x1F 										*/
#define	_ML_E2		0x20				/* E2??:�ѥ�����Σģͣɣ�			*/
#define _ML_POPEN	_ML_E2 + E200		/* E200:�����ѥ������ץ��׵�		*/
#define _ML_PCLOS	_ML_E2 + E201		/* E201:�����ѥ��������׵�		*/
#define _ML_PCPUT	_ML_E2 + E202		/* E202:��ʸ�����׵�				*/
#define _ML_PTRED	_ML_E2 + E203		/* E203:��ʸ�����׵�				*/
#define _ML_PFALT	_ML_E2 + E204		/* E204:�ξ������׵�				*/
#define _ML_PRCOV	_ML_E2 + E205		/* E205:�ξ�������׵�				*/
#define _ML_PACTV	_ML_E2 + E206		/* E206:���ãԣɣ֣��׵�			*/
#define _ML_PLIST	_ML_E2 + E207		/* E207:�̣ɣӣԣţ��׵�			*/
#define _ML_PCFRE	_ML_E2 + E208		/* E208:���ͥ����������׵�		*/
#define _ML_PCABT	_ML_E2 + E209		/* E209:���ͥ�����󥢥ܡ����׵�	*/
#define _ML_POPTI	_ML_E2 + E210		/* E210:���ץ���������׵�			*/
#define _ML_PSURG	_ML_E2 + E211		/* E211:�۵ޥǡ��������׵�			*/
#define _ML_PRURG	_ML_E2 + E212		/* E212:�۵ޥǡ��������׵�			*/
#define _ML_PRCAN	_ML_E2 + E213		/* E213:��������󥻥��׵�			*/
#define _ML_POCAN	_ML_E2 + E214		/* E214:�۵ޥǡ�����������󥻥��׵�*/
#define _ML_PATCH	_ML_E2 + E215		/* E215:���ԣԣ��ãȴ�λ			*/
#define _ML_PBIND	_ML_E2 + E216		/* E216:�£ɣΣĴ�λ				*/
#define _ML_PLISN	_ML_E2 + E217		/* E217:�̣ɣӣԣţδ�λ			*/
#define _ML_PASY0	_ML_E2 + E218		/* E218:��Ʊ�������׵ᴰλ			*/
#define _ML_PDECH	_ML_E2 + E219		/* E219:�ģţԣ��ãȴ�λ			*/
#define _ML_PACPT	_ML_E2 + E220		/* E220:���ããţУԴ�λ			*/
#define _ML_PACTP	_ML_E2 + E221		/* E221:�ѥ����ãԣɣ֣�����		*/
#define _ML_PDACP	_ML_E2 + E222		/* E222:�ѥ��ģţ��ã�����			*/
#define _ML_PCDCT	_ML_E2 + E223		/* E223:���Ȏ�������DEACT��λ���� 		*/
/* RESERVE				0x38...0x3F 										*/
#define	_ML_E3		0x40				/* E3??:���ͥ����������Σģͣɣ�	*/
#define _ML_CLIST	_ML_E3 + E300		/* E300:�̣ɣӣԣţ��׵�����		*/
#define _ML_CACTV	_ML_E3 + E301		/* E301:���ãԣɣ֣��׵�����		*/
#define _ML_CCPUT	_ML_E3 + E302		/* E302:��ʸ�����׵�����			*/
#define _ML_CTRED	_ML_E3 + E303		/* E303:��ʸ�����׵�����			*/
#define _ML_CCFRE	_ML_E3 + E304		/* E304:���ͥ����������׵�����	*/
#define _ML_CCABT	_ML_E3 + E305		/* E305:���ͥ�����󥢥ܡ����׵�����*/
#define _ML_COCAN	_ML_E3 + E306		/* E306:�۵ޥǡ�������󥻥��׵�����*/
#define _ML_CRCAN	_ML_E3 + E307		/* E307:��ʸ��������󥻥��׵�����	*/
#define _ML_COPTI	_ML_E3 + E308		/* E308:���ץ���������׵�����		*/
#define _ML_CSURG	_ML_E3 + E309		/* E309:�۵ޥǡ��������׵�����		*/
#define _ML_CRURG	_ML_E3 + E310		/* E310:�۵ޥǡ��������׵�����		*/
#define _ML_CCDEA	_ML_E3 + E311		/* E311:���ͥ������ģţ��ã�����	*/
#define _ML_CSETO	_ML_E3 + E312		/* E312:�ӣţԣϣУԴ�λ			*/
#define _ML_CWRTD	_ML_E3 + E313		/* E313:����������䴰λ		*/
#define _ML_CREAD	_ML_E3 + E314		/* E314:��������䴰λ		*/
#define _ML_CROOB	_ML_E3 + E315		/* E315:�ңã֣ϣϣ´�λ			*/
#define _ML_CSOOB	_ML_E3 + E316		/* E316:�ӣţΣģϣϣ´�λ			*/
#define _ML_CASY1	_ML_E3 + E317		/* E317:��Ʊ�������׵ᴰλ			*/
#define _ML_CDECH	_ML_E3 + E318		/* E318:�ģţԣ��ãȴ�λ			*/
#define _ML_CABOT	_ML_E3 + E319		/* E319:���£ϣңԴ�λ				*/
#define _ML_CDCON	_ML_E3 + E320		/* E320:�ģɣӣãϣΣΣţãԴ�λ	*/
#define _ML_CCONN	_ML_E3 + E321		/* E321:�ãϣΣΣţãԴ�λ			*/
#define _ML_CDTIT	_ML_E3 + E322		/* E322:DETACH�؎Ď׎������ϴ�λ			*/
/**************************************/
/* �ɣҥ��������					  */
/**************************************/
#define _IR_TERMP	MCSTERM 			/* �����ĺ� 						*/
/* RESERVE				0x01...0x01 										*/
#define	_IR_E1		0x10				/* E1??:��������Σɣҥ�����		*/
#define _IR_LOPEN	_IR_E1 + E100		/* E100:�ԣãС��ɣХ����ץ�λ����*/
#define _IR_LFAIL	_IR_E1 + E101		/* E101:�㳲����					*/
#define _IR_LRCOV	_IR_E1 + E102		/* E102:��������					*/
#define _IR_LKISW	_IR_E1 + E103		/* E103:���ڤ��ؤ�����				*/
#define _IR_LDACT	_IR_E1 + E104		/* E104:�ѥ��ģţ��ãԴ�λ����		*/
#define _IR_LSMSK	_IR_E1 + E105		/* E105:NETCTL(���̎ގȎ��Ďώ���)��λ		*/
#define _IR_LSIPA	_IR_E1 + E106		/* E106:NETCTL(IP���Ďގڎ�)��λ 		*/
#define _IR_LSFLG	_IR_E1 + E108		/* E108:NETCTL(�Ȏ��Ď܎����̎׎���)��λ		*/
/* RESERVE				0x17...0x1F 										*/
#define	_IR_E2		0x20				/* E2??:�ѥ�����Σɣҥ�����		*/
#define _IR_POPEN	_IR_E2 + E200		/* E200:�����ѥ������ץ��׵�		*/
#define _IR_PCLOS	_IR_E2 + E201		/* E201:�����ѥ��������׵�		*/
#define _IR_PCPUT	_IR_E2 + E202		/* E202:��ʸ�����׵�				*/
#define _IR_PTRED	_IR_E2 + E203		/* E203:��ʸ�����׵�				*/
#define _IR_PFALT	_IR_E2 + E204		/* E204:�ξ������׵�				*/
#define _IR_PRCOV	_IR_E2 + E205		/* E205:�ξ�������׵�				*/
#define _IR_PACTV	_IR_E2 + E206		/* E206:���ãԣɣ֣��׵�			*/
#define _IR_PLIST	_IR_E2 + E207		/* E207:�̣ɣӣԣţ��׵�			*/
#define _IR_PCFRE	_IR_E2 + E208		/* E208:���ͥ����������׵�		*/
#define _IR_PCABT	_IR_E2 + E209		/* E209:���ͥ�����󥢥ܡ����׵�	*/
#define _IR_POPTI	_IR_E2 + E210		/* E210:���ץ���������׵�			*/
#define _IR_PSURG	_IR_E2 + E211		/* E211:�۵ޥǡ��������׵�			*/
#define _IR_PRURG	_IR_E2 + E212		/* E212:�۵ޥǡ��������׵�			*/
#define _IR_PRCAN	_IR_E2 + E213		/* E213:��������󥻥��׵�			*/
#define _IR_POCAN	_IR_E2 + E214		/* E214:�۵ޥǡ�����������󥻥��׵�*/
#define _IR_PATCH	_IR_E2 + E215		/* E215:���ԣԣ��ãȴ�λ			*/
#define _IR_PBIND	_IR_E2 + E216		/* E216:�£ɣΣĴ�λ				*/
#define _IR_PLISN	_IR_E2 + E217		/* E217:�̣ɣӣԣţδ�λ			*/
#define _IR_PASY0	_IR_E2 + E218		/* E218:��Ʊ�������׵ᴰλ			*/
#define _IR_PDECH	_IR_E2 + E219		/* E219:�ģţԣ��ãȴ�λ			*/
#define _IR_PACPT	_IR_E2 + E220		/* E220:���ããţУԴ�λ			*/
#define _IR_PACTP	_IR_E2 + E221		/* E221:�ѥ����ãԣɣ֣�����		*/
#define _IR_PDACP	_IR_E2 + E222		/* E222:�ѥ��ģţ��ã�����			*/
#define _IR_PCDCT	_IR_E2 + E223		/* E223:���Ȏ�������DEACT��λ���� 		*/
/* RESERVE				0x38...0x3F 										*/
#define	_IR_E3		0x40				/* E3??:���ͥ����������Σɣҥ�����*/
#define _IR_CLIST	_IR_E3 + E300		/* E300:�̣ɣӣԣţ��׵�����		*/
#define _IR_CACTV	_IR_E3 + E301		/* E301:���ãԣɣ֣��׵�����		*/
#define _IR_CCPUT	_IR_E3 + E302		/* E302:��ʸ�����׵�����			*/
#define _IR_CTRED	_IR_E3 + E303		/* E303:��ʸ�����׵�����			*/
#define _IR_CCFRE	_IR_E3 + E304		/* E304:���ͥ����������׵�����	*/
#define _IR_CCABT	_IR_E3 + E305		/* E305:���ͥ�����󥢥ܡ����׵�����*/
#define _IR_COCAN	_IR_E3 + E306		/* E306:�۵ޥǡ�������󥻥��׵�����*/
#define _IR_CRCAN	_IR_E3 + E307		/* E307:��ʸ��������󥻥��׵�����	*/
#define _IR_COPTI	_IR_E3 + E308		/* E308:���ץ���������׵�����		*/
#define _IR_CSURG	_IR_E3 + E309		/* E309:�۵ޥǡ��������׵�����		*/
#define _IR_CRURG	_IR_E3 + E310		/* E310:�۵ޥǡ��������׵�����		*/
#define _IR_CCDEA	_IR_E3 + E311		/* E311:���ͥ������ģţ��ã�����	*/
#define _IR_CSETO	_IR_E3 + E312		/* E312:�ӣţԣϣУԴ�λ			*/
#define _IR_CWRTD	_IR_E3 + E313		/* E313:����������䴰λ		*/
#define _IR_CREAD	_IR_E3 + E314		/* E314:��������䴰λ		*/
#define _IR_CROOB	_IR_E3 + E315		/* E315:�ңã֣ϣϣ´�λ			*/
#define _IR_CSOOB	_IR_E3 + E316		/* E316:�ӣţΣģϣϣ´�λ			*/
#define _IR_CASY1	_IR_E3 + E317		/* E317:��Ʊ�������׵ᴰλ			*/
#define _IR_CDECH	_IR_E3 + E318		/* E318:�ģţԣ��ãȴ�λ			*/
#define _IR_CABOT	_IR_E3 + E319		/* E319:���£ϣңԴ�λ				*/
#define _IR_CDCON	_IR_E3 + E320		/* E320:�ģɣӣãϣΣΣţãԴ�λ	*/
#define _IR_CCONN	_IR_E3 + E321		/* E321:�ãϣΣΣţãԴ�λ			*/
/**************************************/
/* ���֣ɣҥ��������				  */
/**************************************/
#define _SIR_NULL	0x00				/* ���֣ɣҥ����ɤ���Ѥ��ʤ�		*/
#define _SIR_XONL	0x01				/* ����ƥ����ȤΤ߲��� 			*/
#define _SIR_LONL	0x02				/* �����륻�å����Τ߲���		*/
#define _SIR_XADL	0x03				/* �ێ����َ��������ݤ���ӎ��ݎÎ����Ĳ���		*/
#define _SIR_OPEN	0x00				/* �����ץ�Ѥ�						*/
#define _SIR_HALT	0x01				/* �����ģţ��ã���					*/
#define _SIR_CLOS	0x02				/* ��������						*/

/**************************************/
/* �ɣң¥ƥ�ץ졼�ȡ����Σɣң¡�   */
/**************************************/
typedef struct {
	long				ih_qlink[2];	/* �ɣң¥إå������塼���		*/
	char				ih_bytp;		/* �ɣң¥إå����£٣ԣ�			*/
	char				ih_gmid;		/* �ɣң¥إå����ǣͣɣ�			*/
	char				ih_dmid;		/* �ɣң¥إå����ģͣɣ�			*/
	char				ih_omid;		/* �ɣң¥إå����ϣͣɣ�			*/
	char				ih_ircd;		/* �ɣң¥إå����ɣҥ����� 		*/
	char				ih_subcd;		/* �ɣң¥إå������֣ɣҥ����� 	*/
	short				ih_cond;		/* �ɣң¥إå�����λ������ 		*/
	long				ctxtp;			/* ����ƥ����ȥ��ɥ쥹   ��		*/
	long				msglen; 		/* ������ʸĹ						*/
	long				msgp;			/* ������å������ݥ���			*/
	long				reserve;		/* ͽ�� 							*/
	long				irblinkp;		/* �ɣң¥�󥯥��ɥ쥹 			*/
	long				srctxtp;		/* ȯ��������ƥ����ȥ��ɥ쥹		*/
	short				lsno;			/* �̣��ֹ� 						*/
	short				deactsts;		/* �㳲�װ� 						*/
	long				ripaddr;		/* ��⡼�ȥ��󥿥ͥåȥ��ɥ쥹 	*/
	short				rportno;		/* ��⡼�ȥݡ����ֹ�				*/
	short				yobi0;			/* ͽ���ʣģ��ǣ��ã����		*/
	long				yobi1[3];		/* ͽ���ʣģ��ǣ��ã����		*/
}	MPCIRB0;
/**************************************/
/* �ɣң¥ƥ�ץ졼�ȡʴ�λ�ɣң¡�   */
/**************************************/
typedef struct {
	long				ih_qlink[2];	/* �ɣң¥إå������塼���		*/
	char				ih_bytp;		/* �ɣң¥إå����£٣ԣ�			*/
	char				ih_gmid;		/* �ɣң¥إå����ǣͣɣ�			*/
	char				ih_dmid;		/* �ɣң¥إå����ģͣɣ�			*/
	char				ih_omid;		/* �ɣң¥إå����ϣͣɣ�			*/
	char				ih_ircd;		/* �ɣң¥إå����ɣҥ����� 		*/
	char				ih_subcd;		/* �ɣң¥إå������֣ɣҥ����� 	*/
	short				ih_cond;		/* �ɣң¥إå�����λ������ 		*/
	long				ctxtp;			/* ����ƥ����ȥ��ɥ쥹   ��		*/
	long				result; 		/* �ꥶ�����						*/
	long				reserve;		/* ͽ�� 							*/
	long				rd; 			/* �����							*/
	long				irblinkp;		/* �ɣң¥�󥯥��ɥ쥹 			*/
	long				argarea[7]; 	/* �����ƥॳ���륢��������Ȱ�	*/
}	MPCIRB1;

