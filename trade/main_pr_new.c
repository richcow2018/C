/* r~r��zqr��,ryrw|��{qzrw */
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
//#include "oscrepr_ins.h"				/* z��{3Qxe|��*/

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

	int pr[15] ;	/* r��(r qzr}x */

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
	
	

	
			
	DbgInit( D_DEF, D_DEF, D_DEF );					// r�ӽӣ�nq��u��nq���֎�x�Ҏ�q��q��

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


	sprintf(id[0], "SCS0");			//x��l{U����qd��	
	sprintf(id[1], "SCS2");			//x��l{U����qd��
	sprintf(id[2], "SCS6");			//x��l{U����qd��
	sprintf(id[3], "SO02");			//x��l{U����qd��
	sprintf(id[4], "SO06");			//x��l{U����qd��
	sprintf(id[5], "SO27");			//x��l{U����qd��
	sprintf(id[6], "SO33");			//x��l{U����qd��
	sprintf(id[7], "SO38");			//x��l{U����qd��
	sprintf(id[8], "SO62");			//x��l{U����qd��
	sprintf(id[9], "SOB6");		//x��l{U����qd��
	sprintf(id[10], "SRRA");		//x��l{U����qd��
	sprintf(id[11], "SRRB");		//x��l{U����qd��
	sprintf(id[12], "SOD1");		//x��l{U����qd��





/*
	sprintf(id[0], "SCS0");			//x��l{U����qd��	
	sprintf(id[1], "SCS1");			//x��l{U����qd��
	sprintf(id[2], "SCS2");			//x��l{U����qd��
	sprintf(id[3], "SCS3");			//x��l{U����qd��
	sprintf(id[4], "SCS4");			//x��l{U����qd��
	sprintf(id[5], "SCS5");			//x��l{U����qd��
	sprintf(id[6], "SCS6");			//x��l{U����qd��
	sprintf(id[7], "SCS7");			//x��l{U����qd��
	sprintf(id[8], "SCS8");			//x��l{U����qd��
	sprintf(id[9], "SCS9");			//x��l{U����qd��
	sprintf(id[10], "SCSA");		//x��l{U����qd��
	sprintf(id[11], "SCSB");		//x��l{U����qd��
	sprintf(id[12], "SCSC");		//x��l{U����qd��
	sprintf(id[13], "SCSD");		//x��l{U����qd��
	sprintf(id[14], "SD03");		//x��l{U����qd
//	sprintf(id[15], "SR02");		//x��l{U����qd��		
//	sprintf(id[16], "SR03");		//x��l{U����qd��	
*/	

/*
	sprintf(id[15], "SO01");		//x��l{U����qd��
	sprintf(id[16], "SO02");		//x��l{U����qd��
	sprintf(id[17], "SO03");		//x��l{U����qd��
	sprintf(id[18], "SO04");		//x��l{U����qd��	
	sprintf(id[19], "SO05");		//x��l{U����qd��
	sprintf(id[20], "SO06");		//x��l{U����qd��
	sprintf(id[21], "SO07");		//x��l{U����qd��
	sprintf(id[22], "SO08");		//x��l{U����qd��
	sprintf(id[23], "SO09");		//x��l{U����qd��
	sprintf(id[24], "SO0A");		//x��l{U����qd��
	sprintf(id[25], "SO0B");		//x��l{U����qd��
	sprintf(id[26], "SO10");		//x��l{U����qd��
	sprintf(id[27], "SO11");		//x��l{U����qd��
	sprintf(id[28], "SO12");		//x��l{U����qd��
	sprintf(id[29], "SO13");		//x��l{U����qd��
	sprintf(id[30], "SO14");		//x��l{U����qd��
	sprintf(id[31], "SO15");		//x��l{U����qd��
	sprintf(id[32], "SO16");		//x��l{U����qd��
	sprintf(id[33], "SO17");		//x��l{U����qd��
	sprintf(id[34], "SO20");		//x��l{U����qd��
	sprintf(id[35], "SO21");		//x��l{U����qd��
	sprintf(id[36], "SO22");		//x��l{U����qd��
	sprintf(id[37], "SO23");		//x��l{U����qd��
	sprintf(id[38], "SO24");		//x��l{U����qd��
	sprintf(id[39], "SO25");		//x��l{U����qd��	
	sprintf(id[40], "SO26");		//x��l{U����qd��	
	sprintf(id[41], "SO27");		//x��l{U����qd��	
	sprintf(id[42], "SO30");		//x��l{U����qd��	
	sprintf(id[43], "SO31");		//x��l{U����qd��	
	sprintf(id[44], "SO32");		//x��l{U����qd��	
	sprintf(id[45], "SO33");		//x��l{U����qd��	
	sprintf(id[46], "SO34");		//x��l{U����qd��	
	sprintf(id[47], "SO35");		//x��l{U����qd��	
	sprintf(id[48], "SO36");		//x��l{U����qd��	
	sprintf(id[49], "SO37");		//x��l{U����qd��	
	sprintf(id[50], "SO38");		//x��l{U����qd��	
	sprintf(id[51], "SO39");		//x��l{U����qd��	
	sprintf(id[52], "SO40");		//x��l{U����qd��	
	sprintf(id[53], "SO41");		//x��l{U����qd��	
	sprintf(id[54], "SO42");		//x��l{U����qd��	
	sprintf(id[55], "SO43");		//x��l{U����qd��	
	sprintf(id[56], "SO44");		//x��l{U����qd��	
	sprintf(id[57], "SO45");		//x��l{U����qd��	
	sprintf(id[58], "SO46");		//x��l{U����qd��	
	sprintf(id[59], "SO47");		//x��l{U����qd��	
	sprintf(id[60], "SO48");		//x��l{U����qd��	
	sprintf(id[61], "SO49");		//x��l{U����qd��	
	sprintf(id[62], "SO51");		//x��l{U����qd��	
	sprintf(id[63], "SO52");		//x��l{U����qd��	
	sprintf(id[64], "SO47");		//x��l{U����qd��	
	sprintf(id[65], "SO47");		//x��l{U����qd��	
	sprintf(id[66], "SO47");		//x��l{U����qd��	
	sprintf(id[67], "SO47");		//x��l{U����qd��	
	sprintf(id[68], "SO47");		//x��l{U����qd��	
	sprintf(id[69], "SO47");		//x��l{U����qd��	
	sprintf(id[70], "SO47");		//x��l{U����qd��	
	sprintf(id[71], "SO47");		//x��l{U����qd��	
	sprintf(id[72], "SO47");		//x��l{U����qd��	
	sprintf(id[73], "SO47");		//x��l{U����qd��	
	sprintf(id[74], "SO47");		//x��l{U����qd��	
	sprintf(id[75], "SO47");		//x��l{U����qd��	
	sprintf(id[76], "SO47");		//x��l{U����qd��	
	sprintf(id[77], "SO47");		//x��l{U����qd��	
	sprintf(id[78], "SO47");		//x��l{U����qd��	
	sprintf(id[79], "SO47");		//x��l{U����qd��	
	sprintf(id[80], "SO47");		//x��l{U����qd��	
	sprintf(id[81], "SO47");		//x��l{U����qd��	
	sprintf(id[82], "SO47");		//x��l{U����qd��	
	sprintf(id[83], "SO47");		//x��l{U����qd��	
	sprintf(id[84], "SO47");		//x��l{U����qd��	
	sprintf(id[85], "SO47");		//x��l{U����qd��	
	sprintf(id[86], "SO47");		//x��l{U����qd��	
	sprintf(id[87], "SO47");		//x��l{U����qd��	
	sprintf(id[88], "SO47");		//x��l{U����qd��	
	sprintf(id[89], "SO47");		//x��l{U����qd��	
	sprintf(id[90], "SO47");		//x��l{U����qd��	
	sprintf(id[91], "SO47");		//x��l{U����qd��	
	sprintf(id[92], "SO47");		//x��l{U����qd��	
	sprintf(id[93], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
	sprintf(id[62], "SO47");		//x��l{U����qd��	
*/	
	
	
	for ( i = 0 ; i <13 ; i++)
	{

		lRet = osioctl1(fildes, OSIMSPRS, &arg, sizeof(arg));
		
//		sprintf(MsgBuf, "%.4s\tabc\tdef\thijk\tlmno\trstu\t\tvwxyz", id[i]);

//		DbgDmp02( DLv04, ("TEST OSWRITE 0", MsgBuf, 500, 1, 0));
	
		sprintf(MsgBuf, "%.4s\t������\t������\t\t������", id[i]);
		
//		memset(MsgBuf+5, 0x61, 512);

//		memset(MsgBuf+517, 0x00, 1);


		len = strlen(MsgBuf);
		
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
		
	}


	for ( i = 0 ; i < 12 ; i++)
	{
			
		DbgMsg01( DLv04, ( OutPut, "\n######## RMSG (2) == %s\n", RMSG[i]) );
	}

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
	
	DbgEnd();										// r�ӽӣ�nq��xh|X

/*
while(1)
{
}
*/

	return(0);
}


