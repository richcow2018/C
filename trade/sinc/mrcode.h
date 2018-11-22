/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ﾌｧｲﾙﾒｲ														 */
/*		ｱﾎﾞ-ﾄ/ﾀﾞｳﾝ ｺ-ﾄﾞ ﾃｲｷﾞ ﾌｧｲﾙ (mrcode.h)						 */
/*																	 */
/*	2 ｸﾌﾞﾝ															 */
/*		ﾘｶﾊﾞﾘ ｷｮｳﾂｳ													 */
/*																	 */
/*	3 ﾘﾚｷ															 */
/*		ｾｯｹｲ ｼｬ : ﾎｼﾉ ﾋﾛﾄｼ											 */
/*		ｻｸｾｲ ｼｬ : ﾔﾏﾓﾄ ﾕｳｼﾞ							 				 */
/*		ﾍﾝｺｳ ｼｬ : ｽｽﾞｷ ｵｻﾑ			'87/10/02			(L01)		 */
/*			 (ｵｲｶｹ ﾘｶﾊﾞﾘ ｶﾝﾚﾝ ｺｳﾓｸ ﾉ ｻｸｼﾞｮ)				---STC395	 */
/*		ﾍﾝｺｳｼﾔ : ﾎｼﾉ ﾋﾛﾄｼ			'87/11/28			(L02)		 */
/*			 (VRCV/BKUP ｲﾝﾀｰﾌｪｲｽ ﾆ ﾖﾙ ﾍﾝｺｳ)				---STC351	 */
/*		ﾍﾝｺｳ ｼｬ : ﾏﾂｼﾀ ｴｲｼﾞ			'87/12/24			(L03)		 */
/*			 (ｼｮｳｶﾞｲ ｱﾄ ｼｮﾘ ﾌﾟﾛｾｽ ｷﾉｳ ﾂｲｶ)				---STC559	 */
/*		ﾍﾝｺｳ ｼｬ : ｽｽﾞｷ ｵｻﾑ 			'88/05/17			(L04)		 */
/*			 (ﾎﾞﾘｭｰﾑ ﾍｲｿｸ ｼｮﾘ ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ)			---STC911	 */
/*		ﾍﾝｺｳ ｼｬ : ｳﾁﾀﾞ ﾕｳｽｹ			'88/08/10			(L05)		 */
/*			 (ﾌﾟﾛｾｽﾘｶﾊﾞﾘ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ)			    ---STC978  	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			'88/10/14 			(L06)		 */
/*			 (ｼﾞｬｰﾅﾙ ﾘｰﾄﾞ ｶｲｿﾞｳ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ)			---TC1230	 */
/*		ﾍﾝｺｳｼﾔ : ﾏﾂｼﾀ ｴｲｼﾞ			'88/11/01			(L07)		 */
/*			 (ﾄﾗﾝｻﾞｸｼｮﾝ ｶﾝﾘ ｴﾗｰｼﾞ ﾉ ｼｮﾘ ﾍﾝｺｳ)			---TC2024	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			'89/02/07 			(L08)		 */
/*			 (ﾎﾞﾘｭｰﾑ ｼｮｳｶﾞｲ ｼﾞｮｳﾀｲ ｼｭﾄｸ ｶﾝｽｳ ﾉ ﾂｲｶ)		---TC2310	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			'89/02/10 			(L09)		 */
/*			 (BKUP･VRCV･VCPY ｲｼﾞｮｳｼﾞ ｱﾎﾞｰﾄ ｷﾉｳ ﾉ ﾂｲｶ)	---TC2419	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			'89/03/08 			(L10)		 */
/*			 (ﾎﾞﾘｭｰﾑ ｼｮｳｶﾞｲ ｼﾞｮｳﾎｳ ﾂｳﾁ ｷﾉｳ ﾉ ﾂｲｶ)		---TC2368	 */
/*		ﾍﾝｺｳｼｬ : ｽｽﾞｷ ｵｻﾑ 				'89/04/15 		(L11)		 */
/*			 (SCSI ﾊﾞｽ ﾘｾｯﾄ ｼｮﾘ ﾂｲｶ ﾆ ﾄﾓﾅｳ ﾍﾝｺｳ) 		--- TC2466	 */
/*		ﾍﾝｺｳｼﾔ : ﾔﾏﾀﾞ ｶｽﾞﾉﾘ			'89/04/19			(L12)		 */
/*			 (ｷﾄﾞｳ ﾊﾟﾗﾒﾀ ﾁｪｯｸ ｷﾉｳ ﾉ ﾂｲｶ)				---TC2528	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '89/07/29 			(L13)		 */
/*				(ﾊﾞｯｸｱｯﾌﾟ ｻｲ ｷﾄﾞｳ ｷﾉｳ ﾉ ﾂｲｶ)			--- TC2701	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '89/11/02 			(L14)		 */
/*			 (ｼｮｳｶﾞｲ ﾎﾞﾘｭｰﾑ ｴﾗｰｼｭﾍﾞﾂ ﾂｳﾁ ｷﾉｳ ﾉ ﾂｲｶ)		--- TC3200	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '89/12/06 			(L15)		 */
/*			 (ﾌﾟﾛｾｽ ﾏｲｽｳ 512 ﾆﾖﾙ mr_jnl ｶｲｿﾞｳ)			--- TC3013	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '89/12/05 			(L16)		 */
/*				(RBI ｼｭﾄｸ ﾃｲｼ ｷﾉｳ ﾉ ﾂｲｶ)				--- TC3188	 */
/*		ﾍﾝｺｳｼﾔ : ｽｽﾞｷ ｵｻﾑ			 '90/04/28 			(L17)		 */
/*			 (ｺﾋﾟｰﾌﾟﾛｾｽ ﾏﾙﾁ ｷﾄﾞｳ ｷﾉｳ ﾉ ﾂｲｶ)				--- TC3550	 */
/*      変更者 : 佐藤　亘             93/11/12           TD-00       */
/*                (ﾎﾂﾄｽﾀﾝﾊﾞｲ変更に伴う変更)              TD-02       */
/*                (ｱｸｾｽ権付ﾊﾞｯﾌｧに伴う変更)              TD-10       */
/*                (ﾐﾗ-ﾘﾝｸﾞｻﾎﾟ-ﾄに伴う変更)               TD-22       */
/*                (LMﾃ-ﾌﾞﾙﾘｶﾊﾞﾘ機能導入に伴う変更)       TD-39       */
/*				  (KJの分離に伴う変更)					 TD-42		 */
/*                (ﾎﾞﾘﾕ-ﾑ故障監視に伴う変更)             TD-44       */
/*				  (ﾐﾗ-ﾎﾞﾘﾕ-ﾑVRCVに伴う変更)				 TD-45       */
/*				  (ﾊﾞｯｸｱｯﾌﾟ変更に伴う変更)				 TD-46		 */
/*                (ﾎﾞﾘﾕ-ﾑ閉塞通知削除に伴う変更)         TD-47       */
/*                (ｼｽﾃﾑﾀﾞｳﾝの見直しに伴う変更)           TD-48       */
/*                (ﾌﾟﾛｾｽｱﾎﾞ-ﾄの見直しに伴う変更)         TD-49       */
/*                (PUの独立化に伴う変更)                 TD-59       */
/*                (SCSIﾘｾﾂﾄ機能の変更に伴う変更)         TD-61       */
/*                (BACKUP中JNL取得に伴う変更)    	     TD-67       */
/*				  (SRCV失敗時復旧に伴う変更)			 TD-78       */
/*                (JNL・RBIの初期化に伴う変更)           TD-79       */
/*                (mr_vbgt拡張)							 TD-81		 */
/*                (ﾎﾞﾘﾕ-ﾑ閉塞単位変更に伴う変更)         TD-90       */
/*                (SMP日付の導入に伴う変更)              TD-92       */
/*      変更者 : 杉岡	克也		95/ 2/ 7		 	ST1550		 */
/*				  (mr_efcl復活に伴う修正)							 */
/*		変更者 : 山本  智也			95/03/15			 MO7		 */
/*				  (JNL/KJ故障時の強制面切替	仕様変更要求書 SSCY0025) */
/*				  (論理ﾎﾞﾘﾕ-ﾑ閉塞機能		仕様変更要求書 SSCY0037) */
/*				  (ﾎﾞﾘﾕ-ﾑ情報取得機能		仕様変更要求書 SSCY0038) */
/*		変更者 : 杉岡  克也			93/ 3/23			TD-22		 */
/*                (ﾐﾗｰﾘﾝｸﾞ同期機能			仕様変更要求書 SSCYXXXX) */
/*		変更者 : 今井　弘幸			95/ 3/28 --- CT0977(ST2646) 	 */
/*                (2重故障時面切替機能追加に伴う変更	SSCYXXXX)	 */
/*      変更者 : 宮脇  伸			95/ 5/23						 */
/*				  (ACC閉塞機能				仕様変更要求書 SSCY0020) */
/*      変更者 : 山本  智也			95/ 5/26						 */
/*				  (mr_crfe追加				仕様変更要求書 SSCY0038) */
/*      変更者 : 山本  智也			95/ 5/26						 */
/*				  (mr_kjwt2,mr_fcgt追加		仕様変更要求書 SSCY0042) */
/*      変更者 : 赤塚  一元			95/05/30 --- CT1039(ST2764)		 */
/*				  (SCSIﾘｾﾂﾄ機能				仕様変更要求書 SSCYXXXX) */
/*      変更者 : 今井　弘幸			95/ 6/15			ST2806       */
/*				  (VRCV例外関数のﾓｼﾞｭｰﾙID追加)						 */
/*      変更者 : 山本  智也			95/ 6/15						 */
/*				  (mr_nabt追加				仕様変更要求書 SSCY0065) */
/*		変更者 : 杉岡  克也			95/ 7/19 --- CT1096(ST2997)      */
/*             	  (VRCVのﾐﾗｰﾎﾞﾘｭｰﾑ復旧中の対処)						 */
/*		変更者 : 柴崎　智子			95/07/24 --- CT1091(ST2993)	 	 */
/*				 （ミラー復旧時問題点対処）							 */
/*		変更者 : 柴崎　智子			95/07/24 --- CT1093(ST2995) 	 */
/*				 （Ｗログの充実）									 */
/*		変更者 : 柴崎　智子			95/07/24			ST2891		 */
/*				 （状態遷移失敗時の対処）							 */
/*		変更者 : 柴崎　智子			95/07/24			ST2893		 */
/*				 （メッセージの充実）								 */
/*		変更者 : 杉岡  克也			95/ 8/14 --- ST2948				 */
/*             	  (二重故障時面切替機能に関するﾐﾗｰﾎﾞﾘｭｰﾑ対応)		 */
/*      変更者 : 赤塚  一元			95/ 8/16 --- CT1106(ST3142)   	 */
/*		変更者 : 杉岡  克也			95/09/08 --- CT1103(ST3408)		 */
/*                (mr_mdbg及びmrqﾌﾟﾛｾｽ新設に伴う変更)				 */
/*		変更者 : 杉岡  克也			95/10/10 --- ST3492				 */
/*                (ﾎｯﾄｽﾀﾝﾊﾞｲ活線挿抜機能対応処理新設)				 */
/*		変更者 : 杉岡  克也			95/10/19 --- CT1172(ST3676)		 */
/*				  (引継復旧状態ｶﾞｰﾄﾞﾌﾗｸﾞ対応処理新設)				 */
/*		変更者 : 杉岡  克也			95/10/30 --- CT1118(ST3410)		 */
/*				  (ﾒｯｾｰｼﾞの充実)				 				     */
/*		変更者 : 杉岡  克也			95/11/07 --- ST3704				 */
/*		変更者 : 杉岡  克也			95/11/16 --- CT1163(ST3808)		 */
/*				  (mro起動中のmrp起動優先)							 */
/*		変更者 : 杉岡  克也			95/11/24 --- ST3802				 */
/*				  (不正電文受信時の対処)							 */
/*		変更者 : 杉岡  克也			95/11/28 --- ST3804				 */
/*		変更者 : 杉岡  克也			95/12/25 --- TD-N7				 */
/*				  (mr_dum2追加に伴う変更)							 */
/*		変更者 : 今井  弘幸			96/02/13 --- ST3754				 */
/*		変更者 : 今井  弘幸			96/02/20 --- ST3991				 */
/*      変更者 : Com'app			96/02/21 --- ST3921,SSCY0152	 */
/*		変更者 : 山本  有司			96/02/22 --- CT1211(ST4062)		 */
/*				  (ﾎｯﾄｽﾀﾝﾊﾞｲ系切替時間短縮に伴う変更)				 */
/*		変更者 : 杉岡  克也			96/02/25 --- CT1212(ST4166)		 */
/*				  (SPM退避ﾌｧｲﾙ創成機能の追加に伴う変更)				 */
/*		変更者 : 今井  弘幸			96/02/26 --- CT1213(ST4078)		 */
/*				  (強制ｱﾝﾏｳﾝﾄ失敗時処理変更に伴うｺｰﾄﾞ追加)			 */
/*		変更者 : 今井  弘幸			96/02/28 --- ST4031	 			 */
/*				  (mrnﾀﾞｳﾝ要ﾁｪｯｸ廃止に伴う変更)			 			 */
/*      変更者 : Com'app			96/04/09 --- ST4008				 */
/*				  (装置間バスリセット機能追加)						 */
/*		変更者 : 今井  弘幸			96/04/09 --- ST4041	 			 */
/*				  (ﾐﾗｰ機能SCSIﾘｾｯﾄに伴う変更)			 			 */
/*		変更者 : 山本　智也			96/12/06 --- ST4608		 		 */
/*				  (mrcref.cのﾓｼﾞｭｰﾙid追加)			 			 	 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	終了コードの定義                                                 */
/*********************************************************************/
/*********************************/
/*	1.ｼｽﾃﾑ ﾘｶﾊﾞﾘ (SRCV)			 */
/*********************************/
#define	MREYCOM		0x2000		/* SRCV 共通					TD@1 */
#define	MREYRCV		0x2001		/* SRCV ﾒｲﾝ						TD49 */
#define	MREYDWN		0x2002		/* SRCV 用ﾀﾞｳﾝ処理				TD49 */
#define	MREYMSG		0x2003		/* SRCV ﾒｯｾｰｼﾞの出力			TD49 */
#define	MREYINF		0x2004		/* SRCV 共通情報設定			TD49 */
#define	MREYMRB		0x2005		/* SRCV RBI展開ﾒｲﾝ				TD49 */
#define	MREYROP		0x2006		/* SRCV RBIのｵｰﾌﾟﾝ				TD49 */
#define	MREYREF		0x2007		/* SRCV 最新有効RBIの検索		TD49 */
#define	MREYRBS		0x2008		/* SRCV RBIｲﾝﾃﾞｯｸｽの読み込み	TD49 */
#define	MREYRST		0x2009		/* SRCV RBIﾃﾞｰﾀの読み込み		TD49 */
#define	MREYRCL		0x200a		/* SRCV RBIのｸﾛｰｽﾞ				TD49 */
#define	MREYJOS		0x200b		/* SRCV JNLｵﾌｾｯﾄの初期化		TD49 */
#define	MREYMTU		0x200c		/* SRCV ﾃｰﾌﾞﾙ更新ﾒｲﾝ			TD49 */
#define	MREYJRP		0x200d		/* SRCV 実更新代行開始位置の検索TD49 */
#define	MREYTNX		0x200e		/* SRCV 待機面のﾃｰﾌﾞﾙ更新		TD49 */
#define	MREYJCH		0x200f		/* SRCV JNLﾌｧｲﾙの切り替え		TD49 */
#define	MREYJRS		0x2010		/* SRCV JNLﾃﾞｰﾀの検索			TD49 */
#define	MREYJEW		0x2011		/* SRCV JNLﾃﾞｰﾀ異常時処理		TD49 */
#define	MREYJDC		0x2012		/* SRCV JNLﾃﾞｰﾀのﾁｪｯｸ			TD49 */
#define	MREYTJU		0x2013		/* SRCV ﾃｰﾌﾞﾙの更新				TD49 */
#define	MREYTIN		0x2014		/* SRCV ﾎﾞﾘｭｰﾑ情報の初期化		TD49 */
#define	MREYMFU		0x2015		/* SRCV ﾌｧｲﾙ更新ﾒｲﾝ				TD49 */
#define	MREYFJU		0x2016		/* SRCV ﾌｧｲﾙの更新				TD49 */
#define	MREYFOP		0x2017		/* SRCV ﾌｧｲﾙのｵｰﾌﾟﾝ				TD49 */
#define	MREYFAC		0x2018		/* SRCV ﾌｧｲﾙｱｸｾｽﾁｪｯｸ			TD49 */
#define	MREYFER		0x2019		/* SRCV ﾌｧｲﾙ故障時処理			TD49 */
#define	MREYFCL		0x201a		/* SRCV ﾌｧｲﾙのｸﾛｰｽﾞ				TD49 */
#define	MREYMKU		0x201b		/* SRCV KJの復旧				TD49 */
#define	MREYOSR		0x201c		/* SRCV SCSIﾘｾｯﾄ付きｼｽﾃﾑｺｰﾙ		TD49 */
#define	MREYNRV		0x201d		/* 非RCVﾎﾞﾘﾕ-ﾑﾐﾗ-同期処理		TD22 */

/*********************************/
/*	2.ｻﾌﾞｼｽﾃﾑ ﾘｶﾊﾞﾘ    			 */
/*********************************/
#define MREYLCOM	0x2020		/* ｻﾌﾞｼｽﾃﾑﾘｶﾊﾞﾘ共通				TD@1 */
#define MREYLSR		0x2021		/* ｻﾌﾞｼｽﾃﾑﾘｶﾊﾞﾘﾒｲﾝ				TD39 */

/*********************************/
/*	3.ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ (PRCV)		*/
/*********************************/
#define	MREPRCVCOM	0x2040		/* ﾌﾟﾛｾｽﾘｶﾊﾞﾘ共通				TD49 */
#define	MREPEXS		0x2041		/* AP例外関数の登録処理			TD49 */
#define	MREPSET		0x2042		/* ﾌﾟﾛｾｽﾘｶﾊﾞﾘの登録処理			TD49 */
#define	MREPCAN		0x2043		/* ﾌﾟﾛｾｽﾘｶﾊﾞﾘの登録解放処理		TD49 */
#define	MREPRCX		0x2044		/* ﾌﾟﾛｾｽﾘｶﾊﾞﾘの例外受付処理		TD49 */
#define	MREPRCV		0x2045		/* ﾌﾟﾛｾｽﾘｶﾊﾞﾘの受付処理			TD49 */
#define	MREPERI		0x2046		/* 異常情報出力処理				TD49 */
#define	MREPREC		0x2047		/* 復旧処理						TD49 */
#define	MREPFIL		0x2048		/* ｼﾞｬｰﾅﾙからの復旧処理			TD49 */
#define	MREPFTJ		0x2049		/* ﾃｰﾌﾞﾙ更新処理 				TD49 */
#define	MREPFFJ		0x204a		/* ﾌｧｲﾙ更新処理					TD49 */

#define	MREPRCVBUS 	0x2050		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ﾊﾞｽ ｴﾗｰ 	 	  	(L05)*/
#define	MREPRCVADR 	0x2051		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ｱﾄﾞﾚｽ ｴﾗｰ 	  	(L05)*/
#define	MREPRCVILL 	0x2052		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ﾌﾄｳ ﾒｲﾚｲ	 	  	(L05)*/
#define	MREPRCVDVD 	0x2053		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ｾﾞﾛ ｼﾞｮｻﾞﾝ	  	(L05)*/
#define	MREPRCVTRM 	0x2055		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ﾌﾟﾛｾｽ ｼｭｳﾘｮｳ		(L05)*/
#define	MREPRCVSTK 	0x2056		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ｽﾀｯｸ ｲｼﾞｮｳ	  	(L05)*/
#define	MREPRCVILK 	0x2058		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ｶｰﾈﾙｺｰﾙ ｼﾖｳ ｱﾔﾏﾘ (L05)*/
#define	MREPRCVUSR 	0x2059		/* ﾌﾟﾛｻｽ ﾚｲｶﾞｲ ﾕｰｻﾞ ﾚｲｶﾞｲｼﾃｲ    (L05)*/ 

/*********************************/
/*	4.先行ﾘｶﾊﾞﾘ (ARCV)   		 */
/*********************************/
#define MREYACOM   0x2060       /* 先行ﾘｶﾊﾞﾘ共通				TD02 */
#define MREYARC	   0x2061       /* apmain						TD02 */
#define MREYAIN	   0x2062       /* 初期設定処理					TD02 */
#define MREYAMR	   0x2063       /* リカバリ完了主処理			TD02 */
#define MREYARI	   0x2064       /* ﾘｶﾊﾞﾘ完了初期処理			TD02 */
#define MREYAMC	   0x2065       /* CM/ﾌｧｲﾙ復旧処理				TD02 */
#define MREYAML	   0x2066       /* LM復旧処理					TD02 */
#define MREYASI	   0x2067       /* 初期化代行主処理				TD02 */
#define MREYAJC	   0x2068       /* JNLﾌｧｲﾙﾁｪｯｸ処理				TD02 */
#define MREYABC	   0x2069       /* RBIﾌｧｲﾙﾁｪｯｸ処理				TD02 */
#define MREYARB	   0x206a       /* RBI取得依頼処理				TD02 */
#define MREYABT	   0x206b       /* 先行ﾘｶﾊﾞﾘ用ﾀﾞｳﾝ関数			TD02 */
#define MREYASY	   0x206c       /* ﾒﾓﾘ無効化処理				TD02 */

/*********************************/
/*	  VRCV提供関数               */
/*********************************/
                                /* その他提供関数へ移動のため削除    */
                                /* (2行)                        TD@1 */
								/* VRCV前処理ﾌﾟﾛｾｽへの移動のため削除 */
								/* (2行)                        TD90 */
								/* 故障管理プロセス移動のため削除    */
								/* (3行)                        TD@1 */
                                /* その他提供関数へ移動のため削除    */
                                /* (1行)                        TD@1 */
								/* VRCV前処理ﾌﾟﾛｾｽへの移動のため削除 */
								/* (1行)                        TD90 */
                                /* その他提供関数へ移動のため削除    */
                                /* (1行)                        TD@1 */

/*********************************/
/*	ﾎﾘｭｳ ﾃﾞ-ﾀ ｼｭﾄｸ (RSRV)		 */
/*********************************/
                                /* 存在しない機能の削除(3行)    TD@1 */

/*********************************/
/*	5.ACC閉塞機能		SSCY0020 */
/*********************************/
#define	MREACCCOM	0x2080		/* ACC閉塞機能共通					 */
#define	MREACCF		0x2081		/* ACCﾄﾞﾗｲﾌﾞ閉塞					 */
#define	MREAGTS		0x2082		/* ACCﾄﾞﾗｲﾌﾞ状態取得				 */

#define	MREACRV		0x208a      /* ACCﾄﾞﾗｲﾌﾞ閉塞/組み込み状態RCV	 */
#define	MREACMS		0x208b      /* ACC事象通知AP通知				 */

/*********************************/
/*    装置間ﾊﾞｽﾘｾﾂﾄ機能	 ST4008	 */
/*********************************/
#define	MREPBCOM	0x20a0		/* 装置間バスリセット機能共通 ST4008 */
#define	MREPUNM		0x20a1		/* 特殊ﾌｱｲﾙ情報取得			ST4008	 */
#define	MREBRST		0x20a2		/* 装置間ﾊﾞｽﾘｾﾂﾄ処理		ST4008	 */

/*********************************/
/*	6.RBI ｼｭﾄｸ ｼｮﾘ (RBI)		 */
/*********************************/
#define	MRERBICOM	0x2100		/* RBI取得処理共通				TD@1 */
#define	MRERBI		0x2101		/* RBI取得処理					TD49 */
#define	MRERINF		0x2102		/* 共通情報設定処理				TD49 */
#define	MRERGET		0x2103		/* 取得処理						TD49 */
#define	MRERWRT		0x2104		/* 書き込み処理					TD49 */
#define	MRERINV		0x2105		/* 無効化処理					TD49 */
#define	MRERSNM		0x2106		/* 完了通知送信処理				TD49 */
#define	MREROPN		0x2107		/* ｵｰﾌﾟﾝ処理					TD49 */
#define	MRERCLS		0x2108		/* ｸﾛｰｽﾞ処理					TD49 */
#define	MREROCN		0x2109		/* ﾌｧｲﾙ連結処理					TD61 */
#define	MREROWD		0x210a		/* ﾃﾞｰﾀ書き込み処理				TD61 */
#define	MREROFL		0x210b		/* 遅延ﾃﾞｰﾀの書き込み処理		TD61 */
#define	MRERERR		0x210c		/* ﾌｧｲﾙｱｸｾｽｴﾗｰ処理				TD49 */
#define	MRERMSG		0x210d		/* RBI故障ﾒﾂｾ-ｼﾞ出力		ST3921	 */

/*********************************/
/*  7.ﾐﾗ-同期解析ﾌﾟﾛｾｽ			 */
/*********************************/
#define	MREMQCOM	0x2120		/* ﾐﾗ-同期解析共通			CT1103	 */
#define	MREMQMA		0x2121		/* ﾐﾗ-同期解析ﾒｲﾝ			CT1103	 */
#define	MREMQMP		0x2122		/* ﾒｯｾｰｼﾞ出力処理			CT1103	 */

/*********************************/
/*	8.ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ｼｮﾘ (JNL)		 */
/*********************************/
#define MREJCOM		0x2140		/* ｼﾞｬｰﾅﾙ取得処理共通			TD49 */
#define MREJJCAN	0x2141		/* ｷｬﾝｾﾙ処理					TD49 */
#define MREJJCHK	0x2142		/* ﾃﾞｰﾀﾁｪｯｸ処理					TD49 */
#define MREJJCLR	0x2143		/* ｼﾞｬｰﾅﾙﾍｯﾀﾞｸﾘｱ処理			TD49 */
#define MREJJCLS	0x2144		/* ｸﾛｰｽﾞ処理					TD49 */
#define MREJJDEQ	0x2145		/* DEQ処理						TD49 */
#define MREJJED2	0x2146		/* FJ編集処理					TD49 */
#define MREJJED3	0x2147		/* TJ編集処理					TD49 */
#define MREJJED5	0x2148		/* KJ編集処理					TD49 */
#define MREJJED8	0x2149		/* VJ編集処理					TD49 */
#define MREJJEDT	0x214a		/* 編集処理						TD49 */
#define MREJJENQ	0x214b		/* ENQ処理						TD49 */
#define MREJJERR	0x214c		/* ｴﾗｰ処理						TD49 */
#define MREJJFAC	0x214d		/* ﾌｧｲﾙｱｸｾｽ処理					TD49 */
#define MREJJFBF	0x214e		/* ﾊﾞｯﾌｧ解放処理				TD49 */
#define MREJJFOP	0x214f		/* ﾌｧｲﾙｵｰﾌﾟﾝ処理				TD49 */
#define MREJJGBF	0x2150		/* ﾊﾞｯﾌｧ獲得処理				TD49 */
#define MREJJIDX	0x2151		/* ﾚｺｰﾄﾞｲﾝﾃﾞｯｸｽ情報ｾｯﾄ処理		TD49 */
#define MREJJINT	0x2152		/* ｲﾆｼｬﾙ処理					TD49 */
#define MREJJITM	0x2153		/* 項目単位編集処理				TD49 */
#define MREJJNL		0x2154		/* 書き込み処理					TD49 */
#define MREJJOPN	0x2155		/* ｵｰﾌﾟﾝ処理					TD49 */
#define MREJJRD		0x2156		/* 読み込み処理					TD49 */
#define MREJJSMP	0x2157		/* SMPｲﾝﾃﾞｯｸｽ編集処理			TD49 */
#define MREJJSP		0x2158		/* ﾎﾟｼﾞｼｮﾆﾝｸﾞ処理				TD49 */
#define MREJJSYN	0x2159		/* 同期合わせ処理				TD49 */
#define MREJJTBL	0x215a		/* ﾃｰﾌﾞﾙ更新処理				TD49 */
#define MREJJVCC	0x215b		/* JVCﾁｪｯｸ処理					TD49 */
#define MREJJVCS	0x215c		/* JVCｾｯﾄ処理					TD49 */
#define MREJJWRT	0x215d		/* ﾊﾞｯﾌｧ書き出し処理			TD49 */
#define MREJJEND	0x215e		/* ｼﾞｬｰﾅﾙﾆｱｴﾝﾄﾞ通知処理			TD49 */
#define MREJJMCG	0x215f		/* ｼﾞｬｰﾅﾙ再ｵｰﾌﾟﾝ処理			TD49 */
#define	MREJFCGT	0x2160		/* JNL使用面番号取得処理	SSCY0042 */
#define	MREJJFRD	0x2161		/* JNLﾊﾞｯﾌｧﾘﾝｸﾞ読込み処理	CT1211	 */

#define	MREJKJWT2	0x2170		/* 待機面KJｲﾝﾃﾞﾂｸｽ待避処理  SSCY0042 */
#define MREJKJCL	0x2171		/* 勘定照合ｸﾛｰｽﾞ処理			TD49 */
#define MREJKJMN	0x2172		/* 勘定照合ﾎﾞﾘｭｰﾑﾏｳﾝﾄ処理		TD49 */
#define MREJKJOP	0x2173		/* 勘定照合ｵｰﾌﾟﾝ処理			TD49 */
#define MREJKJRD	0x2174		/* 勘定照合読み込み処理			TD49 */
#define MREJKJTR	0x2175		/* ｲﾝﾃﾞｯｸｽﾃｰﾌﾞﾙﾛｰﾄﾞ処理			TD49 */
#define MREJKJTW	0x2176		/* ｲﾝﾃﾞｯｸｽﾃｰﾌﾞﾙ退避処理			TD49 */
#define MREJKJUM	0x2177		/* 勘定照合ﾎﾞﾘｭｰﾑｱﾝﾏｳﾝﾄ処理		TD49 */
#define MREJKJWT	0x2178		/* 勘定照合ﾃﾞｰﾀ編集処理			TD49 */

/*********************************/
/*  9.ﾄﾗﾝｻﾞｸｼﾖﾝ管理              */
/*********************************/
#define MRETRN      0x2180      /* トランザクション管理共通          */
#define MRETRANART  0x2181      /* トランザクション開始処理          */
#define MRETRANEND  0x2182      /* トランザクション終了処理          */
#define MRETRANCAN  0x2183      /* トランザクション打ち切り処理      */
#define MRETRER     0x2184      /* トランザクション終了エラー処理TD49*/
#define MRETRUP     0x2185      /* 実更新及び実送出処理          TD48*/

/*********************************/
/*	10.ﾊﾞｯｸｱｯﾌﾟ ｼｮﾘ (BKUP)		 */
/*********************************/
#define MREUCOM     0x21b0      /* バックアッププロセス共通     TD49 */
#define MREUMAN     0x21b1      /* バックアップ処理メイン     	TD49 */
#define MREUWTO     0x21b2      /* メッセージ出力処理	     	TD49 */
#define MREUPRM     0x21b3      /* パラメタチェック処理	     	TD49 */
#define MREUDAT     0x21b4      /* バックアップＩＤ設定処理		TD49 */
#define MREUMCK     0x21b5      /* マルチコピーチェック処理		TD49 */
#define MREUSCK     0x21b6      /* シングルコピーチェック処理	TD49 */
#define MREUJMC     0x21b7      /* ｼﾞｬｰﾅﾙﾏﾙﾁｺﾋﾟｰ処理			TD49 */
#define MREUERV     0x21b8      /* ﾊﾞｯｸｱｯﾌﾟ続行可否判定処理		TD49 */
#define MREUJCL     0x21b9      /* ｼﾞｬｰﾅﾙﾌｧｲﾙｸﾛｰｽﾞ処理			TD49 */
#define MREUURA     0x21ba      /* 裏面ＴＶＢＴ更新処理			TD49 */
#define MREUFMQ     0x21bb      /* ＴＦＭＴ個別部占有処理		TD49 */
#define MREUPBK     0x21bc      /* 識別名指定時ﾊﾞｯｸｱｯﾌﾟ処理		TD49 */
#define MREUVSR     0x21bd      /* ＴＶＢＴリセット処理			TD49 */
#define MREUVBR     0x21be      /* ＴＶＢＴ更新内容決定処理		TD49 */
#define MREUVBT     0x21bf      /* ＴＶＢＴ更新処理				TD49 */
#define	MREUINT		0x21c0		/* ｼｮｷ ｼｮﾘ							 */
#define	MREUSRT		0x21c1		/* ｶｲｼ ｼｮﾘ 							 */
#define	MREUIND		0x21c2		/* ｶｲｼ ﾄﾞｳｷ ｼｮﾘ						 */

#define	MREUVBK		0x21c3		/* ﾎﾞﾘｭｰﾑ ﾊﾞｯｸｱｯﾌﾟ ｼｮﾘ				 */
								/* １行削除						TD46 */
#define	MREUVCP		0x21c5		/* ﾛﾝﾘ  ﾎﾞﾘｭｰﾑ ｺﾋﾟｰ ｼｮﾘ				 */

#define	MREUJBK		0x21c6		/* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ﾊﾞｯｸ ｱｯﾌﾟ ｼｮﾘ		 */
#define	MREUJCP		0x21c7		/* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ｺﾋﾟｰ ｼｮﾘ				 */

#define	MREUJIN		0x21c8		/* ｼﾞｬｰﾅﾙ ｼｮｷｶ ｼｮﾘ			 		 */
#define	MREUBKT		0x21c9		/* TBKT ｶﾘ ｺｳｼﾝ ｼｮﾘ				TD00 */

#define	MREUTRM		0x21ca		/* ｼｭｳﾘｮｳ ｼｮﾘ						 */
#define	MREUTRP		0x21cb		/* ｼｭｳﾘｮｳ ｱﾄ ｼｮﾘ					 */
#define	MREUCAN		0x21cc		/* ﾎﾞﾘｭｰﾑ ｺﾋﾟｰ ｷｬﾝｾﾙ ｼｮﾘ			 */
#define	MREUTRD		0x21cd		/* ｼｭｳﾘｮｳ ﾄﾞｳｷ ｼｮﾘ					 */

#define	MREUENQ		0x21ce		/* ｼｹﾞﾝ ｾﾝﾕｳ ｼｮﾘ					 */
#define	MREUSNM		0x21cf		/* ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｼｮﾘ					 */
#define	MREURBE		0x21d0		/* RBI定周期取得停止依頼処理	TD39 */
#define	MREUARL		0x21d1		/* ﾘｻﾞﾙﾄ ｼﾞｭｼﾝ ｼｮﾘ					 */

#define	MREUJOP		0x21d2		/* ｼﾞｬｰﾅﾙ ｵｰﾌﾟﾝ ｼｮﾘ					 */
#define	MREUJED		0x21d3		/* ｼﾞｬｰﾅﾙ ﾍﾝｼｭｳ ｼｮﾘ					 */
#define	MREUJNL		0x21d4		/* ｼﾞｬｰﾅﾙ ｼｭﾄｸ ｼｮﾘ					 */
#define	MREUJAF		0x21d5		/* ｼﾞｬｰﾅﾙ ｼｭﾄｸ ｱﾄ ｼｮﾘ				 */
								/* １行削除						TD46 */
#define	MREUTBQ		0x21d7		/* TBKT/TTST占有処理			TD49 */
#define	MREUBKR		0x21d8		/* JNLﾊﾞｯｸｱｯﾌﾟｽﾃｰﾀｽ更新処理		TD49 */
#define	MREUJNM		0x21d9		/* ﾊﾞｯｸｱｯﾌﾟﾌｧｲﾙ名書換処理		TD49 */
#define	MREUECK		0x21da		/* ﾊﾞｯｸｱｯﾌﾟ結果判定処理			TD49 */
#define	MREUTCT		0x21db		/* TTCT初期化処理				TD49 */
#define	MREUTBL		0x21dc		/* TBKT実更新処理				TD49 */
#define	MREUPBR		0x21dd		/* I/Oｴﾗｰ発生ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑ 	   	 */
								/* TVBTﾘｾｯﾄ処理 	   	 		TD49 */
#define	MREUEVM		0x21de		/* ｴﾗｰﾎﾞﾘｭｰﾑ識別名出力処理 	    TD49 */
#define MREUSBK	    0x21e6		/* ｼﾝｸﾞﾙ ｺﾋﾟｰ ﾊﾞｯｸ ｱｯﾌﾟ ｼｮﾘ	   (L17) */
/* ｱﾎﾞｰﾄｺｰﾄﾞ見直しの為削除（１８行）							TD49 */
#define MREUMBK	    0x21e7		/* ﾏﾙﾁ ｺﾋﾟｰ ﾊﾞｯｸ ｱｯﾌﾟ ｼｮﾘ	   (L17) */
#define MREUMCP	    0x21e8		/* ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ﾏﾙﾁ ｺﾋﾟｰ ｼｮﾘ	   (L17) */
#define MREUCRL	    0x21e9		/* ｺﾋﾟｰ ｼｮﾘ ﾘｻﾞﾙﾄ ｼﾞｭｼﾝ ｼｮﾘ	   (L17) */
#define MREUESN	    0x21ea		/* ｺｼｮｳ ﾊｯｾｲ ﾂｳﾁ ｿｳｼﾝ ｼｮﾘ		TD00 */
#define MREUMTC	    0x21eb		/* 電文廃棄処理 				TD46 */
#define MREURBG	    0x21ec		/* RBI直接取得依頼処理			TD46 */
#define MREURBS	    0x21ed		/* RBI定周期取得開始依頼処理	TD46 */
#define	MREUOLN		0x21ee		/* ファイルリンク処理			TD61 */

/*********************************/
/*	11.ﾌﾟﾛｾｽ ｼｮｷｶ ｼｭｳﾘｮｳ (PRC)   */
/*********************************/
#define	MREPRC		0x2200		/* ﾌﾟﾛｾｽ ｼｮｷｶ ｼｭｳﾘｮｳ ｼｮﾘ ｷｮｳﾂｳ		 */
#define	MREPRCINT	0x2201		/* ﾌﾟﾛｾｽ ｼｮｷｶ ｼｮﾘ					 */
#define	MREPRCTRM	0x2202		/* ﾌﾟﾛｾｽ ｼｭｳﾘｮｳ ｼｮﾘ					 */
#define MREPTBL		0x2203		/* ﾃｰﾌﾞﾙ検索処理				TD49 */
#define	MREPINT2	0x2204      /* ﾌﾟﾛｾｽ初期化処理				TD22 */

/*********************************/
/*	12.ｼｽﾃﾑ ｼｮｷｶ ｼｭｳﾘｮｳ (SYS)    */
/*********************************/
#define	MRESYS		0x2240		/* ｼｽﾃﾑ ｼｮｷｶ ｼｭｳﾘｮｳ ｼｮﾘ ｷｮｳﾂｳ		 */
#define	MRESYSINT	0x2241		/* ｼｽﾃﾑ ｼｮｷｶ ｼｮﾘ					 */
#define	MRESYSTRM	0x2242		/* ｼｽﾃﾑ ｼｭｳﾘｮｳ ｼｮﾘ					 */
#define	MRESYSINF	0x2243		/* 共通情報設定処理				TD49 */
#define	MRESYSFSR	0x2244		/* ﾌｧｲﾙ名検索処理				TD49 */
#define	MRESYSJFS	0x2245		/* ｼﾞｬｰﾅﾙﾌｧｲﾙ検索処理			TD49 */
#define	MRESYSJNC	0x2246		/* ｼﾞｬｰﾅﾙﾌｧｲﾙﾁｪｯｸ処理			TD49 */
#define	MRESYSJNL	0x2247		/* ｼﾞｬｰﾅﾙﾚｺｰﾄﾞ取得処理			TD49 */
#define	MRESYSJUD	0x2248		/* ｼﾞｬｰﾅﾙ切り替え処理			TD49 */
#define	MRESYSMNT	0x2249		/* ﾊﾞｯｸｱｯﾌﾟｼﾞｬｰﾅﾙﾎﾞﾘｭｰﾑのﾏｳﾝﾄ処理	 */
								/*								TD49 */
#define	MRESYSOMC	0x224a		/* ｵｰﾌﾟﾝﾓｰﾄﾞ変換処理			TD49 */
#define	MRESYSRBA	0x224b		/* RBIﾃﾞｰﾀ取得依頼処理			TD49 */
#define	MRESYSRBC	0x224c		/* RBIﾌｧｲﾙﾁｪｯｸ処理				TD49 */
#define	MRESYSRFS	0x224d		/* RBIﾌｧｲﾙ検索処理				TD49 */
#define	MRESYSUMT	0x224e		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑのｱﾝﾏｳﾝﾄ処理	TD49 */

/*********************************/
/*  13.異常受付処理         TD00 */
/*********************************/
#define MRESABT		0x2261		/* 異常終了受付処理				TD49 */
#define MRESDWN		0x2262		/* ｼｽﾃﾑﾀﾞｳﾝ要求受付処理			TD49 */
#define MRENABT		0x2263		/* ｱﾎﾞｰﾄ未取得異常終了受付処理		 */
								/* SSCY0065							 */

/*********************************/
/*  14.ＶＲＣＶ前処理       TD00 */
/*********************************/
#define	MREHCOM		0x2270		/* VRCV前処理ﾌﾟﾛｾｽ共通          TD@1 */
#define	MREHMAN		0x2271		/* VRCV前処理ﾌﾟﾛｾｽﾒｲﾝ           TD90 */
#define MREHWTO		0x2272		/* ﾒﾂｾ-ｼﾞ出力処理				TD90 */
#define MREHINT		0x2273		/* 初期処理						TD90 */
#define	MREHPRM		0x2274		/* ﾊﾟﾗﾒﾀﾁｴﾂｸ処理				TD90 */
#define MREHPVL		0x2275		/* 指定物理ﾎﾞﾘﾕ-ﾑ閉塞処理		TD90 */
#define	MREHVMH		0x2276		/* 論理ﾎﾞﾘﾕ-ﾑ閉塞処理			TD90 */
#define	MREHFVH		0x2277		/* 一般ﾎﾞﾘﾕ-ﾑ閉塞処理			TD90 */
#define	MREHRUM		0x2278		/* ﾘﾓ-ﾄｱﾝﾏｳﾝﾄ処理				TD02 */
#define	MREHUMT		0x2279		/* 強制ｱﾝﾏｳﾝﾄ処理				TD90 */
#define	MREHRVH		0x227a		/* RCVﾎﾞﾘﾕ-ﾑ閉塞処理			TD78 */
#define	MREHMVH		0x227b		/* ﾐﾗ-化ﾎﾞﾘﾕ-ﾑ片系閉塞処理      TD45 */
#define	MREHPVH		0x227f		/* 物理ﾎﾞﾘﾕ-ﾑ閉塞処理			TD90 */
#define	MREHPMS		0x2282		/* 予備系物理ﾎﾞﾘｭｰﾑ閉塞処理     TD90 */
#define	MREHTRM		0x2283		/* 終了処理						TD90 */
#define	MREHJER		0x2284		/* JNLﾌｱｲﾙ閉塞処理              TD78 */
#define	MREHRER		0x2285		/* RBIﾌｱｲﾙ閉塞処理              TD78 */
#define MREHABT		0x2286      /* VRCV前処理ｱﾎﾞ-ﾄ時処理        TD90 */

/*********************************/
/*  15.ﾐﾗ-ﾘﾝｸﾞ制御同期関数  TD00 */
/*********************************/
#define	MREMIRR		0x22a0		/* ﾐﾗ-ﾘﾝｸﾞ制御同期機能共通		TD22 */
#define	MREMINT		0x22a1		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ初期処理			TD22 */
#define	MREMTRM		0x22a2		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ終了処理			TD22 */
#define	MREMMNT		0x22a3		/* 両肺ﾏｳﾝﾄ前処理				TD22 */
#define	MREMJRS		0x22a4		/* JNL&RBI同期処理				TD22 */
#define	MREMTBL		0x22a5		/* ﾃ-ﾌﾞﾙとの同期処理			TD22 */
#define	MREMSSV		0x22a6		/* SPMｾ-ﾌﾞ処理					TD22 */
#define	MREMSLD		0x22a7		/* SPMﾛ-ﾄﾞ処理					TD22 */
#define	MREMSLD2	0x22a8		/* SPMﾛ-ﾄﾞ処理２				TD22 */
#define	MREMNRS		0x22a9		/* RCV不要時同期処理			TD22 */
#define	MREMRVS		0x22aa		/* RCVﾎﾞﾘﾕ-ﾑ同期処理			TD22 */
#define	MREMSPM		0x22ab		/* 更新領域ﾛｸﾞ取得設定処理		TD22 */
#define	MREMRCV		0x22ac		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ部分復旧処理		TD22 */
#define	MREMJRS2	0x22ad		/* JNL&RBI同期処理２			TD22 */
#define	MREMNSP		0x22ae		/* 復旧不可能通知送信処理		TD22 */
#define	MREMDBG		0x22af		/* ﾐﾗ-同期解析処理			CT1103	 */
#define	MREMSCO		0x22b0		/* ﾐﾗ-特殊ﾌｱｲﾙｺﾈｸﾄｵ-ﾌﾟﾝ処理     TD22 */
#define	MREMSCD		0x22b1		/* ﾐﾗ-特殊ﾌｱｲﾙｺｸﾛ-ｽﾞﾃﾞｲｽｺﾈｸﾄ処理TD22 */
#define	MREMINF		0x22b2		/* ﾐﾗ-ﾘﾝｸﾞ制御状態取得処理      TD22 */
#define	MREMVCK		0x22b3		/* ﾎﾞﾘﾕ-ﾑｽﾃ-ﾀｽﾁｴﾂｸ処理			TD22 */
#define	MREMCHG		0x22b4		/* ﾐﾗ-状態遷移処理				TD22 */
#define	MREMVSU		0x22b5		/* ﾎﾞﾘﾕ-ﾑｽﾃ-ﾀｽ更新処理			TD22 */
#define	MREMRSU		0x22b6		/* RCVｽﾃ-ﾀｽ更新処理				TD22 */
#define	MREMRSN		0x22b7      /* RBI遷移処理(正常時)			TD22 */
#define	MREMJSN		0x22b8      /* JNL遷移処理(正常時)			TD22 */
#define	MREMMMT     0x22b9      /* ﾐﾗ-ﾎﾞﾘﾕ-ﾑﾏｳﾝﾄ処理			TD22 */
#define	MREMMUT     0x22ba      /* ﾐﾗ-ﾎﾞﾘﾕ-ﾑｱﾝﾏｳﾝﾄ処理			TD22 */
#define	MEEMSMT		0x22bb		/* ｼﾝｸﾞﾙﾎﾞﾘﾕ-ﾑﾏｳﾝﾄ処理			TD22 */
#define	MEEMSUT		0x22bc		/* ｼﾝｸﾞﾙﾎﾞﾘﾕ-ﾑｱﾝﾏｳﾝﾄ処理		TD22 */
#define	MREMRSE		0x22bd		/* RBI遷移処理(異常時)			TD22 */
#define	MREMJSE		0x22be		/* JNL遷移処理(異常時)			TD22 */
#define	MREMYRD		0x22bf		/* 有効RBI決定処理				TD22 */
#define	MREMMUF     0x22c0      /* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ強制ｱﾝﾏｳﾝﾄ処理		TD22 */
#define	MREMYJD		0x22c1		/* 有効JNL決定処理				TD22 */
#define	MREMOPN		0x22c2		/* ﾐﾗ-特殊ﾌｱｲﾙｵ-ﾌﾟﾝ処理			TD22 */
#define	MREMCLS		0x22c3		/* ﾐﾗ-特殊ﾌｱｲﾙｸﾛ-ｽﾞ処理			TD22 */
#define	MREMSHT		0x22c4		/* SPM情報変更/登録処理			TD22 */
#define	MREMNOT		0x22c5		/* 肺状態付替処理				TD22 */
#define	MREMJOP		0x22c6		/* JNLｼﾝｸﾞﾙOPEN処理				TD22 */
#define	MREMJRD		0x22c7		/* JNLｼﾝｸﾞﾙREAD処理				TD22 */
#define	MREMJCL		0x22c8		/* JNLｼﾝｸﾞﾙCLOSE処理			TD22 */
#define	MREMJCP		0x22c9		/* JNL復旧ｺﾋﾟ-処理				TD22 */
#define	MREMCON		0x22ca		/* ﾐﾗ-特殊ﾌｱｲﾙｺﾈｸﾄ処理     		TD22 */
#define	MREMDCN		0x22cb		/* ﾐﾗ-特殊ﾌｱｲﾙﾃﾞｲｽｺﾈｸﾄ処理		TD22 */
#define MREMRSY		0x22cc		/* RBI同期処理					TD22 */
#define MREMFRB		0x22cd		/* ﾊﾞﾂﾌｱ解放処理				TD22 */
#define MREMJFB		0x22ce		/* JNL読込みﾊﾞﾂﾌｱ解放処理		TD22 */
#define MREMJSY		0x22cf		/* JNL同期処理					TD22 */
#define	MREMJKO		0x22d0		/* JNL媒体別OPEN処理			TD22 */
#define	MREMJWT		0x22d1		/* JNL媒体別WRITE処理			TD22 */
#define	MREMJKC		0x22d2		/* JNL媒体別CLOSE処理			TD22 */
#define	MREMWTO		0x22d3		/* メッセージ表示				TD22 */
#define	MREMGLG		0x22d4		/* 更新領域ログ取得処理			TD22 */
#define	MREMSLG		0x22d5		/* 更新領域ログ設定処理			TD22 */
#define	MREMTAP		0x22d6		/* 特定ＡＰ電文送信処理			TD22 */
#define	MREMROP		0x22d7		/* RBIｼﾝｸﾞﾙｵ-ﾌﾟﾝ処理			TD22 */
#define	MREMREF		0x22d8		/* RBI有効面検出処理			TD22 */
#define	MREMRTS		0x22d9		/* 最新RBI待避処理				TD22 */
#define	MREMFCP		0x22da		/* 復旧コピー処理				TD22 */
#define	MREMRCL		0x22db		/* RBIｼﾝｸﾞﾙｸﾛ-ｽﾞ処理			TD22 */
#define	MREMSNR		0x22dc		/* RCVﾎﾞﾘｭｰﾑﾁｪｯｸ処理			TD22 */
#define	MREMVOF		0x22dd		/* ﾎﾞﾘｭｰﾑｽﾃｰﾀｽ未故障更新処理	TD22 */
#define	MREMYRD2	0x22de		/* 有効RBI決定処理2				TD22 */
#define	MREMFSI		0x22df		/* 再ｲﾆｼｴｰﾄﾏｳﾝﾄ処理			ST3492	 */
#define	MREMHFI		0x22f0		/* 引継復旧ｶﾞｰﾄﾞﾌﾗｸﾞ対応処理CT1172	 */
#define	MREMWTO2	0x22f1		/* ﾒｯｾｰｼﾞ表示処理2			CT1118	 */
#define	MREMCON2	0x22f2		/* ﾐﾗ-特殊ﾌｱｲﾙｺﾈｸﾄ処理2 	ST3704	 */
#define	MREMCSF		0x22f3		/* SPM退避ﾌｱｲﾙ創成処理 		CT1212	 */
#define	MREMWTO3	0x22f4		/* ﾒﾂｾ-ｼﾞ出力処理2			CT1212	 */
#define	MREMVMT		0x22f5		/* VMT検索処理				CT1212	 */
#define	MREMOCR		0x22f6		/* ﾌｱｲﾙ生成共通処理			CT1212	 */
#define	MREMOWT		0x22f7		/* oswrite共通処理			CT1212	 */
#define	MREMOCL		0x22f8		/* ﾌｱｲﾙｸﾛ-ｽﾞ共通処理		CT1212	 */
#define	MREMODC		0x22f9		/* 連結解除共通処理			CT1212	 */
#define	MREMODE		0x22fa		/* ﾌｧｲﾙ削除共通処理			CT1212	 */
#define	MREMOUF		0x22fb		/* ﾌｧｲﾙ･ｼｽﾃﾑ強制ｱﾝﾏｳﾝﾄ処理	ST4041	 */
#define	MREMORE		0x22fc		/* ﾃﾞｰﾀの読込み処理			ST4041	 */
#define	MREMVMT2	0x22fd		/* VMT検索処理2				ST4041	 */

/*********************************/
/*	16.故障管理提供関数     TD00 */
/*********************************/
#define MREECCOM    0x2300      /* 故障管理提供共通             TD@1 */
                             	/* その他提供関数に移動(1行)    TD@1 */
#define	MREEJRQ		0x2303		/* ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ｲﾗｲ ｼｮﾘ				 */
#define	MREESRQ		0x2304		/* 故障管理依頼　　　　　　　　 TD00 */
                        		/* RCV内共通関数に移動(1行)     TD@1 */
								/* 不要な処理の削除(2行)        TD47 */
#define MREEARQ     0x2305      /* JNL・RBI初期化依頼           TD79 */
#define	MREEFCL		0x2306		/* 故障ﾎﾞﾘﾕ-ﾑ閉塞処理		  ST1550 */
#define	MREEVRQ		0x2307		/* 論理ﾎﾞﾘﾕ-ﾑ閉塞処理			MO7  */
#define	MREJRER		0x2308		/* JNL/KJ閉塞処理				MO7  */
#define	MRERRER		0x2309		/* RBI閉塞処理					MO7  */
#define	MREEACC		0x230a		/* ACC故障通知処理			SSCY0152 */

/*********************************/
/*  17.ＲＣＶ内共通関数     TD00 */
/*********************************/
#define MRECCCOM    0X2310      /* RCV内共通関数共通            TD@1 */
#define MRECGBF     0x2311      /* プールバッファ確保処理       TD@1 */
#define MRECMIA		0x2312		/* ＭＩＡ初期化					TD@1 */
#define MRECPCT		0x2313		/* TPCT個別部アドレス検索		TD@1 */
#define MRECTBA		0x2314		/* テーブルアドレス検索			TD@1 */
#define MRECPCT2    0x2315      /* TPCT個別部アドレス検索       TD49 */

/*********************************/
/*  18.その他の提供関数     TD00 */
/*********************************/
#define MREACCOM    0x2320      /* その他の提供関数共通         TD@1 */
#define MRECPCA     0x2321      /* PCAｽﾃ-ﾀｽ操作処理             TD@1 */
#define MREVPEJ     0x2322      /* 故障情報仮更新処理		    TD@1 */
#define MREVPER     0x2323      /* 故障情報実更新処理			TD@1 */
#define MREVMGT	    0x2324      /* 元帳ﾎﾞﾘｭｰﾑ故障状態の取得		TD@1 */
#define MREVBGT     0x2325      /* ﾊﾞｯｸｱｯﾌﾟ未完了情報取得処理	TD@1 */
#define MRECERR     0x2326      /* JNL･RBI２重故障時処理		TD79 */
#define MRECSRR     0x2327      /* ｼｽﾃﾑｺ-ﾙｴﾗ-時処理	     TD61 CT1039 */
#define MRECDAT     0x2328      /* SMP日付取得処理				TD92 */
#define MRECRBI     0x2329      /* RBI定周期取得開始処理        TD79 */
#define MRECJKS     0x232a      /* JNLｽﾃ-ﾀｽ回復処理             TD79 */
#define	MREERRQ		0x232b		/* JNL/KJ強制故障処理			MO7  */
#define	MREVINF		0x232c		/* ﾎﾞﾘﾕ-ﾑ情報取得処理			MO7  */
#define	MRECRFE		0x232d		/* RCVﾌｱｲﾙ故障原因設定処理	SSCY0038 */
#define	MREDUM2		0x232e		/* SCSIﾊﾞｽﾘｾｯﾄ処理				TDN7 */

#define	MRECSSMP	0x2330		/* 疑似SMP通知送信処理	 TD61 CT1039 */
#define	MRECSSM2	0x2331		/* 疑似SMP通知3送信処理	 TD61 CT1106 */
								/* 削除(3行)				  CT1039 */

#define	MREVBGT2	0x2334		/* ﾊﾞﾂｸｱﾂﾌﾟ失敗論理ﾎﾞﾘﾕ-ﾑ算出処理	 */
								/* (信金版)						TD81 */
#define	MREVBGT3	0x2335		/* ﾊﾞﾂｸｱﾂﾌﾟ失敗論理ﾎﾞﾘﾕ-ﾑ算出処理	 */
								/* (通常版)						TD81 */
#define	MREVBGT4	0x2336		/* ﾊﾞﾂｸｱﾂﾌﾟ故障情報設定(信金版) TD81 */
#define	MREVBGT5	0x2337		/* ﾊﾞﾂｸｱﾂﾌﾟ故障情報設定(通常版) TD81 */
#define	MREVBGT6    0x2338      /* 論理ﾎﾞﾘﾕ-ﾑﾊﾞﾂｸｱﾂﾌﾟ状況判定	TD81 */
#define	MREVBGT7	0x2339		/* JNLﾊﾞﾂｸｱﾂﾌﾟ状況判定処理		TD81 */
#define	MREVBGT8	0x233a		/* KJﾊﾞﾂｸｱﾂﾌﾟ状況判定処理		TD81 */
#define	MREDOCN		0x233b		/* 特殊ﾌｧｲﾙｺﾈｸﾄ処理				TDN7 */
#define	MREDOPN		0x233c		/* 特殊ﾌｧｲﾙｵｰﾌﾟﾝ処理			TDN7 */
#define	MREDCLS		0x233d		/* 特殊ﾌｧｲﾙｸﾛｰｽﾞ処理			TDN7 */
#define	MREDODN		0x233e		/* 特殊ﾌｧｲﾙﾃﾞｨｽｺﾈｸﾄ処理			TDN7 */
#define	MREDOSI		0x233f		/* ﾘｾｯﾄ処理						TDN7 */
#define	MREDWTO		0x2340		/* ﾒｯｾｰｼﾞ出力処理				TDN7 */
#define	MRECINS		0x2341		/* 装置組込処理				  ST3754 */
#define	MRECWTO		0x2342		/* ﾒｯｾｰｼﾞ出力処理			  ST3754 */

/*********************************/
/*	19.故障管理ﾌﾟﾛｾｽ(ERRP)  TD00 */
/*********************************/
#define MREECOM     0x2370      /* 故障管理ﾌﾟﾛｾｽ共通            TD@1 */
#define MREERRP     0x2371      /* 故障管理ﾌﾟﾛｾｽﾒｲﾝ　           TD@1 */
#define MREEUMT		0x2372		/* 強制ｱﾝﾏｳﾝﾄ処理			    TD61 */
#define MREEMNT     0x2373      /* ﾏｳﾝﾄ処理						TD79 */
#define MREEVMS     0x2374      /* VRCV契機ﾒﾂｾ-ｼﾞ出力           TD@1 */
#define MREEVEJ     0x2375      /* VJ関連仮更新処理             TD@1 */
#define MREEMIR		0x2376		/* VRCV中ﾐﾗｰﾎﾞﾘｭｰﾑ処理	TD22  CT1096 */
#define MREEUMR     0x2377      /* ﾎﾞﾘﾕ-ﾑｽﾃ-ﾀｽ実更新２          TD47 */
#define MREEBLR     0x2378      /* 閉塞ｽﾃ-ﾀｽ実更新処理          TD00 */
#define MREEVER     0x2379      /* VJ関連実更新処理             TD00 */

#define MREEMVS     0x237b      /* 対象ﾎﾞﾘﾕ-ﾑ特定処理           TD44 */

#define MREEMER     0x237d      /* ﾎﾞﾘﾕ-ﾑｽﾃ-ﾀｽ実更新処理        TD44 */


#define	MRECLOG		0x2380		/* Cﾛｸﾞ共通						TD50 */
#define	MREEINT		0x2381		/* ｼｮｷｶ ｼｮﾘ					   (L04) */
#define	MREEEVT		0x2382		/* ｲﾍﾞﾝﾄ ﾂｳﾁ ｼｮﾘ					 */
#define	MREEBAT		0x2383		/* ﾊﾞｯﾃﾘｰ ｱﾗｰﾑ ｼｮﾘ			   (L03) */
#define	MREESRT		0x2384		/* ｶｲｼ ｼｮﾘ 					   (L04) */
#define	MREESMS		0x2385		/* ｶｲｼ ﾂｳﾁ ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｼｮﾘ	   (L04) */
#define	MREEOSN		0x2386		/* ﾀｹｲ ｼｮｳｶﾞｲ ｱﾄｼｮﾘ ﾌﾟﾛｾｽ ｿｳｼﾝ (L04) */
#define	MREERMS		0x2387		/* ﾒｯｾ-ｼﾞ ｼﾞｭｼﾝ ﾖｳｷｭｳ ｼｮﾘ 	   (L04) */
#define	MREERFM		0x2388		/* ﾘｶﾊﾞﾘ ﾌｧｲﾙ ｼｮｳｶﾞｲﾁｭｳ ﾒｯｾ-ｼﾞ (L04) */
#define	MREEVBF		0x2389		/* ｼﾞｹｲ ﾎﾞﾘｭ-ﾑ ﾍｲｿｸ ｶﾝﾘｮｳ ｼｮﾘ  (L04) */
#define	MREEBLJ		0x238a		/* ﾍｲｿｸ ｶﾝﾘｮｳ ﾌﾗｸﾞ ｶﾘｺｳｼﾝ ｼｮﾘ  (L04) */
#define	MREESMF		0x238b		/* ｼﾞｹｲ ﾍｲｿｸ ｶﾝﾘｮｳ ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ (L04) */
#define	MREESMB		0x238c		/* ﾀｹｲ ﾍｲｿｸ ｲﾗｲ ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｼｮﾘ(L04) */
								/* 強制ｱﾝﾏｳﾝﾄ機能採用に伴う削除      */
								/* (2行)                        TD47 */
#define MREEVML     0x238d      /* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ片系故障時処理      TD22 */
#define MREEMEJ     0x238e      /* ﾎﾞﾘﾕ-ﾑｽﾃ-ﾀｽ仮更新処理        TD44 */
#define	MREEARL		0x238f		/* ﾘｻﾞﾙﾄ ｼﾞｭｼﾝ ｼｮﾘ			   (L04) */
								/* 強制ｱﾝﾏｳﾝﾄ機能採用に伴う削除      */
								/* (2行)                        TD47 */
#define	MREEESR		0x2390		/* 不正電文受信時処理		ST3802	 */
#define MREEJRC     0x2391      /* JNL・RBI切替依頼電文受信時の処理  */
								/*                              TD79 */
#define	MREEOBR		0x2392		/* ﾀｹｲ ﾍｲｿｸ ｲﾗｲ ﾃﾞﾝﾌﾞﾝ ｳｹﾂｹ ｼｮﾘ(L04) */
#define	MREEOBF		0x2393		/* ﾀｹｲ ﾍｲｿｸ ｶﾝﾘｮｳ ｳｹﾂｹ ｼｮﾘ	   (L04) */
#define	MREETRM		0x2394		/* ﾌﾟﾛｾｽ ｼｭｳﾘｮｳ ｼｮﾘ 		   (L04) */
								/* SCSIﾘｾﾂﾄ機能変更に伴う削除(2行)   */
								/*                              TD61 */
#define MREESMC     0x2395      /* JNL・RBI切替完了電文送信     TD79 */
#define MREERBE		0x2396		/* RBIﾌｱｲﾙ故障処理              TD79 */
#define	MREEJNL		0x2397		/* ｼﾞｬｰﾅﾙ ｼｭﾄｸ ｲﾗｲ ﾃﾞﾝﾌﾞﾝ ｳｹﾂｹ (L11) */


#define MREEPVC     0x239a      /* 論理ﾎﾞﾘﾕ-ﾑ状態ﾁｴﾂｸ           TD90 */
#define MREEVBL     0x239b      /* 論理ﾎﾞﾘﾕ-ﾑ閉塞処理           TD90 */
#define MREEFJL     0x239c      /* ｼﾞﾔ-ﾅﾙ取得処理               TD00 */
#define MREEROS     0x239d      /* TRADE故障通知処理            TD00 */
#define MREEPVS     0x239e      /* VMT個別部検索処理            TD90 */
#define MREEOST     0x239f      /* 他系開始通知電文受信時処理   TD00 */
                                /* 未使用の処理削除(1行)        TD00 */
#define MREEMRI     0x23a0      /* ﾌﾟﾛｾｽ終了通知電文受信時処理  TD79 */
#define	MREESMD		0x23a1		/* ｴﾗｰ ｼｭﾍﾞﾂ ﾂｳﾁ ｼｮﾘ  		   (L14) */
#define MREERVH		0x23a2		/* RCVﾌｱｲﾙ閉塞処理			  CT0618 */
#define MREEJER		0x23a3		/* JNLﾌｱｲﾙ閉塞処理			  CT0619 */
#define	MREERER		0x23a4		/* RBIﾌｱｲﾙ閉塞処理			  CT0620 */
#define	MREESMP		0x23a5		/* 閉塞電文送信処理			  ST1550 */
#define	MREEJCN		0x23a6		/* JNL使用面切替処理		  CT0977 */
#define	MREEIJN		0x23a7		/* JNL初期化処理		  	  CT0977 */
#define	MREECON		0x23aa		/* ﾌｧｲﾙの連結	  			  CT0977 */
#define	MREEWRI		0x23ab		/* ﾃﾞｰﾀの直接書き込み		  CT0977 */
#define	MREEFLU		0x23ac		/* 遅延ﾃﾞｰﾀの制御書き込み	  CT0977 */
#define MREEMVH		0x23ad		/* 強制片肺遷移処理			  ST2948 */

/*********************************/
/*	20.RCV ﾌｧｲﾙ ｿｳｾｲ･ｶｲﾌｸ ｼｮﾘ	 */
/*********************************/
#define	MREFCOM		0x23c0		/* RCVﾌｧｲﾙ創成共通			    TD49 */
#define	MREFMAN		0x23c1		/* RCVﾌｧｲﾙ創成ﾒｲﾝ			    TD49 */
#define	MREFCHK		0x23c2		/* 開始ﾁｪｯｸ処理				    TD49 */
#define	MREFPRM		0x23c3		/* ﾊﾟﾗﾒｰﾀﾁｪｯｸ処理			    TD49 */
#define	MREFRBC		0x23c4		/* RBIﾌｧｲﾙ関連情報ﾁｪｯｸ処理		TD49 */
#define MREFRFS		0x23c5		/* TFMT個別部存在ﾁｪｯｸ処理		TD49 */
#define	MREFVCK		0x23c6		/* ﾎﾞﾘｭｰﾑﾁｪｯｸ処理				TD49 */
#define	MREFJNC		0x23c7		/* JNLﾌｧｲﾙ関連情報ﾁｪｯｸ処理		TD49 */
#define	MREFRBG		0x23c8		/* RBI取得依頼処理				TD79 */
#define	MREFCRB		0x23c9		/* RBIﾌｧｲﾙ創成処理				TD39 */
#define	MREFMKF		0x23ca		/* ﾌｧｲﾙ創成処理					TD49 */
#define	MREFIRB		0x23cb		/* RBIﾌｧｲﾙ初期化処理			TD49 */
#define	MREFRBT		0x23cc		/* RBT ｼｮｷｶ ｼｮﾘ     		    TD@1 */
#define	MREFCJN		0x23cd		/* JNLﾌｧｲﾙ創成処理				TD42 */
#define	MREFIJN		0x23ce		/* JNLﾌｧｲﾙ初期化処理			TD49 */
#define	MREFEDJ		0x23cf		/* JNLﾌｧｲﾙ編集処理				TD@1 */
#define	MREFRCT		0x23d0		/* RCT ｼｮｷｶ ｼｮﾘ     		    TD@1 */
#define	MREFMKD		0x23d1		/* ﾃﾞｨﾚｸﾄﾘﾌｧｲﾙ作成処理			TD49 */
#define	MREFMKN		0x23d2		/* ﾃﾞｨﾚｸﾄﾘ作成					TD61 */
#define	MREFCRE		0x23d3		/* ﾌｧｲﾙ作成						TD61 */
#define	MREFFLU		0x23d4		/* ﾌｧｲﾙの強制書き込み			TD61 */
#define	MREFCON		0x23d5		/* ﾌｧｲﾙの連結					TD61 */
#define	MREFWRI		0x23d6		/* ﾌｧｲﾙの直接書き込み			TD61 */
#define MREFWTO		0x23d7		/* ﾒｯｾｰｼﾞ出力処理				TD49 */

/*********************************/
/*	21.ﾎﾞﾘｭ-ﾑ ﾘｶﾊﾞﾘ (VRCV)		 */
/*********************************/
#define	MREWCOM		0x23f0		/* VRCV共通						TD@1 */
#define	MREWMAN		0x23f1		/* ﾎﾞﾘｭｰﾑ ﾘｶﾊﾞﾘ ﾒｲﾝ ｼｮﾘ		   (L09) */
#define	MREWRSM		0x23f2		/* ﾘｽﾄｱﾒｲﾝ処理					TD49 */
#define	MREWRST		0x23f3		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑﾁｪｯｸ処理		TD49 */
#define	MREWSFV		0x23f5		/* MRWFEB決定処理				TD49 */
#define	MREWVFF		0x23f6		/* MRWVEB･MRWFEB解放処理		TD49 */
#define	MREWVPG		0x23f7		/* MRWVEB･MRWFEB獲得処理		TD49 */
#define	MREWVFT		0x23f8		/* 一般ﾌｧｲﾙﾎﾞﾘｭｰﾑ初期化処理		TD49 */
#define	MREWWTO		0x23f9		/* メッセージ出力処理			TD49 */
#define	MREWVJC		0x23fa		/* VJ検出時処理					TD49 */
#define	MREWRON		0x2400		/* 復旧終了ﾋﾞｯﾄｵﾝ処理			TD49 */
#define	MREWSRT		0x2401		/* ﾌﾟﾛｾｽ ｶｲｼ ｼｮﾘ 					 */
#define	MREWTBL		0x2402		/* ﾃｰﾌﾞﾙ ｱﾄﾞﾚｽ ｼｹﾞﾝﾊﾞﾝｺﾞｳ ｶｸﾄｸ ｼｮﾘ	 */
								/*								TD@1 */
#define	MREWABS		0x2403		/* 直後のﾊﾞｯｸｱｯﾌﾟBKT検索処理	TD49 */
#define	MREWVRF		0x2404		/* ｲｯﾊﾟﾝﾖｳ ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ﾌｫｰﾏｯﾄ ｼｮﾘ	 */
#define	MREWVWF		0x2405		/* ﾜｰｸﾖｳ ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ﾌｫｰﾏｯﾄ ｼｮﾘ		 */
#define	MREWJRM		0x2406		/* 'FJ' ﾌｯｷｭｳ ｼｮﾘ					 */
#define	MREWPEF		0x2407		/* ﾌﾞﾂﾘ ﾎﾞﾘｭｳﾑ ﾅｲ EOF ﾄﾞｳｷ ｼｮﾘ		 */
#define	MREWVRE		0x2408		/* ﾌﾞﾂﾘ ﾎﾞﾘｭｰﾑ ｺﾋﾟｰ ｼｮﾘ				 */
#define	MREWCCN		0x2409		/* ｷﾄﾞｳ ｺﾏﾝﾄﾞ ｷｬﾝｾﾙ ｼｮﾘ				 */
#define	MREWTRP		0x240b		/* ｼｭｳﾘｮｳ ｱﾄ ｼｮﾘ					 */
#define	MREWTSO		0x240c		/* RCV ｽﾃｰﾀｽ ﾋﾞｯﾄ ｵﾌ ｼｮﾘ			 */
#define	MREWVPF		0x240d		/* MRWFEB ｶｲﾎｳ ｼｮﾘ			 		 */
#define	MREWCLR		0x240e		/* 復旧後処理					TD49 */
#define	MREWVCP		0x240f		/* ﾛﾝﾘ ﾎﾞﾘｭｰﾑ ｺﾋﾟｰ ｼｮﾘ				 */
#define	MREWENQ		0x2410		/* ｼｹﾞﾝ ｾﾝﾕｳ ｼｮﾘ					 */
#define	MREWJOP		0x2411		/* ｼﾞｬｰﾅﾙ ｵｰﾌﾟﾝ ｼｮﾘ					 */
#define	MREWJRD		0x2412		/* ｼﾞｬｰﾅﾙ ﾖﾐｺﾐ ｼｮﾘ					 */
#define	MREWJED		0x2413		/* ｼﾞｬｰﾅﾙ ﾍﾝｼｭｳ ｼｮﾘ					 */
#define	MREWJNL		0x2414		/* ｼﾞｬｰﾅﾙ ｼｭﾄｸ ｼｮﾘ					 */
#define	MREWJAF		0x2415		/* ｼﾞｬｰﾅﾙ ｼｭﾄｸ ｱﾄ ｼｮﾘ				 */
#define	MREWJSP		0x2416		/* ｼﾞｬｰﾅﾙ ﾎﾟｼﾞｼｮﾝ ｼｮﾘ				 */
#define	MREWRSN		0x2418		/* ｼｮｳｶﾞｲ ｶｲﾌｸ ﾂｳﾁ ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｼｮﾘ	 */
#define	MREWARL		0x2419		/* ﾘｻﾞﾙﾄ ｼﾞｭｼﾝ ｼｮﾘ					 */
#define	MREWEOF		0x241a		/* EOF情報設定処理				TD49 */
#define	MREWEJQ		0x241b		/* ｼｮｳｶﾞｲ ﾂｳﾁ ｼｮﾘ					 */
#define	MREWISN		0x241c		/* ﾌｯｷｭｳ ｼﾞｮｳﾎｳ ﾃﾞﾝﾌﾞﾝ ｿｳｼﾝ ｼｮﾘ		 */
#define	MREWRSD		0x241d		/* ﾘｽﾄｱ対象ﾎﾞﾘｭｰﾑ決定処理		TD49 */
#define	MREWFEQ		0x241e		/* FMT資源占有処理				TD49 */
#define	MREWFJM		0x241f		/* FJ復旧ﾒｲﾝ処理				TD49 */
#define	MREWFRD		0x2420		/* FJ復旧対象ﾎﾞﾘｭｰﾑ決定処理		TD49 */
#define	MREWGPV		0x2421		/* PVT･VMTｴﾝﾄﾘ番号獲得処理		TD49 */
#define	MREWINF		0x2422		/* 初期処理						TD49 */
#define	MREWJCL		0x2423		/* ｼﾞｬｰﾅﾙｸﾛｰｽﾞ処理				TD49 */
#define	MREWJEA		0x2424		/* ｼﾞｬｰﾅﾙ2重故障時ｴﾗｰ処理		TD49 */
#define MREWRBS		0x2425		/* RBI ﾃｲｼｭｳｷ ｼｭﾄｸ ﾃｲｼ ｲﾗｲ ｼｮﾘ (L16) */
#define MREWRBR		0x2426		/* RBI ﾃｲｼｭｳｷ ｼｭﾄｸ ｶｲｼ ｲﾗｲ ｼｮﾘ (L16) */
#define MREWRBP		0x2427		/* ﾃｲｼｭｳｷ ｼｭﾄｸ ｶｲｼ ﾚｲｶﾞｲ ﾙｰﾁﾝ  (L16) */
#define	MREWRVC		0x2428 		/* RCVﾌｧｲﾙ収容情報設定処理		TD90 */
#define	MREWFOC		0x2429 		/* 一般ﾌｧｲﾙ対象ﾁｪｯｸ処理			TD90 */
#define	MREWWOC		0x242a 		/* ﾜｰｸﾌｧｲﾙ対象ﾁｪｯｸ処理			TD90 */
#define	MREWROC		0x242b 		/* RCVﾌｧｲﾙ対象ﾁｪｯｸ処理			TD90 */
#define	MREWFOS		0x242c 		/* 一般ﾌｧｲﾙ復旧情報設定処理		TD90 */
#define	MREWVVG		0x242d 		/* MRWFEB獲得処理				TD49 */
#define	MREWEDS		0x242e 		/* 故障発生日付時刻設定処理		TD46 */
#define	MREWROS		0x242f 		/* RCVﾎﾞﾘｭｰﾑ復旧情報設定処理	TD90 */
#define	MREWRSS		0x2430 		/* リラン時復旧情報設定処理		TD90 */
#define	MREWRSC		0x2431 		/* リラン時対象ﾎﾞﾘｭｰﾑﾁｪｯｸ処理	TD90 */
#define	MREWJRS		0x2432 		/* ｼﾞｬｰﾅﾙﾚｺｰﾄﾞﾁｪｯｸ処理			TD49 */
#define	MREWJVR		0x2433 		/* VMT･FMT故障情報更新処理		TD49 */
#define	MREWFEA		0x2434 		/* ファイルブロック解放処理		TD90 */
#define	MREWUMC		0x2435 		/* 論理ﾎﾞﾘｭｰﾑｱﾝﾏｳﾝﾄ処理			TD02 */
#define	MREWOUM		0x2436 		/* ﾎﾞﾘｭｰﾑｱﾝﾏｳﾝﾄ					TD61 */
#define	MREWVEP		0x2437 		/* MRWVEBP検索処理				TD22 */
#define	MREWOCL		0x2438 		/* ﾌｧｲﾙのｸﾛｰｽﾞ					TD61 */
#define	MREWPCL		0x2439		/* 論理ﾎﾞﾘｭｰﾑ内ﾌｧｲﾙｸﾛｰｽﾞ		TD49 */
#define	MREWPER		0x243a		/* ﾎﾞﾘｭｰﾑ故障後処理				TD49 */
#define	MREWWOS		0x243b		/* ﾜｰｸﾎﾞﾘｭｰﾑ復旧情報設定処理	TD22 */
#define	MREWVIN		0x243c		/* 論理ﾎﾞﾘｭｰﾑ初期化処理			TD49 */
#define	MREWMSM		0x243d		/* ﾐﾗｰﾎﾞﾘｭｰﾑ状態遷移処理		TD22 */
#define	MREWVMT		0x243e		/* TVMT更新処理					TD22 */
#define	MREWVMI		0x243f		/* ﾐﾗｰﾎﾞﾘｭｰﾑ状態取得処理		TD22 */
#define	MREWFEX		0x2440		/* ﾌｧｲﾙ拡張処理					TD@1 */
#define	MREWFCK		0x2441		/* TFMTﾁｪｯｸ処理					TD@1 */
#define	MREWOEX		0x2442		/* ﾌｧｲﾙ領域の拡張				TD61 */
#define	MREWRCP		0x2443		/* 閉塞依頼電文受信後処理		TD49 */
#define	MREWOCR		0x2444		/* ﾌｧｲﾙの生成					TD61 */
#define	MREWOWR		0x2445		/* ﾃﾞｰﾀの直接書込				TD61 */
#define	MREWFMD		0x2446		/* 一般ﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ作成処理		TD@1 */
#define	MREWFCR		0x2447		/* 一般ﾌｧｲﾙ創成処理				TD@1 */
#define	MREWCRT		0x2448		/* 一般ﾌｧｲﾙ初期化処理			TD@1 */
#define	MREWRND		0x2449		/* ﾗﾝﾀﾞﾏｲｽﾞﾌｧｲﾙ初期化			TD@1 */
#define	MREWWMD		0x244a		/* ﾜｰｸﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ作成処理		TD@1 */
#define	MREWWMT		0x244b		/* TWMT更新処理					TD33 */
#define	MREWMIR		0x244c		/* ﾐﾗｰﾎﾞﾘｭｰﾑ復旧処理			TD22 */
#define	MREWAMN		0x244d		/* 復旧ﾎﾞﾘｭｰﾑﾏｳﾝﾄ処理			TD49 */
#define	MREWBJD		0x244e		/* 復旧ｼﾞｬｰﾅﾙ環境設定			TD49 */
#define	MREWFOP		0x244f		/* FJ復旧ﾌｧｲﾙｵｰﾌﾟﾝ処理			TD49 */
#define	MREWFJU		0x2450		/* FJﾃﾞｰﾀ更新処理				TD49 */
#define	MREWJFE		0x2451		/* EOF情報仮更新処理			TD49 */
#define	MREWIFO		0x2452		/* ﾌｧｲﾙ情報取得					TD49 */
#define	MREWRFE		0x2453		/* EOF情報実更新処理			TD49 */
#define	MREWVEQ		0x2454		/* TVMT占有処理					TD49 */
#define	MREWTRM		0x2455		/* ﾌﾟﾛｾｽ終了処理				TD49 */
#define	MREWPCD		0x2456		/* ﾊﾞｯｸｱｯﾌﾟIDﾁｪｯｸ処理			TD49 */
#define	MREWPCK		0x2457		/* ﾊﾟﾗﾒﾀﾁｪｯｸ処理				TD49 */
#define	MREWPCN		0x2458		/* 故障ﾎﾞﾘｭｰﾑ復旧時ﾁｪｯｸ処理		TD49 */
#define	MREWPCR		0x2459		/* 物理ﾎﾞﾘｭｰﾑ故障情報ｸﾘｱ処理	TD49 */
#define	MREWPCU		0x245a		/* リラン対応時ﾁｪｯｸ処理			TD49 */
#define	MREWPEA		0x245b		/* ﾎﾞﾘｭｰﾑ復旧不可能時処理		TD49 */
#define	MREWPRE		0x245c		/* 物理ﾎﾞﾘｭｰﾑ関連情報後処理		TD49 */
#define	MREWPRM		0x245d		/* 解析情報設定処理				TD49 */
#define	MREWPRV		0x245e		/* ﾘｽﾄｱ対象論理ﾎﾞﾘｭｰﾑ検索処理	TD49 */
#define	MREWRNE		0x245f		/* 復旧終了ﾎﾞﾘｭｰﾑ状態ﾁｪｯｸ処理	TD49 */

/****************************************/
/*	22.SCSIﾘｾﾂﾄﾌﾟﾛｾｽ(mrg)		CT1039	*/
/****************************************/
#define	MREGCOM		0x2460		/*	ＳＣＳＩリセット共通	   TD61 */
#define	MREGMAN		0x2461		/*	メイン処理				   TD61 */
#define	MREGSR1		0x2462		/*	疑似ＳＭＰ通知１受信時処理 TD61 */
#define	MREGSR2		0x2463		/*	疑似ＳＭＰ通知２受信時処理 TD61 */
#define	MREGSR3		0x2464		/*	ＳＭＰ通知３受信時処理	   TD61 */
#define	MREGOCN		0x2465		/*	特殊ﾌｧｲﾙコネクト処理	   TD61 */
#define	MREGODN		0x2466		/*	特殊ﾌｧｲﾙディスコネクト処理 TD61 */
#define	MREGOSI		0x2467		/*	入出力制御処理			   TD61 */
#define	MREGOPN		0x2468		/*	特殊ファイルオープン処理   TD61 */
#define	MREGCLS		0x2469		/*	特殊ファイルクローズ処理   TD61 */
#define	MREGSR4		0x246a		/*	疑似SMP通知受信時処理 	ST4008  */
#define	MREGWTO		0x246b		/*  メッセージ出力処理		   TD61 */

/*********************************/
/*	23.ﾎﾞﾘｭ-ﾑ ｺﾋﾟｰ ｼｮﾘ			 */
/*********************************/
#define MRELCOM     0x2480      /* ﾎﾞﾘﾕ-ﾑｺﾋﾟ-処理共通           TD@1 */
#define	MRELMAN		0x2481		/* ﾎﾞﾘｭ-ﾑ ｺﾋﾟｰ ﾒｲﾝ ｼｮﾘ	  (L09) TD@1 */
#define	MRELARL		0x2482		/* ﾘｻﾞﾙﾄ ｼﾞｭｼﾝ ｼｮﾘ					 */
#define MRELINT     0x2483      /* 初期処理                     TD49 */
#define MRELPRM     0x2484      /* ﾊﾟﾗﾒﾀﾁｴﾂｸ処理                TD49 */
								/* 詳細情報2の使用に伴う削除(13行)   */
								/*                              TD49 */
#define MRELVMT     0x2485      /* VMT検索処理                  TD49 */
#define MRELMRT     0x2486      /* MRT検索処理                  TD22 */
#define MRELVBT     0x2487      /* VBT検索処理                  TD49 */
#define MRELCHK     0x2488      /* 起動元正当性ﾁｴﾂｸ処理         TD49 */
#define MRELSYC     0x2489      /* 強制書き出し処理             TD61 */
#define	MRELDCP		0x248a		/* ｼﾞｷ ﾃﾞｨｽｸ ｺﾋﾟｰ ｼｮﾘ				 */
#define MRELOPN     0x248b      /* ﾌｱｲﾙｵ-ﾌﾟﾝ処理                TD49 */
#define MRELCON     0x248c      /* ｺﾈｸﾄ処理                     TD61 */


#define MRELCLS     0x248f      /* ﾌｱｲﾙｸﾛ-ｽﾞ処理                TD49 */
#define	MRELOFL		0x2490		/* 強制書き込み処理				TD61 */
#define	MRELTRM		0x2491		/* ｼｭｳﾘｮｳ ｼｮﾘ		            TD@1 */

/*********************************/
/*	  ﾎﾞﾘｭ-ﾑ ｼｮｷｶ ｼｮﾘ	    	 */
/*********************************/
								/* 当ﾌﾟﾛｾｽの廃止に伴う削除(6行) TD@1 */

/*********************************/
/*  24.ｻﾌﾞ故障管理ﾌﾟﾛｾｽ     TD00 */
/*********************************/
#define MREKCOM		0x24c0		/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽ共通			TD02 */
#define MRESERP		0x24c1		/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽﾒｲﾝ			TD02 */
#define MREEKST		0x24c2		/* ﾌﾟﾛｾｽ開始処理				TD02 */
#define	MREEKRM		0x24c3		/* ﾒｯｾｰｼﾞ受信要求処理			TD02 */
#define	MREEKAR		0x24c4		/* ﾒｯｾｰｼﾞ受信処理				TD02 */
#define MREEKHR		0x24c5		/* 閉塞依頼電文受信時の処理		TD02 */
#define	MREEKPV		0x24c6		/* PVT検索処理					TD02 */
#define MREEKMS		0x24c7		/* 閉塞/閉塞解除完了電文送信処理TD02 */
#define MREEKNR		0x24c8		/* 閉塞解除依頼電文受信時の処理	TD02 */
#define	MREEKTD		0x24c9		/* SMP通知電文受信時の処理		TD02 */
#define MREEKBA		0x24ca		/* ﾊﾞｯﾃﾘｰｱﾗｰﾑ通知処理			TD02 */
#define	MREEKTM		0x24cb		/* ﾌﾟﾛｾｽ終了処理				TD02 */
#define	MREEKMO		0x24cc		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ閉塞処理		ST3492	 */
#define	MREEKUF		0x24cd		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ強制ｱﾝﾏｳﾝﾄ処理	ST3492	 */
#define	MREEKMI		0x24ce		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑ組込処理		ST3492	 */
#define	MREEKMT		0x24cf		/* ﾐﾗ-ﾎﾞﾘﾕ-ﾑﾏｳﾝﾄ処理		ST3492	 */

/*********************************/
/*  25.ＶＲＣＶ／信金       TD00 */
/*********************************/
#define	MREVCOM		0x2500		/* ＶＲＣＶ（ＦＪ無し）共通		TD99 */
#define	MREVMAN		0x2501		/* ＶＲＣＶ(ＦＪ無し)メイン処理	TD99 */
#define	MREVMRQ		0x2502		/* 電文受信要求処理				TD99 */
#define	MREVJED		0x2503		/* ジャーナルデータ編集処理		TD99 */
#define	MREVJNL		0x2504		/* ジャーナルデータ書き込み処理	TD99 */
#define	MREVJAF		0x2505		/* ジャーナル取得後処理			TD99 */
#define	MREVUMC		0x2506		/* アンマウント共通処理			TD99 */
#define	MREVMNT		0x2507		/* マウント処理					TD99 */
#define	MREVRVF		0x2508		/* ﾘｶﾊﾞﾘﾌｧｲﾙTFMT検索処理		TD99 */
#define	MREVWTO		0x2509		/* メッセージ出力処理			TD99 */
#define	MREVSIZ		0x250a		/* 文字列長算出処理			CT1093	 */
#define	MREVERF		0x250b		/* ファイル名待避処理		ST2893	 */

#define	MREVINT		0x2510		/* ＶＲＣＶ初期機能メイン処理	TD99 */
#define	MREVSCK		0x2511		/* システム状態チェック処理		TD99 */
#define	MREVPCB		0x2512		/* ﾌﾟﾛｾｽ制御ﾌﾞﾛｯｸ初期化処理		TD99 */
#define	MREVPCK		0x2513		/* ＴＰＣＴチェック処理			TD99 */
#define	MREVACK		0x2514		/* 入力パラメタチェック処理		TD99 */
#define	MREVANC		0x2515		/* ﾎﾞﾘｭｰﾑ回復ﾊﾟﾗﾒﾀﾁｪｯｸ処理		TD99 */
#define	MREVARC		0x2516		/* ﾎﾞﾘｭｰﾑﾘｽﾄｱﾊﾟﾗﾒﾀﾁｪｯｸ処理		TD99 */
#define	MREVMTC		0x2517		/* 電文廃棄処理					TD99 */
#define	MREVJOP		0x2518		/* ｼﾞｬｰﾅﾙﾌｧｲﾙｵｰﾌﾟﾝ処理			TD99 */
#define	MREVRST		0x2519		/* ﾘｶﾊﾞﾘｽﾃｰﾀｽﾁｪｯｸ処理			TD99 */

#define	MREVRCV		0x2520		/* 故障ボリューム回復処理		TD99 */
#define	MREVINS		0x2521		/* 物理ボリューム閉塞解除処理	TD99 */
#define	MREVANY		0x2522		/* 物理vol閉塞解除完了電文受信	TD99 */
#define	MREVTIM		0x2523		/* インタバルタイマ設定処理		TD99 */
#define	MREVVCK		0x2524		/* 回復ボリュームチェック処理	TD99 */
#define	MREVRVC		0x2525		/* ﾘｶﾊﾞﾘﾌｧｲﾙﾎﾞﾘｭｰﾑﾁｪｯｸ処理		TD99 */
#define	MREVNVC		0x2526		/* 一般ﾌｧｲﾙﾎﾞﾘｭｰﾑﾁｪｯｸ処理		TD99 */
#define	MREVPVT		0x2527		/* ＴＰＶＴ更新処理				TD99 */
#define	MREVVMT		0x2528		/* ＴＶＭＴ更新処理				TD99 */
#define	MREVVMI		0x2529		/* ミラーボリューム状態取得処理	TD99 */
#define	MREVCRS		0x252a		/* リストア制御処理				TD99 */
#define	MREVVER		0x252b		/* 論理ボリューム閉塞処理		TD99 */
#define	MREVSVT		0x252c		/* リストア対象決定処理			TD99 */
#define	MREVENQ		0x252d		/* ＴＶＭＴ占有処理			CT1091	 */
#define	MREVDEQ		0x252e		/* ＴＶＭＴ占有解除処理		CT1091	 */
#define	MREVMCK		0x252f		/* 肺状態チェック処理		ST2891	 */

#define	MREVPRV		0x2530		/* ボリューム回復前処理			TD99 */
#define	MREVVIN		0x2531		/* 論理ボリューム初期化処理		TD99 */
#define	MREVMVT		0x2532		/* ミラーボリューム状態遷移処理	TD99 */
#define	MREVMRV		0x2533		/* ミラーボリューム復旧前処理	TD99 */
#define	MREVNBV		0x2534		/* ﾊﾞｯｸｱｯﾌﾟ要ﾎﾞﾘｭｰﾑ回復前処理	TD99 */
#define	MREVVBT		0x2535		/* ＴＶＢＴチェック処理			TD99 */
#define	MREVVLC		0x2536		/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽ起動処理		TD99 */
#define	MREVRVV		0x2537		/* リカバリボリューム回復前処理	TD99 */

#define	MREVTWT		0x2540		/* 回復終了待ち合わせ処理		TD99 */
#define	MREVRVM		0x2541		/* 受信電文振り分け処理			TD99 */
#define	MREVTRV		0x2542		/* ボリューム回復後処理			TD99 */
#define	MREVMTR		0x2543		/* ミラーボリューム復旧後処理	TD99 */
#define	MREVPTR		0x2544		/* ボリュームコピー後処理		TD99 */
#define	MREVFMT		0x2545		/* ＴＦＭＴ同期処理				TD99 */
#define	MREVFML		0x2546		/* ＴＦＭＴリスト作成処理		TD99 */
#define	MREVDFC		0x2547		/* ﾃﾞｨﾚｸﾄﾘ･TFMT比較処理			TD99 */
#define	MREVFDR		0x2548		/* ディレクトリファイル処理		TD99 */
#define	MREVFFL		0x2549		/* 通常ファイル処理				TD99 */
#define	MREVFDL		0x254a		/* ファイル削除処理				TD99 */
#define	MREVFMD		0x254b		/* ファイルステータス更新処理	TD99 */
#define	MREVUTR		0x254c		/* ﾊﾞｯｸｱｯﾌﾟ不要ﾎﾞﾘｭｰﾑ回復後処理	TD99 */
#define	MREVUMD		0x254d		/* 一般ﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ作成処理		TD99 */
#define	MREVUCR		0x254e		/* 一般ファイル創成処理			TD99 */
#define	MREVFCK		0x254f		/* 該当ファイルチェック処理		TD99 */
#define	MREVFIT		0x2550		/* ファイル初期化処理			TD99 */
#define	MREVURD		0x2551		/* ﾗﾝﾀﾞﾏｲｽﾞﾌｧｲﾙ初期化処理		TD99 */
#define	MREVWTR		0x2552		/* ﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑ回復後処理		TD99 */
#define	MREVWMD		0x2553		/* ﾜｰｸﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ作成処理		TD99 */
#define	MREVWMT		0x2554		/* ＴＷＭＴ更新処理				TD99 */
#define	MREVEJQ		0x2555		/* ジャーナル取得依頼発行処理	TD99 */
#define	MREVRMS		0x2556		/* ﾎﾞﾘｭｰﾑ復旧情報通知電文送信	TD99 */
#define	MREVMSG		0x2557		/* 回復終了メッセージ出力処理	TD99 */
#define	MREVEOF		0x2558		/* EOF同期処理				ST3804	 */

#define	MREVTRM		0x2560		/* プロセス終了時処理			TD99 */
#define	MREVSTP		0x2561		/* プロセス中断時処理			TD99 */
#define	MREVVRS		0x2562		/* 論理ボリューム閉塞解除処理	TD99 */

#define	MREVOCR		0x2570		/* ｏｓｃｒｅａｔ共通処理		TD99 */
#define	MREVOCL		0x2571		/* ｏｓｃｌｏｓｅ共通処理		TD99 */
#define	MREVODL		0x2572		/* ｏｓｄｅｌｅｔ共通処理		TD99 */
#define	MREVOEX		0x2573		/* ｏｓｅｘｔｅｎ共通処理		TD99 */
#define	MREVOMT		0x2574		/* ｏｓｍｏｕｎｔ共通処理		TD99 */
#define	MREVORD		0x2575		/* ｏｓｒｅａｄ共通処理			TD99 */
#define	MREVOTR		0x2576		/* ｏｓｔｒｕｎｃ共通処理		TD99 */
#define	MREVOUM		0x2577		/* ｏｓｕｍｏｕｎｔ共通処理		TD99 */
#define	MREVOWT		0x2578		/* ｏｓｗｒｉｔｅｄ共通処理		TD99 */
#define	MREVOUF		0x2579		/* ｏｓｕｍｏｕｎｔｆ共通処理	TD99 */
#define	MREVABT		0x257a		/* VRCV例外処理				ST2806   */
#define	MREVVMT2	0x257b		/* 肺状態同期処理			ST3991   */

/*********************************/
/*  26.ﾊﾞﾂｸｱﾂﾌﾟ／信金       TD00 */
/*********************************/
#define	MREBCON		0x2580		/* ﾊﾞｯｸｱｯﾌﾟ／信金共通			TD83 */
#define	MREBMAN		0x2581		/* ﾊﾞｯｸｱｯﾌﾟ／信金メイン			TD83 */
#define	MREBBKS		0x2582		/* TBKT個別部検索処理			TD83 */
#define	MREBUMT		0x2583		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑｱﾝﾏｳﾝﾄ処理		TD83 */
#define MREBBMNT	0x2584		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑﾏｳﾝﾄ処理		TD83 */
#define	MREBMCK		0x2585		/* 論理ﾎﾞﾘｭｰﾑ識別名ﾁｪｯｸ処理		TD83 */
#define	MREBGTP		0x2586		/* JNLﾊﾞｯｸｱｯﾌﾟﾌｧｲﾙﾊﾟｽ名生成処理 TD83 */
#define	MREBOMN		0x2587		/* ﾌｧｲﾙ･ｼｽﾃﾑのﾏｳﾝﾄ処理			TD61 */
#define MREBOUM		0x2588		/* ﾌｧｲﾙ･ｼｽﾃﾑのｱﾝﾏｳﾝﾄ処理		TD61 */
#define MREBORE		0x2589		/* ﾃﾞｰﾀの直接読込				TD61 */
#define MREBSCC		0x258a		/* ｼﾝｸﾞﾙｺﾋﾟｰﾊﾟﾗﾒﾀﾁｪｯｸ処理		TD83 */ 
#define	MREBPRM		0x258b		/* ﾊﾟﾗﾒﾀﾁｪｯｸ処理				TD83 */
#define MREBINT		0x258c		/* 初期処理						TD83 */
#define MREBSRT		0x258d		/* 開始処理						TD83 */
#define MREBENQ		0x258e		/* 資源占有処理					TD83 */
#define	MREBIND		0x258f		/* 開始同期処理					TD83 */
#define	MREBUAL		0x2590		/* ﾘｻﾞﾙﾄ受信処理				TD83 */
#define MREBERV		0x2591		/* ﾊﾞｯｸｱｯﾌﾟ続行可否判定処理		TD83 */
#define	MREBSNM		0x2592		/* 電文送信処理					TD83 */
#define MREBRBE		0x2593		/* RBI定周期取得停止依頼処理	TD83 */
#define	MREBJOP		0x2594		/* ｼﾞｬｰﾅﾙｵｰﾌﾟﾝ処理				TD83 */
#define	MREBJED		0x2595		/* ｼﾞｬｰﾅﾙｸﾛｰｽﾞ処理				TD83 */
#define MREBJNL		0x2596		/* ｼﾞｬｰﾅﾙ取得処理				TD83 */
#define MREBSBK		0x2597		/* ｼﾝｸﾞﾙｺﾋﾟｰﾊﾞｯｸｱｯﾌﾟ処理		TD83 */
#define MREBVCP		0x2598		/* 論理ﾎﾞﾘｭｰﾑｼﾝｸﾞﾙｺﾋﾟｰ処理		TD83 */
#define MREBCRL		0x2599		/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽからのﾘｻﾞﾙﾄ   TD83 */
								/* 受信処理							 */
#define	MREBESN		0x259a		/* 故障通知電文送信処理			TD83 */	
#define MREBMBK		0x259b		/* ﾏﾙﾁｺﾋﾟｰﾊﾞｯｸｱｯﾌﾟ処理			TD83 */
#define MREBMCP		0x259c		/* 論理ﾎﾞﾘｭｰﾑﾏﾙﾁｺﾋﾟｰ処理		TD83 */
#define	MREBKJC		0x259d		/* 勘定照合ﾌｧｲﾙ面切替処理		TD67 */
#define	MREBKBK		0x259e		/* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ処理		TD83 */
#define	MREBKCP		0x259f		/* KJｺﾋﾟｰ処理					TD83 */
#define	MREBJNM		0x25a0		/* ﾊﾞｯｸｱｯﾌﾟﾌｧｲﾙ名書換処理       TD83 */
#define	MREBTRM		0x25a1		/* 終了処理						TD83 */
#define	MREBCAN		0x25a2		/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽｷｬﾝｾﾙ処理		TD83 */
#define	MREBJAF		0x25a3		/* ｼﾞｬｰﾅﾙ取得後処理				TD83 */
#define	MREBTRP		0x25a4		/* 終了後処理					TD83 */
#define	MREBTRD		0x25a5		/* 終了同期処理					TD83 */
#define	MREBMCC		0x25a6		/* ﾏﾙﾁｺﾋﾟｰﾊﾟﾗﾒﾀﾁｪｯｸ処理			TD83 */
#define MREBWTO		0x25a7		/* ﾒｯｾｰｼﾞ出力処理				TD83 */	
#define	MREBVBK		0x25a8		/* 一般ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ処理			TD83 */
#define	MREBJCL		0x25a9		/* ｼﾞｬｰﾅﾙｸﾛｰｽﾞ処理				TD83 */
#define	MREBURA		0x25aa		/* 裏面ﾊﾞｯｸｱｯﾌﾟｽﾃｰﾀｽｸﾘｱ処理		TD83 */
#define	MREBMSG		0x25ab		/* 電文受信後処理				TD83 */
#define	MREBFMQ		0x25ac		/* TFMT占有処理					TD83 */
#define	MREBPBK		0x25ad		/* ﾊﾟﾗﾒﾀ指定ﾊﾞｯｸｱｯﾌﾟ処理		TD83 */
#define MREBVSR		0x25ae		/* ﾊﾞｯｸｱｯﾌﾟｽﾃｰﾀｽﾘｾｯﾄ処理		TD83 */	
#define	MREBVBR		0x25af		/* TVBT更新内容決定処理			TD83 */
#define	MREBIJN		0x25b0		/* 初期JNL取得処理				TD83 */
#define MREBPBR		0x25b2		/* I/Oｴﾗｰ発生TPBT内ﾊﾞｯｸｱｯﾌﾟｽﾃｰﾀｽTD83 */
								/* ﾘｾｯﾄ処理						TD83 */
#define	MREBBKR		0x25b3		/* TBKTｽﾃｰﾀｽﾘｾｯﾄ処理			TD83 */
#define MREBOLN		0x25b4		/* ﾌｧｲﾙへのﾘﾝｸ処理				TD83 */
#define MREBBKT		0x25b5		/* TBKT仮更新処理				TD83 */
#define MREBTBL		0x25b6		/* TBKT実更新処理				TD83 */
#define	MREBERM		0x25b7		/* I/Oｴﾗｰ発生ﾊﾞｯｸｱｯﾌﾟ物理ﾎﾞﾘｭｰﾑ TD83 */
								/* 識別名出力処理					 */
#define MREBROF		0x25b8		/* リカバリﾘｶﾊﾞﾘｽﾃｰﾀｽ更新処理   TD83 */
#define	MREBDAT		0x25b9		/* ﾊﾞｯｸｱｯﾌﾟID設定処理			TD83 */
#define	MREBVBT		0x25ba		/* TVBT実更新処理				TD83 */
#define	MREBMTC		0x25bb		/* TVBT実更新処理				TD83 */
#define MREBRBG		0x25bc		/* RBI直接取得依頼処理			TD83 */
#define MREBRBS		0x25bd		/* RBI定周期取得開始依頼処理	TD83 */
#define	MREBMCK2	0x25be		/* 論理ﾎﾞﾘｭｰﾑ識別名ﾁｪｯｸ処理		TD49 */
#define	MREBMNT2	0x25bf		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑﾏｳﾝﾄ処理		TD49 */
#define	MREBUMT2	0x25c0		/* ﾊﾞｯｸｱｯﾌﾟﾎﾞﾘｭｰﾑｱﾝﾏｳﾝﾄ処理		TD49 */
#define	MREBENQ2	0x25c1		/* 資源占有処理					TD46 */
#define	MREBCAN2	0x25c2		/* VRCV(mro)ｷﾔﾝｾﾙ処理		CT1163	 */
#define	MREBCAN3	0x25c3		/* VRCV起動mrcｷﾔﾝｾﾙ処理		CT1163	 */

/***********************************/
/*  27.ｓｐｍｃｒｅｆ 		ST4608 */
/***********************************/
#define	MREMRCREF	0x2600		/* SPM待避ファイル作成		ST4608	 */

/*********************************************************************/
/*	ｼｮｳｻｲ ｺ-ﾄﾞ ﾌｶ ｼﾞｮｳﾎｳ ﾉ ﾃｲｷﾞ										 */
/*********************************************************************/
/*********************************/
/*	1.ﾃ-ﾌﾞﾙ ｼｷﾍﾞﾂｼ ﾉ ﾃｲｷﾞ		 */
/*********************************/
#define	MRDTTCT		0x00000001	/* TTCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
								/* TRES廃止による削除(1行)      TD61 */
#define MRDTSUR     0x00000002  /* TSUR ﾃ-ﾌﾞﾙｴﾗ-                TD61 */
#define MRDTPUT     0x00000004  /* TPUT ﾃ-ﾌﾞﾙｴﾗ-                TD59 */
#define	MRDTJCT		0x00000008	/* TJCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBKT		0x00000010	/* TBKT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTRCT		0x00000020	/* TRCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTTDT		0x00000040	/* TTDT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTRBT		0x00000080	/* TRBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTFMT		0x00000100	/* TFMT ﾃｰﾌﾞﾙ ｴﾗｰ				TD49 */
#define	MRDTFMTJ	0x00000101	/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ﾉ TFMT ﾃ-ﾌﾞﾙ ｴﾗ- TD49 */
#define	MRDTFMTK	0x00000102	/* KJﾌｧｲﾙのTFMTﾃ-ﾌﾞﾙｴﾗ-			TD42 */
#define	MRDTFMTR	0x00000104	/* RBI ﾌｧｲﾙ ﾉ TFMT ﾃ-ﾌﾞﾙ ｴﾗ-    TD49 */
#define MRDTSBR     0x00000200  /* TSBRﾃ-ﾌﾞﾙｴﾗ-                 TD61 */
#define	MRDTSST		0x00000400	/* TSST ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTPCT		0x00000800	/* ｼｮｳｶﾞｲ ﾂｳﾁｻｷ AP ﾌﾟﾛｾｽ ｼｷﾍﾞﾂﾒｲ ｶﾞ	 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define	MRDTDAPCT	0x00000801	/* ﾀﾞｲﾋｮｳ AP ﾌﾟﾛｾｽ ｼｷﾍﾞﾂﾒｲ ｶﾞ		 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ	   (L10) */
#define	MRDTRBI		0x00001000	/* RBI ｼｮﾄｸ ﾃ-ﾌﾞﾙ ﾉ ｵｵｷｻ ｶﾞ ﾌﾄｳ		 */
#define	MRDTRBPCT	0x00002000	/* RBI ﾌﾟﾛｾｽ ｼｷﾍﾞﾂﾒｲ ｶﾞ 			 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define	MRDTERPCT 	0x00004000	/* ｼｮｳｶﾞｲ ｱﾄｼｮﾘ ﾌﾟﾛｾｽ ｶﾞ PCT ﾆ ﾅｲ	 */
#define	MRDTSEPCT	0x00004001	/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽがTPCTに無い(TD02)*/
#define	MRDTGRPCT	0x00004002	/* SCSIﾘｾﾂﾄﾌﾟﾛｾｽがTPCTに無い  CT1039 */
#define MRDTSRPCT	0x00004003	/* SSRCVﾌﾟﾛｾｽがTPCTに定義されていない*/
								/*								TD39 */
#define MRDTARPCT	0x00004004	/* ARCVﾌﾟﾛｾｽがTPCTに定義されていない */
								/*								TD02 */
#define MRDTVCPCT	0x00004005	/* ﾎﾞﾘｭｰﾑ ｺﾋﾟｰ ﾌﾟﾛｾｽ ｶﾞ				 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ	CT1163	 */
#define	MRDTVRPCT	0x00004006	/* VRCVﾌﾟﾛｾｽがPCTに未定義	CT1163	 */
#define MRDTPVT		0x00008000	/* TPVT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
                                /* ﾎﾞﾘﾕ-ﾑ閉塞単位変更による削除(3行) */
								/*                              TD90 */
#define MRDTSTVMT	0x00008005	/* TVMT ｽﾃｰﾀｽ ｴﾗ-			  ST1550 */
#define MRDTVBT		0x00010000	/* TVBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTPBT		0x00020000	/* TPBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBKPCT	0x00040000	/* ﾊﾞｯｸ ｱｯﾌﾟ ｼｮﾘ ｶﾗ 				 */
								/*	ﾃﾞﾝﾌﾞﾝ ｦ ｵｸﾙ ﾌﾟﾛｾｽ ｶﾞ			 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define MRDTVMT		0x00080000	/* TVMT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTERVMT	0x00080001  /* 閉塞依頼を受けたボリュームが TD90 */
								/* TVMTに定義されていない       TD90 */
#define MRDTCRVMT	0x00080002	/* 閉塞依頼を受けたﾎﾞﾘｭｰﾑがｸﾛｽｺ-ﾙ    */
								/* ﾎﾞﾘｭｰﾑでない                 TD90 */
#define MRDTVMTJ	0x00080003	/* ｼﾞｬｰﾅﾙﾌｧｲﾙがﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑに	TD42 */
								/* 存在する							 */
#define MRDTVMTK	0x00080004	/* KJﾌｧｲﾙがﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑに存在	TD42 */
								/* する								 */
#define MRDTSRT		0x00100000	/* TSRT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTWMT		0x00200000	/* TWMT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
								/*									 */
#define	MRDTMRT		0x00800000	/* TMRTﾃｰﾌﾞﾙｴﾗｰ				CT1039	 */

/*********************************/
/*	 2.ｷｷｬｸ ﾃﾞﾝﾌﾞﾝ ｼｭﾍﾞﾂ ﾉ ﾃｲｷﾞ	 */
/*********************************/
#define	MRDALLMSG	0x00000001	/* ｶﾘ ｿｳｼﾝ ﾃﾞﾝﾌﾞﾝ ﾉ ｷｷｬｸ			 */
#define	MRDCEDT		0x00000001  /* ﾃﾞﾝﾌﾞﾝ ﾍﾝｼｭｳ				   (L04) */

/*********************************************************************/
/*	ｼｮｳｻｲ ｺ-ﾄﾞ ﾉ ﾃｲｷﾞ												 */
/*********************************************************************/
/*********************************/
/*	1.ﾛﾝﾘ ｴﾗ- (0x10-0x3F)		 */
/*********************************/
/*-------------------------------*/
/*  1.1.ﾃ-ﾌﾞﾙｴﾗ-                 */
/*-------------------------------*/
#define	MRDTBLERR	0x10000000	/* ﾃ-ﾌﾞﾙ ｴﾗ-						 */
#define	MRDTBLTCT	( MRDTBLERR | MRDTTCT )
								/* TTCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
								/* TRES廃止による削除(1行)      TD61 */
#define MRDTBLSUR   ( MRDTBLERR | MRDTSUR )
								/* TSUR ﾃ-ﾌﾞﾙｴﾗ-                TD61 */
#define	MRDTBLPUT	( MRDTBLERR | MRDTPUT )
								/* TPUT ﾃｰﾌﾞﾙ ｴﾗｰ				TD59 */
#define	MRDTBLJCT	( MRDTBLERR | MRDTJCT )
								/* TJCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLBKT	( MRDTBLERR | MRDTBKT )
								/* TBKT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLRCT	( MRDTBLERR | MRDTRCT )
								/* TRCT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLTDT	( MRDTBLERR | MRDTTDT )
								/* TTDT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLRBT	( MRDTBLERR | MRDTRBT )
								/* TRBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLFMT	( MRDTBLERR | MRDTFMT )
								/* TFMT ﾃ-ﾌﾞﾙ ｴﾗ-			CT1163	 */
#define	MRDTBLFMTJ	( MRDTBLERR | MRDTFMTJ )
								/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ﾉ TFMT ﾃ-ﾌﾞﾙ ｴﾗ-		 */
#define	MRDTBLFMTK	( MRDTBLERR | MRDTFMTK )
								/* KJﾌｧｲﾙのTFMTﾃ-ﾌﾞﾙｴﾗ-			TD42 */
#define	MRDTBLFMTR	( MRDTBLERR | MRDTFMTR )
								/* RBI ﾌｧｲﾙ ﾉ TFMT ﾃ-ﾌﾞﾙ ｴﾗ-		 */
#define MRDTBLSBR   ( MRDTBLERR | MRDTSBR )
								/* TSBR ﾃ-ﾌﾞﾙｴﾗ-                TD61 */
#define	MRDTBLSST	( MRDTBLERR | MRDTSST )
								/* TSST ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLPCT	( MRDTBLERR | MRDTPCT )
								/* ｼｮｳｶﾞｲﾂｳﾁｻｷAPﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲｶﾞ	 	 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define	MRDTBLDAPCT	( MRDTBLERR | MRDTDAPCT )
								/* ﾀﾞｲﾋｮｳAPﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲ ｶﾞ		 	 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ	   (L10) */
#define	MRDTBLRBI	( MRDTBLERR | MRDTRBI )
								/* RBI ｼｮﾄｸ ﾃ-ﾌﾞﾙ ﾉ ｵｵｷｻ ｶﾞ ﾌﾄｳ		 */
#define	MRDTBLRBPCT	( MRDTBLERR | MRDTRBPCT )	
								/* RBIﾌﾟﾛｾｽｼｷﾍﾞﾂﾒｲｶﾞ 			 	 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define	MRDTBLERPCT	( MRDTBLERR | MRDTERPCT )	
								/* ｼｮｳｶﾞｲ ｱﾄｼｮﾘ ﾌﾟﾛｾｽ ｶﾞ PCT ﾆ ﾅｲ	 */
#define	MRDTBLSEPCT ( MRDTBLERR | MRDTSEPCT )
								/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽがTPCTにない(TD02)*/
#define	MRDTBLGRPCT ( MRDTBLERR | MRDTGRPCT )
								/* SCSIﾘｾﾂﾄﾌﾟﾛｾｽがTPCTにない  CT1039 */
#define	MRDTBLSRPCT	( MRDTBLERR | MRDTSRPCT )
								/* SSRCVﾌﾟﾛｾｽ未存在				TD39 */
#define	MRDTBLARPCT	( MRDTBLERR | MRDTARPCT )
								/* ARCVﾌﾟﾛｾｽ未存在				TD02 */
#define MRDTBLVCPCT	( MRDTBLERR | MRDTVCPCT )
								/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽPCT未定義			 */
#define MRDTBLVRPCT	( MRDTBLERR | MRDTVRPCT )
								/* VRCVﾌﾟﾛｾｽPCT未定義		CT1163	 */
#define MRDTBLPVT	( MRDTBLERR | MRDTPVT )
								/* TPVT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
								/* ﾎﾞﾘﾕ-ﾑ閉塞単位変更による削除(3行) */
								/*                              TD90 */
#define MRDTBLVBT	( MRDTBLERR | MRDTVBT )
								/* TVBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTBLPBT	( MRDTBLERR | MRDTPBT )
								/* TPBT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLBKPCT	( MRDTBLERR | MRDTBKPCT )	
								/* ﾊﾞｯｸ ｱｯﾌﾟ ｼｮﾘ ｶﾗ					 */
								/*	ﾃﾞﾝﾌﾞﾝ ｦ ｵｸﾙ ﾌﾟﾛｾｽ ｶﾞ			 */
								/*   TPCT ﾆ ﾃｲｷﾞ ｻﾚﾃ ｲﾅｲ			 */
#define MRDTBLVMT	( MRDTBLERR | MRDTVMT )
								/* TVMT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTBLERVMT	( MRDTBLERR | MRDTERVMT )
								/* 閉塞依頼を受けたボリュームが TD90 */
								/* TVMTに未定義である                */
#define MRDTBLCRVMT	( MRDTBLERR | MRDTCRVMT )
                                /* 閉塞依頼を受けたボリュームが TD90 */
								/* クロスコールボリュームでない      */
#define MRDTBLVMTJ	( MRDTBLERR | MRDTVMTJ )
								/* ｼﾞｬｰﾅﾙﾌｧｲﾙがﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑに	TD42 */
								/* 存在する							 */
#define MRDTBLVMTK	( MRDTBLERR | MRDTVMTK )
								/* KJﾌｧｲﾙがﾜｰｸﾌｧｲﾙﾎﾞﾘｭｰﾑに存在	TD42 */
								/* する								 */
#define MRDTBLSTVMT	( MRDTBLERR | MRDTSTVMT )
								/* TVMT ｽﾃｰﾀｽ ｴﾗ-			  ST1550 */
#define MRDTBLSRT	( MRDTBLERR | MRDTSRT )
								/* TSRT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define MRDTBLWMT	( MRDTBLERR | MRDTWMT )
								/* TWMT ﾃ-ﾌﾞﾙ ｴﾗ-					 */
#define	MRDTBLMRT	( MRDTBLERR | MRDTMRT )	/*	TMRTﾃｰﾌﾞﾙｴﾗｰ  CT1039 */

/*-------------------------------*/
/*  1.2.その他の論理エラー       */
/*-------------------------------*/
#define	MRDFBUFERR	0x11000000	/* ﾌﾟ-ﾙ ﾊﾞｯﾌｧ ｶｲﾎｳ ｴﾗ-				 */
#define	MRDNORBIERR	0x12000000	/* ﾕｳｺｳ RBI ｶﾞ ｿﾝｻﾞｲ ｼﾅｲ			 */
#define	MRDJCHKERR	0x13000000	/* ｼﾞｬ-ﾅﾙ ﾍﾝｼｭｳｲｷ ﾊｶｲ ｴﾗ-			 */
#define	MRDJEDERR	0x14000000	/* ｼﾞｬ-ﾅﾙ ﾍﾝｼｭｳ ｴﾗ-					 */
#define	MRDPRCERR	0x15000000	/* ﾌﾟﾛｾｽ ｼｮｷｶ ｼｮﾘ ｴﾗ-				 */
#define	MRDDATERR	0x16000000	/* ﾏｼﾝ ﾋｽﾞｹ ｼﾞｺｸ ｶｸﾄｸ ｴﾗ-			 */
#define	MRDSENMSERR	0x17000000	/* ﾒｯｾ-ｼﾞ ｿｳｼﾝ ｴﾗ-					 */
#define	MRDEDTMSERR	( MRDSENMSERR | MRDCEDT )
								/* ﾃﾞﾝﾌﾞﾝ ﾍﾝｼｭｳ ｴﾗ-			   (L04) */
#define	MRDRCVMSERR	0x18000000	/* ﾒｯｾ-ｼﾞ ｼﾞｭｼﾝ ｴﾗ-					 */
#define	MRDRBIERR	0x19000000	/* RBI ﾃﾞ-ﾀ ｼｭﾄｸ ｴﾗ- (ｱｸｾｽ ｴﾗ- ｲｶﾞｲ) */
#define	MRDJNLWTERR	0x1a000000	/* ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ｴﾗ-					 */
#define	MRDRSLTERR	0x1b000000	/* ﾋﾄﾞｳｷ ﾖｳｷｭｳ ｶﾝﾘｮｳ ﾏﾁ ｴﾗ-			 */
#define	MRDJDATERR	0x1c000000	/* ｼﾞｬ-ﾅﾙ ｼｭﾄｸ ﾋｽﾞｹ ｼﾞｺｸ ｴﾗ-		 */
#define	MRDMCANERR	0x1d000000	/* ﾃﾞﾝﾌﾞﾝ ｷｷｬｸ ｴﾗ-					 */
#define	MRDMCANALL	( MRDMCANERR | MRDALLMSG )
								/* ｶﾘ ｿｳｼﾝ ﾃﾞﾝﾌﾞﾝ ﾉ ｷｷｬｸ ｴﾗ-		 */
#define	MRDJREDERR	0x1e000000	/* ｼﾞｬ-ﾅﾙ ﾖﾐｺﾐ ｴﾗ-					 */
#define	MRDRBISZERR	0x1f000000	/* RBI ﾌｧｲﾙ ｻｲｽﾞ ｴﾗ-				 */
#define	MRDNODEQERR	0x20000000	/* ﾘｶﾊﾞﾘ ｶﾝﾚﾝ ﾃ-ﾌﾞﾙ ｶﾞ DEQ ｻﾚﾃ ｲﾅｲ	 */
#define	MRDNODEQTCT	( MRDNODEQERR | MRDTTCT )
								/* TTCT ﾃ-ﾌﾞﾙ ｶﾞ DEQ ｻﾚﾃ ｲﾅｲ		 */
#define	MRDNODEQTDT	( MRDNODEQERR | MRDTTDT )
								/* TTDT ﾃ-ﾌﾞﾙ ｶﾞ DEQ ｻﾚﾃ ｲﾅｲ		 */
#define	MRDTRANERR	0x21000000	/* ﾄﾗﾝｻﾞｸｼｮﾝ ﾓｰﾄﾞ ｶﾞ ﾌﾄｳ			 */
#define	MRDTOUTERR	0x22000000	/* ﾀｲﾑ ｱｳﾄ ｴﾗ-						 */
#define	MRDTIMERERR	0x23000000	/* ﾀｲﾏ- ｾｯﾃｲ ｴﾗ-					 */
#define	MRDJOPNERR	0x24000000	/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ｵ-ﾌﾟﾝ ｴﾗ-			 */
#define	MRDJCLSERR	0x25000000	/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ｸﾛ-ｽﾞ ｴﾗ-			 */
#define	MRDMSGINV	0x26000000	/* ｶﾝｹｲ ﾉ ﾅｲ ﾒｯｾｰｼﾞ ｶﾞ ｿｳｼﾝ ｻﾚﾀ		 */
#define	MRDRSNRCV	0x27000000	/* ﾎﾘｭｳ ﾌｧｲﾙ ｶﾞ ﾘｶﾊﾞﾘ ﾌﾖｳ ﾃﾞ ﾅｲ 	 */
#define	MRDRCVMSP	0x28000000	/* ﾒｯｾ-ｼﾞ ﾉ ﾌﾟ-ﾙﾊﾞｯﾌｧ ｼﾞｭｼﾝ ｼｯﾊﾟｲ	 */
#define	MRDEVENT 	0x29000000	/* ｲﾍﾞﾝﾄ ﾉ ﾂｳﾁ ｼｯﾊﾟｲ				 */
#define	MRDJDTERR 	0x2a000000	/* ｼﾞｬｰﾅﾙ ﾃﾞｰﾀ ｴﾗｰ  		   (L06) */
#define MRDSDATEERR 0x2b000000  /* SMP日付取得ｴﾗ-               TD92 */
#define	MRDTRANNG	0x2c000000	/* ﾄﾗﾝｻﾞｸｼｮﾝ矛盾				TD@1 */
#define	MRDNOMRH	0x2d000000	/* 故障管理ﾌﾟﾛｾｽ未存在			TD59 */
#define	MRDNOJNLERR	0x2f000000	/* 有効JNLが存在しない			TD67 */

#define	MRDPGMERR 	0x30000000	/* ﾌﾟﾛｸﾞﾗﾑ ﾛﾝﾘ ｴﾗｰ  		   (L04) */
#define	MRDFCLERR 	0x31000000	/* ﾌｧｲﾙ ﾉ ｲｯｶﾂ ｸﾛｰｽﾞ ｴﾗｰ 	   (L04) */
#define	MRDCANTUMT 	0x32000000	/* ﾎﾞﾘｭｳﾑ ﾍｲｿｸ ｴﾗｰ			   (L04) */
#define	MRDKJSZERR	0x33000000	/* KJﾌｧｲﾙｻｲｽﾞｴﾗｰ				TD42 */
#define	MRDRCVACERR	0x34000000  /* RCVﾌｧｲﾙｱｸｾｽｴﾗｰ			    TD83 */
#define	MRDRCVFERR	0x35000000  /* RCVﾌｧｲﾙ故障中			    TD83 */	
#define	MRDNOMRK	0x36000000  /* ｻﾌﾞ故障管理ﾌﾟﾛｾｽ未存在		TD02 */
#define	MRDSYNCERR	0x37000000  /* ﾒﾓﾘ無効化失敗				TD02 */
#define	MRDJCLRERR	0x38000000  /* ｼﾞｬｰﾅﾙｲﾝﾃﾞｯｸｽｸﾘｱｴﾗｰ			TD49 */

#define	MRDEHOTWAIT	0x3a000000	/* 自系がﾎｯﾄｽﾀﾝﾊﾞｲ予備系　　　(TD59) */
#define	MRDEJRFG	0x3b000000	/* ﾖﾋﾞﾀﾞｼ ﾌｶ ﾌﾗｸﾞ ｶﾞ 0 ﾃﾞﾅｲ			 */
#define	MRDERRPDEAD	0x3c000000	/* ｼｮｳｶﾞｲ ｱﾄｼｮﾘ ﾌﾟﾛｾｽ ｶﾞ "ｷﾄﾞｳﾁｭｳ",	 */
								/* "ｲﾁｼﾞﾃｲｼﾁｭｳ" ﾃﾞﾅｲ				 */
#define	MRDWAITEV	0x3d000000	/* イベント受信待ち失敗			TD00 */
#define	MRDSWAITV	0x3d000001	/* ｻﾌﾞ故障管理ﾌﾟﾛｾｽに対して	  (TD59) */
								/* ｲﾍﾞﾝﾄの待ちが出来なかった  (TD59) */
#define	MRDDESPRERR 0x3e000000	/* ｺ ﾌﾟﾛｾｽ ｼｭｳﾘｮｳ ｼｯﾊﾟｲ				 */
#define	MRDJNLSZERR	0x3f000000	/* ｼﾞｬｰﾅﾙ ﾌｧｲﾙ ｻｲｽﾞ ｴﾗ-				 */

/*********************************/
/*	2.ﾊﾟﾗﾒﾀ ｴﾗ- (0x40-0x4f)		 */
/*********************************/
#define MRDINVPVTNO 0x40000000	/* PVT ｴﾝﾄﾘ ﾊﾞﾝｺﾞｳ ﾌﾄｳ				 */
#define MRDINVVMTNO 0x41000000  /* VMT ｴﾝﾄﾘ番号不当			    TD90 */
#define MRDINVRBINO 0x42000000  /* RBI取得ﾌﾟﾛｾｽの起動ﾊﾟﾗﾒﾀｴﾗｰ   TD59 */
#define MRDINVBUFNO 0x43000000  /* ﾌﾟｰﾙﾊﾞｯﾌｧの種別指定ｴﾗｰ	    TD10 */
#define MRDINVPVTN2 0x44000000	/* PVTｴﾝﾄﾘ番号2不当			    TD61 */
#define MRDINVPBTNO 0x45000000	/* PBTｴﾝﾄﾘ番号不当				TD61 */
#define MRDINVSCHID 0x46000000	/* 装置ID不当					TD61 */
#define MRDINVTYPE  0x47000000	/* 依頼区分不当					TD61 */
#define MRDINVCOPY  0x48000000	/* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽ起動ﾊﾟﾗﾒﾀ不当	TD49 */
#define MRDINVBKUP  0x49000000	/* ﾊﾞｯｸｱｯﾌﾟﾌﾟﾛｾｽ起動ﾊﾟﾗﾒﾀ不当	TD49 */
#define MRDJNL2ERR  0x4a000000	/* 物理ﾎﾞﾘｭｰﾑ識別名不当(JNL) ST4031  */
#define MRDKJ2ERR   0x4b000000	/* 物理ﾎﾞﾘｭｰﾑ識別名不当(KJ)  ST4031  */
#define MRDRBI2ERR  0x4c000000	/* 物理ﾎﾞﾘｭｰﾑ識別名不当(RBI) ST4031  */


/*********************************/
/*	3.ｼｶｸ ﾄﾞｳｷ ｴﾗ- (0x80-0x9F)	 */
/*********************************/
/*-------------------------------*/
/*  3.1.資源占有エラー           */
/*-------------------------------*/
#define	MRDENQERR	0x80000000	/* ｼｹﾞﾝ ｾﾝﾕｳ ｴﾗ-					 */
#define	MRDENQTCT	( MRDENQERR | MRDTTCT )
								/* TTCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */


#define	MRDENQJCT	( MRDENQERR | MRDTJCT )
								/* TJCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQBKT	( MRDENQERR | MRDTBKT )
								/* TBKT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQRCT	( MRDENQERR | MRDTRCT )
								/* TRCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQTDT	( MRDENQERR | MRDTTDT )
								/* TTDT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQRBT	( MRDENQERR | MRDTRBT )
								/* TRBT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQFMT	( MRDENQERR | MRDTFMT )
								/* TFMT ﾃｰﾌﾞﾙ ｾﾝﾕｳ ｴﾗｰ			TD49 */
#define	MRDENQSST	( MRDENQERR | MRDTSST )
								/* TSST ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQPVT	( MRDENQERR | MRDTPVT )
								/* TPVT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */
#define	MRDENQVBT	( MRDENQERR | MRDTVBT )
								/* TVBT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */

#define	MRDENQVMT	( MRDENQERR | MRDTVMT )
								/* TVMTﾃ-ﾌﾞﾙ占有ｴﾗ-			    TD44 */

#define	MRDENQWMT	( MRDENQERR | MRDTWMT )
								/* TWMT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｴﾗ-				 */

/*-------------------------------*/
/*  3.2.資源占有解除エラー       */
/*-------------------------------*/
#define	MRDDEQERR	0x81000000	/* ｼｹﾞﾝ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-				 */
#define	MRDDEQTCT	( MRDDEQERR | MRDTTCT )
								/* TTCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define MRDDEQSUR   ( MRDDEQERR | MRDTSUR )
								/* TSUR ﾃ-ﾌﾞﾙ占有解除ｴﾗ-        TD61 */
#define	MRDDEQJCT	( MRDDEQERR | MRDTJCT )
								/* TJCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQBKT	( MRDDEQERR | MRDTBKT )
								/* TBKT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQRCT	( MRDDEQERR | MRDTRCT )
								/* TRCT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQTDT	( MRDDEQERR | MRDTTDT )
								/* TTDT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQRBT	( MRDDEQERR | MRDTRBT )
								/* TRBT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQSST	( MRDDEQERR | MRDTSST )
								/* TSST ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define	MRDDEQVBT	( MRDDEQERR | MRDTVBT )
								/* TVBT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */

#define MRDDEQVMT   ( MRDDEQERR | MRDTVMT )
								/* TVMTﾃ-ﾌﾞﾙ占有解除ｴﾗ-         TD90 */
#define MRDDEQPVT   ( MRDDEQERR | MRDTPVT )
								/* TPVTﾃ-ﾌﾞﾙ占有解除ｴﾗ-         TD90 */

#define	MRDDEQWMT	( MRDDEQERR | MRDTWMT )
								/* TWMT ﾃ-ﾌﾞﾙ ｾﾝﾕｳ ｶｲｼﾞｮ ｴﾗ-		 */
#define MRDDEQSBR   ( MRDDEQERR | MRDTSBR )
								/* TSBR ﾃ-ﾌﾞﾙ占有解除ｴﾗ-        TD61 */

/*-------------------------------*/
/*  3.3.その他資格同期エラー     */
/*-------------------------------*/
#define	MRDJSYNERR	0x82000000	/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ﾄﾞｳｷ ｱﾜｾ ｴﾗ-			 */
#define	MRDMSCALL 	0x83000000	/* ﾏｽﾀｽｹｼﾞｭｳﾗ ｶﾗﾉ ﾖﾋﾞﾀﾞｼ ﾃﾞｱﾙ		 */
#define	MRDSMSCALL	0x83000001	/* ｻﾌﾞMSからの呼出である        TD59 */
#define	MRDACCFRERR 0x84000000	/* ACC ｾﾝﾕｳ ｶｲｼﾞｮ ｼｯﾊﾟｲ				 */
#define	MRDDESACERR 0x85000000	/* ｱｸｾｽｹﾝ ｶﾞ ﾅｲ				   (L04) */
#define	MRDDESPVERR 0x86000000	/* ﾀ PU ﾍﾉ ﾌﾟﾛｾｽ ｻｸｼﾞｮｹﾝ ｶﾞ ﾅｲ (L04) */
#define	MRDPUSYNERR	0x87000000	/* PU間同期エラー			  (TD59) */

#define	MRDNORCV	0x89000000	/* ﾘｶﾊﾞﾘ不要時の起動である		TD49 */
#define	MRDTYPERR	0x8a000000	/* 装置種別が不当				TD49 */
#define	MRDNOBKUP	0x8b000000  /* ﾊﾞｯｸｱｯﾌﾟ不要ｼｽﾃﾑでの起動		TD49 */
#define	MRDNOSTART	0x8c000000  /* ﾊﾞｯｸｱｯﾌﾟ不能					TD49 */

/*********************************/
/*	4.ﾊ-ﾄﾞ ｴﾗ- (0xA0-0xCF)		 */
/*********************************/
#define	MRDJNLWERR	0xa0000000	/* ｼﾞｬ-ﾅﾙ ﾌｧｲﾙ ﾆｼﾞｭｳ ｼｮｳｶﾞｲ			 */
#define	MRDRBIWERR	0xa1000000	/* RBI ﾌｧｲﾙ ﾆｼﾞｭｳ ｼｮｳｶﾞｲ			 */
#define	MRDAPFILERR	0xa2000000	/* AP ﾌｧｲﾙ ｼｮｳｶﾞｲ					 */
#define MRDCFIOERR	0xa3000000	/* ﾌｧｲﾙI/Oｴﾗｰ					TD49 */
#define MRDCFMIOERR	0xa3000001	/* ｺﾋﾟｰ元ﾌｧｲﾙI/Oｴﾗｰ				TD49 */
#define MRDCFSIOERR	0xa3000002	/* ｺﾋﾟｰ先ﾌｧｲﾙI/Oｴﾗｰ				TD49 */
#define MRDCFOTERR	0xa4000000	/* ﾌｧｲﾙその他のｴﾗｰ				TD49 */
#define MRDCFDERR	0xa5000000	/* ﾌｧｲﾙ2重故障					TD49 */
#define MRDCVMIOERR	0xa6000000	/* ｺﾋﾟｰ元ﾎﾞﾘｭｰﾑI/Oｴﾗｰ			TD49 */
#define MRDCVSIOERR	0xa7000000	/* ｺﾋﾟｰ先ﾎﾞﾘｭｰﾑI/Oｴﾗｰ			TD49 */
#define MRDJNLBKERR	0xa8000000	/* ｼﾞｬｰﾅﾙﾊﾞｯｸｱｯﾌﾟ失敗			TD49 */
#define MRDJNKBKERR	0xa9000000	/* JNL･KJ共にﾊﾞｯｸｱｯﾌﾟ失敗		TD49 */
#define	MRDMCONERR	0xaa000000	/* ﾐﾗ-特殊ﾌｱｲﾙｺﾈｸﾄ失敗			TD22 */
#define	MRDMOPNERR	0xab000000	/* ﾐﾗ-特殊ﾌｱｲﾙｵ-ﾌﾟﾝ失敗			TD22 */
#define	MRDMCLSERR	0xac000000	/* ﾐﾗ-特殊ﾌｱｲﾙｸﾛ-ｽﾞ失敗			TD22 */
#define	MRDMDCNERR	0xad000000	/* ﾐﾗ-特殊ﾌｱｲﾙﾃﾞｲｽｺﾈｸﾄ失敗		TD22 */
								/*				CT1039				 */
#define	MRDBCONERR	0xae000000	/*	ﾊﾞｽ特殊ﾌｧｲﾙｺﾈｸﾄ失敗				*/
#define	MRDECONERR	0xaf000000	/*	装置特殊ﾌｧｲﾙｺﾈｸﾄ失敗			*/
#define	MRDBDCNERR	0xb0000000	/*	ﾊﾞｽ特殊ﾌｧｲﾙﾃﾞｨｽｺﾈｸﾄｴﾗｰ			*/
#define	MRDEDCNERR	0xb1000000	/*	装置特殊ﾌｧｲﾙﾃﾞｨｽｺﾈｸﾄｴﾗｰ			*/
#define	MRDBRSTERR	0xb2000000	/*	ﾊﾞｽﾘｾｯﾄｴﾗｰ						*/
#define	MRDERSTERR	0xb3000000	/*	装置ﾘｾｯﾄｴﾗｰ						*/
#define	MRDBHCKERR	0xb4000000	/*	ﾊﾞｽﾍﾙｽﾁｪｯｸｴﾗｰ					*/
#define	MRDEHCKERR	0xb5000000	/*	装置ﾍﾙｽﾁｪｯｸｴﾗｰ					*/
#define	MRDBOPNERR	0xb6000000	/*	ﾊﾞｽ特殊ﾌｧｲﾙｵｰﾌﾟﾝ失敗			*/
#define	MRDEOPNERR	0xb7000000	/*	装置特殊ﾌｧｲﾙｵｰﾌﾟﾝ失敗			*/
#define	MRDBCLSERR	0xb8000000	/*	ﾊﾞｽ特殊ﾌｧｲﾙｸﾛｰｽﾞ失敗			*/
#define	MRDECLSERR	0xb9000000	/*	装置特殊ﾌｧｲﾙｸﾛｰｽﾞ失敗			*/

/*********************************/
/*	5.ｼｹﾞﾝ ﾌﾞｿｸ ｴﾗ- (0xD0-0xDF)	 */
/*********************************/
#define	MRDGBUFERR	0xd0000000	/* ﾌﾟ-ﾙ ﾊﾞｯﾌｧ ｶｸﾎ ｴﾗ-				 */
#define	MRDNBUFERR	0xd1000000	/* ﾒﾓﾘ不足						TD49 */

/*********************************/
/*	6.ｿﾉﾀ ﾉ ｴﾗ- (0xE0-0xFF)		 */
/*********************************/
#define	MRDPABTERR	0xe0000000	/* ﾚｲｶﾞｲ ﾊｯｾｲ ｶｲｽｳ ｶﾞ ｷｮﾖｳﾁ ｦ ｺｴﾀ	 */
#define	MRDMNTERR 	0xe1000000	/* ﾏｳﾝﾄ ｼｯﾊﾟｲ                        */
#define	MRDUMTERR 	0xe2000000	/* ｱﾝ ﾏｳﾝﾄ ｼｯﾊﾟｲ                     */
#define	MRDJSPERR 	0xe3000000	/* ﾎﾟｼﾞｼｮﾆﾝｸﾞ ｼｯﾊﾟｲ                  */
#define	MRDVUMTERR 	0xe4000000	/* ｱﾝ ﾏｳﾝﾄ ｼｯﾊﾟｲ(VMT)				 */
#define	MRDEJQERR 	0xe5000000	/* ｼｮｳｶﾞｲ ﾂｳﾁ ｿｳｼﾝ ｼｯﾊﾟｲ			 */
#define	MRDFSRCVERR	0xe6000000	/* mr_srcv ﾉ ﾍﾝｷｬｸﾁ ｶﾞ ﾉｰﾏﾙ ｲｶﾞｲ(L02)*/
#define	MRDNOEXPU0	0xe7000000	/* SRCV ｶﾞ PU0 ﾃﾞ ｷﾄﾞｳ ｻﾚﾃ ｲﾅｲ (L02) */
#define	MRDCRPRERR	0xe8000000	/* ﾌﾟﾛｾｽ ｾｲｾｲ ｼｯﾊﾟｲ					 */
#define	MRDEXCMERR	0xe9000000	/* ｺﾏﾝﾄﾞ ｼﾞｯｺｳ ｼｯﾊﾟｲ				 */
#define	MRDCHLDERR	0xea000000	/* ｺ ﾌﾟﾛｾｽ ｲｼﾞｮｳ ｼｭｳﾘｮｳ				 */
#define	MRDCONFOERR	0xeb000000	/* ｿｳﾁ ﾍｲｿｸ ｼｯﾊﾟｲ			   (L11) */
#define	MRDCONFIERR	0xec000000	/* ｿｳﾁ ｸﾐｺﾐ ｼｯﾊﾟｲ			   (L11) */
#define MRDFLZFILE	0xed000000	/* ﾌﾘｰｽﾞﾌｧｲﾙ取得			  (TD91) */
#define	MRDCVMNTE	0xee000000	/* ｺﾋﾟｰ先ﾎﾞﾘｭｰﾑがﾏｳﾝﾄ中である	TD49 */
#define	MRDLVOLSERR	0xef000000	/* 論理ｾｸﾀ長 or ﾎﾞﾘｭｰﾑｻｲｽﾞ不当	TD49 */

#define	MRDSEQERR	0xf0000000	/* ﾄﾗﾝｻﾞｸｼｮﾝ ﾘﾖｳｼｬ ｼｰｹﾝｽ ｴﾗｰ   (L07) */
#define	MRDINVECD	0xf1000000	/* ｺ ﾌﾟﾛｾｽ ﾉ ｼｭｳﾘｮｳ	ｺｰﾄﾞ ｶﾞ ﾌﾄｳ(L09) */
#define	MRDPCTOVER	0xf2000000	/* ﾌﾟﾛｾｽ ﾊﾞﾝｺﾞｳ ｶﾞ 256 ｲｼﾞｮｳ   (L15) */
#define MRDSDOFERR	0xf3000000	/* ＳＭＰ日付がｵｰﾊﾞｰﾌﾛｰした	  (TD92) */

#define	MRDCLGERR	0xf5000000	/* Cﾛｸﾞｴﾗｰ					  (TD50) */
#define	MRDREADERR	0xf6000000	/* 読み込みｴﾗｰ					TD49 */

#define	MRDWRITERR	0xf8000000	/* 書き込みｴﾗｰ					TD49 */
#define	MRDSPMERR	0xf9000000  /* ﾐﾗ-ﾘﾝｸﾞ制御ｴﾗ-				TD22 */
#define	MRDSYSCERR	0xfa000000  /* TRADEｼｽﾃﾑｺｰﾙｴﾗｰ				TD49 */
#define	MRDKJBKERR	0xfb000000  /* 勘定照合ﾌｧｲﾙﾊﾞｯｸｱｯﾌﾟ失敗     TD49 */
#define	MRDVESNERR	0xfc000000  /* 故障通知電文送信失敗		    TD49 */
#define	MRDCPSTOP	0xfd000000  /* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽ強制終了		TD49 */
#define	MRDCPYERR	0xfe000000  /* ﾎﾞﾘｭｰﾑｺﾋﾟｰﾌﾟﾛｾｽその他ｴﾗｰ     TD49 */
#define	MRDUMTFERR	0xff000000  /* 強制ｱﾝﾏｳﾝﾄ失敗   		  CT1213 */
