/*********************************************************************/
/*  PSECT ｼｽﾃﾑ ｷｮｳﾂｳｲｷ ﾉ ｺｳｿﾞｳﾀｲ                                     */
/*					ＴＤＣ開発用（暫定版）	１９９３年１１月１６日	 */
/*********************************************************************/
struct  pscpsect{
    char  pscprsas[2];                  /* ﾌﾟﾛｾｽ ｲﾛﾜｹ                */
    short pscpsize;                     /* PSECT ﾉ ｵｵｷｻ              */
    char  pscstats[2];                  /* ｽﾃ-ﾀｽ                     */
    char  pscyobi0[2];                  /* ﾖﾋﾞ0                      */
    TCOMPAT *psccmadt;                  /* CM ﾉ TADT ｾﾝﾄｳ ｱﾄﾞﾚｽ      */
    TCOMPAT *psclmadt;                  /* LM ﾉ TADT ｾﾝﾄｳ ｱﾄﾞﾚｽ      */
    TCOMPAT *pscpctad;                  /* TPCT ｾﾝﾄｳ ｱﾄﾞﾚｽ           */
    long  pscprsid;                     /* ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ｼ             */
    char  pscprsnm[8];                  /* ﾌﾟﾛｾｽ ｼｷﾍﾞﾂ ﾒｲ            */
    long  pscmlbx1;                     /* ﾒ-ﾙﾎﾞｯｸｽ ｼｷﾍﾞﾂｼ 1         */
    char *pscnvmad;                     /* NVM ﾉ ｾﾝﾄｳ ｱﾄﾞﾚｽ	     */
    long  pscmlbms;                     /* MS ﾒ-ﾙﾎﾞｯｸｽ ｼｷﾍﾞﾂｼ        */
    short pscpctno;                     /* ﾌﾟﾛｾｽ ﾅﾝﾊﾞｰ               */
    short pscprgno;                     /* ﾌﾟﾛｸﾞﾗﾑ ｺﾍﾞﾂﾌﾞ ﾊﾞﾝｺﾞｳ     */
    short psctpsno;                     /* ｼｮﾘﾁﾕｳ ﾊﾟｽ ﾊﾞﾝｺﾞｳ         */
    char  pscpuno;                      /* PUﾉ ﾊﾞﾝｺﾞｳ                */
    char  psctexcm;                     /* mo_excmﾉ ﾌﾟﾛｾｽ ｾｲｾｲ ｶﾋ    */
    char *pscmiaad;                     /*ｼﾞｭｼﾝﾖｳ MIAﾘｮｳｲｷ ｾﾝﾄｳ ｱﾄﾞﾚｽ*/
    char  pscedsts;                     /* md_cedt ｽﾃｰﾀｽ (STC 752)   */ 
    char  pscyobi1;                     /* ﾖﾋﾞ 1 (STC 752)           */
    short pscmiasz;                     /* MIA ﾁｮｳ                   */
    char *pscobaad;                     /* ｼｮｳｶﾞｲｶｲｾｷ ｼﾞｮｳﾎｳｴﾘｱ ｱﾄﾞﾚｽ*/
	char *pscobsad;						/* 障害解析情報エリア(SMP用) */
										/* アドレス				TD86 */
    char  pscmfzcb[64];                 /* ｶﾘ ｺｳｼﾝ ｶﾝﾘ ﾌﾞﾛｯｸ         */
    char  pscmfqcb[128];                /* ｼｹﾞﾝ ｾﾝﾕｳ ﾖｳｷｭｳ ｶﾝﾘ ﾌﾞﾛｯｸ */
    char  pscmrjcf[128];                /* JCF(Journal Control Feild)*/
    char  pscmopcb[128];                /* OCP ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
    char  pscmfpcb[128];                /* FIP ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
    char  pscmrpcb[128];                /* RCV ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
    char  pscmdpcb[128];                /* DCP ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
    long  pscoseki;                     /* ｴﾗ- ﾊｯｾｲ ｼｽﾃﾑ ｺ-ﾙ ｼｭﾍﾞﾂ   */
    long  pscosede;                     /* ｴﾗ- ｼｮｳｻｲ ｼﾞｮｳﾎｳ          */
    char  pscmspcb[16];                 /* SCP ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
	long  pscmbsms;						/* サブＭＳメイルボックスＩＤ*/
	unsigned long	psclogcnt;			/* ログ呼び出し通番 TD93	 */
    char  pscmlpcb[32];                 /*FTAM ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
    char  pscmmpcb[32];                 /* RMS ﾌﾟﾛｾｽ ｼﾞｮｳﾎｳ ｶﾝﾘ ﾌﾞﾛｯｸ*/
};
typedef  struct  pscpsect  PSCPSECT;
