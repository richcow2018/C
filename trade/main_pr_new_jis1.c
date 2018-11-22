/* r~rä˜qr{ä¨ryrw|xä÷qzrw */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>

#define GLOBAL_VALUE_DEFINE
#define	 GLOBAL_DEBUG
//#include "os_debug.h"

#include "oscom.h"
#include "oscom_ins.h"
#include "os_SG_ins.h"
#include "osimsio.h" 
#include "osioctl1_ins.h"

//#include "oscrepr.h"
//#include "oscrepr_ins.h"				/* zpy3Qxe|x„­

long os_initProcess(long, void*, long);
long oswrite1(long, char*, long);
void os_trcget1(short, short, char*, long);
void os_trcget2(short, short, long, ... );
void os_startTrace( void );
void os_printf(char *message);

int main(int arvc,char *argv[])
{
	long lRet = 0;
	long lMem = 0;
	long lRes = 0;
	long lMoa = 0;
	
	long fildes = 0;
	char MsgBuf1[1024];
	long len=0;

	int pr[15] ;	/* rxä¤r qzr}x */

	char id[15][256] ;   /* MesageID */

	int i ;

	int j;

	
	long lAssign = 0;
	
	char *msg = NULL;
	
	long lRetForSprintf = 0;
	
//	char *PTMsgPoint = NULL;
	
	long arg = 0x00000000;				
	
	char PTMsgPoint[1024];
	
//	char RMSG[12][1024];
		
	TEmmcTableInd* ptEmmcInd = NULL;

	TEmmcTableInd* ptEmmcIndLog = NULL;
	
	lAssign=sizeof(TMsgHed)+2;

//	char PTMsgPoint[1024];
	
//	PTMsgPoint= calloc(2048, sizeof(char));
	
	
	msg = calloc(256, sizeof(char));
	
	

	
			
	DbgInit( D_DEF, D_DEF, D_DEF );					// rsäôyèˆæï{zšåïu|àù9vyä²ä»y{–vŒ

	DbgMsg01( DLv04, ( OutPut, "***** START PROCESS\n") );
	lMem = atol(argv[1]);
	lMoa = strtol(argv[3],NULL, 16);

	DbgMsg01( DLv04, ( OutPut, "***** lMem:%ld\n", lMem ) );
	DbgMsg01( DLv04, ( OutPut, "***** lMoa:%lx\n", lMoa ) );
	
	lRes = os_initProcess( lMem, 0, lMoa);
	
//	arg = 0x00020122;
	
	DbgMsg01( DLv04, ( OutPut, "######## (1) arg==%08x\n", arg ) );
	
	DbgMsg01( DLv04, ( OutPut, "######## (2) lMyPid==%08x\n", lMyPid ) );
	
//	arg = ((0x0001ffff & lMyPid) | 0x00010000) ;

	arg = 0x00010122 ;

	
	DbgMsg01( DLv04, ( OutPut, "######## (3) arg==%08x\n", arg ) );
	
	DbgMsg01( DLv04, ( OutPut, "======== START ========\n") ); 

	/*	==============================  */
	/* 	buffer message initilization 	*/
	/*	==============================	*/
	

	
	
	/*	##############################	*/
	/* 			SEND Process			*/
	/*	##############################	*/


	pr[0] = 2 ;		/* SCS0 */
	pr[1] = 0 ;		/* SCS2 */
	pr[2] = 0 ;		/* SCS6 */
	pr[3] = 0 ;		/* SO02 */
	pr[4] = 1 ;		/* SO06 */
	pr[5] = 2 ;		/* SO14 */
	pr[6] = 1 ;		/* SO27 */
	pr[7] = 0 ;		/* SO33 */
	pr[8] = 5 ;		/* SO38 */
	pr[9] = 5 ;		/* SO62 */
	pr[10] = 1 ;	/* SOB6 */
	pr[11] = 0 ;	/* SRRA */
	pr[12] = 0 ;	/* SRRB */


	sprintf(id[0], "\t ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİ ß"); 
	sprintf(id[1], "\tabcdefghijklmnopqrstuvwxyz");			
	sprintf(id[2], "\t abcdefghijklmnopqrstuvwxyz ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİ ß");
	sprintf(id[3], "\t a±bc³defµhijklmnoÛqrstuvwÔyz ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»a¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎcÏĞÑÒÓÔÕÖd×ØÙÚÛÜİ ß");
	sprintf(id[4], "\tabcdef±²³´µ\t±²³´µ¶·¸¹");
	sprintf(id[5], "\tabcdef±²³´µ\t\t ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİ ß");
	sprintf(id[6], "\tabc±²³´µ\t\tabcdefghijklmnopqrstuvwxyz"); 
	sprintf(id[7], "\tabcd\t\t abcdefghijklmnopqrstuvwxyz ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİ ß");	
	sprintf(id[8], "\tabdef\t\t a±bc³defµhijklmnoÛqrstuvwÔyz ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»a¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎcÏĞÑÒÓÔÕÖd×ØÙÚÛÜİ ß");
	sprintf(id[9], "\taBaB123Ü¦İ456¥¤¡789¢£°\t\taBcDEnd");

/*
	sprintf(id[0], "SXXX");		//xx~åùU}zy}y„puåŒ
	sprintf(id[1], "SOD1");		//xx~åùU}zy}y„puåŒ
	sprintf(id[2], "SXX1");		//xx~åùU}zy}y„puåŒ
*/

	sprintf(id[0], "SO72");		//xx~åùU}zy}y„puåŒ

	lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
	
	
	for ( i = 0 ; i <10 ; i++)
	{
		memset( ( (id[i]) + ( strlen(id[i]) - 2) ), 0xde, 1);   
		
		switch(i);
		{
			case 0
				memset(id[i] + 1, 0xa0, 1);
			case 2
				memset(id[i] + 28, 0xa0, 1);
			case 3
				memset(id[i] + 30, 0xa0, 1);
			case 5
				memset(id[i] + 14, 0xa0, 1);
			case 7
				memset(id[i] + 35, 0xa0, 1);
			case 8
				memset(id[i] + 38, 0xa0, 1);
			default
				break;
		}
		
		os_printf(id[i]);
		
	}


	
	DbgMsg01( DLv04, ( OutPut, "========    Finish  ========\n") ); 
	
	DbgEnd();										// rsäôyèˆæï{{æ|X

/*
while(1)
{
}
*/

	return(0);
}

void os_printf( char *message);
{
		char MsgBuf[1024];
		
		char RMSG[1024];
		
		int i = 0;	
			
		memset(MsgBuf, 0x00, 1024);

		
		sprintf(MsgBuf, "SO72%s, message);


//		DbgDmp02( DLv04, ("TEST OSWRITE 0", MsgBuf, 500, 1, 0));
	
//		sprintf(MsgBuf, "%.4s\tupuytvTvœò\twxuK id[i]);
		
//		memset(MsgBuf+6, 0xa0, 1);

//		memset(MsgBuf, 0x00, 1);


		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, 517 , 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		


		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		


		memset(PTMsgPoint, 0x00, 1024);

		lRet = osrcvms( arg, 50, 256, PTMsgPoint);
	
		len = strlen(PTMsgPoint+1);
		
		memset( RMSG[i], 0x00 , 1024 ) ;
		
		memcpy(RMSG[i], PTMsgPoint+1, len+1);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 2", PTMsgPoint, 256, 1, 0));
	
		DbgMsg01( DLv04, ( OutPut, "\n######## PTMsgPoint (1) == %s\n", PTMsgPoint+1) );
	
		memset( MsgBuf, 0x00 , 1024 ) ;
		
		memset( PTMsgPoint, 0x00 , 1024 ) ;

}


