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
//从前往后冒泡，将元素最大的移动到后面
void  bubling_max(SSTable& s, int n)
{
	int low = 0; int high = n;
	
	
	for (int i = low; i < high; ++i)
	{
		bool flag = false;
		if (s.elem[i] > s.elem[i + 1])
		{
			mySwap(s.elem[i] , s.elem[i + 1]);

			flag = true;
		}
		
		if (!flag)
		{
			return;
		}
		
	}
}


//从前往后冒泡，将元素最大的移动到后面
bool  bubling_max(SSTable& s, int low,int n)
{
	 int high = n;
	
	
	for (int i = low; i < high; ++i)
	{
		bool flag = false;
		if (s.elem[i] > s.elem[i + 1])
		{
			mySwap(s.elem[i] , s.elem[i + 1]);

			flag = true;
		}
		
		return flag;
		
	}
}

//从后往前冒泡，将元素最小的移动到前面
bool  bubling_min(SSTable& s, int low,int n)
{
	 int high = n - 1;


	for (int i = high; i>low; --i)
	{
		bool flag = false;
		if (s.elem[i] < s.elem[i -1])
		{
			mySwap(s.elem[i], s.elem[i - 1]);

			flag = true;
		}

		return flag;

	}
}
void ChapterEightTest::two(SSTable& s,int n)
{
	int low = 0; int high = n - 1;
	bool flag = true;
	while (low<high && flag)
	{
		bool flag1 = bubling_max(s, low, high);
		high--;
		bool flag2 = bubling_min(s, low, high);
		low++;
		if (!flag1 && !flag2)
		{
			flag = false;
		}
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
