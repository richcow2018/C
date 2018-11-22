/************************************************************************************************/
/*																								*/
/*	＜関数名＞ void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 			*/
/*                              short *sCode, long lMsgLen)										*/
/*	                             	     			    										*/
/*																								*/
/*	＜機能概要＞ 出力メッセージを取得															*/
/*																								*/
/*																								*/
/*	パラメーター:																				*/
/*		パラメーター(1)  - 	メッセージフォーマット情報アドレス									*/
/*		パラメーター(2)	 - 	データ格納バッファ													*/
/*		パラメーター(3)	 -	編集後のメッセージ													*/
/*		パラメーター(4)	 -	データ格納バッファのサイズ											*/
/*		パラメーター(5)	 -	コード変換情報														*/
/*		パラメーター(6)	 -	テーブルのメッセージサイズ											*/
/*																								*/
/*																								*/
/*																								*/
/*																								*/
/************************************************************************************************/
void os_GetMsg(char *pcFmtAdr, char *pcBuf, char **pcMsg, long lBufLen, 
				short *sCode, long lMsgLen)
{
	/********************************************************************************************/
	/*  ワーク領域                                                                              */
	/********************************************************************************************/
	
	long lMsgStart = 0;										// メッセージフォーマット情報用の先頭
	
	long lMsgEnd = 0;										// メッセージフォーマット情報用の終端
	
	long lBufStart = 0;										// データ格納バッファ用の先頭
	
	long lBufEnd = 0;										// データ格納バッファ用の終端 
	
	long ltemp = 0;
	
	long lFlg = 0;
	
	long lCnt = 0;
	
	/********************************************************************************************/
	/*	 本処理																				    */
	/********************************************************************************************/

//	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, lBufLen + lMsgLen + 20);
															// メッセージフォーマット情報と
															// データ格納バッファを確保するため
//	*pcMsg = (char*)malloc( (lBufLen * 2) + lMsgLen);		// の領域を取ります
															// TBCS0123
															
															// TBCS0153 / TBCS0155
	os_trcget2( D_MD_OSWRITE1, D_T_SYS_MALLOC, 1, ( (lBufLen * 100) + (lMsgLen + 9) ) );

	*pcMsg = (char*)malloc( (lBufLen * 2) + (lMsgLen + 9)); // データ編集の領域を確保
															// 全角に編集するサイズ分=引数*2
															// 時間,スペース,[]のサイズ分=9
															// TBCS0153 / TBCS0155

	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );

#ifndef debug_test	
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (1) lMsgLen == %ld\n", lMsgLen) );	
		
	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (2) lBufLen == %ld\n", lBufLen) );	
#endif

	lMsgStart = 8;
	
	while(lMsgStart > 0)
	{ 
															// 編集制御文字を検索
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
	
	if ( lMsgStart != -1) 									// 見つかった場合
	{
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgStart - 8); 	// 指定範囲されたメッセージ情報から
															// 出力メッセージに加え
															
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
															// データ格納バッファの埋め込み文字列
															// の範囲を取得
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
				{											// データ格納バッファから
														// 出力メッセージに編集
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
															// メッセージフォーマット情報から
															// 出力メッセージに編集
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
															// メッセージフォーマット情報から
															// 出力メッセージに編集
				
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
					
															// メッセージフォーマット情報から
															// 出力メッセージに編集
															
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (15) lBufStart == %ld\n", lBufStart ) );	
			
			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (16) pcFmtAdr[lMsgStart]  == %c\n", 
					pcFmtAdr[lMsgStart]  ) );
#endif
		}


	}
	else
	{
		
	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (8) pcFmtAdr == %s\n", pcFmtAdr) );	
		
		strncpy(*pcMsg, (pcFmtAdr + 8), lMsgLen); 			// 指定範囲されたメッセージ情報か
															// 出力メッセージに加え
	} 

}


