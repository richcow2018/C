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

int main(int arvc,char *argv[])
{
	long lRet = 0;
	long lMem = 0;
	long lRes = 0;
	long lMoa = 0;
	
	long fildes = 0;
	char MsgBuf[1024];
	long len=0;

	int pr[15] ;	/* rxä¤r qzr}x */

	char id[15][100] ;   /* MesageID */

	int i ;

	int j;

	
	long lAssign = 0;
	
	char *msg = NULL;
	
	long lRetForSprintf = 0;
	
//	char *PTMsgPoint = NULL;
	
	long arg = 0x00000000;				
	
	char PTMsgPoint[1024];
	
	char RMSG[12][1024];
		
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


/*	sprintf(id[0], "SCS0");			//xx~åùU}zy}y„psåŒ
	sprintf(id[1], "SCS2");			//xx~åùU}zy}y„puåŒ
	sprintf(id[2], "SCS6");			//xx~åùU}zy}y„puåŒ
	sprintf(id[3], "SO02");			//xx~åùU}zy}y„puåŒ
	sprintf(id[4], "SO06");			//xx~åùU}zy}y„puåŒ
	sprintf(id[5], "SO27");			//xx~åùU}zy}y„puåŒ
	sprintf(id[6], "SO33");			//xx~åùU}zy}y„puåŒ
	sprintf(id[7], "SO38");			//xx~åùU}zy}y„puåŒ
	sprintf(id[8], "SO62");			//xx~åùU}zy}y„puåŒ
	sprintf(id[9], "SOB6");		//xx~åùU}zy}y„puåŒ
	sprintf(id[10], "SRRA");		//xx~åùU}zy}y„puåŒ
	sprintf(id[11], "SXXX");		//xx~åùU}zy}y„puåŒ
	sprintf(id[12], "SOD1");		//xx~åùU}zy}y„puåŒ
	sprintf(id[13], "SO72");		//xx~åùU}zy}y„puåŒ
*/


/*
	sprintf(id[0], "SXXX");		//xx~åùU}zy}y„puåŒ
	sprintf(id[1], "SOD1");		//xx~åùU}zy}y„puåŒ
	sprintf(id[2], "SXX1");		//xx~åùU}zy}y„puåŒ
*/

	sprintf(id[0], "SO72");		//xx~åùU}zy}y„puåŒ
	
	
	for ( i = 0 ; i <1 ; i++)
	{

		lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));

		memset(MsgBuf, 0x00, 1024);

		
		sprintf(MsgBuf, "%.4s\tabcdef±²³´µ\t\t ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝ ß", id[i]);

//		memset(MsgBuf+5, 0xa0, 1);

//		sprintf(MsgBuf, "%.4s\taBaB123Ü¦Ý456¥¤¡789¢£°\t\taBcDEnd", id[i]);

		memset(MsgBuf + ( strlen(MsgBuf) - 2), 0xde, 1);

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



/*
	for ( i = 0 ; i < 12 ; i++)
	{
			
		DbgMsg01( DLv04, ( OutPut, "\n######## RMSG (2) == %s\n", RMSG[i]) );
	}

*/

/*

	for ( i = 0 ; i < 14 ; i++)
	{

		for( j=0; j< 14; j++)
		{
			
			lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
		
			sprintf(MsgBuf, "SO%1x%1x\tabc\tdef\tghi\tjklm\tnop\tqrs\t\tvwxyz", i, j);

//			sprintf(MsgBuf, "SO%1x%1x", i, j );

			(int)MsgBuf[2] = toupper((int)MsgBuf[2]);
			
			(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
			len = strlen(MsgBuf);
		
			DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

			lRet = oswrite1(fildes, MsgBuf, len);
		
			DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
			memset( MsgBuf , 0x00 , len ) ;
		}
	}

	for ( i = 0 ; i < 12 ; i++)
	{

	
		lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
		
			sprintf(MsgBuf, "SRR%1x\tabc\tdef\thij\tklm\tnop\tqrs\t\tvwxyz", i);

//		sprintf(MsgBuf, "SRR%1x", i);


		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
	}
*/
	sprintf(MsgBuf, "SRRA");
	
	len = strlen(MsgBuf);

	lRet = oswrite1(fildes, MsgBuf, len);


	
	DbgMsg01( DLv04, ( OutPut, "========    Finish  ========\n") ); 
	
	DbgEnd();										// rsäôyèˆæï{{æ|X

/*
while(1)
{
}
*/

	return(0);
}


