#define CL_ENTRYEVENTL			0x00ff8730
#define CL_EXITEVENTL			0x00ff8731
#define CL_ENTRYEVENTP			0x00ff8740
#define CL_EXITEVENTP			0x00ff8741
#define CL_ENTRYEVENTC			0x00ff8750
#define CL_EXITEVENTC			0x00ff8751
#define POF_MKCODE			0

#define POF_SENDPROCESS		32
#define POF_IFCODE			88

#define POF_COMMON1			4			/* 共通部４〜						*/
#define POF_SENDMAIL		8			/* 発信元ＭＢＩＤ（送信側メール）	*/
#define POF_RCVMAIL			12			/* 送信元ＭＢＩＤ（受信側メール）	*/
#define POF_COMMON4			16			/* 共通部１６〜						*/
#define POF_COMMON5			20			/* 共通部２０〜						*/
#define POF_COMMON6			24			/* 共通部２４〜						*/
#define POF_COMMON7			28			/* 共通部２８〜						*/
#define POF_COMMAND0		32			/* 要求・応答電文の３２〜			*/
#define POF_COMMAND1		36			/* 要求・応答電文の３６〜			*/

typedef	struct {
	char	pnm[8];						/* 送信元メールボックス識別子		*/
	long	mkcd;						/* コマンドコード					*/
	long	ifcd;						/* インタフェースコード				*/
	long	msgsize;					/* メッセージ長サイズ				*/
} MMSGTR;								/* ＭＩＡ電文トレース情報			*/\

#define PLOG_RDDT(P1, P2)				/* Pﾄﾚｰｽ取得（非完了型の読込の完了）*/\
	mc_loga(CL_RDDT, P1, P2)
#define PLOG_WTDT(P1, P2)				/* Pﾄﾚｰｽ取得（書込要求の前）		*/\
	mc_loga(CL_WTDT, P1, P2)
#define PLOG_RVNTFY(P1, P2)				/* Pﾄﾚｰｽ取得（OSからの非同期通知受	*/\
										/* 信時）							*/\
	mc_loga(CL_RVNTFY, P1, P2)

#define PLOG_RVCMMSG(P1, P2)			/* Pﾄﾚｰｽ取得（通信制御要求／応答電文*/\
										/* 受信時）							*/\
	mc_logv(																  \
		CL_RVCMMSG,															  \
		7, 													  				  \
		*(long *)((long)P2 + POF_RCVMAIL),			  						  \
		*(long *)((long)P2 + POF_COMMON7),									  \
		*(long *)((long)P2 + POF_COMMAND0),									  \
		*(long *)((long)P2 + POF_COMMAND1),									  \
		*(long *)((long)P2 + POF_SENDMAIL),			  						  \
		*(long *)(long)P2 + POF_MKCODE,										  \
		(long)P1															  \
	)
										/* Ｐトレース取得					*/
										/*   通信制御要求応答電文受信時ログ	*/
										/*   ログ取得情報数が以下の５つ		*/
										/*   送信元メールボックスｉｄ		*/
										/*   共通部２８〜３１バイト			*/
										/*   コマンド部先頭から４バイト		*/
										/*   コマンド部４〜７バイト			*/
										/*   ＭＫコード						*/
										/*   発信元メールボックスｉｄ		*/
										/*   受信電文長						*/
#define PLOG_RVMIAMSG(P1, P2)			/* Pﾄﾚｰｽ取得（ＭＩＡ電文受信時）	*/\
{																			  \
	MMSGTR	mmsgtr;						/* ＭＩＡ電文トレース情報			*/\
	int i;								/* ループカウンタ					*/\
	for( i = 0; i < 8; i++)				/* 送信元プロセス識別名を取り出す	*/\
	{																		  \
		mmsgtr.pnm[i] = *(char *)((long)P2 + POF_SENDPROCESS + i);			  \
										/* １オクテットスずつ取り出す		*/\
	}																		  \
	mmsgtr.mkcd = *(long *)((long)P2 + POF_MKCODE);							  \
										/* ＭＫコードを取り出す				*/\
	mmsgtr.ifcd = *(long *)((long)P2 + POF_IFCODE);							  \
										/* インタフェースコードを取り出す	*/\
	mmsgtr.msgsize = P1;				/* メッセージ長を取り出す			*/\
	mc_loga(																  \
		CL_RVMIAMSG,														  \
		sizeof(MMSGTR), 													  \
		&mmsgtr																  \
	);																		  \
										/* Ｐトレース取得					*/\
										/*   ＭＩＡ電文受信のログ			*/\
										/*   ＭＩＡ電文トレース情報のサイズ	*/\
										/*   ＭＩＡ電文トレース情報の格納域	*/\
										/*   受信電文長						*/\
}
#define PLOG_SDCMMSG(P1, P2)			/* Pﾄﾚｰｽ取得（通信制御要求／応答電文*/\
										/* 送信時）							*/\
	mc_logv(																  \
		CL_SDCMMSG,															  \
		7, 													  				  \
		*(long *)((long)P2 + POF_RCVMAIL),			  						  \
		*(long *)((long)P2 + POF_COMMON7),									  \
		*(long *)((long)P2 + POF_COMMAND0),									  \
		*(long *)((long)P2 + POF_COMMAND1),									  \
		*(long *)((long)P2 + POF_SENDMAIL),			  						  \
		*(long *)(long)P2 + POF_MKCODE,										  \
		(long)P1															  \
	)
										/* Ｐトレース取得					*/
										/*   通信制御要求応答電文送信時ログ	*/
										/*   ログ取得情報数が以下の５つ		*/
										/*   送信元メールボックスｉｄ		*/
										/*   共通部２８〜３１バイト			*/
										/*   コマンド部先頭から４バイト		*/
										/*   コマンド部４〜７バイト			*/
										/*   発信元メールボックスｉｄ		*/
										/*   ＭＫコード						*/
										/*   メッセージ長					*/
#define PLOGUPDATECONN
#define PLOGUPDATELINE
#define PLOGUPDATEPATH
#define PLOGENTRYEVENTL(MODID, LINECTXP, IRBP)								  \
	mc_logv(																  \
		CL_ENTRYEVENTL,														  \
		11, 												  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)IRBP + 12),					  						  \
		*(long *)((long)IRBP + 16),											  \
		*(long *)((long)IRBP + 20),											  \
		*(long *)((long)IRBP + 24),											  \
		*(long *)((long)IRBP + 28),			  								  \
		*(long *)((long)LINECTXP + 12),										  \
		*(long *)((long)LINECTXP + 16),										  \
		*(long *)((long)LINECTXP + 20),										  \
		*(long *)((long)LINECTXP + 24),										  \
		*(long *)((long)LINECTXP + 28)										  \
		)
#define PLOGEXITEVENTL(MODID, LINECTXP)										  \
	mc_logv(																  \
		CL_EXITEVENTL,														  \
		6, 													  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)LINECTXP + 12),										  \
		*(long *)((long)LINECTXP + 16),										  \
		*(long *)((long)LINECTXP + 20),										  \
		*(long *)((long)LINECTXP + 24),										  \
		*(long *)((long)LINECTXP + 28)										  \
		)
#define PLOGENTRYEVENTP(MODID, PATHCTXP, IRBP)								  \
	mc_logv(																  \
		CL_ENTRYEVENTP,														  \
		11, 												  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)IRBP + 12),					  						  \
		*(long *)((long)IRBP + 16),											  \
		*(long *)((long)IRBP + 20),											  \
		*(long *)((long)IRBP + 24),											  \
		*(long *)((long)IRBP + 28),			  								  \
		*(long *)((long)PATHCTXP + 12),										  \
		*(long *)((long)PATHCTXP + 16),										  \
		*(long *)((long)PATHCTXP + 20),										  \
		*(long *)((long)PATHCTXP + 24),										  \
		*(long *)((long)PATHCTXP + 28)										  \
		)
#define PLOGEXITEVENTP(MODID, PATHCTXP)										  \
	mc_logv(																  \
		CL_EXITEVENTP,														  \
		6, 													  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)PATHCTXP + 12),										  \
		*(long *)((long)PATHCTXP + 16),										  \
		*(long *)((long)PATHCTXP + 20),										  \
		*(long *)((long)PATHCTXP + 24),										  \
		*(long *)((long)PATHCTXP + 28)										  \
		)
#define PLOGENTRYEVENTC(MODID, CONNCTXP, IRBP)								  \
	mc_logv(																  \
		CL_ENTRYEVENTC,														  \
		11, 												  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)IRBP + 12),					  						  \
		*(long *)((long)IRBP + 16),											  \
		*(long *)((long)IRBP + 20),											  \
		*(long *)((long)IRBP + 24),											  \
		*(long *)((long)IRBP + 28),			  								  \
		*(long *)((long)CONNCTXP + 12),										  \
		*(long *)((long)CONNCTXP + 16),										  \
		*(long *)((long)CONNCTXP + 20),										  \
		*(long *)((long)CONNCTXP + 24),										  \
		*(long *)((long)CONNCTXP + 28)										  \
		)
#define PLOGEXITEVENTC(MODID, CONNCTXP)										  \
	mc_logv(																  \
		CL_EXITEVENTC,														  \
		6, 													  				  \
		MID_EX + MODID,								  						  \
		*(long *)((long)CONNCTXP + 12),										  \
		*(long *)((long)CONNCTXP + 16),										  \
		*(long *)((long)CONNCTXP + 20),										  \
		*(long *)((long)CONNCTXP + 24),										  \
		*(long *)((long)CONNCTXP + 28)										  \
		)
#ifdef SI001
	#define DBGSI001(P1)	printf(P1);	/* プログラム実行開始表示用			*/
#else
	#define DBGSI001
#endif
#define SGDUMPALL(buff_addr) \
{ \
	extern void		DumpHex(); \
    DumpHex( (int)(12 + ((TCOMPAT *)buff_addr)->tcomsbps + \
        ((TCOMPAT *)buff_addr)->tcomprsl * ((TCOMPAT *)buff_addr)->tcommxno), \
    	buff_addr, ""); \
}
#define SGDUMPPSZ(buff_addr, kno) \
{ \
    unsigned char *addr; \
	extern void		DumpHex(); \
    addr = (unsigned char *)((char *)buff_addr + 12 + \
           ((TCOMPAT *)buff_addr)->tcomsbps + \
           ((TCOMPAT *)buff_addr)->tcomprsl * (kno-1)); \
    DumpHex( ((TCOMPAT *)buff_addr)->tcomprsl, addr ,""); \
} 

#ifdef SIDEBUGMODE
    #define SGDUMPCOM(P1) \
    { \
		extern void		DumpHex(); \
        printf("SGTableCommonAreaDump(P1)\n"); \
        DumpHex( sizeof(TCOMPAT), tblp[P1], ""); \
    }
    #define SGDUMPSUB(P1)													  \
    {																		  \
		extern void		DumpHex();											  \
        printf("SGTableSubAreaDump(P1)\n");									  \
        DumpHex( (int)((TCOMPAT *)tblp[P1])->tcomsbps,						  \
			(long)tblp[P1] + sizeof(TCOMPAT) ,"");							  \
    }
    #define DBGPSZDUMP(P1, P2, P3)  	/* 個別部テーブルダンプ表示			*/\
    {                                                                         \
        printf("-- %s KOBETSUBU DUMP [NO.%d]--\n", P3, P2);					  \
        SGDUMPPSZ(P1, P2);                                                    \
    }
#else
    #define DBGPSZDUMP
	#define SGDUMPCOM
	#define SGDUMPSUB
#endif

#ifdef SIDBG
    #define AREADUMP(SIZE, BUFFP, MIDASHI);									  \
    {																		  \
		extern void		DumpHex();											  \
        DumpHex( SIZE, BUFFP, MIDASHI);										  \
    }
#else
    #define AREADUMP
#endif

#ifdef SIDBG100
    #define DBGFUNCSTART(P1)    printf(P1)
                                        /* プログラム実行開始表示           */
    #define DBGFUNCEND(P1)    printf(P1)/* プログラム実行終了表示           */
    #define DBG100PRINT1(P1)  printf(P1)
    #define DBG100PRINT2(P1, P2)  printf(P1, P2)
#else
    #define DBGFUNCSTART
    #define DBGFUNCEND
    #define DBG100PRINT1
    #define DBG100PRINT2
#endif

#define DELAY(P1)	printf("Delay(%d)min.start ",P1); osdelay(P1,2); printf("End\n");

#ifdef SETDP_SVCCALL_RETCODE
    #define DISP_SVCCALL_RETCODE(P1, P2) \
	    printf("ServiceCall[%s]ReturnValue = %d,%08x\n",P1, P2, P2);
#else
    #define DISP_SVCCALL_RETCODE
#endif
#ifdef SETDP_SVCMACRO_PARAM
    #define DP_SVCMACRO_PARAM(P1, P2, P3) \
	    printf("Param%1d[%s] = %d,%08x\n",P1, P2, P3, P3);
#else
    #define DP_SVCMACRO_PARAM
#endif

#define BREAKPOINT()														  \
{																			  \
    extern long oscalldemon();												  \
    oscalldemon();															  \
}

#define BP_CALL_SYSCALL(DSIZE, DADDR, MIDASHI)								  \
										/* デバック（システムコール発行直前	*/\
										/* に行う）							*/\
{																			  \
    extern long oscalldemon();												  \
	extern void		DumpHex();												  \
	printf("BREAK POINT %s CALL\n", MIDASHI);								  \
    printf("ARGUMENT AREA DUMP (ADDR=%08x, SIZE=%d)\n", DADDR, DSIZE);        \
    DumpHex(DSIZE, DADDR, "");												  \
    oscalldemon();															  \
}
#define BP_RETURN_SVCCALL(DRESULT, DADDR, MIDASHI)							  \
{																			  \
										/* デバック（サービスコール発行直後	*/\
										/* に行う）							*/\
    extern long oscalldemon();												  \
	printf("BREAK POINT %s RESULT\n", MIDASHI);								  \
    printf("RETURN CODE = %08x, ADDR = %08x\n", DRESULT, DADDR);       		  \
    oscalldemon();															  \
}

#if defined(SETBP_CALL_SYSCALL) || defined(SETBP_CALL_ABORT)
#define BP_CALL_ABORT(P1, P2)												  \
	BP_CALL_SYSCALL((long)P1, (long)P2, "osiioctl(ABORT)")
#else
#define BP_CALL_ABORT
#endif

#if defined(SETBP_SVCCALL) || defined(SETBP_MOGABF)
    #define BP_RETURN_MOGABF(P1, P2)										  \
	    BP_RETURN_SVCCALL((long)P1, (long)P2, "mo_gabf()")
#else
    #define BP_RETURN_MOGABF
#endif

#if defined(SETBP_SVCCALL) || defined(SETBP_MCNCLR)
    #define BP_RETURN_MCNCLR(P1, P2)										  \
	    BP_RETURN_SVCCALL((long)P1, (long)P2, "mc_nclr()")
#else
    #define BP_RETURN_MCNCLR
#endif

#if defined(SETBP_SVCCALL) || defined(SETBP_MOGINF)
    #define BP_CALL_MOGINF(DSIZE, DADDR)									  \
		AREADUMP(DSIZE, DADDR, "mo_ginf() HakkouMae\n")
    #define BP_RETURN_MOGINF(DSIZE, DADDR)									  \
	{ 																		  \
		AREADUMP(DSIZE, DADDR, "mo_ginf() HakkouGo\n");					      \
    	BREAKPOINT();														  \
	}
#else
    #define BP_CALL_MOGINF
    #define BP_RETURN_MOGINF
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_SNSMS)
    #define BP_SNSMS(DSIZE, DADDR, MIDASHI)									  \
		AREADUMP(DSIZE, DADDR, MIDASHI);									  \
    	BREAKPOINT();
#else
    #define BP_SNSMS
#endif

#if defined(SETBP_TACHIAGE)
    #define BP_TACHIAGE(DSIZE, DADDR, MIDASHI)								  \
		AREADUMP(DSIZE, DADDR, MIDASHI);									  \
    	BREAKPOINT();
#else
    #define BP_TACHIAGE
#endif

#if defined(SETBP_SVCCALL) || defined(SETBP_MILSTAT)
    #define BP_RETURN_MILSTAT(P1, P2)										  \
	    BP_RETURN_SVCCALL((long)P1, (long)P2, "mi_lstat()")
#endif
#ifndef BP_RETURN_MILSTAT
    #define BP_RETURN_MILSTAT
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_OSCONN)
	#define BP_CALL_OSCONN(P1, P2)											  \
		AREADUMP(P1, P2, "osconn Param1 Dump\n")
	#define BP_RETURN_OSCONN(P1)		/* ブレークポイント					*/\
										/* （システムコール発行後）			*/\
	{																		  \
    	AREADUMP(sizeof(long), &P1, "Return Value Dump osconn\n");  		  \
		BREAKPOINT();														  \
	}
#else
	#define BP_CALL_OSCONN
	#define BP_RETURN_OSCONN
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_OSGFINF)
	#define BP_ARGDUMP_OSGFINF(P1, P2, P3)									  \
		AREADUMP(P1, P2, P3)
	#define BP_RETURN_OSGFINF(P1)		/* ブレークポイント					*/\
										/* （システムコール発行後）			*/\
	{																		  \
    	AREADUMP(sizeof(long), &P1, "Return Value Dump osgfinf\n");  		  \
		BREAKPOINT();														  \
	}
#else
	#define BP_ARGDUMP_OSGFINF
	#define BP_RETURN_OSGFINF
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_OSOPEN)
	#define BP_RETURN_OSOPEN(P1)		/* ブレークポイント					*/\
										/* （システムコール発行後）			*/\
	{																		  \
    	AREADUMP(sizeof(long), &P1, "Return Value Dump osopen\n");  		  \
		BREAKPOINT();														  \
	}
#else
	#define BP_RETURN_OSOPEN
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_SETNETMASK)
	#define BP_ARGDUMP_SETNETMASK(P1, P2, P3)								  \
		AREADUMP(P1, P2, P3)
	#define BP_RETURN_SETNETMASK(P1)	/* ブレークポイント					*/\
										/* （システムコール発行後）			*/\
	{																		  \
    	AREADUMP(sizeof(long), &P1,											  \
			"Return Value Dump osioctl(Netctl/Netmask)\n");  				  \
		BREAKPOINT();														  \
	}
#else
	#define BP_ARGDUMP_SETNETMASK
	#define BP_RETURN_SETNETMASK
#endif

#if defined(SETBP_SYSCALL) || defined(SETBP_SETLOCALADDR)
	#define BP_ARGDUMP_SETLOCALADDR(P1, P2, P3)								  \
		AREADUMP(P1, P2, P3)
	#define BP_RETURN_SETLOCALADDR(P1)	/* ブレークポイント					*/\
										/* （システムコール発行後）			*/\
	{																		  \
    	AREADUMP(sizeof(long), &P1,											  \
			"Return Value Dump osioctl(Netctl/LOCALADDR)\n");  				  \
		BREAKPOINT();														  \
	}
#else
	#define BP_ARGDUMP_SETLOCALADDR
	#define BP_RETURN_SETLOCALADDR
#endif

#if defined(SETBP_SVCCALL)
	#define DP_SVCCALL_NAME(P1) printf("ServiceCall(%s) Start\n", P1)
#endif
#ifndef DP_SVCCALL_NAME
	#define DP_SVCCALL_NAME
#endif

#ifdef SETADUMPNVT
	#define ADUMPNVT(P1, P2, P3)	AREADUMP(P1, P2, P3);
#endif

#ifndef SETADUMPNVT
	#define ADUMPNVT
#endif

#ifdef SETADUMPLINE
	#define ADUMPLINE(P1, P2, P3)	AREADUMP(P1, P2, P3);
#endif

#ifndef SETADUMPLINE
	#define ADUMPLINE
#endif

#ifdef SETADUMPPATH
	#define ADUMPPATH(P1, P2, P3)	AREADUMP(P1, P2, P3);
#endif

#ifndef SETADUMPPATH
	#define ADUMPPATH
#endif

#ifdef SETADUMPCONN
	#define ADUMPCONN(P1, P2, P3)	AREADUMP(P1, P2, P3);
#endif

#ifndef SETADUMPCONN
	#define ADUMPCONN
#endif

#ifdef SETBP_IRBDUMP
	#define BP_IRBDUMP(P1)											  \
		printf("IRB ADDRESS %08x\n",P1);							  \
    	BREAKPOINT();
#endif

#ifndef SETBP_IRBDUMP
	#define BP_IRBDUMP
#endif

#ifdef SIDUMPIRB
	#define DBG3DUMPIRB(P1) \
		AREADUMP(sizeof(MPCIRB0), P1, "IRB Dump\n");				  \
		BP_IRBDUMP(P1);
	#define DBG4DUMPIRB(P1)	\
		AREADUMP(sizeof(MPCIRB0), P1, "IRB Dump\n");				  \
		BP_IRBDUMP(P1);
	#define DBG5DUMPIRB(P1)	\
		AREADUMP(sizeof(MPCIRB0), P1, "IRB Dump\n");				  \
		BP_IRBDUMP(P1);
#endif

#ifdef SIDUMPLMB
	#define DBG3DUMPLMB(P1)	\
		AREADUMP(sizeof(MPCLMB), P1, "Line Control Context Dump\n");
#endif

#ifdef SIDUMPPMB
	#define DBG4DUMPPMB(P1)	\
		AREADUMP(sizeof(MPCPMB), P1, "Path Control Context Dump\n");
#endif

#ifdef SIDUMPCMB
	#define DBG5DUMPCMB(P1)	\
		AREADUMP(sizeof(MPCCMB), P1, "Connection Control Context Dump\n");
#endif

#ifdef SIDBG
    #define DBG3FUNCSTART(P1)    printf(P1)
                                        /* プログラム実行開始表示           */
    #define DBG3FUNCEND(P1)    printf(P1)/* プログラム実行終了表示           */
    #define DBG4FUNCSTART(P1)    printf(P1)
                                        /* プログラム実行開始表示           */
    #define DBG4FUNCEND(P1)    printf(P1)/* プログラム実行終了表示           */
    #define DBG5FUNCSTART(P1)    printf(P1)
                                        /* プログラム実行開始表示           */
    #define DBG5FUNCEND(P1)    printf(P1)/* プログラム実行終了表示           */
#endif

#ifndef DBG3DUMPIRB
	#define DBG3DUMPIRB
#endif
#ifndef DBG4DUMPIRB
	#define DBG4DUMPIRB
#endif
#ifndef DBG5DUMPIRB
	#define DBG5DUMPIRB
#endif
#ifndef DBG3DUMPLMB
	#define DBG3DUMPLMB
#endif
#ifndef DBG4DUMPPMB
	#define DBG4DUMPPMB
#endif
#ifndef DBG5DUMPCMB
	#define DBG5DUMPCMB
#endif
#ifndef DBG3FUNCSTART
    #define DBG3FUNCSTART
#endif
#ifndef DBG3FUNCEND
    #define DBG3FUNCEND
#endif
#ifndef DBG4FUNCSTART
    #define DBG4FUNCSTART
#endif
#ifndef DBG4FUNCEND
    #define DBG4FUNCEND
#endif
#ifndef DBG5FUNCSTART
    #define DBG5FUNCSTART
#endif
#ifndef DBG5FUNCEND
    #define DBG5FUNCEND
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_ATTACH)
	#define DELAY_ATTACH(P1)												  \
		printf("ATTACH ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_ATTACH
	#define DELAY_ATTACH
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_BIND)
	#define DELAY_BIND(P1)												  \
		printf("BIND ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_BIND
	#define DELAY_BIND
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_CONNECT)
	#define DELAY_CONNECT(P1)												  \
		printf("CONNECT ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_CONNECT
	#define DELAY_CONNECT
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_DETACH0)
	#define DELAY_DETACH0(P1)												  \
		printf("DETACH0 ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_DETACH0
	#define DELAY_DETACH0
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_DETACH1)
	#define DELAY_DETACH1(P1)												  \
		printf("DETACH1 ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_DETACH1
	#define DELAY_DETACH1
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_DISCONNECT)
	#define DELAY_DISCONNECT(P1)											  \
		printf("DISCONNECT ");												  \
		DELAY(P1);
#endif
#ifndef DELAY_DISCONNECT
	#define DELAY_DISCONNECT
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_LISTEN)
	#define DELAY_LISTEN(P1)												  \
		printf("LISTEN ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_LISTEN
	#define DELAY_LISTEN
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_RCVOOB)
	#define DELAY_RCVOOB(P1)												  \
		printf("RCVOOB ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_RCVOOB
	#define DELAY_RCVOOB
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_SENDOOB)
	#define DELAY_SENDOOB(P1)												  \
		printf("SENDOOB ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_SENDOOB
	#define DELAY_SENDOOB
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_SETOPT)
	#define DELAY_SETOPT(P1)												  \
		printf("SETOPT ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_SETOPT
	#define DELAY_SETOPT
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_ABORT)
	#define DELAY_ABORT(P1)												  \
		printf("ABORT ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_ABORT
	#define DELAY_ABORT
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_ACCEPT)
	#define DELAY_ACCEPT(P1)												  \
		printf("ACCEPT ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_ACCEPT
	#define DELAY_ACCEPT
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_ASYNC0)
	#define DELAY_ASYNC0(P1)												  \
		printf("ASYNC0 ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_ASYNC0
	#define DELAY_ASYNC0
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_ASYNC1)
	#define DELAY_ASYNC1(P1)												  \
		printf("ASYNC1 ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_ASYNC1
	#define DELAY_ASYNC1
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_SETNFLAG)
	#define DELAY_SETNFLAG(P1)												  \
		printf("SETNFLAG ");												  \
		DELAY(P1);
#endif
#ifndef DELAY_SETNFLAG
	#define DELAY_SETNFLAG
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_SETIPADDR)
	#define DELAY_SETIPADDR(P1)												  \
		printf("SETIPADDR ");												  \
		DELAY(P1);
#endif
#ifndef DELAY_SETIPADDR
	#define DELAY_SETIPADDR
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_SETSUBMASK)
	#define DELAY_SETSUBMASK(P1)											  \
		printf("SETSUBMASK ");												  \
		DELAY(P1);
#endif
#ifndef DELAY_SETSUBMASK
	#define DELAY_SETSUBMASK
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_TIMNFLAG)
	#define DELAY_TIMNFLAG(P1)												  \
		printf("RETRY TIMER NFLAG ");									  \
		DELAY(P1);
#endif
#ifndef DELAY_TIMNFLAG
	#define DELAY_TIMNFLAG
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_TIMIPADDR)
	#define DELAY_TIMIPADDR(P1)												  \
		printf("RETRY TIMER IPADDR ");									  \
		DELAY(P1);
#endif
#ifndef DELAY_TIMIPADDR
	#define DELAY_TIMIPADDR
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_TIMSUBMASK)
	#define DELAY_TIMSUBMASK(P1)											  \
		printf("RETRY TIMER SUBMASK ");												  \
		DELAY(P1);
#endif
#ifndef DELAY_TIMSUBMASK
	#define DELAY_TIMSUBMASK
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_READD)
	#define DELAY_READD(P1)												  \
		printf("READD ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_READD
	#define DELAY_READD
#endif

#if defined(SETDELAY_SYSCALL) || defined(SETDELAY_WRITD)
	#define DELAY_WRITD(P1)												  \
		printf("WRITD ");													  \
		DELAY(P1);
#endif
#ifndef DELAY_WRITD
	#define DELAY_WRITD
#endif

#if defined(SIDBG)
	#define DBGPRINT2_MPCMFREE(P1, P2)										  \
		printf(P1, P2)
#endif
#ifndef DBGPRINT2_MPCMFREE
	#define DBGPRINT2_MPCMFREE
#endif

#if defined(SETRDPRINT)
	#define RDPRINT(P1)										  \
		printf("RD = %08x", P1)
#endif
#ifndef RDPRINT
	#define RDPRINT
#endif
