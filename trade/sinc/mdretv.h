/******************************************/
/*                                        */
/*               mdretv.h                 */
/*                                        */
/*            SMPｺｰﾙ(DCP)ﾍﾝｷｬｸﾁ           */
/*                                        */
/* 修正した日：１９９５年６月２０日    M01*/
/* 氏名　　　：新藤由美					  */
/*     ﾒﾓﾘﾊﾟｯﾁｴﾗｰを追加した				  */
/*	   仕様変更要求書：SSCY0079		   	  */
/******************************************/

#define  MDNORMAL    0l      	/*  ｾｲｼﾞｮｳ ｼｭｳﾘｮｳ　       */
#define  MDIVPARM   0xffff0001	/*  ﾊﾟﾗﾒｰﾀ ｴﾗｰ            */
#define  MDDUBREQ   0xffff0002	/*  ﾆｼﾞｭｳ ﾖｳｷｭｳ　         */
#define  MDNOTRCV   0xffff0003	/*  ｳｹﾂｹ ﾌｶ      　       */
#define  MDMSNDER   0xffff0004	/*  ﾒｯｾｰｼﾞ ｿｳｼﾝ ｲｼﾞｮｳ     */
#define  MDTBLERR   0xffff0005	/*  ﾃｰﾌﾞﾙ ｴﾗｰ       　    */
#define  MDPBUFER   0xffff0006	/*  ﾌﾟｰﾙﾊﾞｯﾌｧ ｶｸﾎ ｲｼﾞｮｳ   */
#define  MDOVRENT   0xffff0007	/*  ﾄｳﾛｸｽｳ ｵｰﾊﾞｰ          */
#define  MDIFAERR   0xffff0008	/*  ｲﾝﾀｰﾌｪｰｽ ｴﾗｰ      　  */
#define  MDDIVSEQ   0xffff0009	/*  ﾌﾞﾝｶﾂ ｼｰｹﾝｽ ｴﾗｰ       */
#define  MDINVENT   0xffff000a	/*  ﾄｳﾛｸ ﾑｺｳ    　        */
#define  MDLPCHNG   0xffff000b	/*  ﾛﾝﾘﾊﾟｽ ｷﾘｶｴﾁｭｳ        */
#define  MDLPRSTR   0xffff000c	/*  ﾛﾝﾘﾊﾟｽ ｻｲｶｲｼﾁｭｳ       */
#define  MDLPCLSE   0xffff000d	/*  ﾛﾝﾘﾊﾟｽ ｸﾛｰｽﾞﾁｭｳ       */
#define  MDLPUNUS   0xffff000e	/*  ﾛﾝﾘﾊﾟｽ ﾐｼﾖｳ           */
#define  MDOVRLNG   0xffff0010	/*  ｻｲｽﾞ ﾌﾞｿｸ             */
#define  MDOTHDWN   0xffff0012	/*  ﾀｹｲ ｼｮｳｶﾞｲ            */
#define  MDNOTONL   0xffff0013	/*  ｳﾝﾃﾝ ﾓｰﾄﾞ ｴﾗｰ         */
#define  MDHRDERR   0xffff0014	/*  ﾊｰﾄﾞ ｼｮｳｶﾞｲ           */
#define  MDCHBLOK   0xffff0015	/*  ﾁｬﾈﾙ ｼﾖｳﾁｭｳ           */
#define  MDDATERR   0xffff0016	/*  ﾖｳｷﾕｳ ｼﾞﾖｳﾎｳ ﾌｾｲ      */
#define  MDNOTCLS   0xffff0017	/*  ﾛﾝﾘﾊﾟｽ ﾐｸﾛｰｽﾞ         */
#define  MDCDEXER   0xffff0018	/*  ｶｸﾁｮｳﾎｳ ｴﾗｰ(ｿﾞｯｺｳﾌｶ)  */
#define  MDEXTRER   0xffff0019	/*  ｶｸﾁｮｳﾎｳ ｴﾗｰ(ｿﾞｯｺｳｶ)   */
#define  MDNCNNLN   0xffff001a	/*  ﾃﾞﾝﾜﾓｳ ﾐｾﾂｿﾞｸ         */
#define  MDNOUSLN   0xffff001b	/*  ｶｲｾﾝ ﾑｼﾞﾕﾝ            */
#define  MDNOTUSE   0xffff001c	/*  DCP ｼﾖｳ ﾌｶ            */
#define  MDINTLER   0xffff001d	/*  TINT ﾛﾝﾘ ﾑｼﾞﾕﾝ        */
#define  MDNOTACC   0xffff001e	/*  ｱｸｾｽｹﾝ ﾅｼ             */
#define  MDMEPTER   0xffff001f	/*  ﾒﾓﾘﾊﾟｯﾁｴﾗｰ         M01*/
#define  MDUNDFCD   0xffff8000	/*  ﾐﾃｲｷﾞ ｺｰﾄﾞ ｹﾝｼｭﾂ      */
#define  MDUDFOLG   0xffff8010	/*  ｻｲｽﾞﾌﾞｿｸ & ﾐﾃｲｷﾞ ｺｰﾄﾞ */
#define  MDUDCDER   0xffff8018	/*  ｶｸﾁｮｳﾎｳ ｴﾗｰ(ｿﾞｯｺｳﾌｶ)  */
                                /*   & ﾐﾃｲｷﾞ ｺｰﾄﾞ         */
#define  MDUDEXER   0xffff8019	/*  ｶｸﾁｮｳﾎｳ ｴﾗｰ(ｿﾞｯｺｳｶ)   */
                                /*   & ﾐﾃｲｷﾞ ｺｰﾄﾞ         */
