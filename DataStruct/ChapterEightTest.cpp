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
