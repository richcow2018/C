/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ﾌｧｲﾙﾒｲ														 */
/*		ﾒｯｾ-ｼﾞ ID ﾃｲｷﾞ ﾌｧｲﾙ (mrmsg.h)								 */
/*																	 */
/*	2 ｸﾌﾞﾝ															 */
/*		ﾘｶﾊﾞﾘ ｷｮｳﾂｳ													 */
/*																	 */
/*	3 ﾘﾚｷ															 */
/*		ｾｯｹｲ ｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ											 */
/*		ｻｸｾｲ ｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ						 					 */
/*		ﾍﾝｺｳ ｼｬ : ｽｽﾞｷ ｵｻﾑ				'87/10/01	(L01)			 */
/*			 (ｵｲｶｹ ﾘｶﾊﾞﾘ ｶﾝﾚﾝ ｺｳﾓｸ ﾉ ｻｸｼﾞｮ)				---STC395	 */
/*		ﾍﾝｺｳｼﾔ : ﾎｼﾉ ﾋﾛﾄｼ				'87/11/28	(L02)			 */
/*			 (VRCV/BKUP ｲﾝﾀｰﾌｪｲｽ ﾆ ﾖﾙ ﾍﾝｺｳ)				---STC351	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 	'89/07/29   (L03)			 */
/*			 (ﾊﾞｯｸｱｯﾌﾟ ｻｲ ｷﾄﾞｳ ｷﾉｳ ﾉ ﾂｲｶ)				---TC2701	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 	'89/09/07   (L04)			 */
/*			 (RCV ﾌｧｲﾙ ｿｳｾｲ/ｶｲﾌｸ ﾊﾟﾗﾒﾀ ｾｯﾃｲ ｷﾉｳ ﾂｲｶ)	---TCXXXX	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 	'89/10/19 	(L05)			 */
/*			 (ﾊﾞｯｸｱｯﾌﾟ ﾎﾞﾘｭｰﾑ A･Bﾒﾝ ｼﾖｳ ｷﾉｳ ﾉ ﾂｲｶ)		---TC3020	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 	'90/04/28	(L06)			 */
/*			 (ｺﾋﾟｰﾌﾟﾛｾｽ ﾏﾙﾁ ｷﾄﾞｳ ｷﾉｳ ﾉ ﾂｲｶ)				--- TC3550	 */
/*      変更者 : 杉岡　克也              93/11/12    TD-00           */
/*                (他TC動作監視に伴う変更)           TD-02           */
/*				  (2重化ｱｸｾｽの廃止に伴う変更)		 TD-27			 */
/*                (LMﾃ-ﾌﾞﾙﾘｶﾊﾞﾘ導入に伴う変更)       TD-39           */
/*                (KJ分離に伴う変更)				 TD-42			 */
/*                (ﾊﾞﾂｸｱﾂﾌﾟ中JNL取得に伴う変更)      TD-67           */
/*				  (ｵﾝ中のJNL初期化に伴う変更)		 TD-79			 */
/*                (KJ単独ﾊﾞﾂｸｱﾂﾌﾟ導入に伴う変更)     TD-83           */
/*				  (SMP日付の導入に伴う変更)			 TD-92			 */
/*      変更者 : 赤塚　一元              95/02/23    CT0881          */
/*		変更者 : 今井　弘幸				 95/03/30 	 CT0977(ST2646)  */
/*				  (2重故障時面切替機能追加に伴う変更				 */
/*				   仕様変更要求書 SSCYXXXX)							 */
/*	    変更者 : 今井　弘幸				 95/07/04	 CT1085(ST2987)	 */
/*				  (ﾒｯｾｰｼﾞの充実:mri)								 */
/*	    変更者 : 今井　弘幸				 95/07/04	 CT1086(ST2988)	 */
/*				  (ﾒｯｾｰｼﾞの充実:mrp)								 */
/*	    変更者 : 杉岡  克也				 95/07/11	 CT1084(ST2986)	 */
/*				  (ﾒｯｾｰｼﾞの充実:mrh)								 */
/*		変更者 : 柴崎　智子				 95/07/24	 ST2893			 */
/*				  (ﾒｯｾｰｼﾞの充実:mro)								 */
/*	    変更者 : 杉岡  克也				 95/08/08	 CT1102(ST3410)	 */
/*				  (ﾒｯｾｰｼﾞの充実:jnl)								 */
/*		変更者 : 赤塚　一元				 95/08/08	 ST3026			 */
/*		変更者 : 赤塚　一元				 95/08/29	 CT1106(ST3142)	 */
/*      変更者 : 杉岡  克也				 95/09/12					 */
/*                (mr_mdbg及びmrq新設に伴う変更)	 CT1103(ST3408)	 */
/*      変更者 : 杉岡  克也				 95/10/10    ST3492			 */
/*	    変更者 : 杉岡  克也				 95/10/26	 CT1118(ST3410)	 */
/*				  (ﾒｯｾｰｼﾞの充実:ﾐﾗ-同期)							 */
/*		変更者 : 赤塚　一元				 95/11/07	 ST3688			 */
/*	    変更者 : 杉岡  克也				 95/11/16	 CT1163(ST3808)	 */
/*				  (mro起動中のmrp起動優先)							 */
/*	    変更者 : 杉岡  克也				 95/11/24	 ST3802			 */
/*	    変更者 : 杉岡  克也				 95/12/12	 ST3820			 */
/*	    変更者 : 杉岡  克也				 96/01/08	 TD-N7			 */
/*				  (mr_dum2新規提供に伴う変更)						 */
/*		変更者 : 今井　弘幸				 96/02/16	 ST4036			 */
/*		変更者 : 今井　弘幸				 96/02/21	 ST3754			 */
/*		変更者 : 山本  智也				 96/02/21	 ST3921			 */
/*		変更者 : Com'App				 96/02/21	 SSCY0152		 */
/*	    変更者 : 杉岡  克也				 96/02/24	 CT1212(ST4166)	 */
/*				 (SPM待避ﾌｱｲﾙ創成機能新設に伴う変更)				 */
/*		変更者 : 今井　弘幸				 96/02/24	 ST4042			 */
/*				 (mroﾒｯｾｰｼﾞのｺﾒﾝﾄ修正)								 */
/*		変更者 : 今井　弘幸				 96/02/28	 ST4031			 */
/*				 (mrnﾀﾞｳﾝ要ﾁｪｯｸ廃止に伴う変更)						 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*		ms_wtop ﾊﾟﾗﾒﾀ ﾉ ﾃｲｷﾞ										 */
/*********************************************************************/

#define		MRMSGFOM	0x10
#define		MROUTPTN	0x40
#define		MRATGRUP	0
#define		MRATSUBN	0

/*********************************************************************/
/*			1.ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ (PRCV)									 */
/*********************************************************************/

#define	MRMSG02	"SR02"	/* 現用系 ﾌﾟﾛｾｽ･ｱﾎﾞ-ﾄ 					TD00 */
						/*   (nnnnnnnn pppppppp cccccccc dddddddd)	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ﾒｲ				 */
						/*   pppppppp : ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ｼ (HEX)			 */
						/*   cccccccc : ｱﾎﾞ-ﾄ ｺ-ﾄﾞ (HEX)			 */
						/*   dddddddd : ｼｮｳｻｲ ｺ-ﾄﾞ (HEX)			 */
#define	MRMSG03	"SR03"	/* 予備系 ﾌﾟﾛｾｽ･ｱﾎﾞ-ﾄ 					TD00 */
						/*   (nnnnnnnn pppppppp cccccccc dddddddd)	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ﾒｲ				 */
						/*   pppppppp : ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ｼ (HEX)			 */
						/*   cccccccc : ｱﾎﾞ-ﾄ ｺ-ﾄﾞ (HEX)			 */
						/*   dddddddd : ｼｮｳｻｲ ｺ-ﾄﾞ (HEX)			 */

/*********************************************************************/
/*			2.その他提供関数(COMM)									 */
/*********************************************************************/
#define	MRMSG05 "SR05"	/* ﾘｾｯﾄ成功(ffff....)					TDN7 */
#define	MRMSG06 "SR06"	/* ﾘｾｯﾄ失敗(ffff....)					TDN7 */
						/*  RC=rrrrrrrr  PN=nnnnnnnn  				 */
						/*   ffff.... : SCSIﾊﾞｽ特殊ﾌｱｲﾙ名			 */ 
						/*   rrrrrrrr : ｼｽﾃﾑｺ-ﾙ返却値				 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名					 */
#define	MRMSG07 "SR07"	/* 特殊ﾌｱｲﾙI/Oｴﾗ-(ffff...)				TDN7 */
						/*  TYPE=oooo  RC=rrrrrrrr  PN=nnnnnnnn 	 */
						/*   ffff.... : SCSIﾊﾞｽ特殊ﾌｱｲﾙ名			 */ 
						/*   oooo     : ｼｽﾃﾑｺ-ﾙ種別					 */
						/*   rrrrrrrr : ｼｽﾃﾑｺ-ﾙ返却値				 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名					 */
#define	MRMSG08 "SR08"	/* 装置組込失敗						  ST3754 */
						/* (pppppppp dddddddd)						 */ 
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名				 */
						/* dddddddd : osconfig返却値				 */
#define	MRMSG09 "SR09"	/* テーブルエラー (tttt)			  ST3754 */
						/* tttt : ﾃｰﾌﾞﾙ名							 */
						

/*********************************************************************/
/*			3.RBI ｼｭﾄｸ ｼｮﾘ (RBI)									 */
/*********************************************************************/

#define	MRMSG10	"SR10"	/* CMﾃｰﾌﾞﾙ用 RBIﾌｧｲﾙ ｲｼﾞｮｳ(nnnnnnnn)    TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名			ST3921	 */
						/*   oooooooo : ｼｽﾃﾑｺｰﾙ種別			ST3921	 */
						/*	 rrrrrrrr : ｼｽﾃﾑｺｰﾙ返却値		ST3921	 */
#define	MRMSG11	"SR11"	/* LM0ﾃｰﾌﾞﾙ用 RBIﾌｧｲﾙ ｲｼﾞｮｳ(nnnnnnnn)	TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名			ST3921	 */
						/*   oooooooo : ｼｽﾃﾑｺｰﾙ種別			ST3921	 */
						/*	 rrrrrrrr : ｼｽﾃﾑｺｰﾙ返却値		ST3921	 */
#define	MRMSG12	"SR12"	/* LM1ﾃｰﾌﾞﾙ用 RBIﾌｧｲﾙ ｲｼﾞｮｳ(nnnnnnnn)	TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名			ST3921	 */
						/*   oooooooo : ｼｽﾃﾑｺｰﾙ種別			ST3921	 */
						/*	 rrrrrrrr : ｼｽﾃﾑｺｰﾙ返却値		ST3921	 */
						/* MRMSG13 〜 MRMSG18を削除				TD@1 */

/*********************************************************************/
/*			4.ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ｼｮﾘ (JNL)									 */
/*********************************************************************/
										/* 不用ﾃﾞﾌｧｲﾝ削除(8行)	TD42 */
#define	MRMSG23	"SR23"	/* ｼﾞｬ-ﾅﾙﾌｧｲﾙ ｲｼﾞｮｳ(s k m) 				TD42 */
						/* ｹﾝｼｭﾂ(nnnnnnnn) SC=oooooooo RC=rrrrrrrr	 */
						/*									CT1102	 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名			CT1102	 */
						/*   oooooooo : ｼｽﾃﾑｺｰﾙ種別			CT1102	 */
						/*	 rrrrrrrr : ｼｽﾃﾑｺｰﾙ返却値		CT1102	 */
#define	MRMSG24	"SR24"	/* ｼﾞｬ-ﾅﾙﾌｧｲﾙ ﾘｮｳｲｷﾌﾞｿｸ(s k m)			TD42 */
						/* ｹﾝｼｭﾂ(nnnnnnnn) SC=oooooooo RC=rrrrrrrr	 */
						/*									CT1102	 */
#define	MRMSG25	"SR25"	/* ｼﾞｬ-ﾅﾙﾌｧｲﾙ ﾆｱｴﾝﾄﾞ (s k m)			TD65 */
						/*   s : 'G'---現用系	'Y'---予備系		 */
						/*   k : 'J'---JNL		'K'---KJ			 */
						/*   m : '1'---1面		'2'---2面			 */

/*********************************************************************/
/*		5.ｼｽﾃﾑ ﾘｶﾊﾞﾘ (SRCV)										 	*/
/*********************************************************************/

#define	MRMSG30	"SR30"	/* ｼﾞｬ-ﾅﾙﾃﾞ-ﾀﾁｮｳｴﾗ- (ii dddd rrrrrrrr)		 */
						/*   ii : ﾃﾞ-ﾀID							 */
						/*   dddd : ﾚｺ-ﾄﾞ ﾅｲ ﾃﾞ-ﾀ ﾂｳﾊﾞﾝ (DEC)		 */
						/*   rrrrrrrr : ﾚｺ-ﾄﾞ ﾂｳﾊﾞﾝ (DEC)			 */
#define	MRMSG31	"SR31"	/* ｼﾞｬ-ﾅﾙﾃﾞ-ﾀｴﾗ- (ii dddd rrrrrrrr)			 */
						/*   ii : ﾃﾞ-ﾀID							 */
						/*   dddd : ﾚｺ-ﾄﾞ ﾅｲ ﾃﾞ-ﾀ ﾂｳﾊﾞﾝ (DEC)		 */
						/*   rrrrrrrr : ﾚｺ-ﾄﾞ ﾂｳﾊﾞﾝ (DEC)			 */
#define	MRMSG32	"SR32"	/* ｼﾞｬ-ﾅﾙﾚｺ-ﾄﾞｴﾗ- (rrrrrrrr)				 */
						/*   rrrrrrrr : ﾚｺ-ﾄﾞ ﾂｳﾊﾞﾝ (DEC)			 */
#define	MRMSG33	"SR33"	/* ｼﾞｬ-ﾅﾙﾃﾞ-ﾀIDｴﾗ- (ii dddd rrrrrrrr)		 */
						/*   ii : ﾃﾞ-ﾀID							 */
						/*   dddd : ﾚｺ-ﾄﾞ ﾅｲ ﾃﾞ-ﾀ ﾂｳﾊﾞﾝ (DEC)		 */
						/*   rrrrrrrr : ﾚｺ-ﾄﾞ ﾂｳﾊﾞﾝ (DEC)			 */
#define	MRMSG38	"SR38"	/* ｶｲｼ ﾒｯｾｰｼﾞ(ｴｷｼｮｳ ﾃﾞｽﾌﾟﾚｲ)		   (L02) */
#define	MRMSG39	"SR39"	/* ｼｭｳﾘｮｳ ﾒｯｾｰｼﾞ(ｴｷｼｮｳ ﾃﾞｽﾌﾟﾚｲ)		   (L02) */
#define	MRMSG57	"SR57"	/* ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ ﾁｭｳ ﾆ ｼｽﾃﾑﾀﾞｳﾝ 				 */

/*********************************************************************/
/*		6.	故障管理プロセス                                	TD-00*/
/*********************************************************************/

#define MRMSG40 "SR40"	/* VRCV ｷﾄﾞｳ								 */
						/* ﾌﾞﾛﾂｸ構成の変更に伴う削除(17行)      TD01 */
#define	MRMSG41	"SR41"	/* 現用系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(1面)            TD67 */
#define	MRMSG42	"SR42"	/* 現用系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(2面)            TD67 */
#define	MRMSG43	"SR43"	/* 現用系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(両面)           TD67 */
#define	MRMSG44	"SR44"	/* 予備系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(1面)            TD67 */
#define	MRMSG45	"SR45"	/* 予備系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(2面)            TD67 */
#define MRMSG46 "SR46"  /* 予備系ｼﾞﾔ-ﾅﾙﾌｱｲﾙ故障(両面)           TD67 */
#define	MRMSG47	"SR47"	/* 現用系勘定照合ﾌｱｲﾙ故障(1面)          TD83 */
#define	MRMSG48	"SR48"	/* 現用系勘定照合ﾌｱｲﾙ故障(2面)          TD83 */
#define	MRMSG49	"SR49"	/* 現用系勘定照合ﾌｱｲﾙ故障(両面)         TD83 */
#define	MRMSG4A "SR4A"	/* 予備系勘定照合ﾌｱｲﾙ故障(1面)          TD83 */
#define	MRMSG4B	"SR4B"	/* 予備系勘定照合ﾌｱｲﾙ故障(2面)          TD83 */
#define	MRMSG4C	"SR4C"	/* 予備系勘定照合ﾌｱｲﾙ故障(両面)         TD83 */
#define	MRMSG4D	"SR4D"	/* 現用系RBIﾌｱｲﾙ故障                    TD39 */
#define	MRMSG4E	"SR4E"	/* 予備系RBIﾌｱｲﾙ故障                    TD39 */
#define	MRMSG4F	"SR4F"	/* 待機面JNLﾌｧｲﾙ故障(1面)             CT0977 */
#define	MRMSG4G	"SR4G"	/* 待機面KJﾌｧｲﾙ故障(1面)              CT0977 */
#define	MRMSG4H	"SR4H"	/* 待機面JNLﾌｧｲﾙ故障(2面)             CT0977 */
#define	MRMSG4I	"SR4I"	/* 待機面KJﾌｧｲﾙ故障(2面 )             CT0977 */
#define	MRMSG4J	"SR4J"	/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ(vvvvvvvv)片系(s)故障(eeeeeeee)  */
						/*									  CT1084 */
						/*   vvvvvvvv : 論理ﾎﾞﾘﾕ-ﾑ識別名			 */
						/*   s        : 正/副区分					 */
						/*   eeeeeeee : ｴﾗ-ｺ-ﾄﾞ						 */
#define	MRMSG4K	"SR4K"	/* 不正電文受信						ST3802	 */ 
						/*	MK1=0x0m  MK2=0x0k  PNAME=nnnnnnnn		 */ 
						/*  IF1=0xiiii  IF2=0xffff  				 */ 
						/*	 m        : MKｺ-ﾄﾞ1						 */
						/*	 k        : MKｺ-ﾄﾞ2						 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名					 */
						/*   iiii	  : ｲﾝﾀ-ﾌｴ-ｽｺ-ﾄﾞ1				 */
						/*   ffff	  : ｲﾝﾀ-ﾌｴ-ｽｺ-ﾄﾞ2				 */

/*********************************************************************/
/*      7. ＶＲＣＶ前処理プロセス（ＡＶＲＣＶ）                 TD00 */
/*********************************************************************/
#define	MRMSG50	"SR50"	/* VRCV前処理開始(現用系)				TD90 */
#define	MRMSG51	"SR51"	/* VRCV前処理開始(予備系)				TD90 */
#define	MRMSG52	"SR52"	/* RCV不要ｼｽﾃﾑである					TD90 */
#define	MRMSG53	"SR53"	/* 自系物理ﾎﾞﾘﾕ-ﾑ(pppppppp)閉塞失敗(dddddddd)*/
						/*										TD90 */
						/*   pppppppp : 物理ﾎﾞﾘﾕ-ﾑ識別名			 */
						/*   dddddddd : 詳細ｺ-ﾄﾞ     	             */
#define	MRMSG54 "SR54"	/* 先行ﾘｶﾊﾞﾘ中である                    TD90 */
#define	MRMSG55 "SR55"	/* 予備系に起動された                   TD90 */
#define	MRMSG56	"SR56"	/* ﾊﾟﾗﾒﾀ個数不当						TD90 */
						/* 欠番(ｼｽﾃﾑﾘｶﾊﾞﾘが使用)                TD00 */
#define	MRMSG58	"SR58"	/* VRCV・BKUP中である                   TD90 */
#define MRMSG59	"SR59"	/* 現用系JNLﾌｱｲﾙ故障(1面)               TD78 */
#define MRMSG5A	"SR5A"	/* 現用系JNLﾌｱｲﾙ故障(2面)               TD78 */
/* 削除（１行）												ST4031	 */
#define MRMSG5C	"SR5C"	/* 予備系JNLﾌｱｲﾙ故障(1面)               TD78 */
#define MRMSG5D	"SR5D"	/* 予備系JNLﾌｱｲﾙ故障(2面)               TD78 */
/* 削除（１行）												ST4031	 */
#define MRMSG5F	"SR5F"	/* 現用系勘定照合ﾌｱｲﾙ故障(1面)          TD78 */
#define MRMSG5G	"SR5G"	/* 現用系勘定照合ﾌｱｲﾙ故障(2面)          TD78 */
/* 削除（１行）												ST4031	 */
#define MRMSG5I	"SR5I"	/* 現用系勘定照合ﾌｱｲﾙ故障(1面)          TD78 */
#define MRMSG5J	"SR5J"	/* 現用系勘定照合ﾌｱｲﾙ故障(2面)          TD78 */
#define	MRMSG5K	"SR5K"	/* 物理ﾎﾞﾘｭｰﾑが閉塞されました (pppppppp)TD78 */
						/*   pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名 			 */
#define	MRMSG5L "SR5L"	/* 現用系RBIﾌｱｲﾙ故障                    TD78 */
#define	MRMSG5M "SR5M"	/* 予備系RBIﾌｱｲﾙ故障                    TD78 */
#define	MRMSG5N "SR5N"	/* VRCV前処理終了(現用系)               TD90 */
#define	MRMSG5O "SR5O"	/* VRCV前処理終了(予備系)               TD90 */
#define	MRMSG5P	"SR5P"	/* 他系物理ﾎﾞﾘﾕ-ﾑ(pppppppp)閉塞失敗     TD90 */
						/*   pppppppp : 物理ﾎﾞﾘﾕ-ﾑ識別名			 */
#define	MRMSG5Q	"SR5Q"	/* JNLﾌｱｲﾙ初期化中						TD79 */
#define	MRMSG5R	"SR5R"	/* KJﾌｱｲﾙ初期化中						TD79 */
#define	MRMSG5S	"SR5S"	/* RBIﾌｱｲﾙ初期化中						TD79 */

/*********************************************************************/
/*	    8.ﾊﾞｯｸｱｯﾌﾟ ｼｮﾘ (BKUP)									     */
/*********************************************************************/

#define	MRMSG60	"SR60"	/*											 */
#define	MRMSG61	"SR61"	/* ｹﾞﾝﾖｳｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx ) ｶｲｼ   TD-46 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
#define	MRMSG62	"SR62"	/* ｹﾞﾝﾖｳｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx )	   TD-46 */ 
						/* ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ	 				   TD-46 */
						/*	code  =  eeee						 	 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	eeee : ｼｭｳﾘｮｳ ｺｰﾄﾞ	( DEC )				 */
#define	MRMSG63	"SR63"	/* ｹﾞﾝﾖｳｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx )	   TD-46 */ 
						/* ｲｼﾞｮｳ ｼｭｳﾘｮｳ	 					   TD-46 */
						/*	CD = eeee						   TD-49 */
						/*	DT = pppppppp					   TD-49 */
						/*	DT1 = qqqqqqqq					   TD-49 */
						/*	DT2 = rrrrrrrr					   TD-49 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	eeee 	 : 故障コード			   TD-49 */
						/*	pppppppp : 詳細情報				   TD-49 */
						/*	qqqqqqqq : 詳細情報２			   TD-49 */
						/*	rrrrrrrr : 詳細情報３			   TD-49 */
#define	MRMSG64	"SR64"	/* ﾖﾋﾞｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx ) ｶｲｼ	   TD-46 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
#define	MRMSG65	"SR65"	/* ﾖﾋﾞｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx ) 		   TD-46 */
						/* ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ					   TD-46 */
						/*	code  =  eeee							 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 eeee : ｼｭｳﾘｮｳ ｺｰﾄﾞ	( DEC )				 */
#define	MRMSG66	"SR66"	/* ﾖﾋﾞｹｲ ﾊﾞｯｸｱｯﾌﾟ ( xxxxxxxx ) 		   TD-46 */
						/* ｲｼﾞｮｳ ｼｭｳﾘｮｳ 					   TD-46 */
						/*	CD = eeee						   TD-49 */
						/*	DT = pppppppp					   TD-49 */
						/*	DT1 = qqqqqqqq					   TD-49 */
						/*	DT2 = rrrrrrrr					   TD-49 */
						/*  xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	eeee 	 : 故障コード			   TD-49 */
						/*	pppppppp : 詳細情報				   TD-49 */
						/*	qqqqqqqq : 詳細情報２			   TD-49 */
						/*	rrrrrrrr : 詳細情報３			   TD-49 */
#define	MRMSG67	"SR67"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｶｲｼ ( xxxxxxxx )    TD-46 */
						/*	p=pppppppp 	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll	 			   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG68	"SR68"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ			 */
						/*  ( xxxxxxxx )					   TD-46 */
						/*	p=pppppppp 	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll				   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG69	"SR69"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｲｼﾞｮｳ ｼｭｳﾘｮｳ				 */
						/*  ( xxxxxxxx )					   TD-46 */
						/*	p=pppppppp	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll	 			   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG6A	"SR6A"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｶｲｼ (ﾐﾗｰ)			TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */ 
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG6B	"SR6B"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ (ﾐﾗｰ)  TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */ 
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG6C	"SR6C"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｲｼﾞｮｳ ｼｭｳﾘｮｳ (ﾐﾗｰ)   TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG6D	"SR6D"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｷｬﾝｾﾙ (ﾐﾗｰ)			TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ		  	 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG6E	"SR6E"	/* KJ ﾌｧｲﾙ 2ｼﾞｭｳｺｼｮｳ ﾊﾞｯｸｱｯﾌﾟ ﾌｶ		TD42 */
						/*	(xxxxxxxx) kname = kkkkkkkk	  D-42 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 kkkkkkkk : KJ ﾌｧｲﾙﾒｲ			 		 */
#define	MRMSG6F	"SR6F"	/* KJ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｶｲｼ					TD42 */
						/*	(xxxxxxxx) kname = kkkkkkkk	 TD-42 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 kkkkkkkk : KJ ﾌｧｲﾙﾒｲ			 		 */
#define	MRMSG70	"SR70"	/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｷｬﾝｾﾙ ( xxxxxxxx )  TD-46 */
						/*	p=pppppppp	n=nnnnnnnn			   TD-22 */
						/*	l=llllllllllllllll			 		     */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 nnnnnnnn : ﾛﾝﾘﾎﾞﾘｭｰﾑｼｷﾍﾞﾂﾒｲ	   TD-22 */
						/*	 lll..lll : ﾌｧｲﾙｼｽﾃﾑﾅｼ ｷｬﾗｸﾀﾄｸｼｭﾌｧｲﾙﾒｲ	 */
#define	MRMSG71	"SR71"	/* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ 2ｼﾞｭｳｺｼｮｳ ﾊﾞｯｸｱｯﾌﾟ ﾌｶ   TD-@1 */
						/*	(xxxxxxxx) jname = jjjjjjjj		   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 jjjjjjjj : ｼﾞｬｰﾅﾙ ﾌｧｲﾙﾒｲ		   TD-27 */
#define	MRMSG72	"SR72"	/* 	ﾊﾞｯｸｱｯﾌﾟ ﾎﾞﾘｭｰﾑ I/O ｴﾗｰ ﾊｯｾｲ	   (L03) */
						/*	(xxxxxxxx) p=pppppppp 			   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
#define	MRMSG73	"SR73"	/* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｶｲｼ			   TD-27 */
						/*	(xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 jjjjjjjj : ｼﾞｬｰﾅﾙ ﾌｧｲﾙﾒｲ		   TD-27 */
#define	MRMSG74 "SR74"  /* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ  TD-27 */
						/*  (xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 jjjjjjjj : ｼﾞｬｰﾅﾙ ﾌｧｲﾙﾒｲ			 	 */
#define	MRMSG75 "SR75"  /* KJ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ  	   TD-27 */
						/*  (xxxxxxxx) kname = kkkkkkkk	 TD-27 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 kkkkkkkk : KJ ﾌｧｲﾙﾒｲ			 	 	 */
#define	MRMSG76 "SR76"  /* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｲｼﾞｮｳ ｼｭｳﾘｮｳ   TD-27 */
						/*  (xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 jjjjjjjj : ｼﾞｬｰﾅﾙ ﾌｧｲﾙﾒｲ			 	 */
#define	MRMSG77 "SR77"  /* KJ ﾌｧｲﾙ ﾊﾞｯｸｱｯﾌﾟ ｲｼﾞｮｳ ｼｭｳﾘｮｳ       TD-27 */
						/*  (xxxxxxxx) kname = kkkkkkkk	 TD-27 TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 kkkkkkkk : KJ ﾌｧｲﾙﾒｲ			 	 	 */
/*  ２重化アクセス廃止に伴い削除（２０行）						TD27 */
#define	MRMSG7A	"SR7A"	/* 	ｳﾗﾒﾝ I/O ｴﾗｰ ﾊｯｾｲ				   (L05) */
						/*	(xxxxxxxx) p=pppppppp ｳﾗ=uuuuuuuu  TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*	 pppppppp : ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
						/*	 uuuuuuuu : ｳﾗﾒﾝ ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ	 */
#define	MRMSG7B	"SR7B"	/* 	ｼﾃｲ ﾊﾞｯｸｱｯﾌﾟID ｲｼﾞｮｳ (xxxxxxxx)	    TD46 */
						/*   xxxxxxxx : ﾊﾞｯｸ ｱｯﾌﾟ ID		   TD-46 */
#define	MRMSG7C	"SR7C"	/* 	ｼﾃｲ ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ ｲｼﾞｮｳ	   (L06) */
						/*	(xxxxxxxx) l=llllllll			   TD-46 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			   TD-46 */
						/*   llllllll : ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ｼｷﾍﾞﾂﾒｲ			 */
#define	MRMSG7D	"SR7D"	/* 	ﾊﾟﾗﾒﾀ ｲｼﾞｮｳ				   	 (L06) TD-46 */
/*  バックアップ変更に伴い削除（５行）						   TD-46 */
/*  ２重化アクセス廃止に伴い削除（２行）					   TD-27 */

/*********************************************************************/
/*	    9.ﾎﾞﾘｭ-ﾑ ﾘｶﾊﾞﾘ ﾎﾝﾀｲ (VRCV)						   		     */ 
/*********************************************************************/

#define	MRMSG80	"SR80"	/* 現用系ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ開始			    TD00 */
#define	MRMSG81	"SR81"	/* 予備系ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ開始			    TD00 */
#define	MRMSG82	"SR82"	/* 現用系ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ終了				TD00 */
						/* (cccccccc)							TD00 */
						/* cccccccc : 返却値					TD00 */
#define	MRMSG83	"SR83"	/* 予備系ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ終了				TD00 */
						/* (cccccccc)							TD00 */
						/* cccccccc : 返却値					TD00 */
#define	MRMSG84	"SR84"	/* バックアップ起動中					TD00 */
#define	MRMSG85	"SR85"	/* 論理ﾎﾞﾘｭｰﾑﾘｽﾄｱ開始					TD90 */
						/* (llllllll ssssssss)					TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* ssssssss : 処理内容					TD00 */	
						/* 1 : ﾊﾞｯｸｱｯﾌﾟﾃﾞｰﾀからのﾘｽﾄｱ			TD00 */
						/* 2 : 一般ﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 3 : RCVﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 4 : ﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 5 : ﾐﾗｰﾎﾞﾘｭｰﾑ復旧					TD00 */
#define	MRMSG86	"SR86"	/* ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ非対象ﾎﾞﾘｭｰﾑ存在			TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSG87	"SR87"	/* 論理ﾎﾞﾘｭｰﾑﾘｽﾄｱ終了					TD90 */
						/* (llllllll ssssssss)					TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* ssssssss : 処理内容					TD00 */	
						/* 1 : ﾊﾞｯｸｱｯﾌﾟﾃﾞｰﾀからのﾘｽﾄｱ			TD00 */
						/* 2 : 一般ﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 3 : RCVﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 4 : ﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化				TD00 */
						/* 5 : ﾐﾗｰﾎﾞﾘｭｰﾑ復旧					TD00 */
#define	MRMSG88	"SR88"	/* ﾎﾞﾘｭｰﾑﾘｽﾄｱ開始						TD00 */
						/* (pppppppp dddddddd)					TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */		 
#define	MRMSG89	"SR89"	/* ﾎﾞﾘｭｰﾑﾘｽﾄｱ終了						TD00 */
						/* (cccccccc pppppppp)					TD00 */
						/* cccccccc : 返却値					TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSG90	"SR90"	/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑ未存在					TD00 */
						/* (llllllll pppppppp)					TD00 */		 
						/* llllllll : 論理ボリューム識別名		TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSG91	"SR91"	/* ﾊﾞｯｸｱｯﾌﾟｼﾞｬｰﾅﾙからの復旧開始			TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */		 
#define	MRMSG92	"SR92"	/* ﾊﾞｯｸｱｯﾌﾟｼﾞｬｰﾅﾙからの復旧終了			TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */		 
#define	MRMSG93	"SR93"	/* ｼﾞｬｰﾅﾙﾚｺｰﾄﾞｴﾗｰ						TD00 */
						/* (nnnnnnnn)							TD00 */
						/* nnnnnnnn : JNLﾚｺｰﾄﾞ通番				TD00 */
#define	MRMSG94	"SR94"	/* ｼﾞｬｰﾅﾙﾃﾞｰﾀｴﾗｰ						TD00 */
						/* (iiii ss nnnnnnnn)					TD00 */
						/* iiii : JNLﾃﾞｰﾀ数						TD00 */
						/* ss : JNLﾃﾞｰﾀID						TD00 */
						/* nnnnnnnn : JNLﾚｺｰﾄﾞ通番				TD00 */ 
#define	MRMSG95	"SR95"	/* ﾊﾞｯｸｱｯﾌﾟｼﾞｬｰﾅﾙ異常					TD00 */
						/* (llllllll nnnnnnnn)					TD00 */
						/* llllllll : 論理ボリューム識別名		TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */
#define	MRMSG96	"SR96"	/* ﾄｳｼﾞﾂ ｼﾞｬｰﾅﾙ ｶﾗ ﾉ ﾌｯｷｭｳ ｶｲｼ				 */
#define	MRMSG97	"SR97"	/* ﾄｳｼﾞﾂ ｼﾞｬｰﾅﾙ ｶﾗ ﾉ ﾌｯｷｭｳ ｼｭｳﾘｮｳ			 */
#define	MRMSG98	"SR98"	/* ｼﾃｲ ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ﾐ ｿﾝｻﾞｲ 					 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSG99	"SR99"	/* ﾘｽﾄｱ ﾀｲｼｮｳ ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ﾐ ｿﾝｻﾞｲ			 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGA0	"SRA0"	/* ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ﾐ ｼﾃｲ						 */
#define	MRMSGA1	"SRA1"	/* 復旧ﾎﾞﾘｭｰﾑ故障						TD00 */
						/* (cccccccc llllllll)					TD00 */
						/* cccccccc : 論理ﾎﾞﾘｭｰﾑｴﾗｰｺｰﾄﾞ			TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGA2	"SRA2"	/* 物理ﾎﾞﾘｭｰﾑ復旧正常終了				TD00 */
						/* (pppppppp dddddddd)					TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */		 
#define	MRMSGA3	"SRA3"	/* 物理ﾎﾞﾘｭｰﾑ復旧異常終了					 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGA4	"SRA4"	/* 当日ｼﾞｬｰﾅﾙ異常						TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGA5	"SRA5"	/* ﾘｽﾄｱ 'FJ' ﾌｯｷｭｳ ﾚﾝｿﾞｸ ｼﾃｲ ﾌｶ				 */
#define	MRMSGA6	"SRA6"	/* ﾘｽﾄｱ 'FJ' ﾌｯｷｭｳ ﾀﾝﾄﾞｸ ｼﾃｲ ﾌｶ				 */
#define	MRMSGA7	"SRA7"	/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑ故障					TD00 */
						/* (bbbbbbb llllllll)						 */
						/* bbbbbbbb : ﾊﾞｯｸｱｯﾌﾟ論理ﾎﾞﾘｭｰﾑ識別名	TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGA8	"SRA8"	/* ﾊﾞｯｸｱｯﾌﾟID指定不正				  	TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */
#define	MRMSGA9	"SRA9"	/* 物理ﾎﾞﾘｭｰﾑ回復完了					TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGB0	"SRB0"	/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽ強制終了				TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
/* ボリューム閉塞単位変更に伴う削除（１行）						TD90 */ 
#define	MRMSGB2	"SRB2"	/* ﾎﾞﾘｭｰﾑ初期化処理異常終了				TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGB3	"SRB3"	/* 閉塞された物理ﾎﾞﾘｭｰﾑが存在する		TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGB4	"SRB4"	/* ＶＲＣＶ前処理起動中					TD90 */
#define	MRMSGB5	"SRB5"	/* ＶＲＣＶ対象論理ボリューム未存在		TD90 */
						/* (pppppppp)							TD00 */
						/* pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			TD00 */
#define	MRMSGB6	"SRB6"	/* 論理ﾎﾞﾘｭｰﾑ復旧正常終了				TD90 */
						/* (llllllll dddddddd)					TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* dddddddd : ﾊﾞｯｸｱｯﾌﾟID				TD00 */		 
#define	MRMSGB7	"SRB7"	/* 論理ﾎﾞﾘｭｰﾑ復旧異常終了				TD90 */
						/* (llllllll cccccccc)					TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */
						/* cccccccc : 要因コード				TD00 */
#define	MRMSGB8	"SRB8"	/* 論理ﾎﾞﾘｭｰﾑ回復完了					TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : 論理ﾎﾞﾘｭｰﾑ識別名			TD00 */

/*********************************************************************/
/*	    10.サブ故障管理											TD00 */
/*********************************************************************/
#define	MRMSGC0	"SRC0"	/* ﾊﾞｯﾃﾘｰ故障							TD02 */
#define	MRMSGC1 "SRC1"	/* (pppppppp)閉塞失敗(dddddddd)			TD02 */
						/*  pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名		ST3492	 */
						/*	dddddddd : 詳細ｺｰﾄﾞ(返却値)			     */
#define	MRMSGC2 "SRC2"  /* (pppppppp)閉塞解除失敗(dddddddd)		TD02 */
						/*  pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名		ST3492	 */
						/*	dddddddd : 詳細ｺｰﾄﾞ(返却値)			     */

						/* ﾎﾞﾘﾕ-ﾑ初期化ﾌﾟﾛｾｽ廃止に伴う削除(12行)TD@1 */

/*********************************************************************/
/*	    11.RCV ﾌｧｲﾙ ｿｳｾｲ･ｶｲﾌｸ ｼｮﾘ								     */
/*********************************************************************/

#define	MRMSGE0	"SRE0"	/* ﾌﾟﾛｸﾞﾗﾑ ﾓ-ﾄﾞ ｴﾗ-							 */
#define	MRMSGE1	"SRE1"	/* ﾘｶﾊﾞﾘ ﾓ-ﾄﾞ ｴﾗ-							 */
#define	MRMSGE2	"SRE2"	/* nnnn ﾃ-ﾌﾞﾙ ﾐﾃｲｷﾞ ｴﾗ-					 	 */
						/*	 nnnn : ﾐﾃｲｷﾞ ﾃ-ﾌﾞﾙ ﾒｲ					 */
#define	MRMSGE3	"SRE3"	/* nnnn ﾃ-ﾌﾞﾙ ﾌﾄｳ ｴﾗ-						 */
						/*	 nnnn : ﾌﾄｳ ﾃ-ﾌﾞﾙ ﾒｲ					 */
#define	MRMSGE4	"SRE4"	/* nnnn ﾌｧｲﾙ ﾖｳ TFMT ﾐﾃｲｷﾞ ｴﾗ-				 */
						/* （ llllllll ）				      (TD42) */
						/*	 nnnn : "RBI " ﾏﾀﾊ "JNL "				 */
						/*	 llllllll : RCVﾌｧｲﾙ名			  (TD42) */
#define	MRMSGE5	"SRE5"	/* nnnn ﾌｧｲﾙ ﾖｳ TFMT ｼｮｷﾖｳﾘｮｳ ｴﾗ-			 */
						/* （ llllllll ）					  (TD42) */
						/*	 nnnn : "RBI " ﾏﾀﾊ "JNL "				 */
						/*	 llllllll : RCVﾌｧｲﾙ名			  (TD42) */
#define	MRMSGE6	"SRE6"	/* nnnn ﾌｧｲﾙ ﾖｳ ﾎﾞﾘｭ-ﾑ ﾌﾄｳ ｴﾗ-			 	 */
						/* （ llllllll ）					  (TD42) */
						/*	 nnnn : "RBI " ﾏﾀﾊ "JNL "				 */
						/*	 llllllll : RCVﾌｧｲﾙ名			  (TD42) */
#define	MRMSGE7	"SRE7"	/* nnnn ﾌｧｲﾙ ｱｸｾｽ ｴﾗ-						 */
						/*	( llllllll , oooooooo , dddddddd )		 */
						/*	 nnnn     : "RBI " ﾏﾀﾊ "JNL "			 */
						/*	 llllllll : RCV ﾌｧｲﾙ ﾒｲ					 */
						/*	 oooooooo : ｼｽﾃﾑ ｺ-ﾙ 			 		 */
						/*   dddddddd : ｼｮｳｻｲ ｺ-ﾄﾞ (HEX)		 	 */
#define	MRMSGE8	"SRE8"	/* nnnn ﾃﾞｨﾚｸﾄﾘ ｱｸｾｽ ｴﾗ-					 */
						/*	( llllllll , oooooooo , dddddddd )		 */
						/*	 nnnn     : "RBI " ﾏﾀﾊ "JNL "			 */
						/*	 llllllll : RCV ﾌｧｲﾙ ﾒｲ					 */
						/*	 oooooooo : ｼｽﾃﾑ ｺ-ﾙ 					 */
						/*   dddddddd : ｼｮｳｻｲ ｺ-ﾄﾞ (HEX)			 */
#define	MRMSGE9	"SRE9"	/* ﾊﾟﾗﾒﾀ ｴﾗ-								 */
#define MRMSGEA "SREA"  /* 起動元ﾌﾟﾛｾｽｴﾗｰ					  (TD79) */
#define MRMSGEB "SREB"  /* SMP日付取得ｴﾗｰ					  (TD92) */
#define	MRMSGEC	"SREC"	/* ＲＢＩ定周期取得停止失敗(dddddddd) CT1085 */
						/* dddddddd : RBI完了通知電文通知コード		 */
#define	MRMSGF0	"SRF0"	/* nnnn ﾌｧｲﾙ ｿｳｾｲ ｶｲｼ ( llllllll )		 	 */
						/*	 nnnn     : "RBI " ﾏﾀﾊ "JNL "			 */
						/*	 llllllll : ｿｳｾｲ ﾌｧｲﾙ ﾒｲ				 */
#define	MRMSGF1	"SRF1"	/* nnnn ﾌｧｲﾙ ｿｳｾｲ ｼｭｳﾘｮｳ ( llllllll )	 	 */
						/*	 nnnn     : "RBI " ﾏﾀﾊ "JNL "			 */
						/*	 llllllll : ｿｳｾｲ ﾌｧｲﾙ ﾒｲ				 */
/*  ２重化アクセスの廃止に伴う削除（６行）				      (TD27) */
#define	MRMSGF4	"SRF4"	/* RCV ﾌｧｲﾙ ｿｳｾｲ ｶｲﾌｸ ｼｮﾘ ｼｭｳﾘｮｳ ( dddddddd )*/
						/*   dddddddd : ｼｭｳﾘｮｳ ｺ-ﾄﾞ					 */
#define	MRMSGF5	"SRF5"	/* nnnn占有失敗(eeeeeeee oooooooo dddddddd)  */
						/*									CT1085	 */
						/*   nnnn : 占有失敗テーブル名				 */
						/*   eeeeeeee : mf_renq返却値				 */
						/*   oooooooo : システムコール種別			 */
						/*   dddddddd : システムコール返却値		 */
#define	MRMSGF6	"SRF6"	/* 受信電文破棄失敗(oooooooo dddddddd) CT1085*/
						/*   oooooooo : システムコール				 */
						/*   dddddddd : システムコール返却値		 */
#define	MRMSGF7	"SRF7"	/* ＲＢＩ取得プロセスがＴＰＣＴにない CT1085 */
#define	MRMSGF8	"SRF8"	/* ＲＢＩ定周期取得停止依頼電文用	  CT1085 */
						/* プールバッファの確保失敗					 */
						/* (eeeeeeee oooooooo dddddddd)				 */	
						/*   eeeeeeee : mr_cgbf返却値				 */
						/*   oooooooo : システムコール種別			 */
						/*   dddddddd : システムコール返却値		 */
#define	MRMSGF9	"SRF9"	/* ＲＢＩ取得プロセスへの電文送信失敗 CT1085 */
						/* (oooooooo dddddddd)				 	  	 */	
						/*   oooooooo : システムコール名			 */
						/*   dddddddd : システムコール返却値		 */
#define	MRMSGFA	"SRFA"	/* ＲＢＩ完了通知電文受信失敗		  CT1085 */
						/* (oooooooo dddddddd)				 	  	 */	
						/*   oooooooo : システムコール名			 */
						/*   dddddddd : システムコール返却値		 */
#define	MRMSGFB	"SRFB"	/* ＲＢＩ完了通知電文受信失敗 		  CT1085 */
						/* （タイムオーバー）						 */

/*********************************************************************/
/*	    12.ｻﾌﾞｼｽﾃﾑ ﾘｶﾊﾞﾘ (SSRCV)									 */
/*********************************************************************/
#define	MRMSGG0	"SRG0"	/* PU0開始ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGG1	"SRG1"	/* PU0終了ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGG2	"SRG2"	/* PU1開始ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGG3	"SRG3"	/* PU1終了ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */

/*********************************************************************/
/*	    13.先行 ﾘｶﾊﾞﾘ (ARCV)										 */
/*********************************************************************/
#define	MRMSGH0	"SRH0"	/* PU0開始ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGH1	"SRH1"	/* PU0終了ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGH2	"SRH2"	/* PU1開始ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */
#define	MRMSGH3	"SRH3"	/* PU1終了ﾒｯｾｰｼﾞ(液晶パネル)			TD39 */

/*********************************************************************/
/*      14.ﾎﾞﾘｭｰﾑﾘｶﾊﾞﾘ(FJ無し)										 */
/*********************************************************************/
#define	MRMSGI0	"SRI0"	/* 現用系ボリュームリカバリ開始			TD99 */
#define	MRMSGI1	"SRI1"	/* 予備系ボリュームリカバリ開始			TD99 */
#define	MRMSGI2	"SRI2"	/* 現用系ボリュームリカバリ終了			TD99 */
						/*	CD = cccccccc						 	 */
						/*	 cccccccc : 終了ｺｰﾄﾞ(10進)				 */
#define	MRMSGI3	"SRI3"	/* 予備系ボリュームリカバリ終了			TD99 */
						/*	CD = cccccccc							 */
						/*	 cccccccc : 終了ｺｰﾄﾞ(10進)				 */
#define	MRMSGI4	"SRI4"	/* リカバリ不要システムである			TD99 */
#define	MRMSGI5	"SRI5"	/* ホットスタンバイ構成予備系で起動		TD99 */
						/* された									 */
#define	MRMSGI6	"SRI6"	/* テーブルエラー		        		TD99 */
						/* TBL = xxxxxxxx							 */
						/*	 xxxxxxxx : ﾃｰﾌﾞﾙ名(ｷｬﾗｸﾀ)				 */
#define	MRMSGI7	"SRI7"	/* ボリュームコピープロセス起動中		TD99 */
#define	MRMSGI8	"SRI8"	/* パラメタ形式不当						TD99 */
#define	MRMSGI9	"SRI9"	/* 指定バックアップＩＤ異常		 			 */
						/* ID = bbbbbbbb							 */
						/*	 bbbbbbbb : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
#define	MRMSGIA	"SRIA"	/* バックアップ中						TD99 */
#define	MRMSGIB	"SRIB"	/* ＶＲＣＶ前処理中						TD99 */
#define	MRMSGIC	"SRIC"	/* 先行リカバリ中						TD99 */
#define	MRMSGID	"SRID"	/* 指定物理ボリューム名異常  PN = pppppppp	 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGIE	"SRIE"	/* 物理ボリューム閉塞解除失敗（自系）	TD99 */
						/*	PN = pppppppp  CD = xxxxxxxx			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*   xxxxxxxx : osconfig返却値				 */
#define	MRMSGIF	"SRIF"	/* 指定論理ボリューム名不正  LN = vvvvvvvv   */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ0	"SRJ0"	/* バックアップ不要論理ボリューム指定	TD99 */
						/*	LN = vvvvvvvv							 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ1	"SRJ1"	/* 指定論理ボリューム故障中  LN = vvvvvvvv   */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ2	"SRJ2"	/* 指定論理ボリューム使用中  LN = vvvvvvvv	 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ3	"SRJ3"	/* 論理ﾎﾞﾘｭｰﾑ回復完了(ﾊﾞｯｸｱｯﾌﾟ要ﾎﾞﾘｭｰﾑ)	TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp  			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ4	"SRJ4"	/* 削除ファイルが存在します					 */  
						/*	FN = ffffffff				 			 */
						/*	 ffffffff = 削除ﾌｧｲﾙ名					 */
#define	MRMSGJ5	"SRJ5"	/* 論理ﾎﾞﾘｭｰﾑ回復完了(ﾊﾞｯｸｱｯﾌﾟ不要ﾎﾞﾘｭｰﾑ)TD99*/
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ6	"SRJ6"	/* 論理ﾎﾞﾘｭｰﾑ回復完了(ﾘｶﾊﾞﾘﾌｧｲﾙﾎﾞﾘｭｰﾑ)	TD99 */
						/*  PN = pppppppp  LN = vvvvvvvv 			 */
						/*  FN = ffffffff,ffffffff,････････			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 ffffffff : 収容ﾌｧｲﾙ名					 */
#define	MRMSGJ7	"SRJ7"	/* 論理ﾎﾞﾘｭｰﾑ回復完了(ﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑ)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ8	"SRJ8"	/* 論理ﾎﾞﾘｭｰﾑ回復完了(ﾐﾗｰﾎﾞﾘｭｰﾑ復旧)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJ9	"SRJ9"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(回復先I/Oｴﾗｰ)		TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  FN = ffffffff  SC = ssssssss     		 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 ffffffff : 対象ﾌｧｲﾙ名					 */
						/*	 ssssssss : システムコール種別			 */
						/*	 xxxxxxxx : システムコール返却値		 */
#define	MRMSGJA	"SRJA"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(回復元I/Oｴﾗｰ)		TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJB	"SRJB"	/* リカバリファイル創成プロセス起動失敗	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  FN = ffffffff  				     		 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
						/*   ffffffff : 収容ﾌｧｲﾙ名					 */
#define	MRMSGJC	"SRJC"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(ﾐﾗｰﾎﾞﾘｭｰﾑ復旧)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
						/*   xxxxxxxx : osioctl返却値				 */
#define	MRMSGJD	"SRJD"	/* ホットスタンバイ構成予備系ダウン		TD99 */
#define	MRMSGJE	"SRJE"	/* プロセス終了要求受信					TD99 */
#define	MRMSGJF	"SRJF"	/* 物理ボリューム閉塞解除失敗（他系）	TD99 */
						/*	PN = pppppppp							 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJG	"SRJG"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(ﾊﾞｯｸｱｯﾌﾟﾃﾞｰﾀ無)	TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJH	"SRJH"	/* リカバリファイル初期化中				TD99 */
#define	MRMSGJI	"SRJI"	/* リカバリファイル創成プロセス起動中	TD99 */
#define	MRMSGJJ	"SRJJ"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(mrc回復先I/Oｴﾗｰ)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJK	"SRJK"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(mri回復先I/Oｴﾗｰ)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
#define	MRMSGJL	"SRJL"	/* 論理ﾎﾞﾘｭｰﾑ回復失敗(vdi回復先I/Oｴﾗｰ)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名			 */
						/*	 vvvvvvvv : 論理ﾎﾞﾘｭｰﾑ識別名			 */
						/*   xxxxxxxx : ｼｽﾃﾑｺｰﾙ返却値				 */

/*********************************************************************/
/*	    15.余り(ＳＲＫ０〜ＳＲＫＺ）								 */
/*********************************************************************/

/*********************************************************************/
/*	    16.ﾊﾞｯｸｱｯﾌﾟﾌﾟﾛｾｽ(JNL2面構成)							     */
/*********************************************************************/
#define	MRMSGL0	"SRL0"	/* 現用系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始 ID = xxxxxxxx*/
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
#define	MRMSGL1	"SRL1"	/* 現用系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了			 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 終了ｺｰﾄﾞ(DEC)			     */
#define	MRMSGL2	"SRL2"	/* 現用系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了			 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGL3	"SRL3"	/* 現用系／勘定照合ﾌｧｲﾙ面切替開始			 */
#define	MRMSGL4	"SRL4"	/* 現用系／勘定照合ﾌｧｲﾙ面切替正常終了		 */
						/*  CD = eeee							 	 */
						/*   eeee : 終了ｺｰﾄﾞ(DEC)					 */
#define	MRMSGL5	"SRL5"	/* 現用系／勘定照合ﾌｧｲﾙ面切替異常終了		 */
						/*  CD = eeee  DT = pppppppp  DT1 = qqqqqqqq */
						/*  DT2 = rrrrrrrr						     */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGL6	"SRL6"	/* 現用系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
#define	MRMSGL7	"SRL7"	/* 現用系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了		 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 終了ｺｰﾄﾞ(DEC)			     */
#define	MRMSGL8	"SRL8"	/* 現用系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了		 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGL9	"SRL9"	/* 予備系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始 			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
#define	MRMSGLA	"SRLA"	/* 予備系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了			 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 終了ｺｰﾄﾞ(DEC)			     */
#define	MRMSGLB	"SRLB"	/* 予備系／一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了			 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGLC	"SRLC"	/* 予備系／勘定照合ﾌｧｲﾙ面切替開始			 */
#define	MRMSGLD	"SRLD"	/* 予備系／勘定照合ﾌｧｲﾙ面切替正常終了		 */
						/*  CD = eeee							 	 */
						/*   eeee : 終了ｺｰﾄﾞ(DEC)					 */
#define	MRMSGLE	"SRLE"	/* 予備系／勘定照合ﾌｧｲﾙ面切替異常終了		 */
						/*  CD = eeee  DT = pppppppp DT1 = qqqqqqqq  */
						/*  DT2 = rrrrrrrr						 	 */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGLF	"SRLF"	/* 予備系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */

#define	MRMSGM0	"SRM0"	/* 予備系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了		 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 終了ｺｰﾄﾞ(DEC)			     */
#define	MRMSGM1	"SRM1"	/* 予備系／勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了		 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID(ｷｬﾗｸﾀ)			 */
						/*   eeee     : 故障ｺｰﾄﾞ(HEX)				 */
						/*   pppppppp : 詳細情報(HEX)				 */
						/*   qqqqqqqq : 詳細情報1(HEX)				 */
						/*   rrrrrrrr : 詳細情報2(HEX)				 */
#define	MRMSGM2	"SRM2"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ開始  ID = xxxxxxxx	 */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGM3	"SRM3"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ正常終了  ID = xxxxxxxx */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGM4	"SRM4"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ異常終了  ID = xxxxxxxx */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGM5	"SRM5"	/* 待機面JNLｱｸｾｽｴﾗｰ							 */
#define	MRMSGM6	"SRM6"	/* 待機面KJｱｸｾｽｴﾗｰ							 */
#define	MRMSGM7	"SRM7"	/* 待機面KJ故障中の為KJﾊﾞｯｸｱｯﾌﾟ不可			 */
						/*  ID = XXXXXXXX					 		 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			 		 */
#define	MRMSGM8	"SRM8"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始	 ID = xxxxxxxxx  */ 
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGM9	"SRM9"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了				 */ 
						/*  ID = xxxxxxxx  P = pppppppp  L = llllllll*/
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGMA	"SRMA"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了				 */ 
						/*  ID = xxxxxxxx  P = pppppppp  L = llllllll*/
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGMB	"SRMB"	/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑI/Oｴﾗｰ発生	 ID = xxxxxxxx   */
						/*  P = pppppppp			 				 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			 		 */
						/*   pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名 	 		 */
#define	MRMSGMC	"SRMC"	/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑ裏面I/Oｴﾗｰ発生 			 */
						/*  ID = xxxxxxxx  P = pppppppp  			 */
						/*  UP = qqqqqqqq							 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			 		 */
						/*   pppppppp : 物理ﾎﾞﾘｭｰﾑ識別名 	 		 */
						/*   qqqqqqqq : 裏面物理ﾎﾞﾘｭｰﾑ識別名  		 */
#define	MRMSGMD	"SRMD"	/* ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟｷｬﾝｾﾙ ID = xxxxxxxx		 */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名 	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
/* 削除（１行）												ST4036	 */
#define	MRMSGMF	"SRMF"	/* 指定論理ﾎﾞﾘｭｰﾑ識別名異常 ID = xxxxxxxx	 */
						/*  L = llllllll							 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID			 		 */
						/*   llllllll : 論理ﾎﾞﾘｭｰﾑ識別名     		 */
#define	MRMSGMG	"SRMG"	/* VRCVﾌﾟﾛｾｽｷｬﾝｾﾙ成功				CT1163	 */
#define	MRMSGMH	"SRMH"	/* VRCVﾌﾟﾛｾｽｷｬﾝｾﾙ失敗				CT1163	 */
						/*  RC = rrrrrrrr ST = ssss					 */
						/*   rrrrrrrr : mo_excm返却値				 */
						/*   ssss     : ﾌﾟﾛｾｽｽﾃｰﾀｽ					 */
#define	MRMSGMI	"SRMI"	/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽｷｬﾝｾﾙ成功			CT1163	 */
						/*  PNAME = nnnnnnnn						 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名					 */
#define	MRMSGMJ	"SRMJ"	/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽｷｬﾝｾﾙ失敗			CT1163	 */
						/*   RC = rrrrrrrr ST = ssss PNAME = nnnnnnnn */
						/*   rrrrrrrr : mo_excm返却値				 */
						/*   ssss     : ﾌﾟﾛｾｽｽﾃｰﾀｽ					 */
						/*   nnnnnnnn : ﾌﾟﾛｾｽ識別名					 */

/* 削除（１行）												ST4036	 */
#define	MRMSGN2	"SRN2"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ開始(ﾐﾗｰ) ID = xxxxxxxx */
						/*  P1 = pppppppp  P2 = qqqqqqqq			 */
						/*  L = llllllll  F = nnnnnnnnnnnnnnnn		 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN3	"SRN3"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ正常終了(ﾐﾗｰ)			 */
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN4	"SRN4"	/* 論理ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟ異常終了(ﾐﾗｰ)			 */
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN5	"SRN5"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ開始(ﾐﾗｰ)			 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN6	"SRN6"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ正常終了(ﾐﾗｰ)		 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN7	"SRN7"	/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ異常終了(ﾐﾗｰ)		 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN8	"SRN8"	/* ﾎﾞﾘｭｰﾑﾊﾞｯｸｱｯﾌﾟｷｬﾝｾﾙ(ﾐﾗｰ)  ID = xxxxxxxx   */
						/*  P1 = pppppppp  P2 = qqqqqqqq			 */
						/*  L = llllllll  F = nnnnnnnnnnnnnnnn		 */
						/*   xxxxxxxx         : ﾊﾞｯｸｱｯﾌﾟID			 */
						/*   pppppppp         : 物理ﾎﾞﾘｭｰﾑ識別名1	 */
						/*   qqqqqqqq         : 物理ﾎﾞﾘｭｰﾑ識別名2	 */
						/*   llllllll         : 論理ﾎﾞﾘｭｰﾑ識別名     */
						/*   nnnnnnnnnnnnnnnn : ﾌｧｲﾙ無ｷｬﾗｸﾀ特殊ﾌｧｲﾙ名*/
#define	MRMSGN9	"SRN9"	/* 故障JNL/KJﾌｧｲﾙ有面切替不可		  CT1086 */
#define	MRMSGNA	"SRNA"	/* バックアップボリューム故障発生	  CT1086 */
						/*  ID = xxxxxxxx  VBTE = vvvv  SC = nnnnnnnn*/
						/*  RC = eeee								 */
						/*   xxxxxxxx : ﾊﾞｯｸｱｯﾌﾟID					 */
						/*   vvvv     : 故障VBTｴﾝﾄﾘ番号				 */
						/*   nnnnnnnn : システムコール名			 */
						/*   eeee     : システムコール返却値		 */
#define	MRMSGNB	"SRNB"	/* ジャーナルファイル２重故障発生	  CT1086 */
						/*  SC = nnnnnnnn  RC = eeee				 */
						/*   nnnnnnnn : システムコール名			 */
						/*   eeee     : システムコール返却値		 */
/*********************************************************************/
/*	    17.ミラーリング制御同期保証				CT0881			     */
/*********************************************************************/
#define	MRMSGO1	"SRO1"	/* ＳＰＭ待避ファイルI/Oエラー(mmmm)		 */
						/* SID = rrrrrrrr  RCD = rrrrrrrr			 */
						/*   mmmm     : モジュールID		CT1118	 */
						/*   ssssssss : ｼｽﾃﾑｺｰﾙ名					 */
						/*   rrrrrrrr : ｼｽﾃﾑｺｰﾙ返却値				 */
#define	MRMSGO2	"SRO2"	/* ミラーボリューム復旧可能  VOL = vvvvvvvv  */
						/*   vvvvvvvv : 論理ボリューム識別名		 */
#define	MRMSGO3	"SRO3"	/* ミラーボリューム復旧不可能  VOL = vvvvvvvv*/
						/* ERRTYPE = ee  ERRCODE = rrrrrrrr			 */
						/*   vvvvvvvv : 論理ボリューム識別名		 */
						/*   ee		  : エラー種別					 */
						/*   rrrrrrrr : エラーコード				 */
#define	MRMSGO4	"SRO4"	/* ミラー特殊ファイルI/Oエラー(mmmm)		 */
						/* VOL=vvvvvvvv  FNAME = ffffffffffffffff    */
						/* OSTYPE=oooooooo  OSRET = rrrrrrrr		 */
						/*   mmmm             : ﾓｼﾞﾕ-ﾙID	CT1118	 */
						/*   rrrrrrrr         : 論理ボリューム識別名 */
						/*   ffffffffffffffff : ﾌｧｲﾙ無しｷｬﾗｸﾀ特殊ﾌｧｲﾙ*/
						/*   oo               : システムコール種別	 */
						/*   rrrrrrrr         : システムコール返却値 */
#define	MRMSGO5	"SRO5"	/* ミラーリング制御エラー(mmmm)		CT1118	 */
						/*  VOL = vvvvvvvv  FNAME = ffffffffffffffff */
						/*  REQ = ssssssss  OSRET = rrrrrrrr		 */
						/*   mmmm             : ﾓｼﾞﾕ-ﾙID	CT1118	 */
						/*   vvvvvvvv         : 論理ボリューム識別名 */
						/*   ffffffffffffffff : ﾌｧｲﾙ無しｷｬﾗｸﾀ特殊ﾌｧｲﾙ*/
						/*   ssssssss         : 要求識別子	CT1118   */
						/*   rrrrrrrr         : システムコール返却値 */
#define	MRMSGO6	"SRO6"	/* ミラーリング制御矛盾(mmmm)		CT1118	 */
						/*  VOL = vvvvvvvv  FNAME = ffffffffffffffff */
					    /*  MS = llllllll  							 */
						/*   mmmm             : ﾓｼﾞﾕ-ﾙID	CT1118	 */
						/*   vvvvvvvv         : 論理ボリューム識別名 */
						/*   ffffffffffffffff : ﾌｧｲﾙ無しｷｬﾗｸﾀ特殊ﾌｧｲﾙ*/
						/*   llllllll         : ﾐﾗ-制御状態 CT1118	 */
#define	MRMSGO7	"SRO7"	/* 特定ＡＰがＴＰＣＴに存在しない			 */
						/* APNAME = aaaaaaaa						 */
						/*   aaaaaaaa : 特定ＡＰプロセス識別名		 */
#define	MRMSGO8	"SRO8"	/* 電文送信失敗  VOL = vvvvvvvv				 */
						/* FNAME = ffffffffffffffff  OSTYPE = oo     */
						/* OSRET = rrrrrrrr							 */
						/*   vvvvvvvv         : 論理ボリューム識別名 */
						/*   ffffffffffffffff : ﾌｧｲﾙ無しｷｬﾗｸﾀ特殊ﾌｧｲﾙ*/
						/*   oo               : システムコール種別	 */
						/*   rrrrrrrr         : システムコール返却値 */
						/*					ST3026					 */
#define	MRMSGO9 "SRO9"	/* ＳＰＭ待避ファイルサイズエラー			 */
						/* SIZE = ssssssss MUSTSIZE = mmmmmmmm		 */ 
						/*	 ssssssss		  : 現サイズ			 */
						/*	 mmmmmmmm		  :	最低限必要なサイズ	 */
#define	MRMSGOA "SROA"	/* ttttテーブルエラー(mmmm)			CT1118	 */
						/*   tttt : テーブル名				CT1118	 */
						/*   mmmm : モジュールID			CT1118   */
#define	MRMSGOB "SROB"	/* システムコールエラー(mmmm)		CT1118	 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm     : モジュールID		CT1118	 */
						/*   oooooooo : システムコール種別	CT1118	 */
						/*   rrrrrrrr : システムコール返却値CT1118	 */
#define	MRMSGOC	"SROC"	/* ミラーボリュームI/Oエラー(mmmm)  CT1118	 */
						/*  VOL = vvvvvvvv  ID = iiiiiiiiiiii		 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm    		  : モジュールID		 */
						/*   vvvvvvvv         : 論理ボリューム識別名 */
						/*   iiiiiiiiiiii	  : 装置ID				 */
						/*   oooooooo         : システムコール種別	 */
						/*   rrrrrrrr         : システムコール返却値 */
#define	MRMSGOD	"SROD"	/* ＪＮＬファイルI/Oエラー(mmmm)			 */
						/*  FNAME = ffffffff  KEI = s				 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm      : モジュールID		 		 */
						/*   ffffffff  : ＪＮＬファイル名			 */
						/*   s		   : 種別						 */
						/*               'M'-両系 'S'-正系 'F'-副系	 */
						/*   oooooooo  : システムコール種別	 		 */
						/*   rrrrrrrr  : システムコール返却値 		 */
#define	MRMSGOE	"SROE"	/* ＲＢＩファイルI/Oエラー(mmmm)			 */
						/*  FNAME = ffffffff  KEI = s				 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm      : モジュールID		 		 */
						/*   ffffffff  : ＲＢＩファイル名			 */
						/*   s		   : 種別						 */
						/*               'M'-両系 'S'-正系 'F'-副系	 */
						/*   oooooooo  : システムコール種別	 		 */
						/*   rrrrrrrr  : システムコール返却値 		 */
#define	MRMSGOF	"SROF"	/* ミラーボリューム(vvvvvvvv)状態(llllllll)	 */
						/*  正(s) 副(s)							 	 */
						/*   vvvvvvvv  : 論理ボリューム識別名		 */
						/*   llllllll  : ミラーリング制御状態		 */
						/*   s         : ボリュームステータス		 */
#define	MRMSGOG "SROG"  /* ＳＭＰシステム管理ファイルＩ／Ｏエラー	 */
						/* OSTYPE = oooooooo  OSRET = rrrrrrrr		 */
						/*									CT1212   */
						/*   oooooooo  : システムコール種別	 		 */
						/*   rrrrrrrr  : システムコール返却値 		 */
#define	MRMSGOH "SROH"  /* バッファ獲得失敗  				CT1212	 */
						/*  SCRET = rrrrrrrr		 		CT1212   */
						/*   rrrrrrrr  : サービスコール返却値		 */
#define	MRMSGOI	"SROI"	/* ＳＰＭ退避ファイル創成成功		CT1212	 */
#define	MRMSGOJ	"SROJ"	/* ＳＰＭ退避ファイル創成失敗		CT1212	 */
#define	MRMSGOK	"SROK"	/* ＳＰＭ退避ファイル創成不要		CT1212	 */
#define	MRMSGOL	"SROL"	/* ＳＰＭ退避ファイルが既に存在する	CT1212	 */

/*********************************************************************/
/*	    18.ＳＣＳＩリセットプロセス				CT1106			     */
/*********************************************************************/
#define	MRMSGP1 "SRP1"	/* バスリセット成功			ST3688			 */
						/*  FN = sssssss.....						 */
						/* sssssss....	: リセット対象バスファイル名 */
#define	MRMSGP2 "SRP2"	/* バスリセット失敗			ST3688			 */
						/*  FN = sssssss..... RC = rrrrrrrr			 */
						/* sssssss....	: リセット対象バスファイル名 */
						/* rrrrrrrr		: システムコール返却値		 */
#define	MRMSGP3 "SRP3"	/* 装置リセット成功			ST3688			 */
						/*  FN = sssssss.....						 */
						/* sssssss....	: リセット対象装置ファイル名 */
#define	MRMSGP4 "SRP4"	/* 装置リセット失敗			ST3688			 */
						/*  FN = sssssss..... RC = rrrrrrrr			 */
						/* sssssss....	: リセット対象装置ファイル名 */
						/* rrrrrrrr		: システムコール返却値		 */
#define	MRMSGP5 "SRP5"	/* 特殊ファイルＩ／Ｏエラー			ST3820	 */
						/*  FN = ffffffffffffffff....  OSTYPE = oo   */
						/*  RC = rrrrrrrr						     */
						/*   ffffffffffffffff : 特殊ファイル名	 	 */
						/*   oo               : システムコール種別	 */
						/*   rrrrrrrr         : システムコール返却値 */

/*********************************************************************/
/*      19.故障管理提供関数								SSCY0152	 */
/*********************************************************************/
#define	MRMSGQ1	"SRQ1"	/* ACC故障  DEVNO = dddddddd  	SSCY0152	 */
						/*  ELEMENT = eeeeeeee  DETAIL = ssssssss	 */ 
						/*   dddddddd : 装置ID			SSCY0152	 */
						/*   eeeeeeee : ｴﾚﾒﾝﾄNO			SSCY0152	 */
						/*   ssssssss : 故障詳細		SSCY0152	 */

/*********************************************************************/

/*********************************************************************/
/*      20.RCVメッセージ一覧	SUPPLY 2003-04-08					 */
/*********************************************************************/
#define	MRMSRR1	"SRR1"	/* システムコールエラーが発生した			 */
						/* 引継ぎ情報アクセスエラー %s errno=%s		 */
						/* USEFILE ACCESS ERROR %s errno=%s			 */
#define MRMSRR2 "SRR2"	/* システムコールエラーが発生した。			 */
						/* STATUSFILE ACCESS ERROR %s errno=%s		 */
						/* 引継ぎ状態アクセスエラー %s errno=%s		 */
#define MRMSRR3	"SRR3"	/* （引継ぎ状態ファイルから読み込んだ）		 */
						/* 引継ぎ情報ファイルの作成日付、作成時間、  */
						/* 故障状態を表示							 */
						/* TRCV JNLFILE STATAUS： %s USEFILE： 		 */
						/* yymmdd hhmmss							 */
						/* 引継ぎ情報ファイルステータス： %s 		 */
						/* 使用ファイル： yymmdd hhmmss				 */
#define MRMSRR4 "SRR4"	/* 引継ぎ情報ファイルの初期化開始			 */
						/* TRCV JNLFILE INITIALIZATION START（%s）	 */
						/* 引継ぎ情報ファイル初期化開始（%s）		 */
#define MRMSRR5 "SRR5"	/* 引継ぎ情報ファイルの初期化終了。			 */
						/* TRCV JNLFILE CREATE： yymmdd hhmmss		 */
						/* 引継ぎ情報ファイル初期化終了 作成：		 */
						/* yymmdd hhmmss							 */
#define MRMSRR6 "SRR6"	/* 引継ぎ状態ファイルの初期化開始			 */
						/* TRCV STATUSFILE INITIALIZATION START（%s）*/
						/* 引継ぎ状態ファイル初期化開始（%s）		 */
#define MRMSRR7 "SRR7"	/* 引継ぎ状態ファイルの初期化終了。			 */
						/* TRCV STATUSFILE CREATE： yymmdd hhmmss	 */
						/* STATUS： %s								 */
						/* 引継ぎ状態ファイル初期終了 作成： 		 */
						/* yymmdd hhmmss							 */
#define MRMSRR8 "SRR8"  /* テーブルリカバリ処理の開始				 */
						/* TABLE RECOVERY START						 */
						/* テーブルリカバリ回避（ファイル故障中）	 */
#define MRMSRR9 "SRR9"	/* テーブルリカバリ処理の終了。				 */
						/* TABLE RECOVERY END USEFILE： %s1%s2 		 */
						/* RECORDS： %s3							 */
						/* テーブルリカバリ終了 使用ファイル： 		 */
						/* %s1 %s2 レコード数： %s3					 */
#define MRMSRRA	"SRRA"	/* テーブルリカバリ処理の回避。				 */
						/* TABLE RECOVERY AVOID（FILE FAILURE）		 */
						/* テーブルリカバリ回避（ファイル故障中）	 */
#define MRMSRRB	"SRRB"	/* 利用者終了途中によるシステム正常終了		 */
						/* 処理の開始。								 */
						/* SYSTEM STOP START（USER END MIDDLE）		 */
						/* システム正常終了処理開始（利用者終了途中）*/
#define MRMSRRC	"SRRC"	/* 関数発行失敗 詳細情報 					 */
						/* SYSTEM STOP START（USER END MIDDLE）		 */
						/* command failed. Error code = 			 */
/*********************************************************************/



