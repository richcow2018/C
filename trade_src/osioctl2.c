/****************************************************************************/
/* ���⥷���ƥ�  �����ƥॳ����                                             */
/* ��ǽ��TCP/IP���ͥ����������桦�ƻ�ʴ�λ����                           */
/* ��������2002ǯ11��26��                                                   */
/* �ѹ�����2002ǯ11��26��                                                   */
/* �����ԡ�����                                                             */
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
#include "osioctl2_ins.h"               // ���������ѡʸ��̡�

/****************************************************************************/
/* ��ǽ��TCP/IP���ͥ����������桦�ƻ�ʴ�λ����                           */
/* ��������2002ǯ11��27��                                                   */
/* �ѹ�����2002ǯ11��27��                                                   */
/* �����ԡ�����                                                             */
/* �ƽз�����                                                               */
/*   long osioctl2( long fildes, long request, char *arg, long argsiz )     */
/*     long fildes            �ե�����ǥ�������ץ�                        */
/*     long request           �������                                      */
/*                                (1) ATTACH        ��0x006CF100            */
/*                                (2) BIND          ��0x006C7102            */
/*                                (3) LISTEN        ��0x006C7103            */
/*                                (4) NETCTL        ��0x006CF150            */
/*     char *arg              ����������Ȱ�ؤΥݥ���                  */
/*     long argsiz            ����������Ȱ�Υ�����                      */
/*                                                                          */
/****************************************************************************/
long osioctl2( long fildes, long request, char *arg, long argsiz )
{
/****************************************************************************/
/* �������                                                                 */
/****************************************************************************/
    struct sockaddr_in tSockAddr_In;    // sockaddr_in��¤��
	/*****	�����ѹ���SSLA0012��Start				��������2003.02.25	*****/
    int iOpt;							// setsockopt�ǻ��ꤹ�륪�ץ����
	/*****	�����ѹ���SSLA0012�� End				��������2003.02.25	*****/
    int iRet;                           // �ֵ���
    long lRet;                          // �ֵ���
    int iLoopCnt;                       // �롼�ץ�����
    TEcncTableInd *ptEcncIndAdr;        // ���ͥ����������ơ��֥�������Υ��ɥ쥹
    TArgAttach *ptArgAttach;            // ����������ȡ�ATTACH��
    TArgBind *ptArgBind;                // ����������ȡ�BIND��
    TArgListen *ptArgListen;            // ����������ȡ�LISTEN��

	os_trcget2( D_MD_OSIOCTL2, D_T_TRA_IN, 4, fildes, request, arg, argsiz );
	
   	DbgMsg01( DLv02, ( OutPut, "***** %s: Start Function\n", D_PROC_NAME ) );

    if( ptEcnc == NULL )                // ���ͥ����������ơ��֥뤬̤�����λ�
    {
    	DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 01: 0x%08x\n",
    														D_PROC_NAME, OSFEFILDES ) );
		os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, OSFEFILDES );
        return( OSFEFILDES );           // OSFEFILDES���ֵ�
    }

/****************************************************************************/
/* �ܽ���                                                                   */
/****************************************************************************/
    switch( request )                   // ������̤ˤ������ο���ʬ��
    {
        case D_TASSO_ATTACH:            // ������̤�ATTACH�λ�
            if( argsiz != sizeof(TArgAttach) )
            {                           // ����������ȥ������������λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 02: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARG���ֵ�
            }
            ptArgAttach = (TArgAttach *)arg;
            for( iLoopCnt = 0; iLoopCnt < ptEcnc->lMaxIndNum; iLoopCnt++ )
            {
                ptEcncIndAdr = (TEcncTableInd *)(ptEcnc + 1) + iLoopCnt;
                                        // ���ͥ����������ơ��֥���оݸ������μ���
                if( ptEcncIndAdr->lSockDes == 0 )
                {                       // �����åȥǥ�������ץ���0�λ�
                    break;              // ������ȴ����
                }
            }
            if( iLoopCnt == ptEcnc->lMaxIndNum )
            {                           // �оݤȤʤ�����������Ĥ���ʤ��ä���
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 03: 0x%08x\n",
    														D_PROC_NAME, D_ERR_NOBUF ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_NOBUF );
                return( D_ERR_NOBUF );  // D_ERR_NOBUF���ֵ�
            }

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_SOCKET, 3, PF_INET, SOCK_STREAM, 0 );
            iRet = socket( PF_INET, SOCK_STREAM, 0 );
                                        // �����åȤ�����
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
                                        // D_ERR_LOGIC���ֵ�
                        break;
                    case ENFILE:
                    case EMFILE:
                    case ENOBUFS:
                    case ENOMEM:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 05: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_NOBUF, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_NOBUF );
                        return( D_ERR_NOBUF );
                                        // D_ERR_NOBUF���ֵ�
                        break;
                    case EACCES:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 06: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, OSFEACC, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, OSFEACC );
                        return( OSFEACC );
                                        // OSFEACC���ֵ�
                        break;
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 07: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "socket", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1�ʥ��ܡ��ȡˤ��ֵ�
                }
            }

                                        // �����åȥǥ�������ץ�������
			ptEcncIndAdr->lSockDes = iRet;
                                        // �оݸ������Υ���ǥå���������
			ptArgAttach->sLocalSession = iLoopCnt + 1 ;

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->lSockDes=%ld )\n",
														D_PROC_NAME, ptEcncIndAdr->lSockDes ) );
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptArgAttach->sLocalSession=%hd )\n",
													D_PROC_NAME, ptArgAttach->sLocalSession ) );

			/*****	�����ѹ���SSLA0012��Start		��������2003.02.25	*****/
			/****************************************************************/
			/*  TCP/IP�����륢�ɥ쥹�ƻ��ѵ��Ĥ�����						*/
			/****************************************************************/
			iOpt = 1;					// ���ץ���������

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_SETSOCKOPT, 5, ptEcncIndAdr->lSockDes, 
											SOL_SOCKET, SO_REUSEADDR, &iOpt, sizeof(iOpt) );

													// �����åȥ��ץ���������
			iRet = setsockopt( ptEcncIndAdr->lSockDes, SOL_SOCKET, SO_REUSEADDR,
																 &iOpt, sizeof(iOpt) );

			DbgMsg01( DLv04, ( OutPut, "***** %s: Display (setsockopt iRet=%ld )\n",
															D_PROC_NAME, iRet ) );

			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_END, 1, iRet );

			if( iRet == D_ERR_SYS )					// �۾�λ�
			{
				switch( errno )						// ���顼�ֹ�ˤ������ο�ʬ��
				{
					case EBADF:
					case ENOTSOCK:
					case ENOPROTOOPT:
					case EFAULT:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 28: 0x%08x (%s: %s)\n",
								D_PROC_NAME, D_ERR_LOGIC, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, errno );
                        return( D_ERR_LOGIC );		// D_ERR_LOGIC���ֵ�
						break;

					default:
						DbgMsg01(DLv05,(OutPut, "***** %s: Err Function 29: 0x%08x (%s: %s)\n",
								D_PROC_NAME, -1, "setsockopt", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, errno );
						lRet = -1;					// -1�ʥ��ܡ��ȡˤ�����
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( lRet );				// -1���ֵ�
						break;
				}
			}
			/*****	�����ѹ���SSLA0012�� End		��������2003.02.25	*****/

            lRet = NORMAL;              // �ֵ��ͤȤ���NORMAL�����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_BIND:              // ������̤�BIND�λ�
            if( argsiz != sizeof(TArgBind) )
            {                           // ����������ȥ������������λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 08: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARG���ֵ�
            }
            ptArgBind = (TArgBind *)arg;
            if( ptArgBind->sLocalSession < D_LOCALSESSNO_MIN
                || ptArgBind->sLocalSession > ptEcnc->lMaxIndNum )
            {                           // �����륻������ֹ椬�ϰϳ��λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 09: 0x%08x\n",
    														D_PROC_NAME, D_ERR_LOGIC ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                return( D_ERR_LOGIC );  // D_ERR_LOGIC���ֵ�
            }
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgBind->sLocalSession - 1);
                                        // ���ͥ����������ơ��֥���оݸ������μ���
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
                                        // �����åȤ���Ͽ
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
                                        // D_ERR_LOGIC���ֵ�
                        break;
                    case EINVAL:
                    case EADDRINUSE:	// 20030307 KL0025 �ɲ�
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 11: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, D_ERR_USEDADDR, "bind", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_USEDADDR );
                        return( D_ERR_USEDADDR );
                                        // D_ERR_USEDADDR���ֵ�
                        break;
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 12: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "bind", strerror(errno) ) );
						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1�ʥ��ܡ��ȡˤ��ֵ�
                }
            }
            lRet = NORMAL;              // �ֵ��ͤȤ���NORMAL�����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_LISTEN:            // ������̤�LISTEN�λ�
            if( argsiz != sizeof(TArgListen) )
            {                           // ����������ȥ������������λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 13: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARG���ֵ�
            }
            ptArgListen = (TArgListen *)arg;
            if( ptArgListen->sLocalSession < D_LOCALSESSNO_MIN
                || ptArgListen->sLocalSession > ptEcnc->lMaxIndNum )
            {                           // �����륻������ֹ椬�ϰϳ��λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 14: 0x%08x\n",
    														D_PROC_NAME, D_ERR_LOGIC ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
                return( D_ERR_LOGIC );  // D_ERR_LOGIC���ֵ�
            }
            ptEcncIndAdr = ((TEcncTableInd *)(ptEcnc + 1) + ptArgListen->sLocalSession - 1);
                                        // ���ͥ����������ơ��֥���оݸ������μ���
    		DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr=%p )\n",
															D_PROC_NAME, ptEcncIndAdr ) );
            
			os_trcget2( D_MD_OSIOCTL2, D_T_SYS_LISTEN, 2, ptEcncIndAdr->lSockDes, 
																ptArgListen->sMaxWaitResNum );
            iRet = listen( ptEcncIndAdr->lSockDes, ptArgListen->sMaxWaitResNum );
                                        // �����åȤ�����
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
                                        // D_ERR_LOGIC���ֵ�
                        break;
                        
                    default:
						DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 16: 0x%08x ( %s: %s )\n",
									D_PROC_NAME, -1, "listen", strerror(errno) ) );

						os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 2, -1 , errno );
						os_treterm(os_EndCod(D_END_TYPE1), (D_MD_OSIOCTL2 << 16) | D_T_ERR_SYS );
						//return( -1 );   // -1�ʥ��ܡ��ȡˤ��ֵ�
                }
            }
            ptEcncIndAdr->cSCFlg = D_SCINFO_SERVER;
                                        // �����Ф�����
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( ptEcncIndAdr->cSCFlg=%hhd )\n",
															D_PROC_NAME, ptEcncIndAdr->cSCFlg ) );
            lRet = NORMAL;              // �ֵ��ͤȤ���NORMAL�����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        case D_TASSO_NETCTL:            // ������̤�NETCTL�λ�
            if( argsiz < D_ARG_NETCTL_MIN )
            {                           // ����������ȥ������������λ�
    			DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 17: 0x%08x\n",
    														D_PROC_NAME, D_ERR_ARG ) );
				os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_ARG );
                return( D_ERR_ARG );    // D_ERR_ARG���ֵ�
            }
            lRet = NORMAL;              // �ֵ��ͤȤ���NORMAL�����ꤹ��
			DbgMsg01( DLv04, ( OutPut, "***** %s: Display ( lRet=%ld )\n",
															D_PROC_NAME, lRet ) );
            break;

        default:
    		DbgMsg01( DLv05, ( OutPut, "***** %s: Err Function 18: 0x%08x\n",
    													D_PROC_NAME, D_ERR_LOGIC ) );
			os_trcget2( D_MD_OSIOCTL2, D_T_ERR_SYS, 1, D_ERR_LOGIC );
            return( D_ERR_LOGIC );      // D_ERR_LOGIC���ֵ�
    }

	DbgMsg01( DLv02, ( OutPut, "***** %s: End Function\n", D_PROC_NAME ) );
	os_trcget2( D_MD_OSIOCTL2, D_T_TRA_OUT, 1, lRet );
    return( lRet );                     // �����ͤ��ֵ�
}
/****************************************************************************/
/* End                                                                      */
/****************************************************************************/
