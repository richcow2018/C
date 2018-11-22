/****************************************************************************/
/* 		OCPのインクルードファイル											*/
/****************************************************************************/
 
#define  MOSPSIZE 0x00010000L
#define  MOSCMID  0x00060000L

#define  MOSTOP   1L
#define  MORSTAT  2L
#define  MOSTART  3L
#define  MOIPL    4L
#define  MODOWN   5L
#define  MOCHG    6L
#define  MOREV    5L

#define  MOMSGOK  0L
#define  MOMSGNG  1L

#define	 MOSETEXNUM 31L							/* ossetex2引数用				PRC-055-01 */
#define  MOINITSYS	0x00010001					/* os_initSystem 用引数			PRC-008-04 */

/****************************************************************************/
/* 		起動元プロセス情報													*/
/****************************************************************************/

struct mopinf{
    long             moogrsv;				/* リザーブ						*/
    unsigned char    moogkcl;				/* 系区分						*/
    unsigned char    moogrsv3;				/* リザーブ3					*/
    short            moogrsv4;				/* リザーブ4					*/
    unsigned char    moogpnm[8];			/* プロセス識別子				*/
    long             moogclno;				/* コンソール通番				*/
    long             moogrsv2;				/* リザーブ2					*/
	long			 moontcn;				/* 						TD01	*/
	long			 mooexmo;				/*						TD01	*/
};
typedef  struct  mopinf  MOPINF;

/****************************************************************************/
/* 		終了情報															*/
/****************************************************************************/

struct terminf{
    long             type;					/* 終了種別						*/
    long             code;					/* 終了コード					*/
    long             dtal;					/* 詳細情報						*/
};

