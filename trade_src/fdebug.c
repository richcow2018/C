// *****
// * Debugging Function.
// * Note:
// * This Function has a system of writing debugging data to a file which has process id.
// * A debugging file is created under each user home directory.
// * The process which is running on each user creates each file.
// * About Thread, it is wrtten out to one file.
// * by Fukami.
// *****

#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/time.h>
#include	<time.h>
#include	<errno.h>
#include	<varargs.h>
#include	<stdarg.h>
#include	<pthread.h>

typedef struct {
	char	acDate[43];
	char	acText[982];
} TTextFmt;

typedef union {
	char		acText[1024];
	TTextFmt	tFmt;
} TTextBuf;

void os_fdebug( FILE *stream, const char* format, ... );
void os_fwrite( int iFp, char *pcFmt, ... );
void os_memdump( char *titl, char *adr, long length, int fp );
void os_fdump( char *titl, char *adr, long length, long disp, FILE *fp );

void os_fdebug( FILE *stream, const char* format, ... )
{
	char	*pcDbgFil	= NULL;
	char	acDbgFileName[256];

	struct	timeval tTmVal;
	struct	tm		*ptTm;

	char	*fmt;
	int		iRet;
	int		iFp	= 0;
	va_list	args;
	TTextBuf	tBuf;

	sprintf( acDbgFileName ,"/tmp/dbgdmp.%d\0", getpid() );

	iFp = open( acDbgFileName, O_WRONLY | O_APPEND | O_CREAT, 0666 );
	if( -1 == iFp ) goto	end_fdebug;

	gettimeofday( &tTmVal, NULL );
	ptTm = localtime( &tTmVal.tv_sec );

	memset( tBuf.acText, '\0', sizeof( tBuf.acText ));
	sprintf( tBuf.tFmt.acDate, "TRD:%02d:%02d:%02d.%03d.%03d:PID%.8d:TID%.8d:",
		ptTm->tm_hour, ptTm->tm_min, ptTm->tm_sec, tTmVal.tv_usec / 1000, tTmVal.tv_usec % 1000,
		getpid(), pthread_self() );

	va_start( args, format );
	vsprintf( tBuf.tFmt.acText, format, args );
	va_end( args );

	iRet = lockf( iFp, F_LOCK, 0 );
	if( -1 == iRet ) goto	end_fdebug;

	iRet = write( iFp, tBuf.acText, (size_t)strlen( tBuf.acText ));
	if( -1 == iRet ) goto	end_fdebug;

	lockf( iFp , F_ULOCK , 0 );

	close( iFp );

	return;

end_fdebug:
	lockf( iFp , F_ULOCK , 0 );

	if( 0 != iFp ) close( iFp );

	return;
}

// void tol_dump(titl,adr,length,disp,fp)
// DbgDmp02( DLv04, ("ptEbpc", (long)ptEtrd + (ptEtrd->tTrdEPBC.lRAdr)

void os_fwrite( int iFp, char *pcFmt, ... )
{
	char	acBuff[1024];
	int		iRet;
	va_list	args;

	va_start( args, pcFmt );
	vsprintf( acBuff, pcFmt, args );
	va_end( args );

	iRet = write( iFp, acBuff, (size_t)strlen( acBuff ));

	return;
}

void os_memdump( char *titl, char *adr, long length, int fp )
{
	char	acBuf[1024];
	long	cnt;
	long	cnt2;
	long	amari;
	struct	timeval tTmVal;
	struct	tm		*ptTm;

	gettimeofday( &tTmVal, NULL );
	ptTm = localtime( &tTmVal.tv_sec );

	os_fwrite( fp, "TRD:DumpStart:%02d:%02d:%02d Address:%p\n",
		ptTm->tm_hour, ptTm->tm_min, ptTm->tm_sec, adr );
	os_fwrite( fp, "TRD:%s\n", titl );
	os_fwrite( fp, "TRD:       0 1 2 3  4 5 6 7  8 9 a b  c d e f  /0123456789abcdef/\n");

	amari	= 0;

	for( cnt = 0 ; cnt < length;cnt++ ) {
		if( cnt % 16 == 0 ) os_fwrite( fp, "TRD:%04lx :",cnt & 0xfffffff0);

		if(cnt % 4 == 0) os_fwrite( fp, " " );

		os_fwrite( fp, "%02x", (*adr) & 0xff );

		if((cnt % 16) == 15) {
			os_fwrite( fp, "  " );
			for(cnt2 = 15;cnt2 >=0;cnt2--) {
				if( isalnum( *(adr-cnt2) ))
						os_fwrite( fp, "%c", *(adr-cnt2) );
				else 	os_fwrite( fp, "." );
			}
			os_fwrite( fp, "\n" );
		}
		adr++;
	}
	amari	= cnt % 16;
	while(( cnt % 16 ))
	{
		if( cnt % 4 == 0 ) os_fwrite( fp, " " );

		os_fwrite( fp, "  " );

		if((cnt % 16) == 15) {
			os_fwrite( fp, "  " );
			adr -= 15;

			for(cnt2 = 0;cnt2 < amari;cnt2++) {
				if( isalnum( *(adr-cnt2) ))
						os_fwrite( fp, "%c", *adr );
				else	os_fwrite( fp, "." );
				adr++;
			}
			os_fwrite( fp, "\n" );
		}
		adr ++;
		cnt ++;
	}

	os_fwrite( fp, "TRD:DumpEnd\n" );
}

void os_fdump( char *titl, char *adr, long length, long disp, FILE *fp )
{
	char	*pcDbgFil	= NULL;
	char	acDbgFileName[256];

	int		iRet;
	int		iFp	= 0;

	sprintf( acDbgFileName ,"/tmp/dbgdmp.%d\0", getpid() );

	iFp = open( acDbgFileName, O_WRONLY | O_APPEND | O_CREAT, 0666 );
	if( -1 == iFp ) goto	end_fdump;

	iRet = lockf( iFp, F_LOCK, 0 );
	if( -1 == iRet ) goto	end_fdump;

	os_memdump( titl, adr, length, iFp );

	lockf( iFp , F_ULOCK , 0 );

	close( iFp );

	return;

end_fdump:
	pcDbgFil			= NULL;
	acDbgFileName[0]	= '\0';

	lockf( iFp , F_ULOCK , 0 );

	if( 0 != iFp ) close( iFp );

	return;
}
