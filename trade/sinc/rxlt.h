/**********************************************************************/
/*       X.25  LINE  CONTROL  TABLE                                   */
/**********************************************************************/
#define FTCMX 58
#define X25_80  0                       /*  X25_ 80ǯ����            T*/
#define X25_84  1                       /*  X25_ 84ǯ����            T*/
/**************/
/* ���ֶ����� */
/**************/
typedef struct RXLTS {
                char    cgadexl;	/*  ��NSAP���ɥ쥹Ĺ         T*/
       unsigned char	cgadex[20];	/*  ��NSAP���ɥ쥹           T*/
       unsigned char	rsv[3];  	/*  ͽ��                     T*/
} RXLTS ;
/********************************/
/* ������ + ���ֶ����� + ������ */
/********************************/
typedef struct RXLTJ {
       unsigned char   passnm[32] ;	/*  SPECIAL  file  name       */
                                        /*  1995.02.09 16->32	      */
                                        /*  RSCY1728.CUU017           */
       int                 rdatal  ;	/*  recieve  data  length     */
       unsigned short      rbufno  ;	/*  recieve  biffer  no       */
       unsigned char	   linelcn ;	/*  line : 0      lcn : 1     */
       unsigned char       rrspflag ;   /*  receive rsp flag  	      */
       unsigned char       plcnno[16] ;	/*  LCN  no ( pvc )H.01.07.20 */
       unsigned char	   scnfflag  ;  /*  SOTATSU  cnf  flag        */
       unsigned char       lntype;      /*  ��������                 T*/
       short               unsyncno ;   /*  HIDOKI req. NO.           */
       short               chkno ;      /*  ���NSAPñ�̤������³�� T*/
       unsigned char       mltopn;      /*  X25DRV ¿�ť����ץ����  T*/
       unsigned char       ver;         /*  X25ǯ���Ǽ���            T*/
       /*********************/
       /* �ե�����ƥ�(SG)  */
       /*********************/
       unsigned char       facl;        /*  �ե�����ƥ�Ĺ           T*/
       unsigned char       fac[FTCMX];  /*  �ե�����ƥ�             T*/
       /*******************/
       /* ������ ����� */
       /*******************/
       unsigned char       lstatus ;    /*  line status	              */
       char               *urdcbp ;    /*  RDCB addr ( for hidouki)  */
       char              *clsrp ;	/*  RDCB addr ( for close )   */
       char              *crdcbp ;	/*  RDCB addr �����³�׵��� T*/
       char             *cyakkoq ;	/*  cyakko ji queue           */
       unsigned long    sendwq ;	/*  send  wait queue          */
       unsigned long    sendwqt ;	/*  send  wait queue tail     */
       unsigned long    bgwq ;	        /*  buf get wait queue        */
       unsigned long    bgwqt ;	        /*  buf get wait queue tail   */
       char             *rrdcb  ;     /*  RDCB addr (for osireadd)  */
       long       fdes ;                /*  file descripter           */
} RXLTJ ;
