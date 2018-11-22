/****************************************************************************/
/*                                                                          */
/*           リモートメンテナンス制御情報管理テーブル（ＴＲＭＮ）           */
/*                                                                          */
/*                作成日：1994/4/8      更新日：1994/4/11                   */
/*                修正日：1997/10/19    宮脇　伸                 ST4978  	*/
/*                                      trmnfchr追加                        */
/*                修正日：1997/11/03    宮脇  伸                 ST4946     */
/*                						trmnkeit,trmngnex追加				*/
/*                修正日：1997/11/16    宮脇  伸                 ST4993     */
/*                						trmnysms追加						*/
/*                                                                          */
/****************************************************************************/

/*******************************  個別部  ***********************************/

struct trmnpsz
{
    unsigned char    trmndtyp;          /* リモートメンテナンス日付タイプ   */
    unsigned char    trmnrsv8;          /* Reserve 8				        */
             char    trmnsusp;          /* suspend Create ID 	            */
             char    trmnrsv1;          /* リザーブ 1                       */
             char    trmnapid[8];       /* 代表ＡＰプロセス識別名           */
             char    trmnrmp1[8];       /* ﾘﾓｰﾄ通知特定APﾌﾟﾛｾｽ識別名(P01)   */
             char    trmnrmp2[8];       /* ﾘﾓｰﾄ通知特定APﾌﾟﾛｾｽ識別名(P02)   */
             char    trmnrmp3[8];       /* ﾘﾓｰﾄ通知特定APﾌﾟﾛｾｽ識別名(P03)   */
             long    trmntmem;          /* ﾒﾓﾘﾊﾟｯﾁ許可応答回収待ちﾀｲﾏ値     */
             long    trmntmrm;          /* リモート通知再発行待ちタイマ値   */
             long    trmntins;          /* ＩＮＩＴ−Ｓ待ちタイマ値         */
             long    trmntine;          /* ＩＮＩＴ−Ｅ待ちタイマ値         */
             long    trmntprs;          /* プロセス走行依頼待ちタイマ値     */
             long    trmntbmn;          /* 状態照会応答待ち待ちタイマ値     */
             long    trmnymem;          /* 予備系ﾒﾓﾘﾊﾟｯﾁ完了通知待ちﾀｲﾏ値   */
             long    trmnyfpt;          /* 予備系ﾌｧｲﾙﾊﾟｯﾁ完了通知待ちﾀｲﾏ値  */
             long    trmnyfcg;          /* 予備系ﾌｧｲﾙ入れ替え完了通知待ち   */
                                        /* ﾀｲﾏ値                            */
             long    trmnyrbk;          /* 予備系ﾌｧｲﾙﾛｰﾙﾊﾞｯｸ完了通知待ち    */
                                        /* ﾀｲﾏ値                            */
             long    trmnygrp;          /* 予備系ｸﾞﾙｰﾌﾟ実行完了待ちﾀｲﾏ値    */
             long    trmnlpcn;          /* 論理ﾊﾟｽｺﾈｸﾄﾀｲﾏ値                 */
             long    trmntpso;          /* 論理ﾊﾟｽｵｰﾌﾟﾝﾀｲﾏ値                */
    unsigned short   trmnrtry;          /* リモート通知最大リトライ数       */
										/* ###ST4978 start					*/
    unsigned char    trmnfchr;          /* ﾌｧｲﾙ入替作業ﾃﾞｨﾚｸﾄﾘ作成ﾓｰﾄﾞ      */
										/* ###ST4978 end					*/
										/* ###ST4946 start					*/
    unsigned char    trmnkeit;          /* 主従系区分タイプ   	       		*/
    unsigned char    trmngnex;          /* 現用系区分抑止フラグ   			*/
             char    trmnrsv3[3];       /* リザーブ３                       */
										/* ###ST4946 end					*/
    unsigned short   trmnrmns;          /* リモートメンテナンス状態         */
             short   trmnrsv4;          /* リザーブ４                       */
             long    trmnprid;          /* メンテナンス子プロセスｉｄ       */
    unsigned char    trmnisrs;          /* ＩＮＩＴ−Ｓ通知受信状態         */
    unsigned char    trmniers;          /* ＩＮＩＴ−Ｅ通知受信状態         */
    unsigned char    trmnpsrs;          /* プロセス走行依頼通知受信状態     */
    unsigned char    trmnmnrs;          /* メンテナンス依頼受信状態         */
    unsigned char    trmntsrs;          /* テーブル退避完了通知受信状態     */
    unsigned char    trmnkcrs;          /* 系切り替え通知受信状態           */
    unsigned char    trmnymrs;          /* 予備系ﾒﾝﾃﾅﾝｽ終了依頼通知受信状態 */
    unsigned char    trmnysms;          /* 予備系ｼｽﾃﾑﾓｰﾄﾞ変更実施フラグ		*/
             char    trmnrsv7[20];      /* リザーブ７                       */
};

typedef struct trmnpsz TRMNPSZ; 

