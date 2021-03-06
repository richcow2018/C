/**********************************************************************/
/*                                                                    */
/*           THPT Ã-ÌÞÙ Ì«-Ï¯Ä     thpt.h   (63.05.20)                */
/*                                                                    */
/**********************************************************************/

struct mdhptko {
       short  thptlnno;                         /* Õ³º³¾²·Þ®¶²¾Ý½³    */
       short  thptyob0;                         /* ÖËÞ                */
       short  thptln01;                         /* TPLT´ÝÄØÊÞÝºÞ³#1   */
       short  thptln02;                         /*               #2   */
       short  thptln03;                         /*               #3   */
       short  thptln04;                         /*               #4   */
       short  thptln05;                         /*               #5   */
       short  thptln06;                         /*               #6   */
       short  thptln07;                         /*               #7   */
       short  thptln08;                         /*               #8   */
       short  thptln09;                         /*               #9   */
       short  thptln10;                         /*               #10  */
       short  thptln11;                         /*               #11  */
       short  thptln12;                         /*               #12  */
       short  thptln13;                         /*               #13  */
       short  thptln14;                         /*               #14  */
       short  thptln15;                         /*               #15  */
       short  thptln16;                         /*               #16  */
       short  thptln17;                         /*               #17  */
       short  thptln18;                         /*               #18  */
       short  thptln19;                         /*               #19  */
       short  thptln20;                         /*               #20  */
       short  thptln21;                         /*               #21  */
       short  thptln22;                         /*               #22  */
       short  thptln23;                         /*               #23  */
       short  thptln24;                         /*               #24  */
       short  thptln25;                         /*               #25  */
       short  thptln26;                         /*               #26  */
       short  thptln27;                         /*               #27  */
       short  thptln28;                         /*               #28  */
       short  thptln29;                         /*               #29  */
       short  thptln30;                         /*               #30  */
       short  thptln31;                         /*               #31  */
       short  thptln32;                         /*               #32  */
       short  thptpuno;                         /* ¶Þ²Ä³HCP-P¾²·Þ®PU½³*/
       short  thptmxpu;                         /* 1¶²¾Ý±ÀØ»²ÀÞ²PU½³  */
       short  thptluno;                         /* ¶Þ²Ä³HCP-P¾²·Þ®LU½³*/
       short  thptmxlu;                         /* 1PU±ÀØ»²ÀÞ²LU½³    */
       short  thptptyp;                         /* PUÀ²Ìß             */
       short  thptopap;                         /* 1LU±ÀØ»²ÀÞ²µÎÌßÝAP */
                                                /*                ½³  */
       short  thptcmdt;                         /* ºÏÝÄÞ¿³¼ÝÚ½ÎßÝ½    */
                                                /*        ÏÁÀ²ÏÁ      */
       short  thptdatt;                         /* ÃÞ-À¿³¼ÝÚ½ÎßÝ½     */
                                                /*        ÏÁÀ²ÏÁ      */
       short  thptnodt;                         /* network open       */
                                                /*     ÃÞ¨Ú²À²ÏÁ      */
       short  thptnorc;                         /* network open       */
                                                /*     ØÄ×²¶³ÝÀÁ      */
       short  thptdlrt;                         /* ÃÞ-ÀØÝ¸¾¯Ã²ØÄ×²    */
                                                /*       ÃÞ¨Ú²À²ÏÁ    */
       short  thptdlrc;                         /* ÃÞ-ÀØÝ¸¾¯Ã²ØÄ×²    */
                                                /*            ¶³ÝÀÁ   */
       short  thptaprc;                         /* ACTPU ØÄ×²¶³ÝÀÁ    */
       short  thptalrc;                         /* ACTLU ØÄ×²¶³ÝÀÁ    */
       short  thptbirc;                         /* BIND ØÄ×²¶³ÝÀÁ     */
       short  thptopdt;                         /* Ä¸¼­Ì§²Ùµ-ÌßÝ      */
                                                /*        ÃÞ¨Ú²À²ÏÁ   */
       short  thptcldt;                         /* Í²¿¸¶²¼Þ®ÃÞ¨Ú²À²ÏÁ */
       short  thptclrc;                         /* Í²¿¸¶²¼Þ®ØÄ×²¶³ÝÀÁ */
       short  thptmsno;                         /* MAX¿³¼ÝCT½³        */
       short  thptmrno;                         /* MAX¼Þ­¼ÝCT½³       */
       short  thptonml;                         /* »²ÀÞ²LOGONÒ¯¾-¼ÞÁ®³*/
       short  thptofml;                         /* »²ÀÞ²LOGOFF        */
                                                /*        Ò¯¾-¼ÞÁ®³   */
       short  thpttrsz;                         /* ÄÚ-½´Ø±»²½Þ        */
       short  thptwrit;                         /* 1¶²¾Ý±ÀØ É osiwrit */
                                                /*       »²ÀÞ²Ê¯º³½³  */
       short  thptbsct;                         /* ·ÎÝÀ²Ï-Á           */
       short  thptyob1;                         /* ÖËÞ                */
       char   thptssid[5];                      /* SSCP-ID            */
       char   thptyob2;                         /* ÖËÞ                */
       short  thptoems;                         /* LOGON ERROR        */
                                                /*         Ò¯¾-¼ÞÁ®³  */
       char   thptemsg[380];                    /* LOGON ERROR Ò¯¾-¼Þ */
};
typedef  struct  mdhptko  THPTPSZ;

