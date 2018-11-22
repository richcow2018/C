/**************************************/
/*                                    */
/*             mepnws.h               */
/*                                    */
/*          me_pnws �� �͎����ގ̎�����        */
/*                                    */
/**************************************/
/**********************************************************************/
/*       �㥽����������̾��                ������                   */
/*       �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ�������       */
/*                                          �ξ����ɼTCBS0191        */
/*                                          �����������롼���ֹ���ֵ�*/
/*                                          ��ǽ���ɲ�            M01 */
/**********************************************************************/

typedef struct  {                       /* �؎ݎ�������������            */
    char    mditype ;                   /* �؎ݎ�����                    */
    char    mdyobi1[3] ;                /* ͽ��                       */
    long    mdsoptn[2] ;                /* Ŭ�ю����Îю��̎ߎ�����             */
    short   mdlink1 ;                   /* �����ʎߎ�����1             */
    char    mdccnid ;                   /* �̿��������               */
    char    mdyobi2 ;                   /* ͽ��                       */
    char    mdhpuno ;                   /* �Ύ��Ĳ���PU�ֹ�              */
    char    mdhchno ;                   /* �Ύ��Ĳ���CH�ֹ�              */
    short   mdhllno ;                   /* �Ύ������������ֹ�            */
    short   mdhrcum ;                   /* RCU���Ďގڎ�(�Ҏ���)              */
    short   mdhrcus ;                   /* RCU���Ďގڎ�(���̎�)              */
    short   mdlink2 ;                   /* �����ʎߎ�����2             */
/*  char    mdtpuno ;                   /* ü������PU�ֹ�  ���   M01 */
/*  char    mdtchno ;                   /* ü������CH�ֹ�  ���   M01 */
    char    mdtgrno ;                   /* �����������롼���ֹ�   M01 */
    short   mdtllno ;                   /* ü�����������ֹ�           */
    char    mdtlptn ;                   /* ü��LPN                    */
    char    mdtapic ;                   /* ü��API���Î��ގ�               */
} MELINKI;

typedef struct {                        /* me_pnws()�ֵѾ���͎�����      */
    short   mdrewsns;                   /* �܎������Î������� �ʎގݎ��ގ�����         */
    short   mdreyob1;                   /* �֎ˎ�                        */
    char    mdreprid[8];                /* �̎ߎێ��������͎ގҎ�               */
} MELINKH;

typedef struct {						/* me_pnws()�ֵѾ�������      */
	MELINKH mdh;						/* �͎�����                       */
	MELINKI mdi[256];					/* �؎ݎ���������                */
} MELINKA;
                  
#define PSZADR(p1,p2)                                     \
				((long)(p1) + sizeof(TCOMPAT) +           \
			    (((TCOMPAT*)p1)->tcomsbps) +               \
				(((TCOMPAT*)p1)->tcomprsl)*((p2)-1))

