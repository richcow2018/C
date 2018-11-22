/****************************************************************************/
/* 信金システム  システムコール                                             */
/* 機能：TCP/IPコネクションの制御・監視（完了型）                           */
/* 作成日：2002年11月26日                                                   */
/* 変更日：2002年11月26日                                                   */
/* 作成者：江川                                                             */
/*                                                                          */
/* Copyright(C) 2002, Supply Corporation.                                   */
/* All Rights Reserved.                                                     */
/****************************************************************************/
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <linux/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "osioctl2.h"
#include "osioctl2_ins.h"               // 内部参照用（個別）

/****************************************************************************/
/* 機能：TCP/IPコネクションの制御・監視（完了型）                           */
/* 作成日：2002年11月27日                                                   */
/* 変更日：2002年11月27日                                                   */
/* 作成者：江川                                                             */
/* 呼出形式：                                                               */
/*   long osioctl2( long fildes, long request, char *arg, long argsiz )     */
/*     long fildes            ファイルディスクリプタ                        */
/*     long request           制御種別                                      */
/*                                (1) ATTACH        ：0x006CF100            */
/*                                (2) BIND          ：0x006C7102            */
/*                                (3) LISTEN        ：0x006C7103            */
/*                                (4) NETCTL        ：0x006CF150            */
/*     char *arg              アーギュメント域へのポインタ                  */
/*     long argsiz            アーギュメント域のサイズ                      */
/*                                                                          */
/****************************************************************************/
long osioctl2( long fildes, long request, char *arg, long argsiz )
{
/****************************************************************************/
/* 初期処理                                                                 */
/****************************************************************************/
    struct sockaddr_in tSockAddr_In;    // sockaddr_in構造体
	/*****	仕様変更（SSLA0012）Start				修正日：2003.02.25	*****/
    int iOpt;							// setsockoptで指定するオプション
	/*****	仕様変更（SSLA0012） End				修正日：2003.02.25	*****/
    int iRet;                           // 返却値
    long lRet;                          // 返却値
    int iLoopCnt;                       // ループカウンタ
    TEcncTableInd *ptEcncIndAdr;        // コネクション管理テーブル個別部のアドレス
    TArgAttach *ptArgAttach;            // アーギュメント（ATTACH）
    TArgBind *ptArgBind;                // アーギュメント（BIND）
    TArgListen *ptArgListen;            // アーギュメント（LISTEN）

	os_trcget2( D_MD_OSIOCTL2, D_T_TRA_IN, 4, fildes, request, arg, argsiz );
	
   	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    if( ptEcnc == NULL )                // コネクション管理テーブルが未作成の時
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, OSFEFILDES );
        return( OSFEFILDES );           // OSFEFILDESを返却
    }

/****************************************************************************/
/* 本処理                                                                   */
/****************************************************************************/
    switch( request )                   // 制御種別による処理の振り分け
    {
        case D_TASSO_ATTACH:            // 制御種別がATTACHの時
            if( argsiz != sizeof(TArgAttach) )
            {                           // アーギュメントサイズが不正の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARGを返却
            }
            ptArgAttach = (TArgAttach *)arg;
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;
                                        // コネクション管理テーブルの対象個別部の取得
                if( ptEcncIndAdr->lSockDes == 0 )
                {                       // ソケットディスクリプタが0の時
                    break;              // 処理を抜ける
                }
            }
            if( iLoopCnt == ptEcnc->lMaxIndNum )
            {                           // 対象となる個別部が見つからなかった時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, D_ERR_NOBUF ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_NOBUF );
                return( D_ERR_NOBUF );  // D_ERR_NOBUFを返却
            }

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_SOCKET, 3, PF_INET, SOCK_STREAM, 0 );
            iRet = socket( PF_INET, SOCK_STREAM, 0 );
                                        // ソケットの生成
			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_END, 1, iRet );

            if( iRet == D_ERR_SYS )
            {
                switch( errno )
                {
                    case EPROTONOSUPPORT:
                    case EAFNOSUPPORT:
                    case EINVAL:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 04: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                        return( D_ERR_LOGIC );
                                        // D_ERR_LOGICを返却
                        break;
                    case ENFILE:
                    case EMFILE:
                    case ENOBUFS:
                    case ENOMEM:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_NOBUF, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_NOBUF );
                        return( D_ERR_NOBUF );
                                        // D_ERR_NOBUFを返却
                        break;
                    case EACCES:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, OSFEACC );
                        return( OSFEACC );
                                        // OSFEACCを返却
                        break;
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1（アボート）を返却
                }
            }

                                        // ソケットディスクリプタの設定
			ptEcncIndAdr->lSockDes = iRet;
                                        // 対象個別部のインデックスを設定
			ptArgAttach->sLocalSession = iLoopCnt + 1 ;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->lSockDes=%ld )\n",
														D_PROC_NAME, ptEcncIndAdr->lSockDes ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAttach->sLocalSession=%hd )\n",
													D_PROC_NAME, ptArgAttach->sLocalSession ) );

			/*****	仕様変更（SSLA0012）Start		修正日：2003.02.25	*****/
			/****************************************************************/
			/*  TCP/IPローカルアドレス再使用許可の設定						*/
			/****************************************************************/
			iOpt = 1;					// オプションを設定

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
											SOL_SOCKET, SO_REUSEADDR, &iOpt, sizeof(iOpt) );

													// ソケットオプションの設定
			iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_REUSEADDR,
																 &iOpt, sizeof(iOpt) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display (setsockopt iRet=%ld )\n",
															D_PROC_NAME, iRet ) );

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// 異常の時
			{
				switch( errno )						// エラー番号による処理の振分け
				{
					case EBADF:
					case ENOTSOCK:
					case ENOPROTOOPT:
					case EFAULT:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
								D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, errno );
                        return( D_ERR_LOGIC );		// D_ERR_LOGICを返却
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
								D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, errno );
						lRet = -1;					// -1（アボート）を設定
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( lRet );				// -1を返却
						break;
				}
			}
			/*****	仕様変更（SSLA0012） End		修正日：2003.02.25	*****/

            lRet = NORMAL;              // 返却値としてNORMALを設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_BIND:              // 制御種別がBINDの時
            if( argsiz != sizeof(TArgBind) )
            {                           // アーギュメントサイズが不正の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARGを返却
            }
            ptArgBind = (TArgBind *)arg;
            if( ptArgBind->sLocalSession < D_LOCALSESSNO_MIN
                || ptArgBind->sLocalSession > ptEcnc->lMaxIndNum )
            {                           // ローカルセション番号が範囲外の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    														D_PROC_NAME, D_ERR_LOGIC ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                return( D_ERR_LOGIC );  // D_ERR_LOGICを返却
            }
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgBind->sLocalSession - 1);
                                        // コネクション管理テーブルの対象個別部の取得
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
															D_PROC_NAME, ptEcncIndAdr ) );
            tSockAddr_In.sin_family = PF_INET;
            tSockAddr_In.sin_port = htons(ptArgBind->sLocalPortNo);
            tSockAddr_In.sin_addr.s_addr = htonl(ptArgBind->lLocalAddr);

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->lSockDes=%ld )\n",
														D_PROC_NAME, ptEcncIndAdr->lSockDes ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgBind->sLocalSession=%hd )\n",
													D_PROC_NAME, ptArgBind->sLocalSession ) );

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_BIND, 3, ptEcncIndAdr->lSockDes, 
								(struct sockaddr *)&tSockAddr_In, sizeof(tSockAddr_In) );
            iRet = bind( ptEcncIndAdr->lSockDes, (struct sockaddr *)&tSockAddr_In,
                                                                    sizeof(tSockAddr_In) );
                                        // ソケットの登録
			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_END, 2, iRet, errno );
            
            if( iRet == D_ERR_SYS )
            {
                switch( errno )
                {
                    case EBADF:
                    case EACCES:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 10: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "bind", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                        return( D_ERR_LOGIC );
                                        // D_ERR_LOGICを返却
                        break;
                    case EINVAL:
                    case EADDRINUSE:	// 20030307 KL0025 追加
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_USEDADDR, "bind", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_USEDADDR );
                        return( D_ERR_USEDADDR );
                                        // D_ERR_USEDADDRを返却
                        break;
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "bind", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1（アボート）を返却
                }
            }
            lRet = NORMAL;              // 返却値としてNORMALを設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_LISTEN:            // 制御種別がLISTENの時
            if( argsiz != sizeof(TArgListen) )
            {                           // アーギュメントサイズが不正の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARGを返却
            }
            ptArgListen = (TArgListen *)arg;
            if( ptArgListen->sLocalSession < D_LOCALSESSNO_MIN
                || ptArgListen->sLocalSession > ptEcnc->lMaxIndNum )
            {                           // ローカルセション番号が範囲外の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    														D_PROC_NAME, D_ERR_LOGIC ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                return( D_ERR_LOGIC );  // D_ERR_LOGICを返却
            }
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgListen->sLocalSession - 1);
                                        // コネクション管理テーブルの対象個別部の取得
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
															D_PROC_NAME, ptEcncIndAdr ) );
            
			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_LISTEN, 2, ptEcncIndAdr->lSockDes, 
																ptArgListen->sMaxWaitResNum );
            iRet = listen( ptEcncIndAdr->lSockDes, ptArgListen->sMaxWaitResNum );
                                        // ソケットの設定
			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_END, 1, iRet );
                                        
            if( iRet == D_ERR_SYS )
            {
                switch( errno )
                {
                    case EADDRINUSE:
                    case EBADF:
                    case ENOTSOCK:
                    case EOPNOTSUPP:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 15: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_LOGIC, "listen", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                        return( D_ERR_LOGIC );
                                        // D_ERR_LOGICを返却
                        break;
                        
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "listen", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1（アボート）を返却
                }
            }
            ptEcncIndAdr->cSCFlg = D_SCINFO_SERVER;
                                        // サーバを設定
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
															D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );
            lRet = NORMAL;              // 返却値としてNORMALを設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_NETCTL:            // 制御種別がNETCTLの時
            if( argsiz < D_ARG_NETCTL_MIN )
            {                           // アーギュメントサイズが不正の時
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 17: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARGを返却
            }
            lRet = NORMAL;              // 返却値としてNORMALを設定する
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        default:
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 18: 0x%08x\n",
    													D_PROC_NAME, D_ERR_LOGIC ) );
			os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
            return( D_ERR_LOGIC );      // D_ERR_LOGICを返却
    }

	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSIOCTL2, D_T_TRA_OUT, 1, lRet );
    return( lRet );                     // 正常値を返却
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
