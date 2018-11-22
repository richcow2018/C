/****************************************************************************/
/* �ե�����̾����mi_log.h                                                   */
/* ��ǽ  ������  �̎ߎێ����ێ��޼�����Ϣ�ώ���                                        */
/* ��������  ��  1993.12.13                                                 */
/* �ѹ�����  ��  1994.10.14                                             PD0A*/
/*   �ξ����ɼ(ST1761) ����ɡ����б�                                      */
/* �ѹ���������  1996.03.05                                             PD0R*/ 
/*   �����ѹ��׵��(SSCY0156) X.25�����ƻ��ѹ��б�                          */ 
/****************************************************************************/
#include <mc.h>                         /* mc.h                             */
#include <mc_logx.h>                    /* P�Ďڎ�����������͎����ގ̎����ٻ������    */
#include <mc_logmac.h>                  /* �����Îю����َώ�������͎����ގ̎����ٻ������   */

#define MILOGA00    0x00ff9000          /* �ؿ�TRACE�ێ���ID(SI_1)             */
#define MILOGV01    0x00ff9001          /* �����Ҏ��������ގێ���                    */
#define MILOGV12    0x00ff9012          /* ��λ�����̎ߎݴ�λ�ێ���               */
#define MILOGV13    0x00ff9013          /* ��λ���ێ����޴�λ�ێ���               */
#define MILOGV20    0x00ff9020          /* �������괰λ�ێ���                  */
#define MILOGV22    0x00ff9022          /* ��ƴ�λ�ێ���                      */
#define MILOGV23    0x00ff9023          /* ȯ�ƴ�λ�ێ���                      */
#define MILOGV24    0x00ff9024          /* ��Ʊ�����δ�λ�ێ���                */
#define MILOGV25    0x00ff9025          /* ���ֻ�Îގ���������λ�ێ���          */
#define MILOGV26    0x00ff9026          /* ���Ǵ�λ�ێ���                  PD0A*/
#define MILOGV27    0x00ff9027          /* �Îގ����؎ݎ������괰λ�ێ���         PD0R*/
#define MILOGVSS    0x00ff90f0          /* ���������Ȏَ��Î������ێ���                 */
#define MILOGVSE    0x00ff90f1          /* �и������Ȏَ��Î������ێ���                 */
#define MILOGVLP    0x00ff90ff          /* �����ʎߎ����Î������������ێ���            */

#define POF_MKCODE           0
#define POF_SENDPROCESS     32
#define POF_RCVPROCESS      40
#define POF_IFCODE          88
#define POF_SYBETU         144

extern   long   mc_logv();              /* �Ďڎ����������                     */
extern   long   mc_loga(long, long, char *);
                                        /* �Ďڎ����������                     */

typedef struct {
    char    pnm[8];                     /* �������᡼��ܥå������̻�       */
    long    mkcd;                       /* ���ޥ�ɥ�����                   */
    long    ifcd;                       /* ���󥿥ե�����������             */
    long    msgsize;                    /* ��å�����Ĺ������               */
    char    sybetu[9];                  /* ���μ���                         */
    char    lineno[3];                  /* �����ֹ桿�����ʎߎ��ֹ�            */
} MMSGTR;                               /* �ͣɣ���ʸ�ȥ졼������           */

#define PLOG_RVNTFY(P1, P2)             /* P�Ďڎ���������OS�������Ʊ�����μ�  */\
                                        /* ������                           */\
    mc_loga(CL_RVNTFY, P1, (char *)P2)

#define PLOG_RVMIAMSG(P1, P2)           /* P�Ďڎ��������ʣͣɣ���ʸ��������    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* �ͣɣ���ʸ�ȥ졼������           */\
    int i;                              /* �롼�ץ�����                   */\
    for( i = 0; i < 8; i++)             /* �������ץ���������̾����Ф�   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_SENDPROCESS + i);            \
                                        /* �������ƥåȥ����ļ��Ф�       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* �ͣ˥����ɤ���Ф�             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* ���󥿥ե����������ɤ���Ф�   */\
    mmsgtr.msgsize = P1;                /* ��å�����Ĺ����Ф�           */\
    if( mmsgtr.ifcd == 0x58001000 )     /* ���ݎ����̎����������Ďޤ��Վ��Î��؎Î���ư�������*/\
    {                                                                         \
        for( i = 0; i < 9; i++)         /* ���μ��̤���Ф�               */\
        {                                                                     \
            mmsgtr.sybetu[i] = *(char *)((long)P2 + POF_SYBETU + i);          \
                                        /* �������ƥåȥ����ļ��Ф�       */\
        }                                                                     \
    }                                                                         \
    mc_loga(                                                                  \
        CL_RVMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
		(char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* �Хȥ졼������                   */\
                                        /*   �ͣɣ���ʸ�����Υ���           */\
                                        /*   �ͣɣ���ʸ�ȥ졼������Υ����� */\
                                        /*   �ͣɣ���ʸ�ȥ졼������γ�Ǽ�� */\
                                        /*   ������ʸĹ                     */\
}
#define PLOG_SDMIAMSG(P1, P2)           /* P�Ďڎ��������ʣͣɣ���ʸ��������    */\
{                                                                             \
    MMSGTR  mmsgtr;                     /* �ͣɣ���ʸ�ȥ졼������           */\
    int i;                              /* �롼�ץ�����                   */\
    for( i = 0; i < 8; i++)             /* ������ץ���������̾����Ф�   */\
    {                                                                         \
        mmsgtr.pnm[i] = *(char *)((long)P2 + POF_RCVPROCESS + i);             \
                                        /* �������ƥåȥ����ļ��Ф�       */\
    }                                                                         \
    mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);                           \
                                        /* �ͣ˥����ɤ���Ф�             */\
    mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);                           \
                                        /* ���󥿥ե����������ɤ���Ф�   */\
    mmsgtr.msgsize = P1;                /* ��å�����Ĺ����Ф�           */\
    mc_loga(                                                                  \
        CL_SDMIAMSG,                                                          \
        sizeof(MMSGTR),                                                       \
        (char *)&mmsgtr                                                       \
    );                                                                        \
                                        /* �Хȥ졼������                   */\
                                        /*   �ͣɣ���ʸ�����Υ���           */\
                                        /*   �ͣɣ���ʸ�ȥ졼������Υ����� */\
                                        /*   �ͣɣ���ʸ�ȥ졼������γ�Ǽ�� */\
                                        /*   ������ʸĹ                     */\
}
/****************************************/
/* IRB��������ώ��ۡ���                   */
/* <��������>                           */
/*  ����IR�����Ď�                          */
/*  �������̎�IR�����Ď�                       */
/*  ��  �Ҏ��������ގ��Ďގڎ�                     */
/*  ��  �Ҏ���������Ĺ��                      */
/****************************************/
#define LOG_IRB(p1)                                                           \
{                                                                             \
    mc_logv(MILOGV01, 5L,                                                     \
            (long)((MIIRB *)p1)->ir_cd,                                       \
            (long)((MIIRB *)p1)->sir_cd,                                      \
            (long)(((MIIRB *)p1)->msgp),                                      \
            (long)((MIIRB *)p1)->msglen,                                      \
            (long)((MILCTX *)((MIIRB *)p1)->ctxtp)->lineno);                  \
                                        /* �ێ��޼����ؿ��¹�              PD0A*/\
}
/****************************************/
/* �����ʎߎ����Î�����������������ώ���          */
/* <��������>                           */
/*      �����������ʎߎ����Î�����              */
/*      �����������ʎߎ����Î�����              */
/*      �ӎ��ގ�����ID                        */
/****************************************/
#define LOG_LPT(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* �ێ��޼����ؿ��¹�                  */\
}
/****************************************/
/* �����Îю������ֵ��;�������ώ���             */
/* <��������>                           */
/*      ��λ�����Îю������ֵ���             */
/*      �ӎ��ގ�����ID                        */
/****************************************/
#define LOG_RTN(p1, p2, p3)                                                   \
{                                                                             \
    mc_logv(p1, 2L,(long)p2, (long)(0x67ff0000 | ((long)p3)));                \
								        /* �ێ��޼����ؿ��¹�                  */\
}
/****************************************/
/* ���Î�������������ώ���                     */
/* <��������>                           */
/*      ���������Ȏَ��Î�����                   */
/*      ʪ�������Ȏَ��Î�����                   */
/*      �ӎ��ގ�����ID                        */
/****************************************/
#define LOG_STS(p1, p2, p3, p4)                                               \
{                                                                             \
    mc_logv(p1, 3L,(long)p2, (long)p3, (long)(0x67ff0000 | ((long)p4)));      \
								        /* �ێ��޼����ؿ��¹�                  */\
}
/****************************************/
/* �ؿ�Ďڎ�����������ώ���(SI1�Î�����)        */
/****************************************/
#ifdef  SI_1
#define DBGTRACE(P1)                                                          \
{                                                                             \
    printf(P1);                                                               \
    printf("\n");                                                             \
}
#else
#define DBGTRACE(P1)                                                          \
{                                                                             \
    mc_loga(MILOGA00, 8, (char *)P1);   /* �ێ��޼����ؿ��¹�              PD0A*/\
}
#endif
/****************************************/
/* ���ގݎ̎߼����ώ���(SI1�Î�����)               */
/****************************************/
#ifdef  SI_D
#define DBGDMP(P1, P2)                                                        \
{                                                                             \
    extern  long   DumpHex();                                                 \
	DumpHex(P1, P2);                    /* ���ގݎ̎߼����ؿ��¹�                */\
}
#else
#define DBGDMP(P1, P2)
#endif