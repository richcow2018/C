/****************************************************************************/
/* �ե�����̾����mi_std.h                                                   */
/* ��ǽ  ������  �ơ��֥륢�ɥ쥹����                                       */
/*               �ɣҥ�����                                                 */
/*               ���֣ɣҥ�����                                             */
/*               �⥸�塼��ɣ�                                             */
/*               �ɣң¥ƥ�ץ졼��                                         */
/*               �����ƥॳ����ץ�ȥ�����                                 */
/*               �����ƥॳ���륢��������Ȱ�ƥ�ץ졼��                 */
/* ��������  ��  1993.12.13                                                 */
/* �ѹ�����  ��  1994.09.16                                             PD01*/
/*   �ξ����ɼ(ST1068) �ɣã��ֵ����Υ����ɽ���                            */
/* �ѹ�����  ��  1994.10.14                                             PD0A*/
/*   �ξ����ɼ(ST1761) ����ɡ����б�                                      */
/* �ѹ���������  1995.06.13                                             PD0C*/
/*   �����ѹ��׵��(SSCY0062) ưŪ�����ƥ��ѹ��б�                          */
/* �ѹ���������  1995.07.27                                              M01*/
/*   �ξ����ɼ(ST0713) ��������Ƚ�꽤��                                    */
/* �ѹ���������  1995.07.12                                             PD0E*/
/*   �����ѹ��׵��(SSCY0094) ���ر����ѹ��б�                              */
/* �ѹ���������  1995.08.03                                             PD0F*/
/*   �����ѹ��׵��(SSCY0097) ��������̎ߎݤǤΎ̎ߎێ������Ύގ��Ĳ���                   */
/* �ѹ���������  1995.08.09                                             PD0G*/
/*   �����ѹ��׵��(SSCY0098) �������̤�̵����                              */
/* �ѹ���������  1995.09.29                                             PD0J*/
/*   �����ѹ��׵��(SSCY0113) ���׸ξ㸡���ѹ��б�                          */
/* �ѹ���������  1995.11.07                                             PD0N*/
/*   �����ѹ��׵��(SSCY0126) X.25���׎��Ďގ؎Ď׎��б�                             */
/* �ѹ���������  1995.11.29                                             PD0O*/
/*   �����ѹ��׵��(SSCY0063) �̣ɣãкƵ�ư�б�                            */
/* �ѹ���������  1996.03.05                                             PD0R*/ 
/*   �����ѹ��׵��(SSCY0156) X.25�����ƻ��ѹ��б�                          */ 
/* �ѹ���������  1996.07.12                                             PD02*/ 
/*   �ξ����ɼ(ST4483) MIA_BCCN����                                        */
/* �ѹ���������  1996.12.17                                             PD0V*/ 
/*   �����ѹ��׵��(SSCY0188) PU,CH�ֹ����������ǽ����                         */
/* �ѹ���������  1997.03.05                                             PD0X*/ 
/*   �����ѹ��׵��(SSCY0194) �Ҏ����������ɲ�			                        */
/* �ѹ���������  1997.03.17                                             PD0Y*/ 
/*   �ξ����ɼ(ST4810) ISDN��Ʊ�����������ɲ�                              */
/* �ѹ���������  1997.05.12                                             PD0Z*/ 
/*   �ξ����ɼ(ST4834) LICP��λ�ƻ��ѹ�                                    */
/* �ѹ���������  1997.06.25                                          ST4868 */ 
/*   �ξ����ɼ(ST4868) ISDN��Ʊ���������潤��                              */
/* �ѹ���������  1998.02.16                                        SSCY0203 */ 
/*   �����ѹ�(SSCY0203) �����ξ�£������κƻ���							*/
/****************************************************************************/
#include <tcom.h>                       /* SMP�Î��̎ގٶ��������               */
#include <psect.h>                      /* psect                            */
#include <mcs_0000.h>                   /* �������塼�鶦�̥إå��ե�����   */
#include <mf.h>                         /* ��桥��                         */
#include <mi_log.h>                     /* �̎ߎێ����ێ��޼�����Ϣ�ώ���              */

extern   PSCPSECT      pscparea;        /* PSECT��Ύߎ��ݎ�                     */

#ifdef  DMY
#undef  C_IOPEN
#define C_IOPEN(p1,p2,p3,p4,p5,p6,p7) dmy_iopen(p1,p2,p3,p4,p5,p6,p7)  
#undef  C_ICLOSE
#define C_ICLOSE(p1,p2) dmy_iclose(p1,p2)  
#undef  C_IIOCTL
#define C_IIOCTL(p1,p2,p3,p4,p5) dmy_iioctl(p1,p2,p3,p4,p5)
#undef  C_IOCTL
#define C_IOCTL(p1,p2,p3,p4) dmy_ioctl(p1,p2,p3,p4)
#undef  C_CONFIG
#define C_CONFIG(p1,p2,p3) dmy_config(p1,p2,p3)
#endif

/**************************************/
/* �Σ֣ԥץ������̰�ƥ�ץ졼�� */
/**************************************/
typedef struct {
    long            chead[3];           /* ����ƥ����ȥإå���             */
    short           lctxcnt;            /* �������掺�ݎÎ����Ŀ�                 */
    char            battvrn;            /* �������׵ḵ����               */
    char            mode;               /* ��ư�⡼��                       */
    long            lctxa;              /* �������掺�ݎÎ�������Ƭ���Ďގڎ�          */
    long            rnlpt;              /* TLPT���ֹ�                     */
    long            batreqa;            /* �������׵Ꮁ�Ďގڎ������          */
    long            tblp;               /* SG�Î��̎ގ���Ƭ���Ďގڎ�                 */
    long            ukeno;              /* �������׵�����ֹ�             */
    long            faceno;             /* ������TFAC���ݎĎ�NO               */
    long            hctxa;              /* ��¾���掺�ݎÎ�������Ƭ���Ďގڎ�      PD0C*/
    char            pcchkf;             /* PU,CH������������                PD0V*/
	char			rcyflg;				/* �����ξ�����ƻ��ѻ��� SSCY0203*/
    short           lp_bueno;           /* �ǽ�����£�����ȥ�SSCY0203 PD0V*/
										/* (HDLC�َ��̎�&-rcy�����ͭ��)SSCY0203*/
} MINVTP;

/**************************************/
/* SG�Î��̎ގَ��Ďގڎ��؎��ľ�γƼ�Î��̎ގ٤ΰ��� */
/**************************************/
#define TCST_NO    0                    /* �ԣãӣԥ��ɥ쥹�ΰ���           */
#define TPCT_NO    1                    /* �ԣУãԥ��ɥ쥹�ΰ���           */
#define TPAT_NO    2                    /* �ԣУ��ԥ��ɥ쥹�ΰ���           */
#define TLGT_NO    3                    /* �ԣ̣ǣԥ��ɥ쥹�ΰ���           */
#define TLPT_NO    4                    /* �ԣ̣Уԥ��ɥ쥹�ΰ���           */
#define TFAP_NO    5                    /* �ԣƣ��Х��ɥ쥹�ΰ���           */
#define TFAC_NO    6                    /* �ԣƣ��å��ɥ쥹�ΰ���           */
#define TFAH_NO    7                    /* �ԣƣ��ȥ��ɥ쥹�ΰ���           */
#define TFAX_NO    8                    /* �ԣƣ��إ��ɥ쥹�ΰ���       PD0A*/
#define TSST_NO    9                    /* �ԣӣӣԥ��ɥ쥹�ΰ���       PD0A*/
#define TFAL_NO   10                    /* �ԣƣ��̥��ɥ쥹�ΰ���       PD0C*/

/**************************************/
/* �ֵ������                         */
/**************************************/
#define MINORMAL     0                  /* ����                             */
#define MIERR       -1                  /* �۾�                             */
#define MINOSING     0                  /* ¸�ߤ��ʤ�                       */
#define ZERO         0                  /* ��                               */
#define MIBUSY       0x9f80000c         /* �ˎގ��ގ�                            */
#define MIPUOUS      0x9f80000d         /* PU ous (out of service)          */
#define MIDMAOUS     0x9f80000e         /* DMAC ous (out of service)        */
#define MIIOCOUS     0x9f80000f         /* IOC ous (out of service)         */
#define RTN_RETRY    1                  /* �؎Ď׎���ǽ                         */
#define RTN_END      2                  /* �؎Ď׎��Բ�                         */
#define RTN_ERR      3                  /* ���顼                       PD0F*/
#define ERR80        0x80               /* �ʎ��Ď޾㳲                   stPD0A*/
#define ERR90        0x90               /* �ӎÎގ�DSU�㳲                      */
#define ERRA0        0xA0               /* �Îގ����؎ݎ��ڎ͎ގٰ۾�              PD0R*/
#define ERRA3        0xA3               /* ���������٥�۾�               */
#define ERRE5        0xE5               /* �����桢�������֤�               */
#define ERRCHK       0xffff0000         /* �ֵ��͎���������                     */
#define RTNCHK       0x00f00000         /* ���̎��׎�����������                    */
#define MDCHK        0x00ffffff         /* �ӎ��Ď����Ǹ��Ў���������               */
#define ERR_DCON     0x00F00002         /* �ӎ��Ď����Ǹ���                     */

#define DYR_ERR1     0x00010000         /* ���֤����               stPD0C*/
#define DYR_ERR2     0x00020000         /* ���ء����ᤷ���׻���³������     */
#define DYR_ERR3     0x00030000         /* ��¾���������                   */
#define DYR_ERR4     0x00040000         /* ���ظ����Ѳ���                   */
#define DYR_ERR5     0x00050000         /* ������BU����                     */
#define DYR_ERR6     0x00060000         /* �׻���³�桡               edPD0C*/

/**************************************/
/* �����ֵ������                     */
/**************************************/
#define TOUT1_4W     0xC1E50000         /* �����Îގ��������ю�����(CD����)             */
#define TOUT2_4W     0xC1E50001         /* �����Îގ��������ю�����(CD����)             */
#define ERRC1F0      0xC1F00000         /* ���̎��׎�                          */
#define ERRC1F2      0xC1F20000         /* ���̎��׎�                          */
#define ERRC180      0xC1800000         /* �ʎ��Ď޾㳲                         */
#define ERRC190      0xC1900000         /* �ӎÎގ�DSU�㳲                      */
#define ERRC1E4      0xC1E40000         /* �����桢�������֤�               */
#define ERRC1E5      0xC1E50000         /* �����桢�������֤�               */
#define ERRC1A2      0xC1A20000         /* ���������٥�۾�               */
#define ERRC1A3      0xC1A30000         /* ���������٥�۾�               */
#define ERRC1A0      0xC1A00000         /* ���������٥�۾�               */

/**************************************/
/* HDLC�َ��̎��ֵ������                 */
/**************************************/
#define TOUT_HDLC    0xC2E50000         /* �����Îގ��������ю�����                   */
#define CHKF_HDLC    0xC2E50001         /* �����Îގ������������̎����َĎގ��׎�            */
#define ERRC2F0      0xC2F00000         /* ���̎��׎�                          */
#define ERRC2F1      0xC2F10000         /* ���̎��׎�                          */
#define ERRC2F2      0xC2F20000         /* ���̎��׎�                          */
#define ERRC280      0xC2800000         /* �ʎ��Ď޾㳲                         */
#define ERRC290      0xC2900000         /* �ӎÎގ�DSU�㳲                      */
#define ERRC2F3      0xC2F30000         /* �����桢�������֤�               */
#define ERRC2E4      0xC2E40000         /* �����桢�������֤�               */

/**************************************/
/* X25�ֵ������                      */
/**************************************/
#define ERRE8F0      0xE8F00000         /* ���̎��׎�                          */
#define ERRE8F1      0xE8F10000         /* ���̎��׎�                          */
#define ERRE8F2      0xE8F20000         /* ���̎��׎�                          */
#define ERRE880      0xE8800000         /* �ʎ��Ď޾㳲                         */
#define ERRE890      0xE8900000         /* �ӎÎގ�DSU�㳲                      */
#define ERRE8F3      0xE8F30000         /* �����桢�������֤�               */
#define ERRE8E5      0xE8E50000         /* �����桢�������֤�               */
#define ERRE8A0      0xE8A00000         /* �Îގ����؎ݎ��ڎ͎ގٰ۾�                  */
#define ERRE8B0      0xE8B00000         /* �Ȏ��Ď܎����ڎ͎ގٰ۾�                   */
#define ERRE8B1      0xE8B10000         /* �Ȏ��Ď܎����ڎ͎ގٰ۾�                   */
#define ERRE8B3      0xE8B30000         /* �Ȏ��Ď܎����ڎ͎ގٰ۾�                   */

/**************************************/
/* ISDN�ֵ������                     */
/**************************************/
#define ERRDBF0      0xDBF00000         /* ���̎��׎�                          */
#define ERRDBF1      0xDBF10000         /* ���̎��׎�                          */
#define ERRDBF2      0xDBF20000         /* ���̎��׎�                          */
#define ERRDB80      0xDB800000         /* �ʎ��Ď޾㳲                         */
#define ERRDBA0      0xDBA00000         /* �Îގ����؎ݎ��ڎ͎ގٰ۾�                  */
#define ERRDBB0      0xDBB00000         /* �ץ�ȥ���㳲             edPD0A*/

/**************************************/
/* �ӣãдؿ����ֵ������             */
/**************************************/
#define SHORING      0x0000f000         /* �����۾�                     PD01*/
#define SIZENG       0x0000f001         /* �������۾�                   PD01*/

/**************************************/
/* ������                             */
/**************************************/
#define SETSYU       0x01               /* ��Ǽ�����                   PD01*/
#define DATASYU      0x10               /* �Îގ�������                     PD01*/
#define TDATASZ      64                 /* TFAC���֤���юÎގ�����������     PD01*/
#define TMIASZ       100                /* ���֤�����׵���ʸ��������     PD01*/

#define    SUBADDR_MAX  23              /* �去�̎ގ��Ďގڎ�����Ĺ                 */
#define    JTQ931     0x08              /* JT-Q931�ΎՎ����ގ�������Ҏ��������� stPD0A*/
#define    SETUP      0x05              /* ������(SETUP)                    */
#define    DISCON     0x45              /* ����(DISCONNECT)                 */
#define    ICAUSESZ   4                 /* ��ͳɽ����������                     */
#define    FRMMAX     260               /* LAPD����I�̎ڎ���Ĺ(����̎����َĎ�)      */

#define    IBCID      0x04              /* ��ãǽ��                         */
#define    ICIID      0x18              /* �����Ȏټ��̻�                       */
#define    IFAID      0x1C              /* �̎����؎Î�                           */
#define    ICDID      0x6C              /* ȯ�ֹ�                           */
#define    ICHID      0x6D              /* ȯ���̎ގ��Ďގڎ�                       */
#define    ICGID      0x70              /* ���ֹ�                           */
#define    ICSID      0x71              /* �去�̎ގ��Ďގڎ�                       */
#define    ILLID      0x7C              /* ��̎ڎ���������                    */
#define    IHLID      0x7D              /* ��̎ڎ���������                    */
#define    IUUID      0x7E              /* �Վ����ގ��Վ�����                  edPD0A*/

#define    ON         0x01              /* �̎׎��ގ���                       PD0C*/
#define    OFF        0x00              /* �̎׎��ގ���                       PD0C*/

/**************************************/
/* ��������                           */
/**************************************/
#define LINECHK      0x60               /* �������̎���������                   */
#define LINE_4W      0x40               /* 4W                               */
#define LINE_LOOP    0x00               /* HDLC�َ��̎�                         */

/**************************************/
/* ���ܾ������                       */
/**************************************/
#define DEV_INS      0                  /* �ĺɲ��                         */
#define DEV_OUS      1                  /* �ĺ�                             */

/**************************************/
/* ��¾����׵��ѹ��о����           */
/**************************************/
#define CHG_LL       0x01               /* ʪ������                   stPD0C*/
#define CHG_PL       0x02               /* ��������                         */
#define CHG_PP       0x03               /* �����ѥ�                   edPD0C*/

/**************************************/
/* ��¾����׵�����������           */
/**************************************/
#define SY_DEL     0x01                 /* ű��                       stPD0C*/
#define SY_INS     0x02                 /* ����                             */
#define SY_CHG     0x03                 /* °���ѹ�                   edPD0C*/

/**************************************/
/* IRB�����̎����                        */
/**************************************/
#define TYPEN        0x00               /* �����̎�N                            */

/**************************************/
/* �ʎގ��̎�������� ��                   */
/**************************************/
#define CMBFPL       0L                 /* CM�ʎގ��̎��̎ߎ���                      */

/**************************************/
/* ���������                         */
/**************************************/
#define KO_00        0x00               /* �����ֹ棱����               PD0A*/
#define KO_01        0x01               /* �����ֹ棲����               PD0A*/
#define KO_SV        0x02               /* �׵�������ֹ�����           PD0A*/

/**************************************/
/* �ɣҥ��������                     */
/**************************************/
#define IR_TIMUP   MCSTIME              /* �����޴�λ���٥��               */
#define IR_TERMP   MCSTERM              /* �����ĺ�                         */

/**************************************/
/* �⥸�塼��ɣġʣͣɣġ����       */
/**************************************/
#define ML_TERMP   0x02                 /* �ץ�����λ����                 */
#define ML_4W      0x10                 /* ü��I/O�����Ȏ�����(4W)              */
#define ML_HDLC    0x20                 /* ü��I/O�����Ȏ�����(HDLC�َ��̎�)        */
#define ML_TEL     0x30                 /* ü��I/O�����Ȏ�����(TEL)             */
#define ML_BACKUP  0x40                 /* �ʎގ��������̎ߎ����Ȏ�����                 */
#define ML_LAN     0x50                 /* LAN�����Ȏ�����                      */
#define ML_BAT     0x60                 /* ����������                     */
#define ML_X25T    0x70                 /* ü��I/O�����Ȏ�����(X.25)        PD0A*/
#define ML_X25H    0x80                 /* �Ύ���I/O�����Ȏ�����(X.25)         PD0A*/
#define ML_TELH    0x90                 /* �Ύ���I/O�����Ȏ�����(TEL)          PD0A*/
#define ML_HAIT    0xa0                 /* ��¾�������                 PD0C*/
#define ML_LANT    0xb0                 /* ü��I/O�����Ȏ�����(LAN)         PD0O*/
#define ML_SYNC    0xb1                 /* ISDN��Ʊ����������           PD0Y*/

/**************************************/
/* �ɣҥ��������                     */
/**************************************/
#define IR_PROCE   0x10                 /* �ץ������٥��                 */
#define IR_LOPEN   0x20                 /* ����ͥ륪���ץ�λ             */
#define IR_LCLOS   0x30                 /* ����ͥ륯������λ             */
#define IR_LASYC   0x40                 /* ��Ʊ�����α���                   */
#define IR_ORIST   0x50                 /* ���ֻ���괰λ                 */
#define IR_ORIDT   0x60                 /* ���֤��Îގ���������λ               */
#define IR_CEND    0x70                 /* ��ƴ�λ                         */
#define IR_HEND    0x80                 /* ȯ�ƴ�λ   ����                  */
#define IR_LDCON   0x90                 /* ���Ǵ�λ                     PD0A*/
#define IR_INSID   0xa0                 /* �������٥��                     */
#define IR_LICP    0xb0                 /* �Ҏ̎ߎێ�����λ����              PD0O*/
#define IR_DLRSET  0xc0                 /* �Îގ����؎ݎ������괰λ            PD0R*/

/**************************************/
/* ���֣ɣҥ��������                 */
/**************************************/
#define SIR_ORIKA  0x01                 /* ���ֻ�׵�                     */
#define SIR_KIRIK  0x02                 /* ��������׵�                     */
#define SIR_HHAKK  0x03                 /* ȯ�������׵�                     */
#define SIR_NHAKK  0x04                 /* ȯ�����ءʵ���̵���׵�           */
#define SIR_HKKRI  0x05                 /* ȯ�ƶ��������׵ᡡ����������     */
#define SIR_KKYOK  0x06                 /* ���ص����׵ᡡ������������       */
#define SIR_CANCE  0x07                 /* ��������׵ᡡ����               */
#define SIR_MODOS  0x08                 /* �����׵�     ����                */
#define SIR_KNORM  0x09                 /* �����ĺɱ����������             */
#define SIR_KBUSY  0x0a                 /* �����ĺɱ����ʥӥ�����           */
#define SIR_IKHKR  0x0b                 /* ȯ�ư�������׵�                 */
#define SIR_IKAMO  0x0c                 /* ��������׵�    ������������     */
#define SIR_HEKAI  0x0d                 /* �ĺɲ���׵�          ������     */
#define SIR_IHRTN  0x0e                 /* ȯ�ư�����ر������������Ρ�     */
#define SIR_IMRTN  0x0f                 /* �������������������Ρˡ�       */
#define SIR_NSTOK  0x10                 /* �̿���߱����������         PD0A*/
#define SIR_NSTNG  0x11                 /* �̿���߱����ʰ۾��         PD0A*/
#define SIR_RINJI  0x12                 /* �׻���³�׵�                 PD0A*/
#define SIR_RINDA  0x13                 /* �׻������׵�                 PD0A*/
#define SIR_HAISY  0x14                 /* ��¾��������׵�             PD0C*/
#define SIR_HAIKY  0x15                 /* ��¾��ֲ���׵�             PD0C*/
#define SIR_HAISR  0x16                 /* ��¾�������������������Ρ� PD0C*/
#define SIR_HAIKR  0x17                 /* ��¾��ֲ���������������Ρ� PD0C*/
#define SIR_SBUSY  0x18                 /* ���ݎ�&���ێ����ޱ����ʥӥ�����      PD0J*/
#define SIR_LICPE  0x19                 /* LICP��λ����                 PD0Z*/
#define SIR_NULL   0x00                 /* �Σգ̣�              ������     */

/**************************************/
/* �ͣ˥�����                         */
/**************************************/
#define MKMOTI      0x03070100          /* �������                         */
#define MKCOMD      0x03060000          /* ���ޥ��                         */
#define MKLAN       0x03070200          /* �̣���                           */
#define MKHOST      0x03070300          /* �ۥ���                       PD0A*/
#define MKHAIT      0x030e0000          /* ��¾���                     PD0C*/
#define MKLICPEND   0x030c0000          /* LICP��λ����                 PD0Z*/

/**************************************/
/* ���󥿡��ե�����������             */
/**************************************/
#define IFCOMD      0x58001000          /* ���ώݎĎ�                            */
#define IFORIKAE    0x60000000          /* ���ֻ�׵�                     */
#define IFHESOKU    0x60000001          /* �����ĺɱ���                     */
#define IFOPEN      0x60000002          /* �����̎ߎ�����                        */
#define IFSC        0x60000003          /* ���ݎ�&���ێ������׵�/����           PD0J*/
#define IFIKAMOD    0x60000004          /* ������ᤷ�׵�                   */
#define IFKIRIKA    0x60000005          /* ��������׵ᡡ��                 */
#define IFKKYOKA    0x60000006          /* ���ص����׵ᡡ����               */
#define IFCANCEL    0x60000007          /* ��������׵ᡡ����������         */
#define IFMODOSI    0x60000008          /* ���ᤷ�׵�                       */
#define IFHHAKKI    0x60000009          /* ȯ�������׵�                     */
#define IFNHAKKO    0x6000000a          /* ȯ�����ءʵ���̵���׵�           */
#define IFHKKRIK    0x6000000c          /* ȯ�ƶ��������׵�                 */
#define IFIKHKRI    0x6000000d          /* ���ȯ�������׵�             PD0R*/
#define IFERR       0x6000000f          /* ���ݎ����̎����������Ď���������             */
#define IFLANNG     0x60000010          /* �̣��β����㳲����               */
#define IFLANOK     0x60000011          /* �̣��β����㳲��������           */
#define IFHKIRI     0x60000012          /* �̿�����׵�����ء�         PD0A*/
#define IFHKYO      0x60000013          /* �̿�����׵�ζ������ء�     PD0A*/
#define IFHMODO     0x60000014          /* �̿�����׵�����ᤷ��       PD0A*/
#define IFHREST     0x60000015          /* �̿��Ƴ���ǽ����             PD0A*/
#define IFRINJI     0x60000016          /* �׻���³�׵�                 PD0A*/
#define IFRINDA     0x60000017          /* �׻������׵�                 PD0A*/
#define IFHAISY     0x79a00041          /* ��¾��������׵�             PD0C*/
#define IFHAIKY     0x79a00042          /* ��¾��ֲ���׵�             PD0C*/
#define IFHAISO     0x60002000          /* ��¾����������             PD0C*/
#define IFHAIKO     0x60002001          /* ��¾��ֲ������             PD0C*/
#define IFLICPEND   0x10290001          /* LICP��λ����                 PD0Z*/

/**************************************/
/* ���μ��̿����                     */
/**************************************/
#define COMDCNT      12                 /* ���μ��̿�                       */

/**************************************/
/* ���μ������                       */
/**************************************/
#define TU_ORIKA  "-miorikae"           /* ���ֻ�׵�                     */
#define TU_KIRIK  "-mikirika"           /* ��������׵�                     */
#define TU_HHAKK  "-mihhakko"           /* ȯ�������׵�                     */
#define TU_NHAKK  "-minhakko"           /* ȯ�����ءʵ���̵���׵�           */
#define TU_HKKRI  "-mihkkrik"           /* ȯ�ƶ��������׵ᡡ����������     */
#define TU_KKYOK  "-mikkyoka"           /* ���ص����׵ᡡ������������       */
#define TU_CANCE  "-micancel"           /* ��������׵ᡡ����               */
#define TU_MODOS  "-mimodosi"           /* �����׵�     ����                */
#define TU_IKHKR  "-miikhkri"           /* ȯ�ư�������׵�                 */
#define TU_IKAMO  "-miikamod"           /* ��������׵�    ������������     */
#define TU_LANOR  "-milanori"           /* LAN�ޤ��֤���׵� ��  ����     */
#define TU_LANHE  "-milanins"           /* LAN�ĺɲ���׵�                  */

/**************************************/
/* ���ώݎĎގ��ݎ����̎�������ʸ�Îގ����莻���������    */
/**************************************/
#define ORI_D_SZ     15                 /* ���ֻ�׵�                     */
#define CYA_D_SZ     13                 /* ��������׵�                     */
#define HAK_D_SZ     15                 /* ȯ�������׵�                     */
#define NHAK_D_SZ    15                 /* ȯ�����ءʵ���̵���׵�           */
#define HAKK_D_SZ    29                 /* ȯ�ƶ��������׵ᡡ����������     */
#define KYOKA_D_SZ   13                 /* ���ص����׵ᡡ������������       */
#define CAN_D_SZ     13                 /* ��������׵ᡡ����               */
#define MODO_D_SZ    13                 /* �����׵�     ����                */
#define IHAK_D_SZ    14                 /* ȯ�ư�������׵�                 */
#define IMODO_D_SZ    9                 /* ��������׵�    ������������     */
#define KAIJYO_D_SZ  13                 /* �ĺɲ���׵�    ������������     */
#define LICPEND_D_SZ 20                 /* LICP��λ����    ���������� ��PD0Z*/

/**************************************/
/* �������ʸ���̰莻���������           */
/**************************************/
#define ORI_SZ       12                 /* ���ֻ�׵�                     */
#define CYA_SZ       24                 /* ��������׵�                     */
#define HAK_SZ       24                 /* ȯ�������׵�                     */
#define NHAK_SZ      52                 /* ȯ�����ءʵ���̵���׵�       PD0A*/
#define HAKK_SZ      52                 /* ȯ�ƶ��������׵ᡡ���������� PD0A*/
#define KYOKA_SZ     12                 /* ���ص����׵ᡡ������������       */
#define CAN_SZ       12                 /* ��������׵ᡡ����               */
#define MODO_SZ      12                 /* �����׵�     ����                */
#define IHAK_SZ      12                 /* ȯ�ư�������׵�                 */
#define IMODO_SZ     12                 /* ��������׵�    ������������     */
#define RINJI_SZ     52                 /* �׻���³�׵�    ������������ PD0A*/
#define RINDA_SZ     24                 /* �׻������׵�    ������������ PD0A*/

/**************************************/
/* �Ҏ���������ID                           */
/**************************************/
#define MSG_00      "SI00"              /* ���س���                         */
#define MSG_01      "SI01"              /* ���ؽ�λ                         */
#define MSG_02      "SI02"              /* ���ᤷ����                       */
#define MSG_03      "SI03"              /* ���ᤷ��λ                       */
#define MSG_04      "SI04"              /* ��������̵��                     */
#define MSG_05      "SI05"              /*                                  */
#define MSG_06      "SI06"              /* ��������̵��                     */
#define MSG_07      "SI07"              /* ����ͥ�ξ�                     */
#define MSG_08      "SI08"              /*                                  */
#define MSG_09      "SI09"              /* ��ǥ�ξ�                       */
#define MSG_10      "SI10"              /* ��������                         */
#define MSG_11      "SI11"              /*                                  */
#define MSG_12      "SI12"              /* ����󥻥볫��                   */
#define MSG_13      "SI13"              /* ���ֳ���                         */
#define MSG_14      "SI14"              /* ���ֽ�λ                         */
#define MSG_15      "SI15"              /* ����󥻥뽪λ                   */
#define MSG_16      "SI16"              /* �ξ����                         */
#define MSG_17      "SI17"              /* �����ξ�                         */
#define MSG_18      "SI18"              /* �ѥ����輺��                     */
#define MSG_19      "SI19"              /* ������³����                     */
#define MSG_20      "SI20"              /* �ѥ�᡼�������顼               */
#define MSG_21      "SI21"              /* �ѥ�������                       */
#define MSG_22      "SI22"              /* ȯ���׵���                       */
#define MSG_23      "SI23"              /* ����̤����                       */
#define MSG_24      "SI24"              /* ���긵���                       */
#define MSG_25      "SI25"              /* �����                           */
#define MSG_26      "SI26"              /* �оݳ�����                       */
#define MSG_27      "SI27"              /* ���ؤ���                         */
#define MSG_28      "SI28"              /* ���ᤷ��                         */
#define MSG_29      "SI29"              /* ���֤����                     */
#define MSG_30      "SI30"              /* ȯ�ư۾�                         */
#define MSG_31      "SI31"              /* ��ư۾�                         */
#define MSG_32      "SI32"              /* ���֤��۾�                       */
#define MSG_33      "SI33"              /* BU�����㳲                       */
#define MSG_34      "SI34"              /* �ѥ���ɥ��顼                 */
#define MSG_35      "SI35"              /* �����ȹ���                       */
#define MSG_36      "SI36"              /* �ȹ�����                         */
#define MSG_37      "SI37"              /* �ȹ���λ                         */
#define MSG_38      "SI38"              /* �ϡ��ɾ㳲                       */
#define MSG_39      "SI39"              /* �����ĺ�                         */
#define MSG_40      "SI40"              /* �����ȹ�                         */
#define MSG_41      "SI41"              /* �������ĺ�                       */
#define MSG_42      "SI42"              /* �Ƶ�ư��                         */
#define MSG_43      "SI43"              /* �������饹����                   */
#define MSG_44      "SI44"              /* PU,CH����                        */
#define MSG_45      "SI45"              /* ����ͥ�̤����                   */
#define MSG_46      "SI46"              /* �����ĺ���                       */
#define MSG_47      "SI47"              /* ������س���                     */
#define MSG_48      "SI48"              /* ������ؽ�λ                     */
#define MSG_49      "SI49"              /* ���ؤ���                         */
#define MSG_50      "SI50"              /* ���ᤷ��                         */
#define MSG_51      "SI51"              /* ���֤����                     */
#define MSG_52      "SI52"              /* �����㳲                         */
#define MSG_53      "SI53"              /* �Хåե��㳲                     */
#define MSG_54      "SI54"              /* �ץ�ȥ���㳲                   */
#define MSG_55      "SI55"              /* �׻������㳲               stPD0A*/
#define MSG_56      "SI56"              /* �Ʋ�������                       */
#define MSG_57      "SI57"              /* �ꥻ�å�����                     */
#define MSG_58      "SI58"              /* �ꥹ����������                   */
#define MSG_59      "SI59"              /* ���������                       */
#define MSG_60      "SI60"              /* ���ˎގ��ގ�����                    */
#define MSG_61      "SI61"              /* ���ˎގ��ގ����                    */
#define MSG_62      "SI62"              /* �ꥻ�å��Դ�λ                   */
#define MSG_63      "SI63"              /* �ǡ�����󥯰۾�                 */
#define MSG_64      "SI64"              /* �⡼����������                   */
#define MSG_65      "SI65"              /* �⡼����������                   */
#define MSG_66      "SI66"              /* �ƣңͣ���������                 */
#define MSG_67      "SI67"              /* �ƣңͣҼ�������                 */
#define MSG_68      "SI68"              /* ��³����                         */
#define MSG_69      "SI69"              /* ��������                         */
#define MSG_70      "SI70"              /* �������                         */
#define MSG_71      "SI71"              /* �؎ݎ��㳲��                        */
#define MSG_72      "SI72"              /* �؎ݎ��㳲��                        */
#define MSG_73      "SI73"              /* BU��������                 edPD0A*/
#define MSG_74      "SI74"              /* ��¾�����                   PD0C*/
#define MSG_75      "SI75"              /* ��¾�����                   PD0C*/
#define MSG_76      "SI76"              /* LICP��ư����                 PD0O*/
#define MSG_77      "SI77"              /* ��³����                     PD0X*/
/**************************************/
/* �Ύߎ��Ď����Ď�                           */
/**************************************/
#define PST_000     0x0000              /* ���ｪλ                         */
#define PST_010     0x0010              /* ������������                     */
#define PST_100     0x0100              /* �������顼                       */
#define PST_110     0x0110              /* �ɣãн�����                     */
#define PST_120     0x0120              /* �����ֹ�����                     */
#define PST_130     0x0130              /* �����ॢ����                     */
#define PST_140     0x0140              /* ��ǥ२�顼                     */
#define PST_144     0x0144              /* �����㳲                         */
#define PST_145     0x0145              /* �ϡ��ɾ㳲                       */
#define PST_146     0x0146              /* �ģͣ��ĺ�                       */
#define PST_147     0x0147              /* �ɣϣ��ĺ�                       */
#define PST_148     0x0148              /* �У��㳲                         */
#define PST_149     0x0149              /* ����ȥ������ĺɰܹ���         */
#define PST_200     0x0200              /* ���󥿡��ե��������顼           */
#define PST_300     0x0300              /* ̤��ƾ���                       */
#define PST_400     0x0400              /* �����ְ۾�                       */
#define PST_500     0x0500              /* �ɣãн�����                     */
#define PST_600     0x0600              /* ���긵���                       */
#define PST_700     0x0700              /* �����Բ�ǽ                       */
#define PST_800     0x0800              /* �ѥ���ɥ��顼                 */
/**************************************/
/* �ɣң¥ƥ�ץ졼��                 */
/**************************************/
typedef struct {
    unsigned long       qlink[2];       /* ���塼���                     */
    unsigned char       btyp;           /* �£ԣ٣�                         */
    unsigned char       gmid;           /* �ǣͣɣ�                         */
    unsigned char       dmid;           /* �ģͣɣ�                         */
    unsigned char       omid;           /* �ϣͣɣ�                         */
    unsigned char       ir_cd;          /* �ɣҥ�����                       */
    unsigned char       sir_cd;         /* ���֣ɣҥ�����                   */
    short               endcd;          /* ��λ������                       */
    long                ctxtp;          /* ����ƥ����ȥ��ɥ쥹   ��        */
    long                msglen;         /* ������ʸĹ���ꥶ�����           */
    long                msgp;           /* ������å������ݥ���           */
    long                rd;             /* �����                           */
    long                faceno;         /* TFAC���ݎĎ�NO                       */
    long                eventno;        /* ���͎ގݎ��ֹ桡                      */
    long                argarea[5];     /* �����ƥॳ���륢��������Ȱ�   */
}   MIIRB;
/**************************************/
/* �������楳��ƥ����ȥƥ�ץ졼��   */
/**************************************/
typedef struct {
    long            chead[3];           /* ����ƥ����ȥإå���             */
    short           lineno;             /* �����ֹ�                         */
    short           sysrtcnt;           /* �����Îю����َ؎Ď׎������ݎ�                  */
    long            devid;              /* ����ID                           */
    long            timerid;            /* ������ID                            */
    long            openirba;           /* �����̎ߎ��׵�IRB���Ďގڎ�                */
    long            ctrolirba;          /* ��Ʊ���׵�IRB���Ďގڎ�               */
    long            faceno;             /* TFAC���ݎĎ�NO                       */
    long            fackop;             /* TFAC������Ύߎ��ݎ�                  */
    long            faheno;             /* TFAH���ݎĎ�NO                       */
    char           *fahkop;             /* TFAH������Ύߎ��ݎ�                  */
    long            sakieno;            /* ������TFAC���ݎĎ�NO                 */
    long            sakikop;            /* ������TFAC������Ύߎ��ݎ�            */
    long            m_id;               /* �оݎ����Ȏ�����ӎ��ގ�����ID             */
    long            ukeno;              /* �����ֹ�                         */
    short           postcd;             /* �Ύߎ��Ď����Ď�                         */
    char            rockf;              /* ���ݎÎ����Ďێ����̎׎���                PD0C*/
    char            ikfg;               /* �������ե饰                   */
    char            telno[22];          /* �����������ֹ�               PD0A*/
    char            isdncno;            /* ���ֹ�                       PD0A*/
    char            dkei;               /* ��������������̎ߎێ����϶�ʬ    PD0A*/
    long            telketa;            /* �����������ֹ���               */
    short           wsno;               /* �����ֹ�                         */
    char            koflg;              /* ȯ����̎׎���                   PD0A*/
    char            stopf;              /* �̿���߾��֎̎׎���             PD0A*/
    long            isdnfd;             /* ISDN�ե�����ǥ�������ץ�   PD0A*/
    char            dprocnm[8];         /* ��������������̎ߎێ���̾        PD0A*/
    long            r_faceno;           /* TFAC���ݎĎ�NO�����                 */
    long            r_fackop;           /* TFAC������Ύߎ��ݎ������            */
    long            r_m_id;             /* �оݎ����Ȏ�����ӎ��ގ�����ID�����       */
    long            r_ukeno;            /* �����ֹ������                   */
    long            r_miaa;             /* MIA ADDR �����                  */
    char            cttno[16];          /* ��³�����ֹ�                 PD0A*/
    long            cttsz;              /* ��³�����ֹ掻������             PD0A*/
    char            chgcd;              /* �ѹ���ʬ                     PD0C*/
    char            syoricd;            /* ��������                     PD0C*/
    char            passc;              /* �ʎߎ����ێ����޾���                 PD0J*/
    char            callcnt;            /* ����³�؎Ď׎������ݎ���             PD0N*/
    long            chldirba;           /* �̎ߎێ�����λ����IRB���Ďގڎ�        PD0O*/
    long            dlreirba;           /* �Îގ����؎ݎ�������IRB���Ďގڎ�        PD0R*/
}  MILCTX;
/**************************************/
/* �����ʎߎ������̎ߎ�/���ێ����޽����ʎߎ׎Ҏ���       */
/**************************************/
typedef struct {
    unsigned long       qlink[2];       /* ���塼���                     */
    unsigned char       btyp;           /* �£ԣ٣�                         */
    unsigned char       gmid;           /* �ǣͣɣ�                         */
    unsigned char       dmid;           /* �ģͣɣ�                         */
    unsigned char       omid;           /* �ϣͣɣ�                         */
    unsigned char       ir_cd;          /* �ɣҥ�����                       */
    unsigned char       sir_cd;         /* ���֣ɣҥ�����                   */
    short               endcd;          /* ��λ������                       */
    long                ctxtp;          /* ����ƥ����ȥ��ɥ쥹   ��        */
    short    wsno;                      /* �ף��ֹ�                         */
    char     timerf;                    /* ������ȯ�Ԏ̎׎���                      */
    char     yob1;                      /* ͽ��                             */
    long     irbp;                      /* IRB�Ύߎ��ݎ�                         */
    long     ifcd;                      /* ���ݎ����̎����������Ď�                     */
    long     yob3[7];                   /* ͽ��                             */
} IOPRM;
/**************************************/
/* ��Ʊ�����Ρʣ��ס�                 */
/**************************************/
typedef struct {
    long     func;                      /* ������                         */
    long     errcd;                     /* ���׎������Ď�                          */
} SYGI4W;
/**************************************/
/* ��Ʊ�����Ρʣȣģ̣á�             */
/**************************************/
typedef struct {
    long     func;                      /* ������                         */
    long     errcd;                     /* ���׎������Ď�                          */
} SYGIHDLC;
/**************************************/
/* ��Ʊ�����Ρ������֡�               */
/**************************************/
typedef struct {
    long     func;                      /* ������                         */
    long     errcd;                     /* ���׎������Ď�                          */
} SYGITEL;
/**************************************/
/* ��Ʊ�����Ρ�X.25��                 */
/**************************************/
typedef struct {
    long     func;                      /* ������                     PD0A*/
    long     errcd;                     /* ���׎������Ď�                      PD0A*/
} SYGIX25;
/**************************************/
/* �Îގʎގ������桦�ƻ�                   */
/**************************************/
typedef struct {
    long     iprmsz;                    /* ���ώʎߎ׎Ҏ���Ĺ                 PD0A*/
    long     oprmsz;                    /* ���ώʎߎ׎Ҏ���Ĺ                 PD0A*/
    long     msgcnt;                    /* �Ҏ��������޿�                     PD0A*/
    char     protid;                    /* �̎ߎێĎ��ټ��̻�                 PD0A*/
    char     callno[2];                 /* ���ֹ�                       PD0A*/
    char     msgt;                      /* �Ҏ��������޼���                   PD0A*/
} ISDNMCOM;
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  COMADDR													*/
/*																			*/
/* �㵡ǽ���ס�  �Î��̎ގ٤ζ����􎱎Ďގڎ��μ�����Ԥ�                     		*/
/*																			*/
/* �㲾������																*/
/*	   TBLNO     �оݎÎ��̎ގ��ֹ�   											*/
/*	   RTN	     �оݶ����􎱎Ďގڎ�     										*/
/****************************************************************************/
#define COMADDR(TBLNO, RTN)                                                   \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT������Ύߎ��ݎ�                   */\
    TCOMPAT  **sgtp;                    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ�             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT������Ύߎ��ݎ������           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ������     */\
    RTN = (void *)sgtp[TBLNO];          /* �����􎱎Ďގڎ������              */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  SUBADDR													*/
/*																			*/
/* �㵡ǽ���ס�  �Î��̎ގ٤Ύ��̎޶����􎱎Ďގڎ��μ�����Ԥ�                     		*/
/*																			*/
/* �㲾������																*/
/*	   TBLNO     �оݎÎ��̎ގ��ֹ�   											*/
/*	   RTN	     �оݎ��̎޶����􎱎Ďގڎ�   										*/
/****************************************************************************/
#define SUBADDR(TBLNO, RTN)                                                   \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT������Ύߎ��ݎ�                   */\
    TCOMPAT  **sgtp;                    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ�             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT������Ύߎ��ݎ������           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ������     */\
    RTN = (void *)(sgtp[TBLNO] + 1);    /* ���̎޶����􎱎Ďގڎ������           */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  KOADDR		    											*/
/*																			*/
/* �㵡ǽ���ס�  �Î��̎ގ٤θ����􎴎ݎĎ��ֹ�������􎴎ݎĎ؎��Ďގڎ��μ�����Ԥ�		*/
/*																			*/
/* �㲾������																*/
/*	   TBLNO     �оݎÎ��̎ގ��ֹ�   											*/
/*	   ENO       �����􎴎ݎĎ��ֹ�   											*/
/*	   RTN	     �����􎴎ݎĎ؎��Ďގڎ�      										*/
/****************************************************************************/
#define KOADDR(TBLNO, ENO, RTN)                                               \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT������Ύߎ��ݎ�                   */\
    TCOMPAT  **sgtp;                    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ�             */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT������Ύߎ��ݎ������           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ������     */\
    RTN = (void *)((long)(sgtp[TBLNO] + 1) + sgtp[TBLNO]->tcomsbps +          \
                   sgtp[TBLNO]->tcomprsl * (ENO - 1));                        \
                                        /* �����􎴎ݎĎ؎��Ďގڎ������          */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  KOENTNO        											*/
/*																			*/
/* �㵡ǽ���ס�  �Î��̎ގ٤θ����􎴎ݎĎ؎��Ďގڎ��������􎴎ݎĎ��ֹ�μ�����Ԥ�		*/
/*																			*/
/* �㲾������																*/
/*	   TBLNO     �оݎÎ��̎ގ��ֹ�   											*/
/*	   ADDR      �����􎴎ݎĎ؎��Ďގڎ�   											*/
/*	   RTN	     �����􎴎ݎĎ��ֹ�      										*/
/****************************************************************************/
#define KOENTNO(TBLNO, ADDR, RTN)                                             \
{                                                                             \
    MINVTP   *nvtkop;                   /* NVT������Ύߎ��ݎ�                   */\
    TCOMPAT  **sgtp;                    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ�             */\
    long     work;                      /* �܎������؎�                           */\
    nvtkop = (MINVTP *)(mcsprefix + 1); /* NVT������Ύߎ��ݎ������           */\
    sgtp = (TCOMPAT **)nvtkop->tblp;    /* SG�Î��̎ގَ��Ďގڎ��؎��ĎΎߎ��ݎ������     */\
    RTN = (((long)(ADDR) - (long)sgtp[TBLNO]                                  \
		- (long)(sizeof(TCOMPAT)) - (long)sgtp[TBLNO]->tcomsbps)              \
		/ (long)sgtp[TBLNO]->tcomprsl) + 1;                                   \
										/* �����􎴎ݎĎ�NO�����             */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_IENT        											*/
/*																			*/
/* �㵡ǽ���ס�  (�����ˎގ�������)ICP���ώݎĎ޳��Ϥ�ȯ�Ԥ���	                     	*/
/*																			*/
/* �㲾������																*/
/*	   UKENO     �����ֹ�   	     										*/
/*	   MSGP      ��ʸ��Ǽ�莱�Ďގڎ�   											*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_IENT(UKENO, MSGP, M_ID)                                           \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = ms_ient((long)UKENO, (long *)MSGP);                                 \
                                        /* ICP���ώݎĎ޳���                     */\
    if( ret != MINORMAL )               /* �ֵ��Ͱ۾��                     */\
    {                                                                         \
        MIAPABT(ABTOIENT, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_IRES        											*/
/*																			*/
/* �㵡ǽ���ס�  (�����ˎގ�������)ICP���ώݎĎ޼��դ�ȯ�Ԥ���	                     	*/
/*																			*/
/* �㲾������																*/
/*	   UKENO     �����ֹ�   	     										*/
/*	   RTN       �ֵ���         											*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_IRES(UKENO, RTN, M_ID)                                            \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = ms_ires((long)UKENO, (long)RTN);                                    \
                                        /* ICP���ώݎĎ޼�������                 */\
    if( ret != MINORMAL )               /* �ֵ��Ͱ۾��                     */\
    {                                                                         \
        MIAPABT(ABTOIRES, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_IEND        											*/
/*																			*/
/* �㵡ǽ���ס�  (�����ˎގ�������)ICP���ώݎĎ޽�λ��ȯ�Ԥ���	                     	*/
/*																			*/
/* �㲾������																*/
/*	   UKENO     �����ֹ�   	     										*/
/*	   RTN       �ֵ���         										PD01*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_IEND(UKENO, RTN, M_ID)                                            \
{                                       /*                              PD01*/\
    long    ret;                        /* �ֵ���                           */\
    ret = ms_iend((long)UKENO, (long)RTN);                                    \
										/* ICP���ώݎĎ޽�λ����             PD01*/\
    if( ret != MINORMAL )               /* �ֵ��Ͱ۾��                     */\
    {                                                                         \
        MIAPABT(ABTOIEND, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  TELNO4          											*/
/*																			*/
/* �㵡ǽ���ס�  �����ֹ�β�������������                              	*/
/*																			*/
/* �㲾������																*/
/*	   CTXTP     ���ݎÎ����ĎΎߎ��ݎ�        										*/
/*	   RTN       �����ֹ沼����   											*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define TELNO4(CTXTP, RTN, M_ID)                                              \
{                                                                             \
    char  *area;                        /* ���򎴎؎�                          */\
    area = (char *)(((MILCTX *)CTXTP)->telno +                                \
                    (long)(((MILCTX *)CTXTP)->telketa - 4));                  \
                                        /* �����ֹ沼������Ф�           */\
    MIA_CBCN(area, &RTN, 4, M_ID);      /* �����׎���/�ʎގ��Ŏ��Ѵ�                  */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_FRBF													*/
/*																			*/
/* �㵡ǽ���ס�  �ס���Хåե��β�����Ԥ� 								*/
/* �㲾������																*/
/*	   MSGP		 �ס���Хåե��ݥ��� 									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_FRBF(MSGP, M_ID)                                                  \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mo_frbf((char *)MSGP);        /* �ʎގ��̎�����                        */\
    if( ret != MINORMAL )               /* �ֵ��Ͱ۾��                     */\
    {                                                                         \
        /* MIAPABT(ABTOFRBF, ABT_NULL, M_ID, ret); */                         \
                                        /* �̎ߎێ������Ύގ���                ST4868 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_MBID													*/
/*																			*/
/* �㵡ǽ���ס�  �Ҏ��َΎގ�����ID�μ�����Ԥ�      								*/
/* �㲾������																*/
/*	   SNPN		 �̎ߎێ���ID                									*/
/*	   MBID	     �Ҏ��َΎގ�����ID                   								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_MBID(SNPN, MBID, M_ID)                                            \
{                                                                             \
    MBID = mi_mbid(SNPN);               /* �Ҏ��َΎގ�����id����                   */\
    if( MBID < MINOSING )               /* �ҎَΎގ�����ID�������Ǥ��ʤ��ä��Ȥ�  */\
    {                                                                         \
        MIAPABT(ABTOMBID, ABT_NULL, M_ID, MBID);                              \
                                        /* �ץ������ܡ���                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_COPY													*/
/*																			*/
/* �㵡ǽ���ס�  �ΰ��ʣ�̤�Ԥ�            								*/
/* �㲾������																*/
/*	   MOTO		 ʣ�̸�                  									*/
/*	   SAKI	     ʣ����                      								*/
/*	   LEN	     �ΰ���礭��        										*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_COPY(MOTO, SAKI, LEN, M_ID)                                       \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mc_copy((char *)MOTO, (char*)SAKI, (long)LEN);                      \
										/* �ΰ莺�ˎߎ�                         */\
    if( ret != MINORMAL )               /* �ҎَΎގ�����ID�������Ǥ��ʤ��ä��Ȥ�  */\
    {                                                                         \
        MIAPABT(ABTOCOPY, ABT_NULL, M_ID, ret);                               \
                                        /* �ץ������ܡ���                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_CCOM													*/
/*																			*/
/* �㵡ǽ���ס�  �ΰ����Ӥ�Ԥ�            								*/
/* �㲾������																*/
/*	   P1		 �ΰ裱                  									*/
/*	   P2	     �ΰ裲                      								*/
/*	   LEN	     �ΰ���礭��        										*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_CCOM(P1, P2, LEN, RTN)                                            \
{                                                                             \
    RTN = mc_ccom((char *)P1, (char *)P2, (long)LEN);                         \
                                        /* �ΰ����                         */\
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_RENQ													*/
/*																			*/
/* �㵡ǽ���ס�  �񸻤���ͭ��Ԥ�            								*/
/* �㲾������																*/
/*	   P1		 ���ֹ�                  									*/
/*	   P2	                                								*/
/*	   P3	                        										*/
/*	   P4	             	             									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_RENQ(P1, P2, P3, P4, M_ID)                                        \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mf_renq((long *)P1, (char *)P2, (long)P3, (char)P4);                \
	                                    /* �񸻤���ͭ                       */\
    if( ret != MFNORMAL )               /* ����˻���ͭ����ʤ��ä���     */\
    {                                                                         \
        MIAPABT(ABTORENQ, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_RDEQ													*/
/*																			*/
/* �㵡ǽ���ס�  �񸻤���ͭ�����Ԥ�         								*/
/* �㲾������																*/
/*	   P1		 ���ֹ�                  									*/
/*	   P2	                                								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_RDEQ(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mf_rdeq((long *)P1, (long)P2);                                      \
										/* �񸻤���ͭ���                   */\
    if( ret != MFNORMAL )               /* ����˻���ͭ�������ʤ��ä��� */\
    {                                                                         \
        MIAPABT(ABTORDEQ, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_NCLR													*/
/*																			*/
/* �㵡ǽ���ס�  �ΰ��NULL���؎���Ԥ�         								*/
/* �㲾������																*/
/*	   P1		 �ΰ莱�Ďގڎ�                									*/
/*	   P2	     �ΰ莻������                     								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_NCLR(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mc_nclr((char *)P1, (long)P2);                                      \
										/* �ΰ�ǎَ��؎�                        */\
    if( ret != MINORMAL )               /* ����ˎ��؎�����ʤ��ä���          */\
    {                                                                         \
        MIAPABT(ABTONCLR, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_CBCN													*/
/*																			*/
/* �㵡ǽ���ס�  �����׎����Îގ�����ʎގ��Ŏ��Ѵ�����     								*/
/* �㲾������																*/
/*	   P1		 �����׎����Îގ����Ύߎ��ݎ�           									*/
/*	   P2	     �ʎގ��Ŏ؎Îގ����ֵюΎߎ��ݎ�         								*/
/*	   P3	     �����׎������Îގ����ʎގ��Ŀ�            								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_CBCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mc_cbcn((char *)P1, (long *)P2, (long)P3);                          \
										/* �����׎���/�ʎގ��Ŏ��Ѵ�                  */\
    if( ret != MCNMAL )                 /* ������Ѵ�����ʤ��ä���         */\
    {                                                                         \
        MIAPABT(ABTOCBCN, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_BCCN													*/
/*																			*/
/* �㵡ǽ���ס�  �ʎގ��Ŏ؎Îގ����򎷎��׎����Ѵ�����     								*/
/* �㲾������																*/
/*	   P1		 �ʎގ��Ŏ؎Îގ���                									*/
/*	   P2	     �����׎����Îގ����ֵюΎߎ��ݎ�         								*/
/*	   P3	     �����׎������Îގ����ֵюʎގ��Ŀ�         								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_BCCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    long    i;                          /* �����ݎ�                       stPD02*/\
    ret = mc_bccn((long)(P1), (char *)(P2), (long)(P3));                      \
										/* �ʎގ��Ŏ�/�����׎����Ѵ�                  */\
    if( ret != MCNMAL )                 /* ������Ѵ�����ʤ��ä���         */\
    {                                                                         \
        MIAPABT(ABTOBCCN, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
    for( i = 0; i < (long)(P3); i++ )   /* �Ѵ��Х��ȿ�ʬ�����å�����       */\
    {                                                                         \
        if( ((char *)(P2))[i] == ' ' )  /* �̎ގ׎ݎ��ξ��                      */\
		{                                                                     \
			((char *)(P2))[i] = '0';    /* ʸ���Σ������ꤹ��         edPD02*/\
		}                                                                     \
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_HCCN													*/
/*																			*/
/* �㵡ǽ���ס�  �͎����Îގ����򎷎��׎����Ѵ�����     								*/
/* �㲾������																*/
/*	   P1		 �͎����Îގ����Ύߎ��ݎ�            									*/
/*	   P2	     �����׎����Îގ����ֵюΎߎ��ݎ�         								*/
/*	   P3	     �����׎������Îގ����ֵюʎގ��Ŀ�         								*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_HCCN(P1, P2, P3, M_ID)                                            \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    ret = mc_hccn((char *)P1, (char *)P2, (long)P3);                          \
	                                    /* �͎���/�����׎����Ѵ�                    */\
    if( ret != MCNMAL )                 /* ������Ѵ�����ʤ��ä���         */\
    {                                                                         \
        MIAPABT(ABTOHCCN, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_SETN													*/
/*																			*/
/* �㵡ǽ���ס�  �̎ߎێ����Ƶ�ư���Ύ��Ύގ��Ĥ����������Ͽ���롣                   */
/* �㲾������																*/
/*	   P1		 ������̎ߎێ���̾            						      stPD0A*/
/*	   P2		 ������϶�ʬ            									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_SETN(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    long    mbid;                       /* �Ҏ��َΎގ�����ID                       */\
    MIA_MBID(P1, mbid, M_ID);           /* �Ҏ��َΎގ�����ID����                   */\
    ret = mc_setn(mbid, (char)P2, 0x67ff, ZERO, ZERO, ZERO);                  \
	                                    /* ���Ύގ�����������Ͽ                  */\
    if( ret != MCNORMAL )               /* �������Ͽ����ʤ��ä���         */\
    {                                                                         \
        MIAPABT(ABTOSETN, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_DELN													*/
/*																			*/
/* �㵡ǽ���ס�  ��Ͽ�ѤߤΎ��Ύގ������Τ��椫�顢���Ύގ�����������Ͽ�����ä��ޤ��� */
/* �㲾������																*/
/*	   P1		 ������̎ߎێ���̾            									*/
/*	   P2		 ������϶�ʬ            									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_DELN(P1, P2, M_ID)                                                \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    long    mbid;                       /* �Ҏ��َΎގ�����ID                       */\
    MIA_MBID(P1, mbid, M_ID);           /* �Ҏ��َΎގ�����ID����                   */\
    ret = mc_deln(mbid, (char)P2, 0x67ff, ZERO, ZERO, ZERO);                  \
	                                    /* ���Ύގ�������������            edPD0A*/\
    if( ret != MCNORMAL )               /* ��������ý���ʤ��ä���         */\
    {                                                                         \
        MIAPABT(ABTODELN, ABT_NULL, M_ID, ret);                               \
                                        /* �̎ߎێ������Ύގ���                       */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_NTAB													*/
/*																			*/
/* �㵡ǽ���ס�  mc_ntab�ˤ����Ͽ���줿���Ύގ�����������Ф��Ǝ��Ύގ������Τ�Ԥʤ�*/
/* �㲾������																*/
/*	   �ʤ�                                                                 */
/****************************************************************************/
#define MIA_NTAB                                                              \
{                                                                             \
    long    ret;                        /* �ֵ���                           */\
    long    ntip[5];                    /* ��Ͽ�������ֵ��ΰ�               */\
    for(;;)                                                                   \
    {                                                                         \
        ret = mc_ntab(ntip);            /* ���Ύގ�������                        */\
        if( ret != MCNORMAL )           /* ���ν�λ�ξ��                   */\
        {                                                                     \
            break;                      /* �َ��̎ߤ�ȴ����                     */\
        }                                                                     \
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  PRMERR          											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ�Ύʎߎ׎Ҏ������׎����α���������Ԥ���     				*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   USRP		 mia��ʸ���Ѽ԰�Ύߎ��ݎ�    									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define PRMERR(IRBP, USRP, M_ID)                                              \
{                                                                             \
    if( ((MIUSR *)USRP)->miifcd == IFCOMD )                                   \
    {                                   /* ���ݎ����̎����������Ďގ��ώݎĎޤξ��          */\
        (void)mcs_za00(MSG_20, ((MIIRB *)IRBP)->rd);                          \
                                        /* ���͎ߎڎ������ν���(SI20)             */\
        MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                         \
                                        /* ��λ���ν���                 PD01*/\
        MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,                \
                 ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);         \
                                        /* ���Ύގ�������������              PD0A*/\
    }                                                                         \
    else                                /* ���ݎ����̎����������Ď޻����ξ��         */\
    {                                                                         \
        mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,              \
                 PST_200, M_ID);        /* �����������ν���(200)          */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_LINECHK     											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ�β����ֹ�Ύ���������Ԥ���							*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_LINECHK(IRBP, M_ID)                                               \
{                                                                             \
    long     puno;                      /* �У��ֹ�                         */\
    long     chno;                      /* �����Ȏ��ֹ�                         */\
    MIUSR    *usrp;                     /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�             */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�����         */\
    if( MCNMAL != mc_cbcn(usrp->milineno, (long *)&puno, 1) )                 \
    {                                   /* ������Ѵ�����ʤ��ä���         */\
		PRMERR(IRBP, usrp, M_ID);       /* �ʎߎ׎Ҏ������׎�����                    */\
		return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
    if( MCNMAL != mc_cbcn(&(usrp->milineno[1]), (long *)&chno, 2) )           \
    {                                   /* ������Ѵ�����ʤ��ä���         */\
		PRMERR(IRBP, usrp, M_ID);       /* �ʎߎ׎Ҏ������׎�����                    */\
		return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
	if( !(((puno >= 0) && (puno <= 7)) && ((chno >= 0) && (chno <= 99))) )    \
	{                                                                         \
		PRMERR(IRBP, usrp, M_ID);       /* �ʎߎ׎Ҏ������׎�����                    */\
		return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
    ((MIIRB *)IRBP)->faceno = mia20003((short)puno, (short)chno);             \
                                        /* TFAC��������������               */\
    if( ((MIIRB *)IRBP)->faceno == MINOSING )                                 \
    {                                   /* TFAC�������˳�����������ֹ椬   */\
                                        /* �ʤ��ä����                     */\
        if( usrp->miifcd == IFCOMD )    /* ���ݎ����̎����������Ďގ��ώݎĎޤξ��          */\
        {                                                                     \
            (void)mcs_za00(MSG_04, ((MIIRB *)IRBP)->rd, puno, chno);          \
                                        /* ���͎ߎڎ������ν���(SI04)             */\
            MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                     \
									    /* ��λ���ν���                 PD01*/\
            MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,            \
                     ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);     \
                                        /* ���Ύގ�������������              PD0A*/\
        }                                                                     \
        else                            /* ���ݎ����̎����������Ď޻����ξ��         */\
        {                                                                     \
            mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,          \
                      PST_120, M_ID);   /* �����������ν���(120)          */\
        }                                                                     \
        return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_KASYCHK     											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ�����֤��ս�Ύ���������Ԥ���							*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_KASYCHK(IRBP, M_ID)                                               \
{                                                                             \
    MIUSR    *usrp;                     /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�             */\
    TFACPSZ  *fackop;                   /* TFAC������Ύߎ��ݎ�                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�����         */\
    KOADDR(TFAC_NO, ((MIIRB *)IRBP)->faceno, fackop);                         \
                                        /* TFAC�����􎴎ݎĎ؎��Ďގڎ������stPD0G*/\
    switch( (unsigned char)fackop->tfacprtc )                                 \
    {                                   /* �������̤ˤ�����֤��ս�������� */\
                                        /* �������������                       */\
        case PRTC4W :                   /* 4W�ξ��                         */\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)) )                              \
            {                           /* ���֤��ս꤬�Ɏ����Ȏٳ����֤��ɡ�   */\
                                        /* �Ɏ����Ȏ������֤��ɰʳ��ξ��       */\
                PRMERR(IRBP, usrp, M_ID);                                     \
                                        /* �ʎߎ׎Ҏ������׎�����                    */\
                return(MIERR);          /* �����۾ｪλ                     */\
            }                                                                 \
            break;                                                            \
        case PRTCLOOP :                 /* HDLC�َ��̎ߤξ��              edM01*/\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)                                 \
               || (usrp->mitpoint == KASYO_3)) )                              \
            {                           /* ���֤��ս꤬�Ɏ����Ȏٳ����֤��ɡ�   */\
                                        /* �Ɏ����Ȏ������֤��ɡ��Ɏ����Ȏ����̿�LSI*/\
                                        /* �����֤��ɰʳ��ξ��             */\
                PRMERR(IRBP, usrp, M_ID);                                     \
                                        /* �ʎߎ׎Ҏ������׎�����                    */\
                return(MIERR);          /* �����۾ｪλ                     */\
            }                                                                 \
            break;                                                            \
        case PRTCTCP :                  /* LAN�ξ��                        */\
            if( !((usrp->mitpoint == KASYO_0)                                 \
               || (usrp->mitpoint == KASYO_1)                                 \
               || (usrp->mitpoint == KASYO_3)) )                              \
            {                           /* ���֤��ս꤬��i82596����َ��̎ߡɡ� */\
                                        /* ��PLS�َ��̎ߡɡ��ɎĎ׎ݎ����ʎގَ��̎ߡ�     */\
                                        /* �ʳ��ξ��                       */\
                (void)mcs_za00(MSG_20, ((MIIRB *)IRBP)->rd);                  \
                                        /* ���͎ߎڎ������ν���(SI20)             */\
                MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                 \
                                        /* ��λ���ν���                 PD01*/\
                MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,        \
                         ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID); \
                                        /* ���Ύގ�������������              PD0A*/\
                return(MIERR);          /* �����۾ｪλ                     */\
            }                                                                 \
            break;                      /*                            edPD0G*/\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_TELCHK����    											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ�������ֹ�Ύ���������Ԥ���							*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_TELCHK(IRBP, M_ID)                                                \
{                                                                             \
    MIUSR    *usrp;                     /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�             */\
    TFACPSZ  *fackop;                   /* TFAC������Ύߎ��ݎ�                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�����         */\
    KOADDR(TFAC_NO, ((MIIRB *)IRBP)->faceno, fackop);                         \
                                        /* TFAC�����􎴎ݎĎ؎��Ďގڎ������      */\
    if( !((usrp->miketa == 0) || (usrp->miketa == 0x20)) )                    \
	{                                   /* �����ֹ��������ʳ��ξ��       */\
        if( (usrp->miketa < 4) || (usrp->miketa > 20) )                       \
        {                               /* �����ֹ��������ʾ売���ʲ���   */\
                                        /* �ϰϰʳ��ξ��                   */\
            PRMERR(IRBP, usrp, M_ID);   /* �ʎߎ׎Ҏ������׎�����                    */\
            return(MIERR);              /* �����۾ｪλ                     */\
        }                                                                     \
    }                                                                         \
    if( mia20005(usrp->mibuteln, usrp->miketa) != MINORMAL )                  \
	{                                   /* �����ֹ�Ǝ����Ҏ؎���������������          */\
                                        /* �����ֹ�۾�ξ��               */\
        PRMERR(IRBP, usrp, M_ID);       /* �ʎߎ׎Ҏ������׎�����                    */\
        return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_WORDCHK����   											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ�Ύʎߎ��܎��ĎޤΎ���������Ԥ���							*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   WORD		 WORD�Ύߎ��ݎ�                									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_WORDCHK(IRBP, WORD, M_ID)                                         \
{                                                                             \
    TFACSUB  *facsbp;                   /* TFAC���̎޶�����Ύߎ��ݎ�               */\
    MIKYO    *usrp;                     /* mia�Ύߎ��ݎ�                         */\
    long      rtn;                      /* �ֵ���                           */\
                                                                              \
    usrp = (MIKYO *)((MIIRB *)IRBP)->msgp;                                    \
										/* �Ύߎ��ݎ�����                        */\
    SUBADDR(TFAC_NO, facsbp);           /* TFAC���̎޶�����Ύߎ��ݎ�����           */\
    MIA_CCOM(facsbp->tfacword, (char *)WORD, 4, rtn);                         \
                                        /* �ʎߎ��܎��Ďޤ�TFAC�Ύʎߎ��܎��Ďޤ����     */\
    if( rtn != MINORMAL )               /* �԰��פξ��                     */\
    {                                                                         \
        if( (unsigned char)usrp->miifcd == IFCOMD )                           \
		{                               /* ���ݎ����̎����������Ďގ��ώݎĎޤξ��          */\
            (void)mcs_za00(MSG_34, ((MIIRB *)IRBP)->rd);                      \
                                        /* ���͎ߎڎ������ν���(SI34)             */\
            MIA_IEND(((MIIRB *)IRBP)->rd, SHORING, M_ID);                     \
									    /* ��λ���ν���                 PD01*/\
            MIA_DELN(((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnpn,            \
                     ((MCMIKYO *)((MIIRB *)IRBP)->msgp)->mcmisnkb, M_ID);     \
                                        /* ���Ύގ�������������              PD0A*/\
        }                                                                     \
        else                            /* ���ݎ����̎����������Ď޻����ξ��         */\
        {                                                                     \
            mia20002(((MIIRB *)IRBP)->msgp, ((MIIRB *)IRBP)->msglen,          \
                      PST_800, M_ID);   /* �����������ν���(800)          */\
        }                                                                     \
        return(MIERR);                  /* �����۾ｪλ                     */\
    }                                                                         \
}
/*********************************************************************stPD0A*/
/*																			*/
/* ��ޥ���̾��  MIA_DOWN   ����   											*/
/*																			*/
/* �㵡ǽ���ס�  �����Îѹ������Ύ��Ď����ݎʎގ����֤��������������ގ����פξ�玼���Îю��ގ���    */
/*               ��Ԥʤ�                                                   */
/* �㲾������																*/
/*	   P1  		 �ԣƣ��ø������ݥ���   									*/
/*	   P2  	     �ܺپ���                                                   */ 
/****************************************************************************/
#define MIA_DOWN(P1, P2)                                                      \
{                                                                             \
    extern  void  mr_sdwn(long, short, long);                                 \
                                        /* �����Îю��ގ��ݽ���                     */\
    TSSTPSZ   *sstkop;                  /* TSST�����􎴎ݎĎ؎��Ďގڎ�              */\
    KOADDR(TSST_NO, 1, sstkop);         /* TSST�����􎴎ݎĎ؎��Ďގڎ������      */\
    if( ((unsigned char)((TFACPSZ *)P1)->tfacdown == DOWNON)                  \
     && ((unsigned char)sstkop->tsstsysc == SYSCHOT) )                        \
    {                                   /* �������������ގ����פ�               */\
                                        /* �����Îѹ������Ύ��Ď����ݎʎގ��ξ��        */\
        mr_sdwn((long)MRDOWN, 0x67ff, (long)P2);                              \
                                        /* �����Îю��ގ��ݽ���ȯ��                 */\
    }                                                                         \
}
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIA_SUBADDR����   											*/
/*																			*/
/* �㵡ǽ���ס�  �׵���ʸ���去�̎ގ��Ďގڎ��Ύ���������Ԥ���							*/
/* �㲾������																*/
/*	   IRBP		 IRB�Ύߎ��ݎ�                  									*/
/*	   M_ID	     ȯ�Ը��ӎ��ގ�����ID      										*/
/****************************************************************************/
#define MIA_SUBADDR(IRBP, M_ID)                                               \
{                                                                             \
    MIUSR    *usrp;                     /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�             */\
    TFACPSZ  *fackop;                   /* TFAC������Ύߎ��ݎ�                  */\
                                                                              \
    usrp = (MIUSR *)(((MIIRB *)IRBP)->msgp + sizeof(MCMIKYO));                \
                                        /* MIA��ʸ���Ѽ԰�Ύߎ��ݎ�����         */\
    if( usrp->misadsz > SUBADDR_MAX )   /* �去�̎ގ��Ďގڎ����ϰϳ��ξ��         */\
    {                                                                         \
        PRMERR(IRBP, usrp, M_ID);       /* �ʎߎ׎Ҏ������׎�����                    */\
        return(MIERR);                  /* �����۾ｪλ               edPD0A*/\
    }                                                                         \
}
/*********************************************************************stPD0E*/
/*																	  stPD0O*/
/* ��ޥ���̾��  MIA_LICP����   											*/
/*																			*/
/* �㵡ǽ���ס�  �������ظ��LICP�ε�ư��Ԥ�  ��							*/
/* �㲾������																*/
/*	   P1		 ������TFAC�Ύߎ��ݎ�           									*/
/*	   P2		 ���ظ�TFAC�Ύߎ��ݎ�           									*/
/*	   P3		 ���ݎÎ����ĎΎߎ��ݎ�              									*/
/*	   P4		 �ֵ���                  									*/
/****************************************************************************/
#define MIA_LICP(P1, P2, P3, P4)                                              \
{                                                                             \
    extern  long  mia12300(long, TCSTPSZ *, TCOMPAT *, TCOMPAT *,             \
                           TCOMPAT *,  TCOMPAT *, MILCTX *);                  \
                                        /* LICP��ư����                     */\
    extern  long  mia12310(long, long, TCSTPSZ *, TCOMPAT *, TCOMPAT *,       \
                           TCOMPAT *,  TCOMPAT *, MILCTX *);                  \
                                        /* ���ظ�LICP��ư����               */\
    TCSTPSZ *cstkop;                    /* TCST�����􎴎ݎĎ؎��Ďގڎ�              */\
    TCOMPAT *faccmp;                    /* TFAC�����􎴎ݎĎ؎��Ďގڎ�              */\
    TCOMPAT *fapcmp;                    /* TFAP�����􎴎ݎĎ؎��Ďގڎ�              */\
    TCOMPAT *faxcmp;                    /* TFAX�����􎴎ݎĎ؎��Ďގڎ�              */\
    TCOMPAT *falcmp;                    /* TFAL�����􎴎ݎĎ؎��Ďގڎ�              */\
                                                                              \
    KOADDR(TCST_NO, 1, cstkop);         /* TCST�����􎴎ݎĎ؎��Ďގڎ������      */\
    COMADDR(TFAC_NO, faccmp);           /* TFAC�����􎴎ݎĎ؎��Ďގڎ������      */\
    COMADDR(TFAP_NO, fapcmp);           /* TFAP�����􎴎ݎĎ؎��Ďގڎ������      */\
    COMADDR(TFAX_NO, faxcmp);           /* TFAX�����􎴎ݎĎ؎��Ďގڎ������      */\
    COMADDR(TFAL_NO, falcmp);           /* TFAL�����􎴎ݎĎ؎��Ďގڎ������      */\
    if( P2 == ZERO )                    /* ���ظ�ε�ư�ʳ��λ�             */\
    {                                                                         \
	    P4 = mia12300((long)P1, cstkop, faccmp, fapcmp, faxcmp, falcmp,       \
                       (MILCTX *)P3);   /* LICP��ư����                     */\
    }                                                                         \
    else                                /* ���ظ�ε�ư��                   */\
    {                                                                         \
	    P4 = mia12310((long)P1, (long)P2, cstkop, faccmp, fapcmp, faxcmp,     \
                       falcmp, (MILCTX *)P3);                                 \
                                        /* ���ظ�LICP��ư����         edPD0E*/\
    }                                   /*                            edPD0O*/\
}
