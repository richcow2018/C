/****************************************************************************/
/*【動的ｼｽﾃﾑ構成変更】														*/
/* 作成日・社(者): 1994.12.20 by FUJITSU(K.Kubota)							*/
/* Update history:															*/
/*		95.05.30 K.Kubota ST2637: Process cooperation fail					*/
/*	95.09.13 K.Kubota SSCY0061: 全撤去モード対応							*/
/*	95.10.09 K.Kubota SSCY0118: 対OSP排他区間制御対応						*/
/*	95.11.08 K.Kubota ST3715=AT1844: define TIMER IR-code					*/
/****************************************************************************/

										/* ###ST2637 Start					*/
/****************************************************************************/
/*	排他区間制御ﾌﾞﾛｯｸ														*/
/*	  ﾌﾟﾛｾｽごとの排他区間設定状態を管理する									*/
/*	  排他区間設定要求時に相手ﾌﾟﾛｾｽ単位に確保する							*/
/*	  排他区間解除完了時に解放する											*/
/****************************************************************************/
#define	MAXXBLK			32				/* FNAは数個であろう				*/
										/* ｿﾞﾝﾋﾞﾌﾞﾛｯｸを含めてもこんなもの	*/
typedef	struct{
	long				DType;			/* 格納種別							*/
										/*	1: FTAM							*/
										/*	2: FNA							*/
										/*	3: ICP							*/
										/*	4: OSP ###SSCY0118				*/
										/*	0: 格納なし						*/
	char				SetSt;			/* 排他区間設定状態					*/
										/*	0: 当該ﾌﾞﾛｯｸ未使用				*/
										/*	1: 設定要求中					*/
										/*	2: 設定済み						*/
										/*	3: ﾀｲﾑｱｳﾄ						*/
	char				ResSt;			/* 排他区間解除状態					*/
										/*	0: 解除要求未					*/
										/*	1: 解除要求中					*/
										/*	3: ﾀｲﾑｱｳﾄ						*/
	char				Rsv[2];
	long				SetRq;			/* 排他区間設定時要求識別子			*/
	long				ResRq;			/* 排他区間解除時要求識別子			*/
	char				*pMsg;			/* ﾒｯｾｰｼﾞ保持域						*/
	TPCTPSZ				*pPCT;			/* TPCTPSZ for destination process	*/ 
}						XBLK;

/****************************************************************************/
/*	ﾃｰﾌﾞﾙ更新ﾌﾟﾛｾｽ[mmd]実行管理ﾃｰﾌﾞﾙ										*/
/*	 (寿命:	mmd生存期間中)													*/
/****************************************************************************/
typedef	struct{
	long				PszNum;			/* 有効個別部数						*/
	long				Status;			/* ﾌﾟﾛｾｽ状態ｺｰﾄﾞ					*/
										/*	1: ｱｲﾄﾞﾙ						*/
										/*	2: 排他区間設定中				*/
										/*	3: 他LM更新中					*/
										/*	4: 排他区間解除中				*/
										/* (CPU0ﾌﾟﾛｾｽのみ有効)				*/
										/* (ﾌﾟﾛｾｽ初期設定でｱｲﾄﾞﾙにする)		*/
	long				PU1Rq;			/* 他LM更新依頼要求識別子			*/
	long				TimRq;			/* ﾀｲﾏ要求識別子					*/
	long				TimID;			/* ﾀｲﾏID							*/
	long				RqCnt;			/* 要求識別子採番ｶｳﾝﾀ				*/
										/* (ﾌﾟﾛｾｽ開始時に現在時刻を設定)	*/
	long				RqNum;			/* 応答未受信電文ｶｳﾝﾀ				*/
										/* (要求数 − 応答数)				*/
	long				TblSt;			/* ﾃｰﾌﾞﾙ更新状態					*/
										/*	0 :	未更新						*/
										/*	1 :	更新済						*/
	char				*pTMsg;			/* ﾃｰﾌﾞﾙ更新依頼通知ﾎﾟｲﾝﾀ			*/
										/* ###SSCY0061 start				*/
	char				Node;			/* 系区分							*/
										/*  0x01...現用系					*/
										/*  0x02...予備系					*/
	char				Mode;			/* 処理ﾓｰﾄﾞ							*/
										/*  0x00...通常ﾓｰﾄﾞ					*/
										/*  0x01...全撤去ﾓｰﾄﾞ				*/
										/* ###SSCY0061 end					*/
										/* ###SSCY0118 start				*/
	char				rsv[30];
										/* ###SSCY0118 end					*/
	XBLK				XBs[MAXXBLK	+ 1];
										/* 排他区間制御ﾌﾞﾛｯｸ域				*/
										/* (最後の１ﾌﾞﾛｯｸはｽﾄｯﾊﾟｰ)			*/
}						MMDMNG;

/********************************/
/* IRB固定部 20B				*/
/********************************/
typedef struct
{
	long				dmy1[3];		/*									*/
	unsigned char		ircode;			/* IRｺｰﾄﾞ							*/
										/* ###SSCY0118 start				*/
#define MMIRSCD			0x01			/* SCD内部ｲﾍﾞﾝﾄ.ﾀｲﾏ	###ST3715		*/
#define MMIRAP			0x02			/* APﾌﾟﾛｾｽから						*/
#define MMIRSMP			0x03			/* SMPﾌﾟﾛｾｽから						*/
										/* ###SSCY0118 end					*/
	unsigned char		subcode;		/* ｻﾌﾞIRｺｰﾄﾞ						*/
										/* ###SSCY0118 start				*/
#define MMISUPDRQ		0x01			/* ﾃｰﾌﾞﾙ更新要求					*/
#define MMISUPDRS		0x02			/* ﾃｰﾌﾞﾙ更新応答					*/
#define MMISFNA11		0x11			/* FNA排他区間設定許可応答			*/
#define MMISFNA12		0x12			/* FNA排他区間設定否定応答			*/
#define MMISFNA21		0x13			/* FNA排他区間解除応答				*/
#define MMISFTM11		0x21			/* FTAM排他区間設定許可応答			*/
#define MMISFTM12		0x22			/* FTAM排他区間設定否定応答			*/
#define MMISFTM21		0x23			/* FTAM排他区間解除応答				*/
#define MMISICP11		0x31			/* ICP排他区間設定許可応答			*/
#define MMISICP12		0x32			/* ICP排他区間設定否定応答			*/
#define MMISICP21		0x33			/* ICP排他区間解除応答				*/
#define MMISOSP11		0x41			/* OSP排他区間設定許可応答			*/
#define MMISOSP12		0x42			/* OSP排他区間設定否定応答			*/
#define MMISOSP21		0x43			/* OSP排他区間解除応答				*/
										/* ###ST3715 start					*/
#define	SetTim			0x71			/* 排他区間設定ﾀｲﾏ					*/
#define	LMUpdateTim		0x72			/* 他LMﾃｰﾌﾞﾙ更新ﾀｲﾏ					*/
#define	UnSetTim		0x73			/* 排他区間解除ﾀｲﾏ					*/
										/* ###ST3715 end					*/
										/* ###SSCY0118 end					*/
	short				dmy2;			/*									*/
	long				dmy3;			/*									*/
}						IRBSET;

/****************************************************************************/
/* 外部電文受信IRB [64B]													*/
/****************************************************************************/
typedef	struct
{
	IRBSET				irb;			/* IRB固定部相当					*/
	short				info1;			/* 情報1							*/
	short				info2;			/* 情報2							*/
	long				info3;			/* 情報3							*/
	long				info4;			/* 情報4							*/
	long				*adrs1;			/* ｱﾄﾞﾚｽ1 [MIA/CIA電文域]			*/
	long				*adrs2;			/* ｱﾄﾞﾚｽ2							*/
	long				*adrs3;			/* ｱﾄﾞﾚｽ3							*/
	long				dmy[5];			/* Varriable Area					*/
} 						DYRECIRB;

/********************************/
/* ﾀｲﾑｱｳﾄ通知IRB				*/
/********************************/
typedef struct
{
	IRBSET				irb;			/* IRB固定部						*/
	long				dmy2;			/*									*/
	long				d[10];			/* d1 〜 d10領域					*/
										/* (d1領域に要求識別子を設定する)	*/
}						TIMEIRB;

/********************************/
/*	電文解放ﾏｸﾛ					*/
/********************************/
#define MMD_FRBF(pMsg)\
	mo_frbf((long)pMsg);

/********************************/
/*	IRB解放ﾏｸﾛ					*/
/********************************/
#define MMD_Z300(pIRB)\
	mcs_z300((MCSIRB*)pIRB);
										/* ###ST2637 End					*/
