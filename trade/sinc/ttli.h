/****************************************************************************/
/*                                                                          */
/*      �ԣԣ̣ɥơ��֥�ե����ޥå�  ttli.h                  (93.11.22)    */
/*                                                                          */
/*  ����   :  ST4626��96.12.11�����̎޶�������ͽ����ttlimet���ѹ�              */
/****************************************************************************/

struct  ttlisub {                       /* ���ֶ�����                       */
    char   ttlipsnm[2][22];             /* �ԣãС��ɣ��ü�ե�����̾       */
    unsigned short  ttlinivt;           /* �Σţԣãԣ̥�ȥ饤������       */
    char   ttlimet;                 	/* �������                       */
										/* ST4626 ͽ���������̤��ѹ�	*/
    char   ttliyob0;                    /* ͽ��                             */
};
typedef struct ttlisub MDTLIPS;         /* �ģã���                         */
typedef struct ttlisub TTLIPS;          /* �ƣɣ���                         */

struct  ttlipsz {                       /* ������                           */
    long   			ttliipa0;           /* �ɣХ��ɥ쥹��                   */
    unsigned char   ttlimca0[6];        /* �ͣ��å��ɥ쥹��                 */
    short  			ttlimct0;           /* �ͣ��å����ף�                   */
    long   			ttliipa1;           /* �ɣХ��ɥ쥹��                   */
    unsigned char   ttlimca1[6];        /* �ͣ��å��ɥ쥹��                 */
    short  			ttlimct1;           /* �ͣ��å����ף�                   */
    long   			ttlismsk;           /* ���֥ͥåȥޥ���                 */
    unsigned long	ttlirbfh;           /* �����Хåե������               */
    unsigned long	ttlirbfl;           /* �����Хåե�������               */
    unsigned long	ttlisbfh;           /* �����Хåե������               */
    unsigned long	ttlisbfl;           /* �����Хåե�������               */
    unsigned char	ttliwrmx;           /* Ʊ�������׵�����               */
    unsigned char	ttliremx;           /* Ʊ�������׵�����               */
    unsigned short	ttliivtd;           /* �ģţԣ��ã�ȯ�ԥ�ȥ饤������   */
    char   			ttliecdt[8];        /* ��������ǡ���                 */
    unsigned char	ttliecdc;           /* ��������ǡ��������֤����     */
    char   			ttliyob0[3];        /* ͽ����                           */
};
typedef struct  ttlipsz MDTLIKO;        /* �ģã���                         */
typedef struct  ttlipsz TTLIPSZ;        /* �ƣɣ���                         */
