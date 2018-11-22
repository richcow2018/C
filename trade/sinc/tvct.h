/*********************************************************************/
/*  TVCT ｻﾌﾞ ｷﾖｳﾂｳﾌﾞ ﾉ ｺｳｿﾞｳﾀｲ                                       */
/*********************************************************************/
 
struct  tvctsub {
    char  tvctskb;                      /* ｶｲｼ ｸﾌﾞﾝ                  */
    char  tvctsy1;                      /* ﾖﾋﾞ 1                     */
    short tvcttsz;                      /* ﾃｰﾌﾞﾙ ﾃﾝｶｲ ｲｷ ﾉ ｵｵｷｻ      */
    char  tvcttdy[6];                   /* ﾎﾝｼﾞﾂ ﾋﾂﾞｹ                */
	unsigned	short	tvctsdy1;		/* SMP日付(立ち上げ回数)TD92 */
    short tvctsal;                      /* ﾋｷﾂｷﾞ ｴﾘｱ ｼﾞｮｳﾎｳ ﾉ        */
										/*       ｾﾝﾄｳ ﾉ ﾛｹｰｼｮﾝ       */
    short tvctsac;                      /* ﾋｷﾂｷﾞ ｴﾘｱ ｼﾞｮｳﾎｳ ﾉ ｶｽﾞ    */
    short tvctsyal;                     /* ﾖｸｼﾞﾂ ﾋｷﾂｷﾞ ｴﾘｱ ｼﾞｮｳﾎｳ ﾉ  */
										/*       ｾﾝﾄｳ ﾉ ﾛｹｰｼｮﾝ       */
    short tvctsyac;                     /* ﾖｸｼﾞﾂ ﾋｷﾂｷﾞ ｴﾘｱ ｼﾞｮｳﾎｳ ﾉ  */
										/*       ｶｽﾞ                 */
};      
typedef  struct  tvctsub  TVCTSUB;
 
/*********************************************************************/
/*  TVCT ｺﾍﾞﾂ ﾌﾞ ﾉ ｺｳｿﾞｳﾀｲ                                           */
/*********************************************************************/
 
struct  tvctpsz {
    char  tvcteti[4];                   /* ﾃ-ﾌﾞﾙ ｼｷﾍﾞﾂｼ              */
    short tvctemn;                      /* ｻｲﾀﾞｲ ｴﾝﾄﾘ ｽｳ             */
    short tvcteyn;                      /* ﾕｳｺｳ ｴﾝﾄﾘ ｽｳ              */
    short tvcteps;                      /* 1 ｺﾍﾞﾂﾌﾞ ﾉ ｵｵｷｻ           */
    unsigned	char  tvctesz;          /* ｻﾌﾞ ｷﾖｳﾂｳﾌﾞ ﾉ ｵｵｷｻ TC1965 */
    char  tvctest;                      /* ｽﾃ-ﾀｽ                     */
	long  tvctyor;                      /* ﾃｰﾌﾞﾙ ﾉ ﾖｳﾘｮｳ             */
	long  tvctadr;                      /* ﾃｰﾌﾞﾙ ﾉ ARﾌｧｲﾙ ﾅｲ ｱﾄﾞﾚｽ   */
	unsigned  short tvctst1;            /* ｽﾃｰﾀｽ 1                   */
	unsigned  short tvctst2;            /* ｽﾃｰﾀｽ 2                   */
	short tvctklc;                      /* ﾋｷﾂｷﾞ ｷｰ ﾉ ﾛｹｰｼｮﾝ         */
	short tvctkln;                      /* ﾋｷﾂｷﾞ ｷｰ ﾉ ﾊﾞｲﾄ ｽｳ        */
};      
typedef  struct  tvctpsz  TVCTPSZ;
 
struct  tvctarp {                       /* ﾋｷﾂｷﾞ ｴﾘｱ ｼﾞｳﾎｳ ﾉ ｺｳｿﾞｳﾀｲ */
 	short tvctarl;                      /* ﾋｷﾂｷﾞ ｴﾘｱ ﾉ ﾛｹｰｼｮﾝ        */
 	short tvctarb;                      /* ﾋｷﾂｷﾞ ｴﾘｱ ﾉ ﾊﾞｲﾄ ｽｳ       */
};
typedef  struct  tvctarp  TVCTARP;
 
struct  tvctyal {                       /* ﾖｸｼﾞﾂ ﾋｷﾂｷﾞ               */
                                        /*       ｴﾘｱ ｼﾞｳﾎｳ ﾉ ｺｳｿﾞｳﾀｲ */
 	short tvctyal;                      /* ﾖｸｼﾞﾂ ﾋｷﾂｷﾞ ｴﾘｱ ﾉ ﾛｹｰｼｮﾝ  */
 	short tvctyab;                      /* ﾖｸｼﾞﾂ ﾋｷﾂｷﾞ ｴﾘｱ ﾉ ﾊﾞｲﾄ ｽｳ */
};
typedef  struct  tvctyal  TVCTYAL;
