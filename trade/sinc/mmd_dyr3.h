/****************************************************************************/
/*																			*/
/* 通信制御関連／プロセス協調関連の定数と情報構造							*/
/*																			*/
/* Update History:															*/
/*		95.06.12 K.Kubota ST2637: Process cooperation fail					*/
/*		95.06.24 K.Kubota ST2707: 対ICPﾌﾟﾛｾｽ協調 (と書式整理)				*/
/*	95.09.14 K.Kubota SSCY0061: 全撤去ﾓｰﾄﾞ対応								*/
/****************************************************************************/

										/* ###ST2707 start					*/
#include "ttli.h"
#include "ttsi.h"
#include "tefx.h"
#include "tefy.h"
#include "tdad.h"
#include "mmd_dyr1.h"
#include "mmd_dyr5.h"

/********************************/
/* 定数定義						*/
/********************************/
#define END				-1				/* 終了指示							*/

/************************************/
/* 関数型宣言						*/
/************************************/
/* 通信ﾌﾟﾛｾｽｻｽﾍﾟﾝﾄﾞ解除				*/
void					mmd_2400();
/* ｻｽﾍﾟﾝﾄﾞ解除ﾘｽﾄ初期設定			*/
void					mmd_2401();
/* ｻｽﾍﾟﾝﾄﾞ解除ﾌﾟﾛｾｽ登録				*/
void					mmd_2402(/*PCTn*/);
/* FNA論理回線増設処理				*/
void					mmd_51a0(/*q*/);
/* FNA論理回線撤去処理 ###SSCY0061	*/
void					mmd_51d0(/*q*/); /* ###SSCY0061	*/
/* FNA論理回線属性変更処理			*/
void					mmd_51u0(/*q*/);
/* FNA論理ﾊﾟｽ増設処理				*/
void					mmd_61a0(/*q*/);
/* FNA論理ﾊﾟｽ属性変更処理			*/
void					mmd_61u0(/*q*/);
/* 関数名：FNA論理ﾊﾟｽ撤去処理		*/
void					mmd_61d0(/*q*/);
/* 通信制御ﾃｰﾌﾞﾙ複写処理			*/
void					mmd_8000();
/* TEFX空き個別部検索処理			*/
TEFXPSZ					*mmd_8310(/*pNO*/);
/* TEFX個別部更新処理				*/
void					mmd_8320(/*q, pEFX,	EFXn, FAHn*/);
/* TEFX個別部変更処理				*/
void					mmd_8330(/*q, pEFX,	EFXn*/);
/* TEFX個別部複写処理				*/
void					mmd_8340();
/* TEFX個別部削除処理				*/
void					mmd_8350(/*pEFX, EFXn*/);
/* TDAD個別部キー検索処理			*/
TDADPSZ					*mmd_8914(/*pckb, pNO*/);
										/* ###ST2707 end					*/
