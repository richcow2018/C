#ifndef INCLUDE_OSWRITE1_INS
#define INCLUDE_OSWRITE1_INS

/**************************************************************************************************/
/* 																								  */
/* v_z��qer r��yqzrvx��l/r,rn��v																  */
/* w�َ�z��e2002z��11v��9z��																	  */
/* {nwwz��e 																					  */
/* w�َ���qe��																				  */
/*																								  */
/**************************************************************************************************/
/************************************************************************************************/
/* u��Az��w% qeTBCS0123                                                      					*/
/* u��Az��|��qe{nu��v��JISrqqzr�Ҏ�0xbcq��x��@q��q��q��q�Ҏ�q��w��;q`	                  					*/
/*			  z`y��qr2r{qzr*q`r,rnr��_rbr*{nu��v�UCrqqzr�Ҏ�0x5aq�ڎ�u`							*/
/* u��AzӁ  qe2003.06.03                                                    					*/
/* u��A��   qeSupply    ��                                                					*/
/************************************************************************************************/
#include <sys/msg.h>
#include "oscom_ins.h"


//************************************************
//***** r��,r��}rbr���׎�

long os_getSG(char*, void*);
long ossenms(long, long, char*);
long osgtdat(long*, long*);

//rurwr��x(u��Zx'|<	os_InitSystem
//rurwr��xh|Xx'|<		os_XXXXX ({��v���
// ***** y�׎�x����***************************************************************
// define{��q��x>�Ҏ�{��{��q��q��q���Ҏ�q��
#define ERR_HEADER			0x940d0000 

#define NO_MSGSEND			0x00000000

#define CON_NORMAL			0x00000001 
#define PRC_NORMAL			0x00000002 
#define LOG_NORMAL			0x00000004

#define CON_ERROR			0x00000040 
#define PRC_ERROR			0x00000020 
#define LOG_ERROR			0x00000010

#define DAT_ERROR			0x00000100
#define SIZ_ERROR			0x00000200
#define FIL_ERROR			0x00000400

#define INV_ERROR			0x00000800

#define SYS_IDENT			""


short before[] = {						  		// {nu��v��JISrqqzr��
0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,		// TBCS0123
0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,
0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,
0x79,0x7a,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,
0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,
0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,
0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,
0xbe,0xbf,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,
0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,
0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,
0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,
0xde,0xdf
};


short sProAfter[] = {					  		// z`y����,ryrw{nu��v�UCrqqzr��
0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,		// TBCS0123
0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,
0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,
0x59,0x5a,0x8ea0,0x8ea1,0x8ea2,0x8ea3,0x8ea4,0x8ea5,
0x8ea6,0x8ea7,0x8ea8,0x8ea9,0x8eaa,0x8eab,0x8eac,0x8ead,
0x8eae,0x8eaf,0x8eb0,0x8eb1,0x8eb2,0x8eb3,0x8eb4,0x8eb5,
0x8eb6,0x8eb7,0x8eb8,0x8eb9,0x8eba,0x8ebb,0x8ebc,0x8ebd,
0x8ebe,0x8ebf,0x8ec0,0x8ec1,0x8ec2,0x8ec3,0x8ec4,0x8ec5,
0x8ec6,0x8ec7,0x8ec8,0x8ec9,0x8eca,0x8ecb,0x8ecc,0x8ecd,
0x8ece,0x8ecf,0x8ed0,0x8ed1,0x8ed2,0x8ed3,0x8ed4,0x8ed5,
0x8ed6,0x8ed7,0x8ed8,0x8ed9,0x8eda,0x8edb,0x8edc,0x8edd,
0x8ede,0x8edf
};


short sConAfter[] = {					  		// z`y��qr2r{qzr*q`r,rnr��_rbr*{nu��v�UCrqqzr��
0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,			// TBCS0123
0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,
0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,
0x59,0x5a,0xa0,0xa1a3,0xa1d6,0xa1d7,0xa1a2,0xa1a6,
0xa5f2,0xa5a1,0xa5a3,0xa5a5,0xa5a7,0xa5a9,0xa5e3,0xa5e5,
0xa5e7,0xa5c3,0xa1bc,0xa5a2,0xa5a4,0xa5a6,0xa5a8,0xa5aa,
0xa5ab,0xa5ad,0xa5af,0xa5b1,0xa5b3,0xa5b5,0xa5b7,0xa5b9,
0xa5bb,0xa5bd,0xa5bf,0xa5c1,0xa5c4,0xa5c6,0xa5c8,0xa5ca,
0xa5cb,0xa5cc,0xa5cd,0xa5ce,0xa5cf,0xa5d2,0xa5d5,0xa5d8,
0xa5db,0xa5de,0xa5df,0xa5e0,0xa5e1,0xa5e2,0xa5e4,0xa5e6,
0xa5e8,0xa5e9,0xa5ea,0xa5eb,0xa5ec,0xa5ed,0xa5ef,0xa5f3,
0xa1ab,0xa1ac
};

long lFacility[]= {								// r��_rur)r��arqqzr��
LOG_LOCAL0,LOG_LOCAL1,LOG_LOCAL2,LOG_LOCAL3,
LOG_LOCAL4,LOG_LOCAL5,LOG_LOCAL6,LOG_LOCAL7
};

					
/**************************************************************************************************/
/* End																							  */
/**************************************************************************************************/
#endif	// INCLUDE_OSSENMS_INS
