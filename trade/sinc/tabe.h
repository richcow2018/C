/**********************************************************************/
/*                                                                    */
/*        TABE �Î��̎ގ� �̎����ώ���     tabe.h  			                  */
/*                                   							      */
/*                                                                    */
/**********************************************************************/

struct  tabeko {
        short   tabenden;   	        /* ���ǡ�������ȥ��ֹ�              */
        short   tabeyob1;	       	    /* ͽ����				             */
        long    tabembid;       	    /* ������Ҏ��َΎގ�����ID					 */
        char    tabekkbn;       	    /* �����϶�ʬ					     */
        char    tabeyob2;	       	    /* ͽ����				             */
        short   tabesmid;       	    /* ȯ�Ը��ӎ��ގ�����ID				     */
        long    tabeadt1;       	    /* Ǥ�ՎÎގ���1					 	 */
        long    tabeadt2;       	    /* Ǥ�ՎÎގ���2					 	 */
        long    tabeadt3;       	    /* Ǥ�ՎÎގ���3					 	 */
};
typedef struct  tabeko TABEPSZ;        	/* TABE������   					 */
