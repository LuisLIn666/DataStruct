/*************************************************************************************
 *
 * 文 件 名:   SqList.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 14:05
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "SqList.h"
#include<array>
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
			throw "空间不足";
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

bool SqList::listInsert(SqList& L, int i, ElemType e)
{
	if (i<1||i>L.length+1)
	{
		return false;
	}
	else if (L.length > -MaxSize)
	{
		return false;

	}
	else
	{
		for (int j = L.length; j >= i; j--)
			L.data[j] = L.data[j - 1];
		L.data[i - 1] = e;
		L.length++;
		return true;

	}
	
}
