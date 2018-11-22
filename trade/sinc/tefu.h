/****************************************************************************/
/*  �������������                                                        */
/*            �Σԣԥǡ����̿��������                                      */
/*              ��ͻ�����ƥ��������                                        */
/*                                                                          */
/*                                                                          */
/*  ����ʪ  ���ãšݣӣͣХ����ƥ�                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*        ���ãšݣӣͣС��ƣԣ���  �ӣǥǡݥ��ơ��֥빽¤�����            */
/*                                                                          */
/*                                                                          */
/*          <tefu.h>                       FTAM�̎ߎێ��ގ׎� SG�Îގ����Î��̎ގٹ�¤�����*/
/*                                                                          */
/*                                                                          */
/*��������ɣġ�ǯ��������̾��                                              */
/*  <     > : ��������ǯ���������        ���ıѹ�                        */
/*�㽤�����ɣġ�ǯ��������̾��                                              */
/*  <FJ003> : ��������ǯ���������        ���ıѹ�                        */
/*            �������ѹ����ã֣ϣӥ��٥���ɲ�                              */
/*            �������ѹ���ưŪ�����ƥ��ѹ��н�                              */
/*--------------------------------------------------------------------------*/
/*  95.06.05 K.Kubota SSCY0057: F_DATA��������������������ɲ�              */
/*                                                                          */
/*                                                                          */
/****************************************************************************/


/****************************************************************************/
/*********************************** �ģţƣɣΣ��� *************************/
/* teft.h��Ʊ����include����Ȥ����ܥե������������֤��뤳�� (K.Kubota)	*/
/****************************************************************************/
#ifndef MLHCCLEN						/* SSCY0057 Start					*/
	#define MLHCCLEN	16				/* �̿�����̾���؎�Ĺ��				*/
	#define MLHCFLEN	64				/* ���̿�����̾�̎����َ��؎�Ĺ��			*/
	#define MLHEXADL	20				/* ��ĥ���ɥ쥹���؎�Ĺ��				*/
	#define MLHEXMAX	40				/* ��ĥ���ɥ쥹����Ĺ��		<FJ003>	*/
	#define MLH_PRCNL	8				/* �ץ�������̾Ĺ��				*/
	#define MLHFSAPL	16				/* �ƣӣ��Сݣɣ�Ĺ��				*/
	#define MLHTSAPL	32				/* �ƣӣ��Сݣɣ�Ĺ��				*/
	#define MLH_ADLN	8				/* ���ɥ쥹Ĺ��						*/
	#define MLH_PSLL	4				/* �̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��				*/
#endif									/* SSCY0057 End						*/

/****************************************************************************/
/*********************************** ��¤�Ρ���� ***************************/
/****************************************************************************/

/****************************************************************************/
/*  �ԣţƣե��ֶ�������¤����                                              */
/****************************************************************************/
struct	tefusub							/* �ԣţƣե��ֶ�������¤			*/
{
										/********* �ɣң´�Ϣ������ *********/
	unsigned short	tefuirbs ;			/* ����ɣң¿�						*/
	unsigned short	tefukafu ;			/* �ɣң²���ٰܹԿ�				*/
	unsigned short	tefukaij ;			/* �ɣң²���ٲ����				*/
										/******** ���ܡ��Ȱ����Ѥ����� ******/
	unsigned short	tefuoprq ;			/* FSAP��Ͽ�׵�ȯ�Կ�				*/
	unsigned short	tefuoprs ;			/* FSAP��Ͽ�����ǧ������			*/
	unsigned short	tefuclrq ;			/* FSAP����׵�ȯ�Կ�				*/
	unsigned short	tefuclrs ;			/* FSAP��������ǧ������			*/
	unsigned short	tefufspn ;			/* FSAP�ֹ� 						*/
										/***** RALLY ������� �����Ўݎ���Ĵ�� ****/
	short			tefurcnt ;			/* rvinit�؎Ď׎������					*/
	short			tefurtms ;			/* rvinit NG ��(�؎Ď׎��Ԥ�������)		*/
										/******* ACE-SMP��FTAM �ӣ��� ********/
	unsigned short	tefufmax ;			/* �ƣú�����						*/
	unsigned short	tefursno ;			/* ����¦�ƣÿ�						*/
	unsigned short	tefuovtm ;			/* �����Ԥ��̎ߎ؎ЎÎ��̎ގ����ю�������			*/
	unsigned short	tefuintv ;			/* ���̥ǡ��������ֳ֥�������		*/
	unsigned short	tefumdid ;			/* ���⥸�塼��ɣ�					*/
	unsigned short	tefuacid ;			/* ��ư¦���ܣ��ãɣ�				*/
	unsigned short	tefuownl ;			/* ���̿�����̾Ĺ��					*/
	unsigned short	tefufspl ;			/* ���ƣӣ��Сݣɣ�Ĺ��				*/
	unsigned char	tefurpnm[MLH_PRCNL];/* �ڎ��Ύߎݎ���������AP�̎ߎێ�������̾	*/
	unsigned char	tefudfnm[MLHCFLEN];	/* ���̿�����̾�ե�����ѥ�̾		*/
	unsigned char	tefuowid[MLHCCLEN];	/* ���̿�����̾						*/
	unsigned char	tefufsap[MLHFSAPL];	/* ���ƣӣ��Сݣɣ�					*/
	unsigned short	tefusaet ;			/* ȯ��¦���ť����ȥ�				*/
	unsigned short	tefusnet ;			/* ȯ��¦�ּ���						*/
	unsigned short	tefusadl ;			/* ȯ��¦���ɥ쥹Ĺ��				*/
	unsigned short	tefusprl ;			/* ȯ��¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��		*/
	unsigned char	tefusadr[MLH_ADLN] ;/* ȯ��¦���ɥ쥹					*/
	unsigned char	tefusprs[MLH_PSLL] ;/* ȯ��¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���			*/
	unsigned short	tefutpno ;			/* �ԣӣ����ֹ�						*/
	unsigned char	tefubdmy ;			/* ��ͽ����							*/
	unsigned char	tefuswal ;			/* ����ĥ���Ďގڎ�Ĺ��					*/
	unsigned char	tefuswad[MLHEXADL];	/* ����ĥ���Ďގڎ�						*/
	unsigned short	tefusvcl ;			/* �����ӥ����饹					*/
	unsigned short	tefumaxs ;			/* ���祹�ȥ��Ĺ					*/
	unsigned char	tefufunt[2] ;		/* ��ǽ��˥å�						*/
	unsigned char	tefuagrp[2] ;		/* °�����롼��						*/
										/******** ž��ñ�̴��ǡ��� ********/
	unsigned short	tefumaxb ;			/* �����������Хåե�Ĺ				*/
	unsigned short	tefumins ;			/* �Ǿ����ȥ��Ĺ					*/
										/*** �ե����������ѥ�᡼������� ***/
	long			tefuusid ;			/* �����̎�����:���Վ�����ID				*/
	long			tefugpid ;			/* �����̎�����:�����ގَ��̎�ID				*/
	long			tefubsiz ;			/* �Х��ȥ��ȥ꡼��֥�å�Ĺ		*/
	long			tefuf1at ;			/* �ƣԣ��͡ݣ���°��				*/
	long			tefuf1rc ;			/* �ƣԣ��͡ݣ����쥳����Ĺ			*/
	unsigned short	tefuf1bl ;			/* �ƣԣ��͡ݣ����֥�å�Ĺ			*/
	unsigned short	tefuf1as ;			/* �ƣԣ��͡ݣ�������ΰ襵����		*/
	long			tefuf3at ;			/* �ƣԣ��͡ݣ���°��				*/
	long			tefuf3rc ;			/* �ƣԣ��͡ݣ����쥳����Ĺ			*/
	unsigned short	tefuf3bl ;			/* �ƣԣ��͡ݣ����֥�å�Ĺ			*/
	unsigned short	tefuf3as ;			/* �ƣԣ��͡ݣ�������ΰ襵����		*/
	long			tefui1at ;			/* �ɣΣԣ��Сݣ���°��				*/
	long			tefui1rc ;			/* �ɣΣԣ��Сݣ����쥳����Ĺ		*/
	unsigned short	tefui1bl ;			/* �ɣΣԣ��Сݣ����֥�å�Ĺ		*/
	unsigned short	tefui1as ;			/* �ɣΣԣ��Сݣ�������ΰ襵����	*/
						/* F_DATA����������ϢSG�� @@@SSCY0057 Start			*/
	unsigned char		tefurstf;		/* ������������ؼ��̎׎���				*/
										/*  0x01...��������������			*/
										/*  0x00...����������������			*/
	unsigned char		tefursts;		/* ������������CVOS�ʎގ��̎�����Ψ(%)	*/
										/*  >=tefursts�ΤȤ���������		*/
	unsigned char		tefurste;		/* �����������CVOS�ʎގ��̎�����Ψ(%)	*/
										/*  <tefurste�ΤȤ��������			*/
										/*  tefursts>=tefurste�Ǥ��뤳��	*/
	unsigned char		tefursti;		/* ������������ƻ�ֳ�(��)			*/
	unsigned char		tefursv[4];		/* ͽ��								*/
										/* @@@SSCY0057 End					*/
};										/* �ԣţƣե��ֶ�������¤			*/
typedef	struct	tefusub		TEFUSUB;	/* �ԣţƣե��ֶ�������¤			*/


/****************************************************************************/
/*  �ԣţƣո�������¤    ����                                              */
/****************************************************************************/
struct	tefupsz							/* �ԣţƣո�������¤				*/
{
	unsigned char	tefupstn ;			/* �ԣţƣո��������ơ�����	<FJ003>	*/
	unsigned char	tefudumy[3] ;		/* ͽ�����ꥢ				<FJ003>	*/
	unsigned short	tefudstl ;			/* �̿���꼱��̾Ĺ��				*/
	unsigned short	tefusapl ;			/* �����ƣӣ��Сݣɣ�Ĺ��			*/
	unsigned char	tefudsid[MLHCCLEN];	/* �̿���꼱��̾					*/
	unsigned char	tefursap[MLHFSAPL];	/* �����ƣӣ��Сݣɣ�				*/
	unsigned short	tefuraet ;			/* ���¦���ť����ȥ�				*/
	unsigned short	tefurnet ;			/* ���¦�ּ���						*/
	unsigned short	tefuradl ;			/* ���¦���ɥ쥹Ĺ��				*/
	unsigned short	tefurprl ;			/* ���¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��		*/
	unsigned char	tefuradr[MLH_ADLN] ;/* ���¦���ɥ쥹					*/
	unsigned char	tefurprs[MLH_PSLL] ;/* ���¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���			*/
	unsigned short	tefulnno ;			/* �̣�								*/
	unsigned short	tefutpln ;			/* ���ԣӣ��Сݣɣ�Ĺ��			*/
	unsigned char	tefutpid[MLHTSAPL];	/* ���ԣӣ��Сݣɣ�				*/
	unsigned char	tefusidl ;			/* ���̎ގ����Ďގڎ�Ĺ��					*/
	unsigned char	tefupltl ;			/* �̎ߎێĎ���IDĹ��						*/
	unsigned char	tefucdws ;			/* ��Ǝ����ݎĎގ�����������					*/
	unsigned char	tefuciws ;			/* ȯ�Ǝ����ݎĎގ�����������					*/
	unsigned char	tefusbid[8] ;		/* ���̎ގ����Ďގڎ�						*/
	unsigned char	tefuplid[4] ;		/* �̎ߎێĎ���ID							*/
	unsigned char	tefutpcl ;			/* ���َ��̎ߎ��Ď����׎�						*/
	unsigned char	tefucdps ;			/* ��Ǝʎߎ����Ď�������					*/
	unsigned char	tefucips ;			/* ȯ�Ǝʎߎ����Ď�������					*/
	unsigned char	tefufast ;			/* �̎����Ď��ڎ���							*/
	unsigned char	tefuheno[2] ;		/* �İ��������ֹ�					*/
	unsigned char	tefudmy0 ;			/* ��ͽ����							*/
	unsigned char	tefuawal ;			/* ����ĥ���Ďގڎ�Ĺ��				*/
	unsigned char	tefuawad[MLHEXADL];	/* ����ĥ���Ďގڎ�					*/
};										/* �ԣţƣո�������¤				*/
typedef	struct	tefupsz		TEFUPSZ ;	/* �ԣţƣո�������¤				*/

/*********************** <<<<< end of mlh_0001.h >>>>> **********************/
