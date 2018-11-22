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
/* �㥵���ӥ�����̾��				 ���٥������												*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ�												*/
/* ��⥸�塼��̾��					 ���ޥե�������												*/
/* ��⥸�塼��ɣġ�				 oscresp													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(:�أأأ�)						*/
/* �����ԡ�����                                                                                   */
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* ��������2002ǯ7��26��                                                                          */
/* �㥽���������ԡ� 			 	 															*/
/* �㥽������ǯ�����ڤӽ����ɣġ�    															*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���ޥե�������																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oscresp.h>																	*/
/*																								*/
/*	   	long	oscresp( long value, long spid, long access )  									*/
/*																								*/
/* �㲾������																					*/
/*		long	value;		���ޥե��ν���͡�0x0000��0x7ffff��									*/
/*		long	spid;		���ޥե����̻ҡ�0�ʳ������͡�										*/
/*		long	access;		������������̤���ѡ�0������										*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		���ޥե����̻�															*/
/*		�۾ｪλ		OSEEIVAL																*/
/*	   					OSEEISPI																*/
/*						OSEEEXST																*/
/*						OSEEWKEX																*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤�� 																		*/
/* �����»���� 																				*/
/*	   �äˤʤ� 																				*/
/* ����ѳ����⥸�塼��ɣġ�																	*/
/* ��ƽи��Υ⥸�塼��ɣġ�																	*/
/*																								*/
/*																								*/
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include "oscresp.h"
#include "oscresp_ins.h"

/**************************************************************************************************/
/* ��ǽ�����ޥե�������                                                                           */
/* ��������2002ǯ7��26��                                                                          */
/* �ѹ�����                                                                                       */
/* �����ԡ�����                                                                                   */
/* �ƽз�����                                                                                     */
/*   long oscresp( long value, long spid, long access )                                           */
/*     long value          ���ޥե��ν���͡�0x0000��0x7ffff��                                    */
/*     long spid           ���ޥե����̻ҡ�0x000a0000��0x000affff����0x00030000��0x0003ffff��     */
/*     long access         ������������̤���ѡ�0������                                          */
/*                                                                                                */
/**************************************************************************************************/
long oscresp( long value, long spid, long access )
{
    int   iSemId;                                 // ���ޥե�ID
    int   iSemCtl;                                // semctl�ֵ���
    char  acSemKey[9];                            // ���ޥե���
    long  lSemKey = 0;                            // ntok��


	os_trcget2( D_MD_OSCRESP, D_T_TRA_IN, 3, value, spid, access);
    

//	DbgMsg01( DLv02, ( OutPut, "***** Start oscresp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** value :%x\n", value) );
//	DbgMsg01( DLv04, ( OutPut, "***** spid  :%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** access:%x\n", access) );
    //********************************************
    //***** ���������å�
    //*****
    if(( D_OS_SPMIN > value ) || ( D_OS_SPMAX < value))
    {                                             // ���ޥե��ν����
    	DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEIVAL\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_PRA, 1, OSEEIVAL);
    	
        return( OSEEIVAL );
    }

    //if( D_OS_SPIDMIN >= spid )                  // 20021218����
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // ���ޥե����̻�
    	DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEISPI\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_PRA, 1, OSEEISPI);
    	
        return( OSEEISPI );
    }

    //********************************************
    //***** ���ޥե�ID�μ���
    //*****
    /*------2002/12/18 �ɲ� ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL ); // 20021218 ����
		os_trcget2( D_MD_OSCRESP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, 
														D_SEM_ACCESS | IPC_CREAT | IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, D_SEM_ACCESS | IPC_CREAT | IPC_EXCL );
		os_trcget2( D_MD_OSCRESP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 03:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08x\n") );
            goto err_oscresp;
        }
		DbgMsg01( DLv04, ( OutPut, "***** Semget �롼�� iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08x\n") );

    //********************************************
    //***** ���ޥե��ν����
    //*****
    uSem.val = value;                             // ���ޥե��ν��������

    do{
		os_trcget2( D_MD_OSCRESP, D_T_SYS_SEMCTL, 4, iSemId, D_SEM_NUM, SETVAL, uSem );
        iSemCtl = semctl( iSemId, D_SEM_NUM, SETVAL, uSem );
		os_trcget2( D_MD_OSCRESP, D_T_SYS_END, 1, iSemCtl );
        
        if( D_ERR_SYS == iSemCtl && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 04:semctl Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semctl iSemCtl:%08x\n", iSemCtl) );
            goto err_oscresp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semctl �롼�� iSemCtl:%08x\n", iSemCtl) );
    } while( D_ERR_SYS == iSemCtl );
    DbgMsg01( DLv04, ( OutPut, "***** semctl iSemCtl:%08x\n", iSemCtl) );

//	DbgMsg01( DLv02, ( OutPut, "***** End oscresp\n") );
	
	os_trcget2( D_MD_OSCRESP, D_T_TRA_OUT, 1, spid);
	
    return( spid );

//************************************************
//***** �۾����
//*****
err_oscresp:

    switch( errno ){
    case EEXIST:
    	DbgMsg01( DLv05, ( OutPut, "***** 05:Err OSEEEXST\n") );
   		
   		os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEEXST);
   		
    	return( OSEEEXST ); 
    	break;
    	
    case ENOMEM:
    	DbgMsg01( DLv05, ( OutPut, "***** 06:Err ENOMEM\n") );
    case ENOSPC:
    	DbgMsg01( DLv05, ( OutPut, "***** 07:Err OSEEWKEX\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEWKEX);
    	
    	return( OSEEWKEX ); 
    	break;
    	
    case ERANGE:
    	DbgMsg01( DLv05, ( OutPut, "***** 08:Err OSEEIVAL\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_SYS, 1, OSEEIVAL);
    	
    	return( OSEEIVAL ); 
    	break;
    default:
    	DbgMsg01( DLv05, ( OutPut, "***** 09:Err ABORT\n") );
    	
    	os_trcget2( D_MD_OSCRESP, D_T_ERR_ABT, 0);
    	
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSCRESP << 16) | D_T_ERR_SYS );
    }

}

/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
