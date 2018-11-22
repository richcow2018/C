/****************************************************************************/
/* ﾌｧｲﾙ名　：　mi_abort.h                                                   */
/* 機能　　：  ｱﾎﾞｰﾄ詳細情報上1ﾊﾞｲﾄ                                         */
/*             ﾌﾟﾛｾｽｱﾎﾞｰﾄﾏｸﾛ                                                */
/*             ﾓｼﾞｭｰﾙID（拡張）                                             */
/* 作成日　：  1992.01.07                                                   */
/* 変更日　：  1994.10.14                                               PD0A*/
/*   故障処理票(ST1761) 統合Ｉ／Ｏ対応                                      */
/* 変更日　：  1995.03.31                                               PD0B*/
/*   故障処理票(ST2144) ISDN呼切断時切断通知発行                            */
/* 変更日　　：  1995.06.13                                             PD0C*/
/*   仕様変更要求書(SSCY0062) 動的システム変更対応                          */
/* 変更日　　：  1995.09.29                                             PD01*/
/*   故障処理票(ST3504) 障害回線に対してﾘﾄﾗｲを行うよう修正                  */
/* 変更日　　：  1995.09.29                                             PD0J*/
/*   仕様変更要求書(SSCY0113) ４Ｗ故障検出変更対応                          */
/* 変更日　  ：  1995.10.13                                             PD02*/
/*   故障処理票(ST3572) 障害検出時ｸﾛｰｽﾞ待ち追加                             */
/* 変更日　　：  1995.11.29                                             PD0O*/
/*   仕様変更要求書(SSCY0063) ＬＩＣＰ再起動対応                            */
/* 変更日　　：  1995.02.01                                              M01*/
/*   仕様変更要求書(ST3978  ) アボートコード設定ミス                        */
/* 変更日　　：  1996.03.05                                             PD0R*/ 
/*   仕様変更要求書(SSCY0156) X.25回復監視変更対応                          */ 
/* 変更日　　：  1997.02.27                                             PD0W*/ 
/*   故障処理票(ST4648) mia12120()追加                                      */
/* 変更日　　：  1997.03.17                                             PD0Y*/ 
/*   故障処理票(ST4810) miae0000()追加                                      */
/* 変更日　　：  1997.05.12                                             PD0Z*/ 
/*   故障処理票(ST4834) mia25000(),mia25001(),mia25002()追加                */
/* 変更日　　：  1998.02.16                                         SSCY0203*/ 
/*   仕様変更要求書(SSCY0203) 代行中故障Ｂｕ回線の再使用					*/
/* 変更日　　：  1998.03.16                                           ST5113*/ 
/*   故障処理票(ST5113) mia00013()追加                                      */
/****************************************************************************/
/* ＜ソース修正者＞                  営業店システム担当　山口(KSP)          */
/* ＜ソース修正年月日及び修正ＩＤ＞  ２０００年１０月２３日         ST6007  */
/*   アボートコードが正しく編集される様マクロMIAPABTを修正した				*/
/*--------------------------------------------------------------------------*/
/**************************************/
/* ｱﾎﾞｰﾄ詳細情報上1ﾊﾞｲﾄ               */
/**************************************/
/********************/
/* SG値不正         */
/********************/
#define ABTINVSG    0x01                /* SG値不正                         */

/**************************************/
/* 論理エラー                         */
/**************************************/
#define ABTLMTX     0x05                /* マトリクス矛盾                   */
#define ABTCONN     0x10                /* osconn                           */
#define ABTDCONN    0x11                /* osdconn                          */
#define ABTLOPEN    0x12                /* osiopen                          */
#define ABTLCLOS    0x13                /* osiclose                         */
#define ABTGFINF    0x14                /* osgfinf                          */
#define ABTCONFI    0x15                /* osconfig                         */
#define ABTSENMS    0x16                /* ossenmsp                         */
#define ABTDELET    0x17                /* osdelet                          */
#define ABTMKNOD    0x18                /* osmknod                          */
#define ABTLTEST    0x20                /* 折返設定要求                     */
#define ABTTMRST    0x21                /* 折返解除要求                     */
#define ABTCHAKU    0x22                /* 着呼要求                         */
#define ABTHAKKO    0x23                /* 発呼要求                         */
#define ABTASYNC    0x24                /* 非同期通知要求                   */
#define ABTDATAS    0x25                /* 折返試験ﾃﾞｰﾀ送信要求             */
#define ABTGTIOS    0x26                /* osgetios                         */
#define ABTLDCON    0x27                /* 切断要求                     PD0A*/
#define ABTDESPR    0x28                /* プロセス終了                 PD0O*/
#define ABTDLSET    0x29                /* ﾃﾞｰﾀﾘﾝｸ再設定                PD0R*/
/**************************************/
/* ハードエラー(ﾀﾞｳﾝｺｰﾄﾞ詳細情報)     */
/**************************************/
#define DOWNSYNC1   0x31000000          /* 非同期通知要求(4W)           PD0A*/
#define DOWNSYNC2   0x32000000          /* 非同期通知要求(HDLC LOOP)    PD0A*/
#define DOWNSYNC3   0x33000000          /* 非同期通知要求(TEL)          PD0A*/
#define DOWNSYNC4   0x34000000          /* 非同期通知要求(Bu)           PD0A*/
#define DOWNSYNC5   0x35000000          /* 非同期通知要求(LAN)          PD0A*/
#define DOWNSYNC6   0x36000000          /* 非同期通知要求(X.25)         PD0A*/
#define DOWNOPEN1   0x41000000          /* osiopen(4W)                  PD0A*/
#define DOWNOPEN2   0x42000000          /* osiopen(HDLC LOOP)           PD0A*/
#define DOWNOPEN3   0x43000000          /* osiopen(LAN)                 PD0A*/
#define DOWNOPEN4   0x44000000          /* osiopen(X.25)                PD0A*/
#define DOWNOPEN5   0x45000000          /* osiopen(X.25H)               PD0A*/
#define DOWNOPEN6   0x46000000          /* osiopen(TELH)                PD0A*/
/**************************************/
/* その他のエラー                     */
/**************************************/
#define ABTOGTBF    0xE0                /* サービスコール異常(mo_gtbf)　    */
#define ABTONCLR    0xE1                /* サービスコール異常(mc_nclr)　    */
#define ABTOFRBF    0xE2                /* サービスコール異常(mo_frbf)　    */
#define ABTORTGT    0xE3                /* サービスコール異常(mf_rtgt)　    */
#define ABTORENQ    0xE4                /* サービスコール異常(mf_renq)　    */
#define ABTORDEQ    0xE5                /* サービスコール異常(mf_rdeq)　    */
#define ABTOBCCN    0xE6                /* サービスコール異常(mc_bccn)　    */
#define ABTOHCCN    0xE7                /* サービスコール異常(mc_hccn)　    */
#define ABTOIENT    0xE8                /* サービスコール異常(ms_ient)　    */
#define ABTOIRES    0xE9                /* サービスコール異常(ms_ires)　    */
#define ABTOIEND    0xEa                /* サービスコール異常(ms_iend)　    */
#define ABTOUWTO    0xEb                /* サービスコール異常(ms_uwto)      */
#define ABTOCOPY    0xEc                /* サービスコール異常(mc_copy)      */
#define ABTOCCOM    0xEd                /* サービスコール異常(mc_ccom)      */
#define ABTOMBID    0xEe                /* サービスコール異常(mi_mbid)      */
#define ABTOCBCN    0xF0                /* サービスコール異常(mc_cbcn)      */
#define ABTOSETN    0xF1                /* サービスコール異常(mc_setn)      */
#define ABTODELN    0xF2                /* サービスコール異常(mc_deln)      */
#define ABTONTAB    0xF3                /* サービスコール異常(mc_ntab)      */
#define ABTOCONN    0xF4                /* サービスコール異常(mc_conn)      */
/********************/
/* ﾌﾟﾛｸﾞﾗﾑｴﾗｰ       */
/********************/
#define ABTPGMER    0x60                /* ﾌﾟﾛｸﾞﾗﾑｴﾗｰ                       */

/********************/
/* ｲﾍﾞﾝﾄ異常        */
/********************/
#define ABTINVEV    0x70                /* ｲﾍﾞﾝﾄ異常                        */

/**************************************/
/* モジュールＩＤ                     */
/**************************************/
#define MID_EX       0x67ff0000         /* miaﾓｼﾞｭｰﾙID                      */

#define STATEVNT(P1, P2)    ((long)P1<<8)|(long)P2
#define ABT_NULL     0x0                
/****************************************************************************/
/*																			*/
/* ＜マクロ名＞  MIAPABT													*/
/*																			*/
/* ＜機能概要＞  アボート処理を行う											*/
/*																			*/
/* ＜仮引数＞																*/
/*	   P1	     詳細情報													*/
/*	   P2	     任意値１ 													*/
/*	   P3	     モジュールＩＤ（拡張モジュールＩＤの下２桁）				*/
/*	   P4	     任意値２ 													*/
/****************************************************************************/
#define MIAPABT(P1, P2, P3, P4) 		/* アボート処理 					*/\
{                                                                             \
	extern   long   mc_lsch(long);                                            \
	(void)mc_lsch(0);                                                         \
	MCS_ABEX((MID_EX | ((unsigned long)(P3) & 0x0000ffff)), P1, P2, P4);	  \
	/* M01 ST6007 */														  \
}
										/* プロセスアボートマクロ			*/
/**************************************/
/* モジュールＩＤ（拡張）             */
/**************************************/
#define   MIA00001  0x0000              /* mia00001() のﾓｼﾞｭｰﾙID            */
#define   MIA00002  0x0001              /* mia00002() のﾓｼﾞｭｰﾙID            */
#define   MIA00003  0x0002              /* mia00003() のﾓｼﾞｭｰﾙID            */
#define   MIA00004  0x0003              /* mia00004() のﾓｼﾞｭｰﾙID            */
#define   MIA00005  0x0004              /* mia00005() のﾓｼﾞｭｰﾙID            */
#define   MIA00006  0x0005              /* mia00006() のﾓｼﾞｭｰﾙID            */
#define   MIA00008  0x0007              /* mia00008() のﾓｼﾞｭｰﾙID            */
#define   MIA00009  0x000f              /* mia00009() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA00010  0x000e              /* mia00010() のﾓｼﾞｭｰﾙID            */
#define   MIA00011  0x0008              /* mia00011() のﾓｼﾞｭｰﾙID            */
#define   MIA00012  0x0009              /* mia00012() のﾓｼﾞｭｰﾙID            */
#define   MIA00013  0x001a              /* mia00013() のﾓｼﾞｭｰﾙID      ST5113*/
#define   MIA00016  0x000a              /* mia00016() のﾓｼﾞｭｰﾙID            */
#define   MIA00018  0x000b              /* mia00018() のﾓｼﾞｭｰﾙID            */
#define   MIA00019  0x000c              /* mia00019() のﾓｼﾞｭｰﾙID            */
#define   MIA00020  0x000d              /* mia00020() のﾓｼﾞｭｰﾙID            */
#define   MIA00021  0x0035              /* mia00021() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00022  0x0036              /* mia00022() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00023  0x0037              /* mia00023() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00024  0x0038              /* mia00024() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00025  0x0039              /* mia00025() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00027  0x003b              /* mia00027() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00028  0x003c              /* mia00028() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00029  0x003d              /* mia00029() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00030  0x0042              /* mia00030() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA00031  0x0043              /* mia00031() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA00040  0x004b              /* mia00040() のﾓｼﾞｭｰﾙID        PD01*/
#define   MIA00041  0x004c              /* mia00041() のﾓｼﾞｭｰﾙID        PD01*/
#define   MIA00042  0x004d              /* mia00042() のﾓｼﾞｭｰﾙID    SSCY0203*/
#define   MIA00050  0x0010              /* mia00050() のﾓｼﾞｭｰﾙID            */
#define   MIA00051  0x0011              /* mia00051() のﾓｼﾞｭｰﾙID            */
#define   MIA00052  0x0012              /* mia00052() のﾓｼﾞｭｰﾙID            */
#define   MIA00053  0x0013              /* mia00053() のﾓｼﾞｭｰﾙID            */
#define   MIA00054  0x0014              /* mia00054() のﾓｼﾞｭｰﾙID            */
#define   MIA00055  0x0015              /* mia00055() のﾓｼﾞｭｰﾙID            */
#define   MIA00056  0x0016              /* mia00056() のﾓｼﾞｭｰﾙID            */
#define   MIA00057  0x0017              /* mia00057() のﾓｼﾞｭｰﾙID            */
#define   MIA00058  0x0018              /* mia00058() のﾓｼﾞｭｰﾙID            */
#define   MIA00059  0x0019              /* mia00059() のﾓｼﾞｭｰﾙID            */
#define   MIA00060  0x0020              /* mia00060() のﾓｼﾞｭｰﾙID            */
#define   MIA00061  0x0021              /* mia00061() のﾓｼﾞｭｰﾙID            */
#define   MIA00062  0x0022              /* mia00062() のﾓｼﾞｭｰﾙID            */
#define   MIA00063  0x0023              /* mia00063() のﾓｼﾞｭｰﾙID            */
#define   MIA00064  0x0024              /* mia00064() のﾓｼﾞｭｰﾙID            */
#define   MIA00065  0x0025              /* mia00065() のﾓｼﾞｭｰﾙID            */
#define   MIA00066  0x003e              /* mia00066() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00067  0x003f              /* mia00067() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00068  0x0040              /* mia00068() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00069  0x0041              /* mia00069() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA00100  0x0026              /* mia00100() のﾓｼﾞｭｰﾙID            */
#define   MIA00101  0x0027              /* mia00101() のﾓｼﾞｭｰﾙID            */
#define   MIA00102  0x0028              /* mia00102() のﾓｼﾞｭｰﾙID            */
#define   MIA00103  0x0029              /* mia00103() のﾓｼﾞｭｰﾙID            */
#define   MIA00104  0x002a              /* mia00104() のﾓｼﾞｭｰﾙID            */
#define   MIA00105  0x002b              /* mia00105() のﾓｼﾞｭｰﾙID            */
#define   MIA00106  0x002c              /* mia00106() のﾓｼﾞｭｰﾙID            */
#define   MIA00107  0x002d              /* mia00107() のﾓｼﾞｭｰﾙID            */
#define   MIA00108  0x002e              /* mia00108() のﾓｼﾞｭｰﾙID            */
#define   MIA00109  0x002f              /* mia00109() のﾓｼﾞｭｰﾙID            */
#define   MIA00110  0x0034              /* mia00110() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA00150  0x0030              /* mia00150() のﾓｼﾞｭｰﾙID            */
#define   MIA00151  0x0031              /* mia00151() のﾓｼﾞｭｰﾙID            */
#define   MIA00152  0x0032              /* mia00152() のﾓｼﾞｭｰﾙID            */
#define   MIA00153  0x0033              /* mia00153() のﾓｼﾞｭｰﾙID            */
#define   MIA00200  0x0044              /* mia00200() のﾓｼﾞｭｰﾙID      stPD0C*/
#define   MIA00201  0x0045              /* mia00201() のﾓｼﾞｭｰﾙID            */
#define   MIA00202  0x0046              /* mia00202() のﾓｼﾞｭｰﾙID            */
#define   MIA00203  0x0047              /* mia00203() のﾓｼﾞｭｰﾙID            */
#define   MIA00204  0x0048              /* mia00204() のﾓｼﾞｭｰﾙID            */
#define   MIA00205  0x0049              /* mia00205() のﾓｼﾞｭｰﾙID            */
#define   MIA00206  0x004a              /* mia00206() のﾓｼﾞｭｰﾙID      edPD0C*/
#define   MIA11000  0x1000              /* mia11000() のﾓｼﾞｭｰﾙID            */
#define   MIA12000  0x1001              /* mia12000() のﾓｼﾞｭｰﾙID            */
#define   MIA12010  0x1002              /* mia12010() のﾓｼﾞｭｰﾙID            */
#define   MIA12100  0x1003              /* mia12100() のﾓｼﾞｭｰﾙID            */
#define   MIA12110  0x1004              /* mia12110() のﾓｼﾞｭｰﾙID            */
#define   MIA12200  0x1005              /* mia12200() のﾓｼﾞｭｰﾙID            */
#define   MIA12201  0x1008              /* mia12201() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA12120  0x1009              /* mia12120() のﾓｼﾞｭｰﾙID        PD0W*/
#define   MIA13000  0x1006              /* mia13000() のﾓｼﾞｭｰﾙID            */
#define   MIA14000  0x1007              /* mia14000() のﾓｼﾞｭｰﾙID            */
#define   MIA20000  0x2000              /* mia20000() のﾓｼﾞｭｰﾙID            */
#define   MIA20001  0x2001              /* mia20001() のﾓｼﾞｭｰﾙID            */
#define   MIA20002  0x2002              /* mia20002() のﾓｼﾞｭｰﾙID            */
#define   MIA20003  0x2003              /* mia20003() のﾓｼﾞｭｰﾙID            */
#define   MIA20004  0x2004              /* mia20004() のﾓｼﾞｭｰﾙID            */
#define   MIA20005  0x2005              /* mia20005() のﾓｼﾞｭｰﾙID            */
#define   MIA20006  0x2006              /* mia20006() のﾓｼﾞｭｰﾙID            */
#define   MIA20007  0x2007              /* mia20007() のﾓｼﾞｭｰﾙID            */
#define   MIA20010  0x2010              /* mia20010() のﾓｼﾞｭｰﾙID            */
#define   MIA20011  0x2011              /* mia20011() のﾓｼﾞｭｰﾙID            */
#define   MIA20012  0x2012              /* mia20012() のﾓｼﾞｭｰﾙID            */
#define   MIA20013  0x2030              /* mia20013() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA20020  0x2031              /* mia20020() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA20040  0x2038              /* mia20040() のﾓｼﾞｭｰﾙID        PD01*/
#define   MIA21000  0x2013              /* mia21000() のﾓｼﾞｭｰﾙID            */
#define   MIA21001  0x2014              /* mia21001() のﾓｼﾞｭｰﾙID            */
#define   MIA21002  0x2015              /* mia21002() のﾓｼﾞｭｰﾙID            */
#define   MIA21003  0x2016              /* mia21003() のﾓｼﾞｭｰﾙID            */
#define   MIA21004  0x2017              /* mia21004() のﾓｼﾞｭｰﾙID            */
#define   MIA21005  0x2018              /* mia21005() のﾓｼﾞｭｰﾙID            */
#define   MIA21006  0x2019              /* mia21006() のﾓｼﾞｭｰﾙID            */
#define   MIA21007  0x201a              /* mia21007() のﾓｼﾞｭｰﾙID            */
#define   MIA21008  0x201b              /* mia21008() のﾓｼﾞｭｰﾙID            */
#define   MIA21009  0x201c              /* mia21009() のﾓｼﾞｭｰﾙID            */
#define   MIA21010  0x201d              /* mia21010() のﾓｼﾞｭｰﾙID            */
#define   MIA21011  0x201e              /* mia21011() のﾓｼﾞｭｰﾙID            */
#define   MIA21012  0x201f              /* mia21012() のﾓｼﾞｭｰﾙID            */
#define   MIA22000  0x2020              /* mia22000() のﾓｼﾞｭｰﾙID            */
#define   MIA22001  0x2021              /* mia22001() のﾓｼﾞｭｰﾙID            */
#define   MIA22002  0x2022              /* mia22002() のﾓｼﾞｭｰﾙID            */
#define   MIA22003  0x2023              /* mia22003() のﾓｼﾞｭｰﾙID            */
#define   MIA22004  0x2024              /* mia22004() のﾓｼﾞｭｰﾙID            */
#define   MIA22005  0x2025              /* mia22005() のﾓｼﾞｭｰﾙID            */
#define   MIA22006  0x2026              /* mia22006() のﾓｼﾞｭｰﾙID            */
#define   MIA22007  0x2027              /* mia22007() のﾓｼﾞｭｰﾙID            */
#define   MIA22008  0x2028              /* mia22008() のﾓｼﾞｭｰﾙID            */
#define   MIA22009  0x2029              /* mia22009() のﾓｼﾞｭｰﾙID            */
#define   MIA22010  0x202a              /* mia22010() のﾓｼﾞｭｰﾙID            */
#define   MIA22011  0x202b              /* mia22011() のﾓｼﾞｭｰﾙID            */
#define   MIA22012  0x202c              /* mia22012() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA22013  0x202f              /* mia22013() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA23000  0x202d              /* mia23000() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA23001  0x202e              /* mia23001() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA24000  0x202f              /* mia24000() のﾓｼﾞｭｰﾙID      stPD0C*/
#define   MIA24001  0x2036              /* mia24001() のﾓｼﾞｭｰﾙID            */
#define   MIA24100  0x2037              /* mia24100() のﾓｼﾞｭｰﾙID            */
#define   MIA24101  0x2032              /* mia24101() のﾓｼﾞｭｰﾙID            */
#define   MIA24200  0x2033              /* mia24200() のﾓｼﾞｭｰﾙID            */
#define   MIA24201  0x2034              /* mia24201() のﾓｼﾞｭｰﾙID            */
#define   MIA24202  0x2035              /* mia24202() のﾓｼﾞｭｰﾙID      edPD0C*/
#define   MIA25000  0x2035              /* mia25000() のﾓｼﾞｭｰﾙID      stPD0Z*/
#define   MIA25001  0x2035              /* mia25001() のﾓｼﾞｭｰﾙID            */
#define   MIA25002  0x2035              /* mia25002() のﾓｼﾞｭｰﾙID      edPD0Z*/
#define   MIA30000  0x3000              /* mia30000() のﾓｼﾞｭｰﾙID            */
#define   MIA30001  0x3001              /* mia30001() のﾓｼﾞｭｰﾙID            */
#define   MIA30002  0x3002              /* mia30002() のﾓｼﾞｭｰﾙID            */
#define   MIA30003  0x3003              /* mia30003() のﾓｼﾞｭｰﾙID            */
#define   MIA30004  0x3004              /* mia30004() のﾓｼﾞｭｰﾙID            */
#define   MIA31000  0x3005              /* mia31000() のﾓｼﾞｭｰﾙID            */
#define   MIA32000  0x3006              /* mia32000() のﾓｼﾞｭｰﾙID            */
#define   MIA40000  0x4000              /* mia40000() のﾓｼﾞｭｰﾙID            */
#define   MIA40001  0x4001              /* mia40001() のﾓｼﾞｭｰﾙID            */
#define   MIA40005  0x4002              /* mia40005() のﾓｼﾞｭｰﾙID            */
#define   MIA40006  0x4003              /* mia40006() のﾓｼﾞｭｰﾙID            */
#define   MIA40007  0x4004              /* mia40007() のﾓｼﾞｭｰﾙID            */
#define   MIA40008  0x4005              /* mia40008() のﾓｼﾞｭｰﾙID            */
#define   MIA40009  0x406d              /* mia40009() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA40100  0x4071              /* mia40100() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA40105  0x4010              /* mia40105() のﾓｼﾞｭｰﾙID            */
#define   MIA40107  0x4011              /* mia40107() のﾓｼﾞｭｰﾙID            */
#define   MIA40108  0x4012              /* mia40108() のﾓｼﾞｭｰﾙID            */
#define   MIA40109  0x4013              /* mia40109() のﾓｼﾞｭｰﾙID            */
#define   MIA40152  0x4014              /* mia40152() のﾓｼﾞｭｰﾙID            */
#define   MIA40200  0x4072              /* mia40200() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA40205  0x4015              /* mia40205() のﾓｼﾞｭｰﾙID            */
#define   MIA40207  0x4016              /* mia40207() のﾓｼﾞｭｰﾙID            */
#define   MIA40208  0x4017              /* mia40208() のﾓｼﾞｭｰﾙID            */
#define   MIA40209  0x4018              /* mia40209() のﾓｼﾞｭｰﾙID            */
#define   MIA40252  0x4019              /* mia40252() のﾓｼﾞｭｰﾙID            */
#define   MIA40300  0x4073              /* mia40300() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA40305  0x401a              /* mia40305() のﾓｼﾞｭｰﾙID            */
#define   MIA40307  0x401b              /* mia40307() のﾓｼﾞｭｰﾙID            */
#define   MIA40308  0x401c              /* mia40308() のﾓｼﾞｭｰﾙID            */
#define   MIA40309  0x401d              /* mia40309() のﾓｼﾞｭｰﾙID            */
#define   MIA40352  0x401e              /* mia40352() のﾓｼﾞｭｰﾙID            */
#define   MIA40400  0x4074              /* mia40400() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA40405  0x401f              /* mia40405() のﾓｼﾞｭｰﾙID            */
#define   MIA40407  0x4020              /* mia40407() のﾓｼﾞｭｰﾙID            */
#define   MIA40408  0x4021              /* mia40408() のﾓｼﾞｭｰﾙID            */
#define   MIA40409  0x4022              /* mia40409() のﾓｼﾞｭｰﾙID            */
#define   MIA40452  0x4023              /* mia40452() のﾓｼﾞｭｰﾙID            */
#define   MIA40500  0x4075              /* mia40500() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA40501  0x4024              /* mia40501() のﾓｼﾞｭｰﾙID            */
#define   MIA40502  0x4025              /* mia40502() のﾓｼﾞｭｰﾙID            */
#define   MIA40505  0x4026              /* mia40505() のﾓｼﾞｭｰﾙID            */
#define   MIA40507  0x4027              /* mia40507() のﾓｼﾞｭｰﾙID            */
#define   MIA40508  0x4028              /* mia40508() のﾓｼﾞｭｰﾙID            */
#define   MIA40509  0x4029              /* mia40509() のﾓｼﾞｭｰﾙID            */
#define   MIA40552  0x402a              /* mia40552() のﾓｼﾞｭｰﾙID            */
#define   MIA40624  0x402b              /* mia40624() のﾓｼﾞｭｰﾙID            */
#define   MIA40628  0x402c              /* mia40628() のﾓｼﾞｭｰﾙID            */
#define   MIA40722  0x402d              /* mia40722() のﾓｼﾞｭｰﾙID            */
#define   MIA40723  0x402e              /* mia40723() のﾓｼﾞｭｰﾙID            */
#define   MIA40724  0x402f              /* mia40724() のﾓｼﾞｭｰﾙID            */
#define   MIA40728  0x4030              /* mia40728() のﾓｼﾞｭｰﾙID            */
#define   MIA40911  0x4031              /* mia40911() のﾓｼﾞｭｰﾙID            */
#define   MIA40919  0x4032              /* mia40919() のﾓｼﾞｭｰﾙID            */
#define   MIA40927  0x4033              /* mia40927() のﾓｼﾞｭｰﾙID            */
#define   MIA40935  0x4034              /* mia40935() のﾓｼﾞｭｰﾙID            */
#define   MIA40942  0x4035              /* mia40942() のﾓｼﾞｭｰﾙID            */
#define   MIA40950  0x4036              /* mia40950() のﾓｼﾞｭｰﾙID            */
#define   MIA40951  0x4037              /* mia40951() のﾓｼﾞｭｰﾙID            */
#define   MIA40954  0x406e              /* mia40954() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA41101  0x403f              /* mia41101() のﾓｼﾞｭｰﾙID            */
#define   MIA41107  0x4040              /* mia41107() のﾓｼﾞｭｰﾙID            */
#define   MIA41112  0x4041              /* mia41112() のﾓｼﾞｭｰﾙID            */
#define   MIA41120  0x4042              /* mia41120() のﾓｼﾞｭｰﾙID            */
#define   MIA41129  0x4043              /* mia41129() のﾓｼﾞｭｰﾙID            */
#define   MIA41136  0x4044              /* mia41136() のﾓｼﾞｭｰﾙID            */
#define   MIA41143  0x4045              /* mia41143() のﾓｼﾞｭｰﾙID            */
#define   MIA41205  0x4046              /* mia41205() のﾓｼﾞｭｰﾙID            */
#define   MIA41210  0x4047              /* mia41210() のﾓｼﾞｭｰﾙID            */
#define   MIA41217  0x4048              /* mia41217() のﾓｼﾞｭｰﾙID            */
#define   MIA41218  0x4049              /* mia41218() のﾓｼﾞｭｰﾙID            */
#define   MIA41225  0x404a              /* mia41225() のﾓｼﾞｭｰﾙID            */
#define   MIA41226  0x404b              /* mia41226() のﾓｼﾞｭｰﾙID            */
#define   MIA41233  0x404c              /* mia41233() のﾓｼﾞｭｰﾙID            */
#define   MIA41234  0x404d              /* mia41234() のﾓｼﾞｭｰﾙID            */
#define   MIA41240  0x404e              /* mia41240() のﾓｼﾞｭｰﾙID            */
#define   MIA41241  0x404f              /* mia41241() のﾓｼﾞｭｰﾙID            */
#define   MIA41247  0x4050              /* mia41247() のﾓｼﾞｭｰﾙID            */
#define   MIA41253  0x406f              /* mia41253() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA41302  0x4051              /* mia41302() のﾓｼﾞｭｰﾙID            */
#define   MIA41309  0x4052              /* mia41309() のﾓｼﾞｭｰﾙID            */
#define   MIA41415  0x4053              /* mia41415() のﾓｼﾞｭｰﾙID            */
#define   MIA41516  0x4054              /* mia41516() のﾓｼﾞｭｰﾙID            */
#define   MIA41622  0x4055              /* mia41622() のﾓｼﾞｭｰﾙID            */
#define   MIA41731  0x4056              /* mia41731() のﾓｼﾞｭｰﾙID            */
#define   MIA41738  0x4057              /* mia41738() のﾓｼﾞｭｰﾙID            */
#define   MIA41745  0x4058              /* mia41745() のﾓｼﾞｭｰﾙID            */
#define   MIA41808  0x4059              /* mia41808() のﾓｼﾞｭｰﾙID            */
#define   MIA41809  0x405a              /* mia41809() のﾓｼﾞｭｰﾙID            */
#define   MIA41811  0x405b              /* mia41811() のﾓｼﾞｭｰﾙID            */
#define   MIA41813  0x405c              /* mia41813() のﾓｼﾞｭｰﾙID            */
#define   MIA41814  0x405d              /* mia41814() のﾓｼﾞｭｰﾙID            */
#define   MIA41819  0x405e              /* mia41819() のﾓｼﾞｭｰﾙID            */
#define   MIA41821  0x405f              /* mia41821() のﾓｼﾞｭｰﾙID            */
#define   MIA41823  0x4060              /* mia41823() のﾓｼﾞｭｰﾙID            */
#define   MIA41827  0x4061              /* mia41827() のﾓｼﾞｭｰﾙID            */
#define   MIA41830  0x4062              /* mia41830() のﾓｼﾞｭｰﾙID            */
#define   MIA41832  0x4063              /* mia41832() のﾓｼﾞｭｰﾙID            */
#define   MIA41835  0x4064              /* mia41835() のﾓｼﾞｭｰﾙID            */
#define   MIA41837  0x4065              /* mia41837() のﾓｼﾞｭｰﾙID            */
#define   MIA41839  0x4066              /* mia41839() のﾓｼﾞｭｰﾙID            */
#define   MIA41842  0x4067              /* mia41842() のﾓｼﾞｭｰﾙID            */
#define   MIA41844  0x4068              /* mia41844() のﾓｼﾞｭｰﾙID            */
#define   MIA41846  0x4069              /* mia41846() のﾓｼﾞｭｰﾙID            */
#define   MIA41850  0x406a              /* mia41850() のﾓｼﾞｭｰﾙID            */
#define   MIA41851  0x406b              /* mia41851() のﾓｼﾞｭｰﾙID            */
#define   MIA41854  0x4070              /* mia41854() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA49999  0x406c              /* mia49999() のﾓｼﾞｭｰﾙID            */
#define   MIA50000  0x5000              /* mia50000() のﾓｼﾞｭｰﾙID            */
#define   MIA50001  0x5001              /* mia50001() のﾓｼﾞｭｰﾙID            */
#define   MIA50005  0x5002              /* mia50005() のﾓｼﾞｭｰﾙID            */
#define   MIA50006  0x5003              /* mia50006() のﾓｼﾞｭｰﾙID            */
#define   MIA50007  0x5004              /* mia50007() のﾓｼﾞｭｰﾙID            */
#define   MIA50008  0x5005              /* mia50008() のﾓｼﾞｭｰﾙID            */
#define   MIA50009  0x506d              /* mia50009() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA50010  0x5107              /* mia50010() のﾓｼﾞｭｰﾙID    SSCY0203*/
#define   MIA50104  0x510a              /* mia50104() のﾓｼﾞｭｰﾙID    SSCY0203*/
#define   MIA50105  0x5010              /* mia50105() のﾓｼﾞｭｰﾙID            */
#define   MIA50106  0x5100              /* mia50106() のﾓｼﾞｭｰﾙID            */
#define   MIA50107  0x5011              /* mia50107() のﾓｼﾞｭｰﾙID            */
#define   MIA50108  0x5012              /* mia50108() のﾓｼﾞｭｰﾙID            */
#define   MIA50109  0x5013              /* mia50109() のﾓｼﾞｭｰﾙID            */
#define   MIA50152  0x5014              /* mia50152() のﾓｼﾞｭｰﾙID            */
#define   MIA50205  0x5015              /* mia50205() のﾓｼﾞｭｰﾙID            */
#define   MIA50206  0x5101              /* mia50206() のﾓｼﾞｭｰﾙID            */
#define   MIA50207  0x5016              /* mia50207() のﾓｼﾞｭｰﾙID            */
#define   MIA50208  0x5017              /* mia50208() のﾓｼﾞｭｰﾙID            */
#define   MIA50209  0x5018              /* mia50209() のﾓｼﾞｭｰﾙID            */
#define   MIA50252  0x5019              /* mia50252() のﾓｼﾞｭｰﾙID            */
#define   MIA50305  0x501a              /* mia50305() のﾓｼﾞｭｰﾙID            */
#define   MIA50306  0x5102              /* mia50306() のﾓｼﾞｭｰﾙID            */
#define   MIA50307  0x501b              /* mia50307() のﾓｼﾞｭｰﾙID            */
#define   MIA50308  0x501c              /* mia50308() のﾓｼﾞｭｰﾙID            */
#define   MIA50309  0x501d              /* mia50309() のﾓｼﾞｭｰﾙID            */
#define   MIA50352  0x501e              /* mia50352() のﾓｼﾞｭｰﾙID            */
#define   MIA50405  0x501f              /* mia50405() のﾓｼﾞｭｰﾙID            */
#define   MIA50406  0x5103              /* mia50406() のﾓｼﾞｭｰﾙID            */
#define   MIA50407  0x5020              /* mia40407() のﾓｼﾞｭｰﾙID            */
#define   MIA50408  0x5021              /* mia50408() のﾓｼﾞｭｰﾙID            */
#define   MIA50409  0x5022              /* mia50409() のﾓｼﾞｭｰﾙID            */
#define   MIA50452  0x5023              /* mia50452() のﾓｼﾞｭｰﾙID            */
#define   MIA50501  0x5024              /* mia50501() のﾓｼﾞｭｰﾙID            */
#define   MIA50502  0x5025              /* mia50502() のﾓｼﾞｭｰﾙID            */
#define   MIA50505  0x5026              /* mia50505() のﾓｼﾞｭｰﾙID            */
#define   MIA50506  0x5104              /* mia50506() のﾓｼﾞｭｰﾙID            */
#define   MIA50507  0x5027              /* mia50507() のﾓｼﾞｭｰﾙID            */
#define   MIA50508  0x5028              /* mia50508() のﾓｼﾞｭｰﾙID            */
#define   MIA50509  0x5029              /* mia50509() のﾓｼﾞｭｰﾙID            */
#define   MIA50552  0x502a              /* mia50552() のﾓｼﾞｭｰﾙID            */
#define   MIA50624  0x502b              /* mia50624() のﾓｼﾞｭｰﾙID            */
#define   MIA50628  0x502c              /* mia50628() のﾓｼﾞｭｰﾙID            */
#define   MIA50722  0x502d              /* mia50722() のﾓｼﾞｭｰﾙID            */
#define   MIA50723  0x502e              /* mia50723() のﾓｼﾞｭｰﾙID            */
#define   MIA50724  0x502f              /* mia50724() のﾓｼﾞｭｰﾙID            */
#define   MIA50728  0x5030              /* mia50728() のﾓｼﾞｭｰﾙID            */
#define   MIA50804  0x5109              /* mia50804() のﾓｼﾞｭｰﾙID    SSCY0203*/
#define   MIA50906  0x5105              /* mia50906() のﾓｼﾞｭｰﾙID            */
#define   MIA50911  0x5031              /* mia50911() のﾓｼﾞｭｰﾙID            */
#define   MIA50919  0x5032              /* mia50919() のﾓｼﾞｭｰﾙID            */
#define   MIA50927  0x5033              /* mia50927() のﾓｼﾞｭｰﾙID            */
#define   MIA50935  0x5034              /* mia50935() のﾓｼﾞｭｰﾙID            */
#define   MIA50942  0x5035              /* mia50942() のﾓｼﾞｭｰﾙID            */
#define   MIA50950  0x5036              /* mia50950() のﾓｼﾞｭｰﾙID            */
#define   MIA50951  0x5037              /* mia50951() のﾓｼﾞｭｰﾙID            */
#define   MIA50954  0x506e              /* mia50954() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA51101  0x503f              /* mia51101() のﾓｼﾞｭｰﾙID            */
#define   MIA51107  0x5040              /* mia51107() のﾓｼﾞｭｰﾙID            */
#define   MIA51112  0x5041              /* mia51112() のﾓｼﾞｭｰﾙID            */
#define   MIA51120  0x5042              /* mia51120() のﾓｼﾞｭｰﾙID            */
#define   MIA51129  0x5043              /* mia51129() のﾓｼﾞｭｰﾙID            */
#define   MIA51136  0x5044              /* mia51136() のﾓｼﾞｭｰﾙID            */
#define   MIA51143  0x5045              /* mia51143() のﾓｼﾞｭｰﾙID            */
#define   MIA51205  0x5046              /* mia51205() のﾓｼﾞｭｰﾙID            */
#define   MIA51210  0x5047              /* mia51210() のﾓｼﾞｭｰﾙID            */
#define   MIA51217  0x5048              /* mia51217() のﾓｼﾞｭｰﾙID            */
#define   MIA51218  0x5049              /* mia51218() のﾓｼﾞｭｰﾙID            */
#define   MIA51225  0x504a              /* mia51225() のﾓｼﾞｭｰﾙID            */
#define   MIA51226  0x504b              /* mia51226() のﾓｼﾞｭｰﾙID            */
#define   MIA51233  0x504c              /* mia51233() のﾓｼﾞｭｰﾙID            */
#define   MIA51234  0x504d              /* mia51234() のﾓｼﾞｭｰﾙID            */
#define   MIA51240  0x504e              /* mia51240() のﾓｼﾞｭｰﾙID            */
#define   MIA51241  0x504f              /* mia51241() のﾓｼﾞｭｰﾙID            */
#define   MIA51247  0x5050              /* mia51247() のﾓｼﾞｭｰﾙID            */
#define   MIA51253  0x506f              /* mia51253() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA51302  0x5051              /* mia51302() のﾓｼﾞｭｰﾙID            */
#define   MIA51309  0x5052              /* mia51309() のﾓｼﾞｭｰﾙID            */
#define   MIA51415  0x5053              /* mia51415() のﾓｼﾞｭｰﾙID            */
#define   MIA51516  0x5054              /* mia51516() のﾓｼﾞｭｰﾙID            */
#define   MIA51622  0x5055              /* mia51622() のﾓｼﾞｭｰﾙID            */
#define   MIA51731  0x5056              /* mia51731() のﾓｼﾞｭｰﾙID            */
#define   MIA51738  0x5057              /* mia51738() のﾓｼﾞｭｰﾙID            */
#define   MIA51745  0x5058              /* mia51745() のﾓｼﾞｭｰﾙID            */
#define   MIA51806  0x5106              /* mia51806() のﾓｼﾞｭｰﾙID            */
#define   MIA51808  0x5059              /* mia51808() のﾓｼﾞｭｰﾙID            */
#define   MIA51809  0x505a              /* mia51809() のﾓｼﾞｭｰﾙID            */
#define   MIA51811  0x505b              /* mia51811() のﾓｼﾞｭｰﾙID            */
#define   MIA51813  0x505c              /* mia51813() のﾓｼﾞｭｰﾙID            */
#define   MIA51814  0x505d              /* mia51814() のﾓｼﾞｭｰﾙID            */
#define   MIA51819  0x505e              /* mia51819() のﾓｼﾞｭｰﾙID            */
#define   MIA51821  0x505f              /* mia51821() のﾓｼﾞｭｰﾙID            */
#define   MIA51823  0x5060              /* mia51823() のﾓｼﾞｭｰﾙID            */
#define   MIA51827  0x5061              /* mia51827() のﾓｼﾞｭｰﾙID            */
#define   MIA51830  0x5062              /* mia51830() のﾓｼﾞｭｰﾙID            */
#define   MIA51832  0x5063              /* mia51832() のﾓｼﾞｭｰﾙID            */
#define   MIA51835  0x5064              /* mia51835() のﾓｼﾞｭｰﾙID            */
#define   MIA51837  0x5065              /* mia51837() のﾓｼﾞｭｰﾙID            */
#define   MIA51839  0x5066              /* mia51839() のﾓｼﾞｭｰﾙID            */
#define   MIA51842  0x5067              /* mia51842() のﾓｼﾞｭｰﾙID            */
#define   MIA51844  0x5068              /* mia51844() のﾓｼﾞｭｰﾙID            */
#define   MIA51846  0x5069              /* mia51846() のﾓｼﾞｭｰﾙID            */
#define   MIA51850  0x506a              /* mia51850() のﾓｼﾞｭｰﾙID            */
#define   MIA51851  0x506b              /* mia51851() のﾓｼﾞｭｰﾙID            */
#define   MIA51854  0x5070              /* mia51854() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA59999  0x506c              /* mia59999() のﾓｼﾞｭｰﾙID            */
#define   MIA60000  0x6000              /* mia60000() のﾓｼﾞｭｰﾙID            */
#define   MIA60002  0x6001              /* mia60002() のﾓｼﾞｭｰﾙID            */
#define   MIA60003  0x6002              /* mia60003() のﾓｼﾞｭｰﾙID            */
#define   MIA60004  0x6003              /* mia60004() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA60005  0x6004              /* mia60005() のﾓｼﾞｭｰﾙID    SSCY0203*/
#define   MIA60100  0x6085              /* mia60100() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA60103  0x6010              /* mia60103() のﾓｼﾞｭｰﾙID            */
#define   MIA60104  0x6011              /* mia60104() のﾓｼﾞｭｰﾙID            */
#define   MIA60105  0x6012              /* mia60105() のﾓｼﾞｭｰﾙID            */
#define   MIA60107  0x6013              /* mia60107() のﾓｼﾞｭｰﾙID            */
#define   MIA60108  0x6014              /* mia60108() のﾓｼﾞｭｰﾙID            */
#define   MIA60109  0x6015              /* mia60109() のﾓｼﾞｭｰﾙID            */
#define   MIA60152  0x6016              /* mia60152() のﾓｼﾞｭｰﾙID            */
#define   MIA60200  0x6086              /* mia60200() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA60203  0x6017              /* mia60203() のﾓｼﾞｭｰﾙID            */
#define   MIA60204  0x6018              /* mia60204() のﾓｼﾞｭｰﾙID            */
#define   MIA60205  0x6019              /* mia60205() のﾓｼﾞｭｰﾙID            */
#define   MIA60207  0x601a              /* mia60207() のﾓｼﾞｭｰﾙID            */
#define   MIA60208  0x601b              /* mia60208() のﾓｼﾞｭｰﾙID            */
#define   MIA60209  0x601c              /* mia60209() のﾓｼﾞｭｰﾙID            */
#define   MIA60252  0x601d              /* mia60252() のﾓｼﾞｭｰﾙID            */
#define   MIA60300  0x6087              /* mia60300() のﾓｼﾞｭｰﾙID        PD0J*/
#define   MIA60303  0x601e              /* mia60303() のﾓｼﾞｭｰﾙID            */
#define   MIA60304  0x601f              /* mia60304() のﾓｼﾞｭｰﾙID            */
#define   MIA60305  0x6020              /* mia60305() のﾓｼﾞｭｰﾙID            */
#define   MIA60307  0x6021              /* mia60307() のﾓｼﾞｭｰﾙID            */
#define   MIA60308  0x6022              /* mia60308() のﾓｼﾞｭｰﾙID            */
#define   MIA60309  0x6023              /* mia60309() のﾓｼﾞｭｰﾙID            */
#define   MIA60352  0x6024              /* mia60352() のﾓｼﾞｭｰﾙID            */
#define   MIA60400  0x607d              /* mia60400() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA60403  0x6025              /* mia60403() のﾓｼﾞｭｰﾙID            */
#define   MIA60404  0x6026              /* mia60404() のﾓｼﾞｭｰﾙID            */
#define   MIA60405  0x6027              /* mia60405() のﾓｼﾞｭｰﾙID            */
#define   MIA60407  0x6028              /* mia60407() のﾓｼﾞｭｰﾙID            */
#define   MIA60408  0x6029              /* mia60408() のﾓｼﾞｭｰﾙID            */
#define   MIA60409  0x602a              /* mia60409() のﾓｼﾞｭｰﾙID            */
#define   MIA60452  0x602b              /* mia60452() のﾓｼﾞｭｰﾙID            */
#define   MIA60461  0x6088              /* mia60461() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60462  0x6089              /* mia60462() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60500  0x607e              /* mia60500() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA60501  0x602c              /* mia60501() のﾓｼﾞｭｰﾙID            */
#define   MIA60502  0x602d              /* mia60502() のﾓｼﾞｭｰﾙID            */
#define   MIA60503  0x602e              /* mia60503() のﾓｼﾞｭｰﾙID            */
#define   MIA60504  0x602f              /* mia60504() のﾓｼﾞｭｰﾙID            */
#define   MIA60505  0x6030              /* mia60505() のﾓｼﾞｭｰﾙID            */
#define   MIA60507  0x6031              /* mia60507() のﾓｼﾞｭｰﾙID            */
#define   MIA60508  0x6032              /* mia60508() のﾓｼﾞｭｰﾙID            */
#define   MIA60509  0x6033              /* mia60509() のﾓｼﾞｭｰﾙID            */
#define   MIA60552  0x6034              /* mia60552() のﾓｼﾞｭｰﾙID            */
#define   MIA60561  0x608a              /* mia60561() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60562  0x608b              /* mia60562() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60624  0x6035              /* mia60624() のﾓｼﾞｭｰﾙID            */
#define   MIA60628  0x6036              /* mia60628() のﾓｼﾞｭｰﾙID            */
#define   MIA60722  0x6037              /* mia60722() のﾓｼﾞｭｰﾙID            */
#define   MIA60723  0x6038              /* mia60723() のﾓｼﾞｭｰﾙID            */
#define   MIA60724  0x6039              /* mia60724() のﾓｼﾞｭｰﾙID            */
#define   MIA60728  0x603a              /* mia60728() のﾓｼﾞｭｰﾙID            */
#define   MIA60800  0x607f              /* mia60800() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA60802  0x603b              /* mia60802() のﾓｼﾞｭｰﾙID            */
#define   MIA60803  0x603c              /* mia60803() のﾓｼﾞｭｰﾙID            */
#define   MIA60804  0x603d              /* mia60804() のﾓｼﾞｭｰﾙID            */
#define   MIA60852  0x603e              /* mia60852() のﾓｼﾞｭｰﾙID            */
#define   MIA60861  0x608c              /* mia60861() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60862  0x608d              /* mia60862() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA60911  0x603f              /* mia60911() のﾓｼﾞｭｰﾙID            */
#define   MIA60919  0x6040              /* mia60919() のﾓｼﾞｭｰﾙID            */
#define   MIA60927  0x6041              /* mia60927() のﾓｼﾞｭｰﾙID            */
#define   MIA60935  0x6042              /* mia60935() のﾓｼﾞｭｰﾙID            */
#define   MIA60942  0x6043              /* mia60942() のﾓｼﾞｭｰﾙID            */
#define   MIA60949  0x6044              /* mia60949() のﾓｼﾞｭｰﾙID            */
#define   MIA60950  0x6045              /* mia60950() のﾓｼﾞｭｰﾙID            */
#define   MIA60951  0x6046              /* mia60951() のﾓｼﾞｭｰﾙID            */
#define   MIA60961  0x608e              /* mia60961() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA61101  0x604e              /* mia61101() のﾓｼﾞｭｰﾙID            */
#define   MIA61107  0x604f              /* mia61107() のﾓｼﾞｭｰﾙID            */
#define   MIA61112  0x6050              /* mia61112() のﾓｼﾞｭｰﾙID            */
#define   MIA61120  0x6051              /* mia61120() のﾓｼﾞｭｰﾙID            */
#define   MIA61129  0x6052              /* mia61129() のﾓｼﾞｭｰﾙID            */
#define   MIA61136  0x6053              /* mia61136() のﾓｼﾞｭｰﾙID            */
#define   MIA61143  0x6054              /* mia61143() のﾓｼﾞｭｰﾙID            */
#define   MIA61205  0x6055              /* mia61205() のﾓｼﾞｭｰﾙID            */
#define   MIA61210  0x6056              /* mia61210() のﾓｼﾞｭｰﾙID            */
#define   MIA61217  0x6057              /* mia61217() のﾓｼﾞｭｰﾙID            */
#define   MIA61218  0x6058              /* mia61218() のﾓｼﾞｭｰﾙID            */
#define   MIA61225  0x6059              /* mia61225() のﾓｼﾞｭｰﾙID            */
#define   MIA61226  0x605a              /* mia61226() のﾓｼﾞｭｰﾙID            */
#define   MIA61233  0x605b              /* mia61233() のﾓｼﾞｭｰﾙID            */
#define   MIA61234  0x605c              /* mia61234() のﾓｼﾞｭｰﾙID            */
#define   MIA61240  0x605d              /* mia61240() のﾓｼﾞｭｰﾙID            */
#define   MIA61241  0x605e              /* mia61241() のﾓｼﾞｭｰﾙID            */
#define   MIA61247  0x605f              /* mia61247() のﾓｼﾞｭｰﾙID            */
#define   MIA61248  0x6060              /* mia61248() のﾓｼﾞｭｰﾙID            */
#define   MIA61302  0x6061              /* mia61302() のﾓｼﾞｭｰﾙID            */
#define   MIA61309  0x6062              /* mia61309() のﾓｼﾞｭｰﾙID            */
#define   MIA61415  0x6063              /* mia61415() のﾓｼﾞｭｰﾙID            */
#define   MIA61516  0x6064              /* mia61516() のﾓｼﾞｭｰﾙID            */
#define   MIA61622  0x6065              /* mia61622() のﾓｼﾞｭｰﾙID            */
#define   MIA61731  0x6066              /* mia61731() のﾓｼﾞｭｰﾙID            */
#define   MIA61738  0x6067              /* mia61738() のﾓｼﾞｭｰﾙID            */
#define   MIA61745  0x6068              /* mia61745() のﾓｼﾞｭｰﾙID            */
#define   MIA61808  0x6069              /* mia61808() のﾓｼﾞｭｰﾙID            */
#define   MIA61809  0x606a              /* mia61809() のﾓｼﾞｭｰﾙID            */
#define   MIA61811  0x606b              /* mia61811() のﾓｼﾞｭｰﾙID            */
#define   MIA61813  0x606c              /* mia61813() のﾓｼﾞｭｰﾙID            */
#define   MIA61814  0x606d              /* mia61814() のﾓｼﾞｭｰﾙID            */
#define   MIA61819  0x606e              /* mia61819() のﾓｼﾞｭｰﾙID            */
#define   MIA61821  0x606f              /* mia61821() のﾓｼﾞｭｰﾙID            */
#define   MIA61823  0x6070              /* mia61823() のﾓｼﾞｭｰﾙID            */
#define   MIA61827  0x6071              /* mia61827() のﾓｼﾞｭｰﾙID            */
#define   MIA61830  0x6072              /* mia61830() のﾓｼﾞｭｰﾙID            */
#define   MIA61832  0x6073              /* mia61832() のﾓｼﾞｭｰﾙID            */
#define   MIA61835  0x6074              /* mia61835() のﾓｼﾞｭｰﾙID            */
#define   MIA61837  0x6075              /* mia61837() のﾓｼﾞｭｰﾙID            */
#define   MIA61839  0x6076              /* mia61839() のﾓｼﾞｭｰﾙID            */
#define   MIA61842  0x6077              /* mia61842() のﾓｼﾞｭｰﾙID            */
#define   MIA61844  0x6078              /* mia61844() のﾓｼﾞｭｰﾙID            */
#define   MIA61846  0x6079              /* mia61846() のﾓｼﾞｭｰﾙID            */
#define   MIA61849  0x607d              /* mia61849() のﾓｼﾞｭｰﾙID            */
#define   MIA61850  0x607a              /* mia61850() のﾓｼﾞｭｰﾙID            */
#define   MIA61851  0x607b              /* mia61851() のﾓｼﾞｭｰﾙID            */
#define   MIA61861  0x608f              /* mia61861() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA61953  0x6080              /* mia61953() のﾓｼﾞｭｰﾙID      stPD0A*/
#define   MIA61954  0x6081              /* mia61954() のﾓｼﾞｭｰﾙID            */
#define   MIA61955  0x6082              /* mia61955() のﾓｼﾞｭｰﾙID            */
#define   MIA61956  0x6083              /* mia61956() のﾓｼﾞｭｰﾙID            */
#define   MIA61957  0x6084              /* mia61957() のﾓｼﾞｭｰﾙID      edPD0A*/
#define   MIA62100  0x6090              /* mia62100() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA62102  0x6091              /* mia62102() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA62152  0x6092              /* mia62152() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA69999  0x607c              /* mia69999() のﾓｼﾞｭｰﾙID            */
#define   MIA70000  0x7000              /* mia70000() のﾓｼﾞｭｰﾙID            */
#define   MIA70001  0x7001              /* mia70001() のﾓｼﾞｭｰﾙID            */
#define   MIA70002  0x7002              /* mia70002() のﾓｼﾞｭｰﾙID            */
#define   MIA70003  0x7015              /* mia70003() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA70004  0x7016              /* mia70004() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA70005  0x7017              /* mia70005() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA70100  0x7003              /* mia70100() のﾓｼﾞｭｰﾙID            */
#define   MIA71101  0x7004              /* mia71101() のﾓｼﾞｭｰﾙID            */
#define   MIA71107  0x700b              /* mia71107() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71206  0x7005              /* mia71206() のﾓｼﾞｭｰﾙID            */
#define   MIA71211  0x700c              /* mia71211() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71214  0x7011              /* mia71214() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71216  0x7018              /* mia71216() のﾓｼﾞｭｰﾙID        PD02*/
#define   MIA71312  0x7014              /* mia71312() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71404  0x7006              /* mia71404() のﾓｼﾞｭｰﾙID            */
#define   MIA71505  0x7007              /* mia71505() のﾓｼﾞｭｰﾙID            */
#define   MIA71709  0x700d              /* mia71709() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71802  0x7008              /* mia71802() のﾓｼﾞｭｰﾙID            */
#define   MIA71803  0x7009              /* mia71803() のﾓｼﾞｭｰﾙID            */
#define   MIA71808  0x700e              /* mia71808() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71810  0x700f              /* mia71810() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71913  0x7013              /* mia71913() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA71915  0x7019              /* mia71915() のﾓｼﾞｭｰﾙID        PD02*/
#define   MIA72000  0x7010              /* mia72000() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA72112  0x7012              /* mia72112() のﾓｼﾞｭｰﾙID        PD0A*/
#define   MIA79999  0x700a              /* mia79999() のﾓｼﾞｭｰﾙID            */
#define   MIA80000  0x8000              /* mia80000() のﾓｼﾞｭｰﾙID            */
#define   MIA80001  0x8001              /* mia80001() のﾓｼﾞｭｰﾙID            */
#define   MIA80002  0x8002              /* mia80002() のﾓｼﾞｭｰﾙID            */
#define   MIA80003  0x8003              /* mia80003() のﾓｼﾞｭｰﾙID            */
#define   MIA80004  0x8004              /* mia80004() のﾓｼﾞｭｰﾙID            */
#define   MIA80005  0x8005              /* mia80005() のﾓｼﾞｭｰﾙID            */
#define   MIA80101  0x8006              /* mia80101() のﾓｼﾞｭｰﾙID            */
#define   MIA80105  0x8007              /* mia80105() のﾓｼﾞｭｰﾙID            */
#define   MIA80106  0x8008              /* mia80106() のﾓｼﾞｭｰﾙID            */
#define   MIA80107  0x8009              /* mia80107() のﾓｼﾞｭｰﾙID            */
#define   MIA80112  0x800a              /* mia80112() のﾓｼﾞｭｰﾙID            */
#define   MIA80201  0x800b              /* mia80201() のﾓｼﾞｭｰﾙID            */
#define   MIA80205  0x800c              /* mia80205() のﾓｼﾞｭｰﾙID            */
#define   MIA80206  0x800d              /* mia80206() のﾓｼﾞｭｰﾙID            */
#define   MIA80207  0x800e              /* mia80207() のﾓｼﾞｭｰﾙID            */
#define   MIA80212  0x800f              /* mia80212() のﾓｼﾞｭｰﾙID            */
#define   MIA80301  0x8010              /* mia80301() のﾓｼﾞｭｰﾙID            */
#define   MIA80307  0x8011              /* mia80307() のﾓｼﾞｭｰﾙID            */
#define   MIA80312  0x8012              /* mia80312() のﾓｼﾞｭｰﾙID            */
#define   MIA80404  0x8013              /* mia80404() のﾓｼﾞｭｰﾙID            */
#define   MIA80411  0x8014              /* mia80411() のﾓｼﾞｭｰﾙID            */
#define   MIA80414  0x801d              /* mia80414() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA80503  0x8015              /* mia80503() のﾓｼﾞｭｰﾙID            */
#define   MIA80609  0x8016              /* mia80609() のﾓｼﾞｭｰﾙID            */
#define   MIA80710  0x8017              /* mia80710() のﾓｼﾞｭｰﾙID            */
#define   MIA80802  0x8018              /* mia80802() のﾓｼﾞｭｰﾙID            */
#define   MIA80808  0x8019              /* mia80808() のﾓｼﾞｭｰﾙID            */
#define   MIA80813  0x801a              /* mia80813() のﾓｼﾞｭｰﾙID            */
#define   MIA89999  0x801b              /* mia89999() のﾓｼﾞｭｰﾙID            */
#define   MIA90000  0x9000              /* mia90000() のﾓｼﾞｭｰﾙID      stPD0A*/
#define   MIA90001  0x9033              /* mia90001() のﾓｼﾞｭｰﾙID        PD0B*/
#define   MIA90005  0x9001              /* mia90005() のﾓｼﾞｭｰﾙID            */
#define   MIA90006  0x9002              /* mia90006() のﾓｼﾞｭｰﾙID            */
#define   MIA90007  0x9003              /* mia90007() のﾓｼﾞｭｰﾙID            */
#define   MIA90008  0x9004              /* mia90008() のﾓｼﾞｭｰﾙID            */
#define   MIA90400  0x9005              /* mia90400() のﾓｼﾞｭｰﾙID            */
#define   MIA90405  0x9006              /* mia90405() のﾓｼﾞｭｰﾙID            */
#define   MIA90406  0x9007              /* mia90406() のﾓｼﾞｭｰﾙID            */
#define   MIA90407  0x9008              /* mia90407() のﾓｼﾞｭｰﾙID            */
#define   MIA90408  0x9009              /* mia90408() のﾓｼﾞｭｰﾙID            */
#define   MIA90409  0x900a              /* mia90409() のﾓｼﾞｭｰﾙID            */
#define   MIA90452  0x900b              /* mia90452() のﾓｼﾞｭｰﾙID            */
#define   MIA90460  0x9037              /* mia90460() のﾓｼﾞｭｰﾙID      stPD0O*/
#define   MIA90461  0x9038              /* mia90461() のﾓｼﾞｭｰﾙID            */
#define   MIA90462  0x9039              /* mia90462() のﾓｼﾞｭｰﾙID      edPD0O*/
#define   MIA90500  0x900c              /* mia90500() のﾓｼﾞｭｰﾙID            */
#define   MIA90501  0x900d              /* mia90501() のﾓｼﾞｭｰﾙID            */
#define   MIA90502  0x900e              /* mia90502() のﾓｼﾞｭｰﾙID            */
#define   MIA90505  0x900f              /* mia90505() のﾓｼﾞｭｰﾙID            */
#define   MIA90506  0x9010              /* mia90506() のﾓｼﾞｭｰﾙID            */
#define   MIA90507  0x9011              /* mia90507() のﾓｼﾞｭｰﾙID            */
#define   MIA90508  0x9012              /* mia90508() のﾓｼﾞｭｰﾙID            */
#define   MIA90509  0x9013              /* mia90509() のﾓｼﾞｭｰﾙID            */
#define   MIA90552  0x9014              /* mia90552() のﾓｼﾞｭｰﾙID            */
#define   MIA90560  0x903a              /* mia90560() のﾓｼﾞｭｰﾙID      stPD0O*/
#define   MIA90561  0x903b              /* mia90561() のﾓｼﾞｭｰﾙID            */
#define   MIA90562  0x903c              /* mia90562() のﾓｼﾞｭｰﾙID      edPD0O*/
#define   MIA90906  0x9015              /* mia90906() のﾓｼﾞｭｰﾙID            */
#define   MIA90935  0x9016              /* mia90935() のﾓｼﾞｭｰﾙID            */
#define   MIA90942  0x9017              /* mia90942() のﾓｼﾞｭｰﾙID            */
#define   MIA90959  0x9034              /* mia90959() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA90961  0x903d              /* mia90961() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA91101  0x9018              /* mia91101() のﾓｼﾞｭｰﾙID            */
#define   MIA91107  0x9019              /* mia91107() のﾓｼﾞｭｰﾙID            */
#define   MIA91136  0x901a              /* mia91136() のﾓｼﾞｭｰﾙID            */
#define   MIA91143  0x901b              /* mia91143() のﾓｼﾞｭｰﾙID            */
#define   MIA91205  0x901c              /* mia91205() のﾓｼﾞｭｰﾙID            */
#define   MIA91234  0x901d              /* mia91234() のﾓｼﾞｭｰﾙID            */
#define   MIA91240  0x901e              /* mia91240() のﾓｼﾞｭｰﾙID            */
#define   MIA91241  0x901f              /* mia91241() のﾓｼﾞｭｰﾙID            */
#define   MIA91247  0x9020              /* mia91247() のﾓｼﾞｭｰﾙID            */
#define   MIA91258  0x9035              /* mia91258() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA91260  0x9046              /* mia91260() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA91302  0x9021              /* mia91302() のﾓｼﾞｭｰﾙID            */
#define   MIA91309  0x9022              /* mia91309() のﾓｼﾞｭｰﾙID            */
#define   MIA91738  0x9023              /* mia91738() のﾓｼﾞｭｰﾙID            */
#define   MIA91745  0x9024              /* mia91745() のﾓｼﾞｭｰﾙID            */
#define   MIA91806  0x9025              /* mia91806() のﾓｼﾞｭｰﾙID            */
#define   MIA91808  0x9026              /* mia91808() のﾓｼﾞｭｰﾙID            */
#define   MIA91809  0x9027              /* mia91809() のﾓｼﾞｭｰﾙID            */
#define   MIA91835  0x9028              /* mia91835() のﾓｼﾞｭｰﾙID            */
#define   MIA91837  0x9029              /* mia91837() のﾓｼﾞｭｰﾙID            */
#define   MIA91839  0x902a              /* mia91839() のﾓｼﾞｭｰﾙID            */
#define   MIA91842  0x902b              /* mia91842() のﾓｼﾞｭｰﾙID            */
#define   MIA91844  0x902c              /* mia91844() のﾓｼﾞｭｰﾙID            */
#define   MIA91850  0x902d              /* mia91850() のﾓｼﾞｭｰﾙID            */
#define   MIA91851  0x902e              /* mia91851() のﾓｼﾞｭｰﾙID            */
#define   MIA91846  0x902f              /* mia91846() のﾓｼﾞｭｰﾙID            */
#define   MIA91859  0x9036              /* mia91859() のﾓｼﾞｭｰﾙID        PD0C*/
#define   MIA91861  0x903e              /* mia91861() のﾓｼﾞｭｰﾙID        PD0O*/
#define   MIA91954  0x9030              /* mia91954() のﾓｼﾞｭｰﾙID            */
#define   MIA91956  0x9031              /* mia91956() のﾓｼﾞｭｰﾙID            */
#define   MIA92100  0x9042              /* mia92100() のﾓｼﾞｭｰﾙID      stPD0O*/
#define   MIA92101  0x9043              /* mia92101() のﾓｼﾞｭｰﾙID            */
#define   MIA92102  0x9044              /* mia92102() のﾓｼﾞｭｰﾙID            */
#define   MIA92199  0x9045              /* mia92199() のﾓｼﾞｭｰﾙID      edPD0O*/
#define   MIA92209  0x9047              /* mia92209() のﾓｼﾞｭｰﾙID        PD0R*/
#define   MIA99999  0x9032              /* mia99999() のﾓｼﾞｭｰﾙID            */
#define   MIAa0000  0xa000              /* miaa0000() のﾓｼﾞｭｰﾙID            */
#define   MIAa0001  0xa001              /* miaa0001() のﾓｼﾞｭｰﾙID            */
#define   MIAa0002  0xa002              /* miaa0002() のﾓｼﾞｭｰﾙID            */
#define   MIAa0100  0xa003              /* miaa0100() のﾓｼﾞｭｰﾙID            */
#define   MIAa0302  0xa004              /* miaa0302() のﾓｼﾞｭｰﾙID            */
#define   MIAa0405  0xa005              /* miaa0405() のﾓｼﾞｭｰﾙID            */
#define   MIAa0509  0xa006              /* miaa0509() のﾓｼﾞｭｰﾙID            */
#define   MIAa0610  0xa007              /* miaa0610() のﾓｼﾞｭｰﾙID            */
#define   MIAa0707  0xa008              /* miaa0707() のﾓｼﾞｭｰﾙID            */
#define   MIAa0802  0xa009              /* miaa0802() のﾓｼﾞｭｰﾙID            */
#define   MIAa0806  0xa00a              /* miaa0806() のﾓｼﾞｭｰﾙID            */
#define   MIAa0808  0xa00b              /* miaa0808() のﾓｼﾞｭｰﾙID            */
#define   MIAa0814  0xa00d              /* miaa0814() のﾓｼﾞｭｰﾙID            */
#define   MIAa9999  0xa00c              /* miaa9999() のﾓｼﾞｭｰﾙID            */
#define   MIAb0000  0xb000              /* miab0000() のﾓｼﾞｭｰﾙID            */
#define   MIAb0001  0xb001              /* miab0001() のﾓｼﾞｭｰﾙID            */
#define   MIAb0002  0xb002              /* miab0002() のﾓｼﾞｭｰﾙID            */
#define   MIAb0100  0xb003              /* miab0100() のﾓｼﾞｭｰﾙID            */
#define   MIAb0101  0xb004              /* miab0101() のﾓｼﾞｭｰﾙID            */
#define   MIAb0200  0xb005              /* miab0200() のﾓｼﾞｭｰﾙID            */
#define   MIAb0201  0xb006              /* miab0201() のﾓｼﾞｭｰﾙID            */
#define   MIAb0302  0xb007              /* miab0302() のﾓｼﾞｭｰﾙID            */
#define   MIAb0311  0xb008              /* miab0311() のﾓｼﾞｭｰﾙID            */
#define   MIAb0315  0xb016              /* miab0315() のﾓｼﾞｭｰﾙID            */
#define   MIAb0316  0xb017              /* miab0316() のﾓｼﾞｭｰﾙID            */
#define   MIAb0405  0xb009              /* miab0405() のﾓｼﾞｭｰﾙID            */
#define   MIAb0504  0xb00a              /* miab0504() のﾓｼﾞｭｰﾙID            */
#define   MIAb0509  0xb00b              /* miab0509() のﾓｼﾞｭｰﾙID            */
#define   MIAb0513  0xb00c              /* miab0513() のﾓｼﾞｭｰﾙID            */
#define   MIAb0603  0xb00d              /* miab0603() のﾓｼﾞｭｰﾙID            */
#define   MIAb0610  0xb00e              /* miab0610() のﾓｼﾞｭｰﾙID            */
#define   MIAb0612  0xb00f              /* miab0612() のﾓｼﾞｭｰﾙID            */
#define   MIAb0707  0xb010              /* miab0707() のﾓｼﾞｭｰﾙID            */
#define   MIAb0802  0xb011              /* miab0802() のﾓｼﾞｭｰﾙID            */
#define   MIAb0806  0xb012              /* miab0806() のﾓｼﾞｭｰﾙID            */
#define   MIAb0808  0xb013              /* miab0808() のﾓｼﾞｭｰﾙID            */
#define   MIAb0811  0xb014              /* miab0811() のﾓｼﾞｭｰﾙID            */
#define   MIAb0814  0xb018              /* miab0814() のﾓｼﾞｭｰﾙID            */
#define   MIAb0815  0xb019              /* miab0815() のﾓｼﾞｭｰﾙID            */
#define   MIAb0816  0xb01a              /* miab0816() のﾓｼﾞｭｰﾙID            */
#define   MIAb9999  0xb015              /* miab9999() のﾓｼﾞｭｰﾙID      edPD0A*/
#define   MIAc0000  0xc000              /* miac0000() のﾓｼﾞｭｰﾙID      stPD0C*/
#define   MIAc0001  0xc001              /* miac0001() のﾓｼﾞｭｰﾙID            */
#define   MIAc0002  0xc002              /* miac0002() のﾓｼﾞｭｰﾙID            */
#define   MIAc1000  0xc003              /* miac1000() のﾓｼﾞｭｰﾙID            */
#define   MIAc2000  0xc004              /* miac2000() のﾓｼﾞｭｰﾙID      edPD0C*/
#define   MIAd0000  0xd000              /* miad0000() のﾓｼﾞｭｰﾙID      stPD0O*/
#define   MIAd0100  0xd001              /* miad0100() のﾓｼﾞｭｰﾙID            */
#define   MIAd0102  0xd002              /* miad0102() のﾓｼﾞｭｰﾙID            */
#define   MIAd0103  0xd003              /* miad0103() のﾓｼﾞｭｰﾙID            */
#define   MIAd0201  0xd004              /* miad0201() のﾓｼﾞｭｰﾙID            */
#define   MIAd0202  0xd005              /* miad0202() のﾓｼﾞｭｰﾙID            */
#define   MIAd0203  0xd006              /* miad0203() のﾓｼﾞｭｰﾙID            */
#define   MIAd0400  0xd007              /* miad0400() のﾓｼﾞｭｰﾙID            */
#define   MIAd0401  0xd008              /* miad0401() のﾓｼﾞｭｰﾙID            */
#define   MIAd0403  0xd009              /* miad0403() のﾓｼﾞｭｰﾙID            */
#define   MIAd0501  0xd00a              /* miad0501() のﾓｼﾞｭｰﾙID            */
#define   MIAd0502  0xd00b              /* miad0502() のﾓｼﾞｭｰﾙID            */
#define   MIAd0503  0xd00c              /* miad0503() のﾓｼﾞｭｰﾙID            */
#define   MIAd9999  0xd00d              /* miad9999() のﾓｼﾞｭｰﾙID      edPD0O*/
#define   MIAe0000  0xe000              /* miae0000() のﾓｼﾞｭｰﾙID        PD0Y*/

