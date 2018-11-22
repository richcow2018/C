/*********************************************************************/
/*   テストする関数 mr_smrs  ダミーﾌﾟﾛｾｽでコールする関数            */
/*********************************************************************/

#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <netinet/in.h>

#include    "mosmpcom.h"
#include    "mr.h"
#include    "mo.h"
#include    "mc.h"
#include    "tcom.h"                     /* ﾃｰﾌﾞﾙ共通部               */
#include    "psect.h"                    /* PSECT                     */
#include    "mrcom.h"                    /* RCV ｷｮｳﾂｳ                 */
#include    "tsst.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "tpct.h"
#include    "mopcb.h"                   /* OCP ﾌﾟﾛｾｽ ｶﾝﾘ ﾌﾞﾛﾂｸ       */
#include    "mcmia.h"                   /* ﾃﾞﾝﾌﾞﾝ ｷｮｳﾂｳﾌﾞ            */
#include    "mrmuse.h"                  /* RCV ﾃﾞﾝﾌﾞﾝ ﾌｫ-ﾏｯﾄ         */
#include    "mrcode.h"                  /* RCV ﾀﾞｳﾝｺ-ﾄﾞ              */
#include    "mrmac.h"
#include    "mcdebug.h"
#include    "ossenmsp.h"
#include    "mre.h"
#include    "osgtpin.h"
#include	"mrmsg.h"
                                        /* mo_wlg.h は 削除          */
#define    MR_EJRQ    0x6d725f65,0x6a727120


/*********************************************************************/
/*    ｶﾞｲﾌﾞ ﾍﾝｽｳ                                                     */
/*********************************************************************/
extern    PSCPSECT    pscparea;
extern    MOPSCPCB    *mopcbp;

long 	ms_wtop(long, short, char, char, long, long);     

/*********************************************************************/
/*   ダミーﾌﾟﾛｾｽ  定義                                               */
/*********************************************************************/
long apmain(int argc, char *argv[], char *arge[])
{
    /*****************************************************************/
    /*  DMY ﾌﾟﾛｾｽ ﾅｲ ｼﾖｳ ｶﾝｽｳ ﾉ ﾃｲｷﾞ                                 */
    /*****************************************************************/
    TPCTPSZ *mr_cpct();                   /* PCT ｻ-ﾁ ｼｮﾘ             */
    long    mr_cgbf();                    /* ﾌﾟ-ﾙﾊﾞﾂﾌｧ ﾉ ｶｸﾄｸ        */
    long    ossenmsp();                   /* ﾒｯｾ-ｼﾞ ﾉ ﾊﾞｯﾌｧ ｿｳｼﾝ     */
    long    mc_copy();                    /* ﾃﾞ-ﾀ ｺﾋﾟ-               */
    long    mc_clea();                    /* ﾊﾞｯﾌｧ ｸﾘｱ-              */
    long    mo_frbf();                    /* ﾌﾟｰﾙﾊﾞｯﾌｧ ﾉ ｶｲﾎｳ        */
    void    mr_sabt();                    /* ﾌﾟﾛｾｽ ｱﾎﾞｰﾄ             */
    
    /*****************************************************************/
    /*  DMY ﾌﾟﾛｾｽﾅｲ ﾜ-ｸ ｴﾘｱ                                          */
    /*****************************************************************/
    register    TPCTPSZ  *pctp;         /* PCT ｺﾍﾞﾂﾌﾞ ﾎﾟｲﾝﾀ          */
    
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
