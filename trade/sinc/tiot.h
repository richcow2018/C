/**********************************************************************/
/*                                                                    */
/*                   mdtio.h                                          */
/*                                                                    */
/*            TIOT �Î��̎ގ� �̎����ώ���                                       */
/*                                                                    */
/**********************************************************************/
struct mdiotko {
       short  tiotiocd;                     /*X I/O �����Ď�              */
       char   tiotiocl;                     /*X I/O �����͎ގ�             */
       char   tiotyobi;                     /*X �֎ˎ�                   */
};
typedef struct mdiotko TIOTKO;
typedef struct mdiotko TIOTPSZ;
