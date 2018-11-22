/******************************************/
/*                                        */
/*               miretjoh.h               */
/*                                        */
/*          Ž¶Ž²Ž¾ŽÝ ŽÊŽÞŽÝŽºŽÞŽ³ Ž¼Ž­ŽÄŽ¸ Ž²Ž·           */
/*                                        */
/******************************************/
/********   88.1.2 shuu seu *****/
/*******   sakujo 
union  kno {
    char  ckaisen[3];
    short  skaisen;
};
********************/
/*********************************/
struct  retjoh {
/*********
        union kno  kaisen    ;
***********/
/******** sinki sakusei **********/
        char   ckaisen[3];
/*********************************/
        char   jotai    ;
        char   syubetu  ;
};
typedef struct retjoh RETJOH;
