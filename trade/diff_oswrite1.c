41,43d40
< /* �㥽���������ԡ� 			 	 ���ץ饤����												*/
< /* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
< /*																�ξ�����ֹ�ʣԣ£ãӣ���������*/
205,207d201
< 
< 	
< 	memset(pcTmpBufMsgId, 0x00, 4);						// TBCS0153/TBCS0155
209,218c203,204
< 	if(len >= 4)										// TBCS0153/TBCS0155
< 	{
< 		strncpy(pcTmpBufMsgId, buf, 4);					// �ǡ�����Ǽ�Хåե�����
< 														// ��å��������̻Ҥ���
< 	}
< 	else												// TBCS0153/TBCS0155
< 	{
< 		strncpy(pcTmpBufMsgId, buf, len);				// TBCS0153/TBCS0155
< 	}
< 
---
> 	strncpy(pcTmpBufMsgId, buf, 4); 						// �ǡ�����Ǽ�Хåե�����
> 															// ��å��������̻Ҥ���
408c394
< //		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );		
---
> 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );		
411,419c397
< //		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
< 		
< 															// TBCS0153/TBCS0155
< 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
< 															// TBCS0153/TBCS0155
< 															// ���Ѥ��Խ����륵����ʬ=����*2
< 															// ����,���ڡ���,[]�Υ�����ʬ=9
< 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
< 		
---
> 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
650c628
< //		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
---
> 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
653,660c631
< //		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
< 
< 																	// TBCS0153/TBCS0155
< 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
< 															// TBCS0153/TBCS0155
< 															// ���Ѥ��Խ����륵����ʬ=����*2
< 															// ����,���ڡ���,[]�Υ�����ʬ=9
< 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
---
> 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
927c898
< //		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
---
> 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20 );
930,938c901
< //		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
< 
< 
< 															// TBCS0153/TBCS0155
< 		os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
< 															// TBCS0153/TBCS0155
< 															// ���Ѥ��Խ����륵����ʬ=����*2
< 															// ����,���ڡ���,[]�Υ�����ʬ=9
< 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
---
> 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
1136c1099
< //	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
---
> 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
1139c1102
< //	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// ���ΰ����ޤ�
---
> 	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// ���ΰ����ޤ�
1141,1153d1103
< 															
< 															// TBCS0153 / TBCS0155
< 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
< 
< 	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // �ǡ����Խ����ΰ�����
< 															// ���Ѥ��Խ����륵����ʬ=����*2
< 															// ����,���ڡ���,[]�Υ�����ʬ=9
< 															// TBCS0153 / TBCS0155
< 
< 
< 
< 
< 
