/*******************************************************/
/*                                                     */
/*                 mcmia.h                             */
/*                                                     */
/*           MIA �������Վ����� �� �̎����ώ���                      */
/*                                                     */
/*                                                     */
/*   ����:2003/6/23 H.TANAKA TBCS0176�ˤ�뽤��		M01*/
/*******************************************************/

#ifndef _SMP_MCMIA_H				/*	�������ɻ����M01	*/
struct mcmikyo {
	char       mcmimkcd[4]   ;      /*  MK �����Ď�              */
	short      mcmimisz      ;      /*  MIA ��������             */
	char       mcmituch      ;      /*  ���� ���̎ގ�             */
	char       mcmiinkb      ;      /*  �Ǝ����؎��� �ӎ� ���̎ގ�       */
	short      mcmiinno      ;      /*  �Ǝ����؎��� �ӎ� �ʎގݎ��ގ�     */
	char       mcmidtar      ;      /*  �Îގ��� �����Ɏ����� �����͎ގ�    */
	char       mcmidtsb      ;      /*  �Îގ��� �����͎ގ�           */
	char       *mcmidtad     ;      /*  �Îގ��� �����Ɏ� ���Ďގڎ�      */
	short      mcmidtsz      ;      /*  �Îގ��� �����Ɏ� ��������       */
	char       mcmidcp[2]    ;      /*  DCP �ڎݎ׎�����           */
	short      mcmisnnd      ;      /*  �ʎ����ݎӎ� �Ɏ��Ď� �ʎގݎ��ގ�   */
	char       mcmisnkb      ;      /*  �ʎ����� ���� ���̎ގ�         */
	char       mcmistbl      ;      /*  �̎ގ׎����� ������           */
	short      mcmirvnd      ;      /*  �������ݎ��� �Ɏ��Ď� �ʎގݎ��ގ�   */
	char       mcmirvkb      ;      /*  �������� ���� ���̎ގ�         */
	char       mcmiedbl      ;      /*  �̎ގ׎����� �������؎���        */
	char       mcmikfty      ;      /*  �������� �̎؎܎� �����̎�       */
	char       mcmikfng      ;      /*  �������� �̎؎܎� �����ގ���      */
	char       mcmikfcd[2]   ;      /*  �������� �̎؎܎� �����Ď�       */
	char       mcmisnpn[8]   ;      /*  �ʎ����ݎӎ� �̎ߎێ��� �����͎ގҎ� */
	char       mcmirvpn[8]   ;      /*  �������ݎ��� �̎ߎێ��� �����͎ގҎ� */
	char       mcmiattc[3]   ;      /*  ���Îݎ����� �����Ď�          */
	char       mcmicdcn      ;      /*  CD �ˎ�������             */
	char       mcmihdki[8]   ;      /*  �ˎĎގ��� ���� ���ގ����Ύ�     */
	short      mcmitmid      ;      /*  ������ ID               */
	char       mcmidrsh      ;      /*  DR1 / DR2 �ˎ֎����� 2    */
	char       mcmisccd      ;      /*  SMP ������ �����Ď�         */
	char       mcmiscsb      ;      /*  ������ �����Ď�             */
	char       mcmiencd      ;      /*  ������ ���ݎ؎��� �����Ď�       */
	char       mcmiensb[2]   ;      /*  ������ ���ݎ؎��� ���̎ގ����Ď�    */
	short      mcmisnsq      ;      /*  �������ݎ� �ʎގݎ��ގ� (��������)  */
	short      mcmirvsq      ;      /*  �������ݎ� �ʎގݎ��ގ� (���ގ�����) */
	long       mcmircno      ;      /*  RCV ���ʎގ�            */
	long       mcmirqid      ;      /*  �؎������� �����͎ގ�         */
	long       mcmirqrl      ;      /*  �͎ݎ�������               */
	long       mcmisens      ;      /*  ���ݎ� �����Ď�             */
};
typedef struct mcmikyo MCMIKYO;
#define _SMP_MCMIA_H				/*					M01	*/
#endif								/*					M01 */
