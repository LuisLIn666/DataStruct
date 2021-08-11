/*************************************************************************************
 *
 * 文 件 名:   ChapterEightTest.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/8/7 23:48
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "ChapterEightTest.h"

int Patition(int low, int high, SSTable& s)
{
	ElemType temp = s.elem[low];
	
	while (low<high)
	{
		while (low<high&&s.elem[high]>temp)
		{
			high--;
		}
		s.elem[low] = s.elem[high];
		while (low<high && s.elem[low]<=temp)
		{
			low++;
		}
	}
	s.elem[low] = temp;
	return low;
}
void ChapterEightTest::one(SSTable& s, int n)
{
	//快速排序思想在于将区间分化成左右两个区间，比基准小往左比基准大往右边
	deque<ElemType> que;
}

void ChapterEightTest::two(SSTable& s,int n)
{
	int low = 0, high = n - 1;
	bool flag = true;
	while (low<high&&flag)
	{
		flag = false;
		for (int i = low; i < high; i++)
		{
			if (s.elem[i] > s.elem[i + 1])
			{
				mySwap(s.elem[i], s.elem[i + 1]);
				flag = true;
			}
		}
		high--;
		for (int j = high; j> low; j--)
		{
			if (s.elem[j] < s.elem[j - 1])
			{
				mySwap(s.elem[j], s.elem[j - 1]);
				flag = true;
			}
		}
		low++;
	}
	
}

int ChapterEightTest::five(SSTable& s,int k)
{
	//判断k与枢轴元素的关系
	//如果m=k则返回m
	//如果m>k,则在左子表中，否则在又子表中;
	int low = 0;
	int high = s.TableLen - 1;
	int m = Patition(low,high,s);
	
	if (m == k)
	{
		return m;
	}
	else if (m > k)
	{
		m = Patition(0, m - 1, s);
	}
	else
	{
		m = Patition(m, high, s);
	}

	return 0;
}
