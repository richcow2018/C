/****************************************************************************/
/*																			*/
/*	動的システム変更提供サービスコール用									*/
/*																			*/
/*	作成:94/09/16															*/
/*	更新:																	*/
/*		95.06.24 K.Kubota ST2707: 対ICPﾌﾟﾛｾｽ協調動作						*/
/*		95.06.27 K.Kubota ST2706: 対EDP/DCP協調動作							*/
/*		95.07.10 K.Kubota ST2910: activate CheckList						*/
/*		95.07.14 K.Kubota SSCY0073: TNTC対応								*/
/*	95.08.28 K.Kubota SSCY0100: tfacrxtn対応								*/
/*	95.08.29 K.Kubota SSCY0095: TFAX分割ﾃﾞｰﾀ長対応							*/
/*	95.09.06 K.Kubota SSCY0061: raw mode for mm_diff,						*/
/*								all delete mode for mm_dyrc()				*/
/*	95.09.19 K.Kubota ST3309=AT1084: tel/ISDNno	[10]-->[16]					*/
/*	95.10.06 K.Kubota SSCY0118: 対OSP協調動作								*/
/*	95.12.13 K.Kubota ST3865: add MMELSW									*/
/*	95.12.19 K.Kubota ST3859=AT2081; retry ossenms()						*/
/*	96.02.29 K.Kubota ST4050; 正規化データ.ホスト論理回線.lnnoを予備とする	*/
/*	96.03.28 K.Kubota SSCY0153: for BTURIREC rep yobi2_2 to apno			*/
/*	96.04.04 K.Kubota SSCY0157: mm_rvrs send request to mme000 on alter ACE	*/
/*	96.05.26 K.Kubota ST4384: on mme's abort, tell MMEPABT to AP			*/
/*	98.11.30 K.Yamagu SPCY0134: mm_rvdf新規サービスコール関連定義を追加		*/
/*	03.03.06 サプライ：岩下 MD001: Linux移植に伴う修正						*/
/*							端末論理回線レコードに論理回線グループ番号追加	*/
/*							ノード間通信パスレコードにNSコンテキスト番号追加*/
/*	03.08.08 サプライ：中村 TBCS0265:障害対応								*/
/*							新規モジュールＩＤ追加							*/
/****************************************************************************/

										/* ###ST2707 start					*/
/********************************/
/* 機能ﾕﾆｯﾄID					*/
/********************************/
#define MMMODULE1		0x01			/* 実行管理: mmd_2000()				*/

/********************************/
/* ﾓｼﾞｭｰﾙID [MMD]				*/
/********************************/
#define MM_DYRC			0x79FFDF00
#define MMD_0GEN		0x79FFD001
#define MMD_IRBI		0x79FFD002
#define MMD_SC00		0x79FFD003
#define MMD_SC10		0x79FFD004
#define MMD_0000		0x79FFD000
#define MMD_0700		0x79FFD070
#define MMD_2000		0x79FFD200
#define MMD_2100		0x79FFD210
#define MMD_2200		0x79FFD220
#define MMD_2210		0x79FFD221
#define MMD_2300		0x79FFD230
#define MMD_2400		0x79FFD240
#define MMD_2500		0x79FFD250
#define MMD_3000		0x79FFD300
#define MMD_3100		0x79FFD310
#define MMD_3200		0x79FFD320
#define MMD_3300		0x79FFD330
#define MMD_3400		0x79FFD340
#define MMD_3500		0x79FFD350
#define MMD_3600		0x79FFD360
#define MMD_3700		0x79FFD370
#define MMD_3800		0x79FFD380
#define MMD_3900		0x79FFD390
#define MMD_3A00		0x79FFD3A0
#define MMD_4000		0x79FFD400
#define MMD_4100		0x79FFD410
#define MMD_41A0		0x79FFD41A
#define MMD_41U0		0x79FFD41B
#define MMD_41D0		0x79FFD41D
#define MMD_4200		0x79FFD420
#define MMD_42A0		0x79FFD42A
#define MMD_42U0		0x79FFD42B
#define MMD_42D0		0x79FFD42D
#define MMD_4300		0x79FFD430
#define MMD_43A0		0x79FFD43A
#define MMD_43U0		0x79FFD43B
#define MMD_43D0		0x79FFD43D
#define MMD_4400		0x79FFD440
#define MMD_44A0		0x79FFD44A
#define MMD_44U0		0x79FFD44B
#define MMD_44D0		0x79FFD44D
#define MMD_4700		0x79FFD470
#define MMD_47A0		0x79FFD47A
#define MMD_47U0		0x79FFD47B
#define MMD_47D0		0x79FFD47D
#define MMD_4800		0x79FFD480
#define MMD_48A0		0x79FFD48A
#define MMD_48U0		0x79FFD48B
#define MMD_48D0		0x79FFD48D
#define MMD_4900		0x79FFD490
#define MMD_49A0		0x79FFD49A
#define MMD_49U0		0x79FFD49B
#define MMD_49D0		0x79FFD49D
#define MMD_4A00		0x79FFD4A0
#define MMD_4AA0		0x79FFD4AA
#define MMD_4AU0		0x79FFD4AB
#define MMD_4AD0		0x79FFD4AD
#define MMD_5000		0x79FFD500
#define MMD_5100		0x79FFD510
#define MMD_51A0		0x79FFD51A
#define MMD_51U0		0x79FFD51B
#define MMD_51D0		0x79FFD51D
#define MMD_6000		0x79FFD600
#define MMD_6100		0x79FFD610
#define MMD_61A0		0x79FFD61A
#define MMD_61U0		0x79FFD61B
#define MMD_61D0		0x79FFD61D
#define MMD_7000		0x79FFD700
#define MMD_7110		0x79FFD711
#define MMD_7120		0x79FFD712
#define MMD_7130		0x79FFD713
#define MMD_7140		0x79FFD714
#define MMD_7150		0x79FFD715
#define MMD_7210		0x79FFD721
#define MMD_7220		0x79FFD722
#define MMD_7230		0x79FFD723
#define MMD_7240		0x79FFD724
#define MMD_7250		0x79FFD725
#define MMD_7310		0x79FFD731
#define MMD_7320		0x79FFD732
#define MMD_7330		0x79FFD733			/* ###SSCY0095				*/
#define MMD_7340		0x79FFD734
#define MMD_7350		0x79FFD735
#define MMD_7410		0x79FFD741
#define MMD_7420		0x79FFD742
#define MMD_7430		0x79FFD743
#define MMD_7440		0x79FFD744
#define MMD_7450		0x79FFD745
#define MMD_7510		0x79FFD751
#define MMD_7520		0x79FFD752
#define MMD_7540		0x79FFD754
#define MMD_7550		0x79FFD755
#define MMD_75F0		0x79FFD75F
#define MMD_7610		0x79FFD761
#define MMD_7620		0x79FFD762
#define MMD_7630		0x79FFD763
#define MMD_7640		0x79FFD764
#define MMD_7650		0x79FFD765
#define MMD_7710		0x79FFD771
#define MMD_7720		0x79FFD772
#define MMD_7730		0x79FFD773
#define MMD_7740		0x79FFD774
#define MMD_7750		0x79FFD775
#define MMD_7810		0x79FFD781
#define MMD_7820		0x79FFD782
#define MMD_7840		0x79FFD784
#define MMD_7850		0x79FFD785
#define MMD_7910		0x79FFD791
#define MMD_7920		0x79FFD792
#define MMD_7930		0x79FFD793
#define MMD_7940		0x79FFD794
#define MMD_7950		0x79FFD795
#define MMD_7A10		0x79FFD7A1
#define MMD_7A20		0x79FFD7A2
#define MMD_7A30		0x79FFD7A3
#define MMD_7A40		0x79FFD7A4
#define MMD_7A50		0x79FFD7A5
#define MMD_7B10		0x79FFD7B1
#define MMD_7B20		0x79FFD7B2
#define MMD_7B30		0x79FFD7B3
#define MMD_7B40		0x79FFD7B4
#define MMD_7B50		0x79FFD7B5
#define MMD_7C10		0x79FFD7C1		/* ###SSCY0073 start				*/
#define MMD_7C20		0x79FFD7C2
#define MMD_7C30		0x79FFD7C3
#define MMD_7C40		0x79FFD7C4
#define MMD_7C50		0x79FFD7C5		/* ###SSCY0073 end					*/
#define MMD_8000		0x79FFD800
#define MMD_8110		0x79FFD811
#define MMD_8120		0x79FFD812
#define MMD_8140		0x79FFD814
#define MMD_8150		0x79FFD815
#define MMD_8210		0x79FFD821
#define MMD_8220		0x79FFD822
#define MMD_8230		0x79FFD823
#define MMD_8240		0x79FFD824
#define MMD_8250		0x79FFD825
#define MMD_8310		0x79FFD831
#define MMD_8320		0x79FFD832
#define MMD_8330		0x79FFD833
#define MMD_8340		0x79FFD834
#define MMD_8350		0x79FFD835
#define MMD_8910		0x79FFD891
#define MMD_8A10		0x79FFD8A1		/* ###SSCY0100						*/
#define MMD_9100		0x79FFD910
#define MMD_9200		0x79FFD920
#define MMD_9310		0x79FFD931
#define MMD_9400		0x79FFD940
#define MMD_9600		0x79FFD960
#define MMD_9700		0x79FFD970
#define MMD_9800		0x79FFD980
#define MMD_9999		0x79FFD999
#define MMD_7E10		0x79FFD7e1
#define MMD_7E20		0x79FFD7e2
#define MMD_7E30		0x79FFD7e3
#define MMD_7E40		0x79FFD7e4
#define MMD_7D10		0x79FFD7d1		/* TBCS0265							*/
#define MMD_7D12		0x79FFD7d2		/* TBCS0265							*/

/*********************************/
/*	モジュールＩＤ（共通機能）	 */
/*********************************/
#define MMD_Y200		0x79FFC200
#define MMD_Y210		0x79FFC210
#define MMD_Y500		0x79FFC500
#define MMD_Y911		0x79FFC911
#define MMD_Y912		0x79FFC912
#define MMD_Y913		0x79FFC913
#define MMD_Y914		0x79FFC914
#define MMD_Y915		0x79FFC915
#define MMD_Y916		0x79FFC916
#define MMD_Y917		0x79FFC917
#define MMD_Y918		0x79FFC918

/********************************/
/* MKｺｰﾄﾞ						*/
/********************************/
#define MMMK_CODE		0x030E0000		/* mm_dyrc <---> mmd/mme			*/

/********************************/
/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ					*/
/********************************/
#define MMIFRVRS		0x79A10002		/* mm_rvrs <---> mme				*/
#define MMIFTBL1		0x79A00001		/* ﾃｰﾌﾞﾙ更新依頼通知				*/
#define MMIFTBL2		0x79A00002		/* ﾃｰﾌﾞﾙ更新完了通知				*/
#define MMIFSPU1		0x79A00011		/* 他LMﾃｰﾌﾞﾙ更新依頼通知(PU1.mmd)	*/
#define MMIFRPU1		0x79A00012		/* 他LMﾃｰﾌﾞﾙ更新完了通知(PU1.mmd)	*/

/********************************/
/* ﾌﾟﾛｸﾞﾗﾑ種別					*/
/********************************/
#define DYRCTYP			"F3"			/* 動的ｼｽﾃﾑ構成変更ﾌﾟﾛｾｽ			*/
#define RVRSTYP			"F4"			/* 逆正規化ﾃﾞｰﾀ作成ﾌﾟﾛｾｽ			*/

/********************************/
/* ｱﾎﾞｰﾄ要因					*/
/********************************/
#define MMABTLGC		0x01000000		/* 論理エラー						*/
#define MMABTPRM		0x04000000		/* パラメータエラー					*/
#define MMABTT_O		0x08000000		/* 資格・同期エラー					*/
#define MMABTHRD		0x0A000000		/* ハードエラー						*/
#define MMABTMEM		0x0D000000		/* 資源不足エラー					*/
#define MMABTETC		0x0E000000		/* その他							*/

/********************************/
/* 応答監視ﾀｲﾏ [単位: ﾐﾘ秒]		*/
/********************************/
#ifndef MMEWAITTIME
#define MMEWAITTIME		200000			/* OSRCVMSPの待ち時間(単位ms)		*/
										/*   0: No Wait						*/
#endif
#ifndef MMDWAITTIME
										/* ###SSCY0061 below				*/
#define MMDWAITTIME		1200000L		/* OSRCVMSPの待ち時間(単位ms)		*/
										/*   0: No Wait						*/
										/*  -1: 無制限待ち					*/
		/* 予備系動的テーブル変更時のみ有効。現用系は無条件で無制限待ち。	*/
										/* ###SSCY0061 above				*/
#endif
										/* ###ST3859 start					*/
/************************************/
/* 予備系送信再試行ﾀｲﾏ [単位: 秒]	*/
/************************************/
#ifndef MMDRTIME
#define MMDRTIME		10				/* osdelay()のﾕﾆｯﾄ数				*/
#endif
#ifndef MMDRUNIT
#define MMDRUNIT		2				/* osdelay()のﾕﾆｯﾄ単位 [秒]			*/
#endif
#ifndef MMDRCNT
#define MMDRCNT			10				/* 再試行回数						*/
#endif
										/* ###ST3859 end					*/
										/* ###SSCY0157 start				*/
#ifndef MMERTIME
#define MMERTIME		10				/* osdelay()のﾕﾆｯﾄ数				*/
#endif
#ifndef MMERUNIT
#define MMERUNIT		2				/* osdelay()のﾕﾆｯﾄ単位 [秒]			*/
#endif
#ifndef MMERCNT
#define MMERCNT			10				/* 再試行回数						*/
#endif
										/* ###SSCY0157 end					*/
/********************************/
/* 返却値						*/
/********************************/
/* 共通							*/
#define MMNORMAL		0L				/* 正常終了							*/
#define MMNOMEM			-81L			/* ﾒﾓﾘ(ﾌﾟｰﾙﾊﾞｯﾌｧ)不足				*/
#define MMEOSERR		-82L			/* TRADEｼｽﾃﾑｺｰﾙｴﾗｰ					*/
#define MMTIMEOT		-83L			/* 応答監視時間切れ					*/
#define MMFLNO			-84L			/* ﾊﾟｽ名1なし						*/
#define MMFLNULL		-85L			/* ﾊﾟｽ名1文字列過長					*/
#define MMLGNO			-86L			/* ﾊﾟｽ名2なし						*/
#define MMLGNULL		-87L			/* ﾊﾟｽ名1文字列過長					*/

/* 正規化						*/
#define MMEERCARD		-1L				/* ｶｰﾄﾞ情報ﾌｧｲﾙ名異常				*/
#define MMEERREGU		-2L				/* 正規化ﾃﾞｰﾀﾌｧｲﾙ名異常				*/
#define MMEERLIST		-3L				/* ｶｰﾄﾞ情報ﾁｪｯｸﾘｽﾄﾌｧｲﾙ名異常		*/
#define MMEERREAD		-4L				/* ｶｰﾄﾞ情報ﾌｧｲﾙ入力ｴﾗｰ				*/
#define MMEERWRIT		-5L				/* 正規化ﾃﾞｰﾀﾌｧｲﾙ未作成				*/
#define MMENOLIST		-6L				/* ｶｰﾄﾞ情報ﾁｪｯｸﾘｽﾄﾌｧｲﾙ未作成		*/
#define MMENOMEM		-7L				/* ﾒﾓﾘ不足							*/
#define MMENMKPRC		-8L				/* ﾌﾟﾛｾｽ識別名作成異常				*/
#define MMEERRCRD		-11L			/* ｶｰﾄﾞ情報異常 ###ST2910			*/

/* 逆正規化						*/
#define MMEERRVRS		-1L				/* 逆正規化ﾃﾞｰﾀﾌｧｲﾙ名異常			*/
#define MMENORVRS		-2L				/* 逆正規化ﾃﾞｰﾀﾌｧｲﾙ未作成			*/
#define MMENOPRNM		-3L				/* 逆正規化ﾌﾟﾛｾｽがTPCTに未登録		*/
										/* ###SSCY0157 above				*/
#define MMETBLERR		-4L				/* SMPﾃｰﾌﾞﾙ論理ｴﾗｰ					*/
										/* ###SSCY0157 start				*/
#define MMENODENM		-5L				/* 現用／予備系区分不当				*/
#define MMEENVDAT		-7L				/* 予備系装置番号取得失敗			*/
										/* ###SSCY0157 end					*/
#define MMELSW			-51L			/* BU回線使用中 ###ST3865			*/
#define MMEPABT			-101L			/* MMEプロセスがアボートした		*/
										/* ###ST4384 above					*/

/* 差分抽出						*/
#define MMEDWORN		-1L				/* 条件付き正常終了					*/
#define MMEDERREGU		-2L				/* 正規化ﾃﾞｰﾀﾌｧｲﾙ名異常				*/
#define MMEDERRVRS		-3L				/* 逆正規化ﾃﾞｰﾀﾌｧｲﾙ名異常			*/
#define MMEDERDIFF		-4L				/* 正規化ﾃﾞｰﾀ(差分)ﾌｧｲﾙ名異常		*/
#define MMEDERRGRD		-5L				/* 正規化ﾃﾞｰﾀﾌｧｲﾙ入力ｴﾗｰ			*/
#define MMEDERRVRD		-6L				/* 逆正規化ﾃﾞｰﾀﾌｧｲﾙ入力ｴﾗｰ			*/
#define MMEDERWRIT		-7L				/* 正規化ﾃﾞｰﾀ(差分)ﾌｧｲﾙ出力ｴﾗｰ		*/
#define MMEDERPROC		-8L				/* 差分ありIOﾌﾟﾛｾｽ構造体領域不足	*/
#define MMEDNOMEM		-9L				/* ﾒﾓﾘ不足							*/
#define MMEDERNODE		-10L			/* ﾉｰﾄﾞ間通信ﾊﾟｽ差分情報返却域不足	*/
#define MMEJINODE		-11L			/* 自ﾉｰﾄﾞ変更不可 ###SSCY0073		*/
#define MMDIMDERR		-12L			/* mode error ###SSCY0061			*/
#define MMEDERTBL		-13L			/* SMPメモリテーブル異常	SPCY0134*/
#define MMEDERNREC		-14L			/* 正規化レコードに該当なし	SPCY0134*/
#define MMEDERBKUP		-15L			/* バックアップ先情報域不正 SPCY0134*/
#define MMEDERFNA		-16L			/* ホスト接続先情報域不正 	SPCY0134*/
#define MMEDERFTAM		-17L			/* FTAM通信相手先情報域不正 SPCY0134*/

/* テーブル変更					*/
#define MMDNODENM		-1L				/* 現用／予備系区分不当				*/
#define MMDNOPRNM		-2L				/* 動的ｼｽﾃﾑ変更ﾌﾟﾛｾｽがTPCTに未登録	*/
#define MMDENVDAT		-3L				/* 予備系装置番号取得失敗			*/
#define MMDEXECUT		-4L				/* ｼｽﾃﾑ構成変更中					*/
#define MMDUDERR		-5L				/* 排他区間設定失敗					*/
#define MMDYMDERR		-6L				/* mode error ###SSCY0061			*/
#define MMDRECKBN		-19L			/* 認識不能ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ			*/
#define MMDBUTSURI		-20L			/* 物理回線ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ			*/
#define MMDGWRONRI		-21L			/* GW端末論理回線ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ	*/
#define MMDLANRNRI		-22L			/* LAN端末論理回線ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ	*/
#define MMDTANPASS		-23L			/* 端末ﾊﾟｽﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ			*/
#define MMDHOSTRON		-24L			/* ﾎｽﾄ論理回線ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ		*/
#define MMDHOSTPAS		-25L			/* ﾎｽﾄﾊﾟｽ(FNA)ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ		*/
#define MMDPROCESS		-26L			/* ﾌﾟﾛｾｽﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ			*/
#define MMDRENKETU		-27L			/* ﾌﾟﾛｾｽ連結ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ		*/
#define MMNODEPORT		-28L			/* ﾉｰﾄﾞ間通信ﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ		*/
#define MMFTAMPATH		-29L			/* FTAM通信ﾊﾟｽﾚｺｰﾄﾞﾃﾞｰﾀﾁｪｯｸｴﾗｰ		*/


/****************************************/
/* ﾃｰﾌﾞﾙ変更依頼電文[mm_dyrc ---> mmd]	*/
/****************************************/
/* MIA利用者域				*/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
	long				reqid;			/* 要求識別子						*/
	long				pid;			/* 要求電文発行ﾌﾟﾛｾｽ識別子			*/
	long				mbox0;			/* pu0ﾒｰﾙﾎﾞｯｸｽ識別子				*/
	long				mbox1;			/* pu1ﾒｰﾙﾎﾞｯｸｽ識別子				*/
	char				prname[8];		/* pu1ﾌﾟﾛｾｽ識別名					*/
	long				code;			/* 完了ｺｰﾄﾞ							*/
	long				faildet;		/* 異常詳細							*/
	char				filename[64];	/* 正規化ﾃﾞｰﾀ(差分)ﾌｧｲﾙ名			*/
	char				logfile[64];	/* ﾃｰﾌﾞﾙ更新情報ﾛｸﾞﾌｧｲﾙ名			*/
										/* ###SSCY0061 start				*/
	char				Node;			/* 系区分							*/
										/*  0x01...現用系					*/
										/*  0x02...予備系					*/
	char				Mode;			/* 処理ﾓｰﾄﾞ							*/
										/*  0x00...通常ﾓｰﾄﾞ					*/
										/*  0x01...全撤去ﾓｰﾄﾞ				*/
	/* 異常時解析用付加情報(^_^;)		   ###SSCY0118 start				*/
	short				ErrRecN;		/* 異常正規化ﾚｺｰﾄﾞ通番				*/
	char				XBpnm[8];		/* 排他区間設定失敗ﾌﾟﾛｾｽ識別名		*/
	long				FailCode;		/* 排他区間設定失敗原因ｺｰﾄﾞ			*/
	char				dmy1[76];		/* 予備	###SSCY0061	end				*/
										/* ###SSCY0118 end					*/
}						DYREC_DC;
typedef DYREC_DC		*PDYREC_DC;

/* MIA電文の全体構造		*/
typedef struct
{
	MCMIKYO				set1;			/* MIA共通域						*/
	DYREC_DC			set2;			/* MIA利用者域						*/
}						SET_AREA;

/****************************************/
/* 逆正規化依頼電文[mm_rvrs ---> mme]	*/
/****************************************/
/* MIA利用者域				*/
typedef struct
{
	long				ifcode;			/* ｲﾝﾀﾌｪｰｽｺｰﾄﾞ						*/
	long				pid;			/* 要求電文発行ﾌﾟﾛｾｽ識別子			*/
	long				code;			/* 完了ｺｰﾄﾞ							*/
	long				faildet;		/* 異常詳細							*/
	char				filename[64];	/* 1.正規化ﾃﾞｰﾀ(差分)ﾌｧｲﾙ名			*/
										/* 2.逆正規化ﾃﾞｰﾀﾌｧｲﾙ名				*/
	char				logfile[64];	/* 1.ﾃｰﾌﾞﾙ更新情報ﾛｸﾞﾌｧｲﾙ名			*/
										/* 2.予備							*/
	char				dmy1[112];		/* 予備								*/
}						RVRS_DC;
typedef RVRS_DC			*PRVRS_DC;

/* MIA電文の全体構造		*/
typedef struct
{
	MCMIKYO				set1;			/* MIA共通域						*/
	RVRS_DC				set2;			/* MIA利用者域						*/
}						SET_RAREA;

/************************************/
/* 差分抽出ｻｰﾋﾞｽｺｰﾙ返却情報の構造	*/
/************************************/
/* 差分ありIOﾌﾟﾛｾｽ情報				*/
typedef struct
{
	long				allen;			/* 全体領域ｻｲｽﾞ(利用者指定項目)		*/
	long				iosu;			/* 個別部有効個数返却域				*/
}						IOPROC;			/* 共通部							*/

typedef struct
{
	char				prnm[8];		/* IOﾌﾟﾛｾｽのﾌﾟﾛｾｽ識別名				*/
	unsigned short		difsts;			/* 差分状態							*/
										/*  0x03...増設						*/
										/*  0x02...属性変更					*/
										/*  0x01...撤去						*/
	short				yobi;
}						PROCNM;			/* 個別部							*/

/********************************/
/* 正規化ﾚｺｰﾄﾞの単位情報構造	*/
/********************************/
/* 共通部						*/
typedef struct com_rec
{
	unsigned char		rec_kbn;		/* レコード種別						*/
										/*  0x10:物理回線					*/
										/*  0x20:GW端末論理回線				*/
										/*  0x30:LAN端末論理回線			*/
										/*  0x40:端末ﾊﾟｽ					*/
										/*  0x51:ﾎｽﾄ論理回線(FNA)			*/
										/*  0x61:ﾎｽﾄﾊﾟｽ(FNA)				*/
										/*  0x70:ﾌﾟﾛｾｽ						*/
										/*  0x80:ﾊﾟｽ連結					*/
										/*  0x90:ﾉｰﾄﾞ間通信ﾊﾟｽ				*/
										/*  0xA0:FTAM_SMP通信ﾊﾟｽ			*/
	char				syor_kbn;		/* 処理区分							*/
#define ZOUSETU			0x03			/*  増設							*/
#define HENKOU			0x02			/*  属性変更						*/
#define TEKKYO			0x01			/*  撤去							*/
										/* ###SSCY0061 start				*/
	char				xcf;			/* 動的対象外資源収容表示			*/
										/*  0x00...収容していない			*/
										/*  0x01...収容している				*/
	/* 逆正規化データで有効であり、逆正規化が設定し、差分抽出が参照する。	*/
	/* 以下の条件を満たす物理回線・論理回線階層に設定される。				*/
	/*  (1). 動的対象外プロセスと連結する論理パスを収容する論理回線または	*/
	/*		 物理回線。														*/
	/*  (2). 上記(1)の論理回線を収容する物理回線。							*/
	/*  (3). ＦＮＡ以外のホスト論理回線を収容しているＸ.２５物理回線。		*/
	/*		 (ホスト論理回線はＸ.２５だけが動的対象)						*/
	/* この表示の目的は、収容器が不用意に撤去判定されるのを防ぐことにある。	*/
	/* 動的対象外資源を収容している収容器は撤去できないし、当然二重増設も	*/
	/* できない。そこで、玉虫色の表示を付加して逆正規化するのである。		*/
	/* 収容器情報がカードに載っていなければ撤去を防ぎ、載っていれば			*/
	/* 相殺させて二重増設を防ぐのである。									*/
	/* (玉虫色の収容器はｒａｗモードの場合でも相殺させる)					*/
	char				rsv;			/* 予備								*/
										/* ###SSCY0061 end					*/
}						COMREC;
typedef COMREC			*PCOMREC;

/* 物理回線 [104B]				*/
typedef struct buturi_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	char				kbst;			/* 回線ｽﾃｰﾀｽ						*/
										/*  b4: ﾘﾓｰﾄ回線表示				*/
										/*		 0:ｲﾝﾊｳｽ					*/
										/*		 1:ﾘﾓｰﾄ						*/
										/*  b0: 現用/BU回線					*/
										/*		 0:現用						*/
										/*		 1:BU						*/
										/* ###ST3309 below					*/
	unsigned char		teln[16];		/* (現用のみ)迂回時の相手網加入番号	*/
										/*	[電話番号/ISDN番号]				*/
	char				tlsu;			/* teln有効桁数						*/
	unsigned char		cld1[21];		/* (teln発呼時)着信側ｻﾌﾞｱﾄﾞﾚｽ		*/
										/* ###ST3309 below					*/
	unsigned char		tel2[16];		/* (現用のみ)迂回時の相手網加入番号	*/
										/*	[電話番号/ISDN番号]				*/
	char				tls2;			/* tel2有効桁数						*/
	unsigned char		cld2[21];		/* (tel2発呼時)着信側ｻﾌﾞｱﾄﾞﾚｽ		*/
	unsigned char		forFTAM;		/* FTAM使用ﾌﾗｸﾞ	###SSCY0100 start	*/
										/*  0x01...FTAM運用で使用する		*/
										/*		   (=tfacrxtn自動設定指示)	*/
										/*  0x00...FTAM運用で使用しない		*/
										/* ###SSCY0100 end					*/
	short				xlno;			/* IO論理回線ｴﾝﾄﾘ数					*/
	short				hlno;			/* ﾎｽﾄ論理回線ｴﾝﾄﾘ数				*/
	short				fapn;			/* IO論理ﾊﾟｽｴﾝﾄﾘ数					*/
	char				apno;      		/* AP.puno ###SSCY0153				*/
	char				prtc;			/* 回線のTRADE処理種別				*/
										/*  0x68:X.25						*/
										/*  0x41:4W							*/
										/*  0x42:HDLCﾙｰﾌﾟ					*/
										/*  0x5B:Q.931 [ISDN_D]				*/
										/*  0x6C:TCP/IP						*/
	char				netw;			/* 回線種別							*/
										/*  0x00:専用直通回線				*/
										/*  0x01:電話網						*/
										/*  0x10:ISDN-Dch					*/
										/*  0x11:ISDN-B1ch					*/
										/*  0x12:ISDN-B2ch					*/
	char				bulp;			/* (現用)迂回時選択BU回線ﾌﾟｰﾙID		*/
										/* (BU  )自BU回線所属ﾌﾟｰﾙID			*/
	char				yobi2_3[12];	/* 予備 ###ST3309					*/
}						BTURIREC;
typedef BTURIREC		*PBTURIREC;

/* GW端末論理回線 [104B]		*/
typedef struct gate_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	short				loca_lino;		/* 論理回線番号						*/
	char				yobi3_1[2];		/* 予備								*/
	unsigned char		dadl;			/* 接続先GWのDTEｱﾄﾞﾚｽ桁数			*/
	char				yobi3_2[3];		/* 予備								*/
	unsigned char		dadr[8];		/* 接続先GWのDTEｱﾄﾞﾚｽ				*/
	unsigned char		cxal;			/* 発ｱﾄﾞﾚｽ拡張桁数					*/
	char				yobi3_3[3];		/* 予備								*/
	unsigned char		cxad[20];		/* 発ｱﾄﾞﾚｽ拡張(自NSAPｱﾄﾞﾚｽ)			*/
	unsigned char		rxal;			/* 着ｱﾄﾞﾚｽ拡張桁数					*/
	char				yobi3_4[3];		/* 予備								*/
	unsigned char		rxad[20];		/* 着ｱﾄﾞﾚｽ拡張(GWのNSAPｱﾄﾞﾚｽ)		*/
	unsigned char		clas;			/* 中継ｸﾗｽ(GW中継先ﾌﾟﾛﾄｺﾙ種別)		*/
	unsigned char		gwln;			/* 収容端末回線番号					*/
										/*	(GW内相対ﾁｬﾈﾙ番号)				*/
	char				yobi3_5[2];		/* 予備								*/
	long				dsta;			/* 中継先端末ｱﾄﾞﾚｽ					*/
										/*	(ﾁｬﾈﾙ内相対装置番号:ｺｰﾙﾕｰｻﾞﾃﾞｰﾀ)*/
	unsigned long		sopt;			/* 適用ｼｽﾃﾑｵﾌﾟｼｮﾝ(AP任意値)			*/
										/* ###SSCY0095 start				*/
	long				maxd;			/* 最大分割ﾃﾞｰﾀ長					*/
	char				yobi3_6[20];	/* 予備								*/
										/* ###SSCY0095 end					*/
}						GATEREC;
typedef GATEREC			*PGATEREC;

/* LAN端末論理回線 [ 36B]		*/
typedef struct lan_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	short				loca_lino;		/* 論理回線番号						*/
/*	char				yobi4_1[2];		/* 予備						MD001	*/
	short				group_no;		/* グループ番号				MD001	*/
	unsigned long		loca;			/* 相手端末ﾛｰｶﾙｱﾄﾞﾚｽ				*/
										/* ###SSCY0095 start				*/
	long				maxd;			/* 最大分割ﾃﾞｰﾀ長					*/
	char				yobi4_2[20];	/* 予備								*/
										/* ###SSCY0095 end					*/

}						LANREC;
typedef LANREC			*PLANREC;

/* 端末パス [44B]				*/
typedef struct wsps_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	char				psnm[8];		/* 論理パス識別名					*/
	char				iokd;			/* APIｶﾃｺﾞﾘ (LOOP/4WIO/4WNTM)		*/
	char				yobi5_1[1];		/* 予備								*/
	short				dvno;			/* 装置番号[4W]/					*/
										/* 当該論理ﾊﾟｽ収容論理回線番号		*/
	short				phno;			/* 論理ﾊﾟｽ番号						*/
										/*　(APIｶﾃｺﾞﾘ=HDLCﾙｰﾌﾟのみ)			*/
	char				soft;			/* ｿﾌﾄ機番							*/
	char				prfx;			/* ﾌﾟﾚﾌｨｸｽ							*/
										/*  (APIｶﾃｺﾞﾘ=4WIO,4WNTMのみ)		*/
	char				yobi5_2[24];	/* 予備								*/
}						WSPSREC;
typedef WSPSREC			*PWSPSREC;

/* ﾎｽﾄ論理回線共通 [12B]		*/
typedef struct hstlc_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	short				lnno;			/* 予備 ###ST4050					*/
	short				llno;			/* 論理回線番号						*/
	char				prot_kbn;		/* 通信制御種別						*/
	char				yobi6_1[3];		/* 予備								*/
}						HSTLCREC;
typedef HSTLCREC		*PHSTLCREC;

/* FNA論理回線 [100B]			*/
typedef struct fnalc_rec
{
	short				fna_puno;		/* FNA.PU番号						*/
	char				yobi7_1[2];		/* 予備								*/
	unsigned char		deln;			/* 相手DTEｱﾄﾞﾚｽ桁数					*/
	unsigned char		hadl;			/* 発ｱﾄﾞﾚｽ拡張桁数					*/
	unsigned char		cadl;			/* 着ｱﾄﾞﾚｽ拡張桁数					*/
	char				yobi7_2[1];		/* 予備								*/
	unsigned char		dead[8];		/* 相手DTEｱﾄﾞﾚｽ						*/
	unsigned char		haad[20];		/* 発ｱﾄﾞﾚｽ拡張						*/
	unsigned char		caad[20];		/* 着ｱﾄﾞﾚｽ拡張						*/
	char				yobi7_3[24];	/* 予備								*/
}						FNALCREC;
typedef FNALCREC		*PFNALCREC;

/* FTAM通信パス [104B]			*/
typedef struct
{
	unsigned short		lnno;			/* 回線番号 (puno << 8 + chno)		*/
	unsigned short		dstl;			/* 通信識別名の長さ(ﾊﾞｲﾄ数)			*/
	unsigned short		sapl;			/* 相手側FSAP-IDの長さ(ﾊﾞｲﾄ数)		*/
	unsigned short		radl;			/* 着呼側DTEｱﾄﾞﾚｽの長さ(ﾊﾞｲﾄ数)		*/
	unsigned char		awal;			/* 相手側拡張ｱﾄﾞﾚｽの長さ(BCD)		*/
	unsigned char		rsv3[3];		/* 予備								*/
	unsigned char		dsid[16];		/* 通信識別名						*/
	unsigned char		rsap[16];		/* 相手側FSAP-ID					*/
	unsigned char		radr[8];		/* 着呼側DTEｱﾄﾞﾚｽ					*/
	unsigned char		awad[20];		/* 相手側拡張ｱﾄﾞﾚｽ					*/
	unsigned char		rsv[64];		/* 予備								*/
}						FTAMREC;
typedef FTAMREC			*PFTAMREC;

/* ﾎｽﾄ論理ﾊﾟｽ共通 [8B]			*/
typedef struct hstps_rec
{
	short				puno;			/* 回線収容PU番号					*/
	short				chno;			/* 回線CH番号 [PU内相対]			*/
	short				loca_lino;		/* 論理回線番号						*/
	char				prot_kbn;		/* 通信制御種別						*/
	char				yobi8_1[1];		/* 予備								*/
}						HSTPSREC;
typedef HSTPSREC		*PHSTPSREC;

/* FNA論理ﾊﾟｽ [40B]				*/
typedef struct fnaps_rec
{
	char				lusb;			/* LU種別[LU0/LU2/LU3]				*/
	char				ttyp;			/* 端末ﾀｲﾌﾟ(端末主導型･ﾎｽﾄ主導型)	*/
	char				yobi9_1[2];		/* 予備								*/
	short				puno;			/* FNA.PU番号						*/
	short				luno;			/* FNA.LU番号						*/
	char				psnm[8];		/* 論理ﾊﾟｽ識別子					*/
	char				yobi8_9[24];	/* 予備								*/
}						FNAPSREC;
typedef FNAPSREC		*PFNAPSREC;

/* ﾌﾟﾛｾｽ [72B]					*/
typedef struct proc_rec
{
	char				pnm[8];			/* ﾌﾟﾛｾｽ識別名						*/
	char				tpfn[16];		/* ﾌﾟﾛｸﾞﾗﾑﾊﾟｽ名						*/
	char				puno;			/* PU番号							*/
	char				kbn;			/* EDP/DCP区分						*/
										/*  '0'...EDP						*/
										/*  '1'...DCP						*/
	char				yobi10_1[2];	/* 予備								*/
	char				tgrn[2];		/* ｸﾞﾙｰﾌﾟｺｰﾄﾞ						*/
	char				tsgn[2];		/* ｻﾌﾞｸﾞﾙｰﾌﾟｺｰﾄﾞ					*/
	unsigned char		grcd[12];		/* ｴﾘｱｺｰﾄﾞ							*/
										/*  ﾒｼﾞｬｰｴﾘｱｺｰﾄﾞ [4]				*/
										/*  ﾏｲﾅｴﾘｱｺｰﾄﾞ   [4]				*/
										/*  ﾛｰｶﾙｴﾘｱｺｰﾄﾞ  [4]				*/
	char				ndth;			/* NTC代表端末						*/
	char				sdth;			/* ﾏｲﾅｴﾘｱ代表端末					*/
	short				iokd;			/* ﾒｯｾｰｼﾞｱﾋﾞﾘﾃｨ(IO種別)				*/
	char				yobi10_2[24];	/* 予備								*/
}						PROCREC;
typedef PROCREC			*PPROCREC;

/* ﾊﾟｽ連結 [52B]				*/
typedef struct coupl_rec
{
	char				pnm[8];			/* ﾌﾟﾛｾｽ識別名						*/
	short				wsno;			/* WS番号							*/
	char				wscl;			/* WS種別(ｼｽﾃﾑ任意値)				*/
	char				yobi11_1[1];	/* 予備								*/
	char				tlphpsnm[8];	/* ﾎｽﾄ論理ﾊﾟｽ識別名					*/
	char				tlptpsnm[8];	/* 端末論理ﾊﾟｽ識別名				*/
	long				ssop[2];		/* 適用ｼｽﾃﾑｵﾌﾟｼｮﾝ					*/
	char				yobi11_2[24];	/* 予備								*/
}						COUPLREC;
typedef COUPLREC		*PCOUPLREC;

/* ﾉｰﾄﾞ通信ﾊﾟｽ [48B]			*/
typedef struct
{
//	char				type;			/* 通信方式					MD001	*/
//										/*  0x00: SCSI				MD001	*/
//										/*  0x01: LAN 				MD001	*/
	unsigned char		netd;			/* ﾈｯﾄﾜｰｸ代表表示					*/
										/*  b0: ﾈｯﾄﾜｰｸ代表表示				*/
										/*   1...ﾈｯﾄﾜｰｸ代表である			*/
										/*   0...ﾈｯﾄﾜｰｸ代表でない			*/
										/*  b1: 自ﾉｰﾄﾞ表示					*/
										/*   1...自ﾉｰﾄﾞである				*/
										/*   0...自ﾉｰﾄﾞでない				*/
										/* b2-7: 常に0						*/
	char				yobi12_1;		/* 予備						MD001	*/									
	short				nscn;			/* NSコンテキスト番号		MD001	*/
	short				ndno;			/* 相手ﾉｰﾄﾞ番号				MD001	*/
	char				yobi12_2[42];	/* 予備						MD001	*/

// MD001
//	char				yobi12_1[2];	/* 予備						MD001	*/
//
//	/* LANのみ			*/
//	long				MYipad;			/* 自ﾉｰﾄﾞIPｱﾄﾞﾚｽ					*/
//	short				MYapno;			/* 自ﾉｰﾄﾞACTIVEｺﾈｸｼｮﾝ使用ﾎﾟｰﾄ番号	*/
//	short				MYlpno;			/* 自ﾉｰﾄﾞLISTENｺﾈｸｼｮﾝ使用ﾎﾟｰﾄ番号	*/
//	short				ndno;			/* 相手ﾉｰﾄﾞ番号						*/
//	char				yobi12_2[2];	/* 予備								*/
//	long				ipad;			/* 相手ﾉｰﾄﾞIPｱﾄﾞﾚｽ					*/
//	short				apno;			/* 相手ﾉｰﾄﾞACTIVEｺﾈｸｼｮﾝ使用ﾎﾟｰﾄ番号	*/
//	short				lpno;			/* 相手ﾉｰﾄﾞLISTENｺﾈｸｼｮﾝ使用ﾎﾟｰﾄ番号	*/
//
//	/* SCSIのみ			*/
//	char				ace1;			/* 相手ﾉｰﾄﾞ(現用系)装置番号			*/
//	char				ace2;			/* 相手ﾉｰﾄﾞ(予備系)装置番号			*/
//	char				yobi12_9[22];	/* 予備								*/
}							NODEREC;
typedef	NODEREC				*PNODEREC;

/************************************/
/* 正規化ﾚｺｰﾄﾞのﾚｺｰﾄﾞ構造			*/
/************************************/
#define RECMAXSIZ		256				/* 正規化ﾚｺｰﾄﾞ読み込み域ｻｲｽﾞ		*/
										/* (最大ﾚｺｰﾄﾞｻｲｽﾞ以上であること)	*/

/* 物理回線 [108B]					*/
typedef struct
{
	COMREC				x;
	BTURIREC			y;
}						REC10;
typedef REC10			*PREC10;

/* GW端末論理回線 [108B]		*/
typedef struct
{
	COMREC				x;
	GATEREC				y;
}						REC20;
typedef REC20			*PREC20;

/* LAN端末論理回線 [40B]		*/
typedef struct
{
	COMREC				x;
	LANREC				y;
}						REC30;
typedef REC30			*PREC30;

/* 端末ﾊﾟｽ [48B]				*/
typedef struct
{
	COMREC				x;
	WSPSREC				y;
}						REC40;
typedef REC40			*PREC40;

/* FNA論理回線 [96B]			*/
typedef struct
{
	COMREC				x;
	HSTLCREC			y;
	FNALCREC			z;
}						REC51;
typedef REC51			*PREC51;

/* FNA論理ﾊﾟｽ [48B]				*/
typedef struct
{
	COMREC				x;
	HSTPSREC			y;
	FNAPSREC			z;
}						REC61;
typedef REC61			*PREC61;

/* ﾌﾟﾛｾｽ [76B]					*/
typedef struct
{
	COMREC				x;
	PROCREC				y;
}						REC70;
typedef REC70			*PREC70;

/* ﾊﾟｽ連結 [56B]				*/
typedef struct
{
	COMREC				x;
	COUPLREC			y;
}						REC80;
typedef REC80			*PREC80;

/* ﾉｰﾄﾞ間通信ﾊﾟｽ [52B]			*/
typedef struct
{
	COMREC				x;
	NODEREC				y;
}						REC90;
typedef REC90			*PREC90;

/* FTAM通信ﾊﾟｽ [108B]			*/
typedef struct
{
	COMREC				x;
	FTAMREC				y;
}						RECA0;
typedef RECA0			*PRECA0;

/************************************/
/* ﾌﾟｰﾙﾊﾞｯﾌｧ管理情報部 [16B]		*/
/************************************/
typedef struct pool_com
{
	struct pool_com		*next_ptr;		/* 次のﾌﾟｰﾙﾊﾞｯﾌｧｱﾄﾞﾚｽ				*/
	long				len;			/* 当該ﾌﾟｰﾙﾊﾞｯﾌｧ長					*/
	short				max_num;		/* 当該ﾌﾟｰﾙﾊﾞｯﾌｧ最大ﾚｺｰﾄﾞ数			*/
	short				use_num;		/* 当該ﾌﾟｰﾙﾊﾞｯﾌｧ使用ﾚｺｰﾄﾞ数			*/
	short				max_bnum;		/* 当該ﾌﾟｰﾙﾊﾞｯﾌｧ最大ﾊﾞｲﾄ数			*/
	short				use_bnum;		/* 当該ﾌﾟｰﾙﾊﾞｯﾌｧ使用済みﾊﾞｲﾄ数		*/
}						POOLBUF;
typedef POOLBUF			*PPOOLBUF;
										/* ###ST2707 end					*/

										/* start SPCY0134					*/
										/*----------------------------------*/
										/* mm_rvdf関連データ構造			*/
										/*----------------------------------*/
#define RVDF_TRUE		1				/* 変更有り							*/
#define RVDF_FALSE		0				/* 変更なし							*/

typedef struct {
	short		len;					/* 領域長							*/
	short		num;					/* 変更情報返却数					*/
} RVDFCOM;								/* 変更情報共通部構造体				*/

typedef struct {
	short		puno;					/* PU番号							*/
	short		chno;					/* CH番号							*/
	char		tel1;					/* 電話番号１変更有無				*/
	char		tel2;					/* 電話番号２変更有無				*/
	short		rsv;
} RVDFBUP;								/* バックアップ先情報構造体			*/

typedef struct {
	short		puno;					/* PU番号							*/
	short		chno;					/* CH番号							*/
	short		fnapuno;				/* FNA-PU番号						*/
	char		dead;					/* 相手DTEアドレス変更有無			*/
	char		rsv;
} RVDFFNA;								/* ホスト接続先情報構造体			*/

typedef struct {
	short		puno;					/* PU番号							*/
	short		chno;					/* CH番号							*/
	char		dsid[16];				/* 通信相手識別名					*/
	char		radr;					/* 着呼側DTEアドレス変更有無		*/
	char		awad;					/* 相手拡張アドレス変更有無			*/
	short		rsv;
} RVDFFTAM;								/* FTAM通信相手先情報構造体			*/
										/* end SPCY0134						*/
