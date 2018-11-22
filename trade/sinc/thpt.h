/**********************************************************************/
/*                                                                    */
/*           THPT ŽÃ-ŽÌŽÞŽÙ ŽÌŽ«-ŽÏŽ¯ŽÄ     thpt.h   (63.05.20)                */
/*                                                                    */
/**********************************************************************/

struct mdhptko {
       short  thptlnno;                         /* ŽÕŽ³ŽºŽ³Ž¾Ž²Ž·ŽÞŽ®Ž¶Ž²Ž¾ŽÝŽ½Ž³    */
       short  thptyob0;                         /* ŽÖŽËŽÞ                */
       short  thptln01;                         /* TPLTŽ´ŽÝŽÄŽØŽÊŽÞŽÝŽºŽÞŽ³#1   */
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
       short  thptpuno;                         /* Ž¶ŽÞŽ²ŽÄŽ³HCP-PŽ¾Ž²Ž·ŽÞŽ®PUŽ½Ž³*/
       short  thptmxpu;                         /* 1Ž¶Ž²Ž¾ŽÝŽ±ŽÀŽØŽ»Ž²ŽÀŽÞŽ²PUŽ½Ž³  */
       short  thptluno;                         /* Ž¶ŽÞŽ²ŽÄŽ³HCP-PŽ¾Ž²Ž·ŽÞŽ®LUŽ½Ž³*/
       short  thptmxlu;                         /* 1PUŽ±ŽÀŽØŽ»Ž²ŽÀŽÞŽ²LUŽ½Ž³    */
       short  thptptyp;                         /* PUŽÀŽ²ŽÌŽß             */
       short  thptopap;                         /* 1LUŽ±ŽÀŽØŽ»Ž²ŽÀŽÞŽ²ŽµŽÎŽÌŽßŽÝAP */
                                                /*                Ž½Ž³  */
       short  thptcmdt;                         /* ŽºŽÏŽÝŽÄŽÞŽ¿Ž³Ž¼ŽÝŽÚŽ½ŽÎŽßŽÝŽ½    */
                                                /*        ŽÏŽÁŽÀŽ²ŽÏŽÁ      */
       short  thptdatt;                         /* ŽÃŽÞ-ŽÀŽ¿Ž³Ž¼ŽÝŽÚŽ½ŽÎŽßŽÝŽ½     */
                                                /*        ŽÏŽÁŽÀŽ²ŽÏŽÁ      */
       short  thptnodt;                         /* network open       */
                                                /*     ŽÃŽÞŽ¨ŽÚŽ²ŽÀŽ²ŽÏŽÁ      */
       short  thptnorc;                         /* network open       */
                                                /*     ŽØŽÄŽ×Ž²Ž¶Ž³ŽÝŽÀŽÁ      */
       short  thptdlrt;                         /* ŽÃŽÞ-ŽÀŽØŽÝŽ¸Ž¾Ž¯ŽÃŽ²ŽØŽÄŽ×Ž²    */
                                                /*       ŽÃŽÞŽ¨ŽÚŽ²ŽÀŽ²ŽÏŽÁ    */
       short  thptdlrc;                         /* ŽÃŽÞ-ŽÀŽØŽÝŽ¸Ž¾Ž¯ŽÃŽ²ŽØŽÄŽ×Ž²    */
                                                /*            Ž¶Ž³ŽÝŽÀŽÁ   */
       short  thptaprc;                         /* ACTPU ŽØŽÄŽ×Ž²Ž¶Ž³ŽÝŽÀŽÁ    */
       short  thptalrc;                         /* ACTLU ŽØŽÄŽ×Ž²Ž¶Ž³ŽÝŽÀŽÁ    */
       short  thptbirc;                         /* BIND ŽØŽÄŽ×Ž²Ž¶Ž³ŽÝŽÀŽÁ     */
       short  thptopdt;                         /* ŽÄŽ¸Ž¼Ž­ŽÌŽ§Ž²ŽÙŽµ-ŽÌŽßŽÝ      */
                                                /*        ŽÃŽÞŽ¨ŽÚŽ²ŽÀŽ²ŽÏŽÁ   */
       short  thptcldt;                         /* ŽÍŽ²Ž¿Ž¸Ž¶Ž²Ž¼ŽÞŽ®ŽÃŽÞŽ¨ŽÚŽ²ŽÀŽ²ŽÏŽÁ */
       short  thptclrc;                         /* ŽÍŽ²Ž¿Ž¸Ž¶Ž²Ž¼ŽÞŽ®ŽØŽÄŽ×Ž²Ž¶Ž³ŽÝŽÀŽÁ */
       short  thptmsno;                         /* MAXŽ¿Ž³Ž¼ŽÝCTŽ½Ž³        */
       short  thptmrno;                         /* MAXŽ¼ŽÞŽ­Ž¼ŽÝCTŽ½Ž³       */
       short  thptonml;                         /* Ž»Ž²ŽÀŽÞŽ²LOGONŽÒŽ¯Ž¾-Ž¼ŽÞŽÁŽ®Ž³*/
       short  thptofml;                         /* Ž»Ž²ŽÀŽÞŽ²LOGOFF        */
                                                /*        ŽÒŽ¯Ž¾-Ž¼ŽÞŽÁŽ®Ž³   */
       short  thpttrsz;                         /* ŽÄŽÚ-Ž½Ž´ŽØŽ±Ž»Ž²Ž½ŽÞ        */
       short  thptwrit;                         /* 1Ž¶Ž²Ž¾ŽÝŽ±ŽÀŽØ ŽÉ osiwrit */
                                                /*       Ž»Ž²ŽÀŽÞŽ²ŽÊŽ¯ŽºŽ³Ž½Ž³  */
       short  thptbsct;                         /* Ž·ŽÎŽÝŽÀŽ²ŽÏ-ŽÁ           */
       short  thptyob1;                         /* ŽÖŽËŽÞ                */
       char   thptssid[5];                      /* SSCP-ID            */
       char   thptyob2;                         /* ŽÖŽËŽÞ                */
       short  thptoems;                         /* LOGON ERROR        */
                                                /*         ŽÒŽ¯Ž¾-Ž¼ŽÞŽÁŽ®Ž³  */
       char   thptemsg[380];                    /* LOGON ERROR ŽÒŽ¯Ž¾-Ž¼ŽÞ */
};
typedef  struct  mdhptko  THPTPSZ;

