/*********************************************************************/
/*	TKMT ���͎ގ� �̎� �� �������ގ�����											 */
/*********************************************************************/
struct	tkmtpsz	{
	short	tkmtofst;					/* ��- �� �ڎ�-�Ď� �Ŏ� ���̎���		 */
	char	tkmtattr;					/* ��- ���ގ�����					 */
										/*   'C' : �ӎ��� ��������			 */
										/*   'S' : 2�ʎގ��Ď� �̎��ގ��� ������ */
										/*   'U' : 2�ʎގ��Ď� �̎��ގ��Ŏ� ������ */
										/*   'L' : 4�ʎގ��Ď� �̎��ގ��� ������ */
										/*   'V' : 4�ʎގ��Ď� �̎��ގ��Ŏ� ������ */
										/*   'P' : �ʎߎ��� ��������		 */
	char	tkmtoth1;					/* �֎ˎ�						 */
	short	tkmtleng;					/* ��- ���֎�					 */
	short	tkmtoth2;					/* �֎ˎ�						 */
};
typedef	struct	tkmtpsz	TKMTPSZ;

/*********************************************************************/
/*	�Î��̎ގَŎ� �����Ď� �Î�����												 */
/*********************************************************************/
#define	TKMTCTYPE	'C'					/*   'C' : �ӎ��� ��������			 */
#define	TKMTSTYPE	'S'					/*   'S' : 2�ʎގ��Ď� �̎��ގ��� ������ */
#define	TKMTUTYPE	'U'					/*   'U' : 2�ʎގ��Ď� �̎��ގ��Ŏ� ������ */
#define	TKMTLTYPE	'L'					/*   'L' : 4�ʎގ��Ď� �̎��ގ��� ������ */
#define	TKMTVTYPE	'V'					/*   'V' : 4�ʎގ��Ď� �̎��ގ��Ŏ� ������ */
#define	TKMTPTYPE	'P'					/*   'P' : �ʎߎ��� �������� 		 */
