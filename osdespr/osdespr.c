/************************************************************************************************/
/*	���	��������																			*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�	�ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 �㳰����													*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 �ץ������ζ�����λ											*/
/* ��⥸�塼��ɣġ�				 osdespr													*/
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
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô��										*/
/* ���߷�ǯ������					 ��������ǯ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ� 				 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�����ѹ��ֹ�ʣӣӣ̣�����������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		�ץ���������Ū�˽�λ�����롣															*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osdespr.h>																	*/
/*																								*/
/*		long	osdespr( long pid , long code )													*/
/*																								*/
/* �㲾������																					*/
/*		long	pid				�ץ��������̻�													*/
/*		long	code			��λ������														*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEIPID		�ץ��������̻Ұ۾�										*/
/*						OSEENEXS		�оݥץ�������¸�ߤ��ʤ���								*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*		�äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include<sys/types.h>                  //kill�ѥإå��� 
#include<signal.h>                  

/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "osdespr.h"
#include "osdespr_ins.h"

/*****************************************************************************/
/* ��ǽ���ץ������ζ�����λ                                                  */
/* ��������2002ǯ11��06��                                                    */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ��������                                                        */
/* �ƽз�����long osdespr(long pid,long code)                                */
/*                                                                           */
/*           long pid;    �ץ��������̻�                                     */
/*           long code;   ��λ������                                         */
/*                                                                           */
/*****************************************************************************/
long osdespr(long pid,long code)
{
/********************************************************************************/
/*	�ѿ����																	*/
/********************************************************************************/
	TEprcTableInd *ptTableInd = NULL;           //�ץ����������ơ��֥�������Υ��ɥ쥹
	long lPinf = 0;                             //�ץ���������
	int iRet = 0;                               //kill���ֵ���
/*****	�����ѹ��ֹ�SSLA0033���б�		Start							��������2003.07.02	*****/
	long lEndCode = 0;							// ��λ������
/*****	�����ѹ��ֹ�SSLA0033���б�		 End							��������2003.07.02	*****/

/********************************************************************************/
/*	�������																	*/
/********************************************************************************/
	os_trcget2( D_MD_OSDESPR, D_T_TRA_IN, 2, pid, code  );
	
//	DbgMsg01(DLv02,(OutPut,"**** osdespr: Start DbgMainFunc\n")); 
	//�ץ��������̻������������å�
//	DbgMsg01(DLv04,(OutPut,"**** osdespr: pid=%x code=%x\n",pid,code)); 

	if((pid & 0x00ff0000)!=0x00010000 &&    //���̤�1�Ǥʤ�
	   (pid & 0x00ffffff)!=0x0)             //���̡����֤Τ����ɤ��餫��0�Ǥʤ�
	{
		os_trcget2( D_MD_OSDESPR, D_T_ERR_PRA, 1, OSEEIPID );
		
		DbgMsg01(DLv05,(OutPut,"**** osdespr: Err osdespr:Ret=%x\n",OSEEIPID));
		return(OSEEIPID);
	}

/********************************************************************************/
/*	�ܽ���																		*/
/********************************************************************************/
											// 20030303 �ɲ�
	if( (pid & 0x00ffffff) == 0x0 )			// �������ֶ���0�λ����ץ�������λ
	{
		ptTableInd = ptMyEPRC;
	}
	else
	{
	
		//�ץ�������ư�ѥ����å�
		DbgMsg01(DLv02,(OutPut,"**** osdespr: Stsrt os_GstPrSep\n"));
		lPinf=os_GstPrSep(1,pid);			//�ץ��������̻Ҥ���ץ����������ơ��֥�򸡺�
		DbgMsg01(DLv02,(OutPut,"**** osdespr: End os_GstPrSep Pinf=%ld\n",lPinf));
		if(lPinf==-1)						//�ץ��������������ʤ�
		{
			os_trcget2( D_MD_OSDESPR, D_T_ERR_SYS, 0 );

			DbgMsg01(DLv05,(OutPut,"**** osdespr:Err os_GstPrSep: Pinf=%ld\n",lPinf)); 
			return(OSEENEXS);
		}
		ptTableInd=(TEprcTableInd *)(ptEprc+1); //�ץ����������ơ��֥��������
		                                        //��Ƭ���ɥ쥹������
		ptTableInd += lPinf;                    //�����ץ����������ơ��֥��������
		                                        //���ɥ쥹������
	}
	
	DbgMsg01(DLv04,(OutPut,"**** osdespr: Pid=%ld\n",ptTableInd->lPid));
	if(!ptTableInd->lPid)                   //�ץ������ɣĤ�0
	{
		DbgMsg01(DLv04,(OutPut,"**** osdespr: invalid Pid=%ld\n",ptTableInd->lPid));
		DbgMsg01(DLv04,(OutPut,"**** osdespr: Err osdespr:Ret=%ld\n",OSEENEXS));
		
		os_trcget2( D_MD_OSDESPR, D_T_ERR_PRA, 1, OSEENEXS );
		
		return(OSEENEXS);
	}
	
	/************************************************/
	/*	�ץ������ζ�����λ							*/
	/************************************************/
/*****	�����ѹ��ֹ�SSLA0033���б�		Start							��������2003.07.02	*****/
	lEndCode = (code | 0x80000000);				// �ʰ����˽�λ�����ɤ���Ƭ�ӥåȤ�Ω�Ƥ�
/*****	�����ѹ��ֹ�SSLA0033���б�		 End							��������2003.07.02	*****/
	ptTableInd->lEndCode = lEndCode;			// ��λ�����ɤ�����
	DbgMsg01(DLv04,(OutPut,"**** osdespr: EndCode=%08lx\n",ptTableInd->lEndCode));
	
	os_trcget2( D_MD_OSDESPR, D_T_SYS_KILL, 2, ptTableInd->lPid, SIGTERM );
	
    iRet=kill(ptTableInd->lPid,SIGTERM);
    
    os_trcget2( D_MD_OSDESPR, D_T_SYS_END, 1, iRet );
    
    DbgMsg01(DLv04,(OutPut,"**** osdespr: End kill: Ret=%d\n",iRet));
	if(iRet==D_ERR_SYS)                      //kill�۾ｪλ
	{
		os_trcget2( D_MD_OSDESPR, D_T_ERR_SYS, 0 );
		
		DbgMsg01(DLv05,(OutPut,"**** osdespr: Err kill:Ret=%d\n",iRet));
		//errno�ˤ�륨�顼����������̤���
	}
//	DbgMsg01(DLv02,(OutPut,"**** osdespr:End DbgMainFunc:Ret=%x\n",NORMAL));
	
	os_trcget2( D_MD_OSDESPR, D_T_TRA_OUT, 1, NORMAL );

	return(NORMAL);
}
/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/