/**********************************************************************/
/* �̎�����̾������mpbabort.h											  */
/* ��ǽ������  ���Ύގ��ľܺپ����1�ʎގ��� 								  */
/*			   �̎ߎێ������Ύގ��Ďώ���										  */
/* ����������  1992.01.07											  */
/* ����������  2002.12.10										 M01  */
/**********************************************************************/
/**************************************/
/* ���Ύގ��ľܺپ����1�ʎގ��� 			  */
/**************************************/

/**************************************/
/* ���Ѥ��ʤ�������					  */
/* (H'00��H'0f)						  */
/**************************************/

/**************************************/
/* �������顼						  */
/* (H'10��H'3f)						  */
/**************************************/
#define ABTLMTX0	0x10				/* �ޥȥꥯ��̷��ʲ��������		*/
#define ABTLMTX1	0x11				/* �ޥȥꥯ��̷��������ѥ������	*/
#define ABTLMTX2	0x12				/* �ޥȥꥯ��̷��ʎ��Ȏ������������ 	*/
#define ABTLMSE1	0x13				/* �ώĎ؎���Ʊ��̷��ʲ����������ʎߎ���	*/
#define ABTLMSE2	0x14				/* �ώĎ؎���Ʊ��̷��������ʎߎ������Ȏ������ݡ� */
#define ABTLSNMP	0x20				/* ossenmsp()�۾�					*/
#define ABTLSNMS	0x21				/* ossnsms()�۾�					*/
#define ABTLOSCN	0x22				/* osconn()�۾� 					*/
#define ABTLFINF	0x23				/* osgfinf()�۾�					*/
#define ABTLOPEN	0x24				/* osopen()�۾� 					*/
#define ABTLSFLG	0x25				/* osiioctl(NETCTL:�Ȏ��Ď܎����̎׎�����Ͽ) 	*/
										/* �۾�								*/
#define ABTLSMSK	0x26				/* osiioctl(NETCTL:���̎ގȎ��Ďώ�����Ͽ)�� */
										/* ��								*/
#define ABTLSIPA	0x27				/* osiioctl(NETCTL:�ێ����َ��Ďގڎ���Ͽ)�� */
										/* ��								*/
#define ABTLATCH	0x28				/* osiioctl(ATTACH)�۾� 			*/
#define ABTLBIND	0x29				/* osiioctl(BIND)�۾�				*/
#define ABTLLIST	0x2a				/* osiioctl(LISTEN)�۾� 			*/
#define ABTLACPT	0x2b				/* osiioctl(ACCEPT)�۾� 			*/
#define ABTLASYN	0x2c				/* osiioctl(��Ʊ�������׵�)�۾� 	*/
#define ABTLDECH	0x2d				/* osiioctl(DETACH)�۾� 			*/
#define ABTLABOT	0x2e				/* osiioctl(ABORT)�۾�				*/
#define ABTLDCON	0x2f				/* osiioctl(DISCONNECT)�۾� 		*/
#define ABTLCONN	0x30				/* osiioctl(CONNECT)�۾�			*/
#define ABTLSOPT	0x31				/* osiioctl(SETOPT)�۾� 			*/
#define ABTLSOOB	0x32				/* osiioctl(SENDOOB)�۾�			*/
#define ABTLROOB	0x33				/* osiioctl(RCVOOB)�۾� 			*/
#define ABTLREAD	0x34				/* osireadd�۾� 					*/
#define ABTLWRTD	0x35				/* osiwritd�۾� 					*/
#define ABTLGTNM	0x36				/* uname�۾�					M01	*/
#define ABTLGTIP	0x37				/* gethostbyname�۾�			M01	*/

/**************************************/
/* �ѥ�᡼�������顼				  */
/* (H'40��H'7f)						  */
/**************************************/
#define ABTINVSG	0x40				/* SG������ 						*/

/**************************************/
/* ��ʡ�Ʊ�����顼					  */
/* (H'80��H'9f)						  */
/**************************************/

/**************************************/
/* �ϡ��ɥ��顼						  */
/* (H'a0��H'cf)						  */
/**************************************/

/**************************************/
/* ����­���顼					  */
/* (H'd0��H'df)						  */
/**************************************/

/**************************************/
/* ����¾�Υ��顼					  */
/* (H'e0��H'ff)						  */
/**************************************/
#define ABTOGABF	0xe4				/* �����ӥ�������۾�(mo_gabf)��	*/
#define ABTONCLR	0xe5				/* �����ӥ�������۾�(mo_nclr)��	*/
#define ABTOFBF0	0xe6				/* �����ӥ�������۾�(mo_frbf)��	*/
#define ABTOLINF	0xe7				/* �����ӥ�������۾�(mi_lstat)��	*/

/**************************************/
/* �⥸�塼��ɣ�					  */
/**************************************/
#define MID_EX 		0x74ff0000			/* ���͎ގݎİ۾�				  */

#define STATEVNT(P1, P2)	((long)P1<<16)|(0x0000ffff&P2)
#define ABT_NULL	 0x0				
/**************************************/
/*									  */
/**************************************/
#define AD_RESLT	 0x00000000 		/* �����ƥॳ�����ֵ��Ͱ۾� 		*/
										/* �ʥꥶ����Ͱ۾��				*/
#define AD_SYSRD	 0x00000001 		/* �����ƥॳ�����ֵ��Ͱ۾� 		*/
										/* �ʣ���Ͱ۾��					*/
#define AD_LMBUF	 0x00010000 		/* �������楳��ƥ����� 			*/
#define AD_PMBUF	 0x00010001 		/* �����ѥ����楳��ƥ����� 		*/
#define AD_CMBUF	 0x00010002 		/* ���ͥ���������楳��ƥ����� 	*/
#define AD_MCOM0	 0x00010002 		/* �̿������å�����           	*/
#define AD_MCOM1(P1) (0x00000000 | (((MPCRQMSG *)P1)->usr.mpcococd << 8 )	  \
	| (((MPCRQMSG *)P1)->usr.mpcotype) )/* �̿������å�����          		*/
#define AD_MICP0	 0x00001003 		/* �ɣãХ�å�����           		*/
#define AD_MOCP0	 0x00001004 		/* �ϣãХ�å�����           		*/
#define AD_MICP1	 0x00001003 		/* �ɣãХ�å�����           		*/
#define AD_MOCP1	 0x00001004 		/* �ϣãХ�å�����           		*/
#define AD_MOTHR	 0x00001004 		/* �ͣɣ�������å�����           	*/
/**************************************/
/* �⥸�塼��ɣġʳ�ĥ��			  */
/**************************************/
#define MPC00001	0x0001		  		/* mpc00001() �Ύӎ��ގ�����ID			*/
#define MPC00002	0x0002		  		/* mpc00002() �Ύӎ��ގ�����ID			*/
#define MPC00003	0x0003		  		/* mpc00003() �Ύӎ��ގ�����ID			*/
#define MPC00004	0x0004		  		/* mpc00004() �Ύӎ��ގ�����ID			*/
#define MPC00005	0x0005		  		/* mpc00005() �Ύӎ��ގ�����ID			*/

#define MPC100XX	0x1000		  		/* mpc100xx() �Ύӎ��ގ�����ID			*/
#define MPC10000	0x1001		  		/* mpc10000() �Ύӎ��ގ�����ID			*/
#define MPC101XX	0x1080		  		/* mpc101xx() �Ύӎ��ގ�����ID			*/
#define MPC10100	0x1081		  		/* mpc10100() �Ύӎ��ގ�����ID			*/
#define MPC10101	0x1082		  		/* mpc10101() �Ύӎ��ގ�����ID			*/
#define MPC10102	0x1083		  		/* mpc10102() �Ύӎ��ގ�����ID			*/
#define MPC102XX	0x1100		  		/* mpc102xx() �Ύӎ��ގ�����ID			*/
#define MPC103XX	0x1180		  		/* mpc103xx() �Ύӎ��ގ�����ID			*/

#define MPC200XX	0x2000		  		/* mpc200xx() �Ύӎ��ގ�����ID			*/
#define MPC20000	0x2001		  		/* mpc20000() �Ύӎ��ގ�����ID			*/
#define MPC20001	0x2002		  		/* mpc20001() �Ύӎ��ގ�����ID			*/
#define MPC20002	0x2003		  		/* mpc20002() �Ύӎ��ގ�����ID			*/

#define MPC300XX	0x3000		  		/* mpc300xx() �Ύӎ��ގ�����ID			*/
#define MPC30000	0x3001		  		/* mpc30000() �Ύӎ��ގ�����ID			*/

#define MPC301XX	0x3080		  		/* mpc301xx() �Ύӎ��ގ�����ID			*/
#define MPC30102	0x3081		  		/* mpc30102() �Ύӎ��ގ�����ID			*/
#define MPC30104	0x3082		  		/* mpc30104() �Ύӎ��ގ�����ID			*/

#define MPC302XX	0x3100		  		/* mpc302xx() �Ύӎ��ގ�����ID			*/
#define MPC30211	0x3101		  		/* mpc30211() �Ύӎ��ގ�����ID			*/
#define MPC30212	0x3102		  		/* mpc30212() �Ύӎ��ގ�����ID			*/
#define MPC30213	0x3103		  		/* mpc30213() �Ύӎ��ގ�����ID			*/

#define MPC303XX	0x3180		  		/* mpc303xx() �Ύӎ��ގ�����ID			*/
#define MPC30301	0x3181		  		/* mpc30301() �Ύӎ��ގ�����ID			*/
#define MPC30302	0x3182		  		/* mpc30302() �Ύӎ��ގ�����ID			*/
#define MPC30303	0x3183		  		/* mpc30303() �Ύӎ��ގ�����ID			*/
#define MPC30304	0x3184		  		/* mpc30304() �Ύӎ��ގ�����ID			*/

#define MPC304XX	0x3200		  		/* mpc304xx() �Ύӎ��ގ�����ID			*/
#define MPC30402	0x3201		  		/* mpc30402() �Ύӎ��ގ�����ID			*/
#define MPC30408	0x3202		  		/* mpc30408() �Ύӎ��ގ�����ID			*/
#define MPC30410	0x3203		  		/* mpc30410() �Ύӎ��ގ�����ID			*/

#define MPC305XX	0x3280		  		/* mpc305xx() �Ύӎ��ގ�����ID			*/
#define MPC30502	0x3281		  		/* mpc30502() �Ύӎ��ގ�����ID			*/
#define MPC30505	0x3282		  		/* mpc30505() �Ύӎ��ގ�����ID			*/
#define MPC30510	0x3283		  		/* mpc30510() �Ύӎ��ގ�����ID			*/

#define MPC306XX	0x3300		  		/* mpc306xx() �Ύӎ��ގ�����ID			*/
#define MPC30602	0x3301		  		/* mpc30602() �Ύӎ��ގ�����ID			*/
#define MPC30607	0x3302		  		/* mpc30607() �Ύӎ��ގ�����ID			*/
#define MPC30610	0x3303		  		/* mpc30610() �Ύӎ��ގ�����ID			*/

#define MPC307XX	0x3380		  		/* mpc307xx() �Ύӎ��ގ�����ID			*/
#define MPC30704	0x3381		  		/* mpc30704() �Ύӎ��ގ�����ID			*/
#define MPC30706	0x3382		  		/* mpc30706() �Ύӎ��ގ�����ID			*/
#define MPC30708	0x3383		  		/* mpc30708() �Ύӎ��ގ�����ID			*/

#define MPC308XX	0x3400		  		/* mpc308xx() �Ύӎ��ގ�����ID			*/
#define MPC30802	0x3401		  		/* mpc30802() �Ύӎ��ގ�����ID			*/
#define MPC30803	0x3402		  		/* mpc30803() �Ύӎ��ގ�����ID			*/
#define MPC30810	0x3403		  		/* mpc30810() �Ύӎ��ގ�����ID			*/

#define MPC400XX	0x4000		  		/* mpc400xx() �Ύӎ��ގ�����ID			*/
#define MPC40000	0x4001		  		/* mpc40000() �Ύӎ��ގ�����ID			*/

#define MPC401XX	0x4080		  		/* mpc401xx() �Ύӎ��ގ�����ID			*/
#define MPC40101	0x4081		  		/* mpc40101() �Ύӎ��ގ�����ID			*/
#define MPC40102	0x4082		  		/* mpc40102() �Ύӎ��ގ�����ID			*/
#define MPC40104	0x4083		  		/* mpc40104() �Ύӎ��ގ�����ID			*/
#define MPC40105	0x4084		  		/* mpc40105() �Ύӎ��ގ�����ID			*/
#define MPC40106	0x4085		  		/* mpc40106() �Ύӎ��ގ�����ID			*/
#define MPC40108	0x4086		  		/* mpc40108() �Ύӎ��ގ�����ID			*/
#define MPC40109	0x4087		  		/* mpc40109() �Ύӎ��ގ�����ID			*/
#define MPC40110	0x4088		  		/* mpc40110() �Ύӎ��ގ�����ID			*/
#define MPC40111	0x4089		  		/* mpc40111() �Ύӎ��ގ�����ID			*/
#define MPC40112	0x408a		  		/* mpc40112() �Ύӎ��ގ�����ID			*/
#define MPC40113	0x408b		  		/* mpc40113() �Ύӎ��ގ�����ID			*/
#define MPC40115	0x408c		  		/* mpc40115() �Ύӎ��ގ�����ID			*/
#define MPC40118	0x408d		  		/* mpc40118() �Ύӎ��ގ�����ID			*/

#define MPC402XX	0x4100		  		/* mpc402xx() �Ύӎ��ގ�����ID			*/
#define MPC40206	0x4101		  		/* mpc40206() �Ύӎ��ގ�����ID			*/

#define MPC403XX	0x4180		  		/* mpc403xx() �Ύӎ��ގ�����ID			*/
#define MPC40306	0x4181		  		/* mpc40306() �Ύӎ��ގ�����ID			*/

#define MPC404XX	0x4200		  		/* mpc404xx() �Ύӎ��ގ�����ID			*/
#define MPC40404	0x4201		  		/* mpc40404() �Ύӎ��ގ�����ID			*/

#define MPC405XX	0x4280		  		/* mpc405xx() �Ύӎ��ގ�����ID			*/
#define MPC40511	0x4281		  		/* mpc40511() �Ύӎ��ގ�����ID			*/

#define MPC406XX	0x4300		  		/* mpc406xx() �Ύӎ��ގ�����ID			*/
#define MPC40604	0x4301		  		/* mpc40604() �Ύӎ��ގ�����ID			*/

#define MPC407XX	0x4380		  		/* mpc407xx() �Ύӎ��ގ�����ID			*/
#define MPC40704	0x4381		  		/* mpc40704() �Ύӎ��ގ�����ID			*/
#define MPC40705	0x4382		  		/* mpc40705() �Ύӎ��ގ�����ID			*/
#define MPC40706	0x4383		  		/* mpc40706() �Ύӎ��ގ�����ID			*/
#define MPC40708	0x4384		  		/* mpc40708() �Ύӎ��ގ�����ID			*/

#define MPC408XX	0x4400		  		/* mpc408xx() �Ύӎ��ގ�����ID			*/
#define MPC40805	0x4401		  		/* mpc40805() �Ύӎ��ގ�����ID			*/
#define MPC40806	0x4402		  		/* mpc40806() �Ύӎ��ގ�����ID			*/
#define MPC40808	0x4403		  		/* mpc40808() �Ύӎ��ގ�����ID			*/
#define MPC40809	0x4404		  		/* mpc40809() �Ύӎ��ގ�����ID			*/

#define MPC409XX	0x4480		  		/* mpc409xx() �Ύӎ��ގ�����ID			*/
#define MPC40901	0x4481		  		/* mpc40901() �Ύӎ��ގ�����ID			*/
#define MPC40905	0x4482		  		/* mpc40905() �Ύӎ��ގ�����ID			*/
#define MPC40906	0x4483		  		/* mpc40906() �Ύӎ��ގ�����ID			*/
#define MPC40908	0x4484		  		/* mpc40908() �Ύӎ��ގ�����ID			*/
#define MPC40909	0x4485		  		/* mpc40909() �Ύӎ��ގ�����ID			*/

#define MPC410XX	0x4500		  		/* mpc410xx() �Ύӎ��ގ�����ID			*/
#define MPC41006	0x4501		  		/* mpc41006() �Ύӎ��ގ�����ID			*/

#define MPC411XX	0x4580		  		/* mpc411xx() �Ύӎ��ގ�����ID			*/
#define MPC41106	0x4581		  		/* mpc41106() �Ύӎ��ގ�����ID			*/

#define MPC412XX	0x4600		  		/* mpc412xx() �Ύӎ��ގ�����ID			*/
#define MPC41206	0x4601		  		/* mpc41206() �Ύӎ��ގ�����ID			*/

#define MPC413XX	0x4680		  		/* mpc413xx() �Ύӎ��ގ�����ID			*/
#define MPC41306	0x4681		  		/* mpc41306() �Ύӎ��ގ�����ID			*/

#define MPC414XX	0x4700		  		/* mpc414xx() �Ύӎ��ގ�����ID			*/
#define MPC41406	0x4701		  		/* mpc41406() �Ύӎ��ގ�����ID			*/

#define MPC415XX	0x4780		  		/* mpc415xx() �Ύӎ��ގ�����ID			*/
#define MPC41502	0x4781		  		/* mpc41502() �Ύӎ��ގ�����ID			*/
#define MPC41514	0x4782		  		/* mpc41514() �Ύӎ��ގ�����ID			*/
#define MPC41516	0x4783		  		/* mpc41516() �Ύӎ��ގ�����ID			*/

#define MPC416XX	0x4800		  		/* mpc416xx() �Ύӎ��ގ�����ID			*/
#define MPC41603	0x4801		  		/* mpc41603() �Ύӎ��ގ�����ID			*/
#define MPC41614	0x4802		  		/* mpc41614() �Ύӎ��ގ�����ID			*/
#define MPC41616	0x4803		  		/* mpc41616() �Ύӎ��ގ�����ID			*/

#define MPC417XX	0x4880		  		/* mpc417xx() �Ύӎ��ގ�����ID			*/
#define MPC41705	0x4881		  		/* mpc41705() �Ύӎ��ގ�����ID			*/
#define MPC41711	0x4882		  		/* mpc41711() �Ύӎ��ގ�����ID			*/
#define MPC41716	0x4883		  		/* mpc41716() �Ύӎ��ގ�����ID			*/

#define MPC418XX	0x4900		  		/* mpc418xx() �Ύӎ��ގ�����ID			*/
#define MPC41807	0x4901		  		/* mpc41807() �Ύӎ��ގ�����ID			*/
#define MPC41812	0x4902		  		/* mpc41812() �Ύӎ��ގ�����ID			*/
#define MPC41817	0x4903		  		/* mpc41817() �Ύӎ��ގ�����ID			*/

#define MPC419XX	0x4980		  		/* mpc419xx() �Ύӎ��ގ�����ID			*/
#define MPC41907	0x4981		  		/* mpc41907() �Ύӎ��ގ�����ID			*/
#define MPC41912	0x4982		  		/* mpc41912() �Ύӎ��ގ�����ID			*/
#define MPC41915	0x4983		  		/* mpc41915() �Ύӎ��ގ�����ID			*/
#define MPC41917	0x4984		  		/* mpc41917() �Ύӎ��ގ�����ID			*/

#define MPC420XX	0x4a00		  		/* mpc420xx() �Ύӎ��ގ�����ID			*/
#define MPC42008	0x4a01		  		/* mpc42008() �Ύӎ��ގ�����ID			*/
#define MPC42011	0x4a02		  		/* mpc42011() �Ύӎ��ގ�����ID			*/
#define MPC42016	0x4a03		  		/* mpc42016() �Ύӎ��ގ�����ID			*/

#define MPC421XX	0x4a80		  		/* mpc421xx() �Ύӎ��ގ�����ID			*/
#define MPC42101	0x4a81		  		/* mpc42101() �Ύӎ��ގ�����ID			*/
#define MPC42113	0x4a82		  		/* mpc42113() �Ύӎ��ގ�����ID			*/

#define MPC422XX	0x4b00		  		/* mpc422xx() �Ύӎ��ގ�����ID			*/
#define MPC42200	0x4b01		  		/* mpc42200() �Ύӎ��ގ�����ID			*/
#define MPC42201	0x4b02		  		/* mpc42201() �Ύӎ��ގ�����ID			*/
#define MPC42202	0x4b03		  		/* mpc42202() �Ύӎ��ގ�����ID			*/
#define MPC42204	0x4b04		  		/* mpc42204() �Ύӎ��ގ�����ID			*/
#define MPC42205	0x4b05		  		/* mpc42205() �Ύӎ��ގ�����ID			*/
#define MPC42208	0x4b06		  		/* mpc42208() �Ύӎ��ގ�����ID			*/
#define MPC42209	0x4b07		  		/* mpc42209() �Ύӎ��ގ�����ID			*/
#define MPC42210	0x4b08		  		/* mpc42210() �Ύӎ��ގ�����ID			*/
#define MPC42215	0x4b09		  		/* mpc42215() �Ύӎ��ގ�����ID			*/
#define MPC42218	0x4b0a		  		/* mpc42218() �Ύӎ��ގ�����ID			*/

#define MPC423XX	0x4b80		  		/* mpc423xx() �Ύӎ��ގ�����ID			*/
#define MPC42306	0x4b81		  		/* mpc42306() �Ύӎ��ގ�����ID			*/
#define MPC42309	0x4b82		  		/* mpc42309() �Ύӎ��ގ�����ID			*/
#define MPC42311	0x4b83		  		/* mpc42311() �Ύӎ��ގ�����ID			*/
#define MPC42312	0x4b84		  		/* mpc42312() �Ύӎ��ގ�����ID			*/
#define MPC42313	0x4b85		  		/* mpc42313() �Ύӎ��ގ�����ID			*/
#define MPC42316	0x4b86		  		/* mpc42316() �Ύӎ��ގ�����ID			*/
#define MPC42317	0x4b87		  		/* mpc42317() �Ύӎ��ގ�����ID			*/

#define MPC500XX	0x5000		  		/* mpc500xx() �Ύӎ��ގ�����ID			*/
#define MPC50000	0x5001		  		/* mpc50000() �Ύӎ��ގ�����ID			*/

#define MPC501XX	0x5080		  		/* mpc501xx() �Ύӎ��ގ�����ID			*/
#define MPC50100	0x5081		  		/* mpc50100() �Ύӎ��ގ�����ID			*/

#define MPC502XX	0x5100		  		/* mpc502xx() �Ύӎ��ގ�����ID			*/
#define MPC50204	0x5101		  		/* mpc50204() �Ύӎ��ގ�����ID			*/
#define MPC50205	0x5102		  		/* mpc50205() �Ύӎ��ގ�����ID			*/

#define MPC503XX	0x5180		  		/* mpc503xx() �Ύӎ��ގ�����ID			*/
#define MPC50304	0x5181		  		/* mpc50304() �Ύӎ��ގ�����ID			*/
#define MPC50305	0x5182		  		/* mpc50305() �Ύӎ��ގ�����ID			*/
#define MPC50399	0x5183		  		/* mpc50399() �Ύӎ��ގ�����ID			*/

#define MPC504XX	0x5200		  		/* mpc504xx() �Ύӎ��ގ�����ID			*/
#define MPC50400	0x5201		  		/* mpc50400() �Ύӎ��ގ�����ID			*/
#define MPC50401	0x5202		  		/* mpc50401() �Ύӎ��ގ�����ID			*/
#define MPC50402	0x5203		  		/* mpc50402() �Ύӎ��ގ�����ID			*/
#define MPC50403	0x5204		  		/* mpc50403() �Ύӎ��ގ�����ID			*/
#define MPC50404	0x5205		  		/* mpc50404() �Ύӎ��ގ�����ID			*/
#define MPC50405	0x5206		  		/* mpc50405() �Ύӎ��ގ�����ID			*/
#define MPC50406	0x5207		  		/* mpc50406() �Ύӎ��ގ�����ID			*/
#define MPC50407	0x5208		  		/* mpc50407() �Ύӎ��ގ�����ID			*/
#define MPC50408	0x5209		  		/* mpc50408() �Ύӎ��ގ�����ID			*/
#define MPC50409	0x520a		  		/* mpc50409() �Ύӎ��ގ�����ID			*/
#define MPC50410	0x520b		  		/* mpc50410() �Ύӎ��ގ�����ID			*/
#define MPC50413	0x520c		  		/* mpc50413() �Ύӎ��ގ�����ID			*/

#define MPC505XX	0x5280		  		/* mpc505xx() �Ύӎ��ގ�����ID			*/
#define MPC50500	0x5281		  		/* mpc50500() �Ύӎ��ގ�����ID			*/
#define MPC50501	0x5282		  		/* mpc50501() �Ύӎ��ގ�����ID			*/
#define MPC50502	0x5283		  		/* mpc50502() �Ύӎ��ގ�����ID			*/
#define MPC50503	0x5284		  		/* mpc50503() �Ύӎ��ގ�����ID			*/
#define MPC50504	0x5285		  		/* mpc50504() �Ύӎ��ގ�����ID			*/
#define MPC50505	0x5286		  		/* mpc50505() �Ύӎ��ގ�����ID			*/
#define MPC50506	0x5287		  		/* mpc50506() �Ύӎ��ގ�����ID			*/
#define MPC50507	0x5288		  		/* mpc50507() �Ύӎ��ގ�����ID			*/
#define MPC50508	0x5289		  		/* mpc50508() �Ύӎ��ގ�����ID			*/
#define MPC50509	0x528a		  		/* mpc50509() �Ύӎ��ގ�����ID			*/
#define MPC50510	0x528b		  		/* mpc50510() �Ύӎ��ގ�����ID			*/
#define MPC50513	0x528c		  		/* mpc50513() �Ύӎ��ގ�����ID			*/

#define MPC506XX	0x5300		  		/* mpc506xx() �Ύӎ��ގ�����ID			*/
#define MPC50604	0x5301		  		/* mpc50604() �Ύӎ��ގ�����ID			*/

#define MPC507XX	0x5380		  		/* mpc507xx() �Ύӎ��ގ�����ID			*/
#define MPC50704	0x5381		  		/* mpc50704() �Ύӎ��ގ�����ID			*/
#define MPC50705	0x5382		  		/* mpc50705() �Ύӎ��ގ�����ID			*/
#define MPC50706	0x5383		  		/* mpc50706() �Ύӎ��ގ�����ID			*/

#define MPC508XX	0x5400		  		/* mpc508xx() �Ύӎ��ގ�����ID			*/
#define MPC50804	0x5401		  		/* mpc50804() �Ύӎ��ގ�����ID			*/
#define MPC50805	0x5402		  		/* mpc50805() �Ύӎ��ގ�����ID			*/

#define MPC509XX	0x5480		  		/* mpc509xx() �Ύӎ��ގ�����ID			*/
#define MPC50904	0x5481		  		/* mpc50904() �Ύӎ��ގ�����ID			*/
#define MPC50905	0x5482		  		/* mpc50905() �Ύӎ��ގ�����ID			*/

#define MPC510XX	0x5500		  		/* mpc510xx() �Ύӎ��ގ�����ID			*/
#define MPC51004	0x5501		  		/* mpc51004() �Ύӎ��ގ�����ID			*/
#define MPC51005	0x5502		  		/* mpc51005() �Ύӎ��ގ�����ID			*/

#define MPC511XX	0x5580		  		/* mpc511xx() �Ύӎ��ގ�����ID			*/
#define MPC51101	0x5581		  		/* mpc51101() �Ύӎ��ގ�����ID			*/
#define MPC51102	0x5582		  		/* mpc51102() �Ύӎ��ގ�����ID			*/
#define MPC51103	0x5583		  		/* mpc51103() �Ύӎ��ގ�����ID			*/
#define MPC51104	0x5584		  		/* mpc51104() �Ύӎ��ގ�����ID			*/
#define MPC51105	0x5585		  		/* mpc51105() �Ύӎ��ގ�����ID			*/
#define MPC51106	0x5586		  		/* mpc51106() �Ύӎ��ގ�����ID			*/
#define MPC51107	0x5587		  		/* mpc51107() �Ύӎ��ގ�����ID			*/
#define MPC51108	0x5588		  		/* mpc51108() �Ύӎ��ގ�����ID			*/
#define MPC51109	0x5589		  		/* mpc51109() �Ύӎ��ގ�����ID			*/

#define MPC512XX	0x5600		  		/* mpc512xx() �Ύӎ��ގ�����ID			*/
#define MPC51204	0x5601		  		/* mpc51204() �Ύӎ��ގ�����ID			*/
#define MPC51205	0x5602		  		/* mpc51205() �Ύӎ��ގ�����ID			*/
#define MPC51206	0x5603		  		/* mpc51206() �Ύӎ��ގ�����ID			*/
#define MPC51210	0x5604		  		/* mpc51210() �Ύӎ��ގ�����ID			*/
#define MPC51213	0x5605		  		/* mpc51213() �Ύӎ��ގ�����ID			*/
#define MPC51216	0x5606		  		/* mpc51216() �Ύӎ��ގ�����ID			*/

#define MPC513XX	0x5680		  		/* mpc513xx() �Ύӎ��ގ�����ID			*/
#define MPC51304	0x5681		  		/* mpc51304() �Ύӎ��ގ�����ID			*/
#define MPC51305	0x5682		  		/* mpc51305() �Ύӎ��ގ�����ID			*/
#define MPC51306	0x5683		  		/* mpc51306() �Ύӎ��ގ�����ID			*/
#define MPC51310	0x5684		  		/* mpc51310() �Ύӎ��ގ�����ID			*/
#define MPC51313	0x5685		  		/* mpc51313() �Ύӎ��ގ�����ID			*/
#define MPC51316	0x5686		  		/* mpc51316() �Ύӎ��ގ�����ID			*/
#define MPC51399	0x5687		  		/* mpc51399() �Ύӎ��ގ�����ID			*/

#define MPC514XX	0x5700		  		/* mpc514xx() �Ύӎ��ގ�����ID			*/
#define MPC51404	0x5701		  		/* mpc51404() �Ύӎ��ގ�����ID			*/
#define MPC51405	0x5702		  		/* mpc51405() �Ύӎ��ގ�����ID			*/
#define MPC51406	0x5703		  		/* mpc51406() �Ύӎ��ގ�����ID			*/
#define MPC51410	0x5704		  		/* mpc51410() �Ύӎ��ގ�����ID			*/
#define MPC51413	0x5705		  		/* mpc51413() �Ύӎ��ގ�����ID			*/
#define MPC51416	0x5706		  		/* mpc51416() �Ύӎ��ގ�����ID			*/
#define MPC51499	0x5707		  		/* mpc51499() �Ύӎ��ގ�����ID			*/

#define MPC515XX	0x5780		  		/* mpc515xx() �Ύӎ��ގ�����ID			*/
#define MPC51504	0x5781		  		/* mpc51504() �Ύӎ��ގ�����ID			*/
#define MPC51505	0x5782		  		/* mpc51505() �Ύӎ��ގ�����ID			*/
#define MPC51506	0x5783		  		/* mpc51506() �Ύӎ��ގ�����ID			*/
#define MPC51510	0x5784		  		/* mpc51510() �Ύӎ��ގ�����ID			*/
#define MPC51513	0x5785		  		/* mpc51513() �Ύӎ��ގ�����ID			*/
#define MPC51516	0x5786		  		/* mpc51516() �Ύӎ��ގ�����ID			*/

#define MPC516XX	0x5800		  		/* mpc516xx() �Ύӎ��ގ�����ID			*/
#define MPC51604	0x5801		  		/* mpc51604() �Ύӎ��ގ�����ID			*/
#define MPC51605	0x5802		  		/* mpc51605() �Ύӎ��ގ�����ID			*/
#define MPC51606	0x5803		  		/* mpc51606() �Ύӎ��ގ�����ID			*/
#define MPC51610	0x5804		  		/* mpc51610() �Ύӎ��ގ�����ID			*/
#define MPC51613	0x5805		  		/* mpc51613() �Ύӎ��ގ�����ID			*/
#define MPC51616	0x5806		  		/* mpc51616() �Ύӎ��ގ�����ID			*/
#define MPC51699	0x5807		  		/* mpc51699() �Ύӎ��ގ�����ID			*/

#define MPC517XX	0x5880		  		/* mpc517xx() �Ύӎ��ގ�����ID			*/
#define MPC51704	0x5881		  		/* mpc51704() �Ύӎ��ގ�����ID			*/
#define MPC51705	0x5882		  		/* mpc51705() �Ύӎ��ގ�����ID			*/
#define MPC51707	0x5883		  		/* mpc51707() �Ύӎ��ގ�����ID			*/
#define MPC51708	0x5884		  		/* mpc51708() �Ύӎ��ގ�����ID			*/
#define MPC51711	0x5885		  		/* mpc51711() �Ύӎ��ގ�����ID			*/
#define MPC51717	0x5886		  		/* mpc51717() �Ύӎ��ގ�����ID			*/

#define MPC518XX	0x5900		  		/* mpc518xx() �Ύӎ��ގ�����ID			*/
#define MPC51803	0x5901		  		/* mpc51803() �Ύӎ��ގ�����ID			*/
#define MPC51807	0x5902		  		/* mpc51807() �Ύӎ��ގ�����ID			*/
#define MPC51811	0x5903		  		/* mpc51811() �Ύӎ��ގ�����ID			*/
#define MPC51814	0x5904		  		/* mpc51814() �Ύӎ��ގ�����ID			*/
#define MPC51817	0x5905		  		/* mpc51817() �Ύӎ��ގ�����ID			*/

#define MPC519XX	0x5980		  		/* mpc519xx() �Ύӎ��ގ�����ID			*/
#define MPC51902	0x5981		  		/* mpc51902() �Ύӎ��ގ�����ID			*/
#define MPC51906	0x5982		  		/* mpc51906() �Ύӎ��ގ�����ID			*/
#define MPC51910	0x5983		  		/* mpc51910() �Ύӎ��ގ�����ID			*/
#define MPC51913	0x5984		  		/* mpc51913() �Ύӎ��ގ�����ID			*/
#define MPC51916	0x5985		  		/* mpc51916() �Ύӎ��ގ�����ID			*/

#define MPC520XX	0x5a00		  		/* mpc520xx() �Ύӎ��ގ�����ID			*/
#define MPC52002	0x5a01		  		/* mpc52002() �Ύӎ��ގ�����ID			*/
#define MPC52010	0x5a02		  		/* mpc52010() �Ύӎ��ގ�����ID			*/
#define MPC52013	0x5a03		  		/* mpc52013() �Ύӎ��ގ�����ID			*/
#define MPC52016	0x5a04		  		/* mpc52016() �Ύӎ��ގ�����ID			*/

#define MPC521XX	0x5a80		  		/* mpc521xx() �Ύӎ��ގ�����ID			*/
#define MPC52101	0x5a81		  		/* mpc52101() �Ύӎ��ގ�����ID			*/
#define MPC52102	0x5a82		  		/* mpc52102() �Ύӎ��ގ�����ID			*/
#define MPC52110	0x5a83		  		/* mpc52110() �Ύӎ��ގ�����ID			*/
#define MPC52113	0x5a84		  		/* mpc52113() �Ύӎ��ގ�����ID			*/
#define MPC52116	0x5a85		  		/* mpc52116() �Ύӎ��ގ�����ID			*/
#define MPC52199	0x5a86		  		/* mpc52199() �Ύӎ��ގ�����ID			*/

#define MPC522XX	0x5b00		  		/* mpc522xx() �Ύӎ��ގ�����ID			*/
#define MPC52208	0x5b01		  		/* mpc52208() �Ύӎ��ގ�����ID			*/
#define MPC52212	0x5b02		  		/* mpc52212() �Ύӎ��ގ�����ID			*/
#define MPC52215	0x5b03		  		/* mpc52215() �Ύӎ��ގ�����ID			*/
#define MPC52218	0x5b04		  		/* mpc52218() �Ύӎ��ގ�����ID			*/

