37c37
< /* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼��:�أأأ�)					*/
---
> /* �㥽���������ԡ� 				 �ã»��ӥ��ͥ����ô��(�᡼���������ץ饤)					*/
43a44,45
> /* �㥽���������ԡ� 			 	 ���ץ饤����												*/
> /* �㥽������ǯ�����ڤӽ����ɣġ�	 ��������ǯ���������     �ξ�����ֹ�ʣԣ£ãӣ���������*/
49c51,55
< /*	 �أأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأأ�						*/
---
> /*		�֥ǡ�����Ǽ�Хåե��פ˳�Ǽ���줿��å���������ʸ������Ƭ�����ʸ���ˤ�KEY�Ȥ���		*/
> /*		��ͭ������Ÿ������Ƥ��륳�󥽡�������ѡ����ե���������ѡ�����ץ��������Ѥ�	*/
> /*		��å������ե����ޥåȤ�����������줾����ϥ�å������Խ���Ԥ���						*/
> /*		�Խ���λ��˽��ϥ�å������򡢡֥�å��������ϻؼ�ʸ���פ˽�����						*/
> /*		���󥽡��롿���ե����롿����Υץ������Ф��ƥ�å��������Ϥ�Ԥ���					*/
53c59
< /*		#include	<XXXXX.h>																	*/
---
> /*		#include	<oswrite1.h>																*/
58,60c64,66
< /*      long fildes                              										        */
< /*      char *buf                                        										*/
< /*      long len                                         										*/
---
> /*      long fildes        �ե����뵭�һ�                     							        */
> /*      char *buf          �ǡ�����Ǽ�Хåե���NULL�ʳ���                              			*/
> /*      long len           ����ǡ�����������0�ʾ��                              				*/
63c69,70
< /*	   0L																						*/
---
> /*		���ｪλ			0x0000XXXX															*/
> /*		�۾ｪλ			0x940dXXXX															*/
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
> 															// �Խ�����ʸ���򸡺�
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
< 															// �Խ�����ʸ���򸡺�
< 	lMsgStart  = os_SeekStr(pcFmtAdr, '%', lMsgStart, lMsgLen);
---
> 	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
1164,1166c1192
< //	DbgMsg01( DLv04, ( OutPut, "*** os_GetMsg(1) lMsgStart == %ld\n", lMsgStart ) );
< 	
< 	if ( lMsgStart != -1)									// ���Ĥ��ä����
---
> 	if ( lMsgStart != -1) 									// ���Ĥ��ä����
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
< 														// �Խ�����ʸ����%z�ξ�祳�����Ѵ�
< 			if ( pcFmtAdr[lMsgEnd+1] == 'z' || pcFmtAdr[lMsgStart+1] == 'z' )
< 			{
< 														// TBCS0123
< 				 os_ChangeCode(pcBuf, sCode, lBufStart, lBufEnd, *pcMsg);
---
> 				os_GetStrPos(pcBuf, '\t', &lBufStart, &lBufEnd, lBufLen);
1198,1204c1212,1214
< 			}
< 			else										// TBCS0123
< 			{											// �ǡ�����Ǽ�Хåե�����
< 														// ���ϥ�å��������Խ�
< 				os_EditString(pcBuf, *pcMsg, lBufStart, lBufEnd);
< 			}
< 			
---
> 														// �Խ�����ʸ����%z�ξ�祳�����Ѵ�
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
> 				{											// �ǡ�����Ǽ�Хåե�����
> 															// ���ϥ�å��������Խ�
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
< 															// ��å������ե����ޥåȾ����
< 															// �Խ�����ʸ����򸡺�
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
> 															// ��å������ե����ޥåȾ��󤫤�
> 															// ���ϥ�å��������Խ�
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
> 															// ��å������ե����ޥåȾ��󤫤�
> 															// ���ϥ�å��������Խ�
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
< 		*lStart = lRetForStart + 1;							// ��ɸ����Ƭ���֤�����
---
> 															// TBCS0172     Start
> 			*lStart = lRetForStart + 1;						// ��ɸ����Ƭ���֤�����
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
< 	syslog(lRetSys, pcMsgFormat);						// syslog �����ƥॳ���� 
---
> 	syslog(lRetSys, "%s", pcMsgFormat);						// TBCS0172 syslog �����ƥॳ���� 
