/**-------------------------------------------------------------------------*/
/*																			*/
/*	   正規化データ作成　			 作成:94/09/01							*/
/*									 更新:94/09/16							*/
/*		95.07.03 K.Kubota SSCY0069: ISDN回線生成方式変更					*/
/*	96.03.19 K.Kubota ST4171: add mmd_y951()								*/
/*	96.12.11 S.Miyawaki ST4627 add mmd_y205()								*/
/*	97.02.09 K.Kubota ST4651: add NRKB??									*/
/*	03.04.25 サプライ：岩下 MD001:Linux移植に伴う修正						*/
/*								  正規化レコード通番を修正					*/
/**-------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*	   正規化データ作成　定数定義											*/
/**-------------------------------------------------------------------------*/
#define	METHOD	 0x00000001
#define	ROPEN	 0x00000001
#define	WOPEN	 0x00000002
#define	READ	 0x00000003
#define	WRITE	 0x00000004
#define	CLOSE	 0x00000005
#define	BCLOSE	 0x00000015

#define	FLAGS	 0x001FFFFF
#define	FORG	 0x00000001
#define	RORG	 0x00000003

#define	PROTFNA	 0x09
#define	PROTFTAM 0x00

#define	HOST	 1L
#define	IO		 2L
#define	HSD		 0x01
#define	INHOUSE	 0x02
#define	LAN		 0x07
#define	PROT4W	 0x02
#define	HDLCLOOP 0x03

#define	FIRST	 1L
#define	NEXT	 2L
#define	LAST	 3L

#define	ERR		-1L
#define	NORM	 0L
#define	EOD		 0L
#define	EOF		 1L
#define	POS		 3L
#define	SP		' '
#define	NULL	 0x00
#define	FF		 0xFF
#define	MAXPKGN	  61L
#define	ISDN	   1L
#define	LGLNNO	 0xFFFF
#define	DTELEN					0x14L
#define	DTEEXLEN				0x30L
#define	ADEXLEN					0x30L
#define	REMOTE	 0x10

#define	RKB10  0x10
#define	RKB20  0x20
#define	RKB30  0x30
#define	RKB40  0x40
#define	RKB51  0x51
#define	RKB61  0x61
#define	RKB70  0x70
#define	RKB80  0x80
#define	RKB90  0x90
#define	RKBA0  0xA0

/* 正規化データ種別通番	###ST4651 start */
// MD001 start
//#define	NRKB10  0
//#define	NRKB20  1
//#define	NRKB30  2
//#define	NRKB40  3
//#define	NRKB51  4
//#define	NRKB61  5
//#define	NRKB70  6
//#define	NRKB80  7
//#define	NRKB90  8
//#define	NRKBA0  9

#define	NRKB30  0
#define	NRKB40  1
#define	NRKB61  2
#define	NRKB70  3
#define	NRKB80  4
#define	NRKB90  5
// MD001 end

/* ###ST4651 end	*/

#define	ALLOC  1L
#define	FREE   2L

#define	MSG01  1L
#define	MSG02  2L
#define	MSG03  3L

#ifndef PBUFSIZE
#define	PBUFSIZE	1024
#define	PINXSIZE	4096
#define	WKAREAL		4096
#endif

long					mmd_y200 ( ) ;
long					mmd_y201 ( ) ;
long					mmd_y202 ( ) ;
long					mmd_y204 ( ) ;
long					mmd_y205 ( ) ;  /* ###ST4627					*/
long					mmd_y210 ( ) ;
long					mmd_y220 ( ) ;
long					mmd_y500 ( ) ;
void					mmd_y501 ( ) ;
void					mmd_y502 ( ) ;
long					mmd_y951 ( ) ;	/* ###ST4171					*/
long					mmd_y911 ( ) ;
long					mmd_y912 ( ) ;
long					mmd_y913 ( ) ;
long					mmd_y914 ( ) ;
long					mmd_y915 ( ) ;
long					mmd_y916 ( ) ;
void					mmd_y917 ( ) ;
long					mmd_y918 ( ) ;
