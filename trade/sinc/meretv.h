/******************************************/
/*                              V/R = 0/0 */
/*               meretv.h                 */
/*                                        */
/*            SMP������(EDP)�͎ݎ�������           */
/*           ��������ǯ���������  M01  */
/*                   �����ѹ��б�(xxxxxx) */
/*           1995ǯ04��27��          M02  */
/*                   �������ѹ�(ST2607)   */
/* ����������������ǯ�������        M03*/
/* ��̾������ƣͳ��					      */
/*	   �����ѹ��׵��SSCY0079		 	  */
/*     �Ҏӎ؎ʎߎ������׎����ɲä���				  */
/*                                        */
/* ����������������ǯ���������      M04*/
/* ��̾������ƣͳ��					      */
/*	   �����ѹ��׵��SSCY0092		 	  */
/*	   LICP�ؤΎҎ����������������Ԥ��ɲ�		  */
/* ����������������ǯ���������      M05*/
/* ��̾�������ҡ��ξ�				      */
/*	   �ξ����ɼ���ӣԣ�������		 	  */
/*	   �ֵ��ͤθ�ľ��		  			  */
/*                                        */
/******************************************/

#define  MENORMAL    0l      	/*  �������ގ��� �������؎�����       */
#define  MEIVPARM   0xffff0001	/*  �ʎߎ׎Ҏ��� ���׎�            */
#define  MEDUBREQ   0xffff0002	/*  �Ǝ��ގ��� �֎���������         */
#define  MENOTRCV   0xffff0003	/*  ������ �̎�      ��       */
#define  MEMSNDER   0xffff0004	/*  �Ҏ��������� �������� �����ގ���     */
#define  METBLERR   0xffff0005	/*  �Î��̎ގ� ���׎�       ��    */
#define  MEPBUFER   0xffff0006	/*  �̎ߎ��َʎގ��̎� ������ �����ގ���   */
#define  MEOVRENT   0xffff0007	/*  �Ď��ێ����� �����ʎގ�          */
#define  MEIFAERR   0xffff0008	/*  ���ݎ����̎����� ���׎�      ��  */
#define  MEOVRLNG   0xffff0010	/*  �������� �̎ގ���             */
#define  MEOTHDWN   0xffff0012	/*  ������ ���������ގ�            */
#define  MEHRDERR   0xffff0014	/*  �ʎ��Ď� ���������ގ�           */
#define  MECHBLOK   0xffff0015	/*  �����Ȏ� �͎����� ������         */
#define  MEDATERR   0xffff0016	/*  �֎������� ���ގ����Ύ� �̎���      */
#define  MENOTUSE   0xffff001c	/*  DCP ���֎� �̎�            */
#define  MENOTACC   0xffff001e	/*  ������������ �Ŏ�             */
								/* memo ffff001f�ϲ�	  */
#define  MEINVMIA   0xffff0020	/*  MIA �����Î� �Ŏ��֎� �̎���     */
#define  MEMISZER   0xffff0021	/*  MIA �������� �̎ގ���         */
#define  MERSSZER   0xffff0022	/*  �����Ď��؎������� �������� �̎ގ���   */
#define  MEIVPROC   0xffff0023	/*  ����̎ߎێ������     M02 */

/**********************************************************/
/* �ե�����ž����ǽ���ɲäˤ�겼��������ɲ�             */
/*                             ��������������������       */
/**********************************************************/
#define  MEINVLPN   0xffff0024          /* �����ʎߎ�����̾����                */
#define  MEINVSFL   0xffff0025          /* ž�����̎�����̾����                 */
#define  MEINVDFL   0xffff0026          /* ž����̎�����̾����                 */
#define  MEIFEXIS   0xffff0027          /* �̎����ٴ�¸��������������           */
#define  MEINTVAL   0xffff0028          /* ž�����ݎ����ʎގَ�����������             */
#define  MEINVPGN   0xffff0029          /* ��ư�̎ߎێ��ގ׎ю̎�����̾�۾�            */
#define  MELPTUSE   0xffff002A          /* TLPT�����􎽎Î�����������            */
#define  MEFAPUSE   0xffff002B          /* TFAP�����􎽎Î�����������            */
#define  MEFACUSE   0xffff002C          /* TFAC�����􎽎Î�����������            */
#define  MEFAXUSE   0xffff002D          /* TFAX�����􎽎Î�����������            */
#define  MEFALUSE   0xffff002E          /* TFAL�����􎽎Î�����������            */
#define  MEFAPAPI   0xffff002F          /* API���Î��ގ�����                     */
#define  MEFACGRP   0xffff0030          /* TRADE������������                */
#define  MEFCPBGT   0xffff0031          /* ���ώݎĎ޵�ư�ʎߎ׎Ҏ����Խ�����          */
                                        /* �ʎގ��̎����ݰ۾�                    */
/* #define  MESNAMCP   0xffff0032          ž�����̎�����̾���ˎߎ��۾�             */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEDNAMCP   0xffff0033          ž����̎�����̾���ˎߎ��۾�             */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MELPNMCP   0xffff0034          �ü�̎�����̾���ˎߎ��۾�               */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEINTMCV   0xffff0035          ž�����ݎ����ʎގَ������Ѵ��۾�           */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEEXISCV   0xffff0036          �̎����ٴ�¸�������Ѵ��۾�           */
										/* M05 �ֵ��ͤθ�ľ��				*/
#define  MEFTCRET   0xffff0037          /* FTOS�����۾�                     */
#define  MEFWCHLD   0xffff0038          /* FTOS��λ�����׵�۾�             */
#define  MEBUFCLR   0xffff0039          /* �̎ߎ��َʎގ��̎����؎��۾�                 */
/* #define  MEMCCOPY   0xffff003A          ʸ���󎺎ˎߎ��۾�                   */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEIOTYCV   0xffff003B          I/O�����Ѵ��۾�                  */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MELPNOCV   0xffff003C          �����ʎߎ��ֹ��Ѵ��۾�              */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEDDTNCV   0xffff003D          DTE���Ďގڎ�����Ѵ��۾�             */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEIPKSCV   0xffff003E          ȯ�Ƽ������ʎߎ����Ď��������Ѵ��۾�      */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MERPKSCV   0xffff003F          ��Ƽ������ʎߎ����Ď��������Ѵ��۾�      */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEIWDSCV   0xffff0040          ȯ�Ƽ����������ݎĎގ����������Ѵ��۾�     */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MERWDSCV   0xffff0041          ��Ƽ����������ݎĎގ����������Ѵ��۾�     */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEFSSLCV   0xffff0042          �̎����Ď��ڎ����׵��Ѵ��۾�             */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEACCOCV   0xffff0043          �忮�ݶ��Ѵ��۾�                 */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MECLASCV   0xffff0044          ȯ��Ǝ��َ��̎ߎ��Ď��׎��Ѵ��۾�         */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEIXANCV   0xffff0045          ȯ���Ďގڎ���ĥ�Ѵ��۾����        */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEIXADCV   0xffff0046          ȯ���Ďގڎ���ĥ�Ѵ��۾����        */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MERXANCV   0xffff0047          �厱�Ďގڎ���ĥ�Ѵ��۾����        */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MERXADCV   0xffff0048          �厱�Ďގڎ���ĥ�Ѵ��۾����        */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEGWPRCV   0xffff0049          �����̎ߎێĎ����Ѵ��۾�             */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEGWLNCV   0xffff004A          �ǣ�������ֹ��Ѵ��۾�           */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEPNUMCV   0xffff004B          ü���ێ����َ��Ďގڎ��Ѵ��۾�            */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEAPLOCV   0xffff004C          ���ю����Îю��̎ߎ������Ѵ��۾�           */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MERSPTCV   0xffff004D          ���Ȏ���/�Îގ������Ȏ��Ďڎ��Ύߎݎ��Ԥ��������Ѵ�   */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MESEGLCV   0xffff004E          ����ʬ��Îގ���Ĺ�Ѵ��۾������   */
										/* M05 �ֵ��ͤθ�ľ��				*/
/* #define  MEL4WSCV   0xffff004F          �������掳���ݎĎގ����������Ѵ��۾��   */
										/* M05 �ֵ��ͤθ�ľ��				*/
#define  MEDTADCV   0xffff0050          /* ���DTE���Ďގڎ��Ѵ��۾��  		*/

#define  MENOEXEC   0xffff0060          /* ������̎�����ž���׵�ʤ�           */
#define  MEMCHCCN   0xffff0061          /* �����׎����Ѵ��۾�                    */
#define  MEODESPR   0xffff0062          /* FTOS������λ�۾�                 */
#define  MEFTMUJN   0xffff0063          /* �̎�����ž������̷��                 */
#define  MEFTSEND   0xffff0064          /* ��ư�ʎߎ׎Ҏ��������۾�               */
#define  MEFTCANC   0xffff0065          /* �̎ߎێ�����λ�����׵Ꮇ���ݎ���           */
                                        /* �۾�                             */
#define  MEFTTERM   0xffff0066          /* FTOS������λ�۾�                 */
/* #define  MECLERER   0xffff0067          �ΰ莸�؎��۾�  					*/
										/* M05 �ֵ��ͤθ�ľ��				*/
#define  METBADGT   0xffff0068          /* SMP�Î��̎ގَ��Ďގڎ������۾�  */
/********************************/
/* ��ư�ʎߎ׎Ҏ���SG�Ͱ۾�			*/
/********************************/
#define  MESGXADL	0xffff0080			/* TFAX���DTE���Ďގڎ��������			*/
#define  MESGXCWS	0xffff0081			/* TFAXȯ�ƼԎ����ݎĎގ�������������			*/
#define  MESGXRWS	0xffff0082			/* TFAX��ƼԎ����ݎĎގ�������������			*/
#define  MESGXFSL	0xffff0083			/* �̎����Ď��ڎ����׵�SG������				*/
#define  MESGPCHK	0xffff0084			/* �忮�ݶ�����						*/
#define  MESGCXAL	0xffff0085			/* ȯ���Ďގڎ���ĥ����					*/
#define  MESGRXAL	0xffff0086			/* �厱�Ďގڎ���ĥ����					*/
#define  MESGCLAS   0xffff0087			/* �����̎ߎێĎ�������					*/
#define  MESGRSPT	0xffff0088			/* ���Ȏ��Ď��Îގ������Ȏ��Ďڎ��Ύߎݎ��Ԥ�����������	*/
#define  MESGMAXD	0xffff0089			/* ����ʬ��Îގ���Ĺ����				*/
#define  MESGLPWS	0xffff008A			/* �������掳���ݎĎގ�������������			*/
#define  MESGLPNO	0xffff008B			/* �����ʎߎ��ֹ�����					*/

/********************************/
/* �����ѹ��б����ͣ���			*/
/********************************/
#define  MEBPTADR	0xffff0090			/* TBPT���Ďގڎ������۾�          stM01 */
#define  MEBFSERH	0xffff0091			/* �ʎގ��̎����������׎�     					*/
/* #define  MEPLIDCV	0xffff0092			�ʎގ��̎��̎ߎ���ID�Ѵ��۾�        edM01 */
										/* M05 �ֵ��ͤθ�ľ��				*/
#define  MEOSSNMP	0xffff0093			/* LICP�ؤΎҎ�����������������		M04 */
										/* ^retry��AP¦�Ǥ���褦��			*/
/********************************/
/* �����ѹ��б����ͣ���			*/
/********************************/
#define  MEMEPTER	0xffff001f			/* �Ҏӎ؎ʎߎ������׎�						*/
