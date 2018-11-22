/**********************************************************************/
/*                                                                    */
/*        TEOA ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ     teoa.h  			                  */
/*                                   							      */
/*                                                                    */
/**********************************************************************/
/*--------------------------------------------------------------------------*/
/* ＜ソース修正者名＞				 営業店システム部　山口(KSP)			*/
/* ＜ソース修正年月日及び修正ＩＤ＞  １９９８年０８月０４日			SPCY0128*/
/*	UINT応答[構成有り|構成なし]を定義するための項目を追加した				*/
/*--------------------------------------------------------------------------*/

struct teoasb {
        UWORD	osasmid;				/* OSASﾓｼﾞｭｰﾙID     */
        UWORD   teoayob0;               /* 予備0                      */
};
typedef struct teoasb TEOASUB;     	    /* TEOAサブ共通部         */

struct  teoako {
        UBYTE	asaplng;				/* ASAP ID長                  */
        UBYTE	teoacflg;				/* UINT受諾[構成有無]指定	SPCY0128*/
        UWORD	teoayob2;				/* 予備2			*/
        UBYTE	asapid[16];				/* ASAP ID			*/
        UWORD   teoairbn;   	        /* IRB数               */
        UWORD   teoatm11;       	    /* ﾀｲﾏ監視値(t11)             */
        UWORD   teoatm12;       	    /* ﾀｲﾏ監視値(t12)             */
        UWORD   teoatm15;       	    /* ﾀｲﾏ監視値(t15)             */
        UWORD   teoaussz;       	    /* UAT利用者情報長           */
        UWORD   teoayob3;       	    /* 予備3			   */
};
typedef struct  teoako TEOAPSZ;        	/* TEOA個別部   */

										/* teoacflg 指定値			SPCY0128*/
#define TEOACFG		1					/* 構成あり					SPCY0128*/
#define TEOANCFG	0					/* 構成なり					SPCY0128*/
