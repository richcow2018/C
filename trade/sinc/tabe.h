/**********************************************************************/
/*                                                                    */
/*        TABE ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ     tabe.h  			                  */
/*                                   							      */
/*                                                                    */
/**********************************************************************/

struct  tabeko {
        short   tabenden;   	        /* 次データエントリ番号              */
        short   tabeyob1;	       	    /* 予備１				             */
        long    tabembid;       	    /* 通知先ﾒｰﾙﾎﾞｯｸｽID					 */
        char    tabekkbn;       	    /* 送信系区分					     */
        char    tabeyob2;	       	    /* 予備２				             */
        short   tabesmid;       	    /* 発行元ﾓｼﾞｭｰﾙID				     */
        long    tabeadt1;       	    /* 任意ﾃﾞｰﾀ1					 	 */
        long    tabeadt2;       	    /* 任意ﾃﾞｰﾀ2					 	 */
        long    tabeadt3;       	    /* 任意ﾃﾞｰﾀ3					 	 */
};
typedef struct  tabeko TABEPSZ;        	/* TABE個別部   					 */
