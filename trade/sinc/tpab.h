/*********************************************************************/
/*                                                                   */
/*             tpab.h 	    95.02.15 Tuboyaki                        */
/*                                                                   */
/*********************************************************************/

typedef struct  {                       /* �؎ݎ�������������            */
    char    tpablkst;                   /* 00:̤���� 01:���Ȏ��ĺѤ�      */
    char    tpabyob2;           	    /* ͽ��                       */
    short   tpablgtn;                   /* TLGT���ݎĎ��ֹ�               */
    short   tpablphn;                   /* TLPH���ݎĎ��ֹ�               */
    short   tpablptn;                   /* TLPT���ݎĎ��ֹ�               */
    long    tpabssop[2];                /* Ŭ�ю����Îю��̎ߎ�����             */
    long    tpabyob3;           	    /* ͽ��                       */
} TPABPS;

typedef struct  {                       /* ������͎�����                 */
    short   tpablkno;                   /* �؎ݎ������􎺎Ȏ��ĺѤ߿�        */
    short   tpabyob1;           	    /* ͽ��                       */
} TPABPM;

typedef struct  {                       /* ���̎޶�����                  */
    short   tpablmax;                   /* �؎ݎ�����������������ǿ�    */
    short   tpabyob0;           	    /* ͽ��                       */
} TPABSUB;
