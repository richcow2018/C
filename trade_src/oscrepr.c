/************************************************************************************************/
/*  ���  ��������                                                                            */
/*            ������ңΣԣԥǡ���                                                              */
/*              ��ͻ�ӥ��ͥ���������                                                            */
/*                                                                                              */
/*                                                                                              */
/*  ����ʪ  �̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��                                  */
/************************************************************************************************/
/* ���оݶ�̳̾��                    �ԣң��ģť��ߥ�졼��                                     */
/* ���оݶ�̳�ɣġ�                  �ԣң�                                                     */
/* �㥵���ӥ�����̾��                �ץ�������                                               */
/* �㥵���ӥ����ܣɣġ�              �أأأأأأ�                                             */
/* ��⥸�塼��̾��                  �ץ���������                                             */
/* ��⥸�塼��ɣġ�                oscrepr                                                    */
/* ��⥸�塼�����֡�                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��                    ���ѥ�����                                                 */
/* ��Ŭ�ѣϣӡ�                      �̣�����                                                 */
/* �㳫ȯ�Ķ���                      �ңȣ��ӣ�����                                             */
/* �㵭�Ҹ����                      �ø���                                                     */
/* ��⥸�塼����֡�                �ؿ�                                                       */
/* �㵡ǽ��ʬ��                                                                                 */
/* ���оݥǡ�����                                                                               */
/* �㹩�������ض�ʬ��                                                                           */
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��                �̣��̣�ݣӣͣХ����ƥ�                                   */
/* �㳫ȯ�����ƥ��ֹ��              �УУ����£�����������                                     */
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��                    �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)                 */
/* �������ֹ��                      148-1457(03-5437-1457)                                     */
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾��                      �ã»��ӥ��ͥ����ô��                                     */
/* ���߷�ǯ������                    ��������ǯ  �������                                     */
/* ���߷׽�����̾��                                                                             */
/* ���߷׽���ǯ�����ڤӽ����ɣġ�                                                               */
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ�					�ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
/* �㥽��������ǯ������              ��������ǯ  �������                                     */
/* �㥽���������ԡ� 			 	 ���ץ饤��ƣΤ												*/
/* �㥽��������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������		�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*																�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*																�ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���                ���ƥå�                                                   */
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס�                                                                                 */
/*      �ץ����κ���                                                                          */
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз�����                                                                                 */
/*		#include	<oscrepr_ins.h>																*/
/*                                                                                              */
/*   long oscrepr( char *fn , long pid , long flag ,                                            */
/*                 osepib *pibp , osearg *argp )                                                */
/*                                                                                              */
/* �㲾������                                                                                   */
/*      char *fn        �ץ����ե�����̾                                                    */
/*      long pid        �ץ������̻�                                                          */
/*      long flag       �ؼ��ե饰��̤���ѡ�                                                    */
/*      osepib *pibp    �ץ�����������֥�å�                                                */
/*      osearg *argp    �ѥ�᥿��¤��                                                          */
/*                                                                                              */
/* ���ֵ��͡�                                                                                   */
/*		���ｪλ		�ץ������̻ҡ����������ҥץ����Υץ������̻ҡ�					*/
/*		�۾ｪλ		OSEENOFL		�ץ������̻Ҥǻ��ꤷ���ե�����̾���ʤ���				*/
/*						OSEEIPID		�ץ������̻Ҥ��ͤ������Ǥ��롣						*/
/*						OSEEEXST		�ץ������̻Ҥǻ��ꤷ���ץ��������Ǥ�¸�ߤ��롣		*/
/*						OSEENEXS		�ץ������̻Ҥǻ��ꤷ���ץ����ơ��֥뤬¸�ߤ��ʤ���	*/
/*						OSEEWKEX		�����ƥ��Ȱ褬���ݤǤ��ʤ���							*/
/*						OSEEILMF		�ե�����η������۾�Ǥ��롣							*/
/*						OSEEACCV		���ɥ쥹�۾郎ȯ��������								*/
/*						OSEEOPEN		�ե�����Υ����ץ�˼��Ԥ�����							*/
/*						OSEEFAIL		�ҥץ������������˰۾ｪλ������					*/
/*                                                                                              */
/*----------------------------------------------------------------------------------------------*/
/* �������ϥǡ�����¤��                                                                         */
/* �����»����                                                                                 */
/*     �äˤʤ�                                                                                 */
/* ����ѳ����⥸�塼��ɣġ�                                                                   */
/* ��ƽи��Υ⥸�塼��ɣġ�                                                                   */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
/******************************** ɸ��إå����ե����� ******************************************/
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
/*****	�ξ�����ֹ�TBCS0231���б�		Start							��������2003.07.28	*****/
#include <sys/time.h>
#include <sys/resource.h>
/*****	�ξ�����ֹ�TBCS0231���б�		 End							��������2003.07.28	*****/

/*****************************  ���ѼԺ����إå����ե�����  *************************************/
#include "oscrepr.h"
#include "oscrepr_ins.h"				/* ���������� */

/*****************************************************************************/
/* ��ǽ���ץ����κ��� ������                                               */
/* ��������2002ǯ9��27��                                                     */
/* �ѹ���������ǯ�����                                                    */
/* �����ԡ�����                                                              */
/* �ƽз�����                                                                */
/*   long oscrepr( char *fn , long pid , long flag ,������������������������ */
/*                 osepib *pibp , osearg *argp )                             */
/*       char *fn         �ץ����ե�����̾����������������     ����������*/
/*       long pid ���������ץ������̻� ����                                */
/*       long flag ������ �ؼ��ե饰��̤���ѡ�  ���������������������������� */
/*       osepib *pibp �����ץ�����������֥�å�                           */
/*       osearg *argp �����ѥ�᥿��¤��                                     */
/*                                                                           */
/*****************************************************************************/
long oscrepr( char *fn , long pid , long flag , osepib *pibp , osearg *argp )
{
/****************************************************************************/
/*	�ѿ����																*/
/****************************************************************************/
    struct stat iiStat;                     /* �ե��������� */
    int iRet;                               /* �ؿ�����ֵ� */
    int iPno;                               /* �ؿ�����ֵ� */
    TEprcTableInd  *ptmoaAdr;
    TEprcTableInd  *ptprcAdr;
                                            /* �ץ��������ơ��֥�������Υ��ɥ쥹 */
    long lMaxFileNum;                       /* �ե����뵭�һҺ��� �Ŀ�              */
    long lLogicSpace;                       /* �������֤Υ�����                     */
    long lTimeSlice;                        /* �����ॹ�饤����                     */
    long lReqIdMax;                         /* �ꥯ�����ȼ��̻Һ� ��Ŀ�            */
    long lPPriority;                        /* ��ư���ץ���ͥ����                 */

    char *pacArgc[256];
    long lCnt = 0;
    /****************************************/
	void func();
	struct sigaction new, old;
	
/****************************************************************************/
/*	�������																*/
/****************************************************************************/
    new.sa_handler = func;
    new.sa_flags = SA_NOMASK ;
//	sigaction(SIGUSR1,&new,&old);
	/****************************************/
	os_trcget2( D_MD_OSCREPR, D_T_TRA_IN, 5, fn , pid , flag , pibp , argp );

       DbgMsg01( DLv02, ( OutPut, "***** oscrepr START ptEprc=%x\n",ptEprc) );
    ptmoaAdr = (TEprcTableInd *)(ptEprc + 1) ;
    ptprcAdr = ptmoaAdr;
	/* ���������å� */
    iRet = strlen(fn);
    if (iRet == 0) {
       DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 01:%d\n",iRet) );
       
	   os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEENOFL );
       
       return(OSEENOFL);               /*���ե�����ʤ�����������*/
    }

	
	if( NULL == argp)							//�ѥ�᥿��¤�Υ��ɥ쥹�����å�
	{
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Par Err argp\n"));
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEACCV );
		
		return(OSEEACCV);
	}

	/****************************************/
	/*	�����ΰ�μ���						*/
	/****************************************/
	for(lCnt = 0; lCnt < argp->argc; lCnt++)
	{
		pacArgc[lCnt] = argp->argv[lCnt];
	}
	
	pacArgc[lCnt] = NULL;
	
	argp->argv = pacArgc;
	
	/****************************************/
	/*	�ե������¸�ߥ����å�				*/
	/****************************************/
	os_trcget2( D_MD_OSCREPR, D_T_SYS_STAT, 2, fn, &iiStat );
	
    iRet =  stat(fn, &iiStat);
    
    os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
    
    if (iRet == D_ERR_SYS)
    {
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 02:%d\n",iRet) );
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENOFL );
		
		return(OSEENOFL);               /*���ե�����ʤ�����������*/
    }

	/****************************************/
	/*	�ץ���ID�Υ����å�				*/
	/****************************************/
    if (((pid & 0x00ff0000) != 0x00010000) 
                     && (pid  != 0x00000000))
    {
		DbgMsg01( DLv05, ( OutPut, "***** oscrepr Err 03:%d\n",iRet) );
		
		os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEIPID );
		
		return(OSEEIPID);               /*��pid��������������������*/
    }
    iPno = os_GstPrSep(1,pid & 0x00ffffff);
					/* �ץ��������ơ��֥븡�����������ץ������̻�  */
    DbgMsg01( DLv02, ( OutPut, "***** oscrepr IPNO=%d\n",iPno) );
    if(NORMAL > iPno)
    {
        DbgMsg01( DLv05, ( OutPut, "***** GetPR Err01:%d\n", iPno ) );
            
        os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEIPID );
            
	    return(OSEEIPID);               /*��pid��������������������*/
            //*     �۾����
    }

	/****************************************/
	/*	�ץ�����¸�ߥ����å�				*/
	/****************************************/
    ptprcAdr +=  iPno;
    if (ptprcAdr->lPid != 0x0) {
		DbgMsg01( DLv05, ( OutPut, "***** GetPR Err02:%d\n", iPno ) );
		
        os_trcget2( D_MD_OSCREPR, D_T_ERR_PRA, 1, OSEEEXST );
		
		return(OSEEEXST);       /*���ץ�������¸�ߡ�����*/
    }

/****************************************************************************/
/*	�ܽ���																	*/
/****************************************************************************/
	/************************************************/
	/*	SG���ɤ߹���								*/
	/************************************************/
	// �ץ�����������
    os_startSG();
    //iRet = os_getSG(D_SG_MOA_FILE_ID_MAX,&lMaxFileNum);     // �ե����뵭�һҺ���Ŀ��ɤ߹���
    iRet = os_getSG(D_SG_EFLC_NUM,&lMaxFileNum);		// 20030306 ����
    if(NORMAL != iRet)								// �ֵ��ͤ��۾�ξ��
    {
/*****	�ξ�����ֹ�TBCS0233���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	�ֵ��͡�OSERRSG�� �� �ֵ��͡�OSEENEXS�� ���ѹ�												*/
/************************************************************************************************/
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// �۾ｪλ
    }
    //iRet = os_getSG(D_SG_MOA_LOGI_SIZE,&lLogicSpace);       // �������֤Υ������ɤ߹���
    iRet = os_getSG( D_SG_LOGI_SIZE,&lLogicSpace);							// 20030306 ����
    if(NORMAL != iRet)								// �ֵ��ͤ��۾�ξ��
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// �۾ｪλ
    }
    //iRet = os_getSG(D_SG_MOA_TIME_SLI,&lTimeSlice); // �����ॹ�饤�����ɤ߹���
    iRet = os_getSG( D_SG_TIME_SLI,&lTimeSlice);				// 20030306 ����
    if(NORMAL != iRet)								// �ֵ��ͤ��۾�ξ��
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// �۾ｪλ
    }
    //iRet = os_getSG(D_SG_MOA_REQ_MAX,&lReqIdMax);   // �ꥯ�����ȼ��̻Һ���Ŀ��ɤ߹���
    iRet = os_getSG(D_SG_ERDC_NUM,&lReqIdMax);				// 20030306 ����
    if(NORMAL != iRet)								// �ֵ��ͤ��۾�ξ��
    {
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, OSEENEXS );
		return(OSEENEXS);							// �۾ｪλ
/*****	�ξ�����ֹ�TBCS0233���б�		 End							��������2003.07.28	*****/
    }
       DbgMsg01( DLv02, ( OutPut, "***** oscrepr SGEND\n") );

	/************************************************/
	/*	�ץ������������							*/
	/************************************************/
    if (pibp == 0x0) {
            ptprcAdr->lLank = ptmoaAdr->lLank;
            ptprcAdr->lUid = ptmoaAdr->lUid;
            ptprcAdr->lMaxFileNum = ptmoaAdr->lMaxFileNum;
            ptprcAdr->lPAttr = ptmoaAdr->lPAttr;
            ptprcAdr->lAccess = ptmoaAdr->lAccess;
            ptprcAdr->lPPriority = ptmoaAdr->lPPriority;
            ptprcAdr->lModifPriority = ptmoaAdr->lModifPriority  ;
            ptprcAdr->lLogSpaceSize = ptmoaAdr->lLogSpaceSize;
            ptprcAdr->lTimeSlice = ptmoaAdr->lTimeSlice;
            ptprcAdr->lMaxReqNum = ptmoaAdr->lMaxReqNum;
    }
    else
    {
//		strcpy(ptprcAdr->acPName,pibp->pname) ;		// 20021218����
		strncpy(ptprcAdr->acPName,pibp->pname, 8) ;
		
        if (pibp->rank == -1)						// �������
        {
            ptprcAdr->lLank = ptmoaAdr->lLank ;
        }
        else
        {
            ptprcAdr->lLank = pibp->rank;
        }
        
        if (pibp->uic == -1)						// �桼�����̥�����
        {
            ptprcAdr->lUid = ptmoaAdr->lUid;
        }
        else
        {
            ptprcAdr->lUid = pibp->uic ;
        }
        
        //if (pibp->fdno == -1)						// �ե����뵭�һҺ���Ŀ�
        if (pibp->fdno <= 0)
        {
            //ptprcAdr->lMaxFileNum = ptmoaAdr->lMaxFileNum;	// 20030306 ����
            ptprcAdr->lMaxFileNum = lMaxFileNum;
        }
        else
        {
            ptprcAdr->lMaxFileNum = pibp->fdno ;
        }
        
        if (pibp->atr == -1)						// �ץ���°��
        {
            ptprcAdr->lPAttr = ptmoaAdr->lPAttr  ;
        }
        else
        {
            ptprcAdr->lPAttr = pibp->atr ;
        }
        
        if (pibp->acc == -1)						// ����������
        {
            ptprcAdr->lAccess = ptmoaAdr->lAccess;
        }
        else
        {
            ptprcAdr->lAccess = pibp->acc ;
        }

        if (pibp->pri == -22)						// ��ư���ץ���ͥ����
        {
            ptprcAdr->lPPriority = ptmoaAdr->lPPriority;
        }        
        else
        {
            ptprcAdr->lPPriority = pibp->pri ;
        }
        
        if (pibp->hpri == -1)					// �ѹ���¥ץ���ͥ����
        {
            ptprcAdr->lModifPriority = ptmoaAdr->lModifPriority  ;
        }
        else
        {
            ptprcAdr->lModifPriority = pibp->hpri ;
        }
        
        if (pibp->spclass == -1)						// �������֤Υ�����
        {
            //ptprcAdr->lLogSpaceSize = ptmoaAdr->lLogSpaceSize;
            ptprcAdr->lLogSpaceSize = lLogicSpace;		// 20030306 ����
        }
        else
        {
            ptprcAdr->lLogSpaceSize = pibp->spclass;
        }
        
        if ( (pibp->tabort == 0) || (pibp->tabort == -1) )	// �����ॹ�饤����
        {
            //ptprcAdr->lTimeSlice = ptmoaAdr->lTimeSlice;
            ptprcAdr->lTimeSlice = lTimeSlice;	// 20030306 ����
        }
        else 
        {
            ptprcAdr->lTimeSlice = pibp->tabort ;
        }
        
        //if (pibp->rdno == -1)						// �ꥯ�����ȼ��̻Һ���Ŀ�
        if (pibp->rdno <= 0)
        {
            //ptprcAdr->lMaxReqNum = ptmoaAdr->lMaxReqNum;
            ptprcAdr->lMaxReqNum = lReqIdMax;	// 20030306 ����
        }
        else
        {
            ptprcAdr->lMaxReqNum = pibp->rdno ;
        }
    }
    ptprcAdr->lEndCode = D_END_CODE1;
    ptprcAdr->lDetailCode = 0;
    memset( &(ptprcAdr->func[0]), -1, 32 * sizeof(long) );
	/* �ҥץ���������*/

	ptprcAdr->cLaunchFlg = 'W';  	/* Ω�夲����  Ω����  */
	
	sigaction(SIGUSR1,&new,&old);

	os_trcget2( D_MD_OSCREPR, D_T_SYS_FORK, 0 );
	
	iRet =	fork();
	
//	os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 1, iRet );
	
	if (iRet == D_ERR_SYS)
	{
		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, OSEEWKEX );
		
		return(OSEEWKEX);				/*����Ȱ���­����������*/
	}
	/* �ץ���������*/
	DbgMsg01( DLv02, ( OutPut, "***** oscrepr FORK :%d\n",iRet) );
	DbgMsg01( DLv02, ( OutPut, "***** oscrepr FORK2 :%x\n",ptprcAdr) );

	if (iRet == 0)
	{	
	
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_GETPID, 0 );	

			/*���ҥץ���			   */
		/********************************************/
		/*	�ץ���ID�μ���						*/
		/********************************************/
		iRet = getpid();
		
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
		
		ptEsys->tMyPrcInfo.lMyPid = iRet;
		ptprcAdr->lPid = iRet;
		DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC1 :%d\n",iRet) );

		/********************************************/
		/*	�ץ饤����ƥ�������					*/
		/********************************************/
		if(NULL == pibp)
		{
			lPPriority = ptprcAdr->lPPriority;
		}
		else
		{
/*****	�ξ�����ֹ�TBCS0231���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	hpri �� pri ���ѹ�																			*/
/************************************************************************************************/
			lPPriority = pibp->pri;					// ��ư���ץ���ͥ���٤�����
/*****	�ξ�����ֹ�TBCS0231���б�		 End							��������2003.07.28	*****/
		}
		if ( lPPriority != -22 )
		{
/*****	�ξ�����ֹ�TBCS0231���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	nice �� setpriority ���ѹ�																	*/
/************************************************************************************************/
			errno = 0;								// errno ���ꥢ

			os_trcget2( D_MD_OSCREPR, D_T_SYS_SETPRIORITY, 3,
						PRIO_PROCESS, ptprcAdr->lPid, lPPriority );
													// �ץ����Υ������塼��󥰤�ͥ���٤�����
			iRet = setpriority(PRIO_PROCESS, ptprcAdr->lPid, lPPriority);
			os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 2, iRet, errno );

			DbgMsg01( DLv04, ( OutPut, "***** oscrepr lPPriority=%ld\n", lPPriority) );
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr setpriority() iRet=%d, errno=%d\n",
					iRet, errno) );
/*****	�ξ�����ֹ�TBCS0231���б�		 End							��������2003.07.28	*****/
		}

		/********************************************/
		/*	�ץ���������							*/
		/********************************************/
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : fn   :%s\n", fn ) );	
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : argv :%p\n", argp->argv ) );	
		for(lCnt = 0; lCnt < (argp->argc);lCnt++)
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr :execvp : argv :%s\n", *(argp->argv+lCnt) ));	
		}

//		os_trcget2( D_MD_OSCREPR, D_T_SYS_EXECVP, 2, fn, argp->argv );	

		iRet = execvp(fn, argp->argv);
		
//		os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
		
		DbgMsg01( DLv04, ( OutPut, "*****  Err Mess:%s\n", strerror(errno)) );
		if (iRet == D_ERR_SYS)
		{
			DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC3 :%d\n",iRet) );
			DbgMsg01( DLv02, ( OutPut, "***** oscrepr EXEC3 errno :%s\n",strerror(errno) ) );
			ptprcAdr->cLaunchFlg = 'E';  	/* Ω�夲���֡��۾ */
/*****	�ξ�����ֹ�TBCS0232���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	execvp���ֵ��� �� errno ���ѹ�																*/
/************************************************************************************************/
			ptprcAdr->lEndCode = errno;				// errno������
/*****	�ξ�����ֹ�TBCS0232���б�		 End							��������2003.07.28	*****/
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_KILL, 2, getppid(), SIGUSR1 );
		
			iRet = kill(getppid(), SIGUSR1);				// �ƥץ����˥����ʥ������
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_END, 1, iRet );
			
			os_trcget2( D_MD_OSCREPR, D_T_SYS_EXIT, 0 );
			
			exit(0);
		}
	}
	else
	{ 					/*���ƥץ���			   */
		/********************************************/
		/*	�ץ���������							*/
		/********************************************/
		DbgMsg01( DLv04, ( OutPut, "***** sigsuspend ľ�� :\n") );
		
		while( ('W' == ptprcAdr->cLaunchFlg) )
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr sigsuspend\n"));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr A ptprcAdr->cLaunchFlg:%c\n"
					, ptprcAdr->cLaunchFlg ));
			pause();
		}
		
		DbgMsg01( DLv04, ( OutPut, "***** oscrepr C ptprcAdr->cLaunchFlg:%x\n"
					, ptprcAdr->cLaunchFlg ));

		sigaction(SIGUSR1, &old, NULL);
		if('S' == ptprcAdr->cLaunchFlg)
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT NORMAL\n"));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT  :%08lx\n",ptprcAdr->lPCode) );
			os_trcget2( D_MD_OSCREPR, D_T_TRA_OUT, 1, ptprcAdr->lPCode );
			return(ptprcAdr->lPCode);
		}
		else
		{
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT ERROR\n" ));
			DbgMsg01( DLv04, ( OutPut, "***** oscrepr EXIT  :%08lx\n",ptprcAdr->lPCode) );
/*****	�ξ�����ֹ�TBCS0232���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	�ֵ��͡�OSEEILMF�� �� �۾���������ܤ���褦�˽���											*/
/************************************************************************************************/
			goto err_oscrepr;						// �۾������
/*****	�ξ�����ֹ�TBCS0232���б�		 End							��������2003.07.28	*****/
		}
	}

err_oscrepr:
	/* �۾���� */
/*****	�ξ�����ֹ�TBCS0232���б�		Start							��������2003.07.28	*****/
/************************************************************************************************/
/*	errno �� ptprcAdr->lEndCode ���ѹ�															*/
/************************************************************************************************/
	switch(ptprcAdr->lEndCode) {					// �ץ��������ơ��֥�ν�λ�����ɤ�Ƚ��
	case EACCES:
	case ENOEXEC:
	case ELIBBAD:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEILMF, ptprcAdr->lEndCode );
		return (OSEEILMF); 
		break;
	case EFAULT:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEACCV, ptprcAdr->lEndCode );
		return (OSEEACCV);
		break;
	case ENOMEM:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEWKEX, ptprcAdr->lEndCode );	
		return (OSEEWKEX);
		break;
	case ENFILE:
	case EMFILE:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEOPEN, ptprcAdr->lEndCode );	
		return (OSEEOPEN);
		break;
	default:
		os_trcget2( D_MD_OSCREPR, D_T_ERR_SYS, 2, OSEEFAIL, ptprcAdr->lEndCode );
		return (OSEEFAIL);
	}
/*****	�ξ�����ֹ�TBCS0232���б�		 End							��������2003.07.28	*****/
}


void func()
{
	DbgMsg01( DLv04, ( OutPut, "***** Call func in oscrepr\n") );
}


/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
