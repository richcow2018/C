/**********************************************************************/
/*                                                                    */
/*        TLPT �Î��̎ގ� �̎����ώ���     tlpt.h      (61.12.  )                */
/*                                    �͎ݎ���  (62.12.  )   CC           */
/*                                    �ѹ�   94.12.20    JJ           */
/*                                    �ѹ��� ����  ��                 */
/*                                    �ѹ�   95.06.08    SS           */
/*                                    �ѹ��� ��ƣͳ��	 ST2772		  */
/*                                    �ѹ�   95.05.06    KK           */
/*                                    �ѹ��� ��������	 SSCY0167  	  */
/*                                                                    */
/**********************************************************************/

struct mdlptsb {
        short    tlptinen;               /* ͽ��                   JJ */
        char     tlptyob0[6];            /* �֎ˎ�0                   JJ */
};
typedef struct mdlptsb MDLPTSB;          /* DCP �֎�                    */
typedef struct mdlptsb TLPTSUB;          /* FIP �֎�                    */

struct mdlptko {
	char   tlptkhyo    ;                 /* ���͎ގ̎� �ˎ�������              */
	char   tlptyob1[2] ;                 /* �֎ˎ�1                   KK */
	char   tlptdcfg    ;                 /* �������ݎ��؎��� �̎׎���          KK */
	short  tlptfapn    ;                 /* TFAP ���ݎĎ� NO.             */
	short  tlptlgtn    ;                 /* TLGT ���ݎĎ� NO.             */
	char   tlptipas    ;                 /* �ʎߎ� ���Î�����                 */
	char   tlptiatt    ;                 /* ATT ���Î�����                 */
	char   tlptihdk    ;                 /* �ˎĎގ��� ���Î�����               */
	char   tlptcomm    ;                 /* ���ޥ��̾			   SS */
	short  tlptpatn    ;                 /* TPAT ���ݎĎ� �ʎގݎ��ގ�       CC */
	short  tlptyob3    ;                 /* �֎ˎ�3                   CC */
	char   tlptpsnm[8] ;                 /* �ێݎ� �ʎߎ� �����͎ގҎ�        CC */
	char   tlptyob4[4] ;                 /* �֎ˎ�4                   JJ */
};
typedef struct mdlptko MDLPTKO;          /* DCP �֎�                    */
typedef struct mdlptko TLPTPSZ;          /* FIP �֎�                    */
