
/**********************************************************************/
/*      MERQMSZ �ώ��� �͎����� �̎�����                 V/R =  0/0   88.01.21   */
/**********************************************************************/
#define MERQMSZ  if(rqcmsize == 0){\
                     sinfsize = sizeof(MDHIKYO) + 4;\
                 }\
                 else{\
                     sinfsize = sizeof(MDHIKYO) + rqcmsize;\
                 }