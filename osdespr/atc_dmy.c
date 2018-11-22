/************************************************************************************************/
/*								共通ヘッダ・ファイル                							*/
/*																								*/
/************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <netinet/in.h>


/************************************************************************************************/
/*								利用者作成ヘッダ・ファイル             							*/
/*																								*/
/************************************************************************************************/
#include    "tcom.h"
#include    "psect.h"
#include    "mr.h"
#include    "tsst.h"	
#include    "tpct.h"	
#include    "mrmac.h"   
#include 	"trcv.h"	
#include    "mrcom.h"
#include    "tcst.h"
#include    "tbpt.h"
#include    "tsrt.h"
#include    "mrmirr.h"
#include    "mrcode.h"
#include    "momsdef.h"
#include    "mo.h"
#include    "mopcb.h"
#include	"mcdebug.h"
#include	"mrmsg.h"
#include    "mo_wlg.h"

/************************************************************************************************/
/*	外部関数宣言										             							*/
/*																								*/
/************************************************************************************************/
char 	syscom_get_bootmode();
long 	mf_srcv();
long 	mo_gtbf(long, long, long**);
long 	mo_frbf(long*);
long 	mo_date(long*, long*);
long 	ms_wtop(long, short, char, char, long, long);     
TCOMPAT *mo_tagt(unsigned char*);
void	mo_wlg4();        


/*********************************************************************/
/*   ダミーﾌﾟﾛｾｽ  定義                                               */
/*********************************************************************/
long apmain(int argc, char *argv[], char *arge[])
{

	char cMsg[256];
    
    
   	sprintf(cMsg, "%.4s", MRMSRRA);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);
   
 
   	sprintf(cMsg, "%.4s", MRMSRRB);
	
	ms_wtop((long)cMsg, strlen(cMsg), MRMSGFOM,MROUTPTN,MRATGRUP,MRATSUBN);

/* 
while(1)
{
}
*/ 
  return (0);
    
    
}
