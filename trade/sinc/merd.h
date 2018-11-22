/**********************************************/
/*                                            */
/*                 merd.h                     */
/*                                            */
/*            rd ｶﾝﾘｲｷ ﾌｫｰﾏｯﾄ                 */
/*											  */
/*		変更　95.5.18 AA	変更者 岡崎 香織  */
/*		変更　95.10.20 BB	変更者 新藤 由美  */
/*		変更　96.03.26 CC	変更者 新藤 由美  */
/*		変更　2003.02.17 DD	変更者 佐伯 健吾  */
/*                                            */
/**********************************************/
#define  RDUSATT  0x0104              /*使用目的(ｱﾃﾝｼｮﾝ通知要求)　   */
#define  RDUSHID  0x0105              /*使用目的(非同期通知要求)　   */
#define  RDUSMAIL 0x0201              /*使用目的(一般ﾒｰﾙ受信要求)    */
#define  RDUSTIM  0x0301              /*使用目的(ﾀｲﾏ登録)            */
#define  RDUSIOP  0x0101              /*使用目的(ﾙｰﾌﾟI/Oｵｰﾌﾟﾝ)　  　 */
#define  RDUS4OP  0x0102              /*使用目的(4W-NTMｵｰﾌﾟﾝ完了引継)*/
#define  RDUS4AT  0x0103              /*使用目的(4W-NTMｵｰﾌﾟﾝ時ATT待) */
#define  RDUSIRE  0x0106              /*使用目的(I/Oﾘｰﾄﾞ)            */
#define  RDUSIWR  0x0107              /*使用目的(I/Oﾗｲﾄ)　　         */
#define  RDUSIWS  0x0108              /*使用目的(I/Oﾗｲﾄ&ｾﾝｽ)         */
#define  RDUSISN  0x0109              /*使用目的(I/Oｾﾝｽ)　　         */
#define  RDUSICN  0x010A              /*使用目的(I/Oｺﾝﾄﾛｰﾙ)          */
/******************************/
/* ﾌｧｲﾙ送信機能追加の為の変更 */
/******************************/
#define  RDUSFSN  0x0401              /*使用目的(ﾌｧｲﾙ送信)           */
#define  RDUSFRV  0x0402              /*使用目的(ﾌｧｲﾙ受信)           */
/******************************/
/* 4W on X.25 の為の変更      */
/******************************/
#define  RDUS4WOP 0x0501              /*使用目的(4WonX.25 osiopen) AA*/
#define  RDUS4WRE 0x0502              /*使用目的(4WonX.25 osiread) AA*/
#define  RDUS4WCT 0x0503              /*使用目的(4WonX.25 control) AA*/
#define  RDUS4WWR 0x0504              /*使用目的(4WonX.25 W.R.待ち)AA*/
#define  RDUS4WRR 0x0505              /*使用目的(4WonX.25 W.R.待ち)AA*/
#define  RDUS4WCR 0x0506              /*使用目的(4WonX.25 W.R.待ち)AA*/
#define  RDUS4WSR 0x0507              /*使用目的(4WonX.25 W.R.待ち)AA*/
#define  RDUS4WHD 0x0508              /*使用目的(4WonX.25非同期通知)AA*/
#define  RDUS4WRCV 0x0509             /*目的(自動回復用ﾀｲﾏ) 	   CC*/
#define  RDUS4WROP 0x050a             /*目的(再オープン用ﾀｲﾏ) 	   CC*/
#define  RDUS4WRCT 0x050b             /*目的(呼設定リトライ用ﾀｲﾏ)  CC*/

/***********************************/
/* 4W on X.25(4W-NTM) の為の追加 BB*/
/***********************************/
#define  RDUS4WNOP 0x0601             /*使用目的(4WonX.25 osiopen) BB*/
#define  RDUS4WNRE 0x0602             /*使用目的(4WonX.25 osiread) BB*/
#define  RDUS4WNCT 0x0603             /*使用目的(4WonX.25 control) BB*/
#define  RDUS4WNWR 0x0604             /*使用目的(4WonX.25 W.R.待ち)BB*/
#define  RDUS4WNRR 0x0605             /*使用目的(4WonX.25 W.R.待ち)BB*/
#define  RDUS4WNCR 0x0606             /*使用目的(4WonX.25 W.R.待ち)BB*/
#define  RDUS4WNSR 0x0607             /*使用目的(4WonX.25 W.R.待ち)BB*/
#define  RDUS4WNHD 0x0608             /*使用目的(4WonX.25非同期通知)BB*/
#define  RDUS4WNIRT 0x0609            /*目的(4WonX.25IRT完了待ち) BB*/
#define  RDUS4WNRCV 0x060a            /*目的(自動回復用ﾀｲﾏ) 	   CC*/
#define  RDUS4WNROP 0x060b            /*目的(再オープン用ﾀｲﾏ) 	   CC*/
#define  RDUS4WNRCT 0x060c            /*目的(呼設定リトライ用ﾀｲﾏ)  CC*/

//**********************************//
// V7ホスト通信用					//
//**********************************//
#define	RDUSV7OPTM	0x0701				// 再オープンリトライタイマ用	DD

struct merdkyo {
	short	merdmax ;             /* ｻｲﾀﾞｲ RD ｶﾝﾘｽｳ              */
	short	merdent ;             /* RD ｶﾝﾘｽｳ                    */
};
typedef struct merdkyo MERDKYO;

struct merdko {
	short	merduse ;             /*使用目的                     */
	short	merdidno;             /*識別情報                     */
	long	merdrdid;             /*RD                           */
	short	merdsize;             /*固有情報ｻｲｽﾞ                 */
	short	merdtmid;             /*ﾀｲﾏ ID                       */
	long    merdurid;             /*ﾕｰｻﾞﾘｸｴｽﾄ識別子              */
    char    merdpinf[48];         /*固有情報　　　               */
};
typedef struct merdko MERDKO;
