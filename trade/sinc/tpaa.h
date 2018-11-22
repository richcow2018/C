/*********************************************************************/
/*                                                                   */
/*             tpaa.h 	                                             */
/*                                                                   */
/* (��) �؎ݎ������������256���Ǥǹ�¤��������Ƥ��뤬                 */
/*     �ºݤΥơ��֥�ϡ������ʤ�Ȥϸ¤�ʤ��Τǡ�                  */
/*     TPAAPSZ���Ф���sizeof����Ŭ�Ѥ��ƤϤ����ʤ���                 */
/*                                          1995,2,8 Sazae           */
/*********************************************************************/

typedef struct  {                       /* �؎ݎ�������������            */
    char    tpaalkst;                   /* 00:̤���� 01:���Ȏ��ĺѤ�      */
    char    tpaayob2;           	    /* ͽ��                       */
    short   tpaalgtn;                   /* TLGT���ݎĎ��ֹ�               */
    short   tpaalphn;                   /* TLPH���ݎĎ��ֹ�               */
    short   tpaalptn;                   /* TLPT���ݎĎ��ֹ�               */
    long    tpaassop[2];                /* Ŭ�ю����Îю��̎ߎ�����             */
    long    tpaayob3;           	    /* ͽ��                       */
} TPAAPS;

typedef struct  {                       /* ������͎�����                 */
    short   tpaalkno;                   /* �؎ݎ������􎺎Ȏ��ĺѤ߿�        */
    short   tpaayob1;           	    /* ͽ��                       */
} TPAAPM;

typedef struct  {						/* ����������                 */
	TPAAPM  tpaapm;						/* ������͎�����                 */
	TPAAPS	tpaaps[256];				/* �؎ݎ�����������              */
} TPAAPSZ;

typedef struct  {                       /* ���̎޶�����                  */
    short   tpaalmax;                   /* �؎ݎ�����������������ǿ�    */
    short   tpaayob0;           	    /* ͽ��                       */
} TPAASUB;
