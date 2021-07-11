/*************************************************************************************
 *
 * �� �� ��:   SqList.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/11 14:05
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "SqList.h"

SqList::SqList(int size)
{
	this->data = new ElemType[size];
	this->length = 0;
	this->MaxSize = size;
}

SqList::~SqList()
{
	delete[] this->data;
}

bool SqList::is_empty()
{
	return length == 0 ? true : false;
}

void SqList::ClearList()
{
	length = 0;
}

bool SqList::addList(ElemType e[])
{
	try
	{
		if (sizeof(e)/sizeof(ElemType)<=MaxSize)
		{
			for (int i = 0; i <MaxSize; i++)
			{
				data[i] = e[i];
				length++;
			}
		}
		else
		{
			throw "�ռ䲻��";
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	return false;
}

void SqList::printList()
{
	if (length >= 0)
	{
		for (int i = 0; i <length; i++)
		{
			cout << data[i] << endl;
		}
	}
}