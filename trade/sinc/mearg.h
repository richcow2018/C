/********************************************/
/*		��mearg.h							*/
/*	�����������ގ��Ҏݎİ�̎����ώ���					*/
/********************************************/

struct radarg{
	long	rapsfd;		/*�̎����َÎގ������؎̎ߎ�		*/
	char	*raptr;		/*�����ʎގ��̎����Ďގڎ�    */
	long 	rasize;		/*�ʎގ��̎��������ޡ������� */
	long	dosapara;	/*ư��ʎߎ׎Ҏ���		*/
	char    *rdaptr;	/*�����Îގ�����Ǽ�莱�Ďގڎ�*/
	long	rdasize;	/*�����Îގ�����Ǽ�莻������*/
	long 	rarit;		/*�؎Ď׎����          */
	long	pbfadr;		/* �̎ߎ��َʎގ��̎����Ďގڎ�	*/
};
typedef struct radarg RADARG;

struct wrtarg{
	long	fildes;		/*�̎����َÎގ������؎̎ߎ�		*/
	char	*bufptr;	/*�����ʎގ��̎����Ďގڎ�    */
	long 	wrtlen;		/*�����ѤߎÎގ���Ĺ	*/
	long	dosapara;	/*ư��ʎߎ׎Ҏ���		*/
	char    *outadr;	/*���ϰ莱�Ďގڎ�	����*/
	long	outsize;	/*����Ǽ�莻������		*/
	long 	retry;		/*�؎Ď׎����          */
	long    wrqlen;	/*�����׵Ꮋ������		*/
};
typedef struct wrtarg WRTARG;
