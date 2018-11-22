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
/* �㥵���ӥ�����̾��				 ���Ѵ���													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ץ����⡼�����꡿����									*/
/* ��⥸�塼��ɣġ�				 osprgmd													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 �ѥͥ���Ф��ƥץ����⡼�ɤ�����/�ɼ��Ԥ���											*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osprgmd.h>																	*/
/*																								*/
/*	   	long	osprgmd(long lMode, long *plInf)												*/
/*																								*/
/* �㲾������																					*/
/*		clong	lMode;		���꡿�ɼ�μ���													*/
/*		long	*plInf;		�ץ����⡼�ɳ�Ǽ���ꥢ											*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���������																				*/
/*			NORMAL		����������ɼ��Ԥä�													*/
/*																								*/
/*		�۾������																				*/
/*			OSSIVMD		MODE�θ�ꡣ(���꡿�ɼ�ϹԤ��ʤ�)									*/
/*			OSSERR		����ΰ۾ｪλ��(����ϹԤ��ʤ�)										*/
/*			OSSNOACC	���ꤵ�줿��Ǽ�ΰ褬��������­�����⤷���ϥ��������Ǥ��ʤ�				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		�⡼�ɻ���ΰ������֥ץ����⡼�ɤ�����(OSSPUTPG)�פξ�硢��������򤷤ʤ�			*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
/***************************** ���ѼԺ����إå����ե����� ***************************************/
#include "osprgmd.h"
#include "osprgmd_ins.h"

long osprgmd(long lMode, long *plInf)
{
/****************************************/
/*	�ѿ����							*/
/****************************************/
	long lRes = 0;								/*	�ֵ�����				*/
	long lModeNum = 0;							/*	�⡼���Ѵ����Ǽ��		*/
	long lCnt = 0;								/*	������				*/
	char acPass[128];							/*	�ץ����⡼�ɥե�����Υѥ�	*/
	char acModeDat[16];							/*	�ץ����⡼�ɿ����ɹ���		*/
	char acTemp[16];							/*	�켡�ɤ߹�����			*/
	FILE *pfPassAdr = NULL;
	
	
	os_trcget2( D_MD_OSPRGMD, D_T_TRA_IN, 2, lMode, plInf );

	
//	DbgMsg01( DLv01, ( OutPut, "***** Start osprgmd *****\n" ) );
//	DbgMsg01( DLv02, ( OutPut, "***** lMode:%lx\n", lMode) );
//	DbgMsg01( DLv02, ( OutPut, "***** plInf:%08lx\n", plInf) );
	
/****************************************/
/*	�������							*/
/****************************************/
	
	memset( (void *)acPass,0,128);				/* ʸ������ν����	*/
	
	memset( (void *)acModeDat,0,16);
	
	memset( (void *)acTemp,0,16);

	/*	���������å�	*/
	if(OSSPUTPG == lMode)						/*	OSSPUTPG �λ��ϲ��⤻�����ｪλ����	*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, NORMAL );
		
		DbgMsg01( DLv05, ( OutPut, "***** 01:Parameter OSSPUTPG return NORMAL\n") );
		return(NORMAL);
	}
	else if(OSSGETPG != lMode)					/*	OSSGETPG �ʳ��ϰ۾ｪλ		*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, OSSIVMD );
		
		DbgMsg01( DLv05, ( OutPut, "***** 02:�ѥ�᥿ Err return OSSIVMD\n") );
		
		return(OSSIVMD);
	}
	
	if(NULL == plInf)							/*	plInf NULL�ʤ�۾ｪλ		*/
	{
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_PRA, 1, OSSNOACC );
		
		DbgMsg01( DLv05, ( OutPut, "***** 03:Parameter Err return OSSNOACC\n") );
		
		return(OSSNOACC);
	}
	
	DbgMsg01( DLv04, ( OutPut, "***** SG �ɤ߹���\n"));
	lRes = os_getSG(D_SG_PRGMD_PASS,acPass);	/*	SG����ѥ����ɤ߹���		*/
	if(NORMAL != lRes)
	{
		DbgMsg01( DLv05, ( OutPut, "***** 04:SG Read Err \n") );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSNOACC );
		
		return(OSSNOACC);
	}
	DbgMsg01( DLv04, ( OutPut, "***** �ɹ���ѥ� : %s\n", acPass) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FOPEN, 2, acPass, "r" );
	
	pfPassAdr = fopen(acPass, "r");
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 1, pfPassAdr );
	
	if(NULL == pfPassAdr)
	{											/*	�ե����륪���ץ���		*/
		DbgMsg01( DLv05, ( OutPut, "***** �ե����륪���ץ���\n") );
		DbgMsg01( DLv05, ( OutPut, "***** 05:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSNOACC );
		
		return(OSSNOACC);
	}
	DbgMsg01( DLv04, ( OutPut, "***** pfPassAdr : %lx\n", pfPassAdr) );
	
/****************************************/
/*	�ܽ���								*/
/****************************************/
/*****  �㳲�б���TBCS0272��    Start                                   ��������2003.08.11  *****/
/************************************************************************************************/
/*  fgets()����fread()�˽���                                                                    */
/************************************************************************************************/
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FREAD, 4, acTemp, D_READ_BYTE, 16, pfPassAdr );
	lRes = fread(acTemp, D_READ_BYTE, 16, pfPassAdr);
/*****  �㳲�б���TBCS0272��    End                                     ��������2003.08.11  *****/
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 1, acTemp );
		
	if(NULL == acTemp)
	{
		DbgMsg01( DLv05, ( OutPut, "***** �ɤ߹��߼���\n") );
		DbgMsg01( DLv05, ( OutPut, "***** 06:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_SYS_FCLOSE, 1, pfPassAdr );	
		
		fclose(pfPassAdr);
		
		os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 0 );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
		
		return(OSSERR);
	}
	DbgMsg01( DLv04, ( OutPut, "***** �ɤ߹����ʸ���� :%s\n", acTemp) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_FCLOSE, 1, pfPassAdr );	
	
	fclose(pfPassAdr);
	
	os_trcget2( D_MD_OSPRGMD, D_T_SYS_END, 0 );
	
	for(lCnt = 0;lCnt < 6;lCnt++)				/*	��Ƭ����6ʸ����������ɤ߹��ߥ����å�����	*/
	{
		if( 0 != isxdigit( acTemp[lCnt] ))	/*	0��9,a��f,A��F�Τߤ��ɤ߹���	*/
		{
			acModeDat[lCnt] = acTemp[lCnt];
			DbgMsg01( DLv04, ( OutPut, "***** acModeDat[%ld]:", lCnt) );
			DbgMsg01( DLv04, ( OutPut, "%x:%c\n", acModeDat[lCnt], acModeDat[lCnt]) );
		}
		else
		{
			acModeDat[0] = '\0';				/*	 ����ʳ�����������		*/
			DbgMsg01( DLv04, ( OutPut, "***** 07:Err Mess:%s\n", strerror(errno) ) );
			
			os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
			
			return(OSSERR);
		}
		
	}
	acModeDat[lCnt] = '\0';

	lRes = strtol(acModeDat, NULL, 16);			//	ʸ���������Ѵ� ʸ����16�ʿ�
	if( (ERANGE  == errno) ||
		(EINVAL  == errno) )
	{
		DbgMsg01( DLv05, ( OutPut, "***** 08:Err Mess:%s\n", strerror(errno) ) );
		
		os_trcget2( D_MD_OSPRGMD, D_T_ERR_SYS, 1, OSSERR );
		
		return(OSSERR);
	}
	
	lModeNum = lRes;
	DbgMsg01( DLv04, ( OutPut, "***** �Ѵ����줿��(16��):%08lx\n", lModeNum ) );
	
/****************************************/
/*	��λ����							*/
/****************************************/
	*plInf = lModeNum;							/*	�������ͤ���������	*/
//	DbgMsg01( DLv01, ( OutPut, "***** End osprgmd *****\n" ) );
	
	os_trcget2( D_MD_OSPRGMD, D_T_TRA_OUT, 1, NORMAL );	
	
	return(NORMAL);
}

/************************************************************************************************/
/*  End                                                                                         */
/************************************************************************************************/
