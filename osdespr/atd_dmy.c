/*********************************************************************/
/*   �ƥ��Ȥ���ؿ� mr_smrs  ���ߡ��̎ߎێ����ǥ����뤹��ؿ�            */
/*********************************************************************/

#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <netinet/in.h>

#include    "mosmpcom.h"
#include    "mr.h"
#include    "mo.h"
#include    "mc.h"
#include    "tcom.h"                     /* �Î��̎ގٶ�����               */
#include    "psect.h"                    /* PSECT                     */
#include    "mrcom.h"                    /* RCV ��������                 */
#include    "tsst.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "tpct.h"
#include    "mopcb.h"                   /* OCP �̎ߎێ��� ���ݎ� �̎ގێ�       */
#include    "mcmia.h"                   /* �Îގݎ̎ގ� ���������̎�            */
#include    "mrmuse.h"                  /* RCV �Îގݎ̎ގ� �̎�-�ώ���         */
#include    "mrcode.h"                  /* RCV ���ގ��ݎ�-�Ď�              */
#include    "mrmac.h"
#include    "mcdebug.h"
#include    "ossenmsp.h"
#include    "mre.h"
#include    "osgtpin.h"
#include	"mrmsg.h"
                                        /* mo_wlg.h �� ���          */
#define    MR_EJRQ    0x6d725f65,0x6a727120


/*********************************************************************/
/*    ���ގ��̎� �͎ݎ���                                                     */
/*********************************************************************/
extern    PSCPSECT    pscparea;
extern    MOPSCPCB    *mopcbp;

long 	ms_wtop(long, short, char, char, long, long);     

/*********************************************************************/
/*   ���ߡ��̎ߎێ���  ���                                               */
/*********************************************************************/
long apmain(int argc, char *argv[], char *arge[])
{
    /*****************************************************************/
    /*  DMY �̎ߎێ��� �Ŏ� ���֎� ���ݎ��� �� �Î�����                                 */
    /*****************************************************************/
    TPCTPSZ *mr_cpct();                   /* PCT ��-�� ������             */
    long    mr_cgbf();                    /* �̎�-�َʎގ̎� �� �����Ď�        */
    long    ossenmsp();                   /* �Ҏ���-���� �� �ʎގ��̎� ��������     */
    long    mc_copy();                    /* �Î�-�� ���ˎ�-               */
    long    mc_clea();                    /* �ʎގ��̎� ���؎�-              */
    long    mo_frbf();                    /* �̎ߎ��َʎގ��̎� �� �����Ύ�        */
    void    mr_sabt();                    /* �̎ߎێ��� ���Ύގ���             */
    
    /*****************************************************************/
    /*  DMY �̎ߎێ����Ŏ� ��-�� ���؎�                                          */
    /*****************************************************************/
    register    TPCTPSZ  *pctp;         /* PCT ���͎ގ̎� �Ύߎ��ݎ�          */
    
    long lRet = 0;

	char cMsg[256];


    /*****************************************************************/
  
 	sprintf(cMsg, "SO62\tSTART");
	
	ms_wtop((long)cMsg, strlen(cMsg) , MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);


  
//   	sprintf(cMsg, "SO62\t%08x\t%ld", pctp->tpctpid, pctp->tpctpid);
	
//	ms_wtop((long)cMsg, strlen(cMsg) , MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);



	lRet = osdespr( 0x00020004, 0 );

	PRINTF("lRet = %08x", lRet);
	
	
//	sprintf(cMsg, "SO62\tlRet=%08x", lRet);
	
//	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
	

	lRet = osdespr( 0x00010004, 0 );
	
	PRINTF("lRet1 = %08x", lRet);
	
//	sprintf(cMsg, "SO62\tlRet1=%08x", lRet);
	
//	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

	sprintf(cMsg, "SO62\tEND");
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
	

	
    return (0);
    
    
}
