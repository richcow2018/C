
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
//#include "oscrepr_ins.h"

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

	int pr[15] ;

	char id[15][100] ; 

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
	
	

	
			
	DbgInit( D_DEF, D_DEF, D_DEF );	

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

		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, 517 , 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		


		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		lRet = osrcvms( arg, 50, 1024, PTMsgPoint);
	
		len = strlen(PTMsgPoint+1);
		
		memset( RMSG[i], 0x00 , 1024 ) ;
		
		memcpy(RMSG[i], PTMsgPoint+1, len+1);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 2", PTMsgPoint, len+1, 1, 0));
	
		DbgMsg01( DLv04, ( OutPut, "\n######## PTMsgPoint (1) == %s\n", PTMsgPoint+1) );
	
		memset( MsgBuf, 0x00 , 1024 ) ;
		
		memset( PTMsgPoint, 0x00 , 1024 ) ;
		
	
/*一度でいいのでここで呼ぶ*/
	lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
			
			
			
	for ( i = 0 ; i < 12 ; i++)
	{
			
		DbgMsg01( DLv04, ( OutPut, "\n######## RMSG (2) == %s\n", RMSG[i]) );
	}

	/*SO01〜SOEF*/
	for ( i = 0 ; i < 15 ; i++)/* ３文字目（０〜E）*/
	{

		for( j=0; j< 16; j++)/* ４文字目（０〜F）*/
		{
			/*パターン１*/
			sprintf(MsgBuf, "SO%1x%1x", i, j);

			(int)MsgBuf[2] = toupper((int)MsgBuf[2]);
			
			(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
			len = strlen(MsgBuf);
		
			DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

			lRet = oswrite1(fildes, MsgBuf, len);
			
			DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
			
			memset( MsgBuf , 0x00 , len ) ;
			
			
			/*パターン２*/
//			lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
		
			sprintf(MsgBuf, "SO%1x%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END", i, j);

//			sprintf(MsgBuf, "SO%1x%1x", i, j );

			(int)MsgBuf[2] = toupper((int)MsgBuf[2]);
			
			(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
			len = strlen(MsgBuf);
		
			DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

			lRet = oswrite1(fildes, MsgBuf, len);
		
			DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
			memset( MsgBuf , 0x00 , len ) ;
			
			
			/*パターン３*/
			
			sprintf(MsgBuf, "SO%1x%1x\t\t-0END", i, j);

			(int)MsgBuf[2] = toupper((int)MsgBuf[2]);
			
			(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
			len = strlen(MsgBuf);
		
			DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

			lRet = oswrite1(fildes, MsgBuf, len);
		
			DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
			
			memset( MsgBuf , 0x00 , len ) ;
			
			
			/*パターン４*/
			sprintf(MsgBuf, "SO%1x%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END", i, j);

			(int)MsgBuf[2] = toupper((int)MsgBuf[2]);
			
			(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
			len = strlen(MsgBuf);
		
			DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

			lRet = oswrite1(fildes, MsgBuf, len);
		
			DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
			memset( MsgBuf , 0x00 , len ) ;
		}
	}
	
	
	
	
	/* SRR0 〜 SRRB */
	for ( i = 0 ; i < 12 ; i++)
	{
		
		/*パターン１*/
		sprintf(MsgBuf, "SRR%1x", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		
		/*パターン２*/
		
		//lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
		
		sprintf(MsgBuf, "SRR%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END", i);

//		sprintf(MsgBuf, "SRR%1x", i);


		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
				
		/*パターン３*/
		sprintf(MsgBuf, "SRR%1x\t\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/*パターン４*/
		sprintf(MsgBuf, "SRR%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END", i);
		
		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	

/***************ここはよくわからないなくてもいいんじゃない？START***************/
/*
	sprintf(MsgBuf, "SRRA");
	
	len = strlen(MsgBuf);
	
	DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

	lRet = oswrite1(fildes, MsgBuf, len);
	
	DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
	
	memset( MsgBuf , 0x00 , len ) ;
*/
/***************ここはよくわからないなくてもいいんじゃない？END***************/
	
	
	
	
	/* SCS1 〜 SCSD */
	for ( i = 0 ; i < 14 ; i++)
	{
		/*パターン１*/		
		sprintf(MsgBuf, "SCS%1x", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/*パターン２*/
		sprintf(MsgBuf, "SCS%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/*パターン３*/
		sprintf(MsgBuf, "SCS%1x\t\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		/*パターン４*/
		sprintf(MsgBuf, "SCS%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		
	}
	
	
	/* SMD1〜SMD2 */
	for ( i = 1 ; i < 3 ; i++)
	{
		/*パターン１*/
		sprintf(MsgBuf, "SMD%1x", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/*パターン２*/
		sprintf(MsgBuf, "SMD%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/*パターン３*/
		sprintf(MsgBuf, "SMD%1x\t\t098\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
		/*パターン４*/
		sprintf(MsgBuf, "SMD%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
			
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );
		
		memset( MsgBuf , 0x00 , len ) ;
		
	}
	
	
	/* SR02 〜 SR03 */
	for ( i = 2 ; i < 4 ; i++)
	{
		/* パターン1 */
		sprintf(MsgBuf, "SR0%1x", i);

		(int)MsgBuf[3] = toupper((int)MsgBuf[3]);
	
		len = strlen(MsgBuf);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
	
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
		memset( MsgBuf , 0x00 , len ) ;
	
	
		/* パターン２ */
		sprintf(MsgBuf, "SR0%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END", i);
	
		len = strlen(MsgBuf);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
	
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
		memset( MsgBuf , 0x00 , len ) ;
	
	
		/* パターン３ */
		sprintf(MsgBuf, "SR0%1x\t\t-0END", i);
	
		len = strlen(MsgBuf);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
	
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/* パターン４ */
		sprintf(MsgBuf, "SR0%1x\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END", i);
	
		len = strlen(MsgBuf);
	
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
	
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
		memset( MsgBuf , 0x00 , len ) ;
	}
	
	
	
	/* SD03 */
		/* パターン１ */
		sprintf(MsgBuf, "SD03");
		
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
		
		memset( MsgBuf , 0x00 , len ) ;
		
		/* パターン２ */
		sprintf(MsgBuf, "SD03\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t-0END");
		
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
		
		memset( MsgBuf , 0x00 , len ) ;
		
		/* パターン３ */
		sprintf(MsgBuf, "SD03\t\t-0END");
		
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
		
		memset( MsgBuf , 0x00 , len ) ;
		
		
		/* パターン４ */
		sprintf(MsgBuf, "SD03\tabc\t123\tあいアイ\t愛,./[]^\t'n'\t098\t\t-0END");
		
		len = strlen(MsgBuf);
		
		DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

		lRet = oswrite1(fildes, MsgBuf, len);
		
		DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
		
		memset( MsgBuf , 0x00 , len ) ;





/*意地悪メッセージ*/
	/*ABCDで行う*/
	/*表示形式は s%s z%z %%s% %%z% %S %Z % s%0s % z%%0z */
	/*EFGHで行う*/
	/*表示形式は s%sup z%z%%s %%z%s %%0s %%0z */
	
	
	
	/* ABCD */
	sprintf(MsgBuf, "ABCD\ta10\b20\tc30\td40\t\t1234567890lm");
	
	len = strlen(MsgBuf);
	
	DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

	lRet = oswrite1(fildes, MsgBuf, len);
	
	DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
	memset( MsgBuf , 0x00 , len ) ;
		
	
	/* EFGH */

	sprintf(MsgBuf, "EFGH \ta10\b20\tc30\td40\te50\t\t1234567890lm");
	
	len = strlen(MsgBuf);
	
	DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, len, 1, 0));

	lRet = oswrite1(fildes, MsgBuf, len);
	
	DbgMsg01( DLv04, ( OutPut, "$$$$$$$$ OSWRITE END lRet ==%08x\n", lRet ) );	
	
	memset( MsgBuf , 0x00 , len ) ;
	
	

	
	
	
	DbgMsg01( DLv04, ( OutPut, "========    Finish  ========\n") ); 
	
	DbgEnd();



	return(0);
}

