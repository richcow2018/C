/*****************************NTC-SMP-RCV*****************************/
/*                                                                   */
/*   1 �̎����َҎ�                                                        */
/*      RBI �Î����� �̎����� (mrrbi.h)                                      */
/*                                                                   */
/*   2 ���̎ގ�                                                          */
/*      RBI �����Ď� ������                                                 */
/*                                                                   */
/*   3 �؎ڎ�                                                           */
/*      �������� ���� : �������� ���ݎ���                        			         */
/*      �������� ���� : �������� ���ݎ���                         			     */
/*      �͎ݎ��� ���� : ��ƣ����          93/11/12                         */
/*				  (2�Ų��̎����٤κ����ȼ���ѹ�)         TD-27          */
/*                (LM�Î��̎ގ٤�RBI������ȼ���ѹ�)        TD-40          */
/*                (��������ˤ���ѹ�)                TD-@1          */
/*                                                                   */
/*********************************************************************/

/*********************************************************************/
/*    MRRCB (�������� ���ގ����Ύ� �����Î� �؎�������)                                */
/*********************************************************************/
struct mrrcb{
	 long    mrrbmin;          /* �����Ď� ���ݎ��� ���ގ���                     */
	 long    mrrbmsg;          /* �Ҏ��������� ���ގ����� �֎������� �����͎ގ�          */
	 long    mrrbtim;          /* ������ ���ގ����� �֎������� �����͎ގ�             */
	 long    mrrbrfd;          /* RBI�̎����ٵ��һ�                 TD@1 */
	 char	 mrrbtyp;          /* ��ư��ʬ                      TD40 */
	 char    mrrbsid;          /* �����Îю�-��ID                          */
	 char	 mrrbyob[2];       /* ͽ��                          TD@1 */
	 long	 mrrbrcd;		   /* �����Îю����� �� �͎ݎ�������					 */
	 TRBTPSZ *mrrbrbt;         /* TRBT�����􎱎Ďގڎ�				TD40 */
};
typedef struct mrrcb MRRCB;

/*********************************************************************/
/*    MRRBIDX  (RBI ���ݎÎގ����� �ʎގ��̎�)                                   */
/*********************************************************************/
struct mrrbidx {
	 long    mrrxuse;          /* �Վ����� �ˎ�������                         */
	 long    mrrxcnt;          /* �����Ď� �����ݎ�                          */
	 long    mrrxday;          /* SMP���վ��2�ʎގ���              TD@1 */
	 long    mrrxtim;          /* SMP���ղ���2�ʎގ���              TD@1 */
};
typedef struct mrrbidx  MRRBIDX;

/*********************************************************************/
/*    MRRBUSE  (RBI �������ގ����� �Îގݎ̎ގ� �؎֎����� ����)                         */
/*********************************************************************/
struct mrrbuse {
	 MRMUSE	 mrrbma1;
	 long    mrrbma2;          /*                                    */
};
typedef struct mrrbuse  MRRBUSE;
                                             
/*********************************************************************/
/*	  RBI �̎ߎێ��� �Ŏ� �̎׎��� ���� ���� 										 */
/*********************************************************************/
#define		MRRBFON		0x0080			/* �̎׎��� ���� 					 */
#define		MRRBFOF		0x0000			/* �̎׎��� ���� 					 */

/*********************************************************************/
/*	  RBI �̎ߎێ��� �Ŏ� �����̎� ���̎ގ� 										 */
/*********************************************************************/
										/* 2�Ų��̎����٤κ����ȼ����� */
										/* (2��)                TD27 */

/*********************************************************************/
/*	RBI �Վ�����/�ю��� �ˎ�������												 */
/*********************************************************************/
#define		MRRBVOID	0x00000000L		/* RBI �ю��� �ˎ�������			 */
#define		MRRBUSEF	0xFFFFFFFFL		/* RBI �Վ����� �ˎ�������			 */

/*********************************************************************/
/*  RBI�̎ߎێ�����ư��ʬ                                                 */
/*********************************************************************/
#define     MRRBICM     0x00            /* CM�Î��̎ގ���            TD40 */
#define     MRRBIL0     0x01            /* PU0�۲�LM�Î��̎ގ���     TD40 */
#define     MRRBIL1     0x02            /* PU1�۲�LM�Î��̎ގ���     TD40 */
