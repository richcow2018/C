/************************************************************************************************/
/*	���	��������																			*/
/*			  ������ңΣԣԥǡ���																*/
/*				��ͻ�ӥ��ͥ���������															*/
/*																								*/
/*																								*/
/*	����ʪ	�̣��̣�ݣӣͣХ����ƥ�    �ԣң��ģť��ߥ�졼��									*/
/************************************************************************************************/
/* ���оݶ�̳̾��					 �ԣң��ģť��ߥ�졼��										*/
/* ���оݶ�̳�ɣġ� 				 �ԣң� 													*/
/* �㥵���ӥ�����̾��				 ���̴ؿ�		 											*/
/* �㥵���ӥ����ܣɣġ� 			 �أأأأأأ� 											*/
/* ��⥸�塼��̾��                  �ס���Хåե����ɥ쥹�������������å�                     */
/* ��⥸�塼��ɣġ�				 os_ChkPB		 											*/
/* ��⥸�塼�����֡�																			*/
/*----------------------------------------------------------------------------------------------*/
/* ��Ŭ�ѵ���̾��					 ���ѥ����� 												*/
/* ��Ŭ�ѣϣӡ� 					 �̣����� 												*/
/* �㳫ȯ�Ķ��� 					 �ңȣ��ӣ����� 											*/
/* �㵭�Ҹ���� 					 �ø��� 													*/
/* ��⥸�塼����֡�				 �ؿ�														*/
/* �㵡ǽ��ʬ�� 																				*/
/* ���оݥǡ�����																				*/
/* �㹩�������ض�ʬ��																			*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯ�����ƥ�̾��				 �̣��̣�ݣӣͣХ����ƥ�									*/
/* �㳫ȯ�����ƥ��ֹ�� 			 �УУ����£����������� 									*/
/*----------------------------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)			    	*/
/* �������ֹ�� 					 148-1457(03-5437-1457) 									*/
/*----------------------------------------------------------------------------------------------*/
/* ���߷׼�̾�� 					 �ã»��ӥ��ͥ����ô�� 									*/
/* ���߷�ǯ������					 ��������ǯ��������� 									*/
/* ���߷׽�����̾�� 																			*/
/* ���߷׽���ǯ�����ڤӽ����ɣġ�																*/
/*----------------------------------------------------------------------------------------------*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤��¼)             */
/* �㥽��������ǯ������ 			 ��������ǯ  ������� 									*/
/* �㥽���������ԡ�                  �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤����)             */
/* �㥽��������ǯ�����ڤӽ����ɣġ�  ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
/*----------------------------------------------------------------------------------------------*/
/* �㸫�ѥ��ƥå׿���				 ���ƥå�													*/
/*----------------------------------------------------------------------------------------------*/
/* �㵡ǽ���ס� 																				*/
/*		  �ס���Хåե����ɥ쥹�������������å�												*/
/*																								*/
/*----------------------------------------------------------------------------------------------*/
/* ��ƽз����� 																				*/
/*		#include	<os_ChkPB_ins.h> 															*/
/*																								*/
/*	 long os_ChkPB(void *pvPbAdr)																*/
/*																								*/
/* �㲾������																					*/
/*		void *pvPbAdr	�ס���Хåե����ɥ쥹													*/
/*		TEbpcTableInd *ptEbpcIndPar EBPC���������ɥ쥹											*/
/*																								*/
/* ���ֵ��͡�																					*/
/*		���ｪλ			NORMAL																*/
/*		�۾ｪλ			OSEEIPOL															*/
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

#include "os_ChkPB_ins.h"

/****************************************************************************/
/* �����Ѵؿ��ץ�ȥ��������                                               */
/****************************************************************************/
long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr);
long os_Chk_Unit_Adr(TAdrDat *ptAdrDat, long lUnitAdr);
long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr, long size, long unitsize, long maxnum);
/****************************************************************************/
/* ��ǽ���ס���Хåե����ɥ쥹�������������å�                             */
/* ��������2003ǯ03��14��                                                   */
/* �ѹ�����                                                                 */
/* �����ԡ���¼                                                             */
/* �ƽз�����                                                               */
/*   long os_ChkPB(void *pvPbAdr)                                           */
/*     void *pvPbAdr        �ס���Хåե����ɥ쥹                          */
/*     TEbpcTableInd *ptEbpcIndPar ����EBPC���������ɥ쥹                   */
/*                                                                          */
/****************************************************************************/
long os_ChkPB(void *pvPbAdr, TEbpcTableInd *ptEbpcIndPar)
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
	long lOpFlg = D_SARCH_BPIND;				// ��������ʬ���ե饰
	long lCnt = 0;								// ������
	long lRes = 0;
	long lPbInd = 0;
	long lUnit = 0;

	TEbpcTableInd *ptEbpcInd = NULL;			// BP�������ݥ���
	TEpbcTableInd *ptEpbcInd = NULL;			// PB�������ݥ���
	
	TAdrDat tBPdat, tPBdat;

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
	DbgMsg01( DLv02, ( OutPut, "***** %s:Start DbgMainFnc\n", D_PROC_NAME ) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:pvPbAdr:%p\n", D_PROC_NAME, pvPbAdr) );
	DbgMsg01( DLv04, ( OutPut, "***** %s:ptEbpcIndPar:%p\n", D_PROC_NAME, ptEbpcIndPar ));
	
	if(NULL != ptEbpcIndPar)
	{
												// �����EBPC�������������
		lOpFlg = D_CHK_MEM_RANGE2;
	}
	
	ptEbpcInd = (TEbpcTableInd *)(ptEbpc + 1);
	
	for(;;)
	{
		switch(lOpFlg)
		{
		case D_SARCH_BPIND:						// BP����������
			DbgMsg01( DLv04, ( OutPut, "***** SARCH_BPIND\n" ));
			if(lCnt >= ptEbpc->lMaxNum)
			{
				lOpFlg = D_ERR;					// ����������̵��
				break;
			}
			else if(D_STAT_CREATED != ptEbpcInd->cStat)
			{
				ptEbpcInd += 1;					// ̤�����Ǥ���м��θ������򸡺�
				break;
			}
			DbgMsg01( DLv04, ( OutPut, "***** %s:ptEbpcInd:%p\n", D_PROC_NAME, ptEbpcInd) );
												// �����������ȯ��
			lOpFlg = D_CHK_MEM_RANGE;			// ��ͭ�����ϰϥ����å���
			break;

		case D_CHK_MEM_RANGE:					// ��ͭ�����ϰϥ����å�
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MEM_RANGE\n" ));

			lRes = os_Chk_SetDat(&tBPdat,
								(long)(ptEbpcInd->pvEbpcAdr),	// ��Ƭ���ɥ쥹����
								0,								// �ΰ襵��������
								ptEbpcInd->lUnitSize + 4,		// ��˥åȥ���������
								ptEbpcInd->lMaxUnitNum );		// ��˥åȺ��������

												// ��˥åȥ��ɥ쥹����Ƭ���ɥ쥹����
			lUnit = (long)pvPbAdr - 4;

			lRes = os_Chk_Mem_Range( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
												//�ϰϳ��Ǥ���м��θ������θ���
				lOpFlg = D_SARCH_BPIND;
				ptEbpcInd += 1;
				break;
			}
												// ��˥åȥ��ɥ쥹�����å���
			lOpFlg = D_CHK_MUCH_PBADR;
			break;

		case D_CHK_MUCH_PBADR:					// ��˥åȥ��ɥ쥹�����å�
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MUCH_PBADR\n" ));

			lRes = os_Chk_Unit_Adr( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
				lOpFlg = D_ERR;
				break;
			}

												// ����PB�������ϰϥ����å���
			lOpFlg = D_CHK_PBIND_RANGE;
			break;

		case D_CHK_PBIND_RANGE:					// ����PB�������ϰϥ����å�
			DbgMsg01( DLv04, ( OutPut, "***** CHK_PBIND_RANGE\n" ));

			lRes = os_Chk_SetDat(&tPBdat,
								(long)(ptEpbc + 1),				// �������ΰ���Ƭ���ɥ쥹����
																// �������ΰ襵��������
								(ptEsys->tMstEPBC.lSize) - sizeof(TEpbcTable),
								sizeof(TEpbcTableInd),			// ����������������
								0 );							// ������������
												// ��˥å�-4�������ͤ�PB���������ɥ쥹�Ȥ���
			lPbInd = *((long*)(pvPbAdr -4));

			lRes = os_Chk_Mem_Range( &tPBdat, lPbInd );
			if(NORMAL != lRes)
			{
				lOpFlg = D_ERR;
				break;
			}
												// ����PB��˥åȥ��ɥ쥹�����å�
			lOpFlg = D_CHK_PBADR;
			break;

		case D_CHK_PBADR:						//PB������ ��˥åȥ��ɥ쥹���
			DbgMsg01( DLv04, ( OutPut, "***** CHK_PBADR\n" ));
			lRes = os_Chk_Unit_Adr( &tPBdat, lPbInd );
			if(NORMAL == lRes)
			{
				DbgMsg01( DLv04, ( OutPut, "***** ��˥åȥ��ɥ쥹�����������å�\n" ));
				ptEpbcInd = (TEpbcTableInd *)lPbInd;
												// ��˥åȥ��ɥ쥹�����
				DbgMsg01( DLv04, ( OutPut, "***** %s:ptEpbcInd->pvUnitAdr:%p\n"
								, D_PROC_NAME, ptEpbcInd->pvUnitAdr ));
				DbgMsg01( DLv04, ( OutPut, "***** %s:pvPbAdr:%p\n"
								, D_PROC_NAME, pvPbAdr ));

/*****  �㳲�б���TBCS0263��	Start									��������2003.08.06  *****/
/************************************************************************************************/
/*  ��˥åȻ��Ѿ��֤Υ����å�����                                                            */
/************************************************************************************************/
												// ��˥åȥ��ɥ쥹������å�
				if( ptEpbcInd->pvUnitAdr == pvPbAdr )
/*****  �㳲�б���TBCS0263��	End										��������2003.08.06  *****/
				{
					lOpFlg = D_NORMAL;
					break;
				}
			}

			lOpFlg = D_ERR;
			break;

		case D_CHK_MEM_RANGE2:					// ��ͭ�����ϰϥ����å� BP������������
			ptEbpcInd = ptEbpcIndPar;
			DbgMsg01( DLv04, ( OutPut, "***** CHK_MEM_RANGE2\n" ));

			lRes = os_Chk_SetDat(&tBPdat,
								(long)(ptEbpcInd->pvEbpcAdr),	// ��Ƭ���ɥ쥹����
								0,								// �ΰ襵��������
								ptEbpcInd->lUnitSize + 4,		// ��˥åȥ���������
								ptEbpcInd->lMaxUnitNum );		// ��˥åȺ��������

												// ��˥åȥ��ɥ쥹����Ƭ���ɥ쥹
			lUnit = (long)pvPbAdr - 4;

			lRes = os_Chk_Mem_Range( &tBPdat, lUnit );
			if(NORMAL != lRes)
			{
												//�ϰϳ��Ǥ���Х��顼���֤�
				lOpFlg = D_ERR;
				break;
			}
												// ��˥åȥ��ɥ쥹�����å���
			lOpFlg = D_CHK_MUCH_PBADR;

			break;

		/****************************************/
		/*  ���顼����                          */
		/****************************************/
		case D_ERR:
			DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc Err\n", D_PROC_NAME ) );
			return(OSEEIPOL);
			break;

		/****************************************/
		/*  �������                            */
		/****************************************/
		case D_NORMAL:
			DbgMsg01( DLv02, ( OutPut, "***** %s:End DbgMainFnc Normal\n", D_PROC_NAME ) );
			return(NORMAL);
			break;
		}
	}

}


/****************************************************************************/
/* ��ǽ�����ɥ쥹�ϰϥ����å�                                               */
/*   long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)                */
/*     TAdrDat *ptAdrDat    ���ɥ쥹����¤��                              */
/*     long lUnitAdr        �оݥ��ɥ쥹                                    */
/*                                                                          */
/****************************************************************************/
long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)
{
	// �ǽ�˹�¤�Τη礱�Ƥ������Ǥ�Ĥ�Υ��Ф������
	// ɬ�ܥ��Ф���Ƭ���ɥ쥹 ����ʳ��ϣ������礱�Ƥ��ɤ�
	long lHead = 0;								// ��Ƭ���ɥ쥹
	long lLast = 0;								// ��ü���ɥ쥹
												// ��Ƭ���ɥ쥹����
	lHead = ptAdrDat->lTopAdr;
												// ��ü���ɥ쥹����
	lLast = lHead + ptAdrDat->lMemSize;
	
	DbgMsg01( DLv04, ( OutPut, "***** %s:TopAddress   :%p\n", D_PROC_NAME, lHead));
	DbgMsg01( DLv04, ( OutPut, "***** %s:TermAddress  :%p\n", D_PROC_NAME, lLast));
	DbgMsg01( DLv04, ( OutPut, "***** %s:TargetAddress:%p\n", D_PROC_NAME, lUnitAdr));
	
	if( (lHead <= lUnitAdr) && (lLast > lUnitAdr) )
	{
		return(NORMAL);
	}
	
	return(D_ERR_ADR);
}

/****************************************************************************/
/* ��ǽ�����ɥ쥹�����������å�                                             */
/*   long os_Chk_Mem_Range(TAdrDat *ptAdrDat, long lUnitAdr)                */
/*     TAdrDat *ptAdrDat    ���ɥ쥹����¤��                              */
/*     long lUnitAdr        �оݥ��ɥ쥹                                    */
/*                                                                          */
/****************************************************************************/
long os_Chk_Unit_Adr(TAdrDat *ptAdrDat, long lUnitAdr)
{
	long lTargtNum = 0;
	long lTargtAdr = 0;
	
	// A = (��˥åȥ��ɥ쥹-��Ƭ���ɥ쥹)/��˥åȥ�����
	lTargtNum = (lUnitAdr - ptAdrDat->lTopAdr) / ptAdrDat->lUnitSize;

	// B = ��Ƭ���ɥ쥹 + (A * ��˥åȥ�����)
	lTargtAdr = ptAdrDat->lTopAdr + (lTargtNum * ptAdrDat->lUnitSize);
	
												// �ԥ�ݥ���ȼ��ǵ�᤿��̤Ȱ����Ȥ���Ӥ���
	DbgMsg01( DLv04, ( OutPut, "***** %s:ͽ�ۥ��ɥ쥹:%p\n", D_PROC_NAME, lTargtAdr));
	DbgMsg01( DLv04, ( OutPut, "***** %s:�оݥ��ɥ쥹:%p\n", D_PROC_NAME, lUnitAdr));
	if(lUnitAdr == lTargtAdr)
	{
		return(NORMAL);
	}
	return(D_ERR_ADR);
	
}

/****************************************************************************/
/* ��ǽ���оݾ�������                                                       */
/*   long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr,                     */
/*                      long size, long unitsize, long maxnum)              */
/*     TAdrDat *ptAdrDat    ���ɥ쥹����¤��                              */
/*     long topadr          ��Ƭ���ɥ쥹                                    */
/*     long size            �ΰ襵����                                      */
/*     long unitsize        ��˥åȥ�����                                  */
/*     long maxnum          ��˥åȺ����                                  */
/*                                                                          */
/****************************************************************************/
long os_Chk_SetDat(TAdrDat *ptAdrDat, long topadr, long size, long unitsize, long maxnum)
{
	long lSize = 0;								// ���ꥵ����
	long lUnit = 0;								// ��˥åȥ�����
	long lNum = 0;								// ��˥åȸĿ�
	
	ptAdrDat->lTopAdr = topadr;					// ��Ƭ���ɥ쥹����
	ptAdrDat->lMemSize = size;					// �ΰ襵��������
	ptAdrDat->lUnitSize = unitsize;				// ��˥åȥ���������
	ptAdrDat->lMaxNum = maxnum;					// ��˥åȸĿ�����

	if(0 == ptAdrDat->lMemSize)
	{
		lSize = ptAdrDat->lUnitSize * ptAdrDat->lMaxNum;
		ptAdrDat->lMemSize = lSize;
	}
	else if(0 == ptAdrDat->lUnitSize)
	{
		lUnit = ptAdrDat->lMemSize / ptAdrDat->lMaxNum;
		ptAdrDat->lUnitSize = lUnit;
	}
	else if(0 == ptAdrDat->lMaxNum)
	{
		lNum = ptAdrDat->lMemSize / ptAdrDat->lUnitSize;
		ptAdrDat->lMaxNum = lNum;
	}

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lTopAdr   :%p\n"
			, D_PROC_NAME, ptAdrDat->lTopAdr) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lMemSize  :%ld\n"
			, D_PROC_NAME, ptAdrDat->lMemSize) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lUnitSize :%ld\n"
			, D_PROC_NAME, ptAdrDat->lUnitSize) );

	DbgMsg01( DLv04, ( OutPut, "***** %s:ptAdrDat->lMaxNum   :%ld\n"
			, D_PROC_NAME, ptAdrDat->lMaxNum) );

	
	return(NORMAL);

}

/*****************************************************************************/
/* End                                                                       */
/*****************************************************************************/
