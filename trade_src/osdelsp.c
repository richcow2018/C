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
/* ��⥸�塼��̾��					 ���ޥե��κ��												*/
/* ��⥸�塼��ɣġ�				 osdelsp													*/
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
/*	 ���ޥե��κ��																				*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<osdelsp.h>																	*/
/*																								*/
/*	   	long	osdelsp( long spid, long udf )													*/
/*																								*/
/* �㲾������																					*/
/*		long	spid;		���ޥե����̻ҡ�0�ʳ������͡�										*/
/*		long	udf;		̵������ե饰													*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ		NORMAL																	*/
/*		�۾ｪλ		OSEEISPI																*/
/*						OSEEIVAL																*/
/*						OSEEWAIT																*/
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
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include "osdelsp.h"
#include "osdelsp_ins.h"                          // ���������ѡʸ��̡�

/**************************************************************************************************/
/* ��ǽ�����ޥե��κ��                                                                           */
/* ��������2002ǯ7��26��                                                                          */
/* �ѹ�����                                                                                       */
/* �����ԡ�����                                                                                   */
/* �ƽз�����                                                                                     */
/*   long osdelsp( long spid, long udf )                                                          */
/*     long spid           ���ޥե����̻ҡ�0x000a0000��0x000affff����0x00030000��0x0003ffff��     */
/*     long udf            ̵������ե饰                                                       */
/*                                                                                                */
/**************************************************************************************************/
long osdelsp( long spid, long udf )
{
    int   iSemId;                                 // ���ޥե�ID
    int   iSemCtl;                                // semctl�ֵ���
    char  acSemKey[9];                            // ���ޥե���
    long  lSemKey = 0;                            // ntok��

	os_trcget2( D_MD_OSDELSP, D_T_TRA_IN, 2, spid, udf );

//	DbgMsg01( DLv02, ( OutPut, "***** Start osdelsp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** spid:%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** udf :%d\n", udf) );
    //********************************************
    //***** ���������å�
    //*****
    //if( D_OS_SPIDMIN >= spid )                  // 20021218 ����
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // ���ޥե����̻�
    	DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEISPI\n") );
    	
    	os_trcget2( D_MD_OSDELSP, D_T_ERR_PRA, 1, OSEEISPI  );
    	
        return( OSEEISPI );
    }

    if(( D_OS_CDDEL != udf ) && ( D_OS_UCDDEL != udf ))
    {                                             // ̵������ե饰
    	DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEIVAL\n") );
    	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_PRA, 1, OSEEIVAL  );
    	
        return( OSEEIVAL );
    }

    //********************************************
    //***** ���ޥե�ID�μ����ʥ��ޥե���¸�ߥ����å���
    //*****
    /*------2002/12/18 �ɲ� ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, IPC_EXCL ); // 20021218 ����
		os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, IPC_EXCL );
		os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 03:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08x\n") );
            goto err_osdelsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semget �롼�� iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08x\n") );

    //********************************************
    //***** ���ޥե��ˤ���Ԥ����֥ץ��������å�
    //*****
    if( D_OS_CDDEL == udf )
    {
        do{                                       // ���ޥե��ͤ������Ԥ��ץ����������å�
			os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, GETZCNT );
            iSemCtl = semctl( iSemId, D_SEM_NUM, GETNCNT );
			os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
            
            if( D_SEM_NOEXIST != iSemCtl && EINTR != errno )
            {
				DbgMsg01( DLv05, ( OutPut, "***** 04:semctl Err:%s\n", strerror(errno) ) );
				DbgMsg01( DLv05, ( OutPut, "***** 01 Err semctl iSemCtl:%08x\n", iSemCtl) );
				
				os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1, OSEEWAIT  );
				
                return( OSEEWAIT );
            }
            DbgMsg01( DLv04, ( OutPut, "***** Semctl �롼��01 iSemCtl:%08x\n", iSemCtl) );
        } while( D_SEM_NOEXIST != iSemCtl );
        DbgMsg01( DLv04, ( OutPut, "***** 01 semctl iSemCtl:%08x\n", iSemCtl) );

        do{                                       // ���ޥե��ͤ�0�Ԥ��ץ����������å�
			os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, GETZCNT );
            iSemCtl = semctl( iSemId, D_SEM_NUM, GETZCNT );
			os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
            
            if( D_SEM_NOEXIST != iSemCtl && EINTR != errno )
            {
				DbgMsg01( DLv05, ( OutPut, "***** 05:semctl Err:%s\n", strerror(errno) ) );
				DbgMsg01( DLv05, ( OutPut, "***** 02 Err semctl iSemCtl:%08x\n", iSemCtl) );
				
				os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1, OSEEWAIT  );
				
                return( OSEEWAIT );
            }
            DbgMsg01( DLv04, ( OutPut, "***** Semctl �롼��02 iSemCtl:%08x\n", iSemCtl) );
        } while( D_SEM_NOEXIST != iSemCtl );
        DbgMsg01( DLv04, ( OutPut, "***** 02 semctl iSemCtl:%08x\n", iSemCtl) );
    }

    //********************************************
    //***** ���ޥե��κ��
    //*****
    do{
		os_trcget2( D_MD_OSDELSP, D_T_SYS_SEMCTL, 3, iSemId, D_SEM_NUM, IPC_RMID );
        iSemCtl = semctl( iSemId, D_SEM_NUM, IPC_RMID );
		os_trcget2( D_MD_OSDELSP, D_T_SYS_END, 1, iSemCtl );
        
        if( D_ERR_SYS == iSemCtl && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 06:semctl Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** 03 Err semctl iSemCtl:%08x\n", iSemCtl) );
            goto err_osdelsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semctl �롼��03 iSemCtl:%08x\n", iSemCtl) );
    } while( D_ERR_SYS == iSemCtl );
    DbgMsg01( DLv04, ( OutPut, "***** 03 semctl iSemCtl:%08x\n", iSemCtl) );

//	DbgMsg01( DLv02, ( OutPut, "***** End osdelsp\n") );
	
	os_trcget2( D_MD_OSDELSP, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

//************************************************
//***** �۾����
//*****
err_osdelsp:

    switch( errno ){
    case ENOENT:
    	DbgMsg01( DLv05, ( OutPut, "***** 07: Err ENOENT\n") );
    	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_SYS, 1,  errno    );
    	
    	return( OSEENEXS ); 
    	break;
    default:
       	DbgMsg01( DLv05, ( OutPut, "***** 08: Err ABORT\n") );
       	
   		os_trcget2( D_MD_OSDELSP, D_T_ERR_ABT, 1,errno );
       	
    	os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSDELSP << 16) | D_T_ERR_SYS );
    }

}
/**************************************************************************************************/
/* End                                                                                            */
/**************************************************************************************************/
