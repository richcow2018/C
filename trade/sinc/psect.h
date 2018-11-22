/*********************************************************************/
/*  PSECT �����Î� ������������ �� �������ގ�����                                     */
/*					�ԣģó�ȯ�ѡʻ����ǡ�	��������ǯ���������	 */
/*********************************************************************/
struct  pscpsect{
    char  pscprsas[2];                  /* �̎ߎێ��� ���ێ܎�                */
    short pscpsize;                     /* PSECT �� ��������              */
    char  pscstats[2];                  /* ����-����                     */
    char  pscyobi0[2];                  /* �֎ˎ�0                      */
    TCOMPAT *psccmadt;                  /* CM �� TADT ���ݎĎ� ���Ďގڎ�      */
    TCOMPAT *psclmadt;                  /* LM �� TADT ���ݎĎ� ���Ďގڎ�      */
    TCOMPAT *pscpctad;                  /* TPCT ���ݎĎ� ���Ďގڎ�           */
    long  pscprsid;                     /* �̎ߎێ��� �����͎ގ� ��             */
    char  pscprsnm[8];                  /* �̎ߎێ��� �����͎ގ� �Ҏ�            */
    long  pscmlbx1;                     /* ��-�َΎގ����� �����͎ގ� 1         */
    char *pscnvmad;                     /* NVM �� ���ݎĎ� ���Ďގڎ�	     */
    long  pscmlbms;                     /* MS ��-�َΎގ����� �����͎ގ�        */
    short pscpctno;                     /* �̎ߎێ��� �Ŏݎʎގ�               */
    short pscprgno;                     /* �̎ߎێ��ގ׎� ���͎ގ̎� �ʎގݎ��ގ�     */
    short psctpsno;                     /* �����؎��Վ� �ʎߎ� �ʎގݎ��ގ�         */
    char  pscpuno;                      /* PU�� �ʎގݎ��ގ�                */
    char  psctexcm;                     /* mo_excm�� �̎ߎێ��� �������� ����    */
    char *pscmiaad;                     /*���ގ����ݎ֎� MIA�؎������� ���ݎĎ� ���Ďގڎ�*/
    char  pscedsts;                     /* md_cedt ���Î����� (STC 752)   */ 
    char  pscyobi1;                     /* �֎ˎ� 1 (STC 752)           */
    short pscmiasz;                     /* MIA ������                   */
    char *pscobaad;                     /* ���������ގ��������� ���ގ����Ύ����؎� ���Ďގڎ�*/
	char *pscobsad;						/* �㳲���Ͼ��󥨥ꥢ(SMP��) */
										/* ���ɥ쥹				TD86 */
    char  pscmfzcb[64];                 /* ���� �������� ���ݎ� �̎ގێ���         */
    char  pscmfqcb[128];                /* �����ގ� ���ݎՎ� �֎������� ���ݎ� �̎ގێ��� */
    char  pscmrjcf[128];                /* JCF(Journal Control Feild)*/
    char  pscmopcb[128];                /* OCP �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
    char  pscmfpcb[128];                /* FIP �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
    char  pscmrpcb[128];                /* RCV �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
    char  pscmdpcb[128];                /* DCP �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
    long  pscoseki;                     /* ����- �ʎ����� �����Î� ��-�� �����͎ގ�   */
    long  pscosede;                     /* ����- ���������� ���ގ����Ύ�          */
    char  pscmspcb[16];                 /* SCP �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
	long  pscmbsms;						/* ���֣ͣӥᥤ��ܥå����ɣ�*/
	unsigned long	psclogcnt;			/* ���ƤӽФ����� TD93	 */
    char  pscmlpcb[32];                 /*FTAM �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
    char  pscmmpcb[32];                 /* RMS �̎ߎێ��� ���ގ����Ύ� ���ݎ� �̎ގێ���*/
};
typedef  struct  pscpsect  PSCPSECT;
