struct motblst{
	char 	motst1;
	char	motst2;
	};
typedef struct motblst MOTBLST;

#define	MOTBOK		0
#define	MOTBNG	   -1

struct motbplst{
	char	mopmtdr1[32];				/*���̎����َώ��ݎĎÎގ��ڎ��Ď�̾�Ύߎ��ݎ�*/
	char	moplvol1[32];				/*���̎���������vol̾�Ύߎ��ݎ�*/
	char	moppass1[32];				/*���̎����ََ̎ʎߎ�̾�Ύߎ��ݎ�*/
	char	mopmtdr2[32];				/*���̎����َώ��ݎĎÎގ��ڎ��Ď�̾�Ύߎ��ݎ�*/
	char	moplvol2[32];				/*���̎���������vol̾�Ύߎ��ݎ�*/
	char	moppass2[32];				/*���̎����ََ̎ʎߎ�̾�Ύߎ��ݎ�*/
	};
typedef struct motbplst MOTBPLST;

#define MOLNML		0				/*����������λ����*/
#define MOLSERT2	1				/*���Υե�����Τߥ��顼*/
#define MOLSERT1	2				/*���Υե�����Τߥ��顼*/
#define MOLWAFT	  100				/*�����θ�����ˤƥ��顼*/
#define	MOLNRCV	   -1				/*�ꥫ�Х��ץ����ƥ�Ǥ���*/
#define MOLMDSYS   -2				/*���̥⡼�ɡ����̥ե��������⡼��
									  �Ǥʤ�*/
#define	MOLBFER	   -3				/*�Хåե��������顼*/
#define MOLERLMT   -4				/*TLMT�ǥ��顼(TLMT�ʤ�����������*/
#define MOLLMTBE   -5				/*LM�ơ��֥�˥��顼*/
#define MOLOTHRE   -6				/*����¾�Υ��顼*/
#define MOLERGSZ   -7				/*mt_zgsz�ˤƥ��顼*/
#define MOLWERMC  -10				/*ξ�̎����ٶ����ώ��ݎĎ����Ȏ��Ĥǥ��顼*/
#define MOLWERVR  -11				/*ξ�̎����ٶ����٥���Ÿ���ǥ��顼*/
#define MOLWERT12 -100				/*ξ�̎����ٶ���������˥��顼*/


