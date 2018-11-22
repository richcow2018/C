/****************************************************************************/
/*	著作権	１９９３														*/
/*			  ＮＴＴデータ通信株式会社										*/
/*				金融システム事業本部										*/
/*																			*/
/*																			*/
/*	収容物	ＡＣＥ−ＳＭＰシステム　ＯＣＰヘッダファイル　　				*/
/****************************************************************************/

/*--------------------------------------------------------------------------*/
/*＜対象業務名＞					 運転実行管理業務						*/
/*＜対象業務ＩＤ＞					 ＯＣＰ									*/
/*＜サービス項目名＞				 										*/
/*＜サービス項目ＩＤ＞				 										*/
/*＜モジュール名＞					 ｍｏｓｄｗｎ．ｈ						*/
/*＜モジュールＩＤ＞				 										*/
/*＜モジュール通番＞				 										*/
/*--------------------------------------------------------------------------*/
/*＜適用機種＞						 ＡＣＥ									*/
/*＜適用ＯＳ＞						 ＴＲＡＤＥ								*/
/*＜開発環境＞						 ＳＵＮ　ＳＰＡＲＣ−ＩＰＸ				*/
/*＜記述言語＞						 Ｃ言語									*/
/*＜モジュール形態＞				 										*/
/*＜機能区分＞						 										*/
/*＜対象データ＞					 										*/
/*＜工程・階層区分＞				 										*/
/*--------------------------------------------------------------------------*/
/*＜開発システム名＞				 ＡＣＥ−ＳＭＰシステム					*/
/*＜開発システム番号＞				 ５７２６０１４０２１００				*/
/*--------------------------------------------------------------------------*/
/*＜開発担当名＞					 営業店システム担当						*/
/*＜電話番号＞						 163-3573(03-5702-3573)					*/
/*--------------------------------------------------------------------------*/
/*＜設計者名＞						 										*/
/*＜設計年月日＞					 										*/
/*--------------------------------------------------------------------------*/
/*＜ソース作成者名＞				 										*/
/*＜ソース作成年月日＞				 										*/
/*＜ソース修正者名＞				 山本　智也								*/
/*＜修正年月日及び修正ＩＤ＞		'94/12/13			 M01				*/
/*	（	ＵＰＳ対応機能　仕様変更要求書番号　ＳＳＣＹ００１５  ）			*/	
/*									'95/02/22			CT0881				*/
/*	（  テーブル故障復旧対応  仕様変更要求書番号  ＳＳＣＹ００７４  ）		*/
/*									'95/07/27			SSCY0074			*/
/*＜ソース修正者名＞				 赤塚　一元								*/
/*＜修正年月日及び修正ＩＤ＞		'95/08/08			 CT1099(ST3133)		*/
/*＜修正年月日及び修正ＩＤ＞		'95/10/13			 ST3492				*/
/*＜ソース修正者名＞				 山本　智也								*/
/*＜修正年月日及び修正ＩＤ＞		'95/12/10			 SSCY0134			*/
/*	（	ﾊﾟﾜｰｵﾌ要求通知対応機能　	仕様変更要求書 SSCY0134	 	）			*/
/*＜修正年月日及び修正ＩＤ＞		'95/12/10			 SSCY0138			*/
/*	（	ＦＡＮアラーム通知対応機能　仕様変更要求書 SSCY0138		 ）			*/
/*＜ソース修正者名＞				 赤塚　一元								*/
/*＜修正年月日及び修正ＩＤ＞		'95/12/15			 CT1193(ST3854)		*/
/*＜ソース修正者名＞				 杉岡  克也								*/
/*＜修正年月日及び修正ＩＤ＞		'96/02/07			 ST3699				*/
/*＜ソース修正者名＞				 今井  弘幸								*/
/*＜修正年月日及び修正ＩＤ＞		'96/02/21			 ST3754				*/
/*＜ソース修正者名＞				 杉岡  克也								*/
/*＜修正年月日及び修正ＩＤ＞		'96/02/26			 ST4027				*/
/*＜ソース修正者名＞				 山本　智也								*/
/*＜修正年月日及び修正ＩＤ＞		'97/06/02			 SSCY0198			*/
/*	（	終了ダンマリ対応機能　		仕様変更要求書 SSCY0198	 	）			*/
/*＜ソース修正者名＞                Com'App 高橋					 		*/
/*＜ソース修正年月日及び修正ＩＤ＞  １９９７年  ６月１１日 SSCY0197  		*/
/*	（プロセスキャンセル追加による  osdespr終了コード追加）	 				*/
/*--------------------------------------------------------------------------*/
/*********************************************************************/
/*プロジェクト名	:												 */
/*プロセス名		:ＡＰプロセス									 */
/*改造番号			:PRC-008-08										 */
/*改造内容			:ＴＲＡＤＥエミュレート関数仕様変更対応			 */
/*改造日			:2002.11.20										 */
/*改造者			:supply Taguchi									 */
/*********************************************************************/
/*********************************************************************/
/*障害番号			:TBCS0083										 */
/*障害内容			:マスタスケジューラダウンコードの規定外			 */
/*修正内容			:ダウンコードの追加								 */
/*修正日			:2003.05.15										 */
/*修正者			:supply sugawara								 */
/*********************************************************************/
/*********************************************************************/
/*障害番号			:TBCS0089										 */
/*障害内容			:SMP終了シェル起動失敗時システムダウンしていない */
/*修正内容			:ダウンコードの追加								 */
/*修正日			:2003.05.20										 */
/*修正者			:supply sugawara								 */
/*********************************************************************/
/*********************************************************************/
/*仕様変更番号		:SSLA0027										 */
/*修正内容			:立上げモード設定関数の呼び出し処理追加に伴い	 */
/*					 ダウンコードの追加								 */
/*修正日			:2003.05.27										 */
/*修正者			:supply sugawara								 */
/*********************************************************************/
/*********************************************************************/
/*障害番号			:TBCS0156										 */
/*障害内容			:テーブルリカバリ失敗時システムダウンしていない	 */
/*修正内容			:ダウンコードの追加								 */
/*修正日			:2003.06.18										 */
/*修正者			:supply sugawara								 */
/*********************************************************************/
/*********************************************************************/
/*    ｼｽﾃﾑ ﾀﾞｳﾝ ｺ-ﾄﾞ                                                 */
/*********************************************************************/

/*****  ｵﾍﾟﾚｰﾀｰ ﾆﾖﾙ ｼｭｳﾘｮｳ  ******************************************/
#define  MOOPETRD  0x01                 /* stop                      */
#define  MOOPETRS  0x02                 /* stop start                */

/*****  ﾛﾝﾘ ｴﾗｰ  *****************************************************/
#define  MOPRORCV  0x10                 /* ﾌﾟﾛｾｽ ﾘｶﾊﾞﾘ ｲｼﾞﾖｳ    CK   */
#define  MODSRABN  0x11                 /* ｼｽﾃﾑ ﾘｶﾊﾞﾘ ｲｼﾞｮｳ ｼｭｳﾘｮｳ   */
#define  MODKKER   0x12                 /* ｹｲｶﾝ ｶﾝｼ ｲｼﾞｮｳ ｼｭｳﾘｮｳ     */
#define  MODACTCI  0x13                 /* ｹｲｶﾝ ｶﾝｼ ﾑｼﾞﾕﾝ            */
#define  MODACTCE  0x14                 /* ｹｲｶﾝ ｶﾝｼ ｲｼﾞﾖｳ            */
#define  MODCREPR  0x15                 /* ﾌﾟﾛｾｽ ﾉ ｾｲｾｲ ｶﾞ ｼｯﾊﾟｲ     */
#define  MODMBMK   0x16                 /* ﾒｲﾙ ﾎﾞｯｸｽ ﾉ ｻｸｾｲ ｶﾞ ｼｯﾊﾟｲ */
#define  MODMBDEL  0x17                 /* ﾒｲﾙ ﾎﾞﾂｸｽ ﾉ ｻｸｼﾞｮ ｼｯﾊﾟｲ   */
#define  MODPBMK   0x18                 /* ﾊﾞｯﾌｧ ﾌﾟｰﾙ ﾉ ｻｸｾｲ   ｼｯﾊﾟｲ */
#define  MODPBGT   0x19                 /* ﾊﾞｯﾌｧ ﾌﾟｰﾙ ﾉ ｶｸﾎ  ｼｯﾊﾟｲ   */
#define  MODPBFRE  0x1A                 /* ﾊﾞｯﾌｧ ﾌﾟｰﾙ ﾉ ｶｲﾎｳ ｼｯﾊﾟｲ   */
#define  MODPBDEL  0x1B                 /* ﾊﾞｯﾌｧ ﾉ ｻｸｼﾞｮ ｼｯﾊﾟｲ       */
#define  MODSFMK   0x1C                 /* ｾﾏﾌｫ ﾉ ｻｸｾｲ  ｼｯﾊﾟｲ        */
#define  MODRIDRS  0x1D                 /* ﾘｸｴｽﾄ id ﾉ ﾖﾔｸ ｼｯﾊﾟｲ      */
#define  MODGTSHM  0x1E                 /* ｷｮｳﾖｳﾒﾓﾘ ｶｸﾄｸ ｼｯﾊﾟｲ       */
#define  MODGTTAD  0x1F                 /* ﾃｰﾌﾞﾙ ｾﾝﾄｳ ｱﾄﾞﾚｽ ｼｭﾄｸｼｯﾊﾟｲ*/

#define  MODCMTBL  0x21                 /* CM ﾖｳ ﾃｰﾌﾞﾙ ﾛｰﾄﾞ ｼｯﾊﾟｲ    */
#define  MODLMTBL  0x22                 /* LM ﾖｳ ﾃｰﾌﾞﾙ ﾛｰﾄﾞ ｼｯﾊﾟｲ    */
#define  MODIDFIL  0x23                 /* ｿｳﾁ ID ﾌｧｲﾙ ﾌﾄｳ 			 */

#define  MODSYSCE  0x27                 /* ｼｽﾃﾑ ｺ-ﾙ ﾉ ｴﾗ-            */
#define  MODSETEX  0x28                 /* ﾚｲｶﾞｲﾙ-ﾁﾝ ﾄｳﾛｸ ｴﾗ-   MA   */
#define  MODMRCVE  0x29                 /* ﾒｯｾｰｼﾞ ｼﾞｭｼﾝ ｼｮﾘ ﾃﾞ ｴﾗｰ   */

#define  MODCALLE  0x2D                 /* ﾃｲｷｮｳ ｶﾝｽｳ ﾃﾞ ｴﾗｰ         */
#define  MODNSMMD  0x2E                 /* ｳﾝﾃﾝ ﾓｰﾄﾞ ﾌｲｯﾁ            */
#define  MODSFRDE  0x2F                 /* SMP ﾌｧｲﾙ I/O ｴﾗｰ          */
#define  MODSFERR  0x30                 /* SMP ﾌｧｲﾙ ﾉ ﾅｲﾖｳ ｶﾞ ﾌﾄｳ    */
#define  MODSTATE  0x31                 /* ｳﾝﾃﾝ ｼﾞｮｳｷｮｳ ｾﾝｲ ｲｼﾞｮｳ ﾂｳﾁ*/
#define  MODINVDM  0x32                 /* ｳﾝﾃﾝ ｼﾞﾖｳｷﾖｳ ｾﾝｲ ﾂｳﾁ ｲｼﾞﾖｳ*/
#define  MODSTART  0x33                 /* ﾀﾁｱｹﾞ ﾄﾞｳｷ ｲｼﾞｮｳ ﾂｳﾁ      */
#define  MODCMNL   0x37                 /* ｽﾄﾘﾝｸﾞ ｶﾞ NULL            */
#define  MODPCTNE  0x38                 /* ﾄｸﾃｲ ﾌﾟﾛｾｽ ｶﾞ PCT ﾆ ﾅｲ    */
#define  MODUSNOT  0x39                 /* TRT ｼﾖｳ ｺﾍﾞﾂﾌﾞ ｶﾞ ﾅｲ      */
#define  MODPMERR  0x3A                 /* ﾌﾟﾛｸﾞﾗﾑ ﾓｰﾄﾞ ｶﾞ ﾌﾄｳ       */
#define  MODTBLS   0x3B                 /* Table Size NG(!=struct)   */
#define  MODKKABT  0x3C                 /* ｹｲｶﾝｶﾝｼ ﾉ ｼﾕｳﾘﾖｳ          */
#define  MODSTSNG  0x3D					/* ﾃｰﾌﾞﾙ ﾌｧｲﾙ ﾀｲﾋ ﾌｶ		 */
#define	 MODTBLNON 0x3E					/* テーブルが存在しないST1220*/
#define	 MODNRERR  0x3F					/* 開始区分の書き換えにCT0696*/
										/* 失敗						 */

#define  MODFRPR   0x40                 /* osrespr ｼｯﾊﾟｲ             */
#define  MODFMSG   0x41                 /* ossenms ｼｯﾊﾟｲ             */
#define  MODFTMR   0x42                 /* ossttim ｼｯﾊﾟｲ             */
#define  MODFSPR   0x43                 /* ossuspr ｼｯﾊﾟｲ             */
#define  MODFDBP   0x44                 /* osdelbp ｼｯﾊﾟｲ             */
#define  MODFDMB   0x45                 /* osdelmb ｼｯﾊﾟｲ             */
#define  MODFDOP   0x46                 /* ｴｷｼｮｳ ﾃﾞｨｽﾌﾟﾚｲ conn/open  */
#define  MODSDBGN  0x47                 /* ｿｳｼﾝ ﾖｳ msg ﾊﾞｯﾌｧ ｶｸﾄｸ NG */
#define  MODMRSDN  0x48                 /* mr_sdwn ｼｯﾊﾟｲ             */
#define  MODASINT  0x49                 /* mo_asin abort             */
#define  MODPABRT  0x4A                 /* process abort             */
#define  MODIOCTL  0x73					/* osioctlで失敗		TD61 */
#define	 MODSENMSP 0x33					/* ossenmspで失敗		TD44 */

#define  MOSBMSDW  0x4B                 /* ｻﾌﾞMS   abort             */
#define  MOPUFALT  0x4C                 /* pu falt                   */
#define	 MOPTOPNF  0x4D					/* 経路開設失敗			TD01 */
#define  MODTMOUT  0x4E                 /* sub MS ｶﾗﾉ ﾂｳﾁ ﾏﾁ time out*/
#define  MODMRCVS  0x4F                 /* ﾒｯｾｰｼﾞ ｿｳｼﾝ ｼｯﾊﾟｲ         */
#define  MODPUNG   0x50                 /* pu ｼﾞｮｳﾀｲ ﾌﾄｳ             */
#define  MODIRPU   0x51                 /* pu ﾊﾞﾝｺﾞｳ ﾌﾄｳ             */
#define  MODPIDDF  0x52                 /* grpmpr pid ﾌｲｯﾁ           */
#define  MODSETER  0x53                 /* ﾌﾟﾛｸﾞﾗﾑ ﾓｰﾄﾞ ｸﾐｱﾜｾ NG	 */
#define  MODSAMTU  0x54                 /* ｹｲｸﾌﾞﾝ ｲｯﾁ			   	 */
#define  MODDFSYS  0x55                 /* ｼｽﾃﾑ ｺｳｾｲ ﾌｲｯﾁ 			 */
#define  MODHOTYB  0x56                 /* ﾎｯﾄｽﾀﾝﾊﾞｲ ﾖﾋﾞ ﾃﾞ ｱｲﾃ ｻｲｶｲｼ*/
#define  MODDFMOD  0x57                 /* ﾌﾟﾛｸﾞﾗﾑ ﾓｰﾄﾞ ﾌｲｯﾁ         */
#define  MODLEXNG  0x58                 /* ｶｲｾﾝ ｷﾘｶｴ ｼｯﾊﾟｲ           */
#define  MODPMDNG  0x59                 /* ﾌﾟﾛｸﾞﾗﾑ ﾓｰﾄﾞ ｾｯﾃｲ ｼｯﾊﾟｲ	 */
#define  MODSTDF   0x5A					/* mosysdte I/O (ﾘｰﾄﾞ)ｴﾗｰ  	 */
#define  MODRNECH  0x5B					/* ﾘｶﾊﾞﾘ ﾖｳ ﾃﾞ ﾎｯﾄｽﾀﾝﾊﾞｲ	 */
#define  MODDNULL  0x5C					/* ﾋﾂﾞｹ･ｼﾞｺｸ ﾆ NULL ｶﾞ ｱﾙ 	 */
#define  MODTRDF   0x5D					/* mosysdte I/O (ｶｷｺﾐ) ｴﾗｰ	 */
#define  MODNOCHG  0x5E					/* ﾘｮｳｹｲｳﾝﾃﾝ ﾃﾞ ｹｲｷﾘｶｴ ﾌﾖｳ   */
#define  MODPCCN   0x5F                 /* mo_pccn ｼｯﾊﾟｲ             */
#define	 MORMTABT  0x60					/* ﾘﾓｰﾄﾒﾝﾃﾅﾝｽｶｰﾈﾙｱﾎﾞｰﾄ	TD56 */
#define	 MOREVCHG  0x61					/* 切替系→予備系		TD01 */
#define	 MOLGCERR  0x62					/* 論理矛盾				TD01 */
#define	 MOUPSURCV 0x63					/* UPS停電状態未回復    M01  */
#define  MODDSTS   0x64					/* mosysdsts I/O ｴﾗｰ  CT0881 */
#define	 MOCHDIR   0x65					/* カレントディレクトリ設定失敗	TBCS0083 */
#define  MOSHSYER  0x66					/* 終了シェル起動失敗    TBCS0089  */
#define  MOFORKER  0x67					/* プロセス生成失敗(fork)TBCS0089  */
#define  MOSYSSET  0x68					/* 立上げモード設定失敗  SSLA0027  */
#define	 MOTRCVER  0x69					/* テーブルリカバリ失敗  TBCS0156  */

/*****  ﾊﾟﾗﾒﾀ ｴﾗｰ  ***************************************************/
#define  MODPRMCE  0x70                 /* ﾊﾟﾗﾒ-ﾀ ﾉ ｺｽｳ ｶﾞ ﾌﾄｳ       */
#define  MODPRMVE  0x71                 /* ｼﾖﾘ ｼﾕﾍﾞﾂ ｶﾞ ﾌﾄｳ          */
#define  MODPRAER  0x72                 /* ﾊﾟﾗﾒｰﾀ ｶﾞ ﾌﾄｳ             */

/*****  ｼｶｸ,ﾄﾞｳｷ ｴﾗｰ  ************************************************/

/*****  ﾊｰﾄﾞ ｴﾗｰ  ****************************************************/
#define  MODBUSER  0xA0                 /* ﾊﾞｽｴﾗ-                    */
#define  MODFANALM 0xA1                 /* FANｱﾗｰﾑ通知受信 SSCY0138  */

/*****  ｼｹﾞﾝﾌﾞｿｸ  ｴﾗｰ  ***********************************************/

/*****  ｿﾉﾀﾉ ｴﾗｰ  ****************************************************/
#define  MODOPER   0xE0                 /*                           */
#define  MODACTCR  0xE1                 /* ｹｲｶﾝｶﾝｼ ﾉ ﾖｳｷﾕｳ ﾆﾖﾙ ｹｲｷﾘｶｴ*/
#define  MODABEND  0xE2                 /* ﾚｲｶﾞｲﾙ-ﾁﾝ ｶﾗﾉ ﾀﾞｳﾝ   MA   */
#define  MODOROSE  0xE3                 /* ROS ｼﾖｳｶﾞｲ ﾂｳﾁ ﾆ ﾖﾙ ﾀﾞｳﾝ  */
#define  MODPOWOFF 0xE4                 /* ﾊﾟﾜｰｵﾌ要求受信 SSCY0134	 */
#define  MODPCANER 0xE5                 /* ｷｬﾝｾﾙﾀﾞﾝﾏﾘ	  SSCY0198	 */

#define	 MOADWDWN  0xB1					/* ダウン要求によるダウン	 */
										/*		ST3847				 */

                                                                  /*%*/
/*********************************************************************/
/*    ｼﾖｳｻｲ ｺ-ﾄﾞ                                                     */
/*********************************************************************/
 
/*   ossttim ｼｯﾊﾟｲ( mo_trem )    (0x42)                              */
#define  MODTMTR   0x01                 /* end timer                 */
#define  MODTMDK   0x02                 /* disk write                */
#define	 MOALNTM   0x03					/* 孤立状態回復待ち		TD01 */
#define	 MOYBWTM   0x04					/* 予備系待ち			TD01 */
#define	 MOADWTM   0x05					/* 相手系ダウン待ち	ST3854	 */
 
/*	 mosysdte I/O ｴﾗｰ (ﾘｰﾄﾞ)	 (0x5A)								 */

/*	 mosysdte I/O ｴﾗｰ (ｶｷｺﾐ)	 (0x5D)								 */

/*   SMP ｼｽﾃﾑ ﾌｧｲﾙ I/O ｴﾗｰ       (0x2F)                              */
#define  MODCONN   0x01                 /* osconn ｼｯﾊﾟｲ              */
#define  MODOPEN   0x02                 /* osopen ｼｯﾊﾟｲ              */
#define  MODREAD   0x03                 /* osread ｼｯﾊﾟｲ              */
#define  MODCLOSE  0x04                 /* osclose ｼｯﾊﾟｲ             */
#define  MODDCONN  0x05                 /* osdconn ｼｯﾊﾟｲ             */
#define  MODGTDAT  0x06                 /* osgtdat ｼｯﾊﾟｲ             */
#define  MODWRITE  0x07                 /* oswrite ｼｯﾊﾟｲ             */

/*   SMP ｼｽﾃﾑ ﾌｧｲﾙ ﾉ ﾅｲﾖｳ ｶﾞ ﾌﾄｳ (0x30)                              */
#define  MODKYONO  0x01                 /* ｷｮｳﾀｲ ﾊﾞﾝｺﾞｳ ｶﾞ ﾌﾄｳ       */
#define  MODSTBLK   0x02				/* 立ち上げ区分が不当	TD01 */
#define  MODTIME   0x03                 /* ﾀﾁｱｹﾞ ｼｮﾖｳ ｼﾞｶﾝ ｶﾞ ﾌﾄｳ    */
#define  MODMDCKT  0x04                 /* ｳﾝﾃﾝ ﾓｰﾄﾞ ﾁｪｯｸ ﾃｰﾌﾞﾙ ﾌﾄｳ  */
#define  MODSINF   0x05                 /* ｼｽﾃﾑ ｺｳｾｲ ｼﾞｮｳﾎｳ ｶﾞ ﾌﾄｳ   */
#define  MODKCHGI  0x06                 /* ｹｲ ｷﾘｶｴ ｼﾞｮｳﾎｳ   ｶﾞ ﾌﾄｳ   */
#define  MODCMID   0x07                 /* CM TBL ﾒﾓﾘ ID ｶﾞ ﾌﾄｳ      */
#define  MODCMAD   0x08                 /* CM TBL ﾏｯﾋﾟﾝｸﾞ ｱﾄﾞﾚｽ ﾌﾄｳ  */
#define  MODDSTNO  0x09                 /* ｿｳﾁ ﾊﾞﾝｺﾞｳ ｶﾞ ﾌﾄｳ         */
#define	 MOTBLNON  0x10					/* ﾃｰﾌﾞﾙﾌｧｲﾙ情報が不当 TD01  */
#define	 MOCMDNON  0x11					/* ｺﾏﾝﾄﾞﾌｧｲﾙ名不当		TD01 */ 
#define	 MOKBFNON  0x12					/* 系間監視ﾊﾞｽﾘｾｯﾄﾌｧｲﾙ無しTD01*/
#define	 MOSPMFVN  0x13					/* SPMﾌｧｲﾙﾎﾞﾘｭｰﾑ無 CT0881	 */
#define	 MOSPMFDN  0x14					/* SPMﾌｧｲﾙﾃﾞｨﾚｸﾄﾘ無 CT0881	 */
#define	 MOSPMFPN  0x15					/* SPMﾌｧｲﾙパス名無 CT0881	 */
#define  MOSPMFCH  0x16					/* カレントディレクトリ	2003.03.14	 */

 
/*   ｳﾝﾃﾝ ｼﾞｮｳｷｮｳ ｾﾝｲ ｲｼﾞｮｳ ﾂｳﾁ  (0x31)                              */
#define  MODPRDWN  0x01                 /* ｼｮﾘｹｲ ﾀﾞｳﾝ , ﾑﾂｳﾁ ｼﾞｮｳﾀｲ  */

/*   ﾌﾟﾛｸﾞﾗﾑ ﾓｰﾄﾞ ｶﾞ ﾌﾄｳ         (0x3A)                              */
#define  MODAMDER  0x01                 /* AP ｳﾝﾃﾝ ﾓｰﾄﾞ ｶﾞ ﾌﾄｳ       */
#define  MODSMDER  0x02                 /* SMP ｳﾝﾃﾝ ﾓｰﾄﾞ ｶﾞ ﾌﾄｳ      */

/*   ﾒｯｾｰｼﾞ ｼﾞｭｼﾝ ﾏﾁ ﾃﾞ ｴﾗｰ      (0x29)                              */
#define  MODMYMBX  0x01                 /* osrcvmsr ｼｯﾊﾟｲ            */
#define  MODSRCV   0x02                 /* osrcvmspr ｼｯﾊﾟｲ           */
#define  MODANYRL  0x03                 /* osanyrl   ｼｯﾊﾟｲ           */
#define  MODGTNRL  0x04                 /* osgtnrl失敗		ST4027	 */
                                                                  /*%*/
/*   ﾌﾟﾛｾｽ ﾉ ｾｲｾｲ ｼｯﾊﾟｲ          (0x15)                              */
 
/*   ﾄｸﾃｲ ﾌﾟﾛｾｽ ｶﾞ PCT ﾆ ﾅｲ      (0x38)                              */
#define  MODKK     0x01                 /* ｹｲｶﾝ ｶﾝｼ                  */
#define  MODSRCVF  0x02                 /* ｼｽﾃﾑ ﾘｶﾊﾞﾘ                */
#define  MODCNSL   0x03                 /* ｺﾝｿｰﾙ ｾｲｷﾞｮ               */
#define  MODIOPRO  0x04                 /* i/o ﾌﾟﾛｾｽ                 */
#define  MODKS     0x05                 /* ｹｲｶﾝ ﾂｳｼﾝ                 */
#define  MODRBI    0x06                 /* RBI ｼｭﾄｸ                  */
#define  MODCMDIP  0x07                 /* ｺﾏﾝﾄﾞ ｲﾝﾀﾌﾟﾘﾀ             */
#define  MODERRP   0x08                 /* 故障管理				     */
#define  MODSUBMS  0x09                 /* sub MS                    */
#define  MODICPPR  0x0A                 /* ICP ﾌﾟﾛｾｽ                 */
#define	 MODMSTPR  0x0B					/* メッセージ中継		TD18 */
#define	 MODMSSPR  0x0C					/* メッセージ制御		TD18 */
#define	 MODMNTPR  0x0D					/* ﾒﾝﾃﾅﾝｽｶｰﾈﾙ			TDxx */
#define	 MODARCV   0x0E					/* 先行リカバリ			TD01 */
#define	 MODL0RCV  0x0F					/* サブシステムリカバリ	TD06 */
#define	 MODDAAPP  0x10					/*	代表ＡＰﾌﾟﾛｾｽ		TD44 */
#define	 MODSERRP  0x11					/*	サブ故障管理		 	 */

/*   ｾﾏﾌｫ ﾉ ｻｸｾｲ ｼｯﾊﾟｲ           (0x1C)                              */
#define  MODPCTAL  0x01                 /* PCT ｾﾞﾝﾀｲ                 */
#define	 MODSSTAL  0x02					/* SST ＳＭＰ日付		TD92 */
 
/*   CM TBL ﾛｰﾄﾞ ｼｯﾊﾟｲ           (0x21)                              */
 
/*   LM TBL ﾛｰﾄﾞ ｼｯﾊﾟｲ           (0x22)                              */
 
/*   ｿｳﾁ ID ﾌｧｲﾙ ﾌﾄｳ             (0x23)                              */
#define  MODCONFIG 0x06                 /* osconfig ｼｯﾊﾟｲ            */
#define  MODFSIZE  0x07                 /* ｿｳﾁ ID ﾌｧｲﾙ ｻｲｽﾞ ﾌﾄｳ      */
#define  MODNLINE  0x08                 /* ｿｳﾁ ID ﾌｧｲﾙ '\n' ﾌﾄｳ      */

/*   ﾃｲｷｮｳ ｶﾝｽｳ ﾉ ﾖﾋﾀﾞｼ ｼｯﾊﾟｲ    (0x2D)                              */
#define  MODFSINT  0x01                 /* mf_sint ｼｯﾊﾟｲ             */
#define  MODRSINT  0x02                 /* mr_sint ｼｯﾊﾟｲ             */
#define  MODTZINT  0x03                 /* mt_zint ｼｯﾊﾟｲ             */
#define  MODTZGSZ  0x04                 /* mt_zgsz ｼｯﾊﾟｲ             */
#define  MODTZTLD  0x05                 /* mt_ztld ｼｯﾊﾟｲ             */
#define  MODTZVLD  0x06                 /* mt_zvld ｼｯﾊﾟｲ             */
#define  MODTZVSV  0x08                 /* mt_zvsv ｼｯﾊﾟｲ             */
#define  MODTZTSV  0x09                 /* mt_ztsv ｼｯﾊﾟｲ             */
#define  MODTZTRM  0x0A                 /* mt_ztrm ｼｯﾊﾟｲ             */
#define  MODFRTGT  0x0B                 /* mf_rtgt ｼｯﾊﾟｲ             */
#define  MODFTOPN  0x0C                 /* mf_topn ｼｯﾊﾟｲ             */
#define  MODFRENQ  0x0D                 /* mf_renq ｼｯﾊﾟｲ             */
#define  MODFRDEQ  0x0E                 /* mf_rdeq ｼｯﾊﾟｲ             */
#define  MODRJEDT  0x0F                 /* mr_jedt ｼｯﾊﾟｲ             */
#define  MODRJNL   0x10                 /* mr_jnl  ｼｯﾊﾟｲ             */
#define  MODDSINT  0x11                 /* md_sint ｼｯﾊﾟｲ             */
#define	 MODMRCRBI 0x12					/* mr_crbi 失敗				 */
#define	 MODMRCJKS 0x13					/* mr_cjks 失敗				 */
#define	 MODMRMINT 0x14					/* mr_mint 失敗	 CT0881		 */
#define	 MODMRMMNT 0x15					/* mr_mmnt 失敗	 CT0881		 */
#define	 MODMRMSPM 0x16					/* mr_mspm 失敗	 CT0881		 */
#define	 MODMRMTBL 0x17					/* mr_mtbl 失敗	 CT0881		 */
#define	 MODMRMJRS 0x18					/* mr_mjrs 失敗	 CT0881		 */
#define	 MODMRMJR2 0x19					/* mr_mjrs2 失敗 CT0881		 */
#define	 MODMRMRVS 0x20					/* mr_mrvs 失敗  CT0881		 */
#define	 MODMRMNRS 0x21					/* mr_mnrs 失敗  CT0881		 */
#define	 MODMRMSLD 0x22					/* mr_msld 失敗  CT0881		 */
#define	 MODMRMSL2 0x23					/* mr_msld2 失敗  CT0881	 */
#define	 MODMRMFSI 0x24					/* mr_mfsi	 失敗  ST3492	 */
#define	 MODMRPINT2	0x25				/* mr_pint2 失敗  ST3699	 */
#define	 MODMRCINS 0x26					/* mr_cins 失敗  ST3754 	 */

/*   ROS ｼﾖｳｶﾞｲﾂｳﾁ ｳｹﾂｹ ﾃﾞ ｲｼﾞﾖｳ (0xE3)                              */
/*                 0x00                  * ｶｲｼ ｼｮﾘ ﾃﾞ ｴﾗ-            */
#define  MODMOOB   0x01                 /* mo_obre ﾃﾞ ｴﾗ-            */
 
/*   ｷｮｳﾖｳ ﾒﾓﾘ ｶｸﾄｸ ｼｯﾊﾟｲ        (0x1E)                              */
#define  MODCMSHM  0x01                 /* CM ﾃﾞ  ｼｯﾊﾟｲ              */
#define  MODLCSHM  0x02                 /* LM ﾃﾞ  ｼｯﾊﾟｲ              */
#define  MODCMNVM  0x03                 /* NVM ﾃﾞ  ｼｯﾊﾟｲ             */
 
/*   ﾃｰﾌﾞﾙ ｾﾝﾄｳ ｱﾄﾞﾚｽ ｼｭﾄｸ ｼｯﾊﾟｲ (0x1F)                              */
 
/*   Table size NG               (0x3B)                              */
/*	 table	None				 (0x3E)					ST1220		 */
#define  MODNGSST  0x01                 /* SST ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGCST  0x02                 /* CST ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGPCT  0x03                 /* PCT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGCMT  0x04                 /* CMT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGTRT  0x05                 /* TRT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGBPT  0x06                 /* BPT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGLMT  0x07                 /* LMT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGSRT  0x08                 /* SRT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGPUT  0x09                 /* PUT ﾃﾞ  ｼｯﾊﾟｲ             */
#define  MODNGSHM  0x0A                 /* SHM ﾃﾞ  ｼｯﾊﾟｲ             */
#define	 MODNGABP  0x0B					/* ABPで失敗			TD10 */
#define	 MODNGNTC  0x0C					/* NTCで失敗			TD12 */
                                                                  /*%*/
/*   ﾊﾞﾂﾌｧ ﾌﾟｰﾙ ﾉ  ｻｸｾｲ ｼｯﾊﾟｲ    (0x18)                              */
 
/*   ﾊﾞﾂﾌｧ ﾌﾟｰﾙ ﾉ  ｶｸﾎ  ｼｯﾊﾟｲ    (0x19)                              */
 
/*   ﾊﾞﾂﾌｧ ﾌﾟｰﾙ ﾉ  ｶｲﾎｳ ｼｯﾊﾟｲ    (0x1A)                              */

/*   ﾊﾞﾂﾌｧ ﾌﾟｰﾙ ﾉ  ｻｸｼﾞｮ ｼｯﾊﾟｲ   (0x1B)                              */
#define  MODPBVCT  0x01                 /* ﾍﾞｸﾀ ﾃｰﾌﾞﾙ ﾖｳ             */
#define  MODPBER   0x02                 /* ｼｮｳｶﾞｲ ﾂｳﾁ ﾖｳ             */
#define  MODSMPF   0x03                 /* SMP ｼｽﾃﾑ ﾌｧｲﾙ   ﾖｳ        */
#define  MODPBCM   0x04                 /* ｲｯﾊﾟﾝ ﾊﾞﾂﾌｧ CM ﾖｳ         */
#define  MODPBLM   0x05                 /* ｲｯﾊﾟﾝ ﾊﾞﾂﾌｧ LM ﾖｳ         */

/*   ﾒｲﾙ ﾎﾞｯｸｽ ﾉ ｻｸｾｲ  ｼｯﾊﾟｲ     (0x16)                              */

/*   ﾒｲﾙ ﾎﾞｯｸｽ ﾉ ｻｸｼﾞｮ ｼｯﾊﾟｲ     (0x17)                              */
#define  MODFXMBM  0x01                 /* ｺﾃｲ ﾒｲﾙ ﾎﾞｯｸｽ(ﾏｽﾀ.ｽｹｼﾞｭｰﾗ)*/
#define  MODFXMBA  0x02                 /* ｺﾃｲ ﾒｲﾙ ﾎﾞｯｸｽ(ｹｲｶﾝ ｶﾝｼ   )*/
#define  MODFXMBK  0x03                 /* ｺﾃｲ ﾒｲﾙ ﾎﾞｯｸｽ(ｹｲｶﾝ ﾂｳｼﾝ  )*/
#define  MODROSMB  0x04                 /* ｼｮｳｶﾞｲ ﾂｳﾁ ﾖｳ             */
#define  MODPROMB  0x05                 /* ｲｯﾊﾟﾝ ﾌﾟﾛｾｽ ﾖｳ (msg)      */
#define  MODMRHKMB 0x06					/* SMP通知保留用		TD44 */

/*   ﾊﾟﾗﾒｰﾀ ﾉ ｴﾗ-                (0x72)                              */
#define  MODPRCNT  0x01                 /* ﾊﾟﾗﾒｰﾀ ﾉ ｺｽｳ ｶﾞ ﾌﾄｳ       */
#define  MODPRMNG  0x02                 /* ﾊﾟﾗﾒｰﾀ ﾉ ﾅｲﾖｳ ｶﾞ ﾌﾄｳ      */

#define  MODASGTP  0x01                 /* osgtpin ﾉ ｼｯﾊﾟｲ           */
#define  MODASPCT  0x02                 /* PCT ｾﾝﾄｳ ｱﾄﾞﾚｽ ｼｭﾄｸ ｼｯﾊﾟｲ */

/*   sub MS ｶﾗﾉ ﾂｳﾁ ﾏﾁ time out  (0x4E)                              */
#define  MODSMINT  0x01                 /* ｼｮｷ ｶﾝﾘｮｳ ﾂｳﾁ             */

/*	経路開設失敗													 */
#define	 MOPATHOP  0x01					/*	ospathopnで失敗		TD01 */

/*	開始区分書き換えに失敗		(0x3F)								 */
#define	 MORRBI	   0x01					/*	RBI故障		CT0696		 */
#define	 MORJNL	   0x02					/*	JNL故障		CT0696		 */
#define	 MORSRV	   0x03					/*	SRCV		CT0696		 */
#define	 MORFIN	   0x04					/*	完了時書き戻し CT0696	 */
#define	 MOTBOK	   0x05					/*	ﾃｰﾌﾞﾙ復旧時 SSCY0074	 */
/*********************************************************************/
/*    ｼｮｳｻｲ ｺｰﾄﾞ                                                     */
/*********************************************************************/
 
#define  MOPCMACP  0x06                 /* ｺﾏﾝﾄﾞ ｳｹﾂｹ                */
#define  MOPCMANL  0x07                 /* ｺﾏﾝﾄﾞ ｶｲｾｷ                */
#define  MOPCMEXC  0x08                 /* ｺﾏﾝﾄﾞ ｼﾞｯｺｳ               */
#define  MOPTMCTL  0x09                 /* ﾄｷ ｷﾄﾞｳ ｾｲｷﾞｮ             */

#define  MODCECR2  0x01                 /* mo_cecr ﾉ ﾀﾞｲ2 ﾊﾟﾗﾒ-ﾀ CM  */
#define  MODCECR3  0x02                 /* mo_cecr ﾉ ﾀﾞｲ3 ﾊﾟﾗﾒ-ﾀ CM  */
#define  MODCESP2  0x03                 /* mo_cesp ﾉ ﾀﾞｲ2 ﾊﾟﾗﾒ-ﾀ CM  */
#define  MODCECK   0x04                 /* mo_ceck ﾉ ﾊﾟﾗﾒ-ﾀ      CM  */
#define  MODCRMP   0x05                 /* mo_crmp ﾉ ﾊﾟﾗﾒ-ﾀ      CM  */

#define  MODCMGM   0x0a                 /* mo_cmgm ﾉ ﾊﾟﾗﾒ-ﾀ      CM  */
#define  MODCMGM2  0x0b                 /* mo_cmgm ﾉ ﾊﾟﾗﾒ-ﾀ      CM  */

/*********************************************************************/
/*    ｱﾎﾞ-ﾄ ｺ-ﾄﾞ                                                     */
/*********************************************************************/

#define  MOAKK040  0x1140               /* argc != 40(ﾊﾟﾗﾒ-ﾀ ｺｽｳ NG) */
														/*	TD00	 */
#define  MOAKK041  0x1141               /* argv(トリガ有無) NG  TD00 */
#define  MOAKK042  0x1142               /* argv(ﾌﾞﾛｯｸ区分) NG   TD00 */
#define  MOAKK043  0x1143               /* argv(ﾄﾞｳｷﾏﾁ ｼﾞｶﾝ)NG		 */
										/* レスポンス待ち時間 NG TD00*/
#define  MOAKK044  0x1144               /* argv(ﾌﾟﾛｸﾞﾗﾑﾓｰﾄﾞ) NG      */
#define  MOAKK045  0x1145               /* argv(ﾒｲﾙﾎﾞｯｸｽID) NG TD00  */
#define  MOAKK046  0x1146               /* argv(ｼｽﾃﾑ ｺｳｾｲ)NG		 */
#define  MOAKK047  0x1147               /* 起動区分異常			TD00 */
#define  MOAKK048  0x1148               /*ﾒﾂｾ-ｼﾞ ｼﾞﾕｼﾝﾖｳｷﾕｳ(osrcvmsr)*/
#define  MOAKK049  0x1149               /* ｲﾝﾀﾊﾞﾙﾀｲﾏ ｾﾂﾄ(ossttim)    */
#define  MOAKK04A  0x114A               /* osconn返却値異常		TD00 */
#define  MOAKK04B  0x114B               /* ﾌﾄｸﾃｲ ﾘｻﾞﾙﾄ ｼﾞﾕｼﾝ(osanyrl)*/
#define  MOAKK04C  0x114C               /* ﾒﾂｾ-ｼﾞ ｿｳｼﾝ(ossenms)      */
#define  MOAKK14D  0x114D               /* osioctl返却値異常	TD00 */
#define  MOAKK14E  0x114E               /* ﾋｶﾝﾘﾖｳﾖｳｷﾕｳ ﾄﾘｹｼ(oscanrq) */
#define  MOAKK14F  0x114F               /* osdconn返却値異常	TD00 */
#define  MOAKK150  0x1150               /* ｲﾝﾀﾊﾞﾙﾀｲﾏ ｾﾂﾄ(ossttim)    */
#define  MOAKK151  0x1151				/* 特定ﾘｻﾞﾙﾄ受信異常	TD00 */
#define  MOAKK152  0x1152				/* 例外ハンドラ設定異常 TD00 */
#define  MOAKK153  0x1153				/* 例外ハンドラから終了  TD00*/
#define  MOAKK254  0x1154               /* acms: MSﾍﾉ ossenms ｼｯﾊﾟｲ  */
#define  MOAKK155  0x1155               /* argv(ｿｳﾁ ﾊﾞﾝｺﾞｳ) NG       */
#define  MOAKK156  0x1156               /* 前回終了日付／時刻 NG TD00*/
#define  MOAKK157  0x1157				/* ｿｳﾁ ﾊﾞﾝｺﾞｳ ﾍｷｻ ﾍﾝｶﾝ NG	 */
#define  MOAKK158  0x1158				/* ﾘｸｴｽﾄ ｼｷﾍﾞﾂｼ ﾌﾄｳ			 */ 
#define  MOAKK159  0x1159				/* ｽﾃｰﾀｽ ﾌﾄｳ	   			 */ 
#define  MOAKK16A  0x116A				/* ﾃﾞﾝﾌﾞﾝ ｼｷﾍﾞﾂｼ ﾌﾄｳ		 */
#define  MOAKK16B  0x116B				/* 処理コード不当		TD00 */
#define  MOAKK16C  0x116C				/* KKREVCHK: ossleep ｼｯﾊﾟｲ	 */
#define  MOAKK16D  0x116D				/* KKREVCHK: ossenms ｼｯﾊﾟｲ	 */
#define  MOAKK16E  0x116E				/* osopen ﾍﾝｷｬｸﾁ異常 CT1099	 */


#define  MOAAS040  0x1340               /* ﾌﾟﾛｾｽ ｼﾞﾖｳﾎｳ ｼﾕﾄｸ(osgtpin)*/
#define  MOAAS041  0x1341               /* ｷﾖｳﾖｳﾒﾓﾘ ﾏﾂﾋﾟﾝｸﾞ(osatshm) */
#define  MOAAS042  0x1342               /* PCTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS043  0x1343               /* LMTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS044  0x1344               /* ｾﾏﾌｵ ｼﾝｺﾞｳﾏﾁ(oswaitsp)    */
#define  MOAAS045  0x1345               /* PCT ｶﾞｲﾄｳｺﾍﾞﾂﾌﾞ ﾅｼ        */
#define  MOAAS046  0x1346               /* SSTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS047  0x1347               /* CSTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS048  0x1348               /* BPTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS049  0x1349               /* SRTｱﾄﾞﾚｽ ｼﾕﾄｸ ﾌﾉｳ         */
#define  MOAAS04A  0x134A               /* RCV ｼﾖｷｶｼﾖﾘ ｲｼﾞﾖｳ         */
#define  MOAAS04B  0x134B               /* FIP ｼﾖｷｶｼﾖﾘ ｲｼﾞﾖｳ         */
#define  MOAAS04C  0x134C               /* DCP ｼﾖｷｶｼﾖﾘ ｲｼﾞﾖｳ         */
#define  MOAAS04D  0x134D               /* ｾﾏﾌｵ ｼﾝｺﾞｳｿｳｼﾝ(ossigsp)   */
#define  MOAAS04E  0x134E               /* DCP ﾌﾟﾛｾｽ ｼﾕｳﾘﾖｳｼﾖﾘ ｲｼﾞﾖｳ */
#define  MOAAS04F  0x134F               /* FIP ﾌﾟﾛｾｽ ｼﾕｳﾘﾖｳｼﾖﾘ ｲｼﾞﾖｳ */
#define  MOAAS050  0x1350               /* RCV ﾌﾟﾛｾｽ ｼﾕｳﾘﾖｳｼﾖﾘ ｲｼﾞﾖｳ */
#define  MOAAS051  0x1351               /* invalid ｷｮｳﾖｳ ﾒﾓﾘ id      */
#define  MOAAS052  0x1352               /* invalid table address     */
#define  MOAAS053  0x1353               /* ｾﾏﾌｫ ｼﾝｺﾞｳ ｿｳｼﾝ(ossigsp)  */
#define  MOAAS054  0x1354               /* argc < 3                  */
#define  MOAAS055  0x1355               /* osatshm ｼｯﾊﾟｲ( LM )       */
#define  MOAAS056  0x1356               /* osatshm ｼｯﾊﾟｲ( NVM)       */
#define  MOAAS057  0x1357				/* TABPｱﾄﾞﾚｽ取得不能	TD10 */
#define	 MOAAS058  0x1358				/* ossnsmsで失敗		TD10 */
#define  MOAAS059  0x1359				/* osrcvmsで失敗		TD10 */
#define	 MOAAS060  0x1360				/* osstpiriで失敗		TD02 */
#define	 MOAAS061  0x1361				/* ossleepで失敗		TD02 */
#define	 MOAAS062  0x1362				/* TNTCｱﾄﾞﾚｽ取得不能	TD12 */
#define	 MOAAS063  0x1363				/* TCMTｱﾄﾞﾚｽ取得不能	TD12 */
										/* 				ST0118 (SM00)*/
#define  MOAAS064  0x1364               /* RMS ｼﾖｷｶｼﾖﾘ ｲｼﾞﾖｳ    SM00 */
#define  MOAAS065  0x1365               /*TOOL ｼﾖｷｶｼﾖﾘ ｲｼﾞﾖｳ    SM00 */
#define  MOAAS066  0x1366               /* RMS ﾌﾟﾛｾｽ ｼﾕｳﾘﾖｳｼﾖﾘ ｲｼﾞﾖｳSM00*/
#define  MOAAS067  0x1367               /*TOOL ﾌﾟﾛｾｽ ｼﾕｳﾘﾖｳｼﾖﾘ ｲｼﾞﾖｳSM00*/
#define  MOAAS068  0x1368               /* mr_pint2で失敗		CT0881*/
#define  MOAAS069  0x1369				/* osrcvmspで失敗   PRC-008-08*/
#define  MOAAS070  0x1370				/* peapmainから異常復帰   PRC-014-01 */

/*    to mo_sbms.c													 */
#define  MOASB001  0x1501               /* パラメータ個数異常	TD00 */
#define  MOASB002  0x1502               /* 欠番					TD06 */
#define  MOASB003  0x1503               /* ﾌﾟﾛｾｽ情報取得失敗(osgtpin)TD00*/
#define  MOASB004  0x1504               /* Ｐｕ番号不当			TD00 */
#define  MOASB005  0x1505               /* 共用ﾒﾓﾘ識別子変換異常TD00 */
#define  MOASB006  0x1506               /* ﾃｰﾌﾞﾙ先頭ｱﾄﾞﾚｽ変換異常TD00*/
#define  MOASB007  0x1507               /* 共用ﾒﾓﾘｱﾀｯﾁ失敗(osatshm)TD00*/
#define  MOASB008  0x1508               /* PCT先頭ｱﾄﾞﾚｽ取得失敗 TD00 */
#define  MOASB009  0x1509               /* SST先頭ｱﾄﾞﾚｽ取得失敗 TD00 */
#define  MOASB00A  0x150A               /* LMT先頭ｱﾄﾞﾚｽ取得失敗 TD00 */
#define  MOASB00B  0x150B               /* ﾒｯｾｰｼﾞ受信要求失敗(osrcvmsr)TD00*/
#define  MOASB00C  0x150C               /* 不特定ﾘｻﾞﾙﾄ受信失敗(osanyrl)TD00*/
#define  MOASB00D  0x150D               /* ﾒｯｾｰｼﾞ受信要求再度失敗(osrcvmsr)TD00*/
#define  MOASB00E  0x150E               /* ﾃｰﾌﾞﾙﾌｧｲﾙｱﾀｯﾁ失敗(mt_zint)TD00*/
#define  MOASB00F  0x150F               /* ﾍﾞｸﾀﾃｰﾌﾞﾙ展開ｻｲｽﾞ取得失敗(mt_zgsz)TD00*/
#define  MOASB010  0x1510               /* ﾌｧｲﾙ状態異常(mt_zgsz)TD00 */
#define  MOASB011  0x1511               /* LMﾊﾞｯﾌｧﾌﾟｰﾙ作成失敗(oscrelbp)TD00*/
#define  MOASB012  0x1512               /* ﾌﾟｰﾙﾊﾞｯﾌｧ確保失敗(osgtpbf)TD00*/
#define  MOASB013  0x1513               /* ﾍﾞｸﾀﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ不可)(mt_zvld)TD00*/
#define  MOASB014  0x1514               /* ﾍﾞｸﾀﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ失敗)(mt_zvld)TD00*/
#define  MOASB015  0x1515               /* ﾍﾞｸﾀﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ不可)(mt_zgsz&mt_zvld)TD00*/
#define  MOASB016  0x1516               /* 共用ﾒﾓﾘ確保失敗(osgtpbf)TD00*/
#define  MOASB017  0x1517               /* ﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ不可)(mt_ztld)TD00*/
#define  MOASB018  0x1518               /* ﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ不可)(mt_zgsz&mt_ztld)TD00*/
#define  MOASB019  0x1519               /* ﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ失敗)(mt_zvld)TD00*/
#define  MOASB01A  0x151A               /* ﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ失敗)(mt_ztld)TD00*/
#define  MOASB01B  0x151B               /* ﾃｰﾌﾞﾙ展開失敗(ﾘﾄﾗｲ不可)(mt_zvld)TD00*/
#define  MOASB01C  0x151C               /* ﾒｯｾｰｼﾞ送信異常(ossenms)TD00*/
#define  MOASB01D  0x151D				/* SHM先頭ｱﾄﾞﾚｽ取得失敗 TD59 */
#define  MOASB01E  0x151E				/* PUT先頭ｱﾄﾞﾚｽ取得失敗 TD59 */
#define  MOASB01F  0x151F				/* BPT先頭ｱﾄﾞﾚｽ取得失敗 TD59 */
#define  MOASB020  0x1520				/* ABP先頭ｱﾄﾞﾚｽ取得失敗 TD10 */
#define  MOASB021  0x1521				/* CST先頭ｱﾄﾞﾚｽ取得失敗 TD59 */
#define  MOASB022  0x1522				/* 例外ハンドラ登録失敗	TD59 */
#define  MOASB023  0x1523				/* 例外ﾊﾝﾄﾞﾗからの終了	TD59 */
#define  MOASB024  0x1524				/* ﾊﾞｯﾌｧﾌﾟｰﾙ作成失敗(oscrecbp)TD59*/
#define  MOASB025  0x1525				/* ﾊﾞｯﾌｧﾌﾟｰﾙ作成失敗(oscrelbp)TD59*/
#define  MOASB026  0x1526				/* SRT先頭ｱﾄﾞﾚｽ取得失敗 TD59 */
#define  MOASB027  0x1527				/* ﾊﾞｯﾌｧﾌﾟｰﾙ削除失敗:TBPT:CM(osdelbp)TD59*/
#define  MOASB028  0x1528				/* ﾊﾞｯﾌｧﾌﾟｰﾙ削除失敗:TBPT:LM(osdelbp)TD59*/
#define  MOASB029  0x1529				/* ﾊﾞｯﾌｧﾌﾟｰﾙ削除失敗:TABP:CM(osdelbp)TD59*/
#define  MOASB02A  0x152A				/* ﾊﾞｯﾌｧﾌﾟｰﾙ削除失敗:TABP:LM(osdelbp)TD59*/
#define  MOASB02B  0x152B				/* ＬＭテーブル無し		TD59 */
#define  MOASB02C  0x152C				/* FIPｼｽﾃﾑ初期化失敗	TD59 */
#define  MOASB02D  0x152D				/* DCPｼｽﾃﾑ初期化失敗	TD59 */
#define  MOASB02E  0x152E				/* RCVｼｽﾃﾑ初期化失敗	TD59 */
#define  MOASB02F  0x152F				/* LMﾃｰﾌﾞﾙ退避時に採用ファイルが無いTD59*/
#define  MOASB030  0x1530				/* LMﾃｰﾌﾞﾙ退避失敗(mt_ztsv)TD59*/
#define  MOASB031  0x1531				/* ﾍﾞｸﾀﾃｰﾌﾞﾙ退避失敗(mt_zvsv)TD59*/

/*********************************************************************/
/*    ﾃｲｷｮｳ ｶﾝｽｳ  ﾀﾞｳﾝ ｺｰﾄﾞ											 */
/*********************************************************************/

#define  MOTAGT    0x1480				/* mo_tagt ｼｯﾊﾟｲ (mo_jpct)   */
#define  MODCREMB  0x1481				/* oscremb ｼｯﾊﾟｲ (mo_jpct)   */
#define  MORIPL    0x14FF               /* mo_ripl ﾉ ﾊﾟﾗﾒ-ﾀ (mo_sipl)*/

/*********************************************************************/
/*    final code ( osdespr )                                         */
/*********************************************************************/

#define  MODESRQD  0x1600               /* ｷｮｳｾｲ ｼｭｳﾘｮｳ ﾖｳｷｭｳ        */
#define  MODESRQA  0x1601               /* 強制終了要求(ｱﾎﾞｰﾄ指示)	 */
										/*					SSCY0197 */

/*********************************************************************/
/*    down code ( mo_term.)                                          */
/*********************************************************************/

#define  MODPGMD   0x1701               /* mo_pgmd ｼｯﾊﾟｲ             */
#define  MODCHGAC  0x1705               /* ｹｲ ｷﾘｶｴ                   */
#define  MODSTATX  0x1706               /* invalid end type          */
#define  MODGTPIN  0x17FE               /* osgtpin ｼｯﾊﾟｲ             */
#define  MODMSPU   0x17FF               /* MS pu ﾊﾞﾝｺﾞｳ ﾌﾄｳ          */

										/*				CT0559		 */
/*********************************************************************/
/*	mo_apdt	abort	code											 */
/*********************************************************************/
#define		MOAPDT	0x142b				/*	モジュールＩＤ			 */

#define		APDTPCAER	0x24000000		/*	ＰＣＡステータス操作失敗 */
#define		APDTRDQER	0x2F000000		/*	TSRT資源占有解除失敗	 */

/* TBCS0083 Start */
/*********************************************************************/
/*	moa	 dwncode( os_InitSystem 発行前 )			TBCS0083		 */
/*********************************************************************/
/*　カレントディレクトリ変更(chdir)失敗 障害情報 */
#define 	MOADWNCHDIR	0x01			/* 環境変数取得あり	TBCS0083 */
#define		MOADWNCHCOM	0x02			/* 環境変数取得なし TBCS0083 */

/* TBCS0083 End */
