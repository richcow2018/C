
/**********************************************************************/
/*																	  */
/* tpau.h  94.09.16	�ٻ��� ������									  */
/*																	  */
/**********************************************************************/

typedef	struct {
		short  tpauwsmx;			   /* �������ގ�	�܎������Î������� ���ݎ؎���		  */
		char   tpautint;			   /* md_tint �֎�				  */
		char   tpauyob1;			   /* �֎ˎ�1						  */
		char   tpauyob2[8];			   /* �֎ˎ�2						  */
		short  tpauioen;			   /* ͽ��					   JJ */
		short  tpauiosu;			   /* ͽ��					   JJ */
		short  tpaucken;			   /* ͽ��					   JJ */
		short  tpaucksu;			   /* ͽ��					   JJ */
		char   tpauyob3[4];			   /* �֎ˎ�3						  */
}			   TPAUSUB;				   /* FIP �֎�					  */

typedef	struct {
		char   tpaugrcd[12]	 ;		   /* ���ގَ��̎� �����Ď�				  */
		char   tpaundth		 ;		   /* NTC ���ގ��ˎ֎� �ˎ֎�����			  */
		char   tpausdth		 ;		   /* ���̎� ���ގَ��̎� ���ގ��ˎ֎�	�ˎ֎�����	  */
		short  tpauiokd		 ;		   /* IO ���Վ͎ގ�					  */
		short  tpauwsen		 ;		   /* �Վ����� �܎������Î������� ���ݎ؎���		  */
		short  tpaupctn		 ;		   /* TPCT ���ݎĎ�	NO.				  */
		char   tpauyob4[4];			   /* �֎ˎ�4						  */
}			   TPAUPSZ;				   /* FIP �֎�					  */

typedef	struct {
		char	tpauwscl;			   /* �܎������Î�������	�����͎ގ�			  */
		char	tpauwskb;			   /* �܎������Î����֎�	NO.	�����Î� ���̎ގ�  CC */
		short	tpauwsno;			   /* �܎������Î�������	NO.				  */
		char	tpauyob5[4];		   /* �֎ˎ�5						  */
}				TPAUWS;				   /* FIP �֎�					  */
