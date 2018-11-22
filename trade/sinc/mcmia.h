/*******************************************************/
/*                                                     */
/*                 mcmia.h                             */
/*                                                     */
/*           MIA ｷｮｳﾕｳｲｷ ﾉ ﾌｫｰﾏｯﾄ                      */
/*                                                     */
/*                                                     */
/*   修正:2003/6/23 H.TANAKA TBCS0176による修正		M01*/
/*******************************************************/

#ifndef _SMP_MCMIA_H				/*	二重定義防止定義M01	*/
struct mcmikyo {
	char       mcmimkcd[4]   ;      /*  MK ｺｰﾄﾞ              */
	short      mcmimisz      ;      /*  MIA ｻｲｽﾞ             */
	char       mcmituch      ;      /*  ﾂｳﾁ ｸﾌﾞﾝ             */
	char       mcmiinkb      ;      /*  ﾆｭｰﾘｮｸ ﾓﾄ ｸﾌﾞﾝ       */
	short      mcmiinno      ;      /*  ﾆｭｰﾘｮｸ ﾓﾄ ﾊﾞﾝｺﾞｳ     */
	char       mcmidtar      ;      /*  ﾃﾞｰﾀ ｶｸﾉｳｲｷ ｼｭﾍﾞﾂ    */
	char       mcmidtsb      ;      /*  ﾃﾞｰﾀ ｼｭﾍﾞﾂ           */
	char       *mcmidtad     ;      /*  ﾃﾞｰﾀ ｶｸﾉｳ ｱﾄﾞﾚｽ      */
	short      mcmidtsz      ;      /*  ﾃﾞｰﾀ ｶｸﾉｳ ｻｲｽﾞ       */
	char       mcmidcp[2]    ;      /*  DCP ﾚﾝﾗｸｲｷ           */
	short      mcmisnnd      ;      /*  ﾊｯｼﾝﾓﾄ ﾉｰﾄﾞ ﾊﾞﾝｺﾞｳ   */
	char       mcmisnkb      ;      /*  ﾊｯｼﾝ ｹｲ ｸﾌﾞﾝ         */
	char       mcmistbl      ;      /*  ﾌﾞﾗｹｯﾄ ｶｲｼ           */
	short      mcmirvnd      ;      /*  ｿｳｼﾝｻｷ ﾉｰﾄﾞ ﾊﾞﾝｺﾞｳ   */
	char       mcmirvkb      ;      /*  ｿｳｼﾝ ｹｲ ｸﾌﾞﾝ         */
	char       mcmiedbl      ;      /*  ﾌﾞﾗｹｯﾄ ｼｭｳﾘｭｳ        */
	char       mcmikfty      ;      /*  ｹｲｶﾝ ﾌﾘﾜｹ ﾀｲﾌﾟ       */
	char       mcmikfng      ;      /*  ｹｲｶﾝ ﾌﾘﾜｹ ｲｼﾞｮｳ      */
	char       mcmikfcd[2]   ;      /*  ｹｲｶﾝ ﾌﾘﾜｹ ｺｰﾄﾞ       */
	char       mcmisnpn[8]   ;      /*  ﾊｯｼﾝﾓﾄ ﾌﾟﾛｾｽ ｼｷﾍﾞﾂﾒｲ */
	char       mcmirvpn[8]   ;      /*  ｿｳｼﾝｻｷ ﾌﾟﾛｾｽ ｼｷﾍﾞﾂﾒｲ */
	char       mcmiattc[3]   ;      /*  ｱﾃﾝｼｮﾝ ｺｰﾄﾞ          */
	char       mcmicdcn      ;      /*  CD ﾋｮｳｼﾞ             */
	char       mcmihdki[8]   ;      /*  ﾋﾄﾞｳｷ ﾂｳﾁ ｼﾞｮｳﾎｳ     */
	short      mcmitmid      ;      /*  ﾀｲﾏ ID               */
	char       mcmidrsh      ;      /*  DR1 / DR2 ﾋﾖｳｼﾞ 2    */
	char       mcmisccd      ;      /*  SMP ｺｰﾙ ｺｰﾄﾞ         */
	char       mcmiscsb      ;      /*  ｼｮﾘ ｺｰﾄﾞ             */
	char       mcmiencd      ;      /*  ｼｮﾘ ｶﾝﾘｮｳ ｺｰﾄﾞ       */
	char       mcmiensb[2]   ;      /*  ｼｮﾘ ｶﾝﾘｮｳ ｻﾌﾞｺｰﾄﾞ    */
	short      mcmisnsq      ;      /*  ｼｰｹﾝｽ ﾊﾞﾝｺﾞｳ (ｿｳｼﾝ)  */
	short      mcmirvsq      ;      /*  ｼｰｹﾝｽ ﾊﾞﾝｺﾞｳ (ｼﾞｭｼﾝ) */
	long       mcmircno      ;      /*  RCV ﾂｳﾊﾞﾝ            */
	long       mcmirqid      ;      /*  ﾘｸｴｽﾄ ｼｷﾍﾞﾂｼ         */
	long       mcmirqrl      ;      /*  ﾍﾝｷｬｸﾁ               */
	long       mcmisens      ;      /*  ｾﾝｽ ｺｰﾄﾞ             */
};
typedef struct mcmikyo MCMIKYO;
#define _SMP_MCMIA_H				/*					M01	*/
#endif								/*					M01 */
