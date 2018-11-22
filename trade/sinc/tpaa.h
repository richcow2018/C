/*********************************************************************/
/*                                                                   */
/*             tpaa.h 	                                             */
/*                                                                   */
/* (注) ﾘﾝｸ管理部配列は256要素で構造体定義しているが                 */
/*     実際のテーブルは、こうなるとは限らないので、                  */
/*     TPAAPSZに対してsizeof等を適用してはいけない。                 */
/*                                          1995,2,8 Sazae           */
/*********************************************************************/

typedef struct  {                       /* ﾘﾝｸ情報配列要素            */
    char    tpaalkst;                   /* 00:未使用 01:ｺﾈｸﾄ済み      */
    char    tpaayob2;           	    /* 予備                       */
    short   tpaalgtn;                   /* TLGTｴﾝﾄﾘ番号               */
    short   tpaalphn;                   /* TLPHｴﾝﾄﾘ番号               */
    short   tpaalptn;                   /* TLPTｴﾝﾄﾘ番号               */
    long    tpaassop[2];                /* 適用ｼｽﾃﾑｵﾌﾟｼｮﾝ             */
    long    tpaayob3;           	    /* 予備                       */
} TPAAPS;

typedef struct  {                       /* 個別部ﾍｯﾀﾞ                 */
    short   tpaalkno;                   /* ﾘﾝｸ管理部ｺﾈｸﾄ済み数        */
    short   tpaayob1;           	    /* 予備                       */
} TPAAPM;

typedef struct  {						/* 個別部全体                 */
	TPAAPM  tpaapm;						/* 個別部ﾍｯﾀﾞ                 */
	TPAAPS	tpaaps[256];				/* ﾘﾝｸ管理部配列              */
} TPAAPSZ;

typedef struct  {                       /* ｻﾌﾞ共通部                  */
    short   tpaalmax;                   /* ﾘﾝｸ管理部配列最大要素数    */
    short   tpaayob0;           	    /* 予備                       */
} TPAASUB;
