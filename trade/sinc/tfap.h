/********************************************************************/ 
/*                                                                  */ 
/*                  tfap.h                                          */ 
/*                                                                  */ 
/*          TFAP ﾃｰﾌﾞﾙ ﾌｫｰﾏｯﾄ   87.12.05                            */ 
/*                       変更   94.12.20 JJ  変更者  西山  伸       */
/*                       変更   95.05.28 JK  変更者  西山  伸       */
/*                       変更   95.07.14 S1  変更者  新藤　由美		*/
/*								AP要求識別子の機能が追加されたため	*/
/*								故障処理票：ST2772					*/
/*                       変更   95.07.18 S2  変更者  新藤　由美		*/
/*								tfaprcad tfaprcszは4WonX25でしか使用*/
/*								してなかったようだが、LICPのﾘｰﾄﾞでも*/
/*								流用することとする。				*/
/*								故障処理票：ST2772					*/
/*                                                                  */
/********************************************************************/

struct mdfapsb {
    short    tfapinen;                  /* 予備                  JJ */
    char     tfapricp;                  /* 予備                  JJ */
    char     tfapyob0[5];               /* ﾖﾋﾞ 0                 JJ */
};
typedef struct mdfapsb MDFAPSB;         /* DCP ﾖｳ                   */
typedef struct mdfapsb TFAPSUB;         /* FIP ﾖｳ                   */

struct mdfapko {
	char 	tfapkbst;              	/*  ｺﾍﾞﾂﾌﾞ ｽﾃｰﾀｽ            */
	char	tfapyob1;               /*  ﾖﾋﾞ 1                   */
	short	tfapfacn;               /*  TFAC ｴﾝﾄﾘ NO            */
	short	tfaplptn;               /*  TLPT ｴﾝﾄﾘ NO            */
	char	tfapiokd;               /*  ﾀﾝﾏﾂ ｼｭﾍﾞﾂ              */
	char	tfapyob2;               /*  ﾖﾋﾞ 2                   */
	short	tfapdvno;               /*  ｿｳﾁ ﾊﾞﾝｺﾞｳ              */
	short	tfapphno;               /*  ﾛﾝﾘ ﾊﾟｽ ﾊﾞﾝｺﾞｳ          */
	char	tfapsoft;               /*  ｿﾌﾄ ｷﾊﾞﾝ                */
	char	tfapprfx;               /*  ﾌﾟﾚﾌｨｸｽ                 */
/* *** 87.12.7 *** STC550 *** */
	char	tfapfiln[22];           /*  ﾄｸｼｭ ﾌｧｲﾙ ﾒｲ            */
	long	tfapfdsc;               /*  ﾌｧｲﾙ ﾃﾞｨｽｸﾘﾌﾟﾀ          */
	char	tfapflst;               /*  ﾌｧｲﾙ ｽﾃｰﾀｽ              */
	char	tfaplpws;               /*  ｳｲﾝﾄﾞｳ ｻｲｽﾞ             */
	short   tfapaprd;				/* char	[2] -> short   JJ JK*/
									/* AP要求識別子			 S1 */
	long	tfaprcad;               /*  受信ﾃﾞｰﾀ格納域ｱﾄﾞﾚｽ  JK */
									/* S2						*/
	long	tfaprcsz;               /*  受信ﾃﾞｰﾀ格納域ｻｲｽﾞ   JK */
									/* S2						*/
	char	tfapyob4[4];            /*  ﾖﾋﾞ 4                JK */
};
typedef struct mdfapko MDFAPKO;         /* DCP ﾖｳ                   */
typedef struct mdfapko TFAPPSZ;         /* FIP ﾖｳ                   */
