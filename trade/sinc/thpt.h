/**********************************************************************/
/*                                                                    */
/*           THPT ��-�̎ގ� �̎�-�ώ���     thpt.h   (63.05.20)                */
/*                                                                    */
/**********************************************************************/

struct mdhptko {
       short  thptlnno;                         /* �Վ������������ގ��������ݎ���    */
       short  thptyob0;                         /* �֎ˎ�                */
       short  thptln01;                         /* TPLT���ݎĎ؎ʎގݎ��ގ�#1   */
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
       short  thptpuno;                         /* ���ގ��Ď�HCP-P�������ގ�PU����*/
       short  thptmxpu;                         /* 1�������ݎ����؎������ގ�PU����  */
       short  thptluno;                         /* ���ގ��Ď�HCP-P�������ގ�LU����*/
       short  thptmxlu;                         /* 1PU�����؎������ގ�LU����    */
       short  thptptyp;                         /* PU�����̎�             */
       short  thptopap;                         /* 1LU�����؎������ގ����Ύ̎ߎ�AP */
                                                /*                ����  */
       short  thptcmdt;                         /* ���ώݎĎގ������ݎڎ��Ύߎݎ�    */
                                                /*        �ώ������ώ�      */
       short  thptdatt;                         /* �Î�-���������ݎڎ��Ύߎݎ�     */
                                                /*        �ώ������ώ�      */
       short  thptnodt;                         /* network open       */
                                                /*     �Îގ��ڎ������ώ�      */
       short  thptnorc;                         /* network open       */
                                                /*     �؎Ď׎������ݎ���      */
       short  thptdlrt;                         /* �Î�-���؎ݎ������Î��؎Ď׎�    */
                                                /*       �Îގ��ڎ������ώ�    */
       short  thptdlrc;                         /* �Î�-���؎ݎ������Î��؎Ď׎�    */
                                                /*            �����ݎ���   */
       short  thptaprc;                         /* ACTPU �؎Ď׎������ݎ���    */
       short  thptalrc;                         /* ACTLU �؎Ď׎������ݎ���    */
       short  thptbirc;                         /* BIND �؎Ď׎������ݎ���     */
       short  thptopdt;                         /* �Ď������̎����َ�-�̎ߎ�      */
                                                /*        �Îގ��ڎ������ώ�   */
       short  thptcldt;                         /* �͎������������ގ��Îގ��ڎ������ώ� */
       short  thptclrc;                         /* �͎������������ގ��؎Ď׎������ݎ��� */
       short  thptmsno;                         /* MAX��������CT����        */
       short  thptmrno;                         /* MAX���ގ�����CT����       */
       short  thptonml;                         /* �������ގ�LOGON�Ҏ���-���ގ�����*/
       short  thptofml;                         /* �������ގ�LOGOFF        */
                                                /*        �Ҏ���-���ގ�����   */
       short  thpttrsz;                         /* �Ď�-�����؎���������        */
       short  thptwrit;                         /* 1�������ݎ����� �� osiwrit */
                                                /*       �������ގ��ʎ���������  */
       short  thptbsct;                         /* ���Ύݎ�����-��           */
       short  thptyob1;                         /* �֎ˎ�                */
       char   thptssid[5];                      /* SSCP-ID            */
       char   thptyob2;                         /* �֎ˎ�                */
       short  thptoems;                         /* LOGON ERROR        */
                                                /*         �Ҏ���-���ގ�����  */
       char   thptemsg[380];                    /* LOGON ERROR �Ҏ���-���� */
};
typedef  struct  mdhptko  THPTPSZ;

