37c37
< /* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカ:ＸＸＸＸ)					*/
---
> /* ＜ソース作成者＞ 				 ＣＢ事ビジネス企画担当(メーカー：サプライ)					*/
43a44,45
> /* ＜ソース修正者＞ 			 	 サプライ　朱												*/
> /* ＜ソース正年月日及び修正ＩＤ＞	 ２００３年　６月２５日     故障管理番号（ＴＢＣＳ０１７２）*/
49c51,55
< /*	 ＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸＸ						*/
---
> /*		「データ格納バッファ」に格納されたメッセージ識別文字（先頭４桁の文字）をKEYとして		*/
> /*		共有メモリ上に展開されているコンソール出力用／ログファイル出力用／特定プロセス出力用の	*/
> /*		メッセージフォーマットを取得し、それぞれ出力メッセージ編集を行う。						*/
> /*		編集完了後に出力メッセージを、「メッセージ出力指示文字」に従い、						*/
> /*		コンソール／ログファイル／特定のプロセスに対してメッセージ出力を行う。					*/
53c59
< /*		#include	<XXXXX.h>																	*/
---
> /*		#include	<oswrite1.h>																*/
58,60c64,66
< /*      long fildes                              										        */
< /*      char *buf                                        										*/
< /*      long len                                         										*/
---
> /*      long fildes        ファイル記述子                     							        */
> /*      char *buf          データ格納バッファ（NULL以外）                              			*/
> /*      long len           指定データサイズ（0以上）                              				*/
63c69,70
< /*	   0L																						*/
---
> /*		正常終了			0x0000XXXX															*/
> /*		異常終了			0x940dXXXX															*/
1131a1139,1140
> 	long lCnt = 0;
> 	
1149a1159
> 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );
1150a1161,1163
> 	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0) lMsgLen == %ld\n", lMsgLen) );	
> 		
> 	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.1) lBufLen == %ld\n", lBufLen) );	
1151a1165,1171
> 															// TBCS0172		Start
> 	lMsgStart = 8;
> 	
> 	while(lMsgStart > 0)
> 	{ 
> 															// 編集制御文字を検索
> 		lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);
1152a1173,1175
> 		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.2) pcFmtAdr[lMsgStart + 1] == %c\n",
> 				pcFmtAdr[lMsgStart + 1]) );	
> 		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.3) lMsgStart == %ld\n", lMsgStart) );
1154,1159c1177,1188
< 	
< 	os_trcget2( D_MD_OSWRITE1, D_T_SYS_END, 1, pcMsg );
< 	
< //	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0) lMsgLen == %ld\n", lMsgLen) );	
< 		
< //	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (0.1) lBufLen == %ld\n", lBufLen) );	
---
> 		if(lMsgStart != -1)
> 		{
> 			if( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') )
> 			{
> 				break;
> 			}
> 			else
> 			{
> 				lMsgStart ++;
> 			}
> 		}
> 	}
1161,1162c1190
< 															// 編集制御文字を検索
< 	lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);
---
> 	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
1164,1166c1192
< //	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
< 	
< 	if ( lMsgStart != -1)									// 見つかった場合
---
> 	if ( lMsgStart != -1) 									// 見つかった場合
1175,1176c1201,1202
< 	//	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.3) *pcMsg\n ") );
< 													
---
> 		ltemp = lMsgStart + 1; 
> 
1178a1205,1207
> 			if( (pcFmtAdr[lMsgStart] == '%') &&
> 			  ( (pcFmtAdr[lMsgStart + 1] == 's') || (pcFmtAdr[lMsgStart + 1] == 'z') ) )
> 			{
1181,1196c1210
< 			os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);
< 	
< 			ltemp = lBufEnd;								// TBCS0123
< 			
< 			lFlg = lBufEnd - lBufStart; 					// TBCS0123
< 			
< 			
< 			if(lFlg < 0)  
< 			{
< 				lBufEnd = lBufLen;
< 			}
< 														// 編集制御文字は%zの場合コード変換
< 			if ( pcFmtAdr[lMsgEnd+1] == 'z' || pcFmtAdr[lMsgStart+1] == 'z' )
< 			{
< 														// TBCS0123
< 				 os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);
---
> 				os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);
1198,1204c1212,1214
< 			}
< 			else										// TBCS0123
< 			{											// データ格納バッファから
< 														// 出力メッセージに編集
< 				os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
< 			}
< 			
---
> 														// 編集制御文字は%zの場合コード変換
> 				if( ( pcFmtAdr[lMsgStart] == '%' ) && ( pcFmtAdr[lMsgStart+1] == 'z' ) )
> 				{
1206c1216,1227
< 			lBufEnd = ltemp;
---
> 					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.4) lBufStart = %ld\n", lBufStart));
> 															// TBCS0123
> 				 	os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);
> 
> 				}
> 				else										// TBCS0123
> 				{											// データ格納バッファから
> 															// 出力メッセージに編集
> 					os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
> 				
> 					DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1.5) lBufStart = %ld\n", lBufStart));
> 				}
1208,1209c1229,1230
< 						
< 	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (3) lBufStart == %d\n", lBufStart ) ); 
---
> 					lMsgStart ++;
> 			}
1211c1232
< 	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(4) lBufEnd == %d\n", lBufEnd ) ); 
---
> 				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (3) lBufStart == %d\n", lBufStart ) ); 
1213,1215c1234,1236
< 															// メッセージフォーマット情報で
< 															// 編集制御文字をを検索
< 			os_GetStrPos(pcFmtAdr, '%', &lMsgStart, &lMsgEnd, lMsgLen);
---
> 				DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(4) lBufEnd == %d\n", lBufEnd ) ); 
> 
> 				lMsgEnd = os_SeekStr(pcFmtAdr, '%', ltemp, lMsgLen);
1217,1218c1238,1265
< 	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (5) pcFmtAdr[lMsgStart] == %c\n", 
< 	//				pcFmtAdr[lMsgStart] ) ); 
---
> 				if(lMsgEnd != -1)  
> 				{
> 				
> 					if( (pcFmtAdr[lMsgEnd + 1 ] == 'z') || (pcFmtAdr[lMsgEnd + 1] == 's') ) 
> 					{
> 					
> 						DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(5) pcFmtAdr[lMsgEnd + 1 ] == %c\n",
> 								pcFmtAdr[lMsgEnd + 1 ] ) ); 
> 					
> 															// メッセージフォーマット情報から
> 															// 出力メッセージに編集
> 						os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgEnd);
> 					
> 						lMsgStart = lMsgEnd;
> 					}
> 					
> 					ltemp = lMsgEnd + 1;
> 					
> 				}
> 				else
> 				{
> 															// メッセージフォーマット情報から
> 															// 出力メッセージに編集
> 					os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgLen);
> 				}
> 
> 			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (5) pcFmtAdr[lMsgStart] == %c\n", 
> 					pcFmtAdr[lMsgStart] ) ); 
1221c1268
< 			os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgEnd);
---
> //			os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgEnd);
1223c1270
< 	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (6) lBufStart == %ld\n", lBufStart ) );	
---
> 			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (6) lBufStart == %ld\n", lBufStart ) );	
1225,1226c1272,1273
< 	//		DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (7) pcFmtAdr[lMsgStart]  == %c\n", 
< 	//				pcFmtAdr[lMsgStart]  ) );
---
> 			DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg (7) pcFmtAdr[lMsgStart]  == %c\n", 
> 					pcFmtAdr[lMsgStart]  ) );
1228,1230c1275
< 
< 		os_EditString(pcFmtAdr, *pcMsg, lMsgStart + 1, lMsgLen);
< 
---
> 															// TBCS0172		 End
1347,1348c1392,1393
< 	
< 		*lStart = lRetForStart + 1;							// 目標の先頭位置を設定
---
> 															// TBCS0172     Start
> 			*lStart = lRetForStart + 1;						// 目標の先頭位置を設定
1351,1353c1396
< 		lRetForEnd = os_SeekStr(pcMessage, cTarget, lRetForStart + 1, lLen);
< 		
< 		*lEnd = lRetForEnd;
---
> 			lRetForEnd = os_SeekStr(pcMessage, cTarget, lRetForStart + 1, lLen);
1354a1398,1406
> 			if(lRetForEnd != -1)
> 			{
> 				*lEnd = lRetForEnd;
> 			}
> 			else
> 			{
> 				*lEnd = lLen;
> 
> 			}
1358,1360c1410
< 			*lEnd = lLen;
< 			
< 			*lStart = lLen;
---
> 			*lEnd = -1;
1362c1412
< 		
---
> 															
1367c1417
< 	*lStart = lRetForStart;
---
> 	*lEnd = lRetForStart;									// TBCS0172      End
1577c1627
< 	syslog(lRetSys, pcMsgFormat);						// syslog システムコール 
---
> 	syslog(lRetSys, "%s", pcMsgFormat);						// TBCS0172 syslog システムコール 
