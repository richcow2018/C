/**********************************************************************/
/*																	  */
/* tfai.h 94/09/16 �ٻ��� ������									  */
/*																	  */
/**********************************************************************/

typedef	struct {
		short	 tfaiinen;				 /*	ͽ��					  */
		char	 tfaitype;				 /*	������ �������ގ� ���Վ͎ގ�		  */
		char	 tfaiyob0;				 /*	�֎ˎ�0					  */
		short	 tfaipsmx;				 /*	�ێݎ�	�ʎߎ�	�������ގ� ����		  */
		char	 tfaiyob1[6];			 /*	�֎ˎ�1					  */
}				 TFAISUB;				 /*	DYREC�֎�					  */

typedef	struct {
		char   tfailnsb		 ;			 /*	�������� �����͎ގ�				  */
		char   tfaipksb		 ;			 /*	�ʎߎ���������	�����͎ގ�			  */
		char   tfainjid[6]	 ;			 /*	2���ގ����� �����͎ގ� ���ގ����Ύ�		  */
		char   tfaipsnm[22]	 ;			 /*	�ʎߎ�	�Ҏ�					  */
		short  tfailnno		 ;			 /*	�������� �ʎގݎ��ގ�				  */
		long   tfaimbid		 ;			 /*	�Ҏ��َΎގ����� ID				  */
		short  tfaiifrm		 ;			 /*	I �̎ڎ��� ������				  */
		char   tfaiyuko		 ;			 /*	�Վ����� �ю��� �ˎ�������			  */
		char   tfaiyob2		 ;			 /*	�֎ˎ�2					  */
		short  tfaisszu		 ;			 /*	�����ގҎݎĎ�������(�ɎΎގ�)		  */
		short  tfaisszd		 ;			 /*	�����ގҎݎĎ�������(�����ގ�)		  */
		char   tfaishut		 ;			 /*	SHUT-DOWN �ˎ֎�����			  */
		char   tfaidlty		 ;			 /*	�Îގ��� �؎ݎ� �ˎ֎�����			  */
		char   tfaibloc		 ;			 /*	�̎ގێ� ���� �ˎ֎�����			  */
		char   tfaibkup		 ;			 /*	�ʎގ� ���̎� �ˎ֎�����			  */
		char   tfaipckb		 ;			 /*	������ �������ގ� ���Վ͎ގ�		  */
		char   tfailsts		 ;			 /*	�������� ���Î�����				  */
		char   tfailhdk		 ;			 /*	�������� �ˎĎގ��� ���� ���Î�����	  */
		char   tfailkdk		 ;			 /*	�������� �����̎� �Ďގ��� ���Î�����	  */
		short  tfaidadn		 ;			 /*	TDAD ���ݎĎ� �ʎގݎ��ގ�		  */
		short  tfaitben		 ;			 /*	���������� �Î��̎ގ�	���ݎĎ� �ʎގݎ��ގ�	  */
		short  tfaifacn		 ;			 /*	�ԣƣ��äΥ���ȥ��ֹ�	  */
		char   tfaichst		 ;			 /*							  */
		char   tfaiyob3		 ;			 /*	 ͽ��					  */
		short  tfailpte		 ;			 /*	TLPH �Ύߎ��ݎ� �Վ�����	���ݎĎ؎���	  */
		short  tfaitplt		 ;			 /*	TPLT ���ݎĎ� �ʎގݎ��ގ�		  */
		char   tfaiyob4[4]	 ;			 /*	 ͽ��					  */
}			   TFAIPSZ;					 /*	DYREC �֎�				  */

typedef	struct {
		short	 tfailphn;				 /*	TLPH ���ݎĎ� �ʎގݎ��ގ�		  */
}				 TFAIPS;				 /*	DYRE �֎�					  */
