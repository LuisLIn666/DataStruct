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

void ChapterTwoTest::reverseList(SqList& L)
{
	ElemType temp;
	for (int i = 0; i <L.length/2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

bool ChapterTwoTest::dele_Elem_X(SqList& L, ElemType x)
{
	if (L.length==0)
	{
		return false;
	}
	int k = 0;
	for (int i = 0; i <L.length; i++)
	{
		if (L.data[i]==x)
		{
			k++;
			L.length--;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
		
	}
	return true;
}

bool ChapterTwoTest::del_s_to_t(SqList& L, ElemType s, ElemType t)
{
	if (s>=t||L.length==0)
	{
		return false;
	}
	int i;
	for (i = 0; i < L.length && L.data; i++);
	
	if (i >= L.length)
		return false;
	int j;
	for (j = i; j < L.length&& L.data[j] <= t; j++);

	while (j<L.length)
	{
		L.data[i] = L.data[j];
		j++;
		i++;
	}
	L.length = i;
	return true;
}

bool ChapterTwoTest::del_s_to_t2(SqList& L, ElemType s, ElemType t)
{
	int i, k = 0;
	if (s >= t || L.length == 0)
	{
		return false;
	}
	for ( i = 0; i <L.length; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
	}
	L.length -= k;
	return true;
}

void ChapterTwoTest::del_repetion(SqList& L)
{
	int i, j;
	for (  i = 0,j=1; j <L.length; j++)
	{
		if (L.data[i]!=L.data[j])
		{
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
}

SqList& ChapterTwoTest::merge(SqList& L1, SqList& L2)
{

	SqList *l3=new SqList(L1.length+L2.length) ;
	int i, j, k = 0;
	while (i<L1.length&&j<L2.length)
	{
		if (L1.data[i]<L2.data[j])
		{
			l3->data[k++] = L1.data[i];
		}
		else
		{
			l3->data[k++] = L2.data[i];
		}
	}

	while (i<L1.length)
	{
		l3->data[k++] = L1.data[i++];
	}

	while (j < L2.length)
	{
		l3->data[k++] = L2.data[j++];
	}
	return *l3;
	
}
