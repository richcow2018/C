/**********************************************************************/
/*      MEUSCK (EDPｼﾖｳ ｶﾋ ﾁｪｯｸ ﾏｸﾛ)  ﾍｯﾀﾞ ﾌｧｲﾙ  V/R =  0/0  88.01.08  */
/*     ＜設計修正者名＞					営業店システム担当(ﾒｰｶ:ｺﾑｱｯﾌﾟ)*/
/*     ＜設計修正年月日及び修正ＩＤ＞　１９９３年１２月２０日     PD03*/
/*                                      EDP使用可否ﾁｪｯｸ条件変更		  */
/*																	  */
/*     ＜設計修正者名＞					営業店システム担当(新藤由美)  */
/*     ＜設計修正年月日及び修正ＩＤ＞　１９９６年　２月１４日      M01*/
/*		故障処理票（発行元管理番号：ST4026)							  */
/*		電文制御区分に、[edp使用但しme_cget()は使用不可]0x03を追加    */
/**********************************************************************/
/*	ＥＤＰ域ポインタ値が不正あるいはＥＤＰ域電文制御使用区分が無効で  */
/*  あればMENOTUSE」で呼び出し元に復帰する							  */

#define MEEBLEDP	0x02			/* 電文制御区分「EDP使用可」 PD03 */
#define MEEBLEDP2	0x03			/*  "  「EDP使用(cget以外)」   M01*/

#define MEUSCK if(((long)mdpsptr <= 0l) || 				  /* PD03  M01*/\
				  ((mdpsptr->mdpsdsts[0] != MEEBLEDP) &&				\
				   (mdpsptr->mdpsdsts[0] != MEEBLEDP2)) ){/* PD03  M01*/\
                   MELOG(0X33331098,&mdpsptr,4l)\
                   return(MENOTUSE);\
               }

/* [EDP使用可、但しcget()以外 */
#define MEUSCK2 if(((long)mdpsptr <= 0l) || 			   /*     M01*/\
				   (mdpsptr->mdpsdsts[0] != MEEBLEDP) ){   /*     M01*/\
                   MELOG(0X33331098,&mdpsptr,4l)\
                   return(MENOTUSE);\
               }

#define MEUSECHK(NAME){										   			\
			extern void mo_wlg4();										\
			if( ((long)mdpsptr <= 0) ||									\
				(mdpsptr->mdpsdsts[0] != MEEBLEDP) &&		/*     M01*/\
				(mdpsptr->mdpsdsts[0] != MEEBLEDP2) ){ 		/* 	   M01*/\
				mo_wlg4(NAME,0x33331098,&mdpsptr,4);					\
				return(MENOTUSE);										\
			}															\
		}
