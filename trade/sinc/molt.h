struct motblst{
	char 	motst1;
	char	motst2;
	};
typedef struct motblst MOTBLST;

#define	MOTBOK		0
#define	MOTBNG	   -1

struct motbplst{
	char	mopmtdr1[32];				/*正ﾌｧｲﾙﾏｳﾝﾄﾃﾞｲﾚｸﾄﾘ名ﾎﾟｲﾝﾀ*/
	char	moplvol1[32];				/*正ﾌｧｲﾙ論理vol名ﾎﾟｲﾝﾀ*/
	char	moppass1[32];				/*正ﾌｧｲﾙﾌﾙﾊﾟｽ名ﾎﾟｲﾝﾀ*/
	char	mopmtdr2[32];				/*副ﾌｧｲﾙﾏｳﾝﾄﾃﾞｲﾚｸﾄﾘ名ﾎﾟｲﾝﾀ*/
	char	moplvol2[32];				/*副ﾌｧｲﾙ論理vol名ﾎﾟｲﾝﾀ*/
	char	moppass2[32];				/*副ﾌｧｲﾙﾌﾙﾊﾟｽ名ﾎﾟｲﾝﾀ*/
	};
typedef struct motbplst MOTBPLST;

#define MOLNML		0				/*正常に退避を終了した*/
#define MOLSERT2	1				/*副のファイルのみエラー*/
#define MOLSERT1	2				/*正のファイルのみエラー*/
#define MOLWAFT	  100				/*退避後の後始末にてエラー*/
#define	MOLNRCV	   -1				/*リカバリ要システムである*/
#define MOLMDSYS   -2				/*一般モード、一般ファイル操作モード
									  でない*/
#define	MOLBFER	   -3				/*バッファ獲得エラー*/
#define MOLERLMT   -4				/*TLMTでエラー(TLMTなし、内容不正*/
#define MOLLMTBE   -5				/*LMテーブルにエラー*/
#define MOLOTHRE   -6				/*その他のエラー*/
#define MOLERGSZ   -7				/*mt_zgszにてエラー*/
#define MOLWERMC  -10				/*両ﾌｧｲﾙ共、ﾏｳﾝﾄ･ｺﾈｸﾄでエラー*/
#define MOLWERVR  -11				/*両ﾌｧｲﾙ共、ベクタ展開でエラー*/
#define MOLWERT12 -100				/*両ﾌｧｲﾙ共、退避中にエラー*/


