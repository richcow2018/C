/****************************************************************************/
/*	ＭＳ運転実行共通ヘッダファイル											*/
/****************************************************************************/
/*************************** 標準ヘッダファイル *****************************/
#include	"osanyrl.h"
#include	"oscrepr.h"
#include	"osdelbp.h"
#include	"osdelmb.h"
#include	"osfrpbf.h"
#include	"osrcvmspr.h"
#include	"osrcvmsr.h"
#include	"osrsrrd.h"
#include	"ossenms.h"
#include	"ossigsp.h"
#include	"ossstd.h"
#include	"oswaitsp.h"

#include	"tadt.h"
#include	"tbpt.h"
#include	"tcom.h"
#include	"tcst.h"
#include	"tlmt.h"
#include	"tpct.h"
#include	"tcmt.h"
#include	"tput.h"
#include	"tshm.h"
#include	"tsrt.h"
#include	"tsst.h"
#include	"ttct.h"
#include	"tvct.h"

/************************ 利用者作成ヘッダファイル **************************/
#include	"mo.h"
#include	"mcdebug.h"
#include	"mcmia.h"
#include	"mochar.h"
#include	"mocmex.h"
#include	"mosdwn.h"
#include	"modwncd.h"
#include	"mowtom.h"
#include	"mocom.h"
#include	"modte.h"
#include	"modted.h"
#include	"momhead.h"
#include	"mostma.h"
#include	"moms.h"
#include	"mosmp.h"
#include	"moer.h"
#include	"mokk.h"
#include	"moxlog.h"
#include	"mf.h"
#include	"mfscsi.h"
#include	"mr.h"
#include	"mrcom.h"
#include	"mrmuse.h"
#include	"mt.h"
#include	"mc.h"
#include	"mopcb.h"
#include	"mdretv.h"
#include	"psect.h"
#include	"momsdef.h"
#include	"momsinit.h"
#include	"momsextn.h"
#include	"momsrtn.h"
#include	"ms.h"
#include	"mscnst.h"
#include	"mscp.h"
										/* CT0529 1line delete	94.08.09	*/

/****************************** 共通関数定義 ********************************/
extern	long	mc_add( char *, char *, char *, long, long, long );
extern	long	mc_bpcn( long, char *, long );
extern	long	mc_bccn( long, char *, long );
extern	long	mc_cbcn( char *, long *, long );
extern	long	mc_ccom( char *, char *, long );
/*	extern	long	mc_ccpy( char *, char *, long );	*/
extern	long	mc_cequ( char *, char *, long, char );
extern	long	mc_chcn( char *, char *, long );
extern	long	mc_clea( char *, char, long );
extern	long	mc_copy( char *, char *, long );
extern	long	mc_cpcn( char *, long, char *, long );
extern	long	mc_hccn( char *, char *, long );
extern	long	mc_nmck( char *, long );
extern	long	mc_padd( char *, char * );
extern	long	mc_pbcn( char *, char * );
extern	long	mc_pccn( char *, char *, long );
extern	long	mc_pcom( char *, char * );
extern	long	mc_pdev( char *, char *, char * );
extern	long	mc_pmvl( char *, char * );
extern	long	mc_psub( char *, char * );
extern	long	mc_save( char *, char *, long *, long *, long * );

/****************************** ＭＳ関数定義 ********************************/
extern	long	mo_gtbf( long, long, long ** );
extern	long	mo_frbf( long * );
extern	long	mo_gabf( long, long, long ** );
extern	long	mo_chcn( char *, char *, long );
extern	void	mo_trdn( long, long, long );
extern	long	mo_trfn( long );
extern	void	mo_trcn( void );
extern	void	mo_sdwn( long, long, long );
extern	void	mo_wtom( long, UCHR ** );
