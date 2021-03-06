/*******************************************************/
/*                                                     */
/*                 mcmia.h                             */
/*                                                     */
/*           MIA ·®³Õ³²· É Ì«°Ï¯Ä                      */
/*                                                     */
/*                                                     */
/*   ½¤Àµ:2003/6/23 H.TANAKA TBCS0176¤Ë¤è¤ë½¤Àµ		M01*/
/*******************************************************/

#ifndef _SMP_MCMIA_H				/*	Æó½ÅÄêµÁËÉ»ßÄêµÁM01	*/
struct mcmikyo {
	char       mcmimkcd[4]   ;      /*  MK º°ÄÞ              */
	short      mcmimisz      ;      /*  MIA »²½Þ             */
	char       mcmituch      ;      /*  Â³Á ¸ÌÞÝ             */
	char       mcmiinkb      ;      /*  Æ­°Ø®¸ ÓÄ ¸ÌÞÝ       */
	short      mcmiinno      ;      /*  Æ­°Ø®¸ ÓÄ ÊÞÝºÞ³     */
	char       mcmidtar      ;      /*  ÃÞ°À ¶¸É³²· ¼­ÍÞÂ    */
	char       mcmidtsb      ;      /*  ÃÞ°À ¼­ÍÞÂ           */
	char       *mcmidtad     ;      /*  ÃÞ°À ¶¸É³ ±ÄÞÚ½      */
	short      mcmidtsz      ;      /*  ÃÞ°À ¶¸É³ »²½Þ       */
	char       mcmidcp[2]    ;      /*  DCP ÚÝ×¸²·           */
	short      mcmisnnd      ;      /*  Ê¯¼ÝÓÄ É°ÄÞ ÊÞÝºÞ³   */
	char       mcmisnkb      ;      /*  Ê¯¼Ý ¹² ¸ÌÞÝ         */
	char       mcmistbl      ;      /*  ÌÞ×¹¯Ä ¶²¼           */
	short      mcmirvnd      ;      /*  ¿³¼Ý»· É°ÄÞ ÊÞÝºÞ³   */
	char       mcmirvkb      ;      /*  ¿³¼Ý ¹² ¸ÌÞÝ         */
	char       mcmiedbl      ;      /*  ÌÞ×¹¯Ä ¼­³Ø­³        */
	char       mcmikfty      ;      /*  ¹²¶Ý ÌØÜ¹ À²Ìß       */
	char       mcmikfng      ;      /*  ¹²¶Ý ÌØÜ¹ ²¼Þ®³      */
	char       mcmikfcd[2]   ;      /*  ¹²¶Ý ÌØÜ¹ º°ÄÞ       */
	char       mcmisnpn[8]   ;      /*  Ê¯¼ÝÓÄ ÌßÛ¾½ ¼·ÍÞÂÒ² */
	char       mcmirvpn[8]   ;      /*  ¿³¼Ý»· ÌßÛ¾½ ¼·ÍÞÂÒ² */
	char       mcmiattc[3]   ;      /*  ±ÃÝ¼®Ý º°ÄÞ          */
	char       mcmicdcn      ;      /*  CD Ë®³¼Þ             */
	char       mcmihdki[8]   ;      /*  ËÄÞ³· Â³Á ¼Þ®³Î³     */
	short      mcmitmid      ;      /*  À²Ï ID               */
	char       mcmidrsh      ;      /*  DR1 / DR2 ËÖ³¼Þ 2    */
	char       mcmisccd      ;      /*  SMP º°Ù º°ÄÞ         */
	char       mcmiscsb      ;      /*  ¼®Ø º°ÄÞ             */
	char       mcmiencd      ;      /*  ¼®Ø ¶ÝØ®³ º°ÄÞ       */
	char       mcmiensb[2]   ;      /*  ¼®Ø ¶ÝØ®³ »ÌÞº°ÄÞ    */
	short      mcmisnsq      ;      /*  ¼°¹Ý½ ÊÞÝºÞ³ (¿³¼Ý)  */
	short      mcmirvsq      ;      /*  ¼°¹Ý½ ÊÞÝºÞ³ (¼Þ­¼Ý) */
	long       mcmircno      ;      /*  RCV Â³ÊÞÝ            */
	long       mcmirqid      ;      /*  Ø¸´½Ä ¼·ÍÞÂ¼         */
	long       mcmirqrl      ;      /*  ÍÝ·¬¸Á               */
	long       mcmisens      ;      /*  ¾Ý½ º°ÄÞ             */
};
typedef struct mcmikyo MCMIKYO;
#define _SMP_MCMIA_H				/*					M01	*/
#endif								/*					M01 */
