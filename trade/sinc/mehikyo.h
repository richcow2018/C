/**********************************************************************/
/*                                                                    */
/*      HCP Ö³·­³ Ì«°Ï¯Ä(·®³Â³ÌÞ)    mdhikyo.h        (61.12.  )      */
/*                                                                    */
/**********************************************************************/

struct mdhikyo {
	char	mdhimkcd[4] ;              /* MKº°ÄÞ                  */
	long	mdhiapar    ;              /* AP¼Ö³²·                 */
	long	mdhismid    ;              /* Ê¯¼ÝÓÄ MB ID            */
	long	mdhirmid    ;              /* ¿³¼ÝÓÄ MB ID            */
	char	mdhirest    ;              /* ¼®Ø¹¯¶ Â³Á Ó°ÄÞ         */
	char	mdhilpkb    ;              /* ÌÞÂØ ÛÝØ ¸ÌÞÝ         * */
	short	mdhilnno    ;              /* ¶²¾Ý ÊÞÝºÞ³           * */
	long	mdhiokid    ;              /* ¾²¼Þ®³ Â³Á »· MB ID     */
	long	mdhingid    ;              /* ²¼Þ®³  Â³Á »· MB ID     */
	short	mdhiwsno    ;              /* Ü°¸½Ã°¼®Ý NO.           */
	char	mdhipuno    ;              /* PU NO.                  */
	char	mdhiluno    ;              /* LU NO.                  */
};
typedef struct mdhikyo MDHIKYO;

/**********************************************************************/
/*   ¼ÖØ¹Â¶ Â³ÁÓ°ÄÞ                                                   */
/**********************************************************************/

#define   RESMOK   0x00                    /* ¾²¼ÞÖ³ ²¼ÞÖ³ ½ÍÞÃ Â³Á   */
#define   RESMNG   0x01                    /* ²¼ÞÖ³ ÀÞ¹ Â³Á           */

/**********************************************************************/
/*   ÌÞÂØ ÛÝØ ¸ÌÞÝ                                                    */
/**********************************************************************/

#define   PLKPAS   0x00                    /* ÛÝØ À²µ³                */
#define   PLKLIN   0x01                    /* ÌÞÂØ À²µ³               */
