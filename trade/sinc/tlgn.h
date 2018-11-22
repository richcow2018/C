/*****************************************************************************/
/*                           <TLGN.H>                                        */
/*****************************************************************************/
/*                 TLGN ���͎ގ̎� �� �������ގ�����                                     */
/*                 ������95.9.1��M01 ���湨Ƿ                                */
/*                 ������97.1.7��M02 ��������   SSCY0191                     */
/*****************************************************************************/
/*****************************************************************************/

struct  tlgnsub {
        unsigned short  tlgnoptm ;      /* �����ץ��ȥ饤�ֳ֥�����       */
        unsigned short  tlgnsyb1 ;      /* ���ֶ�����ͽ����                 */
        unsigned long   tlgnsyb2 ;      /* ���ֶ�����ͽ����                 */
} ;
typedef struct tlgnsub TLGNSUB ;

struct  tlgnps1 {
        unsigned short  tlgnlgno ;      /* LCGN �ʎގݎ��ގ�                      */
        unsigned short  tlgnlcno ;      /* �������֎� LCN  ����                    */
} ;
typedef struct tlgnps1 TLGNPS1 ;

struct  tlgnpsz {
        unsigned short  tlgnlcgn ;      /* LCGN ����                          */
		unsigned char	tlgnflgs ;		/* ͭ����̵���ե饰					*/
        unsigned char   tlgnnapo ;      /* �ͥåȥ���������Ф���/�ʤ�    */	
		unsigned short	tlgnlnno ;		/* PU/�����ֹ�						*/
		unsigned char	tlgnx25v ;		/* X.25�С������ 0:80 1:84	     M01*/
		unsigned char	tlgnltyp ;		/* �������� 0:�� 1:TEL 2:ISDN		*/
		unsigned long	tlgnyob2 ;		/* ͽ����							*/
        TLGNPS1         tlgnps1[16] ;   /* LCGN : LCN ����                    */
} ;
typedef struct tlgnpsz TLGNPSZ ;

