/**************************************************************************/
/*                                                                        */
/*       TEFX ��-�̎ގ� �̎�-�ώ���       tefx.h        (06.06.27)                 */
/*                                                                        */
/*       95.5.29 �������ȥ饤�ֳ�����ˤ�뽤��(ST2638)   ���湨Ƿ  M01 */
/*                                                                        */
/**************************************************************************/
struct mdefxsb {                         /*  TEFX ���̎޶�����               */
       long    tefxtmop;                 /*  �Ǝ����̎ߎݎ����� ��                 */
       long    tefxtmdl;                 /*  �Îގ����؎ݎ������� ��                 */
	   long	   tefxtmko;				 /*	 �������ȥ饤�ֳ֥�����  M01*/ 
};                                       /*                               */
typedef struct mdefxsb TEFXSUB;          /*                               */
                                         /*                               */
struct mdefxko {                         /*  TEFX ������                  */
       char    tefxpuno;                 /*  PU�ֹ�                       */ 
       char    yob1;                     /*  ͽ��                         */
       char    tefxkset;                 /*  ȯ��Ʊ��ѥե饰��           */
       char    tefxqbit;                 /*  Q�ӥå�ON/OFF                */
       long    tefxrtri;                 /*  �؎Ď׎����                     */
       char    tefxhpsz;                 /*  ȯ�ƼԎʎߎ����Ď������� �ʾ����     */ 
       char    tefxcpsz;                 /*  ��ƼԎʎߎ����Ď������� �ʾ����     */ 
       char    tefxpkff;                 /*  �ʎߎ����Ď������� �̎������؎Î��̎׎���        */ 
       char    yob2;                     /*  ͽ��                         */ 
       char    tefxhwsz;                 /*  ȯ�Ƽ�WSNO                   */ 
       char    tefxcwsz;                 /*  ��Ƽ�WSNO                   */ 
       char    tefxwsff;                 /*  WSNO �̎������؎Î��̎׎���             */ 
       char    yob3;                     /*  ͽ��                         */ 
       char    tefxfasp;                 /*  �̎����Ď��ڎ��Ď��ʎߎ׎Ҏ���              */ 
       char    tefxkinp;                 /*  �忮�ݶ⎥�ʎߎ׎Ҏ���              */ 
       char    tefxthru;                 /*  ȯ��ƼԎ��َ��̎ߎ��Ď��׎�           */ 
       char    yob4;                     /*  ͽ��                         */ 
       long    tefxdeln;                 /*  ���DTE���Ďގڎ����             */ 
       long    tefxhadl;                 /*  ȯ���Ďގڎ����                  */ 
       long    tefxcadl;                 /*  �厱�Ďގڎ����                  */ 
       char    tefxdead[20];             /*  ���DTE���Ďގڎ���Ǽ�莱�Ďގڎ�      */ 
       char    tefxhaad[20];             /*  ȯ���Ďގڎ�                      */ 
       char    tefxcaad[20];             /*  �厱�Ďގڎ�                      */ 
};                                       /*                               */
typedef struct mdefxko TEFXPSZ;          /*                               */
