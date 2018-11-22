/**********************************************************************/
/*                                                                    */
/*        TEOA �Î��̎ގ� �̎����ώ���     teoa.h  			                  */
/*                                   							      */
/*                                                                    */
/**********************************************************************/
/*--------------------------------------------------------------------------*/
/* �㥽����������̾��				 �Ķ�Ź�����ƥ���������(KSP)			*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������			SPCY0128*/
/*	UINT����[����ͭ��|�����ʤ�]��������뤿��ι��ܤ��ɲä���				*/
/*--------------------------------------------------------------------------*/

struct teoasb {
        UWORD	osasmid;				/* OSAS�ӎ��ގ�����ID     */
        UWORD   teoayob0;               /* ͽ��0                      */
};
typedef struct teoasb TEOASUB;     	    /* TEOA���ֶ�����         */

struct  teoako {
        UBYTE	asaplng;				/* ASAP IDĹ                  */
        UBYTE	teoacflg;				/* UINT����[����̵ͭ]����	SPCY0128*/
        UWORD	teoayob2;				/* ͽ��2			*/
        UBYTE	asapid[16];				/* ASAP ID			*/
        UWORD   teoairbn;   	        /* IRB��               */
        UWORD   teoatm11;       	    /* �����ϴƻ���(t11)             */
        UWORD   teoatm12;       	    /* �����ϴƻ���(t12)             */
        UWORD   teoatm15;       	    /* �����ϴƻ���(t15)             */
        UWORD   teoaussz;       	    /* UAT���ѼԾ���Ĺ           */
        UWORD   teoayob3;       	    /* ͽ��3			   */
};
typedef struct  teoako TEOAPSZ;        	/* TEOA������   */

										/* teoacflg ������			SPCY0128*/
#define TEOACFG		1					/* ��������					SPCY0128*/
#define TEOANCFG	0					/* �����ʤ�					SPCY0128*/
