/*********************************************/
/*                                           */
/*               mdat.h                      */
/*                                           */
/*          ���Î��� ���ݎ؎��� �̎����ώ���                */
/*                                           */
/*********************************************/

struct mdatkyo {
	short	mdatmxen;           /* �������ގ� ���ݎĎ؎���           */
	short	mdateden;           /* �͎ݎ����� ���ݎĎ؎���           */
};
typedef struct mdatkyo MDATKYO;

struct mdatko {
	char	mdatedst;           /* �͎ݎ����� ���Î�����            */
	char	mdatakbn;           /* ���Î��� ���̎ގ�              */
	char	mdatfndt;           /* ���������� �Îގ��� �����͎ގ�       */
	char	mdatkkst;           /* �������� ���Î�����             */
	short	mdatwsno;           /* �܎������Î������� NO.          */
	short 	mdatanod;           /* ���Î��� �Ɏ��Ď�              */
	char 	mdatfwcd[2];        /* �̎؎܎� �����Ď�              */
	char 	mdatyob1[2];        /* �֎ˎ�1                   */
	char 	mdatpsid[8];        /* �̎ߎێ��� �����͎ގҎ�          */
	long	mdatmsad;           /* �Ҏ��������� ���ݎ؎��� ���Ďގڎ�     */
};
typedef struct mdatko MDATKO;
