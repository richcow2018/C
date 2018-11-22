
/**********************************************************************/
/*																	  */
/*		  TLPI �Î��̎ގ� �̎����ώ���		tlpi.h		(94.09.16)				  */
/*									  �͎ݎ���	(  .  .	 )				  */
/*									  �ѹ�	   .  .					  */
/*									  �ѹ��� ������					  */
/*																	  */
/**********************************************************************/

struct mdlpisb {
		short	tlpiinen;				/* ͽ��					   JJ */
		char	tlpiyob0[6];			/* �֎ˎ�0						  */
};
typedef	struct mdlpisb MDLPISB;			/* DCP �֎�					  */
typedef	struct mdlpisb TLPISUB;			/* FIP �֎�					  */

struct	mdlpiko	{
		char	tlpikhyo	  ;			/* ���͎ގ̎� �ˎ�������				  */
		char	tlpiyob1	  ;			/* �֎ˎ�1						  */
		char	tlpilusb	  ;			/* LU �����͎ގ�					  */
		char	tlpittyp	  ;			/* ���ݎώ�	�����̎�				  */
		short	tlpifahn	  ;			/* TFAH	���ݎĎ� NO.			  */
		short	tlpilgtn	  ;			/* TLGT	���ݎĎ� NO.			  */
		short	tlpipuno	  ;			/* PU NO.					  */
		short	tlpiluno	  ;			/* LU NO.					  */
		char	tlpihpas	  ;			/* �ʎߎ� ���Î�����				  */
		char	tlpihopn	  ;			/* �����̎ߎ� ���Î�����				  */
		char	tlpihred	  ;			/* �؎��Ď�	���Î�����				  */
		char	tlpihwrt	  ;			/* �׎��� ���Î�����				  */
		char	tlpihscn	  ;			/* ��������	�������� ���Î�����			  */
		char	tlpihrcn	  ;			/* ���ގ����� �������� ���Î�����			  */
		char	tlpihres	  ;			/* �����Ď�	�������� ���Î�����			  */
		char	tlpihsht	  ;			/* SHUT	- DOWN ���Î�����		 **/
		char	tlpihtex	  ;			/* ���� �Îގݎ̎ގ� ���Î�����			  */
		char	tlpihhdk	  ;			/* �ˎĎގ��� ���� ���Î�����			 **/
		short	tlpiwrtc	  ;			/* �׎��� �����ݎ�					  */
		char	tlpiblct	  ;			/* �̎ގ׎��� ���֎� �ˎ֎�����			 **/
		char	tlpiyob2	  ;			/* �֎ˎ�2						 **/
		short	tlpitben	  ;			/* TLPI	�������֎��̎�	���ݎĎ؎� �ʎގݎ��ގ� **/
		short	tlpipatn	  ;			/* TPAT	���ݎĎ؎� �ʎގݎ��ގ�	   CC */
		short	tlpiyob3	  ;			/* �֎ˎ�3					   CC */
		char	tlpipsnm[8]	  ;			/* �ێݎ� �ʎߎ� �����͎ގҎ�		   CC */
		long	tlpiyob4[2]	  ;			/* �֎ˎ�4					   CC */
};
typedef	struct	mdlpiko	MDLPIKO;		/* DCP �֎�					  */
typedef	struct	mdlpiko	TLPIPSZ;		/* FIP �֎�					  */
