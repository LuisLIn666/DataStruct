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
#include "Mysearch.h"

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
	int i=0, j=0, k = 0;
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

void ChapterTwoTest::reverse_a_b(SqList& L,int m,int n)
{
	SqList *temp= new SqList(m);
	int start = m + 1;
	for (int  i = 0; i <n; i++)
	{
		temp->data[i++] = L.data[m++];
		temp->length++;
	}
	int j;
	for ( j = 0; j < m; j++)
	{
		L.data[j++] = L.data[start++];
	}
	for (int k = 0; k <temp->length; k++)
	{
		L.data[j++] = temp->data[k++];
	}
}

void ChapterTwoTest::searchExchangeInsert(SqList& L, ElemType x)
{
	//调用二分查找算法，如果找到则交换，如果找不到则插入
	Mysearch m;
	int isSearch;
	isSearch=m.Binary_Search(L,x);
	if (isSearch != -1)
	{
		mySwap(L.data[isSearch], L.data[L.length - 1]);
	}
	else
	{
		L.listInsert(L, L.length, x);
	}
}
void ChapterTwoTest::Reverse(SqList& L, int from, int to)
{
	//算法思想和第八题类似
	//本次采用空间复杂度较小方案
	int i, temp;
	for (i = 0; i < (to - from + 1) / 2; i++)
	{
		temp = L.data[from + i];
		L.data[from + i] = L.data[to - i];
		L.data[to - i] = temp;
	}
}
void ChapterTwoTest::left_p(SqList& L, int n, int p)
{
	Reverse(L, 0, p - 1);//时间复杂度O（p/2）;
	Reverse(L, p, n - 1);//时间复杂度O（n-p）/2;
	Reverse(L, 0, n - 1);//时间复杂度O（n/2）;
	//O(n),空间O(1);
}

int ChapterTwoTest::M_Search(SqList& A, SqList& B, int n)
{
	//计数器，当k=data[n]时候为所求
	int k = 1;
	int p_A = 1, p_B = 1;
	//判断最后一步是A还是B
	bool isA=0;
	bool isB=0;
	while (k<=n)
	{
		bool isA = 0;
		bool isB = 0;
		if (A.data[p_A]<B.data[p_B])
		{
			p_A++;
			k++;
			isA = 1;
		}
		else
		{
			p_B++;
			k++;
			isB = 1;
		}
	}
	return isA;isB?A.data[p_A]:B.data[p_B];
}

//时间复杂度O（n），空间复杂度O（1）