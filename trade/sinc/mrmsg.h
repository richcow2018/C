/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		�Ҏ���-���� ID �Î����� �̎����� (mrmsg.h)								 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		�؎��ʎގ� ��������													 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		�������� ���� : �Ԏώӎ� �Վ�����											 */
/*		�������� ���� : �Ԏώӎ� �Վ�����						 					 */
/*		�͎ݎ��� ���� : �����ގ� ������				'87/10/01	(L01)			 */
/*			 (�������� �؎��ʎގ� ���ݎڎ� �����ӎ� �� �������ގ�)				---STC395	 */
/*		�͎ݎ������� : �Ύ��� �ˎێĎ�				'87/11/28	(L02)			 */
/*			 (VRCV/BKUP ���ݎ����̎����� �� �֎� �͎ݎ���)				---STC351	 */
/*		�͎ݎ������� : �����ގ� ������			 	'89/07/29   (L03)			 */
/*			 (�ʎގ��������̎� ���� ���Ďގ� ���Ɏ� �� ����)				---TC2701	 */
/*		�͎ݎ������� : �����ގ� ������			 	'89/09/07   (L04)			 */
/*			 (RCV �̎����� ��������/�����̎� �ʎߎ׎Ҏ� �����Î� ���Ɏ� ����)	---TCXXXX	 */
/*		�͎ݎ������� : �����ގ� ������			 	'89/10/19 	(L05)			 */
/*			 (�ʎގ��������̎� �Ύގ؎����� A��B�Ҏ� ���֎� ���Ɏ� �� ����)		---TC3020	 */
/*		�͎ݎ������� : �����ގ� ������			 	'90/04/28	(L06)			 */
/*			 (���ˎߎ��̎ߎێ��� �ώَ� ���Ďގ� ���Ɏ� �� ����)				--- TC3550	 */
/*      �ѹ��� : ����������              93/11/12    TD-00           */
/*                (¾TCư��ƻ��ȼ���ѹ�)           TD-02           */
/*				  (2�Ų������������ѻߤ�ȼ���ѹ�)		 TD-27			 */
/*                (LM��-�̎ގَ؎��ʎގ�Ƴ����ȼ���ѹ�)       TD-39           */
/*                (KJʬΥ��ȼ���ѹ�)				 TD-42			 */
/*                (�ʎގ����̎���JNL������ȼ���ѹ�)      TD-67           */
/*				  (�������JNL�������ȼ���ѹ�)		 TD-79			 */
/*                (KJñ�Ȏʎގ����̎�Ƴ����ȼ���ѹ�)     TD-83           */
/*				  (SMP���դ�Ƴ����ȼ���ѹ�)			 TD-92			 */
/*      �ѹ��� : ���͡��층              95/02/23    CT0881          */
/*		�ѹ��� : ���桡����				 95/03/30 	 CT0977(ST2646)  */
/*				  (2�Ÿξ�������ص�ǽ�ɲä�ȼ���ѹ�				 */
/*				   �����ѹ��׵�� SSCYXXXX)							 */
/*	    �ѹ��� : ���桡����				 95/07/04	 CT1085(ST2987)	 */
/*				  (�Ҏ��������ޤν���:mri)								 */
/*	    �ѹ��� : ���桡����				 95/07/04	 CT1086(ST2988)	 */
/*				  (�Ҏ��������ޤν���:mrp)								 */
/*	    �ѹ��� : ����  ����				 95/07/11	 CT1084(ST2986)	 */
/*				  (�Ҏ��������ޤν���:mrh)								 */
/*		�ѹ��� : �ƺꡡ�һ�				 95/07/24	 ST2893			 */
/*				  (�Ҏ��������ޤν���:mro)								 */
/*	    �ѹ��� : ����  ����				 95/08/08	 CT1102(ST3410)	 */
/*				  (�Ҏ��������ޤν���:jnl)								 */
/*		�ѹ��� : ���͡��층				 95/08/08	 ST3026			 */
/*		�ѹ��� : ���͡��층				 95/08/29	 CT1106(ST3142)	 */
/*      �ѹ��� : ����  ����				 95/09/12					 */
/*                (mr_mdbg�ڤ�mrq���ߤ�ȼ���ѹ�)	 CT1103(ST3408)	 */
/*      �ѹ��� : ����  ����				 95/10/10    ST3492			 */
/*	    �ѹ��� : ����  ����				 95/10/26	 CT1118(ST3410)	 */
/*				  (�Ҏ��������ޤν���:�Ў�-Ʊ��)							 */
/*		�ѹ��� : ���͡��층				 95/11/07	 ST3688			 */
/*	    �ѹ��� : ����  ����				 95/11/16	 CT1163(ST3808)	 */
/*				  (mro��ư���mrp��ưͥ��)							 */
/*	    �ѹ��� : ����  ����				 95/11/24	 ST3802			 */
/*	    �ѹ��� : ����  ����				 95/12/12	 ST3820			 */
/*	    �ѹ��� : ����  ����				 96/01/08	 TD-N7			 */
/*				  (mr_dum2�����󶡤�ȼ���ѹ�)						 */
/*		�ѹ��� : ���桡����				 96/02/16	 ST4036			 */
/*		�ѹ��� : ���桡����				 96/02/21	 ST3754			 */
/*		�ѹ��� : ����  ����				 96/02/21	 ST3921			 */
/*		�ѹ��� : Com'App				 96/02/21	 SSCY0152		 */
/*	    �ѹ��� : ����  ����				 96/02/24	 CT1212(ST4166)	 */
/*				 (SPM����̎�����������ǽ���ߤ�ȼ���ѹ�)				 */
/*		�ѹ��� : ���桡����				 96/02/24	 ST4042			 */
/*				 (mro�Ҏ��������ޤΎ��ҎݎĽ���)								 */
/*		�ѹ��� : ���桡����				 96/02/28	 ST4031			 */
/*				 (mrn���ގ����׎��������ѻߤ�ȼ���ѹ�)						 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*		ms_wtop �ʎߎ׎Ҏ� �� �Î�����										 */
/*********************************************************************/

#define		MRMSGFOM	0x10
#define		MROUTPTN	0x40
#define		MRATGRUP	0
#define		MRATSUBN	0

/*********************************************************************/
/*			1.�̎ߎێ��� �؎��ʎގ� (PRCV)									 */
/*********************************************************************/

#define	MRMSG02	"SR02"	/* ���ѷ� �̎ߎێ��������Ύ�-�� 					TD00 */
						/*   (nnnnnnnn pppppppp cccccccc dddddddd)	 */
						/*   nnnnnnnn : �̎ߎێ��� �����͎ގ� �Ҏ�				 */
						/*   pppppppp : �̎ߎێ��� �����͎ގ� �� (HEX)			 */
						/*   cccccccc : ���Ύ�-�� ��-�Ď� (HEX)			 */
						/*   dddddddd : ���������� ��-�Ď� (HEX)			 */
#define	MRMSG03	"SR03"	/* ͽ���� �̎ߎێ��������Ύ�-�� 					TD00 */
						/*   (nnnnnnnn pppppppp cccccccc dddddddd)	 */
						/*   nnnnnnnn : �̎ߎێ��� �����͎ގ� �Ҏ�				 */
						/*   pppppppp : �̎ߎێ��� �����͎ގ� �� (HEX)			 */
						/*   cccccccc : ���Ύ�-�� ��-�Ď� (HEX)			 */
						/*   dddddddd : ���������� ��-�Ď� (HEX)			 */

/*********************************************************************/
/*			2.����¾�󶡴ؿ�(COMM)									 */
/*********************************************************************/
#define	MRMSG05 "SR05"	/* �؎���������(ffff....)					TDN7 */
#define	MRMSG06 "SR06"	/* �؎����ļ���(ffff....)					TDN7 */
						/*  RC=rrrrrrrr  PN=nnnnnnnn  				 */
						/*   ffff.... : SCSI�ʎގ��ü�̎�����̾			 */ 
						/*   rrrrrrrr : �����Îю�-���ֵ���				 */
						/*   nnnnnnnn : �̎ߎێ�������̾					 */
#define	MRMSG07 "SR07"	/* �ü�̎�����I/O����-(ffff...)				TDN7 */
						/*  TYPE=oooo  RC=rrrrrrrr  PN=nnnnnnnn 	 */
						/*   ffff.... : SCSI�ʎގ��ü�̎�����̾			 */ 
						/*   oooo     : �����Îю�-�ټ���					 */
						/*   rrrrrrrr : �����Îю�-���ֵ���				 */
						/*   nnnnnnnn : �̎ߎێ�������̾					 */
#define	MRMSG08 "SR08"	/* �����ȹ�����						  ST3754 */
						/* (pppppppp dddddddd)						 */ 
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾				 */
						/* dddddddd : osconfig�ֵ���				 */
#define	MRMSG09 "SR09"	/* �ơ��֥륨�顼 (tttt)			  ST3754 */
						/* tttt : �Î��̎ގ�̾							 */
						

/*********************************************************************/
/*			3.RBI �����Ď� ������ (RBI)									 */
/*********************************************************************/

#define	MRMSG10	"SR10"	/* CM�Î��̎ގ��� RBI�̎����� �����ގ���(nnnnnnnn)    TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : �̎ߎێ�������̾			ST3921	 */
						/*   oooooooo : �����Îю����ټ���			ST3921	 */
						/*	 rrrrrrrr : �����Îю������ֵ���		ST3921	 */
#define	MRMSG11	"SR11"	/* LM0�Î��̎ގ��� RBI�̎����� �����ގ���(nnnnnnnn)	TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : �̎ߎێ�������̾			ST3921	 */
						/*   oooooooo : �����Îю����ټ���			ST3921	 */
						/*	 rrrrrrrr : �����Îю������ֵ���		ST3921	 */
#define	MRMSG12	"SR12"	/* LM1�Î��̎ގ��� RBI�̎����� �����ގ���(nnnnnnnn)	TD00 */
						/*  SC = oooooooo  RC = rrrrrrrr	ST3921	 */
						/*   nnnnnnnn : �̎ߎێ�������̾			ST3921	 */
						/*   oooooooo : �����Îю����ټ���			ST3921	 */
						/*	 rrrrrrrr : �����Îю������ֵ���		ST3921	 */
						/* MRMSG13 �� MRMSG18����				TD@1 */

/*********************************************************************/
/*			4.���ގ�-�Ŏ� �����Ď� ������ (JNL)									 */
/*********************************************************************/
										/* ���юÎގ̎����ݺ��(8��)	TD42 */
#define	MRMSG23	"SR23"	/* ���ގ�-�Ŏَ̎����� �����ގ���(s k m) 				TD42 */
						/* ���ݎ�����(nnnnnnnn) SC=oooooooo RC=rrrrrrrr	 */
						/*									CT1102	 */
						/*   nnnnnnnn : �̎ߎێ�������̾			CT1102	 */
						/*   oooooooo : �����Îю����ټ���			CT1102	 */
						/*	 rrrrrrrr : �����Îю������ֵ���		CT1102	 */
#define	MRMSG24	"SR24"	/* ���ގ�-�Ŏَ̎����� �؎��������̎ގ���(s k m)			TD42 */
						/* ���ݎ�����(nnnnnnnn) SC=oooooooo RC=rrrrrrrr	 */
						/*									CT1102	 */
#define	MRMSG25	"SR25"	/* ���ގ�-�Ŏَ̎����� �Ǝ����ݎĎ� (s k m)			TD65 */
						/*   s : 'G'---���ѷ�	'Y'---ͽ����		 */
						/*   k : 'J'---JNL		'K'---KJ			 */
						/*   m : '1'---1��		'2'---2��			 */

/*********************************************************************/
/*		5.�����Î� �؎��ʎގ� (SRCV)										 	*/
/*********************************************************************/

#define	MRMSG30	"SR30"	/* ���ގ�-�ŎَÎ�-������������- (ii dddd rrrrrrrr)		 */
						/*   ii : �Î�-��ID							 */
						/*   dddd : �ڎ�-�Ď� �Ŏ� �Î�-�� ���ʎގ� (DEC)		 */
						/*   rrrrrrrr : �ڎ�-�Ď� ���ʎގ� (DEC)			 */
#define	MRMSG31	"SR31"	/* ���ގ�-�ŎَÎ�-������- (ii dddd rrrrrrrr)			 */
						/*   ii : �Î�-��ID							 */
						/*   dddd : �ڎ�-�Ď� �Ŏ� �Î�-�� ���ʎގ� (DEC)		 */
						/*   rrrrrrrr : �ڎ�-�Ď� ���ʎގ� (DEC)			 */
#define	MRMSG32	"SR32"	/* ���ގ�-�Ŏَڎ�-�Ďގ���- (rrrrrrrr)				 */
						/*   rrrrrrrr : �ڎ�-�Ď� ���ʎގ� (DEC)			 */
#define	MRMSG33	"SR33"	/* ���ގ�-�ŎَÎ�-��ID����- (ii dddd rrrrrrrr)		 */
						/*   ii : �Î�-��ID							 */
						/*   dddd : �ڎ�-�Ď� �Ŏ� �Î�-�� ���ʎގ� (DEC)		 */
						/*   rrrrrrrr : �ڎ�-�Ď� ���ʎގ� (DEC)			 */
#define	MRMSG38	"SR38"	/* ������ �Ҏ���������(���������� �Îގ��̎ߎڎ�)		   (L02) */
#define	MRMSG39	"SR39"	/* �������؎��� �Ҏ���������(���������� �Îގ��̎ߎڎ�)		   (L02) */
#define	MRMSG57	"SR57"	/* �Ύގ؎����ю؎��ʎގ� ������ �� �����Îю��ގ��� 				 */

/*********************************************************************/
/*		6.	�ξ�����ץ���                                	TD-00*/
/*********************************************************************/

#define MRMSG40 "SR40"	/* VRCV ���Ďގ�								 */
						/* �̎ގێ��������ѹ���ȼ�����(17��)      TD01 */
#define	MRMSG41	"SR41"	/* ���ѷώ��ގ�-�Ŏَ̎����ٸξ�(1��)            TD67 */
#define	MRMSG42	"SR42"	/* ���ѷώ��ގ�-�Ŏَ̎����ٸξ�(2��)            TD67 */
#define	MRMSG43	"SR43"	/* ���ѷώ��ގ�-�Ŏَ̎����ٸξ�(ξ��)           TD67 */
#define	MRMSG44	"SR44"	/* ͽ���ώ��ގ�-�Ŏَ̎����ٸξ�(1��)            TD67 */
#define	MRMSG45	"SR45"	/* ͽ���ώ��ގ�-�Ŏَ̎����ٸξ�(2��)            TD67 */
#define MRMSG46 "SR46"  /* ͽ���ώ��ގ�-�Ŏَ̎����ٸξ�(ξ��)           TD67 */
#define	MRMSG47	"SR47"	/* ���ѷϴ���ȹ�̎����ٸξ�(1��)          TD83 */
#define	MRMSG48	"SR48"	/* ���ѷϴ���ȹ�̎����ٸξ�(2��)          TD83 */
#define	MRMSG49	"SR49"	/* ���ѷϴ���ȹ�̎����ٸξ�(ξ��)         TD83 */
#define	MRMSG4A "SR4A"	/* ͽ���ϴ���ȹ�̎����ٸξ�(1��)          TD83 */
#define	MRMSG4B	"SR4B"	/* ͽ���ϴ���ȹ�̎����ٸξ�(2��)          TD83 */
#define	MRMSG4C	"SR4C"	/* ͽ���ϴ���ȹ�̎����ٸξ�(ξ��)         TD83 */
#define	MRMSG4D	"SR4D"	/* ���ѷ�RBI�̎����ٸξ�                    TD39 */
#define	MRMSG4E	"SR4E"	/* ͽ����RBI�̎����ٸξ�                    TD39 */
#define	MRMSG4F	"SR4F"	/* �Ե���JNL�̎����ٸξ�(1��)             CT0977 */
#define	MRMSG4G	"SR4G"	/* �Ե���KJ�̎����ٸξ�(1��)              CT0977 */
#define	MRMSG4H	"SR4H"	/* �Ե���JNL�̎����ٸξ�(2��)             CT0977 */
#define	MRMSG4I	"SR4I"	/* �Ե���KJ�̎����ٸξ�(2�� )             CT0977 */
#define	MRMSG4J	"SR4J"	/* �Ў�-�Ύގ؎�-��(vvvvvvvv)�ҷ�(s)�ξ�(eeeeeeee)  */
						/*									  CT1084 */
						/*   vvvvvvvv : �����Ύގ؎�-�Ѽ���̾			 */
						/*   s        : ��/����ʬ					 */
						/*   eeeeeeee : ����-��-�Ď�						 */
#define	MRMSG4K	"SR4K"	/* ������ʸ����						ST3802	 */ 
						/*	MK1=0x0m  MK2=0x0k  PNAME=nnnnnnnn		 */ 
						/*  IF1=0xiiii  IF2=0xffff  				 */ 
						/*	 m        : MK��-�Ď�1						 */
						/*	 k        : MK��-�Ď�2						 */
						/*   nnnnnnnn : �̎ߎێ�������̾					 */
						/*   iiii	  : ���ݎ�-�̎�-����-�Ď�1				 */
						/*   ffff	  : ���ݎ�-�̎�-����-�Ď�2				 */

/*********************************************************************/
/*      7. �֣ңã��������ץ����ʣ��֣ңã֡�                 TD00 */
/*********************************************************************/
#define	MRMSG50	"SR50"	/* VRCV����������(���ѷ�)				TD90 */
#define	MRMSG51	"SR51"	/* VRCV����������(ͽ����)				TD90 */
#define	MRMSG52	"SR52"	/* RCV���׎����ÎѤǤ���					TD90 */
#define	MRMSG53	"SR53"	/* ����ʪ���Ύގ؎�-��(pppppppp)�ĺɼ���(dddddddd)*/
						/*										TD90 */
						/*   pppppppp : ʪ���Ύގ؎�-�Ѽ���̾			 */
						/*   dddddddd : �َܺ�-�Ď�     	             */
#define	MRMSG54 "SR54"	/* ��Ԏ؎��ʎގ���Ǥ���                    TD90 */
#define	MRMSG55 "SR55"	/* ͽ���Ϥ˵�ư���줿                   TD90 */
#define	MRMSG56	"SR56"	/* �ʎߎ׎Ҏ��Ŀ�����						TD90 */
						/* ����(�����Îю؎��ʎގؤ�����)                TD00 */
#define	MRMSG58	"SR58"	/* VRCV��BKUP��Ǥ���                   TD90 */
#define MRMSG59	"SR59"	/* ���ѷ�JNL�̎����ٸξ�(1��)               TD78 */
#define MRMSG5A	"SR5A"	/* ���ѷ�JNL�̎����ٸξ�(2��)               TD78 */
/* ����ʣ��ԡ�												ST4031	 */
#define MRMSG5C	"SR5C"	/* ͽ����JNL�̎����ٸξ�(1��)               TD78 */
#define MRMSG5D	"SR5D"	/* ͽ����JNL�̎����ٸξ�(2��)               TD78 */
/* ����ʣ��ԡ�												ST4031	 */
#define MRMSG5F	"SR5F"	/* ���ѷϴ���ȹ�̎����ٸξ�(1��)          TD78 */
#define MRMSG5G	"SR5G"	/* ���ѷϴ���ȹ�̎����ٸξ�(2��)          TD78 */
/* ����ʣ��ԡ�												ST4031	 */
#define MRMSG5I	"SR5I"	/* ���ѷϴ���ȹ�̎����ٸξ�(1��)          TD78 */
#define MRMSG5J	"SR5J"	/* ���ѷϴ���ȹ�̎����ٸξ�(2��)          TD78 */
#define	MRMSG5K	"SR5K"	/* ʪ���Ύގ؎����Ѥ��ĺɤ���ޤ��� (pppppppp)TD78 */
						/*   pppppppp : ʪ���Ύގ؎����Ѽ���̾ 			 */
#define	MRMSG5L "SR5L"	/* ���ѷ�RBI�̎����ٸξ�                    TD78 */
#define	MRMSG5M "SR5M"	/* ͽ����RBI�̎����ٸξ�                    TD78 */
#define	MRMSG5N "SR5N"	/* VRCV��������λ(���ѷ�)               TD90 */
#define	MRMSG5O "SR5O"	/* VRCV��������λ(ͽ����)               TD90 */
#define	MRMSG5P	"SR5P"	/* ¾��ʪ���Ύގ؎�-��(pppppppp)�ĺɼ���     TD90 */
						/*   pppppppp : ʪ���Ύގ؎�-�Ѽ���̾			 */
#define	MRMSG5Q	"SR5Q"	/* JNL�̎����ٽ������						TD79 */
#define	MRMSG5R	"SR5R"	/* KJ�̎����ٽ������						TD79 */
#define	MRMSG5S	"SR5S"	/* RBI�̎����ٽ������						TD79 */

/*********************************************************************/
/*	    8.�ʎގ��������̎� ������ (BKUP)									     */
/*********************************************************************/

#define	MRMSG60	"SR60"	/*											 */
#define	MRMSG61	"SR61"	/* ���ގݎ֎����� �ʎގ��������̎� ( xxxxxxxx ) ������   TD-46 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
#define	MRMSG62	"SR62"	/* ���ގݎ֎����� �ʎގ��������̎� ( xxxxxxxx )	   TD-46 */ 
						/* �������ގ��� �������؎���	 				   TD-46 */
						/*	code  =  eeee						 	 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	eeee : �������؎��� �����Ď�	( DEC )				 */
#define	MRMSG63	"SR63"	/* ���ގݎ֎����� �ʎގ��������̎� ( xxxxxxxx )	   TD-46 */ 
						/* �����ގ��� �������؎���	 					   TD-46 */
						/*	CD = eeee						   TD-49 */
						/*	DT = pppppppp					   TD-49 */
						/*	DT1 = qqqqqqqq					   TD-49 */
						/*	DT2 = rrrrrrrr					   TD-49 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	eeee 	 : �ξ㥳����			   TD-49 */
						/*	pppppppp : �ܺپ���				   TD-49 */
						/*	qqqqqqqq : �ܺپ���			   TD-49 */
						/*	rrrrrrrr : �ܺپ���			   TD-49 */
#define	MRMSG64	"SR64"	/* �֎ˎގ��� �ʎގ��������̎� ( xxxxxxxx ) ������	   TD-46 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
#define	MRMSG65	"SR65"	/* �֎ˎގ��� �ʎގ��������̎� ( xxxxxxxx ) 		   TD-46 */
						/* �������ގ��� �������؎���					   TD-46 */
						/*	code  =  eeee							 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 eeee : �������؎��� �����Ď�	( DEC )				 */
#define	MRMSG66	"SR66"	/* �֎ˎގ��� �ʎގ��������̎� ( xxxxxxxx ) 		   TD-46 */
						/* �����ގ��� �������؎��� 					   TD-46 */
						/*	CD = eeee						   TD-49 */
						/*	DT = pppppppp					   TD-49 */
						/*	DT1 = qqqqqqqq					   TD-49 */
						/*	DT2 = rrrrrrrr					   TD-49 */
						/*  xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	eeee 	 : �ξ㥳����			   TD-49 */
						/*	pppppppp : �ܺپ���				   TD-49 */
						/*	qqqqqqqq : �ܺپ���			   TD-49 */
						/*	rrrrrrrr : �ܺپ���			   TD-49 */
#define	MRMSG67	"SR67"	/* �Ύގ؎����� �ʎގ��������̎� ������ ( xxxxxxxx )    TD-46 */
						/*	p=pppppppp 	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll	 			   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG68	"SR68"	/* �Ύގ؎����� �ʎގ��������̎� �������ގ��� �������؎���			 */
						/*  ( xxxxxxxx )					   TD-46 */
						/*	p=pppppppp 	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll				   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG69	"SR69"	/* �Ύގ؎����� �ʎގ��������̎� �����ގ��� �������؎���				 */
						/*  ( xxxxxxxx )					   TD-46 */
						/*	p=pppppppp	n=nnnnnnnn	   TD-46   TD-22 */
						/*	l=llllllllllllllll	 			   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG6A	"SR6A"	/* �Ύގ؎����� �ʎގ��������̎� ������ (�Ў׎�)			TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */ 
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG6B	"SR6B"	/* �Ύގ؎����� �ʎގ��������̎� �������ގ��� �������؎��� (�Ў׎�)  TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */ 
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG6C	"SR6C"	/* �Ύގ؎����� �ʎގ��������̎� �����ގ��� �������؎��� (�Ў׎�)   TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG6D	"SR6D"	/* �Ύގ؎����� �ʎގ��������̎� �����ݎ��� (�Ў׎�)			TD22 */
						/*	(xxxxxxxx) ps=pppppppp pf=pppppppp TD-22 */
						/*									   TD-46 */
						/*	n=nnnnnnnn						   TD-22 */
						/*  l=llllllllllllllll	 			   TD-22 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�		  	 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG6E	"SR6E"	/* KJ �̎����� 2���ގ����������� �ʎގ��������̎� �̎�		TD42 */
						/*	(xxxxxxxx) kname = kkkkkkkk	  D-42 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 kkkkkkkk : KJ �̎����َҎ�			 		 */
#define	MRMSG6F	"SR6F"	/* KJ �̎����� �ʎގ��������̎� ������					TD42 */
						/*	(xxxxxxxx) kname = kkkkkkkk	 TD-42 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 kkkkkkkk : KJ �̎����َҎ�			 		 */
#define	MRMSG70	"SR70"	/* �Ύގ؎����� �ʎގ��������̎� �����ݎ��� ( xxxxxxxx )  TD-46 */
						/*	p=pppppppp	n=nnnnnnnn			   TD-22 */
						/*	l=llllllllllllllll			 		     */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 nnnnnnnn : �ێݎ؎Ύގ؎����ю����͎ގҎ�	   TD-22 */
						/*	 lll..lll : �̎����َ����ÎюŎ� �����׎����Ď������̎����َҎ�	 */
#define	MRMSG71	"SR71"	/* ���ގ����Ŏ� �̎����� 2���ގ����������� �ʎގ��������̎� �̎�   TD-@1 */
						/*	(xxxxxxxx) jname = jjjjjjjj		   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 jjjjjjjj : ���ގ����Ŏ� �̎����َҎ�		   TD-27 */
#define	MRMSG72	"SR72"	/* 	�ʎގ��������̎� �Ύގ؎����� I/O ���׎� �ʎ�����	   (L03) */
						/*	(xxxxxxxx) p=pppppppp 			   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
#define	MRMSG73	"SR73"	/* ���ގ����Ŏ� �̎����� �ʎގ��������̎� ������			   TD-27 */
						/*	(xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 jjjjjjjj : ���ގ����Ŏ� �̎����َҎ�		   TD-27 */
#define	MRMSG74 "SR74"  /* ���ގ����Ŏ� �̎����� �ʎގ��������̎� �������ގ��� �������؎���  TD-27 */
						/*  (xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 jjjjjjjj : ���ގ����Ŏ� �̎����َҎ�			 	 */
#define	MRMSG75 "SR75"  /* KJ �̎����� �ʎގ��������̎� �������ގ��� �������؎���  	   TD-27 */
						/*  (xxxxxxxx) kname = kkkkkkkk	 TD-27 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 kkkkkkkk : KJ �̎����َҎ�			 	 	 */
#define	MRMSG76 "SR76"  /* ���ގ����Ŏ� �̎����� �ʎގ��������̎� �����ގ��� �������؎���   TD-27 */
						/*  (xxxxxxxx) jname = jjjjjjjj	 TD-27 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 jjjjjjjj : ���ގ����Ŏ� �̎����َҎ�			 	 */
#define	MRMSG77 "SR77"  /* KJ �̎����� �ʎގ��������̎� �����ގ��� �������؎���       TD-27 */
						/*  (xxxxxxxx) kname = kkkkkkkk	 TD-27 TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 kkkkkkkk : KJ �̎����َҎ�			 	 	 */
/*  ���Ų����������ѻߤ�ȼ������ʣ����ԡ�						TD27 */
#define	MRMSG7A	"SR7A"	/* 	���׎Ҏ� I/O ���׎� �ʎ�����				   (L05) */
						/*	(xxxxxxxx) p=pppppppp ����=uuuuuuuu  TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*	 pppppppp : �̎ގ� �Ύގ؎����� �����͎ގҎ�			 */
						/*	 uuuuuuuu : ���׎Ҏ� �̎ގ� �Ύގ؎����� �����͎ގҎ�	 */
#define	MRMSG7B	"SR7B"	/* 	���Î� �ʎގ��������̎�ID �����ގ��� (xxxxxxxx)	    TD46 */
						/*   xxxxxxxx : �ʎގ��� �����̎� ID		   TD-46 */
#define	MRMSG7C	"SR7C"	/* 	���Î� �ێݎ� �Ύގ؎����� �����͎ގҎ� �����ގ���	   (L06) */
						/*	(xxxxxxxx) l=llllllll			   TD-46 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			   TD-46 */
						/*   llllllll : �ێݎ� �Ύގ؎����� �����͎ގҎ�			 */
#define	MRMSG7D	"SR7D"	/* 	�ʎߎ׎Ҏ� �����ގ���				   	 (L06) TD-46 */
/*  �Хå����å��ѹ���ȼ������ʣ��ԡ�						   TD-46 */
/*  ���Ų����������ѻߤ�ȼ������ʣ��ԡ�					   TD-27 */

/*********************************************************************/
/*	    9.�Ύގ؎�-�� �؎��ʎގ� �Ύݎ��� (VRCV)						   		     */ 
/*********************************************************************/

#define	MRMSG80	"SR80"	/* ���ѷώΎގ؎����ю؎��ʎގس���			    TD00 */
#define	MRMSG81	"SR81"	/* ͽ���ώΎގ؎����ю؎��ʎގس���			    TD00 */
#define	MRMSG82	"SR82"	/* ���ѷώΎގ؎����ю؎��ʎގؽ�λ				TD00 */
						/* (cccccccc)							TD00 */
						/* cccccccc : �ֵ���					TD00 */
#define	MRMSG83	"SR83"	/* ͽ���ώΎގ؎����ю؎��ʎގؽ�λ				TD00 */
						/* (cccccccc)							TD00 */
						/* cccccccc : �ֵ���					TD00 */
#define	MRMSG84	"SR84"	/* �Хå����å׵�ư��					TD00 */
#define	MRMSG85	"SR85"	/* �����Ύގ؎����ю؎��Ď�����					TD90 */
						/* (llllllll ssssssss)					TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
						/* ssssssss : ��������					TD00 */	
						/* 1 : �ʎގ��������̎ߎÎގ�������Ύ؎��Ď�			TD00 */
						/* 2 : ���̎̎����َΎގ؎����ѽ����				TD00 */
						/* 3 : RCV�̎����َΎގ؎����ѽ����				TD00 */
						/* 4 : �܎����̎����َΎގ؎����ѽ����				TD00 */
						/* 5 : �Ў׎��Ύގ؎���������					TD00 */
#define	MRMSG86	"SR86"	/* �Ύގ؎����ю؎��ʎގ����оݎΎގ؎�����¸��			TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSG87	"SR87"	/* �����Ύގ؎����ю؎��Ď���λ					TD90 */
						/* (llllllll ssssssss)					TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
						/* ssssssss : ��������					TD00 */	
						/* 1 : �ʎގ��������̎ߎÎގ�������Ύ؎��Ď�			TD00 */
						/* 2 : ���̎̎����َΎގ؎����ѽ����				TD00 */
						/* 3 : RCV�̎����َΎގ؎����ѽ����				TD00 */
						/* 4 : �܎����̎����َΎގ؎����ѽ����				TD00 */
						/* 5 : �Ў׎��Ύގ؎���������					TD00 */
#define	MRMSG88	"SR88"	/* �Ύގ؎����ю؎��Ď�����						TD00 */
						/* (pppppppp dddddddd)					TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */		 
#define	MRMSG89	"SR89"	/* �Ύގ؎����ю؎��Ď���λ						TD00 */
						/* (cccccccc pppppppp)					TD00 */
						/* cccccccc : �ֵ���					TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSG90	"SR90"	/* �ʎގ��������̎ߎΎގ؎�����̤¸��					TD00 */
						/* (llllllll pppppppp)					TD00 */		 
						/* llllllll : �����ܥ�塼�༱��̾		TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSG91	"SR91"	/* �ʎގ��������̎ߎ��ގ����Ŏ٤�������쳫��			TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */		 
#define	MRMSG92	"SR92"	/* �ʎގ��������̎ߎ��ގ����Ŏ٤�������콪λ			TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */		 
#define	MRMSG93	"SR93"	/* ���ގ����Ŏَڎ����Ďގ��׎�						TD00 */
						/* (nnnnnnnn)							TD00 */
						/* nnnnnnnn : JNL�ڎ����Ď�����				TD00 */
#define	MRMSG94	"SR94"	/* ���ގ����ŎَÎގ������׎�						TD00 */
						/* (iiii ss nnnnnnnn)					TD00 */
						/* iiii : JNL�Îގ�����						TD00 */
						/* ss : JNL�Îގ���ID						TD00 */
						/* nnnnnnnn : JNL�ڎ����Ď�����				TD00 */ 
#define	MRMSG95	"SR95"	/* �ʎގ��������̎ߎ��ގ����Ŏٰ۾�					TD00 */
						/* (llllllll nnnnnnnn)					TD00 */
						/* llllllll : �����ܥ�塼�༱��̾		TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */
#define	MRMSG96	"SR96"	/* �Ď����ގ� ���ގ����Ŏ� ���� �� �̎������� ������				 */
#define	MRMSG97	"SR97"	/* �Ď����ގ� ���ގ����Ŏ� ���� �� �̎������� �������؎���			 */
#define	MRMSG98	"SR98"	/* ���Î� �̎ގ� �Ύގ؎����� �� ���ݎ��ގ� 					 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSG99	"SR99"	/* �؎��Ď� ���������� �ێݎ� �Ύގ؎����� �� ���ݎ��ގ�			 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGA0	"SRA0"	/* �̎ގ� �Ύގ؎����� �� ���Î�						 */
#define	MRMSGA1	"SRA1"	/* ����Ύގ؎����Ѹξ�						TD00 */
						/* (cccccccc llllllll)					TD00 */
						/* cccccccc : �����Ύގ؎����ю��׎������Ď�			TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGA2	"SRA2"	/* ʪ���Ύގ؎������������ｪλ				TD00 */
						/* (pppppppp dddddddd)					TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */		 
#define	MRMSGA3	"SRA3"	/* ʪ���Ύގ؎���������۾ｪλ					 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGA4	"SRA4"	/* �������ގ����Ŏٰ۾�						TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGA5	"SRA5"	/* �؎��Ď� 'FJ' �̎������� �ڎݎ��ގ� ���Î� �̎�				 */
#define	MRMSGA6	"SRA6"	/* �؎��Ď� 'FJ' �̎������� ���ݎĎގ� ���Î� �̎�				 */
#define	MRMSGA7	"SRA7"	/* �ʎގ��������̎ߎΎގ؎����Ѹξ�					TD00 */
						/* (bbbbbbb llllllll)						 */
						/* bbbbbbbb : �ʎގ��������̎������Ύގ؎����Ѽ���̾	TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGA8	"SRA8"	/* �ʎގ��������̎�ID��������				  	TD00 */
						/* (dddddddd)							TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */
#define	MRMSGA9	"SRA9"	/* ʪ���Ύގ؎����Ѳ�����λ					TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGB0	"SRB0"	/* �Ύގ؎����ю��ˎߎ��̎ߎێ���������λ				TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
/* �ܥ�塼���ĺ�ñ���ѹ���ȼ������ʣ��ԡ�						TD90 */ 
#define	MRMSGB2	"SRB2"	/* �Ύގ؎����ѽ���������۾ｪλ				TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGB3	"SRB3"	/* �ĺɤ��줿ʪ���Ύގ؎����Ѥ�¸�ߤ���		TD00 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGB4	"SRB4"	/* �֣ңã���������ư��					TD90 */
#define	MRMSGB5	"SRB5"	/* �֣ңã��о������ܥ�塼��̤¸��		TD90 */
						/* (pppppppp)							TD00 */
						/* pppppppp : ʪ���Ύގ؎����Ѽ���̾			TD00 */
#define	MRMSGB6	"SRB6"	/* �����Ύގ؎������������ｪλ				TD90 */
						/* (llllllll dddddddd)					TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
						/* dddddddd : �ʎގ��������̎�ID				TD00 */		 
#define	MRMSGB7	"SRB7"	/* �����Ύގ؎���������۾ｪλ				TD90 */
						/* (llllllll cccccccc)					TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */
						/* cccccccc : �װ�������				TD00 */
#define	MRMSGB8	"SRB8"	/* �����Ύގ؎����Ѳ�����λ					TD00 */
						/* (llllllll)							TD00 */
						/* llllllll : �����Ύގ؎����Ѽ���̾			TD00 */

/*********************************************************************/
/*	    10.���ָξ����											TD00 */
/*********************************************************************/
#define	MRMSGC0	"SRC0"	/* �ʎގ��Î؎��ξ�							TD02 */
#define	MRMSGC1 "SRC1"	/* (pppppppp)�ĺɼ���(dddddddd)			TD02 */
						/*  pppppppp : ʪ���Ύގ؎����Ѽ���̾		ST3492	 */
						/*	dddddddd : �َܺ����Ď�(�ֵ���)			     */
#define	MRMSGC2 "SRC2"  /* (pppppppp)�ĺɲ������(dddddddd)		TD02 */
						/*  pppppppp : ʪ���Ύގ؎����Ѽ���̾		ST3492	 */
						/*	dddddddd : �َܺ����Ď�(�ֵ���)			     */

						/* �Ύގ؎�-�ѽ�����̎ߎێ����ѻߤ�ȼ�����(12��)TD@1 */

/*********************************************************************/
/*	    11.RCV �̎����� ���������������̎� ������								     */
/*********************************************************************/

#define	MRMSGE0	"SRE0"	/* �̎ߎێ��ގ׎� ��-�Ď� ����-							 */
#define	MRMSGE1	"SRE1"	/* �؎��ʎގ� ��-�Ď� ����-							 */
#define	MRMSGE2	"SRE2"	/* nnnn ��-�̎ގ� �ЎÎ����� ����-					 	 */
						/*	 nnnn : �ЎÎ����� ��-�̎ގ� �Ҏ�					 */
#define	MRMSGE3	"SRE3"	/* nnnn ��-�̎ގ� �̎Ď� ����-						 */
						/*	 nnnn : �̎Ď� ��-�̎ގ� �Ҏ�					 */
#define	MRMSGE4	"SRE4"	/* nnnn �̎����� �֎� TFMT �ЎÎ����� ����-				 */
						/* �� llllllll ��				      (TD42) */
						/*	 nnnn : "RBI " �ώ��� "JNL "				 */
						/*	 llllllll : RCV�̎�����̾			  (TD42) */
#define	MRMSGE5	"SRE5"	/* nnnn �̎����� �֎� TFMT �������֎��؎��� ����-			 */
						/* �� llllllll ��					  (TD42) */
						/*	 nnnn : "RBI " �ώ��� "JNL "				 */
						/*	 llllllll : RCV�̎�����̾			  (TD42) */
#define	MRMSGE6	"SRE6"	/* nnnn �̎����� �֎� �Ύގ؎�-�� �̎Ď� ����-			 	 */
						/* �� llllllll ��					  (TD42) */
						/*	 nnnn : "RBI " �ώ��� "JNL "				 */
						/*	 llllllll : RCV�̎�����̾			  (TD42) */
#define	MRMSGE7	"SRE7"	/* nnnn �̎����� �������� ����-						 */
						/*	( llllllll , oooooooo , dddddddd )		 */
						/*	 nnnn     : "RBI " �ώ��� "JNL "			 */
						/*	 llllllll : RCV �̎����� �Ҏ�					 */
						/*	 oooooooo : �����Î� ��-�� 			 		 */
						/*   dddddddd : ���������� ��-�Ď� (HEX)		 	 */
#define	MRMSGE8	"SRE8"	/* nnnn �Îގ��ڎ��Ď� �������� ����-					 */
						/*	( llllllll , oooooooo , dddddddd )		 */
						/*	 nnnn     : "RBI " �ώ��� "JNL "			 */
						/*	 llllllll : RCV �̎����� �Ҏ�					 */
						/*	 oooooooo : �����Î� ��-�� 					 */
						/*   dddddddd : ���������� ��-�Ď� (HEX)			 */
#define	MRMSGE9	"SRE9"	/* �ʎߎ׎Ҏ� ����-								 */
#define MRMSGEA "SREA"  /* ��ư���̎ߎێ������׎�					  (TD79) */
#define MRMSGEB "SREB"  /* SMP���ռ������׎�					  (TD92) */
#define	MRMSGEC	"SREC"	/* �ң£������������߼���(dddddddd) CT1085 */
						/* dddddddd : RBI��λ������ʸ���Υ�����		 */
#define	MRMSGF0	"SRF0"	/* nnnn �̎����� �������� ������ ( llllllll )		 	 */
						/*	 nnnn     : "RBI " �ώ��� "JNL "			 */
						/*	 llllllll : �������� �̎����� �Ҏ�				 */
#define	MRMSGF1	"SRF1"	/* nnnn �̎����� �������� �������؎��� ( llllllll )	 	 */
						/*	 nnnn     : "RBI " �ώ��� "JNL "			 */
						/*	 llllllll : �������� �̎����� �Ҏ�				 */
/*  ���Ų������������ѻߤ�ȼ������ʣ��ԡ�				      (TD27) */
#define	MRMSGF4	"SRF4"	/* RCV �̎����� �������� �����̎� ������ �������؎��� ( dddddddd )*/
						/*   dddddddd : �������؎��� ��-�Ď�					 */
#define	MRMSGF5	"SRF5"	/* nnnn��ͭ����(eeeeeeee oooooooo dddddddd)  */
						/*									CT1085	 */
						/*   nnnn : ��ͭ���ԥơ��֥�̾				 */
						/*   eeeeeeee : mf_renq�ֵ���				 */
						/*   oooooooo : �����ƥॳ�������			 */
						/*   dddddddd : �����ƥॳ�����ֵ���		 */
#define	MRMSGF6	"SRF6"	/* ������ʸ�˴�����(oooooooo dddddddd) CT1085*/
						/*   oooooooo : �����ƥॳ����				 */
						/*   dddddddd : �����ƥॳ�����ֵ���		 */
#define	MRMSGF7	"SRF7"	/* �ң£ɼ����ץ������ԣУãԤˤʤ� CT1085 */
#define	MRMSGF8	"SRF8"	/* �ң£������������߰�����ʸ��	  CT1085 */
						/* �ס���Хåե��γ��ݼ���					 */
						/* (eeeeeeee oooooooo dddddddd)				 */	
						/*   eeeeeeee : mr_cgbf�ֵ���				 */
						/*   oooooooo : �����ƥॳ�������			 */
						/*   dddddddd : �����ƥॳ�����ֵ���		 */
#define	MRMSGF9	"SRF9"	/* �ң£ɼ����ץ����ؤ���ʸ�������� CT1085 */
						/* (oooooooo dddddddd)				 	  	 */	
						/*   oooooooo : �����ƥॳ����̾			 */
						/*   dddddddd : �����ƥॳ�����ֵ���		 */
#define	MRMSGFA	"SRFA"	/* �ң£ɴ�λ������ʸ��������		  CT1085 */
						/* (oooooooo dddddddd)				 	  	 */	
						/*   oooooooo : �����ƥॳ����̾			 */
						/*   dddddddd : �����ƥॳ�����ֵ���		 */
#define	MRMSGFB	"SRFB"	/* �ң£ɴ�λ������ʸ�������� 		  CT1085 */
						/* �ʥ����४���С���						 */

/*********************************************************************/
/*	    12.���̎ގ����Î� �؎��ʎގ� (SSRCV)									 */
/*********************************************************************/
#define	MRMSGG0	"SRG0"	/* PU0���ώҎ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGG1	"SRG1"	/* PU0��λ�Ҏ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGG2	"SRG2"	/* PU1���ώҎ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGG3	"SRG3"	/* PU1��λ�Ҏ���������(�վ��ѥͥ�)			TD39 */

/*********************************************************************/
/*	    13.��� �؎��ʎގ� (ARCV)										 */
/*********************************************************************/
#define	MRMSGH0	"SRH0"	/* PU0���ώҎ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGH1	"SRH1"	/* PU0��λ�Ҏ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGH2	"SRH2"	/* PU1���ώҎ���������(�վ��ѥͥ�)			TD39 */
#define	MRMSGH3	"SRH3"	/* PU1��λ�Ҏ���������(�վ��ѥͥ�)			TD39 */

/*********************************************************************/
/*      14.�Ύގ؎����ю؎��ʎގ�(FJ̵��)										 */
/*********************************************************************/
#define	MRMSGI0	"SRI0"	/* ���ѷϥܥ�塼��ꥫ�Х곫��			TD99 */
#define	MRMSGI1	"SRI1"	/* ͽ���ϥܥ�塼��ꥫ�Х곫��			TD99 */
#define	MRMSGI2	"SRI2"	/* ���ѷϥܥ�塼��ꥫ�Х꽪λ			TD99 */
						/*	CD = cccccccc						 	 */
						/*	 cccccccc : ��λ�����Ď�(10��)				 */
#define	MRMSGI3	"SRI3"	/* ͽ���ϥܥ�塼��ꥫ�Х꽪λ			TD99 */
						/*	CD = cccccccc							 */
						/*	 cccccccc : ��λ�����Ď�(10��)				 */
#define	MRMSGI4	"SRI4"	/* �ꥫ�Х����ץ����ƥ�Ǥ���			TD99 */
#define	MRMSGI5	"SRI5"	/* �ۥåȥ�����Х�����ͽ���Ϥǵ�ư		TD99 */
						/* ���줿									 */
#define	MRMSGI6	"SRI6"	/* �ơ��֥륨�顼		        		TD99 */
						/* TBL = xxxxxxxx							 */
						/*	 xxxxxxxx : �Î��̎ގ�̾(�����׎���)				 */
#define	MRMSGI7	"SRI7"	/* �ܥ�塼�ॳ�ԡ��ץ�����ư��		TD99 */
#define	MRMSGI8	"SRI8"	/* �ѥ�᥿��������						TD99 */
#define	MRMSGI9	"SRI9"	/* ����Хå����åףɣİ۾�		 			 */
						/* ID = bbbbbbbb							 */
						/*	 bbbbbbbb : �ʎގ��������̎�ID(�����׎���)			 */
#define	MRMSGIA	"SRIA"	/* �Хå����å���						TD99 */
#define	MRMSGIB	"SRIB"	/* �֣ңã���������						TD99 */
#define	MRMSGIC	"SRIC"	/* ��ԥꥫ�Х���						TD99 */
#define	MRMSGID	"SRID"	/* ����ʪ���ܥ�塼��̾�۾�  PN = pppppppp	 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
#define	MRMSGIE	"SRIE"	/* ʪ���ܥ�塼���ĺɲ�����ԡʼ��ϡ�	TD99 */
						/*	PN = pppppppp  CD = xxxxxxxx			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*   xxxxxxxx : osconfig�ֵ���				 */
#define	MRMSGIF	"SRIF"	/* ���������ܥ�塼��̾����  LN = vvvvvvvv   */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ0	"SRJ0"	/* �Хå����å����������ܥ�塼�����	TD99 */
						/*	LN = vvvvvvvv							 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ1	"SRJ1"	/* ���������ܥ�塼��ξ���  LN = vvvvvvvv   */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ2	"SRJ2"	/* ���������ܥ�塼�������  LN = vvvvvvvv	 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ3	"SRJ3"	/* �����Ύގ؎����Ѳ�����λ(�ʎގ��������̎��׎Ύގ؎�����)	TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp  			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : �ʎގ��������̎�ID(�����׎���)			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ4	"SRJ4"	/* ����ե����뤬¸�ߤ��ޤ�					 */  
						/*	FN = ffffffff				 			 */
						/*	 ffffffff = ����̎�����̾					 */
#define	MRMSGJ5	"SRJ5"	/* �����Ύގ؎����Ѳ�����λ(�ʎގ��������̎����׎Ύގ؎�����)TD99*/
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ6	"SRJ6"	/* �����Ύގ؎����Ѳ�����λ(�؎��ʎގ؎̎����َΎގ؎�����)	TD99 */
						/*  PN = pppppppp  LN = vvvvvvvv 			 */
						/*  FN = ffffffff,ffffffff,����������������			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
						/*	 ffffffff : ���Ǝ̎�����̾					 */
#define	MRMSGJ7	"SRJ7"	/* �����Ύގ؎����Ѳ�����λ(�܎����̎����َΎގ؎�����)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ8	"SRJ8"	/* �����Ύގ؎����Ѳ�����λ(�Ў׎��Ύގ؎���������)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJ9	"SRJ9"	/* �����Ύގ؎����Ѳ�������(������I/O���׎�)		TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  FN = ffffffff  SC = ssssssss     		 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
						/*	 ffffffff : �оݎ̎�����̾					 */
						/*	 ssssssss : �����ƥॳ�������			 */
						/*	 xxxxxxxx : �����ƥॳ�����ֵ���		 */
#define	MRMSGJA	"SRJA"	/* �����Ύގ؎����Ѳ�������(������I/O���׎�)		TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : �ʎގ��������̎�ID(�����׎���)			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJB	"SRJB"	/* �ꥫ�Х�ե����������ץ�����ư����	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  FN = ffffffff  				     		 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
						/*   ffffffff : ���Ǝ̎�����̾					 */
#define	MRMSGJC	"SRJC"	/* �����Ύގ؎����Ѳ�������(�Ў׎��Ύގ؎���������)	TD99 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
						/*   xxxxxxxx : osioctl�ֵ���				 */
#define	MRMSGJD	"SRJD"	/* �ۥåȥ�����Х�����ͽ���ϥ�����		TD99 */
#define	MRMSGJE	"SRJE"	/* �ץ�����λ�׵����					TD99 */
#define	MRMSGJF	"SRJF"	/* ʪ���ܥ�塼���ĺɲ�����ԡ�¾�ϡ�	TD99 */
						/*	PN = pppppppp							 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
#define	MRMSGJG	"SRJG"	/* �����Ύގ؎����Ѳ�������(�ʎގ��������̎ߎÎގ���̵)	TD99 */
						/*	ID = bbbbbbbb  PN = pppppppp			 */
						/*  LN = vvvvvvvv							 */
						/*	 bbbbbbbb : �ʎގ��������̎�ID(�����׎���)			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJH	"SRJH"	/* �ꥫ�Х�ե�����������				TD99 */
#define	MRMSGJI	"SRJI"	/* �ꥫ�Х�ե����������ץ�����ư��	TD99 */
#define	MRMSGJJ	"SRJJ"	/* �����Ύގ؎����Ѳ�������(mrc������I/O���׎�)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJK	"SRJK"	/* �����Ύގ؎����Ѳ�������(mri������I/O���׎�)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
#define	MRMSGJL	"SRJL"	/* �����Ύގ؎����Ѳ�������(vdi������I/O���׎�)ST2893 */
						/*	PN = pppppppp  LN = vvvvvvvv  			 */
						/*  RC = xxxxxxxx							 */
						/*	 pppppppp : ʪ���Ύގ؎����Ѽ���̾			 */
						/*	 vvvvvvvv : �����Ύގ؎����Ѽ���̾			 */
						/*   xxxxxxxx : �����Îю������ֵ���				 */

/*********************************************************************/
/*	    15.;��(�ӣңˣ����ӣңˣڡ�								 */
/*********************************************************************/

/*********************************************************************/
/*	    16.�ʎގ��������̎ߎ̎ߎێ���(JNL2�̹���)							     */
/*********************************************************************/
#define	MRMSGL0	"SRL0"	/* ���ѷϡ����̎̎����َʎގ��������̎߳��� ID = xxxxxxxx*/
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
#define	MRMSGL1	"SRL1"	/* ���ѷϡ����̎̎����َʎގ��������̎����ｪλ			 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : ��λ�����Ď�(DEC)			     */
#define	MRMSGL2	"SRL2"	/* ���ѷϡ����̎̎����َʎގ��������̎߰۾ｪλ			 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGL3	"SRL3"	/* ���ѷϡ�����ȹ�̎����������س���			 */
#define	MRMSGL4	"SRL4"	/* ���ѷϡ�����ȹ�̎��������������ｪλ		 */
						/*  CD = eeee							 	 */
						/*   eeee : ��λ�����Ď�(DEC)					 */
#define	MRMSGL5	"SRL5"	/* ���ѷϡ�����ȹ�̎����������ذ۾ｪλ		 */
						/*  CD = eeee  DT = pppppppp  DT1 = qqqqqqqq */
						/*  DT2 = rrrrrrrr						     */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGL6	"SRL6"	/* ���ѷϡ�����ȹ�̎����َʎގ��������̎߳���			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
#define	MRMSGL7	"SRL7"	/* ���ѷϡ�����ȹ�̎����َʎގ��������̎����ｪλ		 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : ��λ�����Ď�(DEC)			     */
#define	MRMSGL8	"SRL8"	/* ���ѷϡ�����ȹ�̎����َʎގ��������̎߰۾ｪλ		 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGL9	"SRL9"	/* ͽ���ϡ����̎̎����َʎގ��������̎߳��� 			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
#define	MRMSGLA	"SRLA"	/* ͽ���ϡ����̎̎����َʎގ��������̎����ｪλ			 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : ��λ�����Ď�(DEC)			     */
#define	MRMSGLB	"SRLB"	/* ͽ���ϡ����̎̎����َʎގ��������̎߰۾ｪλ			 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGLC	"SRLC"	/* ͽ���ϡ�����ȹ�̎����������س���			 */
#define	MRMSGLD	"SRLD"	/* ͽ���ϡ�����ȹ�̎��������������ｪλ		 */
						/*  CD = eeee							 	 */
						/*   eeee : ��λ�����Ď�(DEC)					 */
#define	MRMSGLE	"SRLE"	/* ͽ���ϡ�����ȹ�̎����������ذ۾ｪλ		 */
						/*  CD = eeee  DT = pppppppp DT1 = qqqqqqqq  */
						/*  DT2 = rrrrrrrr						 	 */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGLF	"SRLF"	/* ͽ���ϡ�����ȹ�̎����َʎގ��������̎߳���			 */
						/*  ID = xxxxxxxx							 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */

#define	MRMSGM0	"SRM0"	/* ͽ���ϡ�����ȹ�̎����َʎގ��������̎����ｪλ		 */
						/*  ID = xxxxxxxx  CD = eeee				 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : ��λ�����Ď�(DEC)			     */
#define	MRMSGM1	"SRM1"	/* ͽ���ϡ�����ȹ�̎����َʎގ��������̎߰۾ｪλ		 */
						/*  ID = xxxxxxxx  CD = eeee  DT = pppppppp  */
						/*  DT1	= qqqqqqqq  DT2 = rrrrrrrr			 */
						/*   xxxxxxxx : �ʎގ��������̎�ID(�����׎���)			 */
						/*   eeee     : �ξ㎺���Ď�(HEX)				 */
						/*   pppppppp : �ܺپ���(HEX)				 */
						/*   qqqqqqqq : �ܺپ���1(HEX)				 */
						/*   rrrrrrrr : �ܺپ���2(HEX)				 */
#define	MRMSGM2	"SRM2"	/* �����Ύގ؎����юʎގ��������̎߳���  ID = xxxxxxxx	 */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGM3	"SRM3"	/* �����Ύގ؎����юʎގ��������̎����ｪλ  ID = xxxxxxxx */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGM4	"SRM4"	/* �����Ύގ؎����юʎގ��������̎߰۾ｪλ  ID = xxxxxxxx */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGM5	"SRM5"	/* �Ե���JNL�����������׎�							 */
#define	MRMSGM6	"SRM6"	/* �Ե���KJ�����������׎�							 */
#define	MRMSGM7	"SRM7"	/* �Ե���KJ�ξ���ΰ�KJ�ʎގ��������̎��Բ�			 */
						/*  ID = XXXXXXXX					 		 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			 		 */
#define	MRMSGM8	"SRM8"	/* ����ȹ�̎����َʎގ��������̎߳���	 ID = xxxxxxxxx  */ 
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGM9	"SRM9"	/* ����ȹ�̎����َʎގ��������̎����ｪλ				 */ 
						/*  ID = xxxxxxxx  P = pppppppp  L = llllllll*/
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGMA	"SRMA"	/* ����ȹ�̎����َʎގ��������̎߰۾ｪλ				 */ 
						/*  ID = xxxxxxxx  P = pppppppp  L = llllllll*/
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGMB	"SRMB"	/* �ʎގ��������̎ߎΎގ؎�����I/O���׎�ȯ��	 ID = xxxxxxxx   */
						/*  P = pppppppp			 				 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			 		 */
						/*   pppppppp : ʪ���Ύގ؎����Ѽ���̾ 	 		 */
#define	MRMSGMC	"SRMC"	/* �ʎގ��������̎ߎΎގ؎�����΢��I/O���׎�ȯ�� 			 */
						/*  ID = xxxxxxxx  P = pppppppp  			 */
						/*  UP = qqqqqqqq							 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			 		 */
						/*   pppppppp : ʪ���Ύގ؎����Ѽ���̾ 	 		 */
						/*   qqqqqqqq : ΢��ʪ���Ύގ؎����Ѽ���̾  		 */
#define	MRMSGMD	"SRMD"	/* �Ύގ؎����юʎގ��������̎ߎ����ݎ��� ID = xxxxxxxx		 */
						/*  P = pppppppp  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾ 	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
/* ����ʣ��ԡ�												ST4036	 */
#define	MRMSGMF	"SRMF"	/* ���������Ύގ؎����Ѽ���̾�۾� ID = xxxxxxxx	 */
						/*  L = llllllll							 */
						/*   xxxxxxxx : �ʎގ��������̎�ID			 		 */
						/*   llllllll : �����Ύގ؎����Ѽ���̾     		 */
#define	MRMSGMG	"SRMG"	/* VRCV�̎ߎێ��������ݎ�������				CT1163	 */
#define	MRMSGMH	"SRMH"	/* VRCV�̎ߎێ��������ݎ��ټ���				CT1163	 */
						/*  RC = rrrrrrrr ST = ssss					 */
						/*   rrrrrrrr : mo_excm�ֵ���				 */
						/*   ssss     : �̎ߎێ������Î�����					 */
#define	MRMSGMI	"SRMI"	/* �Ύގ؎����ю��ˎߎ��̎ߎێ��������ݎ�������			CT1163	 */
						/*  PNAME = nnnnnnnn						 */
						/*   nnnnnnnn : �̎ߎێ�������̾					 */
#define	MRMSGMJ	"SRMJ"	/* �Ύގ؎����ю��ˎߎ��̎ߎێ��������ݎ��ټ���			CT1163	 */
						/*   RC = rrrrrrrr ST = ssss PNAME = nnnnnnnn */
						/*   rrrrrrrr : mo_excm�ֵ���				 */
						/*   ssss     : �̎ߎێ������Î�����					 */
						/*   nnnnnnnn : �̎ߎێ�������̾					 */

/* ����ʣ��ԡ�												ST4036	 */
#define	MRMSGN2	"SRN2"	/* �����Ύގ؎����юʎގ��������̎߳���(�Ў׎�) ID = xxxxxxxx */
						/*  P1 = pppppppp  P2 = qqqqqqqq			 */
						/*  L = llllllll  F = nnnnnnnnnnnnnnnn		 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN3	"SRN3"	/* �����Ύގ؎����юʎގ��������̎����ｪλ(�Ў׎�)			 */
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN4	"SRN4"	/* �����Ύގ؎����юʎގ��������̎߰۾ｪλ(�Ў׎�)			 */
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN5	"SRN5"	/* ����ȹ�̎����َʎގ��������̎߳���(�Ў׎�)			 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN6	"SRN6"	/* ����ȹ�̎����َʎގ��������̎����ｪλ(�Ў׎�)		 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN7	"SRN7"	/* ����ȹ�̎����َʎގ��������̎߰۾ｪλ(�Ў׎�)		 */ 
						/*  ID = xxxxxxxx  P1 = pppppppp  			 */
						/*  P2 = qqqqqqqq  L = llllllll				 */
						/*  F = nnnnnnnnnnnnnnnn					 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN8	"SRN8"	/* �Ύގ؎����юʎގ��������̎ߎ����ݎ���(�Ў׎�)  ID = xxxxxxxx   */
						/*  P1 = pppppppp  P2 = qqqqqqqq			 */
						/*  L = llllllll  F = nnnnnnnnnnnnnnnn		 */
						/*   xxxxxxxx         : �ʎގ��������̎�ID			 */
						/*   pppppppp         : ʪ���Ύގ؎����Ѽ���̾1	 */
						/*   qqqqqqqq         : ʪ���Ύގ؎����Ѽ���̾2	 */
						/*   llllllll         : �����Ύގ؎����Ѽ���̾     */
						/*   nnnnnnnnnnnnnnnn : �̎�����̵�����׎����ü�̎�����̾*/
#define	MRMSGN9	"SRN9"	/* �ξ�JNL/KJ�̎�����ͭ�������Բ�		  CT1086 */
#define	MRMSGNA	"SRNA"	/* �Хå����åץܥ�塼��ξ�ȯ��	  CT1086 */
						/*  ID = xxxxxxxx  VBTE = vvvv  SC = nnnnnnnn*/
						/*  RC = eeee								 */
						/*   xxxxxxxx : �ʎގ��������̎�ID					 */
						/*   vvvv     : �ξ�VBT���ݎĎ��ֹ�				 */
						/*   nnnnnnnn : �����ƥॳ����̾			 */
						/*   eeee     : �����ƥॳ�����ֵ���		 */
#define	MRMSGNB	"SRNB"	/* ���㡼�ʥ�ե����룲�Ÿξ�ȯ��	  CT1086 */
						/*  SC = nnnnnnnn  RC = eeee				 */
						/*   nnnnnnnn : �����ƥॳ����̾			 */
						/*   eeee     : �����ƥॳ�����ֵ���		 */
/*********************************************************************/
/*	    17.�ߥ顼�������Ʊ���ݾ�				CT0881			     */
/*********************************************************************/
#define	MRMSGO1	"SRO1"	/* �ӣУ�����ե�����I/O���顼(mmmm)		 */
						/* SID = rrrrrrrr  RCD = rrrrrrrr			 */
						/*   mmmm     : �⥸�塼��ID		CT1118	 */
						/*   ssssssss : �����Îю�����̾					 */
						/*   rrrrrrrr : �����Îю������ֵ���				 */
#define	MRMSGO2	"SRO2"	/* �ߥ顼�ܥ�塼�������ǽ  VOL = vvvvvvvv  */
						/*   vvvvvvvv : �����ܥ�塼�༱��̾		 */
#define	MRMSGO3	"SRO3"	/* �ߥ顼�ܥ�塼�������Բ�ǽ  VOL = vvvvvvvv*/
						/* ERRTYPE = ee  ERRCODE = rrrrrrrr			 */
						/*   vvvvvvvv : �����ܥ�塼�༱��̾		 */
						/*   ee		  : ���顼����					 */
						/*   rrrrrrrr : ���顼������				 */
#define	MRMSGO4	"SRO4"	/* �ߥ顼�ü�ե�����I/O���顼(mmmm)		 */
						/* VOL=vvvvvvvv  FNAME = ffffffffffffffff    */
						/* OSTYPE=oooooooo  OSRET = rrrrrrrr		 */
						/*   mmmm             : �ӎ��ގ�-��ID	CT1118	 */
						/*   rrrrrrrr         : �����ܥ�塼�༱��̾ */
						/*   ffffffffffffffff : �̎�����̵�������׎����ü�̎�����*/
						/*   oo               : �����ƥॳ�������	 */
						/*   rrrrrrrr         : �����ƥॳ�����ֵ��� */
#define	MRMSGO5	"SRO5"	/* �ߥ顼������楨�顼(mmmm)		CT1118	 */
						/*  VOL = vvvvvvvv  FNAME = ffffffffffffffff */
						/*  REQ = ssssssss  OSRET = rrrrrrrr		 */
						/*   mmmm             : �ӎ��ގ�-��ID	CT1118	 */
						/*   vvvvvvvv         : �����ܥ�塼�༱��̾ */
						/*   ffffffffffffffff : �̎�����̵�������׎����ü�̎�����*/
						/*   ssssssss         : �׵ἱ�̻�	CT1118   */
						/*   rrrrrrrr         : �����ƥॳ�����ֵ��� */
#define	MRMSGO6	"SRO6"	/* �ߥ顼�������̷��(mmmm)		CT1118	 */
						/*  VOL = vvvvvvvv  FNAME = ffffffffffffffff */
					    /*  MS = llllllll  							 */
						/*   mmmm             : �ӎ��ގ�-��ID	CT1118	 */
						/*   vvvvvvvv         : �����ܥ�塼�༱��̾ */
						/*   ffffffffffffffff : �̎�����̵�������׎����ü�̎�����*/
						/*   llllllll         : �Ў�-������� CT1118	 */
#define	MRMSGO7	"SRO7"	/* ������Ф��ԣУãԤ�¸�ߤ��ʤ�			 */
						/* APNAME = aaaaaaaa						 */
						/*   aaaaaaaa : ������Хץ�������̾		 */
#define	MRMSGO8	"SRO8"	/* ��ʸ��������  VOL = vvvvvvvv				 */
						/* FNAME = ffffffffffffffff  OSTYPE = oo     */
						/* OSRET = rrrrrrrr							 */
						/*   vvvvvvvv         : �����ܥ�塼�༱��̾ */
						/*   ffffffffffffffff : �̎�����̵�������׎����ü�̎�����*/
						/*   oo               : �����ƥॳ�������	 */
						/*   rrrrrrrr         : �����ƥॳ�����ֵ��� */
						/*					ST3026					 */
#define	MRMSGO9 "SRO9"	/* �ӣУ�����ե����륵�������顼			 */
						/* SIZE = ssssssss MUSTSIZE = mmmmmmmm		 */ 
						/*	 ssssssss		  : ��������			 */
						/*	 mmmmmmmm		  :	�����ɬ�פʥ�����	 */
#define	MRMSGOA "SROA"	/* tttt�ơ��֥륨�顼(mmmm)			CT1118	 */
						/*   tttt : �ơ��֥�̾				CT1118	 */
						/*   mmmm : �⥸�塼��ID			CT1118   */
#define	MRMSGOB "SROB"	/* �����ƥॳ���륨�顼(mmmm)		CT1118	 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm     : �⥸�塼��ID		CT1118	 */
						/*   oooooooo : �����ƥॳ�������	CT1118	 */
						/*   rrrrrrrr : �����ƥॳ�����ֵ���CT1118	 */
#define	MRMSGOC	"SROC"	/* �ߥ顼�ܥ�塼��I/O���顼(mmmm)  CT1118	 */
						/*  VOL = vvvvvvvv  ID = iiiiiiiiiiii		 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm    		  : �⥸�塼��ID		 */
						/*   vvvvvvvv         : �����ܥ�塼�༱��̾ */
						/*   iiiiiiiiiiii	  : ����ID				 */
						/*   oooooooo         : �����ƥॳ�������	 */
						/*   rrrrrrrr         : �����ƥॳ�����ֵ��� */
#define	MRMSGOD	"SROD"	/* �ʣΣ̥ե�����I/O���顼(mmmm)			 */
						/*  FNAME = ffffffff  KEI = s				 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm      : �⥸�塼��ID		 		 */
						/*   ffffffff  : �ʣΣ̥ե�����̾			 */
						/*   s		   : ����						 */
						/*               'M'-ξ�� 'S'-���� 'F'-����	 */
						/*   oooooooo  : �����ƥॳ�������	 		 */
						/*   rrrrrrrr  : �����ƥॳ�����ֵ��� 		 */
#define	MRMSGOE	"SROE"	/* �ң£ɥե�����I/O���顼(mmmm)			 */
						/*  FNAME = ffffffff  KEI = s				 */
						/*  OSTYPE = oo  OSRET = rrrrrrrr			 */
						/*   mmmm      : �⥸�塼��ID		 		 */
						/*   ffffffff  : �ң£ɥե�����̾			 */
						/*   s		   : ����						 */
						/*               'M'-ξ�� 'S'-���� 'F'-����	 */
						/*   oooooooo  : �����ƥॳ�������	 		 */
						/*   rrrrrrrr  : �����ƥॳ�����ֵ��� 		 */
#define	MRMSGOF	"SROF"	/* �ߥ顼�ܥ�塼��(vvvvvvvv)����(llllllll)	 */
						/*  ��(s) ��(s)							 	 */
						/*   vvvvvvvv  : �����ܥ�塼�༱��̾		 */
						/*   llllllll  : �ߥ顼����������		 */
						/*   s         : �ܥ�塼�ॹ�ơ�����		 */
#define	MRMSGOG "SROG"  /* �ӣͣХ����ƥ�����ե�����ɡ��ϥ��顼	 */
						/* OSTYPE = oooooooo  OSRET = rrrrrrrr		 */
						/*									CT1212   */
						/*   oooooooo  : �����ƥॳ�������	 		 */
						/*   rrrrrrrr  : �����ƥॳ�����ֵ��� 		 */
#define	MRMSGOH "SROH"  /* �Хåե���������  				CT1212	 */
						/*  SCRET = rrrrrrrr		 		CT1212   */
						/*   rrrrrrrr  : �����ӥ��������ֵ���		 */
#define	MRMSGOI	"SROI"	/* �ӣУ�����ե�������������		CT1212	 */
#define	MRMSGOJ	"SROJ"	/* �ӣУ�����ե�������������		CT1212	 */
#define	MRMSGOK	"SROK"	/* �ӣУ�����ե�������������		CT1212	 */
#define	MRMSGOL	"SROL"	/* �ӣУ�����ե����뤬����¸�ߤ���	CT1212	 */

/*********************************************************************/
/*	    18.�ӣãӣɥꥻ�åȥץ���				CT1106			     */
/*********************************************************************/
#define	MRMSGP1 "SRP1"	/* �Х��ꥻ�å�����			ST3688			 */
						/*  FN = sssssss.....						 */
						/* sssssss....	: �ꥻ�å��оݥХ��ե�����̾ */
#define	MRMSGP2 "SRP2"	/* �Х��ꥻ�åȼ���			ST3688			 */
						/*  FN = sssssss..... RC = rrrrrrrr			 */
						/* sssssss....	: �ꥻ�å��оݥХ��ե�����̾ */
						/* rrrrrrrr		: �����ƥॳ�����ֵ���		 */
#define	MRMSGP3 "SRP3"	/* ���֥ꥻ�å�����			ST3688			 */
						/*  FN = sssssss.....						 */
						/* sssssss....	: �ꥻ�å��о����֥ե�����̾ */
#define	MRMSGP4 "SRP4"	/* ���֥ꥻ�åȼ���			ST3688			 */
						/*  FN = sssssss..... RC = rrrrrrrr			 */
						/* sssssss....	: �ꥻ�å��о����֥ե�����̾ */
						/* rrrrrrrr		: �����ƥॳ�����ֵ���		 */
#define	MRMSGP5 "SRP5"	/* �ü�ե�����ɡ��ϥ��顼			ST3820	 */
						/*  FN = ffffffffffffffff....  OSTYPE = oo   */
						/*  RC = rrrrrrrr						     */
						/*   ffffffffffffffff : �ü�ե�����̾	 	 */
						/*   oo               : �����ƥॳ�������	 */
						/*   rrrrrrrr         : �����ƥॳ�����ֵ��� */

/*********************************************************************/
/*      19.�ξ�����󶡴ؿ�								SSCY0152	 */
/*********************************************************************/
#define	MRMSGQ1	"SRQ1"	/* ACC�ξ�  DEVNO = dddddddd  	SSCY0152	 */
						/*  ELEMENT = eeeeeeee  DETAIL = ssssssss	 */ 
						/*   dddddddd : ����ID			SSCY0152	 */
						/*   eeeeeeee : ���ڎҎݎ�NO			SSCY0152	 */
						/*   ssssssss : �ξ�ܺ�		SSCY0152	 */

/*********************************************************************/

/*********************************************************************/
/*      20.RCV��å���������	SUPPLY 2003-04-08					 */
/*********************************************************************/
#define	MRMSRR1	"SRR1"	/* �����ƥॳ���륨�顼��ȯ������			 */
						/* ���Ѥ����󥢥��������顼 %s errno=%s		 */
						/* USEFILE ACCESS ERROR %s errno=%s			 */
#define MRMSRR2 "SRR2"	/* �����ƥॳ���륨�顼��ȯ��������			 */
						/* STATUSFILE ACCESS ERROR %s errno=%s		 */
						/* ���Ѥ����֥����������顼 %s errno=%s		 */
#define MRMSRR3	"SRR3"	/* �ʰ��Ѥ����֥ե����뤫���ɤ߹������		 */
						/* ���Ѥ�����ե�����κ������ա��������֡�  */
						/* �ξ���֤�ɽ��							 */
						/* TRCV JNLFILE STATAUS�� %s USEFILE�� 		 */
						/* yymmdd hhmmss							 */
						/* ���Ѥ�����ե����륹�ơ������� %s 		 */
						/* ���ѥե����롧 yymmdd hhmmss				 */
#define MRMSRR4 "SRR4"	/* ���Ѥ�����ե�����ν��������			 */
						/* TRCV JNLFILE INITIALIZATION START��%s��	 */
						/* ���Ѥ�����ե������������ϡ�%s��		 */
#define MRMSRR5 "SRR5"	/* ���Ѥ�����ե�����ν������λ��			 */
						/* TRCV JNLFILE CREATE�� yymmdd hhmmss		 */
						/* ���Ѥ�����ե�����������λ ������		 */
						/* yymmdd hhmmss							 */
#define MRMSRR6 "SRR6"	/* ���Ѥ����֥ե�����ν��������			 */
						/* TRCV STATUSFILE INITIALIZATION START��%s��*/
						/* ���Ѥ����֥ե������������ϡ�%s��		 */
#define MRMSRR7 "SRR7"	/* ���Ѥ����֥ե�����ν������λ��			 */
						/* TRCV STATUSFILE CREATE�� yymmdd hhmmss	 */
						/* STATUS�� %s								 */
						/* ���Ѥ����֥ե���������λ ������ 		 */
						/* yymmdd hhmmss							 */
#define MRMSRR8 "SRR8"  /* �ơ��֥�ꥫ�Х�����γ���				 */
						/* TABLE RECOVERY START						 */
						/* �ơ��֥�ꥫ�Х����ʥե�����ξ����	 */
#define MRMSRR9 "SRR9"	/* �ơ��֥�ꥫ�Х�����ν�λ��				 */
						/* TABLE RECOVERY END USEFILE�� %s1%s2 		 */
						/* RECORDS�� %s3							 */
						/* �ơ��֥�ꥫ�Х꽪λ ���ѥե����롧 		 */
						/* %s1 %s2 �쥳���ɿ��� %s3					 */
#define MRMSRRA	"SRRA"	/* �ơ��֥�ꥫ�Х�����β���				 */
						/* TABLE RECOVERY AVOID��FILE FAILURE��		 */
						/* �ơ��֥�ꥫ�Х����ʥե�����ξ����	 */
#define MRMSRRB	"SRRB"	/* ���ѼԽ�λ����ˤ�륷���ƥ����ｪλ		 */
						/* �����γ��ϡ�								 */
						/* SYSTEM STOP START��USER END MIDDLE��		 */
						/* �����ƥ����ｪλ�������ϡ����ѼԽ�λ�����*/
#define MRMSRRC	"SRRC"	/* �ؿ�ȯ�Լ��� �ܺپ��� 					 */
						/* SYSTEM STOP START��USER END MIDDLE��		 */
						/* command failed. Error code = 			 */
/*********************************************************************/



