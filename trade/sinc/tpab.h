/*********************************************************************/
/*                                                                   */
/*             tpab.h 	    95.02.15 Tuboyaki                        */
/*                                                                   */
/*********************************************************************/

typedef struct  {                       /* ﾘﾝｸ情報配列要素            */
    char    tpablkst;                   /* 00:未使用 01:ｺﾈｸﾄ済み      */
    char    tpabyob2;           	    /* 予備                       */
    short   tpablgtn;                   /* TLGTｴﾝﾄﾘ番号               */
    short   tpablphn;                   /* TLPHｴﾝﾄﾘ番号               */
    short   tpablptn;                   /* TLPTｴﾝﾄﾘ番号               */
    long    tpabssop[2];                /* 適用ｼｽﾃﾑｵﾌﾟｼｮﾝ             */
    long    tpabyob3;           	    /* 予備                       */
} TPABPS;

typedef struct  {                       /* 個別部ﾍｯﾀﾞ                 */
    short   tpablkno;                   /* ﾘﾝｸ管理部ｺﾈｸﾄ済み数        */
    short   tpabyob1;           	    /* 予備                       */
} TPABPM;

typedef struct  {                       /* ｻﾌﾞ共通部                  */
    short   tpablmax;                   /* ﾘﾝｸ管理部配列最大要素数    */
    short   tpabyob0;           	    /* 予備                       */
} TPABSUB;
