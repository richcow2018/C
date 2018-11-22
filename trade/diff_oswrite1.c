41,43d40
< /* ＜ソース修正者＞ 			 	 サプライ　朱												*/
< /* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月１７日     故障管理番号（ＴＢＣＳ０１５３）*/
< /*																故障管理番号（ＴＢＣＳ０１５５）*/
205,207d201
< 
< 	
< 	memset(pcTmpBufMsgId, 0x00, 4);						// TBCS0153/TBCS0155
209,218c203,204
< 	if(len >= 4)										// TBCS0153/TBCS0155
< 	{
< 		strncpy(pcTmpBufMsgId, buf, 4);					// データ格納バッファから
< 														// メッセージ識別子を取る
< 	}
< 	else												// TBCS0153/TBCS0155
< 	{
< 		strncpy(pcTmpBufMsgId, buf, len);				// TBCS0153/TBCS0155
< 	}
< 
---
> 	strncpy(pcTmpBufMsgId, buf, 4); 						// データ格納バッファから
> 															// メッセージ識別子を取る
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
< 															// 全角に編集するサイズ分=引数*2
< 															// 時間,スペース,[]のサイズ分=9
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
< 															// 全角に編集するサイズ分=引数*2
< 															// 時間,スペース,[]のサイズ分=9
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
< 															// 全角に編集するサイズ分=引数*2
< 															// 時間,スペース,[]のサイズ分=9
< 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9) );
---
> 		pcTmpForMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);
1136c1099
< //	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
---
> 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
1139c1102
< //	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// の領域を取ります
---
> 	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// の領域を取ります
1141,1153d1103
< 															
< 															// TBCS0153 / TBCS0155
< 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 2) + (lMsgLen + 9) ) );
< 
< 	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // データ編集の領域を確保
< 															// 全角に編集するサイズ分=引数*2
< 															// 時間,スペース,[]のサイズ分=9
< 															// TBCS0153 / TBCS0155
< 
< 
< 
< 
< 
