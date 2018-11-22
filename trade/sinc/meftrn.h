/****************************************************************************/
/*  ファイル転送機能にて使用するインタフェース領域の構造対定義              */
/*                                                                          */
/*                                                                          */
/* 修正		２００３年０４月１８日		ビジネス企画担当	佐治秀保		*/
/*	Linux化による修正（rd管理域個別部ｱﾄﾞﾚｽをFTOS情報管理域ｱﾄﾞﾚｽへ変更）	 M01*/
/****************************************************************************/
typedef struct fput_ifa{
    TLPTPSZ    *tlptpspp;               /* TLPT個別部ｱﾄﾞﾚｽ格納域            */
    MDFACKO    *tfacpspp;               /* TFAC個別部ｱﾄﾞﾚｽ格納域            */
    TFAPPSZ    *tfappspp;               /* TFAP個別部ｱﾄﾞﾚｽ格納域            */
    TPATPSZ    *tpatpspp;               /* TPAT個別部ｱﾄﾞﾚｽ格納域            */
    TFALPSZ    *tfalpspp;               /* TFAL個別部ｱﾄﾞﾚｽ格納域            */
    TFAXPSZ    *tfaxpspp;               /* TFAX個別部ｱﾄﾞﾚｽ格納域            */
    MDPATWS    *tpatpwsp;               /* TPATws管理部ｱﾄﾞﾚｽ格納域          */
    char       *creprpnm;               /* 起動ｺﾏﾝﾄﾞﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名ｱﾄﾞﾚｽ格納域*/
	MEFIMA	   *ftadarea;				/* FTOS情報管理域ｱﾄﾞﾚｽ格納域	 M01*/
    char       *lpnamept;               /* 論理ﾊﾟｽ識別名ｱﾄﾞﾚｽ格納域         */
    char       *orgfnamp;               /* 転送元ﾌｧｲﾙ名ｱﾄﾞﾚｽ格納域          */
    char       *dstfnamp;               /* 転送先ﾌｧｲﾙ名ｱﾄﾞﾚｽ格納域          */
    long        if_exist;               /* ﾌｧｲﾙ既存時処理指定格納域         */
    long        interval;               /* 転送ｲﾝﾀｰﾊﾞﾙﾀｲﾏ値                 */
    long		licpid;					/* LICP識別子					 M01*/
    char        iotype;                 /* ﾌﾟﾛﾄｺﾙ種別                       */
    char        dumy[3];                /* 予備                             */
} FTREXINF;
