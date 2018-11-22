/**********************************************************************/
/* ファイル名：　mpcrqmsg.h 										  */
/* 機能　　  ：  要求／応答電文 									  */
/* 作成日　  ：  1993.11.22 										  */
/* 更新日　  ： 													  */
/**********************************************************************/
#include <mehikyo.h>
#include <mpcomand.h>
/**************************************/
/* 要求／応答電文テンプレート		  */
/**************************************/
typedef struct {
	MDHIKYO 	com;
	MPCOMAND	usr;
} MPCRQMSG;

/**************************************/
/* 受信／送信要求・応答テンプレート   */
/**************************************/
typedef struct {
	MDHIKYO 	com;					/* 共通部							*/
	MPCOMAND	usr;					/* コマンド領域 					*/
	struct {
		long	reserve0[4];			/* ヘッダー 						*/
	} head;
} MPCMSGRW;

/**************************************/
/* 緊急データ送信テンプレート		  */
/**************************************/
typedef struct {
	MDHIKYO 			com;			/* 共通部							*/
	MPCOMAND			usr;			/* コマンド領域 					*/
	struct {
		long	reserve0[2];			/* リザーブ 						*/
	} head;
} MPCMSGSO;
/**************************************/
/* 緊急データ受信テンプレート		  */
/**************************************/
typedef struct {
	MDHIKYO 	com;					/* 共通部							*/
	MPCOMAND	usr;					/* コマンド領域 					*/
	struct {
		short	reserve0[3];			/* リザーブ 						*/
	}	head;
	char	oob_data;					/* 緊急データ						*/
	char	reserve1;					/* リザーブ 						*/
} MPCMSGRO;

#define PBUFFMAX	0x7ffc				/* プールバッファユニット最大長 	*/

/**************************************/
/* メッセージ長 					  */
/**************************************/
#define MPCMSZRQ	sizeof(MPCRQMSG)	/* 要求電文長						*/
#define MPCMSZRW	sizeof(MPCMSGRW)	/* 電文送信要求のメッセージ長		*/
#define MPCMSZHI	PBUFFMAX			/* 送信／受信のメッセージ長（上限） */
#define MPCMSZRO	sizeof(MPCMSGRO)	/* 緊急データ受信データ 			*/
#define MPCMSZSO	sizeof(MPCMSGSO)	/* 緊急データ送信のメッセージ長 	*/

/**************************************/
/*	データ長						  */
/**************************************/
#define MPCDSZRW	PBUFFMAX - MPCMSZRQ /* 電文送信のデータ長				*/
#define MPCDSZHD	16					/* 電文送信／電文受信の最小データ長 */
#define MPCMAXSO	MPCMSZSO - MPCMSZRQ + 1024
										/* 緊急データ送信のデータ長の最大値 */
#define MPCMINSO	MPCMSZSO - MPCMSZRQ
										/* 緊急データ送信のデータ長の最小値 */
#define MPCDSZRO	8					/* 緊急データ受信のデータ長 		*/
