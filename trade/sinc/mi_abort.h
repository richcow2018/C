/****************************************************************************/
/* �̎�����̾������mi_abort.h                                                   */
/* ��ǽ������  ���Ύގ��ľܺپ����1�ʎގ���                                         */
/*             �̎ߎێ������Ύގ��Ďώ���                                                */
/*             �ӎ��ގ�����ID�ʳ�ĥ��                                             */
/* ����������  1992.01.07                                                   */
/* �ѹ�������  1994.10.14                                               PD0A*/
/*   �ξ����ɼ(ST1761) ����ɡ����б�                                      */
/* �ѹ�������  1995.03.31                                               PD0B*/
/*   �ξ����ɼ(ST2144) ISDN�����ǻ���������ȯ��                            */
/* �ѹ���������  1995.06.13                                             PD0C*/
/*   �����ѹ��׵��(SSCY0062) ưŪ�����ƥ��ѹ��б�                          */
/* �ѹ���������  1995.09.29                                             PD01*/
/*   �ξ����ɼ(ST3504) �㳲�������Ф��Ǝ؎Ď׎���Ԥ��褦����                  */
/* �ѹ���������  1995.09.29                                             PD0J*/
/*   �����ѹ��׵��(SSCY0113) ���׸ξ㸡���ѹ��б�                          */
/* �ѹ�����  ��  1995.10.13                                             PD02*/
/*   �ξ����ɼ(ST3572) �㳲���л����ێ������Ԥ��ɲ�                             */
/* �ѹ���������  1995.11.29                                             PD0O*/
/*   �����ѹ��׵��(SSCY0063) �̣ɣãкƵ�ư�б�                            */
/* �ѹ���������  1995.02.01                                              M01*/
/*   �����ѹ��׵��(ST3978  ) ���ܡ��ȥ���������ߥ�                        */
/* �ѹ���������  1996.03.05                                             PD0R*/ 
/*   �����ѹ��׵��(SSCY0156) X.25�����ƻ��ѹ��б�                          */ 
/* �ѹ���������  1997.02.27                                             PD0W*/ 
/*   �ξ����ɼ(ST4648) mia12120()�ɲ�                                      */
/* �ѹ���������  1997.03.17                                             PD0Y*/ 
/*   �ξ����ɼ(ST4810) miae0000()�ɲ�                                      */
/* �ѹ���������  1997.05.12                                             PD0Z*/ 
/*   �ξ����ɼ(ST4834) mia25000(),mia25001(),mia25002()�ɲ�                */
/* �ѹ���������  1998.02.16                                         SSCY0203*/ 
/*   �����ѹ��׵��(SSCY0203) �����ξ�£������κƻ���					*/
/* �ѹ���������  1998.03.16                                           ST5113*/ 
/*   �ξ����ɼ(ST5113) mia00013()�ɲ�                                      */
/****************************************************************************/
/* �㥽���������ԡ�                  �Ķ�Ź�����ƥ�ô��������(KSP)          */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������         ST6007  */
/*   ���ܡ��ȥ����ɤ��������Խ�������ͥޥ���MIAPABT��������				*/
/*--------------------------------------------------------------------------*/
/**************************************/
/* ���Ύގ��ľܺپ����1�ʎގ���               */
/**************************************/
/********************/
/* SG������         */
/********************/
#define ABTINVSG    0x01                /* SG������                         */

/**************************************/
/* �������顼                         */
/**************************************/
#define ABTLMTX     0x05                /* �ޥȥꥯ��̷��                   */
#define ABTCONN     0x10                /* osconn                           */
#define ABTDCONN    0x11                /* osdconn                          */
#define ABTLOPEN    0x12                /* osiopen                          */
#define ABTLCLOS    0x13                /* osiclose                         */
#define ABTGFINF    0x14                /* osgfinf                          */
#define ABTCONFI    0x15                /* osconfig                         */
#define ABTSENMS    0x16                /* ossenmsp                         */
#define ABTDELET    0x17                /* osdelet                          */
#define ABTMKNOD    0x18                /* osmknod                          */
#define ABTLTEST    0x20                /* ���������׵�                     */
#define ABTTMRST    0x21                /* ���ֲ���׵�                     */
#define ABTCHAKU    0x22                /* ����׵�                         */
#define ABTHAKKO    0x23                /* ȯ���׵�                         */
#define ABTASYNC    0x24                /* ��Ʊ�������׵�                   */
#define ABTDATAS    0x25                /* ���ֻ�Îގ��������׵�             */
#define ABTGTIOS    0x26                /* osgetios                         */
#define ABTLDCON    0x27                /* �����׵�                     PD0A*/
#define ABTDESPR    0x28                /* �ץ�����λ                 PD0O*/
#define ABTDLSET    0x29                /* �Îގ����؎ݎ�������                PD0R*/
/**************************************/
/* �ϡ��ɥ��顼(���ގ��ݎ����Ď޾ܺپ���)     */
/**************************************/
#define DOWNSYNC1   0x31000000          /* ��Ʊ�������׵�(4W)           PD0A*/
#define DOWNSYNC2   0x32000000          /* ��Ʊ�������׵�(HDLC LOOP)    PD0A*/
#define DOWNSYNC3   0x33000000          /* ��Ʊ�������׵�(TEL)          PD0A*/
#define DOWNSYNC4   0x34000000          /* ��Ʊ�������׵�(Bu)           PD0A*/
#define DOWNSYNC5   0x35000000          /* ��Ʊ�������׵�(LAN)          PD0A*/
#define DOWNSYNC6   0x36000000          /* ��Ʊ�������׵�(X.25)         PD0A*/
#define DOWNOPEN1   0x41000000          /* osiopen(4W)                  PD0A*/
#define DOWNOPEN2   0x42000000          /* osiopen(HDLC LOOP)           PD0A*/
#define DOWNOPEN3   0x43000000          /* osiopen(LAN)                 PD0A*/
#define DOWNOPEN4   0x44000000          /* osiopen(X.25)                PD0A*/
#define DOWNOPEN5   0x45000000          /* osiopen(X.25H)               PD0A*/
#define DOWNOPEN6   0x46000000          /* osiopen(TELH)                PD0A*/
/**************************************/
/* ����¾�Υ��顼                     */
/**************************************/
#define ABTOGTBF    0xE0                /* �����ӥ�������۾�(mo_gtbf)��    */
#define ABTONCLR    0xE1                /* �����ӥ�������۾�(mc_nclr)��    */
#define ABTOFRBF    0xE2                /* �����ӥ�������۾�(mo_frbf)��    */
#define ABTORTGT    0xE3                /* �����ӥ�������۾�(mf_rtgt)��    */
#define ABTORENQ    0xE4                /* �����ӥ�������۾�(mf_renq)��    */
#define ABTORDEQ    0xE5                /* �����ӥ�������۾�(mf_rdeq)��    */
#define ABTOBCCN    0xE6                /* �����ӥ�������۾�(mc_bccn)��    */
#define ABTOHCCN    0xE7                /* �����ӥ�������۾�(mc_hccn)��    */
#define ABTOIENT    0xE8                /* �����ӥ�������۾�(ms_ient)��    */
#define ABTOIRES    0xE9                /* �����ӥ�������۾�(ms_ires)��    */
#define ABTOIEND    0xEa                /* �����ӥ�������۾�(ms_iend)��    */
#define ABTOUWTO    0xEb                /* �����ӥ�������۾�(ms_uwto)      */
#define ABTOCOPY    0xEc                /* �����ӥ�������۾�(mc_copy)      */
#define ABTOCCOM    0xEd                /* �����ӥ�������۾�(mc_ccom)      */
#define ABTOMBID    0xEe                /* �����ӥ�������۾�(mi_mbid)      */
#define ABTOCBCN    0xF0                /* �����ӥ�������۾�(mc_cbcn)      */
#define ABTOSETN    0xF1                /* �����ӥ�������۾�(mc_setn)      */
#define ABTODELN    0xF2                /* �����ӥ�������۾�(mc_deln)      */
#define ABTONTAB    0xF3                /* �����ӥ�������۾�(mc_ntab)      */
#define ABTOCONN    0xF4                /* �����ӥ�������۾�(mc_conn)      */
/********************/
/* �̎ߎێ��ގ׎ю��׎�       */
/********************/
#define ABTPGMER    0x60                /* �̎ߎێ��ގ׎ю��׎�                       */

/********************/
/* ���͎ގݎİ۾�        */
/********************/
#define ABTINVEV    0x70                /* ���͎ގݎİ۾�                        */

/**************************************/
/* �⥸�塼��ɣ�                     */
/**************************************/
#define MID_EX       0x67ff0000         /* mia�ӎ��ގ�����ID                      */

#define STATEVNT(P1, P2)    ((long)P1<<8)|(long)P2
#define ABT_NULL     0x0                
/****************************************************************************/
/*																			*/
/* ��ޥ���̾��  MIAPABT													*/
/*																			*/
/* �㵡ǽ���ס�  ���ܡ��Ƚ�����Ԥ�											*/
/*																			*/
/* �㲾������																*/
/*	   P1	     �ܺپ���													*/
/*	   P2	     Ǥ���ͣ� 													*/
/*	   P3	     �⥸�塼��ɣġʳ�ĥ�⥸�塼��ɣĤβ������				*/
/*	   P4	     Ǥ���ͣ� 													*/
/****************************************************************************/
#define MIAPABT(P1, P2, P3, P4) 		/* ���ܡ��Ƚ��� 					*/\
{                                                                             \
	extern   long   mc_lsch(long);                                            \
	(void)mc_lsch(0);                                                         \
	MCS_ABEX((MID_EX | ((unsigned long)(P3) & 0x0000ffff)), P1, P2, P4);	  \
	/* M01 ST6007 */														  \
}
										/* �ץ������ܡ��ȥޥ���			*/
/**************************************/
/* �⥸�塼��ɣġʳ�ĥ��             */
/**************************************/
#define   MIA00001  0x0000              /* mia00001() �Ύӎ��ގ�����ID            */
#define   MIA00002  0x0001              /* mia00002() �Ύӎ��ގ�����ID            */
#define   MIA00003  0x0002              /* mia00003() �Ύӎ��ގ�����ID            */
#define   MIA00004  0x0003              /* mia00004() �Ύӎ��ގ�����ID            */
#define   MIA00005  0x0004              /* mia00005() �Ύӎ��ގ�����ID            */
#define   MIA00006  0x0005              /* mia00006() �Ύӎ��ގ�����ID            */
#define   MIA00008  0x0007              /* mia00008() �Ύӎ��ގ�����ID            */
#define   MIA00009  0x000f              /* mia00009() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA00010  0x000e              /* mia00010() �Ύӎ��ގ�����ID            */
#define   MIA00011  0x0008              /* mia00011() �Ύӎ��ގ�����ID            */
#define   MIA00012  0x0009              /* mia00012() �Ύӎ��ގ�����ID            */
#define   MIA00013  0x001a              /* mia00013() �Ύӎ��ގ�����ID      ST5113*/
#define   MIA00016  0x000a              /* mia00016() �Ύӎ��ގ�����ID            */
#define   MIA00018  0x000b              /* mia00018() �Ύӎ��ގ�����ID            */
#define   MIA00019  0x000c              /* mia00019() �Ύӎ��ގ�����ID            */
#define   MIA00020  0x000d              /* mia00020() �Ύӎ��ގ�����ID            */
#define   MIA00021  0x0035              /* mia00021() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00022  0x0036              /* mia00022() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00023  0x0037              /* mia00023() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00024  0x0038              /* mia00024() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00025  0x0039              /* mia00025() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00027  0x003b              /* mia00027() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00028  0x003c              /* mia00028() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00029  0x003d              /* mia00029() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00030  0x0042              /* mia00030() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA00031  0x0043              /* mia00031() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA00040  0x004b              /* mia00040() �Ύӎ��ގ�����ID        PD01*/
#define   MIA00041  0x004c              /* mia00041() �Ύӎ��ގ�����ID        PD01*/
#define   MIA00042  0x004d              /* mia00042() �Ύӎ��ގ�����ID    SSCY0203*/
#define   MIA00050  0x0010              /* mia00050() �Ύӎ��ގ�����ID            */
#define   MIA00051  0x0011              /* mia00051() �Ύӎ��ގ�����ID            */
#define   MIA00052  0x0012              /* mia00052() �Ύӎ��ގ�����ID            */
#define   MIA00053  0x0013              /* mia00053() �Ύӎ��ގ�����ID            */
#define   MIA00054  0x0014              /* mia00054() �Ύӎ��ގ�����ID            */
#define   MIA00055  0x0015              /* mia00055() �Ύӎ��ގ�����ID            */
#define   MIA00056  0x0016              /* mia00056() �Ύӎ��ގ�����ID            */
#define   MIA00057  0x0017              /* mia00057() �Ύӎ��ގ�����ID            */
#define   MIA00058  0x0018              /* mia00058() �Ύӎ��ގ�����ID            */
#define   MIA00059  0x0019              /* mia00059() �Ύӎ��ގ�����ID            */
#define   MIA00060  0x0020              /* mia00060() �Ύӎ��ގ�����ID            */
#define   MIA00061  0x0021              /* mia00061() �Ύӎ��ގ�����ID            */
#define   MIA00062  0x0022              /* mia00062() �Ύӎ��ގ�����ID            */
#define   MIA00063  0x0023              /* mia00063() �Ύӎ��ގ�����ID            */
#define   MIA00064  0x0024              /* mia00064() �Ύӎ��ގ�����ID            */
#define   MIA00065  0x0025              /* mia00065() �Ύӎ��ގ�����ID            */
#define   MIA00066  0x003e              /* mia00066() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00067  0x003f              /* mia00067() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00068  0x0040              /* mia00068() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00069  0x0041              /* mia00069() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA00100  0x0026              /* mia00100() �Ύӎ��ގ�����ID            */
#define   MIA00101  0x0027              /* mia00101() �Ύӎ��ގ�����ID            */
#define   MIA00102  0x0028              /* mia00102() �Ύӎ��ގ�����ID            */
#define   MIA00103  0x0029              /* mia00103() �Ύӎ��ގ�����ID            */
#define   MIA00104  0x002a              /* mia00104() �Ύӎ��ގ�����ID            */
#define   MIA00105  0x002b              /* mia00105() �Ύӎ��ގ�����ID            */
#define   MIA00106  0x002c              /* mia00106() �Ύӎ��ގ�����ID            */
#define   MIA00107  0x002d              /* mia00107() �Ύӎ��ގ�����ID            */
#define   MIA00108  0x002e              /* mia00108() �Ύӎ��ގ�����ID            */
#define   MIA00109  0x002f              /* mia00109() �Ύӎ��ގ�����ID            */
#define   MIA00110  0x0034              /* mia00110() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA00150  0x0030              /* mia00150() �Ύӎ��ގ�����ID            */
#define   MIA00151  0x0031              /* mia00151() �Ύӎ��ގ�����ID            */
#define   MIA00152  0x0032              /* mia00152() �Ύӎ��ގ�����ID            */
#define   MIA00153  0x0033              /* mia00153() �Ύӎ��ގ�����ID            */
#define   MIA00200  0x0044              /* mia00200() �Ύӎ��ގ�����ID      stPD0C*/
#define   MIA00201  0x0045              /* mia00201() �Ύӎ��ގ�����ID            */
#define   MIA00202  0x0046              /* mia00202() �Ύӎ��ގ�����ID            */
#define   MIA00203  0x0047              /* mia00203() �Ύӎ��ގ�����ID            */
#define   MIA00204  0x0048              /* mia00204() �Ύӎ��ގ�����ID            */
#define   MIA00205  0x0049              /* mia00205() �Ύӎ��ގ�����ID            */
#define   MIA00206  0x004a              /* mia00206() �Ύӎ��ގ�����ID      edPD0C*/
#define   MIA11000  0x1000              /* mia11000() �Ύӎ��ގ�����ID            */
#define   MIA12000  0x1001              /* mia12000() �Ύӎ��ގ�����ID            */
#define   MIA12010  0x1002              /* mia12010() �Ύӎ��ގ�����ID            */
#define   MIA12100  0x1003              /* mia12100() �Ύӎ��ގ�����ID            */
#define   MIA12110  0x1004              /* mia12110() �Ύӎ��ގ�����ID            */
#define   MIA12200  0x1005              /* mia12200() �Ύӎ��ގ�����ID            */
#define   MIA12201  0x1008              /* mia12201() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA12120  0x1009              /* mia12120() �Ύӎ��ގ�����ID        PD0W*/
#define   MIA13000  0x1006              /* mia13000() �Ύӎ��ގ�����ID            */
#define   MIA14000  0x1007              /* mia14000() �Ύӎ��ގ�����ID            */
#define   MIA20000  0x2000              /* mia20000() �Ύӎ��ގ�����ID            */
#define   MIA20001  0x2001              /* mia20001() �Ύӎ��ގ�����ID            */
#define   MIA20002  0x2002              /* mia20002() �Ύӎ��ގ�����ID            */
#define   MIA20003  0x2003              /* mia20003() �Ύӎ��ގ�����ID            */
#define   MIA20004  0x2004              /* mia20004() �Ύӎ��ގ�����ID            */
#define   MIA20005  0x2005              /* mia20005() �Ύӎ��ގ�����ID            */
#define   MIA20006  0x2006              /* mia20006() �Ύӎ��ގ�����ID            */
#define   MIA20007  0x2007              /* mia20007() �Ύӎ��ގ�����ID            */
#define   MIA20010  0x2010              /* mia20010() �Ύӎ��ގ�����ID            */
#define   MIA20011  0x2011              /* mia20011() �Ύӎ��ގ�����ID            */
#define   MIA20012  0x2012              /* mia20012() �Ύӎ��ގ�����ID            */
#define   MIA20013  0x2030              /* mia20013() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA20020  0x2031              /* mia20020() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA20040  0x2038              /* mia20040() �Ύӎ��ގ�����ID        PD01*/
#define   MIA21000  0x2013              /* mia21000() �Ύӎ��ގ�����ID            */
#define   MIA21001  0x2014              /* mia21001() �Ύӎ��ގ�����ID            */
#define   MIA21002  0x2015              /* mia21002() �Ύӎ��ގ�����ID            */
#define   MIA21003  0x2016              /* mia21003() �Ύӎ��ގ�����ID            */
#define   MIA21004  0x2017              /* mia21004() �Ύӎ��ގ�����ID            */
#define   MIA21005  0x2018              /* mia21005() �Ύӎ��ގ�����ID            */
#define   MIA21006  0x2019              /* mia21006() �Ύӎ��ގ�����ID            */
#define   MIA21007  0x201a              /* mia21007() �Ύӎ��ގ�����ID            */
#define   MIA21008  0x201b              /* mia21008() �Ύӎ��ގ�����ID            */
#define   MIA21009  0x201c              /* mia21009() �Ύӎ��ގ�����ID            */
#define   MIA21010  0x201d              /* mia21010() �Ύӎ��ގ�����ID            */
#define   MIA21011  0x201e              /* mia21011() �Ύӎ��ގ�����ID            */
#define   MIA21012  0x201f              /* mia21012() �Ύӎ��ގ�����ID            */
#define   MIA22000  0x2020              /* mia22000() �Ύӎ��ގ�����ID            */
#define   MIA22001  0x2021              /* mia22001() �Ύӎ��ގ�����ID            */
#define   MIA22002  0x2022              /* mia22002() �Ύӎ��ގ�����ID            */
#define   MIA22003  0x2023              /* mia22003() �Ύӎ��ގ�����ID            */
#define   MIA22004  0x2024              /* mia22004() �Ύӎ��ގ�����ID            */
#define   MIA22005  0x2025              /* mia22005() �Ύӎ��ގ�����ID            */
#define   MIA22006  0x2026              /* mia22006() �Ύӎ��ގ�����ID            */
#define   MIA22007  0x2027              /* mia22007() �Ύӎ��ގ�����ID            */
#define   MIA22008  0x2028              /* mia22008() �Ύӎ��ގ�����ID            */
#define   MIA22009  0x2029              /* mia22009() �Ύӎ��ގ�����ID            */
#define   MIA22010  0x202a              /* mia22010() �Ύӎ��ގ�����ID            */
#define   MIA22011  0x202b              /* mia22011() �Ύӎ��ގ�����ID            */
#define   MIA22012  0x202c              /* mia22012() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA22013  0x202f              /* mia22013() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA23000  0x202d              /* mia23000() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA23001  0x202e              /* mia23001() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA24000  0x202f              /* mia24000() �Ύӎ��ގ�����ID      stPD0C*/
#define   MIA24001  0x2036              /* mia24001() �Ύӎ��ގ�����ID            */
#define   MIA24100  0x2037              /* mia24100() �Ύӎ��ގ�����ID            */
#define   MIA24101  0x2032              /* mia24101() �Ύӎ��ގ�����ID            */
#define   MIA24200  0x2033              /* mia24200() �Ύӎ��ގ�����ID            */
#define   MIA24201  0x2034              /* mia24201() �Ύӎ��ގ�����ID            */
#define   MIA24202  0x2035              /* mia24202() �Ύӎ��ގ�����ID      edPD0C*/
#define   MIA25000  0x2035              /* mia25000() �Ύӎ��ގ�����ID      stPD0Z*/
#define   MIA25001  0x2035              /* mia25001() �Ύӎ��ގ�����ID            */
#define   MIA25002  0x2035              /* mia25002() �Ύӎ��ގ�����ID      edPD0Z*/
#define   MIA30000  0x3000              /* mia30000() �Ύӎ��ގ�����ID            */
#define   MIA30001  0x3001              /* mia30001() �Ύӎ��ގ�����ID            */
#define   MIA30002  0x3002              /* mia30002() �Ύӎ��ގ�����ID            */
#define   MIA30003  0x3003              /* mia30003() �Ύӎ��ގ�����ID            */
#define   MIA30004  0x3004              /* mia30004() �Ύӎ��ގ�����ID            */
#define   MIA31000  0x3005              /* mia31000() �Ύӎ��ގ�����ID            */
#define   MIA32000  0x3006              /* mia32000() �Ύӎ��ގ�����ID            */
#define   MIA40000  0x4000              /* mia40000() �Ύӎ��ގ�����ID            */
#define   MIA40001  0x4001              /* mia40001() �Ύӎ��ގ�����ID            */
#define   MIA40005  0x4002              /* mia40005() �Ύӎ��ގ�����ID            */
#define   MIA40006  0x4003              /* mia40006() �Ύӎ��ގ�����ID            */
#define   MIA40007  0x4004              /* mia40007() �Ύӎ��ގ�����ID            */
#define   MIA40008  0x4005              /* mia40008() �Ύӎ��ގ�����ID            */
#define   MIA40009  0x406d              /* mia40009() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA40100  0x4071              /* mia40100() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA40105  0x4010              /* mia40105() �Ύӎ��ގ�����ID            */
#define   MIA40107  0x4011              /* mia40107() �Ύӎ��ގ�����ID            */
#define   MIA40108  0x4012              /* mia40108() �Ύӎ��ގ�����ID            */
#define   MIA40109  0x4013              /* mia40109() �Ύӎ��ގ�����ID            */
#define   MIA40152  0x4014              /* mia40152() �Ύӎ��ގ�����ID            */
#define   MIA40200  0x4072              /* mia40200() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA40205  0x4015              /* mia40205() �Ύӎ��ގ�����ID            */
#define   MIA40207  0x4016              /* mia40207() �Ύӎ��ގ�����ID            */
#define   MIA40208  0x4017              /* mia40208() �Ύӎ��ގ�����ID            */
#define   MIA40209  0x4018              /* mia40209() �Ύӎ��ގ�����ID            */
#define   MIA40252  0x4019              /* mia40252() �Ύӎ��ގ�����ID            */
#define   MIA40300  0x4073              /* mia40300() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA40305  0x401a              /* mia40305() �Ύӎ��ގ�����ID            */
#define   MIA40307  0x401b              /* mia40307() �Ύӎ��ގ�����ID            */
#define   MIA40308  0x401c              /* mia40308() �Ύӎ��ގ�����ID            */
#define   MIA40309  0x401d              /* mia40309() �Ύӎ��ގ�����ID            */
#define   MIA40352  0x401e              /* mia40352() �Ύӎ��ގ�����ID            */
#define   MIA40400  0x4074              /* mia40400() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA40405  0x401f              /* mia40405() �Ύӎ��ގ�����ID            */
#define   MIA40407  0x4020              /* mia40407() �Ύӎ��ގ�����ID            */
#define   MIA40408  0x4021              /* mia40408() �Ύӎ��ގ�����ID            */
#define   MIA40409  0x4022              /* mia40409() �Ύӎ��ގ�����ID            */
#define   MIA40452  0x4023              /* mia40452() �Ύӎ��ގ�����ID            */
#define   MIA40500  0x4075              /* mia40500() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA40501  0x4024              /* mia40501() �Ύӎ��ގ�����ID            */
#define   MIA40502  0x4025              /* mia40502() �Ύӎ��ގ�����ID            */
#define   MIA40505  0x4026              /* mia40505() �Ύӎ��ގ�����ID            */
#define   MIA40507  0x4027              /* mia40507() �Ύӎ��ގ�����ID            */
#define   MIA40508  0x4028              /* mia40508() �Ύӎ��ގ�����ID            */
#define   MIA40509  0x4029              /* mia40509() �Ύӎ��ގ�����ID            */
#define   MIA40552  0x402a              /* mia40552() �Ύӎ��ގ�����ID            */
#define   MIA40624  0x402b              /* mia40624() �Ύӎ��ގ�����ID            */
#define   MIA40628  0x402c              /* mia40628() �Ύӎ��ގ�����ID            */
#define   MIA40722  0x402d              /* mia40722() �Ύӎ��ގ�����ID            */
#define   MIA40723  0x402e              /* mia40723() �Ύӎ��ގ�����ID            */
#define   MIA40724  0x402f              /* mia40724() �Ύӎ��ގ�����ID            */
#define   MIA40728  0x4030              /* mia40728() �Ύӎ��ގ�����ID            */
#define   MIA40911  0x4031              /* mia40911() �Ύӎ��ގ�����ID            */
#define   MIA40919  0x4032              /* mia40919() �Ύӎ��ގ�����ID            */
#define   MIA40927  0x4033              /* mia40927() �Ύӎ��ގ�����ID            */
#define   MIA40935  0x4034              /* mia40935() �Ύӎ��ގ�����ID            */
#define   MIA40942  0x4035              /* mia40942() �Ύӎ��ގ�����ID            */
#define   MIA40950  0x4036              /* mia40950() �Ύӎ��ގ�����ID            */
#define   MIA40951  0x4037              /* mia40951() �Ύӎ��ގ�����ID            */
#define   MIA40954  0x406e              /* mia40954() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA41101  0x403f              /* mia41101() �Ύӎ��ގ�����ID            */
#define   MIA41107  0x4040              /* mia41107() �Ύӎ��ގ�����ID            */
#define   MIA41112  0x4041              /* mia41112() �Ύӎ��ގ�����ID            */
#define   MIA41120  0x4042              /* mia41120() �Ύӎ��ގ�����ID            */
#define   MIA41129  0x4043              /* mia41129() �Ύӎ��ގ�����ID            */
#define   MIA41136  0x4044              /* mia41136() �Ύӎ��ގ�����ID            */
#define   MIA41143  0x4045              /* mia41143() �Ύӎ��ގ�����ID            */
#define   MIA41205  0x4046              /* mia41205() �Ύӎ��ގ�����ID            */
#define   MIA41210  0x4047              /* mia41210() �Ύӎ��ގ�����ID            */
#define   MIA41217  0x4048              /* mia41217() �Ύӎ��ގ�����ID            */
#define   MIA41218  0x4049              /* mia41218() �Ύӎ��ގ�����ID            */
#define   MIA41225  0x404a              /* mia41225() �Ύӎ��ގ�����ID            */
#define   MIA41226  0x404b              /* mia41226() �Ύӎ��ގ�����ID            */
#define   MIA41233  0x404c              /* mia41233() �Ύӎ��ގ�����ID            */
#define   MIA41234  0x404d              /* mia41234() �Ύӎ��ގ�����ID            */
#define   MIA41240  0x404e              /* mia41240() �Ύӎ��ގ�����ID            */
#define   MIA41241  0x404f              /* mia41241() �Ύӎ��ގ�����ID            */
#define   MIA41247  0x4050              /* mia41247() �Ύӎ��ގ�����ID            */
#define   MIA41253  0x406f              /* mia41253() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA41302  0x4051              /* mia41302() �Ύӎ��ގ�����ID            */
#define   MIA41309  0x4052              /* mia41309() �Ύӎ��ގ�����ID            */
#define   MIA41415  0x4053              /* mia41415() �Ύӎ��ގ�����ID            */
#define   MIA41516  0x4054              /* mia41516() �Ύӎ��ގ�����ID            */
#define   MIA41622  0x4055              /* mia41622() �Ύӎ��ގ�����ID            */
#define   MIA41731  0x4056              /* mia41731() �Ύӎ��ގ�����ID            */
#define   MIA41738  0x4057              /* mia41738() �Ύӎ��ގ�����ID            */
#define   MIA41745  0x4058              /* mia41745() �Ύӎ��ގ�����ID            */
#define   MIA41808  0x4059              /* mia41808() �Ύӎ��ގ�����ID            */
#define   MIA41809  0x405a              /* mia41809() �Ύӎ��ގ�����ID            */
#define   MIA41811  0x405b              /* mia41811() �Ύӎ��ގ�����ID            */
#define   MIA41813  0x405c              /* mia41813() �Ύӎ��ގ�����ID            */
#define   MIA41814  0x405d              /* mia41814() �Ύӎ��ގ�����ID            */
#define   MIA41819  0x405e              /* mia41819() �Ύӎ��ގ�����ID            */
#define   MIA41821  0x405f              /* mia41821() �Ύӎ��ގ�����ID            */
#define   MIA41823  0x4060              /* mia41823() �Ύӎ��ގ�����ID            */
#define   MIA41827  0x4061              /* mia41827() �Ύӎ��ގ�����ID            */
#define   MIA41830  0x4062              /* mia41830() �Ύӎ��ގ�����ID            */
#define   MIA41832  0x4063              /* mia41832() �Ύӎ��ގ�����ID            */
#define   MIA41835  0x4064              /* mia41835() �Ύӎ��ގ�����ID            */
#define   MIA41837  0x4065              /* mia41837() �Ύӎ��ގ�����ID            */
#define   MIA41839  0x4066              /* mia41839() �Ύӎ��ގ�����ID            */
#define   MIA41842  0x4067              /* mia41842() �Ύӎ��ގ�����ID            */
#define   MIA41844  0x4068              /* mia41844() �Ύӎ��ގ�����ID            */
#define   MIA41846  0x4069              /* mia41846() �Ύӎ��ގ�����ID            */
#define   MIA41850  0x406a              /* mia41850() �Ύӎ��ގ�����ID            */
#define   MIA41851  0x406b              /* mia41851() �Ύӎ��ގ�����ID            */
#define   MIA41854  0x4070              /* mia41854() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA49999  0x406c              /* mia49999() �Ύӎ��ގ�����ID            */
#define   MIA50000  0x5000              /* mia50000() �Ύӎ��ގ�����ID            */
#define   MIA50001  0x5001              /* mia50001() �Ύӎ��ގ�����ID            */
#define   MIA50005  0x5002              /* mia50005() �Ύӎ��ގ�����ID            */
#define   MIA50006  0x5003              /* mia50006() �Ύӎ��ގ�����ID            */
#define   MIA50007  0x5004              /* mia50007() �Ύӎ��ގ�����ID            */
#define   MIA50008  0x5005              /* mia50008() �Ύӎ��ގ�����ID            */
#define   MIA50009  0x506d              /* mia50009() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA50010  0x5107              /* mia50010() �Ύӎ��ގ�����ID    SSCY0203*/
#define   MIA50104  0x510a              /* mia50104() �Ύӎ��ގ�����ID    SSCY0203*/
#define   MIA50105  0x5010              /* mia50105() �Ύӎ��ގ�����ID            */
#define   MIA50106  0x5100              /* mia50106() �Ύӎ��ގ�����ID            */
#define   MIA50107  0x5011              /* mia50107() �Ύӎ��ގ�����ID            */
#define   MIA50108  0x5012              /* mia50108() �Ύӎ��ގ�����ID            */
#define   MIA50109  0x5013              /* mia50109() �Ύӎ��ގ�����ID            */
#define   MIA50152  0x5014              /* mia50152() �Ύӎ��ގ�����ID            */
#define   MIA50205  0x5015              /* mia50205() �Ύӎ��ގ�����ID            */
#define   MIA50206  0x5101              /* mia50206() �Ύӎ��ގ�����ID            */
#define   MIA50207  0x5016              /* mia50207() �Ύӎ��ގ�����ID            */
#define   MIA50208  0x5017              /* mia50208() �Ύӎ��ގ�����ID            */
#define   MIA50209  0x5018              /* mia50209() �Ύӎ��ގ�����ID            */
#define   MIA50252  0x5019              /* mia50252() �Ύӎ��ގ�����ID            */
#define   MIA50305  0x501a              /* mia50305() �Ύӎ��ގ�����ID            */
#define   MIA50306  0x5102              /* mia50306() �Ύӎ��ގ�����ID            */
#define   MIA50307  0x501b              /* mia50307() �Ύӎ��ގ�����ID            */
#define   MIA50308  0x501c              /* mia50308() �Ύӎ��ގ�����ID            */
#define   MIA50309  0x501d              /* mia50309() �Ύӎ��ގ�����ID            */
#define   MIA50352  0x501e              /* mia50352() �Ύӎ��ގ�����ID            */
#define   MIA50405  0x501f              /* mia50405() �Ύӎ��ގ�����ID            */
#define   MIA50406  0x5103              /* mia50406() �Ύӎ��ގ�����ID            */
#define   MIA50407  0x5020              /* mia40407() �Ύӎ��ގ�����ID            */
#define   MIA50408  0x5021              /* mia50408() �Ύӎ��ގ�����ID            */
#define   MIA50409  0x5022              /* mia50409() �Ύӎ��ގ�����ID            */
#define   MIA50452  0x5023              /* mia50452() �Ύӎ��ގ�����ID            */
#define   MIA50501  0x5024              /* mia50501() �Ύӎ��ގ�����ID            */
#define   MIA50502  0x5025              /* mia50502() �Ύӎ��ގ�����ID            */
#define   MIA50505  0x5026              /* mia50505() �Ύӎ��ގ�����ID            */
#define   MIA50506  0x5104              /* mia50506() �Ύӎ��ގ�����ID            */
#define   MIA50507  0x5027              /* mia50507() �Ύӎ��ގ�����ID            */
#define   MIA50508  0x5028              /* mia50508() �Ύӎ��ގ�����ID            */
#define   MIA50509  0x5029              /* mia50509() �Ύӎ��ގ�����ID            */
#define   MIA50552  0x502a              /* mia50552() �Ύӎ��ގ�����ID            */
#define   MIA50624  0x502b              /* mia50624() �Ύӎ��ގ�����ID            */
#define   MIA50628  0x502c              /* mia50628() �Ύӎ��ގ�����ID            */
#define   MIA50722  0x502d              /* mia50722() �Ύӎ��ގ�����ID            */
#define   MIA50723  0x502e              /* mia50723() �Ύӎ��ގ�����ID            */
#define   MIA50724  0x502f              /* mia50724() �Ύӎ��ގ�����ID            */
#define   MIA50728  0x5030              /* mia50728() �Ύӎ��ގ�����ID            */
#define   MIA50804  0x5109              /* mia50804() �Ύӎ��ގ�����ID    SSCY0203*/
#define   MIA50906  0x5105              /* mia50906() �Ύӎ��ގ�����ID            */
#define   MIA50911  0x5031              /* mia50911() �Ύӎ��ގ�����ID            */
#define   MIA50919  0x5032              /* mia50919() �Ύӎ��ގ�����ID            */
#define   MIA50927  0x5033              /* mia50927() �Ύӎ��ގ�����ID            */
#define   MIA50935  0x5034              /* mia50935() �Ύӎ��ގ�����ID            */
#define   MIA50942  0x5035              /* mia50942() �Ύӎ��ގ�����ID            */
#define   MIA50950  0x5036              /* mia50950() �Ύӎ��ގ�����ID            */
#define   MIA50951  0x5037              /* mia50951() �Ύӎ��ގ�����ID            */
#define   MIA50954  0x506e              /* mia50954() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA51101  0x503f              /* mia51101() �Ύӎ��ގ�����ID            */
#define   MIA51107  0x5040              /* mia51107() �Ύӎ��ގ�����ID            */
#define   MIA51112  0x5041              /* mia51112() �Ύӎ��ގ�����ID            */
#define   MIA51120  0x5042              /* mia51120() �Ύӎ��ގ�����ID            */
#define   MIA51129  0x5043              /* mia51129() �Ύӎ��ގ�����ID            */
#define   MIA51136  0x5044              /* mia51136() �Ύӎ��ގ�����ID            */
#define   MIA51143  0x5045              /* mia51143() �Ύӎ��ގ�����ID            */
#define   MIA51205  0x5046              /* mia51205() �Ύӎ��ގ�����ID            */
#define   MIA51210  0x5047              /* mia51210() �Ύӎ��ގ�����ID            */
#define   MIA51217  0x5048              /* mia51217() �Ύӎ��ގ�����ID            */
#define   MIA51218  0x5049              /* mia51218() �Ύӎ��ގ�����ID            */
#define   MIA51225  0x504a              /* mia51225() �Ύӎ��ގ�����ID            */
#define   MIA51226  0x504b              /* mia51226() �Ύӎ��ގ�����ID            */
#define   MIA51233  0x504c              /* mia51233() �Ύӎ��ގ�����ID            */
#define   MIA51234  0x504d              /* mia51234() �Ύӎ��ގ�����ID            */
#define   MIA51240  0x504e              /* mia51240() �Ύӎ��ގ�����ID            */
#define   MIA51241  0x504f              /* mia51241() �Ύӎ��ގ�����ID            */
#define   MIA51247  0x5050              /* mia51247() �Ύӎ��ގ�����ID            */
#define   MIA51253  0x506f              /* mia51253() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA51302  0x5051              /* mia51302() �Ύӎ��ގ�����ID            */
#define   MIA51309  0x5052              /* mia51309() �Ύӎ��ގ�����ID            */
#define   MIA51415  0x5053              /* mia51415() �Ύӎ��ގ�����ID            */
#define   MIA51516  0x5054              /* mia51516() �Ύӎ��ގ�����ID            */
#define   MIA51622  0x5055              /* mia51622() �Ύӎ��ގ�����ID            */
#define   MIA51731  0x5056              /* mia51731() �Ύӎ��ގ�����ID            */
#define   MIA51738  0x5057              /* mia51738() �Ύӎ��ގ�����ID            */
#define   MIA51745  0x5058              /* mia51745() �Ύӎ��ގ�����ID            */
#define   MIA51806  0x5106              /* mia51806() �Ύӎ��ގ�����ID            */
#define   MIA51808  0x5059              /* mia51808() �Ύӎ��ގ�����ID            */
#define   MIA51809  0x505a              /* mia51809() �Ύӎ��ގ�����ID            */
#define   MIA51811  0x505b              /* mia51811() �Ύӎ��ގ�����ID            */
#define   MIA51813  0x505c              /* mia51813() �Ύӎ��ގ�����ID            */
#define   MIA51814  0x505d              /* mia51814() �Ύӎ��ގ�����ID            */
#define   MIA51819  0x505e              /* mia51819() �Ύӎ��ގ�����ID            */
#define   MIA51821  0x505f              /* mia51821() �Ύӎ��ގ�����ID            */
#define   MIA51823  0x5060              /* mia51823() �Ύӎ��ގ�����ID            */
#define   MIA51827  0x5061              /* mia51827() �Ύӎ��ގ�����ID            */
#define   MIA51830  0x5062              /* mia51830() �Ύӎ��ގ�����ID            */
#define   MIA51832  0x5063              /* mia51832() �Ύӎ��ގ�����ID            */
#define   MIA51835  0x5064              /* mia51835() �Ύӎ��ގ�����ID            */
#define   MIA51837  0x5065              /* mia51837() �Ύӎ��ގ�����ID            */
#define   MIA51839  0x5066              /* mia51839() �Ύӎ��ގ�����ID            */
#define   MIA51842  0x5067              /* mia51842() �Ύӎ��ގ�����ID            */
#define   MIA51844  0x5068              /* mia51844() �Ύӎ��ގ�����ID            */
#define   MIA51846  0x5069              /* mia51846() �Ύӎ��ގ�����ID            */
#define   MIA51850  0x506a              /* mia51850() �Ύӎ��ގ�����ID            */
#define   MIA51851  0x506b              /* mia51851() �Ύӎ��ގ�����ID            */
#define   MIA51854  0x5070              /* mia51854() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA59999  0x506c              /* mia59999() �Ύӎ��ގ�����ID            */
#define   MIA60000  0x6000              /* mia60000() �Ύӎ��ގ�����ID            */
#define   MIA60002  0x6001              /* mia60002() �Ύӎ��ގ�����ID            */
#define   MIA60003  0x6002              /* mia60003() �Ύӎ��ގ�����ID            */
#define   MIA60004  0x6003              /* mia60004() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA60005  0x6004              /* mia60005() �Ύӎ��ގ�����ID    SSCY0203*/
#define   MIA60100  0x6085              /* mia60100() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA60103  0x6010              /* mia60103() �Ύӎ��ގ�����ID            */
#define   MIA60104  0x6011              /* mia60104() �Ύӎ��ގ�����ID            */
#define   MIA60105  0x6012              /* mia60105() �Ύӎ��ގ�����ID            */
#define   MIA60107  0x6013              /* mia60107() �Ύӎ��ގ�����ID            */
#define   MIA60108  0x6014              /* mia60108() �Ύӎ��ގ�����ID            */
#define   MIA60109  0x6015              /* mia60109() �Ύӎ��ގ�����ID            */
#define   MIA60152  0x6016              /* mia60152() �Ύӎ��ގ�����ID            */
#define   MIA60200  0x6086              /* mia60200() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA60203  0x6017              /* mia60203() �Ύӎ��ގ�����ID            */
#define   MIA60204  0x6018              /* mia60204() �Ύӎ��ގ�����ID            */
#define   MIA60205  0x6019              /* mia60205() �Ύӎ��ގ�����ID            */
#define   MIA60207  0x601a              /* mia60207() �Ύӎ��ގ�����ID            */
#define   MIA60208  0x601b              /* mia60208() �Ύӎ��ގ�����ID            */
#define   MIA60209  0x601c              /* mia60209() �Ύӎ��ގ�����ID            */
#define   MIA60252  0x601d              /* mia60252() �Ύӎ��ގ�����ID            */
#define   MIA60300  0x6087              /* mia60300() �Ύӎ��ގ�����ID        PD0J*/
#define   MIA60303  0x601e              /* mia60303() �Ύӎ��ގ�����ID            */
#define   MIA60304  0x601f              /* mia60304() �Ύӎ��ގ�����ID            */
#define   MIA60305  0x6020              /* mia60305() �Ύӎ��ގ�����ID            */
#define   MIA60307  0x6021              /* mia60307() �Ύӎ��ގ�����ID            */
#define   MIA60308  0x6022              /* mia60308() �Ύӎ��ގ�����ID            */
#define   MIA60309  0x6023              /* mia60309() �Ύӎ��ގ�����ID            */
#define   MIA60352  0x6024              /* mia60352() �Ύӎ��ގ�����ID            */
#define   MIA60400  0x607d              /* mia60400() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA60403  0x6025              /* mia60403() �Ύӎ��ގ�����ID            */
#define   MIA60404  0x6026              /* mia60404() �Ύӎ��ގ�����ID            */
#define   MIA60405  0x6027              /* mia60405() �Ύӎ��ގ�����ID            */
#define   MIA60407  0x6028              /* mia60407() �Ύӎ��ގ�����ID            */
#define   MIA60408  0x6029              /* mia60408() �Ύӎ��ގ�����ID            */
#define   MIA60409  0x602a              /* mia60409() �Ύӎ��ގ�����ID            */
#define   MIA60452  0x602b              /* mia60452() �Ύӎ��ގ�����ID            */
#define   MIA60461  0x6088              /* mia60461() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60462  0x6089              /* mia60462() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60500  0x607e              /* mia60500() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA60501  0x602c              /* mia60501() �Ύӎ��ގ�����ID            */
#define   MIA60502  0x602d              /* mia60502() �Ύӎ��ގ�����ID            */
#define   MIA60503  0x602e              /* mia60503() �Ύӎ��ގ�����ID            */
#define   MIA60504  0x602f              /* mia60504() �Ύӎ��ގ�����ID            */
#define   MIA60505  0x6030              /* mia60505() �Ύӎ��ގ�����ID            */
#define   MIA60507  0x6031              /* mia60507() �Ύӎ��ގ�����ID            */
#define   MIA60508  0x6032              /* mia60508() �Ύӎ��ގ�����ID            */
#define   MIA60509  0x6033              /* mia60509() �Ύӎ��ގ�����ID            */
#define   MIA60552  0x6034              /* mia60552() �Ύӎ��ގ�����ID            */
#define   MIA60561  0x608a              /* mia60561() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60562  0x608b              /* mia60562() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60624  0x6035              /* mia60624() �Ύӎ��ގ�����ID            */
#define   MIA60628  0x6036              /* mia60628() �Ύӎ��ގ�����ID            */
#define   MIA60722  0x6037              /* mia60722() �Ύӎ��ގ�����ID            */
#define   MIA60723  0x6038              /* mia60723() �Ύӎ��ގ�����ID            */
#define   MIA60724  0x6039              /* mia60724() �Ύӎ��ގ�����ID            */
#define   MIA60728  0x603a              /* mia60728() �Ύӎ��ގ�����ID            */
#define   MIA60800  0x607f              /* mia60800() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA60802  0x603b              /* mia60802() �Ύӎ��ގ�����ID            */
#define   MIA60803  0x603c              /* mia60803() �Ύӎ��ގ�����ID            */
#define   MIA60804  0x603d              /* mia60804() �Ύӎ��ގ�����ID            */
#define   MIA60852  0x603e              /* mia60852() �Ύӎ��ގ�����ID            */
#define   MIA60861  0x608c              /* mia60861() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60862  0x608d              /* mia60862() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA60911  0x603f              /* mia60911() �Ύӎ��ގ�����ID            */
#define   MIA60919  0x6040              /* mia60919() �Ύӎ��ގ�����ID            */
#define   MIA60927  0x6041              /* mia60927() �Ύӎ��ގ�����ID            */
#define   MIA60935  0x6042              /* mia60935() �Ύӎ��ގ�����ID            */
#define   MIA60942  0x6043              /* mia60942() �Ύӎ��ގ�����ID            */
#define   MIA60949  0x6044              /* mia60949() �Ύӎ��ގ�����ID            */
#define   MIA60950  0x6045              /* mia60950() �Ύӎ��ގ�����ID            */
#define   MIA60951  0x6046              /* mia60951() �Ύӎ��ގ�����ID            */
#define   MIA60961  0x608e              /* mia60961() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA61101  0x604e              /* mia61101() �Ύӎ��ގ�����ID            */
#define   MIA61107  0x604f              /* mia61107() �Ύӎ��ގ�����ID            */
#define   MIA61112  0x6050              /* mia61112() �Ύӎ��ގ�����ID            */
#define   MIA61120  0x6051              /* mia61120() �Ύӎ��ގ�����ID            */
#define   MIA61129  0x6052              /* mia61129() �Ύӎ��ގ�����ID            */
#define   MIA61136  0x6053              /* mia61136() �Ύӎ��ގ�����ID            */
#define   MIA61143  0x6054              /* mia61143() �Ύӎ��ގ�����ID            */
#define   MIA61205  0x6055              /* mia61205() �Ύӎ��ގ�����ID            */
#define   MIA61210  0x6056              /* mia61210() �Ύӎ��ގ�����ID            */
#define   MIA61217  0x6057              /* mia61217() �Ύӎ��ގ�����ID            */
#define   MIA61218  0x6058              /* mia61218() �Ύӎ��ގ�����ID            */
#define   MIA61225  0x6059              /* mia61225() �Ύӎ��ގ�����ID            */
#define   MIA61226  0x605a              /* mia61226() �Ύӎ��ގ�����ID            */
#define   MIA61233  0x605b              /* mia61233() �Ύӎ��ގ�����ID            */
#define   MIA61234  0x605c              /* mia61234() �Ύӎ��ގ�����ID            */
#define   MIA61240  0x605d              /* mia61240() �Ύӎ��ގ�����ID            */
#define   MIA61241  0x605e              /* mia61241() �Ύӎ��ގ�����ID            */
#define   MIA61247  0x605f              /* mia61247() �Ύӎ��ގ�����ID            */
#define   MIA61248  0x6060              /* mia61248() �Ύӎ��ގ�����ID            */
#define   MIA61302  0x6061              /* mia61302() �Ύӎ��ގ�����ID            */
#define   MIA61309  0x6062              /* mia61309() �Ύӎ��ގ�����ID            */
#define   MIA61415  0x6063              /* mia61415() �Ύӎ��ގ�����ID            */
#define   MIA61516  0x6064              /* mia61516() �Ύӎ��ގ�����ID            */
#define   MIA61622  0x6065              /* mia61622() �Ύӎ��ގ�����ID            */
#define   MIA61731  0x6066              /* mia61731() �Ύӎ��ގ�����ID            */
#define   MIA61738  0x6067              /* mia61738() �Ύӎ��ގ�����ID            */
#define   MIA61745  0x6068              /* mia61745() �Ύӎ��ގ�����ID            */
#define   MIA61808  0x6069              /* mia61808() �Ύӎ��ގ�����ID            */
#define   MIA61809  0x606a              /* mia61809() �Ύӎ��ގ�����ID            */
#define   MIA61811  0x606b              /* mia61811() �Ύӎ��ގ�����ID            */
#define   MIA61813  0x606c              /* mia61813() �Ύӎ��ގ�����ID            */
#define   MIA61814  0x606d              /* mia61814() �Ύӎ��ގ�����ID            */
#define   MIA61819  0x606e              /* mia61819() �Ύӎ��ގ�����ID            */
#define   MIA61821  0x606f              /* mia61821() �Ύӎ��ގ�����ID            */
#define   MIA61823  0x6070              /* mia61823() �Ύӎ��ގ�����ID            */
#define   MIA61827  0x6071              /* mia61827() �Ύӎ��ގ�����ID            */
#define   MIA61830  0x6072              /* mia61830() �Ύӎ��ގ�����ID            */
#define   MIA61832  0x6073              /* mia61832() �Ύӎ��ގ�����ID            */
#define   MIA61835  0x6074              /* mia61835() �Ύӎ��ގ�����ID            */
#define   MIA61837  0x6075              /* mia61837() �Ύӎ��ގ�����ID            */
#define   MIA61839  0x6076              /* mia61839() �Ύӎ��ގ�����ID            */
#define   MIA61842  0x6077              /* mia61842() �Ύӎ��ގ�����ID            */
#define   MIA61844  0x6078              /* mia61844() �Ύӎ��ގ�����ID            */
#define   MIA61846  0x6079              /* mia61846() �Ύӎ��ގ�����ID            */
#define   MIA61849  0x607d              /* mia61849() �Ύӎ��ގ�����ID            */
#define   MIA61850  0x607a              /* mia61850() �Ύӎ��ގ�����ID            */
#define   MIA61851  0x607b              /* mia61851() �Ύӎ��ގ�����ID            */
#define   MIA61861  0x608f              /* mia61861() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA61953  0x6080              /* mia61953() �Ύӎ��ގ�����ID      stPD0A*/
#define   MIA61954  0x6081              /* mia61954() �Ύӎ��ގ�����ID            */
#define   MIA61955  0x6082              /* mia61955() �Ύӎ��ގ�����ID            */
#define   MIA61956  0x6083              /* mia61956() �Ύӎ��ގ�����ID            */
#define   MIA61957  0x6084              /* mia61957() �Ύӎ��ގ�����ID      edPD0A*/
#define   MIA62100  0x6090              /* mia62100() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA62102  0x6091              /* mia62102() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA62152  0x6092              /* mia62152() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA69999  0x607c              /* mia69999() �Ύӎ��ގ�����ID            */
#define   MIA70000  0x7000              /* mia70000() �Ύӎ��ގ�����ID            */
#define   MIA70001  0x7001              /* mia70001() �Ύӎ��ގ�����ID            */
#define   MIA70002  0x7002              /* mia70002() �Ύӎ��ގ�����ID            */
#define   MIA70003  0x7015              /* mia70003() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA70004  0x7016              /* mia70004() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA70005  0x7017              /* mia70005() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA70100  0x7003              /* mia70100() �Ύӎ��ގ�����ID            */
#define   MIA71101  0x7004              /* mia71101() �Ύӎ��ގ�����ID            */
#define   MIA71107  0x700b              /* mia71107() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71206  0x7005              /* mia71206() �Ύӎ��ގ�����ID            */
#define   MIA71211  0x700c              /* mia71211() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71214  0x7011              /* mia71214() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71216  0x7018              /* mia71216() �Ύӎ��ގ�����ID        PD02*/
#define   MIA71312  0x7014              /* mia71312() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71404  0x7006              /* mia71404() �Ύӎ��ގ�����ID            */
#define   MIA71505  0x7007              /* mia71505() �Ύӎ��ގ�����ID            */
#define   MIA71709  0x700d              /* mia71709() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71802  0x7008              /* mia71802() �Ύӎ��ގ�����ID            */
#define   MIA71803  0x7009              /* mia71803() �Ύӎ��ގ�����ID            */
#define   MIA71808  0x700e              /* mia71808() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71810  0x700f              /* mia71810() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71913  0x7013              /* mia71913() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA71915  0x7019              /* mia71915() �Ύӎ��ގ�����ID        PD02*/
#define   MIA72000  0x7010              /* mia72000() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA72112  0x7012              /* mia72112() �Ύӎ��ގ�����ID        PD0A*/
#define   MIA79999  0x700a              /* mia79999() �Ύӎ��ގ�����ID            */
#define   MIA80000  0x8000              /* mia80000() �Ύӎ��ގ�����ID            */
#define   MIA80001  0x8001              /* mia80001() �Ύӎ��ގ�����ID            */
#define   MIA80002  0x8002              /* mia80002() �Ύӎ��ގ�����ID            */
#define   MIA80003  0x8003              /* mia80003() �Ύӎ��ގ�����ID            */
#define   MIA80004  0x8004              /* mia80004() �Ύӎ��ގ�����ID            */
#define   MIA80005  0x8005              /* mia80005() �Ύӎ��ގ�����ID            */
#define   MIA80101  0x8006              /* mia80101() �Ύӎ��ގ�����ID            */
#define   MIA80105  0x8007              /* mia80105() �Ύӎ��ގ�����ID            */
#define   MIA80106  0x8008              /* mia80106() �Ύӎ��ގ�����ID            */
#define   MIA80107  0x8009              /* mia80107() �Ύӎ��ގ�����ID            */
#define   MIA80112  0x800a              /* mia80112() �Ύӎ��ގ�����ID            */
#define   MIA80201  0x800b              /* mia80201() �Ύӎ��ގ�����ID            */
#define   MIA80205  0x800c              /* mia80205() �Ύӎ��ގ�����ID            */
#define   MIA80206  0x800d              /* mia80206() �Ύӎ��ގ�����ID            */
#define   MIA80207  0x800e              /* mia80207() �Ύӎ��ގ�����ID            */
#define   MIA80212  0x800f              /* mia80212() �Ύӎ��ގ�����ID            */
#define   MIA80301  0x8010              /* mia80301() �Ύӎ��ގ�����ID            */
#define   MIA80307  0x8011              /* mia80307() �Ύӎ��ގ�����ID            */
#define   MIA80312  0x8012              /* mia80312() �Ύӎ��ގ�����ID            */
#define   MIA80404  0x8013              /* mia80404() �Ύӎ��ގ�����ID            */
#define   MIA80411  0x8014              /* mia80411() �Ύӎ��ގ�����ID            */
#define   MIA80414  0x801d              /* mia80414() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA80503  0x8015              /* mia80503() �Ύӎ��ގ�����ID            */
#define   MIA80609  0x8016              /* mia80609() �Ύӎ��ގ�����ID            */
#define   MIA80710  0x8017              /* mia80710() �Ύӎ��ގ�����ID            */
#define   MIA80802  0x8018              /* mia80802() �Ύӎ��ގ�����ID            */
#define   MIA80808  0x8019              /* mia80808() �Ύӎ��ގ�����ID            */
#define   MIA80813  0x801a              /* mia80813() �Ύӎ��ގ�����ID            */
#define   MIA89999  0x801b              /* mia89999() �Ύӎ��ގ�����ID            */
#define   MIA90000  0x9000              /* mia90000() �Ύӎ��ގ�����ID      stPD0A*/
#define   MIA90001  0x9033              /* mia90001() �Ύӎ��ގ�����ID        PD0B*/
#define   MIA90005  0x9001              /* mia90005() �Ύӎ��ގ�����ID            */
#define   MIA90006  0x9002              /* mia90006() �Ύӎ��ގ�����ID            */
#define   MIA90007  0x9003              /* mia90007() �Ύӎ��ގ�����ID            */
#define   MIA90008  0x9004              /* mia90008() �Ύӎ��ގ�����ID            */
#define   MIA90400  0x9005              /* mia90400() �Ύӎ��ގ�����ID            */
#define   MIA90405  0x9006              /* mia90405() �Ύӎ��ގ�����ID            */
#define   MIA90406  0x9007              /* mia90406() �Ύӎ��ގ�����ID            */
#define   MIA90407  0x9008              /* mia90407() �Ύӎ��ގ�����ID            */
#define   MIA90408  0x9009              /* mia90408() �Ύӎ��ގ�����ID            */
#define   MIA90409  0x900a              /* mia90409() �Ύӎ��ގ�����ID            */
#define   MIA90452  0x900b              /* mia90452() �Ύӎ��ގ�����ID            */
#define   MIA90460  0x9037              /* mia90460() �Ύӎ��ގ�����ID      stPD0O*/
#define   MIA90461  0x9038              /* mia90461() �Ύӎ��ގ�����ID            */
#define   MIA90462  0x9039              /* mia90462() �Ύӎ��ގ�����ID      edPD0O*/
#define   MIA90500  0x900c              /* mia90500() �Ύӎ��ގ�����ID            */
#define   MIA90501  0x900d              /* mia90501() �Ύӎ��ގ�����ID            */
#define   MIA90502  0x900e              /* mia90502() �Ύӎ��ގ�����ID            */
#define   MIA90505  0x900f              /* mia90505() �Ύӎ��ގ�����ID            */
#define   MIA90506  0x9010              /* mia90506() �Ύӎ��ގ�����ID            */
#define   MIA90507  0x9011              /* mia90507() �Ύӎ��ގ�����ID            */
#define   MIA90508  0x9012              /* mia90508() �Ύӎ��ގ�����ID            */
#define   MIA90509  0x9013              /* mia90509() �Ύӎ��ގ�����ID            */
#define   MIA90552  0x9014              /* mia90552() �Ύӎ��ގ�����ID            */
#define   MIA90560  0x903a              /* mia90560() �Ύӎ��ގ�����ID      stPD0O*/
#define   MIA90561  0x903b              /* mia90561() �Ύӎ��ގ�����ID            */
#define   MIA90562  0x903c              /* mia90562() �Ύӎ��ގ�����ID      edPD0O*/
#define   MIA90906  0x9015              /* mia90906() �Ύӎ��ގ�����ID            */
#define   MIA90935  0x9016              /* mia90935() �Ύӎ��ގ�����ID            */
#define   MIA90942  0x9017              /* mia90942() �Ύӎ��ގ�����ID            */
#define   MIA90959  0x9034              /* mia90959() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA90961  0x903d              /* mia90961() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA91101  0x9018              /* mia91101() �Ύӎ��ގ�����ID            */
#define   MIA91107  0x9019              /* mia91107() �Ύӎ��ގ�����ID            */
#define   MIA91136  0x901a              /* mia91136() �Ύӎ��ގ�����ID            */
#define   MIA91143  0x901b              /* mia91143() �Ύӎ��ގ�����ID            */
#define   MIA91205  0x901c              /* mia91205() �Ύӎ��ގ�����ID            */
#define   MIA91234  0x901d              /* mia91234() �Ύӎ��ގ�����ID            */
#define   MIA91240  0x901e              /* mia91240() �Ύӎ��ގ�����ID            */
#define   MIA91241  0x901f              /* mia91241() �Ύӎ��ގ�����ID            */
#define   MIA91247  0x9020              /* mia91247() �Ύӎ��ގ�����ID            */
#define   MIA91258  0x9035              /* mia91258() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA91260  0x9046              /* mia91260() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA91302  0x9021              /* mia91302() �Ύӎ��ގ�����ID            */
#define   MIA91309  0x9022              /* mia91309() �Ύӎ��ގ�����ID            */
#define   MIA91738  0x9023              /* mia91738() �Ύӎ��ގ�����ID            */
#define   MIA91745  0x9024              /* mia91745() �Ύӎ��ގ�����ID            */
#define   MIA91806  0x9025              /* mia91806() �Ύӎ��ގ�����ID            */
#define   MIA91808  0x9026              /* mia91808() �Ύӎ��ގ�����ID            */
#define   MIA91809  0x9027              /* mia91809() �Ύӎ��ގ�����ID            */
#define   MIA91835  0x9028              /* mia91835() �Ύӎ��ގ�����ID            */
#define   MIA91837  0x9029              /* mia91837() �Ύӎ��ގ�����ID            */
#define   MIA91839  0x902a              /* mia91839() �Ύӎ��ގ�����ID            */
#define   MIA91842  0x902b              /* mia91842() �Ύӎ��ގ�����ID            */
#define   MIA91844  0x902c              /* mia91844() �Ύӎ��ގ�����ID            */
#define   MIA91850  0x902d              /* mia91850() �Ύӎ��ގ�����ID            */
#define   MIA91851  0x902e              /* mia91851() �Ύӎ��ގ�����ID            */
#define   MIA91846  0x902f              /* mia91846() �Ύӎ��ގ�����ID            */
#define   MIA91859  0x9036              /* mia91859() �Ύӎ��ގ�����ID        PD0C*/
#define   MIA91861  0x903e              /* mia91861() �Ύӎ��ގ�����ID        PD0O*/
#define   MIA91954  0x9030              /* mia91954() �Ύӎ��ގ�����ID            */
#define   MIA91956  0x9031              /* mia91956() �Ύӎ��ގ�����ID            */
#define   MIA92100  0x9042              /* mia92100() �Ύӎ��ގ�����ID      stPD0O*/
#define   MIA92101  0x9043              /* mia92101() �Ύӎ��ގ�����ID            */
#define   MIA92102  0x9044              /* mia92102() �Ύӎ��ގ�����ID            */
#define   MIA92199  0x9045              /* mia92199() �Ύӎ��ގ�����ID      edPD0O*/
#define   MIA92209  0x9047              /* mia92209() �Ύӎ��ގ�����ID        PD0R*/
#define   MIA99999  0x9032              /* mia99999() �Ύӎ��ގ�����ID            */
#define   MIAa0000  0xa000              /* miaa0000() �Ύӎ��ގ�����ID            */
#define   MIAa0001  0xa001              /* miaa0001() �Ύӎ��ގ�����ID            */
#define   MIAa0002  0xa002              /* miaa0002() �Ύӎ��ގ�����ID            */
#define   MIAa0100  0xa003              /* miaa0100() �Ύӎ��ގ�����ID            */
#define   MIAa0302  0xa004              /* miaa0302() �Ύӎ��ގ�����ID            */
#define   MIAa0405  0xa005              /* miaa0405() �Ύӎ��ގ�����ID            */
#define   MIAa0509  0xa006              /* miaa0509() �Ύӎ��ގ�����ID            */
#define   MIAa0610  0xa007              /* miaa0610() �Ύӎ��ގ�����ID            */
#define   MIAa0707  0xa008              /* miaa0707() �Ύӎ��ގ�����ID            */
#define   MIAa0802  0xa009              /* miaa0802() �Ύӎ��ގ�����ID            */
#define   MIAa0806  0xa00a              /* miaa0806() �Ύӎ��ގ�����ID            */
#define   MIAa0808  0xa00b              /* miaa0808() �Ύӎ��ގ�����ID            */
#define   MIAa0814  0xa00d              /* miaa0814() �Ύӎ��ގ�����ID            */
#define   MIAa9999  0xa00c              /* miaa9999() �Ύӎ��ގ�����ID            */
#define   MIAb0000  0xb000              /* miab0000() �Ύӎ��ގ�����ID            */
#define   MIAb0001  0xb001              /* miab0001() �Ύӎ��ގ�����ID            */
#define   MIAb0002  0xb002              /* miab0002() �Ύӎ��ގ�����ID            */
#define   MIAb0100  0xb003              /* miab0100() �Ύӎ��ގ�����ID            */
#define   MIAb0101  0xb004              /* miab0101() �Ύӎ��ގ�����ID            */
#define   MIAb0200  0xb005              /* miab0200() �Ύӎ��ގ�����ID            */
#define   MIAb0201  0xb006              /* miab0201() �Ύӎ��ގ�����ID            */
#define   MIAb0302  0xb007              /* miab0302() �Ύӎ��ގ�����ID            */
#define   MIAb0311  0xb008              /* miab0311() �Ύӎ��ގ�����ID            */
#define   MIAb0315  0xb016              /* miab0315() �Ύӎ��ގ�����ID            */
#define   MIAb0316  0xb017              /* miab0316() �Ύӎ��ގ�����ID            */
#define   MIAb0405  0xb009              /* miab0405() �Ύӎ��ގ�����ID            */
#define   MIAb0504  0xb00a              /* miab0504() �Ύӎ��ގ�����ID            */
#define   MIAb0509  0xb00b              /* miab0509() �Ύӎ��ގ�����ID            */
#define   MIAb0513  0xb00c              /* miab0513() �Ύӎ��ގ�����ID            */
#define   MIAb0603  0xb00d              /* miab0603() �Ύӎ��ގ�����ID            */
#define   MIAb0610  0xb00e              /* miab0610() �Ύӎ��ގ�����ID            */
#define   MIAb0612  0xb00f              /* miab0612() �Ύӎ��ގ�����ID            */
#define   MIAb0707  0xb010              /* miab0707() �Ύӎ��ގ�����ID            */
#define   MIAb0802  0xb011              /* miab0802() �Ύӎ��ގ�����ID            */
#define   MIAb0806  0xb012              /* miab0806() �Ύӎ��ގ�����ID            */
#define   MIAb0808  0xb013              /* miab0808() �Ύӎ��ގ�����ID            */
#define   MIAb0811  0xb014              /* miab0811() �Ύӎ��ގ�����ID            */
#define   MIAb0814  0xb018              /* miab0814() �Ύӎ��ގ�����ID            */
#define   MIAb0815  0xb019              /* miab0815() �Ύӎ��ގ�����ID            */
#define   MIAb0816  0xb01a              /* miab0816() �Ύӎ��ގ�����ID            */
#define   MIAb9999  0xb015              /* miab9999() �Ύӎ��ގ�����ID      edPD0A*/
#define   MIAc0000  0xc000              /* miac0000() �Ύӎ��ގ�����ID      stPD0C*/
#define   MIAc0001  0xc001              /* miac0001() �Ύӎ��ގ�����ID            */
#define   MIAc0002  0xc002              /* miac0002() �Ύӎ��ގ�����ID            */
#define   MIAc1000  0xc003              /* miac1000() �Ύӎ��ގ�����ID            */
#define   MIAc2000  0xc004              /* miac2000() �Ύӎ��ގ�����ID      edPD0C*/
#define   MIAd0000  0xd000              /* miad0000() �Ύӎ��ގ�����ID      stPD0O*/
#define   MIAd0100  0xd001              /* miad0100() �Ύӎ��ގ�����ID            */
#define   MIAd0102  0xd002              /* miad0102() �Ύӎ��ގ�����ID            */
#define   MIAd0103  0xd003              /* miad0103() �Ύӎ��ގ�����ID            */
#define   MIAd0201  0xd004              /* miad0201() �Ύӎ��ގ�����ID            */
#define   MIAd0202  0xd005              /* miad0202() �Ύӎ��ގ�����ID            */
#define   MIAd0203  0xd006              /* miad0203() �Ύӎ��ގ�����ID            */
#define   MIAd0400  0xd007              /* miad0400() �Ύӎ��ގ�����ID            */
#define   MIAd0401  0xd008              /* miad0401() �Ύӎ��ގ�����ID            */
#define   MIAd0403  0xd009              /* miad0403() �Ύӎ��ގ�����ID            */
#define   MIAd0501  0xd00a              /* miad0501() �Ύӎ��ގ�����ID            */
#define   MIAd0502  0xd00b              /* miad0502() �Ύӎ��ގ�����ID            */
#define   MIAd0503  0xd00c              /* miad0503() �Ύӎ��ގ�����ID            */
#define   MIAd9999  0xd00d              /* miad9999() �Ύӎ��ގ�����ID      edPD0O*/
#define   MIAe0000  0xe000              /* miae0000() �Ύӎ��ގ�����ID        PD0Y*/

