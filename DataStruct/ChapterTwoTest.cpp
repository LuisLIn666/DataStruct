/*************************************************************************************
 *
 * �� �� ��:   ChapterTwoTest.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/21 23:48
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
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
