/******************************************/
/*                                        */
/*            msusrpt1.h                  */
/*                                        */
/*            mia ŽØŽÖŽ³Ž¼Ž¬Ž²Ž·                 */
/*                                        */
/******************************************/
struct msusrpt1 {
       long    msmiuno1;
       long    msmiuno2;
       long    msmitcod;
       short   msmimnno;
       short   msmisnno;
       char    msmimkei;
       char    msmiskei;
       short   msmismsg;
       char    msmimpcs[8];
       char    msmispcs[8];
       char    msmiurun;
       char    msmioptn;
       char    msmimgot;
       char    msmiscod;
       long    msmiatgp;
       long    msmiatsg;
};
typedef struct msusrpt1 MSUSRPT1;

