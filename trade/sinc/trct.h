/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 �̎����َҎ�														 */
/*		TRCT �Î����� �̎����� (trct.h)										 */
/*																	 */
/*	2 ���̎ގ�															 */
/*		�؎��ʎގ� �������ގ� ��-�̎ގ�											 */
/*																	 */
/*	3 �؎ڎ�															 */
/*		������������ : �Ԏώӎ� �Վ�����											 */
/*		������������ : �Ԏώӎ� �Վ�����											 */
/*		�͎ݎ������� : �Ԏώӎ� �Վ�����			'87/10/01	(L01)				 */
/*			 	 (�������� �؎��ʎގ� ���ݎڎ� �����ӎ� �� �������ގ�) --- STC395			 */
/*		�͎ݎ������� : �����ގ� ������ 			'88/02/09	(L02)				 */
/*			 	 (�؎��ʎގ� �̎����� ���������������̎� ������ �� �ĎӎŎ� �͎ݎ���)            	 */
/*      �ѹ��� : ������          93/11/12    TD-00               */
/*                (SMP���դ�Ƴ����ȼ���ѹ�)      TD-92               */
/*																	 */
/*********************************************************************/

/*********************************************************************/
/*	TRCT ���͎ގ̎� �� �������ގ�����											 */
/*********************************************************************/
struct trctpsz{
	char	trctdate[4];				/* ���ݎ֎� �ˎގ�				 */
	char	trctcrtd[4];				/* �؎��ʎގ� �̎����� �������� �ˎގ� (L02)*/
										/* ͽ���κ��(2��)      TD00 */
										/* SMP���� TSST�˰�ư 		 */
};
typedef struct	trctpsz TRCTPSZ;
