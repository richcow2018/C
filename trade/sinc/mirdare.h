/**********************************************************************/
/*                                                                    */
/*                      ���͎ގݎĎ��ݎ؎؎������� �͎�����                            */
/*                                                                    */
/*                      rdryoiki.h                                    */
/*                                                                    */
/**********************************************************************/
/***************************************/
/*        rd���������̎�                    */
/***************************************/
struct rdkyotu {
    short rdid;                          /* ���؎� id                    */
    short ko_sosu;                       /* �������͎ގ̎ގ���                */
    short ko_size;                       /* ���͎ގ̎ގ�������                */
    short ko_kosu;                       /* ���͎ގ̎ގ�����                 */
    long  start_ptr;                     /* start �Ύߎ��ݎ�               */
    long  end_ptr;                       /* end �Ύߎ��ݎ�                 */
    long  space_ptr;                     /* �������؎� �Ύߎ��ݎ�               */
};
typedef struct rdkyotu RDKYOTU;

/***************************************/
/*        rd���͎ގ̎�                     */
/***************************************/
struct rdkobetu {
    long  next_ptr;                      /* next �Ύߎ��ݎ�                */
    long  befor_ptr;                     /* befor �Ύߎ��ݎ�               */
    long  request_id;                    /* �؎������Ď����͎ގ�               */
};
typedef struct rdkobetu RDKOBETU;

/***************************************/
/*         �ێ��� ���؎�                     */
/***************************************/
#if DBG
struct wlog {
    char name[8];                        /* ���ݎ����Ҏ�                    */
    long para[10];                       /* �ʎߎ׎Ҏ���  10���̎ގ�            */
};
typedef struct wlog WLOG;
#endif
struct wlog {
    long para[8];                       /* �ʎߎ׎Ҏ���  10���̎ގ�            */
};
typedef struct wlog WLOG;

#define LM 1                             /* �ێ����َҎӎ�                   */
#define STOPFLG 0xffffffff               /* ���Ď��ʎ�                     */

