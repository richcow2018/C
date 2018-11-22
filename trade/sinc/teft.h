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
/*          <teft.h>                       FTAM�̎ߎێ��ގ׎� SG�Îގ����Î��̎ގٹ�¤�����*/
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
/*  95.07.22 K.Kubota SSCY0089: FC��Ω�����ƻ����������ɲ�              	*/
/*                                                                          */
/*                                                                          */
/****************************************************************************/


/****************************************************************************/
/*********************************** �ģţƣɣΣ��� *************************/
/****************************************************************************/
#define	MLHCCLEN	16					/* �̿�����̾���؎�Ĺ��				*/
#define	MLHCFLEN	64					/* ���̿�����̾�̎����َ��؎�Ĺ��			*/
#define	MLHEXADL	20					/* ��ĥ���ɥ쥹���؎�Ĺ��				*/
#define	MLHEXMAX	40					/* ��ĥ���ɥ쥹����Ĺ��		<FJ003>	*/
#define	MLH_PRCNL	8					/* �ץ�������̾Ĺ��				*/
#define	MLHFSAPL	16					/* �ƣӣ��Сݣɣ�Ĺ��				*/
#define	MLHTSAPL	32					/* �ƣӣ��Сݣɣ�Ĺ��				*/
#define	MLH_ADLN	8					/* ���ɥ쥹Ĺ��						*/
#define	MLH_PSLL	4					/* �̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��				*/


/****************************************************************************/
/*********************************** ��¤�Ρ���� ***************************/
/****************************************************************************/

/****************************************************************************/
/*  �ԣţƣԥ��ֶ�������¤����                                              */
/****************************************************************************/
struct	teftsub							/* �ԣţƣԥ��ֶ�������¤			*/
{
										/********* �ɣң´�Ϣ������ *********/
	unsigned short	teftirbs ;			/* ����ɣң¿�						*/
	unsigned short	teftkafu ;			/* �ɣң²���ٰܹԿ�				*/
	unsigned short	teftkaij ;			/* �ɣң²���ٲ����				*/
										/******** ���ܡ��Ȱ����Ѥ����� ******/
	unsigned short	teftoprq ;			/* FSAP��Ͽ�׵�ȯ�Կ�				*/
	unsigned short	teftoprs ;			/* FSAP��Ͽ�����ǧ������			*/
	unsigned short	teftclrq ;			/* FSAP����׵�ȯ�Կ�				*/
	unsigned short	teftclrs ;			/* FSAP��������ǧ������			*/
	unsigned short	teftfspn ;			/* FSAP�ֹ� 						*/
										/***** RALLY ������� �����Ўݎ���Ĵ�� ****/
	short			teftrcnt ;			/* rvinit�؎Ď׎������					*/
	short			teftrtms ;			/* rvinit NG ��(�؎Ď׎��Ԥ�������)		*/
										/******* ACE-SMP��FTAM �ӣ��� ********/
	unsigned short	teftfmax ;			/* �ƣú�����						*/
	unsigned short	teftrsno ;			/* ����¦�ƣÿ�						*/
	unsigned short	teftovtm ;			/* �����Ԥ��̎ߎ؎ЎÎ��̎ގ����ю�������			*/
	unsigned short	teftintv ;			/* ���̥ǡ��������ֳ֥�������		*/
	unsigned short	teftmdid ;			/* ���⥸�塼��ɣ�					*/
	unsigned short	teftacid ;			/* ��ư¦���ܣ��ãɣ�				*/
	unsigned short	teftownl ;			/* ���̿�����̾Ĺ��					*/
	unsigned short	teftfspl ;			/* ���ƣӣ��Сݣɣ�Ĺ��				*/
	unsigned char	teftrpnm[MLH_PRCNL];/* �ڎ��Ύߎݎ���������AP�̎ߎێ�������̾	*/
	unsigned char	teftdfnm[MLHCFLEN];	/* ���̿�����̾�ե�����ѥ�̾		*/
	unsigned char	teftowid[MLHCCLEN];	/* ���̿�����̾						*/
	unsigned char	teftfsap[MLHFSAPL];	/* ���ƣӣ��Сݣɣ�					*/
	unsigned short	teftsaet ;			/* ȯ��¦���ť����ȥ�				*/
	unsigned short	teftsnet ;			/* ȯ��¦�ּ���						*/
	unsigned short	teftsadl ;			/* ȯ��¦���ɥ쥹Ĺ��				*/
	unsigned short	teftsprl ;			/* ȯ��¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��		*/
	unsigned char	teftsadr[MLH_ADLN] ;/* ȯ��¦���ɥ쥹					*/
	unsigned char	teftsprs[MLH_PSLL] ;/* ȯ��¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���			*/
	unsigned short	tefttpno ;			/* �ԣӣ����ֹ�						*/
	unsigned char	teftbdmy ;			/* ��ͽ����							*/
	unsigned char	teftswal ;			/* ����ĥ���Ďގڎ�Ĺ��					*/
	unsigned char	teftswad[MLHEXADL];	/* ����ĥ���Ďގڎ�						*/
	unsigned short	teftsvcl ;			/* �����ӥ����饹					*/
	unsigned short	teftmaxs ;			/* ���祹�ȥ��Ĺ					*/
	unsigned char	teftfunt[2] ;		/* ��ǽ��˥å�						*/
	unsigned char	teftagrp[2] ;		/* °�����롼��						*/
										/******** ž��ñ�̴��ǡ��� ********/
	unsigned short	teftmaxb ;			/* �����������Хåե�Ĺ				*/
	unsigned short	teftmins ;			/* �Ǿ����ȥ��Ĺ					*/
										/*** �ե����������ѥ�᡼������� ***/
	long			teftusid ;			/* �����̎�����:���Վ�����ID				*/
	long			teftgpid ;			/* �����̎�����:�����ގَ��̎�ID				*/
	long			teftbsiz ;			/* �Х��ȥ��ȥ꡼��֥�å�Ĺ		*/
	long			teftf1at ;			/* �ƣԣ��͡ݣ���°��				*/
	long			teftf1rc ;			/* �ƣԣ��͡ݣ����쥳����Ĺ			*/
	unsigned short	teftf1bl ;			/* �ƣԣ��͡ݣ����֥�å�Ĺ			*/
	unsigned short	teftf1as ;			/* �ƣԣ��͡ݣ�������ΰ襵����		*/
	long			teftf3at ;			/* �ƣԣ��͡ݣ���°��				*/
	long			teftf3rc ;			/* �ƣԣ��͡ݣ����쥳����Ĺ			*/
	unsigned short	teftf3bl ;			/* �ƣԣ��͡ݣ����֥�å�Ĺ			*/
	unsigned short	teftf3as ;			/* �ƣԣ��͡ݣ�������ΰ襵����		*/
	long			tefti1at ;			/* �ɣΣԣ��Сݣ���°��				*/
	long			tefti1rc ;			/* �ɣΣԣ��Сݣ����쥳����Ĺ		*/
	unsigned short	tefti1bl ;			/* �ɣΣԣ��Сݣ����֥�å�Ĺ		*/
	unsigned short	tefti1as ;			/* �ɣΣԣ��Сݣ�������ΰ襵����	*/
						/* F_DATA����������ϢSG�� @@@SSCY0057 Start			*/
	unsigned char		teftrstf;		/* ������������ؼ��̎׎���				*/
										/*  0x01...��������������			*/
										/*  0x00...����������������			*/
	unsigned char		teftrsts;		/* ������������CVOS�ʎގ��̎�����Ψ(%)	*/
										/*  >=teftrsts�ΤȤ���������		*/
	unsigned char		teftrste;		/* �����������CVOS�ʎގ��̎�����Ψ(%)	*/
										/*  <teftrste�ΤȤ��������			*/
										/*  teftrsts>=teftrste�Ǥ��뤳��	*/
	unsigned char		teftrsti;		/* ������������ƻ�ֳ�(��)			*/
										/* ###SSCY0089 start				*/
	unsigned short		teftfctm;		/* FC��Ω�����ƻ����(��)			*/
										/*   0...�ƻ뤷�ʤ�					*/
										/*  >0...�ƻ뤹��					*/
	unsigned char		teftrsv[2];		/* ͽ��								*/
										/* ###SSCY0089 end					*/
										/* @@@SSCY0057 End					*/
};										/* �ԣţƣԥ��ֶ�������¤			*/
typedef	struct	teftsub		TEFTSUB;	/* �ԣţƣԥ��ֶ�������¤			*/


/****************************************************************************/
/*  �ԣţƣԸ�������¤    ����                                              */
/****************************************************************************/
struct	teftpsz							/* �ԣţƣԸ�������¤				*/
{
	unsigned char	teftpstn ;			/* �ԣţƣԸ��������ơ�����	<FJ003>	*/
	unsigned char	teftdumy[3] ;		/* ͽ�����ꥢ				<FJ003>	*/
	unsigned short	teftdstl ;			/* �̿���꼱��̾Ĺ��				*/
	unsigned short	teftsapl ;			/* �����ƣӣ��Сݣɣ�Ĺ��			*/
	unsigned char	teftdsid[MLHCCLEN];	/* �̿���꼱��̾					*/
	unsigned char	teftrsap[MLHFSAPL];	/* �����ƣӣ��Сݣɣ�				*/
	unsigned short	teftraet ;			/* ���¦���ť����ȥ�				*/
	unsigned short	teftrnet ;			/* ���¦�ּ���						*/
	unsigned short	teftradl ;			/* ���¦���ɥ쥹Ĺ��				*/
	unsigned short	teftrprl ;			/* ���¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���Ĺ��		*/
	unsigned char	teftradr[MLH_ADLN] ;/* ���¦���ɥ쥹					*/
	unsigned char	teftrprs[MLH_PSLL] ;/* ���¦�̎ߎڎ��ގݎÎ������ݎ��ڎ���			*/
	unsigned short	teftlnno ;			/* �̣�								*/
	unsigned short	tefttpln ;			/* ���ԣӣ��Сݣɣ�Ĺ��			*/
	unsigned char	tefttpid[MLHTSAPL];	/* ���ԣӣ��Сݣɣ�				*/
	unsigned char	teftsidl ;			/* ���̎ގ����Ďގڎ�Ĺ��					*/
	unsigned char	teftpltl ;			/* �̎ߎێĎ���IDĹ��						*/
	unsigned char	teftcdws ;			/* ��Ǝ����ݎĎގ�����������					*/
	unsigned char	teftciws ;			/* ȯ�Ǝ����ݎĎގ�����������					*/
	unsigned char	teftsbid[8] ;		/* ���̎ގ����Ďގڎ�						*/
	unsigned char	teftplid[4] ;		/* �̎ߎێĎ���ID							*/
	unsigned char	tefttpcl ;			/* ���َ��̎ߎ��Ď����׎�						*/
	unsigned char	teftcdps ;			/* ��Ǝʎߎ����Ď�������					*/
	unsigned char	teftcips ;			/* ȯ�Ǝʎߎ����Ď�������					*/
	unsigned char	teftfast ;			/* �̎����Ď��ڎ���							*/
	unsigned char	teftheno[2] ;		/* �İ��������ֹ�					*/
	unsigned char	teftdmy0 ;			/* ��ͽ����							*/
	unsigned char	teftawal ;			/* ����ĥ���Ďގڎ�Ĺ��				*/
	unsigned char	teftawad[MLHEXADL];	/* ����ĥ���Ďގڎ�					*/
};										/* �ԣţƣԸ�������¤				*/
typedef	struct	teftpsz		TEFTPSZ ;	/* �ԣţƣԸ�������¤				*/

/*********************** <<<<< end of mlh_0001.h >>>>> **********************/
