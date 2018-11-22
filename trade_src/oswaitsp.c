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
/* ��⥸�塼��̾��					 ���ޥե��ο����Ԥ�											*/
/* ��⥸�塼��ɣġ�				 oswaitsp													*/
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
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*	 ���ޥե��ο����Ԥ� 																		*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<oswaitsp.h>																*/
/*																								*/
/*	   	long	oswaitsp( long spid, long count, long limit )									*/
/*																								*/
/* �㲾������																					*/
/*		long	spid;		���ޥե����̻ҡ�0�ʳ������͡�										*/
/*		long	count;		�����͡�0x0000��0x7ffff��											*/
/*		long	limit;		���»��֡�-1����0�ʳ��������͡�  									*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		�������		NORMAL																	*/
/*		��λ����		OSEEISPI																*/
/*						OSEEICNT																*/
/*						OSEEILIM																*/
/*						OSEENEXS																*/
/*						OSEEWKEX																*/
/*						OSEEDELD																*/
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
#include "oswaitsp.h"
#include "oswaitsp_ins.h"                         // ���������ѡʸ��̡�

/************************************************************************************************/
/* ��ǽ�����ޥե��ο����Ԥ�                                                                     */
/* ��������2002ǯ8��14��                                                                        */
/* �ѹ�����                                                                                     */
/* �����ԡ�����                                                                                 */
/* �ƽз�����                                                                                   */
/*   long oswaitsp( long spid, long count, long limit )                                         */
/*     long spid           ���ޥե����̻ҡ�0x000a0000��0x000affff����0x00030000��0x0003ffff��   */
/*     long count          �����͡�0x0000��0x7ffff��                                            */
/*     long limit          ���»��֡�-1����0�ʳ��������͡�                                      */
/*                                                                                              */
/************************************************************************************************/
long oswaitsp( long spid, long count, long limit )
{
    int  iSemId;                                  // ���ޥե�ID
    long lUnLimWt;                                // os_unlimwt���ֵ���
    long lLimWt;                                  // os_limwt���ֵ���
	char  acSemKey[9];                            // ���ޥե���
    long  lSemKey = 0;                            // ntok��
    
    
	os_trcget2( D_MD_OSWAITSP, D_T_TRA_IN, 3, spid, count, limit );
    
	DbgMsg01( DLv02, ( OutPut, "***** Start oswaitsp\n") );
//	DbgMsg01( DLv04, ( OutPut, "***** spid  :%08x\n", spid) );
//	DbgMsg01( DLv04, ( OutPut, "***** count :%04x\n", count) );
//	DbgMsg01( DLv04, ( OutPut, "***** limit :%d\n", limit) );
    //********************************************
    //***** ���������å�
    //*****
    //if( D_OS_SPIDMIN >= spid )                  // 20021218 ����
    if( (0x03 != (spid >> 16)) && (0x0a != (spid >> 16)) )
    {                                             // ���ޥե����̻�
		DbgMsg01( DLv05, ( OutPut, "***** 01:Err OSEEISPI\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEISPI );
		
        return( OSEEISPI );
    }

    if(( D_OS_SUBMIN > count ) || ( D_OS_SUBMAX < count))
    {                                             // ������
		DbgMsg01( DLv05, ( OutPut, "***** 02:Err OSEEICNT\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEICNT );
		
        return( OSEEICNT );
    }

    if( (D_OS_WAIT != limit) && (D_OS_NOWAIT >= limit) )
    {                                             // ���»���
		DbgMsg01( DLv05, ( OutPut, "***** 03:Err OSEEILIM\n") );
		
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_PRA, 1, OSEEILIM );
		
        return( OSEEILIM );
    }
    //********************************************
    //***** ���ޥե�ID�μ���
    //*****
    /*------2002/12/18 �ɲ� ---------------------*/
    sprintf(acSemKey, "%08lx", spid);
    lSemKey = BlpMpf_ntok(acSemKey,D_NTOK_ID);
    /*-------------------------------------------*/
    do{
        //iSemId = semget( spid, D_SEM_SIZE, IPC_EXCL ); // 20021218 ����
		os_trcget2( D_MD_OSWAITSP, D_T_SYS_SEMGET, 3, lSemKey, D_SEM_SIZE, IPC_EXCL );
        iSemId = semget( lSemKey, D_SEM_SIZE, IPC_EXCL );
		os_trcget2( D_MD_OSWAITSP, D_T_SYS_END, 1, iSemId );
        
        if( D_ERR_SYS == iSemId && EINTR != errno )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 04:semget Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err semget iSemId:%08lx\n", iSemId) );
            goto err_oswaitsp;
        }
        DbgMsg01( DLv04, ( OutPut, "***** Semget �롼�� iSemId:%08x\n", iSemId) );
    } while( D_ERR_SYS == iSemId );
    DbgMsg01( DLv04, ( OutPut, "***** semget iSemId:%08lx\n") );

    //********************************************
    //***** ���ޥե��ͤθ���
    //*****
    if( D_OS_WAIT == limit )
    {                                             // ̵����Ԥ�
        lUnLimWt = os_unlimwt( iSemId, count );
        //if( D_ERR_OSUNLIMWT == lUnLimWt )
        if( NORMAL != lUnLimWt )
        {
			DbgMsg01( DLv05, ( OutPut, "***** 05:os_unlimwt Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err os_unlimwt lUnLimWt:%08lx\n", lUnLimWt) );
            goto err_oswaitsp;
        }
    }
    else
    {
        lLimWt = os_limwt( iSemId, count, limit );	// ���»����Ԥ�
//      if( D_ERR_OSLIMWT == lLimWt )
        if( NORMAL != lLimWt )						// �ֵ��ͤ�����ʳ��ξ��
        {
			DbgMsg01( DLv05, ( OutPut, "***** 06:os_limwt Err:%s\n", strerror(errno) ) );
			DbgMsg01( DLv05, ( OutPut, "***** Err os_limwt lLimWt:%08lx\n", lLimWt) );
			
													// 20030317 �ɲ�
			if(OSEETOUT == lLimWt)					// �����ॢ���Ȥˤ�륨�顼�ξ��
			{
				DbgMsg01( DLv02, ( OutPut, "***** End oswaitsp\n") );
				os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 1, OSEELOST );
				return(OSEETOUT);					// time out���ֵ�
			}

            goto err_oswaitsp;						// ����¾�Υ��顼�ξ��
        }
    }

    DbgMsg01( DLv04, ( OutPut, "***** limit:%d\n", limit) );
	DbgMsg01( DLv02, ( OutPut, "***** End oswaitsp\n") );

	os_trcget2( D_MD_OSWAITSP, D_T_TRA_OUT, 1, NORMAL );
    return( NORMAL );


//************************************************
//***** �۾����
//*****
err_oswaitsp:

    switch( errno ){
    case ENOENT:
    	DbgMsg01( DLv05, ( OutPut, "***** 07:Err ENOENT\n") );
   		
   		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEENEXS );
    	
    	return( OSEENEXS ); 
    	break;
    	
    case ENOMEM:
    	DbgMsg01( DLv05, ( OutPut, "***** 08:Err ENOMEM\n") );
    case ENOSPC:
    	DbgMsg01( DLv05, ( OutPut, "***** 09:Err ENOSPC\n") );
    case ERANGE:
    	DbgMsg01( DLv05, ( OutPut, "***** 10:Err ERANGE\n") );
    	
    	os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEWKEX );
    	
    	return( OSEEWKEX ); 
    	break;
    	
    case EIDRM :
    	DbgMsg01( DLv05, ( OutPut, "***** 11:Err EIDRM\n") );
    
    	os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEDELD );
    
    	return( OSEEDELD ); 
    	break;
    	
    case EINVAL:
    	DbgMsg01( DLv05, ( OutPut, "***** 12:Err EINVAL\n") );
    	
   		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 2, errno, OSEEISPI );
    	
    	return( OSEEISPI ); 
    	break;
    default:
		/***** �ξ����ɼKL0044���б�	Start							��������2003.03.26	*****/
		DbgMsg01( DLv05, ( OutPut, "***** 13:Err default\n") );
		os_trcget2( D_MD_OSWAITSP, D_T_ERR_SYS, 1, errno );
//		abort();
		break;
		/***** �ξ����ɼKL0044���б�	 End							��������2003.03.26	*****/
  }
}

/************************************************************************************************/
/* ��ǽ�����ޥե��ͤθ�����̵����Ԥ���                                                         */
/* ��������2002ǯ8��14��                                                                        */
/* �ѹ�����                                                                                     */
/* �����ԡ�����                                                                                 */
/* �ƽз�����                                                                                   */
/*   long os_unlimwt( long iSemId, long count )                                                 */
/*     long iSemId         ���ޥե�ID��0�ʳ������͡�                                            */
/*     long count          �����͡�0x0000��0x7ffff��                                            */
/*                                                                                              */
/************************************************************************************************/
long os_unlimwt( long iSemId, long count )
{
    int  iSemOp;                                  // semop���ֵ���
    long lCnt;                                    // tSemBuf.sem_op��������
    
	os_trcget2( D_MD_OS_UNLIMWT, D_T_TRA_IN, 2, iSemId, count );
    
	DbgMsg01( DLv02, ( OutPut, "***** Start-Sub os_unlimwt\n") );
    //********************************************
    //***** ����ͤ�����
    //***** sem_flg������ˤĤ��Ƥ���Ĵ��
    lCnt = count * D_SIGN_CHANGE;                 // ������count�ˤ�����Ѵ�
    tSemBuf.sem_num = D_SEM_NUM;                  // ���ޥե�����������ֹ�����
    tSemBuf.sem_op = lCnt;                        // ���ޥե��βû�������
/*****	�ξ�����ֹ�TBCS0243���б�		Start							��������2003.07.22	*****/
/************************************************************************************************/
/*	sem_flg��������SEM_UNDO�פ��ѹ�															*/
/************************************************************************************************/
	tSemBuf.sem_flg = SEM_UNDO;					  // ���ޥե������ե饰����
/*****	�ξ�����ֹ�TBCS0243���б�		 End							��������2003.07.22	*****/

    //********************************************
    //***** ���ޥե��ͤθ���
    //*****
    do{                                           // ���ޥե��ͤθ���
		os_trcget2( D_MD_OS_UNLIMWT, D_T_SYS_SEMOP, 3, iSemId, &tSemBuf, D_SEM_SIZE );
        iSemOp = semop( iSemId, &tSemBuf, D_SEM_SIZE );
		os_trcget2( D_MD_OS_UNLIMWT, D_T_SYS_END, 1, iSemOp );
        
        if( D_ERR_SYS == iSemOp && EINTR != errno )
        {
		DbgMsg01( DLv05, ( OutPut, "***** Sub-01:semop Err:%s\n", strerror(errno) ) );
		DbgMsg01( DLv05, ( OutPut, "***** Err semop iSemOp:%08lx\n", iSemOp) );
		DbgMsg01( DLv05, ( OutPut, "***** return D_ERR_OSUNLIMWT:%08lx\n", D_ERR_OSUNLIMWT) );
			
			//os_trcget2( D_MD_OS_UNLIMWT, D_T_ERR_SYS, 1, D_ERR_OSUNLIMWT );
			os_trcget2( D_MD_OS_UNLIMWT, D_T_ERR_SYS, 1, errno );
		
            return( D_ERR_OSUNLIMWT );
        }
//			DbgMsg01( DLv04, ( OutPut, "***** semop �롼�� iSemOp:%d\n", iSemOp) );
    } while( D_ERR_SYS == iSemOp );

	DbgMsg01( DLv02, ( OutPut, "***** End-Sub os_unlimwt\n") );
	
	os_trcget2( D_MD_OS_UNLIMWT, D_T_TRA_OUT, 1, NORMAL );
	
    return( NORMAL );

}

/************************************************************************************************/
/* ��ǽ�����ޥե��ͤθ��������»����Ԥ���                                                       */
/* ��������2002ǯ8��14��                                                                        */
/* �ѹ�����                                                                                     */
/* �����ԡ�����                                                                                 */
/* �ƽз�����                                                                                   */
/*   long os_limwt( long iSemId, long count, long limit )                                       */
/*     long iSemId         ���ޥե�ID��0�ʳ������͡�                                            */
/*     long count          �����͡�0x0000��0x7ffff��                                            */
/*                                                                                              */
/************************************************************************************************/
long os_limwt( long iSemId, long count, long limit )
{
    int  iSemOp;                                  	// semop���ֵ���
    long lCnt;                                    	// tSemBuf.sem_op��������
    long lSysTmCl;                                	// os_systim���ֵ���
    
	os_trcget2( D_MD_OS_LIMWT, D_T_TRA_IN, 3, iSemId, count, limit );

	DbgMsg01( DLv02, ( OutPut, "***** Start-Sub os_limwt\n") );


	/****************************************/
	/*  ���ޥե��ͤ�����					*/
	/****************************************/
    lCnt = count * D_SIGN_CHANGE;                 	// ������count�ˤ�����Ѵ�
    tSemBuf.sem_num = D_SEM_NUM;                  	// ���ޥե�����������ֹ�����
    tSemBuf.sem_op = lCnt;                        	// ���ޥե��βû�������
/*****	�ξ�����ֹ�TBCS0243���б�		Start							��������2003.07.22	*****/
/************************************************************************************************/
/*	sem_flg��������SEM_UNDO�פ��ѹ�															*/
/************************************************************************************************/
	tSemBuf.sem_flg = SEM_UNDO;						// ���ޥե������ե饰����
/*****	�ξ�����ֹ�TBCS0243���б�		 End							��������2003.07.22	*****/


	/****************************************/
	/*  ������ȯ��							*/
	/****************************************/
/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰�Υ��ꥢ���ɲ�													*/
/************************************************************************************************/
	ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;		// �����ƥॿ���ޥե饰�ν����
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/

    lSysTmCl = os_systim( limit, D_TIMER_UNIT, D_TIMER_UPTIME );
    //if( D_ERR_OSSYSTIM == lSysTmCl )				// 200030317 ����
	if(NORMAL != lSysTmCl)							// �ֵ��ͤ�����ʳ��ξ��
	{
		/***** �ξ����ɼKL0044���б�	Start							��������2003.03.26	*****/
		/****************************************************************************************/
		/*	�����ƥॳ���륿���ޤˤ�륨�顼�ξ��ϡ�OSEEWKEX�פ��ֵѤ���褦�˽���			*/
		/****************************************************************************************/
		errno = ERANGE ;

		DbgMsg01( DLv05, ( OutPut, "***** Err os_systim lSysTmCl:%08lx\n", lSysTmCl) );
		DbgMsg01( DLv05, ( OutPut, "***** Sub-02:01 os_systim Err:%s\n", strerror(errno) ) );

		os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 2, lSysTmCl, errno );
//		return( lSysTmCl );
		return( D_ERR_OSLIMWT );					// �ݣ����ֵ�
		/***** �ξ����ɼKL0044���б�	 End							��������2003.03.26	*****/
	}


	/***** �ξ����ɼKL0043���б�	Start								��������2003.03.26	*****/
	/********************************************************************************************/
	/*	�����ॢ���Ȥ�Ƚ���������															*/
	/********************************************************************************************/
	/****************************************/
	/*  ���»��֤ˤʤ�ޤǷ����֤�			*/
	/****************************************/
    while( 1 )
    {
		errno  = 0;
		iSemOp = 0;

		/****************************************/
		/*  ���ޥե��ͤθ���					*/
		/****************************************/
		os_trcget2( D_MD_OS_LIMWT, D_T_SYS_SEMOP, 3, iSemId, &tSemBuf, D_SEM_SIZE );
        iSemOp = semop( iSemId, &tSemBuf, D_SEM_SIZE );
		os_trcget2( D_MD_OS_LIMWT, D_T_SYS_END, 1, iSemOp );

		DbgMsg01( DLv05, ( OutPut, "***** Err semop iSemOp:%08lx\n", iSemOp) );

		if ( D_ERR_SYS == iSemOp )					// �ֵ��ͤ����顼�ξ��
		{
			if (EINTR == errno)						// errno����EINTR�פξ��
			{
				DbgMsg01( DLv05, ( OutPut, "***** ptEtmc->cSysTimeFlg:%x\n",ptEtmc->cSysTimeFlg) );

/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰��Ƚ���������												*/
/************************************************************************************************/
//				if (0x00 == ptEtmc->cSysTimeFlg)	// �����ƥॳ���륿���ޥե饰����OFF�פξ��

													// �����ƥॳ���륿���ޥե饰����̤ȯ�ԡ�
													// ���ϡ�ȯ����פξ��
				if ((0x00 == ptEtmc->cSysTimeFlg) || (0x01 == ptEtmc->cSysTimeFlg))
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/
				{
					DbgMsg01( DLv05, ( OutPut, "***** Sub-02:02 semop Err:%s\n", strerror(errno)));

					continue;						// ��ȥ饤������
				}
				else								// �����ƥॳ���륿���ޥե饰��
				{									// �֥����ॢ���ȡפξ��
					DbgMsg01( DLv05, ( OutPut, "***** Sub-02:03 semop Err:%s\n", strerror(errno)));
/*****	�ξ�����ֹ�TBCS0143���б�		Start							��������2003.06.13	*****/
/************************************************************************************************/
/*	�����ƥॳ���륿���ޡ��ե饰�Υ��ꥢ���ɲ�													*/
/************************************************************************************************/
													/* �����ƥॿ���ޥե饰�ν����				*/
					ptEtmc->cSysTimeFlg = D_ETMC_SYSTIMFLG_OFF;	
/*****	�ξ�����ֹ�TBCS0143���б�		 End							��������2003.06.13	*****/
					os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 2, OSEETOUT, errno );
					return( OSEETOUT );				// �����ॢ���Ȥ��ֵ�
				}
			}
			else									// errno����EINTR�ʳ��פξ��
			{
				DbgMsg01( DLv05, ( OutPut, "***** Sub-02:04 semop Err:%s\n", strerror(errno) ) );

				os_tmcan(0);						// �����ޥ���󥻥�

				os_trcget2( D_MD_OS_LIMWT, D_T_ERR_SYS, 1, errno );
				return( D_ERR_OSLIMWT );			// �ݣ����ֵ�
			}
		}
		else										// �ֵ��ͤ�����ξ��
		{
			os_tmcan(0);							// �����ޥ���󥻥�

			os_trcget2( D_MD_OS_LIMWT, D_T_TRA_OUT, 1, NORMAL );
			return( NORMAL );						// ���ｪλ
		}
	}
	/***** �ξ����ɼKL0043���б�	 End								��������2003.03.26	*****/
}
/************************************************************************************************/
/* End                                                                                          */
/************************************************************************************************/
