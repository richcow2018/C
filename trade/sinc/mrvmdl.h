/****************************************************************************/
/*	�������������														*/
/*			���Σԣԥǡ����̿��������										*/
/*				��ͻ�����ƥ��������										*/
/*																			*/
/*																			*/
/*	����ʪ�����ãšݣӣͣХ����ƥࡡ										*/
/*				�ңã֡��ܥ�塼��ꥫ�Х�ʣƣ�̵����	(mr_vxxx��)			*/
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*���оݶ�̳̾��					 �ξ������̳							*/
/*���оݶ�̳�ɣġ�					 �ңã�									*/
/*�㥵���ӥ�����̾��				 										*/
/*�㥵���ӥ����ܣɣġ�				 										*/
/*��⥸�塼��̾��					 �֣ңã֡ʣƣ�̵���˴ؿ����			*/
/*��⥸�塼��ɣġ�				 										*/
/*��⥸�塼�����֡�														*/
/*--------------------------------------------------------------------------*/
/*��Ŭ�ѵ����						 ���ã�									*/
/*��Ŭ�ѣϣӡ�						 �ԣң��ģ�								*/
/*�㳫ȯ�Ķ���						 �ӣգ�  �ӣУ��ңáݣɣУ�				*/
/*�㵭�Ҹ����						 �ø���									*/
/*��⥸�塼����֡�				 �ؿ�									*/
/*�㵡ǽ��ʬ��																*/
/*���оݥǡ�����															*/
/*�㹩�������ض�ʬ��				 										*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯ�����ƥ�̾��				 ���ãšݣӣͣХ����ƥ�					*/
/*�㳫ȯ�����ƥ��ֹ��				 ������������������������				*/
/*--------------------------------------------------------------------------*/
/*�㳫ȯô��̾��					 �Ķ�Ź�����ƥ�ô��						*/
/*�������ֹ��						 169-3537(03-5702-3537)					*/
/*--------------------------------------------------------------------------*/
/*���߷׼�̾��						 �ƺꡡ�һ�								*/
/*���߷�ǯ������					 ��������ǯ���������					*/
/*���߷׽�����̾��				 	 ����  ����								*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������	ST3804			*/
/*--------------------------------------------------------------------------*/
/*�㥽����������̾��				 �ƺꡡ�һ�								*/
/*�㥽��������ǯ������				 ��������ǯ���������					*/
/*�㥽����������̾��				 ���桡����					ST2806      */
/*�㥽��������ǯ������				 ��������ǯ���������					*/
/*�㥽����������̾��				 �ƺꡡ�һ�								*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������	ST2893			*/
/*�㥽����������̾��				 �ƺꡡ�һ�								*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������	CT1093(ST2995)	*/
/*�㥽����������̾��				 �ƺꡡ�һ�								*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������	CT1091(ST2993)	*/
/*�㥽����������̾��				 ����  ����								*/
/*�㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������	ST3804			*/
/*--------------------------------------------------------------------------*/
/*�㸫�ѥ��ƥå׿���				 ���������ƥå�							*/
/*--------------------------------------------------------------------------*/
/*�㵡ǽ���ס�																*/
/*		�֣ңã֡ʣƣ�̵���˥ץ����ǻ��Ѥ��볰���ؿ������				*/
/*--------------------------------------------------------------------------*/
/*��ƽз�����																*/
/*																			*/
/*�㲾��������																*/
/*																			*/
/*���ֵ��͡�   																*/
/*--------------------------------------------------------------------------*/
/*�������ϥǡ�����¤��														*/
/*																			*/
/*�����»����																*/
/*	  �äˤʤ�																*/
/*																			*/
/*����ѳ����⥸�塼��ɣġ�												*/
/*																			*/
/*��ƽи��Υ⥸�塼��ɣġ�												*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*	�ԣң��ģť����ƥॳ����												*/
/****************************************************************************/
/****************************************/
/*	�¹Դ��������ƥॳ����				*/
/****************************************/
extern	long	oscrepr( char *, long, long, osepib *, osearg * );
extern	long	oswchld( long, oseprtrm *, long );
extern	long	ossenmsp( long, long, char * );
extern	long	osrcvmsp( long, long, char ** );
extern	long	osrcvmspr( long, long, char ** );
extern	long	ossnsms( long );
extern	long	osanyrl( long *, long );
extern	long	oscanrq( long );
extern	long	ossttim( long, long, long );
extern	long	osgtdat( long *, long * );

/****************************************/
/*	�ե�������������ƥॳ����			*/
/****************************************/
extern	long	osclose( long );
extern	long	oscreat( char *, long, long, long, long, long, long );
extern	long	osdconn( long );
extern	long	osdelet( long );
extern	long	osexten( long, long );
extern	long	osmount( char *, char *, long );
extern	long	osopen( long, long, long, long, long, long );
extern	long	ostrunc( long );
extern	long	osumount( char * );
extern	long	osumountf( char * );
extern	long	osread( long, char *, long );
extern	long	osseek( long, long, long );
extern	long	oswrited( long, char *, long, long );
extern	long	osgfinf( long, long, struct osf_info *, long );
extern	long	osioctl( long, long, char *, long );
extern	long	osiioctl( long, long, long, char *, long );

/****************************************/
/*	�����ƥ����楷���ƥॳ����			*/
/****************************************/
extern	long	osconfig( long, long, long );

/****************************************************************************/
/*	�󶡴ؿ��������ӥ������롦���̴ؿ�										*/
/****************************************************************************/
/****************************************/
/*	�ϣã��󶡴ؿ�						*/
/****************************************/
extern	long	mo_crpr( char *, long, char ** );
extern	long	mo_frbf( long * );
extern	long	mo_excm( char * );
extern	long	mo_date( unsigned long *, unsigned long * );
extern	void	mo_wlg4( long, long, long, long *, long );
extern	long	ms_uwto( long, short, char, long );
extern	long	ms_wtop( long, short, char, char, long, long );

/****************************************/
/*	�ģãХ����ӥ�������				*/
/****************************************/
extern	long	md_cedt( char, char, short, char *, short );
extern	long	md_cput( void );

/****************************************/
/*	�ңã��󶡴ؿ�						*/
/****************************************/
extern	long	mr_jopn( char *, char );
extern	long	mr_jcls( void );
extern	long	mr_jedt( short, char *, char *, char *, long, long, long );
extern	long	mr_jnl( char );
extern	long	mr_jint( void );
extern	void	mr_sabt( short, long, long, long );
extern	void	mr_sdwn( long, short, long );
extern	long	mr_ejrq( char, short, char * );
extern	long	mr_cpca( short, char );

/****************************************/
/*	�ңã��ⶦ�̴ؿ�					*/
/****************************************/
extern	long	mr_cgbf( long, long, long ** );
extern	void	mr_cmia( MCMIKYO *, short );
extern	TPCTPSZ	*mr_cpct( char * );
extern	TPCTPSZ	*mr_cpct2( char *, char );
extern	long	mr_bbks( char, char * );
extern	long	mr_bmnt2( TVBTPSZ * );
extern	long	mr_bumt2( TVBTPSZ * );
extern	void	mr_pexs( void (*)() );	/* AP�㳰�ؿ�����Ͽ		ST2806		*/

/****************************************/
/*	�ƣɣ��󶡴ؿ�						*/
/****************************************/
extern	long	mf_fgtp( long, char * );
extern	long	mf_fioc( long, char );
extern	long	mf_rtgt( char * );
extern	long	mf_renq( long *, char *, long, char );
extern	long	mf_rdeq( long *, long );
extern	void	mf_rieq( void );
extern	long	mf_fgef( long, long );
extern	long	mf_fsiz( long );

/****************************************/
/*	���̴ؿ�							*/
/****************************************/
extern	long	mc_add( char *, char *, char *, long, long, long );
extern	long	mc_bpcn( long, char *, long );
extern	long	mc_bccn( long, char *, long );
extern	long	mc_cbcn( char *, long *, long );
extern	long	mc_ccom( char *, char *, long );
extern	long	mc_ccpy( char *, char *, long );
extern	long	mc_cequ( char *, char *, long, char );
extern	long	mc_chcn( char *, char *, long );
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
/*	extern	long	mc_clea( char *, char, long );	*/

/****************************************/
/*	�֣ңã������ؿ�					*/
/****************************************/
extern	void	mr_vwto( char *, char *, char *, char *, char *, char * );
																/*	ST2893	*/
extern	long	mr_vint( long, char ** );
extern	long	mr_vsck( void );
extern	long	mr_vpcb( void );
extern	long	mr_vpck( void );
extern	long	mr_vack( long, char ** );
extern	long	mr_vanc( long, char ** );
extern	long	mr_varc( long, char ** );
extern	long	mr_vmtc( void );
extern	long	mr_vmrq( void );
extern	long	mr_vjop( void );
extern	long	mr_vrst( void );
extern	long	mr_vjed( char *, char *, char *, long, long );
extern	long	mr_vjnl( void );
extern	void	mr_vjaf( void );
extern	long	mr_vrcv( void );
extern	long	mr_vins( void );
extern	long	mr_vany( long * );
extern	long	mr_vtim( void );
extern	long	mr_vvck( MRVRVMT * );
extern	long	mr_vrvc( MRVRVMT * );
extern	long	mr_vnvc( MRVRVMT * );
extern	long	mr_vpvt();
/*extern	long	mr_vpvt( short );*/
extern	long	mr_vtwt( MRVRVMT * );
extern	long	mr_vrvm( MRVRVMT *, unsigned char * );
extern	long	mr_vprv( MRVRVMT * );
extern	long	mr_vvin();
/*extern	long	mr_vvin( short );*/
extern	long	mr_vmvt( MRVRVMT * );
extern	long	mr_vmrv( MRVRVMT * );
extern	long	mr_vnbv( MRVRVMT * );
extern	long	mr_vvbt();
/*extern	long	mr_vvbt( short );*/
extern	long	mr_vumc();
/*extern	long	mr_vumc( short, short );*/
extern	long	mr_vvlc();
/*extern	long	mr_vvlc( short, short );*/
extern	long	mr_vrvv( MRVRVMT * );
extern	long	mr_vmnt();
/*extern	long	mr_vmnt( short );*/
extern	TFMTPSZ	*mr_vrvf();
/*extern	TFMTPSZ	*mr_vrvf( unsigned char );*/
extern	long	mr_vtrv( MRVRVMT * );
extern	long	mr_vmsg( MRVRVMT * );
extern	long	mr_vmtr( MRVRVMT * );
extern	long	mr_vptr( MRVRVMT * );
extern	long	mr_vfmt( MRVRVMT * );
extern	long	mr_vfml();
/*extern	long	mr_vfml( short, TFMTPSZ *** );*/
extern	long	mr_vdfc( char *, long, MRVRVMT *, TFMTPSZ ** );
extern	long	mr_vfdr( char *, long, MRVRVMT *, long, TFMTPSZ ** );
extern	long	mr_vffl( char *, long, MRVRVMT *, long,
								struct osf_info *, TFMTPSZ ** );
extern	long	mr_vfdl( long, char *, MRVRVMT * );
extern	long	mr_vfmd( TFMTPSZ * );
extern	long	mr_vutr( MRVRVMT * );
extern	long	mr_vumd();
/*extern	long	mr_vumd( short );*/
extern	long	mr_vucr();
/*extern	long	mr_vucr( short );*/
extern	long	mr_vfck();
/*extern	long	mr_vfck( short, short );*/
extern	long	mr_vfit();
/*extern	long	mr_vfit( long, short, MFCCRT * );*/
extern	long	mr_vurd();
/*extern	long	mr_vurd( long,	short );*/
extern	long	mr_vwtr( MRVRVMT * );
extern	long	mr_vwmd();
/*extern	long	mr_vwmd( short );*/
extern	long	mr_vwmt();
/*extern	long	mr_vwmt( short );*/
extern	long	mr_vvmt( MRVRVMT * );
extern	long	mr_vvmi();
/*extern	long	mr_vvmi( short, long * );*/
extern	long	mr_vejq();
/*extern	long	mr_vejq( short );*/
extern	long	mr_vrms( MRVRVMT * );
extern	long	mr_vcrs( void );
extern	long	mr_vver( void );
extern	void	mr_vsvt( MRVRVMT * );
extern	long	mr_vstp( void );
extern	long	mr_vvrs( MRVRVMT * );		/*						CT1091	*/
extern	void	mr_vtrm( void );
extern	long	mr_vocr( char *, long, long, long, long, long, long );
extern	long	mr_vocl( long );
extern	long	mr_vodl( long );
extern	long	mr_voex( long, long );
extern	long	mr_vomt( char *, char *, long );
extern	long	mr_vord( long, char *, long );
extern	long	mr_votr( long );
extern	long	mr_voum( char * );
extern	long	mr_vowt( long, char *, long, long );
extern	long	mr_vouf( char * );
extern	void	mr_vabt();					/* 						ST2806	*/
extern	long	mr_verf( char *, char ** );	/*						ST2893	*/
extern	long	mr_vsiz( char * );			/*						CT1093	*/
extern	long	mr_venq( MRVRVMT * );		/*						CT1091	*/
extern	void	mr_vdeq( MRVRVMT * );		/*						CT1091	*/
extern	long	mr_veof();					/*						ST3804	*/
