/************************************************************************/
/* header file for nodekan												*/
/************************************************************************/
typedef struct senms2msg
{
	char	mkcd[4];			// MKコード
	long	pmid;				// 送信先プロセス識別子またはメールボックス識別子
	long	pid;				// 自プロセスID
	long	number;				// 通番
	long	retcode;			// 完了コード
	long	msglen;				// メッセージ長
} SENMS2MSG;

