
/**************************************************************************/
/*																		  */
/*		 TEFY ��-�̎ގ�	�̎�-�ώ���		 tefy.h		   (94.09.16)				  */
/*																		  */
/**************************************************************************/
struct mdefysb {						 /*	 TEFY ���̎޶�����				  */
	   long	   tefytmop;				 /*	 �Ǝ����̎ߎݎ�����	��				  */
	   long	   tefytmdl;				 /*	 �Îގ����؎ݎ�������	��				  */
};										 /*								  */
typedef	struct mdefysb TEFYSUB;			 /*								  */
										 /*								  */
struct mdefyko {						 /*	 TEFY ������				  */
	   char	   tefypuno;				 /*	 PU�ֹ�						  */ 
	   char	   yob1;					 /*	 ͽ��						  */
	   char	   tefykset;				 /*	 ȯ��Ʊ��ѥե饰��			  */
	   char	   tefyqbit;				 /*	 Q�ӥå�ON/OFF				  */
	   long	   tefyrtri;				 /*	 �؎Ď׎����					  */
	   char	   tefyhpsz;				 /*	 ȯ�ƼԎʎߎ����Ď������� �ʾ����	  */ 
	   char	   tefycpsz;				 /*	 ��ƼԎʎߎ����Ď������� �ʾ����	  */ 
	   char	   tefypkff;				 /*	 �ʎߎ����Ď������� �̎������؎Î��̎׎���		  */ 
	   char	   yob2;					 /*	 ͽ��						  */ 
	   char	   tefyhwsz;				 /*	 ȯ�Ƽ�WSNO					  */ 
	   char	   tefycwsz;				 /*	 ��Ƽ�WSNO					  */ 
	   char	   tefywsff;				 /*	 WSNO �̎������؎Î��̎׎���			  */ 
	   char	   yob3;					 /*	 ͽ��						  */ 
	   char	   tefyfasp;				 /*	 �̎����Ď��ڎ��Ď��ʎߎ׎Ҏ���			  */ 
	   char	   tefykinp;				 /*	 �忮�ݶ⎥�ʎߎ׎Ҏ���			  */ 
	   char	   tefythru;				 /*	 ȯ��ƼԎ��َ��̎ߎ��Ď��׎�			  */ 
	   char	   yob4;					 /*	 ͽ��						  */ 
	   long	   tefydeln;				 /*	 ���DTE���Ďގڎ����			  */ 
	   long	   tefyhadl;				 /*	 ȯ���Ďގڎ����				  */ 
	   long	   tefycadl;				 /*	 �厱�Ďގڎ����				  */ 
	   char	   tefydead[20];			 /*	 ���DTE���Ďގڎ���Ǽ�莱�Ďގڎ�	  */ 
	   char	   tefyhaad[20];			 /*	 ȯ���Ďގڎ�					  */ 
	   char	   tefycaad[20];			 /*	 �厱�Ďގڎ�					  */ 
};										 /*								  */
typedef	struct mdefyko TEFYPSZ;			 /*								  */
