/**********************************************************************/
/*       X.25  LINE  CONTROL  TABLE                                   */
/**********************************************************************/
#define FTCMX 58
#define X25_80  0                       /*  X25_ 80年度版            T*/
#define X25_84  1                       /*  X25_ 84年度版            T*/
/**************/
/* サブ共通部 */
/**************/
typedef struct RXLTS {
                char    cgadexl;	/*  自NSAPアドレス長         T*/
       unsigned char	cgadex[20];	/*  自NSAPアドレス           T*/
       unsigned char	rsv[3];  	/*  予備                     T*/
} RXLTS ;
/********************************/
/* 共通部 + サブ共通部 + 個別部 */
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
       unsigned char       lntype;      /*  回線種別                 T*/
       short               unsyncno ;   /*  HIDOKI req. NO.           */
       short               chkno ;      /*  相手NSAP単位の着呼接続数 T*/
       unsigned char       mltopn;      /*  X25DRV 多重オープン可否  T*/
       unsigned char       ver;         /*  X25年度版種別            T*/
       /*********************/
       /* ファシリティ(SG)  */
       /*********************/
       unsigned char       facl;        /*  ファシリティ長           T*/
       unsigned char       fac[FTCMX];  /*  ファシリティ             T*/
       /*******************/
       /* 個別部 ワーク域 */
       /*******************/
       unsigned char       lstatus ;    /*  line status	              */
       char               *urdcbp ;    /*  RDCB addr ( for hidouki)  */
       char              *clsrp ;	/*  RDCB addr ( for close )   */
       char              *crdcbp ;	/*  RDCB addr 着呼接続要求用 T*/
       char             *cyakkoq ;	/*  cyakko ji queue           */
       unsigned long    sendwq ;	/*  send  wait queue          */
       unsigned long    sendwqt ;	/*  send  wait queue tail     */
       unsigned long    bgwq ;	        /*  buf get wait queue        */
       unsigned long    bgwqt ;	        /*  buf get wait queue tail   */
       char             *rrdcb  ;     /*  RDCB addr (for osireadd)  */
       long       fdes ;                /*  file descripter           */
} RXLTJ ;
