/* ダミー子プロセス用ソース */
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
//#include "oscrepr_ins.h"				/* 内部参照用 */

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
	char *MsgBuf=NULL;
	long len=0;
	
	long lAssign = 0;
	
	char *msg = NULL;
	
	long lRetForSprintf = 0;
	
	char *PTMsgPoint = NULL;
	
//	TMsgHed *PTMsgPoint = NULL;
	
	long arg = 0x00000000;				
	
	TEmmcTableInd* ptEmmcInd = NULL;

	TEmmcTableInd* ptEmmcIndLog = NULL;
	
	lAssign=sizeof(TMsgHed)+2;

//	PTMsgPoint=(char*) malloc(256);
	
//	msg=(char*) malloc(256);
	
	PTMsgPoint= calloc(2048, sizeof(char));
	
//	msg = (TMsgHed*)calloc(256, sizeof(TMsgHed));
	
	msg = calloc(256, sizeof(char));
	
	
			
	DbgInit( D_DEF, D_DEF, D_DEF );					// デバッグの開始（親関数のみ）

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
	
//	arg = 0x0001ffff | lMyPid;
	
//	DbgMsg01( DLv04, ( OutPut, "######## (4) arg==%08x\n", arg ) );
	
	DbgMsg01( DLv04, ( OutPut, "========   開始   ========\n") ); 

	/*	==============================  */
	/* 	buffer message initilization 	*/
	/*	==============================	*/
	
	MsgBuf = calloc(4096, sizeof(char));
	

	
	
	/*	##############################	*/
	/* 			SEND Process			*/
	/*	##############################	*/




	lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
	
	DbgMsg01( DLv04, ( OutPut, "\n##### end osioctl1  ***\n\n") );
	
	lRetForSprintf = sprintf(MsgBuf, "%s", "SO72\tabSAc12ｱ3ｲ");
	
	 DbgDmp02( DLv04, ("TEST OSWRITE 1", MsgBuf, sizeof(MsgBuf), 1, 0));
	
	len = strlen(MsgBuf);
	
	lRet = oswrite1(fildes, MsgBuf, len);

	lRet = osrcvms( arg, 50, 2048, PTMsgPoint );
	
	DbgMsg01( DLv04, ( OutPut, "\n######## PTMsgPoint (1) == %s\n", PTMsgPoint) );
	
	free(PTMsgPoint);



	
	if (lRet==-1)
	{
		printf("@@@@@@@ (2) 01:Err Mess: %s Num: %d\n", strerror(errno), errno);
	}
	
	if(lRet == NORMAL)
	{
		DbgMsg01( DLv04, ( OutPut, "========    完了   ========\n") ); 
	}
	
	DbgMsg01( DLv04, ( OutPut, "========    Finish  ========\n") ); 
	
	DbgEnd();										// デバッグの終了

	return(0);
}



