
/**********************************************************************/
/*																	  */
/*		  TLPU �Î��̎ގ� �̎����ώ���		tlpu.h		(94.09.16)				  */
/*									  �͎ݎ���	(  .  .	 )				  */
/*									  �ѹ�	   .  .					  */
/*									  �ѹ���						  */
/*																	  */
/**********************************************************************/

struct mdlpusb {
		short	 tlpuinen;				 /*	ͽ��				   JJ */
		char	 tlpuyob0[6];			 /*	�֎ˎ�0					  */
};
typedef	struct mdlpusb MDLPUSB;			 /*	DCP	�֎�					  */
typedef	struct mdlpusb TLPUSUB;			 /*	FIP	�֎�					  */

struct mdlpuko {
	char   tlpukhyo	   ;				 /*	���͎ގ̎� �ˎ�������			  */
	char   tlpuyob1[3] ;				 /*	�֎ˎ�1					  */
	short  tlpufapn	   ;				 /*	TFAP ���ݎĎ� NO.			  */
	short  tlpulgtn	   ;				 /*	TLGT ���ݎĎ� NO.			  */
	char   tlpuipas	   ;				 /*	�ʎߎ�	���Î�����				  */
	char   tlpuiatt	   ;				 /*	ATT	���Î�����				  */
	char   tlpuihdk	   ;				 /*	�ˎĎގ��� ���Î�����				  */
	char   tlpuyob2	   ;				 /*	�֎ˎ�2					  */
	short  tlpupatn	   ;				 /*	TPAT ���ݎĎ� �ʎގݎ��ގ�	   CC */
	short  tlpuyob3	   ;				 /*	�֎ˎ�3				   CC */
	char   tlpupsnm[8] ;				 /*	�ێݎ�	�ʎߎ�	�����͎ގҎ�		   CC */
	char   tlpuyob4[4] ;				 /*	�֎ˎ�4					  */
};
typedef	struct mdlpuko MDLPUKO;			 /*	DCP	�֎�					  */
typedef	struct mdlpuko TLPUPSZ;			 /*	FIP	�֎�					  */
