/******************< mpcomand.h >********************************************/
/*	�ǡ���̾ : �֎������� / �����Ď� ���ώݎĎ� �؎������� 									*/
/*	������ : �֎������� / �����Ď� ���ώݎĎ� �؎������� �������ގ����� �Î����� �Î�����					*/
/*	������	 : 1993.11.22													*/
/****************************************************************************/
/*	���� : ��������ǯ��������� �Ķ�Ź�����Î�ô�� ���� ST4606				*/
/*				�׵Ꮊ�ώݎĎޤˎ�AP�׵ἱ���ֹ掣�ɲ�								*/
/****************************************************************************/
/**************************************/
/* �׵᡿������ʸ���ޥ�ɰ� 		  */
/**************************************/
struct mpcomand{						/*									*/
	char  	 		mpcococd ;			/* ���ޥ�ɥ����� 					*/
	char   			mpcokan1 ;			/* ��λ������						*/
	short 			mpcokan2 ;			/* �۾��װ� 						*/
	char   			mpcotype ;			/* ������							*/
	char   			mpcoapcd ;			/* AP�׵ἱ���ֹ�					*/
										/* ST4606 ͽ��1���ѹ�				*/
	char   			mpcocanc ;			/* ����󥻥륳�ޥ�ɥ����� 		*/
	char   			mpcocant ;			/* ����󥻥륿���� 				*/
	long   			mpcocnnd ;			/* ���ͥ�������̻�				*/
	long   			mpcolipa ;			/* �����륤�󥿡��ͥåȥ��ɥ쥹	*/
	long   			mpcoripa ;			/* ��⡼�ȥ��󥿡��ͥåȥ��ɥ쥹	*/
	short  			mpcolpon ;			/* ������ݡ����ֹ�				*/
	short  			mpcorpon ;			/* ��⡼�ȥݡ����ֹ�				*/
	long   			mpcodatp ;			/* �ǡ�����Ǽ�襢�ɥ쥹��			*/
	short  			mpcodtsz ;			/* �ǡ���Ĺ 						*/
	char   			mpcopthf ;			/* ���ͥ��������� 				*/
	char   			mpcoyob2 ;			/* ͽ����							*/
	char   			mpcooptk ;			/* ���ץ�������					*/
	char   			mpcooptf ;			/* ���ץ�������ե饰 			*/
	unsigned short  mpcooptv ;			/* ���ץ��������� 				*/
	long   			mpcotsp1 ;			/* �ԣӣл��Ѱ裱					*/
	long   			mpcotsp2 ;			/* �ԣӣл��Ѱ裲�� 				*/
	long   			mpcotsp3 ;			/* �ԣӣл��Ѱ裳					*/
};										/*									*/
typedef struct mpcomand MPCOMAND ;		/*									*/

/**************************************/
/* ��ʸ������						  */
/**************************************/
#define  MPCMSIZE	sizeof(MPCOMAND)	/* �׵ᥳ�ޥ�ɰ襵���� 			*/
#define  MPRCMSZ1	sizeof(MPCOMAND)	/* �������ޥ�ɰ襵���� 			*/

/**************************************/
/* ���ޥ�ɥ�����					  */
/**************************************/
#define   CMDCOPN	 0x01				/* me_copn							*/
#define   CMDCCLS	 0x02				/* me_ccls							*/
#define   CMDTRED	 0x03				/* me_tred							*/
#define   CMDCPUT	 0x04				/* me_cput							*/
#define   CMDTCNT	 0x05				/* me_tcnt							*/
#define   CMDTCAN	 0x06				/* me_tcan							*/


/**************************************/
/* ���ޥ�ɥ�����					  */
/**************************************/
#define   TYPTKOSY	  0x01				/* �ξ������׵� 					*/
#define   TYPTRCOV	  0x02				/* �ξ�����Ԥ��׵� 				*/
#define   TYPTACTV	  0x03				/* ���ãԣɣ֣��׵� 				*/
#define   TYPTLIST	  0x04				/* �̣ɣӣԣţ��׵� 				*/
#define   TYPTDCNN	  0x05				/* ���ͥ����������׵� 			*/
#define   TYPTABOT	  0x06				/* ���ͥ�����󥢥ܡ����׵� 		*/
#define   TYPTSOPT	  0x07				/* ���ץ���������׵�				*/
#define   TYPTSOOB	  0x08				/* �۵ޥǡ��������׵�				*/
#define   TYPTROOB	  0x09				/* �۵ޥǡ��������׵�				*/

/**************************************/
/* ���ץ�������					  */
/**************************************/
#define   SOKEEPAL	   0x03 			/* ���ͥ��������¸���ץ����		*/
#define   SODNTRTE	   0x04 			/* ��ϩ���򥪥ץ����				*/
#define   SOLINGER	   0x07 			/* ��󥬡����ץ����				*/
#define   SOOOBINL	   0x08 			/* �۵ޥǡ������ץ���� 			*/
#define   SOSNDBUF	   0x09 			/* �����Хåե����ץ����			*/
#define   SORCVBUF	   0x0a 			/* �����Хåե����ץ����			*/
/**************************************/
/* ���ץ�������					  */
/**************************************/
#define   SOPTFLG	   0x01 			/* ���ץ�������꡿����ե饰		*/

/**************************************/
/* ���ͥ��������� 				  */
/**************************************/
#define   FLGRVFIN	   0x01 			/* ����¦�Υ���åȥ�����ʣƣɣμ� */
										/* ���ˤ򸡽Ф��ޤ���				*/
/**************************************/
/* �۾��װ� 						  */
/**************************************/
#define   ERRNORML	0x0000				/* ���ｪλ							*/

#define   ERRPHARD	0x0101				/* �ϡݥɸξ�						*/
#define   ERRPKIRI	0x010C				/* ���ڤ��ؤ�						*/
#define   ERRPWAIT	0x010D				/* �Ե���							*/

#define   ERRLNCNN	0x0332				/* �������ͥ������ʤ� 			*/
#define   ERRLREFU	0x0333				/* ���ͥ����������꤬���ݤ��줿	*/
#define   ERRLAUSE	0x0334				/* ���ɥ쥹�ϴ��˻��Ѥ���Ƥ��� 	*/
#define   ERRLANAV	0x0335				/* ���ɥ쥹�λ��Ѥ��Բ�ǽ			*/
#define   ERRLNDWN	0x0336				/* �ͥåȥ���������� 			*/
#define   ERRLNURH	0x0337				/* �ͥåȥ���ؤ���ã�Բ�ǽ		*/
#define   ERRLHURH	0x0338				/* �ۥ��Ȥ���ã�Բ�ǽ				*/
#define   ERRLSHDN	0x0339				/* ���ˎ��Ȏ������ݤώ������Ď��ގ��ݺѤ� 		*/
#define   ERRLTOUT	0x033A				/* ���ͥ������Υ����ॢ����ȯ��	*/
#define   ERRLCABT	0x033B				/* ���ͥ�����󤬥��ܡ��Ȥ���		*/
#define   ERRLCRST	0x033C				/* ���ͥ�����󤬥ꥻ�åȤ��줿 	*/
#define   ERRLNPTH	0x033d				/* ���������ѥ��ʤ��ʎʎߎ׎Ҏ������׎���	*/

#define   ERRINTOP	0x0502				/* ̤�����ץ�						*/
#define   ERRINOPN	0x0503				/* ���ݥץ������					*/
#define   ERRICLOS	0x0504				/* ����ݥ�������					*/
#define   ERRIOPEN	0x0505				/* ���ݥץ��						*/
#define   ERRIPARM	0x0506				/* �ѥ��ݥ������ 				*/
#define   ERRIDUPR	0x0507				/* ���ȯ�ԥ��顼					*/
#define   ERRILNUM	0x0530				/* �������� 						*/
#define   ERRIFREE	0x0540				/* ���ͥ���������������			*/
#define   ERRIABOT	0x0541				/* ���ͥ�����󥢥ܡ��Ƚ�����		*/
#define   ERRICLWT	0x0542				/* �������Ԥ� 					*/
#define   ERRINACT	0x0544				/* ���ãԣɣ֣��׵�����Բ� 		*/
#define   ERRINLST	0x0545				/* �̣ɣӣԣţ��׵�����Բ� 		*/
#define   ERRINOPT	0x0546				/* ���ץ���������Բ�				*/
#define   ERRINROB	0x0547				/* �۵ޥǡ��������Բ�				*/
#define   ERRIECMD	0x0548				/* ���ޥ�ɥ��顼�ʎʎߎ׎Ҏ������׎���		*/

#define   ERRRCANC	0x0601				/* ����󥻥�ˤ���� 			*/
#define   ERRRFREE	0x0610				/* ���ͥ����������׵�ˤ����	*/
#define   ERRRABOT	0x0611				/* ���Ȏ������ݎ��Ύގ����׵�ˤ����		*/

#define   ERRNGCAN	0x0613				/* ����󥻥뼺��					*/

#define   ERRKPCKG	0x0F02				/* �ѥå��ݥ�̤���� 				*/
#define   ERRKBUFF	0x0F04				/* �ϣӻ���­ 					*/
#define   ERRKSDOV	0x0F05				/* �����׵�����ݥС�				*/
#define   ERRKRVOV	0x0F06				/* �����׵�����ݥС�				*/
#define   ERRKLSTN	0x0F07				/* �̣ɣӣԣţ��׵�������С�		*/
