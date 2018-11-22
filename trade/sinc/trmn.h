/****************************************************************************/
/*                                                                          */
/*           ��⡼�ȥ��ƥʥ������������ơ��֥�ʣԣңͣΡ�           */
/*                                                                          */
/*                ��������1994/4/8      ��������1994/4/11                   */
/*                ��������1997/10/19    ���ơ���                 ST4978  	*/
/*                                      trmnfchr�ɲ�                        */
/*                ��������1997/11/03    ����  ��                 ST4946     */
/*                						trmnkeit,trmngnex�ɲ�				*/
/*                ��������1997/11/16    ����  ��                 ST4993     */
/*                						trmnysms�ɲ�						*/
/*                                                                          */
/****************************************************************************/

/*******************************  ������  ***********************************/

struct trmnpsz
{
    unsigned char    trmndtyp;          /* ��⡼�ȥ��ƥʥ����ե�����   */
    unsigned char    trmnrsv8;          /* Reserve 8				        */
             char    trmnsusp;          /* suspend Create ID 	            */
             char    trmnrsv1;          /* �ꥶ���� 1                       */
             char    trmnapid[8];       /* ��ɽ���Хץ�������̾           */
             char    trmnrmp1[8];       /* �؎ӎ�����������AP�̎ߎێ�������̾(P01)   */
             char    trmnrmp2[8];       /* �؎ӎ�����������AP�̎ߎێ�������̾(P02)   */
             char    trmnrmp3[8];       /* �؎ӎ�����������AP�̎ߎێ�������̾(P03)   */
             long    trmntmem;          /* �Ҏӎ؎ʎߎ������ı�������Ԥ���������     */
             long    trmntmrm;          /* ��⡼�����κ�ȯ���Ԥ���������   */
             long    trmntins;          /* �ɣΣɣԡݣ��Ԥ���������         */
             long    trmntine;          /* �ɣΣɣԡݣ��Ԥ���������         */
             long    trmntprs;          /* �ץ������԰����Ԥ���������     */
             long    trmntbmn;          /* ���־Ȳ�����Ԥ��Ԥ���������     */
             long    trmnymem;          /* ͽ���ώҎӎ؎ʎߎ�����λ�����Ԥ���������   */
             long    trmnyfpt;          /* ͽ���ώ̎����َʎߎ�����λ�����Ԥ���������  */
             long    trmnyfcg;          /* ͽ���ώ̎����������ؤ���λ�����Ԥ�   */
                                        /* ��������                            */
             long    trmnyrbk;          /* ͽ���ώ̎����َێ��َʎގ�����λ�����Ԥ�    */
                                        /* ��������                            */
             long    trmnygrp;          /* ͽ���ώ��ގَ��̎߼¹Դ�λ�Ԥ���������    */
             long    trmnlpcn;          /* �����ʎߎ����Ȏ��Ď�������                 */
             long    trmntpso;          /* �����ʎߎ������̎ߎݎ�������                */
    unsigned short   trmnrtry;          /* ��⡼�����κ����ȥ饤��       */
										/* ###ST4978 start					*/
    unsigned char    trmnfchr;          /* �̎��������غ�ȎÎގ��ڎ��Ďغ����ӎ��Ď�      */
										/* ###ST4978 end					*/
										/* ###ST4946 start					*/
    unsigned char    trmnkeit;          /* �罾�϶�ʬ������   	       		*/
    unsigned char    trmngnex;          /* ���ѷ϶�ʬ�޻ߥե饰   			*/
             char    trmnrsv3[3];       /* �ꥶ���֣�                       */
										/* ###ST4946 end					*/
    unsigned short   trmnrmns;          /* ��⡼�ȥ��ƥʥ󥹾���         */
             short   trmnrsv4;          /* �ꥶ���֣�                       */
             long    trmnprid;          /* ���ƥʥ󥹻ҥץ������       */
    unsigned char    trmnisrs;          /* �ɣΣɣԡݣ����μ�������         */
    unsigned char    trmniers;          /* �ɣΣɣԡݣ����μ�������         */
    unsigned char    trmnpsrs;          /* �ץ������԰������μ�������     */
    unsigned char    trmnmnrs;          /* ���ƥʥ󥹰����������         */
    unsigned char    trmntsrs;          /* �ơ��֥�����λ���μ�������     */
    unsigned char    trmnkcrs;          /* ���ڤ��ؤ����μ�������           */
    unsigned char    trmnymrs;          /* ͽ���ώҎݎÎŎݎ���λ�������μ������� */
    unsigned char    trmnysms;          /* ͽ���ώ����Îюӎ��Ď��ѹ��»ܥե饰		*/
             char    trmnrsv7[20];      /* �ꥶ���֣�                       */
};

typedef struct trmnpsz TRMNPSZ; 

