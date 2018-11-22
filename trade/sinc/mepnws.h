/**************************************/
/*                                    */
/*             mepnws.h               */
/*                                    */
/*          me_pnws ﾉ ﾍｯﾀﾞﾌｧｲﾙ        */
/*                                    */
/**************************************/
/**********************************************************************/
/*       ＜ソース修正者名＞                佐伯健吾                   */
/*       ＜ソース修正年月日及び修正ＩＤ＞  ２００３年７月０１日       */
/*                                          故障処理票TCBS0191        */
/*                                          論理回線グループ番号の返却*/
/*                                          機能の追加            M01 */
/**********************************************************************/

typedef struct  {                       /* ﾘﾝｸ情報配列要素            */
    char    mditype ;                   /* ﾘﾝｸ種別                    */
    char    mdyobi1[3] ;                /* 予備                       */
    long    mdsoptn[2] ;                /* 適用ｼｽﾃﾑｵﾌﾟｼｮﾝ             */
    short   mdlink1 ;                   /* 論理ﾊﾟｽ結合子1             */
    char    mdccnid ;                   /* 通信制御種別               */
    char    mdyobi2 ;                   /* 予備                       */
    char    mdhpuno ;                   /* ﾎｽﾄ回線PU番号              */
    char    mdhchno ;                   /* ﾎｽﾄ回線CH番号              */
    short   mdhllno ;                   /* ﾎｽﾄ論理回線番号            */
    short   mdhrcum ;                   /* RCUｱﾄﾞﾚｽ(ﾒｲﾝ)              */
    short   mdhrcus ;                   /* RCUｱﾄﾞﾚｽ(ｻﾌﾞ)              */
    short   mdlink2 ;                   /* 論理ﾊﾟｽ結合子2             */
/*  char    mdtpuno ;                   /* 端末回線PU番号  削除   M01 */
/*  char    mdtchno ;                   /* 端末回線CH番号  削除   M01 */
    char    mdtgrno ;                   /* 論理回線グループ番号   M01 */
    short   mdtllno ;                   /* 端末論理回線番号           */
    char    mdtlptn ;                   /* 端末LPN                    */
    char    mdtapic ;                   /* 端末APIｶﾃｺﾞﾘ               */
} MELINKI;

typedef struct {                        /* me_pnws()返却情報ﾍｯﾀﾞ      */
    short   mdrewsns;                   /* ﾜｰｸｽﾃｰｼｮﾝ ﾊﾞﾝｺﾞｳｽｳ         */
    short   mdreyob1;                   /* ﾖﾋﾞ                        */
    char    mdreprid[8];                /* ﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲ               */
} MELINKH;

typedef struct {						/* me_pnws()返却情報全体      */
	MELINKH mdh;						/* ﾍｯﾀﾞ                       */
	MELINKI mdi[256];					/* ﾘﾝｸ情報配列                */
} MELINKA;
                  
#define PSZADR(p1,p2)                                     \
				((long)(p1) + sizeof(TCOMPAT) +           \
			    (((TCOMPAT*)p1)->tcomsbps) +               \
				(((TCOMPAT*)p1)->tcomprsl)*((p2)-1))

