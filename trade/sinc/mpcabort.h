/**********************************************************************/
/* ﾌｧｲﾙ名　：　mpbabort.h											  */
/* 機能　　：  ｱﾎﾞｰﾄ詳細情報上1ﾊﾞｲﾄ 								  */
/*			   ﾌﾟﾛｾｽｱﾎﾞｰﾄﾏｸﾛ										  */
/* 作成日　：  1992.01.07											  */
/* 更新日　：  2002.12.10										 M01  */
/**********************************************************************/
/**************************************/
/* ｱﾎﾞｰﾄ詳細情報上1ﾊﾞｲﾄ 			  */
/**************************************/

/**************************************/
/* 使用しないコード					  */
/* (H'00〜H'0f)						  */
/**************************************/

/**************************************/
/* 論理エラー						  */
/* (H'10〜H'3f)						  */
/**************************************/
#define ABTLMTX0	0x10				/* マトリクス矛盾（回線制御）		*/
#define ABTLMTX1	0x11				/* マトリクス矛盾（論理パス制御）	*/
#define ABTLMTX2	0x12				/* マトリクス矛盾（ｺﾈｸｼｮﾝ制御） 	*/
#define ABTLMSE1	0x13				/* ﾏﾄﾘｸｽ同期矛盾（回線〜論理ﾊﾟｽ）	*/
#define ABTLMSE2	0x14				/* ﾏﾄﾘｸｽ同期矛盾（論理ﾊﾟｽ〜ｺﾈｸｼｮﾝ） */
#define ABTLSNMP	0x20				/* ossenmsp()異常					*/
#define ABTLSNMS	0x21				/* ossnsms()異常					*/
#define ABTLOSCN	0x22				/* osconn()異常 					*/
#define ABTLFINF	0x23				/* osgfinf()異常					*/
#define ABTLOPEN	0x24				/* osopen()異常 					*/
#define ABTLSFLG	0x25				/* osiioctl(NETCTL:ﾈｯﾄﾜｰｸﾌﾗｸﾞ登録) 	*/
										/* 異常								*/
#define ABTLSMSK	0x26				/* osiioctl(NETCTL:ｻﾌﾞﾈｯﾄﾏｽｸ登録)異 */
										/* 常								*/
#define ABTLSIPA	0x27				/* osiioctl(NETCTL:ﾛｰｶﾙｱﾄﾞﾚｽ登録)異 */
										/* 常								*/
#define ABTLATCH	0x28				/* osiioctl(ATTACH)異常 			*/
#define ABTLBIND	0x29				/* osiioctl(BIND)異常				*/
#define ABTLLIST	0x2a				/* osiioctl(LISTEN)異常 			*/
#define ABTLACPT	0x2b				/* osiioctl(ACCEPT)異常 			*/
#define ABTLASYN	0x2c				/* osiioctl(非同期通知要求)異常 	*/
#define ABTLDECH	0x2d				/* osiioctl(DETACH)異常 			*/
#define ABTLABOT	0x2e				/* osiioctl(ABORT)異常				*/
#define ABTLDCON	0x2f				/* osiioctl(DISCONNECT)異常 		*/
#define ABTLCONN	0x30				/* osiioctl(CONNECT)異常			*/
#define ABTLSOPT	0x31				/* osiioctl(SETOPT)異常 			*/
#define ABTLSOOB	0x32				/* osiioctl(SENDOOB)異常			*/
#define ABTLROOB	0x33				/* osiioctl(RCVOOB)異常 			*/
#define ABTLREAD	0x34				/* osireadd異常 					*/
#define ABTLWRTD	0x35				/* osiwritd異常 					*/
#define ABTLGTNM	0x36				/* uname異常					M01	*/
#define ABTLGTIP	0x37				/* gethostbyname異常			M01	*/

/**************************************/
/* パラメータ・エラー				  */
/* (H'40〜H'7f)						  */
/**************************************/
#define ABTINVSG	0x40				/* SG値不正 						*/

/**************************************/
/* 資格・同期エラー					  */
/* (H'80〜H'9f)						  */
/**************************************/

/**************************************/
/* ハードエラー						  */
/* (H'a0〜H'cf)						  */
/**************************************/

/**************************************/
/* 資源不足エラー					  */
/* (H'd0〜H'df)						  */
/**************************************/

/**************************************/
/* その他のエラー					  */
/* (H'e0〜H'ff)						  */
/**************************************/
#define ABTOGABF	0xe4				/* サービスコール異常(mo_gabf)　	*/
#define ABTONCLR	0xe5				/* サービスコール異常(mo_nclr)　	*/
#define ABTOFBF0	0xe6				/* サービスコール異常(mo_frbf)　	*/
#define ABTOLINF	0xe7				/* サービスコール異常(mi_lstat)　	*/

/**************************************/
/* モジュールＩＤ					  */
/**************************************/
#define MID_EX 		0x74ff0000			/* ｲﾍﾞﾝﾄ異常				  */

#define STATEVNT(P1, P2)	((long)P1<<16)|(0x0000ffff&P2)
#define ABT_NULL	 0x0				
/**************************************/
/*									  */
/**************************************/
#define AD_RESLT	 0x00000000 		/* システムコール返却値異常 		*/
										/* （リザルト値異常）				*/
#define AD_SYSRD	 0x00000001 		/* システムコール返却値異常 		*/
										/* （ｒｄ値異常）					*/
#define AD_LMBUF	 0x00010000 		/* 回線制御コンテキスト 			*/
#define AD_PMBUF	 0x00010001 		/* 論理パス制御コンテキスト 		*/
#define AD_CMBUF	 0x00010002 		/* コネクション制御コンテキスト 	*/
#define AD_MCOM0	 0x00010002 		/* 通信制御メッセージ           	*/
#define AD_MCOM1(P1) (0x00000000 | (((MPCRQMSG *)P1)->usr.mpcococd << 8 )	  \
	| (((MPCRQMSG *)P1)->usr.mpcotype) )/* 通信制御メッセージ          		*/
#define AD_MICP0	 0x00001003 		/* ＩＣＰメッセージ           		*/
#define AD_MOCP0	 0x00001004 		/* ＯＣＰメッセージ           		*/
#define AD_MICP1	 0x00001003 		/* ＩＣＰメッセージ           		*/
#define AD_MOCP1	 0x00001004 		/* ＯＣＰメッセージ           		*/
#define AD_MOTHR	 0x00001004 		/* ＭＩＡ不正メッセージ           	*/
/**************************************/
/* モジュールＩＤ（拡張）			  */
/**************************************/
#define MPC00001	0x0001		  		/* mpc00001() のﾓｼﾞｭｰﾙID			*/
#define MPC00002	0x0002		  		/* mpc00002() のﾓｼﾞｭｰﾙID			*/
#define MPC00003	0x0003		  		/* mpc00003() のﾓｼﾞｭｰﾙID			*/
#define MPC00004	0x0004		  		/* mpc00004() のﾓｼﾞｭｰﾙID			*/
#define MPC00005	0x0005		  		/* mpc00005() のﾓｼﾞｭｰﾙID			*/

#define MPC100XX	0x1000		  		/* mpc100xx() のﾓｼﾞｭｰﾙID			*/
#define MPC10000	0x1001		  		/* mpc10000() のﾓｼﾞｭｰﾙID			*/
#define MPC101XX	0x1080		  		/* mpc101xx() のﾓｼﾞｭｰﾙID			*/
#define MPC10100	0x1081		  		/* mpc10100() のﾓｼﾞｭｰﾙID			*/
#define MPC10101	0x1082		  		/* mpc10101() のﾓｼﾞｭｰﾙID			*/
#define MPC10102	0x1083		  		/* mpc10102() のﾓｼﾞｭｰﾙID			*/
#define MPC102XX	0x1100		  		/* mpc102xx() のﾓｼﾞｭｰﾙID			*/
#define MPC103XX	0x1180		  		/* mpc103xx() のﾓｼﾞｭｰﾙID			*/

#define MPC200XX	0x2000		  		/* mpc200xx() のﾓｼﾞｭｰﾙID			*/
#define MPC20000	0x2001		  		/* mpc20000() のﾓｼﾞｭｰﾙID			*/
#define MPC20001	0x2002		  		/* mpc20001() のﾓｼﾞｭｰﾙID			*/
#define MPC20002	0x2003		  		/* mpc20002() のﾓｼﾞｭｰﾙID			*/

#define MPC300XX	0x3000		  		/* mpc300xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30000	0x3001		  		/* mpc30000() のﾓｼﾞｭｰﾙID			*/

#define MPC301XX	0x3080		  		/* mpc301xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30102	0x3081		  		/* mpc30102() のﾓｼﾞｭｰﾙID			*/
#define MPC30104	0x3082		  		/* mpc30104() のﾓｼﾞｭｰﾙID			*/

#define MPC302XX	0x3100		  		/* mpc302xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30211	0x3101		  		/* mpc30211() のﾓｼﾞｭｰﾙID			*/
#define MPC30212	0x3102		  		/* mpc30212() のﾓｼﾞｭｰﾙID			*/
#define MPC30213	0x3103		  		/* mpc30213() のﾓｼﾞｭｰﾙID			*/

#define MPC303XX	0x3180		  		/* mpc303xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30301	0x3181		  		/* mpc30301() のﾓｼﾞｭｰﾙID			*/
#define MPC30302	0x3182		  		/* mpc30302() のﾓｼﾞｭｰﾙID			*/
#define MPC30303	0x3183		  		/* mpc30303() のﾓｼﾞｭｰﾙID			*/
#define MPC30304	0x3184		  		/* mpc30304() のﾓｼﾞｭｰﾙID			*/

#define MPC304XX	0x3200		  		/* mpc304xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30402	0x3201		  		/* mpc30402() のﾓｼﾞｭｰﾙID			*/
#define MPC30408	0x3202		  		/* mpc30408() のﾓｼﾞｭｰﾙID			*/
#define MPC30410	0x3203		  		/* mpc30410() のﾓｼﾞｭｰﾙID			*/

#define MPC305XX	0x3280		  		/* mpc305xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30502	0x3281		  		/* mpc30502() のﾓｼﾞｭｰﾙID			*/
#define MPC30505	0x3282		  		/* mpc30505() のﾓｼﾞｭｰﾙID			*/
#define MPC30510	0x3283		  		/* mpc30510() のﾓｼﾞｭｰﾙID			*/

#define MPC306XX	0x3300		  		/* mpc306xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30602	0x3301		  		/* mpc30602() のﾓｼﾞｭｰﾙID			*/
#define MPC30607	0x3302		  		/* mpc30607() のﾓｼﾞｭｰﾙID			*/
#define MPC30610	0x3303		  		/* mpc30610() のﾓｼﾞｭｰﾙID			*/

#define MPC307XX	0x3380		  		/* mpc307xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30704	0x3381		  		/* mpc30704() のﾓｼﾞｭｰﾙID			*/
#define MPC30706	0x3382		  		/* mpc30706() のﾓｼﾞｭｰﾙID			*/
#define MPC30708	0x3383		  		/* mpc30708() のﾓｼﾞｭｰﾙID			*/

#define MPC308XX	0x3400		  		/* mpc308xx() のﾓｼﾞｭｰﾙID			*/
#define MPC30802	0x3401		  		/* mpc30802() のﾓｼﾞｭｰﾙID			*/
#define MPC30803	0x3402		  		/* mpc30803() のﾓｼﾞｭｰﾙID			*/
#define MPC30810	0x3403		  		/* mpc30810() のﾓｼﾞｭｰﾙID			*/

#define MPC400XX	0x4000		  		/* mpc400xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40000	0x4001		  		/* mpc40000() のﾓｼﾞｭｰﾙID			*/

#define MPC401XX	0x4080		  		/* mpc401xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40101	0x4081		  		/* mpc40101() のﾓｼﾞｭｰﾙID			*/
#define MPC40102	0x4082		  		/* mpc40102() のﾓｼﾞｭｰﾙID			*/
#define MPC40104	0x4083		  		/* mpc40104() のﾓｼﾞｭｰﾙID			*/
#define MPC40105	0x4084		  		/* mpc40105() のﾓｼﾞｭｰﾙID			*/
#define MPC40106	0x4085		  		/* mpc40106() のﾓｼﾞｭｰﾙID			*/
#define MPC40108	0x4086		  		/* mpc40108() のﾓｼﾞｭｰﾙID			*/
#define MPC40109	0x4087		  		/* mpc40109() のﾓｼﾞｭｰﾙID			*/
#define MPC40110	0x4088		  		/* mpc40110() のﾓｼﾞｭｰﾙID			*/
#define MPC40111	0x4089		  		/* mpc40111() のﾓｼﾞｭｰﾙID			*/
#define MPC40112	0x408a		  		/* mpc40112() のﾓｼﾞｭｰﾙID			*/
#define MPC40113	0x408b		  		/* mpc40113() のﾓｼﾞｭｰﾙID			*/
#define MPC40115	0x408c		  		/* mpc40115() のﾓｼﾞｭｰﾙID			*/
#define MPC40118	0x408d		  		/* mpc40118() のﾓｼﾞｭｰﾙID			*/

#define MPC402XX	0x4100		  		/* mpc402xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40206	0x4101		  		/* mpc40206() のﾓｼﾞｭｰﾙID			*/

#define MPC403XX	0x4180		  		/* mpc403xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40306	0x4181		  		/* mpc40306() のﾓｼﾞｭｰﾙID			*/

#define MPC404XX	0x4200		  		/* mpc404xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40404	0x4201		  		/* mpc40404() のﾓｼﾞｭｰﾙID			*/

#define MPC405XX	0x4280		  		/* mpc405xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40511	0x4281		  		/* mpc40511() のﾓｼﾞｭｰﾙID			*/

#define MPC406XX	0x4300		  		/* mpc406xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40604	0x4301		  		/* mpc40604() のﾓｼﾞｭｰﾙID			*/

#define MPC407XX	0x4380		  		/* mpc407xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40704	0x4381		  		/* mpc40704() のﾓｼﾞｭｰﾙID			*/
#define MPC40705	0x4382		  		/* mpc40705() のﾓｼﾞｭｰﾙID			*/
#define MPC40706	0x4383		  		/* mpc40706() のﾓｼﾞｭｰﾙID			*/
#define MPC40708	0x4384		  		/* mpc40708() のﾓｼﾞｭｰﾙID			*/

#define MPC408XX	0x4400		  		/* mpc408xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40805	0x4401		  		/* mpc40805() のﾓｼﾞｭｰﾙID			*/
#define MPC40806	0x4402		  		/* mpc40806() のﾓｼﾞｭｰﾙID			*/
#define MPC40808	0x4403		  		/* mpc40808() のﾓｼﾞｭｰﾙID			*/
#define MPC40809	0x4404		  		/* mpc40809() のﾓｼﾞｭｰﾙID			*/

#define MPC409XX	0x4480		  		/* mpc409xx() のﾓｼﾞｭｰﾙID			*/
#define MPC40901	0x4481		  		/* mpc40901() のﾓｼﾞｭｰﾙID			*/
#define MPC40905	0x4482		  		/* mpc40905() のﾓｼﾞｭｰﾙID			*/
#define MPC40906	0x4483		  		/* mpc40906() のﾓｼﾞｭｰﾙID			*/
#define MPC40908	0x4484		  		/* mpc40908() のﾓｼﾞｭｰﾙID			*/
#define MPC40909	0x4485		  		/* mpc40909() のﾓｼﾞｭｰﾙID			*/

#define MPC410XX	0x4500		  		/* mpc410xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41006	0x4501		  		/* mpc41006() のﾓｼﾞｭｰﾙID			*/

#define MPC411XX	0x4580		  		/* mpc411xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41106	0x4581		  		/* mpc41106() のﾓｼﾞｭｰﾙID			*/

#define MPC412XX	0x4600		  		/* mpc412xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41206	0x4601		  		/* mpc41206() のﾓｼﾞｭｰﾙID			*/

#define MPC413XX	0x4680		  		/* mpc413xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41306	0x4681		  		/* mpc41306() のﾓｼﾞｭｰﾙID			*/

#define MPC414XX	0x4700		  		/* mpc414xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41406	0x4701		  		/* mpc41406() のﾓｼﾞｭｰﾙID			*/

#define MPC415XX	0x4780		  		/* mpc415xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41502	0x4781		  		/* mpc41502() のﾓｼﾞｭｰﾙID			*/
#define MPC41514	0x4782		  		/* mpc41514() のﾓｼﾞｭｰﾙID			*/
#define MPC41516	0x4783		  		/* mpc41516() のﾓｼﾞｭｰﾙID			*/

#define MPC416XX	0x4800		  		/* mpc416xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41603	0x4801		  		/* mpc41603() のﾓｼﾞｭｰﾙID			*/
#define MPC41614	0x4802		  		/* mpc41614() のﾓｼﾞｭｰﾙID			*/
#define MPC41616	0x4803		  		/* mpc41616() のﾓｼﾞｭｰﾙID			*/

#define MPC417XX	0x4880		  		/* mpc417xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41705	0x4881		  		/* mpc41705() のﾓｼﾞｭｰﾙID			*/
#define MPC41711	0x4882		  		/* mpc41711() のﾓｼﾞｭｰﾙID			*/
#define MPC41716	0x4883		  		/* mpc41716() のﾓｼﾞｭｰﾙID			*/

#define MPC418XX	0x4900		  		/* mpc418xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41807	0x4901		  		/* mpc41807() のﾓｼﾞｭｰﾙID			*/
#define MPC41812	0x4902		  		/* mpc41812() のﾓｼﾞｭｰﾙID			*/
#define MPC41817	0x4903		  		/* mpc41817() のﾓｼﾞｭｰﾙID			*/

#define MPC419XX	0x4980		  		/* mpc419xx() のﾓｼﾞｭｰﾙID			*/
#define MPC41907	0x4981		  		/* mpc41907() のﾓｼﾞｭｰﾙID			*/
#define MPC41912	0x4982		  		/* mpc41912() のﾓｼﾞｭｰﾙID			*/
#define MPC41915	0x4983		  		/* mpc41915() のﾓｼﾞｭｰﾙID			*/
#define MPC41917	0x4984		  		/* mpc41917() のﾓｼﾞｭｰﾙID			*/

#define MPC420XX	0x4a00		  		/* mpc420xx() のﾓｼﾞｭｰﾙID			*/
#define MPC42008	0x4a01		  		/* mpc42008() のﾓｼﾞｭｰﾙID			*/
#define MPC42011	0x4a02		  		/* mpc42011() のﾓｼﾞｭｰﾙID			*/
#define MPC42016	0x4a03		  		/* mpc42016() のﾓｼﾞｭｰﾙID			*/

#define MPC421XX	0x4a80		  		/* mpc421xx() のﾓｼﾞｭｰﾙID			*/
#define MPC42101	0x4a81		  		/* mpc42101() のﾓｼﾞｭｰﾙID			*/
#define MPC42113	0x4a82		  		/* mpc42113() のﾓｼﾞｭｰﾙID			*/

#define MPC422XX	0x4b00		  		/* mpc422xx() のﾓｼﾞｭｰﾙID			*/
#define MPC42200	0x4b01		  		/* mpc42200() のﾓｼﾞｭｰﾙID			*/
#define MPC42201	0x4b02		  		/* mpc42201() のﾓｼﾞｭｰﾙID			*/
#define MPC42202	0x4b03		  		/* mpc42202() のﾓｼﾞｭｰﾙID			*/
#define MPC42204	0x4b04		  		/* mpc42204() のﾓｼﾞｭｰﾙID			*/
#define MPC42205	0x4b05		  		/* mpc42205() のﾓｼﾞｭｰﾙID			*/
#define MPC42208	0x4b06		  		/* mpc42208() のﾓｼﾞｭｰﾙID			*/
#define MPC42209	0x4b07		  		/* mpc42209() のﾓｼﾞｭｰﾙID			*/
#define MPC42210	0x4b08		  		/* mpc42210() のﾓｼﾞｭｰﾙID			*/
#define MPC42215	0x4b09		  		/* mpc42215() のﾓｼﾞｭｰﾙID			*/
#define MPC42218	0x4b0a		  		/* mpc42218() のﾓｼﾞｭｰﾙID			*/

#define MPC423XX	0x4b80		  		/* mpc423xx() のﾓｼﾞｭｰﾙID			*/
#define MPC42306	0x4b81		  		/* mpc42306() のﾓｼﾞｭｰﾙID			*/
#define MPC42309	0x4b82		  		/* mpc42309() のﾓｼﾞｭｰﾙID			*/
#define MPC42311	0x4b83		  		/* mpc42311() のﾓｼﾞｭｰﾙID			*/
#define MPC42312	0x4b84		  		/* mpc42312() のﾓｼﾞｭｰﾙID			*/
#define MPC42313	0x4b85		  		/* mpc42313() のﾓｼﾞｭｰﾙID			*/
#define MPC42316	0x4b86		  		/* mpc42316() のﾓｼﾞｭｰﾙID			*/
#define MPC42317	0x4b87		  		/* mpc42317() のﾓｼﾞｭｰﾙID			*/

#define MPC500XX	0x5000		  		/* mpc500xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50000	0x5001		  		/* mpc50000() のﾓｼﾞｭｰﾙID			*/

#define MPC501XX	0x5080		  		/* mpc501xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50100	0x5081		  		/* mpc50100() のﾓｼﾞｭｰﾙID			*/

#define MPC502XX	0x5100		  		/* mpc502xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50204	0x5101		  		/* mpc50204() のﾓｼﾞｭｰﾙID			*/
#define MPC50205	0x5102		  		/* mpc50205() のﾓｼﾞｭｰﾙID			*/

#define MPC503XX	0x5180		  		/* mpc503xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50304	0x5181		  		/* mpc50304() のﾓｼﾞｭｰﾙID			*/
#define MPC50305	0x5182		  		/* mpc50305() のﾓｼﾞｭｰﾙID			*/
#define MPC50399	0x5183		  		/* mpc50399() のﾓｼﾞｭｰﾙID			*/

#define MPC504XX	0x5200		  		/* mpc504xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50400	0x5201		  		/* mpc50400() のﾓｼﾞｭｰﾙID			*/
#define MPC50401	0x5202		  		/* mpc50401() のﾓｼﾞｭｰﾙID			*/
#define MPC50402	0x5203		  		/* mpc50402() のﾓｼﾞｭｰﾙID			*/
#define MPC50403	0x5204		  		/* mpc50403() のﾓｼﾞｭｰﾙID			*/
#define MPC50404	0x5205		  		/* mpc50404() のﾓｼﾞｭｰﾙID			*/
#define MPC50405	0x5206		  		/* mpc50405() のﾓｼﾞｭｰﾙID			*/
#define MPC50406	0x5207		  		/* mpc50406() のﾓｼﾞｭｰﾙID			*/
#define MPC50407	0x5208		  		/* mpc50407() のﾓｼﾞｭｰﾙID			*/
#define MPC50408	0x5209		  		/* mpc50408() のﾓｼﾞｭｰﾙID			*/
#define MPC50409	0x520a		  		/* mpc50409() のﾓｼﾞｭｰﾙID			*/
#define MPC50410	0x520b		  		/* mpc50410() のﾓｼﾞｭｰﾙID			*/
#define MPC50413	0x520c		  		/* mpc50413() のﾓｼﾞｭｰﾙID			*/

#define MPC505XX	0x5280		  		/* mpc505xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50500	0x5281		  		/* mpc50500() のﾓｼﾞｭｰﾙID			*/
#define MPC50501	0x5282		  		/* mpc50501() のﾓｼﾞｭｰﾙID			*/
#define MPC50502	0x5283		  		/* mpc50502() のﾓｼﾞｭｰﾙID			*/
#define MPC50503	0x5284		  		/* mpc50503() のﾓｼﾞｭｰﾙID			*/
#define MPC50504	0x5285		  		/* mpc50504() のﾓｼﾞｭｰﾙID			*/
#define MPC50505	0x5286		  		/* mpc50505() のﾓｼﾞｭｰﾙID			*/
#define MPC50506	0x5287		  		/* mpc50506() のﾓｼﾞｭｰﾙID			*/
#define MPC50507	0x5288		  		/* mpc50507() のﾓｼﾞｭｰﾙID			*/
#define MPC50508	0x5289		  		/* mpc50508() のﾓｼﾞｭｰﾙID			*/
#define MPC50509	0x528a		  		/* mpc50509() のﾓｼﾞｭｰﾙID			*/
#define MPC50510	0x528b		  		/* mpc50510() のﾓｼﾞｭｰﾙID			*/
#define MPC50513	0x528c		  		/* mpc50513() のﾓｼﾞｭｰﾙID			*/

#define MPC506XX	0x5300		  		/* mpc506xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50604	0x5301		  		/* mpc50604() のﾓｼﾞｭｰﾙID			*/

#define MPC507XX	0x5380		  		/* mpc507xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50704	0x5381		  		/* mpc50704() のﾓｼﾞｭｰﾙID			*/
#define MPC50705	0x5382		  		/* mpc50705() のﾓｼﾞｭｰﾙID			*/
#define MPC50706	0x5383		  		/* mpc50706() のﾓｼﾞｭｰﾙID			*/

#define MPC508XX	0x5400		  		/* mpc508xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50804	0x5401		  		/* mpc50804() のﾓｼﾞｭｰﾙID			*/
#define MPC50805	0x5402		  		/* mpc50805() のﾓｼﾞｭｰﾙID			*/

#define MPC509XX	0x5480		  		/* mpc509xx() のﾓｼﾞｭｰﾙID			*/
#define MPC50904	0x5481		  		/* mpc50904() のﾓｼﾞｭｰﾙID			*/
#define MPC50905	0x5482		  		/* mpc50905() のﾓｼﾞｭｰﾙID			*/

#define MPC510XX	0x5500		  		/* mpc510xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51004	0x5501		  		/* mpc51004() のﾓｼﾞｭｰﾙID			*/
#define MPC51005	0x5502		  		/* mpc51005() のﾓｼﾞｭｰﾙID			*/

#define MPC511XX	0x5580		  		/* mpc511xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51101	0x5581		  		/* mpc51101() のﾓｼﾞｭｰﾙID			*/
#define MPC51102	0x5582		  		/* mpc51102() のﾓｼﾞｭｰﾙID			*/
#define MPC51103	0x5583		  		/* mpc51103() のﾓｼﾞｭｰﾙID			*/
#define MPC51104	0x5584		  		/* mpc51104() のﾓｼﾞｭｰﾙID			*/
#define MPC51105	0x5585		  		/* mpc51105() のﾓｼﾞｭｰﾙID			*/
#define MPC51106	0x5586		  		/* mpc51106() のﾓｼﾞｭｰﾙID			*/
#define MPC51107	0x5587		  		/* mpc51107() のﾓｼﾞｭｰﾙID			*/
#define MPC51108	0x5588		  		/* mpc51108() のﾓｼﾞｭｰﾙID			*/
#define MPC51109	0x5589		  		/* mpc51109() のﾓｼﾞｭｰﾙID			*/

#define MPC512XX	0x5600		  		/* mpc512xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51204	0x5601		  		/* mpc51204() のﾓｼﾞｭｰﾙID			*/
#define MPC51205	0x5602		  		/* mpc51205() のﾓｼﾞｭｰﾙID			*/
#define MPC51206	0x5603		  		/* mpc51206() のﾓｼﾞｭｰﾙID			*/
#define MPC51210	0x5604		  		/* mpc51210() のﾓｼﾞｭｰﾙID			*/
#define MPC51213	0x5605		  		/* mpc51213() のﾓｼﾞｭｰﾙID			*/
#define MPC51216	0x5606		  		/* mpc51216() のﾓｼﾞｭｰﾙID			*/

#define MPC513XX	0x5680		  		/* mpc513xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51304	0x5681		  		/* mpc51304() のﾓｼﾞｭｰﾙID			*/
#define MPC51305	0x5682		  		/* mpc51305() のﾓｼﾞｭｰﾙID			*/
#define MPC51306	0x5683		  		/* mpc51306() のﾓｼﾞｭｰﾙID			*/
#define MPC51310	0x5684		  		/* mpc51310() のﾓｼﾞｭｰﾙID			*/
#define MPC51313	0x5685		  		/* mpc51313() のﾓｼﾞｭｰﾙID			*/
#define MPC51316	0x5686		  		/* mpc51316() のﾓｼﾞｭｰﾙID			*/
#define MPC51399	0x5687		  		/* mpc51399() のﾓｼﾞｭｰﾙID			*/

#define MPC514XX	0x5700		  		/* mpc514xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51404	0x5701		  		/* mpc51404() のﾓｼﾞｭｰﾙID			*/
#define MPC51405	0x5702		  		/* mpc51405() のﾓｼﾞｭｰﾙID			*/
#define MPC51406	0x5703		  		/* mpc51406() のﾓｼﾞｭｰﾙID			*/
#define MPC51410	0x5704		  		/* mpc51410() のﾓｼﾞｭｰﾙID			*/
#define MPC51413	0x5705		  		/* mpc51413() のﾓｼﾞｭｰﾙID			*/
#define MPC51416	0x5706		  		/* mpc51416() のﾓｼﾞｭｰﾙID			*/
#define MPC51499	0x5707		  		/* mpc51499() のﾓｼﾞｭｰﾙID			*/

#define MPC515XX	0x5780		  		/* mpc515xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51504	0x5781		  		/* mpc51504() のﾓｼﾞｭｰﾙID			*/
#define MPC51505	0x5782		  		/* mpc51505() のﾓｼﾞｭｰﾙID			*/
#define MPC51506	0x5783		  		/* mpc51506() のﾓｼﾞｭｰﾙID			*/
#define MPC51510	0x5784		  		/* mpc51510() のﾓｼﾞｭｰﾙID			*/
#define MPC51513	0x5785		  		/* mpc51513() のﾓｼﾞｭｰﾙID			*/
#define MPC51516	0x5786		  		/* mpc51516() のﾓｼﾞｭｰﾙID			*/

#define MPC516XX	0x5800		  		/* mpc516xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51604	0x5801		  		/* mpc51604() のﾓｼﾞｭｰﾙID			*/
#define MPC51605	0x5802		  		/* mpc51605() のﾓｼﾞｭｰﾙID			*/
#define MPC51606	0x5803		  		/* mpc51606() のﾓｼﾞｭｰﾙID			*/
#define MPC51610	0x5804		  		/* mpc51610() のﾓｼﾞｭｰﾙID			*/
#define MPC51613	0x5805		  		/* mpc51613() のﾓｼﾞｭｰﾙID			*/
#define MPC51616	0x5806		  		/* mpc51616() のﾓｼﾞｭｰﾙID			*/
#define MPC51699	0x5807		  		/* mpc51699() のﾓｼﾞｭｰﾙID			*/

#define MPC517XX	0x5880		  		/* mpc517xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51704	0x5881		  		/* mpc51704() のﾓｼﾞｭｰﾙID			*/
#define MPC51705	0x5882		  		/* mpc51705() のﾓｼﾞｭｰﾙID			*/
#define MPC51707	0x5883		  		/* mpc51707() のﾓｼﾞｭｰﾙID			*/
#define MPC51708	0x5884		  		/* mpc51708() のﾓｼﾞｭｰﾙID			*/
#define MPC51711	0x5885		  		/* mpc51711() のﾓｼﾞｭｰﾙID			*/
#define MPC51717	0x5886		  		/* mpc51717() のﾓｼﾞｭｰﾙID			*/

#define MPC518XX	0x5900		  		/* mpc518xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51803	0x5901		  		/* mpc51803() のﾓｼﾞｭｰﾙID			*/
#define MPC51807	0x5902		  		/* mpc51807() のﾓｼﾞｭｰﾙID			*/
#define MPC51811	0x5903		  		/* mpc51811() のﾓｼﾞｭｰﾙID			*/
#define MPC51814	0x5904		  		/* mpc51814() のﾓｼﾞｭｰﾙID			*/
#define MPC51817	0x5905		  		/* mpc51817() のﾓｼﾞｭｰﾙID			*/

#define MPC519XX	0x5980		  		/* mpc519xx() のﾓｼﾞｭｰﾙID			*/
#define MPC51902	0x5981		  		/* mpc51902() のﾓｼﾞｭｰﾙID			*/
#define MPC51906	0x5982		  		/* mpc51906() のﾓｼﾞｭｰﾙID			*/
#define MPC51910	0x5983		  		/* mpc51910() のﾓｼﾞｭｰﾙID			*/
#define MPC51913	0x5984		  		/* mpc51913() のﾓｼﾞｭｰﾙID			*/
#define MPC51916	0x5985		  		/* mpc51916() のﾓｼﾞｭｰﾙID			*/

#define MPC520XX	0x5a00		  		/* mpc520xx() のﾓｼﾞｭｰﾙID			*/
#define MPC52002	0x5a01		  		/* mpc52002() のﾓｼﾞｭｰﾙID			*/
#define MPC52010	0x5a02		  		/* mpc52010() のﾓｼﾞｭｰﾙID			*/
#define MPC52013	0x5a03		  		/* mpc52013() のﾓｼﾞｭｰﾙID			*/
#define MPC52016	0x5a04		  		/* mpc52016() のﾓｼﾞｭｰﾙID			*/

#define MPC521XX	0x5a80		  		/* mpc521xx() のﾓｼﾞｭｰﾙID			*/
#define MPC52101	0x5a81		  		/* mpc52101() のﾓｼﾞｭｰﾙID			*/
#define MPC52102	0x5a82		  		/* mpc52102() のﾓｼﾞｭｰﾙID			*/
#define MPC52110	0x5a83		  		/* mpc52110() のﾓｼﾞｭｰﾙID			*/
#define MPC52113	0x5a84		  		/* mpc52113() のﾓｼﾞｭｰﾙID			*/
#define MPC52116	0x5a85		  		/* mpc52116() のﾓｼﾞｭｰﾙID			*/
#define MPC52199	0x5a86		  		/* mpc52199() のﾓｼﾞｭｰﾙID			*/

#define MPC522XX	0x5b00		  		/* mpc522xx() のﾓｼﾞｭｰﾙID			*/
#define MPC52208	0x5b01		  		/* mpc52208() のﾓｼﾞｭｰﾙID			*/
#define MPC52212	0x5b02		  		/* mpc52212() のﾓｼﾞｭｰﾙID			*/
#define MPC52215	0x5b03		  		/* mpc52215() のﾓｼﾞｭｰﾙID			*/
#define MPC52218	0x5b04		  		/* mpc52218() のﾓｼﾞｭｰﾙID			*/

