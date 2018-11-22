/************************************************************************************************/
/*																								*/
/*	���֐����� void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 			*/
/*                              short *sCode, long lMsgLen)										*/
/*	                             	     			    										*/
/*																								*/
/*	���@�\�T�v�� �o�̓��b�Z�[�W���擾															*/
/*																								*/
/*																								*/
/*	�p�����[�^�[:																				*/
/*		�p�����[�^�[(1)  - 	���b�Z�[�W�t�H�[�}�b�g���A�h���X									*/
/*		�p�����[�^�[(2)	 - 	�f�[�^�i�[�o�b�t�@													*/
/*		�p�����[�^�[(3)	 -	�ҏW��̃��b�Z�[�W													*/
/*		�p�����[�^�[(4)	 -	�f�[�^�i�[�o�b�t�@�̃T�C�Y											*/
/*		�p�����[�^�[(5)	 -	�R�[�h�ϊ����														*/
/*		�p�����[�^�[(6)	 -	�e�[�u���̃��b�Z�[�W�T�C�Y											*/
/*																								*/
/*																								*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 
				short *sCode, long lMsgLen)
{
	/********************************************************************************************/
	/*  ���[�N�̈�                                                                              */
	/********************************************************************************************/
	
	long lMsgStart = 0;										// ���b�Z�[�W�t�H�[�}�b�g���p�̐擪
	
	long lMsgEnd = 0;										// ���b�Z�[�W�t�H�[�}�b�g���p�̏I�[
	
	long lBufStart = 0;										// �f�[�^�i�[�o�b�t�@�p�̐擪
	
	long lBufEnd = 0;										// �f�[�^�i�[�o�b�t�@�p�̏I�[ 
	
	long ltemp = 0;
	
	long lFlg = 0;
	
	long lCnt = 0;
	
	/********************************************************************************************/
	/*	 �{����																				    */
	/********************************************************************************************/

//	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
															// ���b�Z�[�W�t�H�[�}�b�g����
															// �f�[�^�i�[�o�b�t�@���m�ۂ��邽��
//	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// �̗̈�����܂�
															// TBCS0123
															
															// TBCS0153 / TBCS0155
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 100) + (lMsgLen + 9) ) );

	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // �f�[�^�ҏW�̗̈���m��
															// �S�p�ɕҏW����T�C�Y��=����*2
															// ����,�X�y�[�X,[]�̃T�C�Y��=9
															// TBCS0153 / TBCS0155

	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );

#ifndef debug_test	
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (1) lMsgLen == %ld\n", lMsgLen) );	
		
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (2) lBufLen == %ld\n", lBufLen) );	
#endif

	lMsgStart = 8;
	
	while(lMsgStart > 0)
	{ 
															// �ҏW���䕶��������
		lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);

#ifndef debug_test	
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (2) pcFmtAdr[lMsgStart + 1] == %c\n", pcFmtAdr[lMsgStart + 1]) );	
		
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (3) lMsgStart == %ld\n", lMsgStart) );	
#endif
		if(lMsgStart != -1)
		{
			if( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') )
			{
				break;
			}
			else
			{
				lMsgStart ++;
			}
		}
	}
#ifndef debug_test
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(4) lMsgStart == %ld\n", lMsgStart ) );
#endif
	
	if ( lMsgStart != -1) 									// ���������ꍇ
	{
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgStart - 8); 	// �w��͈͂��ꂽ���b�Z�[�W��񂩂�
															// �o�̓��b�Z�[�W�ɉ���
															
		ltemp = lMsgStart - 8;
		
		strncpy((*pcMsg+ltemp), "\0", 1); 

#ifndef debug_test		
		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(5) *pcMsg\n ") );
#endif													

		while(lMsgEnd != -1)
		{
		
			if( (pcFmtAdr[lMsgStart] == '%') &&
			  ( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') ) )
			  {
															// �f�[�^�i�[�o�b�t�@�̖��ߍ��ݕ�����
															// �͈̔͂��擾
				os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);
			  

//			if ( ( ( pcFmtAdr[lMsgEnd] == '%' ) && ( pcFmtAdr[lMsgEnd+1] == 'z' ) ) ||
//				 ( ( pcFmtAdr[lMsgStart] == '%' ) && ( pcFmtAdr[lMsgStart+1] == 'z' ) ) )

				if( ( pcFmtAdr[lMsgStart] == '%' ) && ( pcFmtAdr[lMsgStart+1] == 'z' ) )
				{
				
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(6) lBufStart = %ld\n ", lBufStart) );
					
														// TBCS0123
					os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);

				}
				else 
				{											// �f�[�^�i�[�o�b�t�@����
														// �o�̓��b�Z�[�W�ɕҏW
					os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
				
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(7) lBufStart = %ld\n ", lBufStart) );
				}
			
			}
		
#ifndef debug_test						
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (8) lBufStart == %d\n", lBufStart ) ); 
			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(9) lBufEnd == %d\n", lBufEnd ) ); 
#endif			

			lMsgEnd = os_SeekStr(pcFmtAdr, '%', lMsgStart + 1, lMsgLen);
			
			if(lMsgEnd != -1)  
			{
				
				if( (pcFmtAdr[lMsgEnd + 1 ] == 'z') || (pcFmtAdr[lMsgEnd + 1] == 's') ) 
				{
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(10) pcFmtAdr[lMsgEnd ] == %c\n", pcFmtAdr[lMsgEnd ] ) );
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(10.1) pcFmtAdr[lMsglEnd + 1  ] == %c\n", pcFmtAdr[lMsgEnd +1 ] ) );
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(10.2)lMsgStart == %ld\n", lMsgStart ) );  
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(10.3)lMsgEnd == %ld\n", lMsgEnd ) );  
					
					if( ( lMsgEnd - lMsgStart ) > 2 )
					{
															// ���b�Z�[�W�t�H�[�}�b�g��񂩂�
															// �o�̓��b�Z�[�W�ɕҏW
						os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 2, lMsgEnd);
					}
					
					lMsgStart = lMsgEnd;
				}
				else
				{
					
					//lMsgStart = lMsgEnd + 1;
					
//					lMsgStart++;
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(11) pcFmtAdr[lMsgEnd ] == %c\n", pcFmtAdr[lMsgEnd ] ) );
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(11.1) pcFmtAdr[lMsgEnd + 1  ] == %c\n", pcFmtAdr[lMsgEnd +1 ] ) );
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(12)lMsgStart == %ld\n", lMsgStart ) );  
					
					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(12.1)lMsgEnd == %ld\n", lMsgEnd ) );  
				}
				
//				lMsgStart = lMsgEnd;
		
			}
			else
			{
															// ���b�Z�[�W�t�H�[�}�b�g��񂩂�
															// �o�̓��b�Z�[�W�ɕҏW
				
				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(13) pcFmtAdr[lMsgEnd +2 ] == %c\n", pcFmtAdr[lMsgEnd +2 ] ) );
				
				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(13.1) pcFmtAdr[lMsgEnd ] == %c\n", pcFmtAdr[lMsgEnd ] ) );
					
				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(13.2) pcFmtAdr[lMsgStart + 1  ] == %c\n", pcFmtAdr[lMsgStart +1 ] ) );
					
				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(13.3)lMsgStart == %ld\n", lMsgStart ) );  
					
				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(13.4)lMsgEnd == %ld\n", lMsgEnd ) );  
				
				
				os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 2, lMsgLen);	
			}
			



#ifndef debug_test			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (14) pcFmtAdr[lMsgStart] == %c\n", 
					pcFmtAdr[lMsgStart] ) ); 
					
															// ���b�Z�[�W�t�H�[�}�b�g��񂩂�
															// �o�̓��b�Z�[�W�ɕҏW
															
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (15) lBufStart == %ld\n", lBufStart ) );	
			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (16) pcFmtAdr[lMsgStart]  == %c\n", 
					pcFmtAdr[lMsgStart]  ) );
#endif
		}


	}
	else
	{
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (8) pcFmtAdr == %s\n", pcFmtAdr) );	
		
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgLen); 			// �w��͈͂��ꂽ���b�Z�[�W���
															// �o�̓��b�Z�[�W�ɉ���
	} 

}


