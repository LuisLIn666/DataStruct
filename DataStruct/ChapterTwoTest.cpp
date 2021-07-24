/*************************************************************************************
 *
 * 文 件 名:   ChapterTwoTest.cpp
 * 描    述: 
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
#include "ChapterTwoTest.h"

bool ChapterTwoTest::del_min(SqList& L)
{
	if (L.length==0)
	{
		return false;
	}
	
	ElemType temp = L.data[0];
	int pos = 0;
	for (int i = 1; i <L.length; i++)
	{
		if (L.data[i] < temp)
		{
			temp = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];
	L.length--;
    return true;
}
