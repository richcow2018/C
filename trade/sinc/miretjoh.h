/******************************************/
/*                                        */
/*               miretjoh.h               */
/*                                        */
/*          �������� �ʎގݎ��ގ� �����Ď� ����           */
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
