/************************************************************************************************/
/*                                                                                              */
/*  �����������ե�����̾                                                                        */
/*      osrstex2.c                                                                              */
/*                                                                                              */
/*                                                                                              */
/*  �����ץ������̾��                                                                          */
/*      �㳰�ϥ�ɥ�Υꥻ�å�                                                                  */
/*                                                                                              */
/*                                                                                              */
/*  ������ǽ����                                                                                */
/*      ���ץ����������ơ��֥��������Ρʰ����ǻ��ꤵ�줿�˥����ʥ�ϥ�ɥ�������            */
/*      �㳰�ϥ�ɥ�Υ��ɥ쥹��ꥻ�åȤ��롣                                                  */
/*                                                                                              */
/*                                                                                              */
/*  �����ƤӽФ�����                                                                            */
/*      long    osrstex2()                                                                      */
/*                                                                                              */
/*                                                                                              */
/*  ��������                                                                                    */
/*      int     sig                                                                             */
/*                                                                                              */
/*                                                                                              */
/*  �����ֵ���                                                                                  */
/*      NORMAL      ��������㳰�ϥ�ɥ�Υꥻ�åȤ��Ǥ���                                      */
/*      OSEEICLS    �������ʥ���ͤ������Ǥ���                                                  */
/*      OSEENEXS    ���㳰�ϥ�ɥ餬���ꤵ��Ƥ��ʤ�                                            */
/*                                                                                              */
/*                                                                                              */
/*  ����������ࡦ�õ�����                                                                      */
/*      �ʤ�                                                                                    */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/


/************************************************************************************************/
/*  ���󥯥롼�ɥե�����                                                                        */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/


/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include	"osrstex.h"
#include	"osrstex_ins.h"


long	osrstex2(sig)
int		sig;										/* �����ʥ�									*/
{
	/********************************************************************************************/
	/*  ����ΰ�                                                                              */
	/********************************************************************************************/
	long	lEndCode;								/* ��λ������								*/
    struct sigaction	tAct;						/* �����ʥ���								*/

	os_trcget2( D_MD_OSRSTEX2, D_T_TRA_IN, 0 );
													/* �ؿ�����									*/
	DbgMsg01(DLv02, (OutPut, "\n***** %s:Start DbgSubFnc\n", "osrstex2"));

//	DbgMsg01(DLv04, (OutPut, "***** %s:sig = %d \n", "osrstex2", sig));


	/********************************************************************************************/
	/*  �������                                                                                */
	/********************************************************************************************/
	/****************************************/
	/*  ���������å�						*/
	/****************************************/
													/* �����ʥ뤬 1(SIGHUP)̤��������			*/
													/* �����ʥ뤬31(SIGSYS)��Ķ�᤹����		*/
	if ((SIGHUP > sig) || (SIGSYS < sig))
	{
//		DbgMsg01(DLv05, (OutPut, "***** %s:%s  %s \n", "osrstex2",
//				"�����۾�!!", "�����ʥ���ͤ������Ǥ��롣"));
		os_trcget2( D_MD_OSRSTEX2, D_T_ERR_PRA, 2, sig , OSEEICLS );

		return(OSEEICLS);							/* invalid class							*/
	}


    /********************************************************************************************/
    /*  �ᥤ�����                                                                              */
    /********************************************************************************************/
	/****************************************/
	/*  �㳰�ϥ�ɥ����Ͽ					*/
	/****************************************/
													// ̤��Ͽ���ϥ��顼�ֵ�
	if( D_ADR_INI == ptMyEPRC->func[(sig -1)] )		// 20030228 �ɲ�
	{
		os_trcget2( D_MD_OSRSTEX2, D_T_ERR_PRA, 2, sig , OSEENEXS );
		return(OSEENEXS);
	}
	ptMyEPRC->func[(sig -1)] = D_ADR_INI;			/* �㳰�ϥ�ɥ�Υ��ɥ쥹��ꥻ�å�			*/


    /********************************************************************************************/
    /*  ��λ����                                                                                */
    /********************************************************************************************/

													/* �ؿ��и�									*/
	DbgMsg01( DLv02, ( OutPut, "\n***** %s: End  DbgSubFnc\n", "osrstex2" ) );
	os_trcget2( D_MD_OSRSTEX2, D_T_TRA_OUT, 1, NORMAL );
	return(NORMAL);									/* ���ｪλ									*/
}
/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/