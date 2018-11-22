/****************************************************************************/
/* 		構造体の定義 (ROSからの異常通知用)									*/
/****************************************************************************/
#include "mochar.h"
struct motgmsg {                        /* ROSからの異常通知				*/
	UCHR mopuid;                        /* PU番号							*/
	UCHR mocode;                        /* 中分類コード						*/
	short modetal;                      /* 詳細情報							*/
	long mofactr;                       /* 終了コード						*/
	long mozisho1;						/* 通知コード1						*/
	long mozisho2;						/* 通知コード2						*/
};
typedef struct motgmsg MOTGMSG;

/****************************************************************************/
/* 		識別種別		define												*/
/****************************************************************************/

#define		MOOBSTAC	(UCHR)0xC0		/* 障害通知							*/
#define		MOPHENOM	(UCHR)0xD0		/* 事象通知							*/

/****************************************************************************/
/* 		中分類コード	define												*/
/****************************************************************************/

/*	障害通知																*/
#define		MOOPROBS	(UCHR)0x01		/* 操作管理機能障害					*/
#define		MOPUEROR	(UCHR)0x02		/* Pu障害					CT0541	*/
#define		MOCLDEND	(UCHR)0x03		/* 子プロセス異常終了				*/
#define		MOPUBLOC	(UCHR)0x04		/* Pu閉塞							*/
#define		MOIOOBST	(UCHR)0x05		/* I/O障害通知						*/
#define		MOLINOBS	(UCHR)0x06		/* 回線障害通知						*/
#define		MONVMOBS	(UCHR)0x08		/* NVM障害							*/
#define		MOLM2OBS	(UCHR)0x09		/* LM2ビット障害					*/
#define		MOCIOINS	(UCHR)0x0A		/* コマンドによるI/O予閉塞指示		*/
#define		MOCIOCNL	(UCHR)0x0B		/* コマンドによるI/O閉塞解除		*/
										/* 完了通知							*/
#define		MOCIOCMP	(UCHR)0x0C		/* コマンドによるI/O強制閉塞		*/
										/* 完了通知							*/
#define		MOIOCNCL	(UCHR)0x0D		/* I/O閉塞解除完了通知				*/
#define		MOIOBLOC	(UCHR)0x0E		/* I/O閉塞完了通知					*/
#define		MOCLNINS	(UCHR)0x0F		/* コマンドによる回線予閉塞指示		*/
#define		MOCLNCNL	(UCHR)0x10		/* コマンドによる回線閉塞解除		*/
										/* 完了通知							*/
#define		MOCLNCMP	(UCHR)0x11		/* コマンドによる回線強制閉塞		*/
										/* 完了通知							*/
#define		MOLNCNCL	(UCHR)0x12		/* 回線閉塞解除完了通知				*/
#define		MOLNBLOC	(UCHR)0x13		/* 回線閉塞完了通知					*/
#define		MOBTRALM	(UCHR)0x14		/* バッテリーアラーム				*/
#define		MOCMDINT	(UCHR)0x15		/* コマンドモード終了割り込み		*/
#define		MOCIOECN	(UCHR)0x16		/* コマンドによるI/O閉塞完了通知	*/
#define		MOCLNECN	(UCHR)0x17		/* コマンドによる回線閉塞			*/
										/* 完了通知							*/
#define		MOFANALM	(UCHR)0x1A		/* FANアラーム発生					*/
#define		MOUPSNOR	(UCHR)0x1B		/* UPS停電状態未回復				*/
#define		MORQPOFF	(UCHR)0x1C		/* パワーオフ要求					*/
#define		MOOBTERM	(UCHR)0x1D		/* 障害通知端子受信					*/
#define		MOSTTSMP	(UCHR)0x20		/* 開始処理中のSMP通知				*/

