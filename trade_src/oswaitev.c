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
/* ��⥸�塼��̾��					 ���٥�Ȥμ����Ԥ�											*/
/* ��⥸�塼��ɣġ�				 oswaitev													*/
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
/* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)				*/
/* �㥽��������ǯ������ 			 ��������ǯ��������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���٥�Ȥμ����Ԥ�																			*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oswaitev.h>																*/
/*																								*/
/*	   	long	oswaitev( long evn, long count, long limit ) 									*/
/*																								*/
/* �㲾������																					*/
/*		long	evn;		���٥���ֹ�														*/
/*		long	count;		�����͡�̤���ѡ�0������											*/
/*		long	limit;		���»��֡�-1��														*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEILIM																*/
/*						OSEEIEVN																*/
/*						OSEENEXS																*/
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
#include <sys/msg.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "oswaitev.h"
#include "oswaitev_ins.h"                         // ���������ѡʸ��̡�

/**************************************************************************************************/
/* ��ǽ�����٥�Ȥμ����Ԥ�                                                                       */
/* ��������2002ǯ8��30��                                                                          */
/* �ѹ�����                                                                                       */
/* �����ԡ�����                                                                                   */
/* �ƽз�����                                                                                     */
/*   long oswaitev( long evn, long count, long limit )                                            */
/*     long evn            ���٥���ֹ�(0��1024)                                                  */
/*     long count          �����͡�̤���ѡ�0������                                              */
/*     long limit          ���»��֡�-1��                                                         */
/*                                                                                                */
/**************************************************************************************************/
long oswaitev( long evn, long count, long limit )
{
	int  iGetTmDay = 0; 						// gettimeofday�ֵ���
	int  iMsgRcv = 0;							// msgrcv�ֵ���
	long lMsgQId = 0;							// ��å��������塼ID
	long lMsgType = 0;							// ��å����������� 20030330 �ɲ�

	struct msgbuf tRcvMsg;						  // �����Хåե��������
	struct timeval tTmVal;						  // ���������������
	
	os_trcget2( D_MD_OSWAITEV, D_T_TRA_IN, 3, evn, count, limit );
	
//	DbgMsg01( DLv05, ( OutPut, "***** evn   :%ld\n", evn));
//	DbgMsg01( DLv05, ( OutPut, "***** count :%ld\n", count));
//	DbgMsg01( DLv05, ( OutPut, "***** limit :%ld\n", limit));
    //********************************************
    //***** ���������å�
    //*****
    if(( D_VALUE_MIN > evn ) || ( D_VALUE_MAX < evn ))
    {                                             // ���٥���ֹ�
    	DbgMsg01( DLv05, ( OutPut, "***** 01: Parameter Err env \n") );
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_PRA, 1, OSEEIEVN );
    	
        return( OSEEIEVN );
    }

    if( D_VALUE_WAIT != limit )
    {                                             // ���»���
    	DbgMsg01( DLv05, ( OutPut, "***** 02: Parameter Err limit \n") );
    	
    	os_trcget2( D_MD_OSWAITEV, D_T_ERR_PRA, 1, OSEEIEVN ); 	
    	
        return( OSEEIEVN );
    }

    //**************************************************
    //***** ��å��������塼ID�μ���
    //*****

	lMsgQId = ptMyEMBC->lMsgQId;				// ���ץ����Υ�å��������塼�����
    DbgMsg01( DLv04, ( OutPut, "***** lMsgQId : %lx\n" ,lMsgQId));
    DbgMsg01( DLv04, ( OutPut, "***** lPCode : %lx\n" ,ptMyEMBC->lPCode));
    

    //**************************************************
    //***** ��å������μ����Ԥ�
    //*****
												//20030330 ��� Start
/*
	tRcvMsg.mtype = D_EVENT_MSGTYPE + evn;        // ��å����������פ�����
	DbgMsg01( DLv04, ( OutPut, "***** tRcvMsg.mtype : %ld\n", tRcvMsg.mtype));

	do{                                           // �����ǡ���������
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_GETTIMEOFDAY, 2, &tTmVal, D_VALUE_TZONE );
		iGetTmDay = gettimeofday( &tTmVal, D_VALUE_TZONE );
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_END, 1, iGetTmDay );

		if( D_ERR_GETTMDAY == iGetTmDay && EINTR != errno )
		{
			goto err_oswaitev;
		}
	} while( D_ERR_GETTMDAY == iGetTmDay );
	sprintf( tRcvMsg.mtext, "%ld", tTmVal.tv_sec);
	DbgMsg01( DLv04, ( OutPut, "***** tRcvMsg.mtext : %s\n", tRcvMsg.mtext));
												// 20030330 ��� End
*/
												// 20030330 ����
	lMsgType = D_EVENT_MSGTYPE + evn;        // ��å����������פ�����
	DbgMsg01( DLv04, ( OutPut, "***** lMsgType : %08lx\n", lMsgType));

	do{                                           // ��å������μ����Ԥ�
//		os_trcget2( D_MD_OSWAITEV, D_T_SYS_MSGRCV, 5, lMsgQId, &tRcvMsg, 
//						sizeof(tRcvMsg.mtext[D_AREA_SIZE]), tRcvMsg.mtype,MSG_NOERROR );
//		iMsgRcv = msgrcv( lMsgQId, &tRcvMsg, sizeof(tRcvMsg.mtext[D_AREA_SIZE]), tRcvMsg.mtype,
//						MSG_NOERROR );
												// 20030330 ����
		os_trcget2( D_MD_OSWAITEV, D_T_SYS_MSGRCV, 5, lMsgQId, &tRcvMsg, 
						sizeof(long), tRcvMsg.mtype,MSG_NOERROR );
		iMsgRcv = msgrcv( lMsgQId, &tRcvMsg, sizeof(long), lMsgType,
						MSG_NOERROR );

		os_trcget2( D_MD_OSWAITEV, D_T_SYS_END, 1, iMsgRcv );

		if( D_ERR_MSGRCV == iMsgRcv && EINTR != errno )
		{
			DbgMsg01( DLv05, ( OutPut, "***** 03:msgrcv Err Mess :%s\n", strerror(errno) ) );
			goto err_oswaitev;
		}
	}while( D_ERR_MSGRCV == iMsgRcv );

//	DbgMsg01( DLv05, ( OutPut, "***** End osevent\n"));
	
	os_trcget2( D_MD_OSWAITEV, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

//**************************************************************************************************
//***** �۾����
//*****
err_oswaitev:

    switch( errno ){
    case ENOENT: 
    	DbgMsg01( DLv05, ( OutPut, "***** Err OSEENEXS\n"));
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_SYS, 1, errno ); 
    	
	    return( OSEENEXS ); 
	    break;
	case EIDRM: 
    	DbgMsg01( DLv05, ( OutPut, "***** Err OSEEWKEX\n"));
    	
   		os_trcget2( D_MD_OSWAITEV, D_T_ERR_SYS, 1, errno ); 
    	
	    return( OSEEWKEX ); 
	    break;
    default:     
    	os_trcget2( D_MD_OSWAITEV, D_T_ERR_ABT, 1, errno ); 
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSWAITEV << 16) | D_T_ERR_SYS );
    }

}
/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
