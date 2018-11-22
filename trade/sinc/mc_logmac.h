/****************************************************************************/
/*																	        */
/*	変更履歴														        */
/*																	        */
/*	   変更者　: 宮脇　伸				'94/08/18		ST0146		        */
/*     変更者  : 田中宏之				2003/01/29　Linux化による追加(M01)	*/
/*     変更者  : supply三国淳也			2003/07/10　CORBA関数追加			*/
/*																	        */
/****************************************************************************/
/****************************************************************************/
/*	System-Call Macro when compiled without "DLOFF"							*/
/****************************************************************************/
#ifndef	LOFF
/************************************/
/*			 実行管理				*/
/************************************/
									/* ﾌﾟﾛｾｽ制御							*/
#define	C_CREPR(p1,p2,p3,p4,p5)	mc_lcif(oscrepr,CL_BSYS,CL_ASYS,5,MCEOSCREPR,p1,p2,p3,p4,p5)
#define	C_DESPR(p1,p2)		mc_lcif(osdespr,CL_BSYS,CL_ASYS,2,MCEOSDESPR,p1,p2)
#define	C_TERM(p1)			mc_lcif(osterm,CL_BSYS,CL_ASYS,1,MCEOSTERM,p1)
#define	C_RESPR(p1)			mc_lcif(osrespr,CL_BSYS,CL_ASYS,1,MCEOSRESPR,p1)
#define	C_SLEEP()			mc_lcif(ossleep,CL_BSYS,CL_ASYS,0,MCEOSSLEEP)
#define	C_WAKEUP()			mc_lcif(oswakeup,CL_BSYS,CL_ASYS,0,MCEOSWAKEUP)
#define	C_RSCHD(p1)			mc_lcif(osrschd,CL_BSYS,CL_ASYS,1,MCEOSRSCHD,p1)
#define	C_SUSPR(p1)			mc_lcif(ossuspr,CL_BSYS,CL_ASYS,1,MCEOSSUSPR,p1)
#define	C_WCHLD(p1,p2,p3)	mc_lcif(oswchld,CL_BSYS,CL_ASYS,3,MCEOSWCHLD,p1,p2,p3)
#define	C_WCHLDR(p1,p2,p3)	mc_lcif(oswchldr,CL_BSYS,CL_ASYS,3,MCEOSWCHLDR,p1,p2,p3)
#define	C_STUIC(p1)			mc_lcif(osstuic,CL_BSYS,CL_ASYS,1,MCEOSSTUIC,p1)
#define	C_STPGR(p1)			mc_lcif(osstpgr,CL_BSYS,CL_ASYS,1,MCEOSSTPGR,p1)
#define	C_CHPRI(p1)			mc_lcif(oschpri,CL_BSYS,CL_ASYS,1,MCEOSCHPRI,p1)
#define	C_CHOPRI(p1,p2)		mc_lcif(oschopri,CL_BSYS,CL_ASYS,2,MCEOSCHOPRI,p1,p2)
#define	C_GTPIN(p1,p2)		mc_lcif(osgtpin,CL_BSYS,CL_ASYS,2,MCEOSGTPIN,p1,p2)
#define	C_GTPRI()			mc_lcif(osgtpri,CL_BSYS,CL_ASYS,0,MCEOSGTPRI)
#define	C_GTOPRI(p1)		mc_lcif(osgtopri,CL_BSYS,CL_ASYS,1,MCEOSGTOPRI,p1)
#define	C_GTSTS(p1)			mc_lcif(osgtsts,CL_BSYS,CL_ASYS,1,MCEOSGTSTS,p1)
#define	C_GTUIC()			mc_lcif(osgtuic,CL_BSYS,CL_ASYS,0,MCEOSGTUIC)
#define	C_GTPGR()			mc_lcif(osgtpgr,CL_BSYS,CL_ASYS,0,MCEOSGTPGR)
#define	C_CREMPR(p1,p2,p3,p4,p5,p6)	mc_lcif(oscrempr,CL_BSYS,CL_ASYS,6,MCEOSCREMPR,p1,p2,p3,p4,p5,p6)
										/* ｲﾍﾞﾝﾄ制御						*/
#define	C_CRESP(p1,p2,p3)	mc_lcif(oscresp,CL_BSYS,CL_ASYS,3,MCEOSCRESP,p1,p2,p3)
#define	C_DELSP(p1,p2)		mc_lcif(osdelsp,CL_BSYS,CL_ASYS,2,MCEOSDELSP,p1,p2)
#define	C_WAITSP(p1,p2,p3)	mc_lcif(oswaitsp,CL_BSYS,CL_ASYS,3,MCEOSWAITSP,p1,p2,p3)
#define	C_WAITEV(p1,p2,p3)	mc_lcif(oswaitev,CL_BSYS,CL_ASYS,3,MCEOSWAITEV,p1,p2,p3)
#define	C_SIGSP(p1,p2)		mc_lcif(ossigsp,CL_BSYS,CL_ASYS,2,MCEOSSIGSP,p1,p2)
#define	C_EVENT(p1,p2,p3)	mc_lcif(osevent,CL_BSYS,CL_ASYS,3,MCEOSEVENT,p1,p2,p3)
#define	C_SNSSP(p1)			mc_lcif(ossnssp,CL_BSYS,CL_ASYS,1,MCEOSSNSSP,p1)
#define	C_SNSEV(p1)			mc_lcif(ossnsev,CL_BSYS,CL_ASYS,1,MCEOSSNSEV,p1)
#define	C_RSTEV(p1)			mc_lcif(osrstev,CL_BSYS,CL_ASYS,1,MCEOSRSTEV,p1)
										/* ﾒｯｾｰｼﾞ通信						*/
#define	C_CREMB(p1,p2)		mc_lcif(oscremb,CL_BSYS,CL_ASYS,2,MCEOSCREMB,p1,p2)
#define	C_DELMB(p1,p2)		mc_lcif(osdelmb,CL_BSYS,CL_ASYS,2,MCEOSDELMB,p1,p2)
#define	C_SENMS(p1,p2,p3)	mc_lcif(ossenms,CL_BSYS,CL_ASYS,3,MCEOSSENMS,p1,p2,p3)
#define	C_SENMSP(p1,p2,p3)	mc_lcif(ossenmsp,CL_BSYS,CL_ASYS,3,MCEOSSENMSP,p1,p2,p3)
#define	C_RCVMS(p1,p2,p3,p4)	mc_lcif(osrcvms,CL_BSYS,CL_ASYS,4,MCEOSRCVMS,p1,p2,p3,p4)
#define	C_RCVMSR(p1,p2,p3,p4)	mc_lcif(osrcvmsr,CL_BSYS,CL_ASYS,4,MCEOSRCVMSR,p1,p2,p3,p4)
#define	C_RCVMSP(p1,p2,p3)	mc_lcif(osrcvmsp,CL_BSYS,CL_ASYS,3,MCEOSRCVMSP,p1,p2,p3)
#define	C_RCVMSPR(p1,p2,p3)	mc_lcif(osrcvmspr,CL_BSYS,CL_ASYS,3,MCEOSRCVMSPR,p1,p2,p3)
#define	C_SNSMS(p1)			mc_lcif(ossnsms,CL_BSYS,CL_ASYS,1,MCEOSSNSMS,p1)
#define	C_STMS(p1,p2,p3,p4)	mc_lcif(osstms,CL_BSYS,CL_ASYS,4,MCEOSSTMS,p1,p2,p3,p4)
										/* ﾘｻﾞﾙﾄ･例外						*/
#define	C_GTNRL(p1,p2)		mc_lcif(osgtnrl,CL_BSYS,CL_ASYS,2,MCEOSGTNRL,p1,p2)
#define	C_GTNRLA(p1,p2,p3)	mc_lcif(osgtnrla,CL_BSYS,CL_ASYS,3,MCEOSGTNRLA,p1,p2,p3)
#define	C_ANYRL(p1,p2)		mc_lcif(osanyrl,CL_BANY,CL_AANY,2,MCEOSANYRL,p1,p2)
#define	C_CANRQ(p1)			mc_lcif(oscanrq,CL_BSYS,CL_ASYS,1,MCEOSCANRQ,p1)
#define	C_SNSRL(p1,p2)		mc_lcif(ossnsrl,CL_BSYS,CL_ASYS,2,MCEOSSNSRL,p1,p2)
#define	C_ATRQEV(p1,p2)		mc_lcif(osatrqev,CL_BSYS,CL_ASYS,2,MCEOSATRQEV,p1,p2)
#define	C_ATRQEVI(p1,p2)	mc_lcif(osatrqevi,CL_BSYS,CL_ASYS,2,MCEOSATRQEVI,p1,p2)
#define	C_DTRQEV(p1)		mc_lcif(osdtrqev,CL_BSYS,CL_ASYS,1,MCEOSDTRQEV,p1)
#define	C_RSRRD(p1,p2)		mc_lcif(osrsrrd,CL_BSYS,CL_ASYS,2,MCEOSRSRRD,p1,p2)
#define	C_RELRD(p1,p2)		mc_lcif(osrelrd,CL_BSYS,CL_ASYS,2,MCEOSRELRD,p1,p2)
#define	C_STPIR(p1,p2)		mc_lcif(osstpir,CL_BSYS,CL_ASYS,2,MCEOSSTPIR,p1,p2)
#define	C_STPIRI(p1,p2)		mc_lcif(osstpiri,CL_BSYS,CL_ASYS,2,MCEOSSTPIRI,p1,p2)
#define	C_SETEX(p1,p2)		mc_lcif(ossetex,CL_BSYS,CL_ASYS,2,MCEOSSETEX,p1,p2)
#define	C_SETEXI(p1,p2)		mc_lcif(ossetexi,CL_BSYS,CL_ASYS,2,MCEOSSETEXI,p1,p2)
#define	C_RSTPIR(p1)		mc_lcif(osrstpir,CL_BSYS,CL_ASYS,1,MCEOSRSTPIR,p1)
#define	C_RSTEX(p1)			mc_lcif(osrstex,CL_BSYS,CL_ASYS,1,MCEOSRSTEX,p1)
#define	C_GTCPIR(p1,p2)		mc_lcif(osgtcpir,CL_BSYS,CL_ASYS,2,MCEOSGTCPIR,p1,p2)
#define	C_GTEX(p1,p2)		mc_lcif(osgtex,CL_BSYS,CL_ASYS,2,MCEOSGTEX,p1,p2)
#define	C_RTNPIR()			mc_lcif(osrtnpir,CL_BSYS,CL_ASYS,0,MCEOSRTNPIR)
#define	C_EXITH(p1)			mc_lcif(osexith,CL_BSYS,CL_ASYS,1,MCEOSEXITH,p1)
#define	C_RAIEX(p1,p2)		mc_lcif(osraiex,CL_BSYS,CL_ASYS,2,MCEOSRAIEX,p1,p2)
										/* ﾊﾞｯﾌｧﾌﾟｰﾙ管理					*/
#define	C_CRELBP(p1,p2,p3,p4)	mc_lcif(oscrelbp,CL_BSYS,CL_ASYS,4,MCEOSCRELBP,p1,p2,p3,p4)
#define	C_CRECBP(p1,p2,p3,p4)	mc_lcif(oscrecbp,CL_BSYS,CL_ASYS,4,MCEOSCRECBP,p1,p2,p3,p4)
#define	C_DELBP(p1)			mc_lcif(osdelbp,CL_BSYS,CL_ASYS,1,MCEOSDELBP,p1)
#define	C_GTPBF(p1,p2,p3)	mc_lcif(osgtpbf,CL_BSYS,CL_ASYS,3,MCEOSGTPBF,p1,p2,p3)
#define	C_FRPBF(p1,p2)		mc_lcif(osfrpbf,CL_BSYS,CL_ASYS,2,MCEOSFRPBF,p1,p2)
#define	C_SNSFU(p1)			mc_lcif(ossnsfu,CL_BSYS,CL_ASYS,1,MCEOSSNSFU,p1)
#define	C_SNSAU(p1)			mc_lcif(ossnsau,CL_BSYS,CL_ASYS,1,MCEOSSNSAU,p1)
#define	C_SNSUS(p1)			mc_lcif(ossnsus,CL_BSYS,CL_ASYS,1,MCEOSSNSUS,p1)
#define	C_SNSLC(p1)			mc_lcif(ossnslc,CL_BSYS,CL_ASYS,1,MCEOSSNSLC,p1)
#define	C_SNSPBI(p1)		mc_lcif(ossnspbi,CL_BSYS,CL_ASYS,1,MCEOSSNSPBI,p1)
#define	C_SNSADI(p1)		mc_lcif(ossnsadi,CL_BSYS,CL_ASYS,1,MCEOSSNSADI,p1)
#define	C_ATBP(p1)			mc_lcif(osatbp,CL_BSYS,CL_ASYS,1,MCEOSATBP,p1)
#define	C_DTBP(p1)			mc_lcif(osdtbp,CL_BSYS,CL_ASYS,1,MCEOSDTBP,p1)
										/* 共用ﾒﾓﾘ管理						*/
#define	C_GTSHM(p1,p2,p3,p4)	mc_lcif(osgtshm,CL_BSYS,CL_ASYS,4,MCEOSGTSHM,p1,p2,p3,p4)
#define	C_ATSHM(p1,p2,p3)	mc_lcif(osatshm,CL_BSYS,CL_ASYS,3,MCEOSATSHM,p1,p2,p3)
#define	C_DTSHM(p1)			mc_lcif(osdtshm,CL_BSYS,CL_ASYS,1,MCEOSDTSHM,p1)
										/* ﾀｲﾏ管理							*/
#define	C_DELAY(p1,p2)		mc_lcif(osdelay,CL_BSYS,CL_ASYS,2,MCEOSDELAY,p1,p2)
#define	C_SLPUM(p1,p2)		mc_lcif(osslpum,CL_BSYS,CL_ASYS,2,MCEOSSLPUM,p1,p2)
#define	C_STTIM(p1,p2,p3)	mc_lcif(ossttim,0,CL_WSYS,3,MCEOSSTTIM,p1,p2,p3)
#define	C_STDTIM(p1,p2,p3)	mc_lcif(osstdtim,0,CL_WSYS,3,MCEOSSTDTIM,p1,p2,p3)
#define	C_STDAT(p1,p2)		mc_lcif(osstdat,CL_BSYS,CL_ASYS,2,MCEOSSTDAT,p1,p2)
#define	C_GTDAT(p1,p2)		mc_lcif(osgtdat,CL_BSYS,CL_ASYS,2,MCEOSGTDAT,p1,p2)
#define	C_SNSTM()			mc_lcif(ossnstm,CL_BSYS,CL_ASYS,0,MCEOSSNSTM)
										/* その他							*/
#define	C_LTORAD(p1,p2)		mc_lcif(osltorad,CL_BSYS,CL_ASYS,2,MCEOSLTORAD,p1,p2)
#define	C_GETINF(p1)		mc_lcif(osgetinf,CL_BSYS,CL_ASYS,1,MCEOSGETINF,p1)
#define	C_RSTINF()			mc_lcif(osrstinf,CL_BSYS,CL_ASYS,0,MCEOSRSTINF)
#define	C_STINF()			mc_lcif(osstinf,CL_BSYS,CL_ASYS,0,MCEOSSTINF)
#define	C_TMINF()			mc_lcif(ostminf,CL_BSYS,CL_ASYS,0,MCEOSTMINF)
#define	C_GTPRCINF(p1)		mc_lcif(osgtprcinf,CL_BSYS,CL_ASYS,1,MCEOSGTPRCINF,p1)
#define	C_GTKTRINF(p1,p2,p3)	mc_lcif(osgtktrinf,CL_BSYS,CL_ASYS,3,MCEOSGTKTRINF,p1,p2,p3)
#define	C_PATHOPN(p1)		mc_lcif(ospathopn,CL_BSYS,CL_ASYS,1,MCEOSPATHOPN,p1)
#define	C_PATHCLS(p1)		mc_lcif(ospathcls,CL_BSYS,CL_ASYS,1,MCEOSPATHCLS,p1)
#define	C_SYMTOAD(p1,p2,p3)	mc_lcif(ossymtoad,CL_BSYS,CL_ASYS,3,MCEOSSYMTOAD,p1,p2,p3)
/****************************************/
/*	ﾌｧｲﾙ管理							*/
/****************************************/
										/* ﾌｧｲﾙ･ﾃﾞｨﾚｸﾄﾘ操作					*/
#define	C_CHROOT(p1)		mc_lcif(oschroot,CL_BSYS,CL_ASYS,1,MCEOSCHROOT,p1)
#define	C_CHWKD(p1)			mc_lcif(oschwkd,CL_BSYS,CL_ASYS,1,MCEOSCHWKD,p1)
#define	C_CLOSE(p1)			mc_lcif(osclose,CL_BSYS,CL_ASYS,1,MCEOSCLOSE,p1)
#define	C_ICLOSE(p1,p2)		mc_lcif(osiclose,0,CL_WSYS,2,MCEOSICLOSE,p1,p2)
#define	C_CONN(p1)			mc_lcif(osconn,CL_BSYS,CL_ASYS,1,MCEOSCONN,p1)
#define	C_CREAT(p1,p2,p3,p4,p5,p6,p7) mc_lcif(oscreat,CL_BSYS,CL_ASYS,7,MCEOSCREAT,p1,p2,p3,p4,p5,p6,p7)
#define	C_DCONN(p1)			mc_lcif(osdconn,CL_BSYS,CL_ASYS,1,MCEOSDCONN,p1)
#define	C_DELET(p1)			mc_lcif(osdelet,CL_BSYS,CL_ASYS,1,MCEOSDELET,p1)
#define	C_EXTEN(p1,p2)		mc_lcif(osexten,CL_BSYS,CL_ASYS,2,MCEOSEXTEN,p1,p2)
#define	C_LINK(p1,p2)		mc_lcif(oslink,CL_BSYS,CL_ASYS,2,MCEOSLINK,p1,p2)
#define	C_MKNOD(p1,p2,p3,p4)	mc_lcif(osmknod,CL_BSYS,CL_ASYS,4,MCEOSMKNOD,p1,p2,p3,p4)
#define	C_MOUNT(p1,p2,p3)	mc_lcif(osmount,CL_BSYS,CL_ASYS,3,MCEOSMOUNT,p1,p2,p3)
#define	C_OPEN(p1,p2,p3,p4,p5,p6)	mc_lcif(osopen,CL_BSYS,CL_ASYS,6,MCEOSOPEN,p1,p2,p3,p4,p5,p6)
#define	C_IOPEN(p1,p2,p3,p4,p5,p6,p7) mc_lcif(osiopen,0,CL_WSYS,7,MCEOSIOPEN,p1,p2,p3,p4,p5,p6,p7)
#define	C_RENAM(p1,p2)		mc_lcif(osrenam,CL_BSYS,CL_ASYS,2,MCEOSRENAM,p1,p2)
#define	C_TRUNC(p1)			mc_lcif(ostrunc,CL_BSYS,CL_ASYS,1,MCEOSTRUNC,p1)
#define	C_UMOUNT(p1)		mc_lcif(osumount,CL_BSYS,CL_ASYS,1,MCEOSUMOUNT,p1)
#define	C_UMOUNTF(p1)		mc_lcif(osumountf,CL_BSYS,CL_ASYS,1,MCEOSUMOUNTF,p1)
										/* ﾃﾞｰﾀ操作							*/
#define	C_FLUSH(p1,p2)		mc_lcif(osflush,CL_BSYS,CL_ASYS,2,MCEOSFLUSH,p1,p2)
#define	C_FREE(p1,p2,p3)	mc_lcif(osfree,CL_BSYS,CL_ASYS,3,MCEOSFREE,p1,p2,p3)
#define	C_READ(p1,p2,p3)	mc_lcif(osread,CL_BSYS,CL_ASYS,3,MCEOSREAD,p1,p2,p3)
#define	C_IREAD(p1,p2,p3,p4)	mc_lcif(osiread,0,CL_WSYS,4,MCEOSIREAD,p1,p2,p3,p4)
#define	C_READD(p1,p2,p3,p4)	mc_lcif(osreadd,CL_BSYS,CL_ASYS,4,MCEOSREADD,p1,p2,p3,p4)
#define	C_IREADD(p1,p2,p3,p4,p5)	mc_lcif(osireadd,0,CL_WSYS,5,MCEOSIREADD,p1,p2,p3,p4,p5)
#define	C_READDL(p1,p2,p3,p4,p5)	mc_lcif(osreaddl,CL_BSYS,CL_ASYS,5,MCEOSREADDL,p1,p2,p3,p4,p5)
#define	C_IREADDL(p1,p2,p3,p4,p5,p6) mc_lcif(osireaddl,0,CL_WSYS,6,MCEOSIREADDL,p1,p2,p3,p4,p5,p6)
#define	C_SEEK(p1,p2,p3)	mc_lcif(osseek,CL_BSYS,CL_ASYS,3,MCEOSSEEK,p1,p2,p3)
#define	C_ISEEK(p1,p2,p3,p4)	mc_lcif(osiseek,0,CL_WSYS,4,MCEOSISEEK,p1,p2,p3,p4)
#define	C_SYNC(p1,p2)		mc_lcif(ossync,CL_BSYS,CL_ASYS,2,MCEOSSYNC,p1,p2)
#define	C_WRITE(p1,p2,p3)	mc_lcif(oswrite,CL_BSYS,CL_ASYS,3,MCEOSWRITE,p1,p2,p3)
#define	C_IWRIT(p1,p2,p3,p4)	mc_lcif(osiwrit,0,CL_WSYS,4,MCEOSIWRIT,p1,p2,p3,p4)
#define	C_WRITD(p1,p2,p3,p4)	mc_lcif(oswritd,CL_BSYS,CL_ASYS,4,MCEOSWRITD,p1,p2,p3,p4)
#define	C_IWRITD(p1,p2,p3,p4,p5)	mc_lcif(osiwritd,0,CL_WSYS,5,MCEOSIWRITD,p1,p2,p3,p4,p5)
										/* 制御								*/
#define	C_ACCESS(p1,p2)		mc_lcif(osaccess,CL_BSYS,CL_ASYS,2,MCEOSACCESS,p1,p2)
#define	C_CHACC(p1,p2,p3)	mc_lcif(oschacc,CL_BSYS,CL_ASYS,3,MCEOSCHACC,p1,p2,p3)
#define	C_CHOWN(p1,p2,p3)	mc_lcif(oschown,CL_BSYS,CL_ASYS,3,MCEOSCHOWN,p1,p2,p3)
#define	C_DUP(p1)			mc_lcif(osdup,CL_BSYS,CL_ASYS,1,MCEOSDUP,p1)
#define	C_FCNTL(p1,p2,p3)	mc_lcif(osfcntl,CL_BSYS,CL_ASYS,3,MCEOSFCNTL,p1,p2,p3)
#define	C_GFINF(p1,p2,p3,p4)	mc_lcif(osgfinf,CL_BSYS,CL_ASYS,4,MCEOSGFINF,p1,p2,p3,p4)

#define	C_GLOCK(p1)			mc_lcif(osglock,CL_BSYS,CL_ASYS,1,MCEOSGLOCK,p1)
#define	C_GTACC(p1,p2)		mc_lcif(osgtacc,CL_BSYS,CL_ASYS,2,MCEOSGTACC,p1,p2)
#define	C_GTIDN(p1)			mc_lcif(osgtidn,CL_BSYS,CL_ASYS,1,MCEOSGTIDN,p1)
#define	C_GTWKD(p1,p2)		mc_lcif(osgtwkd,CL_BSYS,CL_ASYS,2,MCEOSGTWKD,p1,p2)
#define	C_GUNLOCK(p1)		mc_lcif(osgunlock,CL_BSYS,CL_ASYS,1,MCEOSGUNLOCK,p1)
#define	C_IOCTL(p1,p2,p3,p4)	mc_lcif(osioctl,CL_BSYS,CL_ASYS,4,MCEOSIOCTL,p1,p2,p3,p4)
#define	C_IIOCTL(p1,p2,p3,p4,p5)	mc_lcif(osiioctl,0,CL_WSYS,5,MCEOSIIOCTL,p1,p2,p3,p4,p5)
#define	C_UMASK(p1)			mc_lcif(osumask,CL_BSYS,CL_ASYS,1,MCEOSUMASK,p1)
/****************************************/
/*	ｼｽﾃﾑ管理							*/
/****************************************/
										/* 開始								*/
#define	C_IPL(p1,p2,p3,p4)		mc_lcif(osipl,CL_BSYS,CL_ASYS,4,MCEOSIPL,p1,p2,p3,p4)
#define	C_IPL2(p1,p2,p3,p4,p5)	mc_lcif(osipl2,CL_BSYS,CL_ASYS,5,MCEOSIPL2,p1,p2,p3,p4,p5)
#define	C_RESTART(p1,p2,p3)		mc_lcif(osrestart,CL_BSYS,CL_ASYS,3,MCEOSRESTART,p1,p2,p3)
#define	C_RESTART2(p1,p2,p3,p4)	mc_lcif(osrestart2,CL_BSYS,CL_ASYS,4,MCEOSRESTART2,p1,p2,p3,p4)
										/* 終了								*/
#define	C_SYSOFF(p1)		mc_lcif(ossysoff,CL_BSYS,CL_ASYS,1,MCEOSSYSOFF,p1)
										/* 障害								*/
#define	C_SYSDOWN(p1,p2)	mc_lcif(ossysdown,CL_BSYS,CL_ASYS,2,MCEOSSYSDOWN,p1,p2)
#define	C_SYSDOWN2(p1,p2,p3)	mc_lcif(ossysdown2,CL_BSYS,CL_ASYS,3,MCEOSSYSDOWN2,p1,p2,p3)
#define	C_CHGACT()			mc_lcif(oschgact,CL_BSYS,CL_ASYS,0,MCEOSCHGACT)
#define	C_CHGACT2(p1)		mc_lcif(oschgact2,CL_BSYS,CL_ASYS,1,MCEOSCHGACT2,p1)
										/* 装置管理							*/
#define	C_CONFIG(p1,p2,p3)	mc_lcif(osconfig,CL_BSYS,CL_ASYS,3,MCEOSCONFIG,p1,p2,p3)
#define	C_CFPCON(p1,p2,p3,p4)	mc_lcif(oscfpcon,CL_BSYS,CL_ASYS,4,MCEOSCFPCON,p1,p2,p3,p4)
#define	C_DSPINF(p1,p2)		mc_lcif(osdspinf,CL_BSYS,CL_ASYS,2,MCEOSDSPINF,p1,p2)
#define	C_CFPRSLT(p1)		mc_lcif(oscfprslt,CL_BSYS,CL_ASYS,1,MCEOSCFPRSLT,p1)

#define	C_GETPTH(p1)		mc_lcif(osgetpth,CL_BSYS,CL_ASYS,1,MCEOSGETPTH,p1)
#define	C_EXCHGPTH(p1,p2)	mc_lcif(osexchgpth,CL_BSYS,CL_ASYS,2,MCEOSEXCHGPTH,p1,p2)
										/* 運用管理							*/
#define	C_GETAPMD()			mc_lcif(osgetapmd,CL_BSYS,CL_ASYS,0,MCEOSGETAPMD)
#define	C_GETHSW(p1)		mc_lcif(osgethsw,CL_BSYS,CL_ASYS,1,MCEOSGETHSW,p1)
#define	C_GETSSW(p1)		mc_lcif(osgetssw,CL_BSYS,CL_ASYS,1,MCEOSGETSSW,p1)
#define	C_SYSRCVR(p1)		mc_lcif(ossysrcvr,CL_BSYS,CL_ASYS,1,MCEOSSYSRCVR,p1)
#define	C_MBINF(p1,p2)		mc_lcif(osmbinf,CL_BSYS,CL_ASYS,2,MCEOSMBINF,p1,p2)
#define	C_GETMBID()			mc_lcif(osgetmbid,CL_BSYS,CL_ASYS,0,MCEOSGETMBID)
#define	C_PRGMD(p1,p2)		mc_lcif(osprgmd,CL_BSYS,CL_ASYS,2,MCEOSPRGMD,p1,p2)
#define	C_GETPUC(p1)		mc_lcif(osgetpuc,CL_BSYS,CL_ASYS,1,MCEOSGETPUC,p1)
#define	C_GETIOS(p1)		mc_lcif(osgetios,CL_BSYS,CL_ASYS,1,MCEOSGETIOS,p1)
#define	C_GETBNO(p1)		mc_lcif(osgetbno,CL_BSYS,CL_ASYS,1,MCEOSGETBNO,p1)
#define	C_SYSMD(p1,p2)		mc_lcif(ossysmd,CL_BSYS,CL_ASYS,2,MCEOSSYSMD,p1,p2)
										/* その他							*/
#define	C_SETPTM(p1,p2)		mc_lcif(ossetptm,CL_BSYS,CL_ASYS,2,MCEOSSETPTM,p1,p2)
#define	C_GETPTM(p1,p2)		mc_lcif(osgetptm,CL_BSYS,CL_ASYS,2,MCEOSGETPTM,p1,p2)
#define	C_ENBPTM(p1)		mc_lcif(osenbptm,CL_BSYS,CL_ASYS,1,MCEOSENBPTM,p1)
#define	C_DSBPTM(p1)		mc_lcif(osdsbptm,CL_BSYS,CL_ASYS,1,MCEOSDSBPTM,p1)
#define	C_EXCNTRL(p1,p2)	mc_lcif(osexcntrl,CL_BSYS,CL_ASYS,2,MCEOSEXCNTRL,p1,p2)
#define	C_GETSRV(p1)		mc_lcif(osgetsrv,CL_BSYS,CL_ASYS,1,MCEOSGETSRV,p1)
#define	C_CMDMD(p1)			mc_lcif(oscmdmd,CL_BSYS,CL_ASYS,1,MCEOSCMDMD,p1)
#define	C_TELREG(p1,p2,p3,p4,p5)	mc_lcif(ostelreg,CL_BSYS,CL_ASYS,5,MCEOSTELREG,p1,p2,p3,p4,p5)
#define	C_TELDEL(p1)		mc_lcif(osteldel,CL_BSYS,CL_ASYS,1,MCEOSTELDEL,p1)
#define	C_TELGET(p1,p2,p3,p4)	mc_lcif(ostelget,CL_BSYS,CL_ASYS,4,MCEOSTELGET,p1,p2,p3,p4)
#define	C_TELCAL(p1,p2)		mc_lcif(ostelcal,CL_BSYS,CL_ASYS,2,MCEOSTELCAL,p1,p2)
#define	C_ABTMD(p1)			mc_lcif(osabtmd,CL_BSYS,CL_ASYS,1,MCEOSABTMD,p1)
/****************************************/
/*	Ｒａｌｌｙ関数						*/
/****************************************/
#define	C_RVINIT()			mc_lcif(rvinit,CL_BSYS,CL_ASYS,0,CF_RVINIT)
#define	C_RVEND()			mc_lcif(rvend,CL_BSYS,CL_ASYS,0,CF_RVEND)
#define	C_RVBGET(p1,p2)		mc_lcif(rvbget,CL_BSYS,CL_ASYS,2,CF_RVBGET,p1,p2)
#define	C_RVBFREE(p1)		mc_lcif(rvbfree,CL_BSYS,CL_ASYS,1,CF_RVBFREE,p1)
#define	C_RVBINQ(p1)		mc_lcif(rvbinq,CL_BSYS,CL_ASYS,1,CF_RVBINQ,p1)
#define	C_RVPOST(p1)		mc_lcif(rvpost,CL_BSYS,CL_ASYS,1,CF_RVPOST,p1)
#define	C_RVL3OPN(p1,p2)	mc_lcif(rvl3opn,CL_BSYS,CL_ASYS,2,CF_RVL3OPN,p1,p2)
#define	C_RVL3CLS(p1,p2)	mc_lcif(rvl3cls,CL_BSYS,CL_ASYS,2,CF_RVL3CLS,p1,p2)
#define	C_RVRSTRT(p1,p2)	mc_lcif(rvrstrt,CL_BSYS,CL_ASYS,2,CF_RVRSTRT,p1,p2)
#define	C_RVRST(p1,p2,p3)	mc_lcif(rvrst,CL_BSYS,CL_ASYS,3,CF_RVRST,p1,p2,p3)
#define	C_RVECHO(p1,p2)		mc_lcif(rvecho,CL_BSYS,CL_ASYS,2,CF_RVECHO,p1,p2)
#define	C_RVECHOE(p1,p2)	mc_lcif(rvechoe,CL_BSYS,CL_ASYS,2,CF_RVECHOE,p1,p2)
#define	C_RVIPT(p1,p2,p3)	mc_lcif(rvipt,CL_BSYS,CL_ASYS,3,CF_RVIPT,p1,p2,p3)
#define	C_RVIPTR(p1,p2)		mc_lcif(rviptr,CL_BSYS,CL_ASYS,2,CF_RVIPTR,p1,p2)
#define	C_RVL3CNF(p1,p2,p3)	mc_lcif(rvl3cnf,CL_BSYS,CL_ASYS,3,CF_RVL3CNF,p1,p2,p3)
#define	C_RVL3ADD(p1,p2,p3)	mc_lcif(rvl3add,CL_BSYS,CL_ASYS,3,CF_RVL3ADD,p1,p2,p3)
/****************************************/
/*	ＯＳＩ−ＦＴＡＭ関数				*/
/****************************************/
										/* C_ACTOPEN〜C_ACKMANG	   ST0146  	*/
#define	C_ACTOPEN(p1,p2,p3,p4)	mc_lcif(actopen,CL_BSYS,CL_ASYS,4,CF_ACTOPEN,p1,p2,p3,p4)
#define	C_ACTCLOS(p1,p2,p3)	mc_lcif(actclos,CL_BSYS,CL_ASYS,3,CF_ACTCLOS,p1,p2,p3)
#define	C_ACTPSET(p1,p2,p3,p4)	mc_lcif(actpset,CL_BSYS,CL_ASYS,4,CF_ACTPSET,p1,p2,p3,p4)
#define	C_ACTPRSP(p1,p2,p3,p4)	mc_lcif(actprsp,CL_BSYS,CL_ASYS,4,CF_ACTPRSP,p1,p2,p3,p4)
#define	C_ACTPFRE(p1,p2,p3,p4)	mc_lcif(actpfre,CL_BSYS,CL_ASYS,4,CF_ACTPFRE,p1,p2,p3,p4)
#define	C_ACTPFRS(p1,p2,p3,p4)	mc_lcif(actpfrs,CL_BSYS,CL_ASYS,4,CF_ACTPFRS,p1,p2,p3,p4)
#define	C_ACTPSND(p1,p2,p3,p4)	mc_lcif(actpsnd,CL_BSYS,CL_ASYS,4,CF_ACTPSND,p1,p2,p3,p4)
#define	C_ACKMANA(p1,p2,p3)	mc_lcif(ackmana,CL_BSYS,CL_ASYS,3,CF_ACKMANA,p1,p2,p3)
#define	C_ACKMANB(p1,p2,p3)	mc_lcif(ackmanb,CL_BSYS,CL_ASYS,3,CF_ACKMANB,p1,p2,p3)
#define	C_ACKMANC(p1,p2,p3)	mc_lcif(ackmanc,CL_BSYS,CL_ASYS,3,CF_ACKMANC,p1,p2,p3)
#define	C_ACKMAND(p1,p2,p3)	mc_lcif(ackmand,CL_BSYS,CL_ASYS,3,CF_ACKMAND,p1,p2,p3)
#define	C_ACKMANE(p1,p2,p3)	mc_lcif(ackmane,CL_BSYS,CL_ASYS,3,CF_ACKMANE,p1,p2,p3)
#define	C_ACKMANF(p1,p2,p3)	mc_lcif(ackmanf,CL_BSYS,CL_ASYS,3,CF_ACKMANF,p1,p2,p3)
#define	C_ACKMANG(p1,p2,p3)	mc_lcif(ackmang,CL_BSYS,CL_ASYS,3,CF_ACKMANG,p1,p2,p3)

/****************************************/
/*	TRADEエミュレートでの追加	M01		*/
/****************************************/
#define	C_SETEX2(p1,p2)		mc_lcif(ossetex2,CL_BSYS,CL_ASYS,2,MCEOSSETEX,p1,p2)
#define	C_RSTEX2(p1)		mc_lcif(osrstex2,CL_BSYS,CL_ASYS,1,MCEOSRSTEX,p1)
#define	C_CLOSE2(p1)		mc_lcif(osclose2,CL_BSYS,CL_ASYS,1,MCEOSCLOSE,p1)
#define	C_CONN2(p1)			mc_lcif(osconn2,CL_BSYS,CL_ASYS,1,MCEOSCONN,p1)
#define	C_DCONN2(p1)		mc_lcif(osdconn2,CL_BSYS,CL_ASYS,1,MCEOSDCONN,p1)
#define	C_OPEN2(p1,p2,p3,p4,p5,p6)	mc_lcif(osopen2,CL_BSYS,CL_ASYS,6,MCEOSOPEN,p1,p2,p3,p4,p5,p6)
#define	C_IREADD2(p1,p2,p3,p4,p5)	mc_lcif(osireadd2,0,CL_WSYS,5,MCEOSIREADD,p1,p2,p3,p4,p5)
#define	C_WRITE1(p1,p2,p3)	mc_lcif(oswrite1,CL_BSYS,CL_ASYS,3,MCEOSWRITE,p1,p2,p3)
#define	C_IWRITD2(p1,p2,p3,p4,p5)	mc_lcif(osiwritd2,0,CL_WSYS,5,MCEOSIWRITD,p1,p2,p3,p4,p5)
#define	C_IOCTL1(p1,p2,p3,p4)	mc_lcif(osioctl1,CL_BSYS,CL_ASYS,4,MCEOSIOCTL,p1,p2,p3,p4)
#define	C_IOCTL2(p1,p2,p3,p4)	mc_lcif(osioctl2,CL_BSYS,CL_ASYS,4,MCEOSIOCTL,p1,p2,p3,p4)
#define	C_IIOCTL2(p1,p2,p3,p4,p5)	mc_lcif(osiioctl2,0,CL_WSYS,5,MCEOSIIOCTL,p1,p2,p3,p4,p5)
#define	C_SENMS2(p1,p2,p3)	mc_lcif(ossenms2,CL_BSYS,CL_ASYS,3,MCEOSSENMS2,p1,p2,p3)

										/* CORBA関数追加 2003/07/10 start */
/*************/
/* CORBA関数 */
/*************/
#define C_CORBA_ORB_init(p1,p2,p3,p4)						\
		mc_lcif(CORBA_ORB_init,CL_BSYS,CL_ASYS,4,FID_CORBA_ORB_init,p1,p2,p3,p4)
#define C_CORBA_ORB_BOA_init(p1,p2,p3,p4,p5)				\
		mc_lcif(CORBA_ORB_BOA_init,CL_BSYS,CL_ASYS,5,FID_CORBA_ORB_BOA_init,p1,p2,p3,p4,p5)
#define C_CORBA_ORB_resolve_initial_references(p1,p2,p3)	\
		mc_lcif(CORBA_ORB_resolve_initial_references,CL_BSYS,CL_ASYS,3,FID_CORBA_ORB_resolve_initial_references,p1,p2,p3)
#define C_FJ_ImplementationRep_lookup_id(p1,p2,p3)			\
		mc_lcif(FJ_ImplementationRep_lookup_id,CL_BSYS,CL_ASYS,3,FID_FJ_ImplementationRep_lookup_id,p1,p2,p3)
#define C_CORBA_BOA_impl_is_ready(p1,p2,p3)					\
		mc_lcif(CORBA_BOA_impl_is_ready,CL_BSYS,CL_ASYS,3,FID_CORBA_BOA_impl_is_ready,p1,p2,p3)
#define C_CORBA_BOA_deactivate_impl(p1,p2,p3)				\
		mc_lcif(CORBA_BOA_deactivate_impl,CL_BSYS,CL_ASYS,3,FID_CORBA_BOA_deactivate_impl,p1,p2,p3)
#define C_CosNaming_NamingContext_resolve(p1,p2,p3)			\
		mc_lcif(CosNaming_NamingContext_resolve,CL_BSYS,CL_ASYS,3,FID_CosNaming_NamingContext_resolve,p1,p2,p3)
#define C_CORBA_ORB_set_client_timer(p1,p2,p3,p4)			\
		mc_lcif(CORBA_ORB_set_client_timer,CL_BSYS,CL_ASYS,4,FID_CORBA_ORB_set_client_timer,p1,p2,p3,p4)
#define C_lala_nodekan_Octets_alloc()						\
		mc_lcif(lala_nodekan_Octets_alloc,CL_BSYS,CL_ASYS,0,FID_lala_nodekan_Octets_alloc)
#define C_lala_nodekan_Octets_allocbuf(p1)					\
		mc_lcif(lala_nodekan_Octets_allocbuf,CL_BSYS,CL_ASYS,1,FID_lala_nodekan_Octets_allocbuf,p1)
#define C_lala_nodekan_msgsnd(p1,p2,p3,p4,p5,p6,p7)			\
		mc_lcif(lala_nodekan_msgsnd,CL_BSYS,CL_ASYS,7,FID_lala_nodekan_msgsnd,p1,p2,p3,p4,p5,p6,p7)
#define C_CORBA_sequence_set_release(p1,p2)					\
		mc_lcif(CORBA_sequence_set_release,CL_BSYS,CL_ASYS,2,FID_CORBA_sequence_set_release,p1,p2)
#define C_CORBA_free(p1)									\
		mc_lcif(CORBA_free,CL_BSYS,CL_ASYS,1,FID_CORBA_free,p1)
#define C_CORBA_Object_release(p1,p2)						\
		mc_lcif(CORBA_Object_release,CL_BSYS,CL_ASYS,2,FID_CORBA_Object_release,p1,p2)
										/* CORBA関数追加 2003/07/10 end */
#endif
/****************************************************************************/
/*	System-Call Macro when compiled with "DLOFF"							*/
/****************************************************************************/
#ifdef	LOFF
/****************************************/
/*	実行管理							*/ 
/****************************************/
										/* ﾌﾟﾛｾｽ制御						*/
#define	C_CREPR(p1,p2,p3,p4,p5)			oscrepr(p1,p2,p3,p4,p5)
#define	C_DESPR(p1,p2)					osdespr(p1,p2)
#define	C_TERM(p1)						osterm(p1)
#define	C_RESPR(p1)						osrespr(p1)
#define	C_SLEEP()						ossleep()
#define	C_WAKEUP()						oswakeup()
#define	C_RSCHD(p1)						osrschd(p1)
#define	C_SUSPR(p1)						ossuspr(p1)
#define	C_WCHLD(p1,p2,p3)				oswchld(p1,p2,p3)
#define	C_WCHLDR(p1,p2,p3)				oswchldr(p1,p2,p3)
#define	C_STUIC(p1)						osstuic(p1)
#define	C_STPGR(p1)						osstpgr(p1)
#define	C_CHPRI(p1)						oschpri(p1)
#define	C_CHOPRI(p1,p2)					oschopri(p1,p2)
#define	C_GTPIN(p1,p2)					osgtpin(p1,p2)
#define	C_GTPRI()						osgtpri()
#define	C_GTOPRI(p1)					osgtopri(p1)
#define	C_GTSTS(p1)						osgtsts(p1)
#define	C_GTUIC()						osgtuic()
#define	C_GTPGR()						osgtpgr()
#define	C_CREMPR(p1,p2,p3,p4,p5,p6)		oscrempr(p1,p2,p3,p4,p5,p6)
										/* ｲﾍﾞﾝﾄ制御						*/
#define	C_CRESP(p1,p2,p3)				oscresp(p1,p2,p3)
#define	C_DELSP(p1,p2)					osdelsp(p1,p2)
#define	C_WAITSP(p1,p2,p3)				oswaitsp(p1,p2,p3)
#define	C_WAITEV(p1,p2,p3)				oswaitev(p1,p2,p3)
#define	C_SIGSP(p1,p2)					ossigsp(p1,p2)
#define	C_EVENT(p1,p2,p3)				osevent(p1,p2,p3)
#define	C_SNSSP(p1)						ossnssp(p1)
#define	C_SNSEV(p1)						ossnsev(p1)
#define	C_RSTEV(p1)						osrstev(p1)
										/* ﾒｯｾｰｼﾞ通信						*/
#define	C_CREMB(p1,p2)					oscremb(p1,p2)
#define	C_DELMB(p1,p2)					osdelmb(p1,p2)
#define	C_SENMS(p1,p2,p3)				ossenms(p1,p2,p3)
#define	C_SENMSP(p1,p2,p3)				ossenmsp(p1,p2,p3)
#define	C_RCVMS(p1,p2,p3,p4)			osrcvms(p1,p2,p3,p4)
#define	C_RCVMSR(p1,p2,p3,p4)			osrcvmsr(p1,p2,p3,p4)
#define	C_RCVMSP(p1,p2,p3)				osrcvmsp(p1,p2,p3)
#define	C_RCVMSPR(p1,p2,p3)				osrcvmspr(p1,p2,p3)
#define	C_SNSMS(p1)						ossnsms(p1)
#define	C_STMS(p1,p2,p3,p4)				osstms(p1,p2,p3,p4)
										/* ﾘｻﾞﾙﾄ･例外						*/
#define	C_GTNRL(p1,p2)					osgtnrl(p1,p2)
#define	C_GTNRLA(p1,p2,p3)				osgtnrla(p1,p2,p3)
#define	C_ANYRL(p1,p2)					osanyrl(p1,p2)
#define	C_CANRQ(p1)						oscanrq(p1)
#define	C_SNSRL(p1,p2)					ossnsrl(p1,p2)
#define	C_ATRQEV(p1,p2)					osatrqev(p1,p2)
#define	C_ATRQEVI(p1,p2)				osatrqevi(p1,p2)
#define	C_DTRQEV(p1)					osdtrqev(p1)
#define	C_RSRRD(p1,p2)					osrsrrd(p1,p2)
#define	C_RELRD(p1,p2)					osrelrd(p1,p2)
#define	C_STPIR(p1,p2)					osstpir(p1,p2)
#define	C_STPIRI(p1,p2)					osstpiri(p1,p2)
#define	C_SETEX(p1,p2)					ossetex(p1,p2)
#define	C_SETEXI(p1,p2)					ossetexi(p1,p2)
#define	C_RSTPIR(p1)					osrstpir(p1)
#define	C_RSTEX(p1)						osrstex(p1)
#define	C_GTCPIR(p1,p2)					osgtcpir(p1,p2)
#define	C_GTEX(p1,p2)					osgtex(p1,p2)
#define	C_RTNPIR()						osrtnpir()
#define	C_EXITH(p1)						osexith(p1)
#define	C_RAIEX(p1,p2)					osraiex(p1,p2)
										/* ﾊﾞｯﾌｧﾌﾟｰﾙ管理					*/
#define	C_CRELBP(p1,p2,p3,p4)			oscrelbp(p1,p2,p3,p4)
#define	C_CRECBP(p1,p2,p3,p4)			oscrecbp(p1,p2,p3,p4)
#define	C_DELBP(p1)						osdelbp(p1)
#define	C_GTPBF(p1,p2,p3)				osgtpbf(p1,p2,p3)
#define	C_FRPBF(p1,p2)					osfrpbf(p1,p2)
#define	C_SNSFU(p1)						ossnsfu(p1)
#define	C_SNSAU(p1)						ossnsau(p1)
#define	C_SNSUS(p1)						ossnsus(p1)
#define	C_SNSLC(p1)						ossnslc(p1)
#define	C_SNSPBI(p1)					ossnspbi(p1)
#define	C_SNSADI(p1)					ossnsadi(p1)
#define	C_ATBP(p1)						osatbp(p1)
#define	C_DTBP(p1)						osdtbp(p1)
										/* 共用ﾒﾓﾘ管理						*/
#define	C_GTSHM(p1,p2,p3,p4)			osgtshm(p1,p2,p3,p4)
#define	C_ATSHM(p1,p2,p3)				osatshm(p1,p2,p3)
#define	C_DTSHM(p1)						osdtshm(p1)
										/* ﾀｲﾏ管理							*/
#define	C_DELAY(p1,p2)					osdelay(p1,p2)
#define	C_SLPUM(p1,p2)					osslpum(p1,p2)
#define	C_STTIM(p1,p2,p3)				ossttim(p1,p2,p3)
#define	C_STDTIM(p1,p2,p3)				osstdtim(p1,p2,p3)
#define	C_STDAT(p1,p2)					osstdat(p1,p2)
#define	C_GTDAT(p1,p2)					osgtdat(p1,p2)
#define	C_SNSTM()						ossnstm()
										/* その他							*/
#define	C_LTORAD(p1,p2)					osltorad(p1,p2)
#define	C_GETINF(p1)					osgetinf(p1)
#define	C_RSTINF()						osrstinf()
#define	C_STINF()						osstinf()
#define	C_TMINF()						ostminf()
#define	C_GTPRCINF(p1)					osgtprcinf(p1)
#define	C_GTKTRINF(p1,p2,p3)			osgtktrinf(p1,p2,p3)
#define	C_PATHOPN(p1)					ospathopn(p1)
#define	C_PATHCLS(p1)					ospathcls(p1)
#define	C_SYMTOAD(p1,p2,p3)				ossymtoad(p1,p2,p3)
/****************************************/
/*	ﾌｧｲﾙ管理							*/
/****************************************/
										/* ﾌｧｲﾙ･ﾃﾞｨﾚｸﾄﾘ操作					*/
#define	C_CHROOT(p1)					oschroot(p1)
#define	C_CHWKD(p1)						oschwkd(p1)
#define	C_CLOSE(p1)						osclose(p1)
#define	C_ICLOSE(p1,p2)					osiclose(p1,p2)
#define	C_CONN(p1)						osconn(p1)
#define	C_CREAT(p1,p2,p3,p4,p5,p6,p7)	oscreat(p1,p2,p3,p4,p5,p6,p7)
#define	C_DCONN(p1)						osdconn(p1)
#define	C_DELET(p1)						osdelet(p1)
#define	C_EXTEN(p1,p2)					osexten(p1,p2)
#define	C_LINK(p1,p2)					oslink(p1,p2)
#define	C_MKNOD(p1,p2,p3,p4)			osmknod(p1,p2,p3,p4)
#define	C_MOUNT(p1,p2,p3)				osmount(p1,p2,p3)
#define	C_OPEN(p1,p2,p3,p4,p5,p6)		osopen(p1,p2,p3,p4,p5,p6)
#define	C_IOPEN(p1,p2,p3,p4,p5,p6,p7)	osiopen(p1,p2,p3,p4,p5,p6,p7)
#define	C_RENAM(p1,p2)					osrenam(p1,p2)
#define	C_TRUNC(p1)						ostrunc(p1)
#define	C_UMOUNT(p1)					osumount(p1)
#define	C_UMOUNTF(p1)					osumountf(p1)
										/* ﾃﾞｰﾀ操作							*/
#define	C_FLUSH(p1,p2)					osflush(p1,p2)
#define	C_FREE(p1,p2,p3)				osfree(p1,p2,p3)
#define	C_READ(p1,p2,p3)				osread(p1,p2,p3)
#define	C_IREAD(p1,p2,p3,p4)			osiread(p1,p2,p3,p4)
#define	C_READD(p1,p2,p3,p4)			osreadd(p1,p2,p3,p4)
#define	C_IREADD(p1,p2,p3,p4,p5)		osireadd(p1,p2,p3,p4,p5)
#define	C_READDL(p1,p2,p3,p4,p5)		osreaddl(p1,p2,p3,p4,p5)
#define	C_IREADDL(p1,p2,p3,p4,p5,p6)	osireaddl(p1,p2,p3,p4,p5,p6)
																	
#define	C_SEEK(p1,p2,p3)				osseek(p1,p2,p3)
#define	C_ISEEK(p1,p2,p3,p4)			osiseek(p1,p2,p3,p4)
#define	C_SYNC(p1,p2)					ossync(p1,p2)
#define	C_WRITE(p1,p2,p3)				oswrite(p1,p2,p3)
#define	C_IWRIT(p1,p2,p3,p4)			osiwrit(p1,p2,p3,p4)
#define	C_WRITD(p1,p2,p3,p4)			oswritd(p1,p2,p3,p4)
#define	C_IWRITD(p1,p2,p3,p4,p5)		osiwritd(p1,p2,p3,p4,p5)
										/* 制御								*/
#define	C_ACCESS(p1,p2)					osaccess(p1,p2)
#define	C_CHACC(p1,p2,p3)				oschacc(p1,p2,p3)
#define	C_CHOWN(p1,p2,p3)				oschown(p1,p2,p3)
#define	C_DUP(p1)						osdup(p1)
#define	C_FCNTL(p1,p2,p3)				osfcntl(p1,p2,p3)
#define	C_GFINF(p1,p2,p3,p4)			osgfinf(p1,p2,p3,p4)
																	
#define	C_GLOCK(p1)						osglock(p1)
#define	C_GTACC(p1,p2)					osgtacc(p1,p2)
#define	C_GTIDN(p1)						osgtidn(p1)
#define	C_GTWKD(p1,p2)					osgtwkd(p1,p2)
#define	C_GUNLOCK(p1)					osgunlock(p1)
#define	C_IOCTL(p1,p2,p3,p4)			osioctl(p1,p2,p3,p4)
#define	C_IIOCTL(p1,p2,p3,p4,p5)		osiioctl(p1,p2,p3,p4,p5)
#define	C_UMASK(p1)						osumask(p1)
/****************************************/
/*	ｼｽﾃﾑ管理							*/
/****************************************/
										/* 開始								*/
#define	C_IPL(p1,p2,p3,p4)				osipl(p1,p2,p3,p4)
#define	C_IPL2(p1,p2,p3,p4,p5)			osipl2(p1,p2,p3,p4,p5)
#define	C_RESTART(p1,p2,p3)				osrestart(p1,p2,p3)
#define	C_RESTART2(p1,p2,p3,p4)			osrestart2(p1,p2,p3,p4)
										/* 終了								*/
#define	C_SYSOFF(p1)					ossysoff(p1)
										/* 障害								*/
#define	C_SYSDOWN(p1,p2)				ossysdown(p1,p2)
#define	C_SYSDOWN2(p1,p2,p3)			ossysdown2(p1,p2,p3)
#define	C_CHGACT()						oschgact()
#define	C_CHGACT2(p1)					oschgact2(p1)
										/* 装置管理							*/
#define	C_CONFIG(p1,p2,p3)				osconfig(p1,p2,p3)
#define	C_CFPCON(p1,p2,p3,p4)			oscfpcon(p1,p2,p3,p4)
#define	C_DSPINF(p1,p2)					osdspinf(p1,p2)
#define	C_CFPRSLT(p1)					oscfprslt(p1)

#define	C_GETPTH(p1)					osgetpth(p1)
#define	C_EXCHGPTH(p1,p2)				osexchgpth(p1,p2)
										/* 運用管理							*/
#define	C_GETAPMD()						osgetapmd()
#define	C_GETHSW(p1)					osgethsw(p1)
#define	C_GETSSW(p1)					osgetssw(p1)
#define	C_SYSRCVR(p1)					ossysrcvr(p1)
#define	C_MBINF(p1,p2)					osmbinf(p1,p2)
#define	C_GETMBID()						osgetmbid()
#define	C_PRGMD(p1,p2)					osprgmd(p1,p2)
#define	C_GETPUC(p1)					osgetpuc(p1)
#define	C_GETIOS(p1)					osgetios(p1)
#define	C_GETBNO(p1)					osgetbno(p1)
#define	C_SYSMD(p1,p2)					ossysmd(p1,p2)
										/* その他							*/
#define	C_SETPTM(p1,p2)					ossetptm(p1,p2)
#define	C_GETPTM(p1,p2)					osgetptm(p1,p2)
#define	C_ENBPTM(p1)					osenbptm(p1)
#define	C_DSBPTM(p1)					osdsbptm(p1)
#define	C_EXCNTRL(p1,p2)				osexcntrl(p1,p2)
#define	C_GETSRV(p1)					osgetsrv(p1)
#define	C_CMDMD(p1)						oscmdmd(p1)
#define	C_TELREG(p1,p2,p3,p4,p5)		ostelreg(p1,p2,p3,p4,p5)
#define	C_TELDEL(p1)					osteldel(p1)
#define	C_TELGET(p1,p2,p3,p4)			ostelget(p1,p2,p3,p4)
#define	C_TELCAL(p1,p2)					ostelcal(p1,p2)
#define	C_ABTMD(p1)						osabtmd(p1)
/****************************************/
/*	Ｒａｌｌｙ関数						*/
/****************************************/
#define	C_RVINIT()				rvinit()
#define	C_RVEND()				rvend()
#define	C_RVBGET(p1,p2)			rvbget(p1,p2)
#define	C_RVBFREE(p1)			rvbfree(p1)
#define	C_RVPOST(p1)			rvpost(p1)
#define	C_RVL3OPN(p1,p2)		rvl3opn(p1,p2)
#define	C_RVL3CLS(p1,p2)		rvl3cls(p1,p2)
#define	C_RVRSTRT(p1,p2)		rvrstrt(p1,p2)
#define	C_RVRST(p1,p2,p3)		rvrst(p1,p2,p3)
#define	C_RVECHO(p1,p2)			rvecho(p1,p2)
#define	C_RVECHOE(p1,p2)		rvechoe(p1,p2)
#define	C_RVIPT(p1,p2,p3)		rvipt(p1,p2,p3)
#define	C_RVIPTR(p1,p2)			rviptr(p1,p2)
#define	C_RVL3CNF(p1,p2,p3)		rvl3cnf(p1,p2,p3)
/****************************************/
/*	ＯＳＩ−ＦＴＡＭ関数				*/
/****************************************/
#define	C_ACTOPEN(p1,p2,p3,p4)	actopen(p1,p2,p3,p4)
#define	C_ACTCLOS(p1,p2,p3)		actclos(p1,p2,p3)
#define	C_ACTPSET(p1,p2,p3,p4)		actpset(p1,p2,p3,p4)
#define	C_ACTPRSP(p1,p2,p3,p4)	actprsp(p1,p2,p3,p4)
#define	C_ACTPFRE(p1,p2,p3,p4)	actpfre(p1,p2,p3,p4)
#define	C_ACTPFRS(p1,p2,p3,p4)	actpfrs(p1,p2,p3,p4)
#define	C_ACTPSND(p1,p2,p3,p4)	actpsnd(p1,p2,p3,p4)
#define	C_ACKMANA(p1,p2,p3)		ackmana(p1,p2,p3)
#define	C_ACKMANB(p1,p2,p3)		ackmanb(p1,p2,p3)
#define	C_ACKMANC(p1,p2,p3)		ackmanc(p1,p2,p3)
#define	C_ACKMAND(p1,p2,p3)		ackmand(p1,p2,p3)
#define	C_ACKMANE(p1,p2,p3)		ackmane(p1,p2,p3)
#define	C_ACKMANF(p1,p2,p3)		ackmanf(p1,p2,p3)
#define	C_ACKMANG(p1,p2,p3)		ackmang(p1,p2,p3)

/****************************************/
/*	TRADEエミュレートでの追加	M01		*/
/****************************************/
#define	C_SETEX2(p1,p2)			ossetex2(p1,p2)
#define	C_RSTEX2(p1)			osrstex2(p1)
#define	C_CLOSE2(p1)			osclose2(p1)
#define	C_CONN2(p1)				osconn2(p1)
#define	C_DCONN2(p1)			osdconn2(p1)
#define	C_OPEN2(p1,p2,p3,p4,p5,p6)	osopen2(p1,p2,p3,p4,p5,p6)
#define	C_IREADD2(p1,p2,p3,p4,p5)	osireadd2(p1,p2,p3,p4,p5)
#define	C_WRITE1(p1,p2,p3)	oswrite1(p1,p2,p3)
#define	C_IWRITD2(p1,p2,p3,p4,p5)	osiwritd2(p1,p2,p3,p4,p5)
#define	C_IOCTL1(p1,p2,p3,p4)	osioctl1(p1,p2,p3,p4)
#define	C_IOCTL2(p1,p2,p3,p4)	osioctl2(p1,p2,p3,p4)
#define	C_IIOCTL2(p1,p2,p3,p4,p5)	osiioctl2(p1,p2,p3,p4,p5)
#define	C_SENMS2(p1,p2,p3)			ossenms2(p1,p2,p3)

										/* CORBA関数追加 2003/07/10 start */
/*************/
/* CORBA関数 */
/*************/
#define C_CORBA_ORB_init(p1,p2,p3,p4)				CORBA_ORB_init(p1,p2,p3,p4)
#define C_CORBA_ORB_BOA_init(p1,p2,p3,p4,p5)		CORBA_ORB_BOA_init(p1,p2,p3,p4,p5)
#define C_CORBA_ORB_resolve_initial_references(p1,p2,p3)	CORBA_ORB_resolve_initial_references(p1,p2,p3)
#define C_FJ_ImplementationRep_lookup_id(p1,p2,p3)	FJ_ImplementationRep_lookup_id(p1,p2,p3)
#define C_CORBA_BOA_impl_is_ready(p1,p2,p3)			CORBA_BOA_impl_is_ready(p1,p2,p3)
#define C_CORBA_BOA_deactivate_impl(p1,p2,p3)		CORBA_BOA_deactivate_impl(p1,p2,p3)
#define C_CosNaming_NamingContext_resolve(p1,p2,p3)	CosNaming_NamingContext_resolve(p1,p2,p3)
#define C_CORBA_ORB_set_client_timer(p1,p2,p3,p4)	CORBA_ORB_set_client_timer(p1,p2,p3,p4)
#define C_lala_nodekan_Octets_alloc()				lala_nodekan_Octets_alloc()
#define C_lala_nodekan_Octets_allocbuf(p1)			lala_nodekan_Octets_allocbuf(p1)
#define C_lala_nodekan_msgsnd(p1,p2,p3,p4,p5,p6,p7)	lala_nodekan_msgsnd(p1,p2,p3,p4,p5,p6,p7)
#define C_CORBA_sequence_set_release(p1,p2)			CORBA_sequence_set_release(p1,p2)
#define C_CORBA_free(p1)							CORBA_free(p1)
#define C_CORBA_Object_release(p1,p2)				CORBA_Object_release(p1,p2)
										/* CORBA関数追加 2003/07/10 end */

#endif
