/******************************************/
/*                                        */
/*               mdretv.h                 */
/*                                        */
/*            SMP������(DCP)�͎ݎ�������           */
/*                                        */
/* ��������������������ǯ�������    M01*/
/* ��̾����������ƣͳ��					  */
/*     �Ҏӎ؎ʎߎ������׎����ɲä���				  */
/*	   �����ѹ��׵��SSCY0079		   	  */
/******************************************/

#define  MDNORMAL    0l      	/*  �������ގ��� �������؎�����       */
#define  MDIVPARM   0xffff0001	/*  �ʎߎ׎Ҏ��� ���׎�            */
#define  MDDUBREQ   0xffff0002	/*  �Ǝ��ގ��� �֎���������         */
#define  MDNOTRCV   0xffff0003	/*  ������ �̎�      ��       */
#define  MDMSNDER   0xffff0004	/*  �Ҏ��������� �������� �����ގ���     */
#define  MDTBLERR   0xffff0005	/*  �Î��̎ގ� ���׎�       ��    */
#define  MDPBUFER   0xffff0006	/*  �̎ߎ��َʎގ��̎� ������ �����ގ���   */
#define  MDOVRENT   0xffff0007	/*  �Ď��ێ����� �����ʎގ�          */
#define  MDIFAERR   0xffff0008	/*  ���ݎ����̎����� ���׎�      ��  */
#define  MDDIVSEQ   0xffff0009	/*  �̎ގݎ��� �������ݎ� ���׎�       */
#define  MDINVENT   0xffff000a	/*  �Ď��ێ� �ю���    ��        */
#define  MDLPCHNG   0xffff000b	/*  �ێݎ؎ʎߎ� ���؎���������        */
#define  MDLPRSTR   0xffff000c	/*  �ێݎ؎ʎߎ� ����������������       */
#define  MDLPCLSE   0xffff000d	/*  �ێݎ؎ʎߎ� ���ێ����ގ�����       */
#define  MDLPUNUS   0xffff000e	/*  �ێݎ؎ʎߎ� �Ў��֎�           */
#define  MDOVRLNG   0xffff0010	/*  �������� �̎ގ���             */
#define  MDOTHDWN   0xffff0012	/*  ������ ���������ގ�            */
#define  MDNOTONL   0xffff0013	/*  ���ݎÎ� �ӎ��Ď� ���׎�         */
#define  MDHRDERR   0xffff0014	/*  �ʎ��Ď� ���������ގ�           */
#define  MDCHBLOK   0xffff0015	/*  �����Ȏ� ���֎�������           */
#define  MDDATERR   0xffff0016	/*  �֎����Վ� ���ގ֎��Ύ� �̎���      */
#define  MDNOTCLS   0xffff0017	/*  �ێݎ؎ʎߎ� �Ў��ێ�����         */
#define  MDCDEXER   0xffff0018	/*  �����������Ύ� ���׎�(���ގ������̎�)  */
#define  MDEXTRER   0xffff0019	/*  �����������Ύ� ���׎�(���ގ�������)   */
#define  MDNCNNLN   0xffff001a	/*  �Îގݎ܎ӎ� �Ў����ގ�         */
#define  MDNOUSLN   0xffff001b	/*  �������� �ю��ގՎ�            */
#define  MDNOTUSE   0xffff001c	/*  DCP ���֎� �̎�            */
#define  MDINTLER   0xffff001d	/*  TINT �ێݎ� �ю��ގՎ�        */
#define  MDNOTACC   0xffff001e	/*  ������������ �Ŏ�             */
#define  MDMEPTER   0xffff001f	/*  �Ҏӎ؎ʎߎ������׎�         M01*/
#define  MDUNDFCD   0xffff8000	/*  �ЎÎ����� �����Ď� ���ݎ�����      */
#define  MDUDFOLG   0xffff8010	/*  �������ގ̎ގ��� & �ЎÎ����� �����Ď� */
#define  MDUDCDER   0xffff8018	/*  �����������Ύ� ���׎�(���ގ������̎�)  */
                                /*   & �ЎÎ����� �����Ď�         */
#define  MDUDEXER   0xffff8019	/*  �����������Ύ� ���׎�(���ގ�������)   */
                                /*   & �ЎÎ����� �����Ď�         */
