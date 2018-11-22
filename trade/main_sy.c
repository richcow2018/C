/* ダミーシステム用ソース */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h> 

#define GLOBAL_VALUE_DEFINE
#define	 GLOBAL_DEBUG
//#include "os_debug.h"

#include "oscom.h"
#include "oscom_ins.h"
#include "os_SG_ins.h"

#include "oscrepr.h"
#include "oscrepr_ins.h"				/* 内部参照用 */

#include "oscremb.h"
#include "oscremb_ins.h"				/* 内部参照用 */

long os_initSystem(long lPCode);

int main(void)
{
	long lMem = 0;
	long lRes = 0;
	long lMoa = 0;
	long lKpr = 0;
	long lMail = 0;
	long lBpid = 0;
	long lFlg = 1;
	long get = 0;
	long spid;
	long lCnt = 0;
	long lLen = 0;
	char acLtoa[10];
	char acPrId[10];
	char acMlId[10];
	char acFname[32];
	char acPass[32];
	char acTestMess[10] = {"TEST TEST"};
	
	TErdcTableInd *ptErdcInd = NULL;
	osearg por;
	TEsysTable *ptEsysTbl = NULL;
	
    /****************************************/
	void func2();                                         
	struct sigaction new,old;
	
    new.sa_handler = func2;
    //new.sa_flags = SA_NOMASK ;
    sigaction(SIGALRM ,&new,&old);
	/****************************************/
	
	DbgInit( D_DEF, D_DEF, D_DEF );					// デバッグの開始（親関数のみ）
	lMoa = 0x00010099;

	
	
	DbgMsg01( DLv02, ( OutPut, "***** os_initSystem 開始\n") );

	lMem = os_initSystem(lMoa);
	
	DbgMsg01( DLv02, ( OutPut, "***** os_initSystem 共有メモリID:%d\n",lMem) );
	
	//	子プロセス１生成
	
	lKpr = 0x00010122;

//	lKpr = 0x00010123;

	lMail = ((lKpr & 0x0000ffff) | 0x00020000);
	
		DbgMsg01( DLv02, ( OutPut, "***** lMail == %lx\n",lMail ) );


	lMail = oscremb(lMail, 1);
	printf("oscremb:%lx\n", lMail);
	
	
	sprintf(acLtoa, "%ld", lMem);
	sprintf(acPrId, "%lx", lKpr);
	sprintf(acMlId, "%lx", lMail);
	strcpy(acPass,"/home/jimmy/10-17-02/main_pr");
	lLen = strlen(acPass);
	memcpy(acFname, acPass, 32L);

	printf("acFname[%s]\n", acFname);
	por.argv = malloc(100);

	por.argc = 4;
	por.argv[0] = acPrId;
	por.argv[1] = acLtoa;
	por.argv[2] = "0";
	por.argv[3] = acMlId;
	por.argv[4] = 0;

	lRes = oscrepr(acFname, lKpr, 0, NULL, &por);
	DbgMsg01( DLv04, ( OutPut, "oscrepr lRes:%lx\n", lRes));
	
	

	// 完了

	//	子プロセス２生成
/*
	lKpr = 0x00010003;
	lMail = ((lKpr & 0x0000ffff) | 0x00020000);

	lMail = oscremb(lMail, 1);
	printf("oscremb:%lx\n", lMail);
	
	sprintf(acLtoa, "%ld", lMem);
	sprintf(acPrId, "%lx", lKpr);
	sprintf(acMlId, "%lx", lMail);
	
	strcpy(acPass,"/home/nakamura/init/trade_rcv");
	memcpy(acFname, acPass, 32L);
	printf("acFname[%s]\n", acFname);
	
	por.argc = 4;
	por.argv[0] = acPrId;
	por.argv[1] = acLtoa;
	por.argv[2] = "0";
	por.argv[3] = acMlId;
	por.argv[4] = 0;
	
	lRes = oscrepr(acFname, lKpr, 0, NULL, &por);
	DbgMsg01( DLv04, ( OutPut, "oscrepr lRes:%lx\n", lRes));
*/
	// 完了

	DbgMsg01( DLv04, ( OutPut, "00SYSTEM\n"));
//	osdelmb(lMail,0);
//	free(por.argv);
	DbgMsg01( DLv01, ( OutPut, "***** os_initSystem 終了\n") );
//	while(1);
//		DbgMsg01( DLv04, ( OutPut, "02SYSTEM\n"));
//	}

	DbgEnd();										// デバッグの終了
//	os_endSG();
return(0);
}

void func2()
{
}

