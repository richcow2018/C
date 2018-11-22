/********************************************************/
/* 1995.07.07 LICP-TRADE���ֵ����Ѵ��Υ��󥹥����		*/
/* 		�����ԡ��Ķ�Ź�����ƥ�ô�����ʿ�ƣͳ����		*/
/*			�ξ����ɼ��ST2911							*/
/*			meio.h��ˤ����ơ��Ѵ��ơ��֥��static�ǻ���*/
/*			�Ƥ�����Τ��ѹ��������Ȥ˵������롣		*/
/*			���Τϡ�me_pint()��¸�ߤ��롣meio.h�Ǥϡ�ex */
/*			tern �ǻ��Ȥ��롣							*/
/********************************************************/
/*��TRADE LOOP(1jikyoku) RETURN VALUE	*/
#define	TIMERR	0xc2b20000	/* �������ͤ����곰			*/
#define PRMERR	0xc2f10000	/* �ѥ�᡼�����顼			*/
#define	RSPERR	0xc2b00100	/* �۾�쥹�ݥ󥹼���	1xx	*/
#define	STSERR	0xc2b30001	/* �����ʎߎ�̤����			*/
#define	RSTERR	0xc2b00200	/* �ڎ��Ύߎݎ��Ԥ������ώ����ю�����		*/
#define	DLIERR	0xc2b00300	/* �ʎߎ܎����̎��Îݎ����ݼ���			*/
#define	CHNERR	0xc2a10000	/* �롼���Ǥ򸡽Ф���		*/
#define	HRDERR	0xc2800400	/* I/O�ڎ��ގ��������������ʎގ����׎�ȯ��	*/
#define	OVFERR	0xc2b00020	/* �����С��ե�			*/
#define	SQCERR	0xc2a00027	/* �������󥹥��顼			*/
#define	CHAERR	0xc2f00005	/* ����̤��³�ˤ�뎷���ݎ���	*/
#define	RPNERR	0xc2b30003	/* �����ʎߎ��ֹ椬��ä�		*/
#define	RPMERR	0xc2b30002	/* ������³�����ʎߎ��􎵎��ʎގ�	*/
#define	KSFERR	0xc2b20001	/* ������������				*/

/*��TRADE 4WI/O RETURN VALUE	*/
#define FPMERR	0xc1a20000	/* �ѥ�᡼�����顼			*/

/*  LICP RETURN CODE 				*/
#define	LICP01	0x01000001	/* ��å��������̻�����		*/
#define	LICP02	0x01000002	/* �Îގ����ʎގ��̎����Ў��Ďގڎ�����	*/
#define	LICP03	0x01000003	/* �Îގ����ʎގ��̎�������������		*/
#define	LICP04	0x01000004	/* �Ҏ��������ގ����̎�����			*/
#define	LICP05	0x01000005	/* �̎��ݎ������ݎ����̎�����			*/
#define	LICP06	0x01000006	/* �ʎߎ�ID����				*/
#define	LICP07	0x01000007	/* ������������				*/
#define	LICP08	0x01000008	/* �������󥹥��顼			*/
#define	LICP09	0x01000009	/* �㳲��ˤ�륭��󥻥�	*/
#define	LICP0a	0x0100000a	/* �����ʎߎ�̤�������		*/
#define	LICP0b	0x0100000b	/* �����ʎߎ��ֹ�����			*/
#define	LICP0c	0x0100000c	/* ������³�����ʎߎ��􎵎��ʎގ�	*/
#define	LICP0d	0x0100000d	/* ȯ��Ƽ��̻�����			*/
#define	LICP0e	0x0100000e	/* ���ģԣŎ��Ďގڎ�Ĺ����	*/
#define	LICP0f	0x0100000f	/* �����َՎ����ގÎގ���Ĺ����		*/
#define	LICP10	0x01000010	/* �����َՎ����ގÎގ����������������*/
#define	LICP11	0x01000011	/* ����ʬ��Îގ���Ĺ����		*/
#define	LICP12	0x01000012	/* �����ݎĎގ�������������			*/
#define	LICP13	0x01000013	/* ���玺�Ȏ������ݿ􎵎��ʎގ�		*/
#define	LICP50	0x01000050	/* ȯ�Ƽ��̻�̤���ݡ���		*/
#define	LPERNC	0x02000001	/* ̤������ޥ�ɼ���		*/
#define	LPERUR	0x02000002	/* �۾�쥹�ݥ󥹼���		*/
#define	LPERSE	0x02000003	/* status error				*/
#define	LPEROV	0x02000004	/* over flow				*/
#define	LPERTO	0x02000005	/* responce time out		*/
#define	X25ERR	0x03000000	/* X.25 error				*/
#define	TCPERR	0x04000000	/* TCP/IP error				*/
#define	DLLERR	0x0a000000	/* data link error			*/
#define	LINERR	0x0b000000	/* line error				*/
#define HADERR	0x0c000000	/* hard error				*/
#define	SYSERR	0x0f000000	/* trade system call error	*/
