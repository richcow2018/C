/****************************************************************************/
/*																			*/
/* tlgu.h 94/09/16 �ٻ��� ������											*/
/*																			*/
/****************************************************************************/
typedef	struct {
	short				tlguinen;		/* ͽ��								*/
	char				tlguyob0[6];	/* �֎ˎ�0								*/
}						TLGUSUB;		/* FIP �֎�							*/

struct mdlguko {
	char   tlgukhyo	   ;	  /* ���͎ގ̎�	�ˎ�������				*/
	char   tlguyob1[3] ;	  /* �֎ˎ�1						*/
	short  tlgulphn	   ;	  /* TLPH ���ݎĎ� NO.				*/
	short  tlgulptn	   ;	  /* TLPT ���ݎĎ� NO.				*/
	short  tlgupatn	   ;	  /* TPAT ���ݎĎ� NO.				*/
	short  tlguyob2	   ;	  /* �֎ˎ�2						*/
	long   *tlgumiaa   ;	  /* �׎��� MIA �����ˎ��� ���Ďގڎ�		*/
	long   *tlgudsad   ;	  /* �Ύ؎��� �Îގ��� ������ ���Ďގڎ�		*/
	char   tlguyob3[4] ;	  /* �֎ˎ�3						*/
};
typedef	struct mdlguko TLGUPSZ;	  /* FIP �֎�						*/
