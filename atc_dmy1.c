/*********************************************************************/
/*																	*/
/* mr_ejrq テスト用ダミープログラム									*/
/*																	*/
/*********************************************************************/

#include	"osrcvmsp.h"
#include	"mc.h"
#include	"mo.h"
#include	"ms.h"
#include	"me.h"
#include	"mf.h"
#include	"mr.h"
#include	"tcom.h"
#include	"tsst.h"
#include	"tpct.h"
#include	"tcst.h"
#include	"psect.h"
#include	"mcdebug.h"
#include	"mo_wlg.h"
#include	"mscp.h"
#include	"tsrt.h"
#include 	"mrmsg.h"

void put_jedt2();
void put_trcv();
long mr_jedt2();
long mr_trcv() ;
char *mo_tagt();
void mr_sabt();
void tdc_dump();
void osdelay();

long apmain(int argc, char *argv[], char *arge[])
{
	 
	 while(1)
	 {
		sleep(1);
	}
	 
    PRINTF("atc_dmy START %d                " , 1 ) ;
			put_jedt2() ;

//			put_trcv() ;
//			break ;

//		default :
//	}
    PRINTF("atc_dmy END   %d                " , 2 ) ;
	return( 0 )	;
}

/************************************************/
/* mr_jedt2発行関数				1				*/
/************************************************/
void put_jedt2()
{
	TSRTPSZ	tsrt ;			/* TSRT構造体	*/
	long 	ret;
	TCOMPAT *tblcom ;
	char *tadtP ;			/* TADT先頭アドレス	*/
	char *tsrtP ;			/* TSRT先頭アドレス	*/
	char *tactP ;			/* TACT先頭アドレス	*/
	char *tbktP ;			/* TBKT先頭アドレス	*/
	char *tfmtP ;			/* TFMT先頭アドレス	*/
	char *tjctP ;			/* TJCT先頭アドレス	*/
	char *tpvtP ;			/* TPVT先頭アドレス	*/
	char *trctP ;			/* TRCT先頭アドレス	*/
	char *tvbtP ;			/* TVBT先頭アドレス	*/
	char *tvmtP ;			/* TVMT先頭アドレス	*/
	char *twmtP ;			/* TWMT先頭アドレス	*/
	char *tabeP ;			/* TABE先頭アドレス	*/

	
	extern  PSCPSECT pscparea;        					    /* システム 共通 TSECT 領域         */


		
	char *data2 ;
	short type ;	
	long  num  ;	
	long  size[10]  ;	
	long  offset[10]  ;	
	
	char* pcData[10];
	
	
	long count = 0;
	long count1 = 0;

	char test[0];

	/* 個別部番号	*/
	num = 1 ;

	/* 更新データサイズ */
//	size = sizeof( TSRTPSZ ) ;
	
	/* オフセット*/
	tadtP = mo_tagt( "TADT" ) ;	/* TADTの先頭アドレス取得	*/

    PRINTF("put_jedt2 (1) tadtP = %08x\n" , tadtP ) ;
   


	/********************     TBKT    ***********************/

	tbktP = mo_tagt("TBKT")	; 		/* TBKTの先頭アドレス取得*/
	
    PRINTF("put_jedt2 (2) tbktP = %08x\n" , tbktP ) ;

	pcData[0] = tbktP;
    
    PRINTF("put_jedt2 (2.1) pcData[0] = %08x\n" , pcData[0] ) ;



	/********************     TFMT    ***********************/

	tfmtP = mo_tagt("TFMT")	; 		/* TFMTの先頭アドレス取得*/

    PRINTF("put_jedt2 (3) tfmtP = %08x\n" , tfmtP ) ;
    
   	pcData[1] = tfmtP;

    PRINTF("put_jedt2 (3.1) pcData[1] = %08x\n" , pcData[1] ) ;



	/********************     TJCT    ***********************/
   
   	tjctP = mo_tagt("TJCT")	; 		/* TJCTの先頭アドレス取得*/

    PRINTF("put_jedt2 (4) tjctP = %08x\n" , tjctP ) ;
 
 	pcData[2] = tjctP;

    PRINTF("put_jedt2 (4.1) pcData[2] = %08x\n" , pcData[2] ) ;



	/********************     TPVT    ***********************/

   	tpvtP = mo_tagt("TPVT")	; 		/* TPVTの先頭アドレス取得*/

    PRINTF("put_jedt2 (5) tpvtP = %08x\n" , tpvtP ) ;
    
    pcData[3] = tpvtP;
    
    PRINTF("put_jedt2 (5.1) pcData[3] = %08x\n" , pcData[3] ) ;



	/********************     TRCT    ***********************/

   	trctP = mo_tagt("TRCT")	; 		/* TRCTの先頭アドレス取得*/

    PRINTF("put_jedt2 (6) trctP = %08x\n" , trctP ) ;
    
    pcData[4] = trctP;
  
    PRINTF("put_jedt2 (6.1) pcData[4] = %08x\n" , pcData[4] ) ;
    


   	/********************     TSRT    ***********************/

	tsrtP = mo_tagt("TSRT")	; 		/* TSRTの先頭アドレス取得*/

    PRINTF("put_jedt2 (7) tsrtP = %08x\n" , tadtP ) ;

	tblcom = (TCOMPAT*)tsrtP ;		
									/* TSRT個別部の先頭アドレスからTADTのアドレスを引く */
	pcData[5] = (char*) ( (( tsrtP + tblcom->tcomsbps + sizeof( TCOMPAT ) ) - tadtP) - 12 ) ;

    PRINTF("put_jedt2 (7.1) pcData[5] = %08x\n" , pcData[5] ) ;



   	/********************     TVBT    ***********************/


   	tvbtP = mo_tagt("TVBT")	; 		/* TVBTの先頭アドレス取得*/

    PRINTF("put_jedt2 (8) tvbtP = %08x\n" , tvbtP ) ;
    
    pcData[6] = tvbtP;
    
    PRINTF("put_jedt2 (8.1) pcData[6] = %08x\n" , pcData[6] ) ;



   	/********************     TVMT    ***********************/

   	tvmtP = mo_tagt("TVMT")	; 		/* TVMTの先頭アドレス取得*/

    PRINTF("put_jedt2 (9) tvmtP = %08x\n" , tvmtP ) ;
    
    pcData[7] = tvmtP ;
    
    PRINTF("put_jedt2 (9.1) pcData[7] = %08x\n" , pcData[7] ) ;



   	/********************     TWMT    ***********************/

   	twmtP = mo_tagt("TWMT")	; 		/* TWMTの先頭アドレス取得*/

    PRINTF("put_jedt2 (10) twmtP = %08x\n" , twmtP ) ;
    
    pcData[8] = twmtP;
    
    PRINTF("put_jedt2 (10.1) pcData[8]  = %08x\n" , pcData[8]  ) ;
    
    

   	/********************     TABE    ***********************/

   	tabeP = mo_tagt("TABE")	; 		/* TWMTの先頭アドレス取得*/

    PRINTF("put_jedt2 (10) tabeP = %08x\n" , tabeP ) ;
    
    pcData[9] = tabeP;
    
    PRINTF("put_jedt2 (10.1) pcData[9]  = %08x\n" , pcData[9]  ) ;
    
  
 // 	 osdelay(0x7FFFFFFF, 4);
  
  //	sprintf(test, "djfjfjdsfjdfjsdjdksjnfldjfs%ld", 1);
  	
 // 	return;
   
  
  
//    mr_sabt( 0x00038204 , 0x12345678 , 0x12345678, 0x12345678 ) ;

//    mr_nabt( 0x00038204 , 0x12345678 , 0x12345678, 0x12345678 ) ;


	/************************************************/
	/* mr_jedt2を発行				 				*/
	/************************************************/
	for(count = 0; count < 10; count++)
	{
	
		if( (count == 3) || (count == 6) )
		{
			size[count] = ( *((pcData[count] ) + 8) ) & 0x000000ff;
		}
		else
		{
			size[count] = *((pcData[count] ) + 8);
		}
	
			
		PRINTF("mr_jedt2 (1) *((pcData[count] ) + 8) = %02x\n" , *((pcData[count] ) + 8)) ;
		
		PRINTF("mr_jedt2 (2) process size[%ld]" , count) ;
		
		PRINTF(" = %ld\n" , size[count]) ;
	
		PRINTF("mr_jedt2 (3) (long) ( (char *)pscparea.psccmadt - pcData[count] = %08x\n" , 
			  ( (char *)pscparea.psccmadt - pcData[count]) );
		  
//		offset[count] = ( pcData[count] - (char *)pscparea.psccmadt) & 0x00000fff;
			
		offset[count] =  ( pcData[count]  - (char *)pscparea.psccmadt ) + 0x0000000c;		
	
		PRINTF("mr_jedt2 (5) offset = %08x\n" , offset[count]);
	
	
//		tblcom = (TCOMPAT*)tadtP ;		
								/* TSRT個別部の先頭アドレスからTADTのアドレスを引く */

		PRINTF("mr_jedt2 (6) offset = %08x\n" , offset[count]);

	
		ret = mr_jedt2( 0, pcData[count], pcData[count] + 12, 0,  count ,  size[count], offset[count] ) ;
																/* 情報取得	*/
	
	}

	 PRINTF("put_jedt2 (4) ret = %ld\n" , ret ) ;

	return ;
}

/************************************************/
/* mr_trcv発行関数				1				*/
/************************************************/
#ifdef debug
void put_trcv()	
{
	TSRTPSZ	tsrt ;			/* TSRT構造体	*/
	long 	ret;
	TCOMPAT *tblcom ;
	char *tadtP ;			/* TADT先頭アドレス	*/
	char *tsrtP ;			/* TSRT先頭アドレス	*/
	char *data2 ;
	short type ;	
	long  num  ;	
	long  size  ;	
	long  offset  ;	

	/* mr_trcv発行	*/
	ret = mr_trcv() ;	/* テーブル復元	*/
	if( ret < 0 )
	{
		mr_sabt( 0x9999 , 0x04L , 0x00L , ret ) ;
	}
}
#endif
/*************************************************/
/* TABLE DUMP TOOL								*/
/*************************************************/
#ifdef debug
void TableDump( char *table_name , long size )
{
	char *tblp ;					/* テーブル個別部先頭アドレス	*/
	
	/* 更新データサイズ */
	tblP = mo_tagt( table_name )	; 		/* テーブルの先頭アドレス*/
	if( tblP == 0)
	{
		mr_sabt( 0x8888 , 0x01L , 0x00L , tblP ) ;
	}

	PRINF("TABLE TUMP START( %s\n )\n" , tbl_name );

	/* 共通部ダンプ */	
    PRINF("KYOTU-BU %s\n" , "start" );
	dump_ptr = tblP ;
	tdc_dump( dump_ptr , sizeof( TCOMPAT) ) ;

	/* サブ共通部ダンプ */
    PRINF("SUB-KYOTU-BU %s\n" , "start" );
	dump_ptr = dump_ptr + sizeof( TCOMPAT ) ;
	tdc_dump( dump_ptr , sizeof( TCOMPAT) ) ;

	/* 個別部ダンプ */
    PRINF("KOBETEUBUU-BU %s\n" , "start" );



	tblcom = (TCOMPAT*)tsrtP ;		
									/* TSRT個別部の先頭アドレスからTADTのアドレスを引く */
	offset = ( tsrtP + tblcom->tcomsbps + sizeof( TCOMPAT ) ) - tadtP ;

	PRINTF( "[10.1] tadtP = %08x\n" , tadtP ) ;
	PRINTF( "[10.2] tsrtP = %08x\n" , tsrtP ) ;
	PRINTF( "[10.3] tcomsbps = %d\n" , tblcom->tcomsbps ) ;
	PRINTF( "[10.4] TCOMPAT size = %d\n" , sizeof( TCOMPAT ) ) ;
	PRINTF( "[10.5] offset = %d\n" , offset ) ;

	/************************************************/
	/* 現在のテーブルをダンプ		 				*/
	/************************************************/
	PRINTF( "[11.0] TSRT(PRE) DUMP %d\n" , 1 );
	tdc_dump( tsrtP , sizeof( TCOMPAT ) + tblcom->tcomsbps + sizeof( TSRTPSZ ) );

	/************************************************/
	/* mr_jedt2を発行				 				*/
	/************************************************/
	ret = mr_jedt2( type , "TSRT" , (char*)&tsrt.tsrtdvst , data2 , num , size , offset ) ;	/* 情報取得	*/

	if( ret < 0 )
	{
		mr_sabt( 0x9999 , 0x03L , 0x00L , ret ) ;
	}
	long ret ;
	TSRTPSZ	*tsrt ;			/* TSRT個別部構造体	*/
 

	/************************************************/
	/* テーブル復元後のダンプ		 				*/
	/************************************************/
	PRINTF( "[12.0] TSRT(END) DUMP %d\n" , 1 );
	tdc_dump( tsrtP , sizeof( TCOMPAT ) + tblcom->tcomsbps + sizeof( TSRTPSZ ) );

	return;
}
#endif

/*************************************************/
/* テーブルダンプツール							*/
/*************************************************/
