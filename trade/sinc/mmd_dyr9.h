/**-------------------------------------------------------------------------*/
/*																			*/
/*	   正規化データﾁｪｯｸ　			 作成:94/09/01							*/
/*									 更新:94/09/16							*/
/*	96.03.19 K.Kubota ST4171: add mmd_y951()								*/
/**-------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*	   正規化データﾁｪｯｸ　定数定義											*/
/**-------------------------------------------------------------------------*/
#define	NORM	 0L
#define	ERR		-1L
#define	EOD		 0L
#define	EOF		 1L

#define	FLAGS	 0x001FFFFF
#define	FORG	 0x00000001
#define	RORG	 0x00000003
#define	METHOD	 0x00000001

#define	FIRST	 1L
#define	NEXT	 2L

#define	ROPEN	 0x00000001
#define	WOPEN	 0x00000002
#define	READ	 0x00000003
#define	WRITE	 0x00000004
#define	CLOSE	 0x00000005

#define	ALLOC  1L
#define	FREE   2L

/* 正規化データ(差分)レコード種別 */
#define	RKB10  			0x10
#define	RKB20  			0x20
#define	RKB30  			0x30
#define	RKB40  			0x40
#define	RKB51  			0x51
#define	RKB52  			0x52
#define	RKB61  			0x61
#define	RKB62  			0x62
#define	RKB70  			0x70
#define	RKB80  			0x80
#define	RKBA0  			0xA0


#ifndef PBUFSIZE
#define	PBUFSIZE	1024				/* POOLBUF for CARD/NRMD			*/
#define	PINXSIZE	4096				/* POOLBUF for INDEX AREA			*/
#endif

#define MSG_FTAM		0x4654414D		/* "FTAM"							*/
#define MSG_FNA			0x464E4120      /* "FNA "							*/
#define MSG_ICP			0x49435020      /* "ICP "							*/
#define MSG_DYR0		0x44595230		/* "DYR0" PU0動的ﾌﾟﾛｾｽ				*/
#define MSG_DYR1        0x44595231      /* "DYR1" PU1動的ﾌﾟﾛｾｽ				*/
#define MSG_AP			0x41502020		/* "AP  "							*/

long					mmd_y200 ( ) ;
long					mmd_y210 ( ) ;
long					mmd_y220 ( ) ;
long					mmd_y500 ( ) ;
void					mmd_y501 ( ) ;
void					mmd_y502 ( ) ;
long					mmd_y951 ( ) ;	/* ###ST4171						*/
long					mmd_y911 ( ) ;
long					mmd_y913 ( ) ;
long					mmd_y914 ( ) ;
long					mmd_y915 ( ) ;
long					mmd_y916 ( ) ;
void					mmd_y917 ( ) ;
long					mmd_y918 ( ) ;
