/**************************** NTC-SMP-RCV ****************************/
/*																	 */
/*	1 ���̎ގʎߎ�-����													 */
/*		RCV															 */
/*																	 */
/*	2 ���ݎ��� ���̎ގ�														 */
/*		�����Îю�������/�������؎��� ������											 */
/*																	 */
/*	3 ���ݎ��� �Ҏ�														 */
/*		mr_somc														 */
/*																	 */
/*	4 ���Ɏ� ���ގ��֎�														 */
/*		���ގ����Ŏ� �̎����� �� AP�ӎ��Ď� �Î� �����̎ߎݎ���								 */
/*																	 */
/*	5 �ʎߎ׎�-��														 */
/*		�Ŏ�															 */
/*																	 */
/*	6 �͎ݎ�������														 */
/*		MRNORMAL		:	���ｪλ					ST3699		 */
/*		MRRJONEC		:	JNL�Ǝ����̎ߎ���				ST3699		 */
/*																	 */
/*	7 �؎ڎ�															 */
/*		������������ : �ώ��� ��������											 */
/*		������������ : �ώ��� ��������				'87/09/24					 */
/*		�͎ݎ������� : �ώ��� ��������				'88/11/20					 */
/*				 (���������ގ� �������� ���ގ����Ύ� �����Ď� ���ݎ��� �� �͎ݎ���) --- TC1990	 */
/*		�ѹ��� : ��ƣ����				'94/02/15			TD-00	 */
/*				 (�����Îю��ގ��ݤθ�ľ���ˤ���ѹ�)				TD-48	 */
/*				 (�ێ��ޤθ�ľ����ȼ������)					TD-50	 */
/*		�ѹ��� : ����  ����				'96/02/15	--- ST3699		 */
/*				 (�Ύ��Ď����ݎʎގ�ͽ����mr_jopn���Ի��н�)					 */
/*																	 */
/*********************************************************************/
/*********************************************************************/
/*�ץ���������̾	:												 */
/*�ץ�����̾		:���Хץ�����									 */
/*��¤�ֹ�			:PRC-034-01										 */
/*��¤����			:NOP�б�	�꥿���󥳡��ɤ������ͤ����ꤷ����	 */
/*								�Ȥʤä������å��Ϻ������			 */
/*��¤��			:2002.11.27										 */
/*��¤��			:��								 */
/*********************************************************************/

/*********************************************************************/
/*	PRC-034-01  ���� START 											 */
/*  NOP�б�															 */
/*********************************************************************/

/*********************************************************************/
/*	���ݎ���-�Ď� �̎�����													 */
/*********************************************************************/
#include	"mr.h"
/*********************************************************************/
/*	�����η����													 */
/*********************************************************************/
long	mr_somc()						/*					ST3699	 */
{
	/*****************************************************************/
	/* �؎����� ����														 */
	/*****************************************************************/
	return(MRNORMAL);													/* PRC-034-01 */
}
/*********************************************************************/
/*	PRC-034-01  ���� END 											 */
/*  NOP�б�															 */
/*********************************************************************/