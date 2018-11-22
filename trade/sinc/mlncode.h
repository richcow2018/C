/*****************************NTC-SMP-TOOL****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		���Ύ�-��/���ގ��� ��-�Ď� �Î����� �̎����� (mlncode.h)						 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		NDTP														 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		�������� ���� : �Ԏώӎ� �Վ�����							 				 */
/*		�������� ���� : �Ԏώӎ� �Վ�����							 				 */
/*		�͎ݎ��� ���� : 													 */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	�������؎��� ��-�Ď� �� �Î�����												 */
/*********************************************************************/

#define	MLENMAN		0x3000
#define	MLENBFE		0x3001
#define	MLENCMD		0x3002
#define	MLENEMC		0x3003
#define	MLENERR		0x3004
#define	MLENFBF		0x3005
#define	MLENFPM		0x3006
#define	MLENFRD		0x3007
#define	MLENGGC		0x3008
#define	MLENKCK		0x3009
#define	MLENKMT		0x300A
#define	MLENMDD		0x300B
#define	MLENMSG		0x300C
#define	MLENMSK		0x300D
#define	MLENTMU		0x300E
#define	MLENVCH		0x300F
#define	MLENWRT		0x3010
#define	MLENWTO		0x3011
#define	MLENWTR		0x3012
#define	MLENFDM		0x3020
#define	MLENDSC		0x3021
#define	MLENFDP		0x3022
#define	MLENKWR		0x3023
#define	MLENDMP		0x3024
#define	MLENRAD		0x3030
#define	MLENRUD		0x3040
#define	MLENPSC		0x3041
#define	MLENFDT		0x3042
#define	MLENBTU		0x3043
#define	MLENFDR		0x3044
#define	MLENUDW		0x3045
#define	MLENTDM		0x3050
#define	MLENTDP		0x3051
#define	MLENTPM		0x3060
#define	MLENENQ		0x3063
#define	MLENDEQ		0x3064
#define	MLENSTU		0x3066

/*********************************************************************/
/*	���������� ��-�Ď� �� �Î�����												 */
/*********************************************************************/

/*********************************/
/*	�ێݎ� ����- (0x01-0x3F)			 */
/*********************************/

#define	MLDPGMERR 	0x01000000	/* �̎ߎێ��ގ׎� �ێݎ� ���׎�  				 */
#define	MLDDATERR 	0x02000000	/* �̎ߎێ��ގ׎� �Ŏ� �Î�-�� �ێݎ� ���׎� 			 */
#define	MLDTBLERR	0x10000000	/* ��-�̎ގ� ����-						 */
#define	MLDFBUFERR	0x11000000	/* �̎�-�� �ʎގ��̎� �����Ύ� ����-				 */
#define	MLDOSDATERR	0x12000000	/* �ώ��� �ˎ��ގ� ���ގ��� �����Ď� ����-			 */
#define	MLDPARMERR	0x30000000	/* NDTP �Ŏ� �ʎߎ׎Ҏ� ����-				 */
#define	MLDPARMXERR	0x31000000	/* NDTP �Ŏ� �ʎߎ׎Ҏ� �Ŏ��֎� ����-			 */

/*********************************/
/*	�ʎߎ׎Ҏ� ����- (0x40-0x7F)		 */
/*********************************/

#define MLDCCDVERR	0x40000000	/* ���ώݎĎ� �������� ���� �� ����-				 */
#define MLDCPRTERR	0x41000000	/* �̎ߎێݎ̎ߎ� �Ҏ���-���� �����؎��� ����-		 */
#define MLDCPFMERR	0x42000000	/* ����- �Ҏ���-���� �͎ݎ����� ����-				 */
#define MLDCKYCERR	0x43000000	/* ��- �ʎߎ׎Ҏ� �������� ����-				 */
#define MLDCDWTERR	0x44000000	/* ���ގݎ̎� �Î�-�� �����؎��� ����-			 */
#define MLDCWTRERR	0x44000000	/* ���ގݎ̎� �Î�-�� �����؎��� ����-			 */

#define MLDHCCNERR	0x45000000	/* �Î�-�� �͎ݎ��� ����-					 */
#define MLDBCCNERR	0x46000000	/* �Î�-�� �͎ݎ��� ����-					 */

#define MLDRFGTERR	0x50000000	/* �̎����� �� �����ގ� �ʎގݎ��ގ� �����Ď� ����-		 */
#define MLDFCONERR	0x51000000	/* �̎����� �ڎݎ��� ����-					 */
#define MLDFDCNERR	0x52000000	/* �̎����� �ڎݎ��� �������ގ� ����-				 */
#define MLDFOPNERR	0x53000000	/* �̎����� ��-�̎ߎ� ����-					 */
#define MLDFCLSERR	0x54000000	/* �̎����� ����-���� ����-					 */
#define MLDFREDERR	0x55000000	/* �̎����� �֎Ў��� ����-					 */
#define MLDFWRTERR	0x56000000	/* �̎����� �������� ����-					 */
#define MLDFWTXERR	0x57000000	/* �̎����� �֎Ў��� ����-					 */
#define MLDFUPDERR	0x58000000	/* �̎����� �������� ����-					 */
#define MLDFSRHERR	0x59000000	/* �̎����� ��-�� ����-						 */
#define MLDFGETERR	0x5A000000	/* �����ʎߎ� �̎����� ���ގ����Ύ� �����Ď� ����-		 */
#define MLDWOPNERR	0x5B000000	/* ��-�� �̎����� ��-�̎ߎ� ����-				 */
#define MLDWGETERR	0x5C000000	/* ��-�� �̎����� ���ގ����Ύ� �����Ď� ����-			 */

#define MLDRTGTERR	0x60000000	/* ��-�̎ގ� �� �����ގ� �ʎގݎ��ގ� �����Ď� ����-		 */
#define MLDTOPNERR	0x61000000	/* ��-�̎ގ� ��-�̎ߎ� ����-					 */
#define MLDTCLSERR	0x62000000	/* ��-�̎ގ� ����-���� ����-					 */
#define MLDTREDERR	0x63000000	/* ��-�̎ގ� �֎Ў��� ����-					 */
#define MLDTSRHERR	0x64000000	/* ��-�̎ގ� ��-�� ����-					 */

#define MLDUWTOERR	0x70000000	/* ��-�̎ގ� ��-�� ����-					 */

/*********************************/
/*	������ �Ďގ��� ����- (0x80-0x9F)	 */
/*********************************/

#define	MLDENQERR	0x80000000	/* �����ގ� ���ݎՎ� ����-					 */
#define	MLDDEQERR	0x81000000	/* �����ގ� ���ݎՎ� �������ގ� ����-				 */
#define	MLDTIMEOUT	0x90000000	/* �����Ď� ������ ������ ����-					 */

/*********************************/
/*	��-�Ď� ����- (0xA0-0xCF)		 */
/*********************************/

#define	MLDWRTERR	0xA0000000	/* �̎����� �������� ����-					 */

/*********************************/
/*	�����ގ� �̎ގ��� ����- (0xD0-0xDF)	 */
/*********************************/

#define	MLDGBUFERR	0xD0000000	/* �̎�-�� �ʎގ��̎� ������ ����-				 */
#define	MLDFEOFERR	0xD1000000	/* �̎����� �֎��؎��� ���� ���؎Ŏ�				 */

/*********************************/
/*	���Ɏ� �� ����- (0xE0-0xFF)		 */
/*********************************/

