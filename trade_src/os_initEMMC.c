/************************************************************************************************/
/*	���	��������							                               					*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 ���̴ؿ�													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �أأأأأأ�												*/
/* ��⥸�塼��ɣġ�				 os_initEMMC												*/
/* ��⥸�塼�����֡�																			*/
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��					 ���ѥ�����													*/
/* ��Ŭ�ѣϣӡ� 					 �̣����� 												*/
/* �㳫ȯ�Ķ��� 					 �ңȣ��ӣ�����												*/
/* �㵭�Ҹ���� 					 �ø��� 													*/
/* ��⥸�塼����֡�				 �ؿ�														*/
/* �㵡ǽ��ʬ�� 																				*/
/* ���оݥǡ�����																				*/
/* �㹩�������ض�ʬ��																			*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��				 �̣��̣�ݣӣͣХ����ƥ�									*/
/* �㳫ȯ�����ƥ��ֹ�� 			 �УУ����£�����������										*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)			    	*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô��										*/
/* ���߷�ǯ������					 ��������ǯ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)						*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*  ��å����������ơ��֥�ν������»ܤ���                                                    */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_initEMMC.h>																*/
/*																								*/
/*	   	long	os_initEMMC(char *pcEmmcTableAdr)												*/
/*																								*/
/* �㲾������																					*/
/*      char *pcEmmcTablAdr     ��å����������ơ��֥���Ƭ���ɥ쥹                              */
/*																								*/
/* ���ֵ��͡�																					*/
/*      ���������  NORMAL                                                                      */
/*      �۾������  OSERREMMC                                                                   */
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*  os_initSystem�ؿ���ǤΤ߻��Ѳ�ǽ�Ȥ���                                                     */
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include	<stdio.h>			// fopen, fread, fclose, fgets
#include	<stdlib.h>			// calloc, free
#include	<string.h>			// strcpy, strtok
#include	<sys/types.h>		// stat
#include	<sys/stat.h>		// stat
#include	<unistd.h>			// stat
#include	<errno.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "os_initEXXX.h"
#include "os_initEXXX_ins.h"
// EMMC�ν����
long os_initEMMC( char *pcEmmcTableAdr )
{
	long	lRet = 0;
	long os_MainEMMC( void );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_initEMMC\n") );		// ������ǧ
	if( NULL == pcEmmcTableAdr ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_initEMMC\n") );
		return( OSERRARG );
	}
	
	ptEmmc = (TEmmcTable *)pcEmmcTableAdr;

	lRet	= os_MainEMMC(  );
	if(NORMAL != lRet)
	{
		return(OSERREMMC);
	}
	
//	DbgDmp02( DLv04, ("ptEmmc   �����", ptEmmc, sizeof(TEmmcTable),1,0));
//	DbgDmp02( DLv04, ("ptEmmcInd�����", ptEmmc->ptConAdr, (sizeof(TEmmcTableInd) * 40),1,0));
//	DbgDmp02( DLv04, ("ptEmmcInd�����", ptEmmc->ptLogAdr, (sizeof(TEmmcTableInd) * 40),1,0));
//	DbgDmp02( DLv04, ("ptEmmcInd�����", ptEmmc->ptProcAdr, (sizeof(TEmmcTableInd) * 40),1,0));
	
	DbgMsg01( DLv02, ( OutPut, "***** End os_initEMMC\n") );

	return( lRet );		// ���̤�����ֵ��ͤ򤽤Τޤ��ֵѤ��롣
}

/****************************************************/
/*   ��ͭ������ɬ�פ�EMMC�Υ��������̤���롣 */
/****************************************************/
long os_getEmmcSize( long *lSize )
// long *lSize  ����ֵ��襢�ɥ쥹
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// �ե�����̾������SGKey
	long	i				= 0;
	long	lRet			= 0;
	TFileInfo	tBufInfo[ 3 ];												// �ƥե��������
//	TEmmcInfo	iInfo;
	
	DbgMsg01( DLv02, ( OutPut, "***** Start os_getEmmcSize\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	
//	tBufInfo->lSize = sizeof( TEmmcTable );	// �������Υ�������û����롣
	*lSize = sizeof( TEmmcTable );	// �������Υ�������û����롣
	if(NULL == lSize)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_getEmmcSize\n") );
		return( OSERRARG );					//�����۾���ֵ�
	}

	for( i = 0 ; i < 3 ; i++ ){
		lRet = os_getFileInfo( pcMsgFileName[ i ], &tBufInfo[ i ] );
		if( NORMAL != lRet ){
			DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_getEmmcSize\n") );
			return( OSERREMMC );
		}
		
//		DbgMsg01( DLv04, ( OutPut, "***** tBufInfo[ i ].lLine :%ld\n", tBufInfo[ i ].lLine));
//		DbgMsg01( DLv04, ( OutPut, "***** tBufInfo[ i ].lSize :%ld\n", tBufInfo[ i ].lSize));
		*lSize
			+= ( tBufInfo[ i ].lSize + ( tBufInfo[ i ].lLine + 1 ) * ( sizeof( TEmmcTableInd )));
			// 1MSG��ɬ�פʴ�������ʬ���ΰ���ɲä����ͤ򻻽Ф��롣+1�Ͻ�ü�����ѡ�
//		DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	}

//	DbgMsg01( DLv04, ( OutPut, "***** lSize :%ld\n", *lSize));
	DbgMsg01( DLv02, ( OutPut, "***** End os_getEmmcSize\n") );

	return( NORMAL );
}
/**************************/
/*   EMMC�ν�����μ���� */
/**************************/
long os_MainEMMC( void )
{
	long	lRet = 0;
	long os_setEmmcMng( void );
	long os_setEmmcInd( void );
	
	lRet = os_setEmmcMng(  );	// ������������
	if( NORMAL != lRet ){
		return( lRet );
	}

	lRet = os_setEmmcInd(  );
	if( NORMAL != lRet ){
		return( lRet );
	}

	return( NORMAL );
}

/**************************/
/*    ������������        */
/**************************/
long os_setEmmcMng( void )
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// �ե�����̾������SGKey
	long	lRet			= 0;
	long	i				= 0;
	long	j				= 0;
	long	lHead			= 0;
	long	*palLine[ 3 ];
	long	lLen			= 0;
	long	lSize			= 0;
	long	lHsize			= 0;

	TEmmcTableInd	**patEmmcInd[ 3 ];
	TFileInfo		tInfo[ 3 ];
	long os_getFileInfo( const char *pcFileSgId, TFileInfo *tInfo  );
	
	DbgMsg01( DLv02, ( OutPut, "***** Start os_setEmmcMng\n") );

	palLine[ 0 ]	= &(ptEmmc->lConCnt);	// �����󥿤�����
	palLine[ 1 ]	= &(ptEmmc->lLogCnt);	//
	palLine[ 2 ]	= &(ptEmmc->lProcCnt);	//

	patEmmcInd[ 0 ]	= (TEmmcTableInd **)&(ptEmmc->ptConAdr);		// ���ɥ쥹������
	patEmmcInd[ 1 ]	= (TEmmcTableInd **)&(ptEmmc->ptLogAdr);		//
	patEmmcInd[ 2 ]	= (TEmmcTableInd **)&(ptEmmc->ptProcAdr);		//

	lHead = (long)(ptEmmc + 1);// ��������Ƭ���ɥ쥹

	strncpy( ptEmmc->acTid, D_EMMC_TID, 4 );
//	DbgMsg01( DLv04, ( OutPut, "***** ptEmmc->acTid : %s\n", ptEmmc->acTid) );

	for( i = 0 ; i < 3 ; i++ )
	{
		lRet	= os_getFileInfo( pcMsgFileName[ i ], &tInfo[ i ]  );
		if( NORMAL != lRet )
		{
			DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_setEmmcMng\n"));
			return(lRet);
		}
		
		*(palLine[ i ])	= tInfo[ i ].lLine;
		j = ( i - 1 ) < 0 ? 0 : ( i - 1 );	// i���1���������ͤ���롣�ޥ��ʥ��λ���0����Ȥ��롣
		lLen = *(palLine[ j ]);
		lSize = (tInfo[ j ].lSize);
		lHsize = (long)( *(patEmmcInd[ j ]) );
		if(0 == i)
		{
			lLen = 0;
			lSize = 0;
			lHsize = lHead;
		}
		
		if(0 != lLen)
		{
			lLen += 1;							// �����������������ʬ�ɲ�20030106�ɲ�
		}
		
		*(patEmmcInd[ i ]) = (TEmmcTableInd *)(lHsize + lSize + lLen * sizeof( TEmmcTableInd ) );
//		DbgMsg01( DLv04, ( OutPut, "***** patEmmcInd[ %ld ]:%p\n", i, *(patEmmcInd[ i ]) ));
		
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setEmmcMng\n") );
	return( NORMAL );
}

/**************************/
/*    ������������        */
/**************************/
long os_setEmmcInd( void )
{
	char	*pcMsgFileName[] = { D_MSGFILE01, D_MSGFILE02, D_MSGFILE03 };	// �ե�����̾������SGKey
	long			*palTableLine[ 3 ];
	TEmmcTableInd	*patEmmcInd[ 3 ];
	long i;
	long lRet;
	long os_setMsg( const char *pcFileSgId, TEmmcTableInd *ptEmmcInd, long lLine );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_setEmmcInd\n") );
	patEmmcInd[ 0 ]	= (TEmmcTableInd *)(ptEmmc->ptConAdr);			// ���ɥ쥹������
	patEmmcInd[ 1 ]	= (TEmmcTableInd *)(ptEmmc->ptLogAdr);			//
	patEmmcInd[ 2 ]	= (TEmmcTableInd *)(ptEmmc->ptProcAdr);		//

	palTableLine[ 0 ]	= &(ptEmmc->lConCnt );	// �����󥿤�����
	palTableLine[ 1 ]	= &(ptEmmc->lLogCnt );	//
	palTableLine[ 2 ]	= &(ptEmmc->lProcCnt);	//

	for( i = 0 ; i < 3 ; i++ ){
//		DbgMsg01( DLv04, ( OutPut, "***** patEmmcInd[%ld]:%08lx\n", i, patEmmcInd[ i ]));
//		DbgMsg01( DLv04, ( OutPut, "***** palTableLine[%ld]:%ld\n", i, *(palTableLine[ i ]) ));

		lRet = os_setMsg( pcMsgFileName[ i ], patEmmcInd[ i ], *palTableLine[ i ] );
		if( NORMAL != lRet ){
			DbgMsg01( DLv05, ( OutPut, "***** Err:05 os_initEMMC\n"));
			return( lRet );
		}
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setEmmcInd\n") );
	return( NORMAL );
}
/************************************************/
/*  GS�ǻ��ꤵ��Ƥ���ե�����ξ����������롣*/
/************************************************/
long os_getFileInfo( const char *pcFileSgId, TFileInfo *tInfo  )
// const char *pcFileSgId SGKey
// TFileInfo *tInfo ����ֵ��ѹ�¤��
{
	char	acFileName[ 256 ];
	long	lRet = 0;
	long	lTemp = 0;
	struct	stat tBuf;
	long os_getFileLine( const char *pcFileName, const long lSize );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_getFileInfo\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** pcFileSgId:%s\n", pcFileSgId));

	lRet = os_getSG( (char *)pcFileSgId, acFileName );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:03 os_getFileInfo\n") );
		return( OSERRSG );
	}
//	DbgMsg01( DLv04, ( OutPut, "***** getSG:%s\n", acFileName));

	lRet = stat( acFileName, &tBuf );			// �ե�����ξ��֤䥵�����μ���
	if( -1 == lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:04 os_getFileInfo:%s\n", strerror(errno)) );
		return( OSERRFILE );
	}

	tInfo->lSize = ((tBuf.st_size + 15) / 16) * 16;	//�ɤ߹��ߥǡ����ΥХ������Ĵ��
	
//	DbgMsg01( DLv04, ( OutPut, "***** tInfo->lSize :%ld\n", tInfo->lSize));
	
	tInfo->lLine = os_getFileLine( acFileName, tBuf.st_size );
	if( 0 == tInfo->lLine ){					// �ֵ��ͤ���λ��ϼ��Ԥΰ�
		DbgMsg01( DLv05, ( OutPut, "***** Err:08 os_initEMMC\n") );
		return( OSERRFILE );
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_getFileInfo\n") );
	return( NORMAL );
}

/**************************/
/*   ��å������γ�Ǽ     */
/**************************/
long os_setMsg( const char *pcFileSgId, TEmmcTableInd *ptEmmcInd, long lLine )
// const char *pcFileSgId SGKey
// TEmmcTableInd *ptEmmcInd ������������Ƭ���ɥ쥹
// long lLine �ɤ߹��ߥե�����Կ�
{
	long	i				= 0;
	long	lRet			= 0;
	long	lBuadr			= 0;
	char	*pcMsgAdr		= NULL;
	char	*pcSearchStr	= NULL;
	char	*pcHitStr		= NULL;
	long os_ReadFile( const char *pcFileSgId, char *pcBuf );

	DbgMsg01( DLv02, ( OutPut, "***** Start os_setMsg\n") );
	pcMsgAdr = (char *)( ptEmmcInd + lLine + 1 );	// ��å�������Ǽ������ꤹ�롣

	lRet = os_ReadFile( pcFileSgId, pcMsgAdr );
	if(NORMAL != lRet)
	{
		return( lRet );
	}

	pcSearchStr	= pcMsgAdr;							// ������
	pcHitStr	= pcMsgAdr;							// ������̳�Ǽ
	
//	DbgMsg01( DLv04, ( OutPut, "***** pcSearchStr :%08lx\n", pcSearchStr));
//	DbgMsg01( DLv04, ( OutPut, "***** pcHitStr    :%08lx\n", pcHitStr));
//	DbgMsg01( DLv04, ( OutPut, "***** pcHitStr    :\n%s\n", pcHitStr));
	
	for( i = 0 ; i < lLine ; i++ )
	{
		pcHitStr	= strtok( pcSearchStr, D_LF );	// ���ԥ����ɤ��Ȥ��ڤ�Ф��Ƴ�Ǽ����
		pcSearchStr	= NULL;							// 2���ܰʹߤ�NULL���Ǽ���롣
		if( NULL == pcHitStr )
			break;
		
		(ptEmmcInd+i)->pcFormatAdr	= pcHitStr;
		strncpy( (ptEmmcInd+i)->acMsgID, pcHitStr + D_MSGID_POS, D_MSGID_SIZE );

//		DbgMsg01( DLv04, ( OutPut, "***** ptEmmcInd + %d:%lx\n", i, ptEmmcInd+i));
//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->acMsgID :%c%c%c%c\n", i,
//		(ptEmmcInd+i)->acMsgID[0], (ptEmmcInd+i)->acMsgID[1], (ptEmmcInd+i)->acMsgID[2], (ptEmmcInd+i)->acMsgID[3] ));

//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->pcFormatAdr:%08lx\n", i, (ptEmmcInd+i)->pcFormatAdr));
//		DbgMsg01( DLv04, ( OutPut, "***** (ptEmmcInd+%ld)->pcFormatAdr:%s\n\n", i, (ptEmmcInd+i)->pcFormatAdr));
	}

	DbgMsg01( DLv02, ( OutPut, "***** End os_setMsg\n") );
	return( NORMAL );
}
/**************************/
/*  �ե��������Ƥ��ɹ�    */
/**************************/
long os_ReadFile( const char *pcFileSgId, char *pcBuf )
// const char *pcFileSgId  SGKey
// char *pcBuf  �ɤ߽Ф��ǡ�����Ǽ���ɥ쥹
{
	char		acFileName[ 256 ];
	long		lRet	= 0;
	TFileInfo	tInfo;
	FILE		*fp = NULL;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_ReadFile\n") );
	lRet	= os_getFileInfo( pcFileSgId, &tInfo );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_ReadFile\n"));
		goto err_os_ReadFile;
	}

	lRet	= os_getSG( (char *)pcFileSgId, acFileName );
	if( NORMAL != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_ReadFile\n"));
		goto err_os_ReadFile;
	}

	fp	= fopen( acFileName, D_MODE_R );
//	DbgMsg01( DLv04, ( OutPut, "***** fp:%lx\n", fp));
	if(NULL == fp)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:03 os_ReadFile\n"));
		goto err_os_ReadFile;
	}
	
	clearerr( fp );
	lRet = fread( pcBuf, sizeof( char ), tInfo.lSize, fp );
	lRet = ferror( fp );
	if( 0 != lRet ){
		DbgMsg01( DLv05, ( OutPut, "***** Err:04 os_ReadFile\n"));
		fclose( fp );
		goto err_os_ReadFile;
	}

	lRet = fclose( fp );
	if( EOF == lRet)
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:05 os_ReadFile\n"));
		goto err_os_ReadFile;
	}
	

	DbgMsg01( DLv02, ( OutPut, "***** End os_ReadFile\n") );
	return( NORMAL );

	err_os_ReadFile:
		return( OSERRFILE );
}

/******************************/
/*  �ե�����ιԿ���������롣*/
/******************************/
long os_getFileLine( const char *pcFileName, const long lSize )
// const char *pcFileName  �оݥե�����Υѥ�
// const long lSize  �����ե�����ιԿ�
{
	char	*pcBuf	= NULL; 
	long	i		= 0;
	long	lCnt	= 0;
	long	lRet	= 0;
	size_t	size	= 0;
	FILE	*fp		=NULL;

	DbgMsg01( DLv02, ( OutPut, "***** Start os_getFileLine\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** pcFileName:%s\n", pcFileName));
	
	fp	= fopen( pcFileName, D_MODE_R );
	if( NULL == fp )
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:01 os_getFileLine\n") );
		goto end_os_getFileSize;
	}

	pcBuf	= calloc( lSize, sizeof( char ));

	clearerr( fp );
	size	= fread( pcBuf, sizeof( char ), lSize, fp );
	lRet	= ferror( fp );
	if( 0 != lRet )
	{
		DbgMsg01( DLv05, ( OutPut, "***** Err:02 os_getFileLine\n") );
		goto end_os_getFileSize;
	}

	for( i = 0 ; i < lSize ; i++ )
	{
		if( '\n' == *(pcBuf+i) )
			lCnt++;	// D_LF�ο��������=�Կ��η׾�
	}
	
	if(0 != lCnt)
		lCnt-=1;								// ��ü�Ԥ�;ʬ�ʤΤ�1����

	end_os_getFileSize:

		if( NULL != pcBuf ){
			free( pcBuf );
			pcBuf = NULL;
		}

		fclose( fp );

//		DbgMsg01( DLv05, ( OutPut, "***** lCnt:%ld\n", lCnt));
		DbgMsg01( DLv02, ( OutPut, "***** End os_getFileLine\n") );
		return( lCnt );
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
