/**********************************************************************/
/*  ＩＢ中継サーバ             ソースファイル                         */
/*                                        作成日    ：1998年 8月20日  */
/*                                        最終修正日：1998年 8月24日  */
/*                                        作成者    ：     寺田 俊彦  */
/**********************************************************************/

#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "sys/time.h"
#include "sys/timeb.h"
#include "netdb.h"
#include "errno.h"
#include "signal.h"
#include "unistd.h"
#include "errno.h"

/**********************************************************************/
/*  関数プロトタイプ宣言                                              */
/**********************************************************************/
void tol_dump();


#ifdef DBG
tol_dump("PORT-TBL",adr,sizeof(INITBL),1,0);
#endif
/* start **************************************************************/
/*   関数名          ：時刻セット処理                                 */
/*   モジュールＩＤ  ：cm_gettime                                     */
/*   引数            ：&a 現在時刻(秒)を格納するアドレス              */
/*                     &b 現在時刻(ﾐﾘ秒)を格納するアドレス            */
/*   返却値          ：なし                                           */
/*   機能説明        ：現在時刻をtimebのﾌｫｰﾏｯﾄに従いaとbに格納する    */
/**********************************************************************/
void cm_gettime(a,b)
  long *a;
  long *b;
{

  struct   timeb        genzai;                 /* ftime 結果格納ｴﾘｱ  */

  ftime(&genzai);

  *a = (long)genzai.time;                       /* 秒                 */
  *b = (long)genzai.millitm;                    /* ﾐﾘ秒               */

  return;
}

/**** 共 通 関 数 ***************************************************/
/********************************************************************/
/*  関 数 名    ：ダンプ関数                                        */
/*  モジュールID：tol_dump                                          */
/*  引 数       ：char * adr  ダンプ開始位置                        */
/*                long length ダンプのバイト数                      */
/*                long disp   画面表示  ０：なし         １：あり   */
/*                FILE *fp    ファイルポインタ ０：ログ取得なし            */
/*  返 却 値    ：なし                                              */
/*  機 能 説 明 ：16進でダンプ表示する。                            */
/********************************************************************/
/*--*----1----*----2----*----3----*----4----*----5----*----6----*---*/
void tol_dump(titl,adr,length,disp,fp)
char *titl;
char *adr;
long length;
long disp;
FILE *fp;
{
  long cnt;
  long amari;
  long cnt2;
  int timea;
  int timeh;
  int timem;
  int times;
  int timeb;

     cm_gettime(&timea,&timeb);
     timeh = ((timea%(24*60*60))/(60*60)+9) % 24;
/*      時                              ↑時差調整(ロンドンから+9Hour)   */
     timem = (timea%(60*60))/60;
     times = timea%60;


  printf("\n******   %2d:%2d:%2d **** %x ******\n",timeh,timem,times,(int)adr);
  printf("%s\n",titl);
  if(disp)
  {
    printf("\n       0 1 2 3  4 5 6 7  8 9 a b  c d e f  /0123456789abcdef/\n");
  }
  if(fp)
  {
    fprintf(fp,
      "\n       0 1 2 3  4 5 6 7  8 9 a b  c d e f  /0123456789abcdef/\n");
  }
  amari = 0;
  for(cnt = 0;cnt < length;cnt++)
  {
	if(cnt % 16 == 0)
	{
      if(disp)
      {
        printf("\n%04lx :",cnt & 0xfffffff0);
	  }
      if(fp)
      {
        fprintf(fp,"\n%04lx :",cnt & 0xfffffff0);
      }
	}
    if(cnt % 4 == 0)
	{
      if(disp)
      {
         printf(" ");
	  }
      if(fp)
      {
        fprintf(fp," ");
      }
	}
    if(disp)
    {
      printf("%02x",(*adr) & 0xff);
	}
    if(fp)
    {
      fprintf(fp,"%02x",(*adr) & 0xff);
    }
    if((cnt % 16) == 15)
    {
      if(disp)
      {
        printf("  ");
	  }
      if(fp)
      {
        fprintf(fp,"  ");
      }
      for(cnt2 = 15;cnt2 >=0;cnt2--)
      {
        if(disp)
        {
          if( ((*(adr-cnt2) >= 0x20) && (*(adr-cnt2) <= 0x7E)) ||
             ((*(adr-cnt2) >= 0xA1) && (*(adr-cnt2) <= 0xDF)) )
          {
            printf("%c",*(adr-cnt2));
          }
          else
          {
            printf(".");
          }
        }
        if(fp)
        {
          fprintf(fp,"%c",*(adr-cnt2));
        }
      }
    }
	adr ++;
  }
  amari = cnt % 16;
  while((cnt % 16))
  {
    if(cnt % 4 == 0)
	{
      if(disp)
      {
        printf(" ");
	  }
      if(fp)
      {
        fprintf(fp," ");
      }
	}
    if(disp)
    {
      printf("  ");
    }
    if(fp)
    {
      fprintf(fp,"  ");
    }
	if((cnt % 16) == 15)
    {
      if(disp)
      {
        printf("  ");
      }
      if(fp)
      {
        fprintf(fp,"  ");
      }
	  adr -= 15;
      for(cnt2 = 0;cnt2 < amari;cnt2++)
      {
        if(disp)
        {
          if( ((*adr >= 0x20) && (*adr <= 0x7E)) ||
             ((*adr >= 0xB1) && (*adr <= 0xFE)) )
          {
            printf("%c",*adr);
          }
          else
          {
            printf(".");
          }
        }
        if(fp)
        {
          fprintf(fp,"%c",*adr);
        }
        adr++;
      }
    }
    adr ++;
    cnt ++;
  }
        if(disp)
        {
          printf("\n");
        }
        if(fp)
        {
          fprintf(fp,"\n");
        }
  printf("******************************************\n");
}

