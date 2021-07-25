/*************************************************************************************
 *
 * 文 件 名:   ChapterTwoTest.h
 * 描    述: 第二章课后练习
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/21 23:48
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "SqList.h"

class ChapterTwoTest
{
	//第一题
	bool del_min(SqList &L);

	//第二题
	void reverseList(SqList& L);

	//第三题
	bool dele_Elem_X(SqList& L, ElemType x);
	
	//第四题,有序
	bool del_s_to_t(SqList& L, ElemType s, ElemType t);

	//第五题，无序
	bool del_s_to_t2(SqList& L, ElemType s, ElemType t);

	//第六题
	void del_repetion(SqList& L);

	//第七题
	SqList& merge(SqList& L1, SqList& L2);

	//8
	void reverse_a_b(SqList& L,int m,int n);

	//9
	void searchExchangeInsert(SqList& L, ElemType x);
	
	//10

};

