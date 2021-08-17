/*************************************************************************************
 *
 * �� �� ��:   ChapterEightTest.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/8/7 23:48
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
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
	//��������˼�����ڽ�����ֻ��������������䣬�Ȼ�׼С����Ȼ�׼�����ұ�
	deque<ElemType> que;
}
//��ǰ����ð�ݣ���Ԫ�������ƶ�������
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


//��ǰ����ð�ݣ���Ԫ�������ƶ�������
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

//�Ӻ���ǰð�ݣ���Ԫ����С���ƶ���ǰ��
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
	//�ж�k������Ԫ�صĹ�ϵ
	//���m=k�򷵻�m
	//���m>k,�������ӱ��У����������ӱ���;
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
