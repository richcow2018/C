/****************************************************************************/
/*���������������                                                        */
/*            �Σԣԥǡ����̿��������                                      */
/*              ��ͻ�����ƥ��������                                        */
/*  ����ʪ��                                                                */
/****************************************************************************/
/*���ե�����̾��ts5l.h                                                      */
/*  ��ǽ      ���̣�����ơ��֥�                                            */
/*  ������������                                                            */
/*  �ѹ���    ��                                                            */
/****************************************************************************/
#if TS5L_INCLUDE
#else
#define TS5L_INCLUDE 1
/*--------------------------------*/
/* ���ֶ�����                     */
/*--------------------------------*/
struct mds5lsb {
	long        ts5lwait;               /* �����������Ԥ���������           */
	long        ts5lrspt;               /* ̤�������ƻ륿������           */
	long		ts5lldas;				/* LWS����������������ݎ������Ď�			*/
	long		ts5llkss;				/* LWS������λ���������ݎ������Ď�			*/
	long		ts5lrtos;				/* ̤�������ƻ�����ю����Ļ��������ݎ������Ď�*/
	long		ts5lnors;				/* read�ʤ����������ݎ������Ď�			*/
	char        ts5lyobi[12];           /* ͽ��                             */
};

typedef struct mds5lsb TS5LSUB;         /* FIP �֎�                           */

/*--------------------------------*/
/* ������                         */
/*--------------------------------*/
struct mds5lko {
	long        ts5lkbst;               /* ���������ơ�����                 */
	short       ts5lluno;               /* �̣��ֹ�                         */
	short       ts5llugn;               /* �̣ե��롼���ֹ�                 */
	short		ts5lfahe;				/* TFAH���ݎĎ��ֹ�						*/
	short		ts5lyob2;				/* ͽ��								*/
	unsigned long	ts5lrcvs;			/* �������RUĹ�����				*/
	unsigned char	ts5lrcvp;			/* ����WS�����						*/
	unsigned char	ts5llufg;			/* ����LWS����ʬ���̎׎���(1:���� 0:¾)	*/
	unsigned char	ts5lyob3[2];		/* ͽ��								*/
	unsigned long	ts5lsnds;			/* ��������RUĹ������				*/
	unsigned short	ts5lwrmx;			/* LU�׎���¿�Ÿ���					*/
	unsigned short	ts5lyob4;			/* ͽ��								*/
	char        ts5lyob5[12];           /* ͽ��                             */
};

typedef struct mds5lko TS5LPSZ;         /* FIP �֎�                           */


#define  TS5LSBSZ   (sizeof(TS5LSUB))   /* TS5L���̎޶����􎻎�����                */
#define  TS5LKOSZ   (sizeof(TS5LPSZ))   /* TS5L�����􎻎�����                   */

#endif
